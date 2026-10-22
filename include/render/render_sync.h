// Recovered Scaleform 4.1.18 Render: GPU fences (Render_Sync). RenderSync hands out Fence handles (ref counted,
// paged); each points at a FenceImpl (the API handle plus an ordering id) owned by the FenceFrame it was inserted
// in. When a frame is retired its fences lose their FenceImpl and keep only the RenderSync, so that a handle that
// outlives its frame can still free itself. The HAL's sync object (D3D9 queries) implements the pure virtuals.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layouts from the exe (0x1426e05a0..0x1426e11fb): FenceImpl 0x20, Fence 0x10 (RefCount +8, HasData +0xa),
// FenceFrame 0x40 (RSContext +0x10, WrappedAround +0x18, Fences +0x20, FrameEndFence +0x38), RenderSync 0xa8
// (FenceFrames +0x10, the three page allocators +0x20 / +0x48 / +0x70, NextFenceID +0x98, OutstandingFrames +0xa0).
#ifndef MS2_SF_RENDER_SYNC_H
#define MS2_SF_RENDER_SYNC_H

#include "ms2/scaleform/kernel/sf_memory.h"
#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_listalloc.h"

namespace Scaleform { namespace Render {

class FenceImpl;
class Fence;
class FenceFrame;
class RenderSync;

enum FenceType
{
    FenceType_Vertex,
    FenceType_Fragment
};

class FenceImpl
{
    friend class RenderSync;
    friend class FenceFrame;
    friend class Fence;

public:
    FenceImpl() : RSContext(0), Parent(0), APIHandle(0), FenceID(0) { }
    FenceImpl(RenderSync* ctx, FenceFrame* parent, UInt64 apiHandle, UInt64 id)
        : RSContext(ctx), Parent(parent), APIHandle(apiHandle), FenceID(id) { }

    // a fence whose frame has been retired has passed
    bool IsPending(FenceType waitType) const;                   // 0x1426e0f70
    void WaitFence(FenceType waitType) const;                   // 0x1426e11e0
    const FenceFrame* GetFrame() const { return Parent; }
    bool   operator>(const FenceImpl& f) const;            // 0x1426e07e0
    UInt64 GetAPIHandle() const { return APIHandle; }

protected:
    RenderSync* RSContext;   // +0x00
    FenceFrame* Parent;      // +0x08, 0 once the frame is retired
    UInt64      APIHandle;   // +0x10
    UInt64      FenceID;     // +0x18
};

class Fence
{
    friend class RenderSync;
    friend class FenceFrame;

public:
    Fence() : Data(0), RefCount(1), HasData(0) { }
    Fence(FenceImpl* f) : Data(f), RefCount(1), HasData(1) { }

    bool IsPending(FenceType waitType) const { return (HasData && Data) ? Data->IsPending(waitType) : false; }
    void WaitFence(FenceType waitType) const { if (HasData && Data) Data->WaitFence(waitType); }
    bool operator>(const Fence& f)
    {
        if (!Data)
            return false;
        if (!f.Data)
            return true;
        return *Data > *f.Data;
    }
    const FenceImpl* GetFencePtr() const { return HasData ? Data : 0; }

    void AddRef() { RefCount++; }
    void Release();                                             // 0x1426e0f90

private:
    union
    {
        FenceImpl*  Data;        // HasData != 0
        RenderSync* RSContext;   // HasData == 0: the frame was retired
    };
    UInt16 RefCount;             // +0x08
    UInt8  HasData;              // +0x0a
};

class FenceFrame : public NewOverrideBase<Stat_Default_Mem>, public ListNode<FenceFrame>
{
    friend class RenderSync;
    friend class Fence;

    typedef ArrayConstPolicy<128, 64, true>                               FenceHandleArrayPolicy;
    typedef ArrayLH<Ptr<Fence>, Stat_Default_Mem, FenceHandleArrayPolicy> FenceHandleArray;

public:
    FenceFrame() : ListNode<FenceFrame>(), WrappedAround(false), FrameEndFence(0) { }
    ~FenceFrame();                                              // 0x1426e05a0

    const Fence* GetFenceEndFrame() const { return FrameEndFence; }
    bool         IsWrappedFrame() const   { return WrappedAround; }

protected:
    RenderSync*      RSContext;       // +0x10
    bool             WrappedAround;   // +0x18
    FenceHandleArray Fences;          // +0x20
    Ptr<Fence>       FrameEndFence;   // +0x38
};

class RenderSync : public RefCountBase<RenderSync, Stat_Default_Mem>
{
    friend class FenceFrame;
    friend class FenceImpl;
    friend class Fence;

public:
    RenderSync() : NextFenceID(0), OutstandingFrames(0) { }
    virtual ~RenderSync();                                      // 0x1426e06d0

    virtual void BeginFrame();                                  // 0x1426e0ac0
    virtual bool EndFrame();                                    // 0x1426e0c60
    Fence*       InsertFence();                                 // 0x1426e0db0
    virtual void KickOffFences(FenceType waitType) = 0;

protected:
    virtual bool   IsPending(FenceType waitType, UInt64 handle, const FenceFrame& parent) = 0;
    virtual void   WaitFence(FenceType waitType, UInt64 handle, const FenceFrame& parent) = 0;
    virtual UInt64 SetFence() = 0;
    virtual bool   CheckWraparound(UInt64) { return false; }
    virtual void   ReleaseFence(UInt64) { }

    void ReleaseOutstandingFrames();                            // 0x1426e1010

    List<FenceFrame>           FenceFrames;        // +0x10
    ListAllocLH<FenceFrame>    FenceFrameAlloc;    // +0x20
    ListAllocLH_POD<FenceImpl> FenceImplAlloc;     // +0x48
    ListAllocLH<Fence>         FenceAlloc;         // +0x70
    UInt64                     NextFenceID;        // +0x98
    unsigned                   OutstandingFrames;  // +0xa0
};

}} // namespace Scaleform::Render

#endif
