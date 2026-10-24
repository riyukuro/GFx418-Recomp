// Recovered Scaleform 4.1.18 GFx: SpriteDef, the definition (timeline) of a movie clip symbol.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout is the exe's (ctor 0x1425d5320): CharacterDef +0..0x20, pMovieDef +0x20, NamedFrames +0x28, FrameCount
// +0x30, LoadingFrame +0x34, Playlist +0x38, pScale9Grid +0x50, pSoundStream +0x58, Flags +0x60; 0x68 bytes.
// Bodies: GFx_SpriteDef (sfr_gfx_04 / sfr_gfx_05).
#ifndef MS2_SF_GFX_SPRITEDEF_H
#define MS2_SF_GFX_SPRITEDEF_H

#include "gfx_characterdef.h"
#include "gfx_loadproc.h"
#include "gfx_moviedef.h"
#include "gfx_scale9grid.h"
#include "../kernel/sf_array.h"
#include "../kernel/sf_stringhash.h"

namespace Scaleform { namespace GFx {

class MovieDataDef;
class SoundStreamDef;

// vftable 0x14318bb08 (TimelineIODef's is 0x14318ba08).
class SpriteDef : public TimelineIODef
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

    // (appended for the sprite definitions, sfr_gfx_05)
    enum
    {
        Flags_Has_Frame_up     = 0x1,
        Flags_Has_Frame_down   = 0x2,
        Flags_Has_Frame_over   = 0x4,
        Flags_HasSpecialFrames = Flags_Has_Frame_up | Flags_Has_Frame_down | Flags_Has_Frame_over
    };

    SpriteDef(MovieDataDef* pmd);
    ~SpriteDef();

    virtual CharacterDefType GetType() const { return Sprite; }

    // A clip of one empty frame.
    void InitEmptyClipDef();
    // Reads the DefineSprite tag body (on the loading thread).
    void Read(LoadProcess* p, ResourceId charId);

    virtual float    GetWidth() const  { return 1; }
    virtual float    GetHeight() const { return 1; }
    virtual bool     DefPointTestLocal(const PointF& pt, bool testShape = 0, const DisplayObjectBase* pinst = 0) const;
    virtual unsigned GetFrameCount() const   { return FrameCount; }
    virtual float    GetFrameRate() const    { return pMovieDef->GetFrameRate(); }
    virtual RectF    GetFrameRect() const    { return RectF(0, 0, 1, 1); }
    virtual unsigned GetLoadingFrame() const { return LoadingFrame; }
    virtual unsigned GetVersion() const      { return pMovieDef->GetVersion(); }
    virtual unsigned GetSWFFlags() const     { return pMovieDef->GetSWFFlags(); }
    virtual unsigned GetTagCount() const     { return 0; }
    virtual UInt32   GetFileBytes() const    { return pMovieDef->GetFileBytes(); }
    virtual const char* GetFileURL() const   { return pMovieDef->GetFileURL(); }

    // Frame numbers are 0-based.
    virtual bool GetLabeledFrame(const char* label, unsigned* frameNumber, bool translateNumbers = 1) const
    {
        return MovieDataDef::TranslateFrameString(NamedFrames, label, frameNumber, translateNumbers);
    }
    virtual const String* GetFrameLabel(unsigned frameNumber, unsigned* exactFrameNumberForLabel = 0) const
    {
        return MovieDataDef::TranslateNumberToFrameString(NamedFrames, frameNumber, exactFrameNumberForLabel);
    }
    virtual Array<String>* GetFrameLabels(unsigned frameNumber, Array<String>* destArr) const;

    virtual void AddFrameName(const String& name, LogState* plog);
    // 4.1.18 stores the frame without checking it against the frame count.
    virtual void SetLoadingPlaylistFrame(const Frame& frame, LogState* plog) { Playlist[LoadingFrame] = frame; }

    virtual const Frame GetPlaylist(int frameNumber) const { return Playlist[frameNumber]; }
    // Only the root timeline has InitAction frames.
    virtual bool GetInitActions(Frame* pframe, int frameNumber) const { return false; }

    virtual SoundStreamDef* GetSoundStream() const { return pSoundStream; }
    virtual void            SetSoundStream(SoundStreamDef* psoundStream);

    virtual unsigned GetResourceTypeCode() const { return MakeTypeCode(RT_SpriteDef); }
};

}} // namespace Scaleform::GFx

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::SpriteDef) == 0x68, "SpriteDef size");

#endif
