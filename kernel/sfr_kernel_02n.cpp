// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18, Render Text_WWHelper (Asian word
// wrapping: the line-break prohibition table, Japanese/Chinese/Korean break rules). It sits in the Kernel address range
// of queue unit sfr_kernel_02. The class lives in include/render/text_wwhelper.h.
// Our own source, written from the exe.
// MS2-UNIT: sfr_kernel_02n
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14264dec0-0x14264e2b0 .text$mn
#include "ms2/scaleform/include/render/text_wwhelper.h"

namespace Scaleform { namespace Render { namespace Text {

// sorted by character except for U+2122, as in the exe (exe 0x143a2f490, 111 entries)
enum { NonStart = WordWrapHelper::CBI_NonStartingChar, NonTerm = WordWrapHelper::CBI_NonTerminatingChar };
WordWrapHelper::CharBreakInfo WordWrapHelper::CharBreakInfoArray[] =
{
    {0x058A, NonStart}, {0x2010, NonStart}, {0x2012, NonStart}, {0x2013, NonStart},
    {0x2014, NonStart}, {0x2018, NonTerm}, {0x2019, NonStart}, {0x201C, NonTerm},
    {0x201D, NonStart}, {0x2024, NonStart}, {0x2025, NonStart}, {0x2026, NonStart},
    {0x2027, NonStart}, {0x2032, NonStart}, {0x2033, NonStart}, {0x2035, NonTerm},
    {0x20A7, NonTerm}, {0x2103, NonStart}, {0x2109, NonStart}, {0x2116, NonTerm},
    {0x2212, NonTerm}, {0x2213, NonTerm}, {0x2122, NonStart}, {0x2574, NonStart},
    {0x266F, NonTerm}, {0x3001, NonStart}, {0x3002, NonStart}, {0x3005, NonStart},
    {0x3008, NonTerm}, {0x3009, NonStart}, {0x300A, NonTerm}, {0x300B, NonStart},
    {0x300C, NonTerm}, {0x300D, NonStart}, {0x300E, NonTerm}, {0x300F, NonStart},
    {0x3010, NonTerm}, {0x3011, NonStart}, {0x3012, NonTerm}, {0x3014, NonTerm},
    {0x3015, NonStart}, {0x301C, NonStart}, {0x301D, NonTerm}, {0x301E, NonStart},
    {0x301F, NonStart}, {0x3041, NonStart}, {0x3043, NonStart}, {0x3045, NonStart},
    {0x3047, NonStart}, {0x3049, NonStart}, {0x3063, NonStart}, {0x3083, NonStart},
    {0x3085, NonStart}, {0x3087, NonStart}, {0x308E, NonStart}, {0x309B, NonStart},
    {0x309C, NonStart}, {0x309D, NonStart}, {0x309E, NonStart}, {0x30A1, NonStart},
    {0x30A3, NonStart}, {0x30A5, NonStart}, {0x30A7, NonStart}, {0x30A9, NonStart},
    {0x30C3, NonStart}, {0x30E3, NonStart}, {0x30E5, NonStart}, {0x30E7, NonStart},
    {0x30EE, NonStart}, {0x30F5, NonStart}, {0x30F6, NonStart}, {0x30FB, NonStart},
    {0x30FC, NonStart}, {0x30FD, NonStart}, {0x30FE, NonStart}, {0xFDFC, NonStart},
    {0xFE50, NonStart}, {0xFE51, NonStart}, {0xFE52, NonStart}, {0xFE54, NonStart},
    {0xFE55, NonStart}, {0xFE56, NonStart}, {0xFE57, NonStart}, {0xFE59, NonTerm},
    {0xFE5A, NonStart}, {0xFE5B, NonTerm}, {0xFE5C, NonStart}, {0xFE5D, NonTerm},
    {0xFE5E, NonStart}, {0xFE6A, NonStart}, {0xFF01, NonStart}, {0xFF04, NonTerm},
    {0xFF05, NonStart}, {0xFF08, NonTerm}, {0xFF09, NonStart}, {0xFF0C, NonStart},
    {0xFF0E, NonStart}, {0xFF1A, NonStart}, {0xFF1B, NonStart}, {0xFF1F, NonStart},
    {0xFF20, NonTerm}, {0xFF3B, NonTerm}, {0xFF3D, NonStart}, {0xFF5B, NonTerm},
    {0xFF5D, NonStart}, {0xFF61, NonStart}, {0xFF64, NonStart}, {0xFFE0, NonStart | NonTerm},
    {0xFFE1, NonTerm}, {0xFFE5, NonTerm}, {0xFFE6, NonTerm}
};

// binary search of the prohibition table
bool WordWrapHelper::FindCharWithFlags(unsigned wwMode, wchar_t c, unsigned charBreakFlags)
{
    if (!(wwMode & WWT_Prohibition))
        return false;

    SPInt left   = 0;
    SPInt right  = sizeof(CharBreakInfoArray) / sizeof(CharBreakInfoArray[0]);
    SPInt middle = 0;
    while (left <= right)
    {
        middle = ((right - left) / 2) + left;
        if (c == CharBreakInfoArray[middle].Char)
            return (CharBreakInfoArray[middle].Flags & charBreakFlags) != 0;
        if (c < CharBreakInfoArray[middle].Char)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return false;
}

// walk back from the line end to the last allowed break; blanks before it stay on the line
UPInt WordWrapHelper::FindWordWrapPos(unsigned wwMode, UPInt wordWrapPos, const wchar_t* pparaText, UPInt paraLen,
                                      UPInt lineStartPos, UPInt lineLen)
{
    if ((wwMode & (WWT_Asian | WWT_NoHangulWrap | WWT_Prohibition)) && lineLen > 0)
    {
        const wchar_t* pstr = pparaText + lineStartPos;
        UPInt remaining = paraLen - lineStartPos;
        UPInt pos = lineLen - 1;
        for (; pos > 0; --pos)
        {
            if (IsWhiteSpaceChar(pstr[pos]))
            {
                UPInt eolPos = FindPrevNonWhiteSpace(pstr, pos);
                if (eolPos == SF_MAX_UPINT)
                {
                    pos = FindNextNonWhiteSpace(pstr, pos + 1, remaining - 1);
                    break;
                }
                pos = eolPos + 1;
            }
            if (IsLineBreakOpportunityAt(wwMode, pstr, pos))
                break;
        }
        if (pos == 0)
        {
            wordWrapPos = lineLen - 1;
        }
        else
        {
            wordWrapPos = FindNextNonWhiteSpace(pstr, pos, remaining - 1);
            if (wordWrapPos == SF_MAX_UPINT)
                wordWrapPos = lineLen - 1;
        }
        return wordWrapPos;
    }
    return SF_MAX_UPINT;
}

}}}  // namespace Scaleform::Render::Text
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ?FindCharWithFlags@WordWrapHelper@Text@Render@Scaleform@@SA_NI_WI@Z 0x14264dec0
// MS2-PIN: ?FindWordWrapPos@WordWrapHelper@Text@Render@Scaleform@@SA_KI_KPEB_W000@Z 0x14264df30
// MS2-PIN: ?IsAsianChar@WordWrapHelper@Text@Render@Scaleform@@SA_NI_W@Z 0x14264e220
