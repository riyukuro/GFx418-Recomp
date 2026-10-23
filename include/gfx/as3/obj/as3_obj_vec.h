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
        void AS3sort(Value& result, unsigned argc, const Value* argv);
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

    public:
        // (appended, sfr16) inlined into InstanceTraits::fl_vec::Vector_String::MakeInstanceS
        explicit Vector_String(InstanceTraits::Traits& t) : Instances::fl::Object(t)
            , V(t.GetVM().GetMemoryHeap(), t.GetVM()) {}
        // (appended, sfr19) other's elements appended (unless fixed); v appended (unless fixed). Bodies in sfr_as3_21
        void Append(const Vector_String& other);   // 0x142559c00
        void PushBack(ASStringNode* v); // 0x1425621c0
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
        void AS3sort(Value& result, unsigned argc, const Value* argv);
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

    public:
        // (appended, sfr16) inlined into InstanceTraits::fl_vec::Vector_double::MakeInstanceS
        explicit Vector_double(InstanceTraits::Traits& t) : Instances::fl::Object(t)
            , V(t.GetVM().GetMemoryHeap(), t.GetVM()) {}
        // (appended, sfr19) other's elements appended (unless fixed); v appended (unless fixed). Bodies in sfr_as3_21
        void Append(const Vector_double& other);   // 0x142559cd0
        void PushBack(Value::Number v); // 0x142562280
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
        void AS3sort(Value& result, unsigned argc, const Value* argv);
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

    public:
        // (appended, sfr16) inlined into InstanceTraits::fl_vec::Vector_int::MakeInstanceS
        explicit Vector_int(InstanceTraits::Traits& t) : Instances::fl::Object(t)
            , V(t.GetVM().GetMemoryHeap(), t.GetVM()) {}
        // (appended, sfr19) other's elements appended (unless fixed); v appended (unless fixed). Bodies in sfr_as3_21
        void Append(const Vector_int& other);   // 0x142559dc0
        void PushBack(SInt32 v);      // 0x142562340
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
        void AS3sort(Value& result, unsigned argc, const Value* argv);
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

    public:
        // (appended, sfr16) inlined into InstanceTraits::fl_vec::Vector_object::MakeInstanceS
        explicit Vector_object(InstanceTraits::Traits& t) : Instances::fl::Object(t)
            , V(t.GetVM().GetMemoryHeap(), t.GetVM()) {}
        // (appended, sfr19) other's elements appended (unless fixed); v appended (unless fixed). Bodies in sfr_as3_21
        void Append(const Vector_object& other);   // 0x142559eb0
        void PushBack(const Value& v); // 0x1425623f0
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
        void AS3sort(Value& result, unsigned argc, const Value* argv);
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

    public:
        // (appended, sfr16) inlined into InstanceTraits::fl_vec::Vector_uint::MakeInstanceS
        explicit Vector_uint(InstanceTraits::Traits& t) : Instances::fl::Object(t)
            , V(t.GetVM().GetMemoryHeap(), t.GetVM()) {}
        // (appended, sfr19) other's elements appended (unless fixed); v appended (unless fixed). Bodies in sfr_as3_21
        void Append(const Vector_uint& other);   // 0x142559fc0
        void PushBack(UInt32 v);      // 0x142562470
    };

}}

// (appended, sfr16) the instance traits of Vector.<T>; MakeInstanceS/MakeObject bodies in sfr_as3_21, ctors in
// sfr_as3_20 (sfr19). Typed vectors are array-like CTraits of 0x70-byte instances; Vector.<Object> instances carry
// their own name (RTraits), one traits object per element type.
namespace InstanceTraits { namespace fl_vec {
    // vftable 0x143182858.
    class Vector_String : public CTraits
    {
    public:
        typedef Instances::fl_vec::Vector_String InstanceType;

        Vector_String(VM& vm, const ClassInfo& ci);                // 0x142554ec0
        static Pickable<InstanceType> MakeInstance(Vector_String& t)
        {
            return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
        }
        // @0x142560100
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl_vec::Vector_String"; }
        SPtr<InstanceType> MakeInstanceS(Vector_String& t);
        virtual void MakeObject(Value& result, Traits& t);
    };

    // vftable 0x143182558.
    class Vector_double : public CTraits
    {
    public:
        typedef Instances::fl_vec::Vector_double InstanceType;

        Vector_double(VM& vm, const ClassInfo& ci);                // 0x142555080
        static Pickable<InstanceType> MakeInstance(Vector_double& t)
        {
            return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
        }
        // @0x142560140
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl_vec::Vector_double"; }
        SPtr<InstanceType> MakeInstanceS(Vector_double& t);
        virtual void MakeObject(Value& result, Traits& t);
    };

    // vftable 0x143181f20.
    class Vector_int : public CTraits
    {
    public:
        typedef Instances::fl_vec::Vector_int InstanceType;

        Vector_int(VM& vm, const ClassInfo& ci);                // 0x142555240
        static Pickable<InstanceType> MakeInstance(Vector_int& t)
        {
            return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
        }
        // @0x142560180
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl_vec::Vector_int"; }
        SPtr<InstanceType> MakeInstanceS(Vector_int& t);
        virtual void MakeObject(Value& result, Traits& t);
    };

    // vftable 0x143182b58.
    class Vector_object : public RTraits
    {
    public:
        typedef Instances::fl_vec::Vector_object InstanceType;
        enum { ThunkInfoNum = 23 };

        Vector_object(VM& vm, const ASString& n, Pickable<Instances::Namespace> ns, const Traits* pt, bool isDynamic,
            bool isFinal);                                      // 0x1425554d0
        static Pickable<InstanceType> MakeInstance(Vector_object& t)
        {
            return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
        }
        // @0x1425601c0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Vector_object"; }
        SPtr<InstanceType> MakeInstanceS(Vector_object& t);
        virtual void MakeObject(Value& result, Traits& t);
    };

    // vftable 0x143182238.
    class Vector_uint : public CTraits
    {
    public:
        typedef Instances::fl_vec::Vector_uint InstanceType;

        Vector_uint(VM& vm, const ClassInfo& ci);                // 0x1425556f0
        static Pickable<InstanceType> MakeInstance(Vector_uint& t)
        {
            return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
        }
        // @0x142560200
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Vector_uint"; }
        SPtr<InstanceType> MakeInstanceS(Vector_uint& t);
        virtual void MakeObject(Value& result, Traits& t);
    };
}}

namespace Classes { namespace fl_vec {
    class Vector_String; class Vector_double; class Vector_int; class Vector_object; class Vector_uint;
}}

// (appended, sfr19) the class traits of Vector and Vector.<T>: each makes its instance traits and class object.
// Ctors and MakeClassTraits in sfr_as3_20.
namespace ClassTraits { namespace fl_vec {
    // vftable 0x143181c40.
    class Vector : public Traits
    {
    public:
        Vector(VM& vm);                                         // 0x142554c80
        // @0x1425600c0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Vector"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);        // 0x142547420
    };

    // vftable 0x143182908.
    class Vector_String : public Traits
    {
    public:
        typedef InstanceTraits::fl_vec::Vector_String InstanceTraitsType;
        typedef Classes::fl_vec::Vector_String ClassType;

        Vector_String(VM& vm);                                     // 0x142554d90
        // @0x1425600e0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Vector_String"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);        // 0x142547040
    };

    // vftable 0x143182608.
    class Vector_double : public Traits
    {
    public:
        typedef InstanceTraits::fl_vec::Vector_double InstanceTraitsType;
        typedef Classes::fl_vec::Vector_double ClassType;

        Vector_double(VM& vm);                                     // 0x142554f50
        // @0x142560120
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Vector_double"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);        // 0x142546ef0
    };

    // vftable 0x143181fd0.
    class Vector_int : public Traits
    {
    public:
        typedef InstanceTraits::fl_vec::Vector_int InstanceTraitsType;
        typedef Classes::fl_vec::Vector_int ClassType;

        Vector_int(VM& vm);                                     // 0x142555110
        // @0x142560160
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Vector_int"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);        // 0x142546c50
    };

    // A Vector.<T> of objects; the element type is EnclosedClassTraits (NULL for Vector.<*>). 0xd0 bytes.
    // vftable 0x143182c00.
    class Vector_object : public Traits
    {
    public:
        typedef InstanceTraits::fl_vec::Vector_object InstanceTraitsType;
        typedef Classes::fl_vec::Vector_object ClassType;

        Vector_object(VM& vm);                                  // 0x1425552d0
        Vector_object(VM& vm, const ASString& n, const ClassTraits::Traits* ect);  // 0x142555310
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;             // 0x14255c1d0 (sfr_as3_21)
        // @0x1425601a0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::fl_vec::Vector_object"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);        // 0x142547190

        const ClassTraits::Traits& GetEnclosedClassTraits() const { return *EnclosedClassTraits; }

        SPtr<const ClassTraits::Traits> EnclosedClassTraits;    // +0xc8
    };

    // vftable 0x1431822e0.
    class Vector_uint : public Traits
    {
    public:
        typedef InstanceTraits::fl_vec::Vector_uint InstanceTraitsType;
        typedef Classes::fl_vec::Vector_uint ClassType;

        Vector_uint(VM& vm);                                     // 0x1425555c0
        // @0x1425601e0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Vector_uint"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);        // 0x142546da0
    };
}}

// (appended, sfr19) the class objects of Vector and Vector.<T>. 0x50 bytes. Ctors in sfr_as3_20, Call and
// ApplyTypeArgs in sfr_as3_21.
namespace Classes { namespace fl_vec {
    // vftable 0x143181cd0.
    class Vector : public Class
    {
    public:
        Vector(ClassTraits::Traits& t);                         // 0x142554d60
        // @0x1425600d0
        virtual const char* GetAS3ObjectType() const { return "Classes::fl_vec::Vector"; }
        virtual Class& ApplyTypeArgs(unsigned argc, const Value* argv);           // 0x14255a5c0
        // The class traits of Vector.<elem> for an element class without a builtin vector, made on first use.
        ClassTraits::Traits& Resolve2Vector(const ClassTraits::Traits& elem);       // 0x142563380
    };

    // vftable 0x1431829a0.
    class Vector_String : public Class
    {
    public:
        Vector_String(ClassTraits::Traits& t);                     // 0x142554e90
        // @0x1425600f0
        virtual const char* GetAS3ObjectType() const { return "Classes::Vector_String"; }
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);   // 0x14255a700
    };

    // vftable 0x1431826a0.
    class Vector_double : public Class
    {
    public:
        Vector_double(ClassTraits::Traits& t);                     // 0x142555050
        // @0x142560130
        virtual const char* GetAS3ObjectType() const { return "Classes::Vector_double"; }
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);   // 0x14255a8a0
    };

    // vftable 0x143182060.
    class Vector_int : public Class
    {
    public:
        Vector_int(ClassTraits::Traits& t);                     // 0x142555210
        // @0x142560170
        virtual const char* GetAS3ObjectType() const { return "Classes::Vector_int"; }
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);   // 0x14255aa40
    };

    // vftable 0x143182ca0.
    class Vector_object : public Class
    {
    public:
        Vector_object(ClassTraits::Traits& t);                     // 0x1425554a0
        // @0x1425601b0
        virtual const char* GetAS3ObjectType() const { return "Classes::Vector_object"; }
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);   // 0x14255abe0
    };

    // vftable 0x143182378.
    class Vector_uint : public Class
    {
    public:
        Vector_uint(ClassTraits::Traits& t);                     // 0x1425556c0
        // @0x1425601f0
        virtual const char* GetAS3ObjectType() const { return "Classes::Vector_uint"; }
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);   // 0x14255ad80
    };
}}

}}} // namespace Scaleform::GFx::AS3

#endif
