// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_Button, the button instance:
// its state characters (created by the AVM side), their bounds and hit tests, and the mouse and keyboard state
// machine that picks the state shown.
// MS2-UNIT: sfr_gfx_05c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425dd840-0x1425df980 .text$mn
// MS2-PIN: ??_7Button@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@2@@ 0x14318c238
// MS2-PIN: ??_7Button@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@12@@ 0x14318c5d0

#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/gfx_button.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_input.h"
#include "../include/gfx/gfx_sound.h"

namespace Scaleform { namespace GFx {

using Render::TreeContainer;

inline bool MovieImpl::IsFocused(const InteractiveObject* ch, unsigned controllerIdx) const
{
    Ptr<InteractiveObject> focused = FocusGroups[FocusGroupIndexes[controllerIdx]].LastFocused;
    return focused.GetPtr() == ch;
}

// The state of each mouse (4 mice), 0x50 bytes apiece from MovieImpl +0x1260.
static inline MouseState* GetMouseStateOf(MovieImpl* proot, unsigned mouseIndex)
{
    if (mouseIndex >= 4)
        return 0;
    return reinterpret_cast<MouseState*>(reinterpret_cast<UByte*>(proot) + 0x1260) + mouseIndex;
}

// MovieImpl::Advance (vftable +0xb8; MovieImpl's vtable is not recovered).
typedef float (*MovieAdvanceFn)(MovieImpl*, float deltaT, unsigned frameCatchUpCount, bool capture);

// @0x1425dd840
// MS2-FUNCTIONAL: /GS frame layout, the exe keeps the RectF temporary next to the cookie
Button::Button(ButtonDef* def, MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot, InteractiveObject* parent,
               ResourceId id)
    : InteractiveObject(pbindingDefImpl, pasRoot, parent, id), pDef(def), LastMouseFlags(IDLE), mMouseFlags(IDLE),
      MouseState(ButtonRecord::MouseUp)
{
    SetScale9Grid(def->GetScale9Grid());
    SetTrackAsMenuFlag(pDef->Menu);
}

// @0x1425dda50
Button::~Button() {}

// @0x1425ddbd0
void Button::AdvanceFrame(bool nextFrame, float)
{
    if (nextFrame && HasAvmObject())
    {
        EventId enterFrame(EventId::Event_EnterFrame);
        GetAvmButton()->OnEvent(enterFrame);
    }
}

// A button keeps advancing for its onEnterFrame handlers unless its advance is off.
// @0x1425ddc20
int Button::CheckAdvanceStatus(bool playingNow)
{
    int  rv              = 0;
    // !CanAdvanceChar(): marked for removal (the exe tests the inverted flag byte)
    bool advanceDisabled = IsAdvanceDisabled() || !((UByte)~((UByte)DisplayObjectBase::Flags >> 6) & 1);
    if (!advanceDisabled)
        rv = !playingNow;
    else if (playingNow)
        rv = -1;
    return rv;
}

// Takes the state's characters out of the render tree, and the state's container out of the button's.
// @0x1425ddc50
void Button::ClearRenderTreeForState(ButtonState state)
{
    if (States[state].pRenNode)
    {
        States[state].pRenNode->Remove(0, States[state].pRenNode->GetReadOnlyData()->Children.GetSize());
        if (States[state].pRenNode->GetParent())
            GetRenderContainer()->Remove(0, 1);
    }
}

// @0x1425ddd20
void Button::CreateCharacters()
{
    if (HasAvmObject())
        GetAvmButton()->CreateCharacters();
}

// @0x1425ddd50
Ptr<TreeContainer> Button::CreateStateRenderContainer(ButtonState buttonState)
{
    States[buttonState].pRenNode = *GetRenderContext().CreateEntry<TreeContainer>();
    return States[buttonState].pRenNode;
}

// @0x1425ddf50
RectF Button::GetBoundsOfRecord(const Matrix& transform, DisplayObjectBase* pch) const
{
    RectF  bounds(0);
    Matrix m;
    if (pch)
    {
        m = transform;
        m.Prepend(pch->GetMatrix());
        bounds = pch->GetBounds(m);
    }
    return bounds;
}

// @0x1425de3b0
RectF Button::GetRectBounds(const Matrix& transform, DisplayObjectBase* pch) const
{
    RectF  bounds(0);
    Matrix m;
    if (pch)
    {
        m = transform;
        m.Prepend(pch->GetMatrix());
        bounds = pch->GetRectBounds(m);
    }
    return bounds;
}

// The bounds of the current state's characters.
// @0x1425dde20
RectF Button::GetBounds(const Matrix& transform) const
{
    RectF bounds(0);
    RectF tempRect;
    bool  boundsInit = false;

    const StateCharArray& chars = GetCharacters(MouseState).Characters;
    for (UPInt i = 0; i < chars.GetSize(); ++i)
    {
        DisplayObjectBase* pch = chars[i].Char;
        tempRect = GetBoundsOfRecord(transform, pch);
        if (!tempRect.IsNull())
        {
            if (!boundsInit)
            {
                bounds     = tempRect;
                boundsInit = true;
            }
            else
                bounds.Union(tempRect);
        }
    }
    return bounds;
}

// @0x1425de520
RectF Button::GetRectBounds(const Matrix& transform) const
{
    RectF bounds(0);
    RectF tempRect;
    bool  boundsInit = false;

    const StateCharArray& chars = GetCharacters(MouseState).Characters;
    for (UPInt i = 0; i < chars.GetSize(); ++i)
    {
        DisplayObjectBase* pch = chars[i].Char;
        tempRect = GetRectBounds(transform, pch);
        if (!tempRect.IsNull())
        {
            if (!boundsInit)
            {
                bounds     = tempRect;
                boundsInit = true;
            }
            else
                bounds.Union(tempRect);
        }
    }
    return bounds;
}

// @0x1425de0c0
RectF Button::GetBoundsOfState(const Matrix& transform, ButtonState state) const
{
    RectF bounds(0);
    RectF tempRect;

    const StateCharArray& chars = States[state].Characters;
    for (UPInt i = 0; i < chars.GetSize(); ++i)
    {
        DisplayObjectBase* pch = chars[i].Char;
        tempRect = GetBoundsOfRecord(transform, pch);
        if (!tempRect.IsNull())
        {
            if (bounds.IsNull())
                bounds = tempRect;
            else
                bounds.Union(tempRect);
        }
    }
    return bounds;
}

// @0x1425de200
Button::ButtonState Button::GetButtonState(ButtonRecord::MouseState mouseState)
{
    ButtonState i = Up;
    switch (mouseState)
    {
    case ButtonRecord::MouseUp:   i = Up; break;
    case ButtonRecord::MouseDown: i = Down; break;
    case ButtonRecord::MouseOver: i = Over; break;
    }
    return i;
}

// @0x1425de220
CharacterDef* Button::GetCharacterDef() const
{
    return pDef;
}

// @0x1425de230
RectF Button::GetFocusRect() const
{
    Matrix m;
    RectF  tempRect;
    if (!(tempRect = GetBoundsOfState(m, Hit)).IsNull())
        return tempRect;
    else if (!(tempRect = GetBoundsOfState(m, Down)).IsNull())
        return tempRect;
    else if (!(tempRect = GetBoundsOfState(m, Over)).IsNull())
        return tempRect;
    else if (!(tempRect = GetBoundsOfState(m, Up)).IsNull())
        return tempRect;
    return GetBounds(m);
}

// The hit state's shapes decide; LocalPt is left for the search to continue when none is hit.
// @0x1425de780
Button::TopMostResult Button::GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr)
{
    pdescr->pResult = 0;
    if (!GetVisible())
        return TopMost_FoundNothing;
    if (pdescr->pIgnoreMC == this)
        return TopMost_FoundNothing;
    if (!IsFocusAllowed(GetMovieImpl(), pdescr->ControllerIdx))
        return TopMost_FoundNothing;

    PointF p(PointF::NoInit);
    if (!TransformPointToLocalAndCheckBounds(&p, pt))
        return TopMost_FoundNothing;

    const StateCharArray& chars = States[Hit].Characters;
    for (UPInt i = 0; i < chars.GetSize(); ++i)
    {
        DisplayObjectBase* pcharacter = chars[i].Char;
        if (pcharacter)
        {
            PointF subp(PointF::NoInit);
            pcharacter->TransformPointToLocal(&subp, p);
            if (pcharacter->PointTestLocal(subp, 1))
            {
                pdescr->pResult = this;
                return TopMost_Found;
            }
        }
    }
    pdescr->LocalPt.SetPoint(p.x, p.y);
    return TopMost_Continue;
}

// @0x1425de8b0
CharacterDef::CharacterDefType Button::GetType() const
{
    return CharacterDef::Button;
}

// @0x1425de8e0
void Button::OnEventLoad()
{
    InteractiveObject::OnEventLoad();
    CreateCharacters();
}

// @0x1425de920
void Button::OnEventUnload()
{
    SetUnloading();
    UnloadCharactersForState(Up);
    UnloadCharactersForState(Over);
    UnloadCharactersForState(Down);
    UnloadCharactersForState(Hit);
    InteractiveObject::OnEventUnload();
}

// The keyboard bringing the focus acts as a rollOver (key code Tab).
// @0x1425de970
void Button::OnGettingKeyboardFocus(unsigned controllerIdx, FocusMovedType fmt)
{
    if (fmt == GFx_FocusMovedByKeyboard)
        OnMouseEvent(EventId(EventId::Event_RollOver, 9, 0, 0, UByte(controllerIdx)));
}

// A key press event of key code with the character it types.
static inline EventId KeyPressEvent(UInt32 keyCode, UByte ascii)
{
    EventId evt(EventId::Event_KeyPress);
    evt.KeyCode       = keyCode;
    evt.AsciiCode     = ascii;
    evt.KeyboardIndex = 0;
    return evt;
}

// A two-bit extension flag: 0 undefined, 1 true, 2 false, 3 read as -1.
static inline int Get3WayFlag(UInt32 flags, unsigned shift)
{
    UInt32 v = (flags >> shift) & 3;
    return (v == 3) ? -1 : int(v);
}

// Key down also fires on(keyPress) once per key (pkeyMask bit 0x10000); Enter or Space on the keyboard-focused button
// presses and releases it, with a movie advance in between so that on(press) runs first.
// @0x1425de9c0
bool Button::OnKeyEvent(const EventId& id, int* pkeyMask)
{
    if (HasAvmObject())
        GetAvmButton()->OnButtonKeyEvent(id, pkeyMask);

    if (id.Id == EventId::Event_KeyDown)
    {
        if (!(*pkeyMask & 0x10000))
        {
            UByte ascii = id.AsciiCode;
            if (!id.AsciiCode)
            {
                if (id.WcharCode && id.WcharCode >= 32 && id.WcharCode < 128)
                    ascii = (UByte)id.WcharCode;
                else if (id.KeyCode >= 32)
                    ascii = id.ConvertKeyCodeToAscii();
            }
            if (OnMouseEvent(KeyPressEvent(id.KeyCode, ascii)))
                *pkeyMask |= 0x10000;
        }

        MovieImpl* proot         = GetMovieImpl();
        unsigned   controllerIdx = id.KeyboardIndex;
        if (proot->IsFocused(this, controllerIdx) && proot->IsFocusRectShown(controllerIdx) &&
            (id.KeyCode == 13 || id.KeyCode == 32))
        {
            if (IsFocusRectEnabled() || Get3WayFlag(proot->Flags, MovieImpl::Shift_AlwaysEnableKeyboardPress) == 1)
            {
                OnMouseEvent(EventId(EventId::Event_Press, 13, 0, 0, id.KeyboardIndex));

                Ptr<InteractiveObject> thisHolder = this;
                ((MovieAdvanceFn)(*(void***)proot)[23])(proot, 0, 0, true);

                OnMouseEvent(EventId(EventId::Event_Release, 13, 0, 0, id.KeyboardIndex));
            }
        }
    }
    return true;
}

// @0x1425dec20
bool Button::OnLosingKeyboardFocus(InteractiveObject*, unsigned controllerIdx, FocusMovedType)
{
    MovieImpl* proot = GetMovieImpl();
    if (proot->IsFocusRectShown(controllerIdx))
        OnMouseEvent(EventId(EventId::Event_RollOut, 9, 0, 0, UByte(controllerIdx)));
    return true;
}

// The mouse state follows the event (a left button held over a non-menu button keeps it as it is), the button
// sound of the transition plays and the state's characters are shown; then the AVM handlers run.
// @0x1425dec90
bool Button::OnMouseEvent(const EventId& evt)
{
    if (IsUnloading() || IsUnloaded())
        return false;
    bool handlerFound = false;

    if (evt.RollOverCnt == 0)   // only multiple mice set it
    {
        GFx::MouseState& ms = *GetMouseStateOf(GetMovieImpl(), evt.MouseIndex);

        switch (evt.Id)
        {
        case EventId::Event_RollOut:
        case EventId::Event_ReleaseOutside:
            MouseState = ButtonRecord::MouseUp;
            break;
        case EventId::Event_MouseUp:
        case EventId::Event_Release:
            MouseState = ButtonRecord::MouseOver;
            break;
        case EventId::Event_RollOver:
            if (GetTrackAsMenu() && (ms.GetPrevButtonsState() & GFx::MouseState::MouseButton_Left))
                MouseState = ButtonRecord::MouseDown;
            else if (!(ms.GetButtonsState() & GFx::MouseState::MouseButton_Left))
                MouseState = ButtonRecord::MouseOver;
            else
                return false;
            break;
        case EventId::Event_DragOut:
            if (GetTrackAsMenu())
                MouseState = ButtonRecord::MouseUp;
            else
                MouseState = ButtonRecord::MouseOver;
            break;
        case EventId::Event_MouseDown:
        case EventId::Event_Press:
        case EventId::Event_DragOver:
            MouseState = ButtonRecord::MouseDown;
            break;
        default:
            break;
        }

        if (pDef->pSound)
        {
            int bi;   // the button sound: rollOut, rollOver, press, release
            switch (evt.Id)
            {
            case EventId::Event_RollOut:  bi = 0; break;
            case EventId::Event_RollOver: bi = 1; break;
            case EventId::Event_Press:    bi = 2; break;
            case EventId::Event_Release:  bi = 3; break;
            default:                      bi = -1; break;
            }
            pDef->pSound->Play(this, bi);
        }

        SwitchState();
    }

    // Focus rollovers (they carry a key code) are not reported when the movie disables them.
    if (Get3WayFlag(GetMovieImpl()->Flags, MovieImpl::Shift_DisableFocusRolloverEvent) == 1 &&
        (evt.Id == EventId::Event_RollOver || evt.Id == EventId::Event_RollOut) && evt.KeyCode != 0)
        return handlerFound;

    if (HasAvmObject())
        handlerFound = GetAvmButton()->OnMouseEvent(evt);
    return handlerFound;
}

static inline bool HitTestDisabled(const InteractiveObject* ch) { return ((ch->Flags >> 11) & 1) != 0; }

// hitTestMask: 1 tests the hit state's shapes instead of the bounds, 2 skips invisible characters.
// @0x1425deeb0
// MS2-FUNCTIONAL: xmm register allocation of the inlined matrix inverse
bool Button::PointTestLocal(const PointF& pt, UByte hitTestMask) const
{
    if (HitTestDisabled(this))
        return false;
    if ((hitTestMask & 2) && !GetVisible())
        return false;

    if (!(DisplayObjectBase::Flags & Mask_Scale9GridExists))
    {
        if (!GetBounds(Matrix()).Contains(pt))
            return false;
        else if (!(hitTestMask & 1))
            return true;
    }

    const StateCharArray& chars = States[Hit].Characters;
    for (UPInt i = 0; i < chars.GetSize(); ++i)
    {
        DisplayObjectBase* ch = chars[i].Char;
        if (!ch)
            continue;
        if ((hitTestMask & 2) && !ch->GetVisible())
            continue;

        Matrix m = ch->GetMatrix();
        PointF p = m.TransformByInverse(pt);
        if (ch->PointTestLocal(p, hitTestMask))
            return true;
    }
    return false;
}

// A dragged button follows the mouse.
// @0x1425df160
void Button::PropagateMouseEvent(const EventId& evt)
{
    if (evt.Id == EventId::Event_MouseMove)
        DoMouseDrag();
    OnEvent(evt);
}

// InteractiveObject::ModifyOptimizedPlayList on a child; the exe tests the play list bits one at a time here.
static inline bool InOptAdvList(const InteractiveObject* ch)       { return ((ch->Flags >> 21) & 1) != 0; }
static inline bool MarkedToLeaveAdvList(const InteractiveObject* ch) { return ((ch->Flags >> 22) & 1) != 0; }

static inline void ModifyChildPlayList(InteractiveObject* ch)
{
    switch (ch->CheckAdvanceStatus(InOptAdvList(ch) && !MarkedToLeaveAdvList(ch)))
    {
    case 1:  ch->AddToOptimizedPlayList(); break;
    case -1: ch->MarkToRemoveFromOptimizedPlayList(); break;
    }
}

// @0x1425df1a0
void Button::PropagateNoAdvanceGlobalFlag()
{
    bool       actualValue = IsNoAdvanceGlobalFlagSet();
    MovieImpl* proot       = GetMovieImpl();
    if (!proot)
        return;

    for (UPInt s = 0; s < StatesCount; ++s)
    {
        StateCharArray& chars = States[s].Characters;
        for (UPInt i = 0; i < chars.GetSize(); ++i)
        {
            DisplayObjectBase* _ch = chars[i].Char;
            if (!_ch)
                continue;
            InteractiveObject* ch = _ch->IsInteractiveObject() ? static_cast<InteractiveObject*>(_ch) : 0;
            if (ch)
            {
                ch->SetNoAdvanceGlobalFlag(IsNoAdvanceGlobalFlagSet() || actualValue);
                ch->PropagateNoAdvanceGlobalFlag();
                ModifyChildPlayList(ch);
            }
        }
    }
}

// @0x1425df300
void Button::PropagateNoAdvanceLocalFlag()
{
    bool       actualValue = IsNoAdvanceLocalFlagSet();
    MovieImpl* proot       = GetMovieImpl();
    if (!proot)
        return;

    for (UPInt s = 0; s < StatesCount; ++s)
    {
        StateCharArray& chars = States[s].Characters;
        for (UPInt i = 0; i < chars.GetSize(); ++i)
        {
            DisplayObjectBase* _ch = chars[i].Char;
            if (!_ch)
                continue;
            InteractiveObject* ch = _ch->IsInteractiveObject() ? static_cast<InteractiveObject*>(_ch) : 0;
            if (ch)
            {
                ch->SetNoAdvanceLocalFlag(IsNoAdvanceLocalFlagSet() || actualValue);
                ch->PropagateNoAdvanceLocalFlag();
                ModifyChildPlayList(ch);
            }
        }
    }
}

// The removed child is unloaded and its slot cleared.
// @0x1425df460
void Button::RemoveDisplayObject(DisplayObjectBase* chToRemove)
{
    for (UPInt s = 0; s < StatesCount; ++s)
    {
        StateCharArray& chars = States[s].Characters;
        for (UPInt i = 0; i < chars.GetSize(); ++i)
        {
            DisplayObjectBase* _ch = chars[i].Char;
            if (!_ch)
                continue;
            InteractiveObject* ch = _ch->IsInteractiveObject() ? static_cast<InteractiveObject*>(_ch) : 0;
            if (ch == chToRemove)
            {
                ch->OnEventUnload();
                chars[i].Char = 0;
            }
        }
    }
}

// Back to the up state, restarting the state characters.
// @0x1425df520
void Button::Restart()
{
    LastMouseFlags = IDLE;
    mMouseFlags    = IDLE;
    MouseState     = ButtonRecord::MouseUp;
    RollOverCnt    = 0;
    for (UPInt s = 0; s < StatesCount; ++s)
    {
        StateCharArray& chars = States[s].Characters;
        for (UPInt i = 0; i < chars.GetSize(); ++i)
        {
            if (chars[i].Char)
                chars[i].Char->Restart();
        }
    }
}

// @0x1425df5d0
void Button::SetStateChangeFlags(UByte flags)
{
    InteractiveObject::Flags &= ~Mask_ChangedFlags;
    InteractiveObject::Flags |= (flags & 0xf) << 16;
    for (UPInt s = 0; s < StatesCount; ++s)
    {
        StateCharArray& chars = States[s].Characters;
        for (UPInt i = 0; i < chars.GetSize(); ++i)
        {
            DisplayObjectBase* ch = chars[i].Char;
            if (ch)
                ch->SetStateChangeFlags(flags);
        }
    }
}

template<>
inline void InteractiveObject::ModifyOptimizedPlayListLocal<Button>()
{
    switch (static_cast<Button*>(this)->Button::CheckAdvanceStatus(InOptAdvList(this) && !MarkedToLeaveAdvList(this)))
    {
    case 1:  AddToOptimizedPlayList(); break;
    case -1: MarkToRemoveFromOptimizedPlayList(); break;
    }
}

// Hiding a button stops its advance when the movie has noInvisibleAdvance set.
// @0x1425df670
void Button::SetVisible(bool visible)
{
    SetVisibleFlag(visible);
    MovieImpl* proot = GetMovieImpl();
    if (!proot)
        return;
    bool noAdvGlob = !visible && proot->IsNoInvisibleAdvanceFlagSet();
    if (noAdvGlob != IsNoAdvanceGlobalFlagSet())
    {
        SetNoAdvanceGlobalFlag(noAdvGlob);
        ModifyOptimizedPlayListLocal<Button>();
        InteractiveObject* pparent = GetParent();
        if (pparent && !pparent->IsNoAdvanceGlobalFlagSet())
            PropagateNoAdvanceGlobalFlag();
    }
}

// @0x1425df750
void Button::SwitchState()
{
    if (HasAvmObject())
        GetAvmButton()->SwitchState(MouseState);
}

// The state's characters get their unload events (scripted ones that may go), then the state is emptied.
// @0x1425df790
void Button::UnloadCharactersForState(ButtonState state)
{
    StateCharArray& chars = States[state].Characters;
    for (UPInt i = 0; i < chars.GetSize(); ++i)
    {
        DisplayObjectBase* ch = chars[i].Char;
        InteractiveObject* pscriptCh = ch->IsInteractiveObject() ? static_cast<InteractiveObject*>(ch) : 0;
        if (pscriptCh)
        {
            if (ch->OnUnloading())
                ch->OnEventUnload();
        }
        chars[i].Char = 0;
    }
    chars.Clear();
    ClearRenderTreeForState(state);
}

}} // namespace Scaleform::GFx
