// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_TextFieldDef, part one: the
// TextClipboard and TextKeyMap states (TextFieldDef and its tag loaders are in sfr_gfx_01g).
// Third source of queue unit sfr_gfx_01 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_01c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14258d2a0-0x14258d550 .text$mn
// MS2-RANGE: 0x14258d600-0x14258d640 .text$mn
// MS2-RANGE: 0x14258d650-0x14258d6a0 .text$mn
// MS2-RANGE: 0x14258d7a0-0x14258d830 .text$mn
// MS2-RANGE: 0x14258d930-0x14258dad0 .text$mn
// MS2-RANGE: 0x14258dae0-0x14258dc80 .text$mn
// MS2-RANGE: 0x14258e030-0x14258e050 .text$mn
// MS2-RANGE: 0x14258e0b0-0x14258e3f0 .text$mn
// MS2-RANGE: 0x14258ecc0-0x14258f1a0 .text$mn

// The text headers use the kernel header tree, so they come before the GFx ones.
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/include/render/text_styledtext.h"
#include "../include/gfx/gfx_textclipboard.h"
#include "../include/kernel/sf_array.h"
#include "../include/kernel/sf_string.h"
#include "../include/kernel/sf_utf8util.h"

namespace Scaleform { namespace GFx {

//
// TextClipboard
//

// @0x14258d510
TextClipboard::TextClipboard() : State(State_TextClipboard), pStyledText(0)
{
}

// @0x14258d650
TextClipboard::~TextClipboard()
{
    ReleaseStyledText();
}

// @0x14258ecc0
void TextClipboard::ReleaseStyledText()
{
    if (pStyledText)
    {
        pStyledText->Release();
        pStyledText = 0;
    }
}

// @0x14258ed90
void TextClipboard::SetPlainText(const wchar_t* ptext, UPInt len)
{
    PlainText.SetString(ptext, len);
    OnTextStore(PlainText.ToWStr(), PlainText.GetLength());
}

// Keeps a copy of pstyledText, made with an allocator of its own on the global heap.
// @0x14258edd0
void TextClipboard::SetStyledText(Render::Text::StyledText* pstyledText)
{
    if (pStyledText)
        pStyledText->Release();
    using Render::Text::Allocator;
    MemoryHeap* pheap      = Memory::GetGlobalHeap();
    Allocator*  pallocator = SF_HEAP_NEW(pheap) Allocator(pheap, Allocator::Flags_Global);
    pStyledText            = SF_HEAP_NEW(pheap) Render::Text::StyledText(pallocator);
    pstyledText->CopyStyledText(pStyledText);
    if (pallocator)
        pallocator->Release();
}

// @0x14258ef00
void TextClipboard::SetText(const String& str)
{
    ReleaseStyledText();
    UPInt len = str.GetLength();
    PlainText.Resize(len + 1);
    UTF8Util::DecodeString(PlainText.GetBuffer(), str.ToCStr(), str.GetSize());
    OnTextStore(PlainText.ToWStr(), PlainText.GetLength());
}

// @0x14258efa0
void TextClipboard::SetText(const wchar_t* ptext, UPInt len)
{
    ReleaseStyledText();
    SetPlainText(ptext, len);
}

// Storing the plain text drops the styled copy again, so only the plain text is kept.
// @0x14258f020
void TextClipboard::SetTextAndStyledText(const wchar_t* ptext, UPInt len, Render::Text::StyledText* pstyledText)
{
    SetStyledText(pstyledText);
    SetText(ptext, len);
}

// @0x14258e040
const WStringBuffer& TextClipboard::GetText()
{
    return PlainText;
}

// @0x14258e030
Render::Text::StyledText* TextClipboard::GetStyledText()
{
    return pStyledText;
}

//
// TextKeyMap
//

// @0x14258d600
TextKeyMap::TextKeyMap() : State(State_TextKeyMap)
{
}

static bool KeyMapEntryLess(const TextKeyMap::KeyMapEntry& a, const TextKeyMap::KeyMapEntry& b)
{
    return (int)(a.KeyCode - b.KeyCode) < 0;
}

static bool KeyMapEntryKeyLess(const TextKeyMap::KeyMapEntry& a, unsigned keyCode)
{
    return (int)(a.KeyCode - keyCode) < 0;
}

// @0x14258d9b0
void TextKeyMap::AddKeyEntry(const KeyMapEntry& entry)
{
    UPInt i = Alg::LowerBound(Map, entry, KeyMapEntryLess);
    Map.InsertAt(i, entry);
}

// @0x14258dbc0
const TextKeyMap::KeyMapEntry* TextKeyMap::FindFirstEntry(unsigned keyCode) const
{
    UPInt i = Alg::LowerBound(Map, keyCode, KeyMapEntryKeyLess);
    if (i < Map.GetSize() && Map[i].KeyCode == keyCode)
        return &Map[i];
    return 0;
}

// @0x14258dc40
const TextKeyMap::KeyMapEntry* TextKeyMap::FindNextEntry(const KeyMapEntry* pcur) const
{
    UPInt i = pcur - &Map[0];
    if (i + 1 < Map.GetSize() && Map[i + 1].KeyCode == pcur->KeyCode)
        return &Map[i + 1];
    return 0;
}

// @0x14258dae0
const TextKeyMap::KeyMapEntry* TextKeyMap::Find(unsigned keyCode, const KeyModifiers& specKeys, KeyState state) const
{
    const KeyMapEntry* pentry = FindFirstEntry(keyCode);
    while (pentry)
    {
        if (pentry->mState == state && (specKeys.States & pentry->SpecKeysPressed) == pentry->SpecKeysPressed)
            return pentry;
        pentry = FindNextEntry(pentry);
    }
    return 0;
}

} // namespace GFx

// The out-of-line binary searches over the key map (by entry and by key code), with int-returning comparators
// (explicit instantiations belong to a namespace enclosing Alg).
// @0x14258d2a0
template UPInt Alg::LowerBound<Array<GFx::TextKeyMap::KeyMapEntry>, unsigned, int (*)(const GFx::TextKeyMap::KeyMapEntry&, unsigned)>(
    const Array<GFx::TextKeyMap::KeyMapEntry>&, const unsigned&, int (*)(const GFx::TextKeyMap::KeyMapEntry&, unsigned));
// @0x14258d330
template UPInt Alg::LowerBound<Array<GFx::TextKeyMap::KeyMapEntry>, GFx::TextKeyMap::KeyMapEntry,
                               int (*)(const GFx::TextKeyMap::KeyMapEntry&, const GFx::TextKeyMap::KeyMapEntry&)>(
    const Array<GFx::TextKeyMap::KeyMapEntry>&, const GFx::TextKeyMap::KeyMapEntry&,
    int (*)(const GFx::TextKeyMap::KeyMapEntry&, const GFx::TextKeyMap::KeyMapEntry&));
// @0x14258d3d0
template UPInt Alg::LowerBoundSliced<Array<GFx::TextKeyMap::KeyMapEntry>, unsigned,
                                     int (*)(const GFx::TextKeyMap::KeyMapEntry&, unsigned)>(
    const Array<GFx::TextKeyMap::KeyMapEntry>&, UPInt, UPInt, const unsigned&, int (*)(const GFx::TextKeyMap::KeyMapEntry&, unsigned));
// @0x14258d470
template UPInt Alg::LowerBoundSliced<Array<GFx::TextKeyMap::KeyMapEntry>, GFx::TextKeyMap::KeyMapEntry,
                                     int (*)(const GFx::TextKeyMap::KeyMapEntry&, const GFx::TextKeyMap::KeyMapEntry&)>(
    const Array<GFx::TextKeyMap::KeyMapEntry>&, UPInt, UPInt, const GFx::TextKeyMap::KeyMapEntry&,
    int (*)(const GFx::TextKeyMap::KeyMapEntry&, const GFx::TextKeyMap::KeyMapEntry&));

namespace GFx {

// @0x14258e0c0
TextKeyMap* TextKeyMap::InitWindowsKeyMap()
{
    enum
    {
        VK_Backspace = 0x08,
        VK_Return    = 0x0d,
        VK_Shift     = 0x10,
        VK_PageUp    = 0x21,
        VK_PageDown  = 0x22,
        VK_End       = 0x23,
        VK_Home      = 0x24,
        VK_Left      = 0x25,
        VK_Up        = 0x26,
        VK_Right     = 0x27,
        VK_Down      = 0x28,
        VK_Insert    = 0x2d,
        VK_Delete    = 0x2e,
        VK_A         = 0x41,
        VK_C         = 0x43,
        VK_V         = 0x56,
        VK_X         = 0x58
    };
    const UInt8 shift = KeyModifiers::Key_ShiftPressed;
    const UInt8 ctrl  = KeyModifiers::Key_CtrlPressed;

    AddKeyEntry(KeyMapEntry(KeyAct_EnterSelectionMode, VK_Shift));
    AddKeyEntry(KeyMapEntry(KeyAct_LeaveSelectionMode, VK_Shift, 0, State_Up));
    AddKeyEntry(KeyMapEntry(KeyAct_Up, VK_Up));
    AddKeyEntry(KeyMapEntry(KeyAct_Down, VK_Down));
    AddKeyEntry(KeyMapEntry(KeyAct_Left, VK_Left));
    AddKeyEntry(KeyMapEntry(KeyAct_Right, VK_Right));
    AddKeyEntry(KeyMapEntry(KeyAct_PageUp, VK_PageUp));
    AddKeyEntry(KeyMapEntry(KeyAct_PageDown, VK_PageDown));
    AddKeyEntry(KeyMapEntry(KeyAct_LineHome, VK_Home));
    AddKeyEntry(KeyMapEntry(KeyAct_LineEnd, VK_End));
    AddKeyEntry(KeyMapEntry(KeyAct_PageHome, VK_PageUp, ctrl));
    AddKeyEntry(KeyMapEntry(KeyAct_PageEnd, VK_PageDown, ctrl));
    AddKeyEntry(KeyMapEntry(KeyAct_DocHome, VK_Home, ctrl));
    AddKeyEntry(KeyMapEntry(KeyAct_DocEnd, VK_End, ctrl));
    AddKeyEntry(KeyMapEntry(KeyAct_Backspace, VK_Backspace));
    AddKeyEntry(KeyMapEntry(KeyAct_Delete, VK_Delete));
    AddKeyEntry(KeyMapEntry(KeyAct_Return, VK_Return));
    AddKeyEntry(KeyMapEntry(KeyAct_Copy, VK_C, ctrl));
    AddKeyEntry(KeyMapEntry(KeyAct_Copy, VK_Insert, ctrl));
    AddKeyEntry(KeyMapEntry(KeyAct_Paste, VK_V, ctrl));
    AddKeyEntry(KeyMapEntry(KeyAct_Paste, VK_Insert, shift));
    AddKeyEntry(KeyMapEntry(KeyAct_Cut, VK_X, ctrl));
    AddKeyEntry(KeyMapEntry(KeyAct_Cut, VK_Delete, shift));
    AddKeyEntry(KeyMapEntry(KeyAct_SelectAll, VK_A, ctrl));
    return this;
}

// The Mac bindings are the Windows ones in this build.
// @0x14258e0b0
TextKeyMap* TextKeyMap::InitMacKeyMap()
{
    return InitWindowsKeyMap();
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7TextClipboard@GFx@Scaleform@@6B@ 0x143184718
// MS2-PIN: ??_7TextKeyMap@GFx@Scaleform@@6B@ 0x143184740
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7?$RefCountBaseNTS@VAllocator@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7Allocator@Text@Render@Scaleform@@6B@ 0x14317c9d0
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
