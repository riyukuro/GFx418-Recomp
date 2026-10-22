// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_UTILS_H
#define MS2_SF_GFX_AS3_OBJ_UTILS_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_events.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_utils {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class ByteArray : public Instances::fl::Object
    {
    public:
        // @0x1424bf580
        void bytesAvailableGet(UInt32& result);
        // @0x1424bf590
        void compress(Value& result, unsigned, const Value*);
        // @0x1424bf6d0
        void endianGet(ASString& result);
        // @0x1424bf750
        void endianSet(const Value& result, const ASString&);
        // @0x1424bf7f0
        void lengthGet(UInt32& result);
        // @0x1424bf800
        void lengthSet(const Value& result, UInt32);
        // @0x1424bf810
        void objectEncodingGet(UInt32& result);
        // @0x1424bf820
        void objectEncodingSet(const Value& result, UInt32);
        // @0x1424bf880
        void positionGet(UInt32& result);
        // @0x1424bf890
        void positionSet(const Value& result, UInt32);
        // @0x1424bf8a0
        void readBoolean(bool& result);
        // @0x1424bf8d0
        void readByte(SInt32& result);
        // @0x1424bf900
        void readBytes(const Value& result, Instances::fl_utils::ByteArray*, UInt32, UInt32);
        // @0x1424bf9e0
        void readDouble(Value::Number& result);
        // @0x1424bfa30
        void readFloat(Value::Number& result);
        // @0x1424bfab0
        void readInt(SInt32& result);
        // @0x1424bfaf0
        void readMultiByte(ASString& result, UInt32, const ASString&);
        // @0x1424bfd90
        void readObject(Value& result);
        // @0x1424bfde0
        void readShort(SInt32& result);
        // @0x1424bfe40
        void readUTF(ASString& result);
        // @0x1424bfeb0
        void readUTFBytes(ASString& result, UInt32);
        // @0x1424bfed0
        void readUnsignedByte(UInt32& result);
        // @0x1424bff00
        void readUnsignedInt(UInt32& result);
        // @0x1424bff40
        void readUnsignedShort(UInt32& result);
        // @0x1424c0380
        void toString(ASString& result);
        // @0x1424c0440
        void uncompress(Value& result, unsigned, const Value*);
        // @0x1424c05c0
        void writeBoolean(const Value& result, bool);
        // @0x1424c0650
        void writeByte(const Value& result, SInt32);
        // @0x1424c06e0
        void writeBytes(const Value& result, Instances::fl_utils::ByteArray*, UInt32, UInt32);
        // @0x1424c0770
        void writeDouble(const Value& result, Value::Number);
        // @0x1424c07b0
        void writeFloat(const Value& result, Value::Number);
        // @0x1424c0890
        void writeInt(const Value& result, SInt32);
        // @0x1424c08f0
        void writeMultiByte(const Value& result, const ASString&, const ASString&);
        // @0x1424c0a90
        void writeObject(const Value& result, const Value&);
        // @0x1424c0ae0
        void writeShort(const Value& result, SInt32);
        // @0x1424c0b90
        void writeUTF(const Value& result, const ASString&);
        // @0x1424c0c50
        void writeUTFBytes(const Value& result, const Value&);
        // @0x1424c0d10
        void writeUnsignedInt(const Value& result, UInt32);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Timer : public Instances::fl_events::EventDispatcher
    {
    public:
        // @0x1424bf620
        void currentCountGet(SInt32& result);
        // @0x1424bf6b0
        void delayGet(Value::Number& result);
        // @0x1424bf6c0
        void delaySet(const Value& result, Value::Number);
        // @0x1424bffa0
        void repeatCountGet(SInt32& result);
        // @0x1424bffb0
        void repeatCountSet(const Value& result, SInt32);
        // @0x1424bffc0
        void reset(const Value& result);
        // @0x1424bffe0
        void runningGet(bool& result);
        // @0x1424c0240
        void start(const Value& result);
        // @0x1424c0310
        void stop(const Value& result);
    };

}}

namespace Classes { namespace fl_utils {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class ByteArray : public Class
    {
    public:
        // @0x1424bf640
        void defaultObjectEncodingGet(UInt32& result);
        // @0x1424bf650
        void defaultObjectEncodingSet(const Value& result, UInt32);
    };

}}

namespace Classes { namespace fl_utils {
    class Endian : public Class
    {
    public:
        Endian(ClassTraits::Traits& t);
        // @0x1424be500
        virtual const char* GetAS3ObjectType() const { return "Classes::Endian"; }

        const char* BIG_ENDIAN;         // +0x50
        const char* LITTLE_ENDIAN;      // +0x58
    };

}}

namespace InstanceTraits { namespace fl_utils {
    // Traits of Dictionary instances: array-like, 0x48 bytes per instance.
    class Dictionary : public CTraits
    {
    public:
        Dictionary(VM& vm, const ClassInfo& ci);
        // @0x1424be4d0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Dictionary"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x1424beb70
    };

    class Timer : public CTraits
    {
    public:
        Timer(VM& vm, const ClassInfo& ci);
        // @0x1424be560
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Timer"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x1424bebe0
    };

}}

namespace ClassTraits { namespace fl_utils {
    class ByteArray : public Traits
    {
    public:
        ByteArray(VM& vm);                                      // 0x1424bc0e0
        // @0x1424be480
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ByteArray"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Dictionary : public Traits
    {
    public:
        Dictionary(VM& vm);
        // @0x1424be4c0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Dictionary"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Endian : public Traits
    {
    public:
        Endian(VM& vm);
        // @0x1424be4f0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Endian"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class IDataInput : public Traits
    {
    public:
        IDataInput(VM& vm);
        // @0x1424be510
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IDataInput"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class IDataOutput : public Traits
    {
    public:
        IDataOutput(VM& vm);
        // @0x1424be520
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IDataOutput"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class IExternalizable : public Traits
    {
    public:
        IExternalizable(VM& vm);
        // @0x1424be530
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IExternalizable"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Proxy : public Traits
    {
    public:
        Proxy(VM& vm);
        // @0x1424be540
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Proxy"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Timer : public Traits
    {
    public:
        Timer(VM& vm);
        // @0x1424be550
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Timer"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

}}

}}} // namespace Scaleform::GFx::AS3

#endif
