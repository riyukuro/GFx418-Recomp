// AS3 leftovers in the sfr_as2_01 map range, between sfr_as3_19's pieces: MovieRoot::Shutdown and the tracer's
// skip over code no branch reaches.
// MS2-UNIT: sfr_as2_01f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14252c4f0-0x14252c7e0 .text$mn
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_moviedefrootnode.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"

// Bodies of the exe called here (not recovered yet), by their addresses.
void FUN_1424dd110(void* paliases);                                       // ~ASStringHash<Value> (the invoke aliases)
void FUN_142423b90(Scaleform::GFx::AS3::Value* v);                        // Value::SetUndefined
void FUN_1424ef380(void** pchains);                                       // EventChains::Clear
void FUN_1425245c0(Scaleform::UPInt* arr, Scaleform::UPInt n);            // ArrayLH<SPtr<DisplayObject>>::Resize
void FUN_142524b90(void* parr, void* pheapAddr, Scaleform::UPInt n);      // ArrayLH<SPtr<VMAbcFile>> resize
void FUN_142530d50(Scaleform::GFx::AS3::ASVM* pavm);                      // ASVM: drops the loaded ABC files
void FUN_14257dcd0(void* p);                                              // RefCountNTSImpl::Release

namespace Scaleform { namespace GFx { namespace AS3 {

// The movie goes away: the queued actions, the stage, the host's aliases and return value, the frame listeners, the
// mice, every movie's ABC files and at last the VM, with a collection between the steps.
// MS2-FUNCTIONAL the 4.1.18 ForceCollect (slot 9) takes no flags; called through the slot without one
// @0x14252c4f0
void MovieRoot::Shutdown()
{
    typedef void (*CollectFn)(MovieRoot*);
    pMovieImpl->ClearPlayList();
    ActionQueue.Clear();
    if (pStage)
        FUN_14257dcd0(pStage);
    pStage = NULL;
    (*reinterpret_cast<CollectFn const* const*>(this))[9](this);
    if (void* p = pInvokeAliases)
    {
        FUN_1424dd110(p);
        Memory::pGlobalHeap->Free(p);
    }
    pInvokeAliases = NULL;
    FUN_142423b90(&ExternalIntfRetVal);
    FUN_1424ef380(&mEventChains);
    for (unsigned i = 0; i < 4; ++i)
    {
        FUN_1425245c0(reinterpret_cast<UPInt*>(mMouseState[i].RolloverStack), 0);
        if (mMouseState[i].LastMouseOverObj)
            FUN_14257dcd0(mMouseState[i].LastMouseOverObj);
        mMouseState[i].LastMouseOverObj = NULL;
    }
    for (GFx::MovieDefRootNode* p = pMovieImpl->RootMovieDefNodes.pNext;
         p != static_cast<GFx::MovieDefRootNode*>(&pMovieImpl->RootMovieDefNodes); p = p->pNext)
    {
        MovieDefRootNode* pnode = static_cast<MovieDefRootNode*>(p);
        FUN_142524b90(&pnode->AbcFiles, &pnode->AbcFiles, 0);
    }
    (*reinterpret_cast<CollectFn const* const*>(this))[9](this);
    FUN_142530d50(pAVM);
    (*reinterpret_cast<CollectFn const* const*>(this))[9](this);
    if (pAVM)
    {
        if (OwnsAVM)
        {
            OwnsAVM = false;
            delete pAVM;
        }
        pAVM = NULL;
    }
    OwnsAVM = false;
}

}}} // namespace Scaleform::GFx::AS3

using namespace Scaleform;
using namespace Scaleform::GFx::AS3;

// The opcode table (sfr_as3_18; same struct name so it binds to the same symbol).
struct Sfr34_OpCodeInfo
{
    signed char   operandCount : 3;
    unsigned char canThrow : 1;
    unsigned char pop : 2;
    unsigned char push : 2;
    unsigned char pop_args : 1;
    unsigned char pop_mn : 1;
    const char*   name;
};
extern const Sfr34_OpCodeInfo DAT_14317fea0[0x100];

void FUN_142511b00(UPInt tracer, UPInt* now, UPInt* old);                 // Tracer: merge block states
char* FUN_142516c40(UPInt tracer, void* buf, UPInt* now, UPInt* old);     // Tracer: merge, result flag
void FUN_1425212f0(UPInt tracer, UPInt pos);                              // Tracer: per-opcode bookkeeping

// Tracer: while the current block is dead code, steps over its opcodes (operands included), entering each block that
// starts where it lands; stops at the end of the code or when a merge fails.
// MS2-FUNCTIONAL raw-offset model of the Tracer
// @0x14252c640
void FUN_14252c640(UPInt tracer, UPInt* pos)
{
    if (!(*reinterpret_cast<UInt8*>(*reinterpret_cast<UPInt*>(tracer + 0x68) + 0x14) & 1))
        return;
    do
    {
        if (*pos >= *reinterpret_cast<UPInt*>(tracer + 0x58))
            return;
        FUN_1425212f0(tracer, *pos);
        const UInt8* code = *reinterpret_cast<const UInt8**>(tracer + 0x50);
        const UInt8 op = code[*pos];
        ++*pos;
        if (op >= 0x0c && op <= 0x1a)
            Abc::ReadS24(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
        else if (op == 0x1b)
        {
            Abc::ReadS24(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
            int n = Abc::ReadU30(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
            for (int i = 0; i <= n; ++i)
                Abc::ReadS24(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
        }
        else if (op == 0x24)
            ++*pos;
        else if (op == 0xef)
        {
            ++*pos;
            Abc::ReadU30(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
            ++*pos;
            Abc::ReadU30(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
        }
        else
        {
            switch (DAT_14317fea0[op].operandCount)
            {
            case 2:
                Abc::ReadU30(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
            case 1:
                Abc::ReadU30(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
                break;
            }
        }
        UPInt* old = *reinterpret_cast<UPInt**>(tracer + 0x68);
        UPInt* blk = *reinterpret_cast<UPInt**>(tracer + 0x110);
        while (blk != NULL && *pos < blk[4])
            blk = reinterpret_cast<UPInt*>(*blk);
        if (blk != NULL && blk[4] == *pos)
        {
            *reinterpret_cast<UPInt**>(tracer + 0x68) = blk;
            if ((*reinterpret_cast<UInt8*>(blk + 2) & 1) == 0)
                FUN_142511b00(tracer, blk, old);
            else if (blk != old)
            {
                char buf[32];
                if (*FUN_142516c40(tracer, buf, blk, old) == 0)
                    return;
            }
        }
    } while (*reinterpret_cast<UInt8*>(*reinterpret_cast<UPInt*>(tracer + 0x68) + 0x14) & 1);
}
