// Recovered Scaleform GFx 4.1.18 AS3 ABC (ActionScript byte code) file readers: the variable-length integer,
// double and string decoders the ABC parser and the interpreter use, and the parts of the constant pool and
// method body tables read from the exe so far. Our own declarations; bodies in sfr_as3_20 (0x1425452c0-).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AS3_ABC_H
#define MS2_SF_GFX_AS3_ABC_H

#include "ms2/scaleform/include/kernel/sf_string.h"

namespace Scaleform { namespace GFx { namespace AS3 { namespace Abc {

// u30: 7 bits per byte, low group first, high bit set while more bytes follow (at most 5 bytes).
template <typename T> int    ReadU30(const T*& p);                          // 0x1425455b0 <UInt8>
template <typename T> int    ReadU30(const T* data, UPInt& pos);            // 0x142545600 <UInt8>
// s24: three bytes little endian, sign-extended from bit 23.
template <typename T> int    ReadS24(const T* data, UPInt& pos);            // 0x1425454b0 <UInt8>
template <typename T> double ReadDouble(const T*& p);                       // 0x142545390 <UInt8>
template <typename T> String ReadString(const T*& p, UPInt size);           // 0x1425454f0 <UInt8>
template <typename T> String ReadString(const T* data, UPInt& pos, UPInt size); // 0x142545530 <UInt8>

// Bodies in sfr_as3_20 (instantiated there for UInt8); the other ABC units call them out of line.

// A namespace set: points at its u30 count followed by the namespace indices.
class NamespaceSetInfo
{
public:
    UPInt GetSize() const;                      // 0x1425452f0

    const UInt8* Data;                          // +0x00
};

// The constant pool. Partially recovered: only the double table pointer is known.
class ConstPool
{
public:
    // The double at index ind (1-based; 0 is NaN in the spec, 0.0 here as in the exe). 0x1425452c0
    double GetDouble(UPInt ind) const;

    void*        Unrecovered_00;                // +0x00
    const UInt8* ConstDouble;                   // +0x08 the doubles, 8 bytes each
};

}}}} // namespace Scaleform::GFx::AS3::Abc

#endif
