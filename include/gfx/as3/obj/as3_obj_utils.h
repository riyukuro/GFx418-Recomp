// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_UTILS_H
#define MS2_SF_GFX_AS3_OBJ_UTILS_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_events.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/kernel/sf_hash.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_utils {
    // 0x60 bytes, vftable 0x1431713f8.
    class ByteArray : public Instances::fl::Object
    {
    public:
        enum EncodingType { encAMF0 = 0, encAMF3 = 3 };
        enum EndianType { endianBig = 0, endianLittle = 1 };

        ByteArray(InstanceTraits::Traits& t);                   // 0x1424bc460
        ByteArray(InstanceTraits::Traits& t, EncodingType enc); // 0x1424bc4c0
        // @0x1424be4b0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_utils::ByteArray"; }
        virtual CheckResult SetProperty(const Multiname& prop_name, const Value& value);   // 0x1424bf000
        virtual CheckResult GetProperty(const Multiname& prop_name, Value& value);         // 0x1424be790
        virtual void GetDynamicProperty(AbsoluteIndex ind, Value& value);                  // 0x1424be580

        UInt32 GetLength() const { return Length; }
        UInt8 Get(UInt32 ind) const;                            // 0x1424be400
        void Set(UInt32 ind, UInt8 v);                          // 0x1424bef90
        // Replaces the content with size bytes of data, position back at 0.
        void Set(const void* data, UPInt size);                 // 0x1424befd0

    protected:
        // Copies n bytes at the position into dest; on running past the end raises EOFError and returns false.
        CheckResult Read(void* dest, UInt32 n);                 // 0x1424bec50
        CheckResult ReadUTFBytes(ASString& result, UInt32 len); // 0x1424bed20
        // True (and EOFError raised) when no byte is left to read.
        CheckResult EOFError();                                 // 0x1424bdb30
        void ThrowEOFError();                                   // 0x1424bf180
        void ThrowMemoryError();                                // 0x1424bf250
        void Write(UInt8 v);                                    // 0x1424bf320
        void Write(const void* src, UInt32 n);                  // 0x1424bf440
        // Sets the length, growing the storage with zeroes; the position stays inside.
        void Resize(UInt32 size);                               // 0x1424bef20
        // Grows the length to cover n more bytes at the position (the storage with zeroes).
        template <typename T> bool ReadValue(T& v);
        template <typename T> void WriteValue(T v);

        __forceinline void GrowFor(UInt32 n)
        {
            UInt32 newPos = Position + n;
            if (newPos < Data.GetSize())
            {
                if (Length <= newPos)
                    Length = newPos;
            }
            else
                Resize(newPos);
        }

    public:

        EncodingType            Encoding : 3;   // +0x38
        EndianType              Endian : 2;
        UInt32                  Position;       // +0x3c
        UInt32                  Length;         // +0x40
        ArrayLH_POD<UInt8>      Data;           // +0x48
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

    // 0x68 bytes, vftable 0x143171dd0.
    class Timer : public Instances::fl_events::EventDispatcher
    {
    public:
        Timer(InstanceTraits::Traits& t);                       // 0x1424bcc80
        // @0x1424be570
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_utils::Timer"; }
        virtual void AS3Constructor(unsigned argc, const Value* argv);                     // 0x1424bd590

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

        SInt32                      RepeatCount;    // +0x50
        SInt32                      CurrentCount;   // +0x54 the core timer's count once it ran
        Value::Number               Delay;          // +0x58 milliseconds
        Ptr<ASIntervalTimerIntf>    pCoreTimer;     // +0x60
    };

    // flash.utils.Dictionary: a hash keyed by value identity. 0x48 bytes, vftable 0x143171810.
    class Dictionary : public Instances::fl::Object
    {
    public:
        typedef HashLH<Value, Value, Value::HashFunctor, 2> ContainerType;

        Dictionary(InstanceTraits::Traits& t);                  // 0x1424bc660
        ~Dictionary();                                          // 0x1424bcd70
        // @0x1424be4e0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_utils::Dictionary"; }
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;                      // 0x1424be3b0
        virtual CheckResult SetProperty(const Multiname& prop_name, const Value& value);   // 0x1424bf0b0
        virtual CheckResult GetProperty(const Multiname& prop_name, Value& value);         // 0x1424be850
        virtual void GetDynamicProperty(AbsoluteIndex ind, Value& value);                  // 0x1424be5e0
        virtual CheckResult DeleteProperty(const Multiname& prop_name);                    // 0x1424bda80
        virtual void AS3Constructor(unsigned argc, const Value* argv);                     // 0x1424bd560
        virtual void AddDynamicSlotValuePair(const Value& prop_name, const Value& v,
                                             SlotInfo::Attribute a = SlotInfo::aNone);     // 0x1424bd650
        virtual void GetNextPropertyName(Value& name, GlobalSlotIndex ind) const;          // 0x1424be710
        virtual GlobalSlotIndex GetNextDynPropIndex(GlobalSlotIndex ind) const;            // 0x1424be630
        virtual PropRef FindDynamicSlot(const Multiname& mn);                              // 0x1424bdd70

        ContainerType::Iterator FindKey(const Multiname& mn);                              // 0x1424bde70

        bool                WeakKeys;   // +0x38
        ContainerType       ValueH;     // +0x40
    };

}}

namespace Classes { namespace fl_utils {
    // 0x58 bytes, vftable 0x1431715f8.
    class ByteArray : public Class
    {
    public:
        ByteArray(ClassTraits::Traits& t);                      // 0x1424bc300
        // @0x1424be490
        virtual const char* GetAS3ObjectType() const { return "Classes::ByteArray"; }

        UInt32 DefaultObjectEncoding;   // +0x50
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
    // Traits of ByteArray instances: array-like, 0x60 bytes per instance; implements IDataInput and IDataOutput.
    class ByteArray : public CTraits
    {
    public:
        typedef Instances::fl_utils::ByteArray InstanceType;

        ByteArray(VM& vm, const ClassInfo& ci);                 // 0x1424bc330
        // @0x1424be4a0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::ByteArray"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x1424beae0
        Pickable<InstanceType> MakeInstance(ByteArray& t);
    };

    // Traits of Dictionary instances: array-like, 0x48 bytes per instance.
    class Dictionary : public CTraits
    {
    public:
        typedef Instances::fl_utils::Dictionary InstanceType;

        Dictionary(VM& vm, const ClassInfo& ci);
        // @0x1424be4d0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Dictionary"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x1424beb70
        Pickable<InstanceType> MakeInstance(Dictionary& t);
    };

    class Timer : public CTraits
    {
    public:
        typedef Instances::fl_utils::Timer InstanceType;

        Timer(VM& vm, const ClassInfo& ci);
        // @0x1424be560
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Timer"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x1424bebe0
        Pickable<InstanceType> MakeInstance(Timer& t);
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
