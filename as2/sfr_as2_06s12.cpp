// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 XML.load of sfr_as2_06 (gap
// recovery, lane sfr24): the loader-thread entry polled by the movie and the load done on the movie thread.
// MS2-UNIT: sfr_as2_06s12
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142967010-0x1429670e0 .text$mn
// MS2-RANGE: 0x142971660-0x1429718b0 .text$mn
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_loadqueueentry.h"
#include "../include/gfx/gfx_asutils.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_movieimpl.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {

// MovieRoot::GetLevelMovie, inlined in the exe.
SF_FORCEINLINE InteractiveObject* LxLevelMovie(const MovieRoot* proot, int level)
{
    MovieImpl* pmovie = proot->pMovieImpl;
    for (unsigned i = 0; i < pmovie->MovieLevelsSize; i++)
    {
        if (pmovie->pMovieLevels[i].Level == level)
            return pmovie->pMovieLevels[i].pSprite;
    }
    return 0;
}

// MovieRoot::GetLevel0Path, inlined in the exe.
SF_FORCEINLINE void LxLevel0Path(const MovieRoot* proot, String* ppath)
{
    if (LxLevelMovie(proot, 0))
    {
        *ppath = proot->pMovieImpl->pMainMovieDef->GetFileURL();
        if (URLBuilder::ExtractFilePath(ppath))
            return;
    }
    ppath->Clear();
}

// The script environment of a character.
SF_FORCEINLINE Environment* LxCharEnv(InteractiveObject* pchar)
{
    AvmDisplayObjBase* pavm = pchar->GetAvmObjImpl();
    return static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pavm))->GetASEnvironment();
}

} // namespace

// The XML is handed to its object once the loader thread has read it; a canceled load just waits for its task.
// MS2-FUNCTIONAL: register allocation differs.
// @0x142967010
bool GFxAS2LoadQueueEntryMT_LoadXML::LoadFinished()
{
    bool                  done   = pTask->IsDone();
    GFxAS2LoadQueueEntry* pentry = static_cast<GFxAS2LoadQueueEntry*>(pQueueEntry);
    if (pentry->Canceled && done)
        return true;
    if (!done)
        return false;
    Environment*   penv    = LxCharEnv(LxLevelMovie(pASMovieRoot, 0));
    XMLFileLoader* ploader = static_cast<XMLFileLoader*>(pentry->XMLHolder.Loader.GetPtr());
    ploader->InitASXml(penv, pentry->XMLHolder.ASObj.ToObject(penv));
    return true;
}

// An XML.load done on the movie thread: the loader reads the file, then fills the XML object.
// MS2-FUNCTIONAL: register allocation differs.
// @0x142971660
void MovieRoot::ProcessLoadXML(GFx::LoadQueueEntry* pentry, LoadStates* pls)
{
    String level0Path;
    LxLevel0Path(this, &level0Path);
    if (pentry->URL.GetLength())
    {
        URLBuilder::LocationInfo loc(URLBuilder::File_LoadXML, pentry->URL, level0Path);
        String                   url;
        pls->BuildURL(&url, loc);
        GFxAS2LoadQueueEntry* pas2entry = static_cast<GFxAS2LoadQueueEntry*>(pentry);
        XMLFileLoader*        ploader   = static_cast<XMLFileLoader*>(pas2entry->XMLHolder.Loader.GetPtr());
        ploader->Load(String(url.ToCStr()), static_cast<FileOpener*>(pls->GetBindStates()->pFileOpener.GetPtr()));
        Environment* penv = LxCharEnv(LxLevelMovie(this, 0));
        ploader = static_cast<XMLFileLoader*>(pas2entry->XMLHolder.Loader.GetPtr());
        ploader->InitASXml(penv, pas2entry->XMLHolder.ASObj.ToObject(penv));
    }
}

}}} // namespace Scaleform::GFx::AS2
