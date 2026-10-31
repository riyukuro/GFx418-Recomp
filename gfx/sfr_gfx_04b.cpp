// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_TagLoaders: the readers of the
// SWF / GFx tags (SWF_TagLoaderTable, by tag type) and the compiler-generated helpers emitted with them.
// Second source of queue unit sfr_gfx_04 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_04b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425c4330-0x1425c43a0 .text$mn
// MS2-RANGE: 0x1425c43a0-0x1425c4500 .text$mn
// MS2-RANGE: 0x1425c4500-0x1425c48e0 .text$mn
// MS2-RANGE: 0x1425c4e90-0x1425c5340 .text$mn
// MS2-RANGE: 0x1425c57b0-0x1425c5bb0 .text$mn
// MS2-RANGE: 0x1425c6180-0x1425c6400 .text$mn
// MS2-RANGE: 0x1425c6400-0x1425c6450 .text$mn
// MS2-RANGE: 0x1425c64c0-0x1425c64eb .text$mn
// MS2-RANGE: 0x1425c8550-0x1425c857b .text$mn
// MS2-RANGE: 0x1425c8670-0x1425c869b .text$mn
// MS2-RANGE: 0x1425c88d0-0x1425c894d .text$mn
// MS2-RANGE: 0x1425c8b20-0x1425c8b31 .text$mn
// MS2-RANGE: 0x1425c8ca0-0x1425c8ce8 .text$mn
// MS2-RANGE: 0x1425c8cf0-0x1425c8d08 .text$mn
// MS2-RANGE: 0x1425c6450-0x1425c64b8 .text$mn
// MS2-RANGE: 0x1425c6620-0x1425c66cd .text$mn
// MS2-RANGE: 0x1425c7ba0-0x1425c7c98 .text$mn
// MS2-RANGE: 0x1425c8010-0x1425c80d7 .text$mn
// MS2-RANGE: 0x1425c8fe0-0x1425c9061 .text$mn
// MS2-RANGE: 0x1425c9190-0x1425c91ec .text$mn
// MS2-RANGE: 0x1425c4db0-0x1425c4e88 .text$mn
// MS2-RANGE: 0x1425c4b70-0x1425c4cf8 .text$mn
// MS2-RANGE: 0x1425c64f0-0x1425c661d .text$mn

#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_placeobject.h"
#include "../include/gfx/gfx_spritedef.h"
#include "../include/gfx/gfx_buttondef.h"
#include "../include/gfx/gfx_fontlib.h"
#include "../include/gfx/gfx_sound.h"
#include "../include/gfx/gfx_shapeswf.h"
#include "../include/render/render_jpeg.h"

#include <stdlib.h>

namespace Scaleform { namespace GFx {

// The image file readers of the load: a state, the render registry after it at +0x18 (as in sfr_gfx_02e/04x).
class ImageFileHandlerRegistry : public State, public Render::ImageFileHandlerRegistry
{
};

extern "C" void FUN_142655fe0(FontData*, LoadProcess*, const TagInfo*);
extern "C" void FUN_1426597e0(void*, void*);
extern "C" void FUN_14257dcb0(void*);

// @0x1425c6450
void SF_STDCALL GFx_DefineVideoStreamLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    void* video = p->GetLoadStates()->pVideoState.GetPtr();
    if (video)
    {
        typedef void (*ReadVideoTag)(void*, LoadProcess*, const TagInfo&);
        void** vtable = *reinterpret_cast<void***>(video);
        ReadVideoTag read = reinterpret_cast<ReadVideoTag>(vtable[7]);
        read(video, p, tagInfo);
    }
    else
    {
        p->GetStream()->LogParse("GFx_DefineVideoStream: Video library is not set.\n");
        p->GetStream()->LogTagBytes();
    }
}

// @0x1425c6620
void SF_STDCALL GFx_FileAttributesLoader(LoadProcess* p)
{
    const UInt16 flags = p->ReadU16();
    p->GetLoadTaskData()->SetFileAttributes(flags);
    if (flags)
    {
        p->LogParse("  fileAttr:");
        char sep = ' ';
        if (flags & 0x01)
        {
            p->LogParse("%cUseNetwork", sep);
            sep = ',';
        }
        // the exe only switches the separator after UseNetwork
        if (flags & 0x08)
            p->LogParse("%cUseActionScript3", sep);
        if (flags & 0x10)
            p->LogParse("%cHasMetadata", sep);
        p->LogParse("\n");
    }
}

// @0x1425c7ba0
void SF_STDCALL GFx_DefineExternalSoundLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    AudioBase* audio = p->GetLoadStates()->pAudioState.GetPtr();
    if (audio)
        audio->GetSoundTagsReader()->ReadDefineExternalSoundTag(p, tagInfo);
    else
    {
        p->GetStream()->LogParse("GFx_DefineExternalSoundLoader: Audio library is not set.\n");
        p->GetStream()->LogTagBytes();
    }
}

// @0x1425c7c20
void SF_STDCALL GFx_DefineExternalStreamSoundLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    AudioBase* audio = p->GetLoadStates()->pAudioState.GetPtr();
    if (audio)
        audio->GetSoundTagsReader()->ReadDefineExternalStreamSoundTag(p, tagInfo);
    else
    {
        p->GetStream()->LogParse("GFx_DefineExternalStreamSoundLoader: Audio library is not set.\n");
        p->GetStream()->LogTagBytes();
    }
}

UInt32 FUN_1425c8c20(LoadProcess* p); // LoadProcess::ReadU32, out of line (sfr_gfx_04x)

// @0x1425c8010
void SF_STDCALL GFx_DefineBinaryDataLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    SF_UNUSED(tagInfo);
    p->LogError("Tag 'DefineBinaryData' (87) is not supported, potentially 'TLF text' fields are used. Switch to 'Classic Text'.");

    int characterId = p->ReadU16();
    p->LogParse("  DefineBinaryData: CharId = %d\n", characterId);
    FUN_1425c8c20(p); // skip reserved.

    if (p->IsVerboseParse())
        p->GetStream()->LogTagBytes();

    // create a fake character to prevent errors, such as 'resource with id=... not found'.
    Ptr<ButtonDef> ch = *SF_HEAP_NEW(p->GetLoadHeap()) ButtonDef;
    p->AddResource(ResourceId(characterId), ch);
}

// @0x1425c4db0
void SF_STDCALL GFx_DefineFontLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    UInt16  fontId = p->ReadU16();

    p->LogParse("  Font: id = %d\n", fontId);

    Ptr<Render::Font> pf;
    if (tagInfo.TagType == static_cast<TagType>(0x3ed)) // Tag_DefineCompactedFont
    {
        p->LogError("Trying to load compacted font with SF_NO_COMPACTED_FONT_SUPPORT defined.");
        return;
    }
    else
    {
        FontData* pfd = SF_HEAP_NEW(p->GetLoadHeap()) FontData;
        pf = *pfd;
        FUN_142655fe0(pfd, p, &tagInfo); // FontData::Read
    }

    p->AddFontDataResource(ResourceId(fontId), pf);
}

// MS2-FUNCTIONAL 0x1425c4b70: the exe's bounds vcall (slot +0x38) sets no float arg (our xorps xmm2) and swaps r12/r15.
// @0x1425c4b70
void SF_STDCALL GFx_DefineShapeLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    UInt16  characterId = p->ReadU16();
    p->LogParse("  ShapeLoader: id = %d\n", characterId);

    // The exe inlines ConstShapeWithStyles' default constructor here; FUN_142659740 is the abstract base's.
    Ptr<ConstShapeWithStyles> shp = *SF_HEAP_NEW(p->GetLoadHeap()) ConstShapeWithStyles;
    int shapeOffset = p->GetStream()->Tell();
    shp->Read(p, tagInfo.TagType, tagInfo.TagLength - (shapeOffset - tagInfo.TagDataOffset), true);

    Ptr<SwfShapeCharacterDef>  ch =
        *SF_HEAP_NEW(p->GetLoadHeap()) SwfShapeCharacterDef(shp);

    p->LogParse("  bound rect:");
    p->GetStream()->LogParseClass(static_cast<ShapeBaseCharacterDef*>(ch.GetPtr())->GetBoundsLocal());

    p->AddResource(ResourceId(characterId), ch.GetPtr());
}

// @0x1425c64f0
void SF_STDCALL GFx_MetadataLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    SF_UNUSED(tagInfo);

    // Determine the size of meta-data and read it into the buffer.
    int     size = p->GetTagEndPosition() - p->Tell();
    UByte*  pbuff = (UByte*)SF_ALLOC(size + 1, Stat_Default_Mem);
    if (pbuff)
    {
        for(int i=0; i<size; i++)
            pbuff[i] = p->ReadU8();
        p->SetMetadata(pbuff, (unsigned)size);

        pbuff[Alg::Min<int>(size,255)] = 0;
        p->LogParse("  metadata: %s\n", pbuff);
        SF_FREE(pbuff);
    }
}

// GFxMovieDefImplKey::GetHashCode with MovieDefBindStates::GetHashCode inlined (SDK GFx_MovieDef.cpp); the MS2
// bind states hold eight state pointers (+0x10..+0x50 except +0x28).
// @0x1425c8fe0
UPInt FUN_1425c8fe0(const void*, const void* object)
{
    struct BindStatesView { UPInt Pad[2]; UPInt pStates[3]; UPInt Pad28; UPInt pStates2[5]; };
    struct KeyView { UPInt Pad[2]; UPInt pDataDef; const BindStatesView* pBindStates; };
    const KeyView* key = reinterpret_cast<const KeyView*>(object);
    const BindStatesView* b = key->pBindStates;
    UPInt bindHash =
        b->pStates[0] ^ (b->pStates[0] >> 7) ^
        b->pStates[1] ^ (b->pStates[1] >> 7) ^
        b->pStates[2] ^ (b->pStates[2] >> 7) ^
        b->pStates2[0] ^ (b->pStates2[0] >> 7) ^
        b->pStates2[1] ^ (b->pStates2[1] >> 7) ^
        b->pStates2[2] ^ (b->pStates2[2] >> 7) ^
        b->pStates2[3] ^ (b->pStates2[3] >> 7) ^
        b->pStates2[4] ^ (b->pStates2[4] >> 7);
    return key->pDataDef ^ (key->pDataDef >> 7) ^ bindHash;
}

// GFxMovieDataDefFileKeyData::GetHashCode (SDK GFx_MovieDef.cpp), with a third state pointer.
// @0x1425c9190
UPInt FUN_1425c9190(const void*, const void* object)
{
    struct KeyView { UPInt Pad[2]; String FileName; UPInt p1; SInt64 ModifyTime; UPInt p2; UPInt p3; };
    const KeyView* key = reinterpret_cast<const KeyView*>(object);
    UPInt fileHashCode = String::BernsteinHashFunction(key->FileName.ToCStr(), key->FileName.GetSize());
    return fileHashCode ^
        ((UPInt)key->ModifyTime) ^
        key->p1 ^ (key->p1 >> 7) ^
        key->p2 ^ (key->p2 >> 7) ^
        key->p3 ^ (key->p3 >> 7);
}

// MS2-FUNCTIONAL: preserves the tables bytes and replace-old-header behavior; the executable's allocator call sequence
// is still being refined.
// The JPEG tables tag supplies the shared header used by following DefineBits tags.
// @0x1425c43a0
void SF_STDCALL GFx_JpegTablesLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    LoadStates* states = p->GetLoadStates();
    Render::ImageFileHandlerRegistry* registry =
        states ? static_cast<Render::ImageFileHandlerRegistry*>(states->GetImageFileHandlerRegistry()) : 0;
    if (!registry)
    {
        p->LogError("Image file handler registry is not installed - can't load jpeg image data");
        return;
    }

    if (!registry->GetReader(Render::ImageFile_JPEG))
    {
        p->LogError("Jpeg System is not installed - can't load jpeg image data");
        return;
    }

    if (tagInfo.TagLength > 0)
    {
        Ptr<Render::JPEG::TablesHeader> tables =
            *SF_HEAP_NEW(p->GetLoadHeap()) Render::JPEG::TablesHeader(p->GetLoadHeap(), tagInfo.TagLength);
        p->GetStream()->ReadToBuffer(tables->Data, tagInfo.TagLength);
        *reinterpret_cast<Ptr<RefCountImpl>*>(reinterpret_cast<UByte*>(p) + 0x360) = tables;
    }
}

// Defines a JPEG image whose stream relies on the tables from the preceding JPEGTables tag.
// MS2-FUNCTIONAL: image data and shared JPEG tables are passed to the reader; exact stream setup is still being refined.
// @0x1425c4500
void SF_STDCALL GFx_DefineBitsJpegLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    ResourceId rid(p->ReadU16());
    Stream* stream = p->GetStream();
    Render::ImageSource* source = 0;
    LoadStates* states = p->GetLoadStates();
    Render::ImageFileHandlerRegistry* registry = states
        ? static_cast<Render::ImageFileHandlerRegistry*>(states->GetImageFileHandlerRegistry()) : 0;
    if (!registry)
    {
        p->LogError("Image file handler registry is not installed - can't load jpeg image data");
    }
    else if (!registry->GetReader(Render::ImageFile_JPEG))
    {
        p->LogError("Jpeg System is not installed - can't load jpeg image data");
    }
    else
    {
        Render::JPEG::AbstractReader* reader = static_cast<Render::JPEG::AbstractReader*>(
            registry->GetReader(Render::ImageFile_JPEG));
        Render::ImageCreateArgs args(Render::Image_None, 0, p->GetLoadHeap());
        stream->SyncFileStream();
        // The reader moves the file position: GetUnderlyingFile marks the stream for a resync.
        File* file = stream->GetUnderlyingFile();
        Ptr<RefCountImpl>* tableSlot = reinterpret_cast<Ptr<RefCountImpl>*>(reinterpret_cast<UByte*>(p) + 0x360);
        Render::JPEG::ExtraData* tables = reinterpret_cast<Render::JPEG::ExtraData*>(tableSlot->GetPtr());
        source = reader->CreateImageSource(file, args, tables, tagInfo.TagLength - 2, false);
    }
    p->AddImageResource(rid, source);
    if (source)
        source->Release();
}

// Defines a self-contained JPEG image (SWF DefineBitsJPEG2).
// MS2-FUNCTIONAL: preserves the tag id, payload length and reader ownership; exact stream setup is still being refined.
// @0x1425c4740
void SF_STDCALL GFx_DefineBitsJpeg2Loader(LoadProcess* p, const TagInfo& tagInfo)
{
    const UInt16 charId = p->ReadU16();
    ResourceId rid(charId);
    Stream* stream = p->GetStream();
    p->LogParse("  GFx_DefineBitsJpeg2Loader: charid = %d pos = 0x%x\n", charId, stream->Tell());
    Render::ImageSource* source = 0;
    LoadStates* states = p->GetLoadStates();
    Render::ImageFileHandlerRegistry* registry = states
        ? static_cast<Render::ImageFileHandlerRegistry*>(states->GetImageFileHandlerRegistry()) : 0;
    if (!registry)
    {
        p->LogError("Image file handler registry is not installed - can't load jpeg image data");
    }
    else if (!registry->GetReader(Render::ImageFile_JPEG))
    {
        p->LogError("Jpeg System is not installed - can't load jpeg image data");
    }
    else
    {
        Render::JPEG::AbstractReader* reader = static_cast<Render::JPEG::AbstractReader*>(
            registry->GetReader(Render::ImageFile_JPEG));
        Render::ImageCreateArgs args(Render::Image_None, 0, p->GetLoadHeap());
        File* file = stream->GetUnderlyingFile();
        source = reader->CreateImageSource(file, args, 0, tagInfo.TagLength - 2, true);
    }
    p->AddImageResource(rid, source);
    if (source)
        source->Release();
}

// The audio state owns the reader that interprets the five SWF sound tags.
// @0x1425c6180
void SF_STDCALL GFx_DefineSoundLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    AudioBase* audio = p->GetLoadStates()->pAudioState.GetPtr();
    if (audio)
        audio->GetSoundTagsReader()->ReadDefineSoundTag(p, tagInfo);
    else
    {
        p->GetStream()->LogParse("GFx_DefineSoundLoader: Audio library is not set.\n");
        p->GetStream()->LogTagBytes();
    }
}

// @0x1425c6200
void SF_STDCALL GFx_StartSoundLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    AudioBase* audio = p->GetLoadStates()->pAudioState.GetPtr();
    if (audio)
        audio->GetSoundTagsReader()->ReadStartSoundTag(p, tagInfo);
    else
    {
        p->GetStream()->LogParse("GFx_StartSoundLoader: Audio library is not set.\n");
        p->GetStream()->LogTagBytes();
    }
}

// @0x1425c6280
void SF_STDCALL GFx_ButtonSoundLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    AudioBase* audio = p->GetLoadStates()->pAudioState.GetPtr();
    if (audio)
        audio->GetSoundTagsReader()->ReadButtonSoundTag(p, tagInfo);
    else
    {
        p->GetStream()->LogParse("GFx_ButtonSoundLoader: Audio library is not set.\n");
        p->GetStream()->LogTagBytes();
    }
}

// @0x1425c6300
void SF_STDCALL GFx_SoundStreamHeadLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    AudioBase* audio = p->GetLoadStates()->pAudioState.GetPtr();
    if (audio)
        audio->GetSoundTagsReader()->ReadSoundStreamHeadTag(p, tagInfo);
    else
    {
        p->GetStream()->LogParse("GFx_SoundStreamHeadLoader: Audio library is not set.\n");
        p->GetStream()->LogTagBytes();
    }
}

// @0x1425c6380
void SF_STDCALL GFx_SoundStreamBlockLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    AudioBase* audio = p->GetLoadStates()->pAudioState.GetPtr();
    if (audio)
        audio->GetSoundTagsReader()->ReadSoundStreamBlockTag(p, tagInfo);
    else
    {
        p->GetStream()->LogParse("GFx_SoundStreamBlockLoader: Audio library is not set.\n");
        p->GetStream()->LogTagBytes();
    }
}

// The tag loaders by SWF tag type.
extern LoaderImpl::LoaderFunction SWF_TagLoaderTable[];

// PlaceObject2 of SWF 3 to 5: the place has no class flag (vftable 0x14318a2d0).
class PlaceObject2Taga : public PlaceObject2Tag
{
public:
    virtual void Unpack(GFxPlaceObjectBase::UnpackedData& data) { UnpackBase(data, 3); }
    virtual void Execute(DisplayObjContainer* m) { ExecuteBase(m, 3); }
    virtual void Trace(const char* str) { TraceBase(str, 3); }
};

// Replaces the loader of an SWF tag type.
// @0x1425c8cf0
bool RegisterTagLoader(unsigned tagType, LoaderImpl::LoaderFunction tagLoaderFunc)
{
    if (tagType > 0x5c)
        return false;
    SWF_TagLoaderTable[tagType] = tagLoaderFunc;
    return true;
}

// @0x1425c4330
void SF_STDCALL GFx_SetBackgroundColorLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    SF_UNUSED(tagInfo);
    SetBackgroundColorTag* pt = p->AllocTag<SetBackgroundColorTag>();
    pt->Read(p);
    p->AddExecuteTag(pt);
}

// The 16 bytes of the SWD id (only of use to the AMP debugger, which this build does not have).
// @0x1425c4e90
void SF_STDCALL GFx_DebugIDLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    SF_UNUSED(tagInfo);
    String strSwdId;
    char   acHex[3];
    for (UPInt i = 0; i < 16; ++i)
    {
        _itoa_s(p->ReadU8(), acHex, 3, 16);
        strSwdId += acHex;
    }
}

// Glyph names and flags for a DefineFont font of the file.
// @0x1425c4f50
void SF_STDCALL GFx_DefineFontInfoLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    UInt16    fontId = p->ReadU16();
    FontData* pfd    = (FontData*)p->GetFontData(ResourceId(fontId));
    if (pfd)
        pfd->ReadFontInfo(p->GetStream(), tagInfo.TagType);
    else
        p->LogError("GFx_DefineFontInfoLoader - can't find FontResource w/ id %d", fontId);
}

// @0x1425c4fe0
void SF_STDCALL GFx_PlaceObjectLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    SF_UNUSED(tagInfo);
    p->LogParse("  PlaceObject\n");
    Stream*         pin    = p->GetStream();
    UPInt           dataSz = PlaceObjectTag::ComputeDataSize(pin);
    PlaceObjectTag* ptag   = p->AllocTag<PlaceObjectTag>(dataSz);
    pin->ReadToBuffer(ptag->pData, (unsigned)dataSz);
    ptag->CheckForCxForm(dataSz);
    p->AddExecuteTag(ptag);
}

// SWF 6 and later get the tag that reads the class flag of the place; an AS2 tag with clip events is the AVM's.
// @0x1425c50a0
void SF_STDCALL GFx_PlaceObject2Loader(LoadProcess* p, const TagInfo& tagInfo)
{
    SF_UNUSED(tagInfo);
    p->LogParse("  PlaceObject2Tag\n");
    Stream* pin              = p->GetStream();
    UPInt   dataSz           = PlaceObject2Tag::ComputeDataSize(pin, p->GetVersion());
    bool    hasEventHandlers = PlaceObject2Tag::HasEventHandlers(pin);
    if (hasEventHandlers)
        dataSz += sizeof(GFxPlaceObjectBase::EventArrayType*);

    PlaceObject2Tag* ptag = 0;
    if (hasEventHandlers && !(p->GetFileAttributes() & LoadProcess::FileAttr_UseActionScript3))
    {
        if (!p->GetLoadStates()->pAS2Support)
            p->LogError("GFx_PlaceObject2Loader - AS2 support is not installed. Tag is skipped.");
        else
            ptag = p->GetLoadStates()->pAS2Support->AllocPlaceObject2Tag(p, dataSz, (UInt8)p->GetVersion());
    }
    else if (p->GetVersion() >= 6)
        ptag = p->AllocTag<PlaceObject2Tag>(dataSz);
    else
        ptag = p->AllocTag<PlaceObject2Taga>(dataSz);
    if (!ptag)
        return;

    if (hasEventHandlers)
    {
        pin->ReadToBuffer(ptag->pData + sizeof(GFxPlaceObjectBase::EventArrayType*),
                          (unsigned)(dataSz - sizeof(GFxPlaceObjectBase::EventArrayType*)));
        PlaceObject2Tag::RestructureForEventHandlers(ptag->pData);
    }
    else
        pin->ReadToBuffer(ptag->pData, (unsigned)dataSz);
    p->AddExecuteTag(ptag);
}

// @0x1425c5210
void SF_STDCALL GFx_PlaceObject3Loader(LoadProcess* p, const TagInfo& tagInfo)
{
    SF_UNUSED(tagInfo);
    p->LogParse("  PlaceObject3Tag\n");
    Stream* pin              = p->GetStream();
    UPInt   dataSz           = PlaceObject3Tag::ComputeDataSize(pin);
    bool    hasEventHandlers = PlaceObject2Tag::HasEventHandlers(pin);
    if (hasEventHandlers)
        dataSz += sizeof(GFxPlaceObjectBase::EventArrayType*);

    PlaceObject3Tag* ptag = 0;
    if (hasEventHandlers && !(p->GetFileAttributes() & LoadProcess::FileAttr_UseActionScript3))
    {
        if (!p->GetLoadStates()->pAS2Support)
            p->LogError("GFx_PlaceObject3Loader - AS2 support is not installed. Tag is skipped.");
        else
            ptag = p->GetLoadStates()->pAS2Support->AllocPlaceObject3Tag(p, dataSz);
    }
    else
        ptag = p->AllocTag<PlaceObject3Tag>(dataSz);
    if (!ptag)
        return;

    if (hasEventHandlers)
    {
        pin->ReadToBuffer(ptag->pData + sizeof(GFxPlaceObjectBase::EventArrayType*),
                          (unsigned)(dataSz - sizeof(GFxPlaceObjectBase::EventArrayType*)));
        PlaceObject2Tag::RestructureForEventHandlers(ptag->pData);
    }
    else
        pin->ReadToBuffer(ptag->pData, (unsigned)dataSz);
    p->AddExecuteTag(ptag);
}

// @0x1425c57b0
void SF_STDCALL GFx_SpriteLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    SF_UNUSED(tagInfo);
    ResourceId characterId = ResourceId(p->ReadU16());
    p->LogParse("  sprite\n  char id = %d\n", characterId.GetIdIndex());

    Ptr<SpriteDef> ch = *SF_HEAP_NEW(p->GetLoadHeap()) SpriteDef(p->GetDataDef_Unsafe());
    ch->Read(p, characterId);
    p->AddCharacter(characterId, ch);
}

// @0x1425c5860
void SF_STDCALL GFx_RemoveObjectLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    SF_UNUSED(tagInfo);
    RemoveObjectTag* ptag = 0;
    if (!(p->GetFileAttributes() & LoadProcess::FileAttr_UseActionScript3))
    {
        if (!p->GetLoadStates()->pAS2Support)
            p->LogError("GFx_RemoveObjectLoader - AS2 support is not installed. Tag is skipped.");
        else
            ptag = p->GetLoadStates()->pAS2Support->AllocRemoveObjectTag(p);
    }
    else
        ptag = p->AllocTag<RemoveObjectTag>();
    if (!ptag)
        return;

    ptag->Read(p);
    p->LogParse("  RemoveObject(%d, %d)\n", ptag->Id, ptag->Depth);
    p->AddExecuteTag(ptag);
}

// @0x1425c5930
void SF_STDCALL GFx_RemoveObject2Loader(LoadProcess* p, const TagInfo& tagInfo)
{
    SF_UNUSED(tagInfo);
    RemoveObject2Tag* ptag = 0;
    if (!(p->GetFileAttributes() & LoadProcess::FileAttr_UseActionScript3))
    {
        if (!p->GetLoadStates()->pAS2Support)
            p->LogError("GFx_PlaceObject3Loader - AS2 support is not installed. Tag is skipped.");
        else
            ptag = p->GetLoadStates()->pAS2Support->AllocRemoveObject2Tag(p);
    }
    else
        ptag = p->AllocTag<RemoveObject2Tag>();
    if (!ptag)
        return;

    ptag->Read(p);
    p->LogParse("  RemoveObject2(%d)\n", ptag->Depth);
    p->AddExecuteTag(ptag);
}

// @0x1425c5a00
void SF_STDCALL GFx_DoActionLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    if (!(p->GetFileAttributes() & LoadProcess::FileAttr_UseActionScript3))
    {
        if (!p->GetLoadStates()->pAS2Support)
            p->LogError("GFx_DoActionLoader - AS2 support is not installed. Tag is skipped.");
        else
            p->GetLoadStates()->pAS2Support->DoActionLoader(p, tagInfo);
    }
    else
        p->LogError("GFx_DoActionLoader - DoAction tag shouldn't appear in AS3 swf. Tag is skipped.");
}

// @0x1425c5a50
void SF_STDCALL GFx_ButtonCharacterLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    int characterId = p->ReadU16();
    p->LogParse("  button GFxCharacter loader: CharId = %d\n", characterId);

    Ptr<ButtonDef> ch = *SF_HEAP_NEW(p->GetLoadHeap()) ButtonDef;
    ch->Read(p, tagInfo.TagType);
    p->AddResource(ResourceId(characterId), ch);
}

// @0x1425c5b00
void SF_STDCALL GFx_FrameLabelLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    SF_UNUSED(tagInfo);
    StringDH name(p->GetLoadHeap());
    p->GetStream()->ReadString(&name);
    p->AddFrameName(name, p->GetLogState());
    p->LogParse("  Frame label: \"%s\"\n", name.ToCStr());
}

// @0x1425c6400
void SF_STDCALL GFx_DoInitActionLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    if (!(p->GetFileAttributes() & LoadProcess::FileAttr_UseActionScript3))
    {
        if (!p->GetLoadStates()->pAS2Support)
            p->LogError("GFx_DoInitActionLoader - AS2 support is not installed. Tag is skipped.");
        else
            p->GetLoadStates()->pAS2Support->DoInitActionLoader(p, tagInfo);
    }
    else
        p->LogError("GFx_DoInitActionLoader - DoInitAction tag shouldn't appear in AS3 swf. Tag is skipped.");
}

// Only FlashPaper files have it; read so that the sprite it may sit in keeps its length.
// @0x1425c64c0
void SF_STDCALL GFx_SetTabIndexLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    SF_UNUSED(tagInfo);
    UInt16 depth    = p->ReadU16();
    UInt16 tabIndex = p->ReadU16();
    SF_UNUSED2(depth, tabIndex);
    p->LogParse("SetTabIndex (unused) \n");
}

// Scalar-deleting ExecuteTag wrapper; two identical wrappers are retained at their executable addresses.
// @0x1425c8550
void* FUN_1425c8550(void* object, unsigned flags)
{
    ExecuteTag base;
    *reinterpret_cast<const void**>(object) = *reinterpret_cast<const void* const*>(&base);
    if (flags & 1)
        ::operator delete(object, 0x10);
    return object;
}

// @0x1425c8670
void* FUN_1425c8670(void* object, unsigned flags)
{
    ExecuteTag base;
    *reinterpret_cast<const void**>(object) = *reinterpret_cast<const void* const*>(&base);
    if (flags & 1)
        ::operator delete(object, 0x10);
    return object;
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7ExecuteTag@GFx@Scaleform@@6B@ 0x14313ba68
// MS2-PIN: ??_7SetBackgroundColorTag@GFx@Scaleform@@6B@ 0x14318a330
// MS2-PIN: ??_7?$RefCountBase@VShapeDataInterface@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318f130
// MS2-PIN: ??_7ShapeDataInterface@Render@Scaleform@@6B@ 0x14317b678
// MS2-PIN: ??_7ShapeDataBase@GFx@Scaleform@@6B@ 0x14318a3b0
// MS2-PIN: ??_7ConstShapeWithStyles@GFx@Scaleform@@6B@ 0x14318a420
// MS2-PIN: ??_7PlaceObject2Tag@GFx@Scaleform@@6B@ 0x14313bb00
// MS2-PIN: ??_7PlaceObject2Taga@GFx@Scaleform@@6B@ 0x14318a2d0
// MS2-PIN: ??_7PlaceObject3Tag@GFx@Scaleform@@6B@ 0x14313bb60
// MS2-PIN: ??_7RemoveObject2Tag@GFx@Scaleform@@6B@ 0x14313bbc0
// MS2-PIN: ??_7RemoveObjectTag@GFx@Scaleform@@6B@ 0x14313bc10
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??_7?$RefCountBase@UExtraData@JPEG@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318a278
// MS2-PIN: ??_7ExtraData@JPEG@Render@Scaleform@@6B@ 0x14318a288
// MS2-PIN: ??_7TablesHeader@JPEG@Render@Scaleform@@6B@ 0x14318a298

// MS2-FUNCTIONAL: empty vtable slot (`ret 0`, no .pdata); referenced by data_data_game.
// @0x1425c5850
void FUN_1425c5850() {}
