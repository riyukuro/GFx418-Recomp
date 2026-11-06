// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_Loader (the public Loader,
// URLBuilder's default rules, StateBag::OpenFile).
// Queue unit sfr_gfx_01 is split along its original sources: this file is GFx_Loader.
// MS2-UNIT: sfr_gfx_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14258c130-0x14258c270 .text$mn
// MS2-RANGE: 0x14258c2f0-0x14258c680 .text$mn
// MS2-RANGE: 0x14258c690-0x14258c790 .text$mn
// MS2-RANGE: 0x14258c7a0-0x14258cb30 .text$mn

#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/kernel/sf_utf8util.h"

// Evaluation build check; an empty function in this build (the exe folds it with other empty functions).
void GFx_ValidateEvaluation();

namespace Scaleform { namespace GFx {

// The URLBuilder state's default: the default rules.
// @0x14258c3a0
void URLBuilder::BuildURL(String* ppath, const LocationInfo& loc)
{
    DefaultBuildURL(ppath, loc);
}

// An absolute file name is used as is; a relative one is appended to the parent path.
// @0x14258c560
void URLBuilder::DefaultBuildURL(String* ppath, const LocationInfo& loc)
{
    if (IsPathAbsolute(loc.FileName.ToCStr()))
        *ppath = loc.FileName;
    else
    {
        UPInt length = loc.ParentPath.GetSize();
        if (length > 0)
        {
            *ppath     = loc.ParentPath;
            char end = loc.ParentPath.ToCStr()[length - 1];
            if ((end != '\\') && (end != '/'))
                *ppath += "/";
            *ppath += loc.FileName;
        }
        else
            *ppath = loc.FileName;
    }
}

// True for "/x", "\x", "c:/x", "http://x" and the empty string; a separator before any ':' makes the path relative.
// @0x14258c8c0
bool URLBuilder::IsPathAbsolute(const char* putf8str)
{
    if (!putf8str || !*putf8str)
        return true;

    UInt32 ch = UTF8Util::DecodeNextChar(&putf8str);
    if ((ch == '/') || (ch == '\\'))
        return true;

    while (ch != 0)
    {
        if (ch == ':')
        {
            ch = UTF8Util::DecodeNextChar(&putf8str);
            if ((ch == '/') || (ch == '\\'))
                return true;
        }
        else if ((ch == '/') || (ch == '\\'))
            break;

        ch = UTF8Util::DecodeNextChar(&putf8str);
    }
    return false;
}

// Cuts *ppath back to its directory (keeping the separator); false if it has none.
// @0x14258c690
bool URLBuilder::ExtractFilePath(String* ppath)
{
    SPInt length = (SPInt)ppath->GetLength();
    SPInt i      = length - 1;
    for (; i >= 0; i--)
    {
        UInt32 ch = ppath->GetCharAt(i);
        if ((ch == '/') || (ch == '\\'))
        {
            *ppath = ppath->Substring(0, i + 1);
            break;
        }
    }
    return (i >= 0);
}

// Opens pfilename through the bag's file opener; logs to plog when there is none.
// @0x14258c9f0
File* StateBag::OpenFileEx(const char* pfilename, Log* plog)
{
    Ptr<FileOpenerBase> popener = GetFileOpener();
    if (!popener)
    {
        if (plog)
            plog->LogError("Loader failed to open '%s', FileOpener not installed", pfilename);
        return 0;
    }
    return popener->OpenFileEx(pfilename, plog);
}

// @0x14258c950
File* StateBag::OpenFile(const char* pfilename)
{
    return OpenFileEx(pfilename, GetLog());
}

// @0x14258c130
Loader::Loader(const LoaderConfig& config)
{
    InitLoader(config);
}

// @0x14258c1d0
Loader::Loader(const Ptr<FileOpenerBase>& pfileOpener, const Ptr<ZlibSupportBase>& pzlib)
{
    LoaderConfig config(0, pfileOpener, pzlib);
    InitLoader(config);
}

// A copy shares the resource library and copies the states (not the load flags).
// @0x14258c160
Loader::Loader(const Loader& src)
{
    GFx_ValidateEvaluation();

    pImpl              = new LoaderImpl(src.pImpl);
    pStrongResourceLib = src.pStrongResourceLib;
    if (pStrongResourceLib)
        pStrongResourceLib->AddRef();
}

// @0x14258c2f0
Loader::~Loader()
{
    if (pImpl)
        pImpl->Release();
    if (pStrongResourceLib)
        pStrongResourceLib->Release();
}

// @0x14258c7a0
void Loader::InitLoader(const LoaderConfig& cfg)
{
    GFx_ValidateEvaluation();

    bool debugHeap = (cfg.DefLoadFlags & LoadDebugHeap) ? true : false;

    DefLoadFlags       = cfg.DefLoadFlags;
    pStrongResourceLib = new ResourceLib(debugHeap);

    if ((pImpl = new LoaderImpl(pStrongResourceLib, debugHeap)) != 0)
    {
        SetFileOpener(cfg.pFileOpener);
        SetParseControl(Ptr<ParseControl>(*new ParseControl(ParseControl::VerboseParseNone)));
        SetZlibSupport(cfg.pZLibSupport);
    }
}

// @0x14258c770
StateBag* Loader::GetStateBagImpl() const
{
    return pImpl;
}

// @0x14258c4d0
bool Loader::CheckTagLoader(int tagType) const
{
    return (pImpl) ? pImpl->CheckTagLoader(tagType) : 0;
}

// @0x14258ca80
void Loader::SetResourceLib(ResourceLib* plib)
{
    if (pImpl)
    {
        if (plib)
            plib->AddRef();
        if (pStrongResourceLib)
            pStrongResourceLib->Release();
        pStrongResourceLib = plib;
        pImpl->SetWeakResourceLib(plib->GetWeakLib());
    }
}

// @0x14258c760
ResourceLib* Loader::GetResourceLib() const
{
    return pStrongResourceLib;
}

// @0x14258c730
bool Loader::GetMovieInfo(const char* pfilename, MovieInfo* pinfo, bool getTagCount, unsigned loadConstants)
{
    if (!pfilename || pfilename[0] == 0)
        return 0;
    if (!pinfo)
        return 0;
    return pImpl ? pImpl->GetMovieInfo(pfilename, pinfo, getTagCount, loadConstants | DefLoadFlags) : 0;
}

// @0x14258c530
MovieDef* Loader::CreateMovie(const char* pfilename, unsigned loadConstants, UPInt memoryArena)
{
    if (!pfilename || pfilename[0] == 0)
        return 0;
    return pImpl ? pImpl->CreateMovie(pfilename, loadConstants | DefLoadFlags, memoryArena) : 0;
}

// @0x14258cb10
void Loader::UnpinAll()
{
    if (pStrongResourceLib)
        pStrongResourceLib->UnpinAll();
}

// @0x14258c4c0
void Loader::CancelLoading()
{
    pImpl->CancelLoading();
}

// @0x14258cb00
void ImagePackParamsBase::SetTextureConfig(const TextureConfig& config)
{
    PackTextureConfig = config;
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7Loader@GFx@Scaleform@@6B@ 0x1431843d8
// MS2-PIN: ??_GLoader@GFx@Scaleform@@UEAAPEAXI@Z 0x14258c340
// MS2-PIN: ??_7StateBag@GFx@Scaleform@@6B@ 0x143183208
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
