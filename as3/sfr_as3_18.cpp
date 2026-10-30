// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_18
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142509d40-0x142523170 .text$mn
#include <math.h>
#include <stdlib.h>
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/kernel/sf_simd.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/as3_vec_base.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fntraits.h"
#include "ms2/scaleform/include/gfx/gfx_loaderimpl.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"
#include "ms2/scaleform/include/gfx/gfx_button.h"
#include "ms2/scaleform/include/gfx/gfx_shapedef.h"
#include "ms2/scaleform/include/gfx/gfx_drawingcontext.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_display.h"
#include "ms2/scaleform/include/gfx/as3/as3_callframe.h"
#include "ms2/scaleform/include/gfx/as3/as3_tracer.h"
#include "ms2/scaleform/include/gfx/as3/as3_udbase.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_userdefined.h"
#include "ms2/scaleform/include/gfx/as2/as2_object.h"   // ASUserData
#include "ms2/scaleform/include/kernel/sf_msgformat.h"
#include "ms2/scaleform/include/gfx/gfx_textfield.h"
#include "ms2/scaleform/include/video/video_statebag.h"
#include "ms2/scaleform/include/gfx/as3/as3_loadqueue.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_net.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_utils.h"
#include "ms2/scaleform/include/gfx/as3/as3_intervaltimer.h"
#include "ms2/scaleform/include/gfx/gfx_imageresource.h"
#include "ms2/scaleform/include/gfx/gfx_imagecreator.h"
#undef GetObject   // windows.h

char* FUN_14250e2d0(const void* si, void* ret, Scaleform::GFx::AS3::VM* vm, Scaleform::GFx::AS3::Value* value, const Scaleform::GFx::AS3::Value* thisValue, void* vtable, int valTarget);   // SlotInfo: read the slot into value
void FUN_1425f9ba0(Scaleform::UPInt self, char* ret, const void* matrix);
Scaleform::UPInt FUN_142525ca0(Scaleform::UPInt a, Scaleform::UPInt b);
bool FUN_1425b9b10(Scaleform::UPInt textField);
Scaleform::UPInt FUN_1425b7e60(Scaleform::UPInt textField);
const Scaleform::GFx::AS3::Traits& FUN_14250ffc0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v);   // the traits of a value
void* FUN_14243d870(void* self, void* p);   // SPtr<Instances::fl::Object>::operator=, out of line
void FUN_1424fa320(Scaleform::GFx::AS3::MovieRoot* proot, unsigned level);   // MovieRoot::ExecuteActionQueue(ActionLevel)
bool FUN_142506000(const Scaleform::GFx::AS3::MovieRoot* proot, Scaleform::GFx::AS3::Value* pval, const char* ppathToVar);   // MovieRoot::GetASVariableAtPath
void FUN_1424f4000(Scaleform::GFx::AS3::MovieRoot* proot, Scaleform::GFx::MovieDefImpl* pmovieDef);   // MovieRoot::CreateStage
void FUN_142524870(void* arr, Scaleform::UPInt n);   // ArrayDH_POD<UPInt>::Resize, out of line
void FUN_1425247f0(void* arr, Scaleform::UPInt n);   // ArrayLH_POD<UPInt>::Resize (the word code), out of line
// Value::operator=(const ASString&), out of line in the exe
Scaleform::GFx::AS3::Value& FUN_1424e0d40(Scaleform::GFx::AS3::Value& v, const Scaleform::GFx::ASString& str);

namespace Scaleform { namespace GFx { namespace AS3 {

// The VM of the tracer's call frame (Tracer::CF at +0x20, as3_tracer.h; that header is not included here).
static SF_INLINE VM& Sfr18TracerVM(const void* tracer)
{
    return (*reinterpret_cast<const CallFrame* const*>(static_cast<const UByte*>(tracer) + 0x20))->GetVM();
}

// @0x14250a1b0
InstanceTraits::Traits& TR::State::GetFunctType(const Value& value) const
{
    switch (value.GetKind())
    {
    case Value::kThunk:
        return static_cast<ClassTraits::Function&>(Sfr18TracerVM(pTracer).GetClassTraitsFunction()).GetThunkTraits();
    case Value::kThunkClosure:
        return static_cast<ClassTraits::Function&>(Sfr18TracerVM(pTracer).GetClassTraitsFunction()).GetThunkFunctionTraits();
    case Value::kVTableInd: // So far kVTableInd is used with MethodInd only.
    case Value::kVTableIndClosure:
        return static_cast<ClassTraits::Function&>(Sfr18TracerVM(pTracer).GetClassTraitsFunction()).GetVTableTraits();
    default:
        break;
    }

    return Sfr18TracerVM(pTracer).GetClassTraitsFunction().GetInstanceTraits();
}

// @0x14250cc30
SPInt Slots::GetPrevSlotIndex(SPInt ind) const
{
    const Slots* slots = this;
    while (static_cast<UPInt>(ind) < slots->FirstOwnSlotNum)
        slots = slots->Parent;
    return slots->VArray[static_cast<UPInt>(ind - static_cast<SPInt>(slots->FirstOwnSlotNum))].Prev;
}

// MS2-FUNCTIONAL 0x14250c230: the SDK form; the exe constant-initializes v (its Value(Object*) is inline there),
// ours calls the out-of-line ctor (sfr_as3_15) inside the guard.
// @0x14250c230
const Value& Value::GetNull()
{
    static const Value v((Object*)NULL);
    return v;
}

// MS2-FUNCTIONAL 0x14250f8f0: default-constructed Value has the undefined tag; local-static initialization differs.
// @0x14250f8f0
const Value& Value::GetUndefined()
{
    static const Value undefinedValue;
    return undefinedValue;
}

// The interned namespace {kind, uri}, else the public one (prefix unused here).
Instances::Namespace* FUN_142415c20(InstanceTraits::fl::Namespace* self, Abc::NamespaceKind kind, const ASString& uri,
                                    const Value& prefix);

// MS2-FUNCTIONAL 0x14250aa50: the empty public URI fast path matches; the exe tail-calls the lookup-only 0x142415c20,
// which falls back to the public namespace and never creates one.
// @0x14250aa50
Instances::Namespace& VM::GetInternedNamespace(Abc::NamespaceKind kind, const ASString& uri) const
{
    if (uri.IsEmpty() && kind == Abc::NS_Public)
        return GetPublicNamespace();
    InstanceTraits::fl::Namespace& traits =
        static_cast<InstanceTraits::fl::Namespace&>(GetClassTraitsNamespace().GetInstanceTraits());
    return *FUN_142415c20(&traits, kind, uri, Value::GetUndefined());
}

// The URI as a VM string, then interned (SDK AS3_VM.cpp form).
// @0x14250aac0
Instances::Namespace& VM::GetInternedNamespace(Abc::NamespaceKind kind, const StringDataPtr& uri) const
{
    return GetInternedNamespace(kind, GetStringManager().CreateString(uri.ToCStr(), uri.GetSize()));
}

// A null C string is taken as empty before interning (SDK AS3_VM.cpp form).
// MS2-FUNCTIONAL scheduling only: the exe loads the string manager ahead of the null test
// @0x14250ab50
Instances::Namespace& VM::GetInternedNamespace(Abc::NamespaceKind kind, const char* name) const
{
    if (!name) name = "";
    return GetInternedNamespace(kind, GetStringManager().CreateString(name));
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

// @0x14250be40
GlobalSlotIndex Object::GetNextDynPropIndex(GlobalSlotIndex ind) const
{
    const DynAttrsType::ConstIterator bit = DynAttrs.Begin();
    // AbsoluteIndex(GlobalSlotIndex) is ind - 1
    DynAttrsType::ConstIterator it(bit.GetContainer(), (ind.IsValid() ? static_cast<SPInt>(ind.Get() - 1) : -1));

    if (it.IsEnd())
        return GlobalSlotIndex(0);

    ++it;
    // Skip "DontEnum" properties.
    while (!it.IsEnd() && (it->First.Flags & 1))
        ++it;

    if (it.IsEnd())
        return GlobalSlotIndex(0);
    else
        return GlobalSlotIndex(static_cast<UInt32>(it.GetIndex() + 1));
}

// @0x14250c010
void Object::GetNextPropertyName(Value& name, GlobalSlotIndex ind) const
{
    const DynAttrsType::ConstIterator bit = DynAttrs.Begin();
    DynAttrsType::ConstIterator it(bit.GetContainer(), ind.Get() - 1);

    FUN_1424e0d40(name, it->First.Name);   // name = it->First.GetName()
}

// ==== Value: references ====

// @0x14251c720
void Value::Pick(Value& other)
{
    Release();
    SIMD::PrefetchObj(&other);
    memcpy(this, &other, sizeof(Value));
    other.SetFlags(0);
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

// Original isdigit() may assert if c > 127.
static inline bool Sfr18IsDigit(char c)
{
    return ('0' <= c && c <= '9');
}

// A string of decimal digits, optionally followed by '.' and zeros only: its number.
// @0x14250ee30
CheckResult GetStrNumber(ASStringNode* sn, Value::Number& result)
{
    if (sn == NULL)
        return false;

    const unsigned ssize = sn->Size;

    if (ssize > 0)
    {
        const char* sdata = sn->pData;
        char c = sdata[0];
        if (Sfr18IsDigit(c))
        {
            for (unsigned i = 1; i < ssize; ++i)
            {
                c = sdata[i];
                if (!Sfr18IsDigit(c))
                {
                    if (c == '.')
                    {
                        for (unsigned j = i + 1; j < ssize; ++j)
                        {
                            if (sdata[j] != '0')
                                return false;
                        }

                        // Everything is fine.
                        break;
                    }

                    return false;
                }
            }

            char* end;
            result = strtod(sdata, &end);

            return true;
        }
    }

    return false;
}

// ==== slots, traits, classes ====

// @0x14250dce0
ASStringNode* Slots::GetSlotNameNode(AbsoluteIndex ind) const
{
    if (ind < FirstOwnSlotNum)
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

// @0x14250d570
ASString InstanceTraits::Traits::GetQualifiedName(QNameFormat f) const
{
    const ASString& nsUri = GetNamespace().GetUri();
    const ASString name = GetName();

    if (nsUri.IsEmpty())
        return name;

    if (f == qnfWithColons)
        return nsUri + "::" + name;

    return nsUri + "." + name;
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

// ValueStack::AllocPage (0x1424eb6b0, sfr_as3_16), which the exe inlines into NewPage.
static SF_INLINE ValueStack::Page* Sfr18AllocStackPage(ValueStack& vs, UInt16 pageSize)
{
    const UInt16 size = Alg::Max<UInt16>(pageSize, 64);
    ValueStack::Page* p = static_cast<ValueStack::Page*>(
        SF_HEAP_AUTO_ALLOC(&vs, sizeof(ValueStack::Page) + sizeof(Value) * (size - 1)));
    p->PageSize       = size;
    p->ReservationNum = 0;
    return p;
}

// @0x1425182a0
ValueStack::Page* ValueStack::NewPage(UInt16 pageSize)
{
    Page* p = pReserved;
    while (p)
    {
        if (p->PageSize >= pageSize)
            break;
        p = p->pNext;
    }

    if (p)
    {
        if (p == pReserved)
        {
            pReserved = p->pNext;
            if (pReserved)
                pReserved->pPrev = NULL;
            p->pNext = NULL;
        }
        else
        {
            p->pPrev->pNext = p->pNext;
            if (p->pNext)
                p->pNext->pPrev = p->pPrev;
            p->pNext = NULL;
            p->pPrev = NULL;
        }
    }
    else
        p = Sfr18AllocStackPage(*this, pageSize);

    return p;
}

// @0x1425181c0
ValueRegisterFile::Page* ValueRegisterFile::NewPage(UInt16 pageSize)
{
    Page* p = NULL;
    if (pageSize <= Unk02)
    {
        p = pReservedPage;
        while (p)
        {
            if (p->PageSize >= pageSize)
                break;
            p = p->pNext;
        }
    }

    if (p)
    {
        if (p == pReservedPage)
        {
            pReservedPage = p->pNext;
            if (pReservedPage)
                pReservedPage->pPrev = NULL;
            p->pNext = NULL;
        }
        else
        {
            p->pPrev->pNext = p->pNext;
            if (p->pNext)
                p->pNext->pPrev = p->pPrev;
            p->pNext = NULL;
            p->pPrev = NULL;
        }
    }
    else
    {
        // AllocPage (0x1424eb640, sfr_as3_16), inlined here in the exe.
        if (pageSize > MaxAllocatedPageSize)
            MaxAllocatedPageSize = static_cast<UInt16>((pageSize + 64) / 64 * 64);
        else
            MaxAllocatedPageSize = Alg::Max<UInt16>(MaxAllocatedPageSize, 64);

        const UInt16 size = MaxAllocatedPageSize;
        p = static_cast<Page*>(SF_HEAP_AUTO_ALLOC(this, sizeof(Page) - sizeof(Value) +
                                                       (sizeof(Value) + sizeof(UInt16)) * size));
        p->PageSize    = size;
        p->ReservedNum = 0;
        p->CurrPos     = 0;
        p->pCurrent    = NULL;
    }

    return p;
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

// VM::MakeInternedNamespace (0x1425162a0), which the exe inlines into the VMAbcFile interning.
static SF_INLINE Pickable<Instances::Namespace> Sfr18MakeInternedNamespace(const VM& vm, Abc::NamespaceKind kind,
                                                                          const ASString& uri)
{
    if (uri.IsEmpty() && kind == Abc::NS_Public)
        return Pickable<Instances::Namespace>(vm.PublicNamespace.GetPtr(), PickValue);
    return static_cast<InstanceTraits::fl::Namespace&>(vm.GetClassTraitsNamespace().GetInstanceTraits())
        .MakeInternedInstance(kind, uri, Value::GetUndefined());
}

// VM::MakeInternedNamespace(kind, const StringDataPtr&) (0x142516340), likewise inlined.
static SF_INLINE Pickable<Instances::Namespace> Sfr18MakeInternedNamespace(const VM& vm, Abc::NamespaceKind kind,
                                                                          const StringDataPtr& uri)
{
    return Sfr18MakeInternedNamespace(vm, kind, vm.GetStringManager().CreateString(uri.ToCStr(), uri.GetSize()));
}

// @0x1425162a0
Pickable<Instances::Namespace> VM::MakeInternedNamespace(Abc::NamespaceKind kind, const ASString& uri) const
{
    return Sfr18MakeInternedNamespace(*this, kind, uri);
}

// @0x142516340
Pickable<Instances::Namespace> VM::MakeInternedNamespace(Abc::NamespaceKind kind, const StringDataPtr& uri) const
{
    return Sfr18MakeInternedNamespace(*this, kind, uri);
}

// @0x142516400
Pickable<Instances::Namespace> VM::MakeInternedNamespace(Abc::NamespaceKind kind, const char* name) const
{
    return Sfr18MakeInternedNamespace(*this, kind,
                                      GetStringManager().GetStringManager()->CreateString(name ? name : ""));
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

// Slots::GetSlotInfo (sfr_as3_04 0x142416fb0), one level inline here as in the exe.
static SF_INLINE const SlotInfo& Sfr18GetSlotInfo(const Slots& s, AbsoluteIndex ind)
{
    if (ind < s.FirstOwnSlotNum)
        return s.Parent->GetSlotInfo(ind);
    return s.VArray[static_cast<UInt32>(ind.Get()) - s.FirstOwnSlotNum].Value;
}

// MS2-FUNCTIONAL: GetSlotInfo/GetSlotNameNode one level inline as in the exe (560 vs 556); ours keeps FirstOwnSlotNum in a register, the exe re-reads it at each use
// @0x142511890
void Class::InitPrototypeFromVTable(AS3::Object& obj, ConvertFunc f) const
{
    InstanceTraits::Traits& itr = GetInstanceTraits();
    const VTable& vt = itr.GetVT();
    for (SPInt i = 0; static_cast<UInt32>(i) < itr.GetSlotInfoNum(); )
    {
        const SlotInfo& si = Sfr18GetSlotInfo(itr, AbsoluteIndex(i));
        if (si.BindType == SlotInfo::BT_Code)
        {
            obj.AddDynamicSlotValuePair(ASString(itr.GetSlotNameNode(AbsoluteIndex(i))), (this->*f)(vt.VTMethods[static_cast<UInt32>(si.ValueInd)], itr),
                                        SlotInfo::aDontEnum);
        }
        if (AbsoluteIndex(i) < itr.GetSlotInfoNum())
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

// @0x142511760
void AvmDisplayObj::InitClassName(const char* name)
{
    if (!pClassName)
    {
        UPInt len = SFstrlen(name);
        char* p = (char*)SF_HEAP_AUTO_ALLOC(pDispObj, len + 1);
        memcpy(p, name, len + 1);
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
        t = reinterpret_cast<UPInt>(&FUN_14250ffc0(*reinterpret_cast<VM*>(vm), *v));
    if (t != 0 && t == TrRd(vm, 0x1f0))
        t = TrRd(vm, 0x1f8);
    return t;
}

// Tracer::GetValueTraits(v, false) (0x14250ff00, Sfr27TracerGetValueTraits below), inlined by the Is*Type checks.
static SF_INLINE const Traits* Sfr18TracerValueTraits(const Tracer& tr, const Value& v)
{
    const Traits* result = NULL;

    switch (v.GetKind())
    {
    case Value::kUndefined:
        result = &tr.GetVoidType();
        break;
    case Value::kInstanceTraits:
        result = &v.GetInstanceTraits();
        break;
    case Value::kClassTraits:
        result = &v.GetClassTraits();
        break;
    default:
        result = &tr.GetVM().GetValueTraits(v);
    }

    // A hack.
    if (result && result == &tr.GetVM().GetClassTraitsClassClass())
        result = &tr.GetVM().GetClassTraitsObject();

    return result;
}

} // namespace TR

// @0x142514000
bool Tracer::IsBooleanType(const Value& v) const
{
    return TR::Sfr18TracerValueTraits(*this, v) == &GetBooleanType();
}
// @0x142514470
bool Tracer::IsNumberType(const Value& v) const
{
    return TR::Sfr18TracerValueTraits(*this, v) == &GetNumberType();
}
// @0x142514c30
bool Tracer::IsSIntType(const Value& v) const
{
    return TR::Sfr18TracerValueTraits(*this, v) == &GetSIntType();
}
// @0x1425150c0
bool Tracer::IsUIntType(const Value& v) const
{
    return TR::Sfr18TracerValueTraits(*this, v) == &GetUIntType();
}
// @0x142514e10
bool Tracer::IsStringType(const Value& v) const
{
    return TR::Sfr18TracerValueTraits(*this, v) == &GetStringType();
}

namespace TR {

// int, uint or Number
// @0x142514510
__declspec(noinline) bool Sfr27TracerIsNumericType(UPInt tracer, UPInt traits)
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
__declspec(noinline) UPInt Sfr27StateGetValueTraits(void* state, const Value* v)
{
    return TraceValueTraits(*reinterpret_cast<const UPInt*>(state), v);
}

// With classes resolved to their instance traits (asInstance), the traits' parent.
// MS2-FUNCTIONAL 0x14250ff00: clang shrink-wraps the frame (only the call path saves registers); the exe saves rbx / rdi up front
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
__declspec(noinline) Value* Sfr27StatePopOpValue(void* state, Value* result)
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

// VM::GetGlobalObject: the global object of the running frame's script (its saved scope's first value), else the
// 'this' of the innermost register set when it is an object; NULL with no frame. (A free function under the name
// sfr_as3_01c calls; VM does not declare it yet, and the register file's innermost set is private: read raw.)
// @0x14250a550
Scaleform::GFx::AS3::Object* FUN_14250a550(Scaleform::GFx::AS3::VM& vm)
{
    using namespace Scaleform::GFx::AS3;
    const CallFrameStack& cs = *reinterpret_cast<const CallFrameStack*>(&vm.Unk070);
    if (cs.Size > 0)
    {
        const Scaleform::UPInt i  = cs.Size - 1;
        const CallFrame&       cf = cs.Pages[i >> 6][i & 0x3f];
        if (cf.pSavedScope && cf.pSavedScope->GetSize() != 0)
            return (*cf.pSavedScope)[0].GetObject();
        const Value* pthis = *reinterpret_cast<Value* const*>(static_cast<const Scaleform::UByte*>(cf.pRegisterFile) + 8);   // pRF
        return pthis->IsObject() ? pthis->GetObject() : NULL;
    }
    return NULL;
}

// ---- Tracer word-code writers and block bookkeeping (free functions under the names sfr_as3_17 / sfr_as3_19 call;
// the Tracer of as3_tracer.h keeps these members private: raw offsets) ----
namespace Scaleform { namespace GFx { namespace AS3 { namespace TR {
namespace {
typedef ArrayDH_POD<UPInt, StatMV_VM>             TrPosArray;   // OrigOpcodePos +0x70 / NewOpcodePos +0x90
typedef ArrayLH_POD<UPInt, StatMV_VM_AbcFile_Mem> TrWordCode;   // *WCode +0x28
inline TrPosArray& TrPos(UPInt tracer, UPInt off) { return *reinterpret_cast<TrPosArray*>(tracer + off); }
inline TrWordCode& TrWCode(UPInt tracer) { return *reinterpret_cast<TrWordCode*>(TrRd(tracer, 0x28)); }
// A new opcode starts at the word code's end.
SF_FORCEINLINE void TrPushNewOpCode(UPInt tracer, int op)
{
    TrPos(tracer, 0x90).PushBack(TrWCode(tracer).GetSize());
    TrWCode(tracer).PushBack(static_cast<UPInt>(static_cast<SPInt>(op)));
}
}
}}}} // namespace Scaleform::GFx::AS3::TR

// Tracer::PushNewOpCode: op at the word code's end, its position noted in NewOpcodePos.
// @0x14251f930
__declspec(noinline) void FUN_14251f930(void* tr, int op)
{
    Scaleform::GFx::AS3::TR::TrPushNewOpCode(reinterpret_cast<Scaleform::UPInt>(tr), op);
}

// The same with one argument word.
// @0x14251fb90
void FUN_14251fb90(void* tr, int op, Scaleform::UPInt arg)
{
    using namespace Scaleform::GFx::AS3::TR;
    TrPushNewOpCode(reinterpret_cast<Scaleform::UPInt>(tr), op);
    TrWCode(reinterpret_cast<Scaleform::UPInt>(tr)).PushBack(arg);
}

// The same with two argument words.
// @0x14251fa10
void FUN_14251fa10(void* tr, int op, Scaleform::UPInt arg1, Scaleform::UPInt arg2)
{
    using namespace Scaleform::GFx::AS3::TR;
    TrPushNewOpCode(reinterpret_cast<Scaleform::UPInt>(tr), op);
    TrWCode(reinterpret_cast<Scaleform::UPInt>(tr)).PushBack(arg1);
    TrWCode(reinterpret_cast<Scaleform::UPInt>(tr)).PushBack(arg2);
}

// Tracer::PushNewOpCodeArg: one argument word at the word code's end.
// @0x14251fcd0
__declspec(noinline) void FUN_14251fcd0(Scaleform::UPInt tracer, Scaleform::UPInt arg)
{
    Scaleform::GFx::AS3::TR::TrWCode(tracer).PushBack(arg);
}

// Slots 1 and 2 of the 3-slot vftable 0x14317f848 (the class whose deleting destructors 0x1424e2c90 and 0x1424e3a00
// store it): forward to the tracer held at +0x10 of the second argument.
// @0x14251aca0
void FUN_14251aca0(void*, void* p, int op)
{
    FUN_14251f930(*reinterpret_cast<void**>(static_cast<char*>(p) + 0x10), op);
}

// @0x14251acd0
void FUN_14251acd0(void*, Scaleform::UPInt p, Scaleform::UPInt arg)
{
    FUN_14251fcd0(*reinterpret_cast<Scaleform::UPInt*>(p + 0x10), arg);
}

// Tracer::PopNewOpCode: the last new opcode and its arguments dropped from the word code.
// @0x14251cc80
void FUN_14251cc80(Scaleform::UPInt tracer)
{
    using namespace Scaleform::GFx::AS3::TR;
    TrPosArray& pos = TrPos(tracer, 0x90);
    const Scaleform::UPInt top = pos.Back();
    FUN_142524870(&pos, pos.GetSize() - 1);
    FUN_1425247f0(&TrWCode(tracer), top);
}

// Tracer::StoreOrigOpCodePos: a byte code position inside the code becomes the current one, is noted in
// OrigOpcodePos and maps to the word code's end.
// @0x1425212f0
void FUN_1425212f0(Scaleform::UPInt tracer, Scaleform::UPInt pos)
{
    using namespace Scaleform::GFx::AS3::TR;
    if (pos >= TrRd(tracer, 0x58))
        return;
    *reinterpret_cast<Scaleform::UPInt*>(tracer + 0x38) = pos;
    TrPos(tracer, 0x70).PushBack(pos);
    TrPos(tracer, 0xd0)[pos] = TrWCode(tracer).GetSize();
}

// Tracer::GetGlobalObject: the traced value of the global object, the saved scope's first value or else the method's
// 'this' (the state's first register). By value (out).
// MS2-FUNCTIONAL 0x14250a490: the copied Value's reference count bump stays out of line in our Value model; the exe inlines it.
// @0x14250a490
Scaleform::GFx::AS3::Value* FUN_14250a490(Scaleform::UPInt tracer, Scaleform::GFx::AS3::Value* out, Scaleform::UPInt state)
{
    using namespace Scaleform::GFx::AS3;
    const CallFrame& cf = *reinterpret_cast<const CallFrame*>(TR::TrRd(tracer, 0x20));
    if (cf.pSavedScope && cf.pSavedScope->GetSize() != 0)
        new (out) Value((*cf.pSavedScope)[0]);
    else
        new (out) Value(*reinterpret_cast<const Value*>(TR::TrRd(state, 0x18)));
    return out;
}

// Writer forwards of an opcode and its argument words (the object at +8 gets op through slot 1, each argument
// through slot 2). No direct callers.
struct Sfr34OpWriter
{
    virtual void Slot0() = 0;
    virtual void PutOp(void* owner, int op) = 0;
    virtual void PutArg(void* owner, Scaleform::UPInt arg) = 0;
};
// @0x14251f870
void FUN_14251f870(void* self, int op, Scaleform::UPInt arg1, Scaleform::UPInt arg2)
{
    Sfr34OpWriter* w = *reinterpret_cast<Sfr34OpWriter**>(static_cast<Scaleform::UByte*>(self) + 8);
    w->PutOp(self, op);
    w->PutArg(self, arg1);
    w->PutArg(self, arg2);
}
// @0x14251f8e0
void FUN_14251f8e0(void* self, int op, Scaleform::UPInt arg)
{
    Sfr34OpWriter* w = *reinterpret_cast<Sfr34OpWriter**>(static_cast<Scaleform::UByte*>(self) + 8);
    w->PutOp(self, op);
    w->PutArg(self, arg);
}

// ---- TR::State opcode refinement (free functions under the names sfr_as3_19 calls; as3_readargs.h declares them as
// private State members) ----
void FUN_1424f1e50(Scaleform::UPInt state, Scaleform::UPInt traits, int nullType);   // TR::State::ConvertOpTo
void FUN_1424f1ed0(Scaleform::UPInt state, Scaleform::SPInt ind, Scaleform::UPInt traits, int nullType);   // TR::State::ConvertRegisterTo

namespace Scaleform { namespace GFx { namespace AS3 { namespace TR {
namespace {
// Values of int, uint, Number and Boolean are never null (Tracer::IsNotNullableType, inlined).
SF_FORCEINLINE int TrNullTypeOf(UPInt vm, UPInt traits)
{
    if (traits == TrBuiltin(vm, 0x220) || traits == TrBuiltin(vm, 0x228) || traits == TrBuiltin(vm, 0x218) ||
        traits == TrBuiltin(vm, 0x210))
        return Value::NotNull;
    return Value::NullOrNot;
}
// Tracer::ReplaceOpCode: the last word written becomes op.
SF_FORCEINLINE void TrReplaceOpCode(UPInt tracer, int op)
{
    TrWordCode& wcode = TrWCode(tracer);
    wcode[wcode.GetSize() - 1] = static_cast<UInt32>(op);
}
inline const Value& TrOpTop(UPInt state)
{
    const ArrayDH<Value>& ops = *reinterpret_cast<const ArrayDH<Value>*>(state + 0x38);
    return ops[ops.GetSize() - 1];
}
}
}}}} // namespace Scaleform::GFx::AS3::TR

// TR::State::RefineOpCodeReg1: the opcode just written becomes op when register idx already has type's traits; else
// the register is converted to type. The register's index follows as the argument word.
// @0x142520d80
void FUN_142520d80(Scaleform::UPInt state, Scaleform::UPInt traits, int op, unsigned int idx)
{
    using namespace Scaleform::GFx::AS3;
    using namespace Scaleform::GFx::AS3::TR;
    const Scaleform::UPInt tracer = TrRd(state, 0);
    const Value* regs = reinterpret_cast<const Value*>(TrRd(state, 0x18));
    if (Sfr27StateGetValueTraits(reinterpret_cast<void*>(state), &regs[idx]) == traits)
        TrReplaceOpCode(tracer, op);
    else
        FUN_1424f1ed0(state, static_cast<int>(idx), traits, TrNullTypeOf(TrVM(tracer), traits));
    FUN_14251fcd0(TrRd(state, 0), idx);
}

// TR::State::RefineOpCodeStack1: the same for the operand stack top.
// @0x142520e60
void FUN_142520e60(Scaleform::UPInt state, Scaleform::UPInt traits, int op)
{
    using namespace Scaleform::GFx::AS3::TR;
    const Scaleform::UPInt tracer = TrRd(state, 0);
    if (Sfr27StateGetValueTraits(reinterpret_cast<void*>(state), &TrOpTop(state)) == traits)
        TrReplaceOpCode(tracer, op);
    else
        FUN_1424f1e50(state, traits, TrNullTypeOf(TrVM(tracer), traits));
}

// TR::State::RefineOpCodeStack2: the same for the top two operands (the top one is popped; the one left is converted).
// MS2-FUNCTIONAL 0x142520f30: the exe keeps the popped Value's flags word in a register across the calls for its release (push rdi frame); clang reloads it
// @0x142520f30
__declspec(safebuffers) void FUN_142520f30(Scaleform::UPInt state, Scaleform::UPInt traits, int op)
{
    using namespace Scaleform::GFx::AS3;
    using namespace Scaleform::GFx::AS3::TR;
    struct { Scaleform::UPInt w0, w1, w2, w3; } buf;   // raw storage: PopOpValue constructs the Value in it
    Value& popped = *reinterpret_cast<Value*>(&buf);
    Sfr27StatePopOpValue(reinterpret_cast<void*>(state), &popped);
    if (Sfr27StateGetValueTraits(reinterpret_cast<void*>(state), &TrOpTop(state)) == traits &&
        TraceValueTraits(TrRd(state, 0), &popped) == traits)
        TrReplaceOpCode(TrRd(state, 0), op);
    else
        FUN_1424f1e50(state, traits, TrNullTypeOf(TrVM(TrRd(state, 0)), traits));
    popped.~Value();
}

// ---- Tracer merging of the block entry states (free functions; as3_tracer.h declares them as Tracer members) ----
void FUN_1424201a0(void* arr, void* heap, Scaleform::UPInt n);   // ArrayDH<Value> growth
void FUN_14252efe0(Scaleform::UPInt tracer, Scaleform::UPInt a, Scaleform::UPInt b);   // raises verify error 0x42c (sfr_as3_19)
namespace Scaleform { namespace GFx { namespace AS3 { namespace TR {

namespace {
// The trace null type of a value joined to the instance traits itr: never null for the value classes, else what the
// two sides agree on.
SF_FORCEINLINE Value::TraceNullType TrJoinNullType(UPInt vm, UPInt itr, const Value& to, const Value& from)
{
    if (itr == TrBuiltin(vm, 0x220) || itr == TrBuiltin(vm, 0x228) || itr == TrBuiltin(vm, 0x218) ||
        itr == TrBuiltin(vm, 0x210))
        return Value::NotNull;
    return CanBeNull(to, from);
}
// to = the traits value { kind, null type } for tr (a temporary assigned through Value::Assign)
__declspec(safebuffers) SF_FORCEINLINE void TrAssignTraits(Value& to, UInt32 flags, UPInt tr)
{
    struct { UInt32 flags; UInt32 pad; UPInt bonus; UPInt tr; UPInt w3; } buf;   // raw storage of the temporary
    buf.bonus = 0;
    buf.flags = flags;
    buf.tr = tr;
    Value& v = *reinterpret_cast<Value*>(&buf);
    to.Assign(v);
    v.~Value();
}
__declspec(safebuffers) SF_FORCEINLINE void TrJoinClassTraits(UPInt tracer, Value& to, const Value& from, UPInt ctr)
{
    const UPInt vm = TrVM(tracer);
    TrAssignTraits(to, static_cast<UInt32>(TrJoinNullType(vm, TrRd(ctr, 0xc0), to, from)) << 5 | Value::kClassTraits, ctr);
}
// a state's operand stack, scope stack or register file (Tracer::MergeSet 0 / 1 / 2)
SF_FORCEINLINE UPInt TrMergeArray(UPInt state, int ms)
{
    switch (ms)
    {
    case 0: return state + 0x38;
    case 1: return state + 0x58;
    case 2: return state + 0x18;
    }
    return 0;
}
// an object kind (Object .. ThunkFunction) holding null
SF_FORCEINLINE bool TrIsNullObject(const Value& v)
{
    return static_cast<UInt32>(v.GetKind()) - 12u <= 3u && TrRd(reinterpret_cast<UPInt>(&v), 0x10) == 0;
}
// Value::AddRef with its weak-reference and per-kind paths inline
SF_FORCEINLINE void TrAddRef(const Value& v)
{
    const UPInt p = reinterpret_cast<UPInt>(&v);
    const UInt32 flags = *reinterpret_cast<const UInt32*>(p);
    const UInt32 k = flags & 0x1f;
    if (k <= 9)
        return;
    if ((flags >> 9) & 1)
    {
        ++*reinterpret_cast<int*>(TrRd(p, 8));
        return;
    }
    if (k == 10)
    {
        ++*reinterpret_cast<int*>(TrRd(p, 0x10) + 0x18);
        return;
    }
    UPInt obj;
    if (k <= 15)
        obj = TrRd(p, 0x10);
    else if (k <= 17)
        obj = TrRd(p, 0x18);
    else
        return;
    if (obj != 0)
    {
        UInt32* rc = reinterpret_cast<UInt32*>(obj + 0x10);
        *rc = (*rc + 1) & 0x8fbfffff;
    }
}
SF_FORCEINLINE bool TrRegChanged(UPInt state, UPInt ind)
{
    return (reinterpret_cast<const UByte*>(TrRd(state, 0x78))[ind >> 3] & (1u << (ind & 7))) != 0;
}
}

}}}}


// Tracer::IsAnyType: Object (or Class) instance traits.
// @0x142513f50
__declspec(noinline) bool FUN_142513f50(Scaleform::UPInt tracer, Scaleform::UPInt traits)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    using namespace Scaleform::GFx::AS3::TR;
    const UPInt vm = TrVM(tracer);
    return traits == TrBuiltin(vm, 0x1f8) || traits == TrBuiltin(vm, 0x1f0);
}

// Tracer::JoinSNodesUpdateType(Value& to, const Value& from, const ClassTraits::Traits& tr)
// MS2-FUNCTIONAL 0x142515840: clang tail-calls the weak-proxy free; the exe calls it and returns
// @0x142515840
__declspec(safebuffers) void FUN_142515840(Scaleform::UPInt tracer, Scaleform::GFx::AS3::Value& to, const Scaleform::GFx::AS3::Value& from,
                   Scaleform::UPInt ctr)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    using namespace Scaleform::GFx::AS3::TR;
    TrJoinClassTraits(tracer, to, from, ctr);
}

// Tracer::JoinSNodesUpdateType(Value& to, const Value& from, const InstanceTraits::Traits& tr)
// MS2-FUNCTIONAL 0x142515930: clang tail-calls the weak-proxy free; the exe calls it and returns
// @0x142515930
__declspec(noinline) __declspec(safebuffers) void FUN_142515930(Scaleform::UPInt tracer, Scaleform::GFx::AS3::Value& to,
                                        const Scaleform::GFx::AS3::Value& from, Scaleform::UPInt itr)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    using namespace Scaleform::GFx::AS3::TR;
    const UPInt vm = TrVM(tracer);
    TrAssignTraits(to, static_cast<UInt32>(TrJoinNullType(vm, itr, to, from)) << 5 | Value::kInstanceTraits, itr);
}

// Tracer::MergeValues: merges entry ind of from's operand stack / scope stack / register file into to's; a type
// conflict raises the verify error and fails.
// MS2-FUNCTIONAL 0x1425178e0: register allocation and block layout of the traits-join cases differ
// @0x1425178e0
__declspec(safebuffers) Scaleform::GFx::AS3::CheckResult* FUN_1425178e0(Scaleform::UPInt tracer, Scaleform::GFx::AS3::CheckResult* out,
                                                Scaleform::UPInt ind, Scaleform::UPInt to, Scaleform::UPInt from, int ms)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    using namespace Scaleform::GFx::AS3::TR;
    Value& tv = reinterpret_cast<Value*>(TrRd(TrMergeArray(to, ms), 0))[ind];
    const Value& fv = reinterpret_cast<const Value*>(TrRd(TrMergeArray(from, ms), 0))[ind];
    const UPInt t1 = TraceValueTraits(tracer, &tv);
    const UPInt t2 = TraceValueTraits(tracer, &fv);

    if (ms == 1)
    {
        if (tv.GetWith() != fv.GetWith())
            goto fail;
    }
    else if (ms == 2)
    {
        if (!TrRegChanged(from, ind))
            goto update;
        if (!TrRegChanged(to, ind))
        {
            tv.Assign(fv);
            goto update;
        }
    }

    if (t1 != t2)
    {
        if (tv.GetKind() == Value::kUndefined)
            tv.Assign(fv);
        else
        {
            const UPInt vm = TrVM(tracer);
            const UPInt objTr = TrBuiltin(vm, 0x1f8);
            if (t1 == objTr || t1 == TrBuiltin(vm, 0x1f0))
                ;
            else if (FUN_142513f50(tracer, t2))
                FUN_142515930(tracer, tv, fv, objTr);
            else
            {
                const bool num1 = Sfr27TracerIsNumericType(tracer, t1);
                if (num1 && Sfr27TracerIsNumericType(tracer, t2))
                    FUN_142515930(tracer, tv, fv, TrBuiltin(vm, 0x218));
                else if (TrIsNullObject(tv) || t1 == TrRd(vm, 0x270))
                {
                    if (TrIsNullObject(fv) || t2 == TrRd(vm, 0x270))
                        ;
                    else if (t2 != TrBuiltin(vm, 0x230) && Sfr27TracerIsNumericType(tracer, t2))
                        goto fail;
                    else
                        tv.Assign(fv);
                }
                else if (TrIsNullObject(fv) || t2 == TrRd(vm, 0x270))
                {
                    if (t1 != TrBuiltin(vm, 0x230) && num1)
                        goto fail;
                }
                else
                {
                    // the nearest common base: mark t1's chain, find the first marked one on t2's
                    for (UPInt t = t1; t != 0; t = TrRd(t, 0x88))
                        *reinterpret_cast<UPInt*>(t + 0x68) |= 0x80;
                    bool found = false;
                    for (UPInt t = t2; t != 0; t = TrRd(t, 0x88))
                    {
                        const UPInt f = TrRd(t, 0x68);
                        if (f & 0x80)
                        {
                            found = true;
                            if (f & 0x20)
                                TrJoinClassTraits(tracer, tv, fv, t);
                            else
                                FUN_142515930(tracer, tv, fv, t);
                            break;
                        }
                    }
                    for (UPInt t = t1; t != 0; t = TrRd(t, 0x88))
                        *reinterpret_cast<UPInt*>(t + 0x68) &= ~static_cast<UPInt>(0x80);
                    if (!found)
                        goto fail;
                }
            }
        }
    }

    if (ms == 2)
    {
    update:
        UByte& bits = reinterpret_cast<UByte*>(TrRd(to, 0x78))[ind >> 3];
        const unsigned bit = static_cast<unsigned>(ind & 7);
        if (TrRegChanged(from, ind) || TrRegChanged(to, ind))
            bits = static_cast<UByte>(bits | (1u << bit));
        else
            bits = static_cast<UByte>(bits & ~(1u << bit));
    }
    *out = true;
    return out;

fail:
    FUN_14252efe0(tracer, t1, t2);
    *out = false;
    return out;
}

// Tracer::MergeLists: merges from's operand stack / scope stack / register file into to's, entry by entry; to grows
// to from's size unless sizes must agree (update).
// MS2-FUNCTIONAL 0x142517740: CheckResult zero-init and AddRef ordering differ from the exe
// @0x142517740
__declspec(safebuffers) Scaleform::GFx::AS3::CheckResult* FUN_142517740(Scaleform::UPInt tracer, Scaleform::GFx::AS3::CheckResult* out,
                                                Scaleform::UPInt to, Scaleform::UPInt from, bool update, int ms)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    using namespace Scaleform::GFx::AS3::TR;
    UPInt* ta = reinterpret_cast<UPInt*>(TrMergeArray(to, ms));
    const UPInt* fa = reinterpret_cast<const UPInt*>(TrMergeArray(from, ms));
    if (update && ta[1] != fa[1])
    {
        *out = false;
        return out;
    }
    for (UPInt i = 0; i < fa[1]; ++i)
    {
        if (i < ta[1])
        {
            CheckResult r(false);
            if (!*FUN_1425178e0(tracer, &r, i, to, from, ms))
            {
                *out = false;
                return out;
            }
        }
        else
        {
            const Value& s = reinterpret_cast<const Value*>(fa[0])[i];
            FUN_1424201a0(ta, reinterpret_cast<void*>(ta[3]), ta[1] + 1);
            new (reinterpret_cast<Value*>(ta[0]) + ta[1] - 1) Value(s, Value::NotRefCounted);
            TrAddRef(s);
        }
    }
    *out = true;
    return out;
}

// ---- VMAbcFile::GetOpCode (traces a method body on first use) ----
Scaleform::UPInt* FUN_1424d9f30(Scaleform::UPInt* self, Scaleform::UPInt heap, Scaleform::UPInt body, Scaleform::UPInt ops,
                                Scaleform::UPInt extra);   // Tracer::Tracer (sfr_as3_15)
void FUN_1424f7840(void* tracer);   // Tracer::EmitCode (sfr_as3_17)
extern "C" void FUN_1424df070(void* tracer);   // Tracer::~Tracer (sfr_as3_16, C linkage)
namespace Scaleform { namespace GFx { namespace AS3 {

// MS2-FUNCTIONAL 0x14250c860: the exe splits the shrink-wrapped slow path into a chained unwind fragment
// @0x14250c860
__declspec(safebuffers) const ArrayLH_POD<UPInt, StatMV_VM_AbcFile_Mem>& VMAbcFile::GetOpCode(SInt32 mbi_ind,
                                                                                            const CallFrame& cf)
{
    if (OpCodeArray[mbi_ind].GetSize() == 0)
    {
        VM& vm = GetVM();
        struct { UPInt q[0x140 / sizeof(UPInt)]; } tr;   // raw storage of the Tracer
        FUN_1424d9f30(tr.q, reinterpret_cast<UPInt>(vm.GetMemoryHeap()), reinterpret_cast<UPInt>(&cf),
                      reinterpret_cast<UPInt>(&OpCodeArray[mbi_ind]), reinterpret_cast<UPInt>(&Exceptions[mbi_ind]));
        if (!vm.IsException())
            FUN_1424f7840(&tr);
        FUN_1424df070(&tr);
    }
    return OpCodeArray[mbi_ind];
}

}}} // namespace Scaleform::GFx::AS3

// Tracer: the run-time operands a chained multiname takes off the operand stack (its name and / or namespace set),
// the name value stored into the multiname. ctx: {tracer, state}.
// MS2-FUNCTIONAL 0x142520380: clang shares the per-case epilogues the exe duplicates, and saves rbp
// @0x142520380
__declspec(safebuffers) int FUN_142520380(void* ctx, void* multiname)
{
    using namespace Scaleform::GFx::AS3;
    using namespace Scaleform::GFx::AS3::TR;
    struct RawValue { Scaleform::UPInt w0, w1, w2, w3; };   // raw storage: PopOpValue constructs the Value in it
    void** c = reinterpret_cast<void**>(ctx);
    int& kind = *reinterpret_cast<int*>(multiname);
    Value& name = *reinterpret_cast<Value*>(reinterpret_cast<Scaleform::UPInt>(multiname) + 0x10);
    for (;;)
    {
        switch (kind)
        {
        case 1: case 9:      // RTQName: the namespace
        {
            RawValue b;
            Value& v = *reinterpret_cast<Value*>(&b);
            Sfr27StatePopOpValue(c[1], &v);
            v.~Value();
            return 1;
        }
        case 5: case 13:     // RTQNameL: the name and the namespace
        {
            {
                RawValue b;
                Value& v = *reinterpret_cast<Value*>(&b);
                Sfr27StatePopOpValue(c[1], &v);
                v.~Value();
            }
            RawValue b;
            Value& v = *reinterpret_cast<Value*>(&b);
            name.Assign(*Sfr27StatePopOpValue(c[1], &v));
            v.~Value();
            return 2;
        }
        case 6: case 14:     // MultinameL: the name
        {
            RawValue b;
            Value& v = *reinterpret_cast<Value*>(&b);
            name.Assign(*Sfr27StatePopOpValue(c[1], &v));
            v.~Value();
            return 1;
        }
        case 16:
        {
            Scaleform::UPInt log = *reinterpret_cast<Scaleform::UPInt*>(reinterpret_cast<Scaleform::UPInt>(c[0]) + 0x20);
            typedef void (*OutFn)(Scaleform::UPInt, int, const char*);
            (*reinterpret_cast<OutFn*>(*reinterpret_cast<Scaleform::UPInt*>(log) + 8))(
                log, 2, "Reading chained multiname in itself.");
            continue;
        }
        default:
            return 0;
        }
    }
}

// ---- Block entry states: the slot type of a property, joining a block's state into its successor's ----
namespace Scaleform { namespace GFx { namespace AS3 {
ClassTraits::Traits* FUN_1425085b0(const SlotInfo* psi, VM* pvm);   // SlotInfo::GetDataType (sfr_as3_17)
void FUN_142508720(const SlotInfo* psi, ASString* name, VM* pvm);   // SlotInfo::GetDataTypeName (sfr_as3_17)
InstanceTraits::Traits& FUN_14250a060(VM& vm, const Value& v);       // VM::GetFunctReturnType
void FUN_14252ecb0(void* vm, const void* error, const void* classInfo);   // VM: raise the error as an instance of the class
}}} // namespace Scaleform::GFx::AS3

// TR::State::GetPropertyType: the traced type of a property read through the slot si of the traits t, into result:
// the function type of a method slot, the return type of a getter, else the slot's declared type (its class for a
// Class-typed or class-bound slot). An unknown declared type raises VerifyError 1014 (false).
// MS2-FUNCTIONAL 0x14250cf20: raw-offset model of the ABC type multiname ("Class" in the public namespace) test
// @0x14250cf20
__declspec(safebuffers) const char* FUN_14250cf20(void* state, char* ret, const void* t, const void* si,
                                                  Scaleform::GFx::AS3::Value& result)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    using namespace Scaleform::GFx::AS3::TR;
    using Scaleform::GFx::ASString;
    const TR::State& st = *static_cast<const State*>(state);
    const UPInt s = reinterpret_cast<UPInt>(si);
    const UInt32 w = *reinterpret_cast<const UInt32*>(s);
    const int bt = static_cast<SInt32>(w << 22) >> 27;
    const Traits& tr = *static_cast<const Traits*>(t);
    UPInt rt;
    UInt32 flags;
    if (bt > 10 && !(w & 0x4000000))   // a method / accessor slot with a valid value index
    {
        const SPInt ind = static_cast<SPInt>(static_cast<SInt32>(w << 5) >> 15);
        if (bt == 11)
        {
            const Value f = tr.GetVT().GetValue(AbsoluteIndex(ind));
            rt = reinterpret_cast<UPInt>(&st.GetFunctType(f));
        }
        else
        {
            VM& vm = *reinterpret_cast<VM*>(TrVM(TrRd(reinterpret_cast<UPInt>(state), 0)));
            const UPInt methods = TrRd(reinterpret_cast<UPInt>(&tr.GetVT()), 8);
            rt = reinterpret_cast<UPInt>(&FUN_14250a060(
                vm, *reinterpret_cast<const Value*>(methods + (static_cast<UPInt>(ind) & 0xffffffff) * 0x20)));
        }
        flags = (static_cast<UInt32>(st.CanBeNull(*reinterpret_cast<const InstanceTraits::Traits*>(rt))) & ~8u) << 5 |
                Value::kInstanceTraits;
    }
    else
    {
        VM& vm = *reinterpret_cast<VM*>(TrVM(TrRd(reinterpret_cast<UPInt>(state), 0)));
        ClassTraits::Traits* ct = FUN_1425085b0(static_cast<const SlotInfo*>(si), &vm);
        if (!ct)
        {
            struct { UPInt node; } nb;   // raw storage: GetDataTypeName constructs the name in it
            ASString& name = *reinterpret_cast<ASString*>(&nb);
            FUN_142508720(static_cast<const SlotInfo*>(si), &name, &vm);
            {
                const Value tv(name);
                const VM::Error e(VM::ErrorID(1014) /* eClassNotFoundError */, vm, tv);
                FUN_14252ecb0(&vm, &e, &fl::VerifyErrorCI);
            }
            name.~ASString();
            *ret = 0;
            return ret;
        }
        rt = reinterpret_cast<UPInt>(ct);
        flags = Value::kClassTraits;
        const UByte* mn = *reinterpret_cast<const UByte* const*>(s + 0x20);   // the ABC type multiname
        if ((w & 0x3e0) != 0x20 && !(mn && (*mn & 0xf) == 4))
        {
            bool isClass = false;
            const UPInt file = *reinterpret_cast<const UPInt*>(s + 0x18);
            if (file && mn)
            {
                const UPInt abc = TrRd(file, 0x28);
                const int mind = *reinterpret_cast<const int*>(mn + 0xc);
                UPInt qn;   // the QName of the type
                if ((*mn & 0xf) == 0 || (*mn & 0xf) == 6)
                    qn = mind ? TrRd(abc, 0xb8) + static_cast<SPInt>(mind) * 0x10 : abc + 0xe8;
                else
                {
                    const SPInt q = *reinterpret_cast<const int*>(
                        *reinterpret_cast<const UPInt*>(TrRd(abc, 0x140) + static_cast<SPInt>(mind) * 8) + 0x24);
                    qn = q ? TrRd(abc, 0xb8) + q * 0x10 : abc + 0xe8;
                }
                const int nsi = *reinterpret_cast<const int*>(qn + 4);
                const UInt32* ns = reinterpret_cast<const UInt32*>(nsi ? TrRd(abc, 0x88) + static_cast<SPInt>(nsi) * 0x18
                                                                       : abc + 0xd0);
                const UPInt sv = TrRd(abc, 0x70) + static_cast<UPInt>(*reinterpret_cast<const UInt32*>(qn + 8)) * 8;
                const StringDataPtr tn = reinterpret_cast<const Abc::StringView*>(sv)->ToStringDataPtr();
                isClass = tn.ToCStr() && strncmp(tn.ToCStr(), "Class", 5) == 0 && (*ns & ~4u) == 0 &&
                          *reinterpret_cast<const UPInt*>(ns + 4) == 0;
            }
            if (!isClass)
            {
                rt = TrRd(rt, 0xc0);
                flags = (static_cast<UInt32>(st.CanBeNull(*reinterpret_cast<const InstanceTraits::Traits*>(rt))) & ~8u)
                            << 5 |
                        Value::kInstanceTraits;
            }
        }
    }
    TrAssignTraits(result, flags, rt);
    *ret = 1;
    return ret;
}

// Tracer::JoinSNodes: a block's state joined into the entry state of the block it falls / jumps into: the operand
// stack, the scope stack and the registers (a mismatch reported, the rest still joined); the target marked visited.
// MS2-FUNCTIONAL 0x142511b00: the exe inlines MergeLists (and MergeValues for the two stacks); here they are called
// @0x142511b00
void FUN_142511b00(Scaleform::UPInt tracer, Scaleform::UPInt* now, Scaleform::UPInt* old)
{
    using namespace Scaleform::GFx::AS3;
    const Scaleform::UPInt to = now[3], from = old[3];
    CheckResult r(false);
    FUN_142517740(tracer, &r, to, from, false, 0);
    FUN_142517740(tracer, &r, to, from, false, 1);
    FUN_142517740(tracer, &r, to, from, true, 2);
    *reinterpret_cast<Scaleform::UInt32*>(now + 2) |= 1;
}

// Tracer::MergeBlock: a block's state merged into an already visited block's entry state: unless the target is a
// catch target, its operand stack (when as deep) and its scope stack (VerifyError 1031 on a mismatch), then its
// registers.
// MS2-FUNCTIONAL 0x142516c40: the exe inlines MergeLists and MergeValues for the two stacks; here they are called
// @0x142516c40
char* FUN_142516c40(Scaleform::UPInt tracer, void* buf, Scaleform::UPInt* now, Scaleform::UPInt* old)
{
    using namespace Scaleform::GFx::AS3;
    CheckResult* out = static_cast<CheckResult*>(buf);
    const Scaleform::UPInt to = now[3], from = old[3];
    if (!(*reinterpret_cast<const Scaleform::UInt32*>(reinterpret_cast<Scaleform::UPInt>(now) + 0x14) & 4))
    {
        CheckResult r(false);
        FUN_142517740(tracer, &r, to, from, true, 0);
        if (!*FUN_142517740(tracer, &r, to, from, false, 1))
        {
            VM& vm = *reinterpret_cast<VM*>(TR::TrVM(tracer));
            const VM::Error e(VM::ErrorID(1031) /* eScopeDepthUnbalancedError */, vm,
                              static_cast<int>(TR::TrRd(to, 0x60)), static_cast<int>(TR::TrRd(from, 0x60)));
            FUN_14252ecb0(&vm, &e, &fl::VerifyErrorCI);
            *out = false;
            return reinterpret_cast<char*>(out);
        }
    }
    return reinterpret_cast<char*>(FUN_142517740(tracer, out, to, from, true, 2));
}

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

// The bounds of the display list of the object under the given matrix (returned in the result passed after this).
// @0x14250d6d0
char* Sfr27DisplayListBounds(UPInt self, char* ret, const void* matrix)
{
    FUN_1425f9ba0(self + 0xd8, ret, matrix);
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

void FUN_142524a30(void* self, const void* pheapAddr, UPInt newSize);   // IntStrings' ResizeNoConstruct

// ArrayData::Resize of IntStrings, with the exe's out-of-line ResizeNoConstruct.
static SF_INLINE void Sfr18ResizeIntStrings(ArrayLH<SPtr<ASStringNode> >& a, UPInt newSize)
{
    const UPInt oldSize = a.GetSize();
    FUN_142524a30(&a, &a, newSize);
    if (newSize > oldSize)
        ConstructArray<SPtr<ASStringNode> >(a.GetDataPtr() + oldSize, newSize - oldSize);
}

// SDK VMFile::GetInternedString form.
// @0x14250b240
ASString VMAbcFile::GetInternedString(UPInt strIndex)
{
    if (strIndex >= IntStrings.GetSize())
        Sfr18ResizeIntStrings(IntStrings, strIndex + 1);

    if (IntStrings[strIndex].GetPtr() == NULL)
    {
        const StringDataPtr s = pFile->Const_Pool.GetString(static_cast<UInt32>(strIndex));
        IntStrings[strIndex].SetPtr(GetVM().GetStringManager().CreateString(s.ToCStr(), s.GetSize()).GetNode());
    }

    return ASString(IntStrings[strIndex]);
}

// @0x14250ae60
Instances::Namespace& VMAbcFile::GetInternedNamespace(UPInt ind)
{
    typedef AbcMultinameHash<SPtr<Instances::Namespace> >::Key NsKey;
    SPtr<Instances::Namespace>* found = IntNamespaces.Get(ind);
    if (!found)
    {
        const Abc::ConstPool& cp = pFile->Const_Pool;
        const Abc::NamespaceInfo& info = ind == 0 ? cp.any_namespace : cp.ConstNamespace[ind];
        Pickable<Instances::Namespace> ns = Sfr18MakeInternedNamespace(GetVM(), info.Kind, info.NameURI);
        IntNamespaces.Entries.Add(NsKey(ind), SPtr<Instances::Namespace>(ns));
        found = IntNamespaces.Get(ind);
    }
    return **found;
}

} } }


namespace Scaleform { namespace GFx { namespace AS3 {

// The namespace a multiname is qualified with; one with a type argument gets that argument's namespace uri appended
// after a '$', so each (namespace, type) pair interns separately.
// AbcMultinameHash::Get(const Abc::Multiname&): only a QName (or QNameA) is interned by namespace index.
static SF_INLINE SPtr<Instances::Namespace>* Sfr18GetInterned(AbcMultinameHash<SPtr<Instances::Namespace> >& h,
                                                              const Abc::Multiname& mn)
{
    if ((static_cast<UInt32>(mn.Kind) & 3) <= 1)
        return h.Get(mn.Ind, mn.NextIndex);
    return NULL;
}

// ConstPool::GetNamespace: index 0 is the any namespace.
static SF_INLINE const Abc::NamespaceInfo& Sfr18GetNamespace(const Abc::ConstPool& cp, SPInt ind)
{
    return ind == 0 ? cp.any_namespace : cp.ConstNamespace[ind];
}

// @0x14250abf0
Instances::Namespace& VMAbcFile::GetInternedNamespace(const Abc::Multiname& mn)
{
    typedef AbcMultinameHash<SPtr<Instances::Namespace> >::Key NsKey;
    SPtr<Instances::Namespace>* pns = Sfr18GetInterned(IntNamespaces, mn);
    if (pns == NULL)
    {
        const Abc::ConstPool& cp = pFile->Const_Pool;
        const Abc::NamespaceInfo& info = Sfr18GetNamespace(cp, mn.Ind);
        ASString uri = GetVM().GetStringManager().CreateString(info.NameURI.ToCStr(), info.NameURI.GetSize());
        if (mn.NextIndex >= 0)
        {
            const Abc::Multiname& next = cp.GetMultiname(mn.NextIndex);
            const Abc::NamespaceInfo& ninfo = Sfr18GetNamespace(cp, next.Ind);
            uri.Append("$", 1);
            uri.Append(GetVM().GetStringManager().CreateString(ninfo.NameURI.ToCStr(), ninfo.NameURI.GetSize()));
        }
        IntNamespaces.Entries.Add(NsKey(mn.Ind, mn.NextIndex),
                                  SPtr<Instances::Namespace>(Sfr18MakeInternedNamespace(GetVM(), info.Kind, uri)));
        pns = Sfr18GetInterned(IntNamespaces, mn);
    }
    return **pns;
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

// @0x142519080
void AvmInteractiveObj::OnEventLoad()
{
    FUN_142526340(this, GetAS3Obj());
}

// AvmButton::IsTabable; self is the AvmInteractiveObjBase part (+0x30) of the button.
// @0x142514eb0
bool AvmButton_IsTabable(UPInt self)
{
    const AvmDisplayObj* avm = reinterpret_cast<const AvmDisplayObj*>(self - 0x30);
    if (!avm->pDispObj->GetVisible())
        return false;
    const InteractiveObject* io = static_cast<const InteractiveObject*>(avm->pDispObj);
    if ((io->Flags & InteractiveObject::Mask_TabEnabled) != 0)
        return (io->Flags & InteractiveObject::Mask_TabEnabled) == InteractiveObject::Mask_TabEnabled;
    return io->TabIndex > 0;
}

// AvmTextField::IsTabable; as the button, and an editable field is tabable by default.
// @0x142515050
bool AvmTextField_IsTabable(UPInt self)
{
    const AvmDisplayObj* avm = reinterpret_cast<const AvmDisplayObj*>(self - 0x30);
    if (!avm->pDispObj->GetVisible())
        return false;
    const InteractiveObject* io = static_cast<const InteractiveObject*>(avm->pDispObj);
    if ((io->Flags & InteractiveObject::Mask_TabEnabled) != 0)
        return (io->Flags & InteractiveObject::Mask_TabEnabled) == InteractiveObject::Mask_TabEnabled;
    else if (io->TabIndex > 0)
        return true;
    return !FUN_1425b9b10(reinterpret_cast<UPInt>(avm->pDispObj));
}

// AvmTextField::OnKeyEvent; self is the AvmInteractiveObjBase part (+0x30).
// MS2-FUNCTIONAL the HasAS3Obj test is folded into the GetAS3Obj load and pDispObj is loaded later
// @0x14251a350
bool AvmTextField_OnKeyEvent(UPInt self, const EventId& id, int*)
{
    const AvmDisplayObj* avm = reinterpret_cast<const AvmDisplayObj*>(self - 0x30);
    if (avm->pAS3RawPtr || avm->pAS3CollectiblePtr)
        FUN_142467ec0(avm->GetAS3Obj(), &id, avm->pDispObj);
    return false;
}

// AvmButton::OnMouseEvent; self is the AvmButtonBase part (+0x40). A press becomes a click, the rest goes to
// OnEvent.
// MS2-FUNCTIONAL free function on the subobject this: fields are read off the AvmDisplayObj base, not off self
// @0x14251a830
bool AvmButton_OnMouseEvent(UPInt self, const EventId& id)
{
    AvmDisplayObj* avm = reinterpret_cast<AvmDisplayObj*>(self - 0x40);
    if (id.Id == EventId::Event_Press)
    {
        if (avm->pAS3RawPtr || avm->pAS3CollectiblePtr)
        {
            EventId click(id);
            click.Id = AS3Event_Click;
            FUN_142467ec0(avm->GetAS3Obj(), &click, avm->pDispObj);
        }
        return true;
    }
    return avm->OnEvent(id);
}

// AvmTextField::OnEventLoad: the field joins the play list after its place in the parent, and the optimized
// advance list when it asks to.
// @0x1425190f0
void AvmTextField_OnEventLoad(UPInt self)
{
    AvmDisplayObj* avm = reinterpret_cast<AvmDisplayObj*>(self);
    InteractiveObject* t = static_cast<InteractiveObject*>(avm->pDispObj);
    if (InteractiveObject* pafter = ToAvmInteractiveObj(t->GetParent())->FindInsertToPlayList(t))
        t->InsertToPlayListAfter(pafter);
    else
        t->AddToPlayList();
    static_cast<InteractiveObject*>(avm->pDispObj)->ModifyOptimizedPlayList();
    FUN_142526340(avm, avm->GetAS3Obj());
}

// AvmTextField::GetStyleSheet; self is the AvmTextFieldBase part (+0x40). The style manager of the field's
// style sheet when the field uses one.
// @0x14250ef30
UPInt AvmTextField_GetStyleSheet(UPInt self)
{
    const UPInt sheet = FUN_1425b7e60(AccRd(self - 0x28, 0));
    if (reinterpret_cast<const AvmTextFieldBase*>(self)->HasStyleSheet())
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

// ---- focus events, play list, frame counter and event chains (sfr34) ---------------------------------------------

// The AS3 event ids past the GFx ones the frame counter queues each frame.
enum
{
    Sfr34_Event_FrameConstructed = 0x1000015,
    Sfr34_Event_ExitFrame        = 0x1000016
};

// What OnFocusChange reads of the ProcessFocusKeyInfo the movie fills (gfx_movieimpl.h, player side only).
struct Sfr34_FocusKeyInfoView
{
    UByte   Unrecovered00[0x34];
    UInt32  KeyCode;        // +0x34
    UByte   KeyboardIndex;  // +0x38
    UByte   KeysState;      // +0x39 bit 0 shift
};

// The movie's AS3 root, as the display objects reach it through their MovieImpl.
static inline MovieRoot* Sfr34_AS3Root(const AvmDisplayObj* pavm)
{
    return static_cast<MovieRoot*>(pavm->GetMovieImpl()->pASMovieRoot);
}

// MS2-FUNCTIONAL register allocation (the exe keeps the AS3 raw pointer live across the focus-event creation)
// @0x142519d50
void AvmInteractiveObj::OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                                unsigned controllerIdx, FocusMovedType fmt)
{
    SF_UNUSED(fmt);
    if (!pAS3RawPtr && !pAS3CollectiblePtr)
        return;
    const char* type = "focusIn";
    if (event == InteractiveObject::KillFocus)
        type = "focusOut";
    Instances::fl_display::DisplayObject* related = NULL;
    if (oldOrNewFocusCh)
        related = ToAvmInteractiveObj(oldOrNewFocusCh)->GetAS3Obj();
    Instances::fl_display::DisplayObject* as3obj = GetAS3Obj();
    SPtr<Instances::fl_events::FocusEvent> evt =
        as3obj->CreateFocusEventObject(Sfr34_AS3Root(this)->GetStringManager418()->CreateConstString(type),
                                       related, controllerIdx, false, 0);
    as3obj->DispatchEventObject(evt, pDispObj);
}

// MS2-FUNCTIONAL register allocation and shared epilogue of the no-AS3-object return
// @0x142519ee0
bool AvmInteractiveObj::OnFocusChange(InteractiveObject* ptoBeFocused, unsigned controllerIdx, FocusMovedType fmt,
                                      ProcessFocusKeyInfo* pfocusKeyInfo)
{
    const char* type = (fmt == GFx_FocusMovedByKeyboard) ? "keyFocusChange" : "mouseFocusChange";
    bool result = true;
    if (!pAS3RawPtr && !pAS3CollectiblePtr)
        return result;
    Instances::fl_display::DisplayObject* related = NULL;
    if (ptoBeFocused)
        related = ToAvmInteractiveObj(ptoBeFocused)->GetAS3Obj();
    Instances::fl_display::DisplayObject* as3obj = GetAS3Obj();
    SPtr<Instances::fl_events::FocusEvent> evt =
        as3obj->CreateFocusEventObject(Sfr34_AS3Root(this)->GetStringManager418()->CreateConstString(type),
                                       related, controllerIdx, false, 0);
    evt->Cancelable = true;
    if (fmt == GFx_FocusMovedByKeyboard)
    {
        const Sfr34_FocusKeyInfoView* pinfo = reinterpret_cast<const Sfr34_FocusKeyInfoView*>(pfocusKeyInfo);
        evt->KeyCode  = pinfo->KeyCode;
        evt->ShiftKey = (pinfo->KeysState & 1) != 0;
    }
    as3obj->DispatchEventObject(evt, pDispObj);
    result = !evt->DefaultPrevented;
    return result;
}

// Takes the object and its branch (the play list entries before it that descend from it) out of the play list and
// puts them back where the parent wants the object now.
// MS2-FUNCTIONAL block layout of the branch reinsertion
// @0x142517ed0
void AvmInteractiveObj::MoveBranchInPlayList()
{
    InteractiveObject* p = GetIntObj();
    InteractiveObject* pend = p;
    InteractiveObject* pbefore = p->pPlayNext;
    InteractiveObject* pafter = NULL;

    // the first entry before the branch: the first one p is not an ancestor of
    for (InteractiveObject* pcur = p->pPlayPrev; pcur; pcur = pcur->pPlayPrev)
    {
        InteractiveObject* c = pcur;
        while (c && c != p)
            c = c->GetParent();
        if (!c)
        {
            pafter = pcur;
            break;
        }
    }
    if (pafter)
    {
        pend = pafter->pPlayNext;
        pafter->pPlayNext = pbefore;
    }
    else if (pbefore)
    {
        pend = GetMovieImpl()->pPlayList;
        GetMovieImpl()->pPlayList = pbefore;
    }
    if (pbefore)
        pbefore->pPlayPrev = pafter;
    p->pPlayNext = NULL;
    pend->pPlayPrev = NULL;

    // the branch [pend .. p] goes in again after what the parent picks, or at the head
    InteractiveObject* parent = GetIntObj()->GetParent();
    if (parent)
    {
        InteractiveObject* pins = ToAvmInteractiveObj(parent)->FindInsertToPlayList(p);
        if (pins)
        {
            p->pPlayNext = pins->pPlayNext;
            if (pins->pPlayNext)
                pins->pPlayNext->pPlayPrev = p;
            pins->pPlayNext = pend;
            pend->pPlayPrev = pins;
            GetMovieImpl()->Flags |= MovieImpl::Flag_OptAdvListInvalid;
            return;
        }
    }
    if (GetMovieImpl()->pPlayList)
    {
        p->pPlayNext = GetMovieImpl()->pPlayList;
        GetMovieImpl()->pPlayList->pPlayPrev = p;
    }
    GetMovieImpl()->pPlayList = pend;
    GetMovieImpl()->Flags |= MovieImpl::Flag_OptAdvListInvalid;
}

// The out-of-line copy of the inline InteractiveObject::ModifyOptimizedPlayList.
// MS2-FUNCTIONAL out-of-line copy of the inline member, recovered as a free wrapper
// @0x142517e70
void Sfr34_ModifyOptimizedPlayList(InteractiveObject* p)
{
    p->ModifyOptimizedPlayList();
}

// MS2-FUNCTIONAL instruction scheduling of the Value init against the AS3 object load
// @0x1425200b0
void AvmSprite::QueueFrameScript(unsigned frame)
{
    Value v;
    if (Instances::fl_display::DisplayObject* as3obj = GetAS3Obj())
    {
        if (static_cast<Instances::fl_display::Sprite*>(GetAS3Obj())->GetFrameScript(frame, &v))
        {
            DisplayObject* pdispObj = pDispObj;
            MovieRoot::ActionEntry* pe =
                static_cast<MovieRoot*>(pdispObj->GetASMovieRoot())->InsertEmptyAction(MovieRoot::AL_Frame);
            pe->Type = MovieRoot::ActionEntry::Entry_Function;
            pe->pCharacter = pdispObj;
            pe->Function = v;
            pe->CFunction = NULL;
            pe->pAS3Obj = NULL;
            pe->pNLoadInitCL = NULL;
            SF_UNUSED(as3obj);
        }
    }
}

// The per-event lists of the display objects listening for a frame or activation event (+0x150 of MovieRoot).
// Entries are only nulled while the lists may be walked; QueueEvents drops them.
class EventChains
{
public:
    typedef ArrayLH<WeakPtr<DisplayObject> > Chain;
    typedef HashUncachedLH<int, AutoPtr<Chain>, IdentityHash<int> > ChainHash;

    void AddToChain(EventId::IdCode evtId, DisplayObject* obj);     // 0x1424eac70
    void RemoveFromChain(EventId::IdCode evtId, DisplayObject* obj);
    void QueueEvents(EventId::IdCode evtId);
    void Dispatch(EventId::IdCode code);                            // 0x1424f71b0 (sfr_as3_17)

private:
    UPInt FindObjectIndexInChain(Chain* chain, DisplayObject* obj); // 0x142501dc0

    ChainHash Chains;
};

// MS2-FUNCTIONAL Hash::Get of the chain hash is not inlined here
// @0x142522830
void EventChains::RemoveFromChain(EventId::IdCode evtId, DisplayObject* obj)
{
    AutoPtr<Chain>* ppchain = Chains.Get(evtId);
    if (ppchain)
    {
        Chain* chain = ppchain->GetPtr();
        UPInt i = FindObjectIndexInChain(chain, obj);
        if (i != SF_MAX_UPINT)
            (*chain)[i] = NULL;
    }
}

// MS2-FUNCTIONAL Hash::Get of the chain hash is not inlined here
// @0x14251fd40
void EventChains::QueueEvents(EventId::IdCode evtId)
{
    AutoPtr<Chain>* ppchain = Chains.Get(evtId);
    if (ppchain)
    {
        Chain* chain = ppchain->GetPtr();
        for (UPInt i = 0; i < chain->GetSize();)
        {
            if ((*chain)[i] == (DisplayObject*)NULL)
            {
                chain->RemoveAt(i);
                continue;
            }
            EventId evt(evtId);
            Ptr<DisplayObject> dobj = (*chain)[i];
            ToAvmDisplayObj(dobj)->OnEvent(evt);
            ++i;
        }
    }
}

// MovieRoot as far as the event chains go.
struct Sfr34_MovieRootChainsView
{
    UByte       Unrecovered00[0x150];
    EventChains Chains;     // +0x150
};

// The stage's frame counter: the last play list entry, which queues the frame scripts and frame events of the
// whole play list once per frame. 0xe0 bytes; vftables 0x14317e608 and 0x14317e9a0.
class FrameCounter : public InteractiveObject
{
    Ptr<DisplayObjContainer> pRoot;     // +0xd8
public:
    FrameCounter(MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id)
        : InteractiveObject(pbindingDefImpl, pasRoot, pparent, id)
    {
    }
    ~FrameCounter() {}

    virtual void            ForceShutdown() {}
    virtual CharacterDef*   GetCharacterDef() const { return NULL; }
    virtual void            AdvanceFrame(bool nextFrame, float framePos = 0.0f);   // 0x1424eb260
    virtual int             CheckAdvanceStatus(bool playingNow) { SF_UNUSED(playingNow); return 1; }
    virtual unsigned        GetLoadingFrame() const { return 1; }

    void QueueFrameActions();
};

// MS2-FUNCTIONAL the exe inlines QueueFrameScript in one of the play list loops
// @0x14251ff60
void FrameCounter::QueueFrameActions()
{
    MovieRoot* proot = static_cast<MovieRoot*>(GetMovieImpl()->pASMovieRoot);
    EventChains& chains = reinterpret_cast<Sfr34_MovieRootChainsView*>(proot)->Chains;
    chains.QueueEvents(EventId::IdCode(Sfr34_Event_FrameConstructed));
    // the play list backwards from the stage, the optimized one while it is valid
    if (!GetMovieImpl()->IsOptAdvListInvalid())
    {
        for (InteractiveObject* cur = pPlayPrevOpt; cur; cur = cur->pPlayPrevOpt)
        {
            ToAvmDisplayObj(cur)->Flags |= AvmDisplayObj::Flag_Loaded;
            if (cur->IsSprite())
            {
                AvmSprite* aspr = static_cast<AvmSprite*>(ToAvmDisplayObj(cur));
                if (aspr->SprFlags & AvmSprite::Flag_NeedExecuteFrame)
                {
                    aspr->QueueFrameScript(aspr->GetSprite()->GetCurrentFrame());
                    aspr->SprFlags &= ~AvmSprite::Flag_NeedExecuteFrame;
                }
            }
        }
    }
    else
    {
        for (InteractiveObject* cur = pPlayPrev; cur; cur = cur->pPlayPrev)
        {
            ToAvmDisplayObj(cur)->Flags |= AvmDisplayObj::Flag_Loaded;
            if (cur->IsSprite())
            {
                AvmSprite* aspr = static_cast<AvmSprite*>(ToAvmDisplayObj(cur));
                if (aspr->SprFlags & AvmSprite::Flag_NeedExecuteFrame)
                {
                    aspr->QueueFrameScript(aspr->GetSprite()->GetCurrentFrame());
                    aspr->SprFlags &= ~AvmSprite::Flag_NeedExecuteFrame;
                }
            }
        }
    }
    chains.QueueEvents(EventId::IdCode(Sfr34_Event_ExitFrame));
}

// The AS3 stage as far as its level insertion goes (sfr_as3_15 keeps the rest of the layout).
class Stage : public DisplayObjContainer
{
public:
    Ptr<DisplayObjContainer> pRoot;             // +0x110
    Ptr<InteractiveObject>   FrameCounterObj;   // +0x118

    Stage(MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id);
    virtual void OnInsertionAsLevel(int level);
    virtual void PropagateMouseEvent(const EventId& id);
    // (sfr21) the container overrides sfr_as3_15's Stage vftable references.
    virtual InteractiveObject* GetTopParent(bool ignoreLockRoot = false) const;
    virtual bool        IsFocusEnabled(FocusMovedType = GFx_FocusMovedByKeyboard) const;
    virtual bool        GetLabeledFrame(const char* plabel, unsigned* frameNumber, bool translateNumbers = true);
    virtual const String* GetFrameLabel(unsigned frame, unsigned* exactFrame = NULL);
    virtual void        GotoFrame(unsigned targetFrameNumber);
    virtual unsigned    GetLoadingFrame() const;
};

// The frame queries go to the root movie clip.
// @0x142509dd0
const String* Stage::GetFrameLabel(unsigned frame, unsigned* exactFrame)
{
    return pRoot ? pRoot->GetFrameLabel(frame, exactFrame) : NULL;
}

// @0x14250b370
bool Stage::GetLabeledFrame(const char* plabel, unsigned* frameNumber, bool translateNumbers)
{
    return pRoot ? pRoot->GetLabeledFrame(plabel, frameNumber, translateNumbers) : false;
}

// @0x14250b3b0
unsigned Stage::GetLoadingFrame() const
{
    return 1;
}

// The stage is the top unless it was itself parented.
// @0x14250f870
InteractiveObject* Stage::GetTopParent(bool ignoreLockRoot) const
{
    if (!pParent)
        return const_cast<Stage*>(this);
    return pParent->GetTopParent(ignoreLockRoot);
}

// @0x142510d20
void Stage::GotoFrame(unsigned targetFrameNumber)
{
    if (pRoot)
        pRoot->GotoFrame(targetFrameNumber);
}

// @0x142514310
bool Stage::IsFocusEnabled(FocusMovedType) const
{
    return false;
}

// @0x14251a110
void Stage::OnInsertionAsLevel(int level)
{
    FrameCounterObj = *SF_HEAP_AUTO_NEW(this) FrameCounter(pDefImpl, GetASMovieRoot(), NULL, ResourceId(0));
    FrameCounterObj->AddToPlayList();
    DisplayObjContainer::OnInsertionAsLevel(level);
}

// sfr34 batch D: the added / removed events and their propagation down the display list.


// MovieRoot::CheckAvm is vftable slot 4 (+0x20) of the movie root: it creates the VM on first use.
static inline void Sfr34_CheckAvm(MovieRoot* root)
{
    typedef bool (*Fn)(MovieRoot*);
    (*reinterpret_cast<Fn const* const*>(root))[4](root);
}

// The stage event (addedToStage / removedFromStage) as the VM's EventDispatcher class creates it.
static inline SPtr<Instances::fl_events::Event> Sfr34_CreateStageEvent(MovieRoot* root, const ASString& type)
{
    Sfr34_CheckAvm(root);
    return static_cast<Classes::fl_events::EventDispatcher*>(root->pAVM->EventDispatcherClass.GetPtr())
        ->CreateEventObject(type, false, false);
}

// The AS3 object becomes collectible and gets "added"; on the stage, "addedToStage" goes down the branch
// (to the children too unless the timeline placed the object).
// @0x1425185d0
void AvmDisplayObj::OnAdded(bool byTimeline)
{
    const ASString&                       added = AS3RootOf(pDispObj)->BuiltinsMgr.GetBuiltin(AS3Builtin_added);
    Instances::fl_display::DisplayObject* obj   = GetAS3Obj();
    FUN_142526340(this, obj);
    if (obj)
    {
        SPtr<Instances::fl_events::Event> evt = obj->CreateEventObject(added, true, false);
        FUN_14243d870(&evt->Target, obj);
        obj->DispatchEventObject(evt, pDispObj);
    }
    if (IsStageAccessible())
    {
        Sfr34_CheckAvm(AS3RootOf(pDispObj));
        MovieRoot* sroot = AS3RootOf(pDispObj);
        if (!sroot->pAVM->IsException())
        {
            SPtr<Instances::fl_events::Event> evt =
                Sfr34_CreateStageEvent(sroot, sroot->BuiltinsMgr.GetBuiltin(AS3Builtin_addedToStage));
            PropagateEvent(*evt, !byTimeline);
        }
    }
}

// "removed" to the AS3 object, "removedFromStage" down the branch; the object is then kept raw (no longer
// collectible).
// @0x14251ace0
void AvmDisplayObj::OnRemoved(bool byTimeline)
{
    const ASString&                       removed = AS3RootOf(pDispObj)->BuiltinsMgr.GetBuiltin(AS3Builtin_removed);
    Instances::fl_display::DisplayObject* obj     = GetAS3Obj();
    if (obj)
    {
        SPtr<Instances::fl_events::Event> evt = obj->CreateEventObject(removed, true, false);
        FUN_14243d870(&evt->Target, obj);
        obj->DispatchEventObject(evt, pDispObj);
    }
    if (IsStageAccessible())
    {
        Sfr34_CheckAvm(AS3RootOf(pDispObj));
        MovieRoot* sroot = AS3RootOf(pDispObj);
        if (!sroot->pAVM->IsException())
        {
            SPtr<Instances::fl_events::Event> evt =
                Sfr34_CreateStageEvent(sroot, sroot->BuiltinsMgr.GetBuiltin(AS3Builtin_removedFromStage));
            PropagateEvent(*evt, !byTimeline);
        }
    }
    pAS3RawPtr = obj;
    reinterpret_cast<SPtr<Instances::fl_display::DisplayObject>&>(pAS3CollectiblePtr) = NULL;
}

// A copy of evt, targeted at and dispatched from this object.
// @0x14251f3a0
void AvmDisplayObj::PropagateEvent(const Instances::fl_events::Event& evt, bool inclChildren)
{
    SF_UNUSED(inclChildren);
    SPtr<Instances::fl_events::Event> e = evt.Clone();
    Instances::fl_display::DisplayObject* obj = GetAS3Obj();
    if (obj)
    {
        FUN_14243d870(&e->Target, obj);
        obj->DispatchEventObject(e, pDispObj);
    }
}

// The container's own copy, then (inclChildren) every child's branch.
// MS2-FUNCTIONAL same length; the exe lays out the child's null-AvmDisplayObj branch the other way round
// @0x14251f430
void AvmDisplayObjContainer::PropagateEvent(const Instances::fl_events::Event& evt, bool inclChildren)
{
    {
        SPtr<Instances::fl_events::Event> e = evt.Clone();
        Instances::fl_display::DisplayObject* obj = GetAS3Obj();
        if (obj)
        {
            FUN_14243d870(&e->Target, obj);
            obj->DispatchEventObject(e, pDispObj);
        }
    }
    if (inclChildren)
    {
        DisplayObjContainer* cont = static_cast<DisplayObjContainer*>(static_cast<DisplayObjectBase*>(pDispObj));
        for (unsigned i = 0, n = unsigned(cont->mDisplayList.GetCount()); i < n; ++i)
        {
            DisplayObjectBase* ch  = cont->mDisplayList.GetDisplayObject(i);
            DisplayObjectBase* sch = ch->IsScriptableObject() ? ch : NULL;
            AvmDisplayObj*     pavm = sch ? ToAvmDisplayObj(sch) : NULL;
            pavm->PropagateEvent(evt, true);
        }
    }
}

// sfr34 batch E: removing children from an AS3 container.

// What follows the removal of ch from the display list: the AS3 side gets "removed", ch loses its parent and
// leaves the play list branch, and a timeline child stops being one.
static __forceinline void Sfr34_AfterChildRemoved(DisplayObjectBase* ch)
{
    InteractiveObject* pio  = ch->IsInteractiveObject() ? static_cast<InteractiveObject*>(ch) : NULL;
    DisplayObjectBase* sch  = ch->IsScriptableObject() ? ch : NULL;
    AvmDisplayObj*     pavm = sch ? ToAvmDisplayObj(sch) : NULL;
    pavm->OnRemoved(false);
    ch->pParent = NULL;
    if (pio && pio->IsInPlayList())
        ToAvmInteractiveObj(pio)->MoveBranchInPlayList();
    DisplayObject* dobj = static_cast<DisplayObject*>(ch);
    if (dobj->Flags & DisplayObject::Mask_TimelineObject)
    {
        dobj->Flags &= ~DisplayObject::Mask_TimelineObject;
        dobj->SetAcceptAnimMoves(false);
        ch->CreateFrame = 0;
        ch->Depth       = -1;
        ToAvmDisplayObj(ch)->OnDetachFromTimeline();
    }
}

// MS2-FUNCTIONAL the exe merges the not-found return into the release of the held reference
// @0x142522570
DisplayObjectBase* AvmDisplayObjContainer::RemoveChild(DisplayObjectBase* ch)
{
    Ptr<DisplayObjectBase> hold = ch;
    DisplayObjContainer*   cont = GetDisplayObjContainer();
    SPInt                  index = cont->mDisplayList.FindDisplayIndex(ch);
    if (index < 0)
        return NULL;
    cont->mDisplayList.RemoveEntryAtIndex(pDispObj, UPInt(index));
    cont->mDisplayList.Flags |= DisplayList::Flags_DepthToIndexInvalid | DisplayList::Flags_MayContainForeignElems;
    Sfr34_AfterChildRemoved(ch);
    return ch;
}

// MS2-FUNCTIONAL declared void here; the exe also returns the removed child (NULL past the end) in rax
// @0x1425226a0
void AvmDisplayObjContainer::RemoveChildAt(unsigned index)
{
    DisplayObjContainer* cont = GetDisplayObjContainer();
    if (index >= unsigned(cont->mDisplayList.GetCount()))
        return;
    Ptr<DisplayObjectBase> hold = cont->mDisplayList.GetDisplayObject(index);
    cont->mDisplayList.RemoveEntryAtIndex(pDispObj, index);
    cont->mDisplayList.Flags |= DisplayList::Flags_DepthToIndexInvalid | DisplayList::Flags_MayContainForeignElems;
    Sfr34_AfterChildRemoved(hold.GetPtr());
}

// sfr34 batch F: hit tests of the AS3 shapes and bitmaps. ShapeObject and AvmBitmap are opaque in as3_avm.h
// (their constructors store the exe's vftables), so their virtuals are members of views over the same layout:
// the DisplayObject part, the AvmDisplayObj part at +0x90, then the class's own fields.

class Sfr34_ShapeObjectView : public DisplayObject
{
public:
    UByte                       AvmPart[0x30];  // +0x90 AvmDisplayObj
    Ptr<ShapeBaseCharacterDef>  pDef;           // +0xc0
    Ptr<DrawingContext>         pDrawing;       // +0xc8 the graphics drawn from AS3

    bool          PointTestLocal(const PointF& pt, UInt8 hitTestMask) const;
    TopMostResult GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr);
    RectF         GetRectBounds(const Render::Matrix2F& t) const;
};

class Sfr34_AvmBitmapView : public DisplayObject
{
public:
    UByte               AvmPart[0x30];  // +0x90 AvmDisplayObj
    Ptr<ImageResource>  pImage;         // +0xc0

    bool PointTestLocal(const PointF& pt, UInt8 hitTestMask) const;
};

// The drawn graphics first, then the shape of the definition.
// @0x14251cac0
bool Sfr34_ShapeObjectView::PointTestLocal(const PointF& pt, UInt8 hitTestMask) const
{
    if (pDrawing && pDrawing->DefPointTestLocal(pt, (hitTestMask & HitTest_TestShape) != 0, this))
        return true;
    return pDef->DefPointTestLocal(pt, (hitTestMask & HitTest_TestShape) != 0, this);
}

// A shape is never the topmost entity itself: with drawn graphics a hit gives the parent, otherwise the
// definition's shape is searched.
// @0x14250f770
DisplayObjectBase::TopMostResult Sfr34_ShapeObjectView::GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr)
{
    if (pDrawing)
    {
        PointF p(PointF::NoInit);
        if (TransformPointToLocalAndCheckBounds(&p, pt, true, NULL) && pDrawing->DefPointTestLocal(p, true, this))
        {
            pdescr->pResult = GetParent();
            return TopMost_Found;
        }
    }
    else
    {
        pdescr->pResult = GetTopMostMouseEntityDef(pDef.GetPtr(), pt, pdescr->TestAll, pdescr->pIgnoreMC);
        if (pdescr->pResult)
            return TopMost_Continue;
    }
    return TopMost_FoundNothing;
}

// Inside the image's rect (in twips, from the origin).
// MS2-FUNCTIONAL member of a layout view (AvmBitmap is opaque in the shared header)
// @0x14251c9f0
bool Sfr34_AvmBitmapView::PointTestLocal(const PointF& pt, UInt8 hitTestMask) const
{
    SF_UNUSED(hitTestMask);
    if (!pImage)
        return false;
    Render::ImageRect r = pImage->GetImage()->GetRect();
    RectF bounds(0.0f);
    bounds.x2 = bounds.x1 + float(r.Width()) * 20.0f;
    bounds.y2 = bounds.y1 + float(r.Height()) * 20.0f;
    return bounds.Contains(pt);
}

} } } // namespace Scaleform::GFx::AS3

// AvmBitmap::RecreateRenderNode: the bitmap's AS3 image may have changed, so its render node is made again
// from the current image and put back where the old one was in the parent's children.
// MS2-FUNCTIONAL declared void by its caller (sfr_as3_07); the exe also returns the new render node in rax
// @0x142520b20
void FUN_142520b20(Scaleform::GFx::DisplayObject* pbitmap)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx;
    using namespace Scaleform::GFx::AS3;
    Sfr34_AvmBitmapView*           self   = static_cast<Sfr34_AvmBitmapView*>(pbitmap);
    Instances::fl_display::Bitmap* as3    = static_cast<Instances::fl_display::Bitmap*>(
        reinterpret_cast<const AvmDisplayObj*>(self->AvmPart)->GetAS3Obj());
    Render::TreeNode*              node   = self->pRenNode;
    Render::TreeContainer*         parent = NULL;
    UPInt                          index  = 0xFFFFFFFFu;
    if (as3)
    {
        if (node && node->GetParent())
        {
            Render::TreeContainer* p = static_cast<Render::TreeContainer*>(node->GetParent());
            p = p->IsMaskNode() ? NULL : p;
            UPInt n = p->GetSize();
            for (index = 0; index < n; ++index)
                if (p->GetAt(index) == node)
                    break;
            p->Remove(index, 1);
            parent = p;
        }
        ImageResource* img = as3->GetImageResource();
        if (img)
            self->pImage = img;
    }
    if (node)
    {
        Ptr<Render::TreeNode> old = self->pRenNode;
        self->pRenNode = self->CreateRenderNode(self->GetRenderContext());
        if (self->pRenNode)
        {
            if (old)
                self->pRenNode->CopyGeomData(*old);
            else
                self->pRenNode->SetVisible(self->IsVisibleFlagSet());
            if (parent)
                parent->Insert(index, self->pRenNode);
        }
    }
}

namespace Scaleform { namespace GFx { namespace AS3 {


// sfr34 batch G: unloading.

// An object past its unload depth only drops its unload state. A timeline child (not named by an instance) is
// taken off the parent's property of its name if that property still holds this object; the AS3 object is then
// kept raw (no longer collectible).
// MS2-FUNCTIONAL the exe inlines both Multiname(Namespace&, const Value&) constructions
// @0x142519200
void AvmDisplayObj::OnEventUnload()
{
    DisplayObject* dobj = pDispObj;
    if (dobj->Depth < -1)
    {
        if (dobj->IsUnloaded())
        {
            dobj->pParent = NULL;
            dobj = pDispObj;
        }
        dobj->DisplayObjectBase::Flags &= ~(DisplayObjectBase::Mask_Unloaded | DisplayObjectBase::Mask_Unloading);
        return;
    }
    if (!(dobj->DisplayObject::Flags & DisplayObject::Mask_InstanceBasedName) &&
        (dobj->DisplayObject::Flags & DisplayObject::Mask_TimelineObject) && GetAS3Parent())
    {
        AvmInteractiveObj*                    avmParent = GetAvmParent();
        Instances::fl_display::DisplayObject* parentObj = avmParent->GetAS3Obj();
        ASString                              name      = pDispObj->GetName();
        Value                                 v;
        {
            Multiname mn(AS3RootOf(pDispObj)->pAVM->GetPublicNamespace(), Value(name));
            parentObj->GetProperty(mn, v);
        }
        VM* vm = AS3RootOf(pDispObj)->pAVM;
        if (!vm->IsException())
        {
            if (!v.IsObject() || v.GetObject() != GetAS3Obj())
                goto done;
            {
                Multiname mn(AS3RootOf(pDispObj)->pAVM->GetPublicNamespace(), Value(name));
                parentObj->SetProperty(mn, Value::GetNull());
            }
            vm = AS3RootOf(pDispObj)->pAVM;
            if (!vm->IsException())
                goto done;
        }
        vm->OutputAndIgnoreException();
        avmParent->pDispObj->DisplayObject::Flags |= DisplayObject::Mask_ExecutionAborted;
    done:;
    }
    pAS3RawPtr = GetAS3Obj();
    reinterpret_cast<SPtr<Instances::fl_display::DisplayObject>&>(pAS3CollectiblePtr) = NULL;
}


// sfr34 batch H: the AS3 heap limit.

} } } // namespace Scaleform::GFx::AS3
void FUN_1424f03f0(Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit* self, Scaleform::MemoryHeap* heap);  // HeapLimit::Collect
namespace Scaleform { namespace GFx { namespace AS3 {

// The heap may grow by HeapLimitMultiplier of its footprint between collections. Past that (or past the user
// limit) the garbage is collected first: right away, or (inside an allocation) at the next frame.
// MS2-FUNCTIONAL same logic; the exe lays out the no-collection path first and allocates other registers
// @0x1425198d0
bool MemoryContextImpl::HeapLimit::OnExceedLimit(MemoryHeap* heap, UPInt overLimit)
{
    const UPInt footprint = heap->GetFootprint();
    const UPInt heapLimit = *reinterpret_cast<UPInt*>(reinterpret_cast<UByte*>(heap) + 0x60);
    const float growth    = float(footprint) * HeapLimitMultiplier;
    const UPInt newLimit  = UPInt(growth) + heapLimit + overLimit;
    UPInt       limit;
    if (SPInt(growth) > SPInt(footprint - LastCollectionFootprint) && (!UserLevelLimit || newLimit <= UserLevelLimit))
        limit = newLimit;
    else
    {
        if (AllocCount)
        {
            MemContext->ASGC->CollectionScheduledFlags = 1;
            return true;
        }
        FUN_1424f03f0(this, heap);
        if (!UserLevelLimit || newLimit <= UserLevelLimit)
            return true;
        if (overLimit > footprint - LastCollectionFootprint)
            CurrentLimit = limit = heapLimit + (LastCollectionFootprint - footprint) + overLimit;
        else
            limit = CurrentLimit;
    }
    heap->SetLimit(limit);
    CurrentLimit = *reinterpret_cast<UPInt*>(reinterpret_cast<UByte*>(heap) + 0x60);
    return true;
}


// sfr34 batch I: the interpreter's exception handlers.

} } } // namespace Scaleform::GFx::AS3
void FUN_1424efcd0(Scaleform::GFx::AS3::CallFrame* cf);    // CallFrame::ClearOpStack
void FUN_1424efd80(Scaleform::GFx::AS3::CallFrame* cf);    // CallFrame::ClearScopeStack
Scaleform::GFx::AS3::ClassTraits::Traits* FUN_142524f60(Scaleform::GFx::AS3::VM* vm, Scaleform::GFx::AS3::VMAbcFile* file,
                                                        const void* abc_multiname);   // VM::Resolve2ClassTraits

// VM::OnException: the handler of the frame's method body for the pending exception thrown at code offset. A
// handler covering offset catches it when it has no type or the exception's class is (or derives from, or
// implements) its type; the operand stack is then emptied down to the exception, the scope stack cleared, and the
// handler's code position returned. -1 (the exception stays pending) when no handler catches it.
// MS2-FUNCTIONAL a free function in place of the VM member (its caller in sfr_as3_19 declares it so)
// @0x142519a00
int FUN_142519a00(Scaleform::GFx::AS3::VM* vm, Scaleform::UPInt offset, void* frame)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    CallFrame&                             cf     = *static_cast<CallFrame*>(frame);
    int                                    result = -1;
    UPInt                                  index  = 0;
    const Abc::MethodBodyInfo::Exception&  e      = cf.pFile->GetException(cf.MBIIndex);
    while (e.FindExceptionInfo(offset, index))
    {
        const Abc::MethodBodyInfo::ExceptionInfo& info = e.info[index];
        bool caught = info.exc_type_ind == 0;
        if (!caught && !vm->ExceptionObj.IsUndefined())
        {
            const ClassTraits::Traits* tr = &vm->GetClassTraits(vm->ExceptionObj);
            vm->HandleException = false;
            const ClassTraits::Traits* et = FUN_142524f60(vm, cf.pFile,
                &cf.pFile->GetAbcFile().Const_Pool.GetMultiname(info.exc_type_ind));
            vm->HandleException = true;
            if (et)
            {
                for (; tr; tr = static_cast<const ClassTraits::Traits*>(tr->GetParent()))
                {
                    if (tr == et || tr->GetInstanceTraits().SupportsInterface(et->GetInstanceTraits()))
                    {
                        caught = true;
                        break;
                    }
                }
            }
        }
        if (caught)
        {
            FUN_1424efcd0(&cf);
            Value*& top = reinterpret_cast<Value**>(&vm->OpStack)[1];     // ValueStack::pCurrent
            new (++top) Value(vm->ExceptionObj);
            vm->ExceptionObj.Clean();
            FUN_1424efd80(&cf);
            result = info.target;
            break;
        }
        ++index;
    }
    vm->HandleException = result < 0;
    return result;
}

namespace Scaleform { namespace GFx { namespace AS3 {

// sfr34 batch J: the host side's array and display object access to AS3 values. The ObjectInterface subclass
// (AS3ValueObjectInterface, vftable 0x14317eff8) is sfr_as3_17's; the slots recovered here are members of a view
// over it.


class Sfr34_ValueObjIfc : public GFx::Value::ObjectInterface
{
public:
    MovieRoot* GetAS3Root() const { return static_cast<MovieRoot*>(pMovieRoot->pASMovieRoot); }

    bool PushBack(void* pdata, const GFx::Value& value);
    bool PopBack(void* pdata, GFx::Value* pval);
    bool RemoveElements(void* pdata, unsigned idx, int count);
    bool GetWorldMatrix(void* pdata, Render::Matrix2F* pmat) const;
    bool GetMatrix3D(void* pdata, Render::Matrix3F* pmat) const;
    bool GetText(void* pdata, GFx::Value* pval, bool isHtml) const;
    bool GetMember(void* pdata, const char* name, GFx::Value* pval, bool isdobj) const;
    bool HasMember(void* pdata, const char* name, bool isdobj) const;
    bool Invoke(void* pdata, GFx::Value* presult, const char* name, const GFx::Value* pargs, UPInt nargs, bool isdobj);
    bool InvokeClosure(void* pdata, UPInt dataAux, GFx::Value* presult, const GFx::Value* pargs, UPInt nargs);
    bool GotoAndPlay(void* pdata, unsigned frame, bool stop);
    bool GotoAndPlay(void* pdata, const char* frame, bool stop);
};

// Whether the AS3 object is a display object instance, and the display object it scripts.
static inline bool Sfr34_IsDisplayObject(void* pdata)
{
    const Traits& tr = static_cast<Object*>(pdata)->GetTraits();
    return (unsigned)(tr.GetTraitsType() - Traits_DisplayObject_Begin) <
               (unsigned)(Traits_DisplayObject_End - Traits_DisplayObject_Begin) &&
           tr.IsInstanceTraits();
}
static inline DisplayObject* Sfr34_DispObjOf(void* pdata)
{
    return static_cast<Instances::fl_display::DisplayObject*>(static_cast<Object*>(pdata))->pDispObj;
}

// @0x14251f780
bool Sfr34_ValueObjIfc::PushBack(void* pdata, const GFx::Value& value)
{
    MovieRoot* root = GetAS3Root();
    Value      v;
    root->GFxValue2ASValue(value, &v);
    static_cast<Instances::fl::Array*>(pdata)->SA.PushBack(v);
    return true;
}

// The last element (to pval when given) is removed; an empty array gives undefined.
// MS2-FUNCTIONAL member of a view over the AS3 value object interface (the class is sfr_as3_17's)
// @0x14251cbe0
bool Sfr34_ValueObjIfc::PopBack(void* pdata, GFx::Value* pval)
{
    SparseArray&     sa   = static_cast<Instances::fl::Array*>(pdata)->SA;
    const MovieRoot* root = GetAS3Root();
    const SInt32     size = SInt32(sa.GetSize());
    if (size <= 0)
    {
        if (pval)
            pval->SetUndefined();
        return false;
    }
    const UPInt last = UPInt(size - 1);
    if (pval)
        root->ASValue2GFxValue(sa.At(last), pval);
    sa.Resize(last);
    return true;
}

// count elements from idx (all of the rest when negative or past the end).
// @0x1425227e0
bool Sfr34_ValueObjIfc::RemoveElements(void* pdata, unsigned idx, int count)
{
    SparseArray&   sa   = static_cast<Instances::fl::Array*>(pdata)->SA;
    const unsigned size = unsigned(sa.GetSize());
    if (idx >= size)
        return false;
    if (count < 0)
        count = int(size - idx);
    const unsigned rest = size - idx;
    if (rest < unsigned(count))
        count = int(rest);
    sa.CutMultipleAt(idx, unsigned(count), NULL);
    return true;
}

// The world matrix, translation in pixels.
// @0x142510a70
bool Sfr34_ValueObjIfc::GetWorldMatrix(void* pdata, Render::Matrix2F* pmat) const
{
    Object*       pobj = static_cast<Object*>(pdata);
    const Traits& tr   = pobj->GetTraits();
    if ((unsigned)(tr.GetTraitsType() - Traits_DisplayObject_Begin) <
            (unsigned)(Traits_DisplayObject_End - Traits_DisplayObject_Begin) &&
        tr.IsInstanceTraits())
    {
        Render::Matrix2F m;
        static_cast<Instances::fl_display::DisplayObject*>(pobj)->pDispObj->GetWorldMatrix(&m);
        m.Tx() = TwipsToPixels(m.Tx());
        m.Ty() = TwipsToPixels(m.Ty());
        *pmat = m;
        return true;
    }
    return false;
}

// The 3D matrix, translation in pixels.
// @0x14250b3c0
bool Sfr34_ValueObjIfc::GetMatrix3D(void* pdata, Render::Matrix3F* pmat) const
{
    Object*       pobj = static_cast<Object*>(pdata);
    const Traits& tr   = pobj->GetTraits();
    if ((unsigned)(tr.GetTraitsType() - Traits_DisplayObject_Begin) <
            (unsigned)(Traits_DisplayObject_End - Traits_DisplayObject_Begin) &&
        tr.IsInstanceTraits())
    {
        Render::Matrix3F m = static_cast<Instances::fl_display::DisplayObject*>(pobj)->pDispObj->GetMatrix3D();
        m.M[0][3] = TwipsToPixels(m.M[0][3]);
        m.M[1][3] = TwipsToPixels(m.M[1][3]);
        m.M[2][3] = TwipsToPixels(m.M[2][3]);
        *pmat = m;
        return true;
    }
    return false;
}

// A text field's text directly; other display objects through their "text" / "htmlText" member.
// MS2-FUNCTIONAL member of a view over the AS3 value object interface (the class is sfr_as3_17's); the exe inlines Value(const ASString&), ours calls it (sfr_as3_15)
// @0x14250f110
bool Sfr34_ValueObjIfc::GetText(void* pdata, GFx::Value* pval, bool isHtml) const
{
    const MovieRoot* root = GetAS3Root();
    Object*          pobj = static_cast<Object*>(pdata);
    const Traits&    tr   = pobj->GetTraits();
    if ((unsigned)(tr.GetTraitsType() - Traits_DisplayObject_Begin) <
            (unsigned)(Traits_DisplayObject_End - Traits_DisplayObject_Begin) &&
        tr.IsInstanceTraits())
    {
        DisplayObject* dobj = static_cast<Instances::fl_display::DisplayObject*>(pobj)->pDispObj;
        if (dobj->GetType() == CharacterDef::TextField)
        {
            ASString str = reinterpret_cast<TextField*>(dobj)->GetText(isHtml);
            Value    v(str);
            root->ASValue2GFxValue(v, pval);
            return true;
        }
        return GetMember(pdata, isHtml ? "htmlText" : "text", pval, true);
    }
    return false;
}

// A sprite goes to the frame (1-based) and plays or stops; the frame's actions run right away.
// @0x142510b70
bool Sfr34_ValueObjIfc::GotoAndPlay(void* pdata, unsigned frame, bool stop)
{
    MovieRoot* root = GetAS3Root();
    if (Sfr34_IsDisplayObject(pdata) && Sfr34_DispObjOf(pdata)->IsSprite())
    {
        Sprite* spr = static_cast<Sprite*>(Sfr34_DispObjOf(pdata));
        spr->GotoFrame(frame - 1);
        spr->SetPlayState(PlayState(stop));
        static_cast<FrameCounter*>(static_cast<Stage*>(root->pStage)->FrameCounterObj.GetPtr())->QueueFrameActions();
        for (unsigned level = 0; level <= MovieRoot::AL_Frame; ++level)
            FUN_1424fa320(root, level);
        return true;
    }
    return false;
}

// The same for a frame label.
// @0x142510c30
bool Sfr34_ValueObjIfc::GotoAndPlay(void* pdata, const char* frame, bool stop)
{
    MovieRoot* root = GetAS3Root();
    if (Sfr34_IsDisplayObject(pdata) && Sfr34_DispObjOf(pdata)->IsSprite())
    {
        Sprite*  spr = static_cast<Sprite*>(Sfr34_DispObjOf(pdata));
        unsigned frameNum;
        if (spr->GetLabeledFrame(frame, &frameNum, true))
        {
            spr->GotoFrame(frameNum);
            spr->SetPlayState(PlayState(stop));
            static_cast<FrameCounter*>(static_cast<Stage*>(root->pStage)->FrameCounterObj.GetPtr())->QueueFrameActions();
            for (unsigned level = 0; level <= MovieRoot::AL_Frame; ++level)
                FUN_1424fa320(root, level);
            return true;
        }
    }
    return false;
}

// sfr34 batch K: the host's variable access through the movie root (Movie::GetVariable & co. of an AS3 movie),
// and the root's start.


// The AS3 value at the dotted path, converted for the host; undefined when nothing is there.
// @0x142510180
bool MovieRoot::GetVariable(GFx::Value* pval, const char* ppathToVar) const
{
    Value v;
    pval->SetUndefined();
    if (FUN_142506000(this, &v, ppathToVar))
    {
        ASValue2GFxValue(v, pval);
        return true;
    }
    return false;
}

// The length of the AS3 array at the path; 0 for anything else.
// @0x142510770
unsigned MovieRoot::GetVariableArraySize(const char* ppathToVar)
{
    Value v;
    if (FUN_142506000(this, &v, ppathToVar))
    {
        Object* pobj = v.GetObject();
        if (pobj && pobj->GetTraits().GetTraitsType() == Traits_Array && pobj->GetTraits().IsInstanceTraits())
            return unsigned(static_cast<Instances::fl::Array*>(pobj)->SA.GetSize());
    }
    return 0;
}

// Whether the path leads to a value.
// @0x142513f90
bool MovieRoot::IsAvailable(const char* ppathToVar) const
{
    Value v;
    return FUN_142506000(this, &v, ppathToVar);
}

// The VM and the stage (as _level0), then the video module's AS3 classes and the sticky variables set before.
// @0x142511530
bool MovieRoot::Init(MovieDefImpl* pmovieDef)
{
    Sfr34_CheckAvm(this);
    FUN_1424f4000(this, pmovieDef);
    pMovieImpl->SetLevelMovie(0, static_cast<DisplayObjContainer*>(pStage));
    Ptr<Video::VideoBase> pvideo = static_cast<StateBag&>(*pMovieImpl->pStateBag).GetVideo();
    if (pvideo && pvideo->GetAS3Support())
    {
        MovieRoot* proot = static_cast<MovieRoot*>(pMovieImpl->pASMovieRoot);
        pvideo->GetAS3Support()->RegisterASClasses(proot->pAVM);
    }
    // ResolveStickyVariables: vftable slot 30 (+0xf0)
    typedef void (*ResolveFn)(MovieRoot*, GFx::DisplayObject*);
    (*reinterpret_cast<ResolveFn const* const*>(this))[30](this, pStage);
    return true;
}

// sfr34 batch L: small VM and movie root helpers. Their callers in other units declare them as FUN_<va> free
// functions, so they are defined under those names (global scope).

} } } // namespace Scaleform::GFx::AS3

extern "C" const Scaleform::StringDataPtr DAT_143a2dd40;   // "scaleform.gfx", the namespace of the GFx extension classes

// MovieRoot::QueueFrameActions: the stage's frame counter queues the frame actions of the display list.
// @0x142520080
void FUN_142520080(Scaleform::GFx::AS3::MovieRoot* proot)
{
    using namespace Scaleform::GFx::AS3;
    static_cast<FrameCounter*>(static_cast<Stage*>(proot->pStage)->FrameCounterObj.GetPtr())->QueueFrameActions();
}

// MovieRoot::RemoveActionQueueEntriesFor: the actions queued at level for pdobj lose their character (they are
// skipped when they come up).
// @0x142522490
void FUN_142522490(Scaleform::GFx::AS3::MovieRoot* proot, int level, Scaleform::GFx::DisplayObject* pdobj)
{
    using namespace Scaleform::GFx::AS3;
    for (MovieRoot::ActionEntry* e = proot->ActionQueue.Entries[level].pActionRoot; e; e = e->pNextEntry)
        if (e->pCharacter == pdobj)
            e->pCharacter = NULL;
}

// ClassTraits::Traits::IsParentTypeOf: tr is other, one of its bases, or an interface one of them implements.
// @0x1425149a0
bool FUN_1425149a0(const Scaleform::GFx::AS3::ClassTraits::Traits& tr, const Scaleform::GFx::AS3::ClassTraits::Traits& other)
{
    using namespace Scaleform::GFx::AS3;
    if (&tr == &other)
        return true;
    for (const ClassTraits::Traits* cur = &other; cur;)
    {
        if (cur->GetInstanceTraits().SupportsInterface(tr.GetInstanceTraits()))
            return true;
        cur = static_cast<const ClassTraits::Traits*>(cur->GetParent());
        if (cur == &tr)
            return true;
    }
    return false;
}

// IsScaleformGFx: ns is "scaleform.gfx" or a namespace under it.
// @0x142514cd0
bool FUN_142514cd0(const Scaleform::GFx::AS3::Instances::Namespace& ns)
{
    const Scaleform::GFx::ASString& uri = ns.GetUri();
    return uri.GetSize() >= DAT_143a2dd40.GetSize() &&
           strncmp(uri.ToCStr(), DAT_143a2dd40.ToCStr(), DAT_143a2dd40.GetSize()) == 0;
}

// ASVM::GetResourceMovieDef: the movie of the ABC file that defines pobj's class; without one (a builtin class) the
// main movie.
// @0x14250d8f0
Scaleform::GFx::MovieDefImpl* FUN_14250d8f0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Instances::fl::Object* pobj)
{
    using namespace Scaleform::GFx;
    using namespace Scaleform::GFx::AS3;
    VMAbcFile* file = pobj->GetTraits().GetConstructor().GetTraits().GetFilePtr();
    if (file)
        return *reinterpret_cast<MovieDefImpl* const*>(reinterpret_cast<const Scaleform::UByte*>(&file->GetAbcFile()) + 0x188);
    return static_cast<ASVM&>(vm).GetMovieImpl()->pMainMovieDef;
}

// VM::GetValueTraits: the instance traits of v's type (the traits themselves for traits values).
// @0x14250ffc0
const Scaleform::GFx::AS3::Traits& FUN_14250ffc0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    // the Function class traits keep two more instance traits: +0xc8 for thunks, +0xe0 for method table entries
    switch (v.GetKind())
    {
    case Value::kBoolean:
        return vm.GetClassTraitsBoolean().GetInstanceTraits();
    case Value::kInt:
        return vm.GetClassTraitsSInt().GetInstanceTraits();
    case Value::kUInt:
        return vm.GetClassTraitsUInt().GetInstanceTraits();
    case Value::kNumber:
        return vm.GetClassTraitsNumber().GetInstanceTraits();
    case Value::kString:
        if (v.GetStringNode() == NULL)
            break;
        return vm.GetClassTraitsString().GetInstanceTraits();
    case Value::kNamespace:
        return vm.GetClassTraitsNamespace().GetInstanceTraits();
    case Value::kObject:
    case Value::kClass:
    case Value::kFunction:
    case Value::kThunkFunction:
        if (v.IsNull())
            break;
        return v.GetObject()->GetTraits();
    case Value::kThunk:
    case Value::kThunkClosure:
        return **reinterpret_cast<const Traits* const*>(reinterpret_cast<const UByte*>(vm.TraitsFunction.GetPtr()) + 0xc8);
    case Value::kVTableInd:
    case Value::kVTableIndClosure:
        return **reinterpret_cast<const Traits* const*>(reinterpret_cast<const UByte*>(vm.TraitsFunction.GetPtr()) + 0xe0);
    case Value::kInstanceTraits:
        return v.GetInstanceTraits();
    case Value::kClassTraits:
        return v.GetClassTraits();
    default:
        return vm.GetITraitsVoid();
    }
    return vm.GetClassTraitsObject().GetInstanceTraits();
}

namespace Scaleform { namespace GFx { namespace AS3 {

// sfr34 batch M: MovieRoot virtuals (4.1.18 vftable 0x14317d8d8). The exe's vftable keeps the slots, so the
// bodies are free functions taking the movie root.

} } } // namespace Scaleform::GFx::AS3

bool FUN_1424445f0(const Scaleform::GFx::AS3::Instances::fl_display::DisplayObject* pobj);  // DisplayObject::HasLoaderInfo

// MovieRoot::GetRootMovie (slot 14): the nearest display object up from dobj whose AS3 object has loader info,
// else the root of the stage dobj's movie sits on. When that is no container, its parent's root movie is
// taken instead. No dobj gives this stage's root.
// SDK AS3_MovieRoot.cpp form on the inlined AvmDisplayObj::GetRoot.
// MS2-FUNCTIONAL a slot of the exe's MovieRoot vftable, defined as a free function; one branch target as in GetRoot
// @0x14250daa0
Scaleform::GFx::DisplayObjContainer* FUN_14250daa0(const Scaleform::GFx::AS3::MovieRoot* self,
                                                   Scaleform::GFx::DisplayObject* dobj)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx;
    using namespace Scaleform::GFx::AS3;
    if (!dobj)
        return static_cast<Stage*>(self->pStage)->pRoot;
    else
    {
        DisplayObject* r = ToAvmDisplayObj(dobj)->GetRoot();
        if (!r)
            return static_cast<Stage*>(self->pStage)->pRoot;
        else
        {
            if (r->IsDisplayObjContainer())
                return static_cast<DisplayObjContainer*>(r);
            else
                return self->GetRootMovie418(r->GetParent());
        }
    }
}

namespace Scaleform { namespace GFx { namespace AS3 {

} } } // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace Render {
Text::Allocator* FUN_1424d61c0(Text::Allocator* self, MemoryHeap* pheap, UInt8 flags);  // the Allocator ctor (sfr_as3_15)
} }

// MovieRoot::GetTextAllocator: the movie heap's text allocator, made on first use.
// MS2-FUNCTIONAL a slot of the exe's MovieRoot vftable, defined as a free function
// @0x14250f290
Scaleform::Render::Text::Allocator* FUN_14250f290(Scaleform::GFx::AS3::MovieRoot* self)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    if (!self->MemContext->TextAllocator)
    {
        Render::Text::Allocator* mem = static_cast<Render::Text::Allocator*>(
            self->MemContext->Heap->Alloc(sizeof(Render::Text::Allocator), (const AllocInfo*)0));
        self->MemContext->TextAllocator = *(mem ? Render::FUN_1424d61c0(mem, self->MemContext->Heap, 0) : mem);
    }
    return self->MemContext->TextAllocator;
}

namespace Scaleform { namespace GFx { namespace AS3 {

} } } // namespace Scaleform::GFx::AS3

Scaleform::GFx::AS3::Value* FUN_142525400(const Scaleform::GFx::AS3::MovieRoot* proot, const char* pname);  // MovieRoot::ResolveInvokeAlias

// MovieRoot::Invoke with a format: InvokeArgs (slot 48) with the variable arguments.
// MS2-FUNCTIONAL a slot of the exe's MovieRoot vftable, defined as a free function
// @0x142513210
bool FUN_142513210(Scaleform::GFx::AS3::MovieRoot* self, const char* pmethodName, Scaleform::GFx::Value* presult,
                   const char* pargFmt, ...)
{
    using namespace Scaleform;
    typedef bool (*Fn)(GFx::AS3::MovieRoot*, const char*, GFx::Value*, const char*, va_list);
    va_list args;
    va_start(args, pargFmt);
    bool r = (*reinterpret_cast<Fn const* const*>(self))[48](self, pmethodName, presult, pargFmt, args);
    va_end(args);
    return r;
}

// MovieRoot::Invoke with host values: the invoke alias of pmethodName, else the function at that AS3 path, is
// called with pargs as AS3 values and its result goes to presult. False when there is none or the call throws
// (the exception is printed and dropped).
// MS2-FUNCTIONAL a slot of the exe's MovieRoot vftable, defined as a free function; the exe inlines the
// undefined value's static and the exception output
// @0x142513240
bool FUN_142513240(Scaleform::GFx::AS3::MovieRoot* self, const char* pmethodName, Scaleform::GFx::Value* presult,
                   const Scaleform::GFx::Value* pargs, unsigned numArgs)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    enum { NumValuesOnStack = 10 };
    void*  argArrayOnStack[NumValuesOnStack * ((sizeof(GFx::Value) + sizeof(void*)) / sizeof(void*))];
    Value* pargArray;
    if (numArgs > NumValuesOnStack)
        pargArray = static_cast<Value*>(SF_HEAP_AUTO_ALLOC(self, sizeof(Value) * numArgs));
    else
        pargArray = reinterpret_cast<Value*>(argArrayOnStack);
    for (unsigned i = 0, n = numArgs; i < n; ++i)
        self->GFxValue2ASValue(pargs[i], ::new (&pargArray[i]) Value());

    bool   retVal = true;
    Value* paliasFunc;
    Value  resultVal;
    if (self->pInvokeAliases && (paliasFunc = FUN_142525400(self, pmethodName)) != NULL)
        self->pAVM->ExecuteInternalUnsafe(*paliasFunc, Value::GetUndefined(), resultVal, numArgs, pargArray, false);
    else
    {
        Value resolvedVal;
        if (FUN_142506000(self, &resolvedVal, pmethodName))
            self->pAVM->ExecuteInternalUnsafe(resolvedVal, Value::GetUndefined(), resultVal, numArgs, pargArray, false);
        else
            retVal = false;
    }
    if (retVal)
    {
        retVal = !self->pAVM->IsException();
        if (self->pAVM->IsException())
        {
            self->pAVM->HandleException = false;
            self->pAVM->OutputError(self->pAVM->ExceptionObj);
            self->pAVM->ExceptionObj.SetUndefined();
        }
        else if (presult)
            self->ASValue2GFxValue(resultVal, presult);
    }

    for (unsigned i = 0, n = numArgs; i < n; ++i)
        pargArray[i].~Value();
    // as in the exe, the heap array is freed only past the stack array's word count
    if (numArgs > sizeof(argArrayOnStack) / sizeof(argArrayOnStack[0]))
        SF_FREE(pargArray);
    return retVal;
}

namespace Scaleform { namespace GFx { namespace AS3 {

} } } // namespace Scaleform::GFx::AS3

// MovieRoot::ParseValueArguments: the AS3 values of an Invoke format into arr. %d int, %u undefined, %n null,
// %b bool, %f or %hf number, %s or %ls string; spaces, tabs and commas between them are skipped and anything
// else is logged as a script error.
// MS2-FUNCTIONAL a member of the exe's MovieRoot, defined as a free function
// @0x14251c1c0
void FUN_14251c1c0(const Scaleform::GFx::AS3::MovieRoot* self, Scaleform::Array<Scaleform::GFx::AS3::Value>& arr,
                   const char* pmethodName, const char* pargFmt, va_list args)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    Ptr<GFx::LogState> plog = self->GetMovieImpl()->GetLogState();
    arr.Clear();
    if (!pargFmt)
        return;
    Value       arg;
    const char* p = pargFmt;
    while (*p)
    {
        char c = *p++;
        if (c == '%')
        {
            c = *p++;
            if (c == 'd')
            {
                arg.SetSInt32(va_arg(args, int));
                arr.PushBack(arg);
            }
            else if (c == 'u')
            {
                arg.SetUndefined();
                arr.PushBack(arg);
            }
            else if (c == 'n')
            {
                arg.SetNull();
                arr.PushBack(arg);
            }
            else if (c == 'b')
            {
                arg.SetBool(va_arg(args, int) != 0);
                arr.PushBack(arg);
            }
            else if (c == 'f')
            {
                arg.SetNumber(va_arg(args, double));
                arr.PushBack(arg);
            }
            else if (c == 'h')
            {
                // a float argument is promoted to double anyway
                c = *p++;
                if (c == 'f')
                {
                    arg.SetNumber(va_arg(args, double));
                    arr.PushBack(arg);
                }
                else if (plog)
                    plog->LogScriptError("ParseArguments('%s','%s') - invalid format '%%h%c'", pmethodName, pargFmt, c);
            }
            else if (c == 's')
                arr.PushBack(Value(self->BuiltinsMgr.CreateString(va_arg(args, const char*))));
            else if (c == 'l')
            {
                c = *p++;
                if (c == 's')
                    arr.PushBack(Value(GFx::ASString(self->BuiltinsMgr.GetStringManager()->CreateStringNode(
                        va_arg(args, const wchar_t*)))));
                else if (plog)
                    plog->LogScriptError("ParseArguments('%s','%s') - invalid format '%%l%c'", pmethodName, pargFmt, c);
            }
            else if (plog)
                plog->LogScriptError("ParseArguments('%s','%s') - invalid format '%%%c'", pmethodName, pargFmt, c);
        }
        else if (plog)
            plog->LogScriptError("ParseArguments('%s','%s') - invalid char '%c'", pmethodName, pargFmt, c);
        while (*p == ' ' || *p == '\t' || *p == ',')
            ++p;
    }
}

// MovieRoot::InvokeArgs: Invoke with the arguments of a format. A throwing call gives false; its exception is
// dropped without output.
// MS2-FUNCTIONAL a slot of the exe's MovieRoot vftable, defined as a free function
// @0x1425136f0
bool FUN_1425136f0(Scaleform::GFx::AS3::MovieRoot* self, const char* pmethodName, Scaleform::GFx::Value* presult,
                   const char* pargFmt, va_list args)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    Array<Value> argArray;
    FUN_14251c1c0(self, argArray, pmethodName, pargFmt, args);
    Value        resultVal;
    const Value* pargs = argArray.GetSize() ? &argArray[0] : NULL;
    Value*       paliasFunc;
    if (self->pInvokeAliases && (paliasFunc = FUN_142525400(self, pmethodName)) != NULL)
        self->pAVM->ExecuteInternalUnsafe(*paliasFunc, Value::GetUndefined(), resultVal, unsigned(argArray.GetSize()),
                                          pargs, false);
    else
    {
        Value resolvedVal;
        if (!FUN_142506000(self, &resolvedVal, pmethodName))
            return false;
        self->pAVM->ExecuteInternalUnsafe(resolvedVal, Value::GetUndefined(), resultVal, unsigned(argArray.GetSize()),
                                          pargs, false);
    }
    const bool retVal = !self->pAVM->IsException();
    if (self->pAVM->IsException())
        self->pAVM->HandleException = false;
    else if (presult)
        self->ASValue2GFxValue(resultVal, presult);
    return retVal;
}

namespace Scaleform { namespace GFx { namespace AS3 {

// sfr34 batch N: small members.

// @0x142519860
void AvmInteractiveObj::OnEventUnload()
{
    AvmDisplayObj::OnEventUnload();
}

// The instance's slots get the values of its traits.
// @0x14251cfd0
CheckResult Classes::UDBase::PreInit(const Value& _this) const
{
    return GetClassTraits().GetInstanceTraits().SetupSlotValues(*_this.GetObject());
}


// XMLSupport's makers of an empty node and list (no member of the shared header, so a view).
class Sfr34_XMLSupportView : public XMLSupport
{
public:
    Pickable<Instances::fl::XML>     MakeXML() const;
    Pickable<Instances::fl::XMLList> MakeXMLList() const;
};

// member of a view over XMLSupport; the node maker is an InstanceTraits::fl::XML member
// @0x142516900
Pickable<Instances::fl::XML> Sfr34_XMLSupportView::MakeXML() const
{
    InstanceTraits::Traits& itr = *GetITraitsXML();
    return static_cast<InstanceTraits::fl::XML&>(itr).FUN_14241ae30(itr);
}

// @0x142516930
Pickable<Instances::fl::XMLList> Sfr34_XMLSupportView::MakeXMLList() const
{
    InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(*GetITraitsXMLList());
    return itr.MakeInstance(itr);
}

// sfr34 batch O: out-of-line copies of inline members and the stage's mouse event.

// @0x142515160
bool FUN_142515160(const Render::Text::TextFormat* pthis)
{
    return pthis->IsUrlSet();
}

// Slots::GetSlotInfo of a traits object, one level inlined.
static SF_INLINE const SlotInfo& Sfr18TraitsSlotInfo(const Traits* pthis, AbsoluteIndex ind)
{
    const Slots& s = *pthis;
    if (ind < s.FirstOwnSlotNum)
        return s.Parent->GetSlotInfo(ind);
    return s.VArray[static_cast<UInt32>(ind.Get()) - s.FirstOwnSlotNum].Value;
}

// @0x14250dca0
__declspec(noinline) const SlotInfo& FUN_14250dca0(const Traits* pthis, AbsoluteIndex ind)
{
    return Sfr18TraitsSlotInfo(pthis, ind);
}

// Object::UserDataHolder (defined in sfr_as3_16; only declared in the shared header).
struct Sfr34_UserDataHolder
{
    Movie*      pMovieView; // +0x00
    ASUserData* pUserData;  // +0x08
};

// Object::UserDataHolder::NotifyDestroy: the user data drops its weak reference and hears that the object is gone.
// @0x142518420
void FUN_142518420(const Sfr34_UserDataHolder* pthis, Object* pobj)
{
    if (pthis->pUserData)
    {
        ASUserData_SetLastObjectValue(pthis->pUserData, 0, 0, false);
        pthis->pUserData->OnDestroy(pthis->pMovieView, pobj);
    }
}

// Stage: a mouse move drags what is being dragged.
// @0x14251f570
void Stage::PropagateMouseEvent(const EventId& id)
{
    Ptr<Stage> hold = this;
    if (id.Id == EventId::Event_MouseMove && GetMovieImpl()->IsMouseSupportEnabled())
        DoMouseDrag();
}

} } } // namespace Scaleform::GFx::AS3

// Abc::TraitInfo: the multiname of a slot's or constant's type, or of a class trait's class (the any type for 0).
// MS2-FUNCTIONAL declared over void pointers by its caller (sfr_as3_17)
// @0x14250f8a0
const Scaleform::GFx::AS3::Abc::Multiname& FUN_14250f8a0(const void* amn, const void* abc)
{
    using namespace Scaleform::GFx::AS3::Abc;
    const TraitInfo& t    = *static_cast<const TraitInfo*>(amn);
    const File&      file = *static_cast<const File*>(abc);
    SInd             ind;
    if (t.GetType() == TraitInfo::tSlot || t.GetType() == TraitInfo::tConst)
        ind = t.Ind;
    else
        ind = file.AS3_Classes.Info[t.Ind]->inst_info.name_ind;
    return file.Const_Pool.GetMultiname(ind);
}

namespace Scaleform { namespace GFx { namespace AS3 {

// sfr34 batch P: small out-of-line copies and the shape's rect bounds.

// The out-of-line copy of DisplayObjectBase::Is3D (the inline in gfx_rendertree.h).
// @0x142513e50
bool FUN_142513e50(const DisplayObjectBase* pobj)
{
    return pobj->Is3D();
}

// The definition's rect bounds through t.
// MS2-FUNCTIONAL member of a layout view; the exe's definition slot takes no float argument (no xmm2 zeroing)
// @0x14250d700
RectF Sfr34_ShapeObjectView::GetRectBounds(const Render::Matrix2F& t) const
{
    return t.EncloseTransform(pDef->GetRectBoundsLocal());
}

// Whether other is self or derives from it or implements it: up other's parents, each asked whether it supports
// self as an interface.
// No caller or reference is left in the exe, so it is a free function over the instance traits.
// @0x142514a10
bool FUN_142514a10(const InstanceTraits::Traits* self, const InstanceTraits::Traits* other)
{
    if (self == other)
        return true;
    for (const InstanceTraits::Traits* cur = other; cur;)
    {
        if (cur->SupportsInterface(*self))
            return true;
        cur = static_cast<const InstanceTraits::Traits*>(cur->GetParent());
        if (cur == self)
            return true;
    }
    return false;
}

} } } // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx {
// @0x142516210
template void LogBase<DisplayObjectBase>::LogError(const char* pfmt, ...) const;
} } // namespace Scaleform::GFx

namespace Scaleform { namespace GFx { namespace AS3 {

// sfr34 batch Q: VM class registry and weak file list, slot iteration and types, focus changes, and the
// number output helpers.

// MS2-FUNCTIONAL the exe calls MultinameHash::Add out of line (sfr_as3_16z FUN_1424e5e80, which takes the value by value; the exe's takes const T&); here it is inlined
// @0x1425210e0
void VM::RegisterClassTraits(ClassTraits::Traits& tr)
{
    InstanceTraits::Traits& itr = tr.GetInstanceTraits();
    ClassTraitsSet.Add(itr.GetName(), itr.GetNamespace(), &tr);
}

// InstanceTraits::Traits::IsParentTypeOf in the SDK form, inline here.
static SF_INLINE bool Sfr18IsParentTypeOf(const InstanceTraits::Traits& self, const InstanceTraits::Traits& other)
{
    if (&self == &other)
        return true;
    const InstanceTraits::Traits* tr = &other;
    while (tr)
    {
        if (tr->SupportsInterface(self))
            return true;
        tr = static_cast<const InstanceTraits::Traits*>(tr->GetParent());
        if (tr == &self)
            return true;
    }
    return false;
}

// Whether cur or one of its parents is t or supports t as an interface.
// No caller or reference is left in the exe, so a free function (cur->IsOfType(*t)).
// @0x142514560
bool FUN_142514560(const InstanceTraits::Traits* cur, const InstanceTraits::Traits* t)
{
    return Sfr18IsParentTypeOf(*t, *cur);
}

const SlotInfo& FUN_14250dca0(const Traits* pthis, AbsoluteIndex ind);
ClassTraits::Traits* FUN_1425085b0(const SlotInfo* psi, VM* pvm);  // SlotInfo::GetDataType (sfr_as3_17)

// The declared type of the slot with the 1-based own index ind.
// MS2-FUNCTIONAL no caller or reference is left in the exe, so a free function; the exe keeps the parent test in a flag
// @0x14250dc30
ClassTraits::Traits* FUN_14250dc30(const Traits* pthis, UInt32 ind)
{
    const AbsoluteIndex abs(SPInt(UPInt(ind) - 1 + UInt32(pthis->FirstOwnSlotInd.Get())));
    const SlotInfo& si = Sfr18TraitsSlotInfo(pthis, abs);
    return FUN_1425085b0(&si, &pthis->GetVM());
}

// The 1-based index of the next enumerable slot after ind; 0 past the last.
class Sfr34_TraitsView : public Traits
{
public:
    GlobalSlotIndex GetNextSlotIndex(GlobalSlotIndex ind) const;
};

// MS2-FUNCTIONAL member of a view over Traits (no caller or reference is left in the exe); i and its copy swap registers
// @0x14250bf90
GlobalSlotIndex Sfr34_TraitsView::GetNextSlotIndex(GlobalSlotIndex ind) const
{
    const UPInt num = GetSlotInfoNum();
    UInt32      i   = ind.Get();
    do
    {
        if (i >= num)
            return GlobalSlotIndex(0);
        ++i;
    } while (FUN_14250dca0(this, AbsoluteIndex(SPInt(i) - 1)).IsDontEnum());
    return GlobalSlotIndex(i);
}

namespace fl_vec { extern const char* NS_Vector; }

// The name of tr's type for messages: the plain name for the Vector types, the qualified one otherwise.
// No caller is recovered yet, so it is a free function over the traits.
// @0x14250bc60
ASString FUN_14250bc60(const Traits& tr)
{
    const InstanceTraits::Traits& itr = tr.IsClassTraits()
                                            ? static_cast<const ClassTraits::Traits&>(tr).GetInstanceTraits()
                                            : static_cast<const InstanceTraits::Traits&>(tr);
    if (strcmp(itr.GetNamespace().GetUri().ToCStr(), fl_vec::NS_Vector) == 0)
        return tr.GetName();
    return tr.GetQualifiedName();
}

// MovieRoot::NotifyOnFocusChange (no current focus means the stage).
// MS2-FUNCTIONAL a slot of the exe's MovieRoot vftable, defined as a free function
// @0x142518480
bool FUN_142518480(const MovieRoot* proot, InteractiveObject* curFocused, InteractiveObject* toBeFocused,
                   unsigned controllerIdx, FocusMovedType fmt, ProcessFocusKeyInfo* pfocusKeyInfo)
{
    AvmInteractiveObj* avm = curFocused ? ToAvmInteractiveObj(curFocused)
                                        : ToAvmInteractiveObj(static_cast<InteractiveObject*>(proot->pStage));
    return avm->OnFocusChange(toBeFocused, controllerIdx, fmt, pfocusKeyInfo);
}

// A number to the UI's action output.
// No caller is recovered yet, so these are free functions over the UI.
// @0x14251b110
void FUN_14251b110(FlashUI* ui, double v)
{
    DoubleFormatter f(v);
    f.Convert();
    ui->Output(FlashUI::Output_Action, f.ToCStr());
}

// @0x14251b190
void FUN_14251b190(FlashUI* ui, SInt64 v)
{
    LongFormatter f(v);
    f.Convert();
    ui->Output(FlashUI::Output_Action, f.ToCStr());
}

} } } // namespace Scaleform::GFx::AS3

// VM::RemoveVMAbcFileWeak: forgets file unless the VM is being destroyed.
// MS2-FUNCTIONAL declared over a void pointer by its caller (sfr_as3_15)
// @0x142522a60
bool FUN_142522a60(Scaleform::GFx::AS3::VM* vm, void* file)
{
    if (vm->InDestructor)
        return false;
    for (Scaleform::UPInt i = 0; i < vm->VMAbcFilesWeak.GetSize(); ++i)
        if (vm->VMAbcFilesWeak[i] == file)
        {
            vm->VMAbcFilesWeak.RemoveAt(i);
            return true;
        }
    return false;
}

namespace Scaleform { namespace Render {
// @0x14250dbc0
UPInt TreeContainer::GetSize() const
{
    return GetReadOnlyData()->Children.GetSize();
}
} } // namespace Scaleform::Render

namespace Scaleform { namespace GFx { namespace AS3 {

// sfr34 batch R: the verbose output of VM values to the UI (values, unsigned numbers, value arrays, the operand
// stack and the register file), and the validity test of a 2D matrix.

const char* FUN_1424ed700(Abc::NamespaceKind kind);    // the name of a namespace kind

void FUN_14251b350(const VM* vm, FlashUI* ui, const Value* v);

// An unsigned number (hexadecimal when asked) to the UI's action output.
// @0x14251b210
void FUN_14251b210(FlashUI* ui, UInt64 v, bool asHex)
{
    LongFormatter f(v);
    if (asHex)
        f.SetBase(16);
    f.Convert();
    ui->Output(FlashUI::Output_Action, f.ToCStr());
}

// The elements of values from index from on, separated by commas.
// @0x14251b2b0
void FUN_14251b2b0(const VM* vm, FlashUI* ui, const ArrayDH<Value>* values, UPInt from)
{
    const UPInt size = values->GetSize();
    for (UPInt i = from; i < size; ++i)
    {
        if (i > from)
            ui->Output(FlashUI::Output_Action, ", ");
        FUN_14251b350(vm, ui, &(*values)[i]);
    }
}

// The values of the operand stack, bottom first.
// MS2-FUNCTIONAL the operand stack's positions are read through a layout view (they are private to it)
// @0x14251bbc0
void FUN_14251bbc0(const VM* vm, FlashUI* ui, const ValueStack* values)
{
    struct View { UInt16 ReservedNum; Value* pCurrent; Value* pStack; };
    const View*  s     = reinterpret_cast<const View*>(values);
    const Value* last  = s->pCurrent;
    const Value* first = s->pStack;
    for (const Value* p = first; p <= last; ++p)
    {
        if (p > first)
            ui->Output(FlashUI::Output_Action, ", ");
        FUN_14251b350(vm, ui, p);
    }
}

// The registers of the innermost call frame.
// MS2-FUNCTIONAL the register file's positions are read through a layout view (they are private to it)
// @0x14251bb20
void FUN_14251bb20(const VM* vm, FlashUI* ui, const ValueRegisterFile* values)
{
    struct View { UInt16 Reserved; UInt16 Unk02; UInt16 Unk04; Value* pRF; ValueRegisterFile::Page* pCurrentPage; };
    const View*  rf   = reinterpret_cast<const View*>(values);
    const UInt16 size = UInt16(rf->Reserved - UInt16(rf->pRF - rf->pCurrentPage->Values));
    for (UInt16 i = 0; i < size; ++i)
    {
        if (i > 0)
            ui->Output(FlashUI::Output_Action, ", ");
        FUN_14251b350(vm, ui, rf->pRF + i);
    }
}

// The name of the traits of obj, to the UI.
static inline void Sfr34_OutputTraitsName(FlashUI* ui, const Traits& tr)
{
    ui->Output(FlashUI::Output_Action, tr.GetName().ToCStr());
}

// One value: its kind's text form, references with their addresses.
// MS2-FUNCTIONAL the switch is laid out by the compiler; the number case inlines its formatter
// @0x14251b350
void FUN_14251b350(const VM* vm, FlashUI* ui, const Value* v)
{
    const Value& value = *v;
    switch (value.GetKind())
    {
    case Value::kUndefined:
        ui->Output(FlashUI::Output_Action, "undefined");
        break;
    case Value::kBoolean:
        ui->Output(FlashUI::Output_Action, value.AsBool() ? "true" : "false");
        break;
    case Value::kInt:
        FUN_14251b190(ui, SInt64(value.AsInt()));
        break;
    case Value::kUInt:
        FUN_14251b210(ui, UInt64(value.AsUInt()), false);
        break;
    case Value::kNumber:
        if (value.IsNaN())
            ui->Output(FlashUI::Output_Action, "NaN");
        else if (value.IsPOSITIVE_ZERO())
            ui->Output(FlashUI::Output_Action, "+0");
        else if (value.IsNEGATIVE_ZERO())
            ui->Output(FlashUI::Output_Action, "-0");
        else if (value.IsPOSITIVE_INFINITY())
            ui->Output(FlashUI::Output_Action, "+Infinity");
        else if (value.IsNEGATIVE_INFINITY())
            ui->Output(FlashUI::Output_Action, "-Infinity");
        else
        {
            DoubleFormatter f(value.AsNumber());
            f.Convert();
            ui->Output(FlashUI::Output_Action, f.ToCStr());
        }
        break;
    case Value::kThunk:
        ui->Output(FlashUI::Output_Action, "thunk@");
        FUN_14251b210(ui, UInt64(&value.AsThunk()), true);
        break;
    case Value::kVTableInd:
        ui->Output(FlashUI::Output_Action, "VTable ind: ");
        FUN_14251b190(ui, SInt64(value.GetVTableInd()));
        break;
    case Value::kInstanceTraits:
    {
        InstanceTraits::Traits& itr = value.GetInstanceTraits();
        if (&itr == &vm->GetITraitsVoid())
            ui->Output(FlashUI::Output_Action, "void");
        else if (&itr == &vm->GetITraitsNull())
            ui->Output(FlashUI::Output_Action, "null");
        else
        {
            switch (value.GetTraceNullType())
            {
            case Value::NotNull:   ui->Output(FlashUI::Output_Action, "nnull:"); break;
            case Value::Null:      ui->Output(FlashUI::Output_Action, "null:"); break;
            case Value::NullOrNot: ui->Output(FlashUI::Output_Action, "nullon:"); break;
            }
            Sfr34_OutputTraitsName(ui, itr);
            ui->Output(FlashUI::Output_Action, "$");
        }
        break;
    }
    case Value::kClassTraits:
        Sfr34_OutputTraitsName(ui, value.GetClassTraits());
        ui->Output(FlashUI::Output_Action, "$$");
        break;
    case Value::kString:
        if (value.GetStringNode())
        {
            ui->Output(FlashUI::Output_Action, "\"");
            ui->Output(FlashUI::Output_Action, value.AsString().ToCStr());
            ui->Output(FlashUI::Output_Action, "\"");
        }
        else
            ui->Output(FlashUI::Output_Action, "null");
        break;
    case Value::kNamespace:
    {
        const Instances::Namespace& ns = value.AsNamespace();
        ui->Output(FlashUI::Output_Action, FUN_1424ed700(ns.GetKind()));
        if (!ns.GetUri().IsEmpty())
        {
            ui->Output(FlashUI::Output_Action, " ");
            ui->Output(FlashUI::Output_Action, ns.GetUri().ToCStr());
        }
        break;
    }
    case Value::kObject:
        if (value.IsNull())
            ui->Output(FlashUI::Output_Action, "null");
        else
        {
            const Object* obj = value.GetObject();
            const Traits& tr  = obj->GetTraits();
            if (!tr.IsGlobal())
            {
                Sfr34_OutputTraitsName(ui, tr);
                ui->Output(FlashUI::Output_Action, "@");
                FUN_14251b210(ui, UInt64(obj), true);
            }
            else if (obj == vm->GlobalObject.GetPtr())
                ui->Output(FlashUI::Output_Action, "globalCPP");
            else
            {
                // the global object of a script: its method index and the file name of its ABC source
                const InstanceTraits::fl::GlobalObjectScript& str =
                    static_cast<const InstanceTraits::fl::GlobalObjectScript&>(tr);
                const Abc::ScriptInfo& si = str.GetScript();
                const String&          src = str.GetFile().GetAbcFile().Source;
                const StringDataPtr    fn(src.ToCStr(), src.GetSize());
                ui->Output(FlashUI::Output_Action, "script_");
                LongFormatter f(si.method_info_ind);
                f.Convert();
                ui->Output(FlashUI::Output_Action, f.GetResult().ToCStr());
                ui->Output(FlashUI::Output_Action, "@");
                SPInt pos = fn.FindLastChar('\\');
                if (pos < 0)
                    pos = fn.FindLastChar('/');
                ++pos;
                ui->Output(FlashUI::Output_Action, fn.GetTrimLeft(UPInt(pos)).ToCStr());
            }
        }
        break;
    case Value::kClass:
        if (value.GetObject())
        {
            Sfr34_OutputTraitsName(ui, value.GetObject()->GetTraits());
            ui->Output(FlashUI::Output_Action, "$$");
        }
        else
            ui->Output(FlashUI::Output_Action, "null");
        break;
    case Value::kFunction:
        if (value.IsNull())
            ui->Output(FlashUI::Output_Action, "null");
        else
        {
            ui->Output(FlashUI::Output_Action, "function@");
            FUN_14251b210(ui, UInt64(value.GetObject()), true);
        }
        break;
    case Value::kThunkFunction:
        if (value.IsNull())
            ui->Output(FlashUI::Output_Action, "null");
        else
        {
            ui->Output(FlashUI::Output_Action, "thunk function@");
            Sfr34_OutputTraitsName(ui, value.GetObject()->GetTraits());
            FUN_14251b210(ui, UInt64(value.GetObject()), true);
        }
        break;
    case Value::kThunkClosure:
        if (value.GetClosure())
        {
            ui->Output(FlashUI::Output_Action, "ThunkClosure@");
            Sfr34_OutputTraitsName(ui, value.GetClosure()->GetTraits());
            ui->Output(FlashUI::Output_Action, "@");
            FUN_14251b210(ui, UInt64(value.GetClosure()), true);
            ui->Output(FlashUI::Output_Action, "@");
            FUN_14251b210(ui, UInt64(&value.AsThunk()), true);
        }
        else
            ui->Output(FlashUI::Output_Action, "null");
        break;
    case Value::kVTableIndClosure:
        if (value.GetClosure())
        {
            ui->Output(FlashUI::Output_Action, "VTableIndClosure@");
            Sfr34_OutputTraitsName(ui, value.GetClosure()->GetTraits());
            ui->Output(FlashUI::Output_Action, "@");
            FUN_14251b210(ui, UInt64(value.GetClosure()), true);
            ui->Output(FlashUI::Output_Action, "@");
            FUN_14251b210(ui, UInt64(SInt64(value.GetVTableInd())), true);
        }
        else
            ui->Output(FlashUI::Output_Action, "null");
        break;
    default:
        break;
    }
}

} } } // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace Render {

// All eight elements in the float range (none NaN or infinite).
template<class T>
bool Matrix2x4<T>::IsValid() const
{
    return M[0][0] >= -FLT_MAX && M[0][0] <= FLT_MAX && M[0][1] >= -FLT_MAX && M[0][1] <= FLT_MAX &&
           M[0][2] >= -FLT_MAX && M[0][2] <= FLT_MAX && M[0][3] >= -FLT_MAX && M[0][3] <= FLT_MAX &&
           M[1][0] >= -FLT_MAX && M[1][0] <= FLT_MAX && M[1][1] >= -FLT_MAX && M[1][1] <= FLT_MAX &&
           M[1][2] >= -FLT_MAX && M[1][2] <= FLT_MAX && M[1][3] >= -FLT_MAX && M[1][3] <= FLT_MAX;
}

// @0x142515710
template bool Matrix2x4<float>::IsValid() const;

} } // namespace Scaleform::Render

namespace Scaleform { namespace GFx { namespace AS3 {

// sfr34 batch S: the VM's namespace maker and the slots every class object has (the Object class methods and the
// class's own prototype methods).

} } } // namespace Scaleform::GFx::AS3

extern const Scaleform::GFx::AS3::ThunkInfo DAT_143a2d5c0[3];   // the Object methods of a class object
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14317aeb0[3];   // the methods of a class object itself

namespace Scaleform { namespace GFx { namespace AS3 {


// A namespace instance of the namespace class (not interned).
// MS2-FUNCTIONAL the exe inlines InstanceTraits::fl::Namespace::MakeInstance (the Namespace constructor is protected)
// @0x1425164c0
Pickable<Instances::Namespace> VM::MakeNamespace(Abc::NamespaceKind kind, const ASString& uri, const Value& prefix) const
{
    InstanceTraits::fl::Namespace& itr =
        static_cast<InstanceTraits::fl::Namespace&>(GetClassTraitsNamespace().GetInstanceTraits());
    return itr.MakeInstance(kind, uri, prefix);
}

// MS2-FUNCTIONAL the anonymous class info only has its names set
// @0x1425216d0
void ClassTraits::Traits::RegisterSlots()
{
    for (unsigned i = 0; i < 3; ++i)
        Add2VT(AS3::fl::ObjectCI, DAT_143a2d5c0[i]);
    ClassInfo ci;
    ci.Name    = "";
    ci.PkgName = "";
    for (unsigned i = 0; i < 3; ++i)
        Add2VT(ci, DAT_14317aeb0[i]);
    FirstOwnSlotInd = AbsoluteIndex(FirstOwnSlotInd.Get() + 6);
}

// sfr34 batch T: the root of an AS3 display object, the text field change/scroll events, the binary load of a
// URLLoader, and small helpers (resource handle lookup, operand stack unwinding, class traits by multiname).

// The nearest display object up from this one whose AS3 object has loader info, else the root of the stage.
// SDK AS3_AvmDisplayObj.cpp loop (GetAvmParent inlined); not found gives the stage's root.
// MS2-FUNCTIONAL one branch target: the exe leaves the loop straight from a NULL parent
// @0x14250d990
DisplayObject* AvmDisplayObj::GetRoot()
{
    AvmDisplayObj* cur = this;
    while (cur && (!cur->GetAS3Obj() || !FUN_1424445f0(cur->GetAS3Obj())))
    {
        AvmInteractiveObj* parent = ToAvmInteractiveObj(cur->pDispObj->GetParent());
        cur = parent;
    }
    if (cur)
    {
        return cur->pDispObj;
    }
    return static_cast<Stage*>(AS3RootOf(pDispObj)->pStage)->pRoot;
}

// A "change" (or "scroll") event to the AS3 object of a text field when it listens for one. self is the
// AvmTextFieldBase part (+0x40) of the AS3 text field.
static inline void Sfr34_TextFieldNotify(UPInt self, BuiltinType type)
{
    const AvmDisplayObj*                  avm  = reinterpret_cast<const AvmDisplayObj*>(self - 0x40);
    Instances::fl_display::DisplayObject* obj  = avm->GetAS3Obj();
    MovieRoot*                            root = AS3RootOf(avm->pDispObj);
    if (obj && obj->HasEventHandler(root->BuiltinsMgr.GetBuiltin(type), false))
    {
        SPtr<Instances::fl_events::Event> evt = obj->CreateEventObject(root->BuiltinsMgr.GetBuiltin(type), true, false);
        FUN_14243d870(&evt->Target, obj);
        obj->DispatchEventObject(evt, avm->pDispObj);
    }
}

// AvmTextField::NotifyChanged.
// MS2-FUNCTIONAL free function on the subobject this (AvmTextField is opaque in the shared header)
// @0x142518360
void FUN_142518360(UPInt self)
{
    Sfr34_TextFieldNotify(self, AS3Builtin_change);
}

// AvmTextField::OnScroll.
// MS2-FUNCTIONAL free function on the subobject this (AvmTextField is opaque in the shared header)
// @0x14251ae60
void FUN_14251ae60(UPInt self)
{
    Sfr34_TextFieldNotify(self, AS3Builtin_scroll);
}

// The data of a URLLoader's binary load, and its open/progress/complete events; a failed load gives the error
// event.
// MS2-FUNCTIONAL a 4.1.18 virtual of the root, defined non-virtual
// @0x14251e4b0
void MovieRoot::ProcessLoadBinaryMT(GFx::LoadQueueEntry* pentry, LoadStates* pls, const ArrayPOD<UByte>& data,
                                    UPInt fileLen, bool succeeded)
{
    SF_UNUSED(pls);
    AS3::LoadQueueEntry* entry = static_cast<AS3::LoadQueueEntry*>(pentry);
    if (!succeeded)
    {
        char buf[1024];
        SFsprintf(buf, sizeof(buf), "Can't open %s", entry->mURLRequest->GetUrl().ToCStr());
        entry->mURLLoader->ExecuteErrorEvent(buf);
        return;
    }
    entry->mURLLoader->SetBinaryData(data);
    entry->mURLLoader->ExecuteOpenEvent();
    entry->mURLLoader->ExecuteProgressEvent(UInt32(fileLen), UInt32(fileLen));
    entry->mURLLoader->ExecuteCompleteEvent();
}

ClassTraits::Traits** FUN_142505aa0(TClassTraitsCache* cache, const Multiname& mn);   // MultinameHash::Get

// The class traits of the class mn names: Class for the any type, else from the VM's class traits cache.
// SDK AS3_VM.cpp form with Multiname::IsAnyType inlined.
// @0x14250d760
const ClassTraits::Traits* FUN_14250d760(VM& vm, const Multiname& mn)
{
    const ClassTraits::Traits* result;
    if (mn.Name.IsNullOrUndefined() || (mn.Name.IsString() && mn.Name.AsString().IsEmpty()))
        result = vm.TraitsClassClass;
    else
    {
        ClassTraits::Traits** pptraits = FUN_142505aa0(&vm.ClassTraitsSet, mn);
        result = pptraits ? *pptraits : NULL;
    }
    return result;
}

// The values of the operand stack above to are destroyed, down to the start of its current page.
// MS2-FUNCTIONAL the operand stack's positions are read through a layout view (they are private to it)
// @0x14251ce20
void FUN_14251ce20(ValueStack* stack, Value* to)
{
    struct View { UInt16 ReservedNum; Value* pCurrent; Value* pStack; ValueStack::Page* pCurrentPage; };
    View* s = reinterpret_cast<View*>(stack);
    while (s->pCurrent > to && s->pCurrent >= s->pCurrentPage->Values)
    {
        s->pCurrent->~Value();
        --s->pCurrent;
    }
}

} } } // namespace Scaleform::GFx::AS3

// ResourceHandle::GetResource, an out-of-line copy of the inline.
// MS2-FUNCTIONAL free function (the inline is defined in gfx_moviedef.h)
// @0x14250d840
Scaleform::GFx::Resource* FUN_14250d840(const Scaleform::GFx::ResourceHandle* self,
                                        Scaleform::GFx::ResourceBinding* pbinding)
{
    return self->GetResource(pbinding);
}

namespace Scaleform {
// ArrayDataBase<UByte, AllocatorGH_POD<UByte, 2>>::Reserve.
// @0x142522d10
template void ArrayDataBase<UByte, AllocatorGH_POD<UByte, 2>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
} // namespace Scaleform

namespace Scaleform { namespace GFx { namespace AS3 {

// sfr34 batch U: methods of a VTable as closures, the text form of a function's name (thunks and VTable methods),
// the canonical form of a run-time name, and the loading of an ABC file into the VM.

namespace fl { extern const char* NS_AS3; extern const char* NS_flash_proxy; }

// A closure value (kind with payload p1 and closure object obj, which gains a reference), built through a layout
// view: Value's closure constructors call the out-of-line AddRefClosure, which the exe expands inline everywhere.
static inline Value Sfr34_Closure(UInt32 kind, const void* p1, Object* obj)
{
    struct Raw { UInt32 Flags; void* Bonus; const void* P1; Object* P2; };
    const Raw r = { kind, NULL, p1, obj };
    if (obj)
        obj->AddRef();
    return Value(*reinterpret_cast<const Value*>(&r), Value::NotRefCounted);
}

// VTable::GetMethod: method slot ind of obj's traits as a value: a thunk becomes a thunk closure of obj, a method
// index a VTable index closure of obj; other slots are copied.
// MS2-FUNCTIONAL free function (the member is not declared in the shared VTable class); SDK form, the exe tail-calls the
// temporary closure's release (jmp vs our call/ret)
// @0x14250ba10
void FUN_14250ba10(const VTable* vt, Value& result, AbsoluteIndex ind, Object* obj)
{
    const Value& m = vt->VTMethods[ind.Get()];
    switch (m.GetKind())
    {
    case Value::kThunk:
        result.Assign(Value(obj, m.AsThunk()));
        return;
    case Value::kMethodInd:
        result.Assign(Value(obj, static_cast<SInt32>(ind.Get())));
        return;
    default:
        break;
    }
    result.Assign(m);
}

// The name of a thunk: "Function " (or "MethodClosure " for a closure), the owner's name with "/" and, for a
// closure, its namespace (AS3 and flash_proxy by their short names; none for the Vector one), then "name()".
// MS2-FUNCTIONAL free function (debug name helper with no declaration in the shared headers)
// @0x14250f330
ASString FUN_14250f330(ASString name, const ThunkInfo& ti, bool closure)
{
    if (!name.IsEmpty())
    {
        name.Append("/", 1);
        const char* ns = ti.NamespaceName;
        if (closure && ns && *ns && strcmp(ns, fl_vec::NS_Vector) != 0)
        {
            if (strcmp(ns, fl::NS_AS3) == 0)
                name.Append("AS3", 3);
            else if (strcmp(ns, fl::NS_flash_proxy) == 0)
                name.Append("flash_proxy", 11);
            else
                name.Append(ns, strlen(ns));
            name.Append("::", 2);
        }
    }
    const String s = String(closure ? "MethodClosure " : "Function ") + String(name.ToCStr(), name.GetSize());
    name = name.GetManager()->CreateString(s.ToCStr(), s.GetSize());
    name.Append(ti.Name, strlen(ti.Name));
    name.Append("()", 2);
    return name;
}

// The name of method slot ind of a VTable: a method index by the slot's recorded name, a thunk by its own.
// @0x14250fc60
ASString FUN_14250fc60(ASString name, const VTable& vt, UInt32 ind, bool closure)
{
    const Value& m = vt.VTMethods[ind];
    if (m.GetKind() == Value::kMethodInd)
    {
        name = !closure ? "Function " : "MethodClosure ";
        return name + vt.Names[ind] + "()";
    }
    return FUN_14250f330(name, m.AsThunk(), closure);
}

// "*" is the any name; "@x" an attribute name x (unless the name is already an attribute's), "@*" any attribute.
// MS2-FUNCTIONAL the exe splits the function into separate code chunks
// @0x14251cef0
__declspec(noinline) void Multiname::PostProcessName(bool isAttr)
{
    if (!Name.IsString())
        return;
    ASString n = Name.AsString();
    if (n.GetSize() == 0)
        return;
    if (n[0] == '*')
        Name = ASString(n.GetManager()->GetEmptyStringNode());
    else if (n[0] == '@' && !isAttr)
    {
        Kind = static_cast<Abc::MultinameKind>(Kind | 8);
        if (n.GetSize() == 2 && n[1] == '*')
            Name = ASString(n.GetManager()->GetEmptyStringNode());
        else
            Name = ASString(n.SubstringNode(1, n.GetSize()));
    }
}

// VM::LoadFile: the ABC file in the VM, its classes' traits made and its scripts registered (run when
// to_execute); NULL when either fails.
// a VM member: the exe passes the result slot in rdx (no caller in the exe)
// @0x142515b90
SPtr<VMAbcFile> VM::FUN_142515b90(const Ptr<Abc::File>& file, bool to_execute)
{
    VM& vm = *this;
    SPtr<VMAbcFile> abc = Pickable<VMAbcFile>(SF_HEAP_NEW(vm.GetMemoryHeap()) VMAbcFile(vm, file));
    if (!abc->RegisterUserDefinedClassTraits() || !abc->RegisterScrips(to_execute))
        return SPtr<VMAbcFile>();
    return abc;
}

// sfr34 batch V: the run-time name of a multiname off the operand stack, the class traits of an ABC class, and
// the public namespace test of an ABC multiname.

void FUN_1425273b0(Multiname& mn, const Value& qname);     // the name and namespace of a QName object (sfr_as3_15)

// Moves the top value of the stack into this one and pops it; this one is not released. Only inlined.
SF_INLINE void Value::PickUnsafe(ValueStack& v)
{
    const Value& top = *v.pCurrent;
    Flags = top.Flags;
    Bonus = top.Bonus;
    value = top.value;
    --v.pCurrent;
}

// A QName instance.
static inline bool Sfr34_IsQNameObject(const Value& v)
{
    bool result = false;
    if (Value::IsObject(v.GetKind()) && v.GetObject() && v.GetObject()->GetTraits().GetTraitsType() == Traits_QName &&
        v.GetObject()->GetTraits().IsInstanceTraits())
        result = true;
    return result;
}

// Multiname::PickRTNameUnsafe: the run-time name on top of the operand stack: a QName object gives the name and
// namespace (and is released), anything else is moved into the name as it is (the old name is not released).
// MS2-FUNCTIONAL free function (not declared in the shared Multiname class); the QName test is not kept as a flag
// @0x14251c8a0
void FUN_14251c8a0(Multiname& mn, ValueStack& vs)
{
    const Value& top = *vs.GetTopPtr();
    if (Sfr34_IsQNameObject(top))
    {
        FUN_1425273b0(mn, top);
        vs.GetTopPtr()->~Value();
        vs.Release(1);
        return;
    }
    mn.Name.PickUnsafe(vs);
    mn.PostProcessName(false);
}

ClassTraits::Traits** FUN_142414ac0(TClassTraitsCache* self, const ASString& name, const Instances::Namespace& ns);
ClassTraits::Traits*  FUN_142524f60(VM& vm, VMAbcFile& file, const Abc::Multiname& mn);  // a scaleform.gfx class

// The class traits of an ABC class by the name of its instance info: from the VM's class traits cache, else (for
// the scaleform.gfx package) made for it.
// MS2-FUNCTIONAL SDK GetUserDefinedTraits form; register allocation only (the VM, the namespace and the result swap
// callee-saved registers)
// @0x14250f9a0
ClassTraits::Traits* FUN_14250f9a0(VM& vm, VMAbcFile& file, const Abc::ClassInfo& ci)
{
    const Abc::Multiname&  mn   = file.GetAbcFile().Const_Pool.GetMultiname(ci.inst_info.name_ind);
    const ASString         name = file.GetInternedString(mn.NameIndex);
    const Instances::Namespace& ns = file.GetInternedNamespace(mn.Ind);
    ClassTraits::Traits**  ptr  = FUN_142414ac0(&vm.ClassTraitsSet, name, ns);
    if (ptr == NULL)
    {
        // check for *scaleform extension* packages.
        const ASString& t_uri = ns.GetUri();
        const StringDataPtr t_str(t_uri.ToCStr(), t_uri.GetSize());
        const StringDataPtr scaleform_gfx("scaleform.gfx");
        if (t_str.GetSize() >= scaleform_gfx.GetSize() &&
            strncmp(t_str.ToCStr(), scaleform_gfx.ToCStr(), scaleform_gfx.GetSize()) == 0)
            return FUN_142524f60(vm, file, mn);
    }
    return *ptr;
}

// An ABC multiname in a public (or explicit) namespace: its namespace, or any of its namespace set.
// MS2-FUNCTIONAL the namespace index is loaded once ahead of the kind test (the exe loads it in each branch)
// @0x1425112f0
bool FUN_1425112f0(const Abc::ConstPool& cp, const Abc::Multiname& mn)
{
    if ((mn.Kind & 3) >= 2)
    {
        const UInt8*  p = cp.const_ns_set[mn.Ind].Data;
        const UInt32  n = Abc::ReadU30(p);
        for (UInt32 i = 0; i < n; ++i)
        {
            const UInt32              ind = Abc::ReadU30(p);
            const Abc::NamespaceInfo& ns  = ind == 0 ? cp.any_namespace : cp.ConstNamespace[ind];
            if ((ns.Kind & ~4) == 0)
                return true;
        }
        return false;
    }
    const Abc::NamespaceInfo& ns = mn.Ind == 0 ? cp.any_namespace : cp.ConstNamespace[mn.Ind];
    return (ns.Kind & ~4) == 0;
}

} } } // namespace Scaleform::GFx::AS3

// sfr34 batch W: the float shape data (ShapeDataFloat) path records the exe keeps in this unit.
namespace Scaleform { namespace Render {

// @0x142518040
template void ShapeDataFloatTempl<Array<UByte> >::MoveTo(float x, float y);
// @0x142515a20
template void ShapeDataFloatTempl<Array<UByte> >::LineTo(float x, float y);
// @0x142520790
template ShapePathType ShapeDataFloatTempl<Array<UByte> >::ReadPathInfo(ShapePosInfo* pos, float* coord,
                                                                     unsigned* styles) const;
// @0x142520580
template PathEdgeType ShapeDataFloatTempl<Array<UByte> >::ReadEdge(ShapePosInfo* pos, float* coord) const;

} } // namespace Scaleform::Render

namespace Scaleform { namespace GFx { namespace AS3 {

// sfr34 batch X: the instance traits of the type a function returns (of a thunk, and of a function value).

// The interned namespace {kind, uri} (prefix unused here).
Instances::Namespace* FUN_142415c20(InstanceTraits::fl::Namespace* self, Abc::NamespaceKind kind, const ASString& uri,
                                    const Value& prefix);
ClassTraits::Traits*  FUN_142415520(Instances::fl::GlobalObjectCPP* self, const ASString& name,
                                    const Instances::Namespace& ns);      // GlobalObjectCPP: class traits by name
const Abc::Multiname& FUN_142546050(const Abc::MethodInfo& mi, const Abc::ConstPool& cp);   // the return type
const Abc::Multiname& FUN_142416e70(const Traits& ftr);             // the return type of a function's method

// VM::GetFunctReturnType(const ThunkInfo&): the instance traits of the class a thunk's result type names (in its
// package's public namespace), found in the class traits cache or else in the global object (then cached); Object
// when the thunk has no result type or the class is unknown.
// MS2-FUNCTIONAL free function (not declared in the shared VM class); ours returns early for no result type
// @0x142509e30
InstanceTraits::Traits& FUN_142509e30(VM& vm, const ThunkInfo& ti)
{
    if (const TypeInfo* rt = ti.ResultType)
    {
        StringManager& sm   = vm.GetStringManager();
        ASString       name = sm.CreateConstString(rt->Name);
        const Instances::Namespace* ns;
        {
            ASString pkg = sm.CreateString(rt->PkgName ? rt->PkgName : "");
            if (pkg.IsEmpty())
                ns = &vm.GetPublicNamespace();
            else
                ns = FUN_142415c20(&static_cast<InstanceTraits::fl::Namespace&>(
                                       vm.GetClassTraitsNamespace().GetInstanceTraits()),
                                   Abc::NS_Public, pkg, Value::GetUndefined());
        }
        ClassTraits::Traits** p  = FUN_142414ac0(&vm.ClassTraitsSet, name, *ns);
        ClassTraits::Traits*  ct = p ? *p : NULL;
        if (!ct)
        {
            ct = FUN_142415520(vm.GlobalObject.GetPtr(), name, *ns);
            if (!ct)
                return vm.GetClassTraitsObject().GetInstanceTraits();
            vm.ClassTraitsSet.Add(name, *ns, ct);
        }
        return ct->GetInstanceTraits();
    }
    return vm.GetClassTraitsObject().GetInstanceTraits();
}

// VM::GetFunctReturnType(const Value&): the return type of a thunk (or thunk closure / thunk function), of a method
// by index (in its traits' ABC file), of a VTable slot (or VTable index closure) and of a function; Object for
// other values and unknown classes.
// MS2-FUNCTIONAL free function (not declared in the shared VM class); the exe re-tests the kind after the VTable lookup
// @0x14250a060
InstanceTraits::Traits& FUN_14250a060(VM& vm, const Value& v)
{
    const Value*          m = &v;
    VMAbcFile*            file;
    const Abc::Multiname* mn;
    switch (v.GetKind())
    {
    case Value::kThunk:
    case Value::kThunkClosure:
        return FUN_142509e30(vm, v.AsThunk());
    case Value::kVTableInd:
    case Value::kVTableIndClosure:
        m = &v.GetTraits().GetVT().VTMethods[UInt32(v.GetVTableInd())];
        if (m->GetKind() != Value::kMethodInd)
            return FUN_142509e30(vm, m->AsThunk());
        // fall through
    case Value::kMethodInd:
    {
        const SInt32 ind = m->GetMethodInd();
        file = m->GetTraits().GetFilePtr();
        const Abc::File& abc = file->GetAbcFile();
        mn = &FUN_142546050(*abc.Methods.Info[ind], abc.Const_Pool);
        break;
    }
    case Value::kFunction:
    {
        const Traits& ftr = v.AsFunction().GetTraits();
        mn   = &FUN_142416e70(ftr);
        file = *reinterpret_cast<VMAbcFile* const*>(reinterpret_cast<const char*>(&ftr) + 0xf0);
        break;
    }
    case Value::kThunkFunction:
        return FUN_142509e30(vm, **reinterpret_cast<const ThunkInfo* const*>(
                                     reinterpret_cast<const char*>(&v.AsThunkFunction()) + 0x40));
    default:
        return vm.GetClassTraitsObject().GetInstanceTraits();
    }
    ClassTraits::Traits* ct = FUN_142524f60(vm, *file, *mn);
    if (!ct)
        return vm.GetClassTraitsObject().GetInstanceTraits();
    return ct->GetInstanceTraits();
}

// sfr34 batch Y: type tests of values (against class traits and by class name) and the push of a value onto an
// argument array.

// VM::IsOfType: whether v is of the class ctr: a number in the range of int or uint (when integral) is of those,
// any int or uint a Number, everything of Object; references by their class (or a base of it, or an interface).
// MS2-FUNCTIONAL free function (not declared in the shared VM class); its jump table starts at kind 1, the exe's at 0
// @0x1425146d0
bool FUN_1425146d0(VM& vm, const Value& v, const ClassTraits::Traits& ctr)
{
    const BuiltinTraitsType tt = ctr.GetTraitsType();
    bool                    is;
    switch (v.GetKind())
    {
    case Value::kBoolean:
        is = tt == Traits_Boolean;
        break;
    case Value::kInt:
        if (tt == Traits_UInt)
            return v.AsInt() >= 0;
        if (tt == Traits_Number)
            return true;
        is = tt == Traits_SInt;
        break;
    case Value::kUInt:
        if (tt == Traits_SInt)
            return v.AsUInt() <= 0x7fffffff;
        if (tt == Traits_Number)
            return true;
        is = tt == Traits_UInt;
        break;
    case Value::kNumber:
    {
        double ip;
        if (modf(v.AsNumber(), &ip) == 0.0)
        {
            if (tt == Traits_UInt)
                return ip >= 0.0 && ip <= 4294967295.0;
            if (tt == Traits_SInt)
                return ip >= -2147483648.0 && ip <= 2147483647.0;
        }
        is = tt == Traits_Number;
        break;
    }
    case Value::kString:
        if (!v.GetStringNode())
            return false;
        is = tt == Traits_String;
        break;
    case Value::kObject:
        if (!v.GetObject())
            return false;
        // fall through
    case Value::kNamespace:
    case Value::kFunction:
    case Value::kThunkFunction:
    case Value::kThunkClosure:
    case Value::kVTableIndClosure:
        return FUN_1425149a0(ctr, vm.GetClassTraits(v));
    case Value::kClass:
        if (!v.GetObject())
            return false;
        return FUN_1425149a0(ctr, v.GetObject()->GetTraits().GetConstructor().GetClassTraits());
    default:
        return false;
    }
    return is || &ctr == &vm.GetClassTraitsObject();
}

} } } // namespace Scaleform::GFx::AS3

const Scaleform::GFx::AS3::ClassTraits::Traits* FUN_142525270(Scaleform::GFx::AS3::VM& vm,
                                                               const Scaleform::GFx::AS3::Multiname& mn);  // Resolve2ClassTraits

// Whether v is of the class named className (a qualified name, "a.b::C" or "a.b.C").
// @0x1425145d0
bool FUN_1425145d0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v, const char* className)
{
    using namespace Scaleform::GFx::AS3;
    const Multiname            mn(vm, Scaleform::StringDataPtr(className));
    const ClassTraits::Traits* ctr = FUN_142525270(vm, mn);
    return ctr && FUN_1425146d0(vm, v, *ctr);
}

namespace Scaleform {
// MS2-FUNCTIONAL the exe inlines the reference count increment of the copied value
// @0x14251f660
template void ArrayBase<ArrayData<GFx::AS3::Value, AllocatorGH<GFx::AS3::Value, 2>, ArrayDefaultPolicy> >::PushBack(
    const GFx::AS3::Value&);
// The Tracer's OrigOpcodePos.PushBack (SkipOrigOpCode calls it out of line).
// @0x14251f710
template void ArrayBase<ArrayDataDH<UPInt, AllocatorDH_POD<UPInt, GFx::AS3::StatMV_VM>, ArrayDefaultPolicy> >::PushBack(const UPInt&);
} // namespace Scaleform

namespace Scaleform { namespace GFx { namespace AS3 {

// sfr34 batch Z: a slot typed Class, and the class traits the VM keeps.

// TraitInfo::GetTypeName, inline here; the exe tests a zero slot type index twice (int, then SPInt).
static SF_INLINE const Abc::Multiname& Sfr18GetTypeName(const Abc::TraitInfo& ti, const Abc::File& abc, const Abc::ConstPool& cp)
{
    const Abc::TraitInfo::Type type = ti.GetType();
    if (type == Abc::TraitInfo::tSlot || type == Abc::TraitInfo::tConst)
        return ti.Ind == 0 ? cp.AnyType : cp.GetMultiname(ti.Ind);
    return cp.GetMultiname(abc.AS3_Classes.Info[ti.Ind]->inst_info.name_ind);
}

// SlotInfo::IsClassType: whether the slot's declared type is the public, top-level Class.
// A free function (SlotInfo is a shared class).
// @0x142514100
bool FUN_142514100(const SlotInfo& si)
{
    bool result = false;
    if (si.File.GetPtr() && si.TI)
    {
    const Abc::File&          abc = si.File->GetAbcFile();
    const Abc::ConstPool&     cp  = abc.Const_Pool;
    const Abc::TraitInfo&     ti  = *si.TI;
    const Abc::Multiname&     mn  = Sfr18GetTypeName(ti, abc, cp);
    const SPInt               nsi = mn.Ind;
    const Abc::NamespaceInfo& ns  = nsi == 0 ? cp.any_namespace : cp.ConstNamespace[nsi];
    if (cp.GetString(static_cast<UInt32>(mn.NameIndex)) == StringDataPtr("Class", 5) &&
        (ns.Kind == Abc::NS_Public || ns.Kind == Abc::NS_Explicit) && ns.NameURI.IsEmpty())
        result = true;
    }
    return result;
}

// VM::IsVMCachedType: whether tr is one of the class traits the VM caches (and XML's, when it is enabled).
// MS2-FUNCTIONAL free function (not declared in the shared VM class)
// @0x142515460
bool FUN_142515460(const VM& vm, const ClassTraits::Traits* tr)
{
    bool result = false;
    if (tr == vm.TraitsBoolean || tr == vm.TraitsNumber || tr == vm.TraitsInt || tr == vm.TraitsUint ||
        tr == vm.TraitsString || tr == vm.TraitsClassClass || tr == vm.TraitsObject || tr == vm.TraitsNamespace ||
        tr == vm.TraitsFunction || tr == vm.TraitsArray || tr == vm.TraitsVector_int || tr == vm.TraitsVector_uint ||
        tr == vm.TraitsVector_double || tr == vm.TraitsVector_String)
        result = true;
    else
    {
        const XMLSupport& xml = vm.GetXMLSupport();
        if (xml.IsEnabled() && (tr == xml.GetClassTraitsQName() || tr == xml.GetClassTraitsXML() ||
                                tr == xml.GetClassTraitsXMLList()))
            result = true;
    }
    return result;
}

// The character keyboard idx's focus group has focused.
static inline Ptr<InteractiveObject> Sfr34_GetFocused(MovieImpl* movie, unsigned idx)
{
    return movie->FocusGroups[movie->FocusGroupIndexes[idx]].LastFocused;
}

// The AS3 container part of a display object container.
static inline AvmDisplayObjContainer* Sfr34_ToAvmContainer(DisplayObject* p)
{
    return static_cast<AvmDisplayObjContainer*>(p->GetAvmObjImpl()->ToAvmDispContainerBase());
}

// MovieRoot's KeyboardState::IListener::OnKeyDown/OnKeyUp: the key event to the AS3 object of the focused
// character (of the stage when there is none), unless the keyboard's focus group is in keyMask (a text field
// handles its own keys). self is the listener part (+0x38) of the root.
static __forceinline void Sfr34_OnKey(UPInt self, const EventId& evt, int keyMask)
{
    MovieRoot*             root    = reinterpret_cast<MovieRoot*>(self - 0x38);
    Ptr<InteractiveObject> focused = Sfr34_GetFocused(root->GetMovieImpl(), evt.KeyboardIndex);
    const unsigned         idx     = evt.KeyboardIndex;
    const unsigned         group   = root->GetMovieImpl()->FocusGroupIndexes[idx];
    if (((1 << group) & keyMask) == 0)
    {
        Instances::fl_display::DisplayObject* as3obj =
            focused ? ToAvmInteractiveObj(focused)->GetAS3Obj()
                    : Sfr34_ToAvmContainer(root->pStage)->GetAS3Obj();
        if (as3obj)
            as3obj->Dispatch(evt, focused);
    }
}

// MS2-FUNCTIONAL free function on the listener subobject this (MovieRoot's IListener base is not modeled)
// @0x14251a1e0
void FUN_14251a1e0(UPInt self, InteractiveObject* pmovie, const EventId& evt, int keyMask)
{
    SF_UNUSED(pmovie);
    Sfr34_OnKey(self, evt, keyMask);
}

// MS2-FUNCTIONAL free function on the listener subobject this (MovieRoot's IListener base is not modeled)
// @0x14251a3b0
void FUN_14251a3b0(UPInt self, InteractiveObject* pmovie, const EventId& evt, int keyMask)
{
    SF_UNUSED(pmovie);
    Sfr34_OnKey(self, evt, keyMask);
}

// MovieRoot's FlashUI::Output: an AVM message to the movie's log (cached for the frame) by type, cut to 1999
// characters. self is the FlashUI part (+0x28) of the root.
// MS2-FUNCTIONAL free function on the FlashUI subobject this (MovieRoot's FlashUI base is not modeled)
// @0x14251bc40
void FUN_14251bc40(UPInt self, FlashUI::OutputMessageType type, const char* msg)
{
    MovieImpl* movie = reinterpret_cast<MovieRoot*>(self - 0x28)->GetMovieImpl();
    if (!((movie->Flags >> 1) & 1))     // Flag_CachedLogFlag
        movie->pCachedLog = movie->GetStateBag()->GetLog();
    Log* log = movie->pCachedLog;
    if (!log)
        return;
    int logId;
    switch (type)
    {
    case FlashUI::Output_Error:   logId = LogChannel_Script | LogMessage_Error; break;
    case FlashUI::Output_Warning: logId = Log_ScriptWarning; break;
    case FlashUI::Output_Action:  logId = Log_Action; break;
    default:                      logId = Log_Message; break;
    }
    char         buf[2000];
    const size_t len  = SFstrlen(msg);
    const size_t copy = len < sizeof(buf) ? len : sizeof(buf) - 1;
    strncpy_s(buf, sizeof(buf), msg, copy);
    buf[copy] = '\0';
    log->LogMessageById(logId, len < sizeof(buf) ? "%s" : "%s ...<truncated>", buf);
}

// sfr34 batch AA: the mouse hit test of an AS3 bitmap.

// AvmBitmap::GetTopMostMouseEntity: a visible bitmap with an image is hit when the point (in its parent's space)
// falls inside the image's rectangle (in twips); the hit is its parent, the interactive object.
// MS2-FUNCTIONAL free function on the bitmap's display object (AvmBitmap is opaque in the shared header)
// @0x14250f660
DisplayObjectBase::TopMostResult FUN_14250f660(DisplayObject* self, const Render::PointF& pt,
                                               DisplayObjectBase::TopMostDescr* pdescr)
{
    ImageResource* image = *reinterpret_cast<ImageResource* const*>(reinterpret_cast<const char*>(self) + 0xc0);
    if (self->GetVisible() && image)
    {
        Render::PointF p;
        self->TransformPointToLocal(&p, pt);
        const Render::ImageRect rect = image->GetImage()->GetRect();
        const RectF r(0, 0, Render::SizeF(PixelsToTwips((float)rect.Width()), PixelsToTwips((float)rect.Height())));
        if (r.Contains(p))
        {
            pdescr->pResult = self->GetParent();
            return DisplayObjectBase::TopMost_Found;
        }
    }
    return DisplayObjectBase::TopMost_FoundNothing;
}

// The data of a URLLoader's text load: URL variables (unescaped first) or a string, then its open/progress/complete
// events; a failed load gives the error event.
// @0x14251f250
void MovieRoot::ProcessLoadVarsMT(GFx::LoadQueueEntry* pentry, LoadStates* pls, const String& data, UPInt fileLen,
                                  bool succeeded)
{
    SF_UNUSED(pls);
    AS3::LoadQueueEntry* entry = static_cast<AS3::LoadQueueEntry*>(pentry);
    if (!succeeded)
    {
        char buf[1024];
        SFsprintf(buf, sizeof(buf), "Can't open %s", entry->mURLRequest->GetUrl().ToCStr());
        entry->mURLLoader->ExecuteErrorEvent(buf);
        return;
    }
    if (entry->mURLLoader->IsLoadingVariables())
    {
        String vars;
        ASUtils::Unescape(data.ToCStr(), data.GetSize(), &vars);
        entry->mURLLoader->SetVariablesDataString(vars.ToCStr());
    }
    else if (entry->mURLLoader->IsLoadingText())
        entry->mURLLoader->SetTextString(data.ToCStr());
    else
        entry->mURLLoader->IsLoadingBinary();   // binary loads come through ProcessLoadBinaryMT
    entry->mURLLoader->ExecuteOpenEvent();
    entry->mURLLoader->ExecuteProgressEvent(UInt32(fileLen), UInt32(fileLen));
    entry->mURLLoader->ExecuteCompleteEvent();
}

void* FUN_1425059f0(const void* self, const UPInt& key);   // the value an identity-hashed word key maps to

// MovieRoot::RemoveLoadedMovieDef: one use less of a loaded movie definition; at the last its entry leaves the
// root's loaded movie definitions (+0x6e8). True when the entry was removed.
// MS2-FUNCTIONAL the identity hash's removal is written out over a layout view (the hash is opaque in the shared header)
// @0x142522920
bool FUN_142522920(MovieRoot* self, MovieDefImpl* def)
{
    struct Entry { SPInt Next; UPInt Key; Ptr<MovieDefImpl> pMovieDef; unsigned UseCnt; };
    struct Table { UPInt EntryCount; UPInt SizeMask; Entry E[1]; };
    Table**     ptable = reinterpret_cast<Table**>(&self->LoadedMovieDefs);
    const UPInt key    = reinterpret_cast<UPInt>(def);
    unsigned*   pcnt   = static_cast<unsigned*>(FUN_1425059f0(ptable, key));
    if (!pcnt || --pcnt[2] != 0)
        return false;
    Table* t = *ptable;
    if (!t)
        return true;
    const UPInt home = key & t->SizeMask;
    Entry*      e    = &t->E[home];
    if (e->Next == -2 || (e->Key & t->SizeMask) != home)
        return true;
    SPInt idx = SPInt(home), prev = -1;
    while ((e->Key & t->SizeMask) != home || e->Key != key)
    {
        if (e->Next == -1)
            return true;
        prev = idx;
        idx  = e->Next;
        e    = &t->E[idx];
    }
    if (idx == SPInt(home))
    {
        if (e->Next != -1)
        {
            // the next one in the chain moves into the home slot
            Entry* n = &t->E[e->Next];
            e->pMovieDef.Clear();
            e->Next      = n->Next;
            e->Key       = n->Key;
            e->pMovieDef = n->pMovieDef;
            e->UseCnt    = n->UseCnt;
            e            = n;
        }
    }
    else
        t->E[prev].Next = e->Next;
    e->pMovieDef.Clear();
    e->Next = -2;
    --t->EntryCount;
    return true;
}

// VM::IsVMCachedType: whether itr is the instance traits of one of the class traits the VM caches (and XML's,
// when it is enabled).
// MS2-FUNCTIONAL free function (not declared in the shared VM class)
// @0x142515580
bool FUN_142515580(const VM& vm, const InstanceTraits::Traits* itr)
{
    bool result = false;
    if (itr == &vm.TraitsBoolean->GetInstanceTraits() || itr == &vm.TraitsNumber->GetInstanceTraits() ||
        itr == &vm.TraitsInt->GetInstanceTraits() || itr == &vm.TraitsUint->GetInstanceTraits() ||
        itr == &vm.TraitsString->GetInstanceTraits() || itr == &vm.TraitsClassClass->GetInstanceTraits() ||
        itr == &vm.TraitsObject->GetInstanceTraits() || itr == &vm.TraitsNamespace->GetInstanceTraits() ||
        itr == &vm.TraitsFunction->GetInstanceTraits() || itr == &vm.TraitsArray->GetInstanceTraits() ||
        itr == &vm.TraitsVector_int->GetInstanceTraits() || itr == &vm.TraitsVector_uint->GetInstanceTraits() ||
        itr == &vm.TraitsVector_double->GetInstanceTraits() || itr == &vm.TraitsVector_String->GetInstanceTraits())
        result = true;
    else
    {
        const XMLSupport& xml = vm.GetXMLSupport();
        if (xml.IsEnabled() && (itr == xml.GetITraitsQName() || itr == xml.GetITraitsXML() ||
                                itr == xml.GetITraitsXMLList()))
            result = true;
    }
    return result;
}

// The actions of level srclvl moved to the end of level dstlvl's queue, in order. The copy of an entry leaves out
// its function value (4.1.18 copies the event, the character and objects, the C function and the load notifier).
// MS2-FUNCTIONAL the exe copies the event id field by field and keeps the queue root in a register
// @0x142522ae0
void MovieRoot::RequeueActionQueue(ActionLevel srclvl, ActionLevel dstlvl)
{
    if (ActionQueue.Entries[srclvl].pActionRoot)
    {
        ActionQueueIterator iter(srclvl, &ActionQueue);
        while (const ActionEntry* src = iter.getNext())
        {
            ActionEntry* dst  = InsertEmptyAction(dstlvl);
            dst->Type         = src->Type;
            dst->pCharacter   = src->pCharacter;
            dst->pAS3Obj      = src->pAS3Obj;
            dst->mEventId     = src->mEventId;
            dst->CFunction    = src->CFunction;
            dst->pNLoadInitCL = src->pNLoadInitCL;
        }
    }
}

// sfr34 batch AB: the registration of a method in the virtual table of traits.

// Slots::FindSlotInfoIndex is protected; its member pointer is taken through a derived class.
struct Sfr34_SlotsAccess : Slots
{
    static AbsoluteIndex Find(const Slots& s, const ASString& k, const Instances::Namespace& ns)
    {
        return (s.*(&Sfr34_SlotsAccess::FindSlotInfoIndex))(k, ns);
    }
};

// Traits::RegisterWithVT: method v (named name in nsi's namespace) overrides the slot of that name and namespace
// (a getter added to a setter, or the reverse, gets a slot of its own), or gets a new one. False when that slot is
// not a method.
// MS2-FUNCTIONAL free function (not declared in the shared Traits class)
// @0x142521d20
CheckResult FUN_142521d20(Traits* self, const ASString& name, const SlotInfo& nsi, const Value& v,
                          SlotInfo::BindingType bt)
{
    const Instances::Namespace& ns  = *nsi.pNs;
    const AbsoluteIndex         ind = Sfr34_SlotsAccess::Find(*self, name, ns);
    if (!ind.IsValid())
    {
        self->Add2VT(name, ns, nsi, v, bt);
        return true;
    }
    const SlotInfo&       si     = self->GetSlotInfo(ind);
    SlotInfo::BindingType new_bt = static_cast<SlotInfo::BindingType>(si.BindType);
    if (new_bt != SlotInfo::BT_Unknown && (new_bt < SlotInfo::BT_Code || new_bt > SlotInfo::BT_GetSet))
        return false;
    if ((new_bt == SlotInfo::BT_Get && bt == SlotInfo::BT_Set) || (new_bt == SlotInfo::BT_Set && bt == SlotInfo::BT_Get))
        new_bt = SlotInfo::BT_GetSet;
    if (new_bt == bt)
    {
        self->UpdateVT4IM(name, ns, v, bt);
        self->UpdateVT(si, v, bt);
    }
    else
        self->Add2VT(name, ns, si, v, bt);
    return true;
}

} } } // namespace Scaleform::GFx::AS3

// Abc::Code::opcode_info: per opcode its operand count (-1: invalid), whether it can throw, the values it pops and
// pushes, and whether it reads an argument count and a multiname.
struct Sfr34_OpCodeInfo
{
    signed char   operandCount : 3;
    unsigned char canThrow : 1;
    unsigned char pop : 2;
    unsigned char push : 2;
    unsigned char pop_args : 1;
    unsigned char pop_mn : 1;
    const char*   name;
};
extern const Sfr34_OpCodeInfo DAT_14317fea0[0x100];

namespace Scaleform { namespace GFx { namespace AS3 {

// The position of the first lookupswitch of the byte code (at +0x50 of its holder) from pos on, past which pos is
// left; 0 when there is none (pos is then at the end).
// MS2-FUNCTIONAL free function over a layout view of the byte code's holder (it has no caller in the exe)
// @0x14250c080
UPInt FUN_14250c080(const void* self, UPInt& pos)
{
    struct View { char pad[0x50]; const UInt8* data; UPInt size; };
    const View* c = static_cast<const View*>(self);
    while (pos < c->size)
    {
        const UPInt op_pos = pos;
        const UInt8 op     = c->data[pos++];
        if (DAT_14317fea0[op].pop_mn)
            Abc::ReadU30(c->data, pos);
        if (DAT_14317fea0[op].pop_args)
            Abc::ReadU30(c->data, pos);
        if (DAT_14317fea0[op].pop_mn || DAT_14317fea0[op].pop_args)
            continue;
        if (op >= 0x0c && op <= 0x1a)
        {
            // the branches
            Abc::ReadS24(c->data, pos);
            continue;
        }
        if (op == 0x1b)
        {
            // lookupswitch: the default offset, the case count - 1 and the case offsets
            Abc::ReadS24(c->data, pos);
            const int n = Abc::ReadU30(c->data, pos);
            for (int i = 0; i <= n; ++i)
                Abc::ReadS24(c->data, pos);
            return op_pos;
        }
        if (op == 0x24)
        {
            // pushbyte
            ++pos;
            continue;
        }
        if (op == 0xef)
        {
            // debug: a byte, a u30, a byte and a u30
            ++pos;
            Abc::ReadU30(c->data, pos);
            ++pos;
            Abc::ReadU30(c->data, pos);
            continue;
        }
        switch (DAT_14317fea0[op].operandCount)
        {
        case 2:
            Abc::ReadU30(c->data, pos);
            // fall through
        case 1:
            Abc::ReadU30(c->data, pos);
            break;
        default:
            break;
        }
    }
    return 0;
}

// The parent's slot table (its slots counted before the own ones, its name set copied) and its fixed value slot
// count; the own slots start after all of them.
// @0x1425115f0
void Traits::CopyParentTraits()
{
    if (const Traits* p = pParent.GetPtr())
    {
        Inherit(*p);
        FirstOwnSlotInd      = AbsoluteIndex(GetSlotInfoNum());
        FixedValueSlotNumber = pParent->FixedValueSlotNumber;
    }
}

void FUN_14252ecb0(void* vm, const void* error, const void* classInfo);   // VM: raise the error as an instance of the class

} } } // namespace Scaleform::GFx::AS3

// SlotInfo::GetSlotValueUnsafe(VM&, Value&, const Value& _this, const VTable*, ValTarget): the value of the slot of
// _this's object: a stored value (of the global object's value array, a Value, an object, a primitive, a string, a
// constant C string), a method (as a closure of the object when it is one and the value is read), or the result of
// the getter. vt is the method table to use (super properties); else that of _this's traits. False (with a
// TypeError or ReferenceError raised for a non-callable getter or a write-only property) when the slot has no
// value.
// MS2-FUNCTIONAL free function (not declared in the shared SlotInfo class); the slot is read over its address
// @0x14250e2d0
char* FUN_14250e2d0(const void* psi, void* ret, Scaleform::GFx::AS3::VM* pvm, Scaleform::GFx::AS3::Value* pvalue,
                    const Scaleform::GFx::AS3::Value* pthis, void* pvt, int vtt)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    const SlotInfo& si    = *static_cast<const SlotInfo*>(psi);
    VM&             vm    = *pvm;
    Value&          value = *pvalue;
    const Value&    _this = *pthis;
    const VTable*   vt    = static_cast<const VTable*>(pvt);
    char*           r     = static_cast<char*>(ret);
    const SInt32    ind   = si.ValueInd;
    const UPInt     base  = reinterpret_cast<UPInt>(_this.GetObject());
    switch (si.BindType)
    {
    case SlotInfo::BT_ValueArray:
        value.AssignUnsafe(reinterpret_cast<const Value*>(*reinterpret_cast<const UPInt*>(base + 0xa8))[UInt32(ind)]);
        break;
    case SlotInfo::BT_Value:
        value.AssignUnsafe(*reinterpret_cast<const Value*>(base + UInt32(ind)));
        break;
    case SlotInfo::BT_ObjectAS:
        reinterpret_cast<STPtr*>(base + UInt32(ind))->GetValueUnsafe(value);
        break;
    case SlotInfo::BT_ObjectCpp:
        value.AssignUnsafe(*reinterpret_cast<const SPtr<Instances::fl::GlobalObjectCPP>*>(base + UInt32(ind)));
        break;
    case SlotInfo::BT_Boolean:
        value.SetBoolUnsafe(*reinterpret_cast<const bool*>(base + UInt32(ind)));
        break;
    case SlotInfo::BT_Int:
        value.SetSInt32Unsafe(*reinterpret_cast<const SInt32*>(base + UInt32(ind)));
        break;
    case SlotInfo::BT_UInt:
        value.SetUInt32Unsafe(*reinterpret_cast<const UInt32*>(base + UInt32(ind)));
        break;
    case SlotInfo::BT_Number:
        value.SetNumberUnsafe(*reinterpret_cast<const Value::Number*>(base + UInt32(ind)));
        break;
    case SlotInfo::BT_String:
        if (GFx::ASStringNode* node = *reinterpret_cast<GFx::ASStringNode* const*>(base + UInt32(ind)))
            value.AssignUnsafe(node);
        else
            value.SetNullUnsafe();   // null is an object, not a string
        break;
    case 10:   // a constant C string (4.1.18 numbers this binding before BT_Code)
        value.AssignUnsafe(vm.GetStringManager().CreateConstString(*reinterpret_cast<const char* const*>(base + UInt32(ind))));
        break;
    case SlotInfo::BT_Code:
        if (!vt)
            vt = &FUN_14250ffc0(vm, _this).GetVT();
        if (_this.IsObject() && vtt == SlotInfo::valGet)
            FUN_14250ba10(vt, value, AbsoluteIndex(ind), _this.GetObject());
        else
            value.AssignUnsafe(vt->GetValue(AbsoluteIndex(ind)));
        break;
    case SlotInfo::BT_Get:
    case SlotInfo::BT_GetSet:
    {
        if (!vt)
            vt = &FUN_14250ffc0(vm, _this).GetVT();
        const Value getter = vt->GetValue(AbsoluteIndex(ind));
        if (!getter.IsCallable())
        {
            const VM::Error e(VM::eCallOfNonFunctionError, vm, getter);
            FUN_14252ecb0(&vm, &e, &fl::TypeErrorCI);
            *r = false;
            return r;
        }
        vm.ExecuteInternalUnsafe(getter, _this, value, 0, NULL, false);
        break;
    }
    case SlotInfo::BT_Set:
    {
        const VM::Error e(static_cast<VM::ErrorID>(1077) /* eWriteOnlyError */, vm, si.Name->pData, _this);
        FUN_14252ecb0(&vm, &e, &fl::ReferenceErrorCI);
    }
        // fall through
    default:
        *r = false;
        return r;
    }
    *r = true;
    return r;
}

namespace Scaleform { namespace GFx { namespace AS3 {

const SlotInfo* FindFixedSlot(VM& vm, const Traits& tr, const Multiname& mn, UPInt& index, Object* obj);   // 0x142500f90

// Value::Swap (sfr_as3_19) in the SDK form, inline here as in the exe.
struct Sfr18ValueSwap
{
    static SF_INLINE void Swap(Value& self, Value& other)
    {
        const UInt32       tmpFlags = other.Flags;
        const Value::Extra tmpBonus = other.Bonus;
        const Value::VU    tmpValue = other.value;

        other.Flags = self.Flags;
        other.Bonus = self.Bonus;
        other.value = self.value;

        self.Flags = tmpFlags;
        self.Bonus = tmpBonus;
        self.value = tmpValue;
    }
};

// GetSuperProperty: the property mn of _this as the parent of ot (by default _this's traits) has it.
// @0x14250ef80
CheckResult GetSuperProperty(VM& vm, const Traits* ot, Value& result, const Value& _this, const Multiname& mn,
                             SlotInfo::ValTarget vtt)
{
    if (!ot)
        ot = &FUN_14250ffc0(vm, _this);
    if (const Traits* parent = ot->pParent.GetPtr())
    {
        UPInt index = 0;
        if (const SlotInfo* si = FindFixedSlot(vm, *parent, mn, index, NULL))
        {
            Value value;
            bool  ok;
            if (*FUN_14250e2d0(si, &ok, &vm, &value, &_this, &parent->GetVT(), vtt))
            {
                Sfr18ValueSwap::Swap(result, value);
                return true;
            }
        }
    }
    return false;
}

// sfr34 batch AC: the registration of a Vector class, ...

// VM::RegisterClassTraitsVector: tr in the VM's class set under the name of its class object's traits, in the
// public namespace of the Vector package.
// MS2-FUNCTIONAL free function (not declared in the shared VM class)
// @0x142521150
void FUN_142521150(VM& vm, ClassTraits::Traits& tr)
{
    const Instances::Namespace* ns;
    {
        ASString uri = vm.GetStringManager().CreateString(fl_vec::NS_Vector ? fl_vec::NS_Vector : "");
        if (uri.IsEmpty())
            ns = &vm.GetPublicNamespace();
        else
            ns = FUN_142415c20(&static_cast<InstanceTraits::fl::Namespace&>(
                                   vm.GetClassTraitsNamespace().GetInstanceTraits()),
                               Abc::NS_Public, uri, Value::GetUndefined());
    }
    vm.ClassTraitsSet.Add(tr.GetInstanceTraits().GetConstructor().GetTraits().GetName(), *ns, &tr);
}

} } } // namespace Scaleform::GFx::AS3

void FUN_142501b00(Scaleform::GFx::AS3::PropRef& result, Scaleform::GFx::AS3::VM& vm,
                   const Scaleform::GFx::AS3::Value& value, const Scaleform::GFx::AS3::Multiname& mn,
                   int attr);   // FindObjProperty

namespace Scaleform { namespace GFx { namespace AS3 {

// GetPropertyUnsafe: the property prop_name of _this into value: by the object itself when it is array-like or an
// XML (list) instance, else by the found slot or dynamic value. False when there is none or it could not be read.
// MS2-FUNCTIONAL free function returning its CheckResult through a pointer; the exe inlines the read of the found
// @0x14250d2f0
char* FUN_14250d2f0(char* ret, VM& vm, const Value& _this, const Multiname& prop_name, Value& value)
{
    if (_this.IsObject())
    {
        Object*       obj = _this.GetObject();
        const Traits& tr  = obj->GetTraits();
        if (tr.IsArrayLike() ||
            ((tr.GetTraitsType() == Traits_XML || tr.GetTraitsType() == Traits_XMLList) && tr.IsInstanceTraits()))
        {
            *ret = obj->GetProperty(prop_name, value);
            return ret;
        }
    }
    PropRef prop;
    FUN_142501b00(prop, vm, _this, prop_name, 0);
    const UPInt bits = reinterpret_cast<UPInt>(prop.pValue);
    if (prop.This.IsUndefined() || bits == 1 || ((bits & 2) != 0 && (bits & ~UPInt(2)) == 0))
        *ret = false;
    else
        *ret = prop.GetSlotValueUnsafe(vm, value);
    return ret;
}

void FUN_1424e6cf0(void* self, UPInt offset);   // the code position offset as the start of a block

// The starts of the byte code's blocks: the labels, the targets of the branches and the positions after them, and
// the targets of the lookupswitches (relative to their opcodes).
// MS2-FUNCTIONAL free function over a layout view of the byte code's holder (it has no caller in the exe)
// @0x142516960
void FUN_142516960(void* self)
{
    struct View { char pad[0x50]; const UInt8* data; UPInt size; };
    const View* c   = static_cast<const View*>(self);
    UPInt       pos = 0;
    while (pos < c->size)
    {
        const UInt8 op = c->data[pos++];
        if (DAT_14317fea0[op].pop_mn)
            Abc::ReadU30(c->data, pos);
        if (DAT_14317fea0[op].pop_args)
            Abc::ReadU30(c->data, pos);
        if (DAT_14317fea0[op].pop_mn || DAT_14317fea0[op].pop_args)
            continue;
        switch (op)
        {
        case 0x09:
            // label
            FUN_1424e6cf0(self, pos - 1);
            break;
        case 0x0c: case 0x0d: case 0x0e: case 0x0f: case 0x10: case 0x11: case 0x12: case 0x13:
        case 0x14: case 0x15: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
        {
            // the branches
            const int offset = Abc::ReadS24(c->data, pos);
            FUN_1424e6cf0(self, pos);
            FUN_1424e6cf0(self, pos + offset);
            break;
        }
        case 0x1b:
        {
            // lookupswitch: the default offset, the case count - 1 and the case offsets
            const UPInt base = pos - 1;
            FUN_1424e6cf0(self, base + Abc::ReadS24(c->data, pos));
            const int n = Abc::ReadU30(c->data, pos);
            for (int i = 0; i <= n; ++i)
                FUN_1424e6cf0(self, base + Abc::ReadS24(c->data, pos));
            break;
        }
        case 0x24:
            // pushbyte
            ++pos;
            break;
        case 0xef:
            // debug: a byte, a u30, a byte and a u30
            ++pos;
            Abc::ReadU30(c->data, pos);
            ++pos;
            Abc::ReadU30(c->data, pos);
            break;
        default:
            switch (DAT_14317fea0[op].operandCount)
            {
            case 2:
                Abc::ReadU30(c->data, pos);
                // fall through
            case 1:
                Abc::ReadU30(c->data, pos);
                break;
            default:
                break;
            }
            break;
        }
    }
}

// A strong reference to a namespace or object (or the object of a closure) becomes a weak one: the object's weak
// proxy (made and registered with the collector on first use) is kept and the reference released.
// MS2-FUNCTIONAL the exe inlines the weak proxy hash lookup and insertion
// @0x142516720
bool Value::MakeWeakRef()
{
    if (IsWeakRef())
        return false;
    GASRefCountBase* obj;
    switch (GetKind())
    {
    case kNamespace:
    case kObject:
    case kClass:
    case kFunction:
    case kThunkFunction:
        obj = value.VS._1.VObj;
        break;
    case kThunkClosure:
    case kVTableIndClosure:
        obj = value.VS._2.VObj;
        break;
    default:
        return false;
    }
    if (!obj)
        return false;
    GASRefCountBase::Collector* gc    = obj->GetCollector();
    WeakProxy*                  proxy = NULL;
    if (!gc->WProxyHash.Get(obj, &proxy))
    {
        proxy = SF_HEAP_AUTO_NEW(obj) WeakProxy;
        if (proxy)
        {
            proxy->RefCount = 1;
            proxy->pObject  = obj;
            *reinterpret_cast<UInt32*>(reinterpret_cast<UByte*>(obj) + 0x10) |= GASRefCountBase::Flag_HasWeakRef;
            gc->WProxyHash.Add(obj, proxy);
        }
    }
    if (proxy)
        proxy->AddRef();
    Flags |= weakRefMask;
    Bonus.pWeakProxy = proxy;
    ReleaseInternal();
    return true;
}

// The call stack as text, the innermost frame first, one per line: line_pref, "at " and the function's name with
// "()", then "[file:line]" when the frame has a source file.
// MS2-FUNCTIONAL the call frames are read through a layout view of the VM's paged call stack (+0x78 size, +0x90 pages)
// @0x14250ec00
void VM::GetStackTraceASString(ASString& result, const char* line_pref)
{
    const UByte*  self  = reinterpret_cast<const UByte*>(this);
    const UPInt   size  = *reinterpret_cast<const UPInt*>(self + 0x78);
    const UByte** pages = *reinterpret_cast<const UByte** const*>(self + 0x90);
    UPInt         ind   = size;
    for (UPInt n = 0; n < size; ++n)
    {
        --ind;
        const CallFrame& cf = *reinterpret_cast<const CallFrame*>(pages[ind >> 6] + (ind & 0x3f) * 0xa8);
        if (n != 0)
            result.Append("\n", 1);
        result.Append(line_pref, strlen(line_pref));
        result.Append("at ", 3);
        result.Append(ASString(cf.Name.GetPtr()));
        result.Append("()", 2);
        if (cf.CurrFileInd != 0)
        {
            result.Append("[", 1);
            result.Append(cf.pFile->GetInternedString(cf.CurrFileInd));
            result.Append(":", 1);
            const String line = Scaleform::AsString(cf.CurrLineNumber);
            result.Append(line.ToCStr(), strlen(line.ToCStr()));
            result.Append("]", 1);
        }
    }
}

namespace fl { extern const ClassInfo FunctionCI; }

// VMAbcFile::GetFunctionInstanceTraits: the traits of the closures of method method_ind of the script gos, made on
// first use and cached by the file (+0x98) unless making them threw (the VM's no-function traits then).
// MS2-FUNCTIONAL free function over a layout view of the file's cache (VMAbcFile keeps it private)
// @0x14250a250
InstanceTraits::Traits& FUN_14250a250(VMAbcFile* file, Instances::fl::GlobalObjectScript& gos, UInt32 method_ind)
{
    typedef HashLH<UInt32, SPtr<InstanceTraits::Function>, FixedSizeHash<UInt32>, StatMV_VM_VMAbcFile_Mem> TCache;
    TCache& cache = *reinterpret_cast<TCache*>(reinterpret_cast<UByte*>(file) + 0x98);
    if (SPtr<InstanceTraits::Function>* p = cache.Get(method_ind))
        return **p;
    VM&                        vm  = file->GetVM();
    InstanceTraits::Function*  itr = SF_HEAP_NEW(vm.GetMemoryHeap())
        InstanceTraits::Function(*file, fl::FunctionCI, method_ind, &gos);
    if (vm.IsException())
        return *vm.NoFunctionTraits;
    cache.Add(method_ind, Pickable<InstanceTraits::Function>(itr));
    return *itr;
}


// The opcode of the byte code (of a tracer, at +0x50) from pos on that consumes the value on the stack top at pos:
// the stack depth is followed through the pops (with a run-time name's namespace and name, and the arguments; two
// per property of a newobject) and pushes, and through the jumps; the last opcode when the code ends first, a nop
// when pos is past the end.
// MS2-FUNCTIONAL free function over layout views of the tracer and its holder (the Tracer model is not ours)
// @0x14250c990
UInt8 FUN_14250c990(const void* self, UPInt pos)
{
    struct Holder { char pad[0x28]; const VMAbcFile* file; };
    struct View { char pad[0x20]; const Holder* holder; char pad2[0x28]; const UInt8* data; UPInt size; };
    const View* c     = static_cast<const View*>(self);
    int         depth = 1;
    if (pos >= c->size)
        return 2;
    UInt8 op;
    do
    {
        op = c->data[pos++];
        if (op == 0x10)
        {
            // jump
            const int off = Abc::ReadS24(c->data, pos);
            pos += off;
            continue;
        }
        const Sfr34_OpCodeInfo& oi = DAT_14317fea0[op];
        depth -= oi.pop;
        if (oi.pop_mn)
        {
            const int ind = Abc::ReadU30(c->data, pos);
            switch (c->holder->file->GetAbcFile().Const_Pool.GetMultiname(ind).Kind)
            {
            case Abc::MNF_RTQName:
            case Abc::MNF_RTQNameA:
            case Abc::MNF_MultinameL:
            case Abc::MNF_MultinameLA:
                depth -= 1;
                break;
            case Abc::MNF_RTQNameL:
            case Abc::MNF_RTQNameLA:
                depth -= 2;
                break;
            default:
                break;
            }
        }
        if (oi.pop_args)
        {
            const int n = Abc::ReadU30(c->data, pos);
            if (op == 0x55)
                depth -= n * 2;
            else
                depth -= n;
        }
        if (depth < 1)
            return op;
        depth += oi.push;
        if (oi.pop_mn || oi.pop_args)
            continue;
        if (op < 0x0c)
            ;
        else if (op < 0x1b)
        {
            // the branches
            Abc::ReadS24(c->data, pos);
            continue;
        }
        else if (op == 0x1b)
        {
            // lookupswitch
            Abc::ReadS24(c->data, pos);
            const int n = Abc::ReadU30(c->data, pos);
            for (int i = 0; i <= n; ++i)
                Abc::ReadS24(c->data, pos);
            continue;
        }
        else if (op == 0x24)
        {
            // pushbyte
            ++pos;
            continue;
        }
        else if (op == 0xef)
        {
            // debug
            ++pos;
            Abc::ReadU30(c->data, pos);
            ++pos;
            Abc::ReadU30(c->data, pos);
            continue;
        }
        switch (oi.operandCount)
        {
        case 2:
            Abc::ReadU30(c->data, pos);
            // fall through
        case 1:
            Abc::ReadU30(c->data, pos);
            break;
        default:
            break;
        }
    } while (pos < c->size);
    return op;
}

} } } // namespace Scaleform::GFx::AS3

void FUN_1424ef180(void* reader, const Scaleform::GFx::AS3::Value& v);    // StackReader::CheckObject
void FUN_142528d20(Scaleform::GFx::AS3::Multiname* mn, const Scaleform::GFx::AS3::Instances::Namespace* ns);   // Multiname::SetRTNamespace

// StackReader::Read(Multiname&): the run-time parts of a multiname off the operand stack: the name (of the late
// kinds), then the namespace (of the run-time qualified ones; an error unless it is an object). ctx is the reader
// {VM*, operand stack*}.
// MS2-FUNCTIONAL free function in the callers' (sfr_as3_19) form; StackReader is not in the shared headers
// @0x1425201f0
void FUN_1425201f0(void* ctx, void* multiname)
{
    using namespace Scaleform::GFx::AS3;
    struct Reader { VM* vm; ValueStack* stack; };
    Reader*    r  = static_cast<Reader*>(ctx);
    Multiname& mn = *static_cast<Multiname*>(multiname);
    for (;;)
    {
        switch (static_cast<Scaleform::UInt32>(mn.Kind))
        {
        case Abc::MNF_RTQNameL:
        case Abc::MNF_RTQNameLA:
            FUN_14251c8a0(mn, *r->stack);
            // fall through
        case Abc::MNF_RTQName:
        case Abc::MNF_RTQNameA:
        {
            FUN_1424ef180(r, *r->stack->GetTopPtr());
            if (r->vm->IsException())
                return;
            Value* top = r->stack->GetTopPtr();
            FUN_142528d20(&mn, &top->AsNamespace());
            top->~Value();
            r->stack->Release(1);
            return;
        }
        case Abc::MNF_MultinameL:
        case Abc::MNF_MultinameLA:
            FUN_14251c8a0(mn, *r->stack);
            return;
        case Abc::MNF_Typename:
            r->vm->GetUI().Output(FlashUI::Output_Warning, "Reading chained multiname in itself.");
            continue;
        default:
            return;
        }
    }
}

namespace Scaleform { namespace GFx { namespace AS3 {

// The vftable of NamespaceSet (the class has no out-of-line constructor; its virtuals are not modeled here).
extern const void* const DAT_14317b058;

// VMAbcFile::GetInternedNamespaceSet: the namespace set at constant pool index ind, made on first use from the
// interned namespaces its entry lists.
// MS2-FUNCTIONAL the set is built over a layout view (its constructor and virtuals are not in the shared header)
// @0x14250aff0
NamespaceSet& VMAbcFile::GetInternedNamespaceSet(UPInt ind)
{
    struct View
    {
        const void*                          vptr;
        ASRefCountCollector*                 gc;
        UInt32                               RefCount;
        UInt32                               pad;
        void*                                pad2;
        ArrayLH<SPtr<Instances::Namespace> > Namespaces;
    };
    if (ind >= IntNamespaceSets.GetSize())
        IntNamespaceSets.Resize(ind + 1);
    if (NamespaceSet* p = IntNamespaceSets[ind].GetPtr())
        return *p;
    View* v = static_cast<View*>(SF_HEAP_ALLOC(GetVM().GetMemoryHeap(), sizeof(View), StatMV_ActionScript_Mem));
    if (v)
    {
        v->vptr     = &DAT_14317b058;
        v->gc       = &GetVM().GetGC();
        v->RefCount = 1;
        ::new (&v->Namespaces) ArrayLH<SPtr<Instances::Namespace> >();
    }
    NamespaceSet* set = reinterpret_cast<NamespaceSet*>(v);
    IntNamespaceSets[ind] = Pickable<NamespaceSet>(set);
    const UInt8* data = GetAbcFile().Const_Pool.const_ns_set[ind].Data;
    const int    n    = Abc::ReadU30(data);
    for (int i = 0; i < n; ++i)
    {
        const int ns_ind = Abc::ReadU30(data);
        v->Namespaces.PushBack(SPtr<Instances::Namespace>(&GetInternedNamespace(ns_ind)));
    }
    return *IntNamespaceSets[ind];
}

CheckResult ExecutePropertyUnsafe(VM& vm, const Multiname& prop_name, const Value& _this, Value& result, unsigned argc,
                                  const Value* argv);   // 0x1424ff910

// The error e as text through the UI: its getStackTrace() when it has one, else (or when that gives null) e
// converted to a string.
// MS2-FUNCTIONAL the exe inlines the Multiname constructor
// @0x14251bdc0
void VM::OutputError(const Value& e)
{
    Value          result;
    ASString       msg = GetStringManager().CreateEmptyString();
    const Multiname mn(GetPublicNamespace(), Value(GetStringManager().CreateConstString("getStackTrace")));
    if (e.IsNullOrUndefined() || !ExecutePropertyUnsafe(*this, mn, e, result, 0, NULL) || result.Convert2String(msg))
    {
        if ((!e.IsNullOrUndefined() && msg.GetNode() != GetStringManager().GetBuiltin(AS3Builtin_null).GetNode()) || e.Convert2String(msg))
            GetUI().Output(FlashUI::Output_Error, msg.ToCStr());
    }
}

void FUN_1424187f0(Instances::fl::GlobalObjectScript* self);   // GlobalObjectScript: its classes' instance traits

// VMAbcFile::RegisterScrips: the traits and global object of each script of the file; the global objects are listed
// in the VM (unowned) and kept in the file's set, and the last script is run when to_execute.
// MS2-FUNCTIONAL the VM's global object list and the file's set are reached through casts (the shared header
// models them as SPtr array and raw table pointer)
// @0x142521390
bool VMAbcFile::RegisterScrips(bool to_execute)
{
    typedef HashSetLH<SPtr<Instances::fl::GlobalObjectScript> > TGlobalObjects;
    VM&              vm   = GetVM();
    const Abc::File& file = GetAbcFile();
    const UPInt      n    = file.Scripts.Info.GetSize();
    for (UPInt i = 0; i < n; ++i)
    {
        const Abc::ScriptInfo& script = *file.Scripts.Info[i];
        SPtr<InstanceTraits::fl::GlobalObjectScript> itr = Pickable<InstanceTraits::fl::GlobalObjectScript>(
            SF_HEAP_NEW(vm.GetMemoryHeap()) InstanceTraits::fl::GlobalObjectScript(*this, vm, script));
        if (vm.IsException())
            return false;
        SPtr<Instances::fl::GlobalObjectScript> gos = itr->FUN_14241aa60();
        if (vm.IsException())
            return false;
        reinterpret_cast<ArrayLH<Instances::fl::GlobalObject*>&>(vm.GlobalObjects).PushBack(gos.GetPtr());
        reinterpret_cast<TGlobalObjects*>(&GlobalObjectsTable)->Set(gos);
        FUN_1424187f0(gos.GetPtr());
    }
    if (to_execute && n != 0)
        static_cast<Instances::fl::GlobalObjectScript*>(vm.GlobalObjects.Back().GetPtr())->Execute();
    return !vm.IsException();
}

void FUN_142530de0(VMAbcFile* file);   // VMAbcFile: the loaded classes' traits unregistered (a failed load)

// VMAbcFile::RegisterUserDefinedClassTraits: the class traits of the file's classes (except the scaleform.gfx
// package's): ones known to the VM (cached, or from the global object, then cached) only add their file to the
// children; the others are made, cached and kept as loaded classes. Then the new ones are initialized; on a failure
// the error is output, the class uncached, the loaded classes unregistered and false returned.
// MS2-FUNCTIONAL the scaleform.gfx test and the class traits cache are reached through the shared helpers
// @0x142521780
bool VMAbcFile::RegisterUserDefinedClassTraits()
{
    VM&                    vm      = GetVM();
    const Abc::ClassTable& classes = GetAbcFile().AS3_Classes;
    UPInt                  made    = 0;
    for (UPInt i = 0; i < classes.Info.GetSize(); ++i)
    {
        const Abc::ClassInfo& ci   = *classes.Info[i];
        const Abc::Multiname& mn   = GetAbcFile().Const_Pool.GetMultiname(ci.inst_info.name_ind);
        const ASString        name = GetInternedString(mn.NameIndex);
        Instances::Namespace& ns   = GetInternedNamespace(mn.Ind);
        const ASString&       uri  = ns.GetUri();
        if (uri.GetSize() >= DAT_143a2dd40.GetSize() &&
            strncmp(uri.ToCStr(), DAT_143a2dd40.ToCStr(), DAT_143a2dd40.GetSize()) == 0)
            continue;
        ClassTraits::Traits** p   = FUN_142414ac0(&vm.ClassTraitsSet, name, ns);
        ClassTraits::Traits*  ctr = p ? *p : NULL;
        if (!ctr)
        {
            ctr = FUN_142415520(vm.GlobalObject.GetPtr(), name, ns);
            if (!ctr)
            {
                SPtr<ClassTraits::Traits> ud = Pickable<ClassTraits::Traits>(
                    SF_HEAP_NEW(vm.GetMemoryHeap()) ClassTraits::UserDefined(*this, vm, ci));
                vm.ClassTraitsSet.Add(name, ns, ud.GetPtr());
                ++made;
                LoadedClasses.PushBack(ud);
                continue;
            }
            vm.ClassTraitsSet.Add(name, ns, ctr);
        }
        if (VMAbcFile* f = ctr->GetFilePtr())
        {
            UPInt j = 0;
            while (j < Children.GetSize() && Children[j].GetPtr() != f)
                ++j;
            if (j == Children.GetSize())
                Children.PushBack(SPtr<VMAbcFile>(f));
        }
    }
    if (made == 0)
        return true;
    for (UPInt i = 0; i < classes.Info.GetSize(); ++i)
    {
        const Abc::ClassInfo& ci   = *classes.Info[i];
        const Abc::Multiname& mn   = GetAbcFile().Const_Pool.GetMultiname(ci.inst_info.name_ind);
        const ASString        name = GetInternedString(mn.NameIndex);
        Instances::Namespace& ns   = GetInternedNamespace(mn.Ind);
        const ASString&       uri  = ns.GetUri();
        if (uri.GetSize() >= DAT_143a2dd40.GetSize() &&
            strncmp(uri.ToCStr(), DAT_143a2dd40.ToCStr(), DAT_143a2dd40.GetSize()) == 0)
            continue;
        ClassTraits::Traits* ctr = FUN_14250f9a0(vm, *this, ci);
        if (&static_cast<ClassTraits::UserDefined*>(ctr)->GetFile() != this || ctr->FUN_142418970())
            continue;
        if (vm.HandleException)
        {
            vm.HandleException = false;
            vm.OutputError(vm.ExceptionObj);
            vm.ExceptionObj.SetUndefined();
        }
        vm.ClassTraitsSet.Entries.RemoveAlt(TClassTraitsCache::Key(name, &ns));
        FUN_142530de0(this);
        return false;
    }
    return true;
}

// sfr34 batch AD: the link, mouse and character events of an AS3 text field (AvmTextFieldBase slots 25..27).

// The document of a text field's DocView (+0x10), its URL flag (RTFlags +0x40 bit 0), the formats at a position and
// the character at a point, bound to the exe (the text headers do not fit this unit's partial models).
bool  FUN_1425996b0(void* styledText, const Render::Text::TextFormat** ppfmt, const void** pppara, UPInt pos);
UPInt FUN_142612240(Render::Text::DocView* doc, float x, float y);   // DocView::GetCharIndexAtPoint
static inline void* Sfr34_StyledTextOf(Render::Text::DocView* doc)
{
    return *reinterpret_cast<void**>(reinterpret_cast<char*>(doc) + 0x10);
}
static inline bool Sfr34_MayHaveUrl(Render::Text::DocView* doc)
{
    return (*(static_cast<const UInt8*>(Sfr34_StyledTextOf(doc)) + 0x40) & 1) != 0;
}

// The AvmTextField of its AvmTextFieldBase part (+0x40), and the text field it is the AVM part of.
static inline AvmDisplayObj* Sfr34_TextFieldAvm(UPInt self)
{
    return reinterpret_cast<AvmDisplayObj*>(self - 0x40);
}
static inline TextField* Sfr34_TextFieldOf(const AvmDisplayObj* avm)
{
    return reinterpret_cast<TextField*>(avm->pDispObj);
}

// The event (TextEventEx with the extensions on, else TextEvent) of the type name, bubbling and cancelable, with
// obj as target.
static inline SPtr<Instances::fl_events::TextEvent> Sfr34_CreateTextEvent(ASVM* asvm, const ASString& name,
                                                                         Instances::fl_display::DisplayObject* obj,
                                                                         bool ex)
{
    SPtr<Instances::fl_events::TextEvent> evt;
    const Value params[] = { Value(name), Value(true), Value(true) };
    asvm->ConstructInstance(evt, ex ? asvm->TextEventExClass : asvm->TextEventClass, 3, params);
    FUN_14243d870(&evt->Target, obj);
    return evt;
}

// AvmTextField::OnLinkEventEx: with the extensions on, the rolling over (or out of) a link gives a
// "linkMouseOver" ("linkMouseOut") TextEventEx with the link's URL to the AS3 object when it listens for it.
// MS2-FUNCTIONAL free function on the subobject this (AvmTextField is opaque in the shared header)
// @0x14251a500
void FUN_14251a500(UPInt self, TextField::LinkEvent event, unsigned pos, unsigned controllerIndex)
{
    AvmDisplayObj* avm  = Sfr34_TextFieldAvm(self);
    MovieRoot*     root = AS3RootOf(avm->pDispObj);
    Sfr34_CheckAvm(root);
    const Render::Text::TextFormat* fmt;
    if (!root->pAVM->ExtensionsEnabled ||
        !FUN_1425996b0(Sfr34_StyledTextOf(Sfr34_TextFieldOf(avm)->GetDocument()), &fmt, NULL, pos) ||
        !fmt->IsUrlSet())
        return;
    const char* url = fmt->GetUrl().ToCStr();
    const char* type;
    switch (event)
    {
    case TextField::Link_rollover: type = "linkMouseOver"; break;
    case TextField::Link_rollout:  type = "linkMouseOut";  break;
    default: return;
    }
    const ASString                        name(root->GetStringManager418()->CreateStringNode(type));
    Instances::fl_display::DisplayObject* obj  = avm->GetAS3Obj();
    if (obj->WillTrigger(name, false))
    {
        SPtr<Instances::fl_events::TextEvent> evt = Sfr34_CreateTextEvent(root->pAVM, name, obj, true);
        evt->Text = ASString(root->GetStringManager418()->CreateStringNode(url));
        static_cast<Instances::fl_gfx::TextEventEx*>(evt.GetPtr())->controllerIdx = controllerIndex;
        obj->DispatchEventObject(evt, avm->pDispObj);
    }
}

int FUN_142586720(const char* a, const char* b, SPInt len);   // String::CompareNoCase(a, b, len)

// AvmTextField::OnMouseEvent: a click (not ending a selection) on an "event:" link of an HTML field gives a "link"
// TextEvent with the rest of the URL to the AS3 object when it listens for it; true for any click.
// MS2-FUNCTIONAL free function on the subobject this (AvmTextField is opaque in the shared header)
// @0x14251a8a0
bool FUN_14251a8a0(UPInt self, const EventId& event)
{
    AvmDisplayObj* avm = Sfr34_TextFieldAvm(self);
    static_cast<AvmInteractiveObj*>(avm)->AvmInteractiveObj::OnEvent(event);
    if (event.Id != AS3Event_Click)
        return false;
    TextField* ptf = Sfr34_TextFieldOf(avm);
    if (ptf->GetBeginIndex() != ptf->GetEndIndex())
        return false;
    Render::PointF                  p;
    const Render::Text::TextFormat* fmt;
    Render::Text::DocView*          doc = ptf->GetDocument();
    if (!ptf->IsHtml() || !Sfr34_MayHaveUrl(doc) || !ptf->IsUrlUnderMouseCursor(event.MouseIndex, &p))
        return true;
    const UPInt pos = FUN_142612240(doc, p.x, p.y);
    if (pos == SF_MAX_UPINT || !FUN_1425996b0(Sfr34_StyledTextOf(doc), &fmt, NULL, pos) || !fmt->IsUrlSet())
        return true;
    const char* url  = fmt->GetUrl().ToCStr();
    MovieRoot*  root = AS3RootOf(avm->pDispObj);
    if (!avm->GetMovieImpl() || FUN_142586720(url, "event:", 6) != 0)
        return true;
    const ASString                        name(root->GetStringManager418()->CreateStringNode("link"));
    Instances::fl_display::DisplayObject* obj  = avm->GetAS3Obj();
    if (obj->WillTrigger(name, false))
    {
        ASVM*                                 asvm = root->pAVM;
        SPtr<Instances::fl_events::TextEvent> evt  = Sfr34_CreateTextEvent(asvm, name, obj, asvm->ExtensionsEnabled);
        evt->Text = ASString(root->GetStringManager418()->CreateStringNode(url + 6));
        if (asvm->ExtensionsEnabled)
        {
            Instances::fl_gfx::TextEventEx* ex = static_cast<Instances::fl_gfx::TextEventEx*>(evt.GetPtr());
            ex->controllerIdx = event.ControllerIndex;
            ex->buttonIdx     = event.ButtonId;
        }
        obj->DispatchEventObject(evt, avm->pDispObj);
    }
    return true;
}

// AvmTextField::OnCharEvent: a "textInput" TextEvent of the character to the AS3 object when it listens for it;
// false when the event's default action was prevented.
// MS2-FUNCTIONAL free function on the subobject this (AvmTextField is opaque in the shared header)
// @0x142518750
bool FUN_142518750(UPInt self, wchar_t wcharCode, unsigned controllerIdx)
{
    AvmDisplayObj*                        avm  = Sfr34_TextFieldAvm(self);
    MovieRoot*                            root = AS3RootOf(avm->pDispObj);
    Instances::fl_display::DisplayObject* obj  = avm->GetAS3Obj();
    const ASString&                       name = root->BuiltinsMgr.GetBuiltin(AS3Builtin_textInput);
    if (!obj->WillTrigger(name, false))
        return true;
    ASVM*                                 asvm = root->pAVM;
    SPtr<Instances::fl_events::TextEvent> evt  = Sfr34_CreateTextEvent(asvm, name, obj, asvm->ExtensionsEnabled);
    evt->SetText(wcharCode);
    if (asvm->ExtensionsEnabled)
        static_cast<Instances::fl_gfx::TextEventEx*>(evt.GetPtr())->controllerIdx = controllerIdx;
    return obj->DispatchEventObject(evt, avm->pDispObj);
}

// sfr34 batch AE: the firing of an interval timer.

} } } // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace GFx { namespace AS3 {

// Once its invoke time is reached: a Timer's event (while under its repeat count) or the setInterval function
// (an exception printed and dropped); then the timer stops (a timeout, or the repeat count reached) or its next
// invoke time is a whole number of intervals (at least a tenth of the frame) past the current one.
// MS2-FUNCTIONAL register allocation differs (the exe keeps the zero in r14 only on the function path)
// @0x142512fc0
bool IntervalTimer::Invoke(MovieImpl* proot, float frameTime)
{
    if (!Active)
        return false;
    MovieRoot*   asroot      = static_cast<MovieRoot*>(proot->pASMovieRoot);
    const UInt64 currentTime = proot->TimeElapsed;
    bool         retval      = false;
    if (currentTime >= InvokeTime)
    {
        if (TimerObj)
        {
            if (RepeatCount == 0 || CurrentCount < RepeatCount)
            {
                ++CurrentCount;
                TimerObj->ExecuteEvent();
            }
        }
        else
        {
            VM&   vm = *asroot->pAVM;
            Value _this;
            Value result;
            vm.ExecuteInternalUnsafe(Function, _this, result, unsigned(Params.GetSize()), Params.GetDataPtr(), false);
            if (vm.HandleException)
            {
                vm.HandleException = false;
                vm.OutputError(vm.ExceptionObj);
                vm.ExceptionObj.SetUndefined();
            }
        }
        if (Timeout || (RepeatCount != 0 && CurrentCount >= RepeatCount))
            Active = false;
        else
        {
            const UInt64 frameMks = UInt64(frameTime * 1000000.f);
            UInt64       next     = 0;
            if (RepeatCount == 0 || CurrentCount < RepeatCount)
            {
                UInt64 interval = Interval;
                if (interval < frameMks / 10)
                    interval = unsigned(frameMks / 10);
                if (interval != 0)
                    next = (currentTime - InvokeTime + interval) / interval * interval;
            }
            if (next > 0)
                InvokeTime += next;
            else
                InvokeTime = currentTime;
        }
        retval = true;
    }
    return retval;
}

} } } // namespace Scaleform::GFx::AS3

void FUN_142501b00(Scaleform::GFx::AS3::PropRef& result, Scaleform::GFx::AS3::VM& vm,
                   const Scaleform::GFx::AS3::Value& value, const Scaleform::GFx::AS3::Multiname& mn,
                   int attr);   // FindObjProperty

namespace Scaleform { namespace GFx { namespace AS3 {

// The property prop_name of this object (its slot or dynamic value, getters run) swapped into value; false when
// there is none or it could not be read.
// MS2-FUNCTIONAL PropRef::GetSlotValueUnsafe written out (the exe inlines it; the shared header defines it out of line)
// @0x14250cc60
CheckResult Object::GetProperty(const Multiname& prop_name, Value& value)
{
    VM&     vm = GetVM();
    PropRef prop;
    FUN_142501b00(prop, vm, Value(this), prop_name, 0);
    const UPInt bits = reinterpret_cast<UPInt>(prop.pValue);
    if (prop.This.IsUndefined() || bits == 1 || ((bits & 2) != 0 && (bits & ~UPInt(2)) == 0))
        return false;
    Value v;
    switch (bits & 3)
    {
    case 0:
    {
        CheckResult r(false);
        if (!*FUN_14250e2d0(prop.pSI, &r, &vm, &v, &prop.This, NULL, 0))
            return false;
        break;
    }
    case 1:
        v = *reinterpret_cast<const Value*>(bits & ~UPInt(1));
        break;
    case 2:
        v = Value(reinterpret_cast<Object*>(bits & ~UPInt(2)));
        break;
    }
    value.Swap(v);
    return true;
}

} } } // namespace Scaleform::GFx::AS3

// Object::GetProperty(name, ns, value): the property name of namespace ns (FindObjProperty, then its value read
// into value, getters run); false when there is none or it could not be read.
// MS2-FUNCTIONAL free function returning its CheckResult through ret, as sfr_as3_17 declares it
// @0x14250dd20
Scaleform::UByte* FUN_14250dd20(Scaleform::GFx::AS3::Object* self, Scaleform::UByte* ret,
                                const Scaleform::GFx::ASString* name, Scaleform::GFx::AS3::Instances::Namespace* ns,
                                Scaleform::GFx::AS3::Value* value)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    VM&     vm = self->GetVM();
    PropRef prop;
    {
        const Multiname mn(*ns, Value(*name));
        FUN_142501b00(prop, vm, Value(self), mn, 0);
    }
    const UPInt bits = reinterpret_cast<UPInt>(prop.pValue);
    if (prop.This.IsUndefined() || bits == 1 || ((bits & 2) != 0 && (bits & ~UPInt(2)) == 0))
    {
        *ret = false;
        return ret;
    }
    switch (bits & 3)
    {
    case 0:
    {
        CheckResult r(false);
        if (!*FUN_14250e2d0(prop.pSI, &r, &vm, value, &prop.This, NULL, 0))
        {
            *ret = false;
            return ret;
        }
        break;
    }
    case 1:
        value->AssignUnsafe(*reinterpret_cast<const Value*>(bits & ~UPInt(1)));
        break;
    case 2:
        value->AssignUnsafe(reinterpret_cast<Object*>(bits & ~UPInt(2)));
        break;
    }
    *ret = true;
    return ret;
}

namespace Scaleform { namespace GFx { namespace AS3 {

} } } // namespace Scaleform::GFx::AS3

// SlotInfo::GetSlotValueUnsafe(Value&, Object*): the value of the slot of obj: a stored value (of the global
// object's value array, a Value, an object, a primitive, a string, a constant C string), a method (as a closure of
// obj), or the result of the getter. False (with a TypeError or ReferenceError raised for a non-callable getter or a
// write-only property) when the slot has no value.
// MS2-FUNCTIONAL free function (not declared in the shared SlotInfo class); the slot is read over its address
// @0x14250e770
char* FUN_14250e770(const Scaleform::GFx::AS3::SlotInfo* psi, char* r, Scaleform::GFx::AS3::Value* pvalue,
                    Scaleform::GFx::AS3::Object* obj)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    const SlotInfo& si    = *psi;
    Value&          value = *pvalue;
    const SInt32    ind   = si.ValueInd;
    const UPInt     base  = reinterpret_cast<UPInt>(obj);
    switch (si.BindType)
    {
    case SlotInfo::BT_ValueArray:
        value.AssignUnsafe(reinterpret_cast<const Value*>(*reinterpret_cast<const UPInt*>(base + 0xa8))[UInt32(ind)]);
        break;
    case SlotInfo::BT_Value:
        value.AssignUnsafe(*reinterpret_cast<const Value*>(base + UInt32(ind)));
        break;
    case SlotInfo::BT_ObjectAS:
        reinterpret_cast<STPtr*>(base + UInt32(ind))->GetValueUnsafe(value);
        break;
    case SlotInfo::BT_ObjectCpp:
        value.AssignUnsafe(*reinterpret_cast<const SPtr<Instances::fl::GlobalObjectCPP>*>(base + UInt32(ind)));
        break;
    case SlotInfo::BT_Boolean:
        value.SetBoolUnsafe(*reinterpret_cast<const bool*>(base + UInt32(ind)));
        break;
    case SlotInfo::BT_Int:
        value.SetSInt32Unsafe(*reinterpret_cast<const SInt32*>(base + UInt32(ind)));
        break;
    case SlotInfo::BT_UInt:
        value.SetUInt32Unsafe(*reinterpret_cast<const UInt32*>(base + UInt32(ind)));
        break;
    case SlotInfo::BT_Number:
        value.SetNumberUnsafe(*reinterpret_cast<const Value::Number*>(base + UInt32(ind)));
        break;
    case SlotInfo::BT_String:
        if (GFx::ASStringNode* node = *reinterpret_cast<GFx::ASStringNode* const*>(base + UInt32(ind)))
            value.AssignUnsafe(node);
        else
            value.SetNullUnsafe();   // null is an object, not a string
        break;
    case 10:   // a constant C string (4.1.18 numbers this binding before BT_Code)
        value.AssignUnsafe(obj->GetVM().GetStringManager().CreateConstString(
            *reinterpret_cast<const char* const*>(base + UInt32(ind))));
        break;
    case SlotInfo::BT_Code:
        FUN_14250ba10(&obj->GetTraits().GetVT(), value, AbsoluteIndex(ind), obj);
        break;
    case SlotInfo::BT_Get:
    case SlotInfo::BT_GetSet:
    {
        const Value getter = obj->GetTraits().GetVT().GetValue(AbsoluteIndex(ind));
        VM&         vm     = obj->GetVM();
        if (!getter.IsCallable())
        {
            const VM::Error e(VM::eCallOfNonFunctionError, vm, obj->GetTraits().GetName().ToCStr());
            FUN_14252ecb0(&vm, &e, &fl::TypeErrorCI);
            *r = false;
            return r;
        }
        vm.ExecuteInternalUnsafe(getter, Value(obj), value, 0, NULL, false);
        break;
    }
    case SlotInfo::BT_Set:
    {
        VM&             vm = obj->GetVM();
        const VM::Error e(static_cast<VM::ErrorID>(1077) /* eWriteOnlyError */, vm, si.Name->pData,
                          obj->GetTraits().GetName().ToCStr());
        FUN_14252ecb0(&vm, &e, &fl::ReferenceErrorCI);
    }
        // fall through
    default:
        *r = false;
        return r;
    }
    *r = true;
    return r;
}

namespace Scaleform { namespace GFx { namespace AS3 {

// ObjectInterface::GetMember: the public property name of the AS3 object; for a display object container without
// such a property, its child of that name. undefined (and false) when neither is there; an exception of the
// property lookup is output (of the child lookup, dropped).
// MS2-FUNCTIONAL member of a view over the AS3 value object interface (the class is sfr_as3_17's); the exe inlines AvmDisplayObjContainer::GetAS3ChildByName
// @0x14250b4a0
bool Sfr34_ValueObjIfc::GetMember(void* pdata, const char* name, GFx::Value* pval, bool isdobj) const
{
    SF_UNUSED(isdobj);
    MovieRoot* root = GetAS3Root();
    VM*        vm   = root->pAVM;
    Object*    obj  = static_cast<Object*>(pdata);
    Value      asval;
    {
        const Multiname mn(vm->GetPublicNamespace(), Value(ASString(root->GetStringManager418()->CreateStringNode(name))));
        if (obj->GetProperty(mn, asval))
        {
            root->ASValue2GFxValue(asval, pval);
            return true;
        }
    }
    const Traits& tr = obj->GetTraits();
    if ((unsigned)(tr.GetTraitsType() - Traits_DisplayObjectContainer) <
            (unsigned)(Traits_DisplayObject_End - Traits_DisplayObjectContainer) &&
        tr.IsInstanceTraits())
    {
        DisplayObject*          dobj  = Sfr34_DispObjOf(pdata);
        AvmDisplayObjContainer* pcurr = Sfr34_ToAvmContainer(dobj->IsDisplayObjContainer() ? dobj : NULL);
        const ASString propName(root->GetStringManager418()->CreateStringNode(name));
        SPtr<Instances::fl_display::DisplayObject> pchild = pcurr->GetAS3ChildByName(propName);
        if (pchild)
        {
            asval = Value(pchild);
            root->ASValue2GFxValue(asval, pval);
            return true;
        }
        if (vm->IsException())
            vm->HandleException = false;
        pval->SetUndefined();
        return false;
    }
    if (vm->IsException())
        vm->OutputAndIgnoreException();
    pval->SetUndefined();
    return false;
}

// The scriptable visible children under pt (topmost first), each in its own coordinates; none when the
// container is invisible or pt is outside its mask. True when any was added.
// MS2-FUNCTIONAL the exe's frame is 0x10 smaller (it shares one world matrix temporary)
// @0x14250c360
bool AvmDisplayObjContainer::GetObjectsUnderPoint(ArrayDH<Ptr<DisplayObjectBase> >* destArray,
                                                  const Render::PointF& pt) const
{
    const DisplayObjContainer* dobjParent = GetDisplayObjContainer();
    if (!dobjParent->GetVisible())
        return false;
    const DisplayList& dl = dobjParent->mDisplayList;
    const SPInt        n  = SPInt(dl.GetCount());
    if (DisplayObject* pmask = dobjParent->GetMask())
    {
        if (pmask->IsUsedAsMask() && !pmask->IsUnloaded())
        {
            Render::Matrix2F matrix, wm;
            pmask->GetWorldMatrix(&wm);
            matrix.SetInverse(wm);
            dobjParent->GetWorldMatrix(&wm);
            matrix.Prepend(wm);
            const Render::PointF p = matrix.Transform(pt);
            if (!pmask->PointTestLocal(p, DisplayObjectBase::HitTest_TestShape | DisplayObjectBase::HitTest_IgnoreInvisible))
                return false;
        }
    }
    Array<UByte> hitTest;
    dobjParent->CalcDisplayListHitTestMaskArray(&hitTest, pt, true);
    Render::PointF p     = pt;
    const UPInt    oldSz = destArray->GetSize();
    for (SPInt i = n - 1; i >= 0; i--)
    {
        DisplayObjectBase* pch = dl.GetDisplayObject(UPInt(i));
        if (!pch->IsScriptableObject() || !pch->GetVisible())
            continue;
        if (hitTest.GetSize() && (!hitTest[UPInt(i)] || pch->ClipDepth != 0))
            continue;
        const Render::Matrix2F& m = pch->GetMatrix();
        p = m.TransformByInverse(pt);
        ToAvmDisplayObj(pch)->GetObjectsUnderPoint(destArray, p);
    }
    return destArray->GetSize() > oldSz;
}

} } } // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx {
// The return value holder of the movie (as sfr_gfx_01i defines it).
struct MovieImpl::ReturnValueHolder : public NewOverrideBase<0x147>   // StatMV_Other_Mem
{
    char*                     CharBuffer;       // +0x00
    unsigned                  CharBufferSize;   // +0x08
    ArrayCC<ASString, 0x147>  StringArray;      // +0x10 (default value +0x28)
    unsigned                  StringArrayPos;   // +0x30

    ReturnValueHolder(ASStringManager* pstrMgr)
        : CharBuffer(0), CharBufferSize(0), StringArray(pstrMgr->CreateConstString("")), StringArrayPos(0) {}
    ~ReturnValueHolder()
    {
        if (CharBuffer)
            SF_FREE(CharBuffer);
    }
};
} } // namespace Scaleform::GFx

namespace Scaleform { namespace GFx { namespace AS3 {

// The strings of the holder are at least one.
static inline void Sfr34_ResizeStringArray(MovieImpl::ReturnValueHolder* h, unsigned n)
{
    h->StringArray.Resize(Alg::Max(1u, n));
}

// count elements of the AS3 array at the path from index on, into the host's array of ints, floats, doubles,
// strings (kept alive by the movie's return value holder), wide strings (in its character buffer) or values.
// Undefined elements give 0 (NULL for strings). False when the path is not an array.
// MS2-FUNCTIONAL a 4.1.18 virtual of the root; the exe saves fewer registers in its prolog
// @0x142510240
bool MovieRoot::GetVariableArray(SetArrayTypeArg type, const char* ppathToVar, unsigned index, void* pdata,
                                 unsigned count)
{
    Value resolvedVal;
    if (!FUN_142506000(this, &resolvedVal, ppathToVar) || !resolvedVal.IsObject())
        return false;
    Object* pobj = resolvedVal.GetObject();
    if (!pobj || pobj->GetTraits().GetTraitsType() != Traits_Array || !pobj->GetTraits().IsInstanceTraits())
        return false;
    MovieImpl::ReturnValueHolder* rvHolder = pMovieImpl->GetRetValHolder();
    rvHolder->StringArrayPos = 0;
    Sfr34_ResizeStringArray(rvHolder, 0);
    SparseArray&       sa      = static_cast<Instances::fl::Array*>(pobj)->SA;
    const unsigned     arrSize = unsigned(sa.GetSize());
    switch (type)
    {
    case 0:   // SA_Int
    {
        int* parr = static_cast<int*>(pdata);
        for (unsigned i = 0, n = Alg::Min(arrSize, count); i < n; ++i)
        {
            const Value& val = sa.At(i + index);
            parr[i] = !val.IsUndefined() ? val.AsInt() : 0;
        }
    }
        // fall through
    case 2:   // SA_Float
    {
        float* parr = static_cast<float*>(pdata);
        for (unsigned i = 0, n = Alg::Min(arrSize, count); i < n; ++i)
        {
            const Value& val = sa.At(i + index);
            parr[i] = !val.IsUndefined() ? float(val.AsNumber()) : 0.0f;
        }
        break;
    }
    case 1:   // SA_Double
    {
        Double* parr = static_cast<Double*>(pdata);
        for (unsigned i = 0, n = Alg::Min(arrSize, count); i < n; ++i)
        {
            const Value& val = sa.At(i + index);
            parr[i] = !val.IsUndefined() ? val.AsNumber() : 0.0;
        }
        break;
    }
    case 5:   // SA_Value
    {
        GFx::Value* parr = static_cast<GFx::Value*>(pdata);
        for (unsigned i = 0, n = Alg::Min(arrSize, count); i < n; ++i)
        {
            const Value& val      = sa.At(i + index);
            GFx::Value*  pdestVal = &parr[i];
            pdestVal->SetUndefined();
            if (!val.IsUndefined())
                ASValue2GFxValue(val, pdestVal);
        }
        break;
    }
    case 3:   // SA_String
    {
        const char**   parr = static_cast<const char**>(pdata);
        const unsigned n    = Alg::Min(arrSize, count);
        Sfr34_ResizeStringArray(rvHolder, n);
        for (unsigned i = 0; i < n; ++i)
        {
            const Value& val = sa.At(i + index);
            if (!val.IsUndefined())
            {
                ASString str = val.AsString();
                parr[i]      = str.ToCStr();
                rvHolder->StringArray[rvHolder->StringArrayPos++] = str;
            }
            else
                parr[i] = NULL;
        }
        break;
    }
    case 4:   // SA_StringW
    {
        const wchar_t** parr    = static_cast<const wchar_t**>(pdata);
        unsigned        bufSize = 0;
        const unsigned  n       = Alg::Min(arrSize, count);
        Sfr34_ResizeStringArray(rvHolder, n);
        for (unsigned i = 0; i < arrSize; ++i)
        {
            const Value& val = sa.At(i + index);
            if (!val.IsUndefined())
            {
                ASString str            = val.AsString();
                rvHolder->StringArray[i] = str;
                bufSize += str.GetLength() + 1;
            }
        }
        const unsigned size = (bufSize * unsigned(sizeof(wchar_t)) + 4095) & ~4095u;
        if (rvHolder->CharBufferSize < size ||
            (rvHolder->CharBufferSize > size && rvHolder->CharBufferSize - size > 4096))
        {
            if (rvHolder->CharBuffer)
                rvHolder->CharBuffer = static_cast<char*>(SF_REALLOC(rvHolder->CharBuffer, size, 0x147));
            else
                rvHolder->CharBuffer = static_cast<char*>(SF_ALLOC(size, 0x147));
            rvHolder->CharBufferSize = size;
        }
        wchar_t* pwBuffer = reinterpret_cast<wchar_t*>(rvHolder->CharBuffer);
        for (unsigned i = 0; i < n; ++i)
        {
            const char* psrcStr  = rvHolder->StringArray[i].ToCStr();
            wchar_t*    pwdstStr = pwBuffer;
            UInt32      code;
            while ((code = UTF8Util::DecodeNextChar(&psrcStr)) != 0)
                *pwBuffer++ = wchar_t(code);
            *pwBuffer++ = 0;
            parr[i]     = pwdstStr;
        }
        Sfr34_ResizeStringArray(rvHolder, 0);
        break;
    }
    default:
        break;
    }
    return true;
}

// ObjectInterface::HasMember: whether the AS3 object has a property of that public name or, as a display object
// container, a child of that name (an exception of the child lookup is dropped).
// MS2-FUNCTIONAL member of a view over the AS3 value object interface (the class is sfr_as3_17's); the exe inlines AvmDisplayObjContainer::GetAS3ChildByName
// @0x142510e70
bool Sfr34_ValueObjIfc::HasMember(void* pdata, const char* name, bool isdobj) const
{
    SF_UNUSED(isdobj);
    MovieRoot* root = GetAS3Root();
    VM*        vm   = root->pAVM;
    Object*    obj  = static_cast<Object*>(pdata);
    const Multiname mn(root->pAVM->GetPublicNamespace(), Value(ASString(root->GetStringManager418()->CreateStringNode(name))));
    PropRef prop;
    obj->FindProperty(prop, mn, 0);
    const UPInt bits  = reinterpret_cast<UPInt>(prop.pValue);
    const bool  found = !(prop.This.IsUndefined() || bits == 1 || ((bits & 2) != 0 && (bits & ~UPInt(2)) == 0));
    const Traits& tr  = obj->GetTraits();
    if (found ||
        (unsigned)(tr.GetTraitsType() - Traits_DisplayObjectContainer) >=
            (unsigned)(Traits_DisplayObject_End - Traits_DisplayObjectContainer) ||
        !tr.IsInstanceTraits())
        return found;
    DisplayObject*          dobj  = Sfr34_DispObjOf(pdata);
    AvmDisplayObjContainer* pcurr = Sfr34_ToAvmContainer(dobj->IsDisplayObjContainer() ? dobj : NULL);
    const ASString          propName(root->GetStringManager418()->CreateStringNode(name));
    if (pcurr->GetAS3ChildByName(propName))
        return true;
    if (vm->IsException())
        vm->HandleException = false;
    return false;
}

// ObjectInterface::Invoke: the method of that public name of the AS3 object called on it with the host's
// arguments; the result (when asked for) converted for the host. An exception of the lookup or the call is output;
// false then, and when there is no such property.
// MS2-FUNCTIONAL member of a view over the AS3 value object interface (the class is sfr_as3_17's); PropRef::GetSlotValueUnsafe written out (the exe inlines it)
// @0x142512870
bool Sfr34_ValueObjIfc::Invoke(void* pdata, GFx::Value* presult, const char* name, const GFx::Value* pargs,
                               UPInt nargs, bool isdobj)
{
    SF_UNUSED(isdobj);
    MovieRoot* root = GetAS3Root();
    VM*        vm   = root->pAVM;
    const Multiname mn(vm->GetPublicNamespace(), Value(ASString(root->GetStringManager418()->CreateStringNode(name))));
    PropRef prop;
    static_cast<Object*>(pdata)->FindProperty(prop, mn, 0);
    const UPInt bits = reinterpret_cast<UPInt>(prop.pValue);
    if (prop.This.IsUndefined() || bits == 1 || ((bits & 2) != 0 && (bits & ~UPInt(2)) == 0))
        return false;
    Value asfn;
    Value asresult;
    switch (bits & 3)
    {
    case 0:
    {
        CheckResult r(false);
        if (!*FUN_14250e2d0(prop.pSI, &r, vm, &asfn, &prop.This, NULL, 0))
            goto exception;
        break;
    }
    case 1:
        asfn = *reinterpret_cast<const Value*>(bits & ~UPInt(1));
        break;
    case 2:
        asfn = Value(reinterpret_cast<Object*>(bits & ~UPInt(2)));
        break;
    }
    if (nargs)
    {
        Array<Value> args(static_cast<int>(nargs));
        for (UPInt i = 0; i < nargs; i++)
            root->GFxValue2ASValue(pargs[i], &args[i]);
        vm->ExecuteInternalUnsafe(asfn, Value(static_cast<Object*>(pdata)), asresult, static_cast<unsigned>(nargs),
                                  &args[0], false);
    }
    else
        vm->ExecuteInternalUnsafe(asfn, Value(static_cast<Object*>(pdata)), asresult, 0, NULL, false);
    if (!vm->IsException())
    {
        if (presult)
            root->ASValue2GFxValue(asresult, presult);
        return true;
    }
exception:
    vm->HandleException = false;
    vm->OutputError(vm->ExceptionObj);
    vm->ExceptionObj.SetUndefined();
    return false;
}

// ObjectInterface::InvokeClosure: a closure of the AS3 object (a VTable index closure when bit 1 of pdata is set,
// with dataAux its index, else a thunk closure of the thunk dataAux) called on it with the host's arguments.
// MS2-FUNCTIONAL member of a view over the AS3 value object interface (the class is sfr_as3_17's)
// @0x142513920
bool Sfr34_ValueObjIfc::InvokeClosure(void* pdata, UPInt dataAux, GFx::Value* presult, const GFx::Value* pargs,
                                      UPInt nargs)
{
    MovieRoot* root = GetAS3Root();
    VM*        vm   = root->pAVM;
    Value      asfn;
    Value      asresult;
    Object*    pobj = reinterpret_cast<Object*>(reinterpret_cast<UPInt>(pdata) & ~UPInt(2));
    if (reinterpret_cast<UPInt>(pdata) & 2)
        asfn = Sfr34_Closure(Value::kVTableIndClosure, reinterpret_cast<const void*>(UPInt(UInt32(dataAux))), pobj);
    else
        asfn = Sfr34_Closure(Value::kThunkClosure, reinterpret_cast<const void*>(dataAux), pobj);
    if (nargs)
    {
        Array<Value> args(static_cast<int>(nargs));
        for (UPInt i = 0; i < nargs; i++)
            root->GFxValue2ASValue(pargs[i], &args[i]);
        vm->ExecuteInternalUnsafe(asfn, Value(pobj), asresult, static_cast<unsigned>(nargs), &args[0], false);
    }
    else
        vm->ExecuteInternalUnsafe(asfn, Value(pobj), asresult, 0, NULL, false);
    if (vm->IsException())
    {
        vm->HandleException = false;
        vm->OutputError(vm->ExceptionObj);
        vm->ExceptionObj.SetUndefined();
        return false;
    }
    if (presult)
        root->ASValue2GFxValue(asresult, presult);
    return true;
}

void FUN_142504630(ASRefCountCollector* gc, void* stats);          // ASRefCountCollector::ForceCollect
void FUN_142446e00(Instances::fl_display::DisplayObject* obj, Instances::fl_display::Loader* loader);  // SetLoaderInfo
void FUN_1425274b0(DisplayObjectBase* bitmap, Resource* pimage);   // AvmBitmap::SetImage

// The new character's AS3 object, made (with the loader's info) and constructed when it has none yet.
static inline void Sfr34_LoadedCtor(AvmDisplayObj* avm, Instances::fl_display::Loader* loader)
{
    if (!avm->GetAS3Obj() && avm->CreateASInstanceNoCtor(true))
    {
        FUN_142446e00(avm->GetAS3Obj(), loader);
        avm->CallCtor(true);
    }
}

// The loaded movie handed to its Loader while the preload task runs: open (once, after the version check), the
// progress of its bytes, its first frame's sprite made the Loader's child (init), and at the end the bitmap of an
// image (init) and complete; an error event when nothing could be loaded. True when the entry is done.
// MS2-FUNCTIONAL Loader::GetDisplayObjContainer and ToAvmSprite are written out (the exe inlines them)
// @0x142515c60
bool LoadQueueEntryMT_LoadMovie::LoadFinished()
{
    const bool      btaskDone = pPreloadTask->IsDone();
    LoadQueueEntry* qe        = static_cast<LoadQueueEntry*>(pQueueEntry);
    if (qe->Canceled && btaskDone)
        return true;
    MovieRoot* root = static_cast<MovieRoot*>(pMovieImpl->pASMovieRoot);
    if (!btaskDone)
    {
        if (qe->FirstExec)
        {
            qe->mLoader->ExecuteOpenEvent();
            qe->FirstExec = false;
        }
        return false;
    }
    MovieDefImpl* pdefImpl = pPreloadTask->GetMoiveDefImpl();
    if (!pdefImpl)
    {
        qe->mLoader->ExecuteErrorEvent(qe->mURLRequest->GetUrl().ToCStr());
        if (qe->NotifyLoadInitCInterface)
            qe->NotifyLoadInitCInterface->ErrorEventCallback();
        qe->FirstExec = false;
        return true;
    }
    if (qe->FirstExec)
    {
        if (pdefImpl->GetVersion() != ~0u &&
            (pdefImpl->GetVersion() < 9 || !(pdefImpl->GetDataDef()->GetFileAttributes() & 8)))
        {
            qe->Canceled = true;
            if (root->GetMovieImpl()->GetLogState() && !qe->QuietOpen)
                root->GetMovieImpl()->GetLogState()->LogScriptWarning(
                    "Failed loading SWF \"%s\": ActionScript version mismatch", qe->mURLRequest->GetUrl().ToCStr());
            qe->mLoader->ExecuteErrorEvent(qe->mURLRequest->GetUrl().ToCStr());
            if (qe->NotifyLoadInitCInterface)
                qe->NotifyLoadInitCInterface->ErrorEventCallback();
            return true;
        }
        qe->mLoader->ExecuteOpenEvent();
        if (qe->NotifyLoadInitCInterface)
            qe->NotifyLoadInitCInterface->OpenEventCallback();
        qe->FirstExec = false;
        root->AddLoadedMovieDef(pdefImpl);
    }
    if (!CharSwitched)
        CharSwitched = true;
    if (BytesLoaded != pdefImpl->pBindData->GetBytesLoaded())
    {
        BytesLoaded = pdefImpl->pBindData->GetBytesLoaded();
        qe->mLoader->ExecuteProgressEvent(BytesLoaded, pdefImpl->GetDataDef()->GetFileBytes());
    }
    if (!FirstFrameLoaded && (pdefImpl->pBindData->GetBindState() & MovieDefImpl::BSF_Frame1Loaded))
    {
        if (pdefImpl->GetDataDef()->MovieType == MovieDataDef::MT_Flash)
        {
            GFx::DisplayObject* pparent = qe->mLoader->pDispObj;
            if (root->pAVM)
                FUN_142504630(&root->pAVM->GetGC(), pMovieImpl->pAdvanceStats);
            CharacterCreateInfo ccinfo = { pdefImpl->GetDataDef(), pdefImpl, NULL };
            Ptr<Sprite> pnewChar = *static_cast<Sprite*>(root->pASSupport->CreateCharacterInstance(
                pMovieImpl, ccinfo, NULL, ResourceId(0), CharacterDef::Sprite));
            pnewChar->SetLoadedSeparately(true);
            pnewChar->Flags |= DisplayObject::Mask_TimelineObject;
            pnewChar->OnEventLoad();
            pnewChar->AddToPlayList();
            AvmSprite* avmSpr = static_cast<AvmSprite*>(ToAvmDisplayObj(pnewChar));
            avmSpr->ExecuteInitActionFrameTags(0);
            pnewChar->SetFOV(55.0);
            Sfr34_LoadedCtor(avmSpr, qe->mLoader);
            Sfr34_ToAvmContainer(pparent)->AddChild(pnewChar);
            root->ResolveStickyVariables(pnewChar);
            pnewChar->ModifyOptimizedPlayListLocal<Sprite>();
            root->DoActions();
            qe->mLoader->QueueInitEvent(pnewChar, Ptr<RefCountImpl>(qe->NotifyLoadInitCInterface.GetPtr()));
        }
        FirstFrameLoaded = true;
    }
    const unsigned state = pdefImpl->pBindData->GetBindState();
    if ((state & (MovieDefImpl::BS_InProgress | MovieDefImpl::BS_Finished)) < MovieDefImpl::BS_Finished)
        return false;
    if (!(state & MovieDefImpl::BS_Finished))
    {
        qe->mLoader->ExecuteErrorEvent(qe->mURLRequest->GetUrl().ToCStr());
        qe->FirstExec = false;
        return true;
    }
    if (pdefImpl->GetDataDef()->MovieType == MovieDataDef::MT_Image)
    {
        GFx::DisplayObject* pparent = qe->mLoader->pDispObj;
        CharacterCreateInfo ccinfo  = { pdefImpl->GetDataDef(), pdefImpl, NULL };
        Ptr<DisplayObjectBase> pnewChar = *root->pASSupport->CreateCharacterInstance(
            root->GetMovieImpl(), ccinfo, NULL, ResourceId(), CharacterDef::Bitmap);
        ResourceHandle rh;
        if (pdefImpl->GetDataDef()->GetResourceHandle(&rh, ResourceId(0)))
        {
            Resource* pres = rh.GetResource(&pdefImpl->GetResourceBinding());
            if (pres && pres->GetResourceType() == Resource::RT_Image)
                FUN_1425274b0(pnewChar, pres);
        }
        Sfr34_ToAvmContainer(pparent)->AddChild(pnewChar);
        Sfr34_LoadedCtor(ToAvmDisplayObj(pnewChar), qe->mLoader);
        qe->mLoader->QueueInitEvent(static_cast<GFx::DisplayObject*>(pnewChar.GetPtr()),
                                    Ptr<RefCountImpl>(qe->NotifyLoadInitCInterface.GetPtr()));
    }
    qe->mLoader->QueueCompleteEvent();
    return true;
}

// VM::IsVMCachedType(const Traits&): whether tr is one of the class traits the VM keeps (or, for instance traits,
// one of their instance traits): the primitives, Class, Object, Namespace, Function, Array, the typed vectors and,
// with XML support, QName, XML and XMLList.
// MS2-FUNCTIONAL free function (not declared in the shared VM class; no caller in the exe)
// @0x1425151a0
bool FUN_1425151a0(const VM& vm, const Traits& tr)
{
    const XMLSupport& xml = vm.GetXMLSupport();
    if (tr.IsClassTraits())
    {
        const Traits* p = &tr;
        if (p == vm.TraitsBoolean.GetPtr() || p == vm.TraitsNumber.GetPtr() || p == vm.TraitsInt.GetPtr() ||
            p == vm.TraitsUint.GetPtr() || p == vm.TraitsString.GetPtr() || p == vm.TraitsClassClass.GetPtr() ||
            p == vm.TraitsObject.GetPtr() || p == vm.TraitsNamespace.GetPtr() || p == vm.TraitsFunction.GetPtr() ||
            p == vm.TraitsArray.GetPtr() || p == vm.TraitsVector_int.GetPtr() ||
            p == vm.TraitsVector_uint.GetPtr() || p == vm.TraitsVector_double.GetPtr() ||
            p == vm.TraitsVector_String.GetPtr())
            return true;
        if (!xml.IsEnabled())
            return false;
        return p == xml.GetClassTraitsQName() || p == xml.GetClassTraitsXML() || p == xml.GetClassTraitsXMLList();
    }
    const Traits* p = &tr;
    if (p == &vm.TraitsBoolean->GetInstanceTraits() || p == &vm.TraitsNumber->GetInstanceTraits() ||
        p == &vm.TraitsInt->GetInstanceTraits() || p == &vm.TraitsUint->GetInstanceTraits() ||
        p == &vm.TraitsString->GetInstanceTraits() || p == &vm.TraitsClassClass->GetInstanceTraits() ||
        p == &vm.TraitsObject->GetInstanceTraits() || p == &vm.TraitsNamespace->GetInstanceTraits() ||
        p == &vm.TraitsFunction->GetInstanceTraits() || p == &vm.TraitsArray->GetInstanceTraits() ||
        p == &vm.TraitsVector_int->GetInstanceTraits() || p == &vm.TraitsVector_uint->GetInstanceTraits() ||
        p == &vm.TraitsVector_double->GetInstanceTraits() || p == &vm.TraitsVector_String->GetInstanceTraits())
        return true;
    if (!xml.IsEnabled())
        return false;
    return p == xml.GetITraitsQName() || p == xml.GetITraitsXML() || p == xml.GetITraitsXMLList();
}

// sfr34 batch AF: the load of a queued request: the data of a URLLoader (variables, text or binary) read from its
// file, or the movie / image of a Loader (protocol images through the image creator) made the Loader's child.

// A queued load done here (not on a loader thread). A URLLoader's file is read whole and handed to it with its
// open/progress/complete events ("Can't open" error otherwise). A Loader's movie is loaded (a stripped player tries
// the ".gfx" name first; Loader.loadBytes from its bytes), an image protocol URL through the image creator; then
// open, the movie's sprite (or the image's bitmap) made the Loader's child and constructed, and init/complete
// (synchronously for protocol images). An error event when nothing could be loaded or the SWF is not AS3.
// MS2-FUNCTIONAL GetRootFilePath and ImageResource's constructor are inlined in the exe
// @0x14251e560
void MovieRoot::ProcessLoadQueueEntry(GFx::LoadQueueEntry* pentry, LoadStates* pls)
{
    if (pentry->Canceled)
        return;
    LoadQueueEntry& entry = static_cast<LoadQueueEntry&>(*pentry);
    if (pentry->Type & (GFx::LoadQueueEntry::LTF_VarsFlag | GFx::LoadQueueEntry::LTF_BinaryFlag))
    {
        bool            error = false;
        String          data;
        ArrayPOD<UByte> binaryData;
        int             fileLen = 0;
        {
            String rootPath;
            GetRootFilePath(&rootPath);
            URLBuilder::LocationInfo loc(URLBuilder::File_LoadVars, pentry->URL, rootPath);
            String                   fileName;
            pls->BuildURL(&fileName, loc);
            Ptr<File> pfile = *pls->OpenFile(fileName.ToCStr(), 0);
            if (pfile)
            {
                if (entry.mURLLoader->IsLoadingVariables())
                    MovieImpl::ReadTextData(&data, pfile, &fileLen, true);
                else if (entry.mURLLoader->IsLoadingText())
                    MovieImpl::ReadTextData(&data, pfile, &fileLen, false);
                else if (entry.mURLLoader->IsLoadingBinary())
                    MovieImpl::ReadBinaryData(&binaryData, pfile, &fileLen);
            }
            else
            {
                char buf[1024];
                SFsprintf(buf, sizeof(buf), "Can't open %s", fileName.ToCStr());
                entry.mURLLoader->ExecuteErrorEvent(buf);
                error = true;
            }
        }
        if (!error)
        {
            if (entry.mURLLoader->IsLoadingVariables())
                entry.mURLLoader->SetVariablesDataString(data.ToCStr());
            else if (entry.mURLLoader->IsLoadingText())
                entry.mURLLoader->SetTextString(data.ToCStr());
            else if (entry.mURLLoader->IsLoadingBinary())
                entry.mURLLoader->SetBinaryData(binaryData);
            entry.mURLLoader->ExecuteOpenEvent();
            entry.mURLLoader->ExecuteProgressEvent(fileLen, fileLen);
            entry.mURLLoader->ExecuteCompleteEvent();
        }
        return;
    }

    String            url(pentry->URL), urlStrGfx;
    LogState*         plog      = pls->GetLogState();
    Ptr<MovieDefImpl> pmovieDef;
    const unsigned    loadFlags = pMovieImpl->pMainMovieDef->GetLoadFlags();
    if (pMovieImpl->pMainMovie &&
        (pMovieImpl->pMainMovie->GetResourceMovieDef()->GetSWFFlags() & 0x10))  // stripped (a .gfx player)
        urlStrGfx = GetUrlStrGfx(url);

    bool       bilinearImage     = false;
    const bool userImageProtocol = LoaderImpl::IsProtocolImage(url, &bilinearImage, NULL);
    if (userImageProtocol)
    {
        ImageCreator* pimageLoader = pls->GetImageCreator();
        if (pimageLoader)
        {
            ImageCreateInfo icinfo(ImageCreateInfo::Create_ProtocolImage, pMovieImpl->GetMovieHeap());
            icinfo.SetStates(pls->GetLog(), pls->pBindStates->pFileOpener, pls->GetImageFileHandlerRegistry());
            icinfo.pMovie = pMovieImpl;
            Ptr<Render::Image> pimg = *pimageLoader->LoadProtocolImage(icinfo, url.ToCStr());
            if (pimg)
            {
                Ptr<ImageResource> pimageRes =
                    *SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) ImageResource(pimg, Resource::Use_Bitmap);
                if (pimageRes)
                    pmovieDef = *pMovieImpl->CreateImageMovieDef(pimageRes, bilinearImage, url.ToCStr(), pls);
            }
            else if (plog)
            {
                plog->LogScriptWarning("ImageCreator::LoadProtocolImage failed to load image \"%s\"", url.ToCStr());
                entry.mLoader->ExecuteErrorEvent(url.ToCStr());
                return;
            }
        }
        else if (plog)
        {
            plog->LogScriptWarning("ImageCreator is not installed, failed to load image \"%s\"", url.ToCStr());
            entry.mLoader->ExecuteErrorEvent(url.ToCStr());
        }
    }
    else
    {
        unsigned lf = loadFlags | GFx::Loader::LoadImageFiles | GFx::Loader::LoadWaitCompletion;
        if (pentry->QuietOpen)
            lf |= GFx::Loader::LoadQuietOpen;
        if (!entry.mBytes)
        {
            String rootPath;
            GetRootFilePath(&rootPath);
            if (urlStrGfx.GetLength() > 0)
            {
                URLBuilder::LocationInfo loc(URLBuilder::File_LoadMovie, urlStrGfx, rootPath);
                pmovieDef = *LoaderImpl::CreateMovie_LoadState(pls, loc, lf);
            }
            if (!pmovieDef)
            {
                URLBuilder::LocationInfo loc(URLBuilder::File_LoadMovie, url, rootPath);
                pmovieDef = *LoaderImpl::CreateMovie_LoadState(pls, loc, lf);
            }
        }
        else
            pmovieDef = *LoaderImpl::CreateMovie_LoadState(pls, *entry.mBytes, lf);

        if (!pmovieDef)
        {
            if (plog && !pentry->QuietOpen)
                plog->LogScriptWarning("Failed loading URL \"%s\"", url.ToCStr());
            entry.mLoader->ExecuteErrorEvent(url.ToCStr());
            if (entry.NotifyLoadInitCInterface)
                entry.NotifyLoadInitCInterface->ErrorEventCallback();
            return;
        }
        if (pmovieDef->GetVersion() != ~0u &&
            (pmovieDef->GetVersion() < 9 || !(pmovieDef->GetDataDef()->GetFileAttributes() & 8)))
        {
            if (plog && !pentry->QuietOpen)
                plog->LogScriptWarning("Failed loading SWF \"%s\": ActionScript version mismatch", url.ToCStr());
            entry.mLoader->ExecuteErrorEvent(url.ToCStr());
            if (entry.NotifyLoadInitCInterface)
                entry.NotifyLoadInitCInterface->ErrorEventCallback();
            return;
        }
    }
    if (pmovieDef)
        AddLoadedMovieDef(pmovieDef);

    entry.mLoader->ExecuteOpenEvent();
    if (entry.NotifyLoadInitCInterface)
        entry.NotifyLoadInitCInterface->OpenEventCallback();

    GFx::DisplayObject*     pparent = entry.mLoader->pDispObj;
    Ptr<DisplayObjectBase>  pnewChar;
    if (pmovieDef && pmovieDef->GetDataDef()->MovieType == MovieDataDef::MT_Image)
    {
        CharacterCreateInfo    ccinfo      = { pmovieDef->GetDataDef(), pmovieDef, NULL };
        Ptr<DisplayObjectBase> pnewBmpChar = *pASSupport->CreateCharacterInstance(
            pMovieImpl, ccinfo, NULL, ResourceId(), CharacterDef::Bitmap);
        ResourceHandle rh;
        if (pmovieDef->GetDataDef()->GetResourceHandle(&rh, ResourceId(0)))
        {
            Resource* pres = rh.GetResource(&pmovieDef->GetResourceBinding());
            if (pres && pres->GetResourceType() == Resource::RT_Image)
                FUN_1425274b0(pnewBmpChar, pres);
        }
        Sfr34_ToAvmContainer(pparent)->AddChild(pnewBmpChar);
        Sfr34_LoadedCtor(ToAvmDisplayObj(pnewBmpChar), entry.mLoader);
        pnewChar = pnewBmpChar;
    }
    else if (pmovieDef)
    {
        if (pAVM)
            FUN_142504630(&pAVM->GetGC(), pMovieImpl->pAdvanceStats);
        const UPInt fileBytes = pmovieDef->GetDataDef()->GetFileBytes();
        entry.mLoader->ExecuteProgressEvent(fileBytes, fileBytes);
        CharacterCreateInfo ccinfo     = { pmovieDef->GetDataDef(), pmovieDef, NULL };
        Ptr<Sprite>         pnewSprite = *static_cast<Sprite*>(pASSupport->CreateCharacterInstance(
            pMovieImpl, ccinfo, NULL, ResourceId(0), CharacterDef::Sprite));
        pnewSprite->SetLoadedSeparately(true);
        pnewSprite->Flags |= DisplayObject::Mask_TimelineObject;
        pnewSprite->OnEventLoad();
        pnewSprite->AddToPlayList();
        AvmSprite* avmSpr = static_cast<AvmSprite*>(ToAvmDisplayObj(pnewSprite));
        avmSpr->ExecuteInitActionFrameTags(0);
        pnewSprite->SetFOV(55.0);
        Sfr34_LoadedCtor(avmSpr, entry.mLoader);
        Sfr34_ToAvmContainer(pparent)->AddChild(pnewSprite);
        ResolveStickyVariables(pnewSprite);
        pnewSprite->ModifyOptimizedPlayListLocal<Sprite>();
        DoActions();
        pnewChar = pnewSprite;
    }

    GFx::DisplayObject* pchar = static_cast<GFx::DisplayObject*>(pnewChar.GetPtr());
    if (!userImageProtocol)
    {
        entry.mLoader->QueueInitEvent(pchar, Ptr<RefCountImpl>(entry.NotifyLoadInitCInterface.GetPtr()));
        entry.mLoader->QueueCompleteEvent();
    }
    else
    {
        entry.mLoader->ExecuteInitEvent(pchar);
        if (entry.NotifyLoadInitCInterface)
            entry.NotifyLoadInitCInterface->InitEventCallback();
        entry.mLoader->ExecuteCompleteEvent();
    }
}

// sfr34 batch AG: one element of TextField.setImageSubstitutions (an object with subString, image, width, height,
// baseLineX, baseLineY and id) made an image substitution of the text field.

} } } // namespace Scaleform::GFx::AS3

namespace Scaleform {
void LogDebugMessage(LogMessageId id, const char* fmt, ...);
}

// The render Text headers do not mix with this kernel tree, so stand-ins of Text::ImageDesc (0x50 bytes, its matrix
// 16-byte aligned) and of DocView::ImageSubstitutor and its Element (as in sfr_as3_15).
struct Sfr34_TextImageDesc : public Scaleform::RefCountBaseNTS<Sfr34_TextImageDesc, 0x4e>   // StatRender_Text_Mem
{
    Scaleform::Ptr<Scaleform::Render::Image> pImage;            // +0x10
    float                                    BaseLineX, BaseLineY;
    float                                    ScreenWidth, ScreenHeight;
    Scaleform::Render::Matrix2F              Matrix;            // +0x30

    Sfr34_TextImageDesc() : BaseLineX(0), BaseLineY(0), ScreenWidth(0), ScreenHeight(0) {}
};
struct Sfr34_ImageSubstElement              // 0x38 bytes
{
    wchar_t                             SubString[20];
    Scaleform::Ptr<Sfr34_TextImageDesc> pImageDesc;              // +0x28
    Scaleform::UByte                    SubStringLen;

    Sfr34_ImageSubstElement() : SubStringLen(0) {}
};
struct Sfr34_ImageSubstitutor : public Scaleform::NewOverrideBase<Scaleform::Stat_Default_Mem>
{
    Scaleform::ArrayLH<Sfr34_ImageSubstElement> Elements;
};
void FUN_14260dcc0(Sfr34_ImageSubstitutor* self, const Sfr34_ImageSubstElement& elem);   // ImageSubstitutor::AddImageDesc
void FUN_1425b65e0(void* ptf, const char* id, Sfr34_TextImageDesc* pdesc);               // TextField::AddIdImageDescAssoc

// The value of the public property name of pobj in v; false when pobj has none.
static bool Sfr34_GetPublicProperty(Scaleform::GFx::AS3::VM& vm, Scaleform::GFx::AS3::Object* pobj, const char* name,
                                    Scaleform::GFx::AS3::Value& v)
{
    using namespace Scaleform::GFx::AS3;
    const Multiname mn(vm.GetPublicNamespace(), Value(vm.GetStringManager().CreateConstString(name)));
    return pobj->GetProperty(mn, v);
}

// The number of the public property name of pobj times scale in result; result is kept when pobj has none.
static void Sfr34_GetNumberProperty(Scaleform::GFx::AS3::VM& vm, Scaleform::GFx::AS3::Object* pobj, const char* name,
                                    Scaleform::GFx::AS3::Value& v, float scale, float& result)
{
    Scaleform::GFx::AS3::Value::Number n;
    if (Sfr34_GetPublicProperty(vm, pobj, name, v) && v.Convert2Number(n))
        result = float(n * scale);
}

// AvmTextField::ProceedImageSubstitution: element idx (ve) of setImageSubstitutions: its subString (at most 15
// characters) replaced by its image (a BitmapData, an image source made an image by the image creator), shown at
// width x height (the image's size by default) with the baseline at (baseLineX, baseLineY) (the bottom by
// default), and under id when it has one; a script warning when the element is not valid.
// MS2-FUNCTIONAL free function on the full AvmTextField (opaque in the shared header); the exe inlines the BitmapData
// type test and gets the image creator twice
// @0x14251d070
void FUN_14251d070(void* pavmtf, Scaleform::GFx::AS3::VM& vm, unsigned idx, const Scaleform::GFx::AS3::Value& ve)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx;
    using namespace Scaleform::GFx::AS3;
    if (!ve.IsObject())
        return;
    Object*             pobj = ve.GetObject();
    GFx::DisplayObject* pdo  = static_cast<AvmDisplayObj*>(pavmtf)->pDispObj;
    TextField*          ptf  = reinterpret_cast<TextField*>(pdo);
    UByte*                  pdoc   = reinterpret_cast<UByte*>(ptf->GetDocument());
    Sfr34_ImageSubstitutor*& psubst = *reinterpret_cast<Sfr34_ImageSubstitutor**>(pdoc + 0x30);   // created on demand
    if (!psubst)
        psubst = new Sfr34_ImageSubstitutor;
    if (!psubst)
        return;

    AS3::Value              v;
    Sfr34_ImageSubstElement elem;
    if (!Sfr34_GetPublicProperty(vm, pobj, "subString", v))
    {
        pdo->LogScriptWarning("%s.setImageSubstitutions() failed for #%d element - subString should be specified",
                              pdo->GetName().ToCStr(), idx);
        return;
    }
    v.ToStringValue(vm.GetStringManager());
    {
        const ASString  subString = v.AsString();
        const unsigned  len       = subString.GetLength();
        if (len > 15)
        {
            pdo->LogScriptWarning(
                "%s.setImageSubstitutions() failed for #%d element - length of subString should not exceed 15 characters",
                pdo->GetName().ToCStr(), idx);
            return;
        }
        UTF8Util::DecodeString(elem.SubString, subString.ToCStr(), subString.GetSize() + 1);
        elem.SubStringLen = UByte(len);
    }

    Ptr<Render::Image> pimg;
    float              origWidth = 0, origHeight = 0;
    if (Sfr34_GetPublicProperty(vm, pobj, "image", v) && FUN_1425145d0(vm, v, "flash.display.BitmapData"))
    {
        ImageResource*    pimageRes = static_cast<Instances::fl_display::BitmapData*>(v.GetObject())->GetImageResource();
        Ptr<MovieDefImpl> pmd       = pdo->GetResourceMovieDef();
        if (pimageRes->GetImage()->GetImageType() != Render::ImageBase::Type_ImageBase)
            pimg = static_cast<Render::Image*>(pimageRes->GetImage());
        else
        {
            Ptr<ImageCreator> pcreator = *static_cast<ImageCreator*>(pmd->GetStateAddRef(State::State_ImageCreator));
            if (!pcreator)
                LogDebugMessage(Log_Warning, "ImageCreator is null in ProceedImageSubstitution");
            else
            {
                ImageCreateInfo cinfo(ImageCreateInfo::Create_SourceImage, Memory::GetHeapByAddress(ptf), 1,
                                      Resource::Use_Bitmap);
                pimg = *pcreator->CreateImage(cinfo, static_cast<Render::ImageSource*>(pimageRes->GetImage()));
            }
        }
        if (pimg)
        {
            const Render::ImageRect r = pimg->GetRect();
            origWidth  = float(UInt32(r.x2 - r.x1));
            origHeight = float(UInt32(r.y2 - r.y1));
            if (origWidth == 0 || origHeight == 0)
            {
                pdo->LogScriptWarning(
                    "%s.setImageSubstitutions() failed for #%d element - image has one zero dimension",
                    pdo->GetName().ToCStr(), idx);
                return;
            }
        }
    }
    if (!pimg)
    {
        pdo->LogScriptWarning(
            "%s.setImageSubstitutions() failed for #%d element - 'image' is not specified or not a BitmapData",
            pdo->GetName().ToCStr(), idx);
        return;
    }

    // Sizes in twips; the baseline is taken in twips and kept in pixels (its default, the bottom, is as the exe
    // computes it: the pixel height less 20).
    float screenWidth = origWidth * 20.0f, screenHeight = origHeight * 20.0f;
    float baseLineX = 0, baseLineY = origHeight - 20.0f;
    Sfr34_GetNumberProperty(vm, pobj, "width", v, 20.0f, screenWidth);
    Sfr34_GetNumberProperty(vm, pobj, "height", v, 20.0f, screenHeight);
    Sfr34_GetNumberProperty(vm, pobj, "baseLineX", v, 20.0f, baseLineX);
    Sfr34_GetNumberProperty(vm, pobj, "baseLineY", v, 20.0f, baseLineY);
    StringBuffer idBuf;
    const char*  pid = NULL;
    if (Sfr34_GetPublicProperty(vm, pobj, "id", v))
    {
        v.Convert2String(idBuf);
        pid = idBuf.ToCStr();
    }

    elem.pImageDesc = *SF_HEAP_AUTO_NEW(ptf) Sfr34_TextImageDesc;
    Sfr34_TextImageDesc* pdesc = elem.pImageDesc;
    pdesc->pImage       = pimg;
    pdesc->BaseLineX    = baseLineX * 0.05f;
    pdesc->BaseLineY    = baseLineY * 0.05f;
    pdesc->ScreenWidth  = screenWidth;
    pdesc->ScreenHeight = screenHeight;
    if (pid)
        FUN_1425b65e0(ptf, pid, pdesc);
    pdesc->Matrix.Tx() += -pdesc->BaseLineX;
    pdesc->Matrix.Ty() += -pdesc->BaseLineY;
    pdesc->Matrix.AppendScaling(pdesc->ScreenWidth / origWidth, pdesc->ScreenHeight / origHeight);
    FUN_14260dcc0(psubst, elem);
    pdoc[0x14b] |= 2;   // DocView: reformat
    ptf->SetDirtyFlag();
}

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
// sfr34: the stage frame counter
// MS2-PIN: ??_7FrameCounter@AS3@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@3@@ 0x14317e608
// MS2-PIN: ??_7FrameCounter@AS3@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@23@@ 0x14317e9a0
// MS2-PIN: ?GetLoadingFrame@FrameCounter@AS3@GFx@Scaleform@@UEBAIXZ 0x14250b390
// MS2-PIN: ?PushBack@?$ArrayData@VValue@AS3@GFx@Scaleform@@U?$AllocatorGH@VValue@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXAEBVValue@AS3@GFx@2@@Z 0x14251f660
// MS2-PIN: ??_7InitStruct@String@Scaleform@@6B@ 0x14313f358
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
// MS2-PIN: ??_7RefCountImplCore@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7RefCountVImpl@Scaleform@@6B@ 0x1431496d0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountVImpl@Scaleform@@$02@Scaleform@@6B@ 0x1431498a0
// MS2-PIN: ??_7?$RefCountBaseV@VImage@Render@Scaleform@@$02@Scaleform@@6B@ 0x1431498b8
// MS2-PIN: ??_7ImageBase@Render@Scaleform@@6B@ 0x1431498d0
// MS2-PIN: ??_7Image@Render@Scaleform@@6B@ 0x143149940
// MS2-PIN: ??_7ImageDelegate@Render@Scaleform@@6B@ 0x143149a28
// MS2-PIN: ??_7ImageDelegate@ImageResource@GFx@Scaleform@@6B@ 0x143149b10
// MS2-PIN: ??_7ImageResource@GFx@Scaleform@@6B@ 0x143149bf8
// MS2-PIN: ??_7RefCountNTSImplCore@Scaleform@@6B@ 0x1431093e0
// MS2-PIN: ??_7RefCountNTSImpl@Scaleform@@6B@ 0x1431093f0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7?$RefCountBaseNTS@USfr34_TextImageDesc@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7Sfr34_TextImageDesc@@6B@ 0x14317c9c0
// MS2-PIN: ?Reserve@?$ArrayDataBase@EU?$AllocatorGH_POD@E$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x142522d10

// ---- The full-exe out-of-line members of this range: the empty or forwarding virtual defaults of the display
// object classes, traits, XML support, interval timer and value interface. ----

#include "ms2/scaleform/include/gfx/as3/as3_valueobjectinterface.h"

namespace Scaleform { namespace GFx {

// The font manager of the parent.
// @0x142509da0
FontManager* DisplayObjectBase::GetFontManager() const
{
    InteractiveObject* pparent = GetParent();
    return pparent ? pparent->GetFontManager() : NULL;
}

// @0x14250d620
float DisplayObjectBase::GetRatio() const
{
    return 0.0f;
}

// @0x14250d6f0
RectF DisplayObjectBase::GetRectBounds(const Matrix& t) const
{
    SF_UNUSED(t);
    return RectF(0, 0, 0, 0);
}

// @0x14250d830
Render::TreeContainer* DisplayObjectBase::GetRenderContainer()
{
    return NULL;
}

// The movie definition of the parent.
// @0x14250d970
MovieDefImpl* DisplayObjectBase::GetResourceMovieDef() const
{
    InteractiveObject* pparent = GetParent();
    return pparent ? pparent->GetResourceMovieDef() : NULL;
}

// @0x14250ee10
UByte DisplayObjectBase::GetStateChangeFlags() const
{
    return 0;
}

// A plain display object takes no mouse input.
// @0x14250f760
DisplayObjectBase::TopMostResult DisplayObjectBase::GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr)
{
    SF_UNUSED(pt);
    pdescr->pResult = NULL;
    return TopMost_FoundNothing;
}

// @0x14250f850
InteractiveObject* DisplayObjectBase::GetTopParent(bool ignoreLockRoot) const
{
    InteractiveObject* pparent = GetParent();
    if (!pparent)
        return NULL;
    return pparent->GetTopParent(ignoreLockRoot);
}

// @0x14250f890
CharacterDef::CharacterDefType DisplayObjectBase::GetType() const
{
    return CharacterDef::Shape;
}

// @0x142510a30
bool DisplayObjectBase::GetVisible() const
{
    return IsVisibleFlagSet();
}

// @0x142510d40
bool DisplayObjectBase::Has3D()
{
    return Is3D();
}

// @0x14251cab0
bool DisplayObjectBase::PointTestLocal(const PointF& pt, UByte hitTestMask) const
{
    SF_UNUSED2(pt, hitTestMask);
    return false;
}

// The frame and focus defaults of an interactive object without a timeline.
// @0x142509dc0
const String* InteractiveObject::GetFrameLabel(unsigned frame, unsigned* exactFrame)
{
    SF_UNUSED2(frame, exactFrame);
    return NULL;
}

// @0x14250b360
bool InteractiveObject::GetLabeledFrame(const char* plabel, unsigned* frameNumber, bool translateNumbers)
{
    SF_UNUSED3(plabel, frameNumber, translateNumbers);
    return false;
}

// @0x14250b3a0
unsigned InteractiveObject::GetLoadingFrame() const
{
    return 0;
}

// @0x14250cc20
PlayState InteractiveObject::GetPlayState() const
{
    return State_Stopped;
}

// @0x14250ee20
UByte InteractiveObject::GetStateChangeFlags() const
{
    return UByte((Flags & Mask_ChangedFlags) >> 16);
}

// MS2-FUNCTIONAL: the exe encodes the empty body as `ret 0`.
// @0x142510d10
void InteractiveObject::GotoFrame(unsigned targetFrameNumber)
{
    SF_UNUSED(targetFrameNumber);
}

// @0x142510e60
bool InteractiveObject::HasLooped() const
{
    return false;
}

// @0x142518990
bool InteractiveObject::OnCharEvent(UInt32 wcharCode, unsigned controllerIdx)
{
    SF_UNUSED2(wcharCode, controllerIdx);
    return false;
}

// MS2-FUNCTIONAL: the exe encodes the empty body as `ret 0`.
// @0x14251a100
void InteractiveObject::OnGettingKeyboardFocus(unsigned controllerIdx, FocusMovedType fmt)
{
    SF_UNUSED2(controllerIdx, fmt);
}

// @0x14251a3a0
bool InteractiveObject::OnKeyEvent(const EventId& id, int* pkeyMask)
{
    SF_UNUSED(pkeyMask);
    return OnEvent(id);
}

// @0x14251a820
bool InteractiveObject::OnLosingKeyboardFocus(InteractiveObject* newFocusCh, unsigned controllerIdx, FocusMovedType fmt)
{
    SF_UNUSED3(newFocusCh, controllerIdx, fmt);
    return true;
}

// @0x14251ac20
bool InteractiveObject::OnMouseEvent(const EventId& id)
{
    return OnEvent(id);
}

// @0x14251ac30
bool InteractiveObject::OnMouseWheelEvent(int mwDelta)
{
    SF_UNUSED(mwDelta);
    return false;
}

// @0x14251f540
void InteractiveObject::PropagateFocusGroupMask(unsigned mask)
{
    FocusGroupMask = UInt16(mask);
}

// @0x14251f550
void InteractiveObject::PropagateKeyEvent(const EventId& id, int* pkeyMask)
{
    OnKeyEvent(id, pkeyMask);
}

// @0x14251f560
void InteractiveObject::PropagateMouseEvent(const EventId& id)
{
    OnEvent(id);
}

// MS2-FUNCTIONAL: the exe encodes the empty body as `ret 0`.
// @0x14251f5c0
void InteractiveObject::PropagateNoAdvanceGlobalFlag()
{
}

// MS2-FUNCTIONAL: the exe encodes the empty body as `ret 0`.
// @0x14251f5d0
void InteractiveObject::PropagateNoAdvanceLocalFlag()
{
}

// @0x14250a5e0
Sprite* DisplayObjContainer::GetHitArea() const
{
    return NULL;
}

// @0x14250a5f0
Sprite* DisplayObjContainer::GetHitAreaHolder() const
{
    return NULL;
}

// The host's reference to a string node, a wide string or an AS3 object (a closure's pointer carries a tag bit).
// @0x142518530
void AS3ValueObjectInterface::ObjectAddRef(Value* val, void* pobj)
{
    switch (val->GetType())
    {
    case Value::VT_String:
        static_cast<ASStringNode*>(pobj)->AddRef();
        break;
    case Value::VT_StringW:
        reinterpret_cast<MovieImpl::WideStringStorage*>(
            static_cast<UByte*>(pobj) - offsetof(MovieImpl::WideStringStorage, pData))->AddRef();
        break;
    case Value::VT_Closure:
        pobj = reinterpret_cast<void*>(reinterpret_cast<UPInt>(pobj) & ~UPInt(2));
        // fall through
    case Value::VT_Object:
    case Value::VT_Array:
    case Value::VT_DisplayObject:
        static_cast<AS3::Object*>(pobj)->AddRef();
        break;
    default:;
    }
}

// @0x142518570
void AS3ValueObjectInterface::ObjectRelease(Value* val, void* pobj)
{
    switch (val->GetType())
    {
    case Value::VT_String:
        static_cast<ASStringNode*>(pobj)->Release();
        break;
    case Value::VT_StringW:
        reinterpret_cast<MovieImpl::WideStringStorage*>(
            static_cast<UByte*>(pobj) - offsetof(MovieImpl::WideStringStorage, pData))->Release();
        break;
    case Value::VT_Closure:
        pobj = reinterpret_cast<void*>(reinterpret_cast<UPInt>(pobj) & ~UPInt(2));
        // fall through
    case Value::VT_Object:
    case Value::VT_Array:
    case Value::VT_DisplayObject:
        static_cast<AS3::Object*>(pobj)->Release();
        break;
    default:;
    }
}

// Whether pdata scripts a display object that still exists.
// @0x142514240
bool AS3ValueObjectInterface::IsDisplayObjectActive(void* pdata) const
{
    return AS3::Sfr34_IsDisplayObject(pdata) &&
           static_cast<AS3::Instances::fl_display::DisplayObject*>(pdata)->pDispObj.GetPtr() != NULL;
}

// The user data the object's holder (+0x30) keeps at +8.
// @0x14250f980
ASUserData* AS3ValueObjectInterface::GetUserData(void* pdata, bool isdobj) const
{
    SF_UNUSED(isdobj);
    if (!pdata)
        return NULL;
    UByte* pholder = *(UByte**)((UByte*)pdata + 0x30);
    if (!pholder)
        return NULL;
    return *(ASUserData**)((UByte*)pholder + 0x8);
}

namespace AS3 {

// @0x14250a5b0
Instances::fl::GlobalObjectScript* Traits::GetGlobalObjectScript() const
{
    return NULL;
}

// MS2-FUNCTIONAL: the exe encodes the empty body as `ret 0`.
// @0x1425117e0
void Traits::InitOnDemand() const
{
}

// @0x142514320
bool Traits::IsGlobal() const
{
    return false;
}

// A class traits makes its class object through its instance traits.
// @0x1425117f0
void ClassTraits::Traits::InitOnDemand() const
{
    ITraits->GetConstructor();
}

// @0x142512620
const SlotInfo* Object::InitializeOnDemand(const SlotInfo* si, const ASString& name, const Instances::Namespace& ns,
                                           UPInt& index)
{
    SF_UNUSED3(name, ns, index);
    return si;
}

// @0x14251cfc0
CheckResult Class::PreInit(const Value& _this) const
{
    SF_UNUSED(_this);
    return true;
}

// @0x14251ced0
void Class::PostInit(const Value& _this, unsigned argc, const Value* argv) const
{
    _this.GetObject()->AS3Constructor(argc, argv);
}

namespace Classes
{
    // @0x142511880
    void UDBase::InitPrototype(AS3::Object& obj) const
    {
        AddConstructor(obj);
    }
}

namespace InstanceTraits
{
    // @0x14250bc20
    ASString RTraits::GetName() const
    {
        return Name;
    }

    // Instances are made by the parent's traits, or Object's.
    // @0x142516570
    void RTraits::MakeObject(Value& result, Traits& t)
    {
        const AS3::Traits* pparent = GetParent();
        if (!pparent)
            pparent = &GetVM().GetClassTraitsObject().GetInstanceTraits();
        const_cast<Traits*>(static_cast<const Traits*>(pparent))->MakeObject(result, t);
    }
}

// @0x14250a650
InstanceTraits::Traits* XMLSupport::GetITraitsQName() const
{
    return NULL;
}

// @0x14250a6e0
InstanceTraits::Traits* XMLSupport::GetITraitsXML() const
{
    return NULL;
}

// @0x14250a700
InstanceTraits::Traits* XMLSupport::GetITraitsXMLList() const
{
    return NULL;
}

// @0x14250a720
int IntervalTimer::GetId() const
{
    return Id;
}

// @0x14250bf80
UInt64 IntervalTimer::GetNextInvokeTime() const
{
    return InvokeTime;
}

// @0x142513eb0
bool IntervalTimer::IsActive() const
{
    return Active;
}

// The top parent of an AS3 parent, else the object itself.
// @0x14250f820
InteractiveObject* AvmInteractiveObj::GetTopParent(bool ignoreLockRoot) const
{
    InteractiveObject* pparent = pDispObj->GetParent();
    if (pparent && pparent->GetAVMVersion() == 2)
        return pparent->GetTopParent(ignoreLockRoot);
    return GetIntObj();
}

// @0x142514330
bool AvmDisplayObjContainer::IsLevelMovie() const
{
    return false;
}

// Once loaded, the AS3 object is held as the counted pointer.
// @0x142519020
void AvmDisplayObj::OnEventLoad()
{
    SetAS3ObjCollectible(GetAS3Obj());
}

// @0x142514a70
bool LoadQueueEntryMT_LoadMovie::IsPreloadingFinished()
{
    return pPreloadTask->IsDone();
}

// Freed segments lower the limit again, down to the user's level.
// @0x14251a0a0
void MemoryContextImpl::HeapLimit::OnFreeSegment(MemoryHeap* heap, UPInt freeingSize)
{
    if (CurrentLimit > UserLevelLimit && CurrentLimit > freeingSize)
    {
        CurrentLimit -= freeingSize;
        heap->SetLimit(CurrentLimit);
    }
}

}}} // namespace Scaleform::GFx::AS3

// ==== pdata-less vftable slots of the AVM display objects, the AS3 MovieRoot and the Tracer (sfr21) ====
// Leaves (`ret`, `xor al,al`, `mov al,1`), tail calls and adjustor thunks without .pdata; the slot only names a VA, so
// the FUN_ ones are free functions (the vftables are data images).

namespace Scaleform { namespace GFx { namespace AS3 {

// @0x142510dd0
bool AvmDisplayObjContainer::HasEventHandler(const EventId&) const
{
    return false;
}

// @0x142514290
bool AvmDisplayObjContainer::IsFocusEnabled(FocusMovedType) const
{
    return false;
}

// @0x142518c50
bool AvmDisplayObjContainer::OnEvent(const EventId& id)
{
    return AvmInteractiveObj::OnEvent(id);
}

// @0x142519040
void AvmDisplayObjContainer::OnEventLoad()
{
    SetAS3ObjCollectible(GetAS3Obj());
}

// @0x142519840
void AvmDisplayObjContainer::OnEventUnload()
{
    AvmDisplayObj::OnEventUnload();
}

// @0x142519d30
void AvmDisplayObjContainer::OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                                     unsigned controllerIdx, FocusMovedType fmt)
{
    AvmInteractiveObj::OnFocus(event, oldOrNewFocusCh, controllerIdx, fmt);
}

// @0x14251a0e0
void AvmDisplayObjContainer::OnGettingKeyboardFocus(unsigned, FocusMovedType)
{
}

// @0x14251a340
bool AvmDisplayObjContainer::OnKeyEvent(const EventId&, int*)
{
    return false;
}

// @0x14251a800
bool AvmDisplayObjContainer::OnLosingKeyboardFocus(InteractiveObject*, unsigned, FocusMovedType)
{
    return true;
}

// @0x14251b0a0
bool AvmDisplayObjContainer::OnUnloading(bool mayRemove)
{
    return AvmDisplayObj::OnUnloading(mayRemove);
}

// @0x14251b0c0
bool AvmInteractiveObj::OnUnloading(bool mayRemove)
{
    return AvmDisplayObj::OnUnloading(mayRemove);
}

// @0x1425190b0
void AvmSprite::OnEventLoad()
{
    SetAS3ObjCollectible(GetAS3Obj());
}

// @0x142519880
void AvmSprite::OnEventUnload()
{
    AvmDisplayObj::OnEventUnload();
}

// @0x14251b0e0
bool AvmSprite::OnUnloading(bool mayRemove)
{
    return AvmDisplayObj::OnUnloading(mayRemove);
}

// -- leaves --

// @0x142510da0
bool FUN_142510da0(UPInt) { return false; }
// @0x142510df0
bool FUN_142510df0(UPInt) { return false; }
// @0x14251a330
bool FUN_14251a330(UPInt) { return false; }
// @0x14251ac90
bool FUN_14251ac90(UPInt) { return false; }
// Tracer::OnOpCode
// @0x14251acb0
bool FUN_14251acb0(UPInt) { return false; }
// @0x142514280
bool FUN_142514280(UPInt) { return true; }
// @0x142518740
bool FUN_142518740(UPInt) { return true; }
// @0x14251a7f0
bool FUN_14251a7f0(UPInt) { return true; }
// @0x14251a810
bool FUN_14251a810(UPInt) { return true; }
// @0x14251af20
bool FUN_14251af20(UPInt) { return true; }
// @0x14251b0f0
bool FUN_14251b0f0(UPInt) { return true; }
// @0x142518470
void FUN_142518470(UPInt) {}
// @0x142518520
void FUN_142518520(UPInt) {}
// @0x14251a0d0
void FUN_14251a0d0(UPInt) {}
// @0x14251a0f0
void FUN_14251a0f0(UPInt) {}
// @0x14251ac80
void FUN_14251ac80(UPInt) {}
// @0x14251acc0
void FUN_14251acc0(UPInt) {}
// @0x14251d060
void FUN_14251d060(UPInt) {}
// @0x1425210c0
void FUN_1425210c0(UPInt) {}
// MS2-FUNCTIONAL: the exe's empty slot is `ret 0`
// @0x1425190d0
void FUN_1425190d0(UPInt) {}
// @0x142514d10
bool FUN_142514d10(UPInt) { return true; }

void FUN_14241e540(Instances::fl::GlobalObjectCPP* self, const ClassInfo* table[]);
// Registers a class table with the VM's global object (+0x298).
// MS2-FUNCTIONAL: raw-layout VM field
// @0x1425210d0
void FUN_1425210d0(VM& vm, const ClassInfo* table[])
{
    FUN_14241e540(reinterpret_cast<Instances::fl::GlobalObjectCPP*>(AccRd(reinterpret_cast<UPInt>(&vm), 0x298)), table);
}

// MS2-FUNCTIONAL: raw-layout getter
// @0x14250ba00
UPInt FUN_14250ba00(UPInt self) { return AccRd(self, 0x40); }
// MS2-FUNCTIONAL: raw-layout getter
// @0x14250d960
UPInt FUN_14250d960(UPInt self) { return AccRd(self, 0xc8); }
// MS2-FUNCTIONAL: raw-layout getter
// @0x14250eef0
UPInt FUN_14250eef0(UPInt self) { return AccRd(AccRd(self, 0x40), 0x18); }

// A float of the render node the handle at +0x48 names (0x38-byte entries on 4K pages, the page's entry table at
// +0x20), 0 for no handle or a node of another type than 3.
// MS2-FUNCTIONAL: raw-layout page walk
// @0x14250d630
float FUN_14250d630(UPInt self)
{
    const UPInt h = AccRd(self, 0x48);
    if (!h)
        return 0.0f;
    const UInt32 idx = (UInt32)((SPInt)((h & 0xfff) - 0x38) / 0x38);
    const UPInt node = AccRd(AccRd(h & ~UPInt(0xfff), 0x20), 0x28 + (UPInt)idx * 8);
    if (*reinterpret_cast<const UInt16*>(node + 8) != 3)
        return 0.0f;
    return *reinterpret_cast<const float*>(node + 0x98);
}

// -- tail calls into the shared bodies --

// MS2-FUNCTIONAL: free-function form of the inherited slot
// @0x142518a10
bool FUN_142518a10(UPInt self, const EventId& id)
{
    return reinterpret_cast<AvmInteractiveObj*>(self)->AvmInteractiveObj::OnEvent(id);
}
// MS2-FUNCTIONAL: free-function form of the inherited slot
// @0x142518fc0
bool FUN_142518fc0(UPInt self, const EventId& id)
{
    return reinterpret_cast<AvmDisplayObj*>(self)->AvmDisplayObj::OnEvent(id);
}
// MS2-FUNCTIONAL: free-function form of the AS3 object's load (AvmDisplayObj::OnEventLoad's body)
// @0x142518fe0
void FUN_142518fe0(UPInt self)
{
    AvmDisplayObj* avm = reinterpret_cast<AvmDisplayObj*>(self);
    avm->SetAS3ObjCollectible(avm->GetAS3Obj());
}
// MS2-FUNCTIONAL: free-function form of the inherited slot
// @0x1425191e0
void FUN_1425191e0(UPInt self)
{
    reinterpret_cast<AvmDisplayObj*>(self)->AvmDisplayObj::OnEventUnload();
}
// MS2-FUNCTIONAL: free-function form of the inherited slot
// @0x142519890
void FUN_142519890(UPInt self)
{
    reinterpret_cast<AvmDisplayObj*>(self)->AvmDisplayObj::OnEventUnload();
}
// MS2-FUNCTIONAL: free-function form of the inherited slot
// @0x1425198b0
void FUN_1425198b0(UPInt self)
{
    reinterpret_cast<AvmDisplayObj*>(self)->AvmDisplayObj::OnEventUnload();
}
// MS2-FUNCTIONAL: free-function form of the inherited slot
// @0x142519d10
void FUN_142519d10(UPInt self, InteractiveObject::FocusEventType event, InteractiveObject* ch, unsigned controllerIdx,
                   FocusMovedType fmt)
{
    // self is already the AvmInteractiveObj base: the exe thunk is a plain jmp, the qualified call through the derived
    // pointer would add 0x30
    reinterpret_cast<AvmInteractiveObj*>(self - 0x30)->AvmInteractiveObj::OnFocus(event, ch, controllerIdx, fmt);
}
// MS2-FUNCTIONAL: free-function form of the inherited slot
// @0x142519ec0
void FUN_142519ec0(UPInt self, InteractiveObject::FocusEventType event, InteractiveObject* ch, unsigned controllerIdx,
                   FocusMovedType fmt)
{
    // self is already the AvmInteractiveObj base: the exe thunk is a plain jmp, the qualified call through the derived
    // pointer would add 0x30
    reinterpret_cast<AvmInteractiveObj*>(self - 0x30)->AvmInteractiveObj::OnFocus(event, ch, controllerIdx, fmt);
}

// MovieRoot slots on its EventChains (+0x150) and MovieImpl (+0x10).
// MS2-FUNCTIONAL: raw-layout MovieRoot slot
// @0x1425184f0
void FUN_1425184f0(UPInt self)
{
    reinterpret_cast<EventChains*>(self + 0x150)->QueueEvents((EventId::IdCode)AS3Event_Controller);
}
// MS2-FUNCTIONAL: raw-layout MovieRoot slot
// @0x142518510
void FUN_142518510(UPInt self, InteractiveObject* pNewFocus, unsigned controllerIdx, FocusMovedType fmt)
{
    reinterpret_cast<MovieImpl*>(AccRd(self, 0x10))->TransferFocus(pNewFocus, controllerIdx, fmt);
}
// activate (0x1000011) or deactivate (0x1000012) to the listening objects.
// MS2-FUNCTIONAL: raw-layout MovieRoot slot
// @0x14251ac40
void FUN_14251ac40(UPInt self, bool activate)
{
    reinterpret_cast<EventChains*>(self + 0x150)->Dispatch((EventId::IdCode)((activate ? 0 : 1) + 0x1000011));
}
// MS2-FUNCTIONAL: raw-layout MovieRoot slot
// @0x14251ac60
void FUN_14251ac60(UPInt self)
{
    reinterpret_cast<EventChains*>(self + 0x150)->QueueEvents((EventId::IdCode)2);
}

// Tracer::Output: passed on to the FlashUI of the traced call frame's VM.
// MS2-FUNCTIONAL: raw-layout walk (CallFrame +0x20 -> +0x28 -> +0x20 -> +0x20)
// @0x14251bda0
void FUN_14251bda0(UPInt self, FlashUI::OutputMessageType type, const char* msg)
{
    reinterpret_cast<FlashUI*>(AccRd(AccRd(AccRd(AccRd(self, 0x20), 0x28), 0x20), 0x20))->Output(type, msg);
}

// -- adjustor thunks (this of a secondary base part back to the object) --

#define SFR21_THUNK(name, off, target) \
    void name(UPInt self) { target(self - off); }
#define SFR21_THUNKB(name, off, target) \
    bool name(UPInt self) { return target(self - off); }

// MS2-FUNCTIONAL: adjustor thunk
// @0x142510da4
SFR21_THUNKB(FUN_142510da4, 0x30, FUN_142510da0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x142510db0
SFR21_THUNKB(FUN_142510db0, 0x40, FUN_142510da0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x142510df4
SFR21_THUNKB(FUN_142510df4, 0x30, FUN_142510df0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x142510e00
SFR21_THUNKB(FUN_142510e00, 0x40, FUN_142510df0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x142514284
SFR21_THUNKB(FUN_142514284, 0x10, FUN_142514280)
// MS2-FUNCTIONAL: adjustor thunk
// @0x142514efc
SFR21_THUNKB(FUN_142514efc, 0x10, AvmButton_IsTabable)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1425150b0
SFR21_THUNKB(FUN_1425150b0, 0x10, AvmTextField_IsTabable)
// MS2-FUNCTIONAL: adjustor thunk
// @0x142518ffc
SFR21_THUNK(FUN_142518ffc, 0x30, FUN_142518fe0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x142519008
SFR21_THUNK(FUN_142519008, 0x40, FUN_142518fe0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1425191bc
SFR21_THUNK(FUN_1425191bc, 0x30, AvmTextField_OnEventLoad)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1425191c8
SFR21_THUNK(FUN_1425191c8, 0x40, AvmTextField_OnEventLoad)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1425191e8
SFR21_THUNK(FUN_1425191e8, 0x30, FUN_1425191e0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1425191f4
SFR21_THUNK(FUN_1425191f4, 0x40, FUN_1425191e0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1425198b8
SFR21_THUNK(FUN_1425198b8, 0x30, FUN_1425198b0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1425198c4
SFR21_THUNK(FUN_1425198c4, 0x40, FUN_1425198b0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x14251a0d4
SFR21_THUNK(FUN_14251a0d4, 0x10, FUN_14251a0d0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x14251a0f4
SFR21_THUNK(FUN_14251a0f4, 0x10, FUN_14251a0f0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x14251a334
SFR21_THUNKB(FUN_14251a334, 0x10, FUN_14251a330)
// MS2-FUNCTIONAL: adjustor thunk
// @0x14251a7f4
SFR21_THUNKB(FUN_14251a7f4, 0x10, FUN_14251a7f0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x14251a814
SFR21_THUNKB(FUN_14251a814, 0x10, FUN_14251a810)
// MS2-FUNCTIONAL: adjustor thunk
// @0x14251af24
SFR21_THUNKB(FUN_14251af24, 0x30, FUN_14251af20)
// MS2-FUNCTIONAL: adjustor thunk
// @0x14251af30
SFR21_THUNKB(FUN_14251af30, 0x40, FUN_14251af20)
// MS2-FUNCTIONAL: adjustor thunk
// @0x14251b0f4
SFR21_THUNKB(FUN_14251b0f4, 0x30, FUN_14251b0f0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x14251b100
SFR21_THUNKB(FUN_14251b100, 0x40, FUN_14251b0f0)

// MS2-FUNCTIONAL: adjustor thunk
// @0x1425190d4
SFR21_THUNK(FUN_1425190d4, 0x30, FUN_1425190d0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1425190e0
SFR21_THUNK(FUN_1425190e0, 0x40, FUN_1425190d0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x142519898
SFR21_THUNK(FUN_142519898, 0x30, FUN_142519890)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1425198a4
SFR21_THUNK(FUN_1425198a4, 0x40, FUN_142519890)

#undef SFR21_THUNK
#undef SFR21_THUNKB

// MS2-FUNCTIONAL: adjustor thunk
// @0x142514304
bool FUN_142514304(UPInt self, UInt32 mode) { return Sfr27TextFieldTabCheck(self - 0x10, mode); }
// MS2-FUNCTIONAL: adjustor thunk
// @0x142518a18
bool FUN_142518a18(UPInt self, const EventId& id) { return FUN_142518a10(self - 0x30, id); }
// MS2-FUNCTIONAL: adjustor thunk
// @0x142518a24
bool FUN_142518a24(UPInt self, const EventId& id) { return FUN_142518a10(self - 0x40, id); }
// MS2-FUNCTIONAL: adjustor thunk
// @0x142518fc8
bool FUN_142518fc8(UPInt self, const EventId& id) { return FUN_142518fc0(self - 0x30, id); }
// MS2-FUNCTIONAL: adjustor thunk
// @0x142518fd4
bool FUN_142518fd4(UPInt self, const EventId& id) { return FUN_142518fc0(self - 0x40, id); }
// MS2-FUNCTIONAL: adjustor thunk
// @0x142519d18
void FUN_142519d18(UPInt self, InteractiveObject::FocusEventType event, InteractiveObject* ch, unsigned controllerIdx,
                   FocusMovedType fmt)
{
    FUN_142519d10(self - 0x10, event, ch, controllerIdx, fmt);
}
// MS2-FUNCTIONAL: adjustor thunk
// @0x142519ec8
void FUN_142519ec8(UPInt self, InteractiveObject::FocusEventType event, InteractiveObject* ch, unsigned controllerIdx,
                   FocusMovedType fmt)
{
    FUN_142519ec0(self - 0x10, event, ch, controllerIdx, fmt);
}
// MS2-FUNCTIONAL: adjustor thunk
// @0x14251a388
bool FUN_14251a388(UPInt self, const EventId& id, int* pkeyMask) { return AvmTextField_OnKeyEvent(self - 0x10, id, pkeyMask); }

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx {

// @0x1425227d0
void InteractiveObject::RemoveDisplayObject(DisplayObjectBase*)
{
}

}} // namespace Scaleform::GFx

// MovieRoot::GetMouseCursorTypeString of the cursor mouse mouseIndex shows (MovieImpl +0x1260: 4 MouseStates of 0x50
// bytes, CursorType at +0x40); an index past them reads through the NULL state, as the exe does.
// MS2-FUNCTIONAL: raw-layout MouseState read; the protected member is reached through a using-declaration
// @0x14250bad0
void FUN_14250bad0(void* proot, Scaleform::GFx::ASString& result, Scaleform::UInt32 mouseIndex)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    struct Access : MovieRoot { using MovieRoot::GetMouseCursorTypeString; };
    const UPInt states = AccRd(reinterpret_cast<UPInt>(proot), 0x10) + 0x1260;
    const UPInt st = mouseIndex < 4 ? states + (UPInt)mouseIndex * 0x50 : 0;
    const UInt32 type = *reinterpret_cast<const volatile UInt32*>(st + 0x40);
    (static_cast<const MovieRoot*>(proot)->*&Access::GetMouseCursorTypeString)(result, type);
}
