// Recovered Scaleform 4.1.18 GFx: Button, the instance of a SWF button (its up / over / down / hit state characters
// and the mouse state machine). Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder
// members or virtuals.
//
// Button is 0x170 bytes (ctor 0x1425dd840, vftable 0x14318c238 with 115 slots, LogBase vftable 0x14318c5d0); it only
// overrides InteractiveObject virtuals. Bodies: sfr_gfx_05c.cpp (GFx_Button, 0x1425dd840..).
#ifndef MS2_SF_GFX_BUTTON_H
#define MS2_SF_GFX_BUTTON_H

#include "gfx_interactiveobject.h"
#include "gfx_buttondef.h"

namespace Scaleform { namespace Render {
class TreeContainer;
}}

namespace Scaleform { namespace GFx {

// The AVM half of a button: slots 23..26 after the AvmInteractiveObjBase ones.
class AvmButtonBase : public AvmInteractiveObjBase
{
public:
    // Creates the state characters once the button is loaded.
    virtual void CreateCharacters() = 0;
    virtual bool OnMouseEvent(const EventId& event) = 0;
    virtual bool OnButtonKeyEvent(const EventId& id, int* pkeyMask) = 0;
    // Shows the characters of the new mouse state.
    virtual void SwitchState(ButtonRecord::MouseState) = 0;
};

class Button : public InteractiveObject
{
public:
    enum ButtonState
    {
        Up,
        Over,
        Down,
        Hit,

        StatesCount
    };

    // A state character and the record it was created from.
    struct CharToRec
    {
        Ptr<DisplayObjectBase> Char;
        const ButtonRecord*    Record;
    };
    typedef ArrayLH<CharToRec> StateCharArray;

protected:
    enum MouseFlags
    {
        IDLE      = 0,
        FLAG_OVER = 1,
        FLAG_DOWN = 2
    };

    struct StateCharacters
    {
        Ptr<Render::TreeContainer> pRenNode;    // the state's container in the render tree
        StateCharArray             Characters;
    };

    ButtonDef*               pDef;                 // +0xd8
    StateCharacters          States[StatesCount];  // +0xe0
    int                      LastMouseFlags;       // +0x160
    int                      mMouseFlags;          // +0x164
    ButtonRecord::MouseState MouseState;           // +0x168

public:
    Button(ButtonDef* def, MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot, InteractiveObject* parent,
           ResourceId id);
    ~Button();

    virtual void            AdvanceFrame(bool nextFrame, float framePos);
    virtual void            OnEventLoad();
    virtual CharacterDef::CharacterDefType GetType() const;
    virtual RectF           GetBounds(const Matrix& transform) const;
    virtual CharacterDef*   GetCharacterDef() const;
    virtual RectF           GetRectBounds(const Matrix& transform) const;
    virtual TopMostResult   GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr);
    virtual void            OnEventUnload();
    virtual bool            PointTestLocal(const PointF& pt, UByte hitTestMask = 0) const;
    virtual void            Restart();
    virtual void            SetStateChangeFlags(UByte flags);

    virtual int             CheckAdvanceStatus(bool playingNow);
    // The hit state's bounds, else the down, over or up state's.
    virtual RectF           GetFocusRect() const;
    // True when a handler ran.
    virtual bool            OnMouseEvent(const EventId& event);
    virtual void            OnGettingKeyboardFocus(unsigned controllerIdx, FocusMovedType fmt);
    virtual bool            OnKeyEvent(const EventId& id, int* pkeyMask);
    virtual bool            OnLosingKeyboardFocus(InteractiveObject*, unsigned controllerIdx, FocusMovedType);
    virtual void            PropagateMouseEvent(const EventId& event);
    virtual void            PropagateNoAdvanceGlobalFlag();
    virtual void            PropagateNoAdvanceLocalFlag();
    virtual void            SetVisible(bool visible);
    virtual void            RemoveDisplayObject(DisplayObjectBase* ch);

    void CreateCharacters();

    AvmButtonBase* GetAvmButton() const { return GetAvmObjImpl()->ToAvmButttonBase(); }
    ButtonDef*     GetButtonDef() const { return pDef; }

    // Bounds of one state character, and of a whole state.
    RectF GetBoundsOfRecord(const Matrix& transform, DisplayObjectBase* pch) const;
    RectF GetBoundsOfState(const Matrix& transform, ButtonState state) const;
    // A state character's bounds without its strokes.
    RectF GetRectBounds(const Matrix& transform, DisplayObjectBase* pch) const;

    const StateCharacters& GetCharacters(ButtonRecord::MouseState mouseState) const
    {
        return States[GetButtonState(mouseState)];
    }
    const StateCharacters& GetCharacters(ButtonState buttonState) const { return States[buttonState]; }
    StateCharacters&       GetCharacters(ButtonState buttonState)       { return States[buttonState]; }
    Render::TreeContainer* GetStateRenderContainer(ButtonState buttonState) const
    {
        return States[buttonState].pRenNode;
    }
    Ptr<Render::TreeContainer> CreateStateRenderContainer(ButtonState buttonState);

    void SwitchState();
    void UnloadCharactersForState(ButtonState state);
    void ClearRenderTreeForState(ButtonState state);

    ButtonState        GetCurrentState() const { return GetButtonState(MouseState); }
    static ButtonState GetButtonState(ButtonRecord::MouseState mouseState);
};

}} // namespace Scaleform::GFx

#endif
