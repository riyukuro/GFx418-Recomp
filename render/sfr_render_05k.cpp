// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, a second Text_WWHelper copy.
// The exe links Text_WWHelper twice: the copy in the Kernel range (sfr_kernel_02n, table 0x143a2f490) and this one
// between the HTML parser (sfr_render_05i) and the tree cache (sfr_render_05j), with its own prohibition table
// (0x143a2f780, same 111 entries) and calling the IsAsianChar copy of Text_DocView (0x142614650). The paragraph
// formatter (sfr_render_03b) calls this FindCharWithFlags. The bodies are the WordWrapHelper ones, named by address.
// Our own source, written from the exe.
// MS2-UNIT: sfr_render_05k
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14267fce0-0x142680040 .text$mn
#include "ms2/scaleform/include/render/text_wwhelper.h"

using Scaleform::UPInt;
using Scaleform::SPInt;
using Scaleform::Render::Text::WordWrapHelper;

// this copy's prohibition table (111 entries, as WordWrapHelper::CharBreakInfoArray)
extern WordWrapHelper::CharBreakInfo DAT_143a2f780[];

// WordWrapHelper::FindCharWithFlags: binary search of the prohibition table
// @0x14267fce0
bool FUN_14267fce0(unsigned wwMode, wchar_t c, unsigned charBreakFlags)
{
    if (!(wwMode & WordWrapHelper::WWT_Prohibition))
        return false;

    SPInt left   = 0;
    SPInt right  = 111;
    SPInt middle = 0;
    while (left <= right)
    {
        middle = ((right - left) / 2) + left;
        if (c == DAT_143a2f780[middle].Char)
            return (DAT_143a2f780[middle].Flags & charBreakFlags) != 0;
        if (c < DAT_143a2f780[middle].Char)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return false;
}

// the WordWrapHelper inlines over this copy's table
static bool IsNonStartingChar(unsigned wwMode, wchar_t c)
{
    return FUN_14267fce0(wwMode, c, WordWrapHelper::CBI_NonStartingChar);
}
static bool IsNonTerminatingChar(unsigned wwMode, wchar_t c)
{
    return FUN_14267fce0(wwMode, c, WordWrapHelper::CBI_NonTerminatingChar);
}
static bool IsLineBreakOpportunityAt(unsigned wwMode, wchar_t prevChar, wchar_t curChar)
{
    if (prevChar == 0)
        return false;
    return (WordWrapHelper::IsWhiteSpaceChar(prevChar) || WordWrapHelper::IsAsianChar(wwMode, curChar) ||
            WordWrapHelper::IsAsianChar(wwMode, prevChar) || prevChar == L'-') &&
           !IsNonStartingChar(wwMode, curChar) && !IsNonTerminatingChar(wwMode, prevChar);
}
static bool IsLineBreakOpportunityAt(unsigned wwMode, const wchar_t* pwstr, UPInt index)
{
    if (index == 0)
        return false;
    return IsLineBreakOpportunityAt(wwMode, pwstr[index - 1], pwstr[index]);
}

// WordWrapHelper::FindWordWrapPos: walk back from the line end to the last allowed break; blanks before it stay on
// the line
// @0x14267fd50
UPInt FUN_14267fd50(unsigned wwMode, UPInt wordWrapPos, const wchar_t* pparaText, UPInt paraLen, UPInt lineStartPos,
                    UPInt lineLen)
{
    if ((wwMode & (WordWrapHelper::WWT_Asian | WordWrapHelper::WWT_NoHangulWrap | WordWrapHelper::WWT_Prohibition)) &&
        lineLen > 0)
    {
        const wchar_t* pstr = pparaText + lineStartPos;
        UPInt remaining = paraLen - lineStartPos;
        UPInt pos = lineLen - 1;
        for (; pos > 0; --pos)
        {
            if (WordWrapHelper::IsWhiteSpaceChar(pstr[pos]))
            {
                UPInt eolPos = WordWrapHelper::FindPrevNonWhiteSpace(pstr, pos);
                if (eolPos == SF_MAX_UPINT)
                {
                    pos = WordWrapHelper::FindNextNonWhiteSpace(pstr, pos + 1, remaining - 1);
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
            wordWrapPos = WordWrapHelper::FindNextNonWhiteSpace(pstr, pos, remaining - 1);
            if (wordWrapPos == SF_MAX_UPINT)
                wordWrapPos = lineLen - 1;
        }
        return wordWrapPos;
    }
    return SF_MAX_UPINT;
}
