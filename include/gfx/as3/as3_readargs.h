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
    Value* GetTopPtr() const { return pCurrent; }
    void   Release(UPInt n)  { pCurrent -= n; }

private:
    ValueStack();

    UPInt  Unk00;               // +0x00
    Value* pCurrent;            // +0x08
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
