// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the text mesh provider TU
// (Render_TextMeshProvider): TextMeshProvider collects the entries of a text layout (glyphs, backgrounds,
// selections, underlines, images, the mask), sorts them into layers of one kind and fill, and tessellates a layer
// when the mesh cache asks for it; VectorGlyphShape is the shared mesh provider of one vector glyph.
// MS2-UNIT: sfr_render_07o
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426e1210-0x1426e8fc0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/kernel/sf_simd.h"
#include "ms2/scaleform/include/render/render_textmeshprovider.h"
#include "ms2/scaleform/include/render/render_renderer2d.h"
#include "ms2/scaleform/include/render/render_glyphcache.h"
#include "ms2/scaleform/include/render/render_glyphqueue.h"
#include "ms2/scaleform/include/render/render_meshcache.h"
#include "ms2/scaleform/include/render/render_sync.h"
#include "ms2/scaleform/include/render/render_fontcachehandle.h"
#include "ms2/scaleform/include/render/render_textprimitivebundle.h"
#include "ms2/scaleform/include/render/render_matrixpool.h"
#include "ms2/scaleform/include/render/render_viewport.h"
#include "ms2/scaleform/include/render/render_math2d.h"
#include "ms2/scaleform/include/render/render_tessgen.h"
#include "ms2/scaleform/kernel/sf_arraystaticbuff.h"
#include <math.h>

namespace Scaleform { namespace Render {

// MS2-PIN: ??_7TextMeshProvider@Render@Scaleform@@6B@ 0x143193f50
// MS2-PIN: ??_7MeshProvider@Render@Scaleform@@6B@ 0x14318f0c0

// the EdgeAA factor of each 2-bit tessellator alpha / factor code (Renderer2DImpl)
extern const UByte Factors[4];   // 0x14318fb30

// vertex of the image and colour glyph quads: position, then texture coordinates
struct ImageGlyphVertex
{
    float x, y;
    float u, v;
    void  Set(float x_, float y_, float u_, float v_) { x = x_; y = y_; u = u_; v = v_; }
    static VertexFormat Format;   // 0x143a30328
};

// the alpha glyph quads' vertex (RasterGlyphVertex) is the glyph cache's, render_glyphcache.h

// a glyph packed into a font texture; only its image is read here (+0x10, after the refcount base)
class TextureGlyph : public RefCountBase<TextureGlyph, Stat_Default_Mem>
{
public:
    Ptr<Image> pImage;            // +0x10
    void*      Unk_18;            // +0x18
    RectF      UvBounds;          // +0x20 texture coordinates of the glyph
    PointF     UvOrigin;          // +0x30 its origin (baseline / pen position) in texture coordinates
};

// corner of a rectangle outline
struct CornerVertex
{
    float x, y;
    CornerVertex() {}
    CornerVertex(float x_, float y_) : x(x_), y(y_) {}
};

// where the edges v0 v1 and v1 v2, both pushed outwards by width, meet (v1 itself when they are parallel)
// @0x1426e1730
template<class VertexType>
static void calcMiter(const VertexType v0, const VertexType v1, const VertexType v2, float width, float* x, float* y)
{
    float l01 = Math2D::Distance(v0, v1);
    float l12 = Math2D::Distance(v1, v2);
    float ax  = width * (v1.y - v0.y) / l01;
    float ay  = width * (v0.x - v1.x) / l01;
    float bx  = width * (v2.y - v1.y) / l12;
    float by  = width * (v1.x - v2.x) / l12;
    *x = v1.x;
    *y = v1.y;
    Math2D::Intersection(v0.x + ax, v0.y + ay, v1.x + ax, v1.y + ay, v1.x + bx, v1.y + by, v2.x + bx, v2.y + by,
                         x, y, 0.001f);
}

// @0x1426e1ad0
TextMeshLayer::~TextMeshLayer()
{
}

// @0x1426e1940
TextMeshProvider::TextMeshProvider(GlyphCache* cache)
    : pCache(cache), Flags(0), Notifiers(cache->GetHeap()), Entries(cache->GetHeap()), Layers(cache->GetHeap()),
      PinCount(0), pBundle(0), pBundleEntry(0), HeightRatio(0), ClipBox(0, 0, 0, 0), ClearBox(0, 0, 0, 0),
      pRenderer(0)
{
}

// @0x1426e1b40
TextMeshProvider::~TextMeshProvider()
{
    Clear();
}

// @0x1426e1bb0
bool TextMeshProvider::CmpEntries::operator()(const TmpTextMeshEntry& a, const TmpTextMeshEntry& b) const
{
    if (a.LayerType != b.LayerType)
        return a.LayerType < b.LayerType;
    if (a.pFill != b.pFill)
        return a.pFill < b.pFill;
    return a.EntryIdx < b.EntryIdx;
}

// @0x1426e1c70
void TextMeshProvider::AddNotifier(TextNotifier* notifier)
{
    if (notifier)
    {
        Notifiers.PushBack(notifier);
        GlyphQueue::PinSlot(notifier->pSlot);
    }
}

// @0x1426e1cf0
void TextMeshProvider::AddToInUseList()
{
    if (Flags & (BF_InUseList | BF_InPinList))
        return;
    SetInUseList(true);
    pCache->GetTextInUse().PushBack(this);
}

// The layer matrix of a vector glyph (the view matrix with the glyph's origin and size scale prepended), its colour
// as a cxform (the colour as the add row, appended to the view cxform), and the key flags of its mesh. A cursor
// layer is keyed as a mask without edge AA.
// MS2-FUNCTIONAL: register allocation: the exe keeps sizeScale in xmm14 and materialises the zero per branch
// @0x1426e1d30
unsigned TextMeshProvider::CalcVectorParams(TextMeshLayer& layer, const TextMeshEntry& ent, const Matrix2F& scalingMtx,
                                            float sizeScale, const HMatrix& m, Renderer2DImpl* ren,
                                            unsigned meshGenFlags, float* keyData)
{
    const GlyphVectorEnt& vec = ent.EntryData.VectorData;

    if (m.Has3D())
    {
        Matrix2F m2d = Matrix2F::Scaling(sizeScale);
        m2d.AppendTranslation(vec.x, vec.y);
        Matrix3F m3d = m.GetMatrix3D();
        m3d.Prepend(m2d);
        if (layer.M.IsNull())
            layer.M = ren->GetMatrixPool().CreateMatrix(m3d);
        else
            layer.M.SetMatrix3D(m3d);
    }
    else
    {
        Matrix2F m2d = m.GetMatrix2D();
        m2d.PrependTranslation(vec.x, vec.y);
        m2d.PrependScaling(sizeScale, sizeScale);
        if (layer.M.IsNull())
            layer.M = ren->GetMatrixPool().CreateMatrix(m2d);
        else
            layer.M.SetMatrix2D(m2d);
    }

    UInt32 c = ent.mColor;
    Cxform colorCx(Cxform::NoInit);
    _mm_store_ps(colorCx.M[0], _mm_setzero_ps());
    colorCx.M[1][0] = (float)(int)((c >> 16) & 0xff) / 255.0f;
    colorCx.M[1][1] = (float)(int)((c >> 8) & 0xff) / 255.0f;
    colorCx.M[1][2] = (float)(int)(c & 0xff) / 255.0f;
    colorCx.M[1][3] = (float)(int)(c >> 24) / 255.0f;
    colorCx.Append(!m.pHandle->HasElement(MatrixPoolImpl::HMatrixConstants::Element_Cxform) ? Cxform::Identity
                                                                                           : *m.pHandle->GetCxformPtr());
    layer.M.SetCxform(colorCx);

    unsigned flags = MeshKey::KF_Fill;
    if (layer.Type != TextLayer_Cursor)
        flags += (meshGenFlags & Mesh_EdgeAA) << 6;
    else
        meshGenFlags = ~Mesh_EdgeAA;
    if (meshGenFlags & Mesh_Mask)
        flags |= MeshKey::KF_Mask;
    bool validKey = MeshKey::CalcMatrixKey(scalingMtx, keyData, 0);
    keyData[MeshKey::GetKeySize(flags) - 1] = 0; // the morph ratio
    if (!validKey)
        flags |= MeshKey::KF_Degenerate;
    return flags;
}

// @0x1426e21e0
void TextMeshProvider::Clear()
{
    if (IsInList())
    {
        SetInUseList(false);
        if (IsInPinList())
        {
            SetInPinList(false);
            UnpinSlots();
        }
        RemoveNode();
    }
    if (pBundle)
    {
        pBundle->removeEntryFromLayers(pBundleEntry);
        ClearBundle();
    }
    ClearEntries();
    Entries.ClearAndRelease();
    Layers.ClearAndRelease();
}

// @0x1426e23f0
void TextMeshProvider::ClearEntries()
{
    UPInt i;
    for (i = 0; i < Notifiers.GetSize(); ++i)
        pCache->GetQueue().RemoveNotifier(Notifiers[i]);
    Notifiers.ClearAndRelease();
    for (i = 0; i < Entries.GetSize(); ++i)
    {
        TextMeshEntry& ent = Entries[i];
        if (ent.LayerType == TextLayer_Shapes || ent.LayerType == TextLayer_Shapes_Masked)
            ent.EntryData.VectorData.pFont->Release();
    }
    Entries.ClearAndRelease();
    Flags &= ~(BF_Created | BF_HasVectorGlyphs | BF_HasUnderlines | BF_HasMask);
}

// font and glyph flag tests in the exe's bit-extract form
static inline bool fontFlag(const Font* f, unsigned bit) { return ((f->GetFontFlags() >> bit) & 1) != 0; }
static inline bool glyphFlag(const GlyphParam& gp, unsigned bit) { return ((gp.Flags >> bit) & 1) != 0; }

// Walks the layout's records into entries (glyphs, backgrounds, selections, underlines, cursors, images), adds the
// clip mask when vector glyphs or underlines may stick out, sorts the entries into layers and gives every layer
// its mesh (vector glyph layers get theirs from createVectorGlyph).
// MS2-FUNCTIONAL: block placement (the exe moves the later record cases past the loop) and xmm allocation; integer ops identical
// @0x1426e24d0
bool TextMeshProvider::CreateMeshData(const TextLayout* layout, Renderer2DImpl* ren, const HMatrix& m,
                                      const Matrix4F& m4, const Viewport& vp, unsigned meshGenFlags)
{
    pRenderer = ren;

    TmpTextStorage storage(Memory::GetGlobalHeap());

    Flags &= ~(BF_Created | BF_HasVectorGlyphs | BF_HasUnderlines);
    Matrix2F viewMatrix = m.GetMatrix2D();
    bool     snap       = !(m.Has3D() || viewMatrix.IsFreeRotation());

    GlyphRunData data;
    data.Param           = layout->GetParam();
    data.Bounds          = layout->GetBounds();
    data.pFont           = 0;
    data.pFontHandle     = 0;
    data.FontSize        = 0;
    data.VectorSize      = 0;
    data.RasterSize      = 0;
    data.NomWidth        = 0;
    data.NomHeight       = 0;
    data.TexHeight       = 0;
    data.mColor          = 0;
    data.NewLineX        = 0;
    data.NewLineY        = 0;
    data.GlyphBounds     = RectF(0, 0, 0, 0);
    data.DirMtx          = m.GetMatrix2D();
    data.InvMtx          = data.DirMtx.GetInverse();
    data.HeightRatio     = calcHeightRatio(m, m4, vp);
    data.HintedNomHeight = 0;
    HeightRatio          = data.HeightRatio;

    // no optimized-for-readability or auto-fit glyphs in 3D
    if (m.Has3D())
    {
        data.Param.TextParam.Flags &= ~(GlyphParam::OptRead | GlyphParam::AutoFit);
        data.Param.ShadowParam.Flags &= ~(GlyphParam::OptRead | GlyphParam::AutoFit);
    }

    Flags &= ~BF_Clip;
    ClipBox = layout->GetClipBox();
    if (!ClipBox.IsEmpty())
        Flags |= BF_Clip;

    Font* font = 0;
    Flags |= BF_Creating;

    TextLayout::Record rec;
    UPInt pos       = 0;
    bool  cacheIsOK = true;
    while (cacheIsOK && (pos = layout->ReadNext(pos, &rec)) != 0)
    {
        switch (layout->GetRecordType(rec))
        {
        case TextLayout::Record_Char:
            if ((rec.mChar.Flags & TextLayout::Flag_Invisible) == 0)
                cacheIsOK = addGlyph(storage, data, rec.mChar.GlyphIndex,
                                     (rec.mChar.Flags & TextLayout::Flag_FauxBold) != 0,
                                     (rec.mChar.Flags & TextLayout::Flag_FauxItalic) != 0, snap, meshGenFlags);
            else
                cacheIsOK = true;
            data.NewLineX += rec.mChar.Advance;
            break;

        case TextLayout::Record_Color:
            data.mColor = rec.mColor.mColor;
            break;

        case TextLayout::Record_Background:
            addBackground(storage, rec.mBackground.BackgroundColor, rec.mBackground.BorderColor, data.Bounds);
            break;

        case TextLayout::Record_NewLine:
            data.NewLineX = rec.mLine.x;
            data.NewLineY = rec.mLine.y;
            if (snap && ((data.pFont && fontFlag(data.pFont, 7)) || glyphFlag(data.Param.TextParam, 0)))
                data.NewLineY = snapY(data);
            break;

        case TextLayout::Record_Font:
            font             = rec.mFont.pFont;
            data.pFont       = font;
            data.pFontHandle = pCache->RegisterFont(font);
            data.FontSize    = rec.mFont.mSize;
            data.TexHeight   = font->GetTextureGlyphHeight();
            // a raster-only font starts on a whole pixel line
            if (snap && data.pFont && fontFlag(data.pFont, 7))
                data.NewLineY = snapY(data);
            break;

        case TextLayout::Record_Selection:
            addSelection(storage, rec.mSelection.mColor,
                         RectF(rec.mSelection.x1, rec.mSelection.y1, rec.mSelection.x2, rec.mSelection.y2));
            break;

        case TextLayout::Record_Underline:
            addUnderline(storage, rec.mUnderline.mColor, (TextUnderlineStyle)rec.mUnderline.Style, rec.mUnderline.x,
                         rec.mUnderline.y, rec.mUnderline.Len);
            Flags |= BF_HasUnderlines;
            break;

        case TextLayout::Record_Cursor:
            addCursor(storage, rec.mCursor.mColor,
                      RectF(rec.mCursor.x1, rec.mCursor.y1, rec.mCursor.x2, rec.mCursor.y2));
            break;

        case TextLayout::Record_Image:
            addImage(storage, data, rec.mImage.pImage, rec.mImage.ScaleX, rec.mImage.ScaleY, rec.mImage.BaseLine,
                     snap);
            data.NewLineX += rec.mImage.Advance;
            break;

        case TextLayout::Record_RefCntData:
            break;
        }
    }

    UPInt i;
    if ((Flags & BF_Clip) && (Flags & (BF_HasVectorGlyphs | BF_HasUnderlines)))
    {
        // the clear box: everything drawn, padded by a screen pixel; masked shapes and underlines get own layers
        addMask(storage);
        bool first = true;
        ClearBox.Clear();
        for (i = 0; i < storage.Entries.GetSize(); ++i)
        {
            TmpTextMeshEntry& ent = storage.Entries[i];
            RectF bounds(0, 0, 0, 0);
            switch (ent.LayerType)
            {
            case TextLayer_RasterText:
                bounds = RectF(ent.EntryData.RasterData.Coord[0], ent.EntryData.RasterData.Coord[1],
                               ent.EntryData.RasterData.Coord[2], ent.EntryData.RasterData.Coord[3]);
                break;
            case TextLayer_PackedText:
                bounds = RectF(ent.EntryData.PackedData.Coord[0], ent.EntryData.PackedData.Coord[1],
                               ent.EntryData.PackedData.Coord[2], ent.EntryData.PackedData.Coord[3]);
                break;
            case TextLayer_Images:
                bounds = RectF(ent.EntryData.ImageData.Coord[0], ent.EntryData.ImageData.Coord[1],
                               ent.EntryData.ImageData.Coord[2], ent.EntryData.ImageData.Coord[3]);
                break;
            case TextLayer_Shapes:
            {
                const GlyphVectorEnt& vec = ent.EntryData.VectorData;
                float scale = vec.FontSize / vec.pFont->GetNominalGlyphHeight();
                vec.pFont->GetGlyphBounds(vec.GlyphIndex, &bounds);
                bounds.x1 = bounds.x1 * scale + vec.x;
                bounds.y1 = bounds.y1 * scale + vec.y;
                bounds.x2 = bounds.x2 * scale + vec.x;
                bounds.y2 = bounds.y2 * scale + vec.y;
                ent.LayerType = TextLayer_Shapes_Masked;
                break;
            }
            }
            if (!bounds.IsEmpty())
            {
                if (first)
                    ClearBox = bounds;
                else
                    ClearBox.Union(bounds);
                first = false;
            }
            if (ent.LayerType == TextLayer_Underline)
                ent.LayerType = TextLayer_Underline_Masked;
        }
        float pad = 1 / HeightRatio;
        ClearBox.x1 -= pad;
        ClearBox.y1 -= pad;
        ClearBox.x2 += pad;
        ClearBox.y2 += pad;
        Flags |= BF_HasMask;
    }

    UnpinSlots();
    Flags &= ~BF_Creating;

    sortEntries(storage);

    for (i = 0; i < Layers.GetSize(); ++i)
    {
        TextMeshLayer& layer = Layers[i];
        if (layer.Type == TextLayer_Shapes || layer.Type == TextLayer_Shapes_Masked)
        {
            createVectorGlyph((unsigned)i, ren, m, meshGenFlags);
            Flags |= BF_HasVectorGlyphs;
        }
        else
        {
            layer.M     = m;
            layer.pMesh = *SF_HEAP_AUTO_NEW(this) Mesh(ren, this, viewMatrix, 0, (unsigned)i, meshGenFlags);
        }
    }

    Flags |= BF_Created;
    return true;
}

// Builds the mesh of one layer. The tessellation matrix is only the height ratio (the local-to-screen scale): that
// keeps it from degenerating under heavy 3D or non-uniform transforms, at some cost to the EdgeAA there.
// MS2-FUNCTIONAL: generate* tail calls not emitted (safebuffers stands in for the exe having no GS cookie), scheduling
// @0x1426e3130
__declspec(safebuffers) bool TextMeshProvider::GetData(MeshBase* mesh, VertexOutput* verOut, unsigned meshGenFlags)
{
    unsigned             layerIdx = mesh->GetLayer();
    Renderer2DImpl*      ren      = mesh->GetRenderer();
    const TextMeshLayer& layer    = GetLayer(layerIdx);
    TextMeshEntry*       ent      = &Entries[layer.Start];
    Matrix2F             mtx      = Matrix2F::Scaling(HeightRatio, HeightRatio);

    switch (layer.Type)
    {
    case TextLayer_Background:
        return generateRectangle(ren, verOut, mtx, ent->EntryData.BackgroundData.Coord, ent->mColor,
                                 ent->EntryData.BackgroundData.BorderColor, meshGenFlags);
    case TextLayer_Selection:
        return generateSelection(ren, verOut, layer, mtx, meshGenFlags);
    case TextLayer_Shadow:
    case TextLayer_ShadowText:
    case TextLayer_RasterText:
        return generateRasterMesh(verOut, layer);
    case TextLayer_PackedText:
    case TextLayer_PackedDFAText:
        return generatePackedMesh(verOut, layer);
    case TextLayer_Images:
        return generateImageMesh(verOut, layer);
    case TextLayer_Shapes:
    case TextLayer_Shapes_Masked:
        // vector glyphs have their own mesh provider (VectorGlyphShape)
        break;
    case TextLayer_Underline:
    case TextLayer_Underline_Masked:
        return generateUnderlines(ren, verOut, layer, mtx, meshGenFlags);
    case TextLayer_Cursor:
        return generateRectangle(ren, verOut, mtx, ent->EntryData.SelectionData.Coord, ent->mColor, 0, meshGenFlags);
    case TextLayer_Mask:
        return generateMask(verOut, layer);
    }
    return false;
}

// The fill of a layer: vertex colour for the solid kinds, the glyph texture (alpha, or full colour for a packed colour
// glyph) for the glyph kinds, the image for images; the mask pass always gets the mask fill.
// @0x1426e3b80
void TextMeshProvider::GetFillData(FillData* data, unsigned layer, unsigned, unsigned meshGenFlags)
{
    if (meshGenFlags & Mesh_Mask)
    {
        *data = FillData(Fill_Mask);
        return;
    }

    const TextMeshLayer& l = Layers[layer];
    switch (l.Type)
    {
    case TextLayer_Background:
    case TextLayer_Selection:
    case TextLayer_Shapes:
    case TextLayer_Underline:
    case TextLayer_Cursor:
    case TextLayer_Shapes_Masked:
    case TextLayer_Underline_Masked:
        *data = FillData(Fill_VColor);
        data->PrimFill = PrimFill_VColor;
        data->pVFormat = &VertexXY16iCF32::Format;
        break;

    case TextLayer_Shadow:
    case TextLayer_ShadowText:
    case TextLayer_RasterText:
    {
        Image* img = pCache->GetImage(Entries[l.Start].TextureId);
        *data = FillData(img, ImageFillMode(Wrap_Clamp, Sample_Linear));
        data->PrimFill = PrimFill_UVTextureAlpha_VColor;
        data->pVFormat = &RasterGlyphVertex::Format;
        break;
    }

    case TextLayer_PackedText:
    {
        Image* img = Entries[l.Start].EntryData.PackedData.pGlyph->pImage;
        *data = FillData(img, ImageFillMode(Wrap_Clamp, Sample_Linear));
        if (img->GetFormat() == Image_A8)
        {
            data->PrimFill = PrimFill_UVTextureAlpha_VColor;
            data->pVFormat = &RasterGlyphVertex::Format;
        }
        else
        {
            data->PrimFill = PrimFill_UVTexture;
            data->pVFormat = &ImageGlyphVertex::Format;
        }
        break;
    }

    case TextLayer_PackedDFAText:
        *data = FillData(Entries[l.Start].EntryData.PackedData.pGlyph->pImage, ImageFillMode(Wrap_Clamp, Sample_Linear));
        data->PrimFill = PrimFill_UVTextureDFAlpha_VColor;
        data->pVFormat = &RasterGlyphVertex::Format;
        break;

    case TextLayer_Images:
        *data = FillData(Entries[l.Start].EntryData.ImageData.pImage, ImageFillMode(Wrap_Clamp, Sample_Linear));
        data->PrimFill = PrimFill_UVTexture;
        data->pVFormat = &ImageGlyphVertex::Format;
        break;

    case TextLayer_Mask:
        *data = FillData(Fill_Mask);
        break;
    }
}

// The mesh of one vector glyph: its outline goes through the tessellator in view space (so the curves are flattened
// for the size it shows at), comes back to shape space and is stretched into the 16-bit vertex range.
// @0x1426e3350
bool VectorGlyphShape::GetData(MeshBase* mesh, VertexOutput* verOut, unsigned meshGenFlags)
{
    Renderer2DImpl* ren = mesh->GetRenderer();
    const Matrix2F& mtx = mesh->GetViewMatrix();

    enum { VerBufSize = 128, TriBufSize = 128 };

    VertexXY16iCF32 meshVer[VerBufSize];
    TessVertex      tessVer[VerBufSize];
    UInt16          tri[TriBufSize * 3];
    TessMesh        tessMesh;

    if (pShape->IsEmpty())
        return generateNullVectorMesh(verOut);

    MeshGenerator* gen = ren->GetMeshGen();
    gen->Clear();

    // glyphs tolerate twice the shape tolerances
    ToleranceParams param = ren->GetToleranceParams();
    param.CurveTolerance *= 2;
    param.CollinearityTolerance *= 2;

    bool edgeAA = (meshGenFlags & Mesh_EdgeAA) != 0 && (meshGenFlags & Mesh_Mask) == 0;
    gen->mTess.SetEdgeAAWidth(edgeAA ? param.EdgeAAScale * 0.5f : 0.0f);
    gen->mTess.SetFillRule(Tessellator::FillNonZero);

    ShapePosInfo  pos(pShape->GetStartingPos());
    ShapePathType pathType;
    PathEdgeType  pathEdge;
    float         coord[Edge_MaxCoord];
    unsigned      styles[3];
    bool          first = true;

    Matrix2F m2 = mtx;

    while ((pathType = pShape->ReadPathInfo(&pos, coord, styles)) != Shape_EndShape)
    {
        // a glyph is a single layer
        if (!first && pathType == Shape_NewLayer)
            break;
        first = false;

        if (styles[0] != styles[1])
        {
            m2.Transform(&coord[0], &coord[1]);
            gen->mTess.AddVertex(coord[0], coord[1]);
            while ((pathEdge = pShape->ReadEdge(&pos, coord)) != Edge_EndPath)
            {
                if (pathEdge == Edge_LineTo)
                {
                    m2.Transform(&coord[0], &coord[1]);
                    gen->mTess.AddVertex(coord[0], coord[1]);
                }
                else if (pathEdge == Edge_QuadTo)
                {
                    m2.Transform(&coord[0], &coord[1]);
                    m2.Transform(&coord[2], &coord[3]);
                    TessellateQuadCurve(&gen->mTess, param, coord[0], coord[1], coord[2], coord[3]);
                }
                else if (pathEdge == Edge_CubicTo)
                {
                    m2.Transform(&coord[0], &coord[1]);
                    m2.Transform(&coord[2], &coord[3]);
                    m2.Transform(&coord[4], &coord[5]);
                    TessellateCubicCurve(&gen->mTess, param, coord[0], coord[1], coord[2], coord[3], coord[4],
                                         coord[5]);
                }
            }
            gen->mTess.FinalizePath(1, 0, false, false);
        }
        else
        {
            // a path with the same style on both sides fills nothing
            pShape->SkipPathData(&pos);
        }
    }

    gen->mTess.Tessellate(false);

    bool ret = true;
    if (gen->mTess.GetMeshCount() && gen->mTess.GetVertexCount())
    {
        gen->mTess.Transform(mtx.GetInverse());
        Matrix2F m16i = gen->mTess.StretchTo(-32768 + 4, -32768 + 4, 32768 - 4, 32768 - 4);

        VertexOutput::Fill fill;
        fill.VertexCount = gen->mTess.GetMeshVertexCount(0);
        fill.IndexCount  = gen->mTess.GetMeshTriangleCount(0) * 3;
        fill.pFormat     = &VertexXY16iCF32::Format;
        fill.FillIndex0  = 0;
        fill.FillIndex1  = 0;
        fill.MergeFlags  = 0;
        fill.MeshIndex   = 0;

        ret = verOut->BeginOutput(&fill, 1, m16i);
        if (ret)
        {
            gen->mTess.GetMesh(0, &tessMesh);

            unsigned start = 0;
            unsigned n;
            while ((n = gen->mTess.GetVertices(&tessMesh, tessVer, VerBufSize)) > 0)
            {
                for (unsigned i = 0; i < n; ++i)
                {
                    const TessVertex& t = tessVer[i];
                    VertexXY16iCF32&  v = meshVer[i];
                    v.x = (SInt16)floorf(t.x < 0 ? t.x - 0.5f : t.x + 0.5f);
                    v.y = (SInt16)floorf(t.y < 0 ? t.y - 0.5f : t.y + 0.5f);
                    v.Color = 0xFFFFFFFF;
                    v.Factors[0] = Factors[t.Flags & 3];
                    v.Factors[1] = Factors[(t.Flags >> 2) & 3];
                }
                verOut->SetVertices(0, start, meshVer, n);
                start += n;
            }

            start = 0;
            unsigned triCount = gen->mTess.GetMeshTriangleCount(fill.MeshIndex);
            while (start < triCount)
            {
                unsigned num = TriBufSize;
                if (start + num > triCount)
                {
                    num = triCount - start;
                    if (num == 0)
                        break;
                }
                gen->mTess.GetTrianglesI16(fill.MeshIndex, tri, start, num);
                verOut->SetIndices(0, start * 3, tri, num * 3);
                start += num;
            }
            verOut->EndOutput();
        }
    }
    else
        ret = generateNullVectorMesh(verOut);

    gen->Clear();
    return ret;
}

// a vector glyph is a single vertex colour fill
// @0x1426e3e70
void VectorGlyphShape::GetFillData(FillData* data, unsigned, unsigned, unsigned)
{
    *data = FillData(Fill_VColor);
    data->pVFormat = &VertexXY16iCF32::Format;
    data->PrimFill = PrimFill_VColor;
}

// The remaining VectorGlyphShape provider virtuals: a glyph keeps no per-mesh state, is one layer of one fill drawn
// untransformed, and reports its cached bounds whatever the matrix.
// @0x1426e4210
void VectorGlyphShape::OnEvict(MeshBase*)
{
}

// @0x1426e3f10
RectF VectorGlyphShape::GetIdentityBounds() const
{
    return Bounds;
}

// @0x1426e30f0
RectF VectorGlyphShape::GetBounds(const Matrix2F&) const
{
    return Bounds;
}

// @0x1426e3110
RectF VectorGlyphShape::GetCorrectBounds(const Matrix2F&, float, StrokeGenerator*, const ToleranceParams*) const
{
    return Bounds;
}

// @0x1426e4190
bool VectorGlyphShape::HitTestShape(const Matrix2F&, float, float, float, StrokeGenerator*,
                                    const ToleranceParams*) const
{
    return false;
}

// @0x1426e4090
unsigned VectorGlyphShape::GetLayerCount() const
{
    return 1;
}

// @0x1426e3b70
unsigned VectorGlyphShape::GetFillCount(unsigned, unsigned) const
{
    return 1;
}

// @0x1426e3ef0
void VectorGlyphShape::GetFillMatrix(MeshBase*, Matrix2F* matrix, unsigned, unsigned, unsigned)
{
    matrix->SetIdentity();
}

// @0x1426e3f30
Fence* TextMeshProvider::GetLatestFence() const
{
    Ptr<Fence> latest = 0;
    for (UPInt li = 0; li < Layers.GetSize(); ++li)
    {
        Mesh* mesh = Layers[li].pMesh;
        if (!mesh)
            continue;
        for (UPInt ci = 0; ci < mesh->CacheItems.GetSize(); ++ci)
        {
            if (!mesh->CacheItems[ci]->GPUFence)
                continue;
            if (!latest || *mesh->CacheItems[ci]->GPUFence > *latest)
                latest = mesh->CacheItems[ci]->GPUFence;
        }
    }
    return latest;
}

// @0x1426e40a0
HMatrix TextMeshProvider::GetMaskClearBounds() const
{
    return ClearBounds;
}

// @0x1426e4100
MeshUseStatus TextMeshProvider::GetMeshUseStatus() const
{
    MeshUseStatus status = MUS_Uncached;
    if (PinCount)
        return MUS_Pinned;
    for (UPInt i = 0; i < GetLayerCount(); i++)
    {
        const TextMeshLayer& l = GetLayer((unsigned)i);
        if (l.Type > TextLayer_RasterText)
            break;
        if (l.Type >= TextLayer_Shadow && l.pMesh)
        {
            MeshUseStatus s = l.pMesh->GetUseStatus();
            if (s > status)
                status = s;
        }
    }
    return status;
}

// @0x1426e41a0
bool TextMeshProvider::NeedsUpdate(const HMatrix& m, const Matrix4F& m4, const Viewport& vp,
                                   const TextFieldParam& param) const
{
    float ratio = calcHeightRatio(m, m4, vp);
    float k     = 0.85f;
    if (param.TextParam.Flags & GlyphParam::OptRead)
        k = 0.99f;
    return HeightRatio * k > ratio || ratio > HeightRatio / k;
}

// @0x1426e4220
void TextMeshProvider::OnEvictSlots()
{
    Clear();
}

// @0x1426e4230
void TextMeshProvider::PinSlots()
{
    for (UPInt i = 0; i < Notifiers.GetSize(); ++i)
        GlyphQueue::PinSlot(Notifiers[i]->pSlot);
}

// @0x1426e4550
void TextMeshProvider::UnpinSlots()
{
    Ptr<Fence> fence = GetLatestFence();
    for (UPInt i = 0; i < Notifiers.GetSize(); ++i)
        GlyphQueue::UnpinSlot(Notifiers[i]->pSlot, fence);
}

// @0x1426e46f0
HMatrix TextMeshProvider::UpdateMaskClearBounds(HMatrix viewMat)
{
    Matrix2F m;
    m.SetRectToRect(0, 0, 1, 1, ClearBox.x1, ClearBox.y1, ClearBox.x2, ClearBox.y2);
    if (viewMat.Has3D())
    {
        Matrix3F m3(viewMat.GetMatrix3D());
        m3.Prepend(m);
        if (ClearBounds.IsNull())
            ClearBounds = pRenderer->GetMatrixPool().CreateMatrix(m3, HMatrix::Has_3D);
        else
            ClearBounds.SetMatrix3D(m3);
    }
    else
    {
        m.Append(viewMat.GetMatrix2D());
        if (ClearBounds.IsNull())
            ClearBounds = pRenderer->GetMatrixPool().CreateMatrix(m, 0);
        else
            ClearBounds.SetMatrix2D(m);
    }
    return ClearBounds;
}

// @0x1426e4900
void TextMeshProvider::addBackground(TmpTextStorage& storage, UInt32 color, UInt32 borderColor, const RectF& rect)
{
    TmpTextMeshEntry e;
    e.LayerType = TextLayer_Background;
    e.TextureId = 0;
    e.EntryIdx  = (unsigned)storage.Entries.GetSize();
    e.mColor    = color;
    e.pFill     = pCache->GetFill(TextLayer_Background, 0);
    e.pFill->AddRef();
    e.EntryData.BackgroundData.Coord[0]    = rect.x1;
    e.EntryData.BackgroundData.Coord[1]    = rect.y1;
    e.EntryData.BackgroundData.Coord[2]    = rect.x2;
    e.EntryData.BackgroundData.Coord[3]    = rect.y2;
    e.EntryData.BackgroundData.BorderColor = borderColor;
    storage.Entries.PushBack(e);
}

// @0x1426e4970
void TextMeshProvider::addCursor(TmpTextStorage& storage, UInt32 color, const RectF& rect)
{
    TmpTextMeshEntry e;
    e.LayerType = TextLayer_Cursor;
    e.TextureId = 0;
    e.EntryIdx  = (unsigned)storage.Entries.GetSize();
    e.mColor    = color;
    e.pFill     = pCache->GetFill(TextLayer_Cursor, 0);
    e.pFill->AddRef();
    e.EntryData.SelectionData.Coord[0] = rect.x1;
    e.EntryData.SelectionData.Coord[1] = rect.y1;
    e.EntryData.SelectionData.Coord[2] = rect.x2;
    e.EntryData.SelectionData.Coord[3] = rect.y2;
    storage.Entries.PushBack(e);
}

// @0x1426e49d0
bool TextMeshProvider::addGlyph(TmpTextStorage& storage, GlyphRunData& data, unsigned glyphIndex, bool fauxBold,
                                bool fauxItalic, bool snap, unsigned meshGenFlags)
{
    bool  needVector = false;
    bool  drawShadow = true;
    float screenSize = data.FontSize * data.HeightRatio;

    // a font texture glyph is used as is unless the text is drawn too large for it (then a vector glyph, no shadow)
    const TextureGlyph* tgl = data.pFont->GetTextureGlyph(glyphIndex);
    if (tgl)
    {
        if (fontFlag(data.pFont, 12) || screenSize <= data.TexHeight * pCache->GetMaxRasterScale())
        {
            if (tgl->pImage)
                addTextureGlyph(storage, tgl, data, data.mColor);
            return true;
        }
        needVector = true;
        drawShadow = false;
    }

    if (meshGenFlags & Mesh_Mask)
        needVector = true;

    bool textBold   = (data.Param.TextParam.Flags & GlyphParam::FauxBold) != 0;
    bool textItalic = (data.Param.TextParam.Flags & GlyphParam::FauxItalic) != 0;
    Ptr<VectorGlyphShape> sh = *pCache->CreateGlyphShape(data, glyphIndex, screenSize, textBold | fauxBold,
                                                         textItalic | fauxItalic, data.Param.TextParam.GetOutline(),
                                                         false);

    GlyphParam gp = data.Param.TextParam;
    gp.pFont      = data.pFontHandle;
    gp.GlyphIndex = (UInt16)glyphIndex;
    gp.SetFauxBold(((data.Param.TextParam.Flags & GlyphParam::FauxBold) != 0) | fauxBold);
    gp.SetFauxItalic(((data.Param.TextParam.Flags & GlyphParam::FauxItalic) != 0) | fauxItalic);
    gp.SetFontSize(pCache->GetCachedFontSize(gp, screenSize, data.pRaster != 0));
    gp.SetUseRaster(data.RasterSize != 0);
    gp.SetStretch(false);

    // small readable glyphs of an unhinted vector font are rasterized stretched
    if (glyphFlag(gp, 0) && !glyphFlag(gp, 8) && data.VectorSize == 0 && data.RasterSize == 0 &&
        !fontFlag(gp.pFont->pFont, 7) && gp.GetBlurX() == 0 && gp.GetBlurY() == 0)
    {
        float w = gp.pFont->pFont->GetGlyphWidth(gp.GlyphIndex) * screenSize / gp.pFont->pFont->GetNominalGlyphHeight();
        if (3 * w < pCache->GetQueue().GetMaxSlotHeight())
            gp.SetStretch(true);
    }

    bool autoFit = pCache->GetParams().UseAutoFit && snap && gp.GetOutline() == 0 && glyphFlag(gp, 0) && glyphFlag(gp, 1) &&
                   screenSize > 6 && (fontFlag(gp.pFont->pFont, 13) || fontFlag(gp.pFont->pFont, 4));
    gp.SetAutoFit(autoFit);

    if (!glyphFlag(data.Param.ShadowParam, 5) && !needVector)
    {
        float      stretch = (gp.Flags & GlyphParam::Stretch) ? 2.5f : 1.0f;
        GlyphNode* node    = pCache->FindGlyph(this, gp);
        if (node)
            addRasterGlyph(storage, TextLayer_RasterText, data, data.mColor, node, screenSize, snap, stretch);
        else
        {
            if (gp.BlurX || gp.BlurY)
                node = pCache->RasterizeShadow(data, this, gp, screenSize, data.pRaster);
            else
                node = pCache->RasterizeGlyph(data, this, gp);
            if (node)
                addRasterGlyph(storage, TextLayer_RasterText, data, data.mColor, node, screenSize, snap, stretch);
            else
            {
                GlyphCache::RasResult res = pCache->GetRasResult();
                if (res == GlyphCache::Res_ShapeNotFound)
                {
                    // a missing glyph shows as a small box
                    float w = data.FontSize / 4;
                    float h = data.FontSize / 2;
                    RectF bounds(data.NewLineX + w / 2, data.NewLineY - h - h / 4, data.NewLineX + w + w / 2,
                                 data.NewLineY - h / 4);
                    addSelection(storage, data.mColor, bounds);
                    return true;
                }
                if (res == GlyphCache::Res_ShapeIsEmpty)
                    return true;
                if (res == GlyphCache::Res_CacheFull)
                {
                    if (!pCache->GetParams().UseVectorOnFullCache)
                        return false;
                    needVector = true;
                }
                if (res == GlyphCache::Res_ShapeIsTooBig || res == GlyphCache::Res_NoRasterCache)
                    needVector = true;
            }
        }
    }

    if (needVector && !data.pShape->IsEmpty())
    {
        addVectorGlyph(storage, data.mColor, data.pFontHandle, (UInt16)glyphIndex, gp.Flags, data.FontSize,
                       data.NewLineX, data.NewLineY);
        Flags |= BF_HasVectorGlyphs;
    }

    if (data.Param.ShadowColor && drawShadow)
    {
        UInt32 color = data.Param.ShadowColor;
        gp           = data.Param.ShadowParam;
        gp.SetOptRead(false);
        gp.SetAutoFit(false);
        gp.pFont = data.pFontHandle;
        gp.SetFauxBold(((data.Param.TextParam.Flags & GlyphParam::FauxBold) != 0) | fauxBold);
        gp.SetFauxItalic(((data.Param.TextParam.Flags & GlyphParam::FauxItalic) != 0) | fauxItalic);
        gp.SetFontSize(pCache->GetCachedShadowSize(screenSize, data.pRaster));
        gp.GlyphIndex = (UInt16)glyphIndex;

        GlyphNode* node = pCache->FindGlyph(this, gp);
        if (node)
            addRasterGlyph(storage, TextLayer_Shadow, data, color, node, screenSize, snap, 1);
        else
        {
            node = pCache->RasterizeShadow(data, this, gp, screenSize, data.pRaster);
            if (node)
                addRasterGlyph(storage, TextLayer_Shadow, data, color, node, screenSize, snap, 1);
            else if (pCache->GetRasResult() == GlyphCache::Res_CacheFull)
                return false;
        }
    }
    return true;
}

// @0x1426e5130
void TextMeshProvider::addImage(TmpTextStorage& storage, const GlyphRunData& data, Image* img, float scaleX,
                                float scaleY, float baseLine, bool snap)
{
    float x = data.NewLineX;
    float y = data.NewLineY - baseLine * scaleY;
    if (snap)
        x = snapX(data);

    TmpTextMeshEntry e;
    e.LayerType = TextLayer_Images;
    e.TextureId = 0;
    e.EntryIdx  = (unsigned)storage.Entries.GetSize();

    // the image's own texture, clamped and filtered
    PrimitiveFillData fd(PrimFill_UVTexture, &ImageGlyphVertex::Format, img->GetTexture(pCache->GetTextureManager()),
                         ImageFillMode(Wrap_Clamp, Sample_Linear));
    e.pFill = pCache->GetPrimitiveFillManager()->CreateFill(fd);

    e.EntryData.ImageData.Coord[0] = x;
    e.EntryData.ImageData.Coord[1] = y;
    e.EntryData.ImageData.Coord[2] = x + (float)img->GetSize().Width * scaleX;
    e.EntryData.ImageData.Coord[3] = y + (float)img->GetSize().Height * scaleY;
    e.EntryData.ImageData.pImage   = img;
    storage.Entries.PushBack(e);
}

// @0x1426e6380
void TextMeshProvider::createVectorGlyph(unsigned layerIdx, Renderer2DImpl* ren, const HMatrix& m, unsigned meshGenFlags)
{
    TextMeshLayer& layer = Layers[layerIdx];
    TextMeshEntry& ent   = Entries[layer.Start];

    // a run of one glyph, rebuilt from the entry
    GlyphRunData data;
    data.pFont           = ent.EntryData.VectorData.pFont;
    data.pFontHandle     = pCache->RegisterFont(data.pFont);
    data.FontSize        = ent.EntryData.VectorData.FontSize;
    data.VectorSize      = 0;
    data.RasterSize      = 0;
    data.NomWidth        = 0;
    data.NomHeight       = 0;
    data.TexHeight       = 0;
    data.mColor          = ent.mColor;
    data.NewLineX        = ent.EntryData.VectorData.x;
    data.NewLineY        = ent.EntryData.VectorData.y;
    data.GlyphBounds     = RectF(0, 0, 0, 0);
    data.HeightRatio     = HeightRatio;
    data.HintedNomHeight = 0;

    UInt16 flags = ent.EntryData.VectorData.Flags;
    Ptr<VectorGlyphShape> shape =
        *pCache->CreateGlyphShape(data, ent.EntryData.VectorData.GlyphIndex, (float)data.VectorSize,
                                  (flags & GlyphParam::FauxBold) != 0, (flags & GlyphParam::FauxItalic) != 0,
                                  flags >> 12, true);
    data.HintedNomHeight = shape->pShape->GetHintedSize();

    float sizeScale = data.FontSize / data.NomHeight;
    float keyData[MeshKey::MaxKeySize];
    Matrix2F scaling = Matrix2F::Scaling(HeightRatio * sizeScale);
    unsigned keyFlags = CalcVectorParams(layer, ent, scaling, sizeScale, m, ren, meshGenFlags, keyData);

    const ToleranceParams& cfg = ren->GetToleranceParams();
    layer.pMeshKey  = *ren->GetMeshKeyManager()->CreateMatchingKey(shape, 0, keyFlags, keyData, cfg);
    layer.pShape    = shape;
    layer.SizeScale = sizeScale;

    // the first use of this key: its mesh, scaled to the screen size
    if (!layer.pMeshKey->pMesh)
        layer.pMeshKey->pMesh =
            *SF_HEAP_AUTO_NEW(this) Mesh(ren, layer.pMeshKey->GetKeySet(), scaling, 0, 0, meshGenFlags);
    layer.pMesh = (Mesh*)layer.pMeshKey->pMesh.GetPtr();
}

// MS2-FUNCTIONAL: scheduling and register allocation of the two rect transforms (the exe keeps three xmm
// registers live across them)
// @0x1426e6690
bool TextMeshProvider::generateImageMesh(VertexOutput* verOut, const TextMeshLayer& layer)
{
    ImageGlyphVertex ver[4];
    UInt16 idx[6] = { 0, 1, 2, 0, 2, 3 };
#ifdef __clang__
    // clang folds the initializer into .rdata: set the exe global's address at run time instead
    VertexOutput::Fill fill = { 4, 6, 0, 0, 0, 0 };
    fill.pFormat = &ImageGlyphVertex::Format;
#else
    VertexOutput::Fill fill = { 4, 6, &ImageGlyphVertex::Format, 0, 0, 0 };
#endif
    const TextImageEnt& ent = Entries[layer.Start].EntryData.ImageData;
    Image* img = ent.pImage;

    // the image's coordinate-to-UV mapping (size, scale and sub-image offset)
    Matrix2F uv(Matrix2F::NoInit);
    img->GetUVNormMatrix(&uv, pCache->GetTextureManager());

    RectF tex(0, 0, 1, 1);
    uv.Transform(&tex.x1, &tex.y1);
    uv.Transform(&tex.x2, &tex.y2);

    float x0 = ent.Coord[0];
    float y0 = ent.Coord[1];
    RectF chr(0, 0, ent.Coord[2] - x0, ent.Coord[3] - y0);
    uv.Transform(&chr.x1, &chr.y1);
    uv.Transform(&chr.x2, &chr.y2);
    chr += PointF(x0, y0);

    clipGlyphRect(chr, tex);

    ver[0].Set(chr.x1, chr.y1, tex.x1, tex.y1);
    ver[1].Set(chr.x2, chr.y1, tex.x2, tex.y1);
    ver[2].Set(chr.x2, chr.y2, tex.x2, tex.y2);
    ver[3].Set(chr.x1, chr.y2, tex.x1, tex.y2);

    if (!verOut->BeginOutput(&fill, 1, Matrix2F::Identity))
        return false;
    verOut->SetVertices(0, 0, ver, 4);
    verOut->SetIndices(0, 0, idx, 6);
    verOut->EndOutput();
    return true;
}

// @0x1426e6960
bool TextMeshProvider::generateMask(VertexOutput* verOut, const TextMeshLayer& layer)
{
    // a quad over nearly the whole 16-bit range, mapped onto the mask rectangle by the vertex matrix
    const MaskEnt& e = Entries[layer.Start].EntryData.MaskData;
    SInt16 c[4] = { -32768 + 4, -32768 + 4, 32768 - 4, 32768 - 4 };

    Matrix2F m;
    m.SetRectToRect(c[0], c[1], c[2], c[3], e.Coord[0], e.Coord[1], e.Coord[2], e.Coord[3]);

    VertexXY16i ver[4];
    ver[0].x = c[0]; ver[0].y = c[1];
    ver[1].x = c[2]; ver[1].y = c[1];
    ver[2].x = c[2]; ver[2].y = c[3];
    ver[3].x = c[0]; ver[3].y = c[3];
    UInt16 idx[6] = { 0, 1, 2, 0, 2, 3 };

#ifdef __clang__
    // clang folds the initializer into .rdata: set the exe global's address at run time instead
    VertexOutput::Fill fill = { 4, 6, 0, 0, 0, 0 };
    fill.pFormat = &VertexXY16i::Format;
#else
    VertexOutput::Fill fill = { 4, 6, &VertexXY16i::Format, 0, 0, 0 };
#endif
    if (!verOut->BeginOutput(&fill, 1, m))
        return false;
    verOut->SetVertices(0, 0, ver, 4);
    verOut->SetIndices(0, 0, idx, 6);
    verOut->EndOutput();
    return true;
}

// @0x1426e8840
void TextMeshProvider::setMeshData(TessBase* tess, VertexOutput* verOut, const UInt32* colors, VertexCountType& verCount)
{
    // vertices and triangles leave the tessellator in chunks of 64
    enum { Chunk = 64 };
    TessVertex      src[Chunk];
    VertexXY16iCF32 dst[Chunk];
    UInt16          tri[Chunk * 3];

    TessMesh mesh;
    tess->GetMesh(0, &mesh);

    unsigned n;
    while ((n = tess->GetVertices(&mesh, src, Chunk)) != 0)
    {
        for (unsigned i = 0; i < n; ++i)
        {
            const TessVertex& t = src[i];
            VertexXY16iCF32&  v = dst[i];
            v.x = (SInt16)floorf(t.x < 0 ? t.x - 0.5f : t.x + 0.5f);
            v.y = (SInt16)floorf(t.y < 0 ? t.y - 0.5f : t.y + 0.5f);
            if (t.Flags & TessStyleMixColors)
                v.Color = ((colors[t.Styles[0] - 1] | colors[t.Styles[1] - 1]) >> 1) & 0x7F7F7F7F;
            else
                v.Color = colors[t.Styles[(t.Flags & TessStyleUseColor2) ? 1 : 0] - 1];
            v.Factors[0] = Factors[t.Flags & 3];
            v.Factors[1] = Factors[(t.Flags >> 2) & 3];
        }
        verOut->SetVertices(0, verCount.VStart, dst, n);
        verCount.VStart += n;
    }

    unsigned triCount = tess->GetMeshTriangleCount(0);
    for (unsigned start = 0; start < triCount;)
    {
        unsigned num = Chunk;
        if (start + num > triCount)
        {
            num = triCount - start;
            if (num == 0)
                break;
        }
        tess->GetTrianglesI16(0, tri, start, num);
        verOut->SetIndices(0, verCount.IStart * 3, tri, num * 3);
        verCount.IStart += num;
        start += num;
    }
}

// The quads of a run of glyphs packed into font textures: alpha glyphs carry the text colour, colour glyphs (any other
// texture format) only their texture coordinates. The first glyph's texture decides for the whole layer.
// @0x1426e6c90
bool TextMeshProvider::generatePackedMesh(VertexOutput* verOut, const TextMeshLayer& layer)
{
    enum { GlyphChunkSize = 64 };

    RasterGlyphVertex verA8[GlyphChunkSize * 4];
    ImageGlyphVertex  verC32[GlyphChunkSize * 4];
    UInt16            indices[GlyphChunkSize * 6];

    unsigned totalGlyphs = layer.Count;
#ifdef __clang__
    // clang folds the initializer into .rdata: set the exe globals' addresses at run time instead
    VertexOutput::Fill fillA8  = { 4 * totalGlyphs, 6 * totalGlyphs, 0, 0, 0, 0 };
    VertexOutput::Fill fillC32 = { 4 * totalGlyphs, 6 * totalGlyphs, 0, 0, 0, 0 };
    fillA8.pFormat  = &RasterGlyphVertex::Format;
    fillC32.pFormat = &ImageGlyphVertex::Format;
#else
    VertexOutput::Fill fillA8  = { 4 * totalGlyphs, 6 * totalGlyphs, &RasterGlyphVertex::Format, 0, 0, 0 };
    VertexOutput::Fill fillC32 = { 4 * totalGlyphs, 6 * totalGlyphs, &ImageGlyphVertex::Format, 0, 0, 0 };
#endif

    bool a8 = Entries[layer.Start].EntryData.PackedData.pGlyph->pImage->GetFormat() == Image_A8;

    if (!verOut->BeginOutput(a8 ? &fillA8 : &fillC32, 1, Matrix2F::Identity))
        return false;

    unsigned glyphCount  = 0;
    unsigned glyphOffset = 0;
    for (unsigned i = 0; i < totalGlyphs; ++i)
    {
        if (glyphCount >= GlyphChunkSize)
        {
            verOut->SetVertices(0, glyphOffset * 4, a8 ? (void*)verA8 : (void*)verC32, GlyphChunkSize * 4);
            verOut->SetIndices(0, glyphOffset * 6, indices, GlyphChunkSize * 6);
            glyphCount = 0;
            glyphOffset += GlyphChunkSize;
        }
        const TextMeshEntry&   ent = Entries[i + layer.Start];
        const GlyphTextureEnt& pak = ent.EntryData.PackedData;
        RectF                  tex = pak.pGlyph->UvBounds;
        UInt32                 c   = ent.mColor;

        unsigned verIdx = glyphCount * 4;
        unsigned indIdx = glyphCount * 6;
        unsigned idx    = i * 4;
        RectF    chr(pak.Coord[0], pak.Coord[1], pak.Coord[2], pak.Coord[3]);

        clipGlyphRect(chr, tex);

        if (a8)
        {
            verA8[verIdx + 0].Set(chr.x1, chr.y1, tex.x1, tex.y1, c);
            verA8[verIdx + 1].Set(chr.x2, chr.y1, tex.x2, tex.y1, c);
            verA8[verIdx + 2].Set(chr.x2, chr.y2, tex.x2, tex.y2, c);
            verA8[verIdx + 3].Set(chr.x1, chr.y2, tex.x1, tex.y2, c);
        }
        else
        {
            verC32[verIdx + 0].Set(chr.x1, chr.y1, tex.x1, tex.y1);
            verC32[verIdx + 1].Set(chr.x2, chr.y1, tex.x2, tex.y1);
            verC32[verIdx + 2].Set(chr.x2, chr.y2, tex.x2, tex.y2);
            verC32[verIdx + 3].Set(chr.x1, chr.y2, tex.x1, tex.y2);
        }
        indices[indIdx + 0] = UInt16(idx + 0);
        indices[indIdx + 1] = UInt16(idx + 1);
        indices[indIdx + 2] = UInt16(idx + 2);
        indices[indIdx + 3] = UInt16(idx + 2);
        indices[indIdx + 4] = UInt16(idx + 3);
        indices[indIdx + 5] = UInt16(idx + 0);
        ++glyphCount;
    }

    if (glyphCount)
    {
        verOut->SetVertices(0, glyphOffset * 4, a8 ? (void*)verA8 : (void*)verC32, glyphCount * 4);
        verOut->SetIndices(0, glyphOffset * 6, indices, glyphCount * 6);
    }
    else
        generateNullVectorMesh(verOut);

    verOut->EndOutput();
    return true;
}

// The quads of a run of rasterized glyphs, out of the glyph cache texture; the cache keeps a one texel border around
// every glyph, left out of the texture rectangle here. Quads leave in chunks of 64.
// @0x1426e7110
bool TextMeshProvider::generateRasterMesh(VertexOutput* verOut, const TextMeshLayer& layer)
{
    enum { GlyphChunkSize = 64 };

    RasterGlyphVertex vertices[GlyphChunkSize * 4];
    UInt16            indices[GlyphChunkSize * 6];

    unsigned totalGlyphs = layer.Count;
#ifdef __clang__
    // clang folds the initializer into .rdata: set the exe global's address at run time instead
    VertexOutput::Fill fill = { 4 * totalGlyphs, 6 * totalGlyphs, 0, 0, 0, 0 };
    fill.pFormat = &RasterGlyphVertex::Format;
#else
    VertexOutput::Fill fill = { 4 * totalGlyphs, 6 * totalGlyphs, &RasterGlyphVertex::Format, 0, 0, 0 };
#endif
    float scaleU = pCache->GetScaleU();
    float scaleV = pCache->GetScaleV();

    if (!verOut->BeginOutput(&fill, 1, Matrix2F::Identity))
        return false;

    unsigned glyphCount  = 0;
    unsigned glyphOffset = 0;
    for (unsigned i = 0; i < totalGlyphs; ++i)
    {
        if (glyphCount >= GlyphChunkSize)
        {
            verOut->SetVertices(0, glyphOffset * 4, vertices, GlyphChunkSize * 4);
            verOut->SetIndices(0, glyphOffset * 6, indices, GlyphChunkSize * 6);
            glyphCount = 0;
            glyphOffset += GlyphChunkSize;
        }
        const TextMeshEntry&  ent = Entries[i + layer.Start];
        const GlyphRasterEnt& ras = ent.EntryData.RasterData;
        const GlyphRect&      r   = ras.pGlyph->mRect;
        UInt32                c   = ent.mColor;

        unsigned verIdx = glyphCount * 4;
        unsigned indIdx = glyphCount * 6;
        unsigned idx    = i * 4;
        RectF    chr(ras.Coord[0], ras.Coord[1], ras.Coord[2], ras.Coord[3]);
        float    texX1 = (r.x + 1) * scaleU;
        float    texY1 = (r.y + 1) * scaleV;
        float    texX2 = texX1 + (r.w - 2) * scaleU;
        float    texY2 = texY1 + (r.h - 2) * scaleV;
        RectF    tex(texX1, texY1, texX2, texY2);

        clipGlyphRect(chr, tex);

        vertices[verIdx + 0].Set(chr.x1, chr.y1, tex.x1, tex.y1, c);
        vertices[verIdx + 1].Set(chr.x2, chr.y1, tex.x2, tex.y1, c);
        vertices[verIdx + 2].Set(chr.x2, chr.y2, tex.x2, tex.y2, c);
        vertices[verIdx + 3].Set(chr.x1, chr.y2, tex.x1, tex.y2, c);
        indices[indIdx + 0] = UInt16(idx + 0);
        indices[indIdx + 1] = UInt16(idx + 1);
        indices[indIdx + 2] = UInt16(idx + 2);
        indices[indIdx + 3] = UInt16(idx + 2);
        indices[indIdx + 4] = UInt16(idx + 3);
        indices[indIdx + 5] = UInt16(idx + 0);
        ++glyphCount;
    }

    if (!glyphCount)
        return generateNullVectorMesh(verOut);

    verOut->SetVertices(0, glyphOffset * 4, vertices, glyphCount * 4);
    verOut->SetIndices(0, glyphOffset * 6, indices, glyphCount * 6);
    verOut->EndOutput();
    return true;
}

// MS2-FUNCTIONAL: generateNullVectorMesh inlined (exe calls it), regalloc
// @0x1426e74d0
bool TextMeshProvider::generateRectangle(Renderer2DImpl* ren, VertexOutput* verOut, const Matrix2F& mtx,
                                         const float* coord, UInt32 fillColor, UInt32 borderColor,
                                         unsigned meshGenFlags)
{
    UInt32         colors[2] = { fillColor, borderColor };
    MeshGenerator* gen       = ren->GetMeshGen();
    gen->Clear();
    gen->mTess.SetFillRule(Tessellator::FillNonZero);
    gen->mTess.SetToleranceParam(ren->GetToleranceParams());
    const ToleranceParams tol = ren->GetToleranceParams();
    bool edgeAA = (meshGenFlags & (Mesh_EdgeAA | Mesh_Mask)) == Mesh_EdgeAA;
    gen->mTess.SetEdgeAAWidth(edgeAA ? tol.EdgeAAScale * 0.5f : 0.0f);

    // the corners clockwise from the top left, in screen space
    float c[8] = { coord[0], coord[1], coord[2], coord[1], coord[2], coord[3], coord[0], coord[3] };
    mtx.Transform(c + 0, c + 1);
    mtx.Transform(c + 2, c + 3);
    mtx.Transform(c + 4, c + 5);
    mtx.Transform(c + 6, c + 7);

    if (fillColor)
    {
        gen->mTess.AddVertex(c[0], c[1]);
        gen->mTess.AddVertex(c[2], c[3]);
        gen->mTess.AddVertex(c[4], c[5]);
        gen->mTess.AddVertex(c[6], c[7]);
        gen->mTess.ClosePath();
        gen->mTess.FinalizePath(0, 1, false, false);
    }
    if (borderColor)
    {
        // a one pixel frame: the rectangle and its outset
        gen->mTess.AddVertex(c[0], c[1]);
        gen->mTess.AddVertex(c[2], c[3]);
        gen->mTess.AddVertex(c[4], c[5]);
        gen->mTess.AddVertex(c[6], c[7]);
        gen->mTess.ClosePath();
        gen->mTess.FinalizePath(0, 2, false, false);

        CornerVertex p0(c[0], c[1]), p1(c[2], c[3]), p2(c[4], c[5]), p3(c[6], c[7]);
        float y, x;
        calcMiter(p1, p0, p3, 1, &x, &y);
        gen->mTess.AddVertex(x, y);
        calcMiter(p0, p3, p2, 1, &x, &y);
        gen->mTess.AddVertex(x, y);
        calcMiter(p3, p2, p1, 1, &x, &y);
        gen->mTess.AddVertex(x, y);
        calcMiter(p2, p1, p0, 1, &x, &y);
        gen->mTess.AddVertex(x, y);
        gen->mTess.ClosePath();
        gen->mTess.FinalizePath(0, 2, false, false);
    }

    gen->mTess.Tessellate(false);
    gen->mTess.Transform(mtx.GetInverse());
    Matrix2F toMesh = gen->mTess.StretchTo(-32768 + 4, -32768 + 4, 32768 - 4, 32768 - 4);

    VertexOutput::Fill fill = { gen->mTess.GetMeshVertexCount(0), gen->mTess.GetMeshTriangleCount(0) * 3,
                                &VertexXY16iCF32::Format, 0, 0, 0, 0 };
    if (fill.VertexCount == 0)
        return generateNullVectorMesh(verOut);

    bool ok = verOut->BeginOutput(&fill, 1, toMesh);
    if (ok)
    {
        VertexCountType count;
        setMeshData(&gen->mTess, verOut, colors, count);
        verOut->EndOutput();
    }
    gen->Clear();
    return ok;
}

// MS2-FUNCTIONAL: frame 0x10 smaller than the exe (unused stack slot), code otherwise identical
// @0x1426e7a60
bool TextMeshProvider::generateSelection(Renderer2DImpl* ren, VertexOutput* verOut, const TextMeshLayer& layer,
                                         const Matrix2F& mtx, unsigned meshGenFlags)
{
    MeshGenerator* gen = ren->GetMeshGen();
    gen->Clear();
    gen->mTess.SetFillRule(Tessellator::FillNonZero);
    gen->mTess.SetToleranceParam(ren->GetToleranceParams());

    // one style per selection rectangle, its colour at style - 1
    ArrayStaticBuffPOD<UInt32, 16> colors(Memory::GetGlobalHeap());

    const ToleranceParams tol = ren->GetToleranceParams();
    bool edgeAA = (meshGenFlags & (Mesh_EdgeAA | Mesh_Mask)) == Mesh_EdgeAA;
    gen->mTess.SetEdgeAAWidth(edgeAA ? tol.EdgeAAScale * 0.5f : 0.0f);

    float x, y;
    for (unsigned i = 0; i < layer.Count; ++i)
    {
        const TextMeshEntry& e   = Entries[layer.Start + i];
        const SelectionEnt&  sel = e.EntryData.SelectionData;
        RectF r(sel.Coord[0], sel.Coord[1], sel.Coord[2], sel.Coord[3]);
        if (Flags & BF_Clip)
            r.Intersect(ClipBox);
        if (!r.IsEmpty())
        {
            x = r.x1; y = r.y1; mtx.Transform(&x, &y); gen->mTess.AddVertex(x, y);
            x = r.x2; y = r.y1; mtx.Transform(&x, &y); gen->mTess.AddVertex(x, y);
            x = r.x2; y = r.y2; mtx.Transform(&x, &y); gen->mTess.AddVertex(x, y);
            x = r.x1; y = r.y2; mtx.Transform(&x, &y); gen->mTess.AddVertex(x, y);
        }
        colors.PushBack(e.mColor);
        gen->mTess.ClosePath();
        gen->mTess.FinalizePath(0, i + 1, false, false);
    }
    gen->mTess.Tessellate(false);

    bool ok = true;
    if (gen->mTess.GetMeshCount() && gen->mTess.GetVertexCount())
    {
        gen->mTess.Transform(mtx.GetInverse());
        Matrix2F toMesh = gen->mTess.StretchTo(-32768 + 4, -32768 + 4, 32768 - 4, 32768 - 4);

        VertexOutput::Fill fill = { gen->mTess.GetMeshVertexCount(0), gen->mTess.GetMeshTriangleCount(0) * 3,
                                    &VertexXY16iCF32::Format, 0, 0, 0, 0 };
        ok = verOut->BeginOutput(&fill, 1, toMesh);
        if (ok)
        {
            VertexCountType count;
            setMeshData(&gen->mTess, verOut, &colors[0], count);
            verOut->EndOutput();
        }
    }
    else
        ok = generateNullVectorMesh(verOut);

    gen->Clear();
    return ok;
}

// MS2-FUNCTIONAL: register allocation (verOut/mtx and the hoisted constants take other registers), code otherwise the same
// @0x1426e7ff0
bool TextMeshProvider::generateUnderlines(Renderer2DImpl* ren, VertexOutput* verOut, const TextMeshLayer& layer,
                                          const Matrix2F& mtx, unsigned meshGenFlags)
{
    // one style per underline, its colour at style - 1
    ArrayStaticBuffPOD<UInt32, 16> colors(Memory::GetGlobalHeap());

    MeshGenerator* gen = ren->GetMeshGen();
    gen->Clear();

    // underlines are stroked unclosed polylines with flat ends, solid in the middle and anti-aliased at the edges
    unsigned   aaMode   = meshGenFlags & (Mesh_EdgeAA | Mesh_Mask);
    StrokerAA& strokeAA = ren->GetMeshGen()->mStrokerAA;
    strokeAA.SetStartLineCap(StrokerTypes::ButtCap);
    strokeAA.SetEndLineCap(StrokerTypes::ButtCap);
    strokeAA.SetLineJoin(StrokerTypes::MiterJoin);
    float solid, edgeAA;
    if (aaMode == Mesh_EdgeAA)
    {
        edgeAA = 0.96f;
        solid  = 0.0f;
    }
    else
    {
        solid  = 0.5f;
        edgeAA = 0.0f;
    }
    strokeAA.SetSolidWidth(solid);
    strokeAA.SetEdgeAAWidth(edgeAA);

    for (unsigned i = 0; i < layer.Count; ++i)
    {
        const TextMeshEntry& e = Entries[layer.Start + i];
        const UnderlineEnt&  u = e.EntryData.UnderlineData;
        if (aaMode == Mesh_EdgeAA)
        {
            strokeAA.SetSolidWidth(u.Style == TextUnderline_Thick || u.Style == TextUnderline_DottedThick ? 1.0f : 0.0f);
            if (u.Style == TextUnderline_DitheredThick)
                strokeAA.SetSolidWidth(0.25f);
            strokeAA.SetEdgeAAWidth(u.Style == TextUnderline_Dithered ? 0.5f : 0.96f);
        }
        else
        {
            strokeAA.SetSolidWidth(u.Style == TextUnderline_Thick || u.Style == TextUnderline_DottedThick ? 1.0f : 0.5f);
            if (u.Style == TextUnderline_DitheredThick)
                strokeAA.SetSolidWidth(0.75f);
            strokeAA.SetEdgeAAWidth(0.0f);
        }
        strokeAA.SetStyleLeft(i + 1);
        strokeAA.SetStyleRight(i + 1);
        colors.PushBack(e.mColor);

        float x1 = u.x * mtx.M[0][0] + u.y * mtx.M[0][1] + mtx.M[0][3];
        float y1 = u.x * mtx.M[1][0] + u.y * mtx.M[1][1] + mtx.M[1][3];
        float x2 = (u.x + u.Len) * mtx.M[0][0] + u.y * mtx.M[0][1] + mtx.M[0][3];
        float y2 = (u.x + u.Len) * mtx.M[1][0] + u.y * mtx.M[1][1] + mtx.M[1][3];

        if (u.Style == TextUnderline_Single || u.Style == TextUnderline_Thick)
        {
            // on the middle of a pixel row
            strokeAA.AddVertex(x1, floorf(y1) + 0.5f);
            strokeAA.AddVertex(x2, floorf(y2) + 0.5f);
            strokeAA.FinalizePath(0, 0, false, false);
        }
        if (u.Style == TextUnderline_Dotted || u.Style == TextUnderline_DottedThick)
        {
            // two pixel dots five pixels apart, each its own path
            x1 = (float)(floor(x1) - 0.5);
            x2 = (float)(floor(x2) + 0.5);
            y1 = (float)(floor(y1) + 0.5);
            y2 = (float)(floor(y2) + 0.5);
            if (x1 <= x2)
            {
                float ya = floorf(y1) + 0.5f;
                float yb = floorf(y2) + 0.5f;
                float x  = x1;
                do
                {
                    strokeAA.AddVertex(x, ya);
                    strokeAA.AddVertex(x + 2.0f, yb);
                    strokeAA.FinalizePath(0, 0, false, false);
                    x += 5.0f;
                } while (x <= x2);
            }
        }
        if (u.Style == TextUnderline_Dithered || u.Style == TextUnderline_DitheredThick)
        {
            // a zigzag of one path across the row
            x1 = (float)floor(x1);
            x2 = (float)(floor(x2) + 1.0);
            y1 = (float)(floor(y1) + 0.5);
            y2 = (float)(floor(y2) + 0.5);
            float step = 4.0f, half = 0.75f;
            if (u.Style == TextUnderline_DitheredThick)
            {
                step = 6.0f;
                half = 1.25f;
            }
            if (x1 <= x2)
            {
                float ya  = floorf(y1) + half;
                float yb  = floorf(y2) - half;
                float seg = step * 0.5f;
                float x   = x1;
                do
                {
                    strokeAA.AddVertex(x, ya);
                    strokeAA.AddVertex(x + seg, yb);
                    x += step;
                } while (x <= x2);
            }
            strokeAA.FinalizePath(0, 0, false, false);
        }
    }

    if (strokeAA.GetVertexCount())
    {
        strokeAA.Transform(mtx.GetInverse());
        Matrix2F toMesh = strokeAA.StretchTo(-32768 + 4, -32768 + 4, 32768 - 4, 32768 - 4);

        VertexOutput::Fill fill = { strokeAA.GetMeshVertexCount(0), strokeAA.GetMeshTriangleCount(0) * 3,
                                    &VertexXY16iCF32::Format, 0, 0, 0, 0 };
        if (verOut->BeginOutput(&fill, 1, toMesh))
        {
            VertexCountType count;
            setMeshData(&strokeAA, verOut, &colors[0], count);
            verOut->EndOutput();
        }
    }
    else
        generateNullVectorMesh(verOut);

    strokeAA.SetStyleLeft(1);
    strokeAA.SetStyleRight(1);
    gen->Clear();
    return true;
}

// @0x1426e6ad0
bool TextMeshProvider::generateNullVectorMesh(VertexOutput* verOut)
{
    // a single degenerate triangle on one zero vertex
    VertexXY16iCF32 ver[1];
    UInt16          tri[3];
    ver[0].x = 0;
    ver[0].y = 0;
    ver[0].Color = 0;
    ver[0].Factors[0] = 0;
    ver[0].Factors[1] = 0;
    tri[0] = tri[1] = tri[2] = 0;
    VertexOutput::Fill fill;
    fill.VertexCount = 1;
    fill.IndexCount  = 3;
    fill.pFormat     = &VertexXY16iCF32::Format;
    fill.FillIndex0  = 0;
    fill.FillIndex1  = 0;
    fill.MergeFlags  = 0;
    fill.MeshIndex   = 0;
    if (!verOut->BeginOutput(&fill, 1, Matrix2F::Identity))
        return false;
    verOut->SetVertices(0, 0, ver, 1);
    verOut->SetIndices(0, 0, tri, 3);
    verOut->EndOutput();
    return true;
}

// @0x1426e6bb0
bool VectorGlyphShape::generateNullVectorMesh(VertexOutput* verOut)
{
    // a single degenerate triangle on one zero vertex
    VertexXY16iCF32 ver[1];
    UInt16          tri[3];
    ver[0].x = 0;
    ver[0].y = 0;
    ver[0].Color = 0;
    ver[0].Factors[0] = 0;
    ver[0].Factors[1] = 0;
    tri[0] = tri[1] = tri[2] = 0;
    VertexOutput::Fill fill;
    fill.VertexCount = 1;
    fill.IndexCount  = 3;
    fill.pFormat     = &VertexXY16iCF32::Format;
    fill.FillIndex0  = 0;
    fill.FillIndex1  = 0;
    fill.MergeFlags  = 0;
    fill.MeshIndex   = 0;
    if (!verOut->BeginOutput(&fill, 1, Matrix2F::Identity))
        return false;
    verOut->SetVertices(0, 0, ver, 1);
    verOut->SetIndices(0, 0, tri, 3);
    verOut->EndOutput();
    return true;
}

// @0x1426e53a0
void TextMeshProvider::addLayer(TmpTextStorage& storage, TextLayerType type, unsigned start, unsigned count)
{
    // a layer draws at most 0x3ffe entries; longer runs are cut into several layers
    do
    {
        unsigned n = (count < 0x3ffe) ? count : 0x3ffe;
        TmpTextMeshLayer layer;
        layer.Type  = type;
        layer.Start = start;
        layer.Count = n;
        layer.pFill = storage.Entries[start].pFill;
        storage.Layers.PushBack(layer);
        count -= n;
        start += n;
    } while (count);
}

// @0x1426e5500
void TextMeshProvider::addLayer(TmpTextStorage& storage, UPInt start, UPInt end)
{
    UInt16 type = storage.Entries[start].LayerType;
    // text right after its shadow with the same fill joins the shadow's layer (the last built mesh layer)
    if (type == TextLayer_RasterText && Layers.GetSize())
    {
        TextMeshLayer& prev = Layers.Back();
        if ((prev.Type == TextLayer_Shadow || prev.Type == TextLayer_ShadowText) &&
            storage.Entries[start].pFill == storage.Entries[prev.Start].pFill)
        {
            prev.Type   = TextLayer_ShadowText;
            prev.Count += unsigned(end - start);
            return;
        }
    }
    if (type == TextLayer_Shapes || type == TextLayer_Shapes_Masked)
    {
        // one layer per vector shape
        for (UPInt i = start; i < end; ++i)
            addLayer(storage, (TextLayerType)storage.Entries[start].LayerType, unsigned(i), 1);
    }
    else if (type == TextLayer_Images)
    {
        // one layer per image
        for (UPInt i = start; i < end; ++i)
            addLayer(storage, TextLayer_Images, unsigned(i), 1);
    }
    else
        addLayer(storage, (TextLayerType)type, unsigned(start), unsigned(end - start));
}

// @0x1426e5660
void TextMeshProvider::addMask(TmpTextStorage& storage)
{
    TmpTextMeshEntry e;
    e.LayerType = TextLayer_Mask;
    e.TextureId = 0;
    e.EntryIdx  = (unsigned)storage.Entries.GetSize();
    e.mColor    = 0;
    e.pFill     = pCache->GetFill(TextLayer_Mask, 0);
    e.pFill->AddRef();
    e.EntryData.MaskData.Coord[0] = ClipBox.x1;
    e.EntryData.MaskData.Coord[1] = ClipBox.y1;
    e.EntryData.MaskData.Coord[2] = ClipBox.x2;
    e.EntryData.MaskData.Coord[3] = ClipBox.y2;
    storage.Entries.PushBack(e);
}

// MS2-FUNCTIONAL: snap test: the exe shifts the font flags (shr 7) and tests each glyph flag from memory; register choice
// @0x1426e56c0
void TextMeshProvider::addRasterGlyph(TmpTextStorage& storage, TextLayerType type, GlyphRunData& data, UInt32 color,
                                      GlyphNode* node, float screenSize, bool snap, float stretch)
{
    // raster-only fonts (font flag 0x80) and readable unstretched glyphs start on a whole pixel
    float x = data.NewLineX;
    const GlyphParam& gp = node->Param;
    if (snap && (((data.pFont->GetFontFlags() >> 7) & 1) != 0 ||
                 ((gp.Flags & GlyphParam::OptRead) != 0 && ((gp.Flags & GlyphParam::Stretch) ? 2.5f : 1.0f) <= 1.0f)))
        x = snapX(data);

    UInt16           textureId = node->pSlot->TextureId & ~GlyphSlot::Mask;
    const GlyphRect& r         = node->mRect;
    if (r.w > 1 && r.h > 1)
    {
        // the glyph image sits one texel in from its slot rectangle; Origin is in 1/16 texels
        RectF rect;
        rect.x1 = float(node->Origin.x) / 16.0f + 1.0f;
        rect.y1 = float(node->Origin.y) / 16.0f + 1.0f;
        rect.x2 = rect.x1 + r.w - 2.0f;
        rect.y2 = rect.y1 + r.h - 2.0f;

        float size = node->Param.GetFontSize();
        if (size < 1e-5f)
            size = 1e-5f;
        float k = (screenSize * node->Scale / size) / data.HeightRatio;
        rect.x1 *= k / stretch;
        rect.y1 *= k;
        rect.x2 *= k / stretch;
        rect.y2 *= k;

        float offsetX = 0, offsetY = 0;
        if (type == TextLayer_Shadow)
        {
            offsetX = data.Param.ShadowOffsetX;
            offsetY = data.Param.ShadowOffsetY;
        }
        rect.x1 += x + offsetX;
        rect.y1 += data.NewLineY + offsetY;
        rect.x2 += x + offsetX;
        rect.y2 += data.NewLineY + offsetY;

        TmpTextMeshEntry e;
        e.LayerType = (UInt16)type;
        e.TextureId = textureId;
        e.EntryIdx  = (unsigned)storage.Entries.GetSize();
        e.mColor    = color;
        e.pFill     = pCache->GetFill(type, textureId);
        e.pFill->AddRef();
        e.EntryData.RasterData.Coord[0] = rect.x1;
        e.EntryData.RasterData.Coord[1] = rect.y1;
        e.EntryData.RasterData.Coord[2] = rect.x2;
        e.EntryData.RasterData.Coord[3] = rect.y2;
        e.EntryData.RasterData.pGlyph   = node;
        storage.Entries.PushBack(e);
    }
}

// @0x1426e5930
void TextMeshProvider::addSelection(TmpTextStorage& storage, UInt32 color, const RectF& rect)
{
    TmpTextMeshEntry e;
    e.LayerType = TextLayer_Selection;
    e.TextureId = 0;
    e.EntryIdx  = (unsigned)storage.Entries.GetSize();
    e.mColor    = color;
    e.pFill     = pCache->GetFill(TextLayer_Selection, 0);
    e.pFill->AddRef();
    e.EntryData.SelectionData.Coord[0] = rect.x1;
    e.EntryData.SelectionData.Coord[1] = rect.y1;
    e.EntryData.SelectionData.Coord[2] = rect.x2;
    e.EntryData.SelectionData.Coord[3] = rect.y2;
    storage.Entries.PushBack(e);
}

// @0x1426e5990
void TextMeshProvider::addTextureGlyph(TmpTextStorage& storage, const TextureGlyph* tgl, GlyphRunData& data, UInt32 color)
{
    float     x = data.NewLineX;
    ImageSize s = tgl->pImage->GetSize();

    // texture coordinates to glyph space: the font's texture glyph height maps to the font size
    float scaleX = data.FontSize / data.TexHeight * s.Width;
    float scaleY = data.FontSize / data.TexHeight * s.Height;

    float x1 = (tgl->UvBounds.x1 - tgl->UvOrigin.x) * scaleX + x;
    float y1 = (tgl->UvBounds.y1 - tgl->UvOrigin.y) * scaleY + data.NewLineY;
    float x2 = (tgl->UvBounds.x2 - tgl->UvOrigin.x) * scaleX + x;
    float y2 = (tgl->UvBounds.y2 - tgl->UvOrigin.y) * scaleY + data.NewLineY;

    TmpTextMeshEntry e;
    e.LayerType = TextLayer_PackedText;
    e.TextureId = 0;
    e.EntryIdx  = (unsigned)storage.Entries.GetSize();
    e.mColor    = color;

    // distance field fonts (font flag 0x10000) get their own layer
    if (data.pFont->GetFontFlags() & 0x10000)
    {
        PrimitiveFillData fd(PrimFill_UVTextureDFAlpha_VColor, &RasterGlyphVertex::Format,
                             tgl->pImage->GetTexture(pCache->GetTextureManager()), ImageFillMode(Wrap_Clamp, Sample_Linear));
        e.pFill     = pCache->GetPrimitiveFillManager()->CreateFill(fd);
        e.LayerType = TextLayer_PackedDFAText;
        Flags |= BF_DistField;
    }
    else if (tgl->pImage->GetFormat() == Image_A8)
    {
        PrimitiveFillData fd(PrimFill_UVTextureAlpha_VColor, &RasterGlyphVertex::Format,
                             tgl->pImage->GetTexture(pCache->GetTextureManager()), ImageFillMode(Wrap_Clamp, Sample_Linear));
        e.pFill = pCache->GetPrimitiveFillManager()->CreateFill(fd);
    }
    else
    {
        PrimitiveFillData fd(PrimFill_UVTexture, &ImageGlyphVertex::Format,
                             tgl->pImage->GetTexture(pCache->GetTextureManager()), ImageFillMode(Wrap_Clamp, Sample_Linear));
        e.pFill = pCache->GetPrimitiveFillManager()->CreateFill(fd);
    }

    e.EntryData.PackedData.Coord[0] = x1;
    e.EntryData.PackedData.Coord[1] = y1;
    e.EntryData.PackedData.Coord[2] = x2;
    e.EntryData.PackedData.Coord[3] = y2;
    e.EntryData.PackedData.pGlyph   = tgl;
    storage.Entries.PushBack(e);
}

// @0x1426e5d10
void TextMeshProvider::addUnderline(TmpTextStorage& storage, UInt32 color, TextUnderlineStyle style, float x, float y,
                                    float len)
{
    TmpTextMeshEntry e;
    e.LayerType = TextLayer_Underline;
    e.TextureId = 0;
    e.EntryIdx  = (unsigned)storage.Entries.GetSize();
    e.mColor    = color;
    e.pFill     = pCache->GetFill(TextLayer_Underline, 0);
    e.pFill->AddRef();
    e.EntryData.UnderlineData.Style = style;
    e.EntryData.UnderlineData.x     = x;
    e.EntryData.UnderlineData.y     = y;
    e.EntryData.UnderlineData.Len   = len;
    storage.Entries.PushBack(e);
}

// @0x1426e5da0
void TextMeshProvider::addVectorGlyph(TmpTextStorage& storage, UInt32 color, FontCacheHandle* font,
                                      UInt16 glyphIndex, UInt16 flags, float fontSize, float x, float y)
{
    TmpTextMeshEntry e;
    e.LayerType = TextLayer_Shapes;
    e.TextureId = 0;
    e.EntryIdx  = (unsigned)storage.Entries.GetSize();
    e.mColor    = color;
    e.pFill     = pCache->GetFill(TextLayer_Shapes, 0);
    e.pFill->AddRef();
    font->pFont->AddRef();
    e.EntryData.VectorData.pFont = font->pFont;
    e.EntryData.VectorData.GlyphIndex = glyphIndex;
    e.EntryData.VectorData.Flags      = flags;
    e.EntryData.VectorData.FontSize   = fontSize;
    e.EntryData.VectorData.x          = x;
    e.EntryData.VectorData.y          = y;
    storage.Entries.PushBack(e);
}

// the larger of the two axis scales
static inline float maxAxisScale(const Matrix2F& m)
{
    return sqrtf(Alg::Max(m.Sx() * m.Sx() + m.Shy() * m.Shy(), m.Shx() * m.Shx() + m.Sy() * m.Sy()));
}

// @0x1426e5e50
float TextMeshProvider::calcHeightRatio(const HMatrix& m, const Matrix4F& m4, const Viewport& vp)
{
    Matrix2F mtx = m.GetMatrix2D();
    if (m.Has3D())
    {
        RectF unit(0, 0, 1, 1);
        float corners[8];
        m4.TransformHomogeneousAndScaleCorners(unit, (float)vp.Width, (float)vp.Height, corners);
        mtx.SetRectToParl(0, 0, 1, 1, corners);
        float r = maxAxisScale(mtx);
        return (r < 1e-5f) ? 1e-5f : r;
    }

    // the height of the unit square's image: distance of the y axis tip from the x axis
    float x0 = 0, y0 = 1;
    float x1 = 1, y1 = 0;
    mtx.Transform2x2(&x0, &y0);
    mtx.Transform2x2(&x1, &y1);
    float r = (float)fabs(Math2D::LinePointDistance(0, 0, x1, y1, x0, y0));
    return (r < 1e-8f) ? 1e-8f : r;
}

// MS2-FUNCTIONAL: register allocation (the exe keeps the glyph rect in xmm8/13/10/7 and its clipped copy in xmm12/4/5/2)
// @0x1426e6100
bool TextMeshProvider::clipGlyphRect(RectF& chr, RectF& tex) const
{
    if (Flags & BF_Clip)
    {
        RectF c(chr);
        c.Intersect(ClipBox);
        if (c.IsEmpty())
        {
            // clipped away: collapse both to a point
            chr = ClipBox;
            chr.x2 = chr.x1;
            chr.y2 = chr.y1;
            tex.x2 = tex.x1;
            tex.y2 = tex.y1;
            return false;
        }
        if (c.x1 != chr.x1 || c.x2 != chr.x2 || c.y1 != chr.y1 || c.y2 != chr.y2)
        {
            // move the texture edges by the share of the glyph cut off
            RectF t(tex);
            if (chr.x1 != c.x1)
                t.x1 = tex.x1 + tex.Width() * (c.x1 - chr.x1) / chr.Width();
            if (chr.y1 != c.y1)
                t.y1 = tex.y1 + tex.Height() * (c.y1 - chr.y1) / chr.Height();
            if (chr.x2 != c.x2)
                t.x2 = tex.x2 - tex.Width() * (chr.x2 - c.x2) / chr.Width();
            if (chr.y2 != c.y2)
                t.y2 = tex.y2 - tex.Height() * (chr.y2 - c.y2) / chr.Height();
            chr = c;
            tex = t;
        }
    }
    return true;
}

// @0x1426e8aa0
float TextMeshProvider::snapX(const GlyphRunData& data) const
{
    float x = data.NewLineX, y = data.NewLineY;
    data.DirMtx.Transform(&x, &y);
    x = floorf(x + 0.5f);
    data.InvMtx.Transform(&x, &y);
    return x;
}

// @0x1426e8b40
float TextMeshProvider::snapY(const GlyphRunData& data) const
{
    float x = data.NewLineX, y = data.NewLineY;
    data.DirMtx.Transform(&x, &y);
    y = floorf(y + 0.5f);
    data.InvMtx.Transform(&x, &y);
    return y;
}

// Sorts the collected entries (by kind, then fill), groups them into layers and moves both into the provider's
// arrays; the fills move with their reference.
// @0x1426e8be0
void TextMeshProvider::sortEntries(TmpTextStorage& storage)
{
    storage.Layers.Clear();

    CmpEntries cmp(pCache);
    ArrayPaged<TmpTextMeshEntry, 6, 4>& arr = storage.Entries;
    Alg::QuickSortSliced(arr, 0, arr.GetSize(), cmp);

    UPInt start = 0;
    UPInt end   = 0;
    for (; end < storage.Entries.GetSize(); ++end)
    {
        if (storage.Entries[start].LayerType != storage.Entries[end].LayerType ||
            storage.Entries[start].pFill != storage.Entries[end].pFill)
        {
            if (end > start)
            {
                addLayer(storage, start, end);
                start = end;
            }
        }
    }
    if (end > start)
        addLayer(storage, start, end);

    Entries.Resize(storage.Entries.GetSize());
    Layers.Resize(storage.Layers.GetSize());
    UPInt i;
    for (i = 0; i < storage.Entries.GetSize(); ++i)
    {
        const TmpTextMeshEntry& e1 = storage.Entries[i];
        TextMeshEntry&          e2 = Entries[i];
        e2.LayerType = e1.LayerType;
        e2.TextureId = e1.TextureId;
        e2.mColor    = e1.mColor;
        e2.pFill     = *e1.pFill;
        e2.EntryData = e1.EntryData;
    }

    for (i = 0; i < storage.Layers.GetSize(); ++i)
    {
        const TmpTextMeshLayer& l1 = storage.Layers[i];
        TextMeshLayer&          l2 = Layers[i];
        l2.Type      = l1.Type;
        l2.Start     = l1.Start;
        l2.Count     = l1.Count;
        l2.pMesh     = 0;
        l2.M         = HMatrix();
        l2.pFill     = l1.pFill;
        l2.SizeScale = 1;
    }
}

}} // namespace Scaleform::Render

namespace Scaleform {
// @0x1426e4410
template void ArrayDataBase<Render::TextMeshEntry, AllocatorDH<Render::TextMeshEntry, 2>, ArrayDefaultPolicy>::Reserve(
    const void*, UPInt);
// @0x1426e44b0
template void ArrayDataBase<Render::TextMeshLayer, AllocatorDH<Render::TextMeshLayer, 2>, ArrayDefaultPolicy>::Reserve(
    const void*, UPInt);
} // namespace Scaleform
