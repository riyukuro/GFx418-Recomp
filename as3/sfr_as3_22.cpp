// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_22
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142568420-0x1425686b0 .text$mn
// MS2-RANGE: 0x142675560-0x142675ad0 .text$mn
// MS2-RANGE: 0x142675bb0-0x142678210 .text$mn
// MS2-RANGE: 0x142685f00-0x142688b70 .text$mn
// MS2-RANGE: 0x1426899e0-0x142690d10 .text$mn
// MS2-RANGE: 0x142744560-0x142746480 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"
#include "ms2/scaleform/include/kernel/sf_array.h"
#include "ms2/scaleform/include/kernel/sf_msgformat.h"
#include "ms2/scaleform/include/kernel/sf_string.h"
#include "ms2/scaleform/kernel/sf_memitem.h"
#include "ms2/scaleform/kernel/sf_log.h"
#include "ms2/scaleform/kernel/sf_random.h"
#include "ms2/scaleform/include/kernel/sf_threads.h"
#include "ms2/scaleform/include/gfx/gfx_rendertree.h"
#include "ms2/scaleform/include/gfx/amp/amp_profileframe.h"
#include "ms2/scaleform/include/render/render_perlin.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "hook/ms2hook.h"
#include <cstdint>
#include <cstring>
#include <math.h>
#include <new>
#include <random>
#include <vector>

// The exe functions and globals this unit uses but does not define, declared by their FUN_<va> / DAT_<va> names: the
// hook DLL binds them to the exe, the full exe to the recovered definition at that VA (tools/fullexe/alias.py).
template <class T> using ExeDecl = T;

extern "C" void FUN_1426906b0(void*, void*, std::size_t);
extern "C" void FUN_142747530(void*, void*, std::size_t);
extern "C" void FUN_1427478c0(void*, void*, std::size_t);
extern "C" void FUN_142585f70(void*, int);
extern "C" void* DAT_143b15f60;
// The vftables below are the tables themselves: their users store the table's address (the exe's lea), not its slot 0.
extern ExeDecl<void*> DAT_1431921e0;
extern ExeDecl<void*> DAT_1431921b0;
#define AS3MovieImageDataVtable ((void*)&DAT_1431921b0)
extern ExeDecl<void*> DAT_143192170;
#define AS3MovieImageStringSetVtable ((void*)&DAT_143192170)
extern ExeDecl<void*> DAT_143192190;
#define AS3MovieImageValueSetVtable ((void*)&DAT_143192190)
extern ExeDecl<void*> DAT_1431921a0;
#define AS3MovieImageNameSetVtable ((void*)&DAT_1431921a0)
extern ExeDecl<void*> DAT_143192180;
#define AS3MovieImageTreeVtable ((void*)&DAT_143192180)
extern ExeDecl<void*> DAT_1431921d0;
#define AS3MovieResourceDataVtable ((void*)&DAT_1431921d0)
extern ExeDecl<void*> DAT_143192160;
#define AS3MovieMemoryItemVtable ((void*)&DAT_143192160)
extern ExeDecl<void*> DAT_1431bede8;
#define AS3AudioEventVtable DAT_1431bede8
extern ExeDecl<void*> DAT_1431bec40;
#define AS3AudioListNodeVtable DAT_1431bec40
extern ExeDecl<void*> DAT_1431bed18;
#define AS3SoundRequestVtable DAT_1431bed18
extern ExeDecl<void*> DAT_1431bed50;
#define AS3SoundRequestNodeVtable DAT_1431bed50
extern ExeDecl<void*> DAT_1431bef00;
#define AS3BufferedRequestVtable DAT_1431bef00
extern ExeDecl<void*> DAT_1431bef38;
#define AS3BufferedRequestNodeVtable DAT_1431bef38
extern ExeDecl<void*> DAT_1431bee50;
#define AS3StreamRequestVtable DAT_1431bee50
extern ExeDecl<void*> DAT_1431bee68;
#define AS3StreamRequestNodeVtable DAT_1431bee68
// The exe's read-only constants this unit alone reads: defined here with the exe's values so the full exe links
// (the hook DLL binds the names to the exe's copies).
ExeDecl<float> DAT_142d175c8 = 0.5f;
#define ImageViewportScale DAT_142d175c8
ExeDecl<float> DAT_142d175cc = 2.0f;
#define ImageViewportBias DAT_142d175cc
ExeDecl<float> DAT_142d175e0 = -1.0f;
#define ImageViewportClampBias DAT_142d175e0
ExeDecl<float> DAT_142eab358 = -2.0f;
#define DrawableImageScale2 DAT_142eab358
ExeDecl<float> DAT_142ceab84 = 1.0f;
#define FloatOne DAT_142ceab84
ExeDecl<float[4]> DAT_143003a80 = { 1.0f, 0.0f, 0.0f, 0.0f };
#define ThresholdTransformX DAT_143003a80
ExeDecl<float[4]> DAT_1430569c0 = { 0.0f, 1.0f, 0.0f, 0.0f };
#define ThresholdTransformY DAT_1430569c0
ExeDecl<unsigned char[9]> DAT_143a2f740 = { 0xff, 0, 1, 0xff, 2, 0xff, 0xff, 0xff, 3 };
#define ChannelIndexMap DAT_143a2f740
ExeDecl<std::uint32_t[4]> DAT_14318da30 = { 0x40000000u, 0, 0, 0xbf800000u };
#define ImageViewportColor DAT_14318da30
ExeDecl<float> DAT_14318ea74 = -0.0f;
#define ImageViewportOrigin DAT_14318ea74
extern ExeDecl<void*> DAT_14318f040;
#define MovieImageInfoVtable DAT_14318f040
extern ExeDecl<void*> DAT_14318f048;
#define AS3MovieMarkerVtable DAT_14318f048
extern ExeDecl<void*> DAT_14318f020;
#define AS3TextValueRecordVtable ((void*)&DAT_14318f020)
extern ExeDecl<void*> DAT_14318f030;
#define AS3MovieViewValueVtable ((void*)&DAT_14318f030)
extern ExeDecl<void*> DAT_1431921c0;
#define AS3MovieImageExtraVtable ((void*)&DAT_1431921c0)
extern "C" void FUN_1426240f0(void*, void*, std::size_t);
extern "C" void FUN_14257dcb0(void*);
extern "C" void FUN_1426251d0(void*, void*, std::int64_t);
extern "C" void* FUN_142689640(void*, bool);
int FUN_1428d8ea8(void*, unsigned, unsigned, void**, void**, unsigned*, unsigned*);
int FUN_1428d8eae(void*, void*, void*, unsigned, unsigned);

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


namespace Scaleform {

namespace GFx { class StaticTextRecord; class TaskThreadInPool; }

// The VM's ABC pointer arrays keep these Resize instances out of line.
// MS2-PIN: ?Resize@?$ArrayData@PEAVMethodBodyInfo@Abc@AS3@GFx@Scaleform@@U?$AllocatorLH_POD@PEAVMethodBodyInfo@Abc@AS3@GFx@Scaleform@@$0BFC@@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAX_K@Z 0x142568420
template void ArrayData<GFx::AS3::Abc::MethodBodyInfo*, AllocatorLH_POD<GFx::AS3::Abc::MethodBodyInfo*, GFx::AS3::StatMV_VM_AbcFile_Mem>, ArrayDefaultPolicy>::Resize(UPInt);
// MS2-PIN: ?Resize@?$ArrayData@PEAVMethodInfo@Abc@AS3@GFx@Scaleform@@U?$AllocatorLH_POD@PEAVMethodInfo@Abc@AS3@GFx@Scaleform@@$0BFC@@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAX_K@Z 0x1425684a0
template void ArrayData<GFx::AS3::Abc::MethodInfo*, AllocatorLH_POD<GFx::AS3::Abc::MethodInfo*, GFx::AS3::StatMV_VM_AbcFile_Mem>, ArrayDefaultPolicy>::Resize(UPInt);
// MS2-PIN: ?Resize@?$ArrayData@PEAVScriptInfo@Abc@AS3@GFx@Scaleform@@U?$AllocatorLH_POD@PEAVScriptInfo@Abc@AS3@GFx@Scaleform@@$0BFC@@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAX_K@Z 0x142568520
template void ArrayData<GFx::AS3::Abc::ScriptInfo*, AllocatorLH_POD<GFx::AS3::Abc::ScriptInfo*, GFx::AS3::StatMV_VM_AbcFile_Mem>, ArrayDefaultPolicy>::Resize(UPInt);
// MS2-PIN: ?Resize@?$ArrayData@PEAVTraitInfo@Abc@AS3@GFx@Scaleform@@U?$AllocatorLH_POD@PEAVTraitInfo@Abc@AS3@GFx@Scaleform@@$0BFC@@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAX_K@Z 0x1425685a0
template void ArrayData<GFx::AS3::Abc::TraitInfo*, AllocatorLH_POD<GFx::AS3::Abc::TraitInfo*, GFx::AS3::StatMV_VM_AbcFile_Mem>, ArrayDefaultPolicy>::Resize(UPInt);
template void MsgFormat::FormatD1<unsigned long>(const unsigned long&);
template void MsgFormat::FormatD1<const char*>(const char* const&);
template void MsgFormat::FormatD1<UInt64>(const UInt64&);

// The Context::CreateEntry template allocates TreeContainer::NodeData, runs its encoded
// constructor, and hands the node data to the context entry table.
template Render::TreeContainer*
Render::ContextImpl::Context::CreateEntry<Render::TreeContainer>();

} // namespace Scaleform

namespace Scaleform {
// The AMP readers call these instances out of line (the Ptr ones fold into 0x1426240f0 / 0x14268ec00).
// MS2-PIN: ??_7ScriptBufferStats@MovieInstructionStats@AMP@GFx@Scaleform@@6B@ 0x14318f020
// MS2-PIN: ??_7FuncTreeItem@AMP@GFx@Scaleform@@6B@ 0x14318f040
// MS2-PIN: ??_7?$RefCountBase@UMovieInstructionStats@AMP@GFx@Scaleform@@$0CEC@@Scaleform@@6B@ 0x143192170
// MS2-PIN: ??_7MovieInstructionStats@AMP@GFx@Scaleform@@6B@ 0x143192170
// MS2-PIN: ??_7?$RefCountBase@UMovieFunctionTreeStats@AMP@GFx@Scaleform@@$01@Scaleform@@6B@ 0x143192180
// MS2-PIN: ??_7MovieFunctionTreeStats@AMP@GFx@Scaleform@@6B@ 0x143192180
// MS2-PIN: ??_7?$RefCountBase@UMovieFunctionStats@AMP@GFx@Scaleform@@$0CEC@@Scaleform@@6B@ 0x143192190
// MS2-PIN: ??_7MovieFunctionStats@AMP@GFx@Scaleform@@6B@ 0x143192190
// MS2-PIN: ??_7?$RefCountBase@UMovieSourceLineStats@AMP@GFx@Scaleform@@$0CEC@@Scaleform@@6B@ 0x1431921a0
// MS2-PIN: ??_7MovieSourceLineStats@AMP@GFx@Scaleform@@6B@ 0x1431921a0
// MS2-PIN: ??_7?$RefCountBase@UMovieProfile@AMP@GFx@Scaleform@@$0CEC@@Scaleform@@6B@ 0x1431921b0
// MS2-PIN: ??_7MovieProfile@AMP@GFx@Scaleform@@6B@ 0x1431921b0
// MS2-PIN: ??_7?$RefCountBase@UImageInfo@AMP@GFx@Scaleform@@$0CEC@@Scaleform@@6B@ 0x1431921c0
// MS2-PIN: ??_7ImageInfo@AMP@GFx@Scaleform@@6B@ 0x1431921c0
// MS2-PIN: ??_7?$RefCountBase@VProfileFrame@AMP@GFx@Scaleform@@$0CEC@@Scaleform@@6B@ 0x1431921d0
// MS2-PIN: ??_7ProfileFrame@AMP@GFx@Scaleform@@6B@ 0x1431921d0
// MS2-PIN: ??_7?$RefCountBase@VServerState@AMP@GFx@Scaleform@@$0CEC@@Scaleform@@6B@ 0x1431921e0
// MS2-PIN: ??_7ServerState@AMP@GFx@Scaleform@@6B@ 0x1431921e0
// MS2-PIN: ??_7FunctionDesc@AMP@GFx@Scaleform@@6B@ 0x14318f030
// MS2-PIN: ??_7?$RefCountBase@UFunctionDesc@AMP@GFx@Scaleform@@$0CEC@@Scaleform@@6B@ 0x14318f030
// MS2-PIN: ??_7MarkerInfo@MovieProfile@AMP@GFx@Scaleform@@6B@ 0x14318f048
// MS2-PIN: ??_7?$RefCountBase@UMarkerInfo@MovieProfile@AMP@GFx@Scaleform@@$0CEC@@Scaleform@@6B@ 0x14318f048
// MS2-PIN: ??_7?$RefCountBase@VFuncTreeItem@AMP@GFx@Scaleform@@$01@Scaleform@@6B@ 0x14318f040
// MS2-PIN: ??_7?$RefCountBase@UScriptBufferStats@MovieInstructionStats@AMP@GFx@Scaleform@@$0CEC@@Scaleform@@6B@ 0x14318f020
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0CEC@@Scaleform@@6B@ 0x14318f020
typedef GFx::AMP::MovieInstructionStats::ScriptBufferStats AmpScriptBufferStats;
typedef GFx::AMP::MovieInstructionStats::InstructionTimePair AmpInstructionTimePair;
// @0x14268ec00
template<> SF_NOINLINE void ArrayDataBase<Ptr<AmpScriptBufferStats>, AllocatorLH<Ptr<AmpScriptBufferStats>, Stat_Default_Mem>,
    ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize)
{
    UPInt oldSize = Size;
    if (newSize < oldSize)
    {
        AllocatorLH<Ptr<AmpScriptBufferStats>, Stat_Default_Mem>::DestructArray(Data + newSize, oldSize - newSize);
        if (newSize < (Policy.GetCapacity() >> 1))
            Reserve(pheapAddr, newSize);
    }
    else if (newSize >= Policy.GetCapacity())
    {
        Reserve(pheapAddr, newSize + (newSize >> 2));
    }
    Size = newSize;
}
template<> SF_NOINLINE void ArrayDataBase<Ptr<GFx::AMP::FuncTreeItem>, AllocatorLH<Ptr<GFx::AMP::FuncTreeItem>, Stat_Default_Mem>,
    ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize)
{
    UPInt oldSize = Size;
    if (newSize < oldSize)
    {
        AllocatorLH<Ptr<GFx::AMP::FuncTreeItem>, Stat_Default_Mem>::DestructArray(Data + newSize, oldSize - newSize);
        if (newSize < (Policy.GetCapacity() >> 1))
            Reserve(pheapAddr, newSize);
    }
    else if (newSize >= Policy.GetCapacity())
    {
        Reserve(pheapAddr, newSize + (newSize >> 2));
    }
    Size = newSize;
}
// @0x14268eac0
template<> SF_NOINLINE void ArrayDataBase<Ptr<GFx::AMP::MovieProfile::MarkerInfo>, AllocatorLH<Ptr<GFx::AMP::MovieProfile::MarkerInfo>, Stat_Default_Mem>,
    ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize)
{
    UPInt oldSize = Size;
    if (newSize < oldSize)
    {
        AllocatorLH<Ptr<GFx::AMP::MovieProfile::MarkerInfo>, Stat_Default_Mem>::DestructArray(Data + newSize, oldSize - newSize);
        if (newSize < (Policy.GetCapacity() >> 1))
            Reserve(pheapAddr, newSize);
    }
    else if (newSize >= Policy.GetCapacity())
    {
        Reserve(pheapAddr, newSize + (newSize >> 2));
    }
    Size = newSize;
}
// @0x14268eb60
template<> SF_NOINLINE void ArrayDataBase<Ptr<GFx::AMP::MovieProfile>, AllocatorLH<Ptr<GFx::AMP::MovieProfile>, Stat_Default_Mem>,
    ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize)
{
    UPInt oldSize = Size;
    if (newSize < oldSize)
    {
        AllocatorLH<Ptr<GFx::AMP::MovieProfile>, Stat_Default_Mem>::DestructArray(Data + newSize, oldSize - newSize);
        if (newSize < (Policy.GetCapacity() >> 1))
            Reserve(pheapAddr, newSize);
    }
    else if (newSize >= Policy.GetCapacity())
    {
        Reserve(pheapAddr, newSize + (newSize >> 2));
    }
    Size = newSize;
}
// @0x14268ea20
template<> SF_NOINLINE void ArrayDataBase<Ptr<GFx::AMP::ImageInfo>, AllocatorLH<Ptr<GFx::AMP::ImageInfo>, Stat_Default_Mem>,
    ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize)
{
    UPInt oldSize = Size;
    if (newSize < oldSize)
    {
        AllocatorLH<Ptr<GFx::AMP::ImageInfo>, Stat_Default_Mem>::DestructArray(Data + newSize, oldSize - newSize);
        if (newSize < (Policy.GetCapacity() >> 1))
            Reserve(pheapAddr, newSize);
    }
    else if (newSize >= Policy.GetCapacity())
    {
        Reserve(pheapAddr, newSize + (newSize >> 2));
    }
    Size = newSize;
}
// @0x14268e9a0
template<> SF_NOINLINE void ArrayData<UInt64, AllocatorLH<UInt64, Stat_Default_Mem>,
    ArrayDefaultPolicy>::Resize(UPInt newSize)
{
    UPInt oldSize = this->Size;
    BaseType::ResizeNoConstruct(this, newSize);
    if (newSize > oldSize)
        AllocatorType::ConstructArray(this->Data + oldSize, newSize - oldSize);
}
// @0x14268e7c0
template<> SF_NOINLINE void ArrayData<AmpInstructionTimePair, AllocatorLH<AmpInstructionTimePair, Stat_Default_Mem>,
    ArrayDefaultPolicy>::Resize(UPInt newSize)
{
    UPInt oldSize = this->Size;
    BaseType::ResizeNoConstruct(this, newSize);
    if (newSize > oldSize)
        AllocatorType::ConstructArray(this->Data + oldSize, newSize - oldSize);
}
template<> SF_NOINLINE void ArrayData<GFx::AMP::MovieSourceLineStats::SourceStats, AllocatorLH<GFx::AMP::MovieSourceLineStats::SourceStats, Stat_Default_Mem>,
    ArrayDefaultPolicy>::Resize(UPInt newSize)
{
    UPInt oldSize = this->Size;
    BaseType::ResizeNoConstruct(this, newSize);
    if (newSize > oldSize)
        AllocatorType::ConstructArray(this->Data + oldSize, newSize - oldSize);
}
template<> SF_NOINLINE void ArrayData<GFx::AMP::MovieFunctionStats::FuncStats, AllocatorLH<GFx::AMP::MovieFunctionStats::FuncStats, Stat_Default_Mem>,
    ArrayDefaultPolicy>::Resize(UPInt newSize)
{
    UPInt oldSize = this->Size;
    BaseType::ResizeNoConstruct(this, newSize);
    if (newSize > oldSize)
        AllocatorType::ConstructArray(this->Data + oldSize, newSize - oldSize);
}
} // namespace Scaleform

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {


}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// MS2-PIN: ??$FormatD1@_K@MsgFormat@Scaleform@@QEAAXAEB_K@Z 0x142685ff0

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

// MS2-FUNCTIONAL: reads one PCM block, applies the executable's six-sample endian shuffle, writes both FMOD lock regions, and advances the ring offsets.
// @0x142745f50
unsigned FUN_142745f50(void* player)
{
    auto* bytes = static_cast<unsigned char*>(player);
    auto* reader = *reinterpret_cast<void**>(bytes + 0x40);
    const unsigned requested = *reinterpret_cast<unsigned*>(bytes + 0x60);
    auto** readerVtable = *reinterpret_cast<void***>(reader);
    const auto read = reinterpret_cast<unsigned (*)(void*, void*, unsigned)>(readerVtable[1]);
    unsigned readCount = read(reader, *reinterpret_cast<void**>(bytes + 0x58), requested);
    auto* buffer = static_cast<unsigned char*>(*reinterpret_cast<void**>(bytes + 0x58));
    if (readCount < requested)
        std::memset(buffer + readCount, 0, requested - readCount);

    if (*reinterpret_cast<int*>(bytes + 0x48) == 6) {
        if (*reinterpret_cast<int*>(bytes + 0x68) == 5) {
            for (unsigned pos = 0; pos < readCount; pos += 24) {
                auto* words = reinterpret_cast<std::uint32_t*>(buffer + pos + 8);
                std::swap(words[0], words[2]);
                std::swap(words[1], words[3]);
            }
        } else {
            for (unsigned pos = 0; pos < readCount; pos += 12) {
                auto* words = reinterpret_cast<std::uint16_t*>(buffer + pos + 4);
                std::swap(words[0], words[2]);
                std::swap(words[1], words[3]);
            }
        }
    }

    auto* sound = *reinterpret_cast<void**>(bytes + 0x30);
    void* first = nullptr;
    void* second = nullptr;
    unsigned firstLength = 0, secondLength = 0;
    if (sound && FUN_1428d8ea8(sound, *reinterpret_cast<unsigned*>(bytes + 0x6c), requested,
                               &first, &second, &firstLength, &secondLength) == 0) {
        if (firstLength < requested) {
            std::memcpy(first, buffer, firstLength);
            const unsigned remaining = requested - firstLength;
            const unsigned secondCopy = (remaining < secondLength) ? remaining : secondLength;
            if (secondCopy)
                std::memcpy(second, buffer + firstLength, secondCopy);
            if (secondLength > secondCopy)
                std::memset(static_cast<unsigned char*>(second) + secondCopy, 0, secondLength - secondCopy);
        } else {
            if (requested)
                std::memcpy(first, buffer, requested);
            if (firstLength > requested)
                std::memset(static_cast<unsigned char*>(first) + requested, 0, firstLength - requested);
            if (secondLength)
                std::memset(second, 0, secondLength);
        }
        if (FUN_1428d8eae(sound, first, second, firstLength, secondLength) != 0)
            return 0;
    }
    *reinterpret_cast<unsigned*>(bytes + 0x6c) += readCount;
    *reinterpret_cast<unsigned*>(bytes + 0x70) += readCount;
    if (*reinterpret_cast<unsigned*>(bytes + 0x64) <= *reinterpret_cast<unsigned*>(bytes + 0x6c))
        *reinterpret_cast<unsigned*>(bytes + 0x6c) -= *reinterpret_cast<unsigned*>(bytes + 0x64);
    return readCount;
}

// MS2-FUNCTIONAL: null-checks the channel and returns the isPlaying flag without checking the FMOD result, like the executable.
// @0x142745c40
bool QueryChannelPlaying(void* soundSource)
{
    FMOD::Channel* channel = *reinterpret_cast<FMOD::Channel**>(static_cast<char*>(soundSource) + 0x38);
    bool playing = false;
    // The exe ignores the FMOD result and returns whatever isPlaying left in the flag.
    if (channel)
        channel->isPlaying(&playing);
    return playing;
}
}

int FUN_1428d8efc(void*, void*);
int FUN_1428d8f14(void*, void*);
void FUN_14257d390(void*, long long, unsigned, unsigned);
void FUN_14257bf70(void*, void*, long long, unsigned);
int FUN_1427483a0(void*, int);
unsigned long long FUN_142748160(void*, void*, unsigned);
int FUN_1428d8ea8(void*, unsigned, unsigned, void**, void**, unsigned*, unsigned*);
int FUN_1428d8eae(void*, void*, void*, unsigned, unsigned);
int FUN_1428d8f2c(void*, bool);
int FUN_1428d8e96(void*, int*, int*, int*, int*, int*, int*);
int FUN_1428d8e9c(void*, void**);
int FUN_1428d8f26(void*, float*);
int FUN_1428d8ede(void*, float*);
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

// The copy-style ops share the exe's clip: the op rect (+0x18..+0x24) is in source space and +0x28/+0x2c is the
// destination point. The span is clipped against the source and then the destination, in destination space; the
// source pixel for destination (x, y) is (x - OffX, y - OffY).
struct BitmapCopySpan
{
    int X0, Y0, X1, Y1, OffX, OffY;
};

static bool ClipBitmapCopy(const unsigned char* op, const Scaleform::Render::ImagePlane& src,
                           const Scaleform::Render::ImagePlane& dst, BitmapCopySpan& span)
{
    const int left = *reinterpret_cast<const int*>(op + 0x18), top = *reinterpret_cast<const int*>(op + 0x1c);
    const int right = *reinterpret_cast<const int*>(op + 0x20), bottom = *reinterpret_cast<const int*>(op + 0x24);
    const int destX = *reinterpret_cast<const int*>(op + 0x28), destY = *reinterpret_cast<const int*>(op + 0x2c);
    const int srcW = static_cast<int>(src.Width), srcH = static_cast<int>(src.Height);
    const int dstW = static_cast<int>(dst.Width), dstH = static_cast<int>(dst.Height);
    span.OffX = destX - left;
    span.OffY = destY - top;
    if (srcH < top || bottom < 0 || right < 0 || srcW < left) return false;
    span.X0 = left >= 0 ? destX : span.OffX;
    span.Y0 = top >= 0 ? destY : span.OffY;
    span.X1 = (right < srcW ? right : srcW) + span.OffX;
    span.Y1 = (bottom < srcH ? bottom : srcH) + span.OffY;
    if (span.Y1 < 0 || dstH < span.Y0 || dstW < span.X0 || span.X1 < 0) return false;
    if (span.X0 < 0) span.X0 = 0;
    if (span.X1 > dstW) span.X1 = dstW;
    if (span.Y0 < 0) span.Y0 = 0;
    if (span.Y1 > dstH) span.Y1 = dstH;
    return true;
}

static long long BitmapScanline(const Scaleform::Render::ImagePlane& plane, int y)
{
    return reinterpret_cast<long long>(plane.pData + static_cast<Scaleform::UPInt>(static_cast<unsigned>(y)) * plane.Pitch);
}

static bool BitmapHasAlpha(const unsigned char* op, unsigned offset)
{
    return *(static_cast<const unsigned char*>(*reinterpret_cast<void* const*>(op + offset)) + 0x48) != 0;
}

// MS2-FUNCTIONAL: reproduces the executable's per-pixel difference image, including optional alpha comparison.
// @0x142676190
extern "C" void FUN_142676190(void* operation, void*, Scaleform::Render::ImageData* output, void** inputs)
{
    using Scaleform::Render::ImageData;
    using Scaleform::Render::ImagePlane;
    auto* reference = static_cast<ImageData*>(inputs[0]);
    auto* candidate = static_cast<ImageData*>(inputs[1]);
    ImagePlane outPlane, referencePlane, candidatePlane;
    output->GetPlane(0, &outPlane);
    reference->GetPlane(0, &referencePlane);
    candidate->GetPlane(0, &candidatePlane);

    auto* operationBytes = static_cast<unsigned char*>(operation);
    const auto* referenceConfig = static_cast<const unsigned char*>(*reinterpret_cast<void**>(operationBytes + 0x10));
    const auto* candidateConfig = static_cast<const unsigned char*>(*reinterpret_cast<void**>(operationBytes + 0x40));
    const bool compareReferenceAlpha = *reinterpret_cast<const bool*>(referenceConfig + 0x48);
    const bool compareCandidateAlpha = *reinterpret_cast<const bool*>(candidateConfig + 0x48);
    const unsigned width = referencePlane.Width < outPlane.Width ? referencePlane.Width : outPlane.Width;
    const unsigned height = referencePlane.Height < outPlane.Height ? referencePlane.Height : outPlane.Height;
    for (unsigned y = 0; y < height; ++y) {
        const auto referenceRow = BitmapScanline(referencePlane, static_cast<int>(y));
        const auto candidateRow = BitmapScanline(candidatePlane, static_cast<int>(y));
        const auto outputRow = BitmapScanline(outPlane, static_cast<int>(y));
        for (unsigned x = 0; x < width; ++x) {
            unsigned referencePixel = 0, candidatePixel = 0;
            FUN_14257bf70(reference, &referencePixel, referenceRow, x);
            FUN_14257bf70(candidate, &candidatePixel, candidateRow, x);
            const auto* referenceChannels = reinterpret_cast<const std::int8_t*>(&referencePixel);
            const auto* candidateChannels = reinterpret_cast<const std::int8_t*>(&candidatePixel);
            int r = referenceChannels[0] - candidateChannels[0];
            int g = referenceChannels[1] - candidateChannels[1];
            int b = referenceChannels[2] - candidateChannels[2];
            int a = (compareReferenceAlpha ? referenceChannels[3] : -1) -
                    (compareCandidateAlpha ? candidateChannels[3] : -1);
            // Equal colours with a different alpha give 0xZZFFFFFF (ZZ = alpha difference); otherwise alpha is 0xff.
            if (r == 0 && g == 0 && b == 0 && a != 0)
                r = g = b = -1;
            else
                a = 0xff;
            unsigned result = static_cast<unsigned char>(r) |
                              (static_cast<unsigned>(static_cast<unsigned char>(g)) << 8) |
                              (static_cast<unsigned>(static_cast<unsigned char>(b)) << 16) |
                              (static_cast<unsigned>(static_cast<unsigned char>(a)) << 24);
            FUN_14257d390(output, outputRow, x, result);
        }
    }
}

// MS2-FUNCTIONAL: threshold. The masked pixel is compared with the masked reference using the op at +0x40 (six
// unsigned comparisons, anything else selects nothing) and selected pixels take the colour at +0x48.
// @0x142677ea0
extern "C" void FUN_142677ea0(void* operation, void*, Scaleform::Render::ImageData* output, void** inputs)
{
    using Scaleform::Render::ImageData;
    using Scaleform::Render::ImagePlane;
    auto* source = static_cast<ImageData*>(inputs[0]);
    ImagePlane destinationPlane, sourcePlane;
    output->GetPlane(0, &destinationPlane);
    source->GetPlane(0, &sourcePlane);
    const auto* op = static_cast<const unsigned char*>(operation);
    BitmapCopySpan span;
    if (!ClipBitmapCopy(op, sourcePlane, destinationPlane, span)) return;

    const unsigned mode = *reinterpret_cast<const unsigned*>(op + 0x40);
    const unsigned mask = *reinterpret_cast<const unsigned*>(op + 0x4c);
    const unsigned reference = *reinterpret_cast<const unsigned*>(op + 0x44) & mask;
    const unsigned replacement = *reinterpret_cast<const unsigned*>(op + 0x48);
    for (int y = span.Y0; y < span.Y1; ++y) {
        const long long sourceRow = BitmapScanline(sourcePlane, y - span.OffY);
        const long long destinationRow = BitmapScanline(destinationPlane, y);
        for (int x = span.X0; x < span.X1; ++x) {
            unsigned pixel = 0;
            FUN_14257bf70(source, &pixel, sourceRow, static_cast<unsigned>(x - span.OffX));
            const unsigned lhs = pixel & mask;
            bool selected = false;
            switch (mode) {
            case 0: selected = lhs < reference; break;
            case 1: selected = lhs <= reference; break;
            case 2: selected = lhs > reference; break;
            case 3: selected = lhs >= reference; break;
            case 4: selected = lhs == reference; break;
            case 5: selected = lhs != reference; break;
            default: break;
            }
            if (!BitmapHasAlpha(op, 0x10)) pixel |= 0xff000000u;
            unsigned result = selected ? replacement : pixel;
            if (!BitmapHasAlpha(op, 8)) result |= 0xff000000u;
            FUN_14257d390(output, destinationRow, static_cast<unsigned>(x), result);
        }
    }
}

// MS2-FUNCTIONAL: merge. Each RGBA channel is (dest * (256 - w) + source * w) >> 8 with the weights at +0x40..+0x4c
// in red, green, blue, alpha order.
// @0x142676ef0
extern "C" void FUN_142676ef0(void* operation, void*, Scaleform::Render::ImageData* image, void** inputs)
{
    using Scaleform::Render::ImageData;
    using Scaleform::Render::ImagePlane;
    auto* overlay = static_cast<ImageData*>(inputs[0]);
    ImagePlane imagePlane, overlayPlane;
    image->GetPlane(0, &imagePlane);
    overlay->GetPlane(0, &overlayPlane);
    const auto* op = static_cast<const unsigned char*>(operation);
    BitmapCopySpan span;
    if (!ClipBitmapCopy(op, overlayPlane, imagePlane, span)) return;
    const int* weights = reinterpret_cast<const int*>(op + 0x40);
    // RGBA channel index -> byte position in the BGRA pixel.
    static const unsigned BytePos[4] = { 2, 1, 0, 3 };
    for (int y = span.Y0; y < span.Y1; ++y) {
        const long long srcRow = BitmapScanline(overlayPlane, y - span.OffY);
        const long long dstRow = BitmapScanline(imagePlane, y);
        for (int x = span.X0; x < span.X1; ++x) {
            unsigned src = 0, dst = 0;
            FUN_14257bf70(overlay, &src, srcRow, static_cast<unsigned>(x - span.OffX));
            FUN_14257bf70(image, &dst, dstRow, static_cast<unsigned>(x));
            auto* sc = reinterpret_cast<unsigned char*>(&src);
            auto* dc = reinterpret_cast<unsigned char*>(&dst);
            if (!BitmapHasAlpha(op, 0x10)) sc[3] = 0xff;
            if (!BitmapHasAlpha(op, 8)) dc[3] = 0xff;
            unsigned result = 0;
            auto* rc = reinterpret_cast<unsigned char*>(&result);
            for (unsigned c = 0; c < 4; ++c) {
                const unsigned pos = BytePos[c];
                const int w = weights[c];
                rc[pos] = static_cast<unsigned char>(
                    static_cast<unsigned>(dc[pos] * (256 - w) + sc[pos] * w) >> 8);
            }
            if (!BitmapHasAlpha(op, 8)) rc[3] = 0xff;
            FUN_14257d390(image, dstRow, static_cast<unsigned>(x), result);
        }
    }
}

// MS2-FUNCTIONAL: copyPixels without mergeAlpha. Copies back to front (so an overlapping self-copy works) and forces
// opaque alpha when either side lacks alpha.
// @0x142677c70
extern "C" void FUN_142677c70(void* operation, void*, Scaleform::Render::ImageData* destination, void** inputs)
{
    using Scaleform::Render::ImageData;
    using Scaleform::Render::ImagePlane;
    auto* source = static_cast<ImageData*>(inputs[0]);
    ImagePlane dst, src;
    destination->GetPlane(0, &dst);
    source->GetPlane(0, &src);
    const auto* op = static_cast<const unsigned char*>(operation);
    BitmapCopySpan span;
    if (!ClipBitmapCopy(op, src, dst, span)) return;
    for (int y = span.Y1 - 1; y >= span.Y0; --y) {
        const long long srcRow = BitmapScanline(src, y - span.OffY);
        const long long dstRow = BitmapScanline(dst, y);
        for (int x = span.X1 - 1; x >= span.X0; --x) {
            unsigned pixel = 0;
            FUN_14257bf70(source, &pixel, srcRow, static_cast<unsigned>(x - span.OffX));
            if (!BitmapHasAlpha(op, 0x10) || !BitmapHasAlpha(op, 8)) pixel |= 0xff000000u;
            FUN_14257d390(destination, dstRow, static_cast<unsigned>(x), pixel);
        }
    }
}

// MS2-FUNCTIONAL: copyChannel. The source and destination channels at +0x40/+0x44 go through the selector table to
// RGBA indices; an unknown channel copies nothing.
// @0x142676380
extern "C" void FUN_142676380(void* operation, void*, Scaleform::Render::ImageData* destination, void** inputs)
{
    using Scaleform::Render::ImageData;
    using Scaleform::Render::ImagePlane;
    auto* source = static_cast<ImageData*>(inputs[0]);
    ImagePlane dst, src;
    destination->GetPlane(0, &dst);
    source->GetPlane(0, &src);
    const auto* op = static_cast<const unsigned char*>(operation);
    BitmapCopySpan span;
    if (!ClipBitmapCopy(op, src, dst, span)) return;
    unsigned from = *reinterpret_cast<const unsigned*>(op + 0x40);
    unsigned to = *reinterpret_cast<const unsigned*>(op + 0x44);
    from = from < 9 ? ChannelIndexMap[from] : 0xff;
    to = to < 9 ? ChannelIndexMap[to] : 0xff;
    if (from >= 4 || to >= 4) return;
    // RGBA channel index -> byte position in the BGRA pixel.
    static const unsigned BytePos[4] = { 2, 1, 0, 3 };
    for (int y = span.Y0; y < span.Y1; ++y) {
        const long long srcRow = BitmapScanline(src, y - span.OffY);
        const long long dstRow = BitmapScanline(dst, y);
        for (int x = span.X0; x < span.X1; ++x) {
            unsigned srcPixel = 0, dstPixel = 0;
            FUN_14257bf70(destination, &dstPixel, dstRow, static_cast<unsigned>(x));
            FUN_14257bf70(source, &srcPixel, srcRow, static_cast<unsigned>(x - span.OffX));
            auto* sc = reinterpret_cast<unsigned char*>(&srcPixel);
            auto* dc = reinterpret_cast<unsigned char*>(&dstPixel);
            if (!BitmapHasAlpha(op, 0x10)) sc[3] = 0xff;
            dc[BytePos[to]] = sc[BytePos[from]];
            if (!BitmapHasAlpha(op, 8)) dc[3] = 0xff;
            FUN_14257d390(destination, dstRow, static_cast<unsigned>(x), dstPixel);
        }
    }
}

// MS2-FUNCTIONAL: paletteMap. The table at +0x40 is four 256-entry UInt32 arrays (red, green, blue, alpha); a
// channel selected in the mask at +0x48 contributes its table entry, the others their own bits, and the four
// contributions are summed.
// @0x142677460
extern "C" void FUN_142677460(void* operation, void*, Scaleform::Render::ImageData* destination, void** inputs)
{
    using Scaleform::Render::ImageData;
    using Scaleform::Render::ImagePlane;
    auto* source = static_cast<ImageData*>(inputs[0]);
    ImagePlane dst, src;
    destination->GetPlane(0, &dst);
    source->GetPlane(0, &src);
    const auto* op = static_cast<const unsigned char*>(operation);
    BitmapCopySpan span;
    if (!ClipBitmapCopy(op, src, dst, span)) return;
    const unsigned mask = *reinterpret_cast<const unsigned*>(op + 0x48);
    const auto* lut = *reinterpret_cast<const unsigned* const*>(op + 0x40);
    for (int y = span.Y0; y < span.Y1; ++y) {
        const long long srcRow = BitmapScanline(src, y - span.OffY);
        const long long dstRow = BitmapScanline(dst, y);
        for (int x = span.X0; x < span.X1; ++x) {
            unsigned pixel = 0;
            FUN_14257bf70(source, &pixel, srcRow, static_cast<unsigned>(x - span.OffX));
            auto* c = reinterpret_cast<unsigned char*>(&pixel);
            if (!BitmapHasAlpha(op, 0x10)) c[3] = 0xff;
            const unsigned red = mask & 1 ? lut[c[2]] : static_cast<unsigned>(c[2]) << 16;
            const unsigned green = mask & 2 ? lut[0x100 + c[1]] : static_cast<unsigned>(c[1]) << 8;
            const unsigned blue = mask & 4 ? lut[0x200 + c[0]] : c[0];
            const unsigned alpha = mask & 8 ? lut[0x300 + c[3]] : static_cast<unsigned>(c[3]) << 24;
            unsigned result = red + green + blue + alpha;
            if (!BitmapHasAlpha(op, 8)) result |= 0xff000000u;
            FUN_14257d390(destination, dstRow, static_cast<unsigned>(x), result);
        }
    }
}

// MS2-FUNCTIONAL: copyPixels with mergeAlpha. The op rect (+0x18..+0x24) is in source space and +0x28/+0x2c is the
// destination point; the dest span is clipped against the source (or, with an alpha bitmap, against the mask rect at
// +0x48/+0x4c) and then against the destination. Source alpha is scaled by the mask alpha and blended over the dest.
// @0x142676660
extern "C" void FUN_142676660(void* operation, void*, Scaleform::Render::ImageData* destination, void** inputs)
{
    using Scaleform::Render::Color;
    using Scaleform::Render::ImageData;
    using Scaleform::Render::ImagePlane;
    auto* source = static_cast<ImageData*>(inputs[0]);
    ImagePlane dst, src;
    destination->GetPlane(0, &dst);
    source->GetPlane(0, &src);
    const auto* op = static_cast<const unsigned char*>(operation);
    const int left = *reinterpret_cast<const int*>(op + 0x18), top = *reinterpret_cast<const int*>(op + 0x1c);
    const int right = *reinterpret_cast<const int*>(op + 0x20), bottom = *reinterpret_cast<const int*>(op + 0x24);
    const int destX = *reinterpret_cast<const int*>(op + 0x28), destY = *reinterpret_cast<const int*>(op + 0x2c);
    const int dstW = static_cast<int>(dst.Width), dstH = static_cast<int>(dst.Height);
    const int srcOffX = destX - left, srcOffY = destY - top;
    if (static_cast<int>(src.Height) < top || bottom < 0 || right < 0 || static_cast<int>(src.Width) < left) return;
    int x0 = left >= 0 ? destX : srcOffX, y0 = top >= 0 ? destY : srcOffY;
    int x1 = (right < static_cast<int>(src.Width) ? right : static_cast<int>(src.Width)) + srcOffX;
    int y1 = (bottom < static_cast<int>(src.Height) ? bottom : static_cast<int>(src.Height)) + srcOffY;
    if (y1 < 0 || dstH < y0 || dstW < x0 || x1 < 0) return;
    const bool hasMask = *reinterpret_cast<void* const*>(op + 0x40) != nullptr;
    auto* mask = static_cast<ImageData*>(hasMask ? inputs[1] : inputs[0]);
    ImagePlane maskPlane;
    mask->GetPlane(0, &maskPlane);
    int maskOffX = srcOffX, maskOffY = srcOffY;
    if (hasMask) {
        const int maskLeft = *reinterpret_cast<const int*>(op + 0x48), maskTop = *reinterpret_cast<const int*>(op + 0x4c);
        maskOffX = destX - maskLeft;
        maskOffY = destY - maskTop;
        int maskRight = right - left + maskLeft, maskBottom = bottom - top + maskTop;
        if (static_cast<int>(maskPlane.Height) < maskTop || maskBottom < 0 || maskRight < 0 ||
            static_cast<int>(maskPlane.Width) < maskLeft) return;
        if (static_cast<int>(maskPlane.Width) <= maskRight) maskRight = static_cast<int>(maskPlane.Width);
        if (static_cast<int>(maskPlane.Height) <= maskBottom) maskBottom = static_cast<int>(maskPlane.Height);
        // The exe takes the span from the mask rect here; the source clip above only decides the early exit.
        x0 = maskLeft >= 0 ? destX : maskOffX;
        y0 = maskTop >= 0 ? destY : maskOffY;
        x1 = maskOffX + maskRight;
        y1 = maskOffY + maskBottom;
        if (y1 < 0 || dstH < y0 || dstW < x0 || x1 < 0) return;
    }
    if (y0 < 0) y0 = 0;
    if (x0 < 0) x0 = 0;
    if (x1 > dstW) x1 = dstW;
    if (y1 > dstH) y1 = dstH;
    const auto* srcAlphaConfig = static_cast<const unsigned char*>(*reinterpret_cast<void* const*>(op + 0x10));
    const auto* dstAlphaConfig = static_cast<const unsigned char*>(*reinterpret_cast<void* const*>(op + 8));
    const bool preserveDestinationAlpha = *reinterpret_cast<const bool*>(op + 0x50);
    for (int y = y0; y < y1; ++y) {
        Scaleform::UByte* dstLine = dst.pData + static_cast<Scaleform::UPInt>(static_cast<unsigned>(y)) * dst.Pitch;
        Scaleform::UByte* srcLine = src.pData + static_cast<Scaleform::UPInt>(static_cast<unsigned>(y - srcOffY)) * src.Pitch;
        Scaleform::UByte* maskLine = maskPlane.pData + static_cast<Scaleform::UPInt>(static_cast<unsigned>(y - maskOffY)) * maskPlane.Pitch;
        for (int x = x0; x < x1; ++x) {
            unsigned foreground = 0, coverage = 0, background = 0;
            FUN_14257bf70(source, &foreground, reinterpret_cast<long long>(srcLine), static_cast<unsigned>(x - srcOffX));
            auto* fg = reinterpret_cast<unsigned char*>(&foreground);
            if (!*reinterpret_cast<const bool*>(srcAlphaConfig + 0x48)) fg[3] = 0xff;
            if (hasMask)
                FUN_14257bf70(mask, &coverage, reinterpret_cast<long long>(maskLine), static_cast<unsigned>(x - maskOffX));
            else
                coverage = foreground;
            FUN_14257bf70(destination, &background, reinterpret_cast<long long>(dstLine), static_cast<unsigned>(x));
            const unsigned char sourceAlpha =
                static_cast<unsigned char>(fg[3] * (hasMask ? (coverage >> 24) + 1 : 0x100u) >> 8);
            unsigned char outAlpha = sourceAlpha;
            if (preserveDestinationAlpha) {
                const unsigned char bgAlpha = reinterpret_cast<const unsigned char*>(&background)[3];
                outAlpha = static_cast<unsigned char>(static_cast<int>(
                    static_cast<float>(bgAlpha) / 255.0f * static_cast<float>(255 - sourceAlpha) + sourceAlpha));
            }
            if (!*reinterpret_cast<const bool*>(dstAlphaConfig + 0x48)) outAlpha = 0xff;
            Color result = Color::Blend(Color(background), Color(foreground),
                                        static_cast<float>(sourceAlpha) / static_cast<float>(outAlpha));
            result.Channels.Alpha = outAlpha;
            FUN_14257d390(destination, reinterpret_cast<long long>(dstLine), static_cast<unsigned>(x), result.Raw);
        }
    }
}

// MS2-FUNCTIONAL: colorTransform. Each channel becomes ((c / 255) * mul + add) * 256 clamped to [0, 255], with the
// multipliers at +0x40 and offsets at +0x50 in red, green, blue, alpha order. When the destination has no alpha the
// colour terms are scaled by (alphaMul + alphaAdd) and the alpha is written opaque.
// @0x142675d30
extern "C" void FUN_142675d30(void* operation, void*, Scaleform::Render::ImageData* destination, void** inputs)
{
    using Scaleform::Render::ImageData;
    using Scaleform::Render::ImagePlane;
    auto* source = static_cast<ImageData*>(inputs[0]);
    ImagePlane dst, src;
    destination->GetPlane(0, &dst);
    source->GetPlane(0, &src);
    const auto* op = static_cast<const unsigned char*>(operation);
    BitmapCopySpan span;
    if (!ClipBitmapCopy(op, src, dst, span)) return;
    float mul[4], add[4];
    for (unsigned i = 0; i < 4; ++i) mul[i] = *reinterpret_cast<const float*>(op + 0x40 + i * 4);
    for (unsigned i = 0; i < 4; ++i) add[i] = *reinterpret_cast<const float*>(op + 0x50 + i * 4);
    if (!BitmapHasAlpha(op, 8)) {
        const float alphaFactor = mul[3] + add[3];
        for (unsigned i = 0; i < 3; ++i) {
            mul[i] *= alphaFactor;
            add[i] *= alphaFactor;
        }
        mul[3] = 1.0f;
        add[3] = 0.0f;
    }
    // RGBA channel index -> byte position in the BGRA pixel.
    static const unsigned BytePos[4] = { 2, 1, 0, 3 };
    for (int y = span.Y0; y < span.Y1; ++y) {
        const long long srcRow = BitmapScanline(src, y - span.OffY);
        const long long dstRow = BitmapScanline(dst, y);
        for (int x = span.X0; x < span.X1; ++x) {
            unsigned pixel = 0;
            FUN_14257bf70(source, &pixel, srcRow, static_cast<unsigned>(x - span.OffX));
            auto* c = reinterpret_cast<unsigned char*>(&pixel);
            if (!BitmapHasAlpha(op, 0x10)) c[3] = 0xff;
            unsigned result = 0;
            auto* out = reinterpret_cast<unsigned char*>(&result);
            for (unsigned channel = 0; channel < 4; ++channel) {
                const unsigned pos = BytePos[channel];
                float value = (static_cast<float>(c[pos]) / 255.0f * mul[channel] + add[channel]) * 256.0f;
                if (value > 255.0f) value = 255.0f;
                if (value < 0.0f) value = 0.0f;
                out[pos] = static_cast<unsigned char>(static_cast<int>(value));
            }
            if (!BitmapHasAlpha(op, 8)) out[3] = 0xff;
            FUN_14257d390(destination, dstRow, static_cast<unsigned>(x), result);
        }
    }
}

// MS2-FUNCTIONAL: flood-fills the executable's clipped pixel region from its seed using 4-connected equal-color spans.
// @0x142676bd0
extern "C" void FUN_142676bd0(void* operation, void*, Scaleform::Render::ImageData* image)
{
    using Scaleform::Render::ImageData;
    using Scaleform::Render::ImagePlane;
    ImagePlane plane;
    image->GetPlane(0, &plane);
    const auto* op = static_cast<const unsigned char*>(operation);
    const int seedX = *reinterpret_cast<const int*>(op + 0x10);
    const int seedY = *reinterpret_cast<const int*>(op + 0x14);
    const int left = 0, top = 0;
    const int right = static_cast<int>(plane.Width), bottom = static_cast<int>(plane.Height);
    if (seedX < left || seedY < top || seedX >= right || seedY >= bottom) return;
    const unsigned fill = *reinterpret_cast<const unsigned*>(op + 0x18);
    const bool preserveAlpha = *reinterpret_cast<const bool*>(
        static_cast<const unsigned char*>(*reinterpret_cast<void* const*>(op + 8)) + 0x48);
    unsigned seed = 0;
    FUN_14257bf70(image, &seed, BitmapScanline(plane, seedY), static_cast<unsigned>(seedX));
    if (!preserveAlpha) { seed |= 0xff000000u; }
    unsigned replacement = fill;
    if (!preserveAlpha) replacement |= 0xff000000u;
    if (seed == replacement) return;

    std::vector<std::pair<int, int>> pending;
    pending.emplace_back(seedX, seedY);
    while (!pending.empty()) {
        const int x = pending.back().first;
        const int y = pending.back().second;
        pending.pop_back();
        if (x < left || y < top || x >= right || y >= bottom) continue;
        unsigned pixel = 0;
        FUN_14257bf70(image, &pixel, BitmapScanline(plane, y), static_cast<unsigned>(x));
        if (!preserveAlpha) pixel |= 0xff000000u;
        if (pixel != seed) continue;
        FUN_14257d390(image, BitmapScanline(plane, y), static_cast<unsigned>(x), replacement);
        pending.emplace_back(x - 1, y);
        pending.emplace_back(x + 1, y);
        pending.emplace_back(x, y - 1);
        pending.emplace_back(x, y + 1);
    }
}

// BitmapData.perlinNoise: per selected channel (red, green, blue, alpha when transparent; grayscale draws red into
// all three colour bytes) one of eight lattice generators is picked from the seed, and every octave cosine-
// interpolates SmoothNoise at the four lattice corners around the (offset) sample point; frequency doubles and
// amplitude halves per octave, the sum is normalised by the total amplitude.
// MS2-FUNCTIONAL: (corrected, sfr36) reads the plane once instead of per pixel; the generator parameters are our table
// @0x142677740
extern "C" void FUN_142677740(void* operation, void*, Scaleform::Render::ImageData* image)
{
    using namespace Scaleform;
    using Scaleform::Render::ImagePlane;
    using Scaleform::Render::PerlinGenerator;
    // Row stride and polynomial coefficients of the eight generators (exe 0x143191a90).
    static const int Generators[8][4] = {
        {67, 19937, 178757, 7978189}, {97, 21701, 100511, 2200591}, {73, 23209, 499321, 9218263},
        {19, 44497, 422861, 6200351}, {59, 43261, 300589, 9299317}, {17, 33461, 475333, 1200809},
        {23, 96557, 457117, 6267011}, {43, 28657, 199669, 2299553},
    };
    const auto* op         = static_cast<const unsigned char*>(operation);
    const float baseX      = *reinterpret_cast<const float*>(op + 0x10);
    const float baseY      = *reinterpret_cast<const float*>(op + 0x14);
    const unsigned octaves = *reinterpret_cast<const unsigned*>(op + 0x18);
    const int seed         = *reinterpret_cast<const int*>(op + 0x1c);
    unsigned channels      = *reinterpret_cast<const unsigned*>(op + 0x24);
    const bool gray        = *reinterpret_cast<const bool*>(op + 0x28);
    const auto* offsets    = reinterpret_cast<const float*>(op + 0x2c);
    const unsigned offsetCount = *reinterpret_cast<const unsigned*>(op + 0xac);
    const float pi = 3.14159265f;
    if (gray)
        channels = (channels & ~6u) | 1u;

    ImagePlane plane;
    image->GetPlane(0, &plane);
    for (unsigned y = 0; y < plane.Height; ++y)
    {
        UByte* line = plane.pData + plane.Pitch * y;
        for (unsigned x = 0; x < plane.Width; ++x)
        {
            const bool transparent =
                *(static_cast<const unsigned char*>(*reinterpret_cast<void* const*>(op + 8)) + 0x48) != 0;
            UInt32 color = 0;
            UByte  alpha = 0xff;
            for (unsigned ch = 0; ch < (transparent ? 4u : 3u); ++ch)
            {
                if (!(channels & (1u << ch)))
                    continue;
                PerlinGenerator gen;
                const int* g = Generators[((seed + (int)ch) * -3) & 7];
                gen.Stride = g[0]; gen.A = g[1]; gen.B = g[2]; gen.C = g[3];

                float fx = 2.0f / baseX, fy = 2.0f / baseY;
                float total = 0.0f, weight = 0.0f, amp = 1.0f;
                for (unsigned o = 0; o < octaves; ++o)
                {
                    float px = (float)x * fx, py = (float)y * fy;
                    if (o < offsetCount)
                    {
                        px += offsets[o * 2];
                        py += offsets[o * 2 + 1];
                    }
                    const int ix = (int)px, iy = (int)py;
                    const float tx = (float)((1.0 - cos((double)((px - (float)ix) * pi))) * 0.5);
                    const float ty = (float)((1.0 - cos((double)((py - (float)iy) * pi))) * 0.5);
                    const float n00 = gen.SmoothNoise(ix, iy);
                    const float n10 = gen.SmoothNoise(ix + 1, iy);
                    const float n01 = gen.SmoothNoise(ix, iy + 1);
                    const float n11 = gen.SmoothNoise(ix + 1, iy + 1);
                    fx += fx;
                    fy += fy;
                    weight += amp;
                    total += ((n00 * (1.0f - tx) + n10 * tx) * (1.0f - ty) + (n01 * (1.0f - tx) + n11 * tx) * ty + 1.0f)
                             * 0.5f * amp;
                    amp *= 0.5f;
                }
                const UByte v = (UByte)(int)((total / weight) * 255.0f);
                if (gray && ch != 3)
                    color = v | ((UInt32)v << 8) | ((UInt32)v << 16);
                else if (ch == 0)
                    color = (color & 0x0000ffffu) | ((UInt32)v << 16);
                else if (ch == 1)
                    color = (color & 0xffff00ffu) | ((UInt32)v << 8);
                else if (ch == 2)
                    color = (color & 0xffffff00u) | v;
                else
                    alpha = v;
            }
            if (!transparent)
                alpha = 0xff;
            image->SetPixelInScanline(line, x, (color & 0x00ffffffu) | ((UInt32)alpha << 24));
        }
    }
}

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
        FUN_1428d8ede(channel, &volume);
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

// stores both flags and the system pointer before querying and caching the software rate.
// @0x142745bc0
bool InitializeAudioSystem(void* player, void* system, unsigned char flag0, unsigned char flag1)
{
    auto* bytes = static_cast<unsigned char*>(player);
    bytes[0xf0] = flag0;
    bytes[0xf1] = flag1;
    *reinterpret_cast<void**>(bytes + 0x10) = system;
    if (system)
    {
        int rate = 0;
        FUN_1428d8e96(system, &rate, nullptr, nullptr, nullptr, nullptr, nullptr);
        *reinterpret_cast<float*>(bytes + 0xf4) = static_cast<float>(rate);
    }
    return *reinterpret_cast<void**>(bytes + 0x10) != nullptr;
}
}

namespace Scaleform {
namespace GFx { namespace AMP {
class MaxIdVisitor
{
public:
    MaxIdVisitor() : MaxId(0) { }
    void operator()(FuncTreeItem* treeItem)
    {
        MaxId = Alg::Max(MaxId, treeItem->TreeItemId);
    }
    UInt32 MaxId;
};

class NumItemsVisitor
{
public:
    NumItemsVisitor() : NumItems(0) { }
    void operator()(FuncTreeItem* treeItem)
    {
        SF_UNUSED(treeItem);
        ++NumItems;
    }
    int NumItems;
};

class OffsetIdVisitor
{
public:
    OffsetIdVisitor(UInt32 offsetId) : OffsetId(offsetId) { }
    void operator()(FuncTreeItem* treeItem)
    {
        treeItem->TreeItemId += OffsetId;
    }
private:
    UInt32 OffsetId;
};

// @0x142686540
template<> void FuncTreeItem::Visit<MaxIdVisitor>(MaxIdVisitor& visitor)
{
    visitor(this);
    for (UPInt i = 0; i < Children.GetSize(); ++i)
    {
        Children[i]->Visit(visitor);
    }
}
}}

namespace GFx { namespace AMP {
// @0x1426865a0
template<> void FuncTreeItem::Visit<NumItemsVisitor>(NumItemsVisitor& visitor)
{
    visitor(this);
    for (UPInt i = 0; i < Children.GetSize(); ++i)
    {
        Children[i]->Visit(visitor);
    }
}
}}

namespace GFx { namespace AMP {
// @0x1426865f0
template<> void FuncTreeItem::Visit<OffsetIdVisitor>(OffsetIdVisitor& visitor)
{
    visitor(this);
    for (UPInt i = 0; i < Children.GetSize(); ++i)
    {
        Children[i]->Visit(visitor);
    }
}
}}


namespace GFx { namespace AMP {
enum { NativeCodeSwdHandle = 1 };

struct FunctionTreeVisitor
{
    FunctionTreeVisitor(bool includeActionscipt) : IncludeActionScript(includeActionscipt) { }
    void operator()(const FuncTreeItem* root)
    {
        if (IncludeActionScript || (root->FunctionId >> 32) == GFx::AMP::NativeCodeSwdHandle)
        {
            Hash<UInt64, MovieFunctionStats::FuncStats>::Iterator it = FuncMap.Find(root->FunctionId);
            if (it != FuncMap.End())
            {
                ++it->Second.TimesCalled;
                it->Second.TotalTime += root->EndTime - root->BeginTime;
            }
            else
            {
                MovieFunctionStats::FuncStats funcStats;
                funcStats.FunctionId = root->FunctionId;
                funcStats.CallerId = 0;
                funcStats.TimesCalled = 1;
                funcStats.TotalTime = root->EndTime - root->BeginTime;
                FuncMap.Add(root->FunctionId, funcStats);
            }
        }
    }
    Hash<UInt64, MovieFunctionStats::FuncStats> FuncMap;
    bool IncludeActionScript;
};

// @0x142686440
template<> void FuncTreeItem::Visit<FunctionTreeVisitor>(FunctionTreeVisitor& visitor)
{
    visitor(this);
    for (UPInt i = 0; i < Children.GetSize(); ++i)
    {
        Children[i]->Visit(visitor);
    }
}
}}
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

    // The start corner is clamped into the second image (cmovle at 0x142675c5f / 0x142675c72).
    clipped[0] = static_cast<int>(left) > 0 ? left : 0;
    clipped[1] = static_cast<int>(top) > 0 ? top : 0;
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
    if (!object[7])
        return;
    using Cleanup = void (*)(void*);
    auto** vtable = *reinterpret_cast<void***>(object);
    reinterpret_cast<Cleanup>(vtable[3])(object);
    // The exe reloads the channel after the virtual call and between the two FMOD calls.
    FUN_1428d8efc(object[7], nullptr);
    FUN_1428d8f14(object[7], nullptr);
    object[7] = nullptr;
}

// MS2-FUNCTIONAL: clears the channel registration and unlinks this node from its intrusive list.
// @0x142746230
void DetachChannelNode(void* node)
{
    auto* bytes = static_cast<unsigned char*>(node);
    const int references = *reinterpret_cast<int*>(bytes - 8);
    void** channel = reinterpret_cast<void**>(bytes + 0x28);
    if (references > 0 && *channel) {
        auto** vtable = *reinterpret_cast<void***>(bytes - 0x10);
        reinterpret_cast<void (*)(void*)>(vtable[3])(bytes - 0x10);
        // The exe reloads the channel after the virtual call and between the two FMOD calls.
        FUN_1428d8efc(*channel, nullptr);
        FUN_1428d8f14(*channel, nullptr);
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
// @0x142687900
GFx::AMP::MovieInstructionStats& GFx::AMP::MovieInstructionStats::operator*=(unsigned num)
{
    for (UPInt i = 0; i < BufferStatsArray.GetSize(); ++i)
    {
        ArrayLH<InstructionTimePair>& times = BufferStatsArray[i]->InstructionTimesArray;
        for (UPInt j = 0; j < times.GetSize(); ++j)
            times[j].Time *= num;
    }
    return *this;
}

// Inlined into the MovieProfile operators; the exe has no out-of-line copy.
inline GFx::AMP::MovieFunctionStats& GFx::AMP::MovieFunctionStats::operator*=(unsigned num)
{
    for (UPInt i = 0; i < FunctionTimings.GetSize(); ++i)
    {
        FunctionTimings[i].TimesCalled *= num;
        FunctionTimings[i].TotalTime *= num;
    }
    return *this;
}

inline GFx::AMP::MovieSourceLineStats& GFx::AMP::MovieSourceLineStats::operator*=(unsigned num)
{
    for (UPInt i = 0; i < SourceLineTimings.GetSize(); ++i)
    {
        SourceLineTimings[i].TotalTime *= num;
    }
    return *this;
}

inline GFx::AMP::MovieSourceLineStats& GFx::AMP::MovieSourceLineStats::operator/=(unsigned numFrames)
{
    for (UPInt i = 0; i < SourceLineTimings.GetSize(); ++i)
    {
        SourceLineTimings[i].TotalTime /= numFrames;
    }
    return *this;
}

// @0x142687980
GFx::AMP::MovieProfile& GFx::AMP::MovieProfile::operator*=(unsigned num)
{
    *InstructionStats *= num;
    *FunctionStats *= num;
    *SourceLineStats *= num;
    return *this;
}

// @0x142688600
GFx::AMP::MovieProfile& GFx::AMP::MovieProfile::operator/=(unsigned numFrames)
{
    *InstructionStats /= numFrames;
    *FunctionStats /= numFrames;
    *SourceLineStats /= numFrames;
    return *this;
}

// @0x142687ae0
GFx::AMP::ProfileFrame& GFx::AMP::ProfileFrame::operator*=(unsigned num)
{
    TimeStamp *= num;
    FramesPerSecond *= num;
    AdvanceTime *= num;
    TimelineTime *= num;
    ActionTime *= num;
    InputTime *= num;
    MouseTime *= num;
    GetVariableTime *= num;
    SetVariableTime *= num;
    InvokeTime *= num;
    DisplayTime *= num;
    PresentTime *= num;
    TesselationTime *= num;
    GradientGenTime *= num;
    UserTime *= num;
    LineCount *= num;
    MaskCount *= num;
    FilterCount *= num;
    MeshCount *= num;
    TriangleCount *= num;
    DrawPrimitiveCount *= num;
    StrokeCount *= num;
    GradientFillCount *= num;
    MeshThrashing *= num;
    RasterizedGlyphCount *= num;
    FontTextureCount *= num;
    NumFontCacheTextureUpdates *= num;
    FontThrashing *= num;
    FontFill *= num;
    FontFail *= num;
    FontMisses *= num;
    FontTotalArea *= num;
    FontUsedArea *= num;
    TotalMemory *= num;
    ImageMemory *= num;
    ImageGraphicsMemory *= num;
    MovieDataMemory *= num;
    MovieViewMemory *= num;
    MeshCacheMemory *= num;
    MeshCacheGraphicsMemory *= num;
    MeshCacheUnusedMemory *= num;
    MeshCacheGraphicsUnusedMemory *= num;
    FontCacheMemory *= num;
    VideoMemory *= num;
    SoundMemory *= num;
    OtherMemory *= num;
    for (UPInt i = 0; i < MovieStats.GetSize(); ++i)
    {
        *MovieStats[i] *= num;
    }
    *DisplayStats *= num;
    *MemoryByStatId *= num;
    *Images *= num;
    *Fonts *= num;
    return *this;
}

// @0x142688520
GFx::AMP::MovieFunctionStats& GFx::AMP::MovieFunctionStats::operator/=(unsigned numFrames)
{
    for (UPInt i = 0; i < FunctionTimings.GetSize(); ++i)
    {
        FunctionTimings[i].TimesCalled /= numFrames;
        FunctionTimings[i].TotalTime /= numFrames;
    }
    return *this;
}

// @0x142688580
GFx::AMP::MovieInstructionStats& GFx::AMP::MovieInstructionStats::operator/=(unsigned numFrames)
{
    for (UPInt i = 0; i < BufferStatsArray.GetSize(); ++i)
    {
        ArrayLH<InstructionTimePair>& times = BufferStatsArray[i]->InstructionTimesArray;
        for (UPInt j = 0; j < times.GetSize(); ++j)
            times[j].Time /= numFrames;
    }
    return *this;
}
}

namespace Scaleform {
namespace GFx { namespace AMP {
// @0x14268a6d0
int ProfileFrame::GetNumFunctionTreeStats() const
{
    int numFunctionTreeStats = 0;
    for (UPInt i = 0; i < MovieStats.GetSize(); ++i)
    {
        MovieFunctionTreeStats* treeStats = MovieStats[i]->FunctionTreeStats;
        if (treeStats != NULL)
        {
            for (UPInt j = 0; j < treeStats->FunctionRoots.GetSize(); ++j)
            {
                numFunctionTreeStats += treeStats->FunctionRoots[j]->GetNumItems();
            }
        }
    }
    if (DisplayFunctionStats)
    {
        for (UPInt j = 0; j < DisplayFunctionStats->FunctionRoots.GetSize(); ++j)
        {
            numFunctionTreeStats += DisplayFunctionStats->FunctionRoots[j]->GetNumItems();
        }
    }
    return numFunctionTreeStats;
}
}}

namespace GFx { namespace AMP {
// @0x14268a810
int FuncTreeItem::GetNumItems()
{
    NumItemsVisitor visitor;
    Visit(visitor);
    return visitor.NumItems;
}
}}

static std::uint64_t HashImageKey(const unsigned char* key)
{
    return (((static_cast<std::uint64_t>(key[3]) * 0x1003full + key[2]) * 0x1003full + key[1]) * 0x1003full +
            static_cast<std::uint64_t>(key[4]) * 0xfc5d1543ec5f01ull +
            static_cast<std::uint64_t>(key[5]) * 0x9b302c28162c613full +
            static_cast<std::uint64_t>(key[7]) * 0xd7c3e496a311b1bfull +
            static_cast<std::uint64_t>(key[6]) * 0x5d02f409d62aee81ull -
            0x514d9afbc3e934fbull + key[0]);
}

// @0x142687eb0
GFx::AMP::ProfileFrame& GFx::AMP::ProfileFrame::operator+=(const ProfileFrame& rhs)
{
    TimeStamp += rhs.TimeStamp;
    FramesPerSecond += rhs.FramesPerSecond;
    AdvanceTime += rhs.AdvanceTime;
    TimelineTime += rhs.TimelineTime;
    ActionTime += rhs.ActionTime;
    InputTime += rhs.InputTime;
    MouseTime += rhs.MouseTime;
    GetVariableTime += rhs.GetVariableTime;
    SetVariableTime += rhs.SetVariableTime;
    InvokeTime += rhs.InvokeTime;
    DisplayTime += rhs.DisplayTime;
    PresentTime += rhs.PresentTime;
    TesselationTime += rhs.TesselationTime;
    GradientGenTime += rhs.GradientGenTime;
    UserTime += rhs.UserTime;
    LineCount += rhs.LineCount;
    MaskCount += rhs.MaskCount;
    FilterCount += rhs.FilterCount;
    MeshCount += rhs.MeshCount;
    TriangleCount += rhs.TriangleCount;
    DrawPrimitiveCount += rhs.DrawPrimitiveCount;
    StrokeCount += rhs.StrokeCount;
    GradientFillCount += rhs.GradientFillCount;
    MeshThrashing += rhs.MeshThrashing;
    RasterizedGlyphCount += rhs.RasterizedGlyphCount;
    FontTextureCount += rhs.FontTextureCount;
    NumFontCacheTextureUpdates += rhs.NumFontCacheTextureUpdates;
    FontThrashing += rhs.FontThrashing;
    FontFill += rhs.FontFill;
    FontFail += rhs.FontFail;
    FontMisses += rhs.FontMisses;
    FontTotalArea += rhs.FontTotalArea;
    FontUsedArea += rhs.FontUsedArea;
    TotalMemory += rhs.TotalMemory;
    ImageMemory += rhs.ImageMemory;
    ImageGraphicsMemory += rhs.ImageGraphicsMemory;
    MovieDataMemory += rhs.MovieDataMemory;
    MovieViewMemory += rhs.MovieViewMemory;
    MeshCacheMemory += rhs.MeshCacheMemory;
    MeshCacheGraphicsMemory += rhs.MeshCacheGraphicsMemory;
    MeshCacheUnusedMemory += rhs.MeshCacheUnusedMemory;
    MeshCacheGraphicsUnusedMemory += rhs.MeshCacheGraphicsUnusedMemory;
    FontCacheMemory += rhs.FontCacheMemory;
    VideoMemory += rhs.VideoMemory;
    SoundMemory += rhs.SoundMemory;
    OtherMemory += rhs.OtherMemory;

    for (UPInt i = 0; i < rhs.MovieStats.GetSize(); ++i)
    {
        bool found = false;
        for (UPInt j = 0; j < MovieStats.GetSize(); ++j)
        {
            if (MovieStats[j]->ViewHandle == rhs.MovieStats[i]->ViewHandle)
            {
                MovieStats[j]->Merge(*rhs.MovieStats[i]);
                found = true;
                break;
            }
        }
        
        if (!found)
        {
            MovieProfile* newStats = SF_HEAP_AUTO_NEW(this) MovieProfile();
            *newStats = *rhs.MovieStats[i];
            MovieStats.PushBack(*newStats);
        }
    }
    DisplayStats->Merge(*rhs.DisplayStats);
    DisplayFunctionStats->Merge(*rhs.DisplayFunctionStats);

    for (UPInt i = 0; i < rhs.SwdHandles.GetSize(); ++i)
    {
        bool found = false;
        for (UPInt j = 0; j < SwdHandles.GetSize(); ++j)
        {
            if (SwdHandles[j] == rhs.SwdHandles[i])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            SwdHandles.PushBack(rhs.SwdHandles[i]);
        }
    }

    for (UPInt i = 0; i < rhs.FileHandles.GetSize(); ++i)
    {
        bool found = false;
        for (UPInt j = 0; j < FileHandles.GetSize(); ++j)
        {
            if (FileHandles[j] == rhs.FileHandles[i])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            FileHandles.PushBack(rhs.FileHandles[i]);
        }
    }

    MemoryByStatId->Merge(*rhs.MemoryByStatId);
    Images->Merge(*rhs.Images);
    Fonts->Merge(*rhs.Fonts);

    for (UPInt i = 0; i < rhs.ImageList.GetSize(); ++i)
    {
        bool found = false;
        for (UPInt j = 0; j < ImageList.GetSize(); ++j)
        {
            if (ImageList[j]->Id == rhs.ImageList[i]->Id)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            ImageList.PushBack(rhs.ImageList[i]);
        }
    }

    return *this;
}


// MS2-FUNCTIONAL: resolves both cached labels and formats every timing record into the executable's temporary String sink.
// @0x14268a040
void FUN_14268a040(void* source)
{
    auto* bytes = static_cast<unsigned char*>(source);
    const std::size_t count = *reinterpret_cast<std::size_t*>(bytes + 0x18);
    const auto* records = *reinterpret_cast<const unsigned char**>(bytes + 0x10);
    auto* table = *reinterpret_cast<unsigned char**>(bytes + 0x28);
    for (std::size_t i = 0; i < count; ++i) {
        const auto* record = records + i * 0x20;
        Scaleform::String first, second, output;
        if (table) {
            const std::uint64_t mask = *reinterpret_cast<std::uint64_t*>(table + 8);
            for (unsigned keyIndex = 0; keyIndex != 2; ++keyIndex) {
                const auto* key = record + keyIndex * 8;
                const std::uint64_t value = *reinterpret_cast<const std::uint64_t*>(key);
                const std::uint64_t bucket = HashImageKey(key) & mask;
                auto* row = reinterpret_cast<std::uint64_t*>(table + 0x10 + bucket * 0x20);
                if (static_cast<std::int64_t>(row[0]) == -2 || row[1] != bucket)
                    continue;
                for (;;) {
                    if (row[1] == bucket && row[2] == value) {
                        (keyIndex ? second : first) = *reinterpret_cast<const Scaleform::String*>(row + 3);
                        break;
                    }
                    if (row[0] == UINT64_MAX)
                        break;
                    row = reinterpret_cast<std::uint64_t*>(table + 0x10 + row[0] * 0x20);
                }
            }
        }
        Scaleform::MsgFormat format{Scaleform::MsgFormat::Sink(output)};
        format.Parse("{0} ({1}) from {2} ({3}): {4} times\n");
        format.FormatD1(first.ToCStr());
        // The two keys are formatted as numbers (0x14268a341/0x14268a35e call FormatD1<UInt64> 0x142685ff0).
        format.FormatD1(*reinterpret_cast<const Scaleform::UInt64*>(record));
        format.FormatD1(second.ToCStr());
        format.FormatD1(*reinterpret_cast<const Scaleform::UInt64*>(record + 8));
        format.FormatD1(*reinterpret_cast<const unsigned long*>(record + 0x10));
        format.FinishFormatD();
    }
}



// The following stream and movie record helpers remain in the same Scaleform namespace.
// @0x14268c190
void GFx::AMP::FuncTreeItem::Read(File& str, UInt32 version)
{
    FunctionId = ReadUInt64(str);
    BeginTime = ReadUInt64(str);
    EndTime = ReadUInt64(str);
    TreeItemId = str.ReadUInt32();
    Children.Resize(str.ReadUInt32());
    for (UPInt i = 0; i < Children.GetSize(); ++i)
    {
        Children[i] = *SF_HEAP_AUTO_NEW(this) FuncTreeItem();
        Children[i]->Read(str, version);
    }
}

// @0x14268c370
void GFx::AMP::ImageInfo::Read(File& str, UInt32 version)
{
    Id = str.ReadUInt32();
    readString(str, &Name);
    if (version < 29)
    {
        String dummy;
        readString(str, &dummy);
    }
    Bytes = str.ReadUInt32();
    External = (ReadUByte(str) != 0);
    AtlasId = str.ReadUInt32();
    AtlasTop = str.ReadUInt32();
    AtlasBottom = str.ReadUInt32();
    AtlasLeft = str.ReadUInt32();
    AtlasRight = str.ReadUInt32();
}

// @0x14268e140
void GFx::AMP::ServerState::Read(File& str, UInt32 version)
{
    StateFlags = str.ReadUInt32();
    if (version >= 20)
    {
        ProfileLevel = static_cast<SInt32>(str.ReadUInt32());
    }
    readString(str, &ConnectedApp);
    if (version >= 5)
    {
        readString(str, &ConnectedFile);
    }
    readString(str, &AaMode);
    readString(str, &StrokeType);
    readString(str, &CurrentLocale);
    UInt32 size = str.ReadUInt32();
    Locales.Resize(size);
    for (UInt32 i = 0; i < size; ++i)
    {
        readString(str, &Locales[i]);
    }
    CurveTolerance = ReadFloat(str);
    CurveToleranceMin = ReadFloat(str);
    CurveToleranceMax = ReadFloat(str);
    CurveToleranceStep = ReadFloat(str);
    if (version >= 10)
    {
        CurrentFileId = ReadUInt64(str);
        CurrentLineNumber = str.ReadUInt32();
    }
}



static void ResizeRawArray(void**, void*, std::size_t, std::size_t);
void FUN_14257dc30(void*);
// @0x14268aff0
void GFx::AMP::MovieInstructionStats::Merge(const MovieInstructionStats& other)
{
    for (UPInt i = 0; i < other.BufferStatsArray.GetSize(); ++i)
    {
        bool buffersMerged = false;
        for (UPInt j = 0; j < BufferStatsArray.GetSize(); ++j)
        {
            if (BufferStatsArray[j]->SwdHandle == other.BufferStatsArray[i]->SwdHandle
                && BufferStatsArray[j]->BufferOffset == other.BufferStatsArray[i]->BufferOffset)
            {
                SF_ASSERT(BufferStatsArray[j]->BufferLength == other.BufferStatsArray[i]->BufferLength);
                ArrayLH<InstructionTimePair>& thisArray = BufferStatsArray[j]->InstructionTimesArray;
                const ArrayLH<InstructionTimePair>& otherArray = BufferStatsArray[i]->InstructionTimesArray;
                for (UPInt k = 0; k < otherArray.GetSize(); ++k)
                {
                    bool instructionsMerged = false;
                    for (UPInt l = 0; l < thisArray.GetSize(); ++l)
                    {
                        if (thisArray[l].Offset == otherArray[k].Offset)
                        {
                            thisArray[l].Time += otherArray[k].Time;
                            instructionsMerged = true;
                            break;
                        }
                    }

                    if (!instructionsMerged)
                    {
                        thisArray.PushBack(otherArray[k]);
                    }
                }
                buffersMerged = true;
                break;
            }
        }

        if (!buffersMerged)
        {
            ScriptBufferStats* newBufferStats = SF_HEAP_AUTO_NEW(this) ScriptBufferStats();
            *newBufferStats = *other.BufferStatsArray[i];
            BufferStatsArray.PushBack(*newBufferStats);
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



// @0x14268b3e0
void GFx::AMP::MovieSourceLineStats::Merge(const MovieSourceLineStats& other)
{
    for (UPInt i = 0; i < other.SourceLineTimings.GetSize(); ++i)
    {
        bool merged = false;
        for (UPInt j = 0; j < SourceLineTimings.GetSize(); ++j)
        {
            if (SourceLineTimings[j].FileId == other.SourceLineTimings[i].FileId
                && SourceLineTimings[j].LineNumber == other.SourceLineTimings[i].LineNumber)
            {
                SourceLineTimings[j].TotalTime += other.SourceLineTimings[i].TotalTime;
                merged = true;
                break;
            }
        }
        if (!merged)
        {
            SourceLineTimings.PushBack(other.SourceLineTimings[i]);
        }
    }

    SourceFileDescMap::ConstIterator it;
    for (it = other.SourceFileInfo.Begin(); it != other.SourceFileInfo.End(); ++it)
    {
        SourceFileInfo.Set(it->First, it->Second);
    }
}

// @0x14268b280
void GFx::AMP::MovieProfile::Merge(const MovieProfile& rhs)
{
    SF_ASSERT(ViewHandle == rhs.ViewHandle);
    SF_ASSERT(ViewName == rhs.ViewName);
    MinFrame = Alg::Min(MinFrame, rhs.MinFrame);
    MaxFrame = Alg::Max(MaxFrame, rhs.MaxFrame);

    for (UPInt i = 0; i < rhs.Markers.GetSize(); ++i)
    {
        bool found = false;
        for (UPInt j = 0; j < Markers.GetSize(); ++j)
        {
            if (rhs.Markers[i]->Name == Markers[j]->Name)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            Markers.PushBack(Markers[i]);
        }
    }

    InstructionStats->Merge(*rhs.InstructionStats);
    FunctionStats->Merge(*rhs.FunctionStats);
    SourceLineStats->Merge(*rhs.SourceLineStats);
    FunctionTreeStats->Merge(*rhs.FunctionTreeStats);
}

// @0x14268a870
const GFx::AMP::FuncTreeItem* GFx::AMP::FuncTreeItem::GetTreeItem(UInt32 treeItemId) const
{
    if (treeItemId == TreeItemId)
    {
        return this;
    }
    for (UPInt i = 0; i < Children.GetSize(); ++i)
    {
        const FuncTreeItem* childItem = Children[i]->GetTreeItem(treeItemId);
        if (childItem != NULL)
        {
            return childItem;
        }
    }
    return NULL;
}

// @0x14268ac40
void GFx::AMP::MovieFunctionTreeStats::Merge(const MovieFunctionTreeStats& other)
{
    FunctionRoots.Append(other.FunctionRoots);
    for (UPInt i = 1; i < FunctionRoots.GetSize(); ++i)
    {
        FunctionRoots[i]->ResetTreeIds(FunctionRoots[i - 1]);
    }

    FunctionDescMap::ConstIterator it;
    for (it = other.FunctionInfo.Begin(); it != other.FunctionInfo.End(); ++it)
    {
        FunctionInfo.Set(it->First, it->Second);
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
    std::memcpy(payload.color, ImageViewportColor, sizeof(payload.color));
    payload.transform[0] = 0.0f;
    payload.transform[1] = scaled;
    payload.transform[2] = 0.0f;
    payload.transform[3] = ImageViewportOrigin - scaled * ImageViewportScale;
    reinterpret_cast<void (*)(void*, void*, const DrawPayload*, void*)>(vtable[0x188 / sizeof(void*)])(
        context, *image, &payload, static_cast<unsigned char*>(state) + 0x20);
    // applyBlendModeImpl(mode, sourceAc = true, forceAc = true)
    reinterpret_cast<void (*)(void*, unsigned, bool, bool)>(vtable[0x118 / sizeof(void*)])(
        context, static_cast<unsigned>(*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(
            *reinterpret_cast<void**>(static_cast<unsigned char*>(command) + 8)) + 0x48) != 0) + 0x0f, true, true);
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

// MS2-FUNCTIONAL: FMOD userseek callback (exinfo +0x90): seeks the stream to pos, error value 20 on failure.
// @0x142745490
unsigned long long ValidateAudioStream(void*, void* position, void* stream)
{
    // The second argument is FMOD's unsigned seek position; the exe passes it through in edx.
    const int pos = static_cast<int>(reinterpret_cast<std::uintptr_t>(position));
    return FUN_1427483a0(stream, pos) == 0 ? 20 : 0;
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
        channels = ((format & 8) != 0) + 1;     // Sample_Stereo
        soundFormat = ((format & 7) == 2) + 1;  // Sample_16: FMOD PCM16, else PCM8
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
        channels = ((format & 8) != 0) + 1;     // Sample_Stereo
        soundFormat = ((format & 7) == 2) + 1;  // Sample_16: FMOD PCM16, else PCM8
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
        channels = ((format & 8) != 0) + 1;     // Sample_Stereo
    } else if ((format & 0x700) != 0x200) {
        return static_cast<FMOD_RESULT>(0x19);
    }

    unsigned char info[0xd8] = {};
    *reinterpret_cast<unsigned*>(info) = sizeof(info);
    *reinterpret_cast<unsigned*>(info + 0x0c) = channels;
    *reinterpret_cast<unsigned*>(info + 0x10) = *reinterpret_cast<const unsigned*>(path + 0x14);
    *reinterpret_cast<unsigned*>(info + 0x14) = (format & 0x700) == 0x200 ? 0xbu : (((format & 7) == 2) + 1);
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


// MS2-FUNCTIONAL: rounds pointer capacity to four slots and uses the global heap's allocate, reallocate, and free paths.
// @0x142678170
void ReserveGlobalPointerArray(void** array, void*, std::size_t requested)
{
    ReserveHeapArray(array, nullptr, requested, 8, false);
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


}

void FUN_14257dcb0(void* object);
void FUN_14257dc30(void* object);
unsigned long long FUN_1425e3480();
int FUN_1428d8ed8(void*, bool);

namespace Scaleform {


}

namespace Scaleform {

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
            if (InterlockedDecrement(references) == 0) {
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

// Initializes an empty hash table at eight slots and doubles it when live entries exceed its 80 percent load threshold.
// @0x142689ec0
void CheckExpandAS3HashSet(void** set, void* owner)
{
    auto* table = static_cast<std::size_t*>(*set);
    if (!table) {
        FUN_1426906b0(set, owner, 8);
        return;
    }
    if (table[0] * 5 > table[1] * 4 + 4)
        FUN_1426906b0(set, owner, table[1] * 2 + 2);
}

// Applies the same empty-table initialization and 80 percent expansion test to this hash layout.
// @0x142744560
void CheckExpandAS3PointerSet(void** set, void* owner)
{
    auto* table = static_cast<std::size_t*>(*set);
    if (!table) {
        FUN_142747530(set, owner, 8);
        return;
    }
    if (table[0] * 5 > table[1] * 4 + 4)
        FUN_142747530(set, owner, table[1] * 2 + 2);
}

// Applies the same empty-table initialization and 80 percent expansion test to this hash layout.
// @0x1427445b0
void CheckExpandAS3CachedSet(void** set, void* owner)
{
    auto* table = static_cast<std::size_t*>(*set);
    if (!table) {
        FUN_1427478c0(set, owner, 8);
        return;
    }
    if (table[0] * 5 > table[1] * 4 + 4)
        FUN_1427478c0(set, owner, table[1] * 2 + 2);
}



static void WriteImageStream(void* stream, const void* data, unsigned size)
{
    auto** streamVtable = *reinterpret_cast<void***>(stream);
    reinterpret_cast<void (*)(void*, const void*, unsigned)>(streamVtable[9])(stream, data, size);
}


// @0x14268f4b0
void GFx::AMP::MovieInstructionStats::Write(File& str, UInt32 version) const
{
    WriteUInt32(str, static_cast<UInt32>(BufferStatsArray.GetSize()));
    for (UPInt i = 0; i < BufferStatsArray.GetSize(); ++i)
    {
        BufferStatsArray[i]->Write(str, version);
    }
}

// @0x14268f600
void GFx::AMP::MovieProfile::Write(File& str, UInt32 version) const
{
    WriteUInt32(str, ViewHandle);
    WriteUInt32(str, MinFrame);
    WriteUInt32(str, MaxFrame);
    if (version >= 4)
    {
        writeString(str, ViewName);
        WriteUInt32(str, Version);
        WriteFloat(str, Width);
        WriteFloat(str, Height);
        WriteFloat(str, FrameRate);
        WriteUInt32(str, FrameCount);
    }
    if (version >= 6)
    {
        WriteUInt32(str, static_cast<UInt32>(Markers.GetSize()));
        for (UPInt i = 0; i < Markers.GetSize(); ++i)
        {
            if (version >= 11)
            {
                writeString(str, Markers[i]->Name);
            }
            WriteUInt32(str, Markers[i]->Number);
        }
    }
    SF_ASSERT(InstructionStats);
    InstructionStats->Write(str, version);
    SF_ASSERT(FunctionStats);
    FunctionStats->Write(str, version);
    SF_ASSERT(SourceLineStats);
    SourceLineStats->Write(str, version);
    if (version >= 25)
    {
        SF_ASSERT(FunctionTreeStats);
        FunctionTreeStats->Write(str, version);
    }
}

// @0x14268f8f0
void GFx::AMP::MovieSourceLineStats::Write(File& str, UInt32 version) const
{
    if (version >= 9)
    {
        WriteUInt32(str, static_cast<UInt32>(SourceLineTimings.GetSize()));
        for (UPInt i = 0; i < SourceLineTimings.GetSize(); ++i)
        {
            WriteUInt64(str, SourceLineTimings[i].FileId);
            WriteUInt32(str, SourceLineTimings[i].LineNumber);
            WriteUInt64(str, SourceLineTimings[i].TotalTime);
        }

        WriteUInt32(str, static_cast<UInt32>(SourceFileInfo.GetSize()));
        SourceFileDescMap::ConstIterator descIt;
        for (descIt = SourceFileInfo.Begin(); descIt != SourceFileInfo.End(); ++descIt)
        {
            WriteUInt64(str, descIt->First);
            writeString(str, descIt->Second);
        }
    }
}

// @0x14268f230
void GFx::AMP::MovieFunctionTreeStats::Write(File& str, UInt32 version) const
{
    SF_UNUSED(version);

    writeString(str, ViewName);

    WriteUInt32(str, static_cast<UInt32>(FunctionRoots.GetSize()));
    for (UPInt i = 0; i < FunctionRoots.GetSize(); ++i)
    {
        FunctionRoots[i]->Write(str, version);
    }

    WriteUInt32(str, static_cast<UInt32>(FunctionInfo.GetSize()));
    FunctionDescMap::ConstIterator descIt;
    for (descIt = FunctionInfo.Begin(); descIt != FunctionInfo.End(); ++descIt)
    {
        WriteUInt64(str, descIt->First);
        writeString(str, descIt->Second->Name);
        WriteUInt32(str, descIt->Second->Length);
        WriteUInt64(str, descIt->Second->FileId);
        WriteUInt32(str, descIt->Second->FileLine);
        WriteUInt32(str, descIt->Second->ASVersion);
    }
}

static void WriteAs3RecordBytes(void* stream, const void* data, std::size_t size)
{
    auto** streamVtable = *reinterpret_cast<void***>(stream);
    reinterpret_cast<void (*)(void*, const void*, std::size_t)>(streamVtable[9])(stream, data, size);
}

// @0x14268ef30
void GFx::AMP::MovieFunctionStats::Write(File& str, UInt32 version) const
{
    SF_UNUSED(version);
    WriteUInt32(str, static_cast<UInt32>(FunctionTimings.GetSize()));
    for (UPInt i = 0; i < FunctionTimings.GetSize(); ++i)
    {
        WriteUInt64(str, FunctionTimings[i].FunctionId);
        WriteUInt64(str, FunctionTimings[i].CallerId);
        WriteUInt32(str, FunctionTimings[i].TimesCalled);
        WriteUInt64(str, FunctionTimings[i].TotalTime);
    }

    WriteUInt32(str, static_cast<UInt32>(FunctionInfo.GetSize()));
    for (FunctionDescMap::ConstIterator descIt = FunctionInfo.Begin(); descIt != FunctionInfo.End(); ++descIt)
    {
        WriteUInt64(str, descIt->First);
        writeString(str, descIt->Second->Name);
        WriteUInt32(str, descIt->Second->Length);
        if (version >= 9)
        {
            WriteUInt64(str, descIt->Second->FileId);
            WriteUInt32(str, descIt->Second->FileLine);
            if (version >= 13)
            {
                WriteUInt32(str, descIt->Second->ASVersion);
            }
        }
    }
}

// @0x142690630
void GFx::AMP::readString(File& file, String* str)
{
    UInt32 stringLength = file.ReadUInt32();
    for (UInt32 i = 0; i < stringLength; ++i)
    {
        str->AppendChar(GFx::AMP::ReadSByte(file));
    }
}

// @0x142690c70
void GFx::AMP::writeString(File& file, const String& str)
{
    GFx::AMP::WriteUInt32(file, static_cast<UInt32>(str.GetLength()));
    for (UPInt i = 0; i < str.GetLength(); ++i)
    {
        GFx::AMP::WriteSByte(file, str.ToCStr()[i]);
    }
}

// @0x14268fb40
void GFx::AMP::ProfileFrame::Write(File& str, UInt32 version) const
{
    WriteUInt64(str, TimeStamp);
    WriteUInt32(str, FramesPerSecond);
    WriteUInt32(str, AdvanceTime);
    WriteUInt32(str, TimelineTime);
    WriteUInt32(str, ActionTime);
    if (version < 21)
    {
        WriteUInt32(str, 0);
    }
    WriteUInt32(str, InputTime);
    WriteUInt32(str, MouseTime);
    WriteUInt32(str, GetVariableTime);
    WriteUInt32(str, SetVariableTime);
    WriteUInt32(str, InvokeTime);
    WriteUInt32(str, DisplayTime);
    if (version >= 30)
    {
        WriteUInt32(str, PresentTime);
    }
    WriteUInt32(str, TesselationTime);
    WriteUInt32(str, GradientGenTime);
    WriteUInt32(str, UserTime);
    WriteUInt32(str, LineCount);
    WriteUInt32(str, MaskCount);
    WriteUInt32(str, FilterCount);
    if (version >= 16)
    {
        WriteUInt32(str, MeshCount);
    }
    WriteUInt32(str, TriangleCount);
    WriteUInt32(str, DrawPrimitiveCount);
    WriteUInt32(str, StrokeCount);
    WriteUInt32(str, GradientFillCount);
    WriteUInt32(str, MeshThrashing);
    WriteUInt32(str, RasterizedGlyphCount);
    WriteUInt32(str, FontTextureCount);
    WriteUInt32(str, NumFontCacheTextureUpdates);
    if (version >= 14)
    {
        WriteUInt32(str, FontThrashing);
        WriteUInt32(str, FontFill);
        WriteUInt32(str, FontFail);
        if (version >= 24)
        {
            WriteUInt32(str, FontMisses);
        }
        if (version >= 27)
        {
            WriteUInt32(str, FontTotalArea);
            WriteUInt32(str, FontUsedArea);
        }
    }
    WriteUInt32(str, TotalMemory);
    WriteUInt32(str, ImageMemory);
    if (version >= 29)
    {
        WriteUInt32(str, ImageGraphicsMemory);
    }
    WriteUInt32(str, MovieDataMemory);
    WriteUInt32(str, MovieViewMemory);
    WriteUInt32(str, MeshCacheMemory);
    if (version >= 28)
    {
        WriteUInt32(str, MeshCacheGraphicsMemory);
        WriteUInt32(str, MeshCacheUnusedMemory);
        WriteUInt32(str, MeshCacheGraphicsUnusedMemory);
    }
    WriteUInt32(str, FontCacheMemory);
    WriteUInt32(str, VideoMemory);
    WriteUInt32(str, SoundMemory);
    WriteUInt32(str, OtherMemory);

    WriteUInt32(str, static_cast<UInt32>(MovieStats.GetSize()));
    for (UPInt i = 0; i < MovieStats.GetSize(); ++i)
    {
        MovieStats[i]->Write(str, version);
    }
    if (version >= 15)
    {
        DisplayStats->Write(str, version);
    }
    if (version >= 25)
    {
        DisplayFunctionStats->Write(str, version);
    }
    WriteUInt32(str, static_cast<UInt32>(SwdHandles.GetSize()));
    for (UPInt i = 0; i < SwdHandles.GetSize(); ++i)
    {
        WriteUInt32(str, SwdHandles[i]);
    }
    if (version >= 9)
    {
        WriteUInt32(str, static_cast<UInt32>(FileHandles.GetSize()));
        for (UPInt i = 0; i < FileHandles.GetSize(); ++i)
        {
            WriteUInt64(str, FileHandles[i]);
        }
    }
    MemoryByStatId->Write(str, version);
    if (version <= 18)
    {
        Ptr<MemItem> tmp = *SF_HEAP_AUTO_NEW(this) MemItem(0);
        tmp->Write(str, version);
    }
    if (version >= 3)
    {
        Images->Write(str, version);
    }
    if (version >= 7)
    {
        Fonts->Write(str, version);
    }
    if (version >= 17)
    {
        WriteUInt32(str, static_cast<UInt32>(ImageList.GetSize()));
        for (UInt32 i = 0; i < ImageList.GetSize(); ++i)
        {
            ImageList[i]->Write(str, version);
        }
    }

    if (version < 8)
    {
        WriteUInt32(str, 0);
        WriteUInt32(str, 0);
    }
}

// @0x142690380
void GFx::AMP::MovieInstructionStats::ScriptBufferStats::Write(File& str, UInt32 version) const
{
    SF_UNUSED(version);
    WriteUInt32(str, SwdHandle);
    WriteUInt32(str, BufferOffset);
    WriteUInt32(str, BufferLength);
    WriteUInt32(str, static_cast<UInt32>(InstructionTimesArray.GetSize()));
    for (UPInt i = 0; i < InstructionTimesArray.GetSize(); ++i)
    {
        WriteUInt32(str, InstructionTimesArray[i].Offset);
        WriteUInt64(str, InstructionTimesArray[i].Time);
    }
}

// @0x142690480
void GFx::AMP::ServerState::Write(File& str, UInt32 version) const
{
    WriteUInt32(str, StateFlags);
    if (version >= 20)
    {
        WriteUInt32(str, static_cast<UInt32>(ProfileLevel));
    }
    writeString(str, ConnectedApp);
    if (version >= 5)
    {
        writeString(str, ConnectedFile);
    }
    writeString(str, AaMode);
    writeString(str, StrokeType);
    writeString(str, CurrentLocale);
    WriteUInt32(str, static_cast<UInt32>(Locales.GetSize()));
    for (UPInt i = 0; i < Locales.GetSize(); ++i)
    {
        writeString(str, Locales[i]);
    }
    WriteFloat(str, CurveTolerance);
    WriteFloat(str, CurveToleranceMin);
    WriteFloat(str, CurveToleranceMax);
    WriteFloat(str, CurveToleranceStep);
    if (version >= 10)
    {
        WriteUInt64(str, CurrentFileId);
        WriteUInt32(str, CurrentLineNumber);
    }
}

static void ReadStreamBytes(void* stream, void* data, std::size_t size)
{
    auto** vtable = *reinterpret_cast<void***>(stream);
    reinterpret_cast<void (*)(void*, void*, std::size_t)>(vtable[10])(stream, data, size);
}

// @0x14268e010
void GFx::AMP::MovieInstructionStats::ScriptBufferStats::Read(File& str, UInt32 version)
{
    SF_UNUSED(version);
    SwdHandle = str.ReadUInt32();
    BufferOffset = str.ReadUInt32();
    BufferLength = str.ReadUInt32();
    UInt32 iSize = str.ReadUInt32();
    InstructionTimesArray.Resize(iSize);
    for (UPInt i = 0; i < InstructionTimesArray.GetSize(); ++i)
    {
        InstructionTimesArray[i].Offset = str.ReadUInt32();
        InstructionTimesArray[i].Time = ReadUInt64(str);
    }
}

// @0x14268eca0
void GFx::AMP::FuncTreeItem::Write(File& str, UInt32 version) const
{
    WriteUInt64(str, FunctionId);
    WriteUInt64(str, BeginTime);
    WriteUInt64(str, EndTime);
    WriteUInt32(str, TreeItemId);
    WriteUInt32(str, static_cast<UInt32>(Children.GetSize()));
    for (UPInt i = 0; i < Children.GetSize(); ++i)
    {
        Children[i]->Write(str, version);
    }
}

static void ReadAs3StreamBytes(void* stream, void* output, std::size_t size)
{
    auto** vtable = *reinterpret_cast<void***>(stream);
    reinterpret_cast<void (*)(void*, void*, std::size_t)>(vtable[10])(stream, output, size);
}

// @0x14268cd80
void GFx::AMP::MovieInstructionStats::Read(File& str, UInt32 version)
{
    UInt32 iSize = str.ReadUInt32();
    BufferStatsArray.Resize(iSize);
    for (UPInt i = 0; i < BufferStatsArray.GetSize(); ++i)
    {
        BufferStatsArray[i] = *SF_HEAP_AUTO_NEW(this) ScriptBufferStats();
        BufferStatsArray[i]->Read(str, version);
    }
}

// @0x142686ae0
GFx::AMP::MovieProfile::MovieProfile() :
    ViewHandle(0),
    MinFrame(0),
    MaxFrame(0)
{
    InstructionStats = *SF_HEAP_AUTO_NEW(this) MovieInstructionStats();
    FunctionStats = *SF_HEAP_AUTO_NEW(this) MovieFunctionStats();
    SourceLineStats = *SF_HEAP_AUTO_NEW(this) MovieSourceLineStats();
    FunctionTreeStats = *SF_HEAP_AUTO_NEW(this) MovieFunctionTreeStats();
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

// @0x142686d30
GFx::AMP::ProfileFrame::ProfileFrame() :
    TimeStamp(0),
    FramesPerSecond(0),
    AdvanceTime(0),
    ActionTime(0),
    TimelineTime(0),
    InputTime(0),
    MouseTime(0),
    GetVariableTime(0),
    SetVariableTime(0),
    InvokeTime(0),
    DisplayTime(0),
    PresentTime(0),
    TesselationTime(0),
    GradientGenTime(0),
    UserTime(0),
    LineCount(0),
    MaskCount(0),
    FilterCount(0),
    MeshCount(0),
    TriangleCount(0),
    DrawPrimitiveCount(0),
    StrokeCount(0),
    GradientFillCount(0),
    MeshThrashing(0),
    RasterizedGlyphCount(0),
    FontTextureCount(0),
    NumFontCacheTextureUpdates(0),
    FontThrashing(0),
    FontFill(0),
    FontFail(0),
    FontMisses(0),
    FontTotalArea(0),
    FontUsedArea(0),
    TotalMemory(0),
    ImageMemory(0),
    ImageGraphicsMemory(0),
    MovieDataMemory(0),
    MovieViewMemory(0),
    MeshCacheMemory(0),
    MeshCacheGraphicsMemory(0),
    MeshCacheUnusedMemory(0),
    MeshCacheGraphicsUnusedMemory(0),
    FontCacheMemory(0),
    VideoMemory(0),
    SoundMemory(0),
    OtherMemory(0)
{
    MemoryByStatId = *SF_HEAP_AUTO_NEW(this) MemItem(0);
    Images = *SF_HEAP_AUTO_NEW(this) MemItem(0);
    Fonts = *SF_HEAP_AUTO_NEW(this) MemItem(0);
    DisplayStats = *SF_HEAP_AUTO_NEW(this) MovieFunctionStats();
    DisplayFunctionStats = *SF_HEAP_AUTO_NEW(this) MovieFunctionTreeStats();
}

// @0x14268c930
void GFx::AMP::MovieFunctionTreeStats::Read(File& str, UInt32 version)
{
    SF_UNUSED(version);

    readString(str, &ViewName);

    FunctionRoots.Resize(str.ReadUInt32());
    for (UInt32 i = 0; i < FunctionRoots.GetSize(); ++i)
    {
        FunctionRoots[i] = *SF_HEAP_AUTO_NEW(this) FuncTreeItem();
        FunctionRoots[i]->Read(str, version);
    }

    UInt32 size = str.ReadUInt32();
    for (UInt32 i = 0; i < size; i++)
    {
        UInt64 iKey = ReadUInt64(str);
        Ptr<FunctionDesc> pDesc = *SF_HEAP_AUTO_NEW(this) FunctionDesc();
        readString(str, &pDesc->Name);
        pDesc->Length = str.ReadUInt32();
        pDesc->FileId = ReadUInt64(str);
        pDesc->FileLine = str.ReadUInt32();
        pDesc->ASVersion = str.ReadUInt32();
        FunctionInfo.Set(iKey, pDesc);
    }
}

// @0x14268c510
void GFx::AMP::MovieFunctionStats::Read(File& str, UInt32 version)
{
    SF_UNUSED(version);
    UInt32 size = str.ReadUInt32();
    FunctionTimings.Resize(size);
    for (UInt32 i = 0; i < size; i++)
    {
        FunctionTimings[i].FunctionId = ReadUInt64(str);
        FunctionTimings[i].CallerId = ReadUInt64(str);
        FunctionTimings[i].TimesCalled = str.ReadUInt32();
        FunctionTimings[i].TotalTime = ReadUInt64(str);
    }

    size = str.ReadUInt32();
    for (UInt32 i = 0; i < size; i++)
    {
        UInt64 iKey = ReadUInt64(str);
        Ptr<FunctionDesc> pDesc = *SF_HEAP_AUTO_NEW(this) FunctionDesc();
        readString(str, &pDesc->Name);
        pDesc->Length = str.ReadUInt32();
        if (version >= 9)
        {
            pDesc->FileId = ReadUInt64(str);
            pDesc->FileLine = str.ReadUInt32();
            if (version >= 13)
            {
                pDesc->ASVersion = str.ReadUInt32();
            }
        }
        FunctionInfo.Set(iKey, pDesc);
    }
}

// @0x14268d2b0
void GFx::AMP::MovieSourceLineStats::Read(File& str, UInt32 version)
{
    if (version >= 9)
    {
        UInt32 size = str.ReadUInt32();
        SourceLineTimings.Resize(size);
        for (UInt32 i = 0; i < size; i++)
        {
            SourceLineTimings[i].FileId = ReadUInt64(str);
            SourceLineTimings[i].LineNumber = str.ReadUInt32();
            SourceLineTimings[i].TotalTime = ReadUInt64(str);
        }

        size = str.ReadUInt32();
        for (UInt32 i = 0; i < size; i++)
        {
            UInt64 iKey = ReadUInt64(str);
            String desc;
            readString(str, &desc);
            SourceFileInfo.Set(iKey, desc);
        }
    }
}

// @0x14268d5c0
void GFx::AMP::ProfileFrame::Read(File& str, UInt32 version)
{
    TimeStamp = ReadUInt64(str);
    FramesPerSecond = str.ReadUInt32();
    AdvanceTime = str.ReadUInt32();
    TimelineTime = str.ReadUInt32();
    ActionTime = str.ReadUInt32();
    if (version < 21)
    {
        str.ReadUInt32();
    }
    InputTime = str.ReadUInt32();
    MouseTime = str.ReadUInt32();
    GetVariableTime = str.ReadUInt32();
    SetVariableTime = str.ReadUInt32();
    InvokeTime = str.ReadUInt32();
    DisplayTime = str.ReadUInt32();
    if (version >= 30)
    {
        PresentTime = str.ReadUInt32();
    }
    TesselationTime = str.ReadUInt32();
    GradientGenTime = str.ReadUInt32();
    UserTime = str.ReadUInt32();
    LineCount = str.ReadUInt32();
    MaskCount = str.ReadUInt32();
    FilterCount = str.ReadUInt32();
    if (version >= 16)
    {
        MeshCount = str.ReadUInt32();
    }
    TriangleCount = str.ReadUInt32();
    DrawPrimitiveCount = str.ReadUInt32();
    StrokeCount = str.ReadUInt32();
    GradientFillCount = str.ReadUInt32();
    MeshThrashing = str.ReadUInt32();
    RasterizedGlyphCount = str.ReadUInt32();
    FontTextureCount = str.ReadUInt32();
    NumFontCacheTextureUpdates = str.ReadUInt32();
    if (version >= 14)
    {
        FontThrashing = str.ReadUInt32();
        FontFill = str.ReadUInt32();
        FontFail = str.ReadUInt32();
        if (version >= 24)
        {
            FontMisses = str.ReadUInt32();
        }
        if (version >= 27)
        {
            FontTotalArea = str.ReadUInt32();
            FontUsedArea = str.ReadUInt32();
        }
    }
    TotalMemory = str.ReadUInt32();
    ImageMemory = str.ReadUInt32();
    if (version >= 29)
    {
        ImageGraphicsMemory = str.ReadUInt32();
    }
    MovieDataMemory = str.ReadUInt32();
    MovieViewMemory = str.ReadUInt32();
    MeshCacheMemory = str.ReadUInt32();
    if (version >= 28)
    {
        MeshCacheGraphicsMemory = str.ReadUInt32();
        MeshCacheUnusedMemory = str.ReadUInt32();
        MeshCacheGraphicsUnusedMemory = str.ReadUInt32();
    }
    FontCacheMemory = str.ReadUInt32();
    VideoMemory = str.ReadUInt32();
    SoundMemory = str.ReadUInt32();
    OtherMemory = str.ReadUInt32();

    MovieStats.Resize(str.ReadUInt32());
    for (UPInt i = 0; i < MovieStats.GetSize(); ++i)
    {
        MovieStats[i] = *SF_HEAP_AUTO_NEW(this) MovieProfile();
        MovieStats[i]->Read(str, version);
    }
    if (version >= 15)
    {
        DisplayStats->Read(str, version);
    }
    if (version >= 25)
    {
        DisplayFunctionStats->Read(str, version);
    }
    SwdHandles.Resize(str.ReadUInt32());
    for (UPInt i = 0; i < SwdHandles.GetSize(); ++i)
    {
        SwdHandles[i] = str.ReadUInt32();
    }
    if (version >= 9)
    {
        FileHandles.Resize(str.ReadUInt32());
        for (UPInt i = 0; i < FileHandles.GetSize(); ++i)
        {
            FileHandles[i] = ReadUInt64(str);
        }
    }
    MemoryByStatId->Read(str, version);
    if (version <= 18)
    {
        Ptr<MemItem> tmp = *SF_HEAP_AUTO_NEW(this) MemItem(0);
        tmp->Read(str, version);
    }
    if (version >= 3)
    {
        Images->Read(str, version);
    }
    if (version >= 7)
    {
        Fonts->Read(str, version);
    }
    if (version >= 17)
    {
        ImageList.Resize(str.ReadUInt32());
        for (UPInt i = 0; i < ImageList.GetSize(); ++i)
        {
            ImageList[i] = *SF_HEAP_AUTO_NEW(this) ImageInfo();
            ImageList[i]->Read(str, version);
        }
    }

    if (version < 8)
    {
        str.ReadUInt32();
        str.ReadUInt32();
    }
}

// @0x14268cfe0
void GFx::AMP::MovieProfile::Read(File& str, UInt32 version)
{
    ViewHandle = str.ReadUInt32();
    MinFrame = str.ReadUInt32();
    MaxFrame = str.ReadUInt32();
    if (version >= 4)
    {
        readString(str, &ViewName);
        Version = str.ReadUInt32();
        Width = ReadFloat(str);
        Height = ReadFloat(str);
        FrameRate = ReadFloat(str);
        FrameCount = str.ReadUInt32();
    }
    if (version >= 6)
    {
        UInt32 numMarkers = str.ReadUInt32();
        Markers.Resize(numMarkers);
        for (UInt32 i = 0; i < numMarkers; ++i)
        {
            Markers[i] = *SF_HEAP_AUTO_NEW(this) MarkerInfo();
            if (version >= 11)
            {
                 readString(str, &Markers[i]->Name);
            }
            else
            {
                Markers[i]->Name = "Marker";
            }
            Markers[i]->Number = str.ReadUInt32();
        }
    }
    SF_ASSERT(InstructionStats);
    InstructionStats->Read(str, version);
    SF_ASSERT(FunctionStats);
    FunctionStats->Read(str, version);
    SF_ASSERT(SourceLineStats);
    SourceLineStats->Read(str, version);
    if (version >= 25)
    {
        SF_ASSERT(SourceLineStats);
        FunctionTreeStats->Read(str, version);
    }
}

// @0x14268ed90
void GFx::AMP::ImageInfo::Write(File& str, UInt32 version) const
{
    WriteUInt32(str, Id);
    writeString(str, Name);
    if (version < 29)
    {
        writeString(str, "");
    }
    WriteUInt32(str, Bytes);
    WriteUByte(str, External ? 1 : 0);
    WriteUInt32(str, AtlasId);
    WriteUInt32(str, AtlasTop);
    WriteUInt32(str, AtlasBottom);
    WriteUInt32(str, AtlasLeft);
    WriteUInt32(str, AtlasRight);
}

// MS2-FUNCTIONAL: hashes the eight byte key, follows the selected bucket's collision chain, and returns the matching value slot (entry + 0x18).
// @0x142745630
void* FindAudioRequestEntry(void** set, const unsigned char* key)
{
    auto* table = static_cast<std::uint64_t*>(*set);
    if (!table)
        return nullptr;
    const std::uint64_t hash =
        (((((std::uint64_t(key[3]) * 0x1003f + key[2]) * 0x1003f + key[1]) * 0x1003f + key[4] * 0xfc5d1543ec5f01ull) +
           key[5] * 0x9b302c28162c613full + key[7] * 0xd7c3e496a311b1bfull +
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
        if (static_cast<std::int64_t>(index) >= 0)
            return table + 5 + index * 6;
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

        // Only reached with a found entry (an unknown key skips straight to the unlock, 0x142745525).
        auto* table = *reinterpret_cast<void**>(managerBytes + 0xa8);
        if ((!table || *reinterpret_cast<unsigned long long*>(table) == 0) && managerBytes[0xf1] &&
            *reinterpret_cast<void**>(managerBytes + 0x18)) {
            managerBytes[0x78] = 1;
            FUN_14257dcb0(*reinterpret_cast<void**>(managerBytes + 0x18));
            *reinterpret_cast<void**>(managerBytes + 0x18) = nullptr;
            reinterpret_cast<Scaleform::Event*>(managerBytes + 0x20)->PulseEvent();
        }
    }
    LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(managerBytes + 0x80));

    if (removed) {
        auto* channel = *reinterpret_cast<FMOD::Channel**>(requestBytes + 0x38);
        if (channel)
            channel->stop();
        FUN_14257dcb0(request);
    }
}

// @0x14268a8e0
void GFx::AMP::MovieFunctionStats::Merge(const MovieFunctionStats& other)
{
    for (UPInt i = 0; i < other.FunctionTimings.GetSize(); ++i)
    {
        bool merged = false;
        for (UPInt j = 0; j < FunctionTimings.GetSize(); ++j)
        {
            if (FunctionTimings[j].FunctionId == other.FunctionTimings[i].FunctionId
                && FunctionTimings[j].CallerId == other.FunctionTimings[i].CallerId)
            {
                FunctionTimings[j].TimesCalled += other.FunctionTimings[i].TimesCalled;
                FunctionTimings[j].TotalTime += other.FunctionTimings[i].TotalTime;
                merged = true;
                break;
            }
        }
        if (!merged)
        {
            FunctionTimings.PushBack(other.FunctionTimings[i]);
        }
    }

    FunctionDescMap::ConstIterator it;
    for (it = other.FunctionInfo.Begin(); it != other.FunctionInfo.End(); ++it)
    {
        FunctionInfo.Set(it->First, it->Second);
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


// @0x142688760
GFx::AMP::ProfileFrame& GFx::AMP::ProfileFrame::operator/=(unsigned numFrames)
{
    TimeStamp /= numFrames;
    FramesPerSecond /= numFrames;
    AdvanceTime /= numFrames;
    TimelineTime /= numFrames;
    ActionTime /= numFrames;
    InputTime /= numFrames;
    MouseTime /= numFrames;
    GetVariableTime /= numFrames;
    SetVariableTime /= numFrames;
    InvokeTime /= numFrames;
    DisplayTime /= numFrames;
    PresentTime /= numFrames;
    TesselationTime /= numFrames;
    GradientGenTime /= numFrames;
    UserTime /= numFrames;
    LineCount /= numFrames;
    MaskCount /= numFrames;
    FilterCount /= numFrames;
    MeshCount /= numFrames;
    TriangleCount /= numFrames;
    DrawPrimitiveCount /= numFrames;
    StrokeCount /= numFrames;
    GradientFillCount /= numFrames;
    MeshThrashing /= numFrames;
    RasterizedGlyphCount /= numFrames;
    FontTextureCount /= numFrames;
    NumFontCacheTextureUpdates /= numFrames;
    FontThrashing /= numFrames;
    FontFill /= numFrames;
    FontFail /= numFrames;
    FontMisses /= numFrames;
    FontTotalArea /= numFrames;
    FontUsedArea /= numFrames;
    TotalMemory /= numFrames;
    ImageMemory /= numFrames;
    ImageGraphicsMemory /= numFrames;
    MovieDataMemory /= numFrames;
    MovieViewMemory /= numFrames;
    MeshCacheMemory /= numFrames;
    MeshCacheGraphicsMemory /= numFrames;
    MeshCacheUnusedMemory /= numFrames;
    MeshCacheGraphicsUnusedMemory /= numFrames;
    FontCacheMemory /= numFrames;
    VideoMemory /= numFrames;
    SoundMemory /= numFrames;
    OtherMemory /= numFrames;
    for (UPInt i = 0; i < MovieStats.GetSize(); ++i)
    {
        *MovieStats[i] /= numFrames;
    }
    *DisplayStats /= numFrames;
    *MemoryByStatId /= numFrames;
    *Images /= numFrames;
    *Fonts /= numFrames;
    return *this;
}

// @0x142687250
GFx::AMP::MovieProfile& GFx::AMP::MovieProfile::operator=(const MovieProfile& rhs)
{
    ViewHandle = rhs.ViewHandle;
    MinFrame = rhs.MinFrame;
    MaxFrame = rhs.MaxFrame;
    ViewName = rhs.ViewName;
    Version = rhs.Version;
    Width = rhs.Width;
    Height = rhs.Height;
    FrameRate = rhs.FrameRate;
    FrameCount = rhs.FrameCount;
    Markers = rhs.Markers;
    *InstructionStats = *rhs.InstructionStats;
    *FunctionStats = *rhs.FunctionStats;
    *SourceLineStats = *rhs.SourceLineStats;
    *FunctionTreeStats = *rhs.FunctionTreeStats;
    return *this;
}

// The String != String of SF_String.h (SFstrcmp); sf_string.h only has the const char* compare.
static inline bool operator!=(const String& lhs, const String& rhs)
{
    return SFstrcmp(lhs.ToCStr(), rhs.ToCStr()) != 0;
}

// @0x142687620
bool GFx::AMP::ServerState::operator!=(const ServerState& rhs) const
{
    if (StateFlags != rhs.StateFlags) return true;
    if (ProfileLevel != rhs.ProfileLevel) return true;
    if (ConnectedApp != rhs.ConnectedApp) return true;
    if (ConnectedFile != rhs.ConnectedFile) return true;
    if (AaMode != rhs.AaMode) return true;
    if (StrokeType != rhs.StrokeType) return true;
    if (CurrentLocale != rhs.CurrentLocale) return true;
    if (Locales.GetSize() != rhs.Locales.GetSize()) return true;
    for (UPInt i = 0; i < Locales.GetSize(); ++i)
    {
        if (Locales[i] != rhs.Locales[i]) return true;
    }
    if (Alg::Abs(CurveTolerance - rhs.CurveTolerance) > 0.0001) return true;
    if (Alg::Abs(CurveToleranceMin - rhs.CurveToleranceMin) > 0.0001) return true;
    if (Alg::Abs(CurveToleranceMax - rhs.CurveToleranceMax) > 0.0001) return true;
    if (Alg::Abs(CurveToleranceStep - rhs.CurveToleranceStep) > 0.0001) return true;
    if (CurrentFileId != rhs.CurrentFileId) return true;
    if (CurrentLineNumber != rhs.CurrentLineNumber) return true;

    return false;
}

// @0x142687540
GFx::AMP::ServerState& GFx::AMP::ServerState::operator=(const ServerState& rhs)
{
    StateFlags = rhs.StateFlags;
    ProfileLevel = rhs.ProfileLevel;
    ConnectedApp = rhs.ConnectedApp;
    ConnectedFile = rhs.ConnectedFile;
    AaMode = rhs.AaMode;
    StrokeType = rhs.StrokeType;
    CurrentLocale = rhs.CurrentLocale;
    Locales.Resize(rhs.Locales.GetSize());
    for (UPInt i = 0; i < Locales.GetSize(); ++i)
    {
        Locales[i] = rhs.Locales[i];
    }
    CurveTolerance = rhs.CurveTolerance;
    CurveToleranceMin = rhs.CurveToleranceMin;
    CurveToleranceMax = rhs.CurveToleranceMax;
    CurveToleranceStep = rhs.CurveToleranceStep;
    CurrentFileId = rhs.CurrentFileId;
    CurrentLineNumber = rhs.CurrentLineNumber;
    return *this;
}

// @0x1426870e0
GFx::AMP::ServerState::ServerState() :
    StateFlags(0),
    ProfileLevel(0),
    CurveTolerance(0.0f),
    CurveToleranceMin(0.0f),
    CurveToleranceMax(0.0f),
    CurveToleranceStep(0.0f),
    CurrentFileId(0),
    CurrentLineNumber(0)
{
}

namespace GFx { namespace AMP {
// @0x14268e6a0
void FuncTreeItem::ResetTreeIds(FuncTreeItem* other)
{
    MaxIdVisitor maxIdVisitor;
    other->Visit(maxIdVisitor);
    OffsetIdVisitor offsetVisitor(maxIdVisitor.MaxId);

    for (UPInt i = 0; i < Children.GetSize(); ++i)
    {
        Children[i]->Visit(offsetVisitor);
    }
}
}}

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

namespace GFx { namespace AMP {
// @0x14268c080
void MovieProfile::Print(Log* log) const
{
    log->LogMessage("========== MOVIE VIEW FUNCTIONS FOR %s ======\n", ViewName.ToCStr());
    FunctionStats->Print(log);
    FunctionTreeStats->Print(log);
}
}}

namespace GFx { namespace AMP {
// @0x14268c0d0
void ProfileFrame::Print(Log* log) const
{
    for (UPInt i = 0; i < MovieStats.GetSize(); ++i)
    {
        MovieStats[i]->Print(log);
    }
    log->LogMessage("========== RENDERER FUNCTIONS ===============\n");
    DisplayStats->Print(log);
    DisplayFunctionStats->Print(log);
}
}}

// MS2-FUNCTIONAL: links either an ordinary sound request or callback-backed stream request, then configures the FMOD source and dispatches stream format metadata.
// The whole body runs under the manager lock (+0xc8), as in the exe: the request is linked into the list before its FMOD
// sound exists, so leaving the lock early let the update thread see a half-built request.
// @0x1427449f0
void* FUN_1427449f0(void* manager, void* requestData)
{
    if (!requestData)
        return nullptr;
    auto* managerBytes = static_cast<unsigned char*>(manager);
    auto* request = static_cast<unsigned char*>(requestData);
    auto* lock = reinterpret_cast<CRITICAL_SECTION*>(managerBytes + 0xc8);
    EnterCriticalSection(lock);

    const unsigned options = *reinterpret_cast<unsigned*>(request + 0x10);
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    auto* object = static_cast<unsigned char*>(reinterpret_cast<void* (*)(void*, std::size_t, const void*)>(heapVtable[10])(
        DAT_143b15f60, 0x40, nullptr));
    if (!object) {
        LeaveCriticalSection(lock);
        return nullptr;
    }
    const bool stream = (options & 0x1000) && !(options & 0x2000);
    auto* node = object + 0x10;
    auto* sentinel = managerBytes + 0xb0;
    void* tail = *reinterpret_cast<void**>(managerBytes + 0xc0);
    *reinterpret_cast<void***>(object) = stream ? &AS3StreamRequestVtable : &AS3SoundRequestVtable;
    *reinterpret_cast<unsigned*>(object + 8) = 1;
    *reinterpret_cast<void***>(node) = stream ? &AS3StreamRequestNodeVtable : &AS3SoundRequestNodeVtable;
    *reinterpret_cast<void**>(node + 8) = sentinel;
    *reinterpret_cast<void**>(node + 0x10) = tail;
    *reinterpret_cast<void**>(static_cast<unsigned char*>(tail) + 8) = node;
    *reinterpret_cast<void**>(managerBytes + 0xc0) = node;
    *reinterpret_cast<unsigned*>(request + 8) += 1;
    *reinterpret_cast<void**>(object + 0x28) = stream ? requestData : manager;
    *reinterpret_cast<void**>(object + 0x30) = nullptr;
    *reinterpret_cast<void**>(object + 0x38) = stream ? manager : requestData;

    auto* system = *reinterpret_cast<FMOD::System**>(managerBytes + 0x10);
    auto* sound = reinterpret_cast<FMOD::Sound**>(object + 0x30);
    void* returned = nullptr;
    if (stream) {
        // Callback-fed stream: hand PCM16/float streams to the buffered-request factory (vtable[4]); every other
        // outcome returns null. The request reference is dropped either way.
        FMOD_RESULT result = static_cast<FMOD_RESULT>(0);
        unsigned char info[0xd8] = {};
        *reinterpret_cast<unsigned*>(info) = sizeof(info);
        *reinterpret_cast<int*>(info + 4) = 0x0fffffff;
        unsigned mode = 0x02002040;
        if ((options & 0x700) == 0x100) {
            mode = 0x02003040;
            *reinterpret_cast<unsigned*>(info + 0x10) = *reinterpret_cast<unsigned*>(request + 0x14);
            *reinterpret_cast<int*>(info + 0x14) = ((options & 7) == 2) + 1;
            *reinterpret_cast<int*>(info + 0x0c) = ((options & 8) != 0) + 1;
        } else if ((options & 0x700) == 0x200) {
            *reinterpret_cast<int*>(info + 0x14) = 0xb;
        } else {
            result = static_cast<FMOD_RESULT>(0x19);
        }
        if (result == 0) {
            *reinterpret_cast<unsigned*>(info + 0x18) = 0x2000;
            *reinterpret_cast<unsigned long long (**)(void*, void*, unsigned*, void*, void**)>(info + 0x78) = Scaleform::OpenAudioStream;
            *reinterpret_cast<unsigned long long (**)(void*, void*)>(info + 0x80) = Scaleform::CloseAudioStream;
            *reinterpret_cast<unsigned long long (**)(void*, void*, unsigned, unsigned*, void*)>(info + 0x88) = Scaleform::ReadAudioCallback;
            *reinterpret_cast<unsigned long long (**)(void*, void*, void*)>(info + 0x90) = Scaleform::ValidateAudioStream;
            result = system->createStream(*reinterpret_cast<const char**>(request + 0x20), mode,
                                          reinterpret_cast<FMOD_CREATESOUNDEXINFO*>(info), sound);
        }
        if (result == 0 && *sound) {
            int format = 0, channels = 0;
            float frequency = 0.0f;
            if (FUN_1428d8eba(*sound, nullptr, &format, &channels, nullptr) == 0
                && FUN_1428d8eb4(*sound, &frequency, nullptr, nullptr, nullptr) == 0
                && (format == 2 || format == 5)) {
                auto** vtable = *reinterpret_cast<void***>(manager);
                returned = reinterpret_cast<void* (*)(void*, void*, int, unsigned, void*)>(vtable[4])(
                    manager, object, channels, static_cast<unsigned>(frequency),
                    reinterpret_cast<void*>(format == 5 ? 1 : 0));
            }
        }
        FUN_14257dcb0(object);
        LeaveCriticalSection(lock);
        return returned;
    }

    FMOD_RESULT result = static_cast<FMOD_RESULT>(0);
    if (options & 0x2000) {
        result = system->createSound(*reinterpret_cast<const char**>(request + 0x20), (options & 0x1000) ? 0xc0 : 0x4040,
                                     nullptr, sound);
        if (result != 0)
            *sound = nullptr;
    } else {
        unsigned mode = 0x1a001040;
        unsigned char info[0xd8] = {};
        *reinterpret_cast<unsigned*>(info) = sizeof(info);
        if ((options & 0x700) == 0x100) {
            *reinterpret_cast<unsigned*>(info + 0x10) = *reinterpret_cast<unsigned*>(request + 0x14);
            *reinterpret_cast<int*>(info + 0x14) = ((options & 7) == 2) + 1;
            *reinterpret_cast<int*>(info + 0x0c) = ((options & 8) != 0) + 1;
        } else if ((options & 0x700) == 0x200) {
            mode = 0x1a000240;
            *reinterpret_cast<int*>(info + 0x14) = 0xb;
        } else {
            result = static_cast<FMOD_RESULT>(0x19);
        }
        if (result == 0) {
            *reinterpret_cast<unsigned*>(info + 4) = *reinterpret_cast<unsigned*>(request + 0x28);
            result = system->createSound(*reinterpret_cast<const char**>(request + 0x20), mode,
                                         reinterpret_cast<FMOD_CREATESOUNDEXINFO*>(info), sound);
        }
    }
    // The returned request keeps one reference (the creation one); a failed one is released here.
    if (result == 0) {
        InterlockedIncrement(reinterpret_cast<volatile long*>(object + 8));
        returned = object;
    }
    if (InterlockedExchangeAdd(reinterpret_cast<volatile long*>(object + 8), -1) == 1) {
        auto** vtable = *reinterpret_cast<void***>(object);
        reinterpret_cast<void (*)(void*, unsigned)>(vtable[0])(object, 1);
    }
    LeaveCriticalSection(lock);
    return returned;
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
    // Release, not delete: the request is already linked into the manager's list.
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(object + 8)) == 0) {
        auto** objectVtable = *reinterpret_cast<void***>(object);
        reinterpret_cast<void (*)(void*, unsigned)>(objectVtable[0])(object, 1);
    }
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

// MS2-FUNCTIONAL: fills every destination pixel with seeded grayscale or masked-channel noise from a seeded
// Alg::Random::Generator, column by column as the exe does.
// @0x142677260
void FUN_142677260(void* command, void*, void* imageData)
{
    auto* settings = static_cast<unsigned char*>(command);
    Scaleform::Alg::Random::Generator random;
    random.SeedRandom(*reinterpret_cast<unsigned*>(settings + 0x10));
    auto* planes = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(imageData) + 0x10);
    const unsigned width = *reinterpret_cast<unsigned*>(planes);
    const unsigned height = *reinterpret_cast<unsigned*>(planes + 4);
    const std::int64_t pitch = *reinterpret_cast<std::int64_t*>(planes + 8);
    const std::int64_t pixels = *reinterpret_cast<std::int64_t*>(planes + 0x18);
    const unsigned mask = *reinterpret_cast<unsigned*>(settings + 0x1c);
    const bool gray = *reinterpret_cast<unsigned char*>(settings + 0x20) != 0;
    auto* image = *reinterpret_cast<unsigned char**>(settings + 8);
    const bool opaque = image && *reinterpret_cast<unsigned char*>(image + 0x48) == 0;
    for (unsigned x = 0; x < width; ++x) {
        for (unsigned y = 0; y < height; ++y) {
            unsigned pixel = 0;
            unsigned alpha = 255;
            if (gray) {
                const float value = random.GetUnitFloat();
                const float alphaValue = (mask & 8) != 0 ? random.GetUnitFloat() : 1.0f;
                const unsigned level = static_cast<unsigned char>(static_cast<int>(value * 255.0f));
                pixel = level | (level << 8) | (level << 16);
                alpha = static_cast<unsigned char>(static_cast<int>(alphaValue * 255.0f));
            } else {
                if (mask & 1) pixel |= unsigned(static_cast<unsigned char>(static_cast<int>(random.GetUnitFloat() * 255.0f))) << 16;
                if (mask & 2) pixel |= unsigned(static_cast<unsigned char>(static_cast<int>(random.GetUnitFloat() * 255.0f))) << 8;
                if (mask & 4) pixel |= static_cast<unsigned char>(static_cast<int>(random.GetUnitFloat() * 255.0f));
                if (mask & 8) alpha = static_cast<unsigned char>(static_cast<int>(random.GetUnitFloat() * 255.0f));
            }
            if (opaque) alpha = 255;
            pixel |= alpha << 24;
            FUN_14257d390(imageData, pitch * y + pixels, x, pixel);
        }
    }
}

// MS2-FUNCTIONAL: rebuilds the threshold draw transform and forwards the operation, threshold, color, mask, and copy-source flag to the renderer.
// @0x142675870
void FUN_142675870(void* command, void* context, void* textures, const void* texgen)
{
    auto* bytes = static_cast<unsigned char*>(command);
    float transform[8] = { ThresholdTransformX[0], ThresholdTransformX[1], ThresholdTransformX[2], ThresholdTransformX[3],
                           ThresholdTransformY[0], ThresholdTransformY[1], ThresholdTransformY[2], ThresholdTransformY[3] };
    auto** commandVtable = *reinterpret_cast<void***>(command);
    const bool requiresSource = reinterpret_cast<bool (*)(void*)>(commandVtable[11])(command);
    if (!requiresSource) {
        auto* image = *reinterpret_cast<void**>(bytes + 8);
        auto** imageVtable = *reinterpret_cast<void***>(image);
        unsigned size[2] = {};
        reinterpret_cast<void* (*)(void*, unsigned*)>(imageVtable[5])(image, size);
        const float scaleX = static_cast<float>(*reinterpret_cast<int*>(bytes + 0x20) - *reinterpret_cast<int*>(bytes + 0x18)) / size[0];
        const float scaleY = static_cast<float>(*reinterpret_cast<int*>(bytes + 0x24) - *reinterpret_cast<int*>(bytes + 0x1c)) / size[1];
        for (unsigned i = 0; i < 4; ++i) {
            transform[i] *= scaleX * 2.0f;
            transform[i + 4] *= scaleY * DrawableImageScale2;
        }
        unsigned origin[2] = {};
        reinterpret_cast<void* (*)(void*, unsigned*)>(imageVtable[5])(image, origin);
        transform[3] = (static_cast<float>(*reinterpret_cast<int*>(bytes + 0x28)) - origin[0] * ImageViewportScale) /
                       size[0] + transform[3];
        transform[7] = (static_cast<float>(*reinterpret_cast<int*>(bytes + 0x2c)) - origin[1] * ImageViewportScale) /
                       size[1] + transform[7];
        transform[7] *= DrawableImageScale2;
    } else {
        transform[0] = ImageViewportBias;
        transform[3] = ImageViewportClampBias;
        transform[5] = DrawableImageScale2;
        transform[7] = FloatOne;
    }
    auto* renderer = *reinterpret_cast<void**>(static_cast<unsigned char*>(context) + 8);
    auto** rendererVtable = *reinterpret_cast<void***>(renderer);
    reinterpret_cast<void (*)(void*, void*, const void*, const float*, unsigned, unsigned, unsigned, unsigned, bool)>(rendererVtable[48])(
        renderer, textures, texgen, transform, *reinterpret_cast<unsigned*>(bytes + 0x40),
        *reinterpret_cast<unsigned*>(bytes + 0x44), *reinterpret_cast<unsigned*>(bytes + 0x48),
        *reinterpret_cast<unsigned*>(bytes + 0x4c), *reinterpret_cast<bool*>(bytes + 0x50));
}

// MS2-FUNCTIONAL: scales the palette-map texture transform for the destination image and submits its channel table and mask to the HAL.
// @0x142675560
void FUN_142675560(void* command, void* context, void* textures, const void* texgen)
{
    auto* bytes = static_cast<unsigned char*>(command);
    float transform[8] = { ThresholdTransformX[0], ThresholdTransformX[1], ThresholdTransformX[2], ThresholdTransformX[3],
                           ThresholdTransformY[0], ThresholdTransformY[1], ThresholdTransformY[2], ThresholdTransformY[3] };
    auto** commandVtable = *reinterpret_cast<void***>(command);
    const bool requiresSource = reinterpret_cast<bool (*)(void*)>(commandVtable[11])(command);
    if (!requiresSource) {
        auto* image = *reinterpret_cast<void**>(bytes + 8);
        auto** imageVtable = *reinterpret_cast<void***>(image);
        unsigned size[2] = {};
        reinterpret_cast<void* (*)(void*, unsigned*)>(imageVtable[5])(image, size);
        const float scaleX = static_cast<float>(*reinterpret_cast<int*>(bytes + 0x24) - *reinterpret_cast<int*>(bytes + 0x1c)) / size[1];
        const float scaleY = static_cast<float>(*reinterpret_cast<int*>(bytes + 0x20) - *reinterpret_cast<int*>(bytes + 0x18)) / size[0];
        for (unsigned i = 0; i < 4; ++i) {
            transform[i] *= scaleY * 2.0f;
            transform[i + 4] *= scaleX * DrawableImageScale2;
        }
        unsigned origin[2] = {};
        reinterpret_cast<void* (*)(void*, unsigned*)>(imageVtable[5])(image, origin);
        transform[3] = (static_cast<float>(*reinterpret_cast<int*>(bytes + 0x28)) - origin[0] * ImageViewportScale) /
                       size[0] + transform[3];
        transform[7] = ((static_cast<float>(*reinterpret_cast<int*>(bytes + 0x2c)) - origin[1] * ImageViewportScale) /
                       size[1] + transform[7]) * DrawableImageScale2;
    } else {
        transform[0] = ImageViewportBias;
        transform[3] = ImageViewportClampBias;
        transform[5] = DrawableImageScale2;
        transform[7] = FloatOne;
    }
    auto* renderer = *reinterpret_cast<void**>(static_cast<unsigned char*>(context) + 8);
    auto** rendererVtable = *reinterpret_cast<void***>(renderer);
    reinterpret_cast<void (*)(void*, void*, const void*, const float*, const unsigned*, unsigned)>(rendererVtable[47])(
        renderer, textures, texgen, transform, *reinterpret_cast<const unsigned**>(bytes + 0x40),
        *reinterpret_cast<unsigned*>(bytes + 0x48));
}

namespace GFx { namespace AMP {
// @0x14268bd60
void MovieFunctionTreeStats::Print(Log* log) const
{
    // Accumulate (0x142689640) lives in sfr_kernel_03n under its FUN_ name.
    Ptr<MovieFunctionStats> accumulatedStats = *static_cast<MovieFunctionStats*>(
        FUN_142689640(const_cast<MovieFunctionTreeStats*>(this), true));

    for (UPInt i = 0; i < accumulatedStats->FunctionTimings.GetSize(); ++i)
    {
        String entry;
        String name;
        FunctionDescMap::ConstIterator descIt;
        descIt = FunctionInfo.Find(accumulatedStats->FunctionTimings[i].FunctionId);
        if (descIt != FunctionInfo.End())
        {
            name = descIt->Second->Name;
        }
        if (!name.IsEmpty())
        {
            Format(entry, "{0}: {1} ms ({2} times)\n", name.ToCStr(), accumulatedStats->FunctionTimings[i].TotalTime / 1000, accumulatedStats->FunctionTimings[i].TimesCalled);
            log->LogMessage("%s", entry.ToCStr());
        }
    }
}
}}

}

namespace Scaleform { namespace GFx { namespace AMP {
bool funcStatsLess(const MovieFunctionStats::FuncStats& lhs, const MovieFunctionStats::FuncStats& rhs)
{
    return lhs.TotalTime > rhs.TotalTime;
}

// @0x14268b710
void MovieFunctionStats::Print(Log* log) const
{
    Hash<UInt64, FuncStats> funcMap;
    for (UPInt i = 0; i < FunctionTimings.GetSize(); ++i)
    {
        Hash<UInt64, FuncStats>::Iterator it = funcMap.Find(FunctionTimings[i].FunctionId);
        if (it != funcMap.End())
        {
            ++it->Second.TimesCalled;
            it->Second.TotalTime += FunctionTimings[i].TotalTime;
        }
        else
        {
            funcMap.Add(FunctionTimings[i].FunctionId, FunctionTimings[i]);
        }
    }

    Array<FuncStats> sortedList;
    for (Hash<UInt64, FuncStats>::Iterator it = funcMap.Begin(); it != funcMap.End(); ++it)
    {
        FuncStats newItem;
        newItem.FunctionId = it->First;
        newItem.CallerId = it->Second.CallerId;
        newItem.TotalTime = it->Second.TotalTime;
        newItem.TimesCalled = it->Second.TimesCalled;
        sortedList.PushBack(newItem);
    }
    Alg::QuickSortSliced(sortedList, 0, sortedList.GetSize(), funcStatsLess);

    for (UPInt i = 0; i < sortedList.GetSize(); ++i)
    {
        String entry;
        String name;
        FunctionDescMap::ConstIterator descIt;
        descIt = FunctionInfo.Find(sortedList[i].FunctionId);
        if (descIt != FunctionInfo.End())
        {
            name = descIt->Second->Name;
        }
        Format(entry, "{0}: {1} ms ({2} times)\n", name.ToCStr(), sortedList[i].TotalTime / 1000, sortedList[i].TimesCalled);
        log->LogMessage("%s", entry.ToCStr());
    }
}
}}}

namespace Scaleform { namespace GFx {

// Shared slots of the sound objects' RTTI-less vftables (data_cri 0x1431bcbe8 / 0x1431bec40 and their secondaries):
// leaf functions without .pdata.
// @0x1427447e0
int FUN_1427447e0(void*)
{
    return 0;
}

// @0x142746220
void FUN_142746220(void*)
{
}

}} // namespace Scaleform::GFx

void FUN_142747b30(void*);

namespace Scaleform { namespace GFx {

// FMOD sound player vftable slots (data_cri 0x1431bede8 / 0x1431bee78 / 0x1431bef00) without .pdata.
// @0x142745620
void FUN_142745620(void* player)
{
    FUN_142747b30(player);
}

// the FMOD system pointer
// @0x142745830
void* FUN_142745830(void* player)
{
    return *reinterpret_cast<void**>(static_cast<char*>(player) + 0x10);
}

// @0x142745a90
bool FUN_142745a90(void*, unsigned* value)
{
    if (!value)
        return false;
    *value = 0;
    return true;
}

// the FMOD sound pointer
// @0x142745ab0
void* FUN_142745ab0(void* player)
{
    return *reinterpret_cast<void**>(static_cast<char*>(player) + 0x30);
}

// @0x142745b70
void* FUN_142745b70(void* player)
{
    return *reinterpret_cast<void**>(static_cast<char*>(player) + 0x28);
}

// MS2-FUNCTIONAL: byte-identical to 0x142745b70; emitted as a distinct exe copy.
// @0x142745b80
void* FUN_142745b80(void* player)
{
    return *reinterpret_cast<void**>(static_cast<char*>(player) + 0x28);
}

// @0x142745c30
bool FUN_142745c30(void* player)
{
    return *reinterpret_cast<void**>(static_cast<char*>(player) + 0x30) != nullptr;
}

// pauses or resumes the channel when one is attached
// @0x142745ea0
void FUN_142745ea0(void* player, bool paused)
{
    void* channel = *reinterpret_cast<void**>(static_cast<char*>(player) + 0x38);
    if (channel)
        FUN_1428d8ed8(channel, paused);
}

// forwards to the source's vftable slot 6 with the flag
// @0x142745f30
int FUN_142745f30(void*, void* source, bool flag)
{
    if (!source)
        return 0;
    using Slot = int (*)(void*, bool);
    return reinterpret_cast<Slot>((*reinterpret_cast<void***>(source))[6])(source, flag);
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7MemItem@Scaleform@@6B@ 0x143192160
// MS2-PIN: ??_7?$RefCountBase@UMemItem@Scaleform@@$01@Scaleform@@6B@ 0x143193df0

// COMDATs of the AMP function-stats printing (MovieFunctionStats::Print, the FunctionTreeVisitor).
typedef Scaleform::Hash<Scaleform::UInt64, Scaleform::GFx::AMP::MovieFunctionStats::FuncStats> Ms2FuncStatsHash;
typedef Scaleform::GFx::AMP::MovieFunctionStats::FuncStats Ms2FuncStats;
typedef decltype(Ms2FuncStatsHash::mHash) Ms2FuncStatsSet;
// @0x1426906b0
template void Ms2FuncStatsSet::BaseType::setRawCapacity(void* pheapAddr, Scaleform::UPInt n);
// @0x1426867f0
template void Ms2FuncStatsSet::BaseType::add<Ms2FuncStatsHash::NodeRef>(void* pheapAddr, const Ms2FuncStatsHash::NodeRef& key, Scaleform::UPInt hashValue);
// @0x14268a450
template Ms2FuncStatsSet::BaseType::Iterator Ms2FuncStatsSet::BaseType::FindAlt<Scaleform::UInt64>(const Scaleform::UInt64& key);
// @0x1426899e0
template void Ms2FuncStatsHash::Add(const Scaleform::UInt64& key, const Ms2FuncStats& value);
// @0x1426871f0
template Ms2FuncStatsSet::BaseType::~HashSetBase();
// @0x14268e420
template void Scaleform::ArrayDataBase<Ms2FuncStats, Scaleform::AllocatorGH<Ms2FuncStats, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void* pheapAddr, Scaleform::UPInt newCapacity);
// @0x1426860f0
template void Scaleform::Alg::QuickSortSliced(Scaleform::Array<Ms2FuncStats>& arr, Scaleform::UPInt start, Scaleform::UPInt end,
                                              bool (*less)(const Ms2FuncStats&, const Ms2FuncStats&));

// COMDATs of the ServerState Locales array (ArrayLH<String>).
typedef Scaleform::ArrayDataBase<Scaleform::String, Scaleform::AllocatorLH<Scaleform::String, 2>, Scaleform::ArrayDefaultPolicy> Ms2StringLHArrayBase;
// symbols.tsv binds ~ArrayDataBase<String, AllocatorLH> to its other copy (0x1422fc040); this one is the
// copy sfr_kernel_03n calls as FUN_142687170.
// @0x142687170
extern "C" void FUN_142687170(Ms2StringLHArrayBase* locales)
{
    Scaleform::AllocatorLH<Scaleform::String, 2>::DestructArray(locales->Data, locales->Size);
    Scaleform::AllocatorLH<Scaleform::String, 2>::Free(locales->Data);
}
// ArrayData<String, AllocatorLH>::Resize. symbols.tsv binds Reserve<String, AllocatorLH> to 0x1422fdbd0, but this
// copy calls the Reserve at 0x14268e600 (the Ptr<ImageInfo> one, folded), so it reaches it by VA.
extern "C" void FUN_14268e600(Ms2StringLHArrayBase* locales, const void* pheapAddr, Scaleform::UPInt newCapacity);
// @0x14268e8c0
extern "C" void FUN_14268e8c0(Ms2StringLHArrayBase* locales, Scaleform::UPInt newSize)
{
    typedef Scaleform::AllocatorLH<Scaleform::String, 2> Allocator;
    Scaleform::UPInt oldSize = locales->Size;
    if (newSize < oldSize)
    {
        Allocator::DestructArray(locales->Data + newSize, oldSize - newSize);
        if (newSize < (locales->Policy.GetCapacity() >> 1))
            FUN_14268e600(locales, locales, newSize);
    }
    else if (newSize >= locales->Policy.GetCapacity())
    {
        FUN_14268e600(locales, locales, newSize + (newSize >> 2));
    }
    locales->Size = newSize;
    if (newSize > oldSize)
        Allocator::ConstructArray(locales->Data + oldSize, newSize - oldSize);
}

// COMDATs of the FunctionTimings / SourceLineTimings arrays (ArrayLH of the 0x20 / 0x18 byte POD stats).
// @0x14268e740
template void Scaleform::ArrayData<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats, Scaleform::AllocatorLH<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats, 2>, Scaleform::ArrayDefaultPolicy>::Resize(Scaleform::UPInt newSize);
// @0x14268e840
template void Scaleform::ArrayData<Scaleform::GFx::AMP::MovieSourceLineStats::SourceStats, Scaleform::AllocatorLH<Scaleform::GFx::AMP::MovieSourceLineStats::SourceStats, 2>, Scaleform::ArrayDefaultPolicy>::Resize(Scaleform::UPInt newSize);

// @0x14268a570
void Scaleform::GFx::AMP::FuncTreeItem::GetAllFunctions(HashSet<UInt64>* functionIds) const
{
    functionIds->Set(FunctionId);
    for (UPInt i = 0; i < Children.GetSize(); ++i)
    {
        Children[i]->GetAllFunctions(functionIds);
    }
}

// COMDATs of the FunctionInfo / SourceFileInfo maps (MovieProfile::operator=) and the GetAllFunctions set.
typedef decltype(Scaleform::GFx::AMP::FunctionDescMap::mHash) Ms2FunctionDescSet;
typedef decltype(Scaleform::GFx::AMP::SourceFileDescMap::mHash) Ms2SourceFileDescSet;
typedef Scaleform::HashSet<Scaleform::UInt64>::BaseType Ms2UInt64SetBase;
// @0x142689aa0
template void Ms2FunctionDescSet::BaseType::Assign(void* pmemAddr, const Ms2FunctionDescSet::BaseType& src);
// @0x142689cb0
template void Ms2SourceFileDescSet::BaseType::Assign(void* pmemAddr, const Ms2SourceFileDescSet::BaseType& src);
// @0x142689f10
template void Ms2FunctionDescSet::BaseType::Clear();
// @0x142689fa0
template void Ms2SourceFileDescSet::BaseType::Clear();
// @0x142686650
template void Ms2SourceFileDescSet::BaseType::add<Scaleform::GFx::AMP::SourceFileDescMap::NodeRef>(void* pheapAddr, const Scaleform::GFx::AMP::SourceFileDescMap::NodeRef& key, Scaleform::UPInt hashValue);
// @0x1426869a0
template void Ms2UInt64SetBase::add<Scaleform::UInt64>(void* pheapAddr, const Scaleform::UInt64& key, Scaleform::UPInt hashValue);
// @0x142690a20
template void Ms2UInt64SetBase::setRawCapacity(void* pheapAddr, Scaleform::UPInt newSize);
// @0x1425684a0
template void Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MethodInfo*, Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodInfo*, Scaleform::GFx::AS3::StatMV_VM_AbcFile_Mem>, Scaleform::ArrayDefaultPolicy>::Resize(Scaleform::UPInt newSize);
// @0x142568520
template void Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::ScriptInfo*, Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::ScriptInfo*, Scaleform::GFx::AS3::StatMV_VM_AbcFile_Mem>, Scaleform::ArrayDefaultPolicy>::Resize(Scaleform::UPInt newSize);
template void Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::ImageInfo>, Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::ImageInfo>, Scaleform::Stat_Default_Mem>, Scaleform::ArrayDefaultPolicy>::Reserve(const void* pheapAddr, Scaleform::UPInt newCapacity);
template void Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::MovieProfile>, Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::MovieProfile>, Scaleform::Stat_Default_Mem>, Scaleform::ArrayDefaultPolicy>::Reserve(const void* pheapAddr, Scaleform::UPInt newCapacity);
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$Ptr@UImageInfo@AMP@GFx@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@UImageInfo@AMP@GFx@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x14268e4c0
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$Ptr@UMovieProfile@AMP@GFx@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@UMovieProfile@AMP@GFx@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x14268e560
