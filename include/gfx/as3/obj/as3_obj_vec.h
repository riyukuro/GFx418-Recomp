// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_VEC_H
#define MS2_SF_GFX_AS3_OBJ_VEC_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/as3_vec_base.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_vec {
    // 0x70 bytes; vftable 0x143182788.
    class Vector_String : public Instances::fl::Object
    {
    public:
        // @0x142557400
        void AS3concat(Value& result, unsigned, const Value*);
        // @0x1425574a0
        void AS3every(bool& result, const Value&, const Value&);
        // @0x142557590
        void AS3filter(SPtr<Instances::fl_vec::Vector_String>& result, const Value&, const Value&);
        // @0x142557630
        void AS3forEach(const Value& result, const Value&, const Value&);
        // @0x1425576d0
        void AS3indexOf(SInt32& result, const ASString&, SInt32);
        // @0x1425578a0
        void AS3join(ASString& result, const ASString&);
        // @0x142557a30
        void AS3lastIndexOf(SInt32& result, const ASString&, SInt32);
        // @0x142557c30
        void AS3map(SPtr<Instances::fl_vec::Vector_String>& result, const Value&, const Value&);
        // @0x142557cd0
        void AS3pop(ASString& result);
        // @0x142558120
        void AS3push(Value& result, unsigned, const Value*);
        // @0x1425583c0
        void AS3reverse(SPtr<Instances::fl_vec::Vector_String>& result);
        // @0x1425587a0
        void AS3shift(ASString& result);
        // @0x142558b20
        void AS3slice(Value& result, unsigned, const Value*);
        // @0x142558bc0
        void AS3some(bool& result, const Value&, const Value&);
        // @0x142558cb0
        void AS3sort(SPtr<Instances::fl_vec::Vector_String>& result, const Value&);
        // @0x1425592b0
        void AS3splice(Value& result, unsigned, const Value*);
        // @0x142559350
        void AS3toLocaleString(ASString& result);
        // @0x142559530
        void AS3toString(ASString& result);
        // @0x142559710
        void AS3unshift(Value& result, unsigned, const Value*);
        // @0x142564bf0
        void fixedGet(bool& result);
        // @0x142564c40
        void fixedSet(const Value& result, bool);
        // @0x142564c90
        void lengthGet(UInt32& result);
        // @0x142564ce0
        void lengthSet(const Value& result, UInt32);

    public:
        // (appended, sfr13) the vector object; bodies in sfr_as3_21 unless noted
        // @0x142560110
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_vec::Vector_String"; }
        virtual CheckResult SetProperty(const Multiname& prop_name, const Value& value);   // 0x142563b20
        virtual CheckResult GetProperty(const Multiname& prop_name, Value& value);         // 0x1425607e0
        virtual void GetDynamicProperty(AbsoluteIndex ind, Value& value);                   // 0x142560270
        virtual CheckResult DeleteProperty(const Multiname& prop_name);                     // 0x14255b7f0
        virtual void AS3Constructor(unsigned argc, const Value* argv);                      // 0x142557110 (sfr_as3_20)
        virtual void GetNextPropertyName(Value& name, GlobalSlotIndex ind) const;           // 0x142560510
        virtual GlobalSlotIndex GetNextDynPropIndex(GlobalSlotIndex ind) const;             // 0x142560330

        VectorBase<Ptr<ASStringNode> > V;   // +0x38
    };

    // 0x70 bytes; vftable 0x143182488.
    class Vector_double : public Instances::fl::Object
    {
    public:
        // @0x142557420
        void AS3concat(Value& result, unsigned, const Value*);
        // @0x1425574d0
        void AS3every(bool& result, const Value&, const Value&);
        // @0x1425575b0
        void AS3filter(SPtr<Instances::fl_vec::Vector_double>& result, const Value&, const Value&);
        // @0x142557650
        void AS3forEach(const Value& result, const Value&, const Value&);
        // @0x142557740
        void AS3indexOf(SInt32& result, Value::Number, SInt32);
        // @0x1425578f0
        void AS3join(ASString& result, const ASString&);
        // @0x142557aa0
        void AS3lastIndexOf(SInt32& result, Value::Number, SInt32);
        // @0x142557c50
        void AS3map(SPtr<Instances::fl_vec::Vector_double>& result, const Value&, const Value&);
        // @0x142557e00
        void AS3pop(Value::Number& result);
        // @0x1425581a0
        void AS3push(Value& result, unsigned, const Value*);
        // @0x1425584f0
        void AS3reverse(SPtr<Instances::fl_vec::Vector_double>& result);
        // @0x142558850
        void AS3shift(Value::Number& result);
        // @0x142558b40
        void AS3slice(Value& result, unsigned, const Value*);
        // @0x142558bf0
        void AS3some(bool& result, const Value&, const Value&);
        // @0x142558de0
        void AS3sort(SPtr<Instances::fl_vec::Vector_double>& result, const Value&);
        // @0x1425592d0
        void AS3splice(Value& result, unsigned, const Value*);
        // @0x1425593b0
        void AS3toLocaleString(ASString& result);
        // @0x142559590
        void AS3toString(ASString& result);
        // @0x142559790
        void AS3unshift(Value& result, unsigned, const Value*);
        // @0x142564c00
        void fixedGet(bool& result);
        // @0x142564c50
        void fixedSet(const Value& result, bool);
        // @0x142564ca0
        void lengthGet(UInt32& result);
        // @0x142564d00
        void lengthSet(const Value& result, UInt32);

    public:
        // (appended, sfr13) the vector object; bodies in sfr_as3_21 unless noted
        // @0x142560150
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_vec::Vector_double"; }
        virtual CheckResult SetProperty(const Multiname& prop_name, const Value& value);   // 0x142563bb0
        virtual CheckResult GetProperty(const Multiname& prop_name, Value& value);         // 0x142560870
        virtual void GetDynamicProperty(AbsoluteIndex ind, Value& value);                   // 0x142560280
        virtual CheckResult DeleteProperty(const Multiname& prop_name);                     // 0x14255b890
        virtual void AS3Constructor(unsigned argc, const Value* argv);                      // 0x142557180 (sfr_as3_20)
        virtual void GetNextPropertyName(Value& name, GlobalSlotIndex ind) const;           // 0x1425605a0
        virtual GlobalSlotIndex GetNextDynPropIndex(GlobalSlotIndex ind) const;             // 0x142560390

        VectorBase<Value::Number > V;   // +0x38
    };

    // 0x70 bytes; vftable 0x143181e58.
    class Vector_int : public Instances::fl::Object
    {
    public:
        // @0x142557440
        void AS3concat(Value& result, unsigned, const Value*);
        // @0x142557500
        void AS3every(bool& result, const Value&, const Value&);
        // @0x1425575d0
        void AS3filter(SPtr<Instances::fl_vec::Vector_int>& result, const Value&, const Value&);
        // @0x142557670
        void AS3forEach(const Value& result, const Value&, const Value&);
        // @0x142557790
        void AS3indexOf(SInt32& result, SInt32, SInt32);
        // @0x142557940
        void AS3join(ASString& result, const ASString&);
        // @0x142557b00
        void AS3lastIndexOf(SInt32& result, SInt32, SInt32);
        // @0x142557c70
        void AS3map(SPtr<Instances::fl_vec::Vector_int>& result, const Value&, const Value&);
        // @0x142557ea0
        void AS3pop(SInt32& result);
        // @0x142558220
        void AS3push(Value& result, unsigned, const Value*);
        // @0x142558590
        void AS3reverse(SPtr<Instances::fl_vec::Vector_int>& result);
        // @0x142558910
        void AS3shift(SInt32& result);
        // @0x142558b60
        void AS3slice(Value& result, unsigned, const Value*);
        // @0x142558c20
        void AS3some(bool& result, const Value&, const Value&);
        // @0x142558f10
        void AS3sort(SPtr<Instances::fl_vec::Vector_int>& result, const Value&);
        // @0x1425592f0
        void AS3splice(Value& result, unsigned, const Value*);
        // @0x142559410
        void AS3toLocaleString(ASString& result);
        // @0x1425595f0
        void AS3toString(ASString& result);
        // @0x142559810
        void AS3unshift(Value& result, unsigned, const Value*);
        // @0x142564c10
        void fixedGet(bool& result);
        // @0x142564c60
        void fixedSet(const Value& result, bool);
        // @0x142564cb0
        void lengthGet(UInt32& result);
        // @0x142564d20
        void lengthSet(const Value& result, UInt32);

    public:
        // (appended, sfr13) the vector object; bodies in sfr_as3_21 unless noted
        // @0x142560190
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_vec::Vector_int"; }
        virtual CheckResult SetProperty(const Multiname& prop_name, const Value& value);   // 0x142563c40
        virtual CheckResult GetProperty(const Multiname& prop_name, Value& value);         // 0x142560930
        virtual void GetDynamicProperty(AbsoluteIndex ind, Value& value);                   // 0x142560290
        virtual CheckResult DeleteProperty(const Multiname& prop_name);                     // 0x14255b970
        virtual void AS3Constructor(unsigned argc, const Value* argv);                      // 0x1425571f0 (sfr_as3_20)
        virtual void GetNextPropertyName(Value& name, GlobalSlotIndex ind) const;           // 0x142560630
        virtual GlobalSlotIndex GetNextDynPropIndex(GlobalSlotIndex ind) const;             // 0x1425603f0

        VectorBase<SInt32 > V;   // +0x38
    };

    // 0x70 bytes; vftable 0x143182a88.
    class Vector_object : public Instances::fl::Object
    {
    public:
        // @0x142557460
        void AS3concat(Value& result, unsigned, const Value*);
        // @0x142557530
        void AS3every(bool& result, const Value&, const Value&);
        // @0x1425575f0
        void AS3filter(SPtr<Instances::fl_vec::Vector_object>& result, const Value&, const Value&);
        // @0x142557690
        void AS3forEach(const Value& result, const Value&, const Value&);
        // @0x1425577d0
        void AS3indexOf(SInt32& result, const Value&, SInt32);
        // @0x142557990
        void AS3join(ASString& result, const ASString&);
        // @0x142557b50
        void AS3lastIndexOf(SInt32& result, const Value&, SInt32);
        // @0x142557c90
        void AS3map(SPtr<Instances::fl_vec::Vector_object>& result, const Value&, const Value&);
        // @0x142557f30
        void AS3pop(Value& result);
        // @0x1425582a0
        void AS3push(Value& result, unsigned, const Value*);
        // @0x142558630
        void AS3reverse(SPtr<Instances::fl_vec::Vector_object>& result);
        // @0x1425589d0
        void AS3shift(Value& result);
        // @0x142558b80
        void AS3slice(Value& result, unsigned, const Value*);
        // @0x142558c50
        void AS3some(bool& result, const Value&, const Value&);
        // @0x142559040
        void AS3sort(SPtr<Instances::fl_vec::Vector_object>& result, const Value&);
        // @0x142559310
        void AS3splice(Value& result, unsigned, const Value*);
        // @0x142559470
        void AS3toLocaleString(ASString& result);
        // @0x142559650
        void AS3toString(ASString& result);
        // @0x142559890
        void AS3unshift(Value& result, unsigned, const Value*);
        // @0x142564c20
        void fixedGet(bool& result);
        // @0x142564c70
        void fixedSet(const Value& result, bool);
        // @0x142564cc0
        void lengthGet(UInt32& result);
        // @0x142564d40
        void lengthSet(const Value& result, UInt32);

    public:
        // (appended, sfr13) the vector object; bodies in sfr_as3_21 unless noted
        // @0x14255c220
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // @0x1425601d0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_vec::Vector_object"; }
        virtual CheckResult SetProperty(const Multiname& prop_name, const Value& value);   // 0x142563cd0
        virtual CheckResult GetProperty(const Multiname& prop_name, Value& value);         // 0x1425609f0
        virtual void GetDynamicProperty(AbsoluteIndex ind, Value& value);                   // 0x1425602a0
        virtual CheckResult DeleteProperty(const Multiname& prop_name);                     // 0x14255ba50
        virtual void AS3Constructor(unsigned argc, const Value* argv);                      // 0x1425572c0 (sfr_as3_20)
        virtual void GetNextPropertyName(Value& name, GlobalSlotIndex ind) const;           // 0x1425606c0
        virtual GlobalSlotIndex GetNextDynPropIndex(GlobalSlotIndex ind) const;             // 0x142560450

        VectorBase<Value > V;   // +0x38
    };

    // 0x70 bytes; vftable 0x143182170.
    class Vector_uint : public Instances::fl::Object
    {
    public:
        // @0x142557480
        void AS3concat(Value& result, unsigned, const Value*);
        // @0x142557560
        void AS3every(bool& result, const Value&, const Value&);
        // @0x142557610
        void AS3filter(SPtr<Instances::fl_vec::Vector_uint>& result, const Value&, const Value&);
        // @0x1425576b0
        void AS3forEach(const Value& result, const Value&, const Value&);
        // @0x142557860
        void AS3indexOf(SInt32& result, UInt32, SInt32);
        // @0x1425579e0
        void AS3join(ASString& result, const ASString&);
        // @0x142557be0
        void AS3lastIndexOf(SInt32& result, UInt32, SInt32);
        // @0x142557cb0
        void AS3map(SPtr<Instances::fl_vec::Vector_uint>& result, const Value&, const Value&);
        // @0x142558090
        void AS3pop(UInt32& result);
        // @0x142558340
        void AS3push(Value& result, unsigned, const Value*);
        // @0x142558700
        void AS3reverse(SPtr<Instances::fl_vec::Vector_uint>& result);
        // @0x142558a60
        void AS3shift(UInt32& result);
        // @0x142558ba0
        void AS3slice(Value& result, unsigned, const Value*);
        // @0x142558c80
        void AS3some(bool& result, const Value&, const Value&);
        // @0x142559180
        void AS3sort(SPtr<Instances::fl_vec::Vector_uint>& result, const Value&);
        // @0x142559330
        void AS3splice(Value& result, unsigned, const Value*);
        // @0x1425594d0
        void AS3toLocaleString(ASString& result);
        // @0x1425596b0
        void AS3toString(ASString& result);
        // @0x142559930
        void AS3unshift(Value& result, unsigned, const Value*);
        // @0x142564c30
        void fixedGet(bool& result);
        // @0x142564c80
        void fixedSet(const Value& result, bool);
        // @0x142564cd0
        void lengthGet(UInt32& result);
        // @0x142564d60
        void lengthSet(const Value& result, UInt32);

    public:
        // (appended, sfr13) the vector object; bodies in sfr_as3_21 unless noted
        // @0x142560210
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_vec::Vector_uint"; }
        virtual CheckResult SetProperty(const Multiname& prop_name, const Value& value);   // 0x142563db0
        virtual CheckResult GetProperty(const Multiname& prop_name, Value& value);         // 0x142560a80
        virtual void GetDynamicProperty(AbsoluteIndex ind, Value& value);                   // 0x1425602b0
        virtual CheckResult DeleteProperty(const Multiname& prop_name);                     // 0x14255baf0
        virtual void AS3Constructor(unsigned argc, const Value* argv);                      // 0x142557330 (sfr_as3_20)
        virtual void GetNextPropertyName(Value& name, GlobalSlotIndex ind) const;           // 0x142560750
        virtual GlobalSlotIndex GetNextDynPropIndex(GlobalSlotIndex ind) const;             // 0x1425604b0

        VectorBase<UInt32 > V;   // +0x38
    };

}}

}}} // namespace Scaleform::GFx::AS3

#endif
