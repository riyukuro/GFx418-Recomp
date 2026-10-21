// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the drawable image queue TU
// (Render_DrawableImage_Queue): the per-image-group command queue (pages of packed DICommand records moved from the
// active list to captured / displaying as the movie captures), its render-thread and advance-thread execution passes,
// and the DICommand helpers that pick the CPU or the HAL path for one command.
// Queue unit sfr_render_04 is split along its original sources (04g Render_DrawableImage_Queue).
// MS2-UNIT: sfr_render_04g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14266fc60-0x142671f40 .text$mn

#include "ms2/scaleform/include/render/render_drawableimage.h"
#include "ms2/scaleform/include/render/render_hal.h"
#include "ms2/scaleform/include/render/render_viewport.h"
#include "ms2/scaleform/kernel/sf_memory.h"

namespace Scaleform { namespace Render {

// ***** DICommandQueue

// @0x14266fc60
DICommandQueue::DICommandQueue(DrawableImageContext* context)
    : pRTCommands(0), pATCommands(0), pDIContext(context), pCPUModifiedImageList(0), pGPUModifiedImageList(0),
      pRTCommandQueue(context->GetQueue()), ExecuteCmd(*SF_NEW ExecuteCommand(this)), CaptureFrameId(0),
      FreePageCount(0), AllocPageCount(0)
{
    pDIContext->AddCaptureNotify(this);
}

// @0x14266fdb0
DICommandQueue::~DICommandQueue()
{
    // OnShutdown can take and drop a reference; keep the count off zero meanwhile.
    RefCount = 2;
    OnShutdown();

    while (!Queues[DIQueue_Free].IsEmpty())
    {
        DIQueuePage* page = Queues[DIQueue_Free].GetFirst();
        page->RemoveNode();
        delete page;
    }
    RefCount = 0;
}

// Render thread: everything queued so far, then wakes the advance thread waiting in ExecuteCommandsAndWait.
// @0x1426700f0
void DICommandQueue::ExecuteCommand::Execute()
{
    DICommandContext context(pQueue->pRTCommandQueue);
    DICommandSet     cmdSet(pQueue);
    {
        Mutex::Locker setLock(&pQueue->CommandSetMutex);
        while (pQueue->pATCommands)
            pQueue->CommandSetWC.Wait(&pQueue->CommandSetMutex);
        pQueue->popCommandSet(&cmdSet, DICommand_All);
        pQueue->pRTCommands = &cmdSet;
    }

    cmdSet.ExecuteCommandsRT(context);

    {
        Mutex::Locker setLock(&pQueue->CommandSetMutex);
        pQueue->pRTCommands = 0;
        pQueue->CommandSetWC.NotifyAll();
    }

    // the reference ExecuteCommandsAndWait took, then the waiter, then our own
    pQueue->Release();
    ExecuteDone.SetEvent();
    Release();
}

// ***** DICommandSet

// Advance thread: every command on the CPU (the caller checked they all can run there).
// MS2-FUNCTIONAL: the exe keeps the context in r12 and the page in r14 with a deferred register save; ours allocates them differently
// @0x1426702e0
void DICommandSet::ExecuteCommandsMT(DICommandContext& context)
{
    while (!QueueList.IsEmpty())
    {
        DIQueuePage* page = QueueList.GetFirst();
        page->RemoveNode();

        DICommand* cmd = page->getFirst();
        while (cmd)
        {
            DISourceImages images;
            unsigned       imageCount = cmd->GetSourceImages(&images);
            cmd->executeSWHelper(context, cmd->pImage, images, imageCount, false);
            cmd = page->destroyAndGetNext(cmd);
        }
        pQueue->freePage(page);
    }
    QueueList.Clear();
}

// Render thread: commands that draw into their image get it pushed as the HAL's render target (kept while the
// following commands share it), each page inside its own frame / scene bracket.
// MS2-FUNCTIONAL: the exe frame is 0x10 larger with a /GS cookie and spills the arguments to other slots
// @0x142670440
void DICommandSet::ExecuteCommandsRT(DICommandContext& context)
{
    HAL* hal      = context.pHAL;
    bool gpuEvent = false;

    while (!QueueList.IsEmpty())
    {
        DIQueuePage* page = QueueList.GetFirst();
        page->RemoveNode();

        if (!gpuEvent)
        {
            hal->GetEvent(Event_DrawableImage).Begin("Scaleform::Render::DrawableImage");
            gpuEvent = true;
        }

        DICommand*     cmd        = page->getFirst();
        DrawableImage* target     = 0;
        bool           wasInFrame = true;
        bool           wasInScene = false;

        while (cmd)
        {
            DrawableImage* image       = cmd->pImage;
            bool           needsTarget = (cmd->GetRenderCaps() & DICommand::RC_GPU_NoRT) == 0;

            // (a target that cannot be made renderable leaves the command where it is)
            if (needsTarget && !image->ensureRenderableRT())
                continue;

            if (!target && needsTarget)
            {
                target = image;
                if (!(hal->HALState & HAL::HS_InFrame))
                {
                    hal->BeginFrame();
                    wasInFrame = false;
                }
                if (hal->HALState & HAL::HS_InScene)
                {
                    wasInScene = true;
                    hal->EndScene();
                }

                ImageSize size = target->GetSize();
                RectF     imageRect(0.0f, 0.0f, (float)size.Width, (float)size.Height);
                hal->PushRenderTarget(imageRect, target->GetRenderTarget(), 1);
                hal->BeginScene();
                Viewport vp(target->GetSize(),
                            Rect<int>((int)imageRect.x1, (int)imageRect.y1, (int)imageRect.x2, (int)imageRect.y2),
                            Viewport::View_IsRenderTexture);
                hal->BeginDisplay(Color(0), vp);
            }
            else if (target != image && needsTarget)
            {
                target = image;
                hal->EndDisplay();
                hal->EndScene();
                hal->PopRenderTarget();
                hal->GetEvent(Event_DrawableImage).End();
                hal->GetEvent(Event_DrawableImage).Begin("Scaleform::Render::DrawableImage");

                ImageSize size = target->GetSize();
                RectF     imageRect(0.0f, 0.0f, (float)size.Width, (float)size.Height);
                hal->PushRenderTarget(imageRect, target->GetRenderTarget(), 1);
                hal->BeginScene();
                Viewport vp(target->GetSize(),
                            Rect<int>((int)imageRect.x1, (int)imageRect.y1, (int)imageRect.x2, (int)imageRect.y2));
                hal->BeginDisplay(Color(0), vp);
            }

            cmd->ExecuteRT(context);
            cmd = page->destroyAndGetNext(cmd);
        }

        if (target)
        {
            hal->EndDisplay();
            hal->EndScene();
            hal->PopRenderTarget();
            hal->GetEvent(Event_DrawableImage).End();
            if (wasInScene)
                hal->BeginScene();
            if (!wasInFrame)
                hal->EndFrame();
        }

        pQueue->freePage(page);
    }
    QueueList.Clear();

    // what the commands changed, copied between the staging data and the render targets
    pQueue->updateCPUModifiedImagesRT();
    pQueue->updateGPUModifiedImagesRT();
}

// Render thread, the capture being displayed: its commands (and only those) run now.
// @0x1426709d0
void DICommandQueue::ExecuteNextCapture(ContextImpl::RenderNotify* notify)
{
    if (!pRTCommandQueue && notify)
        pRTCommandQueue = notify->pRTCommandQueue;

    DICommandContext context(pRTCommandQueue);
    DICommandSet     cmdSet(this);
    {
        Mutex::Locker setLock(&CommandSetMutex);
        while (pATCommands)
            CommandSetWC.Wait(&CommandSetMutex);

        Lock::Locker lock(&QueueLock);
        Queues[DIQueue_Displaying].PushListToBack(Queues[DIQueue_Captured]);
        popCommandSet(&cmdSet, DICommand_Displaying);
        pRTCommands = &cmdSet;
    }

    cmdSet.ExecuteCommandsRT(context);

    {
        Mutex::Locker setLock(&CommandSetMutex);
        pRTCommands = 0;
        CommandSetWC.NotifyAll();
    }
}

// ***** DICommand

// @0x142670b80
void DICommand::ExecuteRT(DICommandContext& context) const
{
    if ((GetRenderCaps() & (RC_CPU | RC_GPUPreference)) == RC_CPU)
    {
        // the CPU reads what the GPU wrote
        pImage->pQueue->updateGPUModifiedImagesRT();

        DISourceImages images;
        unsigned       imageCount = GetSourceImages(&images);
        if (pImage->isMapped() || pImage->mapTextureRT(false))
            executeSWHelper(context, pImage, images, imageCount, true);
    }
    else
    {
        // and the GPU what the CPU wrote
        pImage->pQueue->updateCPUModifiedImagesRT();
        executeHWHelper(context, pImage);
    }
}

// The CPU flag from the command itself, the HAL's flags for it when a render thread is known.
// @0x142670d00
unsigned DICommand::GetRenderCaps() const
{
    unsigned cpuCaps = HasCPUImplementation() ? RC_CPU : 0;
    if (!pImage || !pImage->GetContext() || !pImage->GetContext()->GetQueue())
        return cpuCaps;

    DICommandContext context(pImage->GetContext()->GetQueue());
    if (!context.pHAL)
        return cpuCaps;
    return context.pHAL->DrawableCommandGetFlags(this) | cpuCaps;
}

// A command the CPU can run at once on an already mapped image is not queued.
// @0x142670c60
bool DICommand::ExecuteSWOnAddCommand(DrawableImage* image) const
{
    DISourceImages images;
    unsigned       imageCount = GetSourceImages(&images);
    if ((image->DrawableImageState & (DrawableImage::DIState_Mapped | DrawableImage::DIState_CmdPending)) ==
            DrawableImage::DIState_Mapped &&
        (GetRenderCaps() & (RC_CPU | RC_GPUPreference)) == RC_CPU)
    {
        DICommandContext context;
        if (executeSWHelper(context, pImage, images, imageCount, false))
            return true;
    }
    return false;
}

// @0x142670d90
bool DICommand::IsCPUExecutable() const
{
    if (!(GetRenderCaps() & RC_CPU))
        return false;
    if (!pImage->isMapped())
        return false;

    DISourceImages images;
    if (GetSourceImages(&images))
    {
        if (images[0] && !IsImageCPUReadable(images[0]))
            return false;
        if (images[1] && !IsImageCPUReadable(images[1]))
            return false;
    }
    return true;
}

// @0x142670e10
bool DICommand::IsImageCPUReadable(Image* image)
{
    if (!image)
        return false;
    if (image->GetImageType() == ImageBase::Type_DrawableImage)
    {
        if (!((DrawableImage*)image)->isMappedWithEmptyQueue())
            return false;
    }
    else if (image->GetImageType() != ImageBase::Type_RawImage ||
             (image->GetFormat() != Image_B8G8R8A8 && image->GetFormat() != Image_R8G8B8A8))
        return false;
    return true;
}

// ***** DICommandQueue

// Advance thread capture: what was queued becomes the captured set (after the render thread is done with the last).
// @0x142670e70
void DICommandQueue::OnCapture()
{
    Mutex::Locker setLock(&CommandSetMutex);
    while (pRTCommands)
        CommandSetWC.Wait(&CommandSetMutex);

    Lock::Locker lock(&QueueLock);
    Queues[DIQueue_Captured].PushListToBack(Queues[DIQueue_Active]);
}

// @0x142670f20
void DICommandQueue::OnNextCapture(ContextImpl::RenderNotify* notify)
{
    // updating the images can drop the last outside reference to this queue
    AddRef();
    updateCPUModifiedImagesRT();
    ExecuteNextCapture(notify);
    Release();
}

// @0x142670f60
void DICommandQueue::OnShutdown()
{
    pDIContext->RemoveCaptureNotify(this);
    ImageList.Clear();
    pDIContext.Clear();
}

// Room for one command at the end of the active list; with too many pages out, the queue is run first.
// @0x142670fb0
void* DICommandQueue::allocCommandFromPage(unsigned size, Lock* locked)
{
    DIQueuePage* page = Queues[DIQueue_Active].GetLast();
    if (Queues[DIQueue_Active].IsNull(page) || !page->HasFreeSize(size))
    {
        if (!FreePageCount && AllocPageCount >= AllocPageLimit)
        {
            locked->Unlock();
            ExecuteCommandsAndWait();
            locked->DoLock();
        }
        page = allocPage();
    }
    if (!page)
        return 0;
    return page->AllocSize(size);
}

// @0x142671140
DIQueuePage* DICommandQueue::allocPage()
{
    DIQueuePage* page;
    if (!Queues[DIQueue_Free].IsEmpty())
    {
        page = Queues[DIQueue_Free].GetFirst();
        page->RemoveNode();
        FreePageCount--;
    }
    else
        page = SF_HEAP_AUTO_NEW(this) DIQueuePage;

    if (page)
        Queues[DIQueue_Active].PushBack(page);
    return page;
}

// ***** DICommand

// @0x1426711e0
bool DICommand::executeHWHelper(DICommandContext& context, DrawableImage* image) const
{
    // the HAL draws into the texture, so the CPU mapping goes first
    image->unmapTextureRT();
    ExecuteHW(context);
    if ((GetRenderCaps() & (RC_GPU | RC_GPU_NoRT)) == RC_GPU)
        image->addToGPUModifiedListRT();
    return true;
}

// @0x142671240
bool DICommand::executeSWHelper(DICommandContext& context, DrawableImage* image, DISourceImages& images,
                                unsigned imageCount, bool rtMap) const
{
    ImageData& dest = image->MappedData;
    if (imageCount)
    {
        ImageData  sourceData[2];
        ImageData* sources[2] = { 0, 0 };

        if (images[0] && !DrawableImage::MapImageSource(&sourceData[0], images[0], rtMap))
            return false;
        sources[0] = &sourceData[0];
        if (images[1] && !DrawableImage::MapImageSource(&sourceData[1], images[1], rtMap))
            return false;
        sources[1] = &sourceData[1];

        ExecuteSW(context, dest, sources);
    }
    else
        ExecuteSW(context, dest, 0);

    image->addToCPUModifiedList();
    return true;
}

// ***** DICommandQueue

// Whether every queued command can run on the CPU now.
// @0x142671440
bool DICommandQueue::isCPURenderable_NTS()
{
    return isPageListCPURenderable_NTS(Queues[DIQueue_Active]) &&
           isPageListCPURenderable_NTS(Queues[DIQueue_Displaying]) &&
           isPageListCPURenderable_NTS(Queues[DIQueue_Captured]);
}

// @0x142671490
bool DICommandQueue::isQueueEmpty_NTS() const
{
    return Queues[DIQueue_Displaying].IsEmpty() && Queues[DIQueue_Captured].IsEmpty() &&
           Queues[DIQueue_Active].IsEmpty();
}

// MS2-FUNCTIONAL: cl calls IsImageCPUReadable for the second source image where the exe inlines both
// @0x1426714c0
bool DICommandQueue::isPageListCPURenderable_NTS(List<DIQueuePage>& pages)
{
    for (DIQueuePage* page = pages.GetFirst(); !pages.IsNull(page); page = page->pNext)
    {
        for (DICommand* cmd = page->getFirst(); cmd; cmd = page->getNext(cmd))
        {
            if (!(cmd->GetRenderCaps() & DICommand::RC_CPU) || !cmd->IsCPUExecutable())
                return false;
        }
    }
    return true;
}

// The displaying pages, and for DICommand_All the captured and active ones after them.
// @0x142671660
void DICommandQueue::popCommandSet(DICommandSet* cmdSet, DICommandSetType type)
{
    Lock::Locker lock(&QueueLock);
    cmdSet->QueueList.PushListToBack(Queues[DIQueue_Displaying]);
    if (type == DICommand_All)
    {
        cmdSet->QueueList.PushListToBack(Queues[DIQueue_Captured]);
        cmdSet->QueueList.PushListToBack(Queues[DIQueue_Active]);
    }
}

// The images the CPU wrote get their render targets updated.
// @0x142671740
void DICommandQueue::updateCPUModifiedImagesRT()
{
    Lock::Locker lock(&QueueLock);

    Ptr<DrawableImage> image;
    Ptr<DrawableImage> modified = pCPUModifiedImageList;
    pCPUModifiedImageList.Clear();
    while (modified)
    {
        image = modified;
        image->updateRenderTargetRT();
        modified = image->pCPUModifiedNext;
        image->pCPUModifiedNext.Clear();
        image->DrawableImageState &= ~DrawableImage::DIState_CPUDirty;
    }
}

// The images the GPU wrote get their staging data updated.
// @0x142671830
void DICommandQueue::updateGPUModifiedImagesRT()
{
    Lock::Locker lock(&QueueLock);

    Ptr<DrawableImage> image;
    Ptr<DrawableImage> modified = pGPUModifiedImageList;
    pGPUModifiedImageList.Clear();
    while (modified)
    {
        image = modified;
        image->updateStagingTargetRT();
        modified = image->pGPUModifiedNext;
        image->pGPUModifiedNext.Clear();
        image->DrawableImageState &= ~DrawableImage::DIState_GPUDirty;
    }
}

// The source-rect command bases, copied and built by the queue (COMDATs of this TU in the exe, enum order).
template DICommand_SourceRectImpl<DICommand_ApplyFilter>::DICommand_SourceRectImpl(const DICommand_SourceRectImpl<DICommand_ApplyFilter>&);
template DICommand_SourceRectImpl<DICommand_ApplyFilter>::DICommand_SourceRectImpl(DrawableImage*, DrawableImage*, const Rect<SInt32>&, const Point<SInt32>&);
template DICommand_SourceRectImpl<DICommand_CopyChannel>::DICommand_SourceRectImpl(const DICommand_SourceRectImpl<DICommand_CopyChannel>&);
template DICommand_SourceRectImpl<DICommand_CopyChannel>::DICommand_SourceRectImpl(DrawableImage*, DrawableImage*, const Rect<SInt32>&, const Point<SInt32>&);
template DICommand_SourceRectImpl<DICommand_CopyPixels>::DICommand_SourceRectImpl(const DICommand_SourceRectImpl<DICommand_CopyPixels>&);
template DICommand_SourceRectImpl<DICommand_CopyPixels>::DICommand_SourceRectImpl(DrawableImage*, DrawableImage*, const Rect<SInt32>&, const Point<SInt32>&);
template DICommand_SourceRectImpl<DICommand_ColorTransform>::DICommand_SourceRectImpl(const DICommand_SourceRectImpl<DICommand_ColorTransform>&);
template DICommand_SourceRectImpl<DICommand_ColorTransform>::DICommand_SourceRectImpl(DrawableImage*, DrawableImage*, const Rect<SInt32>&, const Point<SInt32>&);
template DICommand_SourceRectImpl<DICommand_Compare>::DICommand_SourceRectImpl(const DICommand_SourceRectImpl<DICommand_Compare>&);
template DICommand_SourceRectImpl<DICommand_Compare>::DICommand_SourceRectImpl(DrawableImage*, DrawableImage*, const Rect<SInt32>&, const Point<SInt32>&);
template DICommand_SourceRectImpl<DICommand_Merge>::DICommand_SourceRectImpl(const DICommand_SourceRectImpl<DICommand_Merge>&);
template DICommand_SourceRectImpl<DICommand_Merge>::DICommand_SourceRectImpl(DrawableImage*, DrawableImage*, const Rect<SInt32>&, const Point<SInt32>&);
template DICommand_SourceRectImpl<DICommand_PaletteMap>::DICommand_SourceRectImpl(const DICommand_SourceRectImpl<DICommand_PaletteMap>&);
template DICommand_SourceRectImpl<DICommand_PaletteMap>::DICommand_SourceRectImpl(DrawableImage*, DrawableImage*, const Rect<SInt32>&, const Point<SInt32>&);
template DICommand_SourceRectImpl<DICommand_Scroll>::DICommand_SourceRectImpl(const DICommand_SourceRectImpl<DICommand_Scroll>&);
template DICommand_SourceRectImpl<DICommand_Scroll>::DICommand_SourceRectImpl(DrawableImage*, DrawableImage*, const Rect<SInt32>&, const Point<SInt32>&);
template DICommand_SourceRectImpl<DICommand_Threshold>::DICommand_SourceRectImpl(const DICommand_SourceRectImpl<DICommand_Threshold>&);
template DICommand_SourceRectImpl<DICommand_Threshold>::DICommand_SourceRectImpl(DrawableImage*, DrawableImage*, const Rect<SInt32>&, const Point<SInt32>&);
template struct DICommand_SourceRectImpl<DICommand_ApplyFilter>;
template struct DICommand_SourceRectImpl<DICommand_CopyChannel>;
template struct DICommand_SourceRectImpl<DICommand_CopyPixels>;
template struct DICommand_SourceRectImpl<DICommand_ColorTransform>;
template struct DICommand_SourceRectImpl<DICommand_Compare>;
template struct DICommand_SourceRectImpl<DICommand_Merge>;
template struct DICommand_SourceRectImpl<DICommand_PaletteMap>;
template struct DICommand_SourceRectImpl<DICommand_Scroll>;
template struct DICommand_SourceRectImpl<DICommand_Threshold>;

}} // namespace Scaleform::Render

// MS2-PIN: ??_7DICommandQueue@Render@Scaleform@@6B@ 0x143191a50
// MS2-PIN: ??_7ExecuteCommand@DICommandQueue@Render@Scaleform@@6B@ 0x143191a40
// MS2-PIN: ??_G?$RefCountBase@VDICommandQueue@Render@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x14266fed0
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_ApplyFilter@Render@Scaleform@@@Render@Scaleform@@QEAA@AEBU012@@Z 0x142671930
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_ApplyFilter@Render@Scaleform@@@Render@Scaleform@@QEAA@PEAVDrawableImage@12@0AEBV?$Rect@J@12@AEBV?$Point@J@12@@Z 0x142671960
// MS2-PIN: ??1?$DICommand_SourceRectImpl@UDICommand_ApplyFilter@Render@Scaleform@@@Render@Scaleform@@UEAA@XZ 0x142671ca0
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_ApplyFilter@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d088
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_CopyChannel@Render@Scaleform@@@Render@Scaleform@@QEAA@AEBU012@@Z 0x142671990
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_CopyChannel@Render@Scaleform@@@Render@Scaleform@@QEAA@PEAVDrawableImage@12@0AEBV?$Rect@J@12@AEBV?$Point@J@12@@Z 0x1426719c0
// MS2-PIN: ??1?$DICommand_SourceRectImpl@UDICommand_CopyChannel@Render@Scaleform@@@Render@Scaleform@@UEAA@XZ 0x142671ce0
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_CopyChannel@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d350
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_CopyPixels@Render@Scaleform@@@Render@Scaleform@@QEAA@AEBU012@@Z 0x1426719f0
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_CopyPixels@Render@Scaleform@@@Render@Scaleform@@QEAA@PEAVDrawableImage@12@0AEBV?$Rect@J@12@AEBV?$Point@J@12@@Z 0x142671a20
// MS2-PIN: ??1?$DICommand_SourceRectImpl@UDICommand_CopyPixels@Render@Scaleform@@@Render@Scaleform@@UEAA@XZ 0x142671d20
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_CopyPixels@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d410
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_ColorTransform@Render@Scaleform@@@Render@Scaleform@@QEAA@AEBU012@@Z 0x142671a50
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_ColorTransform@Render@Scaleform@@@Render@Scaleform@@QEAA@PEAVDrawableImage@12@0AEBV?$Rect@J@12@AEBV?$Point@J@12@@Z 0x142671a80
// MS2-PIN: ??1?$DICommand_SourceRectImpl@UDICommand_ColorTransform@Render@Scaleform@@@Render@Scaleform@@UEAA@XZ 0x142671d60
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_ColorTransform@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d1c8
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_Compare@Render@Scaleform@@@Render@Scaleform@@QEAA@AEBU012@@Z 0x142671ab0
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_Compare@Render@Scaleform@@@Render@Scaleform@@QEAA@PEAVDrawableImage@12@0AEBV?$Rect@J@12@AEBV?$Point@J@12@@Z 0x142671ae0
// MS2-PIN: ??1?$DICommand_SourceRectImpl@UDICommand_Compare@Render@Scaleform@@@Render@Scaleform@@UEAA@XZ 0x142671da0
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_Compare@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d288
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_Merge@Render@Scaleform@@@Render@Scaleform@@QEAA@AEBU012@@Z 0x142671b10
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_Merge@Render@Scaleform@@@Render@Scaleform@@QEAA@PEAVDrawableImage@12@0AEBV?$Rect@J@12@AEBV?$Point@J@12@@Z 0x142671b40
// MS2-PIN: ??1?$DICommand_SourceRectImpl@UDICommand_Merge@Render@Scaleform@@@Render@Scaleform@@UEAA@XZ 0x142671de0
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_Merge@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d5d0
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_PaletteMap@Render@Scaleform@@@Render@Scaleform@@QEAA@AEBU012@@Z 0x142671b70
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_PaletteMap@Render@Scaleform@@@Render@Scaleform@@QEAA@PEAVDrawableImage@12@0AEBV?$Rect@J@12@AEBV?$Point@J@12@@Z 0x142671ba0
// MS2-PIN: ??1?$DICommand_SourceRectImpl@UDICommand_PaletteMap@Render@Scaleform@@@Render@Scaleform@@UEAA@XZ 0x142671e20
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_PaletteMap@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d710
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_Scroll@Render@Scaleform@@@Render@Scaleform@@QEAA@AEBU012@@Z 0x142671bd0
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_Scroll@Render@Scaleform@@@Render@Scaleform@@QEAA@PEAVDrawableImage@12@0AEBV?$Rect@J@12@AEBV?$Point@J@12@@Z 0x142671c00
// MS2-PIN: ??1?$DICommand_SourceRectImpl@UDICommand_Scroll@Render@Scaleform@@@Render@Scaleform@@UEAA@XZ 0x142671e60
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_Scroll@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d850
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_Threshold@Render@Scaleform@@@Render@Scaleform@@QEAA@AEBU012@@Z 0x142671c30
// MS2-PIN: ??0?$DICommand_SourceRectImpl@UDICommand_Threshold@Render@Scaleform@@@Render@Scaleform@@QEAA@PEAVDrawableImage@12@0AEBV?$Rect@J@12@AEBV?$Point@J@12@@Z 0x142671c60
// MS2-PIN: ??1?$DICommand_SourceRectImpl@UDICommand_Threshold@Render@Scaleform@@@Render@Scaleform@@UEAA@XZ 0x142671ea0
// MS2-PIN: ??_7?$DICommand_SourceRectImpl@UDICommand_Threshold@Render@Scaleform@@@Render@Scaleform@@6B@ 0x14318d910
// MS2-PIN: ??_7?$RefCountBase@VThreadCommand@Render@Scaleform@@$01@Scaleform@@6B@ 0x143183980
// MS2-PIN: ??_7ThreadCommand@Render@Scaleform@@6B@ 0x143183928
// MS2-PIN: ??_7DICommand@Render@Scaleform@@6B@ 0x14318ce80
// MS2-PIN: ??_7DICommand_SourceRect@Render@Scaleform@@6B@ 0x14318d040
// MS2-PIN: ??_7?$RefCountBase@VDICommandQueue@Render@Scaleform@@$01@Scaleform@@6B@ 0x143191a38
