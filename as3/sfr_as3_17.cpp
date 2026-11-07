// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_17
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424ed890-0x1424ede80 .text$mn
// MS2-RANGE: 0x1424ee490-0x1424efb40 .text$mn
// MS2-RANGE: 0x1424efc30-0x1424f03f0 .text$mn
// MS2-RANGE: 0x1424f05a0-0x1424f2010 .text$mn
// MS2-RANGE: 0x1424f2400-0x1424f2450 .text$mn
// MS2-RANGE: 0x1424f2700-0x1424f27b0 .text$mn
// MS2-RANGE: 0x1424f3320-0x1424f33d0 .text$mn
// MS2-RANGE: 0x1424f3710-0x1424f3e60 .text$mn
// MS2-RANGE: 0x1424f3f40-0x1424f4000 .text$mn
// MS2-RANGE: 0x1424f41f0-0x1424f6f50 .text$mn
// MS2-RANGE: 0x1424f7190-0x1424f9570 .text$mn
// MS2-RANGE: 0x1424f96c0-0x1424f9d60 .text$mn
// MS2-RANGE: 0x1424fa320-0x1424fa5b0 .text$mn
// MS2-RANGE: 0x1424fe5b0-0x1424fe620 .text$mn
// MS2-RANGE: 0x1424feab0-0x142500770 .text$mn
// MS2-RANGE: 0x1425008e0-0x142501920 .text$mn
// MS2-RANGE: 0x142501a80-0x142502e70 .text$mn
// MS2-RANGE: 0x142503660-0x142507730 .text$mn
// MS2-RANGE: 0x1425078e0-0x142507910 .text$mn
// MS2-RANGE: 0x142507a40-0x1425094e0 .text$mn
// MS2-RANGE: 0x142509850-0x142509d40 .text$mn
#define SF_AS3_AVMBUTTON_MODEL
#define SF_AS3_SHAPEOBJECT_MODEL   // ShapeObject / AvmBitmap from the SDK MI layout (as3_avm.h)
#define MS2_AS3_ASSIGN_NOALIAS
#define MS2_AS3_SCU   // AS3_All.cpp SCU: AS3_Object.cpp/AS3_Value.cpp AddRef bodies inline (as3_value.h)
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/kernel/sf_simd.h"
#include "ms2/scaleform/include/gfx/gfx_input.h"
#include "ms2/scaleform/include/kernel/sf_autoptr.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_intervaltimer.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/as3/as3_tracer.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_support.h"
#include "ms2/scaleform/include/gfx/gfx_state.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"
#include "ms2/scaleform/include/gfx/as3/as3_avmloader.h"
#include "ms2/scaleform/include/gfx/as3/as3_stage.h"
#include "ms2/scaleform/include/gfx/gfx_loadproc.h"
#include "ms2/scaleform/include/gfx/gfx_shapedef.h"
#include "ms2/scaleform/include/gfx/gfx_drawingcontext.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/as3_callframe.h"
#include "ms2/scaleform/include/render/render_meshprovider.h"
#include "ms2/scaleform/include/kernel/sf_msgformat.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_e4x.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_userdefined.h"
#include "ms2/scaleform/include/gfx/as3/as3_userdefinedfunction.h"

void FUN_142415930(Scaleform::GFx::AS3::Instances::fl::XMLList* self, Scaleform::GFx::AS3::Instances::fl::XMLList& list,
                   const Scaleform::GFx::AS3::Multiname& prop_name);
// Out of line in the exe (instantiated in sfr_as3_01c).
extern template Scaleform::String Scaleform::AsString<long>(const long&);
extern template Scaleform::String Scaleform::AsString<unsigned long>(const unsigned long&);
#undef GetObject

// The exe calls the event chains' ResizeNoConstruct out of line (explicitly instantiated in sfr_as3_19, 0x142524cd0).
namespace Scaleform { namespace GFx { namespace AS3 {
// The protected FunctionBase(InstanceTraits::Traits&) (0x1423ed140, sfr_as3_01c), called in place on the allocation.
struct Sfr17FunctionBaseAccess : Instances::FunctionBase
{
    static void Construct(void* mem, InstanceTraits::Traits& t)
    {
        static_cast<Sfr17FunctionBaseAccess*>(mem)->Instances::FunctionBase::FunctionBase(t);
    }
};
}}} // namespace Scaleform::GFx::AS3
char* FUN_14250e2d0(const void* si, void* ret, Scaleform::GFx::AS3::VM* vm, Scaleform::GFx::AS3::Value* value, const Scaleform::GFx::AS3::Value* thisValue, void* vtable, int valTarget);   // SlotInfo: read the slot into value
namespace Scaleform {
typedef ArrayData<UPInt, AllocatorLH_POD<UPInt, 338>, ArrayDefaultPolicy> Sfr17WordArray;
typedef ArrayDataDH<UPInt, AllocatorDH_POD<UPInt, 328>, ArrayDefaultPolicy> Sfr17WordArrayDH;
typedef ArrayPagedBase<const GFx::AS3::RefCountBaseGC<323>*, 10, 5, AllocatorPagedLH_POD<const GFx::AS3::RefCountBaseGC<323>*, 2> > Sfr17GcPages;
template<> void Sfr17WordArray::Resize(UPInt);
template<> void Sfr17WordArrayDH::Resize(UPInt);
}
namespace Scaleform {
template<> SF_NOINLINE void ArrayDataBase<WeakPtr<GFx::DisplayObject>, AllocatorLH<WeakPtr<GFx::DisplayObject>, Stat_Default_Mem>,
    ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);
// Defined in sfr_as3_16 (0x1424e0340) as an explicit specialization; declared here so this unit calls it.
template<> AutoPtr<ArrayLH<WeakPtr<GFx::DisplayObject>, 2, ArrayDefaultPolicy> >&
AutoPtr<ArrayLH<WeakPtr<GFx::DisplayObject>, 2, ArrayDefaultPolicy> >::operator=(const AutoPtr& p);
// The weak display-object array destructor is the out-of-line 0x1424dc730 (instantiated in sfr_as3_15).
template<> SF_NOINLINE ArrayDataBase<WeakPtr<GFx::DisplayObject>, AllocatorLH<WeakPtr<GFx::DisplayObject>, 2>,
                                     ArrayDefaultPolicy>::~ArrayDataBase();
}

// The definitions (here and in sfr_as3_19) of exe functions called through FUN_ forwarders, by their real names.
namespace Scaleform { namespace GFx { namespace AS3 {
UPInt Sfr31ResolveClassTraits(UPInt vm, UPInt file, UPInt mn);                                    // 0x142524f60
UPInt Sfr31FindClassTraitsByMn(UPInt vm, UPInt mn);                                               // 0x142525270
SInt64 Sfr31NumberToChars(char* buffer, int bufflen, double val);                                 // 0x142525f20
void Sfr31VMRaiseError(UPInt vm, const unsigned long* error, UPInt classInfo);                    // 0x14252ecb0
void Sfr31TraceBlock(UPInt tracer, UPInt pos, UPInt block);                                       // 0x142530220
void Sfr31ClassTraitsCleanup(UPInt entry);                                                        // 0x1425303b0
void Sfr27MultinameFromQName(Multiname* mn, const Value* qname);                                  // sfr_as3_15
}}} // namespace Scaleform::GFx::AS3

// The AS3 object's +0x50 counted reference set to p (unrecovered).
void FUN_142502e70(void* pavm, const Scaleform::GFx::EventId& id);   // AvmDisplayObj: fire the event
// The Value setters, out of line in the exe (GFxValue2ASValue tail-calls them).

namespace Scaleform { namespace GFx { namespace AS3 {
// Trace values for the four built-in scalar traits are definitely non-null; user classes may have
// either nullability, which is recorded conservatively by the tracer.
// @0x1424ee980
Value::TraceNullType TR::State::CanBeNull(const InstanceTraits::Traits& traits) const
{
    return static_cast<const Tracer*>(pTracer)->CanBeNull(traits);
}
// @0x1424ed8f0
SF_NOINLINE void Value::Assign(const Value& other)
{
    if (&other != this)
    {
        Release();
        SIMD::PrefetchObj(&other);
        memcpy(this, &other, sizeof(Value));
        AddRef();
    }
}

// @0x1424ed9d0
// inline: sfr_as3_16 has an inline copy for its operator= (0x1424e0d40), so both are COMDATs.
inline SF_NOINLINE void Value::Assign(const ASString& v)
{
    Release();
    if (v.GetNode() == v.GetNode()->GetManager()->GetNullStringNode())
    {
        value = (ASStringNode*)NULL;
        // null has type Object.
        SetKind(kObject);
    }
    else
    {
        SetKind(kString);
        value = v.GetNode();
        AddRefString();
    }
}

// @0x1424edab0
void Value::Assign(ASStringNode* v)
{
    Release();
    AssignUnsafe(v);
}

// @0x1424edb80
void Value::Assign(Class* v)
{
    Release();
    SetKind(kClass);
    value = v;
    if (v)
        v->AddRef();
}

// @0x1424edc10
void Value::Assign(Object* v)
{
    Release();
    SetKind(kObject);
    value = v;
    if (v)
        v->AddRef();
}

// @0x1424edce0
void Value::AssignUnsafe(const Value& other)
{
    if (&other != this)
    {
        SIMD::PrefetchObj(&other);
        memcpy(this, &other, sizeof(Value));
        AddRef();
    }
}

// @0x1424edd50
void Value::AssignUnsafe(const ASString& v)
{
    if (v.GetNode() == v.GetNode()->GetManager()->GetNullStringNode())
    {
        value = (ASStringNode*)NULL;
        // null has type Object.
        SetKind(kObject);
    }
    else
    {
        SetKind(kString);
        value = v.GetNode();
        AddRefString();
    }
}

// @0x1424eddb0
void Value::AssignUnsafe(ASStringNode* v)
{
    value = v;
    if (v)
    {
        if (v == v->GetManager()->GetNullStringNode())
        {
            SetKind(kObject);
            value = static_cast<Object*>(NULL);
        }
        else
        {
            SetKind(kString);
            AddRefString();
        }
    }
    else
        SetKind(kObject);
}

// @0x1424ede20
void Value::AssignUnsafe(Class* v)
{
    SetKind(kClass);
    value = v;
    if (v)
        v->AddRef();
}

// @0x1424ede50
void Value::AssignUnsafe(Object* v)
{
    SetKind(kObject);
    value = v;
    if (v)
        v->AddRef();
}

// @0x1424efa70
void IntervalTimer::Clear()
{
    Active = false;
    TimerObj = static_cast<Instances::fl_utils::Timer*>(0);
}

// @0x1424f0b70
__declspec(noinline) bool Multiname::ContainsNamespace(const Instances::Namespace& ns) const
{
    if ((static_cast<UInt32>(Kind) & 3) != 2)
        return static_cast<const Instances::Namespace&>(*Obj) == ns;

    const ArrayLH<SPtr<Instances::Namespace> >& nss = static_cast<const NamespaceSet&>(*Obj).GetNamespaces();
    for (UPInt i = 0; i < nss.GetSize(); ++i)
        if (*nss[i] == ns)
            return true;
    return false;
}

// @0x1424f0be0
bool Value::Convert2Boolean() const
{
    bool result = false;

    switch(GetKind())
    {
    case kUndefined:
        result = false;
        break;
    case kBoolean:
        result = value;
        break;
    case kInt:
        result = value.VS._1.VInt != 0;
        break;
    case kUInt:
        result = value.VS._1.VUInt != 0;
        break;
    case kNumber:
        if (IsNaN() || IsPOSITIVE_ZERO() || IsNEGATIVE_ZERO())
            result = false;
        else
            result = true;
        break;
    case kString:
        if (value.VS._1.VStr)
            // Not null.
            result = value.VS._1.VStr->Size != 0;
        else
            // null.
            result = false;
        break;
    case kNamespace:
        result = false;
        break;
    case kFunction:
    case kObject:
    case kClass:
    case kThunkFunction:
        if (IsNull())
            result = false;
        else
            result = true;
        break;
    case kThunkClosure:
    case kVTableIndClosure:
        // The same logic as for kFunction. False in case of null.
        // Because closure is never null, we should return true.
        // In case of ThunkClosure we always have a thunk.
        result = true;
        break;
    case kThunk:
    case kVTableInd:
        result = true;
        break;
    default:
        break;
    }

    return result;
}

// ---- the AVM parts of the display objects (as3_avm.h) and the movie root's action queues ----

// ToAvmInteractiveObj in the SDK form (a null test, then a static_cast of GetAvmIntObj), which the exe inlines.
static __forceinline AvmInteractiveObj* Sfr33ToAvmIntObjInline(InteractiveObject* p)
{
    if (!p)
        return NULL;
    return static_cast<AvmInteractiveObj*>(p->GetAvmIntObj());
}

// @0x1424f2400
unsigned AvmDisplayObj::CreateASInstance(bool execute)
{
    if (!pAS3RawPtr && !pAS3CollectiblePtr && CreateASInstanceNoCtor(execute))
        return CallCtor(execute);
    return 0;
}

// @0x142505e50
Instances::fl_display::DisplayObject* AvmDisplayObj::GetAS3Parent() const
{
    if (!Sfr33ToAvmIntObjInline(pDispObj->GetParent()))
        return NULL;
    return Sfr33ToAvmIntObjInline(pDispObj->GetParent())->GetAS3Obj();
}

// @0x142505ee0
MovieRoot* AvmDisplayObj::GetAS3Root() const
{
    return static_cast<MovieRoot*>(pDispObj->GetASMovieRoot());
}

// @0x142505f20
String& AvmDisplayObj::GetASClassName(String* className) const
{
    if (pClassName)
    {
        *className = pClassName;
    }
    else
    {
        const String* psymbolName = pDispObj->GetResourceMovieDef()->GetNameOfExportedResource(ResourceId(pDispObj->Id));
        if (!psymbolName)
            *className = GetDefaultASClassName();
        else
            *className = *psymbolName;
    }
    return *className;
}

// The VM is created on first use (CheckAvm) before it is returned (SDK form).
// @0x142506d30
ASVM* AvmDisplayObj::GetAVM()
{
    GetAS3Root()->CheckAvm();
    return GetAS3Root()->pAVM;
}

// @0x142506e10
const char* AvmDisplayObj::GetAbsolutePath(String* ppath) const
{
    InteractiveObject* pparent = pDispObj->GetParent();
    if (pparent)
    {
        pparent->GetAbsolutePath(ppath);
        ppath->AppendString(".");
        ASString name = pDispObj->GetName();
        ppath->AppendString(name.ToCStr());
    }
    return ppath->ToCStr();
}

// @0x142507550
__declspec(noinline) AvmInteractiveObj* AvmDisplayObj::GetAvmParent() const
{
    return ToAvmInteractiveObj(pDispObj->GetParent());
}

// The top parent's AVM part when the parent belongs to an AS3 movie (the parent is not checked for NULL).
// @0x142507590
AvmInteractiveObj* AvmInteractiveObj::GetAvmTopParent(bool ignoreLockRoot) const
{
    if (pDispObj->GetParent()->GetAVMVersion() == 2)
        return AvmInteractiveObj::FromBase(pDispObj->GetParent()->GetTopParent(ignoreLockRoot)->GetAvmIntObj());
    return NULL;
}

// @0x1424efe00
void AvmInteractiveObj::CloneInternalData(const InteractiveObject*)
{
}

// @0x1424f1f70
void AvmInteractiveObj::CopyPhysicalProperties(const InteractiveObject*)
{
}

// @0x1424f7190
bool AvmDisplayObjContainer::DetachChild(DisplayObjectBase* ch)
{
    return RemoveChild(ch) != NULL;
}

// The SDK's AvmDisplayObj::HasAS3Obj: either pointer set.
static SF_FORCEINLINE bool Sfr33HasAS3Obj(const AvmDisplayObj* avm)
{
    return avm->pAS3RawPtr || avm->pAS3CollectiblePtr;
}

// The SDK's HasAS3Obj test, then the object's loader info cleared.
// @0x142504810
void AvmSprite::ForceShutdown()
{
    if (Sfr33HasAS3Obj(this))
        GetAS3Obj()->SetLoaderInfo(static_cast<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo*>(NULL));
}

// The frame runs in the next ExecuteFrame: the sprite moves to the optimized playlist.
// @0x1424feab0
void AvmSprite::ExecuteFrameTags(unsigned)
{
    SprFlags |= Flag_NeedExecuteFrame;
    if (GetSprite()->IsInPlayList())
        GetSprite()->AddToOptimizedPlayList();
    GetSprite()->DisplayObjectBase::Flags &= ~DisplayObjectBase::Mask_JustLoaded;
}

// Runs the init actions of frame once.
// @0x1424fee10
void AvmSprite::ExecuteInitActionFrameTags(unsigned frame)
{
    const unsigned byteIndex = frame >> 3;
    if (!(InitActionsExecuted[byteIndex] & (1 << (frame & 7))))
    {
        // Keep the sprite alive while its init actions run.
        Ptr<DisplayObject> thisPtr(pDispObj);
        TimelineDef::Frame initActions;
        if (GetSprite()->pDef->GetInitActions(&initActions, frame) && initActions.GetTagCount() > 0)
        {
            for (unsigned i = 0; i < initActions.GetTagCount(); ++i)
                initActions.GetTag(i)->Execute(GetSprite());
            InitActionsExecuted[byteIndex] |= UByte(1 << (frame & 7));
        }
    }
}

// The hand cursor in button mode.
// @0x142508540
unsigned AvmSprite::GetCursorType() const
{
    return SprFlags & Flag_ButtonMode;
}

// @0x1424fa450
void MovieRoot::ExecuteActionQueues()
{
    for (unsigned lvl = 0; lvl < AL_Count_; ++lvl)
    {
        ActionQueueIterator iter(ActionLevel(lvl), &ActionQueue);
        while (const ActionEntry* entry = iter.getNext())
            entry->Execute(this);
    }
}

void Sfr34_ModifyOptimizedPlayList(InteractiveObject* p);

// Creates the timeline children of frame 0 once: the sprite joins the playlist when its parent is on it, gets its
// load event and runs the init actions of frame 0.
// @0x1424f3320
void AvmSprite::CreateChildren()
{
    if (SprFlags & Flag_ChildrenCreated)
        return;
    Sprite* spr = GetSprite();
    if (!spr->IsInPlayList() && spr->GetParent() && spr->GetParent()->IsInPlayList())
    {
        if (spr->GetParent())
            GetAvmParent()->InsertChildToPlayList(spr);
        else
            spr->AddToPlayList();
        Sfr34_ModifyOptimizedPlayList(spr);
    }
    if (!(spr->Flags & Sprite::Flags_OnEventLoadCalled))
        spr->DefaultOnEventLoad();
    if (spr->HasAvmObject())
        spr->GetAvmSprite()->ExecuteInitActionFrameTags(0);
    SprFlags |= Flag_ChildrenCreated;
}

// ToInt32 of ECMA-262: NaN, infinities and zeros give 0, everything else is truncated modulo 2^32.
// @0x1424f1d60
SInt32 ConvertDouble2SInt32(Double v)
{
    if (NumberUtil::IsNaNOrInfinity(v) || NumberUtil::IsNEGATIVE_ZERO(v) || NumberUtil::IsPOSITIVE_ZERO(v))
        return 0;
    Double result = v < 0.0 ? ::floor(-v) : ::floor(v);
    if (result > 4294967295.0)
        result = ::fmod(result, 4294967296.0);
    if (result >= (Double)2147483648.0)
    {
        const SInt32 tmp = SInt32(result - 2147483648.0);
        if (v < 0.0)
            return 0x80000000 - tmp;
        else
            return 0x80000000 + tmp;
    }
    else
        return SInt32(v < 0.0 ? -result : result);
}

// The thunk of a method 4.1.18 does not implement: a warning naming it.
// @0x1424f9480
void ThunkInfo::EmptyFunc(const ThunkInfo& ti, VM& vm, const Value&, Value&, unsigned, const Value*)
{
    String msg("The method ");
    if (ti.NamespaceName)
    {
        msg += ti.NamespaceName;
        msg += "::";
    }
    if (ti.Name)
    {
        msg += ti.Name;
        msg += "()";
    }
    msg += " is not implemented\n";
    vm.GetUI().Output(FlashUI::Output_Warning, msg.ToCStr());
}

// Calls func; an exception it raises is printed and dropped.
// MS2-FUNCTIONAL: same call and exception reset; the exception branch is laid out inline in the exe.
// @0x142500620
void VM::Execute_IgnoreExceptionUnsafe(const Value& func, const Value& _this, Value& result, unsigned argc,
                                       const Value* argv)
{
    ExecuteInternalUnsafe(func, _this, result, argc, argv, false);
    if (IsException())
    {
        HandleException = false;
        OutputError(ExceptionObj);
        ExceptionObj.SetUndefined();
    }
}

// @0x142502c30
const UInt32* Slots::FindSlotValues(const ASString& k) const
{
    return Set.Get(Ptr<ASStringNode>(k.GetNode()));
}

// @0x1425009e0
SlotInfo& Slots::FindAddOwnSlotInfo(const ASString& k, const SlotInfo& v, AbsoluteIndex& ind)
{
    ind = FindSlotInfoIndex(k, *v.pNs);
    if (!ind.IsValid())
        ind = Add(k, v);
    return GetOwnSlotInfo(ind);
}

// Slots::GetSlotInfo (sfr_as3_04 0x142416fb0), one level inline here as in the exe.
static SF_INLINE const SlotInfo& Sfr17GetSlotInfo(const Slots& s, AbsoluteIndex ind)
{
    if (ind < s.FirstOwnSlotNum)
        return s.Parent->GetSlotInfo(ind);
    return s.VArray[static_cast<UInt32>(ind.Get()) - s.FirstOwnSlotNum].Value;
}

// @0x142502b20
__declspec(noinline) AbsoluteIndex Slots::FindSlotInfoIndex(const ASString& k, const Instances::Namespace& ns) const
{
    if (const UInt32* values = FindSlotValues(k))
    {
        const Abc::NamespaceKind kind = ns.GetKind();
        SPInt ind = *values;
        do
        {
            const Instances::Namespace& sns = *Sfr17GetSlotInfo(*this, AbsoluteIndex(ind)).pNs;
            if (sns.GetKind() == kind)
            {
                switch (kind)
                {
                case Abc::NS_Protected:
                    return AbsoluteIndex(ind);
                case Abc::NS_Private:
                    if (&ns == &sns)
                        return AbsoluteIndex(ind);
                    break;
                default:
                    if (sns.GetUri().GetNode() == ns.GetUri().GetNode())
                        return AbsoluteIndex(ind);
                    break;
                }
            }
            if (static_cast<UPInt>(ind) < FirstOwnSlotNum)
                ind = Parent->GetPrevSlotIndex(ind);
            else
                ind = VArray[static_cast<UPInt>(ind) - FirstOwnSlotNum].Prev;
        } while (ind >= 0);
    }
    return AbsoluteIndex(-1);
}

// @0x142502dc0
// noinline: FindDynamicSlot calls it in both of its loops.
__declspec(noinline) const SPInt* SlotContainerType::FindValues(const ASString& k) const
{
    return KVHashSet.Get(k.GetNode());
}

// The SDK form (a named node, the Add arm first) gives the exe's cmov iterator.
// @0x1425008e0
AbsoluteIndex SlotContainerType::FindAdd(const ASString& k, const SlotInfo& v)
{
    AbsoluteIndex result(-1);

    ASStringNode* node = k.GetNode();
    SetType::Iterator it = KVHashSet.Find(node);
    if (it.IsEnd())
        result = Add(k, v);
    else
        result = AbsoluteIndex(it->Second);

    return result;
}

// @0x142500dd0
const SlotInfo* FindDynamicSlot(const SlotContainerType& c, const ASString& k, const Instances::Namespace& ns)
{
    const SPInt* values = c.FindValues(k);
    if (values)
    {
        for (SPInt ind = *values; ind >= 0; ind = c.VArray[ind].Prev)
        {
            const SlotInfo& si = c.VArray[static_cast<UInt32>(ind)].Value;
            if (*si.pNs == ns)
                return &si;
        }
    }
    return NULL;
}

// The value's collectable and closure object slots (out of line in the 4.2 SDK, inlined in the exe).
inline GASRefCountBase** Value::AsGASRefCountBasePtrPtr() const
{
    switch (GetKind())
    {
    case kFunction:
    case kThunkFunction:
    case kObject:
    case kClass:
    case kNamespace:
        return (GASRefCountBase**)(&value.VS._1.VObj);
    default:
        break;
    }
    return NULL;
}
inline GASRefCountBase** Value::AsClosurePtrPtr() const
{
    return (GASRefCountBase**)(&value.VS._2.VObj);
}

// Visits the collectable a value holds.
// @0x142504530
void ForEachChild_GC_Internal(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const Value& v,
                              ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    typedef void (*GcOpWithOwner)(RefCountCollector<StatMV_ActionScript_Mem>*, const ASRefCountBaseType**,
                                  const ASRefCountBaseType&);
    switch (v.GetKind())
    {
    case Value::kFunction:
    case Value::kObject:
    case Value::kClass:
    case Value::kThunkFunction:
    case Value::kNamespace:
        if (v.GetGASRefCountBase())
            reinterpret_cast<GcOpWithOwner>(op)(prcc, (const ASRefCountBaseType**)v.AsGASRefCountBasePtrPtr(), owner);
        break;
    case Value::kThunkClosure:
    case Value::kVTableIndClosure:
        if (v.GetClosure())
            reinterpret_cast<GcOpWithOwner>(op)(prcc, (const ASRefCountBaseType**)v.AsClosurePtrPtr(), owner);
        break;
    default:
        break;
    }
}

SF_INLINE void ForEachChild_GC(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const Value& v,
                               ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    if (v.IsGarbageCollectable() && !v.IsWeakRef())
        ForEachChild_GC_Internal(prcc, v, op, owner);
}

// @0x142503b50
void SlotInfo::ForEachChild_GC(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const Object& obj,
                               ASRefCountBaseType::GcOp op) const
{
    typedef void (*GcOpWithOwner)(RefCountCollector<StatMV_ActionScript_Mem>*, const ASRefCountBaseType**,
                                  const ASRefCountBaseType&);
    switch (BindType)
    {
    case BT_ValueArray:
        // the global object's value array (GlobalObjectCPP +0xa8; its members are not modelled yet)
        AS3::ForEachChild_GC(prcc, (*reinterpret_cast<Value* const*>(reinterpret_cast<const char*>(&obj) + 0xa8))[static_cast<UInt32>(ValueInd)],
                             op, obj);
        break;
    case BT_Value:
        AS3::ForEachChild_GC(prcc, *reinterpret_cast<const Value*>(reinterpret_cast<const char*>(&obj) + ValueInd),
                             op, obj);
        break;
    case BT_ObjectAS:
        {
            // a tagged pointer: the collector sees it untagged, the tag bits are kept
            UPInt& ptr = *reinterpret_cast<UPInt*>(const_cast<char*>(reinterpret_cast<const char*>(&obj)) + ValueInd);
            const UPInt raw = ptr;
            if (raw)
            {
                const ASRefCountBaseType* child = reinterpret_cast<const ASRefCountBaseType*>(raw & ~(UPInt)6);
                reinterpret_cast<GcOpWithOwner>(op)(prcc, &child, obj);
                ptr = reinterpret_cast<UPInt>(child) | (raw & 6);
            }
        }
        break;
    case BT_ObjectCpp:
        {
            const ASRefCountBaseType** pchild = reinterpret_cast<const ASRefCountBaseType**>(
                const_cast<char*>(reinterpret_cast<const char*>(&obj)) + ValueInd);
            if (*pchild)
                reinterpret_cast<GcOpWithOwner>(op)(prcc, pchild, obj);
        }
        break;
    default:
        break;
    }
}

// Slots::GetSlotInfo as the exe inlines it here.
static SF_INLINE const SlotInfo& Sfr33GetSlotInfo(const Slots& slots, AbsoluteIndex ind)
{
    if (ind < slots.FirstOwnSlotNum)
        return slots.Parent->GetSlotInfo(ind);
    return slots.VArray[static_cast<UInt32>(ind.Get()) - slots.FirstOwnSlotNum].Value;
}

// The SDK loop over AbsoluteIndex values (count and index), which gives the exe's register use.
// @0x142503ce0
void Traits::ForEachChild_GC(Collector* prcc, const Object& obj, GcOp op) const
{
    AbsoluteIndex count(GetSlotInfoNum());
    for (AbsoluteIndex i(0); i.Get() < count.Get(); i = AbsoluteIndex(i.Get() + 1))
        Sfr33GetSlotInfo(*this, i).ForEachChild_GC(prcc, obj, op);
}

// @0x142505cc0
SPtr<Instances::fl_display::DisplayObject> AvmDisplayObjContainer::GetAS3ChildAt(unsigned index)
{
    DisplayObjectBase* ch = GetDisplayObjContainer()->GetChildAt(index);
    if (ch)
    {
        AvmDisplayObj* pavm = ToAvmDisplayObj(ch);
        pavm->CreateASInstance(true);
        return pavm->GetAS3Obj();
    }
    return NULL;
}

// @0x142505d40
SPtr<Instances::fl_display::DisplayObject> AvmDisplayObjContainer::GetAS3ChildByName(const ASString& name)
{
    DisplayObject* ch = GetDisplayObjContainer()->mDisplayList.GetDisplayObjectByName(name, true);
    if (ch)
    {
        AvmDisplayObj* pavm = ToAvmDisplayObj(ch);
        pavm->CreateASInstance(true);
        return pavm->GetAS3Obj();
    }
    return NULL;
}

// ---- the core class objects (built on demand by their instance traits) ----

// @0x142507df0
Classes::fl::Array& VM::GetClassArray() const
{
    return reinterpret_cast<Classes::fl::Array&>(TraitsArray->GetInstanceTraits().GetConstructor());
}

// @0x142507e30
Classes::fl::Boolean& VM::GetClassBoolean() const
{
    return reinterpret_cast<Classes::fl::Boolean&>(TraitsBoolean->GetInstanceTraits().GetConstructor());
}

// @0x142507e70
Classes::fl::int_& VM::GetClassSInt() const
{
    return reinterpret_cast<Classes::fl::int_&>(TraitsInt->GetInstanceTraits().GetConstructor());
}

// @0x142507eb0
Classes::fl::Number& VM::GetClassNumber() const
{
    return reinterpret_cast<Classes::fl::Number&>(TraitsNumber->GetInstanceTraits().GetConstructor());
}

// @0x142507ef0
Classes::fl::String& VM::GetClassString() const
{
    return reinterpret_cast<Classes::fl::String&>(TraitsString->GetInstanceTraits().GetConstructor());
}

// @0x142508100
Classes::fl::uint& VM::GetClassUInt() const
{
    return reinterpret_cast<Classes::fl::uint&>(TraitsUint->GetInstanceTraits().GetConstructor());
}

// @0x1425081f0
SF_NOINLINE Class& VM::GetClassVector() const
{
    return TraitsVector->GetInstanceTraits().GetConstructor();
}

// @0x142508230
Class& VM::GetClassVectorNumber() const
{
    return TraitsVector_double->GetInstanceTraits().GetConstructor();
}

// @0x142508270
Class& VM::GetClassVectorSInt() const
{
    return TraitsVector_int->GetInstanceTraits().GetConstructor();
}

// @0x1425082b0
Class& VM::GetClassVectorString() const
{
    return TraitsVector_String->GetInstanceTraits().GetConstructor();
}

// @0x1425082f0
Class& VM::GetClassVectorUInt() const
{
    return TraitsVector_uint->GetInstanceTraits().GetConstructor();
}

// AvmStage's default AS3 class name (an AvmStage vftable slot).
// MS2-FUNCTIONAL: the literal is ours, not the exe's 0x14317d870 copy
// @0x142508960
const char* FUN_142508960(const void*) { return "flash.display.Stage"; }

// The class traits of v's type: the boxed class for primitives, Function for closures and thunks, the class of
// the object otherwise (Object for null).
// @0x142507f60
const ClassTraits::Traits& VM::GetClassTraits(const Value& v) const
{
    switch (v.GetKind())
    {
    case Value::kBoolean:
        return GetClassTraitsBoolean();
    case Value::kInt:
        return GetClassTraitsSInt();
    case Value::kUInt:
        return GetClassTraitsUInt();
    case Value::kNumber:
        return GetClassTraitsNumber();
    case Value::kString:
        if (v.GetStringNode())
            return GetClassTraitsString();
        return GetClassTraitsObject();
    case Value::kClass:
        return v.AsClass().GetClassTraits();
    case Value::kNamespace:
        return GetClassTraitsNamespace();
    case Value::kThunk:
    case Value::kVTableInd:
    case Value::kFunction:
    case Value::kThunkFunction:
    case Value::kThunkClosure:
    case Value::kVTableIndClosure:
        return GetClassTraitsFunction();
    case Value::kClassTraits:
        return v.GetClassTraits();
    default:
        break;
    }
    if (v.GetObject())
        return v.GetObject()->GetTraits().GetConstructor().GetClassTraits();
    return GetClassTraitsObject();
}

// The unit-local Sfr33GetSlotInfo keeps SlotInfo::ForEachChild_GC (0x142503b50) out of line, as in the exe.
// @0x142504580
void Traits::ForEachChild_GC_Slot(Collector* prcc, const Object& obj, GcOp op) const
{
    const UPInt size = GetSlotInfoNum();
    for (UPInt i = 0; i < size; ++i)
        Sfr33GetSlotInfo(*this, AbsoluteIndex(i)).ForEachChild_GC(prcc, obj, op);
}

// Visits a counted pointer member for owner (the exe's GcOp takes the owner as a third argument).
template <class T>
SF_INLINE void Sfr33GcPtr(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const SPtr<T>& p,
                          ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    typedef void (*GcOpWithOwner)(RefCountCollector<StatMV_ActionScript_Mem>*, const ASRefCountBaseType**,
                                  const ASRefCountBaseType&);
    if (p.GetPtr())
        reinterpret_cast<GcOpWithOwner>(op)(
            prcc, (const ASRefCountBaseType**)(p.GetRawPtr()), owner);
}

// Traits::ForEachChild_GC: the file, namespace and class of every own slot, the class object, the parent, the
// method table's values and the stored scope.
// @0x142503d90
void Traits::ForEachChild_GC(Collector* prcc, GcOp op) const
{
    const UPInt n = VArray.GetSize();
    for (UPInt i = 0; i < n; ++i)
    {
        const SlotInfo& si = VArray[i].Value;
        Sfr33GcPtr(prcc, si.File, op, *this);
        Sfr33GcPtr(prcc, si.pNs, op, *this);
        Sfr33GcPtr(prcc, si.CTraits, op, *this);
    }
    Sfr33GcPtr(prcc, pConstructor, op, *this);
    Sfr33GcPtr(prcc, pParent, op, *this);
    if (const VTable* vt = pVTable.GetPtr())
    {
        const UPInt m = vt->VTMethods.GetSize();
        for (UPInt i = 0; i < m; ++i)
            AS3::ForEachChild_GC(prcc, vt->VTMethods[i], op, vt->GetTraits());
    }
    for (UPInt i = 0; i < InitScope.GetSize(); ++i)
        AS3::ForEachChild_GC(prcc, InitScope[i], op, *this);
}

// AbcMultinameHash::ForEachChild_GC as the SDK has it (a ConstIterator walk over Entries, non-null values visited).
template <class H>
static __forceinline void Sfr33GcHash(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const H& h,
                                      ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    typedef void (*GcOpWithOwner)(RefCountCollector<StatMV_ActionScript_Mem>*, const ASRefCountBaseType**,
                                  const ASRefCountBaseType&);
    typename H::ConstIterator it = h.Begin();
    while (!it.IsEnd())
    {
        const typename H::ValueType& v = it->Second;
        if (v)
            reinterpret_cast<GcOpWithOwner>(op)(prcc, (const ASRefCountBaseType**)(v.GetRawPtr()), owner);
        ++it;
    }
}

// The same walk over a hash set of counted pointers (the element itself is visited).
template <class H>
static __forceinline void Sfr33GcHashSet(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const H& h,
                                         ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    typedef void (*GcOpWithOwner)(RefCountCollector<StatMV_ActionScript_Mem>*, const ASRefCountBaseType**,
                                  const ASRefCountBaseType&);
    typename H::ConstIterator it = h.Begin();
    while (!it.IsEnd())
    {
        const auto& v = *it;
        if (v)
            reinterpret_cast<GcOpWithOwner>(op)(prcc, (const ASRefCountBaseType**)(v.GetRawPtr()), owner);
        ++it;
    }
}

// Views of the raw table members: HashSetLH<SPtr<...>> (AbsObjects, GlobalObjects; 0x18-byte cached entries) and
// HashLH<UInt32, SPtr<...>> (the activation and function traits caches; 0x20-byte cached node entries).
typedef HashSetLH<SPtr<GASRefCountBase> > Sfr33GcPtrSetView;
typedef HashLH<UInt32, SPtr<GASRefCountBase>, FixedSizeHash<UInt32> > Sfr33GcPtrMapView;

// VMAbcFile::ForEachChild_GC: the interned namespaces, the absolute objects, the namespace sets, the global
// objects, the child files, the activation and function traits caches and the loaded classes.
// @0x142503ff0
void VMAbcFile::ForEachChild_GC(Collector* prcc, GcOp op) const
{
    Sfr33GcHash(prcc, IntNamespaces.Entries, op, *this);
    Sfr33GcHashSet(prcc, reinterpret_cast<const Sfr33GcPtrSetView&>(AbsObjectsTable), op, *this);
    for (UPInt i = 0, n = IntNamespaceSets.GetSize(); i < n; ++i)
        Sfr33GcPtr(prcc, IntNamespaceSets[i], op, *this);
    Sfr33GcHashSet(prcc, reinterpret_cast<const Sfr33GcPtrSetView&>(GlobalObjectsTable), op, *this);
    for (UPInt i = 0, n = Children.GetSize(); i < n; ++i)
        Sfr33GcPtr(prcc, Children[i], op, *this);
    Sfr33GcHash(prcc, reinterpret_cast<const Sfr33GcPtrMapView&>(ActivationTraitsCacheTable), op, *this);
    Sfr33GcHash(prcc, reinterpret_cast<const Sfr33GcPtrMapView&>(FunctionTraitsCacheTable), op, *this);
    for (UPInt i = 0, n = LoadedClasses.GetSize(); i < n; ++i)
        Sfr33GcPtr(prcc, LoadedClasses[i], op, *this);
}

// The movie root's per-event lists of the display objects that listen to a frame/activation event (+0x150 of
// MovieRoot); only Dispatch lives here.
class EventChains
{
public:
    typedef ArrayLH<WeakPtr<DisplayObject>, 2> ChainType;
    typedef HashNode<int, AutoPtr<ChainType>, IdentityHash<int> > NodeType;
    typedef HashLH<int, AutoPtr<ChainType>, IdentityHash<int>, 2, NodeType,
                   HashsetNodeEntry<NodeType, NodeType::NodeHashF> > ChainsType;

    void Dispatch(EventId::IdCode code);

private:
    UPInt FindObjectIndexInChain(ChainType* chain, DisplayObject* obj);

public:

    ChainsType Chains;
};

// Fires the event code on every live object of its chain; dead entries are dropped on the way.
// @0x1424f71b0
void EventChains::Dispatch(EventId::IdCode code)
{
    AutoPtr<ChainType>* pchain = Chains.Get(code);
    if (!pchain)
        return;
    ChainType& chain = **pchain;
    for (UPInt i = 0; i < chain.GetSize();)
    {
        if (chain[i] == static_cast<DisplayObject*>(0))
        {
            chain.RemoveAt(i);
            continue;
        }
        EventId id(code);
        Ptr<DisplayObject> ch = chain[i];
        FUN_142502e70(ch ? ToAvmDisplayObj(ch) : 0, id);
        ++i;
    }
}

// Object::ForEachChild_GC: the dynamic property values, the values bound in the traits' slots, then the traits.
// The traits visit goes through Sfr33GcPtr, as in the SDK's ForEachChild_GC(prcc, pTraits, op), so the second
// null test reads pTraits again.
// @0x1425038d0
void Object::ForEachChild_GC(Collector* prcc, GcOp op) const
{
    for (DynAttrsType::ConstIterator it = DynAttrs.Begin(); !it.IsEnd(); ++it)
        AS3::ForEachChild_GC(prcc, it->Second, op, *this);
    if (pTraits)
        pTraits->ForEachChild_GC_Slot(prcc, *this, op);
    Sfr33GcPtr(prcc, pTraits, op, *this);
}
}}}

// ---- sfr33: MovieRoot / Stage helpers ----
// AS3 Event class's object factory (unrecovered).
// the AS3 MovieDefRootNode vftable
extern "C" const void* DAT_14317d8c0;

namespace Scaleform { namespace GFx { namespace AS3 {

// @0x1424ef9e0
void MovieRoot::ActionQueueType::Clear()
{
    for (unsigned i = 0; i < AL_Total; ++i)
    {
        ActionQueueIterator iter(static_cast<ActionLevel>(i), this);
        while (iter.getNext())
            ;
    }
}

// MovieRoot::StickyVarNode::Assign (virtual): name, permanence and value of node. The AS3 node is not modelled.
// @0x1424ed890
void Sfr33StickyVarNodeAssign(UByte* self, const UByte* node)
{
    *reinterpret_cast<ASString*>(self + 0x08) = *reinterpret_cast<const ASString*>(node + 0x08);
    self[0x18] = node[0x18];
    reinterpret_cast<Value*>(self + 0x20)->Assign(*reinterpret_cast<const Value*>(node + 0x20));
}

// MovieRoot::CreateMovieDefRootNode (virtual): the AS3 MovieDefRootNode (0x58 bytes; +0x38..+0x50 cleared).
// The AS3 MovieDefRootNode class is not modelled: its constructor stores the exe's vftable raw.
static inline UByte* Sfr33ConstructAS3MovieDefRootNode(UByte* p, MovieDefImpl* pdefImpl, bool importFlag)
{
    *reinterpret_cast<unsigned*>(p + 0x18) = 1;
    *reinterpret_cast<MovieDefImpl**>(p + 0x20) = pdefImpl;
    p[0x30] = importFlag;
    *reinterpret_cast<void**>(p + 0x38) = NULL;
    *reinterpret_cast<const void**>(p) = &DAT_14317d8c0;
    *reinterpret_cast<void**>(p + 0x40) = NULL;
    *reinterpret_cast<void**>(p + 0x48) = NULL;
    *reinterpret_cast<void**>(p + 0x50) = NULL;
    return p;
}
// @0x1424f3910
void* Sfr33MovieRootCreateMovieDefRootNode(MovieRoot* self, MemoryHeap* pheap, MovieDefImpl* pdefImpl, bool importFlag)
{
    UByte* p = static_cast<UByte*>(pheap->Alloc(0x58));
    return p ? Sfr33ConstructAS3MovieDefRootNode(p, pdefImpl, importFlag) : NULL;
}

// The stage has no instance name: the empty string (of the movie's string manager, pASRoot->pMovieImpl+0x18).
// @0x1424f3980
ASString Stage::CreateNewInstanceName() const
{
    typedef UByte* (*GetStringManagerFn)(void*);
    void* obj = *reinterpret_cast<void* const*>(*reinterpret_cast<const UByte* const*>(
                    *reinterpret_cast<const UByte* const*>(reinterpret_cast<const UByte*>(this) + 0x20) + 0x10) + 0x18);
    UByte* mgr = (*reinterpret_cast<GetStringManagerFn const* const*>(obj))[50](obj);
    return ASString(reinterpret_cast<ASStringNode*>(mgr + 0x40));   // the manager's empty string node
}

// MovieRoot::CreateEventObject (virtual)
// @0x1424f3710
void* Sfr33MovieRootCreateEventObject(MovieRoot* self, void* ret, const ASString& type, bool bubbles, bool cancelable)
{
    typedef void (*Fn)(MovieRoot*);
    (*reinterpret_cast<Fn const* const*>(self))[4](self);
    ::new (ret) SPtr<Instances::fl_events::Event>(
        (*reinterpret_cast<Classes::fl_events::EventDispatcher* const*>(reinterpret_cast<const UByte*>(self->pAVM) + 0x390))
            ->CreateEventObject(type, bubbles, cancelable));
    return ret;
}
}}}

namespace Scaleform { namespace GFx {
// The host side of AS3 values (GFx::Value object calls); only the members recovered so far. pdata is the
// AS3 object; the display object calls apply to instances of the display object classes.
class AS3ValueObjectInterface : public Value::ObjectInterface
{
private:
    virtual bool GetCxform(void* pdata, Render::Cxform* pcx) const;
    virtual bool GetDisplayMatrix(void* pdata, Render::Matrix2F* pmat) const;
    virtual unsigned GetArraySize(void* pdata) const;
    virtual AMP::ViewStats* GetAdvanceStats() const;
    virtual bool GetElement(void* pdata, unsigned idx, Value* pval) const;
    virtual bool DeleteMember(void* pdata, const char* name, bool isdobj);
    virtual bool CreateObjectValue(Value* pval, void* pdata, bool isdobj);
};
}} // namespace Scaleform::GFx

// VM: runs the queued class constructors (unrecovered).
// the AS3 ObjectInterface (AS3ValueObjectInterface) vftable
extern "C" const void* DAT_14317eff8;

extern "C" const void* DAT_14317ef38[];      // UserDefinedFunction vftable
int FUN_140ccaae0(const char* fmt, ...);   // log printf

namespace Scaleform { namespace GFx { namespace AS3 {

// MovieRoot stand-in for the virtuals whose register use depends on being members.
struct Sfr33MovieRoot
{
    MovieRoot* Root() { return reinterpret_cast<MovieRoot*>(this); }
    Sprite* CreateMovieClip(CharacterDef* pdef, MovieDefImpl* pdefImpl, InteractiveObject* parent, ResourceId id,
                            bool loadedSeparately);
    Sprite* CreateSprite(CharacterDef* pdef, MovieDefImpl* pdefImpl, InteractiveObject* parent, ResourceId id,
                         bool loadedSeparately);    void CreateFunction(GFx::Value* pvalue, FunctionHandler* pfc, void* puserData);    void CreateObject(GFx::Value* pvalue, const char* className, const GFx::Value* pargs, unsigned nargs);
};

// MovieRoot::CreateMovieClip (virtual): a sprite of type MovieClip, flagged as a movie clip at +0x6a.
// @0x1424f38a0
Sprite* Sfr33MovieRoot::CreateMovieClip(CharacterDef* pdef, MovieDefImpl* pdefImpl, InteractiveObject* parent,
                                        ResourceId id, bool loadedSeparately)
{
    CharacterCreateInfo ccinfo = { pdef, pdefImpl, NULL };
    DisplayObjectBase* pdo = Root()->pASSupport->CreateCharacterInstance
        (Root()->GetMovieImpl(), ccinfo, parent, id, static_cast<CharacterDef::CharacterDefType>(3));
    Sprite* pspr = static_cast<Sprite*>(pdo);
    pspr->SetLoadedSeparately(loadedSeparately);
    *reinterpret_cast<UInt16*>(reinterpret_cast<UByte*>(pspr) + 0x6a) |= 0x800;
    return pspr;
}

// MovieRoot::CreateSprite (virtual)
// @0x1424f3f90
Sprite* Sfr33MovieRoot::CreateSprite(CharacterDef* pdef, MovieDefImpl* pdefImpl, InteractiveObject* parent,
                                     ResourceId id, bool loadedSeparately)
{
    CharacterCreateInfo ccinfo = { pdef, pdefImpl, NULL };
    DisplayObjectBase* pdo = Root()->pASSupport->CreateCharacterInstance
        (Root()->GetMovieImpl(), ccinfo, parent, id, static_cast<CharacterDef::CharacterDefType>(9));
    Sprite* pspr = static_cast<Sprite*>(pdo);
    pspr->SetLoadedSeparately(loadedSeparately);
    return pspr;
}

// MovieRoot::CreateFunction (virtual): wraps the handler in a user-defined function object (0x50 bytes: FunctionBase,
// then +0x40 the handler, +0x48 the user data) and returns it as a GFx value.
static inline UByte* Sfr33ConstructUserDefinedFunction(void* addr, InstanceTraits::Traits& t, FunctionHandler* pfc, void* puserData)
{
    UByte* pf = static_cast<UByte*>(addr);
    Scaleform::GFx::AS3::Sfr17FunctionBaseAccess::Construct(pf, t);
    *reinterpret_cast<const void**>(pf) = DAT_14317ef38;
    Ptr<FunctionHandler>* pcontext = ::new (pf + 0x40) Ptr<FunctionHandler>();
    *pcontext = pfc;
    *reinterpret_cast<void**>(pf + 0x48) = puserData;
    return pf;
}

// @0x1424f3780
void Sfr33MovieRoot::CreateFunction(GFx::Value* pvalue, FunctionHandler* pfc, void* puserData)
{
    void* addr = (*reinterpret_cast<ASVM**>(reinterpret_cast<UByte*>(this) + 0x48))->GetMemoryHeap()->Alloc(0x50);
    UByte* pf = addr ? Sfr33ConstructUserDefinedFunction(addr, (*reinterpret_cast<ASVM**>(reinterpret_cast<UByte*>(this) + 0x48))->GetClassTraitsFunction().GetInstanceTraits(), pfc, puserData) : NULL;
    Value asval;
    asval.PickUnsafe(reinterpret_cast<Instances::FunctionBase*>(pf));
    Root()->ASValue2GFxValue(asval, pvalue);
}

// Storage for a Value whose dtor expands Value::ReleaseInternal (out of line in sfr_as3_18) in place.
struct Sfr33InlineReleaseValue
{
    union
    {
        UPInt Align;
        UByte Buf[sizeof(Value)];
    };
    Value& Get() { return *reinterpret_cast<Value*>(Buf); }
    static void ReleaseGC(Object* p)
    {
        if (!(reinterpret_cast<UPInt>(p) & 1) && p)
            p->Release();
    }
    __forceinline ~Sfr33InlineReleaseValue()
    {
        Value& v = Get();
        if (!v.IsRefCounted())
            return;
        if (v.IsWeakRef())
        {
            (*reinterpret_cast<WeakProxy**>(Buf + 0x08))->Release();
            return;
        }
        switch (v.GetKind())
        {
        case Value::kString:
            (*reinterpret_cast<ASStringNode**>(Buf + 0x10))->Release();
            break;
        case Value::kNamespace:
            ReleaseGC(*reinterpret_cast<Object**>(Buf + 0x10));
            break;
        case Value::kObject:
            ReleaseGC(*reinterpret_cast<Object**>(Buf + 0x10));
            break;
        case Value::kClass:
            ReleaseGC(*reinterpret_cast<Object**>(Buf + 0x10));
            break;
        case Value::kFunction:
            ReleaseGC(*reinterpret_cast<Object**>(Buf + 0x10));
            break;
        case Value::kThunkFunction:
            ReleaseGC(*reinterpret_cast<Object**>(Buf + 0x10));
            break;
        case Value::kThunkClosure:
            ReleaseGC(*reinterpret_cast<Object**>(Buf + 0x18));
            break;
        case Value::kVTableIndClosure:
            ReleaseGC(*reinterpret_cast<Object**>(Buf + 0x18));
            break;
        default:
            break;
        }
    }
};

// MovieRoot::CreateObject (virtual): a new instance of the global class className ("Object" when none), constructed
// with the host values pargs; a pending exception is printed and dropped. Up to 10 arguments live on the stack.
// @0x1424f39c0
void Sfr33MovieRoot::CreateObject(GFx::Value* pvalue, const char* className, const GFx::Value* pargs, unsigned nargs)
{
    UByte buf[0x140 + 0x50];
    Value* args = nargs > 10 ? static_cast<Value*>(Memory::AllocAutoHeap(this, UPInt(nargs) << 5))
                             : reinterpret_cast<Value*>(buf);
    for (unsigned i = 0; i < nargs; ++i)
    {
        Value* pv = new (&args[i]) Value();
        Root()->GFxValue2ASValue(pargs[i], pv);
    }
    Sfr33InlineReleaseValue res;
    Value& result = *::new (res.Buf) Value();
    const bool ok = (*reinterpret_cast<VM**>(reinterpret_cast<UByte*>(this) + 0x48))
                        ->Construct(className ? className : "Object", result, nargs, args, false);
    VM* pvm = *reinterpret_cast<VM**>(reinterpret_cast<UByte*>(this) + 0x48);
    if (!pvm->HandleException)
    {
        if (ok)
            pvm->ExecuteCode(1);
    }
    else
    {
        FUN_140ccaae0("Exception in CreateObject(\"%s\"):\n\t", className);
        VM* vm = *reinterpret_cast<VM**>(reinterpret_cast<UByte*>(this) + 0x48);
        vm->HandleException = false;
        vm->OutputError(vm->ExceptionObj);
        vm->ExceptionObj.SetUndefined();
    }
    Root()->ASValue2GFxValue(result, pvalue);
    for (unsigned i = 0; i < nargs; ++i)
        args[i].~Value();
    if (nargs > 0x32)
        Memory::Free(args);
}

// MovieRoot::ExecuteCtors (virtual): when constructors are pending (+0x358), runs them and clears the VM's flag.
// @0x1424fe5b0
void Sfr33MovieRootExecuteCtors(UByte* self)
{
    const unsigned count = *reinterpret_cast<unsigned*>(self + 0x358);
    if (count)
    {
        (*reinterpret_cast<VM**>(self + 0x48))->ExecuteCode(count);
        UByte* vm = *reinterpret_cast<UByte**>(self + 0x48);
        if (vm[0x180])
            vm[0x180] = 0;
        *reinterpret_cast<int*>(self + 0x358) = 0;
    }
}

// MovieRoot::MouseState::GetDoubleClickInfo: the 12-byte record (+0x20) of the button of buttonMask.
// @0x142509920
void* Sfr33MouseStateGetDoubleClickInfo(UByte* self, unsigned buttonMask)
{
    static const unsigned ButtonIndex[] = { 0, 1, 2, 0, 3 };
    struct DoubleClickInfo { UInt32 Data[3]; };
    unsigned i;
    if (buttonMask > 4)
        i = static_cast<unsigned>(logf(static_cast<float>(buttonMask)));
    else
        i = ButtonIndex[buttonMask];
    return &reinterpret_cast<DoubleClickInfo*>(self + 0x20)[i];
}

// MovieRoot::CreateObjectInterface (virtual): the movie's AS3 value object interface (0x10 bytes, movie at +0x08).
// The interface class is not modelled here: its constructor stores the exe's vftable raw.
static inline void** Sfr33ConstructAS3ObjectInterface(void** p, MovieImpl* pmovieImpl)
{
    p[1] = pmovieImpl;
    p[0] = const_cast<void**>(&DAT_14317eff8);
    return p;
}
// @0x1424f3cd0
void Sfr33MovieRootCreateObjectInterface(MovieRoot* self, MovieImpl* pmovieImpl)
{
    MemoryHeap* pheap = *reinterpret_cast<MemoryHeap* const*>(reinterpret_cast<const UByte*>(self->pMovieImpl) + 0x40);
    void** p = static_cast<void**>(pheap->Alloc(0x10));
    *reinterpret_cast<void***>(reinterpret_cast<UByte*>(pmovieImpl) + 0x38) =
        p ? Sfr33ConstructAS3ObjectInterface(p, pmovieImpl) : NULL;
}

// ShapeObject::CreateRenderNode (virtual): the tree shape of the shape's definition, bound to its movie
// (GetResourceMovieDef, slot 60).
// @0x1424f3f40
Ptr<Render::TreeNode> ShapeObject::CreateRenderNode(Render::ContextImpl::Context& context) const
{
    return pDef->CreateTreeShape(context, GetResourceMovieDef());
}
//
//
//
//
//
//
//
//

// @0x1424f4a40
CheckResult Object::DeleteProperty(const Multiname& prop_name)
{
    if (GetTraits().IsDynamic())
        return DeleteDynamicSlotValuePair(prop_name);
    return false;
}
}}}

namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl_display {
class DisplayObject;
bool FindLibrarySymbol(const DisplayObject* name, CharacterCreateInfo* pccinfo, MovieDefImpl* pdefImpl);
} } } } }

namespace Scaleform { namespace GFx { namespace AS3 {

// Stops the frame counter, clears the display list (+0xd8), shuts the root movie clip down and drops it, then
// shuts the container down.
// @0x142504860
void Stage::ForceShutdown()
{
    UByte* self = reinterpret_cast<UByte*>(this);
    FrameCounterObj->RemoveFromPlayList();
    reinterpret_cast<DisplayList*>(self + 0xd8)->Clear(this);
    SetDirtyFlag();
    if (pRoot)
        pRoot->ForceShutdown();
    pRoot = NULL;
    DisplayObjContainer::ForceShutdown();
}

// GetFillStyle (shape-data virtual): copies 1-based fill style idx out of the fill array (+0x18).
// @0x142509cb0
void Sfr33ShapeDataGetFillStyle(const UByte* self, unsigned idx, Render::FillStyleType* p)
{
    *p = (*reinterpret_cast<Render::FillStyleType* const*>(self + 0x18))[idx - 1];
}

}}} // namespace Scaleform::GFx::AS3

// MovieRoot::FindLibrarySymbolInAllABCs: true when any loaded movie's ABCs define the library symbol.
// @0x142501a80
bool FUN_142501a80(Scaleform::GFx::ASMovieRootBase* proot, const Scaleform::GFx::AS3::Instances::fl::Object* name,
                   Scaleform::GFx::CharacterCreateInfo* pccinfo)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx;
    using namespace Scaleform::GFx::AS3;
    MovieRoot* self = reinterpret_cast<MovieRoot*>(proot);
    MovieDefRootNode* p = self->pMovieImpl->RootMovieDefNodes.pNext;
    for (;;)
    {
        MovieDefRootNodeLinks* proot = &self->pMovieImpl->RootMovieDefNodes;
        if (p == static_cast<MovieDefRootNode*>(proot))
            return false;
        if (Instances::fl_display::FindLibrarySymbol(reinterpret_cast<const Instances::fl_display::DisplayObject*>(name),
                                                     reinterpret_cast<CharacterCreateInfo*>(pccinfo), p->pDefImpl))
            return true;
        p = p->pNext;
    }
}

namespace Scaleform { namespace GFx { namespace AS3 {
}}}

Scaleform::GFx::AS3::ClassTraits::Traits** FUN_142414ac0(Scaleform::GFx::AS3::TClassTraitsCache* self, const Scaleform::GFx::ASString& name,
                                                       const Scaleform::GFx::AS3::Instances::Namespace& ns);   // TClassTraitsCache::Get(name, ns)
namespace Scaleform { namespace GFx { namespace AS3 { __declspec(noinline) const ArrayLH_POD<UPInt, StatMV_VM_AbcFile_Mem>& Sfr33CallFrameGetCode(CallFrame& cf); }}}
Scaleform::GFx::AS3::ClassTraits::Traits* FUN_142415520(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP* self, const Scaleform::GFx::ASString& name,
                                                     const Scaleform::GFx::AS3::Instances::Namespace& ns);   // GlobalObjectCPP: builtin class traits by name
static inline const Scaleform::GFx::AS3::ClassTraits::Traits* FUN_142525270(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Multiname& mn)
{ return reinterpret_cast<const Scaleform::GFx::AS3::ClassTraits::Traits*>(::Scaleform::GFx::AS3::Sfr31FindClassTraitsByMn(reinterpret_cast<Scaleform::UPInt>(&vm), reinterpret_cast<Scaleform::UPInt>(&mn))); }  // VM::Resolve2ClassTraits
extern "C" Scaleform::StringDataPtr DAT_143a2dd50;   // "Vector.<", the generic Vector prefix

namespace Scaleform { namespace GFx { namespace AS3 {

// AvmBitmap::GetASClassName (virtual)
// @0x142505ef0
String& Sfr33AvmBitmapGetASClassName(const void*, String* className)
{
    *className = "flash.display.Bitmap";
    return *className;
}

// @0x142505fa0
String& AvmLoader::GetASClassName(String* className) const
{
    *className = "flash.display.Loader";
    return *className;
}

// AvmStaticText::GetASClassName (virtual)
// @0x142505fd0
String& Sfr33AvmStaticTextGetASClassName(const void*, String* className)
{
    *className = "flash.text.StaticText";
    return *className;
}

// A copy of the name (+0x18) of the abc file at +0x28.
// @0x142505dd0
String VMAbcFile::GetAS3ObjectName() const
{
    const UByte* powner = *reinterpret_cast<const UByte* const*>(reinterpret_cast<const UByte*>(this) + 0x28);
    return *reinterpret_cast<const String*>(powner + 0x18);
}

// A Value holding an object, with Value(Object*) or Value(Class*) expanded in place as the exe has it: kind kObject or kClass, no weak
// proxy, the object word stored directly and the object AddRef'd.
struct Sfr17ObjectValue
{
    UInt32 Flags;
    void* pWeakProxy;
    Object* pObj;
    void* pRest;
    explicit Sfr17ObjectValue(Object* p, UInt32 kind = Value::kObject)
    {
        Flags = kind;
        pWeakProxy = NULL;
        pObj = p;
        if (p)
            p->AddRef();
    }
    ~Sfr17ObjectValue() { Get().~Value(); }
    Value& Get() { return *reinterpret_cast<Value*>(this); }
};

// StringDataPtr::GetTrimRight: the view without its last size bytes.
static inline StringDataPtr Sfr17TrimRight(const StringDataPtr& s, UPInt size)
{
    size = s.GetSize() < size ? s.GetSize() : size;
    return StringDataPtr(s.ToCStr(), s.GetSize() - size);
}

// "Vector.<T>" resolves T and applies it to Vector; any other name is looked up as a global class.
// MS2-FUNCTIONAL 0x142507be0: the exe re-reads the name size after the empty test and computes the head trim unfolded before the pointer test; same results
// @0x142507be0
Class* VM::GetClass(const StringDataPtr& gname)
{
    Class* _class = NULL;

    if (!gname.IsEmpty())
    {
        const StringDataPtr& vecPref = DAT_143a2dd50;

        if (gname.GetSize() > vecPref.GetSize() && Sfr17TrimRight(gname, gname.GetSize() - vecPref.GetSize()) == vecPref)
        {
            SPInt end = gname.FindLastChar('>');
            if (end > 0)
            {
                const StringDataPtr subtype_name(Sfr17TrimRight(gname.GetTrimLeft(vecPref.GetSize()), gname.GetSize() - end));
                Class* subtype_class = GetClass(subtype_name);

                if (subtype_class)
                {
                    Sfr17ObjectValue subtype_value(subtype_class, Value::kClass);
                    _class = &GetClassVector().ApplyTypeArgs(1, &subtype_value.Get());
                }
            }
        }
        else
        {
            const Multiname mn(*this, gname);
            ClassTraits::Traits* ctr = const_cast<ClassTraits::Traits*>(FUN_142525270(*this, mn));

            if (ctr)
            {
                ctr->InitOnDemand();

                if (!IsException())
                    _class = &ctr->GetInstanceTraits().GetConstructor();
            }
        }
    }

    return _class;
}

// The class traits the VM has cached under {name, ns}, NULL when absent.
// @0x142507f30
ClassTraits::Traits* Sfr33LookupHash1c8(VM* self, const ASString& name, const Instances::Namespace& ns)
{
    ClassTraits::Traits** p = FUN_142414ac0(&self->ClassTraitsSet, name, ns);
    if (!p)
        return NULL;
    return *p;
}

// MultinameHash<ClassTraits::Traits*>::Get(const Multiname&): the first namespace of a namespace set
// with an entry, else the entry under the multiname's single namespace.
// MS2-FUNCTIONAL 0x142505aa0: the exe keeps the name node in rbx across the call (ours reloads it from the slot) and saves rdi/r13 in another order in the loop; same results
// @0x142505aa0
ClassTraits::Traits** Sfr33ClassTraitsCacheGet(TClassTraitsCache* self, const Multiname& mn)
{
    if ((static_cast<UInt32>(mn.Kind) & 3) != Abc::MNF_NS_Multi)
    {
        ASString name = mn.Name.AsString();
        return FUN_142414ac0(self, name, static_cast<const Instances::Namespace&>(*mn.Obj));
    }
    const NamespaceSet& nss = static_cast<const NamespaceSet&>(*mn.Obj);
    const ArrayLH<SPtr<Instances::Namespace> >& nsa = nss.GetNamespaces();
    const UPInt n = nsa.GetSize();
    ClassTraits::Traits** p = NULL;
    for (UPInt i = 0; p == NULL && i < n; ++i)
    {
        ASString name = mn.Name.AsString();
        p = self->Entries.Get(TClassTraitsCache::Key(name, nsa[i].GetPtr()));
    }
    return p;
}

// The class traits mn names. A namespace set takes the first namespace with cached or builtin class traits
// (a builtin hit is cached); a single namespace goes through VM::Resolve2ClassTraits.
// MS2-FUNCTIONAL 0x142500a60: register allocation only: the exe keeps the index in rsi (zeroed at entry, also the n == 0 result) and ct in rdi, saved inside the n != 0 region
// @0x142500a60
ClassTraits::Traits* Sfr33ResolveMnClassTraits(VM* vm, const Multiname& mn)
{
    ClassTraits::Traits* ct = NULL;
    if ((static_cast<UInt32>(mn.Kind) & 3) <= Abc::MNF_NS_Runtime)
        return const_cast<ClassTraits::Traits*>(FUN_142525270(*vm, mn));
    const NamespaceSet& nss = static_cast<const NamespaceSet&>(*mn.Obj);
    const ArrayLH<SPtr<Instances::Namespace> >& nsa = nss.GetNamespaces();
    const UPInt n = nsa.GetSize();
    UPInt i = 0;
    if (n != 0) do
    {
        ASString name = mn.Name.AsString();
        const Instances::Namespace& ns = *nsa[i];
        ClassTraits::Traits** found = FUN_142414ac0(&vm->ClassTraitsSet, name, ns);
        if (found == NULL || (ct = *found) == NULL)
        {
            ClassTraits::Traits* made = FUN_142415520(vm->GlobalObject.GetPtr(), name, ns);
            ct = made;
            if (made != NULL)
                vm->ClassTraitsSet.Add(name, ns, made);
        }
    } while (ct == NULL && ++i < n);
    return ct;
}

// The value at +0x10, made by Sfr33CallFrameGetCode on first use.
// @0x142507a40
void* Sfr33CacheValue(UByte* self)
{
    void*& pvalue = *reinterpret_cast<void**>(self + 0x10);
    if (pvalue == NULL)
        pvalue = *reinterpret_cast<void* const*>(&Scaleform::GFx::AS3::Sfr33CallFrameGetCode(*reinterpret_cast<Scaleform::GFx::AS3::CallFrame*>(self)));
    return pvalue;
}

// Two lazy getters: +0x80 is made by virtual slot 13 on first use.
static inline void* Sfr33LazyGet80(void** self)
{
    void* p = self[0x10];
    if (!p)
    {
        typedef void (*MakeFn)(void*);
        reinterpret_cast<MakeFn*>(*self)[13](self);
        p = self[0x10];
    }
    return p;
}
// @0x142507b80
void* Sfr33LazyGet80a(void** self) { return Sfr33LazyGet80(self); }
// @0x142507bb0
void* Sfr33LazyGet80b(void** self) { return Sfr33LazyGet80(self); }

// The first entry of the array (+0x128 data, +0x130 size) of the object at +0x18, NULL when empty.
// @0x142509970
void* Sfr33FirstEntry(const UByte* self)
{
    const UByte* p = *reinterpret_cast<const UByte* const*>(self + 0x18);
    if (*reinterpret_cast<const UPInt*>(p + 0x130) > 0)
        return **reinterpret_cast<void** const*>(p + 0x128);
    return NULL;
}

// Virtual slot 9 of the object at +0x88, 0x38 without one.
// @0x142509d10
unsigned InstanceTraits::RTraits::GetFixedMemSize() const
{
    const UByte* self = reinterpret_cast<const UByte*>(this);
    void** p = *reinterpret_cast<void** const*>(self + 0x88);
    if (p)
    {
        typedef unsigned (*Fn)(void*);
        return reinterpret_cast<Fn*>(*p)[9](p);
    }
    return 0x38;
}
}}}


namespace Scaleform { namespace GFx { namespace AS3 {

// Tracer::CanBeNull: values of the int, uint, Number and Boolean instance traits are never null.
// @0x1424eea80
Value::TraceNullType Tracer::CanBeNull(const InstanceTraits::Traits& traits) const
{
    if (&traits == &GetSIntType() || &traits == &GetUIntType() || &traits == &GetNumberType() ||
        &traits == &GetBooleanType())
        return Value::NotNull;
    return Value::NullOrNot;
}

typedef void (*Sfr33GcOp)(void* prcc, void* pchild, void* powner);

// ForEachChild_GC (virtual) of an object with collectable children at +0x38 and +0x48.
// @0x142503800
void Class::ForEachChild_GC(Collector* prcc, GcOp gcop) const
{
    UByte* self = reinterpret_cast<UByte*>(const_cast<Class*>(this));
    const Sfr33GcOp op = reinterpret_cast<Sfr33GcOp>(gcop);
    reinterpret_cast<Object*>(self)->Object::ForEachChild_GC(reinterpret_cast<RefCountCollector<323>*>(prcc), reinterpret_cast<void (*)(RefCountCollector<323>*, const RefCountBaseGC<323>**)>(op));
    if (*reinterpret_cast<void**>(self + 0x38))
        op(prcc, self + 0x38, self);
    if (*reinterpret_cast<void**>(self + 0x48))
        op(prcc, self + 0x48, self);
}

// Two ForEachChild_GC (virtual) copies of objects with a collectable child at +0xc0.
static inline void Sfr33ForEachChildGC_c0(UByte* self, void* prcc, Sfr33GcOp op)
{
    reinterpret_cast<Traits*>(self)->Traits::ForEachChild_GC(reinterpret_cast<RefCountCollector<323>*>(prcc), reinterpret_cast<void (*)(RefCountCollector<323>*, const RefCountBaseGC<323>**)>(op));
    void** pchild = reinterpret_cast<void**>(self + 0xc0);
    if (*pchild)
        op(prcc, pchild, self);
}
// @0x142503f50
void ClassTraits::Traits::ForEachChild_GC(Collector* prcc, GcOp op) const
{
    Sfr33ForEachChildGC_c0(reinterpret_cast<UByte*>(const_cast<Traits*>(this)), prcc, reinterpret_cast<Sfr33GcOp>(op));
}
// @0x142503fa0
void InstanceTraits::Traits::ForEachChild_GC(Collector* prcc, GcOp op) const
{
    Sfr33ForEachChildGC_c0(reinterpret_cast<UByte*>(const_cast<Traits*>(this)), prcc, reinterpret_cast<Sfr33GcOp>(op));
}

}}}

// A third Traits::GetConstructor copy.
// @0x142508460
Scaleform::GFx::AS3::Class& FUN_142508460(const Scaleform::GFx::AS3::Traits* t)
{
    void** self = const_cast<void**>(reinterpret_cast<void* const*>(t));
    void* p = self[0x10];
    if (!p)
    {
        typedef void (*MakeFn)(void*);
        reinterpret_cast<MakeFn*>(*self)[13](self);
        p = self[0x10];
    }
    return *static_cast<Scaleform::GFx::AS3::Class*>(p);
}

namespace Scaleform { namespace GFx { namespace AS3 {

// ForEachChild_GC of an owned value array (+0x00 owner, +0x08 data, +0x10 size).
// @0x142504460
void Sfr33OwnedValuesForEachChildGC(const UByte* self, RefCountCollector<StatMV_ActionScript_Mem>* prcc,
                                    ASRefCountBaseType::GcOp op)
{
    const UPInt size = *reinterpret_cast<const UPInt*>(self + 0x10);
    for (UPInt i = 0; i < size; ++i)
        AS3::ForEachChild_GC(prcc, (*reinterpret_cast<Value* const*>(self + 8))[i], op,
                             **reinterpret_cast<const ASRefCountBaseType* const*>(self));
}
}}}

namespace Scaleform { namespace GFx { namespace AS3 {

// ForEachChild_GC of an array (+0x08 data, +0x10 size) of 0x40-byte records with collectable pointers at +0x28,
// +0x18 and +0x20, all owned by powner.
// @0x142503aa0
void Sfr33RecordsForEachChildGC(const UByte* self, void* prcc, Sfr33GcOp op, void* powner)
{
    struct Record { UByte Head[0x18]; void* pA; void* pB; void* pC; UByte Tail[0x10]; };
    const UPInt size = *reinterpret_cast<const UPInt*>(self + 0x10);
    for (UPInt i = 0; i < size; ++i)
    {
        Record& r = (*reinterpret_cast<Record* const*>(self + 8))[i];
        if (r.pC)
            op(prcc, &r.pC, powner);
        if (r.pA)
            op(prcc, &r.pA, powner);
        if (r.pB)
            op(prcc, &r.pB, powner);
    }
}
}}}

namespace Scaleform { namespace GFx { namespace AS3 {

// Stores the value at +0x10 and drops the collectable at +0x08.
// @0x1424edca0
void Sfr33SetValueDropObject(UByte* self, void* value)
{
    *reinterpret_cast<void**>(self + 0x10) = value;
    *reinterpret_cast<SPtr<ASRefCountBaseType>*>(self + 8) = static_cast<ASRefCountBaseType*>(NULL);
}
}}}

// A collector record: a counted object and a second word (zero here).
struct Sfr33CollectorEntry
{
    Sfr33CollectorEntry(Scaleform::RefCountImpl* p) : pObject(p), pExtra(NULL) {}
    Scaleform::Ptr<Scaleform::RefCountImpl> pObject;
    void*                                   pExtra;
};
// (the record goes to Collect as its Stats: pObject is the observer slot)

namespace Scaleform { namespace GFx { namespace AS3 {

// Queues p (unless a collection runs, +0xb1), notes the queue's previous size (+0x94) and its high-water mark (+0x90),
// and asks for a collection (+0xb0) when the flags (+0x78) want one per addition.
// @0x142504630
__declspec(noinline) void Sfr33CollectorQueue(UByte* raw, RefCountImpl* p)
{
    ASRefCountCollector* self = reinterpret_cast<ASRefCountCollector*>(raw);
    if (self->SuspendCnt > 0)
        return;
    const unsigned curRootCount = static_cast<unsigned>(self->GetRootsCount());
    Sfr33CollectorEntry e(p);
    self->Collect(reinterpret_cast<ASRefCountCollector::Stats*>(&e));
    self->FrameCnt = 0;
    self->PeakRootCount = Alg::Max(self->PeakRootCount, curRootCount);
    self->LastRootCount = curRootCount;
    if (self->Flags & ASRefCountCollector::Flags_RequireMoreCollect)
        self->CollectionScheduledFlags = 1;
}

// Queues p as above (or only asks for a collection while one runs), frees an empty queue's pages unless the flags
// keep them (bit 1), and restarts the counters.
static SF_INLINE void Sfr33QueueAndResetImpl(UByte* self, RefCountImpl* p)
{
    if (self[0xb1] > 0)
    {
        self[0xb0] = 1;
        return;
    }
    Sfr33CollectorQueue(self, p);
    if (!(self[0x78] & 2) && *reinterpret_cast<UPInt*>(self + 0x18) == 0)
        reinterpret_cast<Scaleform::Sfr17GcPages*>(self + 0x10)->ClearAndRelease();
    *reinterpret_cast<unsigned*>(self + 0x8c) = *reinterpret_cast<unsigned*>(self + 0xa8);
    *reinterpret_cast<unsigned*>(self + 0x90) = 0;
}

// @0x1425046f0
void Sfr33CollectorQueueAndReset(UByte* self, RefCountImpl* p)
{
    Sfr33QueueAndResetImpl(self, p);
}
}}}

static inline void FUN_14252ecb0(void* vm, const void* error, const void* classInfo) { ::Scaleform::GFx::AS3::Sfr31VMRaiseError(reinterpret_cast<Scaleform::UPInt>(vm), static_cast<const unsigned long*>(error), reinterpret_cast<Scaleform::UPInt>(classInfo)); }   // VM: raise the error as an instance of the class
void FUN_14241de40(Scaleform::GFx::AS3::ValueStack* stack, unsigned n);   // ValueStack::PopBack: pops (and releases) the top n values
namespace Scaleform { namespace GFx { namespace AS3 { namespace fl_errors { extern const ClassInfo MemoryErrorCI; } } } }
bool FUN_1425149a0(const Scaleform::GFx::AS3::ClassTraits::Traits& tr, const Scaleform::GFx::AS3::ClassTraits::Traits& other);
static inline Scaleform::UPInt FUN_142525f20(char* buffer, int bufflen, double val) { return static_cast<Scaleform::UPInt>(::Scaleform::GFx::AS3::Sfr31NumberToChars(buffer, bufflen, val)); }

namespace Scaleform { namespace GFx { namespace AS3 {

// VM::ThrowTypeError, inlined.
static inline void Sfr33ThrowTypeError(VM& vm, const VM::Error& e)
{
    FUN_14252ecb0(&vm, &e, &fl::TypeErrorCI);
}

// VM::ThrowRangeError, inlined.
static inline void Sfr33ThrowRangeError(VM& vm, const VM::Error& e)
{
    FUN_14252ecb0(&vm, &e, &fl::RangeErrorCI);
}

// VM::ThrowReferenceError, inlined.
static inline void Sfr33ThrowReferenceError(VM& vm, const VM::Error& e)
{
    FUN_14252ecb0(&vm, &e, &fl::ReferenceErrorCI);
}

// VM::ThrowMemoryError, inlined.
static inline void Sfr33ThrowMemoryError(VM& vm, const VM::Error& e)
{
    FUN_14252ecb0(&vm, &e, &fl_errors::MemoryErrorCI);
}

// Primitives coerce to their own class and to Object (ints also to Number); objects to any class above theirs.
// undefined becomes null; the tracer-only kinds pass through untouched. The SDK body (AS3_Traits.cpp CoerceValue).
SF_INLINE bool Sfr33CoerceClassValue(const ClassTraits::Traits& self, const Value& value, Value& result)
{
    VM& vm = self.GetVM();
    const BuiltinTraitsType tt = self.GetTraitsType();

    switch (value.GetKind())
    {
    case Value::kUndefined:
        result.SetNull();
        break;
    case Value::kInt:
        if (&self != &vm.GetClassTraitsObject() && tt != Traits_Number && tt != Traits_SInt)
            return false;
        result.SetNumber(value.AsInt());
        break;
    case Value::kUInt:
        if (&self != &vm.GetClassTraitsObject() && tt != Traits_Number && tt != Traits_UInt)
            return false;
        result.SetNumber(value.AsUInt());
        break;
    case Value::kThunk:
    case Value::kVTableInd:
        if (&self != &vm.GetClassTraitsObject() && tt != Traits_Function)
            return false;
        result = value;
        break;
    case Value::kBoolean:
        if (&self != &vm.GetClassTraitsObject() && tt != Traits_Boolean)
            return false;
        result = value;
        break;
    case Value::kNumber:
        if (&self != &vm.GetClassTraitsObject() && tt != Traits_Number)
            return false;
        result = value;
        break;
    case Value::kString:
        if (&self != &vm.GetClassTraitsObject() && tt != Traits_String)
            return false;
        result = value;
        break;
    case Value::kNamespace:
        if (&self != &vm.GetClassTraitsObject() && tt != Traits_Namespace)
            return false;
        result = value;
        break;
    case Value::kFunction:
    case Value::kObject:
    case Value::kThunkFunction:
        if (value.GetObject())
        {
            const ClassTraits::Traits& other = vm.GetClassTraits(value);

            if (FUN_1425149a0(self, other))
                result = value;
            else
                return false;
        }
        else
            result = value;

        break;
    case Value::kThunkClosure:
    case Value::kVTableIndClosure:
        result = value;
        break;
    case Value::kClass:
        if (FUN_1425149a0(self, value.AsClass().GetClassTraits()))
            result = value;
        else
            return false;

        break;
    default:
        break;
    }

    return true;
}

// @0x1424effa0
bool ClassTraits::Traits::Coerce(const Value& value, Value& result) const
{
    return Sfr33CoerceClassValue(*this, value, result);
}

// The SDK body written out (not the forceinline helper): the out-of-line copy lays out its blocks as the exe does.
// @0x1424f01c0
bool ClassTraits::Traits::CoerceValue(const Value& value, Value& result) const
{
    VM& vm = GetVM();
    const BuiltinTraitsType tt = GetTraitsType();

    switch (value.GetKind())
    {
    case Value::kUndefined:
        result.SetNull();
        break;
    case Value::kInt:
        if (this != &vm.GetClassTraitsObject() && tt != Traits_Number && tt != Traits_SInt)
            return false;
        result.SetNumber(value.AsInt());
        break;
    case Value::kUInt:
        if (this != &vm.GetClassTraitsObject() && tt != Traits_Number && tt != Traits_UInt)
            return false;
        result.SetNumber(value.AsUInt());
        break;
    case Value::kThunk:
    case Value::kVTableInd:
        if (this != &vm.GetClassTraitsObject() && tt != Traits_Function)
            return false;
        result = value;
        break;
    case Value::kBoolean:
        if (this != &vm.GetClassTraitsObject() && tt != Traits_Boolean)
            return false;
        result = value;
        break;
    case Value::kNumber:
        if (this != &vm.GetClassTraitsObject() && tt != Traits_Number)
            return false;
        result = value;
        break;
    case Value::kString:
        if (this != &vm.GetClassTraitsObject() && tt != Traits_String)
            return false;
        result = value;
        break;
    case Value::kNamespace:
        if (this != &vm.GetClassTraitsObject() && tt != Traits_Namespace)
            return false;
        result = value;
        break;
    case Value::kFunction:
    case Value::kObject:
    case Value::kThunkFunction:
        if (value.GetObject())
        {
            const ClassTraits::Traits& other = vm.GetClassTraits(value);

            if (FUN_1425149a0(*this, other))
                result = value;
            else
                return false;
        }
        else
            result = value;

        break;
    case Value::kThunkClosure:
    case Value::kVTableIndClosure:
        result = value;
        break;
    case Value::kClass:
        if (FUN_1425149a0(*this, value.AsClass().GetClassTraits()))
            result = value;
        else
            return false;

        break;
    default:
        break;
    }

    return true;
}

// Wraps the thunk held by v in a closure that checks 'this' against this class.
// @0x1424f1c60
Value Class::ConvertCheckType(const Value& v, const Traits& ot) const
{
    const ThunkInfo& thunk = v.AsThunk();
    VM& vm = GetVM();
    const Classes::Function& cf =
        static_cast<const Classes::Function&>(vm.GetClassTraitsFunction().GetInstanceTraits().GetConstructor());
    return Value(cf.MakeCheckTypeInstance(*this, thunk, ot));
}

// Traits::CalculateMemSize: the own value slots are laid out after parent_size by size class (Boolean bytes,
// 4-byte Int/UInt, 8-byte object/Number/String pointers, 32-byte Values), each group aligned to its size; C++
// bound slots keep their offsets. The body follows the SDK (AS3_Traits.cpp), including the unused siv array
// whose destructor gives the exe's final free. The exe reads FirstOwnSlotInd once, as 32 bits, for both loops.
// The SDK's per-size counters (AS3_Traits.cpp VarInfo).
struct Sfr17VarInfo
{
    Sfr17VarInfo() : _1(0), _4(0), _8(0), _value(0) {}

    unsigned _1;
    unsigned _4;
    unsigned _8;
    unsigned _value;
};

// Return new aligned offset. Align must be power of two.
template <int A>
inline unsigned Sfr17AlignMem(unsigned offset)
{
    const unsigned a = A - 1;
    return (offset + a) & ~a;
}

// @0x1424ee490
void Traits::CalculateMemSize(unsigned parent_size)
{
    MemSize = parent_size;

    VM& vm = GetVM();
    ArrayDH_POD<AbsoluteIndex> siv(vm.GetMemoryHeap());
    const UPInt size = GetSlotInfoNum();
    const UPInt first = static_cast<UInt32>(FirstOwnSlotInd.Get());

    // Calculate number of values having different size.
    Sfr17VarInfo var_num;
    for (UPInt i = first; i < size; ++i)
    {
        const SlotInfo& si = Sfr33GetSlotInfo(*this, AbsoluteIndex(i));

        if (static_cast<bool>(si.CppBinding))
            continue;

        SlotInfo::BindingType bt = static_cast<SlotInfo::BindingType>(si.BindType);
        switch (bt)
        {
        case SlotInfo::BT_Value:
            ++var_num._value;
            break;
        case SlotInfo::BT_ObjectAS:
        case SlotInfo::BT_String:
            ++var_num._8;
            break;
        case SlotInfo::BT_Boolean:
            ++var_num._1;
            break;
        case SlotInfo::BT_Int:
            ++var_num._4;
            break;
        case SlotInfo::BT_UInt:
            ++var_num._4;
            break;
        case SlotInfo::BT_Number:
            ++var_num._8;
            break;
        case SlotInfo::BT_Code:
        case SlotInfo::BT_Get:
        case SlotInfo::BT_Set:
        case SlotInfo::BT_GetSet:
            break;
        default:
            break;
        }
    }

    if (var_num._1 + var_num._4 + var_num._8 + var_num._value == 0)
        return;

    Sfr17VarInfo offset;
    offset._1 = parent_size;
    offset._4 = offset._1 + var_num._1 * 1;
    if (var_num._4 > 0)
        offset._4 = Sfr17AlignMem<4>(offset._4);
    offset._8 = offset._4 + var_num._4 * 4;
    if (var_num._8 > 0)
        offset._8 = Sfr17AlignMem<8>(offset._8);
    offset._value = offset._8 + var_num._8 * 8;
    if (var_num._value > 0)
        offset._value = Sfr17AlignMem<32>(offset._value);

    MemSize = offset._value + var_num._value * 32;

    // Replace index in a pool with offset.
    Sfr17VarInfo var_ind;
    for (UPInt i = first; i < size; ++i)
    {
        SlotInfo& si = GetOwnSlotInfo(AbsoluteIndex(i));

        if (static_cast<bool>(si.CppBinding))
            continue;

        switch (si.BindType)
        {
        case SlotInfo::BT_Boolean:
            si.ValueInd = offset._1 + var_ind._1++ * 1;
            break;
        case SlotInfo::BT_Int:
        case SlotInfo::BT_UInt:
            si.ValueInd = offset._4 + var_ind._4++ * 4;
            break;
        case SlotInfo::BT_Number:
            si.ValueInd = offset._8 + var_ind._8++ * 8;
            break;
        case SlotInfo::BT_String:
        case SlotInfo::BT_ObjectAS:
            si.ValueInd = offset._8 + var_ind._8++ * 8;
            break;
        case SlotInfo::BT_Value:
            si.ValueInd = offset._value + var_ind._value++ * 32;
            break;
        default:
            break;
        }
    }
}

// Class::Call: a class called as a function converts its single argument to the class (a TypeError when it
// cannot); any other argument count is a RangeError (exe 0x1424ee79b).
// @0x1424ee6f0
void Class::Call(const Value& _this, Value& result, unsigned argc, const Value* const argv)
{
    SF_UNUSED(_this);
    if (argc == 1)
    {
        const Value& v = argv[0];
        if (GetClassTraits().Coerce(v, result))
            return;
        else
            return Sfr33ThrowTypeError(GetClassTraits().GetVM(), VM::Error(VM::eCheckTypeFailedError, GetClassTraits().GetVM(), v, GetClassTraits().GetName().ToCStr()));
    }
    return Sfr33ThrowRangeError(GetClassTraits().GetVM(), VM::Error(VM::eCoerceArgumentCountError, GetClassTraits().GetVM(), int(argc)));
}

// Class::Construct: a new instance of the class in _this (a MemoryError when none could be made), initialized
// and handed to PostInit; when PreInit refuses it, a call from the VM drops its arguments off the stack.
// @0x1424f0610
void Class::Construct(Value& _this, unsigned argc, const Value* argv, bool extCall)
{
    InstanceTraits::Traits& itr = GetInstanceTraits();
    VM& vm = GetClassTraits().GetVM();
    itr.MakeObject(_this, itr);
    if (_this.IsObject() && _this.GetObject() == NULL)
        Sfr33ThrowMemoryError(vm, VM::Error(VM::ErrorID(1000) /* eOutOfMemoryError */, vm));
    if (PreInit(_this))
    {
        _this.GetObject()->InitInstance(extCall);
        PostInit(_this, argc, argv);
    }
    else if (!extCall)
        FUN_14241de40(reinterpret_cast<ValueStack*>(&vm.OpStack), argc);
}

// VM::GetClassUnsafe, inlined into Construct as in the SCU (the out-of-line copy is Sfr33GetClassValue, 0x142508140).
static inline bool Sfr17GetClassUnsafe(VM& vm, const StringDataPtr& gname, Value& result)
{
    Class* _class = vm.GetClass(gname);

    if (_class)
    {
        result.AssignUnsafe(_class);
        return true;
    }

    if (vm.IsException())
        return false;

    Sfr33ThrowReferenceError(vm, VM::Error(VM::eUndefinedVarError, vm, gname.ToCStr()));

    return false;
}

// Constructs the class named gname; returns whether a constructor frame was pushed (the call stack at +0x78 grew),
// which CreateObject (0x1424f3acd) and the symbol constructor in sfr_as3_17d read to decide on ExecuteCode(1)
// @0x1424f0750
__declspec(noinline) bool VM::Construct(const char* gname, Value& result, unsigned argc, const Value* argv, bool extCall)
{
    const UPInt original_stack_size = Unk070[1];   // call stack size

    // Get class.
    Value value;
    if (!Sfr17GetClassUnsafe(*this, gname, value))
        return false;

    if (value.IsNullOrUndefined())
    {
        Sfr33ThrowTypeError(*this, VM::Error(VM::eConvertNullToObjectError, *this));
        return false;
    }

    // Create instance.
    value.GetObject()->Construct(result, argc, argv, extCall);

    if (IsException())
        return false;

    return Unk070[1] > original_stack_size;
}

// Throws "not a constructor" in the VM of the file at +0x20.
// @0x1424f0700
void Instance::Construct(Value&, unsigned, const Value*, bool)
{
    const UByte* self = reinterpret_cast<const UByte*>(this);
    VM& vm = **reinterpret_cast<VM* const*>(*reinterpret_cast<const UByte* const*>(self + 0x20) + 0x78);
    Sfr33ThrowTypeError(vm, VM::Error(VM::eNotConstructorError, vm));
}

// Throws a TypeError when v, about to be used as an object, is null or undefined.
// As the SDK's StackReader::CheckObject, which calls GetVM() once for the throw and again for the Error.
// @0x1424ef180
void Sfr33CheckObject(VM* const* self, const Value& v)
{
    if (v.IsNullOrUndefined())
    {
        VM& vm = **self;
        Sfr33ThrowTypeError(vm, VM::Error(v.IsNull() ? VM::eConvertNullToObjectError : VM::eConvertUndefinedToObjectError, **self));
    }
}
}}}

void FUN_142502e70(void* pavm, const Scaleform::GFx::EventId& id);   // AvmDisplayObj: fire the event
void FUN_1424feb00(void* self, const Scaleform::GFx::AS3::Value& _this, Scaleform::GFx::AS3::Value& result, unsigned argc,
                   const Scaleform::GFx::AS3::Value* argv);   // UserDefined function: run the body

// UserDefinedFunction body: the receiver and arguments go to the host FunctionHandler (+0x40, user data +0x48) as
// GFx values (the receiver first in the argument array); a defined return value comes back as result.
// @0x1424feb00
void FUN_1424feb00(void* self, const Scaleform::GFx::AS3::Value& _this, Scaleform::GFx::AS3::Value& result, unsigned argc,
                   const Scaleform::GFx::AS3::Value* argv)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx;
    UByte* const fn = static_cast<UByte*>(self);
    ArrayCPP<GFx::Value> args;
    GFx::Value thisVal, retVal;

    AS3::ASVM& asvm = **reinterpret_cast<AS3::ASVM**>(*reinterpret_cast<UByte**>(fn + 0x20) + 0x78);
    AS3::MovieRoot* root = asvm.GetMovieRoot();

    root->ASValue2GFxValue(_this, &thisVal);
    args.PushBack(thisVal);
    for (unsigned i = 0; i < argc; ++i)
    {
        GFx::Value a;
        root->ASValue2GFxValue(argv[i], &a);
        args.PushBack(a);
    }
    FunctionHandler::Params params;
    params.pMovie = reinterpret_cast<Movie*>(asvm.GetMovieImpl());   // MovieImpl derives from Movie at offset 0
    params.pRetVal = &retVal;
    params.pThis = &thisVal;
    params.pArgs = argc > 0 ? &args[1] : NULL;
    params.pArgsWithThis = &args[0];
    params.ArgCount = static_cast<unsigned>(args.GetSize() - 1);
    params.pUserData = *reinterpret_cast<void**>(fn + 0x48);
    (*reinterpret_cast<FunctionHandler**>(fn + 0x40))->Call(params);
    if (!retVal.IsUndefined())
        root->GFxValue2ASValue(retVal, &result);
}
void FUN_14241e4f0(Scaleform::GFx::AS3::Object* self, const Scaleform::GFx::AS3::Value& v);   // UserDefined function: keep the result
typedef Scaleform::HashSetBase<Scaleform::HashNode<const Scaleform::GFx::AS3::Abc::MethodBodyInfo*,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<const Scaleform::GFx::AS3::Abc::MethodBodyInfo*> >,Scaleform::HashNode<const Scaleform::GFx::AS3::Abc::MethodBodyInfo*,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<const Scaleform::GFx::AS3::Abc::MethodBodyInfo*> >::NodeHashF,Scaleform::HashNode<const Scaleform::GFx::AS3::Abc::MethodBodyInfo*,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<const Scaleform::GFx::AS3::Abc::MethodBodyInfo*> >::NodeAltHashF,Scaleform::AllocatorLH<const Scaleform::GFx::AS3::Abc::MethodBodyInfo*,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<const Scaleform::GFx::AS3::Abc::MethodBodyInfo*,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<const Scaleform::GFx::AS3::Abc::MethodBodyInfo*> >,Scaleform::HashNode<const Scaleform::GFx::AS3::Abc::MethodBodyInfo*,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<const Scaleform::GFx::AS3::Abc::MethodBodyInfo*> >::NodeHashF> > Sfr33MethodBodyHashBase; extern template void Sfr33MethodBodyHashBase::setRawCapacity(void*, Scaleform::UPInt);   // 0x142541a60 (sfr_as3_19)
static inline void FUN_14251f930(void* tr, int op) { static_cast<Scaleform::GFx::AS3::Tracer*>(tr)->PushNewOpCode(static_cast<Scaleform::GFx::AS3::Abc::Code::OpCode>(op)); }                // Tracer: emit opcode op
static inline void FUN_14251fb90(void* tr, int op, Scaleform::UPInt arg) { static_cast<Scaleform::GFx::AS3::Tracer*>(tr)->PushNewOpCode(static_cast<Scaleform::GFx::AS3::Abc::Code::OpCode>(op), arg); }   // Tracer: emit opcode op with one argument
bool FUN_1424f86d0(void* tr, const Scaleform::GFx::AS3::Value& v, bool pop);   // Tracer: push the object constant v
static inline void* FUN_142524f60(void* vm, const void* file, const void* mn) { return reinterpret_cast<void*>(::Scaleform::GFx::AS3::Sfr31ResolveClassTraits(reinterpret_cast<Scaleform::UPInt>(vm), reinterpret_cast<Scaleform::UPInt>(file), reinterpret_cast<Scaleform::UPInt>(mn))); }   // VM: the class traits the ABC multiname mn of file names (NULL if unresolved)
const Scaleform::GFx::AS3::Abc::Multiname& FUN_14250f8a0(const void* amn, const void* abc);   // the type name of a multiname
extern "C" const int DAT_143a2d640[];           // the AS3 error ids, sorted
extern "C" const char* const DAT_143a2d890[];   // the AS3 error messages, by id position
// noinline: Value::Convert2PrimitiveValueUnsafe (0x1424f12a0) calls it.
__declspec(noinline) void FUN_142508bd0(Scaleform::UPInt obj, void* out, int hint);   // Object::GetDefaultValueUnsafe (as sfr_as3_19 declares it)
// Object: the property name of namespace ns (FindObjProperty, then its value); the member's hidden CheckResult
// slot is ret.
Scaleform::UByte* FUN_14250dd20(Scaleform::GFx::AS3::Object* self, Scaleform::UByte* ret, const Scaleform::GFx::ASString* name,
                                Scaleform::GFx::AS3::Instances::Namespace* ns, Scaleform::GFx::AS3::Value* value);

// Value::Swap (sfr_as3_19) in the SDK form, inline here as in the exe (same body as sfr_as3_18's).
namespace Scaleform { namespace GFx { namespace AS3 {
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
}}}

// Object::GetSlotValueUnsafe(name, ns, value) and Object::ExecuteValueUnsafe(value, result, 0, NULL), inlined.
static __forceinline bool Sfr33GetSlotValueUnsafe(Scaleform::GFx::AS3::Object& obj, const Scaleform::GFx::ASString& name,
                                                  Scaleform::GFx::AS3::Instances::Namespace& ns, Scaleform::GFx::AS3::Value& value)
{
    Scaleform::UByte ok;
    return *FUN_14250dd20(&obj, &ok, &name, &ns, &value) != 0;
}
static __forceinline void Sfr33ExecuteValueUnsafe(Scaleform::GFx::AS3::Object& obj, Scaleform::GFx::AS3::Value& value,
                                                  Scaleform::GFx::AS3::Value& result)
{
    obj.GetVM().ExecuteInternalUnsafe(value, Scaleform::GFx::AS3::Value(&obj, Scaleform::GFx::AS3::Value::InlineObj), result, 0, NULL, false);
}

// Object::GetDefaultValueUnsafe ([[DefaultValue]]): with the hint String (Date objects and the hint-less default for
// them, and always for the two traits types 0xd/0xe) toString is tried before valueOf, otherwise valueOf first; the
// second runs only when the first left no primitive (and raised nothing).
// @0x142508bd0
void FUN_142508bd0(Scaleform::UPInt objAddr, void* out, int hint)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    Object& obj = *reinterpret_cast<Object*>(objAddr);
    Value& result = *static_cast<Value*>(out);
    StringManager& sm = obj.GetVM().GetStringManager();
    VM& vm = obj.GetVM();
    const int tt = obj.GetTraits().GetTraitsType();
    if (static_cast<unsigned>(tt - 0xd) <= 1)
        hint = Value::hintString;
    else if (hint == Value::hintNone)
        hint = (tt == 8) + 1;
    Value value;

    if (hint == Value::hintString)
    {
        // toString part.
        {
            if (!Sfr33GetSlotValueUnsafe(obj, sm.GetBuiltin(AS3Builtin_toString), vm.GetPublicNamespace(), value))
                return;

            if (value.IsCallable())
            {
                Value v;
                Sfr33ExecuteValueUnsafe(obj, value, v);
                Sfr18ValueSwap::Swap(result, v);
            }

            if (vm.IsException() || result.IsPrimitive())
                return;
        }

        // valueOf part.
        {
            Value value;

            if (!Sfr33GetSlotValueUnsafe(obj, sm.GetBuiltin(AS3Builtin_valueOf), vm.GetPublicNamespace(), value))
                return;

            if (value.IsCallable())
            {
                Value v;
                Sfr33ExecuteValueUnsafe(obj, value, v);
                Sfr18ValueSwap::Swap(result, v);
            }
        }
    }
    else
    {
        // valueOf part.
        {
            if (!Sfr33GetSlotValueUnsafe(obj, sm.GetBuiltin(AS3Builtin_valueOf), vm.GetPublicNamespace(), value))
                return;

            if (value.IsCallable())
            {
                Value v;
                Sfr33ExecuteValueUnsafe(obj, value, v);
                Sfr18ValueSwap::Swap(result, v);
            }

            if (vm.IsException() || result.IsPrimitive())
                return;
        }

        // toString part.
        {
            Value value;

            if (!Sfr33GetSlotValueUnsafe(obj, sm.GetBuiltin(AS3Builtin_toString), vm.GetPublicNamespace(), value))
                return;

            if (value.IsCallable())
            {
                Value v;
                Sfr33ExecuteValueUnsafe(obj, value, v);
                Sfr18ValueSwap::Swap(result, v);
            }
        }
    }
}
namespace Scaleform { namespace GFx { namespace AS3 { const ClassTraits::Traits* FUN_14250d760(VM& vm, const Multiname& mn); }}}   // the traits that define mn

// Coerces value to the return type of the method the current call frame runs (result may be value): TypeError
// 1014 when the type is not found, 1034 when the value does not convert.
// @0x1424efe30
void FUN_1424efe30(Scaleform::GFx::AS3::VM* vm, Scaleform::GFx::AS3::Value* value, Scaleform::GFx::AS3::Value* result)
{
    using namespace Scaleform::GFx::AS3;
    const char* const v = reinterpret_cast<const char*>(vm);
    const Scaleform::UPInt i = *reinterpret_cast<const Scaleform::UPInt*>(v + 0x78) - 1;
    const char* frame = (i & 0x3f) * 0xa8 + *reinterpret_cast<const char* const*>(
        *reinterpret_cast<const char* const*>(v + 0x90) + (i >> 6) * 8);
    const char* abc = *reinterpret_cast<const char* const*>(*reinterpret_cast<const char* const*>(frame + 0x28) + 0x28);
    const char* const* bodies = *reinterpret_cast<const char* const* const*>(abc + 0x170);
    const char* body = bodies[*reinterpret_cast<const int*>(frame + 0x30)];
    const char* const* methods = *reinterpret_cast<const char* const* const*>(abc + 0xf8);
    const char* method = methods[*reinterpret_cast<const int*>(body + 0x18)];
    const char* mn = reinterpret_cast<const char*>(
        &reinterpret_cast<const Abc::TraitInfo*>(method)->GetName(*reinterpret_cast<const Abc::ConstPool*>(abc + 0x30)));
    const ClassTraits::Traits* ctr = static_cast<const ClassTraits::Traits*>(
        FUN_142524f60(vm, *reinterpret_cast<const char* const*>(frame + 0x28), mn));
    if (ctr)
    {
        if (!ctr->Coerce(*value, *result))
            Sfr33ThrowTypeError(*vm, VM::Error(VM::ErrorID(1034) /* eCheckTypeFailedError */, *vm, *value, ctr->GetName().ToCStr()));
    }
    else
    {
        const char* strings = *reinterpret_cast<const char* const*>(
            *reinterpret_cast<const char* const*>(*reinterpret_cast<const char* const*>(frame + 0x28) + 0x28) + 0x70);
        const Abc::StringView& name = *reinterpret_cast<const Abc::StringView*>(
            strings + static_cast<Scaleform::UPInt>(*reinterpret_cast<const unsigned*>(mn + 8)) * 8);
        const Scaleform::StringDataPtr str = name.ToStringDataPtr();
        Sfr33ThrowTypeError(*vm, VM::Error(VM::ErrorID(1014) /* eClassNotFoundError */, *vm, str.ToCStr()));
    }
}

// The ABC file's set of referenced constants (HashSetLH<SPtr<GASRefCountBase>> by pointer value). Its add by raw
// pointer is 0x1424d29d0 and SPtr::SetPtr is 0x1424e0710 (both out of line in the exe).
namespace Scaleform {
typedef GFx::AS3::SPtr<GFx::AS3::GASRefCountBase> Sfr33GCRootPtr;
typedef HashSetBase<Sfr33GCRootPtr, FixedSizeHash<Sfr33GCRootPtr>, FixedSizeHash<Sfr33GCRootPtr>, AllocatorLH<Sfr33GCRootPtr, 2>,
                    HashsetCachedEntry<Sfr33GCRootPtr, FixedSizeHash<Sfr33GCRootPtr> > > Sfr33GCRootSet;
template<> template<>
void Sfr33GCRootSet::add<GFx::AS3::GASRefCountBase*>(void* pheapAddr, GFx::AS3::GASRefCountBase* const& key, UPInt h);
namespace GFx { namespace AS3 {
template<> SPtr<GASRefCountBase>& SPtr<GASRefCountBase>::SetPtr(GASRefCountBase* p);
// SPtr<GASRefCountBase>::operator=(GASRefCountBase*) is out of line too (0x142528c50, emitted in sfr_as3_19).
template<> SPtr<GASRefCountBase>& SPtr<GASRefCountBase>::operator=(GASRefCountBase* p);
}}
}
namespace Scaleform { namespace GFx { namespace AS3 {
const SlotInfo* FindFixedSlot(VM& vm, const Traits& tr, const Multiname& mn, UPInt& index, Object* obj);
}}}

// Tracer: emits the push of the object constant v (pop: drop the last pushed value first) and keeps the object in
// the ABC file's set of referenced constants (+0x38). The argument carries the value kind in the pointer's low bits.
// MS2-FUNCTIONAL 0x1424f86d0: written on raw offsets (tracer +0x20 state, +0x28 file); the exe keeps the object in
// rbx (ours r10, spilled across the inlined Set) and its SPtr AddRef loads, increments, masks and stores the count
// @0x1424f86d0
bool FUN_1424f86d0(void* tr, const Scaleform::GFx::AS3::Value& v, bool pop)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    UByte* const self = static_cast<UByte*>(tr);
    UByte* file = *reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28);
    VM& vm = **reinterpret_cast<VM**>(file + 0x20);
    const Traits& t = vm.GetValueTraits(v);
    if (static_cast<int>(v.GetKind()) != 13 && !t.IsGlobal())
        return false;
    UPInt tag;
    switch (static_cast<int>(v.GetKind()))
    {
    case 11: tag = 6; break;
    case 12: tag = 0; break;
    case 13: tag = 2; break;
    case 14: tag = 4; break;
    default: tag = UPInt(-1); break;
    }
    if (pop)
        reinterpret_cast<Tracer*>(self)->PopPrevValue();
    const UByte* pv = reinterpret_cast<const UByte*>(&v);
    FUN_14251fb90(self, 0xb5, *reinterpret_cast<const UPInt*>(pv + 0x10) + tag);
    const UPInt obj = *reinterpret_cast<const UPInt*>(pv + 0x10);
    file = *reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28);
    if (obj == *reinterpret_cast<const UPInt*>(*reinterpret_cast<UByte**>(file + 0x20) + 0x298))
        return true;
    Sfr33GCRootSet* set = reinterpret_cast<Sfr33GCRootSet*>(file + 0x38);
    set->Set(set, reinterpret_cast<GASRefCountBase*>(v.GetObject()));
    return true;
}

static inline void FUN_14251fa10(void* tr, int op, Scaleform::UPInt arg1, Scaleform::UPInt arg2) { static_cast<Scaleform::GFx::AS3::Tracer*>(tr)->PushNewOpCode(static_cast<Scaleform::GFx::AS3::Abc::Code::OpCode>(op), arg1, arg2); }   // Tracer: emit opcode op with two arguments

// Tracer: emits the property op (op: 0x66 get / 0x68 init / 0x61 set / 5 ...) on a name that resolves to a fixed
// slot of the traits t as a slot access: a plain data slot by index (0xb7/0xb8), a method or getter slot (bind types
// 13/14) as a call of its vtable entry (0x43 callmethod, 0xb9 for op 5) plus a pop; else the op with ind.
// MS2-FUNCTIONAL 0x1424f92f0: written on raw offsets (tracer +0x20 state, +0x28 file, SlotInfo bitfields); the exe
// keeps t in r14, op in ebp and the slot in r15 (ours: rbp, r15d, r14)
// @0x1424f92f0
bool FUN_1424f92f0(void* tr, int op, const Scaleform::GFx::AS3::Traits* t, void* /*unused*/,
                   const Scaleform::GFx::AS3::Multiname* pmn, int ind)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    UByte* const self = static_cast<UByte*>(tr);
    const unsigned& mnw = *reinterpret_cast<const unsigned*>(pmn);
    const unsigned kind = mnw & 3;
    if (kind != 1 && !((UByte)(mnw >> 2) & 1) && (kind != 0 || *reinterpret_cast<const UPInt*>(reinterpret_cast<const UByte*>(pmn) + 8)) && t)
    {
        UByte* file = *reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28);
        UPInt index = 0;
        const SlotInfo* si = FindFixedSlot(**reinterpret_cast<VM**>(file + 0x20), *t, *pmn, index, NULL);
        if (si)
        {
            const int siw = *reinterpret_cast<const int*>(si);
            const int bt = (siw << 0x16) >> 0x1b;
            if (bt > 10)
            {
                if (!((siw >> 0x1a) & 1) && !t->IsInterface() &&
                    static_cast<unsigned>(bt - 13) <= 1)
                {
                    if ((UByte)(mnw >> 2) & 1)
                    {
                        FUN_14251f930(self, 0x2b);   // swap
                        FUN_14251f930(self, 0x29);   // pop
                    }
                    const int vind = (*reinterpret_cast<const int*>(si) << 5) >> 0xf;
                    FUN_14251fa10(self, op == 5 ? 0xb9 : 0x43, static_cast<UPInt>(static_cast<SPInt>(vind + 1)), 1);
                    FUN_14251f930(self, 0x29);
                    return true;
                }
            }
            else
            {
                if ((UByte)(mnw >> 2) & 1)
                {
                    FUN_14251f930(self, 0x2b);
                    FUN_14251f930(self, 0x29);
                }
                FUN_14251fb90(self, (op == 0x68) + 0xb7, static_cast<unsigned>(static_cast<int>(index) + 1));
                return true;
            }
        }
    }
    FUN_14251fb90(self, op, static_cast<UPInt>(static_cast<SPInt>(ind)));
    return true;
}

namespace Scaleform { namespace GFx { namespace AS3 {
ClassTraits::Traits* Sfr33ResolveMnClassTraits(VM* vm, const Multiname& mn);
}}}

// Sets a tracer value word by word: flags (kind | 0x40 traits-typed | 0x400 not null), bonus, object; an object or
// class gets a reference (the GC count at +0x10 keeps its flag bits clear).
static void Sfr33TracerValueSet(Scaleform::GFx::AS3::Value& v, unsigned flags, void* obj, bool addref)
{
    using namespace Scaleform;
    UByte* const pv = reinterpret_cast<UByte*>(&v);
    if (addref)
    {
        unsigned& rc = *reinterpret_cast<unsigned*>(static_cast<UByte*>(obj) + 0x10);
        rc = (rc + 1) & 0x8fbfffff;
    }
    *reinterpret_cast<unsigned*>(pv) = flags;
    *reinterpret_cast<UPInt*>(pv + 8) = 0;
    *reinterpret_cast<void**>(pv + 0x10) = obj;
}

// Tracer: a name mn that resolves to a class is pushed as its class object (kind Class) or, for a class with no
// constructor yet whose script object holds it in a slot, as the slot read of that object; the state's op stack
// (+0x38) gets the class (not_null: flagged not null) or its traits-typed value. False when mn names no class.
// MS2-FUNCTIONAL 0x1424f8910: written on raw offsets (tracer +0x20 state, class traits +0xc0/+0x80/+0x68/+0xd0);
// the exe keeps one Value slot for both branches (ours two, a 0x20 larger frame) and tail-merges the ~Multiname
// returns. The Values are dtor-less slots released through the out-of-line ReleaseInternal, as in the exe.
static __forceinline void Sfr33ValueReleaseInternal(Scaleform::GFx::AS3::Value& v);
// A Value slot with no destructor: the tracer releases it through the out-of-line ReleaseInternal.
struct Sfr33RawValue
{
    union { Scaleform::GFx::AS3::Value v; };
    Sfr33RawValue() {}
    ~Sfr33RawValue() {}
};
// @0x1424f8910
bool FUN_1424f8910(void* tr, void* state, Scaleform::GFx::AS3::Multiname mn, bool pop, bool not_null)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    UByte* const self = static_cast<UByte*>(tr);
    ArrayDH<Value>& opstack = *reinterpret_cast<ArrayDH<Value>*>(static_cast<UByte*>(state) + 0x38);
    VM* vm = *reinterpret_cast<VM**>(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28) + 0x20);
    UByte* ctr = reinterpret_cast<UByte*>(Sfr33ResolveMnClassTraits(vm, mn));
    if (!ctr)
        return false;
    UByte* itr = *reinterpret_cast<UByte**>(ctr + 0xc0);
    if (!itr)
        return false;
    void* cls = *reinterpret_cast<void**>(itr + 0x80);
    if (cls)
    {
        Sfr33RawValue vb;
        Value& v = vb.v;
        Sfr33TracerValueSet(v, 0xd, cls, true);
        if (FUN_1424f86d0(self, v, pop))
        {
            unsigned& fl = *reinterpret_cast<unsigned*>(&v);
            fl = 0xd;
            if (not_null)
                fl = 0x40d;
            opstack.PushBack(v);
            Sfr33ValueReleaseInternal(v);
            return true;
        }
        Sfr33ValueReleaseInternal(v);
        return false;
    }
    if (!((itr[0x68] >> 4) & 1))
        return false;
    UByte* script = *reinterpret_cast<UByte**>(itr + 0xd0);
    UPInt index = 0;
    vm = *reinterpret_cast<VM**>(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28) + 0x20);
    if (!FindFixedSlot(*vm, **reinterpret_cast<const Traits* const*>(script + 0x20), mn, index,
                       reinterpret_cast<Object*>(script)))
        return false;
    Sfr33RawValue vb;
    Value& v = vb.v;
    Sfr33TracerValueSet(v, not_null ? 0x449 : 0x49, ctr, false);
    opstack.PushBack(v);
    Sfr33TracerValueSet(v, 0xc, script, true);
    FUN_1424f86d0(self, v, false);
    Sfr33ValueReleaseInternal(v);
    FUN_14251fb90(self, 0xb6, static_cast<unsigned>(static_cast<int>(index) + 1));   // getslot
    return true;
}

namespace Scaleform { namespace GFx { namespace AS3 { InstanceTraits::Traits& FUN_14250a060(VM&, const Value&); } } }
// value -> traits, through the real VM::GetFunctReturnType (0x14250a060)
static __forceinline Scaleform::UPInt FUN_14250a060(Scaleform::UPInt vm, void* value) { return reinterpret_cast<Scaleform::UPInt>(&Scaleform::GFx::AS3::FUN_14250a060(*reinterpret_cast<Scaleform::GFx::AS3::VM*>(vm), *static_cast<const Scaleform::GFx::AS3::Value*>(value))); }

// Tracer: emits the call op (0x45 callsuper, 0x46 callproperty, 0x4e/0x4f the void forms, ...) of the call info
// (+0x18 argc, +0x148 the name, +0x178 the receiver) and pushes the result type on the state's op stack (+0x38). A
// name that resolves to a method slot of the receiver's traits becomes a call by vtable index (0x43 callmethod /
// 0xb9 callsupermethod), a getter slot a getter call (0xba/0xbb); a name of a class a construct (0xce) when the
// traits are flagged so.
// MS2-FUNCTIONAL 0x1424f7540: written on raw offsets (tracer +0x20 state, call info, SlotInfo bitfields); same
// length as the exe, but the exe keeps an rbp frame, tests the Traits flags as movzx/shr/test (ours: test byte) and
// repeats the (bt - 12) & ~2 test.
// @0x1424f7540
bool FUN_1424f7540(void* tr, int op, void* state, void* pinfo, int ind)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    UByte* const self = static_cast<UByte*>(tr);
    UByte* const info = static_cast<UByte*>(pinfo);
    const UByte* t = reinterpret_cast<const UByte*>(reinterpret_cast<const Tracer*>(self)->GetValueTraits(
        *reinterpret_cast<const Value*>(info + 0x178), op == 0x45 || op == 0x4e));
    const UInt32 argc = *reinterpret_cast<const UInt32*>(info + 0x18);
    const Multiname& mn = *reinterpret_cast<const Multiname*>(info + 0x148);
    const unsigned mnw = *reinterpret_cast<const unsigned*>(&mn);
    const unsigned kind = mnw & 3;
    if (kind == 1 || (static_cast<UByte>(mnw >> 2) & 1) || (kind == 0 && !*reinterpret_cast<const UPInt*>(info + 0x150)))
        goto generic;
    {
        UPInt index = 0;
        VM* vm = *reinterpret_cast<VM**>(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28) + 0x20);
        const SlotInfo* si;
        if (t && !(static_cast<UByte>(t[0x68] >> 2) & 1) &&
            (si = FindFixedSlot(*vm, *reinterpret_cast<const Traits*>(t), mn, index, NULL)) != NULL)
        {
            const int vind = (*reinterpret_cast<const int*>(si) << 5) >> 0xf;
            if (vind >= 0)
            {
                const int bt = (*reinterpret_cast<const int*>(si) << 0x16) >> 0x1b;
                if (bt == 11 || ((bt - 12) & ~2) == 0)
                {
                    if (bt == 11)
                    {
                        FUN_14251fa10(self, op == 0x45 || op == 0x4e ? 0xb9 : 0x43,
                                      static_cast<UPInt>(static_cast<SPInt>(vind)), argc);
                        if (static_cast<unsigned>(op - 0x4e) <= 1)
                        {
                            FUN_14251f930(self, 0x29);   // pop
                            return true;
                        }
                    }
                    else if (((bt - 12) & ~2) == 0)
                    {
                        switch (op)
                        {
                        case 0x45: op = 0xbb; break;
                        case 0x46: op = 0xba; break;
                        }
                        FUN_14251fa10(self, op, static_cast<UPInt>(static_cast<SPInt>(vind)), argc);
                    }
                    const AbsoluteIndex ai((*reinterpret_cast<const int*>(si) << 5) >> 0xf);
                    VM* vm2 = *reinterpret_cast<VM**>(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28) + 0x20);
                    const InstanceTraits::Traits& ret =
                        FUN_14250a060(*vm2, reinterpret_cast<const Traits*>(t)->GetVT().GetValue(ai));
                    reinterpret_cast<ArrayDH<Value>*>(static_cast<UByte*>(state) + 0x38)->PushBack(
                        Value(const_cast<InstanceTraits::Traits&>(ret), reinterpret_cast<const Tracer*>(self)->CanBeNull(ret)));
                    return true;
                }
            }
        }
        const UByte* ct = reinterpret_cast<const UByte*>(Sfr33ResolveMnClassTraits(vm, mn));
        if (!ct)
            goto generic;
        if (static_cast<UByte>(t[0x68] >> 5) & 1)
            FUN_14251fb90(self, 0xce, argc);
        else
        {
            FUN_14251fa10(self, op, static_cast<UInt32>(ind), argc);
            if (static_cast<unsigned>(op - 0x4e) <= 1)
                return true;
        }
        reinterpret_cast<ArrayDH<Value>*>(static_cast<UByte*>(state) + 0x38)->PushBack(
            Value(**reinterpret_cast<InstanceTraits::Traits* const*>(ct + 0xc0), Value::NotNull));
        return true;
    }
generic:
    FUN_14251fa10(self, op, static_cast<UInt32>(ind), argc);
    if (static_cast<unsigned>(op - 0x4e) <= 1)
        return true;
    {
        const UByte* vm = *reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28) + 0x20);
        reinterpret_cast<ArrayDH<Value>*>(static_cast<UByte*>(state) + 0x38)->PushBack(Value(
            **reinterpret_cast<InstanceTraits::Traits* const*>(*reinterpret_cast<const UByte* const*>(vm + 0x1f8) + 0xc0),
            Value::NullOrNot));
    }
    return true;
}

namespace Scaleform { namespace GFx { namespace AS3 {
void* Sfr33LazyGet80b(void** self);
}}}
// The type of the slot si of the traits t as a tracer value (result); the return carries false (first byte) when
// the slot type is not known yet.
namespace Scaleform { namespace GFx { namespace AS3 { namespace TR { struct Sfr33TRStateAccess17 { static SF_FORCEINLINE const char* PropType(void* s, char* ret, const void* t, const void* si, AS3::Value& v) { ::new (ret) CheckResult(static_cast<const State*>(s)->GetPropertyType(static_cast<const AS3::Traits*>(t), *static_cast<const SlotInfo*>(si), v)); return ret; } }; } } } }   // TR::State::GetPropertyType (0x14250cf20, private)

// Tracer: emits the get op (0x66 getproperty, 4 getsuper, ...) of the name mn on a receiver of the traits t and
// pushes the result type on the state's op stack (+0x38): a class name of a global as its class, a data slot as
// getslot (0xb6), a method slot as its function (op 0x66) or a getter call (0x43 callmethod / 0xb9); the builtin
// primitive traits give their class. Anything else is the op with ind and an Object result.
// MS2-FUNCTIONAL 0x1424f8b00: SDK EmitGetProperty order (code slot, else data slot), 1344 of 1370 bytes. The
// method/getter tails are written per branch as in the SDK, and the exe cross-jumps them into one push tail.
// Regalloc differs too: the exe keeps op in r13d and a zero in r12.
// @0x1424f8b00
bool FUN_1424f8b00(void* tr, int op, void* state, const Scaleform::GFx::AS3::Traits* t,
                   const Scaleform::GFx::AS3::Multiname* pmn, int ind)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    UByte* const self = static_cast<UByte*>(tr);
    const UByte* const tb = reinterpret_cast<const UByte*>(t);
    ArrayDH<Value>& opstack = *reinterpret_cast<ArrayDH<Value>*>(static_cast<UByte*>(state) + 0x38);
    const Multiname& mn = *pmn;
    const unsigned mnw = *reinterpret_cast<const unsigned*>(pmn);
    const unsigned kind = mnw & 3;
    UByte* const vm = *reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28) + 0x20);
    const UByte* rt;
    char ok;
    if (kind == 1 || (mnw & 4) || (kind == 0 && !*reinterpret_cast<const UPInt*>(reinterpret_cast<const UByte*>(pmn) + 8)) || !t)
        goto object_result;
    {
    UPInt slot_ind = 0;   // the SDK's slot_ind, zeroed before the IsTraits test
    if ((*reinterpret_cast<const unsigned*>(reinterpret_cast<const UByte*>(pmn) + 0x10) & 0x1f) - 8 < 2)
        goto object_result;
    if (!((tb[0x68] >> 2) & 1) &&
        !reinterpret_cast<const Tracer*>(self)->IsPrimitiveType(t))
    {
        if (t->IsGlobal() && FUN_1424f8910(self, state, mn, true, false))
            return true;
        UPInt& index = slot_ind;
        const SlotInfo* si = FindFixedSlot(*reinterpret_cast<VM*>(vm), *t, mn, index, NULL);
        if (si)
        {
            const unsigned siw = *reinterpret_cast<const unsigned*>(si);
            const int bt = (static_cast<int>(siw) << 0x16) >> 0x1b;
            if (bt > 10)
            {
              if (!((siw >> 0x1a) & 1) && (bt != 11 || op == 0x66))
              {
                if (bt == 11)
                {
                    FUN_14251fb90(self, 0xb6, static_cast<unsigned>(static_cast<int>(index) + 1));
                    const AbsoluteIndex ai((*reinterpret_cast<const int*>(si) << 5) >> 0xf);
                    const InstanceTraits::Traits* const ret = &reinterpret_cast<const TR::State*>(state)->GetFunctType(t->GetVT().GetValue(ai));
                    Value v;
                    Sfr33TracerValueSet(v, ((static_cast<unsigned>(reinterpret_cast<const Tracer*>(self)->CanBeNull(*ret)) & ~8u) << 5) | 8,
                                        const_cast<InstanceTraits::Traits*>(ret), false);
                    opstack.PushBack(v);
                    return true;
                }
                else
                {
                    if ((*reinterpret_cast<const unsigned*>(pmn) >> 2) & 1)   // re-read after the calls, as in the exe
                        FUN_14251f930(self, 0x29);
                    FUN_14251fa10(self, op == 4 ? 0xb9 : 0x43,
                                  static_cast<UPInt>(static_cast<SPInt>((static_cast<int>(siw) << 5) >> 0xf)), 0);
                    const AbsoluteIndex ai((*reinterpret_cast<const int*>(si) << 5) >> 0xf);
                    const InstanceTraits::Traits* const ret = &FUN_14250a060(*reinterpret_cast<VM*>(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28) + 0x20)), t->GetVT().GetValue(ai));
                    Value v;
                    Sfr33TracerValueSet(v, ((static_cast<unsigned>(reinterpret_cast<const Tracer*>(self)->CanBeNull(*ret)) & ~8u) << 5) | 8,
                                        const_cast<InstanceTraits::Traits*>(ret), false);
                    opstack.PushBack(v);
                    return true;
                }
              }
            }
            else
            {
                {
                    Value v;
                    if (!*Scaleform::GFx::AS3::TR::Sfr33TRStateAccess17::PropType(state, &ok, t, si, v))
                        return false;
                    opstack.PushBack(v);
                }
                if ((*reinterpret_cast<const unsigned*>(pmn) >> 2) & 1)   // re-read after the calls, as in the exe
                    FUN_14251f930(self, 0x29);   // pop
                FUN_14251fb90(self, 0xb6, static_cast<unsigned>(static_cast<int>(index) + 1));   // getslot
                return true;
            }
        }
    }
    }
    {
        UPInt index = 0;
        UByte* fvm = *reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28) + 0x20);
        const SlotInfo* si = FindFixedSlot(*reinterpret_cast<VM*>(fvm), *t, mn, index, NULL);
        if (si)
        {
            {
                Value v;
                if (!*Scaleform::GFx::AS3::TR::Sfr33TRStateAccess17::PropType(state, &ok, t, si, v))
                    return false;
                opstack.PushBack(v);
            }
            FUN_14251fb90(self, op, static_cast<UPInt>(static_cast<SPInt>(ind)));
            return true;
        }
        const UByte* ct;
        if (tb == *reinterpret_cast<UByte* const*>(*reinterpret_cast<UByte* const*>(vm + 0x250) + 0xc0))
            ct = *reinterpret_cast<UByte* const*>(vm + 0x220);
        else if (tb == *reinterpret_cast<UByte* const*>(*reinterpret_cast<UByte* const*>(vm + 0x258) + 0xc0))
            ct = *reinterpret_cast<UByte* const*>(vm + 0x228);
        else if (tb == *reinterpret_cast<UByte* const*>(*reinterpret_cast<UByte* const*>(vm + 0x260) + 0xc0))
            ct = *reinterpret_cast<UByte* const*>(vm + 0x218);
        else if (tb == *reinterpret_cast<UByte* const*>(*reinterpret_cast<UByte* const*>(vm + 0x268) + 0xc0))
            ct = *reinterpret_cast<UByte* const*>(vm + 0x230);
        else
        {
            if (*reinterpret_cast<const int*>(tb + 0x70) != 0xb || ((tb[0x68] >> 5) & 1))
                goto object_result;
            const UByte* o = static_cast<const UByte*>(
                Sfr33LazyGet80b(reinterpret_cast<void**>(const_cast<UByte*>(tb))));
            ct = *reinterpret_cast<UByte* const*>(*reinterpret_cast<UByte* const*>(o + 0x20) + 200);
        }
        rt = *reinterpret_cast<UByte* const*>(ct + 0xc0);
        if (!rt)
            goto object_result;
        Value v;
        Sfr33TracerValueSet(v,
                            ((static_cast<unsigned>(reinterpret_cast<const Tracer*>(self)->CanBeNull(
                                  *reinterpret_cast<const InstanceTraits::Traits*>(rt))) & ~8u) << 5) | 8,
                            const_cast<UByte*>(rt), false);
        opstack.PushBack(v);
        FUN_14251fb90(self, op, static_cast<UPInt>(static_cast<SPInt>(ind)));
        return true;
    }
object_result:
    {
        // the exe reads the VM again here
        const UByte* const ovm = *reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28) + 0x20);
        rt = *reinterpret_cast<UByte* const*>(*reinterpret_cast<UByte* const*>(ovm + 0x1f8) + 0xc0);
        Value v;
        Sfr33TracerValueSet(v, 0x48, const_cast<UByte*>(rt), false);
        opstack.PushBack(v);
    }
    FUN_14251fb90(self, op, static_cast<UPInt>(static_cast<SPInt>(ind)));
    return true;
}

namespace Scaleform { namespace GFx { namespace AS3 { void FUN_142501e80(void* state, void* propRef, void* multiname, void* stypeOut, void* scopeIndexOut); }}}   // State::FindProp

// The traits a found property's receiver is traced as: a traits value is its own, the class of Class objects stands
// for the class traits.
static const Scaleform::UByte* Sfr33TracerThisTraits(Scaleform::UByte* vm, const Scaleform::GFx::AS3::Value& v)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    const unsigned k = static_cast<unsigned>(v.GetKind());
    const UByte* t;
    if (k == 0)
        t = *reinterpret_cast<UByte* const*>(vm + 0x278);
    else if (k == 8 || k == 9)
        t = *reinterpret_cast<UByte* const*>(reinterpret_cast<const UByte*>(&v) + 0x10);
    else
        t = reinterpret_cast<const UByte*>(&(*reinterpret_cast<VM*>(vm)).GetValueTraits(v));
    if (t && t == *reinterpret_cast<UByte* const*>(vm + 0x1f0))
        t = *reinterpret_cast<UByte* const*>(vm + 0x1f8);
    return t;
}

// Tracer::EmitFindProperty: the find (getlex when get_prop) of the constant-pool name mn_index, resolved statically
// through the traced scopes (State::FindProp). A class name pushes its class; a slot of an outer scope (stype 0/1)
// pushes that scope object (getscopeobject 0x65 / getouterscope 0x67 unless it is a constant) and, for get_prop
// (or a following getproperty 0x4a), the slot read: a method slot as its function or a getter call. A slot of a
// global object (stype 2) pushes the object or its slot, the globals undefined and NaN as constants. The op stack
// (+0x38) gets the resulting type, flagged not null for a const slot or a namespace kind 4 unless consumer is
// 0x61/0x68. False when the name is run-time or nothing was found.
// MS2-FUNCTIONAL 0x1424f7cc0: written on raw offsets (tracer +0x20 state, SlotInfo bitfields); the trailing bool is
// the exe's stype home slot, unused
// @0x1424f7cc0
bool FUN_1424f7cc0(Scaleform::UPInt tracer, void* state, int idx, bool get_prop, int consumer, bool)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    UByte* const self = reinterpret_cast<UByte*>(tracer);
    ArrayDH<Value>& opstack = *reinterpret_cast<ArrayDH<Value>*>(static_cast<UByte*>(state) + 0x38);
    UByte* const file = *reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28);
    UByte* const abc = *reinterpret_cast<UByte**>(file + 0x28);
    const UByte* amn = idx == 0 ? abc + 0xe8 : *reinterpret_cast<UByte**>(abc + 0xb8) + static_cast<SPInt>(idx) * 0x10;
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), *reinterpret_cast<const Abc::Multiname*>(amn));
    const unsigned mnw = *reinterpret_cast<const unsigned*>(&mn);
    if ((mnw & 3) == 1 || (mnw & 4))
        return false;
    UByte* const vm = *reinterpret_cast<UByte**>(file + 0x20);
    UPInt scope_index = 0;
    UInt32 stype = 0;
    PropRef prop;
    FUN_142501e80(state, &prop, &mn, &stype, &scope_index);
    const UPInt pbits = reinterpret_cast<UPInt>(prop.pValue);
    if (prop.This.GetKind() == Value::kUndefined || pbits == 1 || ((pbits & 2) != 0 && (pbits & ~UPInt(2)) == 0))
        return get_prop && FUN_1424f8910(self, state, mn, false, false);
    if (pbits & 1)
        return false;
    const UByte* const si = reinterpret_cast<const UByte*>(prop.pSI);
    const unsigned siw = *reinterpret_cast<const unsigned*>(si);
    const UByte* const sins = *reinterpret_cast<UByte* const*>(si + 0x20);
    bool not_null = consumer != 0x61 && consumer != 0x68 && ((siw & 0x3e0) == 0x20 || (sins && (*sins & 0xf) == 4));
    const UByte* const t = Sfr33TracerThisTraits(vm, prop.This);
    const int sindex = static_cast<int>(prop.SlotIndex);
    const int st = static_cast<int>(stype);
    const int bt = (static_cast<int>(siw) << 0x16) >> 0x1b;
    if (st < 0 || st > 2)
        return false;
    if (st == 2)
    {
        if (not_null && FUN_1424f8910(self, state, mn, false, true))
            return true;
        if (!get_prop)
        {
            const unsigned k = static_cast<unsigned>(prop.This.GetKind());
            if (k - 8 < 2)
                FUN_14251fb90(self, 0xb6, static_cast<unsigned>(sindex + 1));   // getslot
            else if (k == 0)
                FUN_14251f930(self, 0x21);   // pushundefined
            else if (k == 1)
                FUN_14251f930(self, prop.This.AsBool() ? 0x26 : 0x27);   // pushtrue / pushfalse
            else if (k == 4)
            {
                if (!prop.This.IsNaN())
                    return false;
                FUN_14251f930(self, 0x28);   // pushnan
            }
            else if (k == 0xc || k == 0xd)
            {
                if (!FUN_1424f86d0(self, prop.This, false))
                    return false;
            }
            else
                return false;
            opstack.PushBack(prop.This);
            return true;
        }
        if (bt > 10)
            return false;
        const unsigned k = static_cast<unsigned>(prop.This.GetKind());
        if (k - 0xc < 4 &&
            *reinterpret_cast<const UPInt*>(reinterpret_cast<const UByte*>(&prop.This) + 0x10) ==
                *reinterpret_cast<const UPInt*>(vm + 0x298))
        {
            GFx::ASString name(reinterpret_cast<const Traits*>(t)->GetSlotNameNode(AbsoluteIndex(prop.SlotIndex)));
            int op = 0;
            if (strcmp(name.ToCStr(), "undefined") == 0)
                op = 0x21;   // pushundefined
            else if (memcmp(name.ToCStr(), "NaN", 4) == 0)
                op = 0x28;   // pushnan
            if (op)
            {
                FUN_14251f930(self, op);
                opstack.PushBack(Value::GetUndefined());
                return true;
            }
        }
        if (!FUN_1424f86d0(self, prop.This, false))
            return false;
        Value v;
        char ok;
        if (!*Scaleform::GFx::AS3::TR::Sfr33TRStateAccess17::PropType(state, &ok, Sfr33TracerThisTraits(vm, prop.This), si, v))
            return false;
        if (not_null)
            *reinterpret_cast<unsigned*>(&v) |= 0x400;
        opstack.PushBack(v);
        FUN_14251fb90(self, 0xb6, static_cast<unsigned>(sindex + 1));   // getslot
        return true;
    }
    if (not_null && FUN_1424f8910(self, state, mn, false, true))
        return true;
    if (!FUN_1424f86d0(self, prop.This, false))
        FUN_14251fb90(self, st == 0 ? 0x65 : 0x67, scope_index);   // getscopeobject / getouterscope
    if (!get_prop)
    {
        if (consumer != 0x4a)
        {
            opstack.PushBack(prop.This);
            return true;
        }
        get_prop = true;
        not_null = true;
    }
    const int vind = (static_cast<int>(siw) << 5) >> 0xf;
    if (bt > 10 && vind >= 0 && !((t[0x68] >> 2) & 1))
    {
        const Traits& tr = *reinterpret_cast<const Traits*>(t);
        const InstanceTraits::Traits* ret;
        if (bt == 11)
        {
            FUN_14251fb90(self, 0xb6, static_cast<unsigned>(sindex + 1));   // getslot
            Value f = tr.GetVT().GetValue(AbsoluteIndex(vind));
            ret = &reinterpret_cast<const TR::State*>(state)->GetFunctType(f);
        }
        else
        {
            FUN_14251fa10(self, 0x43, static_cast<UPInt>(static_cast<SPInt>(vind)), 0);   // callmethod (getter)
            Value f = tr.GetVT().GetValue(AbsoluteIndex(vind));
            ret = reinterpret_cast<const InstanceTraits::Traits*>(FUN_14250a060(reinterpret_cast<UPInt>(vm), &f));
        }
        Value v;
        Sfr33TracerValueSet(v, ((static_cast<unsigned>(reinterpret_cast<const Tracer*>(self)->CanBeNull(*ret)) & ~8u) << 5) | 8,
                            const_cast<InstanceTraits::Traits*>(ret), false);
        opstack.PushBack(v);
        return true;
    }
    FUN_14251fb90(self, 0xb6, static_cast<unsigned>(sindex + 1));   // getslot
    Value v;
    char ok;
    if (!*Scaleform::GFx::AS3::TR::Sfr33TRStateAccess17::PropType(state, &ok, t, si, v))
        return false;
    if (not_null)
        *reinterpret_cast<unsigned*>(&v) |= 0x400;
    opstack.PushBack(v);
    return true;
}

__declspec(noinline) void* FUN_142501310(Scaleform::GFx::AS3::VM& vm, void* scope, const Scaleform::GFx::AS3::Multiname& mn);   // find mn on one scope

// Searches the scope objects from the innermost out for mn; when the VM knows the traits that define mn, only the
// scopes of the same owner (vftable slot 10) are tried. Returns what FUN_142501310 found, or NULL.
// FUN_142501310 stays a call, as in the exe (noinline on its declaration).
// @0x142501870
void* FUN_142501870(Scaleform::GFx::AS3::VM& vm, const Scaleform::UPInt* scopes, const Scaleform::GFx::AS3::Multiname& mn)
{
    typedef Scaleform::UPInt (*OwnerFn)(const void*);
    void* found = 0;
    const Scaleform::GFx::AS3::Traits* t = FUN_14250d760(vm, mn);
    Scaleform::UPInt owner = 0;
    if (t)
        owner = (*reinterpret_cast<OwnerFn const* const*>(t))[10](t);
    for (Scaleform::UPInt i = scopes[1]; i != 0; --i)
    {
        void* sc = *reinterpret_cast<void* const*>(reinterpret_cast<const char* const*>(scopes[0])[i - 1] + 0x20);
        if (t && owner != (*reinterpret_cast<OwnerFn const* const*>(sc))[10](sc))
            continue;
        found = FUN_142501310(vm, sc, mn);
        if (found)
            break;
    }
    return found;
}

namespace Scaleform { namespace GFx { namespace AS3 {
ClassTraits::Traits* Sfr33SlotDataType(const SlotInfo* psi, VM* pvm);
ClassTraits::Traits* Sfr27GetClassTraitsByName(VM* vm, const ASString* name, const Instances::Namespace* ns);
}}}

// A slot namespace sns answers to ns: same kind, and protected ones by kind alone, private ones by identity, the rest
// by uri (as in Slots::FindSlotInfoIndex).
static bool Sfr33SlotNsMatches(const Scaleform::GFx::AS3::Instances::Namespace& sns,
                               const Scaleform::GFx::AS3::Instances::Namespace& ns)
{
    using namespace Scaleform::GFx::AS3;
    if (sns.GetKind() != ns.GetKind())
        return false;
    if (sns.GetKind() == Abc::NS_Protected)
        return true;
    return sns.GetKind() == Abc::NS_Private ? &sns == &ns : sns.GetUri().GetNode() == ns.GetUri().GetNode();
}

// Slots::GetSlotInfo and GetPrevSlotIndex, one level inline here as in the exe (0x142416fb0, 0x14250cc30 out of line).
static __forceinline const Scaleform::GFx::AS3::SlotInfo& Sfr17SlotInfoFI(const Scaleform::GFx::AS3::Slots& s,
                                                                          Scaleform::GFx::AS3::AbsoluteIndex ind)
{
    if (ind < s.FirstOwnSlotNum)
        return s.Parent->GetSlotInfo(ind);
    return s.VArray[ind.Get() - s.FirstOwnSlotNum].Value;
}
static __forceinline Scaleform::SPInt Sfr17PrevSlotFI(const Scaleform::GFx::AS3::Slots& s, Scaleform::SPInt ind)
{
    if (static_cast<Scaleform::UPInt>(ind) < s.FirstOwnSlotNum)
        return s.Parent->GetPrevSlotIndex(ind);
    return s.VArray[ind - s.FirstOwnSlotNum].Prev;
}
static __forceinline bool Sfr17IsQNameFI(const Scaleform::GFx::AS3::Multiname& mn)
{
    const unsigned bits = static_cast<Scaleform::UInt8>(mn.Kind) & 3;
    return bits == 0 || bits == 1;
}

// FindFixedSlot (0x1425011c0) without the on-demand object, inline here as in the exe.
static __forceinline const Scaleform::GFx::AS3::SlotInfo* Sfr17FindFixedSlotInl(const Scaleform::GFx::AS3::Traits& t,
    const Scaleform::GFx::ASString& name, const Scaleform::GFx::AS3::Instances::Namespace& ns, Scaleform::UPInt& index)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    const SlotInfo* sli_ptr = NULL;
    const Abc::NamespaceKind kind = ns.GetKind();
    const UInt32* values = t.FindSlotValues(name);
    if (values != NULL)
    {
        for (SPInt ind = *values; ind >= 0; ind = Sfr17PrevSlotFI(t, ind))
        {
            index = static_cast<UPInt>(ind);
            const SlotInfo& si = Sfr17SlotInfoFI(t, AbsoluteIndex(ind));
            const Instances::Namespace& cur_ns = *si.pNs;
            if (cur_ns.GetKind() == kind)
            {
                bool found = false;
                switch (kind)
                {
                case Abc::NS_Protected:
                    found = true;
                    break;
                case Abc::NS_Private:
                    found = (&ns == &cur_ns);
                    break;
                default:
                    found = (cur_ns.GetUri().GetNode() == ns.GetUri().GetNode());
                    break;
                }
                if (found)
                {
                    sli_ptr = &si;
                    break;
                }
            }
        }
    }
    return sli_ptr;
}

// VM::Resolve2ClassTraits(name, ns, appDomain), inline here as in the exe.
static __forceinline Scaleform::GFx::AS3::ClassTraits::Traits* Sfr17Resolve2CT(Scaleform::GFx::AS3::VM& vm,
    const Scaleform::GFx::ASString& name, const Scaleform::GFx::AS3::Instances::Namespace& ns)
{
    using namespace Scaleform::GFx::AS3;
    ClassTraits::Traits** found = FUN_142414ac0(&vm.ClassTraitsSet, name, ns);
    if (found != NULL && *found != NULL)
        return *found;
    ClassTraits::Traits* ctr = FUN_142415520(vm.GlobalObject.GetPtr(), name, ns);
    if (ctr != NULL)
        vm.ClassTraitsSet.Add(name, ns, ctr);
    return ctr;
}

// The class traits for mn as seen from the scope traits t (SDK FindFixedTraits(vm, t, mn, appDomain)).
// MS2-FUNCTIONAL 0x142501310: raw namespace-set and VM offsets; cl hoists the FindSlotValues call shared by both
// branches above the IsQName test, where the exe calls it in each (971 vs 1010 bytes)
// @0x142501310
void* FUN_142501310(Scaleform::GFx::AS3::VM& vm, void* scope, const Scaleform::GFx::AS3::Multiname& mn)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx;
    using namespace Scaleform::GFx::AS3;
    const Traits& t = *static_cast<const Traits*>(scope);
    const AS3::Value& vn = mn.Name;
    const UByte* sm = *reinterpret_cast<UByte* const*>(*reinterpret_cast<UByte* const*>(reinterpret_cast<UByte*>(&vm) + 0x10) + 0x1e8);
    ASString name(reinterpret_cast<ASStringNode*>(const_cast<UByte*>(sm) + 0x40));
    if (!vn.Convert2String(name))
        return NULL;
    const ClassTraits::Traits* result = NULL;
    if (Sfr17IsQNameFI(mn))
    {
        UPInt index = 0;
        const Instances::Namespace& ns = *reinterpret_cast<const Instances::Namespace*>(mn.Obj.GetPtr());
        const SlotInfo* si = Sfr17FindFixedSlotInl(t, name, ns, index);
        if (si)
            result = Sfr33SlotDataType(si, *reinterpret_cast<VM* const*>(reinterpret_cast<const UByte*>(&t) + 0x78));
        return const_cast<ClassTraits::Traits*>(result);
    }
    const UByte* obj = reinterpret_cast<const UByte*>(mn.Obj.GetPtr());
    const UInt32* values = t.FindSlotValues(name);
    const UPInt size = *reinterpret_cast<const UPInt*>(obj + 0x28);
    for (UPInt i = 0; i < size; ++i)
    {
        const Instances::Namespace& ns =
            **reinterpret_cast<Instances::Namespace* const*>(*reinterpret_cast<const UPInt*>(obj + 0x20) + i * 8);
        if (values != NULL)
        {
            for (SPInt ind = *values; ind >= 0; ind = Sfr17PrevSlotFI(t, ind))
            {
                const SlotInfo& si = Sfr17SlotInfoFI(t, AbsoluteIndex(ind));
                const Instances::Namespace& cur_ns = *si.pNs;
                if (cur_ns.GetKind() == ns.GetKind())
                {
                    bool found = false;
                    switch (ns.GetKind())
                    {
                    case Abc::NS_Protected:
                        found = true;
                        break;
                    case Abc::NS_Private:
                        found = (&ns == &cur_ns);
                        break;
                    default:
                        found = (cur_ns.GetUri().GetNode() == ns.GetUri().GetNode());
                        break;
                    }
                    if (found)
                    {
                        result = Sfr33SlotDataType(&si, &vm);
                        break;
                    }
                }
            }
        }
        if (!result)
            result = Sfr17Resolve2CT(vm, name, ns);
        if (result)
            break;
    }
    return const_cast<ClassTraits::Traits*>(result);
}

namespace Scaleform { namespace GFx { namespace AS3 {

ClassTraits::Traits* Sfr33SlotDataType(const SlotInfo* psi, VM* pvm);

// The fixed slot of tr named name in ns (index receives its slot index). 0x1425011c0
const SlotInfo* FindFixedSlot(const Traits& tr, const ASString& name, const Instances::Namespace& ns, UPInt& index,
                              Object* obj);

// How a slot of these traits declared with the ABC multiname mn of file stores its value: the any type is a plain
// value, otherwise the class traits mn names in the traits' VM (this+0x78) decide.
// @0x1425075e0
SlotInfo::BindingType Traits::GetBindingType(VMAbcFile& file, const Abc::Multiname& mn) const
{
    VM& vm = GetVM();
    SlotInfo::BindingType result;

    if (&mn == &file.GetAbcFile().Const_Pool.AnyType)
        result = SlotInfo::BT_Value;
    else
    {
        const ClassTraits::Traits* ct = static_cast<const ClassTraits::Traits*>(FUN_142524f60(&vm, &file, &mn));
        if (ct)
        {
            switch (ct->GetTraitsType())
            {
            case Traits_Boolean:    result = SlotInfo::BT_Boolean; break;
            case Traits_SInt:       result = SlotInfo::BT_Int; break;
            case Traits_UInt:       result = SlotInfo::BT_UInt; break;
            case Traits_Number:     result = SlotInfo::BT_Number; break;
            case Traits_String:     result = SlotInfo::BT_String; break;
            case Traits_Function:   result = SlotInfo::BT_Value; break;
            default:
                if (ct == &vm.GetClassTraitsObject())
                    result = SlotInfo::BT_Value;
                else
                    result = SlotInfo::BT_ObjectAS;
            }
        }
        else
            result = SlotInfo::BT_Value;
    }
    return result;
}

// The declared type of the fixed slot of tr named name in ns (NULL when there is none).
// @0x142501710
ClassTraits::Traits* Sfr33FixedSlotType(const Traits& tr, const ASString& name, const Instances::Namespace& ns,
                                        UPInt& index)
{
    const SlotInfo* si = FindFixedSlot(tr, name, ns, index, NULL);
    if (si)
        return Sfr33SlotDataType(si, *reinterpret_cast<VM* const*>(reinterpret_cast<const UByte*>(&tr) + 0x78));
    return NULL;
}

// ForEachChild_GC of a value array (+0x00 data, +0x08 size), two copies.
// @0x142503660
void Sfr33ValueArrayForEachChildGCa(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const UByte* arr,
                                    ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    for (UPInt i = 0; i < *reinterpret_cast<const UPInt*>(arr + 8); ++i)
        AS3::ForEachChild_GC(prcc, (*reinterpret_cast<Value* const*>(arr))[i], op, owner);
}

// @0x142503730
void Sfr33ValueArrayForEachChildGCb(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const UByte* arr,
                                    ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    for (UPInt i = 0; i < *reinterpret_cast<const UPInt*>(arr + 8); ++i)
        AS3::ForEachChild_GC(prcc, (*reinterpret_cast<Value* const*>(arr))[i], op, owner);
}

// ForEachChild_GC (virtual) of an object with an array of collectable pointers (+0x20 data, +0x28 size).
// @0x142503860
void Sfr33PtrArrayForEachChildGC(UByte* self, void* prcc, Sfr33GcOp op)
{
    const UPInt size = *reinterpret_cast<UPInt*>(self + 0x28);
    for (UPInt i = 0; i < size; ++i)
    {
        void** pchild = *reinterpret_cast<void***>(self + 0x20) + i;
        if (*pchild)
            op(prcc, pchild, self);
    }
}

// ForEachChild_GC of a record with collectable pointers at +0x18, +0x08 and +0x10, owned by powner.
// @0x142503c70
void Sfr33Record3ForEachChildGC(UByte* self, void* prcc, Sfr33GcOp op, void* powner)
{
    if (*reinterpret_cast<void**>(self + 0x18))
        op(prcc, self + 0x18, powner);
    if (*reinterpret_cast<void**>(self + 8))
        op(prcc, self + 8, powner);
    if (*reinterpret_cast<void**>(self + 0x10))
        op(prcc, self + 0x10, powner);
}

// Queues the object (+0x10)->+0x30 on the collector (+0x40)->+0x20 and resets it.
// @0x142504750
void Sfr33QueueOwnerObject(UByte* self)
{
    Sfr33QueueAndResetImpl(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x40) + 0x20),
                           *reinterpret_cast<RefCountImpl**>(*reinterpret_cast<UByte**>(self + 0x10) + 0x30));
}

}}}

namespace Scaleform { namespace GFx {
// AS3ValueObjectInterface::GetElement of an Array: pval receives element idx of the array pdata (false past its end).
// @0x142509ad0
bool AS3ValueObjectInterface::GetElement(void* pobj, unsigned idx, Value* pval) const
{
    const UByte* self = reinterpret_cast<const UByte*>(this);
    UByte* pdata = static_cast<UByte*>(pobj);
    pval->SetUndefined();
    AS3::SparseArray& sa = *reinterpret_cast<AS3::SparseArray*>(pdata + 0x38);
    if (idx >= static_cast<UInt32>(sa.GetSize()))
        return false;
    const AS3::MovieRoot* root = *reinterpret_cast<AS3::MovieRoot* const*>(*reinterpret_cast<UByte* const*>(self + 8) + 0x18);
    const AS3::Value& v = sa.At(idx);
    root->ASValue2GFxValue(v, pval);
    return true;
}
}} // namespace Scaleform::GFx

namespace Scaleform { namespace GFx { namespace AS3 {

// The message of AS3 error id (NULL when it has none).
// @0x142509b60
const char* Sfr33GetErrorMsg(int id)
{
    int lo = 0, hi = 0x91;
    while (lo <= hi)
    {
        const int mid = (hi + lo) >> 1;
        const int v = DAT_143a2d640[mid];
        if (v == id)
        {
            lo = mid;
            break;
        }
        if (id < v)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    if (DAT_143a2d640[lo] == id)
        return DAT_143a2d890[lo];
    return NULL;
}

// The file loader MovieRoot::CheckAvm hands the new VM: no files. vftable 0x14317f470.
class Sfr33NullFileLoader : public FileLoader
{
public:
    virtual UPInt GetSize() const;
    virtual const Ptr<Abc::File>& GetFile(UPInt n);
    virtual const Abc::File* GetFile(const ASString& name);
};

// A function-local static null file (inline, so cl dynamic-inits the static as in the exe).
// @0x142509c20
inline const Ptr<Abc::File>& Sfr33NullFileLoader::GetFile(UPInt)
{
    static Ptr<Abc::File> f;
    return f;
}

// (shared copies: return 0 at 0x14250dbb0 and 0x142509c90)
UPInt Sfr33NullFileLoader::GetSize() const { return 0; }
const Abc::File* Sfr33NullFileLoader::GetFile(const ASString&) { return NULL; }

// FlashUI::SetCurrState is protected (MovieRoot::CheckAvm, a member, calls it).
struct Sfr33FlashUIAccess : FlashUI
{
    static void SetCurrState(FlashUI& ui, StateType s) { static_cast<Sfr33FlashUIAccess&>(ui).FlashUI::SetCurrState(s); }
};

// MovieRoot::CheckAvm (virtual): creates the AS3 VM on first use and runs its startup code.
// @0x1424eecb0
bool Sfr33CheckAvm(MovieRoot* self)
{
    Scaleform::AutoPtr<ASVM>& avm = *reinterpret_cast<Scaleform::AutoPtr<ASVM>*>(&self->pAVM);
    if (!avm)
    {
        // the movie still holds its ActionControl after the Ptr temp releases it
        const ActionControl* pac = Ptr<ActionControl>(*static_cast<ActionControl*>(
            self->GetMovieImpl()->GetStateBag()->GetStateAddRef(State::State_ActionControl)));
        if (pac != NULL)
        {
            self->SetNeedToCheckOpCode((pac->GetActionFlags() & ActionControl::Action_Verbose) != 0);
        }
        else
        {
            self->SetNeedToCheckOpCode(false);
        }
        Sfr33FlashUIAccess::SetCurrState(*self, FlashUI::sStep);
        Sfr33NullFileLoader loader;
        avm = SF_HEAP_NEW(self->GetMovieImpl()->GetMovieHeap())
            ASVM(self, *self, loader, self->BuiltinsMgr, *self->MemContext->ASGC);
        self->pAVM->ExecuteCode(1);
    }
    return avm != NULL;
}



// Runs the class PostInit of the AS3 object without arguments. When that pushed a call frame, it runs now (execute)
// or stays queued (1); an exception is reported and flags the display object (+0x88).
// Returns from each branch as the SDK does (AS3_AvmDisplayObj.cpp), which gives the exe's registers.
// AvmDisplayObj::HasAS3Obj (SDK header inline): the bool result makes the exe test the collectible pointer
// against the zero raw pointer and load it again for GetAS3Obj.
static __forceinline bool Sfr17HasAS3Obj(const AvmDisplayObj& d) { return d.pAS3RawPtr || d.pAS3CollectiblePtr.pObject; }
// @0x1424ee800
SF_NOINLINE unsigned AvmDisplayObj::CallCtor(bool execute)
{
    if (!Sfr17HasAS3Obj(*this))
        return 0;
    Class& cls = reinterpret_cast<Object*>(GetAS3Obj())->GetTraits().GetConstructor();
    Sfr17ObjectValue v(reinterpret_cast<Object*>(GetAS3Obj()));
    UByte* const dobj = reinterpret_cast<UByte*>(pDispObj);
    VM* vm = *reinterpret_cast<VM**>(*reinterpret_cast<UByte**>(dobj + 0x20) + 0x48);
    if (!vm)
        return 0;
    const UPInt depth = *reinterpret_cast<UPInt*>(reinterpret_cast<UByte*>(vm) + 0x78);
    cls.PostInit(v.Get(), 0, NULL);
    if (*reinterpret_cast<UPInt*>(reinterpret_cast<UByte*>(vm) + 0x78) > depth)
    {
        if (execute)
        {
            vm->ExecuteCode(1);
            if (*(reinterpret_cast<UByte*>(vm) + 0x180))
            {
                vm->OutputAndIgnoreException();
                *reinterpret_cast<UInt16*>(reinterpret_cast<UByte*>(pDispObj) + 0x88) |= 0x20;
            }
            return 0;
        }
        else
            return 1;
    }
    return 0;
}

// Commands of a drawing path (+0x48: the command bytes, +0x10: the state).
// Ends the current segment run: command 6, state 5.
// @0x1424f96c0
SF_NOINLINE void Sfr33PathEndRun(UByte* self)
{
    (*reinterpret_cast<Array<UByte>**>(self + 0x48))->PushBack(6);
    *reinterpret_cast<int*>(self + 0x10) = 5;
}

// Closes the path (command 7, state 6), ending the run first; nothing when it is closed or empty.
// @0x1424f9740
void Sfr33PathClose(UByte* self)
{
    const int state = *reinterpret_cast<int*>(self + 0x10);
    if (state == 6 || state == 0)
        return;
    if (state != 5)
        Sfr33PathEndRun(self);
    (*reinterpret_cast<Array<UByte>**>(self + 0x48))->PushBack(7);
    *reinterpret_cast<int*>(self + 0x10) = 6;
}

// The Tracer's 0x140 bytes (an opaque local; the Tracer class is not recovered here).
struct Sfr33TracerStorage
{
    UPInt Q00, Q01, Q02, Q03, Q04, Q05, Q06, Q07, Q08, Q09, Q0a, Q0b, Q0c, Q0d, Q0e, Q0f, Q10, Q11, Q12, Q13;
    UPInt Q14, Q15, Q16, Q17, Q18, Q19, Q1a, Q1b, Q1c, Q1d, Q1e, Q1f, Q20, Q21, Q22, Q23, Q24, Q25, Q26, Q27;
    Sfr33TracerStorage() {}   // a user ctor keeps cl from treating the local as a /GS buffer (the exe frame has no cookie)
};

UPInt* FUN_1424d9f30(UPInt* self, UPInt heap, UPInt body, UPInt ops, UPInt extra);   // Tracer::Tracer
void* FUN_1424e6aa0(Tracer* tracer, const void* blocks, UPInt pos, int a, bool b);   // Tracer: the block starting at pos
static inline void FUN_142530220(void* tracer, UPInt pos, void* block) { ::Scaleform::GFx::AS3::Sfr31TraceBlock(reinterpret_cast<Scaleform::UPInt>(tracer), pos, reinterpret_cast<Scaleform::UPInt>(block)); }   // Tracer::TraceBlock

// The head of a TR::Block (unrecovered): its flags and its entry state.
struct Sfr33TrBlockView
{
    void*       pPrev;      // +0x00 List<TR::Block> node
    void*       pNext;      // +0x08
    UInt32      Flags;      // +0x10 bit 0: not yet traced
    UInt32      Type;       // +0x14 bit 1: try start, bit 2: catch target
    TR::State*  pState;     // +0x18
    __forceinline TR::State& GetState() const { return *pState; }   // TR::Block::GetState (SDK GetFirstBlock().GetState())
};

// vm.ThrowVerifyError(e): raises e as a VerifyError.
static SF_FORCEINLINE void Sfr33ThrowVerifyError(VM& vm, const VM::Error& e)
{
    FUN_14252ecb0(&vm, &e, &fl::VerifyErrorCI);
}

// The SDK ExceptionInfo getters (GetFrom ... GetVariableNameInd), inline: they fix the argument load order.
struct Sfr17ExcGet
{
    typedef Abc::MethodBodyInfo::ExceptionInfo EI;
    static __forceinline UInt32 From(const EI& e) { return static_cast<UInt32>(e.from); }
    static __forceinline UInt32 To(const EI& e) { return static_cast<UInt32>(e.to); }
    static __forceinline UInt32 Target(const EI& e) { return static_cast<UInt32>(e.target); }
    static __forceinline UInt32 ExcType(const EI& e) { return static_cast<UInt32>(e.exc_type_ind); }
    static __forceinline UInt32 VarName(const EI& e) { return static_cast<UInt32>(e.var_name_ind); }
};

// Tracer::EmitCode: seeds each exception handler block with its caught type, traces the body from the
// first block, then patches the recorded branch offsets and copies the remapped exception table.
// @0x1424f7840
void Tracer::EmitCode()
{
    typedef Abc::MethodBodyInfo::ExceptionInfo ExcInfo;
    if (Done)
        return;
    VM& vm = GetVM();
    const Abc::MethodBodyInfo::Exception& e = CF.pFile->GetAbcFile().MethodBodies.Info[CF.MBIIndex]->exception;
    {
        for (UPInt i = 0; i < e.info.GetSize(); ++i)
        {
            const ExcInfo& ei = e.info[i];
            Sfr33TrBlockView* try_block = reinterpret_cast<Sfr33TrBlockView*>(
                FUN_1424e6aa0(this, &reinterpret_cast<const Sfr33TrBlockView*>(Blocks.pNext)->GetState(), static_cast<UInt32>(ei.from), 0, false));
            if (try_block)
            {
                try_block->Flags &= ~1u;
                try_block->Type |= 2;
            }
            Sfr33TrBlockView* catch_block = reinterpret_cast<Sfr33TrBlockView*>(
                FUN_1424e6aa0(this, &reinterpret_cast<const Sfr33TrBlockView*>(Blocks.pNext)->GetState(), static_cast<UInt32>(ei.target), 0, false));
            if (catch_block)
            {
                catch_block->Type |= 4;
                TR::State& state = *catch_block->pState;
                const SInt32 et_ind = ei.exc_type_ind;
                if (et_ind == 0)
                    state.GetOpStack().PushBack(
                        Value(GetVM().GetClassTraitsObject().GetInstanceTraits(), Value::NullOrNot));
                else
                {
                    VMAbcFile& file = *CF.pFile;
                    const Abc::Multiname& amn = file.GetAbcFile().Const_Pool.GetMultiname(et_ind);
                    const ClassTraits::Traits* etr =
                        static_cast<const ClassTraits::Traits*>(FUN_142524f60(&vm, &file, &amn));
                    if (etr)
                    {
                        InstanceTraits::Traits& itr = etr->GetInstanceTraits();
                        VM& tvm = GetVM();
                        const Value::TraceNullType tn = (&itr == &tvm.GetClassTraitsSInt().GetInstanceTraits() ||
                            &itr == &tvm.GetClassTraitsUInt().GetInstanceTraits() ||
                            &itr == &tvm.GetClassTraitsNumber().GetInstanceTraits() ||
                            &itr == &tvm.GetClassTraitsBoolean().GetInstanceTraits()) ? Value::NotNull : Value::NullOrNot;
                        state.GetOpStack().PushBack(Value(itr, tn));
                    }
                    else
                    {
                        return Sfr33ThrowVerifyError(vm, VM::Error(VM::ErrorID(1014) /* eClassNotFoundError */, vm,
                            Value(file.GetInternedString(amn.NameIndex), Value::InlineStr)));
                    }
                }
            }
        }
    }
    FUN_142530220(this, 0, Blocks.pNext);
    if (vm.IsException())
    {
        WCode.Resize(0);
        return;
    }
    for (UPInt i = 0; i < PosToRecalculate.GetSize(); ++i)
    {
        const Recalculate& r = PosToRecalculate[i];
        const Abc::TCodeOffset pos = r.pos;
        const UPInt absolute_address = WCode[pos];
        UPInt new_address = 0;
        if (absolute_address < Orig2newPosMap.GetSize())
        {
            new_address = static_cast<UPInt>(Orig2newPosMap[absolute_address]);
            new_address -= static_cast<UPInt>(pos);
            new_address += r.base;
        }
        WCode[pos] = new_address;
    }
    const Abc::MethodBodyInfo::Exception& e2 = CF.pFile->GetAbcFile().MethodBodies.Info[CF.MBIIndex]->exception;
    for (UPInt i = 0; i < e2.info.GetSize(); ++i)
    {
        const ExcInfo& e = e2.info[i];
        WException.info.PushBack(ExcInfo(static_cast<Abc::SInd>(Orig2newPosMap[Sfr17ExcGet::From(e)]),
                                         static_cast<Abc::SInd>(Orig2newPosMap[Sfr17ExcGet::To(e)]),
                                         static_cast<Abc::SInd>(Orig2newPosMap[Sfr17ExcGet::Target(e)]), Sfr17ExcGet::ExcType(e),
                                         Sfr17ExcGet::VarName(e)));
    }
    Done = true;
}
extern "C" void FUN_1424df070(void* tracer);   // Tracer::~Tracer (sfr_as3_16, C linkage)

// The interpreter code of the frame's method body, traced from its bytecode on first use.
// @0x142508330
const ArrayLH_POD<UPInt, StatMV_VM_AbcFile_Mem>& Sfr33CallFrameGetCode(CallFrame& cf)
{
    typedef ArrayLH_POD<UPInt, StatMV_VM_AbcFile_Mem> CodeType;
    VMAbcFile& file = *cf.pFile;
    UByte* const pf = reinterpret_cast<UByte*>(&file);
    const SInt32 ind = cf.MBIIndex;
    CodeType& code = (*reinterpret_cast<ArrayLH<CodeType, StatMV_VM_VMAbcFile_Mem>*>(pf + 0xb8))[ind];   // OpCodeArray
    if (code.GetSize() == 0)
    {
        VM& vm = file.GetVM();
        Sfr33TracerStorage tr;
        FUN_1424d9f30(&tr.Q00, reinterpret_cast<UPInt>(vm.GetMemoryHeap()), reinterpret_cast<UPInt>(&cf),
                      reinterpret_cast<UPInt>(&code), reinterpret_cast<UPInt>(&(*reinterpret_cast<ArrayLH<Abc::MethodBodyInfo::Exception,
                          StatMV_VM_VMAbcFile_Mem>*>(pf + 0xd0))[ind]));   // Exceptions
        if (!vm.IsException())
            reinterpret_cast<Tracer*>(&tr)->EmitCode();
        FUN_1424df070(&tr);
    }
    return (*reinterpret_cast<ArrayLH<CodeType, StatMV_VM_VMAbcFile_Mem>*>(pf + 0xb8))[ind];
}

// MovieRoot::ExecuteActionQueue: runs (and frees) the actions queued on level lvl.
// @0x1424fa320
void MovieRoot::ExecuteActionQueue(ActionLevel lvl)
{
    ActionQueueIterator iter(lvl, &ActionQueue);
    const ActionEntry* paction;
    while ((paction = iter.getNext()) != NULL)
        paction->Execute(this);
}

// The same for the actions queued after insertAfter (from the level's start without one).
// @0x1424fa3b0
void Sfr33ExecuteActionQueueAfter(MovieRoot* self, MovieRoot::ActionLevel lvl, MovieRoot::ActionEntry* insertAfter)
{
    MovieRoot::ActionQueueIterator iter(lvl, &self->ActionQueue, insertAfter);
    const MovieRoot::ActionEntry* paction;
    while ((paction = iter.getNext()) != NULL)
        paction->Execute(self);
}

static SF_INLINE const char* Sfr33FindLastDot(const char* s)
{
    const UPInt len = SFstrlen(s);
    if (len)
    {
        for (const char* p = s + len; p != s; --p)
        {
            if (*p == '.')
                return p;
        }
    }
    return NULL;
}

// Splits a qualified class name at its last '.': pkg gets what is before it, name what follows. False without a
// dot (one at the very start does not count). The strings come from the manager at self+0x348.
// @0x142500680
bool Sfr33SplitQualifiedName(const UByte* self, const char* qname, ASString& pkg, ASString& name)
{
    const char* dot = Sfr33FindLastDot(qname);
    if (!dot)
        return false;
    const SPInt plen = static_cast<int>(dot - qname);
    name = ASString((*reinterpret_cast<ASStringManager* const*>(self + 0x348))->CreateStringNode(qname + plen + 1));
    pkg = ASString((*reinterpret_cast<ASStringManager* const*>(self + 0x348))->CreateStringNode(qname, plen));
    return true;
}
// TR::State::ConvertOpTo: the operand stack top (+0x38) becomes a value of traits tr.
// @0x1424f1e50
void TR::State::ConvertOpTo(InstanceTraits::Traits& tr, Value::TraceNullType isNull)
{
    OpStack.Back().Assign(Value(tr, isNull));
}

// TR::State::ConvertRegisterTo: register ind (+0x18) becomes a value of traits tr.
// @0x1424f1ed0
void TR::State::ConvertRegisterTo(SPInt ind, InstanceTraits::Traits& tr, Value::TraceNullType isNull)
{
    Registers[static_cast<UInt32>(ind)].Assign(Value(tr, isNull));
}


// The fixed slot of tr named name in ns, own or a parent's, or NULL; index receives its slot index. Object obj
// may initialize it on demand.
// @0x1425011c0
const SlotInfo* FindFixedSlot(const Traits& tr, const ASString& name, const Instances::Namespace& ns, UPInt& index,
                              Object* obj)
{
    const Slots& slots = tr;
    const SlotInfo* result = NULL;
    const UInt32* values = slots.FindSlotValues(name);
    if (values)
    {
        SPInt ind = *values;
        do
        {
            index = ind;
            const SlotInfo* si;
            if (AbsoluteIndex(ind) < slots.FirstOwnSlotNum)
                si = &slots.Parent->GetSlotInfo(AbsoluteIndex(ind));
            else
                si = &slots.VArray[static_cast<UInt32>(ind) - slots.FirstOwnSlotNum].Value;
            const Instances::Namespace& sns = *si->pNs;
            const unsigned kind = ns.GetKind();
            if (sns.GetKind() == kind)
            {
                bool same;
                switch (kind)
                {
                case Abc::NS_Protected:
                    same = true;
                    break;
                case Abc::NS_Private:
                    same = &ns == &sns;
                    break;
                default:
                    same = sns.GetUri().GetNode() == ns.GetUri().GetNode();
                    break;
                }
                if (same)
                {
                    result = si;
                    break;
                }
            }
            if (static_cast<UPInt>(ind) < slots.FirstOwnSlotNum)
                ind = slots.Parent->GetPrevSlotIndex(ind);
            else
                ind = slots.VArray[ind - slots.FirstOwnSlotNum].Prev;
        } while (ind >= 0);
    }
    if (obj)
        return obj->InitializeOnDemand(result, name, ns, index);
    return result;
}

// Multiname::IsQName in the SDK form (getNamespaceBits is MN_NS_Qualified or MN_NS_Runtime).
enum Sfr17MultinameKindBits
{
    Sfr17MN_NS_Mask      = 0x03,
    Sfr17MN_NS_Qualified = 0x00,
    Sfr17MN_NS_Runtime   = 0x01,
    Sfr17MN_NS_Multi     = 0x02
};
static inline bool Sfr17IsQName(const Multiname& mn)
{
    const Sfr17MultinameKindBits bits = (Sfr17MultinameKindBits)(mn.Kind & Sfr17MN_NS_Mask);
    return bits == Sfr17MN_NS_Qualified || bits == Sfr17MN_NS_Runtime;
}

// The fixed slot of tr that mn names (the first namespace of a set that has one), or NULL.
// MS2-FUNCTIONAL 0x142500f90: index and si_ptr swap r14 and r15 (register tie-break); otherwise the same code.
// @0x142500f90
const SlotInfo* FindFixedSlot(VM& vm, const Traits& tr, const Multiname& mn, UPInt& index, Object* obj)
{
    const AS3::Value& vn = mn.Name;
    StringManager& sm = vm.GetStringManager();
    ASString name = sm.GetBuiltin(AS3Builtin_empty_);
    if (!vn.Convert2String(name))
        // Exception.
        return NULL;

    const SlotInfo* si_ptr = NULL;

    // QName case ...
    if (Sfr17IsQName(mn))
        return FindFixedSlot(tr, name, *static_cast<const Instances::Namespace*>(mn.Obj.GetPtr()), index, obj);

    // Multiname case ...
    const ArrayLH<SPtr<Instances::Namespace> >& namespaces =
        static_cast<const NamespaceSet*>(mn.Obj.GetPtr())->GetNamespaces();
    const Slots& slots = tr;

    const UInt32* values = slots.FindSlotValues(name);
    const UPInt size = namespaces.GetSize();

    for (UPInt i = 0; i < size; ++i)
    {
        const Instances::Namespace& ns = *namespaces[i];

        if (values != NULL)
        {
            // Find a property with the same name and check namespace after that ...
            for (SPInt ind = *values; ind >= 0;
                 ind = (static_cast<UPInt>(ind) < slots.FirstOwnSlotNum) ? slots.Parent->GetPrevSlotIndex(ind)
                                                                         : slots.VArray[ind - slots.FirstOwnSlotNum].Prev)
            {
                // DO NOT forget to set index.
                index = static_cast<UPInt>(ind);
                const SlotInfo& si = (AbsoluteIndex(ind) < slots.FirstOwnSlotNum)
                    ? slots.Parent->GetSlotInfo(AbsoluteIndex(ind))
                    : slots.VArray[static_cast<UInt32>(ind) - slots.FirstOwnSlotNum].Value;
                const Instances::Namespace& cur_ns = *si.pNs;

                if (cur_ns.GetKind() == ns.GetKind())
                {
                    bool found = false;

                    switch (ns.GetKind())
                    {
                    case Abc::NS_Protected:
                        found = true;
                        break;
                    case Abc::NS_Private:
                        found = (&ns == &cur_ns);
                        break;
                    default:
                        found = (cur_ns.GetUri().GetNode() == ns.GetUri().GetNode());
                        break;
                    }

                    if (found)
                    {
                        si_ptr = &si;
                        break;
                    }
                }
            }
        }

        if (obj)
            si_ptr = obj->InitializeOnDemand(si_ptr, name, ns, index);

        if (si_ptr)
            break;
    }

    return si_ptr;
}

// @0x1424efd80
void CallFrame::ClearScopeStack()
{
    pScopeStack->Resize(ScopeStackBaseInd);
}

// The slot of c named name in namespace ns (same uri and kind), or NULL; FindDynamicSlot, inlined.
static SF_INLINE const SlotInfo* Sfr33FindDynamicSlotIn(const SlotContainerType& c, const ASString& name,
                                                        const Instances::Namespace& ns)
{
    const SlotInfo* result = NULL;
    const SPInt* values = c.FindValues(name);
    if (values)
    {
        for (SPInt ind = *values; ind >= 0; ind = c.VArray[static_cast<UPInt>(ind)].Prev)
        {
            const SlotInfo& si = c.VArray[static_cast<UInt32>(ind)].Value;
            if (*si.pNs == ns)
            {
                result = &si;
                break;
            }
        }
    }
    return result;
}

// The dynamic slot of c that mn names (the first namespace of a set that has one), or NULL.
// @0x142500c40
const SlotInfo* FindDynamicSlot(VM& vm, const SlotContainerType& c, const Multiname& mn)
{
    ASString name = vm.GetStringManager().CreateEmptyString();
    const bool ok = mn.Name.Convert2String(name);
    const SlotInfo* result = NULL;
    if (ok)
    {
        if ((static_cast<UInt32>(mn.Kind) & 3) >= 2)
        {
            const ArrayLH<SPtr<Instances::Namespace> >& nss =
                static_cast<const NamespaceSet*>(mn.Obj.GetPtr())->GetNamespaces();
            const SlotInfo* si = NULL;
            for (UPInt i = 0; i < nss.GetSize(); ++i)
            {
                si = Sfr33FindDynamicSlotIn(c, name, *nss[i]);
                if (si)
                    break;
            }
            return si;
        }
        result = Sfr33FindDynamicSlotIn(c, name, *static_cast<const Instances::Namespace*>(mn.Obj.GetPtr()));
    }
    return result;
}


// A property lookup that found something (not undefined, not a tagged null value).
static SF_INLINE bool Sfr33PropFound(const PropRef& prop)
{
    return prop.This.GetKind() != Value::kUndefined && reinterpret_cast<UPInt>(prop.pValue) != 1 &&
           !((static_cast<UByte>(reinterpret_cast<UPInt>(prop.pValue) >> 1) & 1) &&
             (reinterpret_cast<UPInt>(prop.pValue) & ~UPInt(2)) == 0);
}

__declspec(noinline) void Sfr33FindScopeProperty(PropRef& result, VM& vm, UPInt baseSSInd,
                                                const ScopeStackType& scope_stack, const Multiname& mn);

// A Value(Object*) for an object known to be non-null, with its ctor expanded in place; released on destruction.
struct Sfr33ThisValue
{
    UInt32 Flags;
    void* pWeakProxy;
    Object* pObj;
    void* pRest;
    explicit Sfr33ThisValue(Object* p) : Flags(Value::kObject), pWeakProxy(NULL), pObj(p) { p->AddRef(); }
    ~Sfr33ThisValue() { Get().~Value(); }
    Value& Get() { return *reinterpret_cast<Value*>(this); }
};

// A fixed-slot PropRef(si, index, Value(obj)) temporary, assigned field by field.
struct Sfr33ThisPropRef
{
    const SlotInfo* pSI;
    UPInt SlotIndex;
    Sfr33ThisValue This;
    Sfr33ThisPropRef(const SlotInfo* si, UPInt index, Object* obj) : pSI(si), SlotIndex(index), This(obj) { }
};

// Storage for a PropRef temporary whose dtor is expanded in place (only This needs releasing).
struct Sfr33PropRefTemp
{
    union
    {
        UPInt Align;
        UByte Buf[sizeof(PropRef)];
    };
    PropRef& Get() { return *reinterpret_cast<PropRef*>(Buf); }
    ~Sfr33PropRefTemp() { Get().This.~Value(); }
};

// @0x142502360
void Object::FindProperty(PropRef& result, const Multiname& mn, int attr)
{
    UPInt index = 0;
    const SlotInfo* si = FindFixedSlot(GetVM(), GetTraits(), mn, index, this);
    if (si)
    {
        Sfr33ThisPropRef t(si, index, this);
        result.pSI = t.pSI;
        result.SlotIndex = t.SlotIndex;
        result.This.Assign(t.This.Get());
        return;
    }
    if (GetTraits().IsDynamic() && (attr != 2 || GetTraits().GetTraitsType() != Traits_XML || !GetTraits().IsInstanceTraits()))
    {
        Sfr33PropRefTemp t;
        const PropRef& r = *::new (static_cast<void*>(t.Buf)) PropRef(FindDynamicSlot(mn));
        result.pSI = r.pSI;
        result.pValue = r.pValue;
        result.pObject = r.pObject;
        result.SlotIndex = r.SlotIndex;
        result.This.Assign(r.This);
    }
    if (Sfr33PropFound(result) || attr == 1)
        return;
    for (const Traits* t = &GetTraits(); t; t = t->GetParent())
    {
        Object* proto = &t->GetConstructor().GetPrototype();
        if (proto == this)
            break;
        proto->FindProperty(result, mn, attr);
        if (result)
            return;
    }
}

// A fixed-slot PropRef(si, index, v) temporary with its dtor expanded in place, assigned field by field.
struct Sfr33ScopePropRef
{
    const SlotInfo* pSI;
    UPInt SlotIndex;
    Value This;
    Sfr33ScopePropRef(const SlotInfo* si, UPInt index, const Value& v) : pSI(si), SlotIndex(index), This(v) { }
};

// The property named mn seen through scope value scope (a with scope or the global object also looks at its
// dynamic values and prototypes; a function falls back to its saved scope).
// @0x142502690
__declspec(noinline) void Sfr33FindPropertyWith(PropRef& result, VM& vm, const Value& scope, const Multiname& mn, int attr)
{
    const Value::KindType kind = scope.GetKind();
    const bool isObj = kind >= Value::kObject && kind <= Value::kFunction;
    const Traits& tr = vm.GetValueTraits(scope);
    UPInt index = 0;
    const SlotInfo* si = FindFixedSlot(vm, tr, mn, index, isObj ? scope.GetObject() : NULL);
    if (si)
    {
        Sfr33ScopePropRef t(si, index, scope);
        result.pSI = t.pSI;
        result.SlotIndex = t.SlotIndex;
        result.This.Assign(t.This);
        return;
    }
    if (!tr.IsGlobal() && !scope.GetWith())
        return;
    if (isObj && tr.IsDynamic() && (attr != 2 || !IsXMLObject(scope)))
    {
        Sfr33PropRefTemp t;
        result = static_cast<PropRef&&>(*::new (static_cast<void*>(t.Buf)) PropRef(scope.GetObject()->FindDynamicSlot(mn)));
    }
    if (Sfr33PropFound(result) || attr == 1)
        return;
    {
        Sfr33PropRefTemp tmp;
        ::new (static_cast<void*>(tmp.Buf)) PropRef();
        for (const Traits* t = &tr; t; t = t->GetParent())
        {
            Object* proto = &t->GetConstructor().GetPrototype();
            proto->FindProperty(tmp.Get(), mn, attr);
            if (Sfr33PropFound(tmp.Get()))
            {
                Sfr33ScopePropRef found(NULL, 0, scope);
                result.pSI = found.pSI;
                result.SlotIndex = found.SlotIndex;
                result.This.Assign(found.This);
                break;
            }
        }
    }
    if (!Sfr33PropFound(result) && scope.GetKind() == Value::kFunction)
        Sfr33FindScopeProperty(result, vm, 0,
                               *reinterpret_cast<const ScopeStackType*>(reinterpret_cast<const UByte*>(scope.GetObject()) + 0x40),
                               mn);
}

// The property named mn in the scope values above baseSSInd, innermost first.
// @0x142502a80
void Sfr33FindScopeProperty(PropRef& result, VM& vm, UPInt baseSSInd, const ScopeStackType& scope_stack,
                            const Multiname& mn)
{
    for (UPInt i = scope_stack.GetSize(); i > baseSSInd; --i)
    {
        Sfr33FindPropertyWith(result, vm, scope_stack[i - 1], mn, 0);
        if (result)
            return;
    }
}


// Tracer::CanBeNull of a traced value: values of class traits are never null, others go by their instance traits.
// @0x1424ee9e0
Value::TraceNullType Tracer::CanBeNull(const Value& v) const
{
    const Traits* tr;
    switch (v.GetKind())
    {
    case Value::kUndefined:
        tr = GetVM().TraitsVoid.GetPtr();
        break;
    case Value::kInstanceTraits:
        tr = &v.GetInstanceTraits();
        break;
    case Value::kClassTraits:
        tr = &v.GetClassTraits();
        break;
    default:
        tr = &GetVM().GetValueTraits(v);
        break;
    }
    if (tr)
    {
        if (tr == GetVM().TraitsClassClass.GetPtr())
            tr = GetVM().TraitsObject.GetPtr();
        if (tr)
        {
            if (tr->IsClassTraits())
                return Value::NotNull;
            return CanBeNull(*static_cast<const InstanceTraits::Traits*>(tr));
        }
    }
    return Value::NullOrNot;
}

// Clears the slot memory of a new instance (Value slots undefined, object and string pointers null).
// @0x1424f0a50
void Traits::ConstructTail(Object& obj) const
{
    const UPInt size = GetSlotInfoNum();
    for (UPInt i = 0; i < size; ++i)
    {
        const SlotInfo& si = Sfr17GetSlotInfo(*this, AbsoluteIndex(i));
        if (static_cast<bool>(si.CppBinding))
            continue;
        UByte* p = reinterpret_cast<UByte*>(&obj) + si.ValueInd;
        switch (si.BindType)
        {
        case SlotInfo::BT_Value:
            new (p) Value();
            break;
        case SlotInfo::BT_ObjectAS:
        case SlotInfo::BT_String:
            *reinterpret_cast<void**>(p) = NULL;
            break;
        default:
            break;
        }
    }
}

// @0x142507210
UPInt VM::GetAllLoadedAbcFiles(Scaleform::Array<SPtr<VMAbcFile> >* destArray) const
{
    UPInt i = 0;
    if (!InDestructor)
    {
        for (UPInt n = VMAbcFilesWeak.GetSize(); i < n; ++i)
        {
            destArray->PushBack(VMAbcFilesWeak[i]);
        }
    }
    return i;
}

// Releases the slot memory of a dying instance, last slot first (Value slots, tagged object pointers, strings).
// @0x1424f6de0
void Traits::DestructTail(Object& obj) const
{
    for (UPInt i = GetSlotInfoNum(); i > 0; --i)
    {
        const SlotInfo& si = Sfr17GetSlotInfo(*this, AbsoluteIndex(i - 1));
        if (static_cast<bool>(si.CppBinding))
            continue;
        UByte* p = reinterpret_cast<UByte*>(&obj) + si.ValueInd;
        switch (si.BindType)
        {
        case SlotInfo::BT_Value:
            reinterpret_cast<Value*>(p)->~Value();
            break;
        case SlotInfo::BT_ObjectAS:
            {
                // a tagged pointer: bit 0 marks a weak one (no count), bits 1..2 the object kind
                UPInt& ptr = *reinterpret_cast<UPInt*>(p);
                const UPInt raw = ptr;
                if (raw)
                {
                    const UPInt object = raw & ~UPInt(6);
                    if (object & 1)
                        ptr = (raw & 6) - 1 + object;
                    else
                        reinterpret_cast<ASRefCountBaseType*>(object)->Release();
                }
            }
            break;
        case SlotInfo::BT_String:
            if (ASStringNode* node = *reinterpret_cast<ASStringNode**>(p))
                node->Release();
            break;
        default:
            break;
        }
    }
}

// A primitive (a null object counts as one) is copied; a namespace gives its URI, a thunk or vtable index 0;
// an object gives its default value.
// noinline: the Convert2* callers call it, as in the exe.
// @0x1424f12a0
__declspec(noinline) CheckResult Value::Convert2PrimitiveValueUnsafe(Value& result, Hint hint) const
{
    if (IsPrimitive() || (IsObject() && GetObject() == NULL))
        result.Assign(*this);
    else
    {
        switch (GetKind())
        {
        case kNamespace:
            // The exe calls the out-of-line operator= (0x1424e0d40).
            (result.*static_cast<Value& (Value::*)(const ASString&)>(&Value::operator=))(GetNamespace()->GetUri());
            return true;
        case kThunk:
        case kThunkClosure:
        case kVTableInd:
        case kVTableIndClosure:
            result.SetNumber(0.0);
            return true;
        default:
            break;
        }
        FUN_142508bd0(reinterpret_cast<UPInt>(GetObject()), &result, hint);
        if (GetObject()->GetVM().IsException())
            return false;
    }
    return true;
}

// @0x1424f0f60
__declspec(noinline) CheckResult Value::Convert2Number(Number& result) const
{
    return Convert2NumberInline(result);
}

// ASString::AssignNode (inline in the exe at each use).
static __forceinline void Sfr17AssignNode(ASString& result, ASStringNode* node)
{
    result.AssignNode(node);
}

// ASString = String: the String's bytes made into a node (inline in the exe at each use).
static __forceinline void Sfr17AssignString(ASString& result, ASStringManager* sm, const String& str)
{
    result = sm->CreateString(str.ToCStr(), str.GetSize());
}

// ToString. Numbers use the ECMA formatting; an object goes through its primitive value (hint String), which must
// come back primitive.
// @0x1424f1390
CheckResult Value::Convert2String(ASString& result) const
{
    ASStringManager* sm = result.GetManager();
    switch (GetKind())
    {
    case kUndefined:
        Sfr17AssignNode(result, sm->CreateConstStringNode("undefined", 9, 0));
        break;
    case kThunk:
    case kVTableInd:
    case kThunkClosure:
    case kVTableIndClosure:
        Sfr17AssignNode(result, sm->CreateConstStringNode("function Function() {}", 22, 0));
        break;
    case kBoolean:
        {
            const bool b = AsBool();
            Sfr17AssignNode(result, sm->CreateConstStringNode(b ? "true" : "false", b ? 4 : 5, 0));
        }
        break;
    case kInt:
        Sfr17AssignString(result, sm, Scaleform::AsString(AsInt()));
        break;
    case kUInt:
        Sfr17AssignString(result, sm, Scaleform::AsString(AsUInt()));
        break;
    case kNumber:
        {
            char buffer[40];
            const UPInt len = FUN_142525f20(buffer, sizeof(buffer), AsNumber());
            Sfr17AssignNode(result, sm->CreateStringNode(buffer, len));
        }
        break;
    case kNamespace:
        result = AsNamespace().GetUri();
        break;
    case kObject:
    case kClass:
    case kFunction:
    case kThunkFunction:
        if (IsNull())
            Sfr17AssignNode(result, sm->CreateConstStringNode("null", 4, 0));
        else
        {
            Value v;
            if (!Convert2PrimitiveValueUnsafe(v, hintString))
                return false;
            if (!v.IsPrimitive())
            {
                VM& vm = v.GetObject()->GetVM();
                Sfr33ThrowTypeError(vm, VM::Error(VM::ErrorID(1050), vm, vm.GetValueTraits(v).GetName().ToCStr()));   // eConvertToPrimitiveError
                return false;
            }
            if (!v.Convert2String(result))
                return false;
        }
        break;
    case kInstanceTraits:
    case kClassTraits:
        Sfr17AssignNode(result, sm->GetEmptyStringNode());
        break;
    case kString:
        if (GetStringNode())
            Sfr17AssignNode(result, GetStringNode());
        else
            Sfr17AssignNode(result, sm->CreateConstStringNode("null", 4, 0));
        break;
    default:
        break;
    }
    return true;
}

// StringBuffer += String: the String's bytes appended (inline in the exe at each use).
static inline void Sfr17AppendString(StringBuffer& buf, const String& str)
{
    buf.AppendString(str.ToCStr(), str.GetSize());
}

// ToString appended to a buffer (SDK AS3_Value.cpp); same cases as above, without the primitive check on an object's value.
// @0x1424f17a0
CheckResult Value::Convert2String(StringBuffer& result) const
{
    switch (GetKind())
    {
    case kUndefined:
        result.AppendString("undefined");
        break;
    case kThunk:
    case kThunkClosure:
    case kVTableInd:
    case kVTableIndClosure:
        result.AppendString("function Function() {}");
        break;
    case kBoolean:
        result.AppendString(value.VS._1.VBool ? "true" : "false");
        break;
    case kInt:
        Sfr17AppendString(result, Scaleform::AsString(operator SInt32()));
        break;
    case kUInt:
        Sfr17AppendString(result, Scaleform::AsString(operator UInt32()));
        break;
    case kNumber:
        {
            char buffer[40];
            UPInt length = Sfr31NumberToChars(buffer, sizeof(buffer), value.VNumber);
            result.AppendString(buffer, length);
        }
        break;
    case kNamespace:
        result.AppendString(AsNamespace().GetUri().ToCStr());
        break;
    case kFunction:
    case kClass:
    case kObject:
    case kThunkFunction:
        if (IsNull())
            result.AppendString("null");
        else
        {
            Value v;
            if (!Convert2PrimitiveValueUnsafe(v, hintString))
                return false;
            if (!v.Convert2String(result))
                return false;
        }
        break;
    case kInstanceTraits:
    case kClassTraits:
        break;
    case kString:
        {
            ASStringNode* snode = value.VS._1.VStr;
            if (snode)
                result.AppendString(snode->pData, snode->Size);
            else
                result.AppendString("null");
        }
        break;
    default:
        break;
    }
    return true;
}

// ToInt32: undefined, thunks and null are 0; strings go through ToNumber, objects through their primitive value.
// @0x1424f0d30
CheckResult Value::Convert2Int32(SInt32& result) const
{
    switch (GetKind())
    {
    case kUndefined:
    case kThunk:
    case kThunkFunction:
        result = 0;
        break;
    case kInt:
    case kUInt:
    case kVTableInd:
        result = value.VS._1.VInt;
        break;
    case kBoolean:
        result = AsBool() ? 1 : 0;
        break;
    case kNumber:
        result = ConvertDouble2SInt32(AsNumber());
        break;
    case kString:
        if (GetStringNode())
        {
            Number n;
            if (!Convert2NumberInline(n))
                return false;
            result = ConvertDouble2SInt32(n);
        }
        else
            result = 0;
        break;
    default:
        if (IsNull())
            result = 0;
        else
        {
            Value v;
            if (!Convert2PrimitiveValueUnsafe(v))
                return false;
            if (!v.Convert2Int32(result))
                return false;
        }
        break;
    }
    return true;
}

// PropRef(const Value& _this, const SlotInfo* si, UPInt index) of the SDK, which our PropRef view lacks.
struct Sfr33SlotPropRef
{
    const SlotInfo* pSI;
    UPInt SlotIndex;
    Value This;
    Sfr33SlotPropRef(const Value& _this, const SlotInfo* si, UPInt index) : pSI(si), SlotIndex(index), This(_this) {}
    const PropRef& Get() const { return *reinterpret_cast<const PropRef*>(this); }
};

// The exe releases the dynamic lookup's PropRef temporary in place: only its This Value is destroyed.
static __forceinline void Sfr33AssignDynamicSlot(PropRef& result, Object* obj, const Multiname& mn)
{
    union Temp { PropRef ref; Temp() { } ~Temp() { } } t;
    result = static_cast<PropRef&&>(*new (&t.ref) PropRef(obj->FindDynamicSlot(mn)));
    t.ref.This.~Value();
}

// The property named mn of the object value stands for: its fixed slots, then (public names only) its dynamic
// values and the prototypes of its traits; a function falls back to its saved scope.
// @0x142501b00
void Sfr33FindObjProperty(PropRef& result, VM& vm, const Value& value, const Multiname& mn, int attr)
{
    const bool isObj = value.GetKind() >= Value::kObject && value.GetKind() <= Value::kFunction;
    const Traits* tr = &vm.GetValueTraits(value);
    UPInt index = 0;
    const SlotInfo* si = FindFixedSlot(vm, *tr, mn, index, isObj ? value.GetObject() : NULL);
    if (si)
    {
        result = Sfr33SlotPropRef(value, si, index).Get();
        return;
    }
    if (!mn.ContainsNamespace(vm.GetPublicNamespace()))
        return;
    if (isObj && tr->IsDynamic() && (attr != 2 || !IsXMLObject(value)))
        Sfr33AssignDynamicSlot(result, value.GetObject(), mn);
    if (Sfr33PropFound(result) || attr == 1)
        return;
    for (; tr; tr = tr->GetParent())
    {
        Object& proto = tr->GetConstructor().GetPrototype();
        proto.FindProperty(result, mn, attr);
        if (result)
            break;
    }
    if (!result && value.GetKind() == Value::kFunction)
        Sfr33FindScopeProperty(result, vm, 0,
                               *reinterpret_cast<const ScopeStackType*>(reinterpret_cast<const UByte*>(value.GetObject()) + 0x40),
                               mn);
}

// E4X equality of two QNames: same namespace (uri and kind) and the same local name; both need a namespace.
// @0x1424f97e0
CheckResult XMLSupportImpl::EqualsQName(bool& result, Instances::fl::QName& l, Instances::fl::QName& r) const
{
    result = l.Ns && r.Ns && *l.Ns == *r.Ns && l.LocalName.GetNode() == r.LocalName.GetNode();
    return true;
}

// E4X equality of two XML nodes: a text or attribute node against one with simple content compares their string
// forms, anything else the nodes themselves.
// @0x1424f9970
CheckResult XMLSupportImpl::EqualsXML(bool& result, Instances::fl::XML& l, Instances::fl::XML& r) const
{
    typedef Instances::fl::XML XML;
    const XML::Kind lk = l.GetKind();
    const XML::Kind rk = r.GetKind();
    if (((lk == XML::kText || lk == XML::kAttr) && r.HasSimpleContent()) ||
        ((rk == XML::kText || rk == XML::kAttr) && l.HasSimpleContent()))
    {
        StringBuffer lbuf(Memory::GetGlobalHeap());
        StringBuffer rbuf(Memory::GetGlobalHeap());
        l.ToString(lbuf, 0);
        r.ToString(rbuf, 0);
        result = lbuf.GetSize() == rbuf.GetSize() && strncmp(lbuf.ToCStr(), rbuf.ToCStr(), lbuf.GetSize()) == 0;
    }
    else
        result = l.EqualsInternal(r) == true3;
    return true;
}

// E4X equality of an XML node with simple content against a non-XML value: their string forms compared (stop set);
// a node without simple content leaves the comparison to the caller. False when r does not convert to a string.
// @0x1424f9850
CheckResult XMLSupportImpl::EqualsXML(bool& stop, bool& result, Instances::fl::XML& l, const Value& r) const
{
    stop = false;
    if (l.HasSimpleContent())
    {
        StringBuffer buf(Memory::GetGlobalHeap());
        ASString str = l.GetVM().GetStringManager().CreateEmptyString();
        l.ToString(buf, 0);
        if (!r.Convert2String(str))
            return false;
        result = strncmp(buf.ToCStr(), str.ToCStr(), str.GetSize()) == 0;
        stop = true;
        return true;
    }
    return true;
}

// @0x1424f9ae0
CheckResult XMLSupportImpl::EqualsXMLList(bool& result, Instances::fl::XMLList& l, const Value& v) const
{
    return l.Equals(result, v);
}

// flash.utils.describeType: a <type> element for value's traits (name, base, isDynamic/isFinal/isStatic), then one
// <extendsClass> per ancestor, the <implementsInterface> names, and a <constant>/<variable>/<method>/<accessor> per
// slot (a class value nests them in <factory>). Slots sharing a value index keep the one of the most derived type.
// The interfaces are listed from the parent's chain on, as the exe does; a failed append stops the listing.
// The type names are the traits' GetName() (slot 7), not GetQualifiedName, as the exe does.
// MS2-FUNCTIONAL 0x1424f4a90: our own reading of the exe; hash orders and string temporaries not reproduced
// @0x1424f4a90
void XMLSupportImpl::DescribeType(VM& vm, SPtr<Instances::fl::XML>& result, const Value& value) const
{
    typedef Instances::fl::XMLElement XMLElement;
    StringManager& sm = vm.GetStringManager();
    const Instances::Namespace& pns = vm.GetPublicNamespace();
    const Traits& tr = vm.GetValueTraits(value);
    const ASString strTrue = sm.GetBuiltin(AS3Builtin_true);
    const ASString strFalse = sm.GetBuiltin(AS3Builtin_false);
    const ASString strType = sm.CreateConstString("type");
    const Value::KindType kind = value.GetKind();
    const bool isClass = kind == Value::kClass;
    const Traits* parent = isClass ? static_cast<const Traits*>(&vm.GetClassTraitsClassClass()) : tr.GetParent();
    InstanceTraits::fl::XML& itr = static_cast<InstanceTraits::fl::XML&>(*GetITraitsXML());
    Pickable<XMLElement> xml = itr.MakeInstanceElement(itr, pns, strType, NULL);
    result = xml;

    const bool isObjKind = kind >= Value::kObject && kind <= Value::kThunkFunction;
    if (kind == Value::kUndefined || (isObjKind && value.GetObject() == NULL))
    {
        xml->AddAttr(pns, sm.CreateConstString("name"), isObjKind ? sm.CreateConstString("null") : tr.GetName());
        xml->AddAttr(pns, sm.CreateConstString("isDynamic"), strFalse);
        xml->AddAttr(pns, sm.CreateConstString("isFinal"), strTrue);
        xml->AddAttr(pns, sm.CreateConstString("isStatic"), strFalse);
    }
    else
    {
        xml->AddAttr(pns, sm.CreateConstString("name"), tr.GetName());
        if (parent)
            xml->AddAttr(pns, sm.CreateConstString("base"), parent->GetName());
        xml->AddAttr(pns, sm.CreateConstString("isDynamic"), isClass || tr.IsDynamic() ? strTrue : strFalse);
        xml->AddAttr(pns, sm.CreateConstString("isFinal"), isClass || tr.IsFinal() ? strTrue : strFalse);
        xml->AddAttr(pns, sm.CreateConstString("isStatic"), isClass || tr.IsClassTraits() ? strTrue : strFalse);

        if (parent)
        {
            const ASString strExtends = sm.CreateConstString("extendsClass");
            for (const Traits* t = parent; t; t = t->GetParent())
            {
                SPtr<XMLElement> el = itr.MakeInstanceElement(itr, pns, strExtends, NULL);
                if (!xml->AppendChild(Value(el.GetPtr())))
                    return;
                el->AddAttr(pns, strType, t->GetName());
            }
        }

        for (const Traits* t = parent; t; t = t->GetParent())
        {
            if (!t->IsInstanceTraits())
                continue;
            const ASString strImplements = sm.CreateConstString("implementsInterface");
            HashSetDH<ASString> seen(vm.GetMemoryHeap());
            ASString name = sm.CreateEmptyString();
            if (!t->IsAbcObject())
            {
                const InstanceTraits::CTraits& ct = static_cast<const InstanceTraits::CTraits&>(*t);
                for (UPInt i = 0; i < ct.ImplementsInterfaces.GetSize(); ++i)
                {
                    if (!ct.ImplementsInterfaces[i].Name.Convert2String(name) || seen.Get(name))
                        continue;
                    seen.Add(name);
                    SPtr<XMLElement> el = itr.MakeInstanceElement(itr, pns, strImplements, NULL);
                    if (!xml->AppendChild(Value(el.GetPtr())))
                        return;
                    el->AddAttr(pns, strType, name);
                }
            }
            else
            {
                const InstanceTraits::UserDefined& ut = static_cast<const InstanceTraits::UserDefined&>(*t);
                const ArrayLH_POD<int, StatMV_VM_AbcFile_Mem>& ifs = ut.GetClassInfo().inst_info.implemented_interfaces.info;
                VMAbcFile& file = ut.GetFile();
                for (UPInt i = 0; i < ifs.GetSize(); ++i)
                {
                    const Multiname mn(file, file.GetAbcFile().Const_Pool.GetMultiname(ifs[i]));
                    if (!mn.Name.Convert2String(name) || seen.Get(name))
                        continue;
                    seen.Add(name);
                    SPtr<XMLElement> el = itr.MakeInstanceElement(itr, pns, strImplements, NULL);
                    if (!xml->AppendChild(Value(el.GetPtr())))
                        return;
                    el->AddAttr(pns, strType, name);
                }
            }
        }

        const ASString strAccess = sm.CreateConstString("access");
        const ASString strAccessor = sm.CreateConstString("accessor");
        const ASString strMethod = sm.CreateConstString("method");
        const ASString strName = sm.CreateConstString("name");
        const ASString strDeclaredBy = sm.CreateConstString("declaredBy");
        const ASString strConstant = sm.CreateConstString("constant");
        const ASString strVariable = sm.CreateConstString("variable");
        const ASString strReturnType = sm.CreateConstString("returnType");
        const ASString strParameter = sm.CreateConstString("parameter");
        const ASString strIndex = sm.CreateConstString("index");
        const ASString strOptional = sm.CreateConstString("optional");
        const ASString strUri = sm.CreateConstString("uri");

        SPtr<XMLElement> cur = xml.GetPtr();
        if (isClass)
        {
            SPtr<XMLElement> factory = itr.MakeInstanceElement(itr, pns, sm.CreateConstString("factory"), NULL);
            if (!xml->AppendChild(Value(factory.GetPtr())))
                return;
            factory->AddAttr(pns, strType, tr.GetName());
            cur = factory;
        }

        // value index -> the slot that describes it
        HashDH<SInt32, UPInt> slots(vm.GetMemoryHeap());
        const UPInt slotNum = tr.GetSlotInfoNum();
        for (UPInt i = 0; i < slotNum; ++i)
        {
            const SlotInfo& si = tr.GetSlotInfo(AbsoluteIndex(i));
            const SInt32 key = si.ValueInd;
            if (UPInt* found = slots.Get(key))
            {
                const ClassTraits::Traits* prev = Sfr33SlotDataType(&tr.GetSlotInfo(AbsoluteIndex(*found)), &vm);
                const ClassTraits::Traits* next = Sfr33SlotDataType(&si, &vm);
                if (prev == next || (prev && next && FUN_1425149a0(*prev, *next)))
                    *found = i;
            }
            else
                slots.Add(key, i);
        }

        for (HashDH<SInt32, UPInt>::ConstIterator it = slots.Begin(); !it.IsEnd(); ++it)
        {
            const UPInt ind = it->Second;
            const SlotInfo& si = tr.GetSlotInfo(AbsoluteIndex(ind));
            const ASString slotName(tr.GetSlotNameNode(AbsoluteIndex(ind)));
            const SInt32 bt = si.BindType;
            const ASString& uri = si.pNs->GetUri();
            if (bt < SlotInfo::BT_Code)
            {
                const bool isConst = si.ReadOnly || (si.TI && si.TI->GetType() == Abc::TraitInfo::tConst);
                SPtr<XMLElement> el = itr.MakeInstanceElement(itr, pns, isConst ? strConstant : strVariable, NULL);
                if (!cur->AppendChild(Value(el.GetPtr())))
                    return;
                el->AddAttr(pns, strName, slotName);
                if (const ClassTraits::Traits* dt = Sfr33SlotDataType(&si, &vm))
                    el->AddAttr(pns, strType, dt->GetName());
                if (uri.GetSize() != 0)
                    el->AddAttr(pns, strUri, uri);
                continue;
            }

            SPtr<XMLElement> el = itr.MakeInstanceElement(itr, pns, bt == SlotInfo::BT_Code ? strMethod : strAccessor, NULL);
            if (!cur->AppendChild(Value(el.GetPtr())))
                return;
            el->AddAttr(pns, strName, slotName);
            if (bt != SlotInfo::BT_Code)
            {
                const char* access = bt == SlotInfo::BT_Get ? "readonly" : bt == SlotInfo::BT_Set ? "writeonly" : "readwrite";
                el->AddAttr(pns, strAccess, sm.CreateConstString(access));
            }
            if (uri.GetSize() != 0)
                el->AddAttr(pns, strUri, uri);

            const Value v = tr.GetVT().GetValue(AbsoluteIndex(si.ValueInd));
            const InstanceTraits::Traits* vt =
                reinterpret_cast<const InstanceTraits::Traits*>(::FUN_14250a060(reinterpret_cast<UPInt>(&vm), const_cast<Value*>(&v)));
            const InstanceTraits::Traits& objIT = vm.GetClassTraitsClassClass().GetInstanceTraits();
            ASString typeName = sm.CreateConstString("*");
            for (const InstanceTraits::Traits* p = vt; p != &objIT; p = static_cast<const InstanceTraits::Traits*>(p->GetParent()))
            {
                if (p == NULL)
                {
                    typeName = vt->GetName();
                    break;
                }
                if (p->SupportsInterface(objIT))
                    break;
            }
            el->AddAttr(pns, bt == SlotInfo::BT_Code ? strReturnType : strType, typeName);

            if (v.GetKind() != Value::kVTableInd)
                continue;
            const Value& entry = v.GetTraits().GetVT().VTMethods[v.GetVTableInd()];
            const Traits& declTr = entry.GetTraits();
            el->AddAttr(pns, strDeclaredBy, declTr.GetName());
            if (si.CppBinding)
                continue;
            VMAbcFile& file = *declTr.GetFilePtr();
            const Abc::File& abc = file.GetAbcFile();
            const Abc::MethodInfo& mi = *abc.Methods.Info[entry.GetMethodInd()];
            const UPInt n = mi.ParamTypes.GetSize();
            const UPInt firstOpt = n - mi.OptionalParams.GetSize();
            for (UPInt i = 0; i < n; ++i)
            {
                LongFormatter f(static_cast<UInt64>(i));
                SPtr<XMLElement> param = itr.MakeInstanceElement(itr, pns, strParameter, NULL);
                if (!el->AppendChild(Value(param.GetPtr())))
                    return;
                f.Convert();
                param->AddAttr(pns, strIndex, sm.CreateString(f.ToCStr(), f.GetSize()));
                const Multiname pmn(file, abc.Const_Pool.GetMultiname(mi.ParamTypes[i]));
                ASString ptype = sm.CreateEmptyString();
                pmn.Name.Convert2String(ptype);
                param->AddAttr(pns, strType, ptype);
                param->AddAttr(pns, strOptional, i < firstOpt ? strFalse : strTrue);
            }
        }
    }
}

// The descendants named mn of an XML or XMLList instance v, as a new list that replaces v; false for anything else.
// True for an object value with instance traits of the given builtin type.
static SF_INLINE bool Sfr33IsInstanceOf(const Value& v, BuiltinTraitsType tt)
{
    if (v.IsObject() && v.GetObject())
    {
        const Traits& tr = v.GetObject()->GetTraits();
        return tr.GetTraitsType() == tt && tr.IsInstanceTraits();
    }
    return false;
}

// @0x142509140
CheckResult XMLSupportImpl::GetDescendants(Value& v, const Multiname& mn) const
{
    bool result = false;
    if (Sfr33IsInstanceOf(v, Traits_XML))
    {
        InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(*GetITraitsXMLList());
        Pickable<Instances::fl::XMLList> list = itr.MakeInstance(itr);
        static_cast<Instances::fl::XML*>(v.GetObject())->GetDescendants(*list, mn);
        v.Pick(list);
        result = true;
    }
    else if (Sfr33IsInstanceOf(v, Traits_XMLList))
    {
        InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(*GetITraitsXMLList());
        Pickable<Instances::fl::XMLList> list = itr.MakeInstance(itr);
        FUN_142415930(static_cast<Instances::fl::XMLList*>(v.GetObject()), *list, mn);
        v.Pick(list);
        result = true;
    }
    return result;
}

// A not-found PropRef() whose dtor is expanded in place (only This needs releasing).
struct Sfr17EmptyPropRef
{
    const SlotInfo* pSI;
    UPInt SlotIndex;
    Value This;
    Sfr17EmptyPropRef() : pSI(0), SlotIndex(0) {}
    PropRef& Get() { return *reinterpret_cast<PropRef*>(this); }
};

// PropRef::GetSlotValueUnsafe (0x14250e200, sfr_as3_18), which the exe inlines here.
static __forceinline CheckResult Sfr17GetSlotValueUnsafe(const PropRef& prop, VM& vm, Value& value)
{
    bool ok = true;
    const UPInt w = reinterpret_cast<UPInt>(prop.pValue);
    switch (w & 3)
    {
    case 0:
    {
        char r;     // the callee's result slot
        ok = *reinterpret_cast<const bool*>(FUN_14250e2d0(prop.pSI, &r, &vm, &value, &prop.This, NULL, 0));
        break;
    }
    case 1:
        value.AssignUnsafe(*reinterpret_cast<const Value*>(w & ~static_cast<UPInt>(1)));
        break;
    case 2:
        value.AssignUnsafe(reinterpret_cast<Object*>(w & ~static_cast<UPInt>(2)));
        break;
    }
    return CheckResult(ok);
}

// VM::ExecutePropertyUnsafe: calls the property prop_name of _this with argv; a null or undefined property is a
// TypeError (#1009). False when the property is missing or its value could not be read, or the call threw.
// @0x1424ff910
CheckResult ExecutePropertyUnsafe(VM& vm, const Multiname& prop_name, const Value& _this, Value& result, unsigned argc,
                                  const Value* argv)
{
    Sfr17EmptyPropRef t;
    PropRef& prop = t.Get();
    Sfr33FindObjProperty(prop, vm, _this, prop_name, 0);
    if (Sfr33PropFound(prop))
    {
        Value func;
        if (Sfr17GetSlotValueUnsafe(prop, vm, func))
        {
            if (!func.IsNullOrUndefined())
            {
                vm.ExecuteInternalUnsafe(func, _this, result, argc, argv, false);
                return !vm.IsException();
            }
            Sfr33ThrowTypeError(vm, VM::Error(VM::eConvertNullToObjectError, vm));
        }
    }
    return false;
}

// A Value(Object*) with its ctor expanded in place (AddRef on construction); the caller releases the object.
struct Sfr33TempObjectValue
{
    UInt32 Flags;
    void* pWeakProxy;
    Object* pObj;
    void* pRest;
    explicit Sfr33TempObjectValue(Object* p) : Flags(Value::kObject), pWeakProxy(NULL), pObj(p)
    {
        if (p)
            p->AddRef();
    }
    const Value& Get() const { return *reinterpret_cast<const Value*>(this); }
};

// The property named mn of the first global object (of the ABC file of tr, when given) that has one.
// MS2-FUNCTIONAL 0x142501750: result and the array size swap rbp and r14; the code is otherwise the exe's.
// @0x142501750
void Sfr33FindGOProperty(PropRef& result, VM& vm, const ArrayLH<Instances::fl::GlobalObject*>& go, const Multiname& mn,
                         const Traits* tr)
{
    VMAbcFile* file = NULL;
    if (tr)
        file = tr->GetFilePtr();
    const UPInt size = go.GetSize();
    for (UPInt i = 0; i < size; ++i)
    {
        Object* obj = reinterpret_cast<Object*>(go[i]);
        if (tr && file != obj->GetTraits().GetFilePtr())
            continue;
        {
            const Sfr33TempObjectValue v(obj);
            Sfr33FindPropertyWith(result, vm, v.Get(), mn, 0);
        }
        if (!(reinterpret_cast<UPInt>(obj) & 1) && obj)
            obj->Release();
        if (result)
            return;
    }
}

// Tracer State::FindProp: the fixed slot mn names, looked up statically through the traced scope stack (State +0x58,
// innermost first; stype 0), then the function's saved scopes (stype 1), then the class or global object that
// defines it (stype 2); scope_index is the stack index tried last. A run-time name or a with scope stops the search.
// MS2-FUNCTIONAL 0x142501e80: SDK State::FindProp body over raw tracer state offsets; regalloc only, same length (1246): the exe keeps the VM in r12, the scope count in r13 and result in r15, ours rotates them; the exe tests kinds 8 and 9 with sub/je/cmp/je, ours with one range check
// The tracer's VM (Tracer::GetVM: CF -> file -> VM), as State::GetVM re-reads it.
static SF_FORCEINLINE VM& Sfr17TrGetVM(UPInt tracer)
{
    return **reinterpret_cast<VM**>(*reinterpret_cast<const UPInt*>(*reinterpret_cast<const UPInt*>(tracer + 0x20) + 0x28) + 0x20);
}
// Tracer::GetValueTraits(v, false) (0x14250ff00) as the exe inlines it here.
// The exe reads v's flags word once, before the call, for both the kind and the with test that follows.
static SF_FORCEINLINE const Traits* Sfr17TrGetValueTraits(UPInt tracer, const Value& v, UInt32 vflags)
{
    const Traits* result = NULL;
    switch (vflags & 0x1f)
    {
    case 0:
        result = *reinterpret_cast<Traits* const*>(reinterpret_cast<const UByte*>(&Sfr17TrGetVM(tracer)) + 0x278);
        break;
    case 8:
    case 9:
        result = *reinterpret_cast<Traits* const*>(reinterpret_cast<const UByte*>(&v) + 0x10);
        break;
    default:
        result = &Sfr17TrGetVM(tracer).GetValueTraits(v);
    }
    if (result && result == *reinterpret_cast<Traits* const*>(reinterpret_cast<const UByte*>(&Sfr17TrGetVM(tracer)) + 0x1f0))
        result = *reinterpret_cast<Traits* const*>(reinterpret_cast<const UByte*>(&Sfr17TrGetVM(tracer)) + 0x1f8);
    return result;
}
// @0x142501e80
void FUN_142501e80(void* state, void* propRef, void* multiname, void* stypeOut, void* scopeIndexOut)
{
    PropRef& result = *static_cast<PropRef*>(propRef);
    const Multiname& mn = *static_cast<const Multiname*>(multiname);
    UInt32& stype = *static_cast<UInt32*>(stypeOut);
    UPInt& scope_index = *static_cast<UPInt*>(scopeIndexOut);
    const UPInt* st = static_cast<const UPInt*>(state);
    if ((mn.Kind & 3) == 1 || (static_cast<UByte>(static_cast<UInt32>(mn.Kind) >> 2) & 1) != 0)
        return;

    VM& vm = Sfr17TrGetVM(st[0]);
    const UByte* const vmb = reinterpret_cast<const UByte*>(&vm);
    UPInt slot_index = 0;

    for (UPInt i = st[0xc]; i > 0; --i)
    {
        scope_index = i - 1;
        const Value& v = reinterpret_cast<const Value*>(st[0xb])[scope_index];
        const UInt32 vflags = *reinterpret_cast<const UInt32*>(&v);
        const Traits* tr = Sfr17TrGetValueTraits(st[0], v, vflags);

        if ((vflags >> 8) & 1)
            return;

        if (tr && !tr->IsGlobal())
        {
            const SlotInfo* si = FindFixedSlot(vm, *tr, mn, slot_index, NULL);
            if (si)
            {
                stype = 0;
                Sfr33ScopePropRef t(si, slot_index, v);
                result.pSI = t.pSI;
                result.SlotIndex = t.SlotIndex;
                result.This.Assign(t.This);
                return;
            }
        }
    }

    {
        const UPInt* ss = *reinterpret_cast<UPInt* const*>(*reinterpret_cast<const UPInt*>(st[0] + 0x20) + 0x38);
        for (UPInt i = ss ? ss[1] : 0; i > 0; --i)
        {
            scope_index = i - 1;
            const Value& v = reinterpret_cast<const Value*>(ss[0])[scope_index];
            const Traits& tr = vm.GetValueTraits(v);

            if (v.GetWith())
                return;

            const SlotInfo* si = FindFixedSlot(vm, tr, mn, slot_index, NULL);
            if (si)
            {
                stype = 1;
                Sfr33ScopePropRef t(si, slot_index, v);
                result.pSI = t.pSI;
                result.SlotIndex = t.SlotIndex;
                result.This.Assign(t.This);
                return;
            }
        }
    }

    const unsigned nameKind = mn.Name.GetKind();
    if (nameKind == 8 || nameKind == 9)
        return;
    const Traits* ctr = FUN_14250d760(vm, mn);
    if (ctr)
    {
        if (const UByte* itr = *reinterpret_cast<UByte* const*>(reinterpret_cast<const UByte*>(ctr) + 0xc0))
        {
            Object* obj = NULL;
            if ((itr[0x68] >> 4) & 1)
                obj = *reinterpret_cast<Object* const*>(itr + 0xd0);
            else
                obj = *reinterpret_cast<Object* const*>(vmb + 0x298);
            UPInt slot_index = 0;
            const SlotInfo* si = FindFixedSlot(vm, obj->GetTraits(), mn, slot_index, obj);
            if (si)
            {
                {
                    Sfr33ThisPropRef t(si, slot_index, obj);
                    result.pSI = t.pSI;
                    result.SlotIndex = t.SlotIndex;
                    result.This.Assign(t.This.Get());
                }
                stype = 2;
                return;
            }
        }
    }
    Sfr33FindGOProperty(result, vm, *reinterpret_cast<const ArrayLH<Instances::fl::GlobalObject*>*>(vmb + 0x1a8), mn, ctr);
    if (Sfr33PropFound(result))
        stype = 2;
}

// Object::DeleteDynamicSlotValuePair: removes the dynamic property prop_name names (namespaces are not looked at).
// @0x1424f4540
CheckResult Object::DeleteDynamicSlotValuePair(const Multiname& prop_name)
{
    ASString str_name(GetVM().GetStringManager().CreateEmptyString());
    if (!prop_name.Name.Convert2String(str_name))
        return false;

    bool result = true;
    if (DynAttrs.Get(DynAttrsKey(str_name)))
        DynAttrs.Remove(DynAttrsKey(str_name));
    else
        result = false;

    return result;
}

// Value(Object*) as the exe inlines it here (its out-of-line copy is sfr_as3_15's 0x1424dc050)
SF_FORCEINLINE Value::Value(Object* v, InlineObjType)
    : Flags(kObject)
    , value(v)
{
    if (v)
        v->AddRef();
}

SF_FORCEINLINE PropRef::PropRef(Object* obj, Value* v, Value::InlineObjType)
    : pValue(reinterpret_cast<Value*>(reinterpret_cast<UPInt>(v) | 1))
    , This(obj, Value::InlineObj)
{
}

// The dynamic value of this object that mn names (namespaces are not looked at).
// @0x142500e50
PropRef Object::FindDynamicSlot(const Multiname& mn)
{
    ASString name = GetVM().GetStringManager().CreateEmptyString();
    if (!mn.Name.Convert2String(name))
        return PropRef();
    return PropRef(this, DynAttrs.Get(DynAttrsKey(name)), Value::InlineObj);
}

// The call frame on top of the VM's paged frame stack.
static SF_INLINE const UByte* Sfr33BackFrame(const VM& vm, UPInt n)
{
    --n;
    return reinterpret_cast<const UByte* const*>(vm.Unk070[4])[n >> 6] + (n & 0x3f) * 0xa8;
}

// The property named mn seen from the current call: the scope stack above the frame's base, the frame's saved
// scope, then the global objects of the ABC file that defines mn's traits.
// @0x142502570
void Sfr33VMFindProperty(VM& vm, PropRef& result, const Multiname& mn)
{
    const UPInt n = vm.Unk070[1];
    Sfr33FindScopeProperty(result, vm, n == 0 ? 0 : *reinterpret_cast<const UPInt*>(Sfr33BackFrame(vm, n) + 8), vm.ScopeStack, mn);
    if (!Sfr33PropFound(result))
    {
        const ScopeStackType* saved = *reinterpret_cast<const ScopeStackType* const*>(Sfr33BackFrame(vm, vm.Unk070[1]) + 0x38);
        if (saved)
            Sfr33FindScopeProperty(result, vm, 0, *saved, mn);
    }
    if (!Sfr33PropFound(result))
        Sfr33FindGOProperty(result, vm, *reinterpret_cast<const ArrayLH<Instances::fl::GlobalObject*>*>(&vm.GlobalObjects),
                            mn, FUN_14250d760(vm, mn));
}

// The loaded ABC file whose source is name (NULL when none is).
// @0x142502d00
SPtr<VMAbcFile> VM::FindVMAbcFileWeak(const char* name) const
{
    for (UPInt i = 0; i < VMAbcFilesWeak.GetSize(); ++i)
    {
        if (strcmp(VMAbcFilesWeak[i]->GetAbcFile().Source.ToCStr(), name) == 0)
            return VMAbcFilesWeak[i];
    }
    return NULL;
}

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

// MovieRoot::CreateString / CreateStringW (virtual): a host value holding the string (null for the null string).
struct Sfr33MovieRootStrings
{
    MovieRoot* Root() { return reinterpret_cast<MovieRoot*>(this); }
    void CreateString(GFx::Value* pvalue, const char* pstring);
    void CreateStringW(GFx::Value* pvalue, const wchar_t* pstring);
};

// @0x1424f41f0
void Sfr33MovieRootStrings::CreateString(GFx::Value* pvalue, const char* pstring)
{
    ASString s(Root()->BuiltinsMgr.GetStringManager()->CreateStringNode(pstring));
    Root()->ASValue2GFxValue(Value(s, Value::InlineStr), pvalue);
}

// @0x1424f42d0
void Sfr33MovieRootStrings::CreateStringW(GFx::Value* pvalue, const wchar_t* pstring)
{
    ASString s(Root()->BuiltinsMgr.GetStringManager()->CreateStringNode(pstring));
    Root()->ASValue2GFxValue(Value(s, Value::InlineStr), pvalue);
}

// Runs the action unless its character was unloaded: an event fired at the character, a function called on its
// AS3 object (an exception is printed and flags the character), or the C callback.
// @0x1424f9b00
void MovieRoot::ActionEntry::Execute(MovieRoot* proot) const
{
    if (!pCharacter || pCharacter->IsUnloaded())
        return;
    switch (Type)
    {
    case Entry_Event:
        FUN_142502e70(ToAvmDisplayObj(pCharacter), mEventId);
        break;
    case Entry_Function:
    {
        Value _this(reinterpret_cast<Object*>(ToAvmDisplayObj(pCharacter)->GetAS3Obj()), Value::InlineObj);
        Value result;
        proot->pAVM->ExecuteInternalUnsafe(Function, _this, result, 0, NULL, false);
        if (proot->pAVM->IsException())
        {
            proot->pAVM->OutputAndIgnoreException();
            *reinterpret_cast<UInt16*>(reinterpret_cast<UByte*>(pCharacter.GetPtr()) + 0x88) |= 0x20;
        }
        break;
    }
    case Entry_CFunction:
        if (CFunction)
            CFunction(*this);
        break;
    default:
        break;
    }
}

// UserDefinedFunction::Execute (virtual): runs the function on _this; the result goes on the caller's operand
// stack unless discarded.
// @0x1424f9ce0
void UserDefinedFunction::Execute(const Value& _this, unsigned argc, const Value* argv, bool discard_result)
{
    void* self = this;
    Value result;
    FUN_1424feb00(self, _this, result, argc, argv);
    if (!discard_result)
        FUN_14241e4f0(static_cast<Object*>(self), result);
}

// MovieRoot::ChangeMouseCursorType (virtual): with the GFx extensions on and a stage, a mouseCursorChange event
// goes to the stage first; unless a listener cancels it the application's handler gets the cursor request.
struct Sfr33MovieRootCursor : MovieRoot
{
    void ChangeMouseCursorType(unsigned mouseIdx, unsigned newCursorType);
};

// @0x1424eeae0
void Sfr33MovieRootCursor::ChangeMouseCursorType(unsigned mouseIdx, unsigned newCursorType)
{
    UByte* const avm = reinterpret_cast<UByte*>(pAVM);
    if (pStage && avm && avm[0x3a0] && *reinterpret_cast<const int*>(reinterpret_cast<UByte*>(pStage) + 0x128))
    {
        Classes::fl_events::EventDispatcher* cls = *reinterpret_cast<Classes::fl_events::EventDispatcher**>(avm + 0x390);
        ASString name(BuiltinsMgr.GetBuiltin(AS3Builtin_empty_));
        GetMouseCursorTypeString(name, newCursorType);
        SPtr<Instances::fl_events::Event> evt = cls->CreateMouseCursorEventObject(name, mouseIdx);
        Instances::fl_display::DisplayObject* stage =
            Sfr33ToAvmIntObjInline(static_cast<InteractiveObject*>(pStage))->GetAS3Obj();
        if (stage && !stage->DispatchEventObject(evt.GetPtr(), pStage))
            return;
    }
    if (pMovieImpl->pUserEventHandler)
    {
        pMovieImpl->pUserEventHandler->HandleEvent(pMovieImpl->AsMovie(),
            MouseCursorEvent(static_cast<MouseCursorEvent::CursorShapeType>(newCursorType), mouseIdx));
    }
}

// MovieRoot::CreateArray (virtual): a host value holding a new empty Array.
struct Sfr33MovieRootArray
{
    MovieRoot* Root() { return reinterpret_cast<MovieRoot*>(this); }
    void CreateArray(GFx::Value* pvalue);
};

// VM::MakeArray (0x142516270), which the exe inlines here.
static __forceinline Pickable<Instances::fl::Array> Sfr33MakeArray(const VM& vm)
{
    InstanceTraits::fl::Array& itr = static_cast<InstanceTraits::fl::Array&>(vm.GetClassTraitsArray().GetInstanceTraits());
    return itr.MakeInstance(itr);
}

// A Value picking a new object, with Value::PickUnsafe(Object*) expanded in place as the exe has it: kind
// kObject, no weak proxy, and the value words copied from a temporary holding only the object.
struct Sfr33PickedObjectValue
{
    struct Words { Object* pObj; void* pRest; };
    UInt32 Flags;
    void* pWeakProxy;
    Words V;
    explicit Sfr33PickedObjectValue(Object* p)
    {
        pWeakProxy = NULL;
        Flags = Value::kObject;
        Words w;
        w.pObj = p;
        V = w;
    }
    ~Sfr33PickedObjectValue() { Get().~Value(); }
    Value& Get() { return *reinterpret_cast<Value*>(this); }
};

// @0x1424f2700
void Sfr33MovieRootArray::CreateArray(GFx::Value* pvalue)
{
    Sfr33PickedObjectValue v(Sfr33MakeArray(*Root()->pAVM).GetPtr());
    Root()->ASValue2GFxValue(v.Get(), pvalue);
}

// MovieRoot::DoActions (virtual): the pending constructors, then the actions of every level up to AL_Render; a
// pending exception is dropped.
// @0x1424f73d0
void Sfr33MovieRootDoActions(MovieRoot* self)
{
    Sfr33MovieRootExecuteCtors(reinterpret_cast<UByte*>(self));
    for (unsigned lvl = MovieRoot::AL_Highest; lvl < MovieRoot::AL_Count_; ++lvl)
        self->ExecuteActionQueue(static_cast<MovieRoot::ActionLevel>(lvl));
    UByte* vm = reinterpret_cast<UByte*>(self->pAVM);
    if (vm[0x180])
        vm[0x180] = 0;
}

// Releases the value the slot si binds in obj (a Value, an object pointer or a string node).
// @0x1424f6b30
void Sfr33SlotReleaseMember(const SlotInfo& si, Object& obj)
{
    UByte* p = reinterpret_cast<UByte*>(&obj) + si.ValueInd;
    switch (si.BindType)
    {
    case SlotInfo::BT_Value:
        reinterpret_cast<Value*>(p)->~Value();
        break;
    case SlotInfo::BT_ObjectAS:
    {
        // STPtr::~STPtr: the object tag (bits 1..2) is stripped before the release.
        GASRefCountBase*& pobj = *reinterpret_cast<GASRefCountBase**>(p);
        if (pobj)
        {
            GASRefCountBase* addr = (GASRefCountBase*)((UPInt)pobj & ~(UPInt)Value::ObjectTagMask);
            if ((UPInt)addr & 1)
                pobj = (GASRefCountBase*)((UPInt)addr - 1 + GetObjectTag((UPInt)pobj));
            else
                addr->Release();
        }
        break;
    }
    case SlotInfo::BT_String:
    {
        ASStringNode* node = *reinterpret_cast<ASStringNode**>(p);
        if (node)
            node->Release();
        break;
    }
    default:
        break;
    }
}

// result receives the class named gname, or a ReferenceError is thrown (false).
// @0x142508140
bool Sfr33GetClassValue(VM& vm, const StringDataPtr& gname, Value& result)
{
    Class* cls = vm.GetClass(gname);
    if (cls)
    {
        result.AssignUnsafe(cls);
        return true;
    }
    if (!vm.IsException())
    {
        Sfr33ThrowReferenceError(vm, VM::Error(VM::eUndefinedVarError, vm, gname.ToCStr()));
    }
    return false;
}

// The value of a tagged object address (bits 1..2: object, class, function, namespace).
// The out-of-line Value::Assign/AssignUnsafe copies for functions and namespaces (sfr_as3_03 defines them).
struct ValueAssignCopies
{
    static void AssignFunction(Value& v, Instances::Function* p);          // 0x1424052a0
    static void AssignUnsafeFunction(Value& v, Instances::Function* p);    // 0x1424053f0
    static void AssignUnsafeNamespace(Value& v, Instances::Namespace* p);  // 0x142405420
    static void ReleaseInternal(Value& v) { v.ReleaseInternal(); }        // 0x142521f00, out of line
};
} } }
static __forceinline void Sfr33ValueReleaseInternal(Scaleform::GFx::AS3::Value& v) { Scaleform::GFx::AS3::ValueAssignCopies::ReleaseInternal(v); }
namespace Scaleform { namespace GFx { namespace AS3 {

// @0x142506d60
Value GetAbsObject(UPInt addr)
{
    Value result;
    const int kind = addr & 6;
    addr -= kind;
    switch (kind)
    {
    case 0:
        result.AssignUnsafe(reinterpret_cast<Object*>(addr));
        break;
    case 2:
        result.AssignUnsafe(reinterpret_cast<Class*>(addr));
        break;
    case 4:
        ValueAssignCopies::AssignUnsafeFunction(result, reinterpret_cast<Instances::Function*>(addr));
        break;
    case 6:
        ValueAssignCopies::AssignUnsafeNamespace(result, reinterpret_cast<Instances::Namespace*>(addr));
        break;
    }
    return result;
}

// ToNumber of a string (kind is kString) or of an object through its primitive value (SDK AS3_Value.cpp).
// @0x1424f1000
CheckResult Value::Convert2NumberInternal(Number& result, KindType kind) const
{
    if (kind == kString)
    {
        const ASStringNode* sn = value.VS._1.VStr;
        if (sn)
        {
            const UInt32 len = sn->Size;
            if (len)
            {
                UInt32 offset;
                const char* str = sn->pData;
                Number d = NumberUtil::StringToDouble(str, len, &offset);
                if (NumberUtil::IsNaN(d) || d == 0.0)
                {
                    if (offset == len)
                    {
                        result = NumberUtil::POSITIVE_ZERO();
                        return true;
                    }
                    else
                    {
                        if (d == 0.0)
                        {
                            UInt32 index = static_cast<UInt32>(UTF8Util::GetByteIndex(ASUtils::SkipWhiteSpace(str + offset), str + offset, len - offset));
                            if (index + offset >= len)
                            {
                                result = d;
                                return true;
                            }
                        }

                        d = NumberUtil::StringToInt(str, len, 0, &offset);
                    }
                }

                UInt32 index = static_cast<UInt32>(UTF8Util::GetByteIndex(ASUtils::SkipWhiteSpace(str + offset), str + offset, len - offset));
                if (index + offset >= len)
                {
                    result = d;
                    return true;
                }
            }
            else
            {
                result = NumberUtil::POSITIVE_ZERO();
                return true;
            }

            result = NumberUtil::NaN();
        }
        else
            result = NumberUtil::POSITIVE_ZERO();
    } else
    {
        if (IsNull())
            result = NumberUtil::POSITIVE_ZERO();
        else
        {
            Value v;
            if (!Convert2PrimitiveValueUnsafe(v, hintNumber))
                return false;
            if (!v.Convert2Number(result))
                return false;
        }
    }
    return true;
}

// ToUInt32 (undefined, thunks and null give 0).
// @0x1424f1a30
CheckResult Value::Convert2UInt32(UInt32& result) const
{
    switch (GetKind())
    {
    case kUndefined:
    case kThunk:
    case kThunkFunction:
        result = 0;
        break;
    case kInt:
    case kUInt:
        result = value.VS._1.VUInt;
        break;
    case kBoolean:
        result = AsBool() ? 1 : 0;
        break;
    case kNumber:
        result = ConvertDouble2SInt32(AsNumber());
        break;
    case kString:
        if (GetStringNode())
        {
            Number n;
            if (!Convert2NumberInline(n))
                return false;
            result = ConvertDouble2SInt32(n);
        }
        else
            result = 0;
        break;
    default:
        if (IsNull())
            result = 0;
        else
        {
            Value v;
            if (!Convert2PrimitiveValueUnsafe(v))
                return false;
            if (!v.Convert2UInt32(result))
                return false;
        }
        break;
    }
    return true;
}

// HashSetBase<ASString, Class*>::CheckExpand look-alike calling its byte-identical setRawCapacity copy.
// @0x1424eefa0
void Sfr33ClassHashCheckExpand(void* self, void* pheapAddr)
{
    // the CheckExpand of the MethodBodyInfo hash (one body with this hash's in the exe)
    reinterpret_cast<Sfr33MethodBodyHashBase*>(self)->CheckExpand(pheapAddr);
    //
    //
    //
}

// The default value of a slot of type ctr: false, 0, NaN for the primitive types; undefined for the
// ClassClass traits (+0x1f0), else null.
// @0x142508a80
SF_NOINLINE Value* Sfr33GetDefaultValue(VM* vm, Value* result, const ClassTraits::Traits& ctr)
{
    switch (*reinterpret_cast<const int*>(reinterpret_cast<const UByte*>(&ctr) + 0x70))
    {
    case 1:
        ::new (result) Value(false);
        return result;
    case 2:
        ::new (result) Value(SInt32(0));
        return result;
    case 3:
        ::new (result) Value(UInt32(0));
        return result;
    case 4:
        ::new (result) Value(NumberUtil::NaN());
        return result;
    default:
        if (&ctr == *reinterpret_cast<ClassTraits::Traits* const*>(reinterpret_cast<const UByte*>(vm) + 0x1f0))
        {
            ::new (result) Value(Value::GetUndefined());
            return result;
        }
        break;
    }

    ::new (result) Value(Value::GetNull());
    return result;
}

// The default value of a slot declared with the ABC multiname mn of file (undefined for the any type or an
// unresolved name).
// @0x1425089a0
Value* Sfr33GetDefaultValueOfType(VM* vm, Value* result, const UByte* file, const UByte* mn)
{
    if (mn != *reinterpret_cast<UByte* const*>(file + 0x28) + 0xe8)
    {
        const ClassTraits::Traits* ctr = static_cast<const ClassTraits::Traits*>(FUN_142524f60(vm, file, mn));
        if (ctr)
        {
            Sfr33GetDefaultValue(vm, result, *ctr);
            return result;
        }
    }
    ::new (result) Value(Value::GetUndefined());
    return result;
}

// ind receives the array index the string sn spells (decimal digits, no leading zero, at most UInt32 max).
// @0x142507490
CheckResult GetArrayInd(ASStringNode* sn, UInt32& ind)
{
    const unsigned ssize = sn->Size;

    if (ssize > 0)
    {
        const char* sdata = sn->pData;
        char c = sdata[0];

        if (c == '0')
        {
            ind = 0;
            return ssize == 1;
        }

        if (static_cast<UByte>(c - '0') <= 9)
        {
            for (unsigned i = 1; i < ssize; ++i)
            {
                if (static_cast<UByte>(sdata[i] - '0') > 9)
                    return false;
            }

            char* end;
            Value::Number num = strtod(sdata, &end);

            if (num <= SF_MAX_UINT32)
            {
                ind = (UInt32)num;
                return true;
            }
        }
    }

    return false;
}

// ind receives the array index prop_name names (a string of digits or a number).
// @0x142507390
CheckResult GetArrayInd(const Multiname& prop_name, UInt32& ind)
{
    bool result = false;
    const Value& name = prop_name.Name;
    const Value::KindType kind = name.GetKind();

    if (kind == Value::kString)
        result = GetArrayInd(name.GetStringNode(), ind);
    else if (kind >= Value::kInt && kind <= Value::kNumber)
        result = name.Convert2UInt32(ind);

    return result;
}

// The source file name of the ABC file of the innermost call frame (self+0x78 frames, paged by 64 at self+0x90)
// into result.
// @0x1425083d0
void Sfr33CurrentFrameFileName(const UByte* self, ASString& result)
{
    const UPInt i = *reinterpret_cast<const UPInt*>(self + 0x78) - 1;
    const UByte* frame = (*reinterpret_cast<UByte* const* const*>(self + 0x90))[i >> 6] + (i & 0x3f) * 0xa8;
    const VMAbcFile* file = *reinterpret_cast<VMAbcFile* const*>(frame + 0x28);
    const String& src = file->GetAbcFile().Source;
    result.AssignNode(result.GetManager()->CreateStringNode(src.ToCStr(), src.GetSize()));
}

// HashSetBase::findIndex over an entry of 4 words: next, int key, value pair.
static SF_INLINE SPInt Sfr33EventChainFindIndex(const UPInt* table, const int& id)
{
    if (!table)
        return -1;
    const int hash = id;
    const UPInt mask = table[1];
    const UPInt home = SPInt(hash) & mask;
    SPInt index = static_cast<SPInt>(home);
    const UPInt* e = table + 2 + index * 4;
    if (e[0] == UPInt(-2) || (SPInt(*reinterpret_cast<const int*>(e + 1)) & mask) != home)
        return -1;
    for (;;)
    {
        const int key = *reinterpret_cast<const int*>(e + 1);
        if ((SPInt(key) & mask) == home && key == hash)
            return index;
        index = static_cast<SPInt>(e[0]);
        if (index == -1)
            return -1;
        e = table + 2 + index * 4;
    }
}

// EventChains::GetChain: the display objects listening for event id (NULL when none do); the chains hash
// (+0x00) maps an event id to an owned array.
// MS2-FUNCTIONAL 0x142507a70: the exe saves rbx and rdi in the home slots and keeps the key in rbx and the mask in
// r11; ours allocates a slot for rdi and swaps the two
// @0x142507a70
ArrayLH<WeakPtr<DisplayObject> >* Sfr33EventChainsGetChain(const UByte* self, int id)
{
    const UPInt* table = *reinterpret_cast<UPInt* const*>(self);
    const SPInt index = Sfr33EventChainFindIndex(table, id);
    const UPInt* pair = index >= 0 ? table + 3 + index * 4 : NULL;
    ArrayLH<WeakPtr<DisplayObject> >* const* value = pair ? reinterpret_cast<ArrayLH<WeakPtr<DisplayObject> >* const*>(pair + 1) : NULL;
    if (value)
        return *value;
    return NULL;
}

// EventChains::FindObjectIndexInChain: the index of obj in chain (-1 when it is not there).
// @0x142501dc0
UPInt EventChains::FindObjectIndexInChain(ChainType* chain, DisplayObject* obj)
{
    for (UPInt i = 0, n = chain->GetSize(); i < n; ++i)
        if ((*chain)[i] == obj)
            return i;
    return UPInt(-1);
}

// AbcMultinameHash<SPtr<Namespace>>::Get: the namespace interned for constant pool index ind (and next).
// @0x1425057f0
template SPtr<Instances::Namespace>* AbcMultinameHash<SPtr<Instances::Namespace> >::Get(UPInt ind, SInt32 next_ind);

// Hash<UPInt, UPInt>::Get of a bytewise-hashed 8-byte key: *pvalue (unless NULL) receives its value.
// @0x1425058c0
// noinline: CreateWeakProxy (0x1424f43c0) calls it for WProxyHash.Get.
__declspec(noinline) bool Sfr33WordHashGet(const HashLH<UPInt, UPInt>& h, const UPInt& key, UPInt* pvalue)
{
    return h.Get(key, pvalue);
}

// Drops the code of the last pushed value when it has no side effects (a push or local get), else emits a pop.
// @0x1424f9180
SF_NOINLINE void Tracer::PopPrevValue()
{
    const int op = NewOpcodePos.GetSize() ? static_cast<int>(WCode[NewOpcodePos[NewOpcodePos.GetSize() - 1]]) : 2;
    switch (op)
    {
    case 0x20: case 0x21: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x2a: case 0x2c: case 0x2d:
    case 0x2e: case 0x2f: case 0x31: case 0x60: case 0x62: case 0x64: case 0x65: case 0x67: case 0x6e: case 0xb5:
    case 0xd0: case 0xd1: case 0xd2: case 0xd3:
    {
        ArrayDH_POD<UPInt, StatMV_VM>& positions = NewOpcodePos;
        const UPInt pos = positions[positions.GetSize() - 1];
        reinterpret_cast<Scaleform::Sfr17WordArrayDH*>(&positions)->Resize(positions.GetSize() - 1);
        reinterpret_cast<Scaleform::Sfr17WordArray*>(&WCode)->Resize(pos);
        return;
    }
    default:
        PushNewOpCode(static_cast<Abc::Code::OpCode>(0x29));   // pop
    }
}

// Emits the push of the constant v (ind: its constant pool index; pop: drop the last pushed value first); false
// when v has no push opcode.
// @0x1424f9060
bool Tracer::PushConstValue(const Value& v, int ind, bool pop)
{
    int op;
    if (static_cast<UInt32>(static_cast<int>(v.GetKind()) - 8) <= 1)
    {
        const int arg = ind + 1;
        PushNewOpCode(static_cast<Abc::Code::OpCode>(0xb6), static_cast<UInt32>(arg));
        return true;
    }
    switch (static_cast<int>(v.GetKind()))
    {
    case 0:
        if (pop)
            PopPrevValue();
        op = 0x21;   // pushundefined
        break;
    case 1:
        if (pop)
            PopPrevValue();
        op = v.AsBool() ? 0x26 : 0x27;   // pushtrue / pushfalse
        break;
    case 4:
        if (!v.IsNaN())
            return false;
        if (pop)
            PopPrevValue();
        op = 0x28;   // pushnan
        break;
    case 12:
        return FUN_1424f86d0(this, v, pop);
    case 13:
        return FUN_1424f86d0(this, v, pop);
    default:
        return false;
    }
    PushNewOpCode(static_cast<Abc::Code::OpCode>(op));
    return true;
}

// The value (+0x10 of its entry) the word key maps to in the identity-hashed map at self (NULL when none).
// HashSetBase::findIndex over an entry of 4 words: next, key, value pair.
static SF_INLINE SPInt Sfr33IdWordFindIndex(const UPInt* table, const UPInt& key)
{
    if (!table)
        return -1;
    const UPInt hash = key;
    const UPInt home = hash & table[1];
    SPInt index = static_cast<SPInt>(home);
    const UPInt* e = table + 2 + index * 4;
    if (e[0] == UPInt(-2) || (e[1] & table[1]) != home)
        return -1;
    for (;;)
    {
        const UPInt v = e[1];
        if ((table[1] & v) == home && v == hash)
            return index;
        index = static_cast<SPInt>(e[0]);
        if (index == -1)
            return -1;
        e = table + 2 + index * 4;
    }
}

// @0x1425059f0
void* Sfr33IdWordHashGet(const UByte* self, const UPInt& key)
{
    const UPInt* table = *reinterpret_cast<UPInt* const*>(self);
    const SPInt index = Sfr33IdWordFindIndex(table, key);
    const UPInt* pair = index >= 0 ? table + 3 + index * 4 : NULL;
    return pair ? const_cast<UPInt*>(pair + 1) : NULL;
}

// GASRefCountBase::CreateWeakProxy: the object's weak proxy, made on first use (registered with the collector, the
// object flagged as weakly referenced); returned with a new reference.
// A free function taking the object, then the (uninitialized) Ptr<WeakProxy> slot it fills.
// @0x1424f43c0
WeakProxy** Sfr33CreateWeakProxy(const GASRefCountBase* obj, WeakProxy** out)
{
    GASRefCountBase::Collector* gc = obj->GetCollector();
    WeakProxy* proxy = NULL;
    if (!Sfr33WordHashGet(reinterpret_cast<const HashLH<UPInt, UPInt>&>(gc->WProxyHash),
                          reinterpret_cast<UPInt>(obj), reinterpret_cast<UPInt*>(&proxy)))
    {
        proxy = SF_HEAP_AUTO_NEW(obj) WeakProxy(obj);
        if (!proxy)
        {
            *out = NULL;
            return out;
        }
        // RefCount (+0x10) is protected: set Flag_HasWeakRef through the raw word
        *reinterpret_cast<UInt32*>(reinterpret_cast<UByte*>(const_cast<GASRefCountBase*>(obj)) + 0x10) |= GASRefCountBase::Flag_HasWeakRef;
        gc->WProxyHash.Add(static_cast<const GASRefCountBase*>(obj), proxy);
    }
    proxy->AddRef();
    *out = proxy;
    return out;
}

// SlotInfo::GetDataType: the class traits of the slot's declared type (si+0x18 the ABC file, +0x20 its type
// multiname), resolved and kept (+0x10) on first use; a slot without an ABC type takes those of its bind type.
// @0x1425085b0
ClassTraits::Traits* Sfr33SlotDataType(const SlotInfo* psi, VM* pvm)
{
    UByte* si = reinterpret_cast<UByte*>(const_cast<SlotInfo*>(psi));
    const UByte* vm = reinterpret_cast<const UByte*>(pvm);
    SPtr<ClassTraits::Traits>& type = *reinterpret_cast<SPtr<ClassTraits::Traits>*>(si + 0x10);
    if (!type)
    {
        VMAbcFile* file = *reinterpret_cast<VMAbcFile**>(si + 0x18);
        const UByte* amn = *reinterpret_cast<const UByte* const*>(si + 0x20);
        if (file && amn)
        {
            const int kind = *amn & 0xf;
            if ((kind & ~6) == 0 && kind != 2)
            {
                const Abc::Multiname& tn =
                    FUN_14250f8a0(amn, *reinterpret_cast<const void* const*>(reinterpret_cast<UByte*>(file) + 0x28));
                Multiname mn(*file, tn);
                type = static_cast<ClassTraits::Traits*>(
                    FUN_142524f60(pvm, *reinterpret_cast<VMAbcFile**>(si + 0x18), &tn));
            }
            else
                type = *reinterpret_cast<ClassTraits::Traits* const*>(vm + 0x208);
        }
        else
        {
            switch ((*reinterpret_cast<const int*>(si) << 0x16) >> 0x1b)
            {
            case 0: case 1: case 2: type = *reinterpret_cast<ClassTraits::Traits* const*>(vm + 0x1f0); break;
            case 3: case 4: type = *reinterpret_cast<ClassTraits::Traits* const*>(vm + 0x1f8); break;
            case 5: type = *reinterpret_cast<ClassTraits::Traits* const*>(vm + 0x210); break;
            case 6: type = *reinterpret_cast<ClassTraits::Traits* const*>(vm + 0x220); break;
            case 7: type = *reinterpret_cast<ClassTraits::Traits* const*>(vm + 0x228); break;
            case 8: type = *reinterpret_cast<ClassTraits::Traits* const*>(vm + 0x218); break;
            case 9: case 10: type = *reinterpret_cast<ClassTraits::Traits* const*>(vm + 0x230); break;
            case 11: case 12: case 13: case 14: type = *reinterpret_cast<ClassTraits::Traits* const*>(vm + 0x208); break;
            default: break;
            }
        }
    }
    return type;
}

// SlotInfo::GetDataTypeName: the name of the slot's declared type: that of the resolved class traits, else the
// ABC type multiname's name (Object's name for a runtime one), else the name of the bind type's class.
// A member (this in rcx, the result slot in rdx), as the exe's callers pass it.
// @0x142508720
ASString SlotInfo::GetDataTypeName(VM& vm) const
{
    ASString result = vm.GetStringManager().CreateEmptyString();
    if (CTraits.GetPtr() == NULL)
    {
        VMAbcFile* const file = File.GetPtr();
        if (file != NULL && TI != NULL)
        {
            const UByte* amn = reinterpret_cast<const UByte*>(TI);
            const int kind = *amn & 0xf;
            if (kind == 0 || kind == 6 || kind == 4)
            {
                const UByte* mn = reinterpret_cast<const UByte*>(&FUN_14250f8a0(
                    amn, *reinterpret_cast<const void* const*>(reinterpret_cast<const UByte*>(file) + 0x28)));
                // out of line here (0x1423f1a30), where the exe keeps it apart from the inlined tail assignment
                (result.*static_cast<void (ASString::*)(const ASString&)>(&ASString::operator=))(
                    file->GetInternedString(*reinterpret_cast<const int*>(mn + 8)));
            }
            else
                result = vm.GetClassTraitsFunction().GetName();
        }
        else
        {
            const ClassTraits::Traits* tr = NULL;
            const BindingType bt = (BindingType)BindType;
            switch (bt)
            {
            case BT_Unknown:
            case BT_ValueArray:
            case BT_Value:
                // through the GASRefCountBase instance's out-of-line operator= (0x142528c50), as the exe calls it
                reinterpret_cast<SPtr<GASRefCountBase>&>(const_cast<SPtr<const ClassTraits::Traits>&>(CTraits)) =
                    (GASRefCountBase*)&vm.GetClassTraitsClassClass();
                break;
            case BT_ObjectAS:
            case BT_ObjectCpp:
                tr = &vm.GetClassTraitsObject();
                break;
            case BT_Boolean:
                tr = (const ClassTraits::Traits*)&vm.GetClassTraitsBoolean();
                break;
            case BT_Int:
                tr = (const ClassTraits::Traits*)&vm.GetClassTraitsSInt();
                break;
            case BT_UInt:
                tr = (const ClassTraits::Traits*)&vm.GetClassTraitsUInt();
                break;
            case BT_Number:
                tr = (const ClassTraits::Traits*)&vm.GetClassTraitsNumber();
                break;
            case BT_String:
            case static_cast<BindingType>(10):
                tr = (const ClassTraits::Traits*)&vm.GetClassTraitsString();
                break;
            case BT_Code:
            case BT_Get:
            case BT_Set:
            case BT_GetSet:
                tr = (const ClassTraits::Traits*)&vm.GetClassTraitsFunction();
                break;
            }
            result = tr->GetName();
        }
    }
    else
        result = CTraits->GetName();
    return result;
}

// VMAbcFile::GetDetailValue: the constant (an optional parameter's or slot's default) a value detail names;
// index 0 (or an unknown kind) is undefined. Kinds: 1 Utf8, 3 Int, 4 UInt, 5/8/0x16..0x1a namespaces,
// 6 Double, 10 False, 11 True, 12 Null.
// @0x142509240
Value VMAbcFile::GetDetailValue(const Abc::ValueDetail& d)
{
    const SInt32 ind = d.ValueIndex;
    if (ind > 0)
    {
        switch (static_cast<int>(d.Kind))
        {
        case 3:
            return Value(GetAbcFile().Const_Pool.ConstInt[ind]);
        case 4:
            return Value(GetAbcFile().Const_Pool.ConstUInt[ind]);
        case 6:
            return Value(GetAbcFile().Const_Pool.GetDouble(ind));
        case 1:
        {
            const StringDataPtr str = GetAbcFile().Const_Pool.GetString(static_cast<UInt32>(ind));
            return Value(GetVM().GetStringManager().CreateString(str.ToCStr(), str.GetSize()), Value::InlineStr);
        }
        case 11:
            return Value(true);
        case 10:
            return Value(false);
        case 12:
            return Value::GetNull();
        case 0:
            return Value::GetUndefined();
        case 8: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a: case 5:
            return Value(&GetInternedNamespace(d.ValueIndex));
        }
    }
    return Value::GetUndefined();
}

}}}

// Value::operator=(const ASString&), out of line in the exe (defined in sfr_as3_19).
Scaleform::GFx::AS3::Value& FUN_1424e0d40(Scaleform::GFx::AS3::Value& v, const Scaleform::GFx::ASString& str);

namespace Scaleform { namespace GFx { namespace AS3 {
// Multiname::PostProcessName(false) (0x14251cef0, sfr_as3_18), as the exe inlines it into DeleteMember.
static __forceinline void Sfr17PostProcessName(Multiname& mn)
{
    if (!mn.Name.IsString())
        return;
    ASString n = mn.Name.AsString();
    if (n.GetSize() == 0)
        return;
    if (n[0] == '*')
        FUN_1424e0d40(mn.Name, ASString(n.GetManager()->GetEmptyStringNode()));
    else if (n[0] == '@')
    {
        mn.Kind = static_cast<Abc::MultinameKind>(mn.Kind | 8);
        if (n.GetSize() == 2 && n[1] == '*')
            FUN_1424e0d40(mn.Name, ASString(n.GetManager()->GetEmptyStringNode()));
        else
            FUN_1424e0d40(mn.Name, ASString(n.SubstringNode(1, n.GetSize())));
    }
}

// Multiname(Namespace&, const Value&) (0x1424d8a90, sfr_as3_15) with SetRTNameUnsafe and PostProcessName, as the
// exe inlines them into DeleteMember (the same body as sfr_as3_19's copy).
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
    Name.AssignUnsafe(name);
    Sfr17PostProcessName(*this);
}
}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx {
// AS3ValueObjectInterface::DeleteMember: deletes the public property name (a leading '@' names an attribute) of
// the object pdata; true when it was deleted. this+8 is the movie whose +0x18 is the MovieRoot (pAVM +0x48,
// string manager +0x348).
// MS2-FUNCTIONAL 0x1424f4780: raw self/MovieRoot offsets; regalloc (the exe holds the temp Value flags in r14 and merges the two string AddRefs)
// @0x1424f4780
bool AS3ValueObjectInterface::DeleteMember(void* pdata, const char* name, bool isdobj)
{
    SF_UNUSED(isdobj);
    void* self = this;
    AS3::Object* obj = static_cast<AS3::Object*>(pdata);
    const UByte* root = *reinterpret_cast<UByte* const*>(*reinterpret_cast<UByte* const*>(static_cast<UByte*>(self) + 8) + 0x18);
    AS3::VM& vm = **reinterpret_cast<AS3::VM* const*>(root + 0x48);
    const AS3::Multiname mn(vm.GetPublicNamespace(),
                            AS3::Value(ASString((*reinterpret_cast<ASStringManager* const*>(root + 0x348))->CreateStringNode(name)), AS3::Value::InlineStr),
                            AS3::Multiname::InlineCtorTag());
    return obj->DeleteProperty(mn);
}
}} // namespace Scaleform::GFx

namespace Scaleform { namespace GFx { namespace AS3 {

namespace InstanceTraits { class Activation { public: Activation(VMAbcFile& file, VM& vm, const Abc::MethodBodyInfo& mbi, const ASString& name); }; }
// VMAbcFile::ActivationTraitsCacheTable (+0x90); its add (0x1424d4430) is instantiated in sfr_as3_15.
typedef HashLH<const Abc::MethodBodyInfo*, SPtr<InstanceTraits::Traits>, FixedSizeHash<const Abc::MethodBodyInfo*>,
               StatMV_VM_VMAbcFile_Mem> Sfr33ActivationTraitsCache;

// VMAbcFile::GetActivationInstanceTraits: the activation traits of method body mbi, made on first use and cached by
// body (+0x90); a body without traits shares the VM's (+0x288).
// @0x142506f00
InstanceTraits::Traits* Sfr33GetActivationInstanceTraits(VMAbcFile& file, const Abc::MethodBodyInfo* mbi, void* p)
{
    VM& vm = file.GetVM();
    if (mbi->obj_traits.GetSize() != 0)
    {
        Sfr33ActivationTraitsCache& cache = *reinterpret_cast<Sfr33ActivationTraitsCache*>(reinterpret_cast<UByte*>(&file) + 0x90);
        SPtr<InstanceTraits::Traits>* ptr = cache.Get(&*mbi);
        if (ptr == NULL)
        {
            void* mem = vm.GetMemoryHeap()->Alloc(0xd0);
            InstanceTraits::Traits* tr = mem ? reinterpret_cast<InstanceTraits::Traits*>(::new (mem) InstanceTraits::Activation(file, vm, *mbi, *reinterpret_cast<const ASString*>(p))) : NULL;
            cache.Add(&*mbi, Pickable<InstanceTraits::Traits>(tr));
            return tr;
        }
        return *ptr;
    }
    return *reinterpret_cast<InstanceTraits::Traits* const*>(reinterpret_cast<const UByte*>(&vm) + 0x288);
}

// ShapeObject::GetDrawingContext (virtual, +0xc8): created on first use with the mask lifted while its tree node
// goes last in the container.
// @0x1425099a0
DrawingContext* ShapeObject::GetDrawingContext()
{
    if (!pDrawing)
    {
        Ptr<DisplayObject> mask = GetMask();
        if (mask)
            SetMask(NULL);
        pDrawing = *DisplayObject::GetMovieImpl()->CreateDrawingContext();
        Render::TreeContainer* node = ConvertToTreeContainer();
        node->Remove(0, 1);
        DrawingContext* dc = pDrawing;
        const UPInt n = node->GetSize();
        node->Insert(n, dc->GetTreeNode());
        if (mask)
            SetMask(mask);
    }
    return pDrawing;
}
//
//
//
//
//
//
}}}

namespace Scaleform { namespace GFx { namespace AS3 {

// Throws a TypeError and returns false when v, about to be used as an object, is null or undefined.
// MS2-FUNCTIONAL 0x1424ef210: value pointer kept in r8 (exe copies it to r9) and the kind test in eax (exe r8d)
// @0x1424ef210
bool Sfr33IsObjectElseThrow(VM& vm, const Value& v)
{
    if (!v.IsNullOrUndefined())
        return true;
    const VM::ErrorID id = v.IsNull() ? VM::eConvertNullToObjectError : VM::eConvertUndefinedToObjectError;
    Sfr33ThrowTypeError(vm, VM::Error(id, vm));
    return false;
}

// A callback holding a function value (+0x10) and an optional object (+0x30); virtual slot 4 cancels it.
struct Sfr33FileCallback
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void Cancel();

    UPInt   Unk08;      // +0x08
    Value   Function;   // +0x10
    Object* pObject;    // +0x30
};

// The ABC file field +0x188 of the file defining traits tr (false when tr has no file).
static SF_INLINE bool Sfr33TraitsFromFile(const Traits& tr, const void* key)
{
    const VMAbcFile* file = tr.GetFilePtr();
    return file && *reinterpret_cast<const void* const*>(reinterpret_cast<const UByte*>(&file->GetAbcFile()) + 0x188) == key;
}
}}}


namespace Scaleform { namespace GFx { namespace AS3 {

// Cancels cb when its function (unless null) or its object comes from the ABC file whose +0x188 is key.
// @0x1424efc30
bool IntervalTimer::ClearFor(MovieImpl* proot, MovieDefImpl* pdefImpl)
{
    Sfr33FileCallback* cb = reinterpret_cast<Sfr33FileCallback*>(this);
    const UByte* owner = reinterpret_cast<const UByte*>(proot);
    const void* key = pdefImpl;
    const Value& f = cb->Function;
    if (!f.IsNull())
    {
        if (Sfr33TraitsFromFile(
                (**reinterpret_cast<VM* const*>(*reinterpret_cast<const UByte* const*>(owner + 0x18) + 0x48)).GetValueTraits(f),
                key))
        {
            cb->Cancel();
            return true;
        }
    }
    if (cb->pObject && Sfr33TraitsFromFile(cb->pObject->GetTraits(), key))
    {
        cb->Cancel();
        return true;
    }
    return false;
}

// The VM operand stack (VM +0x48) as CallFrame sees it.
struct Sfr33OpStack
{
    UInt16              ReservedNum;    // +0x00
    Value*              pCurrent;       // +0x08
    Value*              pStack;         // +0x10
    ValueStack::Page*   pCurrentPage;   // +0x18
};

// @0x1424efcd0
void CallFrame::ClearOpStack()
{
    Value* const pos = PrevInitialStackPos;
    Sfr33OpStack& st = *reinterpret_cast<Sfr33OpStack*>(reinterpret_cast<UByte*>(&GetVM()) + 0x48);
    while (st.pCurrent > pos && st.pCurrent >= st.pCurrentPage->Values)
    {
        Value& v = *st.pCurrent;
        if (v.IsRefCounted())
        {
            if (v.IsWeakRef())
            {
                // Value::ReleaseWeakRef, inlined
                v.Bonus.pWeakProxy->Release();
                v.Flags &= ~(Value::kindMask | Value::weakRefMask);
                v.Bonus.pWeakProxy = NULL;
                v.value.VS._1.VObj = NULL;
                v.value.VS._2.VObj = NULL;
            }
            else
                v.ReleaseInternal();
        }
        --st.pCurrent;
    }
}

// True when the AS3 object of the display object comes from the ABC file whose +0x188 is key.
// @0x1424f74f0
bool Sfr33AS3ObjFromFile(AvmDisplayObj* self, const void* key)
{
    Object* obj = reinterpret_cast<Object*>(self->GetAS3Obj());
    return obj && Sfr33TraitsFromFile(obj->GetTraits(), key);
}

// Runs one queued call frame and pops its return value into result (nothing on an exception).
// @0x1424fa510
void Sfr33ExecuteAndPop(VM& vm, Value& result)
{
    if (vm.IsException())
        return;
    vm.ExecuteCode(1);
    if (vm.IsException())
        return;
    result.Pick(*reinterpret_cast<ValueStack*>(reinterpret_cast<UByte*>(&vm) + 0x48));
}

// Moves result onto the operand stack (result is left undefined).
static void Sfr33PushResult(VM& vm, Value& result)
{
    Sfr33OpStack& st = *reinterpret_cast<Sfr33OpStack*>(reinterpret_cast<UByte*>(&vm) + 0x48);
    ++st.pCurrent;
    ::new (static_cast<void*>(st.pCurrent)) Value(result, PickValue);
}

// VM::ThrowErrorInternal on an Error temporary, as the exe's inlined throws have it (the ctor's result passed on).
static __forceinline void Sfr17ThrowError(VM& vm, const VM::Error& e, const ClassInfo& ci)
{
    FUN_14252ecb0(&vm, &e, &ci);
}

// Room for the Value a closure's this is made in, constructed and destroyed by hand so both closure cases share
// one call and one release.
union Sfr17ValueSlot
{
    Value V;
    Sfr17ValueSlot() {}
    ~Sfr17ValueSlot() {}
};

// The argument count check of VM::ExecuteThunkUnsafe: an ArgumentError (#1063) when argc is outside the thunk's range.
static __forceinline bool Sfr17ThunkArgsOk(VM& vm, const ThunkInfo& thunk, unsigned argc)
{
    const unsigned maxArgs = thunk.GetMaxArgNum();
    if (maxArgs != 0x3ff && (argc > maxArgs || argc < thunk.GetMinArgNum()))
    {
        Sfr17ThrowError(vm, VM::Error(VM::eWrongArgumentCountError, vm, thunk.Name, thunk.GetMinArgNum(), maxArgs, argc),
                        fl::ArgumentErrorCI);
        return false;
    }
    return true;
}

// VM::ExecuteThunkUnsafe as the exe inlines it: the check, then the call, its result moved onto the operand stack
// with result_on_stack.
static __forceinline void Sfr17ExecuteThunk(VM& vm, const ThunkInfo& thunk, const Value& _this, Value& result,
                                            unsigned argc, const Value* argv, bool result_on_stack)
{
    if (!Sfr17ThunkArgsOk(vm, thunk, argc))
        return;
    thunk.Method(thunk, vm, _this, result, argc, argv);
    if (result_on_stack && !vm.IsException())
        Sfr33PushResult(vm, result);
}

// The method half of VM::ExecuteVTableIndUnsafe as the exe inlines it, for the slot m (index ind) of a VTable: a
// call frame invoked by func, run here unless result_on_stack.
static __forceinline void Sfr17AddSlotFrame(VM& vm, const Value& func, const Value& m, UPInt ind, const Value& _this,
                                             Value& result, unsigned argc, const Value* argv, bool result_on_stack)
{
    const Traits& ot = m.GetTraits();
    VMAbcFile& file = *ot.GetFilePtr();
    const SInt32 mbi_ind = file.GetAbcFile().Methods.Info[m.GetMethodInd()]->MethodBodyInfoInd;
    vm.AddFrame(func, file, mbi_ind, _this, argc, argv, false, ot.InitScope, ot, ot.GetVT().Names[ind]);
    if (!result_on_stack)
        Sfr33ExecuteAndPop(vm, result);
}

// VM::ExecuteInternalUnsafe: calls func on _this. A method slot of a traits' VTable pushes a call frame (run here
// unless result_on_stack, when the interpreter picks it up); thunks, objects and functions are called directly. With
// result_on_stack the result goes onto the operand stack. Anything else is a TypeError (#1006).
// MS2-FUNCTIONAL 0x1424fef00: 32 bytes long; the exe shares the kThunk call with the VTableInd thunk, ours does not
// @0x1424fef00
void VM::ExecuteInternalUnsafe(const Value& func, const Value& _this, Value& result, unsigned argc, const Value* argv,
                               bool result_on_stack)
{
    Scaleform::SIMD::PrefetchObj(&func);
    Scaleform::SIMD::PrefetchObj(&_this);
    const ThunkInfo* thunk;
    Sfr17ValueSlot closureThis;
    switch (func.GetKind())
    {
    case Value::kFunction:
        if (result_on_stack)
            const_cast<Instances::Function&>(func.AsFunction()).Execute(_this, argc, argv, false);
        else
            const_cast<Instances::Function&>(func.AsFunction()).ExecuteUnsafe(_this, result, argc, argv);
        break;
    case Value::kObject:
    case Value::kClass:
        if (Object* obj = func.GetObject())
        {
            obj->Call(_this, result, argc, argv);
            if (!IsException() && result_on_stack)
                Sfr33PushResult(*this, result);
            break;
        }
        goto non_function;
    case Value::kThunk:
        thunk = &func.AsThunk();
        Scaleform::SIMD::PrefetchObj(thunk);
        Sfr17ExecuteThunk(*this, *thunk, _this, result, argc, argv, result_on_stack);
        break;
    case Value::kThunkFunction:
        const_cast<Instances::ThunkFunction&>(func.AsThunkFunction()).ExecuteUnsafe(_this, result, argc, argv);
        if (!IsException() && result_on_stack)
            Sfr33PushResult(*this, result);
        break;
    case Value::kThunkClosure:
        thunk = &func.AsThunk();
        Scaleform::SIMD::PrefetchObj(thunk);
        ::new (static_cast<void*>(&closureThis.V)) Value(func.GetClosure(), Value::InlineObj);
        if (!Sfr17ThunkArgsOk(*this, *thunk, argc))
            goto closure_done;
    call_closure_thunk:
        thunk->Method(*thunk, *this, closureThis.V, result, argc, argv);
        if (result_on_stack && !IsException())
            Sfr33PushResult(*this, result);
    closure_done:
        closureThis.V.~Value();
        break;
    case Value::kVTableInd:
    {
        const UPInt ind = static_cast<UInt32>(func.GetVTableInd());
        const Value& m = func.GetTraits().GetVT().VTMethods[ind];
        Scaleform::SIMD::PrefetchObj(&m);
        if (m.GetKind() == Value::kMethodInd)
        {
            Sfr17AddSlotFrame(*this, func, m, ind, _this, result, argc, argv, result_on_stack);
            break;
        }
        thunk = &m.AsThunk();
        Scaleform::SIMD::PrefetchObj(thunk);
        Sfr17ExecuteThunk(*this, *thunk, _this, result, argc, argv, result_on_stack);
        break;
    }
    case Value::kVTableIndClosure:
    {
        const UPInt ind = static_cast<UInt32>(func.GetVTableInd());
        const Value& m = func.GetClosure()->GetTraits().GetVT().VTMethods[ind];
        Scaleform::SIMD::PrefetchObj(&m);
        ::new (static_cast<void*>(&closureThis.V)) Value(func.GetClosure(), Value::InlineObj);
        if (m.GetKind() == Value::kMethodInd)
        {
            Sfr17AddSlotFrame(*this, func, m, ind, closureThis.V, result, argc, argv, result_on_stack);
            goto closure_done;
        }
        thunk = &m.AsThunk();
        Scaleform::SIMD::PrefetchObj(thunk);
        if (!Sfr17ThunkArgsOk(*this, *thunk, argc))
            goto closure_done;
        goto call_closure_thunk;
    }
    default:
    non_function:
        Sfr17ThrowError(*this, VM::Error(VM::eCallOfNonFunctionError, *this, func), fl::TypeErrorCI);
        break;
    }
}

// Value(Object*) as the exe inlines it on a non-null object (no null test); released by ~Value.
struct Sfr17ObjValue
{
    UInt32 Flags;
    void* pWeakProxy;
    Object* pObj;
    void* pRest;
    __forceinline explicit Sfr17ObjValue(Object* p) : Flags(Value::kObject), pWeakProxy(NULL), pObj(p) { p->AddRef(); }
    __forceinline ~Sfr17ObjValue() { reinterpret_cast<Value*>(this)->~Value(); }
    operator const Value&() const { return *reinterpret_cast<const Value*>(this); }
};

// Multiname(Namespace&, const Value&) (0x1424d8a90, sfr_as3_15) with PostProcessName(false) (0x14251cef0), both
// of which the exe inlines here. Same layout as Multiname; its implicit dtor is expanded in place.
struct Sfr17InlineMultiname
{
    Abc::MultinameKind      Kind;
    SPtr<GASRefCountBase>   Obj;
    Value                   Name;
    __forceinline Sfr17InlineMultiname(Instances::Namespace& ns, const Value& name)
        : Kind(static_cast<Abc::MultinameKind>(0))
        , Obj(&ns)
    {
        if (Value::IsObject(name.GetKind()))
        {
            Object* obj = name.GetObject();
            if (obj && obj->GetTraits().GetTraitsType() == Traits_QName && obj->GetTraits().IsInstanceTraits())
            {
                Sfr27MultinameFromQName(&Get(), &name);
                return;
            }
        }
        Name.AssignUnsafe(name);
        if (!Name.IsString())
            return;
        ASString n = Name.AsString();
        if (n.GetSize() == 0)
            return;
        if (n[0] == '*')
            Name = ASString(n.GetManager()->GetEmptyStringNode());
        else if (n[0] == '@')
        {
            Kind = static_cast<Abc::MultinameKind>(Kind | 8);
            if (n.GetSize() == 2 && n[1] == '*')
                Name = ASString(n.GetManager()->GetEmptyStringNode());
            else
                Name = ASString(n.SubstringNode(1, n.GetSize()));
        }
    }
    Multiname& Get() { return *reinterpret_cast<Multiname*>(this); }
};

}}}

// Calls the property name (public namespace; "@" marks an attribute) of self with argc arguments: a missing property
// is a ReferenceError, an undefined/null one a TypeError.
// MS2-FUNCTIONAL 0x1424ffc10: GetSlotValueUnsafe, the Multiname ctor and Value(obj) are inlined as in the exe;
// the frame is 0x30 larger and the name Value / PropRef sit in other slots and registers
// @0x1424ffc10
void FUN_1424ffc10(Scaleform::UPInt self, Scaleform::UPInt name, Scaleform::UPInt result, int argc,
                   const Scaleform::GFx::AS3::Value* argv)
{
    using namespace Scaleform::GFx::AS3;
    Object* obj = reinterpret_cast<Object*>(self);
    const Scaleform::GFx::ASString& nameStr = *reinterpret_cast<const Scaleform::GFx::ASString*>(name);
    Sfr17InlineMultiname m(obj->GetVM().GetPublicNamespace(), Value(nameStr, Value::InlineStr));
    const Multiname& mn = m.Get();
    Sfr17EmptyPropRef t;
    PropRef& prop = t.Get();
    Sfr33FindObjProperty(prop, obj->GetVM(), Sfr17ObjValue(obj), mn, 0);
    VM& vm = obj->GetVM();
    if (!Sfr33PropFound(prop))
    {
        // eReadSealedError (1069): "Property %s not found on %s and there is no default value."
        const VM::Error e(static_cast<VM::ErrorID>(1069), vm, m.Name, Sfr17ObjValue(obj));
        FUN_14252ecb0(&vm, &e, &fl::ReferenceErrorCI);
        return;
    }
    Value func;
    if (!Sfr17GetSlotValueUnsafe(prop, vm, func))
        return;
    if (func.IsNullOrUndefined())
    {
        const VM::Error e(VM::eConvertUndefinedToObjectError, vm);
        FUN_14252ecb0(&vm, &e, &fl::TypeErrorCI);
        return;
    }
    vm.ExecuteInternalUnsafe(func, Sfr17ObjValue(obj), *reinterpret_cast<Value*>(result), static_cast<unsigned>(argc), argv, false);
}

// Calls the method in slot ind of tr's VTable on _this with the result on the operand stack: a method body gets a
// call frame for the interpreter, a thunk is called at once (its result pushed).
// VM::ExecuteVTableIndUnsafe: the VTable-index case of ExecuteInternalUnsafe with the result left on the stack.
// MS2-FUNCTIONAL 0x142500260: AddFrame and the thunk call inlined as the exe does (946 vs 950 bytes); register
// allocation differs, and AddFrame's stack-overflow throw goes through ThrowError rather than FUN_14252ecb0
// @0x142500260
void FUN_142500260(Scaleform::UPInt vmp, unsigned int ind, Scaleform::UPInt traits, void* value, unsigned int argc, void* args)
{
    using namespace Scaleform::GFx::AS3;
    VM& vm = *reinterpret_cast<VM*>(vmp);
    const Traits& tr = *reinterpret_cast<const Traits*>(traits);
    const Value& _this = *static_cast<const Value*>(value);
    const Value* argv = static_cast<const Value*>(args);
    const Value& m = tr.GetVT().VTMethods[ind];
    Scaleform::SIMD::PrefetchObj(&m);
    if (m.GetKind() == Value::kMethodInd)
    {
        const Traits& ot = m.GetTraits();
        VMAbcFile& file = *ot.GetFilePtr();
        const Scaleform::SInt32 mbi_ind = file.GetAbcFile().Methods.Info[m.GetMethodInd()]->MethodBodyInfoInd;
        vm.AddFrame(Value(static_cast<Scaleform::SInt32>(ind), tr, Value::kVTableInd), file, mbi_ind, _this, argc,
                    argv, false, ot.InitScope, ot, ot.GetVT().Names[ind]);
        return;
    }
    const ThunkInfo& thunk = m.AsThunk();
    Scaleform::SIMD::PrefetchObj(&thunk);
    Value result;
    const unsigned maxArgs = thunk.GetMaxArgNum();
    if (maxArgs != 0x3ff && (argc > maxArgs || argc < thunk.GetMinArgNum()))
    {
        const VM::Error e(VM::eWrongArgumentCountError, vm, thunk.Name, thunk.GetMinArgNum(), maxArgs, argc);
        FUN_14252ecb0(&vm, &e, &fl::ArgumentErrorCI);
    }
    else
    {
        thunk.Method(thunk, vm, _this, result, argc, argv);
        if (!vm.IsException())
            Sfr33PushResult(vm, result);
    }
}

// VM::VMAbcFilesWeak.Clear()
template void Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::VMAbcFile*, Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::VMAbcFile*, Scaleform::GFx::AS3::StatMV_VM_VM_Mem>, Scaleform::ArrayDefaultPolicy> >::Clear();
// sfr_as3_19 calls this instance by its exe name (an opaque extern keeps Sfr31ShutdownRegistered's r14 save,
// 0x142530d50); the name binds to this body here. The hook DLL binds the FUN_ name by its symbols row.
#ifndef MS2_HOOK_DLL
#pragma comment(linker, "/alternatename:?FUN_1424ef2a0@@YAX_K@Z=?Clear@?$ArrayBase@U?$ArrayData@PEAVVMAbcFile@AS3@GFx@Scaleform@@U?$AllocatorLH_POD@PEAVVMAbcFile@AS3@GFx@Scaleform@@$0BEJ@@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAXXZ")
#endif

// INST-CheckExp-BEGIN
template void Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::CheckExpand(void*);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >,Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >::NodeHashF,Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::UInt32,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >,Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >::NodeHashF> >::CheckExpand(void*);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode*,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF> >::CheckExpand(void*);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase*,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >::NodeHashF> >::CheckExpand(void*);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode*,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode*,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode*,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode*,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode*,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::CheckExpand(void*);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::CheckExpand(void*);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class*,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class*,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class*,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,329>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class*,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class*,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF> >::CheckExpand(void*);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::CheckExpand(void*);
template void Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > >::CheckExpand(void*);
// INST-CheckExp-END

namespace Scaleform { namespace Render {
class LinearHeap
{
public:
    void* Alloc(UPInt size);   // 0x1424eb4d0
};
namespace ContextImpl {
// The snapshot statistics (Render_Context data).
extern unsigned ConstructCopyCalls, CopyCalls;
} // namespace ContextImpl

// ContextData_ImplMixin<TreeShape::NodeData, TreeNode::NodeData>::ConstructCopy: a copy of the shape node data
// made on the snapshot heap (the provider gets a reference).
// @0x1424f0990
ContextImpl::EntryData* Sfr33ShapeDataConstructCopy(const TreeShape::NodeData* self, LinearHeap& heap)
{
    ContextImpl::ConstructCopyCalls++;
    TreeShape::NodeData* p = static_cast<TreeShape::NodeData*>(heap.Alloc(sizeof(TreeShape::NodeData)));
    new (p) TreeNode::NodeData(*self);
    p->pVTable = TreeShapeNodeDataVTable;
    if (self->pMeshProvider)
        self->pMeshProvider->AddRef();
    p->pMeshProvider = self->pMeshProvider;
    p->MorphRatio    = self->MorphRatio;
    return p;
}

// ContextData_ImplMixin<TreeShape::NodeData, TreeNode::NodeData>::CopyTo: assigns the shape node data to dest.
// @0x1424f1f90
void Sfr33ShapeDataCopyTo(const TreeShape::NodeData* self, void* dest)
{
    TreeShape::NodeData* d = static_cast<TreeShape::NodeData*>(dest);
    static_cast<TreeNode::NodeData&>(*d) = *self;
    if (self->pMeshProvider)
        self->pMeshProvider->AddRef();
    if (d->pMeshProvider)
        d->pMeshProvider->Release();
    d->pMeshProvider = self->pMeshProvider;
    d->MorphRatio    = self->MorphRatio;
    ContextImpl::CopyCalls++;
}
}} // namespace Scaleform::Render

namespace Scaleform { namespace GFx { namespace AS3 {
// GFx::Value as laid out in the exe (its members are not reachable from here).
struct Sfr33GFxValueRaw
{
    GFx::Value::ObjectInterface* pObjectInterface;   // +0x00
    UInt32                       Type;               // +0x08
    void*                        pData;              // +0x10
    UPInt                        DataAux;            // +0x18 closures: the thunk or the vtable index
};

// The GFx value type of an AS3 object: a display object, an array or a plain object.
static SF_INLINE UInt32 Sfr33GFxObjectType(const Object* obj)
{
    const Traits& tr = obj->GetTraits();
    const BuiltinTraitsType tt = tr.GetTraitsType();
    UInt32 type = GFx::Value::VT_Object;
    if (UInt32(tt - Traits_DisplayObject_Begin) < UInt32(Traits_DisplayObject_End - Traits_DisplayObject_Begin) &&
        tr.IsInstanceTraits())
        type = GFx::Value::VT_DisplayObject;
    else if (tt == Traits_Array)
        type = GFx::Value::VT_Array;
    return type;
}

// GFx::Value::IsManagedValue: the VTC_ManagedBit of the type.
static SF_FORCEINLINE bool Sfr33IsManagedValue(const Sfr33GFxValueRaw* v)
{
    return (v->Type >> 6) & 1;
}

// pval becomes a managed reference to obj kept through iface (the old managed value is released first).
static SF_INLINE bool Sfr33SetObjectValue(GFx::Value::ObjectInterface* iface, GFx::Value* pval, Object* obj)
{
    const UInt32 type = Sfr33GFxObjectType(obj);
    Sfr33GFxValueRaw* v = reinterpret_cast<Sfr33GFxValueRaw*>(pval);
    if (Sfr33IsManagedValue(v))
        v->pObjectInterface->ObjectRelease(pval, v->pData);
    v->pData            = obj;
    v->Type             = type | GFx::Value::VTC_ManagedBit;
    v->pObjectInterface = iface;
    iface->ObjectAddRef(pval, obj);
    return true;
}

}}}

namespace Scaleform { namespace GFx {
// AS3ValueObjectInterface::CreateObjectValue: pval refers to the AS3 object pdata.
// @0x1424f3d20
bool AS3ValueObjectInterface::CreateObjectValue(Value* pval, void* pdata, bool isdobj)
{
    SF_UNUSED(isdobj);
    return AS3::Sfr33SetObjectValue(this, pval, static_cast<AS3::Object*>(pdata));
}
}} // namespace Scaleform::GFx

namespace Scaleform { namespace GFx { namespace AS3 {

// The same with the interface passed in (the first argument is unused).
// @0x1424f3dc0
bool Sfr33SetObjectValueThrough(void* self, GFx::Value* pval, GFx::Value::ObjectInterface* iface, Object* obj)
{
    SF_UNUSED(self);
    return Sfr33SetObjectValue(iface, pval, obj);
}

// A host value as an AS3 value. Managed strings and objects come from this movie and are shared as they are; a
// function object keeps its kFunction tag. Closures carry their kind in bit 1 of the object pointer.
// The movie's string manager (+0x348).
static SF_INLINE ASStringManager* sm(const MovieRoot* root)
{
    return *reinterpret_cast<ASStringManager* const*>(reinterpret_cast<const UByte*>(root) + 0x348);
}
// v = ASString(node), node already AddRef'd here. The exe keeps the node in a register across the
// out-of-line operator=, so the reference it is passed is a separate copy of the node pointer.
static SF_INLINE void Sfr17AssignNode(Value& v, ASStringNode* node)
{
    {
        ASStringNode* str = node;
        v = reinterpret_cast<const ASString&>(str);
    }
    node->Release();
}
// The exe calls the Value setters out of line here.
#pragma inline_depth(0)
// MS2-FUNCTIONAL 0x1425048d0: rbx and rdi swapped (the destination and the string node); same code otherwise
// @0x1425048d0
void MovieRoot::GFxValue2ASValue(const GFx::Value& gfxVal, Value* pdestVal)
{
    const Sfr33GFxValueRaw& gv = reinterpret_cast<const Sfr33GFxValueRaw&>(gfxVal);
    switch (int(gv.Type & 0x8f))
    {
    case 0:     // VT_Undefined
        pdestVal->SetUndefined();
        break;
    case 2:     // VT_Boolean
        pdestVal->SetBool(*reinterpret_cast<const bool*>(&gv.pData));
        break;
    case 1:     // VT_Null
        pdestVal->SetNull();
        break;
    case 3:     // VT_Int
        pdestVal->SetSInt32(*reinterpret_cast<const SInt32*>(&gv.pData));
        break;
    case 4:     // VT_UInt
        pdestVal->SetUInt32(*reinterpret_cast<const UInt32*>(&gv.pData));
        break;
    case 5:     // VT_Number
        pdestVal->SetNumber(*reinterpret_cast<const Double*>(&gv.pData));
        break;
    case 6:     // VT_String
        if ((UByte)(gv.Type >> 6) & 1)
            pdestVal->Assign(static_cast<ASStringNode*>(gv.pData));   // pData is the node's first field
        else
        {
            ASStringNode* node = sm(this)->CreateStringNode(static_cast<const char*>(gv.pData));
            node->AddRef();
            Sfr17AssignNode(*pdestVal, node);
        }
        break;
    case 7:     // VT_StringW
        {
            const wchar_t* pwstr = static_cast<const wchar_t*>(gv.pData);
            ASStringNode* node;
            if ((UByte)(gv.Type >> 6) & 1)
            {
                // The wide text sits after the node pointer of its storage.
                node = *reinterpret_cast<ASStringNode* const*>(reinterpret_cast<const UByte*>(pwstr) - 8);
                node->AddRef();
            }
            else
            {
                node = sm(this)->CreateStringNode(pwstr);
                node->AddRef();
            }
            Sfr17AssignNode(*pdestVal, node);
        }
        break;
    case 8:     // VT_Object
    case 9:     // VT_Array
    case 10:    // VT_DisplayObject
        {
            Object* obj = static_cast<Object*>(gv.pData);
            if (obj)
            {
                const Traits& tr = obj->GetTraits();
                if (tr.GetTraitsType() == Traits_Function && tr.IsInstanceTraits())
                {
                    ValueAssignCopies::AssignFunction(*pdestVal, reinterpret_cast<Instances::Function*>(obj));
                    break;
                }
            }
            pdestVal->Assign(obj);
        }
        break;
    case 11:    // VT_Closure
        {
            Object* pobj = reinterpret_cast<Object*>(reinterpret_cast<UPInt>(gv.pData) & ~UPInt(2));
            if ((UByte)(reinterpret_cast<UPInt>(gv.pData) >> 1) & 1)
                *pdestVal = Value(pobj, SInt32(gv.DataAux));
            else
                *pdestVal = Value(pobj, *reinterpret_cast<const ThunkInfo*>(gv.DataAux));
        }
        break;
    default:
        break;
    }
}
#pragma inline_depth()
// The protected state of a GFx::MouseState, read and written by GenerateMouseEvents.
struct Sfr33MouseStateAccess : public GFx::MouseState
{
    using GFx::MouseState::TopmostEntity;
    using GFx::MouseState::ActiveEntity;
    using GFx::MouseState::CurButtonsState;
    using GFx::MouseState::PrevButtonsState;
    using GFx::MouseState::LastPosition;
    using GFx::MouseState::WheelDelta;
    using GFx::MouseState::MouseInsideEntityLast;
    using GFx::MouseState::MouseMoved;
};

void* Sfr33MouseStateGetDoubleClickInfo(UByte* self, unsigned buttonMask);

// MovieImpl::GetMouseState: mouse mouseIndex's state, NULL past the fourth (0x50 bytes each at +0x1260).
static SF_FORCEINLINE Sfr33MouseStateAccess* Sfr33GetMouseState(MovieImpl* pmovie, unsigned mouseIndex)
{
    if (mouseIndex >= 4)
        return NULL;
    return static_cast<Sfr33MouseStateAccess*>(
        reinterpret_cast<GFx::MouseState*>(reinterpret_cast<UByte*>(pmovie) + 0x1260) + mouseIndex);
}

// ButtonEventId(id, mouseIndex, rollOverCnt, buttonIdx).
static SF_FORCEINLINE GFx::EventId Sfr33ButtonEventId(UInt32 id, unsigned mouseIndex, UByte rollOverCnt = 0,
                                                     UByte buttonIdx = 0)
{
    GFx::EventId evt(id);
    evt.ButtonId    = buttonIdx;
    evt.RollOverCnt = rollOverCnt;
    evt.MouseIndex  = SByte(mouseIndex);
    return evt;
}

// InteractiveObject / AvmInteractiveObj Increment/DecrementRollOverCnt, Increment/DecrementMouseOverCnt.
static SF_FORCEINLINE UByte Sfr33IncrementCnt(UByte& cnt) { return cnt++; }
static SF_FORCEINLINE UByte Sfr33DecrementCnt(UByte& cnt) { return (cnt != 0) ? --cnt : 0xff; }

// MovieRoot::MouseState::GetDoubleClickInfo (0x142509920), inlined here; the SDK passes the button index.
static SF_FORCEINLINE MovieRoot::MouseState::DoubleClickInfo& Sfr33GetDoubleClickInfo(MovieRoot::MouseState& rs,
                                                                                     unsigned buttonMask)
{
    return *static_cast<MovieRoot::MouseState::DoubleClickInfo*>(
        Sfr33MouseStateGetDoubleClickInfo(reinterpret_cast<UByte*>(&rs), buttonMask));
}

// MovieRoot::GenerateMouseEvents (virtual): the AS3 mouse events of mouse mouseIndex since the last call. Drag
// over/out while the left button is held; roll out of the objects the mouse left (rollover stack, top down) and
// mouse out of the old active object; per released button release outside, mouse up, then click or (fast enough,
// still, with doubleClickEnabled) double click; mouse wheel and move; roll over of the new object and its parents
// up to the stage, then mouse over; mouse down per pressed button. The object under the mouse becomes active.
// This build has no drag-state substitution and propagates the captured mouse move to any object.
// MS2-FUNCTIONAL 0x142504b50: SDK body
// @0x142504b50
void MovieRoot::GenerateMouseEvents(unsigned mouseIndex)
{
    typedef ArrayLH<Ptr<GFx::InteractiveObject> > RolloverArray;
#define SFR33_ROS (*reinterpret_cast<RolloverArray*>(mMouseState[mouseIndex].RolloverStack))
    enum
    {
        Event_MouseOver   = GFx::EventId::Event_LoadStart + 10,
        Event_MouseOut    = GFx::EventId::Event_LoadStart + 11,
        Event_Click       = GFx::EventId::Event_LoadStart + 12,
        Event_DoubleClick = GFx::EventId::Event_LoadStart + 13,
        Event_MouseWheel  = GFx::EventId::Event_LoadStart + 14
    };
    Sfr33MouseStateAccess& ms = *Sfr33GetMouseState(GetMovieImpl(), mouseIndex);
    Ptr<GFx::InteractiveObject> ActiveEntity  = ms.GetActiveEntity();
    Ptr<GFx::InteractiveObject> TopmostEntity = ms.GetTopmostEntity();

    if (ActiveEntity && ActiveEntity->IsUnloaded())
        ActiveEntity = NULL;
    if (TopmostEntity && TopmostEntity->IsUnloaded())
        TopmostEntity = NULL;

    Ptr<GFx::InteractiveObject> PrevActiveEntity = ActiveEntity;

    const KeyboardState* keybSt = GetMovieImpl()->GetKeyboardState(mouseIndex);

    UInt8    checkCount = pAVM->ExtensionsEnabled ? 16 : 1;
    unsigned changeMask = ms.GetPrevButtonsState() ^ ms.GetButtonsState();

    GFx::InteractiveObject* topmostEntitySafe =
        (TopmostEntity) ? TopmostEntity.GetPtr() : static_cast<GFx::InteractiveObject*>(pStage);

    if (ms.GetPrevButtonsState() & GFx::MouseState::MouseButton_Left)
    {
        if (!ms.IsMouseInsideEntityLast())
        {
            if (TopmostEntity == ActiveEntity)
            {
                // onDragOver
                if (ActiveEntity)
                {
                    GFx::EventId evt = Sfr33ButtonEventId(GFx::EventId::Event_DragOver, mouseIndex,
                                                          Sfr33IncrementCnt(ActiveEntity->RollOverCnt));
                    evt.KeysState = keybSt->GetKeyModifiers().States;
                    ActiveEntity->OnMouseEvent(evt);
                }
                ms.SetMouseInsideEntityLast(true);
            }
        }
        else
        {
            if (TopmostEntity != ActiveEntity)
            {
                // onDragOut
                if (ActiveEntity)
                {
                    GFx::EventId evt = Sfr33ButtonEventId(GFx::EventId::Event_DragOut, mouseIndex,
                                                          Sfr33DecrementCnt(ActiveEntity->RollOverCnt));
                    evt.KeysState = keybSt->GetKeyModifiers().States;
                    ActiveEntity->OnMouseEvent(evt);
                }
                ms.SetMouseInsideEntityLast(false);
            }
        }
    }

    // RollOver/MouseOver events
    if (TopmostEntity != ActiveEntity)
    {
        // rollOut
        UPInt rosSz = SFR33_ROS.GetSize();
        SPInt i;
        for (i = (SPInt)rosSz - 1; i >= 0; --i)
        {
            if (!TopmostEntity || (SFR33_ROS[i] != TopmostEntity && !SFR33_ROS[i]->IsAncestor(TopmostEntity)))
            {
                GFx::EventId evt = Sfr33ButtonEventId(GFx::EventId::Event_RollOut, mouseIndex,
                                                      Sfr33DecrementCnt(SFR33_ROS[i]->RollOverCnt));
                evt.KeysState = keybSt->GetKeyModifiers().States;
                SFR33_ROS[i]->OnMouseEvent(evt);
            }
            else
                break;
        }
        SFR33_ROS.PopBack(rosSz - i - 1);

        if (ActiveEntity)
        {
            // mouseOut
            ActiveEntity->AddRef();
            if (mMouseState[mouseIndex].LastMouseOverObj)
                mMouseState[mouseIndex].LastMouseOverObj->Release();
            mMouseState[mouseIndex].LastMouseOverObj = ActiveEntity;
            GFx::EventId evt = Sfr33ButtonEventId(Event_MouseOut, mouseIndex,
                                                  Sfr33DecrementCnt(ToAvmInteractiveObj(ActiveEntity)->MouseOverCnt));
            evt.KeysState = keybSt->GetKeyModifiers().States;
            ActiveEntity->OnMouseEvent(evt);

            // clean up
            if (mMouseState[mouseIndex].LastMouseOverObj)
                mMouseState[mouseIndex].LastMouseOverObj->Release();
            mMouseState[mouseIndex].LastMouseOverObj = NULL;
        }
    }

    // mouse button release
    for (UInt8 buttonIdx = 0; buttonIdx < checkCount; ++buttonIdx)
    {
        unsigned buttonMask = 1 << buttonIdx;
        if (((changeMask >> buttonIdx) & 0x1) != 0)
        {
            // Button was down, now up
            if (ms.GetPrevButtonsState() & buttonMask)
            {
                MovieRoot::MouseState::DoubleClickInfo& dci =
                    Sfr33GetDoubleClickInfo(mMouseState[mouseIndex], buttonIdx);
                if (ms.GetMouseButtonDownEntity(buttonIdx))
                {
                    GFx::EventId evt = Sfr33ButtonEventId(GFx::EventId::Event_ReleaseOutside, mouseIndex, 0, buttonIdx);
                    evt.KeysState = keybSt->GetKeyModifiers().States;
                    ms.GetMouseButtonDownEntity(buttonIdx)->OnMouseEvent(evt);
                }
                GFx::EventId mouseUpEvt = Sfr33ButtonEventId(GFx::EventId::Event_MouseUp, mouseIndex, 0, buttonIdx);
                mouseUpEvt.KeysState = keybSt->GetKeyModifiers().States;
                topmostEntitySafe->OnMouseEvent(mouseUpEvt);
                if (ms.IsMouseInsideEntityLast())
                {
                    bool   dblClick = false;
                    UInt32 tm       = (UInt32)(Timer::GetTicks() / 1000);
                    if (dci.PrevClickTime != 0)
                    {
                        Render::PointF pt = ms.GetLastPosition();
                        int ax = (int)TwipsToPixels(pt.x);
                        int ay = (int)TwipsToPixels(pt.y);
                        if (tm <= dci.PrevClickTime + 300 &&
                            (int)TwipsToPixels(dci.PrevPosition.x) == ax &&
                            (int)TwipsToPixels(dci.PrevPosition.y) == ay)
                        {
                            dblClick = true;
                        }
                    }
                    if (dblClick && (ToAvmInteractiveObj(topmostEntitySafe)->IntFlags & 2))   // doubleClickEnabled
                    {
                        GFx::EventId evt = Sfr33ButtonEventId(Event_DoubleClick, mouseIndex, 0, buttonIdx);
                        evt.KeysState = keybSt->GetKeyModifiers().States;
                        topmostEntitySafe->OnMouseEvent(evt);
                    }
                    else if (topmostEntitySafe == ms.GetMouseButtonDownEntity(buttonIdx))
                    {
                        GFx::EventId evt = Sfr33ButtonEventId(Event_Click, mouseIndex, 0, buttonIdx);
                        evt.KeysState = keybSt->GetKeyModifiers().States;
                        topmostEntitySafe->OnMouseEvent(evt);
                    }
                    if (dblClick)
                        dci.PrevClickTime = 0;
                    else
                        dci.PrevClickTime = tm;
                    dci.PrevPosition = ms.GetLastPosition();
                }
                ms.SetMouseButtonDownEntity(buttonIdx, NULL);
            }
        }
    }

    if (ms.WheelDelta != 0)
    {
        GFx::EventId evt = Sfr33ButtonEventId(Event_MouseWheel, mouseIndex);
        evt.KeysState       = keybSt->GetKeyModifiers().States;
        evt.MouseWheelDelta = (SInt8)ms.WheelDelta;
        topmostEntitySafe->OnMouseEvent(evt);
    }

    if (ms.MouseMoved)
    {
        GFx::EventId evt = Sfr33ButtonEventId(GFx::EventId::Event_MouseMove, mouseIndex);
        evt.KeysState       = keybSt->GetKeyModifiers().States;
        evt.MouseWheelDelta = (SInt8)ms.WheelDelta;
        topmostEntitySafe->OnMouseEvent(evt);

        // the captured mouse (left button down, mouse moved) also goes to the pressed object
        if (ms.GetMouseButtonDownEntity(0) && ms.GetMouseButtonDownEntity(0) != topmostEntitySafe)
        {
            GFx::EventId evt = Sfr33ButtonEventId(GFx::EventId::Event_MouseMove, mouseIndex, 0, 0);
            evt.KeysState = keybSt->GetKeyModifiers().States;
            ms.GetMouseButtonDownEntity(0)->PropagateMouseEvent(evt);
        }
    }

    // New active entity is whatever is below the mouse right now.
    if (TopmostEntity != ActiveEntity)
    {
        ActiveEntity = TopmostEntity;

        if (ActiveEntity)
        {
            // rollOver
            bool  fireRollover = true;
            UPInt rosSz        = SFR33_ROS.GetSize();
            if (rosSz)
            {
                for (SPInt i = (SPInt)rosSz - 1; i >= 0; --i)
                {
                    if (SFR33_ROS[i] == ActiveEntity)
                    {
                        fireRollover = false;
                        break;
                    }
                }
            }
            if (fireRollover)
            {
                Ptr<GFx::InteractiveObject> cur   = ActiveEntity;
                GFx::InteractiveObject*     stage = static_cast<GFx::InteractiveObject*>(pStage);
                UPInt                       idx   = SFR33_ROS.GetSize();
                for (; cur && cur != stage; cur = cur->GetParent())
                {
                    if (idx != 0)
                    {
                        if (SFR33_ROS[idx - 1] == cur)
                            break;
                    }
                    GFx::EventId evt = Sfr33ButtonEventId(GFx::EventId::Event_RollOver, mouseIndex,
                                                          Sfr33IncrementCnt(cur->RollOverCnt));
                    evt.KeysState = keybSt->GetKeyModifiers().States;
                    cur->OnMouseEvent(evt);
                    SFR33_ROS.InsertAt(idx, cur);
                }
            }

            // mouseOver
            GFx::EventId evt = Sfr33ButtonEventId(Event_MouseOver, mouseIndex,
                                                  Sfr33IncrementCnt(ToAvmInteractiveObj(ActiveEntity)->MouseOverCnt));
            evt.KeysState = keybSt->GetKeyModifiers().States;
            ActiveEntity->OnMouseEvent(evt);
            // cleanup
            if (mMouseState[mouseIndex].LastMouseOverObj)
                mMouseState[mouseIndex].LastMouseOverObj->Release();
            mMouseState[mouseIndex].LastMouseOverObj = NULL;
        }

        ms.SetMouseInsideEntityLast(true);
    }
    else if (!TopmostEntity)
    {
        SFR33_ROS.Clear();
    }

    // mouse button press
    for (UInt8 buttonIdx = 0; buttonIdx < checkCount; ++buttonIdx)
    {
        unsigned buttonMask = 1 << buttonIdx;
        if (((changeMask >> buttonIdx) & 0x1) != 0)
        {
            // Button was up, now down
            if ((ms.GetPrevButtonsState() & buttonMask) == 0)
            {
                // onPress
                GFx::EventId evt = Sfr33ButtonEventId(GFx::EventId::Event_MouseDown, mouseIndex);
                evt.KeysState = keybSt->GetKeyModifiers().States;
                GFx::InteractiveObject* activeEntitySafe =
                    (ActiveEntity) ? ActiveEntity.GetPtr() : static_cast<GFx::InteractiveObject*>(pStage);
                evt.ButtonId = buttonIdx;
                activeEntitySafe->OnMouseEvent(evt);
                ms.SetMouseButtonDownEntity(buttonIdx, activeEntitySafe);

                ms.SetMouseInsideEntityLast(true);
            }
        }
    }
    ms.SetActiveEntity(ActiveEntity.GetPtr());
    ms.MouseMoved = false;
    ms.WheelDelta = 0;
#undef SFR33_ROS
}

// Stage's ExecuteFrameTags and GetCurrentFrame are inline in as3_stage.h, so no unit emits them under their own
// names; sfr_as3_15's Stage vftable reaches them by address.
// MS2-FUNCTIONAL: out-of-line stand-in for the inline Stage::ExecuteFrameTags (the stage has no frame tags).
// @0x1424feaf0
void FUN_1424feaf0(Stage* self, unsigned frame)
{
    SF_UNUSED2(self, frame);
}

// MS2-FUNCTIONAL: out-of-line stand-in for the inline Stage::GetCurrentFrame (the root movie clip's frame).
// @0x1425084e0
unsigned FUN_1425084e0(const Stage* self)
{
    return self->pRoot ? self->pRoot->GetCurrentFrame() : 0;
}

}}} // namespace Scaleform::GFx::AS3

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {


}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

namespace Scaleform {
using AS3NamespaceHash = GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc;
using AS3NamespaceSet = HashSetDH<GFx::AS3::Instances::Namespace*, AS3NamespaceHash,
                                 AS3NamespaceHash, Stat_Default_Mem,
                                 HashsetEntry<GFx::AS3::Instances::Namespace*, AS3NamespaceHash>>;
template void AS3NamespaceSet::CheckExpand();

using DisplayObjectWeakArray = ArrayLH<WeakPtr<GFx::DisplayObject>, 2, ArrayDefaultPolicy>;
using DisplayObjectWeakNode = HashNode<int, AutoPtr<DisplayObjectWeakArray>, IdentityHash<int>>;
using DisplayObjectWeakEntry = HashsetNodeEntry<DisplayObjectWeakNode, DisplayObjectWeakNode::NodeHashF>;
using DisplayObjectWeakHash = HashSetBase<DisplayObjectWeakNode, DisplayObjectWeakNode::NodeHashF,
                                          DisplayObjectWeakNode::NodeAltHashF, AllocatorLH<int, 2>,
                                          DisplayObjectWeakEntry>;
template void DisplayObjectWeakHash::CheckExpand(void*);
// @0x1424ef380
template void DisplayObjectWeakHash::Clear();
// @0x1424ef970
template void DisplayObjectWeakEntry::Clear();

using AS3SlotNameSet = decltype(GFx::AS3::Slots::SetType::mHash)::BaseType;
template void AS3SlotNameSet::Clear();

using AS3AbcNamespaceSet = decltype(GFx::AS3::AbcMultinameHash<GFx::AS3::SPtr<GFx::AS3::Instances::Namespace> >::TContainer::mHash)::BaseType;
template void AS3AbcNamespaceSet::CheckExpand(void*);
template AS3AbcNamespaceSet::~HashSetBase();

using AS3DynAttrsSet = decltype(GFx::AS3::Object::DynAttrsType::mHash)::BaseType;
template void AS3DynAttrsSet::CheckExpand(void*);

template void ConstructorMov<GFx::AS3::SPtr<const GFx::AS3::Instances::Namespace> >::DestructArray(
    GFx::AS3::SPtr<const GFx::AS3::Instances::Namespace>*, UPInt);
template void ConstructorMov<GFx::AS3::SPtr<GFx::AS3::Instances::Namespace> >::DestructArray(
    GFx::AS3::SPtr<GFx::AS3::Instances::Namespace>*, UPInt);
template void ConstructorCPP<GFx::Value>::DestructArray(GFx::Value*, UPInt);

using AS3GcRootPages = ArrayPagedBase<const GFx::AS3::ASRefCountBaseType*, 10, 5, AllocatorPagedLH_POD<const GFx::AS3::ASRefCountBaseType*, Stat_Default_Mem> >;
template void AS3GcRootPages::ClearAndRelease();
namespace GFx { namespace AS2 { class Object; } }
using AS2ObjectIdentitySet = decltype(HashUncached<GFx::AS2::Object*, GFx::AS2::Object*, IdentityHash<GFx::AS2::Object*> >::mHash)::BaseType;
template void AS2ObjectIdentitySet::Clear();
template void HashSetBase<const void*, FixedSizeHash<const void*>, FixedSizeHash<const void*>, AllocatorGH<const void*, 2>, HashsetCachedEntry<const void*, FixedSizeHash<const void*> > >::Clear();   // sfr_as3_19's object-pointer set; the exe folds it with the one above
using AS3ClassTraitsCacheSet = decltype(GFx::AS3::TClassTraitsCache::TContainer::mHash);
template void AS3ClassTraitsCacheSet::BaseType::Clear();
using AS3ClassTraitsCacheNode = HashNode<GFx::AS3::TClassTraitsCache::Key, GFx::AS3::ClassTraits::Traits*,
                                         GFx::AS3::TClassTraitsCache::Key::HashFunctor>;
template void HashsetCachedNodeEntry<AS3ClassTraitsCacheNode, AS3ClassTraitsCacheNode::NodeHashF>::Clear();

// MS2-FUNCTIONAL ?Construct@?$ConstructorMov@VValue@AS3@GFx@Scaleform@@@Scaleform@@SAXPEAXAEBVValue@AS3@GFx@2@@Z: element copy construction retains the same Value payloads; the exe uses an explicit tag/refcount sequence.
// @0x1424f05a0
template void ConstructorMov<GFx::AS3::Value>::Construct(void*, const GFx::AS3::Value&);
// MS2-FUNCTIONAL ?DestructArray@?$ConstructorMov@VValue@AS3@GFx@Scaleform@@@Scaleform@@SAXPEAVValue@AS3@GFx@2@_K@Z: Value destruction releases the same tagged references; the exe clears weak-reference fields explicitly.
// @0x1424f6d50
template void ConstructorMov<GFx::AS3::Value>::DestructArray(GFx::AS3::Value*, UPInt);
// MS2-FUNCTIONAL ?ConstructArray@?$ConstructorMov@VValue@AS3@GFx@Scaleform@@@Scaleform@@SAXPEAX_KPEBVValue@AS3@GFx@2@@Z: the recovered copy loop delegates each element to Value copy construction; the exe emits raw member copies followed by tag-based AddRef.
// @0x1424f08d0
template void ConstructorMov<GFx::AS3::Value>::ConstructArray(void*, UPInt, const GFx::AS3::Value*);
}

namespace Scaleform { namespace GFx {

// The color transform of the display object pdata scripts.
// @0x142508560
bool AS3ValueObjectInterface::GetCxform(void* pdata, Render::Cxform* pcx) const
{
    AS3::Object* pobj = static_cast<AS3::Object*>(pdata);
    const AS3::Traits& tr = pobj->GetTraits();
    if ((unsigned)(tr.GetTraitsType() - AS3::Traits_DisplayObject_Begin) <
            (unsigned)(AS3::Traits_DisplayObject_End - AS3::Traits_DisplayObject_Begin) &&
        tr.IsInstanceTraits())
    {
        *pcx = static_cast<AS3::Instances::fl_display::DisplayObject*>(pobj)->pDispObj->GetCxform();
        return true;
    }
    return false;
}

// The matrix of the display object pdata scripts, translation in pixels.
// @0x142509850
bool AS3ValueObjectInterface::GetDisplayMatrix(void* pdata, Render::Matrix2F* pmat) const
{
    AS3::Object* pobj = static_cast<AS3::Object*>(pdata);
    const AS3::Traits& tr = pobj->GetTraits();
    if ((unsigned)(tr.GetTraitsType() - AS3::Traits_DisplayObject_Begin) <
            (unsigned)(AS3::Traits_DisplayObject_End - AS3::Traits_DisplayObject_Begin) &&
        tr.IsInstanceTraits())
    {
        Render::Matrix2F m = static_cast<AS3::Instances::fl_display::DisplayObject*>(pobj)->pDispObj->GetMatrix();
        m.Tx() = TwipsToPixels(m.Tx());
        m.Ty() = TwipsToPixels(m.Ty());
        *pmat = m;
        return true;
    }
    return false;
}

// DisplayObjContainer::GetBounds, a byte-identical copy (the other one is 0x1425db2f0): the display list's bounds
// under t.
struct Sfr33ContainerBounds
{
    RectF GetBounds(const Render::Matrix2F& t) const;
};
// @0x1425078e0
RectF Sfr33ContainerBounds::GetBounds(const Render::Matrix2F& t) const
{
    return reinterpret_cast<const DisplayList*>(reinterpret_cast<const UByte*>(this) + 0xd8)->GetBounds(t);
}

}} // namespace Scaleform::GFx

// MovieRoot's PathTokenizer (AS3_MovieRoot.cpp): the exe calls StringDataPtr::GetNextToken('.') and inlines the rest.
class Sfr33PathTokenizer
{
    mutable Scaleform::StringDataPtr Path;
    mutable Scaleform::StringDataPtr Token;
public:
    Sfr33PathTokenizer(const char* ppath) : Path(ppath) {}
    bool HasToken() const { return Path.GetSize() > 0; }
    const Scaleform::StringDataPtr& NextToken() const
    {
        Token = Path.GetNextToken('.');
        Path.TrimLeft(Token.GetSize());
        if (Path.ToCStr()[0] == '.') Path.TrimLeft(1);
        return Token;
    }
};

// FormatD1<const char*> stays out of line in the exe (0x1423e85f0, sfr_as3_01c).
template<> void Scaleform::MsgFormat::FormatD1<const char*>(const char* const& v);

namespace Scaleform { namespace GFx { namespace AS3 {
// Value::Assign as the exe inlines it into GetASVariableAtPath.
struct Sfr17ValueInline
{
    static __forceinline void Assign(Value& self, const Value& other)
    {
        self.Release();
        SIMD::PrefetchObj(&other);
        memcpy(&self, &other, sizeof(Value));
        self.AddRef();
    }
};

// Multiname(Namespace&, const Value&) with SetRTNameUnsafe, the QName copy and PostProcessName all inlined, as in
// GetASVariableAtPath. Same layout as Multiname; the out-of-line Multiname dtor is not called (the exe expands it).
struct Sfr17PathMultiname
{
    Abc::MultinameKind      Kind;
    SPtr<GASRefCountBase>   Obj;
    Value                   Name;
    __forceinline Sfr17PathMultiname(Instances::Namespace& ns, const Value& name)
        : Kind(static_cast<Abc::MultinameKind>(0))
        , Obj(&ns)
    {
        const UInt32 k = static_cast<UInt32>(name.GetKind());
        if (k - 0xc <= 3 && name.GetGASRefCountBase() != NULL)
        {
            const Traits& tr = reinterpret_cast<Object*>(name.GetGASRefCountBase())->GetTraits();
            if (static_cast<int>(tr.TraitsType) == 0xc && (static_cast<UInt8>(~static_cast<UInt8>(static_cast<UInt8>(tr.Flags) >> 5)) & 1) != 0)
            {
                const UPInt q = reinterpret_cast<UPInt>(name.GetGASRefCountBase());
                FUN_1424e0d40(Name, *reinterpret_cast<const ASString*>(q + 0x38));
                if (Name.IsString())
                {
                    ASString n = Name.AsString();
                    if (n.GetSize() != 0 && n[0] == '*')
                        FUN_1424e0d40(Name, ASString(n.GetManager()->GetEmptyStringNode()));
                }
                // SPtr::SetPtr, inlined
                GASRefCountBase* p = reinterpret_cast<GASRefCountBase*>(*reinterpret_cast<UPInt*>(q + 0x40));
                GASRefCountBase*& raw = Obj.GetRawRef();
                if (p != raw)
                {
                    if (raw)
                    {
                        if (reinterpret_cast<UPInt>(raw) & 1)
                            raw = reinterpret_cast<GASRefCountBase*>(reinterpret_cast<UPInt>(raw) - 1);
                        else
                            raw->Release();
                    }
                    if (p)
                        p->AddRef();
                    raw = p;
                }
                *reinterpret_cast<UInt32*>(this) &= 0xfffffff9;
                return;
            }
        }
        Name.AssignUnsafe(name);
        // PostProcessName(false); the three renames share one assignment
        if (!Name.IsString())
            return;
        ASString n = Name.AsString();
        if (n.GetSize() == 0)
            return;
        ASStringNode* node;
        if (n[0] == '*')
            node = n.GetManager()->GetEmptyStringNode();
        else if (n[0] == '@')
        {
            Kind = static_cast<Abc::MultinameKind>(Kind | 8);
            if (n.GetSize() == 2 && n[1] == '*')
                node = n.GetManager()->GetEmptyStringNode();
            else
                node = n.SubstringNode(1, n.GetSize());
        }
        else
            return;
        FUN_1424e0d40(Name, ASString(node));
    }
    Multiname& Get() { return *reinterpret_cast<Multiname*>(this); }
    const Multiname& Get() const { return *reinterpret_cast<const Multiname*>(this); }
};
}}} // namespace Scaleform::GFx::AS3

// MovieRoot::GetASVariableAtPath: the value at the dotted path ppathToVar. A global object property of that name
// comes first; otherwise the path is walked from the stage, or from root1 under a "_root", "_level0" or "root"
// prefix, one property (else named display child) per token. A token in the middle that is not an object is logged
// and ends the walk with null. False when there is no path, no root1 or a token resolves to nothing.
// MS2-FUNCTIONAL 0x142506000: the Multiname ctor, Value::Assign, GetSlotValueUnsafe, Swap and the log Format are
// inlined as in the exe
// @0x142506000
bool FUN_142506000(const Scaleform::GFx::AS3::MovieRoot* proot, Scaleform::GFx::AS3::Value* pval, const char* ppathToVar)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    if (!ppathToVar)
        return false;
    MovieRoot* root = const_cast<MovieRoot*>(proot);
    root->CheckAvm();
    pval->SetUndefined();
    VM& vm = *root->pAVM;
    GFx::InteractiveObject* pmain = root->GetMovieImpl()->pMainMovie;
    AvmDisplayObjContainer* pstage =
        pmain ? AvmDisplayObjContainer::FromBase(pmain->GetAvmObjImpl()->ToAvmDispContainerBase()) : NULL;
    Value resolvedVal;
    Sfr17ValueInline::Assign(resolvedVal, Value(pstage->GetAS3Obj(), Value::InlineObj));

    // a global first
    const Multiname gname(vm, StringDataPtr(ppathToVar));
    PropRef globalProp;
    Sfr33FindGOProperty(globalProp, vm, *reinterpret_cast<const ArrayLH<Instances::fl::GlobalObject*>*>(&vm.GlobalObjects),
                        gname, FUN_14250d760(vm, gname));
    if (Sfr33PropFound(globalProp))
    {
        Value v;
        if (!Sfr17GetSlotValueUnsafe(globalProp, vm, v))
            return false;
        Sfr18ValueSwap::Swap(*pval, v);
        return true;
    }

    // the known prefixes: all but "stage" start from root1
    bool isroot1 = false;
    const char* ppath = ppathToVar;
    unsigned offset = 0;
    bool r1allow = true;
    switch (ppath[0])
    {
    case '_':
        if (!strncmp(ppath + 1, "root", 4)) { offset += 5; }
        else if (!strncmp(ppath + 1, "level0", 5)) { offset += 7; }
        break;
    case 'r': if (!strncmp(ppath + 1, "oot", 3)) { offset += 4; } break;
    case 's': if (!strncmp(ppath + 1, "tage", 4)) { offset += 5; r1allow = false; } break;
    }
    switch (ppath[offset])
    {
    case '.':  { offset++; }
    case '\0': { isroot1 = r1allow && true; ppath += offset; }
    }
    if (isroot1)
    {
        GFx::DisplayObject* proot1 = pstage->GetDisplayObjContainer()->mDisplayList.GetDisplayObjectByName(
            root->BuiltinsMgr.CreateConstString("root1"), true);
        if (!proot1 || !proot1->IsDisplayObjContainer())
            return false;
        Sfr17ValueInline::Assign(resolvedVal, Value(AvmDisplayObjContainer::FromBase(
            proot1->GetAvmObjImpl()->ToAvmDispContainerBase())->GetAS3Obj(), Value::InlineObj));
    }

    // one property per token
    Sfr33PathTokenizer pt(ppath);
    while (pt.HasToken())
    {
        const StringDataPtr& token = pt.NextToken();
        GFx::ASString propName = root->BuiltinsMgr.CreateString(token.ToCStr(), token.GetSize());
        const Sfr17PathMultiname prop(vm.GetPublicNamespace(), Value(propName, Value::InlineStr));
        Value subVal;
        Object* pobj = resolvedVal.GetObject();
        if (!pobj)
        {
            pval->SetUndefined();
            if (vm.IsException())
                vm.OutputAndIgnoreException();
            return false;
        }
        if (!pobj->GetProperty(prop.Get(), subVal))
        {
            // not a property: maybe a named child of a display object container
            const Traits& tr = pobj->GetTraits();
            if ((unsigned)(tr.GetTraitsType() - Traits_DisplayObjectContainer) <
                    (unsigned)(Traits_DisplayObject_End - Traits_DisplayObjectContainer) &&
                tr.IsInstanceTraits())
            {
                GFx::DisplayObject* pdo = static_cast<Instances::fl_display::DisplayObject*>(pobj)->pDispObj;
                AvmDisplayObjContainer* pcurr = pdo->IsDisplayObjContainer()
                    ? AvmDisplayObjContainer::FromBase(pdo->GetAvmObjImpl()->ToAvmDispContainerBase()) : NULL;
                Instances::fl_display::DisplayObject* pchild = pcurr->GetAS3ChildByName(propName);
                if (!pchild)
                {
                    if (vm.IsException())
                        vm.OutputAndIgnoreException();
                    return false;
                }
                subVal = Value(pchild, Value::InlineObj);
            }
        }
        resolvedVal = subVal;
        if (pt.HasToken() && !resolvedVal.IsObject())
        {
            if (Log* plog = root->GetMovieImpl()->GetLog().GetPtr())
            {
                StringBuffer s(Memory::GetGlobalHeap());
                MsgFormat f((MsgFormat::Sink(s)));
                f.Parse("Token '{0}' in path '{1}' was not resolved to a valid Object! This may be caused by a property "
                        "that is not of Object type, or by using reserved words/properties for MovieClip names in the "
                        "display tree.");
                f.FormatD1(token);
                f.FormatD1(ppathToVar);
                f.FinishFormatD();
                plog->LogError(s.ToCStr());
            }
            resolvedVal.SetNull();
            break;
        }
    }
    *pval = resolvedVal;
    return true;
}

// ---- (sfr24) bodies of virtuals the full exe links by name (work/sfr35/outside-units.tsv) ----
static inline void FUN_1425303b0(Scaleform::UPInt entry) { ::Scaleform::GFx::AS3::Sfr31ClassTraitsCleanup(entry); }   // shutdown of a registered entry (sfr_as3_19)

namespace Scaleform { namespace GFx { namespace AS3 {

// Calling the class constructs an instance.
// @0x1424ee7d0
void ClassCallConstruct::Call(const Value& /*_this*/, Value& result, unsigned argc, const Value* const argv)
{
    Construct(result, argc, argv);
}

// A plain object is not callable: nothing happens.
// @0x1424ee7f0
void Object::Call(const Value& /*_this*/, Value& /*result*/, unsigned /*argc*/, const Value* const /*argv*/)
{
}

// The default conversion keeps the value as it is.
// @0x1424f1cf0
Value Class::ConvertCopy(const Value& v, const Traits& /*ot*/) const
{
    return v;
}

// The base support (E4X off) knows no XML: nothing to report, compare or walk.
// @0x1424f4a80
void XMLSupport::DescribeType(VM& /*vm*/, SPtr<Instances::fl::XML>& /*result*/, const Value& /*value*/) const
{
}

// @0x1424f97d0
CheckResult XMLSupport::EqualsQName(bool& result, Instances::fl::QName& /*l*/, Instances::fl::QName& /*r*/) const
{
    result = false;
    return false;
}

// @0x1424f9830
CheckResult XMLSupport::EqualsXML(bool& stop, bool& result, Instances::fl::XML& /*l*/, const Value& /*r*/) const
{
    stop   = true;
    result = false;
    return false;
}

// @0x1424f9840
CheckResult XMLSupport::EqualsXML(bool& result, Instances::fl::XML& /*l*/, Instances::fl::XML& /*r*/) const
{
    result = false;
    return false;
}

// @0x1424f9ad0
CheckResult XMLSupport::EqualsXMLList(bool& result, Instances::fl::XMLList& /*l*/, const Value& /*v*/) const
{
    result = false;
    return false;
}

// @0x142504510
void XMLSupport::ForEachChild_GC(Collector* /*prcc*/, GcOp /*op*/) const
{
}

// @0x142504520
void XMLSupportImpl::ForEachChild_GC(Collector* /*prcc*/, GcOp /*op*/) const
{
}

// @0x142509130
CheckResult XMLSupport::GetDescendants(Value& /*v*/, const Multiname& /*mn*/) const
{
    return false;
}

// @0x1425080a0
const ClassTraits::Traits* XMLSupport::GetClassTraitsQName() const
{
    return NULL;
}

// @0x1425080c0
const ClassTraits::Traits* XMLSupport::GetClassTraitsXML() const
{
    return NULL;
}

// @0x1425080e0
const ClassTraits::Traits* XMLSupport::GetClassTraitsXMLList() const
{
    return NULL;
}

// A plain display object has no children to give up.
// @0x1424f7180
bool AvmDisplayObj::DetachChild(DisplayObjectBase* /*ch*/)
{
    return false;
}

// Containers run no frame scripts of their own (sprites do).
// @0x1424fe5f0
void AvmDisplayObjContainer::ExecuteFrame0Events()
{
}

// @0x1424feaa0
void AvmDisplayObjContainer::ExecuteFrameTags(unsigned /*frame*/)
{
}

// @0x1424fee00
void AvmDisplayObjContainer::ExecuteInitActionFrameTags(unsigned /*frame*/)
{
}

// @0x142504800
void AvmDisplayObjContainer::ForceShutdown()
{
}

// The script part of the host call: the body shared with Execute.
// @0x142500250
void UserDefinedFunction::ExecuteUnsafe(const Value& _this, Value& result, unsigned argc, const Value* argv)
{
    FUN_1424feb00(this, _this, result, argc, argv);
}

// The VM drops the file from its list of loaded ABC files.
// @0x1425008d0
void VMAbcFile::Finalize_GC()
{
    FUN_1425303b0((UPInt)this);
}

// @0x142505e40
const char* VMAbcFile::GetAS3ObjectType() const
{
    return "VMAbcFile";
}

// A new character goes into the play list right before its parent.
// @0x142501a60
InteractiveObject* AvmInteractiveObj::FindInsertToPlayList(InteractiveObject* ch)
{
    InteractiveObject* parent = ch->GetParent();
    return parent ? parent->pPlayPrev : NULL;
}

// @0x142508530
unsigned AvmInteractiveObj::GetCursorType() const
{
    return 0;
}

// @0x142508910
const char* AvmDisplayObj::GetDefaultASClassName() const
{
    return "flash.display.DisplayObject";
}

// @0x142508920
const char* AvmDisplayObjContainer::GetDefaultASClassName() const
{
    return "flash.display.DisplayObjectContainer";
}

// @0x142508930
const char* AvmInteractiveObj::GetDefaultASClassName() const
{
    return "flash.display.InteractiveObject";
}

// (outside-units.tsv names this VA AvmDisplayObjContainer; the string and symbols-manual say AvmLoader)
// @0x142508940
const char* AvmLoader::GetDefaultASClassName() const
{
    return "flash.display.Loader";
}

// @0x142508950
const char* AvmSprite::GetDefaultASClassName() const
{
    return "flash.display.Sprite";
}

// The dynamic property in slot ind of the dynamic attribute table.
// @0x142509a80
void Object::GetDynamicProperty(AbsoluteIndex ind, Value& value)
{
    DynAttrsType::Iterator it = DynAttrs.Begin();
    value.Assign(DynAttrsType::Iterator(it.GetContainer(), static_cast<UInt32>(ind.Get()))->Second);
}

// Only traits made from an ABC file have one.
// @0x142509ca0
VMAbcFile* Traits::GetFilePtr() const
{
    return NULL;
}

// @0x142509d30
unsigned Traits::GetFixedMemSize() const
{
    return MemSize;
}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx {

// @0x1424eeca0
int InteractiveObject::CheckAdvanceStatus(bool /*playingNow*/)
{
    return 0;
}

// @0x1424f74c0
void DisplayObject::DoDisplayCallback()
{
}

// The host's display callback, when one is set.
// @0x1424f74d0
void InteractiveObject::DoDisplayCallback()
{
    if (pDisplayCallback)
        pDisplayCallback(DisplayCallbackUserPtr);
}

// @0x1424fe610
void InteractiveObject::ExecuteFrame0Events()
{
}

// @0x1424fedf0
void DisplayObjContainer::ExecuteImportedInitActions(MovieDef* /*psourceMovie*/)
{
}

// @0x142504840
void DisplayObjectBase::ForceShutdown()
{
}

// @0x142506ef0
bool DisplayObject::GetAcceptAnimMoves() const
{
    return (Flags & Mask_AcceptAnimMoves) != 0;
}

// @0x1425084c0
bool DisplayObject::GetContinueAnimationFlag() const
{
    return (Flags & Mask_ContinueAnimation) != 0;
}

// @0x1425084d0
unsigned InteractiveObject::GetCurrentFrame() const
{
    return 0;
}

// A character without geometry has empty bounds.
// @0x142507900
RectF DisplayObjectBase::GetBounds(const Matrix& /*t*/) const
{
    return RectF(0, 0, 0, 0);
}

// @0x142507b50
CharacterDef* DisplayObjContainer::GetCharacterDef() const
{
    return NULL;
}

// @0x142509990
DrawingContext* DisplayObject::GetDrawingContext()
{
    return NULL;
}

// The length of the AS3 array pdata (its SparseArray Length, +0x38; the Array instance class is not visible here).
// MS2-FUNCTIONAL: raw Array instance offset
// @0x142507540
unsigned AS3ValueObjectInterface::GetArraySize(void* pdata) const
{
    return (unsigned)*reinterpret_cast<const UPInt*>(static_cast<const UByte*>(pdata) + 0x38);
}

// The movie's advance statistics.
// @0x1425071d0
AMP::ViewStats* AS3ValueObjectInterface::GetAdvanceStats() const
{
    return (AMP::ViewStats*)pMovieRoot->pASMovieRoot->GetMovieImpl()->pAdvanceStats;
}

}} // namespace Scaleform::GFx

// MS2-PIN: ?ConstructArray@?$ConstructorMov@VValue@AS3@GFx@Scaleform@@@Scaleform@@SAXPEAX_KPEBVValue@AS3@GFx@2@@Z 0x1424f08d0
// MS2-PIN: ?Construct@?$ConstructorMov@VValue@AS3@GFx@Scaleform@@@Scaleform@@SAXPEAXAEBVValue@AS3@GFx@2@@Z 0x1424f05a0
// MS2-PIN: ?DestructArray@?$ConstructorMov@VValue@AS3@GFx@Scaleform@@@Scaleform@@SAXPEAVValue@AS3@GFx@2@_K@Z 0x1424f6d50
// sfr33: byte-identical HashSetBase look-alikes named after their setRawCapacity callees (tplpin --simulate --force-order)
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@H$01@2@V?$HashsetNodeEntry@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1424eedc0
// MS2-PIN: ?CheckExpand@?$HashSetBase@PEAVNamespace@Instances@AS3@GFx@Scaleform@@UNamespaceHashFunc@NamespaceInstanceFactory@345@U67345@U?$AllocatorDH@PEAVNamespace@Instances@AS3@GFx@Scaleform@@$01@5@V?$HashsetEntry@PEAVNamespace@Instances@AS3@GFx@Scaleform@@UNamespaceHashFunc@NamespaceInstanceFactory@345@@5@@Scaleform@@QEAAXPEAX@Z 0x1424eee10
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@KV?$SPtr@VFunction@InstanceTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@K@4@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@K$0BFE@@2@V?$HashsetCachedNodeEntry@U?$HashNode@KV?$SPtr@VFunction@InstanceTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@K@4@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1424eee60
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@PEAUASStringNode@GFx@Scaleform@@_JVASStringNodeHashFunc@AS3@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@PEAUASStringNode@GFx@Scaleform@@$0BEN@@2@V?$HashsetNodeEntry@U?$HashNode@PEAUASStringNode@GFx@Scaleform@@_JVASStringNodeHashFunc@AS3@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1424eeeb0
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@PEAVGASRefCountBase@AS3@GFx@Scaleform@@PEAVWeakProxy@234@V?$FixedSizeHash@PEAVGASRefCountBase@AS3@GFx@Scaleform@@@4@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorGH@PEAVGASRefCountBase@AS3@GFx@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@PEAVGASRefCountBase@AS3@GFx@Scaleform@@PEAVWeakProxy@234@V?$FixedSizeHash@PEAVGASRefCountBase@AS3@GFx@Scaleform@@@4@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1424eef00
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@PEAUStickyVarNode@MovieImpl@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@PEAUStickyVarNode@MovieImpl@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1424eef50
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@PEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@3@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@PEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@3@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1424ef090
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1424ef0e0
// MS2-PIN: ?CheckExpand@?$HashSetBase@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@V54@U?$AllocatorLH@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@@4@@Scaleform@@QEAAXPEAX@Z 0x1424ef130
// MS2-PIN: ??1?$HashSetBase@U?$HashNode@KV?$SPtr@VFunction@InstanceTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@K@4@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@K$0BFE@@2@V?$HashsetCachedNodeEntry@U?$HashNode@KV?$SPtr@VFunction@InstanceTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@K@4@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAA@XZ 0x1424ef450
// MS2-PIN: ?Clear@?$HashSetBase@U?$HashNode@KV?$SPtr@VFunction@InstanceTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@K@4@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@K$0BFE@@2@V?$HashsetCachedNodeEntry@U?$HashNode@KV?$SPtr@VFunction@InstanceTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@K@4@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXXZ 0x1424ef500
// MS2-PIN: ??1?$HashSetBase@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@V54@U?$AllocatorLH@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@@4@@Scaleform@@QEAA@XZ 0x1424ef7b0
// MS2-PIN: ?Clear@?$HashSetBase@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@V54@U?$AllocatorLH@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@@4@@Scaleform@@QEAAXXZ 0x1424ef860
// MS2-PIN: ?GetConstructor@Traits@AS3@GFx@Scaleform@@QEBAAEAVClass@234@XZ 0x142508490
// MS2-PIN: ?Clear@?$ArrayBase@U?$ArrayData@PEAVVMAbcFile@AS3@GFx@Scaleform@@U?$AllocatorLH_POD@PEAVVMAbcFile@AS3@GFx@Scaleform@@$0BEJ@@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAXXZ 0x1424ef2a0
// MS2-PIN: ??_7FileLoader@AS3@GFx@Scaleform@@6B@ 0x14317b798
// MS2-PIN: ??_7Sfr33NullFileLoader@AS3@GFx@Scaleform@@6B@ 0x14317f470
// MS2-PIN: ?Clear@?$HashSetBase@U?$HashNode@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@$0BEJ@@2@V?$HashsetCachedNodeEntry@U?$HashNode@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXXZ 0x1424ef660
// MS2-PIN: ?Clear@?$HashSetBase@U?$HashNode@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@KVASStringNodePtrHashFunc@AS3@GFx@2@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$0BEN@@2@V?$HashsetNodeEntry@U?$HashNode@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@KVASStringNodePtrHashFunc@AS3@GFx@2@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXXZ 0x1424ef720
// MS2-PIN: ?Clear@?$HashSetBase@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@H$01@2@V?$HashsetNodeEntry@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXXZ 0x1424ef380
// MS2-PIN: ?Clear@?$HashsetNodeEntry@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@@Scaleform@@QEAAXXZ 0x1424ef970
// MS2-PIN: ?Clear@?$HashsetCachedNodeEntry@U?$HashNode@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@@Scaleform@@UNodeHashF@12@@Scaleform@@QEAAXXZ 0x1424ef910
// MS2-PIN: ?DestructArray@?$ConstructorMov@V?$SPtr@$$CBVNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@Scaleform@@SAXPEAV?$SPtr@$$CBVNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@2@_K@Z 0x1424f6c90
// MS2-PIN: ?DestructArray@?$ConstructorMov@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@Scaleform@@SAXPEAV?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@2@_K@Z 0x1424f6cf0
// MS2-PIN: ?DestructArray@?$ConstructorCPP@VValue@GFx@Scaleform@@@Scaleform@@SAXPEAVValue@GFx@2@_K@Z 0x1424f6c20
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@UDynAttrsKey@Object@AS3@GFx@Scaleform@@VValue@345@UDynAttrsKeyHashFunctor@2345@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@UDynAttrsKey@Object@AS3@GFx@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@UDynAttrsKey@Object@AS3@GFx@Scaleform@@VValue@345@UDynAttrsKeyHashFunctor@2345@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1424eeff0
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@UKey@?$AbcMultinameHash@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@AS3@GFx@Scaleform@@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@345@V?$FixedSizeHash@UKey@?$AbcMultinameHash@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@AS3@GFx@Scaleform@@@5@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@UKey@?$AbcMultinameHash@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@AS3@GFx@Scaleform@@$0BFE@@2@V?$HashsetCachedNodeEntry@U?$HashNode@UKey@?$AbcMultinameHash@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@AS3@GFx@Scaleform@@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@345@V?$FixedSizeHash@UKey@?$AbcMultinameHash@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@AS3@GFx@Scaleform@@@5@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1424ef040
// MS2-PIN: ??1?$HashSetBase@U?$HashNode@UKey@?$AbcMultinameHash@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@AS3@GFx@Scaleform@@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@345@V?$FixedSizeHash@UKey@?$AbcMultinameHash@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@AS3@GFx@Scaleform@@@5@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@UKey@?$AbcMultinameHash@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@AS3@GFx@Scaleform@@$0BFE@@2@V?$HashsetCachedNodeEntry@U?$HashNode@UKey@?$AbcMultinameHash@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@AS3@GFx@Scaleform@@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@345@V?$FixedSizeHash@UKey@?$AbcMultinameHash@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@AS3@GFx@Scaleform@@@5@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAA@XZ 0x1424ef5b0
// MS2-PIN: ?ClearAndRelease@?$ArrayPagedBase@PEBV?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@$09$04U?$AllocatorPagedLH_POD@PEBV?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@$01@4@@Scaleform@@QEAAXXZ 0x1424efab0
// MS2-PIN: ?Clear@?$HashSetBase@U?$HashNode@PEAVObject@AS2@GFx@Scaleform@@PEAV1234@V?$IdentityHash@PEAVObject@AS2@GFx@Scaleform@@@4@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorGH@PEAVObject@AS2@GFx@Scaleform@@$01@2@V?$HashsetNodeEntry@U?$HashNode@PEAVObject@AS2@GFx@Scaleform@@PEAV1234@V?$IdentityHash@PEAVObject@AS2@GFx@Scaleform@@@4@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXXZ 0x1424ef320
// MS2-PIN: ?Convert2Number@Value@AS3@GFx@Scaleform@@QEBA?AVCheckResult@234@AEAN@Z 0x1424f0f60
// MS2-PIN: ??_7InitStruct@String@Scaleform@@6B@ 0x14313f358

// ==== pdata-less vftable slots of the AVM display objects (sfr21) ====
namespace Scaleform { namespace GFx { namespace AS3 {

// @0x1424efdf0
void AvmDisplayObjContainer::CloneInternalData(const InteractiveObject*)
{
}

// @0x1424efe10
void AvmSprite::CloneInternalData(const InteractiveObject*)
{
}

// @0x1424f1f60
void AvmDisplayObjContainer::CopyPhysicalProperties(const InteractiveObject*)
{
}

// @0x1424fe600
void AvmSprite::ExecuteFrame0Events()
{
}

// @0x142506ea0
const char* AvmDisplayObjContainer::GetAbsolutePath(String* ppath) const
{
    return AvmInteractiveObj::GetAbsolutePath(ppath);
}

// @0x142508520
unsigned AvmDisplayObjContainer::GetCursorType() const
{
    return 0;
}

}}} // namespace Scaleform::GFx::AS3

static inline Scaleform::UPInt Sfr21AccRd(Scaleform::UPInt base, Scaleform::UPInt off) { return *reinterpret_cast<const Scaleform::UPInt*>(base + off); }

// MS2-FUNCTIONAL: empty vftable leaf (ret)
// @0x1424efde0
void FUN_1424efde0(Scaleform::UPInt) {}
// MS2-FUNCTIONAL: empty vftable leaf (ret)
// @0x1424efe20
void FUN_1424efe20(Scaleform::UPInt) {}
// MS2-FUNCTIONAL: empty vftable leaf (ret)
// @0x1424f1f50
void FUN_1424f1f50(Scaleform::UPInt) {}
// MS2-FUNCTIONAL: empty vftable leaf (ret)
// @0x1424f1f80
void FUN_1424f1f80(Scaleform::UPInt) {}


// MS2-FUNCTIONAL: vftable leaf returning 0
// @0x142502cf0
Scaleform::UPInt FUN_142502cf0(Scaleform::UPInt) { return 0; }
// MS2-FUNCTIONAL: vftable leaf returning 0
// @0x142507b30
Scaleform::UPInt FUN_142507b30(Scaleform::UPInt) { return 0; }
// MS2-FUNCTIONAL: vftable leaf returning 0
// @0x142508550
unsigned FUN_142508550(Scaleform::UPInt) { return 0; }

// AvmButton / AvmTextField come from the SDK MI layout (SF_AS3_AVMBUTTON_MODEL), as in sfr_as3_18. Copy-constructing
// them stores the vptrs, so cl emits their vftables and with them its own adjustor thunks (sub rcx,N; jmp member),
// which are the exe ones in this range. The thunk targets stay the leaves above at their exe VAs.
namespace Scaleform { namespace GFx { namespace AS3 {
void Sfr17EmitAvmVftables(void* p, const AvmButton* pbtn, void* q, const AvmTextField* ptxt)
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
// MS2-PIN: ?CloneInternalData@AvmButton@AS3@GFx@Scaleform@@WBA@EAAXPEBVInteractiveObject@34@@Z 0x1424efde4
// MS2-PIN: ?CloneInternalData@AvmTextField@AS3@GFx@Scaleform@@WBA@EAAXPEBVInteractiveObject@34@@Z 0x1424efe24
// MS2-PIN: ?CopyPhysicalProperties@AvmButton@AS3@GFx@Scaleform@@WBA@EAAXPEBVInteractiveObject@34@@Z 0x1424f1f54
// MS2-PIN: ?CopyPhysicalProperties@AvmTextField@AS3@GFx@Scaleform@@WBA@EAAXPEBVInteractiveObject@34@@Z 0x1424f1f84
// MS2-PIN: ?GetAbsolutePath@AvmButton@AS3@GFx@Scaleform@@WDA@EBAPEBDPEAVString@4@@Z 0x142506df8
// MS2-PIN: ?GetAbsolutePath@AvmButton@AS3@GFx@Scaleform@@WEA@EBAPEBDPEAVString@4@@Z 0x142506e04
// MS2-PIN: ?GetAbsolutePath@AvmTextField@AS3@GFx@Scaleform@@WDA@EBAPEBDPEAVString@4@@Z 0x142506ed8
// MS2-PIN: ?GetAbsolutePath@AvmTextField@AS3@GFx@Scaleform@@WEA@EBAPEBDPEAVString@4@@Z 0x142506ee4
// MS2-PIN: ?GetCursorType@AvmButton@AS3@GFx@Scaleform@@WBA@EBAIXZ 0x142508514
// MS2-PIN: ?GetCursorType@AvmTextField@AS3@GFx@Scaleform@@WBA@EBAIXZ 0x142508554

// Queues the object's +0x10 owner's +0x30 counted reference on the +0x40 VM's collector (+0x20).
// MS2-FUNCTIONAL: raw-offset vftable slot
// @0x1425046d0
void FUN_1425046d0(Scaleform::UPInt self)
{
    Scaleform::GFx::AS3::Sfr33CollectorQueue(reinterpret_cast<Scaleform::UByte*>(Sfr21AccRd(Sfr21AccRd(self, 0x40), 0x20)),
        reinterpret_cast<Scaleform::RefCountImpl*>(Sfr21AccRd(Sfr21AccRd(self, 0x10), 0x30)));
}

// AvmBitmap::ForceShutdown: drops the loader info of the AS3 object of its AvmDisplayObj part (+0x90).
// @0x1425047c0
void Scaleform::GFx::AS3::AvmBitmap::ForceShutdown()
{
    const Scaleform::GFx::AS3::AvmDisplayObj& avm = *this;
    if (Scaleform::GFx::AS3::Sfr33HasAS3Obj(&avm))
        avm.GetAS3Obj()->SetLoaderInfo(static_cast<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo*>(NULL));
}

// MS2-FUNCTIONAL: the exe returns its .rdata copy
// @0x142505e00
const char* FUN_142505e00(Scaleform::UPInt) { return "NamespaceSet"; }

// MS2-FUNCTIONAL: tail call into AvmInteractiveObj::GetAbsolutePath
// @0x142506df0
const char* FUN_142506df0(Scaleform::UPInt self, Scaleform::String* ppath)
{
    return reinterpret_cast<const Scaleform::GFx::AS3::AvmInteractiveObj*>(self)
        ->Scaleform::GFx::AS3::AvmInteractiveObj::GetAbsolutePath(ppath);
}

// MS2-FUNCTIONAL: tail call into AvmInteractiveObj::GetAbsolutePath
// @0x142506ed0
const char* FUN_142506ed0(Scaleform::UPInt self, Scaleform::String* ppath)
{
    return reinterpret_cast<const Scaleform::GFx::AS3::AvmInteractiveObj*>(self)
        ->Scaleform::GFx::AS3::AvmInteractiveObj::GetAbsolutePath(ppath);
}

// ShapeObject::GetCharacterDef: the shape definition (pDef, +0xc0).
// @0x142507b70
Scaleform::GFx::CharacterDef* Scaleform::GFx::AS3::ShapeObject::GetCharacterDef() const { return pDef; }

// The enabled bit (Mask_Enabled, 0x10) of the AVM object's display object (+0x18 back from the AVM base), as 0 or 1.
// MS2-FUNCTIONAL: the exe zero-extends the shifted byte before the mask (movzx; and eax,1)
// @0x142508500
unsigned FUN_142508500(Scaleform::UPInt self)
{
    return static_cast<Scaleform::UByte>((*reinterpret_cast<Scaleform::GFx::InteractiveObject* const*>(self - 0x18))->Flags >> 4) & 1;
}

// MS2-FUNCTIONAL: the exe returns its .rdata copy
// @0x1425088f0
const char* FUN_1425088f0(Scaleform::UPInt) { return "flash.display.Bitmap"; }
// MS2-FUNCTIONAL: the exe returns its .rdata copy
// @0x142508900
const char* FUN_142508900(Scaleform::UPInt) { return "flash.display.SimpleButton"; }
// MS2-FUNCTIONAL: the exe returns its .rdata copy
// @0x142508980
const char* FUN_142508980(Scaleform::UPInt) { return "flash.text.TextField"; }
// MS2-FUNCTIONAL: the exe returns its .rdata copy
// @0x142508990
const char* FUN_142508990(Scaleform::UPInt) { return "flash.display.Shape"; }
