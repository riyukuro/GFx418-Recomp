// Recovered Scaleform 4.1.18 GFx: InteractiveObject, the display objects that take focus, mouse and keyboard
// events and sit on the movie's advance (play) list. Shared header of the src/ms2/scaleform units (sfr lane):
// append, do not reorder members or virtuals.
//
// 0xd8 bytes (ctor 0x1425f7c90, vftable 0x14318df70, LogBase vftable 0x14318e308). New virtuals are slots 79..114
// of the Sprite vftable; overloads appear in the reverse of their declaration order, as MSVC emits them.
#ifndef MS2_SF_GFX_INTERACTIVEOBJECT_H
#define MS2_SF_GFX_INTERACTIVEOBJECT_H

#include "gfx_displayobject.h"

namespace Scaleform { namespace GFx {

class SoundResource;
class ASSoundIntf;

enum PlayState
{
    State_Playing,
    State_Stopped
};

// How the focus got moved.
enum FocusMovedType
{
    GFx_FocusMovedByMouse    = 1,
    GFx_FocusMovedByKeyboard = 2,
    GFx_FocusMovedByAS       = 3
};

class InteractiveObject : public DisplayObject
{
public:
    enum FocusEventType
    {
        KillFocus,
        SetFocus
    };

    // Flags (+0xb8). The two-bit fields hold 0 for undefined, 1 or 2 for false and 3 for true.
    enum FlagMasks
    {
        Mask_NoAdvanceLocal          = 0x000004,
        Mask_NoAdvanceGlobal         = 0x000008,
        Mask_Enabled                 = 0x000010,
        Mask_TabEnabled              = 0x000060,
        Mask_FocusRect               = 0x000180,
        Mask_UseHandCursor           = 0x000600,
        Mask_HitTestDisable          = 0x000800,
        Mask_MouseDisabled           = 0x001000,
        Mask_MouseChildrenDisabled   = 0x002000,
        Mask_TrackAsMenu             = 0x004000,
        Mask_TabChildrenDisabled     = 0x008000,
        Mask_ChangedFlags            = 0x0f0000,
        Mask_ReqPartialAdvance       = 0x100000,
        Mask_OptAdvList              = 0x200000,
        Mask_MarkedToRemoveFromOptAdvList = 0x400000,
        Mask_OptAdvListMarker        = 0x800000
    };

    InteractiveObject(MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot, InteractiveObject* pparent,
                      ResourceId id);   // 0x1425f7c90
    virtual ~InteractiveObject();

protected:
    virtual Ptr<Render::TreeNode> CreateRenderNode(Render::ContextImpl::Context& context) const;
public:
    virtual MovieDefImpl*   GetResourceMovieDef() const;
    virtual void            SetBlendMode(Render::BlendMode mode);
    virtual Render::TreeContainer* GetRenderContainer();
    virtual void            OnEventLoad();
    virtual void            OnEventUnload();
    virtual bool            OnUnloading();
    virtual void            SetStateChangeFlags(UByte flags);
    virtual UByte           GetStateChangeFlags() const;
    virtual void            DoDisplayCallback();

    virtual bool            IsFocusAllowed(MovieImpl* proot, unsigned controllerIdx) const;
    virtual bool            IsFocusAllowed(MovieImpl* proot, unsigned controllerIdx);
    virtual bool            IsTabable() const;
    virtual bool            IsFocusRectEnabled() const;
    virtual bool            IsFocusEnabled(FocusMovedType fmt = GFx_FocusMovedByKeyboard) const;
    virtual void            OnFocus(FocusEventType event, InteractiveObject* oldOrNewFocusCh, unsigned controllerIdx,
                                    FocusMovedType fmt);
    virtual void            OnGettingKeyboardFocus(unsigned controllerIdx, FocusMovedType fmt);
    virtual bool            OnLosingKeyboardFocus(InteractiveObject* newFocusCh, unsigned controllerIdx,
                                                  FocusMovedType fmt = GFx_FocusMovedByKeyboard);
    virtual RectF           GetFocusRect() const;
    virtual void            CloneInternalData(const InteractiveObject* src);
    virtual void            SetPause(bool pause);
    virtual bool            OnKeyEvent(const EventId& id, int* pkeyMask);
    virtual bool            OnCharEvent(UInt32 wcharCode, unsigned controllerIdx);
    virtual bool            OnMouseWheelEvent(int mwDelta);
    virtual void            PropagateMouseEvent(const EventId& id);
    virtual bool            OnMouseEvent(const EventId& id);
    virtual void            PropagateKeyEvent(const EventId& id, int* pkeyMask);
    virtual void            SetDisplayCallback(void (SF_CDECL* callback)(void*), void* userPtr);
    // 1: keep advancing, 0: off the play list, -1: no change (the caller decides).
    virtual int             CheckAdvanceStatus(bool playingNow);
    virtual void            PropagateNoAdvanceGlobalFlag();
    virtual void            PropagateNoAdvanceLocalFlag();
    virtual void            PropagateFocusGroupMask(unsigned mask);
    virtual unsigned        GetCurrentFrame() const;
    virtual bool            GetLabeledFrame(const char* plabel, unsigned* frameNumber, bool translateNumbers = true);
    virtual const String*   GetFrameLabel(unsigned frame, unsigned* exactFrame = 0);
    virtual void            GotoFrame(unsigned targetFrameNumber);
    virtual unsigned        GetLoadingFrame() const;
    virtual void            ExecuteFrame0Events();
    virtual bool            HasLooped() const;
    virtual void            SetPlayState(PlayState state);
    virtual PlayState       GetPlayState() const;
    virtual unsigned        GetCursorType() const;
    virtual void            RemoveDisplayObject(DisplayObjectBase* ch);
    virtual void            StopActiveSounds();
    virtual void            StopActiveSounds(SoundResource* pres);
    virtual void            StopActiveSounds(ASSoundIntf* psndobj);

    InteractiveObject*  pPlayNext;     // +0x90
    InteractiveObject*  pPlayPrev;     // +0x98
    union
    {
        InteractiveObject* pPlayNextOpt;  // +0xa0 on the optimized play list
        InteractiveObject* pNextUnloaded; //       on the unloaded list
    };
    InteractiveObject*  pPlayPrevOpt;  // +0xa8
    Ptr<MovieDefImpl>   pDefImpl;      // +0xb0 the movie whose resources this object binds
    UInt32              Flags;         // +0xb8
    SInt16              TabIndex;      // +0xbc
    UInt16              FocusGroupMask;// +0xbe
    UByte               RollOverCnt;   // +0xc0
    void                (SF_CDECL* pDisplayCallback)(void*); // +0xc8
    void*               DisplayCallbackUserPtr;               // +0xd0

    InteractiveObject* GetParent() const { return pParent; }

    // Puts the object on (or takes it off) the movie's optimized advance list after its advance needs changed
    // (instances for Sprite 0x1424d2820, ...).
    template<class T> void ModifyOptimizedPlayListLocal();
    void RemoveFromPlayList();   // 0x1425f8a20
    void AddToOptimizedPlayList();   // 0x1425f7e30
    // On the optimized advance list and not about to leave it.
    bool IsInPlayList() const
    {
        return (Flags & Mask_OptAdvList) && !(Flags & Mask_MarkedToRemoveFromOptAdvList);
    }

    bool IsNoAdvanceLocalFlagSet() const  { return (Flags & Mask_NoAdvanceLocal) != 0; }
    bool IsNoAdvanceGlobalFlagSet() const { return (Flags & Mask_NoAdvanceGlobal) != 0; }
    bool IsAdvanceDisabled() const        { return (Flags & (Mask_NoAdvanceLocal | Mask_NoAdvanceGlobal)) != 0; }
    bool IsEnabledFlagSet() const         { return (Flags & Mask_Enabled) != 0; }
    void SetNoAdvanceLocalFlag(bool v = true)  { if (v) Flags |= Mask_NoAdvanceLocal; else Flags &= ~Mask_NoAdvanceLocal; }
    void SetNoAdvanceGlobalFlag(bool v = true) { if (v) Flags |= Mask_NoAdvanceGlobal; else Flags &= ~Mask_NoAdvanceGlobal; }

    // Tab order collection (the parameter block is filled by the AVM side).
    struct FillTabableParams;

    AvmInteractiveObjBase* GetAvmIntObj() const { return GetAvmObjImpl()->ToAvmInteractiveObjBase(); }
};

// The AVM half of an interactive object: slots 13..22 after the AvmDisplayObjBase ones.
class AvmInteractiveObjBase : public AvmDisplayObjBase
{
public:
    // The clip has button handlers (onPress, ...) and so takes button events.
    virtual bool     ActsAsButton() const = 0;
    virtual unsigned GetCursorType() const = 0;
    virtual void     CloneInternalData(const InteractiveObject* src) = 0;
    virtual void     CopyPhysicalProperties(const InteractiveObject* poldChar) = 0;
    virtual void     OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                             unsigned controllerIdx, FocusMovedType fmt) = 0;
    virtual void     OnGettingKeyboardFocus(unsigned controllerIdx, FocusMovedType fmt) = 0;
    virtual bool     OnKeyEvent(const EventId& id, int* pkeyMask) = 0;
    // A false return keeps the focus where it is.
    virtual bool     OnLosingKeyboardFocus(InteractiveObject* newFocusCh, unsigned controllerIdx,
                                           FocusMovedType fmt = GFx_FocusMovedByKeyboard) = 0;
    virtual bool     IsFocusEnabled(FocusMovedType fmt = GFx_FocusMovedByKeyboard) const = 0;
    virtual bool     IsTabable() const = 0;
};

}} // namespace Scaleform::GFx

#endif
