// Recovered Scaleform GFx video audio glue from the executable; SDK material is reference only. Unlike sfr_video_03
// (the VS2008 Video add-on lib), the 0x142742ed0-0x1427433f0 block is VS2017 code, so this unit builds with the
// default toolset (cl 19.16).
// MS2-UNIT: sfr_video_03b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142742ed0-0x1427433f0 .text$mn
#include "../include/video/video_video.h"
#include "../include/video/video_videoplayerimpl.h"
#include "../include/kernel/sf_array.h"
#include "../../../../third_party/fmod44464/api/inc/fmod.hpp"
#include <cstring>
#include <cstdint>

// The exe functions and globals this unit uses but does not define, declared by their FUN_<va> / DAT_<va> names: the
// hook DLL binds them to the exe, the full exe to the recovered definition at that VA (tools/fullexe/alias.py).
template <class T> struct ExeDecl { typedef T type; };

ExeDecl<void(void*)>::type FUN_14257dc30;
ExeDecl<void(void*)>::type FUN_14257dcb0;
ExeDecl<int(void*, void*)>::type FUN_1428d8f14;
ExeDecl<int(void*, void*)>::type FUN_1428d8efc;
namespace Scaleform { namespace GFx { int FUN_1427443c0(void* channel, int type, void* commanddata1, void* commanddata2); }}   // FMOD channel callback (sfr_as2_01g)
ExeDecl<uint64_t()>::type FUN_1425e3480;
namespace Scaleform { unsigned FUN_142745f50(void*); }
namespace Scaleform { void ReserveVideoPlayerArray(void** array, void* heap, UPInt requested); }   // ArrayData<VideoPlayerImpl*>::Reserve (sfr_as3_22)
extern ExeDecl<void*>::type DAT_1431b4c60; struct Sd_1431bec40; extern "C" Sd_1431bec40 DAT_1431bec40;
#define VideoAudioVtableA DAT_1431b4c60
#define VideoAudioVtableB (*reinterpret_cast<void**>(&DAT_1431bec40))
struct Sd_1431bed60; extern "C" Sd_1431bed60 DAT_1431bed60; struct Sd_1431bedd8; extern "C" Sd_1431bedd8 DAT_1431bedd8;
#define VideoAudioDeleteVtable (*reinterpret_cast<void**>(&DAT_1431bed60))
#define VideoAudioSubVtable (*reinterpret_cast<void**>(&DAT_1431bedd8))
struct Sd_1431bede8; extern "C" Sd_1431bede8 DAT_1431bede8;
#define VideoAudioEventVtable (*reinterpret_cast<void**>(&DAT_1431bede8))
struct Sd_1431bcbb0; extern "C" Sd_1431bcbb0 DAT_1431bcbb0;
#define VideoSoundDeleteVtable (*reinterpret_cast<void**>(&DAT_1431bcbb0))
struct Sd_1431bef00; extern "C" Sd_1431bef00 DAT_1431bef00;
#define VideoSoundVtable (*reinterpret_cast<void**>(&DAT_1431bef00))
struct Sd_1431bef38; extern "C" Sd_1431bef38 DAT_1431bef38;
#define VideoSoundSubVtable (*reinterpret_cast<void**>(&DAT_1431bef38))
struct Sd_1431bee78; extern "C" Sd_1431bee78 DAT_1431bee78;
#define VideoAudioStreamVtable (*reinterpret_cast<void**>(&DAT_1431bee78))
struct Sd_1431beef0; extern "C" Sd_1431beef0 DAT_1431beef0;
#define VideoAudioStreamSubVtable (*reinterpret_cast<void**>(&DAT_1431beef0))

typedef Scaleform::GFx::Video::VideoPlayerImpl* Video03bElement;
typedef Scaleform::ArrayData<Video03bElement, Scaleform::AllocatorGH<Video03bElement, 2>, Scaleform::ArrayDefaultPolicy> Video03bData;
// ArrayData::Append with ArrayDataBase::ResizeNoConstruct, Reserve bound to the exe's 0x1427463e0
static inline void Video03bAppend(Video03bData* output, const Video03bElement other[], Scaleform::UPInt count)
{
    if (count) {
        Scaleform::UPInt oldSize = output->Size;
        Scaleform::UPInt newSize = output->Size + count;
        if (newSize < oldSize) {
            if (newSize < (output->Policy.GetCapacity() >> 1)) Scaleform::ReserveVideoPlayerArray(reinterpret_cast<void**>(output), output, newSize);
        }
        else if (newSize > output->Policy.GetCapacity()) Scaleform::ReserveVideoPlayerArray(reinterpret_cast<void**>(output), output, newSize + (newSize >> 2));
        output->Size = newSize;
        // AllocatorBaseGH ConstructArray(p, count, psource)
        Scaleform::UByte* pdata = reinterpret_cast<Scaleform::UByte*>(output->Data + oldSize);
        for (Scaleform::UPInt i = 0; i < count; ++i, pdata += sizeof(Video03bElement))
            ::new (pdata) Video03bElement(*other++);
    }
}
// ArrayData copy ctor: copies a VideoPlayer pointer array into fresh allocator owned storage. The base ctor from the
// source's Policy keeps the exe's unfolded old size (cl folds it to 0 when the three fields are zeroed by hand).
// @0x142742ed0
__declspec(noinline) void* FUN_142742ed0(void* destination, const uint64_t* source)
{
    const Video03bData& a = *reinterpret_cast<const Video03bData*>(source);
    Video03bData* output = static_cast<Video03bData*>(::new (destination) Video03bData::BaseType(a.Policy));
    Video03bAppend(output, a.Data, a.Size);
    return destination;
}
// copies the three leading array fields and deep copies the VideoPlayer list.
// @0x142742f70
uint64_t* FUN_142742f70(uint64_t* destination, const uint64_t* source)
{
    destination[0] = source[0]; destination[1] = source[1]; destination[2] = source[2];
    FUN_142742ed0(destination + 3, source + 3);
    return destination;
}

namespace {
// the channel object's list link at +0x10 (vtable, next, prev) and the player's channel list sentinel at +0xb0
struct Video03bChannelNode { void* Vtable; Video03bChannelNode* pNext; Video03bChannelNode* pPrev; };
struct Video03bChannelList
{
    Video03bChannelNode Root;
    void PushBack(Video03bChannelNode* p) { p->pPrev = Root.pPrev; p->pNext = &Root; Root.pPrev->pNext = p; Root.pPrev = p; }
};
}

// sfr22: external linkage, sfr_as3_22b's sound-channel Start paths construct the same object.
// Initializes and links the per-channel callback object, then registers it with FMOD.
// The link goes through the list's PushBack and the vtable-B store is a plain qword store, which gives the exe's
// r10/r11 assignment and keeps the RefCount store ahead of it.
// @0x142742fb0
__declspec(noinline) uint64_t* FUN_142742fb0(uint64_t* object, void* player, uint64_t userData, void* channel)
{
    Video03bChannelList* list = reinterpret_cast<Video03bChannelList*>(static_cast<unsigned char*>(player) + 0xb0);
    reinterpret_cast<Scaleform::RefCountImplCore*>(object)->Scaleform::RefCountImplCore::RefCountImplCore();
    *reinterpret_cast<void***>(object) = &VideoAudioVtableA;
    object[2] = reinterpret_cast<uintptr_t>(&VideoAudioVtableB);
    list->PushBack(reinterpret_cast<Video03bChannelNode*>(object + 2));
    *reinterpret_cast<void***>(object) = &VideoAudioDeleteVtable;
    reinterpret_cast<Video03bChannelNode*>(object + 2)->Vtable = &VideoAudioSubVtable;
    object[8] = 0;
    uint64_t* fields = object + 5;
    fields[0] = reinterpret_cast<uintptr_t>(player); fields[1] = userData; fields[2] = reinterpret_cast<uintptr_t>(channel);
    FUN_1428d8f14(reinterpret_cast<void*>(object[7]), object);
    FUN_1428d8efc(reinterpret_cast<void*>(object[7]), reinterpret_cast<void*>(&Scaleform::GFx::FUN_1427443c0));
    return object;
}
namespace {
// initializes the audio event listener, its locks, and its intrusive-list sentinel.
// @0x142743130
uint64_t* FUN_142743130(uint64_t* object)
{
    reinterpret_cast<Scaleform::RefCountImpl*>(object)->Scaleform::RefCountImpl::RefCountImpl();
    *reinterpret_cast<void***>(object) = &VideoAudioEventVtable;
    object[2] = 0; object[3] = 0;
    reinterpret_cast<Scaleform::Event*>(reinterpret_cast<unsigned char*>(object) + 0x20)->Scaleform::Event::Event(false, false);
    reinterpret_cast<Scaleform::Lock*>(reinterpret_cast<unsigned char*>(object) + 0x80)->Scaleform::Lock::Lock(0);
    object[0x15] = 0;
    uint64_t* listRoot = object + 0x16;
    listRoot[1] = reinterpret_cast<uintptr_t>(listRoot);
    *reinterpret_cast<void***>(listRoot) = &VideoAudioVtableB;
    listRoot[2] = reinterpret_cast<uintptr_t>(listRoot);
    reinterpret_cast<Scaleform::Lock*>(reinterpret_cast<unsigned char*>(object) + 0xc8)->Scaleform::Lock::Lock(0);
    unsigned char* bytes = reinterpret_cast<unsigned char*>(object);
    bytes[0xf0] = 0;
    *reinterpret_cast<uint32_t*>(bytes + 0xf4) = 0;
    bytes[0x78] = 0;
    return object;
}

// Initializes an FMOD stream callback, snapshots its start time, and records pause state.
// The +0x69 flag is cleared through a subscripted byte view; the deref-of-cast form makes cl schedule the Lock ctor's lea after the time store.
// @0x142743050
uint64_t* FUN_142743050(uint64_t* object, void* player, void* streamState, void* channel)
{
    FUN_142742fb0(object, player, reinterpret_cast<uintptr_t>(streamState), channel);
    *reinterpret_cast<void***>(object) = &VideoAudioStreamVtable;
    *reinterpret_cast<void***>(object + 2) = &VideoAudioStreamSubVtable;
    object[9] = FUN_1425e3480();
    reinterpret_cast<unsigned char*>(object)[0x69] = 0;
    reinterpret_cast<Scaleform::Lock*>(reinterpret_cast<unsigned char*>(object) + 0x70)->Scaleform::Lock::Lock(0);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<unsigned char*>(object) + 0x98) = 0;
    Scaleform::AtomicOps<int>::ExchangeAdd_NoSync(reinterpret_cast<volatile int*>(static_cast<unsigned char*>(streamState) + 8), 1);
    object[0xb] = 0; object[0xc] = 0;
    // The channel's paused state lands in the member at +0x68, which SetAudioPaused and QueryAudioElapsedSeconds read.
    bool* paused = reinterpret_cast<bool*>(reinterpret_cast<unsigned char*>(object) + 0x68);
    reinterpret_cast<FMOD::Channel*>(object[7])->getPaused(paused);
    if (*paused) { object[10] = object[9]; return object; }
    Scaleform::FUN_142745f50(streamState);
    object[9] = FUN_1425e3480();
    const uint32_t a = *reinterpret_cast<uint32_t*>(static_cast<unsigned char*>(streamState) + 0x70);
    const uint32_t b = *reinterpret_cast<uint32_t*>(static_cast<unsigned char*>(streamState) + 0x50);
    const uint32_t c = *reinterpret_cast<uint32_t*>(static_cast<unsigned char*>(streamState) + 0x48);
    const uint32_t d = *reinterpret_cast<uint32_t*>(static_cast<unsigned char*>(streamState) + 0x4c);
    object[0xc] = ((((static_cast<uint64_t>(a) << 3) / b) / c) * 1000000) / d;
    return object;
}

// Initializes the FMOD streaming sound, computes its PCM format, and creates the sound handle.
// The stream slot (object[8]) is cleared through a volatile view and reassigned through a void*& reference;
// both pin the exe's store schedule.
// @0x142743240
uint64_t* FUN_142743240(uint64_t* object, void* owner, void* stream, int stereo, uint32_t rate, uint32_t channels)
{
    uint64_t* node = object + 2;
    uint64_t* list = reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(owner) + 0xb0);
    uint64_t* sound = object + 6;
    *reinterpret_cast<void***>(object) = &VideoSoundDeleteVtable;
    reinterpret_cast<uint32_t*>(object)[2] = 1;
    *reinterpret_cast<void***>(node) = &VideoAudioVtableB;
    node[2] = list[2];
    node[1] = reinterpret_cast<uintptr_t>(list);
    reinterpret_cast<uint64_t*>(list[2])[1] = reinterpret_cast<uintptr_t>(node);
    list[2] = reinterpret_cast<uintptr_t>(node);
    object[7] = 0;
    *reinterpret_cast<void***>(object) = &VideoSoundVtable;
    *reinterpret_cast<void***>(node) = &VideoSoundSubVtable;
    object[5] = reinterpret_cast<uintptr_t>(owner);
    *sound = 0; *reinterpret_cast<void* volatile*>(object + 8) = 0;
    reinterpret_cast<uint32_t*>(object)[18] = rate;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<unsigned char*>(object) + 0x4c) = channels;
    object[0xb] = 0; reinterpret_cast<uint32_t*>(object)[0x18] = 0;
    *reinterpret_cast<uint64_t*>(reinterpret_cast<unsigned char*>(object) + 0x6c) = 0;
    if (stream) FUN_14257dc30(stream);
    void*& slot = *reinterpret_cast<void**>(object + 8);
    if (slot) FUN_14257dcb0(slot);
    slot = stream;
    const uint32_t format = stereo == 0 ? 2 : 5;
    const uint32_t sampleBits = stereo == 0 ? 0x10 : 0x20;
    const uint32_t soundChannels = *reinterpret_cast<uint32_t*>(reinterpret_cast<unsigned char*>(object) + 0x4c);
    const uint32_t soundRate = reinterpret_cast<uint32_t*>(object)[18];
    reinterpret_cast<uint32_t*>(object)[0x1a] = format;
    reinterpret_cast<uint32_t*>(object)[0x14] = sampleBits;
    const int32_t pcmBytes = static_cast<int32_t>((soundChannels / 1000) * (sampleBits >> 3) * soundRate * 0x5dc);
    *reinterpret_cast<int32_t*>(reinterpret_cast<unsigned char*>(object) + 100) = pcmBytes;
    unsigned int length;
    FMOD_CREATESOUNDEXINFO info;
    memset(&info, 0, sizeof(info));
    uint32_t* infoWords = reinterpret_cast<uint32_t*>(&info);
    infoWords[0] = sizeof(info);
    infoWords[1] = static_cast<uint32_t>(pcmBytes);
    infoWords[3] = soundRate;
    infoWords[4] = soundChannels;
    infoWords[5] = format;
    if (static_cast<FMOD::System*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(object[5]) + 0x10))->createSound(0, 0x442, &info, reinterpret_cast<FMOD::Sound**>(sound)) != 0) *sound = 0;
    else {
        length = 0;
        reinterpret_cast<FMOD::Sound*>(*sound)->getLength(&length, 4);
    }
    return object;
}
} // namespace
