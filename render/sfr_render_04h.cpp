// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the drawable image HAL TU
// (Render_DrawableImage_HW): how the DrawableImage commands draw through the HAL. The source-rect commands share one
// body (sources and their render targets, a temporary target when the destination is also read, the texture
// matrices, the command's own copy action, then the copy back); the others clear, fill, create the texture or draw
// a tree root into the image.
// Queue unit sfr_render_04 is split along its original sources (04h Render_DrawableImage_HW).
// MS2-UNIT: sfr_render_04h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142671f40-0x142675560 .text$mn

#include "ms2/scaleform/include/render/render_drawableimage.h"
#include "ms2/scaleform/include/render/render_hal.h"
#include "ms2/scaleform/include/render/render_renderer2d.h"
#include "ms2/scaleform/include/render/render_primitivequeue.h"
#include "ms2/scaleform/include/render/render_twips.h"
#include "ms2/scaleform/include/render/render_matrixpool.h"
#include "ms2/scaleform/include/render/render_filters.h"

namespace Scaleform { namespace Render {

// the destination, the source and a second source (CopyPixels' alpha source)
enum { MaximumDrawableSources = 3 };

// ***** The source-rect commands

// MS2-FUNCTIONAL: in the texture matrix loop cl steps the matrix pointer before the image index (the exe the other way)
// @0x142671f40
template<class D>
void DICommand_SourceRectImpl<D>::ExecuteHW(DICommandContext& context) const
{
    TextureManager* manager = context.pHAL->GetTextureManager();
    DrawableImage*  images[MaximumDrawableSources];
    // where each image is read from (set by ExecuteHWGetImages for the images it returns, otherwise left unset)
    float           readOffsetData[MaximumDrawableSources * 2];
    Size<float>*    readOffsets = (Size<float>*)readOffsetData;
    RenderTarget*   targets[MaximumDrawableSources];
    Texture*        textures[MaximumDrawableSources];

    memset(images, 0, sizeof(images));
    ExecuteHWGetImages(images, readOffsets);
    for (unsigned i = 0; i < MaximumDrawableSources; i++)
    {
        targets[i]  = images[i] ? images[i]->GetRenderTarget() : 0;
        textures[i] = images[i] ? images[i]->GetTexture(manager) : 0;
    }

    // An operation that reads its destination draws into a temporary target the size of the rectangle, and copies
    // the result back afterwards (a target cannot be read and written at once).
    bool              requiresSource = GetRequireSourceRead();
    Ptr<RenderTarget> temp;
    if (requiresSource)
    {
        ImageSize size(ClippedSourceRect.Width(), ClippedSourceRect.Height());
        temp = *context.pHAL->CreateTempRenderTarget(size, false);
        context.pHAL->PushRenderTarget(RectF(Size<float>((float)size.Width, (float)size.Height)), temp);
    }

    // each source's texture matrix maps the rectangle onto the part of its buffer it is read from
    Matrix2F texgen[MaximumDrawableSources];
    for (int i = 0; i < MaximumDrawableSources; i++)
    {
        if (targets[i])
        {
            texgen[i].AppendScaling(Size<float>((float)ClippedSourceRect.Width() / (float)targets[i]->GetBufferSize().Width,
                                                (float)ClippedSourceRect.Height() / (float)targets[i]->GetBufferSize().Height));
            ImageSize buffer = targets[i]->GetBufferSize();
            texgen[i].Tx() += readOffsets[i].Width / (float)buffer.Width;
            texgen[i].Ty() += readOffsets[i].Height / (float)buffer.Height;
        }
    }

    ExecuteHWCopyAction(context, textures, texgen);

    if (requiresSource)
    {
        context.pHAL->PopRenderTarget();

        // the temporary target onto the rectangle of the destination
        Matrix2F  mvp, texgenCopy;
        RenderTarget* dest = targets[0];
        mvp.AppendScaling((float)ClippedSourceRect.Width() / (float)dest->GetSize().Width,
                          (float)ClippedSourceRect.Height() / (float)dest->GetSize().Height);
        mvp.AppendTranslation((readOffsets[0].Width - (float)dest->GetSize().Width / 2.0f) / (float)dest->GetSize().Width,
                              (readOffsets[0].Height - (float)dest->GetSize().Height / 2.0f) / (float)dest->GetSize().Height);
        float yScale = (GetType() == DICommandType_Scroll || GetType() == DICommandType_Merge)
                           ? context.pHAL->GetViewportScaling() * 2.0f
                           : -2.0f;
        mvp.AppendScaling(2.0f, yScale);

        ImageSize tempSize = temp->GetSize();
        const ImageSize& tempBuffer = temp->GetBufferSize();
        texgenCopy.AppendScaling((float)tempSize.Width / (float)tempBuffer.Width,
                                 (float)tempSize.Height / (float)tempBuffer.Height);
        context.pHAL->DrawableCopyback(temp->GetTexture(), mvp, texgenCopy);
        temp->SetInUse(RTUse_Unused);
    }
}

template void DICommand_SourceRectImpl<DICommand_ApplyFilter>::ExecuteHW(DICommandContext&) const;
template void DICommand_SourceRectImpl<DICommand_CopyChannel>::ExecuteHW(DICommandContext&) const;
template void DICommand_SourceRectImpl<DICommand_CopyPixels>::ExecuteHW(DICommandContext&) const;
template void DICommand_SourceRectImpl<DICommand_ColorTransform>::ExecuteHW(DICommandContext&) const;
template void DICommand_SourceRectImpl<DICommand_Compare>::ExecuteHW(DICommandContext&) const;
template void DICommand_SourceRectImpl<DICommand_Merge>::ExecuteHW(DICommandContext&) const;
template void DICommand_SourceRectImpl<DICommand_PaletteMap>::ExecuteHW(DICommandContext&) const;
template void DICommand_SourceRectImpl<DICommand_Scroll>::ExecuteHW(DICommandContext&) const;
template void DICommand_SourceRectImpl<DICommand_Threshold>::ExecuteHW(DICommandContext&) const;

// ***** The other commands

#pragma strict_gs_check(push, on)
// MS2-FUNCTIONAL: the exe converts the returned size through its address (its temporary 4 bytes lower); ours reloads a copy
// @0x142674a00
void DICommand_Clear::ExecuteHW(DICommandContext& context) const
{
    context.pHAL->applyBlendMode(Blend_OverwriteAll, true, true);
    // the whole image (its size as a float rectangle, back to integer pixels)
    ImageSize size = pImage->GetSize();
    Rect<int> rect = RectF(Size<float>(size));
    context.pHAL->clearSolidRectangle(rect, FillColor);
    context.pHAL->applyBlendMode(Blend_None);
}
#pragma strict_gs_check(pop)

// @0x142674ac0
void DICommand_CreateTexture::ExecuteHW(DICommandContext& context) const
{
    TextureManager* manager = context.pHAL->GetTextureManager();
    pImage->createTextureFromManager(context.pHAL, manager);
}

// The tree root is drawn with the renderer; a display bracket already open is closed around it and reopened.
// @0x142674b00
void DICommand_Draw::ExecuteHW(DICommandContext& context) const
{
    DrawableImageContext* dicontext = pImage->GetContext();
    // the displaying snapshot of the image context (taken now unless already taken)
    dicontext->ExecuteNextCapture(context.pR2D->GetContextNotify());

    Viewport oldVP        = context.pHAL->VP;
    unsigned wasInDisplay = context.pHAL->GetHALState() & HAL::HS_InDisplay;
    if (wasInDisplay)
        context.pHAL->EndDisplay();
    context.pR2D->Display(pRoot);
    if (wasInDisplay)
        context.pHAL->BeginDisplay(Color(0), oldVP);

    dicontext->AddTreeRootToKillList(pRoot);
}

// An opaque image keeps full alpha.
#pragma strict_gs_check(push, on)
// @0x142674c10
void DICommand_FillRect::ExecuteHW(DICommandContext& context) const
{
    context.pHAL->applyBlendMode(Blend_OverwriteAll, true);
    Color fill = FillColor;
    if (!pImage->IsTransparent())
        fill.SetAlpha(0xFF);
    Rect<int> rect;   // edge by edge
    rect.x1 = ApplyRect.x1; rect.y1 = ApplyRect.y1; rect.x2 = ApplyRect.x2; rect.y2 = ApplyRect.y2;
    context.pHAL->clearSolidRectangle(rect, fill);
}
#pragma strict_gs_check(pop)

// ***** Copy actions

// The filter primitive covers the filtered bounds of the rectangle; the source is drawn into its middle.
// MS2-FUNCTIONAL: stack layout: the exe keeps the filter rectangle 16-aligned below the matrices, ours places it lower
// @0x142674cc0
void DICommand_ApplyFilter::ExecuteHWCopyAction(DICommandContext& context, Texture** tex,
                                                const Matrix2F* texgen) const
{
    Matrix2F mvp, mvpContent;
    RectF    filterRect;
    RectF    sourceRect((float)SourceRect.x1, (float)SourceRect.y1, (float)SourceRect.x2, (float)SourceRect.y2);

    DrawableImage::CalcFilterRect(&filterRect,
                                  Rect<SInt32>((SInt32)PixelsToTwips(sourceRect.x1), (SInt32)PixelsToTwips(sourceRect.y1),
                                               (SInt32)PixelsToTwips(sourceRect.x2), (SInt32)PixelsToTwips(sourceRect.y2)),
                                  pFilter);
    filterRect = RectF(TwipsToPixels(filterRect.x1), TwipsToPixels(filterRect.y1), TwipsToPixels(filterRect.x2),
                       TwipsToPixels(filterRect.y2));
    mvp.AppendScaling(filterRect.Width(), filterRect.Height());
    mvp.AppendTranslation(filterRect.x1, filterRect.y1);

    FilterSet                filters(pFilter);
    FilterPrimitive          prim(context.pHAL, &filters, false);
    MatrixPoolImpl::HMatrix  hm = context.pR2D->GetImpl()->GetMatrixPool().CreateMatrix(mvp);
    hm.SetMatrix2D(mvp);
    prim.Insert(0, hm);
    context.pHAL->PushFilters(&prim);

    mvpContent = Matrix2F(2.0f, 0, -1.0f, 0, -2.0f, 1.0f);   // Scaling(2, -2) * Translation(-0.5, -0.5)
    mvpContent.AppendScaling(sourceRect.Width() / filterRect.Width(), sourceRect.Height() / filterRect.Height());
    context.pHAL->DrawableCopyback(tex[1], mvpContent, texgen[1]);

    context.pHAL->PopFilters();
}

// An opaque image takes the alpha into the colour terms and keeps full alpha.
// @0x142675040
void DICommand_ColorTransform::ExecuteHWCopyAction(DICommandContext& context, Texture** tex,
                                                   const Matrix2F* texgen) const
{
    context.pHAL->applyBlendMode(pImage->IsTransparent() ? Blend_OverwriteAll : Blend_Overwrite, true, true);
    Cxform cx = Cx;
    if (!pImage->IsTransparent())
    {
        float alpha = cx.M[0][3] + cx.M[1][3];
        for (int i = 0; i < 3; i++)
        {
            cx.M[0][i] *= alpha;
            cx.M[1][i] *= alpha;
        }
        cx.M[0][3] = 1.0f;
        cx.M[1][3] = 0.0f;
    }
    // the first source is the destination itself
    context.pHAL->DrawableCxform(tex + 1, texgen + 1, &cx);
}

// @0x142675160
void DICommand_Compare::ExecuteHWCopyAction(DICommandContext& context, Texture** tex, const Matrix2F* texgen) const
{
    tex[0] = pSource->GetRenderTarget()->GetTexture();
    tex[1] = pImageCompare1->GetRenderTarget()->GetTexture();
    context.pHAL->DrawableCompare(tex, texgen);
}

// The destination keeps its other channels; the source channel lands in the destination channel.
// @0x1426751e0
void DICommand_CopyChannel::ExecuteHWCopyAction(DICommandContext& context, Texture** tex,
                                                const Matrix2F* texgen) const
{
    Matrix4F cxmul[2];
    unsigned destIndex = 0, sourceIndex = 0;
    switch (DestChannel)
    {
    case DrawableImage::Channel_Red:   destIndex = 0; break;
    case DrawableImage::Channel_Green: destIndex = 1; break;
    case DrawableImage::Channel_Blue:  destIndex = 2; break;
    case DrawableImage::Channel_Alpha: destIndex = 3; break;
    default: break;
    }
    switch (SourceChannel)
    {
    case DrawableImage::Channel_Red:   sourceIndex = 0; break;
    case DrawableImage::Channel_Green: sourceIndex = 1; break;
    case DrawableImage::Channel_Blue:  sourceIndex = 2; break;
    case DrawableImage::Channel_Alpha: sourceIndex = 3; break;
    default: break;
    }

    cxmul[0].M[destIndex][destIndex] = 0;
    memset(cxmul[1].M, 0, sizeof(cxmul[1].M));
    cxmul[1].M[destIndex][sourceIndex] = 1.0f;
    context.pHAL->DrawableCopyChannel(tex, texgen, cxmul);
}

// @0x142675340
void DICommand_CopyPixels::ExecuteHWCopyAction(DICommandContext& context, Texture** tex,
                                               const Matrix2F* texgen) const
{
    Matrix2F mvp(2.0f, 0, -1.0f, 0, -2.0f, 1.0f);   // Scaling(2, -2) * Translation(-0.5, -0.5)
    context.pHAL->applyBlendMode(pImage->IsTransparent() ? Blend_OverwriteAll : Blend_Overwrite, true, true);
    context.pHAL->DrawableCopyPixels(tex, texgen, mvp, MergeAlpha, pImage->IsTransparent());
}

// Each channel blends source and destination by its multiplier (0-256).
// @0x1426753f0
void DICommand_Merge::ExecuteHWCopyAction(DICommandContext& context, Texture** tex, const Matrix2F* texgen) const
{
    Matrix4F cxmul[2];
    float    mult[4];
    mult[0] = Alg::Min<unsigned>(RedMultiplier, 256) / 256.0f;
    mult[1] = Alg::Min<unsigned>(GreenMultiplier, 256) / 256.0f;
    mult[2] = Alg::Min<unsigned>(BlueMultiplier, 256) / 256.0f;
    mult[3] = Alg::Min<unsigned>(AlphaMultiplier, 256) / 256.0f;
    for (int i = 0; i < 4; i++)
    {
        cxmul[0].M[i][i] = 1.0f - mult[i];
        cxmul[1].M[i][i] = mult[i];
    }
    context.pHAL->DrawableMerge(tex, texgen, cxmul);
}

}} // namespace Scaleform::Render

// MS2-PIN: ?ExecuteHW@?$DICommand_SourceRectImpl@UDICommand_ApplyFilter@Render@Scaleform@@@Render@Scaleform@@UEBAXAEAUDICommandContext@23@@Z 0x142671f40
// MS2-PIN: ?ExecuteHW@?$DICommand_SourceRectImpl@UDICommand_CopyChannel@Render@Scaleform@@@Render@Scaleform@@UEBAXAEAUDICommandContext@23@@Z 0x142672400
// MS2-PIN: ?ExecuteHW@?$DICommand_SourceRectImpl@UDICommand_CopyPixels@Render@Scaleform@@@Render@Scaleform@@UEBAXAEAUDICommandContext@23@@Z 0x1426728c0
// MS2-PIN: ?ExecuteHW@?$DICommand_SourceRectImpl@UDICommand_ColorTransform@Render@Scaleform@@@Render@Scaleform@@UEBAXAEAUDICommandContext@23@@Z 0x142672d80
// MS2-PIN: ?ExecuteHW@?$DICommand_SourceRectImpl@UDICommand_Compare@Render@Scaleform@@@Render@Scaleform@@UEBAXAEAUDICommandContext@23@@Z 0x142673240
// MS2-PIN: ?ExecuteHW@?$DICommand_SourceRectImpl@UDICommand_Merge@Render@Scaleform@@@Render@Scaleform@@UEBAXAEAUDICommandContext@23@@Z 0x142673700
// MS2-PIN: ?ExecuteHW@?$DICommand_SourceRectImpl@UDICommand_PaletteMap@Render@Scaleform@@@Render@Scaleform@@UEBAXAEAUDICommandContext@23@@Z 0x142673bc0
// MS2-PIN: ?ExecuteHW@?$DICommand_SourceRectImpl@UDICommand_Scroll@Render@Scaleform@@@Render@Scaleform@@UEBAXAEAUDICommandContext@23@@Z 0x142674080
// MS2-PIN: ?ExecuteHW@?$DICommand_SourceRectImpl@UDICommand_Threshold@Render@Scaleform@@@Render@Scaleform@@UEBAXAEAUDICommandContext@23@@Z 0x142674540
// MS2-PIN: ??_7FilterSet@Render@Scaleform@@6B@ 0x14318cce0
// MS2-PIN: ??_7Interface@RenderQueueItem@Render@Scaleform@@6B@ 0x143191990
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EE@@Scaleform@@6B@ 0x1431919b0
// MS2-PIN: ??_7?$RefCountBase@VFilterPrimitive@Render@Scaleform@@$0EE@@Scaleform@@6B@ 0x1431919f0
// MS2-PIN: ??_7FilterPrimitive@Render@Scaleform@@6B?$RefCountBase@VFilterPrimitive@Render@Scaleform@@$0EE@@2@@ 0x1431919f8
// MS2-PIN: ??_7FilterPrimitive@Render@Scaleform@@6BInterface@RenderQueueItem@12@@ 0x143191a00
