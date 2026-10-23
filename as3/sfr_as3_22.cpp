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
namespace FMOD {
class Sound
{
public:
    ::FMOD_RESULT getLength(unsigned* length, unsigned timeUnit);
    ::FMOD_RESULT release();
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
