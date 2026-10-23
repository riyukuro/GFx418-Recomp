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
#include "ms2/scaleform/include/kernel/sf_threads.h"
#include "ms2/scaleform/include/gfx/gfx_rendertree.h"
#include <cstdint>
#include <cstring>

extern "C" void FUN_1426906b0(void*, void*, std::size_t);
extern "C" void FUN_142747530(void*, void*, std::size_t);
extern "C" void FUN_1427478c0(void*, void*, std::size_t);
extern "C" void FUN_142585f70(void*, int);

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
void ResizeLocalByteArray(void** array, void* heapOwner, std::size_t requested)
{
    ResizeRawArray(array, heapOwner, requested, 1);
}

// MS2-FUNCTIONAL: applies the same backing-array thresholds to the eight-byte record array.
// @0x14268e9a0
void ResizeLocalRecordArray(void** array, void* heapOwner, std::size_t requested)
{
    ResizeRawArray(array, heapOwner, requested, 8);
}
}

void FUN_14257dcb0(void* object);
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
void ResizeStrongPointerArrayA(void** array, void* heapOwner, std::size_t requested)
{
    ResizeStrongPointerArray(array, heapOwner, requested);
}

// MS2-FUNCTIONAL: releases removed strong references, follows Scaleform's capacity thresholds, and updates size.
// @0x14268eac0
void ResizeStrongPointerArrayB(void** array, void* heapOwner, std::size_t requested)
{
    ResizeStrongPointerArray(array, heapOwner, requested);
}

// MS2-FUNCTIONAL: releases removed strong references, follows Scaleform's capacity thresholds, and updates size.
// @0x14268eb60
void ResizeStrongPointerArrayC(void** array, void* heapOwner, std::size_t requested)
{
    ResizeStrongPointerArray(array, heapOwner, requested);
}

// MS2-FUNCTIONAL: releases removed strong references, follows Scaleform's capacity thresholds, and updates size.
// @0x14268ec00
void ResizeStrongPointerArrayD(void** array, void* heapOwner, std::size_t requested)
{
    ResizeStrongPointerArray(array, heapOwner, requested);
}

// MS2-FUNCTIONAL: releases truncated string storage and default-constructs every newly added element.
// @0x14268e8c0
void ResizeStringArray(void** array, void* heapOwner, std::size_t requested)
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
            ReserveLocalPointerArrayA(array, heapOwner, requested);
    } else if (capacity <= requested) {
        ReserveLocalPointerArrayA(array, heapOwner, requested + (requested >> 2));
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

}
