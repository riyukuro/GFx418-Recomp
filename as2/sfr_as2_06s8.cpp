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
    // FindCharacterAndRemove (0x142943360 in sfr_as2_05d), inlined in the exe: a TU-local copy under its own name.
    Button::CharToRec FindCharacterAndRemoveInline(const ButtonRecord& rec);
public: // public in the exe (the symbols row and sfr_as2_03z's callers use the public mangling)
    void RecreateCharacters(ButtonRecord::MouseState mouseState);
private:

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
    if ((mouseState == ButtonRecord::MouseUp && rec.IsUp())      ||
        (mouseState == ButtonRecord::MouseDown && rec.IsDown())  ||
        (mouseState == ButtonRecord::MouseOver && rec.IsOver()) )
        return true;
    return false;
}

// DisplayObjectBase::CharToInteractiveObject (SF_INLINE in the SDK's GFx_InteractiveObject.h).
SF_FORCEINLINE InteractiveObject* CharToInteractiveObject(DisplayObjectBase* pch)
{
    return pch->IsInteractiveObject() ? static_cast<InteractiveObject*>(pch) : 0;
}

} // namespace

// AvmButton::FindCharacterAndRemove (inlined in the exe): the character another state made from the record, taken
// out of that state.
inline Button::CharToRec AvmButton::FindCharacterAndRemoveInline(const ButtonRecord& rec)
{
    Button* button  = GetButton();
    for (unsigned i = 0; i < Button::StatesCount; ++i)
    {
        if (i != Button::Hit)
        {
            Button::ButtonState curState = (Button::ButtonState)i;
            Button::StateCharArray&
                chars = button->GetCharacters(curState).Characters;
            for (UPInt j = 0, n = chars.GetSize(); j < n; ++j)
            {
                if (chars[j].Record == &rec)
                {
                    Button::CharToRec chr = chars[j];
                    chars.RemoveAt(j);
                    return chr;
                }
            }
        }
    }
    return Button::CharToRec();
}

// The other states' render trees are cleared; the new state and the hit state get their characters (a character
// of another state made from the same record is moved over, the rest are created and constructed) and the new
// state's container joins the button's render tree; then the other states' characters are unloaded.
// @0x1429729b0
void AvmButton::RecreateCharacters(ButtonRecord::MouseState mouseState)
{
    ButtonDef* pdef = GetButtonDef();
    Button* button  = GetButton();

    Button::ButtonState bs = button->GetButtonState(mouseState);

    for (unsigned i = 0; i < Button::StatesCount; ++i)
    {
        if (i != unsigned(bs) && i != Button::Hit)
        {
            button->ClearRenderTreeForState((Button::ButtonState)i);
        }
    }
    for (unsigned i = 0; i < Button::StatesCount; ++i)
    {
        if (i != unsigned(bs) && i != Button::Hit)
        {
            continue;
        }

        Button::ButtonState curState = (Button::ButtonState)i;
        Button::StateCharArray& chars =
            button->GetCharacters(curState).Characters;
        Ptr<Render::TreeContainer> pContainer = button->GetStateRenderContainer(curState);
        if (chars.GetSize() == 0)
        {
            if (!pContainer)
                pContainer = button->CreateStateRenderContainer(curState);
            for (UPInt j = 0, n = pdef->GetRecordsCount(); j < n; ++j)
            {
                const ButtonRecord& rec = pdef->GetRecordAt(j);

                if ((i != Button::Hit && MatchMouseState(rec, mouseState)) ||
                    (i == Button::Hit && rec.IsHitTest()))
                {
                    const Render::Matrix2F& mat = rec.ButtonMatrix;
                    const Render::Cxform&   cx  = rec.ButtonCxform;

                    // A character of another state made from the record is moved to this one.
                    Button::CharToRec chr;
                    if (i != Button::Hit)
                        chr = FindCharacterAndRemoveInline(rec);
                    if (chr.Char)
                    {
                        chars.PushBack(chr);
                        AddChild(pContainer, chr.Char->GetRenderNode());

                        if (rec.pFilters)
                            chr.Char->SetFilters(rec.pFilters);

                        chr.Char->SetMatrix(mat);
                        chr.Char->SetCxform(cx);
                        chr.Char->SetBlendMode(rec.BlendMode);
                    }
                    else
                    {
                        CharacterCreateInfo ccinfo = GetButton()->pDefImpl->GetCharacterCreateInfo(rec.CharacterId);

                        if (ccinfo.pCharDef)
                        {
                            Ptr<DisplayObjectBase> ch = *GetAS2Root()->pASSupport->CreateCharacterInstance
                                (pDispObj->GetMovieImpl(), ccinfo, GetButton(), rec.CharacterId);
                            chars.PushBack(Button::CharToRec(ch, &rec));

                            AddChild(pContainer, ch->GetRenderNode());

                            if (rec.pFilters)
                                ch->SetFilters(rec.pFilters);

                            ch->SetMatrix(mat);
                            ch->SetCxform(cx);
                            ch->SetBlendMode(rec.BlendMode);

                            InteractiveObject* pscriptCh   = CharToInteractiveObject(ch);
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
            }
        }
        if (curState != Button::Hit && !pContainer->GetParent())
            AddChild(button->GetRenderContainer(), pContainer);
    }
    for (unsigned i = 0; i < Button::StatesCount; ++i)
    {
        if (i != unsigned(bs) && i != Button::Hit)
        {
            button->UnloadCharactersForState((Button::ButtonState)i);
        }
    }
}

}}} // namespace Scaleform::GFx::AS2
