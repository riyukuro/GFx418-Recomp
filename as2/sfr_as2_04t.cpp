// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 exception unwinding: the catch and
// finally blocks of a thrown value (gap recovery of sfr_as2_04).
// MS2-UNIT: sfr_as2_04t
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142933440-0x142933994 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_movieroot.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {
typedef Environment::TryDescr CeTryDescr;

// The SDK's TryDescr inlines (AS2_Action.h): the sizes are read byte by byte from the ActionTry record.
SF_FORCEINLINE unsigned CeTrySize(const CeTryDescr& d)     { return d.pTryBlock[1] | (((UInt16)d.pTryBlock[2]) << 8); }
SF_FORCEINLINE unsigned CeCatchSize(const CeTryDescr& d)   { return d.pTryBlock[3] | (((UInt16)d.pTryBlock[4]) << 8); }
SF_FORCEINLINE unsigned CeFinallySize(const CeTryDescr& d) { return d.pTryBlock[5] | (((UInt16)d.pTryBlock[6]) << 8); }
SF_FORCEINLINE bool CeIsCatchInRegister(const CeTryDescr& d) { return (d.pTryBlock[0] & 0x4) != 0; }
SF_FORCEINLINE bool CeIsFinallyBlockFlag(const CeTryDescr& d) { return (d.pTryBlock[0] & 0x2) != 0; }
SF_FORCEINLINE bool CeIsCatchBlockFlag(const CeTryDescr& d) { return (d.pTryBlock[0] & 0x1) != 0; }
SF_FORCEINLINE ASString CeGetCatchName(const CeTryDescr& d, Environment* penv)
{
    ASString str = penv->GetBuiltin(ASBuiltin_empty_);
    if (CeIsCatchBlockFlag(d))
    {
        if (!CeIsCatchInRegister(d))
            str = penv->CreateString((const char*)&d.pTryBlock[7]);
    }
    return str;
}
SF_FORCEINLINE int CeGetCatchRegister(const CeTryDescr& d)
{
    if (CeIsCatchBlockFlag(d))
    {
        if (CeIsCatchInRegister(d))
            return (int)((UInt16)d.pTryBlock[7]);
    }
    return -1;
}
} // namespace

// Environment::PopTryBlock, LocalRegisterPtr and SetLocal as the exe inlines them here.
static SF_FORCEINLINE Environment::TryDescr CePopTryBlock(Environment* penv)
{
    Environment::TryDescr descr = penv->TryBlocks[penv->TryBlocks.GetSize() - 1];
    (reinterpret_cast<TryBlocksData*>(&penv->TryBlocks)->*&TryBlocksData::Resize)(penv->TryBlocks.GetSize() - 1);
    return descr;
}
static SF_FORCEINLINE Value* CeLocalRegisterPtr(Environment* penv, unsigned reg)
{
    if (reg >= penv->LocalRegister.GetSize())
    {
        penv->LogError("Invalid local register %d, stack only has %d entries", reg, (int)penv->LocalRegister.GetSize());
        return &penv->GlobalRegister[0];
    }
    return &penv->LocalRegister[penv->LocalRegister.GetSize() - reg - 1];
}
static SF_FORCEINLINE void CeSetLocal(Environment* penv, const ASString& varname, const Value& val)
{
    if (penv->LocalFrames.GetSize() == 0)
        return;
    if (!penv->LocalFrames[penv->LocalFrames.GetSize() - 1])
        return;
    Value* pvalue = const_cast<Value*>(penv->FindLocal(varname));
    if (!pvalue)
        penv->AddLocal(varname, val);
    else
        *pvalue = val;
}

// The frame array's ResizeNoConstruct stays out of line (exe 0x14297e450), as in InvokeContext::Cleanup (sfr_as2_04o).
typedef ArrayDataBase<Ptr<LocalFrame>, AllocatorLH<Ptr<LocalFrame>, Stat_Default_Mem>, ArrayDefaultPolicy> CeLocalFramesData;

// Environment::SetLocalFrameTop: LocalFrames.Resize(t).
static SF_FORCEINLINE void CeSetLocalFrameTop(Environment* penv, unsigned t)
{
    CeLocalFramesData* pdata   = reinterpret_cast<CeLocalFramesData*>(&penv->LocalFrames);
    UPInt              oldSize = pdata->Size;
    (pdata->*&CeLocalFramesData::ResizeNoConstruct)(&penv->LocalFrames, t);
    if (t > oldSize)
        AllocatorLH<Ptr<LocalFrame>, Stat_Default_Mem>::ConstructArray(pdata->Data + oldSize, t - oldSize);
}

// Environment::ClearThrowing (exe 0x1429345d0), inlined here.
static SF_FORCEINLINE void CeClearThrowing(Environment* penv)
{
    penv->ThrowingValue.SetUnset();
    penv->Unrolling = false;
}

// The thrown value ends the try blocks it leaves: each one's catch block gets it (as a local or a register), then its
// finally block runs. Returns where the code goes on.
// @0x142933440
int Environment::CheckExceptions(ActionBuffer* pactBuf, int nextPc, int* plocalTryBlockCount, Value* retval,
                                 const WithStackArray* pwithStack, int execType)
{
    bool needContinueExecution;
    do
    {
        needContinueExecution = false;
        if (ThrowingValue.GetType() != Value::UNSET)
        {
            for (int tc = *plocalTryBlockCount; tc > 0 && !needContinueExecution; --tc)
            {
                Environment::TryDescr tryDescr = CePopTryBlock(this);
                --(*plocalTryBlockCount);

                unsigned topIndex = GetTopIndex();
                if (topIndex > tryDescr.TopStackIndex)
                    Drop(topIndex - tryDescr.TopStackIndex);

                if (CeIsCatchBlockFlag(tryDescr))
                {
                    int localStackTop = 0;
                    if (CeIsCatchInRegister(tryDescr))
                        *(CeLocalRegisterPtr(this, CeGetCatchRegister(tryDescr))) = ThrowingValue;
                    else
                    {
                        localStackTop = (unsigned)LocalFrames.GetSize();
                        Ptr<LocalFrame> prevLocalFrame = GetTopLocalFrame();
                        Ptr<LocalFrame> curLocalFrame  = CreateNewLocalFrame();
                        curLocalFrame->PrevFrame = prevLocalFrame;

                        CeSetLocal(this, CeGetCatchName(tryDescr, this), ThrowingValue);
                    }
                    CeClearThrowing(this);
                    int catchPc = tryDescr.TryBeginPC + CeTrySize(tryDescr);

                    pactBuf->Execute(this, catchPc, CeCatchSize(tryDescr), retval, pwithStack,
                                     static_cast<ActionBuffer::ExecuteType>(execType));

                    nextPc = tryDescr.TryBeginPC + CeTrySize(tryDescr) + CeCatchSize(tryDescr) + CeFinallySize(tryDescr);

                    needContinueExecution = true;

                    if (CeIsCatchInRegister(tryDescr))
                        *(CeLocalRegisterPtr(this, CeGetCatchRegister(tryDescr))) = Value();
                    else
                        CeSetLocalFrameTop(this, localStackTop);
                }
                if (CeIsFinallyBlockFlag(tryDescr))
                {
                    int finallyPc = tryDescr.TryBeginPC + CeTrySize(tryDescr) + CeCatchSize(tryDescr);
                    Unrolling = true;
                    pactBuf->Execute(this, finallyPc, CeFinallySize(tryDescr), retval, pwithStack,
                                     static_cast<ActionBuffer::ExecuteType>(execType));
                    Unrolling = false;
                }
            }
            if (!needContinueExecution)
                return int(*reinterpret_cast<const UInt32*>(reinterpret_cast<const UByte*>(*reinterpret_cast<void* const*>(
                    reinterpret_cast<const UByte*>(pactBuf) + 0x10)) + 0x18)); // pBufferData->GetLength()
        }
    } while (needContinueExecution);
    return nextPc;
}

}}} // namespace Scaleform::GFx::AS2
