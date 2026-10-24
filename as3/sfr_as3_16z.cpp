// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 movie root and display objects,
// the upper half of sfr_as3_16's range (split with cx18 at 0x1424e2040). Our own source, written from the exe.
// MS2-UNIT: sfr_as3_16z
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424e2040-0x1424e2bb0 .text$mn
// MS2-RANGE: 0x1424e2c10-0x1424e3020 .text$mn
// MS2-RANGE: 0x1424e3260-0x1424e3580 .text$mn
// MS2-RANGE: 0x1424e35e0-0x1424e3690 .text$mn
// MS2-RANGE: 0x1424e37a0-0x1424e3bd0 .text$mn
// MS2-RANGE: 0x1424e3c30-0x1424e3cc0 .text$mn
// MS2-RANGE: 0x1424e3d60-0x1424e4290 .text$mn
// MS2-RANGE: 0x1424e42c0-0x1424e46f0 .text$mn
// MS2-RANGE: 0x1424e5e80-0x1424e63b0 .text$mn
// MS2-RANGE: 0x1424e6aa0-0x1424e6f90 .text$mn
// MS2-RANGE: 0x1424e7140-0x1424e7f40 .text$mn
// MS2-RANGE: 0x1424e80f0-0x1424e8c20 .text$mn
// MS2-RANGE: 0x1424e8e20-0x1424e8ed0 .text$mn
// MS2-RANGE: 0x1424eab60-0x1424eaf00 .text$mn
// MS2-RANGE: 0x1424eaf80-0x1424eb610 .text$mn
// The Avm* deleting destructors free only on a global delete, and AvmButton / AvmTextField / AvmStaticText are modeled.
#define SF_AS3_AVM_INPLACE_DELETE
#define SF_AS3_AVMBUTTON_MODEL
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/as3_udbase.h"
#include "ms2/scaleform/include/gfx/as2/as2_object.h"
#include "ms2/scaleform/include/gfx/as3/as3_loadqueue.h"
#include "ms2/scaleform/include/gfx/gfx_loaderimpl.h"
#include "ms2/scaleform/include/gfx/gfx_interactiveobject.h"
#include "ms2/scaleform/include/gfx/gfx_taskmanager.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_framecounter.h"
#include "ms2/scaleform/include/gfx/as3/as3_stickyvarnode.h"
#include "ms2/scaleform/include/gfx/as3/as3_eventchains.h"
#include "ms2/scaleform/include/gfx/as3/as3_valueobjectinterface.h"
#include "ms2/scaleform/include/gfx/as3/as3_userdefinedfunction.h"
#include "ms2/scaleform/include/gfx/as3/as3_support.h"
#undef GetObject

// VM: runs the queued code (unrecovered).
extern "C" void FUN_1424fa5b0(void* vm, unsigned count);

namespace Scaleform { namespace GFx {
// The wide copy keeps its string node; the characters are decoded once. Inline like in sfr_as2_04, which is what
// emits the vftable and the deleting destructor here too.
inline MovieImpl::WideStringStorage::WideStringStorage(ASStringNode* pnode) : pNode(pnode)
{
    pNode->AddRef();
    UTF8Util::DecodeString(pData, pNode->pData, pNode->Size);
}

inline MovieImpl::WideStringStorage::~WideStringStorage()
{
    pNode->Release();
}
}} // namespace Scaleform::GFx

namespace Scaleform { namespace GFx { namespace AS3 {

// MS2-FUNCTIONAL: same calls and stores; the exe lays out the frame and the parent lookup differently.
// @0x1424e6d90
void AvmDisplayObjContainer::AddChild(DisplayObjectBase* ch)
{
    if (ch->GetParent())
        AvmDisplayObjContainer::FromBase(static_cast<DisplayObjContainer*>(ch->GetParent())->GetAvmDispContainer())
            ->RemoveChild(ch);
    DisplayObjContainer* pcont = GetDisplayObjContainer();
    pcont->mDisplayList.AddEntryAtIndex(pcont, pcont->mDisplayList.GetCount(), ch);
    pcont->mDisplayList.Flags |= DisplayList::Flags_DepthToIndexInvalid | DisplayList::Flags_MayContainForeignElems;
    ch->pParent = pcont;
    ch->Depth   = -1;
    ch->SetUnloaded(false);
    ch->SetUnloading(false);
    if (ch->IsInteractiveObject() && static_cast<InteractiveObject*>(ch)->IsInPlayList())
        ToAvmInteractiveObj(static_cast<InteractiveObject*>(ch))->MoveBranchInPlayList();
    if (ch->IsScriptableObject())
        ToAvmDisplayObj(ch)->OnAdded(false);
}

// @0x1424e6e90
void AvmDisplayObjContainer::AddChildAt(DisplayObjectBase* ch, unsigned index)
{
    if (ch->GetParent())
        AvmDisplayObjContainer::FromBase(static_cast<DisplayObjContainer*>(ch->GetParent())->GetAvmDispContainer())
            ->RemoveChild(ch);
    DisplayObjContainer* pcont = GetDisplayObjContainer();
    unsigned count = static_cast<unsigned>(pcont->mDisplayList.GetCount());
    if (index > count)
        index = count;
    pcont->mDisplayList.AddEntryAtIndex(pcont, index, ch);
    ch->pParent = pcont;
    ch->Depth   = -1;
    ch->SetUnloaded(false);
    ch->SetUnloading(false);
    if (ch->IsInteractiveObject() && static_cast<InteractiveObject*>(ch)->IsInPlayList())
        ToAvmInteractiveObj(static_cast<InteractiveObject*>(ch))->MoveBranchInPlayList();
    if (ch->IsScriptableObject())
        ToAvmDisplayObj(ch)->OnAdded(false);
}

// MovieRoot::AddStickyVariable: keeps name = val under path until its target exists (permanently for
// Movie::SV_Permanent, 2).
// @0x1424eab60
void Sfr21AddStickyVariable(MovieRoot* self, const ASString& path, const ASString& name, const Value& val,
                            int setType)
{
    if (name.GetSize() == 0)
        return;
    MovieImpl* pmovie = self->pMovieImpl;
    MovieRoot::StickyVarNode* pnode = SF_HEAP_NEW(pmovie->GetMovieHeap())
        MovieRoot::StickyVarNode(name, val, setType == 2);
    if (pnode)
        pmovie->AddStickyVariableNode(path, pnode);
}

// @0x1424eac70
void EventChains::AddToChain(EventId::IdCode evtId, DisplayObject* obj)
{
    Chain*                     chain;
    Scaleform::AutoPtr<Chain>* pentry = Chains.Get(evtId);
    if (!pentry)
    {
        chain = SF_HEAP_AUTO_NEW(this) Chain();
        Chains.Add(evtId, Scaleform::AutoPtr<Chain>(chain));
    }
    else
        chain = pentry->GetPtr();
    if (FindObjectIndexInChain(chain, obj) == SF_MAX_UPINT)
        chain->PushBack(WeakPtr<DisplayObject>(obj));
}

// MS2-FUNCTIONAL: ClearAction inlined with another register and frame layout than the exe.
// @0x1424eae40
void MovieRoot::ActionQueueType::AddToFreeList(ActionEntry* pentry)
{
    pentry->ClearAction();
    if (FreeEntriesCount < 50)
    {
        pentry->pNextEntry = pFreeEntry;
        pFreeEntry         = pentry;
        ++FreeEntriesCount;
    }
    else
        delete pentry;
}

// Runs the frame: the class constructors still queued, the two highest action levels, then queues the frame
// scripts of the play list and moves the manual actions behind them.
// MS2-FUNCTIONAL: same calls in the same order; the exe saves its registers in another frame layout.
// @0x1424eb260
void FrameCounter::AdvanceFrame(bool nextFrame, float framePos)
{
    SF_UNUSED(framePos);
    if (!nextFrame)
        return;
    MovieRoot* proot = static_cast<MovieRoot*>(GetMovieImpl()->pASMovieRoot);
    if (proot->ASFramesToExecute)
    {
        FUN_1424fa5b0(proot->pAVM, 1);
        if (proot->pAVM->HandleException)
            proot->pAVM->HandleException = false;
        proot->ASFramesToExecute = 0;
    }
    proot->ExecuteActionQueue(MovieRoot::AL_Highest);
    proot->ExecuteActionQueue(MovieRoot::AL_High);
    QueueFrameActions();
    proot->RequeueActionQueue(MovieRoot::AL_Manual, MovieRoot::AL_Frame);
}

// Not exe code: the stage builds its frame counter inline (sfr_as3_18), but FrameCounter's deleting destructor lies in
// this unit's range; constructing one here emits it.
void Unk_As3_16zConstructFrameCounter(void* p, MovieDefImpl* pdefImpl, ASMovieRootBase* pasRoot)
{
    new (p) FrameCounter(pdefImpl, pasRoot, NULL, ResourceId());
}

// Not exe code: the AS3 parts are built by sfr_as3_15's out-of-line constructors and destroyed through their vftables;
// running their inline destructors here emits the vftables and with them the deleting destructors of this range.
void Unk_As3_16zDestroyAvmParts(AvmInteractiveObj* pio, AvmButton* pbtn, AvmTextField* ptxt, AvmStaticText* pst)
{
    pio->AvmInteractiveObj::~AvmInteractiveObj();
    pbtn->AvmButton::~AvmButton();
    ptxt->AvmTextField::~AvmTextField();
    pst->AvmStaticText::~AvmStaticText();
}

// Not exe code: the same for interfaces whose objects are built inline or in other units.
void Unk_As3_16zDestroyInterfaces(AS3ValueObjectInterface* pvoi, GFx::Value::ObjectInterface* poi, FlashUI* pui,
                                  UserDefinedFunction* pudf)
{
    pvoi->AS3ValueObjectInterface::~AS3ValueObjectInterface();
    new (pvoi) AS3ValueObjectInterface(NULL);
    poi->GFx::Value::ObjectInterface::~ObjectInterface();
    pui->FlashUI::~FlashUI();
    pudf->UserDefinedFunction::~UserDefinedFunction();
}

// GFx::Value as the exe lays it out (the members are private to the value).
struct Unk_As3_16zGFxValueRaw
{
    GFx::Value::ObjectInterface* pObjectInterface;   // +0x00
    UInt32                       Type;               // +0x08
    void*                        pData;              // +0x10
    UPInt                        DataAux;            // +0x18 closures: the thunk or the vtable index
};

// v as a host value. A requested type (convert bit) wins; otherwise the kind decides: plain values keep their type,
// objects, classes and functions become objects (display objects and arrays get their own type), closures stay
// closures, a null reference is null and everything else is converted to a string. Strings, objects and closures
// are managed through the movie's object interface; a failed conversion is reported and leaves NaN.
// MS2-FUNCTIONAL: the exe builds the wide string storage inline and keeps the closure kind in a register flag
// @0x1424e42c0
void MovieRoot::ASValue2GFxValue(const Value& v, GFx::Value* pdestVal) const
{
    Unk_As3_16zGFxValueRaw* dest = reinterpret_cast<Unk_As3_16zGFxValueRaw*>(pdestVal);
    unsigned toType;
    bool vtableIndClosure = false;
    if (dest->Type & GFx::Value::VTC_ConvertBit)
        toType = dest->Type & 0xf;
    else
    {
        switch (v.GetKind())
        {
        case Value::kUndefined: toType = GFx::Value::VT_Undefined; break;
        case Value::kBoolean:   toType = GFx::Value::VT_Boolean; break;
        case Value::kInt:       toType = GFx::Value::VT_Int; break;
        case Value::kUInt:      toType = GFx::Value::VT_UInt; break;
        case Value::kNumber:    toType = GFx::Value::VT_Number; break;
        case Value::kObject:
        case Value::kClass:
        case Value::kFunction:
        case Value::kThunkFunction:
            toType = v.GetObject() ? GFx::Value::VT_Object : GFx::Value::VT_Null;
            break;
        case Value::kThunkClosure:
            toType = v.GetClosure() ? GFx::Value::VT_Closure : GFx::Value::VT_Null;
            break;
        case Value::kVTableIndClosure:
            vtableIndClosure = true;
            toType = v.GetClosure() ? GFx::Value::VT_Closure : GFx::Value::VT_Null;
            break;
        default:
            toType = GFx::Value::VT_String;
            break;
        }
        if (v.IsNull())
            toType = GFx::Value::VT_Null;
    }

    if ((dest->Type >> 6) & 1)   // VTC_ManagedBit: drop the old reference
    {
        dest->pObjectInterface->ObjectRelease(pdestVal, dest->pData);
        dest->pObjectInterface = NULL;
    }

    GFx::Value::ObjectInterface* iface = static_cast<GFx::Value::ObjectInterface*>(pMovieImpl->pObjectInterface);
    switch (toType)
    {
    case GFx::Value::VT_Undefined:
    case GFx::Value::VT_Null:
        dest->Type = toType;
        break;
    case GFx::Value::VT_Boolean:
        dest->Type = toType;
        *reinterpret_cast<bool*>(&dest->pData) = v.AsBool();
        break;
    case GFx::Value::VT_Int:
        dest->Type = toType;
        if (!v.Convert2Int32(*reinterpret_cast<SInt32*>(&dest->pData)))
        {
            pAVM->OutputAndIgnoreException();
            *reinterpret_cast<Double*>(&dest->pData) = NumberUtil::NaN();
        }
        break;
    case GFx::Value::VT_UInt:
        dest->Type = toType;
        if (!v.Convert2UInt32(*reinterpret_cast<UInt32*>(&dest->pData)))
        {
            pAVM->OutputAndIgnoreException();
            *reinterpret_cast<Double*>(&dest->pData) = NumberUtil::NaN();
        }
        break;
    case GFx::Value::VT_Number:
        dest->Type = toType;
        if (!v.Convert2NumberInline(*reinterpret_cast<Double*>(&dest->pData)))
        {
            pAVM->OutputAndIgnoreException();
            *reinterpret_cast<Double*>(&dest->pData) = NumberUtil::NaN();
        }
        break;
    case GFx::Value::VT_String:
        {
            ASString str(pAVM->GetStringManager().GetBuiltin(AS3Builtin_empty_));
            if (!v.Convert2String(str))
                pAVM->OutputAndIgnoreException();
            // The node's text pointer is its first field, so the node is the managed string.
            dest->pData            = str.GetNode();
            dest->Type             = GFx::Value::VT_String | GFx::Value::VTC_ManagedBit;
            dest->pObjectInterface = iface;
            iface->ObjectAddRef(pdestVal, dest->pData);
        }
        break;
    case GFx::Value::VT_StringW:
        {
            ASString str(pAVM->GetStringManager().GetBuiltin(AS3Builtin_empty_));
            if (!v.Convert2String(str))
                pAVM->OutputAndIgnoreException();
            ASStringNode* pnode = str.GetNode();
            const unsigned len = str.GetLength() + 1;
            void* pmem = pMovieImpl->GetMovieHeap()->Alloc(
                sizeof(MovieImpl::WideStringStorage) - 1 + sizeof(wchar_t) * len);
            dest->Type = GFx::Value::VT_StringW | GFx::Value::VTC_ManagedBit;
            Ptr<MovieImpl::WideStringStorage> pwstr = *::new (pmem) MovieImpl::WideStringStorage(pnode);
            dest->pData            = pwstr->pData;
            dest->pObjectInterface = iface;
            iface->ObjectAddRef(pdestVal, dest->pData);
        }
        break;
    case GFx::Value::VT_Object:
        {
            Object* obj = v.GetObject();
            const Traits& tr = obj->GetTraits();
            const BuiltinTraitsType tt = tr.GetTraitsType();
            UInt32 type = GFx::Value::VT_Object;
            if (UInt32(tt - Traits_DisplayObject_Begin) < UInt32(Traits_DisplayObject_End - Traits_DisplayObject_Begin) &&
                tr.IsInstanceTraits())
                type = GFx::Value::VT_DisplayObject;
            else if (tt == Traits_Array && tr.IsInstanceTraits())
                type = GFx::Value::VT_Array;
            dest->pData            = obj;
            dest->Type             = type | GFx::Value::VTC_ManagedBit;
            dest->pObjectInterface = iface;
            iface->ObjectAddRef(pdestVal, dest->pData);
        }
        break;
    case GFx::Value::VT_Closure:
        {
            // Bit 1 of the object pointer tells a vtable index closure from a thunk closure.
            dest->Type    = GFx::Value::VT_Closure | GFx::Value::VTC_ManagedBit;
            dest->pData   = reinterpret_cast<void*>(reinterpret_cast<UPInt>(v.GetClosure()) | (vtableIndClosure ? 2 : 0));
            dest->DataAux = vtableIndClosure ? UPInt(SPInt(v.GetVTableInd())) : reinterpret_cast<UPInt>(&v.AsThunk());
            dest->pObjectInterface = iface;
            iface->ObjectAddRef(pdestVal, dest->pData);
        }
        break;
    default:
        break;
    }
}

// The loaded-movie-def hash (+0x6e8): the value an identity-hashed key maps to, and the add of a new node.
void* FUN_1425059f0(const void* self, const UPInt& key);
void FUN_1424d4220(void* self, void* pheapAddr, const void* nodeRef, UPInt hashValue);

// A use of pdefImpl: an entry already listed counts one more use; otherwise one is added (holding the definition)
// with a single use.
// MS2-FUNCTIONAL: the hash lookup and add are called through their exe addresses
// @0x1424e8e20
void MovieRoot::AddLoadedMovieDef(MovieDefImpl* pdefImpl)
{
    struct Info { Ptr<MovieDefImpl> pMovieDef; unsigned UseCnt; };
    struct NodeRef { MovieDefImpl* const* pFirst; const Info* pSecond; };
    UPInt key = reinterpret_cast<UPInt>(pdefImpl);
    Info* pinfo = static_cast<Info*>(FUN_1425059f0(&LoadedMovieDefs, key));
    if (pinfo)
    {
        ++pinfo->UseCnt;
        return;
    }
    Info info;
    info.pMovieDef = pdefImpl;
    info.UseCnt = 1;
    NodeRef ref = { &pdefImpl, &info };
    FUN_1424d4220(&LoadedMovieDefs, &LoadedMovieDefs, &ref, reinterpret_cast<UPInt>(pdefImpl));
}

// MovieRoot::AddInvokeAlias: maps alias to the closure invoked for it, creating the alias hash (+0x80) on first use.
// The AS3 MovieRoot header has no declaration, so it is a free function taking the root.
// MS2-FUNCTIONAL: free function in place of the MovieRoot member
// @0x1424e8ae0
void Sfr21AddInvokeAlias(MovieRoot* self, const ASString& alias, const Value& closure)
{
    ASStringHash<Value>*& aliases = reinterpret_cast<ASStringHash<Value>*&>(self->pInvokeAliases);
    if (!aliases)
        aliases = SF_NEW ASStringHash<Value>();
    aliases->Set(alias, closure);
}

// ASRefCountCollector::AdvanceFrame: a movie's frame of the shared collector. A movie that has not seen the latest
// collection restarts its count; one behind the collector's frame count just counts. Otherwise the collector advances
// and collects when the roots outgrow the limit (or, every MaxFramesBetweenCollections frames, the preset count), then
// sets the next limit from the roots left (at least 0.7 of them, at least the peak).
// MS2-FUNCTIONAL: free function in place of the ASRefCountCollector member (not declared in as3_gc.h)
// @0x1424eaf80
void Sfr21ASGCAdvanceFrame(ASRefCountCollector* gc, unsigned* movieFrameCnt, unsigned* movieLastCollectFrame,
                           ASRefCountCollector::StatsObserver* statsObserver)
{
    if (*movieLastCollectFrame != gc->LastCollectionFrameNum)
    {
        *movieLastCollectFrame = gc->LastCollectionFrameNum;
        *movieFrameCnt = 1;
        return;
    }
    if (*movieFrameCnt < gc->FrameCnt)
    {
        ++*movieFrameCnt;
        return;
    }
    ++gc->TotalFramesCount;
    unsigned frames = ++gc->FrameCnt;
    const unsigned roots = (unsigned)gc->GetRootsCount();
    unsigned peak = roots;
    if (peak < gc->PeakRootCount)
        peak = gc->PeakRootCount;
    gc->PeakRootCount = peak;
    if (!gc->SuspendCnt &&
        ((gc->PresetMaxRootCount != 0 && roots > gc->MaxRootCount) ||
         (gc->MaxFramesBetweenCollections != 0 && frames >= gc->MaxFramesBetweenCollections &&
          roots > gc->PresetMaxRootCount)))
    {
        frames = 0;
        ASRefCountCollector::Stats stats;
        stats.pObserver = statsObserver;
        stats.RootsNumber = 0;
        stats.RootsFreedTotal = 0;
        gc->Collect(&stats);
        unsigned limit;
        if (gc->PresetMaxRootCount < stats.RootsFreedTotal)
        {
            gc->PeakRootCount = roots;
            limit = gc->PresetMaxRootCount;
            peak = roots;
        }
        else
        {
            limit = gc->MaxRootCount;
            peak = gc->PeakRootCount;
        }
        gc->FrameCnt = 0;
        gc->LastPeakRootCount = peak;
        gc->LastCollectedRoots = stats.RootsFreedTotal;
        unsigned left = roots - stats.RootsFreedTotal;
        if (left < limit)
            left = limit;
        const unsigned scaled = (unsigned)(SInt64)((double)left * 0.7);
        if (peak < scaled)
            left = scaled;
        gc->MaxRootCount = left;
        gc->LastCollectionFrameNum = gc->TotalFramesCount;
        frames = gc->FrameCnt;
    }
    gc->LastRootCount = roots;
    *movieFrameCnt = frames;
    *movieLastCollectFrame = gc->LastCollectionFrameNum;
}

void FUN_142504630(ASRefCountCollector* gc, void* advanceStats);   // ASRefCountCollector::ForceCollect

// MovieRoot::AdvanceFrame: until the main movie's loader events are done, fires its loaderInfo init (once), progress
// (each full frame, or once loading has finished) and complete events. An invalidated stage gets its RENDER events run
// right away. A full frame runs a collection System.gc scheduled, then advances the collector.
// MS2-FUNCTIONAL: the scheduled collection is called through its exe address
// @0x1424eb2f0
void MovieRoot::AdvanceFrame(bool nextFrame)
{
    void* advanceStats = *reinterpret_cast<void* const*>(&pMovieImpl->pAdvanceStats);
    if (!(MainLoaderInfoEventsState & 2))
    {
        MovieDefImpl* md = pMovieImpl->pMainMovie->GetResourceMovieDef();
        DisplayObjContainer* rt = GetRootMovie418(NULL);
        SPtr<Instances::fl_display::DisplayObject> as3obj = ToAvmDisplayObj(AsDisplayObject(rt))->GetAS3Obj();
        if (as3obj && as3obj->HasLoaderInfo())
        {
            if (!(MainLoaderInfoEventsState & 1))
            {
                as3obj->pLoaderInfo->ExecuteInitEvent(reinterpret_cast<GFx::DisplayObject*>(rt));
                MainLoaderInfoEventsState |= 1;
            }
            const bool loadingFinished = md->GetLoadingFrame() >= md->GetFrameCount();
            if (nextFrame || loadingFinished)
                as3obj->pLoaderInfo->ExecuteProgressEvent(md->pBindData->GetBytesLoaded(),
                                                          md->GetDataDef()->GetFileBytes());
            if (loadingFinished)
            {
                as3obj->pLoaderInfo->ExecuteCompleteEvent();
                MainLoaderInfoEventsState |= 2;
            }
        }
        else
            MainLoaderInfoEventsState |= 2;
    }
    if (StageInvalidated)
    {
        reinterpret_cast<EventChains*>(&mEventChains)->QueueEvents(static_cast<EventId::IdCode>(0x1000013));   // Event_Render
        DoActions();
        StageInvalidated = false;
    }
    if (nextFrame)
    {
        ASRefCountCollector* gc = MemContext->ASGC;
        if (gc)
        {
            if (gc->CollectionScheduledFlags)
            {
                gc->CollectionScheduledFlags = 0;
                FUN_142504630(gc, advanceStats);
            }
            Sfr21ASGCAdvanceFrame(gc, &NumAdvancesSinceCollection, &LastCollectionFrame,
                                  static_cast<ASRefCountCollector::StatsObserver*>(advanceStats));
        }
    }
}

// AvmSprite::AdvanceFrame: drags the sprite with the mouse; on a full frame (unless its frame is already queued) a
// playing sprite moves on, and a new frame runs its init actions and frame tags, flags the frame for execution and
// puts the sprite back on the optimized play list. Looping back to frame 0 unloads the marked children.
// MS2-FUNCTIONAL: follows the exe's order of checks
// @0x1424eb130
void AvmSprite::AdvanceFrame(bool nextFrame, float framePos)
{
    SF_UNUSED(framePos);
    Ptr<Sprite> spr = GetSprite();
    if (spr->IsAdvanceDisabled() || spr->IsUnloading())
        return;
    if (GetMovieImpl()->IsMouseSupportEnabled())
        spr->DoMouseDrag();
    if (nextFrame && !(SprFlags & Flag_NeedExecuteFrame))
    {
        unsigned currentFrame = spr->GetCurrentFrame();
        if (spr->GetPlayState() == State_Playing)
        {
            const unsigned currentFrame0 = currentFrame;
            spr->IncrementFrameAndCheckForLoop();
            currentFrame = spr->GetCurrentFrame();
            if (currentFrame != currentFrame0)
            {
                ExecuteInitActionFrameTags(currentFrame);
                spr->ExecuteFrameTags(currentFrame);
                SprFlags |= Flag_NeedExecuteFrame;
                if (GetSprite()->IsInPlayList())
                    GetSprite()->AddToOptimizedPlayList();
            }
        }
        if (currentFrame == 0)
            GetSprite()->mDisplayList.UnloadMarkedObjects(GetSprite());
    }
}

// Add: the "+" operator. Two XML objects are joined by the VM's XML support; with a string operand both sides are
// concatenated as strings; two other primitives are summed as numbers; anything else is first made primitive.
// MS2-FUNCTIONAL: functional recovery
// @0x1424e5f50
CheckResult Add(StringManager& sm, Value& result, const Value& l, const Value& r)
{
    if (l.IsObject() && r.IsObject() && l.GetObject() && r.GetObject())
    {
        Object* obj = l.GetObject();
        const XMLSupport& xmls = obj->GetVM().GetXMLSupport();
        if (xmls.Add(result, *l.GetObject(), *r.GetObject()))
            return true;
    }

    if (l.IsString() || r.IsString())
    {
        ASString left(sm.CreateEmptyString());
        ASString right(sm.CreateEmptyString());
        if (l.Convert2String(left) && r.Convert2String(right))
        {
            result = left + right;
            return true;
        }
        return false;
    }

    if (l.IsPrimitive() && r.IsPrimitive())
    {
        Value::Number lnum = 0.0;
        Value::Number rnum = 0.0;
        if (l.Convert2NumberInline(lnum) && r.Convert2NumberInline(rnum))
        {
            result.SetNumber(lnum + rnum);
            return true;
        }
        return false;
    }

    Value lprim;
    Value rprim;
    if (l.Convert2PrimitiveValueUnsafe(lprim) && r.Convert2PrimitiveValueUnsafe(rprim))
        return Add(sm, result, lprim, rprim);
    return false;
}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace Render {

void* FUN_142532060(void* self, UPInt n);   // LinearHeap::allocFromLastPage

// LinearHeap::Alloc (header inline, an exe COMDAT): rounds size up to pointer size and bump-allocates from the last
// page; past it, moves to the next page slot, creating the 64-slot pool on first use and doubling it when full.
// The heap is laid out { pHeap, Granularity, pPagePool, pLastPage, MaxPages } with 0x18-byte page slots.
// MS2-FUNCTIONAL: free function over the LinearHeap layout (its header is in the other kernel tree)
// @0x1424eb4d0
void* Sfr21LinearHeapAlloc(void* self, UPInt size)
{
    struct PageType { UByte* pStart; UByte* pEnd; UByte* pFree; };
    struct Heap { MemoryHeap* pHeap; UPInt Granularity; PageType* pPagePool; PageType* pLastPage; UPInt MaxPages; };
    Heap* h = static_cast<Heap*>(self);
    size = (size + sizeof(UPInt) - 1) & ~(sizeof(UPInt) - 1);
    if (h->pLastPage)
    {
        void* p = FUN_142532060(self, size);
        if (p)
            return p;
        ++h->pLastPage;
    }
    else
    {
        h->pLastPage = h->pPagePool =
            static_cast<PageType*>(h->pHeap->Alloc(64 * sizeof(PageType), static_cast<const AllocInfo*>(0)));
        memset(h->pPagePool, 0, 64 * sizeof(PageType));
        h->MaxPages = 64;
    }
    if (h->pLastPage - h->pPagePool >= SPInt(h->MaxPages))
    {
        UPInt     used = h->pLastPage - h->pPagePool;
        PageType* pool = static_cast<PageType*>(
            h->pHeap->Alloc(h->MaxPages * 2 * sizeof(PageType), static_cast<const AllocInfo*>(0)));
        memcpy(pool, h->pPagePool, h->MaxPages * sizeof(PageType));
        memset(pool + h->MaxPages, 0, h->MaxPages * sizeof(PageType));
        h->pHeap->Free(h->pPagePool);
        h->pPagePool = pool;
        h->MaxPages *= 2;
        h->pLastPage = h->pPagePool + used;
    }
    return FUN_142532060(self, size);
}

}} // namespace Scaleform::Render

namespace Scaleform { namespace GFx {

// Not exe code: abstract probes whose constructors run the implicit constructors of the GFx Avm*Base interfaces, which
// emits their vftables and the deleting destructors of this range.
struct Unk_As3_16zButtonBaseProbe : AvmButtonBase { Unk_As3_16zButtonBaseProbe(); };
struct Unk_As3_16zTextFieldBaseProbe : AvmTextFieldBase { Unk_As3_16zTextFieldBaseProbe(); };
struct Unk_As3_16zSpriteBaseProbe : AvmSpriteBase { Unk_As3_16zSpriteBaseProbe(); };
Unk_As3_16zButtonBaseProbe::Unk_As3_16zButtonBaseProbe() {}
Unk_As3_16zTextFieldBaseProbe::Unk_As3_16zTextFieldBaseProbe() {}
Unk_As3_16zSpriteBaseProbe::Unk_As3_16zSpriteBaseProbe() {}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_GFrameCounter@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2de0
// MS2-FUNCTIONAL 0x1424e3ac0: the exe's ??_G inlines the weak-reference release of mValue, ours calls it.
// MS2-PIN: ??_GStickyVarNode@MovieRoot@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e3ac0
// MS2-PIN: ??_GAvmButtonBase@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2730
// MS2-PIN: ??_GAvmDisplayObjBase@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e27a0
// MS2-PIN: ??_GAvmDisplayObjContainerBase@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2830
// MS2-PIN: ??_GAvmInteractiveObj@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2860
// MS2-PIN: ??_GAvmInteractiveObjBase@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e28b0
// MS2-PIN: ??_GAvmSpriteBase@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e29e0
// MS2-PIN: ??_GAvmStaticText@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2a70
// MS2-PIN: ??_GAvmTextFieldBase@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2b20
// MS2-PIN: ??_GAS3ValueObjectInterface@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2150
// MS2-PIN: ??_GObjectInterface@Value@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e35e0
// MS2-PIN: ??_GFlashUI@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2db0
// MS2-FUNCTIONAL 0x1424e3de0: the exe inlines ~FunctionBase into the deleting destructor, ours calls it.
// MS2-PIN: ??_GUserDefinedFunction@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e3de0
// MS2-PIN: ??_GWideStringStorage@MovieImpl@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e40a0
