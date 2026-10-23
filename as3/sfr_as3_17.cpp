// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_17
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424ed890-0x142509d40 .text$mn
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_intervaltimer.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"
#include "ms2/scaleform/include/gfx/gfx_loadproc.h"
#undef GetObject

// The AS3 object's +0x50 counted reference set to p (unrecovered).
void FUN_142446e70(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject* obj, void* p);

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
ASVM* AvmDisplayObj::GetAVM() const
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
// MS2-FUNCTIONAL: same flag updates and playlist call; register allocation differs.
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
// MS2-FUNCTIONAL: same button-mode bit; reached through a different this adjustment.
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
}}}

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

// MS2-PIN: ?ConstructArray@?$ConstructorMov@VValue@AS3@GFx@Scaleform@@@Scaleform@@SAXPEAX_KPEBVValue@AS3@GFx@2@@Z 0x1424f08d0
// MS2-PIN: ?Construct@?$ConstructorMov@VValue@AS3@GFx@Scaleform@@@Scaleform@@SAXPEAXAEBVValue@AS3@GFx@2@@Z 0x1424f05a0
// MS2-PIN: ?DestructArray@?$ConstructorMov@VValue@AS3@GFx@Scaleform@@@Scaleform@@SAXPEAVValue@AS3@GFx@2@_K@Z 0x1424f6d50
