// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): a Scaleform GFx 4.1.18 stray: the locked chunk-queue
// read behind the AS3 sound's FMOD PCM read callback (sfr_as3_22, 0x142745470). Our own source, written from the exe.
// (0x1426e0080, once taken here for RefCountImplCore::operator=, is the empty RenderQueueProcessor dtor: sfr_render_07j.)
// Sub-unit of queue unit sfr_kernel_03.
// MS2-UNIT: sfr_kernel_03p
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142748160-0x142748230 .text$mn

#include "../gfx/sfr_gfx_07raw.h"
#include <windows.h>
#include <string.h>

namespace Scaleform {

namespace GFx {

// A queued chunk of sound data: next chunk, bytes, byte count.
struct Sfr21SoundChunk
{
    Sfr21SoundChunk* Next;
    char*            Data;
    UInt32           Size;
};

// Copies up to `bytes` from the stream's chunk queue (current chunk +0x30, read position +0x3c, lock +0x40) into
// `dst`, moving on to the next chunk when one is used up; returns the bytes copied.
// @0x142748160
UInt32 FUN_142748160(void* stream, void* dst, UInt32 bytes)
{
    // AppendableSoundData::GetData as the SDK has it (Sound_Sound.cpp), the lock held by a Lock::Locker
    struct Locker
    {
        CRITICAL_SECTION* pLock;
        Locker(CRITICAL_SECTION* plock) : pLock(plock) { EnterCriticalSection(pLock); }
        ~Locker() { LeaveCriticalSection(pLock); }
    } lock(RawFieldPtr<CRITICAL_SECTION>(stream, 0x40));
    if (!RawField<Sfr21SoundChunk*>(stream, 0x30))
        return 0;

    UInt32 copied = 0;
    while (bytes > 0)
    {
        Sfr21SoundChunk* chunk = RawField<Sfr21SoundChunk*>(stream, 0x30);
        UInt32 n = bytes;
        if (RawField<UInt32>(stream, 0x3c) + bytes > chunk->Size)
        {
            n = chunk->Size - RawField<UInt32>(stream, 0x3c);
            if (n == 0)
            {
                if (!chunk->Next)
                    return copied;
                RawField<Sfr21SoundChunk*>(stream, 0x30) = chunk->Next;
                RawField<UInt32>(stream, 0x3c) = 0;
                continue;
            }
        }
        memcpy((char*)dst + copied, chunk->Data + RawField<UInt32>(stream, 0x3c), n);
        bytes -= n;
        RawField<UInt32>(stream, 0x3c) += n;
        copied += n;
    }
    return copied;
}

}} // namespace Scaleform::GFx
