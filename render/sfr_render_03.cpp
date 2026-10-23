// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the 3D matrix product
// (Matrix3x4<float>::MultiplyMatrix) and Text_Core: the character / paragraph format records, their merge,
// intersection and hashing, and the per-document format caches of Text::Allocator.
// MS2-UNIT: sfr_render_03
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142604370-0x142608a30 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include <stdarg.h>
#include "ms2/scaleform/include/kernel/sf_simd.h"
#include "ms2/scaleform/include/render/render_matrix4x4.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/text_core.h"

namespace Scaleform { namespace Render {

using namespace SIMD;

// ---------------------------------------------------------------------------------------------------------------
// Matrix3F: three rows of (x, y, z, t), unaligned. Row i of the product is the sum of b's rows weighted by
// a's row i, plus a's own translation lane.

// @0x142604370
// MS2-FUNCTIONAL: the exe orders the SSE row products differently (register allocation)
template<>
void Matrix3F::MultiplyMatrix(const Matrix3F& a, const Matrix3F& b)
{
    Vector4f a0 = _mm_loadu_ps(a.M[0]);
    Vector4f a1 = _mm_loadu_ps(a.M[1]);
    Vector4f b1 = _mm_loadu_ps(b.M[1]);
    Vector4f b0 = _mm_loadu_ps(b.M[0]);
    Vector4f b2 = _mm_loadu_ps(b.M[2]);
    Vector4f transOnly = BitMask<0, 0, 0, 0xFFFFFFFF>();
    Vector4f a2 = _mm_loadu_ps(a.M[2]);

    _mm_storeu_ps(M[0], Add(Add(Add(Mul(Splat<1>(a0), b1), Mul(Splat<0>(a0), b0)), Mul(Splat<2>(a0), b2)),
                            _mm_and_ps(transOnly, a0)));
    _mm_storeu_ps(M[1], Add(Add(Add(Mul(Splat<1>(a1), b1), Mul(Splat<0>(a1), b0)), Mul(Splat<2>(a1), b2)),
                            _mm_and_ps(transOnly, a1)));
    _mm_storeu_ps(M[2], Add(Add(Add(Mul(Splat<1>(a2), b1), Mul(Splat<0>(a2), b0)), Mul(Splat<2>(a2), b2)),
                            _mm_and_ps(transOnly, a2)));
}

// The 2D matrix contributes only the x and y lanes; z and t pass through from the 3D side.
// MS2-FUNCTIONAL: same instructions, the exe schedules the xmm6-8 spills and loads differently
// @0x142604460
template<>
void Matrix3F::MultiplyMatrix(const Matrix3F& a, const Matrix2x4<float>& m)
{
    Vector4f a0 = _mm_loadu_ps(a.M[0]);
    Vector4f a1 = _mm_loadu_ps(a.M[1]);
    Vector4f a2 = _mm_loadu_ps(a.M[2]);
    Vector4f m0 = _mm_loadu_ps(m.M[0]);
    Vector4f m1 = _mm_loadu_ps(m.M[1]);

    // x lanes, then y lanes, then the z / t lanes passed through
    Vector4f r0 = Mul(Splat<0>(a0), m0);
    Vector4f r1 = Mul(Splat<0>(a1), m0);
    Vector4f r2 = Mul(Splat<0>(a2), m0);
    r0 = MulAdd(Splat<1>(a0), m1, r0);
    r1 = MulAdd(Splat<1>(a1), m1, r1);
    r2 = MulAdd(Splat<1>(a2), m1, r2);
    Vector4f zt = BitMask<0, 0, 0xFFFFFFFF, 0xFFFFFFFF>();
    r0 = Add(r0, _mm_and_ps(a0, zt));
    r1 = Add(r1, _mm_and_ps(a1, zt));
    r2 = Add(r2, _mm_and_ps(a2, zt));
    _mm_storeu_ps(M[0], r0);
    _mm_storeu_ps(M[1], r1);
    _mm_storeu_ps(M[2], r2);
}

// MS2-FUNCTIONAL: same instructions, the exe schedules the xmm6-8 spills and loads differently
// @0x142604500
template<>
void Matrix3F::MultiplyMatrix(const Matrix2x4<float>& m, const Matrix3F& b)
{
    Vector4f m0 = _mm_loadu_ps(m.M[0]);
    Vector4f m1 = _mm_loadu_ps(m.M[1]);
    Vector4f b0 = _mm_loadu_ps(b.M[0]);
    Vector4f b1 = _mm_loadu_ps(b.M[1]);
    Vector4f b2 = _mm_loadu_ps(b.M[2]);

    Vector4f r0 = Mul(Splat<0>(m0), b0);
    Vector4f r1 = Mul(Splat<0>(m1), b0);
    r0 = MulAdd(Splat<1>(m0), b1, r0);
    r1 = MulAdd(Splat<1>(m1), b1, r1);
    r0 = MulAdd(Splat<2>(m0), b2, r0);
    r1 = MulAdd(Splat<2>(m1), b2, r1);
    Vector4f transOnly = BitMask<0, 0, 0, 0xFFFFFFFF>();
    r0 = Add(r0, _mm_and_ps(m0, transOnly));
    r1 = Add(r1, _mm_and_ps(m1, transOnly));
    _mm_storeu_ps(M[0], r0);
    _mm_storeu_ps(M[1], r1);
    _mm_storeu_ps(M[2], b2);
}

namespace Text {

// Inline in this unit only, like the exe: elsewhere the destructor stays out of line (0x142606690).
inline void ParagraphFormat::FreeTabStops()
{
    SF_FREE(pTabStops);
    pTabStops = NULL;
}

// ---------------------------------------------------------------------------------------------------------------
// TextFormat

// @0x142605380
bool TextFormat::operator==(const TextFormat& f) const
{
    return PresentMask == f.PresentMask && FormatFlags == f.FormatFlags && ColorV == f.ColorV &&
           FontSize == f.FontSize &&
           IsFontListSet() == f.IsFontListSet() &&
           (!IsFontListSet() || String::CompareNoCase(FontList.ToCStr(), f.FontList.ToCStr()) == 0) &&
           LetterSpacing == f.LetterSpacing &&
           IsFontHandleSet() == f.IsFontHandleSet() &&
           (!IsFontHandleSet() || pFontHandle == f.pFontHandle ||
            (pFontHandle && f.pFontHandle && *pFontHandle == *f.pFontHandle)) &&
           IsUrlSet() == f.IsUrlSet() &&
           (!IsUrlSet() || String::CompareNoCase(Url.ToCStr(), f.Url.ToCStr()) == 0) &&
           ((pImageDesc && f.pImageDesc && *pImageDesc == *f.pImageDesc) || pImageDesc == f.pImageDesc);
}

// @0x142605820
UPInt TextFormat::HashFunctor::operator()(const TextFormat& data) const
{
    // the fixed size properties packed into four words, then the strings
    UPInt v[4] = { 0, 0, 0, 0 };
    if (data.PresentMask & (PresentMask_Color | PresentMask_Alpha))
        v[0] = data.ColorV;
    if (data.IsLetterSpacingSet())
        v[1] = (UPInt)(SPInt)data.LetterSpacing;
    if (data.IsFontSizeSet())
        v[1] |= (UPInt)data.FontSize << 16;
    v[0] |= (UPInt)data.FormatFlags << 24;
    v[1] |= (UPInt)data.PresentMask << 24;
    if (data.pFontHandle)
        v[2] = 1;
    if (data.IsImageDescSet() && data.pImageDesc)
        v[3] = data.pImageDesc->GetHash();

    UPInt hash = FixedSizeHash<UPInt>::SDBM_Hash(v, sizeof(v));
    if (data.IsFontListSet())
    {
        const String& fontList = data.FontList;
        hash ^= String::BernsteinHashFunctionCIS(fontList.ToCStr(), fontList.GetSize());
    }
    if (data.IsUrlSet())
    {
        const String& url = data.Url;
        hash ^= String::BernsteinHashFunctionCIS(url.ToCStr(), url.GetSize());
    }
    return hash;
}

// @0x1426067e0
UPInt HTMLImageTagDesc::GetHash() const
{
    UPInt v[4];
    v[0] = (UPInt)(SPInt)VSpace;
    v[1] = (UPInt)(SPInt)HSpace;
    v[2] = ParaId;
    v[3] = Alignment;
    UPInt hash = FixedSizeHash<UPInt>::SDBM_Hash(v, sizeof(v));
    hash ^= String::BernsteinHashFunctionCIS(Url.ToCStr(), Url.GetSize());
    hash ^= String::BernsteinHashFunctionCIS(Id.ToCStr(), Id.GetSize());
    return hash;
}

// @0x142606750
const String& TextFormat::GetFontList() const
{
    static String emptyStr;
    if (IsFontListSet())
        return FontList;
    return emptyStr;
}

// @0x142606ba0
void TextFormat::InitByDefaultValues()
{
    SetColor32(0);
    SetFontList("Times New Roman");
    SetFontSize(12);
    SetBold(false);
    SetItalic(false);
    SetUnderline(false);
    SetKerning(false);
    ClearAlpha();
    ClearLetterSpacing();
    ClearUrl();
}

// @0x142606fa0
TextFormat TextFormat::Intersection(const TextFormat& fmt) const
{
    TextFormat intersection(fmt.GetHeap());
    if (IsBoldSet() && fmt.IsBoldSet() && IsBold() == fmt.IsBold())
        intersection.SetBold(fmt.IsBold());
    if (IsItalicSet() && fmt.IsItalicSet() && IsItalic() == fmt.IsItalic())
        intersection.SetItalic(fmt.IsItalic());
    if (IsUnderlineSet() && fmt.IsUnderlineSet() && IsUnderline() == fmt.IsUnderline())
        intersection.SetUnderline(fmt.IsUnderline());
    if (IsKerningSet() && fmt.IsKerningSet() && IsKerning() == fmt.IsKerning())
        intersection.SetKerning(fmt.IsKerning());
    if (IsColorSet() && fmt.IsColorSet() && GetColor32() == fmt.GetColor32())
        intersection.SetColorARGB(fmt.GetColor32());
    if (IsAlphaSet() && fmt.IsAlphaSet() && GetAlpha() == fmt.GetAlpha())
        intersection.SetAlpha(fmt.GetAlpha());
    if (IsLetterSpacingSet() && fmt.IsLetterSpacingSet() && GetLetterSpacing() == fmt.GetLetterSpacing())
        intersection.SetLetterSpacingInFixp(fmt.GetLetterSpacingInFixp());
    if (IsFontSizeSet() && fmt.IsFontSizeSet() && GetFontSizeInFixp() == fmt.GetFontSizeInFixp())
        intersection.SetFontSizeInFixp(fmt.GetFontSizeInFixp());
    if (IsFontListSet() && fmt.IsFontListSet() &&
        String::CompareNoCase(FontList.ToCStr(), fmt.FontList.ToCStr()) == 0)
        intersection.SetFontList(fmt.GetFontList());
    if (IsFontHandleSet() && fmt.IsFontHandleSet() && GetFontHandle() == fmt.GetFontHandle())
        intersection.SetFontHandle(fmt.GetFontHandle());
    if (IsUrlSet() && fmt.IsUrlSet() && String::CompareNoCase(Url.ToCStr(), fmt.Url.ToCStr()) == 0)
        intersection.SetUrl(fmt.GetUrl());
    if (IsImageDescSet() && fmt.IsImageDescSet() && GetImageDesc() == fmt.GetImageDesc())
        intersection.SetImageDesc(fmt.GetImageDesc());
    return intersection;
}

// @0x1426074d0
bool TextFormat::IsFontSame(const TextFormat& fmt) const
{
    return ((IsFontListSet() && fmt.IsFontListSet() &&
             String::CompareNoCase(FontList.ToCStr(), fmt.FontList.ToCStr()) == 0) ||
            (IsFontHandleSet() && fmt.IsFontHandleSet() && pFontHandle == fmt.pFontHandle)) &&
           IsBold() == fmt.IsBold() && IsItalic() == fmt.IsItalic();
}

// @0x142607570
bool TextFormat::IsHTMLFontTagSame(const TextFormat& fmt) const
{
    return ((IsFontListSet() && fmt.IsFontListSet() &&
             String::CompareNoCase(FontList.ToCStr(), fmt.FontList.ToCStr()) == 0) ||
            (IsFontHandleSet() && fmt.IsFontHandleSet() && pFontHandle == fmt.pFontHandle)) &&
           (GetColor32() & 0xFFFFFFu) == (fmt.GetColor32() & 0xFFFFFFu) && GetAlpha() == fmt.GetAlpha() &&
           GetFontSize() == fmt.GetFontSize() && IsKerning() == fmt.IsKerning() &&
           GetLetterSpacing() == fmt.GetLetterSpacing();
}

// @0x142607870
TextFormat TextFormat::Merge(const TextFormat& fmt) const
{
    TextFormat merged(*this);
    if (fmt.IsBoldSet())
        merged.SetBold(fmt.IsBold());
    if (fmt.IsItalicSet())
        merged.SetItalic(fmt.IsItalic());
    if (fmt.IsUnderlineSet())
        merged.SetUnderline(fmt.IsUnderline());
    if (fmt.IsKerningSet())
        merged.SetKerning(fmt.IsKerning());
    if (fmt.IsColorSet())
        merged.SetColorARGB(fmt.GetColor32());
    if (fmt.IsAlphaSet())
        merged.SetAlpha(fmt.GetAlpha());
    if (fmt.IsLetterSpacingSet())
        merged.SetLetterSpacingInFixp(fmt.GetLetterSpacingInFixp());
    if (fmt.IsFontSizeSet())
        merged.SetFontSizeInFixp(fmt.GetFontSizeInFixp());
    if (fmt.IsFontListSet())
        merged.SetFontList(fmt.GetFontList());
    if (fmt.IsFontHandleSet())
        merged.SetFontHandle(fmt.GetFontHandle());
    if (fmt.IsUrlCleared())
        merged.ClearUrl();
    else if (fmt.IsUrlSet())
        merged.SetUrl(fmt.GetUrl());
    if (fmt.IsImageDescSet())
        merged.SetImageDesc(fmt.GetImageDesc());
    return merged;
}

// The style setters drop a font handle the new style no longer matches.

// @0x142607d90
void TextFormat::SetBold(bool bold)
{
    if (IsFontHandleSet() && IsBold() != bold)
        ClearFontHandle();
    if (bold)
        FormatFlags |= Format_Bold;
    else
        FormatFlags &= ~Format_Bold;
    PresentMask |= PresentMask_Bold;
}

// @0x142607e10
void TextFormat::SetFontHandle(FontHandle* pfontHandle)
{
    pFontHandle = pfontHandle;
    PresentMask |= PresentMask_FontHandle;
}

// @0x142607e60
void TextFormat::SetFontList(const String& fontList)
{
    if (IsFontHandleSet())
    {
        if (FontList.GetLength() != fontList.GetLength() ||
            String::CompareNoCase(FontList.ToCStr(), fontList.ToCStr()) != 0)
            ClearFontHandle();
    }
    FontList = fontList;
    PresentMask |= PresentMask_FontList;
    UpdateSingleFontName();
}

// @0x142607f40
void TextFormat::SetFontList(const char* pfontList, UPInt fontListSz)
{
    if (fontListSz == SF_MAX_UPINT)
        fontListSz = SFstrlen(pfontList);
    if (IsFontHandleSet())
    {
        if (FontList.GetLength() != fontListSz ||
            String::CompareNoCase(FontList.ToCStr(), pfontList, fontListSz) != 0)
            ClearFontHandle();
    }
    FontList.Clear();
    FontList.AppendString(pfontList, fontListSz);
    PresentMask |= PresentMask_FontList;
    UpdateSingleFontName();
}

// @0x142608030
// MS2-FUNCTIONAL: the exe shrink-wraps the rdi / r15 saves into the font handle branch; ours saves them in the prolog
void TextFormat::SetFontList(const wchar_t* pfontList, UPInt fontListSz)
{
    if (fontListSz == SF_MAX_UPINT)
        fontListSz = SFwcslen(pfontList);
    if (IsFontHandleSet())
    {
        bool same = (FontList.GetLength() == fontListSz);
        if (same)
        {
            for (UPInt i = 0; i < fontListSz; ++i)
            {
                if (SFtowlower((wchar_t)FontList.ToCStr()[i]) != SFtowlower(pfontList[i]))
                {
                    same = false;
                    break;
                }
            }
        }
        if (!same)
            ClearFontHandle();
    }
    FontList.Clear();
    FontList.AppendString(pfontList, fontListSz);
    PresentMask |= PresentMask_FontList;
    UpdateSingleFontName();
}

// @0x142608140
void TextFormat::SetFontName(const String& fontName)
{
    SetFontList(fontName);
}

// @0x142608150
void TextFormat::SetFontName(const char* pfontName, UPInt fontNameSz)
{
    if (fontNameSz == SF_MAX_UPINT)
        fontNameSz = SFstrlen(pfontName);
    SetFontList(pfontName, fontNameSz);
}

// @0x142608170
// MS2-FUNCTIONAL: SetFontList inlined: the exe shrink-wraps the rdi / r15 saves; ours saves them in the prolog
void TextFormat::SetFontName(const wchar_t* pfontName, UPInt fontNameSz)
{
    if (fontNameSz == SF_MAX_UPINT)
        fontNameSz = SFwcslen(pfontName);
    SetFontList(pfontName, fontNameSz);
}

// @0x1426082a0
void TextFormat::SetItalic(bool italic)
{
    if (IsFontHandleSet() && IsItalic() != italic)
        ClearFontHandle();
    if (italic)
        FormatFlags |= Format_Italic;
    else
        FormatFlags &= ~Format_Italic;
    PresentMask |= PresentMask_Italic;
}

// @0x142608330
void TextFormat::SetKerning(bool kerning)
{
    if (kerning)
        FormatFlags |= Format_Kerning;
    else
        FormatFlags &= ~Format_Kerning;
    PresentMask |= PresentMask_Kerning;
}

// @0x1426084d0
void TextFormat::SetUnderline(bool underline)
{
    if (underline)
        FormatFlags |= Format_Underline;
    else
        FormatFlags &= ~Format_Underline;
    PresentMask |= PresentMask_Underline;
}

// @0x142608500
void TextFormat::SetUrl(const String& url)
{
    Url = url;
    PresentMask |= PresentMask_Url;
}

// @0x142608530
void TextFormat::SetUrl(const char* purl, UPInt urlSz)
{
    if (urlSz == SF_MAX_UPINT)
        urlSz = SFstrlen(purl);
    Url.Clear();
    Url.AppendString(purl, urlSz);
    PresentMask |= PresentMask_Url;
}

// @0x1426085a0
void TextFormat::SetUrl(const wchar_t* purl, UPInt urlSz)
{
    if (urlSz == SF_MAX_UPINT)
        urlSz = SFwcslen(purl);
    Url.Clear();
    Url.AppendString(purl, urlSz);
    PresentMask |= PresentMask_Url;
}

// ---------------------------------------------------------------------------------------------------------------
// ParagraphFormat

// @0x142605330
ParagraphFormat& ParagraphFormat::operator=(const ParagraphFormat& src)
{
    BlockIndent = src.BlockIndent;
    Indent      = src.Indent;
    Leading     = src.Leading;
    LeftMargin  = src.LeftMargin;
    RightMargin = src.RightMargin;
    PresentMask = src.PresentMask;
    CopyTabStops(src.pTabStops);
    return *this;
}

// @0x142605710
UPInt ParagraphFormat::HashFunctor::operator()(const ParagraphFormat& data) const
{
    UPInt hash = 0;
    if (data.IsTabStopsSet() && data.pTabStops)
        hash = FixedSizeHash<unsigned>::SDBM_Hash(data.pTabStops, (data.pTabStops[0] + 1) * sizeof(unsigned));
    if (data.IsBlockIndentSet())
        hash ^= data.BlockIndent;
    if (data.IsIndentSet())
        hash ^= (UPInt)(SPInt)data.Indent << 8;
    if (data.IsLeadingSet())
        hash ^= (UPInt)(SPInt)data.Leading << 12;
    if (data.IsLeftMarginSet())
        hash ^= (UPInt)data.LeftMargin << 16;
    if (data.IsRightMarginSet())
        hash ^= (UPInt)data.RightMargin << 18;
    hash ^= ((UPInt)data.IsBullet() | ((UPInt)data.GetAlignment() << 1) | ((UPInt)data.PresentMask << 9)) ^
            ((UPInt)data.GetDisplay() << 10);
    return hash;
}

// @0x142605c10
void ParagraphFormat::AllocTabStops(unsigned num)
{
    FreeTabStops();
    pTabStops = (unsigned*)SF_ALLOC((num + 1) * sizeof(unsigned), StatRender_Text_Mem);
    pTabStops[0] = num;
}

// @0x1426060a0
void ParagraphFormat::CopyTabStops(const unsigned* psrcTabStops)
{
    if (psrcTabStops)
    {
        unsigned num = psrcTabStops[0];
        if (!pTabStops || pTabStops[0] != num)
            AllocTabStops(num);
        memcpy(pTabStops + 1, psrcTabStops + 1, num * sizeof(unsigned));
    }
    else
        FreeTabStops();
}

// @0x142606b20
const unsigned* ParagraphFormat::GetTabStops(unsigned* pnum) const
{
    if (pTabStops)
    {
        if (pnum)
            *pnum = pTabStops[0];
        return pTabStops + 1;
    }
    return NULL;
}

// @0x142606b40
void ParagraphFormat::InitByDefaultValues()
{
    SetAlignment(Align_Left);
    ClearBlockIndent();
    ClearBullet();
    ClearIndent();
    ClearLeading();
    ClearLeftMargin();
    ClearRightMargin();
    ClearTabStops();
}

// @0x142606ce0
ParagraphFormat ParagraphFormat::Intersection(const ParagraphFormat& fmt) const
{
    ParagraphFormat intersection;
    if (IsAlignmentSet() && fmt.IsAlignmentSet() && GetAlignment() == fmt.GetAlignment())
        intersection.SetAlignment(fmt.GetAlignment());
    if (IsBulletSet() && fmt.IsBulletSet() && IsBullet() == fmt.IsBullet())
        intersection.SetBullet(fmt.IsBullet());
    if (IsBlockIndentSet() && fmt.IsBlockIndentSet() && GetBlockIndent() == fmt.GetBlockIndent())
        intersection.SetBlockIndent(fmt.GetBlockIndent());
    if (IsIndentSet() && fmt.IsIndentSet() && GetIndent() == fmt.GetIndent())
        intersection.SetIndent(fmt.GetIndent());
    if (IsLeadingSet() && fmt.IsLeadingSet() && GetLeading() == fmt.GetLeading())
        intersection.SetLeading(fmt.GetLeading());
    if (IsLeftMarginSet() && fmt.IsLeftMarginSet() && GetLeftMargin() == fmt.GetLeftMargin())
        intersection.SetLeftMargin(fmt.GetLeftMargin());
    if (IsRightMarginSet() && fmt.IsRightMarginSet() && GetRightMargin() == fmt.GetRightMargin())
        intersection.SetRightMargin(fmt.GetRightMargin());
    if (IsTabStopsSet() && fmt.IsTabStopsSet() && TabStopsEqual(fmt.pTabStops))
        intersection.SetTabStops(fmt.pTabStops);
    if (IsDisplaySet() && fmt.IsDisplaySet() && GetDisplay() == fmt.GetDisplay())
        intersection.SetDisplay(fmt.GetDisplay());
    return intersection;
}

// @0x1426076a0
ParagraphFormat ParagraphFormat::Merge(const ParagraphFormat& fmt) const
{
    ParagraphFormat merged(*this);
    if (fmt.IsAlignmentSet())
        merged.SetAlignment(fmt.GetAlignment());
    if (fmt.IsBulletSet())
        merged.SetBullet(fmt.IsBullet());
    if (fmt.IsBlockIndentSet())
        merged.SetBlockIndent(fmt.GetBlockIndent());
    if (fmt.IsIndentSet())
        merged.SetIndent(fmt.GetIndent());
    if (fmt.IsLeadingSet())
        merged.SetLeading(fmt.GetLeading());
    if (fmt.IsLeftMarginSet())
        merged.SetLeftMargin(fmt.GetLeftMargin());
    if (fmt.IsRightMarginSet())
        merged.SetRightMargin(fmt.GetRightMargin());
    if (fmt.IsTabStopsSet())
        merged.SetTabStops(fmt.GetTabStops());
    if (fmt.IsDisplaySet())
        merged.SetDisplay(fmt.GetDisplay());
    return merged;
}

// @0x142608360
void ParagraphFormat::SetTabStops(unsigned num, ...)
{
    if (num > 0)
    {
        if (!pTabStops || pTabStops[0] != num)
        {
            FreeTabStops();
            AllocTabStops(num);
        }
        va_list vl;
        va_start(vl, num);
        for (unsigned i = 0; i < num; ++i)
        {
            unsigned tabStop = va_arg(vl, unsigned);
            pTabStops[i + 1] = tabStop;
        }
        va_end(vl);
        PresentMask |= PresentMask_TabStops;
    }
    else
        ClearTabStops();
}

// @0x142608460
void ParagraphFormat::SetTabStops(const unsigned* psrcTabStops)
{
    if (psrcTabStops && psrcTabStops[0] > 0)
    {
        CopyTabStops(psrcTabStops);
        PresentMask |= PresentMask_TabStops;
    }
    else
        ClearTabStops();
}

// @0x1426084b0
void ParagraphFormat::SetTabStopsElement(unsigned idx, unsigned val)
{
    if (pTabStops && idx < pTabStops[0])
        pTabStops[idx + 1] = val;
}

// @0x142608610
bool ParagraphFormat::TabStopsEqual(const unsigned* psrcTabStops) const
{
    if (pTabStops == psrcTabStops)
        return true;
    if (pTabStops && psrcTabStops && pTabStops[0] == psrcTabStops[0])
        return memcmp(pTabStops + 1, psrcTabStops + 1, pTabStops[0] * sizeof(unsigned)) == 0;
    return false;
}

// ---------------------------------------------------------------------------------------------------------------
// Allocator: formats are interned by value; a cache past its capacity first drops the formats only it holds.

// @0x142605c70
// MS2-FUNCTIONAL: the exe saves rbx / rbp in the home slots and tail-jumps to the shared epilogue; ours pushes them
ParagraphFormat* Allocator::AllocateParagraphFormat(const ParagraphFormat& srcfmt)
{
    ParagraphFormatPtr* ppfmt = ParagraphFormatStorage.Get(const_cast<ParagraphFormat*>(&srcfmt));
    if (ppfmt)
    {
        ppfmt->pFormat->AddRef();
        return ppfmt->pFormat;
    }
    if (ParagraphFormatStorage.GetSize() >= ParagraphFormatStorageCap)
        FlushParagraphFormatCache(false);
    ParagraphFormat* pfmt = SF_HEAP_NEW(pHeap) ParagraphFormat(srcfmt);
    ParagraphFormatStorage.Set(pfmt);
    return pfmt;
}

// @0x142605e30
// MS2-FUNCTIONAL: the exe saves rbx / rbp in the home slots and tail-jumps to the shared epilogue; ours pushes them
TextFormat* Allocator::AllocateTextFormat(const TextFormat& srcfmt)
{
    // formats carrying an image are never shared
    if (!srcfmt.IsImageDescSet())
    {
        TextFormatPtr* ppfmt = TextFormatStorage.Get(const_cast<TextFormat*>(&srcfmt));
        if (ppfmt)
        {
            ppfmt->pFormat->AddRef();
            return ppfmt->pFormat;
        }
        if (TextFormatStorage.GetSize() >= TextFormatStorageCap)
            FlushTextFormatCache(false);
    }
    TextFormat* pfmt = SF_HEAP_NEW(pHeap) TextFormat(srcfmt, pHeap);
    if ((Flags & Flags_Global) && pfmt->IsFontHandleSet())
        pfmt->ClearFontHandle();
    if (!srcfmt.IsImageDescSet())
        TextFormatStorage.Set(pfmt);
    return pfmt;
}

// @0x142606150
bool Allocator::FlushParagraphFormatCache(bool noAllocationsAllowed)
{
    UPInt oldSize = ParagraphFormatStorage.GetSize();
    for (ParagraphFormatStorageType::Iterator it = ParagraphFormatStorage.Begin();
         it != ParagraphFormatStorage.End(); ++it)
    {
        if (it->pFormat->GetRefCount() == 1)
            it.Remove();
    }
    if (!noAllocationsAllowed)
        ParagraphFormatStorage.SetCapacity(ParagraphFormatStorage.GetSize());
    if (ParagraphFormatStorage.GetSize() >= ParagraphFormatStorageCap)
        ParagraphFormatStorageCap = (unsigned)ParagraphFormatStorage.GetSize() + FormatCacheCapacityDelta;
    else if (ParagraphFormatStorage.GetSize() <= InitialFormatCacheCap)
        ParagraphFormatStorageCap = InitialFormatCacheCap;
    return oldSize != ParagraphFormatStorage.GetSize();
}

// @0x142606410
bool Allocator::FlushTextFormatCache(bool noAllocationsAllowed)
{
    UPInt oldSize = TextFormatStorage.GetSize();
    for (TextFormatStorageType::Iterator it = TextFormatStorage.Begin(); it != TextFormatStorage.End(); ++it)
    {
        if (it->pFormat->GetRefCount() == 1)
            it.Remove();
    }
    if (!noAllocationsAllowed)
        TextFormatStorage.SetCapacity(TextFormatStorage.GetSize());
    if (TextFormatStorage.GetSize() >= TextFormatStorageCap)
        TextFormatStorageCap = (unsigned)TextFormatStorage.GetSize() + FormatCacheCapacityDelta;
    else if (TextFormatStorage.GetSize() <= InitialFormatCacheCap)
        TextFormatStorageCap = InitialFormatCacheCap;
    return oldSize != TextFormatStorage.GetSize();
}

} // namespace Text

}} // namespace Scaleform::Render

// MS2-PIN: ??$Set@PEAVParagraphFormat@Text@Render@Scaleform@@@?$HashSetBase@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@U51234@U?$AllocatorLH@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@$0EO@@4@V?$HashsetCachedEntry@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@@4@@Scaleform@@QEAAXPEAXAEBQEAVParagraphFormat@Text@Render@1@@Z 0x1426045b0
// MS2-PIN: ??$Set@PEAVTextFormat@Text@Render@Scaleform@@@?$HashSetBase@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@U51234@U?$AllocatorLH@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@$0EO@@4@V?$HashsetCachedEntry@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@@4@@Scaleform@@QEAAXPEAXAEBQEAVTextFormat@Text@Render@1@@Z 0x1426047b0
// MS2-PIN: ??$add@PEAVParagraphFormat@Text@Render@Scaleform@@@?$HashSetBase@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@U51234@U?$AllocatorLH@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@$0EO@@4@V?$HashsetCachedEntry@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@@4@@Scaleform@@AEAAXPEAXAEBQEAVParagraphFormat@Text@Render@1@_K@Z 0x142604910
// MS2-PIN: ??$add@PEAVTextFormat@Text@Render@Scaleform@@@?$HashSetBase@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@U51234@U?$AllocatorLH@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@$0EO@@4@V?$HashsetCachedEntry@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@@4@@Scaleform@@AEAAXPEAXAEBQEAVTextFormat@Text@Render@1@_K@Z 0x142604bc0
// MS2-PIN: ??$add@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@@?$HashSetBase@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@U51234@U?$AllocatorLH@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@$0EO@@4@V?$HashsetCachedEntry@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@@4@@Scaleform@@AEAAXPEAXAEBV?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@1@_K@Z 0x142604e20
// MS2-PIN: ??$add@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@@?$HashSetBase@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@U51234@U?$AllocatorLH@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@$0EO@@4@V?$HashsetCachedEntry@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@@4@@Scaleform@@AEAAXPEAXAEBV?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@1@_K@Z 0x142604fa0
// MS2-PIN: ??4?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@QEAAAEAV0123@AEBV0123@@Z 0x142605240
// MS2-PIN: ??4?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@QEAAAEAV0123@AEBV0123@@Z 0x1426052c0
// MS2-PIN: ??RHashFunctor@?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@QEBA_KAEBV1234@@Z 0x142605600
// MS2-PIN: ?Clear@?$HashsetCachedEntry@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@@Scaleform@@QEAAXXZ 0x142605fd0
// MS2-PIN: ?Clear@?$HashsetCachedEntry@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@@Scaleform@@QEAAXXZ 0x142606040
// MS2-PIN: ??0ParagraphFormat@Text@Render@Scaleform@@QEAA@AEBV0123@@Z 0x142605120
// MS2-PIN: ??0TextFormat@Text@Render@Scaleform@@QEAA@AEBV0123@PEAVMemoryHeap@3@@Z 0x142605180
// MS2-PIN: ??1ParagraphFormat@Text@Render@Scaleform@@QEAA@XZ 0x142606690
// MS2-PIN: ?GetFontHandle@TextFormat@Text@Render@Scaleform@@QEBAPEAVFontHandle@234@XZ 0x1426066c0
// MS2-PIN: ?setRawCapacity@?$HashSetBase@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@U51234@U?$AllocatorLH@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@$0EO@@4@V?$HashsetCachedEntry@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@@4@@Scaleform@@AEAAXPEAX_K@Z 0x142608660
// MS2-PIN: ?setRawCapacity@?$HashSetBase@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@U51234@U?$AllocatorLH@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@$0EO@@4@V?$HashsetCachedEntry@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@@4@@Scaleform@@AEAAXPEAX_K@Z 0x142608850
