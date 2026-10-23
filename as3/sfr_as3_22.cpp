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
