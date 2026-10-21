// Recovered Scaleform 4.1.18 GFx: the text editing states a loader installs, TextClipboard and TextKeyMap
// (bodies in sfr_gfx_01c, GFx_TextFieldDef).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_TEXTCLIPBOARD_H
#define MS2_SF_GFX_TEXTCLIPBOARD_H

#include "gfx_state.h"
#include "ms2/scaleform/kernel/sf_wstring.h"

namespace Scaleform {
namespace Render { namespace Text { class StyledText; } }
namespace GFx {

// Modifier keys held down with a key press (one byte of flags).
class KeyModifiers
{
public:
    enum
    {
        Key_ShiftPressed = 0x01,
        Key_CtrlPressed  = 0x02,
        Key_AltPressed   = 0x04
    };

    UInt8 States;
};

// Clipboard shared by the text fields of a loader: plain text plus, optionally, its styled form (state, 0x40 bytes,
// vftable 0x143184718).
class TextClipboard : public State
{
    WStringBuffer                PlainText;   // +0x18
    Render::Text::StyledText*    pStyledText; // +0x38

protected:
    void SetPlainText(const wchar_t* ptext, UPInt len);
    void SetStyledText(Render::Text::StyledText* pstyledText);
    void ReleaseStyledText();

public:
    TextClipboard();
    virtual ~TextClipboard();

    void SetText(const String& str);
    void SetText(const wchar_t* ptext, UPInt len = SF_MAX_UPINT);
    void SetTextAndStyledText(const wchar_t* ptext, UPInt len, Render::Text::StyledText* pstyledText);

    virtual const WStringBuffer&       GetText();                                          // +8
    virtual Render::Text::StyledText* GetStyledText();                                    // +0x10
    virtual bool                      ContainsRichText() const { return pStyledText != 0; } // +0x18
    // Called whenever plain text is stored; the default does nothing.
    virtual void OnTextStore(const wchar_t* ptext, UPInt len) { (void)ptext; (void)len; } // +0x20
};

// Key bindings of the text editor, sorted by key code (state, 0x30 bytes, vftable 0x143184740).
class TextKeyMap : public State
{
public:
    enum KeyAction
    {
        KeyAct_None,
        KeyAct_ToggleSelectionMode,
        KeyAct_EnterSelectionMode,
        KeyAct_LeaveSelectionMode,
        KeyAct_Left,
        KeyAct_Right,
        KeyAct_Up,
        KeyAct_Down,
        KeyAct_PageUp,
        KeyAct_PageDown,
        KeyAct_LineHome,
        KeyAct_LineEnd,
        KeyAct_PageHome,
        KeyAct_PageEnd,
        KeyAct_DocHome,
        KeyAct_DocEnd,
        KeyAct_Backspace,
        KeyAct_Delete,
        KeyAct_Return,
        KeyAct_Copy,
        KeyAct_Paste,
        KeyAct_Cut,
        KeyAct_SelectAll
    };
    enum KeyState
    {
        State_Down,
        State_Up
    };

    // One binding (0x10 bytes).
    struct KeyMapEntry
    {
        KeyAction Action;          // +0
        unsigned  KeyCode;         // +4
        unsigned  SpecKeysPressed; // +8 KeyModifiers bits that must be held
        KeyState  mState;          // +0xc

        KeyMapEntry() : KeyCode(~0u) {}
        KeyMapEntry(KeyAction action, unsigned keyCode, UInt8 specKeys = 0, KeyState state = State_Down)
            : Action(action), KeyCode(keyCode), SpecKeysPressed(specKeys), mState(state)
        {
        }
    };

    Array<KeyMapEntry> Map; // +0x18

    TextKeyMap();

    TextKeyMap* InitWindowsKeyMap();
    TextKeyMap* InitMacKeyMap();

    void AddKeyEntry(const KeyMapEntry& entry);

    const KeyMapEntry* FindFirstEntry(unsigned keyCode) const;
    const KeyMapEntry* FindNextEntry(const KeyMapEntry* pcur) const;
    // The binding of keyCode in state whose modifiers are all held in specKeys, or 0.
    const KeyMapEntry* Find(unsigned keyCode, const KeyModifiers& specKeys, KeyState state) const;
};

}} // namespace Scaleform::GFx

#endif
