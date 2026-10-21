// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_MEDIA_H
#define MS2_SF_GFX_AS3_OBJ_MEDIA_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_events.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_media {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Sound : public Instances::fl_events::EventDispatcher
    {
    public:
        // @0x1424d18c0
        void bytesLoadedGet(UInt32& result);
        // @0x1424d18f0
        void bytesTotalGet(SInt32& result);
        // @0x1424d1920
        void close(const Value& result);
        // @0x1424d19a0
        void id3Get(SPtr<Instances::fl_media::ID3Info>& result);
        // @0x1424d19c0
        void isBufferingGet(bool& result);
        // @0x1424d1a80
        void lengthGet(Value::Number& result);
        // @0x1424d1ac0
        void load(const Value& result, Instances::fl_net::URLRequest*, Instances::fl_media::SoundLoaderContext*);
        // @0x1424d1b60
        void play(Value& result, Value::Number, SInt32, Instances::fl_media::SoundTransform*);
        // @0x1424d20e0
        void urlGet(ASString& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class SoundChannel : public Instances::fl_events::EventDispatcher
    {
    public:
        // @0x1424d19e0
        void leftPeakGet(Value::Number& result);
        // @0x1424d1da0
        void positionGet(Value::Number& result);
        // @0x1424d1de0
        void rightPeakGet(Value::Number& result);
        // @0x1424d1ea0
        void soundTransformGet(SPtr<Instances::fl_media::SoundTransform>& result);
        // @0x1424d2070
        void soundTransformSet(const Value& result, Instances::fl_media::SoundTransform*);
        // @0x1424d20d0
        void stop(const Value& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class SoundTransform : public Instances::fl::Object
    {
    public:
        // @0x1424d1a00
        void leftToLeftGet(Value::Number& result);
        // @0x1424d1a20
        void leftToLeftSet(const Value& result, Value::Number);
        // @0x1424d1a40
        void leftToRightGet(Value::Number& result);
        // @0x1424d1a60
        void leftToRightSet(const Value& result, Value::Number);
        // @0x1424d1b40
        void panGet(Value::Number& result);
        // @0x1424d1b50
        void panSet(const Value& result, Value::Number);
        // @0x1424d1e00
        void rightToLeftGet(Value::Number& result);
        // @0x1424d1e20
        void rightToLeftSet(const Value& result, Value::Number);
        // @0x1424d1e40
        void rightToRightGet(Value::Number& result);
        // @0x1424d1e60
        void rightToRightSet(const Value& result, Value::Number);
        // @0x1424d2140
        void volumeGet(Value::Number& result);
        // @0x1424d2150
        void volumeSet(const Value& result, Value::Number);
    };

}}

}}} // namespace Scaleform::GFx::AS3

#endif
