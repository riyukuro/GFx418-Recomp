// Recovered Scaleform GFx video player glue from the executable; SDK material is reference only. The Video add-on lib
// part in this unit is VS2008 SP1 code, so the unit builds with cl 15.00.30729 and the vc11 options (MS2-TOOLSET:
// vc9v, cmake/ms2-unit-profiles.cmake). Keep it C++03: no auto, lambdas, range-for, std:: C functions, alias `using`
// (so ExeDecl is a struct), explicit conversion operators or variadic templates. clang-cl compiles it as before.
// MS2-UNIT: sfr_video_03
// MS2-TOOLSET: vc9v
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140016b50-0x14001c000 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define SF_AS3_AVMINTERACTIVEOBJ_DTOR_OUTOFLINE // AvmVideoCharacter ??_G calls it (0x14001b3a0)
#include "../include/video/video_video.h"
#include "../include/video/video_videoplayerimpl.h"
#include "../include/gfx/gfx_stream.h"
#include "../include/gfx/gfx_resource.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/kernel/sf_array.h"
#include "../include/gfx/as3/as3_value.h"
#include "../include/gfx/as3/as3_obj.h"
#include "../include/gfx/as3/as3_vm.h"
#include "../include/gfx/as3/obj/as3_obj_display.h"
#include "../include/gfx/as3/as3_avm.h"
#include "../include/gfx/as3/obj/as3_obj_media.h"
#include "ms2/scaleform/kernel/sf_log.h"
#include "../../../../third_party/fmod44464/api/inc/fmod.hpp"
#include <cstring>
#include <cstdint>
#include <new>

// The exe functions and globals this unit uses but does not define, declared by their FUN_<va> / DAT_<va> names: the
// hook DLL binds them to the exe, the full exe to the recovered definition at that VA (tools/fullexe/alias.py).
template <class T> struct ExeDecl { typedef T type; };

extern ExeDecl<void*>::type DAT_143b27608;
#define VideoThunkA DAT_143b27608
extern ExeDecl<void*>::type DAT_143b27610;
#define VideoThunkBaseA DAT_143b27610
extern ExeDecl<void*>::type DAT_143b27588;
#define VideoThunkB DAT_143b27588
extern ExeDecl<void*>::type DAT_143b27590;
#define VideoThunkBaseB DAT_143b27590
extern ExeDecl<void*>::type DAT_143b27708;
#define VideoThunkC DAT_143b27708
extern ExeDecl<void*>::type DAT_143b27710;
#define VideoThunkBaseC DAT_143b27710
extern ExeDecl<void*>::type DAT_143b275f8;
#define VideoThunkD DAT_143b275f8
extern ExeDecl<void*>::type DAT_143b27600;
#define VideoThunkBaseD DAT_143b27600
extern ExeDecl<void*>::type DAT_143b27638;
#define VideoThunkE DAT_143b27638
extern ExeDecl<void*>::type DAT_1431b7ba0;
#define VideoDisplayVtable DAT_1431b7ba0
static const float VideoDurationScale = 1000.0f;    // exe 0x142d15c1c
extern ExeDecl<void*>::type DAT_143b27640;
#define VideoThunkBaseE DAT_143b27640
extern ExeDecl<void*>::type DAT_143b27488;
#define VideoThunkF DAT_143b27488
extern ExeDecl<void*>::type DAT_143b27490;
#define VideoThunkBaseF DAT_143b27490
extern ExeDecl<void*>::type DAT_143b27528;
#define VideoCallbackA DAT_143b27528
extern ExeDecl<void*>::type DAT_143b27530;
#define VideoCallbackBaseA DAT_143b27530
extern ExeDecl<void*>::type DAT_143b27548;
#define VideoCallbackB DAT_143b27548
extern ExeDecl<void*>::type DAT_143b27550;
#define VideoCallbackBaseB DAT_143b27550
extern ExeDecl<void*>::type DAT_143b275e8;
#define VideoCallbackC DAT_143b275e8
// Each VideoPropBase* slot is the int this-adjust of a 16-byte member-function pointer. The exe reads only its low
// dword (movsxd); its static init (e.g. 0x142c99be0) copies stack garbage into the high dword.
extern ExeDecl<void*>::type DAT_143b27798; extern ExeDecl<void*>::type DAT_143b277a0;
#define VideoPropGetA DAT_143b27798
#define VideoPropBaseA DAT_143b277a0
extern ExeDecl<void*>::type DAT_143b27778; extern ExeDecl<void*>::type DAT_143b27780;
#define VideoPropSetA DAT_143b27778
#define VideoPropBaseSetA DAT_143b27780
extern ExeDecl<void*>::type DAT_143b27758; extern ExeDecl<void*>::type DAT_143b27760;
#define VideoPropGetB DAT_143b27758
#define VideoPropBaseB DAT_143b27760
extern ExeDecl<void*>::type DAT_143b27728; extern ExeDecl<void*>::type DAT_143b27730;
#define VideoPropSetB DAT_143b27728
#define VideoPropBaseSetB DAT_143b27730
extern ExeDecl<void*>::type DAT_143b27738; extern ExeDecl<void*>::type DAT_143b27740;
#define VideoPropGetC DAT_143b27738
#define VideoPropBaseC DAT_143b27740
extern ExeDecl<void*>::type DAT_143b27748; extern ExeDecl<void*>::type DAT_143b27750;
#define VideoPropGetD DAT_143b27748
#define VideoPropBaseD DAT_143b27750
extern ExeDecl<void*>::type DAT_143b27768; extern ExeDecl<void*>::type DAT_143b27770;
#define VideoPropSetC DAT_143b27768
#define VideoPropBaseSetC DAT_143b27770
extern ExeDecl<void*>::type DAT_143b27718; extern ExeDecl<void*>::type DAT_143b27720;
#define VideoPropSetD DAT_143b27718
#define VideoPropBaseSetD DAT_143b27720
extern ExeDecl<void*>::type DAT_143b276d8; extern ExeDecl<void*>::type DAT_143b276e0;
#define VideoStringCallbackA DAT_143b276d8
#define VideoStringCallbackBaseA DAT_143b276e0
extern ExeDecl<void*>::type DAT_143b27598; extern ExeDecl<void*>::type DAT_143b275a0;
#define VideoStringCallbackB DAT_143b27598
#define VideoStringCallbackBaseB DAT_143b275a0
extern ExeDecl<void*>::type DAT_143b277a8;
#define VideoCriWork DAT_143b277a8
extern ExeDecl<unsigned long>::type DAT_143b277b0;
#define VideoCriWorkSize DAT_143b277b0
extern ExeDecl<unsigned int>::type DAT_143b277b4;
#define VideoCriUsers DAT_143b277b4
extern ExeDecl<void*>::type DAT_143b275f0;
#define VideoCallbackBaseC DAT_143b275f0

// The collector ops handed to ForEachChild_GC.
typedef Scaleform::GFx::AS3::RefCountCollector<Scaleform::GFx::AS3::StatMV_ActionScript_Mem> VideoGcCollector;
#define VideoNative0 VideoGcCollector::ReleaseChildCall
#define VideoNative1 VideoGcCollector::MarkInCycleCall
#define VideoNative2 VideoGcCollector::ScanInUseCall
#define VideoNative3 VideoGcCollector::KillChildCall
#define VideoNative4 VideoGcCollector::ScanTempInUseCall
#define ConvertAS3ValueToBool(v) (static_cast<const Scaleform::GFx::AS3::Value*>(v)->Convert2Boolean())
ExeDecl<void(void*)>::type FUN_1423dfa20;   // RefCountBaseGC::ReleaseInternal(this = the object)
#define ReleaseAS3GcObject FUN_1423dfa20
ExeDecl<void(void*)>::type FUN_14257dc30;
ExeDecl<void(void*)>::type FUN_14257dcd0;
ExeDecl<void(void*)>::type FUN_14257dcb0;
ExeDecl<bool(void*, void*)>::type FUN_142518c70;
ExeDecl<void(void*)>::type FUN_142519860;
__declspec(noinline) bool FUN_142510dc0(const void*, const void*) { return false; }   // @0x142510dc0: the exe ICF-folds this with LogBase<DisplayObjectBase>::IsLogNotNull and the AvmDisplayObj/AvmInteractiveObj HasEventHandler (xor al,al; ret)
ExeDecl<bool(const void*)>::type FUN_142514f70;
ExeDecl<const char*(void*, void*)>::type FUN_142506e10;
ExeDecl<void(void*, void*, const void*)>::type FUN_1424d6750;
namespace Scaleform { namespace GFx { class InteractiveObject; }}
ExeDecl<void(void*, Scaleform::GFx::InteractiveObject*)>::type FUN_1424d6480;   // the AVM interactive-object base constructor
ExeDecl<void(void*, void*, const void*)>::type FUN_1424dabd0;
ExeDecl<void(void*, void*)>::type FUN_1424d6ac0;
void FUN_140019470(void* self, uint64_t* output); // defined below (external: other units take its address)
void FUN_140019660(void* self, uint64_t* output);
ExeDecl<void*(void*, void*)>::type FUN_1400199e0;
ExeDecl<void*(void*, void*)>::type FUN_14001ad20;
ExeDecl<void*()>::type FUN_14257e080;
ExeDecl<void(void*, void*, void*)>::type FUN_1425cd370;   // LoadTaskData::AddResource(ResourceId, Resource*)
ExeDecl<int(void*, bool*)>::type FUN_142303a6b;
ExeDecl<int(void*, const char*, unsigned, void*, void**)>::type FUN_142303a29;
ExeDecl<int(void*, uint32_t*, unsigned)>::type FUN_142303a4d;
namespace Scaleform { namespace GFx { class MovieDefImpl; namespace AS3 { class VM; namespace Instances { namespace fl { class Object; }}}}}
Scaleform::GFx::MovieDefImpl* FUN_14250d8f0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Instances::fl::Object* obj);
namespace Scaleform { namespace GFx { struct CharacterCreateInfo; namespace AS3 { namespace Instances { namespace fl_display {
class DisplayObject;
bool FindLibrarySymbol(const DisplayObject* dobj, CharacterCreateInfo* pccinfo, MovieDefImpl* pdefImpl);
}}}}}
namespace Scaleform { namespace GFx { namespace AS3 { void Sfr33SetValueDropObject(UByte* frame, void* object); }}}
ExeDecl<void(void*, void*, int)>::type FUN_1424687d0;
ExeDecl<void(void*, void*, const void*, void*, unsigned, void*, unsigned)>::type FUN_1424fef00;
ExeDecl<void(void*, void*, double)>::type FUN_1424d2150;   // SoundTransform setter (Value const&, double): the value travels in xmm2
ExeDecl<void(void*)>::type FUN_140026ed0;
ExeDecl<void()>::type FUN_140026db0;
extern ExeDecl<void*>::type DAT_1431b7c70;
#define VideoTraitsVtable DAT_1431b7c70
extern ExeDecl<void*>::type DAT_1431b7f60;
#define VideoTraitsBaseVtable DAT_1431b7f60
extern ExeDecl<void*>::type DAT_1431b7ea0;
#define VideoTraitsSubVtableA DAT_1431b7ea0
extern ExeDecl<void*>::type DAT_1431b7de0;
#define VideoTraitsSubVtableB DAT_1431b7de0
// The AvmVideoCharacter model at the end of the file emits these three tables; the hand-inlined ctor FUN_14001af70
// stores them through the DAT_ names. The hook DLL binds the DAT_ names to the exe by their symbols rows.
#ifndef MS2_HOOK_DLL
#pragma comment(linker, "/alternatename:?DAT_1431b7f60@@3PEAXEA=??_7AvmVideoCharacter@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@")
#pragma comment(linker, "/alternatename:?DAT_1431b7ea0@@3PEAXEA=??_7AvmVideoCharacter@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@")
#pragma comment(linker, "/alternatename:?DAT_1431b7de0@@3PEAXEA=??_7AvmVideoCharacter@AS3@GFx@Scaleform@@6B@")
#endif
extern ExeDecl<void*>::type DAT_1431b7160; extern ExeDecl<void*>::type DAT_1431b7900;
#define VideoClassInfoA DAT_1431b7160
#define VideoClassVtableA DAT_1431b7900
struct Sd_1431b71b0; extern Sd_1431b71b0 DAT_1431b71b0; struct Sd_1431b7260; extern Sd_1431b7260 DAT_1431b7260;
#define VideoInstanceVtableA (*reinterpret_cast<void**>(&DAT_1431b71b0))
#define VideoCTraitsVtable (*reinterpret_cast<void**>(&DAT_1431b7260))
extern ExeDecl<void*>::type DAT_1431b7b50; extern ExeDecl<void*>::type DAT_1431b7d50;
#define VideoClassInfoB DAT_1431b7b50
#define VideoClassVtableB DAT_1431b7d50
extern ExeDecl<void*>::type DAT_1431b7c70;
#define VideoInstanceVtableB DAT_1431b7c70
ExeDecl<void(void*)>::type FUN_1424df220;
ExeDecl<void*(void*)>::type FUN_1424eb610;
namespace Scaleform { namespace GFx { namespace Video { class VideoCharacter; class VideoProvider; }}}
void FUN_140010b80(Scaleform::GFx::Video::VideoCharacter* character, Scaleform::GFx::Video::VideoProvider* provider);
#define DAT_143b15f60 (static_cast<void*>(Scaleform::Memory::pGlobalHeap))

namespace {
typedef void (*VideoGenericThunk)(void*, void*, void*);

__forceinline void ReleaseVideoAtom(uint64_t* value)
{
    uint64_t atom = *value;
    if (!atom) return;
    if (atom & 1) { *value = atom - 1; return; }
    uint32_t* refs = reinterpret_cast<uint32_t*>(atom + 0x10);
    if ((*refs & 0x3fffff) != 0) { --*refs; ReleaseAS3GcObject(reinterpret_cast<void*>(atom)); }
}

__forceinline void RetainVideoAtom(uint64_t atom)
{
    if (atom) reinterpret_cast<Scaleform::GFx::AS3::Object*>(atom)->AddRef();
}

struct VideoAtomHashEntry { uint64_t NextInChain, HashValue, Key, Value; };
struct VideoAtomHashTable { uint64_t EntryCount, SizeMask; };
__forceinline VideoAtomHashEntry& VideoAtomE(VideoAtomHashTable* table, uint64_t index)
{
    return *(reinterpret_cast<VideoAtomHashEntry*>(table + 1) + index);
}

// HashSetBase::RemoveAlt over the cached-hash atom table (SDBM hash of the 8 key bytes).
__forceinline void EraseVideoAtomHashEntry(void* tablePtr, const uint64_t* key)
{
    VideoAtomHashTable* table = *reinterpret_cast<VideoAtomHashTable**>(tablePtr);
    if (table == 0) return;
    size_t size = 8;
    uint64_t h = 0x1505;
    const unsigned char* data = reinterpret_cast<const unsigned char*>(key);
    while (size > 0) { size--; h = (h << 16) + (h << 6) - h + data[size]; }
    int64_t index = h & table->SizeMask;
    VideoAtomHashEntry* e = &VideoAtomE(table, index);
    if (e->NextInChain == ~uint64_t(1) || e->HashValue != static_cast<uint64_t>(index)) return;
    int64_t naturalIndex = index;
    int64_t prevIndex = -1;
    while (e->HashValue != static_cast<uint64_t>(naturalIndex) || !(e->Key == *key)) {
        prevIndex = index;
        index = e->NextInChain;
        if (index == -1) return;
        e = &VideoAtomE(table, index);
    }
    if (naturalIndex == index) {
        if (e->NextInChain != ~uint64_t(0)) {
            VideoAtomHashEntry* ee = &VideoAtomE(table, e->NextInChain);
            e->NextInChain = ~uint64_t(1);
            *e = *ee;
            e = ee;
        }
    } else {
        VideoAtomE(table, prevIndex).NextInChain = e->NextInChain;
    }
    e->NextInChain = ~uint64_t(1);
    (*reinterpret_cast<VideoAtomHashTable**>(tablePtr))->EntryCount--;
}

} // namespace: externally referenced Video native
namespace {
// ThunkArgs1<const Value, Number>: the argument starts at its default (NaN) and goes through the out-of-line Convert2Number.
struct VideoNumberArgs
{
    VideoNumberArgs(void* vm, void* result, unsigned argc, const Scaleform::GFx::AS3::Value* argv, double def)
        : vm(vm), r(result), a0(def)
    {
        if (argc > 0)
            argv[0].Convert2Number(a0);
    }
    void* vm;
    void* r;
    double a0;
};
// ThunkFunc1::Func: calls the member through its code pointer and int this-adjust unless the VM threw.
__forceinline void VideoNumberThunk(void* vm, void* callFrame, void* result, unsigned argc,
                                    const Scaleform::GFx::AS3::Value* argv, void*& method, const void* adjust)
{
    unsigned char* root = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callFrame) + 0x10);
    VideoNumberArgs args(vm, result, argc, argv, Scaleform::GFx::NumberUtil::NaN());
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0)
        reinterpret_cast<void(*)(void*, void*, double)>(method)(root + *static_cast<const int*>(adjust), args.r, args.a0);
}
} // namespace
// @0x140016b50
void FUN_140016b50(void*, void* object, void* callFrame, void* member, int argc,
                   Scaleform::GFx::AS3::Value* args)
{
    VideoNumberThunk(object, callFrame, member, static_cast<unsigned>(argc), args, VideoThunkA, &VideoThunkBaseA);
}
namespace {


} // namespace: externally referenced Video native
// @0x140016be0
void FUN_140016be0(void*, void* object, void* callFrame, void* member, int argc,
                   Scaleform::GFx::AS3::Value* args)
{
    VideoNumberThunk(object, callFrame, member, static_cast<unsigned>(argc), args, VideoThunkB, &VideoThunkBaseB);
}
namespace {


// visits the object through its ForEachChild slot with the GC op selected by the index (5 = the collector's own op at +0x40).
// @0x140016c70
void FUN_140016c70(void* object, void* collector, int op)
{
#define VIDEO_GC_VISIT(fn) reinterpret_cast<void (*)(void*, void*, void*)>((*reinterpret_cast<void***>(object))[0])(object, collector, (fn))
    switch (op) {
    case 0: VIDEO_GC_VISIT(reinterpret_cast<void*>(&VideoNative0)); break;
    case 1: VIDEO_GC_VISIT(reinterpret_cast<void*>(&VideoNative1)); break;
    case 2: VIDEO_GC_VISIT(reinterpret_cast<void*>(&VideoNative2)); break;
    case 4: VIDEO_GC_VISIT(reinterpret_cast<void*>(&VideoNative4)); break;
    case 3: VIDEO_GC_VISIT(reinterpret_cast<void*>(&VideoNative3)); break;
    case 5: VIDEO_GC_VISIT(*reinterpret_cast<void**>(static_cast<unsigned char*>(collector) + 0x40)); break;
    }
#undef VIDEO_GC_VISIT
}

// visits the value with GC op VideoNative3 through vtable slot 0, then calls slot 4 with 1.
// @0x140016d10
void FUN_140016d10(void* object, void* value)
{
    reinterpret_cast<void(*)(void*, void*, void*)>((*reinterpret_cast<void***>(object))[0])(
        object, value, reinterpret_cast<void*>(&VideoNative3));
    reinterpret_cast<void(*)(void*, int)>((*reinterpret_cast<void***>(object))[4])(object, 1);
}

// constructs the recovered three-field AS3 value, retaining its managed payload.
// @0x140016e30
uint64_t* FUN_140016e30(uint64_t* out, uint64_t type, uint64_t flags,
                             int hasValue, uint32_t* sourceType, uint64_t* payload)
{
    out[0] = type; out[1] = flags; out[2] = *payload;
    reinterpret_cast<Scaleform::GFx::ASStringNode*>(out[2])->AddRef();
    if (hasValue) {
        const Scaleform::GFx::AS3::Value& source = *reinterpret_cast<const Scaleform::GFx::AS3::Value*>(sourceType);
        Scaleform::GFx::ASString& text = *reinterpret_cast<Scaleform::GFx::ASString*>(out + 2);
        if (source.IsNull())
            text.SetNull();
        else
            source.Convert2String(text);
    }
    return out;
}

// normalizes the AS3 value tag (stored back before the visit) and visits it through its ForEachChild slot with the
// VideoNative1 op.
// @0x140016ed0
void FUN_140016ed0(uint64_t* value, void* object)
{
    uint32_t tag = *reinterpret_cast<uint32_t*>(value + 2);
    if ((tag & 0x70000000) != 0x10000000) {
        void** vtable = *reinterpret_cast<void***>(value);
        *reinterpret_cast<uint32_t*>(value + 2) = (tag & 0x9fffffff) | 0x10000000;
        reinterpret_cast<void(*)(void*, void*, void*)>(vtable[0])(
            value, object, reinterpret_cast<void*>(&VideoNative1));
    }
}

// HashSetBase::findIndexCore, inlined into FUN_140016f40
static __forceinline int64_t VideoFindIndexCore(unsigned char* table, const uint64_t* key, uint64_t hashValue)
{
    int64_t index = static_cast<int64_t>(hashValue);
    const uint64_t* entry = reinterpret_cast<uint64_t*>(table + 0x10 + index * 0x20);
    if (entry[0] == ~uint64_t(1) || entry[1] != static_cast<uint64_t>(index)) return -1;
    for (;;) {
        if (entry[1] == hashValue && entry[2] == *key) return index;
        index = static_cast<int64_t>(entry[0]);
        if (index == -1) break;
        entry = reinterpret_cast<uint64_t*>(table + 0x10 + index * 0x20);
    }
    return -1;
}

// computes the executable's 8-byte key hash and searches its chained bucket.
// @0x140016f40
__declspec(noinline) inline int64_t FUN_140016f40(void* tablePtr, const uint64_t* key)
{
    unsigned char* table = *reinterpret_cast<unsigned char**>(tablePtr);
    if (!table) return -1;
    // the SDK's FixedSizeHash (SDBM over the key's 8 bytes, last byte first)
    const unsigned char* bytes = reinterpret_cast<const unsigned char*>(key);
    size_t size = 8;
    uint64_t hash = 0x1505;
    while (size > 0) {
        size--;
        hash = (hash << 16) + (hash << 6) - hash + static_cast<size_t>(bytes[size]);
    }
    return VideoFindIndexCore(table, key, hash & *reinterpret_cast<uint64_t*>(table + 8));
}

} // namespace: externally referenced Video native
// forwards an AS3 value through the third property thunk unless its receiver is disabled.
// @0x140016fd0
void FUN_140016fd0(void*, void* object, void* callFrame, void* member, unsigned argc,
                   const uint8_t* args)
{
    uint64_t root = *reinterpret_cast<uint64_t*>(static_cast<uint8_t*>(callFrame) + 0x10);
    uint64_t value = 0;
    if (argc > 0 && (*args & 0x1f)) value = *reinterpret_cast<const uint64_t*>(args + 0x10);
    if (*reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(object) + 0x180) == 0) {
        reinterpret_cast<void(*)(uint64_t, void*, uint64_t)>(VideoThunkC)(
            *reinterpret_cast<const int*>(&VideoThunkBaseC) + root, member, value);
    }
}
namespace {


} // namespace: externally referenced Video native
// forwards the AS3 value through the fourth property thunk unless its receiver is disabled.
// @0x140017020
void FUN_140017020(void*, void* object, void* callFrame, void* member, unsigned argc,
                   const uint8_t* args)
{
    uint64_t root = *reinterpret_cast<uint64_t*>(static_cast<uint8_t*>(callFrame) + 0x10);
    uint64_t value = 0;
    if (argc > 0 && (*args & 0x1f)) value = *reinterpret_cast<const uint64_t*>(args + 0x10);
    if (*reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(object) + 0x180) == 0) {
        reinterpret_cast<void(*)(uint64_t, void*, uint64_t)>(VideoThunkD)(
            *reinterpret_cast<const int*>(&VideoThunkBaseD) + root, member, value);
    }
}
namespace {


} // namespace: externally referenced Video native
// forwards the AS3 value through the fifth property thunk unless its receiver is disabled.
// @0x140017070
void FUN_140017070(void*, void* object, void* callFrame, void* member, unsigned argc,
                   const uint8_t* args)
{
    uint64_t root = *reinterpret_cast<uint64_t*>(static_cast<uint8_t*>(callFrame) + 0x10);
    uint64_t value = 0;
    if (argc > 0 && (*args & 0x1f)) value = *reinterpret_cast<const uint64_t*>(args + 0x10);
    if (*reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(object) + 0x180) == 0) {
        reinterpret_cast<void(*)(uint64_t, void*, uint64_t)>(VideoThunkE)(
            *reinterpret_cast<const int*>(&VideoThunkBaseE) + root, member, value);
    }
}
namespace {


// returns the value slot of the hash-set entry holding the 8-byte key, or null.
// @0x140017440
void* FUN_140017440(void* table, const uint64_t* key)
{
    int64_t index = FUN_140016f40(table, key);
    if (index >= 0) return *static_cast<unsigned char**>(table) + (index + 1) * 0x20;
    return 0;
}

} // namespace: externally referenced Video native
// normalizes a value argument and dispatches the recovered setter with its optional integer.
// @0x140017470
void FUN_140017470(void*, void* object, void* callFrame, void* member, unsigned argc,
                   const uint8_t* args)
{
    struct {
        void* object;
        void* member;
        uint64_t value;
        int extra;
    } call;
    uint64_t root = *reinterpret_cast<uint64_t*>(static_cast<uint8_t*>(callFrame) + 0x10);
    call.object = object;
    call.member = member;
    call.value = 0;
    if (argc) call.value = (*args & 0x1f) ? *reinterpret_cast<const uint64_t*>(args + 0x10) : 0;
    call.extra = -1;
    if (*reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(object) + 0x180) == 0) {
        if (argc > 1) reinterpret_cast<const Scaleform::GFx::AS3::Value*>(args + 0x20)->Convert2Int32(*reinterpret_cast<Scaleform::SInt32*>(&call.extra));
        if (*reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(object) + 0x180) == 0) {
            reinterpret_cast<void(*)(uint64_t, void*, uint64_t, int)>(VideoThunkF)(
                *reinterpret_cast<const int*>(&VideoThunkBaseF) + root, call.member, call.value, call.extra);
        }
    }
}
namespace {


void FUN_140017320(uint64_t* table, const uint64_t* key);

// Clears the atom's recorded flag (bit 26), then drops the recorded atom-table payload (freed through the global heap at zero) and removes its key from the receiver cache.
// @0x140017880
void FUN_140017880(void* receiver, uint64_t* atom)
{
    uint32_t flags = *reinterpret_cast<uint32_t*>(atom + 2);
    if (!(static_cast<uint8_t>(flags >> 26) & 1)) return;
    *reinterpret_cast<uint32_t*>(atom + 2) = flags & 0xfbffffff;
    uint64_t* holder = reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(receiver) + 0x70);
    uint64_t key = reinterpret_cast<uintptr_t>(atom);
    unsigned char* table = *reinterpret_cast<unsigned char**>(holder);
    if (!table) return;
    // the inlined FUN_140016f40 lookup (SDBM over the key's 8 bytes, last byte first)
    const unsigned char* bytes = reinterpret_cast<const unsigned char*>(&key);
    size_t size = 8;
    uint64_t hash = 0x1505;
    while (size > 0) {
        size--;
        hash = (hash << 16) + (hash << 6) - hash + static_cast<size_t>(bytes[size]);
    }
    int64_t index = VideoFindIndexCore(table, &key, hash & *reinterpret_cast<uint64_t*>(table + 8));
    if (index < 0) return;
    unsigned char* entry = table + (index + 1) * 0x20;
    if (!entry) return;
    uint32_t* value = *reinterpret_cast<uint32_t**>(entry + 8);
    if (!value) return;
    *reinterpret_cast<uint64_t*>(value + 2) = 0;
    _ReadWriteBarrier();   // the exe clears the payload before it drops the count
    if (--value[0] == 0) {
        void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
        reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, value);
    }
    key = reinterpret_cast<uintptr_t>(atom);
    FUN_140017320(holder, &key);
}

// decrements a live AS3 object reference and invokes the runtime release hook.
// @0x140017990
void FUN_140017990(void* object)
{
    uint32_t* refs = reinterpret_cast<uint32_t*>(static_cast<unsigned char*>(object) + 0x10);
    if ((*refs & 0x3fffff) != 0) { --*refs; ReleaseAS3GcObject(object); }
}

// releases the stored AS3 atom, including inline tagged integers.
// @0x1400179b0
void FUN_1400179b0(uint64_t* value) { ReleaseVideoAtom(value); }
// releases the stored AS3 atom, including inline tagged integers.
// @0x1400179f0
void FUN_1400179f0(uint64_t* value) { ReleaseVideoAtom(value); }
// releases the stored AS3 atom, including inline tagged integers.
// @0x140017a30
void FUN_140017a30(uint64_t* value) { ReleaseVideoAtom(value); }
// releases the stored AS3 atom, including inline tagged integers.
// @0x140017a70
void FUN_140017a70(uint64_t* value) { ReleaseVideoAtom(value); }
// releases the stored AS3 atom, including inline tagged integers.
// @0x140017ab0
void FUN_140017ab0(uint64_t* value) { ReleaseVideoAtom(value); }
// releases the stored AS3 atom, including inline tagged integers.
// @0x140017af0
void FUN_140017af0(uint64_t* value) { ReleaseVideoAtom(value); }
// releases the stored AS3 atom, including inline tagged integers.
// @0x140017b30
void FUN_140017b30(uint64_t* value) { ReleaseVideoAtom(value); }
// releases the stored AS3 atom, including inline tagged integers.
// @0x140017b70
void FUN_140017b70(uint64_t* value) { ReleaseVideoAtom(value); }
// releases the stored AS3 atom, including inline tagged integers.
// @0x140017bb0
void FUN_140017bb0(uint64_t* value) { ReleaseVideoAtom(value); }
// releases the stored AS3 atom, including inline tagged integers.
// @0x140017bf0
void FUN_140017bf0(uint64_t* value) { ReleaseVideoAtom(value); }
// releases the stored AS3 atom, including inline tagged integers.
// @0x140017c30
void FUN_140017c30(uint64_t* value) { ReleaseVideoAtom(value); }

// replaces an AS3 atom without taking a reference to the replacement.
// @0x140017c70
uint64_t* FUN_140017c70(uint64_t* destination, Scaleform::Pickable<Scaleform::GFx::AS3::Object> replacement)
{
    if (reinterpret_cast<uint64_t>(replacement.GetPtr()) != *destination) { ReleaseVideoAtom(destination); *destination = reinterpret_cast<uint64_t>(replacement.GetPtr()); }
    return destination;
}

// replaces an AS3 atom and retains an object-valued replacement.
// @0x140017cd0
uint64_t* FUN_140017cd0(uint64_t* destination, uint64_t replacement)
{
    if (replacement != *destination) { ReleaseVideoAtom(destination); RetainVideoAtom(replacement); *destination = replacement; }
    return destination;
}

// copy-assigns an AS3 atom with a retain of its managed object payload.
// @0x140017d40
uint64_t* FUN_140017d40(uint64_t* destination, const uint64_t* source)
{
    if (source != destination) { ReleaseVideoAtom(destination); RetainVideoAtom(*source); *destination = *source; }
    return destination;
}
// copy-assigns an AS3 atom with a retain of its managed object payload.
// @0x140017db0
uint64_t* FUN_140017db0(uint64_t* destination, const uint64_t* source)
{
    if (source != destination) { ReleaseVideoAtom(destination); RetainVideoAtom(*source); *destination = *source; }
    return destination;
}

// assigns the AS3 object's unsafe Value view and then releases its retained atom.
// @0x140017e40
void* FUN_140017e40(void* result, Scaleform::GFx::AS3::Value* value, uint64_t* atom)
{
    value->AssignUnsafe(reinterpret_cast<Scaleform::GFx::AS3::Object*>(*atom));
    ReleaseVideoAtom(atom);
    return result;
}
// assigns the AS3 object's unsafe Value view and then releases its retained atom.
// @0x140017eb0
void* FUN_140017eb0(void* result, Scaleform::GFx::AS3::Value* value, uint64_t* atom)
{
    value->AssignUnsafe(reinterpret_cast<Scaleform::GFx::AS3::Object*>(*atom));
    ReleaseVideoAtom(atom);
    return result;
}

// MS2-FUNCTIONAL: assigns an atom after releasing the previous managed value.
// @0x1400190c0
uint64_t* FUN_1400190c0(uint64_t* destination, uint64_t replacement)
{
    if (replacement != *destination) { ReleaseVideoAtom(destination); *destination = replacement; }
    return destination;
}
// copy-assigns an atom while retaining its managed object.
// @0x140019120
uint64_t* FUN_140019120(uint64_t* destination, const uint64_t* source)
{
    if (source != destination) { ReleaseVideoAtom(destination); RetainVideoAtom(*source); *destination = *source; }
    return destination;
}
// assigns an object atom to an unsafe AS3 Value and releases the temporary reference.
// @0x1400191d0
void FUN_1400191d0(Scaleform::GFx::AS3::Value* destination, const uint64_t* source)
{
    uint64_t temp = *source;
    RetainVideoAtom(temp);
    destination->AssignUnsafe(reinterpret_cast<Scaleform::GFx::AS3::Object*>(temp));
    ReleaseVideoAtom(&temp);
}
// assigns an object atom to an unsafe AS3 Value and releases the temporary reference.
// @0x140019220
void FUN_140019220(Scaleform::GFx::AS3::Value* destination, const uint64_t* source)
{
    FUN_1400191d0(destination, source);
}
// MS2-FUNCTIONAL: replaces the retained object atom at byte offset 0x80.
// @0x140019270
void FUN_140019270(void* object, uint64_t replacement)
{
    FUN_1400190c0(reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(object) + 0x80), replacement);
}

// MS2-FUNCTIONAL: transfers an object into an AS3 Value using Pick semantics.
// @0x14001a1e0
void FUN_14001a1e0(Scaleform::GFx::AS3::Value* value, Scaleform::GFx::AS3::Object* object)
{
    value->Pick(object);
}
// the AS3 Value payload union: the int goes into a stack copy and all 16 bytes are stored.
union VideoValueUnion {
    int32_t VInt;
    uint8_t VBool;
    uint64_t Raw[2];
};
// initializes an AS3 numeric Value with a 32-bit integer payload.
// @0x14001a260
inline void FUN_14001a260(uint32_t* value, uint32_t number)
{
    value[0] = (value[0] & 0xffffffe2) | 2;
    VideoValueUnion u;
    u.VInt = static_cast<int32_t>(number);
    *reinterpret_cast<VideoValueUnion*>(value + 4) = u;
}
// copies a 32-bit integer payload into an AS3 numeric Value.
// @0x14001a2b0
void* FUN_14001a2b0(void* result, uint32_t* value, const uint32_t* number)
{
    FUN_14001a260(value, *number);
    return result;
}
} // namespace (sfr36: the natives below have external linkage, other units take their addresses)
// reads the current frame record's integer field at offset 0x10.
// @0x14001a330
void FUN_14001a330(void* self, uint32_t* result)
{
    unsigned char* frames = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x58);
    unsigned char index = frames[0x6d];
    unsigned char* slot = frames + static_cast<size_t>(index) * 4;
    void* data = reinterpret_cast<void*(*)(void*)>((*reinterpret_cast<void***>(slot))[0xc])(slot);
    *result = *reinterpret_cast<uint32_t*>(static_cast<unsigned char*>(data) + 0x10);
}
// writes the current frame record's integer field at offset 0x10.
// @0x14001a360
void FUN_14001a360(void* self, void*, uint32_t number)
{
    unsigned char* frames = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x58);
    unsigned char index = frames[0x6d];
    unsigned char* slot = frames + static_cast<size_t>(index) * 4;
    void* data = reinterpret_cast<void*(*)(void*)>((*reinterpret_cast<void***>(slot))[0xc])(slot);
    *reinterpret_cast<uint32_t*>(static_cast<unsigned char*>(data) + 0x10) = number;
}
// reads the current frame record's flag byte at offset 0x14.
// @0x14001a390
void FUN_14001a390(void* self, uint8_t* result)
{
    unsigned char* frames = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x58);
    unsigned char index = frames[0x6d];
    unsigned char* slot = frames + static_cast<size_t>(index) * 4;
    void* data = reinterpret_cast<void*(*)(void*)>((*reinterpret_cast<void***>(slot))[0xc])(slot);
    *result = *(static_cast<unsigned char*>(data) + 0x14);
}
// writes the current frame record's flag byte at offset 0x14.
// @0x14001a3c0
void FUN_14001a3c0(void* self, void*, uint8_t flag)
{
    unsigned char* frames = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x58);
    unsigned char index = frames[0x6d];
    unsigned char* slot = frames + static_cast<size_t>(index) * 4;
    void* data = reinterpret_cast<void*(*)(void*)>((*reinterpret_cast<void***>(slot))[0xc])(slot);
    *(static_cast<unsigned char*>(data) + 0x14) = flag;
}
// The traits' debug class names (slot 2 of each traits vtable; 0x1431b7f60 [16] for the display object).
// @0x140019af0
const char* FUN_140019af0(const void*) { return "ClassTraits::NetStream"; }
// @0x14001a040
const char* FUN_14001a040(const void*) { return "Instances::fl_media::Video"; }
// @0x14001a0b0
const char* FUN_14001a0b0(const void*) { return "InstanceTraits::Video"; }
// @0x14001ae30
const char* FUN_14001ae30(const void*) { return "ClassTraits::Video"; }

// releases the retained atom field and runs the inherited AS3 cleanup.
// @0x140019060
void FUN_140019060(void* object)
{
    ReleaseVideoAtom(reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(object) + 0xc0));
    static_cast<Scaleform::GFx::AS3::Traits*>(object)->Scaleform::GFx::AS3::Traits::~Traits();
}
// releases the retained atom field and runs the inherited AS3 cleanup.
// @0x140019b00
void FUN_140019b00(void* object)
{
    FUN_140019060(object);
}
__forceinline void* VideoAtomHolderDestroy(void* object, unsigned flags)
{
    ReleaseVideoAtom(reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(object) + 0xc0));
    static_cast<Scaleform::GFx::AS3::Traits*>(object)->Scaleform::GFx::AS3::Traits::~Traits();
    if (flags & 1) {
        void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
        reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, object);
    }
    return object;
}
// releases the retained atom field and optionally frees the object through the Scaleform heap.
// @0x140019b60
void* FUN_140019b60(void* object, unsigned flags)
{
    return VideoAtomHolderDestroy(object, flags);
}

// invokes the stored object's callback with this closure as context.
// @0x14001b3f0
void FUN_14001b3f0(uint64_t* closure)
{
    uint64_t* object = reinterpret_cast<uint64_t*>(closure[0]);
    if (object) reinterpret_cast<void(*)(void*, uint64_t)>(*reinterpret_cast<void**>(*reinterpret_cast<void***>(object) + 2))(object, closure[1]);
}
// invokes the stored object's release slot.
// @0x14001b880
void FUN_14001b880(uint64_t* holder)
{
    void* object = reinterpret_cast<void*>(holder[0]);
    if (object) { void** vtable = *reinterpret_cast<void***>(object); reinterpret_cast<void(*)(void*)>(vtable[8])(object); }
}
// retains the replacement heap, releases the previous heap, then stores it.
// @0x14001b8a0
uint64_t* FUN_14001b8a0(uint64_t* holder, void* replacement)
{
    if (replacement) { void** vtable = *reinterpret_cast<void***>(replacement); reinterpret_cast<void(*)(void*)>(vtable[7])(replacement); }
    FUN_14001b880(holder);
    *holder = reinterpret_cast<uintptr_t>(replacement);
    return holder;
}
// releases the previous heap and stores the supplied pointer without retaining it.
// @0x14001b8e0
uint64_t* FUN_14001b8e0(uint64_t* holder, uint64_t replacement)
{
    if (*holder) { FUN_14001b880(holder); *holder = replacement; }
    else *holder = replacement;
    return holder;
}

// converts a callback object to an unsafe Value when the VM has no pending exception, then drops the callback atom.
__forceinline void VideoCallbackToValue(uint64_t* closure)
{
    unsigned char* vm = reinterpret_cast<unsigned char*>(closure[0]);
    if (vm[0x180] == 0) {
        Scaleform::GFx::AS3::Value* value = reinterpret_cast<Scaleform::GFx::AS3::Value*>(closure[1]);
        uint64_t atom = closure[2];
        RetainVideoAtom(atom);
        value->AssignUnsafe(reinterpret_cast<Scaleform::GFx::AS3::Object*>(atom));
        ReleaseVideoAtom(&atom);
    }
    ReleaseVideoAtom(closure + 2);
}
// @0x140019c30
void FUN_140019c30(uint64_t* closure)
{
    VideoCallbackToValue(closure);
}
// converts a callback object to an unsafe Value when the VM has no pending exception, then drops the callback atom.
// @0x140019cd0
void FUN_140019cd0(uint64_t* closure)
{
    VideoCallbackToValue(closure);
}

namespace {
struct VideoCallbackClosure {
    uint64_t Vm, Output, Object;
    VideoCallbackClosure(void* vm, void* output)
        : Vm(reinterpret_cast<uintptr_t>(vm)), Output(reinterpret_cast<uintptr_t>(output)), Object(0) {}
};
// the callback writes its object into closure[2]; closure = {vm, output, object} as VideoCallbackToValue reads it.
// The base is the int this-adjust of the member-function pointer (low dword only, the high dword is garbage).
__forceinline void ConvertVideoCallback(void* vm, void* callback, const void* base, void* context, Scaleform::GFx::AS3::Value* output)
{
    VideoCallbackClosure closure(vm, output);
    reinterpret_cast<void(*)(uintptr_t, uint64_t*)>(callback)(
        *static_cast<const int*>(base) + *reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(context) + 0x10),
        &closure.Object);
    VideoCallbackToValue(&closure.Vm);
}
} // namespace
// invokes the metadata callback and converts its object result to an AS3 Value.
// @0x140019d70
void FUN_140019d70(void*, void* vm, void* context, Scaleform::GFx::AS3::Value* output)
{
    ConvertVideoCallback(vm, VideoCallbackA, &VideoCallbackBaseA, context, output);
}
// invokes the cue point callback and converts its object result to an AS3 Value.
// @0x140019e20
void FUN_140019e20(void*, void* vm, void* context, Scaleform::GFx::AS3::Value* output)
{
    ConvertVideoCallback(vm, VideoCallbackB, &VideoCallbackBaseB, context, output);
}
// invokes the subtitle callback and converts its object result to an AS3 Value.
// @0x140019ed0
void FUN_140019ed0(void*, void* vm, void* context, Scaleform::GFx::AS3::Value* output)
{
    ConvertVideoCallback(vm, VideoCallbackC, &VideoCallbackBaseC, context, output);
}

// copies a 32-bit integer into the numeric payload of an AS3 Value.
// @0x14001a6f0
void FUN_14001a6f0(uint32_t* value, const uint32_t* number)
{
    FUN_14001a260(value, *number);
}
// writes the callback's integer result to its output Value unless the VM has an exception.
// @0x14001a8e0
void FUN_14001a8e0(uint64_t* closure)
{
    if (*reinterpret_cast<unsigned char*>(closure[0] + 0x180) == 0)
    {
        uint32_t* output = reinterpret_cast<uint32_t*>(closure[1]);
        FUN_14001a260(output, static_cast<uint32_t>(closure[2]));
    }
}

// constructs a Video AS3 DisplayObject with the executable's default dimensions and vtable.
// @0x14001a000
Scaleform::GFx::AS3::Instances::fl_display::DisplayObject* FUN_14001a000(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject* object, Scaleform::GFx::AS3::InstanceTraits::Traits* traits)
{
    typedef Scaleform::GFx::AS3::Instances::fl_display::DisplayObject DisplayObject;
    object->DisplayObject::DisplayObject(*traits);   // MSVC explicit ctor call: no placement-new null test (the exe has none)
    *reinterpret_cast<void***>(object) = &VideoDisplayVtable;
    *reinterpret_cast<double*>(reinterpret_cast<unsigned char*>(object) + 0x68) = 320.0;
    *reinterpret_cast<double*>(reinterpret_cast<unsigned char*>(object) + 0x70) = 240.0;
    return object;
}
struct Video03InstanceMaker { Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> FUN_14001a600(Scaleform::GFx::AS3::InstanceTraits::Traits* traits); };
// allocates and constructs the Video AS3 DisplayObject; the Pickable comes back through the hidden result slot (rdx).
// @0x14001a600
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> Video03InstanceMaker::FUN_14001a600(Scaleform::GFx::AS3::InstanceTraits::Traits* traits)
{
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObject* object = static_cast<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject*>(traits->Alloc());
    return Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>(object ? FUN_14001a000(object, traits) : 0);
}
// allocates and constructs a Video AS3 DisplayObject, then transfers it into a Value.
// @0x14001a860
void FUN_14001a860(void*, Scaleform::GFx::AS3::Value* value, Scaleform::GFx::AS3::InstanceTraits::Traits* traits)
{
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObject* object = static_cast<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject*>(traits->Alloc());
    object = object ? FUN_14001a000(object, traits) : 0;
    value->Pick(reinterpret_cast<Scaleform::GFx::AS3::Object*>(object));
}

namespace Scaleform { namespace GFx { namespace Video { class VideoCharacter; }}}
// Video.videoHeight getter (the display height kept as a double at +0x70).
// @0x14001a060
void FUN_14001a060(void* self, int* result) { *result = (int)*(double*)((Scaleform::UByte*)self + 0x70); }
// Video.videoWidth getter (the display width kept as a double at +0x68).
// @0x14001a070
void FUN_14001a070(void* self, int* result) { *result = (int)*(double*)((Scaleform::UByte*)self + 0x68); }
// Video.attachCamera (unsupported).
// @0x14001a3f0
void FUN_14001a3f0(Scaleform::GFx::AS3::Object* self)
{
    self->GetVM().GetUI().Output(Scaleform::GFx::AS3::FlashUI::Output_Warning,
                                 "The method Video::attachCamera() is not implemented\n");
}
// Video.clear: releases the character's current image (sfr_video_02).
// @0x14001a460
void FUN_14001a460(void* self)
{
    extern void FUN_140010a30(Scaleform::GFx::Video::VideoCharacter*);
    FUN_140010a30(*(Scaleform::GFx::Video::VideoCharacter**)((Scaleform::UByte*)self + 0x58));
}
// attaches the supplied AS3 NetStream's VideoPlayer to this Video's display object and adds its reference.
// @0x14001a410
void FUN_14001a410(void* self, void*, void* netStream)
{
    void* player = 0;
    if (netStream) player = *reinterpret_cast<void**>(static_cast<unsigned char*>(netStream) + 0x50);
    void* display = *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x58);
    if (display) {
        FUN_140010b80(static_cast<Scaleform::GFx::Video::VideoCharacter*>(display), static_cast<Scaleform::GFx::Video::VideoProvider*>(player));
        if (player) { void** vtable = *reinterpret_cast<void***>(player); reinterpret_cast<void(*)(void*, void*)>(vtable[7])(player, display); }
    }
}
// (sfr33) external: the Video traits / display vtable copies of data_rdata_sf_video take these addresses.

// destroys AS3 CTraits and conditionally frees the allocation through the Scaleform heap.
// @0x14001a5c0
Scaleform::GFx::AS3::InstanceTraits::CTraits* FUN_14001a5c0(Scaleform::GFx::AS3::InstanceTraits::CTraits* traits, uint32_t flags)
{
    traits->CTraits::~CTraits();  // MS2: non-virtual, as the exe (a virtual call from the deleting dtor recurses)
    if (flags & 1) {
        void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
        reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, traits);
    }
    return traits;
}
// transfers an object into an AS3 Value using the Pick operation.
// @0x14001a690
Scaleform::GFx::AS3::Value* FUN_14001a690(Scaleform::GFx::AS3::Value* value, Scaleform::GFx::AS3::Object* object)
{
    value->Pick(object);
    return value;
}
// converts the width/height arguments into the Video's +0x68/+0x70 and stores the rectangle in twips.
// @0x14001a760
void FUN_14001a760(void* self, unsigned count, Scaleform::GFx::AS3::Value* args)
{
    if (count >= 2) {
        // The exe converts into the members (0x14001a78f/0x14001a7a1: Convert2Number with r8 = self+0x68, self+0x70);
        // converting into a dropped local left new Video(w, h) at the 320x240 default, so the class-select video drew
        // at 320x240 in the top-left of its box.
        args[0].Convert2Number(*reinterpret_cast<double*>(static_cast<unsigned char*>(self) + 0x68));
        args[1].Convert2Number(*reinterpret_cast<double*>(static_cast<unsigned char*>(self) + 0x70));
        unsigned char* player = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x58);
        *reinterpret_cast<Scaleform::Render::RectF*>(player + 0xe0) = Scaleform::Render::RectF(0.0f, 0.0f,
            static_cast<float>(*reinterpret_cast<double*>(static_cast<unsigned char*>(self) + 0x68)) * 20.0f,
            static_cast<float>(*reinterpret_cast<double*>(static_cast<unsigned char*>(self) + 0x70)) * 20.0f);
    }
}
// updates the player rectangle from the stored Video dimensions when resize is enabled.
// @0x14001a800
void FUN_14001a800(uint64_t* object, uint8_t update)
{
    if (!update) {
        void** vtable = *reinterpret_cast<void***>(object);
        reinterpret_cast<void(*)(void*)>(vtable[21])(object);
        unsigned char* player = reinterpret_cast<unsigned char*>(object[11]);
        *reinterpret_cast<Scaleform::Render::RectF*>(player + 0xe0) = Scaleform::Render::RectF(0.0f, 0.0f,
            static_cast<float>(*reinterpret_cast<double*>(object + 13)) * 20.0f,
            static_cast<float>(*reinterpret_cast<double*>(object + 14)) * 20.0f);
    }
}


// destroys the AS3 DisplayObject subobject and conditionally frees the allocation (unsigned flags, as the exe's
// mov ebx,edx).
// @0x14001a2f0
void* FUN_14001a2f0(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject* object, unsigned flags)
{
    object->Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::~DisplayObject();  // MS2: exe 0x14001a2ff calls ~DisplayObject (0x14243d0b0) directly; the virtual call recursed
    if (flags & 1) {
        void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
        reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, object);
    }
    return object;
}

// Value::SetBool: the Boolean kind and the byte payload (all 16 bytes stored from a stack copy).
inline void SetVideoBoolValue(uint32_t* value, uint8_t b)
{
    value[0] = (value[0] & 0xffffffe1) | 1;
    VideoValueUnion u;
    u.VBool = b;
    *reinterpret_cast<VideoValueUnion*>(value + 4) = u;
}
// the SDK thunk's UnboxArgV0<T>: {vm, result, value}; the getter writes the value through its address.
template <class T, class R = uint32_t*> struct VideoUnboxArgs {
    void* Vm;
    R Result;
    T Value;
};
// fetches the video width integer and writes it to the callback Value.
// @0x14001a9b0
void FUN_14001a9b0(void*, void* vm, void* context, uint32_t* output)
{
    VideoUnboxArgs<uint32_t> args = { vm, output, 0 };
    reinterpret_cast<void(*)(uintptr_t, uint32_t*)>(VideoPropGetA)(*reinterpret_cast<const int*>(&VideoPropBaseA) + *reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(context) + 0x10), &args.Value);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(args.Vm) + 0x180) == 0) FUN_14001a260(args.Result, args.Value);
}
// converts the input to an integer and writes it through the video property setter thunk.
// @0x14001aa20
void FUN_14001aa20(void*, void* vm, void* context, uint64_t result, unsigned argc, void* argv)
{
    uint64_t root = *reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(context) + 0x10);
    VideoUnboxArgs<int32_t, uint64_t> args = { vm, result, 0 };
    if (argc > 0) {
        reinterpret_cast<const Scaleform::GFx::AS3::Value*>(argv)->Convert2Int32(*reinterpret_cast<Scaleform::SInt32*>(&args.Value));
    }
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0)
        reinterpret_cast<void(*)(uintptr_t, uint64_t, int32_t)>(VideoPropSetA)(*reinterpret_cast<const int*>(&VideoPropBaseSetA) + root, args.Result, args.Value);
}
// fetches the video playback boolean and writes it to the callback Value.
// @0x14001aa90
void FUN_14001aa90(void*, void* vm, void* context, uint32_t* output)
{
    VideoUnboxArgs<uint8_t> args = { vm, output, 0 };
    reinterpret_cast<void(*)(uintptr_t, uint8_t*)>(VideoPropGetB)(*reinterpret_cast<const int*>(&VideoPropBaseB) + *reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(context) + 0x10), &args.Value);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(args.Vm) + 0x180) == 0) SetVideoBoolValue(args.Result, args.Value);
}
// converts the input to a boolean and writes it through the video property setter thunk.
// @0x14001ab00
void FUN_14001ab00(void*, void* vm, void* context, uint64_t result, unsigned argc, void* argv)
{
    uint64_t root = *reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(context) + 0x10);
    bool converted = false;
    if (argc > 0) converted = ConvertAS3ValueToBool(argv);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0)
        reinterpret_cast<void(*)(uintptr_t, uint64_t, bool)>(VideoPropSetB)(*reinterpret_cast<const int*>(&VideoPropBaseSetB) + root, result, converted);
}
// fetches the video volume integer and writes it to the callback Value.
// @0x14001ab60
void FUN_14001ab60(void*, void* vm, void* context, uint32_t* output)
{
    VideoUnboxArgs<uint32_t> args = { vm, output, 0 };
    reinterpret_cast<void(*)(uintptr_t, uint32_t*)>(VideoPropGetC)(*reinterpret_cast<const int*>(&VideoPropBaseC) + *reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(context) + 0x10), &args.Value);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(args.Vm) + 0x180) == 0) FUN_14001a260(args.Result, args.Value);
}
// fetches the video pan integer and writes it to the callback Value.
// @0x14001abd0
void FUN_14001abd0(void*, void* vm, void* context, uint32_t* output)
{
    VideoUnboxArgs<uint32_t> args = { vm, output, 0 };
    reinterpret_cast<void(*)(uintptr_t, uint32_t*)>(VideoPropGetD)(*reinterpret_cast<const int*>(&VideoPropBaseD) + *reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(context) + 0x10), &args.Value);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(args.Vm) + 0x180) == 0) FUN_14001a260(args.Result, args.Value);
}

// forwards an object atom to the corresponding video property setter.
// @0x14001ac80
void FUN_14001ac80(void*, void* vm, void* context, uint64_t property, unsigned count, const uint8_t* args)
{
    uint64_t root = *reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(context) + 0x10);
    uint64_t atom = 0;
    if (count > 0 && (*args & 0x1f) != 0) atom = *reinterpret_cast<const uint64_t*>(args + 0x10);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0)
        reinterpret_cast<void(*)(uintptr_t, uint64_t, uint64_t)>(VideoPropSetC)(*reinterpret_cast<const int*>(&VideoPropBaseSetC) + root, property, atom);
}
// forwards an object atom to the second corresponding video property setter.
// @0x14001acd0
void FUN_14001acd0(void*, void* vm, void* context, uint64_t property, unsigned count, const uint8_t* args)
{
    uint64_t root = *reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(context) + 0x10);
    uint64_t atom = 0;
    if (count > 0 && (*args & 0x1f) != 0) atom = *reinterpret_cast<const uint64_t*>(args + 0x10);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0)
        reinterpret_cast<void(*)(uintptr_t, uint64_t, uint64_t)>(VideoPropSetD)(*reinterpret_cast<const int*>(&VideoPropBaseSetD) + root, property, atom);
}
// releases the retained atom field and invokes the AS3 cleanup hook.
// @0x14001ae40
void FUN_14001ae40(void* object)
{
    FUN_140019060(object);
}
// releases the retained atom field, invokes AS3 cleanup, and conditionally frees the object.
// @0x14001aea0
void* FUN_14001aea0(void* object, unsigned flags)
{
    return VideoAtomHolderDestroy(object, flags);
}

// releases the retained pointer stored in the holder.
// @0x14001b980
void FUN_14001b980(void** holder) { if (*holder) FUN_14257dcd0(*holder); }
// retains the replacement, releases the previous pointer, then stores it.
// @0x14001b9a0
uint64_t* FUN_14001b9a0(uint64_t* holder, void* replacement)
{
    if (replacement) ++*reinterpret_cast<uint32_t*>(static_cast<unsigned char*>(replacement) + 8);
    if (*holder) FUN_14257dcd0(reinterpret_cast<void*>(*holder));
    *holder = reinterpret_cast<uintptr_t>(replacement); return holder;
}
// releases the previous pointer and stores the replacement without retaining it.
// @0x14001b9f0
uint64_t* FUN_14001b9f0(uint64_t* holder, uint64_t replacement)
{
    if (*holder) FUN_14257dcd0(reinterpret_cast<void*>(*holder)); *holder = replacement; return holder;
}
// releases the retained pointer stored in the holder.
// @0x14001ba50
void FUN_14001ba50(void** holder) { if (*holder) FUN_14257dcd0(*holder); }
// retains the replacement, releases the previous pointer, then stores it.
// @0x14001ba70
uint64_t* FUN_14001ba70(uint64_t* holder, void* replacement)
{
    if (replacement) ++*reinterpret_cast<uint32_t*>(static_cast<unsigned char*>(replacement) + 8);
    if (*holder) FUN_14257dcd0(reinterpret_cast<void*>(*holder));
    *holder = reinterpret_cast<uintptr_t>(replacement); return holder;
}
// retains the new shared stream and releases the old stream.
// @0x14001bba0
uint64_t* FUN_14001bba0(uint64_t* holder, void* replacement)
{
    if (replacement) FUN_14257dc30(replacement);
    if (*holder) FUN_14257dcb0(reinterpret_cast<void*>(*holder));
    *holder = reinterpret_cast<uintptr_t>(replacement); return holder;
}
// retains and stores a non-null shared stream, or clears the holder.
// @0x14001bc00
uint64_t* FUN_14001bc00(uint64_t* holder, void* replacement)
{
    if (replacement) FUN_14257dc30(replacement);
    *holder = reinterpret_cast<uintptr_t>(replacement); return holder;
}
// releases the shared stream stored in the holder.
// @0x14001bc40
void FUN_14001bc40(void** holder) { if (*holder) FUN_14257dcb0(*holder); }
// releases the shared stream stored in the holder.
// @0x14001bca0
void FUN_14001bca0(void** holder) { if (*holder) FUN_14257dcb0(*holder); }
// retains the replacement shared stream and releases the old stream.
// @0x14001bcc0
uint64_t* FUN_14001bcc0(uint64_t* holder, void* replacement)
{
    if (replacement) FUN_14257dc30(replacement);
    if (*holder) FUN_14257dcb0(reinterpret_cast<void*>(*holder));
    *holder = reinterpret_cast<uintptr_t>(replacement); return holder;
}
// releases the shared stream stored in the holder.
// @0x14001bd70
void FUN_14001bd70(void** holder) { if (*holder) FUN_14257dcb0(*holder); }
// releases the old shared stream and replaces it without retaining the new stream.
// @0x14001bd90
uint64_t* FUN_14001bd90(uint64_t* holder, uint64_t replacement)
{
    if (*holder) FUN_14257dcb0(reinterpret_cast<void*>(*holder)); *holder = replacement; return holder;
}
// releases the shared stream stored in the holder.
// @0x14001bdf0
void FUN_14001bdf0(void** holder) { if (*holder) FUN_14257dcb0(*holder); }
// retains the replacement shared stream and releases the old stream.
// @0x14001be10
uint64_t* FUN_14001be10(uint64_t* holder, void* replacement)
{
    if (replacement) FUN_14257dc30(replacement);
    if (*holder) FUN_14257dcb0(reinterpret_cast<void*>(*holder));
    *holder = reinterpret_cast<uintptr_t>(replacement); return holder;
}
// releases the old shared stream and stores the supplied pointer without retaining it.
// @0x14001be50
uint64_t* FUN_14001be50(uint64_t* holder, uint64_t replacement)
{
    if (*holder) FUN_14257dcb0(reinterpret_cast<void*>(*holder)); *holder = replacement; return holder;
}

// replaces the pointer only after releasing the previously stored value.
// @0x14001bac0
uint64_t* FUN_14001bac0(uint64_t* holder, uint64_t replacement)
{
    if (*holder) FUN_14257dcd0(reinterpret_cast<void*>(*holder));
    *holder = replacement; return holder;
}
// releases the retained pointer stored in the holder.
// @0x14001bb40
void FUN_14001bb40(void** holder) { if (*holder) FUN_14257dcd0(*holder); }
// releases the shared stream stored in the holder.
// @0x14001bb80
void FUN_14001bb80(void** holder) { if (*holder) FUN_14257dcb0(*holder); }
// releases the Scaleform resource stored in the holder.
// @0x14001bd20
void FUN_14001bd20(void** holder) { if (*holder) static_cast<Scaleform::GFx::Resource*>(*holder)->Release(); }
// LogState::GetLog: the installed log (+0x20), else the global Scaleform log (Log::GetGlobalLog).
// @0x14001bf90
void* FUN_14001bf90(void* object)
{
    void* log = *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x20);
    return log ? log : static_cast<void*>(Scaleform::Log::GetGlobalLog());
}
// adds the resource (id, resource) to the movie load task while no failure is present. The exe passes its
// incoming r8 (the Resource*) through untouched.
// @0x14001bfd0
void FUN_14001bfd0(void* object, const uint32_t* id, void* pResource)
{
    if (*reinterpret_cast<uint32_t*>(static_cast<unsigned char*>(object) + 0x3b8) == 0) {
        (*reinterpret_cast<Scaleform::GFx::MovieDataDef::LoadTaskData**>(static_cast<unsigned char*>(object) + 0x38))->AddResource(
            Scaleform::GFx::ResourceId(*id), static_cast<Scaleform::GFx::Resource*>(pResource));
    }
}

namespace {

// forwards VM and ClassInfo to the CTraits ctor and installs the Video traits vtable and object size (+0x60).
// @0x14001a080
void* FUN_14001a080(void* traits, void* vm, const void* classInfo)
{
    static_cast<Scaleform::GFx::AS3::InstanceTraits::CTraits*>(traits)->Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(*static_cast<Scaleform::GFx::AS3::VM*>(vm), *static_cast<const Scaleform::GFx::AS3::ClassInfo*>(classInfo));
    *reinterpret_cast<void***>(traits) = &VideoTraitsVtable;
    *reinterpret_cast<uint32_t*>(static_cast<unsigned char*>(traits) + 0x60) = 0x78;
    return traits;
}
// releases an old reference and stores the supplied pointer.
// @0x14001a0e0
uint64_t* FUN_14001a0e0(uint64_t* holder, uint64_t replacement)
{
    if (*holder) FUN_14257dcd0(reinterpret_cast<void*>(*holder));
    *holder = replacement; return holder;
}
// initializes a native callback record with its VM, property and integer payload (the default, then the
// first AS3 argument through Value::Convert2Int32 when one is supplied).
// @0x14001a920
uint64_t* FUN_14001a920(uint64_t* record, uint64_t vm, uint64_t property, int count, uint64_t args, const uint32_t* value)
{
    record[1] = property; record[0] = vm;
    int* payload = reinterpret_cast<int*>(record + 2);
    *payload = static_cast<int>(*value);
    if (count) {
        reinterpret_cast<const Scaleform::GFx::AS3::Value*>(args)->Convert2Int32(*reinterpret_cast<Scaleform::SInt32*>(payload));
    }
    return record;
}
} // namespace (sfr_video_04 calls FUN_14001af70)

// the character's own fields at +0x48, set up after the AvmInteractiveObj base
namespace {
struct VideoTraitsFields
{
    uint32_t A, B, C;
    bool Flag;
    VideoTraitsFields() { C = 0; B = 0; A = 0; Flag = true; }
};
} // namespace

// the AS3 AVM video character constructor (sfr_video_04): runs the AvmInteractiveObj base constructor on
// the character (rdx passes through) and installs the Video character vtables and defaults.
// @0x14001af70
void* FUN_14001af70(void* self, Scaleform::GFx::InteractiveObject* object)
{
    uint64_t* traits = static_cast<uint64_t*>(self);
    reinterpret_cast<Scaleform::GFx::AS3::AvmInteractiveObj*>(traits)->Scaleform::GFx::AS3::AvmInteractiveObj::AvmInteractiveObj(object);
    reinterpret_cast<VideoTraitsFields*>(reinterpret_cast<unsigned char*>(traits) + 0x48)->VideoTraitsFields::VideoTraitsFields();
    *reinterpret_cast<void***>(traits) = &VideoTraitsBaseVtable;
    reinterpret_cast<void***>(traits)[6] = &VideoTraitsSubVtableA;
    reinterpret_cast<void***>(traits)[8] = &VideoTraitsSubVtableB;
    return traits;
}

namespace {

// initializes a null output and forwards metadata handling to its callback helper.
// @0x140019850
uint64_t* FUN_140019850(void* self, uint64_t* result)
{
    *result = 0; FUN_140019470(self, result); return result;
}
// initializes a null output and forwards cue-point handling to its callback helper.
// @0x140019870
uint64_t* FUN_140019870(void* self, uint64_t* result)
{
    *result = 0; FUN_140019660(self, result); return result;
}
} // MS2: the two class-info factories at global scope (data_rdata_sf_video binds them)
// allocates a Video instance-traits object and constructs it for the supplied class traits.
// @0x140019bd0
void** FUN_140019bd0(void** result, void* classTraits)
{
    Scaleform::MemoryHeap* heap = *reinterpret_cast<Scaleform::MemoryHeap**>(static_cast<unsigned char*>(classTraits) + 0x38);
    void* object = heap->Alloc(200);
    *result = object ? FUN_1400199e0(object, classTraits) : 0;
    return result;
}
// allocates a Video traits object and constructs it for the supplied class traits.
// @0x14001af10
void** FUN_14001af10(void** result, void* classTraits)
{
    Scaleform::MemoryHeap* heap = *reinterpret_cast<Scaleform::MemoryHeap**>(static_cast<unsigned char*>(classTraits) + 0x38);
    void* object = heap->Alloc(200);
    *result = object ? FUN_14001ad20(object, classTraits) : 0;
    return result;
}
namespace {

// initializes the AS3 callback record: captures the optional first atom argument and converts the optional second one
// to its integer payload (Value::Convert2UInt32) unless the VM has an exception pending.
// @0x1400170c0
uint64_t* FUN_1400170c0(uint64_t* record, uint64_t vm, uint64_t property, unsigned count, const uint8_t* args, const uint64_t* defaults)
{
    record[0] = vm; record[1] = property;
    record[2] = defaults[0];
    if (count) {
        if ((*args & 0x1f) == 0) record[2] = 0;
        else record[2] = *reinterpret_cast<const uint64_t*>(args + 0x10);
    }
    uint32_t* payload = reinterpret_cast<uint32_t*>(record + 3);
    *payload = *reinterpret_cast<const uint32_t*>(defaults + 1);
    if (*reinterpret_cast<const uint8_t*>(vm + 0x180) == 0 && count > 1) {
        reinterpret_cast<const Scaleform::GFx::AS3::Value*>(args + 0x20)->Convert2Int32(*reinterpret_cast<Scaleform::SInt32*>(payload));
    }
    return record;
}
// removes the hashed atom key from its chained Scaleform table.
// @0x140017320
void FUN_140017320(uint64_t* table, const uint64_t* key)
{
    EraseVideoAtomHashEntry(table, key);
}

// Reference-counts CRI movie startup and allocates its eight-handle work area on first use.
// @0x14001b460
void FUN_14001b460(uint8_t optional)
{
    const int previous = VideoCriUsers++;
    if (previous == 0) {
        criHeap_Initialize();
        VideoCriWorkSize = CriMv::CalcMovieHandleWork(8, CriMv::ErrorContainer);
        VideoCriWork = Scaleform::Memory::Alloc(VideoCriWorkSize);
        CriMv::SetupMovieHandleWork(8, VideoCriWork, VideoCriWorkSize, CriMv::ErrorContainer);
        CriMv::Initialize(CriMv::ErrorContainer);
        if (optional) CriMv::InitializeFrame32bitARGB();
    }
}
// finalizes CRI movie work and its heap on the final reference release.
// @0x14001b4f0
void FUN_14001b4f0()
{
    const int previous = VideoCriUsers--;
    if (previous == 1) {
        CriMv::Finalize(CriMv::ErrorContainer);
        if (VideoCriWork) {
            void** heap = *reinterpret_cast<void***>(DAT_143b15f60);
            reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, VideoCriWork);
        }
        criHeap_Finalize();
    }
}
// allocates one 16 KiB read buffer per stream and frees partial allocations on failure.
// @0x14001b550
bool FUN_14001b550(void* state, uint32_t count, uint32_t chunkSize)
{
    if (!count) return false;
    unsigned char* bytes = static_cast<unsigned char*>(state);
    *reinterpret_cast<uint32_t*>(bytes + 0x38) = count;
    *reinterpret_cast<uint32_t*>(bytes + 0x3c) = chunkSize;
    *reinterpret_cast<uint32_t*>(bytes + 0x40) = 0;
    for (uint32_t i = 0; i < *reinterpret_cast<uint32_t*>(bytes + 0x38); ++i) {
        void* heap = *reinterpret_cast<void**>(bytes + 0x10);
        void*& block = reinterpret_cast<void**>(bytes + 0x50)[i];
        block = reinterpret_cast<void*(*)(void*, size_t, unsigned)>((*reinterpret_cast<void***>(heap))[10])(heap, 0x4000, 0);  // MS2: vcall
        if (!block) {
            while (i != 0) {
                --i;
                void*& freed = reinterpret_cast<void**>(bytes + 0x50)[i];
                reinterpret_cast<void(*)(void*, void*)>((*reinterpret_cast<void***>(DAT_143b15f60))[12])(DAT_143b15f60, freed);  // MS2: vcall
                freed = 0;
            }
            return false;
        }
    }
    return true;
}
// frees and clears every per-stream read buffer.
// @0x14001b620
void FUN_14001b620(void* state)
{
    unsigned char* bytes = static_cast<unsigned char*>(state);
    for (uint32_t i = 0; i < *reinterpret_cast<uint32_t*>(bytes + 0x38); ++i) {
        void*& block = reinterpret_cast<void**>(bytes + 0x50)[i];
        reinterpret_cast<void(*)(void*, void*)>((*reinterpret_cast<void***>(DAT_143b15f60))[12])(DAT_143b15f60, block);  // MS2: vcall
        block = 0;
    }
    *reinterpret_cast<uint32_t*>(bytes + 0x38) = 0;
}

// Reads interleaved PCM samples from the per-channel stream buffers.
// @0x14001b6b0
int FUN_14001b6b0(void* player, uint32_t* output, uint32_t requestedBytes)
{
    // SDK VideoSoundRendererStream::Streamer::GetPCMData (float samples): views of the streamer (+0x10 pParent) and the
    // parent's PCM stream (+0x30), channel count (+0x38), sample total (+0x48) and per-channel buffers (+0x50)
    struct PCMStream
    {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual uint32_t GetDataFloat(uint32_t nch, float* pcmbuf[], uint32_t req) = 0;
    };
    struct Parent
    {
        char pad[0x30];
        PCMStream* pPCMStream;
        unsigned ChannelCount;
        char pad2[0xc];
        uint64_t TotalGotSamples;
        float* SampleBuffers[8];
    };
    struct Streamer
    {
        char pad[0x10];
        Parent* pParent;
        uint32_t GetData(uint32_t nch, float* pcmbuf[], uint32_t req_nsmpl)
        {
            return pParent->pPCMStream->GetDataFloat(nch, pcmbuf, req_nsmpl);
        }
    };
    Streamer* self = static_cast<Streamer*>(player);
    uint32_t recv_nsmpl = 0;
    unsigned recv_bytes = 0;
    unsigned ssize = 32;
    uint32_t nsmpl = requestedBytes * 8 / ssize / self->pParent->ChannelCount;
    float* buffer = reinterpret_cast<float*>(output);

    if (self->pParent->pPCMStream)
    {
        if (self->pParent->ChannelCount == 1)
        {
            recv_nsmpl = self->GetData(1, &buffer, nsmpl);
        }
        else
        {
            while (nsmpl > 0)
            {
                uint32_t gsmpl = self->GetData(self->pParent->ChannelCount, self->pParent->SampleBuffers,
                    nsmpl > 0x1000 ? 0x1000 : nsmpl);
                if (gsmpl == 0)
                    break;

                for (unsigned count = 0; count < gsmpl; count++)
                {
                    for (unsigned i = 0; i < self->pParent->ChannelCount; ++i)
                        *buffer++ = self->pParent->SampleBuffers[i][count];
                }
                nsmpl -= gsmpl;
                recv_nsmpl += gsmpl;
            }
        }
    }

    self->pParent->TotalGotSamples += recv_nsmpl;
    recv_bytes = recv_nsmpl * ssize * self->pParent->ChannelCount / 8;
    return recv_bytes;
}

namespace {
// Value::Convert2String into *slot, except that a null object (tags 0xc..0xf with no object) takes the string manager's
// builtin "null" node (manager + 0x68), as the exe's callers inline. The CheckResult goes to a scratch byte.
__forceinline void ConvertVideoStringArg(const uint64_t* value, uint64_t* slot)
{
    if (reinterpret_cast<const Scaleform::GFx::AS3::Value*>(value)->IsNull()) {
        unsigned char* nullNode = *reinterpret_cast<unsigned char**>(*slot + 8) + 0x68;
        ++*reinterpret_cast<uint32_t*>(nullNode + 0x18);
        Scaleform::GFx::ASStringNode* old = reinterpret_cast<Scaleform::GFx::ASStringNode*>(*slot);
        if (--*reinterpret_cast<uint32_t*>(reinterpret_cast<unsigned char*>(old) + 0x18) == 0) old->ReleaseNode();
        *slot = reinterpret_cast<uintptr_t>(nullNode);
    } else {
        reinterpret_cast<const Scaleform::GFx::AS3::Value*>(value)->Convert2String(
            *reinterpret_cast<Scaleform::GFx::ASString*>(slot));
    }
}
}
// MS2-FUNCTIONAL: captures two string callback parameters, retaining defaults and converting supplied AS3 values.
// @0x140017130
__declspec(noinline) uint64_t* FUN_140017130(uint64_t* record, uint64_t vm, uint64_t property, unsigned count, const uint64_t* args, const uint64_t* defaults)
{
    record[0] = vm; record[1] = property;
    record[2] = defaults[0];
    ++*reinterpret_cast<uint32_t*>(record[2] + 0x18);
    if (count) ConvertVideoStringArg(args, record + 2);
    record[3] = defaults[1];
    ++*reinterpret_cast<uint32_t*>(record[3] + 0x18);
    if (*reinterpret_cast<unsigned char*>(vm + 0x180) == 0 && count > 1)
        ConvertVideoStringArg(args + 4, record + 3);
    return record;
}
// captures three string callback parameters and converts each supplied AS3 argument.
// @0x140017250
uint64_t* FUN_140017250(uint64_t* record, uint64_t vm, uint64_t property, unsigned count, const uint64_t* args, const uint64_t* defaults)
{
    FUN_140017130(record, vm, property, count, args, defaults);
    record[4] = defaults[2];
    ++*reinterpret_cast<uint32_t*>(record[4] + 0x18);
    if (*reinterpret_cast<unsigned char*>(vm + 0x180) == 0 && count > 2)
        ConvertVideoStringArg(args + 8, record + 4);
    return record;
}

namespace {
__forceinline void* BuildVideoTraits(void* classTraits, void* vm, const void* classInfo, void** classVtable, void** instanceVtable, uint32_t instanceFlags, void** classObjectVtable)
{
    static_cast<Scaleform::GFx::AS3::ClassTraits::Traits*>(classTraits)->Scaleform::GFx::AS3::ClassTraits::Traits::Traits(*static_cast<Scaleform::GFx::AS3::VM*>(vm), *static_cast<const Scaleform::GFx::AS3::ClassInfo*>(classInfo));
    *reinterpret_cast<void***>(classTraits) = classVtable;
    void** heap = *reinterpret_cast<void***>(static_cast<unsigned char*>(vm) + 0x38);
    void* memory = reinterpret_cast<void*(*)(void*, size_t, unsigned)>((*reinterpret_cast<void***>(heap))[10])(heap, 0xe8, 0);  // MS2: vcall
    void* instance;
    if (memory) {
        static_cast<Scaleform::GFx::AS3::InstanceTraits::CTraits*>(memory)->Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(*static_cast<Scaleform::GFx::AS3::VM*>(vm), *static_cast<const Scaleform::GFx::AS3::ClassInfo*>(classInfo));
        *reinterpret_cast<void***>(memory) = instanceVtable;
        *reinterpret_cast<uint32_t*>(static_cast<unsigned char*>(memory) + 0x60) = instanceFlags;
        instance = memory;
    } else {
        instance = 0;
    }
    Scaleform::GFx::AS3::ClassTraits::Traits* typedTraits = static_cast<Scaleform::GFx::AS3::ClassTraits::Traits*>(classTraits);
    Scaleform::GFx::AS3::InstanceTraits::Traits* typedInstance = static_cast<Scaleform::GFx::AS3::InstanceTraits::Traits*>(instance);
    typedTraits->SetInstanceTraits(Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>(typedInstance));
    memory = reinterpret_cast<void*(*)(void*, size_t, unsigned)>((*reinterpret_cast<void***>(heap))[10])(heap, 0x50, 0);  // MS2: vcall
    Scaleform::GFx::AS3::Class* ctraits;
    // only the first class overrides the Class vftable; the second keeps the ctor's
    if (classObjectVtable) {
        if (memory) {
            static_cast<Scaleform::GFx::AS3::Class*>(memory)->Scaleform::GFx::AS3::Class::Class(*static_cast<Scaleform::GFx::AS3::ClassTraits::Traits*>(classTraits));
            *reinterpret_cast<void***>(memory) = classObjectVtable;
            ctraits = static_cast<Scaleform::GFx::AS3::Class*>(memory);
        } else {
            ctraits = 0;
        }
    } else {
        ctraits = ::new (memory) Scaleform::GFx::AS3::Class(*static_cast<Scaleform::GFx::AS3::ClassTraits::Traits*>(classTraits));
    }
    uint64_t* slot = reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(instance) + 0x80);
    if (reinterpret_cast<uint64_t>(ctraits) != *slot) {
        ReleaseVideoAtom(slot);
        *slot = reinterpret_cast<uint64_t>(ctraits);
    }
    return classTraits;
}
}
} // namespace (FUN_1400199e0 / FUN_14001ad20 are declared at global scope above)
// constructs the Video AS3 class traits and its instance and native traits objects.
// @0x1400199e0
void* FUN_1400199e0(void* traits, void* vm)
{
    return BuildVideoTraits(traits, vm, &VideoClassInfoA, &VideoClassVtableA, &VideoInstanceVtableA, 0xf8, &VideoCTraitsVtable);
}
// constructs the VideoPlayer AS3 class traits and its instance and native traits objects.
// @0x14001ad20
void* FUN_14001ad20(void* traits, void* vm)
{
    return BuildVideoTraits(traits, vm, &VideoClassInfoB, &VideoClassVtableB, &VideoInstanceVtableB, 0x78, 0);
}
namespace {

} // namespace: externally referenced Video native
namespace {
struct VideoStringDefaults2
{
    Scaleform::GFx::ASString a, b;
    VideoStringDefaults2(const Scaleform::GFx::ASString& x, const Scaleform::GFx::ASString& y) : a(x), b(y) {}
};
}
// dispatches the metadata or cue callback with converted AS3 string parameters.
// @0x140017520
void FUN_140017520(void*, void* vm, void* frame, uint64_t property, unsigned count, const uint64_t* args)
{
    using Scaleform::GFx::ASString;
    const uint64_t object = *reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(frame) + 0x10);
    unsigned char* vmImpl = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(vm) + 0x10);
    uint64_t record[4];
    {
        VideoStringDefaults2 defaults(ASString((*reinterpret_cast<Scaleform::GFx::ASStringManager**>(vmImpl + 0x1e8))->CreateConstStringNode("null", 4, 0)),
                                      ASString((*reinterpret_cast<Scaleform::GFx::ASStringManager**>(vmImpl + 0x1e8))->CreateConstStringNode("null", 4, 0)));
        FUN_140017130(record, reinterpret_cast<uintptr_t>(vm), property, count, args, reinterpret_cast<const uint64_t*>(&defaults));
    }
    struct Strings
    {
        uint64_t* r;
        ~Strings()
        {
            reinterpret_cast<ASString*>(&r[3])->~ASString();
            reinterpret_cast<ASString*>(&r[2])->~ASString();
        }
    } owner = {record};
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) != 0)
        return;
    void (*thunk)(uintptr_t, uint64_t, uint64_t*, uint64_t*) = reinterpret_cast<void(*)(uintptr_t, uint64_t, uint64_t*, uint64_t*)>(VideoStringCallbackA);
    thunk(object + *reinterpret_cast<const int*>(&VideoStringCallbackBaseA), record[1], &record[2], &record[3]);
}
namespace {

} // namespace: externally referenced Video native
namespace {
// the three default ASStrings of the subtitle thunk, laid out as FUN_140017130 reads them
struct VideoStringDefaults3
{
    Scaleform::GFx::ASString a, b, c;
    VideoStringDefaults3(const Scaleform::GFx::ASString& x, const Scaleform::GFx::ASString& y, const Scaleform::GFx::ASString& z) : a(x), b(y), c(z) {}
};
}
// Dispatches the subtitle callback with converted AS3 string parameters.
// @0x140017670
void FUN_140017670(void*, void* vm, void* frame, uint64_t property, unsigned count, const uint64_t* args)
{
    using Scaleform::GFx::ASString;
    const uint64_t object = *reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(frame) + 0x10);
    const Scaleform::GFx::AS3::StringManager& strings = **reinterpret_cast<Scaleform::GFx::AS3::StringManager**>(static_cast<unsigned char*>(vm) + 0x10);
    VideoStringDefaults3 defaults(strings.CreateEmptyString(), strings.CreateEmptyString(), strings.CreateEmptyString());
    uint64_t record[5];
    FUN_140017130(record, reinterpret_cast<uintptr_t>(vm), property, count, args, reinterpret_cast<const uint64_t*>(&defaults));
    ASString& third = *::new (&record[4]) ASString(defaults.c);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0 && count > 2) {
        const Scaleform::GFx::AS3::Value& arg = reinterpret_cast<const Scaleform::GFx::AS3::Value*>(args)[2];
        if (arg.IsNull())
            third.SetNull();
        else
            arg.Convert2String(third);
    }
    // the record's three strings die at every return, as the exe's Args3 destructor does
    struct Strings
    {
        uint64_t* r;
        ~Strings()
        {
            reinterpret_cast<ASString*>(&r[4])->~ASString();
            reinterpret_cast<ASString*>(&r[3])->~ASString();
            reinterpret_cast<ASString*>(&r[2])->~ASString();
        }
    } owner = {record};
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) != 0)
        return;
    void (*thunk)(uintptr_t, uint64_t, uint64_t*, uint64_t*, uint64_t*) = reinterpret_cast<void(*)(uintptr_t, uint64_t, uint64_t*, uint64_t*, uint64_t*)>(VideoStringCallbackB);
    thunk(object + *reinterpret_cast<const int*>(&VideoStringCallbackBaseB), record[1], &record[2], &record[3], &record[4]);
}
namespace {


} // namespace (sfr36: the natives below have external linkage, other units take their addresses)
// Creates the video metadata object, adds its standard fields, and returns a retained object atom.
// @0x1400192e0
void FUN_1400192e0(void* callback, uint64_t* output)
{
    // the VM comes from the instance itself (0x1400192f4: [[rcx+0x20]+0x78]), not from callback+0x10
    unsigned char* callFrame = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callback) + 0x20);
    unsigned char* as3vm = *reinterpret_cast<unsigned char**>(callFrame + 0x78);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> result = reinterpret_cast<Scaleform::GFx::AS3::VM*>(as3vm)->MakeObject();
    Scaleform::GFx::AS3::Object* object = reinterpret_cast<Scaleform::GFx::AS3::Object*>(result.GetPtr());
    unsigned char* vmImpl = *reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callback) + 0x20) + 0x78) + 0x10);
    {
        Scaleform::GFx::ASString name((*reinterpret_cast<Scaleform::GFx::ASStringManager**>(vmImpl + 0x1e8))->CreateStringNode("onMetaData"));
        object->AddDynamicSlotValuePair(name, *reinterpret_cast<Scaleform::GFx::AS3::Value*>(static_cast<unsigned char*>(callback) + 0x98));
    }
    {
        Scaleform::GFx::ASString name((*reinterpret_cast<Scaleform::GFx::ASStringManager**>(vmImpl + 0x1e8))->CreateStringNode("onCuePoint"));
        object->AddDynamicSlotValuePair(name, *reinterpret_cast<Scaleform::GFx::AS3::Value*>(static_cast<unsigned char*>(callback) + 0xb8));
    }
    {
        Scaleform::GFx::ASString name((*reinterpret_cast<Scaleform::GFx::ASStringManager**>(vmImpl + 0x1e8))->CreateStringNode("onSubtitle"));
        object->AddDynamicSlotValuePair(name, *reinterpret_cast<Scaleform::GFx::AS3::Value*>(static_cast<unsigned char*>(callback) + 0xd8));
    }
    *reinterpret_cast<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>*>(output) = result;
}
namespace {

namespace {
__forceinline void GetVideoSoundTransform(void* self, uint64_t* output, size_t fieldOffset)
{
    using namespace Scaleform::GFx::AS3;
    Value classValue;
    Value transform;
    VM* vm = *reinterpret_cast<VM**>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x20) + 0x78);
    vm->Construct("flash.media.SoundTransform", classValue, 0, 0, true);
    if (vm->IsException() || classValue.IsNullOrUndefined())
        return;
    SPtr<Instances::fl_media::SoundTransform> sound = static_cast<Instances::fl_media::SoundTransform*>(classValue.GetObject());
    sound->volumeSet(transform, *reinterpret_cast<double*>(static_cast<unsigned char*>(self) + fieldOffset));
    *reinterpret_cast<SPtr<Instances::fl_media::SoundTransform>*>(output) = sound;
}
}
} // namespace (sfr36: the natives below have external linkage, other units take their addresses)
// Resolves flash.media.SoundTransform and applies the instance's current transform value.
// @0x140019470
void FUN_140019470(void* self, uint64_t* output) { GetVideoSoundTransform(self, output, 0x88); }
// Resolves flash.media.SoundTransform and applies the instance's default transform value.
// @0x140019660
void FUN_140019660(void* self, uint64_t* output) { GetVideoSoundTransform(self, output, 0x90); }
namespace {
// the instance's VM, [[self+0x20]+0x78]
__forceinline unsigned char* VideoSelfVM(void* self)
{
    return *reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x20) + 0x78);
}
}
// Reads the three event handler properties from the attached AS3 stream object.
// @0x140017f20
void FUN_140017f20(void* self, void*, void* frame)
{
    using namespace Scaleform::GFx::AS3;
    Object* source = *reinterpret_cast<Object**>(static_cast<unsigned char*>(frame) + 0x10);
    const StringManager& strings = **reinterpret_cast<StringManager**>(VideoSelfVM(self) + 0x10);
    Value value;
    Multiname metaData(static_cast<Object*>(self)->GetVM().GetPublicNamespace(),
                       Scaleform::GFx::ASString(strings.GetStringManager()->CreateStringNode("onMetaData")));
    Multiname cuePoint(static_cast<Object*>(self)->GetVM().GetPublicNamespace(),
                       Scaleform::GFx::ASString(strings.GetStringManager()->CreateStringNode("onCuePoint")));
    Multiname subtitle(static_cast<Object*>(self)->GetVM().GetPublicNamespace(),
                       Scaleform::GFx::ASString(strings.GetStringManager()->CreateStringNode("onSubtitle")));
    if (source->GetProperty(metaData, value))
        reinterpret_cast<Value*>(static_cast<unsigned char*>(self) + 0x98)->Assign(value);
    if (source->GetProperty(cuePoint, value))
        reinterpret_cast<Value*>(static_cast<unsigned char*>(self) + 0xb8)->Assign(value);
    if (source->GetProperty(subtitle, value))
        reinterpret_cast<Value*>(static_cast<unsigned char*>(self) + 0xd8)->Assign(value);
}
namespace {

} // namespace: externally referenced Video native
// builds the metadata object from CRI stream dimensions and track counts, then invokes its callback.
// @0x1400182f0
void FUN_1400182f0(void* callback, const uint32_t* info)
{
    using namespace Scaleform::GFx::AS3;
    using Scaleform::GFx::ASString;
    // The onMetaData handler Value lives in the AS3 object at callback+0x10, at +0x98.
    if (reinterpret_cast<Value*>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callback) + 0x10) + 0x98)->IsNullOrUndefined())
        return;
    unsigned char* vmRoot = *reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callback) + 0x10) + 0x20) + 0x78);
    unsigned char* vmImpl = *reinterpret_cast<unsigned char**>(vmRoot + 0x10);
    SPtr<Instances::fl::Object> object = reinterpret_cast<VM*>(vmRoot)->MakeObject();
    Scaleform::GFx::ASStringManager* const& manager = *reinterpret_cast<Scaleform::GFx::ASStringManager**>(vmImpl + 0x1e8);
    // width, height and subtitleTracksCount are AS3 ints (kind 2), the other counts uints (kind 3).
    object->AddDynamicSlotValuePair(ASString(manager->CreateStringNode("duration")),
                                    Value(static_cast<double>((static_cast<float>(info[4]) * VideoDurationScale) / static_cast<float>(info[2]))));
    object->AddDynamicSlotValuePair(ASString(manager->CreateStringNode("width")), Value(static_cast<Scaleform::SInt32>(info[0])));
    object->AddDynamicSlotValuePair(ASString(manager->CreateStringNode("height")), Value(static_cast<Scaleform::SInt32>(info[1])));
    object->AddDynamicSlotValuePair(ASString(manager->CreateStringNode("totalFrames")), Value(static_cast<Scaleform::UInt32>(info[4])));
    object->AddDynamicSlotValuePair(ASString(manager->CreateStringNode("frameRate")), Value(static_cast<double>(static_cast<float>(info[2]) / VideoDurationScale)));
    object->AddDynamicSlotValuePair(ASString(manager->CreateStringNode("subtitleTracksCount")), Value(static_cast<Scaleform::SInt32>(info[0xc])));
    object->AddDynamicSlotValuePair(ASString(manager->CreateStringNode("audioTracksCount")), Value(static_cast<Scaleform::UInt32>(info[0x10])));
    object->AddDynamicSlotValuePair(ASString(manager->CreateStringNode("cuePointsCount")), Value(static_cast<Scaleform::UInt32>(info[8])));
    Value result;
    Value argument(object);
    VM& callVm = *reinterpret_cast<VM*>(*reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callback) + 0x10) + 0x20) + 0x78));
    const Value& thisValue = Value::GetUndefined();
    callVm.ExecuteInternalUnsafe(*reinterpret_cast<Value*>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callback) + 0x10) + 0x98),
                                thisValue, result, 1, &argument, false);
    VM& vm = *reinterpret_cast<VM*>(*reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callback) + 0x10) + 0x20) + 0x78));
    if (vm.IsException())
        vm.OutputAndIgnoreException();
}
namespace {


} // namespace
// MovieDefImpl::GetCharacterCreateInfo(rid) with its hidden return slot spelled out (as in sfr_as2_01).
typedef Scaleform::GFx::CharacterCreateInfo* (Scaleform::GFx::MovieDefImpl::*MS2_GetCreateInfoFn)(
    Scaleform::GFx::CharacterCreateInfo* pret, const Scaleform::GFx::ResourceId* prid);
// SDK ToAvmDisplayObj: the AVM object sits AvmObjOffset (byte at +0x6d) dwords into the display object.
static __forceinline unsigned char* VideoToAvmDisplayObj(void* po)
{
    if (!po)
        return 0;
    return reinterpret_cast<unsigned char*>(reinterpret_cast<uint32_t*>(po) + static_cast<unsigned char*>(po)[0x6d]);
}
// Video::CreateStageObject: resolves and creates the Video display character from the owning MovieDef.
// @0x14001a470
void* FUN_14001a470(void* self)
{
    void** slot = reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x58);
    if (!*slot) {
        unsigned char* root = *reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x20) + 0x78);
        unsigned char* library = *reinterpret_cast<unsigned char**>(root + 0x2d8);
        void* movieDef = FUN_14250d8f0(*reinterpret_cast<Scaleform::GFx::AS3::VM*>(root), static_cast<const Scaleform::GFx::AS3::Instances::fl::Object*>(self));
        if (movieDef) {
            Scaleform::GFx::CharacterCreateInfo createInfo;
            createInfo.pBindDefImpl = 0;
            createInfo.pResource = 0;
            createInfo.pCharDef = 0;
            Scaleform::GFx::AS3::Instances::fl_display::FindLibrarySymbol(static_cast<const Scaleform::GFx::AS3::Instances::fl_display::DisplayObject*>(self), &createInfo,
                static_cast<Scaleform::GFx::MovieDefImpl*>(movieDef));
            if (!createInfo.pCharDef) {
                // no symbol for the class: the exe falls back to the empty Video character (ResourceId 0x10005)
                __declspec(align(8)) uint64_t tmp[3];
                const Scaleform::GFx::ResourceId emptyVideoId(0x10005);
                memcpy(&createInfo, (static_cast<Scaleform::GFx::MovieDefImpl*>(movieDef)->*reinterpret_cast<MS2_GetCreateInfoFn>(
                    &Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo))(reinterpret_cast<Scaleform::GFx::CharacterCreateInfo*>(tmp), &emptyVideoId),
                    sizeof(createInfo));
            }
            // the ASSupport pointer is read inside the call (SDK proot->GetASSupport()->...), after the ResourceId() store
            void* display = (*reinterpret_cast<Scaleform::GFx::ASSupport**>(library + 0x18))->CreateCharacterInstance(
                *reinterpret_cast<Scaleform::GFx::MovieImpl**>(library + 0x10), createInfo, 0, Scaleform::GFx::ResourceId(),
                Scaleform::GFx::CharacterDef::Video);
            if (*slot) FUN_14257dcd0(*slot);
            *slot = display;
            unsigned char* frame = VideoToAvmDisplayObj(display);
            Scaleform::GFx::AS3::Sfr33SetValueDropObject(frame, self);
        }
    }
    return *slot;
}
namespace {

} // namespace: externally referenced Video native
// interns a String DataDesc atom (size at +0, chars at +0xc)
static __forceinline Scaleform::GFx::ASStringNode* VideoInternString(Scaleform::GFx::ASStringManager* strings, const uint64_t* atom)
{
    const char* desc = reinterpret_cast<const char*>(*atom & ~uint64_t(3));
    return strings->CreateStringNode(desc + 0xc, *reinterpret_cast<const uint64_t*>(desc) & 0x7fffffffffffffffull);
}
// creates a callback property object from the supplied AS3 strings and binds it to this stream.
// @0x140019890
void FUN_140019890(void* self, const uint64_t* firstAtom, const uint64_t* secondAtom)
{
    using Scaleform::GFx::ASString;
    // MS2: as exe 0x14001989c: the atoms are String DataDescs (size at +0, chars at +0xc), interned by the
    // ASStringManager at [[[[self+0x10]+0x20]+0x78]+0x10]+0x1e8; they are not ASStringNodes.
    unsigned char* vmImpl = *reinterpret_cast<unsigned char**>(
        *reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x10) + 0x20) + 0x78) + 0x10);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> result =
        (*reinterpret_cast<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher**>(static_cast<unsigned char*>(self) + 0x10))->CreateNetStatusEventObject(
            ASString(VideoInternString(*reinterpret_cast<Scaleform::GFx::ASStringManager**>(vmImpl + 0x1e8), firstAtom)),
            ASString(VideoInternString(*reinterpret_cast<Scaleform::GFx::ASStringManager**>(vmImpl + 0x1e8), secondAtom)));
    uint64_t currentVm = *reinterpret_cast<uint64_t*>(static_cast<unsigned char*>(self) + 0x10);
    uint64_t* owner = reinterpret_cast<uint64_t*>(reinterpret_cast<unsigned char*>(result.GetPtr()) + 0x48);
    if (currentVm != *owner) {
        ReleaseVideoAtom(owner);
        RetainVideoAtom(currentVm);
        *owner = currentVm;
    }
    (*reinterpret_cast<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher**>(static_cast<unsigned char*>(self) + 0x10))->DispatchSingleEvent(result.GetPtr(), false);
}
namespace {


} // namespace: externally referenced Video native
// copies a Scaleform::String data atom into a new ASString node
static __forceinline Scaleform::GFx::ASStringNode* VideoCopyString(Scaleform::GFx::ASStringManager* manager, uint64_t atom)
{
    const unsigned char* desc = reinterpret_cast<const unsigned char*>(atom & ~uint64_t(3));
    return manager->CreateStringNode(reinterpret_cast<const char*>(desc + 0xc),
                                     *reinterpret_cast<const uint64_t*>(desc) & 0x7fffffffffffffffull);
}
namespace {
// the cue callback owner's VM, [[[callback+0x10]+0x20]+0x78]
__forceinline Scaleform::GFx::AS3::VM& VideoSelfVMRef(void* callback)
{
    return *reinterpret_cast<Scaleform::GFx::AS3::VM*>(VideoSelfVM(*reinterpret_cast<void**>(static_cast<unsigned char*>(callback) + 0x10)));
}
}
// MS2-FUNCTIONAL: builds a CRI subtitle/cue event object with its name, timestamp, type and parameter map. Remaining diffs (267 lines): name/type key-vs-Value construction order, an extra loop-alignment nop, and the type ternary temp kept in rsi in the exe.
// @0x140018930
void FUN_140018930(void* callback, const uint32_t* eventData)
{
    using namespace Scaleform::GFx::AS3;
    using Scaleform::GFx::ASString;
    // The handler Value lives in the AS3 object at callback+0x10 (exe: mov rdx,[rcx+0x10]; [rdx+0xb8]), not in callback.
    if (reinterpret_cast<Value*>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callback) + 0x10) + 0xb8)->IsNullOrUndefined())
        return;
    unsigned char* vmImpl = *reinterpret_cast<unsigned char**>(VideoSelfVM(*reinterpret_cast<void**>(static_cast<unsigned char*>(callback) + 0x10)) + 0x10);
    SPtr<Instances::fl::Object> event = reinterpret_cast<VM*>(VideoSelfVM(*reinterpret_cast<void**>(static_cast<unsigned char*>(callback) + 0x10)))->MakeObject();
    Scaleform::GFx::ASStringManager* const& manager = *reinterpret_cast<Scaleform::GFx::ASStringManager**>(vmImpl + 0x1e8);
    // The cue strings are Scaleform::String data pointers (low 2 bits are flags): size at +0 (top bit is a flag),
    // chars at +0xc. The exe copies each into a new ASString node (0x1425c0a80); they are not ASStringNodes.
    { ASString name(VideoCopyString(manager, *reinterpret_cast<const uint64_t*>(eventData + 2))); Scaleform::GFx::ASStringNode* key = manager->CreateStringNode("name"); event->AddDynamicSlotValuePair(ASString(key), name); }
    event->AddDynamicSlotValuePair(ASString(manager->CreateStringNode("time")), Value(static_cast<double>(static_cast<float>(eventData[4]) / VideoDurationScale)));
    event->AddDynamicSlotValuePair(ASString(manager->CreateStringNode("type")),
                                   eventData[0] == 1 ? ASString(manager->CreateStringNode("navigation")) : ASString(manager->CreateStringNode("event")));
    {
        // The exe always adds "parameters" as an empty string; a non-empty cue point then replaces it with an object.
        ASString empty(manager->GetEmptyStringNode());
        event->AddDynamicSlotValuePair(ASString(manager->CreateStringNode("parameters")), empty);
    }
    if (*reinterpret_cast<const uint64_t*>(eventData + 8) > 0) {
        SPtr<Instances::fl::Object> parameters = reinterpret_cast<VM*>(VideoSelfVM(*reinterpret_cast<void**>(static_cast<unsigned char*>(callback) + 0x10)))->MakeObject();
        for (uint64_t i = 0; i < *reinterpret_cast<const uint64_t*>(eventData + 8); ++i) {
            const uint64_t* const& pairs = *reinterpret_cast<const uint64_t* const*>(eventData + 6);
            ASString text(VideoCopyString(manager, pairs[i * 2 + 1]));
            parameters->AddDynamicSlotValuePair(ASString(VideoCopyString(manager, pairs[i * 2])), text);
        }
        event->AddDynamicSlotValuePair(ASString(manager->CreateStringNode("parameters")), Value(parameters));
    }
    Value result;
    Value argument(event);
    VM& callVm = VideoSelfVMRef(callback);
    const Value& thisValue = Value::GetUndefined();
    callVm.ExecuteInternalUnsafe(*reinterpret_cast<Value*>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callback) + 0x10) + 0xb8),
                                 thisValue, result, 1, &argument, false);
    VM& vm = VideoSelfVMRef(callback);
    if (vm.IsException()) {
        vm.HandleException = false;
        vm.OutputError(vm.ExceptionObj);
        vm.ExceptionObj.SetUndefined();
    }
}

// MS2: VideoPlayer.clear's thunk (instance ThunkInfo table 0x1431b79e0, entry 8) was never recovered;
// same member-pointer forwarding as the other video thunks (exe: movsxd rcx,[143b27790]; add rcx,[r8+10]; jmp [143b27788]).
extern ExeDecl<void*>::type DAT_143b27788;
extern ExeDecl<int>::type DAT_143b27790;
// @0x14001a180
void FUN_14001a180(void*, void*, void* callFrame, void* result)
{
    unsigned char* root = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callFrame) + 0x10);
    reinterpret_cast<void(*)(void*, void*)>(DAT_143b27788)(root + DAT_143b27790, result);
}

// The AS3 part of a Video display object (flash.media.Video): AvmInteractiveObj with the AvmVideoCharacterBase part at
// +0x40 and its own fields at +0x48 (ctor FUN_14001af70). Vftables 0x1431b7f60 (+0x00), 0x1431b7ea0 (+0x30) and
// 0x1431b7de0 (+0x40). The overriders are the leaves above at their exe VAs (declared here, symbols-manual rows), so
// the two secondary tables' slots are cl's own adjustor thunks (sub rcx,N; jmp member), which are the exe ones in
// 0x14001b160-0x14001b390. Sfr03EmitAvmVideoVftables copy-constructs one so that cl emits the vftables and thunks.
namespace Scaleform { namespace GFx {
class __declspec(novtable) AvmVideoCharacterBase : public AvmInteractiveObjBase
{
};
namespace AS3 {
class AvmVideoCharacter : public AvmInteractiveObj, public AvmVideoCharacterBase
{
public:
    // the AS3 part lives inside its display object's allocation: the deleting destructor (0x14001b3a0) frees nothing
    // (implicit destructor: the exe's 0x14001b3a0 stores no AvmVideoCharacter vftable)
    void operator delete(void*) {}

    virtual AvmInteractiveObjBase*      ToAvmInteractiveObjBase();      // 0x14001afe0
    virtual AvmSpriteBase*              ToAvmSpriteBase();              // 0x14001b000
    virtual AvmButtonBase*              ToAvmButttonBase();             // 0x14001b010
    virtual AvmTextFieldBase*           ToAvmTextFieldBase();           // 0x14001b020
    virtual AvmDisplayObjContainerBase* ToAvmDispContainerBase();       // 0x14001b030
    virtual const char* GetAbsolutePath(String* ppath) const;           // 0x14001b0a0
    virtual bool        HasEventHandler(const EventId& id) const;       // 0x14001b080
    virtual bool        OnEvent(const EventId& id);                     // 0x14001b040
    virtual void        OnEventLoad();                                  // 0x14001b050
    virtual void        OnEventUnload();                                // 0x14001b060
    virtual bool        OnUnloading(bool mayRemove);                    // 0x14001b070
    virtual AvmVideoCharacterBase* ToAvmVideoCharacterBase();           // 0x14001afd0
    virtual const char* GetDefaultASClassName() const;                  // 0x14001aff0

    virtual bool     ActsAsButton() const;                              // 0x14001b090
    virtual unsigned GetCursorType() const;                             // 0x14001b0b0
    virtual void     CloneInternalData(const InteractiveObject* src);   // 0x14001b0c0
    virtual void     CopyPhysicalProperties(const InteractiveObject* poldChar);    // 0x14001b0d0
    virtual void     OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                             unsigned controllerIdx, FocusMovedType fmt);          // 0x14001b0e0
    virtual void     OnGettingKeyboardFocus(unsigned controllerIdx, FocusMovedType fmt);   // 0x14001b100
    virtual bool     OnKeyEvent(const EventId& id, int* pkeyMask);      // 0x14001b110
    virtual bool     OnLosingKeyboardFocus(InteractiveObject* newFocusCh, unsigned controllerIdx,
                                           FocusMovedType fmt = GFx_FocusMovedByKeyboard);  // 0x14001b120
    virtual bool     IsFocusEnabled(FocusMovedType fmt = GFx_FocusMovedByKeyboard) const;   // 0x14001b130
    virtual bool     IsTabable() const;                                 // 0x14001b140

    UInt32  FieldA, FieldB, FieldC;     // +0x48
    bool    Flag;                       // +0x54
};
void Sfr03EmitAvmVideoVftables(void* p, const AvmVideoCharacter* pvideo)
{
    new (p) AvmVideoCharacter(*pvideo);
}

// AvmVideoCharacter's own leaves and its forwards to the AvmInteractiveObj / AvmDisplayObj versions.
// @0x14001afd0
AvmVideoCharacterBase* AvmVideoCharacter::ToAvmVideoCharacterBase() { return this; }
// @0x14001afe0
AvmInteractiveObjBase* AvmVideoCharacter::ToAvmInteractiveObjBase() { return static_cast<AvmInteractiveObj*>(this); }
// @0x14001aff0
const char* AvmVideoCharacter::GetDefaultASClassName() const { return "flash.media.Video"; }
// @0x14001b000
AvmSpriteBase* AvmVideoCharacter::ToAvmSpriteBase() { return NULL; }
// @0x14001b010
AvmButtonBase* AvmVideoCharacter::ToAvmButttonBase() { return NULL; }
// @0x14001b020
AvmTextFieldBase* AvmVideoCharacter::ToAvmTextFieldBase() { return NULL; }
// @0x14001b030
AvmDisplayObjContainerBase* AvmVideoCharacter::ToAvmDispContainerBase() { return NULL; }
// @0x14001b040
bool AvmVideoCharacter::OnEvent(const EventId& id) { return AvmInteractiveObj::OnEvent(id); }
// @0x14001b050
void AvmVideoCharacter::OnEventLoad() { AvmInteractiveObj::OnEventLoad(); }
// @0x14001b060
void AvmVideoCharacter::OnEventUnload() { AvmInteractiveObj::OnEventUnload(); }
// @0x14001b070
bool AvmVideoCharacter::OnUnloading(bool) { return true; }
// @0x14001b080
bool AvmVideoCharacter::HasEventHandler(const EventId& id) const { return AvmInteractiveObj::HasEventHandler(id); }
// @0x14001b090
bool AvmVideoCharacter::ActsAsButton() const { return true; }
// @0x14001b0a0
const char* AvmVideoCharacter::GetAbsolutePath(String* ppath) const { return AvmDisplayObj::GetAbsolutePath(ppath); }
// @0x14001b0b0
unsigned AvmVideoCharacter::GetCursorType() const { return 0; }
// @0x14001b0c0
void AvmVideoCharacter::CloneInternalData(const InteractiveObject* src) { AvmInteractiveObj::CloneInternalData(src); }
// @0x14001b0d0
void AvmVideoCharacter::CopyPhysicalProperties(const InteractiveObject* poldChar)
{
    AvmInteractiveObj::CopyPhysicalProperties(poldChar);
}
// @0x14001b0e0
void AvmVideoCharacter::OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                                unsigned controllerIdx, FocusMovedType fmt)
{
    AvmInteractiveObj::OnFocus(event, oldOrNewFocusCh, controllerIdx, fmt);
}
// @0x14001b100
void AvmVideoCharacter::OnGettingKeyboardFocus(unsigned, FocusMovedType) {}
// @0x14001b110
bool AvmVideoCharacter::OnKeyEvent(const EventId&, int*) { return false; }
// @0x14001b120
bool AvmVideoCharacter::OnLosingKeyboardFocus(InteractiveObject*, unsigned, FocusMovedType) { return true; }
// @0x14001b130
bool AvmVideoCharacter::IsFocusEnabled(FocusMovedType) const { return true; }
// @0x14001b140
bool AvmVideoCharacter::IsTabable() const { return AvmInteractiveObj::IsTabable(); }
}}} // namespace Scaleform::GFx::AS3

// The AvmVideoCharacter model's vftables and its bases' (pinned as in sfr_as3_17; Scaleform has no RTTI), its
// deleting destructor and cl's adjustor thunks for the 0x1431b7de0 / 0x1431b7ea0 slots.
// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
// MS2-PIN: ??_7AvmInteractiveObjBase@GFx@Scaleform@@6B@ 0x14317bfe8
// MS2-PIN: ??_7AvmDisplayObj@AS3@GFx@Scaleform@@6B@ 0x14317c160
// MS2-PIN: ??_7AvmInteractiveObj@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317ca60
// MS2-PIN: ??_7AvmInteractiveObj@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317cb30
// MS2-PIN: ??_7AvmVideoCharacter@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x1431b7f60
// MS2-PIN: ??_7AvmVideoCharacter@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x1431b7ea0
// MS2-PIN: ??_7AvmVideoCharacter@AS3@GFx@Scaleform@@6B@ 0x1431b7de0
// MS2-PIN: ??_GAvmVideoCharacter@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14001b3a0
// MS2-PIN: ??_EAvmVideoCharacter@AS3@GFx@Scaleform@@WDA@EAAPEAXI@Z 0x14001b2f0
// MS2-PIN: ??_EAvmVideoCharacter@AS3@GFx@Scaleform@@WEA@EAAPEAXI@Z 0x14001b1e0
// MS2-PIN: ?ActsAsButton@AvmVideoCharacter@AS3@GFx@Scaleform@@WBA@EBA_NXZ 0x14001b210
// MS2-PIN: ?CloneInternalData@AvmVideoCharacter@AS3@GFx@Scaleform@@WBA@EAAXPEBVInteractiveObject@34@@Z 0x14001b240
// MS2-PIN: ?CopyPhysicalProperties@AvmVideoCharacter@AS3@GFx@Scaleform@@WBA@EAAXPEBVInteractiveObject@34@@Z 0x14001b190
// MS2-PIN: ?GetAbsolutePath@AvmVideoCharacter@AS3@GFx@Scaleform@@WDA@EBAPEBDPEAVString@4@@Z 0x14001b360
// MS2-PIN: ?GetAbsolutePath@AvmVideoCharacter@AS3@GFx@Scaleform@@WEA@EBAPEBDPEAVString@4@@Z 0x14001b270
// MS2-PIN: ?GetCursorType@AvmVideoCharacter@AS3@GFx@Scaleform@@WBA@EBAIXZ 0x14001b330
// MS2-PIN: ?HasEventHandler@AvmVideoCharacter@AS3@GFx@Scaleform@@WDA@EBA_NAEBVEventId@34@@Z 0x14001b300
// MS2-PIN: ?HasEventHandler@AvmVideoCharacter@AS3@GFx@Scaleform@@WEA@EBA_NAEBVEventId@34@@Z 0x14001b1f0
// MS2-PIN: ?IsFocusEnabled@AvmVideoCharacter@AS3@GFx@Scaleform@@WBA@EBA_NW4FocusMovedType@34@@Z 0x14001b160
// MS2-PIN: ?IsTabable@AvmVideoCharacter@AS3@GFx@Scaleform@@WBA@EBA_NXZ 0x14001b370
// MS2-PIN: ?OnEvent@AvmVideoCharacter@AS3@GFx@Scaleform@@WDA@EAA_NAEBVEventId@34@@Z 0x14001b320
// MS2-PIN: ?OnEvent@AvmVideoCharacter@AS3@GFx@Scaleform@@WEA@EAA_NAEBVEventId@34@@Z 0x14001b220
// MS2-PIN: ?OnEventLoad@AvmVideoCharacter@AS3@GFx@Scaleform@@WDA@EAAXXZ 0x14001b260
// MS2-PIN: ?OnEventLoad@AvmVideoCharacter@AS3@GFx@Scaleform@@WEA@EAAXXZ 0x14001b350
// MS2-PIN: ?OnEventUnload@AvmVideoCharacter@AS3@GFx@Scaleform@@WDA@EAAXXZ 0x14001b2b0
// MS2-PIN: ?OnEventUnload@AvmVideoCharacter@AS3@GFx@Scaleform@@WEA@EAAXXZ 0x14001b1a0
// MS2-PIN: ?OnFocus@AvmVideoCharacter@AS3@GFx@Scaleform@@WBA@EAAXW4FocusEventType@InteractiveObject@34@PEAV634@IW4FocusMovedType@34@@Z 0x14001b290
// MS2-PIN: ?OnGettingKeyboardFocus@AvmVideoCharacter@AS3@GFx@Scaleform@@WBA@EAAXIW4FocusMovedType@34@@Z 0x14001b230
// MS2-PIN: ?OnKeyEvent@AvmVideoCharacter@AS3@GFx@Scaleform@@WBA@EAA_NAEBVEventId@34@PEAH@Z 0x14001b180
// MS2-PIN: ?OnLosingKeyboardFocus@AvmVideoCharacter@AS3@GFx@Scaleform@@WBA@EAA_NPEAVInteractiveObject@34@IW4FocusMovedType@34@@Z 0x14001b380
// MS2-PIN: ?OnUnloading@AvmVideoCharacter@AS3@GFx@Scaleform@@WDA@EAA_N_N@Z 0x14001b1d0
// MS2-PIN: ?OnUnloading@AvmVideoCharacter@AS3@GFx@Scaleform@@WEA@EAA_N_N@Z 0x14001b2e0
// MS2-PIN: ?ToAvmButttonBase@AvmVideoCharacter@AS3@GFx@Scaleform@@WDA@EAAPEAVAvmButtonBase@34@XZ 0x14001b390
// MS2-PIN: ?ToAvmButttonBase@AvmVideoCharacter@AS3@GFx@Scaleform@@WEA@EAAPEAVAvmButtonBase@34@XZ 0x14001b280
// MS2-PIN: ?ToAvmDispContainerBase@AvmVideoCharacter@AS3@GFx@Scaleform@@WDA@EAAPEAVAvmDisplayObjContainerBase@34@XZ 0x14001b310
// MS2-PIN: ?ToAvmDispContainerBase@AvmVideoCharacter@AS3@GFx@Scaleform@@WEA@EAAPEAVAvmDisplayObjContainerBase@34@XZ 0x14001b200
// MS2-PIN: ?ToAvmInteractiveObjBase@AvmVideoCharacter@AS3@GFx@Scaleform@@WDA@EAAPEAVAvmInteractiveObjBase@34@XZ 0x14001b170
// MS2-PIN: ?ToAvmInteractiveObjBase@AvmVideoCharacter@AS3@GFx@Scaleform@@WEA@EAAPEAVAvmInteractiveObjBase@34@XZ 0x14001b2a0
// MS2-PIN: ?ToAvmSpriteBase@AvmVideoCharacter@AS3@GFx@Scaleform@@WDA@EAAPEAVAvmSpriteBase@34@XZ 0x14001b1b0
// MS2-PIN: ?ToAvmSpriteBase@AvmVideoCharacter@AS3@GFx@Scaleform@@WEA@EAAPEAVAvmSpriteBase@34@XZ 0x14001b2c0
// MS2-PIN: ?ToAvmTextFieldBase@AvmVideoCharacter@AS3@GFx@Scaleform@@WDA@EAAPEAVAvmTextFieldBase@34@XZ 0x14001b1c0
// MS2-PIN: ?ToAvmTextFieldBase@AvmVideoCharacter@AS3@GFx@Scaleform@@WEA@EAAPEAVAvmTextFieldBase@34@XZ 0x14001b2d0
// MS2-PIN: ?ToAvmVideoCharacterBase@AvmVideoCharacter@AS3@GFx@Scaleform@@WDA@EAAPEAVAvmVideoCharacterBase@34@XZ 0x14001b340
// MS2-PIN: ?ToAvmVideoCharacterBase@AvmVideoCharacter@AS3@GFx@Scaleform@@WEA@EAAPEAVAvmVideoCharacterBase@34@XZ 0x14001b250
