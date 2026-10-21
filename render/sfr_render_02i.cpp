// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the drawable image TU
// (Render_DrawableImage): BitmapData's image and its movie-level context. The BitmapData operations build a
// DICommand_* record and queue it (after merging the queues of the images it reads); mapping flushes the queue,
// on this thread when its commands are CPU-renderable and through the render thread otherwise.
// Queue unit sfr_render_02 is split along its original sources (sfr_render_02 Matrix2x4 + CxForm, 02b Gradients,
// 02c Filters, 02d TGA reader, 02e DDS reader, 02f PNG reader, 02g JPEG reader, 02h ScreenToWorld,
// 02i DrawableImage).
// MS2-UNIT: sfr_render_02i
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425e8420-0x1425eeef0 .text$mn
// MS2-RANGE: 0x1425ef560-0x1425f0690 .text$mn

#include "ms2/scaleform/include/render/render_drawableimage.h"
#include "ms2/scaleform/include/render/render_hal.h"
#include "ms2/scaleform/include/render/render_treeshape.h"
#include "ms2/scaleform/include/render/render_shapedatafloatmp.h"
#include "ms2/scaleform/include/render/render_gradients.h"

// The exe keeps these out of line where our compiler would inline them (GetPixel32 into GetPixel,
// MapImageSource into mapTextureRT, mapTextureRT into updateStagingTargetRT).
#define MS2_SF_NOINL __declspec(noinline)

namespace Scaleform { namespace Render {

// ---------------------------------------------------------------------------------------------------------------
// Command constructors (out of line or inlined into the operations below)

// @0x1425e93d0
DICommand_Draw::DICommand_Draw(DrawableImage* image, TreeRoot* root, const Rect<SInt32>* clipRect)
    : DICommandImpl<DICommand_Draw>(image), pRoot(root), HasClipRect(clipRect != 0)
{
    // all four edges are read before any is stored
    if (clipRect)
        ClipRect.SetRect(clipRect->x1, clipRect->y1, clipRect->x2, clipRect->y2);
}

inline DICommand_PaletteMap::DICommand_PaletteMap(DrawableImage* image, DrawableImage* source,
                                                  const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                                                  UInt32** channels)
    : DICommand_SourceRectImpl<DICommand_PaletteMap>(image, source, sourceRect, destPoint), ChannelMask(0)
{
    Channels = (UInt32*)SF_ALLOC(PaletteSize, Stat_Default_Mem);
    memset(Channels, 0, PaletteSize);
    for (unsigned i = 0; i < 4; i++)
    {
        if (channels[i])
        {
            ChannelMask |= 1 << i;
            memcpy(Channels + i * 256, channels[i], ChannelSize);
        }
    }
}

inline DICommand_PerlinNoise::DICommand_PerlinNoise(DrawableImage* image, float frequencyX, float frequencyY,
                                                    unsigned numOctaves, unsigned randomSeed, bool stitch,
                                                    bool fractal, unsigned channelMask, bool grayScale,
                                                    float* offsets, unsigned offsetCount)
    : DICommandImpl<DICommand_PerlinNoise>(image), FrequencyX(frequencyX), FrequencyY(frequencyY),
      NumOctaves(numOctaves), RandomSeed(randomSeed), Stitch(stitch), FractalNoise(fractal),
      ChannelMask(channelMask), GrayScale(grayScale)
{
    OffsetCount = Alg::Min<unsigned>(offsetCount, MaximumOffsetOctaves);
    if (offsetCount)
        memcpy(Offsets, offsets, offsetCount * sizeof(float));
}

inline DICommand_Scroll::DICommand_Scroll(DrawableImage* image, int x, int y)
    : DICommand_SourceRectImpl<DICommand_Scroll>(image, image,
                                                 Rect<SInt32>(0, 0, image->GetSize().Width, image->GetSize().Height),
                                                 Point<SInt32>(x, y)),
      X(x), Y(y)
{
}

// ---------------------------------------------------------------------------------------------------------------
// DrawableImage

// The images the command reads join this image's queue first; a command the CPU can run right away is not queued.
template<class C>
void DrawableImage::addCommand(const C& cmd)
{
    DISourceImages images;
    if (cmd.GetSourceImages(&images))
    {
        if (images[0] && !mergeQueueWith(images[0]))
            return;
        if (images[1] && !mergeQueueWith(images[1]))
            return;
    }
    if (cmd.ExecuteSWOnAddCommand(this))
        return;
    pQueue->AddCommand(cmd);
}

// Threshold (linked into the 0x1425eeef0 gap) queues through this instance; its COMDAT is kept in this range.
template void DrawableImage::addCommand<DICommand_Threshold>(const DICommand_Threshold& cmd);
// The same for the Draw command.
template void DrawableImage::addCommand<DICommand_Draw>(const DICommand_Draw& cmd);

// @0x1425e9810
DrawableImage::DrawableImage(ImageFormat format, ImageSize size, bool transparent, Color fillColor,
                             DrawableImageContext* context)
    : ISize(ImageSize::NoInit), DrawableImageState(0), Transparent(transparent)
{
    initialize(format, size, context);
    if (!Transparent)
        fillColor.SetAlpha(0xFF);
    addCommand(DICommand_Clear(this, fillColor));
}

// @0x1425e9a00
DrawableImage::DrawableImage(bool transparent, ImageBase* delegateImage, DrawableImageContext* context)
    : ISize(ImageSize::NoInit), DrawableImageState(0), Transparent(transparent)
{
    pDelegateImage = delegateImage;
    initialize(delegateImage->GetFormat(), delegateImage->GetSize(), context);
}

// @0x1425e9d00
DrawableImage::~DrawableImage()
{
    // A texture still mapped is unmapped on the render thread.
    if (DrawableImageState & (DIState_Mapped | DIState_MappedRead))
    {
        Interfaces rifs;
        pContext->GetRenderInterfacesRT(&rifs);
        if (rifs.RenderThreadID == GetCurrentThreadId())
            unmapTextureRT();
        else
        {
            Ptr<UnmapTextureThreadCommand> cmd = *SF_NEW UnmapTextureThreadCommand(pTexture);
            pContext->GetQueue()->PushThreadCommand(cmd);
        }
    }

    DICommandQueue* queue = pQueue;
    {
        Lock::Locker lock(&queue->QueueLock);
        RemoveNode();
    }
    pQueue = 0;
}

// Reads sourceRect row by row into the provider; false if the rectangle leaves the image.
// @0x1425ecdf0
bool DrawableImage::GetPixels(DIPixelProvider& provider, const Rect<SInt32>& sourceRect)
{
    Rect<SInt32> bounds(0, 0, ISize.Width, ISize.Height);
    if (bounds.x2 < sourceRect.x2 || bounds.y2 < sourceRect.y2 || sourceRect.x1 < bounds.x1 || sourceRect.y1 < bounds.y1)
        return false;

    internalMapAndFlush();
    for (SInt32 y = sourceRect.y1; y < sourceRect.y2; ++y)
    {
        UByte* scanline = MappedData.GetScanline(y);
        for (SInt32 x = sourceRect.x1; x < sourceRect.x2; ++x)
            provider.WriteNextPixel(MappedData.GetPixelInScanline(scanline, x).ToColor32());
    }
    return true;
}

// @0x1425ed1a0
Texture* DrawableImage::GetTexture(TextureManager* manager)
{
    if (pDelegateImage && pDelegateImage->GetImageType() != Type_ImageBase &&
        pDelegateImage->GetImageType() != Type_Other)
        return ((Image*)pDelegateImage.GetPtr())->GetTexture(manager);
    return pTexture;
}

static inline Rect<SInt32> sizeRect(const ImageSize& size)
{
    return Rect<SInt32>(0, 0, size.Width, size.Height);
}

// Per-channel population counts over rect (the whole image when null), clipped to the image.
// MS2-FUNCTIONAL: the exe keeps the GetSize/pixel temporaries in the caller's home area (0x20 smaller frame), shifting registers
// @0x1425ed440
void DrawableImage::Histogram(Rect<SInt32>* rect, unsigned colors[4][256])
{
    internalMapAndFlush();
    memset(colors, 0, sizeof(unsigned) * 4 * 256);
    Rect<SInt32> hrect = rect ? *rect : sizeRect(GetSize());
    for (SInt32 y = Alg::Max<SInt32>(0, hrect.y1); y < Alg::Min<SInt32>(GetSize().Height, hrect.y2); ++y)
    {
        for (SInt32 x = Alg::Max<SInt32>(0, hrect.x1); x < Alg::Min<SInt32>(GetSize().Width, hrect.x2); ++x)
        {
            UInt32 c = GetPixel32(x, y).ToColor32();
            colors[2][(UByte)c]++;
            c >>= 8;
            colors[1][(UByte)c]++;
            c >>= 8;
            colors[0][(UByte)c]++;
            colors[3][c >> 8]++;
        }
    }
}

// Alpha test of this image against secondRect placed at firstPoint (this image mapped inline).
// @0x1425ed5e0
bool DrawableImage::HitTest(const Point<SInt32>& firstPoint, const Rect<SInt32>& secondRect, unsigned firstThreshold)
{
    internalMapAndFlush();
    ImageData data;
    if (mapImageSourceInline(&data, this, false))
    {
        Size<SInt32> dims(Alg::Min<SInt32>(GetSize().Width, secondRect.Width()),
                          Alg::Min<SInt32>(GetSize().Height, secondRect.Height()));
        for (SInt32 y = 0; y < dims.Height; ++y)
        {
            for (SInt32 x = 0; x < dims.Width; ++x)
            {
                // the row offset is taken from secondRect.x1 as in the exe
                Color c = data.GetPixel(secondRect.x1 - firstPoint.x + x, secondRect.x1 - firstPoint.y + y);
                if (c.GetAlpha() >= firstThreshold)
                    return true;
            }
        }
    }
    return false;
}

// Alpha test of this image at firstPoint against secondImage at secondPoint.
// @0x1425ed800
bool DrawableImage::HitTest(ImageBase* secondImage, const Point<SInt32>& firstPoint, const Point<SInt32>& secondPoint,
                            unsigned firstThreshold, unsigned secondThreshold)
{
    internalMapAndFlush();
    ImageData data[2];
    if (MapImageSource(&data[0], this, false) && MapImageSource(&data[1], secondImage, false))
    {
        ImageSize dims(Alg::Min(GetSize().Width - firstPoint.x, secondImage->GetSize().Width - secondPoint.x),
                       Alg::Min(GetSize().Height - firstPoint.y, secondImage->GetSize().Height - secondPoint.y));
        for (SInt32 y = 0; y < (SInt32)dims.Height; ++y)
        {
            for (SInt32 x = 0; x < (SInt32)dims.Width; ++x)
            {
                Color c0 = data[0].GetPixel(secondPoint.x - firstPoint.x + x, secondPoint.y - firstPoint.y + y);
                if (c0.GetAlpha() < firstThreshold)
                    continue;
                Color c1 = data[1].GetPixel(x, y);
                if (c1.GetAlpha() >= secondThreshold)
                    return true;
            }
        }
    }
    return false;
}

// @0x1425eda30
bool DrawableImage::Map(ImageData* pdata, unsigned levelIndex, unsigned levelCount)
{
    Lock::Locker lock(&pQueue->QueueLock);
    internalMapAndFlush();
    DrawableImageState |= DIState_UserMapped;
    if (!pdata->Initialize(MappedData, levelIndex, levelCount))
    {
        Unmap();
        return false;
    }
    return true;
}

__forceinline bool DrawableImage::mapImageSourceInline(ImageData* data, ImageBase* image, bool rtMap)
{
    if (!data || !image)
        return false;

    if (image->GetImageType() == Type_DrawableImage)
    {
        DrawableImage* dimage = (DrawableImage*)image;
        if (!(dimage->DrawableImageState & (DIState_Mapped | DIState_MappedRead)))
        {
            if (rtMap)
            {
                if (!dimage->mapTextureRT(true))
                    return false;
            }
            else
            {
                dimage->pQueue->AddCommand(DICommand_Map(dimage, true));
                dimage->pQueue->ExecuteCommandsAndWait();
                if (!(dimage->DrawableImageState & (DIState_Mapped | DIState_MappedRead)))
                    return false;
            }
        }
        *data = dimage->MappedData;
        return true;
    }

    if (image->GetImageType() == Type_RawImage &&
        (image->GetFormat() == Image_B8G8R8A8 || image->GetFormat() == Image_R8G8B8A8))
    {
        ((RawImage*)image)->GetImageData(data);
        return true;
    }
    return false;
}

// The pixels of a drawable image (mapped first) or of a raw 32-bit image.
// @0x1425edae0
MS2_SF_NOINL bool DrawableImage::MapImageSource(ImageData* data, ImageBase* image, bool rtMap)
{
    return mapImageSourceInline(data, image, rtMap);
}

// MS2-FUNCTIONAL: the exe guards this frame with a /GS security cookie our build does not emit (frame layout and register saves shift with it)
// @0x1425eaff0
void DrawableImage::ApplyFilter(DrawableImage* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                                Filter* filter)
{
    addCommand(DICommand_ApplyFilter(this, source, sourceRect, destPoint, filter));
}

// MS2-FUNCTIONAL: the exe guards this frame with a /GS security cookie our build does not emit (frame layout and register saves shift with it)
// @0x1425eb180
void DrawableImage::CalcFilterRect(RectF* result, const Rect<SInt32>& sourceRect, Filter* filter)
{
    RectF bounds((float)sourceRect.x1, (float)sourceRect.y1, (float)sourceRect.x2, (float)sourceRect.y2);
    TreeNode::NodeData::expandByFilterBounds(filter, &bounds);
    if (result)
        *result = bounds;
}

// @0x1425eb200
void DrawableImage::ColorTransform(const Rect<SInt32>& rect, const Cxform& cxform)
{
    addCommand(DICommand_ColorTransform(this, rect, cxform));
}

// MS2-FUNCTIONAL: the exe guards this frame with a /GS security cookie our build does not emit (frame layout and register saves shift with it)
// @0x1425eb390
void DrawableImage::Compare(DrawableImage* image0, DrawableImage* image1)
{
    addCommand(DICommand_Compare(this, image0, image1));
}

// MS2-FUNCTIONAL: the exe guards this frame with a /GS security cookie our build does not emit (frame layout and register saves shift with it)
// @0x1425eb570
void DrawableImage::CopyChannel(DrawableImage* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                                ChannelBits sourceChannel, ChannelBits destChannel)
{
    addCommand(DICommand_CopyChannel(this, source, sourceRect, destPoint, sourceChannel, destChannel));
}

// MS2-FUNCTIONAL: the exe guards this frame with a /GS security cookie our build does not emit (frame layout and register saves shift with it)
// @0x1425eb700
void DrawableImage::CopyPixels(DrawableImage* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                               DrawableImage* alphaSource, const Point<SInt32>* alphaPoint, bool mergeAlpha)
{
    addCommand(DICommand_CopyPixels(this, source, sourceRect, destPoint, alphaSource, alphaPoint, mergeAlpha));
}

// The viewport of a Draw root: the clip rectangle (or the whole image) of a render target the image's size.
static inline void setTargetViewport(TreeRoot* root, const Rect<SInt32>& area, const ImageSize& size)
{
    Viewport vp;
    vp.BufferWidth   = size.Width;
    vp.BufferHeight  = size.Height;
    vp.Left          = area.x1;
    vp.Top           = area.y1;
    vp.Width         = area.Width();
    vp.Height        = area.Height();
    vp.ScissorLeft   = vp.ScissorTop = vp.ScissorWidth = vp.ScissorHeight = 0;
    vp.Flags         = Viewport::View_IsRenderTexture;
    root->SetViewport(vp);
}

// MS2-FUNCTIONAL: the exe guards this frame with a /GS security cookie and keeps TreeContainer::Add, StartLayer, LineTo and EndPath out of line; the rectangle's closing edge is an explicit test (the exe compares the start and last points)
// @0x1425eb8c0
void DrawableImage::Draw(Image* source, const Matrix2F& matrix, const Cxform& cxform, BlendMode blendMode,
                         const Rect<SInt32>* clipRect, bool smoothing)
{
    SF_UNUSED(smoothing);   // 4.1.18 leaves the fill on its default sampling
    if (!pContext || !pContext->RContext)
        return;

    Ptr<TreeRoot> root = *pContext->RContext->CreateEntry<TreeRoot>();
    if (!root)
        return;
    Ptr<TreeShape> shape = *pContext->RContext->CreateEntry<TreeShape>();
    root->Add(shape);

    // The source becomes the image fill of one rectangle its own size.
    FillStyleType fill;
    fill.Color = 0;
    fill.pFill = *SF_NEW ComplexFill();
    fill.pFill->pImage    = source;
    fill.pFill->BindIndex = ~0u;

    Ptr<ShapeDataFloatMP> shapeData = *SF_NEW ShapeDataFloatMP();
    shapeData->AddFillStyle(fill);
    shapeData->StartLayer();
    shapeData->StartPath(1, 0, 0);
    shapeData->RectanglePath(0, 0, (float)source->GetSize().Width, (float)source->GetSize().Height);
    shapeData->CountLayers();

    TreeShape::NodeData* data = shape->GetWritableData(Change_Shape);
    data->pMeshProvider       = shapeData;
    shape->AddToPropagate();

    setTargetViewport(root, clipRect ? *clipRect : sizeRect(GetSize()), GetSize());
    root->SetMatrix(matrix);
    shape->SetMatrix(Matrix2F::Identity);
    shape->SetCxform(cxform);
    shape->SetBlendMode(blendMode);

    root->AddRef();
    if (pContext->GetControlContext())
        pContext->GetControlContext()->SetDIChangesRequired();
    pContext->OnCapture();
    addCommand(DICommand_Draw(this, root, clipRect));
}

// MS2-FUNCTIONAL: the exe guards this frame with a /GS security cookie and keeps TreeContainer::Add out of line (our build inlines it)
// @0x1425ebf70
void DrawableImage::Draw(TreeNode* subtree, const Matrix2F& matrix, const Cxform& cxform, BlendMode blendMode,
                         const Rect<SInt32>* clipRect)
{
    if (!pContext || !pContext->RContext)
        return;

    // A private root in the image context holds a clone of the subtree; the render thread draws it into the texture.
    Ptr<TreeRoot> root = *pContext->RContext->CreateEntry<TreeRoot>();
    if (!root)
        return;
    Ptr<TreeNode> child = *subtree->Clone(pContext->RContext);
    root->Add(child);

    setTargetViewport(root, clipRect ? *clipRect : sizeRect(GetSize()), GetSize());
    root->SetMatrix(matrix);
    child->SetMatrix(Matrix2F::Identity);
    child->SetCxform(cxform);
    child->SetBlendMode(blendMode);

    // The command owns this reference until the render thread is done with the root.
    root->AddRef();
    if (pContext->GetControlContext())
        pContext->GetControlContext()->SetDIChangesRequired();
    pContext->OnCapture();
    addCommand(DICommand_Draw(this, root, clipRect));
}


// MS2-FUNCTIONAL: the exe guards this frame with a /GS security cookie our build does not emit (frame layout and register saves shift with it)
// @0x1425ec860
void DrawableImage::FillRect(const Rect<SInt32>& rect, Color color)
{
    addCommand(DICommand_FillRect(this, rect, color));
}

// @0x1425ec9e0
void DrawableImage::FloodFill(const Point<SInt32>& pt, Color color)
{
    addCommand(DICommand_FloodFill(this, pt, color));
}

// Scans the mapped pixels on the calling thread; an opaque image ignores the alpha bits of the mask.
// MS2-FUNCTIONAL: the exe stores found=false before the first GetSize call and keeps the match test as two branches
// @0x1425ecb50
Rect<SInt32> DrawableImage::GetColorBoundsRect(UInt32 mask, UInt32 color, bool findColor)
{
    internalMapAndFlush();
    UInt32 useMask = Transparent ? mask : (mask & 0x00FFFFFF);
    Rect<SInt32> bounds(GetSize().Width, GetSize().Height, 0, 0);
    bool found = false;
    for (unsigned y = 0; y < GetSize().Height; ++y)
    {
        for (unsigned x = 0; x < GetSize().Width; ++x)
        {
            Color c = GetPixel32(x, y);
            if (findColor ? ((c.ToColor32() & useMask) == color) : ((c.ToColor32() & useMask) != color))
            {
                found = true;
                bounds.x1 = Alg::Min<SInt32>(bounds.x1, x);
                bounds.y1 = Alg::Min<SInt32>(bounds.y1, y);
                bounds.x2 = Alg::Max<SInt32>(bounds.x2, x + 1);
                bounds.y2 = Alg::Max<SInt32>(bounds.y2, y + 1);
            }
        }
    }
    if (found)
        return bounds;
    return Rect<SInt32>(0, 0, 0, 0);
}

// @0x1425ecdd0
Color DrawableImage::GetPixel(SInt32 x, SInt32 y)
{
    Color c = GetPixel32(x, y);
    c.SetAlpha(0);
    return c;
}

// @0x1425ecd50
Color DrawableImage::GetPixel32(SInt32 x, SInt32 y)
{
    if ((unsigned)x >= ISize.Width || (unsigned)y >= ISize.Height)
        return Color(0);
    internalMapAndFlush();
    return MappedData.GetPixelInScanline(MappedData.GetScanline(y), x);
}

// MS2-FUNCTIONAL: the exe guards this frame with a /GS security cookie our build does not emit (frame layout and register saves shift with it)
// @0x1425edc00
void DrawableImage::Merge(DrawableImage* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                          unsigned redMultiplier, unsigned greenMultiplier, unsigned blueMultiplier,
                          unsigned alphaMultiplier)
{
    addCommand(DICommand_Merge(this, source, sourceRect, destPoint, redMultiplier, greenMultiplier, blueMultiplier,
                               alphaMultiplier));
}

// @0x1425eddc0
void DrawableImage::Noise(unsigned randomSeed, unsigned low, unsigned high, unsigned channelMask, bool grayScale)
{
    addCommand(DICommand_Noise(this, randomSeed, low, high, channelMask, grayScale));
}

// MS2-FUNCTIONAL: the exe guards this frame with a /GS security cookie our build does not emit (frame layout and register saves shift with it)
// @0x1425ee140
void DrawableImage::PaletteMap(DrawableImage* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                               UInt32** channels)
{
    addCommand(DICommand_PaletteMap(this, source, sourceRect, destPoint, channels));
}

// @0x1425ee4d0
void DrawableImage::PerlinNoise(float frequencyX, float frequencyY, unsigned numOctaves, unsigned randomSeed,
                                bool stitch, bool fractal, unsigned channelMask, bool grayScale, float* offsets,
                                unsigned offsetCount)
{
    addCommand(DICommand_PerlinNoise(this, frequencyX, frequencyY, numOctaves, randomSeed, stitch, fractal,
                                     channelMask, grayScale, offsets, offsetCount));
}

// Feedback taps of the maximal-length LFSR used by PixelDissolve, indexed by the bit width of the pixel count.
static const UInt32 PixelDissolveTaps[24] =
{
    0x1, 0x3, 0x6, 0xc, 0x14, 0x30, 0x30, 0xb8, 0x110, 0x240, 0x500, 0xe08,
    0x1c80, 0x3802, 0x6000, 0xb400, 0x9000, 0x20400, 0x72000, 0x90000, 0x140000, 0x300000, 0x420000, 0xe10000
};

// Visits numPixels pseudo-random pixels of the area (an LFSR sequence continued from randomSeed): fills them with
// fill when dissolving in place, otherwise copies them from the source rect. Returns the next seed.
// MS2-FUNCTIONAL: the exe inlines the first MapImageSource (forcing that here outlines DICommand_Map's dtor in
// MapImageSource itself); register allocation and loop shapes differ too (numPixels counted down in a 64-bit register)
// @0x1425ee720
unsigned DrawableImage::PixelDissolve(DrawableImage* source, const Rect<SInt32>& sourceRect,
                                      const Point<SInt32>& destPoint, unsigned randomSeed, unsigned numPixels,
                                      Color fill)
{
    internalMapAndFlush();
    ImageData dest;
    if (!MapImageSource(&dest, this, false))
        return 0;
    addToCPUModifiedList();

    if (source == this)
    {
        SInt32 width  = dest.GetWidth();
        SInt32 height = dest.GetHeight();
        if (height < sourceRect.y1 || sourceRect.y2 < 0 || sourceRect.x2 < 0 || width < sourceRect.x1)
            return 0;
        SInt32 w = Alg::Min<SInt32>(sourceRect.x2, width) - Alg::Max<SInt32>(sourceRect.x1, 0);
        unsigned total = (Alg::Min<SInt32>(sourceRect.y2, height) - Alg::Max<SInt32>(sourceRect.y1, 0)) * w;
        unsigned bits = 0;
        while (total > (1u << bits))
            bits++;
        SInt32 seed = randomSeed;
        for (unsigned i = 0; i < numPixels; i++)
        {
            do
                seed = (seed >> 1) ^ (-(seed & 1) & PixelDissolveTaps[bits]);
            while ((unsigned)seed > total);
            unsigned index = seed - 1;
            dest.SetPixelARGB(index % w, index / w, fill.ToColor32());
        }
        return seed;
    }

    // (the exe maps this image again as the copy source)
    ImageData src;
    if (!MapImageSource(&src, this, false))
        return 0;
    SInt32 w = dest.GetWidth() - destPoint.x - destPoint.x;
    SInt32 h = dest.GetHeight() - destPoint.y - destPoint.y;
    if (w <= 0 || h <= 0)
        return 0;
    SInt32 srcWidth  = src.GetWidth();
    SInt32 srcHeight = src.GetHeight();
    if (sourceRect.y2 < 0 || srcHeight < sourceRect.y1 || srcWidth < sourceRect.x1 || sourceRect.x2 < 0)
        return 0;
    w = Alg::Min<SInt32>(w, Alg::Min<SInt32>(sourceRect.x2, srcWidth) - Alg::Max<SInt32>(sourceRect.x1, 0));
    h = Alg::Min<SInt32>(h, Alg::Min<SInt32>(sourceRect.y2, srcHeight) - Alg::Max<SInt32>(sourceRect.y1, 0));
    unsigned total = h * w;
    unsigned bits = 0;
    while (total > (1u << bits))
        bits++;
    SInt32 seed = randomSeed;
    for (unsigned i = 0; i < numPixels; i++)
    {
        do
            seed = (seed >> 1) ^ (-(seed & 1) & PixelDissolveTaps[bits]);
        while ((unsigned)seed > total);
        unsigned index = seed - 1;
        unsigned x = index % w, y = index / w;
        Color c = src.GetPixel(sourceRect.x1 + x, sourceRect.y1 + y);
        dest.SetPixelARGB(destPoint.x + x, destPoint.y + y, c.ToColor32());
    }
    return seed;
}

// MS2-FUNCTIONAL: the exe guards this frame with a /GS security cookie our build does not emit (frame layout and register saves shift with it)
// @0x1425eed00
void DrawableImage::Scroll(int x, int y)
{
    addCommand(DICommand_Scroll(this, x, y));
}

// @0x1425ef560
void DrawableImage::addToGPUModifiedListRT()
{
    Lock::Locker lock(&pQueue->QueueLock);
    if (DrawableImageState & DIState_GPUDirty)
        return;
    DrawableImageState |= DIState_GPUDirty;
    pGPUModifiedNext = pQueue->pGPUModifiedImageList;
    pQueue->pGPUModifiedImageList = this;
}

// @0x1425ef610
bool DrawableImage::createTextureFromManager(HAL* phal, TextureManager* manager)
{
    ImageSize texSize(Alg::Max<unsigned>(1, ISize.Width), Alg::Max<unsigned>(1, ISize.Height));
    if (!manager->IsNonPow2Supported(manager->GetDrawableImageFormat(), ImageUse_RenderTarget | ImageUse_MapRenderThread))
    {
        unsigned w = texSize.Width - 1;
        w |= w >> 1;
        w |= w >> 2;
        w |= w >> 4;
        w |= w >> 8;
        w |= w >> 16;
        texSize.Width = w + 1;
        unsigned h = texSize.Height - 1;
        h |= h >> 1;
        h |= h >> 2;
        h |= h >> 4;
        h |= h >> 8;
        h |= h >> 16;
        texSize.Height = h + 1;
    }

    Texture* texture = manager->CreateTexture(Format, 1, texSize, ImageUse_RenderTarget | ImageUse_MapRenderThread,
                                              pDelegateImage ? pDelegateImage.GetPtr() : this);
    if (!texture)
        return false;
    initTexture_NoAddRef(texture);
    pRT = *phal->CreateRenderTarget(texture, false);
    if (!pRT)
        return false;
    return true;
}

// Gives the image a render target: recreated on the existing texture after a device loss, or the delegate image is
// replaced by a texture of our own, its contents drawn (or decoded) into it.
// MS2-FUNCTIONAL: the exe guards this frame with a /GS security cookie our build does not emit (frame layout and register saves shift with it)
// @0x1425ef770
bool DrawableImage::ensureRenderableRT()
{
    if (pRT)
        return true;

    Interfaces rifs;
    pContext->GetRenderInterfacesRT(&rifs);

    ImageSize      imageSize = ISize;
    Ptr<ImageBase> oldDelegate = pDelegateImage;
    Texture*       delegateTexture = 0;

    if (pTexture)
    {
        pRT = *rifs.pHAL->CreateRenderTarget(pTexture, false);
        if (!pRT)
            return false;
    }
    else if (pDelegateImage)
    {
        if (pDelegateImage->GetImageType() == Type_DrawableImage)
            mergeQueueWith(pDelegateImage->GetAsImage());
        imageSize = pDelegateImage->GetSize();
        delegateTexture = pDelegateImage->GetAsImage()->GetTexture(rifs.pTextureManager);
        pDelegateImage = 0;
        initialize(rifs.pTextureManager->GetDrawableImageFormat(), imageSize, pContext);
    }
    if (!pRT)
        return false;

    if (delegateTexture)
    {
        ImageSize rtSize = pRT->GetSize();
        rifs.pHAL->PushRenderTarget(RectF(0, 0, (float)rtSize.Width, (float)rtSize.Height), pRT);
        Matrix2F mvp = Matrix2F::Scaling(2, -2);
        mvp.Prepend(Matrix2F::Translation(-0.5f, -0.5f));
        Matrix2F texgen;
        texgen.AppendScaling((float)pRT->GetSize().Width / (float)pRT->GetBufferSize().Width,
                             (float)pRT->GetSize().Height / (float)pRT->GetBufferSize().Height);
        rifs.pHAL->DrawableCopyback(delegateTexture, mvp, texgen);
        rifs.pHAL->PopRenderTarget();
    }
    else if (oldDelegate)
    {
        if (mapTextureRT(false))
        {
            oldDelegate->Decode(&MappedData);
            unmapTextureRT();
        }
    }
    updateStagingTargetRT();
    return true;
}

// @0x1425efbf0
void DrawableImage::initialize(ImageFormat format, const ImageSize& size, DrawableImageContext* context)
{
    ImageId  = ImageBase::GetNextImageId();
    pContext = context;
    pRT      = 0;

    Interfaces rifs;
    pContext->GetRenderInterfacesRT(&rifs);

    Format           = format;
    ISize            = size;
    pCPUModifiedNext = 0;
    pGPUModifiedNext = 0;

    if (!pQueue)
    {
        pQueue = *SF_HEAP_AUTO_NEW(this) DICommandQueue(context);
        pQueue->ImageList.PushBack(this);
    }

    if (pDelegateImage)
        return;
    if (rifs.pTextureManager && rifs.pTextureManager->CanCreateTextureCurrentThread())
        createTextureFromManager(rifs.pHAL, rifs.pTextureManager);
    else
        addCommand(DICommand_CreateTexture(this));
}

// Runs the queued commands (here when they are CPU-renderable, else on the render thread) and maps the texture.
// MS2-FUNCTIONAL: register allocation and frame size (the exe keeps the queue lock address in rbp, reloads pContext)
// @0x1425effe0
void DrawableImage::internalMapAndFlush(bool needMap)
{
    DICommandQueue* queue = pQueue;
    DICommandSet    cmdSet(queue);
    bool            executed;
    {
        Mutex::Locker setLock(&queue->CommandSetMutex);
        while (queue->pRTCommands)
            queue->CommandSetWC.Wait(&queue->CommandSetMutex);

        Lock::Locker lock(&pQueue->QueueLock);
        executed = pQueue->isQueueEmpty_NTS();
        if (DrawableImageState & (DIState_Mapped | DIState_MappedRead))
        {
            if (executed)
                needMap = false;
            else if (pQueue->isCPURenderable_NTS())
            {
                needMap  = false;
                executed = true;
                pQueue->popCommandSet(&cmdSet, DICommand_All);
                pQueue->pATCommands = &cmdSet;
            }
        }
    }

    if (!cmdSet.IsEmpty())
    {
        DICommandContext context;
        cmdSet.ExecuteCommandsMT(context);

        DICommandQueue* q = pQueue;
        Mutex::Locker setLock(&q->CommandSetMutex);
        q->pATCommands = 0;
        q->CommandSetWC.NotifyAll();
    }

    if (needMap || !executed)
    {
        pQueue->ExecuteCommandsAndWait();
        if (needMap)
        {
            pQueue->AddCommand(DICommand_Map(this, false, true));
            pQueue->ExecuteCommandsAndWait();
        }
    }
}

// @0x1425f0220
MS2_SF_NOINL bool DrawableImage::mapTextureRT(bool readOnly, bool forceRemap)
{
    Lock::Locker lock(&pQueue->QueueLock);
    if (readOnly && MapImageSource(&MappedData, pDelegateImage, true))
        DrawableImageState |= DIState_MappedRead;
    else
    {
        if (pDelegateImage && !ensureRenderableRT())
            return false;
        if (pTexture && pTexture->Map(&MappedData))
            DrawableImageState |= DIState_Mapped | DIState_MappedRead;
        if (forceRemap)
            DrawableImageState |= DIState_ForceRemap;
    }
    return (DrawableImageState & (DIState_Mapped | DIState_MappedRead)) != 0;
}

// Moves another drawable image (and its pending commands) onto this image's queue.
// @0x1425f0310
bool DrawableImage::mergeQueueWith(Image* other)
{
    Lock::Locker lock(&pQueue->QueueLock);
    if (other->GetImageType() != Type_DrawableImage)
        return true;
    DrawableImage* image = (DrawableImage*)other;
    if (image->pQueue == pQueue)
        return true;
    if (image->pContext != pContext)
        return false;

    image->internalMapAndFlush(false);
    image->RemoveNode();
    if (image->DrawableImageState & DIState_CPUDirty)
    {
        DICommandQueue* oldQueue = image->pQueue;
        DrawableImage*  prev     = oldQueue->pCPUModifiedImageList;
        if (prev == image)
            oldQueue->pCPUModifiedImageList = image->pCPUModifiedNext;
        else
        {
            while (prev->pCPUModifiedNext != image)
                prev = prev->pCPUModifiedNext;
            prev->pCPUModifiedNext = image->pCPUModifiedNext;
        }
    }
    image->pQueue = pQueue;
    pQueue->ImageList.PushBack(image);
    if (image->DrawableImageState & DIState_CPUDirty)
    {
        image->DrawableImageState &= ~DIState_CPUDirty;
        image->addToCPUModifiedList();
    }
    return true;
}

// @0x1425f0590
void DrawableImage::unmapTextureRT()
{
    Lock::Locker lock(&pQueue->QueueLock);
    if ((DrawableImageState & (DIState_Mapped | DIState_MappedRead)) && pTexture)
    {
        pTexture->Unmap();
        DrawableImageState &= ~(DIState_Mapped | DIState_MappedRead);
    }
}

// MS2-FUNCTIONAL: the exe tail-calls UpdateRenderTargetData without setting the (defaulted) HAL argument
// @0x1425f05f0
void DrawableImage::updateRenderTargetRT()
{
    if (!pTexture)
        return;
    unmapTextureRT();
    pTexture->UpdateRenderTargetData(pRT->GetRenderTargetData());
}

// @0x1425f0630
void DrawableImage::updateStagingTargetRT()
{
    if (!pTexture)
        return;
    unmapTextureRT();
    pTexture->UpdateStagingData(pRT->GetRenderTargetData());
    if (DrawableImageState & DIState_ForceRemap)
    {
        DrawableImageState &= ~DIState_ForceRemap;
        mapTextureRT(false, false);
    }
}

// ---------------------------------------------------------------------------------------------------------------
// DrawableImageContext

// MS2-FUNCTIONAL: the exe copies Interfaces member-wise (four qword moves) where our compiler uses two movups
// @0x1425e9b10
DrawableImageContext::DrawableImageContext(Context* controlContext, ThreadCommandQueue* queue,
                                           const Interfaces& defaults)
    : RContext(0), pControlContext(controlContext), pRTCommandQueue(queue), IDefaults(defaults)
{
    RContext = new Context(Memory::GetHeapByAddress(this));
    if (pControlContext)
        pControlContext->AddCaptureNotify(this);
}

// @0x1425e9f30
DrawableImageContext::~DrawableImageContext()
{
    if (pControlContext)
        pControlContext->RemoveCaptureNotify(this);
    processTreeRootKillList();
}

// @0x1425edf40
void DrawableImageContext::OnCapture()
{
    if (RContext)
        RContext->Capture();
    for (DICommandQueue* queue = QueueList.GetFirst(); !QueueList.IsNull(queue);)
    {
        DICommandQueue* next = queue->pNext;
        queue->OnCapture();
        queue = next;
    }
    processTreeRootKillList();
}

// @0x1425edfb0
void DrawableImageContext::OnNextCapture(ContextImpl::RenderNotify* notify)
{
    ExecuteNextCapture(notify);
    for (DICommandQueue* queue = QueueList.GetFirst(); !QueueList.IsNull(queue);)
    {
        DICommandQueue* next = queue->pNext;
        queue->OnNextCapture(notify);
        queue = next;
    }
}

// The queues still registered run their commands before the context goes away.
// @0x1425ee010
void DrawableImageContext::OnShutdown()
{
    while (!QueueList.IsEmpty())
    {
        Ptr<DICommandQueue> queue = QueueList.GetFirst();
        RemoveCaptureNotify(queue);
        queue->ExecuteCommandsAndWait();
    }
    pControlContext = 0;
    if (RContext)
    {
        processTreeRootKillList();
        delete RContext;
        RContext = 0;
    }
}

// @0x1425ec830
void DrawableImageContext::ExecuteNextCapture(ContextImpl::RenderNotify* notify)
{
    if (RContext)
        RContext->NextCapture(notify);
}

// @0x1425eaf00
void DrawableImageContext::AddCaptureNotify(DICommandQueue* queue)
{
    Lock::Locker lock(&TreeRootKillListLock);
    QueueList.PushBack(queue);
}

// @0x1425eeb50
void DrawableImageContext::RemoveCaptureNotify(DICommandQueue* queue)
{
    Lock::Locker lock(&TreeRootKillListLock);
    if (queue->pNext)
    {
        queue->RemoveNode();
        queue->pPrev = 0;
        queue->pNext = 0;
    }
}

// @0x1425eaf60
void DrawableImageContext::AddTreeRootToKillList(TreeRoot* root)
{
    Lock::Locker lock(&TreeRootKillListLock);
    TreeRootKillList.PushBack(root);
}

// @0x1425f04c0
void DrawableImageContext::processTreeRootKillList()
{
    if (!RContext)
        return;
    Lock::Locker lock(&TreeRootKillListLock);
    for (UPInt i = 0; i < TreeRootKillList.GetSize(); i++)
        ((ContextImpl::Entry*)TreeRootKillList[i])->Release();
    TreeRootKillList.Clear();
}

}} // namespace Scaleform::Render
// MS2-PIN: ??_7DICommand@Render@Scaleform@@6B@ 0x14318ce80
// MS2-PIN: ??_7?$DICommandImpl@UDICommand_Map@Render@Scaleform@@UDICommand@23@@Render@Scaleform@@6B@ 0x14318cec0
// MS2-PIN: ??_7DICommand_Map@Render@Scaleform@@6B@ 0x14318cf00
// MS2-PIN: ??_7?$DICommandImpl@UDICommand_CreateTexture@Render@Scaleform@@UDICommand@23@@Render@Scaleform@@6B@ 0x14318cf40
// MS2-PIN: ??_7DICommand_CreateTexture@Render@Scaleform@@6B@ 0x14318cf80
// MS2-PIN: ??_7?$DICommandImpl@UDICommand_Clear@Render@Scaleform@@UDICommand@23@@Render@Scaleform@@6B@ 0x14318cfc0
// MS2-PIN: ??_7DICommand_Clear@Render@Scaleform@@6B@ 0x14318d000
// MS2-PIN: ??_7DICommand_SourceRect@Render@Scaleform@@6B@ 0x14318d040
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_ApplyFilter@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d088
// MS2-PIN: ??_7DICommand_ApplyFilter@Render@Scaleform@@6B@ 0x14318d0e8
// MS2-PIN: ??_7?$DICommandImpl@UDICommand_Draw@Render@Scaleform@@UDICommand@23@@Render@Scaleform@@6B@ 0x14318d148
// MS2-PIN: ??_7DICommand_Draw@Render@Scaleform@@6B@ 0x14318d188
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_CopyChannel@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d1c8
// MS2-PIN: ??_7DICommand_CopyChannel@Render@Scaleform@@6B@ 0x14318d228
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_CopyPixels@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d288
// MS2-PIN: ??_7DICommand_CopyPixels@Render@Scaleform@@6B@ 0x14318d2e8
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_ColorTransform@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d350
// MS2-PIN: ??_7DICommand_ColorTransform@Render@Scaleform@@6B@ 0x14318d3b0
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_Compare@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d410
// MS2-PIN: ??_7DICommand_Compare@Render@Scaleform@@6B@ 0x14318d470
// MS2-PIN: ??_7?$DICommandImpl@UDICommand_FillRect@Render@Scaleform@@UDICommand@23@@Render@Scaleform@@6B@ 0x14318d4d0
// MS2-PIN: ??_7DICommand_FillRect@Render@Scaleform@@6B@ 0x14318d510
// MS2-PIN: ??_7?$DICommandImpl@UDICommand_FloodFill@Render@Scaleform@@UDICommand@23@@Render@Scaleform@@6B@ 0x14318d550
// MS2-PIN: ??_7DICommand_FloodFill@Render@Scaleform@@6B@ 0x14318d590
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_Merge@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d5d0
// MS2-PIN: ??_7DICommand_Merge@Render@Scaleform@@6B@ 0x14318d630
// MS2-PIN: ??_7?$DICommandImpl@UDICommand_Noise@Render@Scaleform@@UDICommand@23@@Render@Scaleform@@6B@ 0x14318d690
// MS2-PIN: ??_7DICommand_Noise@Render@Scaleform@@6B@ 0x14318d6d0
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_PaletteMap@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d710
// MS2-PIN: ??_7DICommand_PaletteMap@Render@Scaleform@@6B@ 0x14318d770
// MS2-PIN: ??_7?$DICommandImpl@UDICommand_PerlinNoise@Render@Scaleform@@UDICommand@23@@Render@Scaleform@@6B@ 0x14318d7d0
// MS2-PIN: ??_7DICommand_PerlinNoise@Render@Scaleform@@6B@ 0x14318d810
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_Scroll@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d850
// MS2-PIN: ??_7DICommand_Scroll@Render@Scaleform@@6B@ 0x14318d8b0
// MS2-PIN: ??_7UnmapTextureThreadCommand@Render@Scaleform@@6B@ 0x14318d9d0
// MS2-PIN: ??_7DrawableImage@Render@Scaleform@@6B@ 0x14318cd88
// MS2-PIN: ??_7?$RefCountBase@VDrawableImageContext@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318cd50
// MS2-PIN: ??_7DrawableImageContext@Render@Scaleform@@6B?$RefCountBase@VDrawableImageContext@Render@Scaleform@@$01@2@@ 0x14318cd58
// MS2-PIN: ??_7DrawableImageContext@Render@Scaleform@@6BContextCaptureNotify@ContextImpl@12@@ 0x14318cd68
// MS2-PIN: ??_7ContextCaptureNotify@ContextImpl@Render@Scaleform@@6B@ 0x143183f80
// MS2-PIN: ??_7ThreadCommand@Render@Scaleform@@6B@ 0x143183928
// MS2-PIN: ??_7?$RefCountBase@VThreadCommand@Render@Scaleform@@$01@Scaleform@@6B@ 0x143183980
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountVImpl@Scaleform@@$02@Scaleform@@6B@ 0x1431498a0
// MS2-PIN: ??_7?$RefCountBaseV@VImage@Render@Scaleform@@$02@Scaleform@@6B@ 0x1431498b8
// MS2-PIN: ??_7ImageBase@Render@Scaleform@@6B@ 0x1431498d0
// MS2-PIN: ??_7Image@Render@Scaleform@@6B@ 0x143149940
// MS2-PIN: ??_7RefCountVImpl@Scaleform@@6B@ 0x1431496d0
// MS2-FUNCTIONAL ??$AddCommand@UDICommand_Map@Render@Scaleform@@@DICommandQueue@Render@Scaleform@@QEAA_NAEBUDICommand_Map@12@@Z: the Ptr<DrawableImage> copy goes through rcx instead of rax and our build reuses the null page pointer as the false result where the exe clears dil on an explicit failure path
// MS2-PIN: ??$AddCommand@UDICommand_Map@Render@Scaleform@@@DICommandQueue@Render@Scaleform@@QEAA_NAEBUDICommand_Map@12@@Z 0x1425e8420
// MS2-PIN: ??$addCommand@UDICommand_CopyPixels@Render@Scaleform@@@DrawableImage@Render@Scaleform@@IEAAXAEBUDICommand_CopyPixels@12@@Z 0x1425e8960
// MS2-PIN: ??$addCommand@UDICommand_FillRect@Render@Scaleform@@@DrawableImage@Render@Scaleform@@IEAAXAEBUDICommand_FillRect@12@@Z 0x1425e8c20
// MS2-PIN: ??$addCommand@UDICommand_FloodFill@Render@Scaleform@@@DrawableImage@Render@Scaleform@@IEAAXAEBUDICommand_FloodFill@12@@Z 0x1425e8ce0
// MS2-FUNCTIONAL ??0DICommand_SourceRect@Render@Scaleform@@QEAA@AEBU012@@Z: inlined UpdateClippedRects keeps x2/y2 in swapped registers (r9/r10), see render_drawableimage.h
// MS2-PIN: ??0DICommand_SourceRect@Render@Scaleform@@QEAA@AEBU012@@Z 0x1425e9620
// MS2-FUNCTIONAL ??0DICommand_SourceRect@Render@Scaleform@@QEAA@PEAVDrawableImage@12@0AEBV?$Rect@J@12@AEBV?$Point@J@12@@Z: inlined UpdateClippedRects keeps x2/y2 in swapped registers (r9/r10), see render_drawableimage.h
// MS2-PIN: ??0DICommand_SourceRect@Render@Scaleform@@QEAA@PEAVDrawableImage@12@0AEBV?$Rect@J@12@AEBV?$Point@J@12@@Z 0x1425e9710
// MS2-PIN: ??_G?$DICommand_SourceRectImpl@UDICommand_ApplyFilter@Render@Scaleform@@@Render@Scaleform@@UEAAPEAXI@Z 0x1425ea280
// MS2-PIN: ??_G?$DICommand_SourceRectImpl@UDICommand_ColorTransform@Render@Scaleform@@@Render@Scaleform@@UEAAPEAXI@Z 0x1425ea2e0
// MS2-PIN: ??_G?$DICommand_SourceRectImpl@UDICommand_Compare@Render@Scaleform@@@Render@Scaleform@@UEAAPEAXI@Z 0x1425ea340
// MS2-PIN: ??_G?$DICommand_SourceRectImpl@UDICommand_CopyChannel@Render@Scaleform@@@Render@Scaleform@@UEAAPEAXI@Z 0x1425ea3a0
// MS2-PIN: ??_G?$DICommand_SourceRectImpl@UDICommand_CopyPixels@Render@Scaleform@@@Render@Scaleform@@UEAAPEAXI@Z 0x1425ea400
// MS2-PIN: ??_G?$DICommand_SourceRectImpl@UDICommand_Merge@Render@Scaleform@@@Render@Scaleform@@UEAAPEAXI@Z 0x1425ea460
// MS2-PIN: ??_G?$DICommand_SourceRectImpl@UDICommand_PaletteMap@Render@Scaleform@@@Render@Scaleform@@UEAAPEAXI@Z 0x1425ea4c0
// MS2-PIN: ??_G?$DICommand_SourceRectImpl@UDICommand_Scroll@Render@Scaleform@@@Render@Scaleform@@UEAAPEAXI@Z 0x1425ea520
// MS2-PIN: ??$addCommand@UDICommand_Threshold@Render@Scaleform@@@DrawableImage@Render@Scaleform@@IEAAXAEBUDICommand_Threshold@12@@Z 0x1425e9250
// MS2-PIN: ??_G?$DICommand_SourceRectImpl@UDICommand_Threshold@Render@Scaleform@@@Render@Scaleform@@UEAAPEAXI@Z 0x1425ea580
// MS2-PIN: ??_GDICommand_Threshold@Render@Scaleform@@UEAAPEAXI@Z 0x1425eac80
// MS2-PIN: ?ExecuteHWGetImages@?$DICommand_SourceRectImpl@UDICommand_Threshold@Render@Scaleform@@@Render@Scaleform@@UEBAXPEAPEAVDrawableImage@23@PEAV?$Size@M@23@@Z 0x1425ec7a0
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_Threshold@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d910
// MS2-PIN: ??_7DICommand_Threshold@Render@Scaleform@@6B@ 0x14318d970
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?ExecuteHWGetImages@?$DICommand_SourceRectImpl@UDICommand_ApplyFilter@Render@Scaleform@@@Render@Scaleform@@UEBAXPEAPEAVDrawableImage@23@PEAV?$Size@M@23@@Z 0x1425ec320 ; unique
// MS2-PIN: ?ExecuteHWGetImages@?$DICommand_SourceRectImpl@UDICommand_ColorTransform@Render@Scaleform@@@Render@Scaleform@@UEBAXPEAPEAVDrawableImage@23@PEAV?$Size@M@23@@Z 0x1425ec3b0 ; unique
// MS2-PIN: ?ExecuteHWGetImages@?$DICommand_SourceRectImpl@UDICommand_Compare@Render@Scaleform@@@Render@Scaleform@@UEBAXPEAPEAVDrawableImage@23@PEAV?$Size@M@23@@Z 0x1425ec440 ; unique
// MS2-PIN: ?ExecuteHWGetImages@?$DICommand_SourceRectImpl@UDICommand_CopyChannel@Render@Scaleform@@@Render@Scaleform@@UEBAXPEAPEAVDrawableImage@23@PEAV?$Size@M@23@@Z 0x1425ec4d0 ; unique
// MS2-PIN: ?ExecuteHWGetImages@?$DICommand_SourceRectImpl@UDICommand_CopyPixels@Render@Scaleform@@@Render@Scaleform@@UEBAXPEAPEAVDrawableImage@23@PEAV?$Size@M@23@@Z 0x1425ec560 ; unique
// MS2-PIN: ?ExecuteHWGetImages@?$DICommand_SourceRectImpl@UDICommand_Merge@Render@Scaleform@@@Render@Scaleform@@UEBAXPEAPEAVDrawableImage@23@PEAV?$Size@M@23@@Z 0x1425ec5f0 ; unique
// MS2-PIN: ?ExecuteHWGetImages@?$DICommand_SourceRectImpl@UDICommand_PaletteMap@Render@Scaleform@@@Render@Scaleform@@UEBAXPEAPEAVDrawableImage@23@PEAV?$Size@M@23@@Z 0x1425ec680 ; unique
// MS2-PIN: ?ExecuteHWGetImages@?$DICommand_SourceRectImpl@UDICommand_Scroll@Render@Scaleform@@@Render@Scaleform@@UEBAXPEAPEAVDrawableImage@23@PEAV?$Size@M@23@@Z 0x1425ec710 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7EntryData@ContextImpl@Render@Scaleform@@6B@ 0x14317b6d0
// MS2-PIN: ??_7NodeData@TreeNode@Render@Scaleform@@6B@ 0x14317b700
// MS2-PIN: ??_7?$ContextData_ImplMixin@VNodeData@TreeContainer@Render@Scaleform@@V1TreeNode@34@@ContextImpl@Render@Scaleform@@6B@ 0x143183230
// MS2-PIN: ??_7NodeData@TreeContainer@Render@Scaleform@@6B@ 0x143183280
// MS2-PIN: ??_7?$ContextData_ImplMixin@VNodeData@TreeRoot@Render@Scaleform@@V1TreeContainer@34@@ContextImpl@Render@Scaleform@@6B@ 0x1431832d0
// MS2-PIN: ??_7NodeData@TreeRoot@Render@Scaleform@@6B@ 0x143183320
// MS2-PIN: ??_7?$RefCountBase@VComplexFill@Render@Scaleform@@$01@Scaleform@@6B@ 0x14317b660
// MS2-PIN: ??_7ComplexFill@Render@Scaleform@@6B@ 0x14317b668
// MS2-PIN: ??_7?$ContextData_ImplMixin@VNodeData@TreeShape@Render@Scaleform@@V1TreeNode@34@@ContextImpl@Render@Scaleform@@6B@ 0x14317bbf0
// MS2-PIN: ??_7NodeData@TreeShape@Render@Scaleform@@6B@ 0x14317bc40
