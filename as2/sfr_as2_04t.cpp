// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 exception unwinding: the catch and
// finally blocks of a thrown value (gap recovery of sfr_as2_04).
// MS2-UNIT: sfr_as2_04t
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142933440-0x142933994 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_movieroot.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The thrown value ends the try blocks it leaves: each one's catch block gets it (as a local or a register), then its
// finally block runs. Returns where the code goes on.
// MS2-FUNCTIONAL: the catch variable goes through SetLocal, the frame stack and the registers are restored by their
// array operations
// @0x142933440
int Environment::CheckExceptions(ActionBuffer* pactBuf, int pc, int* plocalTryBlockCount, Value* retval,
                                 const WithStackArray* pinitialWithStack, int execType)
{
    bool rerun;
    do
    {
        rerun = false;
        if (ThrowingValue.GetType() == Value::UNSET)
            return pc;
        int count = *plocalTryBlockCount;
        if (count < 1)
            break;
        do
        {
            if (rerun)
                break;
            TryDescr descr = TryBlocks[TryBlocks.GetSize() - 1];
            TryBlocks_Resize(&TryBlocks, TryBlocks.GetSize() - 1);
            --*plocalTryBlockCount;
            unsigned topIndex = (unsigned)GetTopIndex();
            if (descr.TopStackIndex < topIndex)
                Drop(int(topIndex - descr.TopStackIndex));
            const UByte* prec = descr.pTryBlock;
            int          beginPc = (int)descr.TryBeginPC;
            if (prec[0] & 1)
            {
                UPInt savedFrames = 0;
                if (!(prec[0] & 4))
                {
                    savedFrames = LocalFrames.GetSize();
                    Ptr<LocalFrame> pouter = GetTopLocalFrame(0);
                    Ptr<LocalFrame> pframe = CreateNewLocalFrame();
                    pframe->PrevFrame      = pouter;
                    ASString name = GetBuiltin(ASBuiltin_empty_);
                    if ((prec[0] & 1) && !(prec[0] & 4))
                        name = CreateString(reinterpret_cast<const char*>(prec + 7));
                    SetLocal(name, ThrowingValue);
                }
                else
                {
                    *LocalRegisterPtr(prec[7]) = ThrowingValue;
                }
                ThrowingValue.SetUnset();
                Unrolling = false;
                ActionBuffer* pbuf = pactBuf;
                pbuf->Execute(this, int(*reinterpret_cast<const UInt16*>(prec + 1)) + beginPc,
                              *reinterpret_cast<const UInt16*>(prec + 3), retval, pinitialWithStack, static_cast<ActionBuffer::ExecuteType>(execType));
                rerun = true;
                pc = int(*reinterpret_cast<const UInt16*>(prec + 3)) + int(*reinterpret_cast<const UInt16*>(prec + 1)) +
                     beginPc + int(*reinterpret_cast<const UInt16*>(prec + 5));
                if (!(prec[0] & 4))
                    LocalFrames.Resize(savedFrames);
                else
                {
                    unsigned reg = (prec[0] & 1) ? prec[7] : 0xffffffffu;
                    *LocalRegisterPtr(reg) = Value();
                }
            }
            if (prec[0] & 2)
            {
                Unrolling = true;
                pactBuf->Execute(this,
                                 int(*reinterpret_cast<const UInt16*>(prec + 3)) +
                                     int(*reinterpret_cast<const UInt16*>(prec + 1)) + beginPc,
                                 *reinterpret_cast<const UInt16*>(prec + 5), retval, pinitialWithStack, static_cast<ActionBuffer::ExecuteType>(execType));
                Unrolling = false;
            }
            --count;
        } while (count > 0);
    } while (rerun);
    return int(*reinterpret_cast<const UInt32*>(reinterpret_cast<const UByte*>(*reinterpret_cast<void* const*>(
                                                    reinterpret_cast<const UByte*>(pactBuf) + 0x10)) + 0x18));
}

}}} // namespace Scaleform::GFx::AS2
