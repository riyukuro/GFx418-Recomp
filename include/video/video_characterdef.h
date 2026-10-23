// Recovered Scaleform GFx video character definition interface.
// The vtable and the 0x30-byte empty-definition layout are derived from executable vptr stores and slots.
#ifndef MS2_SF_VIDEO_CHARACTERDEF_H
#define MS2_SF_VIDEO_CHARACTERDEF_H

#include "../gfx/gfx_characterdef.h"

namespace Scaleform { namespace GFx { namespace Video {

class VideoCharacterDef : public CharacterDef
{
public:
    UInt32 Width;
    UInt32 Height;
    UInt32 NumFrames;
    UByte Smoothing;
    UByte Deblocking;
    UByte Codec;

    VideoCharacterDef();
    virtual ~VideoCharacterDef();

    virtual unsigned GetResourceTypeCode() const { return MakeTypeCode(RT_VideoDef); }
    virtual ResourceReport* GetResourceReport() { return 0; }
    virtual CharacterDefType GetType() const { return Video; }
    virtual bool DefPointTestLocal(const PointF&, bool = 0, const DisplayObjectBase* = 0) const { return false; }
    virtual RectF GetBoundsLocal(float = 0) const { return RectF(); }
    virtual RectF GetRectBoundsLocal(float = 0) const { return RectF(); }
    virtual unsigned GetVersion() const { return 0; }

    Resource* GetResource() { return this; }
};

static_assert(sizeof(VideoCharacterDef) == 0x30, "VideoCharacterDef exe layout");
static_assert(offsetof(VideoCharacterDef, Width) == 0x20, "VideoCharacterDef width");
static_assert(offsetof(VideoCharacterDef, Codec) == 0x2e, "VideoCharacterDef codec");

}}}

#endif
