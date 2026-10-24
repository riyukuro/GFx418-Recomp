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
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_movieimplstates.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_log.h"
#include "../include/gfx/gfx_keyboardstate.h"
#include "../include/gfx/gfx_input.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_playertasks.h"
#include "../include/gfx/gfx_drawingcontext.h"
#include "../include/gfx/gfx_fontmanager.h"
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
#include "../include/gfx/gfx_asutils.h"
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
static_assert(sizeof(DrawableImageContext) == 0xb8, "DrawableImageContext (GetDrawableImageContext allocates 0xb8)");

}} // namespace Scaleform::Render

namespace Scaleform { namespace GFx {

// The tab order comparers: by tabIndex, or by position (left to right, top to bottom) when no character has one.
// Only the sorts are called here (out of line instantiations, 0x142569200 / 0x1425686b0).
class TabIndexSortFunctor
{
public:
    bool operator()(const InteractiveObject* a, const InteractiveObject* b) const;
};
class AutoTabSortFunctor
{
public:
    bool operator()(const InteractiveObject* a, const InteractiveObject* b) const;
};
// The sorts take the comparers by value from these (the exe loads them from .data).
static TabIndexSortFunctor TabIndexSort;
static AutoTabSortFunctor  AutoTabSort;

}} // namespace Scaleform::GFx

namespace Scaleform { namespace Alg {
template<> void QuickSortSliced(ArrayDH<Ptr<GFx::InteractiveObject>, 0x147>& arr, UPInt start, UPInt end,
                                GFx::TabIndexSortFunctor less);
template<> void QuickSortSliced(ArrayDH<Ptr<GFx::InteractiveObject>, 0x147>& arr, UPInt start, UPInt end,
                                GFx::AutoTabSortFunctor less);
}} // namespace Scaleform::Alg

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

// The AVM root's vftable as the player calls it (ASMovieRootBase carries no virtuals in our headers): 4.1.18 slot
// order, the slots the player does not call left unnamed.
class __declspec(novtable) ASMovieRootSlots418
{
public:
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void ChangeMouseCursorType(unsigned mouseIdx, unsigned newCursorType) = 0;          // 3
    virtual void Slot04() = 0;
    virtual void ClearDisplayList() = 0;                                                       // 5
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void ForceCollect() = 0;                                                            // 9
    virtual void Slot10() = 0;
    virtual void GenerateMouseEvents(unsigned mouseIndex) = 0;                                  // 11
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual DisplayObjectBase* GetRootMovie(DisplayObjectBase* dobj = 0) const = 0;            // 14
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void NotifyOnResize() = 0;                                                         // 17
    virtual void NotifyQueueSetFocus(InteractiveObject* ch, unsigned controllerIdx, FocusMovedType fmt) = 0; // 18
    virtual void NotifyTransferFocus(InteractiveObject* curFocused, InteractiveObject* pnewFocus,
                                     unsigned controllerIdx) = 0;                               // 19
    virtual bool NotifyOnFocusChange(InteractiveObject* curFocused, InteractiveObject* toBeFocused,
                                     unsigned controllerIdx, FocusMovedType fmt,
                                     ProcessFocusKeyInfo* pfocusKeyInfo) = 0;                   // 20
    virtual void OnMovieFocus(bool set) = 0;                                                   // 21
    virtual void Slot22() = 0;
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

// Whether the screen point hits one of the levels; HitTest_ButtonEvents asks for something that takes button events.
// @0x142570a00
bool MovieImpl::HitTest(float x, float y, HitTestType testCond, unsigned controllerIdx)
{
    Render::PointF pt(Render::PointF::NoInit);
    ViewportMatrix.TransformByInverse(&pt, Render::PointF(x, y));

    SetNormalizedScreenCoords(pt);

    for (unsigned movieIndex = (unsigned)MovieLevelsSize; movieIndex > 0; movieIndex--)
    {
        InteractiveObject* pmovie = pMovieLevels[movieIndex - 1].pSprite;

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

    Viewport VP;        // +0xa0
    Color    BGColor;   // +0xcc
};

// @0x14256a710
// MS2-FUNCTIONAL: the node-data vtable store is scheduled after the viewport stores (the exe stores it first)
SF_NOINLINE TreeRoot::NodeData::NodeData() : TreeContainer::NodeData(ET_Root), BGColor(0)
{
    pVTable = TreeRootNodeDataVTable;
}

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
    : pAdvanceStats(0), pHeap(pheap), pMainMovieDef(0), pMovieLevels(0), MovieLevelsSize(0), MovieLevelsCapacity(0),
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

// A SetVariable value waiting for its target: the chain of values set under one path.
struct MovieImpl::StickyVarNode : public NewOverrideBase<0x147>   // StatMV_Other_Mem
{
    ASString       Name;        // +0x08
    StickyVarNode* pNext;       // +0x10
    bool           Permanent;   // +0x18

    virtual ~StickyVarNode() {}
    // The AVM nodes also copy the value (exe 0x1424ed840).
    virtual void Assign(const StickyVarNode& node) { Name = node.Name; Permanent = node.Permanent; }
};

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
            for (int i = (int)MovieLevelsSize; i > 0; --i)
            {
                InteractiveObject* plevel = pMovieLevels[i - 1].pSprite;
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
void MovieImpl::ShutdownTimers()
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
    for (unsigned i = 0; i < MovieLevelsSize; i++)
    {
        if (pMovieLevels[i].pSprite)
            pMovieLevels[i].pSprite->UpdateViewAndPerspective();
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
        for (unsigned movieIndex = (unsigned)MovieLevelsSize; movieIndex > 0; movieIndex--)
            pMovieLevels[movieIndex - 1].pSprite->PropagateKeyEvent(evt, &keyMask);
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
