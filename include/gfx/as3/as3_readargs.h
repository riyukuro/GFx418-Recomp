// ReadArgs: the arguments of a call popped off an operand stack, the first eight in place, more in a heap array.
// The interpreter reads them off the VM's value stack (0x1424d9530); the tracer reads them off its state's operand
// stack (TR::ReadArgs 0x1424d9640). Only what the two constructors touch is modeled.
#ifndef MS2_SCALEFORM_GFX_AS3_AS3_READARGS_H
#define MS2_SCALEFORM_GFX_AS3_AS3_READARGS_H

#include "ms2/scaleform/include/gfx/as3/as3_vm.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// The VM's operand stack (VM +0x48): pCurrent points at the topmost value. Not modeled past that.
class ValueStack
{
public:
    // (appended, sfr19) one block of stack values: a header then PageSize values. 0x48 + (PageSize - 1) * 0x20 bytes.
    struct Page
    {
        UInt16      ReservationNum;     // +0x00
        UInt16      PageSize;           // +0x02 values in the page
        Value*      pFirst;             // +0x08
        Value*      pCurrent;           // +0x10
        Page*       pNext;              // +0x18
        Page*       pPrev;              // +0x20
        Value       Values[1];          // +0x28
    };

    Value* GetTopPtr() const { return pCurrent; }
    void   Release(UPInt n)  { pCurrent -= n; }

private:
    ValueStack();

    // (appended, sfr19) a new page of at least 64 values (global heap). 0x1424eb6b0
    Page* AllocPage(UInt16 pageSize);
    // (appended, sfr19) a reserved page of at least pageSize values, else a new one. 0x1425182a0
    Page* NewPage(UInt16 pageSize);

    UPInt  Unk00;               // +0x00
    Value* pCurrent;            // +0x08
    UPInt  Unk10[2];            // +0x10 (not modeled)
    Page*  pReserved;           // +0x20 (appended, sfr19) released pages, kept for reuse
};

// (appended, sfr19) the register files of the call frames: pages of values, each followed by the sizes of the
// register sets reserved in it. Only what AllocPage touches is modeled.
class ValueRegisterFile
{
public:
    // (appended, sfr19) releases the num registers of the innermost reservation; a page left empty goes back to
    // the reserved list. 0x142521fb0
    void ReleaseReserved(UInt16 num);

    struct Page
    {
        UInt16      CurrPos;            // +0x00
        UInt16      PageSize;           // +0x02 values in the page
        UInt16      ReservedNum;        // +0x04
        Value*      pCurrent;           // +0x08
        Page*       pNext;              // +0x10
        Page*       pPrev;              // +0x18
        Value       Values[1];          // +0x20 then PageSize UInt16 reservation sizes
    };

private:
    ValueRegisterFile();

    // A new page of a multiple of 64 values (at least the largest so far; global heap). 0x1424eb640
    Page* AllocPage(UInt16 pageSize);
    // (appended, sfr19) a reserved page of at least pageSize values, else a new one. 0x1425181c0
    Page* NewPage(UInt16 pageSize);

    // (appended, sfr19) the sizes of the register sets reserved in page p, after its values.
    static UInt16* GetReservations(Page* p) { return reinterpret_cast<UInt16*>(p->Values + p->PageSize); }

    UInt16      Unk00;                  // +0x00 registers reserved in the current page
    UInt16      Unk02;                  // +0x02 the largest page on the reserved list
    UInt16      MaxAllocatedPageSize;   // +0x04
    Value*      pRF;                    // +0x08 (appended, sfr19) the innermost register set
    Page*       pCurrentPage;           // +0x10
    Page*       pReservedPage;          // +0x18 released pages, kept for reuse
};

// 0x138 bytes.
class ReadArgs
{
public:
    ReadArgs(VM& vm, UInt32 argCount);  // 0x1424d9530

protected:
    VM&                 VMRef;          // +0x000
    ValueStack&         OpStack;        // +0x008
    UInt32              ArgNum;         // +0x010
    Value               FixedArgs[8];   // +0x018
    ArrayDH<Value>      CallArgs;       // +0x118 (vm's heap)
};

namespace TR {

// One state of the byte code tracer. Only its operand stack is modeled.
class State
{
public:
    ArrayDH<Value>& GetOpStack() { return OpStack; }
    Value::TraceNullType CanBeNull(const InstanceTraits::Traits& traits) const; // 0x1424ee980
    InstanceTraits::Traits& GetFunctType(const Value& value) const; // 0x14250a1b0

private:
    State();

    UPInt               Unk00[7];       // +0x00
    ArrayDH<Value>      OpStack;        // +0x38
};

// 0x140 bytes.
class ReadArgs
{
public:
    ReadArgs(VM& vm, State& s, UInt32 argCount);  // 0x1424d9640

protected:
    VM&                 VMRef;          // +0x000
    State&              StateRef;       // +0x008
    UInt32              ReadNum;        // +0x010 values read so far
    UInt32              ArgNum;         // +0x018
    Value               FixedArgs[8];   // +0x020
    ArrayDH<Value>      CallArgs;       // +0x120 (vm's heap)
};

} // namespace TR

}}} // Scaleform::GFx::AS3

#endif
