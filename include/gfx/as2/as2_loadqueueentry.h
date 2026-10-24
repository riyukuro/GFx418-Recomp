// Recovered Scaleform GFx 4.1.18 AS2: a queued AS2 load. 0xc8 bytes; vftable 0x143217748 (??_G 0x14292b0c0).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_LOADQUEUEENTRY_H
#define MS2_SF_GFX_AS2_LOADQUEUEENTRY_H

#include "as2_movieroot.h"
#include "../gfx_playertasks.h"
#include "as2_loadqueue.h"   // (sfr24) GFxAS2LoadCSSTask / GFxAS2LoadXMLTask

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

// (sfr24) The loader-thread entries an AS2 movie makes for its queued loads (MovieRoot::AddLoadQueueEntryMT
// 0x14292fc90); the movie polls LoadFinished. Layouts from the ctors and the LoadFinished bodies.

// A loadMovie / level load: a MoviePreloadTask reads the file, then the new sprite replaces the old character.
// 0x58 bytes; vftable 0x143217750 (??_G 0x14292b270).
class GFxAS2LoadQueueEntryMT_LoadMovie : public LoadQueueEntryMT
{
    friend class GFx::MovieImpl;

    Ptr<MoviePreloadTask>  pPreloadTask;     // +0x28
    Ptr<Sprite>            pNewChar;         // +0x30
    bool                   FirstCheck;       // +0x38 (not set by the ctor)
    Ptr<InteractiveObject> pOldChar;         // +0x40
    ResourceId             NewCharId;        // +0x48 (0x10001, the empty movie clip id)
    bool                   CharSwitched;     // +0x4c
    unsigned               BytesLoaded;      // +0x50
    bool                   FirstFrameLoaded; // +0x54

public:
    GFxAS2LoadQueueEntryMT_LoadMovie(LoadQueueEntry* pqueueEntry, MovieImpl* pmovieImpl); // exe 0x14291c690
    ~GFxAS2LoadQueueEntryMT_LoadMovie();                                                   // exe 0x142925890

    bool LoadFinished();         // exe 0x142966650
    bool IsPreloadingFinished(); // exe 0x142965da0 (pPreloadTask->IsDone())
};
static_assert(sizeof(GFxAS2LoadQueueEntryMT_LoadMovie) == 0x58, "GFxAS2LoadQueueEntryMT_LoadMovie size");

// An XML.load: a GFxAS2LoadXMLTask reads the file, then the loader hands it to the XML object.
// 0x40 bytes; vftable 0x143217780 (??_G 0x14292b300, dtor inlined there).
class GFxAS2LoadQueueEntryMT_LoadXML : public LoadQueueEntryMT
{
    Ptr<GFxAS2LoadXMLTask> pTask;        // +0x28
    Ptr<LoadStates>        pLoadStates;  // +0x30
    MovieRoot*             pASMovieRoot; // +0x38

public:
    GFxAS2LoadQueueEntryMT_LoadXML(LoadQueueEntry* pqueueEntry, MovieRoot* pmovieRoot); // exe 0x14291c910
    ~GFxAS2LoadQueueEntryMT_LoadXML();

    bool LoadFinished(); // exe 0x142967010
};
static_assert(sizeof(GFxAS2LoadQueueEntryMT_LoadXML) == 0x40, "GFxAS2LoadQueueEntryMT_LoadXML size");

// A TextField.StyleSheet.load: a GFxAS2LoadCSSTask reads and parses the file.
// 0x38 bytes; vftable 0x1432177b0 (??_G 0x14292b1e0, dtor inlined there).
class GFxAS2LoadQueueEntryMT_LoadCSS : public LoadQueueEntryMT
{
    Ptr<GFxAS2LoadCSSTask> pTask;       // +0x28
    Ptr<LoadStates>        pLoadStates; // +0x30

public:
    GFxAS2LoadQueueEntryMT_LoadCSS(LoadQueueEntry* pqueueEntry, MovieRoot* pmovieRoot); // exe 0x14291c400
    ~GFxAS2LoadQueueEntryMT_LoadCSS();

    bool LoadFinished(); // exe 0x1429665a0
};
static_assert(sizeof(GFxAS2LoadQueueEntryMT_LoadCSS) == 0x38, "GFxAS2LoadQueueEntryMT_LoadCSS size");

}}} // namespace Scaleform::GFx::AS2

#endif
