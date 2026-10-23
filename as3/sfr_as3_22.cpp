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

int FUN_1428d8e96(void*, int*, int*, int*, int*, int*, int*);
int FUN_1428d8e9c(void*, void**);
int FUN_1428d8f26(void*, float*);
int FUN_1428d8eea(void*, float*);
int FUN_1428d8ec0(void*, void*, unsigned, unsigned*);

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
