// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the text highlight TU
// (Text_Highlight): the Highlighter's id-sorted list of highlighted ranges, its merge / cut edits, and the two
// iterators that resolve overlapping highlights per glyph (position iterator) or per run (range iterator).
// Queue unit sfr_render_04 is split along its original sources (04b Text_Highlight).
// MS2-UNIT: sfr_render_04b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142666790-0x142667cf0 .text$mn

#include "ms2/scaleform/include/render/text_highlight.h"
#include "ms2/scaleform/include/render/text_docview.h"
#include "ms2/scaleform/include/kernel/sf_alg.h"

namespace Scaleform { namespace Render { namespace Text {

// The list is kept sorted by id; the binary searches order a desc against a bare id.
struct HighlightIdLess
{
    static int Compare(const HighlightDesc& desc, unsigned id) { return (int)desc.Id - (int)id; }
    static int Less(const HighlightDesc& desc, unsigned id)    { return Compare(desc, id) < 0; }
};

// ---------------------------------------------------------------------------------------------------------------
// HighlightInfo

// Takes over what this info leaves unset.
void HighlightInfo::Append(const HighlightInfo& other)
{
    if (!HasUnderlineStyle() && other.HasUnderlineStyle())
        SetUnderlineStyle(other.GetUnderlineStyle());
    if (!HasBackgroundColor() && other.HasBackgroundColor())
        SetBackgroundColor(other.GetBackgroundColor());
    if (!HasTextColor() && other.HasTextColor())
        SetTextColor(other.GetTextColor());
    if (!HasUnderlineColor() && other.HasUnderlineColor())
        SetUnderlineColor(other.GetUnderlineColor());
}

// Lets everything the other info sets win over this one.
void HighlightInfo::Prepend(const HighlightInfo& other)
{
    if (other.HasUnderlineStyle())
        SetUnderlineStyle(other.GetUnderlineStyle());
    if (other.HasBackgroundColor())
        SetBackgroundColor(other.GetBackgroundColor());
    if (other.HasTextColor())
        SetTextColor(other.GetTextColor());
    if (other.HasUnderlineColor())
        SetUnderlineColor(other.GetUnderlineColor());
}

// @0x142667560
bool HighlightInfo::IsEqualWithFlags(const HighlightInfo& right, unsigned flags)
{
    if ((flags & Flag_UnderlineStyle) && GetUnderlineStyle() != right.GetUnderlineStyle())
        return false;
    if (flags & Flag_Background)
    {
        if (HasBackgroundColor() != right.HasBackgroundColor() || GetBackgroundColor() != right.GetBackgroundColor())
            return false;
    }
    if (flags & Flag_TextColor)
    {
        if (HasTextColor() != right.HasTextColor() || GetTextColor() != right.GetTextColor())
            return false;
    }
    if (flags & Flag_UnderlineColor)
    {
        if (HasUnderlineColor() != right.HasUnderlineColor() || GetUnderlineColor() != right.GetUnderlineColor())
            return false;
    }
    return true;
}

// ---------------------------------------------------------------------------------------------------------------
// Highlighter

// @0x1426668c0
Highlighter::Highlighter() : LastId(0), CorrectionPos(0), CorrectionLen(0), Valid(false), HasUnderline(0)
{
}

// Gives the desc the next free id and inserts a copy at its sorted place.
// @0x142666c80
HighlightDesc* Highlighter::CreateNewHighlighter(HighlightDesc* pdesc)
{
    Invalidate();
    for (;;)
    {
        ++LastId;
        if (!GetHighlighterPtr(LastId))
        {
            pdesc->Id   = LastId;
            UPInt index = Alg::LowerBound(Highlighters, pdesc->Id, HighlightIdLess::Less);
            Highlighters.InsertAt(index, *pdesc);
            return &Highlighters[index];
        }
    }
}

// Inserts a desc under its own (nonzero) id; null when the id is taken.
// @0x142666bc0
HighlightDesc* Highlighter::CreateHighlighter(const HighlightDesc& desc)
{
    Invalidate();
    if (!GetHighlighterPtr(desc.Id))
    {
        UPInt index = Alg::LowerBound(Highlighters, desc.Id, HighlightIdLess::Less);
        Highlighters.InsertAt(index, desc);
        return &Highlighters[index];
    }
    return 0;
}

// @0x142666f80
HighlightDesc* Highlighter::GetHighlighterPtr(unsigned id)
{
    UPInt index = Alg::LowerBound(Highlighters, id, HighlightIdLess::Less);
    if (index < Highlighters.GetSize() && Highlighters[index].Id == id)
        return &Highlighters[index];
    return 0;
}

// @0x142666e70
HighlightDesc Highlighter::GetHighlighter(unsigned id) const
{
    UPInt index = Alg::LowerBound(Highlighters, id, HighlightIdLess::Less);
    if (index < Highlighters.GetSize() && Highlighters[index].Id == id)
        return Highlighters[index];
    return HighlightDesc();
}

// @0x142667ba0
bool Highlighter::SetHighlighter(unsigned id, const HighlightInfo& info)
{
    HighlightDesc* pdesc = GetHighlighterPtr(id);
    if (pdesc)
    {
        pdesc->Info = info;
        Invalidate();
        return true;
    }
    return false;
}

// @0x142666da0
bool Highlighter::FreeHighlighter(unsigned id)
{
    UPInt index = Alg::LowerBound(Highlighters, id, HighlightIdLess::Less);
    if (index < Highlighters.GetSize() && Highlighters[index].Id == id)
    {
        Highlighters.RemoveAt(index);
        Invalidate();
        return true;
    }
    return false;
}

// @0x142667000
HighlighterPosIterator Highlighter::GetPosIterator(UPInt startPos, UPInt len) const
{
    return HighlighterPosIterator(this, startPos, len);
}

// @0x142667050
HighlighterRangeIterator Highlighter::GetRangeIterator(UPInt startPos, unsigned flags) const
{
    return HighlighterRangeIterator(this, startPos, flags);
}

// Maps text positions to glyph indices around an IME composition string: a highlight holding the composition
// position either moves by its own offset or grows by the composition's length, later ones shift past it.
// @0x142667c20
void Highlighter::UpdateGlyphIndices(const CompositionStringBase* pcs)
{
    CorrectionPos = CorrectionLen = 0;
    if (pcs)
    {
        CorrectionPos = pcs->GetPosition();
        CorrectionLen = pcs->GetLength();
    }
    Invalidate();
    for (UPInt i = 0, n = Highlighters.GetSize(); i < n; ++i)
    {
        HighlightDesc& desc = Highlighters[i];
        desc.AdjStartPos    = desc.StartPos;
        desc.GlyphNum       = desc.Length;
        if (CorrectionLen > 0)
        {
            if (desc.ContainsPos(CorrectionPos))
            {
                if (desc.Offset >= 0)
                    desc.AdjStartPos += desc.Offset;
                else
                    desc.GlyphNum += CorrectionLen;
            }
            else if (desc.StartPos > CorrectionPos)
                desc.AdjStartPos += CorrectionLen;
        }
    }
}

// Cached: 0 not yet known, 1 some highlight underlines, -1 none does.
// @0x1426670b0
bool Highlighter::HasUnderlineHighlight() const
{
    if (HasUnderline == 0)
    {
        HasUnderline = -1;
        for (UPInt i = 0, n = Highlighters.GetSize(); i < n; ++i)
        {
            if (Highlighters[i].Info.HasUnderlineStyle())
            {
                HasUnderline = 1;
                break;
            }
        }
    }
    return HasUnderline == 1;
}

// Grows every highlight the range overlaps (to the right when it starts inside one, to the left - and possibly the
// right - when one starts inside it); a range that touches none becomes a highlight of its own.
// @0x142666a30
void Highlighter::Add(HighlightDesc& merge)
{
    bool         merged     = false;
    const UPInt& mergeStart = merge.StartPos;
    UPInt        mergeEnd   = merge.StartPos + merge.Length;
    for (UPInt i = 0, n = Highlighters.GetSize(); i < n; ++i)
    {
        HighlightDesc& desc      = Highlighters[i];
        const UPInt&   descStart = desc.StartPos;
        UPInt          descEnd   = desc.StartPos + desc.Length;
        if (mergeStart >= descStart && mergeStart <= descEnd)
        {
            if (mergeEnd <= descEnd)
                continue;   // already covered
            desc.Length  += mergeEnd - descEnd;
            desc.GlyphNum = desc.Length;
            merged        = true;
            Invalidate();
        }
        else if (descStart > mergeStart && descStart < mergeEnd)
        {
            UPInt grow = descStart - mergeStart;
            desc.StartPos   -= grow;
            desc.AdjStartPos = desc.StartPos;
            desc.Length     += grow;
            desc.GlyphNum    = desc.Length;
            merged           = true;
            Invalidate();
            if (descEnd <= mergeEnd)
            {
                desc.Length  += mergeEnd - descEnd;
                desc.GlyphNum = desc.Length;
            }
        }
    }
    if (!merged)
        CreateNewHighlighter(&merge);
}

// Cuts the range out of every highlight: one that holds it strictly inside splits in two (the right part is added
// after the walk), one inside it is dropped, the others lose the overlapping end.
// @0x142667740
void Highlighter::Remove(const HighlightDesc& cut)
{
    Array<HighlightDesc> rightParts;
    const UPInt&         cutStart = cut.StartPos;
    UPInt                cutEnd   = cut.StartPos + cut.Length;
    for (UPInt i = 0; i < Highlighters.GetSize(); ++i)
    {
        HighlightDesc& desc      = Highlighters[i];
        UPInt          descStart = desc.StartPos;
        UPInt          descEnd   = desc.StartPos + desc.Length;
        if (cutStart > descStart && cutStart < descEnd)
        {
            if (cutEnd < descEnd)
            {
                desc.Length   = cutStart - descStart;
                desc.GlyphNum = desc.Length;
                HighlightDesc right = desc;
                right.StartPos      = cutEnd;
                right.AdjStartPos   = right.StartPos;
                right.Length        = descEnd - cutEnd;
                right.GlyphNum      = right.Length;
                rightParts.PushBack(right);
                Invalidate();
            }
            else
            {
                desc.Length  -= descEnd - cutStart;
                desc.GlyphNum = desc.Length;
                Invalidate();
            }
        }
        else if (descStart >= cutStart && descStart < cutEnd)
        {
            if (descEnd <= cutEnd)
            {
                Highlighters.RemoveAt(i--);
                Invalidate();
            }
            else
            {
                UPInt shrink = cutEnd - descStart;
                desc.StartPos   += shrink;
                desc.AdjStartPos = desc.StartPos;
                desc.Length     -= shrink;
                desc.GlyphNum    = desc.Length;
                Invalidate();
            }
        }
    }
    for (UPInt i = 0; i < rightParts.GetSize(); ++i)
        CreateNewHighlighter(&rightParts[i]);
}

// @0x142667bf0
void Highlighter::SetSelectColor(const Color& color)
{
    for (UPInt i = 0, n = Highlighters.GetSize(); i < n; ++i)
        Highlighters[i].Info.BackgroundColor = color;
    Invalidate();
}

// @0x142667500
bool Highlighter::IsAnyCharSelected(UPInt selectStart, UPInt selectEnd)
{
    for (UPInt i = 0, n = Highlighters.GetSize(); i < n; ++i)
    {
        HighlightDesc& desc      = Highlighters[i];
        UPInt&         descStart = desc.StartPos;
        UPInt          descEnd   = descStart + desc.Length;
        if ((selectStart >= descStart && selectStart < descEnd) || (descStart >= selectStart && descStart < selectEnd))
            return true;
    }
    return false;
}

// ---------------------------------------------------------------------------------------------------------------
// HighlighterRangeIterator

// @0x142666930
HighlighterRangeIterator::HighlighterRangeIterator(const Highlighter* pmanager, UPInt startPos, unsigned flags)
    : pManager(pmanager), CurTextPos(startPos), CurRangeIndex(0), Flags(flags)
{
    InitCurDesc();
}

// Builds the run that starts at CurTextPos from the highlights with any of the wanted flags: the first one holding
// the position gives the run, the ones that do not carry all the flags layer on top and may shorten it, and the
// next highlight to start ends it. Empty stretches are skipped until a run is found or nothing follows.
// @0x142667220
void HighlighterRangeIterator::InitCurDesc()
{
    UPInt         nextStart;
    HighlightDesc desc;
    do
    {
        nextStart = SF_MAX_UPINT;
        for (UPInt i = 0, n = pManager->Highlighters.GetSize(); i < n; ++i)
        {
            const HighlightDesc& cur = pManager->Highlighters[i];
            if ((cur.Info.Flags & Flags) == 0)
                continue;
            if (cur.ContainsIndex(CurTextPos))
            {
                if (desc.IsEmpty())
                {
                    desc              = cur;
                    desc.GlyphNum    -= CurTextPos - desc.AdjStartPos;
                    desc.AdjStartPos  = CurTextPos;
                    if (desc.AdjStartPos + desc.GlyphNum > nextStart)
                    {
                        desc.GlyphNum = nextStart - desc.AdjStartPos;
                        nextStart     = desc.AdjStartPos + desc.GlyphNum;
                    }
                }
                else if ((cur.Info.Flags & Flags) != Flags)
                {
                    desc.Info.Prepend(cur.Info);
                    desc.GlyphNum = Alg::PMin(cur.AdjStartPos + cur.GlyphNum, desc.AdjStartPos + desc.GlyphNum) -
                                    desc.AdjStartPos;
                    nextStart = desc.AdjStartPos + desc.GlyphNum;
                }
            }
            if (cur.AdjStartPos > CurTextPos)
            {
                nextStart = Alg::PMin(nextStart, cur.AdjStartPos);
                if (!desc.IsEmpty() && desc.AdjStartPos + desc.GlyphNum > nextStart)
                    desc.GlyphNum = nextStart - desc.AdjStartPos;
            }
        }
        CurDesc    = desc;
        CurTextPos = nextStart;
    } while (desc.IsEmpty() && nextStart != SF_MAX_UPINT);
}

// @0x142666980
HighlightDesc HighlighterRangeIterator::operator*()
{
    return CurDesc;
}

// @0x1426669f0
void HighlighterRangeIterator::operator++(int)
{
    if (!IsFinished())
        InitCurDesc();
}

// @0x1426676c0
bool HighlighterRangeIterator::IsFinished() const
{
    return CurRangeIndex >= pManager->Highlighters.GetSize() || CurDesc.GlyphNum == 0;
}

// ---------------------------------------------------------------------------------------------------------------
// HighlighterPosIterator

// @0x1426668e0
HighlighterPosIterator::HighlighterPosIterator(const Highlighter* pmanager, UPInt startPos, UPInt len)
    : pManager(pmanager), CurAdjStartPos(startPos), NumGlyphs(len)
{
    InitCurDesc();
}

// One glyph: every highlight holding it layers its info, later ones on top.
// @0x142667100
void HighlighterPosIterator::InitCurDesc()
{
    if (!IsFinished())
    {
        HighlightDesc desc;
        for (UPInt i = 0, n = pManager->Highlighters.GetSize(); i < n; ++i)
        {
            const HighlightDesc& cur = pManager->Highlighters[i];
            if (cur.ContainsIndex(CurAdjStartPos))
                desc.Info.Prepend(cur.Info);
        }
        CurDesc          = desc;
        CurDesc.GlyphNum = 1;
    }
    else
    {
        CurDesc.Info.Reset();
        CurDesc.GlyphNum = 0;
    }
    CurDesc.AdjStartPos = CurAdjStartPos;
    CurDesc.Id          = 0;
}

void HighlighterPosIterator::operator++(int)
{
    if (!IsFinished())
    {
        ++CurAdjStartPos;
        InitCurDesc();
    }
}

// @0x142666a10
void HighlighterPosIterator::operator+=(UPInt p)
{
    if (!IsFinished() && p > 0)
    {
        CurAdjStartPos += p;
        InitCurDesc();
    }
}

// @0x1426676b0
bool HighlighterPosIterator::IsFinished() const
{
    return CurAdjStartPos >= NumGlyphs;
}

}}} // namespace Scaleform::Render::Text
