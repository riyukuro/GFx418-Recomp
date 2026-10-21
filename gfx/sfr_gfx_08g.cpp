// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_ButtonDef (the button
// definition: its character records read from DefineButton / DefineButton2, its actions and its ButtonSound
// sounds).
// Seventh source of queue unit sfr_gfx_08 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_08
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14265da80-0x14265ebc0 .text$mn

#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_buttondef.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_sound.h"
#include "../include/kernel/sf_memory.h"
#include "../include/render/render_filters.h"

namespace Scaleform { namespace GFx {

// Filter list reader of the SWF 8 records (GFx_FilterDesc, sfr_gfx_08b).
template<class S>
unsigned LoadFilters(S* ps, Render::FilterSet* filters);

// @0x14265e540
// MS2-FUNCTIONAL: same code; the stream / process / flags registers are allocated differently (r14, r15, rbp rotated)
bool ButtonRecord::Read(LoadProcess* p, TagType tagType)
{
    int flags = p->ReadU8();
    if (flags == 0)
        return false;

    Stream* pin = p->GetStream();

    pin->LogParse("-- action record:  ");
    Flags = 0;
    if (flags & 8)
    {
        Flags |= Mask_HitTest;
        pin->LogParse("HitTest ");
    }
    if (flags & 4)
    {
        Flags |= Mask_Down;
        pin->LogParse("Down ");
    }
    if (flags & 2)
    {
        Flags |= Mask_Over;
        pin->LogParse("Over ");
    }
    if (flags & 1)
    {
        Flags |= Mask_Up;
        pin->LogParse("Up ");
    }
    pin->LogParse("\n");

    int characterId = p->ReadU16();
    CharacterId     = ResourceId(characterId);
    Depth           = p->ReadU16();
    pin->ReadMatrix(&ButtonMatrix);

    pin->LogParse("   CharId = %d, Depth = %d\n", characterId, Depth);
    pin->LogParse("   mat:\n");
    pin->LogParseClass(ButtonMatrix);

    if (tagType == Tag_ButtonCharacter2)
    {
        pin->ReadCxformRgba(&ButtonCxform);
        pin->LogParse("   cxform:\n");
        pin->LogParseClass(ButtonCxform);
    }

    // SWF 8: a filter list, then a blend mode.
    if (flags & 0x10)
    {
        pin->LogParse("   HasFilters\n");

        Ptr<Render::FilterSet> filters = *SF_HEAP_NEW(p->GetLoadHeap()) Render::FilterSet;
        if (LoadFilters(pin, filters.GetPtr()))
            pFilters = filters;
    }
    if (flags & 0x20)
    {
        UByte blendMode = pin->ReadU8();
        if (blendMode < 1 || blendMode > 14)
            blendMode = 1;
        BlendMode = (Render::BlendMode)blendMode;
        pin->LogParse("   HasBlending, %d\n", (int)BlendMode);
    }
    else
    {
        BlendMode = Render::Blend_None;
    }
    return true;
}

// @0x14265da80
ButtonDef::ButtonDef() : pSound(0), pScale9Grid(0), Menu(false)
{
}

// @0x14265db40
ButtonDef::~ButtonDef()
{
    delete pSound;
    delete pScale9Grid;
}

// Reads past a ButtonSound record set when there is no audio library.
// @0x14265e960
void SkipButtonSoundDef(LoadProcess* p)
{
    Stream* in = p->GetStream();
    for (int i = 0; i < 4; i++)
    {
        UInt16 rid = p->ReadU16();
        if (rid == 0)
            continue;
        in->ReadUInt(2); // reserved
        in->ReadUInt(1); // stop playback
        in->ReadUInt(1); // no multiple
        bool hasEnvelope = in->ReadUInt(1) ? true : false;
        bool hasLoops    = in->ReadUInt(1) ? true : false;
        bool hasOutPoint = in->ReadUInt(1) ? true : false;
        bool hasInPoint  = in->ReadUInt(1) ? true : false;
        if (hasInPoint)
            in->ReadU32();
        if (hasOutPoint)
            in->ReadU32();
        if (hasLoops)
            in->ReadU16();
        if (hasEnvelope)
        {
            int points = in->ReadU8();
            for (int j = 0; j < points; j++)
            {
                in->ReadU32();
                in->ReadU16();
                in->ReadU16();
            }
        }
    }
}

// @0x14265de60
void ButtonDef::Read(LoadProcess* p, TagType tagType)
{
    if (tagType == Tag_ButtonCharacter)
    {
        // Records up to the null one, kept sorted by depth so that they draw in order.
        for (;;)
        {
            ButtonRecord r;
            if (!r.Read(p, tagType))
                break;

            unsigned i;
            for (i = 0; i < ButtonRecords.GetSize(); i++)
                if (ButtonRecords[i].Depth > r.Depth)
                    break;
            ButtonRecords.InsertAt(i, r);
        }

        // The actions follow the records.
        if (!(p->GetFileAttributes() & LoadProcess::FileAttr_UseActionScript3))
        {
            if (p->GetLoadStates()->pAS2Support)
                p->GetLoadStates()->pAS2Support->ReadButtonActions(p, this, tagType);
            else
                p->LogError("GFx_ButtonLoader - AS2 support is not installed. Actions are skipped.");
        }
        else
            p->LogError("GFx_ButtonLoader - AS3 Button shouldn't have AS2 actions. Skipped.");
    }
    else if (tagType == Tag_ButtonSound)
    {
        AudioBase* paudio = p->GetLoadStates()->pAudioState;
        if (paudio)
            pSound = paudio->GetSoundTagsReader()->ReadButtonSoundDef(p);
        else
        {
            SkipButtonSoundDef(p);
            p->LogScriptWarning("ButtonDef::Read - Audio library is not set. Skipping sound definitions.");
        }
    }
    else if (tagType == Tag_ButtonCharacter2)
    {
        Menu = p->ReadU8() != 0;

        // Offset of the condition actions from the offset field itself.
        int actionOffset  = p->ReadU16();
        int nextActionPos = p->Tell() + actionOffset - 2;

        for (;;)
        {
            ButtonRecord r;
            if (!r.Read(p, tagType))
                break;

            unsigned i;
            for (i = 0; i < ButtonRecords.GetSize(); i++)
                if (ButtonRecords[i].Depth > r.Depth)
                    break;
            ButtonRecords.InsertAt(i, r);
        }

        if (actionOffset > 0)
        {
            if (!(p->GetFileAttributes() & LoadProcess::FileAttr_UseActionScript3))
            {
                if (p->GetLoadStates()->pAS2Support)
                {
                    p->SetPosition(nextActionPos);
                    p->GetLoadStates()->pAS2Support->ReadButton2ActionConditions(p, this, tagType);
                }
                else
                    p->LogError("GFx_ButtonLoader - AS2 support is not installed. Actions are skipped.");
            }
            else
                p->LogError("GFx_ButtonLoader - AS3 Button shouldn't have AS2 actions. Skipped.");
        }
    }
}

// @0x14265dcc0
void ButtonDef::AddButtonAction(ButtonActionBase* pact)
{
    ButtonActions.PushBack(pact);
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7ButtonDef@GFx@Scaleform@@6B@ 0x1431914b0
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
