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
    // Instance of flash.media.ID3Info. 0x70 bytes, vftable 0x143178220.
    class ID3Info : public Instances::fl::Object
    {
    public:
        ID3Info(InstanceTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_media::ID3Info"; }

        ASString    album;      // +0x38
        ASString    artist;     // +0x40
        ASString    comment;    // +0x48
        ASString    genre;      // +0x50
        ASString    songName;   // +0x58
        ASString    track;      // +0x60
        ASString    year;       // +0x68
    };

    // Instance of flash.media.Sound. 0x78 bytes, vftable 0x1431787a0.
    class Sound : public Instances::fl_events::EventDispatcher
    {
    public:
        Sound(InstanceTraits::Traits& t);                                   // 0x1424cf830
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_media::Sound"; }
        virtual void AS3Constructor(unsigned argc, const Value* argv);      // 0x1424d0820
        virtual void InitInstance(bool extCall = false);                    // 0x1424d1130
    protected:
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;       // 0x1424d0fa0
    public:
        // @0x1424d18c0
        void bytesLoadedGet(UInt32& result);
        // @0x1424d18f0
        void bytesTotalGet(SInt32& result);
        // @0x1424d1920
        void close(const Value& result);
        // @0x1424d19a0
        void id3Get(SPtr<Instances::fl_media::ID3Info>& result);
        SPtr<Instances::fl_media::ID3Info> id3Get();   // 0x1424d1960 (sfr17)
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

        bool CreateLibraryObject();         // 0x1424d0a00: binds the library sound of an exported subclass
        void DispatchEventComplete();       // 0x1424d0b60
        void DispatchEventIOError();        // 0x1424d0c20
        void DispatchEventOpen();           // 0x1424d0cd0
        void DispatchEventSoundComplete();  // 0x1424d0d90

        Ptr<SoundObject>    pSoundObject;   // +0x50
        Ptr<SoundResource>  pResource;      // +0x58 the library sound of an exported Sound subclass
        String              SoundURL;       // +0x60
        bool                Streaming;      // +0x68
        SPtr<Instances::fl_media::SoundChannel> pChannel;   // +0x70 the channel of the last play()
    };

    // Instance of flash.media.SoundChannel.
    class SoundChannel : public Instances::fl_events::EventDispatcher
    {
    public:
        SoundChannel(InstanceTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_media::SoundChannel"; }
        // @0x1424d19e0
        void leftPeakGet(Value::Number& result);
        // @0x1424d1da0
        void positionGet(Value::Number& result);
        // @0x1424d1de0
        void rightPeakGet(Value::Number& result);
        // @0x1424d1ea0
        void soundTransformGet(SPtr<Instances::fl_media::SoundTransform>& result);
        SPtr<Instances::fl_media::SoundTransform> soundTransformGet();   // 0x1424d1e80
        // @0x1424d2070
        void soundTransformSet(const Value& result, Instances::fl_media::SoundTransform*);
        // @0x1424d20d0
        void stop(const Value& result);

        void DispatchEventSoundComplete();  // 0x1424d0ea0

        Ptr<SoundObject>    pSoundObject;   // +0x50; 0x58 bytes
    };

    // Instance of flash.media.SoundLoaderContext.
    // 0x48 bytes, vftable 0x143178ba8.
    class SoundLoaderContext : public Instances::fl::Object
    {
    public:
        SoundLoaderContext(InstanceTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_media::SoundLoaderContext"; }

        Value::Number   bufferTime;         // +0x38
        bool            checkPolicyFile;    // +0x40
    };

    // Instance of flash.media.SoundTransform.
    // 0x48 bytes, vftable 0x143178590.
    class SoundTransform : public Instances::fl::Object
    {
    public:
        SoundTransform(InstanceTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_media::SoundTransform"; }
        virtual void AS3Constructor(unsigned argc, const Value* argv);  // 0x1424d09a0

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
    class ID3Info : public CTraits
    {
    public:
        typedef Instances::fl_media::ID3Info InstanceType;

        ID3Info(VM& vm, const ClassInfo& ci);
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::ID3Info"; }
        virtual void MakeObject(Value& result, Traits& t);  // 0x1424d15d0
        Pickable<InstanceType> MakeInstance(ID3Info& t);   // 0x1424d1280
    };

    class Sound : public CTraits
    {
    public:
        typedef Instances::fl_media::Sound InstanceType;

        Sound(VM& vm, const ClassInfo& ci);
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Sound"; }
        virtual void MakeObject(Value& result, Traits& t);  // 0x1424d1700
        Pickable<InstanceType> MakeInstance(Sound& t);   // 0x1424d13c0
    };

    class SoundChannel : public CTraits
    {
    public:
        typedef Instances::fl_media::SoundChannel InstanceType;

        SoundChannel(VM& vm, const ClassInfo& ci);
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::SoundChannel"; }
        virtual void MakeObject(Value& result, Traits& t);  // 0x1424d1780
        Pickable<InstanceType> MakeInstance(SoundChannel& t);   // 0x1424d1450
    };

    class SoundLoaderContext : public CTraits
    {
    public:
        typedef Instances::fl_media::SoundLoaderContext InstanceType;

        SoundLoaderContext(VM& vm, const ClassInfo& ci);
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::SoundLoaderContext"; }
        virtual void MakeObject(Value& result, Traits& t);  // 0x1424d17e0
        Pickable<InstanceType> MakeInstance(SoundLoaderContext& t);   // 0x1424d14d0
    };

    class SoundTransform : public CTraits
    {
    public:
        typedef Instances::fl_media::SoundTransform InstanceType;

        SoundTransform(VM& vm, const ClassInfo& ci);
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::SoundTransform"; }
        virtual void MakeObject(Value& result, Traits& t);  // 0x1424d1850
        Pickable<InstanceType> MakeInstance(SoundTransform& t);   // 0x1424d1550
    };
}}

namespace Classes { namespace fl_media {
    class Camera : public Class
    {
    public:
        Camera(ClassTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Classes::Camera"; }
    };

    class Microphone : public Class
    {
    public:
        Microphone(ClassTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Classes::Microphone"; }
    };

    class SoundMixer : public Class
    {
    public:
        SoundMixer(ClassTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Classes::SoundMixer"; }
    };
}}

namespace ClassTraits { namespace fl_media {
    class Camera : public Traits
    {
    public:
        Camera(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Camera"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class ID3Info : public Traits
    {
    public:
        ID3Info(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ID3Info"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Microphone : public Traits
    {
    public:
        Microphone(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Microphone"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Sound : public Traits
    {
    public:
        Sound(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Sound"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SoundChannel : public Traits
    {
    public:
        SoundChannel(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SoundChannel"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SoundLoaderContext : public Traits
    {
    public:
        SoundLoaderContext(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SoundLoaderContext"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SoundMixer : public Traits
    {
    public:
        SoundMixer(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SoundMixer"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SoundTransform : public Traits
    {
    public:
        SoundTransform(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SoundTransform"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };
}}

}}} // namespace Scaleform::GFx::AS3

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_media::Camera) == 0xc8, "Camera size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_media::ID3Info) == 0xc8, "ID3Info size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_media::Microphone) == 0xc8, "Microphone size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_media::Sound) == 0xc8, "Sound size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_media::SoundChannel) == 0xc8, "SoundChannel size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_media::SoundLoaderContext) == 0xc8, "SoundLoaderContext size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_media::SoundMixer) == 0xc8, "SoundMixer size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_media::SoundTransform) == 0xc8, "SoundTransform size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_media::Camera) == 0x50, "Camera size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_media::Microphone) == 0x50, "Microphone size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_media::SoundMixer) == 0x50, "SoundMixer size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_media::ID3Info) == 0xe8, "ID3Info size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_media::Sound) == 0xe8, "Sound size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_media::SoundChannel) == 0xe8, "SoundChannel size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_media::SoundLoaderContext) == 0xe8, "SoundLoaderContext size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_media::SoundTransform) == 0xe8, "SoundTransform size");

#endif
