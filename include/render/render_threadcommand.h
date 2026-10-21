// Recovered Scaleform 4.1.18 Render: ThreadCommand, a ref-counted unit of work pushed to the render thread.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_THREADCOMMAND_H
#define MS2_SF_RENDER_THREADCOMMAND_H

#include "ms2/scaleform/kernel/sf_refcount.h"

namespace Scaleform { namespace Render {

class ThreadCommand : public RefCountBase<ThreadCommand, Stat_Default_Mem>
{
public:
    // no user-declared destructor: the exe's deleting destructors never re-store the ThreadCommand vftable
    virtual void Execute() = 0;
};

}} // namespace Scaleform::Render

#endif
