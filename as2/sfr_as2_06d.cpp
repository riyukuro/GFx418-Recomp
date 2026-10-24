// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 queued movie loads: the
// loader-thread loadMovie entry polled by the movie, the dispatch of a queued load by its type and the loadMovie /
// level load done on the movie thread.
// MS2-UNIT: sfr_as2_06d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142966650-0x142967010 .text$mn
// MS2-RANGE: 0x1429706b0-0x142971340 .text$mn
// MS2-RANGE: 0x142971340-0x142971360 .text$mn
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_loadqueueentry.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_imagecreator.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_movieimplstates.h"
#include "../include/gfx/gfx_playertasks.h"
#include "../include/gfx/gfx_sprite.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {

// MovieRoot::GetLevelMovie, inlined in the exe.
SF_FORCEINLINE InteractiveObject* LmLevelMovie(const MovieRoot* proot, int level)
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
SF_FORCEINLINE void LmLevel0Path(const MovieRoot* proot, String* ppath)
{
    if (LmLevelMovie(proot, 0))
    {
        *ppath = proot->pMovieImpl->pMainMovieDef->GetFileURL();
        if (URLBuilder::ExtractFilePath(ppath))
            return;
    }
    ppath->Clear();
}

// True when the movie of pchar is a stripped (.gfx) file.
SF_FORCEINLINE bool LmIsStripped(InteractiveObject* pchar)
{
    return (pchar->GetResourceMovieDef()->GetSWFFlags() & 0x10) != 0; // the SWF_Stripped flag;
}

// The emergency collection handler embedded at +0x30 of the movie's memory context (not a declared member).
SF_FORCEINLINE MemoryContextImpl::HeapLimit* LmHeapLimit(MemoryContextImpl* pmc)
{
    return reinterpret_cast<MemoryContextImpl::HeapLimit*>(reinterpret_cast<UByte*>(pmc) + 0x30);
}

// The script side of a character, 0 for none (ToAvmCharacter with its null test).
SF_FORCEINLINE AvmCharacter* LmAvmChar(InteractiveObject* pchar)
{
    return pchar ? ToAvmCharacter(pchar) : 0;
}

// The character as a sprite, 0 if it is not one.
SF_FORCEINLINE Sprite* LmCharToSprite(InteractiveObject* pchar)
{
    return pchar->IsSprite() ? static_cast<Sprite*>(pchar) : 0;
}

// The log of the movie (the state bag's Ptr is dropped at once).
SF_FORCEINLINE LogState* LmLogState(const MovieRoot* proot)
{
    return proot->pMovieImpl->GetStateBag()->GetLogState();
}

// Ptr assignment, spelled out so that it is inlined here as in the exe.
SF_FORCEINLINE void LmAssign(Ptr<InteractiveObject>& ptr, InteractiveObject* p)
{
    if (p)
        p->AddRef();
    if (ptr)
        ptr->Release();
    ptr.GetRawRef() = p;
}

} // namespace

// Polled by the movie until the loader thread has the movie: then the new sprite takes the place of the old clip
// (or level) once, the movie clip loader hears of the progress, and frame 0 runs when the first frame (with the
// extensions on) or the whole file is in. False while there is more to wait for.
// MS2-FUNCTIONAL: register allocation and block layout differ.
// @0x142966650
bool GFxAS2LoadQueueEntryMT_LoadMovie::LoadFinished()
{
    bool done = pPreloadTask->IsDone();
    // A canceled load still waits for its task.
    if (pQueueEntry->Canceled && done)
        return true;

    GFxAS2LoadQueueEntry* qe   = static_cast<GFxAS2LoadQueueEntry*>(pQueueEntry);
    MovieRoot*            root = static_cast<MovieRoot*>(pMovieImpl->pASMovieRoot);
    if (!done)
        return false;

    if (!pOldChar && qe->pCharacter)
    {
        // Resolved by name, as Flash does: a clip made with the same name as an existing child loses to it.
        DisplayObject* pobj = qe->pCharacter->ForceResolveCharacter(pMovieImpl);
        if (!pobj)
        {
            Sprite* pmovie0 = root->GetLevelMovie(0);
            if (pmovie0)
            {
                Environment*     penv = AvmSprite::FromSprite(pmovie0)->GetASEnvironment();
                MovieClipLoader* pmovieClipLoader =
                    static_cast<MovieClipLoader*>(qe->MovieClipLoaderHolder.ToObject(penv));
                if (pmovieClipLoader)
                    pmovieClipLoader->NotifyOnLoadError(penv, 0, "Error", 0);
            }
            return true;
        }
        LmAssign(pOldChar, pobj->IsInteractiveObject() ? static_cast<InteractiveObject*>(pobj) : 0);
        // The new clip keeps the old id, or the parent's timeline would bring the old one back.
        NewCharId = ResourceId(pOldChar->Id);
    }

    Sprite* pmovie0 = static_cast<Sprite*>(LmLevelMovie(root, 0));
    // Nothing more to do once _level0 is gone.
    if (!pmovie0)
        return true;
    Environment*     penv0 = AvmSprite::FromSprite(pmovie0)->GetASEnvironment();
    MovieClipLoader* pmovieClipLoader = static_cast<MovieClipLoader*>(qe->MovieClipLoaderHolder.ToObject(penv0));
    // penv0 and pmovie0 may go away below (a load into _level0).
    bool extensions = penv0->CheckExtensions();

    MovieDefImpl* pdefImpl = pPreloadTask->GetMoiveDefImpl();
    if (!pdefImpl)
    {
        // The file could not be loaded: a clip is replaced by an empty one.
        if (qe->pCharacter)
        {
            InteractiveObject* pparent = pOldChar->pParent;
            if (!pparent)
                return true;
            CharacterCreateInfo ccinfo =
                pparent->GetResourceMovieDef()->GetCharacterCreateInfo(ResourceId(0x10001)); // the empty movie clip
            Ptr<Sprite> emptyChar = *static_cast<Sprite*>(root->pAS2Support->CreateCharacterInstance(
                pMovieImpl, ccinfo, pparent, NewCharId, CharacterDef::Sprite));
            // The same create frame, depth and name keep the parent's timeline from rebuilding the old clip.
            emptyChar->CreateFrame = pOldChar->CreateFrame;
            emptyChar->Depth       = pOldChar->Depth;
            if (!pOldChar->IsInstanceBasedNameFlagSet())
                emptyChar->SetName(pOldChar->GetName());
            emptyChar->AddToPlayList();
            ToAvmCharacter(pparent)->ReplaceChildCharacterOnLoad(pOldChar, emptyChar);
            pOldChar->pParent = 0;
            pOldChar          = emptyChar;
        }
        else if (qe->Level != -1)
            LmAssign(pOldChar, root->GetLevelMovie(qe->Level));
        if (pOldChar && pmovieClipLoader)
        {
            Environment* penv = ToAvmCharacter(pOldChar)->GetASEnvironment();
            pmovieClipLoader->NotifyOnLoadError(penv, pOldChar, "URLNotFound", 0);
        }
        if (qe->Level != -1)
            pMovieImpl->ReleaseLevelMovie(qe->Level);
        return true;
    }

    // The clip being replaced went away while its movie loaded (its parents may be gone too).
    if (pOldChar && (pOldChar->IsUnloaded() || pOldChar->IsUnloading()))
        return true;

    // An AS3 movie (version 9 and up with the AS3 file attribute) cannot play here.
    if (pdefImpl->GetVersion() != ~0u && pdefImpl->GetVersion() >= 9 &&
        ((pdefImpl->GetDataDef()->GetFileAttributes() & 8) ? 3 : 2) > 2)
    {
        pQueueEntry->Canceled = true;
        LogState* plog = root->pMovieImpl->GetStateBag()->GetLogState();
        if (plog && !qe->QuietOpen)
        {
            LmLogState(root)->LogScriptWarning(
                "Failed loading SWF \"%s\": ActionScript version mismatch", qe->URL.ToCStr());
        }
        if (pOldChar && pmovieClipLoader)
        {
            Environment* penv = ToAvmCharacter(pOldChar)->GetASEnvironment();
            pmovieClipLoader->NotifyOnLoadError(penv, pOldChar, "ActionScriptMismatch", 0);
        }
        return true;
    }

    if (!CharSwitched)
    {
        // The new sprite takes the place of the old one, once per load.
        InteractiveObject* pparent = 0;
        if (qe->Level != -1)
        {
            pMovieImpl->ReleaseLevelMovie(qe->Level);
            NewCharId = ResourceId();
        }
        else if (qe->pCharacter)
        {
            pparent = pOldChar->pParent;
            if (!pparent)
                return true;
        }
        CharacterCreateInfo ccinfo   = { pdefImpl->GetDataDef(), pdefImpl, 0 };
        Ptr<Sprite>         pnewChar = *static_cast<Sprite*>(root->pASSupport->CreateCharacterInstance(
            root->pMovieImpl, ccinfo, pparent, NewCharId, CharacterDef::Sprite));
        pnewChar->SetLoadedSeparately();
        if (!extensions)
            pnewChar->SetNoAdvanceLocalFlag();

        if (qe->pCharacter)
        {
            pnewChar->AddToPlayList();
            pnewChar->CreateFrame = pOldChar->CreateFrame;
            pnewChar->Depth       = pOldChar->Depth;
            if (!pOldChar->IsInstanceBasedNameFlagSet())
                pnewChar->SetName(pOldChar->GetName());
            LmAvmChar(pparent)->ReplaceChildCharacter(pOldChar, pnewChar);
            pOldChar->pParent = 0;
        }
        else
        {
            AvmSprite::FromSprite(pnewChar)->SetLevel(qe->Level);
            pMovieImpl->SetLevelMovie(qe->Level, pnewChar);
            // Frame 0 is run here, before onLoadInit.
            pMovieImpl->Flags &= ~MovieImpl::Flag_LevelClipsChanged;
        }
        // No advance until the first frame is in.
        pnewChar->SetPlayState(State_Stopped);

        pOldChar = pnewChar;
        if (pmovieClipLoader)
        {
            Environment* penv = ToAvmCharacter(pOldChar)->GetASEnvironment();
            pmovieClipLoader->NotifyOnLoadStart(penv, pOldChar);
            BytesLoaded = pdefImpl->pBindData->GetBytesLoaded();
            pmovieClipLoader->NotifyOnLoadProgress(penv, pOldChar, BytesLoaded, pdefImpl->GetDataDef()->GetFileBytes());
        }
        CharSwitched = true;
    }

    // More bytes since the last poll.
    if (BytesLoaded != pdefImpl->pBindData->GetBytesLoaded() && pmovieClipLoader)
    {
        Environment* penv = LmAvmChar(pOldChar)->GetASEnvironment();
        BytesLoaded       = pdefImpl->pBindData->GetBytesLoaded();
        pmovieClipLoader->NotifyOnLoadProgress(penv, pOldChar, BytesLoaded, pdefImpl->GetDataDef()->GetFileBytes());
    }
    // With the extensions on the movie starts once its first frame is in (Flash waits for the whole file).
    if (extensions && !FirstFrameLoaded && (pdefImpl->pBindData->GetBindState() & MovieDefImpl::BSF_Frame1Loaded) != 0)
    {
        Ptr<Sprite> psprite;
        if (qe->Level == -1)
            psprite = LmCharToSprite(pOldChar);
        else
            psprite = root->GetLevelMovie(qe->Level);
        if (psprite)
        {
            psprite->SetPlayState(State_Playing);
            psprite->SetRootNodeLoadingStat(pdefImpl->pBindData->GetBytesLoaded(), pdefImpl->GetLoadingFrame());
            // Not OnEventLoad: onLoad comes after the first frame.
            psprite->ExecuteFrame0Events();
            root->DoActions();
            if (pmovieClipLoader)
            {
                Environment* penv = AvmSprite::FromSprite(psprite)->GetASEnvironment();
                pmovieClipLoader->NotifyOnLoadInit(penv, psprite);
            }
        }
        FirstFrameLoaded = true;
    }
    // Not all in yet: again on the next poll.
    if ((pdefImpl->pBindData->GetBindState() & (MovieDefImpl::BS_InProgress | MovieDefImpl::BS_Finished)) <
        MovieDefImpl::BS_Finished)
        return false;

    if (pdefImpl->pBindData->GetBindState() & MovieDefImpl::BS_Finished)
    {
        Ptr<Sprite> psprite;
        if (qe->Level == -1)
        {
            psprite = LmCharToSprite(pOldChar);
            root->ResolveStickyVariables(pOldChar);
        }
        else
            psprite = root->GetLevelMovie(qe->Level);
        if (psprite)
        {
            if (!extensions)
                psprite->SetNoAdvanceLocalFlag(false);
            if (pmovieClipLoader)
            {
                Environment* penv = AvmSprite::FromSprite(psprite)->GetASEnvironment();
                pmovieClipLoader->NotifyOnLoadComplete(penv, psprite, 0);
            }
            // Frame 0 now unless it ran with the first frame.
            if (!FirstFrameLoaded)
            {
                psprite->SetPlayState(State_Playing);
                psprite->SetRootNodeLoadingStat(pdefImpl->pBindData->GetBytesLoaded(), pdefImpl->GetLoadingFrame());
                psprite->ExecuteFrame0Events();
                root->DoActions();
                if (pmovieClipLoader)
                {
                    Environment* penv = AvmSprite::FromSprite(psprite)->GetASEnvironment();
                    pmovieClipLoader->NotifyOnLoadInit(penv, psprite);
                }
            }
            FirstFrameLoaded = true;
        }
    }
    else if (pmovieClipLoader)
    {
        // The load failed or was canceled.
        Environment* penv = LmAvmChar(pOldChar)->GetASEnvironment();
        pmovieClipLoader->NotifyOnLoadError(
            penv, pOldChar, pdefImpl->GetDataDef()->GetLoadState() == MovieDataDef::LS_LoadError ? "Error" : "Canceled",
            0);
    }
    return true;
}

// A loadMovie / unloadMovie into a clip or a level: the new sprite takes the place (id, depth, name) of the old
// one, then the movie clip loader of the request hears how it went.
// MS2-FUNCTIONAL: register allocation and block layout differ (one large body, the level searches inlined).
// @0x1429706b0
void MovieRoot::ProcessLoadMovieClip(GFx::LoadQueueEntry* p_entry, LoadStates* pls)
{
    GFxAS2LoadQueueEntry* pentry = static_cast<GFxAS2LoadQueueEntry*>(p_entry);
    // Before the level can be unloaded below.
    String level0Path;
    LmLevel0Path(this, &level0Path);

    String                 url(pentry->URL), urlStrGfx;
    Ptr<InteractiveObject> poldChar;
    InteractiveObject*     pparent   = 0;
    ResourceId             newCharId(0x10001); // the empty movie clip
    LogState*              plog      = pls->GetLogState();
    unsigned               loadFlags = pMovieImpl->pMainMovieDef->GetLoadFlags();
    Ptr<MovieDefImpl>      pmovieDef;
    Ptr<Sprite>            pnewChar;
    bool                   stripped = false;

    if (pentry->pCharacter)
    {
        // Into a clip: it is always resolved by name, and the new one keeps its id so that the parent's timeline
        // does not bring the old one back.
        poldChar = static_cast<InteractiveObject*>(pentry->pCharacter->ForceResolveCharacter(pMovieImpl));
        if (!poldChar)
            return;
        if ((pparent = poldChar->GetParent()) == 0)
            return;
        stripped  = LmIsStripped(poldChar);
        newCharId = ResourceId(poldChar->Id);
    }
    else if (pentry->Level != -1)
    {
        if (LmLevelMovie(this, pentry->Level))
            stripped = LmIsStripped(LmLevelMovie(this, pentry->Level));
        else if (LmLevelMovie(this, 0))
            stripped = LmIsStripped(LmLevelMovie(this, 0));
        // This may unload every level.
        pMovieImpl->ReleaseLevelMovie(pentry->Level);
        newCharId = ResourceId();
    }
    else
        return;

    int filelength = 0;
    // A stripped movie tries the ".gfx" name first.
    if (stripped)
        urlStrGfx = GetUrlStrGfx(url);

    if (url.GetLength())
    {
        bool bilinearImage = false;
        if (LoaderImpl::IsProtocolImage(url, &bilinearImage))
        {
            ImageCreator* pimageLoader = pls->GetImageCreator();
            if (pimageLoader)
            {
                ImageCreateInfo icinfo(ImageCreateInfo::Create_ProtocolImage, pMovieImpl->GetMovieHeap());
                icinfo.SetStates(pls->GetLog(), pls->pBindStates->pFileOpener, pls->GetImageFileHandlerRegistry());
                icinfo.pMovie = pMovieImpl;
                Ptr<Render::Image> pimg = *pimageLoader->LoadProtocolImage(icinfo, String(url.ToCStr()));
                if (pimg)
                {
                    Ptr<ImageResource> pimageRes =
                        *SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) ImageResource(pimg, Resource::Use_Bitmap);
                    if (pimageRes)
                        pmovieDef = *pMovieImpl->CreateImageMovieDef(pimageRes, bilinearImage, url.ToCStr(), pls);
                }
                else if (plog)
                    plog->LogScriptWarning("ImageCreator::LoadProtocolImage failed to load image \"%s\"",
                                           url.ToCStr());
            }
            else if (plog)
                plog->LogScriptWarning("ImageCreator is not installed,failed to load image \"%s\"", url.ToCStr());
        }
        else
        {
            // Images load as movies too; wait for the whole file.
            unsigned lf = loadFlags | GFx::Loader::LoadImageFiles | GFx::Loader::LoadWaitCompletion;
            if (pentry->QuietOpen)
                lf |= GFx::Loader::LoadQuietOpen;
            if (urlStrGfx.GetLength() > 0)
            {
                URLBuilder::LocationInfo loc(URLBuilder::File_LoadMovie, urlStrGfx, level0Path);
                pmovieDef = *LoaderImpl::CreateMovie_LoadState(pls, loc, lf);
            }
            if (!pmovieDef)
            {
                URLBuilder::LocationInfo loc(URLBuilder::File_LoadMovie, url, level0Path);
                pmovieDef = *LoaderImpl::CreateMovie_LoadState(pls, loc, lf);
            }
            if (pmovieDef)
                filelength = pmovieDef->GetDataDef()->GetFileBytes();
            else if (plog && !pentry->QuietOpen)
                plog->LogScriptWarning("Failed loading URL \"%s\"", url.ToCStr());
        }
    }
    else
    {
        // An unload cancels the loads into the same level or clip queued before it.
        for (LoadQueueEntryMT* plentry = pMovieImpl->pLoadQueueMTHead; plentry; plentry = plentry->GetNext())
        {
            GFxAS2LoadQueueEntry* plqentry = static_cast<GFxAS2LoadQueueEntry*>(plentry->GetQueueEntry());
            if (plqentry->EntryTime < pentry->EntryTime)
            {
                if (pentry->Level != -1 && plqentry->Level != -1)
                {
                    if (pentry->Level == plqentry->Level)
                        plqentry->Canceled = true;
                }
                else if (pentry->pCharacter && plqentry->pCharacter && pentry->pCharacter == plqentry->pCharacter)
                    plqentry->Canceled = true;
            }
        }
    }

    if (pmovieDef)
    {
        // An AS3 movie (version 9 and up with the AS3 file attribute) cannot play here.
        if (pmovieDef->GetVersion() != ~0u && pmovieDef->GetVersion() >= 9 &&
            ((pmovieDef->GetDataDef()->GetFileAttributes() & 8) ? 3 : 2) > 2)
        {
            if (plog && !pentry->QuietOpen)
                plog->LogScriptWarning("Failed loading SWF \"%s\": ActionScript version mismatch", url.ToCStr());
            if (poldChar)
            {
                Environment*     penv = ToAvmCharacter(poldChar)->GetASEnvironment();
                MovieClipLoader* pmovieClipLoader =
                    static_cast<MovieClipLoader*>(pentry->MovieClipLoaderHolder.ToObject(penv));
                if (pmovieClipLoader)
                    pmovieClipLoader->NotifyOnLoadError(penv, poldChar, "ActionScriptMismatch", 0);
            }
            return;
        }
        // Loaded separately, so that _lockroot works.
        CharacterCreateInfo ccinfo = { pmovieDef->GetDataDef(), pmovieDef, 0 };
        pnewChar = *static_cast<Sprite*>(
            pASSupport->CreateCharacterInstance(pMovieImpl, ccinfo, pparent, newCharId, CharacterDef::Sprite));
        pnewChar->SetLoadedSeparately();
    }
    bool charIsLoadedSuccessfully = (pnewChar.GetPtr() != 0);

    if (pentry->Level == -1)
    {
        // Into a clip; a failed load (or an unload) leaves an empty clip.
        if (!pnewChar)
        {
            CharacterCreateInfo ccinfo =
                pparent->GetResourceMovieDef()->GetCharacterCreateInfo(ResourceId(0x10001));
            pnewChar = *static_cast<Sprite*>(
                pAS2Support->CreateCharacterInstance(pMovieImpl, ccinfo, pparent, newCharId, CharacterDef::Sprite));
        }
        if (pnewChar)
        {
            // The same create frame, depth and name as the old clip keep the parent's timeline from rebuilding it.
            pnewChar->AddToPlayList();
            pnewChar->CreateFrame = poldChar->CreateFrame;
            pnewChar->Depth       = poldChar->Depth;
            if (!poldChar->IsInstanceBasedNameFlagSet())
                pnewChar->SetName(poldChar->GetName());
            ToAvmCharacter(pparent)->ReplaceChildCharacter(poldChar, pnewChar);
            poldChar->pParent = 0;
            ResolveStickyVariables(pnewChar);
            pnewChar->ModifyOptimizedPlayListLocal<Sprite>();
        }
    }
    else
    {
        if (pnewChar)
        {
            AvmSprite::FromSprite(pnewChar)->SetLevel(pentry->Level);
            pMovieImpl->SetLevelMovie(pentry->Level, pnewChar);
            // Its frame 0 actions run here, before onLoadInit.
            pMovieImpl->Flags &= ~MovieImpl::Flag_LevelClipsChanged;
            ResolveStickyVariables(pnewChar);
        }
        if (!LmLevelMovie(this, 0) && plog)
        {
            plog->LogScriptWarning("_level0 unloaded - no further playback possible");
            return;
        }
    }

    Environment*     penv = ToAvmCharacter(LmLevelMovie(this, 0))->GetASEnvironment();
    MovieClipLoader* pmovieClipLoader = static_cast<MovieClipLoader*>(pentry->MovieClipLoaderHolder.ToObject(penv));
    if (charIsLoadedSuccessfully)
    {
        if (pmovieClipLoader)
        {
            pmovieClipLoader->NotifyOnLoadStart(penv, pnewChar);
            pmovieClipLoader->NotifyOnLoadProgress(penv, pnewChar, filelength, filelength);
            pmovieClipLoader->NotifyOnLoadComplete(penv, pnewChar, 0);
        }
        // Frame 0 first (its onLoad comes after the frame), then onLoadInit.
        pnewChar->ExecuteFrame0Events();
        DoActions();
        if (pmovieClipLoader)
            pmovieClipLoader->NotifyOnLoadInit(penv, pnewChar);
    }
    else if (pmovieClipLoader)
        pmovieClipLoader->NotifyOnLoadError(penv, pnewChar, url.GetLength() ? "URLNotFound" : "Unknown error", 0);

    if (url.GetLength() == 0)
    {
        // An unload drops the old clip now and collects (which also flushes the text format cache).
        poldChar = 0;
        LmHeapLimit(MemContext)->Collect(pMovieImpl->GetMovieHeap());
    }
}

// A queued load goes to the variables, XML, style sheet or movie handler by its type.
// @0x142971340
void MovieRoot::ProcessLoadQueueEntry(GFx::LoadQueueEntry* pentry, LoadStates* pls)
{
    if (pentry->Type & GFx::LoadQueueEntry::LTF_VarsFlag)
        ProcessLoadVars(pentry, pls);
    else if (pentry->Type & GFx::LoadQueueEntry::LTF_XMLFlag)
        ProcessLoadXML(pentry, pls);
    else if (pentry->Type & GFx::LoadQueueEntry::LTF_CSSFlag)
        ProcessLoadCSS(pentry, pls);
    else
        ProcessLoadMovieClip(pentry, pls);
}

}}} // namespace Scaleform::GFx::AS2

// The image resource classes are emitted here through gfx_imageresource.h.
// MS2-PIN: ??_7RefCountVImpl@Scaleform@@6B@ 0x1431496d0
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountVImpl@Scaleform@@$02@Scaleform@@6B@ 0x1431498a0
// MS2-PIN: ??_7?$RefCountBaseV@VImage@Render@Scaleform@@$02@Scaleform@@6B@ 0x1431498b8
// MS2-PIN: ??_7ImageBase@Render@Scaleform@@6B@ 0x1431498d0
// MS2-PIN: ??_7Image@Render@Scaleform@@6B@ 0x143149940
// MS2-PIN: ??_7ImageDelegate@Render@Scaleform@@6B@ 0x143149a28
// MS2-PIN: ??_7ImageDelegate@ImageResource@GFx@Scaleform@@6B@ 0x143149b10
// MS2-PIN: ??_7ImageResource@GFx@Scaleform@@6B@ 0x143149bf8
