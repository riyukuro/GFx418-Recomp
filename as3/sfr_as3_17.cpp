// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_17
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424ed890-0x142509d40 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_intervaltimer.h"
#undef GetObject

namespace Scaleform { namespace GFx { namespace AS3 {
// MS2-FUNCTIONAL 0x1424ed8f0: copy and ownership semantics match; the helper-based release/addref changes the call graph.
// @0x1424ed8f0
void Value::Assign(const Value& other)
{
    if (this != &other)
    {
        Release();
        Flags = other.Flags;
        Bonus = other.Bonus;
        value = other.value;
        other.AddRef();
    }
}

// MS2-FUNCTIONAL: delegates tag selection and retain to the unsafe overload after releasing the previous value.
// @0x1424ed9d0
void Value::Assign(const ASString& v)
{
    Release();
    AssignUnsafe(v);
}

// MS2-FUNCTIONAL: delegates null-string handling and retain to the node overload after releasing the old value.
// @0x1424edab0
void Value::Assign(ASStringNode* v)
{
    Release();
    AssignUnsafe(v);
}

// MS2-FUNCTIONAL: preserves class ownership; Release/SetKind/AddRef schedule the tag cleanup and retain separately.
// @0x1424edb80
void Value::Assign(Class* v)
{
    Release();
    SetKind(kClass);
    value.VS._1.VClass = v;
    if (v)
        v->AddRef();
}

// MS2-FUNCTIONAL: uses the Value helpers for kind cleanup and reference increments.
// @0x1424edc10
void Value::Assign(Object* v)
{
    Release();
    SetKind(kObject);
    value.VS._1.VObj = v;
    if (v)
        v->AddRef();
}

// MS2-FUNCTIONAL 0x1424edce0: unsafe copy retains the same tagged references; assignment order changes the call graph.
// @0x1424edce0
void Value::AssignUnsafe(const Value& other)
{
    if (this != &other)
    {
        Flags = other.Flags;
        Bonus = other.Bonus;
        value = other.value;
        other.AddRef();
    }
}

// MS2-FUNCTIONAL: delegates string-tag and retain behavior to the node overload.
// @0x1424edd50
void Value::AssignUnsafe(const ASString& v)
{
    AssignUnsafe(v.GetNode());
}

// MS2-FUNCTIONAL: uses SetKind and ASStringNode::AddRef for the exe's explicit flag/refcount sequence.
// @0x1424eddb0
void Value::AssignUnsafe(ASStringNode* v)
{
    if (!v || v == v->GetManager()->GetNullStringNode())
    {
        SetKind(kObject);
        value.VS._1.VObj = 0;
        return;
    }
    SetKind(kString);
    value.VS._1.VStr = v;
    v->AddRef();
}

// MS2-FUNCTIONAL: uses SetKind and Class::AddRef for the exe's inline flag/refcount updates.
// @0x1424ede20
void Value::AssignUnsafe(Class* v)
{
    SetKind(kClass);
    value.VS._1.VClass = v;
    if (v)
        v->AddRef();
}

// MS2-FUNCTIONAL: uses SetKind and Object::AddRef for the exe's inline flag/refcount updates.
// @0x1424ede50
void Value::AssignUnsafe(Object* v)
{
    SetKind(kObject);
    value.VS._1.VObj = v;
    if (v)
        v->AddRef();
}

// @0x1424efa70
void IntervalTimer::Clear()
{
    Active = false;
    TimerObj = static_cast<Instances::fl_utils::Timer*>(0);
}

// MS2-FUNCTIONAL 0x1424f0b70: preserves the exe's URI-node identity and namespace-kind test using the recovered
// NamespaceSet array layout at +0x20/+0x28.
// @0x1424f0b70
bool Multiname::ContainsNamespace(const Instances::Namespace& ns) const
{
    const ASStringNode* uri = ns.GetUri().GetNode();
    const UInt8 nsKind = static_cast<UInt8>(ns.GetKind());
    const UInt32 kind = static_cast<UInt32>(Kind);
    const GASRefCountBase* object = Obj.GetPtr();
    if ((kind & 3) != 2)
    {
        const Instances::Namespace* candidate = static_cast<const Instances::Namespace*>(object);
        return candidate && candidate->GetUri().GetNode() == uri &&
               ((static_cast<UInt8>(candidate->GetKind()) ^ nsKind) & 0x0f) == 0;
    }
    if (!object)
        return false;

    const char* bytes = reinterpret_cast<const char*>(object);
    const auto* entries = *reinterpret_cast<SPtr<Instances::Namespace> const* const*>(bytes + 0x20);
    const UPInt count = *reinterpret_cast<const UPInt*>(bytes + 0x28);
    for (UPInt i = 0; i < count; ++i)
    {
        const Instances::Namespace* candidate = entries[i].GetPtr();
        if (candidate && candidate->GetUri().GetNode() == uri &&
            ((static_cast<UInt8>(candidate->GetKind()) ^ nsKind) & 0x0f) == 0)
            return true;
    }
    return false;
}

// MS2-FUNCTIONAL 0x1424f0be0: implements the exe's falsey cases for nullish, primitive, empty-string, and empty-object
// values; the numeric predicates use direct IEEE-754 bits instead of the exe's two helper calls.
// @0x1424f0be0
bool Value::Convert2Boolean() const
{
    switch (GetKind())
    {
    case kUndefined:
    case kNamespace:
        return false;
    case kBoolean:
        return AsBool();
    case kInt:
        return AsInt() != 0;
    case kUInt:
        return AsUInt() != 0;
    case kNumber:
    {
        union NumberBits { Number number; UInt64 bits; } n;
        n.number = value.VNumber;
        const UInt64 magnitude = n.bits & 0x7fffffffffffffffULL;
        const bool nan = (magnitude & 0x7ff0000000000000ULL) == 0x7ff0000000000000ULL &&
                         (magnitude & 0x000fffffffffffffULL) != 0;
        return magnitude != 0 && !nan;
    }
    case kThunk:
    case kVTableInd:
    case kThunkClosure:
    case kVTableIndClosure:
        return true;
    case kString:
        return value.VS._1.VStr && value.VS._1.VStr->Size != 0;
    case kObject:
    case kClass:
    case kFunction:
        return GetObject() != 0;
    default:
        return false;
    }
}
}}}

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {


}}} // namespace Scaleform::GFx::AS3
// THUNKS-END
