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
#include "ms2/scaleform/include/gfx/gfx_button.h"
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


// ==== VMAbcFile: interned strings and namespaces ====
namespace Scaleform { namespace GFx { namespace AS3 {

// MS2-FUNCTIONAL: the exe grows IntStrings through an out-of-line resize and interns the node by hand
// @0x14250b240
ASString VMAbcFile::GetInternedString(UPInt ind)
{
    if (IntStrings.GetSize() <= ind)
        IntStrings.Resize(ind + 1);
    if (!IntStrings[ind])
    {
        const StringDataPtr s = pFile->Const_Pool.GetString(ind);
        ASString str = GetVM().GetStringManager().CreateString(s.ToCStr(), s.GetSize());
        IntStrings[ind] = str.GetNode();
    }
    return ASString(IntStrings[ind]);
}

// MS2-FUNCTIONAL: the hash lookup/add are not the exe's template copies
// @0x14250ae60
Instances::Namespace& VMAbcFile::GetInternedNamespace(UPInt ind)
{
    typedef AbcMultinameHash<SPtr<Instances::Namespace> >::Key NsKey;
    SPtr<Instances::Namespace>* found = IntNamespaces.Entries.Get(NsKey(ind));
    if (!found)
    {
        const Abc::ConstPool& cp = pFile->Const_Pool;
        const Abc::NamespaceInfo& info = ind == 0 ? cp.any_namespace : cp.ConstNamespace[ind];
        ASString uri = GetVM().GetStringManager().CreateString(info.NameURI.ToCStr(), info.NameURI.GetSize());
        Pickable<Instances::Namespace> ns = GetVM().MakeInternedNamespace(info.Kind, uri);
        IntNamespaces.Entries.Add(NsKey(ind), SPtr<Instances::Namespace>(ns));
        found = IntNamespaces.Entries.Get(NsKey(ind));
    }
    return **found;
}

} } }


namespace Scaleform { namespace GFx { namespace AS3 {

// The namespace a multiname is qualified with; one with a type argument gets that argument's namespace uri appended
// after a '$', so each (namespace, type) pair interns separately.
// MS2-FUNCTIONAL: the hash lookup/add are not the exe's template copies
// @0x14250abf0
Instances::Namespace& VMAbcFile::GetInternedNamespace(const Abc::Multiname& mn)
{
    typedef AbcMultinameHash<SPtr<Instances::Namespace> >::Key NsKey;
    const bool keyed = (static_cast<UInt32>(mn.Kind) & 3) < 2;
    const NsKey key(mn.Ind, mn.NextIndex);
    if (keyed)
    {
        SPtr<Instances::Namespace>* found = IntNamespaces.Entries.Get(key);
        if (found)
            return **found;
    }
    const Abc::ConstPool& cp = pFile->Const_Pool;
    const Abc::NamespaceInfo& info = mn.Ind == 0 ? cp.any_namespace : cp.ConstNamespace[mn.Ind];
    ASString uri = GetVM().GetStringManager().CreateString(info.NameURI.ToCStr(), info.NameURI.GetSize());
    if (mn.NextIndex >= 0)
    {
        const Abc::Multiname& next = cp.GetMultiname(mn.NextIndex);
        const Abc::NamespaceInfo& ninfo = next.Ind == 0 ? cp.any_namespace : cp.ConstNamespace[next.Ind];
        uri.Append("$", 1);
        uri.Append(GetVM().GetStringManager().CreateString(ninfo.NameURI.ToCStr(), ninfo.NameURI.GetSize()));
    }
    Pickable<Instances::Namespace> ns = GetVM().MakeInternedNamespace(info.Kind, uri);
    IntNamespaces.Entries.Add(key, SPtr<Instances::Namespace>(ns));
    return **IntNamespaces.Entries.Get(key);
}


// ==== AVM display objects: events, unloading, tabbing (sfr34) ====

}}} // namespace Scaleform::GFx::AS3

bool FUN_142467ec0(void* dispatcher, const Scaleform::GFx::EventId* id, void* dispObj);   // EventDispatcher::Dispatch(const EventId&, DisplayObject*)
bool FUN_14246a160(const void* dispatcher, const void* type, bool useCapture);           // EventDispatcher::HasEventHandler
void FUN_142526340(void* avm, void* as3obj);                                             // AvmDisplayObj::SetAS3ObjCollectible
bool FUN_1425db970(void* sprite, const char* label, int offset);                         // Sprite::GotoLabeledFrame
void FUN_1425f7e30(void* intObj);                                                        // InteractiveObject::AddToOptimizedPlayList

namespace Scaleform { namespace GFx { namespace AS3 {

static MovieRoot* AS3RootOf(const DisplayObject* d) { return static_cast<MovieRoot*>(d->GetASMovieRoot()); }

// Event ids the AS3 player adds after Event_SockXML.
enum
{
    AS3Event_Click          = 0x100000c,    // fired on a press of a button (mode) object
    AS3Event_Removed        = 0x1000010,
    AS3Event_Render         = 0x1000013,
    AS3Event_Controller     = 0x1000014,
    AS3Event_FrameFirst     = 0x1000015,    // the two frame-script events
    AS3Event_FrameLast      = 0x1000016
};

// Queues the event for the object at level lvl.
static void QueueEvent(DisplayObject* d, MovieRoot::ActionLevel lvl, const EventId& id)
{
    AS3RootOf(d)->InsertEmptyAction(lvl)->SetAction(d, id);
}

// Enter frame queues once the object is loaded; render and frame events queue for objects with an AS3 side.
// MS2-FUNCTIONAL queueing goes through a shared helper and the inline SetAction; exe code is split into chained fragments
// @0x142518a30
bool AvmDisplayObj::OnEvent(const EventId& id)
{
    MovieRoot::ActionLevel lvl;
    if (id.Id == EventId::Event_EnterFrame)
    {
        if (GetAS3Obj() && (Flags & Flag_Loaded))
            QueueEvent(pDispObj, MovieRoot::AL_EnterFrame, id);
        Flags |= Flag_Loaded;
        return true;
    }
    if (id.Id == AS3Event_Render)
    {
        if (!GetAS3Obj())
            return true;
        lvl = MovieRoot::AL_Render;
    }
    else
    {
        if (id.Id - AS3Event_FrameFirst > AS3Event_FrameLast - AS3Event_FrameFirst)
            return false;
        if (!GetAS3Obj())
            return true;
        lvl = MovieRoot::AL_Frame;
    }
    QueueEvent(pDispObj, lvl, id);
    return true;
}

// An object with removed listeners gets its removed event queued and leaves the depth order.
// MS2-FUNCTIONAL queueing goes through a shared helper and the inline SetAction; exe code is split into chained fragments
// @0x14251af40
bool AvmDisplayObj::OnUnloading(bool mayRemove)
{
    Instances::fl_display::DisplayObject* obj = GetAS3Obj();
    if (obj)
    {
        MovieRoot* root = AS3RootOf(pDispObj);
        if (FUN_14246a160(obj, &root->BuiltinsMgr.GetBuiltin(AS3Builtin_removed), false) ||
            FUN_14246a160(obj, &AS3RootOf(pDispObj)->BuiltinsMgr.GetBuiltin(AS3Builtin_removedFromStage), false))
        {
            QueueEvent(pDispObj, MovieRoot::AL_EnterFrame, EventId(AS3Event_Removed));
            pDispObj->Depth = -2;
            if (IsStageAccessible())
                Flags |= Flag_Unloaded;
        }
    }
    return mayRemove;
}

// Mouse events go straight to the AS3 object, controller events are queued.
// MS2-FUNCTIONAL queueing goes through a shared helper and the inline SetAction; exe code is split into chained fragments
// @0x142518c70
bool AvmInteractiveObj::OnEvent(const EventId& id)
{
    switch (id.Id)
    {
    case EventId::Event_MouseMove:
    case EventId::Event_MouseDown:
    case EventId::Event_MouseUp:
    case EventId::Event_RollOver:
    case EventId::Event_RollOut:
    case 0x100000a: case 0x100000b: case AS3Event_Click: case 0x100000d: case 0x100000e:
        if (Instances::fl_display::DisplayObject* obj = GetAS3Obj())
            FUN_142467ec0(obj, &id, pDispObj);
        return true;
    case AS3Event_Controller:
        QueueEvent(pDispObj, MovieRoot::AL_ControllerEvents, id);
        return true;
    }
    return AvmDisplayObj::OnEvent(id);
}

// A sprite in button mode shows its _up/_over/_down frames; a press becomes a click.
// MS2-FUNCTIONAL label choice written as a switch; block order and string reloc order differ
// @0x142518df0
bool AvmSprite::OnEvent(const EventId& id)
{
    if (SprFlags & Flag_ButtonMode)
    {
        Sprite* spr = static_cast<Sprite*>(pDispObj);
        const UPInt def = (spr->Flags & Sprite::Flags_SpriteDef) ? reinterpret_cast<const UPInt&>(spr->pDef) : 0;
        const UByte frames = def ? *reinterpret_cast<const UByte*>(def + 0x60) : 0;   // SpriteDef: 1 _up, 2 _down, 4 _over
        if (frames & 7)
        {
            const bool trackAsMenu = (*reinterpret_cast<const UInt32*>(reinterpret_cast<UPInt>(spr) + 0xb8) & 0x4000) != 0;
            const char* label = NULL;
            switch (id.Id)
            {
            case EventId::Event_RollOver:
                if (frames & 4)
                {
                    // MovieImpl::mMouseState[i] (0x50 bytes at +0x1260): +0x30 and +0x34 button states
                    const unsigned mi = (unsigned)(int)id.MouseIndex;
                    const UPInt ms = mi < 4 ? reinterpret_cast<UPInt>(spr->GetMovieImpl()) + 0x1260 + mi * 0x50 : 0;
                    if (trackAsMenu && (*reinterpret_cast<const UByte*>(ms + 0x34) & 1))
                        label = "_down";
                    else if (!(*reinterpret_cast<const UByte*>(ms + 0x30) & 1))
                        label = "_over";
                }
                break;
            case EventId::Event_MouseDown:
            case EventId::Event_DragOver:
                if (frames & 2)
                    label = "_down";
                break;
            case EventId::Event_DragOut:
                if (!trackAsMenu)
                {
                    if (frames & 4)
                        label = "_over";
                    break;
                }
                // fall through
            case EventId::Event_ReleaseOutside:
            case EventId::Event_RollOut:
                if (frames & 1)
                    label = "_up";
                break;
            case EventId::Event_MouseUp:
            case EventId::Event_Release:
                if (frames & 4)
                    label = "_over";
                break;
            }
            if (label)
                FUN_1425db970(spr, label, 0);
        }
        if (id.Id == EventId::Event_Press)
        {
            if (Instances::fl_display::DisplayObject* obj = GetAS3Obj())
            {
                EventId click(id);
                click.Id = AS3Event_Click;
                FUN_142467ec0(obj, &click, pDispObj);
            }
            return true;
        }
    }
    return AvmInteractiveObj::OnEvent(id);
}

// The object is the stage, or its topmost AS3 ancestor is.
// MS2-FUNCTIONAL parent walk via ToAvmInteractiveObj; the exe re-reads the parent each step
// @0x142514d20
bool AvmDisplayObj::IsStageAccessible() const
{
    if (pDispObj->IsInteractiveObject() && ToAvmInteractiveObj(static_cast<InteractiveObject*>(pDispObj))->IsStage())
        return true;
    AvmInteractiveObj* p = ToAvmInteractiveObj(pDispObj->GetParent());
    while (p)
    {
        AvmInteractiveObj* pp = ToAvmInteractiveObj(p->pDispObj->GetParent());
        if (!pp)
            return p->IsStage();
        p = pp;
    }
    return false;
}

// MS2-FUNCTIONAL register allocation of the inlined GetAS3Obj differs
// @0x142519080
void AvmInteractiveObj::OnEventLoad()
{
    FUN_142526340(this, GetAS3Obj());
}

// AvmButton::IsTabable; self is the AvmInteractiveObjBase part (+0x30) of the button.
// MS2-FUNCTIONAL free function on the subobject this; register allocation and branch layout differ
// @0x142514eb0
bool AvmButton_IsTabable(UPInt self)
{
    InteractiveObject* b = reinterpret_cast<InteractiveObject*>(AccRd(self - 0x18, 0));
    if (!b->GetVisible())
        return false;
    const UInt32 tab = *reinterpret_cast<const UInt32*>(reinterpret_cast<UPInt>(b) + 0xb8) & 0x60;   // TabEnabled
    if (tab)
        return tab == 0x60;
    return *reinterpret_cast<const SInt16*>(reinterpret_cast<UPInt>(b) + 0xbc) > 0;          // TabIndex
}

// AvmTextField::IsTabable; as the button, and an editable field is tabable by default.
// MS2-FUNCTIONAL free function on the subobject this; register allocation and branch layout differ
// @0x142515050
bool AvmTextField_IsTabable(UPInt self)
{
    InteractiveObject* t = reinterpret_cast<InteractiveObject*>(AccRd(self - 0x18, 0));
    if (!t->GetVisible())
        return false;
    const UInt32 tab = *reinterpret_cast<const UInt32*>(reinterpret_cast<UPInt>(t) + 0xb8) & 0x60;
    if (tab)
        return tab == 0x60;
    if (*reinterpret_cast<const SInt16*>(reinterpret_cast<UPInt>(t) + 0xbc) > 0)
        return true;
    return !FUN_1425b9b10(reinterpret_cast<UPInt>(t));
}

// AvmTextField::OnKeyEvent; self is the AvmInteractiveObjBase part (+0x30).
// MS2-FUNCTIONAL free function on the subobject this; register allocation and branch layout differ
// @0x14251a350
bool AvmTextField_OnKeyEvent(UPInt self, const EventId& id, int*)
{
    UPInt obj = AccRd(self - 0x20, 0);
    if (!obj)
        obj = AccRd(self - 0x28, 0);
    if (obj)
        FUN_142467ec0(reinterpret_cast<void*>(obj & ~UPInt(1)), &id, reinterpret_cast<void*>(AccRd(self - 0x18, 0)));
    return false;
}

// AvmButton::OnMouseEvent; self is the AvmButtonBase part (+0x40). A press becomes a click, the rest goes to
// OnEvent.
// MS2-FUNCTIONAL free function on the subobject this; register allocation and branch layout differ
// @0x14251a830
bool AvmButton_OnMouseEvent(UPInt self, const EventId& id)
{
    if (id.Id == EventId::Event_Press)
    {
        UPInt obj = AccRd(self - 0x30, 0);
        if (!obj)
            obj = AccRd(self - 0x38, 0);
        if (obj)
        {
            EventId click(id);
            click.Id = AS3Event_Click;
            FUN_142467ec0(reinterpret_cast<void*>(obj & ~UPInt(1)), &click, reinterpret_cast<void*>(AccRd(self - 0x28, 0)));
        }
        return true;
    }
    return reinterpret_cast<AvmDisplayObj*>(self - 0x40)->OnEvent(id);
}

// AvmTextField::OnEventLoad: the field joins the play list after its place in the parent, and the optimized
// advance list when it asks to.
// MS2-FUNCTIONAL free function on the subobject this; register allocation and branch layout differ
// @0x1425190f0
void AvmTextField_OnEventLoad(UPInt self)
{
    InteractiveObject* t = reinterpret_cast<InteractiveObject*>(AccRd(self, 0x18));
    if (InteractiveObject* pafter = ToAvmInteractiveObj(t->GetParent())->FindInsertToPlayList(t))
        t->InsertToPlayListAfter(pafter);
    else
        t->AddToPlayList();
    UInt32& f = *reinterpret_cast<UInt32*>(reinterpret_cast<UPInt>(t) + 0xb8);
    const bool inOptList = (f & 0x200000) && !(f & 0x400000);   // OptAdvList, not MarkedToRemoveFromOptAdvList
    // TextField slot 97: whether the field needs advancing (-1 none, 1 yes)
    const int st = reinterpret_cast<int (*)(void*, bool)>(AccRd(AccRd(reinterpret_cast<UPInt>(t), 0), 0x308))(t, inOptList);
    if (st == -1)
        f |= 0x400000;
    else if (st == 1)
        FUN_1425f7e30(t);
    UPInt obj = AccRd(self, 0x10);
    if (!obj)
        obj = AccRd(self, 8);
    FUN_142526340(reinterpret_cast<void*>(self), reinterpret_cast<void*>(obj & ~UPInt(1)));
}

// AvmTextField::GetStyleSheet; self is the AvmTextFieldBase part (+0x40). The style manager of the field's
// style sheet when the field uses one.
// MS2-FUNCTIONAL free function on the subobject this; register allocation and branch layout differ
// @0x14250ef30
UPInt AvmTextField_GetStyleSheet(UPInt self)
{
    const UPInt sheet = FUN_1425b7e60(AccRd(self - 0x28, 0));
    if (reinterpret_cast<bool (*)(UPInt)>(AccRd(AccRd(self, 0), 0xc0))(self))   // AvmTextFieldBase slot 24: HasStyleSheet
        return AccRd(sheet, 0x40) + 0x50;
    return 0;
}


// ==== Values and container instantiations of the unit (sfr34) ====

// @0x14251c9b0
void Value::PickUnsafe(Class* v)
{
    SetKind(kClass);
    value = v;
}

// @0x14251c9d0
void Value::PickUnsafe(Object* v)
{
    SetKind(kObject);
    value = v;
}

}}} // namespace Scaleform::GFx::AS3

void FUN_1424dde10(void* frame);                                                       // CallFrame::~CallFrame

namespace Scaleform {
template void ArrayDataBase<UByte, AllocatorGH<UByte, 2>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void ArrayDataBase<UByte, AllocatorGH_POD<UByte, 2>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void ArrayDataBase<GFx::AS3::TR::State*, AllocatorDH<GFx::AS3::TR::State*, 328>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void ArrayDataBase<Render::FillStyleType, AllocatorLH<Render::FillStyleType, 2>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void ArrayDataBase<GFx::Button::CharToRec, AllocatorLH<GFx::Button::CharToRec, 2>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void ArrayDataBase<GFx::MovieImpl::LevelInfo, AllocatorLH<GFx::MovieImpl::LevelInfo, 327>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Hash<GFx::AS3::GASRefCountBase*, GFx::AS3::WeakProxy*>::Remove(GFx::AS3::GASRefCountBase* const&);
// MS2-FUNCTIONAL 0x142522350: exe folds Remove into the inlined RemoveAlt<Key> body; ours tail-calls RemoveAlt
template void HashDH<GFx::AS3::MultinameHash<GFx::AS3::ClassTraits::Traits*, 329>::Key, GFx::AS3::ClassTraits::Traits*,
    GFx::AS3::MultinameHash<GFx::AS3::ClassTraits::Traits*, 329>::Key::HashFunctor, 329>::BaseType::Remove(
    const GFx::AS3::MultinameHash<GFx::AS3::ClassTraits::Traits*, 329>::Key&);
// MS2-FUNCTIONAL 0x1425224f0: codegen, the exe resizes to 0 through Resize when the last element goes
template void ArrayBase<ArrayData<WeakPtr<GFx::DisplayObject>, AllocatorLH<WeakPtr<GFx::DisplayObject>, 2>, ArrayDefaultPolicy> >::RemoveAt(UPInt);
// MS2-FUNCTIONAL 0x14251cb40: codegen, the exe calls the out-of-line ResizeNoConstruct
template void ArrayBase<ArrayDataDH<GFx::AS3::Value, AllocatorDH<GFx::AS3::Value, 2>, ArrayDefaultPolicy> >::PopBack(UPInt);
// MS2-FUNCTIONAL 0x14251f800: the Value default/copy ctor and dtor stay out of line in our Value model; the exe inlines
// the undefined-Value copy into the grown slot
template GFx::AS3::Value& ArrayBase<ArrayData<GFx::AS3::Value, AllocatorLH<GFx::AS3::Value, 331>, ArrayDefaultPolicy> >::PushDefault();
template void ArrayData<char, AllocatorGH<char, 2>, ArrayDefaultPolicy>::PushBack(const char&);
template void ArrayBase<ArrayDataDH<Ptr<GFx::DisplayObjectBase>, AllocatorDH<Ptr<GFx::DisplayObjectBase>, 2>, ArrayDefaultPolicy> >::InsertAt(
    UPInt, const Ptr<GFx::DisplayObjectBase>&);
// VMAppDomain is not modeled; the array only stores the SPtr word, so a
// GASRefCountBase element array produces the same Reserve body.
// MS2-FUNCTIONAL wrapper over the SPtr<GASRefCountBase> instantiation (VMAppDomain not modeled)
// @0x142522ef0
void Sfr34_VMAppDomainArray_Reserve(void* self, const void* pheapAddr, UPInt newCapacity)
{
    ((ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::GASRefCountBase>,
        AllocatorLH<GFx::AS3::SPtr<GFx::AS3::GASRefCountBase>, 329>, ArrayDefaultPolicy>*)self)->Reserve(pheapAddr, newCapacity);
}
// The exe element type is Instances::fl::Namespace, which this model keeps as
// Instances::Namespace; only the SPtr word is stored, so the body is the same.
// MS2-FUNCTIONAL wrapper over the SPtr<Instances::Namespace> instantiation (fl::Namespace not modeled)
// @0x142522db0
void Sfr34_FlNamespaceArray_Reserve(void* self, const void* pheapAddr, UPInt newCapacity)
{
    ((ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::Instances::Namespace>,
        AllocatorLH<GFx::AS3::SPtr<GFx::AS3::Instances::Namespace>, 2>, ArrayDefaultPolicy>*)self)->Reserve(pheapAddr, newCapacity);
}

// ArrayPagedBase<CallFrame, 6, 64, AllocatorPagedCC<CallFrame, 329>>::PopBack;
// the paged CC allocator is not modeled. Pages hold 64 frames of 0xa8 bytes.
struct Sfr34_CallFramePagedArray
{
    void*   pHeap;      // +0x00
    UPInt   Size;       // +0x08
    UPInt   NumPages;   // +0x10
    UPInt   MaxPages;   // +0x18
    UByte** Pages;      // +0x20  64 CallFrames of 0xa8 bytes per page
};

// MS2-FUNCTIONAL paged array modeled locally (AllocatorPagedCC not modeled)
// @0x14251cba0
void Sfr34_CallFramePagedArray_PopBack(Sfr34_CallFramePagedArray* self)
{
    if (self->Size)
    {
        UPInt i = self->Size - 1;
        FUN_1424dde10(self->Pages[i >> 6] + (i & 0x3f) * 0xa8);
        self->Size--;
    }
}
} // namespace Scaleform

namespace Scaleform { namespace GFx { namespace AS3 {

} } }

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {


}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?PushBack@?$ArrayData@DU?$AllocatorGH@D$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAXAEBD@Z 0x14251f5f0 ; unique
// MS2-PIN: ?Reserve@?$ArrayDataBase@EU?$AllocatorGH@E$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x142522c70 ; prop
// MS2-PINS-END tplpin
// sfr34: template copies of the unit (coverage names)
// MS2-PIN: ?Reserve@?$ArrayDataBase@EU?$AllocatorGH_POD@E$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x142522d10
// MS2-PIN: ?Reserve@?$ArrayDataBase@PEAVState@TR@AS3@GFx@Scaleform@@U?$AllocatorDH@PEAVState@TR@AS3@GFx@Scaleform@@$0BEI@@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAXPEBX_K@Z 0x142522e50
// MS2-PIN: ?Reserve@?$ArrayDataBase@UFillStyleType@Render@Scaleform@@U?$AllocatorLH@UFillStyleType@Render@Scaleform@@$01@3@UArrayDefaultPolicy@3@@Scaleform@@QEAAXPEBX_K@Z 0x142522f90
// MS2-PIN: ?Reserve@?$ArrayDataBase@UCharToRec@Button@GFx@Scaleform@@U?$AllocatorLH@UCharToRec@Button@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142523030
// MS2-PIN: ?Reserve@?$ArrayDataBase@ULevelInfo@MovieImpl@GFx@Scaleform@@U?$AllocatorLH@ULevelInfo@MovieImpl@GFx@Scaleform@@$0BEH@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x1425230d0
// MS2-PIN: ?Remove@?$Hash@PEAVGASRefCountBase@AS3@GFx@Scaleform@@PEAVWeakProxy@234@V?$FixedSizeHash@PEAVGASRefCountBase@AS3@GFx@Scaleform@@@4@U?$AllocatorGH@PEAVGASRefCountBase@AS3@GFx@Scaleform@@$01@4@U?$HashNode@PEAVGASRefCountBase@AS3@GFx@Scaleform@@PEAVWeakProxy@234@V?$FixedSizeHash@PEAVGASRefCountBase@AS3@GFx@Scaleform@@@4@@4@V?$HashsetCachedNodeEntry@U?$HashNode@PEAVGASRefCountBase@AS3@GFx@Scaleform@@PEAVWeakProxy@234@V?$FixedSizeHash@PEAVGASRefCountBase@AS3@GFx@Scaleform@@@4@@Scaleform@@UNodeHashF@12@@4@V?$HashSet@U?$HashNode@PEAVGASRefCountBase@AS3@GFx@Scaleform@@PEAVWeakProxy@234@V?$FixedSizeHash@PEAVGASRefCountBase@AS3@GFx@Scaleform@@@4@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorGH@PEAVGASRefCountBase@AS3@GFx@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@PEAVGASRefCountBase@AS3@GFx@Scaleform@@PEAVWeakProxy@234@V?$FixedSizeHash@PEAVGASRefCountBase@AS3@GFx@Scaleform@@@4@@Scaleform@@UNodeHashF@12@@2@@4@@Scaleform@@QEAAXAEBQEAVGASRefCountBase@AS3@GFx@2@@Z 0x1425221d0
// MS2-PIN: ?Remove@?$Hash@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@U?$AllocatorDH@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@$0BEJ@@5@U?$HashNode@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@@5@V?$HashsetCachedNodeEntry@U?$HashNode@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@@Scaleform@@UNodeHashF@12@@5@V?$HashSetDH@U?$HashNode@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@$0BEJ@V?$HashsetCachedNodeEntry@U?$HashNode@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@@Scaleform@@UNodeHashF@12@@2@@5@@Scaleform@@QEAAXAEBUKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@2@@Z 0x142522350
// MS2-PIN: ?RemoveAt@?$ArrayBase@U?$ArrayData@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@QEAAX_K@Z 0x1425224f0
// MS2-PIN: ?PopBack@?$ArrayBase@U?$ArrayDataDH@VValue@AS3@GFx@Scaleform@@U?$AllocatorDH@VValue@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_K@Z 0x14251cb40
// MS2-PIN: ?PushDefault@?$ArrayBase@U?$ArrayData@VValue@AS3@GFx@Scaleform@@U?$AllocatorLH@VValue@AS3@GFx@Scaleform@@$0BEL@@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAAEAVValue@AS3@GFx@2@XZ 0x14251f800
// MS2-PIN: ?InsertAt@?$ArrayBase@U?$ArrayDataDH@V?$Ptr@VDisplayObjectBase@GFx@Scaleform@@@Scaleform@@U?$AllocatorDH@V?$Ptr@VDisplayObjectBase@GFx@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@QEAAX_KAEBV?$Ptr@VDisplayObjectBase@GFx@Scaleform@@@2@@Z 0x142512630
