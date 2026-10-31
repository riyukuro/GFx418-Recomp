// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_FontGlyphPacker. Prerenders
// the glyphs of movie fonts into A8 textures when a movie is bound with FontPackParams: the glyph bounds are scaled
// to the nominal size and padded, glyphs of one font with the same geometry share a rect (a hash on the path data),
// the rects are packed into pages of the configured texture size (one set of pages per font with SeparateTextures)
// and every page is rasterized with the scanline rasterizer and handed to the fonts' texture glyph tables.
// MS2-UNIT: sfr_gfx_08m
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426607d0-0x142663400 .text$mn

#define MS2_SF_HASH_CLEAR_NOINLINE           // HashSet Clear out of line, as the exe's setRawCapacity calls it
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_log.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_resource.h"
#include "../include/gfx/gfx_fontresource.h"
#include "../include/gfx/gfx_shapeswf.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_fontglyphpacker.h"
#include "../include/render/render_boundbox.h"
#include "../include/render/render_tessdefs.h"
#include "../include/render/render_toleranceparams.h"
#include "../include/render/render_image.h"
#include "../kernel/sf_log.h"
#include <math.h>
#include <string.h>

namespace Scaleform { namespace GFx {

using namespace Render;

const float FontPackParams::GlyphBoundBox = 1536.0f;

// djb2 over the bytes of buf, last byte first
static inline UInt32 hashBytesBackward(const void* buf, unsigned size, UInt32 hash)
{
    const UByte* bytes = (const UByte*)buf;
    while (size)
    {
        size--;
        hash = (hash * 33) ^ (unsigned)bytes[size];
    }
    return hash;
}

// @0x142661610
bool IsEqualGeometry(const ShapeDataInterface& a, const ShapeDataInterface& b)
{
    bool emptyA = a.IsEmpty();
    bool emptyB = b.IsEmpty();
    if (emptyA || emptyB)
        return emptyA == emptyB;

    ShapePosInfo posA(a.GetStartingPos());
    ShapePosInfo posB(b.GetStartingPos());
    float        coordA[Edge_MaxCoord];
    float        coordB[Edge_MaxCoord];
    unsigned     stylesA[3];
    unsigned     stylesB[3];
    bool         firstPath = true;

    for (;;)
    {
        ShapePathType pathA = a.ReadPathInfo(&posA, coordA, stylesA);
        ShapePathType pathB = b.ReadPathInfo(&posB, coordB, stylesB);
        if (pathA != pathB)
            return false;
        if (pathA == Shape_EndShape)
            return true;
        if (pathA == Shape_NewLayer || firstPath)
            firstPath = false;
        if (memcmp(stylesA, stylesB, sizeof(stylesA)) != 0 || memcmp(coordA, coordB, 2 * sizeof(float)) != 0)
            return false;

        for (;;)
        {
            PathEdgeType edgeA = a.ReadEdge(&posA, coordA);
            PathEdgeType edgeB = b.ReadEdge(&posB, coordB);
            if (edgeA != edgeB)
                return false;
            if (edgeA == Edge_EndPath)
                break;
            if (memcmp(coordA, coordB, ((edgeA == Edge_QuadTo) ? 4 : 2) * sizeof(float)) != 0)
                return false;
        }
    }
}

// @0x142661000
UInt32 ComputeGeometryHash(const ShapeDataInterface& shape)
{
    if (shape.IsEmpty())
        return 0;

    UInt32        hash = 5381;
    ShapePosInfo  pos(shape.GetStartingPos());
    float         coord[Edge_MaxCoord];
    unsigned      styles[3];
    bool          firstPath = true;
    ShapePathType pathType;

    while ((pathType = shape.ReadPathInfo(&pos, coord, styles)) != Shape_EndShape)
    {
        if (!firstPath && pathType == Shape_NewLayer)
            break;
        firstPath = false;

        hash = hashBytesBackward(styles, sizeof(styles), hash);
        if (styles[0] == styles[1])
        {
            shape.SkipPathData(&pos);
            continue;
        }
        hash = hashBytesBackward(coord, 2 * sizeof(float), hash);
        PathEdgeType edge;
        while ((edge = shape.ReadEdge(&pos, coord)) != Edge_EndPath)
            hash = hashBytesBackward(coord, ((edge == Edge_LineTo) ? 2 : 4) * sizeof(float), hash);
    }
    return hash;
}

// @0x1426609a0
FontGlyphPacker::FontGlyphPacker(FontPackParams* params, ImageCreator* pimageCreator, Log* plog,
                                 ResourceId* ptextureIdGen, MemoryHeap* fontHeap, bool threadedLoading)
    : pFontPackParams(params), pTextureIdGen(ptextureIdGen), pImageCreator(pimageCreator), pLog(plog),
      pFontHeap(fontHeap), Ras(Memory::GetGlobalHeap()), ThreadedLoading(threadedLoading)
{
    if (pFontPackParams)
        pFontPackParams->GetTextureConfig(&PackTextureConfig);
    Packer.SetWidth(PackTextureConfig.TextureWidth);
    Packer.SetHeight(PackTextureConfig.TextureHeight);
}

// @0x142660b10
FontGlyphPacker::~FontGlyphPacker()
{
}

// @0x1426619f0
void FontGlyphPacker::generateGlyphInfo(Array<GlyphInfo>* glyphs, FontResource* font)
{
    Font* pfont = font->GetFont();
    if (pfont->GetGlyphShapeCount() == 0)
        return;

    Ptr<TextureGlyphData> ptgd = *SF_HEAP_NEW(pFontHeap) TextureGlyphData(pfont->GetGlyphShapeCount());
    ptgd->SetTextureConfig(PackTextureConfig);
    pfont->SetTextureGlyphData(ptgd.GetPtr());

    float    glyphToPix = PackTextureConfig.NominalSize / FontPackParams::GlyphBoundBox;
    unsigned n          = pfont->GetGlyphShapeCount();
    for (unsigned i = 0; i < n; i++)
    {
        if (ptgd->GetTextureGlyph(i).pImage)
            continue;
        const ShapeDataInterface* shape = pfont->GetPermanentGlyphShape(i);
        if (!shape)
            continue;

        RectF bounds = ComputeBoundsFill(*shape, Matrix2F(), Bound_FillEdges);
        if (!(bounds.Width() > 0 && bounds.Height() > 0))
            continue;

        GlyphInfo gi;
        float     pad = (float)PackTextureConfig.PadPixels;
        gi.Bounds.x1  = bounds.x1 * glyphToPix - pad;
        gi.Bounds.y1  = bounds.y1 * glyphToPix - pad;
        gi.Bounds.x2  = bounds.x2 * glyphToPix + pad;
        gi.Bounds.y2  = bounds.y2 * glyphToPix + pad;
        gi.Origin.x   = 0;
        gi.Origin.y   = 0;
        if (!(gi.Bounds.Width() > 0 && gi.Bounds.Height() > 0))
            continue;

        gi.pFont      = font;
        gi.GlyphIndex = i;
        gi.GlyphReuse = ~0u;
        gi.TextureIdx = ~0u;

        GlyphGeometryKey key(font, shape, ComputeGeometryHash(*shape));
        const unsigned*  reuse = GlyphGeometryHash.Get(key);
        if (reuse)
            gi.GlyphReuse = *reuse;
        else
            GlyphGeometryHash.Add(key, (unsigned)glyphs->GetSize());
        glyphs->PushBack(gi);
    }
}

// @0x1426629c0
unsigned FontGlyphPacker::packGlyphRects(Array<GlyphInfo>* glyphs, unsigned start, unsigned end, unsigned texIdx)
{
    Packer.Clear();
    for (unsigned i = start; i < end; i++)
    {
        const GlyphInfo& gi = (*glyphs)[i];
        if (gi.GlyphReuse != ~0u)
            continue;
        unsigned w = unsigned(ceilf(gi.Bounds.x2) - floorf(gi.Bounds.x1));
        unsigned h = unsigned(ceilf(gi.Bounds.y2) - floorf(gi.Bounds.y1));
        Packer.AddRect(w, h, i);
    }
    Packer.Pack();

    for (unsigned p = 0; p < Packer.GetNumPacks(); p++)
    {
        const RectPacker::PackType& pack = Packer.GetPack(p);
        for (unsigned r = 0; r < pack.NumRects; r++)
        {
            const RectPacker::RectType& rect = Packer.GetRect(pack, r);
            GlyphInfo&                  gi   = (*glyphs)[rect.Id];
            unsigned w    = unsigned(int(ceilf(gi.Bounds.x2) - floorf(gi.Bounds.x1)));
            unsigned h    = unsigned(int(ceilf(gi.Bounds.y2) - floorf(gi.Bounds.y1)));
            gi.Origin.x   = float(rect.x) - gi.Bounds.x1;
            gi.Origin.y   = float(rect.y) - gi.Bounds.y1;
            gi.Bounds.x1  = float(rect.x);
            gi.Bounds.y1  = float(rect.y);
            gi.Bounds.x2  = float(rect.x + w);
            gi.Bounds.y2  = float(rect.y + h);
            gi.TextureIdx = texIdx + p;
        }
    }
    return texIdx + (unsigned)Packer.GetNumPacks();
}

// @0x1426625f0
unsigned FontGlyphPacker::packGlyphRects(Array<GlyphInfo>* glyphs)
{
    unsigned numTextures = 0;
    unsigned start       = 0;
    if (pFontPackParams->GetUseSeparateTextures())
    {
        // a run of glyphs of one font at a time
        for (unsigned i = 1; i < glyphs->GetSize(); i++)
        {
            if ((*glyphs)[i - 1].pFont != (*glyphs)[i].pFont)
            {
                numTextures = packGlyphRects(glyphs, start, i, numTextures);
                start       = i;
            }
        }
    }
    return packGlyphRects(glyphs, start, (unsigned)glyphs->GetSize(), numTextures);
}

// @0x142662d00
void FontGlyphPacker::rasterizeGlyph(RawImage* texImage, GlyphInfo* gi)
{
    const ShapeDataInterface* shape = gi->pFont->GetFont()->GetPermanentGlyphShape(gi->GlyphIndex);
    if (!shape || shape->IsEmpty())
        return;

    ToleranceParams tolerance;
    float           scale = PackTextureConfig.NominalSize / FontPackParams::GlyphBoundBox;
    ShapePosInfo    pos(shape->GetStartingPos());
    float           coord[Edge_MaxCoord];
    unsigned        styles[3];
    bool            firstPath = true;
    ShapePathType   pathType;

    Ras.Clear();
    while ((pathType = shape->ReadPathInfo(&pos, coord, styles)) != Shape_EndShape)
    {
        if (!firstPath && pathType == Shape_NewLayer)
            break;
        firstPath = false;

        if (styles[0] == styles[1])
        {
            shape->SkipPathData(&pos);
            continue;
        }
        coord[0] *= scale;
        coord[1] *= scale;
        Ras.MoveTo(coord[0], coord[1]);
        PathEdgeType edge;
        while ((edge = shape->ReadEdge(&pos, coord)) != Edge_EndPath)
        {
            if (edge == Edge_LineTo)
            {
                coord[0] *= scale;
                coord[1] *= scale;
                Ras.LineTo(coord[0], coord[1]);
            }
            else
            {
                coord[0] *= scale;
                coord[1] *= scale;
                coord[2] *= scale;
                coord[3] *= scale;
                TessellateQuadCurve(&Ras, tolerance, coord[0], coord[1], coord[2], coord[3]);
            }
        }
        Ras.ClosePath();
    }

    if (Ras.SortCells())
    {
        ImageData data;
        texImage->GetImageData(&data);
        unsigned h = Ras.GetMaxY() - Ras.GetMinY() + 1;
        int      x = int(floorf(gi->Bounds.x1)) + PackTextureConfig.PadPixels;
        int      y = int(floorf(gi->Bounds.y1)) + PackTextureConfig.PadPixels;
        for (unsigned i = 0; i < h; i++)
            Ras.SweepScanline(i, data.GetScanline(y + i) + x);
    }
    Ras.Clear();
}

// @0x142662010
void FontGlyphPacker::generateTextures(Array<GlyphInfo>* glyphs, unsigned numTextures)
{
    for (unsigned t = 0; t < numTextures; t++)
    {
        // the smallest power of two that holds the page, unless that is more than half the configured size
        unsigned maxWidth  = 0;
        unsigned maxHeight = 0;
        for (unsigned j = 0; j < glyphs->GetSize(); j++)
        {
            const GlyphInfo& gi = (*glyphs)[j];
            if (gi.TextureIdx != t)
                continue;
            if (int(ceilf(gi.Bounds.x2)) > (int)maxWidth)
                maxWidth = int(ceilf(gi.Bounds.x2));
            if (int(ceilf(gi.Bounds.y2)) > (int)maxHeight)
                maxHeight = int(ceilf(gi.Bounds.y2));
        }
        unsigned texWidth  = PackTextureConfig.TextureWidth;
        unsigned texHeight = PackTextureConfig.TextureHeight;
        if (maxWidth <= (unsigned)PackTextureConfig.TextureWidth / 2)
        {
            texWidth = 1;
            while (texWidth < maxWidth)
                texWidth <<= 1;
        }
        if (maxHeight <= (unsigned)PackTextureConfig.TextureHeight / 2)
        {
            texHeight = 1;
            while (texHeight < maxHeight)
                texHeight <<= 1;
        }

        Ptr<RawImage> texImage =
            *RawImage::Create(Image_A8, 1, ImageSize(texWidth, texHeight), ImageUse_GenMipmaps, pFontHeap);
        ImageData data;
        texImage->GetImageData(&data);
        memset(data.GetPlaneRef().pData, 0, texWidth * texHeight);
        for (unsigned j = 0; j < glyphs->GetSize(); j++)
        {
            GlyphInfo& gi = (*glyphs)[j];
            if (gi.TextureIdx == t)
                rasterizeGlyph(texImage, &gi);
        }

        ImageSize  size      = texImage->GetSize();
        float      pixToU    = 1.0f / size.Width;
        float      pixToV    = 1.0f / size.Height;
        ResourceId textureId = pTextureIdGen->GenerateNextId();

        Ptr<ImageResource> pimageRes = *SF_HEAP_NEW(pFontHeap) ImageResource(texImage.GetPtr(), Resource::Use_FontTexture);

        for (unsigned j = 0; j < glyphs->GetSize(); j++)
        {
            GlyphInfo gi = (*glyphs)[j];
            if (gi.GlyphReuse != ~0u)
            {
                // a reused glyph takes the place of the one it repeats
                const GlyphInfo& orig = (*glyphs)[gi.GlyphReuse];
                gi.TextureIdx = orig.TextureIdx;
                gi.Bounds     = orig.Bounds;
                gi.Origin     = orig.Origin;
            }
            if (gi.TextureIdx != t)
                continue;

            TextureGlyph tg;
            tg.pImage      = texImage.GetPtr();
            tg.UvBounds.x1 = gi.Bounds.x1 * pixToU;
            tg.UvBounds.y1 = gi.Bounds.y1 * pixToV;
            tg.UvBounds.x2 = gi.Bounds.x2 * pixToU;
            tg.UvBounds.y2 = gi.Bounds.y2 * pixToV;
            tg.UvOrigin.x  = gi.Origin.x * pixToU;
            tg.UvOrigin.y  = gi.Origin.y * pixToV;
            tg.BindIndex   = ~0u;

            TextureGlyphData* ptgd = (TextureGlyphData*)gi.pFont->GetFont()->GetTextureGlyphData();
            ptgd->AddTextureGlyph(gi.GlyphIndex, tg);
            ptgd->AddTexture(textureId, pimageRes);
        }
    }
}

// @0x1426613f0
__declspec(noinline) void FontGlyphPacker::GenerateFontBitmaps(const Array<FontResource*>& fonts)
{
    int      limit       = pFontPackParams->GetGlyphCountLimit();
    unsigned totalGlyphs = 0;
    for (unsigned i = 0; i < fonts.GetSize(); i++)
    {
        Font* pfont = fonts[i]->GetFont();
        if (pfont->GetTextureGlyphData())
            continue;
        if (limit && (int)pfont->GetGlyphShapeCount() > limit)
            continue;
        totalGlyphs += pfont->GetGlyphShapeCount();
    }

    Array<GlyphInfo> glyphs;
    glyphs.Reserve(totalGlyphs);
    GlyphGeometryHash.Clear();
    for (unsigned i = 0; i < fonts.GetSize(); i++)
    {
        Font* pfont = fonts[i]->GetFont();
        if (pfont->GetTextureGlyphData())
            continue;
        if (limit && (int)pfont->GetGlyphShapeCount() > limit)
            continue;
        generateGlyphInfo(&glyphs, fonts[i]);
    }

    unsigned numTextures = packGlyphRects(&glyphs);
    generateTextures(&glyphs, numTextures);
}

// @0x1426612b0
void GFx_GenerateFontBitmaps(FontPackParams* params, const Array<FontResource*>& fonts, ImageCreator* pimageCreator,
                             Log* plog, ResourceId* ptextureIdGen, MemoryHeap* fontHeap, bool threadedLoading)
{
    if (!params || !pimageCreator)
        return;
    Ptr<FontGlyphPacker> ppacker =
        *SF_NEW FontGlyphPacker(params, pimageCreator, plog, ptextureIdGen, fontHeap, threadedLoading);
    ppacker->GenerateFontBitmaps(fonts);
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7FontGlyphPacker@GFx@Scaleform@@6B@ 0x1431917f8
// MS2-PIN: ??_7?$RefCountBaseNTS@VFontGlyphPacker@GFx@Scaleform@@$01@Scaleform@@6B@ 0x1431917f0
// MS2-PIN: ??_7RefCountVImpl@Scaleform@@6B@ 0x1431496d0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountVImpl@Scaleform@@$02@Scaleform@@6B@ 0x1431498a0
// MS2-PIN: ??_7?$RefCountBaseV@VImage@Render@Scaleform@@$02@Scaleform@@6B@ 0x1431498b8
// MS2-PIN: ??_7ImageBase@Render@Scaleform@@6B@ 0x1431498d0
// MS2-PIN: ??_7Image@Render@Scaleform@@6B@ 0x143149940
// MS2-PIN: ??_7ImageDelegate@Render@Scaleform@@6B@ 0x143149a28
// MS2-PIN: ??_7ImageDelegate@ImageResource@GFx@Scaleform@@6B@ 0x143149b10
// MS2-PIN: ??_7ImageResource@GFx@Scaleform@@6B@ 0x143149bf8
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
// MS2-PIN: ??_7?$RefCountBase@VTextureGlyph@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318a2a8
// MS2-PIN: ??_7TextureGlyph@Render@Scaleform@@6B@ 0x14318a2b0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0BAF@@Scaleform@@6B@ 0x14318a2b8
// MS2-PIN: ??_7?$RefCountBaseNTS@VTextureGlyphData@GFx@Scaleform@@$0BAF@@Scaleform@@6B@ 0x14318a2c0
// MS2-PIN: ??_7TextureGlyphData@GFx@Scaleform@@6B@ 0x14318a2c8
// MS2-PIN: ??_7TessBase@Render@Scaleform@@6B@ 0x14318fbd8
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@UGlyphGeometryKey@FontGlyphPacker@GFx@Scaleform@@IU1234@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@UGlyphGeometryKey@FontGlyphPacker@GFx@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@UGlyphGeometryKey@FontGlyphPacker@GFx@Scaleform@@IU1234@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x142663090
