// Recovered CRI Movie decoder and timing helpers from MapleStory2.exe, written from the executable's behavior.
// The CRI Movie 3.07 library was built with VS2008 SP1, and so is this unit (MS2-TOOLSET: vc9, cmake/ms2-unit-profiles.cmake):
// keep it C++03 (no auto, decltype, variadic templates, brace-init or nullptr). clang-cl compiles it as before.
// MS2-UNIT: sfr_cri_03
// MS2-TOOLSET: vc9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140039ea8-0x140046a1c .text$mn
// MS2-RANGE: 0x142ccb000-0x142ccd143 .text$mn
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
extern "C" const char* DAT_143ba9d20;
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
extern "C" const CriChar8 DAT_143a482e8[];
extern "C" const CriUint64 DAT_1431b9ca0;
extern "C" const void* PTR_LAB_143a48350;
extern "C" const void* PTR_FUN_143a48638;
extern "C" const void* PTR_FUN_143a48668;
extern "C" const void* PTR_FUN_1431b9b10;
extern "C" const void* PTR_FUN_1431b4f78;
void FUN_1400532b0(void);
void FUN_1400532d0(void);
void FUN_140041190(void);
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
void FUN_1400467a0(void*, CriSint32, CriSint32, void*);
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
void FUN_140037910(CriSint32, const CriChar8*, CriSint32);
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
CriSint32 criSjUni_CalculateWorkSize(const CriSint32* config);
void* FUN_1400459ec(const void*, void*, CriSint32);
CriSint32 criSjRbf_CalculateWorkSize(const CriSint32* config);
void* FUN_140045eec(const void*, void*, CriSint32);
void FUN_140045998(void*);
void FUN_140045fdc(void*);
void FUN_140045474(void*);
void FUN_14029dd60(void*, const CriChar8*, const void*);

// MS2-FUNCTIONAL: send the supplied CRI diagnostic through the movie error dispatcher.
// @0x1400410d0
void FUN_1400410d0(void* owner, const CriChar8* message, CriUint32 value)
{
    FUN_140038ce4(0, message, (CriSint32)value, 0, owner);
}

// MS2-FUNCTIONAL: the second CRI diagnostic entry point forwards the same tuple to the shared dispatcher.
// @0x140041110
void FUN_140041110(void* owner, const CriChar8* message, CriUint32 value)
{
    FUN_140038ce4(0, message, (CriSint32)value, 0, owner);
}

// MS2-FUNCTIONAL: report the picture decode failure through the generic CRI error callback.
// @0x140041190
void FUN_140041190(void)
{
    FUN_1400410d0(NULL, "E07111401M : An error occurred while decoding picture data in MPV module.", 0);
}

// MS2-FUNCTIONAL: forward the contained synchronization object to its release helper when present.
// @0x1400435d0
void FUN_1400435d0(void* object)
{
    struct SyncHolder { CriUint8 Reserved[0x10]; void* Sync; };
    SyncHolder* holder = (SyncHolder*)object;
    if (holder && holder->Sync)
        FUN_140053570(holder->Sync);
}

// MS2-FUNCTIONAL: increment the movie player's paired audio and video progress counters.
// @0x14003ebe0
void FUN_14003ebe0(void* object)
{
    struct ProgressState { CriUint8 Reserved[0x19c]; CriSint32 Audio; CriSint32 Video; };
    ProgressState* state = (ProgressState*)object;
    ++state->Audio;
    ++state->Video;
}

// MS2-FUNCTIONAL: accept only USF chunks whose parsed standard header has no special record flag.
// @0x14003eeb0
CriBool FUN_14003eeb0(const void* input)
{
    struct Input { const CriUint8* Data; CriUint32 Size; };
    const Input* chunk = (const Input*)input;
    CriUsfStandardHeader header = {};
    if (!criUsfCmn_ParseUsfHeaderStd(chunk->Data, chunk->Size, &header))
        return 0;
    return header.Data[15] == 0;
}

// MS2-FUNCTIONAL: mark the input object active and release its retained work buffer when present.
// @0x14003d8f0
void FUN_14003d8f0(void* object)
{
    struct InputState { CriUint8 Reserved00[0x1c]; CriUint32 Active; CriUint8 Reserved20[0x58]; void* Work; };
    InputState* state = (InputState*)object;
    state->Active = 1;
    if (state->Work)
        FUN_140050e90(state->Work);
}

// MS2-FUNCTIONAL: initialize the CRI timer record from the system clock and clear its elapsed state.
// @0x140041a60
void FUN_140041a60(void* object)
{
    struct TimerState
    {
        CriUint8 Reserved00[0x10];
        CriUint64 Start;
        CriUint8 Reserved18[8];
        CriUint8 Active;
        CriUint8 Reserved21[7];
        CriUint8 Mode;
        CriUint8 Reserved29[7];
        CriUint64 Elapsed;
        CriUint64 SystemStart;
        CriUint64 Reserved40;
    };
    TimerState* state = (TimerState*)object;
    state->Elapsed = 0;
    state->SystemStart = FUN_1425e3510();
    state->Reserved40 = 0;
    state->Mode = 0;
    state->Start = FUN_1425e3560();
    state->Active = 1;
}

// MS2-FUNCTIONAL: translate the reader interface's three states into the movie's public status values.
// @0x140041300
CriUint32 FUN_140041300(void* object)
{
    struct ReaderOwner { CriUint8 Reserved[0x10]; void* Reader; };
    ReaderOwner* owner = (ReaderOwner*)object;
    if (!owner->Reader)
        return 0;
    void** vtable = *(void***)owner->Reader;
    CriSint32 state = ((CriSint32 (*)(void*))vtable[7])(owner->Reader);
    if (state == 0)
        return 0;
    if (state == 1)
        return 1;
    return state == 2 ? 0 : 2;
}

// MS2-FUNCTIONAL: flag the video player and notify its retained work object.
// @0x140043680
void FUN_140043680(void* object)
{
    struct PlayerState
    {
        CriSint32 Type;
        CriUint8 Reserved04[0x0c];
        void* Work;
        CriUint8 Reserved18[0x78];
        CriSint32 Active;
    };
    PlayerState* player = (PlayerState*)object;
    if (player && player->Type)
    {
        player->Active = 1;
        FUN_140053e40(player->Work);
    }
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: allocate and initialize the CRI universal stream-joint object with its executable vtable.
// @0x140046324
void* FUN_140046324(const void* config, void* heap, CriUint32 allocationMode)
{
    CriSint32 workSize = criSjUni_CalculateWorkSize((const CriSint32*)config);
    CriUint8* allocation = (CriUint8*)FUN_140027f7c(heap, workSize + 8, "CriSjUni", 8,
                                                     (CriSint32)allocationMode);
    if (!allocation)
    {
        FUN_140038e24(0, "E09021217B", -3);
        return NULL;
    }
    memcpy(allocation, &heap, sizeof(heap));
    void* object = FUN_1400459ec(config, allocation + 8, workSize);
    if (object)
    {
        *(const void**)object = &PTR_FUN_143a48638;
        return object;
    }
    FUN_140027fb4(heap, allocation);
    return NULL;
}

// MS2-FUNCTIONAL: allocate and initialize the CRI ring-buffer stream-joint object with its executable vtable.
// @0x1400464f4
void* FUN_1400464f4(const void* config, void* heap, CriUint32 allocationMode)
{
    CriSint32 workSize = criSjRbf_CalculateWorkSize((const CriSint32*)config);
    CriUint8* allocation = (CriUint8*)FUN_140027f7c(heap, workSize + 8, "CriSjRbf", 8,
                                                     (CriSint32)allocationMode);
    if (!allocation)
    {
        FUN_140038e24(0, "E09021703B", -3);
        return NULL;
    }
    memcpy(allocation, &heap, sizeof(heap));
    void* object = FUN_140045eec(config, allocation + 8, workSize);
    if (object)
    {
        *(const void**)object = &PTR_FUN_143a48668;
        return object;
    }
    FUN_140027fb4(heap, allocation);
    return NULL;
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
    CriUint8 config[0x18] = {};
    memcpy(config, settings, sizeof(CriUint32));
    memcpy(config + 4, &first, sizeof(first));
    memcpy(config + 8, &second, sizeof(second));
    memcpy(config + 0xc, &third, sizeof(third));
    memcpy(config + 0x10, &poolBytes, sizeof(poolBytes));
    return FUN_1400464f4(config, heap, settings[1]);
}

// MS2-FUNCTIONAL: destroy the universal stream-joint lock and free its heap-prefixed allocation.
// @0x1400463c8
void FUN_1400463c8(void* object)
{
    struct Storage { void* Heap; CriUint8 Payload[1]; };
    Storage* storage = CONTAINING_RECORD((CriUint8*)object, Storage, Payload);
    FUN_140045998(object);
    FUN_140027fb4(storage->Heap, storage);
}

// MS2-FUNCTIONAL: destroy the ring-buffer stream-joint lock and free its heap-prefixed allocation.
// @0x140046598
void FUN_140046598(void* object)
{
    struct Storage { void* Heap; CriUint8 Payload[1]; };
    Storage* storage = CONTAINING_RECORD((CriUint8*)object, Storage, Payload);
    FUN_140045fdc(object);
    FUN_140027fb4(storage->Heap, storage);
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: report whether a stream-joint has completed its terminal audio transition.
// @0x140043810
CriBool FUN_140043810(void* object, void* owner)
{
    struct DecoderState
    {
        CriSint32 Type;
        CriUint8 Reserved04[0x0c];
        void* Work;
        CriUint8 Reserved18[0x18];
        void* Queue;
    };
    DecoderState* decoder = (DecoderState*)object;
    if (!decoder || !owner)
        return 1;
    if (decoder->Type)
    {
        if (FUN_140053630(decoder->Work) != 3)
            return 0;
        if (FUN_1400467b8(decoder->Queue, 1) != 0)
            return 0;
    }
    return 1;
}

// MS2-FUNCTIONAL: check one selected audio decoder, treating a missing list as ready.
// @0x140042df0
CriBool FUN_140042df0(void* decoders, void* owner, CriSint32 index)
{
    if (!decoders)
        return 1;
    return FUN_140043810(((void**)decoders)[index], owner);
}

// MS2-FUNCTIONAL: forward a selected audio decoder's channel query.
// @0x140042f00
void FUN_140042f00(void* decoders, CriSint32 index, void* player, CriUint32 channel)
{
    FUN_140043420(((void**)decoders)[index], player, channel);
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: split a stream chunk, append the selected range, and return bytes left after the requested size.
// @0x1400468f4
CriSint32 FUN_1400468f4(void* streamJoint, const void* chunk, void* suffix, CriUint32 maximum)
{
    struct ChunkView { CriUint64 Begin; CriUint32 Size; };
    const ChunkView* view = (const ChunkView*)chunk;
    CriUint32 copied = maximum;
    CriSint32 remaining = 0;
    if (view->Size <= maximum)
    {
        copied = view->Size;
        remaining = (CriSint32)(maximum - view->Size);
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

// MS2-FUNCTIONAL: return the selected decoder's available sample count in player time units.
// @0x14003d9d0
CriUint32 FUN_14003d9d0(void* object)
{
    struct ReaderState
    {
        CriUint8 Reserved[0x50];
        CriUint32 Unit;
        CriUint32 Reserved54;
        void* Queue;
        void* AddOneUnit;
    };
    ReaderState* reader = (ReaderState*)object;
    CriUint32 samples = (CriUint32)FUN_1400467b8(reader->Queue, 1);
    if (reader->AddOneUnit)
        samples += reader->Unit;
    return samples / reader->Unit;
}

// MS2-FUNCTIONAL: return ready when every stored audio decoder has completed its terminal transition.
// @0x140042d70
CriBool FUN_140042d70(void* decoderList, void* owner)
{
    struct DecoderList { void* Decoders[2]; CriSint32 Count; };
    if (!decoderList)
        return 1;
    DecoderList* list = (DecoderList*)decoderList;
    for (CriSint32 index = 0; index < list->Count; ++index)
        if (!FUN_140043810(list->Decoders[index], owner))
            return 0;
    return 1;
}

// MS2-FUNCTIONAL: forward one decoder's interleaved output request.
// @0x140042e40
void FUN_140042e40(void* decoders, CriSint32 index, void* player, CriUint32 channels,
                   void* output, CriUint32 flags, CriUint32* result)
{
    FUN_140042f40(((void**)decoders)[index], player, channels, output, flags, result);
}

// MS2-FUNCTIONAL: forward one decoder's planar output request.
// @0x140042ea0
void FUN_140042ea0(void* decoders, CriSint32 index, void* player, CriUint32 channels,
                   void* output, CriUint32 flags, CriUint32* result)
{
    FUN_1400431a0(((void**)decoders)[index], player, channels, output, flags, result);
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: calculate universal stream-joint work bytes plus the two aligned block headers.
// @0x140046420
CriSint32 FUN_140046420(CriUint32 first, CriUint32 second, const CriUint32* settings)
{
    CriSint32 headerBytes = FUN_140027dd0(8);
    CriUint32 config[3] = { settings[0], first, second };
    return criSjUni_CalculateWorkSize((const CriSint32*)config) + headerBytes * 2;
}

// MS2-FUNCTIONAL: request work sizing for the default one-block stream-joint setup.
// @0x1400464a8
void FUN_1400464a8(CriUint32 first, CriUint32 second)
{
    const CriUint32 settings[2] = { 0, 1 };
    FUN_140046420(first, second, settings);
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: test stream readiness after the active decoder state and buffered input are checked.
// @0x140040de0
CriBool FUN_140040de0(void* object)
{
    struct ReaderState
    {
        CriUint8 Reserved00[0x1c];
        CriSint32 State;
        CriUint8 Reserved20[0x38];
        void* Queue;
    };
    ReaderState* reader = (ReaderState*)object;
    if (reader->State == 1)
        return 0;
    if (criVmpv_GetStatus(object) != 2)
        return 0;
    return FUN_1400467b8(reader->Queue, 1) != 0;
}

// MS2-FUNCTIONAL: determine whether a USF chunk contains payload beyond its declared standard-header extent.
// @0x14003d6c0
CriBool FUN_14003d6c0(const void* input)
{
    struct Input { const CriUint8* Data; CriUint32 Size; };
    const Input* chunk = (const Input*)input;
    CriUsfStandardHeader header = {};
    if (!criUsfCmn_ParseUsfHeaderStd(chunk->Data, chunk->Size, &header))
        return 0;
    CriUint32 declaredSize = 0;
    memcpy(&declaredSize, header.Data + 4, sizeof(declaredSize));
    return chunk->Size != declaredSize + 8;
}

// MS2-FUNCTIONAL: copy the stream-joint setup header into a zeroed 0xb0-byte local work record.
// @0x14003e6a0
void FUN_14003e6a0(void* target, const CriUint64* settings)
{
    struct SetupRecord { CriUint64 First; CriUint32 Count; CriUint8 Reserved[0xa4]; };
    SetupRecord setup = {};
    setup.First = settings[0];
    memcpy(&setup.Count, settings + 1, sizeof(setup.Count));
    FUN_14003e180(target, &setup);
}

// MS2-FUNCTIONAL: release the pending synchronization object for each member of the audio decoder list.
// @0x1400427b0
void FUN_1400427b0(void* decoderList)
{
    struct DecoderList { void* Decoders[2]; CriSint32 Count; };
    DecoderList* list = (DecoderList*)decoderList;
    for (CriSint32 index = 0; index < list->Count; ++index)
        FUN_1400435d0(list->Decoders[index]);
}

// MS2-FUNCTIONAL: notify every decoder in the audio list that its player is active.
// @0x140042880
void FUN_140042880(void* decoderList)
{
    struct DecoderList { void* Decoders[2]; CriSint32 Count; };
    DecoderList* list = (DecoderList*)decoderList;
    if (list)
        for (CriSint32 index = 0; index < list->Count; ++index)
            FUN_140043680(list->Decoders[index]);
}

// MS2-FUNCTIONAL: release each non-null stream joint owned by the audio track set.
// @0x140043610
void FUN_140043610(void* trackSet)
{
    struct TrackSet
    {
        CriUint8 Reserved00[0x18];
        CriUint32 Count;
        CriUint8 Reserved1c[0x14];
        void** Tracks;
    };
    TrackSet* tracks = (TrackSet*)trackSet;
    if (tracks)
        for (CriUint32 index = 0; index < tracks->Count; ++index)
            if (tracks->Tracks[index])
                FUN_140046798(tracks->Tracks[index]);
}

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

// MS2-FUNCTIONAL: release the manager's input joint and all child audio decoder track sets.
// @0x140042800
void FUN_140042800(void* manager)
{
    struct AudioManager { void* Decoders[2]; CriSint32 Count; void* InputJoint; };
    AudioManager* audio = (AudioManager*)manager;
    if (!audio)
        return;
    if (audio->InputJoint)
        FUN_140046798(audio->InputJoint);
    for (CriSint32 index = 0; index < audio->Count; ++index)
        FUN_140043610(audio->Decoders[index]);
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: pass two variadic formatter arguments to the executable's Scaleform string formatter.
// @0x1400469c4
void FUN_1400469c4(void* string, const CriChar8* format, CriUint64 first, CriUint64 second)
{
    const CriUint64 arguments[2] = { first, second };
    FUN_14029dd60(string, format, arguments);
}
#pragma optimize("", on)

void FUN_1400478a0(void);
void FUN_1400493c0(void);
void FUN_1400479e0(void);
void FUN_14004dc70(void);
CriBool FUN_140024ff0(void);
void FUN_140026f40(CriError&);
void FUN_140024f80(void);
void* FUN_140046324(const void*, void*, CriUint32);
void* FUN_1400464f4(const void*, void*, CriUint32);

// ==== CRI critical-section helpers ================================================================================

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: CRI Base was built with VS2008; this wrapper reproduces its aligned storage and initialization.
// @0x140039ea8
void* criCs_Create(void* work, CriSint32 size)
{
    memset(work, 0, (size_t)size);
    uintptr_t aligned = (uintptr_t)work;
    while ((aligned & 7) != 0)
        ++aligned;
    LPCRITICAL_SECTION section = (LPCRITICAL_SECTION)aligned;
    InitializeCriticalSection(section);
    return section;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; this wrapper destroys and clears the caller's lock storage.
// @0x140039f00
void criCs_Destroy(LPCRITICAL_SECTION section)
{
    DeleteCriticalSection(section);
    memset(section, 0, 0x30);
}

// MS2-FUNCTIONAL: the CRI lock helper tracks recursive depth and its owning thread around EnterCriticalSection.
// @0x140039f50
void FUN_140039f50(LPCRITICAL_SECTION section)
{
    EnterCriticalSection(section);
    CriSint32* depth = (CriSint32*)((CriUint8*)section + 0x2c);
    ++*depth;
    if (*depth == 1)
        *(DWORD*)((CriUint8*)section + 0x28) = GetCurrentThreadId();
}

// MS2-FUNCTIONAL: the CRI lock helper clears its owner at the outermost exit and then leaves the section.
// @0x140039f8c
void FUN_140039f8c(LPCRITICAL_SECTION section)
{
    CriSint32* depth = (CriSint32*)((CriUint8*)section + 0x2c);
    --*depth;
    if (*depth == 0)
        *(DWORD*)((CriUint8*)section + 0x28) = 0;
    LeaveCriticalSection(section);
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
    return (CriUint32)((index + 2 * index) * 16 + 0xb8);
}

// MS2-FUNCTIONAL: releases UTF table allocations and all four lazily allocated fast-search indexes.
// @0x14003a108
void criUtfRtv_Destroy(CriUint64* table)
{
    CriUint64* heap = (CriUint64*)table[0];
    void(__fastcall* freeMem)(void*, void*) = (void(__fastcall*)(void*, void*))heap[1];
    void* heapContext = (void*)heap[2];
    if (table[0xc] != 0 && heap)
        freeMem(heapContext, (void*)table[0x16]);
    for (CriSint32 index = 0; index < 4; ++index)
        if (table[0xe + index * 2] != 0)
            FUN_140046d50(table, index);
    freeMem(heapContext, (void*)table[0x15]);
}
#pragma optimize("", on)

// @0x14003b840
void criMvPly_AttachM2V()
{
    FUN_1400478a0();
    DAT_143b27948 = 1;
}

// @0x14003b880
void FUN_14003b880()
{
    FUN_1400493c0();
    FUN_1400479e0();
    DAT_143b27c40 = 1;
}

// MS2-FUNCTIONAL: register the MPEG video and alpha decoder interfaces with CriMv.
// @0x14003b6e0
void FUN_14003b6e0()
{
    CriMvCodecRegistrationEntry registration = {};
    registration.CodecId = 1;
    registration.VideoDecoderInterface = (void*)FUN_14003bed0();
    registration.AlphaDecoderInterface = (void*)FUN_14003bf10();
    FUN_14002e6e0(&registration);
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: route UTF allocations through the caller's CRI heap using its allocation mode.
// @0x14003b20c
void* FUN_14003b20c(void* heap, CriSint32 size, const CriChar8* name, CriSint32 alignment,
                    CriSint32 allocationMode)
{
    CriSint32 type = 0;
    if (allocationMode >= 0 && allocationMode <= 3)
        type = allocationMode;
    else
        FUN_140038e24(0, "E08092651B", -3);
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
    if (allocationMode >= 0 && allocationMode <= 3)
        type = allocationMode;
    else
        FUN_140038e24(0, "E08092650B", -3);
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

// MS2-FUNCTIONAL: retains CRI's conditional decoder attachment followed by common Movie initialization.
// @0x14003bea0
void CriMv::InitializeMana(CriError& error)
{
    if (!FUN_140024ff0())
        FUN_140026f40(error);
    FUN_140024f80();
}

// @0x14003bed0
const void** FUN_14003bed0()
{
    DAT_143b27c48 = "\ncriVmpv/PCx64 Ver.3.32 Build:Jan 20 2012 18:13:28\n";
    FUN_14004dc70();
    return DAT_143a47bc0;
}

// @0x14003bf10
const void** FUN_14003bf10()
{
    return DAT_143a47cb0;
}

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
// MS2-FUNCTIONAL: the CRI table library was built with VS2008; preserve its field-name scan and 0xffffffff sentinel.
// @0x14003a3e0
CriUint32 criUtfRtv_ConvFieldNameToNo(const CriUtfRtvView* table, const CriChar8* name)
{
    for (CriUint32 i = 0; i < table->FieldCount; ++i)
        if (strcmp(name, table->Columns[i].Name) == 0)
            return i;
    return 0xffffffff;
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
    const CriUtfRtvView::CachedIndex* slot = &table->Slots[slotIndex];
    CriUint32 low = 0;
    CriUint32 high = table->RecordCount;
    while (low < high)
    {
        CriUint32 middle = low + ((high - low) >> 1);
        CriUint32 row = slot->SortedRows[middle];
        const CriChar8* candidate = criUtfRtv_GetDataStr(table, row, slot->Key);
        int order = strcmp(candidate ? candidate : "", name);
        if (order == 0)
            return row;
        if (order < 0)
            low = middle + 1;
        else
            high = middle;
    }
    return 0xffffffff;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; field types 0/2/4 read the executable's byte positions.
// @0x14003a460
CriUint8 criUtfRtv_GetDataUint8(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col;
    const CriUint8* p = criUtfGetRecordField(table, row, field, &col);
    if (!p)
    {
        if (col->HasDefault && col->Type >= 0 && col->Type < 6)
            return (CriUint8)col->DefaultValue[1];
        return 0;
    }
    if (col->Type < 0 || col->Type >= 6)
        return 0;
    return p[col->Type == 0 ? 0 : (col->Type == 2 ? 1 : 3)];
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; this accessor decodes stored integers in network byte order.
// @0x14003a58c
CriUint32 criUtfRtv_GetDataUint32(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col;
    const CriUint8* p = criUtfGetRecordField(table, row, field, &col);
    if (!p)
    {
        if (!col->HasDefault || col->Type < 0 || col->Type >= 6)
            return 0;
        CriUint64 d = col->DefaultValue[1];
        return col->Type < 2 ? (CriUint8)d : (col->Type < 4 ? (CriUint16)d : (CriUint32)d);
    }
    if (col->Type < 0 || col->Type >= 6)
        return 0;
    if (col->Type < 2)
        return p[0];
    if (col->Type < 4)
        return ((CriUint32)p[0] << 8) | p[1];
    return criUtfReadBE32(p);
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
    const CriUtfRtvColumn* col;
    const CriUint8* p = criUtfGetRecordField(table, row, field, &col);
    CriUint32 bits = p ? criUtfReadBE32(p) : (col->HasDefault ? (CriUint32)col->DefaultValue[1] : 0);
    CriFloat32 value;
    memcpy(&value, &bits, sizeof(value));
    return value;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; decode the record's big-endian IEEE double precision bits.
// @0x14003a754
double criUtfRtv_GetDataFloat64(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col;
    const CriUint8* p = criUtfGetRecordField(table, row, field, &col);
    CriUint64 bits = p ? criUtfReadBE64(p) : (col->HasDefault ? col->DefaultValue[1] : 0);
    double value;
    memcpy(&value, &bits, sizeof(value));
    return value;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; string cells hold a big-endian offset into the table string block.
// @0x14003a7f4
const CriChar8* criUtfRtv_GetDataStr(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col;
    const CriUint8* p = criUtfGetRecordField(table, row, field, &col);
    if (!p)
        return col->HasDefault ? (const CriChar8*)col->DefaultValue[1] : NULL;
    CriUint32 offset = criUtfReadBE32(p);
    return offset ? (const CriChar8*)(table->StringData + offset) : NULL;
}

// MS2-FUNCTIONAL: the CRI name-based callback resolves its field, then forwards to the corresponding typed accessor.
// @0x14003a85c
CriUint32 FID_conflict_criUtfRtv_GetDataSint32Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriUint32 field = criUtfRtv_ConvFieldNameToNo(table, name);
    return field == 0xffffffff ? 0 : criUtfRtv_GetDataUint32(table, row, field);
}

// MS2-FUNCTIONAL: this second CRI callback has the same executable body and forwards the resolved field to uint32.
// @0x14003a894
CriUint32 FUN_14003a894(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriUint32 field = criUtfRtv_ConvFieldNameToNo(table, name);
    return field == 0xffffffff ? 0 : criUtfRtv_GetDataUint32(table, row, field);
}

// MS2-FUNCTIONAL: the CRI name-based callback resolves the field before reading a float.
// @0x14003a8cc
CriFloat32 criUtfRtv_GetDataFload32Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriUint32 field = criUtfRtv_ConvFieldNameToNo(table, name);
    return field == 0xffffffff ? 0 : criUtfRtv_GetDataFloat32(table, row, field);
}

// MS2-FUNCTIONAL: the CRI name-based callback resolves the field before reading a double.
// @0x14003a904
double criUtfRtv_GetDataFloat64Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriUint32 field = criUtfRtv_ConvFieldNameToNo(table, name);
    return field == 0xffffffff ? 0 : criUtfRtv_GetDataFloat64(table, row, field);
}

// MS2-FUNCTIONAL: the CRI name-based callback resolves the field before reading a string.
// @0x14003a940
const CriChar8* criUtfRtv_GetDataStrFn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriUint32 field = criUtfRtv_ConvFieldNameToNo(table, name);
    return field == 0xffffffff ? NULL : criUtfRtv_GetDataStr(table, row, field);
}

// MS2-FUNCTIONAL: the CRI name-based callback resolves the field before reading a byte.
// @0x14003a978
CriUint8 criUtfRtv_GetDataUint8Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriUint32 field = criUtfRtv_ConvFieldNameToNo(table, name);
    return field == 0xffffffff ? 0 : criUtfRtv_GetDataUint8(table, row, field);
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
    const CriUtfRtvColumn* col = &table->Columns[field];
    CriSint32 rounded = alignment - 1;
    CriUint32 mask = (CriUint32)-(CriSint32)alignment & ~((CriUint32)alignment - 1);
    CriSint32 sum = 0;
    if (col->Type == 2 || col->Type == 4)
    {
        if (col->IsRecordField)
        {
            const CriUint8* p = table->RecordData + (CriUint32)table->RecordSize * firstRow + col->DataOffset;
            do
            {
                CriUint32 value = col->Type == 2 ? (((CriUint32)p[0] << 8) | p[1]) : criUtfReadBE32(p);
                sum += (CriSint32)((value + rounded) & mask);
                p += table->RecordSize;
            } while (--count >= 0);
            return sum;
        }
        if (col->Type == 2)
            return (CriSint32)(CriUint16)((CriUint16)col->DefaultValue[1] + (CriUint16)rounded & (CriUint16)mask) * count;
        return (CriSint32)(((CriUint32)col->DefaultValue[1] + rounded) & mask) * count;
    }
    return 0;
}

// MS2-FUNCTIONAL: this 64-bit variant shares the executable's row iteration and alignment rounding behavior.
// @0x14003adac
CriUint64 FUN_14003adac(const CriUtfRtvView* table, CriUint32 firstRow, CriSint32 count,
                        CriUint32 field, CriSint32 alignment)
{
    return (CriUint64)(CriUint32)criUtfRtv_SumWithAlignment32(table, firstRow, count, field, alignment);
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
    if (!criUsfCmn_GetChunkIdAndSIze(data, size, &id, &chunkSize))
        return NULL;
    CriUint8 headerSize = data[9];
    if (size < 0x10 || headerSize == 0)
        return NULL;
    *contentSize = (CriSint32)(chunkSize - ((CriUint32)data[10] << 8 | data[11]) - headerSize);
    return data + headerSize + 8;
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: CRI Movie computes the caller's decoder work size from the requested handle count.
// @0x14003bf30
CriSint32 criVmpv_CalcMovieHandleWork(CriSint32 count)
{
    return count * 0x8000 + 0x2084;
}

// MS2-FUNCTIONAL: install the caller's VMPV work buffer after validating its size and global handle state.
// @0x14003bf80
CriBool FUN_14003bf80(CriUint32 count, void* work, CriUint32 workSize)
{
    if (DAT_143b27c68 != 0)
    {
        FUN_140041110(NULL, "E08102801M: SetupMovieHandleWork is already active.", DAT_143b27c68);
        return 0;
    }
    if (!work)
    {
        DAT_143b27c6c = 0;
        DAT_143b27c70 = 0;
        return 1;
    }
    CriUint32 required = (CriUint32)criVmpv_CalcMovieHandleWork((CriSint32)count);
    if (workSize < required)
    {
        FUN_140041110(NULL, "E08102802M: SetupMovieHandleWork buffer is too small.", workSize);
        return 0;
    }
    DAT_143b27c6c = count;
    DAT_143b27c70 = (CriUint64)(uintptr_t)work;
    return 1;
}

// MS2-FUNCTIONAL: return the configured movie handle limit or the default limit of sixteen.
// @0x14003c030
CriUint32 criVmpv_GetMaxNumberOfHandles(void)
{
    return DAT_143b27c70 == 0 ? 0x10 : DAT_143b27c6c;
}

// MS2-FUNCTIONAL: expose the configured movie handle count and work buffer.
// @0x14003c060
void* FUN_14003c060(CriUint32* count)
{
    *count = DAT_143b27c6c;
    return (void*)(uintptr_t)DAT_143b27c70;
}

// MS2-FUNCTIONAL: include the configured internal frame pool in the requested count.
// @0x14003c350
CriSint32 decideInternalFramePoolNum(CriSint32 count)
{
    return count == 0 ? (CriSint32)DAT_143b27c60 : count - 1 + (CriSint32)DAT_143b27c60;
}

// MS2-FUNCTIONAL: set the VMPV handle's processor-mask condition on its MPV instance.
// @0x14003c9a0
void criVmpv_SetProcessorMask(void* handle, CriUint32 mask)
{
    void* mpv = NULL;
    if (handle)
        memcpy(&mpv, (CriUint8*)handle + 0x78, sizeof(mpv));
    FUN_14004e2f0(mpv, 0xd, (CriSint32)mask);
}

// MS2-FUNCTIONAL: pack up to three horizontal and vertical DLG parameters for the MPV core.
// @0x14003ca00
void FUN_14003ca00(void* context, CriSint32 count, const CriSint32* horizontal,
                   const CriSint32* vertical)
{
    (void)context;
    CriSint32 active = count > 3 ? 3 : count;
    CriSint32 parameters[10] = {};
    for (CriSint32 i = 0; i < active; ++i)
    {
        parameters[i * 3] = horizontal[i];
        parameters[i * 3 + 1] = vertical[i];
        parameters[i * 3 + 2] = 0x5a5a5a5a;
    }
    FUN_1400500b0(active, parameters);
}

// MS2-FUNCTIONAL: return the VMPV handle's current status field.
// @0x14003cc70
CriSint32 criVmpv_GetStatus(const void* handle)
{
    CriSint32 status;
    memcpy(&status, (const CriUint8*)handle + 0x18, sizeof(status));
    return status;
}

// MS2-FUNCTIONAL: create and configure the MPV instance owned by a VMPV handle.
// @0x14003c8d0
CriBool createMpvHn(void* handle)
{
    void* mpv = FUN_14004e580();
    memcpy((CriUint8*)handle + 0x78, &mpv, sizeof(mpv));
    if (!mpv)
    {
        CriSint32 error = 4;
        memcpy((CriUint8*)handle + 0x18, &error, sizeof(error));
        return 0;
    }
    FUN_14004e2f0(mpv, 6, 3);
    FUN_14004e2f0(mpv, 1, 0);
    FUN_14004ff90(mpv, (void*)FUN_140041190, NULL);
    return 1;
}

// MS2-FUNCTIONAL: build a VMPV handle with its decoder instance, frame pool, and stream joints.
// @0x14003c390
void* FUN_14003c390(void* heap, const CriUint32* config)
{
    if (!heap)
        return NULL;
    CriUint32 width, height, requestedFrames, optionA, optionB;
    CriUint64* config64 = (CriUint64*)config;
    memcpy(&width, config, sizeof(width));
    memcpy(&height, config + 1, sizeof(height));
    memcpy(&requestedFrames, config + 4, sizeof(requestedFrames));
    memcpy(&optionA, config + 8, sizeof(optionA));
    memcpy(&optionB, config + 9, sizeof(optionB));
    void* source = NULL;
    memcpy(&source, config64 + 3, sizeof(source));

    CriUint8* handle = (CriUint8*)FUN_140027ed8(heap, 600, "CriVmpv__HnObj", 4);
    if (!handle)
    {
        FUN_140041110(NULL, "E05070701M: Can't allocate vmpv handle.", 600);
        return NULL;
    }
    memset(handle, 0, 600);
    memcpy(handle + 0x10, &heap, sizeof(heap));
    if (!createMpvHn(handle))
    {
        FUN_14003cae0(handle);
        return NULL;
    }
    void* outputJoint = FUN_1400464c8(heap, 0, 0x20);
    memcpy(handle + 0x180, &outputJoint, sizeof(outputJoint));
    if (!outputJoint)
    {
        FUN_1400410d0(NULL, "E05070702M: Can't create stream joint.", 0);
        FUN_14003cae0(handle);
        return NULL;
    }
    CriUint32 frameCount = (CriUint32)decideInternalFramePoolNum((CriSint32)requestedFrames);
    memcpy(handle + 0x28, &width, sizeof(width));
    memcpy(handle + 0x2c, &height, sizeof(height));
    memcpy(handle + 0x30, &frameCount, sizeof(frameCount));
    CriUint32 poolBase;
    memcpy(&poolBase, &DAT_143b27c60, sizeof(poolBase));
    memcpy(handle + 0x34, &poolBase, sizeof(poolBase));
    CriUint32 format = 0x7512;
    memcpy(handle + 0x38, &format, sizeof(format));
    memcpy(handle + 0x3c, &frameCount, sizeof(frameCount));
    CriUint32 paddedWidth = (width + 0x0f) & ~0x0f;
    CriUint32 paddedHeight = (height + 0x1f) & ~0x1f;
    CriUint32 frameBytes = (((paddedWidth + 0x7f) & ~0x7f) * paddedHeight) +
                           (((paddedWidth / 2 + 0x7f) & ~0x7f) * (paddedHeight / 2)) * 2;
    memcpy(handle + 0x40, &frameBytes, sizeof(frameBytes));
    CriUint32 frameRecordBytes = 200;
    memcpy(handle + 0x50, &frameRecordBytes, sizeof(frameRecordBytes));

    size_t recordsBytes = (size_t)frameRecordBytes * frameCount;
    CriUint8* records = (CriUint8*)FUN_140027ed8(heap, (CriSint32)(recordsBytes + 4),
                                                 "CriVmpv__FrmPoolInfoAry", 4);
    memcpy(handle + 0x48, &records, sizeof(records));
    if (!records)
    {
        FUN_140041110(NULL, "E05092801M: Can't allocate frame pool info.",
                      (CriUint32)recordsBytes);
        FUN_14003cae0(handle);
        return NULL;
    }
    memset(records, 0, recordsBytes);
    for (CriUint32 i = 0; i < frameCount; ++i)
    {
        CriUint8* frame = (CriUint8*)FUN_140027ed8(heap, (CriSint32)frameBytes,
                                                   "CriVmpv__FrmPoolBuf", 0x800);
        memcpy(records + (size_t)i * frameRecordBytes, &frame, sizeof(frame));
        if (!frame)
        {
            FUN_140041110(NULL, "E05070902M: Can't allocate frame buffer.", frameBytes);
            FUN_14003cae0(handle);
            return NULL;
        }
        memcpy(records + (size_t)i * frameRecordBytes + 8, &frameBytes, sizeof(frameBytes));
    }
    void* frameJoint = FUN_1400464c8(heap, 0, frameCount);
    memcpy(handle + 0x58, &frameJoint, sizeof(frameJoint));
    if (!frameJoint)
    {
        FUN_1400410d0(NULL, "E05070903M: Can't create frame pool stream joint.", 0);
        FUN_14003cae0(handle);
        return NULL;
    }

    if (source)
    {
        void* decoder = (void*)FUN_14004fe20(source, optionA, optionB);
        memcpy(handle + 0x220, &decoder, sizeof(decoder));
    }
    memcpy(handle + 0x228, &source, sizeof(source));
    memcpy(handle + 0x230, &optionA, sizeof(optionA));
    memcpy(handle + 0x234, &optionB, sizeof(optionB));
    CriSint32 zero = 0;
    memcpy(handle + 0x238, &zero, sizeof(zero));
    memcpy(handle + 0x23c, &zero, sizeof(zero));
    memcpy(handle + 0x18, &zero, sizeof(zero));
    CriSint32 active = 1;
    memcpy(handle + 8, &active, sizeof(active));
    return handle;
}

// MS2-FUNCTIONAL: release MPV and stream-memory subsystems when the final initializer reference ends.
// @0x14003c130
void FUN_14003c130(void)
{
    --DAT_143b27c68;
    if (DAT_143b27c68 == 0)
    {
        FUN_14004e250();
        FUN_14004eb70();
        FUN_14004f8d0();
    }
}

// MS2-FUNCTIONAL: size the VMPV frame pool, output records, and its two stream-joint work areas.
// @0x14003c190
CriSint32 FUN_14003c190(CriSint32 width, CriSint32 height, CriSint32 requestedFrames)
{
    CriUint32 frameCount = (CriUint32)decideInternalFramePoolNum(requestedFrames);
    CriUint32 paddedWidth = ((CriUint32)width + 0x0f) & ~0x0f;
    CriUint32 paddedHeight = ((CriUint32)height + 0x1f) & ~0x1f;
    CriUint32 luma = ((paddedWidth + 0x7f) & ~0x7f) * paddedHeight;
    CriUint32 chromaWidth = ((paddedWidth / 2 + 0x7f) & ~0x7f);
    CriUint32 chromaHeight = paddedHeight / 2;
    CriUint32 frameBytes = luma + chromaWidth * chromaHeight * 2;
    const CriUint32 settings[2] = { 1, 1 };
    CriSint32 total = 0x25c;
    total += FUN_140046420(0, 0x20, settings);
    total += (CriSint32)(200 * frameCount + 4);
    for (CriUint32 i = 0; i < frameCount; ++i)
        total += (CriSint32)(frameBytes + 0x800);
    total += FUN_140046420(0, frameCount, settings);
    return total;
}

// MS2-FUNCTIONAL: release the MPV handle, stream joints, frame buffers, and owning VMPV allocation.
// @0x14003cae0
void FUN_14003cae0(void* handle)
{
    CriUint8* bytes = (CriUint8*)handle;
    CriSint32 zero = 0;
    memcpy(bytes + 8, &zero, sizeof(zero));
    memcpy(bytes + 0x18, &zero, sizeof(zero));
    void* heap;
    void* mpv;
    void* frameJoint;
    void* frames;
    void* inputJoint;
    memcpy(&heap, bytes + 0x10, sizeof(heap));
    memcpy(&mpv, bytes + 0x78, sizeof(mpv));
    memcpy(&frameJoint, bytes + 0x58, sizeof(frameJoint));
    memcpy(&frames, bytes + 0x48, sizeof(frames));
    memcpy(&inputJoint, bytes + 0x180, sizeof(inputJoint));

    void* decoder = NULL;
    memcpy(&decoder, bytes + 0x220, sizeof(decoder));
    if (decoder)
    {
        void** vtable = *(void***)decoder;
        ((void (*)(void*))vtable[3])(decoder);
        decoder = NULL;
        memcpy(bytes + 0x220, &decoder, sizeof(decoder));
    }
    if (frameJoint)
    {
        FUN_140046784(frameJoint);
        frameJoint = NULL;
        memcpy(bytes + 0x58, &frameJoint, sizeof(frameJoint));
    }
    if (frames)
    {
        CriUint32 frameCount;
        memcpy(&frameCount, bytes + 0x3c, sizeof(frameCount));
        for (CriUint32 i = 0; i < frameCount; ++i)
        {
            void* frame = NULL;
            memcpy(&frame, (CriUint8*)frames + (size_t)i * 200, sizeof(frame));
            if (frame)
                FUN_140027fb4(heap, frame);
        }
        FUN_140027fb4(heap, frames);
    }
    if (inputJoint)
    {
        FUN_140046784(inputJoint);
        inputJoint = NULL;
        memcpy(bytes + 0x180, &inputJoint, sizeof(inputJoint));
    }
    if (mpv)
        FUN_14004e2a0(mpv);
    FUN_140027fb4(heap, handle);
}

// MS2-FUNCTIONAL: drain pending VMPV input, reset frame records, and restore the ready handle state.
// @0x14003cdd0
void FUN_14003cdd0(void* handle)
{
    CriUint8* bytes = (CriUint8*)handle;
    CriSint32 inactive = 0;
    memcpy(bytes + 8, &inactive, sizeof(inactive));
    CriUint8 chunk[16] = {};
    void* inputJoint = NULL;
    memcpy(&inputJoint, bytes + 0x180, sizeof(inputJoint));
    while (FUN_1400467b8(inputJoint, 2) != 0)
    {
        FUN_1400467a0(inputJoint, 2, -1, chunk);
        FUN_1400467b0(inputJoint, 0, chunk);
    }
    if (inputJoint)
        FUN_140046798(inputJoint);

    memset(bytes + 400, 0, 0x18);
    memset(bytes + 0x188, 0, 8);
    void* frameJoint = NULL;
    CriUint8* frameRecords = NULL;
    CriUint32 frameCount, recordBytes;
    memcpy(&frameJoint, bytes + 0x58, sizeof(frameJoint));
    memcpy(&frameRecords, bytes + 0x48, sizeof(frameRecords));
    memcpy(&frameCount, bytes + 0x3c, sizeof(frameCount));
    memcpy(&recordBytes, bytes + 0x50, sizeof(recordBytes));
    FUN_140046798(frameJoint);
    memset(bytes + 0x60, 0, 12);
    for (CriUint32 i = 0; i < frameCount; ++i)
    {
        CriUint8* record = frameRecords + (size_t)i * 200;
        memset(record + 0x10, 0, 0xb0);
        struct QueueRecord { void* Data; CriUint64 Size; } queueRecord = { record, recordBytes };
        FUN_1400467b0(frameJoint, 0, &queueRecord);
    }
    memset(bytes + 0x90, 0, sizeof(void*));
    memset(bytes + 0xb0, 0, sizeof(void*));
    memset(bytes + 0xd0, 0, sizeof(void*));
    memset(bytes + 0x70, 0, sizeof(void*));
    CriSint32 active = 1;
    CriSint32 status = 0;
    memcpy(bytes + 8, &active, sizeof(active));
    memcpy(bytes + 0x18, &status, sizeof(status));
}

// MS2-FUNCTIONAL: advance VMPV input consumption and move the handle through decode and ready states.
// @0x14003cca0
void FUN_14003cca0(void* handle)
{
    CriUint8* bytes = (CriUint8*)handle;
    CriSint32 state, open, ready;
    memcpy(&state, bytes + 0x1c, sizeof(state));
    memcpy(&open, bytes + 0x24, sizeof(open));
    if (state == 1)
    {
        if (open == 1)
            return;
        FUN_14003cdd0(handle);
        state = 0;
        memcpy(bytes + 0x18, &state, sizeof(state));
        memcpy(bytes + 0x1c, &state, sizeof(state));
    }
    memcpy(&state, bytes + 0x18, sizeof(state));
    if (state == 1 || state == 2)
        for (CriSint32 i = 0; i < 7; ++i)
            FUN_14003cff0(handle);

    memcpy(&state, bytes + 0x18, sizeof(state));
    if (state == 1)
    {
        CriUint32 pictures;
        memcpy(&pictures, bytes + 0x188, sizeof(pictures));
        if (pictures >= 2)
            state = 2;
        else
        {
            memcpy(&ready, bytes + 0x20, sizeof(ready));
            if (ready == 1)
                state = 2;
        }
        memcpy(bytes + 0x18, &state, sizeof(state));
    }
    memcpy(&state, bytes + 0x18, sizeof(state));
    memcpy(&ready, bytes + 0x20, sizeof(ready));
    if (state == 2 && ready == 1)
    {
        CriUint32 consumed, buffered;
        memcpy(&consumed, bytes + 0x18c, sizeof(consumed));
        memcpy(&buffered, bytes + 400, sizeof(buffered));
        CriUint32 additional;
        memcpy(&additional, bytes + 0x1a4, sizeof(additional));
        if (consumed <= buffered + additional)
        {
            state = 3;
            memcpy(bytes + 0x18, &state, sizeof(state));
        }
    }
}

// MS2-FUNCTIONAL: append a decoded-frame timestamp to the bounded history ring.
// @0x14003d550
void FUN_14003d550(void* handle)
{
    CriUint8* bytes = (CriUint8*)handle;
    CriUint32 index = 0;
    CriUint32 slot = 0;
    for (; index < 8; ++index)
    {
        CriUint32 timestamp;
        memcpy(&timestamp, bytes + 0x1b8 + (size_t)index * 8, sizeof(timestamp));
        if (timestamp == 0)
        {
            slot = index;
            break;
        }
    }
    if (index == 8)
    {
        CriUint32 oldest;
        memcpy(&oldest, bytes + 0x1b8, sizeof(oldest));
        memcpy(bytes + 500, &oldest, sizeof(oldest));
        for (index = 0; index < 8; ++index)
        {
            if (index < 7)
            {
                memcpy(bytes + 0x1b4 + (size_t)index * 8,
                       bytes + 0x1b4 + (size_t)(index + 1) * 8, sizeof(CriUint32));
                memcpy(bytes + 0x1b8 + (size_t)index * 8,
                       bytes + 0x1b8 + (size_t)(index + 1) * 8, sizeof(CriUint32));
            }
            else
            {
                CriUint32 zero = 0;
                memcpy(bytes + 0x1b4 + (size_t)index * 8, &zero, sizeof(zero));
                memcpy(bytes + 0x1b8 + (size_t)index * 8, &zero, sizeof(zero));
            }
        }
        slot = 7;
    }
    CriUint32 timestamp, frameNumber;
    CriSint32 offset;
    memcpy(&timestamp, bytes + 0x1b0, sizeof(timestamp));
    memcpy(bytes + 0x1b4 + (size_t)slot * 8, &timestamp, sizeof(timestamp));
    memcpy(&frameNumber, bytes + 0x18c, sizeof(frameNumber));
    memcpy(&offset, bytes + 0x238, sizeof(offset));
    CriUint32 adjusted = offset < 1 ? frameNumber : frameNumber + (CriUint32)offset;
    memcpy(bytes + 0x1b8 + (size_t)slot * 8, &adjusted, sizeof(adjusted));
}

// MS2-FUNCTIONAL: publish the primary video and alpha output buffers on a movie handle.
// @0x14003d4b0
void FUN_14003d4b0(void* handle, void* videoBuffer, void* alphaBuffer)
{
    memcpy((CriUint8*)handle + 0x200, &videoBuffer, sizeof(videoBuffer));
    memcpy((CriUint8*)handle + 0x208, &alphaBuffer, sizeof(alphaBuffer));
}

// MS2-FUNCTIONAL: publish the secondary video and alpha output buffers on a movie handle.
// @0x14003d500
void FUN_14003d500(void* handle, void* videoBuffer, void* alphaBuffer)
{
    memcpy((CriUint8*)handle + 0x210, &videoBuffer, sizeof(videoBuffer));
    memcpy((CriUint8*)handle + 0x218, &alphaBuffer, sizeof(alphaBuffer));
}

// MS2-FUNCTIONAL: return the frame pointer currently stored in a CRI VMPV handle.
// @0x14003d940
void* FUN_14003d940(void* handle)
{
    void* frame;
    memcpy(&frame, (CriUint8*)handle + 0x180, sizeof(frame));
    return frame;
}

// MS2-FUNCTIONAL: mark the VMPV handle's frame-ready flag.
// @0x14003d970
void FUN_14003d970(void* handle)
{
    CriUint32 ready = 1;
    memcpy((CriUint8*)handle + 0x20, &ready, sizeof(ready));
}

// MS2-FUNCTIONAL: return the number of picture records held by a video decoder.
// @0x14003d9a0
CriUint32 criVdecCmn_GetNumPictureData(const void* decoder)
{
    CriUint32 count;
    memcpy(&count, (const CriUint8*)decoder + 0x188, sizeof(count));
    return count;
}

CriSint32 FUN_1400532e0(CriSint32 count);

// MS2-FUNCTIONAL: size the CRI decoder's rolling output records and per-channel stream buffers.
// @0x140042150
CriSint32 FUN_140042150(const void* decoder, const CriUint32* config)
{
    CriUint32 channels, rate;
    memcpy(&channels, (const CriUint8*)config + 4, sizeof(channels));
    memcpy(&rate, (const CriUint8*)config + 0xc, sizeof(rate));
    CriSint32 blockSize = 0x9c + FUN_1400532e0((CriSint32)channels);
    CriUint32 decoderWidth;
    memcpy(&decoderWidth, (const CriUint8*)decoder + 0xe1c, sizeof(decoderWidth));
    CriUint32 bufferCount = decoderWidth * 0xc80 / channels;
    CriUint32 streamBytes = rate * decoderWidth + bufferCount * decoderWidth;
    const CriUint32 settings[2] = { 1, 1 };
    for (CriUint32 i = 0; i < channels; ++i)
        blockSize += FUN_140046604(streamBytes, decoderWidth * 0x840, 4, settings);
    return blockSize;
}

void FUN_14257da20(void*, void*);
CriUint32 FUN_14257c0c0(void*);
void FUN_14257c050(void*, CriUint32, void*);

// MS2-FUNCTIONAL: resolve and cache the decoder instance from its media interface and owner state.
// @0x140041910
void* FUN_140041910(void** decoderObject, void** mediaInterface)
{
    if (decoderObject[2])
        return decoderObject[2];
    // the second argument is the media object itself; the exe calls through its own vtable (0x140041941 rbp = [rdx])
    void* mediaObject = mediaInterface;
    void** decoderVtable = *(void***)decoderObject;
    void** mediaVtable = *(void***)mediaObject;
    CriUint32 codec = ((CriUint32 (*)(void*))decoderVtable[15])(decoderObject);
    CriUint8 outputInfo[8] = {};
    CriUint64 output = ((CriUint64 (*)(void*, void*))decoderVtable[5])(decoderObject, outputInfo);
    CriUint32 channels = ((CriUint32 (*)(void*))decoderVtable[7])(decoderObject);
    CriUint32 format = ((CriUint32 (*)(void*))decoderVtable[4])(decoderObject);
    void* instance = ((void* (*)(void*, CriUint32, CriUint32, CriUint64, CriUint32,
                                  void*, void*))mediaVtable[1])(
        mediaObject, format, channels, output, codec, decoderObject, NULL);
    FUN_14257da20(decoderObject, instance);
    return instance;
}

// MS2-FUNCTIONAL: clear the output buffers supplied for each available decoder picture plane.
// @0x140041390
void FUN_140041390(void* owner, void* outputSet)
{
    (void)owner;
    struct OutputBuffer
    {
        CriUint32 Format;
        CriUint32 Flags;
        void* Reserved;
        size_t Size;
        void* Data;
    } outputs[4] = {};
    CriUint32 count = FUN_14257c0c0(outputSet);
    if (count >= 3)
    {
        for (CriUint32 i = 0; i < 3; ++i)
        {
            FUN_14257c050(outputSet, i, &outputs[i]);
            memset(outputs[i].Data, 0, outputs[i].Size);
        }
        count = FUN_14257c0c0(outputSet);
        if (count < 4)
            return;
    }
    FUN_14257c050(outputSet, count < 3 ? 0 : 3, &outputs[3]);
    memset(outputs[3].Data, 0, outputs[3].Size);
}

#include "../include/cri/cri_decodercall.h"

// MS2-FUNCTIONAL: query the status callback in the alpha decoder interface.
// @0x140043cb0
CriSint32 FUN_140043cb0(void* decoder)
{
    return criDecoderCall<CriSint32>(decoder, 0x30, 0);
}

// MS2-FUNCTIONAL: execute the alpha decoder when it has an execution callback.
// @0x140043d00
void FUN_140043d00(void* decoder)
{
    criDecoderCallVoid(decoder, 0x38);
}

// MS2-FUNCTIONAL: decode one alpha frame and return the decoder's result.
// @0x140043d40
CriBool FUN_140043d40(void* decoder)
{
    return criDecoderCall<CriBool>(decoder, 0x40, 0);
}

// MS2-FUNCTIONAL: request the alpha decoder to skip its current frame.
// @0x140043d90
void FUN_140043d90(void* decoder)
{
    criDecoderCallVoid(decoder, 0x50);
}

// MS2-FUNCTIONAL: request the alpha decoder to stop.
// @0x140043dd0
void FUN_140043dd0(void* decoder)
{
    criDecoderCallVoid(decoder, 0x58);
}

// MS2-FUNCTIONAL: run the alpha decoder's completion callback.
// @0x140043e20
void FUN_140043e20(void* decoder)
{
    criDecoderCallVoid(decoder, 0x60);
}

// MS2-FUNCTIONAL: retrieve the alpha decoder's completion state.
// @0x140043e60
CriSint32 FUN_140043e60(void* decoder)
{
    return criDecoderCall<CriSint32>(decoder, 0x68, 0);
}

// MS2-FUNCTIONAL: query the number of alpha decoder frame pools.
// @0x140043eb0
CriUint32 criAlphaDec_GetNumDecPool(void* decoder)
{
    return criDecoderCall<CriUint32>(decoder, 0x70, 0);
}

// MS2-FUNCTIONAL: retrieve the next alpha frame metadata record.
// @0x140043f10
void* FUN_140043f10(void* decoder, void* frameInfo)
{
    return criDecoderCall<void*>(decoder, 0x78, NULL, frameInfo);
}

// MS2-FUNCTIONAL: ask the alpha decoder to copy a frame into the requested output buffers.
// @0x140043f70
CriBool criAlphaDec_CopyAlphaFrameBuffer(void* decoder, void* buffers, void* frameInfo)
{
    return criDecoderCall<CriBool>(decoder, 0x80, 0, buffers, frameInfo);
}

// MS2-FUNCTIONAL: destroy an alpha decoder, clear its wrapper, and release the wrapper allocation.
// @0x140043be0
void FUN_140043be0(void* decoder)
{
    if (!decoder)
        return;
    void** object = (void**)decoder;
    if (!object[1])
        return;
    void** apiTable = (void**)object[1];
    typedef void (*DestroyCallback)(void*);
    DestroyCallback destroy = (DestroyCallback)apiTable[0x20 / sizeof(void*)];
    if (!destroy)
        return;
    destroy(object[0]);
    object[0] = NULL;
    object[1] = NULL;
    FUN_140027fb4(object[2], decoder);
}

// MS2-FUNCTIONAL: retrieve an alpha decoder frame pointer through its callback table.
// @0x140043fe0
void* FUN_140043fe0(void* decoder, void* frameInfo)
{
    return criDecoderCall<void*>(decoder, 0x90, NULL, frameInfo);
}

// MS2-FUNCTIONAL: query the video decoder's current status.
// @0x140044630
CriSint32 FUN_140044630(void* decoder)
{
    return criDecoderCall<CriSint32>(decoder, 0x30, 0);
}

// MS2-FUNCTIONAL: decode one frame through the video decoder interface.
// @0x1400446c0
CriBool FUN_1400446c0(void* decoder)
{
    return criDecoderCall<CriBool>(decoder, 0x40, 0);
}

// MS2-FUNCTIONAL: invoke the video decoder's frame skip callback.
// @0x140044710
void FUN_140044710(void* decoder)
{
    criDecoderCallVoid(decoder, 0x50);
}

// MS2-FUNCTIONAL: request the video decoder to stop.
// @0x140044750
void FUN_140044750(void* decoder)
{
    criDecoderCallVoid(decoder, 0x58);
}

// MS2-FUNCTIONAL: invoke the video decoder's completion callback.
// @0x140044790
void FUN_140044790(void* decoder)
{
    criDecoderCallVoid(decoder, 0x60);
}

// MS2-FUNCTIONAL: query the video decoder's completion state.
// @0x1400447d0
CriSint32 FUN_1400447d0(void* decoder)
{
    return criDecoderCall<CriSint32>(decoder, 0x68, 0);
}

// MS2-FUNCTIONAL: query the video decoder's frame-pool count.
// @0x140044820
CriUint32 criVdec_GetNumDecPool(void* decoder)
{
    return criDecoderCall<CriUint32>(decoder, 0x70, 0);
}

// MS2-FUNCTIONAL: retrieve the next video frame metadata record.
// @0x140044870
void* criVdec_GetNextFrameInfo(void* decoder, void* frameInfo)
{
    return criDecoderCall<void*>(decoder, 0x78, NULL, frameInfo);
}

// MS2-FUNCTIONAL: request a video decoder frame buffer using the supplied format and output data.
// @0x1400448d0
CriBool criVdec_GetFrameBuffer(void* decoder, void* format, CriUint32 mode, void* output)
{
    return criDecoderCall<CriBool>(decoder, 0x80, 0, format, mode, output);
}

// MS2-FUNCTIONAL: copy video decoder frame planes to the caller's output buffers.
// @0x140044950
CriBool criVdec_CopyFrameYuvBuffers(void* decoder, void* output, void* frameInfo)
{
    return criDecoderCall<CriBool>(decoder, 0x88, 0, output, frameInfo);
}

// MS2-FUNCTIONAL: retrieve a decoded video frame pointer.
// @0x1400449c0
void* FUN_1400449c0(void* decoder, void* frameInfo)
{
    return criDecoderCall<void*>(decoder, 0x90, NULL, frameInfo);
}

// MS2-FUNCTIONAL: release a video decoder frame pointer.
// @0x140044a30
void FUN_140044a30(void* decoder, void* frameInfo)
{
    criDecoderCallVoid(decoder, 0x98, frameInfo);
}

// MS2-FUNCTIONAL: retrieve the decoder's video parameters.
// @0x140044a90
void criVdec_GetVideoParameter(void* decoder, void* parameters)
{
    criDecoderCallVoid(decoder, 0xa0, parameters);
}

// MS2-FUNCTIONAL: ask the decoder to skip its current frame.
// @0x140044ae0
void FUN_140044ae0(void* decoder)
{
    criDecoderCallVoid(decoder, 0x48);
}

// MS2-FUNCTIONAL: query the decoder's concatenated stream offset.
// @0x140044b20
void FUN_140044b20(void* decoder, CriUint32 stream, void* offset, void* timestamp)
{
    criDecoderCallVoid(decoder, 0xa8, stream, offset, timestamp);
}

// MS2-FUNCTIONAL: retrieve decoder frame-pool metadata through the interface callback.
// @0x140044b90
void FUN_140044b90(void* decoder, void* a, void* b, void* c, void* d, void* e)
{
    criDecoderCallVoid(decoder, 0xb0, a, b, c, d, e);
}

// MS2-FUNCTIONAL: configure the alpha decoder processor mask.
// @0x140044c10
void FUN_140044c10(void* decoder, CriUint32 mask)
{
    criDecoderCallVoid(decoder, 0xb8, mask);
}

// MS2-FUNCTIONAL: configure the video decoder seek position and mode.
// @0x140044c60
void FUN_140044c60(void* decoder, CriUint32 position, CriUint32 mode)
{
    criDecoderCallVoid(decoder, 0xc0, position, mode);
}

// MS2-FUNCTIONAL: set the video decoder's notification callback and user data.
// @0x140044cc0
void FUN_140044cc0(void* decoder, void* callback, void* userData)
{
    criDecoderCallVoid(decoder, 0xc8, callback, userData);
}

// MS2-FUNCTIONAL: configure the video decoder processor mask.
// @0x140044d20
void criVdec_SetProcessorMask(void* decoder, CriUint32 mask)
{
    criDecoderCallVoid(decoder, 0xd0, mask);
}

// MS2-FUNCTIONAL: call the decoder interface's initialize entry point.
// @0x140044390
void FUN_140044390(const void* decoderInterface)
{
    DAT_143ba9d18 = "\ncriVdec/PCx64 Ver.3.30 Build:Jan 20 2012 18:13:28\n";
    if (decoderInterface)
    {
        void* initialize = *(void* const*)decoderInterface;
        if (initialize)
        {
            typedef void (*Callback)(void);
            ((Callback)initialize)();
        }
    }
}

// MS2-FUNCTIONAL: call the decoder interface's finalize entry point.
// @0x1400443d0
void FUN_1400443d0(void* decoderInterface)
{
    if (!decoderInterface)
        return;
    void* finalize;
    memcpy(&finalize, (CriUint8*)decoderInterface + 8, sizeof(finalize));
    if (finalize)
    {
        typedef void (*Callback)(void);
        ((Callback)finalize)();
    }
}

// MS2-FUNCTIONAL: set the VDEC DLG parameters through its decoder interface.
// @0x140044d70
void criVdec_SetDlgPara(void* decoder, CriUint32 mode, void* first, void* second)
{
    criDecoderCallVoid(decoder, 0xd8, mode, first, second);
}

// MS2-FUNCTIONAL: invoke the decoder's auxiliary callback with its two caller arguments.
// @0x140044de0
void FUN_140044de0(void* decoder, void* first, void* second)
{
    criDecoderCallVoid(decoder, 0xe0, first, second);
}

// MS2-FUNCTIONAL: retrieve the decoder core interface through the interface table's final slot.
// @0x140044e40
void* FUN_140044e40(void* decoder)
{
    // unlike its neighbours this slot sits in the interface table itself and takes no object (0x140044e6e)
    if (!decoder)
        return NULL;
    void* target = *(void**)((CriUint8*)decoder + 0xe8);
    if (!target)
        return NULL;
    return ((void* (*)(void))target)();
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: store one output stream joint and its size flags in the demux table.
// @0x140044fb0
void criUsfDmx_SetOutputSj(void* demux, CriUint32 index, void* stream, CriUint32 flags, CriSint32 limit)
{
    void* outputs;
    memcpy(&outputs, (CriUint8*)demux + 0x18, sizeof(outputs));
    CriUint8* record = (CriUint8*)outputs + (size_t)index * 0x10;
    memcpy(record, &stream, sizeof(stream));
    memcpy(record + 8, &flags, sizeof(flags));
    memcpy(record + 0xc, &limit, sizeof(limit));
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
    CriUint8* bytes = (CriUint8*)ringBuffer;
    FUN_140046014(ringBuffer);
    const size_t cleared[] = { 0x20, 0x28, 0x2c, 0x40, 0x44, 0x48, 0x4c };
    CriUint32 zero = 0, capacity;
    for (size_t i = 0; i < sizeof(cleared) / sizeof(cleared[0]); ++i)
        memcpy(bytes + cleared[i], &zero, sizeof(zero));
    memcpy(&capacity, bytes + 0x38, sizeof(capacity));
    memcpy(bytes + 0x24, &capacity, sizeof(capacity));
    FUN_14004602c(ringBuffer);
}

// MS2-FUNCTIONAL: reserve a bounded input or output region from the CRI stream ring buffer.
// @0x140046094
void criSjRbf_GetChunk(void* ringBuffer, CriSint32 direction, CriUint32 requested, void* result)
{
    CriUint8* bytes = (CriUint8*)ringBuffer;
    FUN_140046014(ringBuffer);
    CriUint32 size, end, available, position;
    void* data;
    memcpy(&size, bytes + 0x38, sizeof(size));
    memcpy(&end, bytes + 0x3c, sizeof(end));
    memcpy(&data, bytes + 0x30, sizeof(data));
    if (direction == 0)
    {
        memcpy(&position, bytes + 0x28, sizeof(position));
        memcpy(&available, bytes + 0x24, sizeof(available));
        CriUint32 contiguous = size - position + end;
        if (available < contiguous)
            contiguous = available;
        if (requested > contiguous)
            requested = contiguous;
        void* chunk = (CriUint8*)data + position;
        position = (position + requested) % size;
        available -= requested;
        CriUint32 total;
        memcpy(&total, bytes + 0x40, sizeof(total));
        total += requested;
        memcpy(bytes + 0x28, &position, sizeof(position));
        memcpy(bytes + 0x24, &available, sizeof(available));
        memcpy(bytes + 0x40, &total, sizeof(total));
        memcpy(result, &chunk, sizeof(chunk));
        memcpy((CriUint8*)result + 8, &requested, sizeof(requested));
        CriUint32 zero = 0;
        memcpy((CriUint8*)result + 12, &zero, sizeof(zero));
    }
    else if (direction == 1)
    {
        memcpy(&position, bytes + 0x2c, sizeof(position));
        memcpy(&available, bytes + 0x20, sizeof(available));
        CriUint32 contiguous = size - position + end;
        if (available < contiguous)
            contiguous = available;
        if (requested > contiguous)
            requested = contiguous;
        void* chunk = (CriUint8*)data + position;
        position = (position + requested) % size;
        available -= requested;
        CriUint32 total;
        memcpy(&total, bytes + 0x48, sizeof(total));
        total += requested;
        memcpy(bytes + 0x2c, &position, sizeof(position));
        memcpy(bytes + 0x20, &available, sizeof(available));
        memcpy(bytes + 0x48, &total, sizeof(total));
        memcpy(result, &chunk, sizeof(chunk));
        memcpy((CriUint8*)result + 8, &requested, sizeof(requested));
        CriUint32 zero = 0;
        memcpy((CriUint8*)result + 12, &zero, sizeof(zero));
    }
    else
    {
        void* empty = NULL;
        CriUint32 zero = 0;
        memcpy(result, &empty, sizeof(empty));
        memcpy((CriUint8*)result + 8, &zero, sizeof(zero));
        memcpy((CriUint8*)result + 12, &zero, sizeof(zero));
    }
    FUN_14004602c(ringBuffer);
}

// MS2-FUNCTIONAL: pop a recycled 0x20-byte chunk from the unified stream-joint free list.
// @0x14004592c
void* FUN_14004592c(void* streamJoint)
{
    CriUint8* bytes = (CriUint8*)streamJoint;
    void* chunk;
    memcpy(&chunk, bytes + 0x48, sizeof(chunk));
    if (!chunk)
        return NULL;
    void* next;
    memcpy(&next, chunk, sizeof(next));
    memcpy(bytes + 0x48, &next, sizeof(next));
    memset(chunk, 0, 0x20);
    return chunk;
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
    CriUint8* bytes = (CriUint8*)streamJoint;
    void* lock;
    memcpy(&lock, bytes + 0x10, sizeof(lock));
    if (lock)
        FUN_140039f50((LPCRITICAL_SECTION)lock);
    CriSint32 count = 0;
    void* chunk;
    memcpy(&chunk, bytes + 0x48, sizeof(chunk));
    while (chunk)
    {
        ++count;
        memcpy(&chunk, chunk, sizeof(chunk));
    }
    if (lock)
        FUN_140039f8c((LPCRITICAL_SECTION)lock);
    return count;
}

// MS2-FUNCTIONAL: drain every active stream-joint queue and return its chunks to the free list.
// @0x140045b7c
void criSjUni_Reset(void* streamJoint)
{
    CriUint8* bytes = (CriUint8*)streamJoint;
    void* lock;
    memcpy(&lock, bytes + 0x10, sizeof(lock));
    if (lock)
        FUN_140039f50((LPCRITICAL_SECTION)lock);
    for (CriUint32 index = 0; index < 4; ++index)
    {
        size_t listOffset = 0x20 + (size_t)index * sizeof(void*);
        void* node;
        memcpy(&node, bytes + listOffset, sizeof(node));
        while (node)
        {
            void* next;
            memcpy(&next, node, sizeof(next));
            memset(node, 0, 0x20);
            void* freeHead;
            memcpy(&freeHead, bytes + 0x48, sizeof(freeHead));
            memcpy(node, &freeHead, sizeof(freeHead));
            memcpy(bytes + 0x48, &node, sizeof(node));
            node = next;
        }
        void* empty = NULL;
        memcpy(bytes + listOffset, &empty, sizeof(empty));
    }
    if (lock)
        FUN_140039f8c((LPCRITICAL_SECTION)lock);
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: return the current tick delta and timestamp for a CRI timer record.
// @0x140041a10
void FUN_140041a10(const void* state, CriSint64* elapsed, CriUint64* timestamp)
{
    CriUint64 now = FUN_1425e3510();
    *timestamp = now;
    CriUint8* bytes = (CriUint8*)state;
    CriUint64 base;
    if (bytes[0x10] != 0)
        base = FUN_1425e3560();
    else
        memcpy(&base, bytes + 8, sizeof(base));
    CriUint64 start;
    memcpy(&start, bytes, sizeof(start));
    *elapsed = (CriSint64)(base - start);
}

// MS2-FUNCTIONAL: toggle the timer record's paused state and accumulate elapsed ticks.
// @0x140041ad0
void FUN_140041ad0(void* state, CriBool paused)
{
    CriUint8* bytes = (CriUint8*)state;
    if (bytes[0x28] == paused)
        return;
    CriUint64 now = FUN_1425e3560();
    if (paused)
    {
        memcpy(bytes + 0x18, &now, sizeof(now));
        bytes[0x20] = 0;
        CriUint64 timestamp = FUN_1425e3510();
        memcpy(bytes + 0x38, &timestamp, sizeof(timestamp));
        CriUint64 base;
        if (bytes[0x20] == 0)
            memcpy(&base, bytes + 0x18, sizeof(base));
        else
            base = FUN_1425e3560();
        CriUint64 start, elapsed, total;
        memcpy(&start, bytes + 0x10, sizeof(start));
        elapsed = base - start;
        memcpy(bytes + 0x30, &elapsed, sizeof(elapsed));
        memcpy(&total, bytes + 0x40, sizeof(total));
        total += elapsed;
        memcpy(bytes + 0x40, &total, sizeof(total));
        bytes[0x28] = paused;
        return;
    }
    memcpy(bytes + 0x10, &now, sizeof(now));
    bytes[0x20] = 1;
    bytes[0x28] = 0;
}

// MS2-FUNCTIONAL: report the accumulated pause duration or the active timer delta and timestamp.
// @0x140041b50
void FUN_140041b50(void* state, CriSint64* elapsed, CriUint64* timestamp)
{
    CriUint8* bytes = (CriUint8*)state;
    if (bytes[0x28] != 0)
    {
        memcpy(elapsed, bytes + 0x40, sizeof(*elapsed));
        memcpy(timestamp, bytes + 0x38, sizeof(*timestamp));
        return;
    }
    CriUint64 now = FUN_1425e3510();
    memcpy(bytes + 0x38, &now, sizeof(now));
    CriUint64 base;
    if (bytes[0x20] == 0)
        memcpy(&base, bytes + 0x18, sizeof(base));
    else
        base = FUN_1425e3560();
    CriUint64 start, total;
    memcpy(&start, bytes + 0x10, sizeof(start));
    CriUint64 delta = base - start;
    memcpy(bytes + 0x30, &delta, sizeof(delta));
    memcpy(&total, bytes + 0x40, sizeof(total));
    *elapsed = (CriSint64)(total + delta);
    *timestamp = now;
}

// MS2-FUNCTIONAL: install the notification callback and its user data on a player manager.
// @0x140041df0
void FUN_140041df0(void* manager, void* callback, void* userData)
{
    memcpy((CriUint8*)manager + 0x28, &callback, sizeof(callback));
    memcpy((CriUint8*)manager + 0x30, &userData, sizeof(userData));
}

// MS2-FUNCTIONAL: route a decrypt callback to the selected active audio decoder.
// @0x140041e30
void FUN_140041e30(void* manager, void* callback, void* userData, CriSint32 stream)
{
    if (!manager)
        return;
    void* decoder;
    memcpy(&decoder, (CriUint8*)manager + (size_t)stream * sizeof(void*), sizeof(decoder));
    if (decoder)
    {
        void* decrypt;
        memcpy(&decrypt, (CriUint8*)decoder + 0x10, sizeof(decrypt));
        if (decrypt)
            FUN_140054040(decrypt, callback, userData);
    }
}

// MS2-FUNCTIONAL: store the two frame dimensions on a CRI video handle.
// @0x140041030
void FUN_140041030(void* handle, CriUint32 width, CriUint32 height)
{
    memcpy((CriUint8*)handle + 0x238, &width, sizeof(width));
    memcpy((CriUint8*)handle + 0x23c, &height, sizeof(height));
}

// MS2-FUNCTIONAL: publish the two caller-provided buffer pointers on the CRI video handle.
// @0x140041080
void FUN_140041080(void* handle, void* first, void* second)
{
    memcpy((CriUint8*)handle + 0x248, &first, sizeof(first));
    memcpy((CriUint8*)handle + 0x250, &second, sizeof(second));
}

// MS2-FUNCTIONAL: mark the CRI handle's error state when a handle is supplied.
// @0x140041150
void FUN_140041150(void* handle)
{
    if (handle)
    {
        CriUint32 state = 4;
        memcpy((CriUint8*)handle + 0x18, &state, sizeof(state));
    }
}

// MS2-FUNCTIONAL: invoke the Initialize entry in the decoder interface table.
// @0x140043a20
void FUN_140043a20(const void* decoder)
{
    if (decoder)
    {
        typedef void (*VoidFunction)(void);
        VoidFunction fn = *(VoidFunction*)decoder;
        if (fn)
            fn();
    }
}

// MS2-FUNCTIONAL: invoke the decoder interface's finalize entry when present.
// @0x140043a50
void FUN_140043a50(void* decoder)
{
    if (decoder)
    {
        typedef void (*VoidFunction)(void);
        VoidFunction fn = *(VoidFunction*)((CriUint8*)decoder + 8);
        if (fn)
            fn();
    }
}

// MS2-FUNCTIONAL: query the decoder work size and include the executable's 0x2e-byte wrapper.
// @0x140043a80
CriSint32 FUN_140043a80(void* decoder, CriSint32 a, CriSint32 b, CriSint32 c)
{
    if (!decoder)
        return 0;
    typedef CriSint32 (*WorkSizeFunction)(CriSint32, CriSint32, CriSint32);
    WorkSizeFunction fn = *(WorkSizeFunction*)((CriUint8*)decoder + 0x10);
    if (!fn)
        return 0;
    return fn(a, b, c) + 0x2e;
}

// MS2-FUNCTIONAL: invoke the alpha decoder interface's frame-info query when available.
// @0x140043c50
void* FUN_140043c50(void** decoder)
{
    if (!decoder || !decoder[1])
        return NULL;
    void** apiTable = (void**)decoder[1];
    if (!apiTable[0x28 / sizeof(void*)])
        return NULL;
    typedef void* (*FrameInfoFunction)(void*);
    return ((FrameInfoFunction)apiTable[0x28 / sizeof(void*)])(*decoder);
}

// MS2-FUNCTIONAL: copy an RFB frame only while the VMPV handle is not stopped and data is present.
// @0x14003e110
CriBool FUN_14003e110(void* handle, void* output, void** frame)
{
    CriUint32 stopped;
    memcpy(&stopped, (CriUint8*)handle + 0x1c, sizeof(stopped));
    if (stopped == 1 || !frame || !*frame)
        return 0;
    FUN_14003e850(handle, *frame, output);
    return 1;
}

// MS2-FUNCTIONAL: clear the two per-frame dimensions stored in a VMPV output record.
// @0x14003e710
void FUN_14003e710(void* unused, void* output)
{
    CriUint32 zero = 0;
    memcpy((CriUint8*)output + 8, &zero, sizeof(zero));
    memcpy((CriUint8*)output + 0xc, &zero, sizeof(zero));
}

// MS2-FUNCTIONAL: store the current frame rate on the VMPV handle.
// @0x14003e820
void FUN_14003e820(void* handle, CriUint32 frameRate)
{
    memcpy((CriUint8*)handle + 0x38, &frameRate, sizeof(frameRate));
}

// MS2-FUNCTIONAL: return the frame timestamp and selected concatenation offset in milliseconds.
// @0x14003e750
void FUN_14003e750(void* handle, CriSint32 frame, CriUint64* timestamp, CriUint64* offset)
{
    CriUint32 frameRate, selected = 0, key = 0;
    memcpy(&frameRate, (CriUint8*)handle + 0x38, sizeof(frameRate));
    *timestamp = 0;
    *offset = frameRate;
    if (frame != 0)
    {
        for (key = 0; key < 8; ++key)
        {
            CriSint32 candidate;
            memcpy(&candidate, (CriUint8*)handle + 0x1b4 + key * 8, sizeof(candidate));
            if (candidate == frame - 1)
            {
                selected = key;
                break;
            }
        }
        if (key == 8)
            selected = 7;
        CriUint32 milliseconds;
        memcpy(&milliseconds, (CriUint8*)handle + 0x1b8 + selected * 8, sizeof(milliseconds));
        *timestamp = (CriUint64)milliseconds * 1000;
    }
}

// MS2-FUNCTIONAL: normalize the movie player's two 64-entry audio-track maps and copy the active entries.
// @0x14003b720
void FUN_14003b720(CriMvSubAudioTrackState* state, CriSint32 count,
                   const CriSint32* trackIds, const CriSint32* trackValues)
{
    memset(state->TrackIds, 0, sizeof(state->TrackIds));
    memset(state->TrackValues, 0, sizeof(state->TrackValues));
    if (count > 64)
        count = 64;
    state->TrackCount = count;
    for (CriSint32 i = 0; i < count; ++i)
    {
        CriSint32 id = trackIds[i];
        CriSint32 value = trackValues[i];
        state->TrackIds[i] = id == -1 ? 0x5a5a5a5a : id;
        state->TrackValues[i] = value == 0x8000000 ? 0x5a5a5a5a : value;
    }
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: search the table's 32-bit record field in row order and return its first matching row.
// @0x14003b168
CriUint32 criUtfRtv_SearchRecNoByUint32(const CriUtfRtvView* table, CriUint32 field, CriUint32 value)
{
    const CriUtfRtvColumn* col = &table->Columns[field];
    if (!col->IsRecordField || col->Type != 4)
        return 0xffffffff;
    for (CriUint32 row = 0; row < table->RecordCount; ++row)
        if (criUtfRtv_GetDataUint32(table, row, field) == value)
            return row;
    return 0xffffffff;
}

// MS2-FUNCTIONAL: search the table's string record field in row order and return its first matching row.
// @0x14003b094
CriUint32 criUtfRtv_SearchRecNoByStr(const CriUtfRtvView* table, CriUint32 field, const CriChar8* value)
{
    const CriUtfRtvColumn* col = &table->Columns[field];
    if (!col->IsRecordField || col->Type != 10)
        return 0xffffffff;
    for (CriUint32 row = 0; row < table->RecordCount; ++row)
    {
        const CriChar8* candidate = criUtfRtv_GetDataStr(table, row, field);
        if (candidate && strcmp(candidate, value) == 0)
            return row;
    }
    return 0xffffffff;
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: these state initializers clear the decoder's four motion-vector components.
// @0x142ccb4f0
void MPVDEC_ResetMv(CriMpvDecoderState* state)
{
    memset(state->MotionVectors, 0, sizeof(state->MotionVectors));
}

// MS2-FUNCTIONAL: reset the three MPEG DC predictors to the executable's midpoint value.
// @0x142ccb500
void MPVDEC_ResetDc(CriMpvDecoderState* state)
{
    state->DcPredictors[1] = 0x400;
    state->DcPredictors[2] = 0x400;
    state->DcPredictors[0] = 0x400;
}

// MS2-FUNCTIONAL: adjust macroblock address and column by 1 minus the supplied run length.
// @0x142ccc580
void mpvumc_SubMbadr(CriMpvDecoderState* state, CriSint32 run)
{
    CriSint32 delta = 1 - run;
    state->MacroblockAddress += delta;
    state->MacroblockColumn += delta;
    while (state->MacroblockColumn < 0)
    {
        state->MacroblockColumn += state->MacroblockWidth;
        --state->MacroblockRow;
    }
}

// MS2-FUNCTIONAL: advance the macroblock column, wrapping to the next row at the row width.
// @0x142ccc5c0
void mpvumc_IncreMbadr(CriMpvDecoderState* state)
{
    if (++state->MacroblockColumn >= state->MacroblockWidth)
    {
        ++state->MacroblockRow;
        state->MacroblockColumn = 0;
    }
    ++state->MacroblockAddress;
}

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

// MS2-FUNCTIONAL: forward the opaque argument through the Vdec callback at table offset 0x98.
// @0x140044050
void FUN_140044050(CriUint64* pair, void* value)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0x98))
        (*(void (**)(CriUint64, void*))((CriUint8*)pair[1] + 0x98))(pair[0], value);
}

// MS2-FUNCTIONAL: call the Vdec callback at table offset 0x88 and add its fixed status bias.
// @0x1400440a0
CriUint32 FUN_1400440a0(CriUint64* pair, void* first, CriUint32 second, void* third)
{
    if (!pair || !*(void**)((CriUint8*)pair[1] + 0x88))
        return 0;
    return (*(CriUint32 (**)(CriUint64, void*, CriUint32, void*))((CriUint8*)pair[1] + 0x88))(
        pair[0], first, second, third);
}

// MS2-FUNCTIONAL: invoke the Vdec callback at table offset 0x48 when provided.
// @0x140044120
void FUN_140044120(CriUint64* pair)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0x48))
        (*(void (**)(CriUint64))((CriUint8*)pair[1] + 0x48))(pair[0]);
}

// MS2-FUNCTIONAL: pass the 32-bit option to the Vdec callback at table offset 0xa0.
// @0x140044160
void FUN_140044160(CriUint64* pair, CriUint32 option)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0xa0))
        (*(void (**)(CriUint64, CriUint32))((CriUint8*)pair[1] + 0xa0))(pair[0], option);
}

// MS2-FUNCTIONAL: pass both 32-bit options to the Vdec callback at table offset 0xa8.
// @0x1400441b0
void FUN_1400441b0(CriUint64* pair, CriUint32 first, CriUint32 second)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0xa8))
        (*(void (**)(CriUint64, CriUint32, CriUint32))((CriUint8*)pair[1] + 0xa8))(pair[0], first, second);
}

// MS2-FUNCTIONAL: pass the two opaque values to the Vdec callback at table offset 0xb0.
// @0x140044210
void FUN_140044210(CriUint64* pair, void* first, void* second)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0xb0))
        (*(void (**)(CriUint64, void*, void*))((CriUint8*)pair[1] + 0xb0))(pair[0], first, second);
}

// MS2-FUNCTIONAL: pass the 32-bit option to the Vdec callback at table offset 0xb8.
// @0x140044270
void FUN_140044270(CriUint64* pair, CriUint32 option)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0xb8))
        (*(void (**)(CriUint64, CriUint32))((CriUint8*)pair[1] + 0xb8))(pair[0], option);
}

// MS2-FUNCTIONAL: forward three arguments to the Vdec callback at table offset 0xc0.
// @0x1400442c0
void FUN_1400442c0(CriUint64* pair, CriUint32 option, void* first, void* second)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0xc0))
        (*(void (**)(CriUint64, CriUint32, void*, void*))((CriUint8*)pair[1] + 0xc0))(
            pair[0], option, first, second);
}

// MS2-FUNCTIONAL: pass the two opaque values to the Vdec callback at table offset 0xc8.
// @0x140044330
void FUN_140044330(CriUint64* pair, void* first, void* second)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0xc8))
        (*(void (**)(CriUint64, void*, void*))((CriUint8*)pair[1] + 0xc8))(pair[0], first, second);
}

// MS2-FUNCTIONAL: call the encoded callback and preserve its 0x3e status adjustment.
// @0x140044400
CriSint32 FUN_140044400(void* callbackPair, CriUint32 first, CriUint32 second, CriUint32 third)
{
    if (!callbackPair || !*(void**)((CriUint8*)callbackPair + 0x10))
        return 0;
    CriUint32 result = ((CriUint32 (*)(CriUint32, CriUint32, CriUint32))
        *(void**)((CriUint8*)callbackPair + 0x10))(first, second, third);
    return result + 0x3e;
}

// MS2-FUNCTIONAL: obtain the value from the Vdec callback at table offset 0x28, defaulting to zero.
// @0x1400445d0
CriUint64 FUN_1400445d0(CriUint64* pair)
{
    return pair && *(void**)((CriUint8*)pair[1] + 0x28)
        ? (*(CriUint64 (**)(CriUint64))((CriUint8*)pair[1] + 0x28))(pair[0]) : 0;
}

// MS2-FUNCTIONAL: invoke the Vdec callback at table offset 0x38 when provided.
// @0x140044680
void FUN_140044680(CriUint64* pair)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0x38))
        (*(void (**)(CriUint64))((CriUint8*)pair[1] + 0x38))(pair[0]);
}

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
    // The exe also stores a version string at DAT_143ba9d30 here; no symbol is bound for it, so the store is omitted.
    (**(void (***)(void*))object)(object);
}

// MS2-FUNCTIONAL: split a stream-joint chunk into a bounded prefix and its remaining suffix.
// @0x1400467c0
void criSj_SplitChunk(const void* source, CriUint32 maximum, void* prefix, void* suffix)
{
    void* data;
    CriUint32 size;
    memcpy(&data, source, sizeof(data));
    memcpy(&size, (const CriUint8*)source + 8, sizeof(size));
    CriUint32 prefixSize = size < maximum ? size : maximum;
    CriUint32 suffixSize = size - prefixSize;
    void* suffixData = suffixSize ? (CriUint8*)data + prefixSize : NULL;
    // The exe copies the whole 16-byte chunk into prefix (+0xc included) and never writes suffix+0xc.
    memcpy(prefix, source, 16);
    memcpy((CriUint8*)prefix + 8, &prefixSize, sizeof(prefixSize));
    memcpy(suffix, &suffixData, sizeof(suffixData));
    memcpy((CriUint8*)suffix + 8, &suffixSize, sizeof(suffixSize));
}

// MS2-FUNCTIONAL: place a bounded prefix on the input queue and return the suffix to output.
// @0x140046814
void criSj_PutInputChunk(void* streamJoint, const void* chunk, CriUint32 size)
{
    CriUint8 prefix[0x10], suffix[0x10];
    CriUint32 available;
    memcpy(&available, (const CriUint8*)chunk + 8, sizeof(available));
    if (available < size)
        size = available;
    criSj_SplitChunk(chunk, size, prefix, suffix);
    FUN_1400467b0(streamJoint, 1, prefix);
    FUN_1400467a8(streamJoint, 0, suffix);
}

// MS2-FUNCTIONAL: place a bounded prefix on the output queue and return the suffix to input.
// @0x140046894
void criSj_PutOutputChunk(void* streamJoint, const void* chunk, CriUint32 size)
{
    CriUint8 prefix[0x10], suffix[0x10];
    CriUint32 available;
    memcpy(&available, (const CriUint8*)chunk + 8, sizeof(available));
    if (available < size)
        size = available;
    criSj_SplitChunk(chunk, size, prefix, suffix);
    FUN_1400467b0(streamJoint, 0, prefix);
    FUN_1400467a8(streamJoint, 1, suffix);
}

// MS2-FUNCTIONAL: call the stream-joint object's second virtual operation.
// @0x1400467a0
void FUN_1400467a0(void* object, CriSint32 operation = 0, CriSint32 limit = 0, void* output = NULL)
{
    if (object)
    {
        void* target = *(void**)((CriUint8*)*(void**)object + 0x10);
        if (target)
        {
            typedef void (*Callback)(void*, CriSint32, CriSint32, void*);
            ((Callback)target)(object, operation, limit, output);
        }
    }
}

// MS2-FUNCTIONAL: call the stream-joint object's third virtual operation.
// @0x1400467a8
void FUN_1400467a8(void* object, CriSint32 operation = 0, void* chunk = NULL)
{
    if (object)
    {
        void* target = *(void**)((CriUint8*)*(void**)object + 0x18);
        if (target)
        {
            typedef void (*Callback)(void*, CriSint32, void*);
            ((Callback)target)(object, operation, chunk);
        }
    }
}

// MS2-FUNCTIONAL: call the stream-joint object's fourth virtual operation.
// @0x1400467b0
void FUN_1400467b0(void* object, CriSint32 operation = 0, void* chunk = NULL)
{
    if (object)
    {
        void* target = *(void**)((CriUint8*)*(void**)object + 0x20);
        if (target)
        {
            typedef void (*Callback)(void*, CriSint32, void*);
            ((Callback)target)(object, operation, chunk);
        }
    }
}

// MS2-FUNCTIONAL: call the stream-joint object's fifth virtual operation.
// @0x1400467b8
CriSint32 FUN_1400467b8(void* object, CriSint32 query = 0)
{
    if (!object)
        return 0;
    void* target = *(void**)((CriUint8*)*(void**)object + 0x28);
    if (!target)
        return 0;
    typedef CriSint32 (*Callback)(void*, CriSint32);
    return ((Callback)target)(object, query);
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

// MS2-FUNCTIONAL: execute the CRI Movie Player manager initialization hook.
// @0x140041ea0
void criMvPlyAmng_Initialize(void)
{
    FUN_1400532b0();
}

// MS2-FUNCTIONAL: execute the CRI Movie Player manager finalization hook.
// @0x140041ec0
void criMvPlyAmng_Finalize(void)
{
    FUN_1400532d0();
}

// MS2-FUNCTIONAL: initialize the timer snapshot with the current CRI clock and its live-state flag.
// @0x1400419d0
void FUN_1400419d0(void* snapshot)
{
    *(CriUint64*)snapshot = FUN_1425e3560();
    *((CriUint8*)snapshot + 0x10) = 1;
}

// MS2-FUNCTIONAL: initialize an elapsed-time accumulator with a stopped flag and current clock.
// @0x1400419f0
void FUN_1400419f0(void* timer)
{
    *(CriUint64*)((CriUint8*)timer + 8) = FUN_1425e3560();
    *((CriUint8*)timer + 0x10) = 0;
}

// MS2-FUNCTIONAL: initialize the alternate timer snapshot layout with a running flag.
// @0x140041bd0
void* FUN_140041bd0(void* snapshot)
{
    *(CriUint64*)snapshot = FUN_1425e3560();
    *((CriUint8*)snapshot + 0x10) = 1;
    return snapshot;
}

// MS2-FUNCTIONAL: reset the timer's accumulated duration and capture a fresh stopped-time origin.
// @0x140041aa0
void FUN_140041aa0(void* timer)
{
    *(CriUint64*)((CriUint8*)timer + 0x18) = FUN_1425e3560();
    *((CriUint8*)timer + 0x20) = 0;
    *(CriUint64*)((CriUint8*)timer + 0x40) = 0;
}

// MS2-FUNCTIONAL: forward the requested state to the attached player interface when present.
// @0x1400412e0
void FUN_1400412e0(void* player, CriSint32 state)
{
    void* target = *(void**)((CriUint8*)player + 0x10);
    if (target)
        (*(void (**)(void*, CriBool))((CriUint8*)*(void**)target + 0x30))(target, state == 1);
}

// MS2-FUNCTIONAL: forward the supplied output pointer to the attached player's slot-four callback.
// @0x1400412a0
void FUN_1400412a0(void* player)
{
    void* target = *(void**)((CriUint8*)player + 0x10);
    if (target)
        (*(void (**)(void*, void*))((CriUint8*)*(void**)target + 0x20))(target, (CriUint8*)player + 0x18);
}

// MS2-FUNCTIONAL: report whether the attached player callback returns the active state value.
// @0x140041270
CriBool FUN_140041270(void* player)
{
    void* target = *(void**)((CriUint8*)player + 0x10);
    return target && (*(CriSint32 (**)(void*))((CriUint8*)*(void**)target + 0x18))(target) != 1;
}

// MS2-FUNCTIONAL: forward the two supplied values to the attached player's slot-one callback.
// @0x140041220
CriBool FUN_140041220(void* player, void*, CriUint32 first, CriUint32 second)
{
    void* target = *(void**)((CriUint8*)player + 0x10);
    return target ? (*(CriBool (**)(void*, CriUint32, CriUint32))((CriUint8*)*(void**)target + 8))(target, first, second) : 0;
}

// MS2-FUNCTIONAL: return the player's shared work-memory size and default alignment.
// @0x1400411e0
void* FUN_1400411e0(CriUint32* size)
{
    *size = 0x10;
    return DAT_143b27c80;
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: publish CRI Base's runtime banner string.
// @0x1400411f8
void FUN_1400411f8(void)
{
    DAT_143ba9d08 = "\nCRI Base/PCx64 Ver.2.21.07 Build:Jan 13 2012 19:02:07\n";
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: forward to the attached object's virtual stop operation when present.
// @0x140041250
void FUN_140041250(void* object)
{
    void** target = *(void***)((CriUint8*)object + 0x10);
    if (target)
        ((void (*)(void*))*(void**)((CriUint8*)*target + 0x10))(*target);
}

// MS2-FUNCTIONAL: forward to the attached object's virtual operation at slot five when present.
// @0x1400412c0
void FUN_1400412c0(void* object)
{
    void** target = *(void***)((CriUint8*)object + 0x10);
    if (target)
        ((void (*)(void*))*(void**)((CriUint8*)*target + 0x28))(*target);
}

// MS2-FUNCTIONAL: forward to the attached object's virtual destroy operation when present.
// @0x140041340
void FUN_140041340(void* object)
{
    void** target = *(void***)((CriUint8*)object + 0x10);
    if (target)
        ((void (*)(void*))*(void**)((CriUint8*)*target + 0x40))(*target);
}

// MS2-FUNCTIONAL: invoke the global heap manager's work-size operation.
// @0x140041d20
CriUint64 FUN_140041d20(void)
{
    void* manager = DAT_143b15f60;
    ((void (*)(void*))*(void**)((CriUint8*)*(void**)manager + 0x60))(manager);
    return 0;
}

// MS2-FUNCTIONAL: release the supplied CRI heap through the global heap manager.
// @0x140041dd0
void FUN_140041dd0(void* heap)
{
    void* manager = DAT_143b15f60;
    ((void (*)(void*, void*))*(void**)((CriUint8*)*(void**)manager + 0x60))(manager, heap);
}

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

// MS2-FUNCTIONAL: initialize the CRI timer context and its default interval/counter fields.
// @0x140041c00
void* FUN_140041c00(void* context)
{
    struct TimerContext
    {
        const void* Vtable;
        CriUint32 Flags;
        CriUint32 Reserved0c;
        CriUint64 Start;
        CriUint64 Reserved18;
        CriUint8 Active;
        CriUint8 Reserved21[7];
        CriUint8 Mode;
        CriUint8 Reserved29[7];
        CriUint64 Current;
        CriUint64 Interval;
        CriUint64 Reserved40;
    };
    TimerContext* timer = (TimerContext*)context;
    timer->Flags = 1;
    timer->Vtable = &PTR_FUN_1431b9b10;
    timer->Start = FUN_1425e3560();
    timer->Active = 1;
    timer->Mode = 0;
    timer->Current = 0;
    timer->Interval = 1000000;
    timer->Reserved40 = 0;
    return context;
}

// MS2-FUNCTIONAL: destroy the global heap manager and optionally free its owning object.
// @0x140041c60
void* FUN_140041c60(void* manager, CriUint64 flags)
{
    *(const void**)manager = &PTR_FUN_1431b4f78;
    FUN_14257db50(manager);
    if (flags & 1)
    {
        void* globalManager = DAT_143b15f60;
        ((void (*)(void*, void*))*(void**)((CriUint8*)*(void**)globalManager + 0x60))(globalManager, manager);
    }
    return manager;
}

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
    ReaderRing* ring = (ReaderRing*)object;
    LPCRITICAL_SECTION section = ring->Section;
    if (section)
        FUN_140039f50(section);
    CriSint32 total = 0;
    void* entry = ring->Queues[lane];
    while (entry)
    {
        total += *(CriSint32*)((CriUint8*)entry + 0x18);
        entry = *(void**)entry;
    }
    if (section)
        FUN_140039f8c(section);
    return total;
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: dispatch the EasyFileReader free operation and release its heap-owned adapter.
// @0x140044560
void FUN_140044560(CriUint64* adapter)
{
    struct FileAdapterOps { CriUint8 Reserved00[0x20]; void* Free; };
    if (adapter && adapter[1] && ((FileAdapterOps*)adapter[1])->Free)
    {
        ((void (*)(CriUint64))((FileAdapterOps*)adapter[1])->Free)(adapter[0]);
        adapter[0] = 0;
        adapter[1] = 0;
        FUN_140027fb4((void*)adapter[2], adapter);
    }
}

// MS2-FUNCTIONAL: clear the current Sofdec input state and reset its attached audio decoder.
// @0x140043550
void FUN_140043550(CriSint32* state, void* input)
{
    struct InputState
    {
        CriSint32 HasState;
        CriUint8 Reserved04[0x0c];
        void* AudioDecoder;
        CriUint8 Reserved18[0x10];
        void* InputControl;
        CriUint8 Reserved30[0x60];
        CriSint32 ResetState;
    };
    if (!input || !state)
        return;
    InputState* decoder = (InputState*)state;
    decoder->ResetState = 0;
    if (decoder->HasState == 0)
        return;
    if (!decoder->InputControl)
        FUN_140037910(0, "E05063023M: Don't have input SJ.", 0);
    FUN_140053540(decoder->AudioDecoder);
}

// MS2-FUNCTIONAL: compute the audio player work area from its configured channel count.
// @0x140041ee0
CriSint32 FUN_140041ee0(const void* player)
{
    struct PlayerConfig { CriUint8 Reserved00[0x4c]; CriSint32 Channels; };
    CriSint32 flags[3] = { 1, 1, 0x5a };
    CriSint32 channels = ((const PlayerConfig*)player)->Channels;
    CriSint32 workSize = channels == 0 ? 0x40 : channels * 0x40;
    return 0x5a + FUN_140046420(0, (CriUint32)workSize, (const CriUint32*)flags);
}

// MS2-FUNCTIONAL: report whether an audio decoder has enough queued samples for the requested operation.
// @0x140043750
CriBool FUN_140043750(void* decoder, const void* operation)
{
    struct TrackState
    {
        CriSint32 Present;
        CriUint8 Reserved04[0x0c];
        void* AudioDecoder;
        CriUint8 Reserved18[4];
        CriUint32 Threshold;
        CriUint8 Reserved20[0x10];
        void* Queue;
    };
    struct Operation { CriUint8 Reserved00[0x10]; CriSint32 Active; CriUint8 Reserved14[0xe08]; CriSint32 Scale; };
    if (!decoder || !operation)
        return 1;
    TrackState* track = (TrackState*)decoder;
    if (track->Present)
    {
        CriSint32 status = (CriSint32)FUN_140053630(track->AudioDecoder);
        if (status == 0 || status == 1)
            return 0;
        const Operation* request = (const Operation*)operation;
        CriUint32 required = (track->Threshold / 0x3c) * 8 * (CriUint32)request->Scale;
        CriUint32 queued = (CriUint32)FUN_1400467b8(track->Queue, 1);
        if (queued < required && request->Active == 0)
            return 0;
    }
    return 1;
}

// MS2-FUNCTIONAL: release all audio decoder entries and the owning stream joint from a player manager.
// @0x1400420b0
void FUN_1400420b0(void* manager, void* heap)
{
    struct AudioManager
    {
        void* Decoders[2];
        CriSint32 Count;
        void* InputJoint;
    };
    AudioManager* audio = (AudioManager*)manager;
    for (CriSint32 index = 0; index < audio->Count; ++index)
    {
        if (audio->Decoders[index])
            FUN_140042600(manager, heap, index);
    }
    if (audio->InputJoint)
    {
        FUN_140046784(audio->InputJoint);
        audio->InputJoint = NULL;
    }
    FUN_140027fb4(heap, manager);
}

// MS2-FUNCTIONAL: create the CRI audio player manager and its channel input stream joint.
// @0x140041f70
void* FUN_140041f70(void* owner, void* heap, const void* config)
{
    CriUint8* manager = (CriUint8*)FUN_140027ed8(heap, 0x38,
                                                 "CriMvPly__CriMvPlyAmngObj", 4);
    if (!manager)
    {
        FUN_140037950(owner, "E07090701M: Can't allocate CriMvPly manager.", 0x38);
        return NULL;
    }
    memset(manager, 0, 0x38);
    CriSint32 initialState = 2;
    memcpy(manager + 0x20, &initialState, sizeof(initialState));
    CriSint32 configuredChannels;
    memcpy(&configuredChannels, (const CriUint8*)config + 0x4c, sizeof(configuredChannels));
    CriUint32 queueSlots = configuredChannels == 0 ? 0x40 : (CriUint32)(configuredChannels * 0x40);
    void* joint = FUN_1400464c8(heap, 0, queueSlots);
    memcpy(manager + 0x18, &joint, sizeof(joint));
    if (!joint)
    {
        FUN_1400420b0(manager, heap);
        FUN_140037910(0, "E05063016M: Can't create audio manager stream joint.", 0);
        return NULL;
    }
    return manager;
}

// MS2-FUNCTIONAL: allocate and wire one CRI audio decoder into the manager's channel table.
// @0x140042270
CriBool FUN_140042270(void* manager, void* owner, void* heap, const CriUint32* decoderConfig,
                      CriUint32 streamIndex, CriSint32 decoderIndex)
{
    CriUint32 enabled;
    memcpy(&enabled, (CriUint8*)owner + 0x64c + (size_t)streamIndex * 0x10, sizeof(enabled));
    if (!enabled)
        return 0;
    CriUint8* decoder = (CriUint8*)FUN_140027ed8(heap, 0x98,
                                                  "CriMvPly__CriMvPlyAdecObj", 4);
    memcpy((CriUint8*)manager + (size_t)decoderIndex * sizeof(void*), &decoder, sizeof(decoder));
    if (!decoder)
    {
        FUN_140042600(manager, heap, decoderIndex);
        FUN_140037950(owner, "E07090702M: Can't allocate CRI audio decoder.", 8);
        return 0;
    }
    memset(decoder, 0, 0x98);
    CriUint32 state = 1;
    CriUint32 signature = 0x40534641;
    memcpy(decoder, &state, sizeof(state));
    memcpy(decoder + 4, &signature, sizeof(signature));
    memcpy(decoder + 8, &streamIndex, sizeof(streamIndex));
    CriUint32 channelCount, channelFormat, workCount;
    memcpy(&channelCount, decoderConfig + 1, sizeof(channelCount));
    memcpy(&channelFormat, decoderConfig, sizeof(channelFormat));
    memcpy(&workCount, decoderConfig + 3, sizeof(workCount));
    memcpy(decoder + 0x18, &channelCount, sizeof(channelCount));
    memcpy(decoder + 0x1c, &channelFormat, sizeof(channelFormat));
    memcpy(decoder + 0x20, &workCount, sizeof(workCount));
    CriUint32 outputMode;
    memcpy(&outputMode, (CriUint8*)owner + 0xe18, sizeof(outputMode));
    void* audioDecoder = FUN_140053340(heap, channelCount, outputMode == 0 ? 0 : 1);
    memcpy(decoder + 0x10, &audioDecoder, sizeof(audioDecoder));
    if (!audioDecoder)
    {
        FUN_140042600(manager, heap, decoderIndex);
        FUN_140037910(0, "E05063014M: Can't create audio decoder.", 0);
        return 0;
    }
    FUN_1400534d0(audioDecoder);
    void* inputJoint;
    memcpy(&inputJoint, (CriUint8*)manager + 0x18, sizeof(inputJoint));
    memcpy(decoder + 0x28, &inputJoint, sizeof(inputJoint));
    CriUint32 decoderWidth;
    memcpy(&decoderWidth, (CriUint8*)owner + 0xe1c, sizeof(decoderWidth));
    CriUint32 streamBytes = workCount * decoderWidth +
                            (decoderWidth * 0xc80 / channelCount) * decoderWidth;
    CriUint32 chunkBytes = decoderWidth * 0x840;
    for (CriUint32 channel = 0; channel < channelCount; ++channel)
    {
        CriUint32 perChannelBytes = streamBytes + chunkBytes;
        memcpy(decoder + 0x70 + (size_t)channel * sizeof(CriUint32),
               &perChannelBytes, sizeof(perChannelBytes));
        void* output = NULL;
        output = ((void* (*)(void*, CriUint32, CriUint32, CriUint32, CriUint64))FUN_140046730)(
            heap, streamBytes, chunkBytes, 4,
            (CriUint64)(uintptr_t)"CriMvPly__AoutBuf");
        memcpy(decoder + 0x30 + (size_t)channel * 16, &output, sizeof(output));
        if (!output)
        {
            FUN_140042600(manager, heap, decoderIndex);
            FUN_140037910(0, "E05063018M: Can't create audio output stream joint.", 0);
            return 0;
        }
    }
    FUN_1400534f0(audioDecoder, inputJoint);
    for (CriUint32 channel = 0; channel < channelCount; ++channel)
    {
        void* output = NULL;
        memcpy(&output, decoder + 0x30 + (size_t)channel * 16, sizeof(output));
        FUN_140053510(audioDecoder, channel, output);
    }
    CriSint32 count;
    memcpy(&count, (CriUint8*)manager + 0x10, sizeof(count));
    ++count;
    memcpy((CriUint8*)manager + 0x10, &count, sizeof(count));
    return 1;
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: drain and reset a CRI movie output ring before restoring its terminal queue entry.
// @0x1400453c4
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
    OutputState* state = (OutputState*)object;
    state->Writing = 0;
    state->Reading = 0;
    // drain the filled lane (1) back to the free lane (0), returning each chunk
    while (FUN_1400467b8(state->InputQueue, 1) != 0)
    {
        CriUint8 chunk[0x10];
        FUN_1400467a0(state->InputQueue, 1, -1, chunk);
        FUN_1400467b0(state->InputQueue, 0, chunk);
    }
    memset(state->Entries, 0, ((size_t)state->Count + 1) * sizeof(QueueEntry));
    state->Active = 0;
    FUN_140046798(state->InputQueue);
    FUN_140046798(state->OutputQueue);
    state->Entries[state->Count].Queue = state->OutputQueue;
    state->Entries[state->Count].Reserved = 0;
    state->Entries[state->Count].State = -1;
    state->Writing = 0;
    state->Reading = 1;
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: detect the encoded CSC flag in a CRI movie packet header.
// @0x140040f80
CriBool FUN_140040f80(const void* packet, CriSint32 size)
{
    struct PacketHeader
    {
        CriUint32 Reserved00;
        CriChar8 Signature[8];
        CriUint8 Reserved0c[0x0b];
        CriChar8 CscFlag;
    };
    if (size < 0x18)
        return 0;
    const PacketHeader* header = (const PacketHeader*)packet;
    for (CriUint32 index = 0; index < 8; ++index)
    {
        if (header->Signature[index] != DAT_143a482e8[index])
            return 0;
    }
    return header->CscFlag == 'C';
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: compute ring-buffer memory requirements for the CRI movie stream joint.
// @0x140046604
CriSint32 FUN_140046604(CriUint32 first, CriUint32 second, CriUint32 third,
                        const CriUint32* settings)
{
    struct Setup { CriUint32 Flags, First, Second, Third; CriUint64 Reserved; };
    CriSint32 overhead = FUN_140027dd0(8);
    Setup setup = { settings[0], first, second, third, 0 };
    return criSjRbf_CalculateWorkSize((const CriSint32*)&setup) + overhead * 2;
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
    CriUint32 length = (CriUint32)span[1];
    uintptr_t source = (uintptr_t)span[0];
    if (length == 0 || source == 0)
        return;
    CriUint8* bytes = (CriUint8*)ring;
    void* lock;
    void* buffer;
    CriUint32 writeOffset, capacity;
    memcpy(&lock, bytes + 0x10, sizeof(lock));
    memcpy(&buffer, bytes + 0x30, sizeof(buffer));
    memcpy(&writeOffset, bytes + 0x38, sizeof(writeOffset));
    memcpy(&capacity, bytes + 0x3c, sizeof(capacity));
    CriUint32 sourceOffset = (CriUint32)source - (CriUint32)(uintptr_t)buffer;
    if (mode == 1)
    {
        if (sourceOffset < capacity)
        {
            CriUint32 first = capacity - sourceOffset;
            if (length < first)
                first = length;
            memcpy((CriUint8*)buffer + writeOffset + sourceOffset, (const void*)source, first);
        }
        CriUint32 end = sourceOffset + length;
        if (writeOffset < end)
        {
            CriUint32 wrapped = end - writeOffset;
            if (length < wrapped)
                wrapped = length;
            memcpy(buffer, (CriUint8*)buffer + end - wrapped, wrapped);
        }
        if (lock)
            FUN_140039f50((LPCRITICAL_SECTION)lock);
        CriUint32 value;
        memcpy(&value, bytes + 0x20, sizeof(value));
        value += length;
        memcpy(bytes + 0x20, &value, sizeof(value));
        memcpy(&value, bytes + 0x4c, sizeof(value));
        value += length;
        memcpy(bytes + 0x4c, &value, sizeof(value));
    }
    else
    {
        if (mode != 0)
        {
            span[1] = 0;
            span[0] = 0;
            return;
        }
        if (lock)
            FUN_140039f50((LPCRITICAL_SECTION)lock);
        CriUint32 value;
        memcpy(&value, bytes + 0x24, sizeof(value));
        value += length;
        memcpy(bytes + 0x24, &value, sizeof(value));
        memcpy(&value, bytes + 0x44, sizeof(value));
        value += length;
        memcpy(bytes + 0x44, &value, sizeof(value));
    }
    if (lock)
        FUN_140039f8c((LPCRITICAL_SECTION)lock);
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: create the named CRI video heap and attach its allocator to the returned adapter.
// @0x140041d40
void* FUN_140041d40(void* manager)
{
    struct HeapConfig { CriSint32 Flags; CriUint64 Fields[7]; };
    HeapConfig config = { 0, { 0x40, 0x20000, 0, ~(CriUint64)0, 0, 0, 0 } };
    void** managerVtable = *(void***)manager;
    void* heap = ((void* (*)(void*, const CriChar8*, const HeapConfig*))managerVtable[4])(
        manager, "_Cri_Video_Heap", &config);
    void** heapVtable = *(void***)heap;
    void* adapter = ((void* (*)(void*, size_t, size_t))heapVtable[10])(heap, 0x10, 0);
    void** fields = (void**)adapter;
    fields[0] = (void*)&PTR_LAB_143a48350;
    fields[1] = heap;
    FUN_14257e4a0(heap, adapter);
    return adapter;
}

// MS2-FUNCTIONAL: map the current CRI movie frame into its segment and update presentation time.
// @0x140040c00
void FUN_140040c00(void* player, void* context)
{
    struct PlayerTimeline
    {
        CriUint8 Reserved000[0x190];
        CriSint32 FrameOffset;
        CriUint8 Reserved194[8];
        CriSint32 TimestampBase;
        CriUint8 Reserved1a0[0x14];
        struct Entry { CriSint32 Begin, End; } Entries[8];
        CriSint32 FinalEnd;
        CriUint8 Reserved1f8[0x40];
        CriSint32 FrameAdjustment;
    };
    struct FrameContext
    {
        CriUint8 Reserved000[8];
        CriSint32 Frame;
        CriUint8 Reserved00c[0x0c];
        CriUint64 PresentationTime;
        CriUint8 Reserved020[8];
        CriSint32 SegmentDelta;
        CriUint8 Reserved02c[0x78];
        CriSint32 FrameAdjustment;
        CriSint32 SegmentIndex;
    };
    PlayerTimeline* timeline = (PlayerTimeline*)player;
    FrameContext* frame = (FrameContext*)context;
    CriSint32 adjusted = timeline->FrameOffset;
    if (timeline->FrameAdjustment > 0)
        adjusted += timeline->FrameAdjustment;
    frame->Frame = adjusted + frame->FrameAdjustment;
    FUN_140040cc0(player, (CriUint32)frame->Frame, &frame->SegmentIndex, &frame->SegmentDelta);
    frame->PresentationTime = (CriUint64)(CriUint32)(adjusted + timeline->TimestampBase) * 1000;
}

// MS2-FUNCTIONAL: locate a frame among eight media segments and return its index and end-relative offset.
// @0x140040cc0
void FUN_140040cc0(void* player, CriUint32 frame, CriSint32* segmentIndex, CriSint32* delta)
{
    struct PlayerTimeline
    {
        CriUint8 Reserved000[0x190];
        CriUint8 Reserved190[0x24];
        struct Entry { CriSint32 Begin, End; } Entries[8];
        CriSint32 FinalEnd;
    };
    PlayerTimeline* timeline = (PlayerTimeline*)player;
    CriSint32 index = 0;
    CriSint32 selected = 0;
    for (; index < 8; ++index)
    {
        const PlayerTimeline::Entry& entry = timeline->Entries[index];
        if (entry.End == 0)
        {
            selected = index == 0 ? 0 : timeline->Entries[index - 1].Begin + 1;
            break;
        }
        if (frame < (CriUint32)entry.End)
        {
            selected = entry.Begin;
            break;
        }
    }
    if (index == 8)
        selected = timeline->Entries[7].Begin + 1;
    CriSint32 end = index == 0 ? timeline->FinalEnd : timeline->Entries[index - 1].End;
    *segmentIndex = selected;
    *delta = (CriSint32)frame - end;
}

// MS2-FUNCTIONAL: execute one audio decoder operation unless its status is already an error.
// @0x1400436d0
void FUN_1400436d0(void* state)
{
    struct AdecState { CriSint32 Present; CriUint8 Reserved04[0x0c]; void* Decoder; };
    if (!state)
        return;
    AdecState* adec = (AdecState*)state;
    if (!adec->Present || !adec->Decoder)
        return;
    if (FUN_140053630(adec->Decoder) == 4)
    {
        FUN_1400379b0(0, "Status of Adec is ERROR.");
        return;
    }
    DAT_143ba9d10 = 1;
    FUN_140053650(adec->Decoder);
    DAT_143ba9d10 = 0;
}

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
    if (owner->Heap && owner->DecoderBuffer)
        FUN_140027fb4(owner->Heap, owner->DecoderBuffer);
    if (owner->InputJoint)
        FUN_140046784(owner->InputJoint);
    if (owner->OutputJoint)
        FUN_140046784(owner->OutputJoint);
    if (owner->Heap)
        FUN_140027fb4(owner->Heap, owner);
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: return a bounded channel's available audio bytes when its decoder is ready.
// @0x140043890
CriUint32 FUN_140043890(void* track, void* player, CriUint32 channel, CriUint32 maximum)
{
    struct AudioTrack
    {
        CriSint32 Present;
        CriUint8 Reserved04[0x0c];
        void* Decoder;
        CriUint32 ChannelCount;
        CriUint32 Threshold;
        CriUint8 Reserved20[0x10];
        void* Queue;
    };
    struct PlayerState { CriUint8 Reserved00[8]; CriSint32 State; };
    AudioTrack* audio = (AudioTrack*)track;
    PlayerState* movie = (PlayerState*)player;
    if (!audio || !audio->Decoder || !audio->Present)
        return 0;
    if (audio->ChannelCount < channel)
    {
        FUN_140037950(player, "E05063028M: Requested audio channel is invalid.", channel);
        return 0;
    }
    if (movie->State == 1)
        return 0;
    CriSint32 status = FUN_1400310b0(player);
    if (status != 4 && status != 5)
        return 0;
    CriUint32 available = FUN_140043420(track, player, channel);
    return available < maximum ? available : maximum;
}

// MS2-FUNCTIONAL: apply the selected channel's three decoder parameters to its audio decoder.
// @0x140043970
void FUN_140043970(void* track, void* player)
{
    struct AudioTrack
    {
        CriSint32 Present;
        CriUint8 Reserved04[4];
        CriSint32 Channel;
        CriUint8 Reserved0c[4];
        void* Decoder;
    };
    struct ChannelParameters { CriUint32 First, Second, Third, Reserved; };
    struct PlayerParameters { CriUint8 Reserved00[0xb2c]; ChannelParameters Channels[16]; };
    if (!track || !player)
        return;
    AudioTrack* audio = (AudioTrack*)track;
    if (!audio->Present)
        return;
    ChannelParameters* channel = &((PlayerParameters*)player)->Channels[audio->Channel];
    FUN_140053e60(audio->Decoder, channel->Second, channel->First, channel->Third);
}

// MS2-FUNCTIONAL: reset every audio track in a player and apply updated decoder parameters when enabled.
// @0x140042700
void FUN_140042700(void* trackSet, void* player)
{
    struct AudioTrackSet { void* Tracks[2]; CriSint32 Count; void* Configuration; };
    struct TrackControl { CriUint32 Reserved; CriUint32 Control; };
    struct PlayerState { CriUint8 Reserved00[0xe58]; CriSint32 ParameterUpdateEnabled; };
    AudioTrackSet* tracks = (AudioTrackSet*)trackSet;
    PlayerState* movie = (PlayerState*)player;
    if (tracks->Tracks[0])
    {
        CriUint32 control = ((TrackControl*)tracks->Tracks[0])->Control;
        FUN_1400345e0(player, tracks->Configuration, control, -1);
    }
    for (CriSint32 index = 0; index < tracks->Count; ++index)
    {
        FUN_140043550((CriSint32*)tracks->Tracks[index], player);
        if (movie->ParameterUpdateEnabled > 0)
            FUN_140043970(tracks->Tracks[index], player);
    }
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: dequeue a chunk large enough for the request or split its head in single-buffer mode.
// @0x140045c60
void FUN_140045c60(void* object, CriSint32 lane, CriUint32 requested, CriUint64* output)
{
    struct ChunkNode { ChunkNode* Next; CriUint64 Reserved08; void* Data; CriUint32 Size, Reserved1c; };
    struct RingQueue
    {
        CriUint8 Reserved00[0x10];
        LPCRITICAL_SECTION Lock;
        CriSint32 Mode;
        CriUint32 Reserved1c;
        ChunkNode* Heads[5];
        ChunkNode* FreeList;
    };
    RingQueue* queue = (RingQueue*)object;
    if (queue->Lock)
        FUN_140039f50(queue->Lock);
    ChunkNode* node = queue->Heads[lane];
    if (node && node->Size <= requested)
    {
        output[0] = (CriUint64)node->Data;
        output[1] = node->Size;
        queue->Heads[lane] = node->Next;
        memset(node, 0, sizeof(*node));
        node->Next = queue->FreeList;
        queue->FreeList = node;
    }
    else if (node && queue->Mode == 1)
    {
        CriUint64 chunk[2] = { (CriUint64)node->Data, node->Size };
        CriUint64 prefix[2] = {}, suffix[2] = {};
        criSj_SplitChunk(chunk, requested, prefix, suffix);
        output[0] = prefix[0];
        output[1] = prefix[1];
        node->Data = (void*)suffix[0];
        node->Size = (CriUint32)suffix[1];
    }
    else
    {
        output[0] = 0;
        output[1] = 0;
    }
    if (queue->Lock)
        FUN_140039f8c(queue->Lock);
}

// MS2-FUNCTIONAL: append a contiguous input chunk to the lane tail or consume a recycled node.
// @0x140045d34
void FUN_140045d34(void* object, CriSint32 lane, const CriUint64* input)
{
    struct ChunkNode { ChunkNode* Next; CriUint64 Reserved08; void* Data; CriUint32 Size, Reserved1c; };
    struct RingQueue
    {
        CriUint8 Reserved00[0x10];
        LPCRITICAL_SECTION Lock;
        CriSint32 Mode;
        CriUint32 Reserved1c;
        ChunkNode* Heads[5];
        ChunkNode* FreeList;
    };
    RingQueue* queue = (RingQueue*)object;
    void* data = (void*)input[0];
    CriUint32 size = (CriUint32)input[1];
    if (size != 0 && data)
    {
        if (queue->Lock)
            FUN_140039f50(queue->Lock);
        ChunkNode** tail = &queue->Heads[lane];
        ChunkNode* last = NULL;
        while (*tail)
        {
            last = *tail;
            tail = &(*tail)->Next;
        }
        if (queue->Mode == 1 && last && (CriUint8*)last->Data + last->Size == data)
            last->Size += size;
        else if (queue->FreeList)
        {
            ChunkNode* node = queue->FreeList;
            queue->FreeList = node->Next;
            memset(node, 0, sizeof(*node));
            node->Data = data;
            node->Size = size;
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
    struct ChunkNode { ChunkNode* Next; CriUint64 Reserved08; void* Data; CriUint32 Size, Reserved1c; };
    struct RingQueue
    {
        CriUint8 Reserved00[0x10];
        LPCRITICAL_SECTION Lock;
        CriSint32 Mode;
        CriUint32 Reserved1c;
        ChunkNode* Heads[5];
        ChunkNode* FreeList;
    };
    RingQueue* queue = (RingQueue*)object;
    void* data = (void*)input[0];
    CriUint32 size = (CriUint32)input[1];
    if (size != 0 && data)
    {
        if (queue->Lock)
            FUN_140039f50(queue->Lock);
        ChunkNode*& head = queue->Heads[lane];
        if (queue->Mode == 1 && head && (CriUint8*)data + size == head->Data)
        {
            head->Data = data;
            head->Size += size;
        }
        else if (queue->FreeList)
        {
            ChunkNode* node = queue->FreeList;
            queue->FreeList = node->Next;
            memset(node, 0, sizeof(*node));
            node->Data = data;
            node->Size = size;
            node->Next = head;
            head = node;
        }
        if (queue->Lock)
            FUN_140039f8c(queue->Lock);
    }
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: initialize shared MPV library work buffers once and maintain their reference count.
// @0x14003c080
void FUN_14003c080(void)
{
    if (DAT_143b27c68 == 0)
    {
        DAT_143b27c50 = 0;
        DAT_143b27c58 = 0;
        DAT_143b27c60 = 0;
        DAT_143b27c64 = 0;
        if (DAT_143b27c70 == 0)
        {
            FUN_1400410d0(0, "E10092150M: MPV libwork is not set.", 0);
            return;
        }
        DAT_143b27c50 = (CriUint64)DAT_143b27c6c << 2;
        DAT_143b27c58 = (DAT_143b27c70 + 3) & ~(CriUint64)3;
        DAT_143b27c60 = 3;
        FUN_14004f8a0();
        FUN_14004eb50();
        FUN_14004e3b0(DAT_143b27c50, DAT_143b27c58);
    }
    ++DAT_143b27c68;
}

// MS2-FUNCTIONAL: drain one pending movie ring chunk after its sample count reaches a full block.
// @0x14003ef00
void FUN_14003ef00(void* object)
{
    struct Reader
    {
        CriUint8 Reserved00[0x50];
        CriUint32 BlockSize;
        CriUint32 Reserved54;
        void* Queue;
        CriUint8 Reserved60[0x20];
        CriUint8 Reserved80[0x10];
        void* CurrentData;
    };
    Reader* reader = (Reader*)object;
    CriUint32 samples = (CriUint32)FUN_1400467b8(reader->Queue, 3) / reader->BlockSize;
    if (samples > 0)
    {
        CriUint64 chunk[2] = {};
        FUN_1400467a0(reader->Queue, 3, -1, chunk);
        // keep the chunk whose token (its first field) is the one being played
        if (!chunk[0] || reader->CurrentData == *(void**)chunk[0])
            FUN_1400467a8(reader->Queue, 3, chunk);
        else
            FUN_1400467b0(reader->Queue, 0, chunk);
    }
}

// MS2-FUNCTIONAL: obtain a CRI video descriptor and publish its packed playback fields.
// @0x14003e2a0
void* FUN_14003e2a0(void* source, void* destination)
{
    struct DescriptorInput
    {
        void* Value;
        CriUint32 Field08, Field0c, Field10, Field14;
        CriUint64 Field18;
        CriUint8 Reserved20[0x30];
        CriUint32 Field50;
        CriUint8 Reserved54[0x5c];   // the callee copies a whole 0xb0-byte decoded frame here (exe local is 0xb0)
    } input = {};
    struct DescriptorOutput
    {
        void* Value;
        CriUint32 Field08, Field0c, Field10, Field14, Field18, Reserved1c;
        CriUint64 Field20;
        CriUint8 Reserved28[0x20];
        CriUint32 Ready;
    };
    if (!FUN_14003da40(source, &input))
        return NULL;
    DescriptorOutput* output = (DescriptorOutput*)destination;
    output->Value = input.Value;
    output->Field08 = input.Field08;
    output->Field0c = input.Field0c;
    output->Field10 = input.Field10;
    output->Field14 = input.Field50;
    output->Field18 = input.Field14;
    output->Field20 = input.Field18;
    output->Ready = 1;
    return output->Value;
}

// MS2-FUNCTIONAL: obtain an alternate CRI video descriptor and publish its packed playback fields.
// @0x14003e5d0
void* FUN_14003e5d0(void* source, void* destination)
{
    struct DescriptorInput
    {
        void* Value;
        CriUint32 Field08, Field0c, Field10, Field14;
        CriUint64 Field18;
        CriUint8 Reserved20[0x30];
        CriUint32 Field50;
        CriUint8 Reserved54[0x5c];   // the callee copies a whole 0xb0-byte decoded frame here (exe local is 0xb0)
    } input = {};
    struct DescriptorOutput
    {
        void* Value;
        CriUint32 Field08, Field0c, Field10, Field14, Field18, Reserved1c;
        CriUint64 Field20;
        CriUint8 Reserved28[0x20];
        CriUint32 Ready;
    };
    if (!FUN_14003dd50(source, &input))
        return NULL;
    DescriptorOutput* output = (DescriptorOutput*)destination;
    output->Value = input.Value;
    output->Field08 = input.Field08;
    output->Field0c = input.Field0c;
    output->Field10 = input.Field10;
    output->Field14 = input.Field50;
    output->Field18 = input.Field14;
    output->Field20 = input.Field18;
    output->Ready = 1;
    return output->Value;
}

// MS2-FUNCTIONAL: release the matching decoded frame from the pending ring and report if none matched.
// @0x14003e180
void FUN_14003e180(void* object, const void* frame)
{
    struct Reader
    {
        CriUint8 Reserved00[0x50];
        CriUint32 BlockSize;
        CriUint32 Reserved54;
        void* Queue;
    };
    struct DecodedChunk
    {
        CriUint8 Reserved00[0x10];
        const void* Frame;
        CriUint8 Reserved18[0xa8];
        CriUint32 QueueLane;
    };
    Reader* reader = (Reader*)object;
    // count the in-use lane (2), the one GetFrame parks taken frames in
    CriUint32 queued = (CriUint32)FUN_1400467b8(reader->Queue, 2) / reader->BlockSize;
    CriBool released = 0;
    for (CriUint32 index = 0; index < queued; ++index)
    {
        CriUint64 chunk[2] = {};
        FUN_1400467a0(reader->Queue, 2, -1, chunk);
        // match the frame's token (its first field), not the address of the caller's frame info
        if (chunk[0] && ((DecodedChunk*)chunk[0])->Frame == *(const void* const*)frame)
        {
            FUN_1400467b0(reader->Queue, ((DecodedChunk*)chunk[0])->QueueLane, chunk);
            released = 1;
            break;
        }
        if (!released)
            FUN_1400467b0(reader->Queue, 2, chunk);
    }
    if (!released)
        FUN_140041110(0, "E11120202M: Failed criVdec Release.", 0);
}

// MS2-FUNCTIONAL: destroy one audio decoder track set and clear its player-manager table entry.
// @0x140042600
void FUN_140042600(void* manager, void* heap, CriSint32 index)
{
    struct TrackSet
    {
        CriUint8 Reserved00[0x10];
        void* Decoder;
        CriUint32 ChannelCount;
        CriUint8 Reserved1c[0x14];
        void* Outputs[8];
    };
    if (!manager || !heap)
        return;
    void** table = (void**)manager;
    TrackSet* track = (TrackSet*)table[index];
    if (!track)
        return;
    if (track->Decoder)
    {
        FUN_140053470(track->Decoder);
        track->Decoder = NULL;
    }
    for (CriUint32 channel = 0; channel < track->ChannelCount; ++channel)
    {
        if (track->Outputs[channel])
        {
            FUN_140046784(track->Outputs[channel]);
            track->Outputs[channel] = NULL;
        }
    }
    FUN_140027fb4(heap, track);
    table[index] = NULL;
}

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
    UsfState* state = (UsfState*)FUN_140027ed8(heap, 0x40, "CriUsfDmx");
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

// MS2-FUNCTIONAL: copy the active input descriptor into the stream joint and advance its input count.
// @0x140040a20
void FUN_140040a20(void* player, void** inputDescriptor)
{
    struct PlayerState
    {
        CriUint8 Reserved00[0x58];
        void* Joint;
        CriUint8 Reserved60[0x138];
        CriSint32 InputCount;
        CriUint8 Reserved19c[8];
        CriUint32 DescriptorValue;
    };
    struct InputDescriptor { CriUint8 Reserved00[0xb4]; CriUint32 Value; };
    PlayerState* state = (PlayerState*)player;
    ((InputDescriptor*)*inputDescriptor)->Value = state->DescriptorValue;
    FUN_1400467b0(state->Joint, 1, inputDescriptor);
    ++state->InputCount;
}

// MS2-FUNCTIONAL: verify each decoder entry in a CRI track set accepts the supplied operation.
// @0x140042cf0
CriBool FUN_140042cf0(void* trackSet, void* operation)
{
    if (!trackSet)
        return 1;
    struct TrackSet { void* Decoders[2]; CriSint32 Count; };
    TrackSet* set = (TrackSet*)trackSet;
    for (CriSint32 index = 0; index < set->Count; ++index)
    {
        if (!FUN_140043750(set->Decoders[index], operation))
            return 0;
    }
    return 1;
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: read the three queue counters for the selected CRI stream joint lane.
// @0x1400450c0
void FUN_1400450c0(void* stream, CriUint32 lane, CriUint32* first, CriUint32* second,
                   CriUint32* third)
{
    struct StreamQueues { CriUint8 Reserved00[0x18]; CriUint8* Entries; };
    StreamQueues* state = (StreamQueues*)stream;
    CriUint8* entry = state->Entries + (size_t)lane * 0x10;
    void* queue = *(void**)entry;
    if (!queue)
        return;
    *first = (CriUint32)FUN_1400467b8(queue, 1);
    *second = (CriUint32)FUN_1400467b8(queue, 0);
    *third = (CriUint32)FUN_1400467b8(queue, 2);
}

// MS2-FUNCTIONAL: advance the read or write cursor of a CRI ring-buffer stream joint after a consumed chunk.
// @0x14004624c
void FUN_14004624c(void* joint, CriSint32 lane, void* chunkPtr)
{
    struct Chunk { CriUint8* Data; CriSint32 Size; };
    struct Joint
    {
        CriUint8 Reserved00[0x10];
        LPCRITICAL_SECTION Lock;
        CriUint8 Reserved18[8];
        CriSint32 Counter20;
        CriSint32 Counter24;
        CriUint32 WriteCursor;
        CriUint32 ReadCursor;
        CriUint8* Base;
        CriUint32 Capacity;
        CriSint32 Reserved3c;
        CriSint32 Avail40;
        CriSint32 Reserved44;
        CriSint32 Avail48;
    };
    Joint* state = (Joint*)joint;
    Chunk* chunk = (Chunk*)chunkPtr;
    if (chunk->Size == 0 || !chunk->Data)
        return;
    if (lane == 0)
    {
        if (state->Lock)
            FUN_140039f50(state->Lock);
        CriUint32 capacity = state->Capacity;
        CriUint32 cursor = (capacity - (CriUint32)chunk->Size + state->WriteCursor) % capacity;
        if (cursor == (CriUint32)((chunk->Data - state->Base) % (CriSint64)capacity))
        {
            state->WriteCursor = cursor;
            state->Counter24 += chunk->Size;
            state->Avail40 -= chunk->Size;
        }
    }
    else
    {
        if (lane != 1)
        {
            chunk->Size = 0;
            chunk->Data = NULL;
            return;
        }
        if (state->Lock)
            FUN_140039f50(state->Lock);
        CriUint32 capacity = state->Capacity;
        CriUint32 cursor = (capacity - (CriUint32)chunk->Size + state->ReadCursor) % capacity;
        if (cursor == (CriUint32)((chunk->Data - state->Base) % (CriSint64)capacity))
        {
            state->ReadCursor = cursor;
            state->Counter20 += chunk->Size;
            state->Avail48 -= chunk->Size;
        }
    }
    if (state->Lock)
        FUN_140039f8c(state->Lock);
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: create the CRI alpha decoder handle object around a decoder-implementation interface.
// @0x140043af0
void* FUN_140043af0(void* implementation, void* heap, void* parameter)
{
    struct Implementation { CriUint8 Reserved00[0x18]; void* (*Create)(void*, void*); };
    Implementation* impl = (Implementation*)implementation;
    if (!impl || !impl->Create)
        return NULL;
    void** object = (void**)FUN_140027ed8(heap, 0x18, "CriAlphaDec: HnObj", 4, 0, 0);
    if (!object)
    {
        FUN_140038e24(0, "E2011030702M", -3);
        return NULL;
    }
    void* created = impl->Create(heap, parameter);
    if (!created)
    {
        FUN_140027fb4(heap, object);
        return NULL;
    }
    object[0] = created;
    object[1] = implementation;
    object[2] = heap;
    return object;
}

// MS2-FUNCTIONAL: create the CRI video decoder handle object around a decoder-implementation interface.
// @0x140044470
void* FUN_140044470(void* implementation, void* heap, void* parameter)
{
    struct Implementation { CriUint8 Reserved00[0x18]; void* (*Create)(void*, void*); };
    Implementation* impl = (Implementation*)implementation;
    if (!impl || !impl->Create)
        return NULL;
    void** object = (void**)FUN_140027ed8(heap, 0x18, "CriVdec: HnObj", 4, 0, 0);
    if (!object)
    {
        FUN_140038e24(0, "E2011030701M", -3);
        return NULL;
    }
    void* created = impl->Create(heap, parameter);
    if (!created)
    {
        FUN_140027fb4(heap, object);
        return NULL;
    }
    object[0] = created;
    object[1] = implementation;
    object[2] = heap;
    return object;
}

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
    const CriUint32* settings = (const CriUint32*)config;
    CriMvWorkAllocator allocator;
    FUN_14002e6b0(work, (CriUint32)workSize, &allocator);
    void** object = (void**)FUN_14002e6c0(&allocator, 0x50, 8);
    memset(object, 0, 0x50);
    object[0] = (void*)&PTR_FUN_143a485d8;
    object[1] = (void*)"CriSjUni";
    if (settings[0] == 1)
    {
        void* csWork = FUN_14002e6c0(&allocator, 0x48, 1);
        object[2] = criCs_Create(csWork, 0x48);
        if (!object[2])
        {
            FUN_140038ddc(0, "E09021213:Failed in criCs_Create().");
            return NULL;
        }
    }
    else
    {
        object[2] = NULL;
    }
    *(CriUint32*)(object + 3) = settings[1];
    object[4] = NULL;
    object[5] = NULL;
    object[6] = NULL;
    object[7] = NULL;
    object[8] = FUN_14002e6c0(&allocator, settings[2] << 5, 8);
    object[9] = NULL;
    for (CriUint32 index = 0; index < settings[2]; ++index)
    {
        void** record = (void**)((CriUint8*)object[8] + (CriUint64)index * 0x20);
        memset(record, 0, 0x20);
        record[0] = object[9];
        object[9] = record;
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

// MS2-FUNCTIONAL: drain the demuxed chunk queue of a video player, counting the chunks it consumes.
// @0x14003ed40
CriSint32 FUN_14003ed40(void* player)
{
    struct Chunk { const CriUint8* Data; CriSint32 Size; CriSint32 Reserved; };
    void* queue = ((CriVideoQueueFields*)player)->InputQueue;
    CriSint32 count = 0;
    while (FUN_1400467b8(queue, 2) != 0)
    {
        Chunk second = {};
        Chunk first;
        FUN_1400467a0(queue, 2, 0xffffffff, &first);
        if (FUN_14003eeb0(&first) != 0)
        {
            FUN_1400467a8(queue, 2, &first);
            return count;
        }
        if (FUN_14003d6c0(&first) != 0)
        {
            if (FUN_1400467b8(queue, 2) == 0)
            {
                FUN_1400467a8(queue, 2, &first);
                return count;
            }
            FUN_1400467a0(queue, 2, 0xffffffff, &second);
            CriUsfStandardHeader header = {};
            criUsfCmn_ParseUsfHeaderStd(first.Data, (CriUint32)first.Size, &header);
            CriUint32 payload;
            memcpy(&payload, header.Data + 4, sizeof(payload));
            if ((CriUint32)(first.Size + second.Size) < payload + 8U)
                FUN_1400410d0(0, "E08121602M : Video chunk might not be demuxed properly.\n", 0);
        }
        FUN_1400467b0(queue, 0, &first);
        if (second.Data)
            FUN_1400467b0(queue, 0, &second);
        ++count;
    }
    return count;
}

// MS2-FUNCTIONAL: flush the pending reference-picture input of a VMPV player into its stream joint.
// @0x140040a90
void FUN_140040a90(void* player)
{
    CriVideoQueueFields* state = (CriVideoQueueFields*)player;
    if (state->Staged == NULL)
        return;
    state->FlagsHigh = 0;
    state->Flags = 0;
    state->WindowEnd = state->Staged;
    state->Window = state->WindowEnd;
    state->WindowNext = state->Window;
    state->Cursor = state->WindowEnd;
    state->Staged = NULL;
    void* descriptor[2];
    memcpy(descriptor, &state->Pending, sizeof(descriptor));
    if (descriptor[0] == NULL)
    {
        FUN_140041110(0, "E06100910M : Failed in crivmpv_FlushReferencePictureInPool()", 0);
        state->Status = 4;
        return;
    }
    FUN_140040a20(player, descriptor);
    state->Pending = NULL;
    state->WindowEnd = NULL;
    void* pending[2];
    FUN_1400467a0(state->Queue, 3, 0xffffffff, pending);
    if (pending[0])
        FUN_1400467b0(state->Queue, 0, pending);
}

// MS2-FUNCTIONAL: report the per-lane picture queue depths of a VMPV player in whole pictures.
// @0x140040e40
void FUN_140040e40(void* player, CriUint32* total, CriUint32* first, CriSint32* second, CriUint32* third,
                   CriUint32* fourth)
{
    CriVideoQueueFields* state = (CriVideoQueueFields*)player;
    *first = 0;
    *second = 0;
    *third = 0;
    *fourth = 0;
    if (!state || !state->Queue)
        return;
    *total = state->PictureCount;
    *first = (CriUint32)FUN_1400467b8(state->Queue, 1) / state->UnitSize;
    *second = (CriSint32)((CriUint32)FUN_1400467b8(state->Queue, 3) / state->UnitSize);
    if (state->Pending != NULL)
        *second += 1;
    *third = (CriUint32)FUN_1400467b8(state->Queue, 2) / state->UnitSize;
    *fourth = (CriUint32)FUN_1400467b8(state->Queue, 0) / state->UnitSize;
}

// MS2-FUNCTIONAL: return the smallest per-channel count of whole audio frames buffered in a sound decoder.
// @0x140043420
CriUint32 FUN_140043420(void* decoder, void* player, CriUint32 channels)
{
    struct Decoder
    {
        CriSint32 Enabled;
        CriUint8 Reserved04[0xc];
        void* Handle;
        CriUint32 ChannelLimit;
        CriUint8 Reserved1c[0x14];
        void* Queues[1];
    };
    struct Player { CriUint8 Reserved00[8]; CriSint32 Mode; CriUint8 Reserved0c[0xe10]; CriUint32 FrameSize; };
    Decoder* base = (Decoder*)decoder;
    Player* ply = (Player*)player;
    if (!base || !base->Handle || base->Enabled == 0)
        return 0;
    if (base->ChannelLimit < channels)
        FUN_140037950(player, "E05063028M : Requested audio channel number is too many", channels);
    if (ply->Mode == 1)
        return 0;
    CriSint32 status = FUN_1400310b0(player);
    if (status != 5 && status != 4)
        return 0;
    CriUint32 frameSize = ply->FrameSize;
    CriUint32 minimum = (CriUint32)FUN_1400467b8(base->Queues[0], 1) / frameSize;
    for (CriUint32 channel = 1; channel < channels; ++channel)
    {
        CriUint32 count = (CriUint32)FUN_1400467b8((&base->Queues[0])[channel * 2], 1) / frameSize;
        if (count < minimum)
            minimum = count;
    }
    return minimum;
}

// MS2-FUNCTIONAL: run a video player's decode step once the demuxer has queued data.
// @0x14003ec30
CriSint32 FUN_14003ec30(void* player)
{
    CriVideoQueueFields* state = (CriVideoQueueFields*)player;
    if (!state || state->Busy == 1)
        return 0;
    if (criVmpv_GetStatus(player) != 2)
        return 0;
    FUN_14003ef00(player);
    if (FUN_1400467b8(state->Queue, 0) == 0)
        return 0;
    CriSint32 result = 0;
    state->Running = 1;
    if (criVdecCmn_GetNumPictureData(player) != 0)
    {
        FUN_14003ed40(player);
        result = FUN_14003efc0(player);
    }
    else if (state->Mode == 1 && FUN_1400467b8(state->InputQueue, 1) == 0 && state->Decoded < state->Threshold)
    {
        FUN_140040a90(player);
    }
    state->Running = 0;
    return result;
}

// MS2-FUNCTIONAL: ask the owner to stop when the playback clock has run ahead of the nominal frame rate.
// @0x1400414f0
void FUN_1400414f0(void* handle)
{
    struct Owner { CriUint8 Reserved00[8]; CriMvEasyPlayer* Player; CriUint8 Reserved10[0x2d0]; CriUint32 FrameRate;
                   CriUint32 Reserved2e4; CriUint64 FramesDone; CriUint64 FramesUnit; };
    struct Handle { CriUint8 Reserved00[0x40]; Owner* State; };
    Owner* state = ((Handle*)handle)->State;
    if (!state)
        return;
    CriMvEasyPlayer* owner = state->Player;
    CriUint64 count;
    CriUint64 unit;
    owner->GetTime(count, unit);
    float counts = (float)count;
    float units = (float)unit;
    float framesDone = (float)state->FramesDone;
    float framesUnit = (float)state->FramesUnit;
    if (1000.0f / ((float)state->FrameRate / 1000.0f) < (counts / units) * 1000.0f - (framesDone / framesUnit) * 1000.0f)
    {
        struct EasyFields { CriUint8 Reserved00[8]; void* Inner; };
        FUN_1400314a0(((EasyFields*)owner)->Inner);
    }
}

// MS2-FUNCTIONAL: reset a VMPV player's counters and return every picture record to its free queue.
// @0x14003d720
void FUN_14003d720(void* player)
{
    struct Player
    {
        CriUint8 Reserved00[0x18];
        CriSint32 Status;
        CriSint32 Busy;
        CriSint32 Mode;
        CriSint32 Running;
        CriUint8 Reserved28[0x14];
        CriUint32 RecordCount;
        CriUint8 Reserved40[8];
        CriUint8* Records;
        CriUint32 UnitSize;
        CriUint8 Reserved54[4];
        void* Queue;
        void* Pending;
        CriSint32 PendingSize;
        CriUint8 Reserved6c[4];
        void* Cursor;
        CriUint8 Reserved78[0x18];
        void* WindowEnd;
        CriUint8 Reserved98[0x18];
        void* Staged;
        CriUint8 Reservedb8[0x18];
        void* Reserved0d0;
        CriUint8 Reservedd8[0xa8];
        CriUint32 Counter180;
        CriUint32 Counter184;
        CriUint32 PictureCount;
        CriUint8 Reserved18c[4];
        CriUint32 Counter190;
        CriUint32 Counter194;
        CriUint32 Counter198;
        CriUint32 Counter19c;
        CriUint32 Counter1a0;
        CriUint32 Counter1a4;
        CriUint32 Counter1a8;
        CriUint32 Counter1ac;
        CriUint8 Reserved1b0[0x90];
        CriUint32 Counter240;
    };
    static_assert(offsetof(Player, Records) == 0x48 && offsetof(Player, Queue) == 0x58 && offsetof(Player, Cursor) == 0x70 &&
                  offsetof(Player, Staged) == 0xb0 && offsetof(Player, PictureCount) == 0x188 &&
                  offsetof(Player, Counter1ac) == 0x1ac && offsetof(Player, Counter240) == 0x240, "layout");
    struct Record { void* Data; CriUint32 Size; };
    Player* state = (Player*)player;
    state->Counter190 = 0;
    state->Counter194 = 0;
    state->Counter198 = 0;
    state->Counter19c = 0;
    state->Counter1a0 = 0;
    state->Counter1a4 = 0;
    state->Status = 1;
    state->Mode = 0;
    state->Busy = 0;
    state->Running = 0;
    state->PictureCount = 0;
    state->Counter240 = 0;
    FUN_140046798(state->Queue);
    state->Pending = NULL;
    state->PendingSize = 0;
    for (CriUint32 index = 0; index < state->RecordCount; ++index)
    {
        Record record;
        record.Data = state->Records + (CriUint64)index * 200;
        record.Size = state->UnitSize;
        memset(state->Records + 0x10 + (CriUint64)index * 200, 0, 0xb0);
        FUN_1400467b0(state->Queue, 0, &record);
    }
    state->WindowEnd = NULL;
    state->Staged = NULL;
    state->Reserved0d0 = NULL;
    state->Cursor = NULL;
    state->Counter1a8 = 0;
    state->Counter1ac = 0;
}

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

// MS2-FUNCTIONAL: convert YUV (and optional alpha) planes into the caller's 32-bit ARGB buffer.
// @0x14003bb60
void FUN_14003bb60(void* player, CriUint8* dstbuf, CriUint32 dstpitch, CriUint32 dstbufsize, const void* srcbufs,
                   const void* src_vinf, const void* src_ainf)
{
    struct PlaneRef { CriUint8* Data; CriUint32 Reserved08; CriUint32 Pitch; };
    struct YuvBuffers { PlaneRef Planes[3]; };
    struct AlphaInfo { CriUint8* Data; CriUint32 Reserved08; CriUint32 Width; CriUint32 Height; CriUint32 Reserved14;
                       CriUint32 Reserved18; CriUint32 Pitch; };
    struct VideoInfo { CriUint8 Reserved00[0xc]; CriUint32 Width; CriUint32 Height; };
    struct PlaneDesc { CriUint8* Data; CriUint32 Width; CriUint32 Height; CriUint32 Pitch; CriUint32 Reserved; };
    struct SourceDesc { CriUint32 Count; CriUint32 Reserved; PlaneDesc Planes[4]; };
    struct DestDesc { CriUint32 Count; CriUint32 Reserved; CriUint8* Data; CriUint32 Width; CriUint32 Height; CriUint32 Pitch; };
    struct PlayerSize { CriUint8 Reserved00[0x614]; CriUint32 Width; CriUint32 Height; };
    (void)dstbufsize;
    if (DAT_143b27c40 != 1)
        FUN_140037950(NULL, "E10110401M : Please call initialization function for 32bit ARGB frame output.", 0);
    const YuvBuffers* yuv = (const YuvBuffers*)srcbufs;
    const AlphaInfo* alpha = (const AlphaInfo*)src_ainf;
    const VideoInfo* video = (const VideoInfo*)src_vinf;
    if (!yuv || !alpha || !dstbuf)
    {
        FUN_140037910(0, "E10060100M : NULL pointer is passed into criMvPly_CopyFrameARGB8888Buffer().", 0);
        return;
    }
    if (alpha->Data != NULL && (video->Width != alpha->Width || video->Height != alpha->Height))
    {
        FUN_140037950(NULL, "E11012101M : The resolutions of alpha stream and video stream should be same in the frame format. Use YUV buffers format.", 0);
        return;
    }
    const PlayerSize* size = (const PlayerSize*)player;
    CriUint32 halfWidth = (size->Width + 1U) / 2;
    CriUint32 halfHeight = (size->Height + 1U) / 2;
    SourceDesc source = {};
    source.Count = 3;
    source.Planes[0].Data = yuv->Planes[0].Data;
    source.Planes[0].Width = size->Width;
    source.Planes[0].Height = size->Height;
    source.Planes[0].Pitch = yuv->Planes[0].Pitch;
    source.Planes[1].Data = yuv->Planes[1].Data;
    source.Planes[1].Width = halfWidth;
    source.Planes[1].Height = halfHeight;
    source.Planes[1].Pitch = yuv->Planes[1].Pitch;
    source.Planes[2].Data = yuv->Planes[2].Data;
    source.Planes[2].Width = halfWidth;
    source.Planes[2].Height = halfHeight;
    source.Planes[2].Pitch = yuv->Planes[2].Pitch;
    source.Planes[3].Data = alpha->Data;
    source.Planes[3].Width = alpha->Width;
    source.Planes[3].Height = alpha->Height;
    source.Planes[3].Pitch = alpha->Pitch;
    DestDesc dest = {};
    dest.Count = 1;
    dest.Data = dstbuf;
    dest.Width = video->Width;
    dest.Height = video->Height;
    dest.Pitch = dstpitch;
    CriUint64 options[6] = {};
    if (DAT_143b27c3c == 1)
        FUN_140049300(&source, &dest, options);
    else
        FUN_14004c0c0(&source, &dest, options);
    if (source.Planes[3].Data != NULL)
    {
        source.Planes[0].Data = source.Planes[3].Data;
        source.Planes[0].Width = source.Planes[3].Width;
        source.Planes[0].Height = source.Planes[3].Height;
        options[0] = 0;
        FUN_14004cbb0(&source, &dest, options);
    }
}

CriBool FUN_14003b8b0(void*, CriUint8*, CriUint32, CriUint32, void*);

// MS2-FUNCTIONAL: fetch the next decoded frame (and alpha frame) and convert it into a 32-bit ARGB buffer.
// @0x14003b8b0
CriBool FUN_14003b8b0(void* player, CriUint8* imagebuf, CriUint32 pitch, CriUint32 bufsize, void* frameinfo)
{
    struct FrameInfo { CriUint8 Reserved00[0xc]; CriUint32 Width; CriUint32 Height; };
    struct Player
    {
        CriUint8 Reserved00[0x5f0];
        CriUint32 FrameId;
        CriUint8 Reserved5f4[0x814];
        void* VideoDecoder;
        CriUint8 Reservede10[0x30];
        void* AlphaDecoder;
    };
    static_assert(offsetof(Player, VideoDecoder) == 0xe08 && offsetof(Player, AlphaDecoder) == 0xe40, "layout");
    Player* ply = (Player*)player;
    FrameInfo* output = (FrameInfo*)frameinfo;
    FUN_140035090(output);
    if (!FUN_140035560(player))
        return 0;
    if (bufsize < output->Width * 4 * output->Height)
    {
        FUN_140037950(player, "E09012805M : ARGB buffer is too small.", 0);
        return 0;
    }
    CriUint8 alphaInfo[0x38];
    CriUint8 alphaCopy[0x38];
    CriMvFrameInfo videoFrame;
    CriMvFrameInfo converted;
    CriUint8 alphaFrame[0x50];
    CriUint8 yuvInfo[0x40];
    FUN_1400351c0(alphaInfo);
    memset(alphaFrame, 0, sizeof(alphaFrame));
    void* videoToken = FUN_1400449c0(ply->VideoDecoder, &videoFrame);
    if (!videoToken)
    {
        FUN_140037910(0, "E10060101M : Cannot get the pointer to video frame buffer.", 0);
        return 0;
    }
    if (ply->AlphaDecoder != NULL && FUN_140043fe0(ply->AlphaDecoder, alphaFrame) == NULL)
    {
        FUN_140037910(0, "E08082502M : Cannot get the pointer to alpha frame buffer.", 0);
        return 0;
    }
    FUN_140035260(player, &converted, &videoFrame, (CriUint64)(uintptr_t)videoFrame.imageptr, videoFrame.width);
    FUN_140035480(player, alphaInfo, alphaFrame);
    FUN_1400358d0(yuvInfo, &videoFrame);
    FUN_1400359e0(yuvInfo, alphaFrame);
    FUN_14003bb60(player, imagebuf, pitch, bufsize, yuvInfo, &converted, alphaInfo);
    memcpy(&ply->FrameId, (const CriUint8*)&videoFrame + 0xa8, sizeof(ply->FrameId));
    if (ply->AlphaDecoder != NULL)
        FUN_140044050((CriUint64*)ply->AlphaDecoder, alphaFrame);
    FUN_140044a30(ply->VideoDecoder, &videoFrame);
    FUN_140035260(player, output, &videoFrame, (CriUint64)(uintptr_t)imagebuf, pitch);
    return 1;
}

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

// MS2-FUNCTIONAL: peek the next decoded picture of a VMPV player and describe its tiled YUV420 planes.
// @0x14003da40
void* FUN_14003da40(void* player, void* output)
{
    CriVideoFrameSource* source = (CriVideoFrameSource*)player;
    if (FUN_140040de0(player) == 0)
        return NULL;
    // Joint queue items are 16-byte {record, size} chunks; an 8-byte local overflows into the saved registers.
    struct { CriFrameRecord* Record; CriUint64 Size; } item;
    FUN_1400467a0(source->Queue, 1, 0xffffffff, &item);
    CriFrameRecord* record = item.Record;
    if (!record)
        return NULL;
    CriDecodedFrame* frame = (CriDecodedFrame*)output;
    memcpy(frame, &record->Frame, sizeof(record->Frame));
    FUN_140040c00(player, frame);
    CriDescribeTiledFrame(frame);
    FUN_1400467a8(source->Queue, 1, &item);
    return frame->Base;
}

// MS2-FUNCTIONAL: take the next decoded picture of a VMPV player, describe its planes and mark it consumed.
// @0x14003dd50
void* FUN_14003dd50(void* player, void* output)
{
    CriVideoFrameSource* source = (CriVideoFrameSource*)player;
    if (FUN_140040de0(player) == 0)
        return NULL;
    if (DAT_143b27c78 == 1 && FUN_1400467b8(source->Queue, 2) != 0)
        return NULL;
    struct { CriFrameRecord* Record; CriUint64 Size; } item;
    FUN_1400467a0(source->Queue, 1, 0xffffffff, &item);
    CriFrameRecord* record = item.Record;
    if (!record)
        return NULL;
    CriFrameRecord* taken = record;
    CriDecodedFrame* frame = (CriDecodedFrame*)output;
    memcpy(frame, &record->Frame, sizeof(record->Frame));
    FUN_140040c00(player, frame);
    CriDescribeTiledFrame(frame);
    source->Position += 1;
    FUN_1400467b0(source->Queue, 2, &item);
    if (source->Window == (void*)taken->Key)
        taken->Mode = source->ChannelCount < 3 ? 0 : 3;
    else
        taken->Mode = 0;
    return frame->Base;
}

// MS2-FUNCTIONAL: copy one tiled luma plane row by row into a caller buffer with its own pitch.
// @0x14003e370
CriBool FUN_14003e370(void* player, void* destination, void* source)
{
    struct Player { CriUint8 Reserved00[0x1c]; CriSint32 Busy; CriUint8 Reserved20[0xd8]; CriSint32 Width; };
    struct Destination { CriUint8* Data; CriUint32 RowBytes; CriUint32 Rows; CriUint32 Pitch; };
    struct Source { const CriUint8* Data; };
    static_assert(offsetof(Player, Width) == 0xf8, "layout");
    Player* ply = (Player*)player;
    Destination* dst = (Destination*)destination;
    Source* src = (Source*)source;
    if (ply->Busy == 1 || !src || !src->Data)
        return 0;
    CriSint32 aligned = ((ply->Width + 0xf) / 0x10) * 0x10 + 0x7f;
    CriSint16 srcPitch = (CriSint16)(aligned / 0x80) * 0x80;
    const CriUint8* srcRow = src->Data;
    CriUint32 copyBytes = (CriUint32)(CriSint32)srcPitch;
    if (dst->RowBytes < copyBytes)
        copyBytes = dst->RowBytes;
    CriUint8* dstRow = dst->Data;
    for (CriUint32 row = 0; row < dst->Rows; ++row)
    {
        memcpy(dstRow, srcRow, copyBytes);
        srcRow += srcPitch;
        dstRow += dst->Pitch;
    }
    return 1;
}

// MS2-FUNCTIONAL: pull one demuxed chunk from a video player's input queue and advance its decode state machine.
// @0x14003cff0
CriSint32 FUN_14003cff0(void* player)
{
    struct Chunk { const CriUint8* Data; CriSint32 Size; CriSint32 Reserved; };
    struct Player
    {
        CriUint8 Reserved00[0x180];
        void* Queue;
        CriUint32 Chunks;
        CriUint32 Chunks2;
        CriUint8 Reserved190[0x18];
        CriSint32 Phase;
        CriSint32 PhaseFlag;
        CriSint32 Metas;
        CriUint8 Reserved1b4[0x4c];
        CriSint32 (*HeaderCallback)(void*, void*);
        void* HeaderArg;
        void (*EndCallback)(void*);
        void* EndArg;
    };
    static_assert(offsetof(Player, Phase) == 0x1a8 && offsetof(Player, Metas) == 0x1b0 &&
                  offsetof(Player, HeaderCallback) == 0x200 && offsetof(Player, EndArg) == 0x218, "layout");
    Player* state = (Player*)player;
    CriSint32 result = 0;
    if (FUN_1400467b8(state->Queue, 1) == 0)
        return result;
    Chunk first;
    Chunk second = {};
    FUN_1400467a0(state->Queue, 1, 0xffffffff, &first);
    CriUsfStandardHeader header = {};
    criUsfCmn_ParseUsfHeaderStd(first.Data, (CriUint32)first.Size, &header);
    CriUint8 kind = header.Data[15];
    if (kind == 0)
    {
        state->Phase = 3;
        if (FUN_14003d6c0(&first) == 0)
        {
            FUN_1400467b0(state->Queue, 2, &first);
        }
        else
        {
            if (FUN_1400467b8(state->Queue, 1) == 0)
            {
                FUN_1400467a8(state->Queue, 1, &first);
                return result;
            }
            FUN_1400467a0(state->Queue, 1, 0xffffffff, &second);
            CriUsfStandardHeader secondHeader = {};
            criUsfCmn_ParseUsfHeaderStd(first.Data, (CriUint32)first.Size, &secondHeader);
            CriUint32 payload;
            memcpy(&payload, secondHeader.Data + 4, sizeof(payload));
            if ((CriUint32)(first.Size + second.Size) < payload + 8U)
            {
                FUN_1400410d0(0, "E07111401M : Video chunk might not be demuxed properly..\n", 0);
            }
            else
            {
                FUN_1400467b0(state->Queue, 2, &first);
                FUN_1400467b0(state->Queue, 2, &second);
            }
        }
        state->Chunks += 1;
        state->Chunks2 += 1;
        result = 1;
    }
    else if (kind == 1)
    {
        state->Phase = 1;
        if (state->HeaderCallback != NULL)
        {
            if (state->HeaderCallback(state->HeaderArg, &first) != 1)
            {
                FUN_1400467a8(state->Queue, 1, &first);
                return result;
            }
        }
    }
    else if (kind == 2)
    {
        if (state->Phase == 1)
        {
            state->PhaseFlag = 0;
            if (state->EndCallback != NULL)
                state->EndCallback(state->EndArg);
        }
        if (state->Phase == 3)
        {
            FUN_14003d550(player);
            state->Metas += 1;
        }
    }
    else if (kind == 3)
    {
        state->Phase = 2;
        if (FUN_14003d6c0(&first) != 0)
        {
            if (FUN_1400467b8(state->Queue, 1) == 0)
            {
                FUN_1400467a8(state->Queue, 1, &first);
                return result;
            }
            FUN_1400467a0(state->Queue, 1, 0xffffffff, &second);
            CriUsfStandardHeader secondHeader = {};
            criUsfCmn_ParseUsfHeaderStd(first.Data, (CriUint32)first.Size, &secondHeader);
            CriUint32 payload;
            memcpy(&payload, secondHeader.Data + 4, sizeof(payload));
            if ((CriUint32)(first.Size + second.Size) < payload + 8U)
                FUN_1400410d0(0, "E08121601M : Video meta chunk might not be demuxed properly.\n", 0);
        }
    }
    if (kind != 0 && kind < 4)
    {
        CriSint32 lane = state->Chunks == 0 ? 0 : 2;
        FUN_1400467b0(state->Queue, lane, &first);
        if (second.Data)
            FUN_1400467b0(state->Queue, lane, &second);
    }
    return result;
}

// MS2-FUNCTIONAL: copy the three tiled YUV420 planes of a decoded picture into caller planes with their own pitches.
// @0x14003e850
void FUN_14003e850(void* player, void* source, void* destination)
{
    struct Player { CriUint8 Reserved00[0xf8]; CriSint32 Width; CriSint32 Height; };
    struct Plane { CriUint8* Data; CriUint32 RowBytes; CriUint32 Rows; CriUint32 Pitch; CriUint32 Reserved; };
    struct Destination { Plane Planes[3]; };
    static_assert(offsetof(Player, Height) == 0xfc && sizeof(Plane) == 0x18, "layout");
    Player* ply = (Player*)player;
    Destination* dst = (Destination*)destination;
    CriSint32 alignedWidth = ((ply->Width + 0xf) / 0x10) * 0x10;
    CriSint32 alignedHeight = ((ply->Height + 0x1f) / 0x20) * 0x20;
    CriSint16 lumaPitch = (CriSint16)((alignedWidth + 0x7f) / 0x80) * 0x80;
    CriSint16 chromaPitch = (CriSint16)((alignedWidth / 2 + 0x7f) / 0x80) * 0x80;
    const CriUint8* lumaStart = (const CriUint8*)source;
    const CriUint8* chromaStart = lumaStart + (CriSint64)(((alignedWidth + 0x7f) / 0x80) * 0x80 * alignedHeight);
    const CriUint8* chroma2Start = chromaStart +
                                   (CriSint64)(((alignedWidth / 2 + 0x7f) / 0x80) * 0x80 * (alignedHeight / 2));
    CriUint32 chromaBytes = (dst->Planes[0].RowBytes + 1U) / 2;
    CriUint32 chromaRows = (dst->Planes[0].Rows + 1U) / 2;
    CriUint32 lumaCopy = (CriUint32)(CriSint32)lumaPitch;
    if (dst->Planes[0].RowBytes < lumaCopy)
        lumaCopy = dst->Planes[0].RowBytes;
    CriUint8* out = dst->Planes[0].Data;
    for (CriUint32 row = 0; row < dst->Planes[0].Rows; ++row)
    {
        memcpy(out, lumaStart, lumaCopy);
        lumaStart += lumaPitch;
        out += dst->Planes[0].Pitch;
    }
    CriUint32 chromaCopy = (CriUint32)(CriSint32)chromaPitch;
    if (chromaBytes < chromaCopy)
        chromaCopy = chromaBytes;
    out = dst->Planes[1].Data;
    for (CriUint32 row = 0; row < chromaRows; ++row)
    {
        memcpy(out, chromaStart, chromaCopy);
        chromaStart += chromaPitch;
        out += dst->Planes[1].Pitch;
    }
    out = dst->Planes[2].Data;
    for (CriUint32 row = 0; row < chromaRows; ++row)
    {
        memcpy(out, chroma2Start, chromaCopy);
        chroma2Start += chromaPitch;
        out += dst->Planes[2].Pitch;
    }
}

void* FUN_1400530c0(const void*, CriUint32, CriUint32);
CriBool FUN_140026dd0(void*, CriUint8*, CriUint32, CriUint32, void*, void*);
void FUN_140021c90(void*, CriSint32, void*);

// MS2-FUNCTIONAL: look for a start-code signature across the tail of one chunk and the head of the next.
// @0x1400405d0
CriBool FUN_1400405d0(void* firstChunk, void* secondChunk, CriUint32 offset)
{
    struct Chunk { CriUint8* Data; CriUint32 Size; };
    Chunk* first = (Chunk*)firstChunk;
    Chunk* second = (Chunk*)secondChunk;
    Chunk head;
    Chunk tail;
    if (first->Size < offset)
    {
        head.Data = NULL;
        head.Size = 0;
        if (second->Data == NULL)
        {
            tail.Data = NULL;
            tail.Size = 0;
        }
        else
        {
            tail.Data = second->Data + (offset - first->Size);
            tail.Size = second->Size - (offset - first->Size);
        }
    }
    else
    {
        if (first->Data == NULL)
        {
            head.Data = NULL;
            head.Size = 0;
        }
        else
        {
            head.Data = first->Data + offset;
            head.Size = first->Size - offset;
        }
        if (second->Data == NULL)
        {
            tail.Data = NULL;
            tail.Size = 0;
        }
        else
        {
            tail.Data = second->Data;
            tail.Size = second->Size;
        }
    }
    if (head.Data != NULL && head.Size >= 4 && FUN_1400530c0(head.Data, head.Size, 0x80) != 0)
        return 1;
    if (tail.Data == NULL || tail.Size == 0)
        return 0;
    CriUint8 joined[8];
    CriUint32 headBytes = head.Size < 4 ? head.Size : 3;
    CriUint32 tailBytes = tail.Size < 4 ? tail.Size : 3;
    if (head.Data != NULL && (CriSint32)headBytes > 0)
        memcpy(joined, head.Data + (head.Size - headBytes), (size_t)(CriSint32)headBytes);
    if (tail.Data != NULL && (CriSint32)tailBytes > 0)
        memcpy(joined + (CriSint32)headBytes, tail.Data, (size_t)(CriSint32)tailBytes);
    if ((CriSint32)(headBytes + tailBytes) >= 4 && FUN_1400530c0(joined, headBytes + tailBytes, 0x80) != 0)
        return 1;
    if (tail.Data == NULL || tail.Size < 4 || FUN_1400530c0(tail.Data, tail.Size, 0x80) == 0)
        return 0;
    return 1;
}

void FUN_1400436d0(void*);

// MS2-FUNCTIONAL: route one stream chunk to the decoder owning the given id and report whether all decoders are fed.
// @0x140042ba0
CriUint32 FUN_140042ba0(void* trackSet, void* chunk, CriSint32 id, CriSint32* counts)
{
    struct Decoder { CriUint8 Reserved00[8]; CriSint32 Id; };
    struct TrackSet { Decoder* Decoders[2]; CriSint32 Count; CriUint8 Reserved14[4]; void* Queue; CriUint32 Limit; };
    TrackSet* set = (TrackSet*)trackSet;
    CriSint32 index = 0;
    for (;; ++index)
    {
        if (set->Count <= index)
        {
            FUN_1400467b0(set->Queue, 0, chunk);
            return 2;
        }
        if (id == set->Decoders[index]->Id)
            break;
    }
    CriUint32 result = 1;
    FUN_1400467a8(set->Queue, 1, chunk);
    FUN_1400436d0(set->Decoders[index]);
    counts[index] += 1;
    for (index = 0; index < set->Count; ++index)
    {
        if ((CriUint32)counts[index] < set->Limit)
            result = 2;
        if (set->Limit + 1U <= (CriUint32)counts[index])
            return 1;
    }
    return result;
}

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

// MS2-FUNCTIONAL: drain buffered audio frames of every channel queue into per-channel 16-bit output buffers.
// @0x140042f40
CriUint32 FUN_140042f40(void* decoder, void* player, CriUint32 channels, void* outputs, CriUint32 mode, CriUint32* info)
{
    return CriDrainAudioChannels(decoder, player, channels, outputs, mode, info, 2);
}

// MS2-FUNCTIONAL: drain buffered audio frames of every channel queue into per-channel 32-bit output buffers.
// @0x1400431a0
CriUint32 FUN_1400431a0(void* decoder, void* player, CriUint32 channels, void* outputs, CriUint32 mode, CriUint32* info)
{
    return CriDrainAudioChannels(decoder, player, channels, outputs, mode, info, 4);
}

void FUN_1400531e0(void*, const void*, void*, void*);

// MS2-FUNCTIONAL: pull the next movie frame into the three (or four) texture planes handed in by the renderer.
// @0x1400415f0
CriBool FUN_1400415f0(void* handle, void* planeSet)
{
    struct Buffer { CriUint32 Format; CriUint32 Flags; CriUint64 Pitch; CriUint64 Size; CriUint8* Data; };
    struct YuvEntry { CriUint8* Data; CriUint32 Size; CriUint32 Pitch; };
    struct YuvSet { YuvEntry Entries[4]; };
    struct State
    {
        CriUint8 Reserved00[8];
        CriMvEasyPlayer* Player;
        CriUint8 Reserved10[0x2b0];
        CriMvFrameInfo Frame;
        CriUint8 Reserved370[0x20];
        CriUint8 AlphaKeep;
        CriUint8 Reserved391[0x18];
        CriUint8 Delivered;
        CriUint8 Cleared;
        CriUint8 PausePending;
    };
    struct Handle { CriUint8 Reserved00[0x40]; State* State; };
    static_assert(offsetof(State, Frame) == 0x2c0 && offsetof(State, AlphaKeep) == 0x390 &&
                  offsetof(State, Delivered) == 0x3a9 && offsetof(State, PausePending) == 0x3ab, "layout");
    State* state = ((Handle*)handle)->State;
    if (!state)
        return 0;
    if (state->Cleared)
    {
        FUN_140041390(handle, planeSet);
        state->Cleared = 0;
        return 1;
    }
    CriMvEasyPlayer* owner = state->Player;
    if (owner->IsNextFrameOnTime() == 0)
        return 0;
    CriUint32 count = FUN_14257c0c0(planeSet);
    if (count < 3)
    {
        Buffer buffer = {};
        FUN_14257c050(planeSet, 0, &buffer);
        FUN_140026dd0(owner, buffer.Data, (CriUint32)buffer.Pitch, (CriUint32)buffer.Size, &state->Frame, &CriMv::ErrorContainer);
        FUN_1400414f0(handle);
    }
    else
    {
        Buffer luma = {};
        Buffer chromaU = {};
        Buffer chromaV = {};
        Buffer alpha = {};
        YuvSet yuv = {};
        FUN_14257c050(planeSet, 0, &luma);
        yuv.Entries[0].Data = luma.Data;
        yuv.Entries[0].Size = (CriUint32)luma.Size;
        yuv.Entries[0].Pitch = (CriUint32)luma.Pitch;
        FUN_14257c050(planeSet, 1, &chromaU);
        yuv.Entries[1].Data = chromaU.Data;
        yuv.Entries[1].Size = (CriUint32)chromaU.Size;
        yuv.Entries[1].Pitch = (CriUint32)chromaU.Pitch;
        FUN_14257c050(planeSet, 2, &chromaV);
        yuv.Entries[2].Data = chromaV.Data;
        yuv.Entries[2].Size = (CriUint32)chromaV.Size;
        yuv.Entries[2].Pitch = (CriUint32)chromaV.Pitch;
        if (FUN_14257c0c0(planeSet) > 3)
        {
            FUN_14257c050(planeSet, 3, &alpha);
            if (state->AlphaKeep == 0)
            {
                memset(alpha.Data, 0xff, (size_t)alpha.Flags * (size_t)alpha.Pitch);
            }
            else
            {
                yuv.Entries[3].Data = alpha.Data;
                yuv.Entries[3].Size = (CriUint32)alpha.Size;
                yuv.Entries[3].Pitch = (CriUint32)alpha.Pitch;
            }
        }
        FUN_1400531e0(owner, &yuv, &state->Frame, &CriMv::ErrorContainer);
        FUN_1400414f0(handle);
    }
    state->Delivered = 1;
    if (state->PausePending)
    {
        FUN_140021c90(owner, 1, &CriMv::ErrorContainer);
        state->PausePending = 0;
    }
    return 1;
}

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

// MS2-FUNCTIONAL: route queued USF chunks to the matching track decoders until a track set needs more data.
// @0x1400428e0
void FUN_1400428e0(void* trackSet, void* player)
{
    struct Chunk { CriUint8* Data; CriUint32 Size; CriUint32 Reserved; };
    struct Decoder { CriUint8 Reserved00[0x90]; CriSint32 Active; };
    struct TrackSet
    {
        Decoder* Decoders[2];
        CriSint32 Count;
        CriUint8 Reserved14[4];
        void* Queue;
        CriUint8 Reserved20[8];
        CriSint32 (*Callback)(void*, void*, CriUint8);
        void* CallbackArg;
    };
    struct Player { CriUint8 Reserved00[0xb08]; CriUint32 Rate; CriUint8 Reservedb0c[0x34c]; CriSint32 Elapsed;
                    CriUint8 Reservede5c[0x10]; CriSint32 Started; };
    static_assert(offsetof(Player, Elapsed) == 0xe58 && offsetof(Player, Started) == 0xe6c &&
                  offsetof(TrackSet, Callback) == 0x28, "layout");
    TrackSet* set = (TrackSet*)trackSet;
    Player* ply = (Player*)player;
    void* queue = set->Queue;
    CriSint32 counts[2] = {};
    for (;;)
    {
        Chunk chunk;
        do
        {
            if (FUN_1400467b8(queue, 1) == 0)
            {
                if (FUN_1400467b8(queue, 1) != 0)
                    return;
                for (CriSint32 index = 0; index < set->Count; ++index)
                {
                    if (set->Decoders[index]->Active == 1)
                        FUN_1400436d0(set->Decoders[index]);
                }
                return;
            }
            FUN_1400467a0(queue, 1, 0xffffffff, &chunk);
        } while (chunk.Size < 0x20);
        CriUsfStandardHeader header;
        criUsfCmn_ParseUsfHeaderStd(chunk.Data, chunk.Size, &header);
        CriSint32 contentSize;
        criUsfCmn_GetContents(chunk.Data, chunk.Size, &contentSize);
        CriUint8 kind = header.Data[15];
        CriUint8 track = header.Data[12];
        if (kind == 1)
        {
            CriSint32 accepted = 1;
            if (set->Callback != NULL)
                accepted = set->Callback(set->CallbackArg, &chunk, track);
            if (accepted != 1)
            {
                FUN_1400467a8(queue, 1, &chunk);
                return;
            }
            FUN_1400467b0(queue, 0, &chunk);
            continue;
        }
        if (kind != 0)
        {
            FUN_1400467b0(queue, 0, &chunk);
            continue;
        }
        if (0 < ply->Elapsed && ply->Started != 1)
        {
            CriUint32 timeNumerator;
            CriUint32 timeDenominator;
            memcpy(&timeNumerator, header.Data + 0x14, sizeof(timeNumerator));
            memcpy(&timeDenominator, header.Data + 0x18, sizeof(timeDenominator));
            if ((float)timeNumerator / (float)timeDenominator <
                ((float)ply->Elapsed * 1000.0) / (float)ply->Rate)
            {
                FUN_1400467b0(queue, 0, &chunk);
                continue;
            }
            ply->Started = 1;
        }
        if (FUN_140042ba0(trackSet, &chunk, track, counts) == 1)
            return;
    }
}

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

// MS2-FUNCTIONAL: predict one block from a reference plane at an integer plus half-pel motion offset.
// @0x142ccc5f0
void FUN_142ccc5f0(CriUint8* reference, CriUint8* destination, CriSint32 stride, CriSint32 stride2, CriSint32 width,
                   CriSint32 height, CriSint32 x, CriSint32 y, CriSint32 mvx, CriSint32 mvy, CriSint32 flags)
{
    CriSint64 index = (CriSint64)flags * 8 + (CriSint64)(mvx & 1) * 2 + ((width >> 2) & 4) + (mvy & 1);
    CriUint8* source = reference + (CriSint64)(((mvy >> 1) + y) * stride) + x + (mvx >> 1);
    CriUint8* target = destination + (CriSint64)(y * stride) + x;
    DAT_143fe8248[index](source, target, stride, stride2, height);
}

// MS2-FUNCTIONAL: dispatch the inverse-transform add for each coded block of the current macroblock.
// @0x142ccc6c0
void FUN_142ccc6c0(void* decoder, CriSint32 codedBlocks, CriSint32 mode)
{
    CriUint32 coded = (CriUint32)(codedBlocks >> 0x18) & 0xff;
    if ((coded & 0x3f) == 0)
        return;
    CriMpvBlockEntry entries[8];
    CriMpvBlockEntry* out = entries;
    CriSint32 y = CriMpvField<CriSint32>(decoder, MPV_ROW) << 4;
    CriSint32 x = CriMpvField<CriSint32>(decoder, MPV_COLUMN) << 4;
    void** slots = (void**)((CriUint8*)decoder + MPV_BLOCK_SLOTS);
    if (coded & 0x3c)
    {
        CriSint32 stride = CriMpvField<CriSint16>(decoder, MPV_LUMA_STRIDE);
        CriUint8* base = CriMpvField<CriUint8*>(decoder, MPV_LUMA_BASE) + (CriSint64)(stride * y) + x;
        if (coded & 0x20)
        {
            out->Function = slots[0];
            out->Data = base;
            out->Stride = stride;
            ++out;
        }
        if (coded & 0x10)
        {
            out->Function = slots[1];
            out->Data = base + 8;
            out->Stride = stride;
            ++out;
        }
        if (coded & 8)
        {
            out->Function = slots[2];
            out->Data = base + (CriSint64)(stride * 8);
            out->Stride = stride;
            ++out;
        }
        if (coded & 4)
        {
            out->Function = slots[3];
            out->Data = base + (CriSint64)(stride * 8) + 8;
            out->Stride = stride;
            ++out;
        }
    }
    if (coded & 3)
    {
        CriSint32 stride = CriMpvField<CriSint16>(decoder, MPV_CHROMA_STRIDE);
        CriSint32 offset = (y >> 1) * stride + (x >> 1);
        if (coded & 2)
        {
            out->Function = slots[4];
            out->Data = CriMpvField<CriUint8*>(decoder, MPV_CB_BASE) + offset;
            out->Stride = stride;
            ++out;
        }
        if (coded & 1)
        {
            out->Function = slots[5];
            out->Data = CriMpvField<CriUint8*>(decoder, MPV_CR_BASE) + offset;
            out->Stride = stride;
            ++out;
        }
    }
    out->Function = NULL;
    DAT_143fe8250[(CriSint64)mode](entries);
}

// MS2-FUNCTIONAL: the all-blocks-coded form (coded mask 0xff000000, mode 0); cri_05 stores it in the
// macroblock-type dispatch table (LAB_142ccc850, no .pdata).
// @0x142ccc850
void FUN_142ccc850(void* decoder)
{
    FUN_142ccc6c0(decoder, (CriSint32)0xff000000, 0);
}

// MS2-FUNCTIONAL: run the skipped-macroblock callback for each address stepped back over, then resume reconstruction.
// @0x142ccc860
void FUN_142ccc860(void* decoder, CriSint32 run)
{
    CriMpvSkipFunc skip = CriMpvField<CriMpvSkipFunc>(decoder, MPV_SKIP_FUNC);
    CriSint32 target = CriMpvField<CriSint32>(decoder, MPV_ADDRESS);
    CriMpvField<CriSint32>(decoder, MPV_CODED) = 0;
    mpvumc_SubMbadr((CriMpvDecoderState*)decoder, run);
    if (CriMpvField<CriSint32>(decoder, MPV_ADDRESS) < target)
    {
        do
        {
            skip(decoder);
            mpvumc_IncreMbadr((CriMpvDecoderState*)decoder);
        } while (CriMpvField<CriSint32>(decoder, MPV_ADDRESS) < target);
    }
}

// MS2-FUNCTIONAL: motion-compensate one macroblock from a reference frame with a clamped motion vector.
// @0x142ccc8c0
void FUN_142ccc8c0(void* decoder, void* referenceFrame, void* motion, CriSint32 flags)
{
    struct Frame { CriUint8* Chroma0; CriUint8* Chroma1; CriUint8* Luma; CriSint16 ChromaStride; CriSint16 LumaStride; };
    struct Motion { CriUint8 Reserved00[0x18]; CriSint32 X; CriSint32 Y; };
    CriSint32 x = CriMpvField<CriSint32>(decoder, MPV_COLUMN) << 4;
    CriSint32 y = CriMpvField<CriSint32>(decoder, MPV_ROW) << 4;
    Motion* mv = (Motion*)motion;
    Frame* frame = (Frame*)referenceFrame;
    CriSint32 mvx = mv->X;
    CriSint32 mvy = mv->Y;
    CriSint32 widthLimit = CriMpvField<CriSint32>(decoder, MPV_MB_WIDTH) << 4;
    CriSint32 heightLimit = CriMpvField<CriSint32>(decoder, MPV_MB_HEIGHT) << 4;
    CriSint32 bound = (-x) * 2;
    if (mvx < bound)
    {
        CriMpvField<CriSint32>(decoder, MPV_CLAMP_COUNT) += 1;
        mvx = bound;
    }
    else
    {
        bound = (widthLimit - x) * 2 - 0x20;
        if (mvx > bound)
        {
            CriMpvField<CriSint32>(decoder, MPV_CLAMP_COUNT) += 1;
            mvx = bound;
        }
    }
    bound = (-y) * 2;
    if (mvy < bound)
    {
        mvy = bound;
        CriMpvField<CriSint32>(decoder, MPV_CLAMP_COUNT) += 1;
    }
    else
    {
        bound = (heightLimit - y) * 2 - 0x20;
        if (mvy > bound)
        {
            mvy = bound;
            CriMpvField<CriSint32>(decoder, MPV_CLAMP_COUNT) += 1;
        }
    }
    CriSint32 lumaStride = frame->LumaStride;
    FUN_142ccc5f0(frame->Luma, CriMpvField<CriUint8*>(decoder, MPV_LUMA_BASE), lumaStride, lumaStride, 0x10, 0x10, x, y,
                  mvx, mvy, flags);
    CriSint32 chromaStride = frame->ChromaStride;
    CriSint32 chromaX = x >> 1;
    CriSint32 chromaY = y >> 1;
    CriSint32 halfX = (mvx - (mvx >> 31)) >> 1;
    CriSint32 halfY = (mvy - (mvy >> 31)) >> 1;
    FUN_142ccc5f0(frame->Chroma0, CriMpvField<CriUint8*>(decoder, MPV_CB_BASE), chromaStride, chromaStride, 8, 8,
                  chromaX, chromaY, halfX, halfY, flags);
    FUN_142ccc5f0(frame->Chroma1, CriMpvField<CriUint8*>(decoder, MPV_CR_BASE), chromaStride, chromaStride, 8, 8,
                  chromaX, chromaY, halfX, halfY, flags);
}

// MS2-FUNCTIONAL: forward-predicted macroblock: compensate from the first reference and add the residual.
// @0x142ccca50
void FUN_142ccca50(void* decoder)
{
    FUN_142ccc8c0(decoder, (CriUint8*)decoder + MPV_REF0, (CriUint8*)decoder + MPV_MV0, 0);
    FUN_142ccc6c0(decoder, CriMpvField<CriSint32>(decoder, MPV_CODED), 1);
}

// MS2-FUNCTIONAL: backward-predicted macroblock: compensate from the second reference and add the residual.
// @0x142ccca90
void FUN_142ccca90(void* decoder)
{
    FUN_142ccc8c0(decoder, (CriUint8*)decoder + MPV_REF1, (CriUint8*)decoder + MPV_MV1, 0);
    FUN_142ccc6c0(decoder, CriMpvField<CriSint32>(decoder, MPV_CODED), 1);
}

// MS2-FUNCTIONAL: bidirectional macroblock: average both reference predictions and add the residual.
// @0x142cccad0
void FUN_142cccad0(void* decoder)
{
    FUN_142ccc8c0(decoder, (CriUint8*)decoder + MPV_REF0, (CriUint8*)decoder + MPV_MV0, 0);
    FUN_142ccc8c0(decoder, (CriUint8*)decoder + MPV_REF1, (CriUint8*)decoder + MPV_MV1, 1);
    FUN_142ccc6c0(decoder, CriMpvField<CriSint32>(decoder, MPV_CODED), 1);
}

// MS2-FUNCTIONAL: copy skipped macroblocks from the first reference with a zero motion vector.
// @0x142cccb30
void FUN_142cccb30(void* decoder, CriSint32 run)
{
    CriUint8 zeroMotion[0x20] = {};
    CriSint32 target = CriMpvField<CriSint32>(decoder, MPV_ADDRESS);
    mpvumc_SubMbadr((CriMpvDecoderState*)decoder, run);
    if (CriMpvField<CriSint32>(decoder, MPV_ADDRESS) < target)
    {
        do
        {
            FUN_142ccc8c0(decoder, (CriUint8*)decoder + MPV_REF0, zeroMotion, 0);
            mpvumc_IncreMbadr((CriMpvDecoderState*)decoder);
        } while (CriMpvField<CriSint32>(decoder, MPV_ADDRESS) < target);
    }
}

// MS2-FUNCTIONAL: decode the six 8x8 blocks of an intra macroblock and hand them to the block output function.
// @0x142cccba0
CriSint32 FUN_142cccba0(void* decoder)
{
    CriUint8* base = (CriUint8*)decoder;
    memset(base + MPV_COEF_LUMA, 0, 0x300);
    CriUint8* context = base + MPV_BLOCK_CONTEXT;
    CriMpvField<CriSint32>(context, 0x30) = CriMpvField<CriSint32>(decoder, MPV_QUANT);
    CriMpvField<CriSint32>(context, 0x48) = 0;
    CriMpvField<void*>(context, 0x28) = base + MPV_COEF_BASE;
    CriMpvField<void*>(context, 0x40) = CriMpvField<void*>(decoder, MPV_TABLE_LUMA);
    CriMpvField<void*>(context, 0x38) = base + MPV_DC;
    CriMpvField<void*>(context, 0x20) = base + MPV_COEF_LUMA;
    CriMpvDecodeBlockFunc decode = CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_BLOCK);
    CriSint32 counts[6];
    counts[0] = decode(decoder, context);
    CriMpvField<void*>(context, 0x20) = base + 0x980;
    counts[1] = decode(decoder, context);
    CriMpvField<void*>(context, 0x20) = base + 0xa00;
    counts[2] = decode(decoder, context);
    CriMpvField<void*>(context, 0x20) = base + 0xa80;
    counts[3] = decode(decoder, context);
    CriMpvField<void*>(context, 0x40) = CriMpvField<void*>(decoder, MPV_TABLE_CHROMA);
    CriMpvField<void*>(context, 0x38) = base + MPV_DC + 4;
    CriMpvField<void*>(context, 0x20) = base + 0xb00;
    counts[4] = decode(decoder, context);
    CriMpvField<void*>(context, 0x38) = base + MPV_DC + 8;
    CriMpvField<void*>(context, 0x20) = base + 0xb80;
    counts[5] = decode(decoder, context);
    CriMpvBlockFunc emit = CriMpvField<CriMpvBlockFunc>(decoder, MPV_BLOCK_FUNC);
    void** slots = (void**)(base + MPV_BLOCK_SLOTS);
    for (CriSint32 block = 0; block < 6; ++block)
        emit(base + MPV_COEF_LUMA + (CriSint64)block * 0x80, slots[block], counts[block]);
    return 0;
}

// MS2-FUNCTIONAL: decode the coded 8x8 inter blocks of a macroblock and hand them to the block output function.
// @0x142cccd80
CriSint32 FUN_142cccd80(void* decoder)
{
    CriUint8* base = (CriUint8*)decoder;
    CriUint8* context = base + MPV_BLOCK_CONTEXT;
    CriMpvField<CriSint32>(context, 0x48) = 1;
    CriMpvField<CriSint32>(context, 0x30) = CriMpvField<CriSint32>(decoder, MPV_QUANT);
    CriMpvField<void*>(context, 0x28) = base + MPV_COEF_BASE_FIRST;
    CriSint32 counts[6];
    CriSint32 mask = CriMpvField<CriSint32>(decoder, MPV_CODED) * 4;
    CriUint8* coefficients = base + MPV_COEF_LUMA;
    CriMpvDecodeBlockFunc decode = CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_INTER);
    for (CriSint32 block = 0; block < 6; ++block)
    {
        if (mask < 0)
        {
            CriMpvField<void*>(context, 0x20) = coefficients;
            counts[block] = decode(decoder, context);
        }
        mask += mask;
        coefficients += 0x80;
    }
    CriMpvBlockFunc emit = CriMpvField<CriMpvBlockFunc>(decoder, MPV_BLOCK_FUNC);
    void** slots = (void**)(base + MPV_BLOCK_SLOTS);
    mask = CriMpvField<CriSint32>(decoder, MPV_CODED) * 4;
    for (CriSint32 block = 0; block < 6; ++block)
    {
        if (mask < 0)
            emit(base + MPV_COEF_LUMA + (CriSint64)block * 0x80, slots[block], counts[block]);
        mask += mask;
    }
    return 0;
}

// MS2-FUNCTIONAL: decode the six blocks of an intra macroblock into 16-bit coefficient planes and emit their counts.
// @0x142cccef0
CriSint32 FUN_142cccef0(void* decoder)
{
    CriUint8* base = (CriUint8*)decoder;
    CriUint8* intra = base + MPV_COEF_INTRA;
    memset(intra, 0, 0x600);
    CriUint8* context = base + MPV_BLOCK_CONTEXT;
    CriMpvField<CriSint32>(context, 0x48) = 0;
    CriMpvField<CriSint32>(context, 0x30) = CriMpvField<CriSint32>(decoder, MPV_QUANT);
    CriMpvField<void*>(context, 0x28) = base + MPV_COEF_BASE;
    CriMpvField<void*>(context, 0x40) = CriMpvField<void*>(decoder, MPV_TABLE_LUMA);
    CriMpvField<void*>(context, 0x20) = intra;
    CriMpvField<void*>(context, 0x38) = base + MPV_DC;
    CriMpvDecodeBlockFunc decode = CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_BLOCK);
    CriUint8* counts = base + 0x1350;
    counts[0] = (CriUint8)decode(decoder, context);
    CriMpvField<void*>(context, 0x20) = base + 0x400;
    counts[1] = (CriUint8)decode(decoder, context);
    CriMpvField<void*>(context, 0x20) = base + 0x500;
    counts[2] = (CriUint8)decode(decoder, context);
    CriMpvField<void*>(context, 0x20) = base + 0x600;
    counts[3] = (CriUint8)decode(decoder, context);
    CriMpvField<void*>(context, 0x40) = CriMpvField<void*>(decoder, MPV_TABLE_CHROMA);
    CriMpvField<void*>(context, 0x38) = base + MPV_DC + 4;
    CriMpvField<void*>(context, 0x20) = base + 0x700;
    counts[4] = (CriUint8)decode(decoder, context);
    CriMpvField<void*>(context, 0x38) = base + MPV_DC + 8;
    CriMpvField<void*>(context, 0x20) = base + 0x800;
    counts[5] = (CriUint8)decode(decoder, context);
    CriMpvField<CriMpvEmitFunc>(decoder, MPV_BLOCK_FUNC)(counts);
    return 0;
}

// MS2-FUNCTIONAL: decode the coded inter blocks of a macroblock into 16-bit coefficient planes and emit their counts.
// @0x142ccd080
CriSint32 FUN_142ccd080(void* decoder)
{
    CriUint8* base = (CriUint8*)decoder;
    CriUint8* context = base + MPV_BLOCK_CONTEXT;
    CriMpvField<CriSint32>(context, 0x48) = 1;
    CriMpvField<CriSint32>(context, 0x30) = CriMpvField<CriSint32>(decoder, MPV_QUANT);
    CriMpvField<void*>(context, 0x28) = base + MPV_COEF_BASE_FIRST;
    CriUint8* coefficients = base + MPV_COEF_INTRA;
    CriSint32 mask = CriMpvField<CriSint32>(decoder, MPV_CODED) * 4;
    CriUint8* counts = base + 0x1350;
    CriMpvDecodeBlockFunc decode = CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_INTER);
    for (CriSint32 block = 0; block < 6; ++block)
    {
        if (mask < 0)
        {
            CriMpvField<void*>(context, 0x20) = coefficients;
            counts[block] = (CriUint8)decode(decoder, context);
        }
        mask += mask;
        coefficients += 0x100;
    }
    CriMpvField<CriSint32>(decoder, 0x1380) = CriMpvField<CriSint32>(decoder, MPV_CODED) * 4;
    CriMpvField<CriMpvEmitFunc>(decoder, MPV_EMIT_FUNC)(counts);
    return 0;
}

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

// MS2-FUNCTIONAL: decode one DC coefficient difference with the MPEG intra VLC tables and update its predictor.
// @0x142ccb520
CriSint32 FUN_142ccb520(void* decoder, void* parameters, CriSint32* output, CriSint32* predictor)
{
    struct Parameters { CriSint32 Double; CriSint32 Size; CriSint32 SignBits; CriSint32 Range; };
    Parameters* params = (Parameters*)parameters;
    CriMpvBitReader bits;
    bits.Load(decoder);
    CriUint32 window = bits.Peek(11);
    CriSint32 entry = (window & 0xffffff80) == 0 ? DAT_143d74a38[window] : DAT_143d749c8[window >> 6];
    CriSint32 symbol = (CriSint8)entry;
    if (symbol == 0x7f)
    {
        bits.Store(decoder);
        return -1;
    }
    bits.Consume((CriUint32)(CriUint16)entry >> 8);
    if (symbol == 0)
    {
        *output = *predictor;
    }
    else
    {
        CriSint32 size = params->Size;
        if (size != 0)
        {
            CriUint32 value = bits.Read(size);
            CriSint32 adjust = params->Range - (CriSint32)value - 1;
            symbol <<= size;
            if (symbol <= 0)
                symbol += adjust;
            else
                symbol -= adjust;
        }
        CriSint32 total = (CriSint32)((CriUint32)(*predictor + symbol) << params->SignBits) >> params->SignBits;
        *output = total;
        *predictor = total;
    }
    if (params->Double != 0)
        *output <<= 1;
    bits.Store(decoder);
    return 0;
}

// MS2-FUNCTIONAL: decode the macroblocks of an intra-only MPEG video slice chunk by chunk.
// @0x142ccb000
CriSint32 FUN_142ccb000(void* decoder, void* queue)
{
    CriMpvSlice slice;
    slice.Decoder = decoder;
    slice.Queue = queue;
    slice.GetChunk();
    slice.Bits.Start(slice.Chunk(), CriMpvField<CriUint32>(decoder, MPV_CHUNK_BIT_OFFSET));
    while (slice.Bits.Peek(23) != 0)
    {
        CriSint32 step;
        if (!slice.ReadAddress(12, DAT_143d74a30, DAT_143d749f0, &step))
            break;
        slice.ReadQuantiser(CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS));
        slice.Bits.Store(decoder);
        CriMpvField<void (*)(void*)>(decoder, 0x18d0)(decoder);
        CriMpvField<void (*)(void*)>(decoder, 0x1700)(decoder);
        CriMpvField<void (*)(void*)>(decoder, 0x1710)(decoder);
        if (!slice.AfterMacroblock())
            break;
    }
    return slice.Finish();
}

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

// MS2-FUNCTIONAL: decode the macroblocks of a predicted MPEG video slice with forward and backward vectors.
// @0x142ccb710
CriSint32 FUN_142ccb710(void* decoder, void* queue)
{
    CriMpvSlice slice;
    slice.Decoder = decoder;
    slice.Queue = queue;
    slice.GetChunk();
    slice.Bits.Start(slice.Chunk(), CriMpvField<CriUint32>(decoder, MPV_CHUNK_BIT_OFFSET));
    bool first = true;
    while (slice.Bits.Peek(23) != 0)
    {
        CriSint32 step;
        if (!slice.ReadAddress(11, DAT_143d749e0, DAT_143d749d8, &step))
            break;
        if (!first && (CriUint32)step > 1)
        {
            CriMpvField<CriMpvSkipRunFunc>(decoder, 0x16f8)(decoder, step);
            MPVDEC_ResetDc((CriMpvDecoderState*)decoder);
            FUN_1400663f0(decoder);
        }
        CriMpvField<CriMpvMacroblockFunc>(decoder, 0x18d0)(decoder);
        if (!(CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS) & 0x20))
        {
            CriSint32 entry = DAT_143d74a08[slice.Bits.Peek(6)];
            slice.Bits.Consume((CriUint8)entry);
            CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS) = (CriUint32)entry >> 8;
        }
        CriUint32 flags = CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS);
        slice.ReadQuantiser(flags);
        if ((flags & 8) && CriMpvReadMotion(slice, 0x174c))
            break;
        if ((CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS) & 4) && CriMpvReadMotion(slice, 0x1770))
            break;
        flags = CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS);
        CriMpvReadPattern(slice, flags);
        slice.Bits.Store(decoder);
        if (flags & 1)
        {
            CriMpvField<CriMpvMacroblockFunc>(decoder, 0x1700)(decoder);
            CriMpvField<CriMpvMacroblockFunc>(decoder, 0x1710)(decoder);
            MPVDEC_ResetMv((CriMpvDecoderState*)((CriUint8*)decoder + 0x174c));
            MPVDEC_ResetMv((CriMpvDecoderState*)((CriUint8*)decoder + 0x1770));
        }
        else
        {
            CriMpvMacroblockFunc predict = CriMpvField<CriMpvMacroblockFunc>(decoder, 0x1718 + ((flags >> 2) & 3) * 8);
            CriMpvField<CriMpvMacroblockFunc>(decoder, 0x1718) = predict;
            if (CriMpvField<CriSint32>(decoder, MPV_CODED) != 0)
                CriMpvField<CriMpvMacroblockFunc>(decoder, 0x1708)(decoder);
            predict(decoder);
            MPVDEC_ResetDc((CriMpvDecoderState*)decoder);
        }
        if (!slice.AfterMacroblock())
            break;
        first = false;
    }
    return slice.Finish();
}

// MS2-FUNCTIONAL: decode the macroblocks of a forward-predicted MPEG video slice with a single vector set.
// @0x142ccbe90
CriSint32 FUN_142ccbe90(void* decoder, void* queue)
{
    CriMpvSlice slice;
    slice.Decoder = decoder;
    slice.Queue = queue;
    slice.GetChunk();
    slice.Bits.Start(slice.Chunk(), CriMpvField<CriUint32>(decoder, MPV_CHUNK_BIT_OFFSET));
    bool first = true;
    while (slice.Bits.Peek(23) != 0)
    {
        CriSint32 step;
        if (!slice.ReadAddress(11, DAT_143d74a00, DAT_143d749f8, &step))
            break;
        if (!first && (CriUint32)step > 1)
        {
            CriMpvField<CriMpvSkipRunFunc>(decoder, 0x16f8)(decoder, step);
            MPVDEC_ResetMv((CriMpvDecoderState*)((CriUint8*)decoder + 0x174c));
            MPVDEC_ResetDc((CriMpvDecoderState*)decoder);
            FUN_1400663f0(decoder);
        }
        CriMpvField<CriMpvMacroblockFunc>(decoder, 0x18d0)(decoder);
        if (!(CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS) & 0x20))
        {
            CriSint32 entry = DAT_143d749d0[slice.Bits.Peek(5)];
            slice.Bits.Consume((CriUint8)entry);
            CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS) = (CriUint32)entry >> 8;
        }
        CriUint32 flags = CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS);
        slice.ReadQuantiser(flags);
        if (flags & 8)
        {
            if (CriMpvReadMotion(slice, 0x174c))
                break;
        }
        else
        {
            MPVDEC_ResetMv((CriMpvDecoderState*)((CriUint8*)decoder + 0x174c));
        }
        flags = CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS);
        CriMpvReadPattern(slice, flags);
        slice.Bits.Store(decoder);
        if (flags & 1)
        {
            CriMpvField<CriMpvMacroblockFunc>(decoder, 0x1700)(decoder);
            CriMpvField<CriMpvMacroblockFunc>(decoder, 0x1710)(decoder);
        }
        else
        {
            if (CriMpvField<CriSint32>(decoder, MPV_CODED) != 0)
                CriMpvField<CriMpvMacroblockFunc>(decoder, 0x1708)(decoder);
            CriMpvField<CriMpvMacroblockFunc>(decoder, 0x1728)(decoder);
            MPVDEC_ResetDc((CriMpvDecoderState*)decoder);
        }
        if (!slice.AfterMacroblock())
            break;
        first = false;
    }
    return slice.Finish();
}

void* FUN_14004eea0(void*, CriUint32);
CriSint32 FUN_140050bd0(void*, void*, void*);
void FUN_1400511d0(void*, void*, CriUint32);
void FUN_1400511f0(void*, CriUint32, void*);
CriSint32 FUN_140052c80(void*, void*, void*);
CriSint32 FUN_140052d00(void*, void*);

// MS2-FUNCTIONAL: decode one picture's slices into the supplied frame set through the MPEG video decoder.
// @0x140040850
CriSint32 FUN_140040850(void* player, void* stream, void* second, CriSint32* consumed, void* frames)
{
    struct Stream { void* Data; CriSint32 Size; };
    struct Object { CriUint8 Reserved00[0x18]; CriSint32 Reserved18; CriSint32 Reserved1c; CriSint32 Reserved20; CriSint32 Reserved24; };
    typedef CriSint32 (*SizeFunc)(void*, CriSint32);
    typedef void (*ReleaseFunc)(void*);
    Stream* input = (Stream*)stream;
    Stream* tail = (Stream*)second;
    void* temporary = NULL;
    void* object;
    if (second == NULL)
    {
        object = FUN_14004eea0(input->Data, (CriUint32)input->Size);
        temporary = object;
        if (!object)
            return -1;
    }
    else
    {
        object = CriMpvField<void*>(player, 0x220);
        if (!object)
            return -1;
        CriSint32 head = (CriSint32)(uintptr_t)input->Data - (CriSint32)(uintptr_t)CriMpvField<void*>(player, 0x228);
        CriSint32 tailBytes = tail->Size + CriMpvField<CriSint32>(player, 0x234);
        CriMpvField<CriSint32>(object, 0x24) = head;
        CriMpvField<CriSint32>(object, 0x20) = tailBytes;
        CriMpvField<CriSint32>(object, 0x1c) = head - tailBytes;
        CriMpvField<CriSint32>(object, 0x18) = CriMpvField<CriSint32>(player, 0x230) - CriMpvField<CriSint32>(object, 0x1c);
    }
    CriSint32 result = FUN_140050bd0(CriMpvField<void*>(player, 0x78), object, frames);
    void** vtable = *(void***)object;
    if (second == NULL)
    {
        *consumed = input->Size - ((SizeFunc)vtable[9])(object, 1);
    }
    else
    {
        CriSint32 total = input->Size + tail->Size;
        *consumed = total - ((SizeFunc)vtable[9])(object, 1);
    }
    if (temporary)
        ((ReleaseFunc)(*(void***)temporary)[3])(temporary);
    return result;
}

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

// MS2-FUNCTIONAL: pull the next demuxed video picture, decode it and update the reference-picture window.
// @0x14003efc0
CriSint32 FUN_14003efc0(void* player)
{
    struct Chunk { void* Data; CriSint32 Size; CriSint32 Reserved; };
    struct Record { CriUint8* Picture; CriUint8 Reserved08[8]; CriUint8* Output; CriUint32 Reserved18; CriSint32 Width;
                    CriSint32 Height; CriUint32 Reserved24; CriUint64 Reserved28; CriUint64 Reserved30; };
    typedef void (*InspectFunc)(void*, void*, void*);
    CriUint8* d = (CriUint8*)player;
    void* inputQueue = CriMpvField<void*>(player, 0x180);
    void* poolQueue = CriMpvField<void*>(player, 0x58);
    void* decoder = CriMpvField<void*>(player, 0x78);
    CriSint32 produced = 0;
    CriSint32 headerBytes = 0;
    CriMpvField<void*>(player, 0x70) = NULL;
    for (;;)
    {
        if (produced != 0)
            return produced;
        CriSint32 attributes[4] = {};
        CriSint32 skip = 0;
        CriSint32 dropAnchor = 0;
        CriSint32 dropPair = 0;
        if (FUN_1400467b8(inputQueue, 2) == 0)
            return produced;
        Chunk chunk;
        Chunk extra;
        FUN_1400467a0(inputQueue, 2, 0xffffffff, &chunk);
        if (CriMpvField<InspectFunc>(player, 0x248) != NULL)
        {
            Chunk* secondary = NULL;
            if (FUN_14003d6c0(&chunk) != 0)
            {
                FUN_1400467a0(inputQueue, 2, 0xffffffff, &extra);
                secondary = &extra;
            }
            CriMpvField<InspectFunc>(player, 0x248)(&chunk, secondary, CriMpvField<void*>(player, 0x250));
            if (secondary)
                FUN_1400467a8(inputQueue, 2, &extra);
        }
        CriSint32 payloadSize;
        CriUint8* payload = (CriUint8*)criUsfCmn_GetContents((const CriUint8*)chunk.Data, (CriUint32)chunk.Size, &payloadSize);
        Chunk packet = { payload, payloadSize, 0 };
        CriUint8* start = (CriUint8*)FUN_1400530c0(payload, (CriUint32)payloadSize, 0x4c);
        if (!start)
        {
            FUN_1400467a8(inputQueue, 2, &chunk);
            FUN_140041110(0, "E06100901M : Failed MPV_SearchDelim().", CriMpvField<CriUint32>(player, 0x194));
            CriMpvField<CriSint32>(player, 0x18) = 4;
            return produced;
        }
        CriUint8 saved[0x40];
        FUN_1400511d0(decoder, saved, 0x40);
        Chunk stream;
        stream.Data = start;
        stream.Size = chunk.Size - ((CriSint32)(uintptr_t)start - (CriSint32)(uintptr_t)chunk.Data);
        if (FUN_140052c80(decoder, &stream, attributes) != 0)
        {
            FUN_1400467a8(inputQueue, 2, &chunk);
            FUN_140041110(0, "E06100902M : failed MPV_DecodePicAtr().", CriMpvField<CriUint32>(player, 0x194));
            CriMpvField<CriSint32>(player, 0x18) = 4;
            return produced;
        }
        if (FUN_140052d00(decoder, d + 0xf8) != 0)
        {
            FUN_1400467a8(inputQueue, 2, &chunk);
            FUN_140041110(0, "E06100903M : MPV_GetPicAtr().", CriMpvField<CriUint32>(player, 0x194));
            CriMpvField<CriSint32>(player, 0x18) = 4;
            return produced;
        }
        CriSint32 width = CriMpvField<CriSint32>(player, 0xf8);
        CriSint32 height = CriMpvField<CriSint32>(player, 0xfc);
        CriSint32 pictureType = CriMpvField<CriSint32>(player, 0x110);
        CriUint32 headerSize;
        FUN_1400511f0(decoder, 0, &headerSize);
        attributes[2] = FUN_140040f80(saved, (CriSint32)headerSize);
        stream.Data = (CriUint8*)stream.Data + attributes[0];
        stream.Size -= attributes[0];
        Chunk slot;
        FUN_1400467a0(poolQueue, 0, 0xffffffff, &slot);
        if (!slot.Data)
        {
            FUN_1400467a8(inputQueue, 2, &chunk);
            FUN_1400410d0(0, "E06100904M : Can't get chunk data from frame buffer Sj.", 0);
            CriMpvField<CriSint32>(player, 0x18) = 4;
            return produced;
        }
        Record* record = (Record*)slot.Data;
        void* current = d + 0xc0;
        CriMpvSetTiledFrame(current, record->Picture, width, height);
        CriMpvField<void*>(player, 0xe0) = d + 0xf8;
        void* forward = d + 0x80;
        void* backward = d + 0xa0;
        if (pictureType < 1)
        {
            FUN_1400467a8(inputQueue, 2, &chunk);
            FUN_140041110(0, "E06100908M : Found D Picture.", 0);
            CriMpvField<CriSint32>(player, 0x18) = 4;
            return produced;
        }
        if (pictureType < 3)
        {
            if (CriMpvField<void*>(player, 0x90) == NULL && CriMpvField<void*>(player, 0xb0) == NULL)
            {
                if (pictureType == 2)
                {
                    skip = 1;
                    if (CriMpvField<CriSint32>(player, 0x34) != 1)
                    {
                        attributes[1] = 1;
                        dropPair = 1;
                    }
                }
                else if (CriMpvField<CriSint32>(player, 0x34) == 1)
                {
                    CriMpvField<void*>(player, 0x70) = CriMpvField<void*>(player, 0xd0);
                    FUN_140040a20(player, (void**)&slot);
                    CriMpvField<CriSint32>(player, 0x240) += 1;
                }
                else
                {
                    CriMpvSetTiledFrame(backward, CriMpvField<CriUint8*>(player, 0xd0), width, height);
                    CriMpvField<void*>(player, 0x70) = NULL;
                    memcpy(d + 0x60, &slot, 0x10);
                }
            }
            else
            {
                CriMpvSetTiledFrame(forward, CriMpvField<CriUint8*>(player, 0xb0), width, height);
                CriMpvSetTiledFrame(backward, CriMpvField<CriUint8*>(player, 0xd0), width, height);
                CriMpvField<void*>(player, 0x70) = CriMpvField<void*>(player, 0x90);
                if (CriMpvField<void*>(player, 0x90) != NULL || CriMpvField<void*>(player, 0xb0) == NULL)
                {
                    Chunk pending;
                    if (FUN_1400467b8(poolQueue, 3) != 0)
                    {
                        FUN_1400467a0(poolQueue, 3, 0xffffffff, &pending);
                        if (!pending.Data)
                        {
                            FUN_1400467a8(inputQueue, 2, &chunk);
                            FUN_1400410d0(0, "E06100906M : Failed in crivmpv_DecodeOnePictureInPool() [IP-2a]", 0);
                            CriMpvField<CriSint32>(player, 0x18) = 4;
                            return produced;
                        }
                        FUN_1400467b0(poolQueue, 0, &pending);
                    }
                    memcpy(&pending, d + 0x60, 0x10);
                    if (!pending.Data)
                    {
                        FUN_1400467a8(inputQueue, 2, &chunk);
                        FUN_1400410d0(0, "E06100907M : Failed in crivmpv_DecodeOnePictureInPool() [IP-2b]", 0);
                        CriMpvField<CriSint32>(player, 0x18) = 4;
                        return produced;
                    }
                    FUN_140040a20(player, (void**)&pending);
                    CriMpvField<CriSint32>(player, 0x240) += 1;
                    memcpy(d + 0x60, &slot, 0x10);
                }
                else
                {
                    Chunk pending;
                    memcpy(&pending, d + 0x60, 0x10);
                    if (!pending.Data)
                    {
                        FUN_1400467a8(inputQueue, 2, &chunk);
                        FUN_1400410d0(0, "E06100905M : Failed in crivmpv_DecodeOnePictureInPool() [IP-1]", 0);
                        CriMpvField<CriSint32>(player, 0x18) = 4;
                        return produced;
                    }
                    FUN_140040a20(player, (void**)&pending);
                    CriMpvField<CriSint32>(player, 0x240) += 1;
                    memcpy(d + 0x60, &slot, 0x10);
                }
            }
        }
        else
        {
            if (pictureType != 3)
            {
                FUN_1400467a8(inputQueue, 2, &chunk);
                FUN_140041110(0, "E06100908M : Found D Picture.", 0);
                CriMpvField<CriSint32>(player, 0x18) = 4;
                return produced;
            }
            if (CriMpvField<CriUint32>(player, 0x34) < 3)
            {
                skip = 1;
            }
            else
            {
                if (CriMpvField<void*>(player, 0xb0) == NULL || CriMpvField<void*>(player, 0x90) == NULL)
                {
                    skip = 1;
                    attributes[1] = 1;
                    if (CriMpvField<void*>(player, 0xb0) == NULL && CriMpvField<void*>(player, 0x90) == NULL)
                        dropPair = 1;
                }
                else
                {
                    CriMpvField<void*>(player, 0x70) = CriMpvField<void*>(player, 0xd0);
                }
                if (dropPair != 1)
                    CriMpvField<CriSint32>(player, 0x240) += 1;
            }
        }
        CriSint32 window = CriMpvField<CriSint32>(player, 0x238) + CriMpvField<CriSint32>(player, 0x23c);
        CriSint32 decoded = CriMpvField<CriSint32>(player, 0x238) - 1 + CriMpvField<CriSint32>(player, 0x240);
        if (window > 0 && pictureType == 3 && decoded < window)
        {
            skip = 1;
            CriMpvField<CriSint32>(player, 0x19c) += 1;
        }
        if (window <= decoded && CriMpvField<CriSint32>(player, 0x1a0) != 0 && pictureType == 3)
        {
            skip = 1;
            dropAnchor = 1;
        }
        if (skip == 1)
        {
            FUN_1400467a8(poolQueue, 0, &slot);
            FUN_1400467b0(inputQueue, 0, &chunk);
            if (FUN_14003d6c0(&chunk) != 0)
            {
                FUN_1400467a0(inputQueue, 2, 0xffffffff, &extra);
                FUN_1400467b0(inputQueue, 0, &extra);
            }
            CriMpvField<CriSint32>(player, 0x188) -= 1;
            if (dropPair == 1)
            {
                CriMpvField<CriSint32>(player, 0x18c) -= 1;
            }
            else
            {
                CriMpvField<CriSint32>(player, 0x1a4) += 1;
                if (dropAnchor == 1)
                    CriMpvField<CriSint32>(player, 0x1a0) -= 1;
            }
            FUN_14003ed40(player);
        }
        else
        {
            Chunk tailChunk = {};
            Chunk* secondary = NULL;
            if (FUN_14003d6c0(&chunk) != 0)
            {
                FUN_1400467a0(inputQueue, 2, 0xffffffff, &extra);
                tailChunk = extra;
                secondary = &tailChunk;
            }
            if (FUN_140040850(player, &stream, secondary, &headerBytes, forward) != 0)
            {
                FUN_1400467a8(inputQueue, 2, &packet);
                FUN_140041110(0, "E06100909M : Failed MPV_DecodeFrm().", 0);
                CriMpvField<CriSint32>(player, 0x18) = 4;
                return produced;
            }
            CriMpvField<CriSint32>(player, 0x194) += 1;
            produced += 1;
            record->Output = CriMpvField<CriUint8*>(player, 0xd0);
            record->Reserved18 = 0;
            record->Width = CriMpvField<CriSint32>(player, 0xf8);
            record->Height = CriMpvField<CriSint32>(player, 0xfc);
            record->Reserved24 = CriMpvField<CriUint32>(player, 0x38);
            record->Reserved28 = 0;
            record->Reserved30 = CriMpvField<CriUint32>(player, 0x38);
            CriMpvField<CriUint32>(record, 0xb0) = 0;
            CriMpvField<CriSint32>(record, 0xbc) = attributes[2];
            if (FUN_1400405d0(&stream, &tailChunk, (CriUint32)headerBytes) == 1)
                CriMpvField<CriSint32>(player, 0x1ac) = 1;
            if (pictureType == 3)
                FUN_140040a20(player, (void**)&slot);
            FUN_1400467b0(inputQueue, 0, &chunk);
            if (FUN_14003d6c0(&chunk) != 0)
            {
                extra = tailChunk;
                FUN_1400467b0(inputQueue, 0, &extra);
            }
            CriMpvField<CriSint32>(player, 0x188) -= 1;
            FUN_14003ed40(player);
        }
    }
}

// ---- full-exe unresolved: leaves without .pdata that data_cri / data_data_game reference as ?FUN_<va>@@YAXXZ ----

struct cri03_stream { virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0;
                      virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0;
                      virtual void v8() = 0; virtual void* Call9(long long a, long long b, long long c) = 0; };

struct cri03_host20 { void* vtbl; void* _08[3]; cri03_stream* stream; };
// MS2-FUNCTIONAL: forwards to slot 9 (+0x48) of the object at +0x20; 0 without one.
// @0x140041360
void* FUN_140041360(cri03_host20* self, long long a, long long b, long long c)
{
    cri03_stream* o = self->stream;
    return o ? o->Call9(a, b, c) : NULL;
}

// MS2-FUNCTIONAL: empty interface slot.
// @0x140041c50
void FUN_140041c50(void*) {}

struct cri03_host08 { void* vtbl; cri03_stream* stream; };
// MS2-FUNCTIONAL: slot 9 (+0x48) of the object at +8 with (a, d, 0), both ints sign-extended.
// @0x140041d00
void* FUN_140041d00(cri03_host08* self, CriSint32 a, void*, CriSint32 d)
{
    cri03_stream* o = self->stream;
    return o->Call9(a, d, 0);
}

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

// Boot tags 96/98: these address-named entry points create critical sections.
// Strong definitions prevent stale CuePoint::Resize alias rows from selecting
// an unrelated array implementation. All forms call the recovered body above.
void* FUN_140039ea8(void* work, CriSint32 size) { return criCs_Create(work, size); }
extern "C" void* FUN_140039ea8(void* work, int size) { return criCs_Create(work, size); }
void* FUN_1400385c8(void* work, CriUint32 size) { return criCs_Create(work, static_cast<CriSint32>(size)); }
extern "C" void* FUN_1400385c8(void* work, unsigned long long size) { return criCs_Create(work, static_cast<CriSint32>(size)); }
