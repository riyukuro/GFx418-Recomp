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
    friend class VM;    // (appended, sfr19) the VM constructor builds its operand stack in place
    friend class CallFrame; // (appended, sfr22) a new frame keeps the stack position and reserves its values
    friend class Value;     // (appended, sfr22) Value::Pick moves the top value out
    ValueStack();

    // (appended, sfr19) a new page of at least 64 values (global heap). 0x1424eb6b0
    Page* AllocPage(UInt16 pageSize);
    // (appended, sfr19) a reserved page of at least pageSize values, else a new one. 0x1425182a0
    Page* NewPage(UInt16 pageSize);

    // (appended, sfr19) makes room for n more values, moving to a new page when the current one is full. 0x1425241f0
    void Reserve(UInt16 n);

    UInt16 ReservedNum;         // +0x00 (sfr19) values reserved by the last Reserve
    Value* pCurrent;            // +0x08
    Value* pStack;              // +0x10 (sfr19) the bottom of the current reservation
    Page*  pCurrentPage;        // +0x18 (sfr19)
    Page*  pReserved;           // +0x20 (appended, sfr19) released pages, kept for reuse
};

// (appended, sfr22) moves the top value of the stack into this one and pops it. Only inlined
// (Instances::Function::ExecuteUnsafe 0x14240ac30).
SF_INLINE void Value::Pick(ValueStack& v)
{
    Release();
    const Value& top = *v.pCurrent;
    Flags = top.Flags;
    Bonus = top.Bonus;
    value = top.value;
    --v.pCurrent;
}

// (appended, sfr19) the register files of the call frames: pages of values, each followed by the sizes of the
// register sets reserved in it. Only what AllocPage touches is modeled.
class ValueRegisterFile
{
public:
    // (appended, sfr19) releases the num registers of the innermost reservation; a page left empty goes back to
    // the reserved list. 0x142521fb0
    void ReleaseReserved(UInt16 num);
    // (appended, sfr22) reserves the num registers of a new call frame. 0x1425240e0
    void Reserve(UInt16 num);

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
    friend class VM;    // (appended, sfr19) the VM constructor builds its register file in place
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
    ~ReadArgs();                       // 0x1424de9e0

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
    void SetRegister(AbsoluteIndex ind, const Value& v);            // 0x142528e20

    // Handlers that need no Tracer model (sfr27).
    void SetLocal0();                       // 0x14253fde0
    void SetLocal1();                       // 0x14253fe30
    void SetLocal2();                       // 0x14253fe80
    void SetLocal3();                       // 0x14253fed0
    void SetLocalN(UInt32 ind);             // 0x14253ff20
    void PushScope();                       // 0x14253f4a0
    void PushByte(UInt32 arg);              // 0x14253f2f0
    void PushShort(SInt32 arg);             // 0x14253f640
    void PushInt(SInt32 ind);               // 0x14253f3b0
    void PushUInt(SInt32 ind);              // 0x14253f770
    void PushDouble(SInt32 ind);            // 0x14253f340
    void PushObject(UInt32 arg);            // 0x1425395f0
    void PushObject2(UInt32 arg);           // 0x14253c1a0
    void PushFunction(UInt32 arg);          // 0x14253c8b0
    void PushBoolean2(UInt32 a, UInt32 b);  // 0x14253a630
    void PushITraits(InstanceTraits::Traits* tr); // 0x142538f20
    void KillRegister(UInt32 ind);          // 0x14253bdf0

private:
    State();
    void MarkChanged(UInt32 ind) { RegChanged[ind >> 3] = static_cast<UInt8>(RegChanged[ind >> 3] | (1u << (ind & 7))); }

    void*               pTracer;        // +0x00 the owning Tracer
    UPInt               Unk08[2];       // +0x08
    ArrayDH<Value>      Registers;      // +0x18
    ArrayDH<Value>      OpStack;        // +0x38
    ArrayDH<Value>      ScopeStack;     // +0x58
    ArrayDH<UInt8>      RegChanged;     // +0x78 one bit per register
};

// 0x140 bytes.
class ReadArgs
{
public:
    ReadArgs(VM& vm, State& s, UInt32 argCount);  // 0x1424d9640
    ~ReadArgs();                                  // 0x1424dea90

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
