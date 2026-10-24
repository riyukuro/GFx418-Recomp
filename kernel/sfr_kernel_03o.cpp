// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 video sound (FMOD back end)
// COMDAT leftovers: the complete destructors of the audio channel/stream/event objects that sfr_video_03 builds,
// the two hash clears they use, and the pointer-array assignment of the video player set. Raw-layout free functions
// under the exe's own FUN_<va> names (these classes are RTTI-less). Our own source, written from the exe.
// Sub-unit of queue unit sfr_kernel_03.
// MS2-UNIT: sfr_kernel_03o
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142743470-0x14274397c .text$mn
// MS2-RANGE: 0x14274397c-0x1427439d0 .text$mn

#include "../gfx/sfr_gfx_07raw.h"
#include <windows.h>
#include <intrin.h>

namespace Scaleform { namespace GFx {

// vftables of the sound objects (primary at +0, list-node subobject at +0x10).
extern "C" char DAT_1431bed60[];   // audio channel
extern "C" char DAT_1431bedd8[];
extern "C" char DAT_1431bec90[];   // its listed base
extern "C" char DAT_1431bed08[];
extern "C" char DAT_1431bec40[];   // list node
extern "C" char DAT_1431bee78[];   // audio stream
extern "C" char DAT_1431beef0[];
extern "C" char DAT_1431bede8[];   // audio event listener
extern "C" char DAT_1431bcbe8[];   // RefCountBase
extern "C" char DAT_1431bed18[];   // sound
extern "C" char DAT_1431bed50[];
extern "C" char DAT_1431bec50[];   // its listed base
extern "C" char DAT_1431bec80[];
extern "C" char DAT_1431bcbb0[];
extern "C" char DAT_1431bef00[];   // buffered sound
extern "C" char DAT_1431bef38[];
extern "C" char DAT_1431bee50[];   // streamed sound
extern "C" char DAT_1431bee68[];
extern "C" char DAT_1431b80b8[];

void FUN_14257db40(void*);                  // RefCountImplCore::~RefCountImplCore
extern "C" void FUN_14257dcd0(void*);       // Ptr Release (sound renderer)
extern "C" void FUN_14258d0b0(void*);       // Lock::~Lock
extern "C" void FUN_142582530(void*);       // Event::~Event
extern "C" void FUN_142746d70(void*);       // audio channel: stop
extern "C" void FUN_142747b30(void*);       // audio event listener: shut down
extern "C" void FUN_1427463e0(U*, void*, U); // ArrayData<VideoPlayerImpl*>::Reserve
extern "C" int FUN_1428d8efc(void*, void*); // FMOD::Channel::setCallback
extern "C" int FUN_1428d8f14(void*, void*); // FMOD::Channel::setUserData
extern "C" int FUN_142303a3b(void*);        // FMOD::Sound::release

static inline void RawSetVtables(void* self, void* primary, void* node)
{
    RawField<void*>(self, 0) = primary;
    RawField<void*>(self, 0x10) = node;
}

// Unlinks the list node at +0x10 (prev +0x18, next +0x20) from its owner's list.
static inline void RawUnlinkNode(void* self)
{
    if (char* next = RawField<char*>(self, 0x20))
    {
        RawField<char*>(RawField<char*>(self, 0x18), 0x10) = next;
        RawField<char*>(RawField<char*>(self, 0x20), 8) = RawField<char*>(self, 0x18);
        RawField<U>(self, 0x18) = 0;
        RawField<U>(self, 0x20) = 0;
    }
}

// HashSet<HashNode<int, StringDataPtr>>::Clear (0x28-byte entries, nothing to release).
// @0x142743470
void FUN_142743470(U** self)
{
    if (*self)
    {
        U off = 0;
        for (U n = (*self)[1] + 1; n; n--, off += 0x28)
        {
            SPInt* link = RawFieldPtr<SPInt>(*self, 0x10 + off);
            if (*link != -2)
                *link = -2;
        }
        if (*self)
            Memory::Free(*self);
        *self = 0;
    }
}

// Clear of a set whose 0x30-byte entries hold an array (buffer at entry +0x28).
// @0x1427434d0
void FUN_1427434d0(U** self)
{
    if (*self)
    {
        U off = 0;
        for (U n = (*self)[1] + 1; n; n--, off += 0x30)
        {
            U* table = *self;
            if (RawField<SPInt>(table, 0x10 + off) != -2)
            {
                if (RawField<void*>(table, 0x28 + off))
                    Memory::Free(RawField<void*>(table, 0x28 + off));
                RawField<SPInt>(table, 0x10 + off) = -2;
            }
        }
        if (*self)
            Memory::Free(*self);
        *self = 0;
    }
}

// Audio channel: detaches from its FMOD channel (+0x38), clears its hash +0x40 and leaves the player's list.
// @0x142743580
void FUN_142743580(void* self)
{
    RawSetVtables(self, DAT_1431bed60, DAT_1431bedd8);
    if (RawField<void*>(self, 0x38))
    {
        FUN_142746d70(self);
        FUN_1428d8efc(RawField<void*>(self, 0x38), 0);
        FUN_1428d8f14(RawField<void*>(self, 0x38), 0);
        RawField<void*>(self, 0x38) = 0;
    }
    FUN_142743470(RawFieldPtr<U*>(self, 0x40));
    RawSetVtables(self, DAT_1431bec90, DAT_1431bed08);
    RawUnlinkNode(self);
    RawField<void*>(self, 0x10) = DAT_1431bec40;
    FUN_14257db40(self);
}

// Audio stream: drops its sound (+0x30, refcount at +8, deleted through slot 0) and its lock +0x70.
// @0x142743630
void FUN_142743630(void* self)
{
    RawSetVtables(self, DAT_1431bee78, DAT_1431beef0);
    char* sound = RawField<char*>(self, 0x30);
    if (_InterlockedExchangeAdd((volatile long*)(sound + 8), -1) == 1 && sound)
        (*(void (**)(void*, unsigned))*(void**)sound)(sound, 1);
    FUN_14258d0b0(RawFieldPtr<void>(self, 0x70));
    FUN_142743580(self);
}

// Audio event listener.
// @0x1427436a0
void FUN_1427436a0(void* self)
{
    RawField<void*>(self, 0) = DAT_1431bede8;
    FUN_142747b30(self);
    FUN_14258d0b0(RawFieldPtr<void>(self, 0xc8));
    RawField<void*>(self, 0xb0) = DAT_1431bec40;
    FUN_1427434d0(RawFieldPtr<U*>(self, 0xa8));
    FUN_14258d0b0(RawFieldPtr<void>(self, 0x80));
    FUN_142582530(RawFieldPtr<void>(self, 0x20));
    if (RawField<void*>(self, 0x18))
        FUN_14257dcb0(RawField<void*>(self, 0x18));
    RawField<void*>(self, 0) = DAT_1431bcbe8;
    FUN_14257db40(self);
}

// Sound: releases its FMOD sound (+0x30), leaves the renderer's list under the renderer's lock (+0x28, +0xc8) and
// drops the renderer (+0x38).
// @0x142743730
void FUN_142743730(void* self)
{
    RawSetVtables(self, DAT_1431bed18, DAT_1431bed50);
    if (RawField<void*>(self, 0x30))
        FUN_142303a3b(RawField<void*>(self, 0x30));
    char* renderer = RawField<char*>(self, 0x28);
    RawField<void*>(self, 0x30) = 0;
    if (renderer)
    {
        EnterCriticalSection((LPCRITICAL_SECTION)(renderer + 0xc8));
        RawUnlinkNode(self);
        LeaveCriticalSection((LPCRITICAL_SECTION)(renderer + 0xc8));
    }
    if (RawField<void*>(self, 0x38))
        FUN_14257dcd0(RawField<void*>(self, 0x38));
    RawSetVtables(self, DAT_1431bec50, DAT_1431bec80);
    RawUnlinkNode(self);
    RawField<void*>(self, 0x10) = DAT_1431bec40;
    RawField<void*>(self, 0) = DAT_1431bcbb0;
}

// Buffered sound: frees its sample buffer (+0x58) and its file (+0x40).
// @0x142743820
void FUN_142743820(void* self)
{
    RawSetVtables(self, DAT_1431bef00, DAT_1431bef38);
    if (RawField<void*>(self, 0x58))
        Memory::Free(RawField<void*>(self, 0x58));
    if (RawField<void*>(self, 0x40))
        FUN_14257dcb0(RawField<void*>(self, 0x40));
    FUN_142743730(self);
}

// Streamed sound.
// @0x142743870
void FUN_142743870(void* self)
{
    RawSetVtables(self, DAT_1431bee50, DAT_1431bee68);
    if (RawField<void*>(self, 0x30))
        FUN_142303a3b(RawField<void*>(self, 0x30));
    RawField<void*>(self, 0x30) = 0;
    RawUnlinkNode(self);
    if (RawField<void*>(self, 0x28))
        FUN_14257dcd0(RawField<void*>(self, 0x28));
    RawField<void*>(self, 0x10) = DAT_1431bec40;
    RawField<void*>(self, 0) = DAT_1431b80b8;
    FUN_14257db40(self);
}

// ArrayBase<ArrayData<VideoPlayerImpl*>>::operator=: shrinks below half capacity, grows by a quarter, then copies.
// @0x142743900
U* FUN_142743900(U* self, const U* source)
{
    U n = source[1];
    if (n < self[1])
    {
        if (n < (self[2] >> 1))
            FUN_1427463e0(self, self, n);
    }
    else if (n > self[2])
        FUN_1427463e0(self, self, n + (n >> 2));
    self[1] = n;
    for (U i = 0; i < self[1]; i++)
        ((U*)self[0])[i] = ((const U*)source[0])[i];
    return self;
}

void* FUN_142743a60(void* self, unsigned flags);
void* FUN_142743ac0(void* self, unsigned flags);
void* FUN_142743b60(void* self, unsigned flags);
void* FUN_142743e00(void* self, unsigned flags);
void* FUN_142743e60(void* self, unsigned flags);
void* FUN_142743f00(void* self, unsigned flags);
void* FUN_142743fa0(void* self, unsigned flags);

// Adjustor thunks of the sound objects' scalar deleting destructors: the list-node subobject's vftable slot 0
// (this at +0x10) back to the full object (leaf, no .pdata).
// MS2-FUNCTIONAL: the exe's compiler-generated thunks adjust with `sub rcx, 10h`; cl emits `add rcx, -10h` here.
// audio channel
// @0x14274397c
void* FUN_14274397c(void* self, unsigned flags)
{
    return FUN_142743a60(static_cast<char*>(self) - 0x10, flags);
}

// audio stream
// @0x142743988
void* FUN_142743988(void* self, unsigned flags)
{
    return FUN_142743ac0(static_cast<char*>(self) - 0x10, flags);
}

// listed sound object
// @0x142743994
void* FUN_142743994(void* self, unsigned flags)
{
    return FUN_142743b60(static_cast<char*>(self) - 0x10, flags);
}

// sound
// @0x1427439a0
void* FUN_1427439a0(void* self, unsigned flags)
{
    return FUN_142743e00(static_cast<char*>(self) - 0x10, flags);
}

// buffered sound
// @0x1427439ac
void* FUN_1427439ac(void* self, unsigned flags)
{
    return FUN_142743e60(static_cast<char*>(self) - 0x10, flags);
}

// listed sound
// @0x1427439b8
void* FUN_1427439b8(void* self, unsigned flags)
{
    return FUN_142743f00(static_cast<char*>(self) - 0x10, flags);
}

// streamed sound
// @0x1427439c4
void* FUN_1427439c4(void* self, unsigned flags)
{
    return FUN_142743fa0(static_cast<char*>(self) - 0x10, flags);
}

}} // namespace Scaleform::GFx
