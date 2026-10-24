// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 AvmButton::RecreateCharacters
// of sfr_as2_06 (gap recovery, lane sfr24): the characters of the button's new state (and of its hit state) are
// made, or moved over from the state that had them, when the mouse state changes.
// MS2-UNIT: sfr_as2_06s8
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429729b0-0x14297303b .text$mn

#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_button.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/gfx_rendertree.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The AS2 side of a button. Only the members used here.
class AvmButton : public AvmCharacter
{
    // A character made from a button record gets the class registered for its export name (0x142935820).
    void ConstructCharacter(InteractiveObject* pchar, const ButtonRecord& rec);
    void RecreateCharacters(ButtonRecord::MouseState mouseState);

    Button*    GetButton() const    { return static_cast<Button*>(pDispObj); }
    ButtonDef* GetButtonDef() const { return GetButton()->GetButtonDef(); }
};

namespace {

// TreeContainer::Add with the child count inlined.
SF_FORCEINLINE void AddChild(Render::TreeContainer* pcontainer, Render::TreeNode* pnode)
{
    pcontainer->Insert(pcontainer->GetReadOnlyData()->Children.GetSize(), pnode);
}

// The record shows its character in the mouse state.
SF_FORCEINLINE bool MatchMouseState(const ButtonRecord& rec, ButtonRecord::MouseState mouseState)
{
    switch (mouseState)
    {
    case ButtonRecord::MouseUp:   return rec.IsUp();
    case ButtonRecord::MouseDown: return rec.IsDown();
    case ButtonRecord::MouseOver: return rec.IsOver();
    default:                      return false;
    }
}

// The record's character as the record placed it.
SF_FORCEINLINE void PlaceRecordCharacter(Render::TreeContainer* pcontainer, DisplayObjectBase* pch,
                                         const ButtonRecord& rec)
{
    AddChild(pcontainer, pch->GetRenderNode());
    if (rec.pFilters)
        pch->SetFilters(rec.pFilters);
    pch->SetMatrix(rec.ButtonMatrix);
    pch->SetCxform(rec.ButtonCxform);
    pch->SetBlendMode(rec.BlendMode);
}

} // namespace

// The other states' render trees are cleared; the new state and the hit state get their characters (a character
// of another state made from the same record is moved over, the rest are created and constructed) and the new
// state's container joins the button's render tree; then the other states' characters are unloaded.
// MS2-FUNCTIONAL: register allocation and stack layout differ.
// @0x1429729b0
void AvmButton::RecreateCharacters(ButtonRecord::MouseState mouseState)
{
    Button*             button = GetButton();
    ButtonDef*          pdef   = GetButtonDef();
    Button::ButtonState bs     = Button::GetButtonState(mouseState);

    for (unsigned i = 0; i < Button::StatesCount; ++i)
    {
        if (i != unsigned(bs) && i != Button::Hit)
            button->ClearRenderTreeForState(Button::ButtonState(i));
    }
    for (unsigned i = 0; i < Button::StatesCount; ++i)
    {
        if (i != unsigned(bs) && i != Button::Hit)
            continue;

        Button::ButtonState        curState   = Button::ButtonState(i);
        Button::StateCharArray&    chars      = button->GetCharacters(curState).Characters;
        Ptr<Render::TreeContainer> pContainer = button->GetStateRenderContainer(curState);
        if (chars.GetSize() == 0)
        {
            if (!pContainer)
                pContainer = button->CreateStateRenderContainer(curState);
            for (UPInt j = 0, n = pdef->GetRecordsCount(); j < n; ++j)
            {
                const ButtonRecord& rec = pdef->GetRecordAt(j);
                if (i != Button::Hit ? !MatchMouseState(rec, mouseState) : !rec.IsHitTest())
                    continue;

                // A character of another state made from the record is moved to this one.
                Button::CharToRec chr;
                chr.Record = 0;
                if (i != Button::Hit)
                {
                    for (unsigned s = 0; s < Button::StatesCount; ++s)
                    {
                        if (s == Button::Hit)
                            continue;
                        Button::StateCharArray& other = button->GetCharacters(Button::ButtonState(s)).Characters;
                        UPInt k = 0, nother = other.GetSize();
                        for (; k < nother; ++k)
                        {
                            if (other[k].Record == &rec)
                                break;
                        }
                        if (k < nother)
                        {
                            chr = other[k];
                            other.RemoveAt(k);
                            break;
                        }
                    }
                }
                if (chr.Char)
                {
                    chars.PushBack(chr);
                    PlaceRecordCharacter(pContainer, chr.Char, rec);
                }
                else
                {
                    CharacterCreateInfo ccinfo = button->pDefImpl->GetCharacterCreateInfo(rec.CharacterId);
                    if (!ccinfo.pCharDef)
                        continue;
                    Ptr<DisplayObjectBase> ch = *pDispObj->GetASMovieRoot()->pASSupport->CreateCharacterInstance(
                        pDispObj->GetMovieImpl(), ccinfo, button, rec.CharacterId);
                    Button::CharToRec newChr;
                    newChr.Char   = ch;
                    newChr.Record = &rec;
                    chars.PushBack(newChr);
                    PlaceRecordCharacter(pContainer, ch, rec);

                    InteractiveObject* pscriptCh = ch->IsInteractiveObject() ? static_cast<InteractiveObject*>(
                                                                                    ch.GetPtr())
                                                                              : 0;
                    if (pscriptCh)
                    {
                        ConstructCharacter(pscriptCh, rec);
                        pscriptCh->AddToPlayList();
                        pscriptCh->ModifyOptimizedPlayList();
                        ch->OnEventLoad();
                    }
                }
            }
        }
        if (curState != Button::Hit && !pContainer->GetParent())
            AddChild(button->GetRenderContainer(), pContainer);
    }
    for (unsigned i = 0; i < Button::StatesCount; ++i)
    {
        if (i != unsigned(bs) && i != Button::Hit)
            button->UnloadCharactersForState(Button::ButtonState(i));
    }
}

}}} // namespace Scaleform::GFx::AS2
