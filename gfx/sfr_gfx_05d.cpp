// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_StaticText, static text: the
// DefineText / DefineText2 tags (StaticTextDef: glyph runs with font, colour, offset and height), its instance
// (StaticTextCharacter: the runs laid out once into a LineBuffer and drawn as a text node), and the text snapshot data
// the AS2 TextSnapshot class queries (selection, search, hit test, glyph visit).
// MS2-UNIT: sfr_gfx_05d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425df980-0x1425e33f0 .text$mn
// MS2-PIN: ??_7StaticTextDef@GFx@Scaleform@@6B@ 0x14318c5e0
// MS2-PIN: ??_7StaticTextCharacter@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@2@@ 0x14318c630
// MS2-PIN: ??_7StaticTextCharacter@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@12@@ 0x14318c8b0
// MS2-PIN: ??_7FontHandle@GFx@Scaleform@@6B@ 0x143189e70
// MS2-PIN: ??_7FontHandle@Text@Render@Scaleform@@6B@ 0x1431899e8
// MS2-PIN: ??_7?$RefCountBase@VFontHandle@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x1431899e0
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x14318ea90
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7?$RefCountBaseNTS@UTextFilter@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143189a00
// MS2-PIN: ??_7TextFilter@Text@Render@Scaleform@@6B@ 0x1431899f8

#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/gfx_statictextcharacter.h"
#include "../include/gfx/gfx_textsnapshot.h"
#include "../include/gfx/gfx_fonthandle.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_stream.h"
#include "../include/render/render_filters.h"
#include "../include/render/render_math2d.h"
#include "../include/render/render_twips.h"
#include "../include/kernel/sf_utf8util.h"
#include <float.h>

namespace Scaleform { namespace Render { namespace Math2D {

// @0x1425df980
template CoordType PointToSegmentPos<PointF>(const PointF& p1, const PointF& p2, const PointF& p);

}}} // namespace Scaleform::Render::Math2D

namespace Scaleform { namespace Alg {

// Round half away from zero (its COMDAT copy here).
// @0x1425df9e0
int IRound(float a)
{
    return (a > 0.0) ? int(a + 0.5) : int(a - 0.5);
}

}} // namespace Scaleform::Alg

namespace Scaleform { namespace GFx {

typedef Render::Text::LineBuffer LineBuffer;

// Movie::GetHeap is vftable +0x178 of the MovieImpl (whose vtable is not recovered).
typedef MemoryHeap* (*MovieGetHeapFn)(MovieImpl*);
static inline MemoryHeap* GetMovieImplHeap(MovieImpl* proot)
{
    return (*(MovieGetHeapFn*)(*(UByte**)proot + 0x178))(proot);
}

// Twips rounded to whole twips, half away from zero.
static inline int RoundTwips(float v)
{
    return (v > 0) ? int(double(v) + 0.5) : int(double(v) - 0.5);
}

// The instance lays the runs out once: each run becomes one line of the buffer, positioned relative to the top-left
// of the text box in the instance's own space.
// @0x1425dfa10
// MS2-FUNCTIONAL: register allocation and stack layout (the exe frame is 0x10 larger)
StaticTextCharacter::StaticTextCharacter(StaticTextDef* pdef, MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot,
                                         InteractiveObject* parent, ResourceId id)
    : DisplayObject(pasRoot, parent, id), pDef(pdef), pHighlight(0), Flags(0)
{
    Matrix invm = pdef->MatrixPriv;
    invm.Invert();
    RectF    r(RectF::NoInit);
    invm.EncloseTransform(&r, pdef->TextRect);
    unsigned textPos = 0;
    r.ExpandToPoint(Render::PointF(0, 0));

    for (unsigned i = 0, n = (unsigned)pdef->TextRecords.GetSize(); i < n; ++i)
    {
        const StaticTextRecord* prec = pdef->TextRecords.Records[i];

        ResourceBindData fontData = pbindingDefImpl->GetResourceBinding().GetResourceData(prec->pFont);
        FontResource*    pfont    = (FontResource*)fontData.pResource.GetPtr();
        if (!pfont)
        {
            Log* plog = pbindingDefImpl->GetLog();
            if (plog)
                plog->LogError("Text style with undefined font; FontId = %d", prec->FontId);
            return;
        }

        // An imported font may be swapped by a localization font library with other advances; the layout here
        // would not follow. Warn once per definition.
        if (!pdef->HasInstances())
        {
            for (ImportData* pimport = pbindingDefImpl->GetDataDef()->GetFirstImport(); pimport != 0;
                 pimport = pimport->pNext)
            {
                for (unsigned j = 0; j < pimport->Imports.GetSize(); j++)
                {
                    if (pimport->Imports[j].BindIndex == prec->pFont.GetBindIndex())
                    {
                        Log* plog = pbindingDefImpl->GetLog();
                        if (plog)
                            plog->LogWarning("Static text uses imported font! FontId = %d, import name = %s",
                                             prec->FontId, pimport->Imports[j].SymbolName.ToCStr());
                    }
                }
            }
        }

        Ptr<FontHandle> pfontHandle = *SF_NEW FontHandle(0, pfont->GetFont());

        // Short lines (8-bit fields) unless the run is long or the font has a layout (then the line gets real
        // dimensions, which may not fit).
        unsigned          glyphsCount = (unsigned)prec->Glyphs.GetSize();
        LineBuffer::Line* pline;
        if (glyphsCount <= 255 && !pfont->GetFont()->HasLayout())
            pline = TextGlyphRecords.InsertNewLine(i, glyphsCount, 2, LineBuffer::Line8);
        else
            pline = TextGlyphRecords.InsertNewLine(i, glyphsCount, 2, LineBuffer::Line32);

        pline->SetTextPos(textPos);
        textPos += glyphsCount;

        Render::PointF offset = prec->Offset;
        float          lineHeight;
        if (pfont->GetFont()->HasLayout())
        {
            // With ascent / descent the line can carry a baseline (the text height is taken as the ascent), which
            // the snapshot selection needs.
            Double fontScale = prec->TextHeight / 1024;
            offset.y -= prec->TextHeight;
            offset.x += -r.x1;
            offset.y += -r.y1;
            pline->SetBaseLineOffset(prec->TextHeight);
            lineHeight = float(prec->TextHeight + pfont->GetFont()->GetDescent() * fontScale);
        }
        else
        {
            offset.x += -r.x1;
            offset.y += -r.y1;
            lineHeight = 0;
        }
        pline->SetOffset(RoundTwips(offset.x), RoundTwips(offset.y));
        pline->SetDimensions(0, 0);

        LineBuffer::GlyphInserter gins(pline->GetGlyphs(), glyphsCount, pline->GetFormatData());
        int                       advance = 0;
        for (unsigned j = 0; j < glyphsCount; ++j, ++gins)
        {
            LineBuffer::GlyphEntry& glyph = gins.GetGlyph();
            glyph.SetLength(1);
            glyph.SetIndex(prec->Glyphs[j].GlyphIndex);
            glyph.SetAdvance((int)prec->Glyphs[j].GlyphAdvance);
            advance += (int)prec->Glyphs[j].GlyphAdvance;
            glyph.SetFontSize((float)Render::TwipsToPixels(prec->TextHeight));
            if (j == 0)
            {
                gins.AddFont(pfontHandle);
                gins.AddColor(prec->ColorV);
            }
        }

        if (pfont->GetFont()->HasLayout())
        {
            pline->SetDimensions(Alg::Max(0, advance), Alg::IRound(lineHeight));
            pline->SetTextLength(glyphsCount);
            r.ExpandToPoint(Render::PointF(float(pline->GetOffsetX() + pline->GetWidth()),
                                           float(pline->GetOffsetY() + pline->GetHeight())));
        }
    }
    TextGlyphRecords.SetVisibleRect(r);
    TextGlyphRecords.SetStaticText();
    Filter.SetDefaultShadow();
    pdef->SetHasInstances();

    RecreateVisibleTextLayout();
}

// @0x1425e0400
StaticTextSnapshotData::StaticTextSnapshotData()
{
    SelectColor = Render::Color(255, 255, 0, 255);
}

// @0x1425e0440
StaticTextCharacter::~StaticTextCharacter()
{
    if (pHighlight)
        delete pHighlight;
}

// Builds the snapshot string: each line's characters, with '\n' where a line starts at the x of the first one.
// @0x1425e0720
void StaticTextSnapshotData::Add(StaticTextCharacter* pstChar)
{
    CharRef cRef;
    cRef.pChar     = pstChar;
    cRef.CharCount = 0;
    float xoffset  = 0;
    bool  bfirst   = true;

    for (LineBuffer::Iterator iter = pstChar->TextGlyphRecords.Begin(); !iter.IsFinished(); ++iter)
    {
        LineBuffer::Line& line        = *iter;
        float             lineXOffset = float(line.GetOffsetX());
        if (!bfirst && lineXOffset == xoffset)
            SnapshotString.AppendChar('\n');
        else if (bfirst)
            xoffset = lineXOffset;
        LineBuffer::GlyphIterator glyphIt = line.Begin();
        Render::Font*             pfont   = glyphIt.GetFont();
        if (!pfont)
            continue;
        for (; !glyphIt.IsFinished(); ++glyphIt)
        {
            LineBuffer::GlyphEntry& glyph = glyphIt.GetGlyph();
            int                     ucs2  = pfont->GetCharValue(glyph.GetIndex());
            if (ucs2 == -1)
                continue;
            cRef.CharCount++;
            SnapshotString.AppendChar(ucs2);
        }
        bfirst = false;
    }

    StaticTextCharRefs.PushBack(cRef);
}

// @0x1425e0a20
StaticTextRecord* StaticTextRecordList::AddRecord()
{
    StaticTextRecord* precord = SF_HEAP_AUTO_NEW(this) StaticTextRecord;
    if (precord)
        Records.PushBack(precord);
    return precord;
}

// @0x1425e0af0
void StaticTextCharacter::AdvanceFrame(bool nextFrame, float framePos)
{
    SF_UNUSED(framePos);
    if (nextFrame)
        Flags |= Flags_NextFrame;
    else
        Flags &= ~Flags_NextFrame;
}

// @0x1425e0be0
void StaticTextRecordList::Clear()
{
    for (UPInt i = 0, n = Records.GetSize(); i < n; i++)
        if (Records[i])
            delete Records[i];
    Records.Clear();
}

// The point of r nearest to p, for p outside r: the corner of its region, or its projection on the near edge.
// @0x1425e0cd0
Render::PointF ClosestPointOnRectangle(const RectF& r, const Render::PointF& p)
{
    const Render::PointF& tl = r.TopLeft();
    const Render::PointF& tr = r.TopRight();
    const Render::PointF& bl = r.BottomLeft();
    const Render::PointF& br = r.BottomRight();

    // column in the low nibble, row in the high one: 0 before, 1 inside, 2 after
    UInt32 region = 0;
    if (p.x <= tl.x)
        region |= 0x00;
    else if (p.x >= tr.x)
        region |= 0x02;
    else
        region |= 0x01;
    if (p.y <= tl.y)
        region |= 0x00;
    else if (p.y >= bl.y)
        region |= 0x20;
    else
        region |= 0x10;

    float          t;
    Render::PointF ret(FLT_MAX, FLT_MAX);
    switch (region)
    {
    case 0x00:
        return tl;
    case 0x10:
        t     = Render::Math2D::PointToSegmentPos(tl, bl, p);
        ret.x = tl.x + (bl.x - tl.x) * t;
        ret.y = tl.y + (bl.y - tl.y) * t;
        return ret;
    case 0x20:
        return bl;
    case 0x01:
        t     = Render::Math2D::PointToSegmentPos(tl, tr, p);
        ret.x = tl.x + (tr.x - tl.x) * t;
        ret.y = tl.y + (tr.y - tl.y) * t;
        return ret;
    case 0x11: // inside: the callers test that first
    case 0x21:
        t     = Render::Math2D::PointToSegmentPos(bl, br, p);
        ret.x = bl.x + (br.x - bl.x) * t;
        ret.y = bl.y + (br.y - bl.y) * t;
        return ret;
    case 0x02:
        return tr;
    case 0x12:
        t     = Render::Math2D::PointToSegmentPos(tr, br, p);
        ret.x = tr.x + (br.x - tr.x) * t;
        ret.y = tr.y + (br.y - tr.y) * t;
        return ret;
    case 0x22:
        return br;
    }
    return ret;
}

// @0x1425e0f10
Ptr<Render::TreeNode> StaticTextCharacter::CreateRenderNode(Render::ContextImpl::Context& context) const
{
    Ptr<Render::TreeText> ptext = *context.CreateEntry<Render::TreeText>();
    return ptext;
}

// @0x1425e0f80
StaticTextCharacter::HighlightDesc* StaticTextCharacter::CreateTextHighlighter()
{
    if (!pHighlight)
        pHighlight = SF_HEAP_NEW(GetMovieImplHeap(FindMovieImpl())) HighlightDesc;
    return pHighlight;
}

// Text has no shape: the box is hit even for shape tests.
// @0x1425e0ff0
bool StaticTextDef::DefPointTestLocal(const PointF& pt, bool testShape, const DisplayObjectBase* pinst) const
{
    SF_UNUSED2(testShape, pinst);
    return TextRect.Contains(pt);
}

// A case-insensitive search (ASCII letters only) ignores newlines in the snapshot string; indexes count characters
// without them.
// @0x1425e1020
int StaticTextSnapshotData::FindTextA(UPInt start, const char* query, bool caseSensitive) const
{
    int         startIdx = (int)start;
    UInt32      chr;
    UInt32      first = UTF8Util::DecodeNextChar(&query);
    const char* pstr  = SnapshotString.ToCStr();

    for (int i = 0; (chr = UTF8Util::DecodeNextChar(&pstr)) != 0; i++)
    {
        if (i >= startIdx && ((caseSensitive && chr == first) ||
                              (!caseSensitive && SFtoupper(chr) == SFtoupper(first))))
        {
            const char* s1 = pstr;
            const char* s2 = query;
            UInt32      c1, c2 = 0;
            int         skipped;
            for (;;)
            {
                skipped = -1;
                c2      = UTF8Util::DecodeNextChar(&s2);
                do
                {
                    c1 = UTF8Util::DecodeNextChar(&s1);
                    ++skipped;
                } while (c1 == '\n');

                if (c1 == 0 || c2 == 0)
                    break;
                if (caseSensitive)
                {
                    if (c1 != c2)
                        break;
                }
                else if (SFtoupper(c1) != SFtoupper(c2))
                    break;
            }
            if (c2 == 0)
                return i;
            if (c1 == 0)
                return -1;
            i -= skipped;
        }
        else if (chr == '\n')
            --i;
    }
    return -1;
}

// @0x1425e1190
void SF_STDCALL GFx_DefineTextLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    UInt16             characterId = p->ReadU16();
    Ptr<StaticTextDef> pch = *SF_HEAP_NEW_ID(p->GetLoadHeap(), StatMD_CharDefs_Mem) StaticTextDef();
    p->LogParse("TextCharacter, id = %d\n", characterId);
    pch->Read(p, tagInfo.TagType);
    p->AddResource(ResourceId(characterId), pch);
}

// @0x1425e12e0
// MS2-FUNCTIONAL: the shared CharacterDef bounds virtuals take a morph ratio (4.1.18 ones take none)
RectF StaticTextCharacter::GetBounds(const Matrix& transform) const
{
    RectF r(RectF::NoInit);
    transform.EncloseTransform(&r, pDef->GetBoundsLocal());
    return r;
}

// @0x1425e1360
UPInt StaticTextSnapshotData::GetCharCount() const
{
    UPInt count = 0;
    for (UPInt i = 0; i < StaticTextCharRefs.GetSize(); i++)
        count += StaticTextCharRefs[i].CharCount;
    return count;
}

// @0x1425e1460
CharacterDef* StaticTextCharacter::GetCharacterDef() const
{
    return pDef;
}

// @0x1425e1470
float StaticTextRecord::GetCumulativeAdvance() const
{
    float advance = 0;
    for (UPInt i = 0, n = Glyphs.GetSize(); i < n; i++)
        advance += Glyphs[i].GlyphAdvance;
    return advance;
}

// @0x1425e14e0
const Render::Matrix2F& StaticTextCharacter::GetMatrix() const
{
    return OrigMatrix;
}

// @0x1425e14f0
// MS2-FUNCTIONAL: the shared CharacterDef bounds virtuals take a morph ratio (4.1.18 ones take none)
RectF StaticTextCharacter::GetRectBounds(const Matrix& transform) const
{
    RectF r(RectF::NoInit);
    transform.EncloseTransform(&r, pDef->GetRectBoundsLocal());
    return r;
}

// The selected characters of all fields in order, newlines kept on request.
// @0x1425e1570
String StaticTextSnapshotData::GetSelectedText(bool inclLineEndings) const
{
    String      ret;
    UPInt       baseIdx = 0;
    UPInt       textIdx = 0;
    const char* pchar   = SnapshotString.ToCStr();
    UInt32      c;
    for (UPInt i = 0; i < StaticTextCharRefs.GetSize(); i++)
    {
        StaticTextCharacter::HighlightDesc* phighlight = StaticTextCharRefs[i].pChar->GetTextHighlighter();
        if (!phighlight)
            continue;

        for (Render::Text::HighlighterRangeIterator ranges = phighlight->GetManager().GetRangeIterator();
             !ranges.IsFinished(); ++ranges)
        {
            Render::Text::HighlightDesc desc = *ranges;
            desc.StartPos += baseIdx;
            UPInt& startIdx = desc.StartPos;
            UPInt  endIdx   = startIdx + desc.Length;
            if (endIdx <= textIdx)
                continue;
            while (textIdx < startIdx)
            {
                c = UTF8Util::DecodeNextChar(&pchar);
                if (c == '\n')
                    textIdx--;
                textIdx++;
            }
            for (UPInt j = textIdx; j < endIdx; j++)
            {
                do
                {
                    c = UTF8Util::DecodeNextChar(&pchar);
                    if (inclLineEndings && c == '\n')
                        ret.AppendChar(c);
                } while (c == '\n');
                ret.AppendChar(c);
            }
            textIdx = endIdx;
        }
        baseIdx += StaticTextCharRefs[i].CharCount;
    }
    return ret;
}

// @0x1425e1740
String StaticTextSnapshotData::GetSubString(UPInt start, UPInt end, bool inclLineEndings) const
{
    String      ret;
    const char* pchar = SnapshotString.ToCStr();
    UInt32      c;
    while (start < end && (c = UTF8Util::DecodeNextChar(&pchar)) != 0)
    {
        if (c != '\n')
        {
            ret.AppendChar(c);
            start++;
        }
        else if (inclLineEndings)
            ret.AppendChar(c);
    }
    return ret;
}

// @0x1425e17e0
DisplayObjectBase::TopMostResult StaticTextCharacter::GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr)
{
    pdescr->pResult = GetTopMostMouseEntityDef(pDef, pt, pdescr->TestAll, pdescr->pIgnoreMC);
    return pdescr->pResult ? TopMost_Found : TopMost_FoundNothing;
}

// @0x1425e1820
CharacterDef::CharacterDefType StaticTextCharacter::GetType() const
{
    return CharacterDef::StaticText;
}

// The character under (x, y): the field containing the point, else the nearest field within closedist (taking the
// point on its box); then the line and the glyph at that point.
// @0x1425e1840
// MS2-FUNCTIONAL: the exe calls Matrix2x4::Invert out of line on a copy and maps through the result
int StaticTextSnapshotData::HitTestTextNearPos(float x, float y, float closedist) const
{
    StaticTextCharacter* pclosest = 0;
    float                minDist  = FLT_MAX;
    UPInt                charBase = 0, baseIdx = 0;
    float                fixedX = 0, fixedY = 0;
    Render::PointF       pt(x, y);

    for (UPInt i = 0; i < StaticTextCharRefs.GetSize(); i++)
    {
        StaticTextCharacter* pstc = StaticTextCharRefs[i].pChar;
        Render::PointF       ip   = pstc->GetMatrix().TransformByInverse(pt);
        RectF&               box  = pstc->TextGlyphRecords.Geom.VisibleRect;
        if (box.Contains(ip))
        {
            pclosest = pstc;
            baseIdx  = charBase;
            fixedX   = ip.x;
            fixedY   = ip.y;
            break;
        }
        Render::PointF rp   = ClosestPointOnRectangle(box, ip);
        float          dist = Render::Math2D::Distance(ip, rp);
        if (dist < closedist && dist < minDist)
        {
            pclosest = pstc;
            minDist  = dist;
            baseIdx  = charBase;
            fixedX   = rp.x;
            fixedY   = rp.y;
        }
        charBase += StaticTextCharRefs[i].CharCount;
    }

    if (!pclosest)
        return -1;

    fixedX -= pclosest->TextGlyphRecords.Geom.VisibleRect.x1;
    fixedY -= pclosest->TextGlyphRecords.Geom.VisibleRect.y1;

    LineBuffer::Iterator it = pclosest->TextGlyphRecords.FindLineAtOffset(Render::PointF(fixedX, fixedY));
    if (!it.IsFinished())
    {
        LineBuffer::Line& line     = *it;
        float             lineOffX = float(line.GetOffsetX());
        if (fixedX >= lineOffX && fixedX <= lineOffX + float(line.GetWidth()))
        {
            float    xInLine = fixedX - lineOffX;
            int      xoffset = 0;
            unsigned j       = 0;
            LineBuffer::GlyphIterator git = line.Begin();
            for (; !git.IsFinished(); ++git)
            {
                const LineBuffer::GlyphEntry& ge = git.GetGlyph();
                xoffset += ge.GetAdvance();
                if (xoffset > xInLine)
                    break;
                j += ge.GetLength();
            }
            return (int)(line.GetTextPos() + j + baseIdx);
        }
    }
    return -1;
}

// @0x1425e1bc0
bool StaticTextSnapshotData::IsSelected(UPInt start, UPInt end) const
{
    String ret;
    UPInt  baseIdx = 0, charStart, charEnd;
    for (UPInt i = 0; i < StaticTextCharRefs.GetSize(); i++)
    {
        StaticTextCharacter::HighlightDesc* phighlight = StaticTextCharRefs[i].pChar->GetTextHighlighter();
        if (!phighlight)
            continue;
        charStart = baseIdx;
        charEnd   = baseIdx + StaticTextCharRefs[i].CharCount;
        if ((start >= charStart && start < charEnd) || (charStart >= start && charStart < end))
        {
            if (phighlight->GetManager().IsAnyCharSelected(start - baseIdx, end - baseIdx))
                return true;
        }
        baseIdx += StaticTextCharRefs[i].CharCount;
    }
    return false;
}

// @0x1425e1cb0
bool StaticTextCharacter::PointTestLocal(const PointF& pt, UByte hitTestMask) const
{
    return pDef->DefPointTestLocal(pt, (hitTestMask & 1) != 0, this);
}

// The tag: text box, matrix, the bit widths of the glyph entries, then style changes and glyph runs alternating
// (a run takes the style values in effect).
// @0x1425e1cd0
void StaticTextDef::Read(LoadProcess* p, TagType tagType)
{
    Stream* in = p->GetStream();

    in->ReadRect(&TextRect);
    in->LogParse("  TextRect = { l: %f, t: %f, r: %f, b: %f }\n", (float)TextRect.x1, (float)TextRect.y1,
                 (float)TextRect.x2, (float)TextRect.y2);

    in->ReadMatrix(&MatrixPriv);
    in->LogParse("  mat:\n");
    in->LogParseClass(MatrixPriv);

    int glyphBits   = in->ReadU8();
    int advanceBits = in->ReadU8();

    in->LogParse("begin text records\n");

    bool                      lastWasStyle = false;
    Render::PointF            offset;
    Color                     color;
    float                     textHeight = 0;
    UInt16                    fontId     = 0;
    ResourcePtr<FontResource> pfont;

    offset.x = offset.y = 0.0f;

    for (;;)
    {
        int firstByte = in->ReadU8();
        if (firstByte == 0)
        {
            in->LogParse("end text records\n");
            break;
        }

        if (!lastWasStyle)
        {
            lastWasStyle = true;

            bool hasFont    = (firstByte >> 3) & 1;
            bool hasColor   = (firstByte >> 2) & 1;
            bool hasYOffset = (firstByte >> 1) & 1;
            bool hasXOffset = (firstByte >> 0) & 1;

            in->LogParse("  text style change\n");

            if (hasFont)
            {
                fontId = in->ReadU16();
                in->LogParse("  HasFont: font id = %d\n", fontId);
                ResourceHandle hres;
                p->GetResourceHandle(&hres, ResourceId(fontId));
                pfont.SetFromHandle(hres);
            }
            if (hasColor)
            {
                if (tagType == Tag_DefineText)
                    in->ReadRgb(&color);
                else
                    in->ReadRgba(&color);
                in->LogParse("  HasColor\n");
            }
            if (hasXOffset)
            {
                offset.x = (SInt16)in->ReadU16();
                in->LogParse("  XOffset = %g\n", offset.x);
            }
            if (hasYOffset)
            {
                offset.y = (SInt16)in->ReadU16();
                in->LogParse("  YOffset = %g\n", offset.y);
            }
            if (hasFont)
            {
                textHeight = in->ReadU16();
                in->LogParse("  TextHeight = %g\n", textHeight);
            }
        }
        else
        {
            lastWasStyle = false;

            // the first run may hold more than 127 glyphs: the count is not masked
            int glyphCount = firstByte;

            StaticTextRecord* precord = TextRecords.AddRecord();
            if (precord)
            {
                precord->Offset     = offset;
                precord->pFont      = pfont;
                precord->TextHeight = textHeight;
                precord->ColorV     = color;
                precord->FontId     = fontId;
                precord->Read(in, glyphCount, glyphBits, advanceBits);

                offset.x += precord->GetCumulativeAdvance();
            }
            in->LogParse("  GlyphRecords: count = %d\n", glyphCount);
        }
    }
}

// @0x1425e23d0
void StaticTextRecord::Read(Stream* in, int glyphCount, int glyphBits, int advanceBits)
{
    Glyphs.Resize(glyphCount);
    for (int i = 0; i < glyphCount; i++)
    {
        Glyphs[i].GlyphIndex   = in->ReadUInt(glyphBits);
        Glyphs[i].GlyphAdvance = (float)in->ReadSInt(advanceBits);
    }
}

// @0x1425e24c0
void StaticTextCharacter::RecreateVisibleTextLayout()
{
    Render::TreeText*            ptextNode = static_cast<Render::TreeText*>(GetRenderNode());
    Render::TextLayout::Builder bld(Memory::GetGlobalHeap());
    if (pHighlight && !pHighlight->IsValid())
    {
        pHighlight->GetManager().UpdateGlyphIndices(0);
        pHighlight->Validate();
    }
    Render::Text::TextFieldParam param;
    Render::Text::LoadTextFieldParamFromTextFilter(param, Filter);
    if (pDef->IsAAForReadability())
    {
        param.TextParam.SetOptRead(true);
        param.TextParam.SetAutoFit(true);
        param.ShadowParam.SetOptRead(true);
        param.ShadowParam.SetAutoFit(true);
    }
    TextGlyphRecords.CreateVisibleTextLayout(bld, pHighlight ? &pHighlight->GetManager() : 0, param);
    bld.SetBounds(TextGlyphRecords.Geom.VisibleRect);
    ptextNode->SetLayout(bld);
}

// @0x1425e2890
void StaticTextCharacter::SetFilters(const Render::FilterSet* filters)
{
    if (!filters)
        return;
    TextFilter tf;
    for (unsigned i = 0; i < filters->GetFilterCount(); i++)
        tf.LoadFilterDesc(filters->GetFilter(i));
    SetTextFilters(tf);
}

// The node gets the placement with the definition's own matrix in front.
// @0x1425e2990
void StaticTextCharacter::SetMatrix(const Matrix& m)
{
    OrigMatrix = m;
    Matrix2F mtx(m);
    mtx.Prepend(pDef->MatrixPriv);
    DisplayObject::SetMatrix(mtx);
}

// @0x1425e2b40
void StaticTextSnapshotData::SetSelectColor(const Render::Color& color)
{
    SelectColor = color;
    for (UPInt i = 0; i < StaticTextCharRefs.GetSize(); i++)
    {
        StaticTextCharacter* pstc = StaticTextCharRefs[i].pChar;
        if (pstc->GetTextHighlighter())
            pstc->GetTextHighlighter()->SetSelectColor(SelectColor);
    }
}

// @0x1425e2bb0
void StaticTextSnapshotData::SetSelected(UPInt start, UPInt end, bool selected) const
{
    UPInt baseIdx = 0, remaining = end - start, charStart, charEnd;
    for (UPInt i = 0; i < StaticTextCharRefs.GetSize(); i++)
    {
        charStart = baseIdx;
        charEnd   = baseIdx + StaticTextCharRefs[i].CharCount;
        if ((charStart >= start && charStart < end) || (start >= charStart && start < charEnd))
        {
            StaticTextCharacter*                pstc       = StaticTextCharRefs[i].pChar;
            StaticTextCharacter::HighlightDesc* phighlight = pstc->GetTextHighlighter();
            if (!phighlight)
                phighlight = pstc->CreateTextHighlighter();
            Render::Text::HighlightDesc desc;
            desc.Info.SetBackgroundColor(SelectColor);
            desc.StartPos    = (baseIdx > start) ? 0 : (start - baseIdx);
            desc.Length      = Alg::Min(remaining, StaticTextCharRefs[i].CharCount - desc.StartPos);
            desc.GlyphNum    = desc.Length;
            desc.AdjStartPos = desc.StartPos;
            if (selected)
                phighlight->GetManager().Add(desc);
            else
                phighlight->GetManager().Remove(desc);
            remaining -= desc.Length;
            pstc->RecreateVisibleTextLayout();
        }
        baseIdx = charEnd;
    }
}

// @0x1425e2d60
// MS2-FUNCTIONAL: the exe copies the shadow offset as an int and a float, cl as one 8-byte move
void StaticTextCharacter::SetTextFilters(const TextFilter& f)
{
    Filter = f;
    RecreateVisibleTextLayout();
}

// Visits the glyphs with index in [start, end): each gets the field's rotation and its origin in the parent space.
// @0x1425e2e00
void StaticTextSnapshotData::Visit(GlyphVisitor* pvisitor, UPInt start, UPInt end) const
{
    if (!pvisitor)
        return;
    UPInt glyphIdx = 0;
    for (UPInt i = 0, n = StaticTextCharRefs.GetSize(); i < n; ++i)
    {
        float                   glyphX = 0, glyphY = 0;
        StaticTextCharacter*    pstchar = StaticTextCharRefs[i].pChar;
        float                   charX = 0, charY = 0;
        const Render::Matrix2F& matChar = pstchar->GetMatrix();
        matChar.Transform(&charX, &charY);
        for (LineBuffer::Iterator iter = pstchar->TextGlyphRecords.Begin(); !iter.IsFinished(); ++iter)
        {
            LineBuffer::Line& line   = *iter;
            UPInt             runIdx = 0;
            float             xoff   = (float)line.GetOffsetX();
            if (xoff < glyphX)
                glyphX = xoff;
            glyphY = float(line.GetOffsetY() + line.GetLeading());
            LineBuffer::GlyphIterator glyphIt = line.Begin();
            Render::Font*             pfont   = glyphIt.GetFont();
            pvisitor->pFont      = pfont;
            pvisitor->ColorValue = glyphIt.GetColor();
            for (; !glyphIt.IsFinished(); ++glyphIt)
            {
                LineBuffer::GlyphEntry& glyph = glyphIt.GetGlyph();
                if (glyphIdx >= start && glyphIdx < end)
                {
                    pvisitor->RunIdx = runIdx;
                    pvisitor->Height = glyph.GetFontSize();
                    Render::Matrix2F mat;
                    mat.AppendRotation((float)matChar.GetRotation());
                    mat.M[0][3] += charX + glyphX;
                    mat.M[1][3] += charY + glyphY;
                    pvisitor->Matrix = mat;
                    RectF corners;
                    pfont->GetGlyphBounds(glyph.GetIndex(), &corners);
                    mat.EncloseTransform(&pvisitor->Corners, corners);
                    pvisitor->bSelected = IsSelected(glyphIdx, glyphIdx + 1);
                    pvisitor->OnVisit();
                    ++runIdx;
                }
                glyphX += glyph.GetAdvance();
                ++glyphIdx;
            }
        }
    }
}

}} // namespace Scaleform::GFx
