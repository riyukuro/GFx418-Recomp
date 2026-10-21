// Recovered Scaleform 4.1.18 Render: DrawableImage (BitmapData's image: a texture the renderer and the CPU both
// draw into), its per-movie DrawableImageContext, and the command queue that defers drawing operations to the
// render thread (DICommand_* records packed into queue pages, DICommandQueue, DICommandSet).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layouts are the exe's (MapleStory2 KMS2_DEV x64):
//   DrawableImageContext 0xb8 (vftables 0x14318cd58 / ContextCaptureNotify part 0x14318cd68),
//   DrawableImage 0xc8 (vftable 0x14318cd88: the Image slots, GetRenderTarget 29, IsExternal 30),
//   DICommandQueue 0x110, DICommand vftable 0x14318ce80 and the per-command pairs (DICommandImpl<D> / D) after it.
// Bodies: sfr_render_02i (Render_DrawableImage), except the queue machinery and the ExecuteHW/ExecuteSW bodies
// (Render_DrawableImage_Queue/_HW/_SW, sfr_render_04) and a few DrawableImage members linked into the gap at
// 0x1425eeef0-0x1425ef560 (SetPixel32/SetPixel/SetPixels/TextureLost/Threshold/Unmap/addToCPUModifiedList and the
// SourceRect clip helper).
#ifndef MS2_SF_RENDER_DRAWABLEIMAGE_H
#define MS2_SF_RENDER_DRAWABLEIMAGE_H

#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/include/render/render_context.h"
#include "ms2/scaleform/include/render/render_threadcommand.h"
#include "ms2/scaleform/include/render/render_cxform.h"
#include "ms2/scaleform/include/render/render_filters.h"
#include "ms2/scaleform/include/render/render_buffer.h"
#include "ms2/scaleform/include/render/render_constants.h"

namespace Scaleform { namespace Render {

class TreeRoot;
class TreeNode;
class Renderer2D;
class DrawableImage;
class DICommandQueue;
class DICommandSet;
class DIPixelProvider;
struct DICommand;
struct DIQueuePage;

// Movie-level owner of the drawable images: the capture hooks of the movie's context drive the queues, and the
// tree roots built for Draw() live in a context of its own (RContext).
class DrawableImageContext : public RefCountBase<DrawableImageContext, Stat_Default_Mem>,
                             public ContextCaptureNotify
{
    friend class DrawableImage;
    friend class DICommandQueue;

public:
    DrawableImageContext(Context* controlContext, ThreadCommandQueue* queue, const Interfaces& defaults = Interfaces());
    ~DrawableImageContext();

    void                SetQueue(ThreadCommandQueue* queue) { pRTCommandQueue = queue; }
    ThreadCommandQueue* GetQueue() const                    { return pRTCommandQueue; }
    Context*            GetControlContext() const           { return pControlContext; }

    // What the render thread reports, with the context's own defaults taking precedence.
    void GetRenderInterfacesRT(Interfaces* p)
    {
        pRTCommandQueue->GetRenderInterfaces(p);
        if (IDefaults.pTextureManager)
            p->pTextureManager = IDefaults.pTextureManager;
        if (IDefaults.pHAL)
            p->pHAL = IDefaults.pHAL;
        if (IDefaults.pRenderer2D)
            p->pRenderer2D = IDefaults.pRenderer2D;
        if (IDefaults.RenderThreadID)
            p->RenderThreadID = IDefaults.RenderThreadID;
    }

    virtual void OnCapture();
    virtual void OnNextCapture(ContextImpl::RenderNotify* notify);
    virtual void OnShutdown();
    virtual void ExecuteNextCapture(ContextImpl::RenderNotify* notify);

    void AddCaptureNotify(DICommandQueue* queue);
    void RemoveCaptureNotify(DICommandQueue* queue);
    void AddTreeRootToKillList(TreeRoot* root);

protected:
    void processTreeRootKillList();

    Context*            RContext;          // +0x30
    Context*            pControlContext;   // +0x38
    ThreadCommandQueue* pRTCommandQueue;   // +0x40

    Lock*                getLock() { return &TreeRootKillListLock; }
    Lock                 TreeRootKillListLock;   // +0x48
    ArrayLH<TreeRoot*>   TreeRootKillList;       // +0x70
    List<DICommandQueue> QueueList;              // +0x88

private:
    Interfaces IDefaults;                        // +0x98
};

class DrawableImage : public Image, public ListNode<DrawableImage>
{
    friend class Texture;
    friend class DICommandSet;
    friend class DICommandQueue;
    friend struct DICommand;
    friend struct DICommand_CreateTexture;
    friend struct DICommand_Map;
    friend struct DICommand_Unmap;

public:
    enum DrawableImageStateFlags
    {
        DIState_Mapped      = 0x01,   // texture data mapped from the GPU (render thread)
        DIState_MappedRead  = 0x02,   // mapped for reading only
        DIState_UserMapped  = 0x04,   // mapped through Map() by the user
        DIState_CPUDirty    = 0x08,   // modified by a CPU command (on the queue's CPU-modified list)
        DIState_GPUDirty    = 0x10,   // modified by a GPU command (on the queue's GPU-modified list)
        DIState_CmdPending  = 0x20,
        DIState_ForceRemap  = 0x40    // map again after the staging copy
    };
    enum ChannelBits
    {
        Channel_Red   = 0x01,
        Channel_Green = 0x02,
        Channel_Blue  = 0x04,
        Channel_Alpha = 0x08
    };
    enum OperationType
    {
        Operator_LT,
        Operator_LE,
        Operator_GT,
        Operator_GE,
        Operator_EQ,
        Operator_NE
    };

    DrawableImage(bool transparent, ImageBase* delegateImage, DrawableImageContext* context);
    DrawableImage(ImageFormat format, ImageSize size, bool transparent, Color fillColor,
                  DrawableImageContext* context);
    ~DrawableImage();

    bool                  IsTransparent() const { return Transparent; }
    DrawableImageContext* GetContext() const    { return pContext; }
    static bool           MapImageSource(ImageData* data, ImageBase* image, bool rtMap);
    // MapImageSource's body, force-inlined where the exe inlines it (HitTest against a rectangle)
    static bool           mapImageSourceInline(ImageData* data, ImageBase* image, bool rtMap);

    // The BitmapData operations.
    void ApplyFilter(DrawableImage* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                     Filter* filter);
    static void CalcFilterRect(RectF* result, const Rect<SInt32>& sourceRect, Filter* filter);
    void ColorTransform(const Rect<SInt32>& rect, const Cxform& cxform);
    void Compare(DrawableImage* image0, DrawableImage* image1);
    void CopyChannel(DrawableImage* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                     ChannelBits sourceChannel, ChannelBits destChannel);
    void CopyPixels(DrawableImage* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                    DrawableImage* alphaSource = 0, const Point<SInt32>* alphaPoint = 0, bool mergeAlpha = false);
    void Draw(TreeNode* subtree, const Matrix2F& matrix, const Cxform& cxform, BlendMode blendMode = Blend_None,
              const Rect<SInt32>* clipRect = 0);
    void Draw(Image* source, const Matrix2F& matrix, const Cxform& cxform, BlendMode blendMode = Blend_None,
              const Rect<SInt32>* clipRect = 0, bool smoothing = false);
    void FillRect(const Rect<SInt32>& rect, Color color);
    void FloodFill(const Point<SInt32>& pt, Color color);
    Rect<SInt32> GetColorBoundsRect(UInt32 mask, UInt32 color, bool findColor);
    Color GetPixel(SInt32 x, SInt32 y);
    Color GetPixel32(SInt32 x, SInt32 y);
    bool  GetPixels(DIPixelProvider& provider, const Rect<SInt32>& sourceRect);
    void  Histogram(Rect<SInt32>* rect, unsigned colors[4][256]);
    bool  HitTest(const Point<SInt32>& firstPoint, const Rect<SInt32>& secondRect, unsigned firstThreshold);
    bool  HitTest(ImageBase* secondImage, const Point<SInt32>& firstPoint, const Point<SInt32>& secondPoint,
                  unsigned firstThreshold, unsigned secondThreshold);
    void  Merge(DrawableImage* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                unsigned redMultiplier, unsigned greenMultiplier, unsigned blueMultiplier, unsigned alphaMultiplier);
    void  Noise(unsigned randomSeed, unsigned low = 0, unsigned high = 255, unsigned channelMask = 7,
                bool grayScale = false);
    void  PaletteMap(DrawableImage* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                     UInt32** channels);
    void  PerlinNoise(float frequencyX, float frequencyY, unsigned numOctaves, unsigned randomSeed, bool stitch,
                      bool fractal, unsigned channelMask, bool grayScale, float* offsets = 0, unsigned offsetCount = 0);
    unsigned PixelDissolve(DrawableImage* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                           unsigned randomSeed, unsigned numPixels, Color fill);
    void  Scroll(int x, int y);
    bool  SetPixel(SInt32 x, SInt32 y, Color c);
    bool  SetPixel32(SInt32 x, SInt32 y, Color c);
    bool  SetPixels(const Rect<SInt32>& destRect, DIPixelProvider& provider);
    void  Threshold(DrawableImage* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                    OperationType op, UInt32 threshold, UInt32 color, UInt32 mask, bool copySource);

    virtual ImageType   GetImageType() const   { return Type_DrawableImage; }
    virtual ImageFormat GetFormat() const      { return Format; }
    virtual unsigned    GetUse() const         { return 0; }
    virtual ImageSize   GetSize() const        { return ISize; }
    virtual unsigned    GetMipmapCount() const { return 1; }
    virtual bool        Map(ImageData* pdata, unsigned levelIndex = 0, unsigned levelCount = 0);
    virtual bool        Unmap();
    virtual Texture*    GetTexture(TextureManager* manager);
    virtual bool        Decode(ImageData*, CopyScanlineFunc = CopyScanlineDefault, void* = 0) const { return false; }
    virtual Image*      GetAsImage()           { return this; }
    virtual UInt32      GetImageId() const     { return ImageId; }
    virtual UInt32      GetBaseImageId() const { return 0; }
    virtual void        TextureLost(TextureLossReason reason);
    virtual RenderTarget* GetRenderTarget() const { return pRT; }   // 29
    virtual UPInt         IsExternal() const      { return 0; }     // 30

protected:
    bool createTextureFromManager(HAL* phal, TextureManager* manager);
    bool mapTextureRT(bool readOnly, bool forceRemap = false);
    void unmapTextureRT();   // exe 0x1425f0590
    void updateRenderTargetRT();
    void updateStagingTargetRT();
    void internalMapAndFlush(bool needMap = true);
    bool mergeQueueWith(Image* other);
    template<class C>
    void addCommand(const C& cmd);
    void addToCPUModifiedList();
    void addToGPUModifiedListRT();
    bool isRenderableRT() const { return pRT != 0; }
    bool ensureRenderableRT();
    void initialize(ImageFormat format, const ImageSize& size, DrawableImageContext* context);

private:
    ImageFormat                 Format;               // +0x38
    ImageSize                   ISize;                // +0x3c (left uninitialized by the ctors)
    volatile unsigned           DrawableImageState;   // +0x44
    bool                        Transparent;          // +0x48
    Ptr<DICommandQueue>         pQueue;               // +0x50
    ImageData                   MappedData;           // +0x58
    Ptr<DrawableImage>          pCPUModifiedNext;     // +0x98
    Ptr<DrawableImage>          pGPUModifiedNext;     // +0xa0
    UInt32                      ImageId;              // +0xa8
    Ptr<ImageBase>              pDelegateImage;       // +0xb0
    Ptr<DrawableImageContext>   pContext;             // +0xb8
    Ptr<RenderTarget>           pRT;                  // +0xc0
};

// Pixel source/sink for GetPixels / SetPixels (ARGB values in scan order).
class DIPixelProvider
{
public:
    virtual ~DIPixelProvider() {}
    virtual UPInt  GetLength() const = 0;
    virtual UInt32 ReadNextPixel() = 0;
    virtual void   WriteNextPixel(UInt32 v) = 0;
};

// ---------------------------------------------------------------------------------------------------------------
// Commands

enum DICommandType
{
    DICommandType_Map,
    DICommandType_Unmap,
    DICommandType_CreateTexture,
    DICommandType_Clear,
    DICommandType_ApplyFilter,
    DICommandType_Draw,
    DICommandType_CopyChannel,
    DICommandType_CopyPixels,
    DICommandType_ColorTransform,
    DICommandType_Compare,
    DICommandType_FillRect,
    DICommandType_FloodFill,
    DICommandType_Merge,
    DICommandType_Noise,
    DICommandType_PaletteMap,
    DICommandType_PerlinNoise,
    DICommandType_Scroll,
    DICommandType_Threshold
};

struct DICommandContext
{
    Renderer2D* pR2D;
    HAL*        pHAL;

    DICommandContext() : pR2D(0), pHAL(0) {}
};

// The images a command reads from (merged into the destination's queue before it is queued).
struct DISourceImages
{
    Image* pImages[2];

    DISourceImages() { pImages[1] = 0; pImages[0] = 0; }
    Image* operator[](int i) const { return pImages[i]; }
};

// vftable: dtor 0, GetType 1, HasCPUImplementation 2, GetRenderCaps 3, GetSize 4, GetSourceImages 5,
// ExecuteHW 6, ExecuteSW 7.
struct DICommand
{
    friend class DICommandSet;

    DICommand(DrawableImage* image = 0) : pImage(image) {}
    virtual ~DICommand() {}

    virtual DICommandType GetType() const = 0;
    virtual unsigned      HasCPUImplementation() const = 0;
    virtual unsigned      GetRenderCaps() const;
    virtual unsigned      GetSize() const = 0;
    virtual unsigned      GetSourceImages(DISourceImages*) const { return 0; }

    bool ExecuteSWOnAddCommand(DrawableImage* image) const;

    virtual void ExecuteHW(DICommandContext&) const {}
    virtual void ExecuteSW(DICommandContext&, ImageData&, ImageData** = 0) const {}

protected:
    Ptr<DrawableImage> pImage;   // +0x08
};

template<class D, class B = DICommand>
struct DICommandImpl : public B
{
    DICommandImpl() {}
    DICommandImpl(DrawableImage* image) : B(image) {}
    DICommandImpl(const DICommandImpl& other) : B(other) {}
    virtual unsigned GetSize() const { return sizeof(D); }
};

struct DICommand_Map : public DICommandImpl<DICommand_Map>
{
    bool ReadOnlyMapping;   // +0x10
    bool ForceRemapping;    // +0x11

    DICommand_Map(DrawableImage* image, bool readOnly, bool forced = false)
        : DICommandImpl<DICommand_Map>(image), ReadOnlyMapping(readOnly), ForceRemapping(forced)
    {
    }
    virtual DICommandType GetType() const              { return DICommandType_Map; }
    virtual unsigned      HasCPUImplementation() const { return false; }
    virtual void ExecuteHW(DICommandContext&) const { pImage->mapTextureRT(ReadOnlyMapping, ForceRemapping); }
};

struct DICommand_CreateTexture : public DICommandImpl<DICommand_CreateTexture>
{
    DICommand_CreateTexture(DrawableImage* image) : DICommandImpl<DICommand_CreateTexture>(image) {}
    DICommand_CreateTexture(const DICommand_CreateTexture& other)
        : DICommandImpl<DICommand_CreateTexture>(other.pImage)
    {
    }
    virtual DICommandType GetType() const              { return DICommandType_CreateTexture; }
    virtual unsigned      HasCPUImplementation() const { return false; }
    virtual void ExecuteHW(DICommandContext& context) const;
};

struct DICommand_Clear : public DICommandImpl<DICommand_Clear>
{
    Color FillColor;   // +0x10

    DICommand_Clear(DrawableImage* image, Color color) : DICommandImpl<DICommand_Clear>(image), FillColor(color) {}
    DICommand_Clear(const DICommand_Clear& other)
        : DICommandImpl<DICommand_Clear>(other.pImage), FillColor(other.FillColor)
    {
    }
    virtual DICommandType GetType() const              { return DICommandType_Clear; }
    virtual unsigned      HasCPUImplementation() const { return true; }
    virtual void ExecuteHW(DICommandContext& context) const;
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
};

// A command reading a rectangle of a source image. vftable adds UpdateClippedRects 8.
struct DICommand_SourceRect : public DICommand
{
    Ptr<DrawableImage> pSource;             // +0x10
    Rect<SInt32>       SourceRect;          // +0x18
    Point<SInt32>      DestPoint;           // +0x28
    Rect<SInt32>       ClippedSourceRect;   // +0x30

    DICommand_SourceRect(DrawableImage* image, DrawableImage* source, const Rect<SInt32>& sourceRect,
                         const Point<SInt32>& destPoint)
        : DICommand(image), pSource(source), SourceRect(sourceRect), DestPoint(destPoint),
          ClippedSourceRect(sourceRect)
    {
        UpdateClippedRects();
    }
    DICommand_SourceRect(const DICommand_SourceRect& other)
        : DICommand(other.pImage), pSource(other.pSource), SourceRect(other.SourceRect),
          DestPoint(other.DestPoint), ClippedSourceRect(other.SourceRect)
    {
        UpdateClippedRects();
    }

    // Trims the right/bottom edges to the source image (exe copy 0x1425ef3d0).
    // MS2-FUNCTIONAL: x2/y2 land in swapped registers (r9/r10) against the exe copy
    virtual void UpdateClippedRects()
    {
        ImageSize size = pSource->GetSize();
        SInt32 overX = SourceRect.x2 - (SInt32)size.Width;
        SInt32 overY = SourceRect.y2 - (SInt32)size.Height;
        ClippedSourceRect.x2 = SourceRect.x2 - Alg::Max<SInt32>(overX, 0);
        ClippedSourceRect.y2 = SourceRect.y2 - Alg::Max<SInt32>(overY, 0);
    }
    virtual unsigned GetSourceImages(DISourceImages* ps) const
    {
        ps->pImages[0] = pSource;
        return 1;
    }
};

// vftable adds ExecuteHWGetImages 9, ExecuteHWCopyAction 10, GetRequireSourceRead 11.
template<class D>
struct DICommand_SourceRectImpl : public DICommand_SourceRect
{
    DICommand_SourceRectImpl(DrawableImage* image, DrawableImage* source, const Rect<SInt32>& sourceRect,
                             const Point<SInt32>& destPoint)
        : DICommand_SourceRect(image, source, sourceRect, destPoint)
    {
    }
    DICommand_SourceRectImpl(const DICommand_SourceRectImpl& other) : DICommand_SourceRect(other) {}

    virtual unsigned GetSize() const { return sizeof(D); }
    virtual void     ExecuteHW(DICommandContext& context) const;

    // The destination first when the operation also reads it, then the source; offsets are where they are read.
    virtual void ExecuteHWGetImages(DrawableImage** images, Size<float>* readOffsets) const
    {
        unsigned i = 0;
        if (GetRequireSourceRead())
        {
            images[i]      = pImage;
            readOffsets[i] = Size<float>((float)DestPoint.x, (float)DestPoint.y);
            i++;
        }
        images[i]      = pSource;
        readOffsets[i] = Size<float>((float)SourceRect.x1, (float)SourceRect.y1);
    }
    virtual void ExecuteHWCopyAction(DICommandContext&, Texture**, const Matrix2F*) const {}
    virtual bool GetRequireSourceRead() const { return false; }
};

struct DICommand_ApplyFilter : public DICommand_SourceRectImpl<DICommand_ApplyFilter>
{
    Ptr<Filter> pFilter;   // +0x40

    DICommand_ApplyFilter(DrawableImage* image, DrawableImage* source, const Rect<SInt32>& sourceRect,
                          const Point<SInt32>& destPoint, Filter* filter)
        : DICommand_SourceRectImpl<DICommand_ApplyFilter>(image, source, sourceRect, destPoint), pFilter(filter)
    {
    }
    DICommand_ApplyFilter(const DICommand_ApplyFilter& other)
        : DICommand_SourceRectImpl<DICommand_ApplyFilter>(other), pFilter(other.pFilter)
    {
    }
    virtual DICommandType GetType() const              { return DICommandType_ApplyFilter; }
    virtual unsigned      HasCPUImplementation() const { return false; }
    virtual void ExecuteHWGetImages(DrawableImage** images, Size<float>* readOffsets) const;
    virtual void ExecuteHWCopyAction(DICommandContext& context, Texture** tex, const Matrix2F* texgen) const;
    virtual bool GetRequireSourceRead() const { return false; }
};

struct DICommand_Draw : public DICommandImpl<DICommand_Draw>
{
    TreeRoot*    pRoot;         // +0x10
    Rect<SInt32> ClipRect;      // +0x18
    bool         HasClipRect;   // +0x28

    DICommand_Draw(DrawableImage* image, TreeRoot* root, const Rect<SInt32>* clipRect);
    DICommand_Draw(const DICommand_Draw& other)
        : DICommandImpl<DICommand_Draw>(other.pImage), pRoot(other.pRoot), ClipRect(other.ClipRect),
          HasClipRect(other.HasClipRect)
    {
    }
    virtual DICommandType GetType() const              { return DICommandType_Draw; }
    virtual unsigned      HasCPUImplementation() const { return false; }
    virtual void ExecuteHW(DICommandContext& context) const;
};

struct DICommand_CopyChannel : public DICommand_SourceRectImpl<DICommand_CopyChannel>
{
    typedef DrawableImage::ChannelBits ChannelBits;
    ChannelBits SourceChannel;   // +0x40
    ChannelBits DestChannel;     // +0x44

    DICommand_CopyChannel(DrawableImage* image, DrawableImage* source, const Rect<SInt32>& sourceRect,
                          const Point<SInt32>& destPoint, ChannelBits sourceChannel, ChannelBits destChannel)
        : DICommand_SourceRectImpl<DICommand_CopyChannel>(image, source, sourceRect, destPoint),
          SourceChannel(sourceChannel), DestChannel(destChannel)
    {
    }
    virtual DICommandType GetType() const              { return DICommandType_CopyChannel; }
    virtual unsigned      HasCPUImplementation() const { return true; }
    virtual void ExecuteHWCopyAction(DICommandContext& context, Texture** tex, const Matrix2F* texgen) const;
    virtual bool GetRequireSourceRead() const { return true; }
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
};

struct DICommand_CopyPixels : public DICommand_SourceRectImpl<DICommand_CopyPixels>
{
    Ptr<DrawableImage> pAlphaSource;   // +0x40
    Point<SInt32>      AlphaPoint;     // +0x48
    bool               MergeAlpha;     // +0x50

    DICommand_CopyPixels(DrawableImage* image, DrawableImage* source, const Rect<SInt32>& sourceRect,
                         const Point<SInt32>& destPoint, DrawableImage* alphaSource,
                         const Point<SInt32>* alphaPoint, bool mergeAlpha)
        : DICommand_SourceRectImpl<DICommand_CopyPixels>(image, source, sourceRect, destPoint),
          pAlphaSource(alphaSource), AlphaPoint(alphaPoint ? *alphaPoint : Point<SInt32>(0, 0)),
          MergeAlpha(mergeAlpha)
    {
    }
    DICommand_CopyPixels(const DICommand_CopyPixels& other)
        : DICommand_SourceRectImpl<DICommand_CopyPixels>(other), pAlphaSource(other.pAlphaSource),
          AlphaPoint(other.AlphaPoint), MergeAlpha(other.MergeAlpha)
    {
    }
    virtual DICommandType GetType() const              { return DICommandType_CopyPixels; }
    virtual unsigned      HasCPUImplementation() const { return true; }
    virtual unsigned GetSourceImages(DISourceImages* ps) const
    {
        unsigned count = 1;
        ps->pImages[0] = pSource;
        if (pAlphaSource)
        {
            ps->pImages[1] = pAlphaSource;
            count++;
        }
        return count;
    }
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    virtual void ExecuteHWGetImages(DrawableImage** images, Size<float>* readOffsets) const;
    virtual void ExecuteHWCopyAction(DICommandContext& context, Texture** tex, const Matrix2F* texgen) const;
    virtual bool GetRequireSourceRead() const { return true; }
    virtual void Execute(DICommandContext&) const {}   // 12
};

struct DICommand_ColorTransform : public DICommand_SourceRectImpl<DICommand_ColorTransform>
{
    Cxform Cx;   // +0x40

    DICommand_ColorTransform(DrawableImage* image, const Rect<SInt32>& rect, const Cxform& cxform)
        : DICommand_SourceRectImpl<DICommand_ColorTransform>(image, image, rect, Point<SInt32>(rect.x1, rect.y1)),
          Cx(cxform)
    {
    }
    DICommand_ColorTransform(const DICommand_ColorTransform& other)
        : DICommand_SourceRectImpl<DICommand_ColorTransform>(other), Cx(other.Cx)
    {
    }
    virtual DICommandType GetType() const              { return DICommandType_ColorTransform; }
    virtual unsigned      HasCPUImplementation() const { return true; }
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    virtual void ExecuteHWCopyAction(DICommandContext& context, Texture** tex, const Matrix2F* texgen) const;
    virtual bool GetRequireSourceRead() const { return true; }
};

struct DICommand_Compare : public DICommand_SourceRectImpl<DICommand_Compare>
{
    Ptr<DrawableImage> pImageCompare1;   // +0x40

    DICommand_Compare(DrawableImage* image, DrawableImage* image0, DrawableImage* image1)
        : DICommand_SourceRectImpl<DICommand_Compare>(image, image0, imageRect(image->GetSize()), Point<SInt32>(0, 0)),
          pImageCompare1(image1)
    {
    }
    static Rect<SInt32> imageRect(const ImageSize& size) { return Rect<SInt32>(0, 0, size.Width, size.Height); }
    DICommand_Compare(const DICommand_Compare& other)
        : DICommand_SourceRectImpl<DICommand_Compare>(other), pImageCompare1(other.pImageCompare1)
    {
    }
    virtual DICommandType GetType() const              { return DICommandType_Compare; }
    virtual unsigned      HasCPUImplementation() const { return true; }
    virtual unsigned GetSourceImages(DISourceImages* ps) const
    {
        ps->pImages[0] = pSource;
        ps->pImages[1] = pImageCompare1;
        return 2;
    }
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    virtual void ExecuteHWCopyAction(DICommandContext& context, Texture** tex, const Matrix2F* texgen) const;
    virtual bool GetRequireSourceRead() const { return pSource == pImage || pImageCompare1 == pImage; }
};

struct DICommand_FillRect : public DICommandImpl<DICommand_FillRect>
{
    Rect<SInt32> ApplyRect;   // +0x10
    Color        FillColor;   // +0x20

    DICommand_FillRect(DrawableImage* image, const Rect<SInt32>& rect, Color color)
        : DICommandImpl<DICommand_FillRect>(image), ApplyRect(rect), FillColor(color)
    {
    }
    DICommand_FillRect(const DICommand_FillRect& other)
        : DICommandImpl<DICommand_FillRect>(other.pImage), ApplyRect(other.ApplyRect), FillColor(other.FillColor)
    {
    }
    virtual DICommandType GetType() const              { return DICommandType_FillRect; }
    virtual unsigned      HasCPUImplementation() const { return true; }
    virtual void ExecuteHW(DICommandContext& context) const;
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
};

struct DICommand_FloodFill : public DICommandImpl<DICommand_FloodFill>
{
    Point<SInt32> Pt;          // +0x10
    Color         FillColor;   // +0x18

    DICommand_FloodFill(DrawableImage* image, const Point<SInt32>& pt, Color color)
        : DICommandImpl<DICommand_FloodFill>(image), Pt(pt), FillColor(color)
    {
    }
    DICommand_FloodFill(const DICommand_FloodFill& other)
        : DICommandImpl<DICommand_FloodFill>(other.pImage), Pt(other.Pt), FillColor(other.FillColor)
    {
    }
    virtual DICommandType GetType() const              { return DICommandType_FloodFill; }
    virtual unsigned      HasCPUImplementation() const { return true; }
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
};

struct DICommand_Merge : public DICommand_SourceRectImpl<DICommand_Merge>
{
    unsigned RedMultiplier;     // +0x40
    unsigned GreenMultiplier;
    unsigned BlueMultiplier;
    unsigned AlphaMultiplier;

    DICommand_Merge(DrawableImage* image, DrawableImage* source, const Rect<SInt32>& sourceRect,
                    const Point<SInt32>& destPoint, unsigned rmul, unsigned gmul, unsigned bmul, unsigned amul)
        : DICommand_SourceRectImpl<DICommand_Merge>(image, source, sourceRect, destPoint),
          RedMultiplier(rmul), GreenMultiplier(gmul), BlueMultiplier(bmul), AlphaMultiplier(amul)
    {
    }
    DICommand_Merge(const DICommand_Merge& other)
        : DICommand_SourceRectImpl<DICommand_Merge>(other), RedMultiplier(other.RedMultiplier),
          GreenMultiplier(other.GreenMultiplier), BlueMultiplier(other.BlueMultiplier),
          AlphaMultiplier(other.AlphaMultiplier)
    {
    }
    virtual DICommandType GetType() const              { return DICommandType_Merge; }
    virtual unsigned      HasCPUImplementation() const { return true; }
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    virtual void ExecuteHWCopyAction(DICommandContext& context, Texture** tex, const Matrix2F* texgen) const;
    virtual bool GetRequireSourceRead() const { return true; }
};

struct DICommand_Noise : public DICommandImpl<DICommand_Noise>
{
    unsigned RandomSeed;    // +0x10
    unsigned Low;
    unsigned High;
    unsigned ChannelMask;
    bool     GrayScale;     // +0x20

    DICommand_Noise(DrawableImage* image, unsigned randomSeed, unsigned low, unsigned high, unsigned channelMask,
                    bool grayScale)
        : DICommandImpl<DICommand_Noise>(image), RandomSeed(randomSeed), Low(low), High(high),
          ChannelMask(channelMask), GrayScale(grayScale)
    {
    }
    DICommand_Noise(const DICommand_Noise& other)
        : DICommandImpl<DICommand_Noise>(other.pImage), RandomSeed(other.RandomSeed), Low(other.Low),
          High(other.High), ChannelMask(other.ChannelMask), GrayScale(other.GrayScale)
    {
    }
    virtual DICommandType GetType() const              { return DICommandType_Noise; }
    virtual unsigned      HasCPUImplementation() const { return true; }
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
};

struct DICommand_PaletteMap : public DICommand_SourceRectImpl<DICommand_PaletteMap>
{
    enum { ChannelSize = 256 * sizeof(UInt32), PaletteSize = 4 * ChannelSize };

    UInt32*  Channels;      // +0x40, the four 256-entry maps back to back
    unsigned ChannelMask;   // +0x48

    DICommand_PaletteMap(DrawableImage* image, DrawableImage* source, const Rect<SInt32>& sourceRect,
                         const Point<SInt32>& destPoint, UInt32** channels);
    DICommand_PaletteMap(const DICommand_PaletteMap& other)
        : DICommand_SourceRectImpl<DICommand_PaletteMap>(other), ChannelMask(other.ChannelMask)
    {
        Channels = (UInt32*)SF_ALLOC(PaletteSize, Stat_Default_Mem);
        memcpy(Channels, other.Channels, PaletteSize);
    }
    ~DICommand_PaletteMap()
    {
        if (Channels)
            SF_FREE(Channels);
        Channels = 0;
    }
    virtual DICommandType GetType() const              { return DICommandType_PaletteMap; }
    virtual unsigned      HasCPUImplementation() const { return true; }
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    virtual void ExecuteHWCopyAction(DICommandContext& context, Texture** tex, const Matrix2F* texgen) const;
    virtual bool GetRequireSourceRead() const { return pImage == pSource; }
};

struct DICommand_PerlinNoise : public DICommandImpl<DICommand_PerlinNoise>
{
    enum { MaximumOffsetOctaves = 16 };

    float    FrequencyX, FrequencyY;          // +0x10
    unsigned NumOctaves;
    unsigned RandomSeed;
    bool     Stitch;                          // +0x20
    bool     FractalNoise;
    unsigned ChannelMask;                     // +0x24
    bool     GrayScale;                       // +0x28
    float    Offsets[MaximumOffsetOctaves * 2];   // +0x2c
    unsigned OffsetCount;                     // +0xac

    DICommand_PerlinNoise(DrawableImage* image, float frequencyX, float frequencyY, unsigned numOctaves,
                          unsigned randomSeed, bool stitch, bool fractal, unsigned channelMask, bool grayScale,
                          float* offsets, unsigned offsetCount);
    DICommand_PerlinNoise(const DICommand_PerlinNoise& other)
        : DICommandImpl<DICommand_PerlinNoise>(other), FrequencyX(other.FrequencyX), FrequencyY(other.FrequencyY),
          NumOctaves(other.NumOctaves), RandomSeed(other.RandomSeed), Stitch(other.Stitch),
          FractalNoise(other.FractalNoise), ChannelMask(other.ChannelMask), GrayScale(other.GrayScale),
          OffsetCount(other.OffsetCount)
    {
        if (other.OffsetCount)
            memcpy(Offsets, other.Offsets, other.OffsetCount * sizeof(float));
    }
    virtual DICommandType GetType() const              { return DICommandType_PerlinNoise; }
    virtual unsigned      HasCPUImplementation() const { return true; }
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
};

struct DICommand_Scroll : public DICommand_SourceRectImpl<DICommand_Scroll>
{
    int X;   // +0x40
    int Y;   // +0x44

    DICommand_Scroll(DrawableImage* image, int x, int y);
    DICommand_Scroll(const DICommand_Scroll& other) : DICommand_SourceRectImpl<DICommand_Scroll>(other), X(other.X), Y(other.Y) {}
    virtual DICommandType GetType() const              { return DICommandType_Scroll; }
    virtual unsigned      HasCPUImplementation() const { return true; }
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    virtual void ExecuteHWCopyAction(DICommandContext& context, Texture** tex, const Matrix2F* texgen) const;
    virtual bool GetRequireSourceRead() const { return true; }
};

struct DICommand_Threshold : public DICommand_SourceRectImpl<DICommand_Threshold>
{
    DrawableImage::OperationType Operation;        // +0x40
    UInt32                       Threshold;
    UInt32                       ThresholdColor;
    UInt32                       Mask;
    bool                         CopySource;       // +0x50

    DICommand_Threshold(DrawableImage* image, DrawableImage* source, const Rect<SInt32>& sourceRect,
                        const Point<SInt32>& destPoint, DrawableImage::OperationType op, UInt32 threshold,
                        UInt32 color, UInt32 mask, bool copySource)
        : DICommand_SourceRectImpl<DICommand_Threshold>(image, source, sourceRect, destPoint), Operation(op),
          Threshold(threshold), ThresholdColor(color), Mask(mask), CopySource(copySource)
    {
    }
    DICommand_Threshold(const DICommand_Threshold& other)
        : DICommand_SourceRectImpl<DICommand_Threshold>(other), Operation(other.Operation),
          Threshold(other.Threshold), ThresholdColor(other.ThresholdColor), Mask(other.Mask),
          CopySource(other.CopySource)
    {
    }
    virtual DICommandType GetType() const              { return DICommandType_Threshold; }
    virtual unsigned      HasCPUImplementation() const { return true; }
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    virtual void ExecuteHWCopyAction(DICommandContext& context, Texture** tex, const Matrix2F* texgen) const;
    virtual bool GetRequireSourceRead() const { return CopySource; }
};

// ---------------------------------------------------------------------------------------------------------------
// Queue

enum DICommandSetType
{
    DICommand_All,
    DICommand_Displaying
};

// The pages popped off a queue for one execution pass.
class DICommandSet
{
    friend class DICommandQueue;

public:
    DICommandSet(DICommandQueue* queue) : pQueue(queue) {}

    void ExecuteCommandsRT(DICommandContext& context);
    void ExecuteCommandsMT(DICommandContext& context);
    bool IsEmpty() const { return QueueList.IsEmpty(); }

private:
    DICommandQueue*   pQueue;
    List<DIQueuePage> QueueList;
};

// Commands of a group of images that share one queue (the images drawn from each other get merged into one).
class DICommandQueue : public RefCountBase<DICommandQueue, Stat_Default_Mem>, public ListNode<DICommandQueue>
{
    friend class DICommandSet;
    friend struct DICommand;

public:
    DICommandQueue(DrawableImageContext* context);
    ~DICommandQueue();

    template<class C>
    bool AddCommand_NTS(const C& cmd)
    {
        void* buffer = allocCommandFromPage(sizeof(C), &QueueLock);
        if (!buffer)
            return false;
        Construct<C>(buffer, cmd);
        return true;
    }
    template<class C>
    bool AddCommand(const C& cmd)
    {
        Lock::Locker lock(&QueueLock);
        return AddCommand_NTS(cmd);
    }

    void OnCapture();
    void OnNextCapture(ContextImpl::RenderNotify* notify);
    void OnShutdown();

    // Runs the queue on the render thread and blocks until it is done.
    void ExecuteCommandsAndWait()
    {
        AddRef();
        ExecuteCmd->AddRef();
        pRTCommandQueue->PushThreadCommand(ExecuteCmd);
        ExecuteCmd->WaitDoneAndReset();
    }

    class ExecuteCommand : public ThreadCommand
    {
    public:
        DICommandQueue* pQueue;        // +0x10
        Event           ExecuteDone;   // +0x18

        ExecuteCommand(DICommandQueue* queue) : pQueue(queue) {}
        virtual void Execute();
        void WaitDoneAndReset()
        {
            ExecuteDone.Wait();
            ExecuteDone.ResetEvent();
        }
    };

protected:
    friend class ExecuteCommand;
    friend class DrawableImage;

    void* allocCommandFromPage(unsigned size, Lock* locked);
    void  popCommandSet(DICommandSet* cmdSet, DICommandSetType type);
    bool  isQueueEmpty_NTS() const;
    bool  isCPURenderable_NTS();

    Mutex                     CommandSetMutex;         // +0x20
    WaitCondition             CommandSetWC;            // +0x48
    DICommandSet*             pRTCommands;             // +0x50
    DICommandSet*             pATCommands;             // +0x58
    List<DrawableImage>       ImageList;               // +0x60
    Ptr<DrawableImageContext> pDIContext;              // +0x70
    Ptr<DrawableImage>        pCPUModifiedImageList;   // +0x78
    Ptr<DrawableImage>        pGPUModifiedImageList;   // +0x80
    ThreadCommandQueue*       pRTCommandQueue;         // +0x88
    Lock                      QueueLock;               // +0x90
    Ptr<ExecuteCommand>       ExecuteCmd;              // +0xb8
    List<DIQueuePage>         Queues[4];               // +0xc0
    unsigned                  CaptureFrameId;          // +0x100
    unsigned                  FreePageCount;           // +0x104
    unsigned                  AllocPageCount;          // +0x108
};

// Unmaps a drawable image's texture on the render thread (pushed when the image dies elsewhere).
class UnmapTextureThreadCommand : public ThreadCommand
{
public:
    Ptr<Texture> pTexture;   // +0x10

    UnmapTextureThreadCommand(Texture* texture) : pTexture(texture) {}
    virtual void Execute()
    {
        if (pTexture)
            pTexture->Unmap();
    }
};

}} // namespace Scaleform::Render

#endif
