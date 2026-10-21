// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render_DrawableImage members that the
// linker placed in the gap after the drawable image TU (sfr_render_02i): the per-pixel writes, SetPixels, Threshold,
// the user Unmap, TextureLost, and the CPU-modified list that a capture flushes.
// MS2-UNIT: sfr_gfx_05f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425eeef0-0x1425ef560 .text$mn

#include "ms2/scaleform/include/render/render_drawableimage.h"
#include "ms2/scaleform/include/render/render_shapedata.h"

namespace Scaleform { namespace Render {

// Writes c as is (alpha included); x == width / y == height pass the check like the exe's.
// @0x1425eef20
bool DrawableImage::SetPixel32(SInt32 x, SInt32 y, Color c)
{
    if (x > (SInt32)ISize.Width || x < 0 || y > (SInt32)ISize.Height || y < 0)
        return false;
    internalMapAndFlush();
    MappedData.SetPixelARGB(x, y, c.ToColor32());
    addToCPUModifiedList();
    return true;
}

// Writes the color channels of c and keeps the pixel's alpha.
// MS2-FUNCTIONAL: the exe inlines GetPixel32 (02i keeps it out of line)
// @0x1425eef90
bool DrawableImage::SetPixel(SInt32 x, SInt32 y, Color c)
{
    if (x > (SInt32)ISize.Width || x < 0 || y > (SInt32)ISize.Height || y < 0)
        return false;
    internalMapAndFlush();
    c.SetAlpha(GetPixel32(x, y).GetAlpha());
    MappedData.SetPixelARGB(x, y, c.ToColor32());
    addToCPUModifiedList();
    return true;
}

// Fills destRect row by row from the provider; false if the rectangle leaves the image or the provider runs dry.
// @0x1425ef060
bool DrawableImage::SetPixels(const Rect<SInt32>& destRect, DIPixelProvider& provider)
{
    Rect<SInt32> bounds(0, 0, ISize.Width, ISize.Height);
    if (bounds.x2 < destRect.x2 || bounds.y2 < destRect.y2 || destRect.x1 < bounds.x1 || destRect.y1 < bounds.y1)
        return false;

    internalMapAndFlush();
    unsigned index = 0;
    for (SInt32 y = destRect.y1; y < destRect.y2; ++y)
    {
        for (SInt32 x = destRect.x1; x < destRect.x2; ++x, ++index)
        {
            if (index >= provider.GetLength())
                return false;
            MappedData.SetPixelARGB(x, y, provider.ReadNextPixel());
        }
    }
    addToCPUModifiedList();
    return true;
}

// A lost device takes the render target with it; it is recreated on the next draw.
// @0x1425ef1b0
void DrawableImage::TextureLost(TextureLossReason reason)
{
    if (reason == TLR_DeviceLost)
        pRT = 0;
}

// MS2-FUNCTIONAL: the exe inlines addCommand<DICommand_Threshold> (its out-of-line instance lives in sfr_render_02i)
// @0x1425ef1e0
void DrawableImage::Threshold(DrawableImage* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                              OperationType op, UInt32 threshold, UInt32 color, UInt32 mask, bool copySource)
{
    addCommand(DICommand_Threshold(this, source, sourceRect, destPoint, op, threshold, color, mask, copySource));
}

// Ends a Map() by the user; false if the image was not user-mapped.
// @0x1425ef370
bool DrawableImage::Unmap()
{
    Lock::Locker lock(&pQueue->QueueLock);
    if (!(DrawableImageState & DIState_UserMapped))
        return false;
    DrawableImageState &= ~DIState_UserMapped;
    return true;
}

// @0x1425ef4a0
void DrawableImage::addToCPUModifiedList()
{
    Lock::Locker lock(&pQueue->QueueLock);
    if (pContext && pContext->pControlContext)
        pContext->pControlContext->SetDIChangesRequired();
    if (DrawableImageState & DIState_CPUDirty)
        return;
    DrawableImageState |= DIState_CPUDirty;
    pCPUModifiedNext = pQueue->pCPUModifiedImageList;
    pQueue->pCPUModifiedImageList = this;
}

// The path-building instances of DrawableImage::Draw(Image*) (sfr_render_02i) that the exe keeps in this gap.
template void ShapeDataFloatTempl<Array<UByte> >::StartLayer();
template void PathDataEncoder<Array<UByte> >::WriteChar(char v);

}} // namespace Scaleform::Render

// The DICommand_SourceRect clip helper's out-of-line copy (inline virtual, render_drawableimage.h).
// MS2-PIN: ?UpdateClippedRects@DICommand_SourceRect@Render@Scaleform@@UEAAXXZ 0x1425ef3d0
// Threshold's command vftables (also emitted by sfr_render_02i).
// MS2-PIN: ??_7DICommand@Render@Scaleform@@6B@ 0x14318ce80
// MS2-PIN: ??_7DICommand_SourceRect@Render@Scaleform@@6B@ 0x14318d040
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_Threshold@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d910
// MS2-PIN: ??_7DICommand_Threshold@Render@Scaleform@@6B@ 0x14318d970
