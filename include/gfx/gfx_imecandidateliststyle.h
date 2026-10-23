// Recovered Scaleform 4.1.18 GFx: the IME candidate list style MovieImpl keeps for the IME manager (0x2c bytes, by
// value). Each value has a set bit in Flags; colors are 0xRRGGBB and the getters drop the alpha byte. Layout and bits
// from the AS3 IMEEx get/setIMECandidateListStyle natives (0x1424cab90 / 0x1424cb980).
#ifndef MS2_SF_GFX_IMECANDIDATELISTSTYLE_H
#define MS2_SF_GFX_IMECANDIDATELISTSTYLE_H

#include "../kernel/sf_types.h"

namespace Scaleform { namespace GFx {

class IMECandidateListStyle
{
public:
    enum
    {
        Flag_TextColor                      = 0x01,
        Flag_BackgroundColor                = 0x02,
        Flag_IndexBackgroundColor           = 0x04,
        Flag_SelectedTextColor              = 0x08,
        Flag_SelectedBackgroundColor        = 0x10,
        Flag_SelectedIndexBackgroundColor   = 0x20,
        Flag_FontSize                       = 0x40,
        Flag_ReadingWindowTextColor         = 0x80,
        Flag_ReadingWindowBackgroundColor   = 0x100,
        Flag_ReadingWindowFontSize          = 0x200
    };

    IMECandidateListStyle() : Flags(0) {}

    void SetTextColor(UInt32 c)                     { TextColor = c; Flags |= Flag_TextColor; }
    void SetBackgroundColor(UInt32 c)               { BackgroundColor = c; Flags |= Flag_BackgroundColor; }
    void SetIndexBackgroundColor(UInt32 c)          { IndexBackgroundColor = c; Flags |= Flag_IndexBackgroundColor; }
    void SetSelectedTextColor(UInt32 c)             { SelectedTextColor = c; Flags |= Flag_SelectedTextColor; }
    void SetSelectedBackgroundColor(UInt32 c)       { SelectedBackgroundColor = c; Flags |= Flag_SelectedBackgroundColor; }
    void SetSelectedIndexBackgroundColor(UInt32 c)  { SelectedIndexBackgroundColor = c; Flags |= Flag_SelectedIndexBackgroundColor; }
    void SetFontSize(UInt32 sz)                     { FontSize = sz; Flags |= Flag_FontSize; }
    void SetReadingWindowTextColor(UInt32 c)        { ReadingWindowTextColor = c; Flags |= Flag_ReadingWindowTextColor; }
    void SetReadingWindowBackgroundColor(UInt32 c)  { ReadingWindowBackgroundColor = c; Flags |= Flag_ReadingWindowBackgroundColor; }
    void SetReadingWindowFontSize(UInt32 sz)        { ReadingWindowFontSize = sz; Flags |= Flag_ReadingWindowFontSize; }

    bool HasTextColor() const                       { return (Flags & Flag_TextColor) != 0; }
    bool HasBackgroundColor() const                 { return (Flags & Flag_BackgroundColor) != 0; }
    bool HasIndexBackgroundColor() const            { return (Flags & Flag_IndexBackgroundColor) != 0; }
    bool HasSelectedTextColor() const               { return (Flags & Flag_SelectedTextColor) != 0; }
    bool HasSelectedBackgroundColor() const         { return (Flags & Flag_SelectedBackgroundColor) != 0; }
    bool HasSelectedIndexBackgroundColor() const    { return (Flags & Flag_SelectedIndexBackgroundColor) != 0; }
    bool HasFontSize() const                        { return (Flags & Flag_FontSize) != 0; }
    bool HasReadingWindowTextColor() const          { return (Flags & Flag_ReadingWindowTextColor) != 0; }
    bool HasReadingWindowBackgroundColor() const    { return (Flags & Flag_ReadingWindowBackgroundColor) != 0; }
    bool HasReadingWindowFontSize() const           { return (Flags & Flag_ReadingWindowFontSize) != 0; }

    UInt32 GetTextColor() const                     { return TextColor & 0xFFFFFF; }
    UInt32 GetBackgroundColor() const               { return BackgroundColor & 0xFFFFFF; }
    UInt32 GetIndexBackgroundColor() const          { return IndexBackgroundColor & 0xFFFFFF; }
    UInt32 GetSelectedTextColor() const             { return SelectedTextColor & 0xFFFFFF; }
    UInt32 GetSelectedBackgroundColor() const       { return SelectedBackgroundColor & 0xFFFFFF; }
    UInt32 GetSelectedIndexBackgroundColor() const  { return SelectedIndexBackgroundColor & 0xFFFFFF; }
    UInt32 GetFontSize() const                      { return FontSize; }
    UInt32 GetReadingWindowTextColor() const        { return ReadingWindowTextColor; }
    UInt32 GetReadingWindowBackgroundColor() const  { return ReadingWindowBackgroundColor; }
    UInt32 GetReadingWindowFontSize() const         { return ReadingWindowFontSize; }

    UInt32  TextColor;                      // +0x00
    UInt32  BackgroundColor;                // +0x04
    UInt32  IndexBackgroundColor;           // +0x08
    UInt32  SelectedTextColor;              // +0x0c
    UInt32  SelectedBackgroundColor;        // +0x10
    UInt32  SelectedIndexBackgroundColor;   // +0x14
    UInt32  ReadingWindowTextColor;         // +0x18
    UInt32  ReadingWindowBackgroundColor;   // +0x1c
    UInt32  FontSize;                       // +0x20
    UInt32  ReadingWindowFontSize;          // +0x24
    UInt16  Flags;                          // +0x28
};

}} // namespace Scaleform::GFx

#endif
