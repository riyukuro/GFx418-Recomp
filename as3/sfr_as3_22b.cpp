// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 sound renderer (FMOD back end):
// the sample / aux-streamer channel methods, the FMOD update thread body and the sync-point set rehashes that sit
// between sfr_as3_22's renderer methods and sfr_gfx_12. Our own source, written from the exe.
// Sub-unit of sfr_as3_22.
// MS2-UNIT: sfr_as3_22b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142746480-0x142747bc0 .text$mn
#include "../gfx/sfr_gfx_07raw.h"
#include <windows.h>
#include <intrin.h>
#include <cstdint>
#include <string.h>
#include <math.h>
#include "fmod44464/api/inc/fmod.hpp"
#include "ms2/scaleform/include/kernel/sf_threads.h"
#include "ms2/scaleform/include/kernel/sf_alg.h"


extern "C" char DAT_1431bee78[];   // aux-streamer channel vftable
extern "C" char DAT_1431beef0[];   // its second base

std::uint64_t* FUN_142742fb0(std::uint64_t* object, void* player, std::uint64_t userData, void* channel); // channel ctor

extern "C" void FUN_142746d70(void* self);
extern "C" void FUN_142747530(Scaleform::GFx::U** self, void* heap, Scaleform::GFx::U n);
extern "C" void FUN_1427478c0(Scaleform::GFx::U** self, void* heap, Scaleform::GFx::U n);
extern "C" void FUN_142747b30(void* self);

unsigned __int64 FUN_1425e3480();  // Timer::GetProfileTicks

namespace Scaleform {
void* FindAudioRequestEntry(void** set, const unsigned char* key);  // sync-point set: the value at key
unsigned FUN_142745f50(void* streamer);   // AuxStreamer ReadAndFill: bytes queued

namespace GFx {

void FUN_142744070(char* self, void* psound);               // renderer: attach a channel
int FUN_1427443c0(void* channel, int type, void* commanddata1, void* commanddata2); // channel callback
void FUN_142742830(U** self, const U* key);                 // array-valued set: remove key
void FUN_1427429d0(U** self, void* heap, const U* node, U hash);        // array-valued set: add (copies the array)
void FUN_142742b50(U** self, void* heap, const NodeRef* node, U hash);  // sync-point set: add
float FUN_1427471f0(void* self);
float FUN_142746f10(void* self);
bool FUN_142746480(void* self, float seconds);
void FUN_1427474d0(void* channel, const void* transform);

static inline CRITICAL_SECTION* RawLock(void* base, U off) { return RawFieldPtr<CRITICAL_SECTION>(base, off); }

// Microseconds of PCM the streamer has queued: bytes * 8 / bits / channels * 1e6 / rate.
static inline U FilledMicros(void* s)
{
    return (U)RawField<unsigned>(s, 0x70) * 8 / RawField<unsigned>(s, 0x50) / RawField<unsigned>(s, 0x48) * 1000000 /
           RawField<unsigned>(s, 0x4c);
}

static inline float AtLeast(float floor, float x) { return floor > x ? floor : x; }
// Lock::Locker over a raw CRITICAL_SECTION member (the channel lock at +0x70, the renderer AuxStreamsLock at +0x80).
struct ChannelLocker
{
    CRITICAL_SECTION* cs;
    ChannelLocker(CRITICAL_SECTION* c) : cs(c) { EnterCriticalSection(cs); }
    ~ChannelLocker() { LeaveCriticalSection(cs); }
};

// The AuxStreamers hash (streamer -> Array<SoundChannelFMODImplAux*>) and its HashSetBase iterator.
struct AuxTable
{
    U EntryCount, SizeMask;
};
struct AuxEntry
{
    SPInt NextInChain; // -2 = empty
    U     HashValue;
    void* Key;
    void** Data;
    U     Size, Policy;
};
struct AuxIter
{
    AuxTable* const* pHash;
    SPInt Index;
    AuxIter(AuxTable* const* h, SPInt i) : pHash(h), Index(i) {}
    static AuxEntry& E(AuxTable* t, SPInt i) { return ((AuxEntry*)(t + 1))[i]; }
    AuxEntry& operator*() const { return E(*pHash, Index); }
    void operator++()
    {
        if (Index <= (SPInt)(*pHash)->SizeMask)
        {
            Index++;
            while ((U)Index <= (*pHash)->SizeMask && E(*pHash, Index).NextInChain == -2)
                Index++;
        }
    }
    bool IsEnd() const { return (pHash == 0) || (*pHash == 0) || (Index > (SPInt)(*pHash)->SizeMask); }
    bool operator==(const AuxIter& o) const
    {
        if (IsEnd() && o.IsEnd())
            return true;
        return (pHash == o.pHash) && (Index == o.Index);
    }
    bool operator!=(const AuxIter& o) const { return !(*this == o); }
};
static inline AuxIter AuxBegin(AuxTable* const* h)
{
    if (*h == 0)
        return AuxIter(0, 0);
    U first = 0;
    while (first <= (*h)->SizeMask && AuxIter::E(*h, first).NextInChain == -2)
        first++;
    return AuxIter(h, first);
}

struct SoundTransform
{
    float Position, Left, Right;
};

// AuxStreamer: skip the source to a time, dropping what was queued.
// @0x142746480
bool FUN_142746480(void* self, float seconds)
{
    void* source = RawField<void*>(self, 0x40);
    if (source && RawField<bool (**)(void*, float)>(source, 0)[2](source, seconds))
    {
        RawField<unsigned>(self, 0x70) = 0;
        return true;
    }
    return false;
}

// SoundRenderer: master volume.
// @0x1427464c0
void FUN_1427464c0(void* self, float volume)
{
    void* group;
    if (reinterpret_cast<FMOD::System*>(RawField<void*>(self, 0x10))->getMasterChannelGroup(reinterpret_cast<FMOD::ChannelGroup**>(&group)) == 0)
        reinterpret_cast<FMOD::ChannelGroup*>(group)->setVolume(volume);
}

// Channel: pan.
// @0x142746500
void FUN_142746500(void* self, float pan)
{
    void* channel = RawField<void*>(self, 0x38);
    if (channel)
        reinterpret_cast<FMOD::Channel*>(channel)->setPan(pan);
}

// Channel: seek to a time, past the sample's leading latency.
// The sample's buffered latency in ms (0 without sample data), inlined in the exe.
static inline unsigned SampleLatencyMs(void* sample)
{
    if (sample)
    {
        void* data = RawField<void*>(sample, 0x38);
        if (data)
            return RawField<unsigned>(data, 0x1c) * 1000 / RawField<unsigned>(data, 0x14);
    }
    return 0;
}

// @0x142746510
void FUN_142746510(void* self, float seconds)
{
    unsigned ms = (unsigned)(long long)(seconds * 1000.0f);
    void* channel = RawField<void*>(self, 0x38);
    if (!channel)
        return;
    reinterpret_cast<FMOD::Channel*>(channel)->setPosition(SampleLatencyMs(RawField<void*>(self, 0x30)) + ms, 1);
}

// Aux channel: seek, then refill the stream from the new position.
// @0x142746560
void FUN_142746560(void* self, float seconds)
{
    ChannelLocker lock(RawLock(self, 0x70));
    void* sample = RawField<void*>(self, 0x30);
    if (sample && FUN_142746480(sample, seconds))
    {
        RawField<float>(self, 0x98) = seconds;
        RawField<U>(self, 0x58) = 0;
        RawField<U>(self, 0x60) = 0;
        RawField<U>(self, 0x48) = FUN_1425e3480();
        unsigned fill = RawField<unsigned>(sample, 0x6c);
        FUN_142745f50(sample);
        reinterpret_cast<FMOD::Channel*>(RawField<void*>(self, 0x38))->setPosition(fill, 4);
        RawField<char>(self, 0x69) = 0;
        RawField<U>(self, 0x60) = FilledMicros(sample);
    }
}

// Sample: seek the underlying stream to a time.
// @0x142746640
bool FUN_142746640(void* self, float seconds)
{
    void* data;
    if (!RawField<void*>(self, 0x30) || !(data = RawField<void*>(self, 0x28)))
        return false;
    unsigned seek = RawField<unsigned>(data, 0x1c);
    float frequency;
    reinterpret_cast<FMOD::Sound*>(RawField<void*>(self, 0x30))->getDefaults(&frequency, 0, 0, 0);
    return reinterpret_cast<FMOD::Sound*>(RawField<void*>(self, 0x30))->seekData((unsigned)(long long)(frequency * seconds) + seek) == 0;
}

// Channel: SetTransforms for channels with no envelope support.
// @0x1427466c0
void FUN_1427466c0(void*, const void*) {}

// Channel: SetTransforms. Installs the sync-point callback and adds one sync point per 0.1 s step of every segment
// of the envelope, each carrying the interpolated left/right levels.
// MS2-FUNCTIONAL: written from the exe's control flow.
// @0x1427466d0
void FUN_1427466d0(void* self, const U* transforms)
{
    const SoundTransform* t = (const SoundTransform*)transforms[0];
    U size = transforms[1];
    void* sample = RawField<void*>(self, 0x30);
    if (!size || !sample || !RawField<void*>(sample, 0x30))
        return;
    void* channel = RawField<void*>(self, 0x38);
    reinterpret_cast<FMOD::Channel*>(channel)->setCallback(reinterpret_cast<FMOD_CHANNEL_CALLBACK>((void*)&FUN_1427443c0));
    for (U i = 0; i < size; i++)
    {
        if (i == 0)
        {
            FUN_1427474d0(channel, &t[0]);
            continue;
        }
        const SoundTransform& a = t[i - 1];
        const SoundTransform& b = t[i];
        float span = a.Position - b.Position;
        float rightSlope = (a.Right - b.Right) / span;
        float leftSlope = (a.Left - b.Left) / span;
        float rightBase = a.Right - a.Position * rightSlope;
        float leftBase = a.Left - a.Position * leftSlope;
        bool last = false;
        for (unsigned step = 1; !last; step++)
        {
            float pos = (float)step * 0.1f + t[i - 1].Position;
            SoundTransform point;
            if (pos > t[i].Position)
            {
                point = t[i];
                last = true;
            }
            else
            {
                point.Position = pos;
                point.Left = pos * leftSlope + leftBase;
                point.Right = pos * rightSlope + rightBase;
            }
            void* sync = 0;
            if (reinterpret_cast<FMOD::Sound*>(RawField<void*>(sample, 0x30))->addSyncPoint((unsigned)(long long)(point.Position * 1000.0f), 1, "", reinterpret_cast<FMOD_SYNCPOINT**>(&sync)) == 0)
            {
                U key = (U)sync;
                NodeRef node = {&key, (void* const*)&point};
                FUN_142742b50(RawFieldPtr<U*>(self, 0x40), RawFieldPtr<U*>(self, 0x40), &node, RawKey8Hash(key));
            }
        }
    }
}

// Channel: volume.
// @0x142746a30
void FUN_142746a30(void* self, float volume)
{
    void* channel = RawField<void*>(self, 0x38);
    if (channel)
        reinterpret_cast<FMOD::Channel*>(channel)->setVolume(volume);
}

// Sample: Start. Plays the sound paused, delays it past the player's latency on the DSP clock, applies the seek,
// then wraps the channel.
// MS2-FUNCTIONAL: cl fuses the two pSoundData tests that the exe keeps apart, and the hi/lo DSP clock slots and
// the scount float sequence differ.
// @0x142746a40
void* FUN_142746a40(void* self, bool paused)
{
    if (RawField<void*>(self, 0x30))
    {
        unsigned latency = RawField<void*>(self, 0x38) ? RawField<unsigned>(RawField<void*>(self, 0x38), 0x1c) : 0;
        unsigned scount = RawField<void*>(self, 0x38) ? RawField<unsigned>(RawField<void*>(self, 0x38), 0x18) : 0;
        if (scount == 0)
            reinterpret_cast<FMOD::Sound*>(RawField<void*>(self, 0x30))->getLength(&scount, 2);

        float sample_rate;
        reinterpret_cast<FMOD::Sound*>(RawField<void*>(self, 0x30))->getDefaults(&sample_rate, 0, 0, 0);

        void* pchan;
        int r;
        r = reinterpret_cast<FMOD::System*>(RawField<void*>(RawField<char*>(self, 0x28), 0x10))->playSound(static_cast<FMOD_CHANNELINDEX>(-1), reinterpret_cast<FMOD::Sound*>(RawField<void*>(self, 0x30)), true, reinterpret_cast<FMOD::Channel**>(&pchan));
        if (r == 0)
        {
            unsigned hi = 0;
            unsigned lo = 0;
            r = reinterpret_cast<FMOD::System*>(RawField<void*>(RawField<char*>(self, 0x28), 0x10))->getDSPClock(&hi, &lo);
            scount = unsigned(scount * RawField<float>(RawField<char*>(self, 0x28), 0xf4) / sample_rate);
            lo += scount; // FMOD_64BIT_ADD
            hi += 0 + (lo < scount);
            r = reinterpret_cast<FMOD::Channel*>(pchan)->setDelay(static_cast<FMOD_DELAYTYPE>(2), hi, lo);
            if (latency > 0)
            {
                r = reinterpret_cast<FMOD::Channel*>(pchan)->setPosition(latency, 2);
                if (r == 0)
                    r = reinterpret_cast<FMOD::Channel*>(pchan)->setPaused(paused);
            }
        }
        if (r != 0)
            return 0;

        void* mem = Memory::Alloc(0x48);
        return mem ? FUN_142742fb0((std::uint64_t*)mem, RawField<char*>(self, 0x28), (std::uint64_t)self, pchan) : 0;
    }
    return 0;
}

// AuxChannel ctor.
static __forceinline char* ConstructAuxChannel(char* c, void* self, void* channel)
{
    FUN_142742fb0((std::uint64_t*)c, RawField<char*>(self, 0x28), (std::uint64_t)self, channel);
    RawField<void*>(c, 0) = DAT_1431bee78;
    RawField<void*>(c, 0x10) = DAT_1431beef0;
    RawField<U>(c, 0x48) = FUN_1425e3480();
    RawField<char>(c, 0x69) = 0;
    reinterpret_cast<Scaleform::Lock*>(c + 0x70)->Lock::Lock(0);
    RawField<unsigned>(c, 0x98) = 0;
    _InterlockedExchangeAdd(RawFieldPtr<volatile long>(self, 8), 1);
    RawField<U>(c, 0x58) = 0;
    RawField<U>(c, 0x60) = 0;
    reinterpret_cast<FMOD::Channel*>(RawField<void*>(c, 0x38))->getPaused(RawFieldPtr<bool>(c, 0x68));
    if (RawField<char>(c, 0x68))
        RawField<U>(c, 0x50) = RawField<U>(c, 0x48);
    else
    {
        FUN_142745f50(self);
        RawField<U>(c, 0x48) = FUN_1425e3480();
        RawField<U>(c, 0x60) = FilledMicros(self);
    }
    return c;
}

// AuxStreamer: Start. Plays the stream sound, sizes the 300 ms staging buffer and wraps the channel in an aux
// channel that tracks played time against what the streamer has queued.
// @0x142746bd0
void* FUN_142746bd0(void* self, bool paused)
{
    void* sound = RawField<void*>(self, 0x30);
    if (!sound)
        return 0;
    void* channel;
    if (reinterpret_cast<FMOD::System*>(RawField<void*>(RawField<char*>(self, 0x28), 0x10))->playSound(static_cast<FMOD_CHANNELINDEX>(-2), reinterpret_cast<FMOD::Sound*>(sound), paused, reinterpret_cast<FMOD::Channel**>(&channel)))
        return 0;
    RawField<unsigned>(self, 0x60) = RawField<unsigned>(self, 0x4c) * 300 / 1000 * (RawField<unsigned>(self, 0x50) >> 3) *
                                     RawField<unsigned>(self, 0x48);
    if (RawField<void*>(self, 0x58))
        Memory::Free(RawField<void*>(self, 0x58));
    RawField<void*>(self, 0x58) = Memory::Alloc(RawField<unsigned>(self, 0x60));
    char* mem = (char*)Memory::Alloc(0xa0);
    char* c = mem ? ConstructAuxChannel(mem, self, channel) : 0;
    FUN_142744070(RawField<char*>(self, 0x28), c);
    return c;
}

} // namespace GFx
} // namespace Scaleform

using namespace Scaleform;
using namespace Scaleform::GFx;

// Channel: Stop.
// @0x142746d70
extern "C" void FUN_142746d70(void* self)
{
    void* channel = RawField<void*>(self, 0x38);
    if (channel)
    {
        reinterpret_cast<FMOD::Channel*>(channel)->stop();
        RawField<void*>(self, 0x38) = 0;
    }
}

namespace Scaleform { namespace GFx {

// Aux channel: Stop. Drops the channel from the renderer's per-streamer list (and the streamer's entry once its
// list is empty), shuts the update thread down when no aux streams remain, then stops and releases the channel.
// SoundRendererFMODImpl::DetachAuxStreamer, inlined into Stop.
static __forceinline void DetachAuxStreamer(char* player, void* pchan)
{
    if (!pchan || !RawField<void*>(pchan, 0x30))
        return;
    void* psample = RawField<void*>(pchan, 0x30);
    if (!RawField<void*>(psample, 0x40))
        return;

    EnterCriticalSection(RawLock(player, 0x80));
    U key = RawField<U>(psample, 0x40);
    U* pcont = (U*)FindAudioRequestEntry(RawFieldPtr<void*>(player, 0xa8), (const unsigned char*)&key);
    bool found = false;
    if (pcont)
    {
        U nulls = 0;
        for (U i = 0; i < pcont[1]; ++i)
        {
            if (((void**)pcont[0])[i] == pchan)
            {
                ((void**)pcont[0])[i] = 0;
                found = true;
            }
            if (((void**)pcont[0])[i] == 0)
                nulls++;
        }
        if (nulls == pcont[1])
        {
            U key2 = RawField<U>(psample, 0x40);
            FUN_142742830(RawFieldPtr<U*>(player, 0xa8), &key2);
        }
        U* set = RawField<U*>(player, 0xa8);
        if ((!set || set[0] == 0) && RawField<char>(player, 0xf1) && RawField<void*>(player, 0x18))
        {
            *(volatile bool*)(player + 0x78) = true; // StopThread
            // pUpdateThread = NULL; the exe reloads it after the StopThread store
            if (void* thread = *(void* volatile*)(player + 0x18))
                FUN_14257dcb0(thread);
            RawField<void*>(player, 0x18) = 0;
            reinterpret_cast<Scaleform::Event*>(player + 0x20)->PulseEvent();
        }
    }
    if (!found)
        pchan = 0;

    LeaveCriticalSection(RawLock(player, 0x80));
    if (pchan)
    {
        reinterpret_cast<FMOD::Channel*>(RawField<void*>(pchan, 0x38))->stop();
        FUN_14257dcb0(pchan);
    }
}

// @0x142746da0
void FUN_142746da0(void* self)
{
    if (RawField<char*>(self, 0x28))
        DetachAuxStreamer(RawField<char*>(self, 0x28), self);
    RawField<U>(self, 0x50) = FUN_1425e3480();
}

// Aux channel: Update. Refills the stream when under a third queued, zero-fills it while starving; returns the
// seconds until the next update is due.
// @0x142746f10
float FUN_142746f10(void* channel)
{
    char* self = (char*)channel;
    ChannelLocker lock(RawLock(self, 0x70));
    if (!RawField<bool (**)(void*)>(self, 0)[5](self))
        return 0.5f;
    if (RawField<char>(self, 0x68))
        return 0.1f;
    void* s = RawField<void*>(self, 0x30);
    U filled = FilledMicros(s);
    U now = FUN_1425e3480();
    U pos = RawField<U>(self, 0x58) + (now - RawField<U>(self, 0x48));
    char starving = RawField<char>(self, 0x69);
    if (!starving && pos > filled)
    {
        RawField<char>(self, 0x69) = 1;
        starving = 1;
        RawField<U>(self, 0x50) = now;
        RawField<U>(self, 0x58) = filled;
    }
    unsigned dist = 0;
    if (!starving)
    {
        unsigned fmodpos = 0;
        if (reinterpret_cast<FMOD::Channel*>(RawField<void*>(self, 0x38))->getPosition(&fmodpos, 4))
            return 0;
        unsigned fill = RawField<unsigned>(s, 0x6c);
        dist = fmodpos > fill ? RawField<unsigned>(s, 0x64) - fmodpos + fill : fill - fmodpos;
    }
    if (dist < RawField<unsigned>(s, 0x60) / 3)
    {
        unsigned got = 0;
        if (RawField<char>(self, 0x69))
        {
            RawField<unsigned>(s, 0x6c) = 0;
            got = FUN_142745f50(s);
            if (got > 0)
            {
                reinterpret_cast<FMOD::Channel*>(RawField<void*>(self, 0x38))->setPosition(0, 4);
                RawField<char>(self, 0x69) = 0;
                RawField<U>(self, 0x48) = FUN_1425e3480();
                pos = RawField<U>(self, 0x58);
            }
            else
            {
                // ClearSoundBuffer
                void *p1, *p2;
                unsigned l1, l2;
                if (reinterpret_cast<FMOD::Sound*>(RawField<void*>(s, 0x30))->lock(0, RawField<unsigned>(s, 0x64), &p1, &p2, &l1, &l2) == 0)
                {
                    memset(p1, 0, l1);
                    reinterpret_cast<FMOD::Sound*>(RawField<void*>(s, 0x30))->unlock(p1, p2, l1, l2);
                }
                return 0.02f;
            }
        }
        else
            got = FUN_142745f50(s);
        if (got > 0)
        {
            RawField<U>(self, 0x60) = FilledMicros(s);
            float t = (RawField<U>(self, 0x60) - pos) / 1000000.f * 2 / 3;
            return t < 0.02f ? 0.02f : t;
        }
        return 0.02f;
    }
    else
    {
        float t = (RawField<U>(self, 0x60) - pos) / 1000000.f / 2;
        return t < 0.02f ? 0.02f : t;
    }
}

// SoundRenderer: Update.
// @0x1427471a0
float FUN_1427471a0(void* self)
{
    float wait = 0.5f;
    if (!RawField<void*>(self, 0x18))
        wait = FUN_1427471f0(self);
    if (RawField<char>(self, 0xf0))
        reinterpret_cast<FMOD::System*>(RawField<void*>(self, 0x10))->update();
    return wait;
}

// UpdateAuxStreams; the update thread inlines it.
static __forceinline float UpdateAuxStreams(void* self)
{
    float nextcall = 0.5f;
    AuxTable* const* streamers = RawFieldPtr<AuxTable*>(self, 0xa8);
    for (AuxIter it = AuxBegin(streamers); it != AuxIter(0, 0); ++it)
    {
        AuxEntry& cont = *it;
        for (U i = 0; i < cont.Size; ++i)
        {
            void* pchan = cont.Data[i];
            if (pchan)
            {
                float t = FUN_142746f10(pchan);
                if (t < nextcall) nextcall = t;
            }
        }
    }
    return nextcall;
}

// SoundRenderer: update every aux channel; the soonest next-update time.
// @0x1427471f0
__declspec(noinline) float FUN_1427471f0(void* self)
{
    return UpdateAuxStreams(self);
}

// SoundRenderer: the aux-stream update thread.
// @0x142747310
int FUN_142747310(void* thread, void* h)
{
    char* pRenderer = (char*)h;
    unsigned wait_time = 2000;
    while (1)
    {
        reinterpret_cast<Scaleform::Event*>(pRenderer + 0x20)->Wait(wait_time);
        if (*(volatile bool*)(pRenderer + 0x78)) // StopThread
            break;
        ChannelLocker lock(RawLock(pRenderer, 0x80));
        wait_time = (unsigned)(UpdateAuxStreams(pRenderer) * 1000);
    }
    return 0;
}

// Channel callback: a sync point was reached; apply its left/right levels as volume and pan.
// @0x1427474d0
void FUN_1427474d0(void* channel, const void* transform)
{
    const SoundTransform* t = (const SoundTransform*)transform;
    // The sum is built in place: (Left + Right) / 2 has cl load Right first.
    float sum = t->Left;
    sum += t->Right;
    reinterpret_cast<FMOD::Channel*>(channel)->setVolume(sum / 2);
    float diff = t->Left - t->Right;
    float pan  = (diff >= 0) ? diff : -diff; // Alg::Abs
    if (t->Left > t->Right)
        pan *= -1;
    reinterpret_cast<FMOD::Channel*>(channel)->setPan(pan);
}

} // namespace GFx
} // namespace Scaleform

// HashSet<SyncPoint*, Transform> (stride 0x28): setRawCapacity.
// MS2-FUNCTIONAL: the exe inlines the add; here it goes through FUN_142742b50.
// @0x142747530
extern "C" void FUN_142747530(U** self, void* heap, U n)
{
    if (n == 0)
    {
        RawClearPlainSet((U*)self, 0x28);
        return;
    }
    U size = n < 8 ? 8 : (U)1 << (Alg::UpperBit(n - 1) + 1);
    U* table = (U*)Memory::Alloc(size * 0x28 + 0x10, AllocInfo(2, 0, 0));
    table[0] = 0;
    table[1] = size - 1;
    for (U i = 0; i < size; i++)
        *(SPInt*)RawEntry(table, i, 0x28) = -2;
    if (*self)
    {
        U last = (*self)[1];
        for (U i = 0; i <= last; i++)
        {
            char* e = RawEntry(*self, i, 0x28);
            if (*(SPInt*)e == -2)
                continue;
            NodeRef node = {RawFieldPtr<const U>(e, 0x10), RawFieldPtr<void* const>(e, 0x18)};
            FUN_142742b50(&table, heap, &node, RawKey8Hash(RawField<U>(e, 0x10)));
            *(SPInt*)e = -2;
        }
        Memory::Free(*self);
    }
    *self = table;
}

// HashSet<Streamer*, ArrayPOD<Channel*>> (stride 0x30): setRawCapacity.
// MS2-FUNCTIONAL: the exe inlines the add; here it goes through FUN_1427429d0 (which copies the array).
// @0x1427478c0
extern "C" void FUN_1427478c0(U** self, void* heap, U n)
{
    if (n == 0)
    {
        if (!*self)
            return;
        U last = (*self)[1];
        for (U i = 0; i <= last; i++)
        {
            char* e = RawEntry(*self, i, 0x30);
            if (*(SPInt*)e == -2)
                continue;
            if (RawField<void*>(e, 0x18))
                Memory::Free(RawField<void*>(e, 0x18));
            *(SPInt*)e = -2;
        }
        Memory::Free(*self);
        *self = 0;
        return;
    }
    U size = n < 8 ? 8 : (U)1 << (Alg::UpperBit(n - 1) + 1);
    U* table = (U*)Memory::Alloc(size * 0x30 + 0x10, AllocInfo(2, 0, 0));
    table[0] = 0;
    table[1] = size - 1;
    for (U i = 0; i < size; i++)
        *(SPInt*)RawEntry(table, i, 0x30) = -2;
    if (*self)
    {
        U last = (*self)[1];
        for (U i = 0; i <= last; i++)
        {
            char* e = RawEntry(*self, i, 0x30);
            if (*(SPInt*)e == -2)
                continue;
            FUN_1427429d0(&table, heap, RawFieldPtr<const U>(e, 0x10), RawKey8Hash(RawField<U>(e, 0x10)));
            if (RawField<void*>(e, 0x18))
                Memory::Free(RawField<void*>(e, 0x18));
            *(SPInt*)e = -2;
        }
        Memory::Free(*self);
    }
    *self = table;
}

// SoundRenderer: finalize. Stops the update thread, then lets every live channel unlink itself from the list.
// MS2-FUNCTIONAL: Lock::Locker spelled as Enter/LeaveCriticalSection.
// @0x142747b30
extern "C" void FUN_142747b30(void* self)
{
    char* r = (char*)self;
    if (RawField<void*>(r, 0x18))
    {
        RawField<char>(r, 0x78) = 1;
        reinterpret_cast<Scaleform::Event*>(r + 0x20)->PulseEvent();
        reinterpret_cast<Scaleform::Waitable*>(RawField<void*>(r, 0x18))->Wait(0xffffffff);
    }
    EnterCriticalSection(RawLock(r, 0xc8));
    while (RawField<char*>(r, 0xc0) != r + 0xb0)
    {
        char* first = RawField<char*>(r, 0xc0);
        (*(void (**)(void*))(RawField<char*>(first, 0) + 8))(first);
    }
    LeaveCriticalSection(RawLock(r, 0xc8));
}
