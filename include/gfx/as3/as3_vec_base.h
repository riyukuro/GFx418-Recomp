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

    // bodies (one per element type) in sfr_as3_21
    virtual UInt32 GetSize() const;
    virtual void   GetValue(UInt32 ind, Value& v) const;
    virtual void   GetValueUnsafe(UInt32 ind, Value& v) const;

    // Appends v's payload as the element type; the caller has already coerced v to it.
    void PushBackUnsafe(const Value& v);
    // The AS3 length setter: new elements get the type's default (0, null).
    CheckResult Resize(UInt32 size);

protected:
    virtual void   PushBackValueUnsafe(const Value& v);

public:
    ValuesType  V;      // +0x18
};

// A property name that is an array index ("3", 3u, 3.0) -> ind. 0x142510800
CheckResult GetVectorInd(const Multiname& prop_name, UInt32& ind);

}}} // namespace Scaleform::GFx::AS3

#endif
