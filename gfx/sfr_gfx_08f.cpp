// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_SoundTagsReader (the loader's
// reader of the SWF sound tags: DefineSound, StartSound, ButtonSound, SoundStreamHead / SoundStreamBlock and the
// GFx external sound tags 1006 / 1007).
// Sixth source of queue unit sfr_gfx_08 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_08
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142646180-0x142647290 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "../include/gfx/gfx_buttondef.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_resource.h"
#include "../include/gfx/gfx_sound.h"
#include "../include/kernel/sf_memory.h"
#include "../include/sound/sound_renderer.h"
#include "../include/sound/sound_sound.h"

namespace Scaleform { namespace GFx {

// Starts or stops an event sound when its frame is reached (0x50 bytes in the tag memory).
class StartSoundTag : public ExecuteTag
{
public:
    void Read(LoadProcess* p, const TagInfo&, UInt16 soundID, ResourceHandle rh)
    {
        Info.SoundId = ResourceId(soundID);
        Info.Style.Read(p->GetStream());
        Info.pSample.SetFromHandle(rh);
    }

    virtual void Execute(DisplayObjContainer* m) { Info.Play((InteractiveObject*)m); }

    SoundInfo Info; // +8
};

// The deleting destructor of SoundFileInfo (0x142646410) is emitted here, where SoundFileInfo is constructed.
// MS2-FUNCTIONAL 0x142646410: same code, this and the -1 release constant are kept in swapped registers (rbx/rdi)

// @0x142646200
SoundInfo::~SoundInfo()
{
}

// @0x142646180
ButtonSoundDefImpl::~ButtonSoundDefImpl()
{
}

// @0x142646630
ButtonSoundDef* SoundTagsReader::ReadButtonSoundDef(LoadProcess* p)
{
    ButtonSoundDefImpl* psound = SF_HEAP_NEW(p->GetLoadHeap()) ButtonSoundDefImpl;
    p->LogParse("button sound options:\n");
    for (int i = 0; i < 4; i++)
    {
        SoundInfo& bs = psound->ButtonSounds[i];
        bs.SoundId    = ResourceId(p->ReadU16());
        if (bs.SoundId == ResourceId(0))
            continue;

        ResourceHandle rh;
        if (p->GetResourceHandle(&rh, bs.SoundId))
            bs.pSample.SetFromHandle(rh);
        else
            p->LogParse("sound tag not found, SoundId=%d, button state #=%i", (int)bs.SoundId.GetIdValue(), i);
        p->LogParse("\n  SoundId = %d\n", (int)bs.SoundId.GetIdValue());
        bs.Style.Read(p->GetStream());
    }
    return psound;
}

// @0x1426467f0
void SoundTagsReader::ReadButtonSoundTag(LoadProcess* p, const TagInfo& tagInfo)
{
    int            buttonCharacterId = p->ReadU16();
    ResourceHandle rh;
    Resource*      pres = 0;

    if (p->GetResourceHandle(&rh, ResourceId(buttonCharacterId)))
        pres = rh.GetResourcePtr();

    if (pres)
    {
        if (pres->GetResourceType() == Resource::RT_ButtonDef)
            ((ButtonDef*)pres)->Read(p, tagInfo.TagType);
    }
    else
    {
        p->LogError("ButtonDef %d referenced in ButtonSound tag not found", buttonCharacterId);
    }
}

// @0x1426468c0
void SoundTagsReader::ReadDefineExternalSoundTag(LoadProcess* p, const TagInfo&)
{
    // GFx tag 1006: character id, format (0 = WAV), bits, channels (UI16), sample rate, sample count, seek sample
    // (UI32), then the export name and the file name (with extension) as length-prefixed strings.
    Stream* pin = p->GetStream();

    unsigned soundResourceId = pin->ReadU16();
    unsigned soundFormat     = p->ReadU16();
    unsigned bits            = p->ReadU16();
    unsigned channels        = p->ReadU16();
    unsigned sampleRate      = p->ReadU32();
    unsigned sampleCount     = p->ReadU32();
    unsigned seekSample      = p->ReadU32();
    String   soundExportName, soundFileName;
    pin->ReadStringWithLength(&soundExportName);
    pin->ReadStringWithLength(&soundFileName);

    pin->LogParse("  DefineExternalSound: id = 0x%X, fmt = %d, name = '%s', exp = '%s'\n", soundResourceId,
                  soundFormat, soundFileName.ToCStr(), soundExportName.ToCStr());

    Ptr<SoundFileInfo> pfi = *SF_NEW SoundFileInfo;
    if (pfi)
    {
        pfi->FileName      = soundFileName;
        pfi->ExportName    = soundExportName;
        pfi->pExporterInfo = p->GetExporterInfo();
        pfi->Format        = (FileTypeConstants::FileFormatType)soundFormat;
        pfi->Bits          = bits;
        pfi->Channels      = channels;
        pfi->SampleRate    = sampleRate;
        pfi->SampleCount   = sampleCount;
        pfi->SeekSample    = seekSample;
        pfi->Use           = Resource::Use_SoundSample;

        p->AddDataResource(ResourceId(soundResourceId), SoundFileResourceCreator::CreateSoundFileResourceData(pfi));
    }
}

// @0x142646b40
void SoundTagsReader::ReadDefineExternalStreamSoundTag(LoadProcess* p, const TagInfo&)
{
    // GFx tag 1007: format (0 = WAV), bits, channels (UI16), sample rate, sample count, seek sample, start frame,
    // last frame (UI32), then the file name (with extension) as a length-prefixed string.
    Stream*                 pin  = p->GetStream();
    Ptr<SoundStreamDefImpl> pdef = *SF_NEW SoundStreamDefImpl;

    unsigned soundFormat    = p->ReadU16();
    unsigned bits           = p->ReadU16();
    unsigned channels       = p->ReadU16();
    pdef->StreamSoundRate   = p->ReadU32();
    pdef->StreamSampleCount = p->ReadU32();
    pdef->LatencySeek       = p->ReadU32();
    pdef->StartFrame        = p->ReadU32();
    pdef->LastFrame         = p->ReadU32();
    SF_UNUSED2(bits, channels);
    String soundFileName;
    pin->ReadStringWithLength(&soundFileName);

    pin->LogParse("  DefineExternalStreamSound: fmt = %d, name = '%s'\n", soundFormat, soundFileName.ToCStr());

    String                   fname;
    URLBuilder::LocationInfo loc(URLBuilder::File_Sound, soundFileName, p->GetLoadStates()->RelativePathForImports);
    p->GetLoadStates()->BuildURL(&fname, loc);

    Ptr<Sound::SoundFile> sound =
        *SF_NEW Sound::SoundFile(fname.ToCStr(), pdef->StreamSoundRate, pdef->StreamSampleCount, true);
    sound->SetSeekSample(pdef->LatencySeek);
    pdef->pSoundInfo = *SF_NEW Sound::SoundInfo(sound);
    p->SetSoundStream(pdef);
}

// @0x142646dd0
void SoundTagsReader::ReadDefineSoundTag(LoadProcess* p, const TagInfo&)
{
    Sound::SoundRenderer* psoundRenderer = p->GetLoadStates()->pAudioState->GetRenderer();
    UInt32                caps           = 0;
    if (psoundRenderer)
        psoundRenderer->GetRenderCaps(&caps);

    Stream*               in          = p->GetStream();
    UInt16                characterId = in->ReadU16();
    Ptr<Sound::SoundData> psound      = *GFx_ReadSoundData(p, characterId);

    // MP3 samples are dropped when the renderer cannot play them.
    if (psoundRenderer && (psound->GetFormat() & Sound::SoundDataBase::Sample_MP3) &&
        (caps & Sound::SoundRenderer::Cap_NoMP3))
        return;

    ResourceData resData = SoundResourceCreator::CreateSoundResourceData(psound);
    p->AddDataResource(ResourceId(characterId), resData);
}

// @0x142646f00
void SoundTagsReader::ReadSoundStreamBlockTag(LoadProcess* p, const TagInfo&)
{
    Sound::SoundRenderer* psoundRenderer = p->GetLoadStates()->pAudioState->GetRenderer();
    UInt32                caps           = 0;
    if (psoundRenderer)
        psoundRenderer->GetRenderCaps(&caps);

    if (psoundRenderer && (caps & Sound::SoundRenderer::Cap_NoStreaming))
        return;

    SoundStreamDefImpl* pdef = (SoundStreamDefImpl*)p->GetSoundStream();
    if (psoundRenderer && pdef->SoundCompression == 2 && (caps & Sound::SoundRenderer::Cap_NoMP3))
        return;

    pdef->ReadBlockTag(p);
}

// @0x142646f90
void SoundTagsReader::ReadSoundStreamHeadTag(LoadProcess* p, const TagInfo& tagInfo)
{
    p->LogParse("SoundStreamHead%c\n", (tagInfo.TagType == Tag_SoundStreamHead) ? ' ' : '2');

    Sound::SoundRenderer* psoundRenderer = p->GetLoadStates()->pAudioState->GetRenderer();
    UInt32                caps           = 0;
    if (psoundRenderer)
        psoundRenderer->GetRenderCaps(&caps);

    if (psoundRenderer && (caps & Sound::SoundRenderer::Cap_NoStreaming))
        return;

    Stream*                 in   = p->GetStream();
    Ptr<SoundStreamDefImpl> pdef = *SF_NEW SoundStreamDefImpl;
    pdef->ReadHeadTag(in);

    if (pdef->StreamSampleCount > 0)
        p->SetSoundStream(pdef);
}

// @0x142647090
void SoundTagsReader::ReadStartSoundTag(LoadProcess* p, const TagInfo& tagInfo)
{
    UInt16 soundId = p->ReadU16();

    ResourceHandle rh;
    if (p->GetResourceHandle(&rh, ResourceId(soundId)))
    {
        StartSoundTag* sst = p->AllocTag<StartSoundTag>();
        sst->Read(p, tagInfo, soundId, rh);

        p->LogParse("StartSound tag: id=%d, stop = %d, loop ct = %d\n", soundId, int(sst->Info.Style.StopPlayback),
                    sst->Info.Style.LoopCount);
        p->AddExecuteTag(sst);
    }
    else
    {
        p->LogError("StartSoundLoader - SoundId %d is not defined", soundId);
    }
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7ExecuteTag@GFx@Scaleform@@6B@ 0x14313ba68
// MS2-PIN: ??_7StartSoundTag@GFx@Scaleform@@6B@ 0x143190070
// MS2-PIN: ??_7ButtonSoundDef@GFx@Scaleform@@6B@ 0x14318ffe8
// MS2-PIN: ??_7ButtonSoundDefImpl@GFx@Scaleform@@6B@ 0x14318fff8
// MS2-PIN: ??_7SoundFileInfo@GFx@Scaleform@@6B@ 0x14318ffe0
// MS2-PIN: ??_7SoundInfo@Sound@Scaleform@@6B@ 0x14318ffa8
// MS2-PIN: ??_7?$RefCountBaseNTS@VSoundInfoBase@Sound@Scaleform@@$03@Scaleform@@6B@ 0x14318ff60
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$03@Scaleform@@6B@ 0x14318ff68
// MS2-PIN: ??_7SoundInfoBase@Sound@Scaleform@@6B@ 0x14318ff70
// MS2-PIN: ??_GSoundFileInfo@GFx@Scaleform@@UEAAPEAXI@Z 0x142646410
// MS2-PIN: ??_GSoundInfoBase@Sound@Scaleform@@UEAAPEAXI@Z 0x142646240
// MS2-PIN: ??_G?$RefCountBaseNTS@VSoundInfoBase@Sound@Scaleform@@$03@Scaleform@@UEAAPEAXI@Z 0x1426462a0
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$03@Scaleform@@UEAAPEAXI@Z 0x142646520
