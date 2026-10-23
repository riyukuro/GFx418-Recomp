// Recovered Scaleform 4.1.18 GFx AS2: the script side of a text field (AvmTextField) and its TextField natives.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
#ifndef MS2_SF_GFX_AS2_AVMTEXTFIELD_H
#define MS2_SF_GFX_AS2_AVMTEXTFIELD_H

#include "as2_avmcharacter.h"
#include "../gfx_textfield.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The AS2 text field's part of the movie (the vftable is not modeled yet).
class AvmTextField : public AvmCharacter
{
public:
    // Sends the event named by the first argument to the listeners of the text field.
    static void BroadcastMessage(const FnCall& fn);

    virtual void CloneInternalData(const InteractiveObject* src);
    virtual void CopyPhysicalProperties(const InteractiveObject* poldChar);

    // (appended for sfr_as2_02) the TextField natives. The field a method works on: this when it is a TextField
    // (TextField is opaque, it starts at its InteractiveObject part).
    static bool IsTextFieldTarget(const FnCall& fn)
    {
        return fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object_TextField;
    }
    // Only after IsTextFieldTarget.
    static TextField* GetTextFieldTarget(const FnCall& fn)
    {
        return reinterpret_cast<TextField*>(fn.ThisPtr->ToCharacter());
    }
    static InteractiveObject* ToCharacter(TextField* ptf) { return reinterpret_cast<InteractiveObject*>(ptf); }

    static void RemoveTextField(const FnCall& fn);         // exe 0x14290a0f0
    static void GetCharBoundaries(const FnCall& fn);       // exe 0x14290a180
    static void GetCharIndexAtPoint(const FnCall& fn);     // exe 0x14290a350
    static void GetExactCharBoundaries(const FnCall& fn);  // exe 0x14290a4b0
    static void GetLineIndexAtPoint(const FnCall& fn);     // exe 0x14290a680
    static void GetLineIndexOfChar(const FnCall& fn);      // exe 0x14290a7d0
    static void GetLineOffset(const FnCall& fn);           // exe 0x14290a8c0
    static void GetLineLength(const FnCall& fn);           // exe 0x14290a9c0
    static void GetFirstCharInParagraph(const FnCall& fn); // exe 0x14290b1c0
    static void AppendText(const FnCall& fn);              // exe 0x14290b920
    static void GetLineMetrics(const FnCall& fn);          // exe 0x14290aac0
    static void GetLineText(const FnCall& fn);             // exe 0x14290afc0
    static void AppendHtml(const FnCall& fn);              // exe 0x14290b9f0
    static void CopyToClipboard(const FnCall& fn);         // exe 0x14290bb20
    static void CutToClipboard(const FnCall& fn);          // exe 0x14290bc50
    static void PasteFromClipboard(const FnCall& fn);      // exe 0x14290bd90
    static void ReplaceSel(const FnCall& fn);              // exe 0x142909b00
    static void ReplaceTextA(const FnCall& fn);            // exe 0x142909d80 (replaceText)
};

}}} // namespace Scaleform::GFx::AS2

#endif
