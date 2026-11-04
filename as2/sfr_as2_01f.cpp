// AS3 leftovers in the sfr_as2_01 map range, between sfr_as3_19's pieces: the plain Traits::SetupSlotValues,
// MovieRoot::Shutdown and the tracer's skip over code no branch reaches.
// MS2-UNIT: sfr_as2_01f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14252c4e0-0x14252c7e0 .text$mn
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_moviedefrootnode.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"

// Bodies of the exe called here (not recovered yet), by their addresses.
void FUN_1424dd110(void* paliases);                                       // ~ASStringHash<Value> (the invoke aliases)
namespace Scaleform { namespace GFx { namespace AS3 {
void Sfr31ShutdownRegistered(UPInt self);  // ASVM: drops the loaded ABC files
} } }
void FUN_14257dcd0(void* p);                                              // RefCountNTSImpl::Release

namespace Scaleform {
// The event chains (Clear 0x1424ef380, sfr_as3_17) and the rollover stacks (Resize 0x1425245c0, sfr_as3_19); the
// members are raw words in as3_asvm.h.
using Sfr01fChainArray  = ArrayLH<WeakPtr<GFx::DisplayObject>, 2, ArrayDefaultPolicy>;
using Sfr01fChainNode   = HashNode<int, AutoPtr<Sfr01fChainArray>, IdentityHash<int>>;
using Sfr01fChainSet    = HashSetBase<Sfr01fChainNode, Sfr01fChainNode::NodeHashF, Sfr01fChainNode::NodeAltHashF,
                                      AllocatorLH<int, 2>, HashsetNodeEntry<Sfr01fChainNode, Sfr01fChainNode::NodeHashF>>;
using Sfr01fRolloverData = ArrayData<Ptr<GFx::InteractiveObject>,
                                     AllocatorLH<Ptr<GFx::InteractiveObject>, GFx::AS3::StatMV_ActionScript_Mem>,
                                     ArrayDefaultPolicy>;
}

namespace Scaleform { namespace GFx { namespace AS3 {

// Plain traits have no slot values to set up.
// @0x14252c4e0
CheckResult Traits::SetupSlotValues(Object&) const
{
    return true;
}

// The movie goes away: the queued actions, the stage, the host's aliases and return value, the frame listeners, the
// mice, every movie's ABC files and at last the VM, with a collection between the steps.
// MS2-FUNCTIONAL the 4.1.18 ForceCollect (slot 9) takes no flags; called through the slot without one
// MS2-FUNCTIONAL: through the slot the vtable load moves above the pStage store, and the list-root test differs
// Value::SetUndefined and ResizeNoConstruct are called through member-pointer locals, as the exe calls them out of line.
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
    void (Scaleform::GFx::AS3::Value::*setUndefined)() = &Scaleform::GFx::AS3::Value::SetUndefined;
    (ExternalIntfRetVal.*setUndefined)();
    void (Sfr01fChainSet::*clearChains)() = &Sfr01fChainSet::Clear;
    (reinterpret_cast<Sfr01fChainSet*>(&mEventChains)->*clearChains)();
    void (Sfr01fRolloverData::*resizeRollover)(UPInt) = &Sfr01fRolloverData::Resize;
    for (unsigned i = 0; i < 4; ++i)
    {
        MouseState& ms = mMouseState[i];
        (reinterpret_cast<Sfr01fRolloverData*>(ms.RolloverStack)->*resizeRollover)(0);
        if (ms.LastMouseOverObj)
            FUN_14257dcd0(ms.LastMouseOverObj);
        ms.LastMouseOverObj = NULL;
    }
    typedef ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,
                          AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>, 2>,
                          ArrayDefaultPolicy> AbcFileData;
    void (AbcFileData::*resizeNoConstruct)(const void*, UPInt) = &AbcFileData::ResizeNoConstruct;
    for (GFx::MovieDefRootNode* p = pMovieImpl->RootMovieDefNodes.pNext;
         p != static_cast<GFx::MovieDefRootNode*>(&pMovieImpl->RootMovieDefNodes); p = p->pNext)
    {
        MovieDefRootNode* pnode = static_cast<MovieDefRootNode*>(p);
        (reinterpret_cast<AbcFileData*>(&pnode->AbcFiles)->*resizeNoConstruct)(&pnode->AbcFiles, 0);
    }
    (*reinterpret_cast<CollectFn const* const*>(this))[9](this);
    Scaleform::GFx::AS3::Sfr31ShutdownRegistered(reinterpret_cast<UPInt>(pAVM));
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

// Walks the Tracer's block list to the first block starting at or before cur.
static inline UPInt* FindTracerBlock(UPInt* blk, UPInt cur)
{
    while (blk != NULL && cur < blk[4])
        blk = reinterpret_cast<UPInt*>(*blk);
    return blk;
}

// Tracer: while the current block is dead code, steps over its opcodes (operands included), entering each block that
// starts where it lands; stops at the end of the code or when a merge fails.
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
        switch (op)
        {
        case 0x0c: case 0x0d: case 0x0e: case 0x0f: case 0x10: case 0x11: case 0x12: case 0x13:
        case 0x14: case 0x15: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
            Abc::ReadS24(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
            break;
        case 0x1b:
        {
            Abc::ReadS24(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
            int n = Abc::ReadU30(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
            for (int i = 0; i <= n; ++i)
                Abc::ReadS24(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
            break;
        }
        case 0x24:
            ++*pos;
            break;
        case 0xef:
            ++*pos;
            Abc::ReadU30(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
            ++*pos;
            Abc::ReadU30(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
            break;
        default:
            switch (DAT_14317fea0[op].operandCount)
            {
            case 2:
                Abc::ReadU30(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
            case 1:
                Abc::ReadU30(*reinterpret_cast<const UInt8**>(tracer + 0x50), *pos);
                break;
            }
            break;
        }
        UPInt* first = *reinterpret_cast<UPInt**>(tracer + 0x110);
        UPInt cur = *pos;
        UPInt* old = *reinterpret_cast<UPInt**>(tracer + 0x68);
        UPInt* blk = FindTracerBlock(first, cur);
        if (blk != NULL && blk[4] == cur)
        {
            *reinterpret_cast<UPInt**>(tracer + 0x68) = blk;
            if (*reinterpret_cast<UInt8*>(blk + 2) & 1)
            {
                if (blk != old)
                {
                    UPInt buf;
                    if (*FUN_142516c40(tracer, &buf, blk, old) == 0)
                        return;
                }
            }
            else
                FUN_142511b00(tracer, blk, old);
        }
    } while (*reinterpret_cast<UInt8*>(*reinterpret_cast<UPInt*>(tracer + 0x68) + 0x14) & 1);
}
