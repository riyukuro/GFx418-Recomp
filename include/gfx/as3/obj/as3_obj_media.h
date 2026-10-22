// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_MEDIA_H
#define MS2_SF_GFX_AS3_OBJ_MEDIA_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_events.h"
#include "ms2/scaleform/include/gfx/as3/as3_soundobject.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_media {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class ID3Info : public Instances::fl::Object
    {
    };

    // MS2-FUNCTIONAL: data members recovered up to Streaming (+0x68); the rest of the instance is not
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

        Ptr<SoundObject>    pSoundObject;   // +0x50
        void*               pSoundResource; // +0x58 (Ptr<SoundResource>; not used here)
        String              SoundURL;       // +0x60
        bool                Streaming;      // +0x68
    };

    // Instance of flash.media.SoundChannel.
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

        Ptr<SoundObject>    pSoundObject;   // +0x50; 0x58 bytes
    };

    // Instance of flash.media.SoundLoaderContext.
    // 0x48 bytes, vftable 0x143178ba8.
    class SoundLoaderContext : public Instances::fl::Object
    {
    public:
        SoundLoaderContext(InstanceTraits::Traits& t)   // 0x1424cfb10
            : Instances::fl::Object(t)
            , bufferTime(1000)
            , checkPolicyFile(false)
        {
        }

        Value::Number   bufferTime;         // +0x38
        bool            checkPolicyFile;    // +0x40
    };

    // Instance of flash.media.SoundTransform.
    // 0x48 bytes, vftable 0x143178590.
    class SoundTransform : public Instances::fl::Object
    {
    public:
        SoundTransform(InstanceTraits::Traits& t)   // 0x1424cfd90
            : Instances::fl::Object(t)
            , Volume(1.0)
            , Pan(0.0)
        {
        }

        Value::Number   Volume;     // +0x38
        Value::Number   Pan;        // +0x40

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

namespace InstanceTraits { namespace fl_media {
    class SoundLoaderContext : public CTraits
    {
    public:
        typedef Instances::fl_media::SoundLoaderContext InstanceType;

        virtual void MakeObject(Value& result, Traits& t);  // 0x1424d17e0
    };

    class SoundTransform : public CTraits
    {
    public:
        typedef Instances::fl_media::SoundTransform InstanceType;

        virtual void MakeObject(Value& result, Traits& t);  // 0x1424d1850
    };
}}

}}} // namespace Scaleform::GFx::AS3

#endif
