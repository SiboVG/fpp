package fpp.compiler.analysis

import fpp.compiler.ast._
import fpp.compiler.util._

/** Apply matched port numbering */
object MatchedPortNumbering {

  // A mapping from component instances to connections
  private type ConnectionMap = Map[ComponentInstance, Connection]

  // State for matched numbering
  private case class State private(
    // The topology
    t: Topology,
    // The port instance for port 1
    pi1: PortInstance,
    // The map from component instances to connections for port 1
    map1: ConnectionMap,
    // The port instance for port 2
    pi2: PortInstance,
    // The map from component instances to connections for port 2
    map2: ConnectionMap,
    // Port numbering state
    numbering: PortNumberingState
  )

  private object State {

    // Number a connection pair
    private def numberConnectionPair(
      matchingLoc: Location,
      state: State,
      c1: Connection,
      c2: Connection
    ): Result.Result[State] = {
      val t = state.t
      val pi1 = state.pi1
      val n1Opt = t.getPortNumber(pi1, c1)
      val pi2 = state.pi2
      val n2Opt = t.getPortNumber(pi2, c2)
      val u1 = state.numbering.usedPorts1
      val u2 = state.numbering.usedPorts2
      (n1Opt, n2Opt) match {
        case (Some(n1), Some(n2)) =>
          // Both ports have a number: check that they match
          if (n1 == n2)
            Right(state)
          else {
            // Error: numbers don't match
            val p1Loc = c1.getThisEndpoint(pi1).loc
            val p2Loc = c2.getThisEndpoint(pi2).loc
            Left(
              SemanticError.MismatchedPortNumbers(
                p1Loc,
                n1,
                p2Loc,
                n2,
                matchingLoc
              )
            )
          }
        case (Some(n1), None) =>
          // Only pi1 has a number: assign it to pi2
          // Check to see if the port number is already in use
          state.numbering.usedPorts2.get(n1) match {
            case Some(prevC) => Left(SemanticError.PortNumberAlreadyInUse(n1, c2.getLoc, prevC.getLoc))
            case None =>
              val t1 = t.assignPortNumber(pi2, c2, n1)
              // Update the set of used ports so that the new port number is tracked
              val num = state.numbering.setUsedPorts(state.numbering.usedPorts1, state.numbering.usedPorts2 + (n1 -> c2))
              Right(state.copy(t = t1, numbering = num))
          }
        case (None, Some(n2)) =>
          // Only pi2 has a number: assign it to pi1
          // Check to see if the port number is already in use
          state.numbering.usedPorts1.get(n2) match {
            case Some(prevC) => Left(SemanticError.PortNumberAlreadyInUse(n2, c1.getLoc, prevC.getLoc))
            case None =>
               val t1 = t.assignPortNumber(pi1, c1, n2)
              // Update the set of used ports so that the new port number is tracked
              val num = state.numbering.setUsedPorts(state.numbering.usedPorts1 + (n2 -> c1), state.numbering.usedPorts2)
              Right(state.copy(t = t1, numbering = num))
          }
        case (None, None) =>
          // Neither port has a number: assign a new one
          val maxSize1 = pi1.getArraySize
          val maxSize2 = pi2.getArraySize
          val (numbering, n) = state.numbering.getPortNumber
          // Check to see if the port number is out of range for either of the port array sizes
          if(n > maxSize1 - 1)
            then Left(SemanticError.NoPortFoundByMatchedPortNumbering(pi1.getLoc))
          else if(n > maxSize2 - 1)
            then Left(SemanticError.NoPortFoundByMatchedPortNumbering(pi2.getLoc))
          // Check to see if the port number is already in use
          (state.numbering.usedPorts1.get(n), state.numbering.usedPorts2.get(n)) match {
            case (Some(prevC), None) => Left(SemanticError.PortNumberAlreadyInUse(n, c2.getLoc, prevC.getLoc))
            case (None, Some(prevC)) => Left(SemanticError.PortNumberAlreadyInUse(n, c1.getLoc, prevC.getLoc))
            case (Some(prevC1), Some(prevC2)) => Left(SemanticError.PortNumberAlreadyInUse(n, c2.getLoc, prevC1.getLoc))
            case (None, None) =>
              val t1 = t.assignPortNumber(pi1, c1, n).assignPortNumber(pi2, c2, n)
              // Update the set of used ports so that the new port number is tracked
              val num = state.numbering.setUsedPorts(state.numbering.usedPorts1 + (n -> c1), state.numbering.usedPorts2 + (n -> c2))
              Right(state.copy(t = t1, numbering = num))
          }
      }
    }

    // For each pair of connections (c1, c2), check that numbers 
    // match and/or assign numbers
    def assignNumbers(
      matchingLoc: Location,
      state: State
    ): Result.Result[State] = {
      val (map1, map2) = (state.map1, state.map2)
      val list1 = map1.toList.sortWith(_._2 < _._2)
      for {
        result <- Result.foldLeft (list1) (state) ({
          case (s, (ci, c1)) => {
            val c2 = map2(ci)
            numberConnectionPair(matchingLoc, s, c1, c2)
          }
        })
      }
      yield result
    }

    def initial(
      t: Topology,
      pi1: PortInstance,
      map1: ConnectionMap,
      pi2: PortInstance,
      map2: ConnectionMap,
      usedPorts1: Map[Int, Connection],
      usedPorts2: Map[Int, Connection]
    ): State = {
      State(
        t,
        pi1,
        map1,
        pi2,
        map2,
        PortNumberingState.initial(usedPorts1, usedPorts2)
      )
    }

  }

  /** Apply matched numbering */
  def apply(t: Topology): Result.Result[Topology] = {
    // Fold over instances and matchings
    Result.foldLeft (t.instanceMap.keys.toList) (t) ((t, ci) =>
      Result.foldLeft (ci.component.portMatchingList) (t) ((t, pm) =>
        handlePortMatching(t, ci, pm)
      )
    )
  }

  // Check for missing connections
  private def checkForMissingConnections(
    matchingLoc: Location,
    map1: ConnectionMap,
    map2: ConnectionMap
  ): Result.Result[Unit] = {
    // Ensure that map2 contains everything in map1
    def helper(map1: ConnectionMap, map2: ConnectionMap) =
      Result.foldLeft (map1.toList) (()) ({ case (u, (ci, c)) =>
        if (map2.contains(ci))
          Right(())
        else {
          val loc = c.getLoc
          Left(SemanticError.MissingConnection(loc, matchingLoc))
        }
      })
    // Ensure that the two sets of keys match
    if (map1.size >= map2.size)
      helper(map1, map2)
    else
      helper(map2, map1)
  }

  // Handle one port matching
  private def handlePortMatching(
    t: Topology,
    ci: ComponentInstance,
    portMatching: Component.PortMatching
  ) = {
    // Map remote components to connections at pi
    def constructMap(loc: Location, pi: PortInstance) = {
      val empty: ConnectionMap = Map()
      val pii = PortInstanceIdentifier(ci, pi)
      val cs = t.getConnectionsAt(pii).toList.sorted
      Result.foldLeft (cs) (empty) ((m, c) => {
        if(c.isUnmatched)
          Right(m)
        else {
          val piiRemote = c.getOtherEndpoint(pi).port
          val ciRemote = piiRemote.componentInstance
          m.get(ciRemote) match {
            case Some(cPrev) => Left(
              SemanticError.DuplicateMatchedConnection(
                c.getLoc,
                cPrev.getLoc,
                portMatching.getLoc
              )
            )
            case None => Right(m + (ciRemote -> c))
          }
        }
      })
    }

    def checkRemoteUsedPorts(piiRemote: PortInstanceIdentifier, used: Map[Int, Connection]) = {
      val csRemote = t.getConnectionsAt(piiRemote).toList.sorted
      Result.foldLeft (csRemote) (()) ((r, cRemote) => {
        t.getPortNumber(piiRemote.portInstance, cRemote) match {
          case Some(n) =>
            used.get(n) match {
              case Some(c) => 
                var cFromPii = c.from.port
                var cToPii = c.to.port
                var cRemoteFromPii = cRemote.from.port
                var cRemoteToPii = cRemote.to.port
                if ((c != cRemote) && (cFromPii == cRemoteFromPii || cToPii == cRemoteToPii)) {
                  Left(SemanticError.PortNumberAlreadyInUse(n, c.getLoc, cRemote.getLoc))
                }
                else
                  Right(())
              case None => Right(())
            }
          case None => Right(())
        }
      })
    }

    // Computes the set of used ports for all connections at a specific port instance
    def computeUsedPortNumbers(pi: PortInstance): Result.Result[Map[Int, Connection]] = {
      val pii = PortInstanceIdentifier(ci, pi)
      val cs = t.getConnectionsAt(pii).toList.sorted
      Result.foldLeft (cs) (Map[Int, Connection]()) ((m, c) => {
        val piiRemote = c.getOtherEndpoint(pi).port
        for {
          used <- t.getPortNumber(pi, c) match {
            case Some(n) => {
              m.get(n) match {
                case Some(prevC) => 
                  val loc = c.getLoc
                  val prevLoc = prevC.getLoc
                  Left(
                    SemanticError.DuplicateConnectionAtMatchedPort(loc, pi.toString, prevLoc, n)
                  )
                case None => {
                  Right(m + (n -> c))
                }
              }
            }
            case None => {
              Right(m)
            }
          }
          _ <- checkRemoteUsedPorts(piiRemote, used)
        } yield used
      })
    }

    val pi1 = portMatching.instance1
    val pi2 = portMatching.instance2
    val loc = portMatching.getLoc
    for {
      map1 <- constructMap(loc, pi1)
      map2 <- constructMap(loc, pi2)
      usedPorts1 <- computeUsedPortNumbers(pi1)
      usedPorts2 <- computeUsedPortNumbers(pi2)
      _ <- checkForMissingConnections(loc, map1, map2)
      state <- {
        val state = State.initial(t, pi1, map1, pi2, map2, usedPorts1, usedPorts2)
        State.assignNumbers(loc, state)
      }
    }
    yield state.t
  }

}
