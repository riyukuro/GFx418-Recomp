// Recovered Scaleform GFx video player glue from the executable; SDK material is reference only.
// MS2-UNIT: sfr_video_03
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140016b50-0x14001c000 .text$mn
// MS2-RANGE: 0x142742ed0-0x1427433f0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/video/video_video.h"
#include "../include/video/video_videoplayerimpl.h"
#include "../include/gfx/gfx_stream.h"
#include "../include/kernel/sf_array.h"
#include "../include/gfx/as3/as3_value.h"
#include "../include/gfx/as3/as3_obj.h"
#include "../include/gfx/as3/as3_vm.h"
#include "../include/gfx/as3/obj/as3_obj_display.h"
#include "hook/ms2hook.h"
#include <cstring>
#include <cstdint>
#include <new>
#include <limits>

// The exe functions and globals this unit uses but does not define, declared by their FUN_<va> / DAT_<va> names: the
// hook DLL binds them to the exe, the full exe to the recovered definition at that VA (tools/fullexe/alias.py).
template <class T> using ExeDecl = T;

extern ExeDecl<void*> DAT_143b27608;
#define VideoThunkA DAT_143b27608
extern ExeDecl<void*> DAT_143b27610;
#define VideoThunkBaseA DAT_143b27610
extern ExeDecl<void*> DAT_143b27588;
#define VideoThunkB DAT_143b27588
extern ExeDecl<void*> DAT_143b27590;
#define VideoThunkBaseB DAT_143b27590
extern ExeDecl<void*> DAT_143b27708;
#define VideoThunkC DAT_143b27708
extern ExeDecl<void*> DAT_143b27710;
#define VideoThunkBaseC DAT_143b27710
extern ExeDecl<void*> DAT_143b275f8;
#define VideoThunkD DAT_143b275f8
extern ExeDecl<void*> DAT_143b27600;
#define VideoThunkBaseD DAT_143b27600
extern ExeDecl<void*> DAT_143b27638;
#define VideoThunkE DAT_143b27638
extern ExeDecl<void*> DAT_1431b7ba0;
#define VideoDisplayVtable DAT_1431b7ba0
static const float VideoTwipsScale = 20.0f;         // exe 0x142d692bc
static const float VideoDurationScale = 1000.0f;    // exe 0x142d15c1c
extern ExeDecl<void*> DAT_143b27640;
#define VideoThunkBaseE DAT_143b27640
extern ExeDecl<void*> DAT_143b27488;
#define VideoThunkF DAT_143b27488
extern ExeDecl<void*> DAT_143b27490;
#define VideoThunkBaseF DAT_143b27490
extern ExeDecl<void*> DAT_143b27528;
#define VideoCallbackA DAT_143b27528
extern ExeDecl<void*> DAT_143b27530;
#define VideoCallbackBaseA DAT_143b27530
extern ExeDecl<void*> DAT_143b27548;
#define VideoCallbackB DAT_143b27548
extern ExeDecl<void*> DAT_143b27550;
#define VideoCallbackBaseB DAT_143b27550
extern ExeDecl<void*> DAT_143b275e8;
#define VideoCallbackC DAT_143b275e8
extern ExeDecl<void*> DAT_143b27798; extern ExeDecl<void*> DAT_143b277a0;
#define VideoPropGetA DAT_143b27798
#define VideoPropBaseA DAT_143b277a0
extern ExeDecl<void*> DAT_143b27778; extern ExeDecl<void*> DAT_143b27780;
#define VideoPropSetA DAT_143b27778
#define VideoPropBaseSetA DAT_143b27780
extern ExeDecl<void*> DAT_143b27758; extern ExeDecl<void*> DAT_143b27760;
#define VideoPropGetB DAT_143b27758
#define VideoPropBaseB DAT_143b27760
extern ExeDecl<void*> DAT_143b27728; extern ExeDecl<void*> DAT_143b27730;
#define VideoPropSetB DAT_143b27728
#define VideoPropBaseSetB DAT_143b27730
extern ExeDecl<void*> DAT_143b27738; extern ExeDecl<void*> DAT_143b27740;
#define VideoPropGetC DAT_143b27738
#define VideoPropBaseC DAT_143b27740
extern ExeDecl<void*> DAT_143b27748; extern ExeDecl<void*> DAT_143b27750;
#define VideoPropGetD DAT_143b27748
#define VideoPropBaseD DAT_143b27750
extern ExeDecl<void*> DAT_143b27768; extern ExeDecl<void*> DAT_143b27770;
#define VideoPropSetC DAT_143b27768
#define VideoPropBaseSetC DAT_143b27770
extern ExeDecl<void*> DAT_143b27718; extern ExeDecl<void*> DAT_143b27720;
#define VideoPropSetD DAT_143b27718
#define VideoPropBaseSetD DAT_143b27720
extern ExeDecl<void*> DAT_143b276d8; extern ExeDecl<void*> DAT_143b276e0;
#define VideoStringCallbackA DAT_143b276d8
#define VideoStringCallbackBaseA DAT_143b276e0
extern ExeDecl<void*> DAT_143b27598; extern ExeDecl<void*> DAT_143b275a0;
#define VideoStringCallbackB DAT_143b27598
#define VideoStringCallbackBaseB DAT_143b275a0
extern ExeDecl<void*> DAT_143b277a8;
#define VideoCriWork DAT_143b277a8
extern ExeDecl<std::uint32_t> DAT_143b277b0;
#define VideoCriWorkSize DAT_143b277b0
extern ExeDecl<int> DAT_143b277b4;
#define VideoCriUsers DAT_143b277b4
extern ExeDecl<void*> DAT_143b275f0;
#define VideoCallbackBaseC DAT_143b275f0

ExeDecl<void(void*, void*, void*)> FUN_1423df980;
#define VideoNative0 FUN_1423df980
ExeDecl<void(void*, void*, void*)> FUN_1423df850;
#define VideoNative1 FUN_1423df850
ExeDecl<void(void*, void*, void*)> FUN_1423dfd20;
#define VideoNative2 FUN_1423dfd20
ExeDecl<void(void*, void*, void*)> FUN_1423df410;
#define VideoNative3 FUN_1423df410
ExeDecl<void(void*, void*, void*)> FUN_1423dfda0;
#define VideoNative4 FUN_1423dfda0
ExeDecl<void(void*, void*, void*)> FUN_1424f1390;
#define ConvertAS3ValueToString FUN_1424f1390
ExeDecl<void(void*, void*, int*, int, void*)> FUN_1424f0d30;
#define ConvertAS3ValueToInt32 FUN_1424f0d30
ExeDecl<std::uint8_t(void*)> FUN_1424f0be0;
#define ConvertAS3ValueToBool FUN_1424f0be0
ExeDecl<void()> FUN_1423dfa20;
#define ReleaseAS3GcObject FUN_1423dfa20
ExeDecl<void(void*)> FUN_14257dc30;
ExeDecl<void(void*)> FUN_14257dcd0;
ExeDecl<void(void*)> FUN_14257dcb0;
ExeDecl<bool(void*, void*)> FUN_142518c70;
ExeDecl<void(void*, std::uint64_t)> FUN_142526340;
ExeDecl<void(void*)> FUN_142519860;
ExeDecl<bool(const void*, const void*)> FUN_142510dc0;
ExeDecl<void(void*, const void*)> FUN_1424efe00;
ExeDecl<void(void*, const void*)> FUN_1424f1f70;
ExeDecl<bool(const void*)> FUN_142514f70;
ExeDecl<const char*(void*, void*)> FUN_142506e10;
ExeDecl<void(void*, std::uint32_t, void*, std::uint32_t, std::uint32_t)> FUN_142519d50;
ExeDecl<void(void*)> FUN_1424ddc20;
ExeDecl<void(void*, void*, const void*)> FUN_1424d6750;
namespace Scaleform { namespace GFx { class InteractiveObject; }}
ExeDecl<void(void*, Scaleform::GFx::InteractiveObject*)> FUN_1424d6480;   // the AVM interactive-object base constructor
ExeDecl<void(void*, void*, const void*)> FUN_1424dabd0;
ExeDecl<void(void*, void*)> FUN_1424d6ac0;
void FUN_140019470(void* self, std::uint64_t* output); // defined below (external: other units take its address)
void FUN_140019660(void* self, std::uint64_t* output);
ExeDecl<void*(void*, void*)> FUN_1400199e0;
ExeDecl<void*(void*, void*)> FUN_14001ad20;
ExeDecl<void(void*)> FUN_1425a4030;
ExeDecl<void()> FUN_14257e080;
ExeDecl<void(void*, void*)> FUN_1425cd370;
ExeDecl<int(void*, void*)> FUN_1428d8f14;
ExeDecl<int(void*, void*)> FUN_1428d8efc;
ExeDecl<void(void*)> FUN_1427443c0;
ExeDecl<std::uint64_t()> FUN_1425e3480;
ExeDecl<int(void*, bool*)> FUN_142303a6b;
ExeDecl<void(void*)> FUN_142745f50;
ExeDecl<int(void*, const char*, unsigned, void*, void**)> FUN_142303a29;
ExeDecl<int(void*, std::uint32_t*, unsigned)> FUN_142303a4d;
ExeDecl<void*(void*, void*)> FUN_142516600;
ExeDecl<void*(void*, void*)> FUN_14250d8f0;
ExeDecl<void(void*, void*, void*)> FUN_142442c30;
ExeDecl<void(void*, void*)> FUN_1424edca0;
ExeDecl<void(void*, void*, void*, void*)> FUN_142467b50;
ExeDecl<void(void*, void*, int)> FUN_1424687d0;
ExeDecl<void(void*, void*, const void*, void*, unsigned, void*, unsigned)> FUN_1424fef00;
ExeDecl<void(void*, void*, std::uint64_t)> FUN_1424d2150;
ExeDecl<void(void*)> FUN_140026ed0;
ExeDecl<void()> FUN_140026db0;
extern ExeDecl<void*> DAT_14317bf80;
#define AvmInteractiveVtable DAT_14317bf80
extern ExeDecl<void*> DAT_1431b7c70;
#define VideoTraitsVtable DAT_1431b7c70
extern ExeDecl<void*> DAT_1431b7f60;
#define VideoTraitsBaseVtable DAT_1431b7f60
extern ExeDecl<void*> DAT_1431b7ea0;
#define VideoTraitsSubVtableA DAT_1431b7ea0
extern ExeDecl<void*> DAT_1431b7de0;
#define VideoTraitsSubVtableB DAT_1431b7de0
extern ExeDecl<void*> DAT_1431b4c60; extern ExeDecl<void*> DAT_1431bec40;
#define VideoAudioVtableA DAT_1431b4c60
#define VideoAudioVtableB DAT_1431bec40
extern ExeDecl<void*> DAT_1431bed60; extern ExeDecl<void*> DAT_1431bedd8;
#define VideoAudioDeleteVtable DAT_1431bed60
#define VideoAudioSubVtable DAT_1431bedd8
extern ExeDecl<void*> DAT_1431bede8;
#define VideoAudioEventVtable DAT_1431bede8
extern ExeDecl<void*> DAT_1431bcbb0;
#define VideoSoundDeleteVtable DAT_1431bcbb0
extern ExeDecl<void*> DAT_1431bef00;
#define VideoSoundVtable DAT_1431bef00
extern ExeDecl<void*> DAT_1431bef38;
#define VideoSoundSubVtable DAT_1431bef38
extern ExeDecl<void*> DAT_1431bee78;
#define VideoAudioStreamVtable DAT_1431bee78
extern ExeDecl<void*> DAT_1431beef0;
#define VideoAudioStreamSubVtable DAT_1431beef0
extern ExeDecl<void*> DAT_1431b7160; extern ExeDecl<void*> DAT_1431b7900;
#define VideoClassInfoA DAT_1431b7160
#define VideoClassVtableA DAT_1431b7900
extern ExeDecl<void*> DAT_1431b71b0; extern ExeDecl<void*> DAT_1431b7260;
#define VideoInstanceVtableA DAT_1431b71b0
#define VideoCTraitsVtable DAT_1431b7260
extern ExeDecl<void*> DAT_1431b7b50; extern ExeDecl<void*> DAT_1431b7d50;
#define VideoClassInfoB DAT_1431b7b50
#define VideoClassVtableB DAT_1431b7d50
extern ExeDecl<void*> DAT_1431b7c70;
#define VideoInstanceVtableB DAT_1431b7c70
ExeDecl<void(void*)> FUN_1424df220;
ExeDecl<void*(void*)> FUN_1424eb610;
ExeDecl<void(void*, void*)> FUN_140010b80;
extern "C" void* DAT_143b15f60;

namespace {
using VideoGenericThunk = void(*)(void*, void*, void*);

void ReleaseVideoAtom(std::uint64_t* value)
{
    auto atom = *value;
    if (!atom) return;
    if (atom & 1) { *value = atom - 1; return; }
    auto* refs = reinterpret_cast<std::uint32_t*>(atom + 0x10);
    if ((*refs & 0x3fffff) != 0) { --*refs; ReleaseAS3GcObject(); }
}

void RetainVideoAtom(std::uint64_t atom)
{
    if (atom) {
        auto* refs = reinterpret_cast<std::uint32_t*>(atom + 0x10);
        *refs = (*refs + 1) & 0x8fbfffff;
    }
}

void EraseVideoAtomHashEntry(void* tablePtr, const std::uint64_t* key)
{
    auto* table = *reinterpret_cast<unsigned char**>(tablePtr);
    if (!table) return;
    std::uint64_t hash = 0x1505;
    auto* bytes = reinterpret_cast<const unsigned char*>(key);
    for (int i = 7; i >= 0; --i) hash = bytes[i] + hash * 0x1003f;
    auto bucket = hash & *reinterpret_cast<std::uint64_t*>(table + 8);
    auto* entry = reinterpret_cast<std::uint64_t*>(table + 0x10 + bucket * 0x20);
    if (entry[0] == ~std::uint64_t(1) || entry[1] != bucket) return;
    std::uint64_t previous = ~std::uint64_t(0), current = bucket;
    while (entry[1] != bucket || entry[2] != *key) {
        previous = current;
        current = entry[0];
        if (current == ~std::uint64_t(0)) return;
        entry = reinterpret_cast<std::uint64_t*>(table + 0x10 + current * 0x20);
    }
    auto next = entry[0];
    if (current == bucket && next != ~std::uint64_t(0)) {
        auto* following = reinterpret_cast<std::uint64_t*>(table + 0x10 + next * 0x20);
        entry[0] = ~std::uint64_t(1);
        entry[0] = following[0]; entry[1] = following[1]; entry[2] = following[2]; entry[3] = following[3];
        following[0] = ~std::uint64_t(1);
    } else {
        if (current != bucket) *reinterpret_cast<std::uint64_t*>(table + 0x10 + previous * 0x20) = next;
        entry[0] = ~std::uint64_t(1);
    }
    --*reinterpret_cast<std::uint64_t*>(table);
}

// MS2-FUNCTIONAL: forwards the normalized AS3 number argument through the first property thunk.
// @0x140016b50
void FUN_140016b50(void*, void* object, void* callFrame, void* member, int argc,
                   Scaleform::GFx::AS3::Value* args)
{
    auto* root = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callFrame) + 0x10);
    auto number = std::numeric_limits<double>::quiet_NaN();
    if (argc != 0) args->Convert2NumberInline(number);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(object) + 0x180) == 0) {
        reinterpret_cast<void(*)(void*, void*, double)>(VideoThunkA)(
            static_cast<unsigned char*>(VideoThunkBaseA) + reinterpret_cast<std::uintptr_t>(root),
            member, number);
    }
}

// MS2-FUNCTIONAL: forwards the normalized AS3 number argument through the second property thunk.
// @0x140016be0
void FUN_140016be0(void*, void* object, void* callFrame, void* member, int argc,
                   Scaleform::GFx::AS3::Value* args)
{
    auto* root = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callFrame) + 0x10);
    auto number = std::numeric_limits<double>::quiet_NaN();
    if (argc != 0) args->Convert2NumberInline(number);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(object) + 0x180) == 0) {
        reinterpret_cast<void(*)(void*, void*, double)>(VideoThunkB)(
            static_cast<unsigned char*>(VideoThunkBaseB) + reinterpret_cast<std::uintptr_t>(root),
            member, number);
    }
}

// MS2-FUNCTIONAL: dispatches one of the six recovered native getters selected by the trait index.
// @0x140016c70
void FUN_140016c70(void* object, void* result, unsigned kind)
{
    static const VideoGenericThunk calls[] = {&VideoNative0, &VideoNative1, &VideoNative2,
                                               &VideoNative3, &VideoNative4, nullptr};
    if (kind < 5) calls[kind](object, result, nullptr);
    else if (kind == 5) reinterpret_cast<VideoGenericThunk>(
        *reinterpret_cast<void**>(static_cast<unsigned char*>(result) + 0x40))(object, result, nullptr);
}

// MS2-FUNCTIONAL: invokes the native setter and then marks the trait value as assigned.
// @0x140016d10
void FUN_140016d10(void* object, void* value)
{
    reinterpret_cast<void(*)(void*, void*, void*)>(*reinterpret_cast<void**>(object))(
        object, value, reinterpret_cast<void*>(&VideoNative3));
    reinterpret_cast<void(*)(void*, int)>(*reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x20))(
        object, 1);
}

// MS2-FUNCTIONAL: constructs the recovered three-field AS3 value, retaining its managed payload.
// @0x140016e30
std::uint64_t* FUN_140016e30(std::uint64_t* out, std::uint64_t type, std::uint64_t flags,
                             int hasValue, std::uint32_t* sourceType, std::uint64_t* payload)
{
    out[0] = type; out[1] = flags; out[2] = *payload;
    auto* count = reinterpret_cast<std::uint32_t*>(out[2] + 0x18);
    ++*count;
    if (hasValue) {
        const auto tag = *sourceType & 0x1f;
        if (tag >= 0x0c && tag < 0x10 && *reinterpret_cast<std::uint64_t*>(sourceType + 4) == 0) {
            auto* node = reinterpret_cast<unsigned char*>(out[2]);
            auto shared = *reinterpret_cast<std::uint64_t*>(node + 8);
            ++*reinterpret_cast<std::uint32_t*>(shared + 0x80);
            auto* refs = reinterpret_cast<std::uint32_t*>(node + 0x18);
            if (--*refs == 0) reinterpret_cast<Scaleform::GFx::ASStringNode*>(node)->ReleaseNode();
            out[2] = shared + 0x68;
        } else {
            ConvertAS3ValueToString(sourceType, out + 2, out + 2);
        }
    }
    return out;
}

// MS2-FUNCTIONAL: normalizes the AS3 value tag and calls the trait setter for non-default values.
// @0x140016ed0
void FUN_140016ed0(std::uint64_t* value, void* object)
{
    auto& tag = *reinterpret_cast<std::uint32_t*>(value + 2);
    if ((tag & 0x70000000) != 0x10000000) {
        tag = (tag & 0x9fffffff) | 0x10000000;
        (&VideoNative1)(object, value, nullptr);
    }
}

// MS2-FUNCTIONAL: computes the executable's 8-byte key hash and searches its chained bucket.
// @0x140016f40
std::int64_t FUN_140016f40(void* tablePtr, const std::uint64_t* key)
{
    auto* table = *reinterpret_cast<unsigned char**>(tablePtr);
    if (!table) return -1;
    std::uint64_t hash = 0x1505;
    auto* bytes = reinterpret_cast<const unsigned char*>(key);
    for (int i = 7; i >= 0; --i) hash = bytes[i] + hash * 0x1003f;
    auto mask = *reinterpret_cast<std::uint64_t*>(table + 8);
    auto index = hash & mask;
    auto* entry = reinterpret_cast<std::uint64_t*>(table + 0x10 + index * 0x20);
    if (entry[0] == ~std::uint64_t(1) || entry[1] != index) return -1;
    for (auto link = index;;) {
        entry = reinterpret_cast<std::uint64_t*>(table + 0x10 + link * 0x20);
        if (entry[1] == index && entry[2] == *key) return static_cast<std::int64_t>(link);
        link = entry[0];
        if (link == ~std::uint64_t(0)) break;
    }
    return -1;
}

// MS2-FUNCTIONAL: forwards an AS3 value through the third property thunk unless its receiver is disabled.
// @0x140016fd0
void FUN_140016fd0(void*, void* object, void* callFrame, void* member, int argc,
                   const std::uint8_t* args)
{
    std::uint64_t value = 0;
    if (argc && (*args & 0x1f)) value = *reinterpret_cast<const std::uint64_t*>(args + 0x10);
    if (*reinterpret_cast<std::uint8_t*>(static_cast<std::uint8_t*>(object) + 0x180) == 0) {
        auto root = *reinterpret_cast<std::uint64_t*>(static_cast<std::uint8_t*>(callFrame) + 0x10);
        reinterpret_cast<void(*)(std::uint64_t, void*, std::uint64_t)>(VideoThunkC)(
            reinterpret_cast<std::uintptr_t>(VideoThunkBaseC) + root, member, value);
    }
}

// MS2-FUNCTIONAL: forwards the AS3 value through the fourth property thunk unless its receiver is disabled.
// @0x140017020
void FUN_140017020(void*, void* object, void* callFrame, void* member, int argc,
                   const std::uint8_t* args)
{
    std::uint64_t value = 0;
    if (argc && (*args & 0x1f)) value = *reinterpret_cast<const std::uint64_t*>(args + 0x10);
    if (*reinterpret_cast<std::uint8_t*>(static_cast<std::uint8_t*>(object) + 0x180) == 0) {
        auto root = *reinterpret_cast<std::uint64_t*>(static_cast<std::uint8_t*>(callFrame) + 0x10);
        reinterpret_cast<void(*)(std::uint64_t, void*, std::uint64_t)>(VideoThunkD)(
            reinterpret_cast<std::uintptr_t>(VideoThunkBaseD) + root, member, value);
    }
}

// MS2-FUNCTIONAL: forwards the AS3 value through the fifth property thunk unless its receiver is disabled.
// @0x140017070
void FUN_140017070(void*, void* object, void* callFrame, void* member, int argc,
                   const std::uint8_t* args)
{
    std::uint64_t value = 0;
    if (argc && (*args & 0x1f)) value = *reinterpret_cast<const std::uint64_t*>(args + 0x10);
    if (*reinterpret_cast<std::uint8_t*>(static_cast<std::uint8_t*>(object) + 0x180) == 0) {
        auto root = *reinterpret_cast<std::uint64_t*>(static_cast<std::uint8_t*>(callFrame) + 0x10);
        reinterpret_cast<void(*)(std::uint64_t, void*, std::uint64_t)>(VideoThunkE)(
            reinterpret_cast<std::uintptr_t>(VideoThunkBaseE) + root, member, value);
    }
}

// MS2-FUNCTIONAL: returns the chained hash-set bucket index for a matching 8-byte key.
// @0x140017440
void* FUN_140017440(void* table, const std::uint64_t* key)
{
    auto index = FUN_140016f40(table, key);
    return index < 0 ? nullptr : static_cast<unsigned char*>(table) + (index + 1) * 0x20;
}

// MS2-FUNCTIONAL: normalizes a value argument and dispatches the recovered setter with its optional integer.
// @0x140017470
void FUN_140017470(void*, void* object, void* callFrame, void* member, unsigned argc,
                   const std::uint8_t* args)
{
    std::uint64_t value = 0;
    if (argc && (*args & 0x1f)) value = *reinterpret_cast<const std::uint64_t*>(args + 0x10);
    int extra = -1;
    if (*reinterpret_cast<std::uint8_t*>(static_cast<std::uint8_t*>(object) + 0x180) == 0) {
        if (argc > 1) ConvertAS3ValueToInt32(const_cast<std::uint8_t*>(args + 0x20), &extra, &extra, -1, object);
        if (*reinterpret_cast<std::uint8_t*>(static_cast<std::uint8_t*>(object) + 0x180) == 0) {
            auto root = *reinterpret_cast<std::uint64_t*>(static_cast<std::uint8_t*>(callFrame) + 0x10);
            reinterpret_cast<void(*)(std::uint64_t, void*, std::uint64_t, int)>(VideoThunkF)(
                reinterpret_cast<std::uintptr_t>(VideoThunkBaseF) + root, member, value, extra);
        }
    }
}

// MS2-FUNCTIONAL: drops the recorded atom-table payload and removes its key from the receiver cache.
// @0x140017880
void FUN_140017880(void* receiver, std::uint64_t* atom)
{
    if ((*reinterpret_cast<std::uint32_t*>(atom + 2) & 0x04000000) == 0) return;
    *reinterpret_cast<std::uint32_t*>(atom + 2) &= 0xfbffffff;
    auto* table = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(receiver) + 0x70);
    if (!table) return;
    const std::uint64_t key = reinterpret_cast<std::uintptr_t>(atom);
    auto index = FUN_140016f40(&table, &key);
    if (index < 0) return;
    auto* entry = reinterpret_cast<unsigned char*>(table) + (index + 1) * 0x20;
    auto* value = *reinterpret_cast<std::uint32_t**>(entry + 8);
    if (!value) return;
    value[2] = value[3] = 0;
    --value[0];
    if (value[0] == 0) { auto fn = *reinterpret_cast<VideoGenericThunk*>(*reinterpret_cast<unsigned char***>(value) + 0x60); fn(value, nullptr, nullptr); }
    EraseVideoAtomHashEntry(&table, &key);
}

// MS2-FUNCTIONAL: decrements a live AS3 object reference and invokes the runtime release hook.
// @0x140017990
void FUN_140017990(void* object)
{
    auto* refs = reinterpret_cast<std::uint32_t*>(static_cast<unsigned char*>(object) + 0x10);
    if ((*refs & 0x3fffff) != 0) { --*refs; ReleaseAS3GcObject(); }
}

// MS2-FUNCTIONAL: releases the stored AS3 atom, including inline tagged integers.
// @0x1400179b0
void FUN_1400179b0(std::uint64_t* value) { ReleaseVideoAtom(value); }
// MS2-FUNCTIONAL: releases the stored AS3 atom, including inline tagged integers.
// @0x1400179f0
void FUN_1400179f0(std::uint64_t* value) { ReleaseVideoAtom(value); }
// MS2-FUNCTIONAL: releases the stored AS3 atom, including inline tagged integers.
// @0x140017a30
void FUN_140017a30(std::uint64_t* value) { ReleaseVideoAtom(value); }
// MS2-FUNCTIONAL: releases the stored AS3 atom, including inline tagged integers.
// @0x140017a70
void FUN_140017a70(std::uint64_t* value) { ReleaseVideoAtom(value); }
// MS2-FUNCTIONAL: releases the stored AS3 atom, including inline tagged integers.
// @0x140017ab0
void FUN_140017ab0(std::uint64_t* value) { ReleaseVideoAtom(value); }
// MS2-FUNCTIONAL: releases the stored AS3 atom, including inline tagged integers.
// @0x140017af0
void FUN_140017af0(std::uint64_t* value) { ReleaseVideoAtom(value); }
// MS2-FUNCTIONAL: releases the stored AS3 atom, including inline tagged integers.
// @0x140017b30
void FUN_140017b30(std::uint64_t* value) { ReleaseVideoAtom(value); }
// MS2-FUNCTIONAL: releases the stored AS3 atom, including inline tagged integers.
// @0x140017b70
void FUN_140017b70(std::uint64_t* value) { ReleaseVideoAtom(value); }
// MS2-FUNCTIONAL: releases the stored AS3 atom, including inline tagged integers.
// @0x140017bb0
void FUN_140017bb0(std::uint64_t* value) { ReleaseVideoAtom(value); }
// MS2-FUNCTIONAL: releases the stored AS3 atom, including inline tagged integers.
// @0x140017bf0
void FUN_140017bf0(std::uint64_t* value) { ReleaseVideoAtom(value); }
// MS2-FUNCTIONAL: releases the stored AS3 atom, including inline tagged integers.
// @0x140017c30
void FUN_140017c30(std::uint64_t* value) { ReleaseVideoAtom(value); }

// MS2-FUNCTIONAL: replaces an AS3 atom without taking a reference to the replacement.
// @0x140017c70
std::uint64_t* FUN_140017c70(std::uint64_t* destination, std::uint64_t replacement)
{
    if (*destination != replacement) { ReleaseVideoAtom(destination); *destination = replacement; }
    return destination;
}

// MS2-FUNCTIONAL: replaces an AS3 atom and retains an object-valued replacement.
// @0x140017cd0
std::uint64_t* FUN_140017cd0(std::uint64_t* destination, std::uint64_t replacement)
{
    if (*destination != replacement) { ReleaseVideoAtom(destination); RetainVideoAtom(replacement); *destination = replacement; }
    return destination;
}

// MS2-FUNCTIONAL: copy-assigns an AS3 atom with a retain of its managed object payload.
// @0x140017d40
std::uint64_t* FUN_140017d40(std::uint64_t* destination, const std::uint64_t* source)
{
    if (destination != source) { ReleaseVideoAtom(destination); RetainVideoAtom(*source); *destination = *source; }
    return destination;
}
// MS2-FUNCTIONAL: copy-assigns an AS3 atom with a retain of its managed object payload.
// @0x140017db0
std::uint64_t* FUN_140017db0(std::uint64_t* destination, const std::uint64_t* source)
{
    if (destination != source) { ReleaseVideoAtom(destination); RetainVideoAtom(*source); *destination = *source; }
    return destination;
}

// MS2-FUNCTIONAL: assigns the AS3 object's unsafe Value view and then releases its retained atom.
// @0x140017e40
void* FUN_140017e40(void* result, Scaleform::GFx::AS3::Value* value, std::uint64_t* atom)
{
    value->AssignUnsafe(reinterpret_cast<Scaleform::GFx::AS3::Object*>(*atom));
    ReleaseVideoAtom(atom);
    return result;
}
// MS2-FUNCTIONAL: assigns the AS3 object's unsafe Value view and then releases its retained atom.
// @0x140017eb0
void* FUN_140017eb0(void* result, Scaleform::GFx::AS3::Value* value, std::uint64_t* atom)
{
    value->AssignUnsafe(reinterpret_cast<Scaleform::GFx::AS3::Object*>(*atom));
    ReleaseVideoAtom(atom);
    return result;
}

// MS2-FUNCTIONAL: assigns an atom after releasing the previous managed value.
// @0x1400190c0
std::uint64_t* FUN_1400190c0(std::uint64_t* destination, std::uint64_t replacement)
{
    if (*destination != replacement) { ReleaseVideoAtom(destination); *destination = replacement; }
    return destination;
}
// MS2-FUNCTIONAL: copy-assigns an atom while retaining its managed object.
// @0x140019120
std::uint64_t* FUN_140019120(std::uint64_t* destination, const std::uint64_t* source)
{
    if (destination != source) { ReleaseVideoAtom(destination); RetainVideoAtom(*source); *destination = *source; }
    return destination;
}
// MS2-FUNCTIONAL: assigns an object atom to an unsafe AS3 Value and releases the temporary reference.
// @0x1400191d0
void FUN_1400191d0(Scaleform::GFx::AS3::Value* destination, const std::uint64_t* source)
{
    auto object = reinterpret_cast<Scaleform::GFx::AS3::Object*>(*source);
    RetainVideoAtom(*source);
    destination->AssignUnsafe(object);
    auto temp = *source;
    ReleaseVideoAtom(&temp);
}
// MS2-FUNCTIONAL: assigns an object atom to an unsafe AS3 Value and releases the temporary reference.
// @0x140019220
void FUN_140019220(Scaleform::GFx::AS3::Value* destination, const std::uint64_t* source)
{
    FUN_1400191d0(destination, source);
}
// MS2-FUNCTIONAL: replaces the retained object atom at byte offset 0x80.
// @0x140019270
void FUN_140019270(void* object, std::uint64_t replacement)
{
    FUN_1400190c0(reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(object) + 0x80), replacement);
}

// MS2-FUNCTIONAL: transfers an object into an AS3 Value using Pick semantics.
// @0x14001a1e0
void FUN_14001a1e0(Scaleform::GFx::AS3::Value* value, Scaleform::GFx::AS3::Object* object)
{
    value->Pick(object);
}
// MS2-FUNCTIONAL: initializes an AS3 numeric Value with a 32-bit integer payload.
// @0x14001a260
void FUN_14001a260(std::uint32_t* value, std::uint32_t number)
{
    value[0] = (value[0] & 0xffffffe2) | 2;
    *reinterpret_cast<std::uint64_t*>(value + 4) = number;
    *reinterpret_cast<std::uint64_t*>(value + 6) = 0;
}
// MS2-FUNCTIONAL: copies a 32-bit integer payload into an AS3 numeric Value.
// @0x14001a2b0
void* FUN_14001a2b0(void* result, std::uint32_t* value, const std::uint32_t* number)
{
    FUN_14001a260(value, *number);
    return result;
}
} // namespace (sfr36: the natives below have external linkage, other units take their addresses)
// MS2-FUNCTIONAL: reads the current frame record's integer field at offset 0x10.
// @0x14001a330
void FUN_14001a330(void* self, std::uint32_t* result)
{
    auto* frames = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x58);
    auto index = frames[0x6d];
    auto* slot = frames + index * 4;
    auto* instance = *reinterpret_cast<unsigned char**>(slot);
    auto getter = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char***>(instance) + 0xc);
    auto data = reinterpret_cast<void*(*)(void*)>(getter)(slot);
    *result = *reinterpret_cast<std::uint32_t*>(static_cast<unsigned char*>(data) + 0x10);
}
// MS2-FUNCTIONAL: writes the current frame record's integer field at offset 0x10.
// @0x14001a360
void FUN_14001a360(void* self, void*, std::uint32_t number)
{
    auto* frames = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x58);
    auto index = frames[0x6d];
    auto* slot = frames + index * 4;
    auto* instance = *reinterpret_cast<unsigned char**>(slot);
    auto getter = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char***>(instance) + 0xc);
    auto data = reinterpret_cast<void*(*)(void*)>(getter)(slot);
    *reinterpret_cast<std::uint32_t*>(static_cast<unsigned char*>(data) + 0x10) = number;
}
// MS2-FUNCTIONAL: reads the current frame record's flag byte at offset 0x14.
// @0x14001a390
void FUN_14001a390(void* self, std::uint8_t* result)
{
    auto* frames = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x58);
    auto index = frames[0x6d];
    auto* slot = frames + index * 4;
    auto* instance = *reinterpret_cast<unsigned char**>(slot);
    auto getter = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char***>(instance) + 0xc);
    auto data = reinterpret_cast<void*(*)(void*)>(getter)(slot);
    *result = *(static_cast<unsigned char*>(data) + 0x14);
}
// MS2-FUNCTIONAL: writes the current frame record's flag byte at offset 0x14.
// @0x14001a3c0
void FUN_14001a3c0(void* self, void*, std::uint8_t flag)
{
    auto* frames = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x58);
    auto index = frames[0x6d];
    auto* slot = frames + index * 4;
    auto* instance = *reinterpret_cast<unsigned char**>(slot);
    auto getter = *reinterpret_cast<void**>(*reinterpret_cast<unsigned char***>(instance) + 0xc);
    auto data = reinterpret_cast<void*(*)(void*)>(getter)(slot);
    *(static_cast<unsigned char*>(data) + 0x14) = flag;
}
// The Video display object's leaf slots; external, the vtable copies of data_rdata_sf_video take their addresses.
// @0x14001b000
__declspec(noinline) std::uint64_t FUN_14001b000(void*) { return 0; }
// @0x14001b010
__declspec(noinline) std::uint64_t FUN_14001b010(void*) { return 0; }
// @0x14001b020
__declspec(noinline) std::uint64_t FUN_14001b020(void*) { return 0; }
// @0x14001b030
__declspec(noinline) std::uint64_t FUN_14001b030(void*) { return 0; }
// @0x14001b070
__declspec(noinline) std::uint8_t FUN_14001b070(void*) { return 1; }
// AvmInteractiveObj::HasEventHandler
// @0x14001b080
__declspec(noinline) bool thunk_FUN_142510dc0(const void* object, const void* id) { return FUN_142510dc0(object, id); }
// @0x14001b090
__declspec(noinline) std::uint8_t FUN_14001b090(void*) { return 1; }
// @0x14001b0b0
__declspec(noinline) std::uint64_t FUN_14001b0b0(void*) { return 0; }
// AvmInteractiveObj::CloneInternalData
// @0x14001b0c0
__declspec(noinline) void thunk_FUN_1424efe00(void* object, const void* source) { FUN_1424efe00(object, source); }
// AvmInteractiveObj::CopyPhysicalProperties
// @0x14001b0d0
__declspec(noinline) void thunk_FUN_1424f1f70(void* object, const void* source) { FUN_1424f1f70(object, source); }
// 0x1431b7ea0 [18..22]
// @0x14001b100
__declspec(noinline) void FUN_14001b100(void*) {}
// @0x14001b110
__declspec(noinline) bool FUN_14001b110(void*) { return false; }
// @0x14001b120
__declspec(noinline) bool FUN_14001b120(void*) { return true; }
// @0x14001b130
__declspec(noinline) bool FUN_14001b130(void*) { return true; }
// AvmInteractiveObj::IsTabable
// @0x14001b140
__declspec(noinline) bool FUN_14001b140(const void* object) { return FUN_142514f70(object); }
// The traits' debug class names (slot 2 of each traits vtable; 0x1431b7f60 [16] for the display object).
// @0x140019af0
const char* FUN_140019af0(const void*) { return "ClassTraits::NetStream"; }
// @0x14001a040
const char* FUN_14001a040(const void*) { return "Instances::fl_media::Video"; }
// @0x14001a0b0
const char* FUN_14001a0b0(const void*) { return "InstanceTraits::Video"; }
// @0x14001ae30
const char* FUN_14001ae30(const void*) { return "ClassTraits::Video"; }
// @0x14001aff0
const char* FUN_14001aff0(const void*) { return "flash.media.Video"; }

// MS2-FUNCTIONAL: releases the retained atom field and runs the inherited AS3 cleanup.
// @0x140019060
void FUN_140019060(void* object)
{
    ReleaseVideoAtom(reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(object) + 0xc0));
    FUN_1424df220(object);
}
// MS2-FUNCTIONAL: releases the retained atom field and runs the inherited AS3 cleanup.
// @0x140019b00
void FUN_140019b00(void* object)
{
    FUN_140019060(object);
}
// MS2-FUNCTIONAL: releases the retained atom field and optionally frees the object through the Scaleform heap.
// @0x140019b60
void* FUN_140019b60(void* object, std::uint64_t flags)
{
    ReleaseVideoAtom(reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(object) + 0xc0));
    FUN_1424df220(object);
    if (flags & 1) {
        auto** heap = *reinterpret_cast<void***>(DAT_143b15f60);
        reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, object);
    }
    return object;
}

// MS2-FUNCTIONAL: invokes the stored object's callback with this closure as context.
// @0x14001b3f0
void FUN_14001b3f0(std::uint64_t* closure)
{
    auto* object = reinterpret_cast<std::uint64_t*>(closure[0]);
    if (object) reinterpret_cast<void(*)(void*, std::uint64_t)>(*reinterpret_cast<void**>(*reinterpret_cast<void***>(object) + 2))(object, closure[1]);
}
// MS2-FUNCTIONAL: invokes the stored object's release slot.
// @0x14001b880
void FUN_14001b880(std::uint64_t* holder)
{
    auto* object = reinterpret_cast<void*>(holder[0]);
    if (object) { auto** vtable = *reinterpret_cast<void***>(object); reinterpret_cast<void(*)(void*)>(vtable[8])(object); }
}
// MS2-FUNCTIONAL: retains the replacement heap, releases the previous heap, then stores it.
// @0x14001b8a0
std::uint64_t* FUN_14001b8a0(std::uint64_t* holder, void* replacement)
{
    if (replacement) { auto** vtable = *reinterpret_cast<void***>(replacement); reinterpret_cast<void(*)(void*)>(vtable[7])(replacement); }
    FUN_14001b880(holder);
    *holder = reinterpret_cast<std::uintptr_t>(replacement);
    return holder;
}
// MS2-FUNCTIONAL: releases the previous heap and stores the supplied pointer without retaining it.
// @0x14001b8e0
std::uint64_t* FUN_14001b8e0(std::uint64_t* holder, std::uint64_t replacement)
{
    if (*holder) { FUN_14001b880(holder); *holder = replacement; }
    else *holder = replacement;
    return holder;
}

// MS2-FUNCTIONAL: converts a callback object to an unsafe Value when the VM has no pending exception, then drops the callback atom.
// @0x140019c30
void FUN_140019c30(std::uint64_t* closure)
{
    auto* vm = reinterpret_cast<unsigned char*>(closure[0]);
    auto atom = closure[2];
    if (vm[0x180] == 0) {
        RetainVideoAtom(atom);
        reinterpret_cast<Scaleform::GFx::AS3::Value*>(closure[1])->AssignUnsafe(reinterpret_cast<Scaleform::GFx::AS3::Object*>(atom));
        ReleaseVideoAtom(&atom);
    }
    ReleaseVideoAtom(closure + 2);
}
// MS2-FUNCTIONAL: converts a callback object to an unsafe Value when the VM has no pending exception, then drops the callback atom.
// @0x140019cd0
void FUN_140019cd0(std::uint64_t* closure)
{
    FUN_140019c30(closure);
}

namespace {
void ConvertVideoCallback(void* vm, std::uint64_t callback, std::uint64_t context, Scaleform::GFx::AS3::Value* output)
{
    void* object = nullptr;
    auto thunk = reinterpret_cast<void(*)(std::uint64_t, void**)>(callback);
    thunk(reinterpret_cast<std::uintptr_t>(reinterpret_cast<void*>(context)), reinterpret_cast<void**>(&object));
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0) {
        RetainVideoAtom(reinterpret_cast<std::uintptr_t>(object));
        output->AssignUnsafe(reinterpret_cast<Scaleform::GFx::AS3::Object*>(object));
        auto temporary = reinterpret_cast<std::uintptr_t>(object);
        ReleaseVideoAtom(&temporary);
    }
    auto temporary = reinterpret_cast<std::uintptr_t>(object);
    ReleaseVideoAtom(&temporary);
}
} // namespace
// MS2-FUNCTIONAL: invokes the metadata callback and converts its object result to an AS3 Value.
// @0x140019d70
void FUN_140019d70(void*, void* vm, void* context, Scaleform::GFx::AS3::Value* output)
{
    ConvertVideoCallback(vm, reinterpret_cast<std::uintptr_t>(VideoCallbackA), reinterpret_cast<std::uintptr_t>(VideoCallbackBaseA) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(context) + 0x10), output);
}
// MS2-FUNCTIONAL: invokes the cue point callback and converts its object result to an AS3 Value.
// @0x140019e20
void FUN_140019e20(void*, void* vm, void* context, Scaleform::GFx::AS3::Value* output)
{
    ConvertVideoCallback(vm, reinterpret_cast<std::uintptr_t>(VideoCallbackB), reinterpret_cast<std::uintptr_t>(VideoCallbackBaseB) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(context) + 0x10), output);
}
// MS2-FUNCTIONAL: invokes the subtitle callback and converts its object result to an AS3 Value.
// @0x140019ed0
void FUN_140019ed0(void*, void* vm, void* context, Scaleform::GFx::AS3::Value* output)
{
    ConvertVideoCallback(vm, reinterpret_cast<std::uintptr_t>(VideoCallbackC), reinterpret_cast<std::uintptr_t>(VideoCallbackBaseC) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(context) + 0x10), output);
}

// MS2-FUNCTIONAL: copies a 32-bit integer into the numeric payload of an AS3 Value.
// @0x14001a6f0
void FUN_14001a6f0(std::uint32_t* value, const std::uint32_t* number)
{
    FUN_14001a260(value, *number);
}
// MS2-FUNCTIONAL: writes the callback's integer result to its output Value unless the VM has an exception.
// @0x14001a8e0
void FUN_14001a8e0(std::uint64_t* closure)
{
    if (*reinterpret_cast<unsigned char*>(closure[0] + 0x180) == 0)
        FUN_14001a260(reinterpret_cast<std::uint32_t*>(closure[1]), static_cast<std::uint32_t>(closure[2]));
}

// MS2-FUNCTIONAL: constructs a Video AS3 DisplayObject with the executable's default dimensions and vtable.
// @0x14001a000
Scaleform::GFx::AS3::Instances::fl_display::DisplayObject* FUN_14001a000(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject* object, Scaleform::GFx::AS3::InstanceTraits::Traits* traits)
{
    using DisplayObject = Scaleform::GFx::AS3::Instances::fl_display::DisplayObject;
    new (object) Scaleform::GFx::AS3::Instances::fl_display::DisplayObject(*traits);
    *reinterpret_cast<double*>(reinterpret_cast<unsigned char*>(object) + 0x68) = 320.0;
    *reinterpret_cast<double*>(reinterpret_cast<unsigned char*>(object) + 0x70) = 240.0;
    *reinterpret_cast<void***>(object) = &VideoDisplayVtable;
    return object;
}
// MS2-FUNCTIONAL: allocates and constructs the Video AS3 DisplayObject into the caller's result slot.
// @0x14001a600
void* FUN_14001a600(void*, void** result, Scaleform::GFx::AS3::InstanceTraits::Traits* traits)
{
    auto* object = static_cast<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject*>(FUN_1424eb610(traits));
    *result = object ? FUN_14001a000(object, traits) : nullptr;
    return result;
}
// MS2-FUNCTIONAL: allocates and constructs a Video AS3 DisplayObject, then transfers it into a Value.
// @0x14001a860
void FUN_14001a860(void*, Scaleform::GFx::AS3::Value* value, Scaleform::GFx::AS3::InstanceTraits::Traits* traits)
{
    auto* object = static_cast<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject*>(FUN_1424eb610(traits));
    if (object) FUN_14001a000(object, traits);
    value->Pick(reinterpret_cast<Scaleform::GFx::AS3::Object*>(object));
}

namespace Scaleform { namespace GFx { namespace Video { class VideoCharacter; }}}
// MS2-FUNCTIONAL: Video.videoHeight getter (the display height kept as a double at +0x70).
// @0x14001a060
void FUN_14001a060(void* self, int* result) { *result = (int)*(double*)((Scaleform::UByte*)self + 0x70); }
// MS2-FUNCTIONAL: Video.videoWidth getter (the display width kept as a double at +0x68).
// @0x14001a070
void FUN_14001a070(void* self, int* result) { *result = (int)*(double*)((Scaleform::UByte*)self + 0x68); }
// MS2-FUNCTIONAL: Video.attachCamera (unsupported).
// @0x14001a3f0
void FUN_14001a3f0(Scaleform::GFx::AS3::Object* self)
{
    self->GetVM().GetUI().Output(Scaleform::GFx::AS3::FlashUI::Output_Warning,
                                 "The method Video::attachCamera() is not implemented\n");
}
// MS2-FUNCTIONAL: Video.clear: releases the character's current image (sfr_video_02).
// @0x14001a460
void FUN_14001a460(void* self)
{
    extern void FUN_140010a30(Scaleform::GFx::Video::VideoCharacter*);
    FUN_140010a30(*(Scaleform::GFx::Video::VideoCharacter**)((Scaleform::UByte*)self + 0x58));
}
// MS2-FUNCTIONAL: attaches the supplied AS3 NetStream's VideoPlayer to this Video's display object and adds its reference.
// @0x14001a410
void FUN_14001a410(void* self, void*, void* netStream)
{
    auto* player = netStream ? *reinterpret_cast<void**>(static_cast<unsigned char*>(netStream) + 0x50) : nullptr;
    auto* display = *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x58);
    if (display) {
        FUN_140010b80(display, player);
        if (player) { auto** vtable = *reinterpret_cast<void***>(player); reinterpret_cast<void(*)(void*, void*)>(vtable[7])(player, display); }
    }
}
// (sfr33) external: the Video traits / display vtable copies of data_rdata_sf_video take these addresses.

// MS2-FUNCTIONAL: destroys AS3 CTraits and conditionally frees the allocation through the Scaleform heap.
// @0x14001a5c0
Scaleform::GFx::AS3::InstanceTraits::CTraits* FUN_14001a5c0(Scaleform::GFx::AS3::InstanceTraits::CTraits* traits, std::uint32_t flags)
{
    traits->~CTraits();
    if (flags & 1) {
        auto** heap = *reinterpret_cast<void***>(DAT_143b15f60);
        reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, traits);
    }
    return traits;
}
// MS2-FUNCTIONAL: transfers an object into an AS3 Value using the Pick operation.
// @0x14001a690
Scaleform::GFx::AS3::Value* FUN_14001a690(Scaleform::GFx::AS3::Value* value, Scaleform::GFx::AS3::Object* object)
{
    value->Pick(object);
    return value;
}
// MS2-FUNCTIONAL: converts coordinate arguments and stores the Video rectangle in twips.
// @0x14001a760
void FUN_14001a760(void* self, unsigned count, Scaleform::GFx::AS3::Value* args)
{
    if (count > 1) {
        double ignored = 0;
        args[0].Convert2NumberInline(ignored);
        args[1].Convert2NumberInline(ignored);
        auto* player = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x58);
        *reinterpret_cast<std::uint32_t*>(player + 0xe0) = 0;
        *reinterpret_cast<std::uint32_t*>(player + 0xe4) = 0;
        *reinterpret_cast<float*>(player + 0xe8) = static_cast<float>(*reinterpret_cast<double*>(static_cast<unsigned char*>(self) + 0x68)) * VideoTwipsScale;
        *reinterpret_cast<float*>(player + 0xec) = static_cast<float>(*reinterpret_cast<double*>(static_cast<unsigned char*>(self) + 0x70)) * VideoTwipsScale;
    }
}
// MS2-FUNCTIONAL: updates the player rectangle from the stored Video dimensions when resize is enabled.
// @0x14001a800
void FUN_14001a800(std::uint64_t* object, std::uint8_t update)
{
    if (!update) {
        auto** vtable = *reinterpret_cast<void***>(object);
        reinterpret_cast<void(*)(void*)>(vtable[21])(object);
        auto* player = reinterpret_cast<unsigned char*>(object[11]);
        *reinterpret_cast<std::uint32_t*>(player + 0xe0) = 0;
        *reinterpret_cast<std::uint32_t*>(player + 0xe4) = 0;
        *reinterpret_cast<float*>(player + 0xe8) = static_cast<float>(object[13]) * VideoTwipsScale;
        *reinterpret_cast<float*>(player + 0xec) = static_cast<float>(object[14]) * VideoTwipsScale;
    }
}


// MS2-FUNCTIONAL: destroys the AS3 DisplayObject subobject and conditionally frees the allocation.
// @0x14001a2f0
void* FUN_14001a2f0(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject* object, std::uint64_t flags)
{
    object->~DisplayObject();
    if (flags & 1) {
        auto** heap = *reinterpret_cast<void***>(DAT_143b15f60);
        reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, object);
    }
    return object;
}

// MS2-FUNCTIONAL: fetches the video width integer and writes it to the callback Value.
// @0x14001a9b0
void FUN_14001a9b0(void*, void* vm, void* context, std::uint32_t* output)
{
    std::uint32_t number = 0;
    reinterpret_cast<void(*)(std::uintptr_t, std::uint32_t*)>(VideoPropGetA)(reinterpret_cast<std::uintptr_t>(VideoPropBaseA) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(context) + 0x10), &number);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0) FUN_14001a260(output, number);
}
// MS2-FUNCTIONAL: converts the input to an integer and writes it through the video property setter thunk.
// @0x14001aa20
void FUN_14001aa20(void*, void* vm, void* context, std::uint64_t value, int count, void* input)
{
    int converted = 0; std::uint32_t number = 0;
    if (count) ConvertAS3ValueToInt32(input, &converted, reinterpret_cast<int*>(&number), static_cast<int>(value), vm);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0)
        reinterpret_cast<void(*)(std::uintptr_t, std::uint64_t, std::uint32_t)>(VideoPropSetA)(reinterpret_cast<std::uintptr_t>(VideoPropBaseSetA) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(context) + 0x10), value, number);
}
// MS2-FUNCTIONAL: fetches the video playback boolean and writes it to the callback Value.
// @0x14001aa90
void FUN_14001aa90(void*, void* vm, void* context, std::uint32_t* output)
{
    std::uint8_t value = 0;
    reinterpret_cast<void(*)(std::uintptr_t, std::uint8_t*)>(VideoPropGetB)(reinterpret_cast<std::uintptr_t>(VideoPropBaseB) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(context) + 0x10), &value);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0) {
        *output = (*output & 0xffffffe1) | 1;
        *reinterpret_cast<std::uint64_t*>(output + 4) = value;
        *reinterpret_cast<std::uint64_t*>(output + 6) = 0;
    }
}
// MS2-FUNCTIONAL: converts the input to a boolean and writes it through the video property setter thunk.
// @0x14001ab00
void FUN_14001ab00(void*, void* vm, void* context, std::uint64_t value, int count, void* input)
{
    auto converted = count ? ConvertAS3ValueToBool(input) : 0;
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0)
        reinterpret_cast<void(*)(std::uintptr_t, std::uint64_t, std::uint8_t)>(VideoPropSetB)(reinterpret_cast<std::uintptr_t>(VideoPropBaseSetB) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(context) + 0x10), value, converted);
}
// MS2-FUNCTIONAL: fetches the video volume integer and writes it to the callback Value.
// @0x14001ab60
void FUN_14001ab60(void*, void* vm, void* context, std::uint32_t* output)
{
    std::uint32_t number = 0;
    reinterpret_cast<void(*)(std::uintptr_t, std::uint32_t*)>(VideoPropGetC)(reinterpret_cast<std::uintptr_t>(VideoPropBaseC) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(context) + 0x10), &number);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0) FUN_14001a260(output, number);
}
// MS2-FUNCTIONAL: fetches the video pan integer and writes it to the callback Value.
// @0x14001abd0
void FUN_14001abd0(void*, void* vm, void* context, std::uint32_t* output)
{
    std::uint32_t number = 0;
    reinterpret_cast<void(*)(std::uintptr_t, std::uint32_t*)>(VideoPropGetD)(reinterpret_cast<std::uintptr_t>(VideoPropBaseD) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(context) + 0x10), &number);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0) FUN_14001a260(output, number);
}

// MS2-FUNCTIONAL: forwards an object atom to the corresponding video property setter.
// @0x14001ac80
void FUN_14001ac80(void*, void* vm, void* context, std::uint64_t property, int count, const std::uint8_t* args)
{
    std::uint64_t atom = (count && ((*args & 0x1f) != 0)) ? *reinterpret_cast<const std::uint64_t*>(args + 0x10) : 0;
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0)
        reinterpret_cast<void(*)(std::uintptr_t, std::uint64_t, std::uint64_t)>(VideoPropSetC)(reinterpret_cast<std::uintptr_t>(VideoPropBaseSetC) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(context) + 0x10), property, atom);
}
// MS2-FUNCTIONAL: forwards an object atom to the second corresponding video property setter.
// @0x14001acd0
void FUN_14001acd0(void*, void* vm, void* context, std::uint64_t property, int count, const std::uint8_t* args)
{
    std::uint64_t atom = (count && ((*args & 0x1f) != 0)) ? *reinterpret_cast<const std::uint64_t*>(args + 0x10) : 0;
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0)
        reinterpret_cast<void(*)(std::uintptr_t, std::uint64_t, std::uint64_t)>(VideoPropSetD)(reinterpret_cast<std::uintptr_t>(VideoPropBaseSetD) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(context) + 0x10), property, atom);
}
// MS2-FUNCTIONAL: releases the retained atom field and invokes the AS3 cleanup hook.
// @0x14001ae40
void FUN_14001ae40(void* object)
{
    FUN_140019060(object);
}
// MS2-FUNCTIONAL: releases the retained atom field, invokes AS3 cleanup, and conditionally frees the object.
// @0x14001aea0
void* FUN_14001aea0(void* object, std::uint64_t flags)
{
    return FUN_140019b60(object, flags);
}
// @0x14001afd0
__declspec(noinline) void* FUN_14001afd0(void* object) { return object ? static_cast<unsigned char*>(object) + 0x40 : nullptr; }
// @0x14001afe0
__declspec(noinline) void* FUN_14001afe0(void* object) { return object ? static_cast<unsigned char*>(object) + 0x30 : nullptr; }

// MS2-FUNCTIONAL: releases the retained pointer stored in the holder.
// @0x14001b980
void FUN_14001b980(void** holder) { if (*holder) FUN_14257dcd0(*holder); }
// MS2-FUNCTIONAL: retains the replacement, releases the previous pointer, then stores it.
// @0x14001b9a0
std::uint64_t* FUN_14001b9a0(std::uint64_t* holder, void* replacement)
{
    if (replacement) ++*reinterpret_cast<std::uint32_t*>(static_cast<unsigned char*>(replacement) + 8);
    if (*holder) FUN_14257dcd0(reinterpret_cast<void*>(*holder));
    *holder = reinterpret_cast<std::uintptr_t>(replacement); return holder;
}
// MS2-FUNCTIONAL: releases the previous pointer and stores the replacement without retaining it.
// @0x14001b9f0
std::uint64_t* FUN_14001b9f0(std::uint64_t* holder, std::uint64_t replacement)
{
    if (*holder) FUN_14257dcd0(reinterpret_cast<void*>(*holder)); *holder = replacement; return holder;
}
// MS2-FUNCTIONAL: releases the retained pointer stored in the holder.
// @0x14001ba50
void FUN_14001ba50(void** holder) { if (*holder) FUN_14257dcd0(*holder); }
// MS2-FUNCTIONAL: retains the replacement, releases the previous pointer, then stores it.
// @0x14001ba70
std::uint64_t* FUN_14001ba70(std::uint64_t* holder, void* replacement)
{
    if (replacement) ++*reinterpret_cast<std::uint32_t*>(static_cast<unsigned char*>(replacement) + 8);
    if (*holder) FUN_14257dcd0(reinterpret_cast<void*>(*holder));
    *holder = reinterpret_cast<std::uintptr_t>(replacement); return holder;
}
// MS2-FUNCTIONAL: retains the new shared stream and releases the old stream.
// @0x14001bba0
std::uint64_t* FUN_14001bba0(std::uint64_t* holder, void* replacement)
{
    if (replacement) FUN_14257dc30(replacement);
    if (*holder) FUN_14257dcb0(reinterpret_cast<void*>(*holder));
    *holder = reinterpret_cast<std::uintptr_t>(replacement); return holder;
}
// MS2-FUNCTIONAL: retains and stores a non-null shared stream, or clears the holder.
// @0x14001bc00
std::uint64_t* FUN_14001bc00(std::uint64_t* holder, void* replacement)
{
    if (replacement) FUN_14257dc30(replacement);
    *holder = reinterpret_cast<std::uintptr_t>(replacement); return holder;
}
// MS2-FUNCTIONAL: releases the shared stream stored in the holder.
// @0x14001bc40
void FUN_14001bc40(void** holder) { if (*holder) FUN_14257dcb0(*holder); }
// MS2-FUNCTIONAL: releases the shared stream stored in the holder.
// @0x14001bca0
void FUN_14001bca0(void** holder) { if (*holder) FUN_14257dcb0(*holder); }
// MS2-FUNCTIONAL: retains the replacement shared stream and releases the old stream.
// @0x14001bcc0
std::uint64_t* FUN_14001bcc0(std::uint64_t* holder, void* replacement)
{
    if (replacement) FUN_14257dc30(replacement);
    if (*holder) FUN_14257dcb0(reinterpret_cast<void*>(*holder));
    *holder = reinterpret_cast<std::uintptr_t>(replacement); return holder;
}
// MS2-FUNCTIONAL: releases the shared stream stored in the holder.
// @0x14001bd70
void FUN_14001bd70(void** holder) { if (*holder) FUN_14257dcb0(*holder); }
// MS2-FUNCTIONAL: releases the old shared stream and replaces it without retaining the new stream.
// @0x14001bd90
std::uint64_t* FUN_14001bd90(std::uint64_t* holder, std::uint64_t replacement)
{
    if (*holder) FUN_14257dcb0(reinterpret_cast<void*>(*holder)); *holder = replacement; return holder;
}
// MS2-FUNCTIONAL: releases the shared stream stored in the holder.
// @0x14001bdf0
void FUN_14001bdf0(void** holder) { if (*holder) FUN_14257dcb0(*holder); }
// MS2-FUNCTIONAL: retains the replacement shared stream and releases the old stream.
// @0x14001be10
std::uint64_t* FUN_14001be10(std::uint64_t* holder, void* replacement)
{
    if (replacement) FUN_14257dc30(replacement);
    if (*holder) FUN_14257dcb0(reinterpret_cast<void*>(*holder));
    *holder = reinterpret_cast<std::uintptr_t>(replacement); return holder;
}
// MS2-FUNCTIONAL: releases the old shared stream and stores the supplied pointer without retaining it.
// @0x14001be50
std::uint64_t* FUN_14001be50(std::uint64_t* holder, std::uint64_t replacement)
{
    if (*holder) FUN_14257dcb0(reinterpret_cast<void*>(*holder)); *holder = replacement; return holder;
}

// MS2-FUNCTIONAL: forwards event dispatch to the common AS3 interactive object handler.
// @0x14001b040
__declspec(noinline) bool thunk_FUN_142518c70(void* object, void* event) { return FUN_142518c70(object, event); }
// MS2-FUNCTIONAL: normalizes a tagged atom and dispatches it through the recovered AS3 helper.
// @0x14001b050
__declspec(noinline) void thunk_FUN_142519080(void* value)
{
    auto atom = *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(value) + 0x10);
    if (!atom) atom = *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(value) + 8);
    if (atom & 1) --atom;
    FUN_142526340(value, atom);
}
// MS2-FUNCTIONAL: AvmInteractiveObj::OnEventUnload.
// @0x14001b060
__declspec(noinline) void thunk_FUN_142519860(void* object) { FUN_142519860(object); }
// MS2-FUNCTIONAL: forwards absolute path formatting to the AS3 display object helper.
// @0x14001b0a0
__declspec(noinline) const char* thunk_FUN_142506e10(void* object, void* path) { return FUN_142506e10(object, path); }
// MS2-FUNCTIONAL: forwards focus changes to the shared AS3 interactive object handler.
// @0x14001b0e0
__declspec(noinline) void FUN_14001b0e0(void* object, std::uint32_t event, void* target, std::uint32_t controller, std::uint32_t moved)
{
    FUN_142519d50(object, event, target, controller, moved);
}
// MS2-FUNCTIONAL: restores the executable's AvmInteractiveObj vtable and destroys the base object.
// @0x14001b3a0
__declspec(noinline) void* FUN_14001b3a0(void* object)
{
    *reinterpret_cast<void***>(static_cast<unsigned char*>(object) + 0x40) = &AvmInteractiveVtable;
    FUN_1424ddc20(object);
    return object;
}
// MS2-FUNCTIONAL: replaces the pointer only after releasing the previously stored value.
// @0x14001bac0
std::uint64_t* FUN_14001bac0(std::uint64_t* holder, std::uint64_t replacement)
{
    if (*holder) FUN_14257dcd0(reinterpret_cast<void*>(*holder));
    *holder = replacement; return holder;
}
// MS2-FUNCTIONAL: releases the retained pointer stored in the holder.
// @0x14001bb40
void FUN_14001bb40(void** holder) { if (*holder) FUN_14257dcd0(*holder); }
// MS2-FUNCTIONAL: releases the shared stream stored in the holder.
// @0x14001bb80
void FUN_14001bb80(void** holder) { if (*holder) FUN_14257dcb0(*holder); }
// MS2-FUNCTIONAL: releases the Scaleform resource stored in the holder.
// @0x14001bd20
void FUN_14001bd20(void** holder) { if (*holder) FUN_1425a4030(*holder); }
// MS2-FUNCTIONAL: requests the global Scaleform log when no video log is installed.
// @0x14001bf90
void FUN_14001bf90(void* object)
{
    if (!*reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x20)) FUN_14257e080();
}
// MS2-FUNCTIONAL: adds the resource identifier to the movie load task while no failure is present.
// @0x14001bfd0
void FUN_14001bfd0(void* object, const std::uint32_t* id)
{
    if (*reinterpret_cast<std::uint32_t*>(static_cast<unsigned char*>(object) + 0x3b8) == 0) {
        std::uint32_t value = *id;
        FUN_1425cd370(*reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x38), &value);
    }
}

// The Video display object's this-adjusting slots: 0x1431b7de0 is the +0x40 / +0x10 bases' table, 0x1431b7ea0 the
// +0x30 / +0x10 bases'; each moves `this` back and runs the primary slot (slot index in brackets).
// 0x1431b7de0 [0]
// @0x14001b1e0
void* FUN_14001b1e0(void* p) { return FUN_14001b3a0(static_cast<unsigned char*>(p) - 0x40); }
// 0x1431b7de0 [1]
// @0x14001b2a0
void* FUN_14001b2a0(void* p) { return FUN_14001afe0(static_cast<unsigned char*>(p) - 0x40); }
// 0x1431b7de0 [2]
// @0x14001b2c0
std::uint64_t FUN_14001b2c0(void* p) { return FUN_14001b000(static_cast<unsigned char*>(p) - 0x40); }
// 0x1431b7de0 [3]
// @0x14001b280
std::uint64_t FUN_14001b280(void* p) { return FUN_14001b010(static_cast<unsigned char*>(p) - 0x40); }
// 0x1431b7de0 [4]
// @0x14001b2d0
std::uint64_t FUN_14001b2d0(void* p) { return FUN_14001b020(static_cast<unsigned char*>(p) - 0x40); }
// 0x1431b7de0 [5]
// @0x14001b200
std::uint64_t FUN_14001b200(void* p) { return FUN_14001b030(static_cast<unsigned char*>(p) - 0x40); }
// 0x1431b7de0 [6]
// @0x14001b270
const char* FUN_14001b270(void* p, void* path) { return thunk_FUN_142506e10(static_cast<unsigned char*>(p) - 0x40, path); }
// 0x1431b7de0 [7]
// @0x14001b1f0
bool FUN_14001b1f0(void* p, const void* id) { return thunk_FUN_142510dc0(static_cast<unsigned char*>(p) - 0x40, id); }
// 0x1431b7de0 [8]
// @0x14001b220
bool FUN_14001b220(void* p, void* event) { return thunk_FUN_142518c70(static_cast<unsigned char*>(p) - 0x40, event); }
// 0x1431b7de0 [9]
// @0x14001b350
void FUN_14001b350(void* p) { thunk_FUN_142519080(static_cast<unsigned char*>(p) - 0x40); }
// 0x1431b7de0 [10]
// @0x14001b1a0
void FUN_14001b1a0(void* p) { thunk_FUN_142519860(static_cast<unsigned char*>(p) - 0x40); }
// 0x1431b7de0 [11]
// @0x14001b2e0
std::uint8_t FUN_14001b2e0(void* p) { return FUN_14001b070(static_cast<unsigned char*>(p) - 0x40); }
// 0x1431b7de0 [12]
// @0x14001b250
void* FUN_14001b250(void* p) { return FUN_14001afd0(static_cast<unsigned char*>(p) - 0x40); }
// 0x1431b7de0 [13]
// @0x14001b210
std::uint8_t FUN_14001b210(void* p) { return FUN_14001b090(static_cast<unsigned char*>(p) - 0x10); }
// 0x1431b7de0 [14]
// @0x14001b330
std::uint64_t FUN_14001b330(void* p) { return FUN_14001b0b0(static_cast<unsigned char*>(p) - 0x10); }
// 0x1431b7de0 [15]
// @0x14001b240
void FUN_14001b240(void* p, const void* source) { thunk_FUN_1424efe00(static_cast<unsigned char*>(p) - 0x10, source); }
// 0x1431b7de0 [16]
// @0x14001b190
void FUN_14001b190(void* p, const void* source) { thunk_FUN_1424f1f70(static_cast<unsigned char*>(p) - 0x10, source); }
// 0x1431b7de0 [17]
// @0x14001b290
void FUN_14001b290(void* p, std::uint32_t event, void* target, std::uint32_t controller, std::uint32_t moved) { FUN_14001b0e0(static_cast<unsigned char*>(p) - 0x10, event, target, controller, moved); }
// 0x1431b7de0 [18]
// @0x14001b230
void FUN_14001b230(void* p) { FUN_14001b100(static_cast<unsigned char*>(p) - 0x10); }
// 0x1431b7de0 [19]
// @0x14001b180
bool FUN_14001b180(void* p) { return FUN_14001b110(static_cast<unsigned char*>(p) - 0x10); }
// 0x1431b7de0 [20]
// @0x14001b380
bool FUN_14001b380(void* p) { return FUN_14001b120(static_cast<unsigned char*>(p) - 0x10); }
// 0x1431b7de0 [21]
// @0x14001b160
bool FUN_14001b160(void* p) { return FUN_14001b130(static_cast<unsigned char*>(p) - 0x10); }
// 0x1431b7de0 [22]
// @0x14001b370
bool FUN_14001b370(void* p) { return FUN_14001b140(static_cast<unsigned char*>(p) - 0x10); }
// 0x1431b7ea0 [0]
// @0x14001b2f0
void* FUN_14001b2f0(void* p) { return FUN_14001b3a0(static_cast<unsigned char*>(p) - 0x30); }
// 0x1431b7ea0 [1]
// @0x14001b170
void* FUN_14001b170(void* p) { return FUN_14001afe0(static_cast<unsigned char*>(p) - 0x30); }
// 0x1431b7ea0 [2]
// @0x14001b1b0
std::uint64_t FUN_14001b1b0(void* p) { return FUN_14001b000(static_cast<unsigned char*>(p) - 0x30); }
// 0x1431b7ea0 [3]
// @0x14001b390
std::uint64_t FUN_14001b390(void* p) { return FUN_14001b010(static_cast<unsigned char*>(p) - 0x30); }
// 0x1431b7ea0 [4]
// @0x14001b1c0
std::uint64_t FUN_14001b1c0(void* p) { return FUN_14001b020(static_cast<unsigned char*>(p) - 0x30); }
// 0x1431b7ea0 [5]
// @0x14001b310
std::uint64_t FUN_14001b310(void* p) { return FUN_14001b030(static_cast<unsigned char*>(p) - 0x30); }
// 0x1431b7ea0 [6]
// @0x14001b360
const char* FUN_14001b360(void* p, void* path) { return thunk_FUN_142506e10(static_cast<unsigned char*>(p) - 0x30, path); }
// 0x1431b7ea0 [7]
// @0x14001b300
bool FUN_14001b300(void* p, const void* id) { return thunk_FUN_142510dc0(static_cast<unsigned char*>(p) - 0x30, id); }
// 0x1431b7ea0 [8]
// @0x14001b320
bool FUN_14001b320(void* p, void* event) { return thunk_FUN_142518c70(static_cast<unsigned char*>(p) - 0x30, event); }
// 0x1431b7ea0 [9]
// @0x14001b260
void FUN_14001b260(void* p) { thunk_FUN_142519080(static_cast<unsigned char*>(p) - 0x30); }
// 0x1431b7ea0 [10]
// @0x14001b2b0
void FUN_14001b2b0(void* p) { thunk_FUN_142519860(static_cast<unsigned char*>(p) - 0x30); }
// 0x1431b7ea0 [11]
// @0x14001b1d0
std::uint8_t FUN_14001b1d0(void* p) { return FUN_14001b070(static_cast<unsigned char*>(p) - 0x30); }
// 0x1431b7ea0 [12]
// @0x14001b340
void* FUN_14001b340(void* p) { return FUN_14001afd0(static_cast<unsigned char*>(p) - 0x30); }

// MS2-FUNCTIONAL: copies a VideoPlayer pointer array into fresh allocator owned storage.
// @0x142742ed0
void* FUN_142742ed0(void* destination, const std::uint64_t* source)
{
    using Element = Scaleform::GFx::Video::VideoPlayerImpl*;
    using Data = Scaleform::ArrayDataBase<Element, Scaleform::AllocatorGH<Element, 2>, Scaleform::ArrayDefaultPolicy>;
    auto* output = static_cast<Data*>(destination);
    output->Data = nullptr; output->Size = 0; output->Policy.SetCapacity(0);
    const auto count = source[1];
    auto* input = reinterpret_cast<Element*>(source[0]);
    if (count) {
        output->Reserve(output, (count >> 2) + count);
        output->Size = count;
        for (std::uint64_t i = 0; i < count; ++i) output->Data[i] = input[i];
    }
    return destination;
}
// MS2-FUNCTIONAL: copies the three leading array fields and deep copies the VideoPlayer list.
// @0x142742f70
std::uint64_t* FUN_142742f70(std::uint64_t* destination, const std::uint64_t* source)
{
    destination[0] = source[0]; destination[1] = source[1]; destination[2] = source[2];
    FUN_142742ed0(destination + 3, source + 3);
    return destination;
}

namespace {

// MS2-FUNCTIONAL: runs the base AS3 traits initializer and installs the Video traits vtable and object size.
// @0x14001a080
void* FUN_14001a080(void* traits)
{
    FUN_1424d6750(traits, nullptr, nullptr);
    *reinterpret_cast<std::uint32_t*>(static_cast<unsigned char*>(traits) + 0xc) = 0x78;
    *reinterpret_cast<void***>(traits) = &VideoTraitsVtable;
    return traits;
}
// MS2-FUNCTIONAL: releases an old reference and stores the supplied pointer.
// @0x14001a0e0
std::uint64_t* FUN_14001a0e0(std::uint64_t* holder, std::uint64_t replacement)
{
    if (*holder) FUN_14257dcd0(reinterpret_cast<void*>(*holder));
    *holder = replacement; return holder;
}
// MS2-FUNCTIONAL: initializes a native callback record with its VM, property and integer payload.
// @0x14001a920
std::uint64_t* FUN_14001a920(std::uint64_t* record, std::uint64_t vm, std::uint64_t property, int, std::uint64_t, const std::uint32_t* value)
{
    record[1] = property; record[0] = vm; reinterpret_cast<std::uint32_t*>(record)[4] = *value;
    return record;
}
} // namespace (sfr_video_04 calls FUN_14001af70)

// MS2-FUNCTIONAL: the AS3 AVM video character constructor (sfr_video_04): runs the AvmInteractiveObj base constructor on
// the character (rdx passes through) and installs the Video character vtables and defaults.
// @0x14001af70
void* FUN_14001af70(void* self, Scaleform::GFx::InteractiveObject* object)
{
    auto* traits = static_cast<std::uint64_t*>(self);
    FUN_1424d6480(traits, object);
    reinterpret_cast<std::uint32_t*>(traits)[20] = 0;
    *reinterpret_cast<std::uint32_t*>(reinterpret_cast<unsigned char*>(traits) + 0x4c) = 0;
    reinterpret_cast<std::uint32_t*>(traits)[18] = 0;
    *reinterpret_cast<std::uint8_t*>(reinterpret_cast<unsigned char*>(traits) + 0x54) = 1;
    *reinterpret_cast<void***>(traits) = &VideoTraitsBaseVtable;
    reinterpret_cast<void***>(traits)[6] = &VideoTraitsSubVtableA;
    reinterpret_cast<void***>(traits)[8] = &VideoTraitsSubVtableB;
    return traits;
}

namespace {

// MS2-FUNCTIONAL: initializes a null output and forwards metadata handling to its callback helper.
// @0x140019850
std::uint64_t* FUN_140019850(void* self, std::uint64_t* result)
{
    *result = 0; FUN_140019470(self, result); return result;
}
// MS2-FUNCTIONAL: initializes a null output and forwards cue-point handling to its callback helper.
// @0x140019870
std::uint64_t* FUN_140019870(void* self, std::uint64_t* result)
{
    *result = 0; FUN_140019660(self, result); return result;
}
// MS2-FUNCTIONAL: allocates a Video instance-traits object and constructs it for the supplied class traits.
// @0x140019bd0
void** FUN_140019bd0(void** result, void* classTraits)
{
    auto* heap = *reinterpret_cast<void***>(static_cast<unsigned char*>(classTraits) + 0x38);
    auto allocate = reinterpret_cast<void*(*)(void*, std::size_t, unsigned)>(heap[10]);
    auto* object = allocate(heap, 200, 0);
    *result = object ? FUN_1400199e0(object, classTraits) : nullptr;
    return result;
}
// MS2-FUNCTIONAL: allocates a Video traits object and constructs it for the supplied class traits.
// @0x14001af10
void** FUN_14001af10(void** result, void* classTraits)
{
    auto* heap = *reinterpret_cast<void***>(static_cast<unsigned char*>(classTraits) + 0x38);
    auto allocate = reinterpret_cast<void*(*)(void*, std::size_t, unsigned)>(heap[10]);
    auto* object = allocate(heap, 200, 0);
    *result = object ? FUN_14001ad20(object, classTraits) : nullptr;
    return result;
}

// MS2-FUNCTIONAL: initializes the AS3 callback record and captures the optional first atom argument.
// @0x1400170c0
std::uint64_t* FUN_1400170c0(std::uint64_t* record, std::uint64_t vm, std::uint64_t property, unsigned count, const std::uint8_t* args, const std::uint64_t* defaults)
{
    record[0] = vm; record[1] = property;
    record[2] = defaults[0];
    if (count) record[2] = ((*args & 0x1f) != 0) ? *reinterpret_cast<const std::uint64_t*>(args + 0x10) : 0;
    record[3] = defaults[1];
    return record;
}
// MS2-FUNCTIONAL: removes the hashed atom key from its chained Scaleform table.
// @0x140017320
void FUN_140017320(std::uint64_t* table, const std::uint64_t* key)
{
    EraseVideoAtomHashEntry(table, key);
}

// MS2-FUNCTIONAL: reference-counts CRI movie startup and allocates its eight-handle work area on first use.
// @0x14001b460
void FUN_14001b460(std::uint8_t optional)
{
    const int previous = VideoCriUsers++;
    if (previous == 0) {
        criHeap_Initialize();
        VideoCriWorkSize = CriMv::CalcMovieHandleWork(8, CriMv::ErrorContainer);
        auto** heap = *reinterpret_cast<void***>(DAT_143b15f60);
        VideoCriWork = reinterpret_cast<void*(*)(void*, std::size_t, unsigned)>(heap[10])(DAT_143b15f60, VideoCriWorkSize, 0);
        CriMv::SetupMovieHandleWork(8, VideoCriWork, VideoCriWorkSize, CriMv::ErrorContainer);
        FUN_140026ed0(&CriMv::ErrorContainer);
        if (optional) FUN_140026db0();
    }
}
// MS2-FUNCTIONAL: finalizes CRI movie work and its heap on the final reference release.
// @0x14001b4f0
void FUN_14001b4f0()
{
    const int previous = VideoCriUsers--;
    if (previous == 1) {
        CriMv::Finalize(CriMv::ErrorContainer);
        if (VideoCriWork) {
            auto** heap = *reinterpret_cast<void***>(DAT_143b15f60);
            reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, VideoCriWork);
        }
        criHeap_Finalize();
    }
}
// MS2-FUNCTIONAL: allocates one 16 KiB read buffer per stream and frees partial allocations on failure.
// @0x14001b550
std::uint64_t FUN_14001b550(void* state, int count, std::uint32_t chunkSize)
{
    if (!count) return 0;
    auto* bytes = static_cast<unsigned char*>(state);
    *reinterpret_cast<int*>(bytes + 0x38) = count;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x3c) = chunkSize;
    *reinterpret_cast<std::uint32_t*>(bytes + 0x40) = 0;
    auto** heap = *reinterpret_cast<void***>(*reinterpret_cast<void**>(bytes + 0x10));
    auto allocate = reinterpret_cast<void*(*)(void*, std::size_t, unsigned)>(heap[10]);
    auto** blocks = reinterpret_cast<void**>(bytes + 0x50);
    for (int i = 0; i < count; ++i) {
        blocks[i] = allocate(*reinterpret_cast<void**>(bytes + 0x10), 0x4000, 0);
        if (!blocks[i]) {
            auto** globalHeap = *reinterpret_cast<void***>(DAT_143b15f60);
            for (int j = i - 1; j >= 0; --j) {
                reinterpret_cast<void(*)(void*, void*)>(globalHeap[12])(DAT_143b15f60, blocks[j]);
                blocks[j] = nullptr;
            }
            return 0;
        }
    }
    return 1;
}
// MS2-FUNCTIONAL: frees and clears every per-stream read buffer.
// @0x14001b620
void FUN_14001b620(void* state)
{
    auto* bytes = static_cast<unsigned char*>(state);
    const auto count = *reinterpret_cast<std::uint32_t*>(bytes + 0x38);
    auto** blocks = reinterpret_cast<void**>(bytes + 0x50);
    auto** heap = *reinterpret_cast<void***>(DAT_143b15f60);
    for (std::uint32_t i = 0; i < count; ++i) {
        reinterpret_cast<void(*)(void*, void*)>(heap[12])(DAT_143b15f60, blocks[i]);
        blocks[i] = nullptr;
    }
    *reinterpret_cast<std::uint32_t*>(bytes + 0x38) = 0;
}

// MS2-FUNCTIONAL: reads interleaved PCM words from the per-channel stream buffers.
// @0x14001b6b0
int FUN_14001b6b0(void* player, std::uint32_t* output, std::uint32_t requestedBytes)
{
    auto* state = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(player) + 0x10);
    const auto channels = *reinterpret_cast<std::uint32_t*>(state + 0x38);
    auto remaining = static_cast<std::uint64_t>((requestedBytes & 0x1fffffff) >> 2) / channels;
    std::uint64_t samples = 0;
    auto* reader = *reinterpret_cast<void**>(state + 0x30);
    if (reader) {
        auto** vtable = *reinterpret_cast<void***>(reader);
        auto read = reinterpret_cast<std::uint32_t(*)(void*, std::uint32_t, void*, std::uint64_t)>(vtable[2]);
        if (channels == 1) {
            samples = read(reader, 1, output, remaining);
        } else {
            while (remaining) {
                auto received = read(reader, channels, state + 0x50, remaining);
                if (!received) break;
                auto* destination = output;
                auto** buffers = reinterpret_cast<void**>(state + 0x50);
                for (std::uint32_t frame = 0; frame < received; ++frame) {
                    for (std::uint32_t channel = 0; channel < channels; ++channel)
                        *destination++ = *reinterpret_cast<std::uint32_t*>(static_cast<unsigned char*>(buffers[channel]) + frame * 4);
                }
                output = destination;
                samples += received;
                remaining -= received;
            }
        }
    }
    *reinterpret_cast<std::uint64_t*>(state + 0x48) += samples;
    return static_cast<int>((channels * static_cast<std::uint32_t>(samples) & 0x7ffffff) << 2);
}

// MS2-FUNCTIONAL: captures two string callback parameters, retaining defaults and converting supplied AS3 values.
// @0x140017130
std::uint64_t* FUN_140017130(std::uint64_t* record, std::uint64_t vm, std::uint64_t property, unsigned count, const std::uint64_t* args, const std::uint64_t* defaults)
{
    record[0] = vm; record[1] = property;
    record[2] = defaults[0];
    if (record[2]) ++*reinterpret_cast<std::uint32_t*>(record[2] + 0x18);
    if (count) ConvertAS3ValueToString(const_cast<std::uint64_t*>(args), nullptr, record + 2);
    record[3] = defaults[1];
    if (record[3]) ++*reinterpret_cast<std::uint32_t*>(record[3] + 0x18);
    if (count > 1 && *reinterpret_cast<unsigned char*>(vm + 0x180) == 0)
        ConvertAS3ValueToString(const_cast<std::uint64_t*>(args + 4), nullptr, record + 3);
    return record;
}
// MS2-FUNCTIONAL: captures three string callback parameters and converts each supplied AS3 argument.
// @0x140017250
std::uint64_t* FUN_140017250(std::uint64_t* record, std::uint64_t vm, std::uint64_t property, unsigned count, const std::uint64_t* args, const std::uint64_t* defaults)
{
    FUN_140017130(record, vm, property, count, args, defaults);
    record[4] = defaults[2];
    if (record[4]) ++*reinterpret_cast<std::uint32_t*>(record[4] + 0x18);
    if (count > 2 && *reinterpret_cast<unsigned char*>(vm + 0x180) == 0)
        ConvertAS3ValueToString(const_cast<std::uint64_t*>(args + 8), nullptr, record + 4);
    return record;
}

namespace {
void* BuildVideoTraits(void* classTraits, void* vm, const void* classInfo, void** classVtable, void** instanceVtable, std::uint32_t instanceFlags)
{
    FUN_1424dabd0(classTraits, vm, classInfo);
    *reinterpret_cast<void***>(classTraits) = classVtable;
    auto** heap = *reinterpret_cast<void***>(static_cast<unsigned char*>(vm) + 0x38);
    auto allocate = reinterpret_cast<void*(*)(void*, std::size_t, unsigned)>(heap[10]);
    auto* instance = allocate(heap, 0xe8, 0);
    if (instance) {
        FUN_1424d6750(instance, vm, classInfo);
        *reinterpret_cast<std::uint32_t*>(static_cast<unsigned char*>(instance) + 0x60) = instanceFlags;
        *reinterpret_cast<void***>(instance) = instanceVtable;
    }
    auto* typedTraits = static_cast<Scaleform::GFx::AS3::ClassTraits::Traits*>(classTraits);
    auto* typedInstance = static_cast<Scaleform::GFx::AS3::InstanceTraits::Traits*>(instance);
    typedTraits->SetInstanceTraits(Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>(typedInstance));
    auto* ctraits = allocate(heap, 0x50, 0);
    if (ctraits) {
        FUN_1424d6ac0(ctraits, classTraits);
        *reinterpret_cast<void***>(ctraits) = &VideoCTraitsVtable;
    }
    if (instance) {
        auto* slot = reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(instance) + 0x80);
        ReleaseVideoAtom(slot);
        *slot = reinterpret_cast<std::uintptr_t>(ctraits);
    }
    return classTraits;
}
}
} // namespace (FUN_1400199e0 / FUN_14001ad20 are declared at global scope above)
// MS2-FUNCTIONAL: constructs the Video AS3 class traits and its instance and native traits objects.
// @0x1400199e0
void* FUN_1400199e0(void* traits, void* vm)
{
    return BuildVideoTraits(traits, vm, &VideoClassInfoA, &VideoClassVtableA, &VideoInstanceVtableA, 0xf8);
}
// MS2-FUNCTIONAL: constructs the VideoPlayer AS3 class traits and its instance and native traits objects.
// @0x14001ad20
void* FUN_14001ad20(void* traits, void* vm)
{
    return BuildVideoTraits(traits, vm, &VideoClassInfoB, &VideoClassVtableB, &VideoInstanceVtableB, 0x78);
}
namespace {

namespace {
Scaleform::GFx::ASStringNode* MakeVideoNullString(Scaleform::GFx::ASStringManager* manager)
{
    return manager->CreateConstStringNode("null", 4, 0);
}
void ReleaseVideoString(Scaleform::GFx::ASStringNode* node)
{
    if (node && --*reinterpret_cast<std::uint32_t*>(reinterpret_cast<unsigned char*>(node) + 0x18) == 0)
        node->ReleaseNode();
}
}
// MS2-FUNCTIONAL: dispatches the metadata or cue callback with converted AS3 string parameters.
// @0x140017520
void FUN_140017520(void*, void* vm, void* frame, std::uint64_t property, unsigned count, const std::uint64_t* args)
{
    auto* vmImpl = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(vm) + 0x10);
    auto* manager = *reinterpret_cast<Scaleform::GFx::ASStringManager**>(vmImpl + 0x1e8);
    auto* first = MakeVideoNullString(manager); auto* second = MakeVideoNullString(manager);
    std::uint64_t defaults[2] = {reinterpret_cast<std::uintptr_t>(first), reinterpret_cast<std::uintptr_t>(second)};
    std::uint64_t record[4]{};
    FUN_140017130(record, reinterpret_cast<std::uintptr_t>(vm), property, count, args, defaults);
    ReleaseVideoString(first); ReleaseVideoString(second);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0) {
        std::uint64_t outA = 0, outB = 0;
        auto thunk = reinterpret_cast<void(*)(std::uintptr_t, std::uint64_t, std::uint64_t*, std::uint64_t*)>(VideoStringCallbackA);
        thunk(reinterpret_cast<std::uintptr_t>(VideoStringCallbackBaseA) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(frame) + 0x10), record[0], &outA, &outB);
        ReleaseVideoString(reinterpret_cast<Scaleform::GFx::ASStringNode*>(outA));
        ReleaseVideoString(reinterpret_cast<Scaleform::GFx::ASStringNode*>(outB));
    }
    ReleaseVideoString(reinterpret_cast<Scaleform::GFx::ASStringNode*>(record[2]));
    ReleaseVideoString(reinterpret_cast<Scaleform::GFx::ASStringNode*>(record[3]));
}
// MS2-FUNCTIONAL: dispatches the subtitle callback with converted AS3 string parameters.
// @0x140017670
void FUN_140017670(void*, void* vm, void* frame, std::uint64_t property, unsigned count, const std::uint64_t* args)
{
    auto* vmImpl = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(vm) + 0x10);
    auto* manager = *reinterpret_cast<Scaleform::GFx::ASStringManager**>(vmImpl + 0x1e8);
    auto* first = MakeVideoNullString(manager); auto* second = MakeVideoNullString(manager); auto* third = MakeVideoNullString(manager);
    std::uint64_t defaults[3] = {reinterpret_cast<std::uintptr_t>(first), reinterpret_cast<std::uintptr_t>(second), reinterpret_cast<std::uintptr_t>(third)};
    std::uint64_t record[5]{};
    FUN_140017250(record, reinterpret_cast<std::uintptr_t>(vm), property, count, args, defaults);
    ReleaseVideoString(first); ReleaseVideoString(second); ReleaseVideoString(third);
    if (*reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(vm) + 0x180) == 0) {
        std::uint64_t outA = 0, outB = 0, outC = 0;
        auto thunk = reinterpret_cast<void(*)(std::uintptr_t, std::uint64_t, std::uint64_t*, std::uint64_t*, std::uint64_t*)>(VideoStringCallbackB);
        thunk(reinterpret_cast<std::uintptr_t>(VideoStringCallbackBaseB) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(frame) + 0x10), record[0], &outA, &outB, &outC);
        ReleaseVideoString(reinterpret_cast<Scaleform::GFx::ASStringNode*>(outA));
        ReleaseVideoString(reinterpret_cast<Scaleform::GFx::ASStringNode*>(outB));
        ReleaseVideoString(reinterpret_cast<Scaleform::GFx::ASStringNode*>(outC));
    }
    ReleaseVideoString(reinterpret_cast<Scaleform::GFx::ASStringNode*>(record[2]));
    ReleaseVideoString(reinterpret_cast<Scaleform::GFx::ASStringNode*>(record[3]));
    ReleaseVideoString(reinterpret_cast<Scaleform::GFx::ASStringNode*>(record[4]));
}

} // namespace (sfr36: the natives below have external linkage, other units take their addresses)
// MS2-FUNCTIONAL: creates the video metadata object, adds its standard fields, and returns a retained object atom.
// @0x1400192e0
void FUN_1400192e0(void* callback, std::uint64_t* output)
{
    auto* vm = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callback) + 0x10);
    auto* callFrame = *reinterpret_cast<unsigned char**>(vm + 0x20);
    auto* as3vm = *reinterpret_cast<unsigned char**>(callFrame + 0x78);
    std::uint64_t objectResult = 0;
    FUN_142516600(as3vm, &objectResult);
    auto* object = reinterpret_cast<Scaleform::GFx::AS3::Object*>(objectResult);
    auto* manager = *reinterpret_cast<Scaleform::GFx::ASStringManager**>(*reinterpret_cast<unsigned char**>(as3vm + 0x10) + 0x1e8);
    const char* names[] = {"onMetaData", "onCuePoint", "onSubtitle"};
    const std::size_t offsets[] = {0x98, 0xb8, 0xd8};
    for (unsigned i = 0; i < 3; ++i) {
        Scaleform::GFx::ASString name(manager->CreateStringNode(names[i]));
        object->AddDynamicSlotValuePair(name, *reinterpret_cast<Scaleform::GFx::AS3::Value*>(static_cast<unsigned char*>(callback) + offsets[i]));
    }
    if (output && *output != objectResult) {
        ReleaseVideoAtom(output);
        RetainVideoAtom(objectResult);
        *output = objectResult;
    }
    auto temporary = objectResult;
    ReleaseVideoAtom(&temporary);
}
namespace {

namespace {
void GetVideoSoundTransform(void* self, std::uint64_t* output, std::size_t fieldOffset)
{
    auto* root = *reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x20) + 0x78);
    Scaleform::GFx::AS3::Value classValue;
    Scaleform::GFx::AS3::Value transform;
    reinterpret_cast<Scaleform::GFx::AS3::VM*>(root)->Construct("flash.media.SoundTransform", classValue, 0, nullptr, true);
    auto* soundClass = classValue.GetObject();
    const auto kind = classValue.GetKind();
    if (*reinterpret_cast<unsigned char*>(root + 0x180) == 0 && kind != 0 && (kind < Scaleform::GFx::AS3::Value::kString || kind > Scaleform::GFx::AS3::Value::kObject || soundClass)) {
        FUN_1424d2150(soundClass, &transform, *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(self) + fieldOffset));
        auto atom = reinterpret_cast<std::uintptr_t>(soundClass);
        ReleaseVideoAtom(output);
        RetainVideoAtom(atom);
        *output = atom;
    }
}
}
} // namespace (sfr36: the natives below have external linkage, other units take their addresses)
// MS2-FUNCTIONAL: resolves flash.media.SoundTransform and applies the instance's current transform value.
// @0x140019470
void FUN_140019470(void* self, std::uint64_t* output) { GetVideoSoundTransform(self, output, 0x88); }
// MS2-FUNCTIONAL: resolves flash.media.SoundTransform and applies the instance's default transform value.
// @0x140019660
void FUN_140019660(void* self, std::uint64_t* output) { GetVideoSoundTransform(self, output, 0x90); }
// sfr22: external linkage, sfr_as3_22b's sound-channel Start paths construct the same object.
// MS2-FUNCTIONAL: initializes and links the per-channel callback object, then registers it with FMOD.
// @0x142742fb0
std::uint64_t* FUN_142742fb0(std::uint64_t* object, void* player, std::uint64_t userData, void* channel)
{
    auto* node = object + 2;
    *reinterpret_cast<void***>(object) = &VideoAudioDeleteVtable;
    reinterpret_cast<std::uint32_t*>(object)[2] = 1;
    *reinterpret_cast<void***>(node) = &VideoAudioVtableB;
    object[4] = *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(player) + 0xc0);
    object[3] = reinterpret_cast<std::uintptr_t>(static_cast<unsigned char*>(player) + 0xb0);
    auto** link = reinterpret_cast<std::uint64_t**>(static_cast<unsigned char*>(player) + 0xc0);
    if (*link) (*link)[1] = reinterpret_cast<std::uintptr_t>(node);
    *link = reinterpret_cast<std::uint64_t*>(node);
    *reinterpret_cast<void***>(object) = &VideoAudioVtableA;
    *reinterpret_cast<void***>(node) = &VideoAudioSubVtable;
    object[8] = 0; object[5] = reinterpret_cast<std::uintptr_t>(player); object[6] = userData; object[7] = reinterpret_cast<std::uintptr_t>(channel);
    FUN_1428d8f14(channel, object);
    FUN_1428d8efc(channel, reinterpret_cast<void*>(&FUN_1427443c0));
    return object;
}
namespace {
// MS2-FUNCTIONAL: initializes the audio event listener, its locks, and its intrusive-list sentinel.
// @0x142743130
std::uint64_t* FUN_142743130(std::uint64_t* object)
{
    *reinterpret_cast<void***>(object) = &VideoAudioEventVtable;
    reinterpret_cast<std::uint32_t*>(object)[2] = 1;
    object[2] = 0; object[3] = 0;
    ::new (reinterpret_cast<unsigned char*>(object) + 0x20) Scaleform::Event(false, false);
    ::new (reinterpret_cast<unsigned char*>(object) + 0x80) Scaleform::Lock(0);
    object[0x15] = 0;
    object[0x17] = reinterpret_cast<std::uintptr_t>(object + 0x16);
    *reinterpret_cast<void***>(object + 0x16) = &VideoAudioVtableB;
    object[0x18] = reinterpret_cast<std::uintptr_t>(object + 0x16);
    ::new (reinterpret_cast<unsigned char*>(object) + 0xc8) Scaleform::Lock(0);
    *reinterpret_cast<std::uint8_t*>(reinterpret_cast<unsigned char*>(object) + 0xf0) = 0;
    *reinterpret_cast<std::uint32_t*>(reinterpret_cast<unsigned char*>(object) + 0xf4) = 0;
    *reinterpret_cast<std::uint8_t*>(reinterpret_cast<unsigned char*>(object) + 0x78) = 0;
    return object;
}

} // namespace (sfr36: the natives below have external linkage, other units take their addresses)
// MS2-FUNCTIONAL: reads the three event handler properties from the attached AS3 stream object.
// @0x140017f20
void FUN_140017f20(void* self, void*, void* frame)
{
    auto* vm = *reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x20) + 0x78);
    auto* vmImpl = *reinterpret_cast<unsigned char**>(vm + 0x10);
    auto* manager = *reinterpret_cast<Scaleform::GFx::ASStringManager**>(vmImpl + 0x1e8);
    auto* ns = *reinterpret_cast<Scaleform::GFx::AS3::Instances::Namespace**>(vm + 0x1d0);
    auto* source = reinterpret_cast<Scaleform::GFx::AS3::Object*>(*reinterpret_cast<void**>(static_cast<unsigned char*>(frame) + 0x10));
    const char* names[] = {"onMetaData", "onCuePoint", "onSubtitle"};
    const std::size_t offsets[] = {0x98, 0xb8, 0xd8};
    for (unsigned i = 0; i < 3; ++i) {
        Scaleform::GFx::ASString name(manager->CreateStringNode(names[i]));
        Scaleform::GFx::AS3::Value nameValue(name);
        Scaleform::GFx::AS3::Multiname property(*ns, nameValue);
        Scaleform::GFx::AS3::Value value;
        if (source->GetProperty(property, value))
            reinterpret_cast<Scaleform::GFx::AS3::Value*>(static_cast<unsigned char*>(self) + offsets[i])->Assign(value);
    }
}
namespace {

// MS2-FUNCTIONAL: builds the metadata object from CRI stream dimensions and track counts, then invokes its callback.
// @0x1400182f0
void FUN_1400182f0(void* callback, const std::uint32_t* info)
{
    auto* vm = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callback) + 0x10);
    if (*reinterpret_cast<unsigned char*>(vm + 0x98) == 0) {
        auto* vmRoot = *reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(vm + 0x20) + 0x78);
        std::uint64_t objectResult = 0;
        FUN_142516600(vmRoot, &objectResult);
        auto* object = reinterpret_cast<Scaleform::GFx::AS3::Object*>(objectResult);
        auto* manager = *reinterpret_cast<Scaleform::GFx::ASStringManager**>(*reinterpret_cast<unsigned char**>(vmRoot + 0x10) + 0x1e8);
        auto addNumber = [&](const char* name, double number) {
            Scaleform::GFx::ASString key(manager->CreateStringNode(name));
            Scaleform::GFx::AS3::Value value(number);
            object->AddDynamicSlotValuePair(key, value);
        };
        auto addInt = [&](const char* name, std::uint32_t number) {
            Scaleform::GFx::ASString key(manager->CreateStringNode(name));
            Scaleform::GFx::AS3::Value value(static_cast<Scaleform::UInt32>(number));
            object->AddDynamicSlotValuePair(key, value);
        };
        const float scale = VideoDurationScale;
        addNumber("duration", (static_cast<float>(info[4]) * scale) / static_cast<float>(info[2]));
        addInt("width", info[0]); addInt("height", info[1]); addInt("totalFrames", info[4]);
        addNumber("frameRate", static_cast<float>(info[2]) / scale);
        addInt("subtitleTracksCount", info[0xc]); addInt("audioTracksCount", info[0x10]); addInt("cuePointsCount", info[8]);
        Scaleform::GFx::AS3::Value objectValue(reinterpret_cast<Scaleform::GFx::AS3::Object*>(object));
        auto* callbackValue = reinterpret_cast<Scaleform::GFx::AS3::Value*>(static_cast<unsigned char*>(callback) + 0x98);
        FUN_1424fef00(vmRoot, callbackValue, Scaleform::GFx::AS3::Value::GetUndefined(), &objectValue, 1, &objectValue, 0);
    }
}

} // namespace
// MS2-FUNCTIONAL: resolves and creates the Video display character from the owning MovieDef.
// @0x14001a470
void* FUN_14001a470(void* self)
{
    auto* root = *reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x20) + 0x78);
    auto* library = *reinterpret_cast<unsigned char**>(root + 0x2d8);
    auto* movieDef = FUN_14250d8f0(root, self);
    if (!movieDef) return *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x58);
    alignas(8) std::uint64_t createInfo[3]{};
    FUN_142442c30(self, createInfo, movieDef);
    if (!createInfo[0]) return *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x58);
    auto* creator = *reinterpret_cast<void**>(library + 0x18);
    auto** vtable = *reinterpret_cast<void***>(creator);
    auto create = reinterpret_cast<void*(*)(void*, void*, void*, int, std::uint32_t*, int)>(vtable[4]);
    std::uint32_t flags[2] = {0x40000, 0};
    auto* display = create(creator, *reinterpret_cast<void**>(library + 0x10), createInfo, 0, flags, 7);
    auto* slot = reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x58);
    if (*slot) FUN_14257dcd0(*slot);
    *slot = display;
    if (display) {
        auto* frame = static_cast<unsigned char*>(display) + static_cast<unsigned char>(static_cast<unsigned char*>(display)[0x6d]) * 4;
        FUN_1424edca0(frame, self);
    }
    return display;
}
namespace {

// MS2-FUNCTIONAL: creates a callback property object from the supplied AS3 strings and binds it to this stream.
// @0x140019890
void FUN_140019890(void* self, const std::uint64_t* firstAtom, const std::uint64_t* secondAtom)
{
    auto* vm = *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x10);
    auto* firstNode = reinterpret_cast<Scaleform::GFx::ASStringNode*>(*firstAtom & ~std::uint64_t(3));
    auto* secondNode = reinterpret_cast<Scaleform::GFx::ASStringNode*>(*secondAtom & ~std::uint64_t(3));
    Scaleform::GFx::ASString first(firstNode);
    Scaleform::GFx::ASString second(secondNode);
    std::uint64_t result = 0;
    FUN_142467b50(vm, &result, &first, &second);
    auto* object = reinterpret_cast<unsigned char*>(result);
    auto currentVm = *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(self) + 0x10);
    auto* owner = reinterpret_cast<unsigned char*>(object + 0x48);
    auto old = *reinterpret_cast<std::uint64_t*>(owner);
    if (old != currentVm) {
        ReleaseVideoAtom(reinterpret_cast<std::uint64_t*>(owner));
        RetainVideoAtom(currentVm);
        *reinterpret_cast<std::uint64_t*>(owner) = currentVm;
    }
    FUN_1424687d0(vm, object, 0);
    auto temporary = result;
    ReleaseVideoAtom(&temporary);
}

// MS2-FUNCTIONAL: builds a CRI subtitle/cue event object with its name, timestamp, type and parameter map.
// @0x140018930
void FUN_140018930(void* callback, const std::uint32_t* eventData)
{
    auto* root = *reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(callback) + 0x10) + 0x20);
    auto* vm = *reinterpret_cast<unsigned char**>(root + 0x78);
    auto* callbackValue = reinterpret_cast<Scaleform::GFx::AS3::Value*>(static_cast<unsigned char*>(callback) + 0xb8);
    if (callbackValue->GetKind() == Scaleform::GFx::AS3::Value::kUndefined) return;
    std::uint64_t eventAtom = 0, parametersAtom = 0;
    FUN_142516600(vm, &eventAtom);
    auto* eventObject = reinterpret_cast<Scaleform::GFx::AS3::Object*>(eventAtom);
    auto* vmImpl = *reinterpret_cast<unsigned char**>(vm + 0x10);
    auto* manager = *reinterpret_cast<Scaleform::GFx::ASStringManager**>(vmImpl + 0x1e8);
    auto addString = [&](Scaleform::GFx::AS3::Object* object, const char* key, std::uint64_t atom) {
        Scaleform::GFx::ASString property(manager->CreateStringNode(key));
        auto* node = reinterpret_cast<Scaleform::GFx::ASStringNode*>(atom & ~std::uint64_t(3));
        Scaleform::GFx::ASString string(node);
        Scaleform::GFx::AS3::Value value(string);
        object->AddDynamicSlotValuePair(property, value);
    };
    addString(eventObject, "name", *reinterpret_cast<const std::uint64_t*>(eventData + 2));
    {
        Scaleform::GFx::ASString key(manager->CreateStringNode("time"));
        Scaleform::GFx::AS3::Value value(static_cast<double>(eventData[4]) / VideoDurationScale);
        eventObject->AddDynamicSlotValuePair(key, value);
    }
    {
        Scaleform::GFx::ASString key(manager->CreateStringNode("type"));
        Scaleform::GFx::ASString type(manager->CreateStringNode(eventData[0] == 1 ? "navigation" : "event"));
        Scaleform::GFx::AS3::Value value(type);
        eventObject->AddDynamicSlotValuePair(key, value);
    }
    const auto count = *reinterpret_cast<const std::uint64_t*>(eventData + 8);
    if (count) {
        FUN_142516600(vm, &parametersAtom);
        auto* parameters = reinterpret_cast<Scaleform::GFx::AS3::Object*>(parametersAtom);
        auto* entries = *reinterpret_cast<const std::uint64_t* const*>(eventData + 6);
        for (std::uint64_t i = 0; i < count; ++i) {
            auto* pair = reinterpret_cast<const std::uint64_t*>(reinterpret_cast<const unsigned char*>(entries) + i * 0x10);
            auto* keyNode = reinterpret_cast<Scaleform::GFx::ASStringNode*>(pair[0] & ~std::uint64_t(3));
            auto* valueNode = reinterpret_cast<Scaleform::GFx::ASStringNode*>(pair[1] & ~std::uint64_t(3));
            Scaleform::GFx::ASString property(manager->CreateStringNode(keyNode->pData, keyNode->Size));
            Scaleform::GFx::ASString text(valueNode);
            Scaleform::GFx::AS3::Value value(text);
            parameters->AddDynamicSlotValuePair(property, value);
        }
        Scaleform::GFx::ASString key(manager->CreateStringNode("parameters"));
        Scaleform::GFx::AS3::Value value(parameters);
        eventObject->AddDynamicSlotValuePair(key, value);
    }
    Scaleform::GFx::AS3::Value selfValue(eventObject);
    FUN_1424fef00(vm, static_cast<unsigned char*>(callback) + 0xb8, Scaleform::GFx::AS3::Value::GetUndefined(), &selfValue, 1, &selfValue, 0);
    ReleaseVideoAtom(&parametersAtom);
    ReleaseVideoAtom(&eventAtom);
}

// MS2-FUNCTIONAL: initializes an FMOD stream callback, snapshots its start time, and records pause state.
// @0x142743050
std::uint64_t* FUN_142743050(std::uint64_t* object, void* player, void* streamState, void* channel)
{
    FUN_142742fb0(object, player, reinterpret_cast<std::uintptr_t>(streamState), channel);
    *reinterpret_cast<void***>(object) = &VideoAudioStreamVtable;
    *reinterpret_cast<void***>(object + 2) = &VideoAudioStreamSubVtable;
    object[9] = FUN_1425e3480();
    *reinterpret_cast<std::uint8_t*>(reinterpret_cast<unsigned char*>(object) + 0x69) = 0;
    ::new (reinterpret_cast<unsigned char*>(object) + 0x70) Scaleform::Lock(0);
    *reinterpret_cast<std::uint32_t*>(reinterpret_cast<unsigned char*>(object) + 0x98) = 0;
    if (streamState) _InterlockedIncrement(reinterpret_cast<volatile long*>(static_cast<unsigned char*>(streamState) + 8));
    object[0xb] = 0; object[0xc] = 0;
    bool paused = false;
    FUN_142303a6b(reinterpret_cast<void*>(object[7]), &paused);
    if (paused) { object[10] = object[9]; return object; }
    FUN_142745f50(streamState);
    object[9] = FUN_1425e3480();
    const auto a = *reinterpret_cast<std::uint32_t*>(static_cast<unsigned char*>(streamState) + 0x70);
    const auto b = *reinterpret_cast<std::uint32_t*>(static_cast<unsigned char*>(streamState) + 0x50);
    const auto c = *reinterpret_cast<std::uint32_t*>(static_cast<unsigned char*>(streamState) + 0x48);
    const auto d = *reinterpret_cast<std::uint32_t*>(static_cast<unsigned char*>(streamState) + 0x4c);
    object[0xc] = ((((static_cast<std::uint64_t>(a) << 3) / b) / c) * 1000000) / d;
    return object;
}

// MS2-FUNCTIONAL: initializes the FMOD streaming sound, computes its PCM format, and creates the sound handle.
// @0x142743240
std::uint64_t* FUN_142743240(std::uint64_t* object, void* owner, void* stream, int stereo, std::uint32_t rate, std::uint32_t channels)
{
    auto* node = object + 2;
    *reinterpret_cast<void***>(object) = &VideoSoundDeleteVtable;
    reinterpret_cast<std::uint32_t*>(object)[2] = 1;
    *reinterpret_cast<void***>(node) = &VideoAudioVtableB;
    object[4] = *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(owner) + 0xc0);
    object[3] = reinterpret_cast<std::uintptr_t>(static_cast<unsigned char*>(owner) + 0xb0);
    auto** link = reinterpret_cast<std::uint64_t**>(static_cast<unsigned char*>(owner) + 0xc0);
    if (*link) (*link)[1] = reinterpret_cast<std::uintptr_t>(node);
    *link = reinterpret_cast<std::uint64_t*>(node);
    object[7] = 0;
    *reinterpret_cast<void***>(object) = &VideoSoundVtable;
    *reinterpret_cast<void***>(node) = &VideoSoundSubVtable;
    object[5] = reinterpret_cast<std::uintptr_t>(owner);
    object[6] = 0; object[8] = 0;
    reinterpret_cast<std::uint32_t*>(object)[18] = rate;
    *reinterpret_cast<std::uint32_t*>(reinterpret_cast<unsigned char*>(object) + 0x4c) = channels;
    object[0xb] = 0; reinterpret_cast<std::uint32_t*>(object)[0xc] = 0;
    *reinterpret_cast<std::uint64_t*>(reinterpret_cast<unsigned char*>(object) + 0x6c) = 0;
    if (stream) FUN_14257dc30(stream);
    if (object[8]) FUN_14257dcb0(reinterpret_cast<void*>(object[8]));
    object[8] = reinterpret_cast<std::uintptr_t>(stream);
    const std::uint32_t format = stereo ? 5 : 2;
    const std::uint32_t sampleBits = stereo ? 0x20 : 0x10;
    reinterpret_cast<std::uint32_t*>(object)[0xd] = format;
    reinterpret_cast<std::uint32_t*>(object)[10] = sampleBits;
    const auto pcmBytes = static_cast<std::int32_t>((channels / 1000) * (sampleBits >> 3) * rate * 0x5dc);
    *reinterpret_cast<std::int32_t*>(reinterpret_cast<unsigned char*>(object) + 100) = pcmBytes;
    alignas(8) unsigned char info[0xd8]{};
    *reinterpret_cast<std::uint32_t*>(info) = sizeof(info);
    *reinterpret_cast<std::int32_t*>(info + 4) = pcmBytes;
    *reinterpret_cast<std::int32_t*>(info + 0xc) = static_cast<std::int32_t>(rate);
    *reinterpret_cast<std::uint32_t*>(info + 0x10) = channels;
    *reinterpret_cast<std::uint32_t*>(info + 0x14) = format;
    auto* system = *reinterpret_cast<void**>(static_cast<unsigned char*>(owner) + 0x10);
    auto result = FUN_142303a29(system, nullptr, 0x442, info, reinterpret_cast<void**>(object + 6));
    if (result == 0) {
        std::uint32_t length = 0;
        FUN_142303a4d(reinterpret_cast<void*>(object[6]), &length, 4);
    } else object[6] = 0;
    return object;
}
} // namespace
