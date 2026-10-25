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

// FMOD (the exe's statically linked fmodex, called through its import thunks)
extern "C" int FUN_1428d8e9c(void* system, void** group);                                  // System::getMasterChannelGroup
extern "C" int FUN_1428d8f20(void* group, float volume);                                   // ChannelGroup::setVolume
extern "C" int FUN_1428d8ee4(void* channel, float pan);                                    // Channel::setPan
extern "C" int FUN_1428d8ef6(void* channel, unsigned position, unsigned unit);             // Channel::setPosition
extern "C" int FUN_1428d8eb4(void* sound, float* frequency, float* volume, float* pan, int* priority); // Sound::getDefaults
extern "C" int FUN_1428d8ec6(void* sound, unsigned pcm);                                   // Sound::seekData
extern "C" int FUN_1428d8efc(void* channel, void* callback);                               // Channel::setCallback
extern "C" int FUN_1428d8ed2(void* sound, unsigned offset, unsigned unit, const char* name, void** point); // Sound::addSyncPoint
extern "C" int FUN_1428d8ea2(void* system, unsigned* hi, unsigned* lo);                    // System::getDSPClock
extern "C" int FUN_1428d8ef0(void* channel, int type, unsigned hi, unsigned lo);           // Channel::setDelay
extern "C" int FUN_1428d8ed8(void* channel, bool paused);                                  // Channel::setPaused
extern "C" int FUN_1428d8ea8(void* sound, unsigned offset, unsigned length, void** p1, void** p2, unsigned* l1,
                             unsigned* l2);                                                // Sound::lock
extern "C" int FUN_1428d8eae(void* sound, void* p1, void* p2, unsigned l1, unsigned l2);  // Sound::unlock
extern "C" int FUN_142303a35(void* system, int index, void* sound, bool paused, void** channel); // System::playSound
extern "C" int FUN_142303a4d(void* sound, unsigned* length, unsigned unit);                // Sound::getLength
extern "C" int FUN_142303a65(void* channel);                                               // Channel::stop
extern "C" int FUN_142303a6b(void* channel, bool* paused);                                 // Channel::getPaused
extern "C" int FUN_142303a71(void* channel, float volume);                                 // Channel::setVolume
extern "C" int FUN_142303a83(void* channel, unsigned* position, unsigned unit);            // Channel::getPosition
extern "C" int FUN_142303a11(void* system);                                                // System::update

extern "C" char DAT_1431bee78[];   // aux-streamer channel vftable
extern "C" char DAT_1431beef0[];   // its second base

std::uint64_t* FUN_142742fb0(std::uint64_t* object, void* player, std::uint64_t userData, void* channel); // channel ctor

extern "C" void FUN_142746d70(void* self);
extern "C" void FUN_142747530(Scaleform::GFx::U** self, void* heap, Scaleform::GFx::U n);
extern "C" void FUN_1427478c0(Scaleform::GFx::U** self, void* heap, Scaleform::GFx::U n);
extern "C" void FUN_142747b30(void* self);

namespace Scaleform {
unsigned FUN_142745f50(void* streamer);   // AuxStreamer ReadAndFill: bytes queued
char FUN_1422fe440(UPInt v);              // Alg::UpperBit

namespace GFx {

UInt64 FUN_1425e3480();                                     // Timer::GetProfileTicks
void FUN_14258d030(void* lock, unsigned spinCount);         // Lock::Lock
void FUN_142583d50(void* event);                            // Event::PulseEvent
bool FUN_142584540(void* event, unsigned ms);               // Event::Wait
bool FUN_1425845e0(void* waitable, unsigned ms);            // Waitable::Wait
void* FUN_142745630(void** set, const unsigned char* key);  // sync-point set: the value at key
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
    void* group = 0;
    if (FUN_1428d8e9c(RawField<void*>(self, 0x10), &group) == 0)
        FUN_1428d8f20(group, volume);
}

// Channel: pan.
// @0x142746500
void FUN_142746500(void* self, float pan)
{
    void* channel = RawField<void*>(self, 0x38);
    if (channel)
        FUN_1428d8ee4(channel, pan);
}

// Channel: seek to a time, past the sample's leading latency.
// @0x142746510
void FUN_142746510(void* self, float seconds)
{
    unsigned ms = (unsigned)(long long)(seconds * 1000.0f);
    void* channel = RawField<void*>(self, 0x38);
    if (!channel)
        return;
    unsigned latency = 0;
    void* sample = RawField<void*>(self, 0x30);
    if (sample)
    {
        void* data = RawField<void*>(sample, 0x38);
        if (data)
            latency = RawField<unsigned>(data, 0x1c) * 1000 / RawField<unsigned>(data, 0x14);
    }
    FUN_1428d8ef6(channel, latency + ms, 1);
}

// Aux channel: seek, then refill the stream from the new position.
// MS2-FUNCTIONAL: Lock::Locker spelled as Enter/LeaveCriticalSection.
// @0x142746560
void FUN_142746560(void* self, float seconds)
{
    EnterCriticalSection(RawLock(self, 0x70));
    void* sample = RawField<void*>(self, 0x30);
    if (sample && FUN_142746480(sample, seconds))
    {
        RawField<float>(self, 0x98) = seconds;
        RawField<U>(self, 0x58) = 0;
        RawField<U>(self, 0x60) = 0;
        RawField<U>(self, 0x48) = FUN_1425e3480();
        unsigned fill = RawField<unsigned>(sample, 0x6c);
        FUN_142745f50(sample);
        FUN_1428d8ef6(RawField<void*>(self, 0x38), fill, 4);
        RawField<char>(self, 0x69) = 0;
        RawField<U>(self, 0x60) = FilledMicros(sample);
    }
    LeaveCriticalSection(RawLock(self, 0x70));
}

// Sample: seek the underlying stream to a time.
// @0x142746640
bool FUN_142746640(void* self, float seconds)
{
    void* sound = RawField<void*>(self, 0x30);
    void* data = RawField<void*>(self, 0x28);
    if (!sound || !data)
        return false;
    unsigned seek = RawField<unsigned>(data, 0x1c);
    float frequency = 0;
    FUN_1428d8eb4(sound, &frequency, 0, 0, 0);
    return FUN_1428d8ec6(sound, (unsigned)(long long)(frequency * seconds) + seek) == 0;
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
    FUN_1428d8efc(channel, (void*)&FUN_1427443c0);
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
            if (FUN_1428d8ed2(RawField<void*>(sample, 0x30), (unsigned)(long long)(point.Position * 1000.0f), 1, "",
                              &sync) == 0)
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
        FUN_142303a71(channel, volume);
}

// Sample: Start. Plays the sound paused, delays it past the player's latency on the DSP clock, applies the seek,
// then wraps the channel.
// MS2-FUNCTIONAL: written from the exe's control flow.
// @0x142746a40
void* FUN_142746a40(void* self, bool paused)
{
    void* sound = RawField<void*>(self, 0x30);
    if (!sound)
        return 0;
    void* data = RawField<void*>(self, 0x38);
    unsigned seek = data ? RawField<unsigned>(data, 0x1c) : 0;
    unsigned length = data ? RawField<unsigned>(data, 0x18) : 0;
    if (!length)
        FUN_142303a4d(sound, &length, 2);
    float frequency = 0;
    FUN_1428d8eb4(sound, &frequency, 0, 0, 0);
    char* player = RawField<char*>(self, 0x28);
    void* system = RawField<void*>(player, 0x10);
    void* channel = 0;
    if (FUN_142303a35(system, -1, sound, true, &channel))
        return 0;
    unsigned hi = 0, lo = 0;
    FUN_1428d8ea2(system, &hi, &lo);
    unsigned delay = (unsigned)(long long)((float)length * RawField<float>(player, 0xf4) / frequency);
    lo += delay;
    if (lo < delay)
        hi++;
    int r = FUN_1428d8ef0(channel, 2, hi, lo);
    if (seek)
    {
        if (FUN_1428d8ef6(channel, seek, 2))
            return 0;
        r = FUN_1428d8ed8(channel, paused);
    }
    if (r)
        return 0;
    void* mem = Memory::Alloc(0x48);
    return mem ? FUN_142742fb0((std::uint64_t*)mem, player, (std::uint64_t)self, channel) : 0;
}

// AuxStreamer: Start. Plays the stream sound, sizes the 300 ms staging buffer and wraps the channel in an aux
// channel that tracks played time against what the streamer has queued.
// MS2-FUNCTIONAL: written from the exe's control flow.
// @0x142746bd0
void* FUN_142746bd0(void* self, bool paused)
{
    void* sound = RawField<void*>(self, 0x30);
    if (!sound)
        return 0;
    char* player = RawField<char*>(self, 0x28);
    void* channel = 0;
    if (FUN_142303a35(RawField<void*>(player, 0x10), -2, sound, paused, &channel))
        return 0;
    RawField<unsigned>(self, 0x60) = RawField<unsigned>(self, 0x4c) * 300 / 1000 * (RawField<unsigned>(self, 0x50) >> 3) *
                                     RawField<unsigned>(self, 0x48);
    if (RawField<void*>(self, 0x58))
        Memory::Free(RawField<void*>(self, 0x58));
    RawField<void*>(self, 0x58) = Memory::Alloc(RawField<unsigned>(self, 0x60));
    char* c = (char*)Memory::Alloc(0xa0);
    if (c)
    {
        FUN_142742fb0((std::uint64_t*)c, player, (std::uint64_t)self, channel);
        RawField<void*>(c, 0) = DAT_1431bee78;
        RawField<void*>(c, 0x10) = DAT_1431beef0;
        RawField<U>(c, 0x48) = FUN_1425e3480();
        RawField<char>(c, 0x69) = 0;
        FUN_14258d030(c + 0x70, 0);
        RawField<unsigned>(c, 0x98) = 0;
        _InterlockedExchangeAdd(RawFieldPtr<volatile long>(self, 8), 1);
        RawField<U>(c, 0x58) = 0;
        RawField<U>(c, 0x60) = 0;
        FUN_142303a6b(RawField<void*>(c, 0x38), RawFieldPtr<bool>(c, 0x68));
        if (RawField<char>(c, 0x68))
            RawField<U>(c, 0x50) = RawField<U>(c, 0x48);
        else
        {
            FUN_142745f50(self);
            RawField<U>(c, 0x48) = FUN_1425e3480();
            RawField<U>(c, 0x60) = FilledMicros(self);
        }
    }
    FUN_142744070(player, c);
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
        FUN_142303a65(channel);
        RawField<void*>(self, 0x38) = 0;
    }
}

namespace Scaleform { namespace GFx {

// Aux channel: Stop. Drops the channel from the renderer's per-streamer list (and the streamer's entry once its
// list is empty), shuts the update thread down when no aux streams remain, then stops and releases the channel.
// MS2-FUNCTIONAL: Lock::Locker spelled as Enter/LeaveCriticalSection.
// @0x142746da0
void FUN_142746da0(void* self)
{
    char* player = RawField<char*>(self, 0x28);
    void* sample = RawField<void*>(self, 0x30);
    if (player && sample && RawField<void*>(sample, 0x40))
    {
        EnterCriticalSection(RawLock(player, 0x80));
        U key = RawField<U>(sample, 0x40);
        U* list = (U*)FUN_142745630(RawFieldPtr<void*>(player, 0xa8), (const unsigned char*)&key);
        bool found = false;
        if (list)
        {
            U empty = 0;
            for (U i = 0; i < list[1]; i++)
            {
                void** data = (void**)list[0];
                if (data[i] == self)
                {
                    data[i] = 0;
                    found = true;
                }
                if (((void**)list[0])[i] == 0)
                    empty++;
            }
            if (empty == list[1])
            {
                U key2 = RawField<U>(sample, 0x40);
                FUN_142742830(RawFieldPtr<U*>(player, 0xa8), &key2);
            }
            U* set = RawField<U*>(player, 0xa8);
            if ((!set || set[0] == 0) && RawField<char>(player, 0xf1) && RawField<void*>(player, 0x18))
            {
                RawField<char>(player, 0x78) = 1;
                if (RawField<void*>(player, 0x18))
                    FUN_14257dcb0(RawField<void*>(player, 0x18));
                RawField<void*>(player, 0x18) = 0;
                FUN_142583d50(player + 0x20);
            }
        }
        LeaveCriticalSection(RawLock(player, 0x80));
        if (found)
        {
            FUN_142303a65(RawField<void*>(self, 0x38));
            FUN_14257dcb0(self);
        }
    }
    RawField<U>(self, 0x50) = FUN_1425e3480();
}

static float AuxUpdateLocked(char* self)
{
    if (!RawField<bool (**)(void*)>(self, 0)[5](self))
        return 0.5f;
    if (RawField<char>(self, 0x68))
        return 0.1f;
    void* s = RawField<void*>(self, 0x30);
    U filled = FilledMicros(s);
    U now = FUN_1425e3480();
    U played = RawField<U>(self, 0x58) - RawField<U>(self, 0x48) + now;
    char starving = RawField<char>(self, 0x69);
    if (!starving && played > filled)
    {
        RawField<char>(self, 0x69) = 1;
        starving = 1;
        RawField<U>(self, 0x50) = now;
        RawField<U>(self, 0x58) = filled;
    }
    unsigned queued = 0;
    if (!starving)
    {
        unsigned pos = 0;
        if (FUN_142303a83(RawField<void*>(self, 0x38), &pos, 4))
            return 0;
        unsigned fill = RawField<unsigned>(s, 0x6c);
        queued = pos > fill ? RawField<unsigned>(s, 0x64) - pos + fill : fill - pos;
    }
    if (queued >= RawField<unsigned>(s, 0x60) / 3)
        return AtLeast(0.02f, (float)(RawField<U>(self, 0x60) - played) / 1000000.0f * 0.5f);
    unsigned read;
    if (RawField<char>(self, 0x69))
    {
        RawField<unsigned>(s, 0x6c) = 0;
        read = FUN_142745f50(s);
        if (read)
        {
            FUN_1428d8ef6(RawField<void*>(self, 0x38), 0, 4);
            RawField<char>(self, 0x69) = 0;
            RawField<U>(self, 0x48) = FUN_1425e3480();
            played = RawField<U>(self, 0x58);
        }
        else
        {
            void *p1, *p2;
            unsigned l1, l2;
            void* sound = RawField<void*>(s, 0x30);
            if (FUN_1428d8ea8(sound, 0, RawField<unsigned>(s, 0x64), &p1, &p2, &l1, &l2) == 0)
            {
                memset(p1, 0, l1);
                FUN_1428d8eae(sound, p1, p2, l1, l2);
            }
            return 0.02f;
        }
    }
    else
        read = FUN_142745f50(s);
    if (!read)
        return 0.02f;
    RawField<U>(self, 0x60) = FilledMicros(s);
    float x = (float)(RawField<U>(self, 0x60) - played) / 1000000.0f;
    return AtLeast(0.02f, (x + x) / 3.0f);
}

// Aux channel: Update. Refills the stream when under a third queued, zero-fills it while starving; returns the
// seconds until the next update is due.
// MS2-FUNCTIONAL: Lock::Locker spelled as Enter/LeaveCriticalSection; the body is split into a helper.
// @0x142746f10
float FUN_142746f10(void* self)
{
    EnterCriticalSection(RawLock(self, 0x70));
    float wait = AuxUpdateLocked((char*)self);
    LeaveCriticalSection(RawLock(self, 0x70));
    return wait;
}

// SoundRenderer: Update.
// @0x1427471a0
float FUN_1427471a0(void* self)
{
    float wait = 0.5f;
    if (!RawField<void*>(self, 0x18))
        wait = FUN_1427471f0(self);
    if (RawField<char>(self, 0xf0))
        FUN_142303a11(RawField<void*>(self, 0x10));
    return wait;
}

// SoundRenderer: update every aux channel; the soonest next-update time.
// @0x1427471f0
float FUN_1427471f0(void* self)
{
    float wait = 0.5f;
    U** set = RawFieldPtr<U*>(self, 0xa8);
    for (U i = 0; *set && i <= (*set)[1]; i++)
    {
        char* e = RawEntry(*set, i, 0x30);
        if (*(SPInt*)e == -2)
            continue;
        for (U j = 0; j < RawField<U>(RawEntry(*set, i, 0x30), 0x20); j++)
        {
            void* channel = RawField<void**>(RawEntry(*set, i, 0x30), 0x18)[j];
            if (channel)
            {
                float t = FUN_142746f10(channel);
                wait = t < wait ? t : wait;
            }
        }
    }
    return wait;
}

// SoundRenderer: the aux-stream update thread.
// MS2-FUNCTIONAL: the exe inlines FUN_1427471f0; Lock::Locker spelled as Enter/LeaveCriticalSection.
// @0x142747310
int FUN_142747310(void* thread, void* renderer)
{
    char* r = (char*)renderer;
    FUN_142584540(r + 0x20, 2000);
    while (!RawField<char>(r, 0x78))
    {
        EnterCriticalSection(RawLock(r, 0x80));
        float wait = FUN_1427471f0(r);
        LeaveCriticalSection(RawLock(r, 0x80));
        FUN_142584540(r + 0x20, (unsigned)(long long)(wait * 1000.0f));
    }
    return 0;
}

// Channel callback: a sync point was reached; apply its left/right levels as volume and pan.
// @0x1427474d0
void FUN_1427474d0(void* channel, const void* transform)
{
    const SoundTransform* t = (const SoundTransform*)transform;
    FUN_142303a71(channel, (t->Left + t->Right) * 0.5f);
    float pan = fabsf(t->Left - t->Right);
    if (t->Left > t->Right)
        pan *= -1.0f;
    FUN_1428d8ee4(channel, pan);
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
    U size = n < 8 ? 8 : (U)1 << (FUN_1422fe440(n - 1) + 1);
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
    U size = n < 8 ? 8 : (U)1 << (FUN_1422fe440(n - 1) + 1);
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
        FUN_142583d50(r + 0x20);
        FUN_1425845e0(RawField<void*>(r, 0x18), 0xffffffff);
    }
    EnterCriticalSection(RawLock(r, 0xc8));
    while (RawField<char*>(r, 0xc0) != r + 0xb0)
    {
        char* first = RawField<char*>(r, 0xc0);
        (*(void (**)(void*))(RawField<char*>(first, 0) + 8))(first);
    }
    LeaveCriticalSection(RawLock(r, 0xc8));
}
