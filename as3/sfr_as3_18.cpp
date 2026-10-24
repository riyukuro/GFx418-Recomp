// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_18
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142509d40-0x142523170 .text$mn
#include <math.h>
#include <stdlib.h>
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/as3_vec_base.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/gfx_loaderimpl.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"
#undef GetObject   // windows.h

void* FUN_14241ba70(void* traits, void* ret, int kind, const void* uri, const void* prefix);   // Namespace::MakeInternedInstance
char* FUN_14250e2d0(const void* si, void* ret, Scaleform::GFx::AS3::VM* vm, Scaleform::GFx::AS3::Value* value, const Scaleform::GFx::AS3::Value* thisValue, void* vtable, int valTarget);   // SlotInfo: read the slot into value
void FUN_1425f9ba0(Scaleform::UPInt self, char* ret);
Scaleform::UPInt FUN_142525ca0(Scaleform::UPInt a, Scaleform::UPInt b);
bool FUN_1425b9b10(Scaleform::UPInt textField);
Scaleform::UPInt FUN_1425b7e60(Scaleform::UPInt textField);
Scaleform::UPInt FUN_14250ffc0(Scaleform::GFx::AS3::VM* vm, const Scaleform::GFx::AS3::Value* v);   // the traits of a value

namespace Scaleform { namespace GFx { namespace AS3 {

namespace {
const Value& GetNullSingleton()
{
    static const Value nullValue = []() {
        Value value;
        value.SetNullUnsafe();
        return value;
    }();
    return nullValue;
}
}

// MS2-FUNCTIONAL 0x14250a1b0: kind-to-trait selection matches; exe branches before following the VM trait pointer chain.
// @0x14250a1b0
InstanceTraits::Traits& TR::State::GetFunctType(const Value& value) const
{
    const UPInt stateRoot = *reinterpret_cast<const UPInt*>(this);
    const UPInt traceContext = *reinterpret_cast<const UPInt*>(stateRoot + 0x20);
    const UPInt vmTraits = *reinterpret_cast<const UPInt*>(traceContext + 0x28);
    const UPInt builtinTraits = *reinterpret_cast<const UPInt*>(vmTraits + 0x20);
    const UPInt functions = *reinterpret_cast<const UPInt*>(builtinTraits + 0x208);
    const UInt32 kind = *reinterpret_cast<const UInt32*>(&value) & 0x1f;
    UPInt offset = 0xc0;
    if (kind == 5)
        offset = 0xc8;
    else if (kind != 7)
    {
        if (kind == 0x10)
            offset = 0xd0;
        else if (kind == 0x11)
            offset = 0xe0;
    }
    else
        offset = 0xe0;
    return **reinterpret_cast<InstanceTraits::Traits**>(functions + offset);
}

// @0x14250cc30
SPInt Slots::GetPrevSlotIndex(SPInt ind) const
{
    const Slots* slots = this;
    while (static_cast<UPInt>(ind) < slots->FirstOwnSlotNum)
        slots = slots->Parent;
    return slots->VArray[static_cast<UPInt>(ind - static_cast<SPInt>(slots->FirstOwnSlotNum))].Prev;
}

// MS2-FUNCTIONAL 0x14250c230: returns the same null singleton; the exe keeps its TLS initializer inside this function.
// @0x14250c230
const Value& Value::GetNull()
{
    return GetNullSingleton();
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
    Pickable<Instances::Namespace> ns;
    FUN_14241ba70(&traits, &ns, kind, &uri, &Value::GetUndefined());
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

// A collectable reference: a tagged pointer (low bit set) holds no count and is only untagged.
static SF_INLINE void ReleaseGCRef(Object*& p)
{
    if (reinterpret_cast<UPInt>(p) & 1)
        p = reinterpret_cast<Object*>(reinterpret_cast<UPInt>(p) - 1);
    else if (p)
        p->Release();
}

// @0x142521f00
void Value::ReleaseInternal()
{
    switch (GetKind())
    {
    case kString:
        value.VS._1.VStr->Release();
        break;
    case kNamespace:
        ReleaseGCRef(value.VS._1.VObj);
        break;
    case kObject:
        ReleaseGCRef(value.VS._1.VObj);
        break;
    case kClass:
        ReleaseGCRef(value.VS._1.VObj);
        break;
    case kFunction:
        ReleaseGCRef(value.VS._1.VObj);
        break;
    case kThunkFunction:
        ReleaseGCRef(value.VS._1.VObj);
        break;
    case kThunkClosure:
        ReleaseGCRef(value.VS._2.VObj);
        break;
    case kVTableIndClosure:
        ReleaseGCRef(value.VS._2.VObj);
        break;
    default:
        break;
    }
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

// ==== vector indices ====

// The largest vector index, 2^32 - 1.
static const double kMaxVectorInd = 4294967295.0;

// @0x142510800
CheckResult GetVectorInd(const Multiname& prop_name, UInt32& ind)
{
    bool result = false;
    const Value& name = prop_name.Name;
    switch (name.GetKind())
    {
    case Value::kInt:
        if (name.AsInt() >= 0)
        {
            ind = name.AsInt();
            result = true;
        }
        break;
    case Value::kUInt:
        ind = name.AsUInt();
        result = true;
        break;
    case Value::kNumber:
    {
        const Value::Number d = name.AsNumber();
        Value::Number ip;
        if (d >= 0 && modf(d, &ip) == 0 && d <= kMaxVectorInd)
        {
            ind = static_cast<UInt32>(d);
            result = true;
        }
        break;
    }
    case Value::kString:
        result = GetVectorInd(name.GetStringNode(), ind);
        break;
    default:
        break;
    }
    return result;
}

// Whether s[0, size) is an array index: digits, optionally followed by '.' and nothing but zeros ("3.000").
static inline bool IsIndexString(const char* s, UInt32 size)
{
    if (static_cast<UByte>(s[0] - '0') > 9)
        return false;
    for (UInt32 i = 1; i < size; ++i)
    {
        const char c = s[i];
        if (static_cast<UByte>(c - '0') > 9)
        {
            if (c != '.')
                return false;
            for (UInt32 j = i + 1; j < size; ++j)
                if (s[j] != '0')
                    return false;
            break;
        }
    }
    return true;
}

// @0x142510960
CheckResult GetVectorInd(ASStringNode* node, UInt32& ind)
{
    bool result = false;
    if (node && node->Size != 0 && IsIndexString(node->pData, node->Size))
    {
        char* end;
        const double d = strtod(node->pData, &end);
        if (d <= kMaxVectorInd)
        {
            ind = static_cast<UInt32>(d);
            result = true;
        }
    }
    return result;
}

// ==== value stack and register file pages ====

// MS2-FUNCTIONAL: the exe inlines AllocPage (out of line in sfr_as3_16) into the not-found path
// @0x1425182a0
ValueStack::Page* ValueStack::NewPage(UInt16 pageSize)
{
    Page* p = pReserved;
    for (; p; p = p->pNext)
        if (pageSize <= p->PageSize)
            break;
    if (!p)
        return AllocPage(pageSize);

    if (p == pReserved)
    {
        pReserved = p->pNext;
        if (pReserved)
            pReserved->pPrev = NULL;
    }
    else
    {
        p->pPrev->pNext = p->pNext;
        if (p->pNext)
            p->pNext->pPrev = p->pPrev;
        p->pPrev = NULL;
    }
    p->pNext = NULL;
    return p;
}

// MS2-FUNCTIONAL: the exe inlines AllocPage (out of line in sfr_as3_16) into the not-found path
// @0x1425181c0
ValueRegisterFile::Page* ValueRegisterFile::NewPage(UInt16 pageSize)
{
    if (pageSize <= Unk02)
    {
        Page* p = pReservedPage;
        for (; p; p = p->pNext)
            if (pageSize <= p->PageSize)
                break;
        if (p)
        {
            if (p == pReservedPage)
            {
                pReservedPage = p->pNext;
                if (pReservedPage)
                    pReservedPage->pPrev = NULL;
            }
            else
            {
                p->pPrev->pNext = p->pNext;
                if (p->pNext)
                    p->pNext->pPrev = p->pPrev;
                p->pPrev = NULL;
            }
            p->pNext = NULL;
            return p;
        }
    }
    return AllocPage(pageSize);
}

// @0x142521fb0
void ValueRegisterFile::ReleaseReserved(UInt16 num)
{
    for (UInt16 i = 0; i < num; ++i)
        pRF[i].Release();
    Unk00 -= num;

    Page* cur = pCurrentPage;
    --cur->CurrPos;
    pRF -= GetReservations(cur)[cur->CurrPos];

    if (Unk00 == 0 && pCurrentPage->pPrev)
    {
        // the page is empty: back to the reserved list, the previous one becomes current
        Unk02 = Alg::Max(pCurrentPage->PageSize, Unk02);
        Page* prev = pCurrentPage->pPrev;
        pCurrentPage->pPrev = NULL;
        pCurrentPage->pNext = pReservedPage;
        pReservedPage = pCurrentPage;
        pCurrentPage = prev;
        prev->pNext = NULL;
        Unk00 = pCurrentPage->ReservedNum;
        pRF = pCurrentPage->pCurrent;
    }
}

// ==== VMAbcFile ====

// @0x142515b30
CheckResult VMAbcFile::Load(bool to_execute)
{
    return RegisterUserDefinedClassTraits() && RegisterScrips(to_execute);
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
    Pickable<Instances::Namespace> r;
    FUN_14241ba70(&itr, &r, kind, &uri, &Value::GetUndefined());
    return r;
}

// @0x142516340
Pickable<Instances::Namespace> VM::MakeInternedNamespace(Abc::NamespaceKind kind, const StringDataPtr& uri) const
{
    return MakeInternedNamespace(kind, GetStringManager().CreateString(uri.ToCStr(), uri.GetSize()));
}

// MS2-FUNCTIONAL 0x142516400: the exe inlines the string creation and the interned factory call with a different frame.
// @0x142516400
Pickable<Instances::Namespace> VM::MakeInternedNamespace(Abc::NamespaceKind kind, const char* name) const
{
    return MakeInternedNamespace(kind, GetStringManager().CreateString(name ? name : ""));
}

// ==== traits vtable ====

SF_INLINE VTable::VTable(Traits& tr)
    : pTraits(&tr), Names(tr.GetVM().GetStringManager().CreateEmptyString())
{
}

SF_INLINE VTable::VTable(Traits& tr, const VTable& parent)
    : pTraits(&tr), VTMethods(parent.VTMethods), Names(parent.Names)
{
}

// MS2-FUNCTIONAL: the exe inlines the Value/ASString array copies (its ArrayData::ResizeNoConstruct is out of line);
// here the array copy ctors stay out of line
// @0x14250fa80
VTable& Traits::GetVT() const
{
    if (!pVTable)
    {
        if (pParent.GetPtr())
            pVTable = SF_HEAP_NEW(pVM->GetMemoryHeap()) VTable(*const_cast<Traits*>(this), pParent->GetVT());
        else
            pVTable = SF_HEAP_NEW(pVM->GetMemoryHeap()) VTable(*const_cast<Traits*>(this));
    }
    return *pVTable;
}

// ==== prototypes ====

// Whether slot i belongs to the parent table (a negative index counts as one).
static SF_INLINE bool IsParentSlot(const Slots& s, SPInt i)
{
    if (i < 0)
        return true;
    return static_cast<UPInt>(i) < s.FirstOwnSlotNum;
}

// Whether slot i is not past the end of the table.
static SF_INLINE bool IsBeforeEnd(const Slots& s, SPInt i)
{
    if (i < 0)
        return true;
    return static_cast<UPInt>(i) < s.GetSlotInfoNum();
}

// MS2-FUNCTIONAL: the exe calls the parent slot lookups out of line and re-reads FirstOwnSlotNum after each call
// @0x142511890
void Class::InitPrototypeFromVTable(AS3::Object& obj, ConvertFunc f) const
{
    InstanceTraits::Traits& itr = GetInstanceTraits();
    const VTable& vt = itr.GetVT();
    for (SPInt i = 0; static_cast<UInt32>(i) < itr.GetSlotInfoNum(); )
    {
        const SlotInfo& si = IsParentSlot(itr, i) ? itr.Parent->GetSlotInfo(AbsoluteIndex(i))
                                                  : itr.VArray[static_cast<UInt32>(i) - itr.FirstOwnSlotNum].Value;
        if (si.BindType == SlotInfo::BT_Code)
        {
            ASStringNode* name = IsParentSlot(itr, i) ? itr.Parent->GetSlotNameNode(AbsoluteIndex(i))
                                                      : itr.VArray[static_cast<UInt32>(i) - itr.FirstOwnSlotNum].Key.GetPtr();
            obj.AddDynamicSlotValuePair(ASString(name), (this->*f)(vt.VTMethods[si.ValueInd], itr),
                                        SlotInfo::aDontEnum);
        }
        if (IsBeforeEnd(itr, i))
            ++i;
    }
}

// @0x142511ac0
void Class::InitPrototypeFromVTableCheckType(AS3::Object& obj) const
{
    InitPrototypeFromVTable(obj, &Class::ConvertCheckType);
}

// @0x142511810
void Class::InitPrototype(AS3::Object& obj) const
{
    if (GetParentClass())
        GetParentClass()->InitPrototype(obj);
    InitPrototypeFromVTable(obj, &Class::ConvertCheckType);
    AddConstructor(obj);
}

// ==== MovieRoot ====

// @0x14250da50
bool MovieRoot::GetRootFilePath(String* ppath) const
{
    MovieImpl* pmovieImpl = pMovieImpl;
    if (pmovieImpl->pMainMovie)
    {
        *ppath = pmovieImpl->pMainMovieDef->GetFileURL();
        if (URLBuilder::ExtractFilePath(ppath))
            return true;
    }
    ppath->Clear();
    return false;
}

// @0x14250bb10
void MovieRoot::GetMouseCursorTypeString(ASString& str, unsigned cursorType) const
{
    switch (cursorType)
    {
    case 0:  str = GetStringManager418()->CreateConstString("arrow", 5); break;
    case 1:  str = GetStringManager418()->CreateConstString("hand", 4); break;
    case 2:  str = GetStringManager418()->CreateConstString("ibeam", 5); break;
    case 3:  str = GetStringManager418()->CreateConstString("button", 6); break;
    default: str = GetStringManager418()->CreateConstString("auto", 4); break;
    }
}


// @0x14250bc40
ASString ClassTraits::Traits::GetName() const
{
    return GetInstanceTraits().GetName();
}

// @0x14250d550
ASString ClassTraits::Traits::GetQualifiedName(QNameFormat f) const
{
    return GetInstanceTraits().GetQualifiedName(f);
}

// @0x14250bbd0
ASString InstanceTraits::CTraits::GetName() const
{
    return GetVM().GetStringManager().GetStringManager()->CreateConstString(CI.GetName());
}

// @0x14250c060
void Object::GetNextPropertyValue(Value& value, GlobalSlotIndex ind)
{
    if (ind.IsValid())
        GetDynamicProperty(AbsoluteIndex(static_cast<SPInt>(ind.Get()) - 1), value);
}

// @0x142516270
Pickable<Instances::fl::Array> VM::MakeArray() const
{
    InstanceTraits::fl::Array& itr = static_cast<InstanceTraits::fl::Array&>(TraitsArray->GetInstanceTraits());
    return itr.MakeInstance(itr);
}

// @0x142516600
Pickable<Instances::fl::Object> VM::MakeObject() const
{
    InstanceTraits::fl::Object& itr = static_cast<InstanceTraits::fl::Object&>(TraitsObject->GetInstanceTraits());
    return itr.MakeInstance(itr);
}

// @0x142516630
Pickable<Object> Class::MakePrototype() const
{
    return GetVM().MakeObject();
}

// @0x1425165a0
void InstanceTraits::Traits::MakeObject(Value& result, Traits& t)
{
    // Traits::Alloc inlined
    void* mem;
    {
        AllocInfo info(StatMV_VM_Instance_Mem, NULL, 0);
        mem = t.GetVM().GetMemoryHeap()->Alloc(t.GetMemSize(), &info);
    }
    result.Pick(new(mem) Instances::fl::Object(t));
}

// @0x142521eb0
void AvmDisplayObj::ReleaseAS3Obj()
{
    reinterpret_cast<SPtr<Instances::fl_display::DisplayObject>&>(pAS3CollectiblePtr) = NULL;
    pAS3RawPtr = NULL;
}


// @0x142514f70
bool AvmInteractiveObj::IsTabable() const
{
    if (!pDispObj->GetVisible())
        return false;
    const InteractiveObject* io = GetIntObj();
    if (io->Flags & InteractiveObject::Mask_TabEnabled)
        return (io->Flags & InteractiveObject::Mask_TabEnabled) == InteractiveObject::Mask_TabEnabled;
    if (io->TabIndex > 0)
        return true;
    return false;
}

// @0x1425142a0
bool AvmSprite::IsFocusEnabled(FocusMovedType fmt) const
{
    switch (fmt)
    {
    case GFx_FocusMovedByMouse:
        if (!(SprFlags & Flag_ButtonMode) && !IsTabable())
            return false;
        return true;
    case GFx_FocusMovedByAS:
        return true;
    }
    return ActsAsButton();
}

// @0x142514fc0
bool AvmSprite::IsTabable() const
{
    if (!pDispObj->GetVisible())
        return false;
    const Sprite* spr = GetSprite();
    const unsigned te = spr->InteractiveObject::Flags & InteractiveObject::Mask_TabEnabled;
    if (te != 0)
    {
        if (te != InteractiveObject::Mask_TabEnabled)
            return false;
        // tabEnabled set: tabable unless an ancestor has tabChildren off
        for (const InteractiveObject* p = spr->GetParent(); p; p = p->GetParent())
        {
            const bool off = (p->Flags >> 15) & 1;    // Mask_TabChildrenDisabled
            if (off)
                return false;
        }
        return true;
    }
    if (spr->TabIndex > 0)
        return true;
    return (SprFlags & Flag_ButtonMode) != 0;
}

// @0x14250bd10
SF_NOINLINE MovieRoot::ActionEntry* MovieRoot::ActionQueueType::GetNewEntry()
{
    ActionEntry* pentry;
    if (pFreeEntry)
    {
        pentry = pFreeEntry;
        pFreeEntry = pentry->pNextEntry;
        pentry->pNextEntry = NULL;
        --FreeEntriesCount;
    }
    else
    {
        pentry = SF_HEAP_NEW(pHeap) ActionEntry;
        if (!pentry)
            return NULL;
        pentry->ClearAction();
    }
    return pentry;
}

// @0x142512800
MovieRoot::ActionEntry* MovieRoot::ActionQueueType::InsertEntry(ActionLevel lvl)
{
    ActionEntry* pentry = GetNewEntry();
    ActionQueueEntry& q = Entries[lvl];
    if (!q.pInsertEntry)
    {
        pentry->pNextEntry = q.pActionRoot;
        q.pActionRoot = pentry;
    }
    else
    {
        pentry->pNextEntry = q.pInsertEntry->pNextEntry;
        q.pInsertEntry->pNextEntry = pentry;
    }
    q.pInsertEntry = pentry;
    if (!pentry->pNextEntry)
        q.pLastEntry = pentry;
    ++ModId;
    return pentry;
}

// @0x142512790
MovieRoot::ActionEntry* MovieRoot::InsertEmptyAction(ActionLevel lvl)
{
    return ActionQueue.InsertEntry(lvl);
}

// @0x142512750
void AvmInteractiveObj::InsertChildToPlayList(InteractiveObject* ch)
{
    if (InteractiveObject* pafter = FindInsertToPlayList(ch))
        ch->InsertToPlayListAfter(pafter);
    else
        ch->AddToPlayList();
}

// @0x142514340
bool AvmSprite::IsLevelMovie() const
{
    return pDispObj->GetParent() == NULL;
}

// @0x142514f10
bool AvmDisplayObjContainer::IsTabable() const
{
    if (!pDispObj->GetVisible())
        return false;
    const InteractiveObject* io = GetIntObj();
    if (io->Flags & InteractiveObject::Mask_TabEnabled)
        return (io->Flags & InteractiveObject::Mask_TabEnabled) == InteractiveObject::Mask_TabEnabled;
    return io->TabIndex > 0;
}

// MS2-FUNCTIONAL: same code, the exe keeps strlen+1 in rdi and the copy in rbx (registers swapped)
// @0x142511760
void AvmDisplayObj::InitClassName(const char* name)
{
    if (!pClassName)
    {
        const UPInt len = SFstrlen(name) + 1;
        char* p = static_cast<char*>(SF_HEAP_AUTO_ALLOC(pDispObj, len));
        memcpy(p, name, len);
        pClassName = p;
    }
}

// @0x14250c2e0
bool AvmDisplayObj::GetObjectsUnderPoint(ArrayDH<Ptr<DisplayObjectBase> >* destArray, const Render::PointF& pt) const
{
    if (pDispObj->PointTestLocal(pt, 1))   // test the shape
    {
        destArray->InsertAt(0, Ptr<DisplayObjectBase>(pDispObj));
        return true;
    }
    return false;
}

// @0x14250c7c0
bool AvmSprite::GetObjectsUnderPoint(ArrayDH<Ptr<DisplayObjectBase> >* destArray, const Render::PointF& pt) const
{
    bool ret = AvmDisplayObjContainer::GetObjectsUnderPoint(destArray, pt);
    if (!ret && GetSprite()->pDrawingAPI)
    {
        DrawingContext* pdc = GetSprite()->GetDrawingContext();
        ret = pdc->DefPointTestLocal(pt, true, pDispObj);
        if (ret)
            destArray->InsertAt(0, Ptr<DisplayObjectBase>(pDispObj));
    }
    return ret;
}

// @0x14251d000
MovieRoot::ActionEntry* MovieRoot::ActionQueueType::PrependEntry(ActionLevel lvl)
{
    ActionEntry* pentry = GetNewEntry();
    ActionQueueEntry& q = Entries[lvl];
    pentry->pNextEntry = q.pActionRoot;
    q.pActionRoot = pentry;
    if (!q.pInsertEntry)
        q.pInsertEntry = pentry;
    if (!pentry->pNextEntry)
        q.pLastEntry = pentry;
    ++ModId;
    return pentry;
}

// MS2-FUNCTIONAL: the exe untags with a branch (dec), cl picks a cmove
// @0x1425189a0
void AvmDisplayObj::OnDetachFromTimeline()
{
    pAS3RawPtr = GetAS3Obj();
    reinterpret_cast<SPtr<Instances::fl_display::DisplayObject>&>(pAS3CollectiblePtr) = NULL;
}

// A sprite advances while it has a frame to execute or an enterFrame listener.
// @0x142518160
bool AvmSprite::MustBeInPlaylist() const
{
    if (!(SprFlags & Flag_NeedExecuteFrame) && !HasEventHandler(EventId(EventId::Event_EnterFrame)))
        return false;
    return true;
}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx {

// The focus rectangle defaults to the local bounds.
// @0x142509d40
RectF InteractiveObject::GetFocusRect() const
{
    return GetBounds(Matrix());
}

// @0x142515190
bool DisplayObject::IsUsedAsMask() const
{
    return IsUsedAsMaskFlagSet();
}

}} // namespace Scaleform::GFx

// ---- Tracer type predicates and value traits (the Tracer is not modeled: raw offsets through its pointer chain) ----
namespace Scaleform { namespace GFx { namespace AS3 { namespace TR {

namespace {
inline UPInt TrRd(UPInt base, UPInt off) { return *reinterpret_cast<const UPInt*>(base + off); }
// tracer -> method info -> the VM
inline UPInt TrVM(UPInt tracer) { return TrRd(TrRd(TrRd(tracer, 0x20), 0x28), 0x20); }
// the instance traits of one of the VM's builtin classes
inline UPInt TrBuiltin(UPInt vm, UPInt off) { return TrRd(TrRd(vm, off), 0xc0); }
}

// The traits a tracer value stands for: undefined is void, traits values themselves, the rest their own class.
// Class is read as Object.
static UPInt TraceValueTraits(UPInt tracer, const Value* v)
{
    const UPInt vm = TrVM(tracer);
    const UInt32 k = static_cast<UInt32>(v->GetKind());
    UPInt t;
    if (k == 0)
        t = TrRd(vm, 0x278);
    else if (k == 8 || k == 9)
        t = TrRd(reinterpret_cast<UPInt>(v), 0x10);
    else
        t = FUN_14250ffc0(reinterpret_cast<VM*>(vm), v);
    if (t != 0 && t == TrRd(vm, 0x1f0))
        t = TrRd(vm, 0x1f8);
    return t;
}

// @0x142514000
bool Sfr27TracerIsBooleanType(UPInt tracer, const Value* v)
{
    return TraceValueTraits(tracer, v) == TrBuiltin(TrVM(tracer), 0x210);
}
// @0x142514470
bool Sfr27TracerIsNumberType(UPInt tracer, const Value* v)
{
    return TraceValueTraits(tracer, v) == TrBuiltin(TrVM(tracer), 0x218);
}
// @0x142514c30
bool Sfr27TracerIsIntType(UPInt tracer, const Value* v)
{
    return TraceValueTraits(tracer, v) == TrBuiltin(TrVM(tracer), 0x220);
}
// @0x1425150c0
bool Sfr27TracerIsUIntType(UPInt tracer, const Value* v)
{
    return TraceValueTraits(tracer, v) == TrBuiltin(TrVM(tracer), 0x228);
}
// @0x142514e10
bool Sfr27TracerIsStringType(UPInt tracer, const Value* v)
{
    return TraceValueTraits(tracer, v) == TrBuiltin(TrVM(tracer), 0x230);
}

// int, uint or Number
// @0x142514510
bool Sfr27TracerIsNumericType(UPInt tracer, UPInt traits)
{
    const UPInt vm = TrVM(tracer);
    return traits == TrBuiltin(vm, 0x220) || traits == TrBuiltin(vm, 0x228) || traits == TrBuiltin(vm, 0x218);
}

// Boolean, void, null or numeric: no reference counting needed
// @0x142514420
bool Sfr27TracerIsNotRefCountedType(UPInt tracer, UPInt traits)
{
    const UPInt vm = TrVM(tracer);
    if (traits != TrBuiltin(vm, 0x210) && traits != TrRd(vm, 0x278) && traits != TrRd(vm, 0x270))
        return Sfr27TracerIsNumericType(tracer, traits);
    return true;
}

// Boolean, void, null, numeric or String
// @0x142514a80
bool Sfr27TracerIsPrimitiveType(UPInt tracer, UPInt traits)
{
    const UPInt vm = TrVM(tracer);
    if (traits != TrBuiltin(vm, 0x210) && traits != TrRd(vm, 0x278) && traits != TrRd(vm, 0x270))
    {
        if (!Sfr27TracerIsNumericType(tracer, traits) && traits != TrBuiltin(vm, 0x230))
            return false;
    }
    return true;
}

// @0x14250fe80
UPInt Sfr27StateGetValueTraits(void* state, const Value* v)
{
    return TraceValueTraits(*reinterpret_cast<const UPInt*>(state), v);
}

// With classes resolved to their instance traits (asInstance), the traits' parent.
// @0x14250ff00
UPInt Sfr27TracerGetValueTraits(UPInt tracer, const Value* v, bool asInstance)
{
    UPInt t;
    if (!asInstance || (t = TrRd(TrRd(tracer, 0x20), 0x40)) == 0)
        t = TraceValueTraits(tracer, v);
    if (asInstance && t != 0)
        return TrRd(t, 0x88);
    return t;
}

// The unsigned 30-bit operand following the opcode of the n-th last instruction.
// @0x14250c1f0
int Sfr27TracerGetNextU30(UPInt tracer, UPInt n)
{
    UPInt pos = *reinterpret_cast<const UPInt*>(TrRd(tracer, 0x70) - 8 + (TrRd(tracer, 0x78) - n) * 8) + 1;
    return Abc::ReadU30<UInt8>(reinterpret_cast<const UInt8*>(TrRd(tracer, 0x50)), pos);
}

}}}} // namespace Scaleform::GFx::AS3::TR

// ---- TR::State operand stack pops (the State's layout lives in as3_readargs.h; its methods are not declared yet) ----
namespace Scaleform { namespace GFx { namespace AS3 { namespace TR {

// @0x14251ccc0
void Sfr27StatePopOp(void* state, UPInt n)
{
    ArrayDH<Value>& ops = *reinterpret_cast<ArrayDH<Value>*>(reinterpret_cast<UPInt>(state) + 0x38);
    ops.PopBack(n);
}

// The top operand returned (by value: hidden result pointer after this), then popped.
// @0x14251cd30
Value* Sfr27StatePopOpValue(void* state, Value* result)
{
    ArrayDH<Value>& ops = *reinterpret_cast<ArrayDH<Value>*>(reinterpret_cast<UPInt>(state) + 0x38);
    new (result) Value(ops[ops.GetSize() - 1]);
    ops.PopBack(1);
    return result;
}

}}}} // namespace Scaleform::GFx::AS3::TR

// ---- PropRef value reads ----
namespace Scaleform { namespace GFx { namespace AS3 {

// The found property's value, getters not run for valGet. The three tags of the reference: a slot, a dynamic value
// (tagged pointer) or a closure object.
// MS2-FUNCTIONAL 0x14250e200: exe inlines the value assign and refcount bumps with a different frame (AssignUnsafe is out-of-line here).
// @0x14250e200
CheckResult PropRef::GetSlotValueUnsafe(VM& vm, Value& value, SlotInfo::ValTarget vt) const
{
    bool ok = true;
    const UPInt w = reinterpret_cast<UPInt>(pValue);
    switch (w & 3)
    {
    case 0:
    {
        CheckResult r(false);
        ok = *FUN_14250e2d0(pSI, &r, &vm, &value, &This, NULL, vt);
        break;
    }
    case 1:
        value.AssignUnsafe(*reinterpret_cast<const Value*>(w & ~static_cast<UPInt>(1)));
        return CheckResult(true);
    case 2:
        value.AssignUnsafe(reinterpret_cast<Object*>(w & ~static_cast<UPInt>(2)));
        return CheckResult(true);
    }
    return CheckResult(ok);
}

// The same with the vtable to read methods from.
// @0x14250e130
char* Sfr27PropRefGetSlotValueVT(const PropRef* self, char* ret, VM* vm, Value* value, VTable* vtable)
{
    bool ok = true;
    const UPInt w = reinterpret_cast<UPInt>(self->pValue);
    switch (w & 3)
    {
    case 0:
    {
        CheckResult r(false);
        ok = *FUN_14250e2d0(self->pSI, &r, vm, value, &self->This, vtable, 0);
        break;
    }
    case 1:
        value->AssignUnsafe(*reinterpret_cast<const Value*>(w & ~static_cast<UPInt>(1)));
        *ret = 1;
        return ret;
    case 2:
        value->AssignUnsafe(reinterpret_cast<Object*>(w & ~static_cast<UPInt>(2)));
        *ret = 1;
        return ret;
    }
    *ret = ok;
    return ret;
}

}}} // namespace Scaleform::GFx::AS3

// ---- Small accessors (leaf functions of the display and VM glue; their classes are not named yet) ----
namespace Scaleform { namespace GFx { namespace AS3 {

namespace {
inline UPInt AccRd(UPInt base, UPInt off) { return *reinterpret_cast<const UPInt*>(base + off); }
}

// @0x14250a5c0
UPInt Sfr27Acc14250a5c0(UPInt self) { return AccRd(AccRd(AccRd(AccRd(self, 0x18), 0x20), 0x10), 0x40); }

// The first entry of the array a display object keeps (data +0x148, count +0x150), or 0.
// @0x14250a600
UPInt Sfr27AccFirst148(UPInt self)
{
    const UPInt o = AccRd(self, 0x18);
    return AccRd(o, 0x150) > 0 ? AccRd(AccRd(o, 0x148), 0) : 0;
}
// @0x14250cbe0
UPInt Sfr27AccFirst108(UPInt self)
{
    const UPInt o = AccRd(self, 0x18);
    return AccRd(o, 0x110) > 0 ? AccRd(AccRd(o, 0x108), 0) : 0;
}
// @0x14250f960
UPInt Sfr27AccFirstE8(UPInt self)
{
    const UPInt o = AccRd(self, 0x18);
    return AccRd(o, 0xf0) > 0 ? AccRd(AccRd(o, 0xe8), 0) : 0;
}

// The instance traits of the VM's Vector.<String> class.
// @0x14250a6c0
UPInt Sfr27AccVectorStringITraits(UPInt vm) { return AccRd(AccRd(vm, 0x268), 0xc0); }

// @0x14250bce0
UPInt Sfr27AccField8(UPInt self) { return AccRd(self, 8); }

// @0x14250edf0
UPInt Sfr27Acc14250edf0(UPInt self) { return AccRd(AccRd(AccRd(self, 0x18), 0x20), 0x158); }

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {

// The bounds of the display list of the object (returned in the result passed after this).
// @0x14250d6d0
char* Sfr27DisplayListBounds(UPInt self, char* ret)
{
    FUN_1425f9ba0(self + 0xd8, ret);
    return ret;
}

// A virtual that returns its value through the hidden result pointer, passed straight on.
// @0x14250d6b0
char* Sfr27ForwardVirtual1b8(void* self, char* ret)
{
    reinterpret_cast<void (*)(void*, char*)>(AccRd(AccRd(reinterpret_cast<UPInt>(self), 0), 0x1b8))(self, ret);
    return ret;
}

// The traits of the interned namespace instance made for the arguments, or 0.
// @0x14250cc00
UPInt Sfr27NamespaceInstanceTraits(UPInt a, UPInt b)
{
    const UPInt ns = FUN_142525ca0(a, b);
    return ns != 0 ? AccRd(ns, 0xc0) : 0;
}

// A text field that is read only cannot be tabbed to in mode 2.
// @0x1425142e0
bool Sfr27TextFieldTabCheck(UPInt self, UInt32 mode)
{
    if (mode != 2)
        return true;
    return !FUN_1425b9b10(AccRd(self - 0x18, 0));
}

// Whether the text field's style sheet resource is set.
// @0x1425113d0
bool Sfr27TextFieldHasStyleSheet(UPInt self)
{
    const UPInt sheet = FUN_1425b7e60(AccRd(self - 0x28, 0));
    return sheet != 0 && AccRd(sheet, 0x40) != 0;
}

}}} // namespace Scaleform::GFx::AS3

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {


}}} // namespace Scaleform::GFx::AS3
// THUNKS-END
