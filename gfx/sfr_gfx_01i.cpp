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
// MS2-RANGE: 0x14256fd60-0x142576530 .text$mn
// MS2-RANGE: 0x142576750-0x142578f10 .text$mn
// MS2-RANGE: 0x142579060-0x142579270 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#define SF_GFX_PLAYERIMPL
#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_log.h"
#include "../include/gfx/gfx_keyboardstate.h"
#include "../include/gfx/gfx_input.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_playertasks.h"
#include "../include/gfx/gfx_drawingcontext.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/render/render_color.h"

namespace Scaleform { namespace GFx {

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
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void ForceCollect() = 0;                                                            // 9
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual DisplayObjectBase* GetRootMovie(DisplayObjectBase* dobj = 0) const = 0;            // 14
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void PrintObjectsReport(UInt32 flags, Log* log, const char* swfName) = 0;          // 25
    virtual void Slot26() = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual void Slot30() = 0;
    virtual void SetExternalInterfaceRetVal(const Value& retVal) = 0;                           // 31
    virtual void Slot32() = 0;
    virtual void Slot33() = 0;
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
    virtual void Slot50() = 0;
    virtual Render::Text::Allocator* GetTextAllocator() = 0;                                    // 51
};

static inline ASMovieRootSlots418* AsRootSlots(ASMovieRootBase* proot)
{
    return reinterpret_cast<ASMovieRootSlots418*>(proot);
}

namespace AMP {
// The movie's advance statistics (AMP; only the call the player makes).
class ViewStats
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

// One of the four mouse states (0x50 bytes from +0x1260).
struct MouseStateView
{
    UByte          Unrecovered_00[0x30];
    unsigned       Buttons;          // +0x30
    UByte          Unrecovered_34[4];
    Render::PointF LastPosition;     // +0x38 twips
    UByte          Unrecovered_40[0x10];
};

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
    reinterpret_cast<Render::ContextImpl::Context*>(RenderContext)->ForceUpdateImages();
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
                 reinterpret_cast<Render::ContextImpl::Context*>(RenderContext)->HasChanges();
    if (doReset)
        Flags &= ~0x400u;
    return dirty;
}

// @0x14256f210
const Render::ContextImpl::DisplayHandle<Render::TreeRoot>& MovieImpl::GetDisplayHandle() const
{
    return *reinterpret_cast<const Render::ContextImpl::DisplayHandle<Render::TreeRoot>*>(&hDisplayRoot);
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
    const MouseStateView& ms = reinterpret_cast<const MouseStateView*>(MouseState0_1260)[mouseIndex];
    float px = (Render::TwipsToPixels(ms.LastPosition.x) - ViewOffsetX) / ViewScaleX;
    float py = (Render::TwipsToPixels(ms.LastPosition.y) - ViewOffsetY) / ViewScaleY;
    if (x)
        *x = px;
    if (y)
        *y = py;
    if (buttons)
        *buttons = ms.Buttons;
}

// @0x14256f880
unsigned MovieImpl::GetMouseCursorCount() const
{
    return MouseCursorCount;
}

// @0x14256f910
MovieDef* MovieImpl::GetMovieDef() const
{
    return (MovieDef*)pMainMovieDef;
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
    return reinterpret_cast<const Render::ContextImpl::Context*>(RenderContext)->IsShutdownComplete();
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
    pRenderRoot->SetMatrix(*reinterpret_cast<const Render::Matrix2F*>(ViewportMatrix));
}

// @0x142575930
void MovieImpl::SetASMovieRoot(ASMovieRootBase* pasMovieRoot)
{
    Ptr<ASMovieRootBase>& saved = *reinterpret_cast<Ptr<ASMovieRootBase>*>(&pSavedASMovieRoot);
    saved         = pasMovieRoot;
    pASMovieRoot  = saved;
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
    reinterpret_cast<Render::ContextImpl::Context*>(RenderContext)->SetCaptureThreadId(captureThreadId);
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
    reinterpret_cast<Render::ContextImpl::Context*>(RenderContext)->Shutdown(wait);
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
    MouseState* pstates = reinterpret_cast<MouseState*>(MouseState0_1260);
    for (unsigned i = 0; i < 4; ++i)
        pstates[i].ResetState();
}

// @0x142575ec0
void MovieImpl::SetKeyboardListener(KeyboardState::IListener* l)
{
    for (unsigned i = 0; i < 4; ++i)
        reinterpret_cast<KeyboardState*>(KeyboardStates[i])->SetListener(l);
}

// @0x14256ed00
FontManager* MovieImpl::FindFontManager(MovieDefImpl* pdefImpl)
{
    MovieDefRootNode* pnode = RootMovieDefNodes.pNext;
    while (static_cast<MovieDefRootNode*>(&RootMovieDefNodes) != pnode)
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
        *ppath = ((MovieDef*)pMainMovieDef)->GetFileURL();
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
    MouseState& ms = reinterpret_cast<MouseState*>(MouseState0_1260)[mouseIdx];
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
                reinterpret_cast<Render::ContextImpl::Context*>(RenderContext)->GetFinalizedFrameId();
            return;
        }
    }
    MDKillListEntry e;
    e.KillFrameId = reinterpret_cast<Render::ContextImpl::Context*>(RenderContext)->GetFinalizedFrameId();
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

}} // namespace Scaleform::GFx

// MS2-FUNCTIONAL ?GetMouseState@MovieImpl@GFx@Scaleform@@UEAAXIPEAM0PEAI@Z: the exe computes both coordinates up front (no common 0.05 constant); this build sinks x into its branch
// MS2-FUNCTIONAL ?Release@Movie@GFx@Scaleform@@QEAAXXZ: register allocation (the exe keeps this in rdi, this build in rbx)
// MS2-FUNCTIONAL ?FindFontManager@MovieImpl@GFx@Scaleform@@QEAAPEAVFontManager@23@PEAVMovieDefImpl@23@@Z: instruction scheduling of the list root's null-checked downcast (same compares and loads)
// MS2-FUNCTIONAL ?AddIntervalTimer@MovieImpl@GFx@Scaleform@@QEAAHPEAVASIntervalTimerIntf@23@@Z: cl inlines ArrayDataBase::ResizeNoConstruct, the exe calls it out of line
// MS2-FUNCTIONAL ?AddMovieDefToKillList@MovieImpl@GFx@Scaleform@@QEAAXPEAVMovieDefImpl@23@@Z: cl inlines ArrayDataBase::ResizeNoConstruct, the exe calls it out of line
// MS2-PIN: ?Reserve@?$ArrayDataBase@UMDKillListEntry@MovieImpl@GFx@Scaleform@@U?$AllocatorGH@UMDKillListEntry@MovieImpl@GFx@Scaleform@@$0BEH@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142574640
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$Ptr@VASIntervalTimerIntf@GFx@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@VASIntervalTimerIntf@GFx@Scaleform@@@Scaleform@@$0BEH@@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1425746e0
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@UMDKillListEntry@MovieImpl@GFx@Scaleform@@U?$AllocatorGH@UMDKillListEntry@MovieImpl@GFx@Scaleform@@$0BEH@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x1425752c0
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@V?$Ptr@VASIntervalTimerIntf@GFx@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@VASIntervalTimerIntf@GFx@Scaleform@@@Scaleform@@$0BEH@@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x142575370
