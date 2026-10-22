// Recovered Scaleform GFx 4.1.18 AS3 vector storage: the typed element arrays behind __AS3__.vec.Vector.<T>
// (Instances::fl_vec::Vector_int/uint/double/String/object keep one at +0x38). Our own declarations; bodies in
// sfr_as3_21 (0x142560220-0x142563240).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AS3_VEC_BASE_H
#define MS2_SF_GFX_AS3_VEC_BASE_H

#include "ms2/scaleform/include/kernel/sf_array.h"
#include "ms2/scaleform/include/gfx/as3/as3_value.h"
#include "ms2/scaleform/include/gfx/as3/as3_vm.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl { class Object; class Array; } }

// The element-type independent face of a vector: the AS3 code reads elements through it as Values.
// 0x18 bytes; vftable 0x143181db8.
class ArrayBase
{
public:
    ArrayBase(VM& vm) : Fixed(false), VMRef(vm) {}
    virtual ~ArrayBase() {}

    virtual UInt32 GetSize() const = 0;
    virtual void   GetValue(UInt32 ind, Value& v) const = 0;           // releases what v held
    virtual void   GetValueUnsafe(UInt32 ind, Value& v) const = 0;     // v holds nothing to release

    // The next index after ind for for..in (-1 past the end). 0x1425602c0
    AbsoluteIndex GetNextArrayIndex(AbsoluteIndex ind) const;

    // Throws the RangeError of a write that changes the length of a fixed vector.
    CheckResult CheckFixed() const
    {
        if (Fixed)
            VMRef.ThrowRangeError(VM::Error(VM::eVectorFixedError, VMRef, "Vector"));
        return !Fixed;
    }

    // The elements converted to strings and joined with sep (null/undefined give ""). 0x142564220
    ASString Join(const ASString& sep) const;
    // Vector.some: calls callback(element, index, owner) on thisObject until one returns true. 0x142563ee0
    bool Some(const Value& callback, const Value& thisObject, Instances::fl::Object* owner) const;
    // TypeError 1034 unless v is callable. 0x14255af20
    CheckResult CheckCallable(const Value& v) const;
    // v coerced to tr into result; TypeError 1034 when it cannot be. 0x14255afd0
    CheckResult CheckCoerce(const ClassTraits::Traits& tr, const Value& v, Value& result) const;
    // TypeError 1034 ("arguments") unless every argv is of type tr. 0x14255b1d0
    CheckResult CheckArgTypes(unsigned argc, const Value* argv, const ClassTraits::Traits& tr) const;
    // (appended, sfr16) whether every element of arr is of type tr. 0x1425614e0
    CheckResult OfCorrectType(const Instances::fl::Array& arr, const ClassTraits::Traits& tr) const;

protected:
    virtual void   PushBackValueUnsafe(const Value& v) = 0;

public:
    bool    Fixed;      // +0x08 the AS3 'fixed' flag: the length cannot change
    VM&     VMRef;      // +0x10
};

// 0x38 bytes. vftables: SInt32 0x143181e30, UInt32 0x143182148, Number 0x143182460,
// Ptr<ASStringNode> 0x143181e08, Value 0x143181de0.
template <typename T>
class VectorBase : public ArrayBase
{
public:
    typedef ArrayDH<T> ValuesType;

    VectorBase(VM& vm) : ArrayBase(vm), V(vm.GetMemoryHeap()) {}
    VectorBase(MemoryHeap* heap, VM& vm) : ArrayBase(vm), V(heap) {}

    // bodies (one per element type) in sfr_as3_21
    virtual UInt32 GetSize() const;
    virtual void   GetValue(UInt32 ind, Value& v) const;
    virtual void   GetValueUnsafe(UInt32 ind, Value& v) const;

    // Appends v's payload as the element type; the caller has already coerced v to it.
    void PushBackUnsafe(const Value& v);
    // The AS3 length setter: new elements get the type's default (0, null).
    CheckResult Resize(UInt32 size);
    // Vector.unshift: argv (already of the element type tr) are inserted at the front.
    // SInt32 0x142564390, UInt32 0x1425644f0, Number 0x142564650, String 0x142564860, Value 0x1425649c0
    void Unshift(unsigned argc, const Value* argv, const ClassTraits::Traits& tr);
    // Element write: v is coerced to the element type tr (throws on failure); ind == size appends unless fixed.
    // SInt32 0x142563720, UInt32 0x142446540, Number 0x1424864c0, String 0x1425638c0, Value 0x142563a00
    CheckResult Set(UInt32 ind, const Value& v, const ClassTraits::Traits& tr);
    // (appended, sfr16) Vector.splice: argv inserted at pos, unchecked. Value 0x142560d70
    void Insert(UPInt pos, unsigned argc, const Value* argv);

protected:
    virtual void   PushBackValueUnsafe(const Value& v);

public:
    ValuesType  V;      // +0x18
};

// A property name that is an array index ("3", 3u, 3.0) -> ind. 0x142510800
CheckResult GetVectorInd(const Multiname& prop_name, UInt32& ind);

}}} // namespace Scaleform::GFx::AS3

#endif
