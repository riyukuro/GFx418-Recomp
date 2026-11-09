// Recovered CRI Movie decoder and timing helpers from MapleStory2.exe, written from the executable's behavior: the /Od
// criMvPly, criVmpv, criVdecCmn, Amng/Adec, criAlphaDec and criVdec objs (with the small /O2 objs between them) and the
// mpvumc code. The /Os criCs/criUtf objs below are sfr_cri_03a, the /Os criUsfDmx/criSj objs above are sfr_cri_03b.
// 0x14003ed40 and 0x140042700 are in sfr_cri_03d: their exe objs were compiled as C (/TC).
// The CRI Movie 3.07 library was built with VS2008 SP1, and so is this unit (MS2-TOOLSET: vc9, cmake/ms2-unit-profiles.cmake):
// keep it C++03 (no auto, decltype, variadic templates, brace-init or nullptr). clang-cl compiles it as before.
// MS2-UNIT: sfr_cri_03
// MS2-TOOLSET: vc9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14003b6e0-0x14003c390 .text$mn
// MS2-RANGE: 0x14003c8d0-0x14003cff0 .text$mn
// MS2-RANGE: 0x14003d4b0-0x14003ed40 .text$mn
// MS2-RANGE: 0x14003eeb0-0x140042270 .text$mn
// MS2-RANGE: 0x140042600-0x140042700 .text$mn
// MS2-RANGE: 0x1400427b0-0x140044e84 .text$mn
// MS2-RANGE: 0x142ccb000-0x142ccd143 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
struct Unk_Frame;
struct Unk_Surface;
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
// "<SUDPS_>": the USF packet signature retrieveCscFlag copies into a local
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
// (the SyncObject vftable 0x1431b4f78 comes from its inline destructor in sfr_cri_03)
void criAdec_Initialize(void);
void criAdec_Finalize(void);
void crivmpv_ErrorFunc(void*, CriSint32);
void criCs_GetVersionString(void);
CriBool criCsWin_InitializeCriticalSection(LPCRITICAL_SECTION);
CriBool criCsWin_DeleteCriticalSection(LPCRITICAL_SECTION);
CriBool FUN_140039e24(LPCRITICAL_SECTION);
CriBool FUN_140039e4c(LPCRITICAL_SECTION);
void FUN_140038ddc(CriSint32, const CriChar8*);
void* criUtfRtv_CreateWithHeapType(void*, CriSint32, const void*, CriUint32);
void FUN_14003e850(void*, void*, void*);
void MPV_Finish(void);
void SJMEM_Finish(void);
void SJRBF_Finish(void);
unsigned int MPV_Destroy(__int64);    // C3: the definition's signature
extern "C" void criSj_Destroy(void*);
extern "C" unsigned __int64 SJRBF_Create(unsigned __int64, unsigned int, unsigned int);   // C3: the definition's signature
extern "C" void criVmpv_Destroy(void*);
extern "C" CriSint32 FUN_14003cff0(void*);   // C3: defined in the C unit sfr_cri_03d
CriUint32 criVdecCmn_GetNumPictureData(const void* decoder);
void* FUN_140027f7c(void*, CriSint32, const CriChar8*, CriSint32, CriSint32);
void* criUtfRtv_CreateByUtfHeapWithHeapType(void*, CriUint32, const void*, CriUint32);
unsigned int MPV_SetCond(__int64, int, unsigned int);    // C3: the definition's signature
void MPV_SetDlgPara(unsigned int, __int64); // C3: the definition's signature
__int64 MPV_Create(void);     // C3: the definition's signature
unsigned int MPV_SetErrFunc(__int64, unsigned __int64, unsigned __int64); // C3: the definition's signature
extern "C" void criSj_UngetChunk(void*, CriSint32, void*);
extern "C" void criSj_PutChunk(void*, CriSint32, void*);
extern "C" CriSint32 FUN_1400467b8(void*, CriSint32);
extern "C" void criSj_Reset(void*);
extern "C" void criSj_GetChunk(void*, CriSint32, CriUint32, void*);
CriSint32 FUN_140053630(void*);
CriUint32 criMvPlyAdec_GetDataSizeWave(void*, void*, CriUint32);
CriBool mvPlyAdec_IsReadyAudioPlayback(void*, const void*);
CriUint32 criMvPlyAdec_GetWave16(void*, void*, CriUint32, void*, CriUint32, CriUint32*);
CriUint32 criMvPlyAdec_GetWave32(void*, void*, CriUint32, void*, CriUint32, CriUint32*);
void criSj_SplitChunk(const void*, CriUint32, void*, void*);
CriSint32 FUN_140027dd0(CriSint32);
CriSint32 criVmpv_GetStatus(const void*);
void criVmpv_ReleaseFramePointer(void*, const void*);
const void** criVmpv_GetInterface(void);
const void** criVmpv_GetAlphaInterface(void);
void criMvPly_AttachCodec(const CriMvCodecRegistrationEntry* registration);
void FUN_140046014(void*);
void FUN_14004602c(void*);
extern "C" CriSint32 criSjRbf_GetRequiredMemorySizeWithConfig(CriUint32, CriUint32, CriUint32, const CriUint32*);
extern "C" void* criSj_CreateNamedRingBuffer(void*, CriUint32, CriUint32, CriUint32, CriUint64);
extern "C" unsigned __int64 * criAdec_Create(unsigned __int64, unsigned int, unsigned int); // C3: the definition's signature
extern "C" void FUN_1400534d0(void*);
extern "C" void criAdec_SetInputSj(__int64, unsigned __int64); // C3: the definition's signature
extern "C" void criAdec_SetOutputSj(__int64, unsigned int, unsigned __int64); // C3: the definition's signature
extern "C" void criMvPlyAmng_DestroyAudioDecoder(void*, void*, CriSint32);
void* FUN_140041910(void** decoderObject, void** mediaInterface);
// Scaleform runtime calls of the CRI glue, through views of the Scaleform classes (no Scaleform header here)
namespace Scaleform {
class MemoryHeap { public: void ReleaseOnFree(void* ptr); };
class Memory { public: static MemoryHeap* pGlobalHeap; };
class Timer { public: static unsigned __int64 GetRawTicks(); static unsigned __int64 GetRawFrequency(); };
class RefCountNTSImplCore { protected: mutable int RefCount; public: virtual ~RefCountNTSImplCore(); }; // 0x14257db50
namespace GFx { namespace Video { class VideoPlayer { public: class SyncObject : public RefCountNTSImplCore { public: virtual void SetStartFrame(unsigned) = 0; virtual void Start() = 0; virtual void Stop() = 0; virtual void Pause(bool) = 0; virtual void GetTime(unsigned __int64*, unsigned __int64*) = 0; virtual ~SyncObject() {} void operator delete(void* p) { void* heap = Memory::pGlobalHeap; ((void (*)(void*, void*))*(void**)((char*)*(void**)heap + 0x60))(heap, p); } }; }; } } // video_video.h view (SF heap delete, as SF_MEMORY_REDEFINE_NEW)
namespace Render {
struct ImagePlane;
class ImageData { public: void GetPlane(unsigned index, ImagePlane* plane) const; unsigned GetPlaneCount() const; };
class Texture;
class Image { protected: void initTexture_NoAddRef(Texture* texture); // 0x14257da20, the decoder's cached-instance store folds with it
    friend void* ::FUN_140041910(void**, void**); };
}
}
void FUN_140054040(__int64, unsigned __int64, unsigned __int64);  // C3: the definition's signature
void FUN_140053540(__int64);  // C3: the definition's signature
extern "C" void crimvply_occurFatalError(void*, const CriChar8*, CriSint32);
extern "C" void crimvply_transitErrorState(void* player, void* message);
unsigned __int64 criAadx_Execute(__int64); // C3: the definition's signature
void FUN_140053470(unsigned __int64 *);  // C3: the definition's signature
extern "C" void crimvply_occurUserError(void*, const CriChar8*, CriSint32);
extern "C" void criMvPlyAmng_DestroyAudioDecoder(void*, void*, CriSint32);
CriSint32 criMvPly_GetStatus(void* player);
void FUN_1400345e0(void *, void *, unsigned long, unsigned long);  // C3: the definition's signature
void criAadx_InsertDummyHeader(void*, CriUint32, CriUint32, CriUint32);
void criSj_SplitChunk(const void* source, CriUint32 maximum, void* prefix, void* suffix);
void SJRBF_Init(void);
void SJMEM_Init(void);
int MPV_Init(unsigned int size, CriUint64 base);        // sfr_cri_05: int(cri_u32, cri_u64)
void* criVmpv_GetNextFrameInfo(void*, void*);
void* criVmpv_GetFramePointer(void*, void*);
void FUN_140040cc0(void*, CriUint32, CriSint32*, CriSint32*);
void criErr_NotifyGeneric(CriSint32, const char*, CriSint32);
void criErr_NotifyPrmArray(CriSint32, const char*, CriSint32, CriSint32, void*);
extern "C" void FUN_140041110(void*, const char*, CriUint32);
void FUN_140046d50(void*, CriSint32);
void FUN_140053570(__int64);  // C3: the definition's signature
void MPV_RequestStop(__int64); // C3: the definition's signature
void criAdec_TerminateSupply(__int64); // C3: the definition's signature
CriUint32 FUN_1400472c0(const CriUint8*, CriUint32);
void* FUN_140046e04(void*, void*, CriUint32, void*, void*, const void*, CriUint32, void*, CriUint32);
const CriChar8* criUtfRtv_GetDataStr(const CriUtfRtvView*, CriUint32, CriUint32);
extern "C" CriUint32 criUsfCmn_ParseUsfHeaderStd(const CriUint8*, CriUint32, CriUsfStandardHeader*);
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
extern "C" CriSint32 criSjUni_CalculateWorkSize(const CriSint32* config);
extern "C" void* criSjUni_Create(const void*, void*, CriSint32);
extern "C" CriSint32 criSjRbf_CalculateWorkSize(const CriSint32* config);
extern "C" void* criSjRbf_Create(const void*, void*, CriSint32);
void FUN_140045998(void*);
void FUN_140045fdc(void*);
void criusfdmx_exec_decode(void*);
void FUN_14029dd60(void*, const CriChar8*, const void*);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// send the supplied CRI diagnostic through the movie error dispatcher.
// @0x1400410d0
extern "C" void crivmpv_occurFatalError(void* owner, const CriChar8* message, CriUint32 value)
{
    criErr_NotifyPrmArray(0, message, (CriSint32)value, 0, owner);
}

// the second CRI diagnostic entry point forwards the same tuple to the shared dispatcher.
// @0x140041110
extern "C" void FUN_140041110(void* owner, const CriChar8* message, CriUint32 value)
{
    criErr_NotifyPrmArray(0, message, (CriSint32)value, 0, owner);
}

// report the picture decode failure through the generic CRI error callback.
// @0x140041190
void crivmpv_ErrorFunc(void* object, CriSint32 value)
{
    object = object;
    value = value;
    crivmpv_occurFatalError(NULL, "E07111401M : An error occurred while decoding picture data in MPV module.", 0);
}

// forward the contained synchronization object to its release helper when present.
// @0x1400435d0
void mvPlyAdec_StopAudioDecoder(void* object)
{
    struct SyncHolder { CriUint8 Reserved[0x10]; void* Sync; };
    if (!object)
        return;
    if (((SyncHolder*)object)->Sync)
        FUN_140053570((__int64)(((SyncHolder*)object)->Sync));
}

// increment the movie player's paired audio and video progress counters.
// @0x14003ebe0
void FUN_14003ebe0(void* object)
{
    struct ProgressState { CriUint8 Reserved[0x19c]; CriSint32 Audio; CriSint32 Video; };
    ProgressState* state = (ProgressState*)object;
    ++state->Audio;
    ++state->Video;
}

// accept only USF chunks whose parsed standard header has no special record flag.
// @0x14003eeb0
extern "C" CriBool FUN_14003eeb0(const void* input)
{
    struct Input { const CriUint8* Data; CriUint32 Size; };
    CriUsfHeaderFields header;
    CriUint32 parsed = criUsfCmn_ParseUsfHeaderStd(((const Input*)input)->Data, ((const Input*)input)->Size,
                                                   (CriUsfStandardHeader*)&header);
    if (!parsed || header.Kind != 0)
        return 0;
    else
        return 1;
}

// mark the input object active and release its retained work buffer when present.
// @0x14003d8f0
void criVmpv_RequestStop(void* object)
{
    struct InputState { CriUint8 Reserved00[0x1c]; CriUint32 Active; CriUint8 Reserved20[0x58]; void* Work; };
    InputState* state = (InputState*)object;
    state->Active = 1;
    if (state->Work)
        MPV_RequestStop((__int64)state->Work);
}
#pragma optimize("", on)

// initialize the CRI timer record from the system clock and clear its elapsed state.
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
    state->SystemStart = Scaleform::Timer::GetRawFrequency();
    state->Reserved40 = 0;
    state->Mode = 0;
    state->Start = Scaleform::Timer::GetRawTicks();
    state->Active = 1;
}

// translate the reader interface's three states into the movie's public status values.
// @0x140041300
CriUint32 FUN_140041300(void* object)
{
    struct ReaderOwner { CriUint8 Reserved[0x10]; void* Reader; };
    ReaderOwner* owner = (ReaderOwner*)object;
    void* reader = owner->Reader;
    if (!reader)
        return 0;
    void** vtable = *(void***)reader;
    switch (((CriSint32 (*)(void*))vtable[7])(reader))
    {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 0;
    default:
        return 2;
    }
}

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// flag the video player and notify its retained work object.
// @0x140043680
void mvPlyAdec_TerminateSupplyAudioDecoder(void* object)
{
    struct PlayerState
    {
        CriSint32 Type;
        CriUint8 Reserved04[0x0c];
        void* Work;
        CriUint8 Reserved18[0x78];
        CriSint32 Active;
    };
    if (object && ((PlayerState*)object)->Type)
    {
        ((PlayerState*)object)->Active = 1;
        criAdec_TerminateSupply((__int64)(((PlayerState*)object)->Work));
    }
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void* criSjUni_CreateByHeap(const void* config, void* heap, CriUint32 allocationMode);

void* criSjRbf_CreateByHeap(const void* config, void* heap, CriUint32 allocationMode);

void criSj_CreateUniversalWithConfig(void* heap, CriUint32 first, CriUint32 second, const CriUint32* settings);

void criSjWithoutCS_CreateUniversal(void* heap, CriUint32 first, CriUint32 second);

extern "C" void* criSj_CreateUniversal(void* heap, CriUint32 first, CriUint32 second);

void* criSj_CreateNamedRingBufferWithConfig(void* heap, CriUint32 first, CriUint32 second, CriUint32 third,
                   CriUint64 poolBytes, const CriUint32* settings);

void FUN_1400463c8(void* object);

void FUN_140046598(void* object);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// report whether a stream-joint has completed its terminal audio transition.
// @0x140043810
CriBool mvPlyAdec_IsEndAudioPlayback(void* object, void* owner)
{
    struct DecoderState
    {
        CriSint32 Type;
        CriUint8 Reserved04[0x0c];
        void* Work;
        CriUint8 Reserved18[0x18];
        void* Queue;
    };
    if (!object || !owner)
        return 1;
    if (object && ((DecoderState*)object)->Type)
    {
        if (FUN_140053630(((DecoderState*)object)->Work) != 3)
            return 0;
        CriUint32 queued = (CriUint32)FUN_1400467b8(((DecoderState*)object)->Queue, 1);
        if (queued > 0)
            return 0;
    }
    return 1;
}

// check one selected audio decoder, treating a missing list as ready.
// @0x140042df0
CriBool criMvPlyAmng_IsEndAudioPlaybackById(void* decoders, void* owner, CriSint32 index)
{
    if (!decoders)
        return 1;
    return mvPlyAdec_IsEndAudioPlayback(((void**)decoders)[index], owner);
}

// forward a selected audio decoder's channel query.
// @0x140042f00
CriUint32 criMvPlyAmng_GetDataSizeWave(void* decoders, CriSint32 index, void* player, CriUint32 channel)
{
    return criMvPlyAdec_GetDataSizeWave(((void**)decoders)[index], player, channel);
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
CriSint32 criSj_PutOutputChunk2(void* streamJoint, const void* chunk, void* suffix, CriUint32 maximum);

void FUN_1400469a4(CriChar8* buffer, size_t capacity, const CriChar8* format, ...);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// return the selected decoder's available sample count in player time units.
// @0x14003d9d0
CriUint32 criVmpv_GetNumDecPool(void* object)
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
    samples /= reader->Unit;
    return samples;
}

// return ready when every stored audio decoder has completed its terminal transition.
// @0x140042d70
CriBool criMvPlyAmng_IsEndAudioPlayback(void* decoderList, void* owner)
{
    struct DecoderList { void* Decoders[2]; CriSint32 Count; };
    CriBool ready;
    CriSint32 index;
    if (!decoderList)
        return 1;
    for (index = 0; index < ((DecoderList*)decoderList)->Count; ++index)
    {
        ready = mvPlyAdec_IsEndAudioPlayback(((DecoderList*)decoderList)->Decoders[index], owner);
        if (!ready)
            return 0;
    }
    return 1;
}

// forward one decoder's interleaved output request.
// @0x140042e40
CriUint32 criMvPlyAmng_GetWave16(void* decoders, CriSint32 index, void* player, CriUint32 channels,
                        void* output, CriUint32 flags, CriUint32* result)
{
    return criMvPlyAdec_GetWave16(((void**)decoders)[index], player, channels, output, flags, result);
}

// forward one decoder's planar output request.
// @0x140042ea0
CriUint32 criMvPlyAmng_GetWave32(void* decoders, CriSint32 index, void* player, CriUint32 channels,
                        void* output, CriUint32 flags, CriUint32* result)
{
    return criMvPlyAdec_GetWave32(((void**)decoders)[index], player, channels, output, flags, result);
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
extern "C" CriSint32 criSjUni_GetRequiredMemorySizeWithConfig(CriUint32 first, CriUint32 second, const CriUint32* settings);

void FUN_1400464a8(CriUint32 first, CriUint32 second);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// test stream readiness after the active decoder state and buffered input are checked.
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
    if (((ReaderState*)object)->State == 1)
        return 0;
    if (criVmpv_GetStatus(object) != 2)
        return 0;
    if ((CriUint32)FUN_1400467b8(((ReaderState*)object)->Queue, 1) <= 0)
        return 0;
    return 1;
}

// determine whether a USF chunk contains payload beyond its declared standard-header extent.
// @0x14003d6c0
extern "C" CriBool FUN_14003d6c0(const void* input)
{
    struct Input { const CriUint8* Data; CriUint32 Size; };
    CriUsfHeaderFields header;
    CriUint32 parsed = criUsfCmn_ParseUsfHeaderStd(((const Input*)input)->Data, ((const Input*)input)->Size,
                                                   (CriUsfStandardHeader*)&header);
    if (!parsed || ((const Input*)input)->Size == header.Size + 8)
        return 0;
    else
        return 1;
}

#pragma function(memset)                      // the exe calls memset here rather than expanding it
// copy the stream-joint setup header into a zeroed 0xb0-byte local work record.
// @0x14003e6a0
void criVmpv_ReleaseAlphaFramePointer(void* target, const CriUint64* settings)
{
    struct SetupRecord { CriUint64 First; CriUint32 Count; CriUint32 Reserved[0x29]; };
    SetupRecord setup;
    memset(&setup, 0, sizeof(setup));
    memcpy(&setup.Count, settings + 1, sizeof(setup.Count));
    setup.First = settings[0];
    criVmpv_ReleaseFramePointer(target, &setup);
}
#pragma intrinsic(memset)

// release the pending synchronization object for each member of the audio decoder list.
// @0x1400427b0
void criMvPlyAmng_Stop(void* decoderList)
{
    struct DecoderList { void* Decoders[2]; CriSint32 Count; };
    for (CriSint32 index = 0; index < ((DecoderList*)decoderList)->Count; ++index)
        mvPlyAdec_StopAudioDecoder(((DecoderList*)decoderList)->Decoders[index]);
}

// notify every decoder in the audio list that its player is active.
// @0x140042880
extern "C" void criMvPlyAmng_TerminateSupply(void* decoderList)
{
    struct DecoderList { void* Decoders[2]; CriSint32 Count; };
    if (!decoderList)
        return;
    for (CriSint32 index = 0; index < ((DecoderList*)decoderList)->Count; ++index)
        mvPlyAdec_TerminateSupplyAudioDecoder(((DecoderList*)decoderList)->Decoders[index]);
}

// release each non-null stream joint owned by the audio track set.
// @0x140043610
void mvPlyAdec_ResetAudioDecoderSj(void* trackSet)
{
    struct TrackSet
    {
        CriUint8 Reserved00[0x18];
        CriUint32 Count;
        CriUint8 Reserved1c[0x14];
        void* Tracks[1];                      // inline array at 0x30, Count entries
    };
    if (!trackSet)
        return;
    for (CriUint32 index = 0; index < ((TrackSet*)trackSet)->Count; ++index)
    {
        void* track = ((TrackSet*)trackSet)->Tracks[index];
        if (track)
            criSj_Reset(track);
    }
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
extern "C" void criUsfDmx_Execute(void* object);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// release the manager's input joint and all child audio decoder track sets.
// @0x140042800
void criMvPlyAmng_ResetAudioSj(void* manager)
{
    struct AudioManager { void* Decoders[2]; CriSint32 Count; void* InputJoint; };
    CriSint32 index;
    void* joint;
    if (!manager)
        return;
    joint = ((AudioManager*)manager)->InputJoint;
    if (joint)
        criSj_Reset(joint);
    for (index = 0; index < ((AudioManager*)manager)->Count; ++index)
        mvPlyAdec_ResetAudioDecoderSj(((AudioManager*)manager)->Decoders[index]);
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void FUN_1400469c4(void* string, const CriChar8* format, ...);
#pragma optimize("", on)

void FUN_1400478a0(void);
void CFT_Ycc420plnToArgb8888Init(void);
void FUN_1400479e0(void);
void criMovieDecoderCore_FourceLinkVersionInfo(void);
namespace CriMv { void FUN_140026f70(void); }  // 0x140026f70, defined in sfr_cri_01
void* criSjUni_CreateByHeap(const void*, void*, CriUint32);
void* criSjRbf_CreateByHeap(const void*, void*, CriUint32);

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

extern "C" void criCs_Destroy(LPCRITICAL_SECTION section);

void criCs_Enter(LPCRITICAL_SECTION section);

void criCs_Leave(LPCRITICAL_SECTION section);

CriUint32 criAtomic_TestAndSet(CriUint32* target, CriUint32 value);

void criAtomic_Initialize();

void criAtomic_Finalize();

CriUint64 FUN_14003a0b4(CriUint64 value, CriUint32 alignment);

CriUint32 FUN_14003a0f8(CriSint32 index);

extern "C" void criUtfRtv_Destroy(CriUint64* table);
#pragma optimize("", on)

// @0x14003b840
void criMvPly_AttachM2V()
{
    FUN_1400478a0();
    DAT_143b27948 = 1;
}

// @0x14003b880
void criMvPly_InitializeFrameARGB8888()
{
    CFT_Ycc420plnToArgb8888Init();
    FUN_1400479e0();
    DAT_143b27c40 = 1;
}

// MS2-FUNCTIONAL: register the MPEG video and alpha decoder interfaces with CriMv.
#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// @0x14003b6e0
void criMvPly_AttachSofdecDecoder()
{
    CriMvCodecRegistrationEntry registration;
    registration.CodecId = 1;
    registration.VideoDecoderInterface = (void*)criVmpv_GetInterface();
    registration.AlphaDecoderInterface = (void*)criVmpv_GetAlphaInterface();
    criMvPly_AttachCodec(&registration);
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void* criUtfRtv_allocByCriHeap(void* heap, CriSint32 size, const CriChar8* name, CriSint32 alignment,
                    CriSint32 allocationMode);

void FUN_14003b2a4(void* heap, void* memory);

void* criUtfRtv_CreateWithHeapType(void* heap, CriSint32 allocationMode, const void* data, CriUint32 size);
#pragma optimize("", on)

// MS2-FUNCTIONAL: allocate the UTF runtime table and field records through its CRI heap callbacks, then let the
// executable's shared UTF parser populate the table layout.
// The exe reports an allocation failure only when this flag (0x143b27c38) is set. Its only writer, the setter at
// 0x14003a0ac, has no callers, so the flag stays 0 and the failures return NULL without an error report.
static CriSint32 s_nUtfRtvReportAllocError = 0;

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void* criUtfRtv_CreateByUtfHeapWithHeapType(void* callbackBlock, CriUint32 allocationMode, const void* data, CriUint32 size);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// retains CRI's conditional decoder attachment followed by common Movie initialization.
// @0x14003bea0
void CriMv::InitializeMana(CriError& error)
{
    if (!IsLibraryInitialized())
    {
        AttachSofdecDecoder(error);
        FUN_140026f70();
    }
    Initialize_Common();
}

// @0x14003bed0
const void** criVmpv_GetInterface()
{
    DAT_143b27c48 = "\ncriVmpv/PCx64 Ver.3.32 Build:Jan 20 2012 18:13:28\n";
    criMovieDecoderCore_FourceLinkVersionInfo();
    const void** table = DAT_143a47bc0;
    return table;
}

// @0x14003bf10
const void** criVmpv_GetAlphaInterface()
{
    const void** table = DAT_143a47cb0;
    return table;
}
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
extern "C" CriUint32 criUtfRtv_ConvFieldNameToNo(const CriUtfRtvView* table, const CriChar8* name);

extern "C" CriUint32 criUtfRtv_GetNumRecord(const CriUtfRtvView* table);

CriUint32 criUtfRtv_SearchFastStrByIndexTable(const CriUtfRtvView* table, CriUint32 slotIndex, const CriChar8* name);
#pragma intrinsic(strcmp)

CriUint8 criUtfRtv_GetDataUint8(const CriUtfRtvView* table, CriUint32 row, CriUint32 field);

CriUint32 criUtfRtv_GetDataUint32(const CriUtfRtvView* table, CriUint32 row, CriUint32 field);

extern "C" CriUint64 criUtfRtv_GetDataUint64(const CriUtfRtvView* table, CriUint32 row, CriUint32 field);

CriFloat32 criUtfRtv_GetDataFloat32(const CriUtfRtvView* table, CriUint32 row, CriUint32 field);

double criUtfRtv_GetDataFloat64(const CriUtfRtvView* table, CriUint32 row, CriUint32 field);

const CriChar8* criUtfRtv_GetDataStr(const CriUtfRtvView* table, CriUint32 row, CriUint32 field);

extern "C" CriUint32 FID_conflict_criUtfRtv_GetDataSint32Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name);

extern "C" CriUint32 criUtfRtv_GetDataSint32Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name);

CriFloat32 criUtfRtv_GetDataFload32Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name);

double criUtfRtv_GetDataFloat64Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name);

const CriChar8* criUtfRtv_GetDataStrFn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name);

CriUint8 criUtfRtv_GetDataUint8Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name);

void criUtfRtv_GetCellValFromAddr(const CriUtfRtvView* table, const CriUint8* address,
                                  CriSint32 type, CriUtfRtvCell* cell);

extern "C" CriBool criUtfRtv_GetCellVal(const CriUtfRtvView* table, CriUint32 row, CriUint32 field, CriUtfRtvCell* cell);

CriUint32 criUtfRtv_GetField(const CriUtfRtvView* table, const CriUint8* field, CriUtfRtvColumn* column);

CriSint32 criUtfRtv_SumWithAlignment32(const CriUtfRtvView* table, CriUint32 firstRow, CriSint32 count,
                                       CriUint32 field, CriSint32 alignment);

CriUint64 FUN_14003adac(const CriUtfRtvView* table, CriUint32 firstRow, CriSint32 count,
                        CriUint32 field, CriSint32 alignment);

CriBool criUsfCmn_GetChunkIdAndSIze(const CriUint8* data, CriUint32 size, CriUint32* id, CriUint32* chunkSize);

extern "C" void* criUtfRtv_Create(void* heap, void* table, CriUint32 size);

extern "C" CriUint32 criUsfCmn_ParseUsfHeaderStd(const CriUint8* data, CriUint32 size, CriUsfStandardHeader* header);

extern "C" const CriUint8* criUsfCmn_GetContents(const CriUint8* data, CriUint32 size, CriSint32* contentSize);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// CRI Movie computes the caller's decoder work size from the requested handle count.
// @0x14003bf30
CriSint32 criVmpv_CalcMovieHandleWork(CriSint32 count)
{
    CriUint32 work;
    work = (CriUint32)((CriUint32)(count * 4 * 0x2000 + 0x2080) / sizeof(CriUint32) * sizeof(CriUint32));
    work += sizeof(CriUint32);
    return work;
}

// install the caller's VMPV work buffer after validating its size and global handle state.
// @0x14003bf80
CriBool criVmpv_SetupMovieHandleWork(CriUint32 count, void* work, CriUint32 workSize)
{
    if (DAT_143b27c68 != 0)
    {
        FUN_140041110(NULL, "E08102801M : SetupMovieHandleWork() was called after handle creation.", DAT_143b27c68);
        return 0;
    }
    if (!work)
    {
        DAT_143b27c6c = 0;
        DAT_143b27c70 = 0;
        return 1;
    }
    CriUint32 required = (CriUint32)criVmpv_CalcMovieHandleWork((CriSint32)count);
    if (required > workSize)
    {
        FUN_140041110(NULL, "E08102802M : SetupMovieHandleWork(): worksize is short.", workSize);
        return 0;
    }
    DAT_143b27c6c = count;
    DAT_143b27c70 = (CriUint64)(uintptr_t)work;
    return 1;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// return the configured movie handle limit or the default limit of sixteen.
// @0x14003c030
CriUint32 criVmpv_GetMaxNumberOfHandles(void)
{
    return DAT_143b27c70 == 0 ? 0x10 : DAT_143b27c6c;
}

// expose the configured movie handle count and work buffer.
// @0x14003c060
void* criVmpv_GetUserLibWork(CriUint32* count)
{
    *count = DAT_143b27c6c;
    return (void*)(uintptr_t)DAT_143b27c70;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// include the configured internal frame pool in the requested count.
// @0x14003c350
extern "C" CriSint32 decideInternalFramePoolNum(CriSint32 count)
{
    return count == 0 ? (CriSint32)DAT_143b27c60 : count - 1 + (CriSint32)DAT_143b27c60;
}

// set the VMPV handle's processor-mask condition on its MPV instance.
// @0x14003c9a0
void criVmpv_SetProcessorMask(void* handle, CriUint32 mask)
{
    struct HandleMpv { CriUint8 Reserved[0x78]; void* Mpv; };
    void* decoder;
    HandleMpv* hn = (HandleMpv*)handle;
    if (handle)
        decoder = hn->Mpv;
    else
        decoder = NULL;
    MPV_SetCond((__int64)decoder, 0xd, (CriSint32)mask);
}

struct CriPostParameter
{
    CriSint32 Horizontal;
    CriSint32 Vertical;
    CriSint32 Magic;
};

// pack up to three horizontal and vertical DLG parameters for the MPV core.
// @0x14003ca00
void criVmpv_SetInitDlgPara(void* context, CriSint32 count, const CriSint32* horizontal,
                   const CriSint32* vertical)
{
    // The exe reads the context's +0x78 field and never uses it.
    void* handle = context;
    void* decoder2;
    CriSint32 i;
    if (context != NULL)
        decoder2 = *(void**)((CriUint8*)handle + 0x78);
    else
        decoder2 = NULL;
    (void)decoder2;
    if (count > 3)
        count = 3;
    CriPostParameter parameters[3];
    for (i = 0; i < count; ++i)
    {
        parameters[i].Horizontal = horizontal[i];
        parameters[i].Vertical = vertical[i];
        parameters[i].Magic = 0x5a5a5a5a;
    }
    MPV_SetDlgPara(count, (__int64)parameters);
}

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

// return the VMPV handle's current status field.
// @0x14003cc70
CriSint32 criVmpv_GetStatus(const void* handle)
{
    const CriVmpvHnFields* hn = (const CriVmpvHnFields*)handle;
    return hn->Status;
}

// create and configure the MPV instance owned by a VMPV handle.
// @0x14003c8d0
extern "C" CriBool createMpvHn(void* handle, void* heap, CriUint32 width, CriUint32 height, CriUint32 frames)
{
    struct VmpvHandle { CriUint8 Reserved00[0x18]; CriSint32 Status; CriUint8 Reserved1C[0x5c]; void* Mpv; };
    // the exe self-assigns its unused parameters (the CRI unused-argument idiom)
    heap = heap;
    width = width;
    height = height;
    frames = frames;
    void* mpv = (void*)MPV_Create();
    ((VmpvHandle*)handle)->Mpv = mpv;
    if (!((VmpvHandle*)handle)->Mpv)
    {
        crivmpv_occurFatalError(0, "E05070103M : Can't create the internal decoder handle (MPV). You may need to increase the maximum number of handle resources.", 0);
        ((VmpvHandle*)handle)->Status = 4;
        return 0;
    }
    MPV_SetCond((__int64)mpv, 6, 3);
    MPV_SetCond((__int64)mpv, 1, 0);
    MPV_SetErrFunc((__int64)mpv, (unsigned __int64)((void*)crivmpv_ErrorFunc), NULL);
    return 1;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// release MPV and stream-memory subsystems when the final initializer reference ends.
// @0x14003c130
void criVmpv_Finalize(void)
{
    --DAT_143b27c68;
    if (DAT_143b27c68 == 0)
    {
        MPV_Finish();
        SJMEM_Finish();
        SJRBF_Finish();
    }
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// size the VMPV frame pool, output records, and its two stream-joint work areas.
// @0x14003c190
CriSint32 FUN_14003c190(CriSint32 width, CriSint32 height, CriSint32 requestedFrames)
{
    // C-style locals at function scope, named so vc9's name-hash slot order matches the exe's
    // (names that share a bucket are declared in reverse slot order)
    CriUint32 settings[2];
    CriUint32 pbuf;
    CriUint32 i;
    CriUint32 num;
    CriSint32 sj2;
    CriSint32 work;
    CriUint32 record;
    CriUint32 size3;
    CriSint32 j1;
    CriSint32 ret;
    CriUint32 bytes;
    CriSint32 head;
    work = 0;
    ret = decideInternalFramePoolNum(requestedFrames);
    num = ret;
    // luma plane (16-aligned width padded to 128, 32-aligned height) plus the two half-size chroma planes
    bytes = ((((CriUint32)width + 0xf) / 0x10 * 0x10 + 0x7f) / 0x80 * 0x80) * (((CriUint32)height + 0x1f) / 0x20 * 0x20) +
            ((((CriUint32)width + 0xf) / 0x10 * 0x10 / 2 + 0x7f) / 0x80 * 0x80) *
                ((((CriUint32)height + 0x1f) / 0x20 * 0x20) / 2) * 2;
    record = 200;
    head = 0x25c;
    work += head;
    settings[0] = 1;
    settings[1] = 1;
    j1 = criSjUni_GetRequiredMemorySizeWithConfig(0, 0x20, settings);
    work += j1;
    size3 = record * num + 4;
    work += size3;
    for (i = 0; i < num; ++i)
    {
        pbuf = bytes + 0x800;
        work += pbuf;
    }
    settings[0] = 1;
    settings[1] = 1;
    sj2 = criSjUni_GetRequiredMemorySizeWithConfig(0, num, settings);
    work += sj2;
    return work;
}

// release the MPV handle, stream joints, frame buffers, and owning VMPV allocation.
// @0x14003cae0
void criVmpv_Destroy(void* handle)
{
    struct FrameRecord { void* Data; CriUint8 Reserved08[0xc0]; };
    struct Handle
    {
        CriUint8 Reserved00[8]; CriSint32 State; CriUint8 Reserved0c[4]; void* Heap; CriSint32 Status;
        CriUint8 Reserved1c[0x20]; CriUint32 FrameCount; CriUint8 Reserved40[8]; FrameRecord* Frames;
        CriUint8 Reserved50[8]; void* FrameJoint; CriUint8 Reserved60[0x18]; void* Mpv;
        CriUint8 Reserved80[0x100]; void* InputJoint; CriUint8 Reserved188[0x98]; void* Decoder;
    };
    typedef void (*ReleaseFunc)(void*);
    // Names chosen so cl 15's name-hash slot order matches the exe's [rsp+N] layout (ties: later = lower slot).
    CriUint32 i;
    void* vmpv;
    Handle* self;
    void* heap;
    self = (Handle*)handle;
    self->State = 0;
    self->Status = 0;
    heap = self->Heap;
    vmpv = self->Mpv;
    if (self->Decoder != NULL)
    {
        ((ReleaseFunc)(*(void***)self->Decoder)[3])(self->Decoder);
        self->Decoder = NULL;
    }
    if (self->FrameJoint != NULL)
    {
        criSj_Destroy(self->FrameJoint);
        self->FrameJoint = NULL;
    }
    if (self->Frames != NULL)
    {
        for (i = 0; i < self->FrameCount; i++)
        {
            if (self->Frames[i].Data != NULL)
                criHeap_Free((CriHeap)heap, self->Frames[i].Data);
        }
        criHeap_Free((CriHeap)heap, self->Frames);
    }
    if (self->InputJoint != NULL)
    {
        criSj_Destroy(self->InputJoint);
        self->InputJoint = NULL;
    }
    if (vmpv != NULL)
        MPV_Destroy((__int64)vmpv);
    criHeap_Free((CriHeap)heap, self);
}

#pragma function(memset)                      // the exe calls memset here rather than expanding it
// drain pending VMPV input, reset frame records, and restore the ready handle state.
// @0x14003cdd0
void criVmpv_StopComplete(void* handle)
{
    struct FrameRecord { void* Data; CriUint8 Reserved08[8]; CriUint8 Info[0xb0]; CriUint8 ReservedC0[8]; };
    struct Handle
    {
        CriUint8 Reserved00[8]; CriSint32 State; CriUint8 Reserved0c[0xc]; CriSint32 Status;
        CriUint8 Reserved1c[0x20]; CriUint32 FrameCount; CriUint8 Reserved40[8]; FrameRecord* Frames;
        CriUint32 RecordBytes; CriUint8 Reserved54[4]; void* FrameJoint; void* FrameHead; CriSint32 FrameQueued;
        CriUint8 Reserved6c[4]; void* Current; CriUint8 Reserved78[0x18]; void* Slot0; CriUint8 Reserved98[0x18];
        void* Slot1; CriUint8 ReservedB8[0x18]; void* Slot2; CriUint8 ReservedD8[0xa8]; void* InputJoint;
        CriSint32 Input0; CriSint32 Input1; CriSint32 Counter[6];
    };
    struct QueueRecord { void* Data; CriUint32 Size; };
    struct Chunk { CriUint64 Data; CriUint64 Size; };
    // Names chosen so cl 15's name-hash slot order matches the exe's [rsp+N] layout (ties: later = lower slot).
    Chunk elem;                              // a chunk pulled off the input joint and handed back to it
    CriUint32 i;
    Handle* self;
    QueueRecord entry;
    self = (Handle*)handle;
    self->State = 0;
    while ((CriUint32)FUN_1400467b8(self->InputJoint, 2) > 0)
    {
        criSj_GetChunk(self->InputJoint, 2, 0xffffffff, &elem);
        criSj_PutChunk(self->InputJoint, 0, &elem);
    }
    if (self->InputJoint != NULL)
        criSj_Reset(self->InputJoint);
    self->Counter[0] = 0;
    self->Counter[1] = 0;
    self->Counter[2] = 0;
    self->Counter[3] = 0;
    self->Counter[4] = 0;
    self->Counter[5] = 0;
    self->Input0 = 0;
    self->Input1 = 0;
    criSj_Reset(self->FrameJoint);
    self->FrameHead = NULL;
    self->FrameQueued = 0;
    for (i = 0; i < self->FrameCount; i++)
    {
        entry.Data = &self->Frames[i];
        entry.Size = self->RecordBytes;
        memset(self->Frames[i].Info, 0, sizeof(self->Frames[i].Info));
        criSj_PutChunk(self->FrameJoint, 0, &entry);
    }
    self->Slot0 = NULL;
    self->Slot1 = NULL;
    self->Slot2 = NULL;
    self->Current = NULL;
    self->State = 1;
    self->Status = 0;
}
#pragma intrinsic(memset)

// advance VMPV input consumption and move the handle through decode and ready states.
// @0x14003cca0
void FUN_14003cca0(void* handle)
{
    struct Fields
    {
        CriUint8 Reserved00[0x18];
        CriSint32 Status;                   // 0x18
        CriSint32 DecodeEnd;                // 0x1c
        CriSint32 FrameReady;               // 0x20
        CriSint32 Opened;                   // 0x24
        CriUint8 Reserved28[0x164];
        CriUint32 Consumed;                 // 0x18c
        CriUint32 Buffered;                 // 0x190
        CriUint8 Reserved194[0x10];
        CriUint32 Additional;               // 0x1a4
    };
    CriSint32 i;
    Fields* hn;
    CriUint32 limit;
    hn = (Fields*)handle;
    if (hn->DecodeEnd == 1)
    {
        if (hn->Opened == 1)
            return;
        criVmpv_StopComplete(hn);
        hn->Status = 0;
        hn->DecodeEnd = 0;
    }
    if (hn->Status == 1 || hn->Status == 2)
        for (i = 0; i < 7; ++i)
            FUN_14003cff0(hn);

    if (hn->Status == 1)
    {
        if ((CriSint32)criVdecCmn_GetNumPictureData(hn) >= 2)
            hn->Status = 2;
        else if (hn->FrameReady == 1)
            hn->Status = 2;
    }
    if (hn->Status == 2 && hn->FrameReady == 1)
    {
        limit = hn->Buffered + hn->Additional;
        if (hn->Consumed <= limit)
            hn->Status = 3;
    }
}

// append a decoded-frame timestamp to the bounded history ring.
// @0x14003d550
extern "C" void FUN_14003d550(void* handle)
{
    struct Entry { CriSint32 Begin, End; };
    struct PlayerTimeline
    {
        CriUint8 Reserved000[0x18c];
        CriSint32 Frame;
        CriUint8 Reserved190[0x20];
        CriSint32 Time;
        Entry Entries[8];
        CriSint32 FinalEnd;
        CriUint8 Reserved1f8[0x40];
        CriSint32 Offset;
    };
    // C-style locals at function scope, named so vc9's name-hash slot order matches the exe's
    CriSint32 i;
    Entry* base;
    CriSint32 slot;
    base = ((PlayerTimeline*)handle)->Entries;
    slot = 0;
    for (i = 0; i < 8; ++i)
    {
        if (base[i].End == 0)
        {
            slot = i;
            break;
        }
    }
    if (i == 8)
    {
        ((PlayerTimeline*)handle)->FinalEnd = base[0].End;
        for (i = 0; i < 8; ++i)
        {
            if (i < 7)
            {
                base[i].Begin = base[i + 1].Begin;
                base[i].End = base[i + 1].End;
            }
            else
            {
                base[i].Begin = 0;
                base[i].End = 0;
            }
        }
        slot = 7;
    }
    base[slot].Begin = ((PlayerTimeline*)handle)->Time;
    if (((PlayerTimeline*)handle)->Offset <= 0)
        base[slot].End = ((PlayerTimeline*)handle)->Frame;
    else
        base[slot].End = ((PlayerTimeline*)handle)->Frame + ((PlayerTimeline*)handle)->Offset;
}

// publish the primary video and alpha output buffers on a movie handle.
// @0x14003d4b0
void FUN_14003d4b0(void* handle, void* videoBuffer, void* alphaBuffer)
{
    struct HandleBuffers { CriUint8 Reserved[0x200]; void* VideoBuffer; void* AlphaBuffer; };
    HandleBuffers* hn = (HandleBuffers*)handle;
    hn->VideoBuffer = videoBuffer;
    hn->AlphaBuffer = alphaBuffer;
}

// publish the secondary video and alpha output buffers on a movie handle.
// @0x14003d500
void FUN_14003d500(void* handle, void* videoBuffer, void* alphaBuffer)
{
    struct HandleBuffers { CriUint8 Reserved[0x210]; void* VideoBuffer; void* AlphaBuffer; };
    HandleBuffers* hn = (HandleBuffers*)handle;
    hn->VideoBuffer = videoBuffer;
    hn->AlphaBuffer = alphaBuffer;
}

// return the frame pointer currently stored in a CRI VMPV handle.
// @0x14003d940
void* FUN_14003d940(void* handle)
{
    void** fields = (void**)handle;
    return fields[0x180 / sizeof(void*)];
}

// mark the VMPV handle's frame-ready flag.
// @0x14003d970
void FUN_14003d970(void* handle)
{
    CriVmpvHnFields* hn = (CriVmpvHnFields*)handle;
    hn->FrameReady = 1;
}

// return the number of picture records held by a video decoder.
// @0x14003d9a0
CriUint32 criVdecCmn_GetNumPictureData(const void* decoder)
{
    const CriUint8* hn = (const CriUint8*)decoder;
    return *(const CriUint32*)(hn + 0x188);
}
#pragma optimize("", on)

int FUN_1400532e0(int);  // C3: the definition's signature

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// size the CRI decoder's rolling output records and per-channel stream buffers.
// @0x140042150
extern "C" CriSint32 criMvPlyAmng_CalcAudioDecoderWorkSize(const void* decoder, const CriUint32* config)
{
    struct Decoder { CriUint8 Reserved00[0xe1c]; CriUint32 Width; };
    // C-style locals at function scope, named so vc9's name-hash slot order matches the exe's
    CriUint32 workSize;
    CriUint32 settings[2];
    CriUint32 i;
    CriSint32 work;
    CriUint32 cnt;
    CriSint32 size;
    CriSint32 total;
    CriUint32 bytes;
    CriSint32 jSize;
    total = 0;
    size = 0x9c;
    total += size;
    work = FUN_1400532e0((CriSint32)config[1]);
    total += work;
    cnt = ((const Decoder*)decoder)->Width * 0xc80 / config[1];
    bytes = config[3] * ((const Decoder*)decoder)->Width + cnt * ((const Decoder*)decoder)->Width;
    workSize = ((const Decoder*)decoder)->Width * 0x840;
    for (i = 0; i < config[1]; ++i)
    {
        settings[0] = 1;
        settings[1] = 1;
        jSize = criSjRbf_GetRequiredMemorySizeWithConfig(bytes, workSize, 4, settings);
        total += jSize;
    }
    return total;
}
#pragma optimize("", on)

// resolve and cache the decoder instance from its media interface and owner state.
// @0x140041910
void* FUN_140041910(void** decoderObject, void** mediaInterface)
{
    // the exe reads the cached instance twice (test, then return), as a volatile read does
    if (((void* volatile*)decoderObject)[2] != NULL)
        return ((void* volatile*)decoderObject)[2];
    // the second argument is the media object itself; the exe calls through its own vtable (0x140041941 rbp = [rdx])
    void** mediaVtable = *(void***)mediaInterface;
    CriUint32 codec = ((CriUint32 (*)(void*))(*(void***)decoderObject)[15])(decoderObject);
    CriUint64 outputInfo;
    CriUint64 output = ((CriUint64 (*)(void*, void*))(*(void***)decoderObject)[5])(decoderObject, &outputInfo);
    CriUint32 channels = ((CriUint32 (*)(void*))(*(void***)decoderObject)[7])(decoderObject);
    CriUint32 format = ((CriUint32 (*)(void*))(*(void***)decoderObject)[4])(decoderObject);
    void* instance = ((void* (*)(void*, CriUint32, CriUint32, CriUint64, CriUint32,
                                  void*, void*))mediaVtable[1])(
        mediaInterface, format, channels, output, codec, decoderObject, NULL);
    ((Scaleform::Render::Image*)decoderObject)->initTexture_NoAddRef((Scaleform::Render::Texture*)instance);
    return instance;
}

// The SDK ImagePlane (only declared here), whose ctor zeroes each field.
struct CriImagePlane
{
    CriUint32 Width, Height;
    CriUint64 Pitch;
    CriUint64 DataSize;
    CriUint8* pData;
    CriImagePlane() : Width(0), Height(0), Pitch(0), DataSize(0), pData(0) {}
};

// clear the output buffers supplied for each available decoder picture plane
// @0x140041390
void FUN_140041390(void* owner, void* outputSet)
{
    (void)owner;
    const Scaleform::Render::ImageData* planes = (const Scaleform::Render::ImageData*)outputSet;
    if (planes->GetPlaneCount() >= 3)
    {
        CriImagePlane luma;
        CriImagePlane chromaU;
        CriImagePlane chromaV;
        CriImagePlane alpha;
        planes->GetPlane(0, (Scaleform::Render::ImagePlane*)&luma);
        planes->GetPlane(1, (Scaleform::Render::ImagePlane*)&chromaU);
        planes->GetPlane(2, (Scaleform::Render::ImagePlane*)&chromaV);
        memset(luma.pData, 0, luma.DataSize);
        memset(chromaU.pData, 0, chromaU.DataSize);
        memset(chromaV.pData, 0, chromaV.DataSize);
        if (planes->GetPlaneCount() >= 4)
        {
            planes->GetPlane(3, (Scaleform::Render::ImagePlane*)&alpha);
            memset(alpha.pData, 0, alpha.DataSize);
        }
    }
    else
    {
        CriImagePlane alpha;
        planes->GetPlane(0, (Scaleform::Render::ImagePlane*)&alpha);
        memset(alpha.pData, 0, alpha.DataSize);
    }
}

// A CRI decoder interface wrapper: the decoder object and its table of entry points.
struct CriDecoderWrapper
{
    void* Object;
    void** Table;
};

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// query the status callback in the alpha decoder interface.
// @0x140043cb0
extern "C" CriSint32 criAlphaDec_GetStatus(void* decoder)
{
    typedef CriSint32 (*Callback)(void*);
    CriSint32 result = 0;
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x30 / 8])
        result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x30 / 8])(((CriDecoderWrapper*)decoder)->Object);
    return result;
}

// execute the alpha decoder when it has an execution callback.
// @0x140043d00
void criAlphaDec_Execute(void* decoder)
{
    typedef void (*Callback)(void*);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x38 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0x38 / 8])(((CriDecoderWrapper*)decoder)->Object);
}

// decode one alpha frame and return the decoder's result.
// @0x140043d40
CriBool criAlphaDec_DecodeFrame(void* decoder)
{
    typedef CriBool (*Callback)(void*);
    CriBool result = 0;
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x40 / 8])
        result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x40 / 8])(((CriDecoderWrapper*)decoder)->Object);
    return result;
}

// request the alpha decoder to skip its current frame.
// @0x140043d90
extern "C" void FUN_140043d90(void* decoder)
{
    typedef void (*Callback)(void*);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x50 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0x50 / 8])(((CriDecoderWrapper*)decoder)->Object);
}

// request the alpha decoder to stop.
// @0x140043dd0
void criAlphaDec_RequestStop(void* decoder)
{
    typedef void (*Callback)(void*);
    if (((CriDecoderWrapper*)decoder)->Table && ((CriDecoderWrapper*)decoder)->Table[0x58 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0x58 / 8])(((CriDecoderWrapper*)decoder)->Object);
}

// run the alpha decoder's completion callback.
// @0x140043e20
extern "C" void criAlphaDec_TerminateSupply(void* decoder)
{
    typedef void (*Callback)(void*);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x60 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0x60 / 8])(((CriDecoderWrapper*)decoder)->Object);
}

// retrieve the alpha decoder's completion state.
// @0x140043e60
extern "C" CriSint32 criAlphaDec_GetNumPictureData(void* decoder)
{
    typedef CriSint32 (*Callback)(void*);
    CriSint32 result = 0;
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x68 / 8])
        result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x68 / 8])(((CriDecoderWrapper*)decoder)->Object);
    return result;
}

// query the number of alpha decoder frame pools.
// @0x140043eb0
extern "C" CriUint32 criAlphaDec_GetNumDecPool(void* decoder)
{
    typedef CriUint32 (*Callback)(void*);
    CriUint32 result = 0;
    if (decoder)
    {
        if (((CriDecoderWrapper*)decoder)->Table[0x70 / 8])
            result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x70 / 8])(((CriDecoderWrapper*)decoder)->Object);
        else
            result = 0;
    }
    return result;
}

// retrieve the next alpha frame metadata record.
// @0x140043f10
void* criAlphaDec_GetNextAlphaFrameInfo(void* decoder, void* frameInfo)
{
    typedef void* (*Callback)(void*, void*);
    void* result = NULL;
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x78 / 8])
        result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x78 / 8])(((CriDecoderWrapper*)decoder)->Object, frameInfo);
    return result;
}

// ask the alpha decoder to copy a frame into the requested output buffers.
// @0x140043f70
CriBool criAlphaDec_CopyAlphaFrameBuffer(void* decoder, void* buffers, void* frameInfo)
{
    typedef CriBool (*Callback)(void*, void*, void*);
    CriBool result = 0;
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x80 / 8])
        result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x80 / 8])(((CriDecoderWrapper*)decoder)->Object, buffers, frameInfo);
    return result;
}

// destroy an alpha decoder, clear its wrapper, and release the wrapper allocation.
// @0x140043be0
extern "C" void criAlphaDec_Destroy(void* decoder)
{
    typedef void (*DestroyCallback)(void*);
    struct DecoderTable { CriUint8 Reserved[0x20]; DestroyCallback Destroy; };
    struct DecoderWrapper { void* Object; DecoderTable* Table; void* Heap; };
    if (decoder && ((DecoderWrapper*)decoder)->Table->Destroy)
    {
        ((DecoderWrapper*)decoder)->Table->Destroy(((DecoderWrapper*)decoder)->Object);
        ((DecoderWrapper*)decoder)->Object = NULL;
        ((DecoderWrapper*)decoder)->Table = NULL;
        criHeap_Free((CriHeap)((DecoderWrapper*)decoder)->Heap, decoder);
    }
}

// retrieve an alpha decoder frame pointer through its callback table.
// @0x140043fe0
extern "C" void* criAlphaDec_GetAlphaFramePointer(void* decoder, void* frameInfo)
{
    typedef void* (*Callback)(void*, void*);
    void* result = NULL;
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x90 / 8])
        result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x90 / 8])(((CriDecoderWrapper*)decoder)->Object, frameInfo);
    return result;
}

// query the video decoder's current status.
// @0x140044630
extern "C" CriSint32 criVdec_GetStatus(void* decoder)
{
    typedef CriSint32 (*Callback)(void*);
    CriSint32 result = 0;
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x30 / 8])
        result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x30 / 8])(((CriDecoderWrapper*)decoder)->Object);
    return result;
}

// decode one frame through the video decoder interface.
// @0x1400446c0
CriBool criVdec_DecodeFrame(void* decoder)
{
    typedef CriBool (*Callback)(void*);
    CriBool result = 0;
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x40 / 8])
        result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x40 / 8])(((CriDecoderWrapper*)decoder)->Object);
    return result;
}

// invoke the video decoder's frame skip callback.
// @0x140044710
extern "C" void FUN_140044710(void* decoder)
{
    typedef void (*Callback)(void*);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x50 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0x50 / 8])(((CriDecoderWrapper*)decoder)->Object);
}

// request the video decoder to stop.
// @0x140044750
void criVdec_RequestStop(void* decoder)
{
    typedef void (*Callback)(void*);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x58 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0x58 / 8])(((CriDecoderWrapper*)decoder)->Object);
}

// invoke the video decoder's completion callback.
// @0x140044790
extern "C" void criVdec_TerminateSupply(void* decoder)
{
    typedef void (*Callback)(void*);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x60 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0x60 / 8])(((CriDecoderWrapper*)decoder)->Object);
}

// query the video decoder's completion state.
// @0x1400447d0
extern "C" CriSint32 criVdec_GetNumPictureData(void* decoder)
{
    typedef CriSint32 (*Callback)(void*);
    CriSint32 result = 0;
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x68 / 8])
        result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x68 / 8])(((CriDecoderWrapper*)decoder)->Object);
    return result;
}

// query the video decoder's frame-pool count.
// @0x140044820
extern "C" CriUint32 criVdec_GetNumDecPool(void* decoder)
{
    typedef CriUint32 (*Callback)(void*);
    CriUint32 result = 0;
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x70 / 8])
        result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x70 / 8])(((CriDecoderWrapper*)decoder)->Object);
    return result;
}

// retrieve the next video frame metadata record.
// @0x140044870
void* criVdec_GetNextFrameInfo(void* decoder, void* frameInfo)
{
    typedef void* (*Callback)(void*, void*);
    void* result = NULL;
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x78 / 8])
        result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x78 / 8])(((CriDecoderWrapper*)decoder)->Object, frameInfo);
    return result;
}

// request a video decoder frame buffer using the supplied format and output data.
// @0x1400448d0
CriBool criVdec_GetFrameBuffer(void* decoder, void* format, CriUint32 mode, void* output)
{
    typedef CriBool (*Callback)(void*, void*, CriUint32, void*);
    CriBool result = 0;
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x80 / 8])
        result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x80 / 8])(((CriDecoderWrapper*)decoder)->Object, format, mode, output);
    return result;
}

// copy video decoder frame planes to the caller's output buffers.
// @0x140044950
CriBool criVdec_CopyFrameYuvBuffers(void* decoder, void* output, void* frameInfo)
{
    typedef CriBool (*Callback)(void*, void*, void*);
    CriBool result = 0;
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x88 / 8])
        result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x88 / 8])(((CriDecoderWrapper*)decoder)->Object, output, frameInfo);
    return result;
}

// retrieve a decoded video frame pointer.
// @0x1400449c0
void* criVdec_GetFramePointer(void* decoder, void* frameInfo)
{
    typedef void* (*Callback)(void*, void*);
    void* result = NULL;
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x90 / 8])
        result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x90 / 8])(((CriDecoderWrapper*)decoder)->Object, frameInfo);
    return result;
}

// release a video decoder frame pointer.
// @0x140044a30
void criVdec_ReleaseFramePointer(void* decoder, void* frameInfo)
{
    typedef void (*Callback)(void*, void*);
    if (!decoder)
        return;
    if (((CriDecoderWrapper*)decoder)->Table && ((CriDecoderWrapper*)decoder)->Table[0x98 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0x98 / 8])(((CriDecoderWrapper*)decoder)->Object, frameInfo);
}

// retrieve the decoder's video parameters.
// @0x140044a90
void criVdec_GetVideoParameter(void* decoder, void* parameters)
{
    typedef void (*Callback)(void*, void*);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0xa0 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0xa0 / 8])(((CriDecoderWrapper*)decoder)->Object, parameters);
}

// ask the decoder to skip its current frame.
// @0x140044ae0
void FUN_140044ae0(void* decoder)
{
    typedef void (*Callback)(void*);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x48 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0x48 / 8])(((CriDecoderWrapper*)decoder)->Object);
}

// query the decoder's concatenated stream offset.
// @0x140044b20
void criVdec_GetOffsetConcatenated(void* decoder, CriUint32 stream, void* offset, void* timestamp)
{
    typedef void (*Callback)(void*, CriUint32, void*, void*);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0xa8 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0xa8 / 8])(((CriDecoderWrapper*)decoder)->Object, stream, offset, timestamp);
}

// retrieve decoder frame-pool metadata through the interface callback.
// @0x140044b90
void criVdec_GetFramePoolInfo(void* decoder, void* a, void* b, void* c, void* d, void* e)
{
    typedef void (*Callback)(void*, void*, void*, void*, void*, void*);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0xb0 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0xb0 / 8])(((CriDecoderWrapper*)decoder)->Object, a, b, c, d, e);
}

// configure the alpha decoder processor mask.
// @0x140044c10
extern "C" void FUN_140044c10(void* decoder, CriUint32 mask)
{
    typedef void (*Callback)(void*, CriUint32);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0xb8 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0xb8 / 8])(((CriDecoderWrapper*)decoder)->Object, mask);
}

// configure the video decoder seek position and mode.
// @0x140044c60
extern "C" void FUN_140044c60(void* decoder, CriUint32 position, CriUint32 mode)
{
    typedef void (*Callback)(void*, CriUint32, CriUint32);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0xc0 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0xc0 / 8])(((CriDecoderWrapper*)decoder)->Object, position, mode);
}

// set the video decoder's notification callback and user data.
// @0x140044cc0
extern "C" void FUN_140044cc0(void* decoder, void* callback, void* userData)
{
    typedef void (*Callback)(void*, void*, void*);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0xc8 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0xc8 / 8])(((CriDecoderWrapper*)decoder)->Object, callback, userData);
}

// configure the video decoder processor mask.
// @0x140044d20
void criVdec_SetProcessorMask(void* decoder, CriUint32 mask)
{
    typedef void (*Callback)(void*, CriUint32);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0xd0 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0xd0 / 8])(((CriDecoderWrapper*)decoder)->Object, mask);
}

// call the decoder interface's initialize entry point.
// @0x140044390
void criVdec_Initialize(const void* decoderInterface)
{
    DAT_143ba9d18 = "\ncriVdec/PCx64 Ver.3.30 Build:Jan 20 2012 18:13:28\n";
    typedef void (*Callback)(void);
    if (decoderInterface && *(Callback const*)decoderInterface)
        (*(Callback const*)decoderInterface)();
}

// call the decoder interface's finalize entry point.
// @0x1400443d0
void criVdec_Finalize(void* decoderInterface)
{
    typedef void (*Callback)(void);
    if (decoderInterface && *(Callback*)((CriUint8*)decoderInterface + 8))
        (*(Callback*)((CriUint8*)decoderInterface + 8))();
}

// set the VDEC DLG parameters through its decoder interface.
// @0x140044d70
void criVdec_SetDlgPara(void* decoder, CriUint32 mode, void* first, void* second)
{
    typedef void (*Callback)(void*, CriUint32, void*, void*);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0xd8 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0xd8 / 8])(((CriDecoderWrapper*)decoder)->Object, mode, first, second);
}

// invoke the decoder's auxiliary callback with its two caller arguments.
// @0x140044de0
extern "C" void FUN_140044de0(void* decoder, void* first, void* second)
{
    typedef void (*Callback)(void*, void*, void*);
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0xe0 / 8])
        ((Callback)((CriDecoderWrapper*)decoder)->Table[0xe0 / 8])(((CriDecoderWrapper*)decoder)->Object, first, second);
}

// retrieve the decoder core interface through the interface table's final slot.
// @0x140044e40
void* criVdec_GetVdecCoreIf(void* decoder)
{
    // unlike its neighbours this slot sits in the interface table itself and takes no object (0x140044e6e)
    typedef void* (*Callback)(void);
    struct DecoderTable { CriUint8 Reserved[0xe8]; Callback Slot; };
    void* result = NULL;
    if (decoder && ((DecoderTable*)decoder)->Slot)
        result = ((DecoderTable*)decoder)->Slot();
    return result;
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
extern "C" void criUsfDmx_SetOutputSj(void* demux, CriUint32 index, void* stream, CriUint32 flags, CriSint32 limit);

extern "C" CriSint32 criSjUni_CalculateWorkSize(const CriSint32* config);

extern "C" CriSint32 criUsfDmx_CalculateWorkSizeWithWork(CriSint32 outputCount);

extern "C" CriSint32 criSjRbf_CalculateWorkSize(const CriSint32* config);

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
    *timestamp = Scaleform::Timer::GetRawFrequency();
    if (timer->Running)
        *elapsed = Scaleform::Timer::GetRawTicks() - timer->Start;
    else
        *elapsed = timer->Stop - timer->Start;
}

// return the current tick delta and timestamp for a CRI timer record.
// @0x140041a10
void FUN_140041a10(const void* state, CriSint64* elapsed, CriUint64* timestamp)
{
    criTimer_GetTime(state, elapsed, timestamp);
}

// toggle the timer record's paused state and accumulate elapsed ticks.
// @0x140041ad0
void FUN_140041ad0(void* state, CriUint8 paused)
{
    struct InnerTimer { CriUint64 Start; CriUint64 Stop; CriUint8 Running; CriUint8 Reserved11[7]; };
    struct TimerState
    {
        CriUint8 Reserved00[0x10];
        InnerTimer Inner;                     // the FUN_140041a10 timer
        CriUint8 Paused;
        CriUint8 Reserved29[7];
        CriSint64 Delta;
        CriUint64 Now;
        CriSint64 Total;
    };
    TimerState* timer = (TimerState*)state;
    if (timer->Paused == paused)
        return;
    CriUint64 now = Scaleform::Timer::GetRawTicks();
    if (paused)
    {
        timer->Inner.Stop = now;
        timer->Inner.Running = 0;
        criTimer_GetTime(&timer->Inner, &timer->Delta, &timer->Now);
        timer->Total += timer->Delta;
    }
    else
    {
        timer->Inner.Start = now;
        timer->Inner.Running = 1;
    }
    timer->Paused = paused;
}

// report the accumulated pause duration or the active timer delta and timestamp.
// @0x140041b50
void FUN_140041b50(void* state, CriSint64* elapsed, CriUint64* timestamp)
{
    struct TimerState
    {
        CriUint8 Reserved00[0x10];
        CriUint8 Inner[0x20];                 // the FUN_140041a10 timer: start, stop, running
        CriSint64 Delta;
        CriUint64 Now;
        CriSint64 Total;
    };
    TimerState* timer = (TimerState*)state;
    if (timer->Inner[0x18])
    {
        *elapsed = timer->Total;
        *timestamp = timer->Now;
        return;
    }
    criTimer_GetTime(timer->Inner, &timer->Delta, &timer->Now);
    *elapsed = timer->Total + timer->Delta;
    *timestamp = timer->Now;
}

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// install the notification callback and its user data on a player manager.
// @0x140041df0
extern "C" void FUN_140041df0(void* manager, void* callback, void* userData)
{
    memcpy((CriUint8*)manager + 0x28, &callback, sizeof(callback));
    memcpy((CriUint8*)manager + 0x30, &userData, sizeof(userData));
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// route a decrypt callback to the selected active audio decoder.
// @0x140041e30
extern "C" void criMvPlyAmng_SetDecryptCallback(void* manager, void* callback, void* userData, CriSint32 stream)
{
    struct AudioDecoder { void* Reserved[2]; void* Decrypt; };
    if (!manager)
        return;
    AudioDecoder* decoder = ((AudioDecoder**)manager)[stream];
    if (!decoder || !decoder->Decrypt)
        return;
    FUN_140054040((__int64)decoder->Decrypt, (unsigned __int64)callback, (unsigned __int64)userData);
}

// store the two frame dimensions on a CRI video handle.
// @0x140041030
void FUN_140041030(void* handle, CriUint32 width, CriUint32 height)
{
    struct HandleSize { CriUint8 Reserved[0x238]; CriUint32 Width; CriUint32 Height; };
    HandleSize* hn = (HandleSize*)handle;
    hn->Width = width;
    hn->Height = height;
}

// publish the two caller-provided buffer pointers on the CRI video handle.
// @0x140041080
void FUN_140041080(void* handle, void* first, void* second)
{
    struct HandleBuffers { CriUint8 Reserved[0x248]; void* First; void* Second; };
    HandleBuffers* hn = (HandleBuffers*)handle;
    hn->First = first;
    hn->Second = second;
}

// mark the CRI handle's error state when a handle is supplied.
// @0x140041150
void FUN_140041150(void* handle, void* unused)
{
    struct HandleState { CriUint8 Reserved[0x18]; CriUint32 State; };
    HandleState* hn = (HandleState*)handle;
    unused = unused;
    if (hn)
        hn->State = 4;
}

// invoke the Initialize entry in the decoder interface table.
// @0x140043a20
void criAlphaDec_Initialize(const void* decoder)
{
    typedef void (*VoidFunction)(void);
    if (decoder && *(VoidFunction*)decoder)
        (*(VoidFunction*)decoder)();
}

// invoke the decoder interface's finalize entry when present.
// @0x140043a50
void criAlphaDec_Finalize(void* decoder)
{
    typedef void (*VoidFunction)(void);
    if (decoder && *(VoidFunction*)((CriUint8*)decoder + 8))
        (*(VoidFunction*)((CriUint8*)decoder + 8))();
}

// query the decoder work size and include the executable's 0x2e-byte wrapper.
// @0x140043a80
extern "C" CriSint32 FUN_140043a80(void* decoder, CriSint32 a, CriSint32 b, CriSint32 c)
{
    typedef CriSint32 (*WorkSizeFunction)(CriSint32, CriSint32, CriSint32);
    struct DecoderTable { CriUint8 Reserved[0x10]; WorkSizeFunction WorkSize; };
    CriSint32 result = 0;
    if (decoder && ((DecoderTable*)decoder)->WorkSize)
    {
        result = ((DecoderTable*)decoder)->WorkSize(a, b, c);
        result = (CriSint32)(result + (CriUint64)0x2e);
    }
    return result;
}

// invoke the alpha decoder interface's frame-info query when available.
// @0x140043c50
extern "C" void* FUN_140043c50(void** decoder)
{
    typedef void* (*Callback)(void*);
    void* result = NULL;
    if (decoder && ((CriDecoderWrapper*)decoder)->Table[0x28 / 8])
        result = ((Callback)((CriDecoderWrapper*)decoder)->Table[0x28 / 8])(((CriDecoderWrapper*)decoder)->Object);
    return result;
}

// copy an RFB frame only while the VMPV handle is not stopped and data is present.
// @0x14003e110
CriBool FUN_14003e110(void* handle, void* output, void** frame)
{
    struct VmpvHandle { CriUint8 Reserved[0x1c]; CriUint32 Stopped; };
    VmpvHandle* vmpv = (VmpvHandle*)handle;
    if (vmpv->Stopped == 1)
        return 0;
    if (!frame || !*frame)
        return 0;
    FUN_14003e850(vmpv, *frame, output);
    return 1;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// clear the two per-frame dimensions stored in a VMPV output record.
// @0x14003e710
void FUN_14003e710(void* unused, void* output)
{
    struct Dimensions { CriUint8 Reserved00[8]; CriUint32 Width; CriUint32 Height; };
    unused = unused;                        // the exe's unused-parameter self-assignment
    ((Dimensions*)output)->Width = 0;
    ((Dimensions*)output)->Height = 0;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// store the current frame rate on the VMPV handle.
// @0x14003e820
void FUN_14003e820(void* handle, CriUint32 frameRate)
{
    CriVmpvHnFields* hn = (CriVmpvHnFields*)handle;
    hn->FrameRate = frameRate;
}

// return the frame timestamp and selected concatenation offset in milliseconds.
// @0x14003e750
void FUN_14003e750(void* handle, CriSint32 frame, CriUint64* timestamp, CriUint64* offset)
{
    struct FrameTime { CriSint32 Frame; CriUint32 Milliseconds; };
    CriSint32 i;
    FrameTime* table;
    CriSint32 slot;
    CriVmpvHnFields* obj;
    obj = (CriVmpvHnFields*)handle;
    table = (FrameTime*)((CriUint8*)obj + 0x1b4);
    slot = 0;
    *timestamp = 0;
    *offset = obj->FrameRate;
    if (frame == 0)
        return;
    for (i = 0; i < 8; i++)
    {
        if (table[i].Frame == frame - 1)
        {
            slot = i;
            break;
        }
    }
    if (i == 8)
        slot = 7;
    *timestamp = (CriUint64)table[slot].Milliseconds * 1000;
}

// MS2-FUNCTIONAL: normalize the movie player's two 64-entry audio-track maps and copy the active entries.
#pragma function(memset)                      // the exe calls memset here rather than expanding it
// @0x14003b720
void FUN_14003b720(CriMvSubAudioTrackState* state, CriSint32 count,
                   const CriSint32* trackIds, const CriSint32* trackValues)
{
    CriSint32 i;
    memset(state->TrackIds, 0, sizeof(state->TrackIds));
    memset(state->TrackValues, 0, sizeof(state->TrackValues));
    if (count > 64)
        count = 64;
    state->TrackCount = count;
    for (i = 0; i < count; ++i)
    {
        state->TrackIds[i] = trackIds[i] != -1 ? trackIds[i] : 0x5a5a5a5a;
        state->TrackValues[i] = trackValues[i] != 0x8000000 ? trackValues[i] : 0x5a5a5a5a;
    }
}
#pragma intrinsic(memset)
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
CriUint32 criUtfRtv_SearchRecNoByUint32(const CriUtfRtvView* table, CriUint32 field, CriUint32 value);

#pragma function(strcmp)                      // the exe calls strcmp here rather than expanding it
CriUint32 criUtfRtv_SearchRecNoByStr(const CriUtfRtvView* table, CriUint32 field, const CriChar8* value);
#pragma intrinsic(strcmp)
#pragma optimize("", on)

// these state initializers clear the decoder's four motion-vector components.
// @0x142ccb4f0
void MPVDEC_ResetMv(CriMpvDecoderState* state)
{
    memset(state->MotionVectors, 0, sizeof(state->MotionVectors));
}

// reset the three MPEG DC predictors to the executable's midpoint value.
// @0x142ccb500
void MPVDEC_ResetDc(CriMpvDecoderState* state)
{
    state->DcPredictors[1] = 0x400;
    state->DcPredictors[2] = 0x400;
    state->DcPredictors[0] = 0x400;
}

// Adjust macroblock address and column by 1 minus the supplied run length. The exe computes 1 - run once per field.
// @0x142ccc580
void mpvumc_SubMbadr(CriMpvDecoderState* state, CriSint32 run)
{
    state->MacroblockAddress += 1 - run;
    state->MacroblockColumn += 1 - run;
    while (state->MacroblockColumn < 0)
    {
        state->MacroblockColumn += state->MacroblockWidth;
        --state->MacroblockRow;
    }
}

// advance the macroblock column, wrapping to the next row at the row width.
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
extern "C" CriSint32 criUsfDmx_GetStatus(void* object);

extern "C" void criUsfDmx_Start(void* object);

extern "C" void criUsfDmx_SetInputSj(void* object, void* value);

extern "C" void criUsfDmx_SetThrououtSwitch(void* object, CriUint8 value);

extern "C" void criUsfDmx_TerminateSupply(void* object);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// forward the opaque argument through the Vdec callback at table offset 0x98.
// @0x140044050
void criAlphaDec_ReleaseAlphaFramePointer(CriUint64* pair, void* value)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0x98))
        (*(void (**)(CriUint64, void*))((CriUint8*)pair[1] + 0x98))(pair[0], value);
}

// call the Vdec callback at table offset 0x88 and add its fixed status bias.
// @0x1400440a0
CriUint32 FUN_1400440a0(CriUint64* pair, void* first, CriUint32 second, void* third)
{
    typedef CriUint32 (*Callback)(CriUint64, void*, CriUint32, void*);
    CriUint32 result = 0;
    if (pair && ((CriDecoderWrapper*)pair)->Table[0x88 / 8])
        result = ((Callback)((CriDecoderWrapper*)pair)->Table[0x88 / 8])(pair[0], first, second, third);
    return result;
}

// invoke the Vdec callback at table offset 0x48 when provided.
// @0x140044120
void FUN_140044120(CriUint64* pair)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0x48))
        (*(void (**)(CriUint64))((CriUint8*)pair[1] + 0x48))(pair[0]);
}

// pass the 32-bit option to the Vdec callback at table offset 0xa0.
// @0x140044160
void FUN_140044160(CriUint64* pair, CriUint32 option)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0xa0))
        (*(void (**)(CriUint64, CriUint32))((CriUint8*)pair[1] + 0xa0))(pair[0], option);
}

// pass both 32-bit options to the Vdec callback at table offset 0xa8.
// @0x1400441b0
extern "C" void FUN_1400441b0(CriUint64* pair, CriUint32 first, CriUint32 second)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0xa8))
        (*(void (**)(CriUint64, CriUint32, CriUint32))((CriUint8*)pair[1] + 0xa8))(pair[0], first, second);
}

// pass the two opaque values to the Vdec callback at table offset 0xb0.
// @0x140044210
extern "C" void FUN_140044210(CriUint64* pair, void* first, void* second)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0xb0))
        (*(void (**)(CriUint64, void*, void*))((CriUint8*)pair[1] + 0xb0))(pair[0], first, second);
}

// pass the 32-bit option to the Vdec callback at table offset 0xb8.
// @0x140044270
void criAlphaDec_SetProcessorMask(CriUint64* pair, CriUint32 option)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0xb8))
        (*(void (**)(CriUint64, CriUint32))((CriUint8*)pair[1] + 0xb8))(pair[0], option);
}

// forward three arguments to the Vdec callback at table offset 0xc0.
// @0x1400442c0
void criAlphaDec_SetDlgPara(CriUint64* pair, CriUint32 option, void* first, void* second)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0xc0))
        (*(void (**)(CriUint64, CriUint32, void*, void*))((CriUint8*)pair[1] + 0xc0))(
            pair[0], option, first, second);
}

// pass the two opaque values to the Vdec callback at table offset 0xc8.
// @0x140044330
extern "C" void FUN_140044330(CriUint64* pair, void* first, void* second)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0xc8))
        (*(void (**)(CriUint64, void*, void*))((CriUint8*)pair[1] + 0xc8))(pair[0], first, second);
}

// call the encoded callback and preserve its 0x3e status adjustment.
// @0x140044400
extern "C" CriSint32 FUN_140044400(void* callbackPair, CriUint32 first, CriUint32 second, CriUint32 third)
{
    typedef CriSint32 (*WorkSizeFunction)(CriUint32, CriUint32, CriUint32);
    struct DecoderTable { CriUint8 Reserved[0x10]; WorkSizeFunction WorkSize; };
    CriSint32 result = 0;
    if (callbackPair && ((DecoderTable*)callbackPair)->WorkSize)
    {
        result = ((DecoderTable*)callbackPair)->WorkSize(first, second, third);
        result = (CriSint32)(result + (CriUint64)0x3e);
    }
    return result;
}

// obtain the value from the Vdec callback at table offset 0x28, defaulting to zero.
// @0x1400445d0
extern "C" CriUint64 FUN_1400445d0(CriUint64* pair)
{
    typedef CriUint64 (*Callback)(CriUint64);
    CriUint64 result = 0;
    if (pair && ((CriDecoderWrapper*)pair)->Table[0x28 / 8])
        result = ((Callback)((CriDecoderWrapper*)pair)->Table[0x28 / 8])(pair[0]);
    return result;
}

// invoke the Vdec callback at table offset 0x38 when provided.
// @0x140044680
void criVdec_Execute(CriUint64* pair)
{
    if (pair && *(void**)((CriUint8*)pair[1] + 0x38))
        (*(void (**)(CriUint64))((CriUint8*)pair[1] + 0x38))(pair[0]);
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void criUsfDmx_Finalize(void);

void FUN_1400459bc(void* object);

void FUN_1400459d4(void* object);

extern "C" void criSj_Reset(void* object);

extern "C" void criSj_Destroy(void* object);

void criSj_SplitChunk(const void* source, CriUint32 maximum, void* prefix, void* suffix);

extern "C" void criSj_PutInputChunk(void* streamJoint, const void* chunk, CriUint32 size);

void criSj_PutOutputChunk(void* streamJoint, const void* chunk, CriUint32 size);

extern "C" void criSj_GetChunk(void* object, CriSint32 operation = 0, CriUint32 limit = 0, void* output = NULL);

extern "C" void criSj_UngetChunk(void* object, CriSint32 operation = 0, void* chunk = NULL);

extern "C" void criSj_PutChunk(void* object, CriSint32 operation = 0, void* chunk = NULL);

extern "C" CriSint32 FUN_1400467b8(void* object, CriSint32 query = 0);

extern "C" void criSj_GetInputChunk(void* object, void* value);

char* FUN_140046944(char* dst, size_t size, const char* src);

char* FUN_14004695c(char* dst, size_t size, const char* src, size_t count);

char* FUN_140046974(char* dst, size_t size, const char* src, size_t count);

char* FUN_14004698c(char* dst, size_t size, const char* src);
#pragma optimize("", on)

void* FUN_1400469f0(void* dst, size_t size, const void* src, size_t count);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// execute the CRI Movie Player manager initialization hook.
// @0x140041ea0
void criMvPlyAmng_Initialize(void)
{
    criAdec_Initialize();
}

// execute the CRI Movie Player manager finalization hook.
// @0x140041ec0
void criMvPlyAmng_Finalize(void)
{
    criAdec_Finalize();
}
#pragma optimize("", on)

// initialize the timer snapshot with the current CRI clock and its live-state flag.
// @0x1400419d0
void FUN_1400419d0(void* snapshot)
{
    *(CriUint64*)snapshot = Scaleform::Timer::GetRawTicks();
    *((CriUint8*)snapshot + 0x10) = 1;
}

// initialize an elapsed-time accumulator with a stopped flag and current clock.
// @0x1400419f0
void FUN_1400419f0(void* timer)
{
    *(CriUint64*)((CriUint8*)timer + 8) = Scaleform::Timer::GetRawTicks();
    *((CriUint8*)timer + 0x10) = 0;
}

// initialize the alternate timer snapshot layout with a running flag.
// @0x140041bd0
void* FUN_140041bd0(void* snapshot)
{
    *(CriUint64*)snapshot = Scaleform::Timer::GetRawTicks();
    *((CriUint8*)snapshot + 0x10) = 1;
    return snapshot;
}

// reset the timer's accumulated duration and capture a fresh stopped-time origin.
// @0x140041aa0
void FUN_140041aa0(void* timer)
{
    *(CriUint64*)((CriUint8*)timer + 0x18) = Scaleform::Timer::GetRawTicks();
    *((CriUint8*)timer + 0x20) = 0;
    *(CriUint64*)((CriUint8*)timer + 0x40) = 0;
}

// forward the requested state to the attached player interface when present.
// @0x1400412e0
void FUN_1400412e0(void* player, CriSint32 state)
{
    void* target = *(void**)((CriUint8*)player + 0x10);
    if (target)
        (*(void (**)(void*, CriUint8))((CriUint8*)*(void**)target + 0x30))(target, state == 1);
}

// forward the supplied output pointer to the attached player's slot-four callback.
// @0x1400412a0
void FUN_1400412a0(void* player)
{
    void* target = *(void**)((CriUint8*)player + 0x10);
    if (target)
        (*(void (**)(void*, void*))((CriUint8*)*(void**)target + 0x20))(target, (CriUint8*)player + 0x18);
}

// report whether the attached player callback returns the active state value.
// @0x140041270
CriBool FUN_140041270(void* player)
{
    void* target = *(void**)((CriUint8*)player + 0x10);
    return target && (*(CriSint32 (**)(void*))((CriUint8*)*(void**)target + 0x18))(target) != 1;
}

// forward the two supplied values to the attached player's slot-one callback.
// @0x140041220
CriBool FUN_140041220(void* player, void*, CriUint32 first, CriUint32 second)
{
    void* target = *(void**)((CriUint8*)player + 0x10);
    return target ? (*(CriUint8 (**)(void*, CriUint32, CriUint32))((CriUint8*)*(void**)target + 8))(target, first, second) : 0;
}

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// return the player's shared work-memory size and default alignment.
// @0x1400411e0
void* criVmpv_GetStaticLibWork(CriUint32* size)
{
    *size = 0x10;
    return DAT_143b27c80;
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// publish CRI Base's runtime banner string.
// @0x1400411f8
void criBaseVersion_ImplantVersionInformation(void)
{
    DAT_143ba9d08 = "\nCRI Base/PCx64 Ver.2.21.07 Build:Jan 13 2012 19:02:07\n";
}
#pragma optimize("", on)

// forward to the attached object's virtual stop operation when present.
// @0x140041250
void FUN_140041250(void* object)
{
    void** target = *(void***)((CriUint8*)object + 0x10);
    if (target)
        ((void (*)(void*))*(void**)((CriUint8*)*target + 0x10))(target);
}

// forward to the attached object's virtual operation at slot five when present.
// @0x1400412c0
void FUN_1400412c0(void* object)
{
    void** target = *(void***)((CriUint8*)object + 0x10);
    if (target)
        ((void (*)(void*))*(void**)((CriUint8*)*target + 0x28))(target);
}

// forward to the attached object's virtual destroy operation when present.
// @0x140041340
void FUN_140041340(void* object)
{
    void** target = *(void***)((CriUint8*)object + 0x10);
    if (target)
        ((void (*)(void*))*(void**)((CriUint8*)*target + 0x40))(target);
}

// invoke the global heap manager's work-size operation.
// @0x140041d20
CriUint64 FUN_140041d20(void)
{
    void* manager = Scaleform::Memory::pGlobalHeap;
    ((void (*)(void*))*(void**)((CriUint8*)*(void**)manager + 0x60))(manager);
    return 0;
}

// release the supplied CRI heap through the global heap manager.
// @0x140041dd0
void FUN_140041dd0(void* heap)
{
    void* manager = Scaleform::Memory::pGlobalHeap;
    ((void (*)(void*, void*))*(void**)((CriUint8*)*(void**)manager + 0x60))(manager, heap);
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void criUsfDmx_Initialize(void);
#pragma optimize("", on)

// initialize the CRI timer context and its default interval/counter fields.
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
    timer->Start = Scaleform::Timer::GetRawTicks();
    timer->Active = 1;
    timer->Mode = 0;
    timer->Current = 0;
    timer->Interval = 1000000;
    timer->Reserved40 = 0;
    return context;
}
// MS2-PIN: ??_7SyncObject@VideoPlayer@Video@GFx@Scaleform@@6B@ 0x1431b4f78
// destroy the global heap manager and optionally free its owning object.
// @0x140041c60
void* FUN_140041c60(void* manager, CriUint32 flags)
{
    static_cast<Scaleform::GFx::Video::VideoPlayer::SyncObject*>(manager)->Scaleform::GFx::Video::VideoPlayer::SyncObject::~SyncObject();
    if (flags & 1)
    {
        void* globalManager = Scaleform::Memory::pGlobalHeap;
        ((void (*)(void*, void*))*(void**)((CriUint8*)*(void**)globalManager + 0x60))(globalManager, manager);
    }
    return manager;
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
CriSint32 criSjUni_GetTotalSize(void* object, CriSint32 lane);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// dispatch the EasyFileReader free operation and release its heap-owned adapter.
// @0x140044560
extern "C" void criVdec_Destroy(CriUint64* adapter)
{
    struct FileAdapterOps { CriUint8 Reserved00[0x20]; void* Free; };
    if (adapter && ((FileAdapterOps*)adapter[1])->Free)
    {
        ((void (*)(CriUint64))((FileAdapterOps*)adapter[1])->Free)(adapter[0]);
        adapter[0] = 0;
        adapter[1] = 0;
        criHeap_Free((CriHeap)adapter[2], adapter);
    }
}

// clear the current Sofdec input state and reset its attached audio decoder.
// @0x140043550
extern "C" void mvPlyAdec_StartAudioDecoder(CriSint32* state, void* input)
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
    ((InputState*)state)->ResetState = 0;
    if (((InputState*)state)->HasState != 0)
    {
        if (!((InputState*)state)->InputControl)
            crimvply_occurFatalError(input, "E05063023M : Don't have input SJ for Audio decoder.", 0);
        FUN_140053540((__int64)(((InputState*)state)->AudioDecoder));
    }
}

// compute the audio player work area from its configured channel count.
// @0x140041ee0
extern "C" CriSint32 criMvPlyAmng_CalcAmngWorkSize(const void* player)
{
    // the local names place the slots as in the exe (vc9 orders /Od locals by a hash of the name)
    struct PlayerConfig { CriUint8 Reserved00[0x4c]; CriUint32 Channels; };
    CriSint32 total = 0;
    CriUint32 settings[2];
    settings[0] = 1;
    settings[1] = 1;
    CriSint32 head = 0x5a;
    total += head;
    CriUint32 size;
    if (((const PlayerConfig*)player)->Channels > 0)
        size = ((const PlayerConfig*)player)->Channels * 0x40;
    else
        size = 0x40;
    CriSint32 jSize = criSjUni_GetRequiredMemorySizeWithConfig(0, size, settings);
    total += jSize;
    return total;
}

// report whether an audio decoder has enough queued samples for the requested operation.
// @0x140043750
CriBool mvPlyAdec_IsReadyAudioPlayback(void* decoder, const void* operation)
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
    if (((TrackState*)decoder)->Present)
    {
        CriSint32 status = (CriSint32)FUN_140053630(((TrackState*)decoder)->AudioDecoder);
        if (status == 0 || status == 1)
            return 0;
        CriUint32 needed = (((TrackState*)decoder)->Threshold / 0x3c) * 8 * (CriUint32)((const Operation*)operation)->Scale;
        CriUint32 available = (CriUint32)FUN_1400467b8(((TrackState*)decoder)->Queue, 1);
        if (available < needed && ((const Operation*)operation)->Active == 0)
            return 0;
    }
    return 1;
}

// release all audio decoder entries and the owning stream joint from a player manager.
// @0x1400420b0
extern "C" void criMvPlyAmng_Destroy(void* manager, void* heap)
{
    struct AudioManager
    {
        void* Decoders[2];
        CriSint32 Count;
        void* InputJoint;
    };
    CriSint32 index;
    void* joint;
    for (index = 0; index < ((AudioManager*)manager)->Count; ++index)
    {
        if (((AudioManager*)manager)->Decoders[index])
            criMvPlyAmng_DestroyAudioDecoder(manager, heap, index);
    }
    joint = ((AudioManager*)manager)->InputJoint;
    if (joint)
    {
        criSj_Destroy(joint);
        ((AudioManager*)manager)->InputJoint = NULL;
    }
    criHeap_Free((CriHeap)heap, manager);
}

// MS2-FUNCTIONAL: create the CRI audio player manager and its channel input stream joint.
#pragma function(memset)                      // the exe calls memset here rather than expanding it
// @0x140041f70
extern "C" void* criMvPlyAmng_Create(void* owner, void* heap, const void* config)
{
    struct AudioManagerObj
    {
        CriUint8 Reserved00[0x18];
        void* InputJoint;
        CriUint32 Rate;
        CriUint8 Reserved24[0x14];
    };
    struct AudioConfig
    {
        CriUint8 Reserved00[0x4c];
        CriUint32 Channels;
    };
    // cl 15 places /Od locals by name hash; these names give the exe's [rsp+N] order.
    AudioManagerObj* p;
    CriUint32 period;
    CriUint32 slots;
    CriUint32 rate;
    p = (AudioManagerObj*)criHeap_AllocFix((CriHeap)heap, 0x38, "CriMvPly: CriMvPlyAmngObj", 4);
    if (p == NULL)
    {
        crimvply_occurUserError(owner, "E07090701M : Can't allocate CriMvPlyAmng handle", 0x38);
        return NULL;
    }
    memset(p, 0, 0x38);
    period = 30;
    rate = 60 / period;
    if (60 % period != 0)
        rate = rate + 1;
    if (rate == 0)
        rate = 1;
    p->Rate = rate;
    if (((const AudioConfig*)config)->Channels > 0)
        slots = ((const AudioConfig*)config)->Channels * 0x40;
    else
        slots = 0x40;
    p->InputJoint = criSj_CreateUniversal(heap, 0, slots);
    if (p->InputJoint == NULL)
    {
        criMvPlyAmng_Destroy(p, heap);
        crimvply_occurFatalError(owner, "E05063016M : Can't create SJ for input audio.", 0);
        return NULL;
    }
    return p;
}
#pragma intrinsic(memset)
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
#pragma function(memset)
extern "C" void criUsfDmx_Stop(void* object);
#pragma intrinsic(memset)
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// detect the encoded CSC flag in a CRI movie packet header.
// @0x140040f80
CriBool retrieveCscFlag(const void* packet, CriSint32 size)
{
    CriSint32 index;
    CriBool result = 0;
    CriUsfSignature signature = DAT_143a482e8;
    const CriChar8* header = (const CriChar8*)packet + 4;
    if (size < 0x18)
        return 0;
    for (index = 0; index < sizeof(signature) - 1; ++index)
    {
        if (header[index] != ((const CriChar8*)&signature)[index])
            return 0;
    }
    if (header[0x13] == 'C') // the CSC flag after the 8-byte signature
        result = 1;
    return result;
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
extern "C" CriSint32 criSjRbf_GetRequiredMemorySizeWithConfig(CriUint32 first, CriUint32 second, CriUint32 third,
                        const CriUint32* settings);

void* criSjWithoutCS_CreateRingBuffer(void* heap, CriUint32 first, CriUint32 second, CriUint32 third);

void* criSjWithoutCS_CreateNamedRingBuffer(void* heap, CriUint32 first, CriUint32 second, CriUint32 third,
                   CriUint64 poolBytes);

CriSint32 criSjWithoutCS_GetRequiredMemorySizeRingBuffer(CriUint32 first, CriUint32 second, CriUint32 third);

void* criSj_CreateRingBuffer(void* heap, CriUint32 first, CriUint32 second, CriUint32 third);

extern "C" void* criSj_CreateNamedRingBuffer(void* heap, CriUint32 first, CriUint32 second, CriUint32 third,
                   CriUint64 poolBytes);

void* criSj_CreateRingBufferWithConfig(void* heap, CriUint32 first, CriUint32 second, CriUint32 third,
                   const CriUint32* settings);

void criSjRbf_PutChunk(void* ring, CriSint32 mode, CriUint64* span);
#pragma optimize("", on)

// create the named CRI video heap and attach its allocator to the returned adapter.
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
    ((Scaleform::MemoryHeap*)heap)->ReleaseOnFree(adapter);
    return adapter;
}

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// map the current CRI movie frame into its segment and update presentation time.
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
    CriSint32 adjusted;
    if (((PlayerTimeline*)player)->FrameAdjustment > 0)
        adjusted = ((PlayerTimeline*)player)->FrameOffset + ((PlayerTimeline*)player)->FrameAdjustment;
    else
        adjusted = ((PlayerTimeline*)player)->FrameOffset;
    ((FrameContext*)context)->Frame = adjusted + ((FrameContext*)context)->FrameAdjustment;
    FUN_140040cc0(player, (CriUint32)((FrameContext*)context)->Frame, &((FrameContext*)context)->SegmentIndex,
                  &((FrameContext*)context)->SegmentDelta);
    ((FrameContext*)context)->PresentationTime =
        (CriUint64)(CriUint32)(adjusted + ((PlayerTimeline*)player)->TimestampBase) * 1000;
}

// locate a frame among eight media segments and return its index and end-relative offset.
// @0x140040cc0
void FUN_140040cc0(void* player, CriUint32 frame, CriSint32* segmentIndex, CriSint32* deltaOut)
{
    struct Entry { CriSint32 Begin, End; };
    struct PlayerTimeline
    {
        CriUint8 Reserved000[0x1b4];
        Entry Entries[8];
        CriSint32 FinalEnd;
    };
    // C-style locals at function scope, named so vc9's name-hash slot order matches the exe's
    CriSint32 i;
    Entry* base;
    CriSint32 start;
    CriSint32 delta;
    base = ((PlayerTimeline*)player)->Entries;
    start = 0;
    delta = -1;
    for (i = 0; i < 8; ++i)
    {
        if (base[i].End == 0)
        {
            if (i == 0)
                start = 0;
            else
                start = base[i - 1].Begin + 1;
            break;
        }
        if (frame < (CriUint32)base[i].End)
        {
            start = base[i].Begin;
            break;
        }
    }
    if (i == 8)
        start = base[7].Begin + 1;
    if (i == 0)
        delta = frame - ((PlayerTimeline*)player)->FinalEnd;
    else
        delta = frame - base[i - 1].End;
    *segmentIndex = start;
    *deltaOut = delta;
}

// execute one audio decoder operation unless its status is already an error.
// @0x1400436d0
void mvPlyAdec_ExecuteHandleAudioServer(void* state)
{
    struct AdecState { CriSint32 Present; CriUint8 Reserved04[0x0c]; void* Decoder; };
    if (!state || !((AdecState*)state)->Present)
        return;
    void* decoder = ((AdecState*)state)->Decoder;
    if (decoder)
    {
        if (FUN_140053630(decoder) == 4)
            crimvply_transitErrorState(0, (void*)"Status of Adec is ERROR.");
        else
        {
            DAT_143ba9d10 = 1;
            criAadx_Execute((__int64)decoder);
            DAT_143ba9d10 = 0;
        }
    }
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
extern "C" void criUsfDmx_Destroy(void* object);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// return a bounded channel's available audio bytes when its decoder is ready.
// @0x140043890
CriUint32 mvPlyAdec_decideOutputSamples(void* track, void* player, CriUint32 channel, CriUint32 maximum)
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
    if (!track)
        return 0;
    if (!((AudioTrack*)track)->Decoder || !((AudioTrack*)track)->Present)
        return 0;
    if (channel > ((AudioTrack*)track)->ChannelCount)
    {
        crimvply_occurUserError(player, "E05063028M : Requested audio channel number is too many.", channel);
        return 0;
    }
    if (((PlayerState*)player)->State == 1)
        return 0;
    CriSint32 status = criMvPly_GetStatus(player);
    if (status != 5 && status != 4)
        return 0;
    CriUint32 available = criMvPlyAdec_GetDataSizeWave(track, player, channel);
    if (maximum < available)
        available = maximum;
    return available;
}

// apply the selected channel's three decoder parameters to its audio decoder.
// @0x140043970
extern "C" void FUN_140043970(void* track, void* player)
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
    CriSint32 index;
    CriUint32 value2;
    CriUint32 value1;
    CriUint32 value3;
    if (!track || !player)
        return;
    if (!((AudioTrack*)track)->Present)
        return;
    index = ((AudioTrack*)track)->Channel;
    value2 = ((PlayerParameters*)player)->Channels[index].Second;
    value1 = ((PlayerParameters*)player)->Channels[index].First;
    value3 = ((PlayerParameters*)player)->Channels[index].Third;
    criAadx_InsertDummyHeader(((AudioTrack*)track)->Decoder, value2, value1, value3);
}

// 0x140042700 FUN_140042700 is in sfr_cri_03d: its exe obj was compiled as C (/TC).
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

// pops a cleared node off the queue's free list (NULL when it is empty); inlined into criSjUni_PutChunk and criSjUni_UngetChunk.
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

void criSjUni_GetChunk(void* object, CriSint32 lane, CriUint32 requested, CriUint64* output);

void criSjUni_PutChunk(void* object, CriSint32 lane, const CriUint64* input);

void criSjUni_UngetChunk(void* object, CriSint32 lane, const CriUint64* input);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
#pragma function(memset)                      // the exe calls memset here rather than expanding it
// Initialize the shared MPV library work buffers once and keep their reference count.
// @0x14003c080
void criVmpv_Initialize(void)
{
    if (DAT_143b27c68 == 0)
    {
        // the 0x18-byte work descriptor at DAT_143b27c50 (size, aligned base, mode, reserved); data_cri keeps the
        // pieces contiguous
        memset(&DAT_143b27c50, 0, 0x18);
        if (DAT_143b27c70 == 0)
        {
            crivmpv_occurFatalError(0, "E10092150M : MPV libwork is not set.", 0);
            return;
        }
        else
        {
            DAT_143b27c50 = DAT_143b27c6c << 2;
            DAT_143b27c58 = (DAT_143b27c70 + 3) & ~(CriUint64)3;
            DAT_143b27c60 = 3;
        }
        SJRBF_Init();
        SJMEM_Init();
        MPV_Init(DAT_143b27c50, DAT_143b27c58);
    }
    DAT_143b27c68 = DAT_143b27c68 + 1;
}
#pragma intrinsic(memset)
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// drain one pending movie ring chunk after its sample count reaches a full block.
// @0x14003ef00
void discardInvalidHoldPool(void* object)
{
    struct Playback { CriUint8 Reserved00[0x10]; void* CurrentData; };
    struct Reader
    {
        CriUint8 Reserved00[0x50];
        CriUint32 BlockSize;
        CriUint32 Reserved54;
        void* Queue;
        CriUint8 Reserved60[0x20];
        Playback Current;
    };
    void** token2;
    CriSint32 samples;
    Playback* playback;
    void* chunk3[2];
    playback = &((Reader*)object)->Current;
    samples = (CriUint32)FUN_1400467b8(((Reader*)object)->Queue, 3) / ((Reader*)object)->BlockSize;
    if (samples > 0)
    {
        criSj_GetChunk(((Reader*)object)->Queue, 3, 0xffffffff, chunk3);
        // keep the chunk whose token (its first field) is the one being played
        if (chunk3[0])
        {
            token2 = (void**)chunk3[0];
            if (playback->CurrentData != *token2)
            {
                criSj_PutChunk(((Reader*)object)->Queue, 0, chunk3);
                return;
            }
        }
        criSj_UngetChunk(((Reader*)object)->Queue, 3, chunk3);
    }
}

// obtain a CRI video descriptor and publish its packed playback fields.
// @0x14003e2a0
void* criVmpv_GetNextAlphaFrameInfo(void* source, void* destination)
{
    struct DescriptorInput
    {
        void* Value;
        CriUint32 Field08, Field0c, Field10, Field14;
        CriUint64 Field18;
        CriUint64 Reserved20[6];
        CriUint32 Field50;
        CriUint32 Reserved54[0x17];   // the callee copies a whole 0xb0-byte decoded frame here (exe local is 0xb0)
    } input;
    struct DescriptorOutput
    {
        void* Value;
        CriUint32 Field08, Field0c, Field10, Field14, Field18, Reserved1c;
        CriUint64 Field20;
        CriUint8 Reserved28[0x20];
        CriUint32 Ready;
    };
    void* found = criVmpv_GetNextFrameInfo(source, &input);
    if (!found)
        return NULL;
    ((DescriptorOutput*)destination)->Field08 = input.Field08;
    ((DescriptorOutput*)destination)->Field20 = input.Field18;
    ((DescriptorOutput*)destination)->Value = input.Value;
    ((DescriptorOutput*)destination)->Field0c = input.Field0c;
    ((DescriptorOutput*)destination)->Field10 = input.Field10;
    ((DescriptorOutput*)destination)->Field14 = input.Field50;
    ((DescriptorOutput*)destination)->Field18 = input.Field14;
    ((DescriptorOutput*)destination)->Ready = 1;
    return ((DescriptorOutput*)destination)->Value;
}

// obtain an alternate CRI video descriptor and publish its packed playback fields.
// @0x14003e5d0
void* criVmpv_GetAlphaFramePointer(void* source, void* destination)
{
    struct DescriptorInput
    {
        void* Value;
        CriUint32 Field08, Field0c, Field10, Field14;
        CriUint64 Field18;
        CriUint64 Reserved20[6];
        CriUint32 Field50;
        CriUint32 Reserved54[0x17];   // the callee copies a whole 0xb0-byte decoded frame here (exe local is 0xb0)
    } input;
    struct DescriptorOutput
    {
        void* Value;
        CriUint32 Field08, Field0c, Field10, Field14, Field18, Reserved1c;
        CriUint64 Field20;
        CriUint8 Reserved28[0x20];
        CriUint32 Ready;
    };
    void* found = criVmpv_GetFramePointer(source, &input);
    if (!found)
        return NULL;
    ((DescriptorOutput*)destination)->Field08 = input.Field08;
    ((DescriptorOutput*)destination)->Field20 = input.Field18;
    ((DescriptorOutput*)destination)->Value = input.Value;
    ((DescriptorOutput*)destination)->Field0c = input.Field0c;
    ((DescriptorOutput*)destination)->Field10 = input.Field10;
    ((DescriptorOutput*)destination)->Field14 = input.Field50;
    ((DescriptorOutput*)destination)->Field18 = input.Field14;
    ((DescriptorOutput*)destination)->Ready = 1;
    return ((DescriptorOutput*)destination)->Value;
}

// release the matching decoded frame from the pending ring and report if none matched.
// @0x14003e180
void criVmpv_ReleaseFramePointer(void* object, const void* frame)
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
    // C-style locals at function scope, named so vc9's name-hash slot order matches the exe's
    Reader* p;
    CriUint64 chk[2];
    CriUint32 i;
    CriUint32 ndec;
    DecodedChunk* cur;
    CriBool released;
    p = (Reader*)object;
    released = 0;
    // count the in-use lane (2), the one GetFrame parks taken frames in
    ndec = (CriUint32)FUN_1400467b8(p->Queue, 2) / p->BlockSize;
    for (i = 0; i < ndec; ++i)
    {
        criSj_GetChunk(p->Queue, 2, -1, chk);
        if (chk[0])
        {
            cur = (DecodedChunk*)chk[0];
            // match the frame's token (its first field), not the address of the caller's frame info
            if (cur->Frame == *(const void* const*)frame)
            {
                criSj_PutChunk(p->Queue, cur->QueueLane, chk);
                released = 1;
                break;
            }
        }
        if (!released)
            criSj_PutChunk(p->Queue, 2, chk);
    }
    if (!released)
        FUN_140041110(0, "E11120202M : Failed criVdec_ReleaseFramePointer().", 0);
}

// destroy one audio decoder track set and clear its player-manager table entry.
// @0x140042600
extern "C" void criMvPlyAmng_DestroyAudioDecoder(void* manager, void* heap, CriSint32 index)
{
    // C-style locals at function scope, named so vc9's name-hash slot order matches the exe's
    struct TrackSet
    {
        CriUint8 Reserved00[0x10];
        void* Decoder;
        CriUint32 ChannelCount;
        CriUint8 Reserved1c[0x14];
        void* Outputs[8];
    };
    CriUint32 i;
    void* output;
    TrackSet* track;
    if (!manager || !heap)
        return;
    track = (TrackSet*)((void**)manager)[index];
    if (!track)
        return;
    if (track->Decoder)
    {
        FUN_140053470((unsigned __int64 *)track->Decoder);
        track->Decoder = NULL;
    }
    for (i = 0; i < track->ChannelCount; ++i)
    {
        output = track->Outputs[i];
        if (output)
        {
            criSj_Destroy(output);
            track->Outputs[i] = NULL;
        }
    }
    criHeap_Free((CriHeap)heap, track);
    ((void**)manager)[index] = NULL;
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
extern "C" void* criUsfDmx_Create(void* heap, CriSint32 outputCount);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// copy the active input descriptor into the stream joint and advance its input count.
// @0x140040a20
void crivmpv_AddDataLineToFramePool(void* player, void** inputDescriptor)
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
    InputDescriptor* descriptor = (InputDescriptor*)*inputDescriptor;
    descriptor->Value = ((PlayerState*)player)->DescriptorValue;
    criSj_PutChunk(((PlayerState*)player)->Joint, 1, inputDescriptor);
    ++((PlayerState*)player)->InputCount;
}

// verify each decoder entry in a CRI track set accepts the supplied operation.
// @0x140042cf0
extern "C" CriBool criMvPlyAmng_IsReadyAudioPlayback(void* trackSet, void* operation)
{
    struct TrackSet { void* Decoders[2]; CriSint32 Count; };
    CriBool ready;
    CriSint32 index;
    if (!trackSet)
        return 1;
    for (index = 0; index < ((TrackSet*)trackSet)->Count; ++index)
    {
        ready = mvPlyAdec_IsReadyAudioPlayback(((TrackSet*)trackSet)->Decoders[index], operation);
        if (!ready)
            return 0;
    }
    return 1;
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void criUsfDmx_GetOutputSjTotalSize(void* stream, CriUint32 lane, CriUint32* first, CriUint32* second,
                   CriUint32* third);

void criSjRbf_UngetChunk(void* joint, CriSint32 lane, void* chunkPtr);
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// create the CRI alpha decoder handle object around a decoder-implementation interface.
// @0x140043af0
extern "C" void* criAlphaDec_Create(void* implementation, void* heap, void* parameter)
{
    void* created;
    void** object_;
    struct Implementation { CriUint8 Reserved00[0x18]; void* (*Create)(void*, void*); };
    object_ = NULL;
    created = NULL;
    if (!((Implementation*)implementation) || !((Implementation*)implementation)->Create)
        return NULL;
    object_ = (void**)criHeap_AllocFix((CriHeap)heap, 0x18, "CriAlphaDec: HnObj", 4);
    if (!object_)
    {
        criErr_NotifyGeneric(0, "E2011030702M", -3);
        return NULL;
    }
    created = ((Implementation*)implementation)->Create(heap, parameter);
    if (!created)
    {
        criHeap_Free((CriHeap)heap, object_);
        return NULL;
    }
    object_[0] = created;
    object_[1] = implementation;
    object_[2] = heap;
    return object_;
}

// create the CRI video decoder handle object around a decoder-implementation interface.
// @0x140044470
extern "C" void* criVdec_Create(void* implementation, void* heap, void* parameter)
{
    void* created;
    void** object_;
    struct Implementation { CriUint8 Reserved00[0x18]; void* (*Create)(void*, void*); };
    object_ = NULL;
    created = NULL;
    if (!((Implementation*)implementation) || !((Implementation*)implementation)->Create)
        return NULL;
    object_ = (void**)criHeap_AllocFix((CriHeap)heap, 0x18, "CriVdec: HnObj", 4);
    if (!object_)
    {
        criErr_NotifyGeneric(0, "E2011030701M", -3);
        return NULL;
    }
    created = ((Implementation*)implementation)->Create(heap, parameter);
    if (!created)
    {
        criHeap_Free((CriHeap)heap, object_);
        return NULL;
    }
    object_[0] = created;
    object_[1] = implementation;
    object_[2] = heap;
    return object_;
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void criusfdmx_discard_zerodata(void* stream);
#pragma optimize("", on)

extern "C" const void* PTR_FUN_143a485d8;
extern "C" const void* PTR_FUN_143a48608;
void FUN_14002e6b0(void*, CriUint32, CriMvWorkAllocator*);
void* FUN_14002e6c0(CriMvWorkAllocator*, CriUint32, CriUint32);
void FUN_14002e6bc(CriMvWorkAllocator*);
void FUN_140038ddc(CriSint32, const CriChar8*);

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
extern "C" void* criSjRbf_Create(const void* config, void* work, CriSint32 workSize);

extern "C" void* criSjUni_Create(const void* config, void* work, CriSint32 workSize);
#pragma optimize("", on)


void FUN_1400314a0(void*);
CriSint32 crivmpv_DecodeOnePictureInPool(void*);

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
// 0x14003ed40 FUN_14003ed40 is in sfr_cri_03d: its exe obj was compiled as C (/TC), so the name is unmangled.
extern "C" CriSint32 FUN_14003ed40(void* player);

// flush the pending reference-picture input of a VMPV player into its stream joint.
// @0x140040a90
void crivmpv_FlushReferencePictureInPool(void* player)
{
    // the picture window block at +0x80, and the 16-byte chunk descriptor the queue functions pass around
    struct PictureWindow
    {
        void* Window;
        void* WindowNext;
        void* WindowEnd;
        CriUint16 Flags;
        CriUint16 FlagsHigh;
        CriUint8 Reserved1c[0x14];
        void* Staged;
    };
    struct ChunkDescriptor { void* Data; CriUint32 Size; };
    // C-style locals at function scope, named so vc9's name-hash slot order matches the exe's
    PictureWindow* window;
    ChunkDescriptor chk;
    ChunkDescriptor picture;
    window = (PictureWindow*)&((CriVideoQueueFields*)player)->Window;
    if (window->Staged != NULL)
    {
        window->FlagsHigh = 0;
        window->Flags = 0;
        window->WindowEnd = window->Staged;
        window->Window = window->WindowEnd;
        window->WindowNext = window->Window;
        ((CriVideoQueueFields*)player)->Cursor = window->WindowEnd;
        window->Staged = NULL;
        picture = *(ChunkDescriptor*)&((CriVideoQueueFields*)player)->Pending;
        if (picture.Data == NULL)
        {
            FUN_140041110(0, "E06100910M : Failed in crivmpv_FlushReferencePictureInPool()", 0);
            ((CriVideoQueueFields*)player)->Status = 4;
            return;
        }
        crivmpv_AddDataLineToFramePool(player, (void**)&picture);
        ((CriVideoQueueFields*)player)->Pending = NULL;
        window->WindowEnd = NULL;
        criSj_GetChunk(((CriVideoQueueFields*)player)->Queue, 3, 0xffffffff, &chk);
        if (chk.Data)
            criSj_PutChunk(((CriVideoQueueFields*)player)->Queue, 0, &chk);
    }
}

// report the per-lane picture queue depths of a VMPV player in whole pictures.
// @0x140040e40
void criVmpv_GetFramePoolInfo(void* player, CriUint32* total, CriUint32* first, CriSint32* second, CriUint32* third,
                   CriUint32* fourth)
{
    CriVideoQueueFields* state = (CriVideoQueueFields*)player;
    *first = 0;
    *second = 0;
    *third = 0;
    *fourth = 0;
    if (!state)
        return;
    if (!state->Queue)
        return;
    *total = state->PictureCount;
    *first = (CriUint32)FUN_1400467b8(state->Queue, 1) / state->UnitSize;
    *second = (CriSint32)((CriUint32)FUN_1400467b8(state->Queue, 3) / state->UnitSize);
    if (state->Pending != NULL)
        *second += 1;
    *third = (CriUint32)FUN_1400467b8(state->Queue, 2) / state->UnitSize;
    *fourth = (CriUint32)FUN_1400467b8(state->Queue, 0) / state->UnitSize;
}

// return the smallest per-channel count of whole audio frames buffered in a sound decoder.
// @0x140043420
CriUint32 criMvPlyAdec_GetDataSizeWave(void* decoder, void* player, CriUint32 channels)
{
    struct Decoder
    {
        CriSint32 Enabled;
        CriUint8 Reserved04[0xc];
        void* Handle;
        CriUint32 ChannelLimit;
        CriUint8 Reserved1c[0x14];
        void* Queues[1];                      // one ring per channel, 8 bytes apart (exe [decoder+channel*8+0x30])
    };
    struct Player { CriUint8 Reserved00[8]; CriSint32 Mode; CriUint8 Reserved0c[0xe10]; CriUint32 FrameSize; };
    // C-style locals at function scope, named so vc9's name-hash slot order matches the exe's
    CriUint32 count;
    CriUint32 channel;
    CriSint32 status;
    CriUint32 result;
    if (decoder == NULL)
        return 0;
    if (((Decoder*)decoder)->Handle == NULL || ((Decoder*)decoder)->Enabled == 0)
        return 0;
    if (channels > ((Decoder*)decoder)->ChannelLimit)
        crimvply_occurUserError(player, "E05063028M : Requested audio channel number is too many", channels);
    if (((Player*)player)->Mode == 1)
        return 0;
    status = criMvPly_GetStatus(player);
    if (status != 5 && status != 4)
        return 0;
    result = (CriUint32)FUN_1400467b8(((Decoder*)decoder)->Queues[0], 1) / ((Player*)player)->FrameSize;
    for (channel = 1; channel < channels; ++channel)
    {
        count = (CriUint32)FUN_1400467b8(((Decoder*)decoder)->Queues[channel], 1) / ((Player*)player)->FrameSize;
        if (count < result)
            result = count;
    }
    return result;
}

// run a video player's decode step once the demuxer has queued data.
// @0x14003ec30
CriSint32 FUN_14003ec30(void* player)
{
    CriVideoQueueFields* self;
    CriSint32 result;
    self = (CriVideoQueueFields*)player;
    result = 0;
    if (self == NULL)
        return 0;
    if (self->Busy == 1)
        return 0;
    if (criVmpv_GetStatus(self) != 2)
        return 0;
    discardInvalidHoldPool(self);
    if ((CriUint32)FUN_1400467b8(self->Queue, 0) <= 0)
        return 0;
    self->Running = 1;
    if (criVdecCmn_GetNumPictureData(self) == 0)
    {
        if (self->Mode == 1 && (CriUint32)FUN_1400467b8(self->InputQueue, 1) <= 0 && self->Decoded < self->Threshold)
            crivmpv_FlushReferencePictureInPool(self);
    }
    else
    {
        FUN_14003ed40(self);
        result = crivmpv_DecodeOnePictureInPool(self);
    }
    self->Running = 0;
    return result;
}
#pragma optimize("", on)

// ask the owner to stop when the playback clock has run ahead of the nominal frame rate (the state is read again
// after the null test, as the exe does)
// @0x1400414f0
void FUN_1400414f0(void* handle)
{
    struct Owner { CriUint8 Reserved00[8]; CriMvEasyPlayer* Player; CriUint8 Reserved10[0x2d0]; CriUint32 FrameRate;
                   CriUint32 Reserved2e4; CriUint64 FramesDone; CriUint64 FramesUnit; };
    struct Handle { CriUint8 Reserved00[0x40]; Owner* State; };
    if (!((Handle*)handle)->State)
        return;
    Owner* state = *(Owner* volatile*)&((Handle*)handle)->State;
    CriMvEasyPlayer* owner = state->Player;
    CriUint64 count;
    CriUint64 unit;
    owner->GetTime(count, unit);
    if ((float)count / (float)unit * 1000.0f - (float)state->FramesDone / (float)state->FramesUnit * 1000.0f
        > 1000.0f / ((float)state->FrameRate / 1000.0f))
    {
        struct EasyFields { CriUint8 Reserved00[8]; void* Inner; };
        FUN_1400314a0(((EasyFields*)owner)->Inner);
    }
}

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: reset a VMPV player's counters and return every picture record to its free queue.
#pragma function(memset)                      // the exe calls memset here rather than expanding it
// @0x14003d720
void criVmpv_Start(void* player)
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
    // C-style locals at function scope, named so vc9's name-hash slot order matches the exe's
    CriUint32 index;
    Player* self;
    Record entry;
    self = (Player*)player;
    self->Counter190 = 0;
    self->Counter194 = 0;
    self->Counter198 = 0;
    self->Counter19c = 0;
    self->Counter1a0 = 0;
    self->Counter1a4 = 0;
    self->Status = 1;
    self->Mode = 0;
    self->Busy = 0;
    self->Running = 0;
    self->PictureCount = 0;
    self->Counter240 = 0;
    criSj_Reset(self->Queue);
    self->Pending = NULL;
    self->PendingSize = 0;
    for (index = 0; index < self->RecordCount; ++index)
    {
        entry.Data = self->Records + (CriUint64)index * 200;
        entry.Size = self->UnitSize;
        memset(self->Records + (CriUint64)index * 200 + 0x10, 0, 0xb0);
        criSj_PutChunk(self->Queue, 0, &entry);
    }
    self->WindowEnd = NULL;
    self->Staged = NULL;
    self->Reserved0d0 = NULL;
    self->Cursor = NULL;
    self->Counter1a8 = 0;
    self->Counter1ac = 0;
}
#pragma intrinsic(memset)
#pragma optimize("", on)

// selects the ARGB converter below; the exe loads it into eax before the compare, as a volatile read does
extern "C" volatile CriUint32 DAT_143b27c3c;
void FUN_140049300(__int64, __int64, __int64 *);  // C3: the definition's signature
void FUN_14004c0c0(__int64, __int64, unsigned __int64 *);  // C3: the definition's signature
void FUN_14004cbb0(Unk_Frame *, Unk_Surface *, unsigned char **);  // C3: the definition's signature
void crimvply_clearFrameInfoMembers(void*);
extern "C" CriBool crimvply_isUnderGetFrameCondition(void* player);
extern "C" void crimvply_clearAlphaFrameInfoMembers(void* info);
extern "C" CriUint32 FUN_1400358d0(void*, const void*);
extern "C" void crimvply_updateMvPlyYuvBuffersFromAlphadecInfo(void* player, const CriMvAlphaDecoderFrameInfo* info);
extern "C" void crimvply_makeFrameInfoMembers(void*, void*, const void*, CriUint64, CriUint32);
extern "C" void crimvply_makeAlphaFrameInfoMembers(void*, void*, const void*);
CriBool criMvPly_CopyFrameARGB8888Buffer(void*, CriUint8*, CriUint32, CriUint32, const void*, const void*, const void*);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// convert YUV (and optional alpha) planes into the caller's 32-bit ARGB buffer
// @0x14003bb60
CriBool criMvPly_CopyFrameARGB8888Buffer(void* player, CriUint8* dstbuf, CriUint32 dstpitch, CriUint32 dstbufsize,
                                         const void* srcbufs, const void* src_vinf, const void* src_ainf)
{
    struct PlaneRef { CriUint8* Data; CriUint32 Reserved08; CriUint32 Pitch; };
    struct YuvBuffers { PlaneRef Planes[3]; };
    struct AlphaInfo { CriUint8* Data; CriUint32 Reserved08; CriUint32 Width; CriUint32 Height; CriUint32 Reserved14;
                       CriUint32 Reserved18; CriUint32 Pitch; };
    struct VideoInfo { CriUint8 Reserved00[0xc]; CriUint32 Width; CriUint32 Height; };
    struct PlaneDesc { CriUint8* Data; CriUint32 Width; CriUint32 Height; CriUint32 Pitch; CriUint32 Reserved; };
    struct SourceDesc { CriUint32 Count; CriUint32 Reserved; PlaneDesc Planes[6]; };
    struct PlayerSize { CriUint8 Reserved00[0x614]; CriUint32 Width; CriUint32 Height; };
    // locals named so vc9's name-hash slot order matches the exe's; none of them is cleared
    SourceDesc dest;
    CriUint64 options[6];
    SourceDesc source;
    if (dstbufsize == dstbufsize) {}
    if (DAT_143b27c40 != 1)
        crimvply_occurUserError(NULL, "E10110401M : Please call initialization function for 32bit ARGB frame output.", 0);
    if (!((const YuvBuffers*)srcbufs) || !((const AlphaInfo*)src_ainf) || !((const AlphaInfo*)src_ainf) || !dstbuf)
    {
        crimvply_occurFatalError(0, "E10060100M : NULL pointer is passed into criMvPly_CopyFrameARGB8888Buffer().", 0);
        return 0;
    }
    if (((const AlphaInfo*)src_ainf)->Data != NULL && (((const VideoInfo*)src_vinf)->Width != ((const AlphaInfo*)src_ainf)->Width || ((const VideoInfo*)src_vinf)->Height != ((const AlphaInfo*)src_ainf)->Height))
    {
        crimvply_occurUserError(NULL, "E11012101M : The resolutions of alpha stream and video stream should be same in the frame format. Use YUV buffers format.", 0);
        return 0;
    }
    source.Count = 3;
    source.Planes[0].Data = ((const YuvBuffers*)srcbufs)->Planes[0].Data;
    source.Planes[0].Width = ((const PlayerSize*)player)->Width;
    source.Planes[0].Height = ((const PlayerSize*)player)->Height;
    source.Planes[0].Pitch = ((const YuvBuffers*)srcbufs)->Planes[0].Pitch;
    source.Planes[1].Data = ((const YuvBuffers*)srcbufs)->Planes[1].Data;
    source.Planes[1].Width = (((const PlayerSize*)player)->Width + 1) / 2;
    source.Planes[1].Height = (((const PlayerSize*)player)->Height + 1) / 2;
    source.Planes[1].Pitch = ((const YuvBuffers*)srcbufs)->Planes[1].Pitch;
    source.Planes[2].Data = ((const YuvBuffers*)srcbufs)->Planes[2].Data;
    source.Planes[2].Width = (((const PlayerSize*)player)->Width + 1) / 2;
    source.Planes[2].Height = (((const PlayerSize*)player)->Height + 1) / 2;
    source.Planes[2].Pitch = ((const YuvBuffers*)srcbufs)->Planes[2].Pitch;
    source.Planes[3].Data = ((const AlphaInfo*)src_ainf)->Data;
    source.Planes[3].Width = ((const AlphaInfo*)src_ainf)->Width;
    source.Planes[3].Height = ((const AlphaInfo*)src_ainf)->Height;
    source.Planes[3].Pitch = ((const AlphaInfo*)src_ainf)->Pitch;
    dest.Count = 1;
    dest.Planes[0].Data = dstbuf;
    dest.Planes[0].Width = ((const VideoInfo*)src_vinf)->Width;
    dest.Planes[0].Height = ((const VideoInfo*)src_vinf)->Height;
    dest.Planes[0].Pitch = dstpitch;
    options[0] = 0;
    if (DAT_143b27c3c == 1)
        FUN_140049300((__int64)&source, (__int64)&dest, (__int64 *)options);
    else
        FUN_14004c0c0((__int64)&source, (__int64)&dest, options);
    if (source.Planes[3].Data != NULL)
    {
        source.Planes[0].Data = source.Planes[3].Data;
        source.Planes[0].Width = source.Planes[3].Width;
        source.Planes[0].Height = source.Planes[3].Height;
        options[0] = 0;
        FUN_14004cbb0((Unk_Frame *)&source, (Unk_Surface *)&dest, (unsigned char **)options);
    }
    return 1;
}
#pragma optimize("", on)

CriBool criMvPly_GetFrameARGB8888(void*, CriUint8*, CriUint32, CriUint32, void*);

#pragma function(memset)
#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Fetch the next decoded frame (and alpha frame) and convert it into a 32-bit ARGB buffer.
// @0x14003b8b0
CriBool criMvPly_GetFrameARGB8888(void* player, CriUint8* imagebuf, CriUint32 pitch, CriUint32 bufsize, void* frameinfo)
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
    // Names chosen so cl 15's name-hash slot order matches the exe's [rsp+N] layout.
    void* pFrame;                            // the frame pointer each Get returns
    CriUint64 alphaAttr[7];                  // alpha conversion info (FUN_1400351c0)
    CriUint64 yuv[8];                        // YUV source buffers for criMvPly_CopyFrameARGB8888Buffer
    CriMvFrameInfo picture;                  // the decoded video frame
    CriBool rv;
    CriMvFrameInfo convFrame;
    CriUint64 ainf[10];                      // the decoded alpha frame
    rv = 0;
    if (bufsize == bufsize) {}
    crimvply_clearFrameInfoMembers((FrameInfo*)frameinfo);
    if (!crimvply_isUnderGetFrameCondition(player))
        return 0;
    if (bufsize < ((FrameInfo*)frameinfo)->Width * 4 * ((FrameInfo*)frameinfo)->Height)
    {
        crimvply_occurUserError(player, "E09012805M : ARGB buffer is too small.", 0);
        return rv;
    }
    crimvply_clearAlphaFrameInfoMembers(alphaAttr);
    memset(ainf, 0, sizeof(ainf));
    pFrame = criVdec_GetFramePointer(((Player*)player)->VideoDecoder, &picture);
    if (pFrame == NULL)
    {
        crimvply_occurFatalError(0, "E10060101M : Cannot get the pointer to video frame buffer.", 0);
        return 0;
    }
    if (((Player*)player)->AlphaDecoder != NULL)
    {
        pFrame = criAlphaDec_GetAlphaFramePointer(((Player*)player)->AlphaDecoder, ainf);
        if (pFrame == NULL)
        {
            crimvply_occurFatalError(0, "E08082502M : Cannot get the pointer to alpha frame buffer.", 0);
            return 0;
        }
    }
    crimvply_makeFrameInfoMembers(player, &convFrame, &picture, (CriUint64)(uintptr_t)picture.imageptr, picture.width);
    crimvply_makeAlphaFrameInfoMembers(player, alphaAttr, ainf);
    FUN_1400358d0(yuv, &picture);
    crimvply_updateMvPlyYuvBuffersFromAlphadecInfo(yuv, (const CriMvAlphaDecoderFrameInfo*)ainf);
    criMvPly_CopyFrameARGB8888Buffer(player, imagebuf, pitch, bufsize, yuv, &convFrame, alphaAttr);
    ((Player*)player)->FrameId = *(CriUint32*)((CriUint8*)&picture + 0xa8);
    if (((Player*)player)->AlphaDecoder != NULL)
        criAlphaDec_ReleaseAlphaFramePointer((CriUint64*)((Player*)player)->AlphaDecoder, ainf);
    criVdec_ReleaseFramePointer(((Player*)player)->VideoDecoder, &picture);
    crimvply_makeFrameInfoMembers(player, frameinfo, &picture, (CriUint64)(uintptr_t)imagebuf, pitch);
    // The exe returns rv, which is still 0 here; its only caller (GetFrameOnTimeAs32bitARGB via 0x1400418a0)
    // discards the result.
    return rv;
}
#pragma optimize("", on)
#pragma intrinsic(memset)

extern "C" CriUint32 DAT_143b27c78;

namespace
{
// 0xb0-byte decoded-frame description copied out of a queue record; the plane table starts at +0x38.
struct CriDecodedPlane { CriUint8* Data; CriUint32 Width; CriUint32 Height; CriUint32 Pitch; CriUint32 Reserved; };
struct CriDecodedFrame
{
    CriUint8* Base;
    CriUint32 Reserved08;                     // reserves are word-typed: the exe's frame local has no /GS cookie
    CriUint32 Width;
    CriUint32 Height;
    CriUint32 Reserved14[9];
    CriUint32 PlaneCount;
    CriUint32 Reserved3c;
    CriDecodedPlane Planes[3];
    CriUint64 Reserved88[5];
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
}

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Peek the next decoded picture of a VMPV player and describe its tiled YUV420 planes. record->Frame is assigned
// straight to the output (one /Od temp at [rsp+0x68]), not through a named local.
// @0x14003da40
void* criVmpv_GetNextFrameInfo(void* player, void* output)
{
    // C-style function-scope locals; the names give cl 15's name-hash slot order the exe has
    // (names that share a bucket are declared in reverse slot order)
    CriFrameRecord* queueRecord;
    CriUint32 width;
    CriUint32 height;
    CriVideoFrameSource* self = (CriVideoFrameSource*)player;
    CriSint16 pitch2[2];                    // [0] chroma pitch, [1] luma pitch
    CriUint8* base;
    CriUint8* crPlane;
    CriUint8* pCb;
    struct { CriFrameRecord* Record; CriUint64 Size; } it;
    if (FUN_140040de0(self) == 0)
        return NULL;
    criSj_GetChunk(self->Queue, 1, 0xffffffff, &it);
    if (it.Record == NULL)
        return NULL;
    queueRecord = it.Record;
    *(CriDecodedFrame*)output = queueRecord->Frame;
    FUN_140040c00(self, (CriDecodedFrame*)output);
    width = ((CriDecodedFrame*)output)->Width;
    height = ((CriDecodedFrame*)output)->Height;
    pitch2[1] = (CriSint16)(((width + 0xf) / 0x10 * 0x10 + 0x7f) / 0x80 * 0x80);
    pitch2[0] = (CriSint16)(((width + 0xf) / 0x10 * 0x10 / 2 + 0x7f) / 0x80 * 0x80);
    base = ((CriDecodedFrame*)output)->Base;
    pCb = base + ((width + 0xf) / 0x10 * 0x10 + 0x7f) / 0x80 * 0x80 * ((height + 0x1f) / 0x20 * 0x20);
    crPlane = pCb + ((width + 0xf) / 0x10 * 0x10 / 2 + 0x7f) / 0x80 * 0x80 * ((height + 0x1f) / 0x20 * 0x20 / 2);
    ((CriDecodedFrame*)output)->PlaneCount = 3;
    ((CriDecodedFrame*)output)->Planes[0].Data = base;
    ((CriDecodedFrame*)output)->Planes[0].Width = width;
    ((CriDecodedFrame*)output)->Planes[0].Height = height;
    ((CriDecodedFrame*)output)->Planes[0].Pitch = pitch2[1];
    ((CriDecodedFrame*)output)->Planes[1].Data = pCb;
    ((CriDecodedFrame*)output)->Planes[1].Width = width / 2;
    ((CriDecodedFrame*)output)->Planes[1].Height = height / 2;
    ((CriDecodedFrame*)output)->Planes[1].Pitch = pitch2[0];
    ((CriDecodedFrame*)output)->Planes[2].Data = crPlane;
    ((CriDecodedFrame*)output)->Planes[2].Width = width / 2;
    ((CriDecodedFrame*)output)->Planes[2].Height = height / 2;
    ((CriDecodedFrame*)output)->Planes[2].Pitch = pitch2[0];
    criSj_UngetChunk(self->Queue, 1, &it);
    return base;
}

// Take the next decoded picture of a VMPV player, describe its planes and mark it consumed.
// @0x14003dd50
void* criVmpv_GetFramePointer(void* player, void* output)
{
    // C-style function-scope locals named for cl 15's name-hash slot order, as in criVmpv_GetNextFrameInfo
    struct CriWindowRef { CriUint8 Reserved00[0x10]; void* Window; };
    CriFrameRecord* queueRecord;
    CriUint32 width;
    CriUint32 height;
    CriVideoFrameSource* self = (CriVideoFrameSource*)player;
    CriSint16 pitch2[2];                    // [0] chroma pitch, [1] luma pitch
    CriUint8* base;
    CriUint8* crPlane;
    CriUint8* pCb;
    CriWindowRef* desc;
    struct { CriFrameRecord* Record; CriUint64 Size; } it;
    if (FUN_140040de0(self) == 0)
        return NULL;
    if (DAT_143b27c78 == 1 && (CriUint32)FUN_1400467b8(self->Queue, 2) > 0)
        return NULL;
    criSj_GetChunk(self->Queue, 1, 0xffffffff, &it);
    if (it.Record == NULL)
        return NULL;
    queueRecord = it.Record;
    *(CriDecodedFrame*)output = queueRecord->Frame;
    FUN_140040c00(self, (CriDecodedFrame*)output);
    width = ((CriDecodedFrame*)output)->Width;
    height = ((CriDecodedFrame*)output)->Height;
    pitch2[1] = (CriSint16)(((width + 0xf) / 0x10 * 0x10 + 0x7f) / 0x80 * 0x80);
    pitch2[0] = (CriSint16)(((width + 0xf) / 0x10 * 0x10 / 2 + 0x7f) / 0x80 * 0x80);
    base = ((CriDecodedFrame*)output)->Base;
    pCb = base + ((width + 0xf) / 0x10 * 0x10 + 0x7f) / 0x80 * 0x80 * ((height + 0x1f) / 0x20 * 0x20);
    crPlane = pCb + ((width + 0xf) / 0x10 * 0x10 / 2 + 0x7f) / 0x80 * 0x80 * ((height + 0x1f) / 0x20 * 0x20 / 2);
    ((CriDecodedFrame*)output)->PlaneCount = 3;
    ((CriDecodedFrame*)output)->Planes[0].Data = base;
    ((CriDecodedFrame*)output)->Planes[0].Width = width;
    ((CriDecodedFrame*)output)->Planes[0].Height = height;
    ((CriDecodedFrame*)output)->Planes[0].Pitch = pitch2[1];
    ((CriDecodedFrame*)output)->Planes[1].Data = pCb;
    ((CriDecodedFrame*)output)->Planes[1].Width = width / 2;
    ((CriDecodedFrame*)output)->Planes[1].Height = height / 2;
    ((CriDecodedFrame*)output)->Planes[1].Pitch = pitch2[0];
    ((CriDecodedFrame*)output)->Planes[2].Data = crPlane;
    ((CriDecodedFrame*)output)->Planes[2].Width = width / 2;
    ((CriDecodedFrame*)output)->Planes[2].Height = height / 2;
    ((CriDecodedFrame*)output)->Planes[2].Pitch = pitch2[0];
    self->Position += 1;
    criSj_PutChunk(self->Queue, 2, &it);
    desc = (CriWindowRef*)((CriUint8*)self + 0x80);
    if (desc->Window == (void*)queueRecord->Key)
    {
        if (self->ChannelCount <= 2)
            queueRecord->Mode = 0;
        else
            queueRecord->Mode = 3;
    }
    else
        queueRecord->Mode = 0;
    return ((CriDecodedFrame*)output)->Base;
}

#pragma function(memcpy)                      // the exe calls memcpy here rather than expanding it
// Copy one tiled luma plane row by row into a caller buffer with its own pitch. The two pitches share one 8-byte
// struct local, as in the exe (separate CriSint16 locals are each 4-aligned; a CriSint16[2] moves widthL into 0x5c).
// @0x14003e370
CriBool FUN_14003e370(void* player, void* destination, void* source)
{
    struct Player { CriUint8 Reserved00[0x1c]; CriSint32 Busy; CriUint8 Reserved20[0xd8]; CriSint32 Width; CriSint32 Height; };
    struct Destination { CriUint8* Data; CriUint32 RowBytes; CriUint32 Rows; CriUint32 Pitch; };
    struct Source { const CriUint8* Data; };
    static_assert(offsetof(Player, Width) == 0xf8 && offsetof(Player, Height) == 0xfc, "layout");
    // Names chosen so cl 15's name-hash slot order matches the exe's [rsp+N] layout (ties: later = lower slot).
    Player* p;
    CriUint8* dstp;
    CriUint32 rowsLeft;
    CriUint32 i;
    CriUint32 lineLen;
    const CriUint8* pU;                      // chroma plane pointers: computed, never read (as in the exe)
    const CriUint8* planeV;
    const CriUint8* lumaRow;
    struct { CriSint16 Chroma; CriSint16 Luma; CriUint32 Unused; } srcPitch;   // the exe's 8-byte pitch slot: 0x58/0x5a, 0x5c unused
    CriSint32 nHeight;
    CriUint32 numRows;
    CriUint32 rowLimit;
    const CriUint8* srcLine;
    CriSint32 widthL;
    p = (Player*)player;
    if (p->Busy == 1)
        return 0;
    if (((Source*)source) == NULL || ((Source*)source)->Data == NULL)
        return 0;
    widthL = p->Width;
    nHeight = p->Height;
    srcPitch.Luma = (CriSint16)((((widthL + 0xf) / 0x10) * 0x10 + 0x7f) / 0x80 * 0x80);
    srcPitch.Chroma = (CriSint16)((((widthL + 0xf) / 0x10) * 0x10 / 2 + 0x7f) / 0x80 * 0x80);
    lumaRow = ((Source*)source)->Data;
    pU = lumaRow + (((widthL + 0xf) / 0x10) * 0x10 + 0x7f) / 0x80 * 0x80 * (((nHeight + 0x1f) / 0x20) * 0x20);
    planeV = pU + (((widthL + 0xf) / 0x10) * 0x10 / 2 + 0x7f) / 0x80 * 0x80 * (((nHeight + 0x1f) / 0x20) * 0x20 / 2);
    rowLimit = ((Destination*)destination)->RowBytes;
    numRows = ((Destination*)destination)->Rows;
    rowsLeft = numRows;
    lineLen = srcPitch.Luma;
    if (lineLen > rowLimit)
        lineLen = rowLimit;
    srcLine = lumaRow;
    dstp = ((Destination*)destination)->Data;
    for (i = 0; i < rowsLeft; i++)
    {
        memcpy(dstp, srcLine, lineLen);
        srcLine = srcLine + srcPitch.Luma;
        dstp = dstp + ((Destination*)destination)->Pitch;
    }
    return 1;
}
#pragma intrinsic(memcpy)

#pragma function(memcpy)                      // the exe calls memcpy here rather than expanding it
// Copy the three tiled YUV420 planes of a decoded picture into caller planes with their own pitches. The two pitches
// share one 8-byte struct local (0x58/0x5a, 0x5c unused), as in FUN_14003e370.
// @0x14003e850
void FUN_14003e850(void* player, void* source, void* destination)
{
    struct Player { CriUint8 Reserved00[0xf8]; CriSint32 Width; CriSint32 Height; };
    struct Plane { CriUint8* Data; CriUint32 RowBytes; CriUint32 Rows; CriUint32 Pitch; CriUint32 Reserved; };
    struct Destination { Plane Planes[3]; };
    static_assert(offsetof(Player, Height) == 0xfc && sizeof(Plane) == 0x18, "layout");
    // Names chosen so cl 15's name-hash slot order matches the exe's [rsp+N] layout (ties: later = lower slot).
    CriUint8* dstp;
    CriUint32 rowsLeft;
    CriUint32 rowsUV;
    CriUint32 i;
    CriUint32 lineLen;
    CriUint32 halfBytes;
    const CriUint8* pU;
    const CriUint8* planeV;
    const CriUint8* lumaRow;
    struct { CriSint16 Chroma; CriSint16 Luma; CriUint32 Unused; } srcPitch;   // the exe's 8-byte pitch slot: 0x58/0x5a, 0x5c unused
    CriSint32 nHeight;
    CriUint32 numRows;
    CriUint32 rowLimit;
    const CriUint8* srcLine;
    CriSint32 widthL;
    widthL = ((Player*)player)->Width;
    nHeight = ((Player*)player)->Height;
    srcPitch.Luma = (CriSint16)((((widthL + 0xf) / 0x10) * 0x10 + 0x7f) / 0x80 * 0x80);
    srcPitch.Chroma = (CriSint16)((((widthL + 0xf) / 0x10) * 0x10 / 2 + 0x7f) / 0x80 * 0x80);
    lumaRow = (const CriUint8*)source;
    pU = lumaRow + (((widthL + 0xf) / 0x10) * 0x10 + 0x7f) / 0x80 * 0x80 * (((nHeight + 0x1f) / 0x20) * 0x20);
    planeV = pU + (((widthL + 0xf) / 0x10) * 0x10 / 2 + 0x7f) / 0x80 * 0x80 * (((nHeight + 0x1f) / 0x20) * 0x20 / 2);
    rowLimit = ((Destination*)destination)->Planes[0].RowBytes;
    numRows = ((Destination*)destination)->Planes[0].Rows;
    halfBytes = (((Destination*)destination)->Planes[0].RowBytes + 1) / 2;
    rowsUV = (((Destination*)destination)->Planes[0].Rows + 1) / 2;
    rowsLeft = numRows;
    lineLen = srcPitch.Luma;
    if (lineLen > rowLimit)
        lineLen = rowLimit;
    srcLine = lumaRow;
    dstp = ((Destination*)destination)->Planes[0].Data;
    for (i = 0; i < rowsLeft; i++)
    {
        memcpy(dstp, srcLine, lineLen);
        srcLine = srcLine + srcPitch.Luma;
        dstp = dstp + ((Destination*)destination)->Planes[0].Pitch;
    }
    rowsLeft = rowsUV;
    lineLen = srcPitch.Chroma;
    if (lineLen > halfBytes)
        lineLen = halfBytes;
    srcLine = pU;
    dstp = ((Destination*)destination)->Planes[1].Data;
    for (i = 0; i < rowsLeft; i++)
    {
        memcpy(dstp, srcLine, lineLen);
        srcLine = srcLine + srcPitch.Chroma;
        dstp = dstp + ((Destination*)destination)->Planes[1].Pitch;
    }
    rowsLeft = rowsUV;
    lineLen = srcPitch.Chroma;
    if (lineLen > halfBytes)
        lineLen = halfBytes;
    srcLine = planeV;
    dstp = ((Destination*)destination)->Planes[2].Data;
    for (i = 0; i < rowsLeft; i++)
    {
        memcpy(dstp, srcLine, lineLen);
        srcLine = srcLine + srcPitch.Chroma;
        dstp = dstp + ((Destination*)destination)->Planes[2].Pitch;
    }
}
#pragma intrinsic(memcpy)
#pragma optimize("", on)

__int64 FUN_1400530c0(__int64, int, int);  // C3: the definition's signature

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
#pragma function(memcpy)                      // the exe calls memcpy here rather than expanding it
// look for a start-code signature across the tail of one chunk and the head of the next.
// @0x1400405d0
CriBool searchSequenceEndCode(void* firstChunk, void* secondChunk, CriUint32 offset)
{
    struct Chunk { CriUint8* Data; CriUint32 Size; };
    // Names chosen so cl 15's name-hash slot order matches the exe's [rsp+N] layout (ties: later = lower slot).
    Chunk tail;
    CriUint64 overlap;                       // up to 3 bytes from each side of the seam (CriUint64: no /GS buffer)
    CriSint32 tb;
    CriSint32 hb;
    Chunk head;
    void* startCode;
    if (offset <= ((Chunk*)firstChunk)->Size)
    {
        if (((Chunk*)firstChunk)->Data == NULL)
        {
            head.Data = NULL;
            head.Size = 0;
        }
        else
        {
            head.Data = &((Chunk*)firstChunk)->Data[offset];
            head.Size = ((Chunk*)firstChunk)->Size - offset;
        }
        if (((Chunk*)secondChunk)->Data == NULL)
        {
            tail.Data = NULL;
            tail.Size = 0;
        }
        else
        {
            tail.Data = ((Chunk*)secondChunk)->Data;
            tail.Size = ((Chunk*)secondChunk)->Size;
        }
    }
    else
    {
        head.Data = NULL;
        head.Size = 0;
        if (((Chunk*)secondChunk)->Data == NULL)
        {
            tail.Data = NULL;
            tail.Size = 0;
        }
        else
        {
            tail.Data = &((Chunk*)secondChunk)->Data[offset - ((Chunk*)firstChunk)->Size];
            tail.Size = ((Chunk*)secondChunk)->Size - (offset - ((Chunk*)firstChunk)->Size);
        }
    }
    if (head.Data != NULL && head.Size > 3)
    {
        startCode = (void*)FUN_1400530c0((__int64)head.Data, head.Size, 0x80);
        if (startCode != NULL)
            return 1;
    }
    if (tail.Data == NULL || tail.Size <= 0)
        return 0;
    if (head.Size > 3)
        hb = 3;
    else
        hb = head.Size;
    if (tail.Size > 3)
        tb = 3;
    else
        tb = tail.Size;
    if (head.Data != NULL && hb > 0)
        memcpy(&overlap, head.Data + (head.Size - hb), hb);
    if (tail.Data != NULL && tb > 0)
        memcpy((CriUint8*)&overlap + hb, tail.Data, tb);
    if (hb + tb > 3)
    {
        startCode = (void*)FUN_1400530c0((__int64)&overlap, hb + tb, 0x80);
        if (startCode != NULL)
            return 1;
    }
    if (tail.Data != NULL && tail.Size > 3)
    {
        startCode = (void*)FUN_1400530c0((__int64)tail.Data, tail.Size, 0x80);
        if (startCode != NULL)
            return 1;
    }
    return 0;
}
#pragma intrinsic(memcpy)
#pragma optimize("", on)

void mvPlyAdec_ExecuteHandleAudioServer(void*);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// route one stream chunk to the decoder owning the given id and report whether all decoders are fed.
// @0x140042ba0
CriUint32 mvPlyAmng_ProcessOneContentChunk(void* trackSet, void* chunk, CriSint32 id, CriSint32* counts)
{
    struct Decoder { CriUint8 Reserved00[8]; CriSint32 Id; };
    struct TrackSet { Decoder* Decoders[2]; CriSint32 Count; CriUint8 Reserved14[4]; void* Queue; CriUint32 Limit; };
    // C-style locals at function scope, named so vc9's name-hash slot order matches the exe's
    CriSint32 index;
    void* queue;
    CriUint32 result;
    queue = ((TrackSet*)trackSet)->Queue;
    for (index = 0; index < ((TrackSet*)trackSet)->Count; ++index)
    {
        if (id == ((TrackSet*)trackSet)->Decoders[index]->Id)
        {
            result = 1;
            criSj_UngetChunk(queue, 1, chunk);
            mvPlyAdec_ExecuteHandleAudioServer(((TrackSet*)trackSet)->Decoders[index]);
            counts[index] = counts[index] + 1;
            for (index = 0; index < ((TrackSet*)trackSet)->Count; ++index)
            {
                if ((CriUint32)counts[index] < ((TrackSet*)trackSet)->Limit)
                    result = 2;
                if ((CriUint32)counts[index] >= ((TrackSet*)trackSet)->Limit + 1)
                {
                    result = 1;
                    break;
                }
            }
            return result;
        }
    }
    criSj_PutChunk(queue, 0, chunk);
    return 2;
}
#pragma optimize("", on)

CriUint32 mvPlyAdec_decideOutputSamples(void*, void*, CriUint32, CriUint32);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
#pragma function(memcpy, memset)              // the exe calls memcpy/memset here rather than expanding them
// drain buffered audio frames of every channel queue into per-channel 16-bit output buffers.
// @0x140042f40
CriUint32 criMvPlyAdec_GetWave16(void* decoder, void* player, CriUint32 channels, void* outputs, CriUint32 mode, CriUint32* info)
{
    struct Decoder { CriUint8 Reserved00[0x30]; void* Queues[8]; };
    struct Player { CriUint8 Reserved00[0xb2c]; CriUint32 Rate; CriUint8 Reserveb30[0x2ec]; CriUint32 FrameSize; };
    struct Chunk { void* Data; CriUint32 Size; };
    // C-style locals at function scope, named so vc9's name-hash slot order matches the exe's
    CriUint32 res;
    CriSint16* dst[8];
    Chunk chk;
    CriUint32 i;
    CriUint32 frames;
    CriUint32 remain[8];
    void* sj;
    CriUint32 len;
    frames = mvPlyAdec_decideOutputSamples(decoder, player, channels, mode);
    if (frames == 0)
        return 0;
    for (i = 0; i < channels; ++i)
    {
        dst[i] = ((CriSint16**)outputs)[i];
        remain[i] = frames;
    }
    while (remain[0] > 0)
    {
        for (i = 0; i < channels; ++i)
        {
            sj = ((Decoder*)decoder)->Queues[i];
            criSj_GetChunk(sj, 1, remain[i] * ((Player*)player)->FrameSize, &chk);
            if (chk.Size > 0)
            {
                len = chk.Size / ((Player*)player)->FrameSize;
                memcpy(dst[i], chk.Data, len * ((Player*)player)->FrameSize);
                dst[i] = dst[i] + len;
                remain[i] = remain[i] - len;
            }
            criSj_PutChunk(sj, 0, &chk);
        }
    }
    res = frames;
    info[0] = channels;
    info[1] = res;
    info[2] = ((Player*)player)->Rate;
    return res;
}

// drain buffered audio frames of every channel queue into per-channel 32-bit output buffers.
// @0x1400431a0
CriUint32 criMvPlyAdec_GetWave32(void* decoder, void* player, CriUint32 channels, void* outputs, CriUint32 mode, CriUint32* info)
{
    struct Decoder { CriUint8 Reserved00[0x30]; void* Queues[8]; };
    struct Player { CriUint8 Reserved00[0xb2c]; CriUint32 Rate; CriUint8 Reserveb30[0x2ec]; CriUint32 FrameSize; };
    struct Chunk { void* Data; CriUint32 Size; };
    // C-style locals at function scope, named so vc9's name-hash slot order matches the exe's
    CriUint32 res;
    CriSint32* dst[8];
    Chunk chk;
    CriUint32 i;
    CriUint32 frames;
    CriUint32 remain[8];
    void* sj;
    CriUint32 len;
    frames = mvPlyAdec_decideOutputSamples(decoder, player, channels, mode);
    if (frames == 0)
        return 0;
    memset(remain, 0, sizeof(remain));
    for (i = 0; i < channels; ++i)
    {
        dst[i] = ((CriSint32**)outputs)[i];
        remain[i] = frames;
    }
    while (remain[0] > 0)
    {
        for (i = 0; i < channels; ++i)
        {
            sj = ((Decoder*)decoder)->Queues[i];
            criSj_GetChunk(sj, 1, remain[i] * ((Player*)player)->FrameSize, &chk);
            if (chk.Size > 0)
            {
                len = chk.Size / ((Player*)player)->FrameSize;
                memcpy(dst[i], chk.Data, len * ((Player*)player)->FrameSize);
                dst[i] = dst[i] + len;
                remain[i] = remain[i] - len;
            }
            criSj_PutChunk(sj, 0, &chk);
        }
    }
    res = frames;
    info[0] = channels;
    info[1] = res;
    info[2] = ((Player*)player)->Rate;
    return res;
}
#pragma intrinsic(memcpy, memset)
#pragma optimize("", on)

unsigned int FUN_1400531e0(__int64, unsigned __int64, unsigned __int64, unsigned int *);  // C3: the definition's signature

// Pull the next movie frame into the three (or four) texture planes handed in by the renderer.
// @0x1400415f0
bool FUN_1400415f0(void* handle, void* planeSet)
{
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
    if (!((Handle*)handle)->State)
        return false;
    if (((Handle*)handle)->State->Cleared)
    {
        FUN_140041390(handle, planeSet);
        ((Handle*)handle)->State->Cleared = 0;
        return true;
    }
    if (((Handle*)handle)->State->Player->IsNextFrameOnTime())
    {
        CriUint32 count = ((const Scaleform::Render::ImageData*)planeSet)->GetPlaneCount();
        if (count >= 3)
        {
            CriImagePlane luma;
            CriImagePlane chromaU;
            CriImagePlane chromaV;
            CriImagePlane alpha;
            YuvSet yuv;  // not zeroed, as in the exe: entry 3 is only written when a fourth plane exists
            ((const Scaleform::Render::ImageData*)planeSet)->GetPlane(0, (Scaleform::Render::ImagePlane*)&luma);
            yuv.Entries[0].Data = luma.pData;
            yuv.Entries[0].Pitch = (CriUint32)luma.Pitch;
            yuv.Entries[0].Size = (CriUint32)luma.DataSize;
            ((const Scaleform::Render::ImageData*)planeSet)->GetPlane(1, (Scaleform::Render::ImagePlane*)&chromaU);
            yuv.Entries[1].Data = chromaU.pData;
            yuv.Entries[1].Pitch = (CriUint32)chromaU.Pitch;
            yuv.Entries[1].Size = (CriUint32)chromaU.DataSize;
            ((const Scaleform::Render::ImageData*)planeSet)->GetPlane(2, (Scaleform::Render::ImagePlane*)&chromaV);
            yuv.Entries[2].Data = chromaV.pData;
            yuv.Entries[2].Pitch = (CriUint32)chromaV.Pitch;
            yuv.Entries[2].Size = (CriUint32)chromaV.DataSize;
            if (((const Scaleform::Render::ImageData*)planeSet)->GetPlaneCount() >= 4)
            {
                ((const Scaleform::Render::ImageData*)planeSet)->GetPlane(3, (Scaleform::Render::ImagePlane*)&alpha);
                if (((Handle*)handle)->State->AlphaKeep)
                {
                    yuv.Entries[3].Data = alpha.pData;
                    yuv.Entries[3].Pitch = (CriUint32)alpha.Pitch;
                    yuv.Entries[3].Size = (CriUint32)alpha.DataSize;
                }
                else
                {
                    memset(alpha.pData, 0xff, alpha.Height * alpha.Pitch);
                    yuv.Entries[3].Data = NULL;
                    yuv.Entries[3].Pitch = 0;
                    yuv.Entries[3].Size = 0;
                }
            }
            FUN_1400531e0((__int64)((Handle*)handle)->State->Player, (unsigned __int64)&yuv, (unsigned __int64)&((Handle*)handle)->State->Frame, (unsigned int *)(&CriMv::ErrorContainer));
            FUN_1400414f0(handle);
        }
        else
        {
            CriImagePlane buffer;
            ((const Scaleform::Render::ImageData*)planeSet)->GetPlane(0, (Scaleform::Render::ImagePlane*)&buffer);
            ((Handle*)handle)->State->Player->GetFrameOnTimeAs32bitARGB(buffer.pData, (CriUint32)buffer.Pitch, (CriUint32)buffer.DataSize, *(CriMvFrameInfo*)&((Handle*)handle)->State->Frame, CriMv::ErrorContainer);
            FUN_1400414f0(handle);
        }
        ((Handle*)handle)->State->Delivered = 1;
        if (((Handle*)handle)->State->PausePending)
        {
            ((Handle*)handle)->State->Player->Pause(1, CriMv::ErrorContainer);
            ((Handle*)handle)->State->PausePending = 0;
        }
        return true;
    }
    return false;
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
extern "C" void* criUsfDmx_CreateWithWork(CriSint32 count, void* work, CriSint32 workSize);
#pragma optimize("", on)

extern "C" const CriUint8* criUsfCmn_GetContents(const CriUint8* data, CriUint32 size, CriSint32* contentSize);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// route queued USF chunks to the matching track decoders until a track set needs more data.
// @0x1400428e0
extern "C" void criMvPlyAmng_ExecuteAudioServer(void* trackSet, void* player)
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
    // C-style function-scope locals; the names give cl 15's name-hash slot order the exe has
    CriSint32 accepted;
    void* inQueue = ((TrackSet*)trackSet)->Queue;
    CriUint32 ret;
    Chunk chunk;
    CriSint32 idx;
    CriSint32 index;                        // unused; the exe keeps a 4-byte slot for it at [rsp+0x5c]
    CriSint32 payloadBytes;
    const CriUint8* pPayload;
    CriSint32 tally[2] = {0};
    CriUsfHeaderFields usfHdr;
    while ((CriUint32)FUN_1400467b8(inQueue, 1) > 0)
    {
        criSj_GetChunk(inQueue, 1, 0xffffffff, &chunk);
        if (chunk.Size >= 0x20)
        {
            criUsfCmn_ParseUsfHeaderStd(chunk.Data, chunk.Size, (CriUsfStandardHeader*)&usfHdr);
            pPayload = criUsfCmn_GetContents(chunk.Data, chunk.Size, &payloadBytes);
            if (usfHdr.Kind == 1)
            {
                accepted = 1;
                if (((TrackSet*)trackSet)->Callback != NULL)
                    accepted = ((TrackSet*)trackSet)->Callback(((TrackSet*)trackSet)->CallbackArg, &chunk, usfHdr.Byte0C);
                if (accepted == 1)
                {
                    criSj_PutChunk(inQueue, 0, &chunk);
                }
                else
                {
                    criSj_UngetChunk(inQueue, 1, &chunk);
                    return;
                }
            }
            else if (usfHdr.Kind == 0)
            {
                if (((Player*)player)->Elapsed > 0 && ((Player*)player)->Started != 1)
                {
                    if ((float)usfHdr.Words[1] / (float)usfHdr.Words[2] <
                        (float)((Player*)player)->Elapsed * 1000.0f / (float)((Player*)player)->Rate)
                    {
                        criSj_PutChunk(inQueue, 0, &chunk);
                        continue;
                    }
                    else
                    {
                        ((Player*)player)->Started = 1;
                    }
                }
                ret = mvPlyAmng_ProcessOneContentChunk(trackSet, &chunk, usfHdr.Byte0C, tally);
                if (ret == 1)
                    return;
            }
            else
            {
                criSj_PutChunk(inQueue, 0, &chunk);
            }
        }
    }
    if (FUN_1400467b8(inQueue, 1) == 0)
    {
        for (idx = 0; idx < ((TrackSet*)trackSet)->Count; idx++)
        {
            if (((TrackSet*)trackSet)->Decoders[idx]->Active == 1)
                mvPlyAdec_ExecuteHandleAudioServer(((TrackSet*)trackSet)->Decoders[idx]);
        }
    }
}
#pragma optimize("", on)

CriSint32 criSjUni_GetNumChainPool(void* streamJoint);

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
void criusfdmx_exec_decode(void* object);
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

// predict one block from a reference plane at an integer plus half-pel motion offset.
// @0x142ccc5f0
void FUN_142ccc5f0(CriUint8* reference, CriUint8* destination, CriSint32 stride, CriSint32 stride2, CriSint32 width,
                   CriSint32 height, CriSint32 x, CriSint32 y, CriSint32 mvx, CriSint32 mvy, CriSint32 flags)
{
    CriSint64 index = (CriSint64)flags * 8 + (CriSint64)(mvx & 1) * 2 + ((width >> 2) & 4) + (mvy & 1);
    CriUint8* source = reference + (CriSint64)(((mvy >> 1) + y) * stride) + x + (mvx >> 1);
    CriUint8* target = destination + (CriSint64)(y * stride) + x;
    DAT_143fe8248[index](source, target, stride, stride2, height);
}

// Dispatch the inverse-transform add for each coded block of the current macroblock.
// @0x142ccc6c0
void addBlocksFrame420(void* decoder, CriSint32 codedBlocks, CriSint32 mode)
{
    CriSint32 coded = codedBlocks >> 0x18;
    CriMpvBlockEntry entries[7], *out = entries;   // up to six coded blocks and the NULL terminator
    if ((coded & 0x3f) == 0)
        return;
    CriSint32 x = CriMpvField<CriSint32>(decoder, MPV_COLUMN) << 4;
    CriSint32 y = CriMpvField<CriSint32>(decoder, MPV_ROW) << 4;
    void** slots = (void**)((CriUint8*)decoder + MPV_BLOCK_SLOTS);
    if (coded & 0x3c)
    {
        CriSint16 stride = CriMpvField<CriSint16>(decoder, MPV_LUMA_STRIDE);
        CriSint32 stride8 = stride * 8;
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
            out->Data = base + stride8;
            out->Stride = stride;
            ++out;
        }
        if (coded & 4)
        {
            out->Function = slots[3];
            out->Data = base + stride8 + 8;
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
    addBlocksFrame420(decoder, (CriSint32)0xff000000, 0);
}

// run the skipped-macroblock callback for each address stepped back over, then resume reconstruction.
// @0x142ccc860
void MPVUMC_BpicSkipped(void* decoder, CriSint32 run)
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

// motion-compensate one macroblock from a reference frame with a clamped motion vector
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
    CriSint32 heightLimit = CriMpvField<CriSint32>(decoder, MPV_MB_HEIGHT) << 4;
    CriSint32 bound = (-x) * 2;
    if (mvx < bound)
    {
        CriMpvField<CriSint32>(decoder, MPV_CLAMP_COUNT) += 1;
        mvx = bound;
    }
    else
    {
        bound = ((CriMpvField<CriSint32>(decoder, MPV_MB_WIDTH) << 4) - x) * 2 - 0x20;
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
    CriSint32 halfX = mvx / 2;
    CriSint32 halfY = mvy / 2;
    FUN_142ccc5f0(frame->Chroma0, CriMpvField<CriUint8*>(decoder, MPV_CB_BASE), chromaStride, chromaStride, 8, 8,
                  chromaX, chromaY, halfX, halfY, flags);
    FUN_142ccc5f0(frame->Chroma1, CriMpvField<CriUint8*>(decoder, MPV_CR_BASE), chromaStride, chromaStride, 8, 8,
                  chromaX, chromaY, halfX, halfY, flags);
}

// forward-predicted macroblock: compensate from the first reference and add the residual.
// @0x142ccca50
void FUN_142ccca50(void* decoder)
{
    FUN_142ccc8c0(decoder, (CriUint8*)decoder + MPV_REF0, (CriUint8*)decoder + MPV_MV0, 0);
    addBlocksFrame420(decoder, CriMpvField<CriSint32>(decoder, MPV_CODED), 1);
}

// backward-predicted macroblock: compensate from the second reference and add the residual.
// @0x142ccca90
void FUN_142ccca90(void* decoder)
{
    FUN_142ccc8c0(decoder, (CriUint8*)decoder + MPV_REF1, (CriUint8*)decoder + MPV_MV1, 0);
    addBlocksFrame420(decoder, CriMpvField<CriSint32>(decoder, MPV_CODED), 1);
}

// bidirectional macroblock: average both reference predictions and add the residual.
// @0x142cccad0
void MPVUMC_BiDirect(void* decoder)
{
    FUN_142ccc8c0(decoder, (CriUint8*)decoder + MPV_REF0, (CriUint8*)decoder + MPV_MV0, 0);
    FUN_142ccc8c0(decoder, (CriUint8*)decoder + MPV_REF1, (CriUint8*)decoder + MPV_MV1, 1);
    addBlocksFrame420(decoder, CriMpvField<CriSint32>(decoder, MPV_CODED), 1);
}

// copy skipped macroblocks from the first reference with a zero motion vector.
// @0x142cccb30
void MPVUMC_PpicSkipped(void* decoder, CriSint32 run)
{
    struct Motion { CriSint32 Reserved00[6]; CriSint32 X; CriSint32 Y; CriSint32 Reserved20[4]; } zeroMotion;
    zeroMotion.X = 0;
    zeroMotion.Y = 0;
    CriSint32 target = CriMpvField<CriSint32>(decoder, MPV_ADDRESS);
    mpvumc_SubMbadr((CriMpvDecoderState*)decoder, run);
    if (CriMpvField<CriSint32>(decoder, MPV_ADDRESS) < target)
    {
        do
        {
            FUN_142ccc8c0(decoder, (CriUint8*)decoder + MPV_REF0, &zeroMotion, 0);
            mpvumc_IncreMbadr((CriMpvDecoderState*)decoder);
        } while (CriMpvField<CriSint32>(decoder, MPV_ADDRESS) < target);
    }
}

// decode the six 8x8 blocks of an intra macroblock and hand them to the block output function
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
    CriSint32 count0 = CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_BLOCK)(decoder, context);
    CriMpvField<void*>(context, 0x20) = base + 0x980;
    CriSint32 count1 = CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_BLOCK)(decoder, context);
    CriMpvField<void*>(context, 0x20) = base + 0xa00;
    CriSint32 count2 = CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_BLOCK)(decoder, context);
    CriMpvField<void*>(context, 0x20) = base + 0xa80;
    CriSint32 count3 = CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_BLOCK)(decoder, context);
    CriMpvField<void*>(context, 0x40) = CriMpvField<void*>(decoder, MPV_TABLE_CHROMA);
    CriMpvField<void*>(context, 0x38) = base + MPV_DC + 4;
    CriMpvField<void*>(context, 0x20) = base + 0xb00;
    CriSint32 count4 = CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_BLOCK)(decoder, context);
    CriMpvField<void*>(context, 0x38) = base + MPV_DC + 8;
    CriMpvField<void*>(context, 0x20) = base + 0xb80;
    CriSint32 count5 = CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_BLOCK)(decoder, context);
    void** slots = (void**)(base + MPV_BLOCK_SLOTS);
    CriMpvField<CriMpvBlockFunc>(decoder, MPV_BLOCK_FUNC)(base + MPV_COEF_LUMA, slots[0], count0);
    CriMpvField<CriMpvBlockFunc>(decoder, MPV_BLOCK_FUNC)(base + 0x980, slots[1], count1);
    CriMpvField<CriMpvBlockFunc>(decoder, MPV_BLOCK_FUNC)(base + 0xa00, slots[2], count2);
    CriMpvField<CriMpvBlockFunc>(decoder, MPV_BLOCK_FUNC)(base + 0xa80, slots[3], count3);
    CriMpvField<CriMpvBlockFunc>(decoder, MPV_BLOCK_FUNC)(base + 0xb00, slots[4], count4);
    CriMpvField<CriMpvBlockFunc>(decoder, MPV_BLOCK_FUNC)(base + 0xb80, slots[5], count5);
    return 0;
}

// Decode the coded 8x8 inter blocks of a macroblock, then hand each coded block to the block output function. The
// exe writes the output pass out block by block and re-reads both function slots for every call.
// @0x142cccd80
CriSint32 FUN_142cccd80(void* decoder)
{
    CriUint8* base = (CriUint8*)decoder;
    CriUint8* context = base + MPV_BLOCK_CONTEXT;
    CriSint32 quant = CriMpvField<CriSint32>(decoder, MPV_QUANT);
    CriMpvField<CriSint32>(context, 0x48) = 1;
    CriMpvField<CriSint32>(context, 0x30) = quant;
    CriMpvField<void*>(context, 0x28) = base + MPV_COEF_BASE_FIRST;
    CriSint32 counts[6];
    CriSint32 mask = CriMpvField<CriSint32>(decoder, MPV_CODED) << 2;
    for (CriUint32 block = 0; block < 6; ++block)
    {
        if (mask < 0)
        {
            CriMpvField<void*>(context, 0x20) = base + MPV_COEF_LUMA + block * 0x80;
            counts[block] = CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_INTER)(decoder, context);
        }
        mask += mask;
    }
    void** slots = (void**)(base + MPV_BLOCK_SLOTS);
    mask = CriMpvField<CriSint32>(decoder, MPV_CODED) << 2;
    if (mask < 0)
        CriMpvField<CriMpvBlockFunc>(decoder, MPV_BLOCK_FUNC)(base + MPV_COEF_LUMA, slots[0], counts[0]);
    mask += mask;
    if (mask < 0)
        CriMpvField<CriMpvBlockFunc>(decoder, MPV_BLOCK_FUNC)(base + MPV_COEF_LUMA + 0x80, slots[1], counts[1]);
    mask += mask;
    if (mask < 0)
        CriMpvField<CriMpvBlockFunc>(decoder, MPV_BLOCK_FUNC)(base + MPV_COEF_LUMA + 0x100, slots[2], counts[2]);
    mask += mask;
    if (mask < 0)
        CriMpvField<CriMpvBlockFunc>(decoder, MPV_BLOCK_FUNC)(base + MPV_COEF_LUMA + 0x180, slots[3], counts[3]);
    mask += mask;
    if (mask < 0)
        CriMpvField<CriMpvBlockFunc>(decoder, MPV_BLOCK_FUNC)(base + MPV_COEF_LUMA + 0x200, slots[4], counts[4]);
    mask += mask;
    if (mask < 0)
        CriMpvField<CriMpvBlockFunc>(decoder, MPV_BLOCK_FUNC)(base + MPV_COEF_LUMA + 0x280, slots[5], counts[5]);
    return 0;
}

// Decode the six blocks of an intra macroblock into 16-bit coefficient planes and emit their counts. The decode slot
// is re-read for every block, as in the exe.
// @0x142cccef0
CriSint32 FUN_142cccef0(void* decoder)
{
    CriUint8* base = (CriUint8*)decoder;
    CriUint8* intra = base + MPV_COEF_INTRA;
    memset(intra, 0, 0x600);
    CriUint8* context = base + MPV_BLOCK_CONTEXT;
    CriSint32 quant = CriMpvField<CriSint32>(decoder, MPV_QUANT);
    CriMpvField<CriSint32>(context, 0x48) = 0;
    CriMpvField<CriSint32>(context, 0x30) = quant;
    CriMpvField<void*>(context, 0x28) = base + MPV_COEF_BASE;
    CriMpvField<void*>(context, 0x40) = CriMpvField<void*>(decoder, MPV_TABLE_LUMA);
    CriMpvField<void*>(context, 0x20) = intra;
    CriMpvField<void*>(context, 0x38) = base + MPV_DC;
    CriUint8* counts = base + 0x1350;
    counts[0] = (CriUint8)CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_BLOCK)(decoder, context);
    CriMpvField<void*>(context, 0x20) = base + 0x400;
    counts[1] = (CriUint8)CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_BLOCK)(decoder, context);
    CriMpvField<void*>(context, 0x20) = base + 0x500;
    counts[2] = (CriUint8)CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_BLOCK)(decoder, context);
    CriMpvField<void*>(context, 0x20) = base + 0x600;
    counts[3] = (CriUint8)CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_BLOCK)(decoder, context);
    CriMpvField<void*>(context, 0x40) = CriMpvField<void*>(decoder, MPV_TABLE_CHROMA);
    CriMpvField<void*>(context, 0x38) = base + MPV_DC + 4;
    CriMpvField<void*>(context, 0x20) = base + 0x700;
    counts[4] = (CriUint8)CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_BLOCK)(decoder, context);
    CriMpvField<void*>(context, 0x38) = base + MPV_DC + 8;
    CriMpvField<void*>(context, 0x20) = base + 0x800;
    counts[5] = (CriUint8)CriMpvField<CriMpvDecodeBlockFunc>(decoder, MPV_DECODE_BLOCK)(decoder, context);
    CriMpvField<CriMpvEmitFunc>(decoder, MPV_BLOCK_FUNC)(counts);
    return 0;
}

// Decode the coded inter blocks of a macroblock into 16-bit coefficient planes and emit their counts. The coded-block
// mask is shifted (<<= 1, not mask += mask: cl 15 then keeps the decoder in rdi, as the exe does).
// @0x142ccd080
CriSint32 FUN_142ccd080(void* decoder)
{
    CriUint8* base = (CriUint8*)decoder;
    CriSint32 quant = CriMpvField<CriSint32>(decoder, MPV_QUANT);
    CriUint8* context = base + MPV_BLOCK_CONTEXT;
    CriMpvField<CriSint32>(context, 0x48) = 1;
    CriMpvField<CriSint32>(context, 0x30) = quant;
    CriMpvField<void*>(context, 0x28) = base + MPV_COEF_BASE_FIRST;
    CriSint32 mask = CriMpvField<CriSint32>(decoder, MPV_CODED) * 4;
    for (CriUint32 block = 0; block < 6; ++block)
    {
        if (mask < 0)
        {
            CriMpvField<void*>(context, 0x20) = base + MPV_COEF_INTRA + block * 0x100;
            base[0x1350 + block] = (CriUint8)CriMpvField<CriMpvDecodeBlockFunc>(base, MPV_DECODE_INTER)(base, context);
        }
        mask <<= 1;
    }
    CriMpvField<CriSint32>(decoder, 0x1380) = CriMpvField<CriSint32>(decoder, MPV_CODED) * 4;
    CriMpvField<CriMpvEmitFunc>(decoder, MPV_EMIT_FUNC)(base + 0x1350);
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
void SJ_SplitChunk(__int64 *, int, __int64 *, __int64 *);  // C3: the definition's signature
unsigned int FUN_140051d90(__int64 *);  // C3: the definition's signature
void MPVCONCEAL_SkippedMb(__int64); // C3: the definition's signature

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
    return ((CriUint32)(CriSint8)data[0] << 24) | ((CriUint32)data[1] << 16) | ((CriUint32)data[2] << 8) | data[3];
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

}

// Bit window steps on plain locals high, low, pos and cur (see the slice decoders below).
#define CRI_MPV_ADVANCE(count)                                                                                  \
    do                                                                                                          \
    {                                                                                                           \
        pos += (count);                                                                                         \
        if (pos >= 0x20)                                                                                        \
        {                                                                                                       \
            high = low;                                                                                         \
            low = CriReadBigEndian32(cur);                                                                      \
            pos -= 0x20;                                                                                        \
            high <<= pos;                                                                                       \
            cur += 4;                                                                                           \
        }                                                                                                       \
        else                                                                                                    \
        {                                                                                                       \
            high <<= (count);                                                                                   \
        }                                                                                                       \
    } while (0)
#define CRI_MPV_PEEK(window, count)                   \
    do                                                \
    {                                                 \
        (window) = high >> (32 - (count));            \
        if (pos > 32 - (count))                       \
            (window) |= low >> (64 - (count) - pos);  \
    } while (0)

// MS2-FUNCTIONAL: decode one DC coefficient difference with the MPEG intra VLC tables and update its predictor.
// The bit window is kept in plain locals as in the slice decoders; what is left is register choice (the exe keeps
// decoder in r9 and saves rbx only around the size read).
// @0x142ccb520
CriSint32 mpvdec_MotionSub(void* decoder, void* parameters, CriSint32* output, CriSint32* predictor)
{
    struct Parameters { CriSint32 Double; CriSint32 Size; CriSint32 SignBits; CriSint32 Range; };
    Parameters* params = (Parameters*)parameters;
    CriUint32 high = CriMpvField<CriUint32>(decoder, MPV_BITS_HIGH);
    CriSint32 pos = CriMpvField<CriSint32>(decoder, MPV_BITS_POSITION);
    CriUint32 low = CriMpvField<CriUint32>(decoder, MPV_BITS_LOW);
    const CriUint8* cur = CriMpvField<const CriUint8*>(decoder, MPV_BITS_CURSOR);
    CriSint32 size = params->Size;
    CriSint32 result = 0;
    CriUint32 window;
    CRI_MPV_PEEK(window, 11);
    CriSint32 entry;
    if ((window & 0xffffff80) == 0)
        entry = DAT_143d74a38[window];
    else
        entry = DAT_143d749c8[window >> 6];
    CriSint32 symbol = (CriSint8)entry;
    if (symbol == 0x7f)
    {
        result = -1;
    }
    else
    {
        CRI_MPV_ADVANCE((CriUint8)((CriUint32)entry >> 8));
        if (symbol == 0)
        {
            *output = *predictor;
        }
        else
        {
            if (size != 0)
            {
                CriUint32 value;
                CriSint32 rest = 32 - size;
                if (pos >= rest)
                {
                    pos = pos + size - 32;
                    if (pos != 0)
                    {
                        value = (low >> (size - pos) | high) >> rest;
                        high = low << pos;
                    }
                    else
                    {
                        value = high >> rest;
                        high = low;
                    }
                    low = CriReadBigEndian32(cur);
                    cur += 4;
                }
                else
                {
                    value = high >> rest;
                    pos += size;
                    high <<= size;
                }
                CriSint32 adjust = params->Range - (CriSint32)value - 1;
                symbol <<= size;
                if (symbol > 0)
                    symbol -= adjust;
                else
                    symbol += adjust;
            }
            CriSint32 total = (CriSint32)((CriUint32)(*predictor + symbol) << params->SignBits) >> params->SignBits;
            *output = total;
            *predictor = total;
        }
        if (params->Double != 0)
            *output <<= 1;
    }
    CriMpvField<CriUint32>(decoder, MPV_BITS_LOW) = low;
    CriMpvField<CriUint32>(decoder, MPV_BITS_HIGH) = high;
    CriMpvField<CriSint32>(decoder, MPV_BITS_POSITION) = pos;
    CriMpvField<const CriUint8*>(decoder, MPV_BITS_CURSOR) = cur;
    return result;
}

// MS2-FUNCTIONAL: decode the macroblocks of an intra-only MPEG video slice chunk by chunk.
// The bit window is kept in plain locals through the CRI_MPV_* macros: VC9 /O2 keeps the cursor of a
// CriMpvBitReader aggregate in a stack slot, where the exe has it in a register. What is left in the I, P and B
// slice decoders is register assignment (the cursor and position sit in other registers); in P and B the longer
// encodings that follow from it put a 6-byte alignment nop before the outer loop head.
#define CRI_MPV_CHUNK() CriMpvField<CriMpvChunk>(decoder, MPV_CHUNK)
#define CRI_MPV_GETCHUNK() ((CriMpvQueueGet)(*(void***)queue)[6])(queue, 1, 0x7fffffff, &CRI_MPV_CHUNK())
#define CRI_MPV_START(extra)                                                                                    \
    do                                                                                                          \
    {                                                                                                           \
        cur = (const CriUint8*)((uintptr_t)CRI_MPV_CHUNK().Data & ~(uintptr_t)3);                              \
        pos = (CriSint32)((CriUint32)(uintptr_t)CRI_MPV_CHUNK().Data << 3);                                     \
        pos -= (CriSint32)((CriUint32)(uintptr_t)cur << 3);                                                     \
        high = CriReadBigEndian32(cur) << pos;                                                                  \
        low = CriReadBigEndian32(cur + 4);                                                                      \
        cur += 8;                                                                                               \
        pos += (extra);                                                                                         \
        if (pos >= 0x20)                                                                                        \
        {                                                                                                       \
            high = low;                                                                                         \
            low = CriReadBigEndian32(cur);                                                                      \
            pos -= 0x20;                                                                                        \
            high <<= pos;                                                                                       \
            cur += 4;                                                                                           \
        }                                                                                                       \
        else                                                                                                    \
        {                                                                                                       \
            high <<= (extra);                                                                                   \
        }                                                                                                       \
    } while (0)
#define CRI_MPV_CONSUMED(alignedBits) \
    ((CriSint32)(((CriUint32)((alignedBits) >> 3)) - (CriUint32)(uintptr_t)CRI_MPV_CHUNK().Data + (CriUint32)(uintptr_t)cur - 8))
#define CRI_MPV_RETURN_UNREAD(consumed)                                                                         \
    do                                                                                                          \
    {                                                                                                           \
        CriMpvChunk remaining;                                                                                  \
        SJ_SplitChunk((__int64*)&CRI_MPV_CHUNK(), (CriUint32)(consumed), (__int64*)&CRI_MPV_CHUNK(), (__int64*)&remaining); \
        ((CriMpvQueuePut)(*(void***)queue)[8])(queue, 0, &CRI_MPV_CHUNK());                                    \
        ((CriMpvQueuePut)(*(void***)queue)[7])(queue, 1, &remaining);                                          \
    } while (0)
#define CRI_MPV_STORE()                                                \
    do                                                                 \
    {                                                                  \
        CriMpvField<CriUint32>(decoder, MPV_BITS_HIGH) = high;         \
        CriMpvField<CriUint32>(decoder, MPV_BITS_LOW) = low;           \
        CriMpvField<CriSint32>(decoder, MPV_BITS_POSITION) = pos;      \
        CriMpvField<const CriUint8*>(decoder, MPV_BITS_CURSOR) = cur;  \
    } while (0)
// @0x142ccb000
CriSint32 MPVDEC_DecIpicMb(void* decoder, void* queue)
{
    CriUint32 high;
    CriUint32 low;
    const CriUint8* cur;
    CriSint32 pos;
    CRI_MPV_GETCHUNK();
    CRI_MPV_START(CriMpvField<CriUint32>(decoder, MPV_CHUNK_BIT_OFFSET));
    for (;;)
    {
        CriUint32 window;
        CRI_MPV_PEEK(window, 23);
        if (window == 0)
            break;
        // macroblock_address_increment
        CriSint32 previous = CriMpvField<CriSint32>(decoder, MPV_ADDRESS);
        CriSint32 entry;
        CriSint32 increment;
        for (;;)
        {
            CRI_MPV_PEEK(window, 12);
            if ((window & 0xffffff00) == 0)
                entry = DAT_143d74a30[window];
            else
                entry = DAT_143d749f0[window >> 6];
            CRI_MPV_ADVANCE(entry & 0xf);
            increment = (CriUint8)((CriUint32)entry >> 2) >> 2;
            if (increment == 0x22)
                continue;
            if (increment == 0x23)
            {
                CriMpvField<CriSint32>(decoder, MPV_ADDRESS) += 0x21;
                continue;
            }
            if (increment == 0x24)
                goto done;
            CriMpvField<CriSint32>(decoder, MPV_ADDRESS) += increment;
            break;
        }
        CriSint32 address = CriMpvField<CriSint32>(decoder, MPV_ADDRESS);
        CriUint32 flags = (CriUint32)entry >> 10;
        CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS) = flags;
        if (address > CriMpvField<CriSint32>(decoder, MPV_LAST_ADDRESS))
            break;
        CriSint32 width = CriMpvField<CriSint32>(decoder, MPV_MB_WIDTH);
        CriSint32 step = address - previous;
        CriMpvField<CriSint32>(decoder, MPV_COLUMN) += step;
        while (CriMpvField<CriSint32>(decoder, MPV_COLUMN) >= width)
        {
            CriMpvField<CriSint32>(decoder, MPV_COLUMN) -= width;
            CriMpvField<CriSint32>(decoder, MPV_ROW) += 1;
        }
        if (step == -2)
            break;
        // quantiser_scale_code
        if (flags & 0x10)
        {
            CriUint32 value;
            if (pos >= 32 - 5)
            {
                pos -= 32 - 5;
                if (pos != 0)
                {
                    value = (high | (low >> (5 - pos))) >> (32 - 5);
                    high = low << pos;
                }
                else
                {
                    value = high >> (32 - 5);
                    high = low;
                }
                low = CriReadBigEndian32(cur);
                cur += 4;
            }
            else
            {
                value = high >> (32 - 5);
                pos += 5;
                high <<= 5;
            }
            CriMpvField<CriUint32>(decoder, MPV_QUANT) = value;
        }
        CRI_MPV_STORE();
        CriMpvField<void (*)(void*)>(decoder, 0x18d0)(decoder);
        CriMpvField<void (*)(void*)>(decoder, 0x1700)(decoder);
        CriMpvField<void (*)(void*)>(decoder, 0x1710)(decoder);
        if (CriMpvField<CriSint32>(decoder, MPV_STOP) != 0 || CriMpvField<CriSint32>(decoder, MPV_ABORT) != 0)
            break;
        if (--CriMpvField<CriSint32>(decoder, MPV_CALLBACK_COUNTDOWN) <= 0)
        {
            CriMpvField<CriSint32>(decoder, MPV_CALLBACK_COUNTDOWN) = CriMpvField<CriSint32>(decoder, MPV_CALLBACK_RELOAD);
            CriMpvField<void (*)(void*)>(decoder, MPV_CALLBACK_FUNC)(CriMpvField<void*>(decoder, MPV_CALLBACK_ARG));
        }
        pos = CriMpvField<CriSint32>(decoder, MPV_BITS_POSITION);
        cur = CriMpvField<const CriUint8*>(decoder, MPV_BITS_CURSOR);
        high = CriMpvField<CriUint32>(decoder, MPV_BITS_HIGH);
        low = CriMpvField<CriUint32>(decoder, MPV_BITS_LOW);
        {
            CriSint32 misaligned = pos & 7;
            CriSint32 consumed = CRI_MPV_CONSUMED(pos - misaligned + 7);
            if ((CriSint32)CRI_MPV_CHUNK().Size - consumed <= 0x800)
            {
                CRI_MPV_RETURN_UNREAD(consumed);
                CRI_MPV_GETCHUNK();
                CRI_MPV_START((CriUint32)misaligned);
            }
        }
    }
done:
    CRI_MPV_RETURN_UNREAD(CRI_MPV_CONSUMED(pos + 7));
    return FUN_140051d90((__int64*)queue);
}

namespace
{
typedef void (*CriMpvMacroblockFunc)(void*);
typedef void (*CriMpvSkipRunFunc)(void*, CriSint32);

}

// MS2-FUNCTIONAL: decode the macroblocks of a predicted MPEG video slice with forward and backward vectors.
// @0x142ccb710
CriSint32 MPVDEC_DecBpicMb(void* decoder, void* queue)
{
    CriUint32 high;
    CriUint32 low;
    const CriUint8* cur;
    CriSint32 pos;
    CriSint32 first = 1;
    CRI_MPV_GETCHUNK();
    CRI_MPV_START(CriMpvField<CriUint32>(decoder, MPV_CHUNK_BIT_OFFSET));
    for (;;)
    {
        CriUint32 window;
        CRI_MPV_PEEK(window, 23);
        if (window == 0)
            break;
        // macroblock_address_increment
        CriSint32 previous = CriMpvField<CriSint32>(decoder, MPV_ADDRESS);
        CriSint32 entry;
        CriSint32 increment;
        for (;;)
        {
            CRI_MPV_PEEK(window, 11);
            if ((window & 0xffffff80) == 0)
                entry = DAT_143d749e0[window];
            else
                entry = DAT_143d749d8[window >> 6];
            CRI_MPV_ADVANCE(entry & 0xf);
            increment = (CriUint8)((CriUint32)entry >> 2) >> 2;
            if (increment == 0x22)
                continue;
            if (increment == 0x23)
            {
                CriMpvField<CriSint32>(decoder, MPV_ADDRESS) += 0x21;
                continue;
            }
            if (increment == 0x24)
                goto done;
            CriMpvField<CriSint32>(decoder, MPV_ADDRESS) += increment;
            break;
        }
        CriSint32 address = CriMpvField<CriSint32>(decoder, MPV_ADDRESS);
        CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS) = (CriUint32)entry >> 10;
        if (address > CriMpvField<CriSint32>(decoder, MPV_LAST_ADDRESS))
            break;
        CriSint32 width = CriMpvField<CriSint32>(decoder, MPV_MB_WIDTH);
        CriSint32 step = address - previous;
        CriMpvField<CriSint32>(decoder, MPV_COLUMN) += step;
        while (CriMpvField<CriSint32>(decoder, MPV_COLUMN) >= width)
        {
            CriMpvField<CriSint32>(decoder, MPV_COLUMN) -= width;
            CriMpvField<CriSint32>(decoder, MPV_ROW) += 1;
            width = CriMpvField<CriSint32>(decoder, MPV_MB_WIDTH);
        }
        if (step == -2)
            break;
        if (!first && (CriUint32)step > 1)
        {
            CriMpvField<CriMpvSkipRunFunc>(decoder, 0x16f8)(decoder, step);
            MPVDEC_ResetDc((CriMpvDecoderState*)decoder);
            MPVCONCEAL_SkippedMb((__int64)decoder);
        }
        CriMpvField<CriMpvMacroblockFunc>(decoder, 0x18d0)(decoder);
        // macroblock_type
        if (!(CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS) & 0x20))
        {
            CRI_MPV_PEEK(window, 6);
            entry = DAT_143d74a08[window];
            CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS) = (CriUint32)entry >> 8;
            CRI_MPV_ADVANCE((CriUint8)entry);
        }
        CriUint32 flags = CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS);
        // quantiser_scale_code
        if (flags & 0x10)
        {
            CriUint32 value;
            if (pos >= 32 - 5)
            {
                pos -= 32 - 5;
                if (pos != 0)
                {
                    value = (high | (low >> (5 - pos))) >> (32 - 5);
                    high = low << pos;
                }
                else
                {
                    value = high >> (32 - 5);
                    high = low;
                }
                low = CriReadBigEndian32(cur);
                cur += 4;
            }
            else
            {
                value = high >> (32 - 5);
                pos += 5;
                high <<= 5;
            }
            CriMpvField<CriUint32>(decoder, MPV_QUANT) = value;
        }
        // motion_vectors: forward, then backward
        if (flags & 8)
        {
            CRI_MPV_STORE();
            CriSint32 horizontal = mpvdec_MotionSub(decoder, (CriUint8*)decoder + 0x174c, (CriSint32*)((CriUint8*)decoder + 0x1764),
                                                    (CriSint32*)((CriUint8*)decoder + 0x175c));
            CriSint32 vertical = mpvdec_MotionSub(decoder, (CriUint8*)decoder + 0x174c, (CriSint32*)((CriUint8*)decoder + 0x1768),
                                                  (CriSint32*)((CriUint8*)decoder + 0x1760));
            high = CriMpvField<CriUint32>(decoder, MPV_BITS_HIGH);
            low = CriMpvField<CriUint32>(decoder, MPV_BITS_LOW);
            pos = CriMpvField<CriSint32>(decoder, MPV_BITS_POSITION);
            cur = CriMpvField<const CriUint8*>(decoder, MPV_BITS_CURSOR);
            if ((horizontal | vertical) != 0)
                break;
        }
        if (CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS) & 4)
        {
            CRI_MPV_STORE();
            CriSint32 horizontal = mpvdec_MotionSub(decoder, (CriUint8*)decoder + 0x1770, (CriSint32*)((CriUint8*)decoder + 0x1788),
                                                    (CriSint32*)((CriUint8*)decoder + 0x1780));
            CriSint32 vertical = mpvdec_MotionSub(decoder, (CriUint8*)decoder + 0x1770, (CriSint32*)((CriUint8*)decoder + 0x178c),
                                                  (CriSint32*)((CriUint8*)decoder + 0x1784));
            high = CriMpvField<CriUint32>(decoder, MPV_BITS_HIGH);
            low = CriMpvField<CriUint32>(decoder, MPV_BITS_LOW);
            pos = CriMpvField<CriSint32>(decoder, MPV_BITS_POSITION);
            cur = CriMpvField<const CriUint8*>(decoder, MPV_BITS_CURSOR);
            if ((horizontal | vertical) != 0)
                break;
        }
        // coded_block_pattern
        CriSint64 mode = CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS);
        if (mode & 2)
        {
            CRI_MPV_PEEK(window, 9);
            entry = DAT_143d74a20[window];
            CriMpvField<CriSint32>(decoder, MPV_CODED) = (CriSint32)((CriUint32)entry << 16) & (CriSint32)0xfff00000;
            CRI_MPV_ADVANCE((CriUint8)entry);
        }
        else
        {
            CriMpvField<CriSint32>(decoder, MPV_CODED) = 0;
        }
        CRI_MPV_STORE();
        if (mode & 1)
        {
            CriMpvField<CriMpvMacroblockFunc>(decoder, 0x1700)(decoder);
            CriMpvField<CriMpvMacroblockFunc>(decoder, 0x1710)(decoder);
            MPVDEC_ResetMv((CriMpvDecoderState*)((CriUint8*)decoder + 0x174c));
            MPVDEC_ResetMv((CriMpvDecoderState*)((CriUint8*)decoder + 0x1770));
        }
        else
        {
            CriMpvMacroblockFunc predict = (&CriMpvField<CriMpvMacroblockFunc>(decoder, 0x1718))[(mode >> 2) & 3];
            CriMpvField<CriMpvMacroblockFunc>(decoder, 0x1718) = predict;
            if (CriMpvField<CriSint32>(decoder, MPV_CODED) != 0)
                CriMpvField<CriMpvMacroblockFunc>(decoder, 0x1708)(decoder);
            predict(decoder);
            MPVDEC_ResetDc((CriMpvDecoderState*)decoder);
        }
        if (CriMpvField<CriSint32>(decoder, MPV_STOP) != 0 || CriMpvField<CriSint32>(decoder, MPV_ABORT) != 0)
            break;
        if (--CriMpvField<CriSint32>(decoder, MPV_CALLBACK_COUNTDOWN) <= 0)
        {
            CriMpvField<CriSint32>(decoder, MPV_CALLBACK_COUNTDOWN) = CriMpvField<CriSint32>(decoder, MPV_CALLBACK_RELOAD);
            CriMpvField<void (*)(void*)>(decoder, MPV_CALLBACK_FUNC)(CriMpvField<void*>(decoder, MPV_CALLBACK_ARG));
        }
        pos = CriMpvField<CriSint32>(decoder, MPV_BITS_POSITION);
        cur = CriMpvField<const CriUint8*>(decoder, MPV_BITS_CURSOR);
        high = CriMpvField<CriUint32>(decoder, MPV_BITS_HIGH);
        low = CriMpvField<CriUint32>(decoder, MPV_BITS_LOW);
        {
            CriSint32 misaligned = pos & 7;
            CriSint32 consumed = CRI_MPV_CONSUMED(pos - misaligned + 7);
            if ((CriSint32)CRI_MPV_CHUNK().Size - consumed <= 0x800)
            {
                CRI_MPV_RETURN_UNREAD(consumed);
                CRI_MPV_GETCHUNK();
                CRI_MPV_START((CriUint32)misaligned);
            }
        }
        first = 0;
    }
done:
    CRI_MPV_RETURN_UNREAD(CRI_MPV_CONSUMED(pos + 7));
    return FUN_140051d90((__int64*)queue);
}

// MS2-FUNCTIONAL: decode the macroblocks of a forward-predicted MPEG video slice with a single vector set.
// @0x142ccbe90
CriSint32 MPVDEC_DecPpicMb(void* decoder, void* queue)
{
    CriUint32 high;
    CriUint32 low;
    const CriUint8* cur;
    CriSint32 pos;
    CriSint32 first = 1;
    CRI_MPV_GETCHUNK();
    CRI_MPV_START(CriMpvField<CriUint32>(decoder, MPV_CHUNK_BIT_OFFSET));
    for (;;)
    {
        CriUint32 window;
        CRI_MPV_PEEK(window, 23);
        if (window == 0)
            break;
        // macroblock_address_increment
        CriSint32 previous = CriMpvField<CriSint32>(decoder, MPV_ADDRESS);
        CriSint32 entry;
        CriSint32 increment;
        for (;;)
        {
            CRI_MPV_PEEK(window, 11);
            if ((window & 0xffffff80) == 0)
                entry = DAT_143d74a00[window];
            else
                entry = DAT_143d749f8[window >> 6];
            CRI_MPV_ADVANCE(entry & 0xf);
            increment = (CriUint8)((CriUint32)entry >> 2) >> 2;
            if (increment == 0x22)
                continue;
            if (increment == 0x23)
            {
                CriMpvField<CriSint32>(decoder, MPV_ADDRESS) += 0x21;
                continue;
            }
            if (increment == 0x24)
                goto done;
            CriMpvField<CriSint32>(decoder, MPV_ADDRESS) += increment;
            break;
        }
        CriSint32 address = CriMpvField<CriSint32>(decoder, MPV_ADDRESS);
        CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS) = (CriUint32)entry >> 10;
        if (address > CriMpvField<CriSint32>(decoder, MPV_LAST_ADDRESS))
            break;
        CriSint32 width = CriMpvField<CriSint32>(decoder, MPV_MB_WIDTH);
        CriSint32 step = address - previous;
        CriMpvField<CriSint32>(decoder, MPV_COLUMN) += step;
        while (CriMpvField<CriSint32>(decoder, MPV_COLUMN) >= width)
        {
            CriMpvField<CriSint32>(decoder, MPV_COLUMN) -= width;
            CriMpvField<CriSint32>(decoder, MPV_ROW) += 1;
            width = CriMpvField<CriSint32>(decoder, MPV_MB_WIDTH);
        }
        if (step == -2)
            break;
        if (!first && (CriUint32)step > 1)
        {
            CriMpvField<CriMpvSkipRunFunc>(decoder, 0x16f8)(decoder, step);
            MPVDEC_ResetMv((CriMpvDecoderState*)((CriUint8*)decoder + 0x174c));
            MPVDEC_ResetDc((CriMpvDecoderState*)decoder);
            MPVCONCEAL_SkippedMb((__int64)decoder);
        }
        CriMpvField<CriMpvMacroblockFunc>(decoder, 0x18d0)(decoder);
        // macroblock_type
        if (!(CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS) & 0x20))
        {
            CRI_MPV_PEEK(window, 5);
            entry = DAT_143d749d0[window];
            CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS) = (CriUint32)entry >> 8;
            CRI_MPV_ADVANCE((CriUint8)entry);
        }
        CriUint32 flags = CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS);
        // quantiser_scale_code
        if (flags & 0x10)
        {
            CriUint32 value;
            if (pos >= 32 - 5)
            {
                pos -= 32 - 5;
                if (pos != 0)
                {
                    value = (high | (low >> (5 - pos))) >> (32 - 5);
                    high = low << pos;
                }
                else
                {
                    value = high >> (32 - 5);
                    high = low;
                }
                low = CriReadBigEndian32(cur);
                cur += 4;
            }
            else
            {
                value = high >> (32 - 5);
                pos += 5;
                high <<= 5;
            }
            CriMpvField<CriUint32>(decoder, MPV_QUANT) = value;
        }
        // motion_vectors
        if (flags & 8)
        {
            CRI_MPV_STORE();
            CriSint32 horizontal = mpvdec_MotionSub(decoder, (CriUint8*)decoder + 0x174c, (CriSint32*)((CriUint8*)decoder + 0x1764),
                                                    (CriSint32*)((CriUint8*)decoder + 0x175c));
            CriSint32 vertical = mpvdec_MotionSub(decoder, (CriUint8*)decoder + 0x174c, (CriSint32*)((CriUint8*)decoder + 0x1768),
                                                  (CriSint32*)((CriUint8*)decoder + 0x1760));
            high = CriMpvField<CriUint32>(decoder, MPV_BITS_HIGH);
            low = CriMpvField<CriUint32>(decoder, MPV_BITS_LOW);
            pos = CriMpvField<CriSint32>(decoder, MPV_BITS_POSITION);
            cur = CriMpvField<const CriUint8*>(decoder, MPV_BITS_CURSOR);
            if ((horizontal | vertical) != 0)
                break;
        }
        else
        {
            MPVDEC_ResetMv((CriMpvDecoderState*)((CriUint8*)decoder + 0x174c));
        }
        // coded_block_pattern
        flags = CriMpvField<CriUint32>(decoder, MPV_MB_FLAGS);
        if (flags & 2)
        {
            CRI_MPV_PEEK(window, 9);
            entry = DAT_143d74a20[window];
            CriMpvField<CriSint32>(decoder, MPV_CODED) = (CriSint32)((CriUint32)entry << 16) & (CriSint32)0xfff00000;
            CRI_MPV_ADVANCE((CriUint8)entry);
        }
        else
        {
            CriMpvField<CriSint32>(decoder, MPV_CODED) = 0;
        }
        CRI_MPV_STORE();
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
        if (CriMpvField<CriSint32>(decoder, MPV_STOP) != 0 || CriMpvField<CriSint32>(decoder, MPV_ABORT) != 0)
            break;
        if (--CriMpvField<CriSint32>(decoder, MPV_CALLBACK_COUNTDOWN) <= 0)
        {
            CriMpvField<CriSint32>(decoder, MPV_CALLBACK_COUNTDOWN) = CriMpvField<CriSint32>(decoder, MPV_CALLBACK_RELOAD);
            CriMpvField<void (*)(void*)>(decoder, MPV_CALLBACK_FUNC)(CriMpvField<void*>(decoder, MPV_CALLBACK_ARG));
        }
        pos = CriMpvField<CriSint32>(decoder, MPV_BITS_POSITION);
        cur = CriMpvField<const CriUint8*>(decoder, MPV_BITS_CURSOR);
        high = CriMpvField<CriUint32>(decoder, MPV_BITS_HIGH);
        low = CriMpvField<CriUint32>(decoder, MPV_BITS_LOW);
        {
            CriSint32 misaligned = pos & 7;
            CriSint32 consumed = CRI_MPV_CONSUMED(pos - misaligned + 7);
            if ((CriSint32)CRI_MPV_CHUNK().Size - consumed <= 0x800)
            {
                CRI_MPV_RETURN_UNREAD(consumed);
                CRI_MPV_GETCHUNK();
                CRI_MPV_START((CriUint32)misaligned);
            }
        }
        first = 0;
    }
done:
    CRI_MPV_RETURN_UNREAD(CRI_MPV_CONSUMED(pos + 7));
    return FUN_140051d90((__int64*)queue);
}
#undef CRI_MPV_STORE
#undef CRI_MPV_RETURN_UNREAD
#undef CRI_MPV_CONSUMED
#undef CRI_MPV_PEEK
#undef CRI_MPV_START
#undef CRI_MPV_ADVANCE
#undef CRI_MPV_GETCHUNK
#undef CRI_MPV_CHUNK

unsigned __int64 FUN_14004eea0(unsigned __int64, unsigned int);  // C3: the definition's signature
unsigned int FUN_140050bd0(__int64, unsigned __int64, void *);  // C3: the definition's signature
void FUN_1400511d0(__int64, unsigned __int64, unsigned int);  // C3: the definition's signature
void MPV_GetPicUsr(__int64, unsigned __int64 *, unsigned int *);  // C3: the definition's signature
unsigned int MPV_DecodePicAtr(unsigned __int64, unsigned __int64 *, int *); // C3: the definition's signature
unsigned int MPV_GetPicAtr(__int64, int *);  // C3: the definition's signature

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// decode one picture's slices into the supplied frame set through the MPEG video decoder.
// @0x140040850
CriSint32 decodeFrmUsingSjrbf(void* player, void* stream, void* second, CriSint32* consumed, void* frames)
{
    struct Stream { void* Data; CriSint32 Size; };
    struct Player { CriUint8 Reserved00[0x78]; void* Decoder; CriUint8 Reserved80[0x1a0]; void* Field; CriUint8* Base; CriSint32 Total; CriSint32 Extra; };
    struct Field { CriUint8 Reserved00[0x18]; CriSint32 Rest; CriSint32 Span; CriSint32 Tail; CriSint32 Head; };
    typedef CriSint32 (*SizeFunc)(void*, CriSint32);
    typedef void (*ReleaseFunc)(void*);
    // Names chosen so cl 15's name-hash slot order matches the exe's [rsp+N] layout (ties: later = lower slot).
    void* p;                                 // the bitstream object handed to the MPEG decoder
    CriSint32 res;
    void* temporary;                         // a bitstream object created here, released at the end
    CriSint32 headBytes;
    Field* field;
    CriSint32 tailSize;
    p = NULL;
    temporary = NULL;
    if (second != NULL)
    {
        field = (Field*)((Player*)player)->Field;
        if (field != NULL)
        {
            p = field;
            headBytes = (CriSint32)((CriUint8*)((Stream*)stream)->Data - ((Player*)player)->Base);
            tailSize = ((Stream*)second)->Size + ((Player*)player)->Extra;
            field->Head = headBytes;
            field->Tail = tailSize;
            field->Span = headBytes - tailSize;
            field->Rest = ((Player*)player)->Total - field->Span;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        temporary = (void*)FUN_14004eea0((unsigned __int64)(((Stream*)stream)->Data), (CriUint32)((Stream*)stream)->Size);
        if (temporary == NULL)
            return -1;
        p = temporary;
    }
    res = FUN_140050bd0((__int64)(((Player*)player)->Decoder), (unsigned __int64)p, frames);
    if (second == NULL)
        *consumed = ((Stream*)stream)->Size - ((SizeFunc)(*(void***)p)[9])(p, 1);
    else
        *consumed = ((Stream*)stream)->Size + ((Stream*)second)->Size - ((SizeFunc)(*(void***)p)[9])(p, 1);
    if (temporary != NULL)
        ((ReleaseFunc)(*(void***)temporary)[3])(temporary);
    return res;
}
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
// MS2-FUNCTIONAL: pull the next demuxed video picture, decode it and update the reference-picture window. Still DIFF
// by structure, same behaviour: the exe switches on the picture type (case 1-2 I/P, case 3 B, default "D Picture" at
// one site), describes the tiled planes inline and reads player fields directly, where ours uses an if chain and
// CriMpvField / CriMpvSetTiledFrame calls (4425 vs 5631 bytes).
// @0x14003efc0
CriSint32 crivmpv_DecodeOnePictureInPool(void* player)
{
    struct Chunk { void* Data; CriSint32 Size; CriSint32 Reserved; };
    struct Record { CriUint8* Picture; CriUint8 Reserved08[8]; CriUint8* Output; CriUint32 Reserved18; CriSint32 Width;
                    CriSint32 Height; CriUint32 Reserved24; CriUint64 Reserved28; CriUint64 Reserved30; };
    typedef void (*InspectFunc)(void*, void*, void*);
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
        criSj_GetChunk(inputQueue, 2, 0xffffffff, &chunk);
        if (CriMpvField<InspectFunc>(player, 0x248) != NULL)
        {
            Chunk* secondary = NULL;
            if (FUN_14003d6c0(&chunk) != 0)
            {
                criSj_GetChunk(inputQueue, 2, 0xffffffff, &extra);
                secondary = &extra;
            }
            CriMpvField<InspectFunc>(player, 0x248)(&chunk, secondary, CriMpvField<void*>(player, 0x250));
            if (secondary)
                criSj_UngetChunk(inputQueue, 2, &extra);
        }
        CriSint32 payloadSize;
        CriUint8* payload = (CriUint8*)criUsfCmn_GetContents((const CriUint8*)chunk.Data, (CriUint32)chunk.Size, &payloadSize);
        Chunk packet = { payload, payloadSize, 0 };
        CriUint8* start = (CriUint8*)FUN_1400530c0((__int64)payload, (CriUint32)payloadSize, 0x4c);
        if (!start)
        {
            criSj_UngetChunk(inputQueue, 2, &chunk);
            FUN_140041110(0, "E06100901M : Failed MPV_SearchDelim().", CriMpvField<CriUint32>(player, 0x194));
            CriMpvField<CriSint32>(player, 0x18) = 4;
            return produced;
        }
        CriUint8 saved[0x40];
        FUN_1400511d0((__int64)decoder, (unsigned __int64)saved, 0x40);
        Chunk stream;
        stream.Data = start;
        stream.Size = chunk.Size - ((CriSint32)(uintptr_t)start - (CriSint32)(uintptr_t)chunk.Data);
        if (MPV_DecodePicAtr((unsigned __int64)decoder, (unsigned __int64 *)&stream, (int *)attributes) != 0)
        {
            criSj_UngetChunk(inputQueue, 2, &chunk);
            FUN_140041110(0, "E06100902M : failed MPV_DecodePicAtr().", CriMpvField<CriUint32>(player, 0x194));
            CriMpvField<CriSint32>(player, 0x18) = 4;
            return produced;
        }
        if (MPV_GetPicAtr((__int64)decoder, (int *)(((CriUint8*)player) + 0xf8)) != 0)
        {
            criSj_UngetChunk(inputQueue, 2, &chunk);
            FUN_140041110(0, "E06100903M : MPV_GetPicAtr().", CriMpvField<CriUint32>(player, 0x194));
            CriMpvField<CriSint32>(player, 0x18) = 4;
            return produced;
        }
        CriSint32 width = CriMpvField<CriSint32>(player, 0xf8);
        CriSint32 height = CriMpvField<CriSint32>(player, 0xfc);
        CriSint32 pictureType = CriMpvField<CriSint32>(player, 0x110);
        CriUint32 headerSize;
        MPV_GetPicUsr((__int64)decoder, 0, (unsigned int *)&headerSize);
        attributes[2] = retrieveCscFlag(saved, (CriSint32)headerSize);
        stream.Data = (CriUint8*)stream.Data + attributes[0];
        stream.Size -= attributes[0];
        Chunk slot;
        criSj_GetChunk(poolQueue, 0, 0xffffffff, &slot);
        if (!slot.Data)
        {
            criSj_UngetChunk(inputQueue, 2, &chunk);
            crivmpv_occurFatalError(0, "E06100904M : Can't get chunk data from frame buffer Sj.", 0);
            CriMpvField<CriSint32>(player, 0x18) = 4;
            return produced;
        }
        Record* record = (Record*)slot.Data;
        void* current = ((CriUint8*)player) + 0xc0;
        CriMpvSetTiledFrame(current, record->Picture, width, height);
        CriMpvField<void*>(player, 0xe0) = ((CriUint8*)player) + 0xf8;
        void* forward = ((CriUint8*)player) + 0x80;
        void* backward = ((CriUint8*)player) + 0xa0;
        if (pictureType < 1)
        {
            criSj_UngetChunk(inputQueue, 2, &chunk);
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
                    crivmpv_AddDataLineToFramePool(player, (void**)&slot);
                    CriMpvField<CriSint32>(player, 0x240) += 1;
                }
                else
                {
                    CriMpvSetTiledFrame(backward, CriMpvField<CriUint8*>(player, 0xd0), width, height);
                    CriMpvField<void*>(player, 0x70) = NULL;
                    memcpy(((CriUint8*)player) + 0x60, &slot, 0x10);
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
                        criSj_GetChunk(poolQueue, 3, 0xffffffff, &pending);
                        if (!pending.Data)
                        {
                            criSj_UngetChunk(inputQueue, 2, &chunk);
                            crivmpv_occurFatalError(0, "E06100906M : Failed in crivmpv_DecodeOnePictureInPool() [IP-2a]", 0);
                            CriMpvField<CriSint32>(player, 0x18) = 4;
                            return produced;
                        }
                        criSj_PutChunk(poolQueue, 0, &pending);
                    }
                    memcpy(&pending, ((CriUint8*)player) + 0x60, 0x10);
                    if (!pending.Data)
                    {
                        criSj_UngetChunk(inputQueue, 2, &chunk);
                        crivmpv_occurFatalError(0, "E06100907M : Failed in crivmpv_DecodeOnePictureInPool() [IP-2b]", 0);
                        CriMpvField<CriSint32>(player, 0x18) = 4;
                        return produced;
                    }
                    crivmpv_AddDataLineToFramePool(player, (void**)&pending);
                    CriMpvField<CriSint32>(player, 0x240) += 1;
                    memcpy(((CriUint8*)player) + 0x60, &slot, 0x10);
                }
                else
                {
                    Chunk pending;
                    memcpy(&pending, ((CriUint8*)player) + 0x60, 0x10);
                    if (!pending.Data)
                    {
                        criSj_UngetChunk(inputQueue, 2, &chunk);
                        crivmpv_occurFatalError(0, "E06100905M : Failed in crivmpv_DecodeOnePictureInPool() [IP-1]", 0);
                        CriMpvField<CriSint32>(player, 0x18) = 4;
                        return produced;
                    }
                    crivmpv_AddDataLineToFramePool(player, (void**)&pending);
                    CriMpvField<CriSint32>(player, 0x240) += 1;
                    memcpy(((CriUint8*)player) + 0x60, &slot, 0x10);
                }
            }
        }
        else
        {
            if (pictureType != 3)
            {
                criSj_UngetChunk(inputQueue, 2, &chunk);
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
            criSj_UngetChunk(poolQueue, 0, &slot);
            criSj_PutChunk(inputQueue, 0, &chunk);
            if (FUN_14003d6c0(&chunk) != 0)
            {
                criSj_GetChunk(inputQueue, 2, 0xffffffff, &extra);
                criSj_PutChunk(inputQueue, 0, &extra);
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
                criSj_GetChunk(inputQueue, 2, 0xffffffff, &extra);
                tailChunk = extra;
                secondary = &tailChunk;
            }
            if (decodeFrmUsingSjrbf(player, &stream, secondary, &headerBytes, forward) != 0)
            {
                criSj_UngetChunk(inputQueue, 2, &packet);
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
            if (searchSequenceEndCode(&stream, &tailChunk, (CriUint32)headerBytes) == 1)
                CriMpvField<CriSint32>(player, 0x1ac) = 1;
            if (pictureType == 3)
                crivmpv_AddDataLineToFramePool(player, (void**)&slot);
            criSj_PutChunk(inputQueue, 0, &chunk);
            if (FUN_14003d6c0(&chunk) != 0)
            {
                extra = tailChunk;
                criSj_PutChunk(inputQueue, 0, &extra);
            }
            CriMpvField<CriSint32>(player, 0x188) -= 1;
            FUN_14003ed40(player);
        }
    }
}
#pragma optimize("", on)

// ---- full-exe unresolved: leaves without .pdata that data_cri / data_data_game reference as ?FUN_<va>@@YAXXZ ----

struct cri03_stream { virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0;
                      virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0;
                      virtual void v8() = 0; virtual void* Call9(long long a, long long b, long long c) = 0; };

struct cri03_host20 { void* vtbl; void* _08[3]; cri03_stream* stream; };
// forwards to slot 9 (+0x48) of the object at +0x20; 0 without one.
// @0x140041360
void* FUN_140041360(cri03_host20* self, long long a, long long b, long long c)
{
    cri03_stream* o = self->stream;
    return o ? o->Call9(a, b, c) : NULL;
}

// empty interface slot.
// @0x140041c50
void FUN_140041c50(void*) {}

struct cri03_host08 { void* vtbl; cri03_stream* stream; };
// slot 9 (+0x48) of the object at +8 with (a, d, 0), both ints sign-extended.
// @0x140041d00
void* FUN_140041d00(cri03_host08* self, CriSint32 a, void*, CriSint32 d)
{
    cri03_stream* o = self->stream;
    return o->Call9(a, d, 0);
}

struct cri03_kinds { void* vtbl; void* _08[3]; CriSint32 k1; CriSint32 k0; };
#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
CriSint32 FUN_140046000(cri03_kinds* self, CriSint32 kind);
#pragma optimize("", on)

void* FUN_140039ea8(void* work, CriSint32 size);
extern "C" void* FUN_140039ea8(void* work, int size);
void* FUN_1400385c8(void* work, CriUint32 size);
extern "C" void* FUN_1400385c8(void* work, unsigned long long size);
