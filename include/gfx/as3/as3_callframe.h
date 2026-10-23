// Recovered Scaleform GFx 4.1.18 AS3: a call frame of the AS3 interpreter (0xa8 bytes), held in the VM's paged
// call stack (VM +0x098).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
// Layout from the copy constructor 0x1424d6900.
#ifndef MS2_SF_GFX_AS3_CALLFRAME_H
#define MS2_SF_GFX_AS3_CALLFRAME_H

#include "ms2/scaleform/include/gfx/as3/as3_obj.h"
#include "ms2/scaleform/include/gfx/gfx_asstring.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/kernel/sf_timer.h"

// (appended, sfr22) ArrayPagedCC<CallFrame>::allocPage: makes sure page nb of the VM's call stack exists.
void FUN_142427560(void* stack, Scaleform::UPInt nb);

namespace Scaleform { namespace GFx { namespace AS3 {

class VMAbcFile;
class Traits;

class CallFrame
{
public:
    // Copies a frame; the copy is marked as such and its line/file debug position is reset (0x1424d6900).
    CallFrame(const CallFrame& other);
    // (appended, sfr22) a frame running method body mbi_ind of file: keeps the VM's operand stack position and
    // reserves the method's operand stack and registers. Only inlined (VM::AddFrame).
    CallFrame(bool discard_result, VMAbcFile& file, SInt32 mbi_ind, const ScopeStackType& saved_scope,
              const Traits& ot, const ASString& name, const Value& invoker, UInt64 start_ticks);
    // (appended, sfr22) 0x1424dde10
    ~CallFrame();

    // (appended, sfr22) fills the registers: this, then the arguments against the method's parameters. 0x14252b5a0
    void SetupRegisters(const Abc::MethodInfo& mi, const Value& _this, unsigned argc, const Value* argv);

    VM& GetVM() const { return pFile->GetVM(); }

    bool                             DiscardResult;       // +0x00
    bool                             ACopy;               // +0x01
    bool                             RegisteredFunction;  // +0x02
    UPInt                            ScopeStackBaseInd;   // +0x08
    const void*                      CP;                  // +0x10 current opcode position
    void*                            pRegisterFile;       // +0x18
    MemoryHeap*                      pHeap;               // +0x20
    VMAbcFile*                       pFile;               // +0x28
    SInt32                           MBIIndex;            // +0x30 method body info index
    const ScopeStackType*            pSavedScope;         // +0x38
    const Traits*                    OriginationTraits;   // +0x40
    ScopeStackType*                  pScopeStack;         // +0x48
    Value*                           PrevInitialStackPos; // +0x50
    SPtr<Instances::Namespace>       DefXMLNamespace;     // +0x58 default XML namespace
    Value*                           PrevFirstStackPos;   // +0x60
    UInt16                           PrevReservedNum;     // +0x68
    SPtr<ASStringNode>               Name;                // +0x70
    UInt32                           CurrFileInd;         // +0x78
    UInt32                           CurrLineNumber;      // +0x7c
    UInt64                           StartTicks;          // +0x80
    Value                            Invoker;             // +0x88 keeps the invoked function alive
};

// (appended, sfr22) the VM's call stack (VM +0x070): frames in pages of 64, then the default frame (VM +0x098).
struct CallFrameStack
{
    void PushBack(const CallFrame& cf)
    {
        const UPInt nb = Size >> 6;
        if (nb >= NumPages)
            FUN_142427560(this, nb);
        new (Pages[nb] + (Size & 0x3f)) CallFrame(cf);
        ++Size;
    }

    UPInt       Unk00;      // +0x00
    UPInt       Size;       // +0x08
    UPInt       NumPages;   // +0x10
    UPInt       MaxPages;   // +0x18
    CallFrame** Pages;      // +0x20
};

SF_INLINE CallFrame::CallFrame(bool discard_result, VMAbcFile& file, SInt32 mbi_ind, const ScopeStackType& saved_scope,
                               const Traits& ot, const ASString& name, const Value& invoker, UInt64 start_ticks)
    : DiscardResult(discard_result)
    , ACopy(false)
    , RegisteredFunction(false)
    , ScopeStackBaseInd(file.GetVM().ScopeStack.GetSize())
    , CP(NULL)
    , pRegisterFile(file.GetVM().RegisterFile)
    , pHeap(file.GetVM().MHeap)
    , pFile(&file)
    , MBIIndex(mbi_ind)
    , pSavedScope(&saved_scope)
    , OriginationTraits(&ot)
    , pScopeStack(&file.GetVM().ScopeStack)
    , DefXMLNamespace(NULL)
    , Name(name.GetNode())
    , CurrFileInd(0)
    , CurrLineNumber(0)
    , StartTicks(start_ticks)
    , Invoker(invoker)
{
    ValueStack& os = *reinterpret_cast<ValueStack*>(file.GetVM().OpStack);
    PrevInitialStackPos = os.pCurrent;
    PrevReservedNum = os.ReservedNum;
    PrevFirstStackPos = os.pStack;
    const Abc::MethodBodyInfo& mbi = *pFile->GetAbcFile().MethodBodies.Info[MBIIndex];
    os.Reserve(static_cast<UInt16>(mbi.max_stack + 1));
    static_cast<ValueRegisterFile*>(pRegisterFile)->Reserve(static_cast<UInt16>(mbi.local_reg_count));
}

SF_INLINE void VM::AddFrame(const Value& invoker, VMAbcFile& file, SInt32 mbi_ind, const Value& _this, unsigned argc,
                            const Value* argv, bool discard_result, const ScopeStackType& saved_scope, const Traits& ot,
                            const ASString& name)
{
    if (Unk070[1] == 128)
    {
        ThrowError(Error(eStackOverflowError, *this));
        return;
    }

    CallFrame cf(discard_result, file, mbi_ind, saved_scope, ot, name, invoker, Timer::GetProfileTicks());
    const Abc::File& abc = file.GetAbcFile();
    cf.SetupRegisters(*abc.Methods.Info[abc.MethodBodies.Info[mbi_ind]->method_info_ind], _this, argc, argv);
    if (IsException())
        cf.ACopy = true;
    else
        reinterpret_cast<CallFrameStack*>(Unk070)->PushBack(cf);
}

}}} // Scaleform::GFx::AS3

#endif
