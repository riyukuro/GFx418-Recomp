// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 debug text of values,
// namespaces, multinames and ABC constant pool records (the tracer and the VM's error messages print these). The
// exe groups them with the AS2 natives, hence the as2 directory.
// MS2-UNIT: sfr_as2_01d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424eb7b0-0x1424ed770 .text$mn
// MS2-RANGE: 0x1424ed7b0-0x1424ed840 .text$mn
// MS2-RANGE: 0x142cc92d0-0x142cc92f9 .text$yd

#define MS2_SF_STRING_FROM_BUFFER
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/kernel/sf_string.h"
#include "ms2/scaleform/include/kernel/sf_msgformat.h"
#include "ms2/scaleform/include/gfx/gfx_asutils.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/as3_vm.h"

namespace Scaleform {

// The exe calls AsString<UInt32> (0x1423e8390) out of line from AsString(const Value&); it is declared here so it is
// not inlined there, and defined by its other users. AsString(cp, vd) inlines the unsigned int copy instead.
template<> String AsString<UInt32>(const UInt32& v);

// "a" followed by the text of s. 0x1424e0e50
String operator+(const char* a, const GFx::ASString& s);
static inline String operator+(const char* left, const String& right) { return String(left, right.ToCStr(), NULL); }

namespace GFx { namespace AS3 {

// How much of a namespace the text shows.
enum NamespaceText
{
    nsKindAndUri,       // "public uri", "private uri", ...
    nsUriOrAccess,      // the uri, but the access word for protected, static protected, private and internal
    nsUriOnly           // the uri of a public or explicit namespace, nothing for the others
};

const char* AsString(Abc::NamespaceKind kind);
String AsString(const Value& v);
String AsString(const Abc::ConstPool& cp, const Abc::Multiname& mn);
String AsString(const Abc::ConstPool& cp, const Abc::NamespaceSetInfo& nss, NamespaceText nt);
String AsString(const Abc::ConstPool& cp, const Abc::ValueDetail& vd);
String AsString(const Abc::NamespaceInfo& ns, NamespaceText nt);
String AsString(const Instances::Namespace& ns, NamespaceText nt);
String AsString(const NamespaceSet& nss);
String AsStringFlag(const Abc::Instance& inst);

// The value as an ActionScript string: the primitives and strings converted, the rest a description.
// @0x1424eb7b0
ASString AsString(const Value& v, StringManager& sm)
{
    switch (v.GetKind())
    {
    case Value::kUndefined:
    case Value::kBoolean:
    case Value::kInt:
    case Value::kUInt:
    case Value::kNumber:
    case Value::kString:
    {
        ASString result = sm.CreateEmptyString();
        v.Convert2String(result);
        return ASString(result);
    }
    case Value::kThunk:
        return sm.GetStringManager()->CreateConstString("thunk", 5);
    case Value::kThunkFunction:
        return sm.GetStringManager()->CreateConstString("thunk function", 14);
    case Value::kVTableInd:
        return sm.CreateString("VTable ind: " + Scaleform::AsString(v.GetVTableInd()));
    case Value::kVTableIndClosure:
        return sm.GetStringManager()->CreateConstString("VTableIndClosure", 16);
    case Value::kFunction:
        return sm.GetStringManager()->CreateConstString("function Function() {}", 22);
    case Value::kObject:
        if (v.GetObject() != NULL)
            return sm.GetStringManager()->CreateConstString("[object ", 8) + v.GetObject()->GetTraits().GetName() + "]";
        return sm.GetBuiltin(AS3Builtin_null);
    case Value::kClass:
        if (v.GetObject() != NULL)
            return sm.GetStringManager()->CreateConstString("[class ", 7) + v.GetObject()->GetTraits().GetName() + "]";
        return sm.GetBuiltin(AS3Builtin_null);
    case Value::kNamespace:
    {
        const Instances::Namespace& ns = v.AsNamespace();
        const char* kind = AsString(ns.GetKind());
        ASString result = sm.GetStringManager()->CreateConstString(kind, strlen(kind));
        if (ns.GetUri().GetSize() != 0)
        {
            result.Append(" ", 1);
            result.Append(ns.GetUri());
        }
        return ASString(result);
    }
    case Value::kThunkClosure:
        return sm.GetStringManager()->CreateConstString("ThunkClosure", 12);
    default:
        return sm.CreateEmptyString();
    }
}

// The values separated by ", ".
// @0x1424ebb70
String AsString(const ValueArray& values)
{
    String result;
    for (UPInt i = 0; i < values.GetSize(); ++i)
    {
        if (i != 0)
            result.AppendString(", ");
        result.AppendString(AsString(values[i]).ToCStr());
    }
    return result;
}

// @0x1424ebc30
String AsString(const ValueArrayDH& values)
{
    String result;
    for (UPInt i = 0; i < values.GetSize(); ++i)
    {
        if (i != 0)
            result.AppendString(", ");
        result.AppendString(AsString(values[i]).ToCStr());
    }
    return result;
}

// The declaration of class ind: "dynamic final class Name extends Base implements I1, I2".
// @0x1424ebcf0
String AsString(const Abc::ConstPool& cp, const Abc::ClassTable& classes, int ind)
{
    String result;
    const Abc::Instance& inst = classes.Info[ind]->inst_info;
    const Abc::Multiname& name = cp.GetMultiname(inst.name_ind);

    result += AsStringFlag(inst) + AsString(cp, name);

    if (inst.super_name_ind != 0)
    {
        result += " extends " + AsString(cp, cp.const_multiname[inst.super_name_ind]);
    }

    if (inst.implemented_interfaces.info.GetSize() > 0)
    {
        result.AppendString(" implements ");
        for (unsigned i = 0; i < inst.implemented_interfaces.info.GetSize(); ++i)
        {
            if (i != 0)
                result.AppendString(", ");
            result += AsString(cp, cp.GetMultiname(inst.implemented_interfaces.info[i]));
        }
    }
    return result;
}

// The signature: "(name:Type, opt:Type = value) : ReturnType".
// @0x1424ebfc0
String AsString(const Abc::ConstPool& cp, const Abc::MethodInfo& mi)
{
    String result;
    result.AppendString("(");

    for (UPInt i = 0; i < mi.ParamTypes.GetSize(); ++i)
    {
        if (i != 0)
            result.AppendString(", ");

        if (mi.HasParamNames())
        {
            const StringDataPtr pname = cp.GetString(mi.ParamNames[i]);
            result.AppendString(pname.ToCStr(), pname.GetSize());
            result.AppendString(":");
        }

        const unsigned type = mi.ParamTypes[i];
        result += AsString(cp, type == 0 ? cp.AnyType : cp.GetMultiname(type));

        if (mi.HasOptionalParams())
        {
            const UPInt count = mi.ParamTypes.GetSize();
            const UPInt optCount = mi.OptionalParams.GetSize();
            if (i >= count - optCount)
            {
                result += " = " + AsString(cp, mi.OptionalParams[optCount - count + i]);
            }
        }
    }

    result.AppendString(") : ");
    // The exe's return-type getter was folded onto TraitInfo::GetName: both read the index at +4.
    result += AsString(cp, reinterpret_cast<const Abc::TraitInfo&>(mi).GetName(cp));
    return result;
}

// A constant pool multiname: "ns::name", "name", "[ns1, ns2]::name" or the namespace set alone.
// @0x1424ec200
String AsString(const Abc::ConstPool& cp, const Abc::Multiname& mn)
{
    switch (static_cast<int>(mn.Kind))
    {
    case Abc::MNF_QName:
    case Abc::MNF_QNameA:
    {
        String result;
        const SPInt ind = mn.Ind;
        const Abc::NamespaceInfo& ns = ind == 0 ? cp.any_namespace : cp.ConstNamespace[ind];
        result += AsString(ns, nsKindAndUri);
        if (!result.IsEmpty())
            result.AppendString("::");
        const StringDataPtr name = cp.GetString(static_cast<UInt32>(mn.NameIndex));
        result.AppendString(name.ToCStr(), name.GetSize());
        return result;
    }
    case Abc::MNF_RTQName:
    case Abc::MNF_RTQNameA:
    {
        const StringDataPtr name = cp.GetString(static_cast<UInt32>(mn.NameIndex));
        return String(name.ToCStr(), name.GetSize());
    }
    case Abc::MNF_RTQNameL:
    case Abc::MNF_RTQNameLA:
        return String("");
    case Abc::MNF_Multiname:
    case Abc::MNF_MultinameA:
    {
        String result;
        result = AsString(cp, cp.const_ns_set[mn.Ind], nsKindAndUri);
        if (!result.IsEmpty())
            result.AppendString("::");
        const StringDataPtr name = cp.GetString(static_cast<UInt32>(mn.NameIndex));
        result.AppendString(name.ToCStr(), name.GetSize());
        return result;
    }
    case Abc::MNF_MultinameL:
    case Abc::MNF_MultinameLA:
        return AsString(cp, cp.const_ns_set[mn.Ind], nsKindAndUri);
    default:
        return String();
    }
}

// The namespaces of a set, "[a, b]"; the empty ones are left out.
// @0x1424ec4a0
String AsString(const Abc::ConstPool& cp, const Abc::NamespaceSetInfo& nss, NamespaceText nt)
{
    String result("[");
    const UInt8* p = nss.Data;
    const unsigned count = Abc::ReadU30(p);
    for (unsigned i = 0; i < count; ++i)
    {
        const UPInt ind = (unsigned)Abc::ReadU30(p);
        const Abc::NamespaceInfo& ns = ind == 0 ? cp.any_namespace : cp.ConstNamespace[ind];
        String text = AsString(ns, nt);
        if (i != 0 && !text.IsEmpty() && result.GetSize() > 1)
            result.AppendString(", ");
        if (!text.IsEmpty())
            result += text;
    }
    return result + "]";
}

// A default value of the constant pool. The cases are in the exe's order; the int is copied before it is formatted.
// @0x1424ec630
String AsString(const Abc::ConstPool& cp, const Abc::ValueDetail& vd)
{
    const SInt32 ind = vd.ValueIndex;
    switch (static_cast<int>(vd.Kind))
    {
    case 0x03:  // int
    {
        const SInt32 v = cp.ConstInt[ind];
        return Scaleform::AsString(v);
    }
    case 0x04:  // uint (formatted inline, as in the exe)
        return Scaleform::AsString<unsigned int>(cp.ConstUInt[ind]);
    case 0x06:  // double
        return Scaleform::AsString(cp.GetDouble(ind));
    case 0x01:  // utf8
    {
        const StringDataPtr s = cp.GetString(static_cast<UInt32>(ind));
        return String(s.ToCStr(), s.GetSize());
    }
    case 0x0b:
        return String("true");
    case 0x0a:
        return String("false");
    case 0x0c:
        return String("null");
    case 0x00:  // undefined
        return String("Undefined");
    case Abc::AbcKind_PrivateNs:
    case Abc::AbcKind_Namespace:
    case Abc::AbcKind_PackageNamespace:
    case Abc::AbcKind_PackageInternalNs:
    case Abc::AbcKind_ProtectedNamespace:
    case Abc::AbcKind_ExplicitNamespace:
    case Abc::AbcKind_StaticProtectedNs:
        return AsString(ind == 0 ? cp.any_namespace : cp.ConstNamespace[ind], nsUriOnly);
    default:
        return String();
    }
}

// A run-time multiname.
// @0x1424ec990
String AsString(const Multiname& mn, NamespaceText nt)
{
    switch (static_cast<int>(mn.Kind))
    {
    case Abc::MNF_QName:
    case Abc::MNF_QNameA:
    {
        String result;
        result += AsString(*static_cast<const Instances::Namespace*>(mn.Obj.GetPtr()), nt);
        if (!result.IsEmpty())
            result.AppendString("::");
        result += AsString(mn.Name);
        return result;
    }
    case Abc::MNF_RTQName:
    case Abc::MNF_RTQNameA:
        return AsString(mn.Name);
    case Abc::MNF_RTQNameL:
    case Abc::MNF_RTQNameLA:
        return String("");
    case Abc::MNF_Multiname:
    case Abc::MNF_MultinameA:
    {
        String result;
        if (nt != nsUriOnly)
            result = AsString(*static_cast<const NamespaceSet*>(mn.Obj.GetPtr()));
        if (!result.IsEmpty())
            result.AppendString("::");
        result += AsString(mn.Name);
        return result;
    }
    case Abc::MNF_MultinameL:
    case Abc::MNF_MultinameLA:
        return AsString(*static_cast<const NamespaceSet*>(mn.Obj.GetPtr()));
    default:
        return String();
    }
}

// A VM namespace.
// @0x1424ecc40
String AsString(const Instances::Namespace& ns, NamespaceText nt)
{
    const ASString uri = ns.GetUri();
    String suri(uri.ToCStr(), uri.GetSize());

    switch (nt)
    {
    case nsUriOrAccess:
    case nsUriOnly:
        switch (ns.GetKind())
        {
        default:                        return String(suri);
        case Abc::NS_Public:            return String(suri);
        case Abc::NS_PackageInternal:   return String("internal");
        case Abc::NS_Protected:         return String("protected");
        case Abc::NS_StaticProtected:   return String("static protected");
        case Abc::NS_Private:           return String("private");
        case Abc::NS_Explicit:          return String(suri);
        }
    default:
        return String();
    case nsKindAndUri:
        return String(AsString(ns.GetKind())) + (suri.IsEmpty() ? String() : " " + suri);
    }
}

// A constant pool namespace.
// @0x1424ece90
String AsString(const Abc::NamespaceInfo& ns, NamespaceText nt)
{
    static String empty;

    switch (nt)
    {
    case nsUriOnly:
        if (ns.Kind != Abc::NS_Undefined)
        {
            if (ns.Kind == Abc::NS_Public || ns.Kind == Abc::NS_Explicit)
                return String(ns.NameURI.ToCStr(), ns.NameURI.GetSize());
            break;
        }
        return String("noname");
    case nsUriOrAccess:
        switch (ns.Kind)
        {
        case Abc::NS_Protected:         return String("protected");
        case Abc::NS_StaticProtected:   return String("static protected");
        case Abc::NS_Private:           return String("private");
        case Abc::NS_PackageInternal:   return String("internal");
        default:                        return String(ns.NameURI.ToCStr(), ns.NameURI.GetSize());
        }
    case nsKindAndUri:
        return String(AsString(ns.Kind)) + (ns.NameURI.GetSize() == 0 ? String()
                                            : " " + String(ns.NameURI.ToCStr(), ns.NameURI.GetSize()));
    }

    return String(empty);
}

static inline void Sfr01dAppend(StringBuffer& buf, const String& text)
{
    buf.AppendString(text.ToCStr(), text.GetSize());
}

// The namespaces of a VM set, "[ab]": their uris (or access words), no separator.
// @0x1424ed150
String AsString(const NamespaceSet& nss)
{
    StringBuffer buf(Memory::GetGlobalHeap());
    const ArrayLH<SPtr<Instances::Namespace> >& list = nss.GetNamespaces();
    const UPInt count = list.GetSize();
    buf.AppendChar('[');
    for (UPInt i = 0; i < count; ++i)
    {
        Sfr01dAppend(buf, AsString(*list[i].GetPtr(), nsUriOnly));
    }
    buf.AppendChar(']');
    return String(buf);
}

// The value as debug text: strings quoted, objects and classes by their type name.
// @0x1424ed240
String AsString(const Value& v)
{
    const Value::KindType kind = v.GetKind();
    if (kind >= Value::kObject && kind <= Value::kThunkFunction && v.GetObject() == NULL)
        return String("null");

    switch (kind)
    {
    case Value::kUndefined:
        return String("undefined");
    case Value::kBoolean:
        return String(v.AsBool() ? "true" : "false");
    case Value::kInt:
        return Scaleform::AsString(v.AsInt());
    case Value::kUInt:
        return Scaleform::AsString(v.AsUInt());
    case Value::kNumber:
        if (v.IsNaN())
            return String("NaN");
        if (v.IsPOSITIVE_ZERO() || v.IsNEGATIVE_ZERO() || v.IsPOSITIVE_INFINITY() || v.IsNEGATIVE_INFINITY())
            return String("0");
        return Scaleform::AsString(v.AsNumber());
    case Value::kString:
    {
        if (v.GetStringNode() == NULL)
            return String("null");
        const ASString s(v.GetStringNode());
        return ("\"" + String(s.ToCStr())) + "\"";
    }
    case Value::kThunk:
        return String("thunk");
    case Value::kThunkFunction:
        return String("thunk function");
    case Value::kVTableInd:
        return String("VTable ind: ", Scaleform::AsString(v.GetVTableInd()).ToCStr(), NULL);
    case Value::kVTableIndClosure:
        return String("VTableIndClosure");
    case Value::kFunction:
        return String("function Function() {}");
    case Value::kObject:
    {
        Object* obj = v.GetObject();
        if (obj == NULL) return String("null");
        return ("[object " + obj->GetTraits().GetName()) + "]";
    }
    case Value::kClass:
    {
        Object* obj = v.GetObject();
        if (obj == NULL) return String("null");
        return ("[class " + obj->GetTraits().GetName()) + "]";
    }
    case Value::kNamespace:
    {
        const Instances::Namespace& ns = v.AsNamespace();
        String result(AsString(ns.GetKind()));
        if (ns.GetUri().GetSize() != 0)
        {
            result.AppendString(" ");
            result.AppendString(ns.GetUri().ToCStr());
        }
        return String(result);
    }
    case Value::kThunkClosure:
        return String("ThunkClosure");
    case Value::kInstanceTraits:
    case Value::kClassTraits:
        if (v.GetTraceNullType() == Value::Null)
            return String("null");
    default:
        return String();
    }
}

// The name of a namespace kind.
// @0x1424ed700
const char* AsString(Abc::NamespaceKind kind)
{
    switch (kind)
    {
    case Abc::NS_Public:            return "public";
    case Abc::NS_Protected:         return "protected";
    case Abc::NS_StaticProtected:   return "static protected";
    case Abc::NS_Private:           return "private";
    case Abc::NS_Explicit:          return "explicit";
    case Abc::NS_PackageInternal:   return "package internal";
    default:                        return "Invalid Namespace type";
    }
}

// The modifiers of a class declaration: "dynamic ", "final ", then "interface " or "class ".
// @0x1424ed7b0
String AsStringFlag(const Abc::Instance& inst)
{
    String result;
    if (!inst.IsSealed())
        result.AppendString("dynamic ");
    if (inst.IsFinal())
        result.AppendString("final ");
    result.AppendString(!inst.IsInterface() ? "class " : "interface ");
    return result;
}

}}} // namespace Scaleform::GFx::AS3
// MS2-PIN: ??__Fempty@?1??AsString@AS3@GFx@Scaleform@@YA?AVString@3@AEBVNamespaceInfo@Abc@123@W4NamespaceText@123@@Z@YAXXZ 0x142cc92d0
