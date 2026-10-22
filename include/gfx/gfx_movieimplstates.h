// Recovered Scaleform 4.1.18 GFx: the MovieImpl state getters (declared in gfx_movieimpl.h), defined once the state
// classes are complete (sfr12). They go through the movie's StateBag at +0x10.
#ifndef MS2_SF_GFX_MOVIEIMPLSTATES_H
#define MS2_SF_GFX_MOVIEIMPLSTATES_H

#include "gfx_movieimpl.h"
#include "gfx_moviedef.h"
#include "gfx_log.h"
#include "gfx_imemanager.h"

namespace Scaleform { namespace GFx {

inline Ptr<Log> MovieImpl::GetLog() const
{
    return GetStateBag()->GetLog();
}

inline Ptr<LogState> MovieImpl::GetLogState() const
{
    return GetStateBag()->GetLogState();
}

inline Ptr<IMEManagerBase> MovieImpl::GetIMEManager() const
{
    return *(IMEManagerBase*)GetStateBag()->GetStateAddRef(State::State_IMEManager);
}

}} // namespace Scaleform::GFx

#endif
