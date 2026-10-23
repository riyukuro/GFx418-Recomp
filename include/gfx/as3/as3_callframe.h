// Recovered Scaleform GFx 4.1.18 AS3: a call frame of the AS3 interpreter (0xa8 bytes), held in the VM's paged
// call stack (VM +0x098).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
// Layout from the copy constructor 0x1424d6900.
#ifndef MS2_SF_GFX_AS3_CALLFRAME_H
#define MS2_SF_GFX_AS3_CALLFRAME_H

#include "ms2/scaleform/include/gfx/as3/as3_obj.h"
#include "ms2/scaleform/include/gfx/gfx_asstring.h"

namespace Scaleform { namespace GFx { namespace AS3 {

class VMAbcFile;
class Traits;

class CallFrame
{
public:
    // Copies a frame; the copy is marked as such and its line/file debug position is reset (0x1424d6900).
    CallFrame(const CallFrame& other);

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

}}} // Scaleform::GFx::AS3

#endif
