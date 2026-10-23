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
#include "../include/gfx/as3/as3_value.h"
#include "../include/gfx/as3/obj/as3_obj_display.h"
#include "hook/ms2hook.h"
#include <cstring>
#include <cstdint>
#include <new>
#include <limits>

MS2_GLOBAL(0x143b27608, void*, VideoThunkA);
MS2_GLOBAL(0x143b27610, void*, VideoThunkBaseA);
MS2_GLOBAL(0x143b27588, void*, VideoThunkB);
MS2_GLOBAL(0x143b27590, void*, VideoThunkBaseB);
MS2_GLOBAL(0x143b27708, void*, VideoThunkC);
MS2_GLOBAL(0x143b27710, void*, VideoThunkBaseC);
MS2_GLOBAL(0x143b275f8, void*, VideoThunkD);
MS2_GLOBAL(0x143b27600, void*, VideoThunkBaseD);
MS2_GLOBAL(0x143b27638, void*, VideoThunkE);
MS2_GLOBAL(0x1431b7ba0, void*, VideoDisplayVtable);
MS2_GLOBAL(0x142d692bc, float, VideoTwipsScale);
MS2_GLOBAL(0x143b27640, void*, VideoThunkBaseE);
MS2_GLOBAL(0x143b27488, void*, VideoThunkF);
MS2_GLOBAL(0x143b27490, void*, VideoThunkBaseF);
MS2_GLOBAL(0x143b27528, void*, VideoCallbackA);
MS2_GLOBAL(0x143b27530, void*, VideoCallbackBaseA);
MS2_GLOBAL(0x143b27548, void*, VideoCallbackB);
MS2_GLOBAL(0x143b27550, void*, VideoCallbackBaseB);
MS2_GLOBAL(0x143b275e8, void*, VideoCallbackC);
MS2_GLOBAL(0x143b275f0, void*, VideoCallbackBaseC);

MS2_EXTERN(0x1423df980, void(void*, void*, void*), VideoNative0);
MS2_EXTERN(0x1423df850, void(void*, void*, void*), VideoNative1);
MS2_EXTERN(0x1423dfd20, void(void*, void*, void*), VideoNative2);
MS2_EXTERN(0x1423df410, void(void*, void*, void*), VideoNative3);
MS2_EXTERN(0x1423dfda0, void(void*, void*, void*), VideoNative4);
MS2_EXTERN(0x1424f1390, void(void*, void*, void*), ConvertAS3ValueToString);
MS2_EXTERN(0x1424f0d30, void(void*, void*, int*, int, void*), ConvertAS3ValueToInt32);
MS2_EXTERN(0x1423dfa20, void(), ReleaseAS3GcObject);
MS2_EXTERN(0x1424df220, void(void*), FUN_1424df220);
MS2_EXTERN(0x1424eb610, void*(void*), FUN_1424eb610);
MS2_EXTERN(0x140010b80, void(void*, void*), FUN_140010b80);
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

void FUN_140017320(void* tablePtr, const std::uint64_t* key)
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
        reinterpret_cast<void(*)(void*, void*, double)>(VideoThunkA.get())(
            static_cast<unsigned char*>(VideoThunkBaseA.get()) + reinterpret_cast<std::uintptr_t>(root),
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
        reinterpret_cast<void(*)(void*, void*, double)>(VideoThunkB.get())(
            static_cast<unsigned char*>(VideoThunkBaseB.get()) + reinterpret_cast<std::uintptr_t>(root),
            member, number);
    }
}

// MS2-FUNCTIONAL: dispatches one of the six recovered native getters selected by the trait index.
// @0x140016c70
void FUN_140016c70(void* object, void* result, unsigned kind)
{
    static const VideoGenericThunk calls[] = {VideoNative0.get(), VideoNative1.get(), VideoNative2.get(),
                                               VideoNative3.get(), VideoNative4.get(), nullptr};
    if (kind < 5) calls[kind](object, result, nullptr);
    else if (kind == 5) reinterpret_cast<VideoGenericThunk>(
        *reinterpret_cast<void**>(static_cast<unsigned char*>(result) + 0x40))(object, result, nullptr);
}

// MS2-FUNCTIONAL: invokes the native setter and then marks the trait value as assigned.
// @0x140016d10
void FUN_140016d10(void* object, void* value)
{
    reinterpret_cast<void(*)(void*, void*, void*)>(*reinterpret_cast<void**>(object))(
        object, value, reinterpret_cast<void*>(VideoNative3.get()));
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
        VideoNative1.get()(object, value, nullptr);
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
        reinterpret_cast<void(*)(std::uint64_t, void*, std::uint64_t)>(VideoThunkC.get())(
            reinterpret_cast<std::uintptr_t>(VideoThunkBaseC.get()) + root, member, value);
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
        reinterpret_cast<void(*)(std::uint64_t, void*, std::uint64_t)>(VideoThunkD.get())(
            reinterpret_cast<std::uintptr_t>(VideoThunkBaseD.get()) + root, member, value);
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
        reinterpret_cast<void(*)(std::uint64_t, void*, std::uint64_t)>(VideoThunkE.get())(
            reinterpret_cast<std::uintptr_t>(VideoThunkBaseE.get()) + root, member, value);
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
            reinterpret_cast<void(*)(std::uint64_t, void*, std::uint64_t, int)>(VideoThunkF.get())(
                reinterpret_cast<std::uintptr_t>(VideoThunkBaseF.get()) + root, member, value, extra);
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
    FUN_140017320(&table, &key);
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

// @0x14001b000
std::uint64_t FUN_14001b000() { return 0; }
// @0x14001b010
std::uint64_t FUN_14001b010() { return 0; }
// @0x14001b020
std::uint64_t FUN_14001b020() { return 0; }
// @0x14001b030
std::uint64_t FUN_14001b030() { return 0; }
// @0x14001b070
std::uint8_t FUN_14001b070() { return 1; }
// @0x14001b080
std::uint8_t thunk_FUN_142510dc0() { return 0; }
// @0x14001b090
std::uint8_t FUN_14001b090() { return 1; }
// @0x14001b0b0
std::uint64_t FUN_14001b0b0() { return 0; }
// @0x14001b0c0
void thunk_FUN_1424efe00() {}
// @0x14001b0d0
void thunk_FUN_1424f1f70() {}

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
}
// MS2-FUNCTIONAL: invokes the metadata callback and converts its object result to an AS3 Value.
// @0x140019d70
void FUN_140019d70(void*, void* vm, void* context, Scaleform::GFx::AS3::Value* output)
{
    ConvertVideoCallback(vm, reinterpret_cast<std::uintptr_t>(VideoCallbackA.get()), reinterpret_cast<std::uintptr_t>(VideoCallbackBaseA.get()) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(context) + 0x10), output);
}
// MS2-FUNCTIONAL: invokes the cue point callback and converts its object result to an AS3 Value.
// @0x140019e20
void FUN_140019e20(void*, void* vm, void* context, Scaleform::GFx::AS3::Value* output)
{
    ConvertVideoCallback(vm, reinterpret_cast<std::uintptr_t>(VideoCallbackB.get()), reinterpret_cast<std::uintptr_t>(VideoCallbackBaseB.get()) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(context) + 0x10), output);
}
// MS2-FUNCTIONAL: invokes the subtitle callback and converts its object result to an AS3 Value.
// @0x140019ed0
void FUN_140019ed0(void*, void* vm, void* context, Scaleform::GFx::AS3::Value* output)
{
    ConvertVideoCallback(vm, reinterpret_cast<std::uintptr_t>(VideoCallbackC.get()), reinterpret_cast<std::uintptr_t>(VideoCallbackBaseC.get()) + *reinterpret_cast<std::uint64_t*>(static_cast<unsigned char*>(context) + 0x10), output);
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
        *reinterpret_cast<float*>(player + 0xe8) = static_cast<float>(*reinterpret_cast<double*>(static_cast<unsigned char*>(self) + 0x68)) * VideoTwipsScale.get();
        *reinterpret_cast<float*>(player + 0xec) = static_cast<float>(*reinterpret_cast<double*>(static_cast<unsigned char*>(self) + 0x70)) * VideoTwipsScale.get();
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
        *reinterpret_cast<float*>(player + 0xe8) = static_cast<float>(object[13]) * VideoTwipsScale.get();
        *reinterpret_cast<float*>(player + 0xec) = static_cast<float>(object[14]) * VideoTwipsScale.get();
    }
}
} // namespace
