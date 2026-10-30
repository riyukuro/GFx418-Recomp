// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 player, the MovieImpl side of the
// Movie interface (GFx_PlayerImpl): the view, background, input state and focus group accessors, the frame and play
// state forwarders to _level0, the AVM root forwarders of Movie, and the movie's lifetime.
// Ninth source of queue unit sfr_gfx_01 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_01i
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425686b0-0x142569a40 .text$mn
// MS2-RANGE: 0x142569c00-0x142569d70 .text$mn
// MS2-RANGE: 0x142569dd0-0x14256a9d0 .text$mn
// MS2-RANGE: 0x14256aa60-0x14256deb0 .text$mn
// MS2-RANGE: 0x14256df40-0x14256fa70 .text$mn
// MS2-RANGE: 0x14256fb80-0x14256fbb0 .text$mn
// MS2-RANGE: 0x14256fd60-0x142576530 .text$mn
// MS2-RANGE: 0x142576750-0x142578f10 .text$mn
// MS2-RANGE: 0x142579060-0x142579270 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#define SF_GFX_PLAYERIMPL
#define MS2_SF_HASH_CLEAR_NOINLINE           // HashSet Clear out of line, as the exe calls it
#include "../include/kernel/sf_alg.h"   // first: Alg::UpperBit out of line, as the exe calls it
#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_displayobjcontainer.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_stickyvarnode.h"
#include "../include/gfx/gfx_movieimplstates.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_log.h"
#include "../include/gfx/gfx_keyboardstate.h"
#include "../include/gfx/gfx_input.h"
#include "../include/gfx/gfx_event.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_playertasks.h"
#include "../include/gfx/gfx_drawingcontext.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_imagecreator.h"
#include "../include/gfx/gfx_fontmanager.h"
#include "../include/gfx/gfx_fontlib.h"
#include "../include/gfx/gfx_fontmap.h"
#include "../include/gfx/gfx_fontprovider.h"
#include "../include/gfx/gfx_sound.h"
#include "../include/sound/sound_renderer.h"
#include "../include/gfx/gfx_value.h"
#include "../include/gfx/gfx_imecandidateliststyle.h"
#include "../include/gfx/gfx_imemanager.h"
#include "../include/gfx/gfx_asimemanager.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/render/render_color.h"
#include "../include/kernel/sf_msgformat.h"
#include "../include/video/video_as3providernetstream.h"
#include "../include/kernel/sf_timer.h"
#include "../include/kernel/sf_std.h"
#include "../include/kernel/sf_utf8util.h"
#include "../include/kernel/sf_simd.h"
#include "../include/gfx/gfx_asutils.h"
#include "../include/render/render_shapedatafloatmp.h"
#include <stdlib.h>

namespace Scaleform {
// The bounded wide string copy (kernel units, exe 0x1425a4c90).
wchar_t* SF_CDECL SFwcscpy(wchar_t* dest, UPInt destsize, const wchar_t* src);
}

namespace Scaleform { namespace Render {

// The drawable image context (the full class is in the render units); the movie creates it and holds a reference.
class DrawableImageContext : public RefCountBase<DrawableImageContext, Stat_Default_Mem>
{
public:
    DrawableImageContext(ContextImpl::Context* controlContext, ThreadCommandQueue* queue,
                         const Interfaces& defaults = Interfaces());   // 0x1425e9b10

    void* Unrecovered_10[21];   // +0x10 the capture notify base and the context state (render units)
};

// Takes a reference on the provider (as sfr_gfx_06e defines it; ShapeMeshProvider is complete here).
inline void TreeShape::SetShape(ShapeMeshProvider* pshape)
{
    NodeData* data = GetWritableData(Change_Shape);
    if (pshape)
        pshape->AddRef();
    if (data->pMeshProvider)
        data->pMeshProvider->Release();
    data->pMeshProvider = pshape;
    AddToPropagate();
}
static_assert(sizeof(DrawableImageContext) == 0xb8, "DrawableImageContext (GetDrawableImageContext allocates 0xb8)");

}} // namespace Scaleform::Render

namespace Scaleform { namespace GFx {

// The tab order comparers: by tabIndex, or by position (left to right, top to bottom) when no character has one.
// Both are inlined into their sorts (0x142569200 / 0x1425686b0).
class TabIndexSortFunctor
{
public:
    bool operator()(const InteractiveObject* a, const InteractiveObject* b) const
    {
        return a->TabIndex < b->TabIndex;
    }
};
class AutoTabSortFunctor
{
public:
    // Rows are 20 twips high: two characters whose tops, bottoms or centers are that close are on one row and go
    // left to right; otherwise the higher one comes first.
    bool operator()(const InteractiveObject* a, const InteractiveObject* b) const
    {
        Render::Matrix2F ma;
        a->GetLevelMatrix(&ma);
        Render::Matrix2F mb;
        b->GetLevelMatrix(&mb);
        RectF ra = ma.EncloseTransform(a->GetFocusRect());
        RectF rb = mb.EncloseTransform(b->GetFocusRect());
        float cxa = (ra.x1 + ra.x2) * 0.5f, cya = (ra.y1 + ra.y2) * 0.5f;
        float cxb = (rb.x1 + rb.x2) * 0.5f, cyb = (rb.y1 + rb.y2) * 0.5f;
        if (Alg::Abs(ra.y1 - rb.y1) <= 20 || Alg::Abs(ra.y2 - rb.y2) <= 20 || Alg::Abs(cya - cyb) <= 20)
            return cxa < cxb;
        return cya < cyb;
    }
};
// The sorts take the comparers by value from these (the exe loads them from .data).
static TabIndexSortFunctor TabIndexSort;
static AutoTabSortFunctor  AutoTabSort;
// MS2-PIN: ??$QuickSortSliced@V?$ArrayDH@V?$Ptr@VInteractiveObject@GFx@Scaleform@@@Scaleform@@$0BEH@UArrayDefaultPolicy@2@@Scaleform@@VAutoTabSortFunctor@GFx@2@@Alg@Scaleform@@YAXAEAV?$ArrayDH@V?$Ptr@VInteractiveObject@GFx@Scaleform@@@Scaleform@@$0BEH@UArrayDefaultPolicy@2@@1@_K1VAutoTabSortFunctor@GFx@1@@Z 0x1425686b0
// MS2-FUNCTIONAL 0x1425686b0: QuickSortSliced<..., AutoTabSortFunctor>; in one of the five inlined comparer copies the exe adds the x centres as x1 + x2 where ours loads x2 first (same operands otherwise; swapping the source order breaks the other four)

}} // namespace Scaleform::GFx


namespace Scaleform {
// The topmost list's Resize stays out of line in the exe (Clear and RemoveAt call it, 0x1425750b0).
template<> SF_NOINLINE
void ArrayData<Ptr<GFx::InteractiveObject>, AllocatorLH<Ptr<GFx::InteractiveObject>, 0x147>, ArrayDefaultPolicy>::Resize(
    UPInt newSize)
{
    UPInt oldSize = this->Size;
    BaseType::ResizeNoConstruct(this, newSize);
    if (newSize > oldSize)
        AllocatorType::ConstructArray(this->Data + oldSize, newSize - oldSize);
}

// The level list's too (SetLevelMovie's InsertAt, 0x142574fe0).
template<> SF_NOINLINE
void ArrayData<GFx::MovieImpl::LevelInfo, AllocatorLH<GFx::MovieImpl::LevelInfo, 0x147>, ArrayDefaultPolicy>::Resize(
    UPInt newSize)
{
    UPInt oldSize = this->Size;
    BaseType::ResizeNoConstruct(this, newSize);
    if (newSize > oldSize)
        AllocatorType::ConstructArray(this->Data + oldSize, newSize - oldSize);
}

// The level list's RemoveAt, out of line (ReleaseLevelMovie's level != 0 path, 0x142574090).
template<> SF_NOINLINE
void ArrayBase<ArrayData<GFx::MovieImpl::LevelInfo, AllocatorLH<GFx::MovieImpl::LevelInfo, 0x147>, ArrayDefaultPolicy> >::RemoveAt(UPInt index)
{
    if (Data.Size == 1)
    {
        Clear();
    }
    else
    {
        AllocatorType::Destruct(Data.Data + index);
        AllocatorType::CopyArrayForward(Data.Data + index, Data.Data + index + 1, Data.Size - 1 - index);
        --Data.Size;
    }
}


// The level list's dtor, out of line (MovieImpl's dtor calls it, 0x14256a800).
template<> SF_NOINLINE
ArrayDataBase<GFx::MovieImpl::LevelInfo, AllocatorLH<GFx::MovieImpl::LevelInfo, 0x147>, ArrayDefaultPolicy>::~ArrayDataBase()
{
    AllocatorLH<GFx::MovieImpl::LevelInfo, 0x147>::DestructArray(Data, Size);
    AllocatorLH<GFx::MovieImpl::LevelInfo, 0x147>::Free(Data);
}

// The kill list's ResizeNoConstruct stays out of line too (Clear and RemoveAt call it, 0x1425752c0).
template<> SF_NOINLINE
void ArrayDataBase<GFx::MovieImpl::MDKillListEntry, AllocatorGH<GFx::MovieImpl::MDKillListEntry, 0x147>,
                   ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize)
{
    UPInt oldSize = Size;
    if (newSize < oldSize)
    {
        AllocatorType::DestructArray(Data + newSize, oldSize - newSize);
        if (newSize < (Policy.GetCapacity() >> 1))
            Reserve(pheapAddr, newSize);
    }
    else if (newSize >= Policy.GetCapacity())
    {
        Reserve(pheapAddr, newSize + (newSize >> 2));
    }
    Size = newSize;
}

// So does the interval timer list's (PushBack calls it, 0x142575370).
template<> SF_NOINLINE
void ArrayDataBase<Ptr<GFx::ASIntervalTimerIntf>, AllocatorLH<Ptr<GFx::ASIntervalTimerIntf>, 0x147>,
                   ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize)
{
    UPInt oldSize = Size;
    if (newSize < oldSize)
    {
        AllocatorType::DestructArray(Data + newSize, oldSize - newSize);
        if (newSize < (Policy.GetCapacity() >> 1))
            Reserve(pheapAddr, newSize);
    }
    else if (newSize >= Policy.GetCapacity())
    {
        Reserve(pheapAddr, newSize + (newSize >> 2));
    }
    Size = newSize;
}
} // namespace Scaleform

namespace Scaleform { namespace GFx {

// The text replacement state (the full class is in sfr_gfx_02f); the font states only release it.
class Translator : public State
{
};

// The host's fscommand handler state (the movie only holds it).
class FSCommandHandler : public State
{
};

// Releases and clears a state pointer the movie holds only while it advances.
template<class C>
class AdvanceStateGuard
{
    C** ppObject;
public:
    AdvanceStateGuard(C** pp) : ppObject(pp) {}
    ~AdvanceStateGuard()
    {
        if (*ppObject)
        {
            (*ppObject)->Release();
            *ppObject = 0;
        }
    }
};

// The AVM root's vftable as the player calls it (ASMovieRootBase carries no virtuals in our headers): 4.1.18 slot
// order, the slots the player does not call left unnamed.
class __declspec(novtable) ASMovieRootSlots418
{
public:
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void AdvanceFrame(bool playingFrame) = 0;                                          // 2
    virtual void ChangeMouseCursorType(unsigned mouseIdx, unsigned newCursorType) = 0;          // 3
    virtual void Slot04() = 0;
    virtual void ClearDisplayList() = 0;                                                       // 5
    virtual void Slot06() = 0;
    virtual void DoActions() = 0;                                                              // 7
    virtual void Slot08() = 0;
    virtual void ForceCollect() = 0;                                                            // 9
    virtual void Slot10() = 0;
    virtual void GenerateMouseEvents(unsigned mouseIndex) = 0;                                  // 11
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual DisplayObjectBase* GetRootMovie(DisplayObjectBase* dobj = 0) const = 0;            // 14
    virtual bool Init(MovieDefImpl* pmovieDef) = 0;                                          // 15
    virtual void NotifyMouseState(const InputEventsQueueEntry* qe, const MouseState* ms, int mi) = 0; // 16
    virtual void NotifyOnResize() = 0;                                                         // 17
    virtual void NotifyQueueSetFocus(InteractiveObject* ch, unsigned controllerIdx, FocusMovedType fmt) = 0; // 18
    virtual void NotifyTransferFocus(InteractiveObject* curFocused, InteractiveObject* pnewFocus,
                                     unsigned controllerIdx) = 0;                               // 19
    virtual bool NotifyOnFocusChange(InteractiveObject* curFocused, InteractiveObject* toBeFocused,
                                     unsigned controllerIdx, FocusMovedType fmt,
                                     ProcessFocusKeyInfo* pfocusKeyInfo) = 0;                   // 20
    virtual void OnMovieFocus(bool set) = 0;                                                   // 21
    virtual void OnNextFrame() = 0;                                                            // 22
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void PrintObjectsReport(UInt32 flags, Log* log, const char* swfName) = 0;          // 25
    virtual void ProcessLoadQueueEntry(LoadQueueEntry* pentry, LoadStates* pls) = 0;        // 26
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual void Slot30() = 0;
    virtual void SetExternalInterfaceRetVal(const Value& retVal) = 0;                           // 31
    virtual void Slot32() = 0;
    virtual void Shutdown() = 0;                                                               // 33
    virtual void CreateString(Value* pvalue, const char* pstring) = 0;                          // 34
    virtual void CreateStringW(Value* pvalue, const wchar_t* pstring) = 0;                      // 35
    virtual void CreateObject(Value* pvalue, const char* className, const Value* pargs, unsigned nargs) = 0; // 36
    virtual void CreateArray(Value* pvalue) = 0;                                                // 37
    virtual void CreateFunction(Value* pvalue, FunctionHandler* pfc, void* puserData) = 0;      // 38
    virtual bool SetVariable(const char* ppathToVar, const Value& value, Movie::SetVarType setType) = 0; // 39
    virtual bool GetVariable(Value* pval, const char* ppathToVar) const = 0;                    // 40
    virtual void Slot41() = 0;
    virtual void Slot42() = 0;
    virtual void Slot43() = 0;
    virtual void Slot44() = 0;
    virtual void Slot45() = 0;
    virtual void Slot46() = 0;
    virtual bool Invoke(const char* ppathToMethod, Value* presult, const Value* pargs, unsigned numArgs) = 0; // 47
    virtual bool InvokeArgs(const char* ppathToMethod, Value* presult, const char* pargFmt, va_list args) = 0; // 48
    virtual MemoryContext* GetMemoryContext() const = 0;                                         // 49
    virtual ASStringManager* GetStringManager() const = 0;                                      // 50
    virtual Render::Text::Allocator* GetTextAllocator() = 0;                                    // 51
};

static inline ASMovieRootSlots418* AsRootSlots(ASMovieRootBase* proot)
{
    return reinterpret_cast<ASMovieRootSlots418*>(proot);
}

namespace AMP {
// The movie's advance statistics (AMP; only the call the player makes).
class ViewStats : public RefCountBase<ViewStats, Stat_Default_Mem>
{
public:
    void GetStats(::Scaleform::StatBag* pbag, bool reset);   // exe 0x142622740
    void SetName(const char* pname);                         // exe 0x142624660 (the file name, path stripped)
};
} // namespace AMP

// A flag test kept as its own inline (the player tests Flags/Flags2 bits through it).
template<UInt32 mask>
inline bool IsFlagSet(UInt32 value)
{
    return (value & mask) != 0;
}
// The matching flag setter.
template<UInt32 mask>
inline void SetFlag(UInt32& value, bool set)
{
    if (set)
        value |= mask;
    else
        value &= ~mask;
}

// ---------------------------------------------------------------------------------------------------------------
// Movie: the AVM root forwarders

// @0x14256e3e0
void Movie::CreateArray(Value* pvalue)
{
    AsRootSlots(pASMovieRoot)->CreateArray(pvalue);
}

// @0x14256e4c0
void Movie::CreateFunction(Value* pvalue, FunctionHandler* pfc, void* puserData)
{
    AsRootSlots(pASMovieRoot)->CreateFunction(pvalue, pfc, puserData);
}

// @0x14256e8e0
void Movie::CreateObject(Value* pvalue, const char* className, const Value* pargs, unsigned nargs)
{
    AsRootSlots(pASMovieRoot)->CreateObject(pvalue, className, pargs, nargs);
}

// @0x14256e8f0
void Movie::CreateString(Value* pvalue, const char* pstring)
{
    AsRootSlots(pASMovieRoot)->CreateString(pvalue, pstring);
}

// @0x14256e900
void Movie::CreateStringW(Value* pvalue, const wchar_t* pstring)
{
    AsRootSlots(pASMovieRoot)->CreateStringW(pvalue, pstring);
}

// @0x14256eff0
int Movie::GetAVMVersion() const
{
    return pASMovieRoot->AVMVersion;
}

// @0x1425700a0
bool Movie::GetVariable(Value* pval, const char* ppathToVar) const
{
    return AsRootSlots(pASMovieRoot)->GetVariable(pval, ppathToVar);
}

// @0x142571000
bool Movie::Invoke(const char* ppathToMethod, Value* presult, const char* pargFmt, ...)
{
    va_list args;
    va_start(args, pargFmt);
    bool result = AsRootSlots(pASMovieRoot)->InvokeArgs(ppathToMethod, presult, pargFmt, args);
    va_end(args);
    return result;
}

// @0x142571030
bool Movie::Invoke(const char* ppathToMethod, Value* presult, const Value* pargs, unsigned numArgs)
{
    return AsRootSlots(pASMovieRoot)->Invoke(ppathToMethod, presult, pargs, numArgs);
}

// @0x142571040
bool Movie::InvokeArgs(const char* ppathToMethod, Value* presult, const char* pargFmt, va_list args)
{
    return AsRootSlots(pASMovieRoot)->InvokeArgs(ppathToMethod, presult, pargFmt, args);
}

// The last reference keeps the AVM's memory context alive until the movie is gone (its heap goes with it).
// @0x142573e70
void Movie::Release()
{
    if (AtomicOps<int>::ExchangeAdd_NoSync(&RefCount, -1) == 1)
    {
        Ptr<MemoryContext> memContext = AsRootSlots(pASMovieRoot)->GetMemoryContext();
        delete this;
    }
}

// @0x142575b00
void Movie::SetExternalInterfaceRetVal(const Value& retVal)
{
    AsRootSlots(pASMovieRoot)->SetExternalInterfaceRetVal(retVal);
}

// @0x142576820
bool Movie::SetVariable(const char* ppathToVar, const Value& value, SetVarType setType)
{
    return AsRootSlots(pASMovieRoot)->SetVariable(ppathToVar, value, setType);
}

// ---------------------------------------------------------------------------------------------------------------
// MovieImpl: the Movie interface

// @0x14256bbe0
bool MovieImpl::AcceptAnimMovesWith3D() const
{
    return (UByte)Flags2 & 1;
}

// @0x14256ee20
void MovieImpl::ForceCollectGarbage()
{
    AsRootSlots(pASMovieRoot)->ForceCollect();
}

// @0x14256ee30
void MovieImpl::ForceUpdateImages()
{
    RenderContext.ForceUpdateImages();
    ++PreviouslyCaptured;
}

// @0x14256f000
float MovieImpl::GetBackgroundAlpha() const
{
    return ((const Render::Color*)&BackgroundColor)->GetAlpha() / 255.0f;
}

// @0x14256f020
unsigned MovieImpl::GetControllerCount() const
{
    return ControllerCount;
}

// @0x14256f030
unsigned MovieImpl::GetControllerFocusGroup(unsigned controllerIdx) const
{
    if (controllerIdx >= 16)
        return 0;
    return FocusGroupIndexes[controllerIdx];
}

// @0x14256f1a0
unsigned MovieImpl::GetCurrentFrame() const
{
    return pMainMovie ? pMainMovie->GetCurrentFrame() : 0;
}

// The render context's changes count too; doReset clears only the movie's own flag.
// @0x14256f1c0
bool MovieImpl::GetDirtyFlag(bool doReset)
{
    bool dirty = IsFlagSet<0x400>(Flags) ||
                 RenderContext.HasChanges();
    if (doReset)
        Flags &= ~0x400u;
    return dirty;
}

// @0x14256f210
const Render::ContextImpl::DisplayHandle<Render::TreeRoot>& MovieImpl::GetDisplayHandle() const
{
    return hDisplayRoot;
}

// @0x14256f2b0
Render::EdgeAAMode MovieImpl::GetEdgeAAMode() const
{
    return pRenderRoot->GetEdgeAAMode();
}

// @0x14256f300
MemoryHeap* MovieImpl::GetHeap() const
{
    return pHeap;
}

// Mouse positions are kept in twips; the host gets window pixels.
// @0x14256f890
void MovieImpl::GetMouseState(unsigned mouseIndex, float* x, float* y, unsigned* buttons)
{
    if (mouseIndex >= MouseCursorCount)
        return;
    const MouseState& ms = mMouseState[mouseIndex];
    float px = (Render::TwipsToPixels(ms.LastPosition.x) - ViewOffsetX) / ViewScaleX;
    float py = (Render::TwipsToPixels(ms.LastPosition.y) - ViewOffsetY) / ViewScaleY;
    if (x)
        *x = px;
    if (y)
        *y = py;
    if (buttons)
        *buttons = ms.CurButtonsState;
}

// @0x14256f880
unsigned MovieImpl::GetMouseCursorCount() const
{
    return MouseCursorCount;
}

// @0x14256f910
MovieDef* MovieImpl::GetMovieDef() const
{
    return (MovieDef*)pMainMovieDef.GetPtr();
}

// @0x14256f930
PlayState MovieImpl::GetPlayState() const
{
    if (!pMainMovie)
        return State_Stopped;
    return pMainMovie->GetPlayState();
}

// @0x14256f950
void MovieImpl::GetProjectionMatrix3D(Render::Matrix4x4<float>* m)
{
    if (DisplayObjectBase* proot = AsRootSlots(pASMovieRoot)->GetRootMovie())
        proot->GetProjectionMatrix3D(m);
}

// @0x14256fa40
Render::RectF MovieImpl::GetSafeRect() const
{
    return SafeRect;
}

// @0x14256fd60
void MovieImpl::GetStats(::Scaleform::StatBag* pbag, bool reset)
{
    if (pAdvanceStats)
        static_cast<AMP::ViewStats*>(pAdvanceStats)->GetStats(pbag, reset);
}

// @0x14256fdd0
Render::Text::Allocator* MovieImpl::GetTextAllocator()
{
    return AsRootSlots(pASMovieRoot)->GetTextAllocator();
}

// @0x142570090
void* MovieImpl::GetUserData() const
{
    return UserData;
}

// @0x1425700d0
Movie::AlignType MovieImpl::GetViewAlignment() const
{
    return (AlignType)ViewAlignment;
}

// @0x1425700e0
void MovieImpl::GetViewMatrix3D(Render::Matrix3x4<float>* m)
{
    if (DisplayObjectBase* proot = AsRootSlots(pASMovieRoot)->GetRootMovie())
        proot->GetViewMatrix3D(m);
}

// @0x142570120
Movie::ScaleModeType MovieImpl::GetViewScaleMode() const
{
    return (ScaleModeType)ViewScaleMode;
}

// @0x142570130
void MovieImpl::GetViewport(Viewport* pviewDesc) const
{
    *pviewDesc = mViewport;
}

// @0x142570160
bool MovieImpl::GetVisible() const
{
    return pMainMovie ? pMainMovie->GetVisible() : false;
}

// @0x142570180
Render::RectF MovieImpl::GetVisibleFrameRect() const
{
    return Render::RectF(Render::TwipsToPixels(VisibleFrameRect.x1), Render::TwipsToPixels(VisibleFrameRect.y1),
                         Render::TwipsToPixels(VisibleFrameRect.x2), Render::TwipsToPixels(VisibleFrameRect.y2));
}

// @0x1425701a0
void MovieImpl::GotoFrame(unsigned frameNumber)
{
    if (pMainMovie)
        pMainMovie->GotoFrame(frameNumber);
}

// @0x1425701c0
bool MovieImpl::GotoLabeledFrame(const char* plabel, int offset)
{
    if (!pMainMovie)
        return false;
    unsigned frameNumber = ~0u;
    if (pMainMovieDef->pBindData->GetDataDef()->GetLabeledFrame(plabel, &frameNumber, false))
    {
        GotoFrame(frameNumber + offset);
        return true;
    }
    if (Ptr<LogState> log = GetStateBag()->GetLogState())
        log->LogScriptError("MovieImpl::GotoLabeledFrame('%s') unknown label", plabel);
    return false;
}

// @0x142570900
bool MovieImpl::HasLooped() const
{
    return pMainMovie ? pMainMovie->HasLooped() : false;
}

// @0x142571060
bool MovieImpl::IsExitRequested() const
{
    return (Flags >> 21) & 1;
}

// @0x142571140
bool MovieImpl::IsMovieFocused() const
{
    return (Flags >> 18) & 1;
}

// @0x142571150
bool MovieImpl::IsPaused() const
{
    return (Flags >> 20) & 1;
}

// @0x142571160
bool MovieImpl::IsShutdownRenderingComplete() const
{
    return RenderContext.IsShutdownComplete();
}

// @0x142571170
bool MovieImpl::IsShutdowning() const
{
    return !pRenderRoot || IsFlagSet<0x4>(Flags2);
}

// @0x142572040
void MovieImpl::PrintObjectsReport(UInt32 flags, Log* log, const char* swfName)
{
    AsRootSlots(pASMovieRoot)->PrintObjectsReport(flags, log, swfName);
}

// @0x142574c50
void MovieImpl::ResetInputFocus(unsigned controllerIdx)
{
    SetFocusTo(NULL, controllerIdx, GFx_FocusMovedByAS);
}

// @0x142574c60
void MovieImpl::ResetKeyboardState()
{
    KeyboardState* pkeyboards = reinterpret_cast<KeyboardState*>(KeyboardStates);
    for (unsigned i = 0; i < 4; ++i)
        pkeyboards[i].ResetState();
}

// @0x142575900
void MovieImpl::RestoreViewport()
{
    ResetViewportMatrix();
    pRenderRoot->SetMatrix(ViewportMatrix);
}

// @0x142575930
void MovieImpl::SetASMovieRoot(ASMovieRootBase* pasMovieRoot)
{
    pSavedASMovieRoot = pasMovieRoot;
    pASMovieRoot      = pSavedASMovieRoot;
}

// @0x1425759a0
void MovieImpl::SetActionErrorsSuppress(bool suppressErrors)
{
    if (suppressErrors)
        Flags |= 0x40;
    else
        Flags &= ~0x40u;
}

// @0x1425759c0
void MovieImpl::SetBackgroundAlpha(float alpha)
{
    UByte a = (UByte)(int)(alpha * 255.0f);
    reinterpret_cast<UByte*>(&BackgroundColor)[3] = a < 255 ? a : 255;
    static_cast<Render::TreeRoot*>(pRenderRoot)->SetBackgroundColor(*(Render::Color*)&BackgroundColor);
}

// @0x142575a00
void MovieImpl::SetBackgroundColor(const Render::Color bgColor)
{
    Render::Color& bg = *(Render::Color*)&BackgroundColor;
    bg = bgColor;
    static_cast<Render::TreeRoot*>(pRenderRoot)->SetBackgroundColor(bg);
}

// @0x142575a90
void MovieImpl::SetCaptureThread(void* captureThreadId)
{
    RenderContext.SetCaptureThreadId(captureThreadId);
}

// @0x142575aa0
void MovieImpl::SetControllerCount(unsigned n)
{
    ControllerCount = n <= 4 ? n : 4;
}

// @0x142575ac0
bool MovieImpl::SetControllerFocusGroup(unsigned controllerIdx, unsigned focusGroupIndex)
{
    if (controllerIdx >= 16 || focusGroupIndex >= 16)
        return false;
    FocusGroupIndexes[controllerIdx] = (UByte)focusGroupIndex;
    if (focusGroupIndex >= FocusGroupsCnt)
        FocusGroupsCnt = focusGroupIndex + 1;
    return true;
}

// @0x142575af0
void MovieImpl::SetEdgeAAMode(Render::EdgeAAMode edgeAA)
{
    pRenderRoot->SetEdgeAAMode(edgeAA);
}

// @0x142576270
void MovieImpl::SetMouseCursorCount(unsigned n)
{
    MouseCursorCount = n <= 4 ? n : 4;
}

// @0x142576470
void MovieImpl::SetPlayState(PlayState s)
{
    if (pMainMovie)
        pMainMovie->SetPlayState(s);
}

// @0x142576490
void MovieImpl::SetProjectionMatrix3D(const Render::Matrix4x4<float>& m)
{
    if (DisplayObjectBase* proot = AsRootSlots(pASMovieRoot)->GetRootMovie())
        proot->SetProjectionMatrix3D(m);
}

// @0x1425764d0
void MovieImpl::SetSafeRect(const Render::RectF& rect)
{
    SafeRect = rect;
}

// @0x142576500
void MovieImpl::SetStageAutoOrients(bool v)
{
    if (v)
        Flags |= 0x4000;
    else
        Flags &= ~0x4000u;
}

// @0x142576810
void MovieImpl::SetUserData(void* ud)
{
    UserData = ud;
}

// @0x142576850
void MovieImpl::SetVerboseAction(bool verboseAction)
{
    if (verboseAction)
        Flags |= 0x4;
    else
        Flags &= ~0x4u;
}

// The view is set up again for the new alignment (the viewport's change count bumped so it is not skipped).
// @0x142576870
void MovieImpl::SetViewAlignment(AlignType align)
{
    ViewAlignment = align;
    Viewport desc = mViewport;
    ++mViewport.Flags;
    SetViewport(desc);
}

// @0x142576920
void MovieImpl::SetViewMatrix3D(const Render::Matrix3x4<float>& m)
{
    if (DisplayObjectBase* proot = AsRootSlots(pASMovieRoot)->GetRootMovie())
        proot->SetViewMatrix3D(m);
}

// @0x142576960
void MovieImpl::SetViewScaleMode(ScaleModeType scaleMode)
{
    ViewScaleMode = scaleMode;
    Viewport desc = mViewport;
    ++mViewport.Flags;
    SetViewport(desc);
}

// @0x142576c30
void MovieImpl::SetVisible(bool visible)
{
    if (pMainMovie)
        pMainMovie->SetVisible(visible);
}

// @0x142576c50
void MovieImpl::ShutdownRendering(bool wait)
{
    RenderContext.Shutdown(wait);
}

// ---------------------------------------------------------------------------------------------------------------
// MovieImpl: the load queues, input states, focus groups, timers and lists

// @0x14256bdf0
void MovieImpl::AddLoadQueueEntry(LoadQueueEntry* pentry)
{
    pentry->EntryTime = ++LastLoadQueueEntryCnt;
    if (!pLoadQueueHead)
    {
        pLoadQueueHead = pentry;
    }
    else
    {
        LoadQueueEntry* plast = pLoadQueueHead;
        while (plast->pNext)
            plast = plast->pNext;
        plast->pNext = pentry;
    }
}

// @0x14256be30
void MovieImpl::AddLoadQueueEntryMT(LoadQueueEntryMT* pentryMT)
{
    pentryMT->pQueueEntry->EntryTime = ++LastLoadQueueEntryCnt;
    if (!pLoadQueueMTHead)
    {
        pLoadQueueMTHead = pentryMT;
    }
    else
    {
        LoadQueueEntryMT* plast = pLoadQueueMTHead;
        while (plast->pNext)
            plast = plast->pNext;
        plast->pNext = pentryMT;
        pentryMT->pPrev = plast;
    }
}

// @0x142574ca0
void MovieImpl::ResetMouseState()
{
    MouseState* pstates = mMouseState;
    for (unsigned i = 0; i < 4; ++i)
        pstates[i].ResetState();
}

// @0x142575ec0
void MovieImpl::SetKeyboardListener(KeyboardState::IListener* l)
{
    for (unsigned i = 0; i < 4; ++i)
        KeyboardStates[i].SetListener(l);
}

// @0x14256ed00
FontManager* MovieImpl::FindFontManager(MovieDefImpl* pdefImpl)
{
    MovieDefRootNode* pnode = RootMovieDefNodes.pNext;
    MovieDefRootNodeLinks* proot = &RootMovieDefNodes;
    while (pnode != static_cast<MovieDefRootNode*>(proot))
    {
        if (pnode->pDefImpl == pdefImpl && pnode->pFontManager)
            return pnode->pFontManager;
        pnode = pnode->pNext;
    }
    return 0;
}

// @0x14256f7e0
Sprite* FocusGroupDescr::GetModalClip(MovieImpl* proot)
{
    if (ModalClip)
    {
        Ptr<DisplayObject> pchar = ModalClip->ResolveCharacter(proot);
        if (pchar)
            return (Sprite*)pchar.GetPtr();
    }
    return 0;
}

// @0x14256f820
Sprite* MovieImpl::GetModalClip(unsigned controllerIdx)
{
    return FocusGroups[FocusGroupIndexes[controllerIdx]].GetModalClip(this);
}

// @0x14256f730
bool MovieImpl::GetMainMoviePath(String* ppath) const
{
    if (pMainMovie)
    {
        *ppath = ((MovieDef*)pMainMovieDef.GetPtr())->GetFileURL();
        if (URLBuilder::ExtractFilePath(ppath))
            return true;
    }
    ppath->Clear();
    return false;
}

// @0x142577c10
void MovieImpl::UpdateAllDrawingContexts()
{
    DrawingContext* pdc = DrawingContextList.GetFirst();
    while (!DrawingContextList.IsNull(pdc))
    {
        if (pdc->IsDirty())
            pdc->UpdateRenderNode();
        pdc = DrawingContextList.GetNext(pdc);
    }
}

// Rebuilds the focus rectangles over the stage: per focus group whose focus came from the keyboard, a shape of four
// one pixel (20 twip) bars around the world bounds of the focused character, each group 20 twips further out and in
// its own color. A focused character with an empty focus rectangle ends the update with FocusRectChanged still set.
// @0x142577cd0
// MS2-FUNCTIONAL
void MovieImpl::UpdateFocusRectRenderNodes()
{
    if (!pMainMovie)
        return;
    if (!FocusRectContainerNode)
    {
        FocusRectContainerNode = *RenderContext.CreateEntry<Render::TreeContainer>();
        pRenderRoot->Insert(pRenderRoot->GetSize(), FocusRectContainerNode);
    }
    else
        FocusRectContainerNode->Remove(0, FocusRectContainerNode->GetSize());

    for (unsigned i = 0; i < FocusGroupsCnt; ++i)
    {
        FocusGroupDescr& focusGroup = FocusGroups[i];
        Ptr<InteractiveObject> curFocused = focusGroup.LastFocused;
        if (!curFocused || !focusGroup.FocusRectShown || !curFocused->IsFocusRectEnabled())
            continue;

        Render::RectF focusLocalRect = curFocused->GetFocusRect();
        if (focusLocalRect.IsNull())
            return;
        Render::Matrix3F worldMat;
        curFocused->GetWorldMatrix3D(&worldMat);
        Render::Matrix3F mat(worldMat);
        Render::RectF r = mat.EncloseTransform(focusLocalRect);

        const float width  = 20.f;
        const float offset = float(i) * width;
        r.x1 -= offset;
        r.x2 += offset;
        r.y1 -= offset;
        r.y2 += offset;

        Ptr<Render::ShapeDataFloat> shapeData = *SF_HEAP_AUTO_NEW(this) Render::ShapeDataFloat();
        Render::FillStyleType fill;
        fill.Color = 0xFF000000u | (0xFFFF00u ^ (i * 0x1080D0u));
        shapeData->AddFillStyle(fill);

        // top, right, bottom, left
        shapeData->StartPath(1, 0, 0);
        shapeData->MoveTo(r.x1, r.y1);
        shapeData->LineTo(r.x2, r.y1);
        shapeData->LineTo(r.x2, r.y1 + width);
        shapeData->LineTo(r.x1, r.y1 + width);
        shapeData->ClosePath();
        shapeData->EndPath();

        shapeData->StartPath(1, 0, 0);
        shapeData->MoveTo(r.x2, r.y1);
        shapeData->LineTo(r.x2, r.y2);
        shapeData->LineTo(r.x2 - width, r.y2);
        shapeData->LineTo(r.x2 - width, r.y1);
        shapeData->ClosePath();
        shapeData->EndPath();

        shapeData->StartPath(1, 0, 0);
        shapeData->MoveTo(r.x2, r.y2);
        shapeData->LineTo(r.x1, r.y2);
        shapeData->LineTo(r.x1, r.y2 - width);
        shapeData->LineTo(r.x2, r.y2 - width);
        shapeData->ClosePath();
        shapeData->EndPath();

        shapeData->StartPath(1, 0, 0);
        shapeData->MoveTo(r.x1, r.y2);
        shapeData->LineTo(r.x1, r.y1);
        shapeData->LineTo(r.x1 + width, r.y1);
        shapeData->LineTo(r.x1 + width, r.y2);
        shapeData->ClosePath();
        shapeData->EndPath();
        shapeData->EndShape();

        // (the exe also builds a provider over the shape that it never uses)
        Ptr<Render::ShapeMeshProvider> unusedProv = *SF_HEAP_AUTO_NEW(this) Render::ShapeMeshProvider(shapeData);
        Ptr<Render::ShapeMeshProvider> meshProv   = *SF_HEAP_AUTO_NEW(this) Render::ShapeMeshProvider(shapeData);
        Ptr<Render::TreeShape> shapeNode = *RenderContext.CreateEntry<Render::TreeShape>();
        shapeNode->SetShape(meshProv);
        FocusRectContainerNode->Insert(FocusRectContainerNode->GetSize(), shapeNode);
        focusGroup.FocusRectNode = shapeNode;
    }
    FocusRectChanged = false;
}

// @0x14256dc00
void MovieImpl::ChangeMouseCursorType(unsigned mouseIdx, unsigned newCursorType)
{
    MouseState& ms = mMouseState[mouseIdx];
    if (ms.CursorType != newCursorType)
        AsRootSlots(pASMovieRoot)->ChangeMouseCursorType(mouseIdx, newCursorType);
    ms.CursorType = (ms.PresetCursorType == ~0u) ? newCursorType : ms.PresetCursorType;
}

// @0x14256e150
void MovieImpl::ClearPlayList()
{
    for (InteractiveObject* pcur = pPlayList; pcur; )
    {
        InteractiveObject* pnext = pcur->pPlayNext;
        pcur->pPlayPrevOpt = NULL;
        pcur->pPlayNextOpt = NULL;
        pcur->pPlayPrev = NULL;
        pcur->pPlayNext = NULL;
        pcur = pnext;
    }
    pPlayListOptHead = NULL;
    pPlayList = NULL;
}

// @0x14256f920
MovieImpl::MultitouchInputMode MovieImpl::GetMultitouchInputMode() const
{
    return (MultitouchInputMode)MultitouchMode;
}

// @0x14256f780
unsigned MovieImpl::GetMaxTouchPoints() const
{
    Ptr<MultitouchInterface> mi = GetMultitouchInterface();
    if (mi && (MultitouchMode & MTI_TouchPoint))
        return mi->GetMaxTouchPoints();
    return 0;
}

// @0x14256fd70
UInt32 MovieImpl::GetSupportedGesturesMask() const
{
    Ptr<MultitouchInterface> mi = GetMultitouchInterface();
    if (mi && (MultitouchMode & MTI_Gesture))
        return mi->GetSupportedGesturesMask();
    return 0;
}

// @0x142576290
void MovieImpl::SetMultitouchInputMode(MultitouchInputMode mode)
{
    Ptr<MultitouchInterface> mi = GetMultitouchInterface();
    if (mi)
    {
        if (mi->SetMultitouchInputMode(mode))
            MultitouchMode = mode;
    }
}

// @0x14256bd60
int MovieImpl::AddIntervalTimer(ASIntervalTimerIntf* timer)
{
    timer->SetId(++LastIntervalTimerId);
    IntervalTimers.PushBack(timer);
    return LastIntervalTimerId;
}

// Only stops the timer; the advance takes cleared timers off the list.
// @0x14256e0d0
void MovieImpl::ClearIntervalTimer(int id)
{
    for (UPInt i = 0, n = IntervalTimers.GetSize(); i < n; ++i)
    {
        if (IntervalTimers[i] && IntervalTimers[i]->GetId() == id)
        {
            IntervalTimers[i]->Clear();
            break;
        }
    }
}

// @0x14256be80
void MovieImpl::AddMovieDefToKillList(MovieDefImpl* pdefImpl)
{
    if (!pdefImpl)
        return;
    for (UPInt i = 0; i < MovieDefKillList.GetSize(); ++i)
    {
        if (MovieDefKillList[i].pMovieDef == pdefImpl)
        {
            MovieDefKillList[i].KillFrameId =
                RenderContext.GetFrameId();
            return;
        }
    }
    MDKillListEntry e;
    e.KillFrameId = RenderContext.GetFrameId();
    e.pMovieDef = pdefImpl;
    MovieDefKillList.PushBack(e);
}

// @0x142575f10
void ASUserData_SetLastObjectValue(ASUserData* puserData, void* pobjIfc, void* pdata, bool isdobj)
{
    puserData->pLastObjectInterface = pobjIfc;
    puserData->pLastData = pdata;
    puserData->IsLastDispObj = isdobj;
}

// The AS getTimer() clock: milliseconds since the movie started. A test stream in Record mode gets each reading, in
// Play mode it supplies them.
// @0x14256ee60
UInt64 MovieImpl::GetASTimerMs() const
{
    TestStream* ptest = GetTestStream();
    if (ptest)
    {
        if (ptest->TestStatus == TestStream::Record)
        {
            UInt64 t = Timer::GetTicks() / 1000 - StartTickMs;
            LongFormatter f(t);
            f.Convert();
            ptest->SetParameter("timer", f.ToCStr());
            return t;
        }
        String tstr;
        ptest->GetParameter("timer", &tstr);
        return _strtoui64(tstr.ToCStr(), NULL, 10);
    }
    return Timer::GetTicks() / 1000 - StartTickMs;
}

// Freezes or resumes the movie: the AS clock stops while paused, the advancing objects and the videos are told.
// @0x1425762f0
void MovieImpl::SetPause(bool pause)
{
    const UInt32 Flag_Paused = 0x100000;
    if ((IsFlagSet<Flag_Paused>(Flags) && pause) || (!IsFlagSet<Flag_Paused>(Flags) && !pause))
        return;
    if (pause)
        Flags |= Flag_Paused;
    else
        Flags &= ~Flag_Paused;
    UInt64 t = Timer::GetTicks() / 1000;
    if (pause)
        PauseTickMs = t;
    else
        StartTickMs += t - PauseTickMs;

    InteractiveObject* pnext = NULL;
    for (InteractiveObject* pch = pPlayList; pch; pch = pnext)
    {
        pnext = pch->pPlayNext;
        pch->SetPause(pause);
    }
    if (VideoProviders.GetSize() > 0)
    {
        for (HashSet<Ptr<Video::VideoProvider> >::Iterator it = VideoProviders.Begin(); it != VideoProviders.End(); ++it)
        {
            Ptr<Video::VideoProvider> pvideo = *it;
            pvideo->Pause(pause);
        }
    }
}

// @0x142576a10
void MovieImpl::SetViewport(const Viewport& viewDesc)
{
    if (memcmp(&viewDesc, &mViewport, sizeof(mViewport)) == 0)
        return;

    int   prevLeft   = mViewport.Left;
    int   prevTop    = mViewport.Top;
    int   prevWidth  = mViewport.Width;
    int   prevHeight = mViewport.Height;
    float prevScale  = mViewport.Scale;
    float prevRatio  = mViewport.AspectRatio;

    SetFlag<0x1>(Flags, true);   // the viewport was set
    mViewport = viewDesc;

    Render::RectF prevVisRect = VisibleFrameRect;
    UpdateViewport();

    if (prevVisRect != VisibleFrameRect ||
        (ViewScaleMode == SM_NoScale &&
            (prevWidth != mViewport.Width || prevHeight != mViewport.Height ||
             prevLeft  != mViewport.Left  || prevTop    != mViewport.Top ||
             prevScale != mViewport.Scale || prevRatio  != mViewport.AspectRatio)) ||
        (ViewScaleMode != SM_ExactFit &&
            (prevWidth != mViewport.Width ||
             prevHeight != mViewport.Height || prevRatio != mViewport.AspectRatio)))
    {
        AsRootSlots(pASMovieRoot)->NotifyOnResize();
    }
    static_cast<Render::TreeRoot*>(pRenderRoot)->SetViewport(mViewport);
    static_cast<Render::TreeRoot*>(pRenderRoot)->SetBackgroundColor(*(Render::Color*)&BackgroundColor);
    static_cast<Render::TreeRoot*>(pRenderRoot)->SetMatrix(ViewportMatrix);
}

// Queues a host mouse update: the move, then a press or a release for every button whose state changed.
// @0x142571e20
void MovieImpl::NotifyMouseState(float x, float y, unsigned buttons, unsigned mouseIndex)
{
    Render::PointF pt(Render::PointF::NoInit);
    ViewportMatrix.TransformByInverse(&pt, Render::PointF(x, y));

    if (mouseIndex < MouseCursorCount)
    {
        GFx::InputEventsQueue* pqueue = &InputEventsQueue;
        pqueue->AddMouseMove(mouseIndex, pt);
        unsigned lastButtons = mMouseState[mouseIndex].CurButtonsState;
        for (unsigned i = 0, mask = 1; i < 16; i++, mask <<= 1)   // MouseButton_MaxNum
        {
            if ((buttons & mask) && !(lastButtons & mask))
                pqueue->AddMouseButtonEvent(mouseIndex, pt, (buttons & mask), 0);
            else if ((lastButtons & mask) && !(buttons & mask))
                pqueue->AddMouseButtonEvent(mouseIndex, pt, (lastButtons & mask),
                                            InputEventsQueueEntry::MouseButton_Released);
        }
    }
}

// @0x142571f10
void MovieImpl::OnMovieFocus(bool set)
{
    if (!set)
    {
        ResetKeyboardState();
        ResetMouseState();
    }
    SetFlag<0x40000>(Flags, set);   // the movie is focused
    Ptr<IMEManagerBase> pimeManager = GetIMEManager();
    if (pimeManager)
    {
        pimeManager->SetActiveMovie(this);
        if (!set)
        {
            // a composition left open is committed as typed
            const wchar_t* pcomposition = pimeManager->GetCompositionString();
            if (pcomposition && SFwcslen(pcomposition) != 0)
            {
                pimeManager->SetWideCursor(false);
                pimeManager->FinalizeComposition(pcomposition);
            }
        }
    }
    AsRootSlots(pASMovieRoot)->OnMovieFocus(set);
}

// The toggle keys (num / caps / scroll lock) of a keyboard as the application reports them.
static __forceinline void SetToggleKeys(KeyboardState* pks, const KeyModifiers& mods)
{
    pks->SetKeyToggled(Key::NumLock, mods.IsNumToggled());
    pks->SetKeyToggled(Key::CapsLock, mods.IsCapsToggled());
    pks->SetKeyToggled(Key::ScrollLock, mods.IsScrollToggled());
}

// The modifier byte of an event as it came (no initialized bit added).
static inline KeyModifiers EventModifiers(const Event& event)
{
    KeyModifiers mods;
    mods.States = event.Modifiers.States;
    return mods;
}

// An input event from the application: mouse and key events are queued for the next Advance (mouse positions mapped
// from viewport pixels onto the stage), focus changes take effect at once and IME events go to the IME manager.
// An unfocused movie only takes the focus event.
// @0x142570280
unsigned MovieImpl::HandleEvent(const Event& event)
{
    if (!IsMovieFocused() && event.Type != Event::SetFocus)
        return HE_NotHandled;

    if (event.Type == Event::SetFocus)
    {
        const SetFocusEvent& fevent = static_cast<const SetFocusEvent&>(event);
        for (unsigned i = 0; i < 4; ++i)
        {
            if (fevent.KeysStates[i].States != 0)
                SetToggleKeys(GetKeyboardState(i), fevent.KeysStates[i]);
        }
        OnMovieFocus(true);
        return HE_Handled;
    }
    if (event.Type == Event::KeyDown || event.Type == Event::KeyUp)
    {
        const KeyEvent& kevent = static_cast<const KeyEvent&>(event);
        KeyboardState* pks = GetKeyboardState(kevent.KeyboardIndex);
        if (pks && event.Modifiers.States != 0)
            SetToggleKeys(pks, event.Modifiers);
    }

    switch (event.Type)
    {
    case Event::MouseMove:
    {
        const MouseEvent& mevent = static_cast<const MouseEvent&>(event);
        unsigned mouseIndex = mevent.MouseIndex;
        if (mouseIndex < MouseCursorCount)
        {
            Render::PointF pt(Render::PointF::NoInit);
            ViewportMatrix.TransformByInverse(&pt, Render::PointF(mevent.x, mevent.y));
            InputEventsQueue.AddMouseMove(mouseIndex, pt);
            return HE_Completed;
        }
        break;
    }
    case Event::MouseUp:
    {
        const MouseEvent& mevent = static_cast<const MouseEvent&>(event);
        unsigned mouseIndex = mevent.MouseIndex;
        if (mouseIndex < MouseCursorCount)
        {
            Render::PointF pt(Render::PointF::NoInit);
            ViewportMatrix.TransformByInverse(&pt, Render::PointF(mevent.x, mevent.y));
            InputEventsQueue.AddMouseButtonEvent(mouseIndex, pt, 1u << mevent.Button,
                                                 InputEventsQueueEntry::MouseButton_Released);
            return HE_Completed;
        }
        break;
    }
    case Event::MouseDown:
    {
        const MouseEvent& mevent = static_cast<const MouseEvent&>(event);
        unsigned mouseIndex = mevent.MouseIndex;
        if (mouseIndex < MouseCursorCount)
        {
            Render::PointF pt(Render::PointF::NoInit);
            ViewportMatrix.TransformByInverse(&pt, Render::PointF(mevent.x, mevent.y));
            InputEventsQueue.AddMouseButtonEvent(mouseIndex, pt, 1u << mevent.Button, 0);
            return HE_Completed;
        }
        break;
    }
    case Event::MouseWheel:
    {
        const MouseEvent& mevent = static_cast<const MouseEvent&>(event);
        unsigned mouseIndex = mevent.MouseIndex;
        if (mouseIndex < MouseCursorCount)
        {
            Render::PointF pt(Render::PointF::NoInit);
            ViewportMatrix.TransformByInverse(&pt, Render::PointF(mevent.x, mevent.y));
            InputEventsQueue.AddMouseWheel(mouseIndex, pt, (int)mevent.ScrollDelta);
            return HE_Completed;
        }
        break;
    }
    case Event::KeyDown:
    {
        const KeyEvent& kevent = static_cast<const KeyEvent&>(event);
        KeyboardState* pks = GetKeyboardState(kevent.KeyboardIndex);
        if (pks)
        {
            pks->SetKeyDown(kevent.KeyCode, kevent.AsciiCode, EventModifiers(event));
            // the left / right variant of a shift, control or alt key (the extended one is the right key)
            switch (kevent.KeyCode)
            {
            case Key::Shift:
                if (!EventModifiers(event).IsExtendedKey())
                    pks->SetKeyDown(0xa0, 0, KeyModifiers(0), false);
                else
                    pks->SetKeyDown(0xa1, 0, KeyModifiers(0), false);
                break;
            case Key::Control:
                if (!EventModifiers(event).IsExtendedKey())
                    pks->SetKeyDown(0xa2, 0, KeyModifiers(0), false);
                else
                    pks->SetKeyDown(0xa3, 0, KeyModifiers(0), false);
                break;
            case Key::Alt:
                if (!EventModifiers(event).IsExtendedKey())
                    pks->SetKeyDown(0xa4, 0, KeyModifiers(0), false);
                else
                    pks->SetKeyDown(0xa5, 0, KeyModifiers(0), false);
                break;
            default:
                break;
            }
        }
        InputEventsQueue.AddKeyEvent((short)kevent.KeyCode, kevent.AsciiCode, 0, true, EventModifiers(event),
                                     kevent.KeyboardIndex);
        if (kevent.WcharCode == 13 || (kevent.WcharCode >= 32 && kevent.WcharCode != 127))
            InputEventsQueue.AddKeyEvent(0, 0, kevent.WcharCode, true, KeyModifiers(0), kevent.KeyboardIndex);
        return HE_Completed;
    }
    case Event::KeyUp:
    {
        const KeyEvent& kevent = static_cast<const KeyEvent&>(event);
        KeyboardState* pks = GetKeyboardState(kevent.KeyboardIndex);
        if (pks)
        {
            pks->SetKeyUp(kevent.KeyCode, kevent.AsciiCode, EventModifiers(event));
            switch (kevent.KeyCode)
            {
            case Key::Shift:
                if (!EventModifiers(event).IsExtendedKey())
                    pks->SetKeyUp(0xa0, 0, KeyModifiers(0), false);
                else
                    pks->SetKeyUp(0xa1, 0, KeyModifiers(0), false);
                break;
            case Key::Control:
                if (!EventModifiers(event).IsExtendedKey())
                    pks->SetKeyUp(0xa2, 0, KeyModifiers(0), false);
                else
                    pks->SetKeyUp(0xa3, 0, KeyModifiers(0), false);
                break;
            case Key::Alt:
                if (!EventModifiers(event).IsExtendedKey())
                    pks->SetKeyUp(0xa4, 0, KeyModifiers(0), false);
                else
                    pks->SetKeyUp(0xa5, 0, KeyModifiers(0), false);
                break;
            default:
                break;
            }
        }
        InputEventsQueue.AddKeyEvent((short)kevent.KeyCode, kevent.AsciiCode, 0, false, EventModifiers(event),
                                     kevent.KeyboardIndex);
        return HE_Completed;
    }
    case Event::Char:
    {
        const CharEvent& cevent = static_cast<const CharEvent&>(event);
        InputEventsQueue.AddKeyEvent(0, 0, cevent.WcharCode, true, KeyModifiers(0), cevent.KeyboardIndex);
        return HE_Completed;
    }
    case Event::IME:
    {
        Ptr<IMEManagerBase> pimeManager = GetIMEManager();
        if (pimeManager)
            return pimeManager->HandleIMEEvent(this, static_cast<const IMEEvent&>(event));
        break;
    }
    case Event::KillFocus:
        OnMovieFocus(false);
        break;
    default:
        break;
    }
    return HE_NotHandled;
}

// Whether the screen point hits one of the levels; HitTest_ButtonEvents asks for something that takes button events.
// @0x142570a00
bool MovieImpl::HitTest(float x, float y, HitTestType testCond, unsigned controllerIdx)
{
    Render::PointF pt(Render::PointF::NoInit);
    ViewportMatrix.TransformByInverse(&pt, Render::PointF(x, y));

    SetNormalizedScreenCoords(pt);

    for (unsigned movieIndex = (unsigned)MovieLevels.GetSize(); movieIndex > 0; movieIndex--)
    {
        InteractiveObject* pmovie = MovieLevels[movieIndex - 1].pSprite;

        Render::RectF movieLocalBounds = pmovie->GetBounds(Render::Matrix2F());

        Render::PointF ptMv(Render::PointF::NoInit);
        pmovie->TransformPointToLocal(&ptMv, pt, false);

        if (movieLocalBounds.Contains(ptMv) || pmovie->Has3D())
        {
            switch (testCond)
            {
            case HitTest_Bounds:
                if (pmovie->PointTestLocal(ptMv, 0))
                    return true;
                break;
            case HitTest_Shapes:
                if (pmovie->PointTestLocal(ptMv, DisplayObjectBase::HitTest_TestShape))
                    return true;
                break;
            case HitTest_ButtonEvents:
                {
                    DisplayObjectBase::TopMostDescr descr;
                    descr.ControllerIdx = controllerIdx;
                    if (GetAVMVersion() == 1)
                    {
                        // AS1/AS2: only clips with button handlers are hit
                        if (pmovie->GetTopMostMouseEntity(ptMv, &descr) == DisplayObjectBase::TopMost_Found)
                            return true;
                    }
                    else
                    {
                        // AS3: anything is hit; one of its parents must act as a button
                        descr.TestAll = true;
                        if (pmovie->GetTopMostMouseEntity(ptMv, &descr) == DisplayObjectBase::TopMost_Found)
                        {
                            for (InteractiveObject* p = descr.pResult; p; p = p->GetParent())
                            {
                                if (p->HasAvmObject() && p->GetAvmIntObj()->ActsAsButton())
                                    return true;
                            }
                        }
                    }
                    break;
                }
            case HitTest_ShapesNoInvisible:
                if (pmovie->PointTestLocal(ptMv,
                        DisplayObjectBase::HitTest_TestShape | DisplayObjectBase::HitTest_IgnoreInvisible))
                    return true;
                break;
            }
        }
    }
    return false;
}

// @0x1425775c0
Render::PointF MovieImpl::TranslateToScreen(const Render::PointF& p, Render::Matrix2F* puserMatrix)
{
    Render::Matrix2F worldMatrix;
    pMainMovie->GetWorldMatrix(&worldMatrix);
    Render::Matrix2F mat = ViewportMatrix;

    if (puserMatrix)
        mat.Prepend(*puserMatrix);
    mat.Prepend(worldMatrix);
    return mat.Transform(Render::PixelsToTwips(p));
}

// @0x142577860
Render::RectF MovieImpl::TranslateToScreen(const Render::RectF& r, Render::Matrix2F* puserMatrix)
{
    Render::Matrix2F worldMatrix;
    pMainMovie->GetWorldMatrix(&worldMatrix);
    Render::Matrix2F mat = ViewportMatrix;

    if (puserMatrix)
        mat.Prepend(*puserMatrix);
    mat.Prepend(worldMatrix);
    return mat.EncloseTransform(Render::PixelsToTwips(r));
}

// pathToCharacter: a path such as "_root.hud.mc"; pt is in pixels in that character's space, *presPt in screen
// pixels.
bool MovieImpl::TranslateLocalToScreen(const char* pathToCharacter, const Render::PointF& pt, Render::PointF* presPt,
                                       Render::Matrix2F* userMatrix)
{
    Value res;
    if (!GetVariable(&res, pathToCharacter))
        return false;
    Render::Matrix2F worldMatrix;
    if (!res.GetWorldMatrix(&worldMatrix))
        return false;

    Render::Matrix2F mat = ViewportMatrix;
    // the world matrix translates in pixels: undo the viewport matrix's 1/20
    mat.AppendScaling(20.f, 20.f);

    if (userMatrix)
        mat.Prepend(*userMatrix);
    mat.Prepend(worldMatrix);
    *presPt = mat.Transform(pt);
    return true;
}

void MovieImpl::AddVideoProvider(Video::VideoProvider* pvideo)
{
    if (pvideo)
        VideoProviders.Add(pvideo);
}

void MovieImpl::RemoveVideoProvider(Video::VideoProvider* pvideo)
{
    VideoProviders.RemoveAlt(pvideo);
}

Movie::~Movie()
{
}

}} // namespace Scaleform::GFx

namespace Scaleform { namespace Render {

// The root's node data: a container's, plus the viewport it is drawn into and the color the frame is cleared to.
class TreeRoot::NodeData : public TreeContainer::NodeData
{
public:
    NodeData();
    NodeData(const NodeData& src);

    Viewport VP;        // +0xa0
    Color    BGColor;   // +0xcc
};

// @0x14256a710
// MS2-FUNCTIONAL: the node-data vtable store is scheduled after the viewport stores (the exe stores it first)
SF_NOINLINE TreeRoot::NodeData::NodeData() : TreeContainer::NodeData(ET_Root), BGColor(0)
{
    pVTable = TreeRootNodeDataVTable;
}

// The copy a snapshot clones: the root's vftable goes in before the viewport is copied.
// @0x14256a630
SF_NOINLINE TreeRoot::NodeData::NodeData(const NodeData& src)
    : TreeContainer::NodeData(src), VP((pVTable = TreeRootNodeDataVTable, src.VP)), BGColor(src.BGColor)
{
}

// The deleting destructors in slot 0 of the node data vftables. The node data carries its vftable as a plain pointer
// here (gfx_rendertree.h), so they are written out: the children's shared array, the states, then the entry data
// (0x14257eb30), in reverse member order.
}} // namespace Scaleform::Render
void FUN_14257eb30(void* entryData);   // ContextImpl::EntryData::~EntryData
namespace Scaleform { namespace Render {

static SF_INLINE void destroyChildren(TreeNodeArray& children)
{
    if (children.hasArrayData())
    {
        TreeNodeArray::ArrayData* array = children.getArrayData();
        if (AtomicOps<int>::ExchangeAdd_NoSync(&array->RefCount, -1) == 1)
            SF_FREE(array);
    }
}

// ContextData_ImplMixin<TreeContainer::NodeData, TreeNode::NodeData> (vftable 0x143183230)
// @0x14256b5e0
void* FUN_14256b5e0(TreeNode::NodeData* data, unsigned flags)
{
    data->States.~StateBag();
    FUN_14257eb30(data);
    if (flags & 1)
        ::operator delete(data, 0x90);
    return data;
}

// ContextData_ImplMixin<TreeRoot::NodeData, TreeContainer::NodeData> (vftable 0x1431832d0)
// @0x14256b630
void* FUN_14256b630(TreeContainer::NodeData* data, unsigned flags)
{
    destroyChildren(data->Children);
    data->States.~StateBag();
    FUN_14257eb30(data);
    if (flags & 1)
        ::operator delete(data, 0xa0);
    return data;
}

// TreeContainer::NodeData (vftable 0x143183280)
// @0x14256b9f0
void* FUN_14256b9f0(TreeContainer::NodeData* data, unsigned flags)
{
    destroyChildren(data->Children);
    data->States.~StateBag();
    FUN_14257eb30(data);
    if (flags & 1)
        ::operator delete(data, 0xa0);
    return data;
}

// TreeRoot::NodeData (vftable 0x143183320)
// @0x14256ba70
void* FUN_14256ba70(TreeRoot::NodeData* data, unsigned flags)
{
    destroyChildren(data->Children);
    data->States.~StateBag();
    FUN_14257eb30(data);
    if (flags & 1)
        ::operator delete(data, 0xd0);
    return data;
}

class LinearHeap
{
public:
    void* Alloc(UPInt size);   // 0x1424eb4d0
};

namespace ContextImpl {

// The snapshot statistics (Render_Context data).
extern unsigned ConstructCopyCalls, CopyCalls;

// The member-wise copies the copy slots inline (TreeContainer::NodeData::operator= itself is out of line in
// sfr_render_03c; the exe has no copy of it).
inline void copyNodeData(TreeContainer::NodeData& dest, const TreeContainer::NodeData& src)
{
    dest.TreeNode::NodeData::operator=(src);
    dest.Children = src.Children;
}
inline void copyNodeData(TreeRoot::NodeData& dest, const TreeRoot::NodeData& src)
{
    copyNodeData((TreeContainer::NodeData&)dest, src);
    dest.VP      = src.VP;
    dest.BGColor = src.BGColor;
}

// The copy slots of the container and root node data vftables. The node data carries its vftable as a plain pointer
// here (gfx_rendertree.h), so the mixin only holds the slots: `this` is the C node data.
template<class C, class B>
class ContextData_ImplMixin
{
public:
    virtual EntryData* ConstructCopy(LinearHeap& heap) const
    {
        ConstructCopyCalls++;
        return new (heap.Alloc(sizeof(C))) C(*(const C*)this);
    }
    virtual void CopyTo(void* dest) const
    {
        copyNodeData(*(C*)dest, *(const C*)this);
        CopyCalls++;
    }
};

// @0x14256e280
template EntryData* ContextData_ImplMixin<TreeContainer::NodeData, TreeNode::NodeData>::ConstructCopy(LinearHeap&) const;
// @0x14256e310
template void ContextData_ImplMixin<TreeContainer::NodeData, TreeNode::NodeData>::CopyTo(void*) const;
// @0x14256e2e0
template EntryData* ContextData_ImplMixin<TreeRoot::NodeData, TreeContainer::NodeData>::ConstructCopy(LinearHeap&) const;
// @0x14256e350
template void ContextData_ImplMixin<TreeRoot::NodeData, TreeContainer::NodeData>::CopyTo(void*) const;

extern unsigned DestroyCalls;

// TreeRoot::NodeData's Destroy slot (no .pdata): counts, then destroys in place through the virtual destructor.
// MS2-FUNCTIONAL: free-function form of the mixin's Destroy (the mixin here carries only the copy slots); calls the
// deleting destructor directly instead of through the vftable.
// @0x14256e920
void FUN_14256e920(TreeRoot::NodeData* data)
{
    DestroyCalls++;
    FUN_14256ba70(data, 0);
}

} // namespace ContextImpl

// The background color travels with the viewport change bit.
// @0x142575a20
void TreeRoot::SetBackgroundColor(const Color& color)
{
    if (((const NodeData*)GetReadOnlyDataBase())->BGColor != color)
        ((NodeData*)getWritableData(Change_Viewport))->BGColor = color;
}

}} // namespace Scaleform::Render

namespace Scaleform { namespace GFx {

inline Movie::Movie()
{
}

// The render tree (root plus the topmost container) is created and captured once, so the render thread has a
// display handle before the first advance.
// @0x142569e20
// MS2-FUNCTIONAL: instruction scheduling (a few store pairs swapped) differs; every store and call matches
MovieImpl::MovieImpl(MemoryHeap* pheap)
    : pAdvanceStats(0), pHeap(pheap), pMainMovieDef(0), MovieLevels(),
      pStateBag(0), pRenderRoot(0), pTopMostRoot(0), PixelScale(1.f), pUserEventHandler(0), pFSCommandHandler(0),
      pExtIntfHandler(0), pFontManagerStates(0), pXMLObjectManager(0), BackgroundColor(0, 0, 0, 0xff),
      MouseCursorCount(1), ControllerCount(1), UserData(0), StickyVariables(), TopmostLevelCharacters(),
      FocusRectContainerNode(), Flags(0), Flags2(0), RegisteredFonts(), pSavedASMovieRoot(0),
      RenderContext(Memory::pGlobalHeap), DIContext(0), pRTCommandQueue(0), MultitouchHAL(0), GestureTopMostChar(0),
      IndirectTransformPairs()
{
    Render::TreeRoot* proot = RenderContext.CreateEntry<Render::TreeRoot>();
    pRenderRoot = *proot;
    hDisplayRoot = Render::ContextImpl::DisplayHandle<Render::TreeRoot>(proot);

    Render::TreeContainer* ptopmost = RenderContext.CreateEntry<Render::TreeContainer>();
    pTopMostRoot = *ptopmost;
    static_cast<Render::TreeContainer*>(pRenderRoot)->Add(ptopmost);
    RenderContext.Capture();

    pMainMovie        = 0;
    Flags            |= 0x40180;
    pPlayListOptHead  = 0;
    pPlayList         = 0;
    TimeElapsed       = 0;
    TimeRemainder     = 0.f;
    FrameTime         = 1.f / 12.f;
    ForceFrameCatchUp = 0;
    pLoadQueueHead    = 0;
    pLoadQueueMTHead  = 0;

    StateBagImpl* pstates = new (pHeap) StateBagImpl(0);
    pStateBag = *pstates;

    for (UByte i = 0; i < 4; i++)
        KeyboardStates[i].SetKeyboardIndex(i);
    pRetValHolder = 0;

    FontManagerStates* pfontStates = new (pHeap) FontManagerStates(pStateBag);
    pFontManagerStates = *pfontStates;

    InstanceNameCount = 0;
    ViewScaleX  = 1.f;
    ViewScaleY  = 1.f;
    ViewOffsetX = 0.f;
    ViewOffsetY = 0.f;
    ViewScaleMode = SM_ShowAll;
    ViewAlignment = Align_Center;
    FocusGroupsCnt = 1;
    memset(FocusGroupIndexes, 0, sizeof(FocusGroupIndexes));
    LastIntervalTimerId    = 0;
    pIMECandidateListStyle = 0;
    StartTickMs = Timer::GetTicks() / 1000;
    PauseTickMs = 0;
    SafeRect.Clear();
    pAudio                = 0;
    pSoundRenderer        = 0;
    pObjectInterface      = 0;
    LastLoadQueueEntryCnt = 0;
    pUnloadListHead       = 0;
    MultitouchMode        = 0;
    FocusRectChanged      = true;
    PreviouslyCaptured    = 0;
}

// The text and strings an ExternalInterface.call return value was converted into.
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
static_assert(sizeof(MovieImpl::ReturnValueHolder) == 0x38, "ReturnValueHolder (GetRetValHolder allocates 0x38)");

// @0x14256bc90
void MovieImpl::AddIndirectTransformPair(DisplayObjContainer* origParent, Render::TreeNode* origParentNode,
                                         DisplayObjectBase* obj)
{
    IndirectTransPair p = { origParentNode, obj, origParent, -1 };
    IndirectTransformPairs.PushBack(p);
}

// @0x14256e010
void MovieImpl::ClearIndirectTransformPairs()
{
    for (UPInt i = 0, n = IndirectTransformPairs.GetSize(); i < n; ++i)
    {
        IndirectTransPair& p = IndirectTransformPairs[i];
        p.TransformParent = NULL;
        p.Obj             = NULL;
        p.OriginalParent  = NULL;
        p.OrigParentDepth = 0;
    }
    IndirectTransformPairs.Clear();
}

// Drops the SetVariable values still waiting for their targets.
// @0x14256e1a0
void MovieImpl::ClearStickyVariables()
{
    for (ASStringHash<StickyVarNode*>::Iterator it = StickyVariables.Begin(); it != StickyVariables.End(); ++it)
    {
        StickyVarNode* pnode = it->Second;
        while (pnode)
        {
            StickyVarNode* p = pnode;
            pnode = pnode->pNext;
            delete p;
        }
    }
    StickyVariables.Clear();
}

// @0x14256bbf0
void MovieImpl::ActivateFocusCapture(unsigned controllerIdx)
{
    // A Tab press with no modifiers, as if the controller had sent it.
    ProcessFocusKeyInfo focusKeyInfo;
    InputEventsQueueEntry::KeyEntry keyEntry;
    keyEntry.KeyboardIndex = (UInt8)controllerIdx;
    keyEntry.Code          = Key::Tab;
    keyEntry.KeysState     = 0;
    ProcessFocusKey(Event::KeyDown, keyEntry, &focusKeyInfo);
    FinalizeProcessFocusKey(&focusKeyInfo);
}

// @0x14256e9a0
// MS2-FUNCTIONAL: register allocation (the info pointer and the array swap r14/r15); same code otherwise
void MovieImpl::FillTabableArray(const ProcessFocusKeyInfo* pfocusInfo)
{
    FocusGroupDescr& focusGroup = *pfocusInfo->pFocusGroup;
    if (pfocusInfo->InclFocusEnabled && (focusGroup.TabableArrayStatus & 3) == 1)
        focusGroup.ResetTabableArray();   // collected without the focusEnabled characters: collect again
    if (!(focusGroup.TabableArrayStatus & 1))
    {
        InteractiveObject::FillTabableParams params;
        ArrayDH<Ptr<InteractiveObject>, 0x147>& tabableArray = focusGroup.TabableArray;
        params.Array = &tabableArray;
        params.InclFocusEnabled = pfocusInfo->InclFocusEnabled;

        DisplayObjContainer* pmodalClip = (DisplayObjContainer*)focusGroup.GetModalClip(this);
        if (pmodalClip)
            pmodalClip->FillTabableArray(&params);
        else
        {
            // Every level, the topmost first.
            for (int i = (int)MovieLevels.GetSize(); i > 0; --i)
            {
                InteractiveObject* plevel = MovieLevels[i - 1].pSprite;
                if (plevel->IsDisplayObjContainer())
                    ((DisplayObjContainer*)plevel)->FillTabableArray(&params);
            }
        }

        if (params.TabIndexed)
            Alg::QuickSortSliced(tabableArray, 0, tabableArray.GetSize(), TabIndexSort);
        else
            Alg::QuickSortSliced(tabableArray, 0, tabableArray.GetSize(), AutoTabSort);

        focusGroup.TabableArrayStatus = 1;
        if (pfocusInfo->InclFocusEnabled)
            focusGroup.TabableArrayStatus = 3;   // 2: with the focusEnabled characters
    }
}

// @0x14256eae0
SF_NOINLINE void MovieImpl::FinalizeProcessFocusKey(ProcessFocusKeyInfo* pfocusInfo)
{
    FocusGroupDescr& focusGroup = FocusGroups[FocusGroupIndexes[pfocusInfo->KeyboardIndex]];
    if (pfocusInfo->Initialized && (focusGroup.TabableArrayStatus & 1) && pfocusInfo->CurFocusIdx >= 0 &&
        pfocusInfo->CurFocusIdx < (int)focusGroup.TabableArray.GetSize())
    {
        InteractiveObject*     pnewFocus   = focusGroup.TabableArray[pfocusInfo->CurFocusIdx];
        Ptr<InteractiveObject> lastFocused = focusGroup.LastFocused;
        if (lastFocused != pnewFocus)
        {
            focusGroup.LastFocusKeyCode = pfocusInfo->PrevKeyCode;
            focusGroup.LastFocusedRect = pfocusInfo->PrevFocusRect;
            QueueSetFocusTo(pnewFocus, NULL, pfocusInfo->KeyboardIndex, GFx_FocusMovedByKeyboard, pfocusInfo);
        }
        // A text field shows its own cursor: no focus rect around it.
        if (pnewFocus && pnewFocus->GetType() == CharacterDef::TextField)
        {
            if (focusGroup.FocusRectShown)
                FocusRectChanged = true;
            focusGroup.FocusRectShown = false;
        }
        else
        {
            if (!focusGroup.FocusRectShown)
                FocusRectChanged = true;
            focusGroup.FocusRectShown = true;
        }
    }
}

// @0x142570d80
// MS2-FUNCTIONAL: register allocation of the inlined FillTabableArray and focus group lookup
void MovieImpl::InitFocusKeyInfo(ProcessFocusKeyInfo* pfocusInfo, const InputEventsQueueEntry::KeyEntry& keyEntry,
                                 bool inclFocusEnabled, FocusGroupDescr* pfocusGroup)
{
    if (pfocusInfo->Initialized)
        return;
    FocusGroupDescr& focusGroup = pfocusGroup ? *pfocusGroup : FocusGroups[FocusGroupIndexes[keyEntry.KeyboardIndex]];
    pfocusInfo->pFocusGroup      = &focusGroup;
    pfocusInfo->PrevKeyCode      = focusGroup.LastFocusKeyCode;
    pfocusInfo->PrevFocusRect    = focusGroup.LastFocusedRect;
    pfocusInfo->InclFocusEnabled = inclFocusEnabled;
    pfocusInfo->ManualFocus      = false;
    pfocusInfo->KeyboardIndex    = keyEntry.KeyboardIndex;
    pfocusInfo->KeyCode          = keyEntry.Code;
    pfocusInfo->KeysState        = keyEntry.KeysState;

    FillTabableArray(pfocusInfo);

    pfocusInfo->CurFocusIdx = -1;
    pfocusInfo->CurFocused  = focusGroup.LastFocused;
    if (pfocusInfo->CurFocused)
    {
        for (UPInt i = 0, n = focusGroup.TabableArray.GetSize(); i < n; ++i)
        {
            if (focusGroup.TabableArray[i] == pfocusInfo->CurFocused)
            {
                pfocusInfo->CurFocusIdx = (int)i;
                break;
            }
        }
    }
    pfocusInfo->Initialized = true;
}

// The focus search of the arrow keys measures in whole pixels.
static inline float FocusPixels(float twips)
{
    return floorf(Render::TwipsToPixels(twips));
}

// Moves the keyboard focus within the focus group of the key's controller: Tab steps through the tab order
// (backwards with Shift), the arrow keys, while the focus rectangle is up or the focus is moved by hand, pick the
// closest character on that side of the focused one. Only the candidate (CurFocusIdx, CurFocused) is chosen here;
// FinalizeProcessFocusKey moves the focus.
// @0x142572050
// MS2-FUNCTIONAL: scheduling (the -1 step of the search loops stays in a register, two rect loads swap)
void MovieImpl::ProcessFocusKey(Event::EventType event, const InputEventsQueueEntry::KeyEntry& keyEntry,
                                ProcessFocusKeyInfo* pfocusInfo)
{
    if (event != Event::KeyDown)
        return;
    if (keyEntry.Code != Key::Tab &&
        !((IsFocusRectShown(keyEntry.KeyboardIndex) || pfocusInfo->ManualFocus) &&
          (keyEntry.Code == Key::Left || keyEntry.Code == Key::Right || keyEntry.Code == Key::Up ||
           keyEntry.Code == Key::Down)))
        return;

    InitFocusKeyInfo(pfocusInfo, keyEntry, false, NULL);
    const FocusGroupDescr& focusGroup = *pfocusInfo->pFocusGroup;
    const int count = (int)focusGroup.TabableArray.GetSize();

    if (keyEntry.Code == Key::Tab)
    {
        // The next character of the tab order that takes the focus, wrapping around once.
        int idx = pfocusInfo->CurFocusIdx;
        pfocusInfo->CurFocusIdx = -1;
        for (int n = 0; n < count; ++n)
        {
            if (KeyModifiers(keyEntry.KeysState).IsShiftPressed())
            {
                if (--idx < 0)
                    idx = count - 1;
            }
            else
            {
                if (++idx >= count)
                    idx = 0;
            }
            if (focusGroup.TabableArray[idx] &&
                (pfocusInfo->InclFocusEnabled || focusGroup.TabableArray[idx]->IsTabable()) &&
                focusGroup.TabableArray[idx]->IsFocusAllowed(this, pfocusInfo->KeyboardIndex))
            {
                pfocusInfo->CurFocusIdx = idx;
                break;
            }
        }
    }
    else if (pfocusInfo->CurFocused)
    {
        if (pfocusInfo->CurFocused->IsFocusRectEnabled() || IsAlwaysEnableFocusArrowKeys() ||
            pfocusInfo->ManualFocus)
        {
            Render::Matrix2F fromMat;
            pfocusInfo->CurFocused->GetLevelMatrix(&fromMat);
            Render::RectF fromRect = fromMat.EncloseTransform(pfocusInfo->CurFocused->GetFocusRect());

            // Pressing the same arrow again keeps measuring from the rectangle the run of presses started at across
            // the direction, so the focus walks a straight line.
            if (pfocusInfo->PrevKeyCode == keyEntry.Code)
            {
                if (keyEntry.Code == Key::Up || keyEntry.Code == Key::Down)
                {
                    fromRect.x1 = pfocusInfo->PrevFocusRect.x1;
                    fromRect.x2 = pfocusInfo->PrevFocusRect.x2;
                }
                else if (keyEntry.Code == Key::Right || keyEntry.Code == Key::Left)
                {
                    fromRect.y1 = pfocusInfo->PrevFocusRect.y1;
                    fromRect.y2 = pfocusInfo->PrevFocusRect.y2;
                }
            }
            else
            {
                pfocusInfo->PrevFocusRect = fromRect;
                pfocusInfo->PrevKeyCode   = keyEntry.Code;
            }

            if (keyEntry.Code == Key::Right || keyEntry.Code == Key::Left)
            {
                // Characters overlapping the band beside the focused one (by at least two pixels of height) win
                // over all others and among themselves go by the horizontal distance; without any, the straight
                // distance between the facing edge midpoints decides.
                int idx = pfocusInfo->CurFocusIdx;
                Render::RectF bestRect;
                bestRect.x1 = bestRect.x2 = (keyEntry.Code == Key::Right) ? float(INT_MAX) : float(INT_MIN);
                bestRect.y1 = bestRect.y2 = float(INT_MAX);
                bool inBand = false;
                for (int n = 0; n < count - 1; ++n)
                {
                    idx = (keyEntry.Code == Key::Right) ? idx + 1 : idx - 1;
                    if (idx >= count)
                        idx = 0;
                    else if (idx < 0)
                        idx = count - 1;
                    Ptr<InteractiveObject> pcand = focusGroup.TabableArray[idx];
                    if ((!pfocusInfo->InclFocusEnabled && !pcand->IsTabable()) ||
                        !pcand->IsFocusAllowed(this, pfocusInfo->KeyboardIndex))
                        continue;
                    Render::Matrix2F candMat;
                    pcand->GetLevelMatrix(&candMat);
                    Render::RectF candRect = candMat.EncloseTransform(pcand->GetFocusRect());

                    bool candInBand = false;
                    Render::RectF band;
                    if (keyEntry.Code == Key::Right)
                        band = Render::RectF(fromRect.x2 + 1, fromRect.y1, FLT_MAX, fromRect.y2);
                    else
                        band = Render::RectF(FLT_MIN, fromRect.y1, fromRect.x1 - 1, fromRect.y2);
                    if (candRect.Intersects(band))
                    {
                        Render::RectF overlap = candRect;
                        overlap.Intersect(band);
                        if (overlap.Height() >= 40)
                            candInBand = true;
                    }
                    if (candInBand)
                    {
                        if (!inBand)
                        {
                            pfocusInfo->CurFocusIdx = idx;
                            bestRect = candRect;
                            inBand = true;
                            continue;
                        }
                    }
                    if (inBand && !candInBand)
                        continue;

                    // From the middle of the focused rectangle's facing edge to the middle of the near edges of
                    // the candidate and of the best one so far, both cut to the part on this side.
                    Render::PointF toCand, toBest;
                    if (keyEntry.Code == Key::Right)
                    {
                        Render::PointF from(fromRect.x2, fromRect.y1 + fromRect.Height() / 2);
                        Render::RectF cand(candRect), best(bestRect);
                        cand.x1 = Alg::Max(fromRect.x2, cand.x1);
                        cand.x2 = Alg::Min(candRect.x2, cand.x2);
                        best.x1 = Alg::Max(fromRect.x2, best.x1);
                        best.x2 = Alg::Min(bestRect.x2, best.x2);
                        if (!cand.IsNormal() || Alg::IRound(Render::TwipsToPixels(cand.Width())) <= 3)
                            continue;
                        toCand.x = FocusPixels(cand.x1 - from.x);
                        toCand.y = FocusPixels(candRect.y1 + candRect.Height() / 2 - from.y);
                        toBest.x = FocusPixels(best.x1 - from.x);
                        toBest.y = FocusPixels(bestRect.y1 + bestRect.Height() / 2 - from.y);
                        if (toCand.x < 0)
                            continue;
                    }
                    else
                    {
                        Render::PointF from(fromRect.x1, fromRect.y1 + fromRect.Height() / 2);
                        Render::RectF cand(candRect), best(bestRect);
                        cand.x1 = Alg::Max(candRect.x1, cand.x1);
                        cand.x2 = Alg::Min(fromRect.x1, cand.x2);
                        best.x1 = Alg::Max(bestRect.x1, best.x1);
                        best.x2 = Alg::Min(fromRect.x1, best.x2);
                        if (!cand.IsNormal() || Alg::IRound(Render::TwipsToPixels(cand.Width())) <= 3)
                            continue;
                        toCand.x = FocusPixels(cand.x2 - from.x);
                        toCand.y = FocusPixels(candRect.y1 + candRect.Height() / 2 - from.y);
                        toBest.x = FocusPixels(best.x2 - from.x);
                        toBest.y = FocusPixels(bestRect.y1 + bestRect.Height() / 2 - from.y);
                        if (toCand.x > 0)
                            continue;
                    }
                    if ((inBand && (Alg::Abs(toCand.x) < Alg::Abs(toBest.x) ||
                                    (toCand.x == toBest.x && Alg::Abs(toCand.y) < Alg::Abs(toBest.y)))) ||
                        (!inBand && toCand.x * toCand.x + toCand.y * toCand.y <
                                        toBest.x * toBest.x + toBest.y * toBest.y))
                    {
                        pfocusInfo->CurFocusIdx = idx;
                        bestRect = candRect;
                    }
                }
            }
            else if (keyEntry.Code == Key::Up || keyEntry.Code == Key::Down)
            {
                // The same search turned upright: the band runs above or below the focused character and ranks by
                // the vertical distance first.
                int idx = pfocusInfo->CurFocusIdx;
                Render::RectF bestRect(0, 0, 0, 0);
                bestRect.x1 = float(INT_MAX);
                bestRect.y1 = (keyEntry.Code == Key::Down) ? float(INT_MAX) : float(INT_MIN);
                bool inBand = false;
                for (int n = 0; n < count - 1; ++n)
                {
                    idx = (keyEntry.Code == Key::Down) ? idx + 1 : idx - 1;
                    if (idx >= count)
                        idx = 0;
                    else if (idx < 0)
                        idx = count - 1;
                    Ptr<InteractiveObject> pcand = focusGroup.TabableArray[idx];
                    if ((!pfocusInfo->InclFocusEnabled && !pcand->IsTabable()) ||
                        !pcand->IsFocusAllowed(this, pfocusInfo->KeyboardIndex))
                        continue;
                    Render::Matrix2F candMat;
                    pcand->GetLevelMatrix(&candMat);
                    Render::RectF candRect = candMat.EncloseTransform(pcand->GetFocusRect());

                    bool candInBand = false;
                    Render::RectF band;
                    if (keyEntry.Code == Key::Down)
                        band = Render::RectF(fromRect.x1, fromRect.y2 + 1, fromRect.x2, FLT_MAX);
                    else
                        band = Render::RectF(fromRect.x1, FLT_MIN, fromRect.x2, fromRect.y1 - 1);
                    if (candRect.Intersects(band))
                    {
                        Render::RectF overlap = candRect;
                        overlap.Intersect(band);
                        if (overlap.Width() >= 40)
                            candInBand = true;
                    }
                    if (candInBand)
                    {
                        if (!inBand)
                        {
                            pfocusInfo->CurFocusIdx = idx;
                            bestRect = candRect;
                            inBand = true;
                            continue;
                        }
                    }
                    if (inBand && !candInBand)
                        continue;

                    Render::PointF toCand, toBest;
                    if (keyEntry.Code == Key::Up)
                    {
                        Render::PointF from(fromRect.x1 + fromRect.Width() / 2, fromRect.y1);
                        Render::RectF cand(candRect), best(bestRect);
                        cand.y1 = Alg::Max(candRect.y1, cand.y1);
                        cand.y2 = Alg::Min(fromRect.y1, cand.y2);
                        best.y1 = Alg::Max(bestRect.y1, best.y1);
                        best.y2 = Alg::Min(fromRect.y1, best.y2);
                        if (!cand.IsNormal() || Alg::IRound(Render::TwipsToPixels(cand.Height())) <= 3)
                            continue;
                        toCand.x = FocusPixels(cand.x1 + cand.Width() / 2 - from.x);
                        toCand.y = FocusPixels(cand.y2 - from.y);
                        toBest.x = FocusPixels(best.x1 + best.Width() / 2 - from.x);
                        toBest.y = FocusPixels(best.y2 - from.y);
                        if (toCand.y > 0)
                            continue;
                    }
                    else
                    {
                        Render::PointF from(fromRect.x1 + fromRect.Width() / 2, fromRect.y2);
                        Render::RectF cand(candRect), best(bestRect);
                        cand.y1 = Alg::Max(fromRect.y2, cand.y1);
                        cand.y2 = Alg::Min(candRect.y2, cand.y2);
                        best.y1 = Alg::Max(fromRect.y2, best.y1);
                        best.y2 = Alg::Min(bestRect.y2, best.y2);
                        if (!cand.IsNormal() || Alg::IRound(Render::TwipsToPixels(cand.Height())) <= 3)
                            continue;
                        toCand.x = FocusPixels(cand.x1 + cand.Width() / 2 - from.x);
                        toCand.y = FocusPixels(cand.y1 - from.y);
                        toBest.x = FocusPixels(best.x1 + best.Width() / 2 - from.x);
                        toBest.y = FocusPixels(best.y1 - from.y);
                        if (toCand.y < 0)
                            continue;
                    }
                    if ((inBand && (Alg::Abs(toCand.y) < Alg::Abs(toBest.y) ||
                                    (toCand.y == toBest.y && Alg::Abs(toCand.x) < Alg::Abs(toBest.x)))) ||
                        (!inBand && toCand.x * toCand.x + toCand.y * toCand.y <
                                        toBest.x * toBest.x + toBest.y * toBest.y))
                    {
                        pfocusInfo->CurFocusIdx = idx;
                        bestRect = candRect;
                    }
                }
            }
        }
    }

    if (pfocusInfo->CurFocusIdx >= 0 && pfocusInfo->CurFocusIdx < count)
        pfocusInfo->CurFocused = focusGroup.TabableArray[pfocusInfo->CurFocusIdx];
    else
        pfocusInfo->CurFocused = NULL;
}

// @0x142570920
void MovieImpl::HideFocusRect(unsigned controllerIdx)
{
    FocusGroupDescr& focusGroup = FocusGroups[FocusGroupIndexes[controllerIdx]];
    if (focusGroup.FocusRectShown)
    {
        Ptr<InteractiveObject> curFocused = focusGroup.LastFocused;
        if (curFocused && curFocused->GetParent() &&
            !curFocused->OnLosingKeyboardFocus(NULL, controllerIdx, GFx_FocusMovedByKeyboard))
            return;
    }
    focusGroup.FocusRectShown = false;
    FocusRectChanged = true;
}

// @0x142571070
bool MovieImpl::IsFocused(const InteractiveObject* ch) const
{
    for (unsigned i = 0; i < FocusGroupsCnt; ++i)
    {
        if (Ptr<InteractiveObject>(FocusGroups[i].LastFocused).GetPtr() == ch)
            return true;
    }
    return false;
}

// MS2-FUNCTIONAL: the exe inlines the CharacterHandle release and GetCharacterHandle; called out of line here.
// @0x1425761a0
void MovieImpl::SetModalClip(Sprite* pmovie, unsigned controllerIdx)
{
    FocusGroupDescr& focusGroup = FocusGroups[FocusGroupIndexes[controllerIdx]];
    if (!pmovie)
        focusGroup.ModalClip.Clear();
    else
        focusGroup.ModalClip = ((DisplayObject*)pmovie)->GetCharacterHandle();   // Sprite is incomplete here (base at +0)
}

// @0x142576c60
SF_NOINLINE void MovieImpl::ShutdownTimers()
{
    UPInt n = IntervalTimers.GetSize();
    for (UPInt i = 0; i < n; ++i)
        IntervalTimers[i]->Clear();
    IntervalTimers.Clear();
}

// @0x142576cc0
void MovieImpl::ShutdownTimersForMovieDef(MovieDefImpl* pdefImpl)
{
    UPInt n = IntervalTimers.GetSize();
    for (UPInt i = 0; i < n; ++i)
    {
        if (IntervalTimers[i]->ClearFor(this, pdefImpl))
            IntervalTimers[i] = NULL;
    }
}

// @0x14256f990
MovieImpl::ReturnValueHolder* MovieImpl::GetRetValHolder()
{
    if (!pRetValHolder)
        pRetValHolder = new (pHeap) ReturnValueHolder(AsRootSlots(pASMovieRoot)->GetStringManager());
    return pRetValHolder;
}

// @0x1425742c0
void MovieImpl::RemoveTopmostLevelCharacter(DisplayObjectBase* pch)
{
    for (UPInt i = 0, n = TopmostLevelCharacters.GetSize(); i < n; ++i)
    {
        if (TopmostLevelCharacters[i] == pch)
        {
            static_cast<Render::TreeContainer*>(pTopMostRoot)->Remove(i, 1);
            pch->RemoveIndirectTransform();
            TopmostLevelCharacters.RemoveAt(i);
            return;
        }
    }
}

// @0x14256f220
Render::DrawableImageContext* MovieImpl::GetDrawableImageContext()
{
    if (!DIContext)
        DIContext = *new Render::DrawableImageContext(&RenderContext, (Render::ThreadCommandQueue*)pRTCommandQueue,
                                                      Render::Interfaces());
    return DIContext;
}

// @0x14256f310
void MovieImpl::GetIMECandidateListStyle(IMECandidateListStyle* pst) const
{
    if (!pIMECandidateListStyle)
        *pst = IMECandidateListStyle();
    else
        *pst = *pIMECandidateListStyle;
}

// @0x142575c30
void MovieImpl::SetIMECandidateListStyle(const IMECandidateListStyle& st)
{
    if (!pIMECandidateListStyle)
    {
        // A heap-new: the copy only goes in when the allocation succeeded.
        void* pmem = pHeap->Alloc(sizeof(IMECandidateListStyle));
        pIMECandidateListStyle = pmem ? new (pmem) IMECandidateListStyle(st) : NULL;
    }
    else
        *pIMECandidateListStyle = st;
}

// @0x142578760
void MovieImpl::UpdateViewAndPerspective()
{
    if (VisibleFrameRect.IsNull())
        return;
    for (unsigned i = 0; i < MovieLevels.GetSize(); i++)
    {
        if (MovieLevels[i].pSprite)
            MovieLevels[i].pSprite->UpdateViewAndPerspective();
    }
}

// @0x142577c60
void MovieImpl::UpdateAllRenderNodes()
{
    UpdateAllDrawingContexts();
    if (FocusRectChanged)
        UpdateFocusRectRenderNodes();
}

// @0x1425786d0
void MovieImpl::UpdateTransformParent(DisplayObjectBase* pch, DisplayObjectBase* pparent)
{
    for (UPInt i = 0, n = IndirectTransformPairs.GetSize(); i < n; ++i)
    {
        if (IndirectTransformPairs[i].Obj.GetPtr() == pch)
        {
            IndirectTransPair& p = IndirectTransformPairs[i];
            p.TransformParent = pparent ? pparent->GetRenderNode() : NULL;
            p.OrigParentDepth = -1;
            break;
        }
    }
}

// @0x1425738b0
void MovieImpl::ProcessUnloadQueue()
{
    if (pUnloadListHead)
    {
        InteractiveObject* pnextCh;
        for (InteractiveObject* pcurCh = pUnloadListHead; pcurCh; pcurCh = pnextCh)
        {
            pnextCh = pcurCh->pNextUnloaded;
            pcurCh->pNextUnloaded = NULL;
            pcurCh->OnEventUnload();
            if (pcurCh->GetParent())
                pcurCh->GetParent()->RemoveDisplayObject(pcurCh);
            pcurCh->Release();
        }
        pUnloadListHead = NULL;
    }
}

// @0x142573b10
bool SF_STDCALL MovieImpl::ReadBinaryData(ArrayPOD<UByte>* pdata, File* pfile, int* pfileLen)
{
    *pfileLen = pfile->GetLength();
    if (*pfileLen == 0)
        return false;
    pdata->Resize(*pfileLen);
    if (pfile->Read(pdata->GetDataPtr(), *pfileLen) != *pfileLen)
        return false;
    return true;
}

// @0x14256ec50
bool MovieImpl::FindExportedResource(MovieDefImpl* pdefImpl, ResourceBindData* pdata, const String& symbol)
{
    if (pdefImpl->GetExportedResource(pdata, symbol))
        return true;
    // Then the movies that import it, each one in turn being the importer the next must import.
    MovieDefImpl* pimported = pdefImpl;
    MovieDefRootNode* pnode = RootMovieDefNodes.pNext;
    MovieDefRootNodeLinks* proot = &RootMovieDefNodes;
    while (pnode != static_cast<MovieDefRootNode*>(proot))
    {
        if (pnode->pDefImpl != pdefImpl && pnode->pDefImpl->DoesDirectlyImport(pimported))
        {
            if (pnode->pDefImpl->GetExportedResource(pdata, symbol))
                return true;
            pimported = pnode->pDefImpl;
        }
        pnode = pnode->pNext;
    }
    return false;
}

// @0x1425737e0
void MovieImpl::ProcessMovieDefToKillList()
{
    if (MovieDefKillList.GetSize() > 0)
    {
        // Lets go of the first movie def whose frame the render thread has finished.
        UInt64 finalizedFrameId = RenderContext.GetFinalizedFrameId();
        for (UPInt i = 0; i < MovieDefKillList.GetSize(); ++i)
        {
            if (finalizedFrameId > MovieDefKillList[i].KillFrameId)
            {
                MovieDefKillList.RemoveAt(i);
                break;
            }
        }
    }
}

// @0x142570c80
void MovieImpl::DragState::InitCenterDelta(bool lockCenter)
{
    LockCenter = lockCenter;
    if (!LockCenter)
    {
        // Not centred on the mouse: keep the character's offset from it, in its parent's coordinates.
        Render::Matrix2F   parentWorldMat;
        Render::Matrix2F   worldMat;
        InteractiveObject* pchar = pCharacter;
        if (pchar->GetParent())
        {
            pchar->GetParent()->GetWorldMatrix(&worldMat);
            parentWorldMat = worldMat;
        }
        Render::PointF worldMouse(pchar->GetMovieImpl()->mMouseState[0].GetLastPosition());
        Render::PointF parentMouse(Render::PointF::NoInit);
        parentWorldMat.TransformByInverse(&parentMouse, worldMouse);

        const Render::Matrix2F& local = pchar->GetMatrix();
        float dy = local.Ty() - parentMouse.y;
        CenterDelta.x = local.Tx() - parentMouse.x;
        CenterDelta.y = dy;
    }
}

// @0x142573d60
bool MovieImpl::RegisterFont(MovieDef* md, FontResource* pfont)
{
    for (UPInt i = 0, n = RegisteredFonts.GetSize(); i < n; ++i)
    {
        if (RegisteredFonts[i].pFont == pfont && RegisteredFonts[i].pMovieDef == md)
            return false;
    }
    FontDesc desc;
    desc.pFont     = pfont;
    desc.pMovieDef = md;
    RegisteredFonts.PushBack(desc);
    Flags2 |= 0x2;   // the registered fonts changed
    return true;
}

// @0x142577b00
void MovieImpl::UnregisterFonts(MovieDefImpl* pdefImpl)
{
    for (UPInt i = 0; i < RegisteredFonts.GetSize(); )
    {
        if (RegisteredFonts[i].pMovieDef == pdefImpl)
            RegisteredFonts.RemoveAt(i);
        else
            ++i;
    }
    // The font managers may hold glyphs of its fonts too.
    MovieDefRootNode* pnode = RootMovieDefNodes.pNext;
    MovieDefRootNodeLinks* proot = &RootMovieDefNodes;
    while (pnode != static_cast<MovieDefRootNode*>(proot))
    {
        pnode->pFontManager->CleanCacheFor(pdefImpl);
        pnode = pnode->pNext;
    }
    Flags2 |= 0x2;
}

// @0x142574eb0
void MovieImpl::ResetViewportMatrix()
{
    ViewportMatrix = Render::Matrix2F::Translation(-VisibleFrameRect.x1, -VisibleFrameRect.y1);
    ViewportMatrix.AppendScaling(mViewport.Width / VisibleFrameRect.Width(),
                                 mViewport.Height / VisibleFrameRect.Height());
}

// @0x142575b10
bool MovieImpl::SetFocusTo(InteractiveObject* ch, unsigned controllerIdx, FocusMovedType fmt)
{
    FocusGroupDescr& focusGroup = FocusGroups[FocusGroupIndexes[controllerIdx]];
    Ptr<InteractiveObject> curFocused = focusGroup.LastFocused;
    if (curFocused == ch)
        return false;
    FocusRectChanged = true;
    // The focused character may refuse to let go.
    if (curFocused && curFocused->GetParent() && !curFocused->OnLosingKeyboardFocus(ch, controllerIdx, fmt))
        return false;
    TransferFocus(ch, controllerIdx, fmt);
    if (ch)
        ch->OnGettingKeyboardFocus(controllerIdx, fmt);
    return true;
}

// @0x14256f050
unsigned MovieImpl::GetControllerMaskByFocusGroup(unsigned focusGroupIdx)
{
    unsigned mask = 0;
    for (unsigned i = 0, bit = 1; i < 16; ++i, bit <<= 1)
        if (FocusGroupIndexes[i] == focusGroupIdx)
            mask |= bit;
    return mask;
}

// @0x142573940
bool MovieImpl::QueueSetFocusTo(InteractiveObject* ch, InteractiveObject* dontRemoveFromFocused, unsigned controllerIdx,
                                FocusMovedType fmt, ProcessFocusKeyInfo* pfocusKeyInfo)
{
    FocusGroupDescr& focusGroup = FocusGroups[FocusGroupIndexes[controllerIdx]];
    Ptr<InteractiveObject> curFocused = focusGroup.LastFocused;
    if (curFocused == ch)
        return false;
    FocusRectChanged = true;
    // The IME may move the focus somewhere else (its candidate list keeps it).
    Ptr<IMEManagerBase> pIMEManager = GetIMEManager();
    if (pIMEManager)
    {
        ch = pIMEManager->pASIMEManager->HandleFocus(this, curFocused, ch, dontRemoveFromFocused);
        if (curFocused == ch)
            return false;
    }
    if (!AsRootSlots(pASMovieRoot)->NotifyOnFocusChange(curFocused, ch, controllerIdx, fmt, pfocusKeyInfo))
        return false;
    if (ch && !ch->IsFocusEnabled(fmt))
        ch = NULL;
    // The focused character may refuse to let go.
    if (curFocused && curFocused->GetParent() && !curFocused->OnLosingKeyboardFocus(ch, controllerIdx, fmt))
        return false;
    if (ch)
        ch->OnGettingKeyboardFocus(controllerIdx, fmt);
    AsRootSlots(pASMovieRoot)->NotifyQueueSetFocus(ch, controllerIdx, fmt);
    return true;
}

// @0x142577060
void MovieImpl::TransferFocus(InteractiveObject* pNewFocus, unsigned controllerIdx, FocusMovedType fmt)
{
    FocusGroupDescr& focusGroup = FocusGroups[FocusGroupIndexes[controllerIdx]];
    Ptr<InteractiveObject> curFocused = focusGroup.LastFocused;
    if (curFocused == pNewFocus)
        return;
    FocusRectChanged = true;
    UByte avmVersion = pASMovieRoot->AVMVersion;
    // AS3 moves the focus before the kill focus event, AS2 after it.
    if (avmVersion == 2)
    {
        if (pNewFocus && !pNewFocus->IsFocusEnabled(fmt))
        {
            focusGroup.LastFocused = NULL;
            pNewFocus = NULL;
        }
        else
            focusGroup.LastFocused = pNewFocus;
    }
    if (curFocused && curFocused->GetParent())
        curFocused->OnFocus(InteractiveObject::KillFocus, pNewFocus, controllerIdx, fmt);
    if (avmVersion == 1)
        focusGroup.LastFocused = pNewFocus;
    if (pNewFocus)
        pNewFocus->OnFocus(InteractiveObject::SetFocus, curFocused, controllerIdx, fmt);
    AsRootSlots(pASMovieRoot)->NotifyTransferFocus(curFocused, pNewFocus, controllerIdx);
}

// @0x142575cd0
void MovieImpl::SetKeyboardFocusTo(InteractiveObject* ch, unsigned controllerIdx, FocusMovedType fmt)
{
    // The IME may move the focus somewhere else (the state straight off this movie's bag: no null check of this).
    Ptr<IMEManagerBase> pIMEManager = *(IMEManagerBase*)GetStateAddRef(State::State_IMEManager);
    if (pIMEManager && pIMEManager->pASIMEManager)
    {
        Ptr<InteractiveObject> curFocused = FocusGroups[FocusGroupIndexes[controllerIdx]].LastFocused;
        if (curFocused != ch)
            ch = pIMEManager->pASIMEManager->HandleFocus(this, curFocused, ch, NULL);
    }
    FocusGroupDescr& focusGroup = FocusGroups[FocusGroupIndexes[controllerIdx]];
    // A text field shows its own cursor: no focus rect around it.
    if (ch && ch->GetType() == CharacterDef::TextField)
    {
        if (focusGroup.FocusRectShown)
            FocusRectChanged = true;
        focusGroup.FocusRectShown = false;
    }
    else
    {
        if (!focusGroup.FocusRectShown)
            FocusRectChanged = true;
        focusGroup.FocusRectShown = true;
    }
    focusGroup.LastFocusKeyCode = 0;
    if (SetFocusTo(ch, controllerIdx, fmt) && focusGroup.FocusRectShown)
    {
        // The rect stays up only while the character and all its parents are visible.
        InteractiveObject* p = ch;
        while (p && p->GetVisible())
            p = p->GetParent();
        bool show = (p == NULL);
        if (focusGroup.FocusRectShown != show)
            FocusRectChanged = true;
        focusGroup.FocusRectShown = show;
    }
}

// @0x142574110
MovieImpl::IndirectTransPair MovieImpl::RemoveIndirectTransformPair(DisplayObjectBase* obj)
{
    for (UPInt i = 0, n = IndirectTransformPairs.GetSize(); i < n; ++i)
    {
        if (IndirectTransformPairs[i].Obj == obj)
        {
            IndirectTransPair p = IndirectTransformPairs[i];
            IndirectTransformPairs.RemoveAt(i);
            return IndirectTransPair(p);
        }
    }
    IndirectTransPair none = { NULL, NULL, NULL, -1 };
    return none;
}

// @0x142576d50
// The value as text: numbers formatted like the VMs do, objects asked through their ObjectInterface (slot 35).
String Value::ToString() const
{
    String retVal;
    switch (GetType())
    {
    case VT_Undefined:
        retVal = String("undefined");
        break;
    case VT_Null:
        retVal = String("null");
        break;
    case VT_Boolean:
        retVal = String(mValue.BValue ? "true" : "false");
        break;
    case VT_Number:
    {
        char buf[64];
        retVal = String(NumberUtil::ToString(mValue.NValue, buf, sizeof(buf), 10));
        break;
    }
    case VT_Int:
    {
        char buf[32];
        SFsprintf(buf, 32, "%d", mValue.IValue);
        retVal = String(buf);
        break;
    }
    case VT_UInt:
    {
        char buf[32];
        SFsprintf(buf, 32, "%u", mValue.UIValue);
        retVal = String(buf);
        break;
    }
    case VT_String:
        retVal = String(IsManagedValue() ? *mValue.pStringManaged : mValue.pString);
        break;
    case VT_StringW:
        retVal = String(mValue.pStringW);
        break;
    case VT_Object:
    case VT_Array:
    case VT_DisplayObject:
    {
        typedef void (*Fn)(ObjectInterface*, String*, const Value&);
        (*reinterpret_cast<Fn const* const*>(pObjectInterface))[35](pObjectInterface, &retVal, *this);
        break;
    }
    default:
        retVal = "<bad type>";
        break;
    }
    return retVal;
}

// @0x142576fd0
const wchar_t* Value::ToStringW(wchar_t* pdest, UPInt destSz) const
{
    if (GetType() != VT_StringW)
        UTF8Util::DecodeString(pdest, ToString().ToCStr(), -1);
    else
        SFwcscpy(pdest, destSz, mValue.pStringW);
    return pdest;
}

// @0x142576750
SF_NOINLINE void MouseState::SetTopmostEntity(InteractiveObject* pent)
{
    PrevTopmostEntity        = TopmostEntity;
    PrevTopmostEntityWasNull = TopmostEntityIsNull;
    TopmostEntity            = pent;
    TopmostEntityIsNull      = (pent == NULL);
}

// @0x14256ed40
FontResource* MovieImpl::FindRegisteredFont(const char* pfontName, unsigned fontFlags, MovieDef** ppsrcMovieDef) const
{
    for (UPInt i = 0, n = RegisteredFonts.GetSize(); i < n; ++i)
    {
        FontResource* pfont = static_cast<FontResource*>(RegisteredFonts[i].pFont.GetPtr());
        if (pfont->GetFont()->MatchFont(pfontName, fontFlags))
        {
            *ppsrcMovieDef = RegisteredFonts[i].pMovieDef;
            return static_cast<FontResource*>(RegisteredFonts[i].pFont.GetPtr());
        }
    }
    return NULL;
}

// @0x142573220
// Runs the queued load requests, then retires the loader-thread requests once every one of them has preloaded.
void MovieImpl::ProcessLoadQueue()
{
    while (pLoadQueueHead)
    {
        LoadQueueEntry* pentry = pLoadQueueHead;
        pLoadQueueHead = pentry->pNext;
        Ptr<LoadStates> pls = *new LoadStates(pMainMovieDef->pLoaderImpl, pStateBag);
        AsRootSlots(pASMovieRoot)->ProcessLoadQueueEntry(pentry, pls);
        delete pentry;
    }

    LoadQueueEntryMT* pentryMT = pLoadQueueMTHead;
    while (pentryMT)
    {
        if (!pentryMT->IsPreloadingFinished())
            return;
        pentryMT = pentryMT->pNext;
    }
    pentryMT = pLoadQueueMTHead;
    while (pentryMT)
    {
        bool              finished = pentryMT->LoadFinished();
        LoadQueueEntryMT* pnext    = pentryMT->pNext;
        if (finished)
        {
            if (pnext)
                pnext->pPrev = pentryMT->pPrev;
            if (pentryMT->pPrev)
                pentryMT->pPrev->pNext = pnext;
            if (pLoadQueueMTHead == pentryMT)
                pLoadQueueMTHead = pnext;
            delete pentryMT;
        }
        pentryMT = pnext;
    }
}

// Whether the mouse moved onto another entity (or onto / off nothing) since the last topmost entity update.
static SF_INLINE bool IsTopmostEntityChanged(const Ptr<InteractiveObject>& ptop, const Ptr<InteractiveObject>& pprev,
                                             bool topIsNull, bool prevWasNull)
{
    return ptop != pprev || (!ptop && !topIsNull) || (!pprev && !prevWasNull);
}

// @0x14256dca0
void MovieImpl::CheckMouseCursorType(unsigned mouseIdx, InteractiveObject* ptopMouseCharacter)
{
    MouseState& ms = mMouseState[mouseIdx];
    bool changed;
    {
        Ptr<InteractiveObject> ptop  = ms.TopmostEntity;
        Ptr<InteractiveObject> pprev = ms.PrevTopmostEntity;
        changed = IsTopmostEntityChanged(ptop, pprev, ms.TopmostEntityIsNull, ms.PrevTopmostEntityWasNull);
    }
    if (changed)
    {
        unsigned newCursorType = MouseState::Cursor_Arrow;
        if (ptopMouseCharacter)
            newCursorType = ptopMouseCharacter->GetCursorType();
        ChangeMouseCursorType(mouseIdx, newCursorType);
    }
}

// @0x142573bc0
// The whole of pfile as text: a UTF-16 file (either byte order) or a UTF-8 one (BOM dropped); loadVariables data is
// URL-decoded.
bool SF_STDCALL MovieImpl::ReadTextData(String* pdata, File* pfile, int* pfileLen, bool urlEncoded)
{
    *pfileLen = pfile->GetLength();
    if (*pfileLen == 0)
        return false;
    String str;
    UByte* ptextData = (UByte*)SF_ALLOC(*pfileLen, Stat_Default_Mem);
    pfile->Read(ptextData, *pfileLen);

    UInt16 bom = *(UInt16*)ptextData;
    UByte  bomHi = UByte(bom >> 8);
    if (bom == 0xFEFF)
    {
        // little endian UTF-16
        str.AppendString((const wchar_t*)(ptextData + 2), *pfileLen / 2 - 1);
    }
    else if (bom == 0xFFFE)
    {
        // big endian UTF-16: swap the bytes first
        wchar_t* pchars = (wchar_t*)(ptextData + 2);
        int      len    = *pfileLen / 2 - 1;
        for (int i = 0; i < len; ++i)
            pchars[i] = (wchar_t)((pchars[i] << 8) | (pchars[i] >> 8));
        str.AppendString(pchars, len);
    }
    else if (*pfileLen > 2 && UByte(bom) == 0xEF && bomHi == 0xBB && ptextData[2] == 0xBF)
    {
        str.AppendString((const char*)(ptextData + 3), *pfileLen - 3);
    }
    else
    {
        str.AppendString((const char*)ptextData, *pfileLen);
    }

    if (urlEncoded)
        ASUtils::Unescape(str.ToCStr(), str.GetSize(), pdata);
    else
        *pdata = str;
    SF_FREE(ptextData);
    return true;
}

// @0x14256e710
// The next "instanceN" name for an unnamed display object.
ASString MovieImpl::CreateNewInstanceName()
{
    char pbuffer[48] = { 0 };
    ++InstanceNameCount;
    Format(StringDataPtr(pbuffer, sizeof(pbuffer)), "instance{0}", InstanceNameCount);
    return ASString(AsRootSlots(pASMovieRoot)->GetStringManager()->CreateStringNode(pbuffer));
}

// @0x1425711a0
void MovieImpl::LoadRegisteredFonts(HashSet<Ptr<Render::Font> >& fonts)
{
    for (UPInt i = 0, n = RegisteredFonts.GetSize(); i < n; ++i)
    {
        Render::Font* pfont = static_cast<FontResource*>(RegisteredFonts[i].pFont.GetPtr())->GetFont();
        fonts.Set(pfont);
    }
}

// @0x14256bf50
// Keeps pnode under path: a node of the same name in the chain takes over its value, otherwise it joins the chain.
void MovieImpl::AddStickyVariableNode(const ASString& path, StickyVarNode* pnode)
{
    StickyVarNode* phead = 0;
    if (StickyVariables.Get(path, &phead) && phead)
    {
        StickyVarNode* p = phead;
        while (p && !(p->Name == pnode->Name))
            p = p->pNext;
        if (p)
        {
            p->Assign(*pnode);
            delete pnode;
        }
        else
        {
            pnode->pNext = phead->pNext;
            phead->pNext = pnode;
        }
    }
    else
        StickyVariables.Set(path, pnode);
}

// @0x14256e4d0
MovieDefImpl* MovieImpl::CreateImageMovieDef(ImageResource* pimageRes, bool bilinear, const char* purl,
                                             LoadStates* pls)
{
    MovieDefImpl*   pdefImpl = 0;
    Ptr<LoadStates> plsHolder;
    if (!pls)
    {
        plsHolder = *new LoadStates(pMainMovieDef->pLoaderImpl, pStateBag);
        pls = plsHolder.GetPtr();
    }
    if (pimageRes)
    {
        ResourceKey  fileKey = MovieDataDef::CreateMovieFileKey(purl, 0, 0, 0, 0);
        MemoryHeap*  pheap   = pHeap;
        Ptr<MovieDataDef> pdataDef =
            *new (pheap ? pheap : Memory::GetGlobalHeap()) MovieDataDef(fileKey, MovieDataDef::MT_Image, purl, pheap);
        if (pdataDef)
        {
            Log* plog = pls->GetLog();
            bool ok;
            {
                // ImageCreator is a State at offset 0 (incomplete here).
                Ptr<State> pimageCreator = *GetStateAddRef(State::State_ImageCreator);
                ok = pdataDef->InitImageFileMovieDef(0, pimageRes, reinterpret_cast<ImageCreator*>(pimageCreator.GetPtr()),
                                                     plog, bilinear);
            }
            if (ok)
            {
                pls->SetRelativePathForDataDef(pdataDef);
                pdefImpl = new (pheap) MovieDefImpl(pdataDef, pls->pBindStates, pls->pLoaderImpl, 0,
                                                    pStateBag->GetDelegate(), pheap, true);
            }
        }
    }
    return pdefImpl;
}

// @0x142573070
void MovieImpl::ProcessKeyboard(const InputEventsQueueEntry* qe, ProcessFocusKeyInfo* focusKeyInfo)
{
    int keyMask = 0;
    const InputEventsQueueEntry::KeyEntry& keyEntry = qe->GetKeyEntry();
    if (keyEntry.Code != 0)
    {
        UInt32           eventIdCode = !keyEntry.KeyIsDown ? EventId::Event_KeyUp : EventId::Event_KeyDown;
        Event::EventType eventType   = keyEntry.KeyIsDown ? Event::KeyDown : Event::KeyUp;
        EventId evt(eventIdCode);
        evt.WcharCode     = keyEntry.WcharCode;
        evt.KeyCode       = keyEntry.Code;
        evt.AsciiCode     = keyEntry.AsciiCode;
        evt.KeyboardIndex = keyEntry.KeyboardIndex;
        evt.KeysState     = keyEntry.KeysState | 0x80;   // KeyModifiers::Initialized_Mask
        // The levels hear the key from the top down.
        for (unsigned movieIndex = (unsigned)MovieLevels.GetSize(); movieIndex > 0; movieIndex--)
            MovieLevels[movieIndex - 1].pSprite->PropagateKeyEvent(evt, &keyMask);
        GetKeyboardState(keyEntry.KeyboardIndex)->NotifyListeners(pMainMovie, evt, keyMask);
        if (!IsDisableFocusKeys())
            ProcessFocusKey(eventType, keyEntry, focusKeyInfo);
    }
    else if (keyEntry.WcharCode != 0)
    {
        // A typed character goes to the focused character of the keyboard.
        Ptr<InteractiveObject> curFocused = FocusGroups[FocusGroupIndexes[keyEntry.KeyboardIndex]].LastFocused;
        if (curFocused)
            curFocused->OnCharEvent(keyEntry.WcharCode, keyEntry.KeyboardIndex);
    }
}

// @0x142572e10
void MovieImpl::ProcessInput()
{
    if (!pMainMovie)
        return;
    bool     avm2 = pASMovieRoot->AVMVersion == 2;
    ProcessFocusKeyInfo focusKeyInfo;
    unsigned miceSupportedMask = (1u << MouseCursorCount) - 1;
    UInt32   miceProceededMask = 0;
    while (!InputEventsQueue.IsQueueEmpty())
    {
        const InputEventsQueueEntry* qe = InputEventsQueue.GetEntry();
        if (qe->IsKeyEntry())
            ProcessKeyboard(qe, &focusKeyInfo);
        else if (qe->IsMouseEntry())
            ProcessMouse(qe, &miceProceededMask, avm2);
    }
    // The mice without an event still see what moved under them.
    if (IsFlagSet<Flag_NeedMouseUpdate>(Flags))
    {
        UInt32 proceeded = miceProceededMask;
        if ((proceeded & miceSupportedMask) != miceSupportedMask)
        {
            unsigned mask = 1;
            for (unsigned mi = 0; mi < MouseCursorCount; ++mi, mask <<= 1)
            {
                if (!(proceeded & mask) && mMouseState[mi].IsActivated())
                {
                    mMouseState[mi].ResetPrevButtonsState();
                    Render::PointF mousePos = mMouseState[mi].GetLastPosition();
                    Ptr<InteractiveObject> ptop = GetTopMostEntity(mousePos, mi, avm2, 0);
                    mMouseState[mi].SetTopmostEntity(ptop);
                    CheckMouseCursorType(mi, ptop);
                    AsRootSlots(pASMovieRoot)->GenerateMouseEvents(mi);
                }
            }
        }
    }
    FinalizeProcessFocusKey(&focusKeyInfo);
    Flags &= ~Flag_NeedMouseUpdate;
}

// @0x142575f20
// Puts psprite at level, keeping the levels sorted; false when the level is taken. _level0 becomes the main movie:
// its def gives the movie's states, frame time and (unless the host set one) the viewport.
bool MovieImpl::SetLevelMovie(int level, DisplayObjContainer* psprite)
{
    unsigned i = 0;
    for (; i < MovieLevels.GetSize(); i++)
    {
        if (MovieLevels[i].Level >= level)
        {
            if (MovieLevels[i].Level == level)
                return false;
            break;
        }
    }
    Flags |= 0x100;   // the level clips changed

    LevelInfo li;
    li.Level   = level;
    li.pSprite = psprite;
    MovieLevels.InsertAt(i, li);
    psprite->OnInsertionAsLevel(level);

    if (level == 0)
    {
        pMainMovie    = psprite;
        pMainMovieDef = psprite->GetResourceMovieDef();
        if (pMainMovieDef && pAdvanceStats)
            pAdvanceStats->SetName(pMainMovieDef->GetFileURL());
        pStateBag->SetDelegate(pMainMovieDef->pStateBag);
        FrameTime = 1.0f / GetMovieDef()->GetFrameRate();

        if (!IsFlagSet<0x1>(Flags))   // no viewport from the host yet: the stage size
        {
            MovieDefImpl* pdef = psprite->GetResourceMovieDef();
            Viewport desc((int)pdef->GetWidth(), (int)pdef->GetHeight(), 0, 0,
                          (int)pdef->GetWidth(), (int)pdef->GetHeight());
            SetViewport(desc);
        }
    }
    Flags |= Flag_NeedMouseUpdate;
    return true;
}

// ReleaseLevelMovie's level 0 loop has RemoveAt inlined: the same body, kept inline here (the array data is
// protected: reached through a derived view).
template<class A>
struct ArrayDataView : A { using A::Data; };
template<class A>
static SF_INLINE void RemoveLevelAtInline(A& arr, UPInt index)
{
    ArrayDataView<A>& a = static_cast<ArrayDataView<A>&>(arr);
    if (a.Data.Size == 1)
    {
        a.Clear();
    }
    else
    {
        A::AllocatorType::Destruct(a.Data.Data + index);
        A::AllocatorType::CopyArrayForward(a.Data.Data + index, a.Data.Data + index + 1, a.Data.Size - 1 - index);
        --a.Data.Size;
    }
}

// @0x142573ed0
bool MovieImpl::ReleaseLevelMovie(int level)
{
    if (level == 0)
    {
        // Releasing _level0 releases every level, top first.
        CurrentDragState.pCharacter = NULL;
        ShutdownTimers();
        while (MovieLevels.GetSize())
        {
            InteractiveObject* plevel = MovieLevels[MovieLevels.GetSize() - 1].pSprite;
            plevel->OnEventUnload();
            AsRootSlots(pASMovieRoot)->DoActions();
            plevel->ForceShutdown();
            RemoveLevelAtInline(MovieLevels, MovieLevels.GetSize() - 1);
        }
        FrameTime = 1.0f / 12;
        pMainMovie = NULL;
        Flags |= 0x100;   // the level clips changed
        return true;
    }
    for (unsigned i = 0; i < MovieLevels.GetSize(); i++)
    {
        if (MovieLevels[i].Level == level)
        {
            Ptr<InteractiveObject> plevel = MovieLevels[i].pSprite;
            plevel->OnEventUnload();
            AsRootSlots(pASMovieRoot)->DoActions();
            plevel->ForceShutdown();
            MovieLevels.RemoveAt(i);
            Flags |= 0x100;
            return true;
        }
    }
    return false;
}

// The bit-clear test (the exe inverts the shifted byte: `shr al,N; not al; test al,1`).
template<UInt32 mask, class T>
inline bool IsFlagClear(T value)
{
    return (~UInt8(IsFlagSet<mask>(value)) & 1) != 0;
}
// @0x14256d390
void MovieImpl::AdvanceFrame(bool nextFrame, float framePos)
{
    if (nextFrame)
        AsRootSlots(pASMovieRoot)->OnNextFrame();

    // An invalidated optimized list is rebuilt while walking the whole advance list (in its own loop: the advances
    // may change the optimized list).
    if (IsFlagSet<Flag_OptAdvListInvalid>(Flags))
    {
        SIMD::PrefetchObj(pPlayList);
        Flags &= ~Flag_OptAdvListInvalid;
        pPlayListOptHead = NULL;
        // A flipped marker tells the members added from now on from the stale ones.
        bool marker = !GetOptAdvListMarker();
        if (marker) Flags2 |= Flag2_OptAdvListMarker; else Flags2 &= ~Flag2_OptAdvListMarker;

        InteractiveObject* pnextCh;
        for (InteractiveObject* pcurCh = pPlayList; pcurCh; pcurCh = pnextCh)
        {
            pnextCh = pcurCh->pPlayNext;
            SIMD::PrefetchObj(pnextCh);
            if (!pcurCh->IsValidOptAdvListMember(this))
            {
                pcurCh->Flags &= ~InteractiveObject::Mask_OptAdvList;
                pcurCh->SetOptAdvListMarker(marker);
                pcurCh->pPlayNextOpt = pcurCh->pPlayPrevOpt = NULL;
            }
            if (IsFlagClear<DisplayObjectBase::Mask_MarkedForRemove>(pcurCh->DisplayObjectBase::Flags) &&
                !IsFlagSet<DisplayObject::Mask_ExecutionAborted>(pcurCh->DisplayObject::Flags))
            {
                if (!pcurCh->IsValidOptAdvListMember(this) && pcurCh->CheckAdvanceStatus(false) == 1)
                    pcurCh->AddToOptimizedPlayList();
                if (nextFrame || IsFlagSet<InteractiveObject::Mask_ReqPartialAdvance>(pcurCh->Flags))
                    pcurCh->AdvanceFrame(nextFrame, framePos);
            }
        }
    }
    else
    {
        SIMD::PrefetchObj(pPlayListOptHead);
        InteractiveObject* pnextCh;
        for (InteractiveObject* pcurCh = pPlayListOptHead; pcurCh; pcurCh = pnextCh)
        {
            pnextCh = pcurCh->pPlayNextOpt;
            SIMD::PrefetchObj(pnextCh);
            if (IsFlagSet<InteractiveObject::Mask_MarkedToRemoveFromOptAdvList>(pcurCh->Flags))
            {
                pcurCh->RemoveFromOptimizedPlayList();
                continue;
            }
            if (IsFlagClear<DisplayObjectBase::Mask_MarkedForRemove>(pcurCh->DisplayObjectBase::Flags) &&
                (nextFrame || IsFlagSet<InteractiveObject::Mask_ReqPartialAdvance>(pcurCh->Flags)) &&
                !IsFlagSet<DisplayObject::Mask_ExecutionAborted>(pcurCh->DisplayObject::Flags))
                pcurCh->AdvanceFrame(nextFrame, framePos);
        }
    }
    Flags2 &= ~0x2u;   // the registered fonts changed: seen
}

// @0x14256fde0
// MS2-FUNCTIONAL: register allocation (the exe keeps the result in r15 and spills ignoreMC).
InteractiveObject* MovieImpl::GetTopMostEntity(const Render::PointF& mousePos, unsigned controllerIdx, bool testAll,
                                               const InteractiveObject* ignoreMC)
{
    InteractiveObject* ptopMouseCharacter = NULL;

    // The 3D hit tests map the mouse through the view and projection: the position in -1..1 of the visible frame.
    float w = VisibleFrameRect.x2 - VisibleFrameRect.x1;
    float h = VisibleFrameRect.y2 - VisibleFrameRect.y1;
    float nsx = 2.f * ((mousePos.x - ViewOffsetX * 20.f) / w) - 1.f;
    float nsy = 2.f * ((mousePos.y - ViewOffsetY * 20.f) / h) - 1.f;
    ScreenToWorld.SetNormalizedScreenCoords(nsx, nsy);
    Render::Matrix4F projMat;
    GetProjectionMatrix3D(&projMat);
    ScreenToWorld.SetProjection(projMat);
    Render::Matrix3F viewMat;
    GetViewMatrix3D(&viewMat);
    ScreenToWorld.SetView(viewMat);

    // The topmost characters first, the last one on top; their points are in their parents' space.
    for (int i = (int)TopmostLevelCharacters.GetSize() - 1; i >= 0; --i)
    {
        InteractiveObject* pch = TopmostLevelCharacters[i];
        Render::Matrix2F m;
        pch->GetParent()->GetWorldMatrix(&m);
        Render::PointF p(Render::PointF::NoInit);
        m.TransformByInverse(&p, mousePos);
        DisplayObjectBase::TopMostDescr descr;
        descr.pIgnoreMC     = ignoreMC;
        descr.TestAll       = testAll;
        descr.ControllerIdx = controllerIdx;
        if (pch->GetTopMostMouseEntity(p, &descr) == DisplayObjectBase::TopMost_Found)
        {
            ptopMouseCharacter = descr.pResult;
            break;
        }
    }
    if (!ptopMouseCharacter)
    {
        // Then the levels, the highest first.
        for (int movieIndex = (int)MovieLevels.GetSize(); movieIndex > 0; movieIndex--)
        {
            InteractiveObject* pmovie = MovieLevels[movieIndex - 1].pSprite;
            DisplayObjectBase::TopMostDescr descr;
            descr.pIgnoreMC     = ignoreMC;
            descr.TestAll       = testAll;
            descr.ControllerIdx = controllerIdx;
            if (pmovie->GetTopMostMouseEntity(mousePos, &descr) == DisplayObjectBase::TopMost_Found)
                return descr.pResult;
        }
    }
    return ptopMouseCharacter;
}

// A twips value snapped down to a whole pixel.
static SF_INLINE float SnapToPixel(float twips)
{
    return float(int(Render::TwipsToPixels(twips)) * 20);
}

// @0x1425787d0
// MS2-FUNCTIONAL: register allocation and store scheduling (the exe reloads VisibleFrameRect members it just stored).
void MovieImpl::UpdateViewport()
{
    Render::RectF prevVisibleFrameRect = VisibleFrameRect;
    float prevViewOffsetX = ViewOffsetX, prevViewOffsetY = ViewOffsetY;
    float prevViewScaleX = ViewScaleX, prevViewScaleY = ViewScaleY;
    float prevPixelScale = PixelScale;

    if (pMainMovieDef)
    {
        // The viewport in twips and the stage the movie wants.
        Render::RectF viewRect(Render::PixelsToTwips(float(mViewport.Left)),
                               Render::PixelsToTwips(float(mViewport.Top)),
                               Render::PixelsToTwips(float(mViewport.Left + mViewport.Width)),
                               Render::PixelsToTwips(float(mViewport.Top + mViewport.Height)));
        float viewWidth   = viewRect.Width();
        float viewHeight  = viewRect.Height();
        const Render::RectF& frameRect = pMainMovieDef->GetDataDef()->GetFrameRectInTwips();
        float frameWidth  = frameRect.Width();
        float frameHeight = frameRect.Height();

        switch (ViewScaleMode)
        {
        case SM_NoScale:
            {
                // The stage at its own size, placed by the alignment on whole pixels.
                float width  = viewWidth * mViewport.AspectRatio * mViewport.Scale;
                float height = viewHeight * mViewport.Scale;
                switch (ViewAlignment)
                {
                case Align_Center:
                    VisibleFrameRect.x1 = SnapToPixel(frameWidth / 2 - width / 2);
                    VisibleFrameRect.y1 = SnapToPixel(frameHeight / 2 - height / 2);
                    break;
                case Align_TopCenter:
                    VisibleFrameRect.y1 = 0;
                    VisibleFrameRect.x1 = SnapToPixel(frameWidth / 2 - width / 2);
                    break;
                case Align_BottomCenter:
                    VisibleFrameRect.y1 = frameHeight - height;
                    VisibleFrameRect.x1 = SnapToPixel(frameWidth / 2 - width / 2);
                    break;
                case Align_CenterLeft:
                    VisibleFrameRect.x1 = 0;
                    VisibleFrameRect.y1 = SnapToPixel(frameHeight / 2 - height / 2);
                    break;
                case Align_CenterRight:
                    VisibleFrameRect.x1 = frameWidth - width;
                    VisibleFrameRect.y1 = SnapToPixel(frameHeight / 2 - height / 2);
                    break;
                case Align_TopLeft:
                    VisibleFrameRect.x1 = 0;
                    VisibleFrameRect.y1 = 0;
                    break;
                case Align_TopRight:
                    VisibleFrameRect.y1 = 0;
                    VisibleFrameRect.x1 = frameWidth - width;
                    break;
                case Align_BottomLeft:
                    VisibleFrameRect.x1 = 0;
                    VisibleFrameRect.y1 = frameHeight - height;
                    break;
                case Align_BottomRight:
                    VisibleFrameRect.x1 = frameWidth - width;
                    VisibleFrameRect.y1 = frameHeight - height;
                    break;
                }
                VisibleFrameRect.x2 = width + VisibleFrameRect.x1;
                VisibleFrameRect.y2 = height + VisibleFrameRect.y1;
                ViewOffsetX = Render::TwipsToPixels(VisibleFrameRect.x1);
                ViewOffsetY = Render::TwipsToPixels(VisibleFrameRect.y1);
                ViewScaleX  = mViewport.Scale * mViewport.AspectRatio;
                ViewScaleY  = mViewport.Scale;
            }
            break;

        case SM_ShowAll:
        case SM_NoBorder:
            {
                // The whole stage (show all) or the whole viewport (no border), the stage's aspect kept: the other
                // dimension is centered.
                float viewWidthAR = viewWidth * mViewport.AspectRatio;
                if ((ViewScaleMode == SM_ShowAll && viewHeight / frameHeight > viewWidthAR / frameWidth) ||
                    (ViewScaleMode == SM_NoBorder && viewWidthAR / frameWidth > viewHeight / frameHeight))
                {
                    float visibleHeight = frameWidth * viewHeight / viewWidthAR;
                    VisibleFrameRect.x1 = 0;
                    VisibleFrameRect.x2 = frameWidth + VisibleFrameRect.x1;
                    VisibleFrameRect.y1 = frameHeight / 2 - visibleHeight / 2;
                    VisibleFrameRect.y2 = visibleHeight + VisibleFrameRect.y1;
                    ViewOffsetX = 0;
                    ViewOffsetY = Render::TwipsToPixels(VisibleFrameRect.y1);
                    ViewScaleX  = viewWidth ? (frameWidth / viewWidth) : 0.0f;
                    ViewScaleY  = ViewScaleX / mViewport.AspectRatio;
                }
                else
                {
                    float visibleWidth = viewWidthAR * frameHeight / viewHeight;
                    VisibleFrameRect.y1 = 0;
                    VisibleFrameRect.x1 = frameWidth / 2 - visibleWidth / 2;
                    VisibleFrameRect.x2 = VisibleFrameRect.x1 + visibleWidth;
                    VisibleFrameRect.y2 = frameHeight + VisibleFrameRect.y1;
                    ViewOffsetX = Render::TwipsToPixels(VisibleFrameRect.x1);
                    ViewOffsetY = 0;
                    ViewScaleY  = viewHeight ? (frameHeight / viewHeight) : 0.0f;
                    ViewScaleX  = ViewScaleY * mViewport.AspectRatio;
                }
            }
            break;

        case SM_ExactFit:
            // The stage stretched over the viewport.
            VisibleFrameRect.x1 = 0;
            VisibleFrameRect.y1 = 0;
            VisibleFrameRect.x2 = frameWidth + VisibleFrameRect.x1;
            VisibleFrameRect.y2 = frameHeight + VisibleFrameRect.y1;
            ViewOffsetX = 0;
            ViewOffsetY = 0;
            ViewScaleX  = viewWidth ? (VisibleFrameRect.Width() / viewWidth) : 0.0f;
            ViewScaleY  = viewHeight ? (VisibleFrameRect.Height() / viewHeight) : 0.0f;
            break;
        }
        // Twips per pixel: the larger of the two directions.
        float scaleY = ViewScaleY ? (1.0f / ViewScaleY) : 0.005f;
        float scaleX = ViewScaleX ? (1.0f / ViewScaleX) : 0.005f;
        PixelScale = Alg::Max(scaleX, scaleY);
    }
    else
    {
        ViewOffsetX = ViewOffsetY = 0;
        ViewScaleX  = ViewScaleY = 1.0f;
        PixelScale  = 1.0f;
    }
    ResetViewportMatrix();

    // A changed view goes to the levels (their 3D views and projections follow it).
    if (prevVisibleFrameRect != VisibleFrameRect ||
        prevViewOffsetX != ViewOffsetX || prevViewOffsetY != ViewOffsetY ||
        prevViewScaleX != ViewScaleX || prevViewScaleY != ViewScaleY ||
        prevPixelScale != PixelScale)
    {
        if (!VisibleFrameRect.IsNull())
        {
            for (unsigned i = 0; i < MovieLevels.GetSize(); i++)
                if (MovieLevels[i].pSprite)
                    MovieLevels[i].pSprite->UpdateViewAndPerspective();
        }
    }
}

// The Matrix2F inverse the exe keeps out of line (exe 0x142446cb0, defined by sfr_as2_01).
namespace AS2 { void Matrix2F_SetInverse(Render::Matrix2F* m, const Render::Matrix2F& src); }

// Moves (and maybe scales) the view so that box, in viewport pixels, shows inside screenRect.
// MS2-FUNCTIONAL: register allocation (the exe keeps one more xmm register and a scalar sign mask).
// @0x142571380
void MovieImpl::MakeAreaVisible(const Render::RectF& screenRect, const Render::RectF& box, UInt32 flags)
{
    if (screenRect.Contains(box))
        return;

    // The screen rect and the box in stage twips.
    Render::Matrix2F invViewport;
    ResetViewportMatrix();
    AS2::Matrix2F_SetInverse(&invViewport, ViewportMatrix);
    Render::RectF ptBox;
    invViewport.EncloseTransform(&ptBox, screenRect);
    Render::RectF boxTw(Render::PixelsToTwips(box.x1), Render::PixelsToTwips(box.y1),
                        Render::PixelsToTwips(box.x2), Render::PixelsToTwips(box.y2));

    double scaleX = 1.0, scaleY = 1.0;
    if (!(flags & MAVF_DontScaleDown))
    {
        if (boxTw.Width() > ptBox.Width())
            scaleX = double(ptBox.Width()) / double(boxTw.Width());
        if (boxTw.Height() > ptBox.Height())
            scaleY = double(ptBox.Height()) / double(boxTw.Height());
    }
    if ((flags & MAVF_ScaleUp50) && scaleX == 1.0 && scaleY == 1.0)
    {
        // A small box grows to half the screen rect's area, its aspect kept, but never past the screen rect.
        double screenArea = ptBox.Height() * ptBox.Width();
        if (screenArea > boxTw.Height() * boxTw.Width() * 2)
        {
            double boxWidth  = boxTw.Width();
            double boxHeight = boxTw.Height();
            double halfArea  = screenArea * 0.5;
            double newWidth  = sqrt(boxWidth / boxHeight * halfArea);
            double newHeight = halfArea / newWidth;
            scaleX = newWidth / boxWidth;
            scaleY = newHeight / boxHeight;
            if (boxWidth * scaleX > ptBox.Width())
                scaleX = ptBox.Width() / boxWidth;
            if (boxHeight * scaleY > ptBox.Height())
                scaleY = ptBox.Height() / boxHeight;
        }
    }
    float scale = float(Alg::Min(scaleX, scaleY));

    // Scaled about the box's top left.
    Render::Matrix2F m;
    m.AppendTranslation(-boxTw.x1, -boxTw.y1);
    m.AppendScaling(scale);
    m.AppendTranslation(boxTw.x1, boxTw.y1);
    Render::RectF newBox;
    m.EncloseTransform(&newBox, boxTw);

    // A box that sticks out is centered in the screen rect (or put at its top left).
    float dx = 0, dy = 0;
    if (newBox.x1 > ptBox.x2 || ptBox.x1 > newBox.x2 || newBox.x2 > ptBox.x2 || ptBox.x1 > newBox.x1)
    {
        if (!(flags & MAVF_LeftTopToZero))
            dx = (newBox.x1 + newBox.Width() * 0.5f) - (ptBox.x2 - ptBox.Width() * 0.5f);
        else
            dx = newBox.x1 - ptBox.x1;
    }
    if (newBox.y1 > ptBox.y2 || ptBox.y1 > newBox.y2 || newBox.y2 > ptBox.y2 || ptBox.y1 > newBox.y1)
    {
        if (!(flags & MAVF_LeftTopToZero))
            dy = (newBox.y1 + newBox.Height() * 0.5f) - (ptBox.y2 - ptBox.Height() * 0.5f);
        else
            dy = newBox.y1 - ptBox.y1;
    }
    m.AppendTranslation(-dx, -dy);

    ViewportMatrix.Prepend(m);
    pRenderRoot->SetMatrix(ViewportMatrix);
}

// A mouse event from the queue: the topmost entity, the IME, the levels' mouse events, the focus rectangle, the wheel,
// the AVM's mouse events and the focus a left click moves.
// @0x142573380
void MovieImpl::ProcessMouse(const InputEventsQueueEntry* qe, UInt32* miceProceededMask, bool avm2)
{
    const InputEventsQueueEntry::MouseEntry& me = qe->GetMouseEntry();
    *miceProceededMask |= (1 << me.MouseIndex);
    unsigned    mi = me.MouseIndex;
    MouseState& ms = mMouseState[mi];
    ms.UpdateState(*qe);

    Ptr<InteractiveObject> ptopMouseCharacter = GetTopMostEntity(me.GetPosition(), mi, avm2, NULL);
    ms.SetTopmostEntity(ptopMouseCharacter);
    unsigned buttonsState = mMouseState[mi].GetButtonsState();

    if (me.IsButtonsStateChanged())
    {
        Ptr<IMEManagerBase> pimeManager = *(IMEManagerBase*)GetStateAddRef(State::State_IMEManager);
        if (pimeManager && pimeManager->IsMovieActive(this))
        {
            if (!(me.Flags & (InputEventsQueueEntry::MouseButton_Move | InputEventsQueueEntry::MouseButton_Released)) &&
                me.IsButtonsStateChanged())
                pimeManager->OnMouseDown(this, buttonsState, ptopMouseCharacter);
            else
                pimeManager->OnMouseUp(this, buttonsState, ptopMouseCharacter);
        }
    }

    UInt32 mouseEvent = 0;
    if (me.IsButtonsStateChanged() && (me.ButtonsState & InputEventsQueueEntry::MouseButton_Left))
        mouseEvent = (me.Flags & (InputEventsQueueEntry::MouseButton_Move | InputEventsQueueEntry::MouseButton_Released))
                         ? EventId::Event_MouseUp : EventId::Event_MouseDown;
    for (unsigned movieIndex = (unsigned)MovieLevels.GetSize(); movieIndex > 0; movieIndex--)
    {
        InteractiveObject* pmovie = MovieLevels[movieIndex - 1].pSprite;
        if (mouseEvent)
        {
            EventId evt(mouseEvent);
            evt.ButtonId    = 0;
            evt.MouseIndex  = (SByte)mi;
            evt.RollOverCnt = 0;
            pmovie->PropagateMouseEvent(evt);
        }
        if (mMouseState[mi].MouseMoved)
        {
            EventId evt(EventId::Event_MouseMove);
            evt.ButtonId    = 0;
            evt.MouseIndex  = (SByte)mi;
            evt.RollOverCnt = 0;
            pmovie->PropagateMouseEvent(evt);
        }
    }

    if ((!IsFlagSet<Flag_DisableFocusAutoReleaseByMouseClick>(Flags) && me.IsButtonsStateChanged()) ||
        (!IsDisableFocusAutoRelease() && mMouseState[mi].MouseMoved))
        HideFocusRect(mi);

    if (me.IsMouseWheel() && ptopMouseCharacter)
        ptopMouseCharacter->OnMouseWheelEvent(me.WheelScrollDelta);

    AsRootSlots(pASMovieRoot)->NotifyMouseState(qe, &ms, mi);
    CheckMouseCursorType(mi, ptopMouseCharacter);

    // A left click moves the focus to what is under the mouse.
    if (!(me.Flags & (InputEventsQueueEntry::MouseButton_Move | InputEventsQueueEntry::MouseButton_Released)) &&
        me.IsButtonsStateChanged() && (me.ButtonsState & InputEventsQueueEntry::MouseButton_Left))
    {
        Ptr<InteractiveObject> curFocused = FocusGroups[FocusGroupIndexes[mi]].LastFocused;
        if (ptopMouseCharacter != curFocused)
            QueueSetFocusTo(ptopMouseCharacter, ptopMouseCharacter, mi, GFx_FocusMovedByMouse, NULL);
    }
    AsRootSlots(pASMovieRoot)->GenerateMouseEvents(mi);
}

// Restarts the movie from frame 1 of its own definition: drops the levels, the load queue, the focus and the
// input state, then lets the AVM root create _level0 again.
// MS2-FUNCTIONAL: instruction scheduling (the load queue null stores, the Flags2 clear before the Init call, the
// callee-saved restores after the two releases); same operations.
// @0x142575410
void MovieImpl::Restart(bool advance0)
{
    if (pMainMovie)
    {
        Flags2 |= 0x4;   // restarting
        ProcessUnloadQueue();

        Ptr<MovieDefImpl> prootMovieDef = pMainMovie->GetResourceMovieDef();

        for (int i = (int)MovieLevels.GetSize() - 1; i >= 0; i--)
            ReleaseLevelMovie(i);
        MovieLevels.Clear();

        // Cancel the loader-thread requests and wait until every one of them is done.
        LoadQueueEntryMT* plq = pLoadQueueMTHead;
        unsigned plqCount = 0;
        while (plq)
        {
            plqCount++;
            plq->Cancel();
            plq = plq->pNext;
        }
        if (plqCount)
        {
            unsigned plqDoneCount;
            do
            {
                plqDoneCount = 0;
                for (plq = pLoadQueueMTHead; plq; plq = plq->pNext)
                {
                    if (plq->LoadFinished())
                        plqDoneCount++;
                }
            } while (plqCount > plqDoneCount);
        }
        while (pLoadQueueHead)
        {
            LoadQueueEntry* pentry = pLoadQueueHead;
            pLoadQueueHead = pentry->pNext;
            delete pentry;
        }
        while (pLoadQueueMTHead)
        {
            LoadQueueEntryMT* pentry = pLoadQueueMTHead;
            pLoadQueueMTHead = pentry->pNext;
            delete pentry;
        }
        pLoadQueueHead   = NULL;
        pLoadQueueMTHead = NULL;

        Flags |= Flag_OptAdvListInvalid;   // InvalidateOptAdvanceList
        pPlayListOptHead = NULL;
        pPlayList        = NULL;

        bool imeWasActive = false;
        Ptr<IMEManagerBase> pIMEManager = *(IMEManagerBase*)GetStateAddRef(State::State_IMEManager);
        if (pIMEManager && pIMEManager->IsMovieActive(this))
        {
            imeWasActive = true;
            pIMEManager->SetActiveMovie(NULL);
        }
        SF_FREE(pIMECandidateListStyle);
        pIMECandidateListStyle = NULL;

        VideoProviders.Clear();

        if (pMainMovie)
        {
            InteractiveObject* psprite = pMainMovie->IsSprite() ? pMainMovie : NULL;
            psprite->StopActiveSounds();
        }

        AsRootSlots(pASMovieRoot)->Shutdown();
        ClearIndirectTransformPairs();

        delete pRetValHolder;
        pRetValHolder = NULL;

        for (unsigned i = 0; i < FocusGroupsCnt; ++i)
        {
            FocusGroupDescr& fg = FocusGroups[i];
            fg.ModalClip = NULL;
            if (fg.TabableArrayStatus & 1)
            {
                fg.TabableArray.Clear();
                fg.TabableArrayStatus = 0;
            }
            fg.LastFocusKeyCode = 0;
        }

        // The focus options (_focusrect, disableFocusKeys, ...) go back to undefined.
        Flags &= 0x3fffff;
        for (unsigned i = 0; i < 4; ++i)
            mMouseState[i].ResetState();

        AsRootSlots(pASMovieRoot)->ForceCollect();
        Flags2 &= ~0x4u;
        AsRootSlots(pASMovieRoot)->Init(prootMovieDef);

        if (pMainMovie)
        {
            if (pUserEventHandler)
            {
                for (unsigned i = 0; i < MouseCursorCount; ++i)
                {
                    pUserEventHandler->HandleEvent(this, MouseCursorEvent(Event::DoShowMouse, i));
                    pUserEventHandler->HandleEvent(this, MouseCursorEvent(MouseCursorEvent::ARROW, i));
                }
            }
            FocusRectChanged = true;
            for (unsigned i = 0; i < 4; ++i)
                KeyboardStates[i].ResetState();
            if (imeWasActive)
                pIMEManager->SetActiveMovie(this);
            if (advance0)
                Advance(0.0f, 0, true);
            AsRootSlots(pASMovieRoot)->ForceCollect();
        }
    }
}

// A character going away loses the focus of every group that has it; the group's controllers are told.
// @0x142574820
void MovieImpl::ResetFocusForChar(InteractiveObject* ch)
{
    for (unsigned i = 0; i < FocusGroupsCnt; ++i)
    {
        if (Ptr<InteractiveObject>(FocusGroups[i].LastFocused).GetPtr() == ch)
        {
            Ptr<InteractiveObject> curFocused = FocusGroups[i].LastFocused;
            if (curFocused && !IsShutdowning())
            {
                unsigned mask = GetControllerMaskByFocusGroup(i);
                unsigned n    = GetControllerCount();
                for (unsigned c = 0; mask && c < n; ++c, mask >>= 1)
                    SetFocusTo(NULL, c, GFx_FocusMovedByKeyboard);
            }
            FocusGroups[i].LastFocused = NULL;
        }
    }
}

// Every focus group drops its modal clip, its tab order and the key that last moved its focus.
// @0x142574b00
void MovieImpl::ResetFocusStates()
{
    for (unsigned i = 0; i < FocusGroupsCnt; ++i)
    {
        FocusGroupDescr& fg = FocusGroups[i];
        fg.ModalClip = NULL;
        if (fg.TabableArrayStatus & 1)
        {
            fg.TabableArray.Clear();
            fg.TabableArrayStatus = 0;
        }
        fg.LastFocusKeyCode = 0;
    }
}

// Every focus group drops a filled tab order, so the next focus key collects it again.
// @0x142574da0
void MovieImpl::ResetTabableArrays()
{
    for (unsigned i = 0; i < FocusGroupsCnt; ++i)
    {
        FocusGroupDescr& fg = FocusGroups[i];
        if (fg.TabableArrayStatus & 1)
        {
            fg.TabableArray.Clear();
            fg.TabableArrayStatus = 0;
        }
    }
}

// Moves the movie on by deltaT seconds: refreshes the cached states, runs the interval timers, the videos, the sound
// and the queued input, then as many whole frames as are due (a catch-up count lets it run several in one call) or
// just the in-between position. Returns the seconds until it should be called again.
// @0x14256c610
// MS2-FUNCTIONAL
float MovieImpl::Advance(float deltaT, unsigned frameCatchUpCount, bool capture)
{
    if (IsFlagSet<Flag_Paused>(Flags))
    {
        if (capture)
            MovieImpl::Capture(true);
        return 0.05f;
    }
    if (!pMainMovie)
    {
        // Nothing to play (a script may have unloaded it): still hand the renderer the empty frame.
        if (capture)
            MovieImpl::Capture(true);
        return pMainMovieDef ? 1.0f / pMainMovieDef->GetFrameRate() : 0.0f;
    }

    ProcessMovieDefToKillList();

    if (deltaT < 0.0f)
        deltaT = 0.0f;
    SetFlag<Flag_AdvanceCalled>(Flags, true);

    // The states, fetched under one lock.
    Ptr<ActionControl> pac;
    State* pstates[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    static const State::StateType stateQuery[10] = {
        State::State_UserEventHandler, State::State_FSCommandHandler, State::State_ExternalInterface,
        State::State_ActionControl,    State::State_Log,              State::State_FontLib,
        State::State_FontMap,          State::State_FontProvider,     State::State_Translator,
        State::State_Audio};
    pStateBag->GetStatesAddRef(pstates, stateQuery, 10);

    Ptr<LogState> logState;
    pUserEventHandler = *(UserEventHandler*)pstates[0];
    pFSCommandHandler = *(FSCommandHandler*)pstates[1];
    pExtIntfHandler   = *(ExternalInterface*)pstates[2];
    pac               = *(ActionControl*)pstates[3];
    logState          = *(LogState*)pstates[4];
    pCachedLog = logState ? logState->GetLog() : 0;

    // A changed font state empties the font caches below.
    UInt8 stateChangeFlag = 0;
    {
        Ptr<FontLib>      fontLib      = *(FontLib*)pstates[5];
        Ptr<FontMap>      fontMap      = *(FontMap*)pstates[6];
        Ptr<FontProvider> fontProvider = *(FontProvider*)pstates[7];
        Ptr<Translator>   translator   = *(Translator*)pstates[8];
        stateChangeFlag = pFontManagerStates->CheckStateChange(fontLib, fontMap, fontProvider, translator);
    }

    SetFlag<Flag_CachedLogFlag>(Flags, true);
    if (pac)
    {
        SetFlag<Flag_VerboseAction>(Flags, (pac->GetActionFlags() & ActionControl::Action_Verbose) != 0);
        SetFlag<Flag_SuppressActionErrors>(Flags, (pac->GetActionFlags() & ActionControl::Action_ErrorSuppress) != 0);
        SetFlag<Flag_LogRootFilenames>(Flags, (pac->GetActionFlags() & ActionControl::Action_LogRootFilenames) != 0);
        SetFlag<Flag_LogLongFilenames>(Flags, (pac->GetActionFlags() & ActionControl::Action_LongFilenames) != 0);
        SetFlag<Flag_LogChildFilenames>(Flags, (pac->GetActionFlags() & ActionControl::Action_LogChildFilenames) != 0);
    }
    else
    {
        SetFlag<Flag_VerboseAction>(Flags, false);
        SetFlag<Flag_SuppressActionErrors>(Flags, false);
        SetFlag<Flag_LogRootFilenames>(Flags, false);
        SetFlag<Flag_LogLongFilenames>(Flags, false);
        SetFlag<Flag_LogChildFilenames>(Flags, false);
    }

    // The audio state and its renderer are held until the advance returns.
    pAudio = (AudioBase*)pstates[9];
    AdvanceStateGuard<AudioBase> audioGuard(&pAudio);
    if (pAudio)
    {
        pSoundRenderer = pAudio->GetRenderer();
        if (pSoundRenderer)
            pSoundRenderer->AddRef();
    }
    AdvanceStateGuard<Sound::SoundRenderer> rendererGuard(&pSoundRenderer);

    // Every root node takes the loading progress of its movie once, so all the clips sharing a movie see the same.
    MovieDefRootNode* pnode = RootMovieDefNodes.pNext;
    MovieDefRootNodeLinks* proot = &RootMovieDefNodes;
    while (pnode != static_cast<MovieDefRootNode*>(proot))
    {
        if (!pnode->ImportFlag)
        {
            pnode->BytesLoaded  = pnode->pDefImpl->pBindData->GetBytesLoaded();
            pnode->LoadingFrame = pnode->pDefImpl->GetLoadingFrame();
        }
        if (stateChangeFlag)
            pnode->pFontManager->CleanCache();
        pnode = pnode->pNext;
    }

    // The text fields re-resolve their fonts.
    if (stateChangeFlag || IsFlagSet<0x2>(Flags2))
    {
        for (unsigned i = 0; i < MovieLevels.GetSize(); i++)
            MovieLevels[i].pSprite->SetStateChangeFlags(stateChangeFlag);
    }

    if (pMainMovie->GetLoadingFrame() == 0)
    {
        // The first frame is not there yet.
        if (capture)
            MovieImpl::Capture(true);
        SetFlag<Flag_CachedLogFlag>(Flags, false);
        return 0;
    }

    // New levels run their frame 0 (and its actions) before any frame advance.
    if (IsFlagSet<Flag_LevelClipsChanged>(Flags) && pMainMovie->GetLoadingFrame() > 0)
    {
        SetFlag<Flag_LevelClipsChanged>(Flags, false);
        for (unsigned level = (unsigned)MovieLevels.GetSize(); level > 0; level--)
            MovieLevels[level - 1].pSprite->ExecuteFrame0Events();
        AsRootSlots(pASMovieRoot)->DoActions();
        ProcessUnloadQueue();
        ProcessLoadQueue();
    }

    TimeElapsed += UInt64(deltaT * 1000000.f);
    TimeRemainder += deltaT;

    UInt64 advanceStart = Timer::GetProfileTicks();
    float  minDelta = FrameTime;

    // The interval timers: the due ones fire; the stopped ones are cleared out afterwards.
    if (IntervalTimers.GetSize() > 0)
    {
        UPInt    i, n;
        unsigned inactive = 0;
        for (i = 0, n = IntervalTimers.GetSize(); i < n; ++i)
        {
            if (IntervalTimers[i] && IntervalTimers[i]->IsActive())
            {
                IntervalTimers[i]->Invoke(this, FrameTime);
                float delta = float(IntervalTimers[i]->GetNextInvokeTime() - TimeElapsed) / 1000000.f;
                if (delta < minDelta)
                    minDelta = delta;
            }
            else
                ++inactive;
        }
        if (inactive)
        {
            unsigned j;
            for (i = j = 0, n = IntervalTimers.GetSize(); i < n; ++i)
            {
                if (!IntervalTimers[j] || !IntervalTimers[j]->IsActive())
                {
                    IntervalTimers[j]->Clear();
                    IntervalTimers.RemoveAt(j);
                }
                else
                    ++j;
            }
        }
    }

    // The videos: a playing one may shorten the wait; the finished ones are closed and dropped.
    if (VideoProviders.GetSize() > 0)
    {
        Array<Video::VideoProvider*> finished;
        for (HashSet<Ptr<Video::VideoProvider> >::Iterator it = VideoProviders.Begin(); it != VideoProviders.End(); ++it)
        {
            Ptr<Video::VideoProvider> pvideo = *it;
            pvideo->Advance();
            if (pvideo->IsActive())
            {
                if (pvideo->GetFrameTime() < minDelta)
                    minDelta = pvideo->GetFrameTime();
            }
            else
            {
                pvideo->Close();
                finished.PushBack(pvideo);
            }
        }
        for (UPInt i = 0; i < finished.GetSize(); ++i)
            RemoveVideoProvider(finished[i]);
    }

    if (pSoundRenderer)
    {
        float delta = pSoundRenderer->Update();
        if (delta < minDelta)
            minDelta = delta;
    }

    ProcessInput();

    if (TimeRemainder >= FrameTime)
    {
        // Run what the input queued first, so a gotoAndPlay is not overridden by the next frame's actions.
        AsRootSlots(pASMovieRoot)->DoActions();

        bool frameCatchUp = frameCatchUpCount > 0 || ForceFrameCatchUp > 0;
        do
        {
            if (frameCatchUp)
                TimeRemainder -= FrameTime;
            else
                TimeRemainder = (float)fmod(TimeRemainder, FrameTime);

            float framePos = (TimeRemainder >= FrameTime) ? 0.0f : (TimeRemainder / FrameTime);
            AdvanceFrame(true, framePos);
            // The videos follow the timeline.
        if (VideoProviders.GetSize() > 0)
        {
            Array<Video::VideoProvider*> finished;
            for (HashSet<Ptr<Video::VideoProvider> >::Iterator it = VideoProviders.Begin(); it != VideoProviders.End(); ++it)
            {
                Ptr<Video::VideoProvider> pvideo = *it;
                pvideo->Advance();
                if (pvideo->IsActive())
                {
                    if (pvideo->GetFrameTime() < minDelta)
                        minDelta = pvideo->GetFrameTime();
                }
                else
                {
                    pvideo->Close();
                    finished.PushBack(pvideo);
                }
            }
            for (UPInt i = 0; i < finished.GetSize(); ++i)
                RemoveVideoProvider(finished[i]);
        }

            AsRootSlots(pASMovieRoot)->DoActions();
            ProcessUnloadQueue();
            ProcessLoadQueue();
            if (ForceFrameCatchUp > 0)
                ForceFrameCatchUp--;
        } while ((frameCatchUpCount-- > 0 && TimeRemainder >= FrameTime) || ForceFrameCatchUp > 0);

        // The buttons recheck the mouse next time.
        SetFlag<Flag_NeedMouseUpdate>(Flags, true);
        AsRootSlots(pASMovieRoot)->AdvanceFrame(true);
    }
    else
    {
        // Only the in-between position moves.
        float framePos = TimeRemainder / FrameTime;
        AdvanceFrame(false, framePos);
        TimeRemainder = (float)fmod(TimeRemainder, FrameTime);

        AsRootSlots(pASMovieRoot)->DoActions();
        ProcessUnloadQueue();
        ProcessLoadQueue();
        AsRootSlots(pASMovieRoot)->AdvanceFrame(false);
    }

    UpdateAllRenderNodes();
    ResetTabableArrays();
    SetFlag<Flag_CachedLogFlag>(Flags, false);

    // The time spent here comes off the wait.
    UInt64 advanceStop = Timer::GetProfileTicks();
    minDelta -= float(advanceStop - advanceStart) / 1000000.f;
    minDelta = Alg::Max(0.0f, minDelta);

    if (capture)
        MovieImpl::Capture(true);
    return Alg::Min(minDelta, FrameTime - TimeRemainder);
}

// Freezes the frame's changes into a snapshot for the render thread when anything changed (or always, unless
// onChangeOnly). An object drawn under another parent first gets the matrix that keeps it where its original parent
// would have put it, once any node on either parent chain moved. With nothing changed it still captures as many
// times as were asked for (PreviouslyCaptured).
// @0x14256d630
// MS2-FUNCTIONAL
void MovieImpl::Capture(bool onChangeOnly)
{
    if (!onChangeOnly || RenderContext.HasChanges() || MovieDefKillList.GetSize() != 0)
    {
        if (IndirectTransformPairs.GetSize())
        {
            for (UPInt i = 0, n = IndirectTransformPairs.GetSize(); i < n; ++i)
            {
                const IndirectTransPair& p = IndirectTransformPairs[i];
                Render::TreeNode* node = p.Obj->GetRenderNode();

                // a moved node, a mask change or a new parent node on either chain
                static const unsigned CHBITS = Render::Change_Matrix | Render::Change_State_MaskNode |
                                               Render::Change_IsMask | Render::Change_ChildInsert |
                                               (unsigned)Render::Change_Context_NewNode;

                bool changed = node->HasChanges(CHBITS);
                if (!changed)
                {
                    // the original parents; a different depth means the object was taken off one of them
                    Render::TreeNode* cur;
                    int depth = 0;
                    for (cur = p.TransformParent; cur && cur != pRenderRoot; cur = cur->GetParent(), ++depth)
                    {
                        if (cur->HasChanges(CHBITS))
                        {
                            changed = true;
                            break;
                        }
                    }
                    if (depth != p.OrigParentDepth)
                    {
                        changed = true;
                        p.OrigParentDepth = depth;
                    }
                    else if (!changed)
                    {
                        // the parents it is drawn under now
                        for (cur = node->GetParent(); cur && cur != pRenderRoot; cur = cur->GetParent())
                        {
                            if (cur->HasChanges(CHBITS))
                            {
                                changed = true;
                                break;
                            }
                        }
                    }
                }

                if (changed)
                {
                    // the object's own matrix under the original parents, against the one of the parents now
                    const DisplayObjectBase::IndirectTransformDataType* ixf = p.Obj->pIndXFormData;
                    Render::Matrix3F revm(ixf->OrigTransformMatrix);
                    bool is3D = ixf->IsOrig3D;
                    for (Render::TreeNode* cur = p.TransformParent; cur && cur != pRenderRoot; cur = cur->GetParent())
                    {
                        if (cur->Is3D())
                        {
                            revm.Append(cur->M3D());
                            is3D = true;
                        }
                        else
                            revm.Append(cur->M2D());
                    }

                    Render::Matrix3F wm;
                    for (Render::TreeNode* cur = node->GetParent(); cur && cur != pRenderRoot; cur = cur->GetParent())
                    {
                        if (cur->Is3D())
                        {
                            wm.Append(cur->M3D());
                            is3D = true;
                        }
                        else
                            wm.Append(cur->M2D());
                    }
                    if (is3D)
                    {
                        wm.Invert();
                        wm.Prepend(revm);
                        node->SetMatrix3D(wm);
                    }
                    else
                    {
                        Render::Matrix2F& revm2 = *(Render::Matrix2F*)(void*)&revm;
                        Render::Matrix2F& wm2   = *(Render::Matrix2F*)(void*)&wm;
                        wm2.Invert();
                        wm2.Prepend(revm2);
                        node->SetMatrix(wm2);
                    }
                }
            }
        }

        SetFlag<Flag_HasChanges>(Flags, IsFlagSet<Flag_HasChanges>(Flags) || RenderContext.HasChanges());
        RenderContext.Capture();
        PreviouslyCaptured = 1;
    }
    else if (PreviouslyCaptured > 0)
    {
        RenderContext.Capture();
        --PreviouslyCaptured;
    }
}

// A topmost object goes before the first one drawn above it: a higher level, or, on the same level, a display
// list sibling (of the first parents that differ) at a greater depth. A level movie never stays on top.
// @0x14256c140
void MovieImpl::AddTopmostLevelCharacter(InteractiveObject* pch)
{
    if (pch->IsSprite() && static_cast<Sprite*>(pch)->IsLevelMovie())
        return;

    UPInt i = 0;
    if (TopmostLevelCharacters.GetSize() > 0)
    {
        ArrayDH<DisplayObjectBase*> chParents(GetHeap());
        ArrayDH<DisplayObjectBase*> curParents(GetHeap());
        DisplayObjectBase* chRoot;
        DisplayObjectBase* p = pch;
        do
        {
            chParents.PushBack(p);
            chRoot = p;
            p = p->GetParent();
        } while (p);

        for (UPInt n = TopmostLevelCharacters.GetSize(); i < n; ++i)
        {
            if (TopmostLevelCharacters[i] == pch)
                return;
            curParents.Clear();
            DisplayObjectBase* curRoot = NULL;
            for (DisplayObjectBase* c = TopmostLevelCharacters[i]; c; c = c->GetParent())
            {
                curParents.PushBack(c);
                curRoot = c;
            }
            if (curRoot == chRoot)
            {
                SPInt ci = (SPInt)chParents.GetSize() - 1, cj = (SPInt)curParents.GetSize() - 1;
                bool above = false;
                for (; ci >= 0 && cj >= 0; --ci, --cj)
                {
                    if (chParents[ci] != curParents[cj])
                    {
                        if (chParents[ci]->Depth < curParents[cj]->Depth)
                            above = true;
                        break;
                    }
                }
                if (above)
                    break;
            }
            else if (static_cast<Sprite*>(curRoot)->GetLevel() > static_cast<Sprite*>(chRoot)->GetLevel())
                break;
        }
    }
    TopmostLevelCharacters.InsertAt(i, Ptr<InteractiveObject>(pch));
    Ptr<Render::TreeNode> node = pch->SetIndirectTransform(pTopMostRoot);
    if (node)
        pTopMostRoot->Insert(i, node);
}

// The image a linkage id names: a protocol url ("img://...") goes to the image creator state, anything else is
// looked up among the exports of md and of the movies that import from it.
// @0x14256f370
// MS2-FUNCTIONAL: rsi/r14 swapped, the url String temp and its vtable load scheduled differently, one tail not merged
Ptr<ImageResource> MovieImpl::GetImageResourceByLinkageId(MovieDefImpl* md, const char* linkageId)
{
    Ptr<ImageResource> pimageRes;
    if (!md)
        return pimageRes;
    if (LoaderImpl::IsProtocolImage(String(linkageId)))
    {
        StateBag* pstates = pStateBag;
        MemoryHeap* pheap = pHeap;
        ImageCreator* pcreator =
            (ImageCreator*)Ptr<State>(*pstates->GetStateAddRef(State::State_ImageCreator)).GetPtr();
        if (!pcreator)
            return NULL;
        ImageCreateInfo cinfo(ImageCreateInfo::Create_ProtocolImage, pheap, Render::ImageUse_Wrap,
                              Resource::Use_Bitmap);
        cinfo.SetStates(pstates->GetLog(), Ptr<State>(*pstates->GetStateAddRef(State::State_FileOpener)),
                        (ImageFileHandlerRegistry*)Ptr<State>(
                            *pstates->GetStateAddRef(State::State_ImageFileHandlerRegistry)).GetPtr());
        cinfo.pMovie = this;
        Ptr<Render::Image> pimage = *pcreator->LoadProtocolImage(cinfo, String(linkageId));
        if (!pimage)
            return NULL;
        pimageRes = *SF_HEAP_NEW(pheap) ImageResource(pimage, Resource::Use_Bitmap);
    }
    else
    {
        ResourceBindData resBindData;
        if (!FindExportedResource(md, &resBindData, linkageId))
            return NULL;
        if (resBindData.pResource->GetResourceType() == Resource::RT_Image)
            pimageRes = static_cast<ImageResource*>(resBindData.pResource.GetPtr());
    }
    return pimageRes;
}

// The camera of the 3D stage (inlined into MakeViewAndPersp3D): eye looks at at with up roughly up; left-handed (z
// points from the eye to at) when the y axis is inverted, right-handed (z points back at the eye) otherwise.
static __forceinline void MakeView3D(Render::Matrix3F* m, const Render::Point3F& eye, const Render::Point3F& at,
                              const Render::Point3F& up, bool leftHanded)
{
    float zx, zy, zz;
    if (leftHanded)
    {
        zx = at.x - eye.x;
        zy = at.y - eye.y;
        zz = at.z - eye.z;
    }
    else
    {
        zx = eye.x - at.x;
        zy = eye.y - at.y;
        zz = eye.z - at.z;
    }
    float zlen = (float)sqrt(zx * zx + zy * zy + zz * zz);
    zx /= zlen;
    zy /= zlen;
    zz /= zlen;

    // x = up cross z, unit length; y = z cross x
    float xx = up.y * zz - up.z * zy;
    float xy = up.z * zx - up.x * zz;
    float xz = up.x * zy - up.y * zx;
    float xlen = (float)sqrt(xx * xx + xy * xy + xz * xz);
    xx /= xlen;
    xy /= xlen;
    xz /= xlen;
    float yx = zy * xz - zz * xy;
    float yy = zz * xx - zx * xz;
    float yz = zx * xy - zy * xx;

    m->M[0][0] = xx;
    m->M[0][1] = xy;
    m->M[0][2] = xz;
    m->M[0][3] = -(xx * eye.x + xy * eye.y + xz * eye.z);
    m->M[1][0] = yx;
    m->M[1][1] = yy;
    m->M[1][2] = yz;
    m->M[1][3] = -(yx * eye.x + yy * eye.y + yz * eye.z);
    m->M[2][0] = zx;
    m->M[2][1] = zy;
    m->M[2][2] = zz;
    m->M[2][3] = -(zx * eye.x + zy * eye.y + zz * eye.z);
}

// Sets up the view and the projection of a 3D stage. The eye is on the axis through projCenter, focalLength twips
// in front of the stage; with no focal length it is as far as the frame's width needs to fill fieldOfView (degrees).
// A field of view that is not positive gives a parallel projection. Near plane 1, far plane 100000 twips.
// @0x1425718d0
// MS2-FUNCTIONAL
void MovieImpl::MakeViewAndPersp3D(Render::Matrix3F* matView, Render::Matrix4F* matPersp,
                                   const Render::RectF& vfrTwips, const Render::PointF& projCenter,
                                   float fieldOfView, float focalLength, bool invertY)
{
    const float nearZ = 1.f;
    const float farZ  = 100000.f;

    // The frame's edges around the projection center.
    float left   = -(projCenter.x - vfrTwips.x1);
    float right  = vfrTwips.x2 - projCenter.x;
    float bottom = -(vfrTwips.y2 - projCenter.y);
    float top    = projCenter.y - vfrTwips.y1;

    float eyeZ = float(fabs(double(vfrTwips.x2 - vfrTwips.x1))) * 0.5f;
    if (focalLength != 0)
        eyeZ = focalLength;
    else if (fieldOfView > 0)
        eyeZ /= tanf(float(fieldOfView * 3.141592653589793 / 180.0) * 0.5f);

    if (matView)
    {
        Render::Point3F eye(projCenter.x, projCenter.y, Alg::Max(-farZ, -eyeZ));
        Render::Point3F at(projCenter.x, projCenter.y, 0);
        Render::Point3F up(0, invertY ? 1.f : -1.f, 0);
        MakeView3D(matView, eye, at, up, invertY);
    }

    if (matPersp)
    {
        matPersp->Clear();
        if (fieldOfView <= 0)
        {
            // parallel: the frame maps onto the unit square
            matPersp->M[0][0] = 2.f / (right - left);
            matPersp->M[1][1] = 2.f / (top - bottom);
            matPersp->M[0][3] = (left + right) / (left - right);
            matPersp->M[1][3] = (top + bottom) / (bottom - top);
            matPersp->M[2][2] = invertY ? 1.f / (farZ - nearZ) : 1.f / (nearZ - farZ);
            matPersp->M[2][3] = nearZ / (nearZ - farZ);
            matPersp->M[3][3] = 1.f;
        }
        else
        {
            matPersp->M[0][0] = 2.f * eyeZ / (right - left);
            matPersp->M[1][1] = 2.f * eyeZ / (top - bottom);
            if (invertY)
            {
                matPersp->M[0][2] = (left + right) / (left - right);
                matPersp->M[1][2] = (top + bottom) / (bottom - top);
                matPersp->M[2][2] = farZ / (farZ - nearZ);
                matPersp->M[3][2] = 1.f;
            }
            else
            {
                matPersp->M[0][2] = (left + right) / (right - left);
                matPersp->M[1][2] = (top + bottom) / (top - bottom);
                matPersp->M[2][2] = farZ / (nearZ - farZ);
                matPersp->M[3][2] = -1.f;
            }
            matPersp->M[2][3] = nearZ * farZ / (nearZ - farZ);
        }
    }
}

// @0x14256e3f0
DrawingContext* MovieImpl::CreateDrawingContext()
{
    // The image creator state (ImageCreator is a State at offset 0; incomplete here).
    DrawingContext* dc = new (pHeap) DrawingContext(pHeap, RenderContext,
        (ImageCreator*)Ptr<State>(*GetStateBag()->GetStateAddRef(State::State_ImageCreator)).GetPtr());
    DrawingContextList.PushBack(dc);
    return dc;
}

// Unhooks the render tree, the IME and the timers, stops the loads and lets the AVM root shut down before the
// members go.
// The movie's own states (StateBag override; the bag the Get/SetState forwarders go to).
// @0x14256fb90
StateBag* MovieImpl::GetStateBagImpl() const
{
    return pStateBag;
}

// @0x14256ace0
// MS2-FUNCTIONAL: cl inlines the ArrayData Resize/dtor COMDATs the exe calls out of line; Flags update scheduled later
MovieImpl::~MovieImpl()
{
    if (FocusRectContainerNode)
    {
        FocusRectContainerNode->Remove(0, FocusRectContainerNode->GetSize());
        for (unsigned i = 0; i < FocusGroupsCnt; ++i)
            FocusGroups[i].FocusRectNode = NULL;
        FocusRectContainerNode = NULL;
    }

    // ClearDrawingContextList
    DrawingContext* pdc = DrawingContextList.GetFirst();
    while (!DrawingContextList.IsNull(pdc))
    {
        DrawingContext* pnext = DrawingContextList.GetNext(pdc);
        pdc->pPrev = pdc->pNext = NULL;
        pdc = pnext;
    }
    DrawingContextList.Clear();

    ProcessUnloadQueue();
    pRenderRoot = NULL;

    Ptr<IMEManagerBase> pIMEManager = GetIMEManager();
    if (pIMEManager && pIMEManager->IsMovieActive(this))
        pIMEManager->ClearActiveMovie();
    SF_FREE(pIMECandidateListStyle);

    pFontManagerStates = NULL;

    // ShutdownTimers
    UPInt n = IntervalTimers.GetSize();
    for (UPInt i = 0; i < n; ++i)
        IntervalTimers[i]->Clear();
    IntervalTimers.Clear();

    VideoProviders.Clear();

    if (pMainMovie)
        pMainMovie->StopActiveSounds();

    Flags |= Flag_OptAdvListInvalid;   // InvalidateOptAdvanceList
    AsRootSlots(pASMovieRoot)->ClearDisplayList();
    ClearIndirectTransformPairs();

    // ClearStickyVariables
    for (ASStringHash<StickyVarNode*>::Iterator it = StickyVariables.Begin(); it != StickyVariables.End(); ++it)
    {
        StickyVarNode* pnode = it->Second;
        while (pnode)
        {
            StickyVarNode* p = pnode;
            pnode = pnode->pNext;
            delete p;
        }
    }
    StickyVariables.Clear();

    delete pRetValHolder;

    // Cancel the loader-thread requests and wait until every one of them is done.
    LoadQueueEntryMT* plq = pLoadQueueMTHead;
    unsigned plqCount = 0;
    while (plq)
    {
        plqCount++;
        plq->Cancel();
        plq = plq->pNext;
    }
    if (plqCount)
    {
        unsigned plqDoneCount;
        do
        {
            plqDoneCount = 0;
            for (plq = pLoadQueueMTHead; plq; plq = plq->pNext)
            {
                if (plq->LoadFinished())
                    plqDoneCount++;
            }
        } while (plqCount > plqDoneCount);
    }

    while (pLoadQueueHead)
    {
        LoadQueueEntry* pentry = pLoadQueueHead;
        pLoadQueueHead = pentry->pNext;
        delete pentry;
    }
    while (pLoadQueueMTHead)
    {
        LoadQueueEntryMT* pentry = pLoadQueueMTHead;
        pLoadQueueMTHead = pentry->pNext;
        delete pentry;
    }

    TopmostLevelCharacters.Clear();
    delete (Value::ObjectInterface*)pObjectInterface;

    AsRootSlots(pASMovieRoot)->Shutdown();
    pASMovieRoot = NULL;
    pTopMostRoot = NULL;
    RenderContext.Shutdown(true);
    hDisplayRoot.Clear();
}

}} // namespace Scaleform::GFx

// The player TU emits the scalar deleting dtor of this refcount base (exe vftable 0x143183600).
template class Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl, 0x143>;

// MS2-FUNCTIONAL ?GetMouseState@MovieImpl@GFx@Scaleform@@UEAAXIPEAM0PEAI@Z: the exe computes both coordinates up front (no common 0.05 constant); this build sinks x into its branch
// MS2-FUNCTIONAL ?Release@Movie@GFx@Scaleform@@QEAAXXZ: register allocation (the exe keeps this in rdi, this build in rbx)
// MS2-FUNCTIONAL ?HitTest@MovieImpl@GFx@Scaleform@@UEAA_NMMW4HitTestType@Movie@23@I@Z: scheduling of the inlined SetNormalizedScreenCoords (same as sfr_gfx_06 GetMouseX)
// MS2-FUNCTIONAL ?TranslateToScreen@MovieImpl@GFx@Scaleform@@UEAA?AV?$Point@M@Render@3@AEBV453@PEAV?$Matrix2x4@M@53@@Z: xmm register allocation of the inlined Prepend pair (same operations)
// MS2-FUNCTIONAL ?TranslateToScreen@MovieImpl@GFx@Scaleform@@UEAA?AV?$Rect@M@Render@3@AEBV453@PEAV?$Matrix2x4@M@53@@Z: xmm register allocation of the inlined Prepend pair (same operations)
// MS2-FUNCTIONAL ?InitCenterDelta@DragState@MovieImpl@GFx@Scaleform@@QEAAX_N@Z: the two matrices' stack slots are swapped and the mouse point's halves load in the other order; same operations
// MS2-FUNCTIONAL ?SetKeyboardFocusTo@MovieImpl@GFx@Scaleform@@QEAAXPEAVInteractiveObject@23@IW4FocusMovedType@23@@Z: the exe keeps 0 in a callee-saved register (one more saved register, 0x50 frame); same operations
// MS2-FUNCTIONAL ?ReadTextData@MovieImpl@GFx@Scaleform@@SA_NPEAVString@3@PEAVFile@3@PEAH_N@Z: the exe tests the BOM high byte in the other register and keeps rbp in a different home slot; same operations
// MS2-FUNCTIONAL ?CreateImageMovieDef@MovieImpl@GFx@Scaleform@@QEAAPEAVMovieDefImpl@23@PEAVImageResource@23@_NPEBDPEAVLoadStates@23@@Z: the image resource and the load states sit in swapped callee-saved registers; same operations
// MS2-FUNCTIONAL ?ProcessInput@MovieImpl@GFx@Scaleform@@QEAAXXZ: the exe gives the mouse position the stack slot of the spent mice mask; same operations
// MS2-FUNCTIONAL ?HandleEvent@MovieImpl@GFx@Scaleform@@UEAAIAEBVEvent@23@@Z: the SetFocus loop walks the keyboard states with a stepped pointer and picks NULL past 4 with a cmov (0 kept in r15: one more saved register, 0x48 frame); this build indexes and branches; same calls
// MS2-PIN: ??1?$HashSetBase@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@@2@V32@U?$AllocatorGH@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@$01@2@V?$HashsetCachedEntry@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@@2@@2@@Scaleform@@QEAA@XZ 0x14256aa60
// MS2-PIN: ?Reserve@?$ArrayDataBase@UMDKillListEntry@MovieImpl@GFx@Scaleform@@U?$AllocatorGH@UMDKillListEntry@MovieImpl@GFx@Scaleform@@$0BEH@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142574640
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$Ptr@VASIntervalTimerIntf@GFx@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@VASIntervalTimerIntf@GFx@Scaleform@@@Scaleform@@$0BEH@@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1425746e0
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@UMDKillListEntry@MovieImpl@GFx@Scaleform@@U?$AllocatorGH@UMDKillListEntry@MovieImpl@GFx@Scaleform@@$0BEH@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x1425752c0
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@V?$Ptr@VASIntervalTimerIntf@GFx@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@VASIntervalTimerIntf@GFx@Scaleform@@@Scaleform@@$0BEH@@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x142575370
// MS2-PIN: ??$add@PEAVVideoProvider@Video@GFx@Scaleform@@@?$HashSetBase@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@@2@V32@U?$AllocatorGH@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@$01@2@V?$HashsetCachedEntry@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@@2@@2@@Scaleform@@AEAAXPEAXAEBQEAVVideoProvider@Video@GFx@1@_K@Z 0x142569870
// MS2-PIN: ??$add@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@@?$HashSetBase@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@@2@V32@U?$AllocatorGH@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@$01@2@V?$HashsetCachedEntry@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@@2@@2@@Scaleform@@AEAAXPEAXAEBV?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@1@_K@Z 0x142569c00
// MS2-PIN: ?CheckExpand@?$HashSetBase@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@@2@V32@U?$AllocatorGH@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@$01@2@V?$HashsetCachedEntry@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@@2@@2@@Scaleform@@QEAAXPEAX@Z 0x14256dc50
// MS2-PIN: ?Clear@?$HashSetBase@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@@2@V32@U?$AllocatorGH@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@$01@2@V?$HashsetCachedEntry@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@@2@@2@@Scaleform@@QEAAXXZ 0x14256df40
// MS2-PIN: ?setRawCapacity@?$HashSetBase@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@@2@V32@U?$AllocatorGH@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@$01@2@V?$HashsetCachedEntry@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@@2@@2@@Scaleform@@AEAAXPEAX_K@Z 0x142579060
// MS2-PIN: ??_7InitStruct@String@Scaleform@@6B@ 0x14313f358
// MS2-PIN: ??$RemoveAlt@PEAVVideoProvider@Video@GFx@Scaleform@@@?$HashSetBase@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@@2@V32@U?$AllocatorGH@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@$01@2@V?$HashsetCachedEntry@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@@2@@2@@Scaleform@@QEAAXAEBQEAVVideoProvider@Video@GFx@1@@Z 0x1425696b0
// MS2-PIN: ??_GStateBag@GFx@Scaleform@@UEAAPEAXI@Z 0x14256baf0
// MS2-PIN: ??_7StateBag@GFx@Scaleform@@6B@ 0x143183208
// MS2-PIN: ??_7Movie@GFx@Scaleform@@6B?$RefCountBase@VMovie@GFx@Scaleform@@$0BEH@@2@@ 0x143183378
// MS2-PIN: ??_7Movie@GFx@Scaleform@@6BStateBag@12@@ 0x143183580
// MS2-PIN: ??0MovieImpl@GFx@Scaleform@@QEAA@PEAVMemoryHeap@2@@Z 0x142569e20
// MS2-PIN: ??_7?$RefCountBase@VMovie@GFx@Scaleform@@$0BEH@@Scaleform@@6B@ 0x143183370
// MS2-PIN: ??_G?$RefCountBase@VMovie@GFx@Scaleform@@$0BEH@@Scaleform@@UEAAPEAXI@Z 0x14256b6e0
// MS2-PIN: ??_G?$RefCountBase@VStateBagImpl@GFx@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x14256b740
// MS2-PIN: ??_7?$LogBase@VStateBagImpl@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431835b0
// MS2-PIN: ??_7StateBagImpl@GFx@Scaleform@@6B?$RefCountBase@VStateBagImpl@GFx@Scaleform@@$01@2@@ 0x1431835c0
// MS2-PIN: ??_7StateBagImpl@GFx@Scaleform@@6BStateBag@12@@ 0x1431835c8
// MS2-PIN: ??_7StateBagImpl@GFx@Scaleform@@6B?$LogBase@VStateBagImpl@GFx@Scaleform@@@12@@ 0x1431835f0
// MS2-PIN: ??_7?$RefCountBaseNTS@VFontManagerStates@GFx@Scaleform@@$01@Scaleform@@6B@ 0x143183608
// MS2-PIN: ??_7FontManagerStates@GFx@Scaleform@@6B?$RefCountBaseNTS@VFontManagerStates@GFx@Scaleform@@$01@2@@ 0x143183610
// MS2-PIN: ??_7FontManagerStates@GFx@Scaleform@@6BStateBag@12@@ 0x143183618
// MS2-PIN: ??_7MovieImpl@GFx@Scaleform@@6B?$RefCountBase@VMovie@GFx@Scaleform@@$0BEH@@2@@ 0x143183640
// MS2-PIN: ??_7MovieImpl@GFx@Scaleform@@6BStateBag@12@@ 0x143183860
// MS2-PIN: ?GetStateBagImpl@FontManagerStates@GFx@Scaleform@@UEBAPEAVStateBag@23@XZ 0x14256fb80
// MS2-PIN: ?Reserve@?$ArrayDataBase@UIndirectTransPair@MovieImpl@GFx@Scaleform@@U?$AllocatorLH@UIndirectTransPair@MovieImpl@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x1425745a0
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@UIndirectTransPair@MovieImpl@GFx@Scaleform@@U?$AllocatorLH@UIndirectTransPair@MovieImpl@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142575220
// MS2-PIN: ?ResetTabableArray@FocusGroupDescr@GFx@Scaleform@@QEAAXXZ 0x142574ce0
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@V?$Ptr@VASIntervalTimerIntf@GFx@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@VASIntervalTimerIntf@GFx@Scaleform@@@Scaleform@@$0BEH@@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x142575370
// MS2-PIN: ??_7?$RefCountBase@VStateBagImpl@GFx@Scaleform@@$01@Scaleform@@6B@ 0x1431835a8
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BEH@@Scaleform@@6B@ 0x1431937a8
// MS2-PIN: ?Reserve@?$ArrayDataBase@PEAVVideoProvider@Video@GFx@Scaleform@@U?$AllocatorGH@PEAVVideoProvider@Video@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142574460
// MS2-PIN: ??_7RefCountVImpl@Scaleform@@6B@ 0x1431496d0
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
// MS2-PIN: ??_7?$RefCountBase@VShapeDataInterface@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318f130
// MS2-PIN: ??_7ShapeDataInterface@Render@Scaleform@@6B@ 0x14317b678
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountVImpl@Scaleform@@$02@Scaleform@@6B@ 0x1431498a0
// MS2-PIN: ??_7?$RefCountBaseV@VImage@Render@Scaleform@@$02@Scaleform@@6B@ 0x1431498b8
// MS2-PIN: ??_7ImageBase@Render@Scaleform@@6B@ 0x1431498d0
// MS2-PIN: ??_7Image@Render@Scaleform@@6B@ 0x143149940
// MS2-PIN: ??_7ImageDelegate@Render@Scaleform@@6B@ 0x143149a28
// MS2-PIN: ??_7ImageDelegate@ImageResource@GFx@Scaleform@@6B@ 0x143149b10
// MS2-PIN: ??_7ImageResource@GFx@Scaleform@@6B@ 0x143149bf8
// MS2-PIN: ??_7?$ShapeDataFloatTempl@V?$Array@E$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@@Render@Scaleform@@6B@ 0x14317bb40
// MS2-PIN: ??_7ShapeDataFloat@Render@Scaleform@@6B@ 0x14317bb98
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0BED@@Scaleform@@6B@ 0x143183600
