// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the Win32 GDI font provider
// TU (Render_FontProviderWinAPI): the provider that makes system fonts by name and lists the installed faces, and the
// GDI font that reads glyph metrics, kerning, outlines and bitmaps through GetGlyphOutline.
// MS2-UNIT: sfr_render_04o
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142647290-0x1426499b0 .text$mn
// MS2-RANGE: 0x14264ba40-0x14264cb80 .text$mn

#include "ms2/scaleform/include/render/render_fontprovider.h"
#include "ms2/scaleform/include/render/render_glyphshape.h"
#include "ms2/scaleform/kernel/sf_std.h"
#include "ms2/scaleform/kernel/sf_utf8util.h"
#include <strsafe.h>

namespace Scaleform { namespace Render {

// @0x142647db0 (the font's own destructor is the inline one of render_font.h)

// @0x1426483e0
String Font::GetCharRanges() const
{
    return String("");
}

// The base font has no hinted, texture or temporary glyphs and no character values (out of line in the exe).
// @0x142648410
int Font::GetCharValue(unsigned) const { return -1; }
// @0x142648c30
bool Font::GetGlyphRaster(unsigned, unsigned, GlyphRaster*) { return false; }
// @0x1426490c0
bool Font::GetTemporaryGlyphShape(unsigned, unsigned, GlyphShape*) { return false; }
// @0x1426490d0
const TextureGlyph* Font::GetTextureGlyph(unsigned) const { return 0; }
// @0x1426490e0
void* Font::GetTextureGlyphData() const { return 0; }
// @0x1426490f0
float Font::GetTextureGlyphHeight() const { return 0.0f; }
// @0x142649100
bool Font::HasVectorOrRasterGlyphs() const { return true; }
// @0x1426491b0
bool Font::IsHintedRasterGlyph(unsigned, unsigned) const { return false; }
// @0x142649260
bool Font::IsHintedVectorGlyph(unsigned, unsigned) const { return false; }
// @0x1426499a0
void Font::SetTextureGlyphData(void*) {}

//------------------------------------------------------------------------
// ExternalFontWinAPI

// @0x142647c30
ExternalFontWinAPI::~ExternalFontWinAPI()
{
    if (HintedFont)
        ::DeleteObject(HintedFont);
    if (MasterFont)
        ::DeleteObject(MasterFont);
}

// the face exists when the enumeration reports anything at all
static int CALLBACK EnumFontFamExProc(const LOGFONTW*, const TEXTMETRICW*, DWORD, LPARAM lParam)
{
    *(bool*)lParam = true;
    return 0;
}

// @0x14264c4d0
void ExternalFontWinAPI::loadKerningPairs()
{
    Array<KERNINGPAIR> pairs;
    unsigned           count = ::GetKerningPairsW(pSysData->WinHDC, 0, 0);
    if (count)
    {
        pairs.Resize(count);
        ::GetKerningPairsW(pSysData->WinHDC, count, &pairs[0]);
    }

    KerningPairs.Clear();
    for (unsigned i = 0; i < pairs.GetSize(); ++i)
    {
        KerningPairType pair;
        pair.Char0 = pairs[i].wFirst;
        pair.Char1 = pairs[i].wSecond;
        KerningPairs.Add(pair, float(pairs[i].iKernAmount) * Scale1024);
    }
}

// @0x1426475b0
ExternalFontWinAPI::ExternalFontWinAPI(FontProviderWinAPI* pprovider, FontSysDataWinAPI* psysData, const char* name,
                                       unsigned fontFlags, Lock* fontLock)
    : Font(fontFlags), pFontProvider(pprovider), pSysData(psysData), MasterFont(0), HintedFont(0),
      LastHintedFontSize(0), Scale1024(1024.0f / GGO_FontHeight), pFontLock(fontLock)
{
    Name.Resize(SFstrlen(name) + 1);
    SFstrcpy(&Name[0], SFstrlen(name) + 1, name);

    NameW.Resize(UTF8Util::GetLength(name) + 1);
    UTF8Util::DecodeString(&NameW[0], name);

    // GDI substitutes a default face for an unknown name; only the Flash device font names may go that way
    LOGFONTW lf;
    ::StringCchCopyW(lf.lfFaceName, LF_FACESIZE, &NameW[0]);
    lf.lfCharSet    = DEFAULT_CHARSET;
    bool faceExists = false;
    ::EnumFontFamiliesExW(pSysData->WinHDC, &lf, (FONTENUMPROCW)EnumFontFamExProc, (LPARAM)&faceExists, 0);
    if (!faceExists && strcmp(name, "_sans") != 0 && strcmp(name, "_typewriter") != 0 &&
        strcmp(name, "_serif") != 0)
        return;

    MasterFont = ::CreateFontW(-GGO_FontHeight, 0, 0, 0, IsBold() ? FW_BOLD : FW_NORMAL, IsItalic(), 0, 0,
                               DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
                               DEFAULT_PITCH, &NameW[0]);
    if (MasterFont)
    {
        HDC        dc      = pSysData->WinHDC;
        HGDIOBJ    oldFont = ::SelectObject(dc, MasterFont);
        TEXTMETRICW tm;
        if (::GetTextMetricsW(pSysData->WinHDC, &tm))
        {
            Leading = float(tm.tmExternalLeading) * Scale1024;
            Ascent  = float(tm.tmAscent) * Scale1024;
            Descent = float(tm.tmDescent) * Scale1024;
            loadKerningPairs();
        }
        ::SelectObject(dc, oldFont);
    }
}

// @0x14264bb10
bool ExternalFontWinAPI::decomposeGlyphOutline(const UByte* data, unsigned size, GlyphShape* shape,
                                               unsigned hintedSize)
{
    const UByte* cur    = data;
    const UByte* end    = data + size;
    bool         hinted = hintedSize != 0;
    ShapePosInfo pos(0);

    shape->Clear();
    while (cur < end)
    {
        const TTPOLYGONHEADER* header  = (const TTPOLYGONHEADER*)cur;
        const UByte*           polyEnd = cur + header->cb;
        const UByte*           poly    = cur + sizeof(TTPOLYGONHEADER);

        if (hinted)
            shape->StartPath(&pos, Shape_NewPath, 1, 0, 0, FxToTwips(header->pfxStart.x),
                             -FxToTwips(header->pfxStart.y));
        else
            shape->StartPath(&pos, Shape_NewPath, 1, 0, 0, FxToS1024(header->pfxStart.x),
                             -FxToS1024(header->pfxStart.y));

        while (poly < polyEnd)
        {
            const TTPOLYCURVE* curve = (const TTPOLYCURVE*)poly;

            if (curve->wType == TT_PRIM_LINE)
            {
                for (int i = 0; i < curve->cpfx; i++)
                {
                    if (hinted)
                        shape->LineTo(&pos, FxToTwips(curve->apfx[i].x), -FxToTwips(curve->apfx[i].y));
                    else
                        shape->LineTo(&pos, FxToS1024(curve->apfx[i].x), -FxToS1024(curve->apfx[i].y));
                }
            }

            if (curve->wType == TT_PRIM_QSPLINE)
            {
                // every point is a control point; the anchors between two of them are their midpoints
                for (int i = 0; i < curve->cpfx - 1; i++)
                {
                    POINTFX ctrl   = curve->apfx[i];
                    POINTFX anchor = curve->apfx[i + 1];
                    if (i < curve->cpfx - 2)
                    {
                        *(int*)&anchor.x = (*(int*)&ctrl.x + *(int*)&anchor.x) / 2;
                        *(int*)&anchor.y = (*(int*)&ctrl.y + *(int*)&anchor.y) / 2;
                    }
                    if (hinted)
                        shape->QuadTo(&pos, FxToTwips(ctrl.x), -FxToTwips(ctrl.y), FxToTwips(anchor.x),
                                      -FxToTwips(anchor.y));
                    else
                        shape->QuadTo(&pos, FxToS1024(ctrl.x), -FxToS1024(ctrl.y), FxToS1024(anchor.x),
                                      -FxToS1024(anchor.y));
                }
            }
            poly += sizeof(WORD) * 2 + sizeof(POINTFX) * curve->cpfx;
        }
        cur += header->cb;
        shape->ClosePath(&pos);
        shape->EndPath();
    }

    if (shape->IsEmpty())
        return false;
    shape->EndShape();
    shape->SetHintedSize(hinted ? hintedSize * 20 : 0);
    return true;
}

// @0x14264ba40
void ExternalFontWinAPI::decomposeGlyphBitmap(const UByte* data, int width, int height, int originX, int originY,
                                              GlyphRaster* raster)
{
    raster->OriginX = -originX;
    raster->OriginY = originY;
    raster->Width   = width;
    raster->Height  = height;
    raster->Raster.Resize(width * height);

    // GGO_BITMAP rows are 1 bit per pixel, high bit first, padded to 4 bytes
    UByte* dst   = &raster->Raster[0];
    int    pitch = ((width + 31) >> 3) & ~3;
    for (int y = 0; y < height; ++y)
    {
        const UByte* src  = data;
        UByte        mask = 0x80;
        for (int x = 0; x < width; ++x)
        {
            *dst++ = (*src & mask) ? 255 : 0;
            mask >>= 1;
            if (mask == 0)
            {
                ++src;
                mask = 0x80;
            }
        }
        data += pitch;
    }
}

// @0x142648570
int ExternalFontWinAPI::GetGlyphIndex(UInt16 code)
{
    if (!MasterFont)
        return -1;

    Lock::Locker lock(pFontLock);
    const unsigned* pindex = CodeTable.Get(code);
    if (pindex)
        return *pindex;

    HDC     dc      = pSysData->WinHDC;
    HGDIOBJ oldFont = ::SelectObject(dc, MasterFont);

    GLYPHMETRICS gm;
    MAT2         mat = { { 0, 1 }, { 0, 0 }, { 0, 0 }, { 0, 1 } };
    int          index;
    if (::GetGlyphOutlineW(pSysData->WinHDC, code, GGO_METRICS, &gm, 0, 0, &mat) == GDI_ERROR)
        index = -1;
    else
    {
        GlyphType glyph;
        glyph.Code      = code;
        glyph.Advance   = float(gm.gmCellIncX) * Scale1024;
        glyph.Bounds.x1 = float(gm.gmptGlyphOrigin.x) * Scale1024;
        glyph.Bounds.y1 = -(float(gm.gmptGlyphOrigin.y) * Scale1024);
        glyph.Bounds.x2 = glyph.Bounds.x1 + float(gm.gmBlackBoxX) * Scale1024;
        glyph.Bounds.y2 = glyph.Bounds.y1 + float(gm.gmBlackBoxY) * Scale1024;
        Glyphs.PushBack(glyph);
        CodeTable.Add(code, unsigned(Glyphs.GetSize() - 1));
        index = int(Glyphs.GetSize() - 1);
    }
    ::SelectObject(dc, oldFont);
    return index;
}

// @0x1426491c0
bool ExternalFontWinAPI::IsHintedVectorGlyph(unsigned glyphIndex, unsigned hintedSize) const
{
    if ((glyphIndex & 0xFFFF) == 0xFFFF || Hinting.VectorRange == DontHint ||
        hintedSize > Hinting.MaxVectorHintedSize)
        return false;
    if (Hinting.VectorRange == HintAll)
        return true;

    Lock::Locker lock(pFontLock);
    return IsCJK(UInt16(Glyphs[glyphIndex].Code));
}

// @0x142649110
bool ExternalFontWinAPI::IsHintedRasterGlyph(unsigned glyphIndex, unsigned hintedSize) const
{
    if ((glyphIndex & 0xFFFF) == 0xFFFF || Hinting.RasterRange == DontHint ||
        hintedSize > Hinting.MaxRasterHintedSize)
        return false;
    if (Hinting.RasterRange == HintAll)
        return true;

    Lock::Locker lock(pFontLock);
    return IsCJK(UInt16(Glyphs[glyphIndex].Code));
}

// MS2-FUNCTIONAL: register allocation only (exe keeps the shape pointer in r12, ours in r13; 6 bytes longer)
// @0x142648de0
bool ExternalFontWinAPI::GetTemporaryGlyphShape(unsigned glyphIndex, unsigned hintedSize, GlyphShape* shape)
{
    if ((glyphIndex & 0xFFFF) == 0xFFFF)
        return false;
    if (!IsHintedVectorGlyph(glyphIndex, hintedSize))
        hintedSize = 0;

    Lock::Locker     lock(pFontLock);
    HFONT            font  = MasterFont;
    const GlyphType& glyph = Glyphs[glyphIndex];
    if (hintedSize)
    {
        if (hintedSize != LastHintedFontSize)
        {
            if (HintedFont)
                ::DeleteObject(HintedFont);
            HintedFont = ::CreateFontW(-int(hintedSize), 0, 0, 0, IsBold() ? FW_BOLD : FW_NORMAL, IsItalic(), 0, 0,
                                       DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
                                       DEFAULT_PITCH, &NameW[0]);
            LastHintedFontSize = hintedSize;
        }
        font = HintedFont;
    }

    HDC     dc      = pSysData->WinHDC;
    HGDIOBJ oldFont = ::SelectObject(dc, font);
    if (pSysData->GlyphBuffer.GetSize() == 0)
        pSysData->GlyphBuffer.Resize(FontSysDataWinAPI::BufSizeInc);

    // a too small buffer is grown to what GDI asks for and the outline read again
    GLYPHMETRICS gm;
    MAT2         mat  = { { 0, 1 }, { 0, 0 }, { 0, 0 }, { 0, 1 } };
    int          size = ::GetGlyphOutlineW(pSysData->WinHDC, glyph.Code, GGO_NATIVE, &gm,
                                           (DWORD)pSysData->GlyphBuffer.GetSize(), &pSysData->GlyphBuffer[0], &mat);
    if (size == GDI_ERROR || size > (int)pSysData->GlyphBuffer.GetSize())
    {
        size = ::GetGlyphOutlineW(pSysData->WinHDC, glyph.Code, GGO_NATIVE, &gm, 0, 0, &mat);
        if (size != GDI_ERROR)
        {
            pSysData->GlyphBuffer.Resize(size + FontSysDataWinAPI::BufSizeInc);
            size = ::GetGlyphOutlineW(pSysData->WinHDC, glyph.Code, GGO_NATIVE, &gm,
                                      (DWORD)pSysData->GlyphBuffer.GetSize(), &pSysData->GlyphBuffer[0], &mat);
        }
    }
    bool ret = false;
    if (size != GDI_ERROR && size <= (int)pSysData->GlyphBuffer.GetSize() &&
        (size == 0 || decomposeGlyphOutline(&pSysData->GlyphBuffer[0], size, shape, hintedSize)))
        ret = true;

    ::SelectObject(dc, oldFont);
    return ret;
}

// @0x1426488b0
bool ExternalFontWinAPI::GetGlyphRaster(unsigned glyphIndex, unsigned hintedSize, GlyphRaster* raster)
{
    if ((glyphIndex & 0xFFFF) == 0xFFFF || !IsHintedRasterGlyph(glyphIndex, hintedSize))
        return false;

    Lock::Locker     lock(pFontLock);
    const GlyphType& glyph = Glyphs[glyphIndex];
    if (hintedSize != LastHintedFontSize)
    {
        if (HintedFont)
            ::DeleteObject(HintedFont);
        HintedFont = ::CreateFontW(-int(hintedSize), 0, 0, 0, IsBold() ? FW_BOLD : FW_NORMAL, IsItalic(), 0, 0,
                                   DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
                                   DEFAULT_PITCH, &NameW[0]);
        LastHintedFontSize = hintedSize;
    }

    HDC     dc      = pSysData->WinHDC;
    HGDIOBJ oldFont = ::SelectObject(dc, HintedFont);
    if (pSysData->GlyphBuffer.GetSize() == 0)
        pSysData->GlyphBuffer.Resize(FontSysDataWinAPI::BufSizeInc);

    GLYPHMETRICS gm;
    MAT2         mat  = { { 0, 1 }, { 0, 0 }, { 0, 0 }, { 0, 1 } };
    bool         ok   = true;
    int          size = ::GetGlyphOutlineW(pSysData->WinHDC, glyph.Code, GGO_BITMAP, &gm,
                                           (DWORD)pSysData->GlyphBuffer.GetSize(), &pSysData->GlyphBuffer[0], &mat);
    if (size == GDI_ERROR || size > (int)pSysData->GlyphBuffer.GetSize())
    {
        size = ::GetGlyphOutlineW(pSysData->WinHDC, glyph.Code, GGO_BITMAP, &gm, 0, 0, &mat);
        if (size == GDI_ERROR)
            ok = false;
        else
        {
            pSysData->GlyphBuffer.Resize(size + FontSysDataWinAPI::BufSizeInc);
            size = ::GetGlyphOutlineW(pSysData->WinHDC, glyph.Code, GGO_BITMAP, &gm,
                                      (DWORD)pSysData->GlyphBuffer.GetSize(), &pSysData->GlyphBuffer[0], &mat);
            if (size == GDI_ERROR || size > (int)pSysData->GlyphBuffer.GetSize())
                ok = false;
        }
    }
    if (ok)
    {
        if (size)
            decomposeGlyphBitmap(&pSysData->GlyphBuffer[0], gm.gmBlackBoxX, gm.gmBlackBoxY, gm.gmptGlyphOrigin.x,
                                 gm.gmptGlyphOrigin.y, raster);
        else
        {
            // a blank glyph (space): one empty pixel
            raster->Width  = 1;
            raster->Height = 1;
            raster->Raster.Resize(1);
            raster->Raster[0] = 0;
        }
    }

    ::SelectObject(dc, oldFont);
    return ok;
}

// @0x142648360
float ExternalFontWinAPI::GetAdvance(unsigned glyphIndex) const
{
    if (UInt16(glyphIndex) == 0xFFFFu)
        return GetNominalGlyphWidth();

    Lock::Locker lock(pFontLock);
    return Glyphs[glyphIndex].Advance;
}

float ExternalFontWinAPI::GetKerningAdjustment(unsigned lastCode, unsigned thisCode) const
{
    KerningPairType pair;
    pair.Char0          = UInt16(lastCode);
    pair.Char1          = UInt16(thisCode);
    const float* adjust = KerningPairs.Get(pair);
    return adjust ? *adjust : 0;
}

// @0x142648c50
float ExternalFontWinAPI::GetGlyphWidth(unsigned glyphIndex) const
{
    if (UInt16(glyphIndex) == 0xFFFF)
        return GetNominalGlyphWidth();

    Lock::Locker lock(pFontLock);
    return Glyphs[glyphIndex].Bounds.Width();
}

// @0x1426484f0
float ExternalFontWinAPI::GetGlyphHeight(unsigned glyphIndex) const
{
    if (UInt16(glyphIndex) == 0xFFFF)
        return GetNominalGlyphHeight();

    Lock::Locker lock(pFontLock);
    return Glyphs[glyphIndex].Bounds.Height();
}

// @0x142648420
RectF& ExternalFontWinAPI::GetGlyphBounds(unsigned glyphIndex, RectF* prect) const
{
    if (UInt16(glyphIndex) == 0xFFFF)
    {
        prect->SetRect(0, 0, GetNominalGlyphWidth(), GetNominalGlyphHeight());
        return *prect;
    }

    Lock::Locker lock(pFontLock);
    *prect = Glyphs[glyphIndex].Bounds;
    return *prect;
}

const char* ExternalFontWinAPI::GetName() const
{
    return &Name[0];
}

//------------------------------------------------------------------------
// FontProviderWinAPI

// @0x142647ae0
FontProviderWinAPI::FontProviderWinAPI(HDC dc) : SysData(dc)
{
    // the default: CJK glyphs raster hinted, no vector hinting, both up to 24 pixels
    Font::NativeHintingType nh;
    nh.RasterRange         = Font::HintCJK;
    nh.VectorRange         = Font::DontHint;
    nh.MaxRasterHintedSize = 24;
    nh.MaxVectorHintedSize = 24;
    NativeHinting.PushBack(nh);
}

// @0x142647df0
FontProviderWinAPI::~FontProviderWinAPI()
{
}

// @0x14264c440
Font::NativeHintingType* FontProviderWinAPI::findNativeHinting(const char* name)
{
    for (unsigned i = 0; i < NativeHinting.GetSize(); ++i)
    {
        if (String::CompareNoCase(NativeHinting[i].Typeface.ToCStr(), name) == 0)
            return &NativeHinting[i];
    }
    return 0;
}

// @0x142649880
// MS2-FUNCTIONAL: frame: the exe shrink-wraps the rdi save into the not-found path and pins the args in rsi/rbp/r14/r15; same body
void FontProviderWinAPI::SetHinting(const char* name, Font::NativeHintingRange vectorRange,
                                    Font::NativeHintingRange rasterRange, unsigned maxVectorHintedSize,
                                    unsigned maxRasterHintedSize)
{
    Font::NativeHintingType* nh = findNativeHinting(name);
    if (!nh)
    {
        // a new face starts from the default entry
        Font::NativeHintingType newNh = NativeHinting[0];
        newNh.Typeface                = name;
        NativeHinting.PushBack(newNh);
        nh = &NativeHinting.Back();
    }
    nh->MaxVectorHintedSize = maxVectorHintedSize;
    nh->MaxRasterHintedSize = maxRasterHintedSize;
    nh->VectorRange         = vectorRange;
    nh->RasterRange         = rasterRange;
}

// @0x142649970
void FontProviderWinAPI::SetHintingAllFonts(Font::NativeHintingRange vectorRange,
                                            Font::NativeHintingRange rasterRange, unsigned maxVectorHintedSize,
                                            unsigned maxRasterHintedSize)
{
    NativeHinting[0].VectorRange         = vectorRange;
    NativeHinting[0].RasterRange         = rasterRange;
    NativeHinting[0].MaxVectorHintedSize = maxVectorHintedSize;
    NativeHinting[0].MaxRasterHintedSize = maxRasterHintedSize;
}

// @0x142648250
Font* FontProviderWinAPI::CreateFont(const char* name, unsigned fontFlags)
{
    fontFlags &= Font::FF_CreateFont_Mask;
    fontFlags |= Font::FF_DeviceFont | Font::FF_NativeHinting;

    ExternalFontWinAPI* font = SF_HEAP_AUTO_NEW(this) ExternalFontWinAPI(this, &SysData, name, fontFlags, &FontLock);
    if (font && !font->IsValid())
    {
        font->Release();
        return 0;
    }

    Font::NativeHintingType* nh = findNativeHinting(name);
    font->SetHinting(nh ? *nh : NativeHinting[0]);
    return font;
}

// @0x1426492d0
int CALLBACK LoadFontNamesProc(ENUMLOGFONTEXW* lpelfe, NEWTEXTMETRICEXW*, DWORD, LPARAM lParam)
{
    StringHash<String>* fontnames = (StringHash<String>*)lParam;
    String              fontname(lpelfe->elfFullName);
    fontnames->Set(fontname, fontname);
    return 1;
}

// @0x142649270
void FontProviderWinAPI::LoadFontNames(StringHash<String>& fontnames)
{
    LOGFONTW lf;
    lf.lfCharSet        = DEFAULT_CHARSET;
    lf.lfFaceName[0]    = 0;
    lf.lfPitchAndFamily = 0;
    ::EnumFontFamiliesExW(SysData.WinHDC, &lf, (FONTENUMPROCW)LoadFontNamesProc, (LPARAM)&fontnames, 0);
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7?$RefCountBase@VFontProvider@Render@Scaleform@@$0EP@@Scaleform@@6B@ 0x1431901e8
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EP@@Scaleform@@6B@ 0x1431901f0
// MS2-PIN: ??_7Font@Render@Scaleform@@6B@ 0x1431901f8
// MS2-PIN: ??_7?$RefCountBase@VFont@Render@Scaleform@@$0EP@@Scaleform@@6B@ 0x1431902b0
// MS2-PIN: ??_7FontProvider@Render@Scaleform@@6B@ 0x1431902b8
// MS2-PIN: ??_7ExternalFontWinAPI@Render@Scaleform@@6B@ 0x1431902d0
// MS2-PIN: ??_7FontProviderWinAPI@Render@Scaleform@@6B@ 0x143190388
// MS2-PIN: ?Resize@?$ArrayData@EU?$AllocatorGH@E$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAX_K@Z 0x1426497d0
