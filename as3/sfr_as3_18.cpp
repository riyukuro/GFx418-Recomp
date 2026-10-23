// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_18
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142509d40-0x142523170 .text$mn
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#undef GetObject   // windows.h

namespace Scaleform { namespace GFx { namespace AS3 {

// @0x14250cc30
SPInt Slots::GetPrevSlotIndex(SPInt ind) const
{
    const Slots* slots = this;
    while (static_cast<UPInt>(ind) < slots->FirstOwnSlotNum)
        slots = slots->Parent;
    return slots->VArray[static_cast<UPInt>(ind - static_cast<SPInt>(slots->FirstOwnSlotNum))].Prev;
}

// MS2-FUNCTIONAL 0x14250c230: returns the executable's null-tagged singleton; C++ local-static initialization differs.
// @0x14250c230
const Value& Value::GetNull()
{
    static const Value nullValue = []() {
        Value value;
        value.SetNullUnsafe();
        return value;
    }();
    return nullValue;
}

// MS2-FUNCTIONAL 0x14250f8f0: default-constructed Value has the undefined tag; local-static initialization differs.
// @0x14250f8f0
const Value& Value::GetUndefined()
{
    static const Value undefinedValue;
    return undefinedValue;
}

// MS2-FUNCTIONAL 0x14250aa50: the empty public URI fast path and interned instance result match; factory call placement differs.
// @0x14250aa50
Instances::Namespace& VM::GetInternedNamespace(Abc::NamespaceKind kind, const ASString& uri) const
{
    if (uri.IsEmpty() && kind == Abc::NS_Public)
        return GetPublicNamespace();
    InstanceTraits::fl::Namespace& traits =
        static_cast<InstanceTraits::fl::Namespace&>(GetClassTraitsNamespace().GetInstanceTraits());
    Pickable<Instances::Namespace> ns = traits.MakeInternedInstance(kind, uri, Value::GetUndefined());
    return *ns;
}

// MS2-FUNCTIONAL 0x14250aac0: builds the URI node with the VM string manager and delegates to the shared interner.
// @0x14250aac0
Instances::Namespace& VM::GetInternedNamespace(Abc::NamespaceKind kind, const StringDataPtr& uri) const
{
    ASString value = GetStringManager().CreateString(uri.ToCStr(), uri.GetSize());
    return GetInternedNamespace(kind, value);
}

// MS2-FUNCTIONAL 0x14250ab50: normalizes a null C string to empty before interning.
// @0x14250ab50
Instances::Namespace& VM::GetInternedNamespace(Abc::NamespaceKind kind, const char* uri) const
{
    ASString value = GetStringManager().CreateString(uri ? uri : "", uri ? strlen(uri) : 0);
    return GetInternedNamespace(kind, value);
}

// MS2-FUNCTIONAL 0x14250a900: tracer-only and class-traits tags still need exact edge-case matching.
// @0x14250a900
// The executable selects the boxed primitive traits from the value kind and takes the
// instance traits directly from reference values. The remaining tracer-only tags are
// deliberately mapped through their public Value accessors; their uncommon edge cases
// still need byte-level comparison.
const InstanceTraits::Traits& VM::GetInstanceTraits(const Value& v) const
{
    switch (v.GetKind())
    {
    case Value::kBoolean: return GetClassTraitsBoolean().GetInstanceTraits();
    case Value::kInt:     return GetClassTraitsSInt().GetInstanceTraits();
    case Value::kUInt:    return GetClassTraitsUInt().GetInstanceTraits();
    case Value::kNumber:  return GetClassTraitsNumber().GetInstanceTraits();
    case Value::kString:  return GetClassTraitsString().GetInstanceTraits();
    case Value::kNamespace: return GetClassTraitsNamespace().GetInstanceTraits();
    case Value::kClass:   return v.AsClass().GetInstanceTraits();
    case Value::kFunction:
    case Value::kThunk:
    case Value::kThunkFunction:
        return GetClassTraitsFunction().GetInstanceTraits();
    case Value::kUndefined:
    case Value::kMethodInd:
    case Value::kVTableInd:
    case Value::kVTableIndClosure:
        return GetClassTraitsVoid().GetInstanceTraits();
    default:
        if (v.IsNull())
            return GetClassTraitsNull().GetInstanceTraits();
        return v.GetInstanceTraits();
    }
}

// MS2-FUNCTIONAL 0x14250be40: iterator preserves bucket order; exact tombstone boundary comparison remains to verify.
// @0x14250be40
GlobalSlotIndex Object::GetNextDynPropIndex(GlobalSlotIndex ind) const
{
    const DynAttrsType& attrs = DynAttrs;
    DynAttrsType::ConstIterator it = attrs.Begin();
    const UPInt start = ind.IsValid() ? static_cast<UPInt>(ind.Get() - 1) : 0;
    for (; !it.IsEnd(); ++it)
    {
        if (static_cast<UPInt>(it.GetIndex()) < start)
            continue;
        if ((it->First.Flags & 1) == 0)
            return GlobalSlotIndex(static_cast<UInt32>(it.GetIndex() + 1));
    }
    return GlobalSlotIndex(0);
}

// MS2-FUNCTIONAL 0x14250c010: name lookup follows the recovered bucket index; invalid-index behavior remains to verify.
// @0x14250c010
void Object::GetNextPropertyName(Value& name, GlobalSlotIndex ind) const
{
    const UPInt target = ind.IsValid() ? static_cast<UPInt>(ind.Get() - 1) : 0;
    for (DynAttrsType::ConstIterator it = DynAttrs.Begin(); !it.IsEnd(); ++it)
    {
        if (static_cast<UPInt>(it.GetIndex()) == target)
        {
            name.Assign(it->First.Name);
            return;
        }
    }
    name.SetUndefined();
}

// ==== Value: references ====

// @0x14251c720
void Value::Pick(Value& other)
{
    Release();
    Flags = other.Flags;
    Bonus = other.Bonus;
    value = other.value;
    other.Flags = kUndefined;
}

// @0x14251c7a0
void Value::Pick(Class* v)
{
    Release();
    SetKind(kClass);
    value = v;
}

// @0x14251c820
void Value::Pick(Object* v)
{
    Release();
    SetKind(kObject);
    value = v;
}

// A weak reference becomes a strong one (undefined when its object is gone).
// MS2-FUNCTIONAL ?MakeStrongRef@Value@AS3@GFx@Scaleform@@QEAA_NXZ: same AddRef switch; the exe schedules the final Bonus/flag stores differently and encodes the kind mask as imm32
// @0x142516670
bool Value::MakeStrongRef()
{
    if (IsWeakRef())
    {
    if (IsValidWeakRef())
    {
        switch (GetKind())
        {
        case kString:
            ++value.VS._1.VStr->RefCount;
            break;
        case kNamespace:
        case kObject:
        case kClass:
        case kFunction:
        case kThunkFunction:
            if (value.VS._1.VObj)
                value.VS._1.VObj->AddRef();
            break;
        case kThunkClosure:
        case kVTableIndClosure:
            if (value.VS._2.VObj)
                value.VS._2.VObj->AddRef();
            break;
        default:
            break;
        }
        Bonus.pWeakProxy->Release();
    }
    else
    {
        value.VS._1.VObj = NULL;
        SetKind(kUndefined);
        value.VS._2.VObj = NULL;
    }

    Bonus.pWeakProxy = NULL;
    Flags &= ~weakRefMask;
    return true;
    }
    return false;
}

// @0x142522190
void Value::ReleaseWeakRef()
{
    Bonus.pWeakProxy->Release();
    Flags &= ~(kindMask | weakRefMask);
    Bonus.pWeakProxy = NULL;
    value.VS._1.VObj = NULL;
    value.VS._2.VObj = NULL;
}

// @0x1425157a0
bool Value::IsValidWeakRef() const
{
    if (IsWeakRef())
        return Bonus.pWeakProxy->pObject != NULL;
    return true;
}

// @0x142514bf0
bool IsQNameObject(const Value& v)
{
    if (v.IsObject() && v.GetObject())
    {
        const Traits& tr = v.GetObject()->GetTraits();
        return tr.GetTraitsType() == Traits_QName && tr.IsInstanceTraits();
    }
    return false;
}

// @0x1425157c0
bool IsXMLListObject(Object* obj)
{
    bool result = false;
    if (obj && obj->GetTraits().GetTraitsType() == Traits_XMLList && obj->GetTraits().IsInstanceTraits())
        result = true;
    return result;
}

// @0x1425157f0
bool IsXMLObject(Object* obj)
{
    bool result = false;
    if (obj && obj->GetTraits().GetTraitsType() == Traits_XML && obj->GetTraits().IsInstanceTraits())
        result = true;
    return result;
}

// A string of decimal digits, optionally followed by '.' and zeros only: its number.
// @0x14250ee30
CheckResult GetStrNumber(ASStringNode* str, Value::Number& result)
{
    if (str == NULL || str->Size == 0)
        return false;
    const char* s = str->pData;
    if (static_cast<UByte>(s[0] - '0') > 9)
        return false;
    for (unsigned i = 1; i < str->Size; ++i)
    {
        if (static_cast<UByte>(s[i] - '0') > 9)
        {
            if (s[i] != '.')
                return false;
            for (++i; i < str->Size; ++i)
            {
                if (s[i] != '0')
                    return false;
            }
            break;
        }
    }
    char* end;
    result = strtod(s, &end);
    return true;
}

// ==== slots, traits, classes ====

// MS2-FUNCTIONAL: the exe materializes the own/parent test as a bool before branching
// @0x14250dce0
ASStringNode* Slots::GetSlotNameNode(AbsoluteIndex ind) const
{
    bool inParent;
    if (ind.Get() < 0)
        inParent = true;
    else
        inParent = static_cast<UPInt>(ind.Get()) < FirstOwnSlotNum;
    if (inParent)
        return Parent->GetSlotNameNode(ind);
    return VArray[static_cast<UInt32>(ind.Get()) - FirstOwnSlotNum].Key.GetPtr();
}

// @0x142511400
void Slots::Inherit(const Slots& p)
{
    Parent = &p;
    FirstOwnSlotNum = p.FirstOwnSlotNum + p.VArray.GetSize();
    Set = p.Set;
}

// MS2-FUNCTIONAL: the exe inlines the Value copy's AddRef switch; ours calls it
// @0x14250fd90
Value VTable::GetValue(AbsoluteIndex ind) const
{
    const Value& v = VTMethods[static_cast<UInt32>(ind.Get())];
    if (v.IsMethodInd())
        return Value(static_cast<SInt32>(ind.Get()), *pTraits, Value::kVTableInd);
    return v;
}

// MS2-FUNCTIONAL: same calls; register allocation and the separator select differ
// @0x14250d570
ASString InstanceTraits::Traits::GetQualifiedName(QNameFormat f) const
{
    const Instances::Namespace& ns = GetNamespace();
    const ASString name = GetName();
    if (ns.GetUri().IsEmpty())
        return name;
    return ns.GetUri() + (f == qnfWithColons ? "::" : ".") + name;
}

// @0x14250d4c0
Object& Class::GetPrototype()
{
    if (!pPrototype)
    {
        pPrototype = MakePrototype();
        InitPrototype(*pPrototype);
    }
    return *pPrototype;
}

// The value of a traced pointer: a null object when it is empty.
// MS2-FUNCTIONAL: the exe inlines AssignUnsafe(Object*/Class*) and calls Value::SetNull; ours the reverse
// @0x1425100f0
void STPtr::GetValueUnsafe(Value& v)
{
    if (pObject)
    {
        ObjType* p = GetRawAddr();
        switch (AS3::GetObjectTag(reinterpret_cast<UPInt>(pObject)))
        {
        case Value::otObject:
            v.AssignUnsafe(static_cast<Object*>(p));
            return;
        case Value::otClass:
            v.AssignUnsafe(static_cast<Class*>(p));
            return;
        case Value::otFunction:
            v.AssignUnsafe(reinterpret_cast<Instances::Function*>(p));   // (not modeled; its counted base is first)
            return;
        case Value::otNamespace:
            v.AssignUnsafe(static_cast<Instances::Namespace*>(p));
            return;
        default:
            break;
        }
    }
    v.SetNull();
}

// ==== VM: interned namespaces ====

// @0x1425162a0
Pickable<Instances::Namespace> VM::MakeInternedNamespace(Abc::NamespaceKind kind, const ASString& uri) const
{
    if (uri.IsEmpty() && kind == Abc::NS_Public)
    {
        Instances::Namespace* ns = PublicNamespace.GetPtr();
        if (ns)
            ns->AddRef();
        return Pickable<Instances::Namespace>(ns);
    }
    InstanceTraits::fl::Namespace& itr =
        static_cast<InstanceTraits::fl::Namespace&>(GetClassTraitsNamespace().GetInstanceTraits());
    return itr.MakeInternedInstance(kind, uri, Value::GetUndefined());
}

// @0x142516340
Pickable<Instances::Namespace> VM::MakeInternedNamespace(Abc::NamespaceKind kind, const StringDataPtr& uri) const
{
    return MakeInternedNamespace(kind, GetStringManager().CreateString(uri.ToCStr(), uri.GetSize()));
}

// @0x142516400
Pickable<Instances::Namespace> VM::MakeInternedNamespace(Abc::NamespaceKind kind, const char* name) const
{
    return MakeInternedNamespace(kind, GetStringManager().CreateString(name ? name : ""));
}

}}} // namespace Scaleform::GFx::AS3

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {


}}} // namespace Scaleform::GFx::AS3
// THUNKS-END
