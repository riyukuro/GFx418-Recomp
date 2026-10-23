// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the glyph cache TU
// (Render_GlyphCache). The cache rasterizes glyphs (hinted or auto-fitted, faux bold / italic, outlined, blurred or
// knocked-out shadows) into a pool of A8 textures packed by its GlyphQueue, writes them through the texture mapping
// method the device supports (direct map, partial updates through a staging image, or a whole raw image), keeps
// the shared vector glyph shapes keyed by font / glyph / style, and hands the text mesh providers their fills.
// Queue unit sfr_render_06 is split along its original sources (06d Render_GlyphCache); the flattened path's
// out-of-line members (Render_VertexPath, just ahead of it) live here too, the cache's scratch paths emit its vtable.
// MS2-UNIT: sfr_render_06d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426c21b0-0x1426c51f0 .text$mn
// MS2-RANGE: 0x1426c5280-0x1426cba30 .text$mn
// The glyph rasters' refcount bases (non-RTTI, one slot each):
// MS2-PIN: ??_7?$RefCountBaseNTS@VGlyphRaster@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143192d98
// MS2-PIN: ??_G?$RefCountBaseNTS@VGlyphRaster@Render@Scaleform@@$0EO@@Scaleform@@UEAAPEAXI@Z 0x1426c4930
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@UEAAPEAXI@Z 0x1426c48d0

#include "ms2/scaleform/include/render/render_tessgen.h" // first: StrokeGenerator is a struct here, as 07o mangles it
#include "ms2/scaleform/include/render/render_glyphcache.h"
#include "ms2/scaleform/include/render/render_boundbox.h"
#include "ms2/scaleform/include/render/render_hal.h"
#include "ms2/scaleform/include/render/render_imagefile.h"
#include "ms2/scaleform/include/render/render_resizeimage.h"

#include <string.h>
#include <math.h>

namespace Scaleform { namespace Render {

// ---- VertexPath (Render_VertexPath) ----

// @0x1426c21b0
void VertexPath::AddVertex(CoordType x, CoordType y)
{
    VertexBasic v = { x, y };
    Vertices.PushBack(v);
}

// @0x1426c21e0
void VertexPath::Clear()
{
    Vertices.ClearAndRelease();
    Paths.ClearAndRelease();
    LastVertex = 0;
}

// repeats the contour's first vertex unless the contour already ends on it (or is too short to close)
// @0x1426c2210
void VertexPath::ClosePath()
{
    if (Vertices.GetSize() - LastVertex > 2 &&
        (Vertices[LastVertex].x != Vertices.Back().x || Vertices[LastVertex].y != Vertices.Back().y))
        Vertices.PushBack(Vertices[LastVertex]);
}

// a contour of fewer than three vertices is dropped, otherwise it becomes a path
// @0x1426c2280
void VertexPath::FinalizePath(unsigned, unsigned, bool, bool)
{
    if (Vertices.GetSize() - LastVertex < 3)
        Vertices.CutAt(LastVertex);
    else
    {
        PathBasic p = { LastVertex, (unsigned)Vertices.GetSize() - LastVertex };
        Paths.PushBack(p);
        LastVertex = (unsigned)Vertices.GetSize();
    }
}

// the render channel's error / warning ids the cache logs with
enum { GlyphCacheLog_Error = LogChannel_Render | LogMessage_Error, GlyphCacheLog_Warning = LogChannel_Render | LogMessage_Warning };

// glyph heights the cache snaps to; FontSizeMap maps a pixel size to the step it rounds up to
static unsigned FontSizeRamp[] = { 0, 0, 2, 4, 6, 8, 12, 16, 18, 22, 26, 32, 36, 40, 45, 50, 56, 64, 72, 80, 90, 108,
                                   128, 147, 168, 194, 222, 256, 0 };   // 0x143a2fe70

// RasterGlyphVertex::Format (0x143a2fe50) stays the exe's

//--------------------------------------------------------------------------------------------------------------------
// GlyphTextureImage / GlyphTextureMapper

// MS2-FUNCTIONAL: the exe inlines TextureImage's ctor here, ours calls its out-of-line copy (0x1425792d0)
// @0x1426c41a0
GlyphTextureImage::GlyphTextureImage(GlyphCache* cache, unsigned textureId, const ImageSize& size, unsigned use)
    : TextureImage(Image_A8, size, use), pCache(cache), TextureId(textureId)
{
}

// @0x1426c5280
GlyphTextureImage* GlyphTextureImage::Create(MemoryHeap* heap, TextureManager* texMan, GlyphCache* cache,
                                             unsigned textureId, const ImageSize& size, unsigned use)
{
    GlyphTextureImage* image = SF_HEAP_NEW(heap) GlyphTextureImage(cache, textureId, size, use);
    Texture* texture = texMan->CreateTexture(Image_A8, 1, size, use, image);
    if (!texture)
    {
        image->Release();
        return 0;
    }
    image->initTexture_NoAddRef(texture);
    return image;
}

// the image lets its texture go, then the cache forgets every glyph packed into it
// @0x1426c8090
void GlyphTextureImage::TextureLost(TextureLossReason reason)
{
    TextureImage::TextureLost(reason);
    pCache->TextureLost(TextureId, reason);
}

// @0x1426c53a0
bool GlyphTextureMapper::Create(unsigned method, MemoryHeap* heap, TextureManager* texMan,
                                PrimitiveFillManager* fillMan, GlyphCache* cache, unsigned textureId,
                                const ImageSize& size)
{
    pTexMan = texMan;
    Method  = method;
    unsigned use = 0;
    bool     ok;

    if (method == GlyphCache::TU_WholeImage)
    {
        // the glyphs are drawn into system memory and the whole image is uploaded on unmap
        pTexImg = 0;
        use |= ImageUse_Update;
        pRawImg = *RawImage::Create(Image_A8, 1, size, use, heap);
        ok = pRawImg.GetPtr() != 0;
        if (ok)
        {
            PrimitiveFillData fill(PrimFill_UVTextureAlpha_VColor, &RasterGlyphVertex::Format,
                                   pRawImg->GetTexture(texMan), ImageFillMode(Wrap_Clamp, Sample_Linear));
            pFill = *fillMan->CreateFill(fill);
        }
    }
    else
    {
        pRawImg = 0;
        if (method == GlyphCache::TU_MultipleUpdate)
            use |= ImageUse_PartialUpdate;
        else
            use |= ImageUse_MapSimThread | ImageUse_MapRenderThread;
        pTexImg = *GlyphTextureImage::Create(heap, texMan, cache, textureId, size, use);
        ok = pTexImg.GetPtr() != 0;
        if (ok)
        {
            PrimitiveFillData fill(PrimFill_UVTextureAlpha_VColor, &RasterGlyphVertex::Format,
                                   pTexImg->GetTexture(texMan), ImageFillMode(Wrap_Clamp, Sample_Linear));
            pFill = *fillMan->CreateFill(fill);
        }
    }
    Valid = ok;
    return ok;
}

// the plane glyphs are copied into (none for partial updates, those go through the staging image)
// @0x1426c6750
ImagePlane* GlyphTextureMapper::Map()
{
    ImagePlane* plane = 0;
    switch (Method)
    {
    case GlyphCache::TU_DirectMap:
        if (!Mapped)
        {
            if (!pTexImg->Map(&Data, 0, 1))
                break;
            Mapped = true;
        }
        plane = Data.pPlanes;
        break;

    case GlyphCache::TU_WholeImage:
        if (!Mapped)
        {
            if (!pRawImg->Map(&Data, 0, 0))
                break;
            Mapped = true;
        }
        plane = Data.pPlanes;
        break;
    }
    return plane;
}

// @0x1426c8250
bool GlyphTextureMapper::Unmap()
{
    bool ok = false;
    switch (Method)
    {
    case GlyphCache::TU_DirectMap:
        if (Mapped)
        {
            ok     = pTexImg->Unmap();
            Mapped = false;
        }
        break;

    case GlyphCache::TU_WholeImage:
        if (Mapped)
        {
            ok = pRawImg->Unmap();
            pRawImg->GetTexture(pTexMan)->Update();
            Mapped = false;
        }
        break;
    }
    return ok;
}

// @0x1426c8360
bool GlyphTextureMapper::Update(const Texture::UpdateDesc* updates, unsigned count)
{
    bool ok = false;
    if (Method == GlyphCache::TU_MultipleUpdate)
    {
        Texture* texture = pTexImg->GetTexture(pTexMan);
        if (texture)
            ok = texture->Update(updates, count);
    }
    return ok;
}

Texture* GlyphTextureMapper::GetTexture()
{
    if (Method == GlyphCache::TU_WholeImage)
        return pRawImg->GetTexture(pTexMan);
    return pTexImg->GetTexture(pTexMan);
}

//--------------------------------------------------------------------------------------------------------------------
// GlyphCache: life cycle

// @0x1426c3930
GlyphCache::GlyphCache(MemoryHeap* heap)
    : pHeap(heap), pRenderer(0), pFillMan(0), pTexMan(0),
      TextureWidth(0), TextureHeight(0), MaxNumTextures(0), MaxSlotHeight(0), SlotPadding(0),
      ScaleU(0), ScaleV(0), ShadowQuality(1),
      Method(TU_DirectMap), UpdatePacker(0, 0),
      pRQCaches(0),
      Fitter(heap), Ras(heap),
      ScanlineFilter(8.0f / 9.0f, 2.0f / 9.0f, 0.2f / 9.0f),
      RasterPitch(0),
      LHeap1(heap), LHeap2(heap),
      mStroker(&LHeap2), TmpPath1(&LHeap1), TmpPath2(&LHeap2),
      RasterizationCount(0), RasterCacheWarning(true), RasterTooBigWarning(true)
{
    Notifier.pCache = this;

    unsigned step = 0;
    for (unsigned size = 0; size < 256; ++size)
    {
        if (size > FontSizeRamp[step + 1])
            ++step;
        FontSizeMap[size] = (UByte)step;
    }

    pLog = Log::GetGlobalLog();
    if (!pLog)
        pLog = Log::GetDefaultLog();
}

// @0x1426c43c0
GlyphCache::~GlyphCache()
{
    Destroy();
}

// @0x1426c5f40
void GlyphCache::Destroy()
{
    UnpinAllSlots();
    Queue.Clear();
    releaseAllTextures();
    UpdatePacker.Clear();
    GlyphsToUpdate.Clear();
    RectsToUpdate.Clear();
    VectorGlyphShapeList.Clear();
    VectorGlyphCache.Clear();
    if (pFontHandleManager)
    {
        pFontHandleManager->DestroyAllFonts();
        pFontHandleManager.Clear();
    }
    if (pRQCaches)
    {
        pRQCaches->SetCache(Cache_Glyph, 0);
        pRQCaches = 0;
    }
}

// @0x1426c5180
void GlyphCache::ClearCache()
{
    UnpinAllSlots();
    Queue.Clear();
    UpdatePacker.Clear();
    GlyphsToUpdate.Clear();
    RectsToUpdate.Clear();
    VectorGlyphShapeList.Clear();
    VectorGlyphCache.Clear();
}

// @0x1426c7e00
bool GlyphCache::SetParams(const GlyphCacheParams& params)
{
    Param = params;
    if (pRenderer && pRenderer->IsInitialized())
        initialize();
    return true;
}

// sizes the texture pool from the parameters (power-of-two textures, at most 32 of them), picks how glyphs reach
// the textures and creates the fills
// @0x1426ca670
void GlyphCache::initialize()
{
    Destroy();
    pTexMan = pRenderer->GetTextureManager();

    unsigned texWidth   = Param.TextureWidth;
    unsigned texHeight  = Param.TextureHeight;
    unsigned numTex     = Param.NumTextures;
    unsigned slotHeight = Param.MaxSlotHeight;
    unsigned padding    = Param.SlotPadding;
    unsigned updWidth   = Param.TexUpdWidth;
    unsigned updHeight  = Param.TexUpdHeight;
    bool     fenceWait  = Param.FenceWaitOnFullCache;

    unsigned w = (texWidth < 64) ? 63 : texWidth - 1;
    unsigned h = (texHeight < 64) ? 63 : texHeight - 1;
    unsigned wBits = 0, hBits = 0;
    while (w) { ++wBits; w >>= 1; }
    while (h) { ++hBits; h >>= 1; }
    if (numTex > TexturePoolSize)
        numTex = TexturePoolSize;

    TextureWidth   = 1 << wBits;
    TextureHeight  = 1 << hBits;
    MaxNumTextures = numTex;
    MaxSlotHeight  = slotHeight;
    SlotPadding    = padding;
    ScaleU         = 1.0f / (float)TextureWidth;
    ScaleV         = 1.0f / (float)TextureHeight;
    ShadowQuality  = Param.ShadowQuality;

    if (MaxNumTextures)
    {
        Queue.Init(&Notifier, 0, numTex, texWidth, texHeight, slotHeight, fenceWait);

        unsigned caps = pTexMan->GetTextureUseCaps(Image_A8);
        if (caps & ImageUse_MapRenderThread)
            Method = TU_DirectMap;
        else if (caps & ImageUse_PartialUpdate)
        {
            Method       = TU_MultipleUpdate;
            UpdatePacker = TextureUpdatePacker(updWidth, updHeight);
            UpdateBuffer = *RawImage::Create(Image_A8, 1, ImageSize(updWidth, updHeight), 0, pHeap);
        }
        else
            Method = TU_WholeImage;

        for (unsigned i = 0; i < MaxNumTextures; ++i)
            Textures[i].Create(Method, pHeap, pTexMan, pFillMan, this, i, ImageSize(TextureWidth, TextureHeight));
    }

    if (!pFontHandleManager)
        pFontHandleManager = *SF_NEW FontCacheHandleManager(pHeap, this);

    PrimitiveFillData solid(PrimFill_VColor_EAlpha, &VertexXY16iCF32::Format);
    PrimitiveFillData mask(PrimFill_Mask, &VertexXY16i::Format);
    pSolidFill = *pFillMan->CreateFill(solid);
    pMaskFill  = *pFillMan->CreateFill(mask);
    pRQCaches  = &pRenderer->GetRQCacheInterface();
    pRQCaches->SetCache(Cache_Glyph, this);
}

// @0x1426c6660
void GlyphCache::Initialize(HAL* ren, PrimitiveFillManager* fillMan)
{
    pRenderer = ren;
    pFillMan  = fillMan;
    if (pRenderer->IsInitialized())
        initialize();
}

// the pool is built lazily, once the HAL is up
// @0x1426c8d30
bool GlyphCache::checkInitialization()
{
    if (!pFontHandleManager)
    {
        if (!pRenderer || !pRenderer->IsInitialized())
            return false;
        initialize();
    }
    return pFontHandleManager.GetPtr() != 0;
}

// @0x1426c67c0
void GlyphCache::OnBeginFrame()
{
    if (checkInitialization())
        pFontHandleManager->ProcessKillList();
}

// @0x1426c67b0
void GlyphCache::MergeCacheSlots()
{
    Queue.MergeEmptySlots();
}

void GlyphCache::OnEndFrame()
{
}

// a font died: drop its glyphs from the queue and its vector shapes from the list and the set
// @0x1426c4f10
void GlyphCache::CleanUpFont(FontCacheHandle* font)
{
    ApplyInUseList();
    UpdatePinList();
    Queue.CleanUpFont(font);

    VectorGlyphShape* shape = VectorGlyphShapeList.GetFirst();
    while (!VectorGlyphShapeList.IsNull(shape))
    {
        VectorGlyphShape* next = shape->pNext;
        if (shape->Key.pFont == font)
        {
            VectorGlyphShapeList.Remove(shape);
            VectorGlyphCache.Remove(shape);
        }
        shape = next;
    }
}

// @0x1426c62a0
PrimitiveFill* GlyphCache::GetFill(TextLayerType type, unsigned textureId)
{
    switch (type)
    {
    case TextLayer_Background:
    case TextLayer_Selection:
        return pSolidFill;
    case TextLayer_Shadow:
    case TextLayer_ShadowText:
    case TextLayer_RasterText:
        return Textures[textureId].GetFill();
    case TextLayer_PackedText:
    case TextLayer_PackedDFAText:
    case TextLayer_Images:
        return 0;
    case TextLayer_Shapes:
    case TextLayer_Underline:
    case TextLayer_Cursor:
        return pSolidFill;
    case TextLayer_Mask:
        return pMaskFill;
    case TextLayer_Shapes_Masked:
    case TextLayer_Underline_Masked:
        return pSolidFill;
    }
    return 0;
}

// @0x1426c6380
Image* GlyphCache::GetImage(unsigned textureId)
{
    return Textures[textureId].GetImage();
}

//--------------------------------------------------------------------------------------------------------------------
// GlyphCache: texture updates

// sends the glyphs staged for each texture as one batch of rectangles
// @0x1426cae60
void GlyphCache::partialUpdateTextures()
{
    ImageData staging;
    UpdateBuffer->GetImageData(&staging);

    for (unsigned i = 0; i < MaxNumTextures; ++i)
    {
        GlyphTextureMapper& texture = Textures[i];
        if (!texture.NumGlyphsToUpdate)
            continue;

        RectsToUpdate.Resize(texture.NumGlyphsToUpdate, 32);
        unsigned numRects = 0;
        for (unsigned j = 0; j < (unsigned)GlyphsToUpdate.GetSize(); j++)
        {
            if (GlyphsToUpdate[j].TextureId != i)
                continue;
            const UpdateRect& r    = GlyphsToUpdate[j];
            UpdateDesc&       desc = RectsToUpdate[numRects++];
            ImageData         src;
            UpdateBuffer->GetImageData(&src);
            desc.DestRect.x1       = r.DstX;
            desc.DestRect.y1       = r.DstY;
            desc.DestRect.x2       = r.DstX + r.w;
            desc.DestRect.y2       = r.DstY + r.h;
            desc.SourcePlane       = staging.pPlanes[0];
            desc.SourcePlane.pData = src.pPlanes[0].GetScanline(r.SrcY) + r.SrcX;
            desc.PlaneIndex        = 0;
        }
        texture.Update(&RectsToUpdate[0], numRects);
        texture.NumGlyphsToUpdate = 0;
    }
    GlyphsToUpdate.Clear();
    UpdatePacker.Clear();
}

// @0x1426c9b00
void GlyphCache::copyImageData(ImagePlane* pl, const UByte* data, unsigned pitch, unsigned dstX, unsigned dstY,
                               unsigned w, unsigned h)
{
    for (unsigned row = 0; row < h; ++row)
    {
        memcpy(pl->GetScanline(dstY + row) + dstX, data, w);
        data += pitch;
    }
}

// copies the freshly rasterized glyph (RasterData) to its texture, or stages it for a partial update
// @0x1426cb6e0
bool GlyphCache::updateTextureGlyph(const GlyphNode* node)
{
    unsigned     textureId = GetTextureId(node);
    const UByte* data      = &RasterData[0];
    unsigned     pitch     = RasterPitch;
    unsigned     dstX      = node->mRect.x;
    unsigned     dstY      = node->mRect.y;
    unsigned     w         = node->mRect.w;
    unsigned     h         = node->mRect.h;

    if (!Textures[textureId].IsValid())
        Textures[textureId].Create(Method, pHeap, pTexMan, pFillMan, this, textureId,
                                   ImageSize(TextureWidth, TextureHeight));

    pRQCaches->SetCacheLocked(Cache_Glyph);
    if (Method == TU_MultipleUpdate)
    {
        unsigned updX, updY;
        if (!UpdatePacker.Allocate(w, h, &updX, &updY))
        {
            partialUpdateTextures();
            if (!UpdatePacker.Allocate(w, h, &updX, &updY))
                return false;
        }
        ImageData staging;
        UpdateBuffer->GetImageData(&staging);
        copyImageData(staging.pPlanes, data, pitch, updX, updY, w, h);
        Textures[textureId].NumGlyphsToUpdate++;

        UpdateRect r;
        r.SrcX      = updX;
        r.SrcY      = updY;
        r.DstX      = dstX;
        r.DstY      = dstY;
        r.w         = w;
        r.h         = h;
        r.TextureId = textureId;
        GlyphsToUpdate.PushBack(r);
        return true;
    }

    ImagePlane* plane = Textures[textureId].Map();
    if (plane)
    {
        copyImageData(plane, data, pitch, dstX, dstY, w, h);
        return true;
    }
    return false;
}

// the AMP profiler's snapshot of the textures: each valid one is written through the AMP image writer
class AmpGlyphImageWriter : public ImageFileWriter_Mixin<AmpGlyphImageWriter>
{
public:
    AmpGlyphImageWriter() : Version(0) {}
    static bool  WriteImage(File* file, Image* image) { return writeImage(file, &Instance, image, 0); }
    void         SetVersion(UInt32 version) { Version = version; }
    virtual bool Write(File* file, const ImageData& imageData, const ImageWriteArgs* args = 0) const
    {
        imageData.Write(*file, Version);
        return true;
    }
    static AmpGlyphImageWriter Instance;   // 0x143a2fee8
private:
    UInt32 Version;
};
AmpGlyphImageWriter AmpGlyphImageWriter::Instance;

// @0x1426c6550
int GlyphCache::GetTextureData(File* dataFile, UInt32 version)
{
    int count = 0;
    AmpGlyphImageWriter::Instance.SetVersion(version);
    pRQCaches->SetCacheLocked(Cache_Glyph);
    for (unsigned i = 0; i < MaxNumTextures; ++i)
    {
        if (Textures[i].IsValid() &&
            AmpGlyphImageWriter::WriteImage(dataFile, Textures[i].GetImage()))
            ++count;
    }
    pRQCaches->ClearCacheLocked(Cache_Glyph);
    return count;
}

// @0x1426c8180
void GlyphCache::UnlockBuffers()
{
    if (Method == TU_MultipleUpdate)
        partialUpdateTextures();
    for (unsigned i = 0; i < MaxNumTextures; ++i)
        Textures[i].Unmap();
    pRQCaches->ClearCacheLocked(Cache_Glyph);
}

void GlyphCache::releaseAllTextures()
{
    for (unsigned i = 0; i < MaxNumTextures; ++i)
        Textures[i].Invalidate();
    GlyphsToUpdate.Clear();
}

// @0x1426c7fc0
void GlyphCache::TextureLost(unsigned textureId, unsigned)
{
    Queue.CleanUpTexture(textureId);

    UPInt kept = 0;
    for (UPInt i = 0; i < GlyphsToUpdate.GetSize(); i++)
    {
        if (GlyphsToUpdate[i].TextureId != textureId)
            GlyphsToUpdate[kept++] = GlyphsToUpdate[i];
    }
    GlyphsToUpdate.CutAt(kept);
    Textures[textureId].Invalidate();
}

//--------------------------------------------------------------------------------------------------------------------
// GlyphCache: fonts, glyph nodes and the text lists

// @0x1426c7c10
FontCacheHandle* GlyphCache::RegisterFont(Font* font)
{
    if (checkInitialization())
        return pFontHandleManager->RegisterFont(font);
    return 0;
}

// @0x1426c6110
GlyphNode* GlyphCache::FindGlyph(TextMeshProvider* tm, const GlyphParam& gp)
{
    GlyphNode* node = Queue.FindGlyph(gp);
    if (node)
        tm->AddNotifier(Queue.CreateNotifier(node, tm));
    return node;
}

// @0x1426c8bf0
GlyphNode* GlyphCache::allocateGlyph(TextMeshProvider* tm, const GlyphParam& gp, unsigned w, unsigned h)
{
    GlyphNode* node = Queue.AllocateGlyph(gp, w, h);
    if (node)
        tm->AddNotifier(Queue.CreateNotifier(node, tm));
    return node;
}

// @0x1426c82e0
void GlyphCache::UnpinAllSlots()
{
    TextMeshProvider* tm;
    for (tm = TextInUse.GetFirst(); !TextInUse.IsNull(tm); tm = tm->pNext)
        tm->ClearInList();
    for (tm = TextInPin.GetFirst(); !TextInPin.IsNull(tm); tm = tm->pNext)
        tm->ClearInList();
    TextInUse.Clear();
    TextInPin.Clear();
    Queue.UnpinAllSlots();
}

void GlyphCache::EvictText(TextMeshProvider* tm)
{
    tm->OnEvictSlots();
}

// the texts drawn this frame pin their slots and move to the pinned list
// @0x1426c4e20
void GlyphCache::ApplyInUseList()
{
    TextMeshProvider* tm = TextInUse.GetFirst();
    while (!TextInUse.IsNull(tm))
    {
        TextMeshProvider* next = tm->pNext;
        tm->SetInUseList(false);
        tm->PinSlots();
        TextInPin.PushBack(tm);
        tm->SetInPinList(true);
        tm = next;
    }
    TextInUse.Clear();
}

// pinned texts no longer in use give their slots back; true when any did
// @0x1426c83d0
bool GlyphCache::UpdatePinList()
{
    bool released = false;
    TextMeshProvider* tm = TextInPin.GetFirst();
    while (!TextInPin.IsNull(tm))
    {
        TextMeshProvider* next = tm->pNext;
        if (!tm->IsInUse())
        {
            tm->SetInPinList(false);
            tm->UnpinSlots();
            tm->RemoveNode();
            released = true;
        }
        tm = next;
    }
    return released;
}

// @0x1426c8d00
void GlyphCache::cacheFullWarning()
{
    if (RasterCacheWarning)
    {
        LogWarning("Increase raster glyph cache capacity - see GlyphCacheParams.");
        RasterCacheWarning = false;
    }
}

// the shape set is looked up by key without building a shape
inline bool operator==(const Ptr<VectorGlyphShape>& shape, const VectorGlyphKey& key) { return shape->Key == key; }

// a cached shape no mesh refers to any more
static inline bool IsShapeUnused(const VectorGlyphShape* shape)
{
    return shape->hKeySet.pKeySet == 0 || shape->hKeySet.pKeySet->IsEmpty();
}

// The outline (and hinted bitmap) of one glyph for a text run. Plain unhinted glyphs come straight from the font's
// permanent shapes and return 0; anything hinted, faux-styled or outlined is built once and kept in the shape set,
// most recently used last, the oldest unused ones dropped when the set outgrows MaxVectorCacheSize.
// @0x1426c5700
VectorGlyphShape* GlyphCache::CreateGlyphShape(GlyphRunData& data, unsigned glyphIndex, float screenSize,
                                               bool fauxBold, bool fauxItalic, unsigned outline,
                                               bool needsVectorShape)
{
    Font* font = data.pFont;
    data.VectorSize  = 0;
    data.RasterSize  = 0;
    data.pShape      = 0;
    data.pRaster     = 0;
    data.GlyphBounds = RectF(0, 0, 0, 0);
    data.NomHeight   = font->GetNominalGlyphHeight();
    data.NomWidth    = font->GetNominalGlyphWidth();

    if ((glyphIndex & 0xFFFF) == 0xFFFF)
        return 0;

    bool nativeHinting = UInt8(font->GetFontFlags() >> 5) & 1;   // FF_NativeHinting
    if (!nativeHinting)
        screenSize = 0;

    unsigned hintedVector = 0;
    unsigned hintedRaster = 0;
    if (screenSize != 0)
    {
        if (font->IsHintedRasterGlyph(glyphIndex, unsigned(screenSize)))
            hintedRaster = unsigned(screenSize);
        if (font->IsHintedVectorGlyph(glyphIndex, unsigned(screenSize)))
            hintedVector = unsigned(screenSize);
    }

    unsigned flags = (fauxBold ? Font::FF_Bold : 0) | (fauxItalic ? Font::FF_Italic : 0);
    if (flags == 0 && hintedVector == 0 && hintedRaster == 0 && outline == 0 && !needsVectorShape)
    {
        data.pShape = font->GetPermanentGlyphShape(glyphIndex);
        if (data.pShape)
        {
            font->GetGlyphBounds(glyphIndex, &data.GlyphBounds);
            return 0;
        }
    }

    Ptr<VectorGlyphShape>* found = VectorGlyphCache.GetAlt(
        VectorGlyphKey(data.pFontHandle, glyphIndex, hintedVector, hintedRaster, flags, outline));
    if (found)
    {
        VectorGlyphShapeList.SendToBack(*found);
        data.VectorSize  = (*found)->Key.HintedVector;
        data.RasterSize  = (*found)->Key.HintedRaster;
        data.pShape      = (*found)->pShape;
        data.pRaster     = (*found)->pRaster;
        data.GlyphBounds = (*found)->Bounds;
        (*found)->AddRef();
        return *found;
    }

    VectorGlyphShape* shape = 0;
    if (VectorGlyphCache.GetSize() > Param.MaxVectorCacheSize)
    {
        shape = VectorGlyphShapeList.GetFirst();
        unsigned excess = unsigned(VectorGlyphCache.GetSize()) - Param.MaxVectorCacheSize;
        if (excess > Param.MaxVectorCacheSize)
            excess = Param.MaxVectorCacheSize;
        for (unsigned i = 0; i < excess && !VectorGlyphShapeList.IsNull(shape); ++i)
        {
            VectorGlyphShape* next = shape->pNext;
            if (IsShapeUnused(shape))
            {
                VectorGlyphShapeList.Remove(shape);
                VectorGlyphCache.Remove(shape);
            }
            shape = next;
        }
    }

    shape = SF_HEAP_NEW(pHeap) VectorGlyphShape(this);
    shape->Key.pFont        = data.pFontHandle;
    shape->Key.GlyphIndex   = UInt16(glyphIndex);
    shape->Key.HintedVector = UInt8(hintedVector);
    shape->Key.HintedRaster = UInt8(hintedRaster);
    shape->Key.Flags        = UInt8(flags);
    shape->Key.Outline      = UInt8(outline);
    shape->pShape = *SF_HEAP_NEW(pHeap) GlyphShape;
    if (hintedRaster)
        shape->pRaster = *SF_HEAP_NEW(pHeap) GlyphRaster;

    const ShapeDataInterface* permanent = 0;
    if (hintedVector == 0)
        permanent = font->GetPermanentGlyphShape(glyphIndex);

    float descent = font->GetDescent();
    if (permanent)
    {
        font->GetGlyphBounds(glyphIndex, &shape->Bounds);
        copyAndTransformShape(shape, permanent, fauxBold, fauxItalic, outline, descent, data.NomHeight);
    }
    else if (!fauxBold && !fauxItalic && outline == 0)
    {
        shape->pShape->Clear();
        font->GetTemporaryGlyphShape(glyphIndex, hintedVector, shape->pShape);
        getGlyphBounds(shape, shape->pShape);
    }
    else
    {
        // the font's outline goes to a scratch shape first, the styled copy into the cached one
        Ptr<GlyphShape> scratch = *SF_HEAP_NEW(pHeap) GlyphShape;
        font->GetTemporaryGlyphShape(glyphIndex, hintedVector, scratch);
        getGlyphBounds(shape, scratch);
        copyAndTransformShape(shape, scratch, fauxBold, fauxItalic, outline, descent, data.NomHeight);
    }

    if (hintedRaster)
    {
        font->GetGlyphRaster(glyphIndex, hintedRaster, shape->pRaster);
        shape->pRaster->HintedSize = hintedRaster;
    }

    data.GlyphBounds     = shape->Bounds;
    data.VectorSize      = hintedVector;
    data.RasterSize      = hintedRaster;
    data.pShape          = shape->pShape;
    data.pRaster         = shape->pRaster;
    data.HintedNomHeight = shape->pShape->GetHintedSize();
    VectorGlyphShapeList.PushBack(shape);
    VectorGlyphCache.Add(shape);
    return shape;
}

// A glyph the font delivers already rasterized: its bitmap goes into a padded slot as is (no scaling).
// @0x1426ca460
GlyphNode* GlyphCache::getPrerasterizedGlyph(GlyphRunData& data, TextMeshProvider* tm, const GlyphParam& gp)
{
    const GlyphRaster* raster = data.pRaster;
    if (unsigned(raster->Height + 2 * SlotPadding) >= MaxSlotHeight && !data.pShape->IsEmpty())
    {
        Result = Res_ShapeIsTooBig;
        return 0;
    }

    int pad = SlotPadding;
    int x1  = -raster->OriginX - pad;
    int x2  = raster->Width - raster->OriginX + pad;
    int y1  = -raster->OriginY - pad;
    int y2  = raster->Height - raster->OriginY + pad;

    unsigned w = x2 - x1 + 1;
    unsigned h = y2 - y1 + 1;
    if (h > MaxSlotHeight)
    {
        h = MaxSlotHeight;
        rasterTooBigWarning();
    }

    GlyphNode* node = allocateGlyph(tm, gp, w, h);
    if (!node)
    {
        Result = Res_CacheFull;
        cacheFullWarning();
        return 0;
    }
    node->Origin.x = SInt16(x1 * 16);
    node->Origin.y = SInt16(y1 * 16);
    node->Scale    = 1.0f;

    RasterData.Resize(w * h);
    RasterPitch = w;
    memset(&RasterData[0], 0, w * h);
    for (unsigned row = 0; row < unsigned(raster->Height) && pad + row < h; ++row)
        memcpy(&RasterData[(pad + row) * RasterPitch + pad], &raster->Raster[row * raster->Width], unsigned(raster->Width));

    updateTextureGlyph(node);
    ++RasterizationCount;
    return node;
}

// Rasterizes one glyph into a free slot: prerasterized glyphs are copied, outlines are scaled to the font size (hinted
// through the fitter when the font has its tops and is not natively hinted), swept row by row into the work raster
// and uploaded. Stretched glyphs (x 2.5, for readability) are filtered horizontally.
// MS2-FUNCTIONAL: same instruction stream; stretch and the floored top swap xmm7 / xmm8
// @0x1426c6840
GlyphNode* GlyphCache::RasterizeGlyph(GlyphRunData& data, TextMeshProvider* tm, const GlyphParam& gp)
{
    if (MaxNumTextures == 0)
    {
        Result = Res_NoRasterCache;
        return 0;
    }
    if (data.RasterSize)
        return getPrerasterizedGlyph(data, tm, gp);
    if (data.pShape == 0)
    {
        Result = Res_ShapeNotFound;
        return 0;
    }

    unsigned lowerCaseTop = 0;
    unsigned upperCaseTop = 0;
    bool  autoFit      = Param.UseAutoFit && gp.IsAutoFit();
    float stretch      = gp.GetStretch();
    if (autoFit)
    {
        lowerCaseTop = gp.pFont->pFont->GetLowerCaseTop(this);
        upperCaseTop = gp.pFont->pFont->GetUpperCaseTop(this);
        if (lowerCaseTop == 0 || upperCaseTop == 0)
            autoFit = false;
    }

    float nomHeight = data.NomHeight;
    if (data.HintedNomHeight)
    {
        nomHeight = float(data.HintedNomHeight);
        autoFit   = false;
    }

    float scale = gp.GetFontSize() / nomHeight;
    float y1    = float(floor(data.GlyphBounds.y1 * scale));
    float y2    = float(ceil(data.GlyphBounds.y2 * scale));
    if (y1 >= y2)
        y1 = y2 = 0;
    if (unsigned(y2 - y1) + 2 * SlotPadding >= MaxSlotHeight)
    {
        Result = Res_ShapeIsTooBig;
        return 0;
    }

    Ras.Clear();
    if (autoFit)
        addShapeAutoFit(data.pShape, unsigned(data.NomHeight), lowerCaseTop, upperCaseTop, gp.GetFontSize(), stretch);
    else
        addShapeToRasterizer(data.pShape, scale * stretch, scale);

    int pad = SlotPadding;
    int x1 = 0, x2 = 0, iy1 = 0, iy2 = 0;
    if (Ras.SortCells())
    {
        x1  = Ras.GetMinX() - pad;
        x2  = Ras.GetMaxX() + pad;
        iy1 = Ras.GetMinY() - pad;
        iy2 = Ras.GetMaxY() + pad;
    }
    unsigned w = x2 - x1 + 1;
    unsigned h = iy2 - iy1 + 1;
    if (h > MaxSlotHeight)
        h = MaxSlotHeight;

    GlyphNode* node = allocateGlyph(tm, gp, w, h);
    if (!node)
    {
        Result = Res_CacheFull;
        cacheFullWarning();
        return 0;
    }
    node->Origin.x = SInt16(x1 * 16);
    node->Origin.y = SInt16(iy1 * 16);
    node->Scale    = 1.0f;

    RasterData.Resize(w * h);
    RasterPitch = w;
    memset(&RasterData[0], 0, w * h);

    if (Ras.GetGamma1() != 1.0f)
        Ras.SetGamma1(1.0f);

    bool filter = w >= 5 && stretch > 1.0f;
    for (unsigned i = 0; i < Ras.GetNumScanlines() && pad + i < h; ++i)
    {
        UByte* sl = &RasterData[(pad + i) * RasterPitch];
        Ras.SweepScanline(i, sl + pad, 1, 0);
        if (filter)
            filterScanline(sl, w);
    }

    updateTextureGlyph(node);
    ++RasterizationCount;
    Ras.Clear();
    return node;
}

// A knocked-out shadow keeps only what lies outside the glyph: every pixel is scaled down by the unblurred
// coverage saved in KnockOutCopy.
inline void GlyphCache::knockOut(UByte* raster)
{
    const UByte* glyph = &KnockOutCopy[0];
    for (UPInt i = 0; i < KnockOutCopy.GetSize(); ++i)
    {
        unsigned outside = 255 - *glyph++;
        *raster = UByte((*raster * outside + 255) >> 8);
        ++raster;
    }
}
inline void GlyphCache::knockOut(ArrayLH_POD<UByte, SID>& image)
{
    const UByte* glyph  = &KnockOutCopy[0];
    UByte*       raster = &image[0];
    for (UPInt i = 0; i < KnockOutCopy.GetSize(); ++i)
    {
        unsigned outside = 255 - *glyph++;
        *raster = UByte((*raster * outside + 255) >> 8);
        ++raster;
    }
}

// A shadow / glow: from the font's own raster when it has one, otherwise the outline is rasterized with the blur
// radius as extra padding, softened by a gamma, blurred, strengthened and optionally knocked out. Shadows taller
// than the quality-scaled slot are drawn smaller and stretched back by the node's scale.
// MS2-FUNCTIONAL: knock-out loop loads the raster pointer before KnockOutCopy's (exe the other way round)
// @0x1426c6d80
GlyphNode* GlyphCache::RasterizeShadow(GlyphRunData& data, TextMeshProvider* tm, const GlyphParam& gp,
                                       float screenSize, const GlyphRaster* ras)
{
    if (MaxNumTextures == 0)
    {
        Result = Res_NoRasterCache;
        return 0;
    }
    if (ras)
    {
        GlyphNode* node = createShadowFromRaster(data, tm, gp, screenSize, ras);
        if (node)
            return node;
    }
    if (data.pShape == 0)
    {
        Result = Res_ShapeNotFound;
        return 0;
    }

    float k     = gp.GetFontSize() / screenSize;
    float blurX = gp.GetBlurX() * k * data.HeightRatio;
    float blurY = gp.GetBlurY() * k * data.HeightRatio;
    float maxH  = float(MaxSlotHeight) * ShadowQuality - float(2 * SlotPadding);

    float rasterScale = 1.0f;
    float scale = gp.GetFontSize() / (data.HintedNomHeight ? float(data.HintedNomHeight) : data.NomHeight);
    float y1    = data.GlyphBounds.y1;
    float y2    = data.GlyphBounds.y2;
    if (y1 >= y2)
        y1 = y2 = 0;
    y1 = y1 * scale - blurY;
    y2 = y2 * scale + blurY;
    float h = y2 - y1;
    if (h >= maxH)
    {
        k            = maxH / h;
        scale       *= k;
        blurX       *= k;
        blurY       *= k;
        rasterScale  = 1.0f / k;
    }

    int intBlurX = int(ceil(blurX));
    int intBlurY = int(ceil(blurY));

    Ras.Clear();
    addShapeToRasterizer(data.pShape, scale, scale);

    int padX = SlotPadding + intBlurX;
    int padY = SlotPadding + intBlurY;
    int x1 = 0, x2 = 0, iy1 = 0, iy2 = 0;
    if (Ras.SortCells())
    {
        x1  = Ras.GetMinX() - padX;
        x2  = Ras.GetMaxX() + padX;
        iy1 = Ras.GetMinY() - padY;
        iy2 = Ras.GetMaxY() + padY;
    }
    unsigned w  = x2 - x1 + 1;
    unsigned hh = iy2 - iy1 + 1;
    if (hh > MaxSlotHeight)
        hh = MaxSlotHeight;

    GlyphNode* node = allocateGlyph(tm, gp, w, hh);
    if (!node)
    {
        Result = Res_CacheFull;
        cacheFullWarning();
        return 0;
    }
    node->Origin.x = SInt16(x1 * 16);
    node->Origin.y = SInt16(iy1 * 16);
    node->Scale    = rasterScale;

    RasterData.Resize(w * hh);
    RasterPitch = w;
    memset(&RasterData[0], 0, w * hh);

    if (w > 1 && hh > 1)
    {
        // a softer gamma makes blurred shadows and glows stronger
        float gamma = 1.0f;
        if (gp.BlurX || gp.BlurY)
            gamma = 0.4f;
        if (gamma != Ras.GetGamma2())
            Ras.SetGamma2(gamma);

        for (unsigned i = 0; i < Ras.GetNumScanlines() && padY + i < hh; ++i)
        {
            UByte* sl = &RasterData[(padY + i) * RasterPitch];
            Ras.SweepScanline(i, sl + padX, 1, 1);
        }

        int bias = 0;
        int sx = 0, sy = 0;
        if (gp.IsKnockOut())
            KnockOutCopy = RasterData;
        if (blurX > 0 || blurY > 0)
        {
            recursiveBlur(&RasterData[0], RasterPitch, sx, sy, w, hh, blurX, blurY);
            bias = 8;
        }
        strengthenImage(&RasterData[0], RasterPitch, sx, sy, w, hh,
                        gp.GetBlurStrength(), (gp.GetBlurStrength() <= 1.0f) ? 0 : bias);
        if (gp.IsKnockOut())
            knockOut(&RasterData[0]);
    }

    updateTextureGlyph(node);
    ++RasterizationCount;
    Ras.Clear();
    return node;
}

// A shadow / glow from the font's own raster: the bitmap is copied into a padded source buffer, blurred,
// strengthened and optionally knocked out there, then bilinearly shrunk into RasterData when the slot is smaller
// (the node's scale stretches it back).
// @0x1426c9ba0
GlyphNode* GlyphCache::createShadowFromRaster(GlyphRunData& data, TextMeshProvider* tm, const GlyphParam& gp,
                                              float screenSize, const GlyphRaster* ras)
{
    float k     = gp.GetFontSize() / screenSize;
    float blurX = gp.GetBlurX() * k * data.HeightRatio;
    float blurY = gp.GetBlurY() * k * data.HeightRatio;
    float maxH  = float(MaxSlotHeight) * ShadowQuality - float(2 * SlotPadding);
    float shrink = 1.0f;
    float h = blurY + blurY + float(unsigned(ras->Height));
    if (h >= maxH)
    {
        shrink  = maxH / h;
        blurX  *= shrink;
        blurY  *= shrink;
    }

    unsigned padX = int(ceil(blurX)) + SlotPadding;
    unsigned padY = int(ceil(blurY)) + SlotPadding;
    unsigned srcW = ras->Width + 1 + 2 * padX;
    unsigned srcH = ras->Height + 1 + 2 * padY;
    unsigned w    = unsigned(ceilf(float(srcW) * shrink));
    unsigned hh   = unsigned(ceilf(float(srcH) * shrink));
    if (hh > MaxSlotHeight)
        hh = MaxSlotHeight;

    GlyphNode* node = allocateGlyph(tm, gp, w, hh);
    if (!node)
    {
        Result = Res_CacheFull;
        cacheFullWarning();
        return 0;
    }
    node->Origin.x = SInt16(float(-(ras->OriginX + int(padX)) * 16) * w / srcW);
    node->Origin.y = SInt16(float(-(ras->OriginY + int(padY)) * 16) * hh / srcH);
    node->Scale    = (float(srcH) / float(hh) + float(srcW) / float(w)) * 0.5f;

    RasterDataSrc.Resize(srcW * srcH);
    RasterData.Resize(w * hh);
    RasterPitch = w;
    memset(&RasterDataSrc[0], 0, srcW * srcH);

    if (srcW > 1 && srcH > 1)
    {
        for (unsigned i = 0; i < unsigned(ras->Height) && padY + i < srcH; ++i)
            memcpy(&RasterDataSrc[0] + ((padY + i) * srcW + padX), &ras->Raster[0] + unsigned(ras->Width) * i, unsigned(ras->Width));

        int bias = 0;
        if (gp.IsKnockOut())
            KnockOutCopy = RasterDataSrc;
        if (blurX > 0 || blurY > 0)
        {
            recursiveBlur(&RasterDataSrc[0], srcW, 0, 0, srcW, srcH, blurX, blurY);
            bias = 8;
        }
        strengthenImage(&RasterDataSrc[0], srcW, 0, 0, srcW, srcH,
                        gp.GetBlurStrength(), (gp.GetBlurStrength() <= 1.0f) ? 0 : bias);
        if (gp.IsKnockOut())
            knockOut(RasterDataSrc);
    }

    if (srcH == hh && srcW == w)
        RasterData = RasterDataSrc;
    else
    {
        memset(&RasterData[0], 0, w * hh);
        ResizeImageBilinear(&RasterData[0], w, hh, w, &RasterDataSrc[0], srcW, srcH, srcW, ResizeGray);
    }

    updateTextureGlyph(node);
    ++RasterizationCount;
    return node;
}

// ---- glyph outlines ----

// bounds of the selected fill paths through a transformer, empty (inverted 1e30) when there are none
template<class Transformer>
static RectF ComputeBoundsFill(const ShapeDataInterface& shape, const Transformer& trans, BoundEdges edges)
{
    RectF bounds(1e30f, 1e30f, -1e30f, -1e30f);
    ExpandBoundsToFill(shape, trans, &bounds, edges);
    return bounds;
}

// Unhinted glyphs take the font's bounds, falling back to the outline's when the font has none; hinted ones are
// measured on the hinted outline first.
// @0x1426ca230
void GlyphCache::getGlyphBounds(VectorGlyphShape* glyphShape, const ShapeDataInterface* shape) const
{
    if (glyphShape->Key.HintedVector == 0)
    {
        glyphShape->Key.pFont->pFont->GetGlyphBounds(glyphShape->Key.GlyphIndex, &glyphShape->Bounds);
        if (glyphShape->Bounds.x1 >= glyphShape->Bounds.x2 || glyphShape->Bounds.y1 >= glyphShape->Bounds.y2)
        {
            if (!shape->IsEmpty())
                glyphShape->Bounds = ComputeBoundsFill(*shape, Matrix2F(), Bound_AllEdges);
        }
    }
    else
    {
        if (!shape->IsEmpty())
            glyphShape->Bounds = ComputeBoundsFill(*shape, Matrix2F(), Bound_AllEdges);
        else
            glyphShape->Key.pFont->pFont->GetGlyphBounds(glyphShape->Key.GlyphIndex, &glyphShape->Bounds);
    }
}

// The winding of the contour with the largest extent (of the first layer's filled paths): its signed area > 0.
// @0x1426caa80
bool GlyphCache::isOuterContourCW(const ShapeDataInterface* shape) const
{
    float minX1 = 1e10f, minY1 = 1e10f, maxX1 = -1e10f, maxY1 = -1e10f;
    float minX2 = 1e10f, minY2 = 1e10f, maxX2 = -1e10f, maxY2 = -1e10f;
    bool  cw = true;

    ShapePosInfo  pos(shape->GetStartingPos());
    ShapePathType pathType;
    PathEdgeType  edge;
    float         coord[Edge_MaxCoord];
    unsigned      styles[3];
    bool          first = true;
    while ((pathType = shape->ReadPathInfo(&pos, coord, styles)) != Shape_EndShape)
    {
        if (!first && pathType == Shape_NewLayer)
            break;
        first = false;

        if (styles[0] != styles[1])
        {
            float area   = 0;
            float startX = coord[0];
            float startY = coord[1];
            float lastX  = coord[0];
            float lastY  = coord[1];
            while ((edge = shape->ReadEdge(&pos, coord)) != Edge_EndPath)
            {
                if (coord[0] < minX1) minX1 = coord[0];
                if (coord[1] < minY1) minY1 = coord[1];
                if (coord[0] > maxX1) maxX1 = coord[0];
                if (coord[1] > maxY1) maxY1 = coord[1];
                area += lastX * coord[1] - lastY * coord[0];
                lastX = coord[0];
                lastY = coord[1];

                // a curve counts through its control and end points
                if (edge == Edge_QuadTo)
                {
                    if (coord[2] < minX1) minX1 = coord[2];
                    if (coord[3] < minY1) minY1 = coord[3];
                    if (coord[2] > maxX1) maxX1 = coord[2];
                    if (coord[3] > maxY1) maxY1 = coord[3];
                    area += lastX * coord[3] - lastY * coord[2];
                    lastX = coord[2];
                    lastY = coord[3];
                }
            }

            if (lastX != startX || lastY != startY)
            {
                if (startX < minX1) minX1 = startX;
                if (startY < minY1) minY1 = startY;
                if (startX > maxX1) maxX1 = startX;
                if (startY > maxY1) maxY1 = startY;
                area += lastX * startY - lastY * startX;
            }

            if (minX1 < minX2 || minY1 < minY2 || maxX1 > maxX2 || maxY1 > maxY2)
            {
                minX2 = minX1;
                minY2 = minY1;
                maxX2 = maxX1;
                maxY2 = maxY1;
                cw    = area > 0;
            }
        }
        else
            shape->SkipPathData(&pos);
    }
    return cw;
}

// Feeds the stroker with the y axis stretched (the faux bold outline is built at 1000x vertical resolution, so the
// equidistant of a thin italic stem keeps its shape); remembers the unscaled last point.
class StrokeScaler : public TessBase
{
public:
    StrokeScaler(TessBase& stroker, float scaleX, float scaleY)
        : pStroker(&stroker), ScaleX(scaleX), ScaleY(scaleY), LastX(0), LastY(0)
    {
    }

    virtual void      Clear() {}
    virtual CoordType GetLastX() const { return LastX; }
    virtual CoordType GetLastY() const { return LastY; }
    virtual void      AddVertex(CoordType x, CoordType y)
    {
        LastX = x;
        LastY = y;
        pStroker->AddVertex(x * ScaleX, y * ScaleY);
    }
    virtual void      ClosePath() {}
    virtual void      FinalizePath(unsigned, unsigned, bool, bool) {}
    virtual void      Transform(const Matrix2F&) {}
    virtual Matrix2F  StretchTo(float, float, float, float) { return Matrix2F(); }
    virtual unsigned  GetVertexCount() const { return 0; }
    virtual unsigned  GetMeshCount() const { return 0; }
    virtual unsigned  GetMeshVertexCount(unsigned) const { return 0; }
    virtual unsigned  GetMeshTriangleCount(unsigned) const { return 0; }
    virtual void      GetMesh(unsigned, TessMesh*) const {}
    virtual unsigned  GetVertices(TessMesh*, TessVertex*, unsigned) const { return 0; }
    virtual void      GetTrianglesI16(unsigned, UInt16*, unsigned, unsigned) const {}

private:
    TessBase* pStroker;
    float     ScaleX, ScaleY;
    float     LastX, LastY;
};

// The default tolerances with the curve and collinearity ones scaled to the glyph size.
static inline void InitGlyphTolerance(ToleranceParams* p, float tolerance)
{
    p->Epsilon                = 1e-5f;
    p->CurveTolerance         = tolerance;
    p->CollinearityTolerance  = tolerance;
    p->IntersectionEpsilon    = 0.001f;
    p->FillLowerScale         = 0.7071f;
    p->FillUpperScale         = 1.4142f;
    p->FillAliasedLowerScale  = 0.5f;
    p->FillAliasedUpperScale  = 2.0f;
    p->StrokeLowerScale       = 0.99f;
    p->StrokeUpperScale       = 1.01f;
    p->HintedStrokeLowerScale = 0.999f;
    p->HintedStrokeUpperScale = 1.001f;
    p->Scale9LowerScale       = 0.995f;
    p->Scale9UpperScale       = 1.005f;
    p->EdgeAAScale            = 0.95f;
    p->MorphTolerance         = 0.0001f;
}

// Hinted path: the outline goes through the fitter in nominal units (y up, at most 2048 units = 32 px), is snapped to
// the pixel grid for the given height, the x height and the cap height, then rasterized (x stretched).
// @0x1426c8460
void GlyphCache::addShapeAutoFit(const ShapeDataInterface* shape, unsigned nomHeight, int lowerCaseTop,
                                 int upperCaseTop, float screenSize, float stretch)
{
    Fitter.Clear();
    if (shape->IsEmpty())
        return;

    int nominal = int(screenSize * 64);
    if (nominal > 2048)
        nominal = 2048;
    Fitter.SetNominalFontHeight(nominal);
    float scale = float(nominal) / float(nomHeight);

    float tolerance = 0.5f * float(nominal) / screenSize;
    ToleranceParams param;
    InitGlyphTolerance(&param, 1.0f);
    param.CurveTolerance *= tolerance;
    param.CollinearityTolerance *= tolerance;

    ShapePosInfo  pos(shape->GetStartingPos());
    ShapePathType pathType;
    PathEdgeType  edge;
    float         coord[Edge_MaxCoord];
    unsigned      styles[3];
    bool          first = true;
    while ((pathType = shape->ReadPathInfo(&pos, coord, styles)) != Shape_EndShape)
    {
        if (!first && pathType == Shape_NewLayer)
            break;
        first = false;
        if (styles[0] != styles[1])
        {
            coord[0] *= scale;
            coord[1] *= -scale;
            Fitter.MoveTo(coord[0], coord[1]);
            while ((edge = shape->ReadEdge(&pos, coord)) != Edge_EndPath)
            {
                if (edge == Edge_LineTo)
                {
                    coord[0] *= scale;
                    coord[1] *= -scale;
                    Fitter.LineTo(coord[0], coord[1]);
                }
                else
                {
                    coord[0] *= scale;
                    coord[1] *= -scale;
                    coord[2] *= scale;
                    coord[3] *= -scale;
                    TessellateQuadCurve(&Fitter, param, coord[0], coord[1], coord[2], coord[3]);
                }
            }
            Fitter.ClosePath();
        }
        else
        {
            shape->SkipPathData(&pos);
        }
    }

    Fitter.FitGlyph(int(screenSize), 0, int(lowerCaseTop * scale), int(upperCaseTop * scale));
    scale = 1.0f / Fitter.GetUnitsPerPixelY();

    for (unsigned i = 0; i < Fitter.GetNumContours(); ++i)
    {
        const GlyphFitter::ContourType& c = Fitter.GetContour(i);
        if (c.NumVertices > 2)
        {
            GlyphFitter::VertexType v = Fitter.GetVertex(c, 0);
            Fitter.SnapVertex(v);
            Ras.MoveTo(v.x * scale * stretch, -v.y * scale);
            for (unsigned j = 1; j < c.NumVertices; ++j)
            {
                v = Fitter.GetVertex(c, j);
                Fitter.SnapVertex(v);
                Ras.LineTo(v.x * scale * stretch, -v.y * scale);
            }
            Ras.ClosePath();
        }
    }
    Fitter.Clear();
}

// Feeds the outline (first layer, filled paths only) scaled to raster pixels into the rasterizer; curves are
// flattened with the unit tolerances.
// @0x1426c89a0
void GlyphCache::addShapeToRasterizer(const ShapeDataInterface* shape, float scaleX, float scaleY)
{
    if (shape->IsEmpty())
        return;

    ToleranceParams param;
    InitGlyphTolerance(&param, 1.0f);

    ShapePosInfo  pos(shape->GetStartingPos());
    ShapePathType pathType;
    PathEdgeType  edge;
    float         coord[Edge_MaxCoord];
    unsigned      styles[3];
    bool          first = true;
    while ((pathType = shape->ReadPathInfo(&pos, coord, styles)) != Shape_EndShape)
    {
        if (!first && pathType == Shape_NewLayer)
            break;
        first = false;
        if (styles[0] != styles[1])
        {
            coord[0] *= scaleX;
            coord[1] *= scaleY;
            Ras.MoveTo(coord[0], coord[1]);
            while ((edge = shape->ReadEdge(&pos, coord)) != Edge_EndPath)
            {
                if (edge == Edge_LineTo)
                {
                    coord[0] *= scaleX;
                    coord[1] *= scaleY;
                    Ras.LineTo(coord[0], coord[1]);
                }
                else
                {
                    coord[0] *= scaleX;
                    coord[1] *= scaleY;
                    coord[2] *= scaleX;
                    coord[3] *= scaleY;
                    TessellateQuadCurve(&Ras, param, coord[0], coord[1], coord[2], coord[3]);
                }
            }
            Ras.ClosePath();
        }
        else
        {
            shape->SkipPathData(&pos);
        }
    }
}

// Copies the font outline into the cached glyph shape, sheared for faux italic. Faux bold grows every filled contour
// by an equidistant on its outer side, an outline glyph strokes the (possibly bolded) contours with a mitered line;
// both come out as polygons (layer 1 = fill style 1).
// MS2-FUNCTIONAL: same instruction stream; stack frame 0x10 smaller (local slot order) and register allocation
// @0x1426c8d80
void GlyphCache::copyAndTransformShape(VectorGlyphShape* glyphShape, const ShapeDataInterface* srcShape,
                                       bool fauxBold, bool fauxItalic, unsigned outline,
                                       float italicOffset, float nominalSize)
{
    if (srcShape->IsEmpty())
        return;

    ToleranceParams param;
    InitGlyphTolerance(&param, nominalSize / 64);

    Matrix2F italic;
    if (fauxItalic)
    {
        italic.AppendTranslation(0, italicOffset);
        italic.Append(Matrix2F(1, tanf(-Param.FauxItalicAngle), 0, float(tan(0.0)), 1, 0));
        italic.AppendTranslation(0, -italicOffset);
    }

    ShapePosInfo  srcPos(srcShape->GetStartingPos());
    ShapePosInfo  dstPos(0);
    ShapePathType pathType;
    PathEdgeType  edge;
    float         coord[Edge_MaxCoord];
    unsigned      styles[3];
    bool          first = true;
    GlyphShape*   dst;

    if (!fauxBold && !outline)
    {
        while ((pathType = srcShape->ReadPathInfo(&srcPos, coord, styles)) != Shape_EndShape)
        {
            if (!first && pathType == Shape_NewLayer)
                break;
            first = false;
            if (styles[0] == styles[1])
            {
                srcShape->SkipPathData(&srcPos);
                continue;
            }
            italic.Transform(&coord[0], &coord[1]);
            glyphShape->pShape->StartPath(&dstPos, pathType, styles[0], styles[1], styles[2], coord[0], coord[1]);
            while ((edge = srcShape->ReadEdge(&srcPos, coord)) != Edge_EndPath)
            {
                dst = glyphShape->pShape;
                if (edge == Edge_LineTo)
                {
                    italic.Transform(&coord[0], &coord[1]);
                    dst->LineTo(&dstPos, coord[0], coord[1]);
                }
                else
                {
                    italic.Transform(&coord[0], &coord[1]);
                    italic.Transform(&coord[2], &coord[3]);
                    dst->QuadTo(&dstPos, coord[0], coord[1], coord[2], coord[3]);
                }
            }
            glyphShape->pShape->ClosePath(&dstPos);
            glyphShape->pShape->EndPath();
        }
        glyphShape->pShape->EndShape();
        return;
    }

    bool cw = isOuterContourCW(srcShape);
    mStroker.Clear();
    TmpPath1.Clear();
    mStroker.SetWidth(fauxBold ? nominalSize * Param.FauxBoldRatio : 0.0f);
    StrokeScaler scaler(mStroker, 1, 1000);
    while ((pathType = srcShape->ReadPathInfo(&srcPos, coord, styles)) != Shape_EndShape)
    {
        if (!first && pathType == Shape_NewLayer)
            break;
        first = false;
        if (styles[0] == styles[1])
        {
            srcShape->SkipPathData(&srcPos);
            continue;
        }
        italic.Transform(&coord[0], &coord[1]);
        scaler.AddVertex(coord[0], coord[1]);
        while ((edge = srcShape->ReadEdge(&srcPos, coord)) != Edge_EndPath)
        {
            if (edge == Edge_LineTo)
            {
                italic.Transform(&coord[0], &coord[1]);
                scaler.AddVertex(coord[0], coord[1]);
            }
            else
            {
                italic.Transform(&coord[0], &coord[1]);
                italic.Transform(&coord[2], &coord[3]);
                TessellateQuadCurve(&scaler, param, coord[0], coord[1], coord[2], coord[3]);
            }
        }
        mStroker.ClosePath();
        mStroker.CalcEquidistant(&TmpPath1, cw ? Stroker::DirForward : Stroker::DirBackward);
    }
    TmpPath1.Scale(1, 1.0f / 1000);

    VertexPath* path = &TmpPath1;
    unsigned    i, j;
    if (outline)
    {
        path = &TmpPath2;
        TmpPath2.Clear();
        mStroker.Clear();
        mStroker.SetLineJoin(Stroker::MiterJoin);
        mStroker.SetWidth(float(outline) * Param.OutlineRatio * nominalSize);
        for (i = 0; i < TmpPath1.GetNumPaths(); ++i)
        {
            const PathBasic& p = TmpPath1.GetPath(i);
            if (p.Count <= 2)
                continue;
            for (j = 0; j < p.Count; ++j)
            {
                const VertexBasic& v = TmpPath1.GetVertex(p.Start + j);
                mStroker.AddVertex(v.x, v.y);
            }
            mStroker.ClosePath();
            mStroker.GenerateStroke(&TmpPath2);
        }
    }

    unsigned np = 0;
    for (i = 0; i < path->GetNumPaths(); ++i)
    {
        const PathBasic& p = path->GetPath(i);
        if (p.Count <= 2)
            continue;
        const VertexBasic& v1 = path->GetVertex(p.Start);
        glyphShape->pShape->StartPath(&dstPos, np ? Shape_NewPath : Shape_NewLayer, 1, 0, 0, v1.x, v1.y);
        for (j = 1; j < p.Count; ++j)
        {
            const VertexBasic& v = path->GetVertex(p.Start + j);
            glyphShape->pShape->LineTo(&dstPos, v.x, v.y);
        }
        glyphShape->pShape->ClosePath(&dstPos);
        glyphShape->pShape->EndPath();
        ++np;
    }
    glyphShape->pShape->EndShape();
    mStroker.Clear();
    TmpPath1.Clear();
    TmpPath2.Clear();
    LHeap1.ClearAndRelease();
    LHeap2.ClearAndRelease();
}

// ---- blur / filters on the A8 work raster ----

// a sub-rectangle of the raster seen row by row (X) or column by column (Y), so one blur pass serves both directions
class ImgBlurWrapperX
{
public:
    ImgBlurWrapperX(UByte* img, unsigned pitch, unsigned x, unsigned y, unsigned w, unsigned h)
        : Img(img), Pitch(pitch), Sx(x), Sy(y), W(w), H(h) {}

    unsigned GetWidth() const  { return W; }
    unsigned GetHeight() const { return H; }
    UByte    GetPixel(unsigned x, unsigned y) const { return Img[Pitch * (Sy + y) + Sx + x]; }
    void     CopySpanTo(unsigned x, unsigned y, unsigned len, const UByte* src)
    {
        memcpy(Img + Pitch * (Sy + y) + Sx + x, src, len);
    }

private:
    ImgBlurWrapperX(const ImgBlurWrapperX&);
    void operator=(const ImgBlurWrapperX&);
    UByte*   Img;
    unsigned Pitch;
    unsigned Sx, Sy, W, H;
};

class ImgBlurWrapperY
{
public:
    ImgBlurWrapperY(UByte* img, unsigned pitch, unsigned x, unsigned y, unsigned w, unsigned h)
        : Img(img), Pitch(pitch), Sx(x), Sy(y), W(w), H(h) {}

    unsigned GetWidth() const  { return H; }
    unsigned GetHeight() const { return W; }
    UByte    GetPixel(unsigned x, unsigned y) const { return Img[Pitch * (Sy + x) + Sx + y]; }
    void     CopySpanTo(unsigned x, unsigned y, unsigned len, const UByte* src)
    {
        UByte* p = Img + Pitch * (Sy + x) + Sx + y;
        do
        {
            *p = *src++;
            p += Pitch;
        } while (--len);
    }

private:
    ImgBlurWrapperY(const ImgBlurWrapperY&);
    void operator=(const ImgBlurWrapperY&);
    UByte*   Img;
    unsigned Pitch;
    unsigned Sx, Sy, W, H;
};

// Recursive (IIR) gaussian approximation, one direction: every line runs forward into sum (padded on both sides
// so the tails fade out), then backward into buf, which is copied back over the line.
template<class Img, class SumBuf, class ColorBuf>
void RecursiveBlur(Img& img, float radius, SumBuf& sum, ColorBuf& buf)
{
    if (radius < 0.62f)
        radius = 0.62f;

    int w   = img.GetWidth();
    int h   = img.GetHeight();
    int pad = int(ceilf(radius)) + 3;
    int x, y;

    float s  = radius * 0.5f;
    float q  = (s < 2.5f) ? 3.97156f - 4.14554f * sqrtf(1.0f - 0.26891f * s) : 0.98711f * s - 0.9633f;
    float q2 = q * q;
    float q3 = q2 * q;

    float b0 = 1.0f / (1.57825f + 2.44413f * q + 1.4281f * q2 + 0.422205f * q3);
    float b2 = 2.44413f * q + 2.85619f * q2 + 1.26661f * q3;
    float b3 = -1.4281f * q2 - 1.26661f * q3;
    float b4 = 0.422205f * q3;
    float b1 = 1.0f - (b2 + b3 + b4) * b0;
    b2 *= b0;
    b3 *= b0;
    b4 *= b0;

    sum.Resize(w + 2 * pad);
    buf.Resize(w + 2 * pad);

    for (y = 0; y < h; y++)
    {
        float a1 = 0, a2 = 0, a3 = 0, a4 = 0;

        for (x = 0; x < pad; ++x)
            sum[x] = 0;
        for (x = 0; x < w; ++x)
        {
            a1 = sum[x + pad] = b1 * img.GetPixel(x, y) + b2 * a2 + b3 * a3 + b4 * a4;
            a4 = a3;
            a3 = a2;
            a2 = a1;
        }
        for (x = 0; x < pad; ++x)
        {
            a1 = sum[x + w + pad] = b2 * a2 + b3 * a3 + b4 * a4;
            a4 = a3;
            a3 = a2;
            a2 = a1;
        }

        a1 = a2 = a3 = a4 = 0;
        for (x = w + pad + pad - 1; x >= pad; --x)
        {
            a1 = b1 * sum[x] + b2 * a2 + b3 * a3 + b4 * a4;
            a4 = a3;
            a3 = a2;
            a2 = a1;
            buf[x] = UByte(a1 + 0.5f);
        }
        img.CopySpanTo(0, y, w, &buf[pad]);
    }
}

// @0x1426cb1b0
SF_NOINLINE void GlyphCache::recursiveBlur(UByte* img, unsigned pitch, unsigned sx, unsigned sy, unsigned w, unsigned h,
                               float rx, float ry)
{
    ImgBlurWrapperX rows(img, pitch, sx, sy, w, h);
    RecursiveBlur(rows, rx, BlurSum, BlurStack);
    ImgBlurWrapperY cols(img, pitch, sx, sy, w, h);
    RecursiveBlur(cols, ry, BlurSum, BlurStack);
}

// scales the coverage around bias (a shadow's strength), clamped to a byte
// @0x1426cb510
void GlyphCache::strengthenImage(UByte* img, unsigned pitch, unsigned sx, unsigned sy, unsigned w, unsigned h,
                                 float ratio, int bias)
{
    if (ratio != 1.0f)
    {
        for (unsigned y = 0; y < h; ++y)
        {
            UByte* p = img + (sy + y) * pitch + sx;
            for (unsigned x = 0; x < w; ++x)
            {
                int v = int((int(*p) - bias) * ratio + 0.5f) + bias;
                if (v < 0)
                    v = 0;
                if (v > 255)
                    v = 255;
                *p++ = UByte(v);
            }
        }
    }
}

// spreads every pixel over its neighbours through the scanline filter's tables (at most 256 pixels)
// @0x1426ca120
void GlyphCache::filterScanline(UByte* sl, unsigned w) const
{
    UByte  line[256];
    UByte* src = sl;
    UByte* dst = line;
    if (w > 256)
        w = 256;
    memset(line, 0, w);
    for (unsigned i = 2; i + 2 < w; ++i)
        ScanlineFilter.Filter(src++, dst++);
    memcpy(sl, line, w);
}

// @0x1426cb180
void GlyphCache::rasterTooBigWarning()
{
    if (RasterTooBigWarning)
    {
        LogWarning("Warning: Raster glyph is too big - increase GlyphCacheParams.MaxSlotHeight");
        RasterTooBigWarning = false;
    }
}

// ---- cached glyph sizes ----

// text sizes go up a quarter before they are rounded up to the next ramp step
// @0x1426c7e50
float GlyphCache::SnapFontSizeToRamp(float screenSize) const
{
    unsigned size = unsigned(floor(screenSize));
    size += (size + 3) >> 2;
    if (size <= 255)
        size = FontSizeRamp[FontSizeMap[size] + 1];
    else
        size = 255;
    return float(size);
}

// @0x1426c7ea0
float GlyphCache::SnapShadowSizeToRamp(float screenSize) const
{
    unsigned size = unsigned(floor(screenSize));
    if (size <= 255)
        size = FontSizeRamp[FontSizeMap[size] + 1];
    else
        size = 255;
    return float(size);
}

// readability-optimized text keeps quarter pixels, other text snaps to the ramp; a size that still fits the slots
// once scaled up is clamped to the slot height
// @0x1426c6170
float GlyphCache::GetCachedFontSize(const GlyphParam& gp, float screenSize, bool exactFit) const
{
    if (!exactFit)
    {
        if (!(gp.Flags & GlyphParam::OptRead))
            screenSize = SnapFontSizeToRamp(screenSize);
        else
            screenSize = float(floor(screenSize * 4.0f + 0.5f) * 0.25);
    }
    float maxHeight = float(MaxSlotHeight - 2 * SlotPadding);
    if (screenSize <= maxHeight * Param.MaxRasterScale)
        return (screenSize < maxHeight) ? screenSize : maxHeight;
    return screenSize;
}

// @0x1426c6220
float GlyphCache::GetCachedShadowSize(float screenSize, const GlyphRaster* ras) const
{
    if (ras)
        return float(ras->HintedSize);
    float size      = SnapShadowSizeToRamp(screenSize);
    float maxHeight = float(MaxSlotHeight - 2 * SlotPadding);
    return (size < maxHeight) ? size : maxHeight;
}

// @0x1426c66d0
void GlyphCache::LogError(const char* fmt, ...)
{
    if (pLog)
    {
        va_list args;
        va_start(args, fmt);
        pLog->LogMessageVarg(GlyphCacheLog_Error, fmt, args);
        va_end(args);
    }
}

// @0x1426c6710
void GlyphCache::LogWarning(const char* fmt, ...)
{
    if (pLog)
    {
        va_list args;
        va_start(args, fmt);
        pLog->LogMessageVarg(GlyphCacheLog_Warning, fmt, args);
        va_end(args);
    }
}

}} // namespace Scaleform::Render
// MS2-PIN: ??_G?$ImageFileWriter_Mixin@VAmpGlyphImageWriter@Render@Scaleform@@VImageFileWriter@23@@Render@Scaleform@@UEAAPEAXI@Z 0x1426c2460
// MS2-PIN: ??_7?$ImageFileWriter_Mixin@VAmpGlyphImageWriter@Render@Scaleform@@VImageFileWriter@23@@Render@Scaleform@@6B@ 0x143192d38
// MS2-PIN: ?Write@AmpGlyphImageWriter@Render@Scaleform@@UEBA_NPEAVFile@3@AEBVImageData@23@PEBUImageWriteArgs@23@@Z 0x1426c2490
// MS2-PIN: ??_GAmpGlyphImageWriter@Render@Scaleform@@UEAAPEAXI@Z 0x1426c24b0
// MS2-PIN: ??_7AmpGlyphImageWriter@Render@Scaleform@@6B@ 0x143192d60
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@EU?$AllocatorLH_POD@E$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1426c7da0
