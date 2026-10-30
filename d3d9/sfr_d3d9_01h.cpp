// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 video sound (FMOD back end)
// deleting destructors and the identical-code-folded RefCountBase/SystemVertexFormat deleting destructors that sit
// next to them. Raw-layout free functions under the exe's own FUN_<va> names. Our own source, written from the exe.
// Sub-unit of queue unit sfr_d3d9_01.
// MS2-UNIT: sfr_d3d9_01h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1427439d0-0x142743db0 .text$mn

#include "../gfx/sfr_gfx_07raw.h"
#include <windows.h>
#include <intrin.h>

namespace Scaleform { namespace GFx {

extern "C" char DAT_1431bec40[];   // list node
extern "C" char DAT_1431bec90[];   // listed sound object
extern "C" char DAT_1431bed08[];
extern "C" char DAT_1431bee78[];   // audio stream
extern "C" char DAT_1431beef0[];
extern "C" char DAT_1431bede8[];   // audio event listener
extern "C" char DAT_1431bcbe8[];   // RefCountBase

void FUN_14257db40(void*);                  // RefCountImplCore::~RefCountImplCore
void FUN_14015b310(void*, UPInt);           // sized operator delete (Scaleform heap)
extern "C" void FUN_142743580(void*);       // audio channel dtor
extern "C" void FUN_1427434d0(void*);       // array-valued set Clear
extern "C" void FUN_142582530(void*);       // Event::~Event
extern "C" void FUN_142747b30(void*);       // audio event listener: shut down
extern "C" void FUN_14258d0b0(void*);       // Lock::~Lock

static inline void* RawDeleteTail(void* self, unsigned flags, UPInt size)
{
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, size);
    }
    return self;
}

// RefCountBaseStatImpl<RefCountImpl, 0x41>: the shared 0x10-byte RefCountBase deleting destructor.
// @0x1427439d0
void* FUN_1427439d0(void* self, unsigned flags)
{
    FUN_14257db40(self);
    return RawDeleteTail(self, flags, 0x10);
}

// List node (0x18 bytes, CRT heap).
// @0x142743a30
void* FUN_142743a30(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_1431bec40;
    if (flags & 1)
        ::operator delete(self, (size_t)0x18);
    return self;
}

// Audio channel.
// @0x142743a60
void* FUN_142743a60(void* self, unsigned flags)
{
    FUN_142743580(self);
    return RawDeleteTail(self, flags, 0x48);
}

// Audio stream.
// @0x142743ac0
void* FUN_142743ac0(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_1431bee78;
    RawField<void*>(self, 0x10) = DAT_1431beef0;
    char* sound = RawField<char*>(self, 0x30);
    if (_InterlockedExchangeAdd((volatile long*)(sound + 8), -1) == 1 && sound)
        (*(void (**)(void*, unsigned))*(void**)sound)(sound, 1);
    FUN_14258d0b0(RawFieldPtr<void>(self, 0x70));
    FUN_142743580(self);
    return RawDeleteTail(self, flags, 0xa0);
}

// Listed sound object.
// @0x142743b60
void* FUN_142743b60(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_1431bec90;
    RawField<void*>(self, 0x10) = DAT_1431bed08;
    if (char* next = RawField<char*>(self, 0x20))
    {
        RawField<char*>(RawField<char*>(self, 0x18), 0x10) = next;
        RawField<char*>(RawField<char*>(self, 0x20), 8) = RawField<char*>(self, 0x18);
        RawField<U>(self, 0x18) = 0;
        RawField<U>(self, 0x20) = 0;
    }
    RawField<void*>(self, 0x10) = DAT_1431bec40;
    FUN_14257db40(self);
    return RawDeleteTail(self, flags, 0x28);
}

// SystemVertexFormat (and the other 0x10-byte RefCountBase leaves folded onto it).
// @0x142743c10
void* FUN_142743c10(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_1431bcbe8;
    FUN_14257db40(self);
    return RawDeleteTail(self, flags, 0x10);
}

// A second, separately emitted copy of the same destructor.
// @0x142743c80
void* FUN_142743c80(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_1431bcbe8;
    FUN_14257db40(self);
    return RawDeleteTail(self, flags, 0x10);
}

// Audio event listener.
// @0x142743cf0
void* FUN_142743cf0(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_1431bede8;
    FUN_142747b30(self);
    DeleteCriticalSection(RawFieldPtr<CRITICAL_SECTION>(self, 0xc8));
    RawField<void*>(self, 0xb0) = DAT_1431bec40;
    FUN_1427434d0(RawFieldPtr<void>(self, 0xa8));
    DeleteCriticalSection(RawFieldPtr<CRITICAL_SECTION>(self, 0x80));
    FUN_142582530(RawFieldPtr<void>(self, 0x20));
    if (RawField<void*>(self, 0x18))
        FUN_14257dcb0(RawField<void*>(self, 0x18));
    RawField<void*>(self, 0) = DAT_1431bcbe8;
    FUN_14257db40(self);
    return RawDeleteTail(self, flags, 0xf8);
}

}} // namespace Scaleform::GFx
