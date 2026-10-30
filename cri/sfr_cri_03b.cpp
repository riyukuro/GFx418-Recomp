// Recovered CRI USF demuxer and stream joints from MapleStory2.exe: criUsfDmx, criSjUni, criSjRbf and criSj. In the exe
// this is a run of /Os objs whose strings sit in .rdata (0x1431b9bxxx), split from sfr_cri_03 at the obj boundary
// 0x140044e84, where the /Od criVdec obj ends.
// The CRI Movie 3.07 library was built with VS2008 SP1, and so is this unit (MS2-TOOLSET: vc9, cmake/ms2-unit-profiles.cmake):
// keep it C++03 (no auto, decltype, variadic templates, brace-init or nullptr). clang-cl compiles it as before.
// MS2-UNIT: sfr_cri_03b
// MS2-TOOLSET: vc9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140044e84-0x140046a1c .text$mn
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
// MS2-FUNCTIONAL: allocate and initialize the CRI universal stream-joint object with its executable vtable.
// @0x140046324
void* FUN_140046324(const void* config, void* heap, CriUint32 allocationMode)
{
    CriSint32 size = FUN_140045910((const CriSint32*)config) + 8; // criSjUni_CalculateWorkSize, called as the external
    void** allocation = (void**)FUN_140027f7c(heap, size, "CriSjUni", 8, (CriSint32)allocationMode);
    if (!allocation)
    {
        FUN_140038e24(0, "E09021217B", -3);
        return NULL;
    }
    *allocation = heap;
    void* object = FUN_1400459ec(config, allocation + 1, size - 8);
    if (!object)
    {
        FUN_140027fb4(heap, allocation);
        return NULL;
    }
    *(const void**)object = &PTR_FUN_143a48638;
    return object;
}

// MS2-FUNCTIONAL: allocate and initialize the CRI ring-buffer stream-joint object with its executable vtable.
// @0x1400464f4
void* FUN_1400464f4(const void* config, void* heap, CriUint32 allocationMode)
{
    CriSint32 size = FUN_140045ed0((const CriSint32*)config) + 8; // criSjRbf_CalculateWorkSize, called as the external
    void** allocation = (void**)FUN_140027f7c(heap, size, "CriSjRbf", 8, (CriSint32)allocationMode);
    if (!allocation)
    {
        FUN_140038e24(0, "E09021703B", -3);
        return NULL;
    }
    *allocation = heap;
    void* object = FUN_140045eec(config, allocation + 1, size - 8);
    if (!object)
    {
        FUN_140027fb4(heap, allocation);
        return NULL;
    }
    *(const void**)object = &PTR_FUN_143a48668;
    return object;
}

// MS2-FUNCTIONAL: construct a configured universal stream-joint from the caller's three-word settings.
// @0x1400463f4
void FUN_1400463f4(void* heap, CriUint32 first, CriUint32 second, const CriUint32* settings)
{
    CriUint32 config[3] = { settings[0], first, second };
    FUN_140046324(config, heap, settings[1]);
}

// MS2-FUNCTIONAL: construct the default universal stream-joint with the requested pool dimensions.
// @0x14004647c
void FUN_14004647c(void* heap, CriUint32 first, CriUint32 second)
{
    const CriUint32 config[3] = { 0, first, second };
    FUN_140046324(config, heap, 1);
}

// MS2-FUNCTIONAL: construct a temporary universal stream-joint with the requested pool dimensions.
// @0x1400464c8
void* FUN_1400464c8(void* heap, CriUint32 first, CriUint32 second)
{
    const CriUint32 config[3] = { 1, first, second };
    return FUN_140046324(config, heap, 1);
}

// MS2-FUNCTIONAL: create the configured ring-buffer stream-joint and preserve its 24-byte setup record.
// @0x1400465c4
void* FUN_1400465c4(void* heap, CriUint32 first, CriUint32 second, CriUint32 third,
                   CriUint64 poolBytes, const CriUint32* settings)
{
    struct JointConfig { CriUint32 Mode; CriUint32 First; CriUint32 Second; CriUint32 Third; CriUint64 PoolBytes; };
    JointConfig config;
    config.Mode = settings[0];
    config.First = first;
    config.Second = second;
    config.Third = third;
    config.PoolBytes = poolBytes;
    return FUN_1400464f4(&config, heap, settings[1]);
}

// MS2-FUNCTIONAL: destroy the universal stream-joint lock and free its heap-prefixed allocation.
// @0x1400463c8
void FUN_1400463c8(void* object)
{
    struct Storage { void* Heap; CriUint8 Payload[1]; };
    Storage* storage = CONTAINING_RECORD((CriUint8*)object, Storage, Payload);
    void* heap = storage->Heap;
    FUN_140045998(object);
    FUN_140027fb4(heap, storage);
}

// MS2-FUNCTIONAL: destroy the ring-buffer stream-joint lock and free its heap-prefixed allocation.
// @0x140046598
void FUN_140046598(void* object)
{
    struct Storage { void* Heap; CriUint8 Payload[1]; };
    Storage* storage = CONTAINING_RECORD((CriUint8*)object, Storage, Payload);
    void* heap = storage->Heap;
    FUN_140045fdc(object);
    FUN_140027fb4(heap, storage);
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriBool FUN_140043810(void* object, void* owner);

CriBool FUN_140042df0(void* decoders, void* owner, CriSint32 index);

CriUint32 FUN_140042f00(void* decoders, CriSint32 index, void* player, CriUint32 channel);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: split a stream chunk, append the selected range, and return bytes left after the requested size.
// @0x1400468f4
CriSint32 FUN_1400468f4(void* streamJoint, const void* chunk, void* suffix, CriUint32 maximum)
{
    struct ChunkView { CriUint64 Begin; CriUint32 Size; };
    const ChunkView* view = (const ChunkView*)chunk;
    CriUint32 copied = maximum;
    CriSint32 remaining = 0;
    if (maximum >= view->Size)
    {
        remaining = (CriSint32)(maximum - view->Size);
        copied = view->Size;
    }
    criSj_SplitChunk(chunk, copied, (void*)chunk, suffix);
    // Slot 4 is PutChunk(joint, id, chunk): the exe passes the prefix (still in r8 after the leaf split).
    void** vtable = *(void***)streamJoint;
    ((void (*)(void*, CriSint32, const void*))vtable[4])(streamJoint, 0, chunk);
    return remaining;
}

// MS2-FUNCTIONAL: format a diagnostic through CRI's bounded printf adapter.
// @0x1400469a4
void FUN_1400469a4(CriChar8* buffer, size_t capacity, const CriChar8* format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    _vsnprintf(buffer, capacity, format, arguments);
    va_end(arguments);
}
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
// MS2-FUNCTIONAL: calculate universal stream-joint work bytes plus the two aligned block headers.
// @0x140046420
CriSint32 FUN_140046420(CriUint32 first, CriUint32 second, const CriUint32* settings)
{
    CriSint32 headerBytes = FUN_140027dd0(8);
    CriUint32 config[3] = { settings[0], first, second };
    return FUN_140045910((const CriSint32*)config) + headerBytes * 2;
}

// MS2-FUNCTIONAL: request work sizing for the default one-block stream-joint setup.
// @0x1400464a8
void FUN_1400464a8(CriUint32 first, CriUint32 second)
{
    const CriUint32 settings[2] = { 0, 1 };
    FUN_140046420(first, second, settings);
}
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
// MS2-FUNCTIONAL: refresh a read-buffer header when its state is active, then drain one queued chunk.
// @0x1400458b8
void FUN_1400458b8(void* object)
{
    struct ReaderBuffer
    {
        CriUint8 Reserved00[9];
        CriUint8 State;
        CriUint8 Reserved0a[0x16];
        void* Queue;
        CriUint8 Reserved28[8];
        CriUint8 Chunk[0x20];
    };
    ReaderBuffer* reader = (ReaderBuffer*)object;
    if (reader->State == 1 || reader->State == 2)
        FUN_140045474(object);
    if (reader->Queue)
    {
        FUN_1400467a0(reader->Queue, 1, -1, reader->Chunk);
        FUN_1400467a8(reader->Queue, 1, reader->Chunk);
    }
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_140042800(void* manager);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: pass this function's variadic arguments to the executable's string scanner as one va_list.
// @0x1400469c4
void FUN_1400469c4(void* string, const CriChar8* format, ...)
{
    va_list args;
    va_start(args, format);
    FUN_14029dd60(string, format, args);
}
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
void* criCs_Create(void* work, CriSint32 size);

void criCs_Destroy(LPCRITICAL_SECTION section);

void FUN_140039f50(LPCRITICAL_SECTION section);

void FUN_140039f8c(LPCRITICAL_SECTION section);

CriUint32 criAtomic_TestAndSet(CriUint32* target, CriUint32 value);

void criAtomic_Initialize();

void criAtomic_Finalize();

CriUint64 FUN_14003a0b4(CriUint64 value, CriUint32 alignment);

CriUint32 FUN_14003a0f8(CriSint32 index);

void criUtfRtv_Destroy(CriUint64* table);
#pragma optimize("", on)

void criMvPly_AttachM2V();

void FUN_14003b880();

void FUN_14003b6e0();

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void* FUN_14003b20c(void* heap, CriSint32 size, const CriChar8* name, CriSint32 alignment,
                    CriSint32 allocationMode);

void FUN_14003b2a4(void* heap, void* memory);

void* FUN_14003b2ac(void* heap, CriSint32 allocationMode, const void* data, CriUint32 size);
#pragma optimize("", on)

// MS2-FUNCTIONAL: allocate the UTF runtime table and field records through its CRI heap callbacks, then let the
// executable's shared UTF parser populate the table layout.
// The exe reports an allocation failure only when this flag (0x143b27c38) is set. Its only writer, the setter at
// 0x14003a0ac, has no callers, so the flag stays 0 and the failures return NULL without an error report.
static CriSint32 s_nUtfRtvReportAllocError = 0;

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void* FUN_14003a1a0(void* callbackBlock, CriUint32 allocationMode, const void* data, CriUint32 size);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void CriMv::InitializeMana(CriError& error);

const void** FUN_14003bed0();

const void** FUN_14003bf10();
#pragma optimize("", on)

// ==== CRI UTF heap callback helpers ================================================================================

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void* criUtfHeap_Alloc(void* heap, CriUint32 size, const char* tag, CriSint32 align, CriSint32 flags);

void FUN_14003a0ec(void* heap, void* p);

void* FUN_14003a184(void* heap, CriUint32 size, const char* tag, CriSint32 align);
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
CriUint32 criUtfRtv_ConvFieldNameToNo(const CriUtfRtvView* table, const CriChar8* name);

CriUint32 FUN_14003a45c(const CriUtfRtvView* table);

CriUint32 FUN_14003aeb4(const CriUtfRtvView* table, CriUint32 slotIndex, const CriChar8* name);
#pragma intrinsic(strcmp)

CriUint8 criUtfRtv_GetDataUint8(const CriUtfRtvView* table, CriUint32 row, CriUint32 field);

CriUint32 criUtfRtv_GetDataUint32(const CriUtfRtvView* table, CriUint32 row, CriUint32 field);

CriUint64 criUtfRtv_GetDataUint64(const CriUtfRtvView* table, CriUint32 row, CriUint32 field);

CriFloat32 criUtfRtv_GetDataFloat32(const CriUtfRtvView* table, CriUint32 row, CriUint32 field);

double criUtfRtv_GetDataFloat64(const CriUtfRtvView* table, CriUint32 row, CriUint32 field);

const CriChar8* criUtfRtv_GetDataStr(const CriUtfRtvView* table, CriUint32 row, CriUint32 field);

CriUint32 FID_conflict_criUtfRtv_GetDataSint32Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name);

CriUint32 FUN_14003a894(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name);

CriFloat32 criUtfRtv_GetDataFload32Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name);

double criUtfRtv_GetDataFloat64Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name);

const CriChar8* criUtfRtv_GetDataStrFn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name);

CriUint8 criUtfRtv_GetDataUint8Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name);

void criUtfRtv_GetCellValFromAddr(const CriUtfRtvView* table, const CriUint8* address,
                                  CriSint32 type, CriUtfRtvCell* cell);

CriBool criUtfRtv_GetCellVal(const CriUtfRtvView* table, CriUint32 row, CriUint32 field, CriUtfRtvCell* cell);

CriUint64 FUN_14003afb0(const CriUtfRtvView* table, const CriUint8* field, CriUtfRtvColumn* column);

CriSint32 criUtfRtv_SumWithAlignment32(const CriUtfRtvView* table, CriUint32 firstRow, CriSint32 count,
                                       CriUint32 field, CriSint32 alignment);

CriUint64 FUN_14003adac(const CriUtfRtvView* table, CriUint32 firstRow, CriSint32 count,
                        CriUint32 field, CriSint32 alignment);

CriBool criUsfCmn_GetChunkIdAndSIze(const CriUint8* data, CriUint32 size, CriUint32* id, CriUint32* chunkSize);

void* criUtfRtv_Create(void* heap, void* table, CriUint32 size);

CriUint32 criUsfCmn_ParseUsfHeaderStd(const CriUint8* data, CriUint32 size, CriUsfStandardHeader* header);

const CriUint8* criUsfCmn_GetContents(const CriUint8* data, CriUint32 size, CriSint32* contentSize);
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
// MS2-FUNCTIONAL: store one output stream joint and its size flags in the demux table.
// @0x140044fb0
void criUsfDmx_SetOutputSj(void* demux, CriUint32 index, void* stream, CriUint32 flags, CriSint32 limit)
{
    struct Output { void* stream; CriUint32 flags; CriSint32 limit; };
    (*(Output**)((CriUint8*)demux + 0x18))[index].stream = stream;
    (*(Output**)((CriUint8*)demux + 0x18))[index].flags = flags;
    (*(Output**)((CriUint8*)demux + 0x18))[index].limit = limit;
}

// MS2-FUNCTIONAL: compute the executable's fixed and per-chain work-area size.
// @0x140045910
CriSint32 criSjUni_CalculateWorkSize(const CriSint32* config)
{
    CriSint32 base = 0x58;
    if (config[0] == 1)
        base += 0x48;
    return base + config[2] * 0x20 + 8;
}

// MS2-FUNCTIONAL: calculate the demux work area from its two unified-joint pools and output records.
// @0x140044eb0
CriSint32 criUsfDmx_CalculateWorkSizeWithWork(CriSint32 outputCount)
{
    const CriSint32 config[3] = { 1, 0, 0x80 };
    CriSint32 jointBytes = criSjUni_CalculateWorkSize(config);
    CriSint32 roundedJointBytes = (jointBytes + 7) & ~7;
    CriSint32 recordBytes = outputCount * 0x10 + 0x17;
    CriSint32 recordUnits = (recordBytes + ((recordBytes >> 31) & 7)) >> 3;
    return roundedJointBytes + 0x48 + roundedJointBytes + recordUnits * 8;
}

// MS2-FUNCTIONAL: calculate ring-buffer work size from its synchronization flag and pool sizes.
// @0x140045ed0
CriSint32 criSjRbf_CalculateWorkSize(const CriSint32* config)
{
    CriSint32 size = 0x58;
    if (config[0] == 1)
    {
        size += 0x48;
    }
    return config[1] + config[2] + config[3] + size;
}

// MS2-FUNCTIONAL: destroy the ring-buffer lock and clear its lock pointer.
// @0x140045fdc
void FUN_140045fdc(void* ringBuffer)
{
    void* lock;
    memcpy(&lock, (CriUint8*)ringBuffer + 0x10, sizeof(lock));
    if (lock)
    {
        criCs_Destroy((LPCRITICAL_SECTION)lock);
        lock = NULL;
        memcpy((CriUint8*)ringBuffer + 0x10, &lock, sizeof(lock));
    }
}

// MS2-FUNCTIONAL: enter the ring-buffer's optional critical section.
// @0x140046014
void FUN_140046014(void* ringBuffer)
{
    void* lock;
    memcpy(&lock, (CriUint8*)ringBuffer + 0x10, sizeof(lock));
    if (lock)
        FUN_140039f50((LPCRITICAL_SECTION)lock);
}

// MS2-FUNCTIONAL: leave the ring-buffer's optional critical section.
// @0x14004602c
void FUN_14004602c(void* ringBuffer)
{
    void* lock;
    memcpy(&lock, (CriUint8*)ringBuffer + 0x10, sizeof(lock));
    if (lock)
        FUN_140039f8c((LPCRITICAL_SECTION)lock);
}

// MS2-FUNCTIONAL: clear all ring-buffer counters and restore its available-capacity field.
// @0x140046044
void criSjRbf_Reset(void* ringBuffer)
{
    struct RingBufferState
    {
        CriUint8 Reserved00[0x10];
        LPCRITICAL_SECTION Lock;      // 0x10
        CriUint8 Reserved18[0x08];
        CriUint32 Field20;            // 0x20
        CriUint32 Free;               // 0x24
        CriUint32 Field28;            // 0x28
        CriUint32 Field2C;            // 0x2c
        CriUint8 Reserved30[0x08];
        CriUint32 Capacity;           // 0x38
        CriUint8 Reserved3C[0x04];
        CriUint32 Field40[4];         // 0x40
    };
    RingBufferState* rb = (RingBufferState*)ringBuffer;
    if (rb->Lock)
        FUN_140039f50(rb->Lock);
    rb->Field20 = 0;
    rb->Field28 = 0;
    rb->Field2C = 0;
    rb->Field40[0] = 0;
    rb->Field40[1] = 0;
    rb->Field40[2] = 0;
    rb->Field40[3] = 0;
    rb->Free = rb->Capacity;
    if (rb->Lock)
        FUN_140039f8c(rb->Lock);
}

// The CRI ring-buffer stream joint (criSjRbf) and the chunk it hands out.
struct CriSjRbfFields
{
    CriUint8 Reserved00[0x10];
    LPCRITICAL_SECTION Lock;      // 0x10
    CriUint8 Reserved18[0x08];
    CriUint32 OutputFree;         // 0x20
    CriUint32 InputFree;          // 0x24
    CriUint32 InputPosition;      // 0x28
    CriUint32 OutputPosition;     // 0x2c
    CriUint8* Data;               // 0x30
    CriUint32 Size;               // 0x38
    CriUint32 Extra;              // 0x3c: mirrored tail past Size
    CriUint32 InputGot;           // 0x40
    CriUint32 InputPut;           // 0x44
    CriUint32 OutputGot;          // 0x48
    CriUint32 OutputPut;          // 0x4c
};
struct CriSjRbfChunk { CriUint8* Data; CriUint32 Size; };

// MS2-FUNCTIONAL: reserve a bounded input or output region from the CRI stream ring buffer.
// @0x140046094
void criSjRbf_GetChunk(void* ringBuffer, CriSint32 direction, CriUint32 requested, void* result)
{
    CriSjRbfFields* rb = (CriSjRbfFields*)ringBuffer;
    CriSjRbfChunk* chunk = (CriSjRbfChunk*)result;
    if (rb->Lock)
        FUN_140039f50(rb->Lock);
    if (direction == 0)
    {
        CriUint32 contiguous = rb->Extra - rb->InputPosition + rb->Size;
        if (rb->InputFree < contiguous)
            contiguous = rb->InputFree;
        if (contiguous < requested)
            requested = contiguous;
        chunk->Size = requested;
        chunk->Data = rb->Data + rb->InputPosition;
        rb->InputPosition = (rb->InputPosition + requested) % rb->Size;
        rb->InputFree -= chunk->Size;
        rb->InputGot += chunk->Size;
    }
    else if (direction == 1)
    {
        CriUint32 contiguous = rb->Extra - rb->OutputPosition + rb->Size;
        if (rb->OutputFree < contiguous)
            contiguous = rb->OutputFree;
        if (contiguous < requested)
            requested = contiguous;
        chunk->Size = requested;
        chunk->Data = rb->Data + rb->OutputPosition;
        rb->OutputPosition = (rb->OutputPosition + requested) % rb->Size;
        rb->OutputFree -= chunk->Size;
        rb->OutputGot += chunk->Size;
    }
    else
    {
        chunk->Size = 0;
        chunk->Data = NULL;
    }
    if (rb->Lock)
        FUN_140039f8c(rb->Lock);
}

// MS2-FUNCTIONAL: pop a recycled 0x20-byte chunk from the unified stream-joint free list.
// @0x14004592c
void* FUN_14004592c(void* streamJoint)
{
    struct ChunkPool { CriUint8 Reserved[0x48]; void* FreeChunk; };
    ChunkPool* pool = (ChunkPool*)streamJoint;
    void* result = NULL;
    void* chunk = pool->FreeChunk;
    if (chunk != NULL)
    {
        result = chunk;
        pool->FreeChunk = *(void**)chunk;
        memset(result, 0, 0x20);
    }
    return result;
}

// MS2-FUNCTIONAL: return a 0x20-byte stream-joint chunk to the unified free list.
// @0x140045964
void FUN_140045964(void* streamJoint, void* chunk)
{
    memset(chunk, 0, 0x20);
    void* head;
    memcpy(&head, (CriUint8*)streamJoint + 0x48, sizeof(head));
    memcpy(chunk, &head, sizeof(head));
    memcpy((CriUint8*)streamJoint + 0x48, &chunk, sizeof(chunk));
}

// MS2-FUNCTIONAL: release the stream-joint lock when one was initialized.
// @0x140045998
void FUN_140045998(void* streamJoint)
{
    void* lock;
    memcpy(&lock, (CriUint8*)streamJoint + 0x10, sizeof(lock));
    if (lock)
    {
        criCs_Destroy((LPCRITICAL_SECTION)lock);
        lock = NULL;
        memcpy((CriUint8*)streamJoint + 0x10, &lock, sizeof(lock));
    }
}

// MS2-FUNCTIONAL: count recycled chunks while honoring the stream-joint lock.
// @0x140045b34
CriSint32 criSjUni_GetNumChainPool(void* streamJoint)
{
    struct ChainPool { CriUint8 Reserved00[0x10]; LPCRITICAL_SECTION Lock; CriUint8 Reserved18[0x30]; void* FreeChunk; };
    ChainPool* pool = (ChainPool*)streamJoint;
    if (pool->Lock)
        FUN_140039f50(pool->Lock);
    CriSint32 count = 0;
    for (void* chunk = pool->FreeChunk; chunk; chunk = *(void**)chunk)
        ++count;
    if (pool->Lock)
        FUN_140039f8c(pool->Lock);
    return count;
}

// MS2-FUNCTIONAL: drain every active stream-joint queue and return its chunks to the free list.
// @0x140045b7c
#pragma function(memset)
void criSjUni_Reset(void* streamJoint)
{
    struct ChainPool { CriUint8 Reserved00[0x10]; LPCRITICAL_SECTION Lock; CriUint8 Reserved18[8]; void* Lists[4]; CriUint8 Reserved40[8]; void* FreeChunk; };
    ChainPool* pool = (ChainPool*)streamJoint;
    if (pool->Lock)
        FUN_140039f50(pool->Lock);
    for (CriUint32 index = 0; index < 4; ++index)
    {
        void* chunk;
        while ((chunk = pool->Lists[index]) != NULL)
        {
            pool->Lists[index] = *(void**)chunk;
            memset(chunk, 0, 0x20);
            *(void**)chunk = pool->FreeChunk;
            pool->FreeChunk = chunk;
        }
        pool->Lists[index] = NULL;
    }
    if (pool->Lock)
        FUN_140039f8c(pool->Lock);
}
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
CriUint32 criUtfRtv_SearchRecNoByUint32(const CriUtfRtvView* table, CriUint32 field, CriUint32 value);

#pragma function(strcmp)                      // the exe calls strcmp here rather than expanding it
CriUint32 criUtfRtv_SearchRecNoByStr(const CriUtfRtvView* table, CriUint32 field, const CriChar8* value);
#pragma intrinsic(strcmp)
#pragma optimize("", on)

void MPVDEC_ResetMv(CriMpvDecoderState* state);

void MPVDEC_ResetDc(CriMpvDecoderState* state);

void mpvumc_SubMbadr(CriMpvDecoderState* state, CriSint32 run);

void mpvumc_IncreMbadr(CriMpvDecoderState* state);

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: read the initialized flag stored in the CRI demux object.
// @0x140044f8c
CriSint32 FUN_140044f8c(void* object)
{
    if (object == NULL)
    {
        return 0;
    }
    return *((signed char*)object + 9);
}

// MS2-FUNCTIONAL: reset the demux object's secondary state and mark it initialized.
// @0x140044f9c
void FUN_140044f9c(void* object)
{
    *((CriUint8*)object + 10) = 0;
    *((CriUint8*)object + 9) = 1;
}

// MS2-FUNCTIONAL: store the demux object's opaque user-data pointer.
// @0x140044fa8
void FUN_140044fa8(void* object, void* value)
{
    *(void**)((CriUint8*)object + 0x10) = value;
}

// MS2-FUNCTIONAL: clear the demux object's one-byte status flag.
// @0x140044fd8
void FUN_140044fd8(void* object, CriUint8 value)
{
    *((CriUint8*)object + 0xb) = value;
}

// MS2-FUNCTIONAL: mark the demux object's reset flag.
// @0x140044fdc
void FUN_140044fdc(void* object)
{
    *((CriUint8*)object + 10) = 1;
}
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
// MS2-FUNCTIONAL: decrement CRI's shared demux counter.
// @0x140044ea8
void FUN_140044ea8(void)
{
    --DAT_143ba9d28;
}

// MS2-FUNCTIONAL: lock the object's embedded CRI critical section when present.
// @0x1400459bc
void FUN_1400459bc(void* object)
{
    void* section = *(void**)((CriUint8*)object + 0x10);
    if (section)
        FUN_140039f50((LPCRITICAL_SECTION)section);
}

// MS2-FUNCTIONAL: unlock the object's embedded CRI critical section when present.
// @0x1400459d4
void FUN_1400459d4(void* object)
{
    void* section = *(void**)((CriUint8*)object + 0x10);
    if (section)
        FUN_140039f8c((LPCRITICAL_SECTION)section);
}

// MS2-FUNCTIONAL: call the stream-joint object's first virtual operation.
// @0x140046798
void FUN_140046798(void* object)
{
    (*(void (**)(void*))((CriUint8*)*(void**)object + 8))(object);
}

// MS2-FUNCTIONAL: call the stream-joint object's deleting destructor slot.
// @0x140046784
void FUN_140046784(void* object)
{
    DAT_143ba9d30 = "\nCRI Stream Joint/PCx64 Ver.1.01.00 Build:Jan 13 2012 19:02:02\n";
    (**(void (***)(void*))object)(object);
}

// MS2-FUNCTIONAL: split a stream-joint chunk into a bounded prefix and its remaining suffix.
// @0x1400467c0
void criSj_SplitChunk(const void* source, CriUint32 maximum, void* prefix, void* suffix)
{
    struct SjChunk
    {
        CriUint8* Data;
        CriUint32 Size;
        CriUint32 Reserved;
    };
    SjChunk* head = (SjChunk*)prefix;
    SjChunk* tail = (SjChunk*)suffix;
    // The exe copies the whole 16-byte chunk into prefix (+0xc included) and never writes suffix+0xc.
    *head = *(const SjChunk*)source;
    tail->Size = head->Size;
    if (head->Size > maximum)
        head->Size = maximum;
    tail->Size -= head->Size;
    if (tail->Size == 0)
    {
        tail->Data = NULL;
        return;
    }
    tail->Data = head->Data + head->Size;
}

// MS2-FUNCTIONAL: place a bounded prefix on the input queue and return the suffix to output.
// @0x140046814
void criSj_PutInputChunk(void* streamJoint, const void* chunk, CriUint32 size)
{
    struct SjChunk { CriUint8* Data; CriUint32 Size; CriUint32 Reserved; };
    typedef void (*PutChunk)(void*, CriSint32, void*);
    struct SjInterface { void* Reserved[3]; PutChunk UngetChunk; PutChunk PutChunk; };
    const SjChunk* source = (const SjChunk*)chunk;
    SjChunk prefix = *source, suffix;
    if (size > source->Size)
        size = source->Size;
    criSj_SplitChunk(&prefix, size, &prefix, &suffix);
    (*(SjInterface**)streamJoint)->PutChunk(streamJoint, 1, &prefix);
    (*(SjInterface**)streamJoint)->UngetChunk(streamJoint, 0, &suffix);
}

// MS2-FUNCTIONAL: place a bounded prefix on the output queue and return the suffix to input.
// @0x140046894
void criSj_PutOutputChunk(void* streamJoint, const void* chunk, CriUint32 size)
{
    struct SjChunk { CriUint8* Data; CriUint32 Size; CriUint32 Reserved; };
    typedef void (*PutChunk)(void*, CriSint32, void*);
    struct SjInterface { void* Reserved[3]; PutChunk UngetChunk; PutChunk PutChunk; };
    const SjChunk* source = (const SjChunk*)chunk;
    SjChunk prefix = *source, suffix;
    if (size > source->Size)
        size = source->Size;
    criSj_SplitChunk(&prefix, size, &prefix, &suffix);
    (*(SjInterface**)streamJoint)->PutChunk(streamJoint, 0, &prefix);
    (*(SjInterface**)streamJoint)->UngetChunk(streamJoint, 1, &suffix);
}

// MS2-FUNCTIONAL: call the stream-joint object's second virtual operation.
// @0x1400467a0
void FUN_1400467a0(void* object, CriSint32 operation = 0, CriUint32 limit = 0, void* output = NULL)
{
    typedef void (*Callback)(void*, CriSint32, CriUint32, void*);
    ((Callback)*(void**)((CriUint8*)*(void**)object + 0x10))(object, operation, limit, output);
}

// MS2-FUNCTIONAL: call the stream-joint object's third virtual operation.
// @0x1400467a8
void FUN_1400467a8(void* object, CriSint32 operation = 0, void* chunk = NULL)
{
    typedef void (*Callback)(void*, CriSint32, void*);
    ((Callback)*(void**)((CriUint8*)*(void**)object + 0x18))(object, operation, chunk);
}

// MS2-FUNCTIONAL: call the stream-joint object's fourth virtual operation.
// @0x1400467b0
void FUN_1400467b0(void* object, CriSint32 operation = 0, void* chunk = NULL)
{
    typedef void (*Callback)(void*, CriSint32, void*);
    ((Callback)*(void**)((CriUint8*)*(void**)object + 0x20))(object, operation, chunk);
}

// MS2-FUNCTIONAL: call the stream-joint object's fifth virtual operation.
// @0x1400467b8
CriSint32 FUN_1400467b8(void* object, CriSint32 query = 0)
{
    typedef CriSint32 (*Callback)(void*, CriSint32);
    return ((Callback)*(void**)((CriUint8*)*(void**)object + 0x28))(object, query);
}

// MS2-FUNCTIONAL: call the stream-joint object's indexed range operation with default bounds.
// @0x140046804
void FUN_140046804(void* object, void* value)
{
    ((void (*)(void*, CriSint32, CriSint32, void*))*(void**)((CriUint8*)*(void**)object + 0x10))(object, 0, -1, value);
}

// MS2-FUNCTIONAL: copy a null-terminated string with the executable's bounded secure CRT helper.
// @0x140046944
char* FUN_140046944(char* dst, size_t size, const char* src)
{
    strcpy_s(dst, size, src);
    return dst;
}

// MS2-FUNCTIONAL: copy a bounded string with the executable's secure CRT helper.
// @0x14004695c
char* FUN_14004695c(char* dst, size_t size, const char* src, size_t count)
{
    strncpy_s(dst, size, src, count);
    return dst;
}

// MS2-FUNCTIONAL: append a bounded string with the executable's secure CRT helper.
// @0x140046974
char* FUN_140046974(char* dst, size_t size, const char* src, size_t count)
{
    strncat_s(dst, size, src, count);
    return dst;
}

// MS2-FUNCTIONAL: append a null-terminated string with the executable's secure CRT helper.
// @0x14004698c
char* FUN_14004698c(char* dst, size_t size, const char* src)
{
    strcat_s(dst, size, src);
    return dst;
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: copy the requested number of bytes with the executable's secure CRT helper.
// @0x1400469f0
void* FUN_1400469f0(void* dst, size_t size, const void* src, size_t count)
{
    memcpy_s(dst, size, src, count);
    return dst;
}

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
// MS2-FUNCTIONAL: initialize the USF demux runtime banner on first use and increment its reference count.
// @0x140044e84
void FUN_140044e84(void)
{
    if (DAT_143ba9d28 == 0)
        DAT_143ba9d20 = "\nCRI UsfDmx/PCx64 Ver.1.01.03 Build:Jan 13 2012 19:02:04\n";
    ++DAT_143ba9d28;
}
#pragma optimize("", on)

void* FUN_140041c00(void* context);

void* FUN_140041c60(void* manager, CriUint32 flags);

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: sum the queued byte counts in one CRI reader ring-buffer lane.
// @0x140045c08
CriSint32 FUN_140045c08(void* object, CriSint32 lane)
{
    struct ReaderRing
    {
        CriUint8 Reserved00[0x10];
        LPCRITICAL_SECTION Section;
        CriUint8 Reserved18[8];
        void* Queues[2];
    };
    struct QueueEntry { QueueEntry* Next; CriUint8 Reserved08[0x10]; CriSint32 Size; };
    ReaderRing* ring = (ReaderRing*)object;
    if (ring->Section)
        FUN_140039f50(ring->Section);
    CriSint32 total = 0;
    for (QueueEntry* entry = (QueueEntry*)ring->Queues[lane]; entry; entry = entry->Next)
        total += entry->Size;
    if (ring->Section)
        FUN_140039f8c(ring->Section);
    return total;
}
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
// MS2-FUNCTIONAL: drain and reset a CRI movie output ring before restoring its terminal queue entry.
// @0x1400453c4
#pragma function(memset)
void FUN_1400453c4(void* object)
{
    struct QueueEntry { void* Queue; CriUint32 Reserved; CriSint32 State; };
    struct OutputState
    {
        CriUint8 Reserved00[8];
        CriUint8 Reading;
        CriUint8 Writing;
        CriUint8 Active;
        CriUint8 Reserved0b[1];
        CriUint32 Count;
        CriUint8 Reserved10[8];
        QueueEntry* Entries;
        void* InputQueue;
        void* OutputQueue;
    };
    struct Chunk { void* Data; CriUint64 Size; }; // scalar members: no /GS buffer
    OutputState* state = (OutputState*)object;
    Chunk chunk;
    CriUint32 last;
    state->Writing = 0;
    state->Reading = 0;
    // drain the filled lane (1) back to the free lane (0), returning each chunk
    while (FUN_1400467b8(state->InputQueue, 1) != 0)
    {
        FUN_1400467a0(state->InputQueue, 1, -1, &chunk);
        FUN_1400467b0(state->InputQueue, 0, &chunk);
    }
    memset(state->Entries, 0, (state->Count + 1) * sizeof(QueueEntry));
    state->Active = 0;
    FUN_140046798(state->InputQueue);
    FUN_140046798(state->OutputQueue);
    last = state->Count;
    state->Entries[last].Queue = state->OutputQueue;
    state->Entries[last].Reserved = 0;
    state->Entries[last].State = -1;
    state->Writing = 0;
    state->Reading = 1;
}
#pragma intrinsic(memset)
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
CriBool FUN_140040f80(const void* packet, CriSint32 size);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: compute ring-buffer memory requirements for the CRI movie stream joint.
// @0x140046604
CriSint32 FUN_140046604(CriUint32 first, CriUint32 second, CriUint32 third,
                        const CriUint32* settings)
{
    struct Setup { CriUint32 Flags, First, Second, Third; CriUint64 Reserved; };
    CriSint32 overhead = FUN_140027dd0(8);
    Setup setup = { settings[0], first, second, third, 0 };
    return FUN_140045ed0((const CriSint32*)&setup) + overhead * 2;
}

// MS2-FUNCTIONAL: create a standard ring-buffer stream joint using the static CRI pool descriptor.
// @0x140046678
void* FUN_140046678(void* heap, CriUint32 first, CriUint32 second, CriUint32 third)
{
    const CriUint32 settings[2] = { 0, 1 };
    return FUN_1400465c4(heap, first, second, third, (CriUint64)&DAT_1431b9ca0, settings);
}

// MS2-FUNCTIONAL: create a configured ring-buffer stream joint with caller-supplied pool storage.
// @0x1400466ac
void* FUN_1400466ac(void* heap, CriUint32 first, CriUint32 second, CriUint32 third,
                   CriUint64 poolBytes)
{
    const CriUint32 settings[2] = { 0, 1 };
    return FUN_1400465c4(heap, first, second, third, poolBytes, settings);
}

// MS2-FUNCTIONAL: calculate stream-joint requirements using the default setup flags.
// @0x1400466dc
CriSint32 FUN_1400466dc(CriUint32 first, CriUint32 second, CriUint32 third)
{
    const CriUint32 settings[2] = { 0, 1 };
    return FUN_140046604(first, second, third, settings);
}

// MS2-FUNCTIONAL: create a non-zero initialized ring-buffer stream joint using the static pool descriptor.
// @0x1400466fc
void* FUN_1400466fc(void* heap, CriUint32 first, CriUint32 second, CriUint32 third)
{
    const CriUint32 settings[2] = { 1, 1 };
    return FUN_1400465c4(heap, first, second, third, (CriUint64)&DAT_1431b9ca0, settings);
}

// MS2-FUNCTIONAL: create a non-zero initialized ring-buffer stream joint with caller pool storage.
// @0x140046730
void* FUN_140046730(void* heap, CriUint32 first, CriUint32 second, CriUint32 third,
                   CriUint64 poolBytes)
{
    const CriUint32 settings[2] = { 1, 1 };
    return FUN_1400465c4(heap, first, second, third, poolBytes, settings);
}

// MS2-FUNCTIONAL: create a stream joint using caller setup flags and the static pool descriptor.
// @0x140046760
void* FUN_140046760(void* heap, CriUint32 first, CriUint32 second, CriUint32 third,
                   const CriUint32* settings)
{
    return FUN_1400465c4(heap, first, second, third, (CriUint64)&DAT_1431b9ca0, settings);
}

// MS2-FUNCTIONAL: append a decoder read span to its wrapped input buffer and update read counters.
// @0x140046170
void FUN_140046170(void* ring, CriSint32 mode, CriUint64* span)
{
    CriSjRbfFields* rb = (CriSjRbfFields*)ring;
    CriSjRbfChunk* chunk = (CriSjRbfChunk*)span;
    if (chunk->Size == 0 || chunk->Data == NULL)
        return;
    if (mode == 1)
    {
        CriUint32 offset = (CriUint32)(chunk->Data - rb->Data);
        if (offset < rb->Extra)
        {
            CriUint32 first = rb->Extra - offset;
            if (chunk->Size < first)
                first = chunk->Size;
            memcpy(rb->Data + (offset + rb->Size), chunk->Data, first);
        }
        CriUint32 end = (CriUint32)(chunk->Data + chunk->Size - rb->Data);
        if (end > rb->Size)
        {
            CriUint32 wrapped = end - rb->Size;
            if (chunk->Size < wrapped)
                wrapped = chunk->Size;
            memcpy(rb->Data, rb->Data + (end - wrapped), wrapped);
        }
        if (rb->Lock)
            FUN_140039f50(rb->Lock);
        rb->OutputFree += chunk->Size;
        rb->OutputPut += chunk->Size;
    }
    else if (mode == 0)
    {
        if (rb->Lock)
            FUN_140039f50(rb->Lock);
        rb->InputFree += chunk->Size;
        rb->InputPut += chunk->Size;
    }
    else
    {
        chunk->Size = 0;
        chunk->Data = NULL;
        return;
    }
    if (rb->Lock)
        FUN_140039f8c(rb->Lock);
}
#pragma optimize("", on)

void* FUN_140041d40(void* manager);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_140040c00(void* player, void* context);

void FUN_140040cc0(void* player, CriUint32 frame, CriSint32* segmentIndex, CriSint32* delta);

void FUN_1400436d0(void* state);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: release the decoder, both stream joints, and the heap-owned reader state.
// @0x140044f28
void FUN_140044f28(void* object)
{
    struct DecoderOwner
    {
        void* Heap;
        void* Reserved08[2];
        void* DecoderBuffer;
        void* InputJoint;
        void* OutputJoint;
    };
    DecoderOwner* owner = (DecoderOwner*)object;
    if (!owner)
        return;
    void* heap = owner->Heap;
    if (heap && owner->DecoderBuffer)
        FUN_140027fb4(heap, owner->DecoderBuffer);
    if (owner->InputJoint)
        FUN_140046784(owner->InputJoint);
    if (owner->OutputJoint)
        FUN_140046784(owner->OutputJoint);
    if (heap)
        FUN_140027fb4(heap, owner);
}
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

// MS2-FUNCTIONAL: dequeue a chunk large enough for the request or split its head in single-buffer mode.
// @0x140045c60
void FUN_140045c60(void* object, CriSint32 lane, CriUint32 requested, CriUint64* output)
{
    CriSjRingQueue* queue = (CriSjRingQueue*)object;
    CriSjChunk* result = (CriSjChunk*)output;
    if (queue->Lock)
        FUN_140039f50(queue->Lock);
    CriSjChunkNode* node = queue->Heads[lane];
    if (node)
    {
        CriSjChunk chunk = node->Chunk;
        if (chunk.Size <= requested)
        {
            *result = chunk;
            queue->Heads[lane] = node->Next;
            memset(node, 0, sizeof(*node));
            node->Next = queue->FreeList;
            queue->FreeList = node;
        }
        else if (queue->Mode == 1)
        {
            CriSjChunk suffix;
            criSj_SplitChunk(&chunk, requested, &chunk, &suffix);
            *result = chunk;
            node->Chunk = suffix;
        }
        else
        {
            result->Data = NULL;
            result->Size = 0;
        }
    }
    else
    {
        result->Data = NULL;
        result->Size = 0;
    }
    if (queue->Lock)
        FUN_140039f8c(queue->Lock);
}

// MS2-FUNCTIONAL: append a contiguous input chunk to the lane tail or consume a recycled node.
// @0x140045d34
void FUN_140045d34(void* object, CriSint32 lane, const CriUint64* input)
{
    CriSjRingQueue* queue = (CriSjRingQueue*)object;
    const CriSjChunk* chunk = (const CriSjChunk*)input;
    if (chunk->Size > 0 && chunk->Data)
    {
        if (queue->Lock)
            FUN_140039f50(queue->Lock);
        CriSjChunkNode** tail = &queue->Heads[lane];
        CriSjChunkNode* last = NULL;
        for (CriSjChunkNode* walk = *tail; walk; walk = walk->Next)
        {
            last = walk;
            tail = &walk->Next;
        }
        CriSjChunkNode* node = NULL;
        if (queue->Mode == 1 && last && (CriUint8*)last->Chunk.Data + last->Chunk.Size == chunk->Data)
            last->Chunk.Size += chunk->Size;
        else
            node = criSjRbf_PopFreeNode(queue);
        if (node)
        {
            node->Chunk = *chunk;
            *tail = node;
        }
        if (queue->Lock)
            FUN_140039f8c(queue->Lock);
    }
}

// MS2-FUNCTIONAL: prepend a contiguous input chunk or a recycled node to the selected ring lane.
// @0x140045e04
void FUN_140045e04(void* object, CriSint32 lane, const CriUint64* input)
{
    CriSjRingQueue* queue = (CriSjRingQueue*)object;
    const CriSjChunk* chunk = (const CriSjChunk*)input;
    if (chunk->Size > 0 && chunk->Data)
    {
        if (queue->Lock)
            FUN_140039f50(queue->Lock);
        CriSjChunkNode* head = queue->Heads[lane];
        if (queue->Mode == 1 && head && (CriUint8*)chunk->Data + chunk->Size == head->Chunk.Data)
        {
            head->Chunk.Data = chunk->Data;
            head->Chunk.Size += chunk->Size;
        }
        else
        {
            CriSjChunkNode* node = criSjRbf_PopFreeNode(queue);
            if (node)
            {
                node->Chunk = *chunk;
                node->Next = queue->Heads[lane];
                queue->Heads[lane] = node;
            }
        }
        if (queue->Lock)
            FUN_140039f8c(queue->Lock);
    }
}
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
// MS2-FUNCTIONAL: allocate a USF demux state, output table, and its paired stream joints.
// @0x1400452b4
void* FUN_1400452b4(void* heap, CriSint32 outputCount)
{
    struct OutputEntry { void* Queue; CriUint32 Reserved; CriSint32 State; };
    struct UsfState
    {
        void* Heap;
        CriUint8 Running;
        CriUint8 Initialized;
        CriUint8 Closed;
        CriUint8 Reserved0b;
        CriSint32 OutputCount;
        void* Reserved10;
        OutputEntry* Outputs;
        void* InputQueue;
        void* OutputQueue;
        CriUint8 Reserved30[0x10];
    };
    UsfState* state = (UsfState*)FUN_140027ed8(heap, 0x40, "CriUsfDmx", 0);
    if (!state)
        return NULL;
    memset(state, 0, sizeof(*state));
    state->Heap = heap;
    state->OutputCount = outputCount;
    state->Outputs = (OutputEntry*)FUN_140027ed8(heap, (outputCount + 1) * 0x10,
                                                 "CriUsfDmxOut", 0);
    if (!state->Outputs)
    {
        FUN_140044f28(state);
        return NULL;
    }
    memset(state->Outputs, 0, ((size_t)outputCount + 1) * sizeof(OutputEntry));
    state->InputQueue = FUN_1400464c8(heap, 0, 0x80);
    if (!state->InputQueue)
    {
        FUN_140044f28(state);
        return NULL;
    }
    state->OutputQueue = FUN_1400464c8(heap, 0, 0x80);
    if (!state->OutputQueue)
    {
        FUN_140044f28(state);
        return NULL;
    }
    state->Outputs[outputCount].Queue = state->OutputQueue;
    state->Outputs[outputCount].State = -1;
    state->Running = 1;
    memset(state->Reserved30, 0, sizeof(state->Reserved30));
    return state;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_140040a20(void* player, void** inputDescriptor);

CriBool FUN_140042cf0(void* trackSet, void* operation);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: read the three queue counters for the selected CRI stream joint lane.
// @0x1400450c0
void FUN_1400450c0(void* stream, CriUint32 lane, CriUint32* first, CriUint32* second,
                   CriUint32* third)
{
    struct QueueEntry { void* Queue; void* Reserved; };
    struct StreamQueues { CriUint8 Reserved00[0x18]; QueueEntry* Entries; };
    QueueEntry* entries = ((StreamQueues*)stream)->Entries;
    if (!entries[lane].Queue)
        return;
    *first = (CriUint32)FUN_1400467b8(entries[lane].Queue, 1);
    *second = (CriUint32)FUN_1400467b8(entries[lane].Queue, 0);
    *third = (CriUint32)FUN_1400467b8(entries[lane].Queue, 2);
}

// MS2-FUNCTIONAL: advance the read or write cursor of a CRI ring-buffer stream joint after a consumed chunk.
// @0x14004624c
void FUN_14004624c(void* joint, CriSint32 lane, void* chunkPtr)
{
    CriSjRbfFields* rb = (CriSjRbfFields*)joint;
    CriSjRbfChunk* chunk = (CriSjRbfChunk*)chunkPtr;
    if (chunk->Size <= 0 || chunk->Data == NULL)
        return;
    if (lane == 0)
    {
        if (rb->Lock)
            FUN_140039f50(rb->Lock);
        CriUint32 position = (rb->Size - chunk->Size + rb->InputPosition) % rb->Size;
        if (position == (CriUint32)((chunk->Data - rb->Data) % (CriSint64)rb->Size))
        {
            rb->InputPosition = position;
            rb->InputFree += chunk->Size;
            rb->InputGot -= chunk->Size;
        }
    }
    else if (lane == 1)
    {
        if (rb->Lock)
            FUN_140039f50(rb->Lock);
        CriUint32 position = (rb->Size - chunk->Size + rb->OutputPosition) % rb->Size;
        if (position == (CriUint32)((chunk->Data - rb->Data) % (CriSint64)rb->Size))
        {
            rb->OutputPosition = position;
            rb->OutputFree += chunk->Size;
            rb->OutputGot -= chunk->Size;
        }
    }
    else
    {
        chunk->Size = 0;
        chunk->Data = NULL;
        return;
    }
    if (rb->Lock)
        FUN_140039f8c(rb->Lock);
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void* FUN_140043af0(void* implementation, void* heap, void* parameter);

void* FUN_140044470(void* implementation, void* heap, void* parameter);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: skip leading zero bytes of the first stream queue chunk and split it between two joints.
// @0x140044fe4
void FUN_140044fe4(void* stream)
{
    struct Chunk { CriUint8* Data; CriSint32 Size; };
    struct Stream { CriUint8 Reserved00[0x10]; void* Source; CriUint8 Reserved18[8]; void* First; void* Second; };
    Stream* state = (Stream*)stream;
    void* source = state->Source;
    void* first = state->First;
    void* second = state->Second;
    Chunk chunk;
    CriUint8 split[16];
    FUN_1400467a0(source, 1, 0x7fffffff, &chunk);
    CriSint32 index = 1;
    if (1 < chunk.Size)
    {
        CriUint8* scan = chunk.Data;
        do
        {
            ++scan;
            if (*scan != 0)
            {
                criSj_SplitChunk(&chunk, index, &chunk, split);
                FUN_1400467a8(source, 1, split);
                FUN_1400467b0(first, 1, &chunk);
                second = state->Second;
                FUN_1400467b0(second, 1, &chunk);
                return;
            }
            ++index;
        } while (index < chunk.Size);
    }
    FUN_1400467b0(first, 1, &chunk);
    FUN_1400467b0(second, 1, &chunk);
}
#pragma optimize("", on)

extern "C" const void* PTR_FUN_143a485d8;
extern "C" const void* PTR_FUN_143a48608;
void FUN_14002e6b0(void*, CriUint32, CriMvWorkAllocator*);
void* FUN_14002e6c0(CriMvWorkAllocator*, CriUint32, CriUint32);
void FUN_14002e6bc(CriMvWorkAllocator*);
void FUN_140038ddc(CriSint32, const CriChar8*);

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: lay out a CRI ring-buffer stream joint inside the supplied work area.
// @0x140045eec
void* FUN_140045eec(const void* config, void* work, CriSint32 workSize)
{
    const CriSint32* settings = (const CriSint32*)config;
    CriMvWorkAllocator allocator;
    FUN_14002e6b0(work, (CriUint32)workSize, &allocator);
    void** object = (void**)FUN_14002e6c0(&allocator, 0x50, 8);
    memset(object, 0, 0x50);
    object[0] = (void*)&PTR_FUN_143a48608;
    object[1] = (void*)"CriSjRbf";
    if (settings[0] == 1)
    {
        void* csWork = FUN_14002e6c0(&allocator, 0x48, 1);
        object[2] = criCs_Create(csWork, 0x48);
        if (!object[2])
        {
            FUN_140038ddc(0, "E09021620B:Failed in criCs_Create().");
            return NULL;
        }
    }
    else
    {
        object[2] = NULL;
    }
    object[3] = *(void* const*)(settings + 4);
    object[6] = FUN_14002e6c0(&allocator, (CriUint32)(settings[1] + settings[2]), (CriUint32)settings[3]);
    *(CriSint32*)(object + 7) = settings[1];
    *(CriSint32*)((CriUint8*)object + 0x3c) = settings[2];
    FUN_140046798(object);
    FUN_14002e6bc(&allocator);
    return object;
}

// MS2-FUNCTIONAL: lay out a CRI universal stream joint and its free list of 0x20-byte chunk records.
// @0x1400459ec
void* FUN_1400459ec(const void* config, void* work, CriSint32 workSize)
{
    struct Chunk { Chunk* Next; CriUint8 Reserved08[0x18]; };
    struct StreamJoint
    {
        const void* Vtable;           // 0x00
        const char* Name;             // 0x08
        LPCRITICAL_SECTION Lock;      // 0x10
        CriUint32 Mode;               // 0x18
        void* Lists[4];               // 0x20
        Chunk* Chunks;                // 0x40
        Chunk* FreeChunk;             // 0x48
    };
    struct Config { CriUint32 Locked; CriUint32 Mode; CriUint32 NumChunks; };
    const Config* settings = (const Config*)config;
    CriMvWorkAllocator allocator;
    FUN_14002e6b0(work, (CriUint32)workSize, &allocator);
    StreamJoint* object = (StreamJoint*)FUN_14002e6c0(&allocator, 0x50, 8);
    memset(object, 0, 0x50);
    object->Vtable = &PTR_FUN_143a485d8;
    object->Name = "CriSjUni";
    if (settings->Locked == 1)
    {
        void* csWork = FUN_14002e6c0(&allocator, 0x48, 1);
        object->Lock = (LPCRITICAL_SECTION)criCs_Create(csWork, 0x48);
        if (!object->Lock)
        {
            FUN_140038ddc(0, "E09021213:Failed in criCs_Create().");
            return NULL;
        }
    }
    else
    {
        object->Lock = NULL;
    }
    object->Mode = settings->Mode;
    object->Lists[0] = NULL;
    object->Lists[1] = NULL;
    object->Lists[2] = NULL;
    object->Lists[3] = NULL;
    object->Chunks = (Chunk*)FUN_14002e6c0(&allocator, settings->NumChunks << 5, 8);
    object->FreeChunk = NULL;
    for (CriUint32 index = 0; index < settings->NumChunks; ++index)
    {
        Chunk* record = &object->Chunks[index];
        memset(record, 0, 0x20);
        record->Next = object->FreeChunk;
        object->FreeChunk = record;
    }
    FUN_14002e6bc(&allocator);
    return object;
}
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
// MS2-FUNCTIONAL: build a stream demuxer object holding two universal stream joints and a per-track table.
// @0x140045144
void* FUN_140045144(CriSint32 count, void* work, CriSint32 workSize)
{
    struct Track { void* Joint; CriUint32 Reserved08; CriUint32 Limit; };
    struct Demux
    {
        void* Reserved00;
        CriUint8 Ready;
        CriUint8 Reserved09;
        CriUint8 Reserved0a;
        CriUint8 Reserved0b;
        CriSint32 Count;
        void* Reserved10;
        Track* Tracks;
        void* Input;
        void* Output;
        CriUint64 Tail[2];
    };
    static_assert(sizeof(Demux) == 0x40, "layout");
    memset(work, 0, (size_t)workSize);
    CriMvWorkAllocator allocator;
    FUN_14002e6b0(work, (CriUint32)workSize, &allocator);
    Demux* demux = (Demux*)FUN_14002e6c0(&allocator, 0x40, 8);
    if (demux != NULL)
    {
        demux->Reserved00 = NULL;
        demux->Reserved10 = NULL;
        demux->Reserved09 = 0;
        demux->Count = count;
        demux->Reserved0a = 0;
        demux->Tracks = (Track*)FUN_14002e6c0(&allocator, (CriUint32)(count + 1) * 0x10, 8);
        if (demux->Tracks != NULL)
        {
            CriUint32 config[3] = { 1, 0, 0x80 };
            CriUint32 size = (CriUint32)criSjUni_CalculateWorkSize((const CriSint32*)config);
            demux->Input = FUN_1400459ec(config, FUN_14002e6c0(&allocator, size, 8), (CriSint32)size);
            if (demux->Input != NULL)
            {
                config[2] = 0x80;
                size = (CriUint32)criSjUni_CalculateWorkSize((const CriSint32*)config);
                demux->Output = FUN_1400459ec(config, FUN_14002e6c0(&allocator, size, 8), (CriSint32)size);
                if (demux->Output != NULL)
                {
                    Track* last = &demux->Tracks[(CriUint32)demux->Count];
                    last->Joint = demux->Output;
                    last->Reserved08 = 0;
                    last->Limit = 0xffffffffu;
                    demux->Ready = 1;
                    memset(demux->Tail, 0, sizeof(demux->Tail));
                    FUN_14002e6bc(&allocator);
                    return demux;
                }
            }
        }
        FUN_140044f28(demux);
    }
    return NULL;
}
#pragma optimize("", on)

const CriUint8* criUsfCmn_GetContents(const CriUint8* data, CriUint32 size, CriSint32* contentSize);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_1400428e0(void* trackSet, void* player);
#pragma optimize("", on)

CriSint32 criSjUni_GetNumChainPool(void* streamJoint);

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: match demuxed USF chunks against the per-track filters and hand them to the matching track queues.
// @0x140045474
void FUN_140045474(void* object)
{
    struct Chunk { CriUint8* Data; CriUint32 Size; CriUint32 Reserved; };
    struct TrackEntry { void* Queue; CriUint32 Type; CriUint32 Id; };
    struct Demux
    {
        CriUint8 Reserved00[9];
        CriUint8 State;
        CriUint8 Flush;
        CriUint8 Primed;
        CriSint32 Count;
        void* Input;
        TrackEntry* Tracks;
        void* Output;
    };
    static_assert(offsetof(Demux, Output) == 0x20 && sizeof(TrackEntry) == 0x10, "layout");
    Demux* demux = (Demux*)object;
    void* input = demux->Input;
    void* output = demux->Output;
    TrackEntry* tracks = demux->Tracks;
    CriSint32 count = demux->Count;
    Chunk first;
    Chunk second;
    Chunk split;
    Chunk rest;
    Chunk tail;
    CriUsfStandardHeader header;
    CriSint32 index;
    CriSint32 matched;
    CriSint32 available;
    CriUint32 headerSize;
    CriUint32 needed;
    CriUint32 type;
    Chunk* source;
    CriUint32 length;
    if (demux->Primed == 1)
    {
        void* queue = tracks[count].Queue;
        FUN_1400467a0(queue, 1, 0xffffffff, &first);
        while (first.Size != 0)
        {
            FUN_1400467b0(queue, 0, &first);
            FUN_1400467a0(queue, 1, 0xffffffff, &first);
        }
        count += 1;
        first.Size = 0;
    }
    do
    {
        FUN_1400467a0(output, 1, 0xffffffff, &first);
        if (first.Size == 0)
        {
            if (demux->State == 2)
            {
                demux->State = 3;
                return;
            }
            goto drainInput;
        }
        matched = 0;
        for (index = 0; index < count; ++index)
        {
            if (tracks[index].Queue != NULL)
            {
                FUN_1400467a0(tracks[index].Queue, 0, 0xffffffff, &second);
                if (first.Data == second.Data)
                {
                    length = second.Size < first.Size ? second.Size : first.Size;
                    criSj_SplitChunk(&first, length, &first, &split);
                    criSj_SplitChunk(&second, length, &second, &rest);
                    FUN_1400467b0(input, 0, &first);
                    FUN_1400467a8(output, 1, &split);
                    FUN_1400467a8(tracks[index].Queue, 0, &rest);
                    break;
                }
                FUN_1400467a8(tracks[index].Queue, 0, &second);
            }
            ++matched;
        }
    } while (matched != count);
    FUN_1400467a8(output, 1, &first);
drainInput:
    {
        available = FUN_1400467b8(input, 1);
        FUN_1400467a0(input, 1, 0x7fffffff, &first);
        while (first.Size != 0)
        {
            available -= (CriSint32)first.Size;
            if (*first.Data == 0)
            {
                FUN_1400467a8(input, 1, &first);
                FUN_140044fe4(object);
            }
            else
            {
                tail.Data = NULL;
                tail.Size = 0;
                if (criUsfCmn_ParseUsfHeaderStd(first.Data, first.Size, &header) == 0)
                    goto releaseFirst;
                memcpy(&headerSize, header.Data + 4, sizeof(headerSize));
                needed = headerSize + 8;
                if (first.Size < needed)
                {
                    if (available < 1)
                        goto releaseFirst;
                    FUN_1400467a0(input, 1, 0x7fffffff, &tail);
                    if (tail.Size + first.Size < needed)
                    {
                        FUN_1400467a8(input, 1, &tail);
                        goto releaseFirst;
                    }
                    source = &tail;
                    length = (headerSize - first.Size) + 8;
                }
                else
                {
                    source = &first;
                    length = needed;
                }
                criSj_SplitChunk(source, length, source, &second);
                FUN_1400467a8(input, 1, &second);
                memcpy(&type, header.Data, sizeof(type));
                for (index = 0; index < count; ++index)
                {
                    TrackEntry* track = &tracks[index];
                    if (track->Queue != NULL && (track->Type == 0 || track->Type == type) &&
                        (track->Id == 0xffffffffu || track->Id == (CriUint32)header.Data[12]))
                    {
                        if (criSjUni_GetNumChainPool(output) < 3 || criSjUni_GetNumChainPool(track->Queue) < 3)
                            goto releaseTail;
                        FUN_1400467b0(track->Queue, 1, &first);
                        FUN_1400467b0(output, 1, &first);
                        first.Data = NULL;
                        first.Size = 0;
                        if (tail.Data != NULL)
                        {
                            FUN_1400467b0(track->Queue, 1, &tail);
                            FUN_1400467b0(output, 1, &tail);
                            tail.Data = NULL;
                            tail.Size = 0;
                        }
                        break;
                    }
                }
                if (index == count)
                {
releaseTail:
                    if (tail.Data != NULL)
                        FUN_1400467a8(input, 1, &tail);
releaseFirst:
                    FUN_1400467a8(input, 1, &first);
                    return;
                }
            }
            available = FUN_1400467b8(input, 1);
            FUN_1400467a0(input, 1, 0x7fffffff, &first);
        }
    }
    if (demux->Flush == 1)
        demux->State = 2;
}
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
// MS2-FUNCTIONAL: field +0x20 for kind 1, +0x24 for kind 0, else 0.
// @0x140046000
CriSint32 FUN_140046000(cri03_kinds* self, CriSint32 kind)
{
    if (kind == 1)
        return self->k1;
    if (kind == 0)
        return self->k0;
    return 0;
}
#pragma optimize("", on)

void* FUN_140039ea8(void* work, CriSint32 size);
extern "C" void* FUN_140039ea8(void* work, int size);
void* FUN_1400385c8(void* work, CriUint32 size);
extern "C" void* FUN_1400385c8(void* work, unsigned long long size);
