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
#include "../kernel/sf_hash.h"     // (sfr24) LoadRegisteredFonts HashSet
#include "gfx_keyboardstate.h"
#ifdef SF_GFX_PLAYERIMPL
#include "gfx_player.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "gfx_keyboardstate.h"
#include "../kernel/sf_hash.h"
#include "gfx_input.h"
#include "gfx_rendertree.h"
#include "../render/render_screentoworld.h"
#include "../render/render_color.h"
#include "../render/render_matrix2x4.h"
#include "gfx_asstringhash.h"
#endif

namespace Scaleform {
class File;
namespace GFx {

class ASMovieRootBase;
namespace Video { class VideoProvider; }
class AudioBase;
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
namespace GFx { namespace AMP { class ViewStats; } class FSCommandHandler; class MultitouchInterface; }
namespace Render { class DrawableImageContext; class Font; }
namespace Sound { class SoundRenderer; }
namespace Render { class TreeNode; class TreeShape; template<class T> class Matrix3x4; template<class T> class Matrix4x4; class ScreenToWorld;
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
class InputEventsQueueEntry;
class MovieImpl;

// (sfr_gfx_06d) the links of the movie's list of root nodes (List<MovieDefRootNode>): the list root's pNext is the
// first node, and the root itself passes for a node one base offset before it.
struct MovieDefRootNodeLinks
{
    MovieDefRootNode* pPrev;
    MovieDefRootNode* pNext;
#ifdef SF_GFX_PLAYERIMPL
    // The movie's list root: empty, linked to itself (defined below MovieDefRootNode).
    inline MovieDefRootNodeLinks();
#endif
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
#ifdef SF_GFX_PLAYERIMPL
    Ptr<Render::TreeShape>           FocusRectNode;   // +0x00 the shape drawing the focus rectangle
    ArrayDH<Ptr<InteractiveObject>, 0x147> TabableArray;   // +0x08 the tab order, in the group's own heap
#else
    UByte   Unrecovered_00[0x28];      // +0x00 focus rect node, tabable array
#endif
    mutable WeakPtr<InteractiveObject> LastFocused;   // +0x28 the focused character
    Ptr<CharacterHandle> ModalClip;    // +0x30 the clip the focus is kept within
    UInt32  LastFocusKeyCode;          // +0x38
    UByte   Unrecovered_3c[4];
    Render::RectF LastFocusedRect;     // +0x40
    bool    FocusRectShown;            // +0x50 the focus rectangle is up (focus moved by keyboard)
    UByte   TabableArrayStatus;        // +0x51
    UByte   Unrecovered_52[0xe];

#ifdef SF_GFX_PLAYERIMPL
    // The defaulted heap makes MSVC emit the default ctor closure ??_F (exe 0x14256b580, unreferenced).
    FocusGroupDescr(MemoryHeap* heap = 0)
        : TabableArray(heap ? heap : Memory::GetHeapByAddress(this)), LastFocusKeyCode(0), FocusRectShown(false),
          TabableArrayStatus(0) {}
#endif

    // The modal clip, if it is still alive (exe 0x14256f7e0).
    Sprite* GetModalClip(MovieImpl* proot);
#ifdef SF_GFX_PLAYERIMPL
    // (appended, sfr24) Drops a filled tab order so the next focus key collects it again (exe 0x142574ce0).
    SF_NOINLINE void ResetTabableArray()
    {
        if (TabableArrayStatus & 1)
        {
            TabableArray.Clear();
            TabableArrayStatus = 0;
        }
    }
#endif
};
static_assert(sizeof(FocusGroupDescr) == 0x60, "FocusGroupDescr size");
static_assert(offsetof(FocusGroupDescr, FocusRectShown) == 0x50, "FocusGroupDescr::FocusRectShown");

#ifdef SF_GFX_PLAYERIMPL
// (appended, sfr24) The state of one focus key (Tab / arrows) while it is handled: InitFocusKeyInfo fills it from
// the controller's focus group, ProcessFocusKey moves CurFocusIdx, FinalizeProcessFocusKey applies it (0x40 bytes,
// on the stack of ActivateFocusCapture).
struct ProcessFocusKeyInfo
{
    FocusGroupDescr*       pFocusGroup;      // +0x00
    Ptr<InteractiveObject> CurFocused;       // +0x08
    int                    CurFocusIdx;      // +0x10 index into the tab order, -1 none
    Render::RectF          PrevFocusRect;    // +0x20 (16-aligned)
    UInt32                 PrevKeyCode;      // +0x30
    UInt32                 KeyCode;          // +0x34
    UInt8                  KeyboardIndex;    // +0x38
    UInt8                  KeysState;        // +0x39
    bool                   ManualFocus;      // +0x3a
    bool                   InclFocusEnabled; // +0x3b
    bool                   Initialized;      // +0x3c

    ProcessFocusKeyInfo() : pFocusGroup(0), CurFocusIdx(-1), PrevKeyCode(0), KeyCode(0), KeyboardIndex(0),
                            KeysState(0), ManualFocus(false), InclFocusEnabled(false), Initialized(false) {}
};
static_assert(sizeof(ProcessFocusKeyInfo) == 0x40, "ProcessFocusKeyInfo size");
static_assert(offsetof(ProcessFocusKeyInfo, PrevKeyCode) == 0x30, "ProcessFocusKeyInfo::PrevKeyCode");
#endif

class MovieImpl
#ifdef SF_GFX_PLAYERIMPL
    : public Movie
#endif
{
public:
    // A SetVariable value kept for a target that does not exist yet (gfx_stickyvarnode.h).
    struct StickyVarNode;
    // The buffers of an ExternalInterface.call return value (defined in the player unit).
    struct ReturnValueHolder;

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

#ifndef SF_GFX_PLAYERIMPL
    void*            MovieBase_Unrecovered[3]; // +0x00 RefCountBase vftable + count, StateBag vftable
    ASMovieRootBase* pASMovieRoot;             // +0x18 Ptr<ASMovieRootBase>: the AVM specific root
#endif
    LoadQueueEntry*  pLoadQueueHead;           // +0x20 the load requests processed on the next advance
    UInt32           LastLoadQueueEntryCnt;    // +0x28
#ifdef SF_GFX_PLAYERIMPL
    Ptr<AMP::ViewStats> pAdvanceStats;       // +0x30 (GetStats)
#else
    void*            pAdvanceStats;            // +0x30 Ptr<AMP::ViewStats> (GetStats)
#endif
    void*            pObjectInterface;         // +0x38 Value::ObjectInterface*: how host values reach the VM objects
    MemoryHeap*      pHeap;                    // +0x40 the movie's heap
#ifdef SF_GFX_PLAYERIMPL
    Ptr<MovieDefImpl> pMainMovieDef;          // +0x48 the _level0 movie
#else
    MovieDefImpl*    pMainMovieDef;            // +0x48 Ptr<MovieDefImpl>: the _level0 movie (sfr_gfx_07f)
#endif
    InteractiveObject* pMainMovie;             // +0x50 _level0
#ifdef SF_GFX_PLAYERIMPL
    // A level clip by level number; the movie holds a reference on it (0x10 bytes).
    struct LevelInfo { int Level; Ptr<InteractiveObject> pSprite; };
    ArrayLH<LevelInfo, 0x147> MovieLevels;     // +0x58 sorted by level, _level0 first (StatMV_Other_Mem)
#else
    struct LevelInfo { int Level; InteractiveObject* pSprite; };   // (sfr_gfx_06)
    LevelInfo*       pMovieLevels;             // +0x58 MovieLevels (ArrayLH data): _level0 first (sfr_gfx_06)
    UPInt            MovieLevelsSize;          // +0x60 MovieLevels size
    UPInt            MovieLevelsCapacity;      // +0x68
#endif
    MovieDefRootNodeLinks RootMovieDefNodes;   // +0x70 the root nodes of the loaded movies (sfr_gfx_06d)
#ifdef SF_GFX_PLAYERIMPL
    Ptr<StateBagImpl> pStateBag;              // +0x80 the movie's own states
#else
    StateBagImpl*    pStateBag;                // +0x80 Ptr<StateBagImpl>: the movie's own states (sfr_video_01)
#endif
#ifdef SF_GFX_PLAYERIMPL
    Ptr<Render::TreeRoot> pRenderRoot;        // +0x88
#else
    Render::TreeNode* pRenderRoot;             // +0x88 Ptr<TreeRoot> (sfr_gfx_06)
#endif
#ifdef SF_GFX_PLAYERIMPL
    Render::ContextImpl::DisplayHandle<Render::TreeRoot> hDisplayRoot; // +0x90 (GetDisplayHandle)
#else
    void*            hDisplayRoot;             // +0x90 DisplayHandle<TreeRoot> (GetDisplayHandle)
#endif
#ifdef SF_GFX_PLAYERIMPL
    Ptr<Render::TreeContainer> pTopMostRoot;  // +0x98
#else
    Render::TreeNode* pTopMostRoot;            // +0x98 Ptr<TreeContainer> (sfr_gfx_06)
#endif
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
#ifdef SF_GFX_PLAYERIMPL
    Render::Matrix2F ViewportMatrix;           // +0x110 stage twips -> viewport pixels
#else
    float            ViewportMatrix[2][4];     // +0x110 Matrix2F: stage twips -> viewport pixels
#endif
#ifdef SF_GFX_PLAYERIMPL
    Render::ScreenToWorld ScreenToWorld;       // +0x130 the 3D hit test mapping (0xf0 bytes)
#else
    float            ScreenToWorldSx;          // +0x130 ScreenToWorld: the normalized mouse position (y up)
    float            ScreenToWorldSy;          // +0x134
    void*            ScreenToWorldRest[0x1d];  // +0x138 the rest of Render::ScreenToWorld
#endif
#ifdef SF_GFX_PLAYERIMPL
    HashSet<Ptr<Video::VideoProvider> > VideoProviders; // +0x220 the playing videos (paused with the movie)
#else
    void*            VideoProviders;           // +0x220 HashSet<Ptr<Video::VideoProvider>>
#endif
    Ptr<Log>         pCachedLog;               // +0x228 the log state's log, cached (sfr_gfx_06)
#ifdef SF_GFX_PLAYERIMPL
    Ptr<UserEventHandler>  pUserEventHandler;  // +0x230
    Ptr<FSCommandHandler>  pFSCommandHandler;  // +0x238
    Ptr<ExternalInterface> pExtIntfHandler;    // +0x240
    Ptr<FontManagerStates> pFontManagerStates; // +0x248
#else
    UserEventHandler* pUserEventHandler;       // +0x230 Ptr<UserEventHandler>: cached during advance (sfr12)
    void*            pFSCommandHandler;        // +0x238 Ptr<FSCommandHandler>
    ExternalInterface* pExtIntfHandler;        // +0x240 Ptr<ExternalInterface>: the host's ExternalInterface.call hook
    FontManagerStates* pFontManagerStates;     // +0x248 Ptr: the font states the movies' font managers share (sfr_gfx_06d)
#endif
#ifdef SF_GFX_PLAYERIMPL
    AudioBase*       pAudio;                   // +0x250 held for the length of an Advance only
    Sound::SoundRenderer* pSoundRenderer;      // +0x258 pAudio's renderer, the same
#else
    void*            pAudio;                   // +0x250 AudioBase*
    void*            pSoundRenderer;           // +0x258
#endif
    void*            pXMLObjectManager;        // +0x260
    UInt64           TimeElapsed;              // +0x268
    float            TimeRemainder;            // +0x270
    float            FrameTime;                // +0x274 seconds per frame (sfr_video_01 SetSwfSync)
    unsigned         ForceFrameCatchUp;        // +0x278
#ifdef SF_GFX_PLAYERIMPL
    GFx::InputEventsQueue InputEventsQueue;    // +0x280
    Render::Color    BackgroundColor;          // +0x1258
    MouseState       mMouseState[4];           // +0x1260 0x50 bytes each
#else
    void*            InputEventsQueue[0xfd8 / 8]; // +0x280 InputEventsQueue
    UInt32           BackgroundColor;          // +0x1258 Render::Color (alpha in the top byte)
    void*            MouseState0_1260[7];      // +0x1260 mMouseState[4], 0x50 bytes each: buttons at +0x30
    Render::PointF   MouseLastPosition;        // +0x1298 MouseState[0] last position, twips (sfr_gfx_06)
    UByte            MouseStatesRest[0x100];   // +0x12a0 the rest of mMouseState
#endif
    unsigned         MouseCursorCount;         // +0x13a0 the mice in use (up to 4)
    unsigned         ControllerCount;          // +0x13a4
    void*            UserData;                 // +0x13a8 the host's
#ifdef SF_GFX_PLAYERIMPL
    KeyboardState    KeyboardStates[4];        // +0x13b0 one per keyboard
#else
    UByte            KeyboardStates[4][0x688]; // +0x13b0 KeyboardState[4] (gfx_keyboardstate.h), one per keyboard
#endif
#ifdef SF_GFX_PLAYERIMPL
    ReturnValueHolder* pRetValHolder;          // +0x2dd0 the ExternalInterface.call return value
#else
    void*            pRetValHolder;            // +0x2dd0
#endif
    unsigned long    InstanceNameCount;        // +0x2dd8 the instanceN names handed out (formatted with the unsigned long LongFormatter)
    // A character the timeline keeps advancing even when stopped (MS2 build; Sprite::CheckAdvanceStatus).
#ifdef SF_GFX_PLAYERIMPL
    DragState        CurrentDragState;         // +0x2de0
#else
    DisplayObjectBase* pKeepAdvancingChar;     // +0x2de0 CurrentDragState (0x28 bytes, DragState above)
    UByte            CurrentDragStateRest[0x20]; // +0x2de8
#endif
#ifdef SF_GFX_PLAYERIMPL
    ASStringHash<StickyVarNode*> StickyVariables; // +0x2e08 SetVariable values waiting for their target
#else
    void*            StickyVariables;          // +0x2e08 ASStringHash<StickyVarNode*>
#endif
#ifdef SF_GFX_PLAYERIMPL
    ArrayLH<Ptr<InteractiveObject>, 0x147> TopmostLevelCharacters; // +0x2e10 (StatMV_Other_Mem)
#else
    void*            TopmostLevelCharacters[3]; // +0x2e10 ArrayLH<Ptr<InteractiveObject>>
#endif
    UInt64           StartTickMs;              // +0x2e28
    UInt64           PauseTickMs;              // +0x2e30
#ifdef SF_GFX_PLAYERIMPL
    ArrayLH<Ptr<ASIntervalTimerIntf>, 0x147> IntervalTimers; // +0x2e38 (StatMV_Other_Mem)
#else
    void*            IntervalTimers[3];        // +0x2e38 ArrayLH<Ptr<ASIntervalTimerIntf>>
#endif
    int              LastIntervalTimerId;      // +0x2e50
#ifdef SF_GFX_PLAYERIMPL
    Ptr<Render::TreeContainer> FocusRectContainerNode; // +0x2e58
#else
    void*            FocusRectContainerNode;   // +0x2e58 Ptr<TreeContainer>
#endif

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
        Flag_NeedMouseUpdate    = 0x80,        // (appended, sfr_gfx_01i) the topmost entities need a refresh
        Flag_NoInvisibleAdvance = 0x800,       // _global.noInvisibleAdvance: hidden clips stop advancing
        Flag_SetCursorTypeFuncOverloaded = 0x1000, // (appended, sfr_as2_07) Mouse.setCursorType replaced by a script
        Flag_ContinueAnimation  = 0x2000,      // _global.gfxExtensions continueAnimation (sfr_gfx_06)
        Flag_DisableFocusAutoReleaseByMouseClick = 0x10000, // (appended, sfr_gfx_01i) a click keeps the focus rect
        Shift_AlwaysEnableKeyboardPress = 26,  // two bits: 0 undefined, 1 true, 2 false, 3 read as -1
        Shift_DisableFocusRolloverEvent = 28,  // two bits, the same encoding
        // (appended, sfr_as2_05) the other Selection extension properties, same encoding
        Shift_DisableFocusAutoRelease   = 22,
        Shift_AlwaysEnableArrowKeys     = 24,
        Shift_DisableFocusKeys          = 30,
        // (appended, sfr_gfx_01i) the per-advance copies of the log and the ActionControl state
        Flag_CachedLogFlag         = 0x2,      // pCachedLog is valid (inside Advance)
        Flag_VerboseAction         = 0x4,
        Flag_LogRootFilenames      = 0x8,
        Flag_LogChildFilenames     = 0x10,
        Flag_LogLongFilenames      = 0x20,
        Flag_SuppressActionErrors  = 0x40,
        Flag_LevelClipsChanged     = 0x100,    // (appended, sfr_gfx_01i) a level was set: run its frame 0 first
        Flag_AdvanceCalled         = 0x200,    // (appended, sfr_gfx_01i)
        Flag_HasChanges            = 0x400,    // the last capture had changes (Capture)
        Flag_Paused                = 0x100000, // (appended, sfr_gfx_01i) SetPause
    };
    bool IsNoInvisibleAdvanceFlagSet() const { return (Flags & Flag_NoInvisibleAdvance) != 0; }
    // _focusrect rollover events suppressed (disableFocusRolloverEvent extension property).
    // (appended, sfr_gfx_01i) Tab / arrow keys do not move the focus (disableFocusKeys extension property).
    bool IsDisableFocusKeys() const
    {
        UInt32 v = (Flags >> Shift_DisableFocusKeys) & 3;
        return ((v == 3) ? -1 : int(v)) == 1;
    }
    // (appended, sfr_gfx_01i) a mouse move keeps the focus rectangle up (disableFocusAutoRelease property).
    bool IsDisableFocusAutoRelease() const
    {
        UInt32 v = (Flags >> Shift_DisableFocusAutoRelease) & 3;
        return ((v == 3) ? -1 : int(v)) == 1;
    }
    bool IsDisableFocusRolloverEvent() const
    {
        int v = (Flags >> Shift_DisableFocusRolloverEvent) & 3;
        if (v == 3)
            v = -1;
        return v == 1;
    }
    // (appended, sfr24) the arrow keys move the focus even where the focused character shows no focus rectangle
    // (alwaysEnableArrowKeys extension property)
    bool IsAlwaysEnableFocusArrowKeys() const
    {
        int v = (Flags >> Shift_AlwaysEnableArrowKeys) & 3;
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
    // Whether ch has the focus of any focus group (exe 0x142571070).
    bool IsFocused(const InteractiveObject* ch) const;
    // Takes the focus rectangle down unless the focused character refuses to lose the focus (exe 0x142570920).
    void HideFocusRect(unsigned controllerIdx);
    bool IsFocusRectShown(unsigned controllerIdx) const
    {
        return FocusGroups[FocusGroupIndexes[controllerIdx]].FocusRectShown;
    }
    // (appended for the game's GFxManager, gfxui/gfxmanager.cpp) the controller's focus group (protected in the exe:
    // IEAA) and what it has focused.
protected:
    FocusGroupDescr& GetFocusGroup(unsigned controllerIdx)
    {
        return FocusGroups[FocusGroupIndexes[controllerIdx]];
    }
public:
    // Defined once both MovieImpl and InteractiveObject are complete (the end of this header or gfx_interactiveobject.h).
    inline Ptr<InteractiveObject> GetFocusedCharacter(unsigned controllerIdx);

    // Removes the setInterval/setTimeout timer with the given id (exe 0x14256e0d0).
    void ClearIntervalTimer(int id);
    // Registers a started setInterval/setTimeout/Timer timer and returns its id (exe 0x14256bd60).
    int AddIntervalTimer(ASIntervalTimerIntf* timer);

    // (appended for the display objects, sfr_gfx_06)
    UInt32           Flags2;                   // +0x3494 (sfr_gfx_06b)
    IMECandidateListStyle* pIMECandidateListStyle; // +0x3498
    LoadQueueEntryMT* pLoadQueueMTHead;        // +0x34a0 the loader-thread entries, newest first (sfr19)
#ifdef SF_GFX_PLAYERIMPL
    // A font registered with Font.registerFont (exe dtor of the array 0x14256a780: two Resource Ptrs, 0x10 bytes).
    struct FontDesc
    {
        Ptr<MovieDef>    pMovieDef;
        Ptr<Resource>    pFont;
    };
    ArrayLH<FontDesc, 2> RegisteredFonts;      // +0x34a8
#else
    void*            RegisteredFonts[3];       // +0x34a8 ArrayLH<FontDesc>
#endif
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
#ifdef SF_GFX_PLAYERIMPL
    Ptr<ASMovieRootBase> pSavedASMovieRoot;   // +0x34e8
#else
    ASMovieRootBase* pSavedASMovieRoot;        // +0x34e8 Ptr<ASMovieRootBase>
#endif
#ifdef SF_GFX_PLAYERIMPL
    Render::ContextImpl::Context RenderContext; // +0x34f0 (0x110)
#else
    void*            RenderContext[0x22];      // +0x34f0 Render::ContextImpl::Context (0x110; gfx_rendertree.h: the heap first)
#endif
    char             PreviouslyCaptured;       // +0x3600 bumped (incremented) by ForceUpdateImages; signed (Capture)
#ifdef SF_GFX_PLAYERIMPL
    Ptr<Render::DrawableImageContext> DIContext; // +0x3608
#else
    void*            DIContext;                // +0x3608 Ptr<Render::DrawableImageContext>
#endif
    void*            pRTCommandQueue;          // +0x3610 ThreadCommandQueue*
#ifdef SF_GFX_PLAYERIMPL
    Ptr<MultitouchInterface> MultitouchHAL;   // +0x3618
#else
    void*            MultitouchHAL;            // +0x3618 Ptr<MultitouchInterface>
#endif
    int              MultitouchMode;           // +0x3620 MultitouchInputMode
#ifdef SF_GFX_PLAYERIMPL
    Ptr<InteractiveObject> GestureTopMostChar; // +0x3628
#else
    InteractiveObject* GestureTopMostChar;     // +0x3628 Ptr<InteractiveObject>
#endif
    int              DeviceOrientation;        // +0x3630 OrientationEvent: 0 default, 1 rotated left, 2 right, 3 upside down (sfr19)
#ifdef SF_GFX_PLAYERIMPL
    struct IndirectTransPair;
    ArrayLH<IndirectTransPair, 2> IndirectTransformPairs; // +0x3638 (Stat_Default_Mem: the exe Reserve passes 2)
#else
    void*            IndirectTransformPairs[3]; // +0x3638 ArrayLH<IndirectTransPair>
#endif

    ASString CreateNewInstanceName();          // exe 0x14256e710
    bool     SetLevelMovie(int level, DisplayObjContainer* psprite); // exe 0x142575f20
    // (appended, sfr_gfx_01i) unloads a level; level 0 unloads them all (exe 0x142573ed0).
    bool     ReleaseLevelMovie(int level);
    // (appended, sfr_gfx_01i) advances the characters on the advance list (exe 0x14256d390).
    void     AdvanceFrame(bool nextFrame, float framePos);
    // The image exported (or provided by the image callback) under linkageId of md (exe 0x14256f370).
    Ptr<ImageResource> GetImageResourceByLinkageId(MovieDefImpl* md, const char* linkageId);
    // The topmost interactive object under a point (twips), skipping ignoreMC (exe 0x14256fde0).
    InteractiveObject* GetTopMostEntity(const Render::PointF& mousePos, unsigned controllerIdx, bool testAll,
                                        const InteractiveObject* ignoreMC = NULL);
    // The modal clip of the controller's focus group, if it is still alive (exe 0x14256f820).
    Sprite* GetModalClip(unsigned controllerIdx);
    // Keeps the focus of the controller's group within pmovie (NULL: anywhere) (exe 0x1425761a0).
    void    SetModalClip(Sprite* pmovie, unsigned controllerIdx);
    // Clears every interval timer and empties the list (exe 0x142576c60).
    void    ShutdownTimers();
    // The ExternalInterface.call return value buffers, created on first use (exe 0x14256f990).
    ReturnValueHolder* GetRetValHolder();
    // The BitmapData drawing context, created on first use (exe 0x14256f220).
    Render::DrawableImageContext* GetDrawableImageContext();
    // Drops the timers that belong to pdefImpl (exe 0x142576cc0).
    void    ShutdownTimersForMovieDef(MovieDefImpl* pdefImpl);

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
    void ProcessLoadQueue();   // exe 0x142573220
    // (appended, sfr_gfx_01i) adds the fonts of Font.registerFont to fonts (exe 0x1425711a0).
    void LoadRegisteredFonts(HashSet<Ptr<Render::Font> >& fonts);
    // (appended, sfr24) Removes the clips queued for unloading (exe 0x1425738b0).
    void ProcessUnloadQueue();
    // (appended, sfr24) Lets go of a movie def whose kill frame the render thread has finished (exe 0x1425737e0).
    void ProcessMovieDefToKillList();
    // (appended, sfr24) Drops the indirect transform pairs (exe 0x14256e010).
    void ClearIndirectTransformPairs();
    // (appended, sfr24) Drops the SetVariable values waiting for their targets (exe 0x14256e1a0).
    void ClearStickyVariables();
    // (appended, sfr_gfx_01i) keeps a SetVariable value until its target exists (exe 0x14256bf50).
    void AddStickyVariableNode(const ASString& path, StickyVarNode* pnode);
    // (appended, sfr_gfx_01i) handles the queued input events (exe 0x142572e10).
    void ProcessInput();
    // A queued mouse event; miceProceededMask gets the mouse's bit (exe 0x142573380).
    void ProcessMouse(const InputEventsQueueEntry* qe, UInt32* miceProceededMask, bool avm2);
#ifdef SF_GFX_PLAYERIMPL
    // (appended, sfr24) The focus keys. A Tab press on the controller without a key event (exe 0x14256bbf0).
    void ActivateFocusCapture(unsigned controllerIdx);
    // Fills the key state from the controller's focus group, collecting its tab order first (exe 0x142570d80).
    void InitFocusKeyInfo(ProcessFocusKeyInfo* pfocusInfo, const InputEventsQueueEntry::KeyEntry& keyEntry,
                          bool inclFocusEnabled, FocusGroupDescr* pfocusGroup = 0);
    // Moves the focus index for a Tab / arrow key (exe 0x142572050).
    void ProcessFocusKey(Event::EventType event, const InputEventsQueueEntry::KeyEntry& keyEntry,
                         ProcessFocusKeyInfo* pfocusInfo);
    // Gives the focus to the character the key moved to and shows or hides the focus rect (exe 0x14256eae0).
    void FinalizeProcessFocusKey(ProcessFocusKeyInfo* pfocusInfo);
    // (appended, sfr_gfx_01i) a queued key event (exe 0x142573070).
    void ProcessKeyboard(const InputEventsQueueEntry* qe, ProcessFocusKeyInfo* focusKeyInfo);
    // Queues the focus change for the next advance (exe 0x142573940).
    bool QueueSetFocusTo(InteractiveObject* ch, InteractiveObject* dontRemoveFromFocused, unsigned controllerIdx,
                         FocusMovedType fmt, ProcessFocusKeyInfo* pfocusKeyInfo = 0);
protected:
    // Collects the tab order of the key's focus group (exe 0x14256e9a0).
    void FillTabableArray(const ProcessFocusKeyInfo* pfocusInfo);
public:
#endif

    // The object no longer stays on top of the levels (0x1425742c0).
    // (appended, sfr_gfx_01i) The object stays on top of the levels, ordered like the display lists (0x14256c140).
    void AddTopmostLevelCharacter(InteractiveObject* pch);
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
#ifdef SF_GFX_PLAYERIMPL
        ScreenToWorld.SetNormalizedScreenCoords(nsx, nsy);
#else
        ScreenToWorldSx = nsx;
        ScreenToWorldSy = -nsy;
#endif
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
#ifdef SF_GFX_PLAYERIMPL
    void SetDragState(const DragState& st) { CurrentDragState = st; }
#else
    void SetDragState(const DragState& st) { *reinterpret_cast<DragState*>(&pKeepAdvancingChar) = st; }
#endif
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
#ifdef SF_GFX_PLAYERIMPL
    Render::ScreenToWorld& GetScreenToWorld() { return ScreenToWorld; }
#else
    Render::ScreenToWorld& GetScreenToWorld() { return *reinterpret_cast<Render::ScreenToWorld*>(&ScreenToWorldSx); }
#endif

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
            return reinterpret_cast<const KeyboardState*>(&KeyboardStates[keyboardIndex]);
        return NULL;
    }
    KeyboardState* GetKeyboardState(unsigned keyboardIndex)
    {
        if (keyboardIndex < 4)
            return reinterpret_cast<KeyboardState*>(&KeyboardStates[keyboardIndex]);
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
    unsigned GetControllerMaskByFocusGroup(unsigned focusGroupIdx); // exe 0x14256f050
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
    // (appended, sfr_gfx_01i) Unregisters a video (exe 0x1425743a0).
    void RemoveVideoProvider(Video::VideoProvider* pvideo);
    // The font manager of the root node that loaded pdefImpl (exe 0x14256ed00).
    FontManager* FindFontManager(MovieDefImpl* pdefImpl);
    // (appended, sfr_gfx_01i) Font.registerFont: adds the font once per movie def (exe 0x142573d60).
    bool RegisterFont(MovieDef* md, FontResource* pfont);
    // (appended, sfr_gfx_01i) Drops pdefImpl's registered fonts and the font caches for it (exe 0x142577b00).
    void UnregisterFonts(MovieDefImpl* pdefImpl);
    // (appended, sfr_gfx_01i) Makes ch the focused character of the controller's focus group (exe 0x142577060).
    void TransferFocus(InteractiveObject* ch, unsigned controllerIdx, FocusMovedType fmt);
    // The cursor shape of a mouse; the AVM root is told when it changes (exe 0x14256dc00).
    void ChangeMouseCursorType(unsigned mouseIdx, unsigned newCursorType);
    // Takes every object off the advance lists (exe 0x14256e150).
    void ClearPlayList();
    // The listener of all four keyboards (exe 0x142575ec0).
    void SetKeyboardListener(KeyboardState::IListener* l);
private:
    // Rebuilds the render nodes of the drawings changed since the last capture (exe 0x142577c10).
    void UpdateAllDrawingContexts();
    // Passes a changed view or perspective on to every level (exe 0x142578760).
    void UpdateViewAndPerspective();
    // Redraws the focus rectangles of the focus groups (exe 0x142577cd0).
    void UpdateFocusRectRenderNodes();
    // (appended, sfr_gfx_01i) A changed topmost entity of the mouse picks up its cursor shape (exe 0x14256dca0).
    void CheckMouseCursorType(unsigned mouseIdx, InteractiveObject* ptopMouseCharacter);
public:
    // The drawings, then the focus rectangles when they changed (exe 0x142577c60).
    void UpdateAllRenderNodes();
protected:
    void ResetKeyboardState();   // exe 0x142574c60
    void ResetMouseState();      // exe 0x142574ca0
#ifdef SF_GFX_PLAYERIMPL
    // (appended, sfr_gfx_01i) Every focus group drops its modal clip, tab order and last focus key (exe 0x142574b00).
    void ResetFocusStates();
    // Every focus group drops a filled tab order (exe 0x142574da0).
    void ResetTabableArrays();
#endif
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
static_assert(offsetof(MovieImpl, pMainMovieDef) == 0x48, "MovieImpl::pMainMovieDef");
static_assert(offsetof(MovieImpl, pStateBag) == 0x80, "MovieImpl::pStateBag");
static_assert(offsetof(MovieImpl, pRenderRoot) == 0x88, "MovieImpl::pRenderRoot");
static_assert(offsetof(MovieImpl, FocusGroups) == 0x2e60, "MovieImpl::FocusGroups");
static_assert(offsetof(MovieImpl, FocusGroupIndexes) == 0x3464, "MovieImpl::FocusGroupIndexes");
static_assert(offsetof(MovieImpl, Flags) == 0x3490, "MovieImpl::Flags");
static_assert(offsetof(MovieImpl, Flags2) == 0x3494, "MovieImpl::Flags2");

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
    // (appended, sfr24) as AS2 MovieRoot::CreateMovieDefRootNode 0x1429365c0 builds it (0x40 bytes); the links,
    // LoadingFrame and BytesLoaded are left to the movie.
    MovieDefRootNode(MovieDefImpl* pdefImpl, bool importFlag)
        : SpriteRefCount(1), pDefImpl(pdefImpl), ImportFlag(importFlag), pFontManager(NULL)
    {
    }
    // (sfr24) inline: ??_G 0x1424e3380 releases the font manager (a Ptr in the exe) in place. vftable 0x14317c9e0
    virtual ~MovieDefRootNode()
    {
        reinterpret_cast<Ptr<RefCountImpl>*>(&pFontManager)->~Ptr<RefCountImpl>();
    }
    // (appended, sfr24) the deleting destructors free through the global heap
    SF_MEMORY_REDEFINE_NEW(MovieDefRootNode, Stat_Default_Mem)

    unsigned          SpriteRefCount;    // +0x18
    MovieDefImpl*     pDefImpl;          // +0x20
    unsigned          LoadingFrame;      // +0x28
    unsigned          BytesLoaded;       // +0x2c
    bool              ImportFlag;        // +0x30 the root of an import: its loading state is the parent's
    FontManager*      pFontManager;      // +0x38 Ptr<FontManager>
};

#ifdef SF_GFX_PLAYERIMPL
inline MovieDefRootNodeLinks::MovieDefRootNodeLinks()
{
    pNext = pPrev = static_cast<MovieDefRootNode*>(this);
}
#endif

// A timer the movie drives each frame (AS2 setInterval, AS3 flash.utils.Timer). Interface vftable 0x142dc9d48.
class __declspec(novtable) ASIntervalTimerIntf : public RefCountBase<ASIntervalTimerIntf, 0x143>   // StatMV_ActionScript_Mem
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

// MovieImpl::GetFocusedCharacter, emitted by whichever of gfx_movieimpl.h / gfx_interactiveobject.h comes second.
#if defined(MS2_SF_GFX_MOVIEIMPL_H) && defined(MS2_SF_GFX_INTERACTIVEOBJECT_H) && !defined(MS2_SF_GFX_MOVIEIMPL_FOCUSEDCHAR)
#define MS2_SF_GFX_MOVIEIMPL_FOCUSEDCHAR
namespace Scaleform { namespace GFx {
inline Ptr<InteractiveObject> MovieImpl::GetFocusedCharacter(unsigned controllerIdx)
{
    return Ptr<InteractiveObject>(GetFocusGroup(controllerIdx).LastFocused);
}
}} // namespace Scaleform::GFx
#endif

#endif
