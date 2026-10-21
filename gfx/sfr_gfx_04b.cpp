// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_TagLoaders: the readers of the
// SWF / GFx tags (SWF_TagLoaderTable, by tag type) and the compiler-generated helpers emitted with them.
// Second source of queue unit sfr_gfx_04 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_04b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425c4330-0x1425c43a0 .text$mn
// MS2-RANGE: 0x1425c4e90-0x1425c5340 .text$mn
// MS2-RANGE: 0x1425c57b0-0x1425c5bb0 .text$mn
// MS2-RANGE: 0x1425c6400-0x1425c6450 .text$mn
// MS2-RANGE: 0x1425c64c0-0x1425c64eb .text$mn
// MS2-RANGE: 0x1425c8550-0x1425c857b .text$mn
// MS2-RANGE: 0x1425c8670-0x1425c869b .text$mn
// MS2-RANGE: 0x1425c88d0-0x1425c894d .text$mn
// MS2-RANGE: 0x1425c8b20-0x1425c8b31 .text$mn
// MS2-RANGE: 0x1425c8ca0-0x1425c8ce8 .text$mn
// MS2-RANGE: 0x1425c8cf0-0x1425c8d08 .text$mn

#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_placeobject.h"
#include "../include/gfx/gfx_spritedef.h"
#include "../include/gfx/gfx_buttondef.h"
#include "../include/gfx/gfx_fontlib.h"

#include <stdlib.h>

namespace Scaleform { namespace GFx {

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

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7ExecuteTag@GFx@Scaleform@@6B@ 0x14313ba68
// MS2-PIN: ??_7SetBackgroundColorTag@GFx@Scaleform@@6B@ 0x14318a330
// MS2-PIN: ??_7PlaceObject2Tag@GFx@Scaleform@@6B@ 0x14313bb00
// MS2-PIN: ??_7PlaceObject2Taga@GFx@Scaleform@@6B@ 0x14318a2d0
// MS2-PIN: ??_7PlaceObject3Tag@GFx@Scaleform@@6B@ 0x14313bb60
// MS2-PIN: ??_7RemoveObject2Tag@GFx@Scaleform@@6B@ 0x14313bbc0
// MS2-PIN: ??_7RemoveObjectTag@GFx@Scaleform@@6B@ 0x14313bc10
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
