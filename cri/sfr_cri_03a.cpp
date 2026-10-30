// Recovered CRI base layer from MapleStory2.exe: criCs critical sections, criAtomic, the criUtf @UTF table reader and
// criUsfCmn. In the exe this is a run of /Os objs whose strings sit in .rdata (0x1431b9xxx), split from sfr_cri_03 at the
// obj boundary 0x14003b6e0, where the /Od criMvPly objs begin.
// The CRI Movie 3.07 library was built with VS2008 SP1, and so is this unit (MS2-TOOLSET: vc9, cmake/ms2-unit-profiles.cmake):
// keep it C++03 (no auto, decltype, variadic templates, brace-init or nullptr). clang-cl compiles it as before.
// MS2-UNIT: sfr_cri_03a
// MS2-TOOLSET: vc9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140039ea8-0x14003b6e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/cri/cri_movie.h"
#include <windows.h>
#include <cstring>
#include <cstddef>
#include <memory>
#include <cstdarg>
#include <cstdio>

extern "C" CriSint32 DAT_143ba9d28;
extern "C" CriSint32 DAT_143b27be0;
extern "C" void* DAT_143b27be8;
extern "C" CriUint8 DAT_143b27bf0[0x48];
extern "C" const char* DAT_143ba9d08;
extern "C" const char* volatile DAT_143ba9d20;
extern "C" const char* DAT_143ba9d30;
extern "C" void* DAT_143b15f60;
extern "C" CriUint8 DAT_143b27c80[];
extern "C" CriUint32 DAT_143b27c60;
extern "C" CriUint32 DAT_143b27c64;
extern "C" CriUint32 DAT_143b27c68;
extern "C" CriUint32 DAT_143b27c6c;
extern "C" CriUint64 DAT_143b27c70;
extern "C" CriSint32 DAT_143ba9d10;
extern "C" CriSint32 DAT_143b27948;
extern "C" CriUint32 DAT_143b27c40;
extern "C" CriUint32 DAT_143b27c50;
extern "C" CriUint64 DAT_143b27c58;
extern "C" const char* DAT_143b27c48;
extern "C" const void* DAT_143a47bc0[];
extern "C" const void* DAT_143a47cb0[];
extern "C" const char* DAT_143ba9d18;
// "<SUDPS_>": the USF packet signature FUN_140040f80 copies into a local
struct CriUsfSignature
{
    // nine scalar bytes, not a char[9]: keeps the local copy out of /GS
    CriChar8 Text0, Text1, Text2, Text3, Text4, Text5, Text6, Text7, Terminator;
};
extern "C" const CriUsfSignature DAT_143a482e8;
extern "C" const CriUint64 DAT_1431b9ca0;
extern "C" const void* PTR_LAB_143a48350;
extern "C" const void* PTR_FUN_143a48638;
extern "C" const void* PTR_FUN_143a48668;
extern "C" const void* PTR_FUN_1431b9b10;
extern "C" const void* PTR_FUN_1431b4f78;
void FUN_1400532b0(void);
void FUN_1400532d0(void);
void FUN_140041190(void*, CriSint32);
void FUN_1400385b8(void);
CriBool criCsWin_InitializeCriticalSection(LPCRITICAL_SECTION);
CriBool criCsWin_DeleteCriticalSection(LPCRITICAL_SECTION);
CriBool FUN_140039e24(LPCRITICAL_SECTION);
CriBool FUN_140039e4c(LPCRITICAL_SECTION);
void FUN_140038ddc(CriSint32, const CriChar8*);
void* FUN_14003b2ac(void*, CriSint32, const void*, CriUint32);
void FUN_14003e850(void*, void*, void*);
void FUN_14004e250(void);
void FUN_14004eb70(void);
void FUN_14004f8d0(void);
void FUN_140027fb4(void*, void*);
void FUN_14004e2a0(void*);
void FUN_140046784(void*);
void* FUN_14004fe20(void*, CriUint32, CriUint32);
void FUN_14003cae0(void*);
CriSint32 FUN_14003cff0(void*);
CriUint32 criVdecCmn_GetNumPictureData(const void* decoder);
void* FUN_140027f7c(void*, CriSint32, const CriChar8*, CriSint32, CriSint32);
void* FUN_14003a1a0(void*, CriUint32, const void*, CriUint32);
CriSint32 FUN_14004e2f0(void*, CriSint32, CriSint32);
CriSint32 FUN_1400500b0(CriSint32, void*);
void* FUN_14004e580(void);
void FUN_14004ff90(void*, void*, void*);
void FUN_1400467a8(void*, CriSint32, void*);
void FUN_1400467b0(void*, CriSint32, void*);
CriSint32 FUN_1400467b8(void*, CriSint32);
void FUN_140046798(void*);
void FUN_1400467a0(void*, CriSint32, CriUint32, void*);
CriSint32 FUN_140053630(void*);
CriUint32 FUN_140043420(void*, void*, CriUint32);
CriBool FUN_140043750(void*, const void*);
CriUint32 FUN_140042f40(void*, void*, CriUint32, void*, CriUint32, CriUint32*);
CriUint32 FUN_1400431a0(void*, void*, CriUint32, void*, CriUint32, CriUint32*);
void criSj_SplitChunk(const void*, CriUint32, void*, void*);
CriSint32 FUN_140027dd0(CriSint32);
CriSint32 criVmpv_GetStatus(const void*);
void FUN_14003e180(void*, const void*);
const void** FUN_14003bed0(void);
const void** FUN_14003bf10(void);
void FUN_14002e6e0(const CriMvCodecRegistrationEntry* registration);
void FUN_140046014(void*);
void FUN_14004602c(void*);
CriSint32 FUN_140046604(CriUint32, CriUint32, CriUint32, const CriUint32*);
void* FUN_140046730(void*, CriUint32, CriUint32, CriUint32, CriUint64);
void* FUN_140053340(void*, CriUint32, CriUint32);
void FUN_1400534d0(void*);
void FUN_1400534f0(void*, void*);
void FUN_140053510(void*, CriUint32, void*);
void FUN_140042600(void*, void*, CriSint32);
CriUint64 FUN_1425e3510(void);
CriUint64 FUN_1425e3560(void);
void FUN_14257db50(void* object);
void FUN_14257e4a0(void*, void*);
void FUN_140054040(void*, void*, void*);
void FUN_140053540(void*);
void FUN_140037910(void*, const CriChar8*, CriSint32);
void FUN_1400379b0(CriSint32, const CriChar8*);
void FUN_140053650(void*);
void FUN_140053470(void*);
void FUN_140037950(void*, const CriChar8*, CriSint32);
void FUN_140042600(void*, void*, CriSint32);
CriSint32 FUN_1400310b0(void*);
void FUN_1400345e0(void*, void*, CriUint32, CriSint32);
void FUN_140053e60(void*, CriUint32, CriUint32, CriUint32);
void criSj_SplitChunk(const void* source, CriUint32 maximum, void* prefix, void* suffix);
void FUN_14004f8a0(void);
void FUN_14004eb50(void);
void FUN_14004e3b0(CriUint64, CriUint64);
void* FUN_14003da40(void*, void*);
void* FUN_14003dd50(void*, void*);
void* FUN_140027ed8(void*, CriSint32, const CriChar8*, ...);
void FUN_140040cc0(void*, CriUint32, CriSint32*, CriSint32*);
void FUN_140038e24(CriSint32, const char*, CriSint32);
void FUN_140038ce4(CriSint32, const char*, CriSint32, CriSint32, void*);
void FUN_140041110(void*, const char*, CriUint32);
void FUN_140046d50(void*, CriSint32);
void FUN_140053570(void*);
void FUN_140050e90(void*);
void FUN_140053e40(void*);
CriUint32 FUN_1400472c0(const CriUint8*, CriUint32);
void* FUN_140046e04(void*, void*, CriUint32, void*, void*, const void*, CriUint32, void*, CriUint32);
const CriChar8* criUtfRtv_GetDataStr(const CriUtfRtvView*, CriUint32, CriUint32);
CriUint32 criUsfCmn_ParseUsfHeaderStd(const CriUint8*, CriUint32, CriUsfStandardHeader*);
// CriUsfStandardHeader read through its parsed fields. The exe's header local is not a byte buffer (no /GS cookie).
struct CriUsfHeaderFields
{
    CriUint32 ChunkId;      // 0x00
    CriUint32 Size;         // 0x04
    CriUint32 Word08;       // 0x08
    CriUint8 Byte0C;        // 0x0c
    CriUint8 Byte0D;        // 0x0d
    CriUint8 Byte0E;        // 0x0e
    CriUint8 Kind;          // 0x0f
    CriUint32 Words[5];     // 0x10
};
CriSint32 criSjUni_CalculateWorkSize(const CriSint32* config);
CriSint32 FUN_140045910(const CriSint32*);
CriSint32 FUN_140045ed0(const CriSint32*);
void* FUN_1400459ec(const void*, void*, CriSint32);
CriSint32 criSjRbf_CalculateWorkSize(const CriSint32* config);
void* FUN_140045eec(const void*, void*, CriSint32);
void FUN_140045998(void*);
void FUN_140045fdc(void*);
void FUN_140045474(void*);
void FUN_14029dd60(void*, const CriChar8*, const void*);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_1400410d0(void* owner, const CriChar8* message, CriUint32 value);

void FUN_140041110(void* owner, const CriChar8* message, CriUint32 value);

void FUN_140041190(void* object, CriSint32 value);

void FUN_1400435d0(void* object);

void FUN_14003ebe0(void* object);

CriBool FUN_14003eeb0(const void* input);

void FUN_14003d8f0(void* object);
#pragma optimize("", on)

void FUN_140041a60(void* object);

CriUint32 FUN_140041300(void* object);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_140043680(void* object);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void* FUN_140046324(const void* config, void* heap, CriUint32 allocationMode);

void* FUN_1400464f4(const void* config, void* heap, CriUint32 allocationMode);

void FUN_1400463f4(void* heap, CriUint32 first, CriUint32 second, const CriUint32* settings);

void FUN_14004647c(void* heap, CriUint32 first, CriUint32 second);

void* FUN_1400464c8(void* heap, CriUint32 first, CriUint32 second);

void* FUN_1400465c4(void* heap, CriUint32 first, CriUint32 second, CriUint32 third,
                   CriUint64 poolBytes, const CriUint32* settings);

void FUN_1400463c8(void* object);

void FUN_140046598(void* object);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriBool FUN_140043810(void* object, void* owner);

CriBool FUN_140042df0(void* decoders, void* owner, CriSint32 index);

CriUint32 FUN_140042f00(void* decoders, CriSint32 index, void* player, CriUint32 channel);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
CriSint32 FUN_1400468f4(void* streamJoint, const void* chunk, void* suffix, CriUint32 maximum);

void FUN_1400469a4(CriChar8* buffer, size_t capacity, const CriChar8* format, ...);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriUint32 FUN_14003d9d0(void* object);

CriBool FUN_140042d70(void* decoderList, void* owner);

CriUint32 FUN_140042e40(void* decoders, CriSint32 index, void* player, CriUint32 channels,
                        void* output, CriUint32 flags, CriUint32* result);

CriUint32 FUN_140042ea0(void* decoders, CriSint32 index, void* player, CriUint32 channels,
                        void* output, CriUint32 flags, CriUint32* result);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
CriSint32 FUN_140046420(CriUint32 first, CriUint32 second, const CriUint32* settings);

void FUN_1400464a8(CriUint32 first, CriUint32 second);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriBool FUN_140040de0(void* object);

CriBool FUN_14003d6c0(const void* input);

#pragma function(memset)                      // the exe calls memset here rather than expanding it
void FUN_14003e6a0(void* target, const CriUint64* settings);
#pragma intrinsic(memset)

void FUN_1400427b0(void* decoderList);

void FUN_140042880(void* decoderList);

void FUN_140043610(void* trackSet);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void FUN_1400458b8(void* object);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_140042800(void* manager);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void FUN_1400469c4(void* string, const CriChar8* format, ...);
#pragma optimize("", on)

void FUN_1400478a0(void);
void FUN_1400493c0(void);
void FUN_1400479e0(void);
void FUN_14004dc70(void);
CriBool FUN_140024ff0(void);
void FUN_140026f40(CriError&);
void FUN_140026f70(void);
void FUN_140024f80(void);
void* FUN_140046324(const void*, void*, CriUint32);
void* FUN_1400464f4(const void*, void*, CriUint32);

// ==== CRI critical-section helpers ================================================================================

// The CRI lock: a critical section followed by the owning thread and the recursion depth.
struct CriLockFields
{
    RTL_CRITICAL_SECTION Section;  // 0x00
    DWORD OwnerThread;             // 0x28
    CriSint32 Depth;               // 0x2c
};

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: CRI Base was built with VS2008; this wrapper reproduces its aligned storage and initialization.
// @0x140039ea8
void* criCs_Create(void* work, CriSint32 size)
{
    FUN_1400385b8();
    memset(work, 0, (size_t)size);
    uintptr_t aligned = (uintptr_t)work;
    aligned = (aligned + 7) & ~(uintptr_t)7;
    LPCRITICAL_SECTION section = (LPCRITICAL_SECTION)aligned;
    if (!criCsWin_InitializeCriticalSection(section))
    {
        FUN_140038ddc(0, "E2006081802:InitializeCriticalSection function has failed.");
        return NULL;
    }
    return section;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; this wrapper destroys and clears the caller's lock storage.
// @0x140039f00
void criCs_Destroy(LPCRITICAL_SECTION section)
{
    CriLockFields* lock = (CriLockFields*)section;
    if (lock->Depth > 0)
        FUN_140038ddc(0, "E2010062902:Critical section object will be deleted while some process is still in the section.");
    if (!criCsWin_DeleteCriticalSection(section))
    {
        FUN_140038ddc(0, "E2006081803:DeleteCriticalSection function has failed.");
        return;
    }
    memset(section, 0, 0x30);
}

// MS2-FUNCTIONAL: the CRI lock helper enters the section, reporting a failed enter, and tracks the recursive depth and
// owning thread.
// @0x140039f50
void FUN_140039f50(LPCRITICAL_SECTION section)
{
    CriLockFields* lock = (CriLockFields*)section;
    if (!FUN_140039e24(section))
    {
        FUN_140038ddc(0, "E2006081804:EnterCriticalSection function has failed.");
        return;
    }
    lock->Depth++;
    if (lock->Depth == 1)
        lock->OwnerThread = GetCurrentThreadId();
}

// MS2-FUNCTIONAL: the CRI lock helper clears its owner at the outermost exit, then reports an unbalanced leave or
// leaves the section, reporting a failed LeaveCriticalSection with the library's (Enter-worded) message.
// @0x140039f8c
void FUN_140039f8c(LPCRITICAL_SECTION section)
{
    CriLockFields* lock = (CriLockFields*)section;
    lock->Depth--;
    if (lock->Depth == 0)
        lock->OwnerThread = 0;
    if (lock->Depth < 0)
        FUN_140038ddc(0, "E2010062901:Mismatch of the number of entering and leaving to critical section.");
    else if (!FUN_140039e4c(section))
        FUN_140038ddc(0, "E2006081805:EnterCriticalSection function has failed.");
}

// MS2-FUNCTIONAL: preserves CRI's null diagnostic and serializes the old-value/store operation with its shared lock.
// @0x14003a050
CriUint32 criAtomic_TestAndSet(CriUint32* target, CriUint32 value)
{
    if (!target)
    {
        FUN_140038e24(0, "E2008071421", -2);
        return value;
    }
    FUN_140039f50((LPCRITICAL_SECTION)DAT_143b27be8);
    CriUint32 old = *target;
    *target = value;
    FUN_140039f8c((LPCRITICAL_SECTION)DAT_143b27be8);
    return old;
}

// @0x140039fc8
void criAtomic_Initialize()
{
    if (++DAT_143b27be0 == 1) {
        memset(DAT_143b27bf0, 0, (size_t)DAT_143b27be0 + 0x47);
        DAT_143b27be8 = criCs_Create(DAT_143b27bf0, 0x48);
    }
}

// @0x14003a010
void criAtomic_Finalize()
{
    if (--DAT_143b27be0 == 0) {
        if (DAT_143b27be8) {
            criCs_Destroy((LPCRITICAL_SECTION)DAT_143b27be8);
            DAT_143b27be8 = NULL;
        }
        memset(DAT_143b27bf0, 0, 0x48);
    }
}

// @0x14003a0b4
CriUint64 FUN_14003a0b4(CriUint64 value, CriUint32 alignment)
{
    CriUint64 rem = value % alignment;
    return rem ? value + alignment - rem : value;
}

// @0x14003a0f8
CriUint32 FUN_14003a0f8(CriSint32 index)
{
    return (CriUint32)((CriUint32)((index + 2 * index) * 16) + (CriUint64)0xb8);
}

// MS2-FUNCTIONAL: releases UTF table allocations and all four lazily allocated fast-search indexes.
// @0x14003a108
void criUtfRtv_Destroy(CriUint64* table)
{
    typedef void(__fastcall* FreeFn)(void*, void*);
    CriUint64* heap = (CriUint64*)table[0];
    if (table[0xc] != 0 && heap)
        ((FreeFn)heap[1])((void*)heap[2], (void*)table[0x16]);
    for (CriUint32 index = 0; index < 4; ++index)
        if (table[0xe + index * 2] != 0)
            FUN_140046d50(table, index);
    ((FreeFn)heap[1])((void*)heap[2], (void*)table[0x15]);
}
#pragma optimize("", on)

void criMvPly_AttachM2V();

void FUN_14003b880();

void FUN_14003b6e0();

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: route UTF allocations through the caller's CRI heap using its allocation mode.
// @0x14003b20c
void* FUN_14003b20c(void* heap, CriSint32 size, const CriChar8* name, CriSint32 alignment,
                    CriSint32 allocationMode)
{
    CriSint32 type = 0;
    switch (allocationMode)
    {
    case 0:
        break;
    case 1:
        type = 1;
        break;
    case 2:
        type = 2;
        break;
    case 3:
        type = 3;
        break;
    default:
        FUN_140038e24(0, "E08092651B", -3);
        break;
    }
    return FUN_140027f7c(heap, size, name, alignment, type);
}

// @0x14003b2a4
void FUN_14003b2a4(void* heap, void* memory)
{
    FUN_140027fb4(heap, memory);
}

// MS2-FUNCTIONAL: adapt the four CRI heap modes and callbacks before constructing a UTF runtime table.
// @0x14003b2ac
void* FUN_14003b2ac(void* heap, CriSint32 allocationMode, const void* data, CriUint32 size)
{
    struct HeapCallbacks { void* Allocate; void* Free; void* Heap; } callbacks;
    CriSint32 type = 0;
    switch (allocationMode)
    {
    case 0:
        break;
    case 1:
        type = 1;
        break;
    case 2:
        type = 2;
        break;
    case 3:
        type = 3;
        break;
    default:
        FUN_140038e24(0, "E08092650B", -3);
        break;
    }
    callbacks.Allocate = (void*)FUN_14003b20c;
    callbacks.Free = (void*)FUN_14003b2a4;
    callbacks.Heap = heap;
    return FUN_14003a1a0(&callbacks, (CriUint32)type, data, size);
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: allocate the UTF runtime table and field records through its CRI heap callbacks, then let the
// executable's shared UTF parser populate the table layout.
// The exe reports an allocation failure only when this flag (0x143b27c38) is set. Its only writer, the setter at
// 0x14003a0ac, has no callers, so the flag stays 0 and the failures return NULL without an error report.
static CriSint32 s_nUtfRtvReportAllocError = 0;

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// @0x14003a1a0
void* FUN_14003a1a0(void* callbackBlock, CriUint32 allocationMode, const void* data, CriUint32 size)
{
    typedef void* (*AllocateFn)(void*, CriSint32, const CriChar8*, CriSint32, CriSint32);
    typedef void (*FreeFn)(void*, void*);
    struct Callbacks { AllocateFn Allocate; FreeFn Free; void* Context; };
    struct RuntimeTable
    {
        void* Self;
        Callbacks Init;
        CriUint32 Flags, Reserved24;
        const CriUint8* Base;
        CriUint32 Size, Reserved34;
        const CriUint8* RecordData;
        const CriUint8* StringData;
        const CriUint8* BlobData;
        const CriUint8* Reserved50;
        CriUint16 FieldCount, RecordSize;
        CriUint32 RecordCount;
        void* Columns;
        CriUint8 Slots[0x40];
        void* Context;
        void* SecondaryAllocation;
    };
    if (!callbackBlock)
    {
        FUN_140038e24(0, "E06100303", -2);
        return NULL;
    }

    Callbacks* callbacks = (Callbacks*)callbackBlock;
    CriUint8* rawTable = (CriUint8*)callbacks->Allocate(callbacks->Context, 0xb8, "@UTF1", 0x10,
                                                        (CriSint32)allocationMode);
    if (!rawTable)
    {
        if (s_nUtfRtvReportAllocError)
            FUN_140038e24(0, "E06100310", -3);
        return NULL;
    }

    memset(rawTable, 0, 0xb8);
    void* tableMemory = rawTable;
    size_t tableSpace = 0xb8;
    RuntimeTable* table = (RuntimeTable*)std::align(0x10, sizeof(RuntimeTable), tableMemory, tableSpace);
    CriUint32 fieldCount = FUN_1400472c0((const CriUint8*)data, size);
    CriUint32 recordsSize = fieldCount * 0x30;
    CriUint8* rawRecords = (CriUint8*)callbacks->Allocate(callbacks->Context, (CriSint32)recordsSize,
                                                           "@UTF2", 0x10, (CriSint32)allocationMode);
    if (rawRecords)
    {
        memset(rawRecords, 0, recordsSize);
        void* recordsMemory = rawRecords;
        size_t recordsSpace = recordsSize;
        void* records = std::align(0x10, recordsSize, recordsMemory, recordsSpace);
        if (FUN_140046e04(table, rawTable, fieldCount, records, rawRecords, data, size,
                          callbackBlock, allocationMode))
            return table;
        criUtfRtv_Destroy((CriUint64*)table);
        return NULL;
    }

    table->Self = &table->Init;
    table->Init = *callbacks;
    table->Flags = allocationMode;
    table->Columns = NULL;
    table->Context = rawTable;
    table->SecondaryAllocation = NULL;
    criUtfRtv_Destroy((CriUint64*)table);
    if (s_nUtfRtvReportAllocError)
        FUN_140038e24(0, "E06100312", -3);
    return NULL;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void CriMv::InitializeMana(CriError& error);

const void** FUN_14003bed0();

const void** FUN_14003bf10();
#pragma optimize("", on)

// ==== CRI UTF heap callback helpers ================================================================================

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: this callback forwarder uses the executable's two-word heap interface.
// @0x14003a0d0
void* criUtfHeap_Alloc(void* heap, CriUint32 size, const char* tag, CriSint32 align, CriSint32 flags)
{
    void** slots = (void**)heap;
    return ((void*(__fastcall*)(void*, CriUint32, const char*, CriSint32, CriSint32))slots[0])(slots[2], size, tag, align, flags);
}

// MS2-FUNCTIONAL: this callback forwarder uses the executable's three-word UTF heap interface.
// @0x14003a0ec
void FUN_14003a0ec(void* heap, void* p)
{
    void** slots = (void**)heap;
    ((void(__fastcall*)(void*, void*))slots[1])(slots[2], p);
}

// MS2-FUNCTIONAL: this callback forwarder uses the executable's two-word heap interface.
// @0x14003a184
void* FUN_14003a184(void* heap, CriUint32 size, const char* tag, CriSint32 align)
{
    void** slots = (void**)heap;
    return ((void*(__fastcall*)(void*, CriUint32, const char*, CriSint32, CriSint32))slots[0])(slots[2], size, tag, align, 1);
}
#pragma optimize("", on)

// ==== CRI UTF runtime table field accessors ========================================================================

static inline CriUint32 criUtfReadBE32(const CriUint8* p)
{
    return ((CriUint32)p[0] << 24) | ((CriUint32)p[1] << 16) | ((CriUint32)p[2] << 8) | p[3];
}

static inline CriUint64 criUtfReadBE64(const CriUint8* p)
{
    return ((CriUint64)criUtfReadBE32(p) << 32) | criUtfReadBE32(p + 4);
}

static inline const CriUint8* criUtfRecordAddr(const CriUtfRtvView* table, CriUint32 row, const CriUtfRtvColumn* col)
{
    return table->RecordData + (CriUint32)table->RecordSize * row + col->DataOffset;
}

static inline const CriUint8* criUtfGetRecordField(const CriUtfRtvView* table, CriUint32 row,
                                                    CriUint32 field, const CriUtfRtvColumn** column)
{
    const CriUtfRtvColumn* col = &table->Columns[field];
    *column = col;
    if (!col->IsRecordField || row >= table->RecordCount)
        return NULL;
    return table->RecordData + (CriUint32)table->RecordSize * row + col->DataOffset;
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
#pragma function(strcmp)                      // the exe calls strcmp here rather than expanding it
// MS2-FUNCTIONAL: the CRI table library was built with VS2008; preserve its field-name scan and 0xffffffff sentinel.
// @0x14003a3e0
CriUint32 criUtfRtv_ConvFieldNameToNo(const CriUtfRtvView* table, const CriChar8* name)
{
    CriSint32 i;
    for (i = 0; i < table->FieldCount; ++i)
        if (strcmp(name, table->Columns[i].Name) == 0)
            break;
    if (i == table->FieldCount)
        i = -1;
    return (CriUint32)i;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; this accessor reads the table's row count.
// @0x14003a45c
CriUint32 FUN_14003a45c(const CriUtfRtvView* table)
{
    return table->RecordCount;
}

// MS2-FUNCTIONAL: use the cached sorted row index to find a UTF string key by binary search.
// @0x14003aeb4
CriUint32 FUN_14003aeb4(const CriUtfRtvView* table, CriUint32 slotIndex, const CriChar8* name)
{
    CriUint32 low, high;
    const CriUint32* rows = table->Slots[slotIndex].SortedRows;
    CriUint32 key = table->Slots[slotIndex].Key;
    low = 0;
    high = table->RecordCount;
    for (;;)
    {
        CriUint32 middle = (high + low - 1) >> 1;
        int order = strcmp(criUtfRtv_GetDataStr(table, rows[middle], key), name);
        if (order == 0)
            return rows[middle];
        if (order > 0)
            high = middle;
        else
            low = middle + 1;
        if (low == high)
            return 0xffffffff;
    }
}
#pragma intrinsic(strcmp)

// MS2-FUNCTIONAL: CRI Base was built with VS2008; field types 0/2/4 read the executable's byte positions.
// @0x14003a460
CriUint8 criUtfRtv_GetDataUint8(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col = &table->Columns[field];
    CriUint8 result = 0;
    if (col->IsRecordField && row < table->RecordCount)
    {
        const CriUint8* p = table->RecordData + (CriUint32)table->RecordSize * row + col->DataOffset;
        switch (col->Type)
        {
        case 0:
        case 1:
            result = p[0];
            break;
        case 2:
        case 3:
            result = p[1];
            break;
        case 4:
        case 5:
            result = p[3];
            break;
        }
    }
    else if (col->HasDefault)
    {
        switch (col->Type)
        {
        case 0:
        case 1:
            result = (CriUint8)col->DefaultValue[1];
            break;
        case 2:
        case 3:
            result = (CriUint8)(CriUint16)col->DefaultValue[1];
            break;
        case 4:
        case 5:
            result = (CriUint8)(CriUint32)col->DefaultValue[1];
            break;
        }
    }
    return result;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; this accessor decodes stored integers in network byte order.
// @0x14003a58c
CriUint32 criUtfRtv_GetDataUint32(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col = &table->Columns[field];
    CriUint32 result = 0;
    if (col->IsRecordField && row < table->RecordCount)
    {
        const CriUint8* p = table->RecordData + (CriUint32)table->RecordSize * row + col->DataOffset;
        switch (col->Type)
        {
        case 0:
        case 1:
            result = p[0];
            break;
        case 2:
        case 3:
            result = ((CriUint32)p[0] << 8) | p[1];
            break;
        case 4:
        case 5:
            result = criUtfReadBE32(p);
            break;
        }
    }
    else if (col->HasDefault)
    {
        switch (col->Type)
        {
        case 0:
        case 1:
            result = (CriUint8)col->DefaultValue[1];
            break;
        case 2:
        case 3:
            result = (CriUint16)col->DefaultValue[1];
            break;
        case 4:
        case 5:
            result = (CriUint32)col->DefaultValue[1];
            break;
        }
    }
    return result;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; this accessor reads 64-bit big-endian record fields.
// @0x14003a648
CriUint64 criUtfRtv_GetDataUint64(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col;
    const CriUint8* p = criUtfGetRecordField(table, row, field, &col);
    return p ? criUtfReadBE64(p) : (col->HasDefault ? col->DefaultValue[1] : 0);
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; decode the record's big-endian IEEE single precision bits.
// @0x14003a6e8
CriFloat32 criUtfRtv_GetDataFloat32(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col = &table->Columns[field];
    if (col->IsRecordField && row < table->RecordCount)
    {
        // the exe reuses the field argument's home slot for the bits
        field = criUtfReadBE32(table->RecordData + (CriUint32)table->RecordSize * row + col->DataOffset);
        return *(const CriFloat32*)&field;
    }
    if (col->HasDefault)
        return *(const CriFloat32*)&col->DefaultValue[1];
    return 0.0f;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; decode the record's big-endian IEEE double precision bits.
// @0x14003a754
double criUtfRtv_GetDataFloat64(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col = &table->Columns[field];
    if (col->IsRecordField && row < table->RecordCount)
    {
        const CriUint8* p = table->RecordData + (CriUint32)table->RecordSize * row + col->DataOffset;
        CriUint64 bits = p[0];
        bits = (bits << 8) | p[1];
        bits = (bits << 8) | p[2];
        bits = (bits << 8) | p[3];
        bits = (bits << 8) | p[4];
        bits = (bits << 8) | p[5];
        bits = (bits << 8) | p[6];
        bits = (bits << 8) | p[7];
        return *(const double*)&bits;
    }
    if (col->HasDefault)
        return *(const double*)&col->DefaultValue[1];
    return 0.0;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; string cells hold a big-endian offset into the table string block.
// @0x14003a7f4
const CriChar8* criUtfRtv_GetDataStr(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col = &table->Columns[field];
    const CriChar8* result = NULL;
    if (col->IsRecordField && row < table->RecordCount)
    {
        CriUint32 offset = criUtfReadBE32(table->RecordData + (CriUint32)table->RecordSize * row + col->DataOffset);
        if (!offset)
            return NULL;
        return (const CriChar8*)(table->StringData + offset);
    }
    if (col->HasDefault)
        result = (const CriChar8*)col->DefaultValue[1];
    return result;
}

// MS2-FUNCTIONAL: the CRI name-based callback resolves its field, then forwards to the corresponding typed accessor.
// @0x14003a85c
CriUint32 FID_conflict_criUtfRtv_GetDataSint32Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriSint32 field = (CriSint32)criUtfRtv_ConvFieldNameToNo(table, name);
    if (field < 0)
        return 0;
    return criUtfRtv_GetDataUint32(table, row, field);
}

// MS2-FUNCTIONAL: this second CRI callback has the same executable body and forwards the resolved field to uint32.
// @0x14003a894
CriUint32 FUN_14003a894(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriSint32 field = (CriSint32)criUtfRtv_ConvFieldNameToNo(table, name);
    if (field < 0)
        return 0;
    return criUtfRtv_GetDataUint32(table, row, field);
}

// MS2-FUNCTIONAL: the CRI name-based callback resolves the field before reading a float.
// @0x14003a8cc
CriFloat32 criUtfRtv_GetDataFload32Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriSint32 field = (CriSint32)criUtfRtv_ConvFieldNameToNo(table, name);
    return field < 0 ? 0 : criUtfRtv_GetDataFloat32(table, row, field);
}

// MS2-FUNCTIONAL: the CRI name-based callback resolves the field before reading a double.
// @0x14003a904
double criUtfRtv_GetDataFloat64Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriSint32 field = (CriSint32)criUtfRtv_ConvFieldNameToNo(table, name);
    return field < 0 ? 0 : criUtfRtv_GetDataFloat64(table, row, field);
}

// MS2-FUNCTIONAL: the CRI name-based callback resolves the field before reading a string.
// @0x14003a940
const CriChar8* criUtfRtv_GetDataStrFn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriSint32 field = (CriSint32)criUtfRtv_ConvFieldNameToNo(table, name);
    if (field < 0)
        return NULL;
    return criUtfRtv_GetDataStr(table, row, field);
}

// MS2-FUNCTIONAL: the CRI name-based callback resolves the field before reading a byte.
// @0x14003a978
CriUint8 criUtfRtv_GetDataUint8Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriSint32 field = (CriSint32)criUtfRtv_ConvFieldNameToNo(table, name);
    if (field < 0)
        return 0;
    return criUtfRtv_GetDataUint8(table, row, field);
}

// MS2-FUNCTIONAL: this decoder copies the field representation into the CRI's tagged 24-byte cell value.
// @0x14003a9e4
void criUtfRtv_GetCellValFromAddr(const CriUtfRtvView* table, const CriUint8* address,
                                  CriSint32 type, CriUtfRtvCell* cell)
{
    cell->Type = (CriUint8)type;
    switch (type)
    {
    case 0: case 1:
        cell->Value[0] = address[0];
        break;
    case 2: case 3:
        *(CriUint16*)cell->Value = (CriUint16)(((CriUint32)address[0] << 8) | address[1]);
        break;
    case 4: case 5: case 8:
        *(CriUint32*)cell->Value = criUtfReadBE32(address);
        break;
    case 6: case 7: case 9:
        *(CriUint64*)cell->Value = criUtfReadBE64(address);
        break;
    case 10:
    {
        CriUint32 offset = criUtfReadBE32(address);
        *(CriUint64*)cell->Value = offset ? (CriUint64)(table->StringData + offset) : 0;
        break;
    }
    case 11:
    {
        CriUint32 offset = criUtfReadBE32(address);
        *(CriUint64*)cell->Value = (CriUint64)(table->BlobData + (CriSint32)offset);
        *(CriUint32*)(cell->Value + 8) = criUtfReadBE32(address + 4);
        break;
    }
    case 12:
        *(CriUint64*)cell->Value = criUtfReadBE64(address);
        *(CriUint64*)(cell->Value + 8) = criUtfReadBE64(address + 8);
        break;
    default:
        break;
    }
}

// MS2-FUNCTIONAL: this accessor copies the column's default triple or decodes its row cell into the caller record.
// @0x14003af50
CriBool criUtfRtv_GetCellVal(const CriUtfRtvView* table, CriUint32 row, CriUint32 field, CriUtfRtvCell* cell)
{
    const CriUtfRtvColumn* col = &table->Columns[field];
    if (!col->IsRecordField || row >= table->RecordCount)
        memcpy(cell, col->DefaultValue, sizeof(col->DefaultValue));
    else
        criUtfRtv_GetCellValFromAddr(table, table->RecordData + (CriUint32)table->RecordSize * row + col->DataOffset,
                                     col->Type, cell);
    return 1;
}

// MS2-FUNCTIONAL: decode a UTF column descriptor, its optional name, and its default cell.
// @0x14003afb0
CriUint64 FUN_14003afb0(const CriUtfRtvView* table, const CriUint8* field, CriUtfRtvColumn* column)
{
    CriUint8 flags = field[0];
    column->Type = flags & 0x0f;
    column->HasDefault = (flags >> 5) & 1;
    CriUint32 consumed = 1;
    if (flags & 0x10)
    {
        CriUint32 nameOffset = criUtfReadBE32(field + consumed);
        column->Name = nameOffset ? (const CriChar8*)(table->StringData + nameOffset) : NULL;
        consumed += 4;
    }
    else
        column->Name = NULL;

    if (flags & 0x20)
    {
        criUtfRtv_GetCellValFromAddr(table, field + consumed, column->Type,
                                     (CriUtfRtvCell*)column->DefaultValue);
        switch (column->Type)
        {
        case 0: case 1: consumed += 1; break;
        case 2: case 3: consumed += 2; break;
        case 4: case 5: case 8: case 10: consumed += 4; break;
        case 6: case 7: case 9: consumed += 8; break;
        case 11: consumed += 8; break;
        case 12: consumed += 16; break;
        default: break;
        }
    }
    else
    {
        // The exe writes only the cell's type byte (+0x18) and its first value qword (+0x20).
        ((CriUtfRtvCell*)column->DefaultValue)->Type = 0xff;
        memset((CriUint8*)column->DefaultValue + 8, 0, 8);
    }
    column->IsRecordField = (flags >> 6) & 1;
    return consumed;
}

// MS2-FUNCTIONAL: the table's 16/32-bit signed fields are summed after rounding each value up to the requested alignment.
// @0x14003aca8
CriSint32 criUtfRtv_SumWithAlignment32(const CriUtfRtvView* table, CriUint32 firstRow, CriSint32 count,
                                       CriUint32 field, CriSint32 alignment)
{
    CriSint32 rounded = alignment - 1;
    CriUint32 mask = (CriUint32)-1 - rounded;
    CriSint32 sum = 0;
    const CriUtfRtvColumn* col = &table->Columns[field];
    if (col->Type == 2)
    {
        if (!col->IsRecordField)
            return (CriSint32)(CriUint16)((CriUint16)col->DefaultValue[1] + (CriUint16)rounded & (CriUint16)mask) * count;
        const CriUint8* p = criUtfRecordAddr(table, firstRow, col);
        do
        {
            sum += (CriSint32)(((CriUint16)(p[0] << 8) | p[1]) + rounded & mask);
            p += table->RecordSize;
        } while (count--);
    }
    else if (col->Type == 4)
    {
        if (!col->IsRecordField)
            return (CriSint32)(((CriUint32)col->DefaultValue[1] + rounded) & mask) * count;
        const CriUint8* p = criUtfRecordAddr(table, firstRow, col);
        do
        {
            sum += (CriSint32)((criUtfReadBE32(p) + rounded) & mask);
            p += table->RecordSize;
        } while (count--);
    }
    return sum;
}

// MS2-FUNCTIONAL: the 64-bit variant: the same row walk and alignment rounding, summed into 64 bits.
// @0x14003adac
CriUint64 FUN_14003adac(const CriUtfRtvView* table, CriUint32 firstRow, CriSint32 count,
                        CriUint32 field, CriSint32 alignment)
{
    CriSint32 rounded = alignment - 1;
    CriUint32 mask = (CriUint32)-1 - rounded;
    CriUint64 sum = 0;
    const CriUtfRtvColumn* col = &table->Columns[field];
    if (col->Type == 2)
    {
        if (!col->IsRecordField)
            return (CriUint32)(CriUint16)((CriUint16)col->DefaultValue[1] + (CriUint16)rounded & (CriUint16)mask) * count;
        const CriUint8* p = criUtfRecordAddr(table, firstRow, col);
        do
        {
            sum += (CriUint64)(CriUint32)(((CriUint16)(p[0] << 8) | p[1]) + rounded) & (CriUint64)mask;
            p += table->RecordSize;
        } while (count--);
    }
    else if (col->Type == 4)
    {
        if (!col->IsRecordField)
            return (((CriUint32)col->DefaultValue[1] + rounded) & mask) * count;
        const CriUint8* p = criUtfRecordAddr(table, firstRow, col);
        do
        {
            sum += (CriUint64)(CriUint32)(criUtfReadBE32(p) + rounded) & (CriUint64)mask;
            p += table->RecordSize;
        } while (count--);
    }
    return sum;
}

// MS2-FUNCTIONAL: parse USF chunk ID and size as network-order dwords, requiring the minimum 16-byte header.
// @0x14003b358
CriBool criUsfCmn_GetChunkIdAndSIze(const CriUint8* data, CriUint32 size, CriUint32* id, CriUint32* chunkSize)
{
    if (size < 0x10)
    {
        *id = 0;
        *chunkSize = 0;
        return 0;
    }
    *id = criUtfReadBE32(data);
    *chunkSize = criUtfReadBE32(data + 4);
    return 1;
}

// MS2-FUNCTIONAL: create a UTF runtime table using the CRI heap callback convention.
// @0x14003b348
void* criUtfRtv_Create(void* heap, void* table, CriUint32 size)
{
    return FUN_14003b2ac(heap, 1, table, size);
}

// MS2-FUNCTIONAL: decode the executable's 0x24-byte USF standard header fields.
// @0x14003b3fc
CriUint32 criUsfCmn_ParseUsfHeaderStd(const CriUint8* data, CriUint32 size, CriUsfStandardHeader* header)
{
    CriUint8 headerSize = data[9];
    if (size <= 0x0f || headerSize == 0 || headerSize > size)
        return 0;
    // The chunk id, size, offset word and the four trailing dwords are big-endian in the stream;
    // the exe stores them byte-swapped so callers read native integers.
    CriUint8* out = header->Data;
    CriUint32 value = criUtfReadBE32(data);
    memcpy(out, &value, 4);
    value = criUtfReadBE32(data + 4);
    memcpy(out + 4, &value, 4);
    out[8] = data[8]; out[9] = data[9];
    CriUint16 offset = (CriUint16)(((CriUint32)data[10] << 8) | data[11]);
    memcpy(out + 10, &offset, 2);
    out[12] = data[12]; out[13] = data[13]; out[14] = data[14];
    out[15] = data[15] & 3;
    out[16] = data[15] >> 4;
    for (CriUint32 i = 0; i < 4; ++i)
    {
        value = criUtfReadBE32(data + 0x10 + i * 4);
        memcpy(out + 0x14 + i * 4, &value, 4);
    }
    return headerSize;
}

// MS2-FUNCTIONAL: return the payload after the variable USF header and remove its embedded header-size fields.
// @0x14003b674
const CriUint8* criUsfCmn_GetContents(const CriUint8* data, CriUint32 size, CriSint32* contentSize)
{
    CriUint32 id, chunkSize;
    *contentSize = 0;
    if (criUsfCmn_GetChunkIdAndSIze(data, size, &id, &chunkSize) && size >= 0x10)
    {
        CriUint8 headerSize = data[9];
        CriUint16 offset = (CriUint16)((data[10] << 8) | data[11]);
        *contentSize = (CriSint32)(chunkSize - offset - headerSize);
        return data + (headerSize + 8);
    }
    return NULL;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriSint32 criVmpv_CalcMovieHandleWork(CriSint32 count);

CriBool FUN_14003bf80(CriUint32 count, void* work, CriUint32 workSize);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriUint32 criVmpv_GetMaxNumberOfHandles(void);

void* FUN_14003c060(CriUint32* count);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriSint32 decideInternalFramePoolNum(CriSint32 count);

void criVmpv_SetProcessorMask(void* handle, CriUint32 mask);

struct CriPostParameter
{
    CriSint32 Horizontal;
    CriSint32 Vertical;
    CriSint32 Magic;
};

void FUN_14003ca00(void* context, CriSint32 count, const CriSint32* horizontal,
                   const CriSint32* vertical);

// The VMPV handle fields read and written by the /Od accessors below.
struct CriVmpvHnFields
{
    CriUint8 Reserved00[0x18];
    CriSint32 Status;                       // 0x18
    CriUint8 Reserved1C[4];
    CriUint32 FrameReady;                   // 0x20
    CriUint8 Reserved24[0x14];
    CriUint32 FrameRate;                    // 0x38
};

CriSint32 criVmpv_GetStatus(const void* handle);

CriBool createMpvHn(void* handle, void* heap, CriUint32 width, CriUint32 height, CriUint32 frames);

void* FUN_14003c390(void* heap, const CriUint32* config);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_14003c130(void);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriSint32 FUN_14003c190(CriSint32 width, CriSint32 height, CriSint32 requestedFrames);

void FUN_14003cae0(void* handle);

void FUN_14003cdd0(void* handle);

void FUN_14003cca0(void* handle);

void FUN_14003d550(void* handle);

void FUN_14003d4b0(void* handle, void* videoBuffer, void* alphaBuffer);

void FUN_14003d500(void* handle, void* videoBuffer, void* alphaBuffer);

void* FUN_14003d940(void* handle);

void FUN_14003d970(void* handle);

CriUint32 criVdecCmn_GetNumPictureData(const void* decoder);
#pragma optimize("", on)

CriSint32 FUN_1400532e0(CriSint32 count);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriSint32 FUN_140042150(const void* decoder, const CriUint32* config);
#pragma optimize("", on)

void FUN_14257da20(void*, void*);
CriUint32 FUN_14257c0c0(void*);
void FUN_14257c050(void*, CriUint32, void*);

void* FUN_140041910(void** decoderObject, void** mediaInterface);

void FUN_140041390(void* owner, void* outputSet);

// A CRI decoder interface wrapper: the decoder object and its table of entry points.
struct CriDecoderWrapper
{
    void* Object;
    void** Table;
};

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriSint32 FUN_140043cb0(void* decoder);

void FUN_140043d00(void* decoder);

CriBool FUN_140043d40(void* decoder);

void FUN_140043d90(void* decoder);

void FUN_140043dd0(void* decoder);

void FUN_140043e20(void* decoder);

CriSint32 FUN_140043e60(void* decoder);

CriUint32 criAlphaDec_GetNumDecPool(void* decoder);

void* FUN_140043f10(void* decoder, void* frameInfo);

CriBool criAlphaDec_CopyAlphaFrameBuffer(void* decoder, void* buffers, void* frameInfo);

void FUN_140043be0(void* decoder);

void* FUN_140043fe0(void* decoder, void* frameInfo);

CriSint32 FUN_140044630(void* decoder);

CriBool FUN_1400446c0(void* decoder);

void FUN_140044710(void* decoder);

void FUN_140044750(void* decoder);

void FUN_140044790(void* decoder);

CriSint32 FUN_1400447d0(void* decoder);

CriUint32 criVdec_GetNumDecPool(void* decoder);

void* criVdec_GetNextFrameInfo(void* decoder, void* frameInfo);

CriBool criVdec_GetFrameBuffer(void* decoder, void* format, CriUint32 mode, void* output);

CriBool criVdec_CopyFrameYuvBuffers(void* decoder, void* output, void* frameInfo);

void* FUN_1400449c0(void* decoder, void* frameInfo);

void FUN_140044a30(void* decoder, void* frameInfo);

void criVdec_GetVideoParameter(void* decoder, void* parameters);

void FUN_140044ae0(void* decoder);

void FUN_140044b20(void* decoder, CriUint32 stream, void* offset, void* timestamp);

void FUN_140044b90(void* decoder, void* a, void* b, void* c, void* d, void* e);

void FUN_140044c10(void* decoder, CriUint32 mask);

void FUN_140044c60(void* decoder, CriUint32 position, CriUint32 mode);

void FUN_140044cc0(void* decoder, void* callback, void* userData);

void criVdec_SetProcessorMask(void* decoder, CriUint32 mask);

void FUN_140044390(const void* decoderInterface);

void FUN_1400443d0(void* decoderInterface);

void criVdec_SetDlgPara(void* decoder, CriUint32 mode, void* first, void* second);

void FUN_140044de0(void* decoder, void* first, void* second);

void* FUN_140044e40(void* decoder);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void criUsfDmx_SetOutputSj(void* demux, CriUint32 index, void* stream, CriUint32 flags, CriSint32 limit);

CriSint32 criSjUni_CalculateWorkSize(const CriSint32* config);

CriSint32 criUsfDmx_CalculateWorkSizeWithWork(CriSint32 outputCount);

CriSint32 criSjRbf_CalculateWorkSize(const CriSint32* config);

void FUN_140045fdc(void* ringBuffer);

void FUN_140046014(void* ringBuffer);

void FUN_14004602c(void* ringBuffer);

void criSjRbf_Reset(void* ringBuffer);

void criSjRbf_GetChunk(void* ringBuffer, CriSint32 direction, CriUint32 requested, void* result);

void* FUN_14004592c(void* streamJoint);

void FUN_140045964(void* streamJoint, void* chunk);

void FUN_140045998(void* streamJoint);

CriSint32 criSjUni_GetNumChainPool(void* streamJoint);

#pragma function(memset)
void criSjUni_Reset(void* streamJoint);
#pragma intrinsic(memset)
#pragma optimize("", on)

// FUN_140041a10's body; the exe inlines it into the outer timer's getters
static __forceinline void criTimer_GetTime(const void* state, CriSint64* elapsed, CriUint64* timestamp)
{
    struct InnerTimer { CriUint64 Start; CriUint64 Stop; CriUint8 Running; };
    const InnerTimer* timer = (const InnerTimer*)state;
    *timestamp = FUN_1425e3510();
    if (timer->Running)
        *elapsed = FUN_1425e3560() - timer->Start;
    else
        *elapsed = timer->Stop - timer->Start;
}

void FUN_140041a10(const void* state, CriSint64* elapsed, CriUint64* timestamp);

void FUN_140041ad0(void* state, CriUint8 paused);

void FUN_140041b50(void* state, CriSint64* elapsed, CriUint64* timestamp);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_140041df0(void* manager, void* callback, void* userData);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_140041e30(void* manager, void* callback, void* userData, CriSint32 stream);

void FUN_140041030(void* handle, CriUint32 width, CriUint32 height);

void FUN_140041080(void* handle, void* first, void* second);

void FUN_140041150(void* handle, void* unused);

void FUN_140043a20(const void* decoder);

void FUN_140043a50(void* decoder);

CriSint32 FUN_140043a80(void* decoder, CriSint32 a, CriSint32 b, CriSint32 c);

void* FUN_140043c50(void** decoder);

CriBool FUN_14003e110(void* handle, void* output, void** frame);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_14003e710(void* unused, void* output);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_14003e820(void* handle, CriUint32 frameRate);

void FUN_14003e750(void* handle, CriSint32 frame, CriUint64* timestamp, CriUint64* offset);

void FUN_14003b720(CriMvSubAudioTrackState* state, CriSint32 count,
                   const CriSint32* trackIds, const CriSint32* trackValues);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: search the table's 32-bit record field in row order and return its first matching row.
// @0x14003b168
CriUint32 criUtfRtv_SearchRecNoByUint32(const CriUtfRtvView* table, CriUint32 field, CriUint32 value)
{
    // a CriUtfRtvCell without byte arrays, which the exe does not treat as a /GS buffer
    struct Cell { CriUint64 Type; CriUint32 Value; CriUint32 Reserved0C; CriUint64 Reserved10; } cell;
    CriUint32 size = table->RecordSize;
    CriUint32 row = 0;
    CriUint32 result = 0xffffffff;
    const CriUtfRtvColumn* col = &table->Columns[field];
    CriUint32 offset = col->DataOffset;
    if (col->IsRecordField && col->Type == 4)
    {
        for (; row < table->RecordCount; ++row)
        {
            criUtfRtv_GetCellValFromAddr(table, table->RecordData + size * row + offset, 4, (CriUtfRtvCell*)&cell);
            if (value == cell.Value)
            {
                result = row;
                break;
            }
        }
    }
    return result;
}

// MS2-FUNCTIONAL: find the row whose string record field equals value. A sorted index slot on the field
// is searched through FUN_14003aeb4; otherwise the rows are scanned in order and RecordCount means no match.
// @0x14003b094
#pragma function(strcmp)                      // the exe calls strcmp here rather than expanding it
CriUint32 criUtfRtv_SearchRecNoByStr(const CriUtfRtvView* table, CriUint32 field, const CriChar8* value)
{
    // a CriUtfRtvCell without byte arrays, which the exe does not treat as a /GS buffer
    struct Cell { CriUint64 Type; const CriChar8* Value; CriUint64 Reserved10; } cell;
    CriUint32 size = table->RecordSize;
    const CriUtfRtvColumn* col = &table->Columns[field];
    CriUint32 offset = col->DataOffset;
    const CriUint8* records = table->RecordData;
    CriUint32 row;
    CriUint32 slot;
    if (col->IsRecordField && col->Type == 10)
    {
        for (slot = 0; slot < 4; ++slot)
            if (table->Slots[slot].Key == field)
                break;
        if (slot < 4)
            return FUN_14003aeb4(table, slot, value);
        for (row = 0; row < table->RecordCount; ++row)
        {
            criUtfRtv_GetCellValFromAddr(table, records + size * row + offset, col->Type, (CriUtfRtvCell*)&cell);
            if (strcmp(value, cell.Value) == 0)
                break;
        }
    }
    else
        row = 0xffffffff;
    return row;
}
#pragma intrinsic(strcmp)
#pragma optimize("", on)

void MPVDEC_ResetMv(CriMpvDecoderState* state);

void MPVDEC_ResetDc(CriMpvDecoderState* state);

void mpvumc_SubMbadr(CriMpvDecoderState* state, CriSint32 run);

void mpvumc_IncreMbadr(CriMpvDecoderState* state);

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
CriSint32 FUN_140044f8c(void* object);

void FUN_140044f9c(void* object);

void FUN_140044fa8(void* object, void* value);

void FUN_140044fd8(void* object, CriUint8 value);

void FUN_140044fdc(void* object);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_140044050(CriUint64* pair, void* value);

CriUint32 FUN_1400440a0(CriUint64* pair, void* first, CriUint32 second, void* third);

void FUN_140044120(CriUint64* pair);

void FUN_140044160(CriUint64* pair, CriUint32 option);

void FUN_1400441b0(CriUint64* pair, CriUint32 first, CriUint32 second);

void FUN_140044210(CriUint64* pair, void* first, void* second);

void FUN_140044270(CriUint64* pair, CriUint32 option);

void FUN_1400442c0(CriUint64* pair, CriUint32 option, void* first, void* second);

void FUN_140044330(CriUint64* pair, void* first, void* second);

CriSint32 FUN_140044400(void* callbackPair, CriUint32 first, CriUint32 second, CriUint32 third);

CriUint64 FUN_1400445d0(CriUint64* pair);

void FUN_140044680(CriUint64* pair);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void FUN_140044ea8(void);

void FUN_1400459bc(void* object);

void FUN_1400459d4(void* object);

void FUN_140046798(void* object);

void FUN_140046784(void* object);

void criSj_SplitChunk(const void* source, CriUint32 maximum, void* prefix, void* suffix);

void criSj_PutInputChunk(void* streamJoint, const void* chunk, CriUint32 size);

void criSj_PutOutputChunk(void* streamJoint, const void* chunk, CriUint32 size);

void FUN_1400467a0(void* object, CriSint32 operation = 0, CriUint32 limit = 0, void* output = NULL);

void FUN_1400467a8(void* object, CriSint32 operation = 0, void* chunk = NULL);

void FUN_1400467b0(void* object, CriSint32 operation = 0, void* chunk = NULL);

CriSint32 FUN_1400467b8(void* object, CriSint32 query = 0);

void FUN_140046804(void* object, void* value);

char* FUN_140046944(char* dst, size_t size, const char* src);

char* FUN_14004695c(char* dst, size_t size, const char* src, size_t count);

char* FUN_140046974(char* dst, size_t size, const char* src, size_t count);

char* FUN_14004698c(char* dst, size_t size, const char* src);
#pragma optimize("", on)

void* FUN_1400469f0(void* dst, size_t size, const void* src, size_t count);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void criMvPlyAmng_Initialize(void);

void criMvPlyAmng_Finalize(void);
#pragma optimize("", on)

void FUN_1400419d0(void* snapshot);

void FUN_1400419f0(void* timer);

void* FUN_140041bd0(void* snapshot);

void FUN_140041aa0(void* timer);

void FUN_1400412e0(void* player, CriSint32 state);

void FUN_1400412a0(void* player);

CriBool FUN_140041270(void* player);

CriBool FUN_140041220(void* player, void*, CriUint32 first, CriUint32 second);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void* FUN_1400411e0(CriUint32* size);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void FUN_1400411f8(void);
#pragma optimize("", on)

void FUN_140041250(void* object);

void FUN_1400412c0(void* object);

void FUN_140041340(void* object);

CriUint64 FUN_140041d20(void);

void FUN_140041dd0(void* heap);

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void FUN_140044e84(void);
#pragma optimize("", on)

void* FUN_140041c00(void* context);

void* FUN_140041c60(void* manager, CriUint32 flags);

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
CriSint32 FUN_140045c08(void* object, CriSint32 lane);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_140044560(CriUint64* adapter);

void FUN_140043550(CriSint32* state, void* input);

CriSint32 FUN_140041ee0(const void* player);

CriBool FUN_140043750(void* decoder, const void* operation);

void FUN_1400420b0(void* manager, void* heap);

void* FUN_140041f70(void* owner, void* heap, const void* config);

CriBool FUN_140042270(void* manager, void* owner, void* heap, const CriUint32* decoderConfig,
                      CriUint32 streamIndex, CriSint32 decoderIndex);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
#pragma function(memset)
void FUN_1400453c4(void* object);
#pragma intrinsic(memset)
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriBool FUN_140040f80(const void* packet, CriSint32 size);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
CriSint32 FUN_140046604(CriUint32 first, CriUint32 second, CriUint32 third,
                        const CriUint32* settings);

void* FUN_140046678(void* heap, CriUint32 first, CriUint32 second, CriUint32 third);

void* FUN_1400466ac(void* heap, CriUint32 first, CriUint32 second, CriUint32 third,
                   CriUint64 poolBytes);

CriSint32 FUN_1400466dc(CriUint32 first, CriUint32 second, CriUint32 third);

void* FUN_1400466fc(void* heap, CriUint32 first, CriUint32 second, CriUint32 third);

void* FUN_140046730(void* heap, CriUint32 first, CriUint32 second, CriUint32 third,
                   CriUint64 poolBytes);

void* FUN_140046760(void* heap, CriUint32 first, CriUint32 second, CriUint32 third,
                   const CriUint32* settings);

void FUN_140046170(void* ring, CriSint32 mode, CriUint64* span);
#pragma optimize("", on)

void* FUN_140041d40(void* manager);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_140040c00(void* player, void* context);

void FUN_140040cc0(void* player, CriUint32 frame, CriSint32* segmentIndex, CriSint32* delta);

void FUN_1400436d0(void* state);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void FUN_140044f28(void* object);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriUint32 FUN_140043890(void* track, void* player, CriUint32 channel, CriUint32 maximum);

void FUN_140043970(void* track, void* player);

void FUN_140042700(void* trackSet, void* player);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
struct CriSjChunk { void* Data; CriUint32 Size, Reserved0c; };
struct CriSjChunkNode { CriSjChunkNode* Next; CriUint64 Reserved08; CriSjChunk Chunk; };
struct CriSjRingQueue
{
    CriUint8 Reserved00[0x10];
    LPCRITICAL_SECTION Lock;
    CriSint32 Mode;
    CriUint32 Reserved1c;
    CriSjChunkNode* Heads[5];
    CriSjChunkNode* FreeList;
};

// pops a cleared node off the queue's free list (NULL when it is empty); inlined into FUN_140045d34 and FUN_140045e04.
// The node is taken back from memset's result, so the callers re-test it after the clear, as the exe does.
static __forceinline CriSjChunkNode* criSjRbf_PopFreeNode(CriSjRingQueue* queue)
{
    CriSjChunkNode* node = queue->FreeList;
    if (node)
    {
        queue->FreeList = node->Next;
        node = (CriSjChunkNode*)memset(node, 0, sizeof(*node));
    }
    return node;
}

void FUN_140045c60(void* object, CriSint32 lane, CriUint32 requested, CriUint64* output);

void FUN_140045d34(void* object, CriSint32 lane, const CriUint64* input);

void FUN_140045e04(void* object, CriSint32 lane, const CriUint64* input);
#pragma optimize("", on)

void FUN_14003c080(void);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_14003ef00(void* object);

void* FUN_14003e2a0(void* source, void* destination);

void* FUN_14003e5d0(void* source, void* destination);

void FUN_14003e180(void* object, const void* frame);

void FUN_140042600(void* manager, void* heap, CriSint32 index);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void* FUN_1400452b4(void* heap, CriSint32 outputCount);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_140040a20(void* player, void** inputDescriptor);

CriBool FUN_140042cf0(void* trackSet, void* operation);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void FUN_1400450c0(void* stream, CriUint32 lane, CriUint32* first, CriUint32* second,
                   CriUint32* third);

void FUN_14004624c(void* joint, CriSint32 lane, void* chunkPtr);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void* FUN_140043af0(void* implementation, void* heap, void* parameter);

void* FUN_140044470(void* implementation, void* heap, void* parameter);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void FUN_140044fe4(void* stream);
#pragma optimize("", on)

extern "C" const void* PTR_FUN_143a485d8;
extern "C" const void* PTR_FUN_143a48608;
void FUN_14002e6b0(void*, CriUint32, CriMvWorkAllocator*);
void* FUN_14002e6c0(CriMvWorkAllocator*, CriUint32, CriUint32);
void FUN_14002e6bc(CriMvWorkAllocator*);
void FUN_140038ddc(CriSint32, const CriChar8*);

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void* FUN_140045eec(const void* config, void* work, CriSint32 workSize);

void* FUN_1400459ec(const void* config, void* work, CriSint32 workSize);
#pragma optimize("", on)


void FUN_1400314a0(void*);
CriSint32 FUN_14003efc0(void*);

namespace
{
// Video player (VMPV handle) fields touched by the queue helpers below.
struct CriVideoQueueFields
{
    CriUint8 Reserved00[0x18];
    CriSint32 Status;
    CriSint32 Busy;
    CriSint32 Mode;
    CriSint32 Running;
    CriUint8 Reserved28[0x28];
    CriUint32 UnitSize;
    CriUint8 Reserved54[4];
    void* Queue;
    void* Pending;
    CriUint32 PendingSize;
    CriUint8 Reserved6c[4];
    void* Cursor;
    CriUint8 Reserved78[8];
    void* Window;
    void* WindowNext;
    void* WindowEnd;
    CriUint16 Flags;
    CriUint16 FlagsHigh;
    CriUint8 Reserved9c[0x14];
    void* Staged;
    CriUint8 Reserveda8[0xc8];
    void* InputQueue;
    CriUint32 PictureCount;
    CriUint8 Reserved18c[4];
    CriUint32 Decoded;
    CriUint32 Threshold;
};
}

static_assert(offsetof(CriVideoQueueFields, Queue) == 0x58 && offsetof(CriVideoQueueFields, Staged) == 0xb0 &&
              offsetof(CriVideoQueueFields, InputQueue) == 0x180 && offsetof(CriVideoQueueFields, Threshold) == 0x194 &&
              offsetof(CriVideoQueueFields, Decoded) == 0x190 && offsetof(CriVideoQueueFields, UnitSize) == 0x50, "layout");

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriSint32 FUN_14003ed40(void* player);

void FUN_140040a90(void* player);

void FUN_140040e40(void* player, CriUint32* total, CriUint32* first, CriSint32* second, CriUint32* third,
                   CriUint32* fourth);

CriUint32 FUN_140043420(void* decoder, void* player, CriUint32 channels);

CriSint32 FUN_14003ec30(void* player);
#pragma optimize("", on)

void FUN_1400414f0(void* handle);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_14003d720(void* player);
#pragma optimize("", on)

extern "C" CriUint32 DAT_143b27c3c;
void FUN_140049300(const void*, void*, void*);
void FUN_14004c0c0(const void*, void*, void*);
void FUN_14004cbb0(const void*, void*, void*);
void FUN_140035090(void*);
CriBool FUN_140035560(void*);
void FUN_1400351c0(void*);
CriUint32 FUN_1400358d0(void*, const void*);
void FUN_1400359e0(void*, const void*);
void FUN_140035260(void*, void*, const void*, CriUint64, CriUint32);
void FUN_140035480(void*, void*, const void*);
void FUN_14003bb60(void*, CriUint8*, CriUint32, CriUint32, const void*, const void*, const void*);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_14003bb60(void* player, CriUint8* dstbuf, CriUint32 dstpitch, CriUint32 dstbufsize, const void* srcbufs,
                   const void* src_vinf, const void* src_ainf);
#pragma optimize("", on)

CriBool FUN_14003b8b0(void*, CriUint8*, CriUint32, CriUint32, void*);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriBool FUN_14003b8b0(void* player, CriUint8* imagebuf, CriUint32 pitch, CriUint32 bufsize, void* frameinfo);
#pragma optimize("", on)

extern "C" CriUint32 DAT_143b27c78;

namespace
{
// 0xb0-byte decoded-frame description copied out of a queue record; the plane table starts at +0x38.
struct CriDecodedPlane { CriUint8* Data; CriUint32 Width; CriUint32 Height; CriUint32 Pitch; CriUint32 Reserved; };
struct CriDecodedFrame
{
    CriUint8* Base;
    CriUint8 Reserved08[4];
    CriUint32 Width;
    CriUint32 Height;
    CriUint8 Reserved14[0x24];
    CriUint32 PlaneCount;
    CriUint32 Reserved3c;
    CriDecodedPlane Planes[3];
    CriUint8 Reserved88[0x28];
};
struct CriFrameRecord { CriUint8* Key; CriUint8 Reserved08[8]; CriDecodedFrame Frame; CriUint32 Mode; };
struct CriVideoFrameSource
{
    CriUint8 Reserved00[0x34];
    CriUint32 ChannelCount;
    CriUint8 Reserved38[0x20];
    void* Queue;
    CriUint8 Reserved60[0x30];
    void* Window;
    CriUint8 Reserved98[0xf8];
    CriUint32 Position;
};
static_assert(sizeof(CriDecodedFrame) == 0xb0 && offsetof(CriFrameRecord, Mode) == 0xc0 &&
              offsetof(CriVideoFrameSource, Queue) == 0x58 && offsetof(CriVideoFrameSource, Window) == 0x90 &&
              offsetof(CriVideoFrameSource, Position) == 0x190, "layout");

// Describe the tiled YUV420 layout of a decoded frame whose picture memory starts at frame->Base.
inline void CriDescribeTiledFrame(CriDecodedFrame* frame)
{
    CriUint32 width = frame->Width;
    CriUint32 height = frame->Height;
    CriUint32 alignedWidth = ((width + 0xf) / 0x10) * 0x10;
    CriSint16 lumaPitch = (CriSint16)((alignedWidth + 0x7f) / 0x80) * 0x80;
    CriSint16 chromaPitch = (CriSint16)((alignedWidth / 2 + 0x7f) / 0x80) * 0x80;
    CriUint8* base = frame->Base;
    CriUint8* lumaEnd = base + (CriUint64)(((alignedWidth + 0x7f) / 0x80) * 0x80 * ((height + 0x1f) / 0x20) * 0x20);
    CriUint8* chromaEnd = lumaEnd + (CriUint64)(((alignedWidth / 2 + 0x7f) / 0x80) * 0x80 *
                                                ((((height + 0x1f) / 0x20) * 0x20) / 2));
    frame->PlaneCount = 3;
    frame->Planes[0].Data = base;
    frame->Planes[0].Width = width;
    frame->Planes[0].Height = height;
    frame->Planes[0].Pitch = (CriUint32)(CriSint32)lumaPitch;
    frame->Planes[1].Data = lumaEnd;
    frame->Planes[1].Width = width / 2;
    frame->Planes[1].Height = height / 2;
    frame->Planes[1].Pitch = (CriUint32)(CriSint32)chromaPitch;
    frame->Planes[2].Data = chromaEnd;
    frame->Planes[2].Width = width / 2;
    frame->Planes[2].Height = height / 2;
    frame->Planes[2].Pitch = (CriUint32)(CriSint32)chromaPitch;
}
}

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void* FUN_14003da40(void* player, void* output);

void* FUN_14003dd50(void* player, void* output);

CriBool FUN_14003e370(void* player, void* destination, void* source);

CriSint32 FUN_14003cff0(void* player);

void FUN_14003e850(void* player, void* source, void* destination);
#pragma optimize("", on)

void* FUN_1400530c0(const void*, CriUint32, CriUint32);
CriBool FUN_140026dd0(void*, CriUint8*, CriUint32, CriUint32, void*, void*);
void FUN_140021c90(void*, CriSint32, void*);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriBool FUN_1400405d0(void* firstChunk, void* secondChunk, CriUint32 offset);
#pragma optimize("", on)

void FUN_1400436d0(void*);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriUint32 FUN_140042ba0(void* trackSet, void* chunk, CriSint32 id, CriSint32* counts);
#pragma optimize("", on)

CriUint32 FUN_140043890(void*, void*, CriUint32, CriUint32);

namespace
{
// Shared body of the 16-bit and 32-bit PCM drains: each channel queue is copied into its own output buffer.
inline CriUint32 CriDrainAudioChannels(void* decoder, void* player, CriUint32 channels, void* outputs, CriUint32 mode,
                                       CriUint32* info, CriUint32 stride)
{
    struct Decoder { CriUint8 Reserved00[0x30]; void* Queues[8]; };
    struct Player { CriUint8 Reserved00[0xb2c]; CriUint32 Rate; CriUint8 Reserveb30[0x2ec]; CriUint32 FrameSize; };
    struct Chunk { void* Data; CriUint32 Size; };
    static_assert(offsetof(Player, FrameSize) == 0xe1c, "layout");
    Decoder* source = (Decoder*)decoder;
    Player* ply = (Player*)player;
    CriUint32 frames = FUN_140043890(decoder, player, channels, mode);
    if (frames == 0)
        return 0;
    CriUint8* cursors[8];
    CriUint32 remaining[8] = {};
    for (CriUint32 channel = 0; channel < channels; ++channel)
    {
        cursors[channel] = ((CriUint8* const*)outputs)[channel];
        remaining[channel] = frames;
    }
    while (remaining[0] != 0)
    {
        for (CriUint32 channel = 0; channel < channels; ++channel)
        {
            void* queue = source->Queues[channel];
            Chunk chunk;
            FUN_1400467a0(queue, 1, remaining[channel] * ply->FrameSize, &chunk);
            if (chunk.Size != 0)
            {
                CriUint32 count = chunk.Size / ply->FrameSize;
                memcpy(cursors[channel], chunk.Data, count * ply->FrameSize);
                cursors[channel] += (CriUint64)count * stride;
                remaining[channel] -= count;
            }
            FUN_1400467b0(queue, 0, &chunk);
        }
    }
    info[0] = channels;
    info[1] = frames;
    info[2] = ply->Rate;
    return frames;
}
}

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriUint32 FUN_140042f40(void* decoder, void* player, CriUint32 channels, void* outputs, CriUint32 mode, CriUint32* info);

CriUint32 FUN_1400431a0(void* decoder, void* player, CriUint32 channels, void* outputs, CriUint32 mode, CriUint32* info);
#pragma optimize("", on)

void FUN_1400531e0(void*, const void*, void*, void*);

CriBool FUN_1400415f0(void* handle, void* planeSet);

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void* FUN_140045144(CriSint32 count, void* work, CriSint32 workSize);
#pragma optimize("", on)

const CriUint8* criUsfCmn_GetContents(const CriUint8* data, CriUint32 size, CriSint32* contentSize);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_1400428e0(void* trackSet, void* player);
#pragma optimize("", on)

CriSint32 criSjUni_GetNumChainPool(void* streamJoint);

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void FUN_140045474(void* object);
#pragma optimize("", on)

// ---- MPEG video (PSFD section) macroblock reconstruction helpers ----
extern "C" void (**DAT_143fe8248)(CriUint8*, CriUint8*, CriSint32, CriSint32, CriSint32);
extern "C" void (**DAT_143fe8250)(void*);

namespace
{
template <typename T>
inline T& CriMpvField(void* decoder, size_t offset)
{
    return *(T*)((CriUint8*)decoder + offset);
}

enum CriMpvOffset : size_t
{
    MPV_COEF_LUMA = 0x900,       // six 0x80-byte coefficient blocks
    MPV_COEF_INTRA = 0x300,      // six 0x100-byte coefficient blocks
    MPV_COEF_BASE = 0xc00,
    MPV_COEF_BASE_FIRST = 0xc40,
    MPV_BLOCK_CONTEXT = 0x1300,
    MPV_MB_WIDTH = 0x15a0,
    MPV_MB_HEIGHT = 0x15a4,
    MPV_REF0 = 0x1638,
    MPV_REF1 = 0x1658,
    MPV_CB_BASE = 0x16b0,
    MPV_CR_BASE = 0x16b8,
    MPV_LUMA_BASE = 0x16c0,
    MPV_CHROMA_STRIDE = 0x16c8,
    MPV_LUMA_STRIDE = 0x16ca,
    MPV_SKIP_FUNC = 0x1718,
    MPV_BLOCK_FUNC = 0x1738,
    MPV_EMIT_FUNC = 0x1740,
    MPV_QUANT = 0x1748,
    MPV_MV0 = 0x174c,
    MPV_MV1 = 0x1770,
    MPV_ADDRESS = 0x1794,
    MPV_ROW = 0x1798,
    MPV_COLUMN = 0x179c,
    MPV_CODED = 0x17a8,
    MPV_DC = 0x17ac,
    MPV_BLOCK_SLOTS = 0x17c8,
    MPV_DECODE_BLOCK = 0x1818,
    MPV_DECODE_INTER = 0x1820,
    MPV_TABLE_LUMA = 0x1838,
    MPV_TABLE_CHROMA = 0x1840,
    MPV_CLAMP_COUNT = 0x18ec,
};

struct CriMpvBlockEntry
{
    void* Function;
    CriUint8* Data;
    CriSint32 Stride;
    CriSint32 Reserved;
};

typedef CriSint32 (*CriMpvDecodeBlockFunc)(void*, void*);
typedef void (*CriMpvBlockFunc)(void*, void*, CriSint32);
typedef void (*CriMpvEmitFunc)(void*);
typedef void (*CriMpvSkipFunc)(void*);
}

void FUN_142ccc5f0(CriUint8* reference, CriUint8* destination, CriSint32 stride, CriSint32 stride2, CriSint32 width,
                   CriSint32 height, CriSint32 x, CriSint32 y, CriSint32 mvx, CriSint32 mvy, CriSint32 flags);

void FUN_142ccc6c0(void* decoder, CriSint32 codedBlocks, CriSint32 mode);

void FUN_142ccc850(void* decoder);

void FUN_142ccc860(void* decoder, CriSint32 run);

void FUN_142ccc8c0(void* decoder, void* referenceFrame, void* motion, CriSint32 flags);

void FUN_142ccca50(void* decoder);

void FUN_142ccca90(void* decoder);

void FUN_142cccad0(void* decoder);

void FUN_142cccb30(void* decoder, CriSint32 run);

CriSint32 FUN_142cccba0(void* decoder);

CriSint32 FUN_142cccd80(void* decoder);

CriSint32 FUN_142cccef0(void* decoder);

CriSint32 FUN_142ccd080(void* decoder);

extern "C" const CriSint16* DAT_143d74a38;
extern "C" const CriSint16* DAT_143d749c8;
extern "C" const CriSint16* DAT_143d74a30;
extern "C" const CriSint16* DAT_143d749f0;
extern "C" const CriSint16* DAT_143d749e0;
extern "C" const CriSint16* DAT_143d749d8;
extern "C" const CriSint16* DAT_143d74a08;
extern "C" const CriSint16* DAT_143d74a20;
extern "C" const CriSint16* DAT_143d74a00;
extern "C" const CriSint16* DAT_143d749f8;
extern "C" const CriSint16* DAT_143d749d0;
void FUN_140069020(const void*, CriUint32, void*, void*);
CriSint32 FUN_140051d90(void*);
void FUN_1400663f0(void* decoder);   // reads [decoder+0x1794], writes [decoder+0x18dc]

namespace
{
enum CriMpvBitOffset : size_t
{
    MPV_BITS_HIGH = 0x1280,
    MPV_BITS_LOW = 0x1284,
    MPV_BITS_POSITION = 0x1288,
    MPV_BITS_CURSOR = 0x1290,
    MPV_CHUNK = 0x1800,
    MPV_CHUNK_BIT_OFFSET = 0x1810,
    MPV_LAST_ADDRESS = 0x17a0,
    MPV_MB_FLAGS = 0x17a4,
    MPV_STOP = 0x18f0,
    MPV_ABORT = 0x17f8,
    MPV_CALLBACK_COUNTDOWN = 0x1830,
    MPV_CALLBACK_RELOAD = 0x1580,
    MPV_CALLBACK_FUNC = 0x1588,
    MPV_CALLBACK_ARG = 0x1590,
};

struct CriMpvChunk
{
    CriUint8* Data;
    CriUint32 Size;
    CriUint32 Reserved;
};

inline CriUint32 CriReadBigEndian32(const CriUint8* data)
{
    return ((CriUint32)data[0] << 24) | ((CriUint32)data[1] << 16) | ((CriUint32)data[2] << 8) | data[3];
}

typedef void (*CriMpvQueueGet)(void*, CriSint32, CriSint32, void*);
typedef void (*CriMpvQueuePut)(void*, CriSint32, void*);

// Bit window of the MPEG video decoder: a 64-bit big-endian window split over two words (High holds the next
// unread bits, Low the following 32), with Position counting the bits of High already consumed.
struct CriMpvBitReader
{
    CriUint32 High;
    CriUint32 Low;
    CriSint32 Position;
    const CriUint8* Cursor;

    void Load(void* decoder)
    {
        High = CriMpvField<CriUint32>(decoder, MPV_BITS_HIGH);
        Low = CriMpvField<CriUint32>(decoder, MPV_BITS_LOW);
        Position = CriMpvField<CriSint32>(decoder, MPV_BITS_POSITION);
        Cursor = CriMpvField<const CriUint8*>(decoder, MPV_BITS_CURSOR);
    }
    void Store(void* decoder) const
    {
        CriMpvField<CriUint32>(decoder, MPV_BITS_LOW) = Low;
        CriMpvField<CriUint32>(decoder, MPV_BITS_HIGH) = High;
        CriMpvField<CriSint32>(decoder, MPV_BITS_POSITION) = Position;
        CriMpvField<const CriUint8*>(decoder, MPV_BITS_CURSOR) = Cursor;
    }
    // Position the window at the start of a chunk, skipping extra bits past the 4-byte aligned base.
    void Start(const CriMpvChunk& chunk, CriUint32 extra)
    {
        const CriUint8* aligned = (const CriUint8*)((uintptr_t)chunk.Data & ~(uintptr_t)3);
        CriUint32 misalign = (CriUint32)(((uintptr_t)chunk.Data & 3) * 8);
        High = CriReadBigEndian32(aligned) << misalign;
        Low = CriReadBigEndian32(aligned + 4);
        Cursor = aligned + 8;
        Position = (CriSint32)(misalign + extra);
        if (Position >= 0x20)
        {
            High = Low;
            Low = CriReadBigEndian32(Cursor);
            Position -= 0x20;
            High <<= Position;
            Cursor += 4;
        }
        else
        {
            High <<= extra;
        }
    }
    CriUint32 Peek(CriSint32 count) const
    {
        CriUint32 window = High >> (32 - count);
        if (Position > 32 - count)
            window |= Low >> (64 - count - Position);
        return window;
    }
    void Consume(CriSint32 count)
    {
        Position += count;
        if (Position >= 0x20)
        {
            High = Low;
            Low = CriReadBigEndian32(Cursor);
            Position -= 0x20;
            High <<= Position;
            Cursor += 4;
        }
        else
        {
            High <<= count;
        }
    }
    CriUint32 Read(CriSint32 count)
    {
        CriUint32 value = Peek(count);
        Consume(count);
        return value;
    }
};

// One slice worth of chunk handling shared by the MPEG video slice decoders below.
struct CriMpvSlice
{
    void* Decoder;
    void* Queue;
    CriMpvBitReader Bits;

    CriMpvChunk& Chunk() const { return CriMpvField<CriMpvChunk>(Decoder, MPV_CHUNK); }
    void** Vtable() const { return *(void***)Queue; }
    void GetChunk() { ((CriMpvQueueGet)Vtable()[6])(Queue, 1, 0x7fffffff, &Chunk()); }
    // Hand back the bytes the bit reader has not reached yet and release the consumed head of the chunk.
    void ReturnUnread(CriSint32 consumed)
    {
        CriMpvChunk remaining;
        FUN_140069020(&Chunk(), (CriUint32)consumed, &Chunk(), &remaining);
        ((CriMpvQueuePut)Vtable()[8])(Queue, 0, &Chunk());
        ((CriMpvQueuePut)Vtable()[7])(Queue, 1, &remaining);
    }
    CriSint32 ConsumedBytes(CriSint32 alignedBits) const
    {
        return (CriSint32)(((CriUint32)(alignedBits >> 3)) - (CriUint32)(uintptr_t)Chunk().Data +
                           (CriUint32)(uintptr_t)Bits.Cursor - 8);
    }
    // End of the slice: give the unread bytes back and let the queue finish its chunk.
    CriSint32 Finish()
    {
        ReturnUnread(ConsumedBytes(Bits.Position + 7));
        return FUN_140051d90(Queue);
    }
    // After a macroblock: when fewer than 0x800 bytes are left in the chunk, fetch the next one.
    void Refill()
    {
        CriSint32 misaligned = Bits.Position & 7;
        CriSint32 consumed = ConsumedBytes(Bits.Position - misaligned + 7);
        if ((CriSint32)Chunk().Size - consumed > 0x800)
            return;
        ReturnUnread(consumed);
        GetChunk();
        Bits.Start(Chunk(), (CriUint32)misaligned);
    }
    // Run the periodic user callback and apply the stop conditions; returns false when the slice must end.
    bool AfterMacroblock()
    {
        if (CriMpvField<CriSint32>(Decoder, MPV_STOP) != 0 || CriMpvField<CriSint32>(Decoder, MPV_ABORT) != 0)
            return false;
        if (--CriMpvField<CriSint32>(Decoder, MPV_CALLBACK_COUNTDOWN) <= 0)
        {
            CriMpvField<CriSint32>(Decoder, MPV_CALLBACK_COUNTDOWN) = CriMpvField<CriSint32>(Decoder, MPV_CALLBACK_RELOAD);
            CriMpvField<void (*)(void*)>(Decoder, MPV_CALLBACK_FUNC)(CriMpvField<void*>(Decoder, MPV_CALLBACK_ARG));
        }
        Bits.Load(Decoder);
        Refill();
        return true;
    }
    // macroblock_address_increment: returns false at a start code or the end of the picture.
    bool ReadAddress(CriSint32 peekBits, const CriSint16* tableA, const CriSint16* tableB, CriSint32* delta)
    {
        CriSint32 previous = CriMpvField<CriSint32>(Decoder, MPV_ADDRESS);
        CriSint32 entry;
        CriSint32 increment;
        for (;;)
        {
            CriUint32 window = Bits.Peek(peekBits);
            entry = window < (1u << (peekBits - 4)) ? tableA[window] : tableB[window >> 6];
            Bits.Consume(entry & 0xf);
            increment = (CriSint32)(((CriUint32)entry >> 4) & 0x3f);
            if (increment == 0x22)
                continue;
            if (increment == 0x23)
            {
                CriMpvField<CriSint32>(Decoder, MPV_ADDRESS) += 0x21;
                continue;
            }
            if (increment == 0x24)
                return false;
            CriMpvField<CriSint32>(Decoder, MPV_ADDRESS) += increment;
            break;
        }
        CriSint32 address = CriMpvField<CriSint32>(Decoder, MPV_ADDRESS);
        CriMpvField<CriUint32>(Decoder, MPV_MB_FLAGS) = (CriUint32)entry >> 10;
        if (address > CriMpvField<CriSint32>(Decoder, MPV_LAST_ADDRESS))
            return false;
        CriSint32 step = address - previous;
        CriSint32 width = CriMpvField<CriSint32>(Decoder, MPV_MB_WIDTH);
        CriMpvField<CriSint32>(Decoder, MPV_COLUMN) += step;
        while (CriMpvField<CriSint32>(Decoder, MPV_COLUMN) >= width)
        {
            CriMpvField<CriSint32>(Decoder, MPV_COLUMN) -= width;
            CriMpvField<CriSint32>(Decoder, MPV_ROW) += 1;
            width = CriMpvField<CriSint32>(Decoder, MPV_MB_WIDTH);
        }
        *delta = step;
        return step != -2;
    }
    // Read the optional 5-bit quantiser scale selected by bit 0x10 of the macroblock flags.
    void ReadQuantiser(CriUint32 flags)
    {
        if (flags & 0x10)
            CriMpvField<CriUint32>(Decoder, MPV_QUANT) = Bits.Read(5);
    }
};
}

CriSint32 FUN_142ccb520(void* decoder, void* parameters, CriSint32* output, CriSint32* predictor);

CriSint32 FUN_142ccb000(void* decoder, void* queue);

namespace
{
typedef void (*CriMpvMacroblockFunc)(void*);
typedef void (*CriMpvSkipRunFunc)(void*, CriSint32);

// Decode the horizontal and vertical motion-vector components of one vector set; returns true on a bad code.
inline bool CriMpvReadMotion(CriMpvSlice& slice, size_t setOffset)
{
    void* decoder = slice.Decoder;
    slice.Bits.Store(decoder);
    CriSint32 horizontal = FUN_142ccb520(decoder, (CriUint8*)decoder + setOffset, (CriSint32*)((CriUint8*)decoder + setOffset + 0x18),
                                         (CriSint32*)((CriUint8*)decoder + setOffset + 0x10));
    CriSint32 vertical = FUN_142ccb520(decoder, (CriUint8*)decoder + setOffset, (CriSint32*)((CriUint8*)decoder + setOffset + 0x1c),
                                       (CriSint32*)((CriUint8*)decoder + setOffset + 0x14));
    slice.Bits.Load(decoder);
    return (horizontal | vertical) != 0;
}

// Read the 9-bit coded_block_pattern when bit 2 of the macroblock flags asks for it.
inline void CriMpvReadPattern(CriMpvSlice& slice, CriUint32 flags)
{
    if (flags & 2)
    {
        CriUint32 window = slice.Bits.Peek(9);
        CriSint32 entry = DAT_143d74a20[window];
        CriMpvField<CriSint32>(slice.Decoder, MPV_CODED) = (CriSint32)((CriUint32)entry << 16) & (CriSint32)0xfff00000;
        slice.Bits.Consume((CriUint8)entry);
    }
    else
    {
        CriMpvField<CriSint32>(slice.Decoder, MPV_CODED) = 0;
    }
}
}

CriSint32 FUN_142ccb710(void* decoder, void* queue);

CriSint32 FUN_142ccbe90(void* decoder, void* queue);

void* FUN_14004eea0(void*, CriUint32);
CriSint32 FUN_140050bd0(void*, void*, void*);
void FUN_1400511d0(void*, void*, CriUint32);
void FUN_1400511f0(void*, CriUint32, void*);
CriSint32 FUN_140052c80(void*, void*, void*);
CriSint32 FUN_140052d00(void*, void*);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriSint32 FUN_140040850(void* player, void* stream, void* second, CriSint32* consumed, void* frames);
#pragma optimize("", on)

namespace
{
// Lay out a tiled YUV420 frame (three planes) starting at base for a picture of the given size.
inline void CriMpvSetTiledFrame(void* frame, CriUint8* base, CriSint32 width, CriSint32 height)
{
    CriSint32 aligned = ((width + 0xf) / 0x10) * 0x10;
    CriSint32 lumaBlocks = (aligned + 0x7f) / 0x80;
    CriSint32 chromaBlocks = (aligned / 2 + 0x7f) / 0x80;
    CriSint32 alignedHeight = ((height + 0x1f) / 0x20) * 0x20;
    CriMpvField<CriSint16>(frame, 0x1a) = (CriSint16)(lumaBlocks * 0x80);
    CriMpvField<CriSint16>(frame, 0x18) = (CriSint16)(chromaBlocks * 0x80);
    CriMpvField<CriUint8*>(frame, 0x10) = base;
    CriMpvField<CriUint8*>(frame, 0x00) = base + (CriSint64)(lumaBlocks * 0x80 * alignedHeight);
    CriMpvField<CriUint8*>(frame, 0x08) = CriMpvField<CriUint8*>(frame, 0x00) + (CriSint64)(chromaBlocks * 0x80 * (alignedHeight / 2));
}
}

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriSint32 FUN_14003efc0(void* player);
#pragma optimize("", on)

// ---- full-exe unresolved: leaves without .pdata that data_cri / data_data_game reference as ?FUN_<va>@@YAXXZ ----

struct cri03_stream { virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0;
                      virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0;
                      virtual void v8() = 0; virtual void* Call9(long long a, long long b, long long c) = 0; };

struct cri03_host20 { void* vtbl; void* _08[3]; cri03_stream* stream; };
void* FUN_140041360(cri03_host20* self, long long a, long long b, long long c);

void FUN_140041c50(void*);

struct cri03_host08 { void* vtbl; cri03_stream* stream; };
void* FUN_140041d00(cri03_host08* self, CriSint32 a, void*, CriSint32 d);

struct cri03_kinds { void* vtbl; void* _08[3]; CriSint32 k1; CriSint32 k0; };
#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
CriSint32 FUN_140046000(cri03_kinds* self, CriSint32 kind);
#pragma optimize("", on)

// Boot tags 96/98: these address-named entry points create critical sections.
// Strong definitions prevent stale CuePoint::Resize alias rows from selecting
// an unrelated array implementation. All forms call the recovered body above.
void* FUN_140039ea8(void* work, CriSint32 size) { return criCs_Create(work, size); }
extern "C" void* FUN_140039ea8(void* work, int size) { return criCs_Create(work, size); }
void* FUN_1400385c8(void* work, CriUint32 size) { return criCs_Create(work, static_cast<CriSint32>(size)); }
extern "C" void* FUN_1400385c8(void* work, unsigned long long size) { return criCs_Create(work, static_cast<CriSint32>(size)); }
