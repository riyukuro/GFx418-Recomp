// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): two Scaleform GFx 4.1.18 strays: the empty
// RefCountImplCore copy assignment (refcounts are not copied) and the locked chunk-queue read behind the AS3 sound's
// FMOD PCM read callback (sfr_as3_22, 0x142745470). Our own source, written from the exe.
// Sub-unit of queue unit sfr_kernel_03.
// MS2-UNIT: sfr_kernel_03p
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426e0080-0x1426e0090 .text$mn
// MS2-RANGE: 0x142748160-0x142748230 .text$mn

#include "../gfx/sfr_gfx_07raw.h"
#include <windows.h>
#include <string.h>

namespace Scaleform {

// RefCountImplCore::operator= (inline in sf_refcount.h), the out-of-line COMDAT copy: refcounts are not copied.
// MS2-FUNCTIONAL: the exe encodes the empty body as `ret 0`.
// @0x1426e0080
void FUN_1426e0080(void*, const void*)
{
}

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
    EnterCriticalSection(RawFieldPtr<CRITICAL_SECTION>(stream, 0x40));
    UInt32 copied = 0;
    if (RawField<Sfr21SoundChunk*>(stream, 0x30))
    {
        UInt32 pos = RawField<UInt32>(stream, 0x3c);
        while (bytes)
        {
            Sfr21SoundChunk* chunk = RawField<Sfr21SoundChunk*>(stream, 0x30);
            UInt32 n = bytes;
            if (pos + bytes > chunk->Size)
            {
                n = chunk->Size - pos;
                if (!n)
                {
                    if (!chunk->Next)
                        break;
                    RawField<Sfr21SoundChunk*>(stream, 0x30) = chunk->Next;
                    pos = 0;
                    RawField<UInt32>(stream, 0x3c) = 0;
                    continue;
                }
            }
            memcpy((char*)dst + copied, chunk->Data + pos, n);
            RawField<UInt32>(stream, 0x3c) += n;
            bytes -= n;
            pos = RawField<UInt32>(stream, 0x3c);
            copied += n;
        }
    }
    LeaveCriticalSection(RawFieldPtr<CRITICAL_SECTION>(stream, 0x40));
    return copied;
}

}} // namespace Scaleform::GFx
