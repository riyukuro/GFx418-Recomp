// Recovered Scaleform 4.1.18 GFx: LoadProcess, the loader task that parses one SWF file into a MovieDataDef, as seen
// by the tag readers of this include tree (gfx_loadprocess.h is the declaration of the other tree, used by the AS3
// units). Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout (0x420 bytes) from the exe's tag readers; only the members the recovered units use are named.
#ifndef MS2_SF_GFX_LOADPROC_H
#define MS2_SF_GFX_LOADPROC_H

#include "gfx_loaderimpl.h"
#include "gfx_moviedef.h"
#include "gfx_stream.h"

namespace Scaleform { namespace GFx {

// The timeline a sprite definition is loaded into. Only its loading frame (vftable slot 18) is used so far; the
// CharacterDef / TimelineDef slots before it are not named yet.
class TimelineIODef : public Resource
{
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;

public:
    virtual unsigned GetLoadingFrame() const = 0;
};

class LoadProcess : public LoaderTask, public LogBase<LoadProcess>
{
public:
    enum LoadStateType
    {
        LS_LoadingRoot   = 0,
        LS_LoadingSprite = 1 // between DefineSprite and its end tag
    };

    // The stream of the tag being read: the SWF stream, or another one while a nested block is parsed.
    Stream* GetStream() { return pAltStream ? pAltStream : &ProcessStream; }

    unsigned GetLoadingFrame() const { return pLoadData->GetLoadingFrame(); }
    // A streaming sound block belongs to the frame of the timeline being loaded.
    unsigned GetLoadingFrameForStreamSound() const
    {
        if (LoadState == LS_LoadingSprite)
            return pTimelineDef->GetLoadingFrame();
        return GetLoadingFrame();
    }

    Log* GetLog() const;

private:
    // +0x20 LogBase<LoadProcess>
    unsigned                        ParseFlags;      // +0x28
    void*                           pBindProcess;    // +0x30 Ptr<MovieBindProcess>
    Ptr<MovieDataDef::LoadTaskData> pLoadData;       // +0x38
    MovieDataDef*                   pDataDef_Unsafe; // +0x40
    UByte                           Unknown48[8];    // +0x48
    Stream                          ProcessStream;   // +0x50 first member of the SWF process info
    UByte                           Unknown2C0[0xf8]; // +0x2c0 rest of the process info, JPEG tables, data lists
    LoadStateType                   LoadState;       // +0x3b8
    TimelineIODef*                  pTimelineDef;    // +0x3c0
    UByte                           Unknown3C8[0x50]; // +0x3c8 frame / init action tag arrays
    Stream*                         pAltStream;      // +0x418
};

}} // namespace Scaleform::GFx

#endif
