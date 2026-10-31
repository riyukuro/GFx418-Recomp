// Recovered Scaleform 4.1.18 Render: ThreadCommand, a ref-counted unit of work pushed to the render thread.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_THREADCOMMAND_H
#define MS2_SF_RENDER_THREADCOMMAND_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_threads.h"

namespace Scaleform { namespace Render {

class ThreadCommand : public RefCountBase<ThreadCommand, Stat_Default_Mem>
{
public:
    // no user-declared destructor: the exe's deleting destructors never re-store the ThreadCommand vftable
    virtual void Execute() = 0;
};

class TextureManager;
class HAL;
class Renderer2D;

// The render objects a render thread hands out on request (not AddRef'ed: for immediate use only).
struct Interfaces
{
    TextureManager* pTextureManager;
    HAL*            pHAL;
    Renderer2D*     pRenderer2D;
    ThreadId        RenderThreadID;

    Interfaces(TextureManager* textureManager = 0, HAL* hal = 0, Renderer2D* r2d = 0, ThreadId tid = 0)
        : pTextureManager(textureManager), pHAL(hal), pRenderer2D(r2d), RenderThreadID(tid)
    {
    }
    // member-wise, as in the SDK: the exe copies with four qword moves
    Interfaces(const Interfaces& other)
        : pTextureManager(other.pTextureManager), pHAL(other.pHAL), pRenderer2D(other.pRenderer2D),
          RenderThreadID(other.RenderThreadID)
    {
    }
    void Clear()
    {
        pTextureManager = 0;
        pHAL            = 0;
        pRenderer2D     = 0;
        RenderThreadID  = 0;
    }
};

// Implemented by the render thread: commands pushed here run on it (they stay AddRef'ed until executed).
class ThreadCommandQueue
{
public:
    virtual ~ThreadCommandQueue() {}
    virtual void PushThreadCommand(ThreadCommand* command) = 0;
    virtual void GetRenderInterfaces(Interfaces* p) { p->Clear(); }
};

}} // namespace Scaleform::Render

#endif
