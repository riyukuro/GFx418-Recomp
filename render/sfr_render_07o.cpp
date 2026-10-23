// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the text mesh provider TU
// (Render_TextMeshProvider): TextMeshProvider collects the entries of a text layout (glyphs, backgrounds,
// selections, underlines, images, the mask), sorts them into layers of one kind and fill, and tessellates a layer
// when the mesh cache asks for it; VectorGlyphShape is the shared mesh provider of one vector glyph.
// MS2-UNIT: sfr_render_07o
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426e1210-0x1426e8fc0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_textmeshprovider.h"
#include "ms2/scaleform/include/render/render_renderer2d.h"
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

// vertex of the alpha (raster, packed and distance field) glyph quads: position, texture coordinates, colour
struct RasterGlyphVertex
{
    static VertexFormat Format;   // 0x143a2fe50
};

// a glyph packed into a font texture; only its image is read here (+0x10, after the refcount base)
class TextureGlyph : public RefCountBase<TextureGlyph, Stat_Default_Mem>
{
public:
    Ptr<Image> pImage;            // +0x10
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

}} // namespace Scaleform::Render
