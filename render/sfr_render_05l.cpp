// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 COMDAT leftovers inside the queue
// ranges of sfr_render_05: the deleting destructors of the SysAlloc singleton bases and of five small ref-counted
// render objects (the last one also drops a counted buffer). Raw-layout free functions under the exe's own
// FUN_<va> names; the object types are unnamed in the exe's RTTI-less COMDATs.
// Sub-unit of queue unit sfr_render_05.
// MS2-UNIT: sfr_render_05l
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142685e20-0x142685eeb .text$mn
// MS2-RANGE: 0x142688cf0-0x142688e70 .text$mn
// MS2-RANGE: 0x142688ed0-0x142688f50 .text$mn

#include "../gfx/sfr_gfx_07raw.h"
#include <intrin.h>

namespace Scaleform { namespace GFx {

extern char DAT_14318f0a8[];

void FUN_14015b310(void*, UPInt);

static inline void RawDeleteBranch(void* self, unsigned flags, UPInt size)
{
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, size);
    }
}

// Bare vftable holders (the SysAlloc singleton bases and SysAllocMalloc): vftable store, then the plain delete.
// @0x142685e20
void* FUN_142685e20(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_14318f0a8;
    if (flags & 1)
        ::operator delete(self, 0x10);
    return self;
}

// @0x142685e70
void* FUN_142685e70(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_14318f0a8;
    if (flags & 1)
        ::operator delete(self, 0x10);
    return self;
}

// @0x142685ec0
void* FUN_142685ec0(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_14318f0a8;
    if (flags & 1)
        ::operator delete(self, 0x10);
    return self;
}

// RefCountImplCore-only objects of size 0x10 (ThreadCommand, RefCountBase<DICommandQueue> and look-alikes).
// @0x142688cf0
void* FUN_142688cf0(void* self, unsigned flags)
{
    RawRefCountCoreDtor(self);
    RawDeleteBranch(self, flags, 0x10);
    return self;
}

// @0x142688d50
void* FUN_142688d50(void* self, unsigned flags)
{
    RawRefCountCoreDtor(self);
    RawDeleteBranch(self, flags, 0x10);
    return self;
}

// @0x142688db0
void* FUN_142688db0(void* self, unsigned flags)
{
    RawRefCountCoreDtor(self);
    RawDeleteBranch(self, flags, 0x10);
    return self;
}

// @0x142688e10
void* FUN_142688e10(void* self, unsigned flags)
{
    RawRefCountCoreDtor(self);
    RawDeleteBranch(self, flags, 0x10);
    return self;
}

// A counted buffer at +0x18 (low two bits are tag bits, count at +8 of the buffer), released with the object.
// @0x142688ed0
void* FUN_142688ed0(void* self, unsigned flags)
{
    char* buffer = (char*)(RawField<U>(self, 0x18) & ~(U)3);
    if (_InterlockedDecrement((volatile long*)(buffer + 8)) == 0)
        Memory::Free(buffer);
    RawRefCountCoreDtor(self);
    RawDeleteBranch(self, flags, 0x40);
    return self;
}

}} // namespace Scaleform::GFx
