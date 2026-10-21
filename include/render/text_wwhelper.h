// Recovered Scaleform 4.1.18 Render Text: word-wrapping helper (Asian line-break rules and the prohibition table).
// Bodies: Text_WWHelper (unit sfr_kernel_02n); IsAsianChar also gets an out-of-line copy in Text_DocView.
// Our own source, written from the exe.
#ifndef MS2_SF_RENDER_TEXT_WWHELPER_H
#define MS2_SF_RENDER_TEXT_WWHELPER_H

#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform { namespace Render { namespace Text {

class WordWrapHelper
{
public:
    enum BreakInfoFlags
    {
        CBI_NonStartingChar    = 1,    // may not start a line
        CBI_NonTerminatingChar = 2     // may not end a line
    };
    enum WordWrappingTypes
    {
        WWT_Default      = 0,
        WWT_Asian        = 0x1,    // break between any two CJK characters
        WWT_Prohibition  = 0x2,    // honour the CharBreakInfoArray prohibitions
        WWT_NoHangulWrap = 0x4,    // Korean: Hangul wraps by words
        WWT_Last         = WWT_NoHangulWrap,
        WWT_All          = WWT_Asian | WWT_Prohibition | WWT_NoHangulWrap
    };
    struct CharBreakInfo
    {
        wchar_t Char;
        UByte   Flags;
    };
    static CharBreakInfo CharBreakInfoArray[];

    static bool SF_STDCALL FindCharWithFlags(unsigned wwMode, wchar_t c, unsigned charBreakFlags);
    static bool SF_STDCALL IsAsianChar(unsigned wwMode, wchar_t c)
    {
        if (wwMode & WWT_NoHangulWrap)
        {
            if ((c >= 0x1100 && c <= 0x11FF) || (c >= 0x3130 && c <= 0x318F) || (c >= 0xAC00 && c <= 0xD7A3))
                return false;
        }
        return (c >= 0x1100 && c <= 0x11FF) || (c >= 0x3000 && c <= 0xD7AF) || (c >= 0xF900 && c <= 0xFAFF) ||
               (c >= 0xFF00 && c <= 0xFFDC);
    }
    static bool SF_STDCALL IsNonStartingChar(unsigned wwMode, wchar_t c)
    {
        return FindCharWithFlags(wwMode, c, CBI_NonStartingChar);
    }
    static bool SF_STDCALL IsNonTerminatingChar(unsigned wwMode, wchar_t c)
    {
        return FindCharWithFlags(wwMode, c, CBI_NonTerminatingChar);
    }
    static bool SF_STDCALL IsWhiteSpaceChar(wchar_t c) { return c == L'\t' || c == L'\r' || c == L' ' || c == 0x3000; }
    static bool SF_STDCALL IsLineFeedChar(wchar_t c) { return c == L'\n'; }
    static bool SF_STDCALL IsLineBreakOpportunityAt(unsigned wwMode, const wchar_t* pwstr, UPInt index)
    {
        if (index == 0)
            return false;
        return IsLineBreakOpportunityAt(wwMode, pwstr[index - 1], pwstr[index]);
    }
    static bool SF_STDCALL IsLineBreakOpportunityAt(unsigned wwMode, wchar_t prevChar, wchar_t curChar)
    {
        if (prevChar == 0)
            return false;
        return (IsWhiteSpaceChar(prevChar) || IsAsianChar(wwMode, curChar) || IsAsianChar(wwMode, prevChar) ||
                prevChar == L'-') &&
               !IsNonStartingChar(wwMode, curChar) && !IsNonTerminatingChar(wwMode, prevChar);
    }
    // skips blanks and one line feed; ~0 past maxPos
    static UPInt SF_STDCALL FindNextNonWhiteSpace(const wchar_t* pwstr, UPInt pos, UPInt maxPos)
    {
        while (IsWhiteSpaceChar(pwstr[pos]))
            ++pos;
        if (pwstr && IsLineFeedChar(pwstr[pos]))
            ++pos;
        return (pos <= maxPos) ? pos : SF_MAX_UPINT;
    }
    static UPInt SF_STDCALL FindPrevNonWhiteSpace(const wchar_t* pwstr, UPInt pos)
    {
        SPInt p = (SPInt)pos;
        while (p >= 0 && (IsWhiteSpaceChar(pwstr[p]) || IsLineFeedChar(pwstr[p])))
            --p;
        return (p < 0) ? SF_MAX_UPINT : (UPInt)p;
    }

    // new wrap position inside the line (0 = lineStartPos), ~0 if the mode has no Asian rules
    static UPInt SF_STDCALL FindWordWrapPos(unsigned wwMode, UPInt wordWrapPos, const wchar_t* pparaText, UPInt paraLen,
                                            UPInt lineStartPos, UPInt lineLen);
};

}}}  // namespace Scaleform::Render::Text

#endif
