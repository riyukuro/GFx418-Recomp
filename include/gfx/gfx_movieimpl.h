// Recovered Scaleform 4.1.18 GFx: the movie implementation (MovieImpl), as far as the recovered units call into it.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
// By default MovieImpl is a plain layout mirror: the Movie base (RefCountBase + StateBag + pASMovieRoot,
// gfx_player.h) is kept as placeholder words, so units with a local class Movie of their own can include this.
// A unit that defines SF_GFX_PLAYERIMPL before including it gets the real polymorphic MovieImpl : Movie (the
// player units, sfr_gfx_01i on); the layout is the same either way (0x3650 bytes).
#ifndef MS2_SF_GFX_MOVIEIMPL_H
#define MS2_SF_GFX_MOVIEIMPL_H

#include "../kernel/sf_refcount.h"
#include "../render/render_types2d.h"
#include "../render/render_twips.h"
#include "../kernel/sf_string.h"
#include "../kernel/sf_array.h"
#ifdef SF_GFX_PLAYERIMPL
#include "gfx_player.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "gfx_keyboardstate.h"
#include "../kernel/sf_hash.h"
#endif

namespace Scaleform {
class File;
namespace GFx {

class ASMovieRootBase;
namespace Video { class VideoProvider; }
class DisplayObjectBase;
class InteractiveObject;
class Sprite;
class DrawingContext;
class DisplayObjContainer;
class MovieDefImpl;
class ImageResource;
class LoadStates;
class FontManager;
class ASString;
struct ASStringNode;
}
class MemoryHeap;
class Log;
namespace Render { class TreeNode; template<class T> class Matrix3x4; template<class T> class Matrix4x4; class ScreenToWorld;
                   namespace Text { class Allocator; } }
namespace GFx {
class StateBag;
class ASIntervalTimerIntf;
class FontManagerStates;
class MovieDefRootNode;
class FontResource;
class MovieDef;
class StateBagImpl;
class Movie;
class LoadQueueEntry;
class LoadQueueEntryMT;
class UserEventHandler;
class ExternalInterface;
class KeyboardState;
class LogState;
class IMEManagerBase;
class IMECandidateListStyle;
class CharacterHandle;
class MovieImpl;

// (sfr_gfx_06d) the links of the movie's list of root nodes (List<MovieDefRootNode>): the list root's pNext is the
// first node, and the root itself passes for a node one base offset before it.
struct MovieDefRootNodeLinks
{
    MovieDefRootNode* pPrev;
    MovieDefRootNode* pNext;
};

// (also in gfx_interactiveobject.h)
#ifndef SF_GFX_FOCUSMOVEDTYPE
#define SF_GFX_FOCUSMOVEDTYPE
// How the focus got moved.
enum FocusMovedType
{
    GFx_FocusMovedByMouse    = 1,
    GFx_FocusMovedByKeyboard = 2,
    GFx_FocusMovedByAS       = 3
};
#endif

// Keyboard focus state of one focus group (one per controller group; 0x60 bytes, 16-aligned).
struct FocusGroupDescr
{
    UByte   Unrecovered_00[0x28];      // +0x00 focus rect node, tabable array
    mutable WeakPtr<InteractiveObject> LastFocused;   // +0x28 the focused character
    Ptr<CharacterHandle> ModalClip;    // +0x30 the clip the focus is kept within
    UInt32  LastFocusKeyCode;          // +0x38
    UByte   Unrecovered_3c[4];
    UByte   Unrecovered_40[0x10];      // +0x40 last focused rect
    bool    FocusRectShown;            // +0x50 the focus rectangle is up (focus moved by keyboard)
    UByte   Unrecovered_51[0xf];

    // The modal clip, if it is still alive (exe 0x14256f7e0).
    Sprite* GetModalClip(MovieImpl* proot);
};
static_assert(sizeof(FocusGroupDescr) == 0x60, "FocusGroupDescr size");
static_assert(offsetof(FocusGroupDescr, FocusRectShown) == 0x50, "FocusGroupDescr::FocusRectShown");

class MovieImpl
#ifdef SF_GFX_PLAYERIMPL
    : public Movie
#endif
{
public:
#ifndef SF_GFX_PLAYERIMPL
    void*            MovieBase_Unrecovered[3]; // +0x00 RefCountBase vftable + count, StateBag vftable
    ASMovieRootBase* pASMovieRoot;             // +0x18 Ptr<ASMovieRootBase>: the AVM specific root
#endif
    LoadQueueEntry*  pLoadQueueHead;           // +0x20 the load requests processed on the next advance
    UInt32           LastLoadQueueEntryCnt;    // +0x28
    void*            pAdvanceStats;            // +0x30 Ptr<AMP::ViewStats> (GetStats)
    void*            pObjectInterface;         // +0x38 Value::ObjectInterface*: how host values reach the VM objects
    MemoryHeap*      pHeap;                    // +0x40 the movie's heap
    MovieDefImpl*    pMainMovieDef;            // +0x48 Ptr<MovieDefImpl>: the _level0 movie (sfr_gfx_07f)
    InteractiveObject* pMainMovie;             // +0x50 _level0
    struct LevelInfo { int Level; InteractiveObject* pSprite; };   // (sfr_gfx_06)
    LevelInfo*       pMovieLevels;             // +0x58 MovieLevels (ArrayLH data): _level0 first (sfr_gfx_06)
    UPInt            MovieLevelsSize;          // +0x60 MovieLevels size
    UPInt            MovieLevelsCapacity;      // +0x68
    MovieDefRootNodeLinks RootMovieDefNodes;   // +0x70 the root nodes of the loaded movies (sfr_gfx_06d)
    StateBagImpl*    pStateBag;                // +0x80 Ptr<StateBagImpl>: the movie's own states (sfr_video_01)
    Render::TreeNode* pRenderRoot;             // +0x88 Ptr<TreeRoot> (sfr_gfx_06)
    void*            hDisplayRoot;             // +0x90 DisplayHandle<TreeRoot> (GetDisplayHandle)
    Render::TreeNode* pTopMostRoot;            // +0x98 Ptr<TreeContainer> (sfr_gfx_06)
#ifdef SF_GFX_PLAYERIMPL
    Viewport         mViewport;                // +0xa0 (0x34 bytes)
#else
    int              ViewportUnrecovered_a0[4]; // +0xa0 mViewport: buffer size, left/top
    int              ViewportWidth;            // +0xb0 mViewport.Width, pixels (sfr_gfx_06)
    int              ViewportHeight;           // +0xb4 mViewport.Height
    int              ViewportScissor[4];       // +0xb8 mViewport scissor rect
    unsigned         ViewportFlags;            // +0xc8 mViewport.Flags
    float            ViewportScale;            // +0xcc mViewport.Scale
    float            ViewportAspectRatio;      // +0xd0 mViewport.AspectRatio
#endif
    float            PixelScale;               // +0xd4
    float            ViewScaleX, ViewScaleY;   // +0xd8 stage twips per window pixel (sfr_gfx_06)
    float            ViewOffsetX, ViewOffsetY; // +0xe0 viewport offset in pixels (sfr_gfx_06)
    int              ViewScaleMode;            // +0xe8 Movie::ScaleModeType
    int              ViewAlignment;            // +0xec Movie::AlignType
    Render::RectF    VisibleFrameRect;         // +0xf0 the visible stage, twips
    Render::RectF    SafeRect;                 // +0x100 the title-safe rect, twips
    float            ViewportMatrix[2][4];     // +0x110 Matrix2F: stage twips -> viewport pixels
    float            ScreenToWorldSx;          // +0x130 ScreenToWorld: the normalized mouse position (y up)
    float            ScreenToWorldSy;          // +0x134
    void*            ScreenToWorldRest[0x1d];  // +0x138 the rest of Render::ScreenToWorld
#ifdef SF_GFX_PLAYERIMPL
    HashSet<Ptr<Video::VideoProvider> > VideoProviders; // +0x220 the playing videos (paused with the movie)
#else
    void*            VideoProviders;           // +0x220 HashSet<Ptr<Video::VideoProvider>>
#endif
    Ptr<Log>         pCachedLog;               // +0x228 the log state's log, cached (sfr_gfx_06)
    UserEventHandler* pUserEventHandler;       // +0x230 Ptr<UserEventHandler>: cached during advance (sfr12)
    void*            pFSCommandHandler;        // +0x238 Ptr<FSCommandHandler>
    ExternalInterface* pExtIntfHandler;        // +0x240 Ptr<ExternalInterface>: the host's ExternalInterface.call hook
    FontManagerStates* pFontManagerStates;     // +0x248 Ptr: the font states the movies' font managers share (sfr_gfx_06d)
    void*            pAudio;                   // +0x250 AudioBase*
    void*            pSoundRenderer;           // +0x258
    void*            pXMLObjectManager;        // +0x260
    UInt64           TimeElapsed;              // +0x268
    float            TimeRemainder;            // +0x270
    float            FrameTime;                // +0x274 seconds per frame (sfr_video_01 SetSwfSync)
    unsigned         ForceFrameCatchUp;        // +0x278
    void*            InputEventsQueue[0xfd8 / 8]; // +0x280 InputEventsQueue
    UInt32           BackgroundColor;          // +0x1258 Render::Color (alpha in the top byte)
    void*            MouseState0_1260[7];      // +0x1260 mMouseState[4], 0x50 bytes each: buttons at +0x30
    Render::PointF   MouseLastPosition;        // +0x1298 MouseState[0] last position, twips (sfr_gfx_06)
    UByte            MouseStatesRest[0x100];   // +0x12a0 the rest of mMouseState
    unsigned         MouseCursorCount;         // +0x13a0 the mice in use (up to 4)
    unsigned         ControllerCount;          // +0x13a4
    void*            UserData;                 // +0x13a8 the host's
    UByte            KeyboardStates[4][0x688]; // +0x13b0 KeyboardState[4] (gfx_keyboardstate.h), one per keyboard
    void*            pRetValHolder;            // +0x2dd0
    unsigned         InstanceNameCount;        // +0x2dd8 the instanceN names handed out
    // A character the timeline keeps advancing even when stopped (MS2 build; Sprite::CheckAdvanceStatus).
    DisplayObjectBase* pKeepAdvancingChar;     // +0x2de0 CurrentDragState (0x28 bytes, DragState below)
    UByte            CurrentDragStateRest[0x20]; // +0x2de8
    void*            StickyVariables;          // +0x2e08 ASStringHash<StickyVarNode*>
    void*            TopmostLevelCharacters[3]; // +0x2e10 ArrayLH<Ptr<InteractiveObject>>
    UInt64           StartTickMs;              // +0x2e28
    UInt64           PauseTickMs;              // +0x2e30
#ifdef SF_GFX_PLAYERIMPL
    ArrayLH<Ptr<ASIntervalTimerIntf>, 0x147> IntervalTimers; // +0x2e38 (StatMV_Other_Mem)
#else
    void*            IntervalTimers[3];        // +0x2e38 ArrayLH<Ptr<ASIntervalTimerIntf>>
#endif
    int              LastIntervalTimerId;      // +0x2e50
    void*            FocusRectContainerNode;   // +0x2e58 Ptr<TreeContainer>

    typedef GFx::FocusGroupDescr FocusGroupDescr;
    FocusGroupDescr  FocusGroups[16];          // +0x2e60
    unsigned         FocusGroupsCnt;           // +0x3460 the focus groups in use (Selection.numFocusGroups)
    UByte            FocusGroupIndexes[16];    // +0x3464 controller index -> focus group
    bool             FocusRectChanged;         // +0x3474
    InteractiveObject* pPlayList;              // +0x3478 pPlayListHead: the advance list, last added first (sfr_gfx_06b)
    InteractiveObject* pPlayListOptHead;       // +0x3480 the optimized advance list (sfr_gfx_06b)
    InteractiveObject* pUnloadListHead;        // +0x3488
    UInt32           Flags;                    // +0x3490

    enum FlagsType
    {
        Flag_NoInvisibleAdvance = 0x800,       // _global.noInvisibleAdvance: hidden clips stop advancing
        Flag_SetCursorTypeFuncOverloaded = 0x1000, // (appended, sfr_as2_07) Mouse.setCursorType replaced by a script
        Flag_ContinueAnimation  = 0x2000,      // _global.gfxExtensions continueAnimation (sfr_gfx_06)
        Shift_AlwaysEnableKeyboardPress = 26,  // two bits: 0 undefined, 1 true, 2 false, 3 read as -1
        Shift_DisableFocusRolloverEvent = 28,  // two bits, the same encoding
        // (appended, sfr_as2_05) the other Selection extension properties, same encoding
        Shift_DisableFocusAutoRelease   = 22,
        Shift_AlwaysEnableArrowKeys     = 24,
        Shift_DisableFocusKeys          = 30
    };
    bool IsNoInvisibleAdvanceFlagSet() const { return (Flags & Flag_NoInvisibleAdvance) != 0; }
    // _focusrect rollover events suppressed (disableFocusRolloverEvent extension property).
    bool IsDisableFocusRolloverEvent() const
    {
        int v = (Flags >> Shift_DisableFocusRolloverEvent) & 3;
        if (v == 3)
            v = -1;
        return v == 1;
    }
    // Enter/Space press a focused clip that is not a button (alwaysEnableKeyboardPress extension property).
    bool IsAlwaysEnableKeyboardPress() const
    {
        int v = (Flags >> Shift_AlwaysEnableKeyboardPress) & 3;
        if (v == 3)
            v = -1;
        return v == 1;
    }
    // Defined where InteractiveObject is complete (sfr_gfx_05b).
    inline bool IsFocused(const InteractiveObject* ch, unsigned controllerIdx) const;
    bool IsKeyboardFocused(const InteractiveObject* ch, unsigned controllerIdx) const;
    bool IsFocusRectShown(unsigned controllerIdx) const
    {
        return FocusGroups[FocusGroupIndexes[controllerIdx]].FocusRectShown;
    }

    // Removes the setInterval/setTimeout timer with the given id (exe 0x14256e0d0).
    void ClearIntervalTimer(int id);
    // Registers a started setInterval/setTimeout/Timer timer and returns its id (exe 0x14256bd60).
    int AddIntervalTimer(ASIntervalTimerIntf* timer);

    // (appended for the display objects, sfr_gfx_06)
    UInt32           Flags2;                   // +0x3494 (sfr_gfx_06b)
    IMECandidateListStyle* pIMECandidateListStyle; // +0x3498
    LoadQueueEntryMT* pLoadQueueMTHead;        // +0x34a0 the loader-thread entries, newest first (sfr19)
    void*            RegisteredFonts[3];       // +0x34a8 ArrayLH<FontDesc>
#ifdef SF_GFX_PLAYERIMPL
    List<DrawingContext> DrawingContextList;   // +0x34c0
    // A movie def kept alive until the render thread finished the frame it was let go in.
    struct MDKillListEntry
    {
        UInt64            KillFrameId;
        Ptr<MovieDefImpl> pMovieDef;
    };
    Array<MDKillListEntry, 0x147> MovieDefKillList;   // +0x34d0 (StatMV_Other_Mem)
#else
    void*            DrawingContextList[2];    // +0x34c0 List<DrawingContext>
    void*            MovieDefKillList[3];      // +0x34d0 Array<MDKillListEntry>
#endif
    ASMovieRootBase* pSavedASMovieRoot;        // +0x34e8 Ptr<ASMovieRootBase>
    void*            RenderContext[0x22];      // +0x34f0 Render::ContextImpl::Context (0x110; gfx_rendertree.h: the heap first)
    UByte            PreviouslyCaptured;       // +0x3600 bumped (incremented) by ForceUpdateImages
    void*            DIContext;                // +0x3608 Ptr<Render::DrawableImageContext>
    void*            pRTCommandQueue;          // +0x3610 ThreadCommandQueue*
    void*            MultitouchHAL;            // +0x3618 Ptr<MultitouchInterface>
    int              MultitouchMode;           // +0x3620 MultitouchInputMode
    InteractiveObject* GestureTopMostChar;     // +0x3628 Ptr<InteractiveObject>
    int              DeviceOrientation;        // +0x3630 OrientationEvent: 0 default, 1 rotated left, 2 right, 3 upside down (sfr19)
    void*            IndirectTransformPairs[3]; // +0x3638 ArrayLH<IndirectTransPair>

    ASString CreateNewInstanceName();          // exe 0x14256e710
    bool     SetLevelMovie(int level, DisplayObjContainer* psprite); // exe 0x142575f20
    // The image exported (or provided by the image callback) under linkageId of md (exe 0x14256f370).
    Ptr<ImageResource> GetImageResourceByLinkageId(MovieDefImpl* md, const char* linkageId);
    // The topmost interactive object under a point (twips), skipping ignoreMC (exe 0x14256fde0).
    InteractiveObject* GetTopMostEntity(const Render::PointF& mousePos, unsigned controllerIdx, bool testAll,
                                        const InteractiveObject* ignoreMC = NULL);
    // The modal clip of the controller's focus group, if it is still alive (exe 0x14256f820).
    Sprite* GetModalClip(unsigned controllerIdx);

    // The movie's StateBag base (+0x10).
#ifdef SF_GFX_PLAYERIMPL
    StateBag* GetStateBag() const { return const_cast<MovieImpl*>(this); }
#else
    StateBag* GetStateBag() const { return (StateBag*)&MovieBase_Unrecovered[2]; }
#endif
    MemoryHeap* GetMovieHeap() const { return pHeap; }
    // Appends a load request to the queue processed on the next advance (exe 0x14256bdf0).
    void AddLoadQueueEntry(LoadQueueEntry* pentry);
    // (appended, sfr19) Appends a loader-thread entry to the pLoadQueueMTHead list (exe 0x14256be30).
    void AddLoadQueueEntryMT(LoadQueueEntryMT* pentryMT);

    // The object no longer stays on top of the levels (0x1425742c0).
    void RemoveTopmostLevelCharacter(DisplayObjectBase* pch);

    // An object drawn under another parent than its display list one (Ptr members: complete types needed where
    // a pair is destroyed).
    struct IndirectTransPair
    {
        Ptr<Render::TreeNode>      TransformParent;
        Ptr<DisplayObjectBase>     Obj;
        Ptr<DisplayObjContainer>   OriginalParent;
        mutable int                OrigParentDepth;   // -1 when unknown; no inline ctor, so the Ptr dtors stay uninstantiated
    };
    // Records obj as drawn under another node than the one of its display list parent (0x14256bc90).
    void AddIndirectTransformPair(DisplayObjContainer* origParent, Render::TreeNode* origParentNode,
                                  DisplayObjectBase* obj);
    // Takes the pair of obj off the movie's list and returns it (0x142574110).
    IndirectTransPair RemoveIndirectTransformPair(DisplayObjectBase* obj);

    // The mouse position relative to the visible frame, -1..1 with y up, for the 3D screen-to-world mapping.
    void SetNormalizedScreenCoords(const Render::PointF& mousePos)
    {
        float nsx = 2.f * ((mousePos.x - Render::PixelsToTwips(ViewOffsetX)) / VisibleFrameRect.Width()) - 1.0f;
        float nsy = 2.f * ((mousePos.y - Render::PixelsToTwips(ViewOffsetY)) / VisibleFrameRect.Height()) - 1.0f;
        ScreenToWorldSx = nsx;
        ScreenToWorldSy = -nsy;
    }

    // A new empty drawing (the scrollRect mask shape), referenced once (0x14256e3f0).
    DrawingContext* CreateDrawingContext();

    // The view and the perspective of a 3D stage: the eye on the axis through projCenter (twips), the visible frame
    // filling the field of view (degrees); focalLength 0 derives it from the field of view (0x1425718d0).
    static void MakeViewAndPersp3D(Render::Matrix3x4<float>* matView, Render::Matrix4x4<float>* matPersp,
                                   const Render::RectF& vfrTwips, const Render::PointF& projCenter,
                                   float fieldOfView, float focalLength = 0, bool invertY = false);

    // (appended for the interactive objects, sfr_gfx_06b)
    enum
    {
        Flag_OptAdvListInvalid = 0x80000,      // Flags: the optimized advance list is rebuilt before the next advance
        Flag2_OptAdvListMarker = 0x8           // Flags2: the marker the current members of the optimized list carry
    };
    bool IsOptAdvListInvalid() const  { return (Flags & Flag_OptAdvListInvalid) != 0; }
    bool GetOptAdvListMarker() const  { return (Flags2 & Flag2_OptAdvListMarker) != 0; }
    // The drag state kept at +0x2de0 (0x28 bytes; its first field is pKeepAdvancingChar).
    struct DragState
    {
        InteractiveObject* pCharacter;   // +0x00
        bool               LockCenter;   // +0x08
        bool               Bound;        // +0x09
        Render::PointF     BoundLT;      // +0x0c twips
        Render::PointF     BoundRB;      // +0x14
        Render::PointF     CenterDelta;  // +0x1c

        DragState() : pCharacter(0), LockCenter(false), Bound(false) {}
        // Offset from the mouse to the character, or none when the center is locked (exe 0x142570c80).
        void InitCenterDelta(bool lockCenter);
    };
    void SetDragState(const DragState& st) { *reinterpret_cast<DragState*>(&pKeepAdvancingChar) = st; }
    // +0x2de0 is the drag state: the dragged character (pKeepAdvancingChar), then these.
    bool DragLockCenter() const       { return *((const bool*)this + 0x2de8); }
    bool DragBound() const            { return *((const bool*)this + 0x2de9); }
    const Render::PointF& DragBoundLT() const     { return *(const Render::PointF*)((const UByte*)this + 0x2dec); }
    const Render::PointF& DragBoundRB() const     { return *(const Render::PointF*)((const UByte*)this + 0x2df4); }
    const Render::PointF& DragCenterDelta() const { return *(const Render::PointF*)((const UByte*)this + 0x2dfc); }

    // Takes the keyboard focus off ch in every focus group (0x142574820).
    void ResetFocusForChar(InteractiveObject* ch);
    // Moves the keyboard focus of the controller's focus group to ch, null to clear it (0x142575cd0, sfr19).
    void SetKeyboardFocusTo(InteractiveObject* ch, unsigned controllerIdx, FocusMovedType fmt);

    // (appended for the display list, sfr_gfx_06c)
    // Keeps a movie def (and so its heap) alive until the render thread let go of its nodes (0x14256be80).
    void AddMovieDefToKillList(MovieDefImpl* pdefImpl);
    // Re-parents the transform of an object with an indirect transform; null parent detaches it (0x1425786d0).
    void UpdateTransformParent(DisplayObjectBase* pch, DisplayObjectBase* pparent);

    // (appended for the containers, sfr_gfx_06d) a mouse is in use (MouseCursorCount, +0x13a0)
    bool IsMouseSupportEnabled() const { return *(const unsigned*)((const UByte*)this + 0x13a0) > 0; }
    // The 3D hit test mapping (Render::ScreenToWorld, 0x100 bytes) starts at ScreenToWorldSx.
    Render::ScreenToWorld& GetScreenToWorld() { return *reinterpret_cast<Render::ScreenToWorld*>(&ScreenToWorldSx); }

    // (appended for the player tasks, sfr_gfx_07f)
    // The directory of the main movie's URL (0x14256f730).
    bool GetMainMoviePath(String* ppath) const;
    // The whole of pfile as loadVariables text / loadBinary bytes (0x142573bc0 / 0x142573b10).
    static bool SF_STDCALL ReadTextData(String* pdata, File* pfile, int* pfileLen, bool urlEncoded);
    static bool SF_STDCALL ReadBinaryData(ArrayPOD<UByte>* pdata, File* pfile, int* pfileLen);

    // (appended for the font manager, sfr_gfx_07g) a font of the movies registered with RegisterFonts, by name and
    // style, and the movie it came from (0x14256ed40).
    FontResource* FindRegisteredFont(const char* pfontName, unsigned fontFlags, MovieDef** ppsrcMovieDef) const;

    // (appended for the AS3 support, sfr12) constructed by the AVM's CreateMovie into 0x3650 bytes of the movie heap.
    MovieImpl(MemoryHeap* pheap);
    // Movie's operator set (RefCountBase<Movie, StatMV_Other_Mem>): new (heap) allocates in the heap.
    SF_MEMORY_REDEFINE_NEW(MovieImpl, 0x147)
    // The log state's log (through the StateBag base).
    inline Ptr<Log> GetLog() const;     // defined in gfx_movieimplstates.h

    // (appended for the AS3 natives, sfr12)
    // The Movie interface MovieImpl implements: its base at offset 0 (what the host handlers receive).
    Movie* AsMovie() const { return (Movie*)this; }
    // The movie's states (StateBag at +0x10); defined in gfx_movieimplstates.h. Code matching the exe calls
    // GetStateBag()->GetLogState() instead: the exe reads the returned Ptr through the call's result register.
    inline Ptr<LogState>       GetLogState() const;
    inline Ptr<IMEManagerBase> GetIMEManager() const;
    // Keyboard keyboardIndex (0..3), NULL past the last one.
    const KeyboardState* GetKeyboardState(unsigned keyboardIndex) const
    {
        if (keyboardIndex < 4)
            return reinterpret_cast<const KeyboardState*>(KeyboardStates[keyboardIndex]);
        return NULL;
    }
    KeyboardState* GetKeyboardState(unsigned keyboardIndex)
    {
        if (keyboardIndex < 4)
            return reinterpret_cast<KeyboardState*>(KeyboardStates[keyboardIndex]);
        return NULL;
    }
    // MovieImpl as its Movie interface, for the virtual calls on itself (callers make the call through this: the
    // visible stage in pixels is AsMovieInterface()->GetVisibleFrameRect(), slot 17 at +0x88; an inline forwarder would
    // change how callers read the returned rect).
    inline const class MovieInterface418* AsMovieInterface() const;
    const Render::RectF& GetVisibleFrameRectInTwips() const { return VisibleFrameRect; }

    // Multitouch input (exe bodies).
    enum MultitouchInputMode
    {
        MTI_None       = 0,
        MTI_TouchPoint = 1,
        MTI_Gesture    = 2,
        MTI_Mixed      = 3
    };
    MultitouchInputMode GetMultitouchInputMode() const;
    void                SetMultitouchInputMode(MultitouchInputMode);
    unsigned            GetMaxTouchPoints() const;
    UInt32              GetSupportedGesturesMask() const;

    // (appended for the AS3 FocusManager, sfr17) the controllers of focus group focusGroupIdx, one bit each.
    UInt32 GetControllerMaskByFocusGroup(unsigned focusGroupIdx);   // exe 0x14256f050
    // (appended for the AS3 Sound, sfr17) the resource exported from pdefImpl's library as symbol.
    bool FindExportedResource(MovieDefImpl* pdefImpl, struct ResourceBindData* pdata, const String& symbol);   // exe 0x14256ec50
    // (appended for the AS3 IMEEx, sfr19) the IME candidate list style, copied out / in by value.
    void GetIMECandidateListStyle(IMECandidateListStyle* pst) const;   // exe 0x14256f310
    void SetIMECandidateListStyle(const IMECandidateListStyle& st);    // exe 0x142575c30
    // (appended for sfr_as2_02) a movie definition holding just the image, for attachBitmap; returns an added
    // reference.
    MovieDefImpl* CreateImageMovieDef(ImageResource* pimageRes, bool bilinear, const char* purl,
                                      LoadStates* pls = 0);   // exe 0x14256e4d0

    // (appended for sfr_as2_04) the wide copy of a string handed to the host as a VT_StringW value; it keeps
    // the string node. 0x20 bytes with the first character; the ctor and dtor are defined where used.
    class WideStringStorage : public RefCountBase<WideStringStorage, 0x143>   // StatMV_ActionScript_Mem
    {
    public:
        ASStringNode* pNode;    // +0x10
        wchar_t       pData[1]; // +0x18 the decoded characters, 0 terminated

        WideStringStorage(ASStringNode* pnode);
        virtual ~WideStringStorage();
    };

    // (appended for the player, sfr_gfx_01i)
    // Swaps in the AVM root (the AVM's CreateMovie sets it; exe 0x142575930).
    void SetASMovieRoot(ASMovieRootBase* pasMovieRoot);
    // The movie is shutting down: no render root left, or the shutdown flag set (exe 0x142571170).
    bool IsShutdowning() const;
    // The text allocator of the AVM root (exe 0x14256fdd0).
    Render::Text::Allocator* GetTextAllocator();
    // Moves the focus of the controller's focus group to ch (exe 0x142575b10).
    bool SetFocusTo(InteractiveObject* ch, unsigned controllerIdx, FocusMovedType fmt);
    // The stage-to-viewport matrix from the viewport, scale mode and alignment (exe 0x142574eb0).
    void ResetViewportMatrix();
    // (appended, sfr_gfx_01i) The view scale/offset, visible frame and viewport matrix from the viewport, the scale
    // mode and the alignment (exe 0x1425787d0).
    void UpdateViewport();
    // (appended, sfr_gfx_01i) Registers a playing video; the movie pauses it with itself (exe 0x14256c520).
    void AddVideoProvider(Video::VideoProvider* pvideo);
    // The font manager of the root node that loaded pdefImpl (exe 0x14256ed00).
    FontManager* FindFontManager(MovieDefImpl* pdefImpl);
    // The cursor shape of a mouse; the AVM root is told when it changes (exe 0x14256dc00).
    void ChangeMouseCursorType(unsigned mouseIdx, unsigned newCursorType);
    // Takes every object off the advance lists (exe 0x14256e150).
    void ClearPlayList();
#ifdef SF_GFX_PLAYERIMPL
    // The listener of all four keyboards (exe 0x142575ec0).
    void SetKeyboardListener(KeyboardState::IListener* l);
#endif
private:
    // Rebuilds the render nodes of the drawings changed since the last capture (exe 0x142577c10).
    void UpdateAllDrawingContexts();
protected:
    void ResetKeyboardState();   // exe 0x142574c60
    void ResetMouseState();      // exe 0x142574ca0
    // The movie got or lost the host's focus (Event::SetFocus / KillFocus); losing it resets the keyboards and mice
    // and finalizes an IME composition in progress (exe 0x142571f10).
    void OnMovieFocus(bool set);
public:

#ifdef SF_GFX_PLAYERIMPL
    // (sfr_gfx_01i) the Movie interface; exe vftables 0x143183640 (68 slots) and 0x143183860 (StateBag).
    virtual ~MovieImpl();
    virtual StateBag*      GetStateBagImpl() const;

    virtual MovieDef*      GetMovieDef() const;
    virtual unsigned       GetCurrentFrame() const;
    virtual bool           HasLooped() const;
    virtual void           GotoFrame(unsigned frameNumber);
    virtual bool           GotoLabeledFrame(const char* plabel, int offset = 0);
    virtual void           SetPlayState(PlayState s);
    virtual PlayState      GetPlayState() const;
    virtual void           SetVisible(bool visible);
    virtual bool           GetVisible() const;
    virtual UInt64         GetASTimerMs() const;
    virtual void           SetViewport(const Viewport& viewDesc);
    virtual void           GetViewport(Viewport* pviewDesc) const;
    virtual void           SetViewScaleMode(ScaleModeType);
    virtual ScaleModeType  GetViewScaleMode() const;
    virtual void           SetViewAlignment(AlignType);
    virtual AlignType      GetViewAlignment() const;
    virtual Render::RectF  GetVisibleFrameRect() const;
    virtual Render::RectF  GetSafeRect() const;
    virtual void           SetSafeRect(const Render::RectF& rect);
    virtual void           SetEdgeAAMode(Render::EdgeAAMode edgeAA);
    virtual Render::EdgeAAMode GetEdgeAAMode() const;
    virtual void           Restart(bool advance0 = true);
    virtual float          Advance(float deltaT, unsigned frameCatchUpCount = 2, bool capture = true);
    virtual void           Capture(bool onChangeOnly = true);
    virtual const Render::ContextImpl::DisplayHandle<Render::TreeRoot>& GetDisplayHandle() const;
    virtual void           SetCaptureThread(void* captureThreadId);
    virtual void           ShutdownRendering(bool wait);
    virtual bool           IsShutdownRenderingComplete() const;
    virtual void           SetPause(bool pause);
    virtual bool           IsPaused() const;
    virtual void           SetBackgroundColor(const Render::Color bgColor);
    virtual void           SetBackgroundAlpha(float alpha);
    virtual float          GetBackgroundAlpha() const;
    virtual unsigned       HandleEvent(const Event& event);
    virtual void           GetMouseState(unsigned mouseIndex, float* x, float* y, unsigned* buttons);
    virtual void           NotifyMouseState(float x, float y, unsigned buttons, unsigned mouseIndex = 0);
    virtual bool           HitTest(float x, float y, HitTestType testCond = HitTest_Shapes, unsigned controllerIdx = 0);
    virtual void*          GetUserData() const;
    virtual void           SetUserData(void*);
    virtual bool           IsMovieFocused() const;
    virtual bool           GetDirtyFlag(bool doReset = true);
    virtual void           SetMouseCursorCount(unsigned n);
    virtual unsigned       GetMouseCursorCount() const;
    virtual void           SetControllerCount(unsigned n);
    virtual unsigned       GetControllerCount() const;
    virtual void           GetStats(::Scaleform::StatBag* pbag, bool reset = true);
    virtual MemoryHeap*    GetHeap() const;
    virtual void           ForceCollectGarbage();
    virtual void           PrintObjectsReport(UInt32 flags = 0, Log* log = 0, const char* swfName = 0);
    virtual Render::PointF TranslateToScreen(const Render::PointF& p, Render::Matrix2x4<float>* puserMatrix = 0);
    virtual Render::RectF  TranslateToScreen(const Render::RectF& p, Render::Matrix2x4<float>* puserMatrix = 0);
    virtual bool           TranslateLocalToScreen(const char* pathToCharacter, const Render::PointF& pt,
                                                  Render::PointF* presPt, Render::Matrix2x4<float>* userMatrix = 0);
    virtual bool           SetControllerFocusGroup(unsigned controllerIdx, unsigned focusGroupIndex);
    virtual unsigned       GetControllerFocusGroup(unsigned controllerIdx) const;
    virtual void           ResetInputFocus(unsigned controllerIdx);
    virtual bool           IsExitRequested() const;
    virtual void           GetViewMatrix3D(Render::Matrix3x4<float>*);
    virtual void           SetViewMatrix3D(const Render::Matrix3x4<float>& m);
    virtual void           GetProjectionMatrix3D(Render::Matrix4x4<float>*);
    virtual void           SetProjectionMatrix3D(const Render::Matrix4x4<float>& m);
    virtual void           SetStageAutoOrients(bool v = true);
    virtual void           ForceUpdateImages();
    virtual void           MakeAreaVisible(const Render::RectF& screenRect, const Render::RectF& box, UInt32 flags = 0);
    virtual void           RestoreViewport();
    // MovieImpl's own (slots 65..67).
    virtual void           SetVerboseAction(bool verboseAction);
    virtual void           SetActionErrorsSuppress(bool suppressErrors);
    virtual bool           AcceptAnimMovesWith3D() const;
#endif
};

static_assert(sizeof(MovieImpl) == 0x3650, "MovieImpl size (ctor allocation 0x3650)");

// The leading Movie vftable slots, for the virtual calls MovieImpl makes on itself (GetVisibleFrameRect).
class __declspec(novtable) MovieInterface418
{
public:
    virtual void Slot00() = 0;
    virtual MovieDef* GetMovieDef() const = 0; // 1
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual Render::RectF GetVisibleFrameRect() const = 0; // 17
    virtual Render::RectF GetSafeRect() const = 0;         // 18 the title-safe stage rect, empty when unset
};

inline const MovieInterface418* MovieImpl::AsMovieInterface() const
{
    return reinterpret_cast<const MovieInterface418*>(this);
}

// The root of one loaded movie's sprite tree; leading members only (the font manager, bytes loaded and so on).
class MovieDefRootNode : public MovieDefRootNodeLinks   // pPrev +0x08, pNext +0x10
{
public:
    virtual ~MovieDefRootNode();         // vftable +0x00

    unsigned          SpriteRefCount;    // +0x18
    MovieDefImpl*     pDefImpl;          // +0x20
    unsigned          LoadingFrame;      // +0x28
    unsigned          BytesLoaded;       // +0x2c
    bool              ImportFlag;        // +0x30 the root of an import: its loading state is the parent's
    FontManager*      pFontManager;      // +0x38 Ptr<FontManager>
};

// A timer the movie drives each frame (AS2 setInterval, AS3 flash.utils.Timer). Interface vftable 0x142dc9d48.
class ASIntervalTimerIntf : public RefCountBase<ASIntervalTimerIntf, 0x143>   // StatMV_ActionScript_Mem
{
public:
    virtual ~ASIntervalTimerIntf() {}

    virtual void   Start(MovieImpl* proot) = 0;
    virtual bool   Invoke(MovieImpl* proot, float frameTime) = 0;  // frameTime in seconds
    virtual bool   IsActive() const = 0;
    virtual void   Clear() = 0;
    virtual bool   ClearFor(MovieImpl* proot, MovieDefImpl* pdefImpl) = 0;
    virtual UInt64 GetNextInvokeTime() const = 0;                  // microseconds
    virtual void   SetId(int id) = 0;
    virtual int    GetId() const = 0;
};

}} // namespace Scaleform::GFx

#endif
