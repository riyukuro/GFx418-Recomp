// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_22
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142568420-0x1425686b0 .text$mn
// MS2-RANGE: 0x142675560-0x142678210 .text$mn
// MS2-RANGE: 0x142685f00-0x142688b70 .text$mn
// MS2-RANGE: 0x1426899e0-0x142690d10 .text$mn
// MS2-RANGE: 0x142744560-0x142746480 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/kernel/sf_array.h"
#include "ms2/scaleform/include/kernel/sf_msgformat.h"
#include "ms2/scaleform/include/kernel/sf_string.h"
#include "ms2/scaleform/kernel/sf_memitem.h"
#include "ms2/scaleform/kernel/sf_log.h"
#include "ms2/scaleform/include/kernel/sf_threads.h"
#include "ms2/scaleform/include/gfx/gfx_rendertree.h"
#include "hook/ms2hook.h"
#include <cstdint>
#include <cstring>
#include <new>

extern "C" void FUN_1426906b0(void*, void*, std::size_t);
extern "C" void FUN_142747530(void*, void*, std::size_t);
extern "C" void FUN_1427478c0(void*, void*, std::size_t);
extern "C" void FUN_142585f70(void*, int);
extern "C" void* DAT_143b15f60;
extern "C" void FUN_14268ef30(void*, void*, unsigned);
extern "C" void FUN_14268f8f0(void*, void*, unsigned);
extern "C" void FUN_1426869a0(void*, void*, const void*, std::uint64_t);
extern "C" void FUN_1426867f0(void*, void*, void*, std::uint64_t);
extern "C" void FUN_142690a20(void*, void*, std::int64_t);
MS2_GLOBAL(0x1431921e0, void*, AS3TextRecordVtable);
MS2_GLOBAL(0x1431921b0, void*, AS3MovieImageDataVtable);
MS2_GLOBAL(0x143192170, void*, AS3MovieImageStringSetVtable);
MS2_GLOBAL(0x143192190, void*, AS3MovieImageValueSetVtable);
MS2_GLOBAL(0x1431921a0, void*, AS3MovieImageNameSetVtable);
MS2_GLOBAL(0x143192180, void*, AS3MovieImageTreeVtable);
MS2_GLOBAL(0x1431921d0, void*, AS3MovieResourceDataVtable);
MS2_GLOBAL(0x143192160, void*, AS3MovieMemoryItemVtable);
MS2_GLOBAL(0x1431bede8, void*, AS3AudioEventVtable);
MS2_GLOBAL(0x1431bec40, void*, AS3AudioListNodeVtable);
MS2_GLOBAL(0x1431bed18, void*, AS3SoundRequestVtable);
MS2_GLOBAL(0x1431bed50, void*, AS3SoundRequestNodeVtable);
MS2_GLOBAL(0x1431bef00, void*, AS3BufferedRequestVtable);
MS2_GLOBAL(0x1431bef38, void*, AS3BufferedRequestNodeVtable);
MS2_GLOBAL(0x142d175c8, float, ImageViewportScale);
MS2_GLOBAL(0x142d175cc, float, ImageViewportBias);
MS2_GLOBAL(0x14318da30, std::uint32_t[4], ImageViewportColor);
MS2_GLOBAL(0x14318ea74, float, ImageViewportOrigin);
MS2_GLOBAL(0x14318f040, void*, MovieImageInfoVtable);
MS2_GLOBAL(0x14318f048, void*, AS3MovieMarkerVtable);
MS2_GLOBAL(0x14318f020, void*, AS3TextValueRecordVtable);
MS2_GLOBAL(0x14318f030, void*, AS3MovieViewValueVtable);
MS2_GLOBAL(0x1431921c0, void*, AS3MovieImageExtraVtable);
extern "C" void FUN_14268cd80(void*, void*, unsigned);
extern "C" void FUN_14268c510(void*, void*, unsigned);
extern "C" void FUN_14268d2b0(void*, void*, unsigned);
extern "C" void FUN_14268c930(void*, void*, unsigned);
extern "C" void FUN_14268cfe0(void*, void*, unsigned);
extern "C" void* FUN_142686ae0(void*);
extern "C" void* FUN_142686d30(void*);
extern "C" void FUN_1426240f0(void*, void*, std::size_t);
extern "C" void FUN_14257dcb0(void*);
extern "C" void FUN_1426251d0(void*, void*, std::int64_t);
extern "C" void FUN_14268aff0(void*, void*);
extern "C" void FUN_14268a8e0(void*, void*);
extern "C" void FUN_14268b3e0(void*, void*);
extern "C" void FUN_14268ac40(void*, void*);
extern "C" void FUN_142689aa0(void*, void*, void*);
extern "C" void FUN_142689cb0(void*, void*, void*);

static void CopyFixedHashPayload(std::uint64_t* destination, const std::uint64_t* source)
{
    for (unsigned i = 1; i < 7; ++i)
        destination[i] = source[i];
}
static void WriteFixedHashValue(std::uint64_t* row, const std::uint64_t* value)
{
    row[2] = *reinterpret_cast<const std::uint64_t*>(value[0]);
    const auto* payload = reinterpret_cast<const std::uint64_t*>(value[1]);
    for (unsigned i = 0; i < 4; ++i)
        row[3 + i] = payload[i];
}
namespace Scaleform { static std::uint64_t HashImageKey(const unsigned char* key); }

// MS2-FUNCTIONAL: clears or rebuilds the fixed 0x38-byte movie-record hash table and reinserts each occupied key/payload pair.
// @0x1426906b0
extern "C" void FUN_1426906b0(void* setObject, void* allocator, std::size_t requestedSize)
{
    auto** set = static_cast<std::uint64_t**>(setObject);
    auto* oldTable = *set;
    if (!requestedSize) {
        if (oldTable) {
            const std::uint64_t oldCapacity = oldTable[1] + 1;
            auto* bytes = reinterpret_cast<unsigned char*>(oldTable);
            for (std::uint64_t i = 0; i < oldCapacity; ++i) {
                auto* row = reinterpret_cast<std::uint64_t*>(bytes + 0x10 + i * 0x38);
                if (static_cast<std::int64_t>(row[0]) != -2)
                    row[0] = UINT64_MAX - 1;
            }
            auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
            reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, oldTable);
            *set = nullptr;
        }
        return;
    }

    std::uint64_t capacity = 8;
    while (capacity < requestedSize)
        capacity <<= 1;
    int statId = 2;
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    auto* newTable = reinterpret_cast<std::uint64_t* (*)(void*, std::size_t, const int*)>(heapVtable[10])(
        DAT_143b15f60, static_cast<std::size_t>(capacity * 0x38 + 0x10), &statId);
    newTable[0] = 0;
    newTable[1] = capacity - 1;
    auto* newBytes = reinterpret_cast<unsigned char*>(newTable);
    for (std::uint64_t i = 0; i < capacity; ++i)
        *reinterpret_cast<std::uint64_t*>(newBytes + 0x10 + i * 0x38) = UINT64_MAX - 1;
    *set = newTable;

    if (oldTable) {
        const std::uint64_t oldCapacity = oldTable[1] + 1;
        auto* oldBytes = reinterpret_cast<unsigned char*>(oldTable);
        for (std::uint64_t i = 0; i < oldCapacity; ++i) {
            auto* row = reinterpret_cast<std::uint64_t*>(oldBytes + 0x10 + i * 0x38);
            if (static_cast<std::int64_t>(row[0]) != -2) {
                const auto* key = reinterpret_cast<const unsigned char*>(oldBytes + 0x20 + i * 0x38);
                const auto* payload = reinterpret_cast<const std::uint64_t*>(oldBytes + 0x28 + i * 0x38);
                struct Pair { const unsigned char* key; const std::uint64_t* payload; } pair{key, payload};
                FUN_1426867f0(setObject, allocator, &pair, Scaleform::HashImageKey(key));
                row[0] = UINT64_MAX - 1;
            }
        }
        auto** oldHeapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
        reinterpret_cast<void (*)(void*, void*)>(oldHeapVtable[12])(DAT_143b15f60, oldTable);
    }
}

// MS2-FUNCTIONAL: inserts a key and six qwords of cached payload into the fixed-size hash table, relocating collisions and growing it as needed.
// @0x1426867f0
extern "C" void FUN_1426867f0(void* setObject, void* allocator, void* valueData, std::uint64_t hash)
{
    auto* value = static_cast<std::uint64_t*>(valueData);
    auto** set = static_cast<std::uint64_t**>(setObject);
    auto* table = *set;
    std::uint64_t capacity;
    if (!table) {
        capacity = 8;
    } else {
        if (table[0] * 5 <= table[1] * 4 + 4)
            goto insert_entry;
        capacity = table[1] * 2 + 2;
    }
    FUN_1426906b0(setObject, allocator, capacity);
insert_entry:
    table = *set;
    const std::uint64_t bucket = hash & table[1];
    ++table[0];
    auto* row = reinterpret_cast<std::uint64_t*>(reinterpret_cast<unsigned char*>(table) + 0x10 + bucket * 0x38);
    const std::uint64_t occupant = row[0];
    if (static_cast<std::int64_t>(occupant) == -2) {
        row[0] = UINT64_MAX;
        WriteFixedHashValue(row, value);
    } else {
        std::uint64_t empty = bucket;
        do {
            empty = (empty + 1) & table[1];
        } while (static_cast<std::int64_t>(*reinterpret_cast<std::uint64_t*>(
            reinterpret_cast<unsigned char*>(table) + 0x10 + empty * 0x38)) != -2);
        auto* target = reinterpret_cast<std::uint64_t*>(reinterpret_cast<unsigned char*>(table) + 0x10 + empty * 0x38);
        if (row[1] == bucket) {
            target[0] = occupant;
            CopyFixedHashPayload(target, row);
            row[0] = empty;
        } else {
            auto* previous = reinterpret_cast<std::uint64_t*>(reinterpret_cast<unsigned char*>(table) +
                0x10 + row[1] * 0x38);
            while (previous[0] != bucket)
                previous = reinterpret_cast<std::uint64_t*>(reinterpret_cast<unsigned char*>(table) +
                    0x10 + previous[0] * 0x38);
            target[0] = occupant;
            CopyFixedHashPayload(target, row);
            previous[0] = empty;
            row[0] = UINT64_MAX;
        }
        WriteFixedHashValue(row, value);
    }
    row[1] = bucket;
}
namespace Scaleform {

namespace GFx { class StaticTextRecord; class TaskThreadInPool; }

// The executable's four adjacent Resize bodies are template instances of the recovered ArrayData implementation.
// MS2-PIN: ?Resize@?$ArrayBase@U?$ArrayData@EU?$AllocatorGH_POD@E$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@QEAAX_K@Z 0x142568420
template void ArrayBase<ArrayData<UByte, AllocatorGH_POD<UByte, 2>, ArrayDefaultPolicy>>::Resize(UPInt);
// MS2-PIN: ?Resize@?$ArrayData@PEAVTaskThreadInPool@GFx@Scaleform@@U?$AllocatorGH@PEAVTaskThreadInPool@GFx@Scaleform@@$01@3@UArrayDefaultPolicy@3@@Scaleform@@QEAAX_K@Z 0x1425685a0
template void ArrayData<GFx::TaskThreadInPool*, AllocatorGH<GFx::TaskThreadInPool*, 2>, ArrayDefaultPolicy>::Resize(UPInt);
// MS2-PIN: ?Resize@?$ArrayData@MU?$AllocatorLH_POD@M$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAX_K@Z 0x14268e7c0
// MS2-FUNCTIONAL 0x14268e7c0: resize behavior matches; executable calls Reserve at 0x142623c60 while the source map selects 0x14268e380.
template void ArrayData<float, AllocatorLH_POD<float, 2>, ArrayDefaultPolicy>::Resize(UPInt);
template void MsgFormat::FormatD1<unsigned long>(const unsigned long&);
template void MsgFormat::FormatD1<const char*>(const char* const&);

// The Context::CreateEntry template allocates TreeContainer::NodeData, runs its encoded
// constructor, and hands the node data to the context entry table.
template Render::TreeContainer*
Render::ContextImpl::Context::CreateEntry<Render::TreeContainer>();

} // namespace Scaleform

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {


}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// MS2-PIN: ??$FormatD1@PEBD@MsgFormat@Scaleform@@QEAAXAEBQEBD@Z 0x142685ff0

namespace Scaleform {
extern "C" void FUN_1425463f0(void*, const void*, UPInt);
extern "C" void FUN_142546490(void*, const void*, UPInt);

// ArrayData::Resize shrinks only after the size drops below half capacity; growth reserves 25% headroom.
// MS2-FUNCTIONAL: preserves the executable's size/capacity decisions and reserve call targets; register allocation differs.
// @0x1425684a0
void ResizeTextStyleArray(void* array, UPInt size)
{
    UPInt* fields = static_cast<UPInt*>(array);
    if (size < fields[1])
    {
        if (size < (fields[2] >> 1))
        {
            FUN_1425463f0(array, array, size);
            fields[1] = size;
            return;
        }
    }
    else if (fields[2] <= size)
    {
        FUN_1425463f0(array, array, (size >> 2) + size);
        fields[1] = size;
        return;
    }
    fields[1] = size;
}

// MS2-FUNCTIONAL: preserves the executable's size/capacity decisions and reserve call targets; register allocation differs.
// @0x142568520
void ResizeStaticTextArray(void* array, UPInt size)
{
    UPInt* fields = static_cast<UPInt*>(array);
    if (size < fields[1])
    {
        if (size < (fields[2] >> 1))
        {
            FUN_142546490(array, array, size);
            fields[1] = size;
            return;
        }
    }
    else if (fields[2] <= size)
    {
        FUN_142546490(array, array, (size >> 2) + size);
        fields[1] = size;
        return;
    }
    fields[1] = size;
}
}

enum FMOD_RESULT : int {};
struct FMOD_CREATESOUNDEXINFO;
namespace FMOD {
class Sound
{
public:
    ::FMOD_RESULT getLength(unsigned* length, unsigned timeUnit);
    ::FMOD_RESULT release();
    ::FMOD_RESULT lock(unsigned offset, unsigned length, void** first, void** second,
                       unsigned* firstLength, unsigned* secondLength);
    ::FMOD_RESULT unlock(void* first, void* second, unsigned firstLength, unsigned secondLength);
};
class System
{
public:
    ::FMOD_RESULT createSound(const char* path, unsigned mode, ::FMOD_CREATESOUNDEXINFO* info, Sound** sound);
    ::FMOD_RESULT createStream(const char* path, unsigned mode, ::FMOD_CREATESOUNDEXINFO* info, Sound** sound);
};
class Channel
{
public:
    ::FMOD_RESULT isPlaying(bool* playing);
    ::FMOD_RESULT getPosition(unsigned* position, unsigned timeUnit);
    ::FMOD_RESULT stop();
};
}

namespace Scaleform {
static FMOD::Sound* SoundForLength(void* soundSource)
{
    return *reinterpret_cast<FMOD::Sound**>(static_cast<char*>(soundSource) + 0x30);
}

// MS2-FUNCTIONAL: retains the executable's null check, FMOD millisecond query, and failure result.
// @0x142745760
unsigned QuerySoundLength(void* soundSource)
{
    FMOD::Sound* sound = SoundForLength(soundSource);
    unsigned length = 0;
    return sound && sound->getLength(&length, 8) == 0 ? length : 0;
}

// MS2-FUNCTIONAL: byte-identical behavior to the neighboring FMOD length query; emitted as a distinct exe copy.
// @0x1427457a0
unsigned QuerySoundLengthCopy(void* soundSource)
{
    FMOD::Sound* sound = SoundForLength(soundSource);
    unsigned length = 0;
    return sound && sound->getLength(&length, 8) == 0 ? length : 0;
}

// MS2-FUNCTIONAL: retains the executable's sample-unit query and conversion to seconds.
// @0x1427457e0
float QuerySoundDuration(void* soundSource)
{
    FMOD::Sound* sound = SoundForLength(soundSource);
    unsigned length = 0;
    if (!sound || sound->getLength(&length, 1) != 0)
        return 0.0f;
    return static_cast<float>(length) / 1000.0f;
}

// MS2-FUNCTIONAL: preserves the executable's null check and FMOD error handling.
// @0x142745c40
bool QueryChannelPlaying(void* soundSource)
{
    FMOD::Channel* channel = *reinterpret_cast<FMOD::Channel**>(static_cast<char*>(soundSource) + 0x38);
    bool playing = false;
    return channel && channel->isPlaying(&playing) == 0 ? playing : false;
}
}

int FUN_1428d8efc(void*, void*);
int FUN_1428d8f14(void*, void*);
void FUN_14257d390(void*, long long, unsigned, unsigned);
int FUN_1427483a0(void*, int);
unsigned long long FUN_142748160(void*, void*, unsigned);
int FUN_1428d8ea8(void*, unsigned, unsigned, void**, void**, unsigned*, unsigned*);
int FUN_1428d8eae(void*, void*, void*, unsigned, unsigned);
int FUN_1428d8f2c(void*, bool);
int FUN_1428d8e96(void*, int*, int*, int*, int*, int*, int*);
int FUN_1428d8e9c(void*, void**);
int FUN_1428d8f26(void*, float*);
int FUN_1428d8eea(void*, float*);
int FUN_1428d8ec0(void*, void*, unsigned, unsigned*);
int FUN_1428d8eb4(void*, float*, float*, float*, int*);
int FUN_1428d8eba(void*, void*, int*, int*, int*);
int FUN_1428d8ea2(void*, unsigned*, unsigned*);
int FUN_1428d8f02(void*, unsigned);
int FUN_1428d8f08(void*, int);
int FUN_1428d8ef6(void*, unsigned, unsigned);
int FUN_1428d8f0e(void*, unsigned, unsigned, unsigned, unsigned);
int FUN_1428d8ef0(void*, unsigned, unsigned, unsigned);
void FUN_142742830(long long*, unsigned long long*);
void FUN_14268b710(void*, Scaleform::Log*);
void FUN_14268bd60(void*, Scaleform::Log*);

namespace Scaleform {
// MS2-FUNCTIONAL: uses the executable's FMOD wrapper calls and preserves its defaults and result handling.
// @0x142745840
float QueryMasterVolume(void* player)
{
    float volume = 1.0f;
    void* group = nullptr;
    if (FUN_1428d8e9c(*reinterpret_cast<void**>(static_cast<char*>(player) + 0x10), &group) == 0)
        FUN_1428d8f26(group, &volume);
    return volume;
}

// MS2-FUNCTIONAL: mirrors the channel null check and reads the pan value through the executable wrapper.
// @0x1427458b0
float QueryChannelPan(void* player)
{
    void* channel = *reinterpret_cast<void**>(static_cast<char*>(player) + 0x38);
    float pan = 0.0f;
    if (channel)
        FUN_1428d8eea(channel, &pan);
    return pan;
}

// MS2-FUNCTIONAL: the sound read count is initialized to zero and returned only for a non-null sound.
// @0x142745880
unsigned ReadSoundData(void* player, void* buffer, unsigned bytes)
{
    void* sound = *reinterpret_cast<void**>(static_cast<char*>(player) + 0x30);
    unsigned read = 0;
    if (sound)
        FUN_1428d8ec0(sound, buffer, bytes, &read);
    return read;
}

// MS2-FUNCTIONAL: returns the channel volume when present, otherwise the executable's default of one.
// @0x142745b90
float QueryChannelVolume(void* player)
{
    void* channel = *reinterpret_cast<void**>(static_cast<char*>(player) + 0x38);
    float volume = 1.0f;
    if (channel)
        FUN_1428d8f26(channel, &volume);
    return volume;
}
}


namespace Scaleform {
// MS2-FUNCTIONAL: preserves the executable's time-unit conversions and both FMOD position queries.
// @0x1427458e0
float QueryChannelTime(void* player)
{
    void* channel = *reinterpret_cast<void**>(static_cast<char*>(player) + 0x38);
    if (!channel)
        return 0.0f;

    unsigned offset = 0;
    void* soundSource = *reinterpret_cast<void**>(static_cast<char*>(player) + 0x30);
    if (soundSource) {
        void* metadata = *reinterpret_cast<void**>(static_cast<char*>(soundSource) + 0x38);
        if (metadata) {
            const auto numerator = *reinterpret_cast<int*>(static_cast<char*>(metadata) + 0x1c) * 1000;
            const auto denominator = *reinterpret_cast<unsigned*>(static_cast<char*>(metadata) + 0x14);
            if (denominator)
                offset = static_cast<unsigned>(numerator) / denominator;
        }
    }

    unsigned position = 0;
    unsigned dspPosition = 0;
    reinterpret_cast<FMOD::Channel*>(channel)->getPosition(&position, 1);
    reinterpret_cast<FMOD::Channel*>(channel)->getPosition(&dspPosition, 4);
    (void)dspPosition;
    return static_cast<float>(position - offset) / 1000.0f;
}

// MS2-FUNCTIONAL: stores both flags and the system pointer before querying and caching the software rate.
// @0x142745bc0
bool InitializeAudioSystem(void* player, void* system, unsigned char flag0, unsigned char flag1)
{
    auto* bytes = static_cast<unsigned char*>(player);
    bytes[0xf0] = flag0;
    bytes[0xf1] = flag1;
    *reinterpret_cast<void**>(bytes + 0x10) = system;
    if (!system)
        return false;

    int rate = 0;
    FUN_1428d8e96(system, &rate, nullptr, nullptr, nullptr, nullptr, nullptr);
    *reinterpret_cast<float*>(bytes + 0xf4) = static_cast<float>(rate);
    return true;
}
}

namespace Scaleform {
// MS2-FUNCTIONAL: recursively computes the greatest node depth field while walking the child array.
// @0x142686540
void UpdateTreeMaximumDepth(void* node, unsigned* maximum)
{
    auto* bytes = static_cast<unsigned char*>(node);
    const unsigned depth = *reinterpret_cast<unsigned*>(bytes + 0x28);
    if (depth > *maximum)
        *maximum = depth;
    void** children = *reinterpret_cast<void***>(bytes + 0x30);
    const std::size_t count = *reinterpret_cast<std::size_t*>(bytes + 0x38);
    for (std::size_t i = 0; i < count; ++i)
        UpdateTreeMaximumDepth(children[i], maximum);
}

// MS2-FUNCTIONAL: counts each tree node and all descendants using the executable's child range.
// @0x1426865a0
void CountTreeNodes(void* node, int* count)
{
    ++*count;
    auto* bytes = static_cast<unsigned char*>(node);
    void** children = *reinterpret_cast<void***>(bytes + 0x30);
    const std::size_t childCount = *reinterpret_cast<std::size_t*>(bytes + 0x38);
    for (std::size_t i = 0; i < childCount; ++i)
        CountTreeNodes(children[i], count);
}

// MS2-FUNCTIONAL: adds the supplied count to every node's 32-bit accumulated value recursively.
// @0x1426865f0
void AddTreeNodeValue(void* node, const int* value)
{
    auto* bytes = static_cast<unsigned char*>(node);
    *reinterpret_cast<int*>(bytes + 0x28) += *value;
    void** children = *reinterpret_cast<void***>(bytes + 0x30);
    const std::size_t childCount = *reinterpret_cast<std::size_t*>(bytes + 0x38);
    for (std::size_t i = 0; i < childCount; ++i)
        AddTreeNodeValue(children[i], value);
}

void* FindFixedHashKey(void*, void*, const unsigned char*);
void AddImageHashValue(void*, const unsigned char*, const void*);

// MS2-FUNCTIONAL: adds or updates this tree node's fixed-hash record, then processes all child nodes.
// @0x142686440
void AccumulateImageTreeValue(void* node, void* set)
{
    auto* bytes = static_cast<unsigned char*>(node);
    auto* key = bytes + 0x10;
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(set) + 8) != 0 ||
        (*reinterpret_cast<std::uint64_t*>(key) >> 32) == 1) {
        std::uint64_t found[2] = {};
        FindFixedHashKey(set, found, key);
        if (!found[0] || *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(
                              reinterpret_cast<void*>(found[0])) + 8) < found[1]) {
            struct ValueRecord { std::uint64_t key; std::uint64_t index; std::uint32_t count; std::uint32_t pad; std::uint64_t size; };
            ValueRecord value{*reinterpret_cast<std::uint64_t*>(key), 0, 1, 0,
                              *reinterpret_cast<std::uint64_t*>(bytes + 0x20) -
                              *reinterpret_cast<std::uint64_t*>(bytes + 0x18)};
            AddImageHashValue(set, key, &value);
        } else {
            auto* base = reinterpret_cast<unsigned char*>(found[0]);
            auto* entry = base + 0x38 + found[1] * 0x38;
            ++*reinterpret_cast<std::uint32_t*>(entry);
            *reinterpret_cast<std::uint64_t*>(entry + 8) +=
                *reinterpret_cast<std::uint64_t*>(bytes + 0x20) -
                *reinterpret_cast<std::uint64_t*>(bytes + 0x18);
        }
    }
    void** children = *reinterpret_cast<void***>(bytes + 0x30);
    const std::size_t count = *reinterpret_cast<std::size_t*>(bytes + 0x38);
    for (std::size_t i = 0; i < count; ++i)
        AccumulateImageTreeValue(children[i], set);
}
}

namespace Scaleform {
// MS2-FUNCTIONAL: clips the requested rectangle against both image sizes and returns the origin delta.
// @0x142675bb0
bool ClipImageRect(void* command, void* firstImage, void* secondImage, const int* requested,
                   unsigned* clipped, int* originDelta)
{
    const unsigned* firstSize = *reinterpret_cast<unsigned**>(static_cast<char*>(firstImage) + 0x10);
    const unsigned* secondSize = *reinterpret_cast<unsigned**>(static_cast<char*>(secondImage) + 0x10);
    const int dx = *reinterpret_cast<const int*>(static_cast<const char*>(command) + 0x28) - requested[0];
    const int dy = *reinterpret_cast<const int*>(static_cast<const char*>(command) + 0x2c) - requested[1];
    originDelta[0] = dx;
    originDelta[1] = dy;

    const int reqLeft = requested[0];
    const int reqTop = requested[1];
    const int reqRight = requested[2];
    const int reqBottom = requested[3];
    if (reqTop > static_cast<int>(firstSize[1]) || reqBottom < 0 || reqRight < 0 ||
        reqLeft > static_cast<int>(firstSize[0]))
        return false;

    const unsigned left = static_cast<unsigned>(reqLeft < 0 ? 0 : reqLeft) + dx;
    const unsigned right = static_cast<unsigned>(reqRight < static_cast<int>(firstSize[0]) ? reqRight : firstSize[0]) + dx;
    const unsigned top = static_cast<unsigned>(reqTop < 0 ? 0 : reqTop) + dy;
    const unsigned bottom = static_cast<unsigned>(reqBottom < static_cast<int>(firstSize[1]) ? reqBottom : firstSize[1]) + dy;
    if (static_cast<int>(right) < 0 || static_cast<int>(top) > static_cast<int>(secondSize[1]) ||
        static_cast<int>(left) > static_cast<int>(secondSize[0]) || static_cast<int>(bottom) < 0)
        return false;

    clipped[0] = left;
    clipped[1] = top;
    clipped[2] = right < secondSize[0] ? right : secondSize[0];
    clipped[3] = bottom < secondSize[1] ? bottom : secondSize[1];
    return true;
}
}


namespace Scaleform {
// MS2-FUNCTIONAL: reports channels, integer default frequency, and the executable's supported-format flag.
// @0x142745ac0
bool QuerySoundFormat(void* player, unsigned* formatFlag, int* channels, int* frequency)
{
    void* sound = *reinterpret_cast<void**>(static_cast<char*>(player) + 0x30);
    if (!sound)
        return false;

    int soundFormat = 0;
    int channelCount = 0;
    if (FUN_1428d8eba(sound, nullptr, &soundFormat, &channelCount, nullptr) != 0)
        return false;
    *channels = channelCount;

    float defaultFrequency = 0.0f;
    if (FUN_1428d8eb4(sound, &defaultFrequency, nullptr, nullptr, nullptr) != 0)
        return false;
    *frequency = static_cast<int>(defaultFrequency);
    if (soundFormat != 2 && soundFormat != 5)
        return false;
    *formatFlag = soundFormat == 5 ? 1u : 0u;
    return true;
}
}


namespace Scaleform {
// MS2-FUNCTIONAL: gets the master channel group and applies the requested mute state on success.
// @0x142745e70
void SetMasterMuted(void* player, bool muted)
{
    void* system = *reinterpret_cast<void**>(static_cast<char*>(player) + 0x10);
    void* group = nullptr;
    if (FUN_1428d8e9c(system, &group) == 0)
        FUN_1428d8f2c(group, muted);
}

// @0x1427461c0
void ReleasePlayerSound(void* player)
{
    auto** sound = reinterpret_cast<FMOD::Sound**>(static_cast<char*>(player) + 0x30);
    if (*sound)
        (*sound)->release();
    *sound = nullptr;
}

// @0x1427461f0
void ReleasePlayerSoundCopy(void* player)
{
    auto** sound = reinterpret_cast<FMOD::Sound**>(static_cast<char*>(player) + 0x30);
    if (*sound)
        (*sound)->release();
    *sound = nullptr;
}
}


namespace Scaleform {
// MS2-FUNCTIONAL: unregisters callback and user data, then clears the channel reference.
// @0x142746180
void DetachChannelCallback(void** object)
{
    void* channel = object[7];
    if (!channel)
        return;
    using Cleanup = void (*)(void*);
    auto** vtable = *reinterpret_cast<void***>(object);
    reinterpret_cast<Cleanup>(vtable[3])(object);
    FUN_1428d8efc(channel, nullptr);
    FUN_1428d8f14(channel, nullptr);
    object[7] = nullptr;
}

// MS2-FUNCTIONAL: clears the channel registration and unlinks this node from its intrusive list.
// @0x142746230
void DetachChannelNode(void* node)
{
    auto* bytes = static_cast<unsigned char*>(node);
    const int references = *reinterpret_cast<int*>(bytes - 8);
    void* channel = *reinterpret_cast<void**>(bytes + 0x28);
    if (references > 0 && channel) {
        auto** vtable = *reinterpret_cast<void***>(bytes - 0x10);
        reinterpret_cast<void (*)(void*)>(vtable[3])(bytes - 0x10);
        FUN_1428d8efc(channel, nullptr);
        FUN_1428d8f14(channel, nullptr);
        *reinterpret_cast<void**>(bytes + 0x28) = nullptr;
    }
    *reinterpret_cast<void**>(bytes + 0x18) = nullptr;
    void* next = *reinterpret_cast<void**>(bytes + 0x10);
    if (next) {
        void* previous = *reinterpret_cast<void**>(bytes + 8);
        *reinterpret_cast<void**>(static_cast<char*>(previous) + 0x10) = next;
        *reinterpret_cast<void**>(static_cast<char*>(next) + 8) = previous;
        *reinterpret_cast<void**>(bytes + 8) = nullptr;
        *reinterpret_cast<void**>(bytes + 0x10) = nullptr;
    }
}
}

namespace Scaleform {
// MS2-FUNCTIONAL: multiplies each 64-bit element in each nested 16-byte record by the supplied factor.
// @0x142687900
void ScaleNestedRecords(void* array, unsigned factor)
{
    auto* bytes = static_cast<unsigned char*>(array);
    void** items = *reinterpret_cast<void***>(bytes + 0x10);
    const std::size_t count = *reinterpret_cast<std::size_t*>(bytes + 0x18);
    for (std::size_t i = 0; i < count; ++i) {
        auto* item = static_cast<unsigned char*>(items[i]);
        const std::size_t n = *reinterpret_cast<std::size_t*>(item + 0x28);
        auto* values = *reinterpret_cast<unsigned long long**>(item + 0x20);
        for (std::size_t j = 0; j < n; ++j)
            values[j * 2 + 1] *= factor;
    }
}

// MS2-FUNCTIONAL: scales nested 16-byte entries, 32-byte paired records, and 24-byte timestamp records.
// @0x142687980
void* ScaleTextTreeRecords(void* object, unsigned factor)
{
    auto* bytes = static_cast<unsigned char*>(object);
    auto* nestedArray = *reinterpret_cast<unsigned char**>(bytes + 0x58);
    auto** nestedItems = *reinterpret_cast<unsigned char***>(nestedArray + 0x10);
    const std::size_t nestedCount = *reinterpret_cast<std::size_t*>(nestedArray + 0x18);
    for (std::size_t i = 0; i < nestedCount; ++i) {
        auto* item = nestedItems[i];
        auto* values = *reinterpret_cast<unsigned long long**>(item + 0x20);
        const std::size_t count = *reinterpret_cast<std::size_t*>(item + 0x28);
        for (std::size_t j = 0; j < count; ++j)
            values[j * 2 + 1] *= factor;
    }

    auto* pairArray = *reinterpret_cast<unsigned char**>(bytes + 0x60);
    auto* pairs = *reinterpret_cast<unsigned char**>(pairArray + 0x10);
    const std::size_t pairCount = *reinterpret_cast<std::size_t*>(pairArray + 0x18);
    for (std::size_t i = 0; i < pairCount; ++i) {
        auto* pair = pairs + i * 0x20;
        *reinterpret_cast<unsigned*>(pair + 0x10) *= factor;
        *reinterpret_cast<unsigned long long*>(pair + 0x18) *= factor;
    }

    auto* timeArray = *reinterpret_cast<unsigned char**>(bytes + 0x68);
    auto* times = *reinterpret_cast<unsigned char**>(timeArray + 0x10);
    const std::size_t timeCount = *reinterpret_cast<std::size_t*>(timeArray + 0x18);
    for (std::size_t i = 0; i < timeCount; ++i)
        *reinterpret_cast<unsigned long long*>(times + i * 0x18 + 0x10) *= factor;
    return object;
}

// MS2-FUNCTIONAL: divides the nested 16-byte records, 32-byte paired records, and 24-byte timestamp records.
// @0x142688600
void* DivideTextTreeRecords(void* object, unsigned long long divisor)
{
    const unsigned d = static_cast<unsigned>(divisor);
    auto* bytes = static_cast<unsigned char*>(object);
    auto* nestedArray = *reinterpret_cast<unsigned char**>(bytes + 0x58);
    auto** nestedItems = *reinterpret_cast<unsigned char***>(nestedArray + 0x10);
    const std::size_t nestedCount = *reinterpret_cast<std::size_t*>(nestedArray + 0x18);
    for (std::size_t i = 0; i < nestedCount; ++i) {
        auto* item = nestedItems[i];
        auto* values = *reinterpret_cast<unsigned long long**>(item + 0x20);
        const std::size_t count = *reinterpret_cast<std::size_t*>(item + 0x28);
        for (std::size_t j = 0; j < count; ++j)
            values[j * 2 + 1] /= d;
    }

    auto* pairArray = *reinterpret_cast<unsigned char**>(bytes + 0x60);
    auto* pairs = *reinterpret_cast<unsigned char**>(pairArray + 0x10);
    const std::size_t pairCount = *reinterpret_cast<std::size_t*>(pairArray + 0x18);
    for (std::size_t i = 0; i < pairCount; ++i) {
        auto* pair = pairs + i * 0x20;
        *reinterpret_cast<unsigned*>(pair + 0x10) /= d;
        *reinterpret_cast<unsigned long long*>(pair + 0x18) /= d;
    }

    auto* timeArray = *reinterpret_cast<unsigned char**>(bytes + 0x68);
    auto* times = *reinterpret_cast<unsigned char**>(timeArray + 0x10);
    const std::size_t timeCount = *reinterpret_cast<std::size_t*>(timeArray + 0x18);
    for (std::size_t i = 0; i < timeCount; ++i)
        *reinterpret_cast<unsigned long long*>(times + i * 0x18 + 0x10) /= d;
    return object;
}

// MS2-FUNCTIONAL: scales the fixed timing fields, child tree records, paired counters, and all three MemItem trees.
// @0x142687ae0
void* ScaleTextTree(void* object, unsigned factor)
{
    auto* bytes = static_cast<unsigned char*>(object);
    *reinterpret_cast<unsigned long long*>(bytes + 0x10) *= factor;
    for (std::size_t offset = 0x18; offset <= 0xc8; offset += 4)
        *reinterpret_cast<unsigned*>(bytes + offset) *= factor;

    auto** childArray = *reinterpret_cast<void***>(bytes + 0xd0);
    const std::size_t childCount = *reinterpret_cast<std::size_t*>(bytes + 0xd8);
    for (std::size_t i = 0; i < childCount; ++i)
        ScaleTextTreeRecords(childArray[i], factor);

    auto* records = static_cast<unsigned char*>(*reinterpret_cast<void**>(bytes + 0xe8));
    const std::size_t recordCount = *reinterpret_cast<std::size_t*>(records + 0x18);
    auto* entries = *reinterpret_cast<unsigned char**>(records + 0x10);
    for (std::size_t i = 0; i < recordCount; ++i) {
        auto* entry = entries + i * 0x20;
        *reinterpret_cast<unsigned*>(entry + 0x10) *= factor;
        *reinterpret_cast<unsigned long long*>(entry + 0x18) *= factor;
    }

    for (std::size_t offset : { std::size_t(0x128), std::size_t(0x130), std::size_t(0x138) }) {
        auto* item = *reinterpret_cast<Scaleform::MemItem**>(bytes + offset);
        if (item)
            item->operator*=(factor);
    }
    return object;
}

// MS2-FUNCTIONAL: divides the 32-bit and 64-bit values of each 32-byte record by the divisor.
// @0x142688520
void DivideRecordPairs(void* array, unsigned long long divisor)
{
    auto* bytes = static_cast<unsigned char*>(array);
    auto* records = *reinterpret_cast<unsigned char**>(bytes + 0x10);
    const std::size_t count = *reinterpret_cast<std::size_t*>(bytes + 0x18);
    const unsigned d = static_cast<unsigned>(divisor);
    for (std::size_t i = 0; i < count; ++i) {
        auto* record = records + i * 0x20;
        *reinterpret_cast<unsigned*>(record) /= d;
        *reinterpret_cast<unsigned long long*>(record + 8) /= d;
    }
}

// MS2-FUNCTIONAL: divides each 64-bit element in each nested 16-byte record by the low 32-bit divisor.
// @0x142688580
void DivideNestedRecords(void* array, unsigned long long divisor)
{
    auto* bytes = static_cast<unsigned char*>(array);
    void** items = *reinterpret_cast<void***>(bytes + 0x10);
    const std::size_t count = *reinterpret_cast<std::size_t*>(bytes + 0x18);
    const unsigned d = static_cast<unsigned>(divisor);
    for (std::size_t i = 0; i < count; ++i) {
        auto* item = static_cast<unsigned char*>(items[i]);
        const std::size_t n = *reinterpret_cast<std::size_t*>(item + 0x28);
        auto* values = *reinterpret_cast<unsigned long long**>(item + 0x20);
        for (std::size_t j = 0; j < n; ++j)
            values[j * 2 + 1] /= d;
    }
}
}

namespace Scaleform {
static int CountMovieRoots(void** roots, std::size_t rootCount)
{
    int total = 0;
    for (std::size_t i = 0; i < rootCount; ++i) {
        int count = 1;
        auto* root = static_cast<unsigned char*>(roots[i]);
        void** children = *reinterpret_cast<void***>(root + 0x30);
        const std::size_t childCount = *reinterpret_cast<std::size_t*>(root + 0x38);
        for (std::size_t j = 0; j < childCount; ++j)
            CountTreeNodes(children[j], &count);
        total += count;
    }
    return total;
}

// MS2-FUNCTIONAL: counts descendants across every root view and the extra root tree, seeding each view node at one.
// @0x14268a6d0
int CountMovieViewNodes(void* movie)
{
    auto* bytes = static_cast<unsigned char*>(movie);
    int total = 0;
    auto** views = *reinterpret_cast<void***>(bytes + 0xd0);
    const std::size_t viewCount = *reinterpret_cast<std::size_t*>(bytes + 0xd8);
    for (std::size_t i = 0; i < viewCount; ++i) {
        auto* viewRoots = static_cast<unsigned char*>(views[i]) + 0x70;
        total += CountMovieRoots(*reinterpret_cast<void***>(viewRoots + 0x18),
                                 *reinterpret_cast<std::size_t*>(viewRoots + 0x20));
    }
    auto* roots = static_cast<unsigned char*>(*reinterpret_cast<void**>(bytes + 0xf0));
    if (roots)
        total += CountMovieRoots(*reinterpret_cast<void***>(roots + 0x18),
                                 *reinterpret_cast<std::size_t*>(roots + 0x20));
    return total;
}

// MS2-FUNCTIONAL: returns one plus the recursive descendant count, matching the executable's seed value.
// @0x14268a810
unsigned CountTreeWithRoot(void* node)
{
    int count = 1;
    auto* bytes = static_cast<unsigned char*>(node);
    void** children = *reinterpret_cast<void***>(bytes + 0x30);
    const std::size_t childCount = *reinterpret_cast<std::size_t*>(bytes + 0x38);
    for (std::size_t i = 0; i < childCount; ++i)
        CountTreeNodes(children[i], &count);
    return static_cast<unsigned>(count);
}

static std::uint64_t HashImageKey(const unsigned char* key)
{
    return (((static_cast<std::uint64_t>(key[3]) * 0x1003full + key[2]) * 0x1003full + key[1]) * 0x1003full +
            static_cast<std::uint64_t>(key[4]) * 0xfc5d1543ec5f01ull +
            static_cast<std::uint64_t>(key[5]) * 0x9b302c28162c6120ull +
            static_cast<std::uint64_t>(key[7]) * 0xd7c3e496a311bbbfll +
            static_cast<std::uint64_t>(key[6]) * 0x5d02f409d62aee81ull -
            0x514d9afbc3e934fbull + key[0]);
}

// MS2-FUNCTIONAL: accumulates the fixed counters and merges nested movie lookup tables; variable view and id lists remain to be copied.
// @0x142687eb0
extern "C" void* FUN_142687eb0(void* destination, const void* source)
{
    auto* dst = static_cast<unsigned char*>(destination);
    const auto* src = static_cast<const unsigned char*>(source);
    *reinterpret_cast<std::uint64_t*>(dst + 0x10) += *reinterpret_cast<const std::uint64_t*>(src + 0x10);
    for (std::size_t offset = 0x18; offset <= 0xc8; offset += sizeof(std::uint32_t))
        *reinterpret_cast<std::uint32_t*>(dst + offset) += *reinterpret_cast<const std::uint32_t*>(src + offset);
    FUN_14268a8e0(*reinterpret_cast<void**>(dst + 0xe8), *reinterpret_cast<void* const*>(src + 0xe8));
    FUN_14268ac40(*reinterpret_cast<void**>(dst + 0xf0), *reinterpret_cast<void* const*>(src + 0xf0));
    return destination;
}

// MS2-FUNCTIONAL: hashes the eight-byte key, follows the bucket collision chain, and returns the matching cached node index.
// @0x14268a450
void* FindFixedHashKey(void* setObject, void* result, const unsigned char* key)
{
    auto* output = static_cast<std::uint64_t*>(result);
    auto* set = static_cast<unsigned char*>(setObject);
    auto* table = *reinterpret_cast<unsigned char**>(set);
    std::int64_t found = -1;
    if (table) {
        const std::uint64_t hash = HashImageKey(key);
        const std::uint64_t bucket = hash & *reinterpret_cast<std::uint64_t*>(table + 8);
        auto* entry = reinterpret_cast<std::int64_t*>(table + 0x10 + bucket * 0x38);
        if (entry[0] != -2 && static_cast<std::uint64_t>(entry[1]) == bucket) {
            for (;;) {
                if (static_cast<std::uint64_t>(entry[1]) == bucket &&
                    static_cast<std::uint64_t>(entry[2]) == *reinterpret_cast<const std::uint64_t*>(key)) {
                    found = static_cast<std::int64_t>(bucket);
                    break;
                }
                const std::int64_t next = entry[0];
                if (next == -1)
                    break;
                entry = reinterpret_cast<std::int64_t*>(table + 0x10 + next * 0x38);
            }
        }
    }
    output[0] = found < 0 ? 0 : reinterpret_cast<std::uint64_t>(setObject);
    output[1] = found < 0 ? 0 : static_cast<std::uint64_t>(found);
    return result;
}

// MS2-FUNCTIONAL: inserts an eight-byte key/value pair through the recovered cached hash-set insertion routine.
// @0x1426899e0
void AddImageHashValue(void* set, const unsigned char* key, const void* value)
{
    struct Pair { const unsigned char* key; std::uint64_t value; } pair{key, reinterpret_cast<std::uint64_t>(value)};
    FUN_1426867f0(set, set, &pair, HashImageKey(key));
}

// MS2-FUNCTIONAL: inserts a pointer value into the allocator-backed open-addressed hash set, relocating collisions and growing at the executable's load threshold.
// @0x1426869a0
void AddCachedPointer(void* setObject, void* allocator, const std::uint64_t* value, std::uint64_t hash)
{
    auto** set = static_cast<std::uint64_t**>(setObject);
    auto* table = *set;
    std::uint64_t capacity;
    if (!table) {
        capacity = 8;
    } else {
        if (table[0] * 5 <= table[1] * 4 + 4)
            goto insert_entry;
        capacity = table[1] * 2 + 2;
    }
    FUN_142690a20(setObject, allocator, static_cast<std::int64_t>(capacity));
insert_entry:
    table = *set;
    const std::uint64_t bucket = hash & table[1];
    ++table[0];
    auto* row = table + 2 + bucket * 3;
    const std::uint64_t occupant = row[0];
    std::uint64_t storedValue;
    if (static_cast<std::int64_t>(occupant) == -2) {
        row[1] = UINT64_MAX;
        storedValue = *value;
    } else {
        std::uint64_t empty = bucket;
        do {
            empty = (empty + 1) & table[1];
        } while (static_cast<std::int64_t>(table[2 + empty * 3]) != -2);
        auto* target = table + 2 + empty * 3;
        if (row[1] == bucket) {
            target[0] = occupant;
            target[1] = row[1];
            target[2] = row[2];
            storedValue = *value;
            row[0] = empty;
        } else {
            std::uint64_t previous = row[1];
            auto* previousRow = table + 2 + previous * 3;
            while (previousRow[0] != bucket) {
                previous = previousRow[0];
                previousRow = table + 2 + previous * 3;
            }
            target[0] = occupant;
            target[1] = row[1];
            target[2] = row[2];
            previousRow[0] = empty;
            row[0] = UINT64_MAX;
            storedValue = *value;
        }
    }
    row[2] = storedValue;
    row[1] = bucket;
}

// MS2-FUNCTIONAL: recreates the open-addressed table at the requested power-of-two size, rehashes occupied values, and frees the old allocation.
// @0x142690a20
extern "C" void FUN_142690a20(void* setObject, void* allocator, std::int64_t requestedSize)
{
    auto** set = static_cast<std::uint64_t**>(setObject);
    auto* oldTable = *set;
    if (requestedSize == 0) {
        if (oldTable) {
            const std::uint64_t oldCapacity = oldTable[1] + 1;
            auto* bytes = reinterpret_cast<unsigned char*>(oldTable);
            for (std::uint64_t i = 0; i < oldCapacity; ++i) {
                auto* row = reinterpret_cast<std::uint64_t*>(bytes + 0x10 + i * 0x18);
                if (static_cast<std::int64_t>(row[0]) != -2)
                    row[0] = UINT64_MAX - 1;
            }
            auto** oldHeapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
            reinterpret_cast<void (*)(void*, void*)>(oldHeapVtable[12])(DAT_143b15f60, oldTable);
            *set = nullptr;
        }
        return;
    }

    std::uint64_t capacity = 8;
    const std::uint64_t requested = static_cast<std::uint64_t>(requestedSize);
    while (capacity < requested)
        capacity <<= 1;
    int statId = 2;
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    auto* newTable = reinterpret_cast<std::uint64_t* (*)(void*, std::size_t, const int*)>(heapVtable[10])(
        DAT_143b15f60, static_cast<std::size_t>(capacity * 0x18 + 0x10), &statId);
    newTable[0] = 0;
    newTable[1] = capacity - 1;
    auto* newBytes = reinterpret_cast<unsigned char*>(newTable);
    for (std::uint64_t i = 0; i < capacity; ++i)
        *reinterpret_cast<std::uint64_t*>(newBytes + 0x10 + i * 0x18) = UINT64_MAX - 1;

    *set = newTable;
    if (oldTable) {
        const std::uint64_t oldCapacity = oldTable[1] + 1;
        auto* oldBytes = reinterpret_cast<unsigned char*>(oldTable);
        for (std::uint64_t i = 0; i < oldCapacity; ++i) {
            auto* row = reinterpret_cast<std::uint64_t*>(oldBytes + 0x10 + i * 0x18);
            if (static_cast<std::int64_t>(row[0]) != -2) {
                const auto* value = reinterpret_cast<const std::uint64_t*>(oldBytes + 0x20 + i * 0x18);
                AddCachedPointer(setObject, allocator, value, HashImageKey(reinterpret_cast<const unsigned char*>(value)));
                row[0] = UINT64_MAX - 1;
            }
        }
        auto** oldHeapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
        reinterpret_cast<void (*)(void*, void*)>(oldHeapVtable[12])(DAT_143b15f60, oldTable);
    }
}
// The following stream and movie record helpers remain in the same Scaleform namespace.
void ReadNarrowString(void*, void*);
void ResizeStringArray(void**, std::size_t);
static void ReadMovieBytes(void* stream, void* destination, std::size_t size)
{
    auto** vtable = *reinterpret_cast<void***>(stream);
    reinterpret_cast<void (*)(void*, void*, std::size_t)>(vtable[10])(stream, destination, size);
}

// MS2-FUNCTIONAL: reads the versioned movie image record and reconstructs its refcounted child records recursively.
// @0x14268c190
void ReadMovieImageRecord(void* object, void* stream, unsigned version)
{
    auto* bytes = static_cast<unsigned char*>(object);
    ReadMovieBytes(stream, bytes + 0x10, 8);
    ReadMovieBytes(stream, bytes + 0x18, 8);
    ReadMovieBytes(stream, bytes + 0x20, 8);
    ReadMovieBytes(stream, bytes + 0x28, 4);
    std::uint32_t count = 0;
    ReadMovieBytes(stream, &count, 4);
    const std::size_t oldCount = *reinterpret_cast<std::size_t*>(bytes + 0x38);
    FUN_1426240f0(bytes + 0x30, bytes + 0x30, count);
    void** children = *reinterpret_cast<void***>(bytes + 0x30);
    if (oldCount < count)
        std::memset(children + oldCount, 0, (count - oldCount) * sizeof(void*));
    for (std::size_t i = 0; i < count; ++i) {
        int flags = 2;
        auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
        void* child = reinterpret_cast<void* (*)(void*, void*, std::size_t, const int*)>(heapVtable[14])(
            DAT_143b15f60, object, 0x48, &flags);
        if (child) {
            std::memset(child, 0, 0x48);
            *reinterpret_cast<void***>(child) = &MovieImageInfoVtable;
            *reinterpret_cast<unsigned*>(static_cast<unsigned char*>(child) + 8) = 1;
        }
        if (children[i])
            FUN_14257dcb0(children[i]);
        children[i] = child;
        if (child)
            ReadMovieImageRecord(child, stream, version);
    }
}

// MS2-FUNCTIONAL: reads a movie image's versioned narrow-string and scalar fields from the input stream.
// @0x14268c370
void ReadMovieImageFields(void* object, void* stream, unsigned version)
{
    auto* bytes = static_cast<unsigned char*>(object);
    ReadMovieBytes(stream, bytes + 0x10, 4);
    ReadNarrowString(stream, bytes + 0x18);
    if (version < 0x1d) {
        std::uint32_t ignoredLength = 0;
        ReadMovieBytes(stream, &ignoredLength, 4);
        for (std::uint32_t i = 0; i < ignoredLength; ++i) {
            unsigned char ignored = 0;
            ReadMovieBytes(stream, &ignored, 1);
        }
    }
    ReadMovieBytes(stream, bytes + 0x20, 4);
    unsigned char flag = 0;
    ReadMovieBytes(stream, &flag, 1);
    bytes[0x24] = flag != 0;
    ReadMovieBytes(stream, bytes + 0x28, 4);
    ReadMovieBytes(stream, bytes + 0x2c, 4);
    ReadMovieBytes(stream, bytes + 0x30, 4);
    ReadMovieBytes(stream, bytes + 0x34, 4);
    ReadMovieBytes(stream, bytes + 0x38, 4);
}

// MS2-FUNCTIONAL: reads the versioned image resource fields and its array of narrow-string labels.
// @0x14268e140
void ReadImageResourceRecord(void* object, void* stream, unsigned version)
{
    auto* bytes = static_cast<unsigned char*>(object);
    ReadMovieBytes(stream, bytes + 0x10, 4);
    if (version > 0x13)
        ReadMovieBytes(stream, bytes + 0x14, 4);
    ReadNarrowString(stream, bytes + 0x18);
    if (version > 4)
        ReadNarrowString(stream, bytes + 0x20);
    ReadNarrowString(stream, bytes + 0x28);
    ReadNarrowString(stream, bytes + 0x30);
    ReadNarrowString(stream, bytes + 0x38);
    std::uint32_t count = 0;
    ReadMovieBytes(stream, &count, 4);
    ResizeStringArray(reinterpret_cast<void**>(bytes + 0x40), count);
    auto* strings = static_cast<unsigned char*>(*reinterpret_cast<void**>(bytes + 0x40));
    for (std::uint32_t i = 0; i < count; ++i) {
        std::uint32_t length = 0;
        ReadMovieBytes(stream, &length, 4);
        for (std::uint32_t j = 0; j < length; ++j) {
            unsigned char ch = 0;
            ReadMovieBytes(stream, &ch, 1);
            FUN_142585f70(strings + static_cast<std::size_t>(i) * 8, static_cast<signed char>(ch));
        }
    }
    ReadMovieBytes(stream, bytes + 0x58, 4);
    ReadMovieBytes(stream, bytes + 0x5c, 4);
    ReadMovieBytes(stream, bytes + 0x60, 4);
    ReadMovieBytes(stream, bytes + 0x64, 4);
    if (version > 9) {
        ReadMovieBytes(stream, bytes + 0x68, 8);
        ReadMovieBytes(stream, bytes + 0x70, 4);
    }
}

// MS2-FUNCTIONAL: updates or inserts this node's cached key, then repeats the operation for its child nodes.
// @0x14268a570
void UpdateImageHashTree(void* node, void* setObject)
{
    auto* bytes = static_cast<unsigned char*>(node);
    auto* key = bytes + 0x10;
    auto* set = static_cast<unsigned char*>(setObject);
    auto* table = *reinterpret_cast<unsigned char**>(set);
    const std::uint64_t hash = HashImageKey(key);
    if (table) {
        const std::uint64_t bucket = hash & *reinterpret_cast<std::uint64_t*>(table + 8);
        std::uint64_t index = bucket;
        auto* entry = reinterpret_cast<std::uint64_t*>(table + 0x10 + index * 0x18);
        if (static_cast<std::int64_t>(entry[0]) != -2 && entry[1] == bucket) {
            for (;;) {
                if (entry[1] == bucket && entry[2] == *reinterpret_cast<std::uint64_t*>(key)) {
                    *reinterpret_cast<std::uint64_t*>(table + 0x20 + index * 0x18) =
                        *reinterpret_cast<std::uint64_t*>(key);
                    break;
                }
                index = entry[0];
                if (index == UINT64_MAX) {
                    FUN_1426869a0(setObject, setObject, key, hash);
                    break;
                }
                entry = reinterpret_cast<std::uint64_t*>(table + 0x10 + index * 0x18);
            }
        } else {
            FUN_1426869a0(setObject, setObject, key, hash);
        }
    } else {
        FUN_1426869a0(setObject, setObject, key, hash);
    }
    void** children = *reinterpret_cast<void***>(bytes + 0x30);
    const std::size_t count = *reinterpret_cast<std::size_t*>(bytes + 0x38);
    for (std::size_t i = 0; i < count; ++i)
        UpdateImageHashTree(children[i], setObject);
}

// MS2-FUNCTIONAL: inserts a key and copied Scaleform string in the cached hash table, rehoming colliding entries and growing at the recovered threshold.
// @0x142686650
void AddStringHashEntry(void* setObject, void* allocator, const std::uint64_t* value, std::uint64_t hash)
{
    auto** set = static_cast<std::uint64_t**>(setObject);
    auto* table = *set;
    std::uint64_t capacity;
    if (!table) {
        capacity = 8;
    } else {
        if (table[0] * 5 <= table[1] * 4 + 4)
            goto insert_string;
        capacity = table[1] * 2 + 2;
    }
    FUN_1426251d0(setObject, allocator, static_cast<std::int64_t>(capacity));
insert_string:
    table = *set;
    const std::uint64_t bucket = hash & table[1];
    ++table[0];
    auto* row = reinterpret_cast<unsigned char*>(table) + bucket * 0x20;
    auto* entry = reinterpret_cast<std::uint64_t*>(row + 0x10);
    const std::uint64_t occupant = entry[0];
    auto* sourceString = reinterpret_cast<const String*>(value[1]);
    if (static_cast<std::int64_t>(occupant) == -2) {
        entry[0] = UINT64_MAX;
        entry[2] = *reinterpret_cast<const std::uint64_t*>(value[0]);
        new (row + 0x28) String(*sourceString);
    } else {
        std::uint64_t empty = bucket;
        do {
            empty = (empty + 1) & table[1];
        } while (static_cast<std::int64_t>(*reinterpret_cast<std::uint64_t*>(
            reinterpret_cast<unsigned char*>(table) + empty * 0x20 + 0x10)) != -2);
        auto* targetBytes = reinterpret_cast<unsigned char*>(table) + empty * 0x20;
        auto* target = reinterpret_cast<std::uint64_t*>(targetBytes + 0x10);
        if (entry[1] == bucket) {
            target[0] = occupant;
            target[1] = entry[1];
            target[2] = entry[2];
            new (targetBytes + 0x28) String(*reinterpret_cast<String*>(row + 0x28));
            entry[0] = empty;
            entry[2] = *reinterpret_cast<const std::uint64_t*>(value[0]);
            *reinterpret_cast<String*>(row + 0x28) = *sourceString;
        } else {
            auto* previous = reinterpret_cast<std::uint64_t*>(reinterpret_cast<unsigned char*>(table) +
                entry[1] * 0x20 + 0x10);
            while (previous[0] != bucket)
                previous = reinterpret_cast<std::uint64_t*>(reinterpret_cast<unsigned char*>(table) +
                    previous[0] * 0x20 + 0x10);
            target[0] = occupant;
            target[1] = entry[1];
            target[2] = entry[2];
            new (targetBytes + 0x28) String(*reinterpret_cast<String*>(row + 0x28));
            previous[0] = empty;
            entry[0] = UINT64_MAX;
            entry[2] = *reinterpret_cast<const std::uint64_t*>(value[0]);
            new (row + 0x28) String(*sourceString);
        }
    }
    entry[1] = bucket;
}

void ResizeStrongPointerArrayB(void**, std::size_t);
static void ResizeRawArray(void**, void*, std::size_t, std::size_t);
void FUN_14257dc30(void*);
// MS2-FUNCTIONAL: merges sampled timing pairs into matching text value records, adding unmatched records with retained ownership.
// @0x14268aff0
extern "C" void FUN_14268aff0(void* destination, void* source)
{
    auto* dst = static_cast<unsigned char*>(destination);
    auto* src = static_cast<unsigned char*>(source);
    const std::size_t sourceCount = *reinterpret_cast<std::size_t*>(src + 0x18);
    auto** sourceRecords = *reinterpret_cast<unsigned char***>(src + 0x10);
    for (std::size_t i = 0; i < sourceCount; ++i) {
        auto* incoming = sourceRecords[i];
        const std::size_t destinationCount = *reinterpret_cast<std::size_t*>(dst + 0x18);
        auto** destinationRecords = *reinterpret_cast<unsigned char***>(dst + 0x10);
        std::size_t match = 0;
        while (match < destinationCount &&
               (*reinterpret_cast<std::uint32_t*>(destinationRecords[match] + 0x10) != *reinterpret_cast<std::uint32_t*>(incoming + 0x10) ||
                *reinterpret_cast<std::uint32_t*>(destinationRecords[match] + 0x14) != *reinterpret_cast<std::uint32_t*>(incoming + 0x14)))
            ++match;

        if (match == destinationCount) {
            std::uint32_t statId = 0x242;
            auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
            auto* copy = static_cast<unsigned char*>(reinterpret_cast<void* (*)(void*, void*, std::size_t, const void*)>(heapVtable[14])(
                DAT_143b15f60, destination, 0x38, &statId));
            if (!copy)
                continue;
            std::memset(copy, 0, 0x38);
            *reinterpret_cast<void**>(copy) = AS3TextValueRecordVtable;
            *reinterpret_cast<std::uint32_t*>(copy + 8) = 1;
            std::memcpy(copy + 0x10, incoming + 0x10, 12);
            const std::size_t sampleCount = *reinterpret_cast<std::size_t*>(incoming + 0x28);
            ResizeRawArray(reinterpret_cast<void**>(copy + 0x20), copy + 0x20, sampleCount, 0x10);
            if (sampleCount)
                std::memcpy(*reinterpret_cast<void**>(copy + 0x20), *reinterpret_cast<void**>(incoming + 0x20), sampleCount * 0x10);
            ResizeStrongPointerArrayB(reinterpret_cast<void**>(dst + 0x10), destinationCount + 1);
            destinationRecords = *reinterpret_cast<unsigned char***>(dst + 0x10);
            FUN_14257dc30(copy);
            destinationRecords[destinationCount] = copy;
            FUN_14257dcb0(copy);
            continue;
        }

        auto* target = destinationRecords[match];
        const std::size_t sourceSamples = *reinterpret_cast<std::size_t*>(incoming + 0x28);
        auto* sourceValues = *reinterpret_cast<unsigned char**>(incoming + 0x20);
        for (std::size_t j = 0; j < sourceSamples; ++j) {
            const std::uint32_t key = *reinterpret_cast<std::uint32_t*>(sourceValues + j * 0x10);
            const std::size_t targetSamples = *reinterpret_cast<std::size_t*>(target + 0x28);
            auto* targetValues = *reinterpret_cast<unsigned char**>(target + 0x20);
            std::size_t valueIndex = 0;
            while (valueIndex < targetSamples && *reinterpret_cast<std::uint32_t*>(targetValues + valueIndex * 0x10) != key)
                ++valueIndex;
            if (valueIndex < targetSamples) {
                *reinterpret_cast<std::uint64_t*>(targetValues + valueIndex * 0x10 + 8) +=
                    *reinterpret_cast<std::uint64_t*>(sourceValues + j * 0x10 + 8);
            } else {
                ResizeRawArray(reinterpret_cast<void**>(target + 0x20), target + 0x20, targetSamples + 1, 0x10);
                targetValues = *reinterpret_cast<unsigned char**>(target + 0x20);
                std::memcpy(targetValues + targetSamples * 0x10, sourceValues + j * 0x10, 0x10);
            }
        }
    }
}

static void AddMovieViewHashEntry(void** setObject, void* allocator, std::uint64_t key, void* value)
{
    auto* table = static_cast<std::uint64_t*>(*setObject);
    std::uint64_t capacity = 8;
    if (table) {
        if (table[0] * 5 > table[1] * 4 + 4)
            capacity = table[1] * 2 + 2;
        else
            capacity = 0;
    }
    if (capacity)
        FUN_1426251d0(setObject, allocator, static_cast<std::int64_t>(capacity));
    table = static_cast<std::uint64_t*>(*setObject);
    const std::uint64_t bucket = HashImageKey(reinterpret_cast<const unsigned char*>(&key)) & table[1];
    auto* home = table + 2 + bucket * 4;
    if (static_cast<std::int64_t>(home[0]) != -2) {
        std::uint64_t index = bucket;
        auto* entry = home;
        while (entry[1] == bucket) {
            if (entry[2] == key) {
                if (value) FUN_14257dc30(value);
                if (entry[3]) FUN_14257dcb0(reinterpret_cast<void*>(entry[3]));
                entry[3] = reinterpret_cast<std::uint64_t>(value);
                return;
            }
            if (entry[0] == UINT64_MAX)
                break;
            index = entry[0];
            entry = table + 2 + index * 4;
        }
        std::uint64_t empty = bucket;
        do {
            empty = (empty + 1) & table[1];
        } while (static_cast<std::int64_t>(table[2 + empty * 4]) != -2);
        ++table[0];
        auto* target = table + 2 + empty * 4;
        if (home[1] == bucket) {
            target[0] = home[0]; target[1] = bucket; target[2] = home[2]; target[3] = home[3];
            home[0] = empty;
        } else {
            std::uint64_t previousIndex = home[1];
            auto* previous = table + 2 + previousIndex * 4;
            while (previous[0] != bucket) {
                previousIndex = previous[0];
                previous = table + 2 + previousIndex * 4;
            }
            target[0] = home[0]; target[1] = home[1]; target[2] = home[2]; target[3] = home[3];
            previous[0] = empty;
            home[0] = UINT64_MAX;
        }
        home = target;
    } else {
        ++table[0];
        home[0] = UINT64_MAX;
        home[1] = bucket;
    }
    if (value) FUN_14257dc30(value);
    home[2] = key;
    home[3] = reinterpret_cast<std::uint64_t>(value);
}

// MS2-FUNCTIONAL: clears the destination cached pointer set and rehashes every live source key/value pair into it.
// @0x142689aa0
extern "C" void FUN_142689aa0(void* destination, void* allocator, void* sourceSet)
{
    auto** destinationSet = static_cast<void**>(destination);
    auto* oldTable = static_cast<std::uint64_t*>(*destinationSet);
    if (oldTable) {
        const std::uint64_t mask = oldTable[1];
        for (std::uint64_t i = 0; i <= mask; ++i) {
            auto* row = oldTable + 2 + i * 4;
            if (static_cast<std::int64_t>(row[0]) == -2)
                continue;
            if (row[3]) FUN_14257dcb0(reinterpret_cast<void*>(row[3]));
            row[0] = UINT64_C(0xfffffffffffffffe);
        }
        oldTable[0] = 0;
    }
    auto* sourceTable = *static_cast<std::uint64_t**>(sourceSet);
    if (!sourceTable)
        return;
    const std::uint64_t mask = sourceTable[1];
    for (std::uint64_t i = 0; i <= mask; ++i) {
        auto* row = sourceTable + 2 + i * 4;
        if (static_cast<std::int64_t>(row[0]) == -2)
            continue;
        AddMovieViewHashEntry(destinationSet, allocator, row[2], reinterpret_cast<void*>(row[3]));
    }
}

// MS2-FUNCTIONAL: clears the destination resource-id map and copies each live keyed Scaleform string entry.
// @0x142689cb0
extern "C" void FUN_142689cb0(void* destination, void* allocator, void* sourceSet)
{
    auto** destinationSet = static_cast<void**>(destination);
    auto* oldTable = static_cast<std::uint64_t*>(*destinationSet);
    if (oldTable) {
        const std::uint64_t mask = oldTable[1];
        for (std::uint64_t i = 0; i <= mask; ++i) {
            auto* row = oldTable + 2 + i * 4;
            if (static_cast<std::int64_t>(row[0]) == -2)
                continue;
            reinterpret_cast<Scaleform::String*>(row + 3)->~String();
            row[0] = UINT64_C(0xfffffffffffffffe);
        }
        oldTable[0] = 0;
    }
    auto* sourceTable = *static_cast<std::uint64_t**>(sourceSet);
    if (!sourceTable)
        return;
    const std::uint64_t mask = sourceTable[1];
    for (std::uint64_t i = 0; i <= mask; ++i) {
        auto* row = sourceTable + 2 + i * 4;
        if (static_cast<std::int64_t>(row[0]) == -2)
            continue;
        const std::uint64_t key = row[2];
        struct StringPair { const void* key; const Scaleform::String* value; } pair{
            &key, reinterpret_cast<const Scaleform::String*>(row + 3)
        };
        AddStringHashEntry(destination, allocator,
            reinterpret_cast<const std::uint64_t*>(&pair),
            HashImageKey(reinterpret_cast<const unsigned char*>(&key)));
    }
}

// MS2-FUNCTIONAL: merges keyed movie-name counters and inserts the source table's retained String values by their 64-bit keys.
// @0x14268b3e0
extern "C" void FUN_14268b3e0(void* destination, void* source)
{
    auto* dst = static_cast<unsigned char*>(destination);
    auto* src = static_cast<unsigned char*>(source);
    const std::size_t sourceCount = *reinterpret_cast<std::size_t*>(src + 0x18);
    auto* sourceRows = *reinterpret_cast<unsigned char**>(src + 0x10);
    for (std::size_t i = 0; i < sourceCount; ++i) {
        auto* incoming = sourceRows + i * 0x18;
        const std::size_t destinationCount = *reinterpret_cast<std::size_t*>(dst + 0x18);
        auto* destinationRows = *reinterpret_cast<unsigned char**>(dst + 0x10);
        std::size_t match = 0;
        while (match < destinationCount &&
               (*reinterpret_cast<std::uint64_t*>(destinationRows + match * 0x18) != *reinterpret_cast<std::uint64_t*>(incoming) ||
                *reinterpret_cast<std::uint32_t*>(destinationRows + match * 0x18 + 8) != *reinterpret_cast<std::uint32_t*>(incoming + 8)))
            ++match;
        if (match < destinationCount) {
            *reinterpret_cast<std::uint64_t*>(destinationRows + match * 0x18 + 0x10) +=
                *reinterpret_cast<std::uint64_t*>(incoming + 0x10);
        } else {
            ResizeRawArray(reinterpret_cast<void**>(dst + 0x10), dst + 0x10, destinationCount + 1, 0x18);
            destinationRows = *reinterpret_cast<unsigned char**>(dst + 0x10);
            std::memcpy(destinationRows + destinationCount * 0x18, incoming, 0x18);
        }
    }

    auto* sourceTable = *reinterpret_cast<unsigned char**>(src + 0x28);
    if (!sourceTable)
        return;
    const std::uint64_t mask = *reinterpret_cast<std::uint64_t*>(sourceTable + 8);
    for (std::uint64_t i = 0; i <= mask; ++i) {
        auto* row = sourceTable + 0x10 + i * 0x20;
        if (*reinterpret_cast<std::int64_t*>(row) == -2)
            continue;
        const std::uint64_t key = *reinterpret_cast<std::uint64_t*>(row + 0x10);
        struct StringPair { const void* key; const Scaleform::String* value; } pair{
            &key, reinterpret_cast<const Scaleform::String*>(row + 0x18)
        };
        Scaleform::AddStringHashEntry(dst + 0x28, dst + 0x28,
            reinterpret_cast<const std::uint64_t*>(&pair), Scaleform::HashImageKey(reinterpret_cast<const unsigned char*>(&key)));
    }
}

// MS2-FUNCTIONAL: intersects the scalar limits, adds unique tagged strings with retained references, and merges the four nested resource tables.
// @0x14268b280
void MergeMovieResourceTables(void* destination, void* source)
{
    auto* dst = static_cast<unsigned char*>(destination);
    auto* src = static_cast<unsigned char*>(source);
    const unsigned firstLimit = *reinterpret_cast<unsigned*>(dst + 0x14);
    const unsigned otherFirst = *reinterpret_cast<unsigned*>(src + 0x14);
    *reinterpret_cast<unsigned*>(dst + 0x14) = firstLimit < otherFirst ? firstLimit : otherFirst;
    const unsigned secondLimit = *reinterpret_cast<unsigned*>(dst + 0x18);
    const unsigned otherSecond = *reinterpret_cast<unsigned*>(src + 0x18);
    *reinterpret_cast<unsigned*>(dst + 0x18) = secondLimit < otherSecond ? secondLimit : otherSecond;

    auto** dstItems = *reinterpret_cast<std::uint64_t***>(dst + 0x40);
    const std::size_t dstCount = *reinterpret_cast<std::size_t*>(dst + 0x48);
    auto** srcItems = *reinterpret_cast<std::uint64_t***>(src + 0x40);
    const std::size_t srcCount = *reinterpret_cast<std::size_t*>(src + 0x48);
    for (std::size_t i = 0; i < srcCount; ++i) {
        const std::uint64_t encoded = *reinterpret_cast<std::uint64_t*>(srcItems[i] + 0x10);
        const char* candidate = reinterpret_cast<const char*>((encoded & ~std::uint64_t(3)) + 0x0c);
        bool duplicate = false;
        for (std::size_t j = 0; j < dstCount; ++j) {
            const std::uint64_t existing = *reinterpret_cast<std::uint64_t*>(dstItems[j] + 0x10);
            const char* text = reinterpret_cast<const char*>((existing & ~std::uint64_t(3)) + 0x0c);
            if (std::strcmp(candidate, text) == 0) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            auto** array = reinterpret_cast<void**>(dst + 0x40);
            ResizeStrongPointerArrayB(array, *reinterpret_cast<std::size_t*>(dst + 0x48) + 1);
            dstItems = *reinterpret_cast<std::uint64_t***>(dst + 0x40);
            FUN_14257dc30(srcItems[i]);
            dstItems[*reinterpret_cast<std::size_t*>(dst + 0x48) - 1] = srcItems[i];
        }
    }
    FUN_14268aff0(*reinterpret_cast<void**>(dst + 0x58), *reinterpret_cast<void**>(src + 0x58));
    FUN_14268a8e0(*reinterpret_cast<void**>(dst + 0x60), *reinterpret_cast<void**>(src + 0x60));
    FUN_14268b3e0(*reinterpret_cast<void**>(dst + 0x68), *reinterpret_cast<void**>(src + 0x68));
    FUN_14268ac40(*reinterpret_cast<void**>(dst + 0x70), *reinterpret_cast<void**>(src + 0x70));
}

// MS2-FUNCTIONAL: performs depth-first child traversal and returns the first node with the requested key.
// @0x14268a870
void* FindTreeNodeByKey(void* node, int key)
{
    auto* bytes = static_cast<unsigned char*>(node);
    if (*reinterpret_cast<int*>(bytes + 0x28) == key)
        return node;
    void** children = *reinterpret_cast<void***>(bytes + 0x30);
    const std::size_t childCount = *reinterpret_cast<std::size_t*>(bytes + 0x38);
    for (std::size_t i = 0; i < childCount; ++i) {
        if (void* found = FindTreeNodeByKey(children[i], key))
            return found;
    }
    return nullptr;
}

// MS2-FUNCTIONAL: appends retained tree entries, repairs cumulative child counters, and merges movie-to-manager hash entries.
// @0x14268ac40
extern "C" void FUN_14268ac40(void* destination, void* source)
{
    auto* dst = static_cast<unsigned char*>(destination);
    auto* src = static_cast<unsigned char*>(source);
    const std::size_t oldCount = *reinterpret_cast<std::size_t*>(dst + 0x20);
    const std::size_t sourceCount = *reinterpret_cast<std::size_t*>(src + 0x20);
    Scaleform::ResizeStrongPointerArrayB(reinterpret_cast<void**>(dst + 0x18), oldCount + sourceCount);
    auto** dstItems = *reinterpret_cast<void***>(dst + 0x18);
    auto** srcItems = *reinterpret_cast<void***>(src + 0x18);
    for (std::size_t i = 0; i < sourceCount; ++i) {
        if (srcItems[i]) FUN_14257dc30(srcItems[i]);
        dstItems[oldCount + i] = srcItems[i];
    }

    const std::size_t count = *reinterpret_cast<std::size_t*>(dst + 0x20);
    for (std::size_t i = 1; i < count; ++i) {
        auto* previous = static_cast<unsigned char*>(dstItems[i - 1]);
        auto* current = static_cast<unsigned char*>(dstItems[i]);
        int base = *reinterpret_cast<int*>(previous + 0x28);
        auto** previousChildren = *reinterpret_cast<void***>(previous + 0x30);
        const std::size_t previousCount = *reinterpret_cast<std::size_t*>(previous + 0x38);
        for (std::size_t j = 0; j < previousCount; ++j)
            Scaleform::UpdateTreeMaximumDepth(previousChildren[j], reinterpret_cast<unsigned*>(&base));
        auto** currentChildren = *reinterpret_cast<void***>(current + 0x30);
        const std::size_t currentCount = *reinterpret_cast<std::size_t*>(current + 0x38);
        for (std::size_t j = 0; j < currentCount; ++j) {
            auto* child = static_cast<unsigned char*>(currentChildren[j]);
            *reinterpret_cast<int*>(child + 0x28) += base;
            auto** grandchildren = *reinterpret_cast<void***>(child + 0x30);
            const std::size_t grandchildCount = *reinterpret_cast<std::size_t*>(child + 0x38);
            for (std::size_t k = 0; k < grandchildCount; ++k)
                Scaleform::AddTreeNodeValue(grandchildren[k], &base);
        }
    }

    auto* sourceTable = *reinterpret_cast<std::uint64_t**>(src + 0x30);
    if (!sourceTable)
        return;
    const std::uint64_t mask = sourceTable[1];
    for (std::uint64_t i = 0; i <= mask; ++i) {
        auto* entry = sourceTable + 2 + i * 4;
        if (static_cast<std::int64_t>(entry[0]) == -2)
            continue;
        AddMovieViewHashEntry(reinterpret_cast<void**>(dst + 0x30), dst + 0x30,
                              entry[2], reinterpret_cast<void*>(entry[3]));
    }
}
}


namespace Scaleform {
// MS2-FUNCTIONAL: locks the sound region at offset zero, clears the first segment, and unlocks it.
// @0x142744600
void ClearSoundBuffer(void* player)
{
    auto* bytes = static_cast<unsigned char*>(player);
    void* sound = *reinterpret_cast<void**>(bytes + 0x30);
    const unsigned length = *reinterpret_cast<unsigned*>(bytes + 0x64);
    void* first = nullptr;
    void* second = nullptr;
    unsigned firstLength = 0;
    unsigned secondLength = 0;
    if (FUN_1428d8ea8(sound, 0, length, &first, &second, &firstLength, &secondLength) == 0) {
        if (first && firstLength)
            memset(first, 0, firstLength);
        FUN_1428d8eae(sound, first, second, firstLength, secondLength);
    }
}
}


namespace Scaleform {
// MS2-FUNCTIONAL: prepares the image viewport transform and dispatches the fill and blend operations through the render context.
// @0x142675790
void DrawImageViewport(void* command, void* contextOwner, void** image, void* state)
{
    auto* owner = static_cast<unsigned char*>(contextOwner);
    void* context = *reinterpret_cast<void**>(owner + 8);
    auto** vtable = *reinterpret_cast<void***>(context);
    const float measured = reinterpret_cast<float (*)(void*)>(vtable[0x1e0 / sizeof(void*)])(context);
    const float scaled = measured * ImageViewportBias;
    struct DrawPayload { std::uint32_t color[4]; float transform[4]; } payload{};
    std::memcpy(payload.color, ImageViewportColor.get(), sizeof(payload.color));
    payload.transform[0] = 0.0f;
    payload.transform[1] = scaled;
    payload.transform[2] = 0.0f;
    payload.transform[3] = ImageViewportOrigin - scaled * ImageViewportScale;
    reinterpret_cast<void (*)(void*, void*, const DrawPayload*, void*)>(vtable[0x188 / sizeof(void*)])(
        context, *image, &payload, static_cast<unsigned char*>(state) + 0x20);
    reinterpret_cast<void (*)(void*, unsigned, unsigned)>(vtable[0x118 / sizeof(void*)])(
        context, static_cast<unsigned>(*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(
            *reinterpret_cast<void**>(static_cast<unsigned char*>(command) + 8)) + 0x48) != 0) + 0x0f, 1);
}

// MS2-FUNCTIONAL: clips a rectangle to the destination image and fills the surviving pixels with the selected alpha-adjusted color.
// @0x142676ac0
void FillClippedImageRect(void* command, void*, void* image)
{
    auto* bytes = static_cast<unsigned char*>(command);
    auto* plane = *reinterpret_cast<unsigned**>(static_cast<unsigned char*>(image) + 0x10);
    const int x0 = static_cast<int>(*reinterpret_cast<unsigned*>(bytes + 0x10));
    const int y0 = static_cast<int>(*reinterpret_cast<unsigned*>(bytes + 0x14));
    const int x1 = *reinterpret_cast<int*>(bytes + 0x18);
    const int y1 = *reinterpret_cast<int*>(bytes + 0x1c);
    if (static_cast<int>(plane[1]) < y0 || y1 < 0 || x1 < 0 || static_cast<int>(plane[0]) < x0)
        return;
    const int left = x0 < 0 ? 0 : x0;
    const int right = x1 < static_cast<int>(plane[0]) ? x1 : static_cast<int>(plane[0]);
    const int top = y0 < 0 ? 0 : y0;
    const int bottom = y1 < static_cast<int>(plane[1]) ? y1 : static_cast<int>(plane[1]);
    const long long pitch = *reinterpret_cast<long long*>(plane + 2);
    const long long base = *reinterpret_cast<long long*>(plane + 6);
    unsigned color = *reinterpret_cast<unsigned*>(bytes + 0x20) | 0xff000000u;
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(*reinterpret_cast<void**>(bytes + 8)) + 0x48))
        color = *reinterpret_cast<unsigned*>(bytes + 0x20);
    for (int y = top; y < bottom; ++y)
        for (int x = left; x < right; ++x)
            FUN_14257d390(image, base + pitch * y, static_cast<unsigned>(x), color);
}

// MS2-FUNCTIONAL: fills every pixel using the executable's image write helper and the stored color value.
// @0x142675ca0
void FillImageData(void* command, void*, void* image)
{
    auto* bytes = static_cast<unsigned char*>(image);
    auto* plane = *reinterpret_cast<unsigned**>(bytes + 0x10);
    const unsigned width = plane[0];
    const unsigned height = plane[1];
    const long long pitch = *reinterpret_cast<long long*>(plane + 2);
    const long long base = *reinterpret_cast<long long*>(plane + 6);
    const unsigned color = *reinterpret_cast<unsigned*>(static_cast<char*>(command) + 0x10);
    for (unsigned y = 0; y < height; ++y) {
        for (unsigned x = 0; x < width; ++x)
            FUN_14257d390(image, base + pitch * y, x, color);
    }
}

}



namespace Scaleform {
// MS2-FUNCTIONAL: closes the callback stream with the executable's common state reset helper.
// @0x142745410
unsigned long long CloseAudioStream(void*, void* stream)
{
    FUN_1427483a0(stream, 0);
    return 0;
}

// MS2-FUNCTIONAL: initializes a callback stream, stores its handle and the executable's 0x0fffffff limit.
// @0x142745430
unsigned long long OpenAudioStream(void* stream, void*, unsigned* length, void*, void** handle)
{
    FUN_1427483a0(stream, 0);
    *handle = stream;
    *length = 0x0fffffff;
    return 0;
}

// MS2-FUNCTIONAL: returns the callback's success code or the executable's error value 20.
// @0x142745490
unsigned long long ValidateAudioStream(void*, void*, void* stream)
{
    return FUN_1427483a0(stream, 0) == 0 ? 20 : 0;
}
}


namespace Scaleform {
// MS2-FUNCTIONAL: reads callback bytes from the fifth-argument stream state and reports the count.
// @0x142745470
unsigned long long ReadAudioCallback(void*, void* buffer, unsigned bytes, unsigned* bytesRead, void* stream)
{
    *bytesRead = static_cast<unsigned>(FUN_142748160(stream, buffer, bytes));
    return 0;
}
}


namespace Scaleform {
// MS2-FUNCTIONAL: builds the requested FMOD mode, clears the output handle on failure, and returns FMOD status.
// @0x1427453b0
FMOD_RESULT CreateAudioSound(void* player, void* request, FMOD::Sound** sound)
{
    auto* requestBytes = static_cast<unsigned char*>(request);
    void* owner = *reinterpret_cast<void**>(static_cast<char*>(player) + 0x28);
    auto* system = reinterpret_cast<FMOD::System*>(*reinterpret_cast<void**>(static_cast<char*>(owner) + 0x10));
    const unsigned flags = (*reinterpret_cast<unsigned*>(requestBytes + 0x10) & 0x1000) ? 0xc0u : 0x4040u;
    const FMOD_RESULT result = system->createSound(*reinterpret_cast<char**>(requestBytes + 0x20), flags, nullptr, sound);
    if (result != 0)
        *sound = nullptr;
    return result;
}
}


namespace Scaleform {
// MS2-FUNCTIONAL: validates the encoded sample format, prepares the 0xd8-byte FMOD info block, and creates the sound.
// @0x1427452e0
FMOD_RESULT CreateAudioSoundFromRequest(void* player, void* request, FMOD::Sound** sound)
{
    auto* requestBytes = static_cast<unsigned char*>(request);
    const unsigned format = *reinterpret_cast<unsigned*>(requestBytes + 0x10);
    unsigned flags;
    unsigned channels = 0;
    unsigned defaultFrequency = 0;
    unsigned soundFormat;
    if ((format & 0x700) == 0x100) {
        flags = 0x1a001040;
        defaultFrequency = *reinterpret_cast<unsigned*>(requestBytes + 0x14);
        channels = ((format & 7) == 2) + 1;
        soundFormat = ((format & 8) != 0) + 1;
    } else if ((format & 0x700) == 0x200) {
        flags = 0x1a000240;
        soundFormat = 0xb;
    } else {
        return static_cast<FMOD_RESULT>(0x19);
    }

    unsigned char info[0xd8] = {};
    *reinterpret_cast<unsigned*>(info) = sizeof(info);
    *reinterpret_cast<unsigned*>(info + 4) = *reinterpret_cast<unsigned*>(requestBytes + 0x28);
    *reinterpret_cast<unsigned*>(info + 0x0c) = channels;
    *reinterpret_cast<unsigned*>(info + 0x10) = defaultFrequency;
    *reinterpret_cast<unsigned*>(info + 0x14) = soundFormat;
    void* owner = *reinterpret_cast<void**>(static_cast<char*>(player) + 0x28);
    auto* system = reinterpret_cast<FMOD::System*>(*reinterpret_cast<void**>(static_cast<char*>(owner) + 0x10));
    return system->createSound(*reinterpret_cast<char**>(requestBytes + 0x20), flags,
                               reinterpret_cast<FMOD_CREATESOUNDEXINFO*>(info), sound);
}
}


namespace Scaleform {
// MS2-FUNCTIONAL: constructs the callback-backed FMOD stream descriptor for the two accepted request formats.
// @0x1427450b0
FMOD_RESULT CreateBufferedAudioStream(void* player, const char* path, FMOD::Sound** sound)
{
    const unsigned format = *reinterpret_cast<const unsigned*>(path + 0x10);
    unsigned mode;
    unsigned channels = 0;
    unsigned frequency = 0;
    unsigned soundFormat;
    if ((format & 0x700) == 0x100) {
        mode = 0x2003040;
        frequency = *reinterpret_cast<const unsigned*>(path + 0x14);
        channels = ((format & 7) == 2) + 1;
        soundFormat = ((format & 8) != 0) + 1;
    } else if ((format & 0x700) == 0x200) {
        mode = 0x2002040;
        soundFormat = 0xb;
    } else {
        return static_cast<FMOD_RESULT>(0x19);
    }

    unsigned char info[0xd8] = {};
    *reinterpret_cast<unsigned*>(info) = sizeof(info);
    *reinterpret_cast<unsigned*>(info + 4) = 0x0fffffff;
    *reinterpret_cast<unsigned*>(info + 0x0c) = channels;
    *reinterpret_cast<unsigned*>(info + 0x10) = frequency;
    *reinterpret_cast<unsigned*>(info + 0x14) = soundFormat;
    *reinterpret_cast<unsigned*>(info + 0x18) = 0x2000;
    using Callback = void (*)();
    *reinterpret_cast<Callback*>(info + 0x78) = reinterpret_cast<Callback>(&OpenAudioStream);
    *reinterpret_cast<Callback*>(info + 0x80) = reinterpret_cast<Callback>(&CloseAudioStream);
    *reinterpret_cast<Callback*>(info + 0x88) = reinterpret_cast<Callback>(&ReadAudioCallback);
    *reinterpret_cast<Callback*>(info + 0x90) = reinterpret_cast<Callback>(&ValidateAudioStream);

    auto* playerBytes = static_cast<char*>(player);
    auto* system = reinterpret_cast<FMOD::System*>(*reinterpret_cast<void**>(playerBytes + 0x10));
    return system->createStream(path, mode, reinterpret_cast<FMOD_CREATESOUNDEXINFO*>(info), sound);
}

// MS2-FUNCTIONAL: resolves the stream owner and writes the created FMOD stream into the request record.
// @0x142744680
bool CreateRequestAudioStream(void* request)
{
    auto* bytes = static_cast<unsigned char*>(request);
    auto* owner = *reinterpret_cast<void**>(bytes + 0x38);
    if (!owner)
        return false;
    const char* path = *reinterpret_cast<const char**>(bytes + 0x28);
    auto* sound = reinterpret_cast<FMOD::Sound**>(bytes + 0x30);
    return CreateBufferedAudioStream(owner, path, sound) == 0;
}
}


namespace Scaleform {
// MS2-FUNCTIONAL: sets the FMOD file callbacks, metadata fields, loop settings, and format-specific mode.
// @0x1427451c0
FMOD_RESULT CreateMetadataAudioSound(void* player, const char* path, FMOD::Sound** sound)
{
    const unsigned format = *reinterpret_cast<const unsigned*>(path + 0x10);
    unsigned mode = 0xa0000c0;
    unsigned channels = 0;
    if ((format & 0x700) == 0x100) {
        mode = 0xa0010c0;
        channels = ((format & 7) == 2) + 1;
    } else if ((format & 0x700) != 0x200) {
        return static_cast<FMOD_RESULT>(0x19);
    }

    unsigned char info[0xd8] = {};
    *reinterpret_cast<unsigned*>(info) = sizeof(info);
    *reinterpret_cast<unsigned*>(info + 0x0c) = channels;
    *reinterpret_cast<unsigned*>(info + 0x10) = *reinterpret_cast<const unsigned*>(path + 0x14);
    *reinterpret_cast<unsigned*>(info + 0x14) = (format & 0x700) == 0x200 ? 0xbu : (((format & 8) != 0) + 1);
    *reinterpret_cast<unsigned*>(info + 0x18) = 0x1000;
    *reinterpret_cast<unsigned*>(info + 0xb8) = *reinterpret_cast<const unsigned*>(path + 0x1c);
    *reinterpret_cast<unsigned*>(info + 0xbc) = 2;
    using Callback = void (*)();
    *reinterpret_cast<Callback*>(info + 0x78) = reinterpret_cast<Callback>(&OpenAudioStream);
    *reinterpret_cast<Callback*>(info + 0x80) = reinterpret_cast<Callback>(&CloseAudioStream);
    *reinterpret_cast<Callback*>(info + 0x88) = reinterpret_cast<Callback>(&ReadAudioCallback);
    *reinterpret_cast<Callback*>(info + 0x90) = reinterpret_cast<Callback>(&ValidateAudioStream);

    void* owner = *reinterpret_cast<void**>(static_cast<char*>(player) + 0x28);
    auto* system = reinterpret_cast<FMOD::System*>(*reinterpret_cast<void**>(static_cast<char*>(owner) + 0x10));
    return system->createSound(path, mode, reinterpret_cast<FMOD_CREATESOUNDEXINFO*>(info), sound);
}
}

extern "C" void* DAT_143b15f60;

namespace Scaleform {
static void ReserveHeapArray(void** array, void* heapOwner, std::size_t requested,
                             std::size_t elementBytes, bool localHeap)
{
    auto** vtable = *reinterpret_cast<void***>(DAT_143b15f60);
    auto* data = static_cast<unsigned char*>(array[0]);
    if (!requested) {
        if (data)
            reinterpret_cast<void (*)(void*, void*)>(vtable[12])(DAT_143b15f60, data);
        array[0] = nullptr;
        array[2] = nullptr;
        return;
    }
    const std::size_t capacity = (requested + 3) & ~std::size_t(3);
    if (data) {
        array[0] = reinterpret_cast<void* (*)(void*, void*, std::size_t)>(vtable[11])(
            DAT_143b15f60, data, capacity * elementBytes);
    } else {
        unsigned flags[2] = { 2, 0 };
        if (localHeap)
            array[0] = reinterpret_cast<void* (*)(void*, void*, std::size_t, const void*)>(vtable[14])(
                DAT_143b15f60, heapOwner, capacity * elementBytes, flags);
        else
            array[0] = reinterpret_cast<void* (*)(void*, std::size_t, const void*)>(vtable[10])(
                DAT_143b15f60, capacity * elementBytes, flags);
    }
    array[2] = reinterpret_cast<void*>(capacity);
}

// MS2-FUNCTIONAL: rounds capacity to four values and allocates or reallocates 32-byte records.
// @0x14268e420
void ReserveValueRecordArray(void** array, void* heapOwner, std::size_t requested)
{
    ReserveHeapArray(array, heapOwner, requested, 32, false);
}

// MS2-FUNCTIONAL: rounds pointer capacity to four slots and uses the global heap's allocate, reallocate, and free paths.
// @0x142678170
void ReserveGlobalPointerArray(void** array, void*, std::size_t requested)
{
    ReserveHeapArray(array, nullptr, requested, 8, false);
}

// MS2-FUNCTIONAL: uses the local heap owner and eight-byte element stride observed by the executable.
// @0x14268e4c0
void ReserveLocalPointerArrayA(void** array, void* heapOwner, std::size_t requested)
{
    ReserveHeapArray(array, heapOwner, requested, 8, true);
}

// MS2-FUNCTIONAL: preserves the local heap allocation and four-element capacity rounding.
// @0x14268e560
void ReserveLocalPointerArrayB(void** array, void* heapOwner, std::size_t requested)
{
    ReserveHeapArray(array, heapOwner, requested, 8, true);
}

// MS2-FUNCTIONAL: preserves the local heap allocation and four-element capacity rounding.
// @0x14268e600
void ReserveLocalPointerArrayC(void** array, void* heapOwner, std::size_t requested)
{
    ReserveHeapArray(array, heapOwner, requested, 8, true);
}

static void ResizeRawArray(void** array, void* heapOwner, std::size_t requested, std::size_t stride)
{
    const std::size_t oldSize = reinterpret_cast<std::size_t>(array[1]);
    const std::size_t capacity = reinterpret_cast<std::size_t>(array[2]);
    if (requested < oldSize) {
        if (requested < (capacity >> 1))
            ReserveHeapArray(array, heapOwner, requested, stride, true);
    } else if (capacity <= requested) {
        ReserveHeapArray(array, heapOwner, requested + (requested >> 2), stride, true);
    }
    array[1] = reinterpret_cast<void*>(requested);
}

// MS2-FUNCTIONAL: applies the observed quarter-growth and half-shrink rules to the byte array.
// @0x14268e840
void ResizeLocalByteArray(void** array, std::size_t requested)
{
    ResizeRawArray(array, array, requested, 1);
}

// MS2-FUNCTIONAL: applies the same backing-array thresholds to the eight-byte record array.
// @0x14268e9a0
void ResizeLocalRecordArray(void** array, std::size_t requested)
{
    ResizeRawArray(array, array, requested, 8);
}
}

void FUN_14257dcb0(void* object);
void FUN_14257dc30(void* object);
unsigned long long FUN_1425e3480();
int FUN_1428d8ed8(void*, bool);

namespace Scaleform {
static void ResizeStrongPointerArray(void** array, void* heapOwner, std::size_t requested)
{
    const std::size_t oldSize = reinterpret_cast<std::size_t>(array[1]);
    const std::size_t capacity = reinterpret_cast<std::size_t>(array[2]);
    auto** elements = static_cast<void**>(array[0]);
    if (requested < oldSize) {
        for (std::size_t i = oldSize; i > requested; --i)
            if (elements[i - 1]) FUN_14257dcb0(elements[i - 1]);
        if (requested < (capacity >> 1))
            ReserveLocalPointerArrayA(array, heapOwner, requested);
    } else if (capacity <= requested) {
        ReserveLocalPointerArrayA(array, heapOwner, requested + (requested >> 2));
    }
    array[1] = reinterpret_cast<void*>(requested);
}

// MS2-FUNCTIONAL: releases removed strong references, follows Scaleform's capacity thresholds, and updates size.
// @0x14268ea20
void ResizeStrongPointerArrayA(void** array, std::size_t requested)
{
    ResizeStrongPointerArray(array, array, requested);
}

// MS2-FUNCTIONAL: releases removed strong references, follows Scaleform's capacity thresholds, and updates size.
// @0x14268eac0
void ResizeStrongPointerArrayB(void** array, std::size_t requested)
{
    ResizeStrongPointerArray(array, array, requested);
}

// MS2-FUNCTIONAL: releases removed strong references, follows Scaleform's capacity thresholds, and updates size.
// @0x14268eb60
void ResizeStrongPointerArrayC(void** array, std::size_t requested)
{
    ResizeStrongPointerArray(array, array, requested);
}

// MS2-FUNCTIONAL: releases removed strong references, follows Scaleform's capacity thresholds, and updates size.
// @0x14268ec00
void ResizeStrongPointerArrayD(void** array, std::size_t requested)
{
    ResizeStrongPointerArray(array, array, requested);
}

// MS2-FUNCTIONAL: releases truncated string storage and default-constructs every newly added element.
// @0x14268e8c0
void ResizeStringArray(void** array, std::size_t requested)
{
    const std::size_t oldSize = reinterpret_cast<std::size_t>(array[1]);
    const std::size_t capacity = reinterpret_cast<std::size_t>(array[2]);
    auto* elements = static_cast<unsigned long long*>(array[0]);
    if (requested < oldSize) {
        auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
        for (std::size_t i = oldSize; i > requested; --i) {
            const auto encoded = elements[i - 1];
            if (!encoded) continue;
            auto* data = reinterpret_cast<unsigned char*>(encoded & ~3ull);
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(data + 8)) == 0)
                reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, data);
        }
        if (requested < (capacity >> 1))
            ReserveLocalPointerArrayA(array, array, requested);
    } else if (capacity <= requested) {
        ReserveLocalPointerArrayA(array, array, requested + (requested >> 2));
    }
    elements = static_cast<unsigned long long*>(array[0]);
    array[1] = reinterpret_cast<void*>(requested);
    for (std::size_t i = oldSize; i < requested; ++i)
        new (elements + i) Scaleform::String();
}
}

namespace Scaleform {
// MS2-FUNCTIONAL: releases live cached values, marks each bucket as a tombstone, then frees the bucket table.
// @0x142689f10
void ClearCachedHashSet(void* hashSet)
{
    auto** set = static_cast<void**>(hashSet);
    auto* table = static_cast<unsigned char*>(set[0]);
    if (!table)
        return;
    const std::size_t buckets = *reinterpret_cast<std::size_t*>(table + 8) + 1;
    for (std::size_t i = 0; i < buckets; ++i) {
        auto* node = table + 0x10 + i * 0x20;
        if (*reinterpret_cast<long long*>(node) == -2)
            continue;
        void* value = *reinterpret_cast<void**>(node + 0x18);
        if (value)
            FUN_14257dcb0(value);
        *reinterpret_cast<long long*>(node) = -2;
    }
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, table);
    set[0] = nullptr;
}

// MS2-FUNCTIONAL: releases cached styles by their encoded reference-count pointer and frees the table storage.
// @0x142689fa0
void ClearStyleHashSet(void* hashSet)
{
    auto** set = static_cast<void**>(hashSet);
    auto* table = static_cast<unsigned char*>(set[0]);
    if (!table)
        return;
    const std::size_t buckets = *reinterpret_cast<std::size_t*>(table + 8) + 1;
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    for (std::size_t i = 0; i < buckets; ++i) {
        auto* node = table + 0x10 + i * 0x20;
        if (*reinterpret_cast<long long*>(node) == -2)
            continue;
        const auto encoded = *reinterpret_cast<unsigned long long*>(node + 0x18);
        if (encoded) {
            auto* object = reinterpret_cast<unsigned char*>(encoded & ~3ull);
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(object + 8)) == 0)
                reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, object);
        }
        *reinterpret_cast<long long*>(node) = -2;
    }
    reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, table);
    set[0] = nullptr;
}
}


namespace Scaleform {
// MS2-FUNCTIONAL: serializes pause changes, updates paused timestamps, and pulses the completion event on resume.
// @0x142745eb0
void SetAudioPaused(void* player, bool paused)
{
    auto* bytes = static_cast<unsigned char*>(player);
    auto* lock = reinterpret_cast<CRITICAL_SECTION*>(bytes + 0x70);
    EnterCriticalSection(lock);
    if (static_cast<bool>(bytes[0x68]) != paused) {
        void* channel = *reinterpret_cast<void**>(bytes + 0x38);
        if (channel)
            FUN_1428d8ed8(channel, paused);
        bytes[0x68] = paused;
        const long long now = static_cast<long long>(FUN_1425e3480());
        if (!paused) {
            *reinterpret_cast<long long*>(bytes + 0x48) = now;
            auto* event = reinterpret_cast<Scaleform::Event*>(*reinterpret_cast<void**>(bytes + 0x28));
            event->PulseEvent();
        } else {
            *reinterpret_cast<long long*>(bytes + 0x50) = now;
            auto* accumulated = reinterpret_cast<long long*>(bytes + 0x58);
            *accumulated += now - *reinterpret_cast<long long*>(bytes + 0x48);
        }
    }
    LeaveCriticalSection(lock);
}

// MS2-FUNCTIONAL: computes elapsed playback time under the player's lock and clamps/records the audio end time.
// @0x142745980
float QueryAudioElapsedSeconds(void* player)
{
    auto* bytes = static_cast<unsigned char*>(player);
    EnterCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(bytes + 0x70));
    float elapsedSeconds;
    if (!bytes[0x68] && !bytes[0x69]) {
        auto* format = *reinterpret_cast<unsigned char**>(bytes + 0x30);
        const std::uint64_t rate = *reinterpret_cast<unsigned*>(format + 0x4c);
        const std::uint64_t bitDepth = *reinterpret_cast<unsigned*>(format + 0x50);
        const std::uint64_t sampleFrames = *reinterpret_cast<unsigned*>(format + 0x70);
        const std::uint64_t channels = *reinterpret_cast<unsigned*>(format + 0x48);
        const std::uint64_t totalSamples = ((sampleFrames * 8) / bitDepth) / channels;
        const std::uint64_t duration = (totalSamples * 1000000ull) / rate;
        const std::uint64_t now = FUN_1425e3480();
        std::uint64_t elapsed = (*reinterpret_cast<std::uint64_t*>(bytes + 0x58) -
                                 *reinterpret_cast<std::uint64_t*>(bytes + 0x48)) + now;
        if (duration < elapsed) {
            bytes[0x69] = 1;
            *reinterpret_cast<std::uint64_t*>(bytes + 0x50) = now;
            *reinterpret_cast<std::uint64_t*>(bytes + 0x58) = duration;
            elapsed = duration;
        }
        elapsedSeconds = *reinterpret_cast<float*>(bytes + 0x98) +
                         static_cast<float>(elapsed) / 1000000.0f;
    } else {
        elapsedSeconds = *reinterpret_cast<float*>(bytes + 0x98) +
                         static_cast<float>(*reinterpret_cast<std::uint64_t*>(bytes + 0x58)) / 1000000.0f;
    }
    LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(bytes + 0x70));
    return elapsedSeconds;
}

// MS2-FUNCTIONAL: applies loop bounds in milliseconds and schedules the channel's loop delay from the DSP clock.
// @0x142745c80
void ConfigureAudioLoop(void* player, int loopCount, float startSeconds, float endSeconds)
{
    auto* bytes = static_cast<unsigned char*>(player);
    auto* channel = *reinterpret_cast<FMOD::Channel**>(bytes + 0x38);
    if (!channel || loopCount == 0)
        return;
    if (loopCount > 1) {
        FUN_1428d8f02(channel, 2);
        FUN_1428d8f08(channel, loopCount);
    }

    auto* request = *reinterpret_cast<unsigned char**>(bytes + 0x30);
    auto* metadata = *reinterpret_cast<unsigned char**>(request + 0x38);
    unsigned start = metadata ? *reinterpret_cast<unsigned*>(metadata + 0x18) : 0;
    unsigned loopLength = metadata ? *reinterpret_cast<unsigned*>(metadata + 0x1c) : 0;
    auto* sound = *reinterpret_cast<FMOD::Sound**>(request + 0x30);
    unsigned soundLength = 0;
    sound->getLength(&soundLength, 2);
    float defaults[10] = {};
    FUN_1428d8eb4(sound, defaults, nullptr, nullptr, nullptr);
    if (startSeconds > 0.0f)
        start = static_cast<unsigned>(static_cast<long long>(defaults[0] * startSeconds));
    unsigned end = static_cast<unsigned>(static_cast<long long>(defaults[0] * endSeconds));
    if (end == 0 || soundLength - 1 < end) {
        end = start + loopLength;
        if (loopLength == 0)
            end = soundLength - 1;
    }
    FUN_1428d8ef6(channel, start, 2);
    FUN_1428d8f0e(channel, start, 2, end, 2);

    auto* manager = *reinterpret_cast<unsigned char**>(bytes + 0x28);
    auto* system = *reinterpret_cast<FMOD::System**>(manager + 0x10);
    unsigned clockHigh = 0, clockLow = 0;
    FUN_1428d8ea2(system, &clockHigh, &clockLow);
    const float duration = static_cast<float>((end - start) * loopCount) *
                           (*reinterpret_cast<float*>(manager + 0xf4) / defaults[0]);
    const unsigned delay = static_cast<unsigned>(static_cast<long long>(duration));
    const unsigned nextLow = clockLow + delay;
    clockHigh += nextLow < clockLow;
    FUN_1428d8ef0(channel, 2, clockHigh, nextLow);
}
}

namespace Scaleform {
// MS2-FUNCTIONAL: destroys an audio request record, releases its FMOD sound when the final request reference drops, and unlinks it from its owner list.
// @0x1427462b0
void ReleaseAudioRequestRecord(void* request)
{
    auto* bytes = static_cast<unsigned char*>(request);
    *reinterpret_cast<void**>(bytes + 0x18) = nullptr;
    auto* references = reinterpret_cast<volatile long*>(bytes - 8);
    long count = *references;
    while (count != 0) {
        if (InterlockedCompareExchange(references, count + 1, count) == count) {
            auto* sound = *reinterpret_cast<FMOD::Sound**>(bytes + 0x20);
            if (sound)
                sound->release();
            *reinterpret_cast<FMOD::Sound**>(bytes + 0x20) = nullptr;
            auto* previous = *reinterpret_cast<void**>(bytes + 8);
            auto* next = *reinterpret_cast<void**>(bytes + 0x10);
            if (next) {
                *reinterpret_cast<void**>(static_cast<unsigned char*>(previous) + 0x10) = next;
                *reinterpret_cast<void**>(static_cast<unsigned char*>(next) + 8) = previous;
                *reinterpret_cast<void**>(bytes + 8) = nullptr;
                *reinterpret_cast<void**>(bytes + 0x10) = nullptr;
            }
            if (InterlockedDecrement(references) == 1) {
                void** object = reinterpret_cast<void**>(bytes - 0x10);
                reinterpret_cast<void (*)(void*, unsigned)>((*reinterpret_cast<void***>(object))[0])(object, 1);
            }
            return;
        }
        count = *references;
    }
    auto* next = *reinterpret_cast<void**>(bytes + 0x10);
    if (next) {
        auto* previous = *reinterpret_cast<void**>(bytes + 8);
        *reinterpret_cast<void**>(static_cast<unsigned char*>(previous) + 0x10) = next;
        *reinterpret_cast<void**>(static_cast<unsigned char*>(next) + 8) = previous;
        *reinterpret_cast<void**>(bytes + 8) = nullptr;
        *reinterpret_cast<void**>(bytes + 0x10) = nullptr;
    }
}

// MS2-FUNCTIONAL: clears a player sound's callback data, drops its FMOD sound when referenced, and detaches its list node.
// @0x142746380
void ClearPlayerSoundRecord(void* request)
{
    auto* bytes = static_cast<unsigned char*>(request);
    *reinterpret_cast<void**>(bytes + 0x28) = nullptr;
    if (*reinterpret_cast<long*>(bytes - 8) > 0) {
        auto* sound = *reinterpret_cast<FMOD::Sound**>(bytes + 0x20);
        if (sound)
            sound->release();
        *reinterpret_cast<FMOD::Sound**>(bytes + 0x20) = nullptr;
    }
    auto* next = *reinterpret_cast<void**>(bytes + 0x10);
    if (next) {
        auto* previous = *reinterpret_cast<void**>(bytes + 8);
        *reinterpret_cast<void**>(static_cast<unsigned char*>(previous) + 0x10) = next;
        *reinterpret_cast<void**>(static_cast<unsigned char*>(next) + 8) = previous;
        *reinterpret_cast<void**>(bytes + 8) = nullptr;
        *reinterpret_cast<void**>(bytes + 0x10) = nullptr;
    }
}

// MS2-FUNCTIONAL: rounds pointer capacity to four entries, reallocates through the global heap, and frees storage when capacity is zero.
// @0x1427463e0
void ReserveVideoPlayerArray(void** array, void*, std::size_t requested)
{
    auto** vtable = *reinterpret_cast<void***>(DAT_143b15f60);
    void* data = array[0];
    std::size_t capacity = requested ? ((requested + 3) & ~std::size_t(3)) : 0;
    if (!capacity) {
        if (data)
            reinterpret_cast<void (*)(void*, void*)>(vtable[12])(DAT_143b15f60, data);
        array[0] = nullptr;
        array[2] = nullptr;
        return;
    }
    const std::size_t bytes = capacity * sizeof(void*);
    if (data) {
        array[0] = reinterpret_cast<void* (*)(void*, void*, std::size_t)>(vtable[11])(DAT_143b15f60, data, bytes);
    } else {
        int flags = 2;
        array[0] = reinterpret_cast<void* (*)(void*, std::size_t, const int*)>(vtable[10])(DAT_143b15f60, bytes, &flags);
    }
    array[2] = reinterpret_cast<void*>(capacity);
}

// MS2-FUNCTIONAL: initializes an empty hash table at eight slots and doubles it when live entries exceed its 80 percent load threshold.
// @0x142689ec0
void CheckExpandAS3HashSet(void** set, void* owner)
{
    auto* table = static_cast<std::size_t*>(*set);
    if (!table) {
        FUN_1426906b0(set, owner, 8);
        return;
    }
    if (table[1] * 4 + 4 < table[0] * 5)
        FUN_1426906b0(set, owner, table[1] * 2 + 2);
}

// MS2-FUNCTIONAL: applies the same empty-table initialization and 80 percent expansion test to this hash layout.
// @0x142744560
void CheckExpandAS3PointerSet(void** set, void* owner)
{
    auto* table = static_cast<std::size_t*>(*set);
    if (!table) {
        FUN_142747530(set, owner, 8);
        return;
    }
    if (table[1] * 4 + 4 < table[0] * 5)
        FUN_142747530(set, owner, table[1] * 2 + 2);
}

// MS2-FUNCTIONAL: applies the same empty-table initialization and 80 percent expansion test to this hash layout.
// @0x1427445b0
void CheckExpandAS3CachedSet(void** set, void* owner)
{
    auto* table = static_cast<std::size_t*>(*set);
    if (!table) {
        FUN_1427478c0(set, owner, 8);
        return;
    }
    if (table[1] * 4 + 4 < table[0] * 5)
        FUN_1427478c0(set, owner, table[1] * 2 + 2);
}

// MS2-FUNCTIONAL: decrements every encoded object's reference count, frees objects released by the array, then frees the backing buffer.
// @0x142687170
void DestroyStrongReferenceArray(void** array)
{
    auto* elements = static_cast<unsigned long long*>(array[0]);
    const std::size_t count = reinterpret_cast<std::size_t>(array[1]);
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    for (std::size_t i = count; i != 0; --i) {
        const auto encoded = elements[i - 1];
        auto* object = reinterpret_cast<unsigned char*>(encoded & ~3ull);
        auto* refs = reinterpret_cast<volatile long*>(object + 8);
        if (encoded && InterlockedDecrement(refs) == 1)
            reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, object);
    }
    reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, elements);
}

// MS2-FUNCTIONAL: marks each occupied fixed-width hash bucket deleted, frees the table allocation, and clears the set pointer.
// @0x1426871f0
void ClearFixedHashSet(void** set)
{
    auto* table = static_cast<unsigned char*>(set[0]);
    if (!table)
        return;
    const std::size_t buckets = *reinterpret_cast<std::size_t*>(table + 8) + 1;
    for (std::size_t i = 0; i < buckets; ++i) {
        auto* marker = reinterpret_cast<long long*>(table + 0x10 + i * 0x38);
        if (*marker != -2)
            *marker = -2;
    }
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, table);
    set[0] = nullptr;
}

static void WriteImageStream(void* stream, const void* data, unsigned size)
{
    auto** streamVtable = *reinterpret_cast<void***>(stream);
    reinterpret_cast<void (*)(void*, const void*, unsigned)>(streamVtable[9])(stream, data, size);
}

void WriteNarrowString(void*, const String*);
void WriteTextTreeNode(const void*, void*, unsigned);
void WriteTextRecordGroup(void*, void*, unsigned);

// MS2-FUNCTIONAL: writes the collection count, each image record header, and every nested 16-byte entry through the stream vtable.
// @0x14268f4b0
void WriteImageMetadataRecords(void* object, void* stream)
{
    auto* bytes = static_cast<unsigned char*>(object);
    unsigned value = static_cast<unsigned>(*reinterpret_cast<std::size_t*>(bytes + 0x18));
    WriteImageStream(stream, &value, 4);
    void** records = *reinterpret_cast<void***>(bytes + 0x10);
    const std::size_t count = *reinterpret_cast<std::size_t*>(bytes + 0x18);
    for (std::size_t i = 0; i < count; ++i) {
        auto* record = static_cast<unsigned char*>(records[i]);
        value = *reinterpret_cast<unsigned*>(record + 0x10); WriteImageStream(stream, &value, 4);
        value = *reinterpret_cast<unsigned*>(record + 0x14); WriteImageStream(stream, &value, 4);
        value = *reinterpret_cast<unsigned*>(record + 0x18); WriteImageStream(stream, &value, 4);
        const std::size_t nestedCount = *reinterpret_cast<std::size_t*>(record + 0x28);
        value = static_cast<unsigned>(nestedCount); WriteImageStream(stream, &value, 4);
        auto* nested = *reinterpret_cast<unsigned char**>(record + 0x20);
        for (std::size_t j = 0; j < nestedCount; ++j) {
            WriteImageStream(stream, nested + j * 0x10, 4);
            WriteImageStream(stream, nested + j * 0x10 + 8, 8);
        }
    }
}

// MS2-FUNCTIONAL: serializes the versioned movie image data, nested image records, and trailing resource tables.
// @0x14268f600
void WriteMovieImageData(void* object, void* stream, unsigned version)
{
    auto* bytes = static_cast<unsigned char*>(object);
    WriteImageStream(stream, bytes + 0x10, 4);
    WriteImageStream(stream, bytes + 0x14, 4);
    WriteImageStream(stream, bytes + 0x18, 4);
    if (version > 3) {
        WriteNarrowString(stream, reinterpret_cast<const String*>(bytes + 0x20));
        WriteImageStream(stream, bytes + 0x28, 4);
        WriteImageStream(stream, bytes + 0x2c, 4);
        WriteImageStream(stream, bytes + 0x30, 4);
        WriteImageStream(stream, bytes + 0x34, 4);
        WriteImageStream(stream, bytes + 0x38, 4);
    }
    if (version > 5) {
        const std::size_t count = *reinterpret_cast<std::size_t*>(bytes + 0x48);
        unsigned count32 = static_cast<unsigned>(count);
        WriteImageStream(stream, &count32, 4);
        auto** entries = *reinterpret_cast<void***>(bytes + 0x40);
        for (std::size_t i = 0; i < count; ++i) {
            auto* entry = static_cast<unsigned char*>(entries[i]);
            if (version > 10)
                WriteNarrowString(stream, reinterpret_cast<const String*>(entry + 0x10));
            WriteImageStream(stream, entry + 0x18, 4);
        }
    }
    WriteImageMetadataRecords(*reinterpret_cast<void**>(bytes + 0x58), stream);
    FUN_14268ef30(*reinterpret_cast<void**>(bytes + 0x60), stream, version);
    FUN_14268f8f0(*reinterpret_cast<void**>(bytes + 0x68), stream, version);
    if (version > 0x18)
        WriteTextRecordGroup(*reinterpret_cast<void**>(bytes + 0x70), stream, version);
}

// MS2-FUNCTIONAL: writes the version-nine string resource arrays and each occupied cached hash entry with its length-prefixed name.
// @0x14268f8f0
void WriteStringResourceTable(void* object, void* stream, unsigned version)
{
    if (version < 9)
        return;
    auto* bytes = static_cast<unsigned char*>(object);
    unsigned count = *reinterpret_cast<unsigned*>(bytes + 0x18);
    WriteImageStream(stream, &count, 4);
    auto* records = *reinterpret_cast<unsigned char**>(bytes + 0x10);
    for (std::size_t i = 0; i < count; ++i) {
        WriteImageStream(stream, records + i * 0x18, 8);
        WriteImageStream(stream, records + i * 0x18 + 8, 4);
        WriteImageStream(stream, records + i * 0x18 + 0x10, 8);
    }
    auto* table = *reinterpret_cast<unsigned char**>(bytes + 0x28);
    unsigned entryCount = table ? *reinterpret_cast<unsigned*>(table) : 0;
    WriteImageStream(stream, &entryCount, 4);
    if (!table)
        return;
    std::uint64_t index = 0;
    const std::uint64_t mask = *reinterpret_cast<std::uint64_t*>(table + 8);
    auto* marker = reinterpret_cast<std::int64_t*>(table + 0x10);
    while (index <= mask) {
        if (*marker != -2) {
            auto* row = table + index * 0x20;
            const std::uint64_t value = *reinterpret_cast<std::uint64_t*>(row + 0x20);
            WriteImageStream(stream, &value, 8);
            auto* text = reinterpret_cast<const String*>(row + 0x28);
            const std::size_t length = text->GetLength();
            const unsigned length32 = static_cast<unsigned>(length);
            WriteImageStream(stream, &length32, 4);
            const auto encoded = *reinterpret_cast<const std::uint64_t*>(text);
            const char* chars = reinterpret_cast<const char*>((encoded & ~std::uint64_t(3)) + 0x0c);
            for (std::size_t j = 0; j < length; ++j)
                WriteImageStream(stream, chars + j, 1);
        }
        ++index;
        marker += 4;
    }
}

// MS2-FUNCTIONAL: serializes the text record group, its recursive tree entries, and occupied string-cache records.
// @0x14268f230
void WriteTextRecordGroup(void* object, void* stream, unsigned version)
{
    auto* bytes = static_cast<unsigned char*>(object);
    Scaleform::WriteNarrowString(stream, reinterpret_cast<const Scaleform::String*>(bytes + 0x10));
    const unsigned count = *reinterpret_cast<unsigned*>(bytes + 0x20);
    auto** nodes = *reinterpret_cast<void***>(bytes + 0x18);
    auto** streamVtable = *reinterpret_cast<void***>(stream);
    reinterpret_cast<void (*)(void*, const void*, std::size_t)>(streamVtable[9])(stream, &count, 4);
    for (unsigned i = 0; i < count; ++i)
        Scaleform::WriteTextTreeNode(nodes[i], stream, version);

    auto* table = *reinterpret_cast<unsigned char**>(bytes + 0x30);
    const unsigned entryCount = table ? *reinterpret_cast<unsigned*>(table) : 0;
    reinterpret_cast<void (*)(void*, const void*, std::size_t)>(streamVtable[9])(stream, &entryCount, 4);
    if (!table)
        return;

    const std::uint64_t mask = *reinterpret_cast<std::uint64_t*>(table + 8);
    for (std::uint64_t index = 0; index <= mask; ++index) {
        auto* row = table + index * 0x20;
        if (*reinterpret_cast<std::int64_t*>(row + 0x10) == -2)
            continue;
        const std::uint64_t key = *reinterpret_cast<std::uint64_t*>(row + 0x20);
        reinterpret_cast<void (*)(void*, const void*, std::size_t)>(streamVtable[9])(stream, &key, 8);
        auto* value = *reinterpret_cast<unsigned char**>(row + 0x28);
        auto* text = reinterpret_cast<const Scaleform::String*>(value + 0x10);
        Scaleform::WriteNarrowString(stream, text);
        reinterpret_cast<void (*)(void*, const void*, std::size_t)>(streamVtable[9])(stream, value + 0x18, 4);
        reinterpret_cast<void (*)(void*, const void*, std::size_t)>(streamVtable[9])(stream, value + 0x20, 8);
        reinterpret_cast<void (*)(void*, const void*, std::size_t)>(streamVtable[9])(stream, value + 0x28, 4);
        reinterpret_cast<void (*)(void*, const void*, std::size_t)>(streamVtable[9])(stream, value + 0x2c, 4);
    }
}

static void WriteAs3RecordBytes(void* stream, const void* data, std::size_t size)
{
    auto** streamVtable = *reinterpret_cast<void***>(stream);
    reinterpret_cast<void (*)(void*, const void*, std::size_t)>(streamVtable[9])(stream, data, size);
}

// MS2-FUNCTIONAL: serializes the image metadata records and cached image names, with later fields gated by format version.
// @0x14268ef30
extern "C" void FUN_14268ef30(void* object, void* stream, unsigned version)
{
    auto* bytes = static_cast<unsigned char*>(object);
    unsigned count = *reinterpret_cast<unsigned*>(bytes + 0x18);
    WriteAs3RecordBytes(stream, &count, 4);
    auto* records = *reinterpret_cast<unsigned char**>(bytes + 0x10);
    for (unsigned i = 0; i < count; ++i) {
        auto* record = records + i * 0x20;
        WriteAs3RecordBytes(stream, record, 8);
        WriteAs3RecordBytes(stream, record + 8, 8);
        WriteAs3RecordBytes(stream, record + 0x10, 4);
        WriteAs3RecordBytes(stream, record + 0x18, 8);
    }

    auto* table = *reinterpret_cast<unsigned char**>(bytes + 0x28);
    const unsigned entryCount = table ? *reinterpret_cast<unsigned*>(table) : 0;
    WriteAs3RecordBytes(stream, &entryCount, 4);
    if (!table)
        return;
    const std::uint64_t mask = *reinterpret_cast<std::uint64_t*>(table + 8);
    for (std::uint64_t i = 0; i <= mask; ++i) {
        auto* row = table + i * 0x20;
        if (*reinterpret_cast<std::int64_t*>(row + 0x10) == -2)
            continue;
        WriteAs3RecordBytes(stream, row + 0x20, 8);
        auto* value = *reinterpret_cast<unsigned char**>(row + 0x28);
        Scaleform::WriteNarrowString(stream, reinterpret_cast<const Scaleform::String*>(value + 0x10));
        WriteAs3RecordBytes(stream, value + 0x18, 4);
        if (version > 8) {
            WriteAs3RecordBytes(stream, value + 0x20, 8);
            WriteAs3RecordBytes(stream, value + 0x28, 4);
            if (version > 12)
                WriteAs3RecordBytes(stream, value + 0x2c, 4);
        }
    }
}

// MS2-FUNCTIONAL: reads a length-prefixed narrow string from the stream, appending each byte to the destination.
// @0x142690630
void ReadNarrowString(void* stream, void* destination)
{
    auto** vtable = *reinterpret_cast<void***>(stream);
    unsigned length = 0;
    reinterpret_cast<void (*)(void*, void*, std::size_t)>(vtable[10])(stream, &length, sizeof(length));
    for (unsigned i = 0; i < length; ++i) {
        unsigned char ch = 0;
        reinterpret_cast<void (*)(void*, void*, std::size_t)>(vtable[10])(stream, &ch, 1);
        FUN_142585f70(destination, static_cast<signed char>(ch));
    }
}

// MS2-FUNCTIONAL: writes a narrow string's 32-bit length followed by its bytes to the stream.
// @0x142690c70
void WriteNarrowString(void* stream, const Scaleform::String* text)
{
    auto** vtable = *reinterpret_cast<void***>(stream);
    const unsigned length = static_cast<unsigned>(text->GetLength());
    reinterpret_cast<void (*)(void*, const void*, std::size_t)>(vtable[9])(stream, &length, sizeof(length));
    const auto encoded = *reinterpret_cast<const std::uintptr_t*>(text);
    auto* raw = reinterpret_cast<const unsigned char*>(encoded & ~std::uintptr_t(3));
    for (unsigned i = 0; i < length; ++i)
        reinterpret_cast<void (*)(void*, const void*, std::size_t)>(vtable[9])(stream, raw + 12 + i, 1);
}

static void WriteStreamBytes(void* stream, const void* data, std::size_t size)
{
    auto** vtable = *reinterpret_cast<void***>(stream);
    reinterpret_cast<void (*)(void*, const void*, std::size_t)>(vtable[9])(stream, data, size);
}

// MS2-FUNCTIONAL: serializes the record's scalar fields followed by each fixed-width value and timestamp pair.
// @0x142690380
void WriteValueRecord(const void* record, void* stream)
{
    auto* src = static_cast<const unsigned char*>(record);
    WriteStreamBytes(stream, src + 0x10, 4);
    WriteStreamBytes(stream, src + 0x14, 4);
    WriteStreamBytes(stream, src + 0x18, 4);
    const unsigned count = *reinterpret_cast<const unsigned*>(src + 0x28);
    WriteStreamBytes(stream, &count, 4);
    auto* entries = static_cast<const unsigned char*>(*reinterpret_cast<void* const*>(src + 0x20));
    for (unsigned i = 0; i < count; ++i) {
        WriteStreamBytes(stream, entries + i * 0x10, 4);
        WriteStreamBytes(stream, entries + i * 0x10 + 8, 8);
    }
}

// MS2-FUNCTIONAL: serializes the complete text record, including version-gated strings and 64-bit timing fields.
// @0x142690480
void WriteTextRecord(const void* record, void* stream, unsigned version)
{
    auto* src = static_cast<const unsigned char*>(record);
    WriteStreamBytes(stream, src + 0x10, 4);
    if (version > 0x13)
        WriteStreamBytes(stream, src + 0x14, 4);
    WriteNarrowString(stream, reinterpret_cast<const Scaleform::String*>(src + 0x18));
    if (version > 4)
        WriteNarrowString(stream, reinterpret_cast<const Scaleform::String*>(src + 0x20));
    for (std::size_t offset : { std::size_t(0x28), std::size_t(0x30), std::size_t(0x38) })
        WriteNarrowString(stream, reinterpret_cast<const Scaleform::String*>(src + offset));
    const unsigned count = *reinterpret_cast<const unsigned*>(src + 0x48);
    WriteStreamBytes(stream, &count, 4);
    auto* strings = static_cast<const Scaleform::String*>(*reinterpret_cast<void* const*>(src + 0x40));
    for (unsigned i = 0; i < count; ++i)
        WriteNarrowString(stream, strings + i);
    for (std::size_t offset : { std::size_t(0x58), std::size_t(0x5c), std::size_t(0x60), std::size_t(0x64) })
        WriteStreamBytes(stream, src + offset, 4);
    if (version > 9) {
        WriteStreamBytes(stream, src + 0x68, 8);
        WriteStreamBytes(stream, src + 0x70, 4);
    }
}

static void ReadStreamBytes(void* stream, void* data, std::size_t size)
{
    auto** vtable = *reinterpret_cast<void***>(stream);
    reinterpret_cast<void (*)(void*, void*, std::size_t)>(vtable[10])(stream, data, size);
}

// MS2-FUNCTIONAL: reads three scalar values and a counted list of 16-byte value/timestamp records.
// @0x14268e010
void ReadValueRecord(void* record, void* stream)
{
    auto* dst = static_cast<unsigned char*>(record);
    ReadStreamBytes(stream, dst + 0x10, 4);
    ReadStreamBytes(stream, dst + 0x14, 4);
    ReadStreamBytes(stream, dst + 0x18, 4);
    unsigned count = 0;
    ReadStreamBytes(stream, &count, 4);
    ResizeRawArray(reinterpret_cast<void**>(dst + 0x20), dst + 0x20, count, 0x10);
    auto* entries = static_cast<unsigned char*>(*reinterpret_cast<void**>(dst + 0x20));
    for (unsigned i = 0; i < count; ++i) {
        ReadStreamBytes(stream, entries + i * 0x10, 4);
        ReadStreamBytes(stream, entries + i * 0x10 + 8, 8);
    }
}

// MS2-FUNCTIONAL: writes node scalars and recursively serializes the complete child list in order.
// @0x14268eca0
void WriteTextTreeNode(const void* node, void* stream, unsigned version)
{
    auto* bytes = static_cast<const unsigned char*>(node);
    WriteStreamBytes(stream, bytes + 0x10, 8);
    WriteStreamBytes(stream, bytes + 0x18, 8);
    WriteStreamBytes(stream, bytes + 0x20, 8);
    WriteStreamBytes(stream, bytes + 0x28, 4);
    const unsigned count = *reinterpret_cast<const unsigned*>(bytes + 0x38);
    WriteStreamBytes(stream, &count, 4);
    auto* children = static_cast<void* const*>(*reinterpret_cast<void* const*>(bytes + 0x30));
    for (unsigned i = 0; i < count; ++i)
        WriteTextTreeNode(children[i], stream, version);
}

static void ReadAs3StreamBytes(void* stream, void* output, std::size_t size)
{
    auto** vtable = *reinterpret_cast<void***>(stream);
    reinterpret_cast<void (*)(void*, void*, std::size_t)>(vtable[10])(stream, output, size);
}

// MS2-FUNCTIONAL: rebuilds the counted text value records, including each record's scalar values and 16-byte samples.
// @0x14268cd80
extern "C" void FUN_14268cd80(void* object, void* stream, unsigned)
{
    auto* bytes = static_cast<unsigned char*>(object);
    unsigned count = 0;
    ReadAs3StreamBytes(stream, &count, 4);
    Scaleform::ResizeStrongPointerArrayB(reinterpret_cast<void**>(bytes + 0x10), count);
    auto** records = *reinterpret_cast<unsigned char***>(bytes + 0x10);
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    std::uint32_t statId = 0x242;
    for (unsigned i = 0; i < count; ++i) {
        auto* record = static_cast<unsigned char*>(reinterpret_cast<void* (*)(void*, void*, std::size_t, const void*)>(heapVtable[14])(
            DAT_143b15f60, object, 0x38, &statId));
        if (!record) {
            if (records[i])
                FUN_14257dcb0(records[i]);
            records[i] = nullptr;
            std::uint32_t discarded = 0;
            ReadAs3StreamBytes(stream, &discarded, 4);
            ReadAs3StreamBytes(stream, &discarded, 4);
            ReadAs3StreamBytes(stream, &discarded, 4);
            unsigned valueCount = 0;
            ReadAs3StreamBytes(stream, &valueCount, 4);
            for (unsigned j = 0; j < valueCount; ++j) {
                std::uint64_t discardedValue = 0;
                ReadAs3StreamBytes(stream, &discarded, 4);
                ReadAs3StreamBytes(stream, &discardedValue, 8);
            }
            continue;
        }
        std::memset(record, 0, 0x38);
        *reinterpret_cast<void**>(record) = AS3TextValueRecordVtable;
        *reinterpret_cast<std::uint32_t*>(record + 8) = 1;
        if (records[i])
            FUN_14257dcb0(records[i]);
        records[i] = record;
        ReadAs3StreamBytes(stream, record + 0x10, 4);
        ReadAs3StreamBytes(stream, record + 0x14, 4);
        ReadAs3StreamBytes(stream, record + 0x18, 4);
        unsigned valueCount = 0;
        ReadAs3StreamBytes(stream, &valueCount, 4);
        Scaleform::ResizeRawArray(reinterpret_cast<void**>(record + 0x20), record + 0x20, valueCount, 0x10);
        auto* values = *reinterpret_cast<unsigned char**>(record + 0x20);
        for (unsigned j = 0; j < valueCount; ++j) {
            ReadAs3StreamBytes(stream, values + j * 0x10, 4);
            ReadAs3StreamBytes(stream, values + j * 0x10 + 8, 8);
        }
    }
}

// MS2-FUNCTIONAL: initializes the movie image data record, its five strings, and the four owned collection records.
// @0x142686ae0
extern "C" void* FUN_142686ae0(void* object)
{
    auto* bytes = static_cast<unsigned char*>(object);
    std::memset(bytes + 0x10, 0, 0x68);
    *reinterpret_cast<void**>(bytes) = AS3MovieImageDataVtable;
    *reinterpret_cast<std::uint32_t*>(bytes + 8) = 1;
    new (bytes + 0x20) Scaleform::StringLH();
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    const std::size_t sizes[4] = { 0x28, 0x30, 0x30, 0x38 };
    void* vtables[4] = { AS3MovieImageStringSetVtable, AS3MovieImageValueSetVtable,
                         AS3MovieImageNameSetVtable, AS3MovieImageTreeVtable };
    const std::size_t offsets[4] = { 0x58, 0x60, 0x68, 0x70 };
    std::uint32_t stat = 0x242;
    for (unsigned i = 0; i < 4; ++i) {
        auto* child = static_cast<unsigned char*>(reinterpret_cast<void* (*)(void*, void*, std::size_t, const void*)>(heapVtable[14])(
            DAT_143b15f60, object, sizes[i], &stat));
        if (!child) {
            *reinterpret_cast<void**>(bytes + offsets[i]) = nullptr;
            continue;
        }
        std::memset(child, 0, sizes[i]);
        *reinterpret_cast<void**>(child) = vtables[i];
        *reinterpret_cast<std::uint32_t*>(child + 8) = 1;
        if (i == 3)
            new (child + 0x10) Scaleform::StringLH();
        *reinterpret_cast<void**>(bytes + offsets[i]) = child;
    }
    return object;
}

static void* CreateAs3ReportBlock(void* owner, std::size_t size, std::uint32_t statId, void* vtable, bool hasString)
{
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    auto* block = static_cast<unsigned char*>(reinterpret_cast<void* (*)(void*, void*, std::size_t, const void*)>(heapVtable[14])(
        DAT_143b15f60, owner, size, &statId));
    if (!block)
        return nullptr;
    std::memset(block, 0, size);
    *reinterpret_cast<void**>(block) = vtable;
    *reinterpret_cast<std::uint32_t*>(block + 8) = 1;
    if (hasString)
        new (block + 0x10) Scaleform::StringLH();
    return block;
}

// MS2-FUNCTIONAL: initializes the movie resource data record, its three memory items, lookup set, and named tree list.
// @0x142686d30
extern "C" void* FUN_142686d30(void* object)
{
    auto* bytes = static_cast<unsigned char*>(object);
    std::memset(bytes + 0x10, 0, 0x148);
    *reinterpret_cast<void**>(bytes) = AS3MovieResourceDataVtable;
    *reinterpret_cast<std::uint32_t*>(bytes + 8) = 1;
    void* itemA = CreateAs3ReportBlock(object, 0x48, 2, AS3MovieMemoryItemVtable, true);
    void* itemB = CreateAs3ReportBlock(object, 0x48, 2, AS3MovieMemoryItemVtable, true);
    void* itemC = CreateAs3ReportBlock(object, 0x48, 2, AS3MovieMemoryItemVtable, true);
    void* values = CreateAs3ReportBlock(object, 0x30, 0x242, AS3MovieImageValueSetVtable, false);
    void* tree = CreateAs3ReportBlock(object, 0x38, 2, AS3MovieImageTreeVtable, true);
    *reinterpret_cast<void**>(bytes + 0x128) = itemA;
    *reinterpret_cast<void**>(bytes + 0x130) = itemB;
    *reinterpret_cast<void**>(bytes + 0x138) = itemC;
    *reinterpret_cast<void**>(bytes + 0xe8) = values;
    *reinterpret_cast<void**>(bytes + 0xf0) = tree;
    return object;
}

// MS2-FUNCTIONAL: reads the image info string, counted movie-image records, and versioned movie-to-manager lookup entries.
// @0x14268c930
extern "C" void FUN_14268c930(void* object, void* stream, unsigned version)
{
    auto* bytes = static_cast<unsigned char*>(object);
    Scaleform::ReadNarrowString(stream, bytes + 0x10);
    unsigned count = 0;
    ReadAs3StreamBytes(stream, &count, 4);
    Scaleform::ResizeStrongPointerArrayB(reinterpret_cast<void**>(bytes + 0x18), count);
    auto** images = *reinterpret_cast<unsigned char***>(bytes + 0x18);
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    std::uint32_t localStat = 2;
    for (unsigned i = 0; i < count; ++i) {
        auto* image = static_cast<unsigned char*>(reinterpret_cast<void* (*)(void*, void*, std::size_t, const void*)>(heapVtable[14])(
            DAT_143b15f60, object, 0x48, &localStat));
        if (!image)
            return;
        std::memset(image, 0, 0x48);
        *reinterpret_cast<void**>(image) = MovieImageInfoVtable;
        *reinterpret_cast<std::uint32_t*>(image + 8) = 1;
        if (images[i]) FUN_14257dcb0(images[i]);
        images[i] = image;
        Scaleform::ReadMovieImageRecord(image, stream, version);
    }

    unsigned cachedCount = 0;
    ReadAs3StreamBytes(stream, &cachedCount, 4);
    std::uint32_t cachedStat = 0x242;
    for (unsigned i = 0; i < cachedCount; ++i) {
        std::uint64_t key = 0;
        ReadAs3StreamBytes(stream, &key, 8);
        auto* value = static_cast<unsigned char*>(reinterpret_cast<void* (*)(void*, void*, std::size_t, const void*)>(heapVtable[14])(
            DAT_143b15f60, object, 0x30, &cachedStat));
        if (!value) {
            Scaleform::String discardedName;
            Scaleform::ReadNarrowString(stream, &discardedName);
            std::uint32_t discarded = 0;
            std::uint64_t discardedWide = 0;
            ReadAs3StreamBytes(stream, &discarded, 4);
            ReadAs3StreamBytes(stream, &discardedWide, 8);
            ReadAs3StreamBytes(stream, &discarded, 4);
            ReadAs3StreamBytes(stream, &discarded, 4);
            continue;
        }
        std::memset(value, 0, 0x30);
        *reinterpret_cast<void**>(value) = AS3MovieViewValueVtable;
        *reinterpret_cast<std::uint32_t*>(value + 8) = 1;
        new (value + 0x10) Scaleform::StringLH();
        Scaleform::ReadNarrowString(stream, value + 0x10);
        ReadAs3StreamBytes(stream, value + 0x18, 4);
        ReadAs3StreamBytes(stream, value + 0x20, 8);
        ReadAs3StreamBytes(stream, value + 0x28, 4);
        ReadAs3StreamBytes(stream, value + 0x2c, 4);
        Scaleform::AddMovieViewHashEntry(reinterpret_cast<void**>(bytes + 0x30), bytes + 0x30, key, value);
        FUN_14257dcb0(value);
    }
}

// MS2-FUNCTIONAL: reads the versioned movie-to-manager records and interns each keyed ASIMEManager value.
// @0x14268c510
extern "C" void FUN_14268c510(void* object, void* stream, unsigned version)
{
    auto* bytes = static_cast<unsigned char*>(object);
    unsigned recordCount = 0;
    ReadAs3StreamBytes(stream, &recordCount, 4);
    Scaleform::ResizeRawArray(reinterpret_cast<void**>(bytes + 0x10), bytes + 0x10, recordCount, 0x20);
    auto* records = *reinterpret_cast<unsigned char**>(bytes + 0x10);
    for (unsigned i = 0; i < recordCount; ++i) {
        auto* record = records + i * 0x20;
        ReadAs3StreamBytes(stream, record, 8);
        ReadAs3StreamBytes(stream, record + 8, 8);
        ReadAs3StreamBytes(stream, record + 0x10, 4);
        ReadAs3StreamBytes(stream, record + 0x18, 8);
    }

    unsigned entryCount = 0;
    ReadAs3StreamBytes(stream, &entryCount, 4);
    std::uint32_t statId = 0x242;
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    for (unsigned i = 0; i < entryCount; ++i) {
        std::uint64_t key = 0;
        ReadAs3StreamBytes(stream, &key, 8);
        auto* value = static_cast<unsigned char*>(reinterpret_cast<void* (*)(void*, void*, std::size_t, const void*)>(heapVtable[14])(
            DAT_143b15f60, object, 0x30, &statId));
        if (!value) {
            Scaleform::String discardedName;
            Scaleform::ReadNarrowString(stream, &discardedName);
            std::uint32_t discarded = 0;
            std::uint64_t discardedWide = 0;
            ReadAs3StreamBytes(stream, &discarded, 4);
            if (version > 8) {
                ReadAs3StreamBytes(stream, &discardedWide, 8);
                ReadAs3StreamBytes(stream, &discarded, 4);
                if (version > 12)
                    ReadAs3StreamBytes(stream, &discarded, 4);
            }
            continue;
        }
        std::memset(value, 0, 0x30);
        *reinterpret_cast<void**>(value) = AS3MovieViewValueVtable;
        *reinterpret_cast<std::uint32_t*>(value + 8) = 1;
        new (value + 0x10) Scaleform::StringLH();
        Scaleform::ReadNarrowString(stream, value + 0x10);
        ReadAs3StreamBytes(stream, value + 0x18, 4);
        if (version > 8) {
            ReadAs3StreamBytes(stream, value + 0x20, 8);
            ReadAs3StreamBytes(stream, value + 0x28, 4);
            if (version > 12)
                ReadAs3StreamBytes(stream, value + 0x2c, 4);
        }
        Scaleform::AddMovieViewHashEntry(reinterpret_cast<void**>(bytes + 0x28), bytes + 0x28, key, value);
        FUN_14257dcb0(value);
    }
}

// MS2-FUNCTIONAL: reads version-nine keyed image resource ids and interns each associated string into the cached hash table.
// @0x14268d2b0
extern "C" void FUN_14268d2b0(void* object, void* stream, unsigned version)
{
    if (version <= 8)
        return;
    auto* bytes = static_cast<unsigned char*>(object);
    unsigned count = 0;
    ReadAs3StreamBytes(stream, &count, 4);
    Scaleform::ResizeRawArray(reinterpret_cast<void**>(bytes + 0x10), bytes + 0x10, count, 0x18);
    auto* records = *reinterpret_cast<unsigned char**>(bytes + 0x10);
    for (unsigned i = 0; i < count; ++i) {
        auto* record = records + i * 0x18;
        ReadAs3StreamBytes(stream, record, 8);
        ReadAs3StreamBytes(stream, record + 8, 4);
        ReadAs3StreamBytes(stream, record + 0x10, 8);
    }
    unsigned stringCount = 0;
    ReadAs3StreamBytes(stream, &stringCount, 4);
    for (unsigned i = 0; i < stringCount; ++i) {
        std::uint64_t key = 0;
        ReadAs3StreamBytes(stream, &key, 8);
        Scaleform::String value;
        Scaleform::ReadNarrowString(stream, &value);
        struct StringPair { const void* key; const Scaleform::String* value; } pair{ &key, &value };
        Scaleform::AddStringHashEntry(bytes + 0x28, bytes + 0x28,
            reinterpret_cast<const std::uint64_t*>(&pair),
            Scaleform::HashImageKey(reinterpret_cast<const unsigned char*>(&key)));
    }
}

// MS2-FUNCTIONAL: reads the aggregate movie image header, nested movies, timing arrays, and versioned memory report trees.
// @0x14268d5c0
extern "C" void FUN_14268d5c0(void* object, void* stream, unsigned version)
{
    auto* bytes = static_cast<unsigned char*>(object);
    ReadAs3StreamBytes(stream, bytes + 0x10, 8);
    for (std::size_t offset : { std::size_t(0x18), std::size_t(0x1c), std::size_t(0x24), std::size_t(0x20) })
        ReadAs3StreamBytes(stream, bytes + offset, 4);
    if (version < 0x15) {
        std::uint32_t legacy = 0;
        ReadAs3StreamBytes(stream, &legacy, 4);
    }
    for (std::size_t offset : { std::size_t(0x28), std::size_t(0x2c), std::size_t(0x30), std::size_t(0x34),
                                std::size_t(0x38), std::size_t(0x3c) })
        ReadAs3StreamBytes(stream, bytes + offset, 4);
    if (version > 0x1d) ReadAs3StreamBytes(stream, bytes + 0x40, 4);
    for (std::size_t offset : { std::size_t(0x44), std::size_t(0x48), std::size_t(0x4c), std::size_t(0x50),
                                std::size_t(0x54), std::size_t(0x58) })
        ReadAs3StreamBytes(stream, bytes + offset, 4);
    if (version > 0x0f) ReadAs3StreamBytes(stream, bytes + 0x5c, 4);
    for (std::size_t offset : { std::size_t(0x60), std::size_t(0x64), std::size_t(0x68), std::size_t(0x6c),
                                std::size_t(0x70), std::size_t(0x74), std::size_t(0x78), std::size_t(0x7c) })
        ReadAs3StreamBytes(stream, bytes + offset, 4);
    if (version > 0x0d) {
        for (std::size_t offset : { std::size_t(0x80), std::size_t(0x84), std::size_t(0x88) })
            ReadAs3StreamBytes(stream, bytes + offset, 4);
        if (version > 0x17) ReadAs3StreamBytes(stream, bytes + 0x8c, 4);
        if (version > 0x1a) {
            ReadAs3StreamBytes(stream, bytes + 0x90, 4);
            ReadAs3StreamBytes(stream, bytes + 0x94, 4);
        }
    }
    for (std::size_t offset : { std::size_t(0x98), std::size_t(0x9c) })
        ReadAs3StreamBytes(stream, bytes + offset, 4);
    if (version > 0x1c) ReadAs3StreamBytes(stream, bytes + 0xa0, 4);
    for (std::size_t offset : { std::size_t(0xa4), std::size_t(0xa8), std::size_t(0xac) })
        ReadAs3StreamBytes(stream, bytes + offset, 4);
    if (version > 0x1b) {
        for (std::size_t offset : { std::size_t(0xb0), std::size_t(0xb4), std::size_t(0xb8) })
            ReadAs3StreamBytes(stream, bytes + offset, 4);
    }
    for (std::size_t offset : { std::size_t(0xbc), std::size_t(0xc0), std::size_t(0xc4), std::size_t(0xc8) })
        ReadAs3StreamBytes(stream, bytes + offset, 4);

    unsigned imageCount = 0;
    ReadAs3StreamBytes(stream, &imageCount, 4);
    Scaleform::ResizeStrongPointerArrayB(reinterpret_cast<void**>(bytes + 0xd0), imageCount);
    auto** images = *reinterpret_cast<unsigned char***>(bytes + 0xd0);
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    std::uint32_t imageStat = 0x242;
    for (unsigned i = 0; i < imageCount; ++i) {
        auto* image = static_cast<unsigned char*>(reinterpret_cast<void* (*)(void*, void*, std::size_t, const void*)>(heapVtable[14])(
            DAT_143b15f60, object, 0x78, &imageStat));
        if (!image)
            return;
        image = static_cast<unsigned char*>(FUN_142686ae0(image));
        if (images[i]) FUN_14257dcb0(images[i]);
        images[i] = image;
        FUN_14268cfe0(image, stream, version);
    }
    if (version > 0x0e) FUN_14268c510(*reinterpret_cast<void**>(bytes + 0xe8), stream, version);
    if (version > 0x18) FUN_14268c930(*reinterpret_cast<void**>(bytes + 0xf0), stream, version);

    unsigned idCount = 0;
    ReadAs3StreamBytes(stream, &idCount, 4);
    Scaleform::ResizeRawArray(reinterpret_cast<void**>(bytes + 0xf8), bytes + 0xf8, idCount, 4);
    auto* ids = *reinterpret_cast<std::uint32_t**>(bytes + 0xf8);
    for (unsigned i = 0; i < idCount; ++i)
        ReadAs3StreamBytes(stream, ids + i, 4);
    if (version > 8) {
        unsigned count = 0;
        ReadAs3StreamBytes(stream, &count, 4);
        Scaleform::ResizeRawArray(reinterpret_cast<void**>(bytes + 0x110), bytes + 0x110, count, 8);
        auto* values = *reinterpret_cast<std::uint64_t**>(bytes + 0x110);
        for (unsigned i = 0; i < count; ++i)
            ReadAs3StreamBytes(stream, values + i, 8);
    }
    for (std::size_t offset : { std::size_t(0x128), std::size_t(0x130), std::size_t(0x138) }) {
        auto* item = *reinterpret_cast<Scaleform::MemItem**>(bytes + offset);
        if (item) item->Read(*reinterpret_cast<Scaleform::File*>(stream), version);
    }
    if (version < 0x13) {
        std::uint32_t itemStat = 2;
        void* legacy = reinterpret_cast<void* (*)(void*, void*, std::size_t, const void*)>(heapVtable[14])(
            DAT_143b15f60, object, sizeof(Scaleform::MemItem), &itemStat);
        if (legacy) {
            ::new (legacy) Scaleform::MemItem(2);
            static_cast<Scaleform::MemItem*>(legacy)->Read(*reinterpret_cast<Scaleform::File*>(stream), version);
            FUN_14257dcb0(legacy);
        }
    }
    if (version > 0x10) {
        unsigned extraCount = 0;
        ReadAs3StreamBytes(stream, &extraCount, 4);
        Scaleform::ResizeStrongPointerArrayB(reinterpret_cast<void**>(bytes + 0x140), extraCount);
        auto** extras = *reinterpret_cast<unsigned char***>(bytes + 0x140);
        std::uint32_t extraStat = 0x242;
        for (unsigned i = 0; i < extraCount; ++i) {
            auto* extra = static_cast<unsigned char*>(reinterpret_cast<void* (*)(void*, void*, std::size_t, const void*)>(heapVtable[14])(
                DAT_143b15f60, object, 0x40, &extraStat));
            if (!extra)
                return;
            std::memset(extra, 0, 0x40);
            *reinterpret_cast<void**>(extra) = AS3MovieImageExtraVtable;
            *reinterpret_cast<std::uint32_t*>(extra + 8) = 1;
            new (extra + 0x18) Scaleform::StringLH();
            if (extras[i]) FUN_14257dcb0(extras[i]);
            extras[i] = extra;
            Scaleform::ReadMovieImageFields(extra, stream, version);
        }
    }
    if (version < 8) {
        std::uint32_t legacy = 0;
        ReadAs3StreamBytes(stream, &legacy, 4);
        ReadAs3StreamBytes(stream, &legacy, 4);
    }
}

// MS2-FUNCTIONAL: reads the versioned movie image header and marker records, then delegates the nested resource tables.
// @0x14268cfe0
extern "C" void FUN_14268cfe0(void* object, void* stream, unsigned version)
{
    auto* bytes = static_cast<unsigned char*>(object);
    ReadAs3StreamBytes(stream, bytes + 0x10, 4);
    ReadAs3StreamBytes(stream, bytes + 0x14, 4);
    ReadAs3StreamBytes(stream, bytes + 0x18, 4);
    if (version > 3) {
        Scaleform::ReadNarrowString(stream, bytes + 0x20);
        ReadAs3StreamBytes(stream, bytes + 0x28, 4);
        ReadAs3StreamBytes(stream, bytes + 0x2c, 4);
        ReadAs3StreamBytes(stream, bytes + 0x30, 4);
        ReadAs3StreamBytes(stream, bytes + 0x34, 4);
        ReadAs3StreamBytes(stream, bytes + 0x38, 4);
    }
    if (version > 5) {
        unsigned markerCount = 0;
        ReadAs3StreamBytes(stream, &markerCount, 4);
        Scaleform::ResizeStrongPointerArrayB(reinterpret_cast<void**>(bytes + 0x40), markerCount);
        auto** markers = *reinterpret_cast<unsigned char***>(bytes + 0x40);
        for (unsigned i = 0; i < markerCount; ++i) {
            std::uint32_t statId = 0x242;
            auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
            auto* marker = static_cast<unsigned char*>(reinterpret_cast<void* (*)(void*, void*, std::size_t, const void*)>(heapVtable[14])(
                DAT_143b15f60, object, 0x20, &statId));
            if (!marker) {
                if (markers[i])
                    FUN_14257dcb0(markers[i]);
                markers[i] = nullptr;
                Scaleform::String discardedName;
                Scaleform::ReadNarrowString(stream, &discardedName);
                std::uint32_t discardedTime = 0;
                ReadAs3StreamBytes(stream, &discardedTime, 4);
                continue;
            }
            std::memset(marker, 0, 0x20);
            *reinterpret_cast<void**>(marker) = AS3MovieMarkerVtable;
            *reinterpret_cast<std::uint32_t*>(marker + 8) = 1;
            new (marker + 0x10) Scaleform::StringLH();
            auto* prior = markers[i];
            if (prior)
                FUN_14257dcb0(prior);
            markers[i] = marker;
            if (version < 11)
                reinterpret_cast<Scaleform::StringLH*>(marker + 0x10)->operator=("Marker");
            else
                Scaleform::ReadNarrowString(stream, marker + 0x10);
            ReadAs3StreamBytes(stream, marker + 0x18, 4);
        }
    }
    FUN_14268cd80(*reinterpret_cast<void**>(bytes + 0x58), stream, version);
    FUN_14268c510(*reinterpret_cast<void**>(bytes + 0x60), stream, version);
    FUN_14268d2b0(*reinterpret_cast<void**>(bytes + 0x68), stream, version);
    if (version > 0x18)
        FUN_14268c930(*reinterpret_cast<void**>(bytes + 0x70), stream, version);
}

// MS2-FUNCTIONAL: writes text metadata and a version-gated empty compatibility string, normalizing the boolean byte.
// @0x14268ed90
void WriteTextMetadata(const void* record, void* stream, unsigned version)
{
    auto* src = static_cast<const unsigned char*>(record);
    WriteStreamBytes(stream, src + 0x10, 4);
    WriteNarrowString(stream, reinterpret_cast<const Scaleform::String*>(src + 0x18));
    if (version < 0x1d) {
        const unsigned zeroLength = 0;
        WriteStreamBytes(stream, &zeroLength, 4);
    }
    WriteStreamBytes(stream, src + 0x20, 4);
    const unsigned char enabled = *reinterpret_cast<const unsigned char*>(src + 0x24) != 0;
    WriteStreamBytes(stream, &enabled, 1);
    for (std::size_t offset : { std::size_t(0x28), std::size_t(0x2c), std::size_t(0x30), std::size_t(0x34), std::size_t(0x38) })
        WriteStreamBytes(stream, src + offset, 4);
}

// MS2-FUNCTIONAL: hashes the eight byte key, follows the selected bucket's collision chain, and returns the matching value slot.
// @0x142745630
void* FindAudioRequestEntry(void** set, const unsigned char* key)
{
    auto* table = static_cast<std::uint64_t*>(*set);
    if (!table)
        return nullptr;
    const std::uint64_t hash =
        (((((std::uint64_t(key[3]) * 0x1003f + key[2]) * 0x1003f + key[1]) * 0x1003f + key[4] * 0xfc5d1543ec5f01ull) +
           key[5] * 0x9b302c28162c612full + key[7] * 0xd7c3e496a311b1bfull +
           key[6] * 0x5d02f409d62aee81ull - 0x514d9afbc3e934fbull + key[0])) & table[1];
    auto* node = table + 2 + hash * 6;
    if (static_cast<std::int64_t>(*node) != -2 && node[1] == hash) {
        std::uint64_t index = hash;
        while (node[1] != hash || node[2] != *reinterpret_cast<const std::uint64_t*>(key)) {
            index = node[0];
            if (index == ~std::uint64_t(0))
                return nullptr;
            node = table + 2 + index * 6;
        }
        return table + 4 + index * 6;
    }
    return nullptr;
}

// MS2-FUNCTIONAL: removes a finished request from its keyed channel list, pulses completion when the table empties, and stops/releases the channel.
// @0x1427454b0
void RemoveAudioRequest(void* manager, void* request)
{
    if (!request)
        return;
    auto* requestBytes = static_cast<unsigned char*>(request);
    auto* sound = *reinterpret_cast<unsigned char**>(requestBytes + 0x30);
    if (!sound)
        return;
    unsigned long long key = *reinterpret_cast<unsigned long long*>(sound + 0x40);
    if (!key)
        return;

    auto* managerBytes = static_cast<unsigned char*>(manager);
    EnterCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(managerBytes + 0x80));
    auto** set = reinterpret_cast<void**>(managerBytes + 0xa8);
    auto* entry = static_cast<unsigned long long*>(FindAudioRequestEntry(set,
        reinterpret_cast<const unsigned char*>(&key)));
    bool removed = false;
    if (entry) {
        auto** channels = reinterpret_cast<void**>(entry[0]);
        const std::size_t count = entry[1];
        std::size_t emptyCount = 0;
        for (std::size_t i = 0; i < count; ++i) {
            if (channels[i] == request) {
                channels[i] = nullptr;
                removed = true;
            }
            if (!channels[i])
                ++emptyCount;
        }
        if (emptyCount == count)
            FUN_142742830(reinterpret_cast<long long*>(set), &key);
    }

    auto* table = *reinterpret_cast<void**>(managerBytes + 0xa8);
    if ((!table || *reinterpret_cast<unsigned long long*>(table) == 0) && managerBytes[0xf1] &&
        *reinterpret_cast<void**>(managerBytes + 0x18)) {
        managerBytes[0x78] = 1;
        FUN_14257dcb0(*reinterpret_cast<void**>(managerBytes + 0x18));
        *reinterpret_cast<void**>(managerBytes + 0x18) = nullptr;
        reinterpret_cast<Scaleform::Event*>(managerBytes + 0x20)->PulseEvent();
    }
    LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(managerBytes + 0x80));

    if (removed) {
        auto* channel = *reinterpret_cast<FMOD::Channel**>(requestBytes + 0x38);
        if (channel)
            channel->stop();
        FUN_14257dcb0(request);
    }
}

// MS2-FUNCTIONAL: merges 32-byte image metric records by their two-word key, accumulating the count and total fields.
// @0x14268a8e0
extern "C" void FUN_14268a8e0(void* destination, void* source)
{
    auto* dst = static_cast<unsigned char*>(destination);
    auto* src = static_cast<const unsigned char*>(source);
    const std::size_t sourceCount = *reinterpret_cast<const std::size_t*>(src + 0x18);
    auto* sourceRows = *reinterpret_cast<const unsigned char* const*>(src + 0x10);
    for (std::size_t i = 0; i < sourceCount; ++i) {
        const auto* incoming = sourceRows + i * 0x20;
        const std::size_t destinationCount = *reinterpret_cast<const std::size_t*>(dst + 0x18);
        auto* destinationRows = *reinterpret_cast<unsigned char**>(dst + 0x10);
        std::size_t match = 0;
        while (match < destinationCount && std::memcmp(destinationRows + match * 0x20, incoming, 16) != 0)
            ++match;
        if (match < destinationCount) {
            auto* row = destinationRows + match * 0x20;
            *reinterpret_cast<std::uint32_t*>(row + 0x10) += *reinterpret_cast<const std::uint32_t*>(incoming + 0x10);
            *reinterpret_cast<std::uint64_t*>(row + 0x18) += *reinterpret_cast<const std::uint64_t*>(incoming + 0x18);
        } else {
            Scaleform::ResizeRawArray(reinterpret_cast<void**>(dst + 0x10), dst + 0x10, destinationCount + 1, 0x20);
            destinationRows = *reinterpret_cast<unsigned char**>(dst + 0x10);
            std::memcpy(destinationRows + destinationCount * 0x20, incoming, 0x20);
        }
    }
}

static bool SameAs3String(const Scaleform::String* left, const Scaleform::String* right)
{
    const std::size_t length = left->GetLength();
    if (length != right->GetLength())
        return false;
    const auto leftBits = *reinterpret_cast<const std::uintptr_t*>(left);
    const auto rightBits = *reinterpret_cast<const std::uintptr_t*>(right);
    const auto* leftChars = reinterpret_cast<const unsigned char*>((leftBits & ~std::uintptr_t(3)) + 12);
    const auto* rightChars = reinterpret_cast<const unsigned char*>((rightBits & ~std::uintptr_t(3)) + 12);
    return std::memcmp(leftChars, rightChars, length) == 0;
}

static void CopyAs3StrongArray(void** destinationArray, void* const* sourceArray)
{
    const std::size_t count = reinterpret_cast<const std::size_t*>(sourceArray)[1];
    Scaleform::ResizeStrongPointerArrayB(destinationArray, count);
    auto** dstItems = static_cast<void**>(destinationArray[0]);
    auto* srcItems = static_cast<void* const*>(sourceArray[0]);
    for (std::size_t i = 0; i < count; ++i) {
        if (srcItems[i]) FUN_14257dc30(srcItems[i]);
        if (dstItems[i]) FUN_14257dcb0(dstItems[i]);
        dstItems[i] = srcItems[i];
    }
}

static void CopyAs3RawRecords(unsigned char* destinationList, const unsigned char* sourceList, std::size_t stride)
{
    const std::size_t count = *reinterpret_cast<const std::size_t*>(sourceList + 0x18);
    Scaleform::ResizeRawArray(reinterpret_cast<void**>(destinationList + 0x10), destinationList + 0x10, count, stride);
    if (count)
        std::memcpy(*reinterpret_cast<void**>(destinationList + 0x10),
                    *reinterpret_cast<void* const*>(sourceList + 0x10), count * stride);
}

// MS2-FUNCTIONAL: orders a half-open range of 32-byte records using the supplied comparison callback.
// @0x1426860f0
extern "C" void FUN_1426860f0(void** array, std::size_t first, std::size_t last,
                              unsigned char (*less)(const void*, const void*))
{
    auto* data = static_cast<unsigned char*>(*array);
    if (!data || last <= first)
        return;
    unsigned char saved[0x20];
    for (std::size_t i = first + 1; i < last; ++i) {
        std::memcpy(saved, data + i * 0x20, sizeof(saved));
        std::size_t position = i;
        while (position > first && less(saved, data + (position - 1) * 0x20)) {
            std::memcpy(data + position * 0x20, data + (position - 1) * 0x20, 0x20);
            --position;
        }
        std::memcpy(data + position * 0x20, saved, sizeof(saved));
    }
}

// MS2-FUNCTIONAL: divides movie timing counters, nested text and metric timestamps, renderer records, and MemItem totals.
// @0x142688760
extern "C" long long FUN_142688760(void* object, std::uint32_t divisor)
{
    auto* bytes = static_cast<unsigned char*>(object);
    *reinterpret_cast<std::uint64_t*>(bytes + 0x10) /= divisor;
    for (std::size_t offset = 0x18; offset <= 0xc8; offset += 4)
        *reinterpret_cast<std::uint32_t*>(bytes + offset) /= divisor;

    const std::size_t movieCount = *reinterpret_cast<std::size_t*>(bytes + 0xd8);
    auto** movies = *reinterpret_cast<unsigned char***>(bytes + 0xd0);
    for (std::size_t movieIndex = 0; movieIndex < movieCount; ++movieIndex) {
        auto* movie = movies[movieIndex];
        auto* textGroup = *reinterpret_cast<unsigned char**>(movie + 0x58);
        const std::size_t textCount = *reinterpret_cast<std::size_t*>(textGroup + 0x18);
        auto** texts = *reinterpret_cast<unsigned char***>(textGroup + 0x10);
        for (std::size_t i = 0; i < textCount; ++i) {
            auto* text = texts[i];
            const std::size_t valueCount = *reinterpret_cast<std::size_t*>(text + 0x28);
            auto* values = *reinterpret_cast<unsigned char**>(text + 0x20);
            for (std::size_t j = 0; j < valueCount; ++j)
                *reinterpret_cast<std::uint64_t*>(values + j * 0x10 + 8) /= divisor;
        }

        auto* metrics = *reinterpret_cast<unsigned char**>(movie + 0x60);
        const std::size_t metricCount = *reinterpret_cast<std::size_t*>(metrics + 0x18);
        auto* metricRows = *reinterpret_cast<unsigned char**>(metrics + 0x10);
        for (std::size_t i = 0; i < metricCount; ++i) {
            auto* row = metricRows + i * 0x20;
            *reinterpret_cast<std::uint32_t*>(row + 0x10) /= divisor;
            *reinterpret_cast<std::uint64_t*>(row + 0x18) /= divisor;
        }

        auto* names = *reinterpret_cast<unsigned char**>(movie + 0x68);
        const std::size_t nameCount = *reinterpret_cast<std::size_t*>(names + 0x18);
        auto* nameRows = *reinterpret_cast<unsigned char**>(names + 0x10);
        for (std::size_t i = 0; i < nameCount; ++i)
            *reinterpret_cast<std::uint64_t*>(nameRows + i * 0x18 + 0x10) /= divisor;
    }

    auto* renderer = *reinterpret_cast<unsigned char**>(bytes + 0xe8);
    const std::size_t rendererCount = *reinterpret_cast<std::size_t*>(renderer + 0x18);
    auto* rendererRows = *reinterpret_cast<unsigned char**>(renderer + 0x10);
    for (std::size_t i = 0; i < rendererCount; ++i) {
        auto* row = rendererRows + i * 0x20;
        *reinterpret_cast<std::uint32_t*>(row + 0x10) /= divisor;
        *reinterpret_cast<std::uint64_t*>(row + 0x18) /= divisor;
    }
    for (std::size_t offset : { std::size_t(0x128), std::size_t(0x130), std::size_t(0x138) })
        reinterpret_cast<Scaleform::MemItem*>(*reinterpret_cast<void**>(bytes + offset))->operator/=(divisor);
    return static_cast<long long>(reinterpret_cast<std::uintptr_t>(object));
}

// MS2-FUNCTIONAL: copies the image resource record and its nested strong-reference arrays, metric lists, and lookup sets.
// @0x142687250
extern "C" long long FUN_142687250(void* destination, const void* source)
{
    auto* dst = static_cast<unsigned char*>(destination);
    auto* src = static_cast<const unsigned char*>(source);
    std::memcpy(dst + 0x10, src + 0x10, 12);
    *reinterpret_cast<Scaleform::String*>(dst + 0x20) = *reinterpret_cast<const Scaleform::String*>(src + 0x20);
    std::memcpy(dst + 0x28, src + 0x28, 20);

    CopyAs3StrongArray(reinterpret_cast<void**>(dst + 0x40), reinterpret_cast<void* const*>(src + 0x40));

    auto* dstPtrRecords = *reinterpret_cast<unsigned char**>(dst + 0x58);
    auto* srcPtrRecords = *reinterpret_cast<const unsigned char* const*>(src + 0x58);
    CopyAs3StrongArray(reinterpret_cast<void**>(dstPtrRecords + 0x10), reinterpret_cast<void* const*>(srcPtrRecords + 0x10));
    auto* dstMetrics = *reinterpret_cast<unsigned char**>(dst + 0x60);
    auto* srcMetrics = *reinterpret_cast<const unsigned char* const*>(src + 0x60);
    CopyAs3RawRecords(dstMetrics, srcMetrics, 0x20);
    FUN_142689aa0(dstMetrics + 0x28, dstMetrics + 0x28, const_cast<unsigned char*>(srcMetrics + 0x28));
    auto* dstNames = *reinterpret_cast<unsigned char**>(dst + 0x68);
    auto* srcNames = *reinterpret_cast<const unsigned char* const*>(src + 0x68);
    CopyAs3RawRecords(dstNames, srcNames, 0x18);
    FUN_142689cb0(dstNames + 0x28, dstNames + 0x28, const_cast<unsigned char*>(srcNames + 0x28));

    auto* dstTree = *reinterpret_cast<unsigned char**>(dst + 0x70);
    auto* srcTree = *reinterpret_cast<const unsigned char* const*>(src + 0x70);
    *reinterpret_cast<Scaleform::String*>(dstTree + 0x10) = *reinterpret_cast<const Scaleform::String*>(srcTree + 0x10);
    CopyAs3StrongArray(reinterpret_cast<void**>(dstTree + 0x18), reinterpret_cast<void* const*>(srcTree + 0x18));
    FUN_142689aa0(dstTree + 0x30, dstTree + 0x30, const_cast<unsigned char*>(srcTree + 0x30));
    return static_cast<long long>(reinterpret_cast<std::uintptr_t>(destination));
}

// MS2-FUNCTIONAL: compares a text record's strings, string array, scalar identity, and near-equal geometry values.
// @0x142687620
long long TextRecordEquivalent(const void* leftRecord, const void* rightRecord)
{
    auto* left = static_cast<const unsigned char*>(leftRecord);
    auto* right = static_cast<const unsigned char*>(rightRecord);
    if (*reinterpret_cast<const std::uint32_t*>(left + 0x10) != *reinterpret_cast<const std::uint32_t*>(right + 0x10) ||
        *reinterpret_cast<const std::uint32_t*>(left + 0x14) != *reinterpret_cast<const std::uint32_t*>(right + 0x14))
        return 1;
    for (std::size_t offset : { std::size_t(0x18), std::size_t(0x20), std::size_t(0x28), std::size_t(0x30), std::size_t(0x38) })
        if (!SameAs3String(reinterpret_cast<const Scaleform::String*>(left + offset),
                           reinterpret_cast<const Scaleform::String*>(right + offset)))
            return 1;
    const std::size_t stringCount = *reinterpret_cast<const std::size_t*>(left + 0x48);
    if (stringCount != *reinterpret_cast<const std::size_t*>(right + 0x48))
        return 1;
    auto* leftStrings = static_cast<const Scaleform::String*>(*reinterpret_cast<void* const*>(left + 0x40));
    auto* rightStrings = static_cast<const Scaleform::String*>(*reinterpret_cast<void* const*>(right + 0x40));
    for (std::size_t i = 0; i < stringCount; ++i)
        if (!SameAs3String(leftStrings + i, rightStrings + i))
            return 1;
    for (std::size_t offset : { std::size_t(0x58), std::size_t(0x5c), std::size_t(0x60), std::size_t(0x64) }) {
        const float difference = *reinterpret_cast<const float*>(left + offset) - *reinterpret_cast<const float*>(right + offset);
        if (difference < -0.00001f || difference > 0.00001f)
            return 1;
    }
    return (*reinterpret_cast<void* const*>(left + 0x68) == *reinterpret_cast<void* const*>(right + 0x68) &&
            *reinterpret_cast<const std::uint32_t*>(left + 0x70) == *reinterpret_cast<const std::uint32_t*>(right + 0x70)) ? 0 : 1;
}

// MS2-FUNCTIONAL: copies the record's scalar fields and strings, resizes its owned string list, then assigns each element.
// @0x142687540
void* CopyTextRecord(void* destination, const void* source)
{
    auto* dst = static_cast<unsigned char*>(destination);
    auto* src = static_cast<const unsigned char*>(source);
    *reinterpret_cast<unsigned*>(dst + 0x10) = *reinterpret_cast<const unsigned*>(src + 0x10);
    *reinterpret_cast<unsigned*>(dst + 0x14) = *reinterpret_cast<const unsigned*>(src + 0x14);
    for (std::size_t offset : { std::size_t(0x18), std::size_t(0x20), std::size_t(0x28), std::size_t(0x30), std::size_t(0x38) })
        *reinterpret_cast<Scaleform::String*>(dst + offset) = *reinterpret_cast<const Scaleform::String*>(src + offset);
    const std::size_t count = *reinterpret_cast<const std::size_t*>(src + 0x48);
    ResizeStringArray(reinterpret_cast<void**>(dst + 0x40), count);
    auto* dstStrings = static_cast<Scaleform::String*>(*reinterpret_cast<void**>(dst + 0x40));
    auto* srcStrings = static_cast<const Scaleform::String*>(*reinterpret_cast<void* const*>(src + 0x40));
    for (std::size_t i = 0; i < count; ++i)
        dstStrings[i] = srcStrings[i];
    for (std::size_t offset : { std::size_t(0x58), std::size_t(0x5c), std::size_t(0x60), std::size_t(0x64), std::size_t(0x70) })
        *reinterpret_cast<unsigned*>(dst + offset) = *reinterpret_cast<const unsigned*>(src + offset);
    *reinterpret_cast<unsigned long long*>(dst + 0x68) = *reinterpret_cast<const unsigned long long*>(src + 0x68);
    return destination;
}

// MS2-FUNCTIONAL: initializes the refcounted text record, all five local-heap strings, and its empty child state.
// @0x1426870e0
void* InitializeTextRecord(void* object)
{
    auto* fields = static_cast<unsigned long long*>(object);
    *reinterpret_cast<void***>(object) = &AS3TextRecordVtable;
    *reinterpret_cast<unsigned*>(static_cast<unsigned char*>(object) + 8) = 1;
    fields[2] = 0;
    for (std::size_t i = 3; i <= 7; ++i)
        new (fields + i) Scaleform::StringLH();
    for (std::size_t i = 8; i <= 13; ++i)
        fields[i] = 0;
    *reinterpret_cast<unsigned*>(fields + 14) = 0;
    return object;
}

// MS2-FUNCTIONAL: finds the source tree's maximum depth and adds it to each destination child and descendant.
// @0x14268e6a0
void AddTreeDepthOffset(void* destination, void* source)
{
    auto* src = static_cast<unsigned char*>(source);
    int maximum = *reinterpret_cast<int*>(src + 0x28);
    auto** sourceChildren = *reinterpret_cast<void***>(src + 0x30);
    const std::size_t sourceCount = *reinterpret_cast<std::size_t*>(src + 0x38);
    for (std::size_t i = 0; i < sourceCount; ++i)
        UpdateTreeMaximumDepth(sourceChildren[i], reinterpret_cast<unsigned*>(&maximum));

    auto* dst = static_cast<unsigned char*>(destination);
    auto** destinationChildren = *reinterpret_cast<void***>(dst + 0x30);
    const std::size_t destinationCount = *reinterpret_cast<std::size_t*>(dst + 0x38);
    for (std::size_t i = 0; i < destinationCount; ++i) {
        auto* child = static_cast<unsigned char*>(destinationChildren[i]);
        *reinterpret_cast<int*>(child + 0x28) += maximum;
        auto** grandchildren = *reinterpret_cast<void***>(child + 0x30);
        const std::size_t grandchildCount = *reinterpret_cast<std::size_t*>(child + 0x38);
        for (std::size_t j = 0; j < grandchildCount; ++j)
            AddTreeNodeValue(grandchildren[j], &maximum);
    }
}

// MS2-FUNCTIONAL: allocates the audio event manager and constructs its event, locks, and circular list sentinel.
// @0x142744fe0
void* CreateAudioEventManager()
{
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    unsigned flags[2] = { 2, 0 };
    auto* object = static_cast<unsigned char*>(reinterpret_cast<void* (*)(void*, std::size_t, const void*)>(heapVtable[10])(
        DAT_143b15f60, 0xf8, flags));
    if (!object)
        return nullptr;
    *reinterpret_cast<void***>(object) = &AS3AudioEventVtable;
    *reinterpret_cast<unsigned*>(object + 8) = 1;
    *reinterpret_cast<unsigned long long*>(object + 0x10) = 0;
    *reinterpret_cast<unsigned long long*>(object + 0x18) = 0;
    ::new (static_cast<void*>(object + 0x20)) Scaleform::Event(false, false);
    ::new (static_cast<void*>(object + 0x80)) Scaleform::Lock(0);
    *reinterpret_cast<unsigned long long*>(object + 0xa8) = 0;
    auto* sentinel = object + 0xb0;
    *reinterpret_cast<void***>(sentinel) = &AS3AudioListNodeVtable;
    *reinterpret_cast<void**>(object + 0xb8) = sentinel;
    *reinterpret_cast<void**>(object + 0xc0) = sentinel;
    ::new (static_cast<void*>(object + 0xc8)) Scaleform::Lock(0);
    object[0x78] = 0;
    object[0xf0] = 0;
    *reinterpret_cast<unsigned*>(object + 0xf4) = 0;
    return object;
}

// MS2-FUNCTIONAL: prints the movie-view heading and enumerates the function and renderer hash tables.
// @0x14268c080
void LogMovieViewFunctions(void* movieView, Scaleform::Log* log)
{
    auto* bytes = static_cast<unsigned char*>(movieView);
    auto encoded = *reinterpret_cast<std::uintptr_t*>(bytes + 0x20);
    const char* name = reinterpret_cast<const char*>((encoded & ~std::uintptr_t(3)) + 0xc);
    log->LogMessage("========== MOVIE VIEW FUNCTIONS FOR %s ======\n", name);
    FUN_14268b710(*reinterpret_cast<void**>(bytes + 0x60), log);
    FUN_14268bd60(*reinterpret_cast<void**>(bytes + 0x70), log);
}

// MS2-FUNCTIONAL: logs each movie view's function tables followed by both renderer function tables.
// @0x14268c0d0
void LogMovieAndRendererFunctions(void* movieRoot, Scaleform::Log* log)
{
    auto* bytes = static_cast<unsigned char*>(movieRoot);
    auto** views = *reinterpret_cast<void***>(bytes + 0xd0);
    const std::size_t count = *reinterpret_cast<std::size_t*>(bytes + 0xd8);
    for (std::size_t i = 0; i < count; ++i)
        LogMovieViewFunctions(views[i], log);
    log->LogMessage("========== RENDERER FUNCTIONS ===============\n");
    FUN_14268b710(*reinterpret_cast<void**>(bytes + 0xe8), log);
    FUN_14268bd60(*reinterpret_cast<void**>(bytes + 0xf0), log);
}

// MS2-FUNCTIONAL: creates and links a sound request under the manager lock, then initializes its FMOD sound or stream.
// @0x142744ea0
void* CreateAudioRequest(void* manager, const char* path, bool stream)
{
    auto* managerBytes = static_cast<unsigned char*>(manager);
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    unsigned flags[2] = { 2, 0 };
    auto* object = static_cast<unsigned char*>(reinterpret_cast<void* (*)(void*, std::size_t, const void*)>(heapVtable[10])(
        DAT_143b15f60, 0x40, flags));
    if (!object)
        return nullptr;

    EnterCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(managerBytes + 0xc8));
    auto* node = object + 0x10;
    auto* sentinel = managerBytes + 0xb0;
    void* oldTail = *reinterpret_cast<void**>(managerBytes + 0xc0);
    *reinterpret_cast<void***>(object) = &AS3SoundRequestVtable;
    *reinterpret_cast<unsigned*>(object + 8) = 1;
    *reinterpret_cast<void***>(node) = &AS3SoundRequestNodeVtable;
    *reinterpret_cast<void**>(node + 8) = sentinel;
    *reinterpret_cast<void**>(node + 0x10) = oldTail;
    *reinterpret_cast<void**>(static_cast<unsigned char*>(oldTail) + 8) = node;
    *reinterpret_cast<void**>(managerBytes + 0xc0) = node;
    *reinterpret_cast<void**>(object + 0x28) = manager;
    *reinterpret_cast<void**>(object + 0x30) = nullptr;
    *reinterpret_cast<void**>(object + 0x38) = nullptr;

    LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(managerBytes + 0xc8));
    auto* system = *reinterpret_cast<FMOD::System**>(managerBytes + 0x10);
    auto* sound = reinterpret_cast<FMOD::Sound**>(object + 0x30);
    const auto result = stream
        ? system->createStream(path, 0x49, nullptr, sound)
        : system->createSound(path, 0x49, nullptr, sound);
    if (result == 0)
        return object;

    *sound = nullptr;
    auto** objectVtable = *reinterpret_cast<void***>(object);
    reinterpret_cast<void (*)(void*, unsigned)>(objectVtable[0])(object, 1);
    return nullptr;
}

// MS2-FUNCTIONAL: builds a linked buffered request, retains its backing data, and creates its callback-fed FMOD sound.
// @0x1427447f0
void* CreateBufferedAudioRequest(void* manager, void* backing, unsigned channels, unsigned rate, bool wideSamples)
{
    auto* managerBytes = static_cast<unsigned char*>(manager);
    EnterCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(managerBytes + 0xc8));
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    unsigned flags[2] = { 2, 0 };
    auto* object = static_cast<unsigned char*>(reinterpret_cast<void* (*)(void*, std::size_t, const void*)>(heapVtable[10])(
        DAT_143b15f60, 0x78, flags));
    if (!object) {
        LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(managerBytes + 0xc8));
        return nullptr;
    }

    auto* node = object + 0x10;
    auto* sentinel = managerBytes + 0xb0;
    void* oldTail = *reinterpret_cast<void**>(managerBytes + 0xc0);
    *reinterpret_cast<void***>(object) = &AS3BufferedRequestVtable;
    *reinterpret_cast<unsigned*>(object + 8) = 1;
    *reinterpret_cast<void***>(node) = &AS3BufferedRequestNodeVtable;
    *reinterpret_cast<void**>(node + 8) = sentinel;
    *reinterpret_cast<void**>(node + 0x10) = oldTail;
    *reinterpret_cast<void**>(static_cast<unsigned char*>(oldTail) + 8) = node;
    *reinterpret_cast<void**>(managerBytes + 0xc0) = node;
    *reinterpret_cast<void**>(object + 0x28) = manager;
    *reinterpret_cast<void**>(object + 0x30) = nullptr;
    *reinterpret_cast<void**>(object + 0x38) = nullptr;
    *reinterpret_cast<void**>(object + 0x40) = backing;
    if (backing)
        FUN_14257dc30(backing);

    const unsigned bits = wideSamples ? 32u : 16u;
    const unsigned format = wideSamples ? 5u : 2u;
    const unsigned length = (rate / 1000u) * (bits >> 3) * channels * 0x5dcu;
    *reinterpret_cast<unsigned*>(object + 0x48) = channels;
    *reinterpret_cast<unsigned*>(object + 0x4c) = rate;
    *reinterpret_cast<unsigned*>(object + 0x50) = bits;
    *reinterpret_cast<unsigned*>(object + 0x68) = format;
    *reinterpret_cast<unsigned*>(object + 0x64) = length;
    *reinterpret_cast<void**>(object + 0x58) = nullptr;
    *reinterpret_cast<unsigned*>(object + 0x60) = 0;
    *reinterpret_cast<unsigned long long*>(object + 0x6c) = 0;

    unsigned char info[0xd8] = {};
    *reinterpret_cast<unsigned*>(info) = sizeof(info);
    *reinterpret_cast<int*>(info + 4) = static_cast<int>(length);
    *reinterpret_cast<int*>(info + 0x0c) = static_cast<int>(channels);
    *reinterpret_cast<unsigned*>(info + 0x10) = rate;
    *reinterpret_cast<unsigned*>(info + 0x14) = format;
    auto* system = *reinterpret_cast<FMOD::System**>(managerBytes + 0x10);
    auto* sound = reinterpret_cast<FMOD::Sound**>(object + 0x30);
    if (system->createSound(nullptr, 0x442, reinterpret_cast<FMOD_CREATESOUNDEXINFO*>(info), sound) == 0)
        (*sound)->getLength(reinterpret_cast<unsigned*>(info), 4);

    LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(managerBytes + 0xc8));
    return object;
}

}
