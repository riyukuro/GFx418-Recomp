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
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/gfx_input.h"
#include "ms2/scaleform/include/kernel/sf_autoptr.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_intervaltimer.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
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
// Out of line in the exe (instantiated in sfr_as3_01c).
extern template Scaleform::String Scaleform::AsString<long>(const long&);
extern template Scaleform::String Scaleform::AsString<unsigned long>(const unsigned long&);
#undef GetObject

// The AS3 object's +0x50 counted reference set to p (unrecovered).
void FUN_142446e70(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject* obj, void* p);
void FUN_142502e70(void* pavm, const Scaleform::GFx::EventId& id);   // AvmDisplayObj: fire the event

namespace Scaleform { namespace GFx { namespace AS3 {
// Trace values for the four built-in scalar traits are definitely non-null; user classes may have
// either nullability, which is recorded conservatively by the tracer.
// @0x1424ee980
Value::TraceNullType TR::State::CanBeNull(const InstanceTraits::Traits& traits) const
{
    const UPInt stateRoot = *reinterpret_cast<const UPInt*>(this);
    const UPInt traceContext = *reinterpret_cast<const UPInt*>(stateRoot + 0x20);
    const UPInt vmTraits = *reinterpret_cast<const UPInt*>(traceContext + 0x28);
    const UPInt builtinTraits = *reinterpret_cast<const UPInt*>(vmTraits + 0x20);
    const InstanceTraits::Traits* const arg = &traits;
    if (arg != *reinterpret_cast<const InstanceTraits::Traits* const*>(
                  *reinterpret_cast<const UPInt*>(builtinTraits + 0x220) + 0xc0) &&
        arg != *reinterpret_cast<const InstanceTraits::Traits* const*>(
                  *reinterpret_cast<const UPInt*>(builtinTraits + 0x228) + 0xc0) &&
        arg != *reinterpret_cast<const InstanceTraits::Traits* const*>(
                  *reinterpret_cast<const UPInt*>(builtinTraits + 0x218) + 0xc0) &&
        arg != *reinterpret_cast<const InstanceTraits::Traits* const*>(
                  *reinterpret_cast<const UPInt*>(builtinTraits + 0x210) + 0xc0))
        return Value::NullOrNot;
    return Value::NotNull;
}

// MS2-FUNCTIONAL 0x1424ed8f0: copy and ownership semantics match; the helper-based release/addref changes the call graph.
// @0x1424ed8f0
SF_NOINLINE void Value::Assign(const Value& other)
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

// ---- the AVM parts of the display objects (as3_avm.h) and the movie root's action queues ----

// @0x1424f2400
unsigned AvmDisplayObj::CreateASInstance(bool execute)
{
    if (!pAS3RawPtr && !pAS3CollectiblePtr && CreateASInstanceNoCtor(execute))
        return CallCtor(execute);
    return 0;
}

// MS2-FUNCTIONAL: same two parent lookups; the inlined AVM-part casts compile to a different branch layout.
// @0x142505e50
Instances::fl_display::DisplayObject* AvmDisplayObj::GetAS3Parent() const
{
    if (!ToAvmInteractiveObj(pDispObj->GetParent()))
        return NULL;
    return ToAvmInteractiveObj(pDispObj->GetParent())->GetAS3Obj();
}

// @0x142505ee0
MovieRoot* AvmDisplayObj::GetAS3Root() const
{
    return static_cast<MovieRoot*>(pDispObj->GetASMovieRoot());
}

// MS2-FUNCTIONAL: same three-way class name choice; the String assignments are emitted differently.
// @0x142505f20
String& AvmDisplayObj::GetASClassName(String* className) const
{
    const char* name = pClassName;
    if (!name)
    {
        const String* exportName = pDispObj->GetResourceMovieDef()->GetNameOfExportedResource(ResourceId(pDispObj->Id));
        if (exportName)
        {
            *className = *exportName;
            return *className;
        }
        name = GetDefaultASClassName();
    }
    *className = name;
    return *className;
}

// MS2-FUNCTIONAL: the exe also makes a result-ignored call through vftable slot 4 of the movie root first.
// @0x142506d30
ASVM* AvmDisplayObj::GetAVM()
{
    return GetAS3Root()->pAVM;
}

// MS2-FUNCTIONAL: same path building; the temporary ASString release is inlined differently.
// @0x142506e10
const char* AvmDisplayObj::GetAbsolutePath(String* ppath) const
{
    if (pDispObj->GetParent())
    {
        pDispObj->GetParent()->GetAbsolutePath(ppath);
        ppath->AppendString(".");
        ppath->AppendString(pDispObj->GetName().ToCStr());
    }
    return ppath->ToCStr();
}

// @0x142507550
AvmInteractiveObj* AvmDisplayObj::GetAvmParent() const
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

// MS2-FUNCTIONAL: same AS3-object lookup and call; the null tests are ordered differently.
// @0x142504810
void AvmSprite::ForceShutdown()
{
    Instances::fl_display::DisplayObject* as3obj = GetAS3Obj();
    if (as3obj)
        FUN_142446e70(as3obj, NULL);
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
// MS2-FUNCTIONAL: same bit test, init-action run and bit set; the Ptr<Sprite> addref/release is laid out differently.
// @0x1424fee10
void AvmSprite::ExecuteInitActionFrameTags(unsigned frame)
{
    const unsigned byteIndex = frame >> 3;
    if (InitActionsExecuted[byteIndex] & (1 << (frame & 7)))
        return;
    Ptr<Sprite> spr = GetSprite();
    TimelineDef::Frame initActions;
    if (spr->pDef->GetInitActions(&initActions, frame) && initActions.GetTagCount())
    {
        for (unsigned i = 0; i < initActions.GetTagCount(); ++i)
            initActions.GetTag(i)->Execute(GetSprite());
        InitActionsExecuted[byteIndex] |= UByte(1 << (frame & 7));
    }
}

// The hand cursor in button mode.
// @0x142508540
unsigned AvmSprite::GetCursorType() const
{
    return SprFlags & Flag_ButtonMode;
}

// MS2-FUNCTIONAL: same queue walk; the iterator construction and free-list release are scheduled differently.
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

// Creates the timeline children of frame 0 once: the sprite joins the playlist when its parent is on it, gets its
// load event and runs the init actions of frame 0.
// MS2-FUNCTIONAL: same playlist, load-event and init-action steps; the parent is reloaded and the AvmSprite this
// adjustment differs.
// @0x1424f3320
void AvmSprite::CreateChildren()
{
    if (SprFlags & Flag_ChildrenCreated)
        return;
    Sprite* spr = GetSprite();
    if (!spr->IsInPlayList() && spr->GetParent() && spr->GetParent()->IsInPlayList())
    {
        if (!spr->GetParent())
            spr->AddToPlayList();
        else
            GetAvmParent()->InsertChildToPlayList(spr);
        spr->ModifyOptimizedPlayList();
    }
    if (!(spr->Flags & Sprite::Flags_OnEventLoadCalled))
        spr->DefaultOnEventLoad();
    if (spr->HasAvmObject())
        spr->GetAvmSprite()->ExecuteInitActionFrameTags(0);
    SprFlags |= Flag_ChildrenCreated;
}

// ToInt32 of ECMA-262: NaN, infinities and zeros give 0, everything else is truncated modulo 2^32.
// MS2-FUNCTIONAL: same NaN/zero tests, floor/fmod reduction and wrap; xmm7 holds 0.0 across the calls in the exe.
// @0x1424f1d60
SInt32 ConvertDouble2SInt32(Double v)
{
    if (NumberUtil::IsNaNOrInfinity(v) || NumberUtil::IsPOSITIVE_ZERO(v) || NumberUtil::IsNEGATIVE_ZERO(v))
        return 0;
    const bool neg = v < 0.0;
    Double d = v;
    if (neg)
        d = -d;
    d = floor(d);
    if (d > 4294967295.0)
        d = fmod(d, 4294967296.0);
    if (d >= 2147483648.0)
    {
        const int low = int(d - 2147483648.0);
        if (neg)
            return SInt32(0x80000000u - unsigned(low));
        return SInt32(unsigned(low) + 0x80000000u);
    }
    if (neg)
        d = -d;
    return int(d);
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

// MS2-FUNCTIONAL: chain walk and namespace compares laid out differently
// @0x142502b20
AbsoluteIndex Slots::FindSlotInfoIndex(const ASString& k, const Instances::Namespace& ns) const
{
    if (const UInt32* values = FindSlotValues(k))
    {
        SPInt ind = *values;
        do
        {
            const Instances::Namespace& sns = *GetSlotInfo(AbsoluteIndex(ind)).pNs;
            if (sns.GetKind() == ns.GetKind())
            {
                if (sns.GetKind() == Abc::NS_Protected)
                    return AbsoluteIndex(ind);
                if (sns.GetKind() == Abc::NS_Private ? &sns == &ns
                                                      : sns.GetUri().GetNode() == ns.GetUri().GetNode())
                    return AbsoluteIndex(ind);
            }
            if (static_cast<UPInt>(ind) < FirstOwnSlotNum)
                ind = Parent->GetPrevSlotIndex(ind);
            else
                ind = VArray[static_cast<UPInt>(ind) - FirstOwnSlotNum].Prev;
        } while (ind >= 0);
    }
    return AbsoluteIndex(-1);
}

// @0x1425009e0
SlotInfo& Slots::FindAddOwnSlotInfo(const ASString& k, const SlotInfo& v, AbsoluteIndex& ind)
{
    ind = FindSlotInfoIndex(k, *v.pNs);
    if (!ind.IsValid())
        ind = Add(k, v);
    return GetOwnSlotInfo(ind);
}

// @0x142502dc0
const SPInt* SlotContainerType::FindValues(const ASString& k) const
{
    return KVHashSet.Get(k.GetNode());
}

// MS2-FUNCTIONAL: the hash Find inlined (the exe calls it)
// @0x1425008e0
AbsoluteIndex SlotContainerType::FindAdd(const ASString& k, const SlotInfo& v)
{
    SetType::Iterator it = KVHashSet.Find(k.GetNode());
    if (!it.IsEnd())
        return AbsoluteIndex(it->Second);
    return Add(k, v);
}

// MS2-FUNCTIONAL: FindValues inlined (the exe calls it) and the hash probe split into chunks
// @0x142500dd0
const SlotInfo* FindDynamicSlot(const SlotContainerType& c, const ASString& k, const Instances::Namespace& ns)
{
    const SPInt* values = c.FindValues(k);
    if (values)
    {
        for (SPInt ind = *values; ind >= 0; ind = c.VArray[static_cast<UInt32>(ind)].Prev)
        {
            const SlotInfo& si = c.VArray[static_cast<UInt32>(ind)].Value;
            if (si.pNs->GetUri().GetNode() == ns.GetUri().GetNode() && si.pNs->GetKind() == ns.GetKind())
                return &si;
        }
    }
    return NULL;
}

// Visits the collectable a value holds.
// MS2-FUNCTIONAL: the member offset is selected before the add
// @0x142504530
void ForEachChild_GC_Internal(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const Value& v,
                              ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    typedef void (*GcOpWithOwner)(RefCountCollector<StatMV_ActionScript_Mem>*, const ASRefCountBaseType**,
                                  const ASRefCountBaseType&);
    const char* p = reinterpret_cast<const char*>(&v);
    const unsigned kind = v.GetKind();
    if (kind < Value::kNamespace)
        return;
    if (kind <= Value::kThunkFunction)
        p += 0x10;          // the object
    else if (kind <= Value::kVTableIndClosure)
        p += 0x18;          // a closure's object
    else
        return;
    const ASRefCountBaseType* const* pchild = reinterpret_cast<const ASRefCountBaseType* const*>(p);
    if (*pchild)
        reinterpret_cast<GcOpWithOwner>(op)(prcc, const_cast<const ASRefCountBaseType**>(pchild), owner);
}

SF_INLINE void ForEachChild_GC(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const Value& v,
                               ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    if (v.IsGarbageCollectable() && !v.IsWeakRef())
        ForEachChild_GC_Internal(prcc, v, op, owner);
}

// MS2-FUNCTIONAL: the inlined value visits laid out differently
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
        AS3::ForEachChild_GC(prcc, (*reinterpret_cast<Value* const*>(reinterpret_cast<const char*>(&obj) + 0xa8))[ValueInd],
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

// MS2-FUNCTIONAL: the parent-slot test of the inlined GetSlotInfo is not materialised as a bool
// @0x142503ce0
void Traits::ForEachChild_GC(Collector* prcc, const Object& obj, GcOp op) const
{
    const SPInt size = GetSlotInfoNum();
    for (SPInt i = 0; i < size; ++i)
        GetSlotInfo(AbsoluteIndex(i)).ForEachChild_GC(prcc, obj, op);
}

// MS2-FUNCTIONAL: the parent-slot test of the inlined GetSlotInfo is not materialised as a bool
// MS2-FUNCTIONAL: the tag bit of the inlined GetAS3Obj is cleared with a cmov, not a branch
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

// MS2-FUNCTIONAL: the tag bit of the inlined GetAS3Obj is cleared with a cmov, not a branch
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
Class& VM::GetClassVector() const
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

// @0x142504580
void Traits::ForEachChild_GC_Slot(Collector* prcc, const Object& obj, GcOp op) const
{
    const UPInt size = GetSlotInfoNum();
    for (UPInt i = 0; i < size; ++i)
        GetSlotInfo(AbsoluteIndex(i)).ForEachChild_GC(prcc, obj, op);
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
// MS2-FUNCTIONAL 0x142503d90: the inlined value visits are laid out differently; same visits
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
    const UPInt ss = InitScope.GetSize();
    for (UPInt i = 0; i < ss; ++i)
        AS3::ForEachChild_GC(prcc, InitScope[i], op, *this);
}

// Visits the counted pointer at offset off of every used entry of a raw hash table (0x10-byte header: entry
// count, size mask; an entry's first word is its chain link, -2 when empty).
static SF_INLINE void Sfr33GcRawHash(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const void* table, UPInt esize,
                                     UPInt off, ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    typedef void (*GcOpWithOwner)(RefCountCollector<StatMV_ActionScript_Mem>*, const ASRefCountBaseType**,
                                  const ASRefCountBaseType&);
    if (!table)
        return;
    const char* t = static_cast<const char*>(table);
    const UPInt mask = *reinterpret_cast<const UPInt*>(t + 8);
    for (UPInt i = 0; i <= mask; ++i)
    {
        const char* e = t + 0x10 + i * esize;
        if (*reinterpret_cast<const SPInt*>(e) == -2)
            continue;
        const ASRefCountBaseType** pchild = (const ASRefCountBaseType**)(e + off);
        if (*pchild)
            reinterpret_cast<GcOpWithOwner>(op)(prcc, pchild, owner);
    }
}

// VMAbcFile::ForEachChild_GC: the interned namespaces, the absolute objects, the namespace sets, the global
// objects, the child files, the activation and function traits caches and the loaded classes.
// MS2-FUNCTIONAL 0x142503ff0: the exe inlines the hash iterators; same visits
// @0x142503ff0
void VMAbcFile::ForEachChild_GC(Collector* prcc, GcOp op) const
{
    Sfr33GcRawHash(prcc, *reinterpret_cast<void* const*>(&IntNamespaces), 0x28, 0x20, op, *this);
    Sfr33GcRawHash(prcc, AbsObjectsTable, 0x18, 0x10, op, *this);
    for (UPInt i = 0, n = IntNamespaceSets.GetSize(); i < n; ++i)
        Sfr33GcPtr(prcc, IntNamespaceSets[i], op, *this);
    Sfr33GcRawHash(prcc, GlobalObjectsTable, 0x18, 0x10, op, *this);
    for (UPInt i = 0, n = Children.GetSize(); i < n; ++i)
        Sfr33GcPtr(prcc, Children[i], op, *this);
    Sfr33GcRawHash(prcc, ActivationTraitsCacheTable, 0x20, 0x18, op, *this);
    Sfr33GcRawHash(prcc, FunctionTraitsCacheTable, 0x20, 0x18, op, *this);
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

    ChainsType Chains;
};

// Fires the event code on every live object of its chain; dead entries are dropped on the way.
// MS2-FUNCTIONAL 0x1424f71b0: the exe tests the weak pointer before taking the reference; same results
// @0x1424f71b0
void EventChains::Dispatch(EventId::IdCode code)
{
    AutoPtr<ChainType>* pchain = Chains.Get(code);
    if (!pchain)
        return;
    ChainType& chain = **pchain;
    for (UPInt i = 0; i < chain.GetSize();)
    {
        Ptr<DisplayObject> ch = chain[i];
        if (!ch)
        {
            chain.RemoveAt(i);
            continue;
        }
        FUN_142502e70(ToAvmDisplayObj(ch), EventId(code));
        ++i;
    }
}

// Object::ForEachChild_GC: the dynamic property values, the values bound in the traits' slots, then the traits.
// MS2-FUNCTIONAL 0x1425038d0: the exe walks the hash table and the traits' slots inline; same visits
// @0x1425038d0
void Object::ForEachChild_GC(Collector* prcc, GcOp op) const
{
    for (DynAttrsType::ConstIterator it = DynAttrs.Begin(); !it.IsEnd(); ++it)
        AS3::ForEachChild_GC(prcc, it->Second, op, *this);
    if (pTraits)
        pTraits->ForEachChild_GC_Slot(prcc, *this, op);
    if (pTraits)
    {
        typedef void (*GcOpWithOwner)(RefCountCollector<StatMV_ActionScript_Mem>*, const ASRefCountBaseType**,
                                      const ASRefCountBaseType&);
        reinterpret_cast<GcOpWithOwner>(op)(
            prcc, const_cast<const ASRefCountBaseType**>(reinterpret_cast<ASRefCountBaseType**>(pTraits.GetRawPtr())),
            *this);
    }
}
}}}

// ---- sfr33: MovieRoot / Stage helpers ----
// AS3 Event class's object factory (unrecovered).
void FUN_142466be0(void* eventClass, void* ret, const Scaleform::GFx::ASString& type, bool bubbles, bool cancelable);
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
    FUN_142466be0(*reinterpret_cast<void* const*>(reinterpret_cast<const UByte*>(self->pAVM) + 0x390), ret, type,
                  bubbles, cancelable);
    return ret;
}
}}}

// VM: runs the queued class constructors (unrecovered).
// the AS3 ObjectInterface (AS3ValueObjectInterface) vftable
extern "C" const void* DAT_14317eff8;

extern "C" const void* DAT_14317ef38[];      // UserDefinedFunction vftable
int FUN_140ccaae0(const char* fmt, ...);   // log printf
void FUN_1423ed140(void* self, Scaleform::GFx::AS3::InstanceTraits::Traits* t);   // FunctionBase(InstanceTraits::Traits&)

namespace Scaleform { namespace GFx { namespace AS3 {

// The timeline sprite shared by CreateMovieClip and CreateSprite: the AS support's character of type ctype.
static inline Sprite* Sfr33CreateTimelineSprite(MovieRoot* self, CharacterDef* pdef, MovieDefImpl* pdefImpl,
                                                InteractiveObject* parent, ResourceId id,
                                                CharacterDef::CharacterDefType ctype)
{
    ASSupport* psupport = self->pASSupport;
    CharacterCreateInfo ccinfo = { pdef, pdefImpl, NULL };
    return static_cast<Sprite*>(static_cast<DisplayObjectBase*>(
        psupport->CreateCharacterInstance(self->GetMovieImpl(), ccinfo, parent, id, ctype)));
}

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
// MS2-FUNCTIONAL 0x1424f38a0: the MovieRoot and ASSupport pointers trade registers (r10/rcx); same calls and stores.
// @0x1424f38a0
Sprite* Sfr33MovieRoot::CreateMovieClip(CharacterDef* pdef, MovieDefImpl* pdefImpl, InteractiveObject* parent,
                                        ResourceId id, bool loadedSeparately)
{
    Sprite* pspr = Sfr33CreateTimelineSprite(Root(), pdef, pdefImpl, parent, id, static_cast<CharacterDef::CharacterDefType>(3));
    pspr->SetLoadedSeparately(loadedSeparately);
    *reinterpret_cast<UInt16*>(reinterpret_cast<UByte*>(pspr) + 0x6a) |= 0x800;
    return pspr;
}

// MovieRoot::CreateSprite (virtual)
// MS2-FUNCTIONAL 0x1424f3f90: the MovieRoot and ASSupport pointers trade registers (r10/rcx); same calls and stores.
// @0x1424f3f90
Sprite* Sfr33MovieRoot::CreateSprite(CharacterDef* pdef, MovieDefImpl* pdefImpl, InteractiveObject* parent,
                                     ResourceId id, bool loadedSeparately)
{
    Sprite* pspr = Sfr33CreateTimelineSprite(Root(), pdef, pdefImpl, parent, id, static_cast<CharacterDef::CharacterDefType>(9));
    pspr->SetLoadedSeparately(loadedSeparately);
    return pspr;
}

// MovieRoot::CreateFunction (virtual): wraps the handler in a user-defined function object (0x50 bytes: FunctionBase,
// then +0x40 the handler, +0x48 the user data) and returns it as a GFx value.
// MS2-FUNCTIONAL 0x1424f3780: the object is built on the exe's UserDefinedFunction vftable, not a class of ours.
// @0x1424f3780
void Sfr33MovieRoot::CreateFunction(GFx::Value* pvalue, FunctionHandler* pfc, void* puserData)
{
    ASVM* pavm = *reinterpret_cast<ASVM**>(reinterpret_cast<UByte*>(this) + 0x48);
    UByte* pf = static_cast<UByte*>(pavm->GetMemoryHeap()->Alloc(0x50));
    if (pf)
    {
        FUN_1423ed140(pf, &pavm->GetClassTraitsFunction().GetInstanceTraits());
        *reinterpret_cast<const void**>(pf) = DAT_14317ef38;
        *reinterpret_cast<FunctionHandler**>(pf + 0x40) = NULL;
        if (pfc)
        {
            reinterpret_cast<RefCountImpl*>(pfc)->AddRef();
            if (RefCountImpl* old = *reinterpret_cast<RefCountImpl**>(pf + 0x40))
                old->Release();
        }
        *reinterpret_cast<FunctionHandler**>(pf + 0x40) = pfc;
        *reinterpret_cast<void**>(pf + 0x48) = puserData;
    }
    Value asval;
    asval.PickUnsafe(reinterpret_cast<Instances::FunctionBase*>(pf));
    Root()->ASValue2GFxValue(asval, pvalue);
}

// MovieRoot::CreateObject (virtual): a new instance of the global class className ("Object" when none), constructed
// with the host values pargs; a pending exception is printed and dropped. Up to 10 arguments live on the stack.
// MS2-FUNCTIONAL 0x1424f39c0: our Value code builds and frees the arguments; the frame test of VM::Construct is inline
// @0x1424f39c0
void Sfr33MovieRoot::CreateObject(GFx::Value* pvalue, const char* className, const GFx::Value* pargs, unsigned nargs)
{
    UByte buf[0x140 + 0x50];
    Value* args = nargs < 11 ? reinterpret_cast<Value*>(buf)
                             : static_cast<Value*>(Memory::AllocAutoHeap(this, UPInt(nargs) << 5));
    for (unsigned i = 0; i < nargs; ++i)
    {
        Value* pv = new (&args[i]) Value();
        Root()->GFxValue2ASValue(pargs[i], pv);
    }
    Value result;
    VM* pvm = *reinterpret_cast<VM**>(reinterpret_cast<UByte*>(this) + 0x48);
    // VM::Construct 0x1424f0750 as the exe has it returns whether a constructor frame was queued (+0x78 grew)
    const UPInt frames = pvm->Unk070[1];
    pvm->Construct(className ? className : "Object", result, nargs, args, false);
    const bool ok = !pvm->HandleException && pvm->Unk070[1] > frames;
    pvm = *reinterpret_cast<VM**>(reinterpret_cast<UByte*>(this) + 0x48);
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

// ShapeObject::CreateRenderNode (virtual): the tree shape of the shape's definition, bound to its movie.
// ShapeObject is opaque (as3_avm.h); a member of a stand-in keeps the virtual's register use.
struct Sfr33ShapeObject
{
    Ptr<Render::TreeNode> CreateRenderNode(Render::Context& context);
};
// @0x1424f3f40
Ptr<Render::TreeNode> Sfr33ShapeObject::CreateRenderNode(Render::Context& context)
{
    UByte* self = reinterpret_cast<UByte*>(this);
    const ShapeBaseCharacterDef* pdef = *reinterpret_cast<ShapeBaseCharacterDef* const*>(self + 0xc0);
    typedef MovieDefImpl* (*GetResourceMovieDefFn)(UByte*);
    MovieDefImpl* pdefImpl = (*reinterpret_cast<GetResourceMovieDefFn const* const*>(self))[60](self);
    return pdef->CreateTreeShape(context, pdefImpl);
}

// @0x1424f4a40
CheckResult Object::DeleteProperty(const Multiname& prop_name)
{
    if (GetTraits().IsDynamic())
        return DeleteDynamicSlotValuePair(prop_name);
    return false;
}
}}}

bool FUN_142442c30(const void* name, void* pccinfo, void* pdefImpl);

namespace Scaleform { namespace GFx { namespace AS3 {

// Stops the frame counter, clears the display list (+0xd8), shuts the root movie clip down and drops it, then
// shuts the container down.
// MS2-FUNCTIONAL 0x142504860: the null-root path jumps past the release (exe re-tests +0x110); same calls/stores.
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

struct Sfr33MovieRootFind
{
    bool FindLibrarySymbolInAllABCs(const void* name, void* pccinfo);
};
// MovieRoot::FindLibrarySymbolInAllABCs: true when any loaded movie's ABCs define the library symbol.
// @0x142501a80
bool Sfr33MovieRootFind::FindLibrarySymbolInAllABCs(const void* name, void* pccinfo)
{
    MovieRoot* self = reinterpret_cast<MovieRoot*>(this);
    MovieDefRootNode* p = self->pMovieImpl->RootMovieDefNodes.pNext;
    for (;;)
    {
        MovieDefRootNodeLinks* proot = &self->pMovieImpl->RootMovieDefNodes;
        if (p == static_cast<MovieDefRootNode*>(proot))
            return false;
        if (FUN_142442c30(name, pccinfo, p->pDefImpl))
            return true;
        p = p->pNext;
    }
}
}}}

Scaleform::GFx::AS3::ClassTraits::Traits** FUN_142414ac0(Scaleform::GFx::AS3::TClassTraitsCache* self, const Scaleform::GFx::ASString& name,
                                                       const Scaleform::GFx::AS3::Instances::Namespace& ns);   // TClassTraitsCache::Get(name, ns)
void** FUN_142508330(void* self);
Scaleform::GFx::AS3::ClassTraits::Traits* FUN_142415520(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP* self, const Scaleform::GFx::ASString& name,
                                                     const Scaleform::GFx::AS3::Instances::Namespace& ns);   // GlobalObjectCPP: builtin class traits by name
const Scaleform::GFx::AS3::ClassTraits::Traits* FUN_142525270(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Multiname& mn);  // VM::Resolve2ClassTraits
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

// A copy of the name (+0x18) of the object at +0x28 (an unidentified by-value String virtual).
struct Sfr33NamedOwner
{
    String GetOwnerName() const;
};
// @0x142505dd0
String Sfr33NamedOwner::GetOwnerName() const
{
    const UByte* powner = *reinterpret_cast<const UByte* const*>(reinterpret_cast<const UByte*>(this) + 0x28);
    return *reinterpret_cast<const String*>(powner + 0x18);
}

// "Vector.<T>" resolves T and applies it to Vector; any other name is looked up as a global class.
// MS2-FUNCTIONAL 0x142507be0: the exe keeps the prefix length in a register across the trims; same results
// @0x142507be0
Class* VM::GetClass(const StringDataPtr& gname)
{
    if (gname.IsEmpty())
        return NULL;
    const StringDataPtr& prefix = DAT_143a2dd50;
    if (gname.GetSize() > prefix.GetSize())
    {
        UPInt cut = gname.GetSize() - prefix.GetSize();
        if (gname.GetSize() < cut)
            cut = gname.GetSize();
        if (StringDataPtr(gname.ToCStr(), gname.GetSize() - cut) == prefix)
        {
            const SPInt pos = gname.FindLastChar('>');
            if (pos <= 0)
                return NULL;
            const StringDataPtr rest = gname.GetTrimLeft(prefix.GetSize());
            UPInt rcut = gname.GetSize() - pos;
            if (rest.GetSize() < rcut)
                rcut = rest.GetSize();
            Class* elem = GetClass(StringDataPtr(rest.ToCStr(), rest.GetSize() - rcut));
            if (elem == NULL)
                return NULL;
            const Value arg(elem);
            return &GetClassVector().ApplyTypeArgs(1, &arg);
        }
    }

    Class* result = NULL;
    Multiname mn(*this, gname);
    ClassTraits::Traits* ctr = const_cast<ClassTraits::Traits*>(FUN_142525270(*this, mn));
    if (ctr)
    {
        ctr->InitOnDemand();
        if (!IsException())
            result = &ctr->GetInstanceTraits().GetConstructor();
    }
    return result;
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
// MS2-FUNCTIONAL 0x142505aa0: the exe inlines the hash probe of each namespace; same results
// @0x142505aa0
ClassTraits::Traits** Sfr33ClassTraitsCacheGet(TClassTraitsCache* self, const Multiname& mn)
{
    if ((static_cast<UInt32>(mn.Kind) & 3) == Abc::MNF_NS_Multi)
    {
        const NamespaceSet& nss = static_cast<const NamespaceSet&>(*mn.Obj);
        const ArrayLH<SPtr<Instances::Namespace> >& nsa = nss.GetNamespaces();
        for (UPInt i = 0; i < nsa.GetSize(); ++i)
        {
            ClassTraits::Traits** p = self->Entries.Get(TClassTraitsCache::Key(mn.Name.AsString(), nsa[i].GetPtr()));
            if (p)
                return p;
        }
        return NULL;
    }
    return FUN_142414ac0(self, mn.Name.AsString(), static_cast<const Instances::Namespace&>(*mn.Obj));
}

// The class traits mn names. A namespace set takes the first namespace with cached or builtin class traits
// (a builtin hit is cached); a single namespace goes through VM::Resolve2ClassTraits.
// MS2-FUNCTIONAL 0x142500a60: the exe inlines the cache add; same results
// @0x142500a60
ClassTraits::Traits* Sfr33ResolveMnClassTraits(VM* vm, const Multiname& mn)
{
    if ((static_cast<UInt32>(mn.Kind) & 3) > Abc::MNF_NS_Runtime)
    {
        const NamespaceSet& nss = static_cast<const NamespaceSet&>(*mn.Obj);
        const ArrayLH<SPtr<Instances::Namespace> >& nsa = nss.GetNamespaces();
        ClassTraits::Traits* ct = NULL;
        for (UPInt i = 0; ct == NULL && i < nsa.GetSize(); ++i)
        {
            ASString name = mn.Name.AsString();
            const Instances::Namespace& ns = *nsa[i];
            ClassTraits::Traits** found = FUN_142414ac0(&vm->ClassTraitsSet, name, ns);
            ct = found != NULL ? *found : NULL;
            if (ct == NULL)
            {
                ct = FUN_142415520(vm->GlobalObject.GetPtr(), name, ns);
                if (ct != NULL)
                    vm->ClassTraitsSet.Add(name, ns, ct);
            }
        }
        return ct;
    }
    return const_cast<ClassTraits::Traits*>(FUN_142525270(*vm, mn));
}

// The value at +0x10, made by FUN_142508330 on first use.
// @0x142507a40
void* Sfr33CacheValue(UByte* self)
{
    void*& pvalue = *reinterpret_cast<void**>(self + 0x10);
    if (pvalue == NULL)
        pvalue = *FUN_142508330(self);
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
UPInt Sfr33Slot9Or38(const UByte* self)
{
    void** p = *reinterpret_cast<void** const*>(self + 0x88);
    if (p)
    {
        typedef UPInt (*Fn)(void*);
        return reinterpret_cast<Fn*>(*p)[9](p);
    }
    return 0x38;
}
}}}

void FUN_1425038d0(void* self, void* prcc, void (*op)(void*, void*, void*));
void FUN_142503d90(void* self, void* prcc, void (*op)(void*, void*, void*));

namespace Scaleform { namespace GFx { namespace AS3 {

// Tracer::CanBeNull: values of the int, uint, Number and Boolean instance traits are never null.
// @0x1424eea80
Value::TraceNullType Sfr33TracerCanBeNull(const UByte* self, const InstanceTraits::Traits* tr)
{
    const UByte* pfile = *reinterpret_cast<const UByte* const*>(*reinterpret_cast<const UByte* const*>(self + 0x20) + 0x28);
    const VM& vm = **reinterpret_cast<VM* const*>(pfile + 0x20);
    if (tr == &vm.TraitsInt->GetInstanceTraits() || tr == &vm.TraitsUint->GetInstanceTraits() ||
        tr == &vm.TraitsNumber->GetInstanceTraits() || tr == &vm.TraitsBoolean->GetInstanceTraits())
        return Value::NotNull;
    return Value::NullOrNot;
}

typedef void (*Sfr33GcOp)(void* prcc, void* pchild, void* powner);

// ForEachChild_GC (virtual) of an object with collectable children at +0x38 and +0x48.
// @0x142503800
void Sfr33ForEachChildGC_38_48(UByte* self, void* prcc, Sfr33GcOp op)
{
    FUN_1425038d0(self, prcc, op);
    if (*reinterpret_cast<void**>(self + 0x38))
        op(prcc, self + 0x38, self);
    if (*reinterpret_cast<void**>(self + 0x48))
        op(prcc, self + 0x48, self);
}

// Two ForEachChild_GC (virtual) copies of objects with a collectable child at +0xc0.
static inline void Sfr33ForEachChildGC_c0(UByte* self, void* prcc, Sfr33GcOp op)
{
    FUN_142503d90(self, prcc, op);
    void** pchild = reinterpret_cast<void**>(self + 0xc0);
    if (*pchild)
        op(prcc, pchild, self);
}
// @0x142503f50
void Sfr33ForEachChildGC_c0a(UByte* self, void* prcc, Sfr33GcOp op) { Sfr33ForEachChildGC_c0(self, prcc, op); }
// @0x142503fa0
void Sfr33ForEachChildGC_c0b(UByte* self, void* prcc, Sfr33GcOp op) { Sfr33ForEachChildGC_c0(self, prcc, op); }

// A third Traits::GetConstructor copy.
struct Sfr33LazyTraits
{
    void* GetConstructor();
};
// @0x142508460
void* Sfr33LazyTraits::GetConstructor()
{
    void** self = reinterpret_cast<void**>(this);
    void* p = self[0x10];
    if (!p)
    {
        typedef void (*MakeFn)(void*);
        reinterpret_cast<MakeFn*>(*self)[13](self);
        p = self[0x10];
    }
    return p;
}
}}}

namespace Scaleform { namespace GFx { namespace AS3 {

// ForEachChild_GC of an owned value array (+0x00 owner, +0x08 data, +0x10 size).
// MS2-FUNCTIONAL 0x142504460: the exe inlines the value visit with a spare null register (r15) and a cmova guard.
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
void FUN_1423de770(void* self, const Sfr33CollectorEntry& e);
void FUN_1424efab0(void* pages);   // ArrayPagedLH_POD<unsigned,6,64,2> ClearAndRelease

namespace Scaleform { namespace GFx { namespace AS3 {

// Queues p (unless a collection runs, +0xb1), notes the queue's previous size (+0x94) and its high-water mark (+0x90),
// and asks for a collection (+0xb0) when the flags (+0x78) want one per addition.
// MS2-FUNCTIONAL 0x142504630: the high-water max lands in esi (exe copies the count to ecx first); same stores.
// @0x142504630
__declspec(noinline) void Sfr33CollectorQueue(UByte* self, RefCountImpl* p)
{
    if (self[0xb1] > 0)
        return;
    const unsigned count = *reinterpret_cast<unsigned*>(self + 0x18);
    Sfr33CollectorEntry e(p);
    FUN_1423de770(self, e);
    *reinterpret_cast<unsigned*>(self + 0x94) = count;
    *reinterpret_cast<unsigned*>(self + 0x90) = Alg::Max(*reinterpret_cast<unsigned*>(self + 0x90), count);
    *reinterpret_cast<unsigned*>(self + 0x88) = 0;
    if (self[0x78] & 0x10)
        self[0xb0] = 1;
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
        FUN_1424efab0(self + 0x10);
    *reinterpret_cast<unsigned*>(self + 0x8c) = *reinterpret_cast<unsigned*>(self + 0xa8);
    *reinterpret_cast<unsigned*>(self + 0x90) = 0;
}

// @0x1425046f0
void Sfr33CollectorQueueAndReset(UByte* self, RefCountImpl* p)
{
    Sfr33QueueAndResetImpl(self, p);
}
}}}

void FUN_14252ecb0(void* vm, const void* error, const void* classInfo);   // VM: raise the error as an instance of the class
void FUN_14241de40(void* stack, unsigned n);   // ValueStack::PopBack: pops (and releases) the top n values
namespace Scaleform { namespace GFx { namespace AS3 { namespace fl_errors { extern const ClassInfo MemoryErrorCI; } } } }
bool FUN_1425149a0(const Scaleform::GFx::AS3::ClassTraits::Traits& tr, const Scaleform::GFx::AS3::ClassTraits::Traits& other);
const Scaleform::GFx::AS3::Traits& FUN_14250ffc0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v);
Scaleform::UPInt FUN_142525f20(char* buffer, int bufflen, double val);

namespace Scaleform { namespace GFx { namespace AS3 {

// VM::ThrowTypeError, inlined.
static inline void Sfr33ThrowTypeError(VM& vm, const VM::Error& e)
{
    FUN_14252ecb0(&vm, &e, &fl::TypeErrorCI);
}

// Primitives coerce to their own class and to Object (ints also to Number); objects to any class above theirs.
// undefined becomes null; the tracer-only kinds pass through untouched.
SF_INLINE bool Sfr33CoerceClassValue(const ClassTraits::Traits& self, const Value& value, Value& result)
{
    VM& vm = self.GetVM();
    const BuiltinTraitsType tt = self.GetTraitsType();
    const bool toObject = &self == &vm.GetClassTraitsObject();
    switch (value.GetKind())
    {
    case Value::kUndefined:
        result.SetNull();
        break;
    case Value::kInt:
        if (!toObject && tt != Traits_Number && tt != Traits_SInt)
            return false;
        result.SetNumber(value.AsInt());
        break;
    case Value::kUInt:
        if (!toObject && tt != Traits_Number && tt != Traits_UInt)
            return false;
        result.SetNumber(value.AsUInt());
        break;
    case Value::kThunk:
    case Value::kVTableInd:
        if (!toObject && tt != Traits_Function)
            return false;
        result.Assign(value);
        break;
    case Value::kBoolean:
        if (!toObject && tt != Traits_Boolean)
            return false;
        result.Assign(value);
        break;
    case Value::kNumber:
        if (!toObject && tt != Traits_Number)
            return false;
        result.Assign(value);
        break;
    case Value::kString:
        if (!toObject && tt != Traits_String)
            return false;
        result.Assign(value);
        break;
    case Value::kNamespace:
        if (!toObject && tt != Traits_Namespace)
            return false;
        result.Assign(value);
        break;
    case Value::kFunction:
    case Value::kObject:
    case Value::kThunkFunction:
        if (value.GetObject())
        {
            if (!FUN_1425149a0(self, vm.GetClassTraits(value)))
                return false;
        }
        result.Assign(value);
        break;
    case Value::kClass:
        if (!FUN_1425149a0(self, value.AsClass().GetClassTraits()))
            return false;
        result.Assign(value);
        break;
    case Value::kThunkClosure:
    case Value::kVTableIndClosure:
        result.Assign(value);
        break;
    default:
        break;
    }
    return true;
}

// MS2-FUNCTIONAL 0x1424effa0: the exe orders the switch blocks differently; same results
// @0x1424effa0
bool ClassTraits::Traits::Coerce(const Value& value, Value& result) const
{
    return Sfr33CoerceClassValue(*this, value, result);
}

// MS2-FUNCTIONAL 0x1424f01c0: the exe orders the switch blocks differently; same results
// @0x1424f01c0
bool ClassTraits::Traits::CoerceValue(const Value& value, Value& result) const
{
    return Sfr33CoerceClassValue(*this, value, result);
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
// bound slots keep their offsets.
// MS2-FUNCTIONAL 0x1424ee490: the exe ends with a free of an empty local buffer; same results
// @0x1424ee490
void Traits::CalculateMemSize(unsigned parent_size)
{
    MemSize = parent_size;

    unsigned bools = 0, ints = 0, ptrs = 0, values = 0;
    const UPInt first = FirstOwnSlotInd.Get();
    const UPInt num = GetSlotInfoNum();
    for (UPInt i = first; i < num; ++i)
    {
        const SlotInfo& si = GetSlotInfo(AbsoluteIndex(i));
        if (si.CppBinding)
            continue;
        switch (si.BindType)
        {
        case SlotInfo::BT_Value:
            ++values;
            break;
        case SlotInfo::BT_ObjectAS:
        case SlotInfo::BT_Number:
        case SlotInfo::BT_String:
            ++ptrs;
            break;
        case SlotInfo::BT_Boolean:
            ++bools;
            break;
        case SlotInfo::BT_Int:
        case SlotInfo::BT_UInt:
            ++ints;
            break;
        default:
            break;
        }
    }

    if (values + ptrs + bools + ints == 0)
        return;

    unsigned boolOff = parent_size;
    unsigned intOff = boolOff + bools;
    if (ints)
        intOff = (intOff + 3) & ~3u;
    unsigned ptrOff = intOff + ints * 4;
    if (ptrs)
        ptrOff = (ptrOff + 7) & ~7u;
    unsigned valueOff = ptrOff + ptrs * 8;
    if (values)
        valueOff = (valueOff + 31) & ~31u;
    MemSize = valueOff + values * 32;

    for (UPInt i = first; i < num; ++i)
    {
        SlotInfo& si = GetOwnSlotInfo(AbsoluteIndex(i));
        if (si.CppBinding)
            continue;
        switch (si.BindType)
        {
        case SlotInfo::BT_Value:
            si.ValueInd = valueOff;
            valueOff += 32;
            break;
        case SlotInfo::BT_ObjectAS:
        case SlotInfo::BT_Number:
        case SlotInfo::BT_String:
            si.ValueInd = ptrOff;
            ptrOff += 8;
            break;
        case SlotInfo::BT_Boolean:
            si.ValueInd = boolOff;
            boolOff += 1;
            break;
        case SlotInfo::BT_Int:
        case SlotInfo::BT_UInt:
            si.ValueInd = intOff;
            intOff += 4;
            break;
        default:
            break;
        }
    }
}

// Class::Call: a class called as a function converts its single argument to the class (a TypeError when it
// cannot); any other argument count is an ArgumentError.
// MS2-FUNCTIONAL 0x1424ee6f0: the exe holds the class name in another frame slot; same results
// @0x1424ee6f0
void Class::Call(const Value& _this, Value& result, unsigned argc, const Value* const argv)
{
    SF_UNUSED(_this);
    ClassTraits::Traits& ctr = GetClassTraits();
    if (argc == 1)
    {
        if (ctr.Coerce(argv[0], result))
            return;
        ASString name = GetClassTraits().GetName();
        VM& vm = GetClassTraits().GetVM();
        const VM::Error e(VM::eCheckTypeFailedError, vm, argv[0], name.ToCStr());
        FUN_14252ecb0(&vm, &e, &fl::TypeErrorCI);
    }
    else
    {
        VM& vm = ctr.GetVM();
        const VM::Error e(VM::eCoerceArgumentCountError, vm, int(argc));
        FUN_14252ecb0(&vm, &e, &fl::ArgumentErrorCI);
    }
}

// Class::Construct: a new instance of the class in _this (a MemoryError when none could be made), initialized
// and handed to PostInit; when PreInit refuses it, a call from the VM drops its arguments off the stack.
// MS2-FUNCTIONAL 0x1424f0610: two argument loads before the throw call are swapped; same results
// @0x1424f0610
void Class::Construct(Value& _this, unsigned argc, const Value* argv, bool extCall)
{
    InstanceTraits::Traits& itr = GetInstanceTraits();
    VM& vm = GetClassTraits().GetVM();
    itr.MakeObject(_this, itr);
    if (_this.IsObject() && _this.GetObject() == NULL)
    {
        const VM::Error e(VM::ErrorID(1000) /* eOutOfMemoryError */, vm);
        FUN_14252ecb0(&vm, &e, &fl_errors::MemoryErrorCI);
    }
    if (PreInit(_this))
    {
        _this.GetObject()->InitInstance(extCall);
        PostInit(_this, argc, argv);
    }
    else if (!extCall)
        FUN_14241de40(vm.OpStack, argc);
}

// MS2-FUNCTIONAL 0x1424f0750: same steps; returns whether a constructor frame was pushed (the call stack at +0x78 grew),
// which CreateObject (0x1424f3acd) and the symbol constructor in sfr_as3_17d read to decide on ExecuteCode(1)
// @0x1424f0750
bool VM::Construct(const char* gname, Value& result, unsigned argc, const Value* argv, bool extCall)
{
    const UPInt size = Unk070[1];   // call stack size
    const StringDataPtr name(gname);
    Class* cl = GetClass(name);
    if (cl == NULL)
    {
        if (!IsException())
        {
            const Error e(ErrorID(1065), *this, name.ToCStr());   // eClassNotFoundError
            FUN_14252ecb0(this, &e, &fl::ReferenceErrorCI);
        }
        return false;
    }
    Value _class(cl);
    if (_class.IsNull())
    {
        const Error e(ErrorID(1009), *this);   // eConvertNullToObjectError
        FUN_14252ecb0(this, &e, &fl::TypeErrorCI);
        return false;
    }
    _class.GetObject()->Construct(result, argc, argv, extCall);
    return !IsException() && Unk070[1] > size;
}

// Throws "not a constructor" in the VM of the file at +0x20.
// @0x1424f0700
void Sfr33ThrowNotConstructor(const UByte* self)
{
    VM& vm = **reinterpret_cast<VM* const*>(*reinterpret_cast<const UByte* const*>(self + 0x20) + 0x78);
    Sfr33ThrowTypeError(vm, VM::Error(VM::eNotConstructorError, vm));
}

// Throws a TypeError when v, about to be used as an object, is null or undefined.
// MS2-FUNCTIONAL 0x1424ef180: value pointer kept in r8 (exe reuses rdx) and Error ctor arg order differs; same tests/throw
// @0x1424ef180
void Sfr33CheckObject(VM* const* self, const Value& v)
{
    if (v.IsNullOrUndefined())
    {
        VM& vm = **self;
        const VM::ErrorID id = v.IsNull() ? VM::eConvertNullToObjectError : VM::eConvertUndefinedToObjectError;
        Sfr33ThrowTypeError(vm, VM::Error(id, vm));
    }
}
}}}

void FUN_142502e70(void* pavm, const Scaleform::GFx::EventId& id);   // AvmDisplayObj: fire the event
void FUN_1424feb00(void* self, const Scaleform::GFx::AS3::Value& _this, Scaleform::GFx::AS3::Value& result, unsigned argc,
                   const Scaleform::GFx::AS3::Value* argv);   // UserDefined function: run the body

// UserDefinedFunction body: the receiver and arguments go to the host FunctionHandler (+0x40, user data +0x48) as
// GFx values (the receiver first in the argument array); a defined return value comes back as result.
// MS2-FUNCTIONAL 0x1424feb00: raw function-object and ASVM offsets
// @0x1424feb00
void FUN_1424feb00(void* self, const Scaleform::GFx::AS3::Value& _this, Scaleform::GFx::AS3::Value& result, unsigned argc,
                   const Scaleform::GFx::AS3::Value* argv)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx;
    UByte* const fn = static_cast<UByte*>(self);
    AS3::ASVM& asvm = **reinterpret_cast<AS3::ASVM**>(*reinterpret_cast<UByte**>(fn + 0x20) + 0x78);
    AS3::MovieRoot* root = asvm.GetMovieRoot();
    GFx::Value thisVal;
    GFx::Value retVal;
    root->ASValue2GFxValue(_this, &thisVal);
    ArrayCPP<GFx::Value, 2> args;
    args.PushBack(thisVal);
    for (unsigned i = 0; i < argc; ++i)
    {
        GFx::Value a;
        root->ASValue2GFxValue(argv[i], &a);
        args.PushBack(a);
    }
    FunctionHandler::Params params;
    params.pRetVal = &retVal;
    params.pMovie = reinterpret_cast<Movie*>(asvm.GetMovieImpl());   // MovieImpl derives from Movie at offset 0
    params.pThis = &thisVal;
    params.pArgsWithThis = &args[0];
    params.pArgs = argc ? &args[1] : NULL;
    params.ArgCount = static_cast<unsigned>(args.GetSize() - 1);
    params.pUserData = *reinterpret_cast<void**>(fn + 0x48);
    (*reinterpret_cast<FunctionHandler**>(fn + 0x40))->Call(params);
    if (!retVal.IsUndefined())
        root->GFxValue2ASValue(retVal, &result);
}
void FUN_14241e4f0(void* self, Scaleform::GFx::AS3::Value& result);   // UserDefined function: keep the result
void FUN_1424674c0(void* cls, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>& result,
                   const Scaleform::GFx::ASString& name, unsigned mouseIdx);   // MouseCursorEvent class: make the event
bool FUN_142468740(void* target, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>& evt,
                   Scaleform::GFx::DisplayObject* stage);   // dispatch evt on the stage (false: default prevented)
void FUN_142541a60(void* self, void* pheapAddr, Scaleform::UPInt newSize);   // HashSetBase::setRawCapacity copy
void FUN_142524870(void* arr, Scaleform::UPInt n);   // Resize of a POD array with its heap at +0x18
void FUN_1425247f0(void* arr, Scaleform::UPInt n);   // Resize of a POD array
void FUN_14251f930(void* tr, int op);                // Tracer: emit opcode op
void FUN_14251fb90(void* tr, int op, Scaleform::UPInt arg);   // Tracer: emit opcode op with one argument
bool FUN_1424f86d0(void* tr, const Scaleform::GFx::AS3::Value& v, bool pop);   // Tracer: push the object constant v
void* FUN_142524f60(void* vm, const void* file, const void* mn);   // VM: the class traits the ABC multiname mn of file names (NULL if unresolved)
const Scaleform::GFx::AS3::Abc::Multiname& FUN_14250f8a0(const void* amn, const void* abc);   // the type name of a multiname
extern "C" const int DAT_143a2d640[];           // the AS3 error ids, sorted
extern "C" const char* const DAT_143a2d890[];   // the AS3 error messages, by id position
const Scaleform::GFx::AS3::Traits& FUN_14250ffc0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v);   // the traits of a value
void FUN_142508bd0(Scaleform::UPInt obj, void* out, int hint);   // Object::GetDefaultValueUnsafe (as sfr_as3_19 declares it)
// Object: the property name of namespace ns (FindObjProperty, then its value); the member's hidden CheckResult
// slot is ret.
Scaleform::UByte* FUN_14250dd20(Scaleform::GFx::AS3::Object* self, Scaleform::UByte* ret, const Scaleform::GFx::ASString* name,
                                Scaleform::GFx::AS3::Instances::Namespace* ns, Scaleform::GFx::AS3::Value* value);

// Object::GetDefaultValue for one method name: a callable property name is called on obj with no arguments and its
// result swapped into result. False when the property lookup itself failed.
static bool Sfr33CallDefaultMethod(Scaleform::GFx::AS3::Object& obj, const Scaleform::GFx::ASString& name,
                                   Scaleform::GFx::AS3::Value& result)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    VM& vm = obj.GetVM();
    Value func;
    UByte ok;
    if (!*FUN_14250dd20(&obj, &ok, &name, &vm.GetPublicNamespace(), &func))
        return false;
    const unsigned k = func.GetKind();
    if (k > Value::kNamespace || k - Value::kThunk < 3)
    {
        Value r;
        vm.ExecuteInternalUnsafe(func, Value(&obj), r, 0, NULL, false);
        result.Swap(r);
    }
    return true;
}

// Object::GetDefaultValueUnsafe ([[DefaultValue]]): with the hint String (Date objects and the hint-less default for
// them, and always for the two traits types 0xd/0xe) toString is tried before valueOf, otherwise valueOf first; the
// second runs only when the first left no primitive (and raised nothing).
// MS2-FUNCTIONAL 0x142508bd0: untyped signature as sfr_as3_19 declares it; one helper for the two name lookups
// @0x142508bd0
void FUN_142508bd0(Scaleform::UPInt objAddr, void* out, int hint)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    Object& obj = *reinterpret_cast<Object*>(objAddr);
    Value& result = *static_cast<Value*>(out);
    VM& vm = obj.GetVM();
    const int tt = obj.GetTraits().GetTraitsType();
    if (static_cast<unsigned>(tt - 0xd) < 2)
        hint = Value::hintString;
    else if (hint == Value::hintNone)
        hint = (tt == 8) + 1;
    const GFx::ASString& toStr = vm.GetStringManager().GetBuiltin(AS3Builtin_toString);
    const GFx::ASString& valueOf = vm.GetStringManager().GetBuiltin(AS3Builtin_valueOf);
    const bool str = hint == Value::hintString;
    if (!Sfr33CallDefaultMethod(obj, str ? toStr : valueOf, result))
        return;
    const unsigned k = result.GetKind();
    if (vm.IsException() || k < Value::kThunk || k == Value::kString)
        return;
    Sfr33CallDefaultMethod(obj, str ? valueOf : toStr, result);
}
const Scaleform::GFx::AS3::Traits* FUN_14250d760(Scaleform::GFx::AS3::VM& vm,
                                                 const Scaleform::GFx::AS3::Multiname& mn);   // the traits that define mn
const void* FUN_142546050(const void* method_info, const void* const_pool);   // the return type multiname of a method

// Coerces value to the return type of the method the current call frame runs (result may be value): TypeError
// 1014 when the type is not found, 1034 when the value does not convert.
// MS2-FUNCTIONAL 0x1424efe30: written on raw offsets (VM call stack +0x78 size / +0x90 pages, Abc::File tables)
// @0x1424efe30
void FUN_1424efe30(Scaleform::GFx::AS3::VM* vm, Scaleform::GFx::AS3::Value* value, Scaleform::GFx::AS3::Value* result)
{
    using namespace Scaleform::GFx::AS3;
    const char* const v = reinterpret_cast<const char*>(vm);
    const Scaleform::UPInt i = *reinterpret_cast<const Scaleform::UPInt*>(v + 0x78) - 1;
    const char* frame = (i & 0x3f) * 0xa8 + *reinterpret_cast<const char* const*>(
        *reinterpret_cast<const char* const*>(v + 0x90) + (i >> 6) * 8);
    const char* file = *reinterpret_cast<const char* const*>(frame + 0x28);
    const char* abc = *reinterpret_cast<const char* const*>(file + 0x28);
    const char* const* bodies = *reinterpret_cast<const char* const* const*>(abc + 0x170);
    const char* const* methods = *reinterpret_cast<const char* const* const*>(abc + 0xf8);
    const char* body = bodies[*reinterpret_cast<const int*>(frame + 0x30)];
    const char* mn = static_cast<const char*>(FUN_142546050(methods[*reinterpret_cast<const int*>(body + 0x18)],
                                                            abc + 0x30));
    const ClassTraits::Traits* ctr = static_cast<const ClassTraits::Traits*>(FUN_142524f60(vm, file, mn));
    if (!ctr)
    {
        const char* strings = *reinterpret_cast<const char* const*>(abc + 0x70);
        const Abc::StringView& name = *reinterpret_cast<const Abc::StringView*>(
            strings + static_cast<Scaleform::UPInt>(*reinterpret_cast<const unsigned*>(mn + 8)) * 8);
        const VM::Error e(VM::ErrorID(1014) /* eClassNotFoundError */, *vm, name.ToStringDataPtr().ToCStr());
        FUN_14252ecb0(vm, &e, &fl::TypeErrorCI);
        return;
    }
    if (ctr->Coerce(*value, *result))
        return;
    const VM::Error e(VM::ErrorID(1034) /* eCheckTypeFailedError */, *vm, *value, ctr->GetName().ToCStr());
    FUN_14252ecb0(vm, &e, &fl::TypeErrorCI);
}

void FUN_1424d29d0(void* set, void* pheapAddr, const Scaleform::UPInt* key, Scaleform::UPInt hash);   // HashSetLH<SPtr>::add
namespace Scaleform { namespace GFx { namespace AS3 {
void Sfr33TracerPopLast(UByte* self);
const SlotInfo* FindFixedSlot(VM& vm, const Traits& tr, const Multiname& mn, UPInt& index, Object* obj);
}}}

// Tracer: emits the push of the object constant v (pop: drop the last pushed value first) and keeps the object in
// the ABC file's set of referenced constants (+0x38). The argument carries the value kind in the pointer's low bits.
// MS2-FUNCTIONAL 0x1424f86d0: written on raw offsets (tracer +0x20 state, +0x28 file); the exe calls SPtr::SetPtr out of line
// @0x1424f86d0
bool FUN_1424f86d0(void* tr, const Scaleform::GFx::AS3::Value& v, bool pop)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    UByte* const self = static_cast<UByte*>(tr);
    UByte* file = *reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28);
    VM& vm = **reinterpret_cast<VM**>(file + 0x20);
    const Traits& t = FUN_14250ffc0(vm, v);
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
        Sfr33TracerPopLast(self);
    const UByte* pv = reinterpret_cast<const UByte*>(&v);
    FUN_14251fb90(self, 0xb5, *reinterpret_cast<const UPInt*>(pv + 0x10) + tag);
    file = *reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28);
    const UPInt obj = *reinterpret_cast<const UPInt*>(pv + 0x10);
    if (obj == *reinterpret_cast<const UPInt*>(*reinterpret_cast<UByte**>(file + 0x20) + 0x298))
        return true;
    UByte* set = file + 0x38;
    const UPInt hash = FixedSizeHash<UPInt>::SDBM_Hash(&obj, sizeof(obj));
    const UPInt* table = *reinterpret_cast<UPInt* const*>(set);
    if (table)
    {
        const UPInt mask = table[1];
        const UPInt home = hash & mask;
        const UPInt* e = table + 2 + home * 3;
        if (e[0] != UPInt(-2) && e[1] == home)
        {
            UPInt i = home;
            for (;;)
            {
                if (e[1] == home && e[2] == obj)
                {
                    reinterpret_cast<SPtr<GASRefCountBase>*>(const_cast<UPInt*>(table + 4 + i * 3))
                        ->SetPtr(reinterpret_cast<GASRefCountBase*>(obj));
                    return true;
                }
                i = e[0];
                if (i == UPInt(-1))
                    break;
                e = table + 2 + i * 3;
            }
        }
    }
    FUN_1424d29d0(set, set, &obj, hash);
    return true;
}

void FUN_14251fa10(void* tr, int op, Scaleform::UPInt arg1, Scaleform::UPInt arg2);   // Tracer: emit opcode op with two arguments

// Tracer: emits the property op (op: 0x66 get / 0x68 init / 0x61 set / 5 ...) on a name that resolves to a fixed
// slot of the traits t as a slot access: a plain data slot by index (0xb7/0xb8), a method or getter slot (bind types
// 13/14) as a call of its vtable entry (0x43 callmethod, 0xb9 for op 5) plus a pop; else the op with ind.
// MS2-FUNCTIONAL 0x1424f92f0: written on raw offsets (tracer +0x20 state, +0x28 file, SlotInfo bitfields)
// @0x1424f92f0
bool FUN_1424f92f0(void* tr, int op, const Scaleform::GFx::AS3::Traits* t, void* /*unused*/,
                   const Scaleform::GFx::AS3::Multiname* pmn, int ind)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    UByte* const self = static_cast<UByte*>(tr);
    const unsigned mnw = *reinterpret_cast<const unsigned*>(pmn);
    const unsigned kind = mnw & 3;
    if (kind != 1 && !(mnw & 4) && (kind != 0 || *reinterpret_cast<const UPInt*>(reinterpret_cast<const UByte*>(pmn) + 8)) && t)
    {
        UByte* file = *reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28);
        UPInt index = 0;
        const SlotInfo* si = FindFixedSlot(**reinterpret_cast<VM**>(file + 0x20), *t, *pmn, index, NULL);
        if (si)
        {
            const int siw = *reinterpret_cast<const int*>(si);
            const int bt = (siw << 0x16) >> 0x1b;
            if (bt < 11)
            {
                if (mnw & 4)
                {
                    FUN_14251f930(self, 0x2b);   // swap
                    FUN_14251f930(self, 0x29);   // pop
                }
                FUN_14251fb90(self, (op == 0x68) + 0xb7, static_cast<unsigned>(static_cast<int>(index) + 1));
                return true;
            }
            if (!((siw >> 0x1a) & 1) && !((reinterpret_cast<const UByte*>(t)[0x68] >> 2) & 1) &&
                static_cast<unsigned>(bt - 13) < 2)
            {
                if (mnw & 4)
                {
                    FUN_14251f930(self, 0x2b);
                    FUN_14251f930(self, 0x29);
                }
                const int vind = (*reinterpret_cast<const int*>(si) << 5) >> 0xf;
                FUN_14251fa10(self, op == 5 ? 0xb9 : 0x43, static_cast<UPInt>(static_cast<SPInt>(vind + 1)), 1);
                FUN_14251f930(self, 0x29);
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
// MS2-FUNCTIONAL 0x1424f8910: written on raw offsets (tracer +0x20 state, class traits +0xc0/+0x80/+0x68/+0xd0)
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
        Value v;
        Sfr33TracerValueSet(v, 0xd, cls, true);
        if (!FUN_1424f86d0(self, v, pop))
            return false;
        *reinterpret_cast<unsigned*>(&v) = not_null ? 0x40d : 0xd;
        opstack.PushBack(v);
        return true;
    }
    if (!((itr[0x68] >> 4) & 1))
        return false;
    UByte* script = *reinterpret_cast<UByte**>(itr + 0xd0);
    UPInt index = 0;
    vm = *reinterpret_cast<VM**>(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28) + 0x20);
    if (!FindFixedSlot(*vm, **reinterpret_cast<const Traits* const*>(script + 0x20), mn, index,
                       reinterpret_cast<Object*>(script)))
        return false;
    {
        Value t;
        Sfr33TracerValueSet(t, not_null ? 0x449 : 0x49, ctr, false);
        opstack.PushBack(t);
    }
    Value v;
    Sfr33TracerValueSet(v, 0xc, script, true);
    FUN_1424f86d0(self, v, false);
    FUN_14251fb90(self, 0xb6, static_cast<unsigned>(static_cast<int>(index) + 1));   // getslot
    return true;
}

namespace Scaleform { namespace GFx { namespace AS3 {
namespace TR { UPInt Sfr27TracerGetValueTraits(UPInt tracer, const Value* v, bool asInstance); }
Value::TraceNullType Sfr33TracerCanBeNull(const UByte* self, const InstanceTraits::Traits* tr);
}}}
Scaleform::UPInt FUN_14250a060(Scaleform::UPInt vm, void* value);   // value -> traits

// Tracer: emits the call op (0x45 callsuper, 0x46 callproperty, 0x4e/0x4f the void forms, ...) of the call info
// (+0x18 argc, +0x148 the name, +0x178 the receiver) and pushes the result type on the state's op stack (+0x38). A
// name that resolves to a method slot of the receiver's traits becomes a call by vtable index (0x43 callmethod /
// 0xb9 callsupermethod), a getter slot a getter call (0xba/0xbb); a name of a class a construct (0xce) when the
// traits are flagged so.
// MS2-FUNCTIONAL 0x1424f7540: written on raw offsets (tracer +0x20 state, call info, SlotInfo bitfields)
// @0x1424f7540
bool FUN_1424f7540(void* tr, int op, void* state, void* pinfo, int ind)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    UByte* const self = static_cast<UByte*>(tr);
    UByte* const info = static_cast<UByte*>(pinfo);
    ArrayDH<Value>& opstack = *reinterpret_cast<ArrayDH<Value>*>(static_cast<UByte*>(state) + 0x38);
    const bool super_call = op == 0x45 || op == 0x4e;
    const UByte* t = reinterpret_cast<const UByte*>(
        TR::Sfr27TracerGetValueTraits(reinterpret_cast<UPInt>(self), reinterpret_cast<const Value*>(info + 0x178), super_call));
    const int argc = *reinterpret_cast<const int*>(info + 0x18);
    const Multiname& mn = *reinterpret_cast<const Multiname*>(info + 0x148);
    const unsigned mnw = *reinterpret_cast<const unsigned*>(&mn);
    const unsigned kind = mnw & 3;
    unsigned flags;
    const void* rt;
    if (kind == 1 || (mnw & 4) || (kind == 0 && !*reinterpret_cast<const UPInt*>(info + 0x150)))
        goto generic;
    {
        VM* vm = *reinterpret_cast<VM**>(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28) + 0x20);
        UPInt index = 0;
        const SlotInfo* si;
        if (t && !((t[0x68] >> 2) & 1) &&
            (si = FindFixedSlot(*vm, *reinterpret_cast<const Traits*>(t), mn, index, NULL)) != NULL)
        {
            const int vind = (*reinterpret_cast<const int*>(si) << 5) >> 0xf;
            if (vind >= 0)
            {
                const int bt = (*reinterpret_cast<const int*>(si) << 0x16) >> 0x1b;
                bool fixed = true;
                if (bt == 11)
                {
                    FUN_14251fa10(self, super_call ? 0xb9 : 0x43, static_cast<UPInt>(static_cast<SPInt>(vind)), argc);
                    if (static_cast<unsigned>(op - 0x4e) < 2)
                    {
                        FUN_14251f930(self, 0x29);   // pop
                        return true;
                    }
                }
                else if (((bt - 12) & ~2) == 0)
                {
                    int gop = op;
                    if (op == 0x45)
                        gop = 0xbb;
                    else if (op == 0x46)
                        gop = 0xba;
                    FUN_14251fa10(self, gop, static_cast<UPInt>(static_cast<SPInt>(vind)), argc);
                }
                else
                    fixed = false;
                if (fixed)
                {
                    VM* vm2 = *reinterpret_cast<VM**>(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28) + 0x20);
                    const AbsoluteIndex ai((*reinterpret_cast<const int*>(si) << 5) >> 0xf);
                    const InstanceTraits::Traits* ret;
                    {
                        Value f = reinterpret_cast<const Traits*>(t)->GetVT().GetValue(ai);
                        ret = reinterpret_cast<const InstanceTraits::Traits*>(
                            FUN_14250a060(reinterpret_cast<UPInt>(vm2), &f));
                    }
                    flags = ((static_cast<unsigned>(Sfr33TracerCanBeNull(self, ret)) & ~8u) << 5) | 8;
                    rt = ret;
                    goto push;
                }
            }
        }
        const UByte* ct = reinterpret_cast<const UByte*>(Sfr33ResolveMnClassTraits(vm, mn));
        if (!ct)
            goto generic;
        if (!((t[0x68] >> 5) & 1))
        {
            FUN_14251fa10(self, op, static_cast<UPInt>(static_cast<SPInt>(ind)), argc);
            if (static_cast<unsigned>(op - 0x4e) < 2)
                return true;
        }
        else
            FUN_14251fb90(self, 0xce, static_cast<UPInt>(static_cast<SPInt>(argc)));
        rt = *reinterpret_cast<void* const*>(ct + 0xc0);
        flags = 8;
        goto push;
    }
generic:
    FUN_14251fa10(self, op, static_cast<UPInt>(static_cast<SPInt>(ind)), argc);
    if (static_cast<unsigned>(op - 0x4e) < 2)
        return true;
    {
        const UByte* vm = *reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28) + 0x20);
        rt = *reinterpret_cast<void* const*>(*reinterpret_cast<const UByte* const*>(vm + 0x1f8) + 0xc0);
    }
    flags = 0x48;
push:
    {
        Value v;
        Sfr33TracerValueSet(v, flags, const_cast<void*>(rt), false);
        opstack.PushBack(v);
    }
    return true;
}

namespace Scaleform { namespace GFx { namespace AS3 {
namespace TR { bool Sfr27TracerIsPrimitiveType(UPInt tracer, UPInt traits); }
void* Sfr33LazyGet80b(void** self);
}}}
// The type of the slot si of the traits t as a tracer value (result); the return carries false (first byte) when
// the slot type is not known yet.
const char* FUN_14250cf20(void* state, char* ret, const void* t, const void* si, Scaleform::GFx::AS3::Value& result);

// Tracer: emits the get op (0x66 getproperty, 4 getsuper, ...) of the name mn on a receiver of the traits t and
// pushes the result type on the state's op stack (+0x38): a class name of a global as its class, a data slot as
// getslot (0xb6), a method slot as its function (op 0x66) or a getter call (0x43 callmethod / 0xb9); the builtin
// primitive traits give their class. Anything else is the op with ind and an Object result.
// MS2-FUNCTIONAL 0x1424f8b00: written on raw offsets (tracer +0x20 state, VM builtin traits, SlotInfo bitfields)
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
    if ((*reinterpret_cast<const unsigned*>(reinterpret_cast<const UByte*>(pmn) + 0x10) & 0x1f) - 8 < 2)
        goto object_result;
    if (!((tb[0x68] >> 2) & 1) &&
        !TR::Sfr27TracerIsPrimitiveType(reinterpret_cast<UPInt>(self), reinterpret_cast<UPInt>(t)))
    {
        if (t->IsGlobal() && FUN_1424f8910(self, state, mn, true, false))
            return true;
        UPInt index = 0;
        const SlotInfo* si = FindFixedSlot(*reinterpret_cast<VM*>(vm), *t, mn, index, NULL);
        if (si)
        {
            const unsigned siw = *reinterpret_cast<const unsigned*>(si);
            const int bt = (static_cast<int>(siw) << 0x16) >> 0x1b;
            if (bt < 11)
            {
                Value v;
                if (!*FUN_14250cf20(state, &ok, t, si, v))
                    return false;
                opstack.PushBack(v);
                if (mnw & 4)
                    FUN_14251f930(self, 0x29);   // pop
                FUN_14251fb90(self, 0xb6, static_cast<unsigned>(static_cast<int>(index) + 1));   // getslot
                return true;
            }
            if (!((siw >> 0x1a) & 1) && (bt != 11 || op == 0x66))
            {
                const InstanceTraits::Traits* ret;
                if (bt == 11)
                {
                    FUN_14251fb90(self, 0xb6, static_cast<unsigned>(static_cast<int>(index) + 1));
                    const AbsoluteIndex ai((*reinterpret_cast<const int*>(si) << 5) >> 0xf);
                    Value f = t->GetVT().GetValue(ai);
                    ret = &reinterpret_cast<const TR::State*>(state)->GetFunctType(f);
                }
                else
                {
                    if (mnw & 4)
                        FUN_14251f930(self, 0x29);
                    FUN_14251fa10(self, op == 4 ? 0xb9 : 0x43,
                                  static_cast<UPInt>(static_cast<SPInt>((static_cast<int>(siw) << 5) >> 0xf)), 0);
                    const AbsoluteIndex ai((*reinterpret_cast<const int*>(si) << 5) >> 0xf);
                    Value f = t->GetVT().GetValue(ai);
                    ret = reinterpret_cast<const InstanceTraits::Traits*>(FUN_14250a060(reinterpret_cast<UPInt>(vm), &f));
                }
                Value v;
                Sfr33TracerValueSet(v, ((static_cast<unsigned>(Sfr33TracerCanBeNull(self, ret)) & ~8u) << 5) | 8,
                                    const_cast<InstanceTraits::Traits*>(ret), false);
                opstack.PushBack(v);
                return true;
            }
        }
    }
    {
        UPInt index = 0;
        UByte* fvm = *reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(*reinterpret_cast<UByte**>(self + 0x20) + 0x28) + 0x20);
        const SlotInfo* si = FindFixedSlot(*reinterpret_cast<VM*>(fvm), *t, mn, index, NULL);
        if (si)
        {
            Value v;
            if (!*FUN_14250cf20(state, &ok, t, si, v))
                return false;
            opstack.PushBack(v);
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
                            ((static_cast<unsigned>(Sfr33TracerCanBeNull(
                                  self, reinterpret_cast<const InstanceTraits::Traits*>(rt))) & ~8u) << 5) | 8,
                            const_cast<UByte*>(rt), false);
        opstack.PushBack(v);
        FUN_14251fb90(self, op, static_cast<UPInt>(static_cast<SPInt>(ind)));
        return true;
    }
object_result:
    {
        rt = *reinterpret_cast<UByte* const*>(*reinterpret_cast<UByte* const*>(vm + 0x1f8) + 0xc0);
        Value v;
        Sfr33TracerValueSet(v, 0x48, const_cast<UByte*>(rt), false);
        opstack.PushBack(v);
    }
    FUN_14251fb90(self, op, static_cast<UPInt>(static_cast<SPInt>(ind)));
    return true;
}

void FUN_142501e80(void* state, void* propRef, void* multiname, void* stypeOut, void* scopeIndexOut);   // State::FindProp

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
        t = reinterpret_cast<const UByte*>(&FUN_14250ffc0(*reinterpret_cast<VM*>(vm), v));
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
        if (!*FUN_14250cf20(state, &ok, Sfr33TracerThisTraits(vm, prop.This), si, v))
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
        Sfr33TracerValueSet(v, ((static_cast<unsigned>(Sfr33TracerCanBeNull(self, ret)) & ~8u) << 5) | 8,
                            const_cast<InstanceTraits::Traits*>(ret), false);
        opstack.PushBack(v);
        return true;
    }
    FUN_14251fb90(self, 0xb6, static_cast<unsigned>(sindex + 1));   // getslot
    Value v;
    char ok;
    if (!*FUN_14250cf20(state, &ok, t, si, v))
        return false;
    if (not_null)
        *reinterpret_cast<unsigned*>(&v) |= 0x400;
    opstack.PushBack(v);
    return true;
}

void* FUN_142501310(Scaleform::GFx::AS3::VM& vm, void* scope, const Scaleform::GFx::AS3::Multiname& mn);   // find mn on one scope

// Searches the scope objects from the innermost out for mn; when the VM knows the traits that define mn, only the
// scopes of the same owner (vftable slot 10) are tried. Returns what FUN_142501310 found, or NULL.
// MS2-FUNCTIONAL 0x142501870: raw scope array and vftable-slot calls (the owning class is not recovered)
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

// The class traits for mn as seen from the scope traits tr. A qualified name takes the declared type of the last
// matching slot of that name; for a namespace set, each namespace in turn takes the type of a matching typed slot,
// else the VM's class of that name and namespace (found on the global object and cached). NULL when the name does
// not convert to a string.
// MS2-FUNCTIONAL 0x142501310: raw namespace-set and VM offsets; name chain walked through Slots::GetSlotInfo
// @0x142501310
void* FUN_142501310(Scaleform::GFx::AS3::VM& vm, void* scope, const Scaleform::GFx::AS3::Multiname& mn)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx;
    using namespace Scaleform::GFx::AS3;
    const Traits& tr = *static_cast<const Traits*>(scope);
    const UByte* sm = *reinterpret_cast<UByte* const*>(*reinterpret_cast<UByte* const*>(reinterpret_cast<UByte*>(&vm) + 0x10) + 0x1e8);
    ASString name(reinterpret_cast<ASStringNode*>(const_cast<UByte*>(sm) + 0x40));
    ClassTraits::Traits* ct = NULL;
    if (!mn.Name.Convert2String(name))
        return NULL;
    const UByte* obj = reinterpret_cast<const UByte*>(mn.Obj.GetPtr());
    if (mn.IsQName())
    {
        const Instances::Namespace& ns = *reinterpret_cast<const Instances::Namespace*>(obj);
        VM* tvm = *reinterpret_cast<VM* const*>(reinterpret_cast<const UByte*>(&tr) + 0x78);
        if (const UInt32* values = tr.FindSlotValues(name))
        {
            SPInt ind = *values;
            do
            {
                const SlotInfo& si = tr.GetSlotInfo(AbsoluteIndex(ind));
                if (Sfr33SlotNsMatches(*si.pNs, ns))
                    ct = Sfr33SlotDataType(&si, tvm);
                if (static_cast<UPInt>(ind) < tr.FirstOwnSlotNum)
                    ind = tr.Parent->GetPrevSlotIndex(ind);
                else
                    ind = tr.VArray[static_cast<UPInt>(ind) - tr.FirstOwnSlotNum].Prev;
            } while (ind >= 0);
        }
        return ct;
    }
    const UInt32* values = tr.FindSlotValues(name);
    const UPInt n = *reinterpret_cast<const UPInt*>(obj + 0x28);
    for (UPInt i = 0; i < n; ++i)
    {
        const Instances::Namespace& ns =
            **reinterpret_cast<Instances::Namespace* const*>(*reinterpret_cast<const UPInt*>(obj + 0x20) + i * 8);
        if (values)
        {
            SPInt ind = *values;
            do
            {
                const SlotInfo& si = tr.GetSlotInfo(AbsoluteIndex(ind));
                if (Sfr33SlotNsMatches(*si.pNs, ns) && (ct = Sfr33SlotDataType(&si, &vm)) != NULL)
                    return ct;
                if (static_cast<UPInt>(ind) < tr.FirstOwnSlotNum)
                    ind = tr.Parent->GetPrevSlotIndex(ind);
                else
                    ind = tr.VArray[static_cast<UPInt>(ind) - tr.FirstOwnSlotNum].Prev;
            } while (ind >= 0);
        }
        ct = Sfr27GetClassTraitsByName(&vm, &name, &ns);
        if (ct)
            break;
    }
    return ct;
}

namespace Scaleform { namespace GFx { namespace AS3 {

ClassTraits::Traits* Sfr33SlotDataType(const SlotInfo* psi, VM* pvm);

// The fixed slot of tr named name in ns (index receives its slot index). 0x1425011c0
const SlotInfo* FindFixedSlot(const Traits& tr, const ASString& name, const Instances::Namespace& ns, UPInt& index,
                              Object* obj);

// The slot bind type of a value declared with the ABC multiname ns of file tr in vm (2: any/Object value; 5..9: the
// primitive types; 3: an object of another class). The tail of Traits::GetBindingType (inlined there in the exe).
static int Sfr33CallerAccessKind(UByte* vm, const UByte* tr, const UByte* ns)
{
    UByte* cur = static_cast<UByte*>(FUN_142524f60(vm, tr, ns));
    if (!cur)
        return 2;
    switch (*reinterpret_cast<const int*>(cur + 0x70))
    {
    case 1: return 5;
    case 2: return 6;
    case 3: return 7;
    case 4: return 8;
    case 5: return 9;
    case 9: break;
    default:
        return (cur != *reinterpret_cast<UByte* const*>(vm + 0x1f8)) + 2;
    }
    return 2;
}

// How a slot of these traits declared with the ABC multiname mn of file stores its value: the any type is a plain
// value, otherwise the class traits mn names in the traits' VM (this+0x78) decide.
// MS2-FUNCTIONAL 0x1425075e0: the null-traits return is laid out before the switch (exe: after); same code.
// @0x1425075e0
SlotInfo::BindingType Traits::GetBindingType(VMAbcFile& file, const Abc::Multiname& mn) const
{
    const UByte* self = reinterpret_cast<const UByte*>(this);
    const UByte* tr = reinterpret_cast<const UByte*>(&file);
    const UByte* ns = reinterpret_cast<const UByte*>(&mn);
    if (ns == *reinterpret_cast<UByte* const*>(tr + 0x28) + 0xe8)
        return static_cast<SlotInfo::BindingType>(2);
    return static_cast<SlotInfo::BindingType>(
        Sfr33CallerAccessKind(*reinterpret_cast<UByte* const*>(self + 0x78), tr, ns));
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
// MS2-FUNCTIONAL 0x142503660: the exe inlines the value visit with a spare null register (r12) and a cmova guard.
// @0x142503660
void Sfr33ValueArrayForEachChildGCa(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const UByte* arr,
                                    ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    for (UPInt i = 0; i < *reinterpret_cast<const UPInt*>(arr + 8); ++i)
        AS3::ForEachChild_GC(prcc, (*reinterpret_cast<Value* const*>(arr))[i], op, owner);
}

// MS2-FUNCTIONAL 0x142503730: the exe inlines the value visit with a spare null register (r12) and a cmova guard.
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

// ObjectInterface::GetElement of an Array: pval receives element idx of the array pdata (false past its end).
// @0x142509ad0
bool Sfr33ArrayGetElement(const UByte* self, UByte* pdata, unsigned idx, GFx::Value* pval)
{
    pval->SetUndefined();
    SparseArray& sa = *reinterpret_cast<SparseArray*>(pdata + 0x38);
    if (idx >= static_cast<UInt32>(sa.GetSize()))
        return false;
    const MovieRoot* root = *reinterpret_cast<MovieRoot* const*>(*reinterpret_cast<UByte* const*>(self + 8) + 0x18);
    const Value& v = sa.At(idx);
    root->ASValue2GFxValue(v, pval);
    return true;
}

// The message of AS3 error id (NULL when it has none).
// MS2-FUNCTIONAL 0x142509b60: our build peels the first search step (constant midpoint); same search and result.
// @0x142509b60
const char* Sfr33GetErrorMsg(int id)
{
    int lo = 0, hi = 0x91;
    do
    {
        const int mid = (hi + lo) >> 1;
        const int v = DAT_143a2d640[mid];
        if (v == id)
        {
            lo = mid;
            break;
        }
        if (v > id)
            hi = mid - 1;
        else
            lo = mid + 1;
    } while (lo <= hi);
    return DAT_143a2d640[lo] == id ? DAT_143a2d890[lo] : NULL;
}

// The file loader MovieRoot::CheckAvm hands the new VM: no files. vftable 0x14317f470.
class Sfr33NullFileLoader : public FileLoader
{
public:
    virtual UPInt GetSize() const;
    virtual const Ptr<Abc::File>& GetFile(UPInt n);
    virtual const Abc::File* GetFile(const ASString& name);
};

// A function-local static null file.
// MS2-FUNCTIONAL 0x142509c20: the null store and the atexit argument load are scheduled the other way round.
// @0x142509c20
const Ptr<Abc::File>& Sfr33NullFileLoader::GetFile(UPInt)
{
    static Ptr<Abc::File> f;
    return f;
}

// (shared copies: return 0 at 0x14250dbb0 and 0x142509c90)
UPInt Sfr33NullFileLoader::GetSize() const { return 0; }
const Abc::File* Sfr33NullFileLoader::GetFile(const ASString&) { return NULL; }

// MovieRoot::CheckAvm (virtual): creates the AS3 VM on first use and runs its startup code.
// MS2-FUNCTIONAL 0x1424eecb0: self lives in rbx (exe rdi) and the null test of the released ActionControl is merged with the one before Release.
// @0x1424eecb0
bool Sfr33CheckAvm(MovieRoot* self)
{
    UByte* const p = reinterpret_cast<UByte*>(self);
    Scaleform::AutoPtr<ASVM>& avm = *reinterpret_cast<Scaleform::AutoPtr<ASVM>*>(p + 0x48);
    if (!avm)
    {
        // FlashUI (+0x28): verbose actions from the movie's ActionControl, output level 3
        const StateBag* states = reinterpret_cast<const StateBag*>(reinterpret_cast<const UByte*>(self->GetMovieImpl()) + 0x10);
        State* pac = states->GetStateAddRef(State::State_ActionControl);   // the movie's Movie::StateBag base
        if (pac)
            pac->Release();
        p[0x34] = pac ? (reinterpret_cast<const UByte*>(pac)[0x18] & 1) : 0;
        *reinterpret_cast<int*>(p + 0x30) = 3;
        Sfr33NullFileLoader loader;
        avm = SF_HEAP_NEW(self->GetMovieImpl()->GetMovieHeap())
            ASVM(self, *reinterpret_cast<FlashUI*>(p + 0x28), loader, self->BuiltinsMgr,
                 **reinterpret_cast<ASRefCountCollector* const*>(*reinterpret_cast<UByte* const*>(p + 0x40) + 0x20));
        avm->ExecuteCode(1);
    }
    return avm != NULL;
}


// Runs the class PostInit of the AS3 object without arguments. When that pushed a call frame, it runs now (execute)
// or stays queued (1); an exception is reported and flags the display object (+0x88).
// MS2-FUNCTIONAL 0x1424ee800: the exe inlines the object Value's ctor and dtor (out of line here).
// @0x1424ee800
SF_NOINLINE unsigned AvmDisplayObj::CallCtor(bool execute)
{
    if (!pAS3RawPtr && !pAS3CollectiblePtr)
        return 0;
    Class& cls = reinterpret_cast<Object*>(GetAS3Obj())->GetTraits().GetConstructor();
    Value v(reinterpret_cast<Object*>(GetAS3Obj()));
    unsigned result = 0;
    UByte* const dobj = reinterpret_cast<UByte*>(pDispObj);
    VM* vm = *reinterpret_cast<VM**>(*reinterpret_cast<UByte**>(dobj + 0x20) + 0x48);
    if (vm)
    {
        const UPInt depth = *reinterpret_cast<UPInt*>(reinterpret_cast<UByte*>(vm) + 0x78);
        cls.PostInit(v, 0, NULL);
        if (*reinterpret_cast<UPInt*>(reinterpret_cast<UByte*>(vm) + 0x78) > depth)
        {
            if (!execute)
                return 1;
            vm->ExecuteCode(1);
            if (*(reinterpret_cast<UByte*>(vm) + 0x180))
            {
                vm->OutputAndIgnoreException();
                *reinterpret_cast<UInt16*>(reinterpret_cast<UByte*>(pDispObj) + 0x88) |= 0x20;
            }
        }
    }
    return result;
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
};

UPInt* FUN_1424d9f30(UPInt* self, UPInt heap, UPInt body, UPInt ops, UPInt extra);   // Tracer::Tracer
UByte* FUN_1424e6aa0(void* tracer, void* blocks, UPInt pos, int a, bool b);   // Tracer: the block starting at pos
void FUN_142530220(void* tracer, UPInt pos, void* block);   // Tracer::TraceBlock

// Tracer::EmitCode: seeds each exception handler block with its caught type, traces the body from the
// first block, then patches the recorded branch offsets and copies the remapped exception table.
// MS2-FUNCTIONAL 0x1424f7840: raw-offset model of the Tracer (the class is not recovered here)
// @0x1424f7840
void FUN_1424f7840(void* tracer)
{
    typedef ArrayLH_POD<UPInt, StatMV_VM_AbcFile_Mem> CodeType;
    typedef Abc::MethodBodyInfo::ExceptionInfo ExcInfo;
    UByte* const tr = static_cast<UByte*>(tracer);
    if (tr[0x10])
        return;
    UByte* const st = *reinterpret_cast<UByte**>(tr + 0x20);
    VMAbcFile& file = **reinterpret_cast<VMAbcFile**>(st + 0x28);
    UByte* const abc = *reinterpret_cast<UByte**>(reinterpret_cast<UByte*>(&file) + 0x28);
    VM& vm = file.GetVM();
    UByte* const vmb = reinterpret_cast<UByte*>(&vm);
    const Abc::MethodBodyInfo& mbi =
        *(*reinterpret_cast<Abc::MethodBodyInfo* const* const*>(abc + 0x170))[*reinterpret_cast<const int*>(st + 0x30)];
    const ArrayLH_POD<ExcInfo, StatMV_VM_AbcFile_Mem>& ei = mbi.exception.info;
    for (UPInt i = 0; i < ei.GetSize(); ++i)
    {
        const ExcInfo& e = ei[i];
        UByte* b = FUN_1424e6aa0(tr, *reinterpret_cast<void**>(*reinterpret_cast<UByte**>(tr + 0x118) + 0x18), e.from, 0, false);
        if (b)
        {
            *reinterpret_cast<UInt32*>(b + 0x10) &= ~1u;
            *reinterpret_cast<UInt32*>(b + 0x14) |= 2;
        }
        b = FUN_1424e6aa0(tr, *reinterpret_cast<void**>(*reinterpret_cast<UByte**>(tr + 0x118) + 0x18), e.target, 0, false);
        if (!b)
            continue;
        *reinterpret_cast<UInt32*>(b + 0x14) |= 4;
        UByte* const bst = *reinterpret_cast<UByte**>(b + 0x18);
        unsigned flags = 0x48;
        void* rt;
        if (e.exc_type_ind == 0)
            rt = *reinterpret_cast<void**>(*reinterpret_cast<UByte**>(vmb + 0x1f8) + 0xc0);
        else
        {
            const UByte* mn = *reinterpret_cast<UByte**>(abc + 0xb8) + static_cast<SPInt>(e.exc_type_ind) * 0x10;
            const UByte* ct = static_cast<const UByte*>(FUN_142524f60(&vm, &file, mn));
            if (!ct)
            {
                const Value name(file.GetInternedString(*reinterpret_cast<const int*>(mn + 8)));
                const VM::Error err(VM::ErrorID(1014) /* eClassNotFoundError */, vm, name);
                FUN_14252ecb0(&vm, &err, &fl::VerifyErrorCI);
                return;
            }
            rt = *reinterpret_cast<void* const*>(ct + 0xc0);
            if (rt == *reinterpret_cast<void**>(*reinterpret_cast<UByte**>(vmb + 0x220) + 0xc0) ||
                rt == *reinterpret_cast<void**>(*reinterpret_cast<UByte**>(vmb + 0x228) + 0xc0) ||
                rt == *reinterpret_cast<void**>(*reinterpret_cast<UByte**>(vmb + 0x218) + 0xc0) ||
                rt == *reinterpret_cast<void**>(*reinterpret_cast<UByte**>(vmb + 0x210) + 0xc0))
                flags = 8;
        }
        Value v;
        Sfr33TracerValueSet(v, flags, rt, false);
        reinterpret_cast<ArrayDH<Value>*>(bst + 0x38)->PushBack(v);
    }
    FUN_142530220(tr, 0, *reinterpret_cast<void**>(tr + 0x118));
    CodeType& code = **reinterpret_cast<CodeType**>(tr + 0x28);
    if (vm.IsException())
    {
        code.Resize(0);
        return;
    }
    struct Recalc { UPInt pos; SInt32 off; };
    const UPInt* map = *reinterpret_cast<UPInt**>(tr + 0xd0);
    const UPInt mapn = *reinterpret_cast<UPInt*>(tr + 0xd8);
    for (UPInt i = 0; i < *reinterpret_cast<UPInt*>(tr + 0xb8); ++i)
    {
        const Recalc& r = (*reinterpret_cast<Recalc**>(tr + 0xb0))[i];
        UPInt& c = code[r.pos];
        c = c < mapn ? map[c] + r.off - r.pos : 0;
    }
    Abc::MethodBodyInfo::Exception& out = **reinterpret_cast<Abc::MethodBodyInfo::Exception**>(tr + 0x30);
    for (UPInt i = 0; i < ei.GetSize(); ++i)
    {
        const ExcInfo& e = ei[i];
        out.info.PushBack(ExcInfo(static_cast<Abc::SInd>(map[e.from]), static_cast<Abc::SInd>(map[e.to]),
                                  static_cast<Abc::SInd>(map[e.target]), e.exc_type_ind, e.var_name_ind));
    }
    tr[0x10] = 1;
}
extern "C" void FUN_1424df070(void* tracer);   // Tracer::~Tracer (sfr_as3_16, C linkage)

// The interpreter code of the frame's method body, traced from its bytecode on first use.
// MS2-FUNCTIONAL 0x142508330: the local Tracer gets a /GS cookie here (the exe has none) and the frame fields load in another order.
// @0x142508330
const ArrayLH_POD<UPInt, StatMV_VM_AbcFile_Mem>& Sfr33CallFrameGetCode(CallFrame& cf)
{
    typedef ArrayLH_POD<UPInt, StatMV_VM_AbcFile_Mem> CodeType;
    VMAbcFile& file = *cf.pFile;
    UByte* const pf = reinterpret_cast<UByte*>(&file);
    CodeType& code = (*reinterpret_cast<ArrayLH<CodeType, StatMV_VM_VMAbcFile_Mem>*>(pf + 0xb8))[cf.MBIIndex];   // OpCodeArray
    if (code.GetSize() == 0)
    {
        VM& vm = file.GetVM();
        Sfr33TracerStorage tr;
        FUN_1424d9f30(&tr.Q00, reinterpret_cast<UPInt>(vm.GetMemoryHeap()), reinterpret_cast<UPInt>(&cf),
                      reinterpret_cast<UPInt>(&code), reinterpret_cast<UPInt>(&(*reinterpret_cast<ArrayLH<Abc::MethodBodyInfo::Exception,
                          StatMV_VM_VMAbcFile_Mem>*>(pf + 0xd0))[cf.MBIIndex]));   // Exceptions
        if (!vm.IsException())
            FUN_1424f7840(&tr);
        FUN_1424df070(&tr);
    }
    return (*reinterpret_cast<ArrayLH<CodeType, StatMV_VM_VMAbcFile_Mem>*>(pf + 0xb8))[cf.MBIIndex];
}

// MovieRoot::ExecuteActionQueue: runs (and frees) the actions queued on level lvl.
// MS2-FUNCTIONAL 0x1424fa320: iterator fields stored in another order; the exe tail-calls AddToFreeList from the inlined dtor.
// @0x1424fa320
void Sfr33ExecuteActionQueue(MovieRoot* self, MovieRoot::ActionLevel lvl)
{
    MovieRoot::ActionQueueIterator iter(lvl, &self->ActionQueue);
    const MovieRoot::ActionEntry* paction;
    while ((paction = iter.getNext()) != NULL)
        paction->Execute(self);
}

// The same for the actions queued after insertAfter (from the level's start without one).
// MS2-FUNCTIONAL 0x1424fa3b0: iterator fields stored in another order; the exe tail-calls AddToFreeList from the inlined dtor.
// @0x1424fa3b0
void Sfr33ExecuteActionQueueAfter(MovieRoot* self, MovieRoot::ActionLevel lvl, MovieRoot::ActionEntry* insertAfter)
{
    MovieRoot::ActionQueueIterator iter(lvl, &self->ActionQueue, insertAfter);
    const MovieRoot::ActionEntry* paction;
    while ((paction = iter.getNext()) != NULL)
        paction->Execute(self);
}

// Splits a qualified class name at its last '.': pkg gets what is before it, name what follows. False without a
// dot (one at the very start does not count). The strings come from the manager at self+0x348.
// @0x142500680
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

bool Sfr33SplitQualifiedName(const UByte* self, const char* qname, ASString& pkg, ASString& name)
{
    const char* dot = Sfr33FindLastDot(qname);
    if (!dot)
        return false;
    const UPInt plen = static_cast<unsigned>(dot - qname);
    name = ASString((*reinterpret_cast<ASStringManager* const*>(self + 0x348))->CreateStringNode(qname + plen + 1));
    pkg = ASString((*reinterpret_cast<ASStringManager* const*>(self + 0x348))->CreateStringNode(qname, plen));
    return true;
}
// TR::State::ConvertOpTo: the operand stack top (+0x38) becomes a value of traits tr.
// MS2-FUNCTIONAL 0x1424f1e50: the exe inlines the weak-reference release of the temporary Value (ours calls ReleaseWeakRef).
// @0x1424f1e50
void Sfr33StateConvertOpTo(UByte* st, InstanceTraits::Traits& tr, Value::TraceNullType isNull)
{
    Value v(tr, isNull);
    ArrayDH<Value>& os = *reinterpret_cast<ArrayDH<Value>*>(st + 0x38);
    os[os.GetSize() - 1].Assign(v);
}

// TR::State::ConvertRegisterTo: register ind (+0x18) becomes a value of traits tr.
// MS2-FUNCTIONAL 0x1424f1ed0: the exe inlines the weak-reference release of the temporary Value (ours calls ReleaseWeakRef).
// @0x1424f1ed0
void Sfr33StateConvertRegisterTo(UByte* st, UInt32 ind, InstanceTraits::Traits& tr, Value::TraceNullType isNull)
{
    Value v(tr, isNull);
    (*reinterpret_cast<ArrayDH<Value>*>(st + 0x18))[ind].Assign(v);
}


// The slot of tr in ns among the slots named like the chain starting at values (protected ones match by kind,
// private ones by identity, the rest by uri), or NULL; index receives the slot index last looked at.
static SF_INLINE const SlotInfo* Sfr33FindSlotInChain(const Traits& tr, const UInt32* values,
                                                      const Instances::Namespace& ns, UPInt& index)
{
    if (values)
    {
        SPInt ind = *values;
        do
        {
            index = ind;
            const SlotInfo* si;
            if (ind < 0 || static_cast<UPInt>(ind) < tr.FirstOwnSlotNum)
                si = &tr.Parent->GetSlotInfo(AbsoluteIndex(ind));
            else
                si = &tr.VArray[static_cast<UInt32>(ind) - tr.FirstOwnSlotNum].Value;
            const Instances::Namespace& sns = *si->pNs;
            const unsigned kind = ns.GetKind();
            if (sns.GetKind() == kind)
            {
                if (kind == Abc::NS_Protected)
                    return si;
                if (kind == Abc::NS_Private ? &ns == &sns : sns.GetUri().GetNode() == ns.GetUri().GetNode())
                    return si;
            }
            if (static_cast<UPInt>(ind) < tr.FirstOwnSlotNum)
                ind = tr.Parent->GetPrevSlotIndex(ind);
            else
                ind = tr.VArray[static_cast<UInt32>(ind) - tr.FirstOwnSlotNum].Prev;
        } while (ind >= 0);
    }
    return NULL;
}

// The fixed slot of tr named name in ns, own or a parent's, or NULL; index receives its slot index. Object obj
// may initialize it on demand.
// MS2-FUNCTIONAL 0x1425011c0: the prologue differs (exe also saves rsi) and the exe splits the loop into chunks.
// @0x1425011c0
const SlotInfo* FindFixedSlot(const Traits& tr, const ASString& name, const Instances::Namespace& ns, UPInt& index,
                              Object* obj)
{
    const SlotInfo* si = Sfr33FindSlotInChain(tr, tr.FindSlotValues(name), ns, index);
    if (obj)
        return obj->InitializeOnDemand(si, name, ns, index);
    return si;
}

// The fixed slot of tr that mn names (the first namespace of a set that has one), or NULL.
// MS2-FUNCTIONAL 0x142500f90: the register assignment and frame differ (exe frame 0x70, r14) and the exe splits the loops into chunks.
// @0x142500f90
const SlotInfo* FindFixedSlot(VM& vm, const Traits& tr, const Multiname& mn, UPInt& index, Object* obj)
{
    ASString name = vm.GetStringManager().GetBuiltin(AS3Builtin_empty_);
    const SlotInfo* si = NULL;
    if (mn.Name.Convert2String(name))
    {
        if (mn.IsQName())
            si = FindFixedSlot(tr, name, *static_cast<const Instances::Namespace*>(mn.Obj.GetPtr()), index, obj);
        else
        {
            const ArrayLH<SPtr<Instances::Namespace> >& nss =
                static_cast<const NamespaceSet*>(mn.Obj.GetPtr())->GetNamespaces();
            const UInt32* values = tr.FindSlotValues(name);
            for (UPInt i = 0; i < nss.GetSize(); ++i)
            {
                const Instances::Namespace& ns = *nss[i];
                si = Sfr33FindSlotInChain(tr, values, ns, index);
                if (obj)
                    si = obj->InitializeOnDemand(si, name, ns, index);
                if (si)
                    break;
            }
        }
    }
    return si;
}

// MS2-FUNCTIONAL 0x1424efd80: the exe saves rsi/rdi where ours pushes rbp/r14 (register assignment); same code.
// @0x1424efd80
void CallFrame::ClearScopeStack()
{
    pScopeStack->Resize(ScopeStackBaseInd);
}

// The slot of c named name in namespace ns (same uri and kind), or NULL; FindDynamicSlot, inlined.
static SF_INLINE const SlotInfo* Sfr33FindDynamicSlotIn(const SlotContainerType& c, const ASString& name,
                                                        const Instances::Namespace& ns)
{
    const SPInt* values = c.FindValues(name);
    if (values)
    {
        for (SPInt ind = *values; ind >= 0; ind = c.VArray[static_cast<UPInt>(ind)].Prev)
        {
            const SlotInfo& si = c.VArray[static_cast<UInt32>(ind)].Value;
            if (*si.pNs == ns)
                return &si;
        }
    }
    return NULL;
}

// The dynamic slot of c that mn names (the first namespace of a set that has one), or NULL.
// MS2-FUNCTIONAL 0x142500c40: the register assignment and frame layout differ and the exe splits the loops into chunks.
// @0x142500c40
const SlotInfo* FindDynamicSlot(VM& vm, const SlotContainerType& c, const Multiname& mn)
{
    ASString name = vm.GetStringManager().CreateEmptyString();
    const SlotInfo* si = NULL;
    if (mn.Name.Convert2String(name))
    {
        if (mn.IsQName())
            si = Sfr33FindDynamicSlotIn(c, name, *static_cast<const Instances::Namespace*>(mn.Obj.GetPtr()));
        else
        {
            const ArrayLH<SPtr<Instances::Namespace> >& nss =
                static_cast<const NamespaceSet*>(mn.Obj.GetPtr())->GetNamespaces();
            for (UPInt i = 0; i < nss.GetSize(); ++i)
            {
                si = Sfr33FindDynamicSlotIn(c, name, *nss[i]);
                if (si)
                    break;
            }
        }
    }
    return si;
}


// A property lookup that found something (not undefined, not a tagged null value).
static SF_INLINE bool Sfr33PropFound(const PropRef& prop)
{
    const UPInt bits = reinterpret_cast<UPInt>(prop.pValue);
    if (prop.This.GetKind() == Value::kUndefined || bits == 1)
        return false;
    return !((bits & 2) != 0 && (bits & ~UPInt(2)) == 0);
}

void Sfr33FindScopeProperty(PropRef& result, VM& vm, UPInt baseSSInd, const ScopeStackType& scope_stack,
                            const Multiname& mn);

// MS2-FUNCTIONAL 0x142502360: the exe move-assigns the dynamic lookup result (0x1424e0b40) and allocates registers differently.
// @0x142502360
void Object::FindProperty(PropRef& result, const Multiname& mn, int attr)
{
    UPInt index = 0;
    Traits& tr = GetTraits();
    const SlotInfo* si = FindFixedSlot(GetVM(), tr, mn, index, this);
    if (si)
    {
        result.pSI = si;
        result.SlotIndex = index;
        result.This = Value(this);
        return;
    }
    if (tr.IsDynamic() && (attr != 2 || tr.GetTraitsType() != Traits_XML || tr.IsClassTraits()))
        result = FindDynamicSlot(mn);
    if (Sfr33PropFound(result) || attr == 1)
        return;
    for (const Traits* t = &GetTraits(); t; t = t->GetParent())
    {
        Object* proto = &t->GetConstructor().GetPrototype();
        if (proto == this)
            break;
        proto->FindProperty(result, mn, attr);
        if (Sfr33PropFound(result))
            return;
    }
}

// The property named mn seen through scope value scope (a with scope or the global object also looks at its
// dynamic values and prototypes; a function falls back to its saved scope).
// MS2-FUNCTIONAL 0x142502690: the exe move-assigns the dynamic lookup result (0x1424e0b40), calls IsXMLObject out of line and allocates registers differently.
// @0x142502690
void Sfr33FindPropertyWith(PropRef& result, VM& vm, const Value& scope, const Multiname& mn, int attr)
{
    const unsigned kind = scope.GetKind();
    const bool isObj = kind >= Value::kObject && kind <= Value::kFunction;
    const Traits& tr = FUN_14250ffc0(vm, scope);
    Object* obj = isObj ? scope.GetObject() : NULL;
    UPInt index = 0;
    const SlotInfo* si = FindFixedSlot(vm, tr, mn, index, obj);
    if (si)
    {
        result.pSI = si;
        result.SlotIndex = index;
        result.This = scope;
        return;
    }
    if (!tr.IsGlobal() && !scope.GetWith())
        return;
    if (isObj && tr.IsDynamic() && (attr != 2 || !IsXMLObject(scope)))
        result = obj->FindDynamicSlot(mn);
    if (Sfr33PropFound(result) || attr == 1)
        return;
    for (const Traits* t = &tr; t; t = t->GetParent())
    {
        PropRef tmp;
        t->GetConstructor().GetPrototype().FindProperty(tmp, mn, attr);
        if (Sfr33PropFound(tmp))
        {
            result.pSI = NULL;
            result.SlotIndex = 0;
            result.This = scope;
            break;
        }
    }
    if (!Sfr33PropFound(result) && scope.GetKind() == Value::kFunction)
        Sfr33FindScopeProperty(result, vm, 0,
                               *reinterpret_cast<const ScopeStackType*>(reinterpret_cast<const UByte*>(scope.GetObject()) + 0x40),
                               mn);
}

// The property named mn in the scope values above baseSSInd, innermost first.
// MS2-FUNCTIONAL 0x142502a80: rbp/rsi swapped in the register assignment and the exe lays out the found test differently.
// @0x142502a80
void Sfr33FindScopeProperty(PropRef& result, VM& vm, UPInt baseSSInd, const ScopeStackType& scope_stack,
                            const Multiname& mn)
{
    for (UPInt i = scope_stack.GetSize(); i > baseSSInd; --i)
    {
        Sfr33FindPropertyWith(result, vm, scope_stack[i - 1], mn, 0);
        if (Sfr33PropFound(result))
            return;
    }
}


// Tracer::CanBeNull of a traced value: values of class traits are never null, others go by their instance traits.
// MS2-FUNCTIONAL 0x1424ee9e0: the exe orders the tracer kind tests differently (block layout).
// @0x1424ee9e0
Value::TraceNullType Sfr33TracerCanBeNullValue(const UByte* self, const Value& v)
{
    const UByte* pfile = *reinterpret_cast<const UByte* const*>(*reinterpret_cast<const UByte* const*>(self + 0x20) + 0x28);
    VM& vm = **reinterpret_cast<VM* const*>(pfile + 0x20);
    const Traits* tr;
    const unsigned kind = v.GetKind();
    if (kind == Value::kUndefined)
        tr = vm.TraitsVoid.GetPtr();
    else if (kind == Value::kInstanceTraits || kind == Value::kClassTraits)
        tr = *reinterpret_cast<const Traits* const*>(reinterpret_cast<const UByte*>(&v) + 0x10);
    else
        tr = &FUN_14250ffc0(vm, v);
    if (tr)
    {
        if (tr == vm.TraitsClassClass.GetPtr())
            tr = vm.TraitsObject.GetPtr();
        if (tr)
        {
            if (tr->IsClassTraits())
                return Value::NotNull;
            return Sfr33TracerCanBeNull(self, reinterpret_cast<const InstanceTraits::Traits*>(tr));
        }
    }
    return Value::NullOrNot;
}

// Clears the slot memory of a new instance (Value slots undefined, object and string pointers null).
// MS2-FUNCTIONAL 0x1424f0a50: the exe inlines the own-slot / parent-slot index split around Slots::GetSlotInfo.
// @0x1424f0a50
void Traits::ConstructTail(Object& obj) const
{
    const UPInt size = GetSlotInfoNum();
    for (UPInt i = 0; i < size; ++i)
    {
        const SlotInfo& si = GetSlotInfo(AbsoluteIndex(i));
        if (si.CppBinding)
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

// MS2-FUNCTIONAL 0x142507210: the exe inlines the PushBack of each SPtr copy; same results
// @0x142507210
UPInt VM::GetAllLoadedAbcFiles(Scaleform::Array<SPtr<VMAbcFile> >* destArray) const
{
    if (InDestructor)
        return 0;
    const UPInt size = VMAbcFilesWeak.GetSize();
    if (size == 0)
        return 0;
    UPInt i = 0;
    do
    {
        destArray->PushBack(SPtr<VMAbcFile>(VMAbcFilesWeak[i]));
        ++i;
    } while (i < size);
    return i;
}

// Releases the slot memory of a dying instance, last slot first (Value slots, tagged object pointers, strings).
// MS2-FUNCTIONAL 0x1424f6de0: the exe inlines the own-slot / parent-slot index split around Slots::GetSlotInfo.
// @0x1424f6de0
void Traits::DestructTail(Object& obj) const
{
    for (UPInt i = GetSlotInfoNum(); i > 0; --i)
    {
        const SlotInfo& si = GetSlotInfo(AbsoluteIndex(i - 1));
        if (si.CppBinding)
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
                    if (raw & 1)
                        ptr = raw - 1;
                    else
                        reinterpret_cast<ASRefCountBaseType*>(raw & ~UPInt(6))->Release();
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

// MS2-FUNCTIONAL 0x1424f12a0: the exe folds the kind tests into range checks where MSVC-clang emits a jump table.
// @0x1424f12a0
CheckResult Value::Convert2PrimitiveValueUnsafe(Value& result, Hint hint) const
{
    switch (GetKind())
    {
    case kUndefined:
    case kBoolean:
    case kInt:
    case kUInt:
    case kNumber:
    case kString:
        result.Assign(*this);
        return true;
    case kThunk:
    case kVTableInd:
    case kThunkClosure:
    case kVTableIndClosure:
        result.SetNumber(0.0);
        return true;
    case kNamespace:
        result = GetNamespace()->GetUri();
        return true;
    case kObject:
    case kClass:
    case kFunction:
    case kThunkFunction:
        if (!GetObject())
        {
            result.Assign(*this);
            return true;
        }
        break;
    default:
        break;
    }
    FUN_142508bd0(reinterpret_cast<UPInt>(GetObject()), &result, hint);
    return !GetObject()->GetVM().IsException();
}

// The out-of-line copy of Value::Convert2NumberInline.
extern CheckResult (Value::* const pSfr33Convert2NumberInline)(Value::Number&) const;
CheckResult (Value::* const pSfr33Convert2NumberInline)(Value::Number&) const = &Value::Convert2NumberInline;

// ToString. Numbers use the ECMA formatting; an object goes through its primitive value (hint String), which must
// come back primitive.
// MS2-FUNCTIONAL 0x1424f1390: the exe shares the string-assign tails between cases; same results
// @0x1424f1390
CheckResult Value::Convert2String(ASString& result) const
{
    ASStringManager* sm = result.GetManager();
    switch (GetKind())
    {
    case kUndefined:
        result.AssignNode(sm->CreateConstStringNode("undefined", 9, 0));
        break;
    case kBoolean:
        {
            const bool b = AsBool();
            result.AssignNode(sm->CreateConstStringNode(b ? "true" : "false", b ? 4 : 5, 0));
        }
        break;
    case kInt:
        {
            const String str = Scaleform::AsString(AsInt());
            result = sm->CreateString(str.ToCStr(), str.GetSize());
        }
        break;
    case kUInt:
        {
            const String str = Scaleform::AsString(AsUInt());
            result = sm->CreateString(str.ToCStr(), str.GetSize());
        }
        break;
    case kNumber:
        {
            char buffer[40];
            const UPInt len = FUN_142525f20(buffer, sizeof(buffer), AsNumber());
            result.AssignNode(sm->CreateStringNode(buffer, len));
        }
        break;
    case kThunk:
    case kVTableInd:
    case kThunkClosure:
    case kVTableIndClosure:
        result.AssignNode(sm->CreateConstStringNode("function Function() {}", 22, 0));
        break;
    case kInstanceTraits:
    case kClassTraits:
        result.AssignNode(sm->GetEmptyStringNode());
        break;
    case kString:
        if (GetStringNode())
            result.AssignNode(GetStringNode());
        else
            result.AssignNode(sm->CreateConstStringNode("null", 4, 0));
        break;
    case kNamespace:
        result = AsNamespace().GetUri();
        break;
    case kObject:
    case kClass:
    case kFunction:
    case kThunkFunction:
        if (IsNull())
            result.AssignNode(sm->CreateConstStringNode("null", 4, 0));
        else
        {
            Value v;
            if (!Convert2PrimitiveValueUnsafe(v, hintString))
                return false;
            if (!v.IsPrimitive())
            {
                VM& vm = v.GetObject()->GetVM();
                const VM::Error e(VM::ErrorID(1050), vm, FUN_14250ffc0(vm, v).GetName().ToCStr());   // eConvertToPrimitiveError
                FUN_14252ecb0(&vm, &e, &fl::TypeErrorCI);
                return false;
            }
            return v.Convert2String(result);
        }
        break;
    default:
        break;
    }
    return true;
}

// ToString appended to a buffer; same cases as above, without the primitive check on an object's value.
// MS2-FUNCTIONAL 0x1424f17a0: the exe shares the AppendString tail between cases; same results
// @0x1424f17a0
CheckResult Value::Convert2String(StringBuffer& result) const
{
    switch (GetKind())
    {
    case kUndefined:
        result.AppendString("undefined");
        break;
    case kBoolean:
        result.AppendString(AsBool() ? "true" : "false");
        break;
    case kInt:
        {
            const String str = Scaleform::AsString(AsInt());
            result.AppendString(str.ToCStr(), str.GetSize());
        }
        break;
    case kUInt:
        {
            const String str = Scaleform::AsString(AsUInt());
            result.AppendString(str.ToCStr(), str.GetSize());
        }
        break;
    case kNumber:
        {
            char buffer[40];
            const UPInt len = FUN_142525f20(buffer, sizeof(buffer), AsNumber());
            result.AppendString(buffer, len);
        }
        break;
    case kThunk:
    case kVTableInd:
    case kThunkClosure:
    case kVTableIndClosure:
        result.AppendString("function Function() {}");
        break;
    case kString:
        if (const ASStringNode* node = GetStringNode())
            result.AppendString(node->pData, node->Size);
        else
            result.AppendString("null");
        break;
    case kNamespace:
        result.AppendString(AsNamespace().GetUri().ToCStr());
        break;
    case kObject:
    case kClass:
    case kFunction:
    case kThunkFunction:
        if (IsNull())
            result.AppendString("null");
        else
        {
            Value v;
            if (!Convert2PrimitiveValueUnsafe(v, hintString))
                return false;
            return v.Convert2String(result);
        }
        break;
    default:
        break;
    }
    return true;
}

// ToInt32: undefined, thunks and null are 0; strings go through ToNumber, objects through their primitive value.
// MS2-FUNCTIONAL 0x1424f0d30: the exe duplicates the release of the primitive temporary on each exit; same results
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
    case kBoolean:
        result = AsBool() ? 1 : 0;
        break;
    case kInt:
    case kUInt:
    case kVTableInd:
        result = value.VS._1.VInt;
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
            return v.Convert2Int32(result);
        }
        break;
    }
    return true;
}

// The property named mn of the object value stands for: its fixed slots, then (public names only) its dynamic
// values and the prototypes of its traits; a function falls back to its saved scope.
// MS2-FUNCTIONAL 0x142501b00: the exe copies the value through a temporary before the assignment, move-assigns the dynamic lookup result and calls IsXMLListObject out of line.
// @0x142501b00
void Sfr33FindObjProperty(PropRef& result, VM& vm, const Value& value, const Multiname& mn, int attr)
{
    const unsigned kind = value.GetKind();
    const bool isObj = kind >= Value::kObject && kind <= Value::kFunction;
    const Traits* tr = &FUN_14250ffc0(vm, value);
    Object* obj = isObj ? value.GetObject() : NULL;
    UPInt index = 0;
    const SlotInfo* si = FindFixedSlot(vm, *tr, mn, index, obj);
    if (si)
    {
        result.pSI = si;
        result.SlotIndex = index;
        result.This = value;
        return;
    }
    if (!mn.ContainsNamespace(vm.GetPublicNamespace()))
        return;
    if (isObj && tr->IsDynamic() && (attr != 2 || !IsXMLListObject(value)))
        result = obj->FindDynamicSlot(mn);
    if (Sfr33PropFound(result) || attr == 1)
        return;
    for (; tr; tr = tr->GetParent())
    {
        tr->GetConstructor().GetPrototype().FindProperty(result, mn, attr);
        if (Sfr33PropFound(result))
            break;
    }
    if (!Sfr33PropFound(result) && value.GetKind() == Value::kFunction)
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
    if (!l.HasSimpleContent())
        return true;
    StringBuffer buf(Memory::GetGlobalHeap());
    ASString str = l.GetVM().GetStringManager().CreateEmptyString();
    l.ToString(buf, 0);
    if (!r.Convert2String(str))
        return false;
    result = strncmp(buf.ToCStr(), str.ToCStr(), str.GetSize()) == 0;
    stop = true;
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
// MS2-FUNCTIONAL 0x1424f4a90: our own reading of the exe; hash orders and string temporaries not reproduced
// @0x1424f4a90
void XMLSupportImpl::DescribeType(VM& vm, SPtr<Instances::fl::XML>& result, const Value& value) const
{
    typedef Instances::fl::XMLElement XMLElement;
    StringManager& sm = vm.GetStringManager();
    const Instances::Namespace& pns = vm.GetPublicNamespace();
    const ASString strTrue = sm.GetBuiltin(AS3Builtin_true);
    const ASString strFalse = sm.GetBuiltin(AS3Builtin_false);
    const ASString strType = sm.CreateConstString("type");
    const Traits& tr = FUN_14250ffc0(vm, value);
    const Value::KindType kind = value.GetKind();
    const bool isClass = kind == Value::kClass;
    const Traits* parent = isClass ? static_cast<const Traits*>(&vm.GetClassTraitsClassClass()) : tr.GetParent();
    InstanceTraits::fl::XML& itr = static_cast<InstanceTraits::fl::XML&>(*GetITraitsXML());
    SPtr<XMLElement> xml = itr.MakeInstanceElement(itr, pns, strType, NULL);
    result = xml.GetPtr();

    const bool isObjKind = kind >= Value::kObject && kind <= Value::kThunkFunction;
    if (kind == Value::kUndefined || (isObjKind && value.GetObject() == NULL))
    {
        xml->AddAttr(pns, sm.CreateConstString("name"), isObjKind ? sm.CreateConstString("null") : tr.GetQualifiedName());
        xml->AddAttr(pns, sm.CreateConstString("isDynamic"), strFalse);
        xml->AddAttr(pns, sm.CreateConstString("isFinal"), strTrue);
        xml->AddAttr(pns, sm.CreateConstString("isStatic"), strFalse);
        return;
    }

    xml->AddAttr(pns, sm.CreateConstString("name"), tr.GetQualifiedName());
    if (parent)
        xml->AddAttr(pns, sm.CreateConstString("base"), parent->GetQualifiedName());
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
            el->AddAttr(pns, strType, t->GetQualifiedName());
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

    SPtr<XMLElement> cur = xml;
    if (isClass)
    {
        SPtr<XMLElement> factory = itr.MakeInstanceElement(itr, pns, sm.CreateConstString("factory"), NULL);
        if (!xml->AppendChild(Value(factory.GetPtr())))
            return;
        factory->AddAttr(pns, strType, tr.GetQualifiedName());
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
                el->AddAttr(pns, strType, dt->GetQualifiedName());
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
                typeName = vt->GetQualifiedName();
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
        el->AddAttr(pns, strDeclaredBy, declTr.GetQualifiedName());
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

void FUN_142415930(Instances::fl::XMLList* self, Instances::fl::XMLList& list, const Multiname& prop_name);

// The descendants named mn of an XML or XMLList instance v, as a new list that replaces v; false for anything else.
// MS2-FUNCTIONAL 0x142509140: XMLList::GetDescendants called through its free-function form
// @0x142509140
CheckResult XMLSupportImpl::GetDescendants(Value& v, const Multiname& mn) const
{
    if (!v.IsObject() || v.GetObject() == NULL)
        return false;
    Object* obj = v.GetObject();
    const Traits& tr = obj->GetTraits();
    const BuiltinTraitsType tt = tr.GetTraitsType();
    if (tt == Traits_XML && tr.IsInstanceTraits())
    {
        InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(*GetITraitsXMLList());
        Pickable<Instances::fl::XMLList> list = itr.MakeInstance(itr);
        static_cast<Instances::fl::XML*>(obj)->GetDescendants(*list, mn);
        v.Pick(list);
        return true;
    }
    if (tt == Traits_XMLList && tr.IsInstanceTraits())
    {
        InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(*GetITraitsXMLList());
        Pickable<Instances::fl::XMLList> list = itr.MakeInstance(itr);
        FUN_142415930(static_cast<Instances::fl::XMLList*>(obj), *list, mn);
        v.Pick(list);
        return true;
    }
    return false;
}

// VM::ExecutePropertyUnsafe: calls the property prop_name of _this with argv; a null or undefined property is a
// TypeError (#1009). False when the property is missing or its value could not be read, or the call threw.
// MS2-FUNCTIONAL 0x1424ff910: PropRef::GetSlotValueUnsafe called out of line (the exe inlines its dispatch)
// @0x1424ff910
CheckResult ExecutePropertyUnsafe(VM& vm, const Multiname& prop_name, const Value& _this, Value& result, unsigned argc,
                                  const Value* argv)
{
    PropRef prop;
    Sfr33FindObjProperty(prop, vm, _this, prop_name, 0);
    if (!Sfr33PropFound(prop))
        return false;
    Value func;
    if (!prop.GetSlotValueUnsafe(vm, func))
        return false;
    if (func.IsNullOrUndefined())
    {
        const VM::Error e(VM::eConvertNullToObjectError, vm);
        FUN_14252ecb0(&vm, &e, &fl::TypeErrorCI);
        return false;
    }
    vm.ExecuteInternalUnsafe(func, _this, result, argc, argv, false);
    return !vm.IsException();
}

// The property named mn of the first global object (of the ABC file of tr, when given) that has one.
// MS2-FUNCTIONAL 0x142501750: the exe builds the object value in place with the reference count bits inlined.
// @0x142501750
void Sfr33FindGOProperty(PropRef& result, VM& vm, const ArrayLH<Instances::fl::GlobalObject*>& go, const Multiname& mn,
                         const Traits* tr)
{
    VMAbcFile* file = tr ? tr->GetFilePtr() : NULL;
    const UPInt size = go.GetSize();
    for (UPInt i = 0; i < size; ++i)
    {
        Object* obj = reinterpret_cast<Object*>(go[i]);
        if (tr && obj->GetTraits().GetFilePtr() != file)
            continue;
        Sfr33FindPropertyWith(result, vm, Value(obj), mn, 0);
        if (Sfr33PropFound(result))
            return;
    }
}

// Tracer State::FindProp: the fixed slot mn names, looked up statically through the traced scope stack (State +0x58,
// innermost first; stype 0), then the function's saved scopes (stype 1), then the class or global object that
// defines it (stype 2); scope_index is the stack index tried last. A run-time name or a with scope stops the search.
// MS2-FUNCTIONAL 0x142501e80: raw tracer state, VM and traits offsets
// @0x142501e80
void FUN_142501e80(void* state, void* propRef, void* multiname, void* stypeOut, void* scopeIndexOut)
{
    PropRef& result = *static_cast<PropRef*>(propRef);
    const Multiname& mn = *static_cast<const Multiname*>(multiname);
    UInt32& stype = *static_cast<UInt32*>(stypeOut);
    UPInt& scope_index = *static_cast<UPInt*>(scopeIndexOut);
    const UInt32 mnKind = static_cast<UInt32>(mn.Kind);
    if ((mnKind & 3) == 1 || ((mnKind >> 2) & 1) != 0)
        return;
    const UPInt* st = static_cast<const UPInt*>(state);
    const UPInt tracer = st[0];
    VM& vm = **reinterpret_cast<VM**>(*reinterpret_cast<const UPInt*>(*reinterpret_cast<const UPInt*>(tracer + 0x20) + 0x28) + 0x20);
    const UByte* const vmb = reinterpret_cast<const UByte*>(&vm);
    UPInt index = 0;
    const Value* ss = reinterpret_cast<const Value*>(st[0xb]);
    for (UPInt i = st[0xc]; i > 0; )
    {
        scope_index = --i;
        const Value& v = ss[i];
        const unsigned kind = v.GetKind();
        const Traits* tr;
        if (kind == 0)
            tr = *reinterpret_cast<Traits* const*>(vmb + 0x278);
        else if (kind == 8 || kind == 9)
            tr = *reinterpret_cast<Traits* const*>(reinterpret_cast<const UByte*>(&v) + 0x10);
        else
            tr = &FUN_14250ffc0(vm, v);
        if (tr && tr == *reinterpret_cast<Traits* const*>(vmb + 0x1f0))
            tr = *reinterpret_cast<Traits* const*>(vmb + 0x1f8);
        if (v.GetWith())
            return;
        if (tr && !tr->IsGlobal())
        {
            if (const SlotInfo* si = FindFixedSlot(vm, *tr, mn, index, NULL))
            {
                stype = 0;
                result.pSI = si;
                result.SlotIndex = index;
                result.This = v;
                return;
            }
        }
    }
    const UPInt* saved = *reinterpret_cast<UPInt* const*>(*reinterpret_cast<const UPInt*>(tracer + 0x20) + 0x38);
    if (saved)
    {
        const Value* sv = reinterpret_cast<const Value*>(saved[0]);
        for (UPInt i = saved[1]; i > 0; )
        {
            scope_index = --i;
            const Value& v = sv[i];
            const Traits& tr = FUN_14250ffc0(vm, v);
            if (v.GetWith())
                return;
            if (const SlotInfo* si = FindFixedSlot(vm, tr, mn, index, NULL))
            {
                stype = 1;
                result.pSI = si;
                result.SlotIndex = index;
                result.This = v;
                return;
            }
        }
    }
    const unsigned nameKind = mn.Name.GetKind();
    if (nameKind == 8 || nameKind == 9)
        return;
    const Traits* ct = ::FUN_14250d760(vm, mn);
    if (ct)
    {
        if (const UByte* itr = *reinterpret_cast<UByte* const*>(reinterpret_cast<const UByte*>(ct) + 0xc0))
        {
            Object* obj = ((itr[0x68] >> 4) & 1) == 0 ? *reinterpret_cast<Object* const*>(vmb + 0x298)
                                                      : *reinterpret_cast<Object* const*>(itr + 0xd0);
            UPInt oindex = 0;
            if (const SlotInfo* si = FindFixedSlot(vm, obj->GetTraits(), mn, oindex, obj))
            {
                result.pSI = si;
                result.SlotIndex = oindex;
                result.This = Value(obj);
                stype = 2;
                return;
            }
        }
    }
    Sfr33FindGOProperty(result, vm, *reinterpret_cast<const ArrayLH<Instances::fl::GlobalObject*>*>(vmb + 0x1a8), mn, ct);
    if (Sfr33PropFound(result))
        stype = 2;
}

// Object::DeleteDynamicSlotValuePair: removes the dynamic property prop_name names (namespaces are not looked at).
// MS2-FUNCTIONAL 0x1424f4540: the exe inlines the hash probe and removal; same results
// @0x1424f4540
CheckResult Object::DeleteDynamicSlotValuePair(const Multiname& prop_name)
{
    ASString name = GetVM().GetStringManager().CreateEmptyString();
    if (!prop_name.Name.Convert2String(name))
        return false;
    if (!DynAttrs.Get(DynAttrsKey(name)))
        return false;
    DynAttrs.Remove(DynAttrsKey(name));
    return true;
}

// The dynamic value of this object that mn names (namespaces are not looked at).
// MS2-FUNCTIONAL 0x142500e50: the exe inlines the dynamic-attribute hash probe and splits the unwind info into chained chunks.
// @0x142500e50
PropRef Object::FindDynamicSlot(const Multiname& mn)
{
    ASString name = GetVM().GetStringManager().CreateEmptyString();
    if (mn.Name.Convert2String(name))
        return PropRef(this, DynAttrs.Get(DynAttrsKey(name)));
    return PropRef();
}

// The property named mn seen from the current call: the scope stack above the frame's base, the frame's saved
// scope, then the global objects of the ABC file that defines mn's traits.
// MS2-FUNCTIONAL 0x142502570: the exe reloads the frame-stack page pointer for the saved scope and inlines the PropRef found test differently.
// @0x142502570
void Sfr33VMFindProperty(VM& vm, PropRef& result, const Multiname& mn)
{
    const UPInt n = vm.Unk070[1];
    const UByte* top = reinterpret_cast<const UByte* const*>(vm.Unk070[4])[(n - 1) >> 6] + ((n - 1) & 0x3f) * 0xa8;
    const UPInt base = n ? *reinterpret_cast<const UPInt*>(top + 8) : 0;
    Sfr33FindScopeProperty(result, vm, base, vm.ScopeStack, mn);
    if (!Sfr33PropFound(result))
    {
        const ScopeStackType* saved = *reinterpret_cast<const ScopeStackType* const*>(top + 0x38);
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
    Value v;
    v.AssignUnsafe(s.GetNode());
    Root()->ASValue2GFxValue(v, pvalue);
}

// @0x1424f42d0
void Sfr33MovieRootStrings::CreateStringW(GFx::Value* pvalue, const wchar_t* pstring)
{
    ASString s(Root()->BuiltinsMgr.GetStringManager()->CreateStringNode(pstring));
    Value v;
    v.AssignUnsafe(s.GetNode());
    Root()->ASValue2GFxValue(v, pvalue);
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
        Value _this(reinterpret_cast<Object*>(ToAvmDisplayObj(pCharacter)->GetAS3Obj()));
        Value result;
        VM* vm = proot->pAVM;
        vm->ExecuteInternalUnsafe(Function, _this, result, 0, NULL, false);
        if (vm->IsException())
        {
            vm->OutputAndIgnoreException();
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
void Sfr33UserDefinedFunctionExecute(void* self, const Value& _this, unsigned argc, const Value* argv,
                                     bool discard_result)
{
    Value result;
    FUN_1424feb00(self, _this, result, argc, argv);
    if (!discard_result)
        FUN_14241e4f0(self, result);
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
        ASString name(BuiltinsMgr.GetBuiltin(AS3Builtin_empty_));
        void* cls = *reinterpret_cast<void**>(avm + 0x390);
        GetMouseCursorTypeString(name, newCursorType);
        SPtr<Object> evt;
        FUN_1424674c0(cls, evt, name, mouseIdx);
        Instances::fl_display::DisplayObject* stage =
            ToAvmInteractiveObj(static_cast<InteractiveObject*>(pStage))->GetAS3Obj();
        if (stage && !FUN_142468740(stage, evt, pStage))
            return;
    }
    UserEventHandler* handler = pMovieImpl->pUserEventHandler;
    if (handler)
        handler->HandleEvent(pMovieImpl->AsMovie(), MouseCursorEvent(static_cast<MouseCursorEvent::CursorShapeType>(newCursorType),
                                                          mouseIdx));
}

// MovieRoot::CreateArray (virtual): a host value holding a new empty Array.
struct Sfr33MovieRootArray
{
    MovieRoot* Root() { return reinterpret_cast<MovieRoot*>(this); }
    void CreateArray(GFx::Value* pvalue);
};

// MS2-FUNCTIONAL 0x1424f2700: the exe inlines VM::MakeArray (the Array traits' MakeInstance call).
// @0x1424f2700
void Sfr33MovieRootArray::CreateArray(GFx::Value* pvalue)
{
    Value v(Root()->pAVM->MakeArray());
    Root()->ASValue2GFxValue(v, pvalue);
}

// MovieRoot::DoActions (virtual): the pending constructors, then the actions of every level up to AL_Render; a
// pending exception is dropped.
// MS2-FUNCTIONAL 0x1424f73d0: the exe inlines ExecuteCtors and the per-level queue run.
// @0x1424f73d0
void Sfr33MovieRootDoActions(MovieRoot* self)
{
    Sfr33MovieRootExecuteCtors(reinterpret_cast<UByte*>(self));
    for (unsigned lvl = MovieRoot::AL_Highest; lvl < MovieRoot::AL_Count_; ++lvl)
        Sfr33ExecuteActionQueue(self, static_cast<MovieRoot::ActionLevel>(lvl));
    UByte* vm = reinterpret_cast<UByte*>(self->pAVM);
    if (vm[0x180])
        vm[0x180] = 0;
}

// Releases the value the slot si binds in obj (a Value, an object pointer or a string node).
// MS2-FUNCTIONAL 0x1424f6b30: the exe keeps the extra tag bits (1..2) of the object pointer when clearing its mark.
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
        reinterpret_cast<SPtr<Object>*>(p)->~SPtr();
        break;
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
        VM::Error e(VM::eUndefinedVarError, vm, gname.ToCStr());
        FUN_14252ecb0(&vm, &e, &fl::ReferenceErrorCI);
    }
    return false;
}

// The value of a tagged object address (bits 1..2: object, class, function, namespace).
// MS2-FUNCTIONAL 0x142506d60: the exe inlines the object/class assignment and calls the out-of-line function/namespace copies.
// @0x142506d60
Value GetAbsObject(UPInt addr)
{
    Value result;
    const UPInt kind = addr & 6;
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
        result.AssignUnsafe(reinterpret_cast<Instances::Function*>(addr));
        break;
    case 6:
        result.AssignUnsafe(reinterpret_cast<Instances::Namespace*>(addr));
        break;
    }
    return result;
}

// The bytes of s (len long) left after its leading white space.
static inline UInt32 Sfr33TrailingStart(const char* s, UInt32 len)
{
    return static_cast<UInt32>(UTF8Util::GetByteIndex(ASUtils::SkipWhiteSpace(String(s)), s, len));
}

// ToNumber of a string (kind is kString) or of an object through its primitive value.
// MS2-FUNCTIONAL 0x1424f1000: the exe keeps the parse in one frame (MSVC splits the string path into a chained chunk); same results
// @0x1424f1000
CheckResult Value::Convert2NumberInternal(Number& result, KindType kind) const
{
    if (kind == kString)
    {
        ASStringNode* node = value.VS._1.VStr;
        if (node && node->Size)
        {
            const char* s = node->pData;
            const UInt32 len = node->Size;
            UInt32 end;
            Number d = NumberUtil::StringToDouble(s, len, &end);
            if (NumberUtil::IsNaN(d) || d == 0.0)
            {
                if (end == len)
                {
                    result = NumberUtil::POSITIVE_ZERO();
                    return true;
                }
                if (d == 0.0 && end + Sfr33TrailingStart(s + end, len - end) >= len)
                {
                    result = d;
                    return true;
                }
                d = NumberUtil::StringToInt(s, len, 0, &end);
            }
            if (end + Sfr33TrailingStart(s + end, len - end) < len)
                result = NumberUtil::NaN();
            else
                result = d;
            return true;
        }
    }
    else if (!IsNull())
    {
        Value v;
        if (!Convert2PrimitiveValueUnsafe(v, hintNumber))
            return false;
        return v.Convert2NumberInline(result);
    }
    result = NumberUtil::POSITIVE_ZERO();
    return true;
}

// ToUInt32 (undefined, thunks and null give 0).
// MS2-FUNCTIONAL 0x1424f1a30: the exe inlines the string-to-number tail differently; same results
// @0x1424f1a30
CheckResult Value::Convert2UInt32(UInt32& result) const
{
    switch (GetKind())
    {
    case kUndefined:
    case kThunk:
    case kThunkFunction:
        break;
    case kBoolean:
        result = value.VS._1.VBool;
        return true;
    case kInt:
    case kUInt:
        result = value.VS._1.VUInt;
        return true;
    case kNumber:
        result = ConvertDouble2SInt32(value.VNumber);
        return true;
    case kString:
        if (value.VS._1.VStr)
        {
            Number n;
            if (!Convert2NumberInternal(n, kString))
                return false;
            result = ConvertDouble2SInt32(n);
            return true;
        }
        break;
    default:
        if (!IsNull())
        {
            Value v;
            if (!Convert2PrimitiveValueUnsafe(v))
                return false;
            return v.Convert2UInt32(result);
        }
        break;
    }
    result = 0;
    return true;
}

// HashSetBase<ASString, Class*>::CheckExpand look-alike calling its byte-identical setRawCapacity copy.
// @0x1424eefa0
void Sfr33ClassHashCheckExpand(void* self, void* pheapAddr)
{
    const UPInt* table = *reinterpret_cast<UPInt* const*>(self);
    if (!table)
        FUN_142541a60(self, pheapAddr, 8);
    else if (table[0] * 5 > (table[1] + 1) * 4)
        FUN_142541a60(self, pheapAddr, (table[1] + 1) * 2);
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
        break;
    case 2:
        ::new (result) Value(SInt32(0));
        break;
    case 3:
        ::new (result) Value(UInt32(0));
        break;
    case 4:
        ::new (result) Value(NumberUtil::NaN());
        break;
    default:
        if (&ctr == *reinterpret_cast<ClassTraits::Traits* const*>(reinterpret_cast<const UByte*>(vm) + 0x1f0))
            ::new (result) Value(Value::GetUndefined());
        else
            ::new (result) Value(Value::GetNull());
        break;
    }
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
            return Sfr33GetDefaultValue(vm, result, *ctr);
    }
    ::new (result) Value(Value::GetUndefined());
    return result;
}

// ind receives the array index the string sn spells (decimal digits, no leading zero, at most UInt32 max).
static SF_INLINE CheckResult Sfr33StringArrayInd(const ASStringNode* sn, UInt32& ind)
{
    const UInt32 size = sn->Size;
    if (size)
    {
        const char* s = sn->pData;
        if (s[0] == '0')
        {
            ind = 0;
            return size == 1;
        }
        if (static_cast<UByte>(s[0] - '0') < 10)
        {
            for (UInt32 i = 1; i < size; ++i)
                if (static_cast<UByte>(s[i] - '0') >= 10)
                    return false;
            char* end;
            const double d = strtod(s, &end);
            if (d <= static_cast<double>(SF_MAX_UINT32))
            {
                ind = static_cast<UInt32>(static_cast<SInt64>(d));
                return true;
            }
        }
    }
    return false;
}

// ind receives the array index prop_name names (a string of digits or a number).
// MS2-FUNCTIONAL 0x142507390: the exe lays out its stack frame differently; same results
// @0x142507390
CheckResult GetArrayInd(const Multiname& prop_name, UInt32& ind)
{
    const Value& name = prop_name.Name;
    const Value::KindType kind = name.GetKind();
    if (kind == Value::kString)
        return Sfr33StringArrayInd(name.GetStringNode(), ind);
    if (kind >= Value::kInt && kind <= Value::kNumber)
        return name.Convert2UInt32(ind);
    return false;
}

// MS2-FUNCTIONAL 0x142507490: the exe lays out its stack frame differently; same results
// @0x142507490
CheckResult GetArrayInd(ASStringNode* sn, UInt32& ind)
{
    return Sfr33StringArrayInd(sn, ind);
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

// EventChains::GetChain: the display objects listening for event id (NULL when none do); the chains hash
// (+0x00) maps an event id to an owned array.
// @0x142507a70
ArrayLH<WeakPtr<DisplayObject> >* Sfr33EventChainsGetChain(const UByte* self, int id)
{
    const UPInt* table = *reinterpret_cast<UPInt* const*>(self);
    if (table)
    {
        const UPInt mask = table[1];
        const UPInt home = SPInt(id) & mask;
        const UPInt* e = table + 2 + home * 4;
        if (e[0] != UPInt(-2) && (SPInt(*reinterpret_cast<const int*>(e + 1)) & mask) == home)
        {
            for (;;)
            {
                const int key = *reinterpret_cast<const int*>(e + 1);
                if ((SPInt(key) & mask) == home && key == id)
                    return *reinterpret_cast<ArrayLH<WeakPtr<DisplayObject> >* const*>(e + 2);
                if (e[0] == UPInt(-1))
                    break;
                e = table + 2 + e[0] * 4;
            }
        }
    }
    return NULL;
}

// EventChains::FindObjectIndexInChain: the index of obj in chain (-1 when it is not there).
// @0x142501dc0
UPInt Sfr33FindObjectIndexInChain(void*, ArrayLH<WeakPtr<DisplayObject> >* chain, DisplayObject* obj)
{
    for (UPInt i = 0, n = chain->GetSize(); i < n; ++i)
        if ((*chain)[i] == obj)
            return i;
    return UPInt(-1);
}

// AbcMultinameHash<SPtr<Namespace>>::Get: the namespace interned for constant pool index ind (and next).
// @0x1425057f0
const SPtr<Instances::Namespace>* Sfr33AbcNamespaceHashGet(const AbcMultinameHash<SPtr<Instances::Namespace> >& h,
                                                           UPInt ind, SPInt next)
{
    return h.Entries.Get(AbcMultinameHash<SPtr<Instances::Namespace> >::Key(ind, next));
}

// Hash<UPInt, UPInt>::Get of a bytewise-hashed 8-byte key: *pvalue (unless NULL) receives its value.
// @0x1425058c0
bool Sfr33WordHashGet(const HashLH<UPInt, UPInt>& h, const UPInt& key, UPInt* pvalue)
{
    return h.Get(key, pvalue);
}

// Tracer (ABC optimizer) helpers: self+0x28 the code array, self+0x90/+0x98 the code positions of the values
// pushed so far.
// Drops the code of the last pushed value when it has no side effects (a push or local get), else emits a pop.
// @0x1424f9180
SF_NOINLINE void Sfr33TracerPopLast(UByte* self)
{
    UPInt* const positions = reinterpret_cast<UPInt*>(self + 0x90);
    const UPInt n = positions[1];
    int op = 2;
    if (n)
        op = *reinterpret_cast<const int*>(**reinterpret_cast<UPInt* const* const*>(self + 0x28) +
                                           reinterpret_cast<UPInt*>(positions[0])[n - 1]);
    switch (op)
    {
    case 0x20: case 0x21: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x2a: case 0x2c: case 0x2d:
    case 0x2e: case 0x2f: case 0x31: case 0x60: case 0x62: case 0x64: case 0x65: case 0x67: case 0x6e: case 0xb5:
    case 0xd0: case 0xd1: case 0xd2: case 0xd3:
    {
        const UPInt pos = reinterpret_cast<UPInt*>(positions[0])[n - 1];
        FUN_142524870(positions, n - 1);
        FUN_1425247f0(*reinterpret_cast<void* const*>(self + 0x28), pos);
        return;
    }
    default:
        FUN_14251f930(self, 0x29);   // pop
    }
}

// Emits the push of the constant v (ind: its constant pool index; pop: drop the last pushed value first); false
// when v has no push opcode.
// @0x1424f9060
bool Sfr33TracerPushConst(UByte* self, const Value& v, int ind, bool pop)
{
    int op;
    switch (static_cast<int>(v.GetKind()))
    {
    case 8:
    case 9:
        FUN_14251fb90(self, 0xb6, ind + 1);
        return true;
    case 0:
        if (pop)
            Sfr33TracerPopLast(self);
        op = 0x21;   // pushundefined
        break;
    case 1:
        if (pop)
            Sfr33TracerPopLast(self);
        op = v.AsBool() ? 0x26 : 0x27;   // pushtrue / pushfalse
        break;
    case 4:
        if (!NumberUtil::IsNaN(v.AsNumber()))
            return false;
        if (pop)
            Sfr33TracerPopLast(self);
        op = 0x28;   // pushnan
        break;
    case 12:
    case 13:
        return FUN_1424f86d0(self, v, pop);
    default:
        return false;
    }
    FUN_14251f930(self, op);
    return true;
}

// The value (+0x10 of its entry) the word key maps to in the identity-hashed map at self (NULL when none).
// MS2-FUNCTIONAL 0x1425059f0: the exe finds the entry index first, then returns its value slot; same results
// @0x1425059f0
void* Sfr33IdWordHashGet(const UByte* self, const UPInt& key)
{
    const UPInt* table = *reinterpret_cast<UPInt* const*>(self);
    if (table)
    {
        const UPInt mask = table[1];
        const UPInt home = key & mask;
        const UPInt* e = table + 2 + home * 4;
        if (e[0] != UPInt(-2) && (e[1] & mask) == home)
        {
            for (;;)
            {
                if ((e[1] & mask) == home && e[1] == key)
                    return const_cast<UPInt*>(e + 2);
                if (e[0] == UPInt(-1))
                    break;
                e = table + 2 + e[0] * 4;
            }
        }
    }
    return NULL;
}

// GASRefCountBase::CreateWeakProxy: the object's weak proxy, made on first use (registered with the collector, the
// object flagged as weakly referenced); returned with a new reference.
// MS2-FUNCTIONAL 0x1424f43c0: free function taking the object, then the (uninitialized) Ptr<WeakProxy> slot it fills
// @0x1424f43c0
WeakProxy** Sfr33CreateWeakProxy(const GASRefCountBase* obj, WeakProxy** out)
{
    GASRefCountBase::Collector* gc = obj->GetCollector();
    WeakProxy* proxy = NULL;
    if (!gc->WProxyHash.Get(obj, &proxy))
    {
        proxy = SF_HEAP_AUTO_NEW(obj) WeakProxy;
        if (!proxy)
        {
            *out = NULL;
            return out;
        }
        proxy->RefCount = 1;
        proxy->pObject = obj;
        // RefCount (+0x10) is protected: set Flag_HasWeakRef through the raw word
        *reinterpret_cast<UInt32*>(reinterpret_cast<UByte*>(const_cast<GASRefCountBase*>(obj)) + 0x10) |= GASRefCountBase::Flag_HasWeakRef;
        gc->WProxyHash.Add(obj, proxy);
    }
    proxy->AddRef();
    *out = proxy;
    return out;
}

// SlotInfo::GetDataType: the class traits of the slot's declared type (si+0x18 the ABC file, +0x20 its type
// multiname), resolved and kept (+0x10) on first use; a slot without an ABC type takes those of its bind type.
// MS2-FUNCTIONAL 0x1425085b0: the exe also builds (and drops) a Multiname of the type name.
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
        int off;
        if (file && amn)
        {
            if ((*amn & 0xf & ~6) == 0 && (*amn & 0xf) != 2)
            {
                const Abc::Multiname& tn =
                    FUN_14250f8a0(amn, *reinterpret_cast<const void* const*>(reinterpret_cast<UByte*>(file) + 0x28));
                Multiname mn(*file, tn);
                type = static_cast<ClassTraits::Traits*>(FUN_142524f60(pvm, file, &tn));
                return type;
            }
            off = 0x208;
        }
        else
        {
            switch ((*reinterpret_cast<const int*>(si) << 0x16) >> 0x1b)
            {
            case 0: case 1: case 2: off = 0x1f0; break;
            case 3: case 4: off = 0x1f8; break;
            case 5: off = 0x210; break;
            case 6: off = 0x220; break;
            case 7: off = 0x228; break;
            case 8: off = 0x218; break;
            case 9: case 10: off = 0x230; break;
            case 11: case 12: case 13: case 14: off = 0x208; break;
            default: return type;
            }
        }
        type = *reinterpret_cast<ClassTraits::Traits* const*>(vm + off);
    }
    return type;
}

// SlotInfo::GetDataTypeName: the name of the slot's declared type: that of the resolved class traits, else the
// ABC type multiname's name (Object's name for a runtime one), else the name of the bind type's class.
// MS2-FUNCTIONAL 0x142508720: a void-typed slot takes the void traits' name (the exe dereferences NULL there).
// @0x142508720
ASString Sfr33SlotDataTypeName(const SlotInfo* psi, VM& vm)
{
    const UByte* si = reinterpret_cast<const UByte*>(psi);
    const UByte* pvm = reinterpret_cast<const UByte*>(&vm);
    ASString name = vm.GetStringManager().CreateEmptyString();
    const ClassTraits::Traits* ct = *reinterpret_cast<ClassTraits::Traits* const*>(si + 0x10);
    if (!ct)
    {
        VMAbcFile* file = *reinterpret_cast<VMAbcFile* const*>(si + 0x18);
        const UByte* amn = *reinterpret_cast<const UByte* const*>(si + 0x20);
        if (file && amn)
        {
            if ((*amn & 9) == 0 && (*amn & 0xf) != 2)
            {
                const UByte* tn = reinterpret_cast<const UByte*>(&FUN_14250f8a0(
                    amn, *reinterpret_cast<const void* const*>(reinterpret_cast<UByte*>(file) + 0x28)));
                name = file->GetInternedString(*reinterpret_cast<const int*>(tn + 8));
            }
            else
                name = (*reinterpret_cast<ClassTraits::Traits* const*>(pvm + 0x208))->GetName();
            return name;
        }
        int off;
        switch ((*reinterpret_cast<const int*>(si) << 0x16) >> 0x1b)
        {
        case 0: case 1: case 2:
            *reinterpret_cast<SPtr<const ClassTraits::Traits>*>(const_cast<UByte*>(si) + 0x10) =
                *reinterpret_cast<ClassTraits::Traits* const*>(pvm + 0x1f0);
            off = 0x1f0; break;
        case 3: case 4: off = 0x1f8; break;
        case 5: off = 0x210; break;
        case 6: off = 0x220; break;
        case 7: off = 0x228; break;
        case 8: off = 0x218; break;
        case 9: case 10: off = 0x230; break;
        case 11: case 12: case 13: case 14: off = 0x208; break;
        default: return name;
        }
        ct = *reinterpret_cast<ClassTraits::Traits* const*>(pvm + off);
    }
    name = ct->GetName();
    return name;
}

// VMAbcFile::GetDetailValue: the constant (an optional parameter's or slot's default) a value detail names;
// index 0 (or an unknown kind) is undefined. Kinds: 1 Utf8, 3 Int, 4 UInt, 5/8/0x16..0x1a namespaces,
// 6 Double, 10 False, 11 True, 12 Null.
// MS2-FUNCTIONAL 0x142509240: a free function over the VMAbcFile (the member is not declared in the header).
// @0x142509240
Value Sfr33GetDetailValue(VMAbcFile& file, const Abc::ValueDetail& d)
{
    const SInt32 ind = d.ValueIndex;
    if (ind > 0)
    {
        const Abc::ConstPool& cp = file.GetAbcFile().Const_Pool;
        switch (static_cast<int>(d.Kind))
        {
        case 1:
        {
            const StringDataPtr str = cp.GetString(ind);
            return Value(file.GetVM().GetStringManager().CreateString(str.ToCStr(), str.GetSize()));
        }
        case 3:
            return Value(cp.ConstInt[ind]);
        case 4:
            return Value(cp.ConstUInt[ind]);
        case 5: case 8: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
            return Value(&file.GetInternedNamespace(ind));
        case 6:
            return Value(cp.GetDouble(ind));
        case 10:
            return Value(false);
        case 11:
            return Value(true);
        case 12:
            return Value::GetNull();
        }
    }
    return Value::GetUndefined();
}

// Deletes the public property name (a leading '@' names an attribute) of obj; true when it was deleted.
// self+8 is the movie whose +0x18 is the MovieRoot (pAVM +0x48, string manager +0x348).
// MS2-FUNCTIONAL 0x1424f4780: raw self/MovieRoot offsets (the owning interface is not recovered)
// @0x1424f4780
bool Sfr33DeleteNamedProperty(void* self, Object* obj, const char* name)
{
    const UByte* root = *reinterpret_cast<UByte* const*>(*reinterpret_cast<UByte* const*>(static_cast<UByte*>(self) + 8) + 0x18);
    VM& vm = **reinterpret_cast<VM* const*>(root + 0x48);
    const ASString str((*reinterpret_cast<ASStringManager* const*>(root + 0x348))->CreateStringNode(name));
    const Multiname mn(vm.GetPublicNamespace(), Value(str));
    return obj->DeleteProperty(mn);
}

InstanceTraits::Traits* FUN_1423eb8f0(void* mem, VMAbcFile& file, VM& vm, const Abc::MethodBodyInfo* mbi,
                                      void* p);   // InstanceTraits::Activation::Activation
void FUN_1424d4430(void* set, void* pheapAddr, const void* noderef,
                   UPInt hash);   // HashLH<const MethodBodyInfo*, SPtr<InstanceTraits::Traits>>::add

// VMAbcFile::GetActivationInstanceTraits: the activation traits of method body mbi, made on first use and cached by
// body (+0x90); a body without traits shares the VM's (+0x288).
// MS2-FUNCTIONAL 0x142506f00: raw cache table walk and add (the hash member is kept as its table pointer)
// @0x142506f00
InstanceTraits::Traits* Sfr33GetActivationInstanceTraits(VMAbcFile& file, const Abc::MethodBodyInfo* mbi, void* p)
{
    VM& vm = file.GetVM();
    if (mbi->obj_traits.GetSize() == 0)
        return *reinterpret_cast<InstanceTraits::Traits* const*>(reinterpret_cast<const UByte*>(&vm) + 0x288);
    const UPInt key = reinterpret_cast<UPInt>(mbi);
    UPInt hash = 5381;
    for (int i = 7; i >= 0; --i)
        hash = hash * 65599 + ((key >> (i * 8)) & 0xff);
    void** const cache = reinterpret_cast<void**>(reinterpret_cast<UByte*>(&file) + 0x90);   // ActivationTraitsCacheTable
    const UPInt* table = static_cast<const UPInt*>(*cache);
    if (table)
    {
        const UPInt idx = hash & table[1];
        const UPInt* e = table + 2 + idx * 4;
        if (e[0] != UPInt(-2) && e[1] == idx)
        {
            for (;;)
            {
                if (e[1] == idx && e[2] == key)
                    return reinterpret_cast<InstanceTraits::Traits*>(e[3]);
                if (e[0] == UPInt(-1))
                    break;
                e = table + 2 + e[0] * 4;
            }
        }
    }
    void* mem = vm.GetMemoryHeap()->Alloc(0xd0);
    InstanceTraits::Traits* tr = mem ? FUN_1423eb8f0(mem, file, vm, mbi, p) : NULL;
    SPtr<InstanceTraits::Traits> ref = Pickable<InstanceTraits::Traits>(tr);
    const void* noderef[2] = { &mbi, &ref };
    FUN_1424d4430(cache, cache, noderef, hash);
    return tr;
}

// DisplayObject::GetDrawingContext (virtual) of a sprite-like object (+0xc8): created on first use with the mask
// lifted while its tree node goes last in the container.
// @0x1425099a0
struct Sfr33DisplayObjectAccess : DisplayObject
{
    using DisplayObjectBase::ConvertToTreeContainer;
};

DrawingContext* Sfr33GetDrawingContext(DisplayObject* self)
{
    Ptr<DrawingContext>& pdc = *reinterpret_cast<Ptr<DrawingContext>*>(reinterpret_cast<UByte*>(self) + 0xc8);
    if (!pdc)
    {
        Ptr<DisplayObject> mask = self->GetMask();
        if (mask)
            self->SetMask(NULL);
        pdc = *self->GetMovieImpl()->CreateDrawingContext();
        Render::TreeContainer* node = static_cast<Sfr33DisplayObjectAccess*>(self)->ConvertToTreeContainer();
        node->Remove(0, 1);
        DrawingContext* dc = pdc;
        const UPInt n = node->GetSize();
        node->Insert(n, dc->GetTreeNode());
        if (mask)
            self->SetMask(mask);
    }
    return pdc;
}
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
bool Sfr33CancelIfFromFile(Sfr33FileCallback* cb, const UByte* owner, const void* key)
{
    const Value& f = cb->Function;
    if (!f.IsNull())
    {
        if (Sfr33TraitsFromFile(
                FUN_14250ffc0(**reinterpret_cast<VM* const*>(*reinterpret_cast<const UByte* const*>(owner + 0x18) + 0x48), f),
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
    Sfr33OpStack& st = *reinterpret_cast<Sfr33OpStack*>(reinterpret_cast<UByte*>(&vm) + 0x48);
    result.Pick(*st.pCurrent);
    --st.pCurrent;
}

// Moves result onto the operand stack (result is left undefined).
static void Sfr33PushResult(VM& vm, Value& result)
{
    Sfr33OpStack& st = *reinterpret_cast<Sfr33OpStack*>(reinterpret_cast<UByte*>(&vm) + 0x48);
    ++st.pCurrent;
    memcpy(static_cast<void*>(st.pCurrent), &result, sizeof(Value));
    *reinterpret_cast<UInt32*>(&result) = 0;
}

// A thunk's argument count check: an ArgumentError (#1063) when argc is outside its range.
static bool Sfr33ThunkArgsOk(VM& vm, const ThunkInfo& ti, unsigned argc)
{
    const unsigned maxArgs = ti.GetMaxArgNum();
    if (maxArgs == 0x3ff || (argc <= maxArgs && ti.GetMinArgNum() <= argc))
        return true;
    const VM::Error e(VM::eWrongArgumentCountError, vm, ti.Name, ti.GetMinArgNum(), maxArgs, argc);
    FUN_14252ecb0(&vm, &e, &fl::ArgumentErrorCI);
    return false;
}

// VM::ExecuteInternalUnsafe: calls func on _this. A method slot of a traits' VTable pushes a call frame (run here
// unless result_on_stack, when the interpreter picks it up); thunks, objects and functions are called directly. With
// result_on_stack the result goes onto the operand stack. Anything else is a TypeError (#1006).
// MS2-FUNCTIONAL 0x1424fef00: VM::AddFrame used for the inlined call frame build; method slot lookup factored out
// @0x1424fef00
void VM::ExecuteInternalUnsafe(const Value& func, const Value& _this, Value& result, unsigned argc, const Value* argv,
                               bool result_on_stack)
{
    const ThunkInfo* thunk = NULL;
    Value closureThis;
    const Value* pthis = &_this;
    switch (func.GetKind())
    {
    case Value::kThunk:
        thunk = &func.AsThunk();
        break;
    case Value::kVTableInd:
    case Value::kVTableIndClosure:
    {
        const bool closure = func.GetKind() == Value::kVTableIndClosure;
        if (closure)
        {
            closureThis = Value(func.GetClosure());
            pthis = &closureThis;
        }
        const Traits& tr = closure ? func.GetClosure()->GetTraits() : func.GetTraits();
        const UPInt ind = static_cast<UInt32>(func.GetVTableInd());
        const Value& m = tr.GetVT().VTMethods[ind];
        if (m.GetKind() == Value::kMethodInd)
        {
            const Traits& ot = m.GetTraits();
            VMAbcFile& file = *ot.GetFilePtr();
            const SInt32 mbi_ind = file.GetAbcFile().Methods.Info[m.GetMethodInd()]->MethodBodyInfoInd;
            AddFrame(func, file, mbi_ind, *pthis, argc, argv, false, ot.InitScope, ot, ot.GetVT().Names[ind]);
            if (!result_on_stack)
                Sfr33ExecuteAndPop(*this, result);
            return;
        }
        thunk = &m.AsThunk();
        break;
    }
    case Value::kThunkClosure:
        thunk = &func.AsThunk();
        closureThis = Value(func.GetClosure());
        pthis = &closureThis;
        break;
    case Value::kObject:
    case Value::kClass:
        if (Object* obj = func.GetObject())
        {
            obj->Call(_this, result, argc, argv);
            if (!IsException() && result_on_stack)
                Sfr33PushResult(*this, result);
            return;
        }
        // fall through: a null object is not callable
    default:
    {
        const VM::Error e(VM::eCallOfNonFunctionError, *this, func);
        FUN_14252ecb0(this, &e, &fl::TypeErrorCI);
        return;
    }
    case Value::kFunction:
        if (result_on_stack)
            const_cast<Instances::Function&>(func.AsFunction()).Execute(_this, argc, argv, false);
        else
            const_cast<Instances::Function&>(func.AsFunction()).Call(_this, result, argc, argv);
        return;
    case Value::kThunkFunction:
        const_cast<Instances::ThunkFunction&>(func.AsThunkFunction()).Call(_this, result, argc, argv);
        if (!IsException() && result_on_stack)
            Sfr33PushResult(*this, result);
        return;
    }
    if (!Sfr33ThunkArgsOk(*this, *thunk, argc))
        return;
    thunk->Method(*thunk, *this, *pthis, result, argc, argv);
    if (result_on_stack && !IsException())
        Sfr33PushResult(*this, result);
}

}}}

// Calls the property name (public namespace; "@" marks an attribute) of self with argc arguments: a missing property
// is a ReferenceError, an undefined/null one a TypeError.
// MS2-FUNCTIONAL 0x1424ffc10: PropRef::GetSlotValueUnsafe and the Multiname ctor called out of line (the exe inlines them)
// @0x1424ffc10
void FUN_1424ffc10(Scaleform::UPInt self, Scaleform::UPInt name, Scaleform::UPInt result, int argc,
                   const Scaleform::GFx::AS3::Value* argv)
{
    using namespace Scaleform::GFx::AS3;
    Object* obj = reinterpret_cast<Object*>(self);
    VM& vm = obj->GetVM();
    const Value nameVal(*reinterpret_cast<const Scaleform::GFx::ASString*>(name));
    const Multiname mn(vm.GetPublicNamespace(), nameVal);
    PropRef prop;
    Sfr33FindObjProperty(prop, vm, Value(obj), mn, 0);
    if (!Sfr33PropFound(prop))
    {
        // eReadSealedError (1069): "Property %s not found on %s and there is no default value."
        const VM::Error e(static_cast<VM::ErrorID>(1069), vm, nameVal, Value(obj));
        FUN_14252ecb0(&vm, &e, &fl::ReferenceErrorCI);
        return;
    }
    Value func;
    if (!prop.GetSlotValueUnsafe(vm, func))
        return;
    if (func.IsNullOrUndefined())
    {
        const VM::Error e(VM::eConvertUndefinedToObjectError, vm);
        FUN_14252ecb0(&vm, &e, &fl::TypeErrorCI);
        return;
    }
    vm.ExecuteInternalUnsafe(func, Value(obj), *reinterpret_cast<Value*>(result), static_cast<unsigned>(argc), argv, false);
}

// Calls the method in slot ind of tr's VTable on _this with the result on the operand stack: a method body gets a
// call frame for the interpreter, a thunk is called at once (its result pushed).
// MS2-FUNCTIONAL 0x142500260: through VM::ExecuteInternalUnsafe on a VTable-index value (same dispatch, inlined there)
// @0x142500260
void FUN_142500260(Scaleform::UPInt vm, unsigned int ind, Scaleform::UPInt traits, void* value, unsigned int argc, void* args)
{
    using namespace Scaleform::GFx::AS3;
    const Value func(static_cast<Scaleform::SInt32>(ind), *reinterpret_cast<const Traits*>(traits), Value::kVTableInd);
    Value result;
    reinterpret_cast<VM*>(vm)->ExecuteInternalUnsafe(func, *static_cast<const Value*>(value), result, argc,
                                                     static_cast<const Value*>(args), true);
}

// VM::VMAbcFilesWeak.Clear()
template void Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::VMAbcFile*, Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::VMAbcFile*, Scaleform::GFx::AS3::StatMV_VM_VM_Mem>, Scaleform::ArrayDefaultPolicy> >::Clear();

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

// pval becomes a managed reference to obj kept through iface (the old managed value is released first).
static SF_INLINE bool Sfr33SetObjectValue(GFx::Value::ObjectInterface* iface, GFx::Value* pval, Object* obj)
{
    const UInt32 type = Sfr33GFxObjectType(obj);
    Sfr33GFxValueRaw* v = reinterpret_cast<Sfr33GFxValueRaw*>(pval);
    if ((v->Type >> 6) & 1)   // VTC_ManagedBit
        v->pObjectInterface->ObjectRelease(pval, v->pData);
    v->pData            = obj;
    v->Type             = type | GFx::Value::VTC_ManagedBit;
    v->pObjectInterface = iface;
    iface->ObjectAddRef(pval, obj);
    return true;
}

// The AS3 value object interface: pval refers to obj.
// MS2-FUNCTIONAL 0x1424f3d20: the exe allocates registers differently; same results
// @0x1424f3d20
bool Sfr33ObjectInterfaceSetObject(GFx::Value::ObjectInterface* self, GFx::Value* pval, Object* obj)
{
    return Sfr33SetObjectValue(self, pval, obj);
}

// The same with the interface passed in (the first argument is unused).
// MS2-FUNCTIONAL 0x1424f3dc0: the exe allocates registers differently; same results
// @0x1424f3dc0
bool Sfr33SetObjectValueThrough(void* self, GFx::Value* pval, GFx::Value::ObjectInterface* iface, Object* obj)
{
    SF_UNUSED(self);
    return Sfr33SetObjectValue(iface, pval, obj);
}

// Value::AddRefClosure: the closure object, if any, gains a reference. The exe expands it inline (no copy of its own).
void Value::AddRefClosure() const
{
    if (value.VS._2.VObj)
        value.VS._2.VObj->AddRef();
}

// A host value as an AS3 value. Managed strings and objects come from this movie and are shared as they are; a
// function object keeps its kFunction tag. Closures carry their kind in bit 1 of the object pointer.
// MS2-FUNCTIONAL 0x1425048d0: the exe calls the Value assignments out of line; same results
// @0x1425048d0
void MovieRoot::GFxValue2ASValue(const GFx::Value& gfxVal, Value* pdestVal)
{
    const Sfr33GFxValueRaw& gv = reinterpret_cast<const Sfr33GFxValueRaw&>(gfxVal);
    // The movie's string manager (+0x348).
    ASStringManager* sm = *reinterpret_cast<ASStringManager* const*>(reinterpret_cast<const UByte*>(this) + 0x348);
    switch (gv.Type & 0x8f)
    {
    case 0:     // VT_Undefined
        pdestVal->SetUndefined();
        break;
    case 1:     // VT_Null
        pdestVal->SetNull();
        break;
    case 2:     // VT_Boolean
        pdestVal->SetBool(*reinterpret_cast<const bool*>(&gv.pData));
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
        if (gv.Type & 0x40)
            *pdestVal = static_cast<ASStringNode*>(gv.pData);   // pData is the node's first field
        else
            *pdestVal = ASString(sm->CreateStringNode(static_cast<const char*>(gv.pData)));
        break;
    case 7:     // VT_StringW
        if (gv.Type & 0x40)
            // The wide text sits after the node pointer of its storage.
            *pdestVal = ASString(*reinterpret_cast<ASStringNode* const*>(static_cast<const UByte*>(gv.pData) - 8));
        else
            *pdestVal = ASString(sm->CreateStringNode(static_cast<const wchar_t*>(gv.pData)));
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
                    *pdestVal = reinterpret_cast<Instances::Function*>(obj);
                    break;
                }
            }
            *pdestVal = obj;
        }
        break;
    case 11:    // VT_Closure
        {
            Object* pobj = reinterpret_cast<Object*>(reinterpret_cast<UPInt>(gv.pData) & ~UPInt(2));
            if (reinterpret_cast<UPInt>(gv.pData) & 2)
                *pdestVal = Value(pobj, SInt32(gv.DataAux), false);
            else
                *pdestVal = Value(pobj, *reinterpret_cast<const ThunkInfo*>(gv.DataAux));
        }
        break;
    default:
        break;
    }
}
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

// One mouse event of mouse mouseIndex sent to pobj (OnMouseEvent, or PropagateMouseEvent), with the keyboard's
// modifier keys.
static void Sfr33SendMouseEvent(GFx::InteractiveObject* pobj, UInt32 id, unsigned mouseIndex, const KeyboardState* kb,
                                unsigned button = 0, UByte rollOverCnt = 0, int wheelDelta = 0, bool propagate = false)
{
    GFx::EventId evt(id);
    evt.ButtonId = static_cast<UByte>(button);
    evt.RollOverCnt = rollOverCnt;
    evt.MouseIndex = static_cast<SByte>(mouseIndex);
    evt.KeysState = kb->GetKeyModifiers().States;
    evt.MouseWheelDelta = static_cast<SByte>(wheelDelta);
    if (propagate)
        pobj->PropagateMouseEvent(evt);
    else
        pobj->OnMouseEvent(evt);
}

void* Sfr33MouseStateGetDoubleClickInfo(UByte* self, unsigned buttonMask);

// MovieRoot::GenerateMouseEvents (virtual): the AS3 mouse events of mouse mouseIndex since the last call. Drag
// over/out while the left button is held; roll out of the objects the mouse left (rollover stack, top down) and
// mouse out of the old active object; per released button release outside, mouse up, then click or (fast enough,
// still, with doubleClickEnabled) double click; mouse wheel and move; roll over of the new object and its parents
// up to the stage, then mouse over; mouse down per pressed button. The object under the mouse becomes active.
// MS2-FUNCTIONAL 0x142504b50: mouse state through a derived view, rollover stack as ArrayLH, events built by a helper
// @0x142504b50
void MovieRoot::GenerateMouseEvents(unsigned mouseIndex)
{
    typedef ArrayLH<Ptr<GFx::InteractiveObject> > RolloverArray;
    enum
    {
        Event_MouseOver   = GFx::EventId::Event_LoadStart + 10,
        Event_MouseOut    = GFx::EventId::Event_LoadStart + 11,
        Event_Click       = GFx::EventId::Event_LoadStart + 12,
        Event_DoubleClick = GFx::EventId::Event_LoadStart + 13,
        Event_MouseWheel  = GFx::EventId::Event_LoadStart + 14
    };
    if (mouseIndex >= 4)
        return;
    MovieImpl* movie = GetMovieImpl();
    // MovieImpl::mMouseState[mouseIndex] (0x50 bytes each at +0x1260)
    Sfr33MouseStateAccess* ms = static_cast<Sfr33MouseStateAccess*>(
        reinterpret_cast<GFx::MouseState*>(reinterpret_cast<UByte*>(movie) + 0x1260) + mouseIndex);
    Ptr<GFx::InteractiveObject> active = ms->ActiveEntity;
    Ptr<GFx::InteractiveObject> topmost = ms->TopmostEntity;
    if (active && active->IsUnloaded())
        active = NULL;
    if (topmost && topmost->IsUnloaded())
        topmost = NULL;
    const KeyboardState* kb = movie->GetKeyboardState(mouseIndex);
    const unsigned checkCount = pAVM->ExtensionsEnabled ? 16 : 1;
    const unsigned changed = ms->CurButtonsState ^ ms->PrevButtonsState;
    GFx::InteractiveObject* const ptarget =
        topmost ? topmost.GetPtr() : static_cast<GFx::InteractiveObject*>(pStage);
    MouseState& rs = mMouseState[mouseIndex];
    RolloverArray& stack = *reinterpret_cast<RolloverArray*>(rs.RolloverStack);

    if (ms->PrevButtonsState & 1)
    {
        if (!ms->MouseInsideEntityLast)
        {
            if (topmost == active)
            {
                if (active)
                    Sfr33SendMouseEvent(active, GFx::EventId::Event_DragOver, mouseIndex, kb, 0, active->RollOverCnt++);
                ms->MouseInsideEntityLast = true;
            }
        }
        else if (topmost != active)
        {
            if (active)
            {
                const UByte cnt = active->RollOverCnt ? --active->RollOverCnt : 0xff;
                Sfr33SendMouseEvent(active, GFx::EventId::Event_DragOut, mouseIndex, kb, 0, cnt);
            }
            ms->MouseInsideEntityLast = false;
        }
    }

    if (topmost != active)
    {
        // roll out of the stack's objects down to topmost or one of its ancestors
        const UPInt n = stack.GetSize();
        SPInt i = static_cast<SPInt>(n) - 1;
        for (; i >= 0; --i)
        {
            GFx::InteractiveObject* p = stack[i];
            if (topmost && (p == topmost || p->IsAncestor(topmost)))
                break;
            const UByte cnt = p->RollOverCnt ? --p->RollOverCnt : 0xff;
            Sfr33SendMouseEvent(p, GFx::EventId::Event_RollOut, mouseIndex, kb, 0, cnt);
        }
        stack.Resize(stack.GetSize() - (n - 1 - i));
        if (active)
        {
            active->AddRef();
            if (rs.LastMouseOverObj)
                rs.LastMouseOverObj->Release();
            rs.LastMouseOverObj = active;
            AvmInteractiveObj* avm = ToAvmInteractiveObj(active);
            const UByte cnt = avm->MouseOverCnt ? --avm->MouseOverCnt : 0xff;
            Sfr33SendMouseEvent(active, Event_MouseOut, mouseIndex, kb, 0, cnt);
            if (rs.LastMouseOverObj)
                rs.LastMouseOverObj->Release();
            rs.LastMouseOverObj = NULL;
        }
    }

    for (unsigned b = 0; b < checkCount; ++b)
    {
        const unsigned bit = 1u << b;
        if (!(changed & bit) || !(ms->PrevButtonsState & bit))
            continue;
        MouseState::DoubleClickInfo& dci = *static_cast<MouseState::DoubleClickInfo*>(
            Sfr33MouseStateGetDoubleClickInfo(reinterpret_cast<UByte*>(&rs), b));
        if (Ptr<GFx::InteractiveObject> pdown = ms->GetMouseButtonDownEntity(b))
            Sfr33SendMouseEvent(pdown, GFx::EventId::Event_ReleaseOutside, mouseIndex, kb, b);
        Sfr33SendMouseEvent(ptarget, GFx::EventId::Event_MouseUp, mouseIndex, kb, b);
        if (ms->MouseInsideEntityLast)
        {
            const float k = 0.05f;   // twips to pixels
            const UInt32 tm = static_cast<UInt32>(Timer::GetTicks() / 1000);
            const bool dbl = dci.PrevClickTime != 0 && tm <= dci.PrevClickTime + 300 &&
                             static_cast<int>(dci.PrevPosition.x * k) == static_cast<int>(ms->LastPosition.x * k) &&
                             static_cast<int>(dci.PrevPosition.y * k) == static_cast<int>(ms->LastPosition.y * k);
            if (dbl && (ToAvmInteractiveObj(ptarget)->IntFlags & 2))   // doubleClickEnabled
                Sfr33SendMouseEvent(ptarget, Event_DoubleClick, mouseIndex, kb, b);
            else if (ptarget == ms->GetMouseButtonDownEntity(b).GetPtr())
                Sfr33SendMouseEvent(ptarget, Event_Click, mouseIndex, kb, b);
            dci.PrevClickTime = dbl ? 0 : tm;
            dci.PrevPosition = ms->LastPosition;
        }
        ms->SetMouseButtonDownEntity(b, NULL);
    }

    if (ms->WheelDelta != 0)
        Sfr33SendMouseEvent(ptarget, Event_MouseWheel, mouseIndex, kb, 0, 0, ms->WheelDelta);
    if (ms->MouseMoved)
    {
        Sfr33SendMouseEvent(ptarget, GFx::EventId::Event_MouseMove, mouseIndex, kb, 0, 0, ms->WheelDelta);
        Ptr<GFx::InteractiveObject> pdown = ms->GetMouseButtonDownEntity(0);
        if (pdown && pdown != ptarget)
            Sfr33SendMouseEvent(pdown, GFx::EventId::Event_MouseMove, mouseIndex, kb, 0, 0, 0, true);
    }

    if (topmost == active)
    {
        if (!topmost)
            stack.Resize(0);
    }
    else
    {
        if (topmost)
        {
            UPInt i = stack.GetSize();
            while (i > 0 && stack[i - 1] != topmost)
                --i;
            if (i == 0)
            {
                // roll over topmost and its parents up to the stage or the stack's top; parents go below
                const UPInt base = stack.GetSize();
                Ptr<GFx::InteractiveObject> p = topmost;
                while (p && p != pStage && !(base && stack[base - 1] == p))
                {
                    Sfr33SendMouseEvent(p, GFx::EventId::Event_RollOver, mouseIndex, kb, 0, p->RollOverCnt++);
                    stack.InsertAt(base, p);
                    p = p->GetParent();
                }
            }
            AvmInteractiveObj* avm = ToAvmInteractiveObj(topmost);
            Sfr33SendMouseEvent(topmost, Event_MouseOver, mouseIndex, kb, 0, avm->MouseOverCnt++);
            if (rs.LastMouseOverObj)
                rs.LastMouseOverObj->Release();
            rs.LastMouseOverObj = NULL;
        }
        ms->MouseInsideEntityLast = true;
    }

    for (unsigned b = 0; b < checkCount; ++b)
    {
        const unsigned bit = 1u << b;
        if (!(changed & bit) || (ms->PrevButtonsState & bit))
            continue;
        GFx::InteractiveObject* pdown = topmost ? topmost.GetPtr() : static_cast<GFx::InteractiveObject*>(pStage);
        Sfr33SendMouseEvent(pdown, GFx::EventId::Event_MouseDown, mouseIndex, kb, b);
        ms->SetMouseButtonDownEntity(b, pdown);
        ms->MouseInsideEntityLast = true;
    }
    ms->ActiveEntity = topmost.GetPtr();
    ms->MouseMoved = false;
    ms->WheelDelta = 0;
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
// MS2-FUNCTIONAL ?Clear@?$HashSetBase@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@H$01@2@V?$HashsetNodeEntry@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXXZ: the exe inlines the AutoPtr<ArrayLH> destructor of each entry; ours calls it.
// @0x1424ef380
template void DisplayObjectWeakHash::Clear();
// MS2-FUNCTIONAL ?Clear@?$HashsetNodeEntry@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@@Scaleform@@QEAAXXZ: the exe inlines the AutoPtr<ArrayLH> destructor; ours calls it.
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

// The host side of AS3 values (GFx::Value object calls); only the members recovered so far. pdata is the
// AS3 object; the display object calls apply to instances of the display object classes.
class AS3ValueObjectInterface : public Value::ObjectInterface
{
private:
    virtual bool GetCxform(void* pdata, Render::Cxform* pcx) const;
    virtual bool GetDisplayMatrix(void* pdata, Render::Matrix2F* pmat) const;
    virtual unsigned GetArraySize(void* pdata) const;
    virtual AMP::ViewStats* GetAdvanceStats() const;
};

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

// MovieRoot::GetASVariableAtPath: the value at the dotted path ppathToVar. A global object property of that name
// comes first; otherwise the path is walked from the stage, or from root1 under a "_root", "_level0" or "root"
// prefix, one property (else named display child) per token. A token in the middle that is not an object is logged
// and ends the walk with null. False when there is no path, no root1 or a token resolves to nothing.
// MS2-FUNCTIONAL 0x142506000: the tokenizer, Multiname ctor and AS3 object fetches are inlined in the exe
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
    Value resolvedVal(pstage->GetAS3Obj());

    // a global first
    const Multiname gname(vm, StringDataPtr(ppathToVar));
    PropRef globalProp;
    Sfr33FindGOProperty(globalProp, vm, *reinterpret_cast<const ArrayLH<Instances::fl::GlobalObject*>*>(&vm.GlobalObjects),
                        gname, FUN_14250d760(vm, gname));
    if (Sfr33PropFound(globalProp))
    {
        Value v;
        if (!globalProp.GetSlotValueUnsafe(vm, v))
            return false;
        pval->Swap(v);
        return true;
    }

    // the known prefixes: all but "stage" start from root1
    const char* ppath = ppathToVar;
    unsigned offset = 0;
    bool r1allow = true;
    if (ppath[0] == '_')
    {
        if (!strncmp(ppath + 1, "root", 4))
            offset = 5;
        else if (!strncmp(ppath + 1, "level0", 5))
            offset = 7;
    }
    else if (ppath[0] == 'r')
    {
        if (!strncmp(ppath + 1, "oot", 3))
            offset = 4;
    }
    else if (ppath[0] == 's' && !strncmp(ppath + 1, "tage", 4))
    {
        offset = 5;
        r1allow = false;
    }
    bool isroot1 = false;
    if (ppath[offset] == '.' || ppath[offset] == '\0')
    {
        if (ppath[offset] == '.')
            ++offset;
        isroot1 = r1allow;
        ppath += offset;
    }
    if (isroot1)
    {
        GFx::DisplayObject* proot1 = pstage->GetDisplayObjContainer()->mDisplayList.GetDisplayObjectByName(
            root->BuiltinsMgr.CreateConstString("root1"), true);
        if (!proot1 || !proot1->IsDisplayObjContainer())
            return false;
        resolvedVal = Value(AvmDisplayObjContainer::FromBase(proot1->GetAvmObjImpl()->ToAvmDispContainerBase())->GetAS3Obj());
    }

    // one property per token
    const char* tok = ppath;
    UPInt rest = strlen(ppath);
    while (rest)
    {
        UPInt len = 0;
        while (len < rest && tok[len] != '.')
            ++len;
        const StringDataPtr token(tok, len);
        tok += len;
        rest -= len;
        if (rest && *tok == '.')
        {
            ++tok;
            --rest;
        }
        GFx::ASString propName = root->BuiltinsMgr.CreateString(token.ToCStr(), token.GetSize());
        const Multiname prop(vm.GetPublicNamespace(), Value(propName));
        Value subVal;
        Object* pobj = resolvedVal.GetObject();
        if (!pobj)
        {
            pval->SetUndefined();
            if (vm.IsException())
                vm.OutputAndIgnoreException();
            return false;
        }
        if (!pobj->GetProperty(prop, subVal))
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
                SPtr<Instances::fl_display::DisplayObject> pchild = pcurr->GetAS3ChildByName(propName);
                if (!pchild)
                {
                    if (vm.IsException())
                        vm.OutputAndIgnoreException();
                    return false;
                }
                subVal = Value(pchild.GetPtr());
            }
        }
        resolvedVal = subVal;
        if (rest && !resolvedVal.IsObject())
        {
            if (Ptr<Log> plog = root->GetMovieImpl()->GetLog())
            {
                String s;
                Format(s, "Token '{0}' in path '{1}' was not resolved to a valid Object! This may be caused by a property "
                          "that is not of Object type, or by using reserved words/properties for MovieClip names in the "
                          "display tree.", token, ppathToVar);
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
void FUN_1425303b0(Scaleform::UPInt entry);   // shutdown of a registered entry (sfr_as3_19)

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
    value.Assign(DynAttrsType::Iterator(it.GetContainer(), ind.Get())->Second);
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
// MS2-PIN: ?Convert2NumberInline@Value@AS3@GFx@Scaleform@@QEBA?AVCheckResult@234@AEAN@Z 0x1424f0f60
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

// MS2-FUNCTIONAL: adjustor thunk
// @0x1424efde4
void FUN_1424efde4(Scaleform::UPInt self) { FUN_1424efde0(self - 0x10); }
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424efe24
void FUN_1424efe24(Scaleform::UPInt self) { FUN_1424efe20(self - 0x10); }
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424f1f54
void FUN_1424f1f54(Scaleform::UPInt self) { FUN_1424f1f50(self - 0x10); }
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424f1f84
void FUN_1424f1f84(Scaleform::UPInt self) { FUN_1424f1f80(self - 0x10); }

// MS2-FUNCTIONAL: vftable leaf returning 0
// @0x142502cf0
Scaleform::UPInt FUN_142502cf0(Scaleform::UPInt) { return 0; }
// MS2-FUNCTIONAL: vftable leaf returning 0
// @0x142507b30
Scaleform::UPInt FUN_142507b30(Scaleform::UPInt) { return 0; }
// MS2-FUNCTIONAL: vftable leaf returning 0
// @0x142508550
unsigned FUN_142508550(Scaleform::UPInt) { return 0; }
// MS2-FUNCTIONAL: adjustor thunk
// @0x142508554
unsigned FUN_142508554(Scaleform::UPInt self) { return FUN_142508550(self - 0x10); }

// Queues the object's +0x10 owner's +0x30 counted reference on the +0x40 VM's collector (+0x20).
// MS2-FUNCTIONAL: raw-offset vftable slot
// @0x1425046d0
void FUN_1425046d0(Scaleform::UPInt self)
{
    Scaleform::GFx::AS3::Sfr33CollectorQueue(reinterpret_cast<Scaleform::UByte*>(Sfr21AccRd(Sfr21AccRd(self, 0x40), 0x20)),
        reinterpret_cast<Scaleform::RefCountImpl*>(Sfr21AccRd(Sfr21AccRd(self, 0x10), 0x30)));
}

// Drops the loader info of the AS3 object (+0xa0, else the tagged +0x98 pointer).
// MS2-FUNCTIONAL: raw-offset vftable slot
// @0x1425047c0
void FUN_1425047c0(Scaleform::UPInt self)
{
    Scaleform::UPInt obj = Sfr21AccRd(self, 0xa0);
    if (!obj)
        obj = Sfr21AccRd(self, 0x98);
    if (!obj)
        return;
    if (obj & 1)
        --obj;
    FUN_142446e70(reinterpret_cast<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject*>(obj), NULL);
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
// MS2-FUNCTIONAL: adjustor thunk
// @0x142506df8
const char* FUN_142506df8(Scaleform::UPInt self, Scaleform::String* ppath) { return FUN_142506df0(self - 0x30, ppath); }
// MS2-FUNCTIONAL: adjustor thunk
// @0x142506e04
const char* FUN_142506e04(Scaleform::UPInt self, Scaleform::String* ppath) { return FUN_142506df0(self - 0x40, ppath); }

// MS2-FUNCTIONAL: tail call into AvmInteractiveObj::GetAbsolutePath
// @0x142506ed0
const char* FUN_142506ed0(Scaleform::UPInt self, Scaleform::String* ppath)
{
    return reinterpret_cast<const Scaleform::GFx::AS3::AvmInteractiveObj*>(self)
        ->Scaleform::GFx::AS3::AvmInteractiveObj::GetAbsolutePath(ppath);
}
// MS2-FUNCTIONAL: adjustor thunk
// @0x142506ed8
const char* FUN_142506ed8(Scaleform::UPInt self, Scaleform::String* ppath) { return FUN_142506ed0(self - 0x30, ppath); }
// MS2-FUNCTIONAL: adjustor thunk
// @0x142506ee4
const char* FUN_142506ee4(Scaleform::UPInt self, Scaleform::String* ppath) { return FUN_142506ed0(self - 0x40, ppath); }

// MS2-FUNCTIONAL: raw getter
// @0x142507b70
Scaleform::UPInt FUN_142507b70(Scaleform::UPInt self) { return Sfr21AccRd(self, 0xc0); }

// The display object's (+0x18 back from the AVM base) flag bit 4 at +0xb8.
// MS2-FUNCTIONAL: raw-offset vftable slot
// @0x142508500
unsigned FUN_142508500(Scaleform::UPInt self)
{
    return (*reinterpret_cast<const Scaleform::UInt32*>(Sfr21AccRd(self - 0x18, 0) + 0xb8) >> 4) & 1;
}
// MS2-FUNCTIONAL: adjustor thunk
// @0x142508514
unsigned FUN_142508514(Scaleform::UPInt self) { return FUN_142508500(self - 0x10); }

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
