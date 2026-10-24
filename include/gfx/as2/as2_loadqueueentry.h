// Recovered Scaleform GFx 4.1.18 AS2: a queued AS2 load. 0xc8 bytes; vftable 0x143217748 (??_G 0x14292b0c0).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_LOADQUEUEENTRY_H
#define MS2_SF_GFX_AS2_LOADQUEUEENTRY_H

#include "as2_movieroot.h"
#include "../gfx_playertasks.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// A queued AS2 load: the target clip or level and the objects to notify (movie clip loader, LoadVars, XML,
// style sheet with its file loader).
class GFxAS2LoadQueueEntry : public LoadQueueEntry
{
public:
    struct HolderType
    {
        Value             ASObj;
        Ptr<RefCountImpl> Loader;
    };

    int                  Level;                 // +0x28
    Ptr<CharacterHandle> pCharacter;            // +0x30
    Value                MovieClipLoaderHolder; // +0x38
    Value                LoadVarsHolder;        // +0x58
    HolderType           XMLHolder;             // +0x78
    HolderType           CSSHolder;             // +0xa0

    GFxAS2LoadQueueEntry(CharacterHandle* pchar, const String& url, LoadMethod method, bool loadingVars = false,
                         bool quietOpen = false)
        : LoadQueueEntry(url, method, loadingVars, quietOpen)
    {
        PConstruct(pchar, -1);
    }
    // A load into _level<level> (exe 0x14291c320).
    GFxAS2LoadQueueEntry(int level, const String& url, LoadMethod method, bool loadingVars = false,
                         bool quietOpen = false);

    void PConstruct(CharacterHandle* pchar, int level); // exe 0x14296e6c0
};
static_assert(sizeof(GFxAS2LoadQueueEntry) == 0xc8, "GFxAS2LoadQueueEntry size");

}}} // namespace Scaleform::GFx::AS2

#endif
