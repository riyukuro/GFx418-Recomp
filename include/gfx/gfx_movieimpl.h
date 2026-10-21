// Recovered Scaleform 4.1.18 GFx: the movie implementation (MovieImpl), as far as the recovered units call into it.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder. The bases (Movie :
// RefCountBase, StateBag) are not recovered yet; their words are kept as placeholders up to the members read.
#ifndef MS2_SF_GFX_MOVIEIMPL_H
#define MS2_SF_GFX_MOVIEIMPL_H

#include "../kernel/sf_refcount.h"
#include "../render/render_types2d.h"
#include "../render/render_twips.h"
#include "../kernel/sf_string.h"
#include "../kernel/sf_array.h"

namespace Scaleform {
class File;
namespace GFx {

class ASMovieRootBase;
class DisplayObjectBase;
class InteractiveObject;
class DrawingContext;
class DisplayObjContainer;
class MovieDefImpl;
class FontManager;
class ASString;
}
class MemoryHeap;
class Log;
namespace Render { class TreeNode; template<class T> class Matrix3x4; template<class T> class Matrix4x4; class ScreenToWorld; }
namespace GFx {
class StateBag;
class FontManagerStates;
class MovieDefRootNode;
class FontResource;
class MovieDef;

// (sfr_gfx_06d) the links of the movie's list of root nodes (List<MovieDefRootNode>): the list root's pNext is the
// first node, and the root itself passes for a node one base offset before it.
struct MovieDefRootNodeLinks
{
    MovieDefRootNode* pPrev;
    MovieDefRootNode* pNext;
};

class MovieImpl
{
public:
    void*            MovieBase_Unrecovered[3]; // +0x00 RefCountBase vftable + count, StateBag vftable
    ASMovieRootBase* pASMovieRoot;             // +0x18 Ptr<ASMovieRootBase>: the AVM specific root
    void*            Unrecovered_20[4];        // +0x20
    MemoryHeap*      pHeap;                    // +0x40 the movie's heap
    MovieDefImpl*    pMainMovieDef;            // +0x48 Ptr<MovieDefImpl>: the _level0 movie (sfr_gfx_07f)
    InteractiveObject* pMainMovie;             // +0x50 _level0
    struct LevelInfo { int Level; InteractiveObject* pSprite; };   // (sfr_gfx_06)
    LevelInfo*       pMovieLevels;             // +0x58 MovieLevels (ArrayLH data): _level0 first (sfr_gfx_06)
    void*            Unrecovered_60[2];        // +0x60
    MovieDefRootNodeLinks RootMovieDefNodes;   // +0x70 the root nodes of the loaded movies (sfr_gfx_06d)
    void*            Unrecovered_80;           // +0x80
    Render::TreeNode* pRenderRoot;             // +0x88 Ptr<TreeRoot> (sfr_gfx_06)
    void*            Unrecovered_90;           // +0x90
    Render::TreeNode* pTopMostRoot;            // +0x98 Ptr<TreeContainer> (sfr_gfx_06)
    int              ViewportUnrecovered_a0[4]; // +0xa0 mViewport: buffer size, left/top
    int              ViewportWidth;            // +0xb0 mViewport.Width, pixels (sfr_gfx_06)
    int              ViewportHeight;           // +0xb4 mViewport.Height
    UByte            ViewportUnrecovered_b8[0x20]; // +0xb8 mViewport: scissor, flags, scale, aspect
    float            ViewScaleX, ViewScaleY;   // +0xd8 stage twips per window pixel (sfr_gfx_06)
    float            ViewOffsetX, ViewOffsetY; // +0xe0 viewport offset in pixels (sfr_gfx_06)
    void*            Unrecovered_e8;           // +0xe8
    Render::RectF    VisibleFrameRect;         // +0xf0 the visible stage, twips
    void*            Unrecovered_100[6];       // +0x100
    float            ScreenToWorldSx;          // +0x130 ScreenToWorld: the normalized mouse position (y up)
    float            ScreenToWorldSy;          // +0x134
    void*            Unrecovered_138[0x1e];    // +0x138
    Ptr<Log>         pCachedLog;               // +0x228 the log state's log, cached (sfr_gfx_06)
    void*            Unrecovered_230[3];       // +0x230
    FontManagerStates* pFontManagerStates;     // +0x248 Ptr: the font states the movies' font managers share (sfr_gfx_06d)
    void*            Unrecovered_250[0x209];   // +0x250
    Render::PointF   MouseLastPosition;        // +0x1298 MouseState[0] last position, twips (sfr_gfx_06)
    void*            Unrecovered_12a0[0x368];  // +0x12a0
    // A character the timeline keeps advancing even when stopped (MS2 build; Sprite::CheckAdvanceStatus).
    DisplayObjectBase* pKeepAdvancingChar;     // +0x2de0
    void*            Unrecovered_2de8[0xf];    // +0x2de8

    // Keyboard focus state of one focus group (one per controller group; 0x60 bytes, 16-aligned).
    struct FocusGroupDescr
    {
        UByte   Unrecovered_00[0x28];      // +0x00 focus rect node, tabable array
        mutable WeakPtr<InteractiveObject> LastFocused;   // +0x28 the focused character
        UByte   Unrecovered_30[0x20];      // +0x30 modal clip, last focus key, last focused rect
        bool    FocusRectShown;            // +0x50 the focus rectangle is up (focus moved by keyboard)
        UByte   Unrecovered_51[0xf];
    };
    FocusGroupDescr  FocusGroups[16];          // +0x2e60
    UInt32           Unrecovered_3460;         // +0x3460
    UByte            FocusGroupIndexes[16];    // +0x3464 controller index -> focus group
    UByte            Unrecovered_3474[4];      // +0x3474
    InteractiveObject* pPlayList;              // +0x3478 the advance list, last added first (sfr_gfx_06b)
    InteractiveObject* pPlayListOptHead;       // +0x3480 the optimized advance list (sfr_gfx_06b)
    UByte            Unrecovered_3488[8];      // +0x3488
    UInt32           Flags;                    // +0x3490

    enum FlagsType
    {
        Flag_NoInvisibleAdvance = 0x800,       // _global.noInvisibleAdvance: hidden clips stop advancing
        Flag_ContinueAnimation  = 0x2000,      // _global.gfxExtensions continueAnimation (sfr_gfx_06)
        Shift_AlwaysEnableKeyboardPress = 26,  // two bits: 0 undefined, 1 true, 2 false, 3 read as -1
        Shift_DisableFocusRolloverEvent = 28   // two bits, the same encoding
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
    bool IsFocusRectShown(unsigned controllerIdx) const
    {
        return FocusGroups[FocusGroupIndexes[controllerIdx]].FocusRectShown;
    }

    // Removes the setInterval/setTimeout timer with the given id (exe 0x14256e0d0).
    void ClearIntervalTimer(int id);

    // (appended for the display objects, sfr_gfx_06)
    UInt32           Flags2;                   // +0x3494 (sfr_gfx_06b)
    UByte            Unrecovered_3498[0x58];   // +0x3498
    void*            RenderContext[1];         // +0x34f0 Render::Context (gfx_rendertree.h: the heap first), rest unrecovered

    ASString CreateNewInstanceName();          // exe 0x14256e710
    bool     SetLevelMovie(int level, DisplayObjContainer* psprite); // exe 0x142575f20

    // The movie's StateBag base (+0x10).
    StateBag* GetStateBag() const { return (StateBag*)&MovieBase_Unrecovered[2]; }
    MemoryHeap* GetMovieHeap() const { return pHeap; }

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
    // +0x2de0 is the drag state: the dragged character (pKeepAdvancingChar), then these.
    bool DragLockCenter() const       { return *((const bool*)this + 0x2de8); }
    bool DragBound() const            { return *((const bool*)this + 0x2de9); }
    const Render::PointF& DragBoundLT() const     { return *(const Render::PointF*)((const UByte*)this + 0x2dec); }
    const Render::PointF& DragBoundRB() const     { return *(const Render::PointF*)((const UByte*)this + 0x2df4); }
    const Render::PointF& DragCenterDelta() const { return *(const Render::PointF*)((const UByte*)this + 0x2dfc); }

    // Takes the keyboard focus off ch in every focus group (0x142574820).
    void ResetFocusForChar(InteractiveObject* ch);

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
};

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

}} // namespace Scaleform::GFx

#endif
