// Recovered Scaleform 4.1.18 GFx: queued movie load requests (loadMovie / unloadMovie / loadVariables).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
//
// Only the request kinds are recovered so far.
#ifndef MS2_SF_GFX_PLAYERTASKS_H
#define MS2_SF_GFX_PLAYERTASKS_H

namespace Scaleform { namespace GFx {

class LoadQueueEntry
{
public:
    // How the variables of the requesting clip go along with the request.
    enum LoadMethod
    {
        LM_None,
        LM_Get,
        LM_Post
    };
};

}} // namespace Scaleform::GFx

#endif
