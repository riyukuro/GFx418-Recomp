// Recovered Scaleform GFx 4.1.18 AS3: the AS3 movie root's load requests (Loader.load/loadBytes, URLLoader.load)
// and the loader-thread entry that preloads a movie for one. Our own declarations from the exe's field accesses.
// Ctors in sfr_as3_15 (0x1424d7f90-0x1424d8350); dtors and MovieRoot::AddNewLoadQueueEntry in sfr_as3_16;
// LoadQueueEntryMT_LoadMovie::LoadFinished/IsPreloadingFinished in sfr_as3_18.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AS3_LOADQUEUE_H
#define MS2_SF_GFX_AS3_LOADQUEUE_H

#include "ms2/scaleform/include/kernel/sf_autoptr.h"
#include "ms2/scaleform/include/gfx/gfx_playertasks.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// The Loader's load-init notification, held by the entry while it is pending (body not recovered; a thread-safe
// counted object, released through RefCountImpl::Release).
class NotifyLoadInitC : public RefCountImpl
{
};

// One AS3 load request: the requesting Loader or URLLoader, the URLRequest, or the bytes of Loader.loadBytes.
// 0x60 bytes; vftable 0x14317d888.
class LoadQueueEntry : public GFx::LoadQueueEntry
{
public:
    // Loader.loadBytes: a copy of bytes' content. 0x1424d7f90
    LoadQueueEntry(Instances::fl_utils::ByteArray* bytes, Instances::fl_display::Loader* loader, LoadMethod method);
    // Loader.load: request's URL. 0x1424d81a0
    LoadQueueEntry(Instances::fl_net::URLRequest* request, Instances::fl_display::Loader* loader, LoadMethod method,
                   bool quietOpen = false);
    // URLLoader.load: a variables load of request's URL. 0x1424d8350
    LoadQueueEntry(Instances::fl_net::URLRequest* request, Instances::fl_net::URLLoader* loader, LoadMethod method,
                   bool quietOpen = false);
    virtual ~LoadQueueEntry();      // ??_G 0x1424e3020

    SPtr<Instances::fl_display::Loader>     mLoader;                    // +0x28
    SPtr<Instances::fl_net::URLLoader>      mURLLoader;                 // +0x30
    SPtr<Instances::fl_net::URLRequest>     mURLRequest;                // +0x38
    AutoPtr<ArrayPOD<UByte> >               mBytes;                     // +0x40 Loader.loadBytes
    Ptr<NotifyLoadInitC>                    NotifyLoadInitCInterface;   // +0x50
    bool                                    FirstExec;                  // +0x58
};

// The loader-thread side of a movie load: a MoviePreloadTask reads the file while the movie polls LoadFinished.
// 0x40 bytes; vftable 0x14317d890.
class LoadQueueEntryMT_LoadMovie : public GFx::LoadQueueEntryMT
{
    friend class GFx::MovieImpl;

    Ptr<MoviePreloadTask>   pPreloadTask;       // +0x28
    bool                    CharSwitched;       // +0x30
    unsigned                BytesLoaded;        // +0x34
    bool                    FirstFrameLoaded;   // +0x38

public:
    // Starts the preload task (stripped players try the .gfx name first) and cancels the pending entries of the
    // same Loader or URLLoader.
    LoadQueueEntryMT_LoadMovie(LoadQueueEntry* pqueueEntry, MovieImpl* pmovieImpl);
    ~LoadQueueEntryMT_LoadMovie() {}   // ??_G 0x1424e31e0

    virtual bool LoadFinished();            // 0x142515c60
    virtual bool IsPreloadingFinished();    // 0x142514a70
};

}}} // namespace Scaleform::GFx::AS3

#endif
