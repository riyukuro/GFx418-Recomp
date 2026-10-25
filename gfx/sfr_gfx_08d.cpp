// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_SoundResource (the resource of
// a sound sample: embedded sound data, or an external sound file loaded at bind time through the resource library).
// Fourth source of queue unit sfr_gfx_08 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_08
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426d1d10-0x1426d2820 .text$mn

#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_resource.h"
#include "../include/gfx/gfx_sound.h"
#include "../include/kernel/sf_memory.h"
#include "../include/sound/sound_sound.h"

namespace Scaleform { namespace GFx {

// The key handle (0x20 bytes).
class SoundFileInfoKeyData : public RefCountBase<SoundFileInfoKeyData, StatMD_Sounds_Mem>
{
    Ptr<FileOpener> pFileOpener; // +0x10

public:
    Ptr<SoundFileInfo> pFileInfo; // +0x18

    SoundFileInfoKeyData(SoundFileInfo* pfileInfo, FileOpener* pfileOpener)
    {
        pFileInfo   = pfileInfo;
        pFileOpener = pfileOpener;
    }

    bool operator==(const SoundFileInfoKeyData& other) const
    {
        return pFileOpener == other.pFileOpener && pFileInfo->FileName == other.pFileInfo->FileName;
    }

    UPInt GetHashCode() const
    {
        return pFileInfo->GetHashCode() ^ ((UPInt)pFileOpener.GetPtr() >> 7) ^ (UPInt)pFileOpener.GetPtr();
    }
};

class SoundFileKeyInterface : public ResourceKey::KeyInterface
{
public:
    typedef ResourceKey::KeyHandle KeyHandle;

    virtual void AddRef(KeyHandle hdata) { ((SoundFileInfoKeyData*)hdata)->AddRef(); }
    virtual void Release(KeyHandle hdata) { ((SoundFileInfoKeyData*)hdata)->Release(); }
    virtual ResourceKey::KeyType GetKeyType(KeyHandle) const { return ResourceKey::Key_File; }
    virtual UPInt GetHashCode(KeyHandle hdata) const;
    virtual bool  KeyEquals(KeyHandle hdata, const ResourceKey& other);
    virtual const char* GetFileURL(KeyHandle hdata) const
    {
        return ((SoundFileInfoKeyData*)hdata)->pFileInfo->FileName.ToCStr();
    }
};

// The exe instance 0x143a2fef8. External: sfr_atexit_01 tears it down as DAT_143a2fef8.
SoundFileKeyInterface SoundFileKeyInterface_Instance;

// @0x1426d1d40
UPInt SoundFileKeyInterface::GetHashCode(KeyHandle hdata) const
{
    return ((SoundFileInfoKeyData*)hdata)->GetHashCode();
}

// @0x1426d1d70
bool SoundFileKeyInterface::KeyEquals(KeyHandle hdata, const ResourceKey& other)
{
    if (other.GetKeyInterface() != this)
        return false;
    return *(SoundFileInfoKeyData*)hdata == *(SoundFileInfoKeyData*)other.GetKeyData();
}

// @0x1426d25d0
ResourceKey SoundResource::CreateSoundFileKey(SoundFileInfo* pfileInfo, FileOpener* pfileOpener)
{
    Ptr<SoundFileInfoKeyData> pdata = *SF_NEW SoundFileInfoKeyData(pfileInfo, pfileOpener);
    return ResourceKey(&SoundFileKeyInterface_Instance, pdata.GetPtr());
}

// @0x1426d27f0
ResourceKey SoundResource::GetKey()
{
    return Key;
}

// @0x1426d1fe0
// MS2-FUNCTIONAL: same code, the inlined String releases of the location test the old count with other instructions
bool SoundFileResourceCreator::CreateResource(DataHandle hdata, ResourceBindData* pbindData, LoadStates* pls,
                                              MemoryHeap* pheap) const
{
    SoundFileInfo* prfi = (SoundFileInfo*)hdata;

    // The key is the info with the file name turned into the URL.
    Ptr<SoundFileInfo>        pfi = *SF_NEW SoundFileInfo(*prfi);
    URLBuilder::LocationInfo loc(URLBuilder::File_Sound, prfi->FileName, pls->RelativePathForImports);
    pls->BuildURL(&pfi->FileName, loc);

    ResourceKey key = SoundResource::CreateSoundFileKey(pfi, (FileOpener*)pls->pBindStates->pFileOpener.GetPtr());

    String                  errorMessage;
    ResourceLib::BindHandle bh;
    Ptr<Resource>           pres;

    if (pls->pWeakResourceLib->BindResourceKey(&bh, key) == ResourceLib::RS_NeedsResolve)
    {
        // This thread loads the file; the others wait on the slot.
        FileOpener* popener = (FileOpener*)pls->pBindStates->pFileOpener.GetPtr();
        Ptr<File>   pfile   = *popener->OpenFile(pfi->FileName.ToCStr());
        if (pfile && pfile->IsValid())
        {
            Ptr<Sound::SoundFile> psound =
                *SF_NEW Sound::SoundFile(pfi->FileName.ToCStr(), prfi->SampleRate, prfi->SampleCount, false);
            psound->SetSeekSample(prfi->SeekSample);
            Ptr<Sound::SoundInfo> psi = *SF_NEW Sound::SoundInfo(psound);
            pres = *SF_NEW SoundResource(psi, key);
        }
        if (pres)
        {
            bh.ResolveResource(pres);
        }
        else
        {
            errorMessage = "Failed to load sound '";
            errorMessage += pfi->FileName;
            errorMessage += "'";
            bh.CancelResolve(errorMessage.ToCStr());
        }
    }
    else
    {
        pres = *bh.WaitForResolve();
        if (!pres)
            errorMessage = bh.GetResolveError();
    }

    if (!pres)
    {
        pls->pLog->LogError("%s", errorMessage.ToCStr());
        return false;
    }
    pbindData->pResource = pres;
    return true;
}

// @0x1426d24b0
bool SoundResourceCreator::CreateResource(DataHandle hdata, ResourceBindData* pbindData, LoadStates*,
                                          MemoryHeap*) const
{
    if (!pbindData->pResource)
    {
        Ptr<Sound::SoundInfo> psi = *SF_NEW Sound::SoundInfo((Sound::SoundData*)hdata);
        pbindData->pResource      = *SF_NEW SoundResource(psi);
    }
    return pbindData->pResource != 0;
}

// @0x1426d26b0
ResourceData SoundFileResourceCreator::CreateSoundFileResourceData(SoundFileInfo* prfi)
{
    static SoundFileResourceCreator static_inst;
    return ResourceData(&static_inst, prfi);
}

// @0x1426d2750
ResourceData SoundResourceCreator::CreateSoundResourceData(Sound::SoundData* psound)
{
    static SoundResourceCreator static_inst;
    return ResourceData(&static_inst, psound);
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7KeyInterface@ResourceKey@GFx@Scaleform@@6B@ 0x14318b240
// MS2-PIN: ??_7SoundFileKeyInterface@GFx@Scaleform@@6B@ 0x143193710
// MS2-PIN: ??_7SoundResource@GFx@Scaleform@@6B@ 0x143193748
// MS2-PIN: ??_7SoundResourceCreator@GFx@Scaleform@@6B@ 0x143193768
// MS2-PIN: ??_7SoundFileResourceCreator@GFx@Scaleform@@6B@ 0x143193788
// MS2-PIN: ??_7?$RefCountBase@VSoundFileInfoKeyData@GFx@Scaleform@@$0BEH@@Scaleform@@6B@ 0x1431937a8
// MS2-PIN: ??_7SoundFileInfoKeyData@GFx@Scaleform@@6B@ 0x1431937b0
// MS2-PIN: ??_7DataInterface@ResourceData@GFx@Scaleform@@6B@ 0x14318f548
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
// MS2-PIN: ??_7SoundFileInfo@GFx@Scaleform@@6B@ 0x14318ffe0
// MS2-PIN: ??_7SoundInfo@Sound@Scaleform@@6B@ 0x14318ffa8
// MS2-PIN: ??_GSoundFileKeyInterface@GFx@Scaleform@@UEAAPEAXI@Z 0x1426d1df0
// MS2-PIN: ??_G?$RefCountBase@VSoundFileInfoKeyData@GFx@Scaleform@@$0BEH@@Scaleform@@UEAAPEAXI@Z 0x1426d1e20
// MS2-PIN: ??_GSoundFileResourceCreator@GFx@Scaleform@@UEAAPEAXI@Z 0x1426d1f00
// MS2-PIN: ??_GSoundResourceCreator@GFx@Scaleform@@UEAAPEAXI@Z 0x1426d1fb0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BEH@@Scaleform@@6B@ 0x1431937a8
// MS2-PIN: ??_7?$RefCountBaseNTS@VSoundInfoBase@Sound@Scaleform@@$03@Scaleform@@6B@ 0x14318ff60
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$03@Scaleform@@6B@ 0x14318ff68
// MS2-PIN: ??_7SoundInfoBase@Sound@Scaleform@@6B@ 0x14318ff70
