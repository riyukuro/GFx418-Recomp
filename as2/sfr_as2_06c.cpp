// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 queued loads: the style sheet
// and variable loads of the movie root, the loader-thread style sheet entry, BitmapData.loadBitmap and the
// name=value parser of LoadVars.
// MS2-UNIT: sfr_as2_06c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142966480-0x1429665a0 .text$mn
// MS2-RANGE: 0x1429665a0-0x142966650 .text$mn
// MS2-RANGE: 0x1429670e0-0x142967390 .text$mn
// MS2-RANGE: 0x142970450-0x1429706b0 .text$mn
// MS2-RANGE: 0x142971360-0x1429715b0 .text$mn
// MS2-RANGE: 0x1429715b0-0x142971660 .text$mn
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_loadqueueentry.h"
#include "../include/gfx/gfx_asutils.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_movieimpl.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {

// MovieRoot::GetLevelMovie, inlined in the exe.
SF_FORCEINLINE InteractiveObject* LqLevelMovie(const MovieRoot* proot, int level)
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
SF_FORCEINLINE void LqLevel0Path(const MovieRoot* proot, String* ppath)
{
    if (LqLevelMovie(proot, 0))
    {
        *ppath = proot->pMovieImpl->pMainMovieDef->GetFileURL();
        if (URLBuilder::ExtractFilePath(ppath))
            return;
    }
    ppath->Clear();
}

// The script environment of a character.
SF_FORCEINLINE Environment* LqCharEnv(InteractiveObject* pchar)
{
    AvmDisplayObjBase* pavm = pchar->GetAvmObjImpl();
    return static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pavm))->GetASEnvironment();
}

} // namespace

// A BitmapData of the image exported under linkageId by the movie of the target.
// MS2-FUNCTIONAL: register allocation differs (rbx/rdi swapped) and the exe keeps a second pimg release tail.
// @0x142966480
BitmapData* BitmapData::LoadBitmapA(Environment* penv, const String& linkageId)
{
    Ptr<ImageResource> pimg = penv->GetTarget()->GetMovieImpl()->GetImageResourceByLinkageId(
        penv->GetTarget()->GetResourceMovieDef(), linkageId.ToCStr());
    if (!pimg)
    {
        penv->LogScriptWarning("BitmapData::LoadBitmap: LoadMovieImageCallback failed to load image \"%s\"",
                               linkageId.ToCStr());
        return 0;
    }
    Ptr<MovieDef> pmd = penv->GetTarget()->GetResourceMovieDef();
    if (!pmd)
        return 0;
    BitmapData* pbmp = SF_HEAP_NEW(penv->GetHeap()) BitmapData(penv);
    pbmp->SetImage(penv, pimg, pmd);
    return pbmp;
}

// The style sheet is handed to its object once the loader thread has read it; a canceled load just waits for it.
// MS2-FUNCTIONAL: register allocation differs (the Done load goes through edx).
// @0x1429665a0
bool GFxAS2LoadQueueEntryMT_LoadCSS::LoadFinished()
{
    bool done = pTask->IsDone();
    if (pQueueEntry->Canceled && done)
        return true;
    if (!done)
        return false;
    MovieRoot*            proot  = static_cast<MovieRoot*>(pMovieImpl->pASMovieRoot);
    Environment*          penv   = LqCharEnv(proot->pMovieImpl->pMainMovie);
    GFxAS2LoadQueueEntry* pentry = static_cast<GFxAS2LoadQueueEntry*>(pQueueEntry);
    ASCSSFileLoader*      ploader = static_cast<ASCSSFileLoader*>(pentry->CSSHolder.Loader.GetPtr());
    ploader->Init(penv, pentry->CSSHolder.ASObj.ToObject(penv));
    return true;
}

// Splits "name=value&name=value" into members of pobj (a CR counts as a LF). False for empty data.
// MS2-FUNCTIONAL: the flags argument is stored before the value string is made in the obj (scheduling only).
// @0x1429670e0
bool LoadVarsProto::LoadVariables(Environment* penv, ObjectInterface* pobj, const String& data)
{
    StringBuffer name(Memory::pGlobalHeap);
    StringBuffer value(Memory::pGlobalHeap);
    if (!data.GetSize())
        return false;

    bool        inName = true;
    const char* p;
    for (UInt32 c = data.GetFirstCharAt(0, &p); c; c = data.GetNextChar(&p))
    {
        if (c == '\r')
            c = '\n';
        if (c == '&')
        {
            pobj->SetMember(penv, penv->CreateString(name.ToCStr(), name.GetSize()),
                            Value(penv->CreateString(value.ToCStr(), value.GetSize())));
            name.Clear();
            value.Clear();
            inName = true;
        }
        else if (inName)
        {
            if (c == '=')
                inName = false;
            else
                name.AppendChar(c);
        }
        else
            value.AppendChar(c);
    }
    if (name.GetLength())
    {
        pobj->SetMember(penv, penv->CreateString(name.ToCStr(), name.GetSize()),
                        Value(penv->CreateString(value.ToCStr(), value.GetSize())));
    }
    return true;
}

// A style sheet load done on the movie thread: the loader reads the file, then fills its object.
// MS2-FUNCTIONAL: register allocation differs (the level search uses other registers).
// @0x142970450
void MovieRoot::ProcessLoadCSS(GFx::LoadQueueEntry* pentry, LoadStates* pls)
{
    String level0Path;
    LqLevel0Path(this, &level0Path);
    if (pentry->URL.GetLength())
    {
        URLBuilder::LocationInfo loc(URLBuilder::File_LoadCSS, pentry->URL, level0Path);
        String                   url;
        pls->BuildURL(&url, loc);
        GFxAS2LoadQueueEntry* pas2entry = static_cast<GFxAS2LoadQueueEntry*>(pentry);
        ASCSSFileLoader*      ploader   = static_cast<ASCSSFileLoader*>(pas2entry->CSSHolder.Loader.GetPtr());
        ploader->Load(url.ToCStr(), static_cast<FileOpener*>(pls->GetBindStates()->pFileOpener.GetPtr()));
        Environment* penv = LqCharEnv(LqLevelMovie(this, 0));
        ploader = static_cast<ASCSSFileLoader*>(pas2entry->CSSHolder.Loader.GetPtr());
        ploader->Init(penv, pas2entry->CSSHolder.ASObj.ToObject(penv));
    }
}

// A loadVariables / LoadVars.load done on the movie thread. A LoadVars object that gets no text is dropped.
// MS2-FUNCTIONAL: register allocation and scheduling differ (the file pointer is kept in rsi).
// @0x142971360
void MovieRoot::ProcessLoadVars(GFx::LoadQueueEntry* pentry, LoadStates* pls)
{
    String level0Path;
    LqLevel0Path(this, &level0Path);
    String data;
    int    fileLen = 0;
    if (pentry->URL.GetLength())
    {
        URLBuilder::LocationInfo loc(URLBuilder::File_LoadVars, pentry->URL, level0Path);
        String                   url;
        pls->BuildURL(&url, loc);
        Ptr<File> pfile = *pls->OpenFile(url.ToCStr(), 0);
        if (pfile)
        {
            GFxAS2LoadQueueEntry* pas2entry = static_cast<GFxAS2LoadQueueEntry*>(pentry);
            if (pas2entry->LoadVarsHolder.GetType() == Value::OBJECT)
            {
                if (!MovieImpl::ReadTextData(&data, pfile, &fileLen, true))
                    pas2entry->LoadVarsHolder.DropRefs();
            }
            else
                MovieImpl::ReadTextData(&data, pfile, &fileLen, true);
        }
    }
    DoProcessLoadVars(pentry, pls, data, fileLen, true);
}

// The text a loader thread read for a variables load, unescaped first.
// @0x1429715b0
void MovieRoot::ProcessLoadVarsMT(GFx::LoadQueueEntry* pentry, LoadStates* pls, const String& data, UPInt fileLen,
                                  bool succeeded)
{
    String s;
    ASUtils::Unescape(data.ToCStr(), data.GetSize(), &s);
    DoProcessLoadVars(pentry, pls, s, fileLen, succeeded);
}

}}} // namespace Scaleform::GFx::AS2
