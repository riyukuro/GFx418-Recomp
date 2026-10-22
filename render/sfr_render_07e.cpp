// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the GPU fence bookkeeping
// (Render_Sync): per frame fence lists, fence handles that outlive their frame, frame retirement in EndFrame.
// Queue unit sfr_render_07 is split along its original sources (07e Render_Sync).
// MS2-UNIT: sfr_render_07e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426e05a0-0x1426e1200 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_sync.h"

namespace Scaleform { namespace Render {

// @0x1426e0f70
bool FenceImpl::IsPending(FenceType waitType) const
{
    if (!Parent)
        return false;
    return RSContext->IsPending(waitType, APIHandle, *Parent);
}

// @0x1426e11e0
void FenceImpl::WaitFence(FenceType waitType) const
{
    if (!Parent)
        return;
    RSContext->WaitFence(waitType, APIHandle, *Parent);
}

// @0x1426e07e0
bool FenceImpl::operator>(const FenceImpl& f) const
{
    return FenceID > f.FenceID;
}

// The last reference frees the handle. While the fence still has its FenceImpl the API fence is released through
// the union member that aliases Data (the shipped code does this), then both go back to their allocators.
// @0x1426e0f90
void Fence::Release()
{
    if (--RefCount == 0)
    {
        if (HasData)
        {
            RenderSync* ctx = Data->RSContext;
            RSContext->ReleaseFence(Data->APIHandle);
            ctx->FenceImplAlloc.Free(Data);
            ctx->FenceAlloc.Free(this);
        }
        else
            RSContext->FenceAlloc.Free(this);
    }
}

// Retiring a frame detaches its fences from their FenceImpl; handles still held elsewhere keep only the RenderSync.
// @0x1426e05a0
FenceFrame::~FenceFrame()
{
    for (FenceHandleArray::Iterator it = Fences.Begin(); it != Fences.End(); ++it)
    {
        if ((*it)->HasData)
        {
            (*it)->HasData = 0;
            RSContext->ReleaseFence((*it)->Data->APIHandle);
            RSContext->FenceImplAlloc.Free((*it)->Data);
            (*it)->RSContext = RSContext;
        }
    }
    Fences.Clear();
    FrameEndFence = 0;
}

// @0x1426e1010
void RenderSync::ReleaseOutstandingFrames()
{
    FenceFrame* frame = FenceFrames.GetFirst();
    while (!FenceFrames.IsNull(frame))
    {
        FenceFrame* next = frame->pNext;
        frame->RemoveNode();
        FenceFrameAlloc.Free(frame);
        frame = next;
        OutstandingFrames--;
    }
}

// @0x1426e06d0
RenderSync::~RenderSync()
{
    ReleaseOutstandingFrames();
}

// @0x1426e0ac0
void RenderSync::BeginFrame()
{
    FenceFrame* frame = FenceFrameAlloc.Alloc();
    frame->RSContext  = this;
    FenceFrames.PushBack(frame);
    OutstandingFrames++;
}

// @0x1426e0db0
Fence* RenderSync::InsertFence()
{
    if (FenceFrames.IsEmpty())
        return 0;

    UInt64     apiHandle = SetFence();
    FenceImpl* pf        = FenceImplAlloc.Alloc();
    ::new(pf) FenceImpl(this, FenceFrames.GetLast(), apiHandle, ++NextFenceID);

    Fence* f   = FenceAlloc.Alloc();
    f->HasData = 1;
    f->Data    = pf;
    Ptr<Fence> fh = *f;
    FenceFrames.GetLast()->Fences.PushBack(fh);
    return fh;
}

// Puts the end of frame fence, then frees every frame before the last whose end fence the GPU has passed.
// @0x1426e0c60
bool RenderSync::EndFrame()
{
    if (FenceFrames.IsEmpty())
        return false;

    FenceFrames.GetLast()->FrameEndFence = InsertFence();
    bool wrapped = CheckWraparound(FenceFrames.GetLast()->FrameEndFence->GetFencePtr()->GetAPIHandle());

    FenceFrame* frame = FenceFrames.GetFirst();
    while (frame != FenceFrames.GetLast())
    {
        if (!frame->FrameEndFence || frame->FrameEndFence->IsPending(FenceType_Fragment))
            break;
        FenceFrame* next = frame->pNext;
        frame->RemoveNode();
        FenceFrameAlloc.Free(frame);
        frame = next;
        OutstandingFrames--;
    }

    if (wrapped)
    {
        for (FenceFrame* f = FenceFrames.GetFirst(); !FenceFrames.IsNull(f); f = f->pNext)
            f->WrappedAround = true;
    }
    return true;
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7RenderSync@Render@Scaleform@@6B@ 0x143193f08
