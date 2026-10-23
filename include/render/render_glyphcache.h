// Recovered Scaleform 4.1.18 Render: the glyph cache (Render_GlyphCache, unit sfr_render_06d). It rasterizes glyphs
// into a pool of A8 textures packed by a GlyphQueue, keeps the shared vector glyph shapes, and hands the text mesh
// providers their fills. Layout recovered from the ctor (0x1426c3930) and dtor (0x1426c43c0); the class is 0x1c98
// bytes.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_GLYPHCACHE_H
#define MS2_SF_RENDER_GLYPHCACHE_H

#include "ms2/scaleform/kernel/sf_log.h"
#include "ms2/scaleform/include/kernel/sf_arraypaged.h"
#include "ms2/scaleform/kernel/sf_arrayunsafe.h"
#include "ms2/scaleform/include/render/render_renderer2d.h"
#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/include/render/render_primitive.h"
#include "ms2/scaleform/include/render/render_glyphqueue.h"
#include "ms2/scaleform/include/render/render_fontcachehandle.h"
#include "ms2/scaleform/include/render/render_textmeshprovider.h"
#include "ms2/scaleform/include/render/render_glyphfitter.h"
#include "ms2/scaleform/include/render/render_rasterizer.h"
#include "ms2/scaleform/include/render/render_stroker.h"
#include "ms2/scaleform/include/render/render_hittest.h"
#include "ms2/scaleform/include/render/render_meshcache.h"

namespace Scaleform { namespace Render {

class HAL;
class TextureManager;
class ShapeDataInterface;

// the vertex the HAL draws rasterized glyphs with (position, color, texture coordinates)
struct RasterGlyphVertex
{
    float  x, y;
    UInt32 Color;
    float  u, v;
    void   Set(float x_, float y_, float u_, float v_, UInt32 c) { x = x_; y = y_; Color = c; u = u_; v = v_; }

    static VertexFormat Format;   // 0x143a2fe50
};

// one A8 texture of the pool; tells the cache when the device loses it (0x50 bytes)
class GlyphTextureImage : public TextureImage
{
public:
    GlyphTextureImage(GlyphCache* cache, unsigned textureId, const ImageSize& size, unsigned use);   // 0x1426c41a0

    static GlyphTextureImage* Create(MemoryHeap* heap, TextureManager* texMan, GlyphCache* cache,
                                     unsigned textureId, const ImageSize& size, unsigned use);

    virtual void TextureLost(TextureLossReason reason);      // 0x1426c8090

private:
    GlyphCache* pCache;      // +0x40
    unsigned    TextureId;   // +0x48
};

// how one texture of the pool is written: mapped directly, updated by rectangles, or through a raw copy (0x80 bytes)
class GlyphTextureMapper
{
public:
    GlyphTextureMapper()
        : Valid(false), Method(0), pTexMan(0), pCache(0), TextureId(0), Mapped(false), NumGlyphsToUpdate(0) {}

    bool        Create(unsigned method, MemoryHeap* heap, TextureManager* texMan, PrimitiveFillManager* fillMan,
                       GlyphCache* cache, unsigned textureId, const ImageSize& size);
    ImagePlane* Map();                                                   // 0x1426c6750
    bool        Unmap();                                                 // 0x1426c8250
    bool        Update(const Texture::UpdateDesc* updates, unsigned count);
    Texture*    GetTexture();

    void Invalidate()     { Valid = false; NumGlyphsToUpdate = 0; }
    bool IsValid() const  { return Valid; }

    const PrimitiveFill* GetFill() const { return pFill; }
          PrimitiveFill* GetFill()       { return pFill; }
    Image* GetImage() { return pRawImg.GetPtr() ? (Image*)pRawImg.GetPtr() : (Image*)pTexImg.GetPtr(); }

private:
    bool                   Valid;        // +0x00
    unsigned               Method;       // +0x04, a GlyphCache::TextureUpdateMethod
    TextureManager*        pTexMan;      // +0x08
    GlyphCache*            pCache;       // +0x10
    unsigned               TextureId;    // +0x18
    ImageData              Data;         // +0x20
    Ptr<RawImage>          pRawImg;      // +0x60
    Ptr<GlyphTextureImage> pTexImg;      // +0x68
    Ptr<PrimitiveFill>     pFill;        // +0x70
    bool                   Mapped;       // +0x78
public:
    unsigned               NumGlyphsToUpdate;   // +0x7c
};

// spreads each coverage sample over five neighbours (the LCD-style horizontal filter), 3 x 256 weight tables
class GlyphScanlineFilter
{
public:
    GlyphScanlineFilter(float prim, float second, float tert)
    {
        float k = 1.0f / (prim + second * 2 + tert * 2);
        prim   *= k;
        second *= k;
        tert   *= k;
        for (unsigned i = 0; i < 256; i++)
        {
            Primary[i]   = (UByte)floorf(prim * i);
            Secondary[i] = (UByte)floorf(second * i);
            Tertiary[i]  = (UByte)floorf(tert * i);
        }
    }

    void Filter(const UByte* src, UByte* dst) const
    {
        UByte c = src[2];
        dst[0] = UByte(dst[0] + Tertiary[c]);
        dst[1] = UByte(dst[1] + Secondary[c]);
        dst[2] = UByte(dst[2] + Primary[c]);
        dst[3] = UByte(dst[3] + Secondary[c]);
        dst[4] = UByte(dst[4] + Tertiary[c]);
    }

private:
    UByte Primary[256];
    UByte Secondary[256];
    UByte Tertiary[256];
};

// row-by-row packer of the staging buffer the partial texture updates are copied through
class TextureUpdatePacker
{
public:
    TextureUpdatePacker(unsigned w, unsigned h) : Width(w), Height(h), LastX(0), LastY(0), LastMaxHeight(0) {}

    unsigned GetWidth() const  { return Width; }
    unsigned GetHeight() const { return Height; }

    void Clear() { LastX = 0; LastY = 0; LastMaxHeight = 0; }

    bool Allocate(unsigned w, unsigned h, unsigned* x, unsigned* y)
    {
        if (LastX + w <= Width && LastY + h <= Height)
        {
            *x = LastX;
            *y = LastY;
            LastX += w;
            if (h > LastMaxHeight)
                LastMaxHeight = h;
            return true;
        }
        LastY += LastMaxHeight;
        if (LastY + h <= Height)
        {
            *x = 0;
            *y = LastY;
            LastX = w;
            LastMaxHeight = h;
            return true;
        }
        return false;
    }

private:
    unsigned Width, Height, LastX, LastY, LastMaxHeight;
};

class GlyphCache : public RefCountBase<GlyphCache, Stat_Default_Mem>, public CacheBase, public GlyphCacheConfig
{
    enum { SID = Stat_Default_Mem };
    enum { TexturePoolSize = 32 };

    // the queue's eviction callbacks, forwarded to the cache (vftable 0x143193098)
    class EvictNotifier : public GlyphEvictNotifier
    {
    public:
        GlyphCache* pCache;
        virtual void Evict(TextMeshProvider* tm) { pCache->EvictText(tm); }
        virtual void ApplyInUseList()            { pCache->ApplyInUseList(); }
        virtual bool UpdatePinList()             { return pCache->UpdatePinList(); }
    };

public:
    enum TextureUpdateMethod
    {
        TU_DirectMap,
        TU_MultipleUpdate,
        TU_WholeImage
    };

    enum RasResult
    {
        Res_Success,
        Res_ShapeIsEmpty,
        Res_ShapeNotFound,
        Res_ShapeIsTooBig,
        Res_NoRasterCache,
        Res_CacheFull
    };

    GlyphCache(MemoryHeap* heap);                                           // 0x1426c3930
    ~GlyphCache();                                                          // 0x1426c43c0

    void Initialize(HAL* ren, PrimitiveFillManager* fillMan);               // 0x1426c6660
    void Destroy();                                                         // 0x1426c5f40
    void OnBeginFrame();                                                    // 0x1426c67c0
    void OnEndFrame();

    bool CanReset() const { return TextInPin.IsEmpty(); }

    virtual void                    ClearCache();                           // 0x1426c5180
    virtual bool                    SetParams(const GlyphCacheParams& params);   // 0x1426c7e00
    virtual const GlyphCacheParams& GetParams() const { return Param; }

    MemoryHeap*           GetHeap()                   { return pHeap; }
    TextureManager*       GetTextureManager()         { return pTexMan; }
    PrimitiveFillManager* GetPrimitiveFillManager()   { return pFillMan; }
    float                 GetMaxRasterScale() const   { return Param.MaxRasterScale; }
    float                 GetScaleU() const           { return ScaleU; }
    float                 GetScaleV() const           { return ScaleV; }

    virtual void UnlockBuffers();                                           // 0x1426c8180

    void TextureLost(unsigned textureId, unsigned reason);                  // 0x1426c7fc0
    void CleanUpFont(FontCacheHandle* font);                                // 0x1426c4f10
    void MergeCacheSlots();                                                 // 0x1426c67b0
    void UnpinAllSlots();                                                   // 0x1426c82e0
    void EvictText(TextMeshProvider* tm);
    void ApplyInUseList();                                                  // 0x1426c4e20
    bool UpdatePinList();                                                   // 0x1426c83d0

    void AddToInUseList(TextMeshProvider* tm)   { TextInUse.PushBack(tm); }
    void PinSlot(GlyphSlot* s)                  { Queue.PinSlot(s); }
    void UnpinSlot(GlyphSlot* s, Fence* f)      { Queue.UnpinSlot(s, f); }
    void RemoveNotifier(TextNotifier* n)        { Queue.RemoveNotifier(n); }

    int CmpFills(unsigned texId1, unsigned texId2) const
    {
        if (texId1 == texId2)
            return 0;
        const PrimitiveFill* f1 = Textures[texId1].GetFill();
        const PrimitiveFill* f2 = Textures[texId2].GetFill();
        return (f1 < f2) ? -1 : 1;
    }

    PrimitiveFill*   GetFill(TextLayerType type, unsigned textureId);       // 0x1426c62a0
    Image*           GetImage(unsigned textureId);                          // 0x1426c6380
    FontCacheHandle* RegisterFont(Font* font);                              // 0x1426c7c10

    float      GetCachedFontSize(const GlyphParam& gp, float screenSize, bool exactFit) const;   // 0x1426c6170
    float      GetCachedShadowSize(float screenSize, const GlyphRaster* ras) const;              // 0x1426c6220
    GlyphNode* FindGlyph(TextMeshProvider* tm, const GlyphParam& gp);                            // 0x1426c6110
    GlyphNode* RasterizeGlyph(GlyphRunData& data, TextMeshProvider* tm, const GlyphParam& gp);   // 0x1426c6840
    GlyphNode* RasterizeShadow(GlyphRunData& data, TextMeshProvider* tm, const GlyphParam& gp,
                               float screenSize, const GlyphRaster* ras);                        // 0x1426c6d80

    RasResult GetRasResult() const { return Result; }
    UInt16    GetTextureId(const GlyphNode* node) const { return UInt16(node->pSlot->TextureId & ~GlyphSlot::Mask); }
    unsigned  GetMaxGlyphHeight() const { return Queue.GetMaxSlotHeight(); }

    void LogWarning(const char* fmt, ...);                                  // 0x1426c6710
    void LogError(const char* fmt, ...);                                    // 0x1426c66d0

    unsigned GetRasterizationCount() const { return RasterizationCount; }
    void     ResetRasterizationCount()     { RasterizationCount = 0; }

    VectorGlyphShape* CreateGlyphShape(GlyphRunData& data, unsigned glyphIndex, float screenSize, bool fauxBold,
                                       bool fauxItalic, unsigned outline, bool needsVectorShape = false);   // 0x1426c5700

    float SnapFontSizeToRamp(float screenSize) const;                       // 0x1426c7e50
    float SnapShadowSizeToRamp(float screenSize) const;                     // 0x1426c7ea0
    bool  GlyphFits(unsigned h) const;                                      // 0x1426c6630

    // AMP: writes every valid texture to dataFile, returns how many were written
    int GetTextureData(File* dataFile, UInt32 version);                     // 0x1426c6550

    void     VisitGlyphs(GlyphQueueVisitor* visitor) const { Queue.VisitGlyphs(visitor); }
    unsigned GetNumRasterizedGlyphs() const { return Queue.GetNumPacked(); }
    unsigned ComputeUsedArea() const        { return Queue.ComputeUsedArea(); }
    unsigned ComputeTotalArea() const       { return TextureWidth * TextureHeight * MaxNumTextures; }
    UPInt    GetBytes() const               { return Queue.GetBytes(); }

    // what the text mesh providers reach directly (sfr_render_07o)
    GlyphQueue&             GetQueue()     { return Queue; }
    List<TextMeshProvider>& GetTextInUse() { return TextInUse; }

private:
    void initialize();                                                      // 0x1426ca670

    struct UpdateRect
    {
        unsigned SrcX, SrcY;
        unsigned DstX, DstY;
        unsigned w, h;
        unsigned TextureId;
    };
    typedef Texture::UpdateDesc UpdateDesc;

    void       getGlyphBounds(VectorGlyphShape* glyphShape, const ShapeDataInterface* shape) const;   // 0x1426ca230
    bool       isOuterContourCW(const ShapeDataInterface* shape) const;                              // 0x1426caa80
    void       copyAndTransformShape(VectorGlyphShape* glyphShape, const ShapeDataInterface* srcShape,
                                     bool fauxBold, bool fauxItalic, unsigned outline,
                                     float italicOffset, float nominalSize);                         // 0x1426c8d80
    GlyphNode* allocateGlyph(TextMeshProvider* tm, const GlyphParam& gp, unsigned w, unsigned h);    // 0x1426c8bf0
    GlyphNode* getPrerasterizedGlyph(GlyphRunData& data, TextMeshProvider* tm, const GlyphParam& gp);   // 0x1426ca460
    void       partialUpdateTextures();                                                              // 0x1426cae60
    void       copyImageData(ImagePlane* pl, const UByte* data, unsigned pitch,
                             unsigned dstX, unsigned dstY, unsigned w, unsigned h);                  // 0x1426c9b00
    void       releaseAllTextures();
    void       addShapeToRasterizer(const ShapeDataInterface* shape, float scaleX, float scaleY);    // 0x1426c89a0
    void       addShapeAutoFit(const ShapeDataInterface* shape, unsigned nomHeight, int lowerCaseTop,
                               int upperCaseTop, float screenSize, float stretch);                   // 0x1426c8460
    void       recursiveBlur(UByte* img, unsigned pitch, unsigned sx, unsigned sy,
                             unsigned w, unsigned h, float rx, float ry);                            // 0x1426cb1b0
    void       strengthenImage(UByte* img, unsigned pitch, unsigned sx, unsigned sy,
                               unsigned w, unsigned h, float ratio, int bias);                       // 0x1426cb510
    void       filterScanline(UByte* sl, unsigned w) const;                                          // 0x1426ca120
    void       knockOut(UByte* raster);
    void       cacheFullWarning();                                                                   // 0x1426c8d00
    void       rasterTooBigWarning();                                                                // 0x1426cb180
    bool       checkInitialization();                                                                // 0x1426c8d30
    bool       updateTextureGlyph(const GlyphNode* node);                                            // 0x1426cb6e0
    GlyphNode* createShadowFromRaster(GlyphRunData& data, TextMeshProvider* tm, const GlyphParam& gp,
                                      float screenSize, const GlyphRaster* ras);                     // 0x1426c9ba0

    typedef HashSetLH<Ptr<VectorGlyphShape>, VectorGlyphShape::PtrHashFunctor> VectorGlyphHashSet;

    GlyphCacheParams                         Param;                // +0x20
    MemoryHeap*                              pHeap;                // +0x58
    HAL*                                     pRenderer;            // +0x60
    PrimitiveFillManager*                    pFillMan;             // +0x68
    TextureManager*                          pTexMan;              // +0x70
    unsigned                                 TextureWidth;         // +0x78
    unsigned                                 TextureHeight;        // +0x7c
    unsigned                                 MaxNumTextures;       // +0x80
    unsigned                                 MaxSlotHeight;        // +0x84
    unsigned                                 SlotPadding;          // +0x88
    float                                    ScaleU;               // +0x8c
    float                                    ScaleV;               // +0x90
    float                                    ShadowQuality;        // +0x94
    GlyphTextureMapper                       Textures[TexturePoolSize];   // +0x98
    GlyphQueue                               Queue;                // +0x1098
    TextureUpdateMethod                      Method;               // +0x11e0
    TextureUpdatePacker                      UpdatePacker;         // +0x11e4
    Ptr<RawImage>                            UpdateBuffer;         // +0x11f8
    ArrayPagedLH_POD<UpdateRect, 6, 16, SID> GlyphsToUpdate;       // +0x1200
    ArrayUnsafeLH_POD<UpdateDesc, SID>       RectsToUpdate;        // +0x1228
    List<TextMeshProvider>                   TextInUse;            // +0x1240
    List<TextMeshProvider>                   TextInPin;            // +0x1250
    EvictNotifier                            Notifier;             // +0x1260
    Ptr<FontCacheHandleManager>              pFontHandleManager;   // +0x1270
    RQCacheInterface*                        pRQCaches;            // +0x1278
    Log*                                     pLog;                 // +0x1280
    List<VectorGlyphShape>                   VectorGlyphShapeList; // +0x1288
    VectorGlyphHashSet                       VectorGlyphCache;     // +0x1298
    Ptr<PrimitiveFill>                       pSolidFill;           // +0x12a0
    Ptr<PrimitiveFill>                       pMaskFill;            // +0x12a8
    UByte                                    FontSizeMap[256];     // +0x12b0
    RasResult                                Result;               // +0x13b0
    GlyphFitter                              Fitter;               // +0x13b8
    Rasterizer                               Ras;                  // +0x14d8
    GlyphScanlineFilter                      ScanlineFilter;       // +0x17a8
    ArrayLH_POD<UByte, SID>                  RasterData;           // +0x1aa8
    ArrayLH_POD<UByte, SID>                  RasterDataSrc;        // +0x1ac0
    ArrayLH_POD<UByte, SID>                  KnockOutCopy;         // +0x1ad8
    unsigned                                 RasterPitch;          // +0x1af0
    ArrayLH_POD<UByte, SID>                  BlurStack;            // +0x1af8
    ArrayLH_POD<float, SID>                  BlurSum;              // +0x1b10
    LinearHeap                               LHeap1;               // +0x1b28
    LinearHeap                               LHeap2;               // +0x1b50
    Stroker                                  mStroker;             // +0x1b78
    VertexPath                               TmpPath1;             // +0x1bd0
    VertexPath                               TmpPath2;             // +0x1c30
    unsigned                                 RasterizationCount;   // +0x1c90
    bool                                     RasterCacheWarning;   // +0x1c94
    bool                                     RasterTooBigWarning;  // +0x1c95
};

}} // namespace Scaleform::Render

#endif
