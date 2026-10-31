// Recovered Scaleform 4.1.18 GFx: Sprite, the movie clip instance (a timeline played over a display list), and its
// active sound bookkeeping. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members
// or virtuals.
//
// Sprite is 0x148 bytes (ctor 0x1425d9760, vftable 0x14318be38 with 126 slots, LogBase vftable 0x14318c228);
// slots 121..125 are its own. Bodies: sfr_gfx_05b.cpp (GFx_Sprite, 0x1425d9760..).
#ifndef MS2_SF_GFX_SPRITE_H
#define MS2_SF_GFX_SPRITE_H

#include "gfx_displayobjcontainer.h"
#include "gfx_drawingcontext.h"
#include "../sound/sound_renderer.h"

namespace Scaleform { namespace GFx {

class TimelineDef;
class SpriteDef;
class FontHandle;
class FontResource;
class StaticTextSnapshotData;

// Allocation stat of the movie view objects other than clips.
enum { StatMV_Other_Mem = 0x147 };

// DrawingContext, the drawing API state of a clip, is declared in gfx_drawingcontext.h.

// Mouse state of a clip that acts as a button.
enum SpriteMouseState
{
    MouseState_Up,
    MouseState_Down,
    MouseState_Over
};

class Sprite : public DisplayObjContainer
{
public:
    // One playing sound started by this clip (an event sound or an AS Sound object's).
    struct ActiveSoundItem : public RefCountBaseNTS<ActiveSoundItem, StatMV_Other_Mem>
    {
        Ptr<Sound::SoundChannel> pChannel;     // +0x10
        ASSoundIntf*             pSoundObject; // +0x18 the AS Sound object that started it, if any
        SoundResource*           pResource;    // +0x20

        ActiveSoundItem() : pSoundObject(0), pResource(0) {}
        virtual ~ActiveSoundItem();
    };

    // Created on first use: the clip's sound transform and its sounds. 0x48 bytes.
    struct ActiveSounds : public NewOverrideBase<StatMV_Other_Mem>
    {
        int                             Volume;       // +0x00 percent
        int                             SubVolume;    // +0x04
        int                             Pan;          // +0x08 -100..100
        ArrayLH<Ptr<ActiveSoundItem> >  Sounds;       // +0x10
        ArrayLH<ASSoundIntf*>           ASSounds;     // +0x28 Sound objects attached to the clip
        Ptr<Sound::SoundChannel>        pStreamSound; // +0x40

        ActiveSounds();
        ~ActiveSounds();
    };

    // Flags (+0x140).
    enum FlagMasks
    {
        Flags_UpdateFrame       = 0x01,
        Flags_HasLoopedPriv     = 0x02,
        Flags_Unloaded          = 0x04,
        Flags_OnEventLoadCalled = 0x08,
        Flags_LoadedSeparately  = 0x10,
        Flags_LockRoot          = 0x20,
        Flags_SpriteDef         = 0x40,
        Flags_OnLoadReqd        = 0x80
    };

    Sprite(TimelineDef* pdef, MovieDefImpl* pdefImpl, ASMovieRootBase* pr, InteractiveObject* parent,
           ResourceId id, bool loadedSeparately = false);
    virtual ~Sprite();

    virtual void            SetVisible(bool visible);
    virtual void            ForceShutdown();
    virtual RectF           GetBounds(const Matrix& t) const;
    virtual RectF           GetRectBounds(const Matrix& t) const;
    virtual bool            PointTestLocal(const PointF& pt, UByte hitTestMask = 0) const;
    virtual TopMostResult   GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr);
    virtual CharacterDef*   GetCharacterDef() const;
    virtual InteractiveObject* GetTopParent(bool ignoreLockRoot = false) const;
    virtual Render::TreeContainer* GetRenderContainer();
    virtual void            Restart();
    virtual void            AdvanceFrame(bool nextFrame, float framePos = 0.0f);
    virtual bool            OnEvent(const EventId& id);
    virtual bool            OnUnloading();
    virtual void            OnEventUnload();
    virtual CharacterDef::CharacterDefType GetType() const;
    virtual DrawingContext* GetDrawingContext();
    virtual bool            IsFocusEnabled(FocusMovedType fmt = GFx_FocusMovedByKeyboard) const;
    virtual void            OnGettingKeyboardFocus(unsigned controllerIdx, FocusMovedType fmt);
    virtual bool            OnLosingKeyboardFocus(InteractiveObject* newFocusCh, unsigned controllerIdx,
                                                  FocusMovedType fmt = GFx_FocusMovedByKeyboard);
    virtual RectF           GetFocusRect() const;
    virtual void            CloneInternalData(const InteractiveObject* src);
    virtual void            SetPause(bool pause);
    virtual bool            OnKeyEvent(const EventId& id, int* pkeyMask);
    virtual bool            OnMouseEvent(const EventId& id);
    virtual int             CheckAdvanceStatus(bool playingNow);
    virtual void            PropagateNoAdvanceGlobalFlag();
    virtual void            PropagateNoAdvanceLocalFlag();
    virtual unsigned        GetCurrentFrame() const;
    virtual bool            GetLabeledFrame(const char* plabel, unsigned* frameNumber, bool translateNumbers = true);
    virtual void            GotoFrame(unsigned targetFrameNumber);
    virtual unsigned        GetLoadingFrame() const;
    virtual void            ExecuteFrame0Events();
    virtual bool            HasLooped() const;
    virtual void            SetPlayState(PlayState state);
    virtual PlayState       GetPlayState() const;
    virtual void            StopActiveSounds();
    virtual void            StopActiveSounds(SoundResource* pres);
    virtual void            StopActiveSounds(ASSoundIntf* psndobj);
    virtual DisplayObjectBase* AddDisplayObject(const CharPosInfo& pos, const ASString& name,
                                                const ArrayLH<SwfEvent*, StatMD_Tags_Mem>* peventHandlers,
                                                const void* pinitSource, unsigned initSourceLen,
                                                unsigned long addFlags, CharacterCreateInfo* pcharCreateOverride,
                                                InteractiveObject* origChar);
    virtual void            ExecuteImportedInitActions(MovieDef* psourceMovie);
    virtual Sprite*         GetHitArea() const;
    virtual Sprite*         GetHitAreaHolder() const;
    virtual void            CreateAndReplaceDisplayObject(const CharPosInfo& pos, const ASString& name,
                                                          DisplayObjectBase** newChar);

    virtual void            SetName(const ASString& name);
    virtual void            OnEventXmlsocketOnxml();
    virtual void            OnEventIntervalTimer();
    virtual void            OnEventLoadProgress();
    virtual void            OnIntervalTimer(void* timer);

    // Sound.
    void                 AddActiveSound(Sound::SoundChannel* pchan, ASSoundIntf* psnd, SoundResource* pres);
    void                 AttachActiveSound(ActiveSoundItem* item);
    ActiveSoundItem*     ReleaseActiveSound(Sound::SoundChannel* pchan);
    void                 AttachSoundObject(ASSoundIntf* psnd);
    void                 DetachSoundObject(ASSoundIntf* psnd);
    bool                 IsSoundPlaying(ASSoundIntf* psnd);
    float                GetActiveSoundPosition(ASSoundIntf* psnd);
    int                  GetSoundVolume();
    int                  GetSoundPan();
    void                 SetSoundVolume(int volume, int subVolume);
    void                 SetSoundPan(int pan);
    float                GetRealSoundVolume();
    float                GetRealSubSoundVolume();
    float                GetRealSoundPan();
    Sound::SoundChannel* GetStreamingSound() const;
    void                 SetStreamingSound(Sound::SoundChannel* pchan);
    void                 UpdateActiveSoundVolume();
    void                 UpdateActiveSoundPan();

    // Timeline.
    void     ExecuteFrameTags(unsigned frame);
    void     IncrementFrameAndCheckForLoop();
    // Drops the finished sounds after an advance, running their AS onSoundComplete (exe 0x1425da3c0).
    void     CheckActiveSounds();
    bool     GotoLabeledFrame(const char* label, int offset);
    void     DefaultOnEventLoad();
    int      GetLevel() const;
    bool     IsLevelMovie() const;
    UInt32   GetBytesLoaded() const;
    void     SetLoadedSeparately(bool v = true);
    void     SetRootNodeLoadingStat(unsigned bytesLoaded, unsigned loadingFrame);
    void     SetHitArea(Sprite* phitArea);
    void     SetIMECandidateListFont(FontResource* pfont);
    void     SetIMECandidateListFont(FontHandle* pfont);
    void     GetTextSnapshot(StaticTextSnapshotData* pdata) const;

    AvmSpriteBase* GetAvmSprite() const;
    bool           MustBeInPlaylist() const;

    bool IsLoadedSeparately() const { return (Flags & Flags_LoadedSeparately) != 0; }
    void SetUpdateFrame(bool v = true)   { Flags = (UByte)((v) ? (Flags | Flags_UpdateFrame)   : (Flags & (~Flags_UpdateFrame))); }
    void SetHasLoopedPriv(bool v = true) { Flags = (UByte)((v) ? (Flags | Flags_HasLoopedPriv) : (Flags & (~Flags_HasLoopedPriv))); }
    bool IsLockRoot() const         { return (Flags & Flags_LockRoot) != 0; }

    Ptr<TimelineDef>           pDef;            // +0x110 Resource AddRef / Release
    PlayState                  PlayStatePriv;   // +0x118
    unsigned                   CurrentFrame;    // +0x11c
    ActiveSounds*              pActiveSounds;   // +0x120
    Ptr<DrawingContext>        pDrawingAPI;     // +0x128
    Ptr<CharacterHandle>       pHitAreaHandle;  // +0x130
    Sprite*                    pHitAreaHolder;  // +0x138
    UByte                      Flags;           // +0x140
    SByte                      FocusEnabled;    // +0x141 Bool3W: 0 undefined, 1 true, 2 false
    SpriteMouseState           MouseStatePriv;  // +0x144

public:
    // (appended for the sprite stubs, sfr_gfx_05b) the renderer hint the AS2 rendererString member sets; 4.1.18
    // ignores it (exe 0x1425dcf30)
    void SetRendererString(ASString str);
    // (appended for sfr_as2_07) the rendererFloat / rendererMatrix hints, ignored too (exe 0x1425dcf10 / 0x1425dcf20,
    // folded into other empty functions)
    void SetRendererFloat(float v);
    void SetRendererMatrix(float* pdata, unsigned count);
};

// The AVM half of a sprite: slots 24..34 (CloneInternalData overrides the AvmInteractiveObjBase slot).
class AvmSpriteBase : public AvmDisplayObjContainerBase
{
public:
    virtual DisplayObjectBase* AddDisplayObject(const CharPosInfo& pos, const ASString& name,
                                                const ArrayLH<SwfEvent*, StatMD_Tags_Mem>* peventHandlers,
                                                const void* pinitSource, unsigned createFrame,
                                                unsigned long addFlags, CharacterCreateInfo* pcharCreateOverride,
                                                InteractiveObject* origChar) = 0;
    virtual void AdvanceFrame(bool nextFrame, float framePos) = 0;
    virtual void CloneInternalData(const InteractiveObject* src) = 0;
    virtual void ExecuteFrame0Events() = 0;
    virtual void ExecuteFrameTags(unsigned frame) = 0;
    virtual void ExecuteInitActionFrameTags(unsigned frame) = 0;
    virtual void ForceShutdown() = 0;
    virtual int  GetLevel() const { return -1; }
    virtual bool IsLevelMovie() const = 0;
    virtual bool MustBeInPlaylist() const { return 0; }
    virtual void SetHitAreaNotify(Sprite* phitArea) {}
    virtual bool CheckCandidateListLevel(int) const { return false; }
};

inline AvmSpriteBase* Sprite::GetAvmSprite() const { return GetAvmObjImpl()->ToAvmSpriteBase(); }

// The AS3 sprite creation allocates the Sprite with its AvmSprite, constructed at +0x148.
static_assert(sizeof(Sprite) == 0x148, "Sprite size");

}} // namespace Scaleform::GFx

#endif
