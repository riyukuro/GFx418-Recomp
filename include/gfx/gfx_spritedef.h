// Recovered Scaleform 4.1.18 GFx: SpriteDef, the definition (timeline) of a movie clip symbol.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout is the exe's (ctor 0x1425d5320): CharacterDef +0..0x20, pMovieDef +0x20, NamedFrames +0x28, FrameCount
// +0x30, LoadingFrame +0x34, Playlist +0x38, pScale9Grid +0x50, pSoundStream +0x58, Flags +0x60; 0x68 bytes.
// Bodies: GFx_SpriteDef (sfr_gfx_04 / sfr_gfx_05).
#ifndef MS2_SF_GFX_SPRITEDEF_H
#define MS2_SF_GFX_SPRITEDEF_H

#include "gfx_characterdef.h"
#include "gfx_scale9grid.h"
#include "../kernel/sf_array.h"
#include "../kernel/sf_stringhash.h"

namespace Scaleform { namespace GFx {

class MovieDataDef;
class SoundStreamDef;

class SpriteDef : public TimelineDef
{
public:
    MovieDataDef*                    pMovieDef;      // +0x20
    StringHashLH<unsigned>           NamedFrames;    // +0x28 label -> 0-based frame
    int                              FrameCount;     // +0x30
    int                              LoadingFrame;   // +0x34
    ArrayLH<Frame, 0x109>            Playlist;       // +0x38 one entry per frame (StatMD_Other_Mem)
    Scale9Grid*                      pScale9Grid;    // +0x50
    Ptr<SoundStreamDef>              pSoundStream;   // +0x58
    UByte                            Flags;          // +0x60

    RectF GetScale9Grid() const { return pScale9Grid ? pScale9Grid->Rect : RectF(0); }
    bool  HasScale9Grid() const { return pScale9Grid != 0; }
};

}} // namespace Scaleform::GFx

#endif
