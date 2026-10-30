// ReadArgs: the arguments of a call popped off an operand stack, the first eight in place, more in a heap array.
// The interpreter reads them off the VM's value stack (0x1424d9530); the tracer reads them off its state's operand
// stack (TR::ReadArgs 0x1424d9640). Only what the two constructors touch is modeled.
#ifndef MS2_SCALEFORM_GFX_AS3_AS3_READARGS_H
#define MS2_SCALEFORM_GFX_AS3_AS3_READARGS_H

#include "ms2/scaleform/include/gfx/as3/as3_vm.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"    // (sfr24) Abc::Code::OpCode

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
    // (appended, sfr24) a copy of v on top; the caller has reserved the room (0x14241e4f0, from a function object).
    void   PushBack(const Value& v) { ++pCurrent; ::new (pCurrent) Value(v); }
    // (appended, sfr24) the operand stack of vm, which as3_vm.h keeps as raw words (VM +0x48).
    static ValueStack& Of(VM& vm) { return *reinterpret_cast<ValueStack*>(&vm.OpStack); }

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

// (appended, sfr24) operands of an opcode read off the VM's operand stack: {VM*, operand stack*} (sfr_as3_18 0x1425201f0
// reads its this as such). The leading two members of ReadArgs have the same layout.
class StackReader
{
public:
    StackReader(VM& vm) : VMRef(vm), OpStack(ValueStack::Of(vm)) {}

    // throws a TypeError (null / undefined to object) when v, about to be used as an object, is null or undefined.
    void CheckObject(const Value& v) const;     // 0x1424ef180
    // the run-time parts of obj (name, then namespace) off the operand stack.
    void Read(Multiname& obj);                  // 0x1425201f0

    VM&         GetVM() const      { return VMRef; }
    ValueStack& GetOpStack() const { return OpStack; }

protected:
    VM&         VMRef;          // +0x00
    ValueStack& OpStack;        // +0x08
};
static_assert(sizeof(StackReader) == 0x10, "StackReader size");

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
    // Tracer result typing: the operand stack top (or a register) becomes a value of a builtin type.
    void TopNumber();                       // 0x142532670
    void TopInt();                          // 0x142532710
    void TopString();                       // 0x1425327b0
    void Pop2Boolean();                     // 0x142532850
    void Pop2Number();                      // 0x142532930
    void Pop2Int();                         // 0x142532a10
    void Pop2UInt();                        // 0x142532af0
    void RegNumber(UInt32 ind);             // 0x142537c50
    void RegInt(UInt32 ind);                // 0x142537ce0
    void RegUInt(UInt32 ind);               // 0x142537d70
    // (sfr24) operand stack pops: drop the top n values; take the top value out.
    void  PopOp(UPInt n);                   // 0x14251ccc0
    Value PopOpValue();                     // 0x14251cd30
    // (sfr24) the operand stack top (or register ind) becomes a value of type tr, null or not as nt says.
    void ConvertOpTo(InstanceTraits::Traits& tr, Value::TraceNullType nt);                          // 0x1424f1e50
    // (sfb) callers pass a sign-extended index (RefineOpCodeReg1: movsxd); the body indexes with its low 32 bits.
    void ConvertRegisterTo(SPInt ind, InstanceTraits::Traits& tr, Value::TraceNullType nt);         // 0x1424f1ed0
    // (appended, sfr24) where FindProp found the property.
    enum ScopeType { stScopeStack, stStoredScope, stGlobalObject };

private:
    State();
    void MarkChanged(UInt32 ind) { RegChanged[ind >> 3] = static_cast<UInt8>(RegChanged[ind >> 3] | (1u << (ind & 7))); }

    // (appended, sfr24) private in the exe (A-mangled). The traits of a traced value.
    const Traits* GetValueTraits(const Value& v) const;                                       // 0x14250fe80
    // (appended, sfr24) the last emitted opcode becomes op when the operand (stack top / top two / register reg_num)
    // already has type's traits; else the value left (stack top / register) is converted to type.
    void RefineOpCodeStack1(InstanceTraits::Traits& type, Abc::Code::OpCode op);              // 0x142520e60
    void RefineOpCodeStack2(InstanceTraits::Traits& type, Abc::Code::OpCode op);              // 0x142520f30
    void RefineOpCodeReg1(InstanceTraits::Traits& type, Abc::Code::OpCode op, int reg_num);   // 0x142520d80
    // (appended, sfr24) traces one opcode at bcp (the tracer's opcode switch).
    void exec_opcode(const Abc::Code::OpCode opcode, Abc::TCodeOffset& bcp);                  // 0x14253d520
    // (appended, sfr24) looks mn up in the scope stack, then the saved scope, then the global object.
    void FindProp(PropRef& result, const Multiname& mn, ScopeType& stype, UPInt& scope_index);  // 0x142501e80
    // (appended, sfr24) the traced type of slot si of obj_traits (a method's function type, a slot's data type).
    CheckResult GetPropertyType(const Traits* obj_traits, const SlotInfo& si, Value& type) const;   // 0x14250cf20

    // (sfr24) one bit per register, from the method body's local_reg_count (Tracer heap, StatMV_VM_Tracer_Mem)
    struct RegisterBits
    {
        UInt8*   Data;      // +0x00
        UInt32   BitCount;  // +0x08

        UInt8&       operator[](UPInt i)       { return Data[i]; }
        const UInt8& operator[](UPInt i) const { return Data[i]; }
    };

    void*               pTracer;        // +0x00 the owning Tracer (as3_tracer.h)
    Abc::TCodeOffset    BCP;            // +0x08 (sfr24) the constructor 0x1424d9be0 sets both to its code offset
    Abc::TCodeOffset    OpcodeCP;       // +0x10
    ArrayDH<Value>      Registers;      // +0x18
    ArrayDH<Value>      OpStack;        // +0x38
    ArrayDH<Value>      ScopeStack;     // +0x58
    RegisterBits        RegChanged;     // +0x78 one bit per register (RegistersAlive)
};
// (sfr24) the Tracer allocates its states with 0x88 bytes (0x1424d9f30) and frees them in ~Tracer 0x1424df070.
static_assert(sizeof(State) == 0x88, "TR::State size");

// (appended, sfr24) the tracer's operand readers. Their constructors are inlined in the tracer; only the destructors of
// three of them are out of line (member order and sizes from those: ReadValue 0x1424dedc0, ReadMnObject 0x1424ded40,
// ReadValueMnObject 0x1424dee30). TR::ReadArgs below starts with the same three members.
class StackReader
{
public:
    StackReader(VM& vm, State& s) : VMRef(vm), StateRef(s), Num(0) {}

    VM&    GetVM() const    { return VMRef; }
    State& GetState() const { return StateRef; }

protected:
    VM&    VMRef;       // +0x00
    State& StateRef;    // +0x08
    int    Num;         // +0x10 values read so far
};

// the file the multiname indices refer to.
class MnReader
{
public:
    MnReader(VMAbcFile& file) : File(file) {}
    VMAbcFile& GetFile() const { return File; }

private:
    VMAbcFile& File;
};

struct ReadMn : public StackReader, public MnReader
{
    Multiname ArgMN;            // +0x20
};

struct ReadMnObject : public ReadMn
{
    ~ReadMnObject();            // 0x1424ded40
    Value ArgObject;            // +0x50
};
static_assert(sizeof(ReadMnObject) == 0x70, "TR::ReadMnObject size");

struct ReadValue : public StackReader
{
    ~ReadValue();               // 0x1424dedc0
    const Value ArgValue;       // +0x18
};
static_assert(sizeof(ReadValue) == 0x38, "TR::ReadValue size");

struct ReadValueMn : public ReadValue, public MnReader
{
    Multiname ArgMN;            // +0x40
};

struct ReadValueMnObject : public ReadValueMn
{
    ~ReadValueMnObject();       // 0x1424dee30
    Value ArgObject;            // +0x70
};
static_assert(sizeof(ReadValueMnObject) == 0x90, "TR::ReadValueMnObject size");

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
    UInt32              ReadNumPad;     // +0x014 (sfr24) the exe's ArgNum is at +0x18 (ctor 0x1424d9660): a StackReader
                                        // base's tail padding there, kept flat so the ctor's initializers stay as written
    UInt32              ArgNum;         // +0x018
    Value               FixedArgs[8];   // +0x020
    ArrayDH<Value>      CallArgs;       // +0x120 (vm's heap)
};
static_assert(sizeof(ReadArgs) == 0x140, "TR::ReadArgs size");

} // namespace TR

}}} // Scaleform::GFx::AS3

#endif
