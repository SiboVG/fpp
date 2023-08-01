package fpp.compiler.codegen

import fpp.compiler.ast._
import io.circe._
import io.circe.generic.auto._
import io.circe.generic.semiauto._
import io.circe.syntax._

/** JSON encoder for Ast objects */
object AstJsonEncoder extends JsonEncoder {

  // JSON encoder for AST nodes
  private implicit def astNodeEncoder[T: Encoder]: Encoder[AstNode[T]] =
    new Encoder[AstNode[T]] {
      override def apply(astNode: AstNode[T]): Json = Json.obj(
        "AstNode" -> Json.obj(
          "data" -> astNode.data.asJson,
          "id" -> astNode.id.asJson
        )
      )
    }

  // ----------------------------------------------------------------------
  // JSON encoders for Scala type variants, each of which has one value
  // with no arguments. We use the unqualified class name of the
  // type to represent the value.
  //
  // TODO: Replace all these ad-hoc transforms with a JSON-to-JSON
  // postprocessing that replaces { "foo" : { } } with "foo" everywhere.
  // ----------------------------------------------------------------------

  implicit val binopEncoder: Encoder[Ast.Binop] =
    Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val componentKindEncoder: Encoder[Ast.ComponentKind] =
    Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val formalParamKindEncoder: Encoder[Ast.FormalParam.Kind] =
    Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val generalKindEncoder: Encoder[Ast.SpecPortInstance.GeneralKind] =
    Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val limitKindEncoder: Encoder[Ast.SpecTlmChannel.LimitKind] =
    Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val patternEncoder: Encoder[Ast.SpecConnectionGraph.Pattern.Kind] =
    Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val queueFullEncoder: Encoder[Ast.QueueFull] =
    Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val severityEncoder: Encoder[Ast.SpecEvent.Severity] =
    Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val specialInputKindEncoder: Encoder[Ast.SpecPortInstance.SpecialInputKind] =
    Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val specialKindEncoder: Encoder[Ast.SpecPortInstance.SpecialKind] =
    Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val typeFloatEncoder: Encoder[Ast.TypeFloat] =
    Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val typeIntEncoder: Encoder[Ast.TypeInt] =
    Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val unopEncoder: Encoder[Ast.Unop] =
    Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val updateEncoder: Encoder[Ast.SpecTlmChannel.Update] =
    Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val visibilityEncoder: Encoder[Ast.Visibility] =
    Encoder.encodeString.contramap(getUnqualifiedClassName(_))

  // ----------------------------------------------------------------------
  // Encoders for helping Circe with recursive types
  // ----------------------------------------------------------------------

  // JSON encoder for qualified identifiers
  implicit val qualIdentEncoder: Encoder[Ast.QualIdent] =
    io.circe.generic.semiauto.deriveEncoder[Ast.QualIdent]

  // JSON encoder for expressions
  implicit val exprEncoder: Encoder[Ast.Expr] =
    io.circe.generic.semiauto.deriveEncoder[Ast.Expr]

  // JSON encoder for type names
  // TODO: Replace the ad-hoc processing. See above.
  implicit val typeNameEncoder: Encoder[Ast.TypeName] =
    Encoder.instance(
      (t: Ast.TypeName) => t match {
        case Ast.TypeNameBool => addTypeNameKey(t, Json.fromString("TypeNameBool"))
        case t => io.circe.generic.semiauto.deriveEncoder[Ast.TypeName].apply(t)
      }
    )

  // JSON encoder for module member nodes
  private implicit val moduleMemberNodeEncoder: Encoder[Ast.ModuleMember.Node] =
    io.circe.generic.semiauto.deriveEncoder[Ast.ModuleMember.Node]

  // ----------------------------------------------------------------------
  // Encoders for skipping the node field
  // This reduces clutter in the output
  // ----------------------------------------------------------------------

  // JSON encoder for module members
  private implicit val moduleMemberEncoder: Encoder[Ast.ModuleMember] =
    Encoder.instance((m: Ast.ModuleMember) => m.node.asJson)

  // JSON encoder for component members
  private implicit val componentMemberEncoder: Encoder[Ast.ComponentMember] =
    Encoder.instance((m: Ast.ComponentMember) => m.node.asJson)

  // JSON encoder for topology members
  private implicit val topologyMemberEncoder: Encoder[Ast.TopologyMember] =
    Encoder.instance((m: Ast.TopologyMember) => m.node.asJson)

  // ----------------------------------------------------------------------
  // The public encoder interface
  // ----------------------------------------------------------------------

  /** Converts Ast to JSON */
  def astToJson(tul: List[Ast.TransUnit]): Json = tul.asJson

}
