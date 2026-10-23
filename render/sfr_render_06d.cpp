// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the glyph cache TU
// (Render_GlyphCache). The cache rasterizes glyphs (hinted or auto-fitted, faux bold / italic, outlined, blurred or
// knocked-out shadows) into a pool of A8 textures packed by its GlyphQueue, writes them through the texture mapping
// method the device supports (direct map, partial updates through a staging image, or a whole raw image), keeps
// the shared vector glyph shapes keyed by font / glyph / style, and hands the text mesh providers their fills.
// Queue unit sfr_render_06 is split along its original sources (06d Render_GlyphCache); the flattened path's
// out-of-line members (Render_VertexPath, just ahead of it) live here too, the cache's scratch paths emit its vtable.
// MS2-UNIT: sfr_render_06d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426c21b0-0x1426c2460 .text$mn
// MS2-RANGE: 0x1426c24e0-0x1426c51f0 .text$mn
// MS2-RANGE: 0x1426c5700-0x1426c7da0 .text$mn
// MS2-RANGE: 0x1426c7e00-0x1426cba30 .text$mn

#include "ms2/scaleform/include/render/render_glyphcache.h"
#include "ms2/scaleform/include/render/render_hal.h"
#include "ms2/scaleform/include/render/render_imagefile.h"

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
// MS2-FUNCTIONAL: the hash's chain fix-up copies the next entry through its out-of-line copy ctor in the exe, inline here
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
class AmpGlyphImageWriter : public ImageFileWriter
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
