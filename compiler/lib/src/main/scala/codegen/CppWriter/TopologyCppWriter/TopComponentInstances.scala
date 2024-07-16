package fpp.compiler.codegen

import fpp.compiler.analysis._
import fpp.compiler.ast._
import fpp.compiler.util._

/** Writes out C++ for topology component instances */
case class TopComponentInstances(
  s: CppWriterState,
  aNode: Ast.Annotated[AstNode[Ast.DefTopology]]
) extends TopologyCppWriterUtils(s, aNode) {

  private val bannerComment = "Component instances"

  def getHppMembers: List[CppDoc.Member] = {
    getDeclMembers match {
      case Nil => List()
      case l => linesMember(CppDocWriter.writeBannerComment(bannerComment)) :: l
    }
  }

  def getCppLines: List[Line] = addBannerComment(
    bannerComment,
    getDefLines
  )

  private def getDeclMembers = {
    def getCode(ci: ComponentInstance): List[CppDoc.Member] = {
      val implType = getImplType(ci)
      val instanceName = ci.getUnqualifiedName
      val cppQualifiedName = CppWriter.writeQualifiedName(ci.qualifiedName)
      val instLines = Line.addPrefixLine (line(s"//! $instanceName")) (
        lines(
          s"extern $implType $instanceName;"
        )
      )
      val qualIdentList = cppQualifiedName contains "::" match {
        case true => cppQualifiedName.substring(0, cppQualifiedName.lastIndexOf("::")).split("::").toList
        case false => List()
      }

      wrapInNamespaces(qualIdentList, List(linesMember(Line.blank :: instLines)))
    }
    instances.flatMap(getCode)
  }

  private def getDefLines = {
    def getCode(ci: ComponentInstance): List[Line] = {
      val implType = getImplType(ci)
      val instanceName = CppWriter.writeQualifiedName(ci.qualifiedName)
      getCodeLinesForPhase (CppWriter.Phases.instances) (ci).getOrElse(
        lines(
          s"$implType $instanceName(FW_OPTIONAL_NAME($q$instanceName$q));"
        )
      )
    }
    flattenWithBlankPrefix(instances.map(getCode))
  }

  private def getImplType(ci: ComponentInstance) = {
    val implType = ci.aNode._2.data.implType.map(_.data)
    implType.getOrElse(getComponentNameAsQualIdent(ci))
  }

}
