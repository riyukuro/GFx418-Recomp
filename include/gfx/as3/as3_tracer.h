// Recovered Scaleform GFx 4.1.18 AS3: the byte code Tracer, which walks a method body block by block, types its
// operand stack / scope stack / registers (TR::State, as3_readargs.h) and writes the optimized word code. 0x140
// bytes, vftable 0x14317b938 (FlashUI: deleting destructor 0x1424e3b90, Output 0x14251bda0, OnOpCode 0x14251acb0).
// Layout from the constructor 0x1424d9f30 (sfr_as3_15) and the destructor 0x1424df070 (sfr_as3_16).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Units that define a local class Tracer of their own (sfr_as3_19) must not include this header.
#ifndef MS2_SF_GFX_AS3_TRACER_H
#define MS2_SF_GFX_AS3_TRACER_H

#include "ms2/scaleform/include/gfx/as3/as3_callframe.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace InstanceTraits { namespace fl { class Catch; } }

namespace TR {
class Block;
// Which part of a state MergeLists joins.
enum MergeSet { msOpStack, msScopeStack, msRegisterFile };
} // namespace TR

class Tracer : public FlashUI
{
public:
    // A jump argument to patch once the new opcode positions are known (0x10 bytes).
    struct Recalculate
    {
        Abc::TCodeOffset pos;   // +0x00
        int              base;  // +0x08
    };

    // The debugger state is sStep, NeedToCheck is copied from the VM's UI; the entry state is built from the method's
    // receiver and parameters. 0x1424d9f30
    Tracer(MemoryHeap* heap, const CallFrame& cf, ArrayLH_POD<UPInt, StatMV_VM_AbcFile_Mem>& wcode,
           Abc::MethodBodyInfo::Exception& wexception);
    virtual ~Tracer();                                                  // 0x1424df070

    // Forwards to the VM's UI. 0x14251bda0
    virtual void Output(OutputMessageType type, const char* msg);
    // false. 0x14251acb0
    virtual bool OnOpCode(Abc::TCodeOffset offset);

    Value::TraceNullType CanBeNull(const Value& value) const;                      // 0x1424ee9e0
    Value::TraceNullType CanBeNull(const InstanceTraits::Traits& traits) const;    // 0x1424eea80
    // The traits a traced value stands for (super: of its class rather than of an instance).
    const Traits* GetValueTraits(const Value& v, bool super_tr) const;             // 0x14250ff00
    bool IsNotRefCountedType(const Traits* tr) const;                             // 0x142514420
    bool IsNumericType(const Traits* tr) const;                                   // 0x142514510
    bool IsPrimitiveType(const Traits* tr) const;                                 // 0x142514a80
    // Whether a traced value is of the class's instance traits (GetValueTraits(v, false) compared).
    bool IsBooleanType(const Value& v) const;                                     // 0x142514000
    bool IsNumberType(const Value& v) const;                                      // 0x142514470
    bool IsSIntType(const Value& v) const;                                        // 0x142514c30
    bool IsStringType(const Value& v) const;                                      // 0x142514e10
    bool IsUIntType(const Value& v) const;                                        // 0x1425150c0
    // (appended, sfb) SDK AS3_Tracer.h inline getters: the VM of the call frame's file and its builtin types.
    VM& GetVM() const                               { return CF.GetVM(); }
    InstanceTraits::Traits& GetBooleanType() const  { return GetVM().GetClassTraitsBoolean().GetInstanceTraits(); }
    InstanceTraits::Traits& GetNumberType() const   { return GetVM().GetClassTraitsNumber().GetInstanceTraits(); }
    InstanceTraits::Traits& GetSIntType() const     { return GetVM().GetClassTraitsSInt().GetInstanceTraits(); }
    InstanceTraits::Traits& GetUIntType() const     { return GetVM().GetClassTraitsUInt().GetInstanceTraits(); }
    InstanceTraits::Traits& GetStringType() const   { return GetVM().GetClassTraitsString().GetInstanceTraits(); }
    InstanceTraits::Traits& GetVoidType() const     { return GetVM().GetITraitsVoid(); }

    // (appended, sfr24) no exe names; public so that TR::State and VMAbcFile can call them.
    // Traces every block of the method body, then writes the word code. 0x1424f7840
    void EmitCode();
    // Whether tr is the Object instance traits or the Class class's (any type passes).
    bool IsAnyType(const Traits* tr) const;                                       // 0x142513f50
    // The entry state of a block reached for the first time: from's stacks and registers copied.
    void InitializeBlock(TR::Block& to, const TR::Block& from);                   // 0x142511b00
    CheckResult MergeBlock(TR::Block& to, const TR::Block& from);                 // 0x142516c40
    CheckResult MergeValues(UPInt ind, TR::State& to, const TR::State& from, TR::MergeSet ms); // 0x1425178e0
    // The saved scope's first entry when the call frame has one, the state's register 0 otherwise.
    Value GetGlobalObject(const TR::State& st) const;                            // 0x14250a490
    // Inside the byte code: the current offset, its new position (the word code's size) recorded.
    void RegisterOrigOpCode(Abc::TCodeOffset opcode_cp);                          // 0x1425212f0
    // The opcode's word code position recorded, then the opcode (and its arguments) written.
    void PushNewOpCode(Abc::Code::OpCode op);                                     // 0x14251f930
    void PushNewOpCode(Abc::Code::OpCode op, UPInt arg1);                         // 0x14251fb90
    void PushNewOpCode(Abc::Code::OpCode op, UPInt arg1, UPInt arg2);             // 0x14251fa10
    void PushNewOpCodeArg(UPInt code);                                            // 0x14251fcd0
    // The last written opcode dropped: the word code cut back to its recorded position.
    void PopNewOpCode();                                                          // 0x14251cc80
    // (appended, sfb) no exe names. The code of the last pushed value dropped when it has no side effects (a push
    // or a local get), else a pop emitted.
    void PopPrevValue();                                                          // 0x1424f9180
    // The push of the constant v emitted (ind: its constant pool index; pop: drop the last pushed value first);
    // false when v has no push opcode.
    bool PushConstValue(const Value& v, int ind, bool pop);                       // 0x1424f9060

private:
    int  GetNextU30(UPInt cp) const;                                              // 0x14250c1f0
    void JoinSNodesUpdateType(Value& to_be_merged, const Value& from, ClassTraits::Traits& tr) const;    // 0x142515840
    void JoinSNodesUpdateType(Value& to_be_merged, const Value& from, InstanceTraits::Traits& tr) const; // 0x142515930
    CheckResult MergeLists(TR::State& to, const TR::State& from, bool update, TR::MergeSet ms);         // 0x142517740
    void SkipOrigOpCode(UPInt& opcode_cp, UPInt new_cp);                          // 0x14252c7e0
    void TraceBlock(UPInt cp, const TR::Block& tr_block);                         // 0x142530220
    CheckResult UpdateBlock(UPInt bcp);                                           // 0x142531040

    // The List<TR::Block> sentinel: it points at itself while the list is empty.
    struct BlockList
    {
        TR::Block* pPrev;
        TR::Block* pNext;
    };

    bool                                        Done;               // +0x10
    MemoryHeap*                                 Heap;               // +0x18
    const CallFrame&                            CF;                 // +0x20
    ArrayLH_POD<UPInt, StatMV_VM_AbcFile_Mem>&  WCode;              // +0x28 the method body's word code (VMAbcFile)
    Abc::MethodBodyInfo::Exception&             WException;         // +0x30
    Abc::TCodeOffset                            CurrOffset;         // +0x38
    StringDataPtr                               BCode;              // +0x40 the method body's byte code
    const UInt8*                                pCode;              // +0x50 BCode's text
    UPInt                                       CodeEnd;            // +0x58 BCode's size
    UPInt                                       PrintOffset;        // +0x60 the VM's call stack depth - 1
    TR::Block*                                  CurrBlock;          // +0x68
    ArrayDH_POD<UPInt, StatMV_VM>               OrigOpcodePos;      // +0x70 (StatMV_VM proven for PosToRecalculate only)
    ArrayDH_POD<UPInt, StatMV_VM>               NewOpcodePos;       // +0x90
    ArrayDH_POD<Recalculate, StatMV_VM>         PosToRecalculate;   // +0xb0
    ArrayDH_POD<UPInt, StatMV_VM>               Orig2newPosMap;     // +0xd0 sized to the byte code by the constructor
    ArrayDH<TR::State*, StatMV_VM>              States;             // +0xf0 0x88 bytes each, on Heap
    BlockList                                   Blocks;             // +0x110
    ArrayDH<SPtr<InstanceTraits::fl::Catch>, StatMV_VM> CatchTraits; // +0x120
};
// The deleting destructor 0x1424e3b90 frees 0x140 bytes.
static_assert(sizeof(Tracer) == 0x140, "Tracer size");

}}} // Scaleform::GFx::AS3

#endif
