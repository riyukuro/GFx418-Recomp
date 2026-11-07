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
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$CreateEntry@VTreeContainer@Render@Scaleform@@@Context@ContextImpl@Render@Scaleform@@QEAAPEAVTreeContainer@23@XZ 0x142568620 ; unique
// MS2-PINS-END tplpin
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"
#include "ms2/scaleform/include/kernel/sf_array.h"
#include "ms2/scaleform/include/kernel/sf_msgformat.h"
#include "ms2/scaleform/include/kernel/sf_string.h"
#include "ms2/scaleform/kernel/sf_memitem.h"
#include "ms2/scaleform/kernel/sf_log.h"
#include "ms2/scaleform/kernel/sf_random.h"
#include "ms2/scaleform/include/kernel/sf_threads.h"
#include "ms2/scaleform/include/kernel/sf_timer.h"
#include "ms2/scaleform/include/gfx/gfx_rendertree.h"
#include "ms2/scaleform/include/gfx/amp/amp_profileframe.h"
#include "ms2/scaleform/include/render/render_perlin.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/render/render_cxform.h"
#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/include/sound/sound_sound.h"
#include "ms2/scaleform/include/kernel/sf_memory.h"
#include "hook/ms2hook.h"
#include <cstdint>
#include <cstring>
#include <math.h>
#include <new>
#include <random>
#include <vector>

// Memory::pGlobalHeap (DAT_143b15f60), read through the real static.
#define DAT_143b15f60 (static_cast<void*>(Scaleform::Memory::pGlobalHeap))

// The exe functions and globals this unit uses but does not define, declared by their FUN_<va> / DAT_<va> names: the
// hook DLL binds them to the exe, the full exe to the recovered definition at that VA (tools/fullexe/alias.py).
template <class T> using ExeDecl = T;

typedef decltype(Scaleform::Hash<Scaleform::UInt64, Scaleform::GFx::AMP::MovieFunctionStats::FuncStats>::mHash)::BaseType Ms2FuncStatsSetBase; extern template void Ms2FuncStatsSetBase::setRawCapacity(void* pheapAddr, Scaleform::UPInt n);   // 0x1426906b0, instantiated below
extern "C" void FUN_142747530(void*, void*, std::size_t);
extern "C" void FUN_1427478c0(void*, void*, std::size_t);
extern "C" void FUN_142585f70(void*, int);
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
struct Sd_1431bede8;
extern "C" Sd_1431bede8 DAT_1431bede8;
#define AS3AudioEventVtable (*reinterpret_cast<void**>(&DAT_1431bede8))
extern "C" char DAT_1431bcbb0[];   // the sound objects' outermost base
#define AS3SoundObjectBaseVtable DAT_1431bcbb0
extern unsigned char DAT_142dc9d48[];   // RefCountImplCore vftable (SwfSoundStreamer ctor chain); the name data_data_game.cpp declares
#define DAT_142dc9d48_RefCountImplCore DAT_142dc9d48
extern "C" char DAT_1431b80b8[];   // SoundRenderer::AuxStreamer vftable
struct Sd_1431bec40;
extern "C" Sd_1431bec40 DAT_1431bec40;
#define AS3AudioListNodeVtable (*reinterpret_cast<void**>(&DAT_1431bec40))
struct Sd_1431bed18;
extern "C" Sd_1431bed18 DAT_1431bed18;
#define AS3SoundRequestVtable (*reinterpret_cast<void**>(&DAT_1431bed18))
struct Sd_1431bed50;
extern "C" Sd_1431bed50 DAT_1431bed50;
#define AS3SoundRequestNodeVtable (*reinterpret_cast<void**>(&DAT_1431bed50))
struct Sd_1431bef00;
extern "C" Sd_1431bef00 DAT_1431bef00;
#define AS3BufferedRequestVtable (*reinterpret_cast<void**>(&DAT_1431bef00))
struct Sd_1431bef38;
extern "C" Sd_1431bef38 DAT_1431bef38;
#define AS3BufferedRequestNodeVtable (*reinterpret_cast<void**>(&DAT_1431bef38))
struct Sd_1431bee50;
extern "C" Sd_1431bee50 DAT_1431bee50;
#define AS3StreamRequestVtable (*reinterpret_cast<void**>(&DAT_1431bee50))
struct Sd_1431bee68;
extern "C" Sd_1431bee68 DAT_1431bee68;
#define AS3StreamRequestNodeVtable (*reinterpret_cast<void**>(&DAT_1431bee68))
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
inline void FUN_14257dcb0(void* p) { static_cast<Scaleform::RefCountImpl*>(p)->Release(); }
inline void FUN_14257dc30(void* p) { static_cast<Scaleform::RefCountImpl*>(p)->AddRef(); }
namespace Scaleform { namespace GFx { void* FUN_142689640(void*, bool); } }

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
enum FMOD_SOUND_FORMAT : int {};
enum FMOD_SOUND_TYPE : int {};
enum FMOD_DSP_RESAMPLER : int {};
enum FMOD_DELAYTYPE : int {};
enum FMOD_CHANNEL_CALLBACKTYPE : int {};
struct FMOD_CHANNEL;
typedef FMOD_RESULT (*FMOD_CHANNEL_CALLBACK)(FMOD_CHANNEL* channel, FMOD_CHANNEL_CALLBACKTYPE type, void* commandData1, void* commandData2);
// FMOD 4.44 FMOD_CREATESOUNDEXINFO (fmod.h), enums and callbacks as their underlying types.
struct FMOD_CREATESOUNDEXINFO
{
    int cbsize;
    unsigned int length;
    unsigned int fileoffset;
    int numchannels;
    int defaultfrequency;
    int format;
    unsigned int decodebuffersize;
    int initialsubsound;
    int numsubsounds;
    int* inclusionlist;
    int inclusionlistnum;
    void* pcmreadcallback;
    void* pcmsetposcallback;
    void* nonblockcallback;
    const char* dlsname;
    const char* encryptionkey;
    int maxpolyphony;
    void* userdata;
    int suggestedsoundtype;
    void* useropen;
    void* userclose;
    void* userread;
    void* userseek;
    void* userasyncread;
    void* userasynccancel;
    int speakermap;
    void* initialsoundgroup;
    unsigned int initialseekposition;
    unsigned int initialseekpostype;
    int ignoresetfilesystem;
    int cddaforceaspi;
    unsigned int audioqueuepolicy;
    unsigned int minmidigranularity;
    int nonblockthreadid;
};
static_assert(sizeof(FMOD_CREATESOUNDEXINFO) == 0xd8, "FMOD_CREATESOUNDEXINFO size");
namespace FMOD {
class Sound
{
public:
    ::FMOD_RESULT getLength(unsigned* length, unsigned timeUnit);
    ::FMOD_RESULT release();
    ::FMOD_RESULT lock(unsigned offset, unsigned length, void** first, void** second,
                       unsigned* firstLength, unsigned* secondLength);
    ::FMOD_RESULT unlock(void* first, void* second, unsigned firstLength, unsigned secondLength);
    ::FMOD_RESULT getDefaults(float* frequency, float* volume, float* pan, int* priority);
    ::FMOD_RESULT getFormat(::FMOD_SOUND_TYPE* type, ::FMOD_SOUND_FORMAT* format, int* channels, int* bits);
    ::FMOD_RESULT readData(void* buffer, unsigned lenBytes, unsigned* read);
};
class ChannelGroup
{
public:
    ::FMOD_RESULT getVolume(float* volume);
    ::FMOD_RESULT setMute(bool mute);
};
class System
{
public:
    ::FMOD_RESULT createSound(const char* path, unsigned mode, ::FMOD_CREATESOUNDEXINFO* info, Sound** sound);
    ::FMOD_RESULT createStream(const char* path, unsigned mode, ::FMOD_CREATESOUNDEXINFO* info, Sound** sound);
    ::FMOD_RESULT getSoftwareFormat(int* sampleRate, ::FMOD_SOUND_FORMAT* format, int* numOutputChannels,
                                    int* maxInputChannels, ::FMOD_DSP_RESAMPLER* resampleMethod, int* bits);
    ::FMOD_RESULT getMasterChannelGroup(ChannelGroup** channelGroup);
    ::FMOD_RESULT getDSPClock(unsigned* hi, unsigned* lo);
};
class Channel
{
public:
    ::FMOD_RESULT isPlaying(bool* playing);
    ::FMOD_RESULT getPosition(unsigned* position, unsigned timeUnit);
    ::FMOD_RESULT stop();
    ::FMOD_RESULT setPaused(bool paused);
    ::FMOD_RESULT getVolume(float* volume);
    ::FMOD_RESULT getPan(float* pan);
    ::FMOD_RESULT setDelay(::FMOD_DELAYTYPE delayType, unsigned delayHi, unsigned delayLo);
    ::FMOD_RESULT setPosition(unsigned position, unsigned posType);
    ::FMOD_RESULT setCallback(::FMOD_CHANNEL_CALLBACK callback);
    ::FMOD_RESULT setMode(unsigned mode);
    ::FMOD_RESULT setLoopCount(int loopCount);
    ::FMOD_RESULT setLoopPoints(unsigned loopStart, unsigned loopStartType, unsigned loopEnd, unsigned loopEndType);
    ::FMOD_RESULT setUserData(void* userData);
};
}

// The fmodex import thunks under their old raw signatures.
inline int FUN_1428d8ea8(void* s, unsigned off, unsigned len, void** a, void** b, unsigned* la, unsigned* lb) { return static_cast<FMOD::Sound*>(s)->lock(off, len, a, b, la, lb); }
inline int FUN_1428d8eae(void* s, void* a, void* b, unsigned la, unsigned lb) { return static_cast<FMOD::Sound*>(s)->unlock(a, b, la, lb); }
inline int FUN_1428d8eb4(void* s, float* f, float* v, float* p, int* pr) { return static_cast<FMOD::Sound*>(s)->getDefaults(f, v, p, pr); }
inline int FUN_1428d8eba(void* s, void* t, int* f, int* c, int* b) { return static_cast<FMOD::Sound*>(s)->getFormat(static_cast<FMOD_SOUND_TYPE*>(t), reinterpret_cast<FMOD_SOUND_FORMAT*>(f), c, b); }
inline int FUN_1428d8ec0(void* s, void* buf, unsigned len, unsigned* read) { return static_cast<FMOD::Sound*>(s)->readData(buf, len, read); }
inline int FUN_1428d8f26(void* g, float* v) { return static_cast<FMOD::ChannelGroup*>(g)->getVolume(v); }
inline int FUN_1428d8f2c(void* g, bool m) { return static_cast<FMOD::ChannelGroup*>(g)->setMute(m); }
inline int FUN_1428d8e96(void* sy, int* rate, int* f, int* oc, int* ic, int* rs, int* bits) { return static_cast<FMOD::System*>(sy)->getSoftwareFormat(rate, reinterpret_cast<FMOD_SOUND_FORMAT*>(f), oc, ic, reinterpret_cast<FMOD_DSP_RESAMPLER*>(rs), bits); }
inline int FUN_1428d8e9c(void* sy, void** g) { return static_cast<FMOD::System*>(sy)->getMasterChannelGroup(reinterpret_cast<FMOD::ChannelGroup**>(g)); }
inline int FUN_1428d8ea2(void* sy, unsigned* hi, unsigned* lo) { return static_cast<FMOD::System*>(sy)->getDSPClock(hi, lo); }
inline int FUN_1428d8ed8(void* c, bool p) { return static_cast<FMOD::Channel*>(c)->setPaused(p); }
inline int FUN_1428d8ede(void* c, float* v) { return static_cast<FMOD::Channel*>(c)->getVolume(v); }
inline int FUN_1428d8eea(void* c, float* p) { return static_cast<FMOD::Channel*>(c)->getPan(p); }
inline int FUN_1428d8ef0(void* c, unsigned t, unsigned hi, unsigned lo) { return static_cast<FMOD::Channel*>(c)->setDelay(static_cast<FMOD_DELAYTYPE>(t), hi, lo); }
inline int FUN_1428d8ef6(void* c, unsigned pos, unsigned type) { return static_cast<FMOD::Channel*>(c)->setPosition(pos, type); }
inline int FUN_1428d8efc(void* c, void* cb) { return static_cast<FMOD::Channel*>(c)->setCallback(reinterpret_cast<FMOD_CHANNEL_CALLBACK>(cb)); }
inline int FUN_1428d8f02(void* c, unsigned m) { return static_cast<FMOD::Channel*>(c)->setMode(m); }
inline int FUN_1428d8f08(void* c, int n) { return static_cast<FMOD::Channel*>(c)->setLoopCount(n); }
inline int FUN_1428d8f0e(void* c, unsigned a, unsigned b, unsigned d, unsigned e) { return static_cast<FMOD::Channel*>(c)->setLoopPoints(a, b, d, e); }
inline int FUN_1428d8f14(void* c, void* u) { return static_cast<FMOD::Channel*>(c)->setUserData(u); }

namespace Scaleform {
static FMOD::Sound* SoundForLength(void* soundSource)
{
    return *reinterpret_cast<FMOD::Sound**>(static_cast<char*>(soundSource) + 0x30);
}

// retains the executable's null check, FMOD millisecond query, and failure result.
// @0x142745760
unsigned QuerySoundLength(void* soundSource)
{
    if (FMOD::Sound* sound = SoundForLength(soundSource))
    {
        unsigned length = 0;
        if (sound->getLength(&length, 8) == 0)
            return length;
    }
    return 0;
}

// Same body as QuerySoundLength; a distinct exe copy.
// @0x1427457a0
unsigned QuerySoundLengthCopy(void* soundSource)
{
    if (FMOD::Sound* sound = SoundForLength(soundSource))
    {
        unsigned length = 0;
        if (sound->getLength(&length, 8) == 0)
            return length;
    }
    return 0;
}

// retains the executable's sample-unit query and conversion to seconds.
// @0x1427457e0
float QuerySoundDuration(void* soundSource)
{
    if (FMOD::Sound* sound = SoundForLength(soundSource))
    {
        unsigned length = 0;
        if (sound->getLength(&length, 1) == 0)
            return static_cast<float>(length) / 1000.0f;
    }
    return 0.0f;
}

// SoundSampleFMODImplAux's fields, from pSound at +0x30.
struct Sfr22AuxSample
{
    void* m_pad[6];
    FMOD::Sound* pSound;
    void* m_pad38;
    void* pStreamer;  // AuxStreamer: GetPCMData is slot 1
    UInt32 Channels;
    UInt32 SampleRate;
    unsigned Bits;
    UByte* pBlockBuffer;
    unsigned BlockSize;
    unsigned SoundLength;
    int Format;
    unsigned FillPosition;
    unsigned TotatBytesRead;
};

// SoundSampleFMODImplAux::ReadAndFillSound: reads one PCM block, reorders 5.1 channels for FMOD, writes both lock
// regions, and advances the ring offsets.
// @0x142745f50
unsigned FUN_142745f50(void* player)
{
    Sfr22AuxSample* self = static_cast<Sfr22AuxSample*>(player);
    void* ptr1, *ptr2;
    unsigned len1, len2;
    unsigned got_bytes = reinterpret_cast<unsigned (*)(void*, UByte*, unsigned)>((*reinterpret_cast<void***>(self->pStreamer))[1])(
        self->pStreamer, self->pBlockBuffer, self->BlockSize);

    if (got_bytes < self->BlockSize)
        std::memset(&self->pBlockBuffer[got_bytes], 0, self->BlockSize - got_bytes);

    if (self->Channels == 6)
    {
        // CRI:  L,R,Ls,Rs,C,LFE
        // FMOD: L,R,C,LFE,Ls,Rs
        if (self->Format == 5)  // FMOD_SOUND_FORMAT_PCMFLOAT
        {
            float tmp;
            float* psample = (float*)self->pBlockBuffer;
            for (UPInt i = 0; i < got_bytes / 4; i += 6)
            {
                tmp = psample[i + 2]; psample[i + 2] = psample[i + 4]; psample[i + 4] = tmp;
                tmp = psample[i + 3]; psample[i + 3] = psample[i + 5]; psample[i + 5] = tmp;
            }
        }
        else
        {
            UInt16 tmp;
            UInt16* psample = (UInt16*)self->pBlockBuffer;
            for (UPInt i = 0; i < got_bytes / 2; i += 6)
            {
                tmp = psample[i + 2]; psample[i + 2] = psample[i + 4]; psample[i + 4] = tmp;
                tmp = psample[i + 3]; psample[i + 3] = psample[i + 5]; psample[i + 5] = tmp;
            }
        }
    }

    if (FUN_1428d8ea8(self->pSound, self->FillPosition, self->BlockSize, &ptr1, &ptr2, &len1, &len2) == 0)  // lock
    {
        if (self->BlockSize > len1)
        {
            std::memcpy(ptr1, self->pBlockBuffer, len1);
            if (self->BlockSize - len1 > len2)
            {
                std::memcpy(ptr2, self->pBlockBuffer + len1, len2);
            }
            else
            {
                std::memcpy(ptr2, self->pBlockBuffer + len1, self->BlockSize - len1);
                std::memset(((UByte*)ptr2) + (self->BlockSize - len1), 0, len2 - (self->BlockSize - len1));
            }
        }
        else
        {
            std::memcpy(ptr1, self->pBlockBuffer, self->BlockSize);
            std::memset(((UByte*)ptr1) + self->BlockSize, 0, len1 - self->BlockSize);
            std::memset(ptr2, 0, len2);
        }
        if (FUN_1428d8eae(self->pSound, ptr1, ptr2, len1, len2) != 0)  // unlock
            return 0;
    }

    self->TotatBytesRead += got_bytes;
    self->FillPosition += got_bytes;
    if (self->FillPosition >= self->SoundLength)
        self->FillPosition -= self->SoundLength;
    return got_bytes;
}

// Null-checks the channel and returns the isPlaying flag without checking the FMOD result, like the executable.
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

// ImageData::SetPixelInScanline / GetPixelInScanline (hidden Color return) and
// AppendableSoundData::SetReadPosition, called through the real members.
inline void FUN_14257d390(void* image, long long line, unsigned x, unsigned color)
{
    static_cast<Scaleform::Render::ImageData*>(image)->SetPixelInScanline(
        reinterpret_cast<Scaleform::UByte*>(line), x, color);
}
inline void FUN_14257bf70(void* image, void* ret, long long line, unsigned x)
{
    ::new (ret) Scaleform::Render::Color(static_cast<Scaleform::Render::ImageData*>(image)->GetPixelInScanline(
        reinterpret_cast<const Scaleform::UByte*>(line), x));
}
inline bool FUN_1427483a0(void* stream, int pos)
{
    return static_cast<Scaleform::Sound::AppendableSoundData*>(stream)->SetReadPosition(static_cast<unsigned>(pos));
}
namespace Scaleform { namespace GFx {
unsigned long FUN_142748160(void*, void*, unsigned long);
void FUN_142742830(unsigned long long**, const unsigned long long*);
} }
inline unsigned long long FUN_142748160(void* stream, void* buffer, unsigned bytes)
{
    return Scaleform::GFx::FUN_142748160(stream, buffer, bytes);
}
inline void FUN_142742830(long long* set, unsigned long long* key)
{
    Scaleform::GFx::FUN_142742830(reinterpret_cast<unsigned long long**>(set), key);
}

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

namespace Scaleform { namespace Render {
struct DICommandContext; class Texture;
// The DrawableImage fields the Noise command reads (Transparent at +0x48) and its channel bits.
struct Sfr22NoiseImage
{
    enum { Channel_Red = 0x01, Channel_Green = 0x02, Channel_Blue = 0x04, Channel_Alpha = 0x08 }; enum { Operator_LT, Operator_LE, Operator_GT, Operator_GE, Operator_EQ, Operator_NE };
    UByte Pad[0x48];
    bool  Transparent;
    bool  IsTransparent() const { return Transparent; }
};
struct DICommand_Compare
{
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    const Sfr22NoiseImage* pImage; const Sfr22NoiseImage* pSource; UByte Pad18[0x28]; const Sfr22NoiseImage* pImageCompare1; // +8 / +0x10 / +0x40
};
struct DICommand_Threshold
{
    typedef Sfr22NoiseImage DrawableImage;
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    virtual void ExecuteHWCopyAction(DICommandContext& context, Texture** tex, const Matrix2F* texgen) const;
    const Sfr22NoiseImage* pImage; const Sfr22NoiseImage* pSource; Rect<SInt32> SourceRect; Point<SInt32> DestPoint; UByte Pad30[0x10]; // +8 / +0x10 / +0x18 / +0x28
    int Operation; UInt32 Threshold; UInt32 ThresholdColor; UInt32 Mask; // +0x40 / +0x44 / +0x48 / +0x4c
};
struct DICommand_Merge
{
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    const Sfr22NoiseImage* pImage; const Sfr22NoiseImage* pSource; Rect<SInt32> SourceRect; Point<SInt32> DestPoint; UByte Pad30[0x10];
    UInt32 RedMultiplier, GreenMultiplier, BlueMultiplier, AlphaMultiplier; // +0x40..+0x4c
};
struct DICommand_Scroll
{
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    virtual void ExecuteHWCopyAction(DICommandContext& context, Texture** tex, const Matrix2F* texgen) const;
    const Sfr22NoiseImage* pImage; const Sfr22NoiseImage* pSource; Rect<SInt32> SourceRect; Point<SInt32> DestPoint; // +8 / +0x10 / +0x18 / +0x28
};
struct DICommand_CopyChannel
{
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    const Sfr22NoiseImage* pImage; const Sfr22NoiseImage* pSource; Rect<SInt32> SourceRect; Point<SInt32> DestPoint; UByte Pad30[0x10];
    int SourceChannel, DestChannel; // +0x40 / +0x44 (DrawableImage::ChannelBits)
};
struct DICommand_PaletteMap
{
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    virtual void ExecuteHWCopyAction(DICommandContext& context, Texture** tex, const Matrix2F* texgen) const;
    static const unsigned ChannelSize = 256 * sizeof(UInt32);
    const Sfr22NoiseImage* pImage; const Sfr22NoiseImage* pSource; Rect<SInt32> SourceRect; Point<SInt32> DestPoint; UByte Pad30[0x10];
    UInt32* Channels; unsigned ChannelMask; // +0x40 / +0x48
};
struct Sfr22SourceRect { virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const = 0; const Sfr22NoiseImage* pImage; const Sfr22NoiseImage* pSource; Rect<SInt32> SourceRect; Point<SInt32> DestPoint; UByte Pad30[0x10]; }; // SDK DICommand_SourceRect
struct DICommand_CopyPixels : Sfr22SourceRect
{
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    const Sfr22NoiseImage* pAlphaSource; Point<SInt32> AlphaPoint; bool MergeAlpha; // +0x40 / +0x48 / +0x50
};
struct DICommand_ColorTransform : Sfr22SourceRect
{
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    Cxform Cx; // +0x40 (16-aligned: in a base-less struct it would push the fields past the vptr)
};
struct DICommand_FloodFill
{
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const; const Sfr22NoiseImage* pImage; Point<SInt32> Pt; Color FillColor; // +8 / +0x10 / +0x18
};
struct DICommand_PerlinNoise
{
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const; const Sfr22NoiseImage* pImage; float FrequencyX, FrequencyY; unsigned NumOctaves, RandomSeed; bool Stitch, FractalNoise; unsigned ChannelMask; bool GrayScale; float Offsets[32]; unsigned OffsetCount; // +8 .. +0xac
};
struct DICommand_FillRect
{
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
};
struct DICommand_Clear
{
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
};
struct DICommand_Noise
{
    typedef Sfr22NoiseImage DrawableImage;
    virtual void ExecuteSW(DICommandContext& context, ImageData& dest, ImageData** src = 0) const;
    const DrawableImage* pImage; // +0x08 (Ptr<DrawableImage>)
    unsigned RandomSeed;         // +0x10
    unsigned Low;
    unsigned High;
    unsigned ChannelMask;
    bool     GrayScale;          // +0x20
};
} }
template<class T> static __forceinline T Sfr22Clamp(const T v, const T minVal, const T maxVal) { return Scaleform::Alg::Max<T>(minVal, Scaleform::Alg::Min<T>(v, maxVal)); } // SDK Alg::Clamp
static __forceinline Scaleform::UByte Sfr22MapChannelIndex(int channel) { if (channel <= 8) return ChannelIndexMap[channel]; return 0xFF; } // SDK MapChannelIndex
static __forceinline void Sfr22GetRGBA(const Scaleform::Render::Color& c, Scaleform::UByte* pr, Scaleform::UByte* pg, Scaleform::UByte* pb, Scaleform::UByte* pa) { c.GetRGB(pr, pg, pb); *pa = c.GetAlpha(); } // SDK Color::GetRGBA
static __forceinline const Scaleform::Render::Rect<Scaleform::SInt32> Sfr22RectPlus(const Scaleform::Render::Rect<Scaleform::SInt32>& r, const Scaleform::Render::Point<Scaleform::SInt32>& pt) { return Scaleform::Render::Rect<Scaleform::SInt32>(r).Offset(pt); }
// SDK DICommand_SourceRect::CalculateDestClippedRect (the exe inlines it into the ExecuteSW bodies; 0x142675bb0 is its out-of-line copy).
template<class C> static __forceinline bool Sfr22CalcDestClippedRect(const C& c, const Scaleform::Render::ImageData& src, const Scaleform::Render::ImageData& dest, const Scaleform::Render::Rect<Scaleform::SInt32>& srcRect, Scaleform::Render::Rect<Scaleform::SInt32>& dstClippedRect, Scaleform::Render::Point<Scaleform::SInt32>& delta)
{   using namespace Scaleform; using namespace Scaleform::Render;
    delta = c.DestPoint - srcRect.TopLeft(); Rect<SInt32> srcImageRect(src.GetSize()); Rect<SInt32> dstImageRect(dest.GetSize()); Rect<SInt32> srcClippedRect;
    if (!srcImageRect.IntersectRect(&srcClippedRect, srcRect)) return false;
    if (!Sfr22RectPlus(srcClippedRect, delta).IntersectRect(&dstClippedRect, dstImageRect)) return false;
    return true; }

// DICommand_Compare::ExecuteSW: the per-pixel difference image, including the optional alpha comparison.
// @0x142676190
void Scaleform::Render::DICommand_Compare::ExecuteSW(Scaleform::Render::DICommandContext&, Scaleform::Render::ImageData& dest, Scaleform::Render::ImageData** psrc) const
{
    // SDK body (Render_DrawableImage_SW.cpp) with plane scanlines in place of the swizzler contexts.
    const ImageData& src0 = *psrc[0];
    const ImageData& src1 = *psrc[1];
    ImagePlane d, s[2];
    dest.GetPlane(0, &d);
    src0.GetPlane(0, &s[0]);
    src1.GetPlane(0, &s[1]);

    for (unsigned y = 0; y < src0.GetSize().Height; ++y)
    {
        UByte* dline = d.GetScanline(y);
        const UByte* s0line = s[0].GetScanline(y);
        const UByte* s1line = s[1].GetScanline(y);

        for (unsigned x = 0; x < src0.GetSize().Width; ++x)
        {
            Color s0Col = src0.GetPixelInScanline(s0line, x);
            Color s1Col = src1.GetPixelInScanline(s1line, x);

            UByte s0Alpha = pSource->IsTransparent() ? s0Col.GetAlpha() : 255;
            UByte s1Alpha = pImageCompare1->IsTransparent() ? s1Col.GetAlpha() : 255;

            UByte delta[4] = { (UByte)(s0Col.GetRed()   - s1Col.GetRed()),
                               (UByte)(s0Col.GetGreen() - s1Col.GetGreen()),
                               (UByte)(s0Col.GetBlue()  - s1Col.GetBlue()),
                               (UByte)(s0Alpha          - s1Alpha) };
            if (delta[0] == 0 && delta[1] == 0 && delta[2] == 0 && delta[3] != 0)
            {
                delta[0] = 0xff;
                delta[1] = 0xff;
                delta[2] = 0xff;
            }
            else
            {
                delta[3] = 0xff;
            }

            Color dCol(delta[0], delta[1], delta[2], delta[3]);

            if (!pImage->IsTransparent())
                delta[3] = 0xff;

            dest.SetPixelInScanline(dline, x, dCol.ToColor32());
        }
    }
}

// MS2-FUNCTIONAL: permanent: threshold (the SDK body without the swizzler contexts); frame layout only: ours spills delta to home slots and drops r12, the exe keeps delta.x in r12 and sCol at rsp+0x20.
// @0x142677ea0
void Scaleform::Render::DICommand_Threshold::ExecuteSW(Scaleform::Render::DICommandContext&, Scaleform::Render::ImageData& dest, Scaleform::Render::ImageData** psrc) const
{
    const ImageData& src = *psrc[0];
    ImagePlane d, s;
    dest.GetPlane(0, &d);
    src.GetPlane(0, &s);
    Point<SInt32> delta;
    Rect<SInt32> dstClippedRect;
    if (!Sfr22CalcDestClippedRect(*this, src, dest, SourceRect, dstClippedRect, delta))
        return;
    SInt32 x, y;
    for (y = dstClippedRect.y1; y < dstClippedRect.y2; y++)
    {
        UByte* dline = dest.GetScanline(y);
        const UByte* sline = s.GetScanline(y - delta.y);

        for (x = dstClippedRect.x1; x < dstClippedRect.x2; x++)
        {
            Color sCol = src.GetPixelInScanline(sline, x - delta.x);
            UInt32 rVal = Threshold & Mask;
            UInt32 lVal = sCol.ToColor32() & Mask;

            bool compareSuccess = false;
            switch (Operation)
            {
            case DrawableImage::Operator_EQ: compareSuccess = (lVal == rVal); break;
            case DrawableImage::Operator_GE: compareSuccess = (lVal >= rVal); break;
            case DrawableImage::Operator_GT: compareSuccess = (lVal > rVal); break;
            case DrawableImage::Operator_LE: compareSuccess = (lVal <= rVal); break;
            case DrawableImage::Operator_LT: compareSuccess = (lVal < rVal); break;
            case DrawableImage::Operator_NE: compareSuccess = (lVal != rVal); break;
            }

            if (!pSource->IsTransparent())
                sCol.SetAlpha(255);
            UInt32 outColor = compareSuccess ? ThresholdColor : sCol.ToColor32();

            if (!pImage->IsTransparent())
                outColor |= (UInt32)255 << 24;

            dest.SetPixelInScanline(dline, x, outColor);
        }
    }
}

// MS2-FUNCTIONAL: merge (the SDK body without the swizzler contexts); frame layout only: ours saves rsi at rsp+0x110, the exe at 0x118 (it never uses the rcx home slot).
// @0x142676ef0
void Scaleform::Render::DICommand_Merge::ExecuteSW(Scaleform::Render::DICommandContext& context, Scaleform::Render::ImageData& dest, Scaleform::Render::ImageData** psrc) const
{
    const ImageData& src = *psrc[0];
    ImagePlane d, s;
    dest.GetPlane(0, &d);
    src.GetPlane(0, &s);
    Point<SInt32> delta;
    Rect<SInt32> dstClippedRect;
    if (!Sfr22CalcDestClippedRect(*this, src, dest, SourceRect, dstClippedRect, delta))
        return;

    SInt32 x, y, channel;
    for (y = dstClippedRect.y1; y < dstClippedRect.y2; y++)
    {
        UByte* dline = dest.GetScanline(y);
        const UByte* sline = s.GetScanline(y - delta.y);
        for (x = dstClippedRect.x1; x < dstClippedRect.x2; x++)
        {
            Color sCol = src.GetPixelInScanline(sline, x - delta.x);
            Color dCol = dest.GetPixelInScanline(dline, x);
            UInt32 factors[4] = { RedMultiplier, GreenMultiplier, BlueMultiplier, AlphaMultiplier };
            UInt32 sChan[4] = { sCol.GetRed(), sCol.GetGreen(), sCol.GetBlue(), sCol.GetAlpha() };
            UInt32 dChan[4] = { dCol.GetRed(), dCol.GetGreen(), dCol.GetBlue(), dCol.GetAlpha() };
            UByte bChan[4];

            if (!pSource->IsTransparent())
                sChan[3] = 255;
            if (!pImage->IsTransparent())
                dChan[3] = 255;
            for (channel = 0; channel < 4; channel++)
                bChan[channel] = (UByte)((sChan[channel] * factors[channel] + dChan[channel] * (256 - factors[channel])) >> 8);
            if (!pImage->IsTransparent())
                bChan[3] = 255;
            Color blendedCol(bChan[0], bChan[1], bChan[2], bChan[3]);
            dest.SetPixelInScanline(dline, x, blendedCol.ToColor32());
        }
    }
}

// MS2-FUNCTIONAL: permanent: scroll (the SDK body without the swizzler contexts); frame layout only: ours packs delta and sCol into home slots, the exe keeps them at rsp+0x20.. and shrink-wraps r15.
// Copies back to front (so an overlapping self-copy works) and forces opaque alpha when either side lacks
// alpha.
// @0x142677c70
void Scaleform::Render::DICommand_Scroll::ExecuteSW(Scaleform::Render::DICommandContext&, Scaleform::Render::ImageData& dest, Scaleform::Render::ImageData** psrc) const
{
    const ImageData& src = *psrc[0];
    ImagePlane d, s;
    dest.GetPlane(0, &d);
    src.GetPlane(0, &s);

    // dst(x,y) = src(x,y) + destPt - SourceRect.TopLeft
    Point<SInt32> delta = DestPoint - SourceRect.TopLeft();


    Rect<SInt32> srcImageRect(src.GetSize());
    Rect<SInt32> dstImageRect(dest.GetSize());
    Rect<SInt32> srcClippedRect, dstClippedRect;

    if (!srcImageRect.IntersectRect(&srcClippedRect, SourceRect))
        return;
    if (!Sfr22RectPlus(srcClippedRect, delta).IntersectRect(&dstClippedRect, dstImageRect))
        return;

    SInt32 x, y;
    for (y = dstClippedRect.y2 - 1; y >= dstClippedRect.y1; y--)
    {
        UByte* dline = dest.GetScanline(y);
        const UByte* sline = s.GetScanline(y - delta.y);

        for (x = dstClippedRect.x2 - 1; x >= dstClippedRect.x1; x--)
        {
            Color sCol = src.GetPixelInScanline(sline, x - delta.x);

            if (!pSource->IsTransparent() || !pImage->IsTransparent())
                sCol.SetAlpha(255);

            dest.SetPixelInScanline(dline, x, sCol.ToColor32());
        }
    }
}

// MS2-FUNCTIONAL: permanent: copyChannel (the SDK body without the swizzler contexts); register allocation and callee-saved spill slots differ (the exe never uses the rcx home slot).
// @0x142676380
void Scaleform::Render::DICommand_CopyChannel::ExecuteSW(Scaleform::Render::DICommandContext&, Scaleform::Render::ImageData& dest, Scaleform::Render::ImageData** psrc) const
{
    const ImageData& src = *psrc[0];
    ImagePlane d, s;
    dest.GetPlane(0, &d);
    src.GetPlane(0, &s);
    Point<SInt32> delta;
    Rect<SInt32> dstClippedRect;
    if (!Sfr22CalcDestClippedRect(*this, src, dest, SourceRect, dstClippedRect, delta))
        return;

    SInt32 x, y;
    UByte sCI = Sfr22MapChannelIndex(SourceChannel);
    UByte dCI = Sfr22MapChannelIndex(DestChannel);
    if ((sCI == 0xFF) || (dCI == 0xFF))
        return;

    for (y = dstClippedRect.y1; y < dstClippedRect.y2; y++)
    {
        UByte* dline = d.GetScanline(y);
        const UByte* sline = s.GetScanline(y - delta.y);
        for (x = dstClippedRect.x1; x < dstClippedRect.x2; x++)
        {
            Color dCol = dest.GetPixelInScanline(dline, x);
            Color sCol = src.GetPixelInScanline(sline, x - delta.x);
            UByte dChannels[4] = { dCol.GetRed(), dCol.GetGreen(), dCol.GetBlue(), dCol.GetAlpha() };
            UByte sChannels[4] = { sCol.GetRed(), sCol.GetGreen(), sCol.GetBlue(), sCol.GetAlpha() };
            if (!pSource->IsTransparent())
                sChannels[3] = 255;
            dChannels[dCI] = sChannels[sCI];
            if (!pImage->IsTransparent())
                dChannels[3] = 255;
            dCol.SetRGBA(dChannels[0], dChannels[1], dChannels[2], dChannels[3]);
            dest.SetPixelInScanline(dline, x, dCol.ToColor32());
        }
    }
}

// MS2-FUNCTIONAL: permanent: paletteMap (the SDK body without the swizzler contexts); register allocation of the channel loop and scanline pointers differs.
// @0x142677460
void Scaleform::Render::DICommand_PaletteMap::ExecuteSW(Scaleform::Render::DICommandContext&, Scaleform::Render::ImageData& dest, Scaleform::Render::ImageData** psrc) const
{
    const ImageData& src = *psrc[0];
    ImagePlane d, s;
    dest.GetPlane(0, &d);
    src.GetPlane(0, &s);
    Point<SInt32> delta;
    Rect<SInt32> dstClippedRect;
    if (!Sfr22CalcDestClippedRect(*this, src, dest, SourceRect, dstClippedRect, delta))
        return;

    SInt32 x, y, channel;
    for (y = dstClippedRect.y1; y < dstClippedRect.y2; y++)
    {
        UByte* dline = dest.GetScanline(y);
        const UByte* sline = s.GetScanline(y - delta.y);
        for (x = dstClippedRect.x1; x < dstClippedRect.x2; x++)
        {
            Color sCol = src.GetPixelInScanline(sline, x - delta.x);
            if (!pSource->IsTransparent())
                sCol.SetAlpha(255);
            UByte rgba[4];
            UInt32 outCols[4];
            UInt32 total = 0;
            Sfr22GetRGBA(sCol, rgba + 0, rgba + 1, rgba + 2, rgba + 3);
            outCols[3] = rgba[3] << 24;
            outCols[0] = rgba[0] << 16;
            outCols[1] = rgba[1] << 8;
            outCols[2] = rgba[2];
            for (channel = 0; channel < 4; channel++)
            {
                if (ChannelMask & (1 << channel))
                    outCols[channel] = Channels[channel*(ChannelSize/sizeof(UInt32)) + rgba[channel]];
                total += outCols[channel];
            }
            if (!pImage->IsTransparent())
                total |= (UInt32)255 << 24;
            Color dCol(total);
            dest.SetPixelInScanline(dline, x, dCol.ToColor32());
        }
    }
}

// MS2-FUNCTIONAL: permanent: copyPixels (the SDK body without the swizzler contexts, ImageData scanlines as in the exe); scheduling of the two inlined clips and the frame size differ (ours 0x80, the exe 0x90).
// @0x142676660
void Scaleform::Render::DICommand_CopyPixels::ExecuteSW(Scaleform::Render::DICommandContext& context, Scaleform::Render::ImageData& dest, Scaleform::Render::ImageData** psrc) const
{
    ImageData& src = *psrc[0];

    Rect<SInt32> dstClippedRect;
    Point<SInt32> delta, deltaAlpha;
    if (!Sfr22CalcDestClippedRect(*this, src, dest, SourceRect, dstClippedRect, delta))
        return;

    bool alphaImage = pAlphaSource != 0;
    ImageData& alphaSrc = alphaImage ? *psrc[1] : *psrc[0];

    int x, y;
    if (alphaImage)
    {
        if (!Sfr22CalcDestClippedRect(*this, alphaSrc, dest, Rect<SInt32>(AlphaPoint.x, AlphaPoint.y, SourceRect.GetSize()), dstClippedRect, deltaAlpha))
            return;
    }
    else
    {
        deltaAlpha = delta;
    }

    for (y = dstClippedRect.y1; y < dstClippedRect.y2; y++)
    {
        UByte* dline = dest.GetScanline(y);
        const UByte* sline = src.GetScanline(y - delta.y);

        const UByte* aline = alphaSrc.GetScanline(y - deltaAlpha.y);
        for (x = dstClippedRect.x1; x < dstClippedRect.x2; x++)
        {

            Color s = src.GetPixelInScanline(sline, x - delta.x);
            if (!pSource->IsTransparent())
                s.SetAlpha(255);

            Color alpha = alphaImage ? alphaSrc.GetPixelInScanline(aline, x - deltaAlpha.x) : s;
            Color d = dest.GetPixelInScanline(dline, x);
            Color final = s;

            UByte alphaIn = s.GetAlpha();
            SInt32 secAlpha = (alphaImage ? (alpha.GetAlpha() + 1) : 256);
            UByte srcAlpha = (UByte)((alphaIn * secAlpha) >> 8);
            UByte dstAlpha = d.GetAlpha();
            UByte outAlpha = srcAlpha;
            if (MergeAlpha)
            {
                outAlpha = (UByte)((0xFF - srcAlpha) * (dstAlpha / 255.0f) + srcAlpha); // SDK Alg::Lerp<UByte, float>
            }
            if (!pImage->IsTransparent())
            {
                outAlpha = 255;
            }

            final = Color::Blend(d, s, (float)srcAlpha / (float)outAlpha);
            final.SetAlpha(outAlpha);

            dest.SetPixelInScanline(dline, x, final.ToColor32());
        }
    }
}

// MS2-FUNCTIONAL: colorTransform (the SDK body without the swizzler contexts); one operand order left in the inlined clip: ours lea eax,[rdx+rsi], the exe [rsi+rdx].
// @0x142675d30
void Scaleform::Render::DICommand_ColorTransform::ExecuteSW(Scaleform::Render::DICommandContext& context, Scaleform::Render::ImageData& dest, Scaleform::Render::ImageData** psrc) const
{
    const ImageData& src = *psrc[0];
    ImagePlane d, s;
    dest.GetPlane(0, &d);
    src.GetPlane(0, &s);

    Point<SInt32> delta;
    Rect<SInt32> dstClippedRect;
    if (!Sfr22CalcDestClippedRect(*this, src, dest, SourceRect, dstClippedRect, delta))
        return;

    // If the image is not transparent, then the Cxform multiplies all components by the alpha offset + alpha multiplier.
    Cxform cx = Cx;
    if (!pImage->IsTransparent())
    {
        float falpha = cx.M[0][3] + cx.M[1][3];
        for (int i = 0; i < 3; ++i)
        {
            cx.M[0][i] *= falpha;
            cx.M[1][i] *= falpha;
        }
        cx.M[0][3] = 1.0f;
        cx.M[1][3] = 0.0f;
    }

    SInt32 x, y;
    for (y = dstClippedRect.y1; y < dstClippedRect.y2; y++)
    {
        UByte* dline = dest.GetScanline(y);
        const UByte* sline = s.GetScanline(y - delta.y);

        for (x = dstClippedRect.x1; x < dstClippedRect.x2; x++)
        {
            Color sCol = src.GetPixelInScanline(sline, x - delta.x);
            if (!pSource->IsTransparent())
                sCol.SetAlpha(255);

            // Note: More or less a duplicate of the implementation in the Cxform class itself,
            // but requires rescaling by 256 rather than 255 in order to be pixel-exact. Using
            // Cxform.Transform causes the resulting colors to be off by 1 in
            // test_bitmapdata_colorTransform.swf.
            float rgbaM[4] = { ((float)sCol.GetRed()   / 255.0f) * cx.M[0][0],
                               ((float)sCol.GetGreen() / 255.0f) * cx.M[0][1],
                               ((float)sCol.GetBlue()  / 255.0f) * cx.M[0][2],
                               ((float)sCol.GetAlpha() / 255.0f) * cx.M[0][3] };
            Color dCol(
                (UByte)Sfr22Clamp<float>((rgbaM[0] + cx.M[1][0]) * 256.0f, 0, 255),
                (UByte)Sfr22Clamp<float>((rgbaM[1] + cx.M[1][1]) * 256.0f, 0, 255),
                (UByte)Sfr22Clamp<float>((rgbaM[2] + cx.M[1][2]) * 256.0f, 0, 255),
                (UByte)Sfr22Clamp<float>((rgbaM[3] + cx.M[1][3]) * 256.0f, 0, 255));

            if (!pImage->IsTransparent())
                dCol.SetAlpha(255);

            dest.SetPixelInScanline(dline, x, dCol.ToColor32());
        }
    }
}

struct Sfr22FillPoint { Scaleform::SInt32 x, y; Sfr22FillPoint() { } Sfr22FillPoint(Scaleform::SInt32 x2, Scaleform::SInt32 y2) { x = x2; y = y2; } Sfr22FillPoint(const Sfr22FillPoint& pt) { x = pt.x; y = pt.y; } }; // SDK Point<SInt32> (empty default ctor)
// MS2-FUNCTIONAL: permanent: SDK floodFill; the exe hoists the overwriteColor load past the out-of-TU GetPixel (LTCG mod-ref) and reloads dest, ours keeps dest in rbx
// @0x142676bd0
void Scaleform::Render::DICommand_FloodFill::ExecuteSW(Scaleform::Render::DICommandContext&, Scaleform::Render::ImageData& dest, Scaleform::Render::ImageData**) const
{
    // SDK body (Render_DrawableImage_SW.cpp) with ImageData::GetPixel / SetPixelARGB in place of the swizzler contexts.
    // Check whether the floodfill origin is even within the bounds.
    Rect<SInt32> imageRect = Rect<SInt32>(dest.GetSize());
    if ( !imageRect.Contains(Pt))
        return;

    UInt32 fillColor = FillColor.ToColor32();
    if (!pImage->IsTransparent())
        fillColor |= (UInt32)255 << 24;

    Color overwriteColor = dest.GetPixel(Pt.x, Pt.y);
    Array<Sfr22FillPoint> toProcess;
    toProcess.PushBack(Sfr22FillPoint(Pt.x,Pt.y));
    while (!toProcess.IsEmpty())
    {
        const Sfr22FillPoint pt = toProcess.Back();
        toProcess.PopBack();
        Rect<SInt32> intersection;
        imageRect.IntersectRect(&intersection, Rect<SInt32>(pt.x, pt.y, Size<SInt32>(1,1)));
        if ( intersection.Width() * intersection.Height() > 0 ) // SDK intersection.Area()
        {
            if( overwriteColor == dest.GetPixel(pt.x, pt.y) )
            {
                dest.SetPixelARGB(pt.x, pt.y, fillColor);

                // Generate 4 cardinal directions to continue fill.
                toProcess.PushBack(Sfr22FillPoint(pt.x-1, pt.y));
                toProcess.PushBack(Sfr22FillPoint(pt.x, pt.y-1));
                toProcess.PushBack(Sfr22FillPoint(pt.x, pt.y+1));
                toProcess.PushBack(Sfr22FillPoint(pt.x+1, pt.y));
            }
        }
    }





}

// BitmapData.perlinNoise: per selected channel (red, green, blue, alpha when transparent; grayscale draws red into
// all three colour bytes) one of eight lattice generators is picked from the seed, and every octave cosine-
// interpolates SmoothNoise at the four lattice corners around the (offset) sample point; frequency doubles and
// amplitude halves per octave, the sum is normalised by the total amplitude.
// MS2-FUNCTIONAL: permanent: cl evaluates the fractional_Y corner pair first, the exe (LTCG) the (1 - fractional_Y) pair;
// every operand order of the expression compiles to the same code here. The rest is register and home-slot choice.
// @0x142677740
void Scaleform::Render::DICommand_PerlinNoise::ExecuteSW(Scaleform::Render::DICommandContext&, Scaleform::Render::ImageData& dest, Scaleform::Render::ImageData**) const
{
    // Prime sets of the eight generators (exe 0x143191a90): row stride and polynomial coefficients.
    static const int NoisePrimeFactors[8][4] = {
        {67, 19937, 178757, 7978189}, {97, 21701, 100511, 2200591}, {73, 23209, 499321, 9218263},
        {19, 44497, 422861, 6200351}, {59, 43261, 300589, 9299317}, {17, 33461, 475333, 1200809},
        {23, 96557, 457117, 6267011}, {43, 28657, 199669, 2299553},
    };
    // Grayscale only uses the red channel (copied to green and blue), and possibly alpha.
    unsigned channelMask = ChannelMask;
    if ( GrayScale )
    {
        channelMask &= ~(Sfr22NoiseImage::Channel_Green|Sfr22NoiseImage::Channel_Blue);
        channelMask |= Sfr22NoiseImage::Channel_Red;
    }

    for ( unsigned y = 0; y < dest.GetSize().Height; ++y )
    {
        UByte* line = dest.GetScanline(y);
        for ( unsigned x = 0; x < dest.GetSize().Width; ++x )
        {
            Color color(0xFF000000);
            bool transparent = pImage->IsTransparent();
            unsigned channelCount = transparent ? 4 : 3;
            for ( unsigned channel = 0; channel < channelCount; ++channel )
            {
                // Skip channels that are not in the mask.
                if ( (channelMask & (1<<channel)) != 0 )
                {
                PerlinGenerator generator = *reinterpret_cast<const PerlinGenerator*>(NoisePrimeFactors[((RandomSeed + channel) * -3) & 7]);
                float freqX = 2.0f / FrequencyX;
                float freqY = 2.0f / FrequencyY;
                float noise = 0;
                float fmax = 0;
                float amplitude = 1.0f;
                for ( unsigned octave = 0; octave < NumOctaves; ++octave )
                {
                    float fx = x * freqX;
                    float fy = y * freqY;
                    if ( octave < OffsetCount )
                    {
                        fx += Offsets[octave*2+0];
                        fy += Offsets[octave*2+1];
                    }
                    // InterpolatedNoise: cosine interpolation of SmoothNoise at the four lattice corners.
                    int   integer_X    = int(fx);
                    int   integer_Y    = int(fy);
                    float fractional_X = (float)((1 - cos((double)((fx - integer_X) * 3.1415927f))) * .5);
                    float fractional_Y = (float)((1 - cos((double)((fy - integer_Y) * 3.1415927f))) * .5);
                    float interp = (generator.SmoothNoise(integer_X, integer_Y) * (1 - fractional_X)
                                  + generator.SmoothNoise(integer_X + 1, integer_Y) * fractional_X) * (1 - fractional_Y)
                                 + (generator.SmoothNoise(integer_X, integer_Y + 1) * (1 - fractional_X)
                                  + generator.SmoothNoise(integer_X + 1, integer_Y + 1) * fractional_X) * fractional_Y;
                    noise += (1 + interp) * 0.5f * amplitude;
                    freqX *= 2;
                    freqY *= 2;
                    fmax += amplitude;
                    amplitude /= 2;
                }
                noise /= fmax;

                if ( GrayScale && channel != 3 )
                    color.SetRGBFloat(noise, noise, noise);
                else
                {
                    UByte v = (UByte)(255*noise);
                    switch(channel)
                    {
                    case 1: color.SetGreen(v); break;
                    case 2: color.SetBlue (v); break;
                    case 3: color.SetAlpha(v); break;
                    default: color.SetRed (v); break;
                    }
                }
                }
            }
            if ( !transparent )
                color.SetAlpha(255);
            dest.SetPixelInScanline(line, x, color.ToColor32());
        }
    }
}





namespace Scaleform {
// Master channel group volume, 1.0 when the group cannot be fetched.
// @0x142745840
float QueryMasterVolume(void* player)
{
    float volume = 1.0f;
    void* group;   // getMasterChannelGroup out-param, only read on FMOD_OK
    if (FUN_1428d8e9c(*reinterpret_cast<void**>(static_cast<char*>(player) + 0x10), &group) == 0)
        FUN_1428d8f26(group, &volume);
    return volume;
}

// Mirrors the channel null check and reads the pan value through the executable wrapper.
// @0x1427458b0
float QueryChannelPan(void* player)
{
    void* channel = *reinterpret_cast<void**>(static_cast<char*>(player) + 0x38);
    float pan = 0.0f;
    if (channel)
        FUN_1428d8eea(channel, &pan);
    return pan;
}

// The sound read count is initialized to zero and returned only for a non-null sound.
// @0x142745880
unsigned ReadSoundData(void* player, void* buffer, unsigned bytes)
{
    void* sound = *reinterpret_cast<void**>(static_cast<char*>(player) + 0x30);
    unsigned read = 0;
    if (sound)
        FUN_1428d8ec0(sound, buffer, bytes, &read);
    return read;
}

// Returns the channel volume when present, otherwise the executable's default of one.
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
// Channel position in seconds, less the stream start offset; both FMOD position queries are kept.
struct Sfr22ChannelPlayerView
{
    float QueryChannelTime();
    // Stream start offset in ms; the exe does not guard the zero sample rate.
    unsigned StartOffset()
    {
        void* soundSource = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x30);
        if (soundSource) {
            void* metadata = *reinterpret_cast<void**>(static_cast<char*>(soundSource) + 0x38);
            if (metadata)
                return static_cast<unsigned>(*reinterpret_cast<int*>(static_cast<char*>(metadata) + 0x1c) * 1000)
                     / *reinterpret_cast<unsigned*>(static_cast<char*>(metadata) + 0x14);
        }
        return 0;
    }
};

// @0x1427458e0
float Sfr22ChannelPlayerView::QueryChannelTime()
{
    auto* bytes = reinterpret_cast<unsigned char*>(this);
    void* channel = *reinterpret_cast<void**>(bytes + 0x38);
    unsigned position = 0;
    unsigned offset = 0;
    if (channel) {
        offset = StartOffset();
        reinterpret_cast<FMOD::Channel*>(channel)->getPosition(&position, 1);
        unsigned dspPosition = 0;
        (*reinterpret_cast<FMOD::Channel**>(bytes + 0x38))->getPosition(&dspPosition, 4);
    }
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
// MS2-FUNCTIONAL: register allocation differs (the exe holds the min edge in the other operand).
// DICommand_SourceRect::CalculateDestClippedRect: clips the source rectangle against the
// source image, then shifts it by DestPoint - TopLeft and clips it against the destination.
// @0x142675bb0
bool ClipImageRect(void* command, void* firstImage, void* secondImage, const int* requested,
                   unsigned* clipped, int* originDelta)
{
    const Render::Rect<SInt32>& srcRect = *reinterpret_cast<const Render::Rect<SInt32>*>(requested);
    Render::Rect<SInt32>& dstClippedRect = *reinterpret_cast<Render::Rect<SInt32>*>(clipped);
    Render::Point<SInt32>& delta = *reinterpret_cast<Render::Point<SInt32>*>(originDelta);
    const Render::Point<SInt32>& destPoint =
        *reinterpret_cast<const Render::Point<SInt32>*>(static_cast<char*>(command) + 0x28);
    delta = destPoint - srcRect.TopLeft();

    Render::Rect<SInt32> srcImageRect(static_cast<Render::ImageData*>(firstImage)->GetSize());
    Render::Rect<SInt32> dstImageRect(static_cast<Render::ImageData*>(secondImage)->GetSize());


    Render::Rect<SInt32> srcClippedRect;

    if (!srcImageRect.IntersectRect(&srcClippedRect, srcRect))
        return false;
    if (!Sfr22RectPlus(srcClippedRect, delta).IntersectRect(&dstClippedRect, dstImageRect))
        return false;
    return true;
}
}


namespace Scaleform {
// reports channels, integer default frequency, and the executable's supported-format flag.
// @0x142745ac0
bool QuerySoundFormat(void* player, unsigned* formatFlag, int* channels, int* frequency)
{
    // the sound member is re-read after each FMOD call
    void* const& sound = *reinterpret_cast<void**>(static_cast<char*>(player) + 0x30);
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
    *frequency = static_cast<int>(static_cast<unsigned>(defaultFrequency));
    if (soundFormat == 2)
        *formatFlag = 0;
    else if (soundFormat == 5)
        *formatFlag = 1;
    else
        return false;
    return true;
}
}


namespace Scaleform {
// Gets the master channel group and applies the requested mute state on success.
// @0x142745e70
void SetMasterMuted(void* player, bool muted)
{
    void* system = *reinterpret_cast<void**>(static_cast<char*>(player) + 0x10);
    void* group;   // getMasterChannelGroup out-param, only read on FMOD_OK
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
// DetachChannelCallback's body; DetachChannelNode inlines it for a node's owner.
static __forceinline void DetachChannelCallbackInline(void** object)
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

// Unregisters the callback and user data, then clears the channel reference.
// @0x142746180
void DetachChannelCallback(void** object)
{
    DetachChannelCallbackInline(object);
}

// Clears the owner's channel registration while it is still referenced, then unlinks this node from its
// intrusive list. The node is at owner + 0x10, so the owner's RefCount is at node - 8 (the exe loads it into a
// register before the test, as a volatile read does).
// @0x142746230
void DetachChannelNode(void* node)
{
    auto* bytes = static_cast<unsigned char*>(node);
    if (*reinterpret_cast<volatile int*>(bytes - 8) > 0)
        DetachChannelCallbackInline(reinterpret_cast<void**>(bytes - 0x10));
    *reinterpret_cast<void**>(bytes + 0x18) = nullptr;
    if (*reinterpret_cast<void**>(bytes + 0x10)) {
        *reinterpret_cast<void**>(*reinterpret_cast<char**>(bytes + 8) + 0x10) = *reinterpret_cast<void**>(bytes + 0x10);
        *reinterpret_cast<void**>(*reinterpret_cast<char**>(bytes + 0x10) + 8) = *reinterpret_cast<void**>(bytes + 8);
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


// @0x14268a040
void GFx::AMP::MovieFunctionStats::DebugPrint() const
{
    for (UPInt i = 0; i < FunctionTimings.GetSize(); ++i)
    {
        String entry;
        String name;
        FunctionDescMap::ConstIterator descIt;
        descIt = FunctionInfo.Find(FunctionTimings[i].FunctionId);
        if (descIt != FunctionInfo.End())
        {
            name = descIt->Second->Name;
        }
        String parentName;
        descIt = FunctionInfo.Find(FunctionTimings[i].CallerId);
        if (descIt != FunctionInfo.End())
        {
            parentName = descIt->Second->Name;
        }
        Scaleform::Format(entry, "{0} ({1}) from {2} ({3}): {4} times\n", name.ToCStr(), FunctionTimings[i].FunctionId, parentName.ToCStr(), FunctionTimings[i].CallerId, FunctionTimings[i].TimesCalled);
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
// Locks the sound region at offset zero, clears the first segment, and unlocks it.
// @0x142744600
void ClearSoundBuffer(void* player)
{
    auto* bytes = static_cast<unsigned char*>(player);
    void* first;   // Sound::lock out-params, only read on FMOD_OK
    void* second;
    unsigned firstLength;
    unsigned secondLength;
    if (FUN_1428d8ea8(*reinterpret_cast<void**>(bytes + 0x30), 0, *reinterpret_cast<unsigned*>(bytes + 0x64),
                      &first, &second, &firstLength, &secondLength) == 0) {
        memset(first, 0, firstLength);
        FUN_1428d8eae(*reinterpret_cast<void**>(bytes + 0x30), first, second, firstLength, secondLength);
    }
}
}


namespace Scaleform {
static __forceinline const Scaleform::Render::Matrix2F Sfr22MulInline(const Scaleform::Render::Matrix2F& m1, const Scaleform::Render::Matrix2F& m2)
{
    return Scaleform::Render::Matrix2F(m1).Prepend(m2);
}

// DICommand_Scroll::ExecuteHWCopyAction: copies the scrolled texture back through the HAL, then sets the blend mode.
// @0x142675790
void Scaleform::Render::DICommand_Scroll::ExecuteHWCopyAction(Scaleform::Render::DICommandContext& context, Scaleform::Render::Texture** tex, const Scaleform::Render::Matrix2F* texgen) const
{
    void* const& pHAL = reinterpret_cast<void* const*>(&context)[1];  // pHAL
    // HAL virtuals: +0x1e0 GetViewportScaling, +0x188 DrawableCopyback, +0x118 applyBlendMode
    Matrix2F mvp = Sfr22MulInline(Matrix2F::Scaling(2, reinterpret_cast<float (*)(void*)>((*reinterpret_cast<void***>(pHAL))[0x1e0 / sizeof(void*)])(pHAL) * 2),
                                  Matrix2F::Translation(-0.5f, -0.5f));
    reinterpret_cast<void (*)(void*, Texture*, const Matrix2F&, const Matrix2F&)>((*reinterpret_cast<void***>(pHAL))[0x188 / sizeof(void*)])(
        pHAL, tex[0], mvp, texgen[1]);
    // applyBlendModeImpl(pImage->IsTransparent() ? Blend_OverwriteAll : Blend_Overwrite, sourceAc = true, forceAc = true)
    reinterpret_cast<void (*)(void*, unsigned, bool, bool)>((*reinterpret_cast<void***>(pHAL))[0x118 / sizeof(void*)])(
        pHAL, static_cast<unsigned>(*reinterpret_cast<const unsigned char*>(reinterpret_cast<const unsigned char*>(
            *reinterpret_cast<void* const*>(reinterpret_cast<const unsigned char*>(this) + 8)) + 0x48) != 0) + 0x0f, true, true);
}

// DICommand_FillRect::ExecuteSW: clips ApplyRect to the image and fills it, opaque unless the image is transparent.
// @0x142676ac0
void Scaleform::Render::DICommand_FillRect::ExecuteSW(Scaleform::Render::DICommandContext&, Scaleform::Render::ImageData& imageRef, Scaleform::Render::ImageData**) const
{
    void* command = const_cast<Scaleform::Render::DICommand_FillRect*>(this);
    void* image = &imageRef;
    // DICommand_FillRect::ExecuteSW: ApplyRect at +0x10, FillColor at +0x20, pImage at +8.
    auto* bytes = static_cast<unsigned char*>(command);
    Render::ImageData& dest = *static_cast<Render::ImageData*>(image);
    const Render::Rect<SInt32>& applyRect = *reinterpret_cast<const Render::Rect<SInt32>*>(bytes + 0x10);
    const Render::ImageSize destSize = dest.GetSize();
    Render::Rect<SInt32> dstImageRect(0, 0, static_cast<SInt32>(destSize.Width), static_cast<SInt32>(destSize.Height));
    Render::Rect<SInt32> clippedRect;
    if (!dstImageRect.IntersectRect(&clippedRect, applyRect))
        return;

    UInt32 fillColor = *reinterpret_cast<UInt32*>(bytes + 0x20);
    if (!*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(*reinterpret_cast<void**>(bytes + 8)) + 0x48))
        fillColor |= (UInt32)255 << 24;

    int x, y;
    for (y = clippedRect.y1; y < clippedRect.y2; y++)
    {
        UByte* row = dest.GetScanline(y);
        for (x = clippedRect.x1; x < clippedRect.x2; x++)
            FUN_14257d390(image, reinterpret_cast<long long>(row), static_cast<unsigned>(x), fillColor);
    }
}

// DICommand_Clear::ExecuteSW: fills every pixel through the image write helper with the stored color.
// @0x142675ca0
void Scaleform::Render::DICommand_Clear::ExecuteSW(Scaleform::Render::DICommandContext&, Scaleform::Render::ImageData& imageRef, Scaleform::Render::ImageData**) const
{
    void* command = const_cast<Scaleform::Render::DICommand_Clear*>(this);
    void* image = &imageRef;
    Render::ImageData* data = static_cast<Render::ImageData*>(image);
    const unsigned color = *reinterpret_cast<unsigned*>(static_cast<char*>(command) + 0x10);
    for (unsigned y = 0; y < data->GetHeight(); ++y) {
        UByte* row = data->GetScanline(y);
        for (unsigned x = 0; x < data->GetWidth(); ++x)
            FUN_14257d390(image, reinterpret_cast<long long>(row), x, color);
    }
}

}



namespace Scaleform {
// Closes the callback stream with the executable's common state reset helper.
// @0x142745410
unsigned long long CloseAudioStream(void*, void* stream)
{
    FUN_1427483a0(stream, 0);
    return 0;
}

// Initializes a callback stream, stores its handle and the executable's 0x0fffffff limit.
// @0x142745430
unsigned long long OpenAudioStream(void* stream, void*, unsigned* length, void*, void** handle)
{
    FUN_1427483a0(stream, 0);
    *handle = stream;
    *length = 0x0fffffff;
    return 0;
}

// FMOD userseek callback (exinfo +0x90): seeks the stream to pos, error value 20 on failure.
// @0x142745490
unsigned long long ValidateAudioStream(void*, void* position, void* stream)
{
    // The second argument is FMOD's unsigned seek position; the exe passes it through in edx.
    const int pos = static_cast<int>(reinterpret_cast<std::uintptr_t>(position));
    return FUN_1427483a0(stream, pos) == 0 ? 20 : 0;
}
}


namespace Scaleform {
// Reads callback bytes from the fifth-argument stream state and reports the count.
// @0x142745470
unsigned long long ReadAudioCallback(void*, void* buffer, unsigned bytes, unsigned* bytesRead, void* stream)
{
    *bytesRead = static_cast<unsigned>(FUN_142748160(stream, buffer, bytes));
    return 0;
}
}


namespace Scaleform {
// @0x1427453b0
FMOD_RESULT CreateAudioSound(void* player, void* request, FMOD::Sound** sound)
{
    auto* requestBytes = static_cast<unsigned char*>(request);
    const unsigned flags = !((UByte)(*reinterpret_cast<unsigned*>(requestBytes + 0x10) >> 12) & 1) ? 0x4040u : 0xc0u;
    const FMOD_RESULT result = reinterpret_cast<FMOD::System*>(*reinterpret_cast<void**>(*reinterpret_cast<char**>(static_cast<char*>(player) + 0x28) + 0x10))->createSound(*reinterpret_cast<char**>(requestBytes + 0x20), flags, nullptr, sound);
    if (result != 0) {
        *sound = nullptr;
        return result;
    }
    return static_cast<FMOD_RESULT>(0);
}
}


namespace Scaleform {
// Validates the encoded sample format, prepares the 0xd8-byte FMOD info block, and creates the sound.
// @0x1427452e0
FMOD_RESULT CreateAudioSoundFromRequest(void* player, void* request, FMOD::Sound** sound)
{
    auto* requestBytes = static_cast<unsigned char*>(request);
    FMOD_CREATESOUNDEXINFO info;
    memset(&info, 0, sizeof(info));
    const unsigned format = *reinterpret_cast<unsigned*>(requestBytes + 0x10);
    info.cbsize = sizeof(info);
    unsigned flags;
    switch (format & 0x700) {
    case 0x100:
        flags = 0x1a001040;
        info.format = ((format & 7) == 2) + 1;       // Sample_16: FMOD PCM16, else PCM8
        info.defaultfrequency = *reinterpret_cast<int*>(requestBytes + 0x14);
        info.numchannels = (format & 8) ? 2 : 1;  // Sample_Stereo
        break;
    case 0x200:
        flags = 0x1a000240;
        info.format = 0xb;
        break;
    default:
        return static_cast<FMOD_RESULT>(0x19);
    }
    info.length = *reinterpret_cast<unsigned*>(requestBytes + 0x28);
    return reinterpret_cast<FMOD::System*>(*reinterpret_cast<void**>(*reinterpret_cast<char**>(static_cast<char*>(player) + 0x28) + 0x10))->createSound(*reinterpret_cast<char**>(requestBytes + 0x20), flags, &info, sound);
}
}


namespace Scaleform {
// Constructs the callback-backed FMOD stream descriptor for the two accepted request formats.
// @0x1427450b0
FMOD_RESULT CreateBufferedAudioStream(void* player, const char* path, FMOD::Sound** sound)
{
    FMOD_CREATESOUNDEXINFO info;
    memset(&info, 0, sizeof(info));
    const unsigned format = *reinterpret_cast<const unsigned*>(path + 0x10);
    unsigned mode = 0x2002040;
    info.cbsize = sizeof(info);
    info.length = 0x0fffffff;
    switch (format & 0x700) {
    case 0x100:
        info.format = ((format & 7) == 2) + 1;  // Sample_16: FMOD PCM16, else PCM8
        info.defaultfrequency = *reinterpret_cast<const int*>(path + 0x14);
        info.numchannels = (format & 8) ? 2 : 1;  // Sample_Stereo
        mode = 0x2003040;
        break;
    case 0x200:
        info.format = 0xb;
        break;
    default:
        return static_cast<FMOD_RESULT>(0x19);
    }
    info.decodebuffersize = 0x2000;
    info.useropen = reinterpret_cast<void*>(&OpenAudioStream);
    info.userclose = reinterpret_cast<void*>(&CloseAudioStream);
    info.userread = reinterpret_cast<void*>(&ReadAudioCallback);
    info.userseek = reinterpret_cast<void*>(&ValidateAudioStream);
    return reinterpret_cast<FMOD::System*>(*reinterpret_cast<void**>(static_cast<char*>(player) + 0x10))->createStream(path, mode, &info, sound);
}

// Resolves the stream owner and writes the created FMOD stream into the request record.
// @0x142744680
bool CreateRequestAudioStream(void* request)
{
    auto* bytes = static_cast<unsigned char*>(request);
    if (void* owner = *reinterpret_cast<void**>(bytes + 0x38))
        return CreateBufferedAudioStream(owner, *reinterpret_cast<const char**>(bytes + 0x28), reinterpret_cast<FMOD::Sound**>(bytes + 0x30)) == 0;
    return false;
}
}


namespace Scaleform {
// MS2-FUNCTIONAL: sets the FMOD file callbacks, metadata fields, loop settings, and format-specific mode.
// @0x1427451c0
FMOD_RESULT CreateMetadataAudioSound(void* player, const char* path, FMOD::Sound** sound)
{
    FMOD_CREATESOUNDEXINFO info;
    memset(&info, 0, sizeof(info));
    const unsigned format = *reinterpret_cast<const unsigned*>(path + 0x10);
    info.cbsize = sizeof(info);
    info.useropen = reinterpret_cast<void*>(&OpenAudioStream);
    info.userclose = reinterpret_cast<void*>(&CloseAudioStream);
    info.userread = reinterpret_cast<void*>(&ReadAudioCallback);
    info.userseek = reinterpret_cast<void*>(&ValidateAudioStream);
    info.decodebuffersize = 0x1000;
    unsigned mode = 0xa0000c0;
    switch (format & 0x700) {
    case 0x100:
        info.format = ((format & 7) == 2) + 1;  // Sample_16: FMOD PCM16, else PCM8
        info.numchannels = (format & 8) ? 2 : 1;  // Sample_Stereo
        mode = 0xa0010c0;
        break;
    case 0x200:
        info.format = 0xb;
        break;
    default:
        return static_cast<FMOD_RESULT>(0x19);
    }
    info.defaultfrequency = *reinterpret_cast<const int*>(path + 0x14);
    info.initialseekposition = *reinterpret_cast<const unsigned*>(path + 0x1c);
    info.initialseekpostype = 2;
    return reinterpret_cast<FMOD::System*>(*reinterpret_cast<void**>(*reinterpret_cast<char**>(static_cast<char*>(player) + 0x28) + 0x10))->createSound(path, mode, &info, sound);
}
}


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


static SF_INLINE void Sfr22ReserveGH(void** array, const void* pheapAddr, std::size_t requested);
struct Sfr22GlobalPtrSlot { void* p; }; struct Sfr22VideoPlayerSlot { void* p; };
// 0x142678170 is the SDK ArrayDataBase<T, AllocatorGH<T, 2>, ArrayDefaultPolicy>::Reserve for an 8-byte T (local stand-in
// Sfr22GlobalPtrSlot); the exe has one copy per element type. It has no callers outside the exe vtables.
template void Scaleform::ArrayDataBase<Sfr22GlobalPtrSlot, Scaleform::AllocatorGH<Sfr22GlobalPtrSlot, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void* pheapAddr, Scaleform::UPInt newCapacity);
// MS2-PIN: ?Reserve@?$ArrayDataBase@USfr22GlobalPtrSlot@Scaleform@@U?$AllocatorGH@USfr22GlobalPtrSlot@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x142678170 ; unique
//
//




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

inline unsigned long long FUN_1425e3480() { return Scaleform::Timer::GetProfileTicks(); }

namespace Scaleform {


}

namespace Scaleform {

}


namespace Scaleform {
// serializes pause changes, updates paused timestamps, and pulses the completion event on resume.
// @0x142745eb0
void SetAudioPaused(void* player, bool paused)
{
    auto* bytes = static_cast<unsigned char*>(player);
    Lock::Locker locker(reinterpret_cast<Lock*>(bytes + 0x70));
    bool& pausedFlag = *reinterpret_cast<bool*>(bytes + 0x68);
    if (pausedFlag != paused) {
        void* channel = *reinterpret_cast<void**>(bytes + 0x38);
        if (channel)
            FUN_1428d8ed8(channel, paused);
        pausedFlag = paused;
        const long long now = static_cast<long long>(FUN_1425e3480());
        if (paused) {
            *reinterpret_cast<long long*>(bytes + 0x50) = now;
            *reinterpret_cast<long long*>(bytes + 0x58) += now - *reinterpret_cast<long long*>(bytes + 0x48);
        } else {
            *reinterpret_cast<long long*>(bytes + 0x48) = now;
            // the manager (+0x28) wakes its worker through the Event at +0x20
            auto* manager = *reinterpret_cast<unsigned char**>(bytes + 0x28);
            reinterpret_cast<Scaleform::Event*>(manager + 0x20)->PulseEvent();
        }
    }
}

// computes elapsed playback time under the player's lock and clamps/records the audio end time.
// @0x142745980
float QueryAudioElapsedSeconds(void* player)
{
    auto* bytes = static_cast<unsigned char*>(player);
    Lock::Locker locker(reinterpret_cast<Lock*>(bytes + 0x70));
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
        if (elapsed > duration) {
            bytes[0x69] = 1;
            *reinterpret_cast<std::uint64_t*>(bytes + 0x50) = now;
            *reinterpret_cast<std::uint64_t*>(bytes + 0x58) = duration;
            elapsedSeconds = *reinterpret_cast<float*>(bytes + 0x98) +
                             static_cast<float>(duration) / 1000000.0f;
        } else {
            elapsedSeconds = *reinterpret_cast<float*>(bytes + 0x98) +
                             static_cast<float>(elapsed) / 1000000.0f;
        }
    } else {
        elapsedSeconds = *reinterpret_cast<float*>(bytes + 0x98) +
                         static_cast<float>(*reinterpret_cast<std::uint64_t*>(bytes + 0x58)) / 1000000.0f;
    }
    return elapsedSeconds;
}

// The sample's sound data (SoundDataBase): the sample count at +0x18 and the seek sample at +0x1c, read through the
// SDK's inline getters.
struct Sfr22SoundData
{
    void* m_pad[3];
    unsigned Length;
    unsigned SeekSample;
    unsigned GetSampleCount() const { return Length; }
    unsigned GetSeekSample() const { return SeekSample; }
};

// SoundChannelFMODImpl::Loop: applies the loop bounds in samples and schedules the channel's loop delay from the DSP clock.
// @0x142745c80
void ConfigureAudioLoop(void* player, int loopCount, float startSeconds, float endSeconds)
{
    auto* bytes = static_cast<unsigned char*>(player);
    auto*& channel = *reinterpret_cast<FMOD::Channel**>(bytes + 0x38);
    if (!channel || loopCount == 0)
        return;
    if (loopCount > 1) {
        FUN_1428d8f02(channel, 2);
        FUN_1428d8f08(channel, loopCount);
    }

    auto*& request = *reinterpret_cast<unsigned char**>(bytes + 0x30);
    const Scaleform::Ptr<Sfr22SoundData>& metadata = *reinterpret_cast<Scaleform::Ptr<Sfr22SoundData>*>(request + 0x38);
    const unsigned loopStart = metadata ? metadata->GetSeekSample() : 0;
    unsigned loopLength = metadata ? metadata->GetSampleCount() : 0;
    unsigned length = 0;
    (*reinterpret_cast<FMOD::Sound**>(request + 0x30))->getLength(&length, 2);
    float frequency;
    FUN_1428d8eb4(*reinterpret_cast<FMOD::Sound**>(request + 0x30), &frequency, nullptr, nullptr, nullptr);
    const unsigned start = startSeconds > 0.0f ? static_cast<unsigned>(static_cast<long long>(frequency * startSeconds)) : loopStart;
    unsigned end = static_cast<unsigned>(static_cast<long long>(frequency * endSeconds));
    if (end == 0 || end > length - 1) {
        if (loopLength > 0)
            end = start + loopLength;
        else
            end = length - 1;
    }
    FUN_1428d8ef6(channel, start, 2);
    FUN_1428d8f0e(channel, start, 2, end, 2);

    auto*& manager = *reinterpret_cast<unsigned char**>(bytes + 0x28);
    unsigned clockHigh = 0, clockLow = 0;
    FUN_1428d8ea2(*reinterpret_cast<FMOD::System**>(manager + 0x10), &clockHigh, &clockLow);
    // the delay reuses the length local, as the exe stores it back to that slot
    length = static_cast<unsigned>(static_cast<long long>(static_cast<float>((end - start) * loopCount) *
                                                          (*reinterpret_cast<float*>(manager + 0xf4) / frequency)));
    clockHigh += (clockLow + length) < clockLow;  // FMOD_64BIT_ADD
    clockLow += length;
    FUN_1428d8ef0(channel, 2, clockHigh, clockLow);
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
            auto*& sound = *reinterpret_cast<FMOD::Sound**>(bytes + 0x20);
            if (sound)
                sound->release();
            sound = nullptr;
            if (*reinterpret_cast<void**>(bytes + 0x10)) {
                *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(bytes + 8) + 0x10) = *reinterpret_cast<void**>(bytes + 0x10);
                *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(bytes + 0x10) + 8) = *reinterpret_cast<void**>(bytes + 8);
                *reinterpret_cast<void**>(bytes + 8) = nullptr;
                *reinterpret_cast<void**>(bytes + 0x10) = nullptr;
            }
            if (InterlockedDecrement(references) == 0) {
                void** object = reinterpret_cast<void**>(bytes - 0x10);
                if (object)
                    reinterpret_cast<void (*)(void*, unsigned)>((*reinterpret_cast<void***>(object))[0])(object, 1);
            }
            return;
        }
        count = *references;
    }
    if (*reinterpret_cast<void**>(bytes + 0x10)) {
        *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(bytes + 8) + 0x10) = *reinterpret_cast<void**>(bytes + 0x10);
        *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(bytes + 0x10) + 8) = *reinterpret_cast<void**>(bytes + 8);
        *reinterpret_cast<void**>(bytes + 8) = nullptr;
        *reinterpret_cast<void**>(bytes + 0x10) = nullptr;
    }
}

// Player sound record as a List node: prev/next at +8/+0x10 point at other records.
struct Sfr22ListNodeView
{
    void* pVtbl;
    Sfr22ListNodeView* pPrev;
    Sfr22ListNodeView* pNext;
};

// Clears a player sound's callback data, drops its FMOD sound when referenced, and detaches its list node.
// @0x142746380
void ClearPlayerSoundRecord(void* request)
{
    auto* bytes = static_cast<unsigned char*>(request);
    const long refCount = *reinterpret_cast<volatile long*>(bytes - 8);   // atomic refcount
    *reinterpret_cast<void**>(bytes + 0x28) = nullptr;
    if (refCount > 0) {
        auto* sound = *reinterpret_cast<FMOD::Sound**>(bytes + 0x20);
        if (sound)
            sound->release();
        *reinterpret_cast<FMOD::Sound**>(bytes + 0x20) = nullptr;
    }
    auto* node = reinterpret_cast<Sfr22ListNodeView*>(bytes);
    if (node->pNext) {
        node->pPrev->pNext = node->pNext;   // list RemoveNode: both links re-read
        node->pNext->pPrev = node->pPrev;
        node->pPrev = nullptr;
        node->pNext = nullptr;
    }
}

// Scaleform AllocInfo: the stat id handed to MemoryHeap::Alloc.
struct Sfr22AllocInfo
{
    unsigned StatId;
    Sfr22AllocInfo(unsigned statId) : StatId(statId) {}
};

// ArrayDataBase<void*, AllocatorGH, ArrayDefaultPolicy>::Reserve; the exe has one copy per element type.
static SF_INLINE void Sfr22ReserveGH(void** array, const void* pheapAddr, std::size_t requested)
{
    // ArrayDataBase::Reserve with granularity 4 on the global heap.
    if (requested == 0) {
        if (array[0]) {
            reinterpret_cast<void (*)(void*, void*)>((*reinterpret_cast<void***>(DAT_143b15f60))[12])(DAT_143b15f60, array[0]);
            array[0] = nullptr;
        }
        array[2] = nullptr;
    } else {
        requested = (requested + 3) / 4 * 4;
        if (array[0]) {
            array[0] = reinterpret_cast<void* (*)(void*, void*, std::size_t)>((*reinterpret_cast<void***>(DAT_143b15f60))[11])(
                DAT_143b15f60, array[0], sizeof(void*) * requested);
        } else {
            array[0] = reinterpret_cast<void* (*)(void*, std::size_t, const Sfr22AllocInfo&)>((*reinterpret_cast<void***>(DAT_143b15f60))[10])(
                DAT_143b15f60, sizeof(void*) * requested, Sfr22AllocInfo(2));
        }
        array[2] = reinterpret_cast<void*>(requested);
    }
}

// 0x1427463e0 is Reserve for the VideoPlayerImpl* array (stand-in Sfr22VideoPlayerSlot). sfr_as2_01g / sfr_kernel_03o
// call it through this out-of-line wrapper.
#pragma inline_depth(0)
void ReserveVideoPlayerArray(void** array, void* heap, std::size_t requested) { reinterpret_cast<Scaleform::ArrayDataBase<Sfr22VideoPlayerSlot, Scaleform::AllocatorGH<Sfr22VideoPlayerSlot, 2>, Scaleform::ArrayDefaultPolicy>*>(array)->Reserve(heap, requested); }
#pragma inline_depth()
// MS2-PIN: ?Reserve@?$ArrayDataBase@USfr22VideoPlayerSlot@Scaleform@@U?$AllocatorGH@USfr22VideoPlayerSlot@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1427463e0 ; unique

// Initializes an empty hash table at eight slots and doubles it when live entries exceed its 80 percent load threshold.
// @0x142689ec0
void CheckExpandAS3HashSet(void** set, void* owner)
{
    // the CheckExpand of the function-stats hash (one body with this hash's in the exe)
    reinterpret_cast<Ms2FuncStatsSetBase*>(set)->CheckExpand(owner);
    //
    //
    //
    //
    //
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
// MS2-FUNCTIONAL: permanent: register choice only; the exe hoists the derived vtable and orders the Set hash byte sums differently.
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
// MS2-FUNCTIONAL: permanent: register and frame only; the exe keeps &FunctionInfo in r15, spills this and shrink-wraps r12 (frame 0x90 vs 0x80).
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

// The manager's request table (+0xa8): HashLH<UInt64, ArrayLH<void*> >::Get, the FixedSizeHash
// of the eight key bytes; returns the channel array (entry + 0x18) or null.
typedef HashLH<UInt64, ArrayLH<void*> > Sfr22RequestHash;
// @0x142745630
__declspec(noinline) void* FindAudioRequestEntry(void** set, const unsigned char* key)
{
    return reinterpret_cast<Sfr22RequestHash*>(set)->Get(*reinterpret_cast<const UInt64*>(key));
}

// Removes a finished request from its keyed channel list, pulses completion when the table empties, and stops/releases the channel.
// @0x1427454b0
void RemoveAudioRequest(void* manager, void* request)
{
    if (!request)
        return;
    auto* requestBytes = static_cast<unsigned char*>(request);
    auto* sound = *reinterpret_cast<unsigned char**>(requestBytes + 0x30);
    if (!sound || !*reinterpret_cast<unsigned long long*>(sound + 0x40))
        return;

    auto* managerBytes = static_cast<unsigned char*>(manager);
    reinterpret_cast<Lock*>(managerBytes + 0x80)->DoLock();
    // SDK SoundRendererFMODImpl::DetachAuxStreamer: explicit DoLock / Unlock, pchan nulled when not found.

        auto** set = reinterpret_cast<void**>(managerBytes + 0xa8);
        unsigned long long key = *reinterpret_cast<unsigned long long*>(sound + 0x40), removeKey;
        auto* entry = static_cast<unsigned long long*>(FindAudioRequestEntry(set,
            reinterpret_cast<const unsigned char*>(&key)));
        bool removed = false;
        if (entry) {
            std::size_t emptyCount = 0;
            for (std::size_t i = 0; i < entry[1]; ++i) {
                auto** channels = reinterpret_cast<void**>(entry[0]);
                if (channels[i] == request) {
                    channels[i] = nullptr;
                    removed = true;
                }
                if (!reinterpret_cast<void**>(entry[0])[i])
                    ++emptyCount;
            }
            if (emptyCount == entry[1]) {
                removeKey = *reinterpret_cast<unsigned long long*>(sound + 0x40);
                FUN_142742830(reinterpret_cast<long long*>(set), &removeKey);
            }

            // Only reached with a found entry (an unknown key skips straight to the unlock, 0x142745525).
            auto* table = *reinterpret_cast<void**>(managerBytes + 0xa8);
            if ((!table || *reinterpret_cast<unsigned long long*>(table) == 0) && managerBytes[0xf1] &&
                *reinterpret_cast<void**>(managerBytes + 0x18)) {
                managerBytes[0x78] = 1;
                if (void* worker = *reinterpret_cast<void**>(managerBytes + 0x18))
                    FUN_14257dcb0(worker);
                *reinterpret_cast<void**>(managerBytes + 0x18) = nullptr;
                reinterpret_cast<Scaleform::Event*>(managerBytes + 0x20)->PulseEvent();
            }
        }
        if (!removed) request = nullptr;

    reinterpret_cast<Lock*>(managerBytes + 0x80)->Unlock();
    if (request) {
        reinterpret_cast<FMOD::Channel*>(*reinterpret_cast<void**>(static_cast<unsigned char*>(request) + 0x38))->stop();
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
    // The exe allocates it with no AllocInfo (r8 = 0), so it lands in the default memory stat.
    auto* object = static_cast<unsigned char*>(reinterpret_cast<void* (*)(void*, std::size_t, const void*)>(heapVtable[10])(
        DAT_143b15f60, 0xf8, nullptr));
    if (object) {
        ::new (static_cast<void*>(object)) Scaleform::RefCountImplCore;
        *reinterpret_cast<void***>(object) = &AS3AudioEventVtable;
        *reinterpret_cast<unsigned long long*>(object + 0x10) = 0;
        *reinterpret_cast<unsigned long long*>(object + 0x18) = 0;
        ::new (static_cast<void*>(object + 0x20)) Scaleform::Event(false, false);
        ::new (static_cast<void*>(object + 0x80)) Scaleform::Lock(0);
        *reinterpret_cast<unsigned long long*>(object + 0xa8) = 0;
        auto* sentinel = object + 0xb0;
        *reinterpret_cast<void***>(sentinel) = &AS3AudioListNodeVtable;
        *reinterpret_cast<void**>(sentinel + 8) = sentinel;
        *reinterpret_cast<void**>(sentinel + 0x10) = sentinel;
        ::new (static_cast<void*>(object + 0xc8)) Scaleform::Lock(0);
        object[0xf0] = 0;
        *reinterpret_cast<unsigned*>(object + 0xf4) = 0;
        object[0x78] = 0;
    }
    return object;
}
// 0x142744fe0 is SoundRendererFMOD::CreateSoundRenderer (gfxsoundfmod's caller names it so); bound to the body above.
#ifndef MS2_HOOK_DLL
#pragma comment(linker, "/alternatename:?CreateSoundRenderer@SoundRendererFMOD@Sound@Scaleform@@SAPEAV123@XZ=?CreateAudioEventManager@Scaleform@@YAPEAXXZ")
#endif

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

// The SDK's file-local CreateSubSound(prenderer, AppendableSoundData*, FMOD::Sound**), inlined into CreateSampleFromData
// (its out-of-line copy is CreateBufferedAudioStream above).
static __forceinline FMOD_RESULT CreateBufferedAudioStreamInl(void* player, const char* path, FMOD::Sound** sound)
{
    FMOD_CREATESOUNDEXINFO info;
    memset(&info, 0, sizeof(info));
    const unsigned format = *reinterpret_cast<const unsigned*>(path + 0x10);
    unsigned mode = 0x2002040;
    info.cbsize = sizeof(info);
    info.length = 0x0fffffff;
    switch (format & 0x700) {
    case 0x100:
        info.format = ((format & 7) == 2) + 1;
        info.defaultfrequency = *reinterpret_cast<const int*>(path + 0x14);
        info.numchannels = (format & 8) ? 2 : 1;
        mode = 0x2003040;
        break;
    case 0x200:
        info.format = 0xb;
        break;
    default:
        return static_cast<FMOD_RESULT>(0x19);
    }
    info.decodebuffersize = 0x2000;
    info.useropen = reinterpret_cast<void*>(&OpenAudioStream);
    info.userclose = reinterpret_cast<void*>(&CloseAudioStream);
    info.userread = reinterpret_cast<void*>(&ReadAudioCallback);
    info.userseek = reinterpret_cast<void*>(&ValidateAudioStream);
    return reinterpret_cast<FMOD::System*>(*reinterpret_cast<void**>(static_cast<char*>(player) + 0x10))->createStream(path, mode, &info, sound);
}

// SwfSoundStreamer::CreateReader: pRenderer (+0x38), pSoundData (+0x28), pSound (+0x30).
static __forceinline bool Sfr22StreamerCreateReader(unsigned char* streamer)
{
    if (void* player = *reinterpret_cast<void**>(streamer + 0x38))
        return CreateBufferedAudioStreamInl(player, *reinterpret_cast<const char**>(streamer + 0x28),
                                            reinterpret_cast<FMOD::Sound**>(streamer + 0x30)) == 0;
    return false;
}

// SwfSoundStreamer::GetSoundFormat
static __forceinline bool Sfr22StreamerGetSoundFormat(unsigned char* streamer, int* fmt, unsigned* channels, unsigned* samplerate)
{
    FMOD::Sound* sound = *reinterpret_cast<FMOD::Sound**>(streamer + 0x30);
    if (!sound)
        return false;
    int format = 0;
    int chans = 0;
    int ret = FUN_1428d8eba(sound, nullptr, &format, &chans, nullptr);
    if (ret != 0)
        return false;
    *channels = chans;
    float frequency = 0.0f;
    ret = FUN_1428d8eb4(*reinterpret_cast<FMOD::Sound**>(streamer + 0x30), &frequency, nullptr, nullptr, nullptr);
    if (ret != 0)
        return false;
    *samplerate = static_cast<unsigned>(frequency);
    if (format == 2)
        *fmt = 0;
    else if (format == 5)
        *fmt = 1;
    else
        return false;
    return true;
}

// SoundSampleFMODImpl::CreateSubSound(SoundFile*): pPlayer (+0x28) -> pDevice (+0x10).
static __forceinline FMOD_RESULT Sfr22SampleCreateFileSound(unsigned char* sample, unsigned char* psd, FMOD::Sound** psound)
{
    unsigned flags = 0x40;
    if (static_cast<UByte>(*reinterpret_cast<unsigned*>(psd + 0x10) >> 12) & 1)
        flags |= 0x80;
    else
        flags |= 0x4000;
    FMOD_RESULT result = (*reinterpret_cast<FMOD::System**>(*reinterpret_cast<unsigned char**>(sample + 0x28) + 0x10))->createSound(
        *reinterpret_cast<const char**>(psd + 0x20), flags, nullptr, psound);
    if (result != 0) {
        *psound = nullptr;
        return result;
    }
    return result;
}

// SoundSampleFMODImpl::CreateSubSound(SoundData*)
static __forceinline FMOD_RESULT Sfr22SampleCreateDataSound(unsigned char* sample, unsigned char* psd, FMOD::Sound** psound)
{
    FMOD_CREATESOUNDEXINFO exinfo;
    memset(&exinfo, 0, sizeof(exinfo));
    exinfo.cbsize = sizeof(exinfo);
    unsigned flags = 0x1a000040;
    switch (*reinterpret_cast<unsigned*>(psd + 0x10) & 0x700) {
    case 0x100:
        exinfo.format = (*reinterpret_cast<unsigned*>(psd + 0x10) & 7) == 2 ? 2 : 1;
        exinfo.defaultfrequency = *reinterpret_cast<int*>(psd + 0x14);
        exinfo.numchannels = (*reinterpret_cast<unsigned*>(psd + 0x10) & 8) ? 2 : 1;
        flags |= 0x1000;
        break;
    case 0x200:
        flags |= 0x200;
        exinfo.format = 0xb;
        break;
    default:
        return static_cast<FMOD_RESULT>(0x19);
    }
    exinfo.length = *reinterpret_cast<unsigned*>(psd + 0x28);
    return (*reinterpret_cast<FMOD::System**>(*reinterpret_cast<unsigned char**>(sample + 0x28) + 0x10))->createSound(
        *reinterpret_cast<const char**>(psd + 0x20), flags, &exinfo, psound);
}

// MS2-FUNCTIONAL: SoundRendererFMODImpl::CreateSampleFromData (SDK 4.2): a callback-fed stream sample becomes a
// SwfSoundStreamer handed to CreateSampleFromAuxStreamer (vtable[4]); any other sample is a SoundSampleFMODImpl
// whose FMOD sound is created from the file name or from the in-memory data.
// Left vs the exe (1199 bytes, ours 1194): cl drops the null test before the final Release (the exe keeps test rsi/je),
// and the streamer's pSoundData store sits one instruction later. A Ptr-like holder keeps the test but moves every register.
// The whole body runs under the manager lock (+0xc8), as in the exe: the request is linked into the list before its FMOD
// sound exists, so leaving the lock early let the update thread see a half-built request.
// @0x1427449f0
void* FUN_1427449f0(void* manager, void* requestData)
{
    if (!requestData)
        return nullptr;
    auto* managerBytes = static_cast<unsigned char*>(manager);
    auto* request = static_cast<unsigned char*>(requestData);
    Lock::Locker locker(reinterpret_cast<Lock*>(managerBytes + 0xc8));

    const unsigned format = *reinterpret_cast<unsigned*>(request + 0x10);
    if ((static_cast<UByte>(format >> 12) & 1) && !(static_cast<UByte>(format >> 13) & 1)) {
        // Ptr<SwfSoundStreamer> pstreamer = *SF_NEW SwfSoundStreamer(this, pasd)
        auto* mem = static_cast<unsigned char*>(Memory::Alloc(0x40));
        unsigned char* streamer;
        if (mem) {
            *reinterpret_cast<void* volatile*>(mem) = DAT_142dc9d48_RefCountImplCore;
            *reinterpret_cast<void* volatile*>(mem) = DAT_1431b80b8;
            auto* node = mem + 0x10;
            auto* sentinel = managerBytes + 0xb0;
            *reinterpret_cast<volatile int*>(mem + 8) = 1;
            *reinterpret_cast<void***>(node) = &AS3AudioListNodeVtable;
            *reinterpret_cast<void**>(node + 0x10) = *reinterpret_cast<void**>(sentinel + 0x10);
            *reinterpret_cast<void**>(node + 8) = sentinel;
            *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(sentinel + 0x10) + 8) = node;
            *reinterpret_cast<void**>(sentinel + 0x10) = node;
            *reinterpret_cast<void***>(mem) = &AS3StreamRequestVtable;
            *reinterpret_cast<void***>(node) = &AS3StreamRequestNodeVtable;
            *reinterpret_cast<int*>(request + 8) += 1;
            *reinterpret_cast<void**>(mem + 0x28) = requestData;
            *reinterpret_cast<void**>(mem + 0x30) = nullptr;
            *reinterpret_cast<void**>(mem + 0x38) = manager;
            streamer = mem;
        } else {
            streamer = nullptr;
        }
        void* returned = nullptr;
        int fmt;
        unsigned channels;
        unsigned samplerate;
        if (Sfr22StreamerCreateReader(streamer) && Sfr22StreamerGetSoundFormat(streamer, &fmt, &channels, &samplerate)) {
            auto** vtable = *reinterpret_cast<void***>(manager);
            returned = reinterpret_cast<void* (*)(void*, void*, unsigned, unsigned, int)>(vtable[4])(
                manager, streamer, channels, samplerate, fmt);
        }
        FUN_14257dcb0(streamer);
        return returned;
    }

    // Ptr<SoundSampleFMODImpl> psample = *SF_NEW SoundSampleFMODImpl(this)
    auto* mem = static_cast<unsigned char*>(Memory::Alloc(0x40));
    unsigned char* sample;
    if (mem) {
        *reinterpret_cast<void**>(mem) = AS3SoundObjectBaseVtable;
        auto* node = mem + 0x10;
        auto* sentinel = managerBytes + 0xb0;
        *reinterpret_cast<volatile int*>(mem + 8) = 1;   // AtomicInt RefCount
        *reinterpret_cast<void***>(node) = &AS3AudioListNodeVtable;
        *reinterpret_cast<void**>(node + 0x10) = *reinterpret_cast<void**>(sentinel + 0x10);
        *reinterpret_cast<void**>(node + 8) = sentinel;
        *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(sentinel + 0x10) + 8) = node;
        *reinterpret_cast<void**>(sentinel + 0x10) = node;
        *reinterpret_cast<void***>(mem) = &AS3SoundRequestVtable;
        *reinterpret_cast<void***>(node) = &AS3SoundRequestNodeVtable;
        *reinterpret_cast<void**>(mem + 0x38) = nullptr;
        *reinterpret_cast<void**>(mem + 0x28) = manager;
        *reinterpret_cast<void**>(mem + 0x30) = nullptr;
        sample = mem;
    } else {
        sample = nullptr;
    }
    // psample->pSoundData = psd (Ptr<SoundDataBase>, NTS refcount)
    *reinterpret_cast<int*>(request + 8) += 1;
    if (*reinterpret_cast<void**>(sample + 0x38))
        static_cast<Scaleform::RefCountNTSImpl*>(*reinterpret_cast<void**>(sample + 0x38))->Release();
    *reinterpret_cast<void**>(sample + 0x38) = requestData;

    bool created = false;
    if (static_cast<UByte>(*reinterpret_cast<unsigned*>(request + 0x10) >> 13) & 1)
        created = (Sfr22SampleCreateFileSound(sample, request, reinterpret_cast<FMOD::Sound**>(sample + 0x30)) == 0);
    else
        created = (Sfr22SampleCreateDataSound(sample, request, reinterpret_cast<FMOD::Sound**>(sample + 0x30)) == 0);
    void* returned = nullptr;
    if (created) {
        InterlockedExchangeAdd(reinterpret_cast<volatile long*>(sample + 8), 1);
        returned = sample;
    }
    if (sample && InterlockedExchangeAdd(reinterpret_cast<volatile long*>(sample + 8), -1) == 1) {
        auto** vtable = *reinterpret_cast<void***>(sample);
        reinterpret_cast<void (*)(void*, unsigned)>(vtable[0])(sample, 1);
    }
    return returned;
}

// creates and links a sound request under the manager lock, then initializes its FMOD sound or stream.
// @0x142744ea0
void* CreateAudioRequest(void* manager, const char* path, bool stream)
{
    auto* managerBytes = static_cast<unsigned char*>(manager);
    unsigned char* object;
    {
        Lock::Locker locker(reinterpret_cast<Lock*>(managerBytes + 0xc8));
        // SF_NEW SoundRequest(manager): the ctor chain stores each base vtable in turn and links
        // the node (+0x10) at the tail of the manager's request list (sentinel +0xb0).
        auto* mem = static_cast<unsigned char*>(Memory::Alloc(0x40));
        if (mem) {
            *reinterpret_cast<void**>(mem) = AS3SoundObjectBaseVtable;
            auto* node = mem + 0x10;
            auto* sentinel = managerBytes + 0xb0;
            *reinterpret_cast<volatile int*>(mem + 8) = 1;   // AtomicInt RefCount
            *reinterpret_cast<void***>(node) = &AS3AudioListNodeVtable;
            *reinterpret_cast<void**>(node + 0x10) = *reinterpret_cast<void**>(sentinel + 0x10);
            *reinterpret_cast<void**>(node + 8) = sentinel;
            *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(sentinel + 0x10) + 8) = node;
            *reinterpret_cast<void**>(sentinel + 0x10) = node;
            *reinterpret_cast<void***>(mem) = &AS3SoundRequestVtable;
            *reinterpret_cast<void***>(node) = &AS3SoundRequestNodeVtable;
            *reinterpret_cast<void**>(mem + 0x38) = nullptr;
            *reinterpret_cast<void**>(mem + 0x28) = manager;
            *reinterpret_cast<void**>(mem + 0x30) = nullptr;
            object = mem;
        } else {
            object = nullptr;
        }
    }
    auto* system = *reinterpret_cast<FMOD::System**>(managerBytes + 0x10);
    auto* sound = reinterpret_cast<FMOD::Sound**>(object + 0x30);
    const auto result = stream
        ? system->createStream(path, 0x49, nullptr, sound)
        : system->createSound(path, 0x49, nullptr, sound);
    if (result != 0) {
        *sound = nullptr;
    // Release, not delete: the request is already linked into the manager's list.
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(object + 8)) == 0) {
            auto** objectVtable = *reinterpret_cast<void***>(object);
            reinterpret_cast<void (*)(void*, unsigned)>(objectVtable[0])(object, 1);
        }
        return nullptr;
    }
    return object;
}

// Builds a linked buffered request, retains its backing data, and creates its callback-fed FMOD sound.
// MS2-FUNCTIONAL: register allocation of the exit: the exe returns through r15 (the null-allocation path sets it from
// the zero register) and restores r13 in each createSound arm; ours returns through r12
// @0x1427447f0
void* CreateBufferedAudioRequest(void* manager, void* backing, unsigned channels, unsigned rate, bool wideSamples)
{
    auto* managerBytes = static_cast<unsigned char*>(manager);
    Lock::Locker locker(reinterpret_cast<Lock*>(managerBytes + 0xc8));
    // SF_NEW BufferedSoundRequest(manager): same ctor chain as CreateAudioRequest, 0x78 bytes.
    auto* object = static_cast<unsigned char*>(Memory::Alloc(0x78));
    if (!object)
        return nullptr;

    *reinterpret_cast<void**>(object) = AS3SoundObjectBaseVtable;
    auto* node = object + 0x10;
    auto* sentinel = managerBytes + 0xb0;
    *reinterpret_cast<volatile int*>(object + 8) = 1;   // AtomicInt RefCount
    *reinterpret_cast<void***>(node) = &AS3AudioListNodeVtable;
    *reinterpret_cast<void**>(node + 0x10) = *reinterpret_cast<void**>(sentinel + 0x10);
    *reinterpret_cast<void**>(node + 8) = sentinel;
    *reinterpret_cast<void**>(*reinterpret_cast<unsigned char**>(sentinel + 0x10) + 8) = node;
    *reinterpret_cast<void**>(sentinel + 0x10) = node;
    *reinterpret_cast<void**>(object + 0x38) = nullptr;
    // volatile: the exe keeps the +0x38 store above the derived vptr store (the ctor-chain order)
    *reinterpret_cast<void** volatile*>(object) = &AS3BufferedRequestVtable;
    *reinterpret_cast<void***>(node) = &AS3BufferedRequestNodeVtable;
    *reinterpret_cast<void**>(object + 0x28) = manager;
    auto* sound = reinterpret_cast<FMOD::Sound**>(object + 0x30);
    *sound = nullptr;
    *reinterpret_cast<void**>(object + 0x40) = nullptr;
    *reinterpret_cast<unsigned*>(object + 0x48) = channels;
    *reinterpret_cast<unsigned*>(object + 0x4c) = rate;
    *reinterpret_cast<void**>(object + 0x58) = nullptr;
    *reinterpret_cast<unsigned*>(object + 0x60) = 0;
    *reinterpret_cast<unsigned long long*>(object + 0x6c) = 0;

    // Ptr<> assignment of the backing data: AddRef the new one, Release the old one.
    if (backing)
        FUN_14257dc30(backing);
    // volatile: the exe re-tests the old data even when backing is null (no threading past the just-stored 0)
    if (void* old = *reinterpret_cast<void* volatile*>(object + 0x40))
        FUN_14257dcb0(old);
    *reinterpret_cast<void**>(object + 0x40) = backing;

    // The exe tests the whole dword of the fifth argument's stack slot, so the parameter is an int there.
    const unsigned wide = *reinterpret_cast<const unsigned*>(&wideSamples);
    const unsigned format = wide == 0 ? 2u : 5u;
    *reinterpret_cast<unsigned*>(object + 0x68) = format;
    const unsigned bits = wide == 0 ? 16u : 32u;
    *reinterpret_cast<unsigned*>(object + 0x50) = bits;
    const unsigned sampleRate = *reinterpret_cast<unsigned*>(object + 0x4c);
    const unsigned channelCount = *reinterpret_cast<unsigned*>(object + 0x48);
    const unsigned length = (sampleRate / 1000u) * (bits >> 3) * channelCount * 0x5dcu;
    *reinterpret_cast<unsigned*>(object + 0x64) = length;

    FMOD_CREATESOUNDEXINFO info;
    std::memset(&info, 0, sizeof(info));
    auto* owner = *reinterpret_cast<unsigned char**>(object + 0x28);
    info.cbsize = sizeof(info);
    info.length = length;
    info.numchannels = channelCount;
    info.defaultfrequency = sampleRate;
    info.format = format;
    auto* system = *reinterpret_cast<FMOD::System**>(owner + 0x10);
    if (system->createSound(nullptr, 0x442, &info, sound) != 0) {
        *sound = nullptr;
    } else {
        unsigned soundLength = 0;
        (*sound)->getLength(&soundLength, 4);
    }
    return object;
}

// Color::SetRGBAFloat (SDK Render_Color.h): SetRGBFloat, then SetAlphaFloat.
static __forceinline void Sfr22SetRGBAFloat(Scaleform::Render::Color& c, float r, float g, float b, float a)
{
    c.SetRGBFloat(r, g, b);
    c.SetAlpha(UByte(a * 255));
}

// Fills every destination pixel with seeded grayscale or masked-channel noise, column by column (the SDK body
// without the swizzler context).
// @0x142677260
void Scaleform::Render::DICommand_Noise::ExecuteSW(Scaleform::Render::DICommandContext&, Scaleform::Render::ImageData& dest, Scaleform::Render::ImageData**) const
{
    Alg::Random::Generator rng;
    rng.SeedRandom(RandomSeed);

    for (unsigned x = 0; x < dest.GetSize().Width; ++x)
    {
        for (unsigned y = 0; y < dest.GetSize().Height; ++y)
        {
            UByte* scanline = dest.GetScanline(y);

            Color c(0);
            if ( GrayScale )
            {
                float val = rng.GetUnitFloat();
                Sfr22SetRGBAFloat(c, val, val, val, ChannelMask & DrawableImage::Channel_Alpha ? rng.GetUnitFloat() : 1.0f);
            }
            else
            {
                if ( ChannelMask & DrawableImage::Channel_Red )
                    c.SetRed((UByte)(rng.GetUnitFloat()*255));
                if ( ChannelMask & DrawableImage::Channel_Green )
                    c.SetGreen((UByte)(rng.GetUnitFloat()*255));
                if ( ChannelMask & DrawableImage::Channel_Blue )
                    c.SetBlue((UByte)(rng.GetUnitFloat()*255));
                if ( ChannelMask & DrawableImage::Channel_Alpha )
                    c.SetAlpha((UByte)(rng.GetUnitFloat()*255));
                else
                    c.SetAlpha(255);
            }

            if (!pImage->IsTransparent())
                c.SetAlpha(255);

            dest.SetPixelInScanline(scanline, x, c.ToColor32());
        }
    }
}

// The destination image as DrawableImage's vftable sees it: GetSize is slot 5.
struct Sfr22ImageView
{
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual Scaleform::Render::ImageSize GetSize() const = 0;
};

// The SDK's header-inline Size operators (Size / Size, Size - Size, Size / scalar).
static inline const Scaleform::Render::Size<float> Sfr22SizeDiv(const Scaleform::Render::Size<float>& s1, const Scaleform::Render::Size<float>& s2)
{
    return Scaleform::Render::Size<float>(s1.Width / s2.Width, s1.Height / s2.Height);
}
static inline const Scaleform::Render::Size<float> Sfr22SizeSub(const Scaleform::Render::Size<float>& s1, const Scaleform::Render::Size<float>& s2)
{
    return Scaleform::Render::Size<float>(s1.Width - s2.Width, s1.Height - s2.Height);
}
static inline const Scaleform::Render::Size<float> Sfr22SizeDiv(const Scaleform::Render::Size<float>& s, float v)
{
    return Scaleform::Render::Size<float>(s.Width / v, s.Height / v);
}

// DICommand_Threshold::ExecuteHWCopyAction (not implemented in the SDK): builds the transform as PaletteMap does, then
// submits the operation, threshold, color, mask, and copy-source flag to the HAL.
// @0x142675870
void Scaleform::Render::DICommand_Threshold::ExecuteHWCopyAction(Scaleform::Render::DICommandContext& context, Scaleform::Render::Texture** tex, const Scaleform::Render::Matrix2F* texgen) const
{
    auto* bytes = reinterpret_cast<const unsigned char*>(this);
    const Rect<SInt32>& sourceRect = *reinterpret_cast<const Rect<SInt32>*>(bytes + 0x18);
    const Point<SInt32>& destPoint = *reinterpret_cast<const Point<SInt32>*>(bytes + 0x28);
    const Sfr22ImageView* const& pImage = *reinterpret_cast<const Sfr22ImageView* const*>(bytes + 8);
    Matrix2F mvp;

    if (reinterpret_cast<bool (*)(const void*)>((*reinterpret_cast<void* const* const*>(this))[11])(this))  // GetRequireSourceRead
    {
        mvp = Sfr22MulInline(Matrix2F::Scaling(2, -2), Matrix2F::Translation(-0.5f, -0.5f));
    }
    else
    {
        mvp.AppendScaling(Sfr22SizeDiv((Size<float>)sourceRect.GetSize(), pImage->GetSize()));
        Size<float> copyOffset = Sfr22SizeDiv(Sfr22SizeSub(Size<float>((float)destPoint.x, (float)destPoint.y),
                                                           Sfr22SizeDiv((Size<float>)pImage->GetSize(), 2.0f)), pImage->GetSize());
        mvp.AppendTranslation(copyOffset.Width, copyOffset.Height);
        mvp.AppendScaling(2.0f, -2.0f);
    }

    // pHAL->DrawableThreshold(tex, texgen, mvp, Operation, Threshold, Color, Mask, CopySource)
    void* hal = reinterpret_cast<void* const*>(&context)[1];
    reinterpret_cast<void (*)(void*, Texture**, const Matrix2F*, const Matrix2F&, unsigned, unsigned, unsigned, unsigned, bool)>((*reinterpret_cast<void***>(hal))[48])(
        hal, tex, texgen, mvp, *reinterpret_cast<const unsigned*>(bytes + 0x40), *reinterpret_cast<const unsigned*>(bytes + 0x44),
        *reinterpret_cast<const unsigned*>(bytes + 0x48), *reinterpret_cast<const unsigned*>(bytes + 0x4c), *reinterpret_cast<const bool*>(bytes + 0x50));
}

// DICommand_PaletteMap::ExecuteHWCopyAction: maps the whole target when the source is read, otherwise positions the
// output at DestPoint in the destination image, then submits the channel table and mask to the HAL.
// @0x142675560
void Scaleform::Render::DICommand_PaletteMap::ExecuteHWCopyAction(Scaleform::Render::DICommandContext& context, Scaleform::Render::Texture** tex, const Scaleform::Render::Matrix2F* texgen) const
{
    auto* bytes = reinterpret_cast<const unsigned char*>(this);
    const Rect<SInt32>& sourceRect = *reinterpret_cast<const Rect<SInt32>*>(bytes + 0x18);
    const Point<SInt32>& destPoint = *reinterpret_cast<const Point<SInt32>*>(bytes + 0x28);
    const Sfr22ImageView* const& pImage = *reinterpret_cast<const Sfr22ImageView* const*>(bytes + 8);
    Matrix2F mvp;

    // If we are rendering to a render target, then we simply render to the whole target. Otherwise, we
    // need to position the output in the destination image properly.
    if (reinterpret_cast<bool (*)(const void*)>((*reinterpret_cast<void* const* const*>(this))[11])(this))  // GetRequireSourceRead
    {
        mvp = Sfr22MulInline(Matrix2F::Scaling(2, -2), Matrix2F::Translation(-0.5f, -0.5f));
    }
    else
    {
        mvp.AppendScaling(Sfr22SizeDiv((Size<float>)sourceRect.GetSize(), pImage->GetSize()));
        Size<float> copyOffset = Sfr22SizeDiv(Sfr22SizeSub(Size<float>((float)destPoint.x, (float)destPoint.y),
                                                           Sfr22SizeDiv((Size<float>)pImage->GetSize(), 2.0f)), pImage->GetSize());
        mvp.AppendTranslation(copyOffset.Width, copyOffset.Height);
        mvp.AppendScaling(2.0f, -2.0f);
    }

    // pHAL->DrawablePaletteMap(tex, texgen, mvp, ChannelMask, Channels)
    void* hal = reinterpret_cast<void* const*>(&context)[1];
    reinterpret_cast<void (*)(void*, Texture**, const Matrix2F*, const Matrix2F&, unsigned, const UInt32*)>((*reinterpret_cast<void***>(hal))[47])(
        hal, tex, texgen, mvp, *reinterpret_cast<const unsigned*>(bytes + 0x48), *reinterpret_cast<const UInt32* const*>(bytes + 0x40));
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

extern "C" void FUN_142747b30(void*);

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

// Byte-identical to 0x142745b70; emitted as a distinct exe copy.
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
typedef Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>, Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>, 2>, Scaleform::ArrayDefaultPolicy> Sfr22FuncTreeArr; // (C3) FUN_14268e600 = its Reserve
// @0x14268e8c0
extern "C" void FUN_14268e8c0(Ms2StringLHArrayBase* locales, Scaleform::UPInt newSize)
{
    typedef Scaleform::AllocatorLH<Scaleform::String, 2> Allocator;
    Scaleform::UPInt oldSize = locales->Size;
    if (newSize < oldSize)
    {
        Allocator::DestructArray(locales->Data + newSize, oldSize - newSize);
        if (newSize < (locales->Policy.GetCapacity() >> 1))
            reinterpret_cast<Sfr22FuncTreeArr*>(locales)->Reserve(locales, newSize);
    }
    else if (newSize >= locales->Policy.GetCapacity())
    {
        reinterpret_cast<Sfr22FuncTreeArr*>(locales)->Reserve(locales, newSize + (newSize >> 2));
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
