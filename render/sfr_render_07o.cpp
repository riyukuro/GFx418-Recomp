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
#include <math.h>

namespace Scaleform { namespace Render {

// MS2-PIN: ??_7TextMeshProvider@Render@Scaleform@@6B@ 0x143193f50

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
