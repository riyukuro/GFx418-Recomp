// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_18
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142509d40-0x14250a660 .text$mn
// MS2-RANGE: 0x14250a6c0-0x14250a6f0 .text$mn
// MS2-RANGE: 0x14250a700-0x14250a710 .text$mn
// MS2-RANGE: 0x14250a720-0x142523170 .text$mn
#define SF_AS3_AVMBUTTON_MODEL
#define SF_AS3_SHAPEOBJECT_MODEL   // ShapeObject / AvmBitmap from the SDK MI layout (as3_avm.h)
#define MS2_AS3_ASSIGN_NOALIAS
#define MS2_AS3_CONSTRUCT_NOALIAS   // ConstructInstance result kept in a register (as3_asvm.h)
#define MS2_AS3_SCU   // AS3_All.cpp SCU: AS3_Object.cpp/AS3_Value.cpp AddRef bodies inline (as3_value.h)
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
#include "ms2/scaleform/include/gfx/gfx_rendertree.h"
#include "ms2/scaleform/include/gfx/gfx_imagecreator.h"
#include "ms2/scaleform/include/gfx/gfx_spritedef.h"
#undef GetObject   // windows.h

namespace Scaleform {
// Traits' vtable holder is set through the out-of-line 0x142524290 (sfr_as3_19).
template<> SF_NOINLINE void AutoPtr<GFx::AS3::VTable>::Reset(GFx::AS3::VTable* p, bool owner);
} // namespace Scaleform

// The definitions in sfr_as3_17 and sfr_as3_19 of exe functions called here, by their real names.
namespace Scaleform { namespace GFx { namespace AS3 {
const char* AsString(Abc::NamespaceKind kind);                                                    // 0x1424ed700
void Sfr33CheckObject(VM* const* reader, const Value& v);                                         // 0x1424ef180
void Sfr33FindObjProperty(PropRef& result, VM& vm, const Value& value, const Multiname& mn, int attr);   // 0x142501b00
void Sfr33CollectorQueue(UByte* gc, RefCountImpl* stats);                                         // 0x142504630
void* Sfr33IdWordHashGet(const UByte* self, const UPInt& key);                                    // 0x1425059f0
ClassTraits::Traits** Sfr33ClassTraitsCacheGet(TClassTraitsCache* cache, const Multiname& mn);    // 0x142505aa0
ClassTraits::Traits* Sfr33SlotDataType(const SlotInfo* psi, VM* pvm);                             // 0x1425085b0
UPInt Sfr31ResolveClassTraits(UPInt vm, UPInt file, UPInt mn);                                    // 0x142524f60
UPInt Sfr31FindClassTraitsByMn(UPInt vm, UPInt mn);                                               // 0x142525270
Value* Sfr31ResolveInvokeAlias(UPInt proot, const char* pname);                                   // 0x142525400
ClassTraits::Traits* Sfr31GetClassTraitsByInfo(VM* vm, UPInt info);                               // 0x142525ca0
// noalias: the exe (LTCG) keeps FUN_14250dd20's name Value in registers across this call.
__declspec(noalias) void Sfr27MultinameFromQName(Multiname* mn, const Value* qname);              // 0x1425273b0
void Sfr31SetResource(UPInt bitmap, Resource* pimage);                                            // 0x1425274b0
void Sfr31SetGcRefClearFlags(unsigned long* mn, UPInt ns);                                        // 0x142528d20
void Sfr31VMRaiseError(UPInt vm, const unsigned long* error, UPInt classInfo);                    // 0x14252ecb0
void Sfr31RaiseNameConflict(UPInt tracer, UPInt a, UPInt b);                                      // 0x14252efe0
void Sfr31UnregisterClassTraits(UPInt file);                                                      // 0x142530de0
}}} // namespace Scaleform::GFx::AS3

char* FUN_14250e2d0(const void* si, void* ret, Scaleform::GFx::AS3::VM* vm, Scaleform::GFx::AS3::Value* value, const Scaleform::GFx::AS3::Value* thisValue, void* vtable, int valTarget);   // SlotInfo: read the slot into value
static inline Scaleform::UPInt FUN_142525ca0(Scaleform::UPInt a, Scaleform::UPInt b) { return reinterpret_cast<Scaleform::UPInt>(::Scaleform::GFx::AS3::Sfr31GetClassTraitsByInfo(reinterpret_cast<Scaleform::GFx::AS3::VM*>(a), b)); }
Scaleform::UPInt FUN_1425b7e60(Scaleform::UPInt textField);
// out of line in the exe
template<> Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>&
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(Scaleform::GFx::AS3::Instances::fl::Object* p);
// Value::operator=(const ASString&), out of line in the exe
Scaleform::GFx::AS3::Value& FUN_1424e0d40(Scaleform::GFx::AS3::Value& v, const Scaleform::GFx::ASString& str);
// The AS3 global-object lookups (sfr_as3_04).
Scaleform::GFx::AS3::Instances::Namespace* FUN_142415c20(Scaleform::GFx::AS3::InstanceTraits::fl::Namespace* self,
                                                         Scaleform::GFx::AS3::Abc::NamespaceKind kind,
                                                         const Scaleform::GFx::ASString& uri,
                                                         const Scaleform::GFx::AS3::Value& prefix);
Scaleform::GFx::AS3::ClassTraits::Traits** FUN_142414ac0(Scaleform::GFx::AS3::TClassTraitsCache* self,
                                                         const Scaleform::GFx::ASString& name,
                                                         const Scaleform::GFx::AS3::Instances::Namespace& ns);
Scaleform::GFx::AS3::ClassTraits::Traits* FUN_142415520(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP* self,
                                                        const Scaleform::GFx::ASString& name,
                                                        const Scaleform::GFx::AS3::Instances::Namespace& ns);   // class traits by name
const void* FUN_142416e70(const char* self);   // the return type of a function's method
void FUN_1424187f0(Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript* self);   // its classes' instance traits
void FUN_14241e540(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP* self, const Scaleform::GFx::AS3::ClassInfo* table[]);
template<> void Scaleform::ArrayDataDH<Scaleform::UPInt, Scaleform::AllocatorDH_POD<Scaleform::UPInt, 328>, Scaleform::ArrayDefaultPolicy>::Resize(Scaleform::UPInt newSize);
template<> void Scaleform::ArrayData<Scaleform::UPInt, Scaleform::AllocatorLH_POD<Scaleform::UPInt, 338>, Scaleform::ArrayDefaultPolicy>::Resize(Scaleform::UPInt newSize);
template<> void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>, 2>, Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, Scaleform::UPInt newSize);
template<> void Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>, 2>, Scaleform::ArrayDefaultPolicy>::Resize(Scaleform::UPInt newSize);   // 0x142524680
template<> Scaleform::String Scaleform::AsString<Scaleform::UInt32>(const Scaleform::UInt32& v);   // 0x1423e8390
// The VTable copy's out-of-line pieces (sfr_as3_17, sfr_as3_19); the ASString element copy stays inline as in the exe.
template<> void Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::ConstructArray(void* p, Scaleform::UPInt count, const Scaleform::GFx::AS3::Value* psource);   // 0x1424f08d0
template<> void Scaleform::ArrayDataBase<Scaleform::GFx::ASString, Scaleform::AllocatorLH<Scaleform::GFx::ASString, 331>, Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, Scaleform::UPInt newSize);   // 0x142524d80
static inline void FUN_1424fa320(Scaleform::GFx::AS3::MovieRoot* proot, unsigned level) { proot->ExecuteActionQueue(static_cast<Scaleform::GFx::AS3::MovieRoot::ActionLevel>(level)); }   // MovieRoot::ExecuteActionQueue(ActionLevel)
bool FUN_142506000(const Scaleform::GFx::AS3::MovieRoot* proot, Scaleform::GFx::AS3::Value* pval, const char* ppathToVar);   // MovieRoot::GetASVariableAtPath
Scaleform::GFx::AS3::AvmInteractiveObj* FUN_1424f4000(Scaleform::GFx::AS3::MovieRoot* proot, Scaleform::GFx::MovieDefImpl* pmovieDef);   // MovieRoot::CreateStage

namespace Scaleform { namespace GFx { namespace AS3 {

// The VM of the tracer's call frame (Tracer::CF at +0x20, as3_tracer.h; that header is not included here).
static SF_INLINE VM& Sfr18TracerVM(const void* tracer)
{
    return (*reinterpret_cast<const CallFrame* const*>(static_cast<const UByte*>(tracer) + 0x20))->GetVM();
}
// @0x14250a1b0
__declspec(noinline) InstanceTraits::Traits& TR::State::GetFunctType(const Value& value) const
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

// Value(Object*) as the exe inlines it here (its out-of-line copy is sfr_as3_15's 0x1424dc050).
SF_FORCEINLINE Value::Value(Object* v, InlineObjType)
    : Flags(kObject)
    , value(v)
{
    if (v)
        v->AddRef();
}

// @0x14250c230
const Value& Value::GetNull()
{
    static const Value v((Object*)NULL, Value::InlineObj);
    return v;
}

// @0x14250f8f0
const Value& Value::GetUndefined()
{
    static const Value undefinedValue;
    return undefinedValue;
}

// The interned namespace {kind, uri}, else the public one (prefix unused here).

// The exe tail-calls the lookup-only 0x142415c20, which falls back to the public namespace and never creates one.
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

// A null C string is taken as empty before interning. The string manager is read before the null test.
// @0x14250ab50
Instances::Namespace& VM::GetInternedNamespace(Abc::NamespaceKind kind, const char* name) const
{
    ASStringManager* sm = GetStringManager().GetStringManager();
    return GetInternedNamespace(kind, sm->CreateString(name ? name : ""));
}

// @0x14250a900
// The traits a value's instances have: the boxed primitive's for primitives (Object's for a null string,
// function, object or class), the value's own for tracer instance-traits tags, void otherwise.
const InstanceTraits::Traits& VM::GetInstanceTraits(const Value& v) const
{
    const Value::KindType k = v.GetKind();
    switch (k)
    {
    case Value::kUndefined:
        break;
    case Value::kBoolean:
        return GetClassTraitsBoolean().GetInstanceTraits();
    case Value::kInt:
        return GetClassTraitsSInt().GetInstanceTraits();
    case Value::kUInt:
        return GetClassTraitsUInt().GetInstanceTraits();
    case Value::kNumber:
        return GetClassTraitsNumber().GetInstanceTraits();
    case Value::kString:
        if (v.GetStringNode())
            return GetClassTraitsString().GetInstanceTraits();
        else
            return GetClassTraitsObject().GetInstanceTraits();
    case Value::kNamespace:
        return GetClassTraitsNamespace().GetInstanceTraits();
    case Value::kFunction:
    case Value::kObject:
    case Value::kThunkFunction:
        if (v.IsNull())
            return GetClassTraitsObject().GetInstanceTraits();
        else
            return static_cast<InstanceTraits::Traits&>(v.GetObject()->GetTraits());
    case Value::kClass:
        if (v.IsNull())
            return GetClassTraitsObject().GetInstanceTraits();
        else
            return v.AsClass().GetClassTraits().GetInstanceTraits();
    case Value::kThunk:
    case Value::kThunkClosure:
        return static_cast<ClassTraits::Function&>(GetClassTraitsFunction()).GetThunkTraits();
    case Value::kVTableInd:
    case Value::kVTableIndClosure:
        return static_cast<ClassTraits::Function&>(GetClassTraitsFunction()).GetVTableTraits();
    case Value::kInstanceTraits:
        return v.GetInstanceTraits();
    case Value::kClassTraits:
        {
            const ClassTraits::Traits& ctr = v.GetClassTraits();
            if (ctr.ITraits.GetPtr() != NULL)   // ctr.IsValid()
                return ctr.GetInstanceTraits();
        }
    case Value::kMethodInd:
        break;
    }

    return GetITraitsVoid();
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
// The weak proxy is cleared in each branch, which gives the exe its store order.
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
        Bonus.pWeakProxy = NULL;
    }
    else
    {
        value.VS._1.VObj = NULL;
        SetKind(kUndefined);
        value.VS._2.VObj = NULL;
        Bonus.pWeakProxy = NULL;
    }

    Flags &= ~weakRefMask;
    return true;
    }
    return false;
}

// @0x142522190
void Value::ReleaseWeakRef()
{
    Bonus.pWeakProxy->Release();
    Bonus.pWeakProxy = NULL;
    Flags &= ~(kindMask | weakRefMask);
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
    const Value::KindType kind = GetKind();
    switch (kind)
    {
    case kString:
        value.VS._1.VStr->Release();
        break;
    case kNamespace:
        {
            Instances::Namespace* ns = value.VS._1.VNs;
            if ((UPInt)ns & 1)
                value.VS._1.VNs = (Instances::Namespace*)((UPInt)ns - 1);
            else if (ns)
                ns->Release();
        }
        break;
    case kClass:
    case kFunction:
    case kThunkFunction:
    case kObject:
        {
            Object* obj = value.VS._1.VObj;
            if ((UPInt)obj & 1)
                value.VS._1.VObj = (Object*)((UPInt)obj - 1);
            else if (obj)
                obj->Release();
        }
        break;
    case kThunkClosure:
    case kVTableIndClosure:
        {
            Object* obj = value.VS._2.VObj;
            if ((UPInt)obj & 1)
                value.VS._2.VObj = (Object*)((UPInt)obj - 1);
            else if (obj)
                obj->Release();
        }
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
    bool result = false;
    if (v.IsObject() && v.GetObject())
    {
        const Traits& tr = v.GetObject()->GetTraits();
        if (tr.GetTraitsType() == Traits_QName && tr.IsInstanceTraits())
            result = true;
    }
    return result;
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

// The exe's Value::Assign/AssignUnsafe copies (sfr_as3_03 defines the out-of-line ones).
struct ValueAssignCopies
{
    static void AssignUnsafeFunction(Value& v, Instances::Function* p);    // 0x1424053f0
    static void AssignUnsafeNamespace(Value& v, Instances::Namespace* p);  // 0x142405420
    // Value::AssignUnsafe(Object*/Class*), which the exe inlines here.
    template <typename T>
    static SF_INLINE void AssignUnsafeInline18(Value& v, Value::KindType kind, T* p)
    {
        v.SetKind(kind);
        v.value = p;
        if (p)
            p->AddRef();
    }
    // Value::AssignUnsafe(const ASString&), which the exe inlines in the slot reader.
    static SF_FORCEINLINE void AssignUnsafeStrInline18(Value& v, const ASString& s)
    {
        if (s.GetNode() == s.GetManager()->GetNullStringNode())
        {
            v.value = (ASStringNode*)NULL;
            v.SetKind(Value::kObject);   // null has type Object
        }
        else
        {
            v.SetKind(Value::kString);
            v.value = s.GetNode();
            v.AddRefString();
        }
    }
    // Value::Assign(const Value&), which the exe inlines in InvokeClosure.
    static SF_FORCEINLINE void AssignInline18(Value& v, const Value& other)
    {
        if (&other != &v)
        {
            v.Release();
            SIMD::PrefetchObj(&other);
            memcpy(&v, &other, sizeof(Value));
            v.AddRef();
        }
    }
    // The same for a pointer known to be non-null (Value(this)).
    static SF_INLINE void AssignUnsafeObjectInline18(Value& v, Object* p)
    {
        v.SetKind(Value::kObject);
        v.value.VS._1.VObj = p;
        p->AddRef();
    }
    // Value::AssignUnsafe(const Value&) (sfr_as3_17), which the exe inlines in Object::GetProperty.
    static SF_FORCEINLINE void AssignUnsafeValueInline18(Value& v, const Value& other)
    {
        if (&other != &v)
        {
            SIMD::PrefetchObj(&other);
            memcpy(&v, &other, sizeof(Value));
            v.AddRef();
        }
    }
    // Value(this) built in place: flags first, then the bonus and the pointer.
    static SF_INLINE void InitObjectInline18(Value& v, Object* p)
    {
        v.Flags            = Value::kObject;
        v.Bonus.pWeakProxy = NULL;
        v.value.VS._1.VObj = p;
        p->AddRef();
    }
    // The release of a Value known to hold a strong object (no kind or weak-ref test).
    static SF_INLINE void ReleaseStrongInline18(Value& v) { v.ReleaseInternal(); }
    // Value(Object*) built in place, with its null test.
    static SF_INLINE void InitObjectNullInline18(Value& v, Object* p)
    {
        v.Flags            = Value::kObject;
        v.Bonus.pWeakProxy = NULL;
        v.value.VS._1.VObj = p;
        if (p)
            p->AddRef();
    }
    // Value::AssignUnsafe(const Value&) without the self test, as the Multiname ctor inlines it.
    static SF_FORCEINLINE void AssignFreshInline18(Value& v, const Value& other)
    {
        v.Release();
        SIMD::PrefetchObj(&other);
        memcpy(&v, &other, sizeof(Value));
        v.AddRef();
    }
};

// The value of a traced pointer: a null object when it is empty.
// @0x1425100f0
void STPtr::GetValueUnsafe(Value& v)
{
    if (pObject)
    {
        ObjType* p = GetRawAddr();
        switch (AS3::GetObjectTag(reinterpret_cast<UPInt>(pObject)))
        {
        case Value::otObject:
            ValueAssignCopies::AssignUnsafeInline18(v, Value::kObject, static_cast<Object*>(p));
            return;
        case Value::otClass:
            ValueAssignCopies::AssignUnsafeInline18(v, Value::kClass, static_cast<Class*>(p));
            return;
        case Value::otFunction:
            ValueAssignCopies::AssignUnsafeFunction(v, reinterpret_cast<Instances::Function*>(p));   // (not modeled; its counted base is first)
            return;
        case Value::otNamespace:
            ValueAssignCopies::AssignUnsafeNamespace(v, static_cast<Instances::Namespace*>(p));
            return;
        default:
            break;
        }
    }
    (v.*&Value::SetNull)();
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

// Plain inline, not SF_INLINE: cl then inlines the two array copies into this ctor and the ctor into GetVT, as the exe
// does. Under __forceinline the array copy ctors stay out of line.
inline VTable::VTable(Traits& tr, const VTable& parent)
    : pTraits(&tr), VTMethods(parent.VTMethods), Names(parent.Names)
{
}

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

// MS2-FUNCTIONAL: the SDK Slots::CIterator loop (a local iterator struct, GetSlotInfo one level inline as in the exe).
// The exe releases the name from the register it was loaded into, not from the ASString temp (LTCG knows that
// AddDynamicSlotValuePair leaves it alone). Here the name is a node copy viewed as an ASString, released in the same
// full expression so that it still goes before the result Value's dtor. Left: the first slot-count test sums into
// r9 where the exe uses r8.
// @0x142511890
void Class::InitPrototypeFromVTable(AS3::Object& obj, ConvertFunc f) const
{
    const InstanceTraits::Traits& itr = GetClassTraits().GetInstanceTraits();
    const VTable& vt = itr.GetVT();
    struct CIt
    {
        AbsoluteIndex Ind;
        const Slots*  Parent;
        SF_INLINE CIt(const Slots& p, AbsoluteIndex ind) : Ind(ind), Parent(&p) {}
        SF_INLINE bool IsEnd() const { return static_cast<UInt32>(Ind.Get()) >= Parent->VArray.GetSize() + Parent->FirstOwnSlotNum; }
        SF_INLINE void Next() { if (Ind < Parent->GetSlotInfoNum()) Ind = AbsoluteIndex(Ind.Get() + 1); }
        SF_INLINE const SlotInfo& GetSlotInfo() const { return Sfr18GetSlotInfo(*Parent, Ind); }
        SF_INLINE ASStringNode* GetSlotName() const { return Parent->GetSlotNameNode(Ind); }
    };
    for (CIt it(itr, AbsoluteIndex(0)); !it.IsEnd(); it.Next())
    {
        const SlotInfo& si = it.GetSlotInfo();
        if (si.BindType == SlotInfo::BT_Code)
        {
            ASStringNode* sn = it.GetSlotName();
            const Value&  m = vt.VTMethods[static_cast<UInt32>(si.ValueInd)];
            sn->AddRef();
            ASStringNode* name = sn;
            obj.AddDynamicSlotValuePair(reinterpret_cast<const ASString&>(name),
                                        (this->*f)(m, itr),
                                        SlotInfo::aDontEnum),
                sn->Release();
        }
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
SF_NOINLINE MovieRoot::ActionEntry* MovieRoot::InsertEmptyAction(ActionLevel lvl)
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

// @0x1425189a0
SF_NOINLINE void AvmDisplayObj::OnDetachFromTimeline()
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
}

// The traits a tracer value stands for: undefined is void, traits values themselves, the rest their own class.
// Class is read as Object.
static SF_FORCEINLINE const Traits* TraceValueTraits(const Tracer& tr, const Value& v)
{
    const Traits* t = NULL;
    switch (v.GetKind())
    {
    case Value::kUndefined:
        t = &tr.GetVM().GetITraitsVoid();
        break;
    case Value::kInstanceTraits:
        t = &v.GetInstanceTraits();
        break;
    case Value::kClassTraits:
        t = &v.GetClassTraits();
        break;
    default:
        t = &tr.GetVM().GetValueTraits(v);
    }
    if (t && t == &tr.GetVM().GetClassTraitsClassClass())
        t = &tr.GetVM().GetClassTraitsObject();
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

}}}} // namespace Scaleform::GFx::AS3::TR

namespace Scaleform { namespace GFx { namespace AS3 {

// int, uint or Number
// @0x142514510
__declspec(noinline) bool Tracer::IsNumericType(const Traits* tr) const
{
    return tr == &GetSIntType() || tr == &GetUIntType() || tr == &GetNumberType();
}

// Boolean, void, null or numeric: no reference counting needed
// @0x142514420
bool Tracer::IsNotRefCountedType(const Traits* tr) const
{
    return tr == &GetBooleanType() || tr == &GetVoidType() || tr == &GetVM().GetITraitsNull() || IsNumericType(tr);
}

// Boolean, void, null, numeric or String
// @0x142514a80
bool Tracer::IsPrimitiveType(const Traits* tr) const
{
    if (tr != &GetBooleanType() && tr != &GetVoidType() && tr != &GetVM().GetITraitsNull())
    {
        if (!IsNumericType(tr) && tr != &GetStringType())
            return false;
    }
    return true;
}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 { namespace TR {

// @0x14250fe80
__declspec(noinline) const Traits* State::GetValueTraits(const Value& v) const
{
    return TraceValueTraits(*static_cast<const Tracer*>(pTracer), v);
}

}}}} // namespace Scaleform::GFx::AS3::TR

namespace Scaleform { namespace GFx { namespace AS3 {

// For super_tr the call frame's origination traits (else the value's traits), then their parent.
// @0x14250ff00
const Traits* Tracer::GetValueTraits(const Value& v, bool super_tr) const
{
    const Traits* result = NULL;
    if (super_tr)
        result = CF.OriginationTraits;
    if (result == NULL)
        result = TR::TraceValueTraits(*this, v);
    if (super_tr && result)
        result = result->GetParent();
    return result;
}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 { namespace TR {

}}}} // namespace Scaleform::GFx::AS3::TR

namespace Scaleform { namespace GFx { namespace AS3 {

// The unsigned 30-bit operand following the opcode of the cp-th last instruction.
// @0x14250c1f0
int Tracer::GetNextU30(UPInt cp) const
{
    UPInt pos = OrigOpcodePos[OrigOpcodePos.GetSize() - cp - 1] + 1;
    return Abc::ReadU30<UInt8>(pCode, pos);
}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 { namespace TR {

}}}} // namespace Scaleform::GFx::AS3::TR

// ---- TR::State operand stack pops ----
namespace Scaleform { namespace GFx { namespace AS3 { namespace TR {

// @0x14251ccc0
void State::PopOp(UPInt n)
{
    OpStack.PopBack(n);
}

// The top operand returned, then popped.
// @0x14251cd30
__declspec(noinline) Value State::PopOpValue()
{
    Value result(OpStack.Back());
    OpStack.PopBack(1);
    return result;
}

}}}} // namespace Scaleform::GFx::AS3::TR

// ---- PropRef value reads ----
namespace Scaleform { namespace GFx { namespace AS3 {

// The found property's value, getters not run for valGet. The three tags of the reference: a slot, a dynamic value
// (tagged pointer) or a closure object.
// @0x14250e200
CheckResult PropRef::GetSlotValueUnsafe(VM& vm, Value& value, SlotInfo::ValTarget vt) const
{
    bool ok = true;
    const UPInt w = reinterpret_cast<UPInt>(pValue);
    switch (w & 3)
    {
    case 0:
    {
        char r;     // the callee's result slot
        ok = *reinterpret_cast<const bool*>(FUN_14250e2d0(pSI, &r, &vm, &value, &This, NULL, vt));
        break;
    }
    case 1:
        value.AssignUnsafe(*reinterpret_cast<const Value*>(w & ~static_cast<UPInt>(1)));
        break;
    case 2:
        ValueAssignCopies::AssignUnsafeInline18(value, Value::kObject, reinterpret_cast<Object*>(w & ~static_cast<UPInt>(2)));
        break;
    }
    return CheckResult(ok);
}

// The same with the vtable to read methods from.
// A view for the member form: the exe returns the CheckResult through the hidden slot as PropRef::GetSlotValueUnsafe does.
struct Sfr27PropRefView : PropRef
{
    CheckResult GetSlotValueVT(VM* vm, Value* value, VTable* vtable) const;
};

// @0x14250e130
CheckResult Sfr27PropRefView::GetSlotValueVT(VM* vm, Value* value, VTable* vtable) const
{
    bool ok = true;
    const UPInt w = reinterpret_cast<UPInt>(pValue);
    switch (w & 3)
    {
    case 0:
    {
        char r;     // the callee's result slot
        ok = *reinterpret_cast<const bool*>(FUN_14250e2d0(pSI, &r, vm, value, &This, vtable, 0));
        break;
    }
    case 1:
        value->AssignUnsafe(*reinterpret_cast<const Value*>(w & ~static_cast<UPInt>(1)));
        break;
    case 2:
        ValueAssignCopies::AssignUnsafeInline18(*value, Value::kObject, reinterpret_cast<Object*>(w & ~static_cast<UPInt>(2)));
        break;
    }
    return CheckResult(ok);
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

// ---- Tracer word-code writers and block bookkeeping ----

namespace Scaleform { namespace GFx { namespace AS3 {

// Tracer::PushNewOpCode: op at the word code's end, its position noted in NewOpcodePos.
// @0x14251f930
__declspec(noinline) void Tracer::PushNewOpCode(Abc::Code::OpCode op)
{
    NewOpcodePos.PushBack(WCode.GetSize());
    WCode.PushBack(static_cast<UPInt>(static_cast<SPInt>(op)));
}

// The same with one argument word.
// @0x14251fb90
void Tracer::PushNewOpCode(Abc::Code::OpCode op, UPInt arg1)
{
    NewOpcodePos.PushBack(WCode.GetSize());
    WCode.PushBack(static_cast<UPInt>(static_cast<SPInt>(op)));
    WCode.PushBack(arg1);
}

// The same with two argument words.
// @0x14251fa10
void Tracer::PushNewOpCode(Abc::Code::OpCode op, UPInt arg1, UPInt arg2)
{
    NewOpcodePos.PushBack(WCode.GetSize());
    WCode.PushBack(static_cast<UPInt>(static_cast<SPInt>(op)));
    WCode.PushBack(arg1);
    WCode.PushBack(arg2);
}

// Tracer::PushNewOpCodeArg: one argument word at the word code's end.
// @0x14251fcd0
__declspec(noinline) void Tracer::PushNewOpCodeArg(UPInt code)
{
    WCode.PushBack(code);
}

}}} // namespace Scaleform::GFx::AS3

// Slots 1 and 2 of the 3-slot vftable 0x14317f848 (the class whose deleting destructors 0x1424e2c90 and 0x1424e3a00
// store it): forward to the tracer held at +0x10 of the second argument.
// @0x14251aca0
void FUN_14251aca0(void*, void* p, int op)
{
    (*reinterpret_cast<Scaleform::GFx::AS3::Tracer**>(static_cast<char*>(p) + 0x10))
        ->PushNewOpCode(static_cast<Scaleform::GFx::AS3::Abc::Code::OpCode>(op));
}

// @0x14251acd0
void FUN_14251acd0(void*, Scaleform::UPInt p, Scaleform::UPInt arg)
{
    (*reinterpret_cast<Scaleform::GFx::AS3::Tracer**>(p + 0x10))->PushNewOpCodeArg(arg);
}

namespace Scaleform { namespace GFx { namespace AS3 {

// Tracer::PopNewOpCode: the last new opcode and its arguments dropped from the word code.
// @0x14251cc80
void Tracer::PopNewOpCode()
{
    ArrayDH_POD<UPInt, StatMV_VM>& pos = NewOpcodePos;
    const UPInt top = pos.Back();
    pos.Resize(pos.GetSize() - 1);
    WCode.Resize(top);
}

// Tracer::RegisterOrigOpCode: a byte code position inside the code becomes the current one, is noted in
// OrigOpcodePos and maps to the word code's end.
// @0x1425212f0
void Tracer::RegisterOrigOpCode(Abc::TCodeOffset opcode_cp)
{
    if (opcode_cp >= CodeEnd)
        return;
    CurrOffset = opcode_cp;
    OrigOpcodePos.PushBack(opcode_cp);
    Orig2newPosMap[opcode_cp] = WCode.GetSize();
}

// The traced value of the global object: the saved scope's first value or else the method's 'this' (the state's
// first register).
// @0x14250a490
Value Tracer::GetGlobalObject(const TR::State& st) const
{
    if (CF.pSavedScope && CF.pSavedScope->GetSize() != 0)
        return (*CF.pSavedScope)[0];
    return st.GetRegisters()[0];
}

}}} // namespace Scaleform::GFx::AS3

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

// ---- TR::State opcode refinement (private State members; sfr_as3_19 calls them through FUN_ decls) ----

namespace Scaleform { namespace GFx { namespace AS3 { namespace TR {
namespace {
// Values of int, uint, Number and Boolean are never null (State::CanBeNull / Tracer::IsNotNullableType, inlined).
SF_FORCEINLINE Value::TraceNullType TrNullTypeOf(const Tracer& t, const InstanceTraits::Traits& traits)
{
    if (&traits == &t.GetSIntType() || &traits == &t.GetUIntType() || &traits == &t.GetNumberType() ||
        &traits == &t.GetBooleanType())
        return Value::NotNull;
    return Value::NullOrNot;
}
}
}}}} // namespace Scaleform::GFx::AS3::TR

namespace Scaleform { namespace GFx { namespace AS3 { namespace TR {

// The last opcode written becomes op when register reg_num already has type's traits; else the register is converted
// to type. The register's index follows as the argument word.
// @0x142520d80
void State::RefineOpCodeReg1(InstanceTraits::Traits& type, Abc::Code::OpCode op, int reg_num)
{
    Tracer& tr = *static_cast<Tracer*>(pTracer);
    if (GetValueTraits(Registers[static_cast<UInt32>(reg_num)]) == &type)
        tr.ReplaceOpCode(op);
    else
        ConvertRegisterTo(reg_num, type, TrNullTypeOf(tr, type));
    static_cast<Tracer*>(pTracer)->PushNewOpCodeArg(static_cast<UInt32>(reg_num));
}

// The same for the operand stack top.
// @0x142520e60
void State::RefineOpCodeStack1(InstanceTraits::Traits& type, Abc::Code::OpCode op)
{
    Tracer& tr = *static_cast<Tracer*>(pTracer);
    if (GetValueTraits(OpStack.Back()) == &type)
        tr.ReplaceOpCode(op);
    else
        ConvertOpTo(type, TrNullTypeOf(tr, type));
}

// The same for the top two operands (the top one is popped; the one left is converted).
// @0x142520f30
__declspec(safebuffers) void State::RefineOpCodeStack2(InstanceTraits::Traits& type, Abc::Code::OpCode op)
{
    Value popped = PopOpValue();
    // the exe inlines State::GetValueTraits for the popped value only
    if (GetValueTraits(OpStack.Back()) == &type && TraceValueTraits(*static_cast<const Tracer*>(pTracer), popped) == &type)
        static_cast<Tracer*>(pTracer)->ReplaceOpCode(op);
    else
        ConvertOpTo(type, TrNullTypeOf(*static_cast<Tracer*>(pTracer), type));
}

}}}} // namespace Scaleform::GFx::AS3::TR

// ---- Tracer merging of the block entry states ----
static inline void FUN_14252efe0(Scaleform::UPInt tracer, Scaleform::UPInt a, Scaleform::UPInt b) { ::Scaleform::GFx::AS3::Sfr31RaiseNameConflict(tracer, a, b); }   // raises verify error 0x42c (sfr_as3_19)
namespace Scaleform { namespace GFx { namespace AS3 { namespace TR {


}}}}

namespace Scaleform { namespace GFx { namespace AS3 {

namespace {
// Tracer::IsNumericType / IsNotNullableType, which the exe inlines here
SF_FORCEINLINE bool TrIsNumericType(const Tracer& t, const Traits* tr)
{
    return tr == &t.GetSIntType() || tr == &t.GetUIntType() || tr == &t.GetNumberType();
}
SF_FORCEINLINE bool TrIsNotNullableType(const Tracer& t, const InstanceTraits::Traits* tr)
{
    return TrIsNumericType(t, tr) || tr == &t.GetBooleanType();
}
// Tracer::CanBeNull(const InstanceTraits::Traits&) (sfr_as3_17), which the exe inlines here
SF_FORCEINLINE Value::TraceNullType TrCanBeNull(const Tracer& t, const InstanceTraits::Traits& traits)
{
    return TrIsNotNullableType(t, &traits) ? Value::NotNull : Value::NullOrNot;
}
}

// Object (or Class) instance traits.
// @0x142513f50
__declspec(noinline) bool Tracer::IsAnyType(const Traits* tr) const
{
    return tr == &GetVM().GetClassTraitsObject().GetInstanceTraits() ||
           tr == &GetVM().GetClassTraitsClassClass().GetInstanceTraits();
}

// @0x142515840
__declspec(safebuffers) void Tracer::JoinSNodesUpdateType(Value& to_be_merged, const Value& from, ClassTraits::Traits& tr) const
{
    // If a new type is always not null, then there is no reason to check "to" and "from".
    Value::TraceNullType null = TrCanBeNull(*this, tr.GetInstanceTraits());
    if (null != Value::NotNull)
        null = AS3::CanBeNull(to_be_merged, from);
    to_be_merged.Assign(Value(tr, null));
}

// @0x142515930
__declspec(noinline) __declspec(safebuffers) void Tracer::JoinSNodesUpdateType(Value& to_be_merged, const Value& from,
                                                                               InstanceTraits::Traits& tr) const
{
    // If a new type is always not null, then there is no reason to check "to" and "from".
    Value::TraceNullType null = TrCanBeNull(*this, tr);
    if (null != Value::NotNull)
        null = AS3::CanBeNull(to_be_merged, from);
    to_be_merged.Assign(Value(tr, null));
}

// Merges entry ind of from's operand stack / scope stack / register file into to's; a type conflict raises the
// verify error and fails.
// The lists are picked by two NULL-start switches (the exe's sub/cmp/lea prologue). The common-base search is a
// lambda so the found flag is set once before the class/instance join, as in the exe. The exe indexes the
// register-changed bits with a 32-bit register number.
// The register bits are tested through an SDK `const unsigned i` local in each block (BitSet::IsSet form).
// MS2-FUNCTIONAL 0x1425178e0: register allocation only: r12/r15 swapped, and in the register-file blocks the exe
// keeps ind in r12 and from in rsi where ours keeps ind in rsi and reloads from (1413 vs 1414 bytes)
// @0x1425178e0
__declspec(safebuffers) CheckResult Tracer::MergeValues(UPInt ind, TR::State& to, const TR::State& from, TR::MergeSet ms)
{
    ArrayDH<Value>* to_list = NULL;
    switch (ms)
    {
    case TR::msOpStack:      to_list = &to.GetOpStack(); break;
    case TR::msScopeStack:   to_list = &to.GetScopeStack(); break;
    case TR::msRegisterFile: to_list = &to.GetRegisters(); break;
    }
    const ArrayDH<Value>* from_list = NULL;
    switch (ms)
    {
    case TR::msOpStack:      from_list = &from.GetOpStack(); break;
    case TR::msScopeStack:   from_list = &from.GetScopeStack(); break;
    case TR::msRegisterFile: from_list = &from.GetRegisters(); break;
    }
    Value& tv = (*to_list)[ind];
    const Value& fv = (*from_list)[ind];
    const Traits* t1 = TR::TraceValueTraits(*this, tv);
    const Traits* t2 = TR::TraceValueTraits(*this, fv);

    if (ms == TR::msScopeStack)
    {
        if (tv.GetWith() != fv.GetWith())
            goto fail;
    }
    else if (ms == TR::msRegisterFile)
    {
        const unsigned i = static_cast<unsigned>(ind);
        if (!from.IsRegChanged(i))
            goto update;
        if (!to.IsRegChanged(i))
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
            InstanceTraits::Traits& objTr = GetVM().GetClassTraitsObject().GetInstanceTraits();
            if (t1 == &objTr || t1 == &GetVM().GetClassTraitsClassClass().GetInstanceTraits())
                ;
            else if (IsAnyType(t2))
                JoinSNodesUpdateType(tv, fv, objTr);
            else
            {
                const bool num1 = IsNumericType(t1);
                if (num1 && IsNumericType(t2))
                    JoinSNodesUpdateType(tv, fv, GetNumberType());
                else if (tv.IsNull() || t1 == &GetVM().GetITraitsNull())
                {
                    if (fv.IsNull() || t2 == &GetVM().GetITraitsNull())
                        ;
                    else if (t2 != &GetStringType() && IsNumericType(t2))
                        goto fail;
                    else
                        tv.Assign(fv);
                }
                else if (fv.IsNull() || t2 == &GetVM().GetITraitsNull())
                {
                    if (t1 != &GetStringType() && num1)
                        goto fail;
                }
                else
                {
                    // the nearest common base: mark t1's chain, find the first marked one on t2's
                    for (const Traits* t = t1; t != NULL; t = t->GetParent())
                        t->Flags |= Traits::TmpBitMask;
                    // bit 7 = TmpBitMask, bit 5 = IsClassTraits(); the unsigned byte shifts give the exe's shr
                    bool found;
                    [&] {
                        for (const Traits* t = t2; t != NULL; t = t->GetParent())
                        {
                            if ((UByte)((UPInt)t->Flags >> 7) & 1)
                            {
                                found = true;
                                if ((UByte)((UPInt)t->Flags >> 5) & 1)
                                    JoinSNodesUpdateType(tv, fv, const_cast<ClassTraits::Traits&>(
                                                                     static_cast<const ClassTraits::Traits&>(*t)));
                                else
                                    JoinSNodesUpdateType(tv, fv, const_cast<InstanceTraits::Traits&>(
                                                                     static_cast<const InstanceTraits::Traits&>(*t)));
                                return;
                            }
                        }
                        found = false;
                    }();
                    for (const Traits* t = t1; t != NULL; t = t->GetParent())
                        t->Flags &= ~static_cast<SPInt>(Traits::TmpBitMask);
                    if (!found)
                        goto fail;
                }
            }
        }
    }

    if (ms == TR::msRegisterFile)
    {
    update:
        const unsigned i = static_cast<unsigned>(ind);
        const bool isAlive = from.IsRegChanged(i) || to.IsRegChanged(i);
        to.SetRegChanged(i, isAlive);
    }
    return true;

fail:
    FUN_14252efe0(reinterpret_cast<UPInt>(this), reinterpret_cast<UPInt>(t1), reinterpret_cast<UPInt>(t2));
    return false;
}

// Merges from's operand stack / scope stack / register file into to's, entry by entry; to grows to from's size
// unless sizes must agree (update).
// @0x142517740
__declspec(safebuffers) CheckResult Tracer::MergeLists(TR::State& to, const TR::State& from, bool update, TR::MergeSet ms)
{
    ArrayDH<Value>* to_list = NULL;
    switch (ms)
    {
    case TR::msOpStack:      to_list = &to.GetOpStack(); break;
    case TR::msScopeStack:   to_list = &to.GetScopeStack(); break;
    case TR::msRegisterFile: to_list = &to.GetRegisters(); break;
    }
    const ArrayDH<Value>* from_list = NULL;
    switch (ms)
    {
    case TR::msOpStack:      from_list = &from.GetOpStack(); break;
    case TR::msScopeStack:   from_list = &from.GetScopeStack(); break;
    case TR::msRegisterFile: from_list = &from.GetRegisters(); break;
    }
    if (update && to_list->GetSize() != from_list->GetSize())
        return false;
    for (UPInt i = 0; i < from_list->GetSize(); ++i)
    {
        if (i >= to_list->GetSize())
            to_list->PushBack((*from_list)[i]);
        else if (!MergeValues(i, to, from, ms))
            return false;
    }
    return true;
}

}}} // namespace Scaleform::GFx::AS3

// ---- VMAbcFile::GetOpCode (traces a method body on first use) ----
extern "C" void FUN_1424df070(void* tracer);   // Tracer::~Tracer (sfr_as3_16, C linkage)
namespace Scaleform { namespace GFx { namespace AS3 {
UPInt* FUN_1424d9f30(UPInt* self, UPInt heap, UPInt body, UPInt ops, UPInt extra);   // Tracer::Tracer (sfr_as3_15)

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
            reinterpret_cast<Tracer*>(&tr)->EmitCode();
        FUN_1424df070(&tr);
    }
    return OpCodeArray[mbi_ind];
}

}}} // namespace Scaleform::GFx::AS3

// Tracer: the run-time operands a chained multiname takes off the operand stack (its name and / or namespace set),
// the name value stored into the multiname. ctx: {tracer, state}.
// Each case pops through c[1] and returns on its own, so the exe duplicates the epilogues; the name is set with Value::operator=.
// @0x142520380
__declspec(safebuffers) int FUN_142520380(void* ctx, void* multiname)
{
    using namespace Scaleform::GFx::AS3;
    using namespace Scaleform::GFx::AS3::TR;
    void** c = reinterpret_cast<void**>(ctx);
    for (;;)
    {
        switch (*static_cast<const int*>(multiname))
        {
        case 1: case 9:      // RTQName: the namespace
            static_cast<State*>(c[1])->PopOpValue();
            return 1;
        case 5: case 13:     // RTQNameL: the name and the namespace
            static_cast<State*>(c[1])->PopOpValue();
            *reinterpret_cast<Value*>(static_cast<Scaleform::UByte*>(multiname) + 0x10) = static_cast<State*>(c[1])->PopOpValue();
            return 2;
        case 6: case 14:     // MultinameL: the name
            *reinterpret_cast<Value*>(static_cast<Scaleform::UByte*>(multiname) + 0x10) = static_cast<State*>(c[1])->PopOpValue();
            return 1;
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
static inline ClassTraits::Traits* FUN_1425085b0(const SlotInfo* psi, VM* pvm) { return ::Scaleform::GFx::AS3::Sfr33SlotDataType(psi, pvm); }   // SlotInfo::GetDataType (sfr_as3_17)
static inline void FUN_142508720(const SlotInfo* psi, ASString* name, VM* pvm) { ::new (static_cast<void*>(name)) ASString(psi->GetDataTypeName(*pvm)); }   // SlotInfo::GetDataTypeName (sfr_as3_17)
InstanceTraits::Traits& FUN_14250a060(VM& vm, const Value& v);       // VM::GetFunctReturnType
static inline void FUN_14252ecb0(void* vm, const void* error, const void* classInfo) { ::Scaleform::GFx::AS3::Sfr31VMRaiseError(reinterpret_cast<Scaleform::UPInt>(vm), static_cast<const unsigned long*>(error), reinterpret_cast<Scaleform::UPInt>(classInfo)); }   // VM: raise the error as an instance of the class
}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {
namespace {
// SlotInfo::IsClassType: the slot's declared type (TraitInfo::GetTypeName: a slot or const trait's type multiname,
// else the name of the class it binds) is "Class" in the public namespace.
SF_FORCEINLINE bool TrIsClassTypeSlot(const SlotInfo& si)
{
    if (si.File.GetPtr() == NULL || si.TI == NULL)
        return false;
    const Abc::File&      f  = si.File->GetAbcFile();
    const Abc::ConstPool& cp = f.Const_Pool;
    const Abc::TraitInfo& ti = *si.TI;
    const Abc::Multiname& mn = ti.GetType() == Abc::TraitInfo::tSlot || ti.GetType() == Abc::TraitInfo::tConst
                                   ? cp.GetMultiname(ti.Ind)
                                   : cp.GetMultiname(f.AS3_Classes.Info[ti.Ind]->inst_info.name_ind);
    const Abc::NamespaceInfo& ns = mn.Ind ? cp.ConstNamespace[mn.Ind] : cp.any_namespace;
    const StringDataPtr       tn = cp.GetString(mn.NameIndex);
    // NamespaceInfo::IsPublic (public or explicit) with an empty URI
    return tn.ToCStr() && strncmp(tn.ToCStr(), "Class", 5) == 0 && (static_cast<UInt32>(ns.Kind) & ~4u) == 0 &&
           ns.NameURI.GetSize() == 0;
}

// VM::ThrowVerifyError: ThrowErrorInternal with the VerifyError class.
SF_FORCEINLINE void TrThrowVerifyError(VM& vm, const VM::Error& e) { FUN_14252ecb0(&vm, &e, &fl::VerifyErrorCI); }
// VM::ThrowTypeError/ThrowReferenceError: ThrowErrorInternal with that error class.
SF_FORCEINLINE void TrThrowError(VM& vm, const VM::Error& e, const ClassInfo& ci) { FUN_14252ecb0(&vm, &e, &ci); }
}

namespace TR {

// The traced type of a property read through the slot si of obj_traits, into type: the function type of a method
// slot, the return type of a getter, else the slot's declared type (its class for a Class-typed or class-bound slot).
// An unknown declared type raises VerifyError 1014 (false).
// MS2-FUNCTIONAL 0x14250cf20: raw-offset model of the ABC type multiname ("Class" in the public namespace) test
// (left: the exe keeps the error value's cleared fields after its weak release, its "Class" compare and
// class-type test shapes, a larger frame, register allocation)
// @0x14250cf20
__declspec(safebuffers) CheckResult State::GetPropertyType(const Traits* obj_traits, const SlotInfo& si, Value& type) const
{
    if (si.BindType > SlotInfo::BT_Code - 1 && si.ValueInd >= 0)
    {
        if (si.BindType == SlotInfo::BT_Code)
        {
            // Retrieve function type.
            InstanceTraits::Traits* ptr;
            {
                const Value& fv = obj_traits->GetVT().GetValue(AbsoluteIndex(si.ValueInd));
                ptr = &GetFunctType(fv);
            }
            InstanceTraits::Traits& tr = *ptr;
            type = Value(tr, CanBeNull(tr));
        }
        else
        {
            // Retrieve function return type.
            InstanceTraits::Traits& tr =
                FUN_14250a060(static_cast<const Tracer*>(pTracer)->GetVM(), obj_traits->GetVT().VTMethods[static_cast<UInt32>(si.ValueInd)]);
            type = Value(tr, CanBeNull(tr));
        }
        return true;
    }

    VM& vm = static_cast<const Tracer*>(pTracer)->GetVM();

    ClassTraits::Traits* ctr = FUN_1425085b0(&si, &vm);
    if (ctr == NULL)
    {
        struct { UPInt node; } nb;   // raw storage: GetDataTypeName constructs the name in it
        ASString& name = *reinterpret_cast<ASString*>(&nb);
        FUN_142508720(&si, &name, &vm);
        TrThrowVerifyError(vm, VM::Error(VM::ErrorID(1014) /* eClassNotFoundError */, vm, Value(name, Value::InlineStr)));
        name.~ASString();
        return false;
    }

    // IsClass: a class trait; IsClassType: declared as Class.
    if (si.BindType == SlotInfo::BT_ValueArray || (si.TI && (*reinterpret_cast<const UByte*>(si.TI) & 0xf) == 4) ||
        TrIsClassTypeSlot(si))
        type = Value(*ctr, Value::NotNull);
    else
    {
        InstanceTraits::Traits& itr = ctr->GetInstanceTraits();
        type = Value(itr, CanBeNull(itr));
    }
    return true;
}

}}}} // namespace Scaleform::GFx::AS3::TR

namespace Scaleform { namespace GFx { namespace AS3 {

// A block's state joined into the entry state of the block it falls / jumps into: the operand stack, the scope stack
// and the registers (a mismatch reported, the rest still joined); the target marked initialized.
// MS2-FUNCTIONAL 0x142511b00: the exe inlines MergeLists (and MergeValues for the two stacks); here they are called
// @0x142511b00
void Tracer::InitializeBlock(TR::Block& to, const TR::Block& from)
{
    MergeLists(*to.pState, *from.pState, false, TR::msOpStack);
    MergeLists(*to.pState, *from.pState, false, TR::msScopeStack);
    MergeLists(*to.pState, *from.pState, true, TR::msRegisterFile);
    to.Flags |= 1;
}

// A block's state merged into an already visited block's entry state: unless the target is a catch target, its
// operand stack (when as deep) and its scope stack (VerifyError 1031 on a mismatch), then its registers.
// MS2-FUNCTIONAL 0x142516c40: the exe inlines MergeLists and MergeValues for the two stacks; here they are called
// @0x142516c40
CheckResult Tracer::MergeBlock(TR::Block& to, const TR::Block& from)
{
    TR::State& ts = *to.pState;
    const TR::State& fs = *from.pState;
    if (!(to.Type & 4))
    {
        MergeLists(ts, fs, true, TR::msOpStack);
        if (!MergeLists(ts, fs, false, TR::msScopeStack))
        {
            VM& vm = GetVM();
            const VM::Error e(VM::ErrorID(1031) /* eScopeDepthUnbalancedError */, vm,
                              static_cast<int>(ts.GetScopeStack().GetSize()), static_cast<int>(fs.GetScopeStack().GetSize()));
            FUN_14252ecb0(&vm, &e, &fl::VerifyErrorCI);
            return false;
        }
    }
    return MergeLists(ts, fs, true, TR::msRegisterFile);
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
Instances::Namespace& Multiname::GetNamespace() const { return *reinterpret_cast<Instances::Namespace*>(AccRd(reinterpret_cast<UPInt>(this), 8)); }

// @0x14250edf0
UPInt Sfr27Acc14250edf0(UPInt self) { return AccRd(AccRd(AccRd(self, 0x18), 0x20), 0x158); }

}}} // namespace Scaleform::GFx::AS3

// The bounds of the display list of the object under the given matrix.
// @0x14250d6d0
Scaleform::GFx::RectF Scaleform::GFx::DisplayObjContainer::GetRectBounds(const Matrix& t) const
{
    return mDisplayList.GetRectBounds(t);
}

namespace Scaleform { namespace GFx { namespace AS3 {

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
    if (mode == 2)
        return !reinterpret_cast<const TextField*>(AccRd(self - 0x18, 0))->IsReadOnly();
    return true;
}

// Whether the text field's style sheet resource is set.
// @0x1425113d0
bool AvmTextField::HasStyleSheet() const
{
    const UPInt self = reinterpret_cast<UPInt>(this) + 0x40;
    const UPInt sheet = FUN_1425b7e60(AccRd(self - 0x28, 0));
    return sheet != 0 && AccRd(sheet, 0x40) != 0;
}

}}} // namespace Scaleform::GFx::AS3


// ==== VMAbcFile: interned strings and namespaces ====
namespace Scaleform { namespace GFx { namespace AS3 {

// ArrayData::Resize of IntStrings, with the exe's out-of-line ResizeNoConstruct.
static SF_INLINE void Sfr18ResizeIntStrings(ArrayLH<SPtr<ASStringNode> >& a, UPInt newSize)
{
    const UPInt oldSize = a.GetSize();
    reinterpret_cast<ArrayDataBase<SPtr<ASStringNode>, AllocatorLH<SPtr<ASStringNode>, 2>, ArrayDefaultPolicy>*>(&a)->ResizeNoConstruct(&a, newSize);
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

// The event id copy of the exe's ActionEntry::operator=: member by member, the first union member only.
static __forceinline void Sfr18CopyEventId(EventId& d, const EventId& s)
{
    d.Id              = s.Id;
    d.WcharCode       = s.WcharCode;
    d.KeyCode         = s.KeyCode;
    d.AsciiCode       = s.AsciiCode;
    d.RollOverCnt     = s.RollOverCnt;
    d.ControllerIndex = s.ControllerIndex;
    d.KeysState       = s.KeysState;
    d.MouseWheelDelta = s.MouseWheelDelta;
}

// ActionEntry::SetAction(DisplayObject*, const EventId&), with the event id copied as the exe does.
static __forceinline void Sfr18SetEventAction(MovieRoot::ActionEntry* e, DisplayObject* pcharacter, const EventId& id)
{
    e->Type = MovieRoot::ActionEntry::Entry_Event;
    e->pCharacter = pcharacter;
    Sfr18CopyEventId(e->mEventId, id);
    e->CFunction = NULL;
    e->pAS3Obj = NULL;
    e->Function.SetUndefined();
    e->pNLoadInitCL = NULL;
}

// Queues the event for the object at level lvl (GetAS3Root()->InsertEmptyAction(lvl)->SetAction(pDispObj, id)).
static __forceinline void QueueEvent(AvmDisplayObj* o, MovieRoot::ActionLevel lvl, const EventId& id)
{
    Sfr18SetEventAction(AS3RootOf(o->pDispObj)->InsertEmptyAction(lvl), o->pDispObj, id);
}

// AvmDisplayObj::HasAS3Obj of the SDK.
static __forceinline bool Sfr18HasAS3Obj(const AvmDisplayObj* p)
{
    return p->pAS3RawPtr || p->pAS3CollectiblePtr.pObject;
}

// Enter frame queues once the object is loaded; render and frame events queue for objects with an AS3 side.
// @0x142518a30
bool AvmDisplayObj::OnEvent(const EventId& id)
{
    switch (id.Id)
    {
    case EventId::Event_EnterFrame:
        if (Sfr18HasAS3Obj(this) && (Flags & Flag_Loaded))
            QueueEvent(this, MovieRoot::AL_EnterFrame, id);
        Flags |= Flag_Loaded;
        return true;
    case AS3Event_FrameFirst:
    case AS3Event_FrameLast:
        if (Sfr18HasAS3Obj(this))
            QueueEvent(this, MovieRoot::AL_Frame, id);
        return true;
    case AS3Event_Render:
        if (Sfr18HasAS3Obj(this))
            QueueEvent(this, MovieRoot::AL_Render, id);
        return true;
    default:;
    }
    return false;
}

// An object with removed listeners gets its removed event queued and leaves the depth order.
// @0x14251af40
bool AvmDisplayObj::OnUnloading(bool mayRemove)
{
    Instances::fl_display::DisplayObject* obj = GetAS3Obj();
    if (obj)
    {
        MovieRoot* root = AS3RootOf(pDispObj);
        if (obj->HasEventHandler(root->BuiltinsMgr.GetBuiltin(AS3Builtin_removed), false) ||
            obj->HasEventHandler(AS3RootOf(pDispObj)->BuiltinsMgr.GetBuiltin(AS3Builtin_removedFromStage), false))
        {
            QueueEvent(this, MovieRoot::AL_EnterFrame, EventId(AS3Event_Removed));
            pDispObj->Depth = -2;
            if (IsStageAccessible())
                Flags |= Flag_Unloaded;
        }
    }
    return mayRemove;
}

// Mouse events go straight to the AS3 object, controller events are queued.
// @0x142518c70
SF_NOINLINE bool AvmInteractiveObj::OnEvent(const EventId& id)
{
    switch (id.Id)
    {
    case EventId::Event_MouseMove:
    case EventId::Event_MouseDown:
    case EventId::Event_MouseUp:
    case EventId::Event_RollOver:
    case EventId::Event_RollOut:
    case 0x100000a: case 0x100000b: case AS3Event_Click: case 0x100000d: case 0x100000e:
        if (Sfr18HasAS3Obj(this))
        {
            DisplayObject* pint = pDispObj;     // GetIntObj
            GetAS3Obj()->Dispatch(id, pint);
        }
        return true;
    case AS3Event_Controller:
        QueueEvent(this, MovieRoot::AL_ControllerEvents, id);
        return true;
    }
    return AvmDisplayObj::OnEvent(id);
}

// A sprite in button mode shows its _up/_over/_down frames; a press becomes a click.
// MovieImpl::mMouseState (0x50 bytes each at +0x1260), the part read here.
struct Sfr34_MouseStateView
{
    UInt32 Pad[12];
    UInt32 ButtonsState;      // +0x30
    UInt32 PrevButtonsState;  // +0x34
    UInt32 Rest[6];

    unsigned GetButtonsState() const     { return ButtonsState; }
    unsigned GetPrevButtonsState() const { return PrevButtonsState; }
};

struct Sfr34_MovieImplMiceView
{
    void*                Pad[0x1260 / 8];
    Sfr34_MouseStateView mMouseState[4];   // +0x1260
};

static __forceinline Sfr34_MouseStateView* Sfr34_GetMouseState(MovieImpl* movie, unsigned mouseIndex)
{
    if (mouseIndex >= 4)
        return NULL;
    return &reinterpret_cast<Sfr34_MovieImplMiceView*>(movie)->mMouseState[mouseIndex];
}

static __forceinline SpriteDef* Sfr34_GetSpriteDef(Sprite* spr)
{
    return (spr->Flags & Sprite::Flags_SpriteDef) ? static_cast<SpriteDef*>(spr->pDef.GetPtr()) : NULL;
}

static __forceinline bool Sfr34_IsTrackAsMenu(Sprite* spr)
{
    return (UByte)(*reinterpret_cast<const UInt32*>(reinterpret_cast<UPInt>(spr) + 0xb8) >> 14) & 1;
}

// SDK shape. The mouse state comes from AvmDisplayObj::GetMovieImpl() (this), not spr->GetMovieImpl(): the
// latter swaps the registers of its two field addresses.
// @0x142518df0
bool AvmSprite::OnEvent(const EventId& id)
{
    if (SprFlags & Flag_ButtonMode)
    {
        // Check if the sprite has special frames, such as _up, _down, _over.
        // Go to these frames if event is Release, Press or RollOver.
        Sprite*    spr = static_cast<Sprite*>(pDispObj);
        SpriteDef* sp;
        if ((sp = Sfr34_GetSpriteDef(spr)) != NULL)
        {
            if (sp->Flags & SpriteDef::Flags_HasSpecialFrames)
            {
                switch (id.Id)
                {
                case EventId::Event_MouseUp:
                case EventId::Event_Release:
                    if (sp->Flags & SpriteDef::Flags_Has_Frame_over)
                        spr->GotoLabeledFrame("_over", 0);
                    break;
                case EventId::Event_RollOver:
                    if (sp->Flags & SpriteDef::Flags_Has_Frame_over)
                    {
                        Sfr34_MouseStateView& ms = *Sfr34_GetMouseState(GetMovieImpl(), id.MouseIndex);
                        if (Sfr34_IsTrackAsMenu(spr) && (ms.GetPrevButtonsState() & 1))
                            spr->GotoLabeledFrame("_down", 0);
                        // prevent button from changing state if left mouse button is pressed (like in Flash)
                        else if (!(ms.GetButtonsState() & 1))
                            spr->GotoLabeledFrame("_over", 0);
                    }
                    break;
                case EventId::Event_DragOut:
                    if (Sfr34_IsTrackAsMenu(spr))
                    {
                        if (sp->Flags & SpriteDef::Flags_Has_Frame_up)
                            spr->GotoLabeledFrame("_up", 0);
                    }
                    else
                    {
                        if (sp->Flags & SpriteDef::Flags_Has_Frame_over)
                            spr->GotoLabeledFrame("_over", 0);
                    }
                    break;
                case EventId::Event_MouseDown:
                case EventId::Event_DragOver:
                    if (sp->Flags & SpriteDef::Flags_Has_Frame_down)
                        spr->GotoLabeledFrame("_down", 0);
                    break;
                case EventId::Event_RollOut:
                case EventId::Event_ReleaseOutside:
                    if (sp->Flags & SpriteDef::Flags_Has_Frame_up)
                        spr->GotoLabeledFrame("_up", 0);
                    break;
                default:;
                }
            }
        }
        if (id.Id == EventId::Event_Press)
        {
            if (pAS3RawPtr || pAS3CollectiblePtr)
            {
                // simulate the Click event
                EventId e(id);
                e.Id = AS3Event_Click;
                GetAS3Obj()->Dispatch(e, pDispObj);
            }
            return true;
        }
    }
    return AvmInteractiveObj::OnEvent(id);
}

// AvmDisplayObj::GetAvmParent. The cast result goes through a named local, so cl threads only the NULL-parent
// return straight out of a caller's loop, as the exe does; a NULL cast result still goes through the loop's test.
static __forceinline AvmInteractiveObj* Sfr34_AvmParent(const AvmDisplayObj* avm)
{
    InteractiveObject* parent = avm->pDispObj->GetParent();
    if (!parent)
        return NULL;
    AvmInteractiveObj* r = static_cast<AvmInteractiveObj*>(parent->GetAvmIntObj());
    return r;
}

// The object is the stage, or its topmost AS3 ancestor is.
// @0x142514d20
bool AvmDisplayObj::IsStageAccessible() const
{
    if (pDispObj->IsInteractiveObject() && ToAvmInteractiveObj(static_cast<InteractiveObject*>(pDispObj))->IsStage())
        return true;
    AvmInteractiveObj* p = Sfr34_AvmParent(this);
    for (; p && Sfr34_AvmParent(p); p = Sfr34_AvmParent(p))
        ;
    if (p)
    {
        return p->IsStage();
    }
    return false;
}

// @0x142519080
void AvmInteractiveObj::OnEventLoad()
{
    SetAS3ObjCollectible(GetAS3Obj());
}

// data_rdata_sf_b's two IsTabable vtable slots name the free forms these were; a data slot cannot name the members.
#pragma comment(linker, "/alternatename:?AvmButton_IsTabable@AS3@GFx@Scaleform@@YA_N_K@Z=?IsTabable@AvmButton@AS3@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?AvmTextField_IsTabable@AS3@GFx@Scaleform@@YA_N_K@Z=?IsTabable@AvmTextField@AS3@GFx@Scaleform@@UEBA_NXZ")

// AvmButton::IsTabable; self is the AvmInteractiveObjBase part (+0x30) of the button.
// @0x142514eb0
bool AvmButton::IsTabable() const
{
    const UPInt self = reinterpret_cast<UPInt>(this) + 0x30;
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
bool AvmTextField::IsTabable() const
{
    const UPInt self = reinterpret_cast<UPInt>(this) + 0x30;
    const AvmDisplayObj* avm = reinterpret_cast<const AvmDisplayObj*>(self - 0x30);
    if (!avm->pDispObj->GetVisible())
        return false;
    const InteractiveObject* io = static_cast<const InteractiveObject*>(avm->pDispObj);
    if ((io->Flags & InteractiveObject::Mask_TabEnabled) != 0)
        return (io->Flags & InteractiveObject::Mask_TabEnabled) == InteractiveObject::Mask_TabEnabled;
    else if (io->TabIndex > 0)
        return true;
    return !static_cast<const TextField*>(avm->pDispObj)->IsReadOnly();
}

// Value(const ASString&) as the exe inlines it here (its out-of-line copy is sfr_as3_15's 0x1424dbf70).
SF_FORCEINLINE Value::Value(const ASString& v, InlineStrType)
    : Flags(kString)
    , value(v.GetNode())
{
    if (v.GetNode() == v.GetManager()->GetNullStringNode())
    {
        SetKind(kObject);
        value = (Object*)NULL;
    }
    else
        value.VS._1.VStr->AddRef();
}

// The SDK's AvmDisplayObj::HasAS3Obj: either pointer set.
static SF_FORCEINLINE bool Sfr34HasAS3Obj(const AvmDisplayObj* avm)
{
    return avm->pAS3RawPtr || avm->pAS3CollectiblePtr;
}

// AvmTextField::OnKeyEvent; self is the AvmInteractiveObjBase part (+0x30).
// @0x14251a350
bool AvmTextField::OnKeyEvent(const EventId& id, int*)
{
    const UPInt self = reinterpret_cast<UPInt>(this) + 0x30;
    const AvmDisplayObj* avm = reinterpret_cast<const AvmDisplayObj*>(self - 0x30);
    if (Sfr34HasAS3Obj(avm))
    {
        DisplayObject* dobj = avm->pDispObj;
        avm->GetAS3Obj()->Dispatch(id, dobj);
    }
    return false;
}

// A press becomes a click, the rest goes to OnEvent. (The virtual comes from AvmButtonBase, so this is that part.)
// @0x14251a830
bool AvmButton::OnMouseEvent(const EventId& id)
{
    if (id.Id == EventId::Event_Press)
    {
        if (Sfr34HasAS3Obj(this))
        {
            EventId click(id);
            click.Id = AS3Event_Click;
            GetAS3Obj()->Dispatch(click, pDispObj);
        }
        return true;
    }
    return OnEvent(id);
}

// AvmTextField::OnEventLoad: the field joins the play list after its place in the parent, and the optimized
// advance list when it asks to.
// @0x1425190f0
void AvmTextField::OnEventLoad()
{
    const UPInt self = reinterpret_cast<UPInt>(this);
    AvmDisplayObj* avm = reinterpret_cast<AvmDisplayObj*>(self);
    InteractiveObject* t = static_cast<InteractiveObject*>(avm->pDispObj);
    if (InteractiveObject* pafter = ToAvmInteractiveObj(t->GetParent())->FindInsertToPlayList(t))
        t->InsertToPlayListAfter(pafter);
    else
        t->AddToPlayList();
    static_cast<InteractiveObject*>(avm->pDispObj)->ModifyOptimizedPlayList();
    avm->SetAS3ObjCollectible(avm->GetAS3Obj());
}

// AvmTextField::GetStyleSheet; self is the AvmTextFieldBase part (+0x40). The style manager of the field's
// style sheet when the field uses one.
// @0x14250ef30
const Text::StyleManager* AvmTextField::GetStyleSheet() const
{
    const UPInt self = reinterpret_cast<UPInt>(this) + 0x40;
    const UPInt sheet = FUN_1425b7e60(AccRd(self - 0x28, 0));
    if (reinterpret_cast<const AvmTextFieldBase*>(self)->HasStyleSheet())
        return reinterpret_cast<const Text::StyleManager*>(AccRd(sheet, 0x40) + 0x50);
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


namespace Scaleform {
template void ArrayDataBase<UByte, AllocatorGH<UByte, 2>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void ArrayDataBase<UByte, AllocatorGH_POD<UByte, 2>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void ArrayDataBase<GFx::AS3::TR::State*, AllocatorDH<GFx::AS3::TR::State*, 328>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void ArrayDataBase<Render::FillStyleType, AllocatorLH<Render::FillStyleType, 2>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void ArrayDataBase<GFx::Button::CharToRec, AllocatorLH<GFx::Button::CharToRec, 2>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void ArrayDataBase<GFx::MovieImpl::LevelInfo, AllocatorLH<GFx::MovieImpl::LevelInfo, 327>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Hash<GFx::AS3::GASRefCountBase*, GFx::AS3::WeakProxy*>::Remove(GFx::AS3::GASRefCountBase* const&);
// MS2-FUNCTIONAL 0x142522350: RemoveAlt<Key> is inlined in both; the exe's inlined Key hash takes the namespace
// half first and its probe loop re-reads the key's pNs->Uri on each compare (ours keeps it in a register)
template void HashDH<GFx::AS3::MultinameHash<GFx::AS3::ClassTraits::Traits*, 329>::Key, GFx::AS3::ClassTraits::Traits*,
    GFx::AS3::MultinameHash<GFx::AS3::ClassTraits::Traits*, 329>::Key::HashFunctor, 329>::BaseType::Remove(
    const GFx::AS3::MultinameHash<GFx::AS3::ClassTraits::Traits*, 329>::Key&);
// Clear goes through a member pointer: the exe tail-calls ResizeNoConstruct, which cl otherwise inlines.
template <>
__declspec(dllexport) void ArrayBase<ArrayData<WeakPtr<GFx::DisplayObject>, AllocatorLH<WeakPtr<GFx::DisplayObject>, 2>, ArrayDefaultPolicy> >::RemoveAt(UPInt index)
{
    if (Data.Size == 1)
    {
        typedef ArrayDataBase<WeakPtr<GFx::DisplayObject>, AllocatorLH<WeakPtr<GFx::DisplayObject>, 2>, ArrayDefaultPolicy> Base;
        (Data.*&Base::ResizeNoConstruct)(&Data, 0);
    }
    else
    {
        AllocatorType::Destruct(Data.Data + index);
        AllocatorType::CopyArrayForward(Data.Data + index, Data.Data + index + 1, Data.Size - 1 - index);
        --Data.Size;
    }
}
template void ArrayBase<ArrayDataDH<GFx::AS3::Value, AllocatorDH<GFx::AS3::Value, 2>, ArrayDefaultPolicy> >::PopBack(UPInt);
template GFx::AS3::Value& ArrayBase<ArrayData<GFx::AS3::Value, AllocatorLH<GFx::AS3::Value, 331>, ArrayDefaultPolicy> >::PushDefault();
template void ArrayData<char, AllocatorGH<char, 2>, ArrayDefaultPolicy>::PushBack(const char&);
template void ArrayBase<ArrayDataDH<Ptr<GFx::DisplayObjectBase>, AllocatorDH<Ptr<GFx::DisplayObjectBase>, 2>, ArrayDefaultPolicy> >::InsertAt(
    UPInt, const Ptr<GFx::DisplayObjectBase>&);
// The exe folds the SPtr<VMAppDomain> and VMAbcFile* POD Reserves into one body; symbols.tsv names the latter.
// @0x142522ef0
template void ArrayDataBase<GFx::AS3::VMAbcFile*, AllocatorLH_POD<GFx::AS3::VMAbcFile*, 329>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// The exe element type: Instances::fl::Namespace, which this model keeps as Instances::Namespace.
namespace GFx { namespace AS3 { namespace Instances { namespace fl { class Namespace : public Instances::Namespace {}; } } } }
// @0x142522db0
template void ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::Instances::fl::Namespace>,
    AllocatorLH<GFx::AS3::SPtr<GFx::AS3::Instances::fl::Namespace>, 2>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);

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

// Paged array modeled locally (AllocatorPagedCC not modeled)
// @0x14251cba0
void Sfr34_CallFramePagedArray_PopBack(Sfr34_CallFramePagedArray* self)
{
    if (self->Size)
    {
        UPInt i = self->Size - 1;
        reinterpret_cast<Scaleform::GFx::AS3::CallFrame*>(self->Pages[i >> 6] + (i & 0x3f) * 0xa8)->~CallFrame();
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
    const char* type = (event == InteractiveObject::KillFocus) ? "focusOut" : "focusIn";
    Instances::fl_display::DisplayObject* related =
        oldOrNewFocusCh ? ToAvmInteractiveObj(oldOrNewFocusCh)->GetAS3Obj() : NULL;
    Instances::fl_display::DisplayObject* as3obj = GetAS3Obj();
    SPtr<Instances::fl_events::FocusEvent> evt =
        as3obj->CreateFocusEventObject(Sfr34_AS3Root(this)->GetStringManager418()->CreateConstString(type),
                                       related, controllerIdx, false, 0);
    as3obj->DispatchEventObject(evt, pDispObj);
}

// @0x142519ee0
bool AvmInteractiveObj::OnFocusChange(InteractiveObject* ptoBeFocused, unsigned controllerIdx, FocusMovedType fmt,
                                      ProcessFocusKeyInfo* pfocusKeyInfo)
{
    const char* type = (fmt == GFx_FocusMovedByKeyboard) ? "keyFocusChange" : "mouseFocusChange";
    if (Sfr34HasAS3Obj(this))
    {
        Instances::fl_display::DisplayObject* related =
            ptoBeFocused ? ToAvmInteractiveObj(ptoBeFocused)->GetAS3Obj() : NULL;
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
        return !evt->DefaultPrevented;
    }
    return true;
}

// Takes the object and its branch (the play list entries before it that descend from it) out of the play list and
// puts them back where the parent wants the object now.
// @0x142517ed0
void AvmInteractiveObj::MoveBranchInPlayList()
{
    InteractiveObject* p = GetIntObj();
    InteractiveObject* pend = p;
    InteractiveObject* pbefore = p->pPlayNext;
    InteractiveObject* pafter = NULL;

    // the first entry before the branch: the first one p is not an ancestor of
    InteractiveObject* pcur = p->pPlayPrev;
    InteractiveObject* parpar = p;
    for (; pcur; pcur = pcur->pPlayPrev)
    {
        InteractiveObject* c = pcur;
        for (; c; c = c->GetParent())
        {
            if (c == parpar)
                break;
        }
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
    else
    {
        if (pbefore)
        {
            pend = GetMovieImpl()->pPlayList;
            GetMovieImpl()->pPlayList = pbefore;
        }
        else
            pend = p;
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
            if (p->pPlayNext)
                p->pPlayNext->pPlayPrev = p;
            pins->pPlayNext = pend;
            pend->pPlayPrev = pins;
        }
        else
            parent = NULL;
    }
    if (!parent)
    {
        InteractiveObject* phead = GetMovieImpl()->pPlayList;
        if (phead)
        {
            p->pPlayNext = phead;
            phead->pPlayPrev = p;
        }
        GetMovieImpl()->pPlayList = pend;
    }
    GetMovieImpl()->Flags |= MovieImpl::Flag_OptAdvListInvalid;
}

// The out-of-line copy of the inline InteractiveObject::ModifyOptimizedPlayList.
// Out-of-line copy of the inline member, recovered as a free wrapper
// @0x142517e70
void Sfr34_ModifyOptimizedPlayList(InteractiveObject* p)
{
    p->ModifyOptimizedPlayList();
}

// ActionEntry::SetAction(DisplayObject*, const Value&) of the SDK (inline there).
static SF_INLINE void Sfr34SetFunctionAction(MovieRoot::ActionEntry* pe, DisplayObject* pcharacter, const Value& v)
{
    pe->Type = MovieRoot::ActionEntry::Entry_Function;
    pe->pCharacter = pcharacter;
    pe->Function = v;
    pe->CFunction = NULL;
    pe->pAS3Obj = NULL;
    pe->pNLoadInitCL = NULL;
}

// @0x1425200b0
void AvmSprite::QueueFrameScript(unsigned frame)
{
    Value v;
    if (Instances::fl_display::DisplayObject* as3obj = GetAS3Obj())
    {
        if (static_cast<Instances::fl_display::Sprite*>(GetAS3Obj())->GetFrameScript(frame, &v))
        {
            Sfr34SetFunctionAction(static_cast<MovieRoot*>(pDispObj->GetASMovieRoot())->InsertEmptyAction(MovieRoot::AL_Frame),
                                   pDispObj, v);
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

// The lookup goes through GetAlt here and Get in QueueEvents: cl inlines each of the two only at a single call site,
// and the exe inlines the lookup in both.
// @0x142522830
void EventChains::RemoveFromChain(EventId::IdCode evtId, DisplayObject* obj)
{
    AutoPtr<Chain>* ppchain = Chains.GetAlt(evtId);
    if (ppchain)
    {
        Chain* chain = ppchain->GetPtr();
        UPInt i = FindObjectIndexInChain(chain, obj);
        if (i != SF_MAX_UPINT)
            (*chain)[i] = NULL;
    }
}

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
            (dobj ? ToAvmDisplayObj(dobj) : 0)->OnEvent(evt);
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

// ToAvmDisplayObj (AS3_AvmDisplayObj.h) with its null test
static inline AvmDisplayObj* Sfr18ToAvmDisplayObj(DisplayObjectBase* po)
{
    if (!po)
        return NULL;
    return static_cast<AvmDisplayObj*>(po->GetAvmObjImpl());
}

// AvmDisplayObj::SetFirstFrameCalledFlag (AS3_AvmDisplayObj.h)
static inline void Sfr18SetLoadedFlag(AvmDisplayObj* avm, bool v = true)
{
    (v) ? avm->Flags |= AvmDisplayObj::Flag_Loaded : avm->Flags &= ~AvmDisplayObj::Flag_Loaded;
}

// FrameCounter::QueueFrameActions (AS3_AvmStage.cpp): the SDK null-tested ToAvmDisplayObj and lvalue-conditional flag setter
// @0x14251ff60
void FrameCounter::QueueFrameActions()
{
    MovieRoot* proot = static_cast<MovieRoot*>(GetMovieImpl()->pASMovieRoot);
    EventChains& chains = reinterpret_cast<Sfr34_MovieRootChainsView*>(proot)->Chains;
    chains.QueueEvents(EventId::IdCode(Sfr34_Event_FrameConstructed));
    // the play list backwards from the stage, the full one while the optimized one is invalid
    if (GetMovieImpl()->IsOptAdvListInvalid())
    {
        for (InteractiveObject* cur = pPlayPrev; cur; cur = cur->pPlayPrev)
        {
            Sfr18SetLoadedFlag(Sfr18ToAvmDisplayObj(cur));
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
        for (InteractiveObject* cur = pPlayPrevOpt; cur; cur = cur->pPlayPrevOpt)
        {
            Sfr18SetLoadedFlag(Sfr18ToAvmDisplayObj(cur));
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
    SetAS3ObjCollectible(obj);
    if (obj)
    {
        SPtr<Instances::fl_events::Event> evt = obj->CreateEventObject(added, true, false);
        evt->Target = obj;
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
        evt->Target = obj;
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
        e->Target = obj;
        obj->DispatchEventObject(e, pDispObj);
    }
}

// The container's own copy, then (inclChildren) every child's branch. The child's AVM part is written as
// !sch ? NULL : ..., which lays out the NULL branch first as in the exe.
// @0x14251f430
void AvmDisplayObjContainer::PropagateEvent(const Instances::fl_events::Event& evt, bool inclChildren)
{
    {
        SPtr<Instances::fl_events::Event> e = evt.Clone();
        Instances::fl_display::DisplayObject* obj = GetAS3Obj();
        if (obj)
        {
            e->Target = obj;
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
            AvmDisplayObj*     pavm = !sch ? NULL : ToAvmDisplayObj(sch);
            pavm->PropagateEvent(evt, true);
        }
    }
}

// sfr34 batch E: removing children from an AS3 container.

// What follows the removal of ch from the display list: the AS3 side gets "removed", ch loses its parent and
// leaves the play list branch, and a timeline child stops being one.
static __forceinline AvmDisplayObj* Sfr34_ToAvmOrNull(DisplayObjectBase* p)
{
    if (!p)
        return NULL;
    return ToAvmDisplayObj(p);
}

static __forceinline bool Sfr34_IsTimelineObject(const DisplayObject* dobj)
{
    return (dobj->Flags & DisplayObject::Mask_TimelineObject) != 0;
}

static __forceinline void Sfr34_SetTimelineObject(DisplayObject* dobj, bool v)
{
    (v) ? dobj->Flags |= DisplayObject::Mask_TimelineObject : dobj->Flags &= (~DisplayObject::Mask_TimelineObject);
}

static __forceinline void Sfr34_AfterChildRemoved(DisplayObjectBase* ch)
{
    InteractiveObject* pio  = ch->IsInteractiveObject() ? static_cast<InteractiveObject*>(ch) : NULL;
    DisplayObjectBase* sch  = ch->IsScriptableObject() ? ch : NULL;
    AvmDisplayObj*     pavm = Sfr34_ToAvmOrNull(sch);
    pavm->OnRemoved(false);
    ch->pParent = NULL;
    if (pio && pio->IsInPlayList())
        ToAvmInteractiveObj(pio)->MoveBranchInPlayList();
    DisplayObject* dobj = static_cast<DisplayObject*>(ch);
    if (Sfr34_IsTimelineObject(dobj))
    {
        Sfr34_SetTimelineObject(dobj, false);
        dobj->SetAcceptAnimMoves(false);
        ch->CreateFrame = 0;
        ch->Depth       = -1;
        ToAvmDisplayObj(ch)->OnDetachFromTimeline();
    }
}

// @0x142522570
DisplayObjectBase* AvmDisplayObjContainer::RemoveChild(DisplayObjectBase* ch)
{
    Ptr<DisplayObjectBase> hold = ch;
    DisplayList&           displayList = GetDisplayObjContainer()->mDisplayList;
    SPInt                  index = displayList.FindDisplayIndex(ch);
    if (index >= 0)
        displayList.RemoveEntryAtIndex(pDispObj, UPInt(index));
    else
        return NULL;
    displayList.Flags |= DisplayList::Flags_DepthToIndexInvalid | DisplayList::Flags_MayContainForeignElems;
    Sfr34_AfterChildRemoved(ch);
    return ch;
}

// @0x1425226a0
DisplayObjectBase* AvmDisplayObjContainer::RemoveChildAt(unsigned index)
{
    if (index >= unsigned(GetDisplayObjContainer()->mDisplayList.GetCount()))
        return NULL;
    DisplayList&           displayList = GetDisplayObjContainer()->mDisplayList;
    Ptr<DisplayObjectBase> hold = displayList.GetDisplayObject(index);
    displayList.RemoveEntryAtIndex(pDispObj, index);
    displayList.Flags |= DisplayList::Flags_DepthToIndexInvalid | DisplayList::Flags_MayContainForeignElems;
    Sfr34_AfterChildRemoved(hold.GetPtr());
    return hold;
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

    // (bool          PointTestLocal(const PointF& pt, UInt8 hitTestMask) const; is the real member now)
    // (TopMostResult GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr); is the real member now)
    // (RectF         GetRectBounds(const Render::Matrix2F& t) const; is the real member now)
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
bool ShapeObject::PointTestLocal(const PointF& pt, UInt8 hitTestMask) const
{
    if (pDrawing && pDrawing->DefPointTestLocal(pt, (hitTestMask & HitTest_TestShape) != 0, this))
        return true;
    return pDef->DefPointTestLocal(pt, (hitTestMask & HitTest_TestShape) != 0, this);
}

// A shape is never the topmost entity itself: with drawn graphics a hit gives the parent, otherwise the
// definition's shape is searched.
// @0x14250f770
DisplayObjectBase::TopMostResult ShapeObject::GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr)
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
// (SF_AS3_SHAPEOBJECT_MODEL member)
// @0x14251c9f0
#pragma strict_gs_check(push, on)
bool AvmBitmap::PointTestLocal(const PointF& pt, UInt8 hitTestMask) const
{
    SF_UNUSED(hitTestMask);
    if (pImage)
    {
        Render::ImageRect rect = pImage->GetImage()->GetRect();
        RectF r(0, 0,
            Render::Size<float>(PixelsToTwips((float)rect.Width()), PixelsToTwips((float)rect.Height())));
        if (r.Contains(pt))
        {
            return true;
        }
    }
    return false;
}
#pragma strict_gs_check(pop)

} } } // namespace Scaleform::GFx::AS3

// AvmBitmap::RecreateRenderNode: the bitmap's AS3 image may have changed, so its render node is made again
// from the current image and put back where the old one was in the parent's children.
// MS2-FUNCTIONAL the parent's inlined GetAt in the search loop loads the entry table one instruction earlier in the
// exe (rcx/rdx swapped there)
// @0x142520b20
Scaleform::Render::TreeNode* FUN_142520b20(Scaleform::GFx::DisplayObject* pbitmap)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx;
    using namespace Scaleform::GFx::AS3;
    Sfr34_AvmBitmapView*           self   = static_cast<Sfr34_AvmBitmapView*>(pbitmap);
    Instances::fl_display::Bitmap* as3    = static_cast<Instances::fl_display::Bitmap*>(
        reinterpret_cast<const AvmDisplayObj*>(self->AvmPart)->GetAS3Obj());
    UPInt                          index  = ~0u;
    Render::TreeContainer*         parent = NULL;
    bool                           renNodeExisted = !!self->pRenNode;
    if (as3)
    {
        if (self->pRenNode && self->pRenNode->GetParent())
        {
            if (!self->pRenNode->IsMaskNode())
                parent = static_cast<Render::TreeContainer*>(self->pRenNode->GetParent());
            index = 0;
            for (UPInt n = parent->GetSize(); index < n; ++index)
            {
                if (parent->GetAt(index) == self->pRenNode)
                    break;
            }
            parent->Remove(index, 1);
        }
        ImageResource* pimg = as3->GetImageResource();
        if (pimg)
            self->pImage = pimg;
    }
    if (renNodeExisted)
    {
        Ptr<Render::TreeNode> node = self->pRenNode;
        self->pRenNode = self->CreateRenderNode(
            *reinterpret_cast<Render::ContextImpl::Context*>(self->GetMovieImpl()->RenderContext));
        if (self->pRenNode)
        {
            if (node)
                self->pRenNode->CopyGeomData(*node.GetPtr());
            else
                self->pRenNode->SetVisible(self->IsVisibleFlagSet());
            if (parent)
                parent->Insert(index, self->pRenNode);
        }
    }
    return self->pRenNode;
}

namespace Scaleform { namespace GFx { namespace AS3 {


// sfr34 batch G: unloading.

// An object past its unload depth only drops its unload state. A timeline child (not named by an instance) is
// taken off the parent's property of its name if that property still holds this object; the AS3 object is then
// kept raw (no longer collectible).
// MS2-FUNCTIONAL both Multiname constructions use the inline copy (InlineStr, InlineCtorTag) as the exe inlines them; left: the exe lays the early Depth < -1 return out of line, shrink-wraps on rdi, and register allocation
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
            Multiname mn(AS3RootOf(pDispObj)->pAVM->GetPublicNamespace(), Value(name, Value::InlineStr), Multiname::InlineCtorTag());
            parentObj->GetProperty(mn, v);
        }
        VM* vm = AS3RootOf(pDispObj)->pAVM;
        if (!vm->IsException())
        {
            if (!v.IsObject() || v.GetObject() != GetAS3Obj())
                goto done;
            {
                Multiname mn(AS3RootOf(pDispObj)->pAVM->GetPublicNamespace(), Value(name, Value::InlineStr), Multiname::InlineCtorTag());
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
void FUN_1424f03f0(Scaleform::UByte* self, Scaleform::MemoryHeap* heap);  // HeapLimit::Collect
namespace Scaleform { namespace GFx { namespace AS3 {

// MemoryHeap::GetLimit (Limit at +0x60 of the heap).
static SF_INLINE UPInt Sfr18HeapGetLimit(const MemoryHeap* heap)
{
    return *reinterpret_cast<const UPInt*>(reinterpret_cast<const UByte*>(heap) + 0x60);
}

// The heap may grow by HeapLimitMultiplier of its footprint between collections. Past that (or past the user
// limit) the garbage is collected first: right away, or (inside an allocation) at the next frame.
// @0x1425198d0
bool MemoryContextImpl::HeapLimit::OnExceedLimit(MemoryHeap* heap, UPInt overLimit)
{
    UPInt footprint = heap->GetFootprint();
    UPInt heapLimit = Sfr18HeapGetLimit(heap);

    SPInt allocsSinceLastCollect = (SPInt)footprint - LastCollectionFootprint;
    UPInt newLimit = (heapLimit + overLimit) + (UPInt)(footprint * HeapLimitMultiplier);

    if (allocsSinceLastCollect >= (SPInt)(footprint * HeapLimitMultiplier) ||
        (UserLevelLimit != 0 && newLimit > UserLevelLimit))
    {
        if (AllocCount)
        {
            MemContext->ASGC->CollectionScheduledFlags = 1;
            return true;
        }
        FUN_1424f03f0(reinterpret_cast<UByte*>(this), heap);

        if (UserLevelLimit != 0 && newLimit > UserLevelLimit)
        {
            if (overLimit > (footprint - LastCollectionFootprint))
            {
                CurrentLimit = heapLimit + (overLimit - (footprint - LastCollectionFootprint));
                heap->SetLimit(CurrentLimit);
                CurrentLimit = Sfr18HeapGetLimit(heap);
            }
            else
            {
                heap->SetLimit(CurrentLimit);
                CurrentLimit = Sfr18HeapGetLimit(heap);
            }
        }
    }
    else
    {
        heap->SetLimit(newLimit);
        CurrentLimit = Sfr18HeapGetLimit(heap);
    }
    return true;
}


// sfr34 batch I: the interpreter's exception handlers.

} } } // namespace Scaleform::GFx::AS3
static inline Scaleform::GFx::AS3::ClassTraits::Traits* FUN_142524f60(Scaleform::GFx::AS3::VM* vm, Scaleform::GFx::AS3::VMAbcFile* file, const void* abc_multiname)
{ return reinterpret_cast<Scaleform::GFx::AS3::ClassTraits::Traits*>(::Scaleform::GFx::AS3::Sfr31ResolveClassTraits(reinterpret_cast<Scaleform::UPInt>(vm), reinterpret_cast<Scaleform::UPInt>(file), reinterpret_cast<Scaleform::UPInt>(abc_multiname))); }   // VM::Resolve2ClassTraits

// ClassTraits::Traits::IsParentTypeOf (inlined by the exe at its OnException call).
static __forceinline bool Sfr18IsParentTypeOf(const Scaleform::GFx::AS3::ClassTraits::Traits& self, const Scaleform::GFx::AS3::ClassTraits::Traits& other)
{
    using namespace Scaleform::GFx::AS3;
    if (&self == &other)
        return true;
    const ClassTraits::Traits* tr = &other;
    while (tr)
    {
        if (tr->GetInstanceTraits().SupportsInterface(self.GetInstanceTraits()))
            return true;
        tr = static_cast<const ClassTraits::Traits*>(tr->GetParent());
        if (tr == &self)
            return true;
    }
    return false;
}

// VM::OnException: the handler of the frame's method body for the pending exception thrown at code offset. A
// handler covering offset catches it when it has no type or the exception's class is (or derives from, or
// implements) its type; the operand stack is then emptied down to the exception, the scope stack cleared, and the
// handler's code position returned. -1 (the exception stays pending) when no handler catches it.
// A free function in place of the VM member (its caller in sfr_as3_19 declares it so).
// @0x142519a00
int FUN_142519a00(Scaleform::GFx::AS3::VM* vm, Scaleform::UPInt offset, void* frame)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    CallFrame&                             cf       = *static_cast<CallFrame*>(frame);
    int                                    position = -1;
    const Abc::MethodBodyInfo::Exception&  e        = cf.pFile->GetException(cf.MBIIndex);
    UPInt                                  index    = 0;
    while (e.FindExceptionInfo(offset, index))
    {
        const Abc::MethodBodyInfo::ExceptionInfo& ei = e.info[index];
        const int et_ind = ei.exc_type_ind;
        if (et_ind == 0)
        {
            cf.ClearOpStack();
            Value*& top = reinterpret_cast<Value**>(&vm->OpStack)[1];     // ValueStack::pCurrent
            new (++top) Value(vm->ExceptionObj);
            vm->ExceptionObj.Clean();
            cf.ClearScopeStack();
            position = ei.target;
            break;
        }
        else
        {
            if (!vm->ExceptionObj.IsUndefined())
            {
                const ClassTraits::Traits& exc_ctr = vm->GetClassTraits(vm->ExceptionObj);
                vm->HandleException = false;
                const ClassTraits::Traits* handler_tr = FUN_142524f60(vm, cf.pFile,
                    &cf.pFile->GetAbcFile().Const_Pool.GetMultiname(et_ind));
                vm->HandleException = true;
                if (handler_tr && Sfr18IsParentTypeOf(*handler_tr, exc_ctr))
                {
                    cf.ClearOpStack();
                    Value*& top = reinterpret_cast<Value**>(&vm->OpStack)[1];     // ValueStack::pCurrent
                    new (++top) Value(vm->ExceptionObj);
                    vm->ExceptionObj.Clean();
                    cf.ClearScopeStack();
                    position = ei.target;
                    break;
                }
            }
        }
        ++index;
    }
    vm->HandleException = position < 0;
    return position;
}

#include "ms2/scaleform/include/gfx/as3/as3_valueobjectinterface.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// sfr34 batch J: the host side's array and display object access to AS3 values. The ObjectInterface subclass
// (AS3ValueObjectInterface, vftable 0x14317eff8) is in as3_valueobjectinterface.h.


static inline MovieRoot* Sfr34_RootOf(MovieImpl* proot) { return static_cast<MovieRoot*>(proot->pASMovieRoot); }

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

} // namespace AS3

// @0x14251f780
bool AS3ValueObjectInterface::PushBack(void* pdata, const GFx::Value& value)
{
    using namespace AS3;
    using AS3::Value;
    MovieRoot* root = Sfr34_RootOf(pMovieRoot);
    Value      v;
    root->GFxValue2ASValue(value, &v);
    static_cast<Instances::fl::Array*>(pdata)->SA.PushBack(v);
    return true;
}

namespace AS3 {

} // namespace AS3

// The last element (to pval when given) is removed; an empty array gives undefined.
// @0x14251cbe0
bool AS3ValueObjectInterface::PopBack(void* pdata, GFx::Value* pval)
{
    using namespace AS3;
    using AS3::Value;
    Instances::fl::Array* arr  = static_cast<Instances::fl::Array*>(pdata);
    const MovieRoot*      root = Sfr34_RootOf(pMovieRoot);
    const int sz = static_cast<int>(arr->GetSize());
    if (sz <= 0)
    {
        if (pval)
            pval->SetUndefined();
        return false;
    }
    if (pval)
    {
        const Value& asval = arr->At(sz - 1);
        root->ASValue2GFxValue(asval, pval);
    }
    arr->Resize(sz - 1);
    return true;
}

namespace AS3 {

} // namespace AS3

// count elements from idx (all of the rest when negative or past the end).
// @0x1425227e0
bool AS3ValueObjectInterface::RemoveElements(void* pdata, unsigned idx, int count)
{
    using namespace AS3;
    using AS3::Value;
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

namespace AS3 {

} // namespace AS3

// The world matrix, translation in pixels.
// @0x142510a70
bool AS3ValueObjectInterface::GetWorldMatrix(void* pdata, Render::Matrix2F* pmat) const
{
    using namespace AS3;
    using AS3::Value;
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

namespace AS3 {

} // namespace AS3

// The 3D matrix, translation in pixels.
// @0x14250b3c0
bool AS3ValueObjectInterface::GetMatrix3D(void* pdata, Render::Matrix3F* pmat) const
{
    using namespace AS3;
    using AS3::Value;
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

namespace AS3 {

} // namespace AS3

// A text field's text directly; other display objects through their "text" / "htmlText" member.
// @0x14250f110
bool AS3ValueObjectInterface::GetText(void* pdata, GFx::Value* pval, bool isHtml) const
{
    using namespace AS3;
    using AS3::Value;
    const MovieRoot* root = Sfr34_RootOf(pMovieRoot);
    Object*          pobj = static_cast<Object*>(pdata);
    const Traits&    tr   = pobj->GetTraits();
    if ((unsigned)(tr.GetTraitsType() - Traits_DisplayObject_Begin) <
            (unsigned)(Traits_DisplayObject_End - Traits_DisplayObject_Begin) &&
        tr.IsInstanceTraits())
    {
        DisplayObject* dobj = static_cast<Instances::fl_display::DisplayObject*>(pobj)->pDispObj;
        if (dobj->GetType() != CharacterDef::TextField)
            return GetMember(pdata, isHtml ? "htmlText" : "text", pval, true);
        ASString str = reinterpret_cast<TextField*>(dobj)->GetText(isHtml);
        root->ASValue2GFxValue(Value(str, Value::InlineStr), pval);
        return true;
    }
    return false;
}

namespace AS3 {

} // namespace AS3

// A sprite goes to the frame (1-based) and plays or stops; the frame's actions run right away.
// @0x142510b70
bool AS3ValueObjectInterface::GotoAndPlay(void* pdata, unsigned frame, bool stop)
{
    using namespace AS3;
    using AS3::Value;
    MovieRoot* root = Sfr34_RootOf(pMovieRoot);
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

namespace AS3 {

} // namespace AS3

// The same for a frame label.
// @0x142510c30
bool AS3ValueObjectInterface::GotoAndPlay(void* pdata, const char* frame, bool stop)
{
    using namespace AS3;
    using AS3::Value;
    MovieRoot* root = Sfr34_RootOf(pMovieRoot);
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

namespace AS3 {

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
const Scaleform::GFx::AS3::Traits& Scaleform::GFx::AS3::VM::GetValueTraits(const Value& v) const
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    VM& vm = const_cast<VM&>(*this);
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


// MovieRoot::GetRootMovie (slot 14): the nearest display object up from dobj whose AS3 object has loader info,
// else the root of the stage dobj's movie sits on. When that is no container, its parent's root movie is
// taken instead. No dobj gives this stage's root.
// SDK AS3_MovieRoot.cpp form on the inlined AvmDisplayObj::GetRoot.
// A slot of the exe's MovieRoot vftable, defined as a free function.
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
// A slot of the exe's MovieRoot vftable, defined as a free function
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

static inline Scaleform::GFx::AS3::Value* FUN_142525400(const Scaleform::GFx::AS3::MovieRoot* proot, const char* pname) { return ::Scaleform::GFx::AS3::Sfr31ResolveInvokeAlias(reinterpret_cast<Scaleform::UPInt>(proot), pname); }  // MovieRoot::ResolveInvokeAlias

// MovieRoot::Invoke with a format: InvokeArgs (slot 48) with the variable arguments.
// A slot of the exe's MovieRoot vftable, defined as a free function
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
// A slot of the exe's MovieRoot vftable, defined as a free function.
// @0x142513240
bool FUN_142513240(Scaleform::GFx::AS3::MovieRoot* self, const char* pmethodName, Scaleform::GFx::Value* presult,
                   const Scaleform::GFx::Value* pargs, unsigned numArgs)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    enum { NumValuesOnStack = 10 };
    void*  argArrayOnStack[NumValuesOnStack * ((sizeof(GFx::Value) + sizeof(void*)) / sizeof(void*))];
    bool   retVal = true;
    Value* pargArray;
    if (numArgs > NumValuesOnStack)
        pargArray = static_cast<Value*>(SF_HEAP_AUTO_ALLOC(self, sizeof(Value) * numArgs));
    else
        pargArray = reinterpret_cast<Value*>(argArrayOnStack);
    for (unsigned i = 0, n = numArgs; i < n; ++i)
        self->GFxValue2ASValue(pargs[i], ::new (&pargArray[i]) Value());

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
        ASVM* vm = self->pAVM;
        retVal   = !vm->IsException();
        if (vm->IsException())
        {
            vm->HandleException = false;
            vm->OutputError(vm->ExceptionObj);
            vm->ExceptionObj.SetUndefined();
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
// plog is a raw pointer taken from the returned Ptr, as in the SDK (the temp is released at once).
// MS2-FUNCTIONAL a member of the exe's MovieRoot, defined as a free function. The exe keeps arg's flags and
// pointer in registers across the inlined release and calls ArrayData<Value>::PushBack (0x14251f660) out of
// line; both the out-of-line call (member pointer) and the SDK for(;;) loop form score worse here.
// @0x14251c1c0
void FUN_14251c1c0(const Scaleform::GFx::AS3::MovieRoot* self, Scaleform::Array<Scaleform::GFx::AS3::Value>& arr,
                   const char* pmethodName, const char* pargFmt, va_list args)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    GFx::LogState* plog = self->GetMovieImpl()->GetStateBag()->GetLogState();
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
// A slot of the exe's MovieRoot vftable, defined as a free function. Value::GetUndefined() is bound to a named
// reference first (as an argument expression its result load is scheduled after the stack argument stores).
// @0x1425136f0
bool FUN_1425136f0(Scaleform::GFx::AS3::MovieRoot* self, const char* pmethodName, Scaleform::GFx::Value* presult,
                   const char* pargFmt, va_list args)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    Array<Value> argArray;
    FUN_14251c1c0(self, argArray, pmethodName, pargFmt, args);
    unsigned     numArgs = static_cast<unsigned>(argArray.GetSize());
    const Value* pargs   = numArgs > 0 ? &argArray[0] : NULL;
    Value*       paliasFunc;
    Value        resultVal;
    if (self->pInvokeAliases && (paliasFunc = FUN_142525400(self, pmethodName)) != NULL)
    {
        VM& vm = *self->pAVM;
        const Value& undef = Value::GetUndefined();
        vm.ExecuteInternalUnsafe(*paliasFunc, undef, resultVal, numArgs, pargs, false);
    }
    else
    {
        Value resolvedVal;
        if (FUN_142506000(self, &resolvedVal, pmethodName))
        {
            VM& vm = *self->pAVM;
            const Value& undef = Value::GetUndefined();
            vm.ExecuteInternalUnsafe(resolvedVal, undef, resultVal, numArgs, pargs, false);
        }
        else
            return false;
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
// Declared over void pointers by its caller (sfr_as3_17). The slot path tests its 32-bit index for 0 before the
// shared AnyType check.
// @0x14250f8a0
const Scaleform::GFx::AS3::Abc::Multiname& FUN_14250f8a0(const void* amn, const void* abc)
{
    using namespace Scaleform::GFx::AS3::Abc;
    const TraitInfo& t    = *static_cast<const TraitInfo*>(amn);
    const File&      file = *static_cast<const File*>(abc);
    TraitInfo::Type  type = t.GetType();
    if (type == TraitInfo::tSlot || type == TraitInfo::tConst)
    {
        if (t.Ind == 0)
            return file.Const_Pool.GetMultiname(0);
        return file.Const_Pool.GetMultiname(t.Ind);
    }
    return file.Const_Pool.GetMultiname(file.AS3_Classes.Info[t.Ind]->inst_info.name_ind);
}

namespace Scaleform { namespace GFx { namespace AS3 {

// sfr34 batch P: small out-of-line copies and the shape's rect bounds.

// The out-of-line copy of DisplayObjectBase::Is3D (the inline in gfx_rendertree.h).
// @0x142513e50
bool FUN_142513e50(const DisplayObjectBase* pobj)
{
    return pobj->Is3D();
}

// 4.1.18's CharacterDef::GetRectBoundsLocal (vftable slot 8, +0x40) takes no morph ratio: the caller passes no xmm2.
struct Sfr34_CharDefBoundsSlots
{
    virtual void  Slot0() = 0;
    virtual void  Slot1() = 0;
    virtual void  Slot2() = 0;
    virtual void  Slot3() = 0;
    virtual void  Slot4() = 0;
    virtual void  Slot5() = 0;
    virtual void  Slot6() = 0;
    virtual void  Slot7() = 0;
    virtual RectF GetRectBoundsLocal() const = 0;
};

// The definition's rect bounds through t.
// @0x14250d700
RectF ShapeObject::GetRectBounds(const Render::Matrix2F& t) const
{
    return t.EncloseTransform(reinterpret_cast<const Sfr34_CharDefBoundsSlots*>(pDef.GetPtr())->GetRectBoundsLocal());
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

void FUN_1424e5e80(TClassTraitsCache* self, const ASString& name, const Instances::Namespace& ns,
                   ClassTraits::Traits* const& v);   // TClassTraitsCache::Add, out of line (sfr_as3_16z)

// The registry insert takes the traits by reference and adds its address.
static SF_INLINE void Sfr18AddClassTraits(TClassTraitsCache& set, const ASString& name, const Instances::Namespace& ns,
                                          ClassTraits::Traits& tr)
{
    FUN_1424e5e80(&set, name, ns, &tr);
}

// @0x1425210e0
void VM::RegisterClassTraits(ClassTraits::Traits& tr)
{
    InstanceTraits::Traits& itr = tr.GetInstanceTraits();
    Sfr18AddClassTraits(ClassTraitsSet, itr.GetName(), itr.GetNamespace(), tr);
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
// (forwarder above)  // SlotInfo::GetDataType (sfr_as3_17)

// The declared type of the slot with the 1-based own index ind.
// No caller or reference is left in the exe, so a free function.
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
// A slot of the exe's MovieRoot vftable, defined as a free function
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

// Clear goes through a member pointer: the exe calls the out-of-line 0x1424ef2a0, which cl otherwise inlines.
namespace Scaleform {
template <>
__forceinline void ArrayBase<ArrayData<GFx::AS3::VMAbcFile*, AllocatorLH_POD<GFx::AS3::VMAbcFile*, GFx::AS3::StatMV_VM_VM_Mem>,
                                       ArrayDefaultPolicy> >::RemoveAt(UPInt index)
{
    if (Data.Size == 1)
    {
        (this->*&ArrayBase::Clear)();
    }
    else
    {
        AllocatorType::Destruct(Data.Data + index);
        AllocatorType::CopyArrayForward(Data.Data + index, Data.Data + index + 1, Data.Size - 1 - index);
        --Data.Size;
    }
}
}

// VM::RemoveVMAbcFileWeak: forgets file unless the VM is being destroyed.
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
__declspec(noinline) UPInt TreeContainer::GetSize() const
{
    return GetReadOnlyData()->Children.GetSize();
}
} } // namespace Scaleform::Render

namespace Scaleform { namespace GFx { namespace AS3 {

// sfr34 batch R: the verbose output of VM values to the UI (values, unsigned numbers, value arrays, the operand
// stack and the register file), and the validity test of a 2D matrix.

static inline const char* FUN_1424ed700(Abc::NamespaceKind kind) { return ::Scaleform::GFx::AS3::AsString(kind); }    // the name of a namespace kind

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
// The operand stack's positions are read through a layout view (they are private to it)
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
// The register file's positions are read through a layout view (they are private to it)
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
// MS2-FUNCTIONAL the literal Output tails are merged through "goto out" as in the exe;
// left: the exe's rbp frame (larger locals area), its hoisted Output vptr in r9, scheduling
// @0x14251b350
void FUN_14251b350(const VM* vm, FlashUI* ui, const Value* v)
{
    const Value& value = *v;
    const char*  s;
    switch (value.GetKind())
    {
    case Value::kUndefined:
        { s = "undefined"; goto out; }
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
        {
            { s = "NaN"; goto out; }
        }

        if (value.IsPOSITIVE_ZERO())
        {
            { s = "+0"; goto out; }
        }

        if (value.IsNEGATIVE_ZERO())
        {
            { s = "-0"; goto out; }
        }

        if (value.IsPOSITIVE_INFINITY())
        {
            { s = "+Infinity"; goto out; }
        }

        if (value.IsNEGATIVE_INFINITY())
        {
            { s = "-Infinity"; goto out; }
        }

        {
            DoubleFormatter f(value.AsNumber());
            f.Convert();
            ui->Output(FlashUI::Output_Action, f.ToCStr());
        }
        break;
    case Value::kString:
        if (value.GetStringNode())
        {
            ui->Output(FlashUI::Output_Action, "\"");
            ui->Output(FlashUI::Output_Action, value.AsString().ToCStr());
            s = "\"";
            goto out;
        }
        else
            { s = "null"; goto out; }
    case Value::kThunk:
        ui->Output(FlashUI::Output_Action, "thunk@");
        FUN_14251b210(ui, UInt64(&value.AsThunk()), true);
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
    case Value::kVTableInd:
        ui->Output(FlashUI::Output_Action, "VTable ind: ");
        FUN_14251b190(ui, SInt64(value.GetVTableInd()));
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
            { s = "null"; goto out; }
    case Value::kFunction:
        if (value.IsNull())
            ui->Output(FlashUI::Output_Action, "null");
        else
        {
            ui->Output(FlashUI::Output_Action, "function@");
            FUN_14251b210(ui, UInt64(value.GetObject()), true);
        }
        break;
    case Value::kObject:
        if (value.IsNull())
            ui->Output(FlashUI::Output_Action, "null");
        else
        {
            const Object* obj = value.GetObject();
            const Traits& tr  = obj->GetTraits();
            if (tr.IsGlobal())
            {
                if (obj == vm->GlobalObject.GetPtr())
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
            else
            {
                Sfr34_OutputTraitsName(ui, tr);
                ui->Output(FlashUI::Output_Action, "@");
                FUN_14251b210(ui, UInt64(obj), true);
            }
        }
        break;
    case Value::kClass:
        if (value.GetObject())
        {
            Sfr34_OutputTraitsName(ui, value.GetObject()->GetTraits());
            s = "$$";
            goto out;
        }
        else
            { s = "null"; goto out; }
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
            { s = "null"; goto out; }
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
        { s = "$$"; goto out; }
    case Value::kMethodInd:
        break;
    default:
        break;
    }
    return;
out:
    ui->Output(FlashUI::Output_Action, s);
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


// A namespace instance of the namespace class (not interned). The exe inlines
// InstanceTraits::fl::Namespace::MakeInstance (0x14241ab60) here, but not the Namespace constructor (0x1423edb60).
// @0x1425164c0
Pickable<Instances::Namespace> VM::MakeNamespace(Abc::NamespaceKind kind, const ASString& uri, const Value& prefix) const
{
    InstanceTraits::fl::Namespace& itr =
        static_cast<InstanceTraits::fl::Namespace&>(GetClassTraitsNamespace().GetInstanceTraits());
    return Pickable<Instances::Namespace>(new((MemAddressPtr)((void*)&itr), StatMV_VM, __FILE__, __LINE__)
                                          Instances::Namespace(itr.GetVM(), itr.InstanceFactory, kind, uri, prefix));
}

// The anonymous class info only has its names set
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
// SDK AS3_AvmDisplayObj.cpp loop (GetAvmParent inlined); not found gives the stage's root. The parent step is
// GetAvmParent's own NULL-parent return, so the exe leaves the loop straight from a NULL parent.
// @0x14250d990
DisplayObject* AvmDisplayObj::GetRoot()
{
    AvmDisplayObj* cur = this;
    while (cur && (!cur->GetAS3Obj() || !cur->GetAS3Obj()->HasLoaderInfo()))
    {
        AvmInteractiveObj* parent = Sfr34_AvmParent(cur);
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
static SF_FORCEINLINE void Sfr34_TextFieldNotify(UPInt self, BuiltinType type)
{
    const AvmDisplayObj*                  avm  = reinterpret_cast<const AvmDisplayObj*>(self - 0x40);
    MovieRoot*                            root = AS3RootOf(avm->pDispObj);
    Instances::fl_display::DisplayObject* obj  = avm->GetAS3Obj();
    if (obj && obj->HasEventHandler(root->BuiltinsMgr.GetBuiltin(type), false))
    {
        SPtr<Instances::fl_events::Event> evt = obj->CreateEventObject(root->BuiltinsMgr.GetBuiltin(type), true, false);
        evt->Target = obj;
        obj->DispatchEventObject(evt, avm->pDispObj);
    }
}

// AvmTextField::NotifyChanged.
// Free function on the subobject this (AvmTextField is opaque in the shared header)
// @0x142518360
void AvmTextField::NotifyChanged()
{
    const UPInt self = reinterpret_cast<UPInt>(this) + 0x40;
    Sfr34_TextFieldNotify(self, AS3Builtin_change);
}

// AvmTextField::OnScroll.
// Free function on the subobject this (AvmTextField is opaque in the shared header)
// @0x14251ae60
void AvmTextField::OnScroll()
{
    const UPInt self = reinterpret_cast<UPInt>(this) + 0x40;
    Sfr34_TextFieldNotify(self, AS3Builtin_scroll);
}

// The data of a URLLoader's binary load, and its open/progress/complete events; a failed load gives the error
// event.
// A 4.1.18 virtual of the root, defined non-virtual
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

static inline ClassTraits::Traits** FUN_142505aa0(TClassTraitsCache* cache, const Multiname& mn) { return ::Scaleform::GFx::AS3::Sfr33ClassTraitsCacheGet(cache, mn); }   // MultinameHash::Get

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
// The operand stack's positions are read through a layout view (they are private to it)
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

// ResourceHandle::GetResource, an out-of-line copy of the inline, written out with the SDK's body (pointer handles
// first). A free function: the inline is defined in gfx_moviedef.h.
// @0x14250d840
Scaleform::GFx::Resource* FUN_14250d840(const Scaleform::GFx::ResourceHandle* self,
                                        Scaleform::GFx::ResourceBinding* pbinding)
{
    if (self->GetHandleType() == Scaleform::GFx::ResourceHandle::RH_Pointer)
        return self->GetResourcePtr();

    Scaleform::GFx::ResourceBindData rbd;
    pbinding->GetResourceData(&rbd, self->GetBindIndex());
    return rbd.pResource;
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
// A free function (the member is not declared in the shared VTable class); SDK form.
// @0x14250ba10
void FUN_14250ba10(const VTable* vt, Value& result, AbsoluteIndex ind, Object* obj)
{
    const Value& m = vt->VTMethods[static_cast<UInt32>(ind.Get())];
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
    if (closure)
    {
        const String s = String("MethodClosure ") + String(name.ToCStr(), name.GetSize());
        name.AssignNode(name.GetManager()->CreateStringNode(s.ToCStr(), s.GetSize()));
    }
    else
    {
        const String s = String("Function ") + String(name.ToCStr(), name.GetSize());
        name.AssignNode(name.GetManager()->CreateStringNode(s.ToCStr(), s.GetSize()));
    }
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
// The two empty-name renames share one block after the substring one, and the temporary's node stays in a
// local across Value::operator= (released through it), as in the exe.
// @0x14251cef0
__declspec(noinline) void Multiname::PostProcessName(bool isAttr)
{
    if (!Name.IsString())
        return;
    ASString n = Name.AsString();
    if (n.GetSize() == 0)
        return;
    ASStringManager* const mgr = n.GetManager();
    ASStringNode* node;
    if (n[0] != '*')
    {
        if (n[0] != '@' || isAttr)
            return;
        Kind = static_cast<Abc::MultinameKind>(Kind | 8);
        if (n.GetSize() != 2 || n[1] != '*')
        {
            node = n.SubstringNode(1, n.GetSize());
            node->AddRef();
            goto assign;
        }
    }
    node = mgr->GetEmptyStringNode();
    node->AddRef();
assign:
    ASStringNode* const tmp = node;
    FUN_1424e0d40(Name, reinterpret_cast<const ASString&>(tmp));
    node->Release();
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

static inline void FUN_1425273b0(Multiname& mn, const Value& qname) { ::Scaleform::GFx::AS3::Sfr27MultinameFromQName(&mn, &qname); }     // the name and namespace of a QName object (sfr_as3_15)

// Moves the top value of the stack into this one and pops it; this one is not released. Only inlined.
SF_INLINE void Value::PickUnsafe(ValueStack& v)
{
    const Value& top = *v.pCurrent;
    Flags = top.Flags;
    Bonus = top.Bonus;
    value = top.value;
    --v.pCurrent;
}

// Multiname::PickRTNameUnsafe: the run-time name on top of the operand stack: a QName object gives the name and
// namespace (and is released), anything else is moved into the name as it is (the old name is not released).
// A free function (not declared in the shared Multiname class). SDK form: IsQNameObject (0x142514bf0, inlined) and
// each use re-read the top, and the two cases are an if/else; this keeps the exe's QName flag (xor r8b ... cmovne).
// @0x14251c8a0
void FUN_14251c8a0(Multiname& mn, ValueStack& vs)
{
    if (IsQNameObject(*vs.GetTopPtr()))
    {
        FUN_1425273b0(mn, *vs.GetTopPtr());
        vs.GetTopPtr()->~Value();
        vs.Release(1);
    }
    else
    {
        mn.Name.PickUnsafe(vs);
        mn.PostProcessName(false);
    }
}

static inline ClassTraits::Traits* FUN_142524f60(VM& vm, VMAbcFile& file, const Abc::Multiname& mn)
{ return reinterpret_cast<ClassTraits::Traits*>(Sfr31ResolveClassTraits(reinterpret_cast<Scaleform::UPInt>(&vm), reinterpret_cast<Scaleform::UPInt>(&file), reinterpret_cast<Scaleform::UPInt>(&mn))); }  // a scaleform.gfx class

// The class traits of an ABC class by the name of its instance info: from the VM's class traits cache, else (for
// the scaleform.gfx package) made for it.
// MS2-FUNCTIONAL SDK GetUserDefinedTraits form; register allocation only (the VM, the namespace and the result swap
// callee-saved registers)
// @0x14250f9a0
__declspec(noinline) ClassTraits::Traits* FUN_14250f9a0(VM& vm, VMAbcFile& file, const Abc::ClassInfo& ci)
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

// ConstPool::GetNamespace(UPInt) and NamespaceInfo::IsPublic (AS3_Abc_ConstPool.h).
static inline const Abc::NamespaceInfo& Sfr18GetNs(const Abc::ConstPool& cp, UPInt ind)
{
    if (ind == 0)
        return cp.any_namespace;
    return cp.ConstNamespace[ind];
}

static inline bool Sfr18IsPublic(const Abc::NamespaceInfo& ns)
{
    return ns.Kind == 0 || ns.Kind == 4;
}

// HasPublicNamespace (AS3_Object.cpp): a multiname in a public (or explicit) namespace, either
// its own namespace or any of its namespace set.
// @0x1425112f0
bool FUN_1425112f0(const Abc::ConstPool& cp, const Abc::Multiname& mn)
{
    // QName case ...
    if ((mn.Kind & 3) == 0 || (mn.Kind & 3) == 1)
        return Sfr18IsPublic(Sfr18GetNs(cp, mn.Ind));

    // Multiname case ...
    const UInt8* ptr = cp.const_ns_set[mn.Ind].Data;
    UInt32 size;
    UInt32 ns_ind;
    Abc::Read(ptr, size);

    for (UInt32 i = 0; i < size; ++i)
    {
        Abc::Read(ptr, ns_ind);
        if (Sfr18IsPublic(Sfr18GetNs(cp, ns_ind)))
            return true;
    }

    return false;
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

// VM::GetFunctReturnType(const ThunkInfo&): the instance traits of the class a thunk's result type names (in its
// package's public namespace), found in the class traits cache or else in the global object (then cached); Object
// when the thunk has no result type or the class is unknown.
// Free function (not declared in the shared VM class).
// @0x142509e30
InstanceTraits::Traits& FUN_142509e30(VM& vm, const ThunkInfo& ti)
{
    if (const TypeInfo* rt = ti.ResultType)
    {
        ASString name = vm.GetStringManager().CreateConstString(rt->Name);
        const Instances::Namespace* ns;
        {
            ASString pkg = vm.GetStringManager().CreateString(rt->PkgName ? rt->PkgName : "");
            if (pkg.IsEmpty())
                ns = &vm.GetPublicNamespace();
            else
                ns = FUN_142415c20(&static_cast<InstanceTraits::fl::Namespace&>(
                                       vm.GetClassTraitsNamespace().GetInstanceTraits()),
                                   Abc::NS_Public, pkg, Value::GetUndefined());
        }
        ClassTraits::Traits*  ct;
        ClassTraits::Traits** p = FUN_142414ac0(&vm.ClassTraitsSet, name, *ns);
        if (p == NULL || (ct = *p) == NULL)
        {
            ClassTraits::Traits* gct = FUN_142415520(vm.GlobalObject.GetPtr(), name, *ns);
            ct = gct;
            if (gct)
                vm.ClassTraitsSet.Add(name, *ns, gct);
        }
        if (ct)
            return ct->GetInstanceTraits();
    }
    return vm.GetClassTraitsObject().GetInstanceTraits();
}

// VM::GetFunctReturnType(const Value&): the return type of a thunk (or thunk closure / thunk function), of a method
// by index (in its traits' ABC file), of a VTable slot (or VTable index closure) and of a function; Object for
// other values and unknown classes.
// A free function (not declared in the shared VM class). The VTable is a named local, so the slot index is read
// after GetVT; the method and thunk pointers are named locals as well, which gives the exe's loads and registers.
// @0x14250a060
InstanceTraits::Traits& FUN_14250a060(VM& vm, const Value& v)
{
    const Value::KindType kind = v.GetKind();

    switch (kind)
    {
    case Value::kFunction:
    {
        const Instances::Function& f = v.AsFunction();
        const Abc::Multiname* rt = static_cast<const Abc::Multiname*>(
            FUN_142416e70(reinterpret_cast<const char*>(&f.GetTraits())));
        VMAbcFile* file = *reinterpret_cast<VMAbcFile* const*>(reinterpret_cast<const char*>(&f.GetTraits()) + 0xf0);
        const ClassTraits::Traits* ctr = FUN_142524f60(vm, *file, *rt);

        if (ctr)
            return ctr->GetInstanceTraits();
    }
    break;
    case Value::kVTableInd:
    case Value::kVTableIndClosure:
    {
        const VTable& vt = v.GetTraits().GetVT();
        const Value& real_func = vt.VTMethods[UInt32(v.GetVTableInd())];

        // The vtable stores a MethodInd or a thunk.
        if (real_func.GetKind() == Value::kMethodInd)
        {
            const SInt32 ind = real_func.GetMethodInd();
            VMAbcFile& file = *real_func.GetTraits().GetFilePtr();
            const Abc::File& abc = file.GetAbcFile();
            const Abc::MethodInfo* mi = abc.Methods.Info[ind];
            const Abc::Multiname& rt = reinterpret_cast<const Abc::TraitInfo*>(mi)->GetName(abc.Const_Pool);
            const ClassTraits::Traits* ctr = FUN_142524f60(vm, file, rt);

            if (ctr)
                return ctr->GetInstanceTraits();
        }
        else
        {
            switch (kind)
            {
            case Value::kVTableInd:
                return FUN_142509e30(vm, real_func.AsThunk());
            case Value::kVTableIndClosure:
                return FUN_142509e30(vm, real_func.AsThunk());
            default:
                break;
            }
        }
    }
    break;
    case Value::kMethodInd:
    {
        const SInt32 ind = v.GetMethodInd();
        VMAbcFile& file = *v.GetTraits().GetFilePtr();
        const Abc::File& abc = file.GetAbcFile();
        const Abc::MethodInfo* mi = abc.Methods.Info[ind];
        const Abc::Multiname& rt = reinterpret_cast<const Abc::TraitInfo*>(mi)->GetName(abc.Const_Pool);
        const ClassTraits::Traits* ctr = FUN_142524f60(vm, file, rt);

        if (ctr)
            return ctr->GetInstanceTraits();
    }
    break;
    case Value::kThunk:
        return FUN_142509e30(vm, v.AsThunk());
    case Value::kThunkFunction:
    {
        const ThunkInfo& ti = **reinterpret_cast<const ThunkInfo* const*>(reinterpret_cast<const char*>(&v.AsThunkFunction()) + 0x40);
        return FUN_142509e30(vm, ti);
    }
    case Value::kThunkClosure:
        return FUN_142509e30(vm, v.AsThunk());
    default:
        break;
    }

    return vm.GetClassTraitsObject().GetInstanceTraits();
}

// sfr34 batch Y: type tests of values (against class traits and by class name) and the push of a value onto an
// argument array.

// VM::IsOfType: whether v is of the class ctr: a number in the range of int or uint (when integral) is of those,
// any int or uint a Number, everything of Object; references by their class (or a base of it, or an interface).
// @0x1425146d0
bool FUN_1425146d0(VM& vm, const Value& v, const ClassTraits::Traits& ctr)
{
    const BuiltinTraitsType tt = ctr.GetTraitsType();
    switch (v.GetKind())
    {
    case Value::kUndefined:
        return false;
    case Value::kBoolean:
        return tt == Traits_Boolean || &ctr == &vm.GetClassTraitsObject();
    case Value::kInt:
        if (tt == Traits_UInt)
            return v.AsInt() >= 0;
        if (tt == Traits_Number)
            return true;
        return tt == Traits_SInt || &ctr == &vm.GetClassTraitsObject();
    case Value::kUInt:
        if (tt == Traits_SInt)
            return v.AsUInt() <= 0x7fffffff;
        if (tt == Traits_Number)
            return true;
        return tt == Traits_UInt || &ctr == &vm.GetClassTraitsObject();
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
        return tt == Traits_Number || &ctr == &vm.GetClassTraitsObject();
    }
    case Value::kString:
        if (!v.GetStringNode())
            return false;
        return tt == Traits_String || &ctr == &vm.GetClassTraitsObject();
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
}

} } } // namespace Scaleform::GFx::AS3

static inline const Scaleform::GFx::AS3::ClassTraits::Traits* FUN_142525270(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Multiname& mn)
{ return reinterpret_cast<const Scaleform::GFx::AS3::ClassTraits::Traits*>(::Scaleform::GFx::AS3::Sfr31FindClassTraitsByMn(reinterpret_cast<Scaleform::UPInt>(&vm), reinterpret_cast<Scaleform::UPInt>(&mn))); }  // Resolve2ClassTraits

// Whether v is of the class named className (a qualified name, "a.b::C" or "a.b.C").
// @0x1425145d0
bool FUN_1425145d0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v, const char* className)
{
    using namespace Scaleform::GFx::AS3;
    const Multiname            mn(vm, Scaleform::StringDataPtr(className));
    const ClassTraits::Traits* ctr = FUN_142525270(vm, mn);
    return ctr && FUN_1425146d0(vm, v, *ctr);
}

// The root's loaded movie definitions (+0x6e8), on the node/allocator/entry types of the add instances in sfr_as3_15.
namespace Scaleform { struct MS2_LoadedMovieDefInfo { Ptr<GFx::MovieDefImpl> pMovieDef; unsigned UseCnt; MS2_LoadedMovieDefInfo(GFx::MovieDefImpl* def) : pMovieDef(def), UseCnt(1) {} }; typedef HashNode<GFx::MovieDefImpl*, MS2_LoadedMovieDefInfo, IdentityHash<GFx::MovieDefImpl*> > MS2_LoadedMovieDefNode; typedef HashsetNodeEntry<MS2_LoadedMovieDefNode, MS2_LoadedMovieDefNode::NodeHashF> MS2_LoadedMovieDefEntry; typedef HashSetBase<MS2_LoadedMovieDefNode, MS2_LoadedMovieDefNode::NodeHashF, MS2_LoadedMovieDefNode::NodeAltHashF, AllocatorLH<GFx::MovieDefImpl*, 2>, MS2_LoadedMovieDefEntry> MS2_LoadedMovieDefSet; template<> MS2_LoadedMovieDefEntry::HashsetNodeEntry(const MS2_LoadedMovieDefEntry&); }   // the entry copy ctor (0x1424d54f0) stays out of line, as in the exe; its COMDAT is sfr_as3_15's
namespace Scaleform {
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

// VM::IsPrimitiveType (4.1 AS3_VM.h): one of the cached primitive class traits.
static SF_FORCEINLINE bool Sfr18IsPrimitiveType(const VM& vm, const ClassTraits::Traits& tr)
{
    const ClassTraits::Traits* p = &tr;
    return p == vm.TraitsBoolean || p == vm.TraitsNumber || p == vm.TraitsInt || p == vm.TraitsUint ||
           p == vm.TraitsString;
}

// The InstanceTraits overload.
static SF_FORCEINLINE bool Sfr18IsPrimitiveType(const VM& vm, const InstanceTraits::Traits& tr)
{
    const InstanceTraits::Traits* p = &tr;
    return p == &vm.TraitsBoolean->GetInstanceTraits() || p == &vm.TraitsNumber->GetInstanceTraits() ||
           p == &vm.TraitsInt->GetInstanceTraits() || p == &vm.TraitsUint->GetInstanceTraits() ||
           p == &vm.TraitsString->GetInstanceTraits();
}

// VM::IsVMCachedType: whether tr is one of the class traits the VM caches (and XML's, when it is enabled).
// A free function (not declared in the shared VM class).
// @0x142515460
bool FUN_142515460(const VM& vm, const ClassTraits::Traits* tr)
{
    const ClassTraits::Traits* p = tr;
    bool result = false;

    if (Sfr18IsPrimitiveType(vm, *p))
        result = true;
    else if (p == vm.TraitsClassClass)
        result = true;
    else if (p == vm.TraitsObject)
        result = true;
    else if (p == vm.TraitsNamespace)
        result = true;
    else if (p == vm.TraitsFunction)
        result = true;
    else if (p == vm.TraitsArray)
        result = true;
    else if (p == vm.TraitsVector_int)
        result = true;
    else if (p == vm.TraitsVector_uint)
        result = true;
    else if (p == vm.TraitsVector_double)
        result = true;
    else if (p == vm.TraitsVector_String)
        result = true;
    else if (vm.GetXMLSupport().IsEnabled())
    {
        const XMLSupport& xmls = vm.GetXMLSupport();
        if (p == xmls.GetClassTraitsQName())
            result = true;
        else if (p == xmls.GetClassTraitsXML())
            result = true;
        else if (p == xmls.GetClassTraitsXMLList())
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

// ToAvmDisplayObjContainer (AS3_AvmDisplayObjContainer.h) with its null test
static inline AvmDisplayObjContainer* Sfr18ToAvmContainerN(DisplayObject* p)
{
    if (!p)
        return NULL;
    return static_cast<AvmDisplayObjContainer*>(p->GetAvmObjImpl()->ToAvmDispContainerBase());
}

// The AS3 container part of the stage, NULL for none (the SDK's ToAvmDisplayObjContainer).
static inline AvmDisplayObjContainer* Sfr34_ToAvmStage(DisplayObject* p)
{
    if (!p)
        return NULL;
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
                    : Sfr34_ToAvmStage(root->pStage)->GetAS3Obj();
        if (as3obj)
            as3obj->Dispatch(evt, focused);
    }
}

// @0x14251a1e0
void FUN_14251a1e0(UPInt self, InteractiveObject* pmovie, const EventId& evt, int keyMask)
{
    SF_UNUSED(pmovie);
    Sfr34_OnKey(self, evt, keyMask);
}

// @0x14251a3b0
void FUN_14251a3b0(UPInt self, InteractiveObject* pmovie, const EventId& evt, int keyMask)
{
    SF_UNUSED(pmovie);
    Sfr34_OnKey(self, evt, keyMask);
}

// MovieImpl::GetCachedLog.
static __forceinline Log* Sfr18GetCachedLog(MovieImpl* movie)
{
    if (!((UByte)(movie->Flags >> 1) & 1))     // Flag_CachedLogFlag
        movie->pCachedLog = movie->GetStateBag()->GetLog();
    return movie->pCachedLog;
}

// MovieRoot's FlashUI::Output: an AVM message to the movie's log (cached for the frame) by type, cut to 1999
// characters. self is the FlashUI part (+0x28) of the root.
// A free function on the FlashUI subobject this (MovieRoot's FlashUI base is not modeled).
// @0x14251bc40
void FUN_14251bc40(UPInt self, FlashUI::OutputMessageType type, const char* msg)
{
    MovieImpl* movie = reinterpret_cast<MovieRoot*>(self - 0x28)->GetMovieImpl();
    Log* log = Sfr18GetCachedLog(movie);
    if (!log)
        return;
    LogMessageId logId;
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
    if (len < sizeof(buf))
        log->LogMessageById(logId, "%s", buf);
    else
        log->LogMessageById(logId, "%s ...<truncated>", buf);
}

// sfr34 batch AA: the mouse hit test of an AS3 bitmap.

// AvmBitmap::GetTopMostMouseEntity: a visible bitmap with an image is hit when the point (in its parent's space)
// falls inside the image's rectangle (in twips); the hit is its parent, the interactive object.
// Compiled under
// strict_gs_check like PointTestLocal (0x14251c9f0): this gives the exe's /GS cookie and frame (point low, rect high).
// @0x14250f660
#pragma strict_gs_check(push, on)
DisplayObjectBase::TopMostResult AvmBitmap::GetTopMostMouseEntity(const Render::PointF& pt,
                                                                TopMostDescr* pdescr)
{   DisplayObject* const self = this;
    if (!self->GetVisible())
        return DisplayObjectBase::TopMost_FoundNothing;
    ImageResource* const& pImage = *reinterpret_cast<ImageResource* const*>(reinterpret_cast<const char*>(self) + 0xc0);
    if (pImage)
    {
        Render::PointF p(Render::PointF::NoInit);
        self->TransformPointToLocal(&p, pt);
        Render::ImageRect rect = pImage->GetImage()->GetRect();
        RectF r(0, 0, Render::SizeF(PixelsToTwips((float)rect.Width()), PixelsToTwips((float)rect.Height())));
        if (r.Contains(p))
        {
            pdescr->pResult = self->GetParent();
            return DisplayObjectBase::TopMost_Found;
        }
    }
    return DisplayObjectBase::TopMost_FoundNothing;
}
#pragma strict_gs_check(pop)

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

static inline void* FUN_1425059f0(const void* self, const UPInt& key) { return ::Scaleform::GFx::AS3::Sfr33IdWordHashGet(static_cast<const UByte*>(self), key); }   // the value an identity-hashed word key maps to

// MovieRoot::RemoveLoadedMovieDef: one use less of a loaded movie definition; at the last its entry leaves the
// root's loaded movie definitions (+0x6e8). True when the entry was removed.
// The SDK HashSetBase::RemoveAlt on the real set type; the entry copy ctor is called out of line (declared above).
//

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

// @0x142522920
bool FUN_142522920(MovieRoot* self, MovieDefImpl* def)
{
    MS2_LoadedMovieDefSet* set = reinterpret_cast<MS2_LoadedMovieDefSet*>(&self->LoadedMovieDefs);
    MovieDefImpl* const key = def;
    unsigned* pcnt = static_cast<unsigned*>(FUN_1425059f0(set, reinterpret_cast<const UPInt&>(def)));
    if (!pcnt || --pcnt[2] != 0)
        return false;
    set->RemoveAlt(key);
    return true;
}

// VM::IsVMCachedType: whether itr is the instance traits of one of the class traits the VM caches (and XML's,
// when it is enabled).
// A free function (not declared in the shared VM class).
// @0x142515580
bool FUN_142515580(const VM& vm, const InstanceTraits::Traits* itr)
{
    const InstanceTraits::Traits* p = itr;
    bool result = false;

    if (Sfr18IsPrimitiveType(vm, *p))
        result = true;
    else if (p == &vm.TraitsClassClass->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsObject->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsNamespace->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsFunction->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsArray->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsVector_int->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsVector_uint->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsVector_double->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsVector_String->GetInstanceTraits())
        result = true;
    else if (vm.GetXMLSupport().IsEnabled())
    {
        const XMLSupport& xmls = vm.GetXMLSupport();
        if (p == xmls.GetITraitsQName())
            result = true;
        else if (p == xmls.GetITraitsXML())
            result = true;
        else if (p == xmls.GetITraitsXMLList())
            result = true;
    }

    return result;
}

// The exe calls the SPtr<DisplayObject> assignment out of line (instantiated in sfr_as3_06).
template <> SPtr<Instances::fl_display::DisplayObject>&
SPtr<Instances::fl_display::DisplayObject>::operator=(const SPtr<Instances::fl_display::DisplayObject>& other);

// The actions of level srclvl moved to the end of level dstlvl's queue, in order. The copy of an entry leaves out
// its function value (4.1.18 copies the event, the character and objects, the C function and the load notifier).
// @0x142522ae0
void MovieRoot::RequeueActionQueue(ActionLevel srclvl, ActionLevel dstlvl)
{
    if (ActionQueue.Entries[srclvl].pActionRoot)
    {
        ActionQueueIterator iter(srclvl, &ActionQueue);
        const ActionEntry* src;
        while ((src = iter.getNext()) != NULL)
        {
            ActionEntry* dst  = ActionQueue.InsertEntry(dstlvl);   // InsertEmptyAction, inlined
            dst->Type         = src->Type;
            dst->pCharacter   = src->pCharacter;
            dst->pAS3Obj      = src->pAS3Obj;
            Sfr18CopyEventId(dst->mEventId, src->mEventId);
            dst->CFunction    = src->CFunction;
            dst->pNLoadInitCL = src->pNLoadInitCL;
        }
    }
}

// sfr34 batch AB: the registration of a method in the virtual table of traits.

// Traits::RegisterWithVT: method v (named name in nsi's namespace) overrides the slot of that name and namespace
// (a getter added to a setter, or the reverse, gets a slot of its own), or gets a new one. False when that slot is
// not a method.
// A Traits member in the exe (this in rcx, the CheckResult return slot in rdx); it is not declared in the shared
// Traits class, so a unit-local view declares it.
struct Sfr34_TraitsAddSlotView : Traits
{
    CheckResult FUN_142521d20(const ASString& name, const SlotInfo& nsi, const Value& v, SlotInfo::BindingType bt);
};
// @0x142521d20
CheckResult Sfr34_TraitsAddSlotView::FUN_142521d20(const ASString& name, const SlotInfo& nsi, const Value& v,
                                                    SlotInfo::BindingType bt)
{
    Traits* self = this;
    const Instances::Namespace& ns  = *nsi.pNs;
    const AbsoluteIndex         ind = FindSlotInfoIndex(name, ns);
    bool                        result = false;
    if (ind.IsValid())
    {
        const SlotInfo&             si     = Sfr18TraitsSlotInfo(self, ind);
        const SlotInfo::BindingType cur_bt = static_cast<SlotInfo::BindingType>(si.BindType);
        if (cur_bt == SlotInfo::BT_Unknown || (cur_bt >= SlotInfo::BT_Code && cur_bt <= SlotInfo::BT_GetSet))
        {
            SlotInfo::BindingType new_bt = cur_bt;
            if ((cur_bt == SlotInfo::BT_Get && bt == SlotInfo::BT_Set) || (cur_bt == SlotInfo::BT_Set && bt == SlotInfo::BT_Get))
                new_bt = SlotInfo::BT_GetSet;
            if (new_bt != bt)
                self->Add2VT(name, ns, si, v, bt);
            else
            {
                self->UpdateVT4IM(name, ns, v, bt);
                self->UpdateVT(si, v, bt);
            }
            result = true;
        }
    }
    else
    {
        self->Add2VT(name, ns, nsi, v, bt);
        result = true;
    }
    return result;
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
// SDK Tracer::GetNextSwitchStmt, as a free function over a layout view of the byte code's holder (it has no caller
// in the exe).
// @0x14250c080
UPInt FUN_14250c080(const void* self, UPInt& pos)
{
    struct View { char pad[0x50]; const UInt8* data; UPInt size; };
    const View* c = static_cast<const View*>(self);
    UPInt result = 0;
    int op = 0; // SDK Code::OpCode (an int enum)
    UPInt op_pos;
    while (pos < c->size)
    {
        op_pos = pos;
        op     = c->data[pos++];
        {
            const Sfr34_OpCodeInfo& oi = DAT_14317fea0[op];
            if (oi.pop_mn)
                Abc::ReadU30(c->data, pos);
            if (oi.pop_args)
                Abc::ReadU30(c->data, pos);
            if (oi.pop_args | oi.pop_mn)
                continue;
        }
        switch (op)
        {
        case 0x0c: case 0x0d: case 0x0e: case 0x0f: case 0x10: case 0x11: case 0x12: case 0x13:
        case 0x14: case 0x15: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
            // the branches
            Abc::ReadS24(c->data, pos);
            break;
        case 0x1b:
        {
            // lookupswitch: the default offset, the case count - 1 and the case offsets
            result = op_pos;
            Abc::ReadS24(c->data, pos);
            const int n = Abc::ReadU30(c->data, pos);
            for (int i = 0; i <= n; ++i)
                Abc::ReadS24(c->data, pos);
        }
            goto end;
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
end:
    return result;
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

// (forwarder above)   // VM: raise the error as an instance of the class

} } } // namespace Scaleform::GFx::AS3

// SlotInfo::GetSlotValueUnsafe(VM&, Value&, const Value& _this, const VTable*, ValTarget): the value of the slot of
// _this's object: a stored value (of the global object's value array, a Value, an object, a primitive, a string, a
// constant C string), a method (as a closure of the object when it is one and the value is read), or the result of
// the getter. vt is the method table to use (super properties); else that of _this's traits. False (with a
// TypeError or ReferenceError raised for a non-callable getter or a write-only property) when the slot has no
// value.
// A free function (not declared in the shared SlotInfo class); the slot is read over its address. ret is
// __restrict, as the CheckResult return slot it stands for, so the result store can move before the value's.
// @0x14250e2d0
char* FUN_14250e2d0(const void* psi, void* __restrict ret, Scaleform::GFx::AS3::VM* pvm, Scaleform::GFx::AS3::Value* pvalue,
                    const Scaleform::GFx::AS3::Value* pthis, void* pvt, int vtt)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    const SlotInfo& si    = *static_cast<const SlotInfo*>(psi);
    VM&             vm    = *pvm;
    Value&          value = *pvalue;
    const Value&    _this = *pthis;
    char* __restrict r    = static_cast<char*>(ret);
    const SInt32    ind   = si.ValueInd;
    switch (si.BindType)
    {
    case SlotInfo::BT_ValueArray:
        value.AssignUnsafe(reinterpret_cast<const Value*>(*reinterpret_cast<const UPInt*>(reinterpret_cast<UPInt>(_this.GetObject()) + 0xa8))[UInt32(ind)]);
        break;
    case SlotInfo::BT_Value:
        value.AssignUnsafe(*reinterpret_cast<const Value*>(reinterpret_cast<UPInt>(_this.GetObject()) + UInt32(ind)));
        break;
    case SlotInfo::BT_ObjectAS:
        reinterpret_cast<STPtr*>(reinterpret_cast<UPInt>(_this.GetObject()) + UInt32(ind))->GetValueUnsafe(value);
        break;
    case SlotInfo::BT_ObjectCpp:
        value.AssignUnsafe(*reinterpret_cast<const SPtr<Instances::fl::GlobalObjectCPP>*>(reinterpret_cast<UPInt>(_this.GetObject()) + UInt32(ind)));
        break;
    case SlotInfo::BT_Boolean:
        value.SetBoolUnsafe(*reinterpret_cast<const bool*>(reinterpret_cast<UPInt>(_this.GetObject()) + UInt32(ind)));
        break;
    case SlotInfo::BT_Int:
        value.SetSInt32Unsafe(*reinterpret_cast<const SInt32*>(reinterpret_cast<UPInt>(_this.GetObject()) + UInt32(ind)));
        break;
    case SlotInfo::BT_UInt:
        value.SetUInt32Unsafe(*reinterpret_cast<const UInt32*>(reinterpret_cast<UPInt>(_this.GetObject()) + UInt32(ind)));
        break;
    case SlotInfo::BT_Number:
        value.SetNumberUnsafe(*reinterpret_cast<const Value::Number*>(reinterpret_cast<UPInt>(_this.GetObject()) + UInt32(ind)));
        break;
    case SlotInfo::BT_String:
        if (GFx::ASStringNode* node = *reinterpret_cast<GFx::ASStringNode* const*>(reinterpret_cast<UPInt>(_this.GetObject()) + UInt32(ind)))
            value.AssignUnsafe(node);
        else
            value.SetNullUnsafe();   // null is an object, not a string
        break;
    case 10:   // a constant C string (4.1.18 numbers this binding before BT_Code)
        ValueAssignCopies::AssignUnsafeStrInline18(value, vm.GetStringManager().CreateConstString(*reinterpret_cast<const char* const*>(reinterpret_cast<UPInt>(_this.GetObject()) + UInt32(ind))));
        break;
    case SlotInfo::BT_Code:
    {
        const VTable* vt = static_cast<const VTable*>(pvt);
        if (!vt)
            vt = &vm.GetValueTraits(_this).GetVT();
        if (_this.IsObject() && vtt == SlotInfo::valGet)
            FUN_14250ba10(vt, value, AbsoluteIndex(si.ValueInd), _this.GetObject());
        else
            value.AssignUnsafe(vt->GetValue(AbsoluteIndex(si.ValueInd)));
        break;
    }
    case SlotInfo::BT_Get:
    case SlotInfo::BT_GetSet:
    {
        const VTable* vt = static_cast<const VTable*>(pvt);
        if (!vt)
            vt = &vm.GetValueTraits(_this).GetVT();
        const Value getter = vt->GetValue(AbsoluteIndex(si.ValueInd));
        if (getter.IsCallable())
            vm.ExecuteInternalUnsafe(getter, _this, value, 0, NULL, false);
        else
        {
            TrThrowError(vm, VM::Error(VM::eCallOfNonFunctionError, vm, getter), fl::TypeErrorCI);
            *r = false;
            return r;
        }
        break;
    }
    case SlotInfo::BT_Set:
        TrThrowError(vm, VM::Error(static_cast<VM::ErrorID>(1077) /* eWriteOnlyError */, vm, si.Name->pData, _this),
                     fl::ReferenceErrorCI);
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
        ot = &vm.GetValueTraits(_this);
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

// The registry insert, inline here (the exe builds the key and calls HashSetBase::add 0x1423eb030 directly).
static SF_FORCEINLINE void Sfr18AddClassTraitsInline(TClassTraitsCache& set, const ASString& name,
                                                     const Instances::Namespace& ns, ClassTraits::Traits* const& v)
{
    set.Entries.Add(TClassTraitsCache::Key(name, &ns), v);
}

// A free function (not declared in the shared VM class). The name lives in its own block, so it shares the uri's
// slot (0x60) and the traits-pointer temporary goes to 0x68, as in the exe.
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
    {
        ASString name = tr.GetInstanceTraits().GetConstructor().GetTraits().GetName();
        Sfr18AddClassTraitsInline(vm.ClassTraitsSet, name, *ns, &tr);
    }
}

} } } // namespace Scaleform::GFx::AS3

static inline void FUN_142501b00(Scaleform::GFx::AS3::PropRef& result, Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& value, const Scaleform::GFx::AS3::Multiname& mn, int attr)
{ ::Scaleform::GFx::AS3::Sfr33FindObjProperty(result, vm, value, mn, attr); }   // FindObjProperty

namespace Scaleform { namespace GFx { namespace AS3 {

// GetPropertyUnsafe: the property prop_name of _this into value: by the object itself when it is array-like or an
// XML (list) instance, else by the found slot or dynamic value. False when there is none or it could not be read.
// MS2-FUNCTIONAL the exe loads prop.This's flags into a register once after the lookup and keeps them for the
// undefined test and the inlined ~PropRef; its false path stores the result at its own site
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
            ::new (ret) CheckResult(obj->GetProperty(prop_name, value));
            return ret;
        }
    }
    PropRef prop;
    FUN_142501b00(prop, vm, _this, prop_name, 0);
    const UPInt bits = reinterpret_cast<UPInt>(prop.pValue);
    bool r = false;
    if (!(prop.This.IsUndefined() || bits == 1 || (((UByte)(bits >> 1) & 1) && (bits & ~UPInt(2)) == 0)))
        r = prop.GetSlotValueUnsafe(vm, value);
    *ret = r;
    return ret;
}

class Tracer;
void FUN_1424e6cf0(Tracer* self, UPInt offset);   // the code position offset as the start of a block

// The starts of the byte code's blocks: the labels, the targets of the branches and the positions after them, and
// the targets of the lookupswitches (relative to their opcodes).
// @0x142516960
void FUN_142516960(void* self)
{
    struct View { char pad[0x50]; const UInt8* data; UPInt size; };
    const View* c   = static_cast<const View*>(self);
    UPInt       pos = 0;
    while (pos < c->size)
    {
        const int op = c->data[pos++];
        const Sfr34_OpCodeInfo& oi = DAT_14317fea0[op];
        if (oi.pop_mn)
            Abc::ReadU30(c->data, pos);
        if (oi.pop_args)
            Abc::ReadU30(c->data, pos);
        if (oi.pop_args | oi.pop_mn)
            continue;
        switch (op)
        {
        case 0x09:
            // label
            FUN_1424e6cf0(static_cast<Tracer*>(self), pos - 1);
            break;
        case 0x0c: case 0x0d: case 0x0e: case 0x0f: case 0x10: case 0x11: case 0x12: case 0x13:
        case 0x14: case 0x15: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
        {
            // the branches
            const int offset = Abc::ReadS24(c->data, pos);
            FUN_1424e6cf0(static_cast<Tracer*>(self), pos);
            FUN_1424e6cf0(static_cast<Tracer*>(self), pos + offset);
            break;
        }
        case 0x1b:
        {
            // lookupswitch: the default offset, the case count - 1 and the case offsets
            const UPInt base = pos - 1;
            FUN_1424e6cf0(static_cast<Tracer*>(self), base + Abc::ReadS24(c->data, pos));
            const int n = Abc::ReadU30(c->data, pos);
            for (int i = 0; i <= n; ++i)
                FUN_1424e6cf0(static_cast<Tracer*>(self), base + Abc::ReadS24(c->data, pos));
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
// The exe's WProxyHash.Get is the out-of-line word-keyed Hash::Get instance (0x1425058c0, sfr_as3_17).
bool Sfr33WordHashGet(const HashLH<UPInt, UPInt>& h, const UPInt& key, UPInt* pvalue);

// GASRefCountBase::CreateWeakProxy, inlined into MakeWeakRef by the exe.
static __forceinline WeakProxy* Sfr18CreateWeakProxy(GASRefCountBase* wb)
{
    GASRefCountBase::Collector* rcc = wb->GetCollector();
    WeakProxy*                  wp  = NULL;
    if (!Sfr33WordHashGet(reinterpret_cast<const HashLH<UPInt, UPInt>&>(rcc->WProxyHash),
                          reinterpret_cast<UPInt>(wb), reinterpret_cast<UPInt*>(&wp)))
    {
        wp = SF_HEAP_AUTO_NEW(wb) WeakProxy(wb);
        if (!wp)
            return NULL;
        *reinterpret_cast<UInt32*>(reinterpret_cast<UByte*>(wb) + 0x10) |= GASRefCountBase::Flag_HasWeakRef;
        // a named key of the hash's key type: the exe gives it its own slot (+0x58), apart from the Get key
        const ASRefCountBaseType* key = wb;
        rcc->WProxyHash.Add(key, wp);
    }
    wp->AddRef();
    return wp;
}

// MS2-FUNCTIONAL only register allocation differs (this/wb/zero in rbx/rdi/rsi, the exe's rdi/rsi/rbx)
// @0x142516720
bool Value::MakeWeakRef()
{
    bool rc = false;
    if (!IsWeakRef() && IsGarbageCollectable())
    {
        GASRefCountBase* wb;
        switch (GetKind())
        {
        case kNamespace:
            wb = value.VS._1.VNs;
            break;
        case kClass:
        case kFunction:
        case kThunkFunction:
        case kObject:
            wb = value.VS._1.VObj;
            break;
        case kThunkClosure:
        case kVTableIndClosure:
            wb = value.VS._2.VObj;
            break;
        default:
            wb = NULL;
            break;
        }
        if (wb)
        {
            WeakProxy* wp = Sfr18CreateWeakProxy(wb);
            Bonus.pWeakProxy = wp;
            Flags |= weakRefMask;
            ReleaseInternal();
            rc = true;
        }
    }
    return rc;
}

// CallFrame::GetCurrFileName / GetCurrLineNumber: by-value returns
static __forceinline ASString CallFrameFileName(const CallFrame& cf)
{
    return cf.pFile->GetInternedString(cf.CurrFileInd);
}

static __forceinline UInt32 CallFrameLineNumber(const CallFrame& cf)
{
    return cf.CurrLineNumber;
}

// The call stack as text, the innermost frame first, one per line: line_pref, "at " and the function's name with
// "()", then "[file:line]" when the frame has a source file.
// The call frames are read through a layout view of the VM's paged call stack (+0x78 size, +0x90 pages).
// @0x14250ec00
void VM::GetStackTraceASString(ASString& result, const char* line_pref)
{
    const UByte* self = reinterpret_cast<const UByte*>(this);
    const UPInt  size = *reinterpret_cast<const UPInt*>(self + 0x78);
    for (UPInt i = size, j = 0; i > 0; ++j, --i)
    {
        const UByte* const* pages = *reinterpret_cast<const UByte* const* const*>(self + 0x90);
        const CallFrame& cf = *reinterpret_cast<const CallFrame*>(pages[(i - 1) >> 6] + ((i - 1) & 0x3f) * 0xa8);
        if (j > 0)
            result += "\n";
        result += line_pref;
        result += "at ";
        result += ASString(cf.Name.GetPtr());
        result += "()";
        if (cf.CurrFileInd != 0)
        {
            result += "[";
            result += CallFrameFileName(cf);
            result += ":";
            result += Scaleform::AsString(CallFrameLineNumber(cf)).ToCStr();
            result += "]";
        }
    }
}

namespace fl { extern const ClassInfo FunctionCI; }

// VMAbcFile::GetFunctionInstanceTraits: the traits of the closures of method method_ind of the script gos, made on
// first use and cached by the file (+0x98) unless making them threw (the VM's no-function traits then).
// MS2-FUNCTIONAL free function over a layout view of the file's cache (VMAbcFile keeps it private); same length,
// the exe loads the table's size mask before hashing the index
// @0x14250a250
InstanceTraits::Traits& FUN_14250a250(VMAbcFile* file, Instances::fl::GlobalObjectScript& gos, UInt32 method_ind)
{
    typedef HashLH<UInt32, SPtr<InstanceTraits::Function>, FixedSizeHash<UInt32>, StatMV_VM_VMAbcFile_Mem> TCache;
    TCache& cache = *reinterpret_cast<TCache*>(reinterpret_cast<UByte*>(file) + 0x98);
    SPtr<InstanceTraits::Function>* p = cache.Get(method_ind);
    if (p == NULL)
    {
        VM&                        vm  = file->GetVM();
        InstanceTraits::Function*  itr = SF_HEAP_NEW(vm.GetMemoryHeap())
            InstanceTraits::Function(*file, fl::FunctionCI, method_ind, &gos);
        if (vm.IsException())
            return *vm.NoFunctionTraits;
        cache.Add(method_ind, Pickable<InstanceTraits::Function>(itr));
        return *itr;
    }
    return **p;
}


// The opcode of the byte code (of a tracer, at +0x50) from pos on that consumes the value on the stack top at pos:
// the stack depth is followed through the pops (with a run-time name's namespace and name, and the arguments; two
// per property of a newobject) and pushes, and through the jumps; the last opcode when the code ends first, a nop
// when pos is past the end.
// A free function over layout views of the tracer and its holder (the Tracer model is not ours)
// @0x14250c990
int FUN_14250c990(const void* self, UPInt pos)
{
    struct Holder { char pad[0x28]; const VMAbcFile* file; };
    struct View { char pad[0x20]; const Holder* holder; char pad2[0x28]; const UInt8* data; UPInt size; };
    const View* c     = static_cast<const View*>(self);
    int         op    = 0x02;
    int         depth = 1;
    while (pos < c->size)
    {
        op = c->data[pos++];
        if (op == 0x10)
        {
            // jump
            const int off = Abc::ReadS24(c->data, pos);
            pos += off;
            continue;
        }
        {
            const Sfr34_OpCodeInfo& oi = DAT_14317fea0[op];
            depth -= oi.pop;
            if (oi.pop_mn)
            {
                const int ind = Abc::ReadU30(c->data, pos);
                switch (c->holder->file->GetAbcFile().Const_Pool.GetMultiname(ind).Kind)
                {
                case Abc::MNF_RTQName:
                case Abc::MNF_RTQNameA:
                    depth -= 1;
                    break;
                case Abc::MNF_RTQNameL:
                case Abc::MNF_RTQNameLA:
                    depth -= 2;
                    break;
                case Abc::MNF_MultinameL:
                case Abc::MNF_MultinameLA:
                    depth -= 1;
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
            if (depth > 0)
                depth += DAT_14317fea0[op].push;
            else
                break;
            if (oi.pop_args | oi.pop_mn)
                continue;
        }
        switch (op)
        {
        case 0x0c: case 0x0d: case 0x0e: case 0x0f: case 0x10: case 0x11: case 0x12: case 0x13: case 0x14:
        case 0x15: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
            // the branches
            Abc::ReadS24(c->data, pos);
            break;
        case 0x1b:
        {
            // lookupswitch
            Abc::ReadS24(c->data, pos);
            const int n = Abc::ReadU30(c->data, pos);
            for (int i = 0; i <= n; ++i)
                Abc::ReadS24(c->data, pos);
            break;
        }
        case 0x24:
            // pushbyte
            ++pos;
            break;
        case 0xef:
            // debug
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
        }
    }
    return op;
}

} } } // namespace Scaleform::GFx::AS3

static inline void FUN_1424ef180(void* reader, const Scaleform::GFx::AS3::Value& v) { ::Scaleform::GFx::AS3::Sfr33CheckObject(static_cast<Scaleform::GFx::AS3::VM* const*>(reader), v); }    // StackReader::CheckObject
static inline void FUN_142528d20(Scaleform::GFx::AS3::Multiname* mn, const Scaleform::GFx::AS3::Instances::Namespace* ns) { ::Scaleform::GFx::AS3::Sfr31SetGcRefClearFlags(reinterpret_cast<unsigned long*>(mn), reinterpret_cast<Scaleform::UPInt>(ns)); }   // Multiname::SetRTNamespace

// StackReader::Read(Multiname&): the run-time parts of a multiname off the operand stack: the name (of the late
// kinds), then the namespace (of the run-time qualified ones; an error unless it is an object). ctx is the reader
// {VM*, operand stack*}.
// MS2-FUNCTIONAL free function in the callers' (sfr_as3_19) form; StackReader is not in the shared headers. In the inlined
// weak release of the popped value, the exe clears the flags after the three zero stores, ours before them
// @0x1425201f0
void FUN_1425201f0(void* ctx, void* multiname)
{
    using namespace Scaleform::GFx::AS3;
    struct Reader { VM* vm; ValueStack* stack; };
    Reader*    r  = static_cast<Reader*>(ctx);
    Multiname& mn = *static_cast<Multiname*>(multiname);
    for (;;)
    {
        switch (static_cast<int>(mn.Kind))
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
            FUN_142528d20(&mn, &r->stack->GetTopPtr()->AsNamespace());
            ValueStack* st = r->stack;
            st->GetTopPtr()->~Value();
            st->Release(1);
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
// The set is built over a layout view (its constructor and virtuals are not in the shared header).
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
    if (IntNamespaceSets[ind].GetPtr() == NULL)
    {
        View* v = static_cast<View*>(SF_HEAP_ALLOC(GetVM().GetMemoryHeap(), sizeof(View), StatMV_ActionScript_Mem));
        if (v)
        {
            ASRefCountCollector* gc = &GetVM().GetGC();
            v->vptr     = &DAT_14317b058;
            v->gc       = gc;
            v->RefCount = 1;
            ::new (&v->Namespaces) ArrayLH<SPtr<Instances::Namespace> >();
        }
        else
            v = NULL;
        NamespaceSet* set = reinterpret_cast<NamespaceSet*>(v);
        IntNamespaceSets[ind] = Pickable<NamespaceSet>(set);
        const UInt8* data = GetAbcFile().Const_Pool.const_ns_set[ind].Data;
        const UInt32 n    = Abc::ReadU30(data);
        for (UInt32 i = 0; i < n; ++i)
        {
            const UInt32 ns_ind = Abc::ReadU30(data);
            v->Namespaces.PushBack(SPtr<Instances::Namespace>(&GetInternedNamespace(ns_ind)));
        }
    }
    return *IntNamespaceSets[ind];
}

CheckResult ExecutePropertyUnsafe(VM& vm, const Multiname& prop_name, const Value& _this, Value& result, unsigned argc,
                                  const Value* argv);   // 0x1424ff910

// Multiname::PostProcessName(false) (0x14251cef0) as the exe inlines it into OutputError: its own body, the three
// renames sharing one assignment.
static __forceinline void Sfr18PostProcessNameShared(Multiname& mn)
{
    if (!mn.Name.IsString())
        return;
    ASString n = mn.Name.AsString();
    if (n.GetSize() != 0)
    {
        ASStringManager* const mgr = n.GetManager();
        ASStringNode* node;
        if (n[0] != '*')
        {
            if (n[0] != '@')
                return;
            mn.Kind = static_cast<Abc::MultinameKind>(mn.Kind | 8);
            if (n.GetSize() != 2 || n[1] != '*')
            {
                node = n.SubstringNode(1, n.GetSize());
                node->AddRef();
                goto assign;
            }
        }
        // "*" and "@*": the empty name.
        node = mgr->GetEmptyStringNode();
        node->AddRef();
    assign:
        // The temporary ASString of the assignment, released through the node (the exe sees operator='s body
        // and keeps the node in a register across it).
        ASStringNode* const tmp = node;
        FUN_1424e0d40(mn.Name, reinterpret_cast<const ASString&>(tmp));
        node->Release();
    }
}

// Multiname(Namespace&, const Value&) (0x1424d8a90) as the exe inlines it into OutputError (other units define
// their own copies of this declaration).
__forceinline Multiname::Multiname(Instances::Namespace& ns, const Value& name, InlineCtorTag)
    : Kind(static_cast<Abc::MultinameKind>(0))
    , Obj(&ns)
{
    const UInt32 k = static_cast<UInt32>(name.GetKind());
    if (k - 0xc <= 3 && name.GetGASRefCountBase() != NULL)
    {
        const Traits& tr = reinterpret_cast<Object*>(name.GetGASRefCountBase())->GetTraits();
        if (static_cast<int>(tr.TraitsType) == 0xc && (static_cast<UInt8>(~static_cast<UInt8>(static_cast<UInt8>(tr.Flags) >> 5)) & 1) != 0)
        {
            Sfr27MultinameFromQName(this, &name);
            return;
        }
    }
    ValueAssignCopies::AssignFreshInline18(Name, name);
    Sfr18PostProcessNameShared(*this);
}

// The error e as text through the UI: its getStackTrace() when it has one, else (or when that gives null) e
// converted to a string.
// The Multiname constructor (with PostProcessName) and the string Value are inlined, as in the exe.
// MS2-FUNCTIONAL the exe keeps the name Value's flags and bonus in registers across the QName call (its LTCG sees
// that the callee does not write it; ours reloads them), one AddRef arm of the name copy that cl threads, and
// register allocation
// @0x14251bdc0
void VM::OutputError(const Value& e)
{
    Value          result;
    ASString       msg = GetStringManager().CreateEmptyString();
    const Multiname mn(GetPublicNamespace(), Value(GetStringManager().CreateConstString("getStackTrace"), Value::InlineStr),
                       Multiname::InlineCtorTag());
    if (e.IsNullOrUndefined() || !ExecutePropertyUnsafe(*this, mn, e, result, 0, NULL) || result.Convert2String(msg))
    {
        if ((!e.IsNullOrUndefined() && msg.GetNode() != GetStringManager().GetBuiltin(AS3Builtin_null).GetNode()) || e.Convert2String(msg))
            GetUI().Output(FlashUI::Output_Error, msg.ToCStr());
    }
}


// VMAbcFile::RegisterScrips: the traits and global object of each script of the file; the global objects are listed
// in the VM (unowned) and kept in the file's set, and the last script is run when to_execute.
// The VM's global object list and the file's set are reached through casts (the shared header models them as an
// SPtr array and a raw table pointer). The instance traits are assigned to an empty SPtr (Pick), which gives the
// exe's null test of the new object (cmovne).
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
        SPtr<InstanceTraits::fl::GlobalObjectScript> itr;
        itr = Pickable<InstanceTraits::fl::GlobalObjectScript>(
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

static inline void FUN_142530de0(VMAbcFile* file) { ::Scaleform::GFx::AS3::Sfr31UnregisterClassTraits(reinterpret_cast<Scaleform::UPInt>(file)); }   // VMAbcFile: the loaded classes' traits unregistered (a failed load)

// ArrayData::PushBack with the exe's out-of-line ResizeNoConstruct (a member pointer call; cl otherwise inlines it).
template <class T, class Alloc>
static __forceinline void Sfr18PushBackOutResize(Scaleform::ArrayBase<Scaleform::ArrayData<T, Alloc, ArrayDefaultPolicy> >& a, const T& val)
{
    typedef ArrayDataBase<T, Alloc, ArrayDefaultPolicy> Base;
    Base& d = reinterpret_cast<Base&>(a);
    (d.*&Base::ResizeNoConstruct)(&d, d.Size + 1);
    Alloc::Construct(d.Data + d.Size - 1, val);
}

// VM::Resolve2ClassTraits(name, ns), inline here as in the exe: the cache, then the global object's classes (cached).
static SF_FORCEINLINE ClassTraits::Traits* Sfr18Resolve2CT(VM& vm, const ASString& name, Instances::Namespace& ns)
{
    ClassTraits::Traits** found = FUN_142414ac0(&vm.ClassTraitsSet, name, ns);
    if (found != NULL && *found != NULL)
        return *found;
    ClassTraits::Traits* ct = FUN_142415520(vm.GlobalObject.GetPtr(), name, ns);
    ClassTraits::Traits* added = ct;
    if (ct != NULL)
        vm.ClassTraitsSet.Add(name, ns, added);
    return ct;
}

// VMAbcFile::RegisterUserDefinedClassTraits: the class traits of the file's classes (except the scaleform.gfx
// package's): ones known to the VM (cached, or from the global object, then cached) only add their file to the
// children; the others are made, cached and kept as loaded classes. Then the new ones are initialized; on a failure
// the error is output, the class uncached, the loaded classes unregistered and false returned.
// MS2-FUNCTIONAL SDK statement structure (resolve helper, if/else, uninitialize tail, SDK return: no class made with classes present = false); left: the exe frame is 0x10 smaller (mov rbp,rsp), it places the found-class Children block inline, and register numbering. FUN_14250f9a0 is noinline, and Hash::Remove / ResizeNoConstruct are called out of line as in the exe
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
        if (FUN_142514cd0(ns))
            continue;
        ClassTraits::Traits* ctr = Sfr18Resolve2CT(vm, name, ns);
        if (ctr == NULL)
        {
            SPtr<ClassTraits::Traits> ud = Pickable<ClassTraits::Traits>(
                SF_HEAP_NEW(vm.GetMemoryHeap()) ClassTraits::UserDefined(*this, vm, ci));
            vm.ClassTraitsSet.Add(name, ns, ud.GetPtr());
            ++made;
            Sfr18PushBackOutResize(LoadedClasses, ud);
        }
        else
        {
            VMAbcFile* f = ctr->GetFilePtr();
            if (f)
            {
                UPInt j = 0;
                while (j < Children.GetSize() && Children[j].GetPtr() != f)
                    ++j;
                if (j == Children.GetSize())
                    Sfr18PushBackOutResize(Children, SPtr<VMAbcFile>(f));
            }
        }
    }
    if (made == 0 && classes.Info.GetSize() != 0)
        return false;
    bool uninitialize = false;
    for (UPInt i = 0; i < classes.Info.GetSize(); ++i)
    {
        const Abc::ClassInfo& ci   = *classes.Info[i];
        const Abc::Multiname& mn   = GetAbcFile().Const_Pool.GetMultiname(ci.inst_info.name_ind);
        const ASString        name = GetInternedString(mn.NameIndex);
        Instances::Namespace& ns   = GetInternedNamespace(mn.Ind);
        if (FUN_142514cd0(ns))
            continue;
        ClassTraits::Traits* ctr = FUN_14250f9a0(vm, *this, ci);
        if (&static_cast<ClassTraits::UserDefined*>(ctr)->GetFile() != this)
            continue;
        if (!ctr->FUN_142418970())
        {
            if (vm.HandleException)
            {
                vm.HandleException = false;
                vm.OutputError(vm.ExceptionObj);
                vm.ExceptionObj.SetUndefined();
            }
            typedef HashDH<TClassTraitsCache::Key, ClassTraits::Traits*, TClassTraitsCache::Key::HashFunctor, 329>::BaseType CacheHash;
            (reinterpret_cast<CacheHash&>(vm.ClassTraitsSet.Entries).*&CacheHash::Remove)(TClassTraitsCache::Key(name, &ns));
            --made;
            uninitialize = true;
            break;
        }
    }
    if (uninitialize)
    {
        FUN_142530de0(this);
        return false;
    }
    return classes.Info.GetSize() == 0 || made != 0;
}

// sfr34 batch AD: the link, mouse and character events of an AS3 text field (AvmTextFieldBase slots 25..27).

// The document of a text field's DocView (+0x10), its URL flag (RTFlags +0x40 bit 0), the formats at a position and
// the character at a point, bound to the exe (the text headers do not fit this unit's partial models).
static inline void* Sfr34_StyledTextOf(Render::Text::DocView* doc)
{
    return *reinterpret_cast<void**>(reinterpret_cast<char*>(doc) + 0x10);
}
static inline bool Sfr34_MayHaveUrl(Render::Text::DocView* doc)
{
    return (*(static_cast<const UInt8*>(Sfr34_StyledTextOf(doc)) + 0x40) & 1) != 0;
}

// The text field an AvmTextField is the AVM part of.
static inline TextField* Sfr34_TextFieldOf(const AvmDisplayObj* avm)
{
    return reinterpret_cast<TextField*>(avm->pDispObj);
}

// AvmTextField::OnLinkEventEx: with the extensions on, the rolling over (or out of) a link gives a
// "linkMouseOver" ("linkMouseOut") TextEventEx with the link's URL to the AS3 object when it listens for it.
// MS2-FUNCTIONAL scheduling only: the instructions match the exe (MS2_AS3_CONSTRUCT_NOALIAS), but the event's
// Value-array stores and the [rcx+8]/0x350 loads come in another order
// @0x14251a500
void AvmTextField::OnLinkEventEx(TextField::LinkEvent event, unsigned pos, unsigned controllerIndex)
{
    Sfr34_CheckAvm(AS3RootOf(pDispObj));
    if (AS3RootOf(pDispObj)->pAVM->ExtensionsEnabled)
    {
        TextField*                      ptf = Sfr34_TextFieldOf(this);
        const Render::Text::TextFormat* fmt;
        if (static_cast<Render::Text::StyledText*>(Sfr34_StyledTextOf(ptf->GetDocument()))->GetTextAndParagraphFormat(&fmt, NULL, pos))
        {
            if (fmt->IsUrlSet())
            {
                const char* url  = fmt->GetUrl().ToCStr();
                const char* type = NULL;
                switch (event)
                {
                case TextField::Link_rollover: type = "linkMouseOver"; break;
                case TextField::Link_rollout:  type = "linkMouseOut";  break;
                default: return;
                }
                const ASString name(AS3RootOf(pDispObj)->BuiltinsMgr.GetStringManager()->CreateStringNode(type));
                Instances::fl_display::DisplayObject* as3obj = GetAS3Obj();
                if (as3obj->WillTrigger(name, false))
                {
                    SPtr<Instances::fl_gfx::TextEventEx> evt;
                    Value params[] = { Value(name, Value::InlineStr), Value(true), Value(true) };
                    ASVM* asvm = AS3RootOf(pDispObj)->pAVM;
                    asvm->ConstructInstance(evt, asvm->TextEventExClass, 3, params);
                    Instances::fl_gfx::TextEventEx* e = evt.GetPtr();
                    e->Target = as3obj;
                    e->Text = ASString(AS3RootOf(pDispObj)->BuiltinsMgr.GetStringManager()->CreateStringNode(url));
                    e->controllerIdx = controllerIndex;
                    as3obj->DispatchEventObject(e, pDispObj);
                }
            }
        }
    }
}


// AvmTextField::OnMouseEvent: a click (not ending a selection) on an "event:" link of an HTML field gives a "link"
// TextEvent with the rest of the URL to the AS3 object when it listens for it; true for any click.
// MS2-FUNCTIONAL scheduling only: the instructions match the exe (MS2_AS3_CONSTRUCT_NOALIAS), but the event's
// Value-array stores and the [rcx+8]/0x20 loads come in another order
// @0x14251a8a0
bool AvmTextField::OnMouseEvent(const EventId& event)
{
    AvmInteractiveObj::OnEvent(event);
    if (event.Id == AS3Event_Click)
    {
        TextField* ptf = Sfr34_TextFieldOf(this);
        if (ptf->GetBeginIndex() != ptf->GetEndIndex())
            return false;
        if (ptf->IsHtml() && Sfr34_MayHaveUrl(ptf->GetDocument()))
        {
            Render::PointF p(Render::PointF::NoInit);
            if (ptf->IsUrlUnderMouseCursor(event.MouseIndex, &p))
            {
                UPInt pos = ptf->GetDocument()->GetCharIndexAtPoint(p.x, p.y);
                if (pos != SF_MAX_UPINT)
                {
                    const Render::Text::TextFormat* fmt;
                    if (static_cast<Render::Text::StyledText*>(Sfr34_StyledTextOf(ptf->GetDocument()))->GetTextAndParagraphFormat(&fmt, NULL, pos))
                    {
                        if (fmt->IsUrlSet())
                        {
                            const char* url = fmt->GetUrl().ToCStr();
                            if (GetMovieImpl() && String::CompareNoCase(url, "event:", 6) == 0)
                            {
                                url += 6;
                                const ASString name(AS3RootOf(pDispObj)->BuiltinsMgr.GetStringManager()->CreateStringNode("link"));
                                Instances::fl_display::DisplayObject* as3obj = GetAS3Obj();
                                if (as3obj->WillTrigger(name, false))
                                {
                                    SPtr<Instances::fl_events::TextEvent> evt;
                                    Value params[] = { Value(name, Value::InlineStr), Value(true), Value(true) };
                                    ASVM* asvm = AS3RootOf(pDispObj)->pAVM;
                                    asvm->ConstructInstance(evt, asvm->ExtensionsEnabled ? asvm->TextEventExClass : asvm->TextEventClass, 3, params);
                                    Instances::fl_events::TextEvent* e = evt.GetPtr();
                                    e->Target = as3obj;
                                    e->Text = ASString(AS3RootOf(pDispObj)->BuiltinsMgr.GetStringManager()->CreateStringNode(url));
                                    if (asvm->ExtensionsEnabled)
                                    {
                                        Instances::fl_gfx::TextEventEx* ex = static_cast<Instances::fl_gfx::TextEventEx*>(e);
                                        ex->controllerIdx = event.ControllerIndex;
                                        ex->buttonIdx     = event.ButtonId;
                                    }
                                    as3obj->DispatchEventObject(e, pDispObj);
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
    return false;
}

// AvmTextField::OnCharEvent: a "textInput" TextEvent of the character to the AS3 object when it listens for it;
// false when the event's default action was prevented.
// MS2-FUNCTIONAL scheduling only: the instructions match the exe (MS2_AS3_CONSTRUCT_NOALIAS), but params[0]'s stores
// come after the evt init in ours, and the 0x350/3/0x348 loads interleave differently with params[1..2]
// @0x142518750
bool AvmTextField::OnCharEvent(wchar_t wcharCode, unsigned controllerIdx)
{
    bool rv = true;
    const ASString&                       name   = AS3RootOf(pDispObj)->BuiltinsMgr.GetBuiltin(AS3Builtin_textInput);
    Instances::fl_display::DisplayObject* as3obj = GetAS3Obj();
    if (as3obj->WillTrigger(name, false))
    {
        SPtr<Instances::fl_events::TextEvent> evt;
        Value params[] = { Value(name, Value::InlineStr), Value(true), Value(true) };
        ASVM* asvm = AS3RootOf(pDispObj)->pAVM;
        asvm->ConstructInstance(evt, asvm->ExtensionsEnabled ? asvm->TextEventExClass : asvm->TextEventClass, 3, params);
        Instances::fl_events::TextEvent* e = evt.GetPtr();
        e->Target = as3obj;
        e->SetText(wcharCode);
        if (asvm->ExtensionsEnabled)
            static_cast<Instances::fl_gfx::TextEventEx*>(e)->controllerIdx = controllerIdx;
        rv = as3obj->DispatchEventObject(e, pDispObj);
    }
    return rv;
}

// sfr34 batch AE: the firing of an interval timer.

} } } // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace GFx { namespace AS3 {

// Once its invoke time is reached: a Timer's event (while under its repeat count) or the setInterval function
// (an exception printed and dropped); then the timer stops (a timeout, or the repeat count reached) or its next
// invoke time is a whole number of intervals (at least a tenth of the frame) past the current one.
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
            // GetNextInterval, inline here
            const auto nextInterval = [this](UInt64 currentTime, UInt64 frameTime) -> UInt64 {
                if (RepeatCount != 0 && CurrentCount >= RepeatCount)
                    return 0;
                UInt64 interval;
                if (Interval < frameTime / 10)
                    interval = unsigned(frameTime / 10);
                else
                    interval = Interval;
                if (interval == 0)
                    return 0;
                return (((currentTime - InvokeTime) + interval) / interval) * interval;
            };
            UInt64 interval = nextInterval(currentTime, UInt64(frameTime * 1000000.f));
            if (interval > 0)
                InvokeTime += interval;
            else
                InvokeTime = currentTime;
        }
        retval = true;
    }
    return retval;
}

} } } // namespace Scaleform::GFx::AS3

// (forwarder above)   // FindObjProperty

namespace Scaleform { namespace GFx { namespace AS3 {

// Value(this) whose release is known to be a strong object's: the exe's LTCG knows FindObjProperty leaves it
// alone, so its dtor is a bare ReleaseInternal call.
struct Sfr18SelfValue
{
    union { Value V; };
    explicit Sfr18SelfValue(Object* p) { ValueAssignCopies::InitObjectInline18(V, p); }
    // Value(Object*) with its null test (the exe's FUN_14250dd20).
    struct NullTested {};
    Sfr18SelfValue(Object* p, NullTested)
    { ValueAssignCopies::InitObjectNullInline18(V, p); }
    ~Sfr18SelfValue() { ValueAssignCopies::ReleaseStrongInline18(V); }
};

// Multiname::PostProcessName(false) (0x14251cef0) as the exe inlines it into FUN_14250dd20.
static __forceinline void Sfr18PostProcessName(Multiname& mn)
{
    if (!mn.Name.IsString())
        return;
    ASString n = mn.Name.AsString();
    if (n.GetSize() != 0)
    {
        ASStringManager* const mgr = n.GetManager();
        ASStringNode* node;
        if (n[0] != '*')
        {
            if (n[0] != '@') goto done;
            mn.Kind = static_cast<Abc::MultinameKind>(mn.Kind | 8);
            if (n.GetSize() != 2 || n[1] != '*')
            { node = n.SubstringNode(1, n.GetSize()); node->AddRef(); goto assign; }
        }
        node = mgr->GetEmptyStringNode();
        node->AddRef();
    assign:
        ASStringNode* const tmp = node;
        FUN_1424e0d40(mn.Name, reinterpret_cast<const ASString&>(tmp));
        node->Release();
    }
done:;
}

// Multiname(Namespace&, const Value&) (0x1424d8a90) with Value::AssignUnsafe inlined, as FUN_14250dd20 has it
// (the same declaration sfr_as3_17d defines for FireEvent; this unit's copy inlines its own PostProcessName).
__forceinline Multiname::Multiname(Instances::Namespace& ns, const Value& name, InlineAssignTag)
    : Kind(static_cast<Abc::MultinameKind>(0))
    , Obj(&ns)
{
    const UInt32 k = static_cast<UInt32>(name.GetKind());
    if (k - 0xc <= 3 && name.GetGASRefCountBase() != NULL)
    {
        const Traits& tr = reinterpret_cast<Object*>(name.GetGASRefCountBase())->GetTraits();
        if (static_cast<int>(tr.TraitsType) == 0xc && (static_cast<UInt8>(~static_cast<UInt8>(static_cast<UInt8>(tr.Flags) >> 5)) & 1) != 0)
        {
            Sfr27MultinameFromQName(this, &name);
            return;
        }
    }
    ValueAssignCopies::AssignFreshInline18(Name, name);
    Sfr18PostProcessName(*this);
}

// The property prop_name of this object (its slot or dynamic value, getters run) swapped into value; false when
// there is none or it could not be read.
// MS2-FUNCTIONAL scheduling only: PropRef::GetSlotValueUnsafe written out (the exe inlines it); the case-1 Value copy
// loads both halves before storing them, the exe stores the first half before loading the second
// @0x14250cc60
CheckResult Object::GetProperty(const Multiname& prop_name, Value& value)
{
    VM&     vm = GetVM();
    PropRef prop;
    {
        Sfr18SelfValue self(this);
        FUN_142501b00(prop, vm, self.V, prop_name, 0);
    }
    const UPInt bits = reinterpret_cast<UPInt>(prop.pValue);
    if (!(prop.This.IsUndefined() || bits == 1 || (((UByte)(bits >> 1) & 1) && (bits & ~UPInt(2)) == 0)))
    {
        Value v;
        bool  result = true;
        switch (bits & 3)
        {
        case 0:
        {
            UByte r;   // written by the slot reader
            result = *FUN_14250e2d0(prop.pSI, &r, &vm, &v, &prop.This, NULL, 0);
            break;
        }
        case 1:
            ValueAssignCopies::AssignUnsafeValueInline18(v, *reinterpret_cast<const Value*>(bits & ~UPInt(1)));
            break;
        case 2:
            ValueAssignCopies::AssignUnsafeInline18(v, Value::kObject, reinterpret_cast<Object*>(bits & ~UPInt(2)));
            break;
        default:
            break;
        }
        if (result)
        {
            Sfr18ValueSwap::Swap(value, v);
            return true;
        }
    }
    return false;
}

} } } // namespace Scaleform::GFx::AS3

// Object::GetProperty(name, ns, value): the property name of namespace ns (FindObjProperty, then its value read
// into value, getters run); false when there is none or it could not be read.
// MS2-FUNCTIONAL free function returning its CheckResult through ret, as sfr_as3_17 declares it. The Multiname ctor,
// Value(ASString), PostProcessName and the slot read are inlined as in the exe; left: regalloc (the exe keeps the
// name Value's flags and bonus in registers across Sfr27MultinameFromQName (LTCG; ours reloads them from the frame),
// saves r12/r15 and shrink-wraps rbx). PostProcessName's tail now matches (single exit, shared n release).
// @0x14250dd20
Scaleform::UByte* FUN_14250dd20(Scaleform::GFx::AS3::Object* self, Scaleform::UByte* ret,
                                const Scaleform::GFx::ASString* name, Scaleform::GFx::AS3::Instances::Namespace* ns,
                                Scaleform::GFx::AS3::Value* value)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    PropRef prop;
    {
        const Value     nv(*name, Value::InlineStr);
        const Multiname mn(*ns, nv, Multiname::InlineAssignTag());
        Sfr18SelfValue  sv(self, Sfr18SelfValue::NullTested());
        FUN_142501b00(prop, self->GetVM(), sv.V, mn, 0);
    }
    const UPInt bits = reinterpret_cast<UPInt>(prop.pValue);
    if (prop.This.IsUndefined() || bits == 1 || (((UByte)(bits >> 1) & 1) && (bits & ~UPInt(2)) == 0))
    {
        *ret = false;
        return ret;
    }
    VM& vm = self->GetVM();
    switch (bits & 3)
    {
    case 0:
    {
        UByte r;   // written by the slot reader
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
        ValueAssignCopies::AssignUnsafeInline18(*value, Value::kObject, reinterpret_cast<Object*>(bits & ~UPInt(2)));
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
    const AbsoluteIndex vind(si.ValueInd);
    switch (si.BindType)
    {
    case SlotInfo::BT_ValueArray:
        value.AssignUnsafe(reinterpret_cast<const Value*>(*reinterpret_cast<const UPInt*>(reinterpret_cast<UPInt>(obj) + 0xa8))[UInt32(vind.Get())]);
        break;
    case SlotInfo::BT_Value:
        value.AssignUnsafe(*reinterpret_cast<const Value*>(reinterpret_cast<UPInt>(obj) + UInt32(vind.Get())));
        break;
    case SlotInfo::BT_ObjectAS:
        reinterpret_cast<STPtr*>(reinterpret_cast<UPInt>(obj) + UInt32(vind.Get()))->GetValueUnsafe(value);
        break;
    case SlotInfo::BT_ObjectCpp:
        value.AssignUnsafe(*reinterpret_cast<const SPtr<Instances::fl::GlobalObjectCPP>*>(reinterpret_cast<UPInt>(obj) + UInt32(vind.Get())));
        break;
    case SlotInfo::BT_Boolean:
        value.SetBoolUnsafe(*reinterpret_cast<const bool*>(reinterpret_cast<UPInt>(obj) + UInt32(vind.Get())));
        break;
    case SlotInfo::BT_Int:
        value.SetSInt32Unsafe(*reinterpret_cast<const SInt32*>(reinterpret_cast<UPInt>(obj) + UInt32(vind.Get())));
        break;
    case SlotInfo::BT_UInt:
        value.SetUInt32Unsafe(*reinterpret_cast<const UInt32*>(reinterpret_cast<UPInt>(obj) + UInt32(vind.Get())));
        break;
    case SlotInfo::BT_Number:
        value.SetNumberUnsafe(*reinterpret_cast<const Value::Number*>(reinterpret_cast<UPInt>(obj) + UInt32(vind.Get())));
        break;
    case SlotInfo::BT_String:
        if (GFx::ASStringNode* node = *reinterpret_cast<GFx::ASStringNode* const*>(reinterpret_cast<UPInt>(obj) + UInt32(vind.Get())))
            value.AssignUnsafe(node);
        else
            value.SetNullUnsafe();   // null is an object, not a string
        break;
    case 10:   // a constant C string (4.1.18 numbers this binding before BT_Code)
        ValueAssignCopies::AssignUnsafeStrInline18(value, obj->GetVM().GetStringManager().CreateConstString(
            *reinterpret_cast<const char* const*>(reinterpret_cast<UPInt>(obj) + UInt32(vind.Get()))));
        break;
    case SlotInfo::BT_Code:
        FUN_14250ba10(&obj->GetTraits().GetVT(), value, vind, obj);
        break;
    case SlotInfo::BT_Get:
    case SlotInfo::BT_GetSet:
    {
        const Value getter = obj->GetTraits().GetVT().GetValue(vind);
        VM&         vm     = obj->GetVM();
        if (getter.IsCallable())
            vm.ExecuteInternalUnsafe(getter, Value(obj), value, 0, NULL, false);
        else
        {
            TrThrowError(vm, VM::Error(VM::eCallOfNonFunctionError, vm, obj->GetTraits().GetName().ToCStr()),
                         fl::TypeErrorCI);
            *r = false;
            return r;
        }
        break;
    }
    case SlotInfo::BT_Set:
    {
        VM& vm = obj->GetVM();
        TrThrowError(vm, VM::Error(static_cast<VM::ErrorID>(1077) /* eWriteOnlyError */, vm, si.Name->pData,
                                   obj->GetTraits().GetName().ToCStr()),
                     fl::ReferenceErrorCI);
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

} // namespace AS3

// ObjectInterface::GetMember: the public property name of the AS3 object; for a display object container without
// such a property, its child of that name. undefined (and false) when neither is there; an exception of the
// property lookup is output (of the child lookup, dropped).
// The Multiname ctor and the string Value are the inline copies (InlineCtorTag, Value::InlineStr), and the
// failure paths are inside if (!GetProperty), as in the SDK.
// MS2-FUNCTIONAL: the exe inlines AvmDisplayObjContainer::GetAS3ChildByName and saves all registers in the
// prolog; the name Value's QName-call reload (LTCG)
// @0x14250b4a0
bool AS3ValueObjectInterface::GetMember(void* pdata, const char* name, GFx::Value* pval, bool isdobj) const
{
    using namespace AS3;
    using AS3::Value;
    SF_UNUSED(isdobj);
    MovieRoot* root = Sfr34_RootOf(pMovieRoot);
    VM*        vm   = root->pAVM;
    Object*    obj  = static_cast<Object*>(pdata);
    const Multiname mn(vm->GetPublicNamespace(), Value(ASString(root->BuiltinsMgr.GetStringManager()->CreateStringNode(name)), Value::InlineStr),
                       Multiname::InlineCtorTag());
    Value asval;
    if (!obj->GetProperty(mn, asval))
    {
        const Traits& tr = obj->GetTraits();
        if ((unsigned)(tr.GetTraitsType() - Traits_DisplayObjectContainer) <
                (unsigned)(Traits_DisplayObject_End - Traits_DisplayObjectContainer) &&
            tr.IsInstanceTraits())
        {
            DisplayObject*          dobj  = Sfr34_DispObjOf(pdata);
            AvmDisplayObjContainer* pcurr = Sfr34_ToAvmContainer(dobj->IsDisplayObjContainer() ? dobj : NULL);
            const ASString propName(root->BuiltinsMgr.GetStringManager()->CreateStringNode(name));
            SPtr<Instances::fl_display::DisplayObject> pchild = pcurr->GetAS3ChildByName(propName);
            if (pchild)
            {
                asval = Value(pchild);
                root->ASValue2GFxValue(asval, pval);
                return true;
            }
            else
            {
                if (vm->IsException())
                    vm->HandleException = false;
                pval->SetUndefined();
                return false;
            }
        }
        if (vm->IsException())
            vm->OutputAndIgnoreException();
        pval->SetUndefined();
        return false;
    }
    root->ASValue2GFxValue(asval, pval);
    return true;
}

namespace AS3 {

// DisplayObjectBase::GetWorldMatrix() by value (the SDK's inline over the out-parameter form).
static inline Render::Matrix2F Sfr18GetWorldMatrix(const DisplayObjectBase* pobj)
{
    Render::Matrix2F m;
    pobj->GetWorldMatrix(&m);
    return m;
}

// The scriptable visible children under pt (topmost first), each in its own coordinates; none when the
// container is invisible or pt is outside its mask. True when any was added.
// MS2-FUNCTIONAL the exe's frame is 0x10 smaller and saves no xmm13 (register allocation in the inlined SetInverse/Prepend)
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
            Render::Matrix2F matrix;
            matrix.SetInverse(Sfr18GetWorldMatrix(pmask));
            matrix.Prepend(Sfr18GetWorldMatrix(dobjParent));   // operator*=
            const Render::PointF p = matrix.Transform(pt);
            if (!pmask->PointTestLocal(p, DisplayObjectBase::HitTest_TestShape | DisplayObjectBase::HitTest_IgnoreInvisible))
                return false;
        }
    }
    Array<UByte> hitTest;
    dobjParent->CalcDisplayListHitTestMaskArray(&hitTest, pt, true);
    Render::Matrix2F m;
    Render::PointF   p     = pt;
    const UPInt      oldSz = destArray->GetSize();
    for (SPInt i = n - 1; i >= 0; i--)
    {
        DisplayObjectBase* pch = dl.GetDisplayObject(UPInt(i));
        if (!pch->IsScriptableObject() || !pch->GetVisible())
            continue;
        if (hitTest.GetSize() && (!hitTest[UPInt(i)] || pch->ClipDepth > 0))
            continue;
        m = pch->GetMatrix();
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
static SF_FORCEINLINE void Sfr34_ResizeStringArray(MovieImpl::ReturnValueHolder* h, unsigned n)
{
    h->StringArray.Resize(Alg::Max(1u, n));
}

// GFx::Value::SetUndefined expanded in place, as the exe does in GetVariableArray (the release and the type are
// protected, hence the derived view).
struct Sfr34_GfxValueView : GFx::Value
{
    static SF_FORCEINLINE void SetUndefined(GFx::Value* v)
    {
        Sfr34_GfxValueView* p = static_cast<Sfr34_GfxValueView*>(v);
        if (p->IsManagedValue())
            p->ReleaseManagedValue();
        p->Type = VT_Undefined;
    }
};

} } } // namespace Scaleform::GFx::AS3

// The path lookup does not keep the value's address (the exe has it in this TU)
__declspec(noalias) bool FUN_142506000(const Scaleform::GFx::AS3::MovieRoot* proot, Scaleform::GFx::AS3::Value* pval,
                                       const char* ppathToVar);

namespace Scaleform { namespace GFx { namespace AS3 {

// count elements of the AS3 array at the path from index on, into the host's array of ints, floats, doubles,
// strings (kept alive by the movie's return value holder), wide strings (in its character buffer) or values.
// Undefined elements give 0 (NULL for strings). False when the path is not an array.
// A 4.1.18 virtual of the root. The path lookup is declared noalias just above, as the exe knows it does not keep
// the value's address, so the resolved value's flags are kept in a stack copy for its destructor.
// @0x142510240
bool MovieRoot::GetVariableArray(SetArrayTypeArg type, const char* ppathToVar, unsigned index, void* pdata,
                                 unsigned count)
{
    Value resolvedVal;
    if (FUN_142506000(this, &resolvedVal, ppathToVar))
    {
        if (!resolvedVal.IsObject())
            return false;
        Object* pobj = resolvedVal.GetObject();
        if (pobj && pobj->GetTraits().GetTraitsType() == Traits_Array && pobj->GetTraits().IsInstanceTraits())
        {
            MovieImpl::ReturnValueHolder* rvHolder = pMovieImpl->GetRetValHolder();
            rvHolder->StringArrayPos = 0;
            Sfr34_ResizeStringArray(rvHolder, 0);
            Instances::fl::Array* parray = static_cast<Instances::fl::Array*>(pobj);
            unsigned arrSize = static_cast<unsigned>(parray->GetSize());
            switch (type)
            {
            case 0:   // SA_Int
            {
                int* parr = static_cast<int*>(pdata);
                for (unsigned i = 0, n = Alg::Min(arrSize, count); i < n; ++i)
                {
                    const Value& val = parray->At(i + index);
                    if (!val.IsUndefined())
                        parr[i] = (int)val.AsInt();
                    else
                        parr[i] = 0;
                }
            }
                // fall through
            case 2:   // SA_Float
            {
                float* parr = static_cast<float*>(pdata);
                for (unsigned i = 0, n = Alg::Min(arrSize, count); i < n; ++i)
                {
                    const Value& val = parray->At(i + index);
                    if (!val.IsUndefined())
                        parr[i] = (float)val.AsNumber();
                    else
                        parr[i] = 0;
                }
                break;
            }
            case 1:   // SA_Double
            {
                Double* parr = static_cast<Double*>(pdata);
                for (unsigned i = 0, n = Alg::Min(arrSize, count); i < n; ++i)
                {
                    const Value& val = parray->At(i + index);
                    if (!val.IsUndefined())
                        parr[i] = (Double)val.AsNumber();
                    else
                        parr[i] = 0;
                }
                break;
            }
            case 5:   // SA_Value
            {
                GFx::Value* parr = static_cast<GFx::Value*>(pdata);
                for (unsigned i = 0, n = Alg::Min(arrSize, count); i < n; ++i)
                {
                    const Value& val      = parray->At(i + index);
                    GFx::Value*  pdestVal = &parr[i];
                    Sfr34_GfxValueView::SetUndefined(pdestVal);
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
                    const Value& val = parray->At(i + index);
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
                    const Value& val = parray->At(i + index);
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
    }
    return false;
}

// PropRef::IsFound: a property was found (a This, and a non-null value or object when the property is one).
static inline bool Sfr34_PropFound(const PropRef& prop)
{
    const UPInt bits = reinterpret_cast<UPInt>(prop.pValue);
    return !(prop.This.IsUndefined() || bits == 1 || ((bits & 2) != 0 && (bits & ~UPInt(2)) == 0));
}

// AvmDisplayObjContainer::GetAS3ChildByName (0x142505d40), which the exe inlines in HasMember.
static SF_FORCEINLINE SPtr<Instances::fl_display::DisplayObject> Sfr34_GetAS3ChildByName(AvmDisplayObjContainer* c,
                                                                                         const ASString& name)
{
    DisplayObjectBase* pch = c->GetDisplayObjContainer()->mDisplayList.GetDisplayObjectByName(name);
    if (pch)
    {
        AvmDisplayObj* avobj = ToAvmDisplayObj(pch);
        avobj->CreateASInstance(true);
        return avobj->GetAS3Obj();
    }
    return NULL;
}

} // namespace AS3

// ObjectInterface::HasMember: whether the AS3 object has a property of that public name or, as a display object
// container, a child of that name (an exception of the child lookup is dropped).
// The Multiname ctor and the string Value are the inline copies (InlineCtorTag, Value::InlineStr), as in the exe.
// MS2-FUNCTIONAL: the exe keeps the name Value's flags and bonus in registers across the QName call (LTCG), so it
// threads the string AddRef arm of the name copy; register allocation
// @0x142510e70
bool AS3ValueObjectInterface::HasMember(void* pdata, const char* name, bool isdobj) const
{
    using namespace AS3;
    using AS3::Value;
    SF_UNUSED(isdobj);
    MovieRoot* root = Sfr34_RootOf(pMovieRoot);
    VM*        vm   = root->pAVM;
    Object*    obj  = static_cast<Object*>(pdata);
    const Multiname mn(root->pAVM->GetPublicNamespace(), Value(ASString(root->BuiltinsMgr.GetStringManager()->CreateStringNode(name)), Value::InlineStr),
                       Multiname::InlineCtorTag());
    PropRef prop;
    obj->FindProperty(prop, mn, 0);
    if (!Sfr34_PropFound(prop))
    {
        const Traits& tr = obj->GetTraits();
        if ((unsigned)(tr.GetTraitsType() - Traits_DisplayObjectContainer) <
                (unsigned)(Traits_DisplayObject_End - Traits_DisplayObjectContainer) &&
            tr.IsInstanceTraits())
        {
            DisplayObject*          dobj  = Sfr34_DispObjOf(pdata);
            AvmDisplayObjContainer* pcurr = Sfr34_ToAvmContainer(dobj->IsDisplayObjContainer() ? dobj : NULL);
            const ASString          propName(root->BuiltinsMgr.GetStringManager()->CreateStringNode(name));
            Instances::fl_display::DisplayObject* pchild = Sfr34_GetAS3ChildByName(pcurr, propName);
            if (pchild)
                return true;
            if (vm->IsException())
                vm->HandleException = false;
            return false;
        }
    }
    return Sfr34_PropFound(prop);
}

namespace AS3 {

} // namespace AS3

// ObjectInterface::Invoke: the method of that public name of the AS3 object called on it with the host's
// arguments; the result (when asked for) converted for the host. An exception of the lookup or the call is output;
// false then, and when there is no such property.
// PropRef::GetSlotValueUnsafe written out (the exe inlines it); the Multiname ctor and the string Value are the
// inline copies (InlineCtorTag, Value::InlineStr).
// MS2-FUNCTIONAL: the name Value's QName-call reload (LTCG), register allocation
// @0x142512870
bool AS3ValueObjectInterface::Invoke(void* pdata, GFx::Value* presult, const char* name, const GFx::Value* pargs,
                               UPInt nargs, bool isdobj)
{
    using namespace AS3;
    using AS3::Value;
    SF_UNUSED(isdobj);
    MovieRoot* root = Sfr34_RootOf(pMovieRoot);
    VM*        vm   = root->pAVM;
    const Multiname mn(vm->GetPublicNamespace(), Value(ASString(root->GetStringManager418()->CreateStringNode(name)), Value::InlineStr),
                       Multiname::InlineCtorTag());
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

namespace AS3 {

} // namespace AS3

// ObjectInterface::InvokeClosure: a closure of the AS3 object (a VTable index closure when bit 1 of pdata is set,
// with dataAux its index, else a thunk closure of the thunk dataAux) called on it with the host's arguments.
// The SDK body; its Value dtors inline the in-TU ReleaseInternal, written as the SDK (merged case labels, the
// pointer loaded into a local before the weak-ref bit test).
// @0x142513920
bool AS3ValueObjectInterface::InvokeClosure(void* pdata, UPInt dataAux, GFx::Value* presult, const GFx::Value* pargs,
                                      UPInt nargs)
{
    using namespace AS3;
    using AS3::Value;
    MovieRoot* root = Sfr34_RootOf(pMovieRoot);
    VM*        vm   = root->pAVM;
    Value      asfn;
    Value      asresult;
    int        closureType = (reinterpret_cast<UPInt>(pdata) & 2) ? 1 : 0;
    Object*    pobj = reinterpret_cast<Object*>(reinterpret_cast<UPInt>(pdata) & ~UPInt(2));
    if (closureType)
        ValueAssignCopies::AssignInline18(asfn, Value(pobj, SInt32(dataAux)));   // VTableIndClosure
    else
        ValueAssignCopies::AssignInline18(asfn, Value(pobj, *reinterpret_cast<const ThunkInfo*>(dataAux)));   // ThunkClosure
    if (nargs)
    {
        Array<Value> args(static_cast<int>(nargs));
        for (UPInt i = 0; i < nargs; i++)
            root->GFxValue2ASValue(pargs[i], &args[i]);
        vm->ExecuteInternalUnsafe(asfn, Value(pobj, Value::InlineObj), asresult, static_cast<unsigned>(nargs), &args[0], false);
    }
    else
        vm->ExecuteInternalUnsafe(asfn, Value(pobj, Value::InlineObj), asresult, 0, NULL, false);
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

namespace AS3 {

static inline void FUN_142504630(ASRefCountCollector* gc, void* stats) { ::Scaleform::GFx::AS3::Sfr33CollectorQueue(reinterpret_cast<UByte*>(gc), static_cast<RefCountImpl*>(stats)); }          // ASRefCountCollector::ForceCollect
static inline void FUN_1425274b0(DisplayObjectBase* bitmap, Resource* pimage) { ::Scaleform::GFx::AS3::Sfr31SetResource(reinterpret_cast<Scaleform::UPInt>(bitmap), pimage); }   // AvmBitmap::SetImage

// The SDK's `if (!avm->HasAS3Obj()) { if (avm->CreateASInstanceNoCtor()) {...} }`, inline as in the exe.
// Ptr<RefCountImpl>'s converting ctor from the entry's Ptr<NotifyLoadInitC>, inline as in the exe.
static SF_FORCEINLINE Pickable<RefCountImpl> Sfr18InitCRef(Ptr<NotifyLoadInitC>& src)
{
    if (src) src->AddRef();
    return Pickable<RefCountImpl>(src);
}

// CreateASInstanceNoCtor ignores its bool, and the exe's LTCG calls it without one: called through the shorter
// signature (the same symbol).
static SF_FORCEINLINE bool Sfr18CreateNoCtor(AvmDisplayObj* avm)
{
    bool (AvmDisplayObj::*const pf)() = reinterpret_cast<bool (AvmDisplayObj::*)()>(&AvmDisplayObj::CreateASInstanceNoCtor);
    return (avm->*pf)();
}

static SF_FORCEINLINE void Sfr18LoadedCtor(AvmDisplayObj* avm, const SPtr<Instances::fl_display::Loader>& loader)
{
    if (!(avm->pAS3RawPtr || avm->pAS3CollectiblePtr.pObject))
    {
        if (Sfr18CreateNoCtor(avm))
        {
            avm->GetAS3Obj()->SetLoaderInfo(*loader);
            avm->CallCtor(true);
        }
    }
}

// DisplayObject::SetTimelineObjectFlag (SDK inline, not in our view): the ternary or/and of the flag.
static SF_FORCEINLINE void Sfr18SetTimelineObjectFlag(GFx::DisplayObject* p, bool v)
{
    (v) ? p->Flags |= GFx::DisplayObject::Mask_TimelineObject : p->Flags &= (~GFx::DisplayObject::Mask_TimelineObject);
}

// MovieRoot::GetLogState (SDK SF_INLINE), called straight on the StateBag: the exe reads the pointer through the
// returned sret address before the release, which the MovieImpl::GetLogState wrapper hides.
static SF_FORCEINLINE LogState* Sfr18RootLogState(MovieRoot* root) { return root->GetMovieImpl()->GetStateBag()->GetLogState(); }

// The loaded movie handed to its Loader while the preload task runs: open (once, after the version check), the
// progress of its bytes, its first frame's sprite made the Loader's child (init), and at the end the bitmap of an
// image (init) and complete; an error event when nothing could be loaded. True when the entry is done.
// @0x142515c60
bool LoadQueueEntryMT_LoadMovie::LoadFinished()
{
    const bool btaskDone = pPreloadTask->IsDone();
    if (pQueueEntry->Canceled && btaskDone)
        return true;
    LoadQueueEntry* qe   = static_cast<LoadQueueEntry*>(pQueueEntry);
    MovieRoot*      root = static_cast<MovieRoot*>(pMovieImpl->pASMovieRoot);
    if (btaskDone)
    {
        MovieDefImpl* pdefImpl = pPreloadTask->GetMoiveDefImpl();
        if (!pdefImpl)
        {
            qe->mLoader->ExecuteErrorEvent(qe->mURLRequest->GetUrl().ToCStr());
            if (qe->NotifyLoadInitCInterface)
                qe->NotifyLoadInitCInterface->ErrorEventCallback();
            qe->FirstExec = false;
            goto error_exit;
        }
        else
        {
            if (qe->FirstExec)
            {
                if (pdefImpl->GetVersion() != ~0u &&
                    (pdefImpl->GetVersion() < 9 || ((pdefImpl->GetDataDef()->GetFileAttributes() & 8) ? 3 : 2) < 3))
                {
                    pQueueEntry->Canceled = true;
                    if (Sfr18RootLogState(root) && !qe->QuietOpen)
                    {
                        Sfr18RootLogState(root)->LogScriptWarning(
                            "Failed loading SWF \"%s\": ActionScript version mismatch", qe->mURLRequest->GetUrl().ToCStr());
                    }
                    qe->mLoader->ExecuteErrorEvent(qe->mURLRequest->GetUrl().ToCStr());
                    if (qe->NotifyLoadInitCInterface)
                        qe->NotifyLoadInitCInterface->ErrorEventCallback();
                    pdefImpl = NULL;
                    goto error_exit;
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
            if (!FirstFrameLoaded && ((pdefImpl->pBindData->GetBindState() & MovieDefImpl::BSF_Frame1Loaded) != 0))
            {
                if (pdefImpl->GetDataDef()->MovieType == MovieDataDef::MT_Flash)
                {
                    GFx::DisplayObject* pparent = qe->mLoader->pDispObj;
                    Ptr<Sprite>         pnewChar;
                    if (pdefImpl)
                    {
                        if (root->pAVM)
                            FUN_142504630(&root->pAVM->GetGC(), pMovieImpl->pAdvanceStats);
                        CharacterCreateInfo ccinfo = { pdefImpl->GetDataDef(), pdefImpl, NULL };
                        pnewChar = *static_cast<Sprite*>(root->pASSupport->CreateCharacterInstance(
                            pMovieImpl, ccinfo, NULL, ResourceId(0), CharacterDef::Sprite));
                        pnewChar->SetLoadedSeparately(true);
                        Sfr18SetTimelineObjectFlag(pnewChar, true);
                        pnewChar->OnEventLoad();
                        pnewChar->AddToPlayList();
                        AvmSprite* avmSpr = static_cast<AvmSprite*>(ToAvmDisplayObj(pnewChar));
                        avmSpr->ExecuteInitActionFrameTags(0);
                        pnewChar->SetFOV(55.0);
                        Sfr18LoadedCtor(avmSpr, qe->mLoader);
                        Sfr34_ToAvmStage(pparent)->AddChild(pnewChar);
                        root->ResolveStickyVariables(pnewChar);
                        pnewChar->ModifyOptimizedPlayListLocal<Sprite>();
                        root->DoActions();
                    }
                    qe->mLoader->QueueInitEvent(pnewChar, Sfr18InitCRef(qe->NotifyLoadInitCInterface));
                }
                FirstFrameLoaded = true;
            }
            if ((pdefImpl->pBindData->GetBindState() & (MovieDefImpl::BS_InProgress | MovieDefImpl::BS_Finished)) <
                MovieDefImpl::BS_Finished)
                return false;
            if (pdefImpl->pBindData->GetBindState() & MovieDefImpl::BS_Finished)
            {
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
                        if (pres)
                        {
                            if (pres->GetResourceType() == Resource::RT_Image)
                                FUN_1425274b0(pnewChar, pres);
                        }
                    }
                    Sfr34_ToAvmStage(pparent)->AddChild(pnewChar);
                    Sfr18LoadedCtor(Sfr18ToAvmDisplayObj(pnewChar), qe->mLoader);
                    qe->mLoader->QueueInitEvent(static_cast<GFx::DisplayObject*>(pnewChar.GetPtr()),
                                                Sfr18InitCRef(qe->NotifyLoadInitCInterface));
                }
                qe->mLoader->QueueCompleteEvent();
            }
            else
            {
                qe->mLoader->ExecuteErrorEvent(qe->mURLRequest->GetUrl().ToCStr());
                qe->FirstExec = false;
            }
        }
error_exit:
        return true;
    }
    else
    {
        if (qe->FirstExec)
        {
            qe->mLoader->ExecuteOpenEvent();
            qe->FirstExec = false;
        }
    }
    return false;
}

// VM::IsVMCachedType(const InstanceTraits::Traits&) and (const ClassTraits::Traits&), inline here.
static SF_FORCEINLINE bool Sfr18IsVMCachedITraits(const VM& vm, const Traits* p)
{
    bool result = false;

    if (p == &vm.TraitsBoolean->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsNumber->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsInt->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsUint->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsString->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsClassClass->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsObject->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsNamespace->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsFunction->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsArray->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsVector_int->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsVector_uint->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsVector_double->GetInstanceTraits())
        result = true;
    else if (p == &vm.TraitsVector_String->GetInstanceTraits())
        result = true;
    else if (vm.GetXMLSupport().IsEnabled())
    {
        const XMLSupport& xmls = vm.GetXMLSupport();
        if (p == xmls.GetITraitsQName())
            result = true;
        else if (p == xmls.GetITraitsXML())
            result = true;
        else if (p == xmls.GetITraitsXMLList())
            result = true;
    }

    return result;
}

static SF_FORCEINLINE bool Sfr18IsVMCachedCTraits(const VM& vm, const Traits* p)
{
    bool result = false;

    if (p == vm.TraitsBoolean.GetPtr())
        result = true;
    else if (p == vm.TraitsNumber.GetPtr())
        result = true;
    else if (p == vm.TraitsInt.GetPtr())
        result = true;
    else if (p == vm.TraitsUint.GetPtr())
        result = true;
    else if (p == vm.TraitsString.GetPtr())
        result = true;
    else if (p == vm.TraitsClassClass.GetPtr())
        result = true;
    else if (p == vm.TraitsObject.GetPtr())
        result = true;
    else if (p == vm.TraitsNamespace.GetPtr())
        result = true;
    else if (p == vm.TraitsFunction.GetPtr())
        result = true;
    else if (p == vm.TraitsArray.GetPtr())
        result = true;
    else if (p == vm.TraitsVector_int.GetPtr())
        result = true;
    else if (p == vm.TraitsVector_uint.GetPtr())
        result = true;
    else if (p == vm.TraitsVector_double.GetPtr())
        result = true;
    else if (p == vm.TraitsVector_String.GetPtr())
        result = true;
    else if (vm.GetXMLSupport().IsEnabled())
    {
        const XMLSupport& xmls = vm.GetXMLSupport();
        if (p == xmls.GetClassTraitsQName())
            result = true;
        else if (p == xmls.GetClassTraitsXML())
            result = true;
        else if (p == xmls.GetClassTraitsXMLList())
            result = true;
    }

    return result;
}


// VM::IsVMCachedType(const Traits&): whether tr is one of the class traits the VM keeps (or, for instance traits,
// one of their instance traits): the primitives, Class, Object, Namespace, Function, Array, the typed vectors and,
// with XML support, QName, XML and XMLList.
// MS2-FUNCTIONAL free function (not declared in the shared VM class; no caller in the exe); the exe gives the
// instance and class halves their own result cmov and epilogue (ours shares one)
// @0x1425151a0
bool FUN_1425151a0(const VM& vm, const Traits& tr)
{
    bool result = false;
    if (tr.IsInstanceTraits())
        result = Sfr18IsVMCachedITraits(vm, &tr);
    else
        result = Sfr18IsVMCachedCTraits(vm, &tr);
    return result;
}

// sfr34 batch AF: the load of a queued request: the data of a URLLoader (variables, text or binary) read from its
// file, or the movie / image of a Loader (protocol images through the image creator) made the Loader's child.

// A queued load done here (not on a loader thread). A URLLoader's file is read whole and handed to it with its
// open/progress/complete events ("Can't open" error otherwise). A Loader's movie is loaded (a stripped player tries
// the ".gfx" name first; Loader.loadBytes from its bytes), an image protocol URL through the image creator; then
// open, the movie's sprite (or the image's bitmap) made the Loader's child and constructed, and init/complete
// (synchronously for protocol images). An error event when nothing could be loaded or the SWF is not AS3.
// MS2-FUNCTIONAL the exe keeps the `if (pmovieDef)` test at the AddLoadedMovieDef join (ours threads past it), merges the pnewBmpChar release tails differently, and differs in store scheduling/regalloc (regnorm 219)
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
    }
    else
    {
        String            url(pentry->URL), urlStrGfx;
        bool              stripped = false;
        LogState*         plog      = pls->GetLogState();
        Ptr<MovieDefImpl> pmovieDef;
        const unsigned    loadFlags = pMovieImpl->pMainMovieDef->GetLoadFlags();
        if (pMovieImpl->pMainMovie)
            stripped = ((pMovieImpl->pMainMovie->GetResourceMovieDef()->GetSWFFlags() & 0x10) != 0);  // a .gfx player
        if (stripped)
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

            if (pmovieDef)
            {
                // MovieDataDef::GetASVersion: 3 with the DoAbc file attribute, else 2
                if (pmovieDef->GetVersion() != ~0u &&
                    (pmovieDef->GetVersion() < 9 ||
                     ((pmovieDef->GetDataDef()->GetFileAttributes() & 8) ? 3u : 2u) < 3))
                {
                    if (plog && !pentry->QuietOpen)
                        plog->LogScriptWarning("Failed loading SWF \"%s\": ActionScript version mismatch", url.ToCStr());
                    entry.mLoader->ExecuteErrorEvent(url.ToCStr());
                    if (entry.NotifyLoadInitCInterface)
                        entry.NotifyLoadInitCInterface->ErrorEventCallback();
                    pmovieDef = NULL;
                    goto error_exit;
                }
            }
            else
            {
                if (plog && !pentry->QuietOpen)
                    plog->LogScriptWarning("Failed loading URL \"%s\"", url.ToCStr());
                entry.mLoader->ExecuteErrorEvent(url.ToCStr());
                if (entry.NotifyLoadInitCInterface)
                    entry.NotifyLoadInitCInterface->ErrorEventCallback();
                goto error_exit;
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
            Sfr18ToAvmContainerN(pparent)->AddChild(pnewBmpChar);
            Sfr18LoadedCtor(Sfr18ToAvmDisplayObj(pnewBmpChar), entry.mLoader);
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
            pnewSprite->GFx::DisplayObject::Flags |= GFx::DisplayObject::Mask_TimelineObject;   // the DisplayObject flags (+0x88), not Sprite::Flags
            pnewSprite->OnEventLoad();
            pnewSprite->AddToPlayList();
            AvmSprite* avmSpr = static_cast<AvmSprite*>(ToAvmDisplayObj(pnewSprite));
            avmSpr->ExecuteInitActionFrameTags(0);
            pnewSprite->SetFOV(55.0);
            Sfr18LoadedCtor(avmSpr, entry.mLoader);
            Sfr18ToAvmContainerN(pparent)->AddChild(pnewSprite);
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
error_exit:;
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
        ptf->AddIdImageDescAssoc(pid, reinterpret_cast<Render::Text::ImageDesc*>(pdesc));
    pdesc->Matrix.Tx() += -pdesc->BaseLineX;
    pdesc->Matrix.Ty() += -pdesc->BaseLineY;
    pdesc->Matrix.AppendScaling(pdesc->ScreenWidth / origWidth, pdesc->ScreenHeight / origHeight);
    reinterpret_cast<Render::Text::DocView::ImageSubstitutor*>(psubst)->AddImageDesc(reinterpret_cast<const Render::Text::DocView::ImageSubstitutor::Element&>(elem));
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

// @0x14251f5c0
void InteractiveObject::PropagateNoAdvanceGlobalFlag()
{
}

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
    if (!AS3::Sfr34_IsDisplayObject(pdata))
        return false;
    return static_cast<AS3::Instances::fl_display::DisplayObject*>(pdata)->pDispObj.GetPtr() != NULL;
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

// @0x142510dc0
bool AvmDisplayObj::HasEventHandler(const EventId&) const { return false; }
bool AvmInteractiveObj::HasEventHandler(const EventId&) const { return false; }   // the exe folds it into the one above
// @0x142510dd0
bool AvmDisplayObjContainer::HasEventHandler(const EventId&) const { return false; }

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
// Empty in the exe too. noinline plus the barrier keep cl from dropping the call, so its adjustor thunks
// (0x1425190d4/0x1425190e0) stay a jmp instead of folding to ret.
// @0x1425190d0
__declspec(noinline) void FUN_1425190d0(UPInt) { _ReadWriteBarrier(); }
// @0x142514d10
bool FUN_142514d10(UPInt) { return true; }

// Registers a class table with the VM's global object (+0x298).
// Raw-layout VM field
// @0x1425210d0
void FUN_1425210d0(VM& vm, const ClassInfo* table[])
{
    FUN_14241e540(reinterpret_cast<Instances::fl::GlobalObjectCPP*>(AccRd(reinterpret_cast<UPInt>(&vm), 0x298)), table);
}

// Raw-layout getter
// @0x14250ba00
UPInt FUN_14250ba00(UPInt self) { return AccRd(self, 0x40); }
// Raw-layout getter
// @0x14250d960
UPInt FUN_14250d960(UPInt self) { return AccRd(self, 0xc8); }
// Raw-layout getter
// @0x14250eef0
UPInt FUN_14250eef0(UPInt self) { return AccRd(AccRd(self, 0x40), 0x18); }

namespace {
// The SDK's Render::ContextImpl::EntryRef (Render_Context.h): the page and index of an entry (as sfr_as2_03y).
struct As3RatioEntryRef
{
    Render::ContextImpl::EntryPage* pPage;
    unsigned                        Index;

    SF_FORCEINLINE As3RatioEntryRef(const Render::ContextImpl::Entry* pentry)
    {
        pPage = (Render::ContextImpl::EntryPage*)(((UPInt)pentry) & ~(UPInt)0xFFF);
        Index = unsigned(pentry - &pPage->Entries[0]);
    }
    SF_FORCEINLINE Render::ContextImpl::EntryData* GetData() const { return pPage->pSnapshotPage->pData[Index]; }
};

SF_FORCEINLINE const Render::ContextImpl::EntryData* As3RatioReadOnlyData(const Render::ContextImpl::Entry* pentry)
{
    return As3RatioEntryRef(pentry).GetData();
}
} // namespace

// ShapeObject::GetRatio: the morph ratio of a shape render node, 0 for any other node (SDK form, as the AS2 twin).
// @0x14250d630
float ShapeObject::GetRatio() const
{
    if (pRenNode)
    {
        if (As3RatioReadOnlyData(pRenNode.GetPtr())->Type == Render::ContextImpl::EntryData::ET_Shape)
        {
            return ((const Render::TreeShape::NodeData*)As3RatioReadOnlyData(
                static_cast<Render::TreeShape*>(pRenNode.GetPtr())))->MorphRatio;
        }
    }
    return 0.f;
}

// -- tail calls into the shared bodies --

// Free-function form of the inherited slot
// @0x142518a10
bool FUN_142518a10(UPInt self, const EventId& id)
{
    return reinterpret_cast<AvmInteractiveObj*>(self)->AvmInteractiveObj::OnEvent(id);
}
// Free-function form of the inherited slot
// @0x142518fc0
bool FUN_142518fc0(UPInt self, const EventId& id)
{
    return reinterpret_cast<AvmDisplayObj*>(self)->AvmDisplayObj::OnEvent(id);
}
// Free-function form of the AS3 object's load (AvmDisplayObj::OnEventLoad's body)
// @0x142518fe0
void AvmButton::OnEventLoad()
{
    const UPInt self = reinterpret_cast<UPInt>(this);
    AvmDisplayObj* avm = reinterpret_cast<AvmDisplayObj*>(self);
    avm->SetAS3ObjCollectible(avm->GetAS3Obj());
}
// Free-function form of the inherited slot
// @0x1425191e0
void FUN_1425191e0(UPInt self)
{
    reinterpret_cast<AvmDisplayObj*>(self)->AvmDisplayObj::OnEventUnload();
}
// Free-function form of the inherited slot
// @0x142519890
void FUN_142519890(UPInt self)
{
    reinterpret_cast<AvmDisplayObj*>(self)->AvmDisplayObj::OnEventUnload();
}
// Free-function form of the inherited slot
// @0x1425198b0
void FUN_1425198b0(UPInt self)
{
    reinterpret_cast<AvmDisplayObj*>(self)->AvmDisplayObj::OnEventUnload();
}
// Free-function form of the inherited slot
// @0x142519d10
void FUN_142519d10(UPInt self, InteractiveObject::FocusEventType event, InteractiveObject* ch, unsigned controllerIdx,
                   FocusMovedType fmt)
{
    // self is already the AvmInteractiveObj base: the exe thunk is a plain jmp, the qualified call through the derived
    // pointer would add 0x30
    reinterpret_cast<AvmInteractiveObj*>(self - 0x30)->AvmInteractiveObj::OnFocus(event, ch, controllerIdx, fmt);
}
// Free-function form of the inherited slot
// @0x142519ec0
void FUN_142519ec0(UPInt self, InteractiveObject::FocusEventType event, InteractiveObject* ch, unsigned controllerIdx,
                   FocusMovedType fmt)
{
    // self is already the AvmInteractiveObj base: the exe thunk is a plain jmp, the qualified call through the derived
    // pointer would add 0x30
    reinterpret_cast<AvmInteractiveObj*>(self - 0x30)->AvmInteractiveObj::OnFocus(event, ch, controllerIdx, fmt);
}

// MovieRoot slots on its EventChains (+0x150) and MovieImpl (+0x10).
// Raw-layout MovieRoot slot
// @0x1425184f0
void FUN_1425184f0(UPInt self)
{
    reinterpret_cast<EventChains*>(self + 0x150)->QueueEvents((EventId::IdCode)AS3Event_Controller);
}
// Raw-layout MovieRoot slot
// @0x142518510
void FUN_142518510(UPInt self, InteractiveObject* pNewFocus, unsigned controllerIdx, FocusMovedType fmt)
{
    reinterpret_cast<MovieImpl*>(AccRd(self, 0x10))->TransferFocus(pNewFocus, controllerIdx, fmt);
}
// activate (0x1000011) or deactivate (0x1000012) to the listening objects.
// Raw-layout MovieRoot slot
// @0x14251ac40
void FUN_14251ac40(UPInt self, bool activate)
{
    reinterpret_cast<EventChains*>(self + 0x150)->Dispatch((EventId::IdCode)((activate ? 0 : 1) + 0x1000011));
}
// Raw-layout MovieRoot slot
// @0x14251ac60
void FUN_14251ac60(UPInt self)
{
    reinterpret_cast<EventChains*>(self + 0x150)->QueueEvents((EventId::IdCode)2);
}

// Tracer::Output: passed on to the FlashUI of the traced call frame's VM.
// Raw-layout walk (CallFrame +0x20 -> +0x28 -> +0x20 -> +0x20)
// @0x14251bda0
void FUN_14251bda0(UPInt self, FlashUI::OutputMessageType type, const char* msg)
{
    reinterpret_cast<FlashUI*>(AccRd(AccRd(AccRd(AccRd(self, 0x20), 0x28), 0x20), 0x20))->Output(type, msg);
}

// -- adjustor thunks (this of a secondary base part back to the object) --

// AvmSprite-side thunks (their targets are not AvmButton/AvmTextField slots)
#define SFR21_THUNK(name, off, target) \
    void name(UPInt self) { target(self - off); }

// MS2-FUNCTIONAL: adjustor thunk; the exe has the compiler-generated sub rcx,N, a hand-written one gives add rcx,-N
// @0x1425190d4
SFR21_THUNK(FUN_1425190d4, 0x30, FUN_1425190d0)
// MS2-FUNCTIONAL: adjustor thunk; the exe has the compiler-generated sub rcx,N, a hand-written one gives add rcx,-N
// @0x1425190e0
SFR21_THUNK(FUN_1425190e0, 0x40, FUN_1425190d0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x142519898
SFR21_THUNK(FUN_142519898, 0x30, FUN_142519890)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1425198a4
SFR21_THUNK(FUN_1425198a4, 0x40, FUN_142519890)

#undef SFR21_THUNK

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx {

// @0x1425227d0
void InteractiveObject::RemoveDisplayObject(DisplayObjectBase*)
{
}

}} // namespace Scaleform::GFx

// MovieRoot::GetMouseCursorType (SDK): GetMouseCursorTypeString of the cursor mouse mouseIndex shows. The MouseState
// comes from the SDK's MovieImpl::GetMouseState (+0x1260: 4 MouseStates of 0x50 bytes, CursorType at +0x40); an index
// past them reads through the NULL state, as the exe does. The protected member is reached through a using-declaration.
// @0x14250bad0
void FUN_14250bad0(void* proot, Scaleform::GFx::ASString& result, Scaleform::UInt32 mouseIndex)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    struct Access : MovieRoot { using MovieRoot::GetMouseCursorTypeString; };
    struct MS { static __forceinline const UInt32* Get(UPInt impl, unsigned i)
    {
        if (i >= 4)
            return NULL;
        return reinterpret_cast<const UInt32*>(impl + 0x1260 + (UPInt)i * 0x50);
    } };
    const UInt32* ms = MS::Get(AccRd(reinterpret_cast<UPInt>(proot), 0x10), mouseIndex);
    (static_cast<const MovieRoot*>(proot)->*&Access::GetMouseCursorTypeString)(result, ms[0x10]);
}

// AvmButton / AvmTextField come from the SDK MI layout (SF_AS3_AVMBUTTON_MODEL). Copy-constructing them stores
// the vptrs, so cl emits their vftables and with them its own adjustor thunks (sub rcx,N; jmp member), which are
// the exe ones. The thunk targets stay the leaves above at their exe VAs.
namespace Scaleform { namespace GFx { namespace AS3 {
void Sfr18EmitAvmVftables(void* p, const AvmButton* pbtn, void* q, const AvmTextField* ptxt)
{
    new (p) AvmButton(*pbtn);
    new (q) AvmTextField(*ptxt);
}
}}} // namespace Scaleform::GFx::AS3

// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
// MS2-PIN: ??_7AvmInteractiveObjBase@GFx@Scaleform@@6B@ 0x14317bfe8
// MS2-PIN: ??_7AvmDisplayObj@AS3@GFx@Scaleform@@6B@ 0x14317c160
// MS2-PIN: ??_7AvmInteractiveObj@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317ca60
// MS2-PIN: ??_7AvmInteractiveObj@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317cb30
// MS2-PIN: ??_7AvmButtonBase@GFx@Scaleform@@6B@ 0x14317db08
// MS2-PIN: ??_7AvmTextFieldBase@GFx@Scaleform@@6B@ 0x14317e508
// MS2-PIN: ??_7AvmButton@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317dbe0
// MS2-PIN: ??_7AvmButton@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317dcb0
// MS2-PIN: ??_7AvmButton@AS3@GFx@Scaleform@@6B@ 0x14317dd68
// MS2-PIN: ??_7AvmTextField@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317ea80
// MS2-PIN: ??_7AvmTextField@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317eb50
// MS2-PIN: ??_7AvmTextField@AS3@GFx@Scaleform@@6B@ 0x14317ec08
// MS2-PIN: ?IsLogNotNull@?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@GFx@Scaleform@@IEBA_NXZ 0x142510dc0
// MS2-PIN: ?HasEventHandler@AvmButton@AS3@GFx@Scaleform@@WDA@EBA_NAEBVEventId@34@@Z 0x142510da4
// MS2-PIN: ?HasEventHandler@AvmButton@AS3@GFx@Scaleform@@WEA@EBA_NAEBVEventId@34@@Z 0x142510db0
// MS2-PIN: ?HasEventHandler@AvmTextField@AS3@GFx@Scaleform@@UEBA_NAEBVEventId@34@@Z 0x142510df0
// MS2-PIN: ?HasEventHandler@AvmTextField@AS3@GFx@Scaleform@@WDA@EBA_NAEBVEventId@34@@Z 0x142510df4
// MS2-PIN: ?HasEventHandler@AvmTextField@AS3@GFx@Scaleform@@WEA@EBA_NAEBVEventId@34@@Z 0x142510e00
// MS2-PIN: ?IsFocusEnabled@AvmButton@AS3@GFx@Scaleform@@WBA@EBA_NW4FocusMovedType@34@@Z 0x142514284
// MS2-PIN: ?IsFocusEnabled@AvmTextField@AS3@GFx@Scaleform@@WBA@EBA_NW4FocusMovedType@34@@Z 0x142514304
// MS2-PIN: ?IsTabable@AvmButton@AS3@GFx@Scaleform@@WBA@EBA_NXZ 0x142514efc
// MS2-PIN: ?IsTabable@AvmTextField@AS3@GFx@Scaleform@@WBA@EBA_NXZ 0x1425150b0
// MS2-PIN: ?OnEvent@AvmButton@AS3@GFx@Scaleform@@WDA@EAA_NAEBVEventId@34@@Z 0x142518a18
// MS2-PIN: ?OnEvent@AvmButton@AS3@GFx@Scaleform@@WEA@EAA_NAEBVEventId@34@@Z 0x142518a24
// MS2-PIN: ?OnEvent@AvmTextField@AS3@GFx@Scaleform@@WDA@EAA_NAEBVEventId@34@@Z 0x142518fc8
// MS2-PIN: ?OnEvent@AvmTextField@AS3@GFx@Scaleform@@WEA@EAA_NAEBVEventId@34@@Z 0x142518fd4
// MS2-PIN: ?OnEventLoad@AvmButton@AS3@GFx@Scaleform@@WDA@EAAXXZ 0x142518ffc
// MS2-PIN: ?OnEventLoad@AvmButton@AS3@GFx@Scaleform@@WEA@EAAXXZ 0x142519008
// MS2-PIN: ?OnEventLoad@AvmTextField@AS3@GFx@Scaleform@@WDA@EAAXXZ 0x1425191bc
// MS2-PIN: ?OnEventLoad@AvmTextField@AS3@GFx@Scaleform@@WEA@EAAXXZ 0x1425191c8
// MS2-PIN: ?OnEventUnload@AvmButton@AS3@GFx@Scaleform@@WDA@EAAXXZ 0x1425191e8
// MS2-PIN: ?OnEventUnload@AvmButton@AS3@GFx@Scaleform@@WEA@EAAXXZ 0x1425191f4
// MS2-PIN: ?OnEventUnload@AvmTextField@AS3@GFx@Scaleform@@WDA@EAAXXZ 0x1425198b8
// MS2-PIN: ?OnEventUnload@AvmTextField@AS3@GFx@Scaleform@@WEA@EAAXXZ 0x1425198c4
// MS2-PIN: ?OnFocus@AvmButton@AS3@GFx@Scaleform@@WBA@EAAXW4FocusEventType@InteractiveObject@34@PEAV634@IW4FocusMovedType@34@@Z 0x142519d18
// MS2-PIN: ?OnFocus@AvmTextField@AS3@GFx@Scaleform@@WBA@EAAXW4FocusEventType@InteractiveObject@34@PEAV634@IW4FocusMovedType@34@@Z 0x142519ec8
// MS2-PIN: ?OnGettingKeyboardFocus@AvmButton@AS3@GFx@Scaleform@@WBA@EAAXIW4FocusMovedType@34@@Z 0x14251a0d4
// MS2-PIN: ?OnGettingKeyboardFocus@AvmTextField@AS3@GFx@Scaleform@@WBA@EAAXIW4FocusMovedType@34@@Z 0x14251a0f4
// MS2-PIN: ?OnKeyEvent@AvmButton@AS3@GFx@Scaleform@@WBA@EAA_NAEBVEventId@34@PEAH@Z 0x14251a334
// MS2-PIN: ?OnKeyEvent@AvmTextField@AS3@GFx@Scaleform@@WBA@EAA_NAEBVEventId@34@PEAH@Z 0x14251a388
// MS2-PIN: ?OnLosingKeyboardFocus@AvmButton@AS3@GFx@Scaleform@@WBA@EAA_NPEAVInteractiveObject@34@IW4FocusMovedType@34@@Z 0x14251a7f4
// MS2-PIN: ?OnLosingKeyboardFocus@AvmTextField@AS3@GFx@Scaleform@@WBA@EAA_NPEAVInteractiveObject@34@IW4FocusMovedType@34@@Z 0x14251a814
// MS2-PIN: ?OnUnloading@AvmButton@AS3@GFx@Scaleform@@WDA@EAA_N_N@Z 0x14251af24
// MS2-PIN: ?OnUnloading@AvmButton@AS3@GFx@Scaleform@@WEA@EAA_N_N@Z 0x14251af30
// MS2-PIN: ?OnUnloading@AvmTextField@AS3@GFx@Scaleform@@WDA@EAA_N_N@Z 0x14251b0f4
// MS2-PIN: ?OnUnloading@AvmTextField@AS3@GFx@Scaleform@@WEA@EAA_N_N@Z 0x14251b100
