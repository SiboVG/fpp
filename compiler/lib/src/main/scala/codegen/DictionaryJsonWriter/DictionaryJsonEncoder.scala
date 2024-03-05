package fpp.compiler.codegen

import fpp.compiler.ast._
import fpp.compiler.util._
import fpp.compiler.analysis._
import io.circe._
import io.circe.syntax._



/** ====================================================================== 
 *  Case class representing dictionary metadata
 *  ====================================================================== */
case class DictionaryMetadata(
    deploymentName: String,
    projectVersion: String, 
    frameworkVersion: String, 
    libraryVersions: List[String], 
    dictionarySpecVersion: String
)

/** ====================================================================== 
 *  Generate dictionary JSON
 *  ====================================================================== */

case class DictionaryJsonEncoder(
    /** Constructed Dictionary data structure */
    dictionary: Dictionary,
    /** Dictionary State */
    dictionaryState: DictionaryJsonEncoderState
) {
    /** Dictionary entry map to JSON */
    private def dictionaryEntryMapAsJson[A, B] (f1: (A, B) => Json) (map: Map[A, B]): Json =
        (map.map { case (key, value) => f1(key, value) }).toList.asJson

    /** Dictionary symbol set to JSON */
    private def dictionarySymbolSetAsJson[A] (f1: A => Json) (set: Set[A]): Json =
        (set.map(elem => f1(elem))).toList.asJson
    
    /** Enum Constant JSON Encoding */
    private def enumConstantAsJson(aNode: AstNode[Ast.DefEnumConstant]): Map[String, Json] = {
        val Value.EnumConstant(value, _) = dictionaryState.a.valueMap(aNode.id)
        Map(value._1 -> value._2.asJson)
    }

    /** Symbol JSON Encoding */
    private implicit def typeSymbolSetEncoder [T <: Symbol]: Encoder[Set[T]] = {
        def f1(symbol: T) = symbol.asJson
        Encoder.instance (dictionarySymbolSetAsJson (f1) _)
    }

    /** DictionaryMetadata JSON Encoding */
    private implicit def dictionaryMetadataEncoder: Encoder[DictionaryMetadata] = new Encoder[DictionaryMetadata] {
        override def apply(metadata: DictionaryMetadata): Json = {
            Json.obj(
                "deploymentName" -> metadata.deploymentName.asJson,
                "projectVersion" -> metadata.projectVersion.asJson,
                "frameworkVersion" -> metadata.frameworkVersion.asJson,
                "libraryVersions" -> metadata.libraryVersions.asJson,
                "dictionarySpecVersion" -> metadata.dictionarySpecVersion.asJson
            )
        }
    }

    /** JSON Encoding for Maps of Commands, Parameters, Events, Telemetry Channels, Records, and Containers */
    private implicit val commandMapEncoder: Encoder[Map[BigInt, CommandEntry]] = {
        def f1(opcode: BigInt, command: CommandEntry) = (opcode -> command).asJson
        Encoder.instance (dictionaryEntryMapAsJson (f1) _)
    }

    private implicit val paramMapEncoder: Encoder[Map[BigInt, ParamEntry]] = {
        def f1(identifier: BigInt, param: ParamEntry) = (identifier -> param).asJson
        Encoder.instance (dictionaryEntryMapAsJson (f1) _)
    }

    private implicit val eventMapEncoder: Encoder[Map[BigInt, EventEntry]] = {
        def f1(identifier: BigInt, event: EventEntry) = (identifier -> event).asJson
        Encoder.instance (dictionaryEntryMapAsJson (f1) _)
    }

    private implicit val channelMapEncoder: Encoder[Map[BigInt, TlmChannelEntry]] = {
        def f1(identifier: BigInt, event: TlmChannelEntry) = (identifier -> event).asJson
        Encoder.instance (dictionaryEntryMapAsJson (f1) _)
    }

    private implicit val recordMapEncoder: Encoder[Map[BigInt, RecordEntry]] = {
        def f1(identifier: BigInt, record: RecordEntry) = (identifier -> record).asJson
        Encoder.instance (dictionaryEntryMapAsJson (f1) _)
    }

    private implicit val containerMapEncoder: Encoder[Map[BigInt, ContainerEntry]] = {
        def f1(identifier: BigInt, container: ContainerEntry) = (identifier -> container).asJson
        Encoder.instance (dictionaryEntryMapAsJson (f1) _)
    }


    /** JSON Encoding for optional fields */
    def jsonWithOptional(key: String, optional: Option[Any], json: Json): Json = {
        optional match {
            case Some(value) => value match {
                case x: Format => Json.obj(key -> formatSpecifierAsJson(x)).deepMerge(json)
                case x: Int => Json.obj(key -> x.asJson).deepMerge(json)
                case Value.Struct(a, t) => {
                    val Value.AnonStruct(members) = a
                    val memberJson = members.map((key, value) => (key.toString -> valueAsJson(value))).asJson
                    Json.obj(key -> memberJson).deepMerge(json)
                }
                case x: Value => Json.obj(key -> valueAsJson(x)).deepMerge(json)
                case x: BigInt => Json.obj(key -> x.asJson).deepMerge(json)
                case x: Ast.QueueFull => Json.obj(key -> x.toString.asJson).deepMerge(json)
            }
            case None => json
        }
    }

    /** JSON Encoding for format specifiers */
    def formatSpecifierAsJson(format: Format): Json =
        format.fields.foldLeft(format.prefix) ((acc, inst) => s"${acc}{}${inst._2}").asJson

    /** JSON Encoding for FPP Types */
    def typeAsJson[T <: Type](elemType: T): Json = {
        elemType match {
            case Type.PrimitiveInt(kind) => {
                val kindString = kind.toString
                val size = if (kindString.startsWith("I")) kindString.split("I").tail else kindString.split("U").tail
                val signed = if (kindString.startsWith("I")) true else false
                Json.obj(
                    "name" -> kindString.asJson,
                    "kind" -> "integer".asJson,
                    "size" -> size.mkString("").toInt.asJson,
                    "signed" -> signed.asJson
                )
            }
            case Type.Float(kind) => {
                val kindString = kind.toString
                val size = kindString.split("F").tail
                Json.obj(
                    "name" -> kindString.asJson,
                    "kind" -> "float".asJson,
                    "size" -> size.mkString("").toInt.asJson
                )
            }
            case Type.Boolean => Json.obj("name" -> "bool".asJson, "kind" -> "bool".asJson, "size" -> dictionaryState.boolSize.asJson)
            case Type.String(size) => {
                val jsonObj = Json.obj(
                    "name" -> "string".asJson,
                    "kind" -> "string".asJson
                )
                size match {
                    case Some(s) => Json.obj("size" -> valueAsJson(dictionaryState.a.valueMap(s.id))).deepMerge(jsonObj)
                    case None => Json.obj("size" -> dictionaryState.defaultStringSize.asJson).deepMerge(jsonObj)
                }
            }
            case Type.Array(node, _, _, _) => {
                Json.obj(
                    "name" -> dictionaryState.a.getQualifiedName(Symbol.Array(node)).toString.asJson,
                    "kind" -> "qualifiedIdentifier".asJson,
                )
            }
            case Type.Enum(node, _, _) => {
                Json.obj(
                    "name" -> dictionaryState.a.getQualifiedName(Symbol.Enum(node)).toString.asJson,
                    "kind" -> "qualifiedIdentifier".asJson,
                )
            }
            case Type.Struct(node, _, _, _, _) => {
                Json.obj(
                    "name" -> dictionaryState.a.getQualifiedName(Symbol.Struct(node)).toString.asJson,
                    "kind" -> "qualifiedIdentifier".asJson,
                )
            }
            // TODO: things excluded from the spec - empty json / do not add
            case _ => {
                Json.obj()
            }
        }
    }

    /** JSON Encoding for arrays */
    def arrayElementsAsJson(elements: List[Value]): Json = {
        val arrayRes = for(e <- elements) yield {
            val res = e match {
                // Case where array is N-dimensional
                case Value.Array(a, t) => arrayElementsAsJson(a.elements)
                case _ => valueAsJson(e)
            }

            res.asJson
        }
        arrayRes.asJson
    }
    
    /** JSON Encoding for FPP Values */
    def valueAsJson[V <: Value](value: V): Json = {
        value match {
            case Value.PrimitiveInt(v, _) => v.asJson
            case Value.Integer(v) => v.asJson
            case Value.Float(v, _) => v.asJson
            case Value.Boolean(v) => v.asJson
            case Value.String(v) => v.asJson
            case Value.Array(a, t) => arrayElementsAsJson(a.elements)
            case Value.EnumConstant(v, _) => v._2.asJson
            case Value.Struct(Value.AnonStruct(members), t) => members.map((key, value) => (key.toString -> valueAsJson(value))).asJson
            case _ => value.toString.asJson
        }
    }

    /** JSON Encoding for symbols (arrays, enums, and structs only) */
    private implicit def typeSymbolEncoder [T <: Symbol]: Encoder[T] = new Encoder[T] {
        override def apply(symbol: T): Json = {
            val qualifiedName = dictionaryState.a.getQualifiedName(symbol).toString
            symbol match {
                case Symbol.Array(_, _, _) => {
                    val arrayType = dictionaryState.a.typeMap(symbol.getNodeId)
                    val Type.Array(_, anonArray, default, format) = arrayType
                    val defaultJsonList: List[Json]= default match {
                        case Some(defaultVal) => for (elem <- defaultVal._1._1) yield valueAsJson(elem)
                        case None => List.empty[Json]
                    }

                    Json.obj(
                        "kind" -> "array".asJson,
                        "qualifiedName" -> qualifiedName.asJson,
                        "size" -> arrayType.getArraySize.asJson,
                        "elementType" -> typeAsJson(anonArray.eltType),
                        "default" -> defaultJsonList.asJson
                    )
                }
                case Symbol.Enum(_, node, _) => {
                    val Type.Enum(_, repType, default) = dictionaryState.a.typeMap(symbol.getNodeId)
                    val enumDefault = default match {
                        case Some(defaultVal) => defaultVal.value._1
                        case None => ""
                    }
                    val identifiers = for (aNode <- node.data.constants) yield Map(aNode._2._1._1.toString -> valueAsJson(dictionaryState.a.valueMap(aNode._2.id)))
                    Json.obj(
                        "kind" -> "enum".asJson,
                        "qualifiedName" -> qualifiedName.asJson,
                        "representationType" -> typeAsJson(repType),
                        "identifiers" -> identifiers.flatten.toMap.asJson,
                        "default" -> s"${qualifiedName}.${enumDefault}".asJson
                    )
                }
                case Symbol.Struct(_, node, _) => {
                    val Type.Struct(_, anonStruct, default, sizes, formats) = dictionaryState.a.typeMap(symbol.getNodeId)
                    val Type.AnonStruct(members) = anonStruct
                    val membersFormatted = for(((key, t), index) <- members.zipWithIndex) yield {
                        val json = Json.obj("type" -> typeAsJson(t).asJson, "index" -> index.asJson)
                        val optionalMap = Map("size" -> sizes.get(key), "format" -> formats.get(key))
                        val withOptionals = optionalMap.foldLeft(json) ((acc, inst) => jsonWithOptional(inst._1, inst._2, acc))
                        (key.toString -> withOptionals)
                    }
                    val json = Json.obj(
                        "kind" -> "struct".asJson,
                        "qualifiedName" -> qualifiedName.asJson,
                        "members" -> membersFormatted.toMap.asJson,
                    )
                    jsonWithOptional("default", default, json)
                }
                // TODO: what to return here
                case _ => Json.obj("TODO" -> "TODO".asJson)
            }
        }
    }

    /** JSON Encoding for parameter SET command formal parameters */
    def formatParamSetCommandParams(typeNameNode: AstNode[Ast.TypeName]): Json = {
        // Convert to list since that is how formal params are represented in the JSON spec
        List.apply(Json.obj(
            "name" -> "val".asJson,
            "description" -> "".asJson,
            "type" -> typeAsJson(dictionaryState.a.typeMap(typeNameNode.id)),
            "ref" -> false.asJson
        )).asJson
    }

    /** JSON Encoding for FormalParamList */
    private implicit def formalParamListEncoder: Encoder[Ast.FormalParamList] = new Encoder[Ast.FormalParamList] {
        override def apply(params: Ast.FormalParamList): Json = {
            val paramListJson = for (paramEntry <- params) yield {
                val (_, elem, annotation) = paramEntry
                val description = annotation.mkString("\n")
                val AstNode(Ast.FormalParam(kind, name, typeNameNode), _) = elem
                val ref = kind match {
                    case Ast.FormalParam.Ref => true
                    case Ast.FormalParam.Value => false
                }
                Json.obj(
                    "name" -> name.asJson,
                    "description" -> description.asJson, 
                    "type" -> typeAsJson(dictionaryState.a.typeMap(typeNameNode.id)),
                    "ref" -> ref.asJson
                )
            }
            paramListJson.asJson
        }
    }

    /** JSON Encoding for Commands */
    private implicit def commandEncoder: Encoder[(BigInt, CommandEntry)] = new Encoder[(BigInt, CommandEntry)] {
        override def apply(entry: (BigInt, CommandEntry)): Json = {
            val opcode = entry._1
            val command  = entry._2.command
            val componentInstUnqualName = entry._2.componentInstance.getUnqualifiedName
            val name = s"${componentInstUnqualName}.${command.getName}"
            command match {
                case Command.NonParam(aNode, kind) => {
                    val (annotation, node, _) = aNode
                    val data = node.data
                    val description = annotation.mkString("\n")
                    val (commandKind, priority, queueFull) = kind match {
                        case Command.NonParam.Async(priority, queueFull) => ("async", priority, Some(queueFull))
                        case Command.NonParam.Guarded => ("guarded", None, None)
                        case Command.NonParam.Sync => ("sync", None, None)
                    }
                    val formalParams = data.params
                    val json = Json.obj(
                        "name" -> name.asJson,
                        "commandKind" -> commandKind.asJson, 
                        "opcode" -> opcode.asJson,
                        "description" -> description.asJson, 
                        "formalParams" -> formalParams.asJson
                    )
                    val optionalMap = Map("priority" -> priority, "queueFullBehavior" -> queueFull)
                    optionalMap.foldLeft(json) ((acc, inst) => jsonWithOptional(inst._1, inst._2, acc))
                }
                // Case where command is param set/save command
                case fpp.compiler.analysis.Command.Param(aNode, kind) => {
                    val (annotation, node, _) = aNode
                    val data = node.data
                    val (commandKind, formalParams) = kind match {
                        case Command.Param.Set => ("set", formatParamSetCommandParams(data.typeName))
                        case Command.Param.Save => ("save", List.empty[String].asJson)
                    }                    
                    Json.obj(
                        "name" -> name.asJson,
                        "commandKind" -> commandKind.asJson, 
                        "opcode" -> opcode.asJson,
                        "description" -> annotation.mkString("\n").asJson, 
                        "formalParams" -> formalParams
                    )
                }
            }
        }
    }

    /** JSON Encoding for Parameters */
    private implicit def paramEncoder: Encoder[(BigInt, ParamEntry)] = new Encoder[(BigInt, ParamEntry)] {
        override def apply(entry: (BigInt, ParamEntry)): Json = {
            val numIdentifier = entry._1
            val param = entry._2.param
            val componentInstUnqualName = entry._2.componentInstance.getUnqualifiedName
            val name = s"${componentInstUnqualName}.${param.getName}"
            val (annotation, node, _) = param.aNode
            val json = Json.obj(
                "name" -> name.asJson,
                "description" -> annotation.mkString("\n").asJson,
                "type" -> typeAsJson(param.paramType),
                "id" -> numIdentifier.asJson
            )
            jsonWithOptional("default", param.default, json)
        }
    }

    /** JSON Encoding for Events */
    private implicit def eventEncoder: Encoder[(BigInt, EventEntry)] = new Encoder[(BigInt, EventEntry)] {
        override def apply(entry: (BigInt, EventEntry)): Json = {
            val event = entry._2.event
            val numIdentifier = entry._1
            val componentInstUnqualName = entry._2.componentInstance.getUnqualifiedName
            val name = s"${componentInstUnqualName}.${event.getName}"
            val (annotation, node, _) = event.aNode
            val json = Json.obj(
                "name" -> name.asJson,
                "description" -> annotation.mkString("\n").asJson,
                "severity" -> node.data.severity.toString.replace(" ", "_").toUpperCase().asJson,
                "formalParams" -> node.data.params.asJson,
                "id" -> numIdentifier.asJson
            )
            val optionalMap = Map("format" -> Some(event.format), "throttle" -> event.throttle)
            optionalMap.foldLeft(json) ((acc, inst) => jsonWithOptional(inst._1, inst._2, acc))
        }
    }

    /** JSON Encoding for TlmChannel.Limits */
    private implicit def channelLimitEncoder: Encoder[TlmChannel.Limits] = new Encoder[TlmChannel.Limits] {
        override def apply(limits: TlmChannel.Limits): Json = {
            (limits.map { case (limitKind, (id, value)) => limitKind.toString -> valueAsJson(value)}).asJson
        }
    }

    /** JSON Encoding for TlmChannels */
    private implicit def channelEncoder: Encoder[(BigInt, TlmChannelEntry)] = new Encoder[(BigInt, TlmChannelEntry)] {
        override def apply(entry: (BigInt, TlmChannelEntry)): Json = {
            val channel = entry._2.tlmChannel
            val numIdentifier = entry._1
            val componentInstUnqualName = entry._2.componentInstance.getUnqualifiedName
            val name = s"${componentInstUnqualName}.${channel.getName}"
            val (annotation, node, _) = channel.aNode
            val json = Json.obj(
                "name" -> name.asJson,
                "description" -> annotation.mkString("\n").asJson,
                "type" -> typeAsJson(channel.channelType),
                "id" -> numIdentifier.asJson,
                "telemetryUpdate" -> channel.update.toString.asJson
            )
            
            val jsonWithOptionals = jsonWithOptional("format", channel.format, json)

            // If channel high or low limits are specified, add them to the JSON and return the telem channel JSON
            if(!channel.lowLimits.isEmpty || !channel.highLimits.isEmpty) {
                val lowLimitJson = if(!channel.lowLimits.isEmpty) Json.obj("low" -> channel.lowLimits.asJson) else Json.obj()
                val highLimitJson = if(!channel.highLimits.isEmpty) Json.obj("high" -> channel.highLimits.asJson) else Json.obj()
                Json.obj("limits" -> lowLimitJson.deepMerge(highLimitJson)).deepMerge(jsonWithOptionals)
            }
            // No channel limits exist, return the telem channel JSON
            else {
                jsonWithOptionals   
            }
        }
    }

    /** JSON Encoding for Records */
    private implicit def recordEncoder: Encoder[(BigInt, RecordEntry)] = new Encoder[(BigInt, RecordEntry)] {
        override def apply(entry: (BigInt, RecordEntry)): Json = {
            val record = entry._2.record
            val numIdentifier = entry._1
            val componentInstUnqualName = entry._2.componentInstance.getUnqualifiedName
            val name = s"${componentInstUnqualName}.${record.getName}"
            val (annotation, node, _) = record.aNode
            Json.obj(
                "name" -> name.asJson,
                "description" -> annotation.mkString("\n").asJson,
                "type" -> typeAsJson(record.recordType),
                "array" -> record.isArray.asJson,
                "id" -> numIdentifier.asJson,
            )            
        }
    }

    /** JSON Encoding for Containers */
    private implicit def containerEncoder: Encoder[(BigInt, ContainerEntry)] = new Encoder[(BigInt, ContainerEntry)] {
        override def apply(entry: (BigInt, ContainerEntry)): Json = {
            val container = entry._2.container
            val numIdentifier = entry._1
            val componentInstUnqualName = entry._2.componentInstance.getUnqualifiedName
            val name = s"${componentInstUnqualName}.${container.getName}"
            val (annotation, node, _) = container.aNode
            val json = Json.obj(
                "name" -> name.asJson,
                "description" -> annotation.mkString("\n").asJson,
                "id" -> numIdentifier.asJson,
            )
            jsonWithOptional("defaultPriority", container.defaultPriority, json)
        }
    }

     /** Given a set of symbols, returns subset consisting of array, enum, and struct symbols */
    def splitTypeSymbolSet(symbolSet: Set[Symbol], outSet: Set[Symbol]): (Set[Symbol]) = {
        if (symbolSet.isEmpty) (outSet) else {
            val (tail, out) = symbolSet.head match {
                case h: (Symbol.Array | Symbol.Enum | Symbol.Struct) => (symbolSet.tail, outSet + h)
                case _ => (symbolSet.tail, outSet)
            }
            splitTypeSymbolSet(tail, out)
        }
    }

    /** JSON Encoding for a complete dictionary */
    def dictionaryAsJson: Json = {
        /** Split set into individual sets consisting of each symbol type (arrays, enums, structs) */
        val typeDefSymbols = splitTypeSymbolSet(dictionary.typeSymbolSet, Set())
        /** Convert each dictionary element to JSON and return the complete dictionary JSON */
        Json.obj(
            "metadata" -> dictionaryState.metadata.asJson,
            "typeDefinitions" -> typeDefSymbols.asJson,
            "commands" -> dictionary.commandEntryMap.asJson,
            "parameters" -> dictionary.paramEntryMap.asJson,
            "events" -> dictionary.eventEntryMap.asJson,
            "telemetryChannels" -> dictionary.tlmChannelEntryMap.asJson,
            "records" -> dictionary.recordEntryMap.asJson,
            "containers" -> dictionary.containerEntryMap.asJson
        )
    }
}