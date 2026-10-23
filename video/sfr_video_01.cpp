// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Video, the AS2 side: the video sound
// stream helpers, then NetStream (script object, prototype methods, constructor) with its media provider, and the AS2
// Video object. Our own source, written from the exe; the leaked SDK copies were only used to name things.
// The Video add-on lib was prebuilt with VS2012 (Rich 0xce build 65501), so with our toolset its code is functional.
// MS2-UNIT: sfr_video_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140002930-0x14000e470 .text$mn
#include "../include/video/video_as2netstream.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/gfx_loaderimpl.h"

extern void FUN_14257dcb0(void*);
extern void FUN_14257dcd0(void*);
extern void FUN_14257db40(void*);
extern void FUN_14257db50(void*);
extern void FUN_1429260b0(void*);
extern void FUN_140006a40(Scaleform::UPInt*);
extern void FUN_1425925f0(void*);
extern void* FUN_1425f1910(void*);
extern "C" void* DAT_143b15f60;

static void ReleaseAs2GCObject(void* object)
{
    if (!object) return;
    auto* count = reinterpret_cast<unsigned*>(static_cast<unsigned char*>(object) + 0x18);
    const unsigned value = *count;
    if ((value & 0x03ffffff) != 0) {
        *count = value - 1;
        FUN_1425925f0(object);
    }
}

// MS2-FUNCTIONAL: forwards the video sound stream's channel attachment callback when a channel is present.
// @0x140002930
void FUN_140002930(void* stream)
{
    void* channel = *reinterpret_cast<void**>(static_cast<unsigned char*>(stream) + 0x10);
    if (channel) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(channel))[5])(channel);
}

// MS2-FUNCTIONAL: stores the stream state and notifies the attached channel of the new state.
// @0x140002960
void FUN_140002960(void* stream, unsigned state)
{
    auto* bytes = static_cast<unsigned char*>(stream);
    *reinterpret_cast<unsigned*>(bytes + 0x18) = state;
    void* channel = *reinterpret_cast<void**>(bytes + 0x10);
    if (channel) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(channel))[11])(channel);
}

// MS2-FUNCTIONAL: forwards the stop notification when the stream has an attached channel.
// @0x140002980
void FUN_140002980(void* stream)
{
    void* channel = *reinterpret_cast<void**>(static_cast<unsigned char*>(stream) + 0x10);
    if (channel) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(channel))[10])(channel);
}

// MS2-FUNCTIONAL: releases the currently retained audio channel if one is assigned.
// @0x1400029d0
void FUN_1400029d0(void** channel)
{
    if (*channel) FUN_14257dcb0(*channel);
}

// MS2-FUNCTIONAL: returns the terminated byte string length using the exe's bounded scan behavior.
// @0x140002f70
Scaleform::UPInt FUN_140002f70(const char* text)
{
    const char* cursor = text;
    while (*cursor) ++cursor;
    return static_cast<Scaleform::UPInt>(cursor - text);
}

// MS2-FUNCTIONAL: replaces the retained audio channel after releasing its previous value.
// @0x1400029f0
void** FUN_1400029f0(void** channel, void* replacement)
{
    if (*channel) FUN_14257dcb0(*channel);
    *channel = replacement;
    return channel;
}

// MS2-FUNCTIONAL: stores the ready flag and forwards the state update to the active player.
// @0x140003580
void FUN_140003580(void* player, bool ready)
{
    auto* bytes = static_cast<unsigned char*>(player);
    bytes[0xc0] = ready;
    void* impl = *reinterpret_cast<void**>(bytes + 0x48);
    if (impl) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(impl))[21])(impl);
}

// MS2-FUNCTIONAL: forwards playback start to the active player implementation.
// @0x1400035b0
void FUN_1400035b0(void* player)
{
    void* impl = *reinterpret_cast<void**>(static_cast<unsigned char*>(player) + 0x48);
    if (impl) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(impl))[18])(impl);
}

// MS2-FUNCTIONAL: forwards playback stop to the active player implementation.
// @0x1400035d0
void FUN_1400035d0(void* player)
{
    void* impl = *reinterpret_cast<void**>(static_cast<unsigned char*>(player) + 0x48);
    if (impl) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(impl))[19])(impl);
}

// MS2-FUNCTIONAL: forwards seek to the active player implementation.
// @0x1400035f0
void FUN_1400035f0(void* player)
{
    void* impl = *reinterpret_cast<void**>(static_cast<unsigned char*>(player) + 0x48);
    if (impl) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(impl))[20])(impl);
}

// MS2-FUNCTIONAL: forwards the frame-ready request to the active player implementation.
// @0x140003610
void FUN_140003610(void* player)
{
    void* impl = *reinterpret_cast<void**>(static_cast<unsigned char*>(player) + 0x48);
    if (impl) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(impl))[7])(impl);
}

// MS2-FUNCTIONAL: updates the reload threshold and notifies the active player.
// @0x140003650
void FUN_140003650(void* player, unsigned threshold)
{
    auto* bytes = static_cast<unsigned char*>(player);
    *reinterpret_cast<unsigned*>(bytes + 0xc8) = threshold;
    void* impl = *reinterpret_cast<void**>(bytes + 0x48);
    if (impl) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(impl))[22])(impl);
}

// MS2-FUNCTIONAL: updates the pool count and notifies the active player.
// @0x140003680
void FUN_140003680(void* player, unsigned count)
{
    auto* bytes = static_cast<unsigned char*>(player);
    *reinterpret_cast<unsigned*>(bytes + 0xc4) = count;
    void* impl = *reinterpret_cast<void**>(bytes + 0x48);
    if (impl) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(impl))[23])(impl);
}

// MS2-FUNCTIONAL: updates buffer time and notifies the active player.
// @0x1400036b0
void FUN_1400036b0(void* player, float time)
{
    auto* bytes = static_cast<unsigned char*>(player);
    *reinterpret_cast<float*>(bytes + 0xcc) = time;
    void* impl = *reinterpret_cast<void**>(bytes + 0x48);
    if (impl) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(impl))[24])(impl);
}

// MS2-FUNCTIONAL: updates the open timeout and notifies the active player.
// @0x1400036e0
void FUN_1400036e0(void* player, float timeout)
{
    auto* bytes = static_cast<unsigned char*>(player);
    *reinterpret_cast<float*>(bytes + 0xd0) = timeout;
    void* impl = *reinterpret_cast<void**>(bytes + 0x48);
    if (impl) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(impl))[26])(impl);
}

// MS2-FUNCTIONAL: forwards video information retrieval into the active player.
// @0x140003710
void FUN_140003710(void* player)
{
    auto* impl = *reinterpret_cast<void**>(static_cast<unsigned char*>(player) + 0x48);
    if (impl) reinterpret_cast<void (*)(void*, void*)>((*reinterpret_cast<void***>(impl))[28])(impl,
        static_cast<unsigned char*>(player) + 0xf0);
}

// MS2-FUNCTIONAL: releases an owned Scaleform reference when present.
// @0x140003770
void FUN_140003770(void** value) { if (*value) FUN_14257dcb0(*value); }
// MS2-FUNCTIONAL: releases an owned Scaleform reference when present.
// @0x140003810
void FUN_140003810(void** value) { if (*value) FUN_14257dcb0(*value); }
// MS2-FUNCTIONAL: releases an owned Scaleform reference when present.
// @0x140003850
void FUN_140003850(void** value) { if (*value) FUN_14257dcb0(*value); }

// MS2-FUNCTIONAL: releases the previous interface and stores the retained replacement.
// @0x140003a70
void** FUN_140003a70(void** destination, void* replacement)
{
    if (replacement) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(replacement))[1])(replacement);
    if (*destination) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(*destination))[2])(*destination);
    *destination = replacement;
    return destination;
}

// MS2-FUNCTIONAL: releases and replaces a non-null interface slot without retaining the replacement.
// @0x140003ab0
void** FUN_140003ab0(void** destination, void* replacement)
{
    if (*destination) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(*destination))[2])(*destination);
    *destination = replacement;
    return destination;
}

// MS2-FUNCTIONAL: initializes the player, timing, pool, timeout, and notification defaults observed in the constructor.
// @0x1400033f0
void FUN_1400033f0(void* player)
{
    auto* bytes = static_cast<unsigned char*>(player);
    *reinterpret_cast<void**>(bytes + 0x48) = nullptr;
    memset(bytes + 0x50, 0, 0x50);
    *reinterpret_cast<float*>(bytes + 0xa8) = 1.0f / 12.0f;
    *reinterpret_cast<void**>(bytes + 0xb0) = nullptr;
    bytes[0xc0] = 0;
    *reinterpret_cast<unsigned*>(bytes + 0xc4) = 2;
    *reinterpret_cast<unsigned*>(bytes + 0xc8) = 0;
    *reinterpret_cast<float*>(bytes + 0xcc) = 0.8f;
    *reinterpret_cast<float*>(bytes + 0xd0) = 5.0f;
    *reinterpret_cast<unsigned*>(bytes + 0xd4) = 0;
    bytes[0xd8] = bytes[0xd9] = bytes[0xda] = 0;
    bytes[0xdb] = 1;
    bytes[0xdc] = 0;
    *reinterpret_cast<void**>(bytes + 0xe0) = nullptr;
    *reinterpret_cast<void**>(bytes + 0xe8) = nullptr;
}

// MS2-FUNCTIONAL: creates a managed AS2 string and stores its retained node in the return object.
// @0x140003000
Scaleform::GFx::ASString* FUN_140003000(Scaleform::GFx::ASStringManager* manager,
                                         Scaleform::GFx::ASString* result, const char* text)
{
    *result = manager->CreateString(text, strlen(text));
    return result;
}

// MS2-FUNCTIONAL: creates a constant AS2 string node over the supplied terminated text.
// @0x140003020
Scaleform::GFx::ASString* FUN_140003020(Scaleform::GFx::ASStringManager* manager,
                                         Scaleform::GFx::ASString* result, const char* text)
{
    *result = manager->CreateConstString(text);
    return result;
}

// MS2-FUNCTIONAL: creates an owned AS2 string from the context's movie string manager.
// @0x1400038f0
Scaleform::GFx::ASString* FUN_1400038f0(Scaleform::GFx::AS2::Environment* environment,
                                         Scaleform::GFx::ASString* result, const char* text)
{
    *result = environment->CreateConstString(text);
    return result;
}

// MS2-FUNCTIONAL: creates an owned AS2 string from the context's movie string manager.
// @0x140003940
Scaleform::GFx::ASString* FUN_140003940(Scaleform::GFx::AS2::Environment* environment,
                                         Scaleform::GFx::ASString* result, const char* text)
{
    *result = environment->CreateString(text);
    return result;
}

// MS2-FUNCTIONAL: looks up the selected movie string manager for a built-in table index.
// @0x1400043e0
Scaleform::GFx::ASStringNodeHolder* FUN_1400043e0(Scaleform::GFx::AS2::Environment* environment, int index)
{
    auto* context = *reinterpret_cast<Scaleform::GFx::AS2::GlobalContext**>(
        reinterpret_cast<unsigned char*>(environment) + 0xe8);
    return &context->GetStringManager()->Builtins[index];
}

// MS2-FUNCTIONAL: selects a built-in string manager within the environment's global context.
// @0x1400044e0
Scaleform::GFx::ASStringNodeHolder* FUN_1400044e0(Scaleform::GFx::AS2::GlobalContext** context, int index)
{
    return &(*context)->GetStringManager()->Builtins[index];
}

// MS2-FUNCTIONAL: creates an owned AS2 string through the selected movie string manager.
// @0x140004400
Scaleform::GFx::ASString* FUN_140004400(Scaleform::GFx::AS2::Environment* environment,
                                         Scaleform::GFx::ASString* result, const char* text)
{
    *result = environment->CreateString(text);
    return result;
}

// MS2-FUNCTIONAL: creates a constant AS2 string through the selected movie string manager.
// @0x140004440
Scaleform::GFx::ASString* FUN_140004440(Scaleform::GFx::AS2::Environment* environment,
                                         Scaleform::GFx::ASString* result, const char* text)
{
    *result = environment->CreateConstString(text);
    return result;
}

// MS2-FUNCTIONAL: creates a constant AS2 string through the global context's movie string manager.
// @0x140004500
Scaleform::GFx::ASString* FUN_140004500(Scaleform::GFx::AS2::GlobalContext** context,
                                         Scaleform::GFx::ASString* result, const char* text)
{
    auto* strings = (*context)->GetStringManager();
    *result = strings->CreateConstString(text);
    return result;
}

// MS2-FUNCTIONAL: releases the weak reference proxy held by this slot.
// @0x140003b20
void FUN_140003b20(void** proxy) { if (*proxy) FUN_14257dcd0(*proxy); }

// MS2-FUNCTIONAL: replaces the weak reference proxy after releasing its prior proxy.
// @0x140003b40
void** FUN_140003b40(void** proxy, void* replacement)
{
    if (*proxy) FUN_14257dcd0(*proxy);
    *proxy = replacement;
    return proxy;
}

// MS2-FUNCTIONAL: releases the weak reference proxy held by this slot.
// @0x140003c00
void FUN_140003c00(void** proxy) { if (*proxy) FUN_14257dcd0(*proxy); }

// MS2-FUNCTIONAL: retains the replacement proxy before releasing the current proxy.
// @0x140003c20
void** FUN_140003c20(void** proxy, void* replacement)
{
    if (replacement) ++*reinterpret_cast<int*>(static_cast<unsigned char*>(replacement) + 8);
    if (*proxy) FUN_14257dcd0(*proxy);
    *proxy = replacement;
    return proxy;
}

// MS2-FUNCTIONAL: replaces the weak reference proxy after releasing its prior proxy.
// @0x140003c70
void** FUN_140003c70(void** proxy, void* replacement)
{
    if (*proxy) FUN_14257dcd0(*proxy);
    *proxy = replacement;
    return proxy;
}

// MS2-FUNCTIONAL: releases a weak reference proxy when the slot is populated.
// @0x140003d10
void FUN_140003d10(void** proxy) { if (*proxy) FUN_14257dcd0(*proxy); }
// MS2-FUNCTIONAL: releases a weak reference proxy when the slot is populated.
// @0x140003da0
void FUN_140003da0(void** proxy) { if (*proxy) FUN_14257dcd0(*proxy); }

// MS2-FUNCTIONAL: creates and retains a display object's character handle on first use.
// @0x140004310
void FUN_140004310(void* object)
{
    if (!*reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x70)) FUN_1425f1910(object);
}

// MS2-FUNCTIONAL: retrieves the display object's character type into the caller's output slot.
// @0x140004330
void** FUN_140004330(void** character, void** result)
{
    *result = reinterpret_cast<void* (*)(void*, unsigned)>((*reinterpret_cast<void***>(character))[3])(character, 0x1e);
    return result;
}

// MS2-FUNCTIONAL: retrieves the display object's subtype into the caller's output slot.
// @0x140004350
void** FUN_140004350(void** character, void** result)
{
    *result = reinterpret_cast<void* (*)(void*, unsigned)>((*reinterpret_cast<void***>(character))[3])(character, 0xb);
    return result;
}

// MS2-FUNCTIONAL: forwards the action to refresh the active player implementation.
// @0x140004600
void FUN_140004600(void* object)
{
    auto* owner = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x68);
    void* impl = *reinterpret_cast<void**>(owner + 0x48);
    if (impl) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(impl))[14])(impl);
}

// MS2-FUNCTIONAL: stores the reload-threshold value and forwards it to the active player.
// @0x140004650
void FUN_140004650(void* object, double threshold)
{
    auto* owner = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x68);
    void* impl = *reinterpret_cast<void**>(owner + 0x48);
    *reinterpret_cast<float*>(owner + 0xc8) = static_cast<float>(threshold);
    if (impl) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(impl))[22])(impl);
}

// MS2-FUNCTIONAL: updates the frame-pool count on the NetStream's player and forwards the new value.
// @0x140004680
void FUN_140004680(void* object, double count)
{
    auto* owner = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x68);
    void* impl = *reinterpret_cast<void**>(owner + 0x48);
    *reinterpret_cast<int*>(owner + 0xc4) = static_cast<int>(count);
    if (impl) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(impl))[23])(impl);
}

// MS2-FUNCTIONAL: updates buffer time on the NetStream's player and forwards it.
// @0x1400046b0
void FUN_1400046b0(void* object, double time)
{
    auto* owner = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x68);
    void* impl = *reinterpret_cast<void**>(owner + 0x48);
    *reinterpret_cast<float*>(owner + 0xcc) = static_cast<float>(time);
    if (impl) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(impl))[24])(impl);
}

// MS2-FUNCTIONAL: updates the open timeout on the NetStream's player and forwards it.
// @0x1400046e0
void FUN_1400046e0(void* object, double timeout)
{
    auto* owner = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x68);
    void* impl = *reinterpret_cast<void**>(owner + 0x48);
    *reinterpret_cast<float*>(owner + 0xd0) = static_cast<float>(timeout);
    if (impl) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(impl))[26])(impl);
}

// MS2-FUNCTIONAL: forwards a seek position to the active player implementation.
// @0x140004710
void FUN_140004710(void* object, double position)
{
    auto* owner = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x68);
    void* impl = *reinterpret_cast<void**>(owner + 0x48);
    if (impl) reinterpret_cast<void (*)(void*, int)>((*reinterpret_cast<void***>(impl))[7])(impl, static_cast<int>(position));
}

// MS2-FUNCTIONAL: forwards the video-info request to the active player with the stored output buffer.
// @0x140004770
void FUN_140004770(void* object)
{
    auto* owner = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x68);
    void* impl = *reinterpret_cast<void**>(owner + 0x48);
    if (impl) reinterpret_cast<void (*)(void*, void*)>((*reinterpret_cast<void***>(impl))[28])(impl, owner + 0xf0);
}

// MS2-FUNCTIONAL: builds the three-field URL location value using owned copies of the two strings.
// @0x140004290
Scaleform::GFx::URLBuilder::LocationInfo* FUN_140004290(
    Scaleform::GFx::URLBuilder::LocationInfo* location, Scaleform::GFx::URLBuilder::FileUse use,
    const Scaleform::String& filename, const Scaleform::String& parentPath)
{
    location->Use = use;
    new (&location->FileName) Scaleform::String(filename);
    new (&location->ParentPath) Scaleform::String(parentPath);
    return location;
}

// MS2-FUNCTIONAL: destroys a character handle and frees its allocation when requested.
// @0x1400042d0
Scaleform::GFx::CharacterHandle* FUN_1400042d0(Scaleform::GFx::CharacterHandle* handle, unsigned flags)
{
    handle->~CharacterHandle();
    if (flags & 1) Scaleform::Memory::Free(handle);
    return handle;
}

// MS2-FUNCTIONAL: destroys the FnCall logging frame and frees its allocation when requested.
// @0x1400043b0
Scaleform::GFx::AS2::FnCall* FUN_1400043b0(Scaleform::GFx::AS2::FnCall* call, unsigned flags)
{
    call->~FnCall();
    if (flags & 1) operator delete(call);
    return call;
}

// MS2-FUNCTIONAL: releases the owned proxy at this weak-pointer slot when present.
// @0x1400045c0
void** FUN_1400045c0(void** proxy, unsigned flags)
{
    if (*proxy) FUN_14257dcd0(*proxy);
    if (flags & 1) operator delete(proxy);
    return proxy;
}

// MS2-FUNCTIONAL: releases a non-null intrusive reference stored in the slot.
// @0x140004dd0
void FUN_140004dd0(void** value) { if (*value) FUN_14257dcb0(*value); }

// MS2-FUNCTIONAL: frees the object held by the first pointer slot when non-null.
// @0x140004e50
void FUN_140004e50(void** value) { if (*value) Scaleform::Memory::Free(*value); }

// MS2-FUNCTIONAL: frees the object held by the first pointer slot when non-null.
// @0x140004e90
void FUN_140004e90(void** value) { if (*value) Scaleform::Memory::Free(*value); }

// MS2-FUNCTIONAL: obtains the live object behind a weak proxy, clearing an expired proxy slot.
// @0x140005000
void* FUN_140005000(void** weakSlot)
{
    auto* proxy = static_cast<unsigned char*>(*weakSlot);
    if (!proxy) return nullptr;
    void* target = *reinterpret_cast<void**>(proxy + 8);
    if (!target) {
        FUN_14257dcd0(proxy);
        *weakSlot = nullptr;
        return nullptr;
    }
    if (*reinterpret_cast<int*>(static_cast<unsigned char*>(target) + 8) != 0) return target;
    return nullptr;
}

// MS2-FUNCTIONAL: grows, resizes, or releases the four-byte-rounded backing array through the Scaleform heap.
// @0x1400050c0
void FUN_1400050c0(void** array, void* heapOwner, Scaleform::UPInt requested)
{
    auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
    auto* data = static_cast<unsigned char*>(array[0]);
    if (requested == 0) {
        if (data) reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, data);
        array[0] = nullptr;
        array[2] = nullptr;
        return;
    }
    const Scaleform::UPInt capacity = (requested + 3) & ~Scaleform::UPInt(3);
    if (data) {
        array[0] = reinterpret_cast<void* (*)(void*, void*, size_t)>(heapVtable[11])(
            DAT_143b15f60, data, capacity * sizeof(void*));
    } else {
        alignas(8) unsigned flags[2] = { 2, 0 };
        array[0] = reinterpret_cast<void* (*)(void*, void*, size_t, const void*)>(heapVtable[14])(
            DAT_143b15f60, heapOwner, capacity * sizeof(void*), flags);
    }
    array[2] = reinterpret_cast<void*>(capacity);
}

// MS2-FUNCTIONAL: adjusts the backing capacity with the observed quarter-growth and half-shrink thresholds.
// @0x140005160
void FUN_140005160(void** array, void* heapOwner, Scaleform::UPInt size)
{
    const Scaleform::UPInt oldSize = reinterpret_cast<Scaleform::UPInt>(array[1]);
    const Scaleform::UPInt capacity = reinterpret_cast<Scaleform::UPInt>(array[2]);
    if (size < oldSize) {
        if (size < (capacity >> 1)) FUN_1400050c0(array, heapOwner, size);
    } else if (capacity <= size) {
        FUN_1400050c0(array, heapOwner, size + (size >> 2));
    }
    array[1] = reinterpret_cast<void*>(size);
}

// MS2-FUNCTIONAL: resizes the array of 16-byte records with four-element capacity rounding.
// @0x1400051c0
void FUN_1400051c0(void** array, void*, Scaleform::UPInt requested)
{
    auto** vtable = *reinterpret_cast<void***>(DAT_143b15f60);
    auto* data = array[0];
    if (!requested) {
        if (data) reinterpret_cast<void (*)(void*, void*)>(vtable[12])(DAT_143b15f60, data);
        array[0] = nullptr; array[2] = nullptr; return;
    }
    const auto capacity = (requested + 3) & ~Scaleform::UPInt(3);
    if (data) array[0] = reinterpret_cast<void* (*)(void*, void*, size_t)>(vtable[11])(
        DAT_143b15f60, data, capacity * 16);
    else {
        unsigned flags[2] = { 2, 0 };
        array[0] = reinterpret_cast<void* (*)(void*, size_t, const void*)>(vtable[10])(
            DAT_143b15f60, capacity * 16, flags);
    }
    array[2] = reinterpret_cast<void*>(capacity);
}

// MS2-FUNCTIONAL: resizes the array of 12-byte records with four-element capacity rounding.
// @0x140005260
void FUN_140005260(void** array, void*, Scaleform::UPInt requested)
{
    auto** vtable = *reinterpret_cast<void***>(DAT_143b15f60);
    auto* data = array[0];
    if (!requested) {
        if (data) reinterpret_cast<void (*)(void*, void*)>(vtable[12])(DAT_143b15f60, data);
        array[0] = nullptr; array[2] = nullptr; return;
    }
    const auto capacity = (requested + 3) & ~Scaleform::UPInt(3);
    if (data) array[0] = reinterpret_cast<void* (*)(void*, void*, size_t)>(vtable[11])(
        DAT_143b15f60, data, capacity * 12);
    else {
        unsigned flags[2] = { 2, 0 };
        array[0] = reinterpret_cast<void* (*)(void*, size_t, const void*)>(vtable[10])(
            DAT_143b15f60, capacity * 12, flags);
    }
    array[2] = reinterpret_cast<void*>(capacity);
}

// MS2-FUNCTIONAL: releases a character handle when its intrusive reference count reaches zero.
// @0x140005480
void FUN_140005480(Scaleform::GFx::CharacterHandle* handle)
{
    if (--*reinterpret_cast<int*>(handle) < 1) {
        handle->~CharacterHandle();
        Scaleform::Memory::Free(handle);
    }
}

// MS2-FUNCTIONAL: releases a retained object pointer when the slot is populated.
// @0x140005660
void FUN_140005660(void** value) { if (*value) FUN_14257dcb0(*value); }

// MS2-FUNCTIONAL: clears the provider's pending notification and requests the active player to stop.
// @0x140005690
void FUN_140005690(void* stream)
{
    auto* provider = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(stream) + 0x68);
    if (provider) {
        *reinterpret_cast<void**>(provider + 0x18) = nullptr;
        void* player = *reinterpret_cast<void**>(provider + 0x48);
        if (player) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(player))[14])(player);
    }
}

// MS2-FUNCTIONAL: releases the owned player-side allocation.
// @0x140005760
void FUN_140005760(void** value) { if (*value) Scaleform::Memory::Free(*value); }

// MS2-FUNCTIONAL: releases the owned player-side allocation.
// @0x140005830
void FUN_140005830(void** value) { if (*value) Scaleform::Memory::Free(*value); }

// MS2-FUNCTIONAL: releases the owned intrusive reference stored in the slot.
// @0x140005870
void FUN_140005870(void** value) { if (*value) FUN_14257dcb0(*value); }

// MS2-FUNCTIONAL: destroys a weak-support object and conditionally frees its storage.
// @0x1400058c0
Scaleform::RefCountWeakSupportImpl* FUN_1400058c0(Scaleform::RefCountWeakSupportImpl* value, unsigned flags)
{
    value->~RefCountWeakSupportImpl();
    if (flags & 1) Scaleform::Memory::Free(value);
    return value;
}

// MS2-FUNCTIONAL: decrements a character-handle reference and destroys it at zero.
// @0x140005900
void FUN_140005900(Scaleform::GFx::CharacterHandle** value)
{
    if (*value && --*reinterpret_cast<int*>(*value) < 1) {
        (*value)->~CharacterHandle();
        Scaleform::Memory::Free(*value);
    }
}

// MS2-FUNCTIONAL: retains the replacement character handle before releasing the previous one.
// @0x140005940
void** FUN_140005940(void** destination, Scaleform::GFx::CharacterHandle* replacement)
{
    if (replacement) ++*reinterpret_cast<int*>(replacement);
    auto* old = static_cast<Scaleform::GFx::CharacterHandle*>(*destination);
    if (old && --*reinterpret_cast<int*>(old) < 1) {
        old->~CharacterHandle();
        Scaleform::Memory::Free(old);
    }
    *destination = replacement;
    return destination;
}

// MS2-FUNCTIONAL: locks a weak proxy into a retained strong object reference.
// @0x1400059b0
void** FUN_1400059b0(void** weakSlot, void** result)
{
    *result = nullptr;
    auto* proxy = static_cast<unsigned char*>(*weakSlot);
    if (!proxy) return result;
    void* target = *reinterpret_cast<void**>(proxy + 8);
    if (!target) {
        FUN_14257dcd0(proxy);
        *weakSlot = nullptr;
    } else if (*reinterpret_cast<int*>(static_cast<unsigned char*>(target) + 8) != 0) {
        ++*reinterpret_cast<int*>(static_cast<unsigned char*>(target) + 8);
        *result = target;
    }
    return result;
}

// MS2-FUNCTIONAL: releases the weak proxy and optionally frees the wrapper object.
// @0x140005a70
void** FUN_140005a70(void** weakSlot, unsigned flags)
{
    if (*weakSlot) FUN_14257dcd0(*weakSlot);
    if (flags & 1) operator delete(weakSlot);
    return weakSlot;
}

// MS2-FUNCTIONAL: appends one pointer value to the backing array, growing capacity when needed.
// @0x140005ac0
void FUN_140005ac0(void** array, const void** value)
{
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    const Scaleform::UPInt newSize = fields[1] + 1;
    if (newSize >= fields[2]) FUN_1400050c0(array, array, newSize + (newSize >> 2));
    fields[1] = newSize;
    *reinterpret_cast<const void**>(static_cast<unsigned char*>(*array) + newSize * sizeof(void*) - sizeof(void*)) = *value;
}

// MS2-FUNCTIONAL: adjusts the 16-byte record array using its quarter-growth and half-shrink thresholds.
// @0x140005b40
void FUN_140005b40(void** array, void* owner, Scaleform::UPInt size)
{
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    const auto oldSize = fields[1], capacity = fields[2];
    if (size < oldSize) { if (size < capacity / 2) FUN_1400051c0(array, owner, size); }
    else if (capacity <= size) FUN_1400051c0(array, owner, size + (size >> 2));
    fields[1] = size;
}

// MS2-FUNCTIONAL: adjusts the 12-byte record array using its quarter-growth and half-shrink thresholds.
// @0x140005ba0
void FUN_140005ba0(void** array, void* owner, Scaleform::UPInt size)
{
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    const auto oldSize = fields[1], capacity = fields[2];
    if (size < oldSize) { if (size < capacity / 2) FUN_140005260(array, owner, size); }
    else if (capacity <= size) FUN_140005260(array, owner, size + (size >> 2));
    fields[1] = size;
}

// MS2-FUNCTIONAL: adjusts the pointer array capacity using four-element rounding and the observed thresholds.
// @0x140005c20
void FUN_140005c20(void** array, Scaleform::UPInt size)
{
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    const auto oldSize = fields[1], capacity = fields[2];
    if (size < oldSize) { if (size < capacity / 2) FUN_1400050c0(array, array, size); }
    else if (capacity <= size) FUN_1400050c0(array, array, size + (size >> 2));
    fields[1] = size;
}

// MS2-FUNCTIONAL: resizes the 12-byte record array and clears each newly exposed record.
// @0x140005ca0
void FUN_140005ca0(void** array, Scaleform::UPInt size)
{
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    const auto oldSize = fields[1], capacity = fields[2];
    if (size < oldSize) { if (size < capacity / 2) FUN_140005260(array, array, size); }
    else if (capacity <= size) FUN_140005260(array, array, size + (size >> 2));
    fields[1] = size;
    if (oldSize < size && *array)
        memset(static_cast<unsigned char*>(*array) + oldSize * 12, 0, (size - oldSize) * 12);
}

// MS2-FUNCTIONAL: releases the stored allocation through Scaleform's global heap.
// @0x140005f60
void FUN_140005f60(void** allocation) { if (*allocation) Scaleform::Memory::Free(*allocation); }

// MS2-FUNCTIONAL: releases the stored allocation through Scaleform's global heap.
// @0x140005fa0
void FUN_140005fa0(void** allocation) { if (*allocation) Scaleform::Memory::Free(*allocation); }

// MS2-FUNCTIONAL: releases the two tagged weak-proxy references, then optionally frees the pair.
// @0x140005d30
void* FUN_140005d30(Scaleform::UPInt* pair, unsigned flags)
{
    auto* second = reinterpret_cast<Scaleform::WeakPtrProxy*>(pair[1] & ~Scaleform::UPInt(3));
    auto* first = reinterpret_cast<Scaleform::WeakPtrProxy*>(pair[0] & ~Scaleform::UPInt(3));
    if (second) second->Release();
    if (first) first->Release();
    if (flags & 1) ::operator delete(pair);
    return pair;
}

// MS2-FUNCTIONAL: releases the two tagged weak-proxy references held by this pair.
// @0x140005df0
void FUN_140005df0(Scaleform::UPInt* pair)
{
    auto* second = reinterpret_cast<Scaleform::WeakPtrProxy*>(pair[1] & ~Scaleform::UPInt(3));
    auto* first = reinterpret_cast<Scaleform::WeakPtrProxy*>(pair[0] & ~Scaleform::UPInt(3));
    if (second) second->Release();
    if (first) first->Release();
}

// MS2-FUNCTIONAL: copies both shared string members when a destination pair is supplied.
// @0x140005db0
void FUN_140005db0(Scaleform::String* destination, const Scaleform::String* source)
{
    if (destination) {
        new (destination) Scaleform::String(source[0]);
        new (destination + 1) Scaleform::String(source[1]);
    }
}

// MS2-FUNCTIONAL: initializes a FunctionRefBase from the source, including its frame ownership mode.
// @0x140005f00
Scaleform::GFx::AS2::FunctionRefBase* FUN_140005f00(
    Scaleform::GFx::AS2::FunctionRefBase* destination,
    const Scaleform::GFx::AS2::FunctionRefBase* source)
{
    destination->Function = source->Function;
    destination->Flags = 0;
    if (destination->Function) destination->Function->AddRef();
    destination->pLocalFrame = nullptr;
    if (source->pLocalFrame)
        destination->SetLocalFrame(source->pLocalFrame, (source->Flags & 1) != 0);
    return destination;
}

// MS2-FUNCTIONAL: releases the retained weak proxy in the owning SyncObject field.
// @0x1400061f0
void FUN_1400061f0(void** proxy)
{
    if (*proxy) FUN_14257dcd0(*proxy);
}

// MS2-FUNCTIONAL: resolves a weak proxy and clears the slot after the target has died.
// @0x140006240
void* FUN_140006240(void** weakSlot)
{
    auto* proxy = reinterpret_cast<Scaleform::WeakPtrProxy*>(
        reinterpret_cast<Scaleform::UPInt>(*weakSlot) & ~Scaleform::UPInt(3));
    if (!proxy) return nullptr;
    auto* object = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(proxy) + 8);
    if (object) return object;
    proxy->Release();
    *weakSlot = nullptr;
    return nullptr;
}

// MS2-FUNCTIONAL: runs the Scaleform base destructor and conditionally releases the allocation.
// @0x140002a60
void* FUN_140002a60(void* object, unsigned flags)
{
    FUN_14257db50(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: runs the shared base destructor and conditionally releases the allocation.
// @0x140002b30
void* FUN_140002b30(void* object, unsigned flags)
{
    FUN_14257db50(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: runs the ref-counted base destructor and conditionally releases the allocation.
// @0x140002bb0
void* FUN_140002bb0(void* object, unsigned flags)
{
    FUN_14257db40(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: tears down the sound stream's channel link before its base object.
// @0x140002c10
void* FUN_140002c10(void* object, unsigned flags)
{
    auto** fields = static_cast<void**>(object);
    auto* channel = fields[2];
    if (channel) *reinterpret_cast<void**>(static_cast<unsigned char*>(channel) + 0x10) = nullptr;
    if (channel) FUN_14257dcb0(channel);
    FUN_14257db50(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: runs the common ref-counted base destructor and optional allocation release.
// @0x140002cc0
void* FUN_140002cc0(void* object, unsigned flags)
{
    FUN_14257db40(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: runs the common ref-counted base destructor and optional allocation release.
// @0x140002d20
void* FUN_140002d20(void* object, unsigned flags)
{
    FUN_14257db40(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: runs the common ref-counted base destructor and optional allocation release.
// @0x140002e40
void* FUN_140002e40(void* object, unsigned flags)
{
    FUN_14257db40(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: releases the retained interface in this slot.
// @0x140003a50
void FUN_140003a50(void** interfaceSlot)
{
    if (*interfaceSlot)
        reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(*interfaceSlot))[2])(*interfaceSlot);
}

// MS2-FUNCTIONAL: releases the tagged proxy pair in reverse field order.
// @0x140004b00
void FUN_140004b00(Scaleform::UPInt* pair)
{
    auto* second = reinterpret_cast<Scaleform::WeakPtrProxy*>(pair[2] & ~Scaleform::UPInt(3));
    auto* first = reinterpret_cast<Scaleform::WeakPtrProxy*>(pair[1] & ~Scaleform::UPInt(3));
    if (second) second->Release();
    if (first) first->Release();
}

// MS2-FUNCTIONAL: destroys the base object and releases its allocation when requested.
// @0x140003df0
void* FUN_140003df0(void* object, unsigned flags)
{
    FUN_1429260b0(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: destroys weak-reference support state and optionally frees the object.
// @0x140004fb0
void* FUN_140004fb0(Scaleform::RefCountWeakSupportImpl* object, unsigned flags)
{
    object->~RefCountWeakSupportImpl();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: releases the two weak-proxy references stored in this small pair.
// @0x140005300
void FUN_140005300(Scaleform::UPInt* pair)
{
    auto* second = reinterpret_cast<Scaleform::WeakPtrProxy*>(pair[1] & ~Scaleform::UPInt(3));
    auto* first = reinterpret_cast<Scaleform::WeakPtrProxy*>(pair[0] & ~Scaleform::UPInt(3));
    if (second) second->Release();
    if (first) first->Release();
}

// MS2-FUNCTIONAL: tears down weak-reference support state and optionally frees its allocation.
// @0x140005430
void* FUN_140005430(Scaleform::RefCountWeakSupportImpl* object, unsigned flags)
{
    object->~RefCountWeakSupportImpl();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: releases the base object's shared state and optionally its storage.
// @0x140004f30
void* FUN_140004f30(void* object, unsigned flags)
{
    FUN_14257db50(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: releases the base object's shared state and optionally its storage.
// @0x140005610
void* FUN_140005610(void* object, unsigned flags)
{
    FUN_14257db50(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: constructs the function and local-frame references from the supplied fields.
// @0x140005590
Scaleform::GFx::AS2::FunctionRefBase* FUN_140005590(
    Scaleform::GFx::AS2::FunctionRefBase* destination,
    const Scaleform::GFx::AS2::FunctionRefBase* source, unsigned char flags)
{
    destination->Flags = flags;
    destination->Function = source->Function;
    if (destination->Function && !(flags & Scaleform::GFx::AS2::FunctionRefBase::FuncRef_Internal))
        destination->Function->AddRef();
    destination->pLocalFrame = nullptr;
    if (source->pLocalFrame)
        destination->SetLocalFrame(source->pLocalFrame, (source->Flags & 1) != 0);
    return destination;
}

// MS2-FUNCTIONAL: releases the single allocation held by this stack or page descriptor.
// @0x140006bb0
void FUN_140006bb0(void** allocation) { if (*allocation) Scaleform::Memory::Free(*allocation); }

// MS2-FUNCTIONAL: releases the single allocation held by this stack or page descriptor.
// @0x140006bd0
void FUN_140006bd0(void** allocation) { if (*allocation) Scaleform::Memory::Free(*allocation); }

// MS2-FUNCTIONAL: releases each retained object in the pointer array and then the array allocation.
// @0x140006c70
void FUN_140006c70(void** array)
{
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    auto** items = static_cast<void**>(*array);
    for (Scaleform::UPInt i = fields[1]; i != 0; --i) {
        void* object = items[i - 1];
        if (object) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(object))[2])(object);
    }
    if (*array) Scaleform::Memory::Free(*array);
}

// MS2-FUNCTIONAL: resizes and copies the 12-byte records from the source array.
// @0x140006db0
void* FUN_140006db0(void** destination, const void** source)
{
    FUN_140005ca0(destination, reinterpret_cast<const Scaleform::UPInt*>(source)[1]);
    auto count = reinterpret_cast<const Scaleform::UPInt*>(destination)[1];
    if (*destination && count)
        memcpy(*destination, *source, count * 12);
    return destination;
}

// MS2-FUNCTIONAL: releases both weak-proxy references held by each 16-byte record.
// @0x1400068d0
void FUN_1400068d0(void* records, Scaleform::UPInt count)
{
    auto* pair = reinterpret_cast<Scaleform::UPInt*>(records);
    for (Scaleform::UPInt i = 0; i < count; ++i, pair += 2) {
        auto* second = reinterpret_cast<Scaleform::WeakPtrProxy*>(pair[1] & ~Scaleform::UPInt(3));
        auto* first = reinterpret_cast<Scaleform::WeakPtrProxy*>(pair[0] & ~Scaleform::UPInt(3));
        if (second) second->Release();
        if (first) first->Release();
    }
}

// MS2-FUNCTIONAL: destroys every weak pair in the storage and releases the array allocation.
// @0x140006e20
void FUN_140006e20(void** array)
{
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    if (fields[1]) FUN_1400068d0(*array, fields[1]);
    if (*array) Scaleform::Memory::Free(*array);
}

// MS2-FUNCTIONAL: copies the two shared strings in each 16-byte hash record.
// @0x140006940
void FUN_140006940(Scaleform::String* destination, Scaleform::UPInt count,
                   const Scaleform::String* source)
{
    for (Scaleform::UPInt i = 0; i < count; ++i) {
        new (destination + i * 2) Scaleform::String(source[i * 2]);
        new (destination + i * 2 + 1) Scaleform::String(source[i * 2 + 1]);
    }
}

// MS2-FUNCTIONAL: grows or shrinks the pointer array using the observed quarter-capacity policy.
// @0x140006810
void FUN_140006810(void** array, void* owner, Scaleform::UPInt capacity)
{
    FUN_1400050c0(array, owner, capacity);
}

// MS2-FUNCTIONAL: reallocates storage for 16-byte records with four-element capacity rounding.
// @0x1400069a0
void FUN_1400069a0(void** array, void* owner, Scaleform::UPInt capacity)
{
    FUN_1400051c0(array, owner, capacity);
}

// MS2-FUNCTIONAL: clears this array descriptor, releasing its buffer when it is dynamically sized.
// @0x140006bf0
void FUN_140006bf0(void** array)
{
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    if (fields[1] == 0) {
        if (fields[2] == 0) FUN_1400051c0(array, array, 0);
        fields[1] = 0;
        return;
    }
    if ((fields[2] & ~Scaleform::UPInt(1)) != 0) {
        if (*array) Scaleform::Memory::Free(*array);
        *array = nullptr;
        fields[2] = 0;
        fields[1] = 0;
        return;
    }
    fields[1] = 0;
}

// MS2-FUNCTIONAL: obtains a 0x400-byte value page, records it, and updates the current stack cursors.
// @0x140006a40
void FUN_140006a40(Scaleform::UPInt* stack)
{
    auto** freePage = reinterpret_cast<void**>(stack[7]);
    void* page = nullptr;
    if (freePage) {
        page = freePage;
        stack[7] = *reinterpret_cast<Scaleform::UPInt*>(static_cast<unsigned char*>(page) + 0x400);
    } else {
        auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
        page = reinterpret_cast<void* (*)(void*, void*, Scaleform::UPInt, unsigned)>(heapVtable[14])(
            DAT_143b15f60, stack, 0x408, 0);
    }
    if (!page) { stack[0] -= 0x20; return; }
    auto* pages = reinterpret_cast<void**>(stack + 4);
    auto size = stack[5] + 1;
    if (size >= stack[6]) FUN_1400050c0(reinterpret_cast<void**>(stack + 4), stack + 4, size + (size >> 2));
    stack[5] = size;
    pages[size - 1] = page;
    stack[1] = reinterpret_cast<Scaleform::UPInt>(page);
    stack[0] = stack[1];
    stack[3] = stack[2] - 0x20;
    stack[2] = stack[1] + 0x400;
}

// MS2-FUNCTIONAL: returns the last page to the free list and restores the preceding stack page.
// @0x140006cf0
void FUN_140006cf0(Scaleform::UPInt* stack)
{
    if (stack[5] < 2) {
        stack[0] += 0x20;
        if (stack[0]) *reinterpret_cast<unsigned char*>(stack[0]) = 0;
        return;
    }
    auto** pages = reinterpret_cast<void**>(stack + 4);
    void* page = pages[stack[5] - 1];
    *reinterpret_cast<Scaleform::UPInt*>(static_cast<unsigned char*>(page) + 0x400) = stack[7];
    stack[7] = reinterpret_cast<Scaleform::UPInt>(page);
    FUN_140005c20(reinterpret_cast<void**>(stack + 4), stack[5] - 1);
    page = pages[stack[5] - 1];
    stack[1] = reinterpret_cast<Scaleform::UPInt>(page);
    stack[2] = stack[1] + 0x400;
    stack[0] = stack[1] + 0x3e0;
    stack[3] = stack[5] < 2 ? stack[1] :
        reinterpret_cast<Scaleform::UPInt>(pages[stack[5] - 2]) + 0x3e0;
}

// MS2-FUNCTIONAL: removes retained elements beyond the new size and adjusts pointer capacity.
// @0x140006e70
void FUN_140006e70(void** array, void* owner, Scaleform::UPInt size)
{
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    if (size < fields[1]) {
        auto** items = static_cast<void**>(*array);
        for (Scaleform::UPInt i = fields[1]; i > size; --i)
            if (items[i - 1]) FUN_14257dcb0(items[i - 1]);
        if (size < fields[2] / 2) FUN_140006810(array, owner, size);
    } else if (size >= fields[2]) {
        FUN_140006810(array, owner, size + (size >> 2));
    }
    fields[1] = size;
}

// MS2-FUNCTIONAL: shrinks or grows an array of two-string records, releasing truncated strings.
// @0x140006f50
void FUN_140006f50(void** array, void* owner, Scaleform::UPInt size)
{
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    if (size < fields[1]) {
        auto* records = static_cast<Scaleform::String*>(*array);
        for (Scaleform::UPInt i = size; i < fields[1]; ++i) {
            records[i * 2].~String();
            records[i * 2 + 1].~String();
        }
        if (size < fields[2] / 2) FUN_1400069a0(array, owner, size);
    } else if (size >= fields[2]) {
        FUN_1400069a0(array, owner, size + (size >> 2));
    }
    fields[1] = size;
}

// MS2-FUNCTIONAL: appends an object value to the current paged stack block.
// @0x140006ff0
void FUN_140006ff0(Scaleform::UPInt* stack, Scaleform::GFx::AS2::Object** value)
{
    *stack += 0x20;
    if (stack[2] <= *stack) FUN_140006a40(reinterpret_cast<Scaleform::UPInt*>(stack));
    if (*stack) ::new (reinterpret_cast<void*>(*stack)) Scaleform::GFx::AS2::Value(*value);
}

// MS2-FUNCTIONAL: appends a retained object value to the current paged stack block.
// @0x140007030
void FUN_140007030(Scaleform::UPInt* stack, Scaleform::GFx::AS2::Object** value)
{
    *stack += 0x20;
    if (stack[2] <= *stack) FUN_140006a40(reinterpret_cast<Scaleform::UPInt*>(stack));
    if (*stack) {
        auto* bytes = reinterpret_cast<unsigned char*>(*stack);
        bytes[0] = 5;
        auto* object = *value;
        *reinterpret_cast<Scaleform::GFx::AS2::Object**>(bytes + 8) = object;
        if (object) object->AddRef();
    }
}

// MS2-FUNCTIONAL: assigns the source 12-byte record array into the destination descriptor.
// @0x140007230
void* FUN_140007230(void** destination, const void** source)
{
    return FUN_140006db0(destination, source);
}

// MS2-FUNCTIONAL: appends and retains one object in the pointer array.
// @0x140007270
void FUN_140007270(void** array, void** value)
{
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    FUN_140006e70(array, array, fields[1] + 1);
    auto** slot = static_cast<void**>(*array) + fields[1] - 1;
    if (*value) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(*value))[1])(*value);
    *slot = *value;
}

// MS2-FUNCTIONAL: destroys weak-pair records and releases their backing allocation.
// @0x1400072c0
void FUN_1400072c0(void** array)
{
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    if (*array) FUN_1400068d0(*array, fields[1]);
    if (*array) Scaleform::Memory::Free(*array);
}

// MS2-FUNCTIONAL: removes the last stack value and returns its page when it becomes empty.
// @0x140007200
void FUN_140007200(Scaleform::UPInt* stack)
{
    FUN_1429260b0(reinterpret_cast<void*>(*stack));
    *stack -= 0x20;
    if (*stack < stack[1]) FUN_140006cf0(stack);
}

// MS2-FUNCTIONAL: resizes the retained pointer array and initializes newly added slots to null.
// @0x1400072f0
void FUN_1400072f0(void** array, Scaleform::UPInt size)
{
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    const auto oldSize = fields[1];
    FUN_140006e70(array, array, size);
    if (oldSize < size && *array)
        memset(static_cast<unsigned char*>(*array) + oldSize * sizeof(void*), 0,
               (size - oldSize) * sizeof(void*));
}

// MS2-FUNCTIONAL: appends copies of a sequence of two-string records.
// @0x140007370
void FUN_140007370(void** array, const Scaleform::String* records, Scaleform::UPInt count)
{
    if (!count) return;
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    const auto oldSize = fields[1];
    FUN_140006f50(array, array, oldSize + count);
    auto* destination = static_cast<Scaleform::String*>(*array) + oldSize * 2;
    for (Scaleform::UPInt i = 0; i < count; ++i) {
        new (destination + i * 2) Scaleform::String(records[i * 2]);
        new (destination + i * 2 + 1) Scaleform::String(records[i * 2 + 1]);
    }
}

// MS2-FUNCTIONAL: appends an object value to the stack at the embedded current cursor.
// @0x140007400
void FUN_140007400(Scaleform::UPInt* owner, Scaleform::GFx::AS2::Object** value)
{
    FUN_140006ff0(owner + 1, value);
}

// MS2-FUNCTIONAL: appends a retained object value to the embedded current cursor.
// @0x140007450
void FUN_140007450(Scaleform::UPInt* owner, Scaleform::GFx::AS2::Object** value)
{
    FUN_140007030(owner + 1, value);
}

// MS2-FUNCTIONAL: removes the last value from the embedded paged stack.
// @0x140007510
void FUN_140007510(Scaleform::UPInt* owner)
{
    FUN_140007200(owner + 1);
}

// MS2-FUNCTIONAL: releases both owned AS2 references according to the weak/internal mode bits.
// @0x1400074a0
void FUN_1400074a0(Scaleform::UPInt* pair)
{
    auto* flags = reinterpret_cast<unsigned char*>(pair + 2);
    if (!(flags[0] & 2)) ReleaseAs2GCObject(reinterpret_cast<void*>(pair[0]));
    pair[0] = 0;
    if (!(flags[0] & 1)) ReleaseAs2GCObject(reinterpret_cast<void*>(pair[1]));
    pair[1] = 0;
}

// MS2-FUNCTIONAL: releases the owned AS2 object reference stored in the slot.
// @0x140007570
void FUN_140007570(void** slot) { ReleaseAs2GCObject(*slot); }

// MS2-FUNCTIONAL: retains the incoming AS2 object, releases the old value, and assigns it.
// @0x1400075a0
void** FUN_1400075a0(void** destination, void** source)
{
    if (*source) {
        auto* count = reinterpret_cast<unsigned*>(static_cast<unsigned char*>(*source) + 0x18);
        *count = (*count + 1) & 0x8fffffff;
    }
    ReleaseAs2GCObject(*destination);
    *destination = *source;
    return destination;
}

// MS2-FUNCTIONAL: releases the owned AS2 object reference in the slot.
// @0x1400076d0
void FUN_1400076d0(void** slot) { ReleaseAs2GCObject(*slot); }

// MS2-FUNCTIONAL: retains a replacement AS2 object and releases the previous reference.
// @0x140007700
void** FUN_140007700(void** destination, void* replacement)
{
    if (replacement) {
        auto* count = reinterpret_cast<unsigned*>(static_cast<unsigned char*>(replacement) + 0x18);
        *count = (*count + 1) & 0x8fffffff;
    }
    ReleaseAs2GCObject(*destination);
    *destination = replacement;
    return destination;
}

// MS2-FUNCTIONAL: overwrites the slot after releasing its previous AS2 reference.
// @0x140007760
void** FUN_140007760(void** destination, void* replacement)
{
    ReleaseAs2GCObject(*destination);
    *destination = replacement;
    return destination;
}

// MS2-FUNCTIONAL: releases the owned AS2 object reference in the slot.
// @0x1400077b0
void FUN_1400077b0(void** slot) { ReleaseAs2GCObject(*slot); }

// MS2-FUNCTIONAL: releases both references in the temporary AS2 value pair.
// @0x140007a40
void FUN_140007a40(Scaleform::UPInt* pair)
{
    auto* flags = reinterpret_cast<unsigned char*>(pair + 2);
    if (!(flags[0] & 2)) ReleaseAs2GCObject(reinterpret_cast<void*>(pair[0]));
    pair[0] = 0;
    if (!(flags[0] & 1)) ReleaseAs2GCObject(reinterpret_cast<void*>(pair[1]));
    pair[1] = 0;
}

// MS2-FUNCTIONAL: retains the replacement AS2 object and releases the old slot value.
// @0x140007600
void** FUN_140007600(void** destination, void* replacement)
{
    if (replacement) {
        auto* count = reinterpret_cast<unsigned*>(static_cast<unsigned char*>(replacement) + 0x18);
        *count = (*count + 1) & 0x8fffffff;
    }
    ReleaseAs2GCObject(*destination);
    *destination = replacement;
    return destination;
}

// MS2-FUNCTIONAL: appends an object pointer to the array and retains it.
// @0x140007680
void FUN_140007680(void** array, void** value)
{
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    FUN_140006e70(array, array, fields[1] + 1);
    auto** slot = static_cast<void**>(*array) + fields[1] - 1;
    if (*value) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(*value))[1])(*value);
    *slot = *value;
}

// MS2-FUNCTIONAL: releases all weak pairs in the backing array and then frees it.
// @0x1400077f0
void FUN_1400077f0(void** array)
{
    auto* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    if (*array) FUN_1400068d0(*array, fields[1]);
    if (*array) Scaleform::Memory::Free(*array);
}

// MS2-FUNCTIONAL: initializes an empty two-string record array and copies the supplied records.
// @0x140007840
void* FUN_140007840(void** destination, const void** source)
{
    destination[0] = destination[1] = destination[2] = nullptr;
    FUN_140007370(destination, static_cast<const Scaleform::String*>(*source),
                  reinterpret_cast<const Scaleform::UPInt*>(source)[1]);
    return destination;
}

// MS2-FUNCTIONAL: copies the type field and retains the AS2 object pointer in the source value.
// @0x140007870
void FUN_140007870(unsigned* destination, void** source)
{
    *destination = *static_cast<unsigned*>(*source);
    auto** sourceSlot = static_cast<void**>(source[1]);
    void* replacement = sourceSlot ? *sourceSlot : nullptr;
    if (replacement) {
        auto* count = reinterpret_cast<unsigned*>(static_cast<unsigned char*>(replacement) + 0x18);
        *count = (*count + 1) & 0x8fffffff;
    }
    ReleaseAs2GCObject(*reinterpret_cast<void**>(destination + 2));
    *reinterpret_cast<void**>(destination + 2) = replacement;
}

// MS2-FUNCTIONAL: releases the object reference in the second pointer-sized field.
// @0x1400078d0
void FUN_1400078d0(void** value)
{
    ReleaseAs2GCObject(value[1]);
}

// MS2-FUNCTIONAL: releases the second-field object reference and optionally deletes the wrapper.
// @0x140007960
void* FUN_140007960(void* value, unsigned flags)
{
    ReleaseAs2GCObject(*reinterpret_cast<void**>(static_cast<unsigned char*>(value) + 8));
    if (flags & 1) ::operator delete(value);
    return value;
}

// MS2-FUNCTIONAL: assigns a typed AS2 value while retaining the replacement and releasing the old object.
// @0x1400079b0
unsigned* FUN_1400079b0(unsigned* destination, const unsigned* source)
{
    const auto type = *source;
    void* replacement = *reinterpret_cast<void* const*>(source + 2);
    if (replacement) {
        auto* count = reinterpret_cast<unsigned*>(static_cast<unsigned char*>(replacement) + 0x18);
        *count = (*count + 1) & 0x8fffffff;
    }
    ReleaseAs2GCObject(*reinterpret_cast<void**>(destination + 2));
    *destination = type;
    *reinterpret_cast<void**>(destination + 2) = replacement;
    return destination;
}

// MS2-FUNCTIONAL: resolves the lowercase node for an ActionScript string when needed.
// @0x140009ec0
void FUN_140009ec0(Scaleform::GFx::ASStringNode** nodeSlot)
{
    if (*nodeSlot && !(*nodeSlot)->pLower) (*nodeSlot)->ResolveLowercase_Impl();
}

// MS2-FUNCTIONAL: compares string node identity, using cached lowercase nodes for insensitive mode.
// @0x14000a030
bool FUN_14000a030(Scaleform::GFx::ASStringNode** left,
                   Scaleform::GFx::ASStringNode** right, bool caseSensitive)
{
    if (caseSensitive) return *left == *right;
    FUN_140009ec0(right);
    return *left && *right && (*left)->pLower == (*right)->pLower;
}

// MS2-FUNCTIONAL: returns the equality result with the same case handling as the bool helper.
// @0x14000a090
bool FUN_14000a090(Scaleform::GFx::ASStringNode** left,
                   Scaleform::GFx::ASStringNode** right, bool caseSensitive)
{
    return FUN_14000a030(left, right, caseSensitive);
}

namespace Scaleform { namespace GFx { namespace Video {

// Only the provider back-pointer is touched here (+0x40); the image classes come with the render units.
class VideoImage : public RefCountBaseV<VideoImage, Stat_Default_Mem>
{
public:
    UByte          Pad[0x40 - 0x10];
    VideoProvider* pVideoProvider;   // +0x40
};

// The display object a provider's frames are drawn into; only its weak-pointer base is needed here.
class VideoCharacter : public RefCountBaseWeakSupport<VideoCharacter, Stat_Default_Mem>
{
};

}}} // namespace Scaleform::GFx::Video

// MovieImpl member that registers a provider for advancing (unnamed in the exe's symbols).
void FUN_14256c520(Scaleform::GFx::MovieImpl* proot, Scaleform::GFx::Video::VideoProvider* pprovider);
// Wakes a video display object up when its provider has a first frame (sfr_video_02).
void FUN_140010a70(Scaleform::GFx::Video::VideoCharacter* pvideo);
// Points a video display object at a provider, or at none (sfr_video_02).
void FUN_140010b80(Scaleform::GFx::Video::VideoCharacter* pvideo, Scaleform::GFx::Video::VideoProvider* pprovider);

namespace Scaleform { namespace GFx { namespace AS2 {

using namespace Video;

// ==== VideoProviderNetStream =========================================================================================

// The sprite whose sound settings a provider's audio follows: the audio target itself, or its parent when the target
// is not a sprite.
static inline Sprite* GetAudioTargetSprite(CharacterHandle* ph)
{
    DisplayObject* pch = ph->pCharacter;
    if (!pch)
        return NULL;
    if (pch->IsSprite())
        return (Sprite*)pch;
    DisplayObject* pparent = (DisplayObject*)pch->pParent;
    if (pparent && pparent->IsSprite())
        return (Sprite*)pparent;
    return NULL;
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000ca90
VideoProviderNetStream::VideoProviderNetStream(NetStream* pnetstream)
    : pNetStream(pnetstream)
{
    pVideoPlayer = NULL;
    memset(&VInfo, 0, sizeof(VInfo));
    FrameTime                = 1.0f / 12;
    pTextureManager          = NULL;
    LoopFlag                 = false;
    PoolsNumber              = 2;
    BufferTime               = 0.0f;
    ReloadThreshHoldTime     = 0.8f;
    OpenURLTimeout           = 5.0f;
    SeekPos                  = 0.0f;
    FrameIsReady             = false;
    StartNotificationSent    = false;
    StopNotificationSent     = false;
    SeekNotificationSent     = true;
    NotFoundNotificationSent = false;
    pSubtitleMsgTmp          = NULL;
    pSubtitleMsg             = NULL;
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000c370
VideoProviderNetStream::~VideoProviderNetStream()
{
    Close();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140003490
bool VideoProviderNetStream::IsActive()
{
    if (!pVideoPlayer)
        return false;
    VideoPlayer::Status status = pVideoPlayer->GetStatus();
    return status == VideoPlayer::Opening || status == VideoPlayer::Ready || status == VideoPlayer::Starting ||
           status == VideoPlayer::Playing || status == VideoPlayer::Seeking || status == VideoPlayer::Stopping;
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls
// @0x140003520
void VideoProviderNetStream::Stop()
{
    if (pVideoPlayer)
        pVideoPlayer->Stop();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): no tail calls
// @0x140003540
void VideoProviderNetStream::Pause(bool pause)
{
    if (pVideoPlayer)
        pVideoPlayer->Pause(pause);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140004b50
void VideoProviderNetStream::Close()
{
    if (pTextureImage)
        pTextureImage->pVideoProvider = NULL;
    pTextureImage = NULL;
    if (pVideoPlayer)
        pVideoPlayer->Destroy();
    pVideoPlayer = NULL;
    if (pSubtitleMsgTmp)
    {
        SF_FREE(pSubtitleMsgTmp);
        pSubtitleMsgTmp = NULL;
    }
    if (pSubtitleMsg)
    {
        SF_FREE(pSubtitleMsg);
        pSubtitleMsg = NULL;
    }
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140004bf0
void VideoProviderNetStream::InitSoundChannel()
{
    if (pAudioTarget)
    {
        Sprite* psprite = GetAudioTargetSprite(pAudioTarget);
        Sound::SoundChannel* pchan = pVideoPlayer->GetSoundChannel(VideoPlayer::MainTrack);
        if (psprite && pchan)
        {
            pchan->SetVolume(psprite->GetRealSoundVolume());
            psprite->AddActiveSound(pchan, NULL, NULL);
        }
        pchan = pVideoPlayer->GetSoundChannel(VideoPlayer::SubAudio);
        if (psprite && pchan)
        {
            pchan->SetVolume(psprite->GetRealSubSoundVolume());
            psprite->AddActiveSound(pchan, NULL, NULL);
        }
    }
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140004cf0
void VideoProviderNetStream::Seek(float pos, MovieImpl* proot)
{
    SeekPos = pos;
    if (pVideoPlayer)
    {
        SeekNotificationSent = false;
        VideoPlayer::Status status = pVideoPlayer->GetStatus();
        if (status == VideoPlayer::Ready || status == VideoPlayer::Stopping || status == VideoPlayer::Playing ||
            status == VideoPlayer::Finished)
        {
            pVideoPlayer->Seek((UInt32)((float)VInfo.FrameRate / 1000.0f * SeekPos));
            if (status == VideoPlayer::Finished && proot)
                FUN_14256c520(proot, this);
        }
        InitSoundChannel();
    }
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140005fc0
void VideoProviderNetStream::SetAudioTarget(Sprite* ptarget)
{
    Sprite* pold = pAudioTarget ? GetAudioTargetSprite(pAudioTarget) : NULL;
    if (pold == ptarget)
        return;
    if (pold && pVideoPlayer)
    {
        Sound::SoundChannel* pchan = pVideoPlayer->GetSoundChannel(VideoPlayer::MainTrack);
        if (pchan)
        {
            Sprite::ActiveSoundItem* pitem = pold->ReleaseActiveSound(pchan);
            if (pitem)
            {
                pitem->pChannel->SetVolume(ptarget->GetRealSoundVolume());
                ptarget->AttachActiveSound(pitem);
                pitem->Release();
            }
            else
            {
                pchan->SetVolume(ptarget->GetRealSoundVolume());
                ptarget->AddActiveSound(pchan, NULL, NULL);
            }
        }
    }
    pAudioTarget = ptarget->GetCharacterHandle();
}

// The clock of a swfSync video: the target clip's frames played since the video started, at the movie's frame rate.
class SwfVideoSyncObject : public VideoPlayer::SyncObject
{
public:
    SF_NOINLINE SwfVideoSyncObject(Sprite* ptarget);
    ~SwfVideoSyncObject() {}

    virtual void SetStartFrame(unsigned frame) { StartFrame = frame; }
    virtual void Start() {}
    virtual void Stop() {}
    virtual void Pause(bool) {}
    virtual void GetTime(UInt64* count, UInt64* unit);

private:
    WeakPtr<Sprite> pTarget;      // +0x10
    unsigned        StartFrame;   // +0x18
    float           FrameTime;    // +0x1c
};

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140006120
SwfVideoSyncObject::SwfVideoSyncObject(Sprite* ptarget)
    : pTarget(ptarget), StartFrame(ptarget->GetCurrentFrame()), FrameTime(ptarget->GetMovieImpl()->FrameTime)
{
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x1400063d0
void SwfVideoSyncObject::GetTime(UInt64* count, UInt64* unit)
{
    Ptr<Sprite> ptarget = pTarget;
    if (ptarget)
    {
        unsigned frame = ptarget->GetCurrentFrame();
        if (frame > StartFrame)
        {
            *unit  = 1000000;
            *count = (UInt64)((float)(frame - StartFrame) * FrameTime * (float)*unit);
            return;
        }
    }
    *count = 0;
    *unit  = 1000;
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x1400064f0
void VideoProviderNetStream::SetSwfSync(bool flag, Sprite* ptarget)
{
    if (flag)
        pSyncObj = *SF_NEW SwfVideoSyncObject(ptarget);
    else
        pSyncObj = NULL;
    if (pVideoPlayer)
        pVideoPlayer->SetSyncObject(pSyncObj);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): member reloaded after the test
// @0x140004da0
VideoImage* VideoProviderNetStream::GetTexture(int* width, int* height)
{
    if (!pVideoPlayer || !pTextureImage)
        return NULL;
    *width  = VInfo.Width;
    *height = VInfo.Height;
    return pTextureImage;
}

// The image state; only the texture manager it creates textures with is read here.
class ImageCreator : public State
{
public:
    Render::TextureManager* GetTextureManager() const { return pTexManager; }

protected:
    Render::TextureManager* pTexManager;   // +0x18
};

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling; the movie heap
// read directly where the exe calls the virtual Movie::GetHeap, the audio target taken from _level0 where the exe
// asks the AS2 root for the root movie (the same object)
// @0x14000c4b0
void VideoProviderNetStream::OpenUrl(const char* url, Environment* penv)
{
    MovieImpl* proot = penv->GetMovieImpl();
    Ptr<LoadStates> pls = *SF_NEW LoadStates(proot->pMainMovieDef->pLoaderImpl, proot->pStateBag);

    String level0Path;
    penv->GetAS2Root()->GetLevel0Path(&level0Path);
    URLBuilder::LocationInfo loc(URLBuilder::File_Regular, String(url), level0Path);
    String fileName;
    pls->BuildURL(&fileName, loc);

    FrameTime = 1.0f / 12.0f;
    SeekPos   = 0.0f;
    VInfo.CuePoints.Clear();
    VInfo.AudioTracks.Clear();
    pTextureImage = NULL;
    FrameIsReady  = false;
    if (!pVideoPlayer)
    {
        StateBag* pstates = proot->GetStateBag();
        Ptr<GFx::Video::VideoBase> pvideo = *(GFx::Video::VideoBase*)pstates->GetStateAddRef(State::State_Video);
        if (pvideo)
        {
            pTextureManager = pvideo->GetTextureManager();
            if (!pTextureManager)
            {
                Ptr<ImageCreator> pimgCreator = *(ImageCreator*)pstates->GetStateAddRef(State::State_ImageCreator);
                pTextureManager = pimgCreator->GetTextureManager();
            }
            Ptr<Log>            plog        = pstates->GetLog();
            Ptr<FileOpenerBase> pfileOpener = *(FileOpenerBase*)pstates->GetStateAddRef(State::State_FileOpener);
            Ptr<TaskManager>    ptaskMgr    = *(TaskManager*)pstates->GetStateAddRef(State::State_TaskManager);
            pVideoPlayer = pvideo->CreateVideoPlayer(proot->GetMovieHeap(), ptaskMgr, pfileOpener, plog);
        }
        if (pVideoPlayer)
        {
            pVideoPlayer->SetSyncObject(pSyncObj);
            pVideoPlayer->SetBufferTime(BufferTime);
            pVideoPlayer->SetNumberOfFramePools(PoolsNumber);
            pVideoPlayer->SetReloadThresholdTime(ReloadThreshHoldTime);
            pVideoPlayer->SetDecodeHeaderTimeout(OpenURLTimeout);
            pVideoPlayer->SetSoundSpatialInfo(SpatialInfo);
        }
    }
    if (pVideoPlayer)
    {
        pVideoPlayer->Open(fileName.ToCStr());
        pTarget = penv->GetTarget()->GetCharacterHandle();
        FUN_14256c520(proot, this);
        pVideoPlayer->SetLoopFlag(LoopFlag);
        StartNotificationSent    = false;
        NotFoundNotificationSent = false;
        SeekNotificationSent     = true;
        if (pSubtitleMsgTmp)
        {
            SF_FREE(pSubtitleMsgTmp);
            pSubtitleMsgTmp = NULL;
        }
        if (pSubtitleMsg)
        {
            SF_FREE(pSubtitleMsg);
            pSubtitleMsg = NULL;
        }
        if (!pAudioTarget)
            pAudioTarget = ((DisplayObject*)proot->pMainMovie)->GetCharacterHandle();
    }
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501)
// @0x14000c4a0
float VideoProviderNetStream::GetFrameTime()
{
    return FrameTime;
}

// ==== NetStream ======================================================================================================

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000cc10
void NetStream::commonInit(Environment* penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_NetStream));
    pVideoProvider = *SF_HEAP_NEW(penv->GetHeap()) VideoProviderNetStream(this);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000cc90
NetStream::NetStream(Environment* penv)
    : Object(penv), Paused(false)
{
    commonInit(penv);
}

inline void NetStream::ReleaseVideoProvider()
{
    if (pVideoProvider)
    {
        pVideoProvider->NotifyNetStreamRemoved();
        if (pVideoProvider->GetPlayer())
            pVideoProvider->GetPlayer()->Stop();
    }
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140008070
NetStream::~NetStream()
{
    ReleaseVideoProvider();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x1400056d0
void NetStream::Finalize_GC()
{
    ReleaseVideoProvider();
    pVideoProvider.~Ptr<VideoProviderNetStream>();
    Object::Finalize_GC();
}

// The exe keeps the three instantiations out of line (pinned at the end of the file).
// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
template<class Functor>
SF_NOINLINE void NetStream::ForEachChild_GC(Collector* prcc) const
{
    Object::template ForEachChild_GC<Functor>(prcc);
    OnSubtitleCallback.template ForEachChild_GC<Functor>(prcc);
    OnMetaDataCallback.template ForEachChild_GC<Functor>(prcc);
    OnStatusCallback.template ForEachChild_GC<Functor>(prcc);
    OnCuePointCallback.template ForEachChild_GC<Functor>(prcc);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140007fb0
void NetStream::ExecuteForEachChild_GC(Collector* prcc, OperationGC operation) const
{
    ASRefCountBaseType::CallForEachChild<NetStream>(prcc, operation);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140008250
bool NetStream::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    if (name == "onMetaData")
    {
        OnMetaDataCallback = val.ToFunction_Call(penv);
        return true;
    }
    else if (name == "onStatus")
    {
        OnStatusCallback = val.ToFunction_Call(penv);
        return true;
    }
    else if (name == "onCuePoint")
    {
        OnCuePointCallback = val.ToFunction_Call(penv);
        return true;
    }
    if (penv->CheckExtensions())
    {
        if (name == "onSubtitle")
        {
            OnSubtitleCallback = val.ToFunction_Call(penv);
            return true;
        }
        else if (name == "subtitleTrack")
        {
            if (!OnSubtitleCallback.IsNull())
                pVideoProvider->SetSubtitleChannel((int)val.ToNumber(penv) - 1);
            return true;
        }
        else if (name == "audioTrack")
        {
            pVideoProvider->SetAudioTrack((int)val.ToNumber(penv));
            return true;
        }
        else if (name == "subAudioTrack")
        {
            pVideoProvider->SetSubAudioTrack((int)val.ToNumber(penv));
            return true;
        }
        else if (name == "voiceTrack")
        {
            pVideoProvider->ReplaceCenterVoice((int)val.ToNumber(penv));
            return true;
        }
        else if (name == "loop")
        {
            pVideoProvider->SetLoopFlag(val.ToBool(penv));
            return true;
        }
        else if (name == "swfSync")
        {
            AvmCharacter* pavm = penv->GetAvmTarget();
            if (pavm->GetDispObj()->IsSprite())
            {
                Sprite* psprite = (Sprite*)static_cast<const ObjectInterface*>(pavm)->ToSprite();
                pVideoProvider->SetSwfSync(val.ToBool(penv), psprite);
            }
        }
    }
    return Object::SetMember(penv, name, val, flags);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000aab0
bool NetStream::GetMember(Environment* penv, const ASString& name, Value* val)
{
    if (penv->CheckExtensions())
    {
        if (name == "setReloadThresholdTime")
        {
            *val = Value(penv->GetSC(), NetStreamProto::SetReloadThresholdTime);
            return true;
        }
        else if (name == "setNumberOfFramePools")
        {
            *val = Value(penv->GetSC(), NetStreamProto::SetNumberOfFramePools);
            return true;
        }
        else if (name == "setOpenTimeout")
        {
            *val = Value(penv->GetSC(), NetStreamProto::SetOpenURLTimeout);
            return true;
        }
        else if (name == "setSoundSpatial")
        {
            *val = Value(penv->GetSC(), NetStreamProto::SetSoundSpatial);
            return true;
        }
        else if (name == "onSubtitle")
        {
            *val = Value(OnSubtitleCallback);
            return true;
        }
        else if (name == "subtitleTrack")
        {
            int channel = pVideoProvider->GetSubtitleChannel();
            if (channel < 0)
                channel = -1;
            *val = Value(channel + 1);
            return true;
        }
        else if (name == "currentFrame")
        {
            *val = Value((Number)(float)(pVideoProvider->GetPosition() + 1));
            return true;
        }
    }
    if (name == "time")
    {
        UInt32 pos       = pVideoProvider->GetPosition();
        UInt32 frameRate = pVideoProvider->GetVideoInfo().FrameRate;
        if (frameRate)
            *val = Value((Number)((float)pos / ((float)frameRate / 1000.0f)));
        else
            *val = Value((Number)0);
        return true;
    }
    else if (name == "onMetaData")
    {
        *val = Value(OnMetaDataCallback);
        return true;
    }
    else if (name == "onStatus")
    {
        *val = Value(OnStatusCallback);
        return true;
    }
    else if (name == "onCuePoint")
    {
        *val = Value(OnCuePointCallback);
        return true;
    }
    else if (name == "currentFps")
    {
        *val = Value((Number)((float)pVideoProvider->GetVideoInfo().FrameRate / 1000.0f));
        return true;
    }
    return Object::GetMember(penv, name, val);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140005720
void NetStream::Seek(Number pos, Environment* penv)
{
    pVideoProvider->Seek((float)pos, penv->GetMovieImpl());
}

// ---- NetStream.prototype

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x1400047a0
void NetStreamProto::Close(const FnCall& fn)
{
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream)
        return;
    pnetstream->Stop();
    // close(true) also drops the player
    if (fn.NArgs > 0 && fn.Arg(0).ToBool(fn.Env))
        pnetstream->GetVideoProvider()->Close();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140004810
void NetStreamProto::Pause(const FnCall& fn)
{
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream)
        return;
    if (fn.NArgs > 0)
        pnetstream->Pause(fn.Arg(0).ToBool(fn.Env));
    else
        pnetstream->Pause();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140004880
void NetStreamProto::SetBufferTime(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.setBufferTime requires one argument (time)\n");
        return;
    }
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream || !fn.Arg(0).IsNumber())
        return;
    pnetstream->SetBufferTime(fn.Arg(0).ToNumber(fn.Env));
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140004920
void NetStreamProto::SetNumberOfFramePools(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.setNumberOfFramePools requires one argument (pools)\n");
        return;
    }
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream || !fn.Arg(0).IsNumber())
        return;
    pnetstream->SetNumberOfFramePools(fn.Arg(0).ToNumber(fn.Env));
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x1400049c0
void NetStreamProto::SetReloadThresholdTime(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.setReloadThresholdTime requires one argument (time)\n");
        return;
    }
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream || !fn.Arg(0).IsNumber())
        return;
    pnetstream->SetReloadThresholdTime(fn.Arg(0).ToNumber(fn.Env));
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140004a60
void NetStreamProto::SetOpenURLTimeout(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.setOpenTimeout requires one argument (timeout)\n");
        return;
    }
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream || !fn.Arg(0).IsNumber())
        return;
    pnetstream->SetOpenURLTimeout(fn.Arg(0).ToNumber(fn.Env));
}

// Reads an array of numbers as (x, y, z) triples.
// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140007080
static SF_NOINLINE void ReadVectorArray(Environment* penv, const Value& val, Array<Sound::SoundChannel::Vector>& vecs)
{
    if (!val.IsObject() || val.ToObject(penv)->GetObjectType() != Object::Object_Array)
        return;
    ArrayObject* parr = static_cast<ArrayObject*>(val.ToObject(penv));
    for (int i = 0, n = parr->GetSize(); i < n; i += 3)
    {
        Sound::SoundChannel::Vector v;
        v.X = (float)parr->GetElementPtr(i)->ToNumber(penv);
        v.Y = (float)parr->GetElementPtr(i + 1)->ToNumber(penv);
        v.Z = (float)parr->GetElementPtr(i + 2)->ToNumber(penv);
        vecs.PushBack(v);
    }
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x1400085c0
void NetStreamProto::SetSoundSpatial(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.SetSoundSpatial requires at least one argument (position)\n");
        return;
    }
    Environment* penv = fn.Env;
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream)
        return;

    Array<Sound::SoundChannel::Vector> position;
    ReadVectorArray(penv, fn.Arg(0), position);
    pnetstream->GetVideoProvider()->SetSpatialInfo(0, position);
    if (fn.NArgs > 1)
    {
        Array<Sound::SoundChannel::Vector> orientation;
        ReadVectorArray(penv, fn.Arg(1), orientation);
        pnetstream->GetVideoProvider()->SetSpatialInfo(1, orientation);
    }
    if (fn.NArgs > 2)
    {
        Array<Sound::SoundChannel::Vector> velocity;
        ReadVectorArray(penv, fn.Arg(2), velocity);
        pnetstream->GetVideoProvider()->SetSpatialInfo(2, velocity);
    }
    pnetstream->GetVideoProvider()->ApplySpatialInfo();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140005780
void NetStreamProto::Seek(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.seek requires one argument (offset)\n");
        return;
    }
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream || !fn.Arg(0).IsNumber())
        return;
    pnetstream->Seek(fn.Arg(0).ToNumber(fn.Env), fn.Env);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000c9f0
void NetStreamProto::Play(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.Play requires one argument (file name)\n");
        return;
    }
    ASString url = fn.Arg(0).ToString(fn.Env);
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (pnetstream)
        pnetstream->OpenUrl(url.ToCStr(), fn.Env);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140009cf0
void VideoProviderNetStream::RegisterVideoCharacter(VideoCharacter* pvideo)
{
    if (!pvideo)
        return;
    for (UPInt i = 0; i < VideoCharacters.GetSize(); ++i)
    {
        Ptr<VideoCharacter> pchar = VideoCharacters[i];
        if (pchar == pvideo)
            return;
    }
    VideoCharacters.PushBack(WeakPtr<VideoCharacter>(pvideo));
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000af10
VideoCharacter* VideoProviderNetStream::RemoveFirstVideoCharacter()
{
    if (VideoCharacters.GetSize() == 0)
        return NULL;
    Ptr<VideoCharacter> pvideo = VideoCharacters[0];
    VideoCharacters.RemoveAt(0);
    pTextureImage = NULL;
    return pvideo;
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140006580
void VideoProviderNetStream::NotifyVideoCharacters()
{
    for (UPInt i = 0; i < VideoCharacters.GetSize(); ++i)
    {
        Ptr<VideoCharacter> pvideo = VideoCharacters[i];
        if (pvideo)
            FUN_140010a70(pvideo);
    }
}

// The environment the NetStream callbacks run on: the target character's, none when it is not interactive.
static inline Environment* GetTargetEnvironment(CharacterHandle* ptarget)
{
    DisplayObject* pch = ptarget->pCharacter;
    InteractiveObject* pchar = pch->IsInteractiveObject() ? (InteractiveObject*)pch : NULL;
    if (!pchar)
        return NULL;
    return ToAvmCharacter(pchar)->GetASEnvironment();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140008860
void VideoProviderNetStream::SendNotification(const char* note, bool error)
{
    if (!pTarget || !pNetStream || pNetStream->OnStatusCallback.IsNull())
        return;
    Environment* penv = GetTargetEnvironment(pTarget);
    if (!penv)
        return;

    Ptr<Object> pobj = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
    if (error)
        pobj->SetConstMemberRaw(penv->GetSC(), "level", Value(penv->CreateConstString("error")));
    else
        pobj->SetConstMemberRaw(penv->GetSC(), "level", Value(penv->CreateConstString("status")));
    pobj->SetConstMemberRaw(penv->GetSC(), "code", Value(penv->CreateConstString(note)));

    penv->Push(Value(pobj));
    Value ret;
    pNetStream->OnStatusCallback.Invoke(FnCall(&ret, pNetStream, penv, 1, penv->GetTopIndex()));
    penv->Drop1();
}

// A cue point as a script object: name, time in seconds, type and its parameters.
// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140008bb0
static Object* ConvertCuePoint(const VideoPlayer::CuePoint& cp, Environment* penv)
{
    Object* pobj = SF_HEAP_NEW(penv->GetHeap()) Object(penv);
    pobj->SetMemberRaw(penv->GetSC(), penv->CreateConstString("name"), Value(penv->CreateString(cp.Name)));
    pobj->SetMemberRaw(penv->GetSC(), penv->CreateConstString("time"), Value((Number)(cp.Time / 1000.0f)));
    pobj->SetMemberRaw(penv->GetSC(), penv->CreateConstString("type"),
                       Value(penv->CreateConstString(cp.Type == VideoPlayer::NavigationCuePoint ? "navigation" : "event")));
    if (cp.Params.GetSize() > 0)
    {
        Ptr<Object> pparams = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
        for (UPInt i = 0; i < cp.Params.GetSize(); ++i)
        {
            // The exe builds an object per parameter that it never uses.
            Ptr<Object> pparam = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
            pparams->SetMemberRaw(penv->GetSC(), penv->CreateString(cp.Params[i].Name),
                                  Value(penv->CreateString(cp.Params[i].Value)));
        }
        pobj->SetMemberRaw(penv->GetSC(), penv->CreateConstString("parameters"), Value(pparams));
    }
    return pobj;
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140009140
void VideoProviderNetStream::SendMetaInformation()
{
    if (!pNetStream || !pTarget || pNetStream->OnMetaDataCallback.IsNull())
        return;
    Environment* penv = GetTargetEnvironment(pTarget);
    if (!penv)
        return;

    Ptr<Object> pobj = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
    pobj->SetConstMemberRaw(penv->GetSC(), "canSeekToEnd", Value(true));
    pobj->SetConstMemberRaw(penv->GetSC(), "framerate", Value((Number)(VInfo.FrameRate / 1000.0f)));
    pobj->SetConstMemberRaw(penv->GetSC(), "width", Value(VInfo.Width));
    pobj->SetConstMemberRaw(penv->GetSC(), "height", Value(VInfo.Height));
    pobj->SetConstMemberRaw(penv->GetSC(), "duration",
                            Value((Number)((float)VInfo.TotalFrames * 1000.0f / (float)VInfo.FrameRate)));
    if (penv->CheckExtensions())
    {
        pobj->SetConstMemberRaw(penv->GetSC(), "subtitleTracksNumber", Value(VInfo.SubtitleChannelsNumber));
        if (VInfo.AudioTracks.GetSize() > 0)
        {
            Ptr<ArrayObject> ptracks = *static_cast<ArrayObject*>(penv->OperatorNew(penv->GetBuiltin(ASBuiltin_Array)));
            for (UPInt i = 0; i < VInfo.AudioTracks.GetSize(); ++i)
            {
                Ptr<Object> ptrack = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
                ptrack->SetConstMemberRaw(penv->GetSC(), "trackIndex", Value(VInfo.AudioTracks[i].Index));
                ptrack->SetConstMemberRaw(penv->GetSC(), "channelsNumber",
                                          Value((int)VInfo.AudioTracks[i].ChannelsNumber));
                ptrack->SetConstMemberRaw(penv->GetSC(), "sampleRate", Value((int)VInfo.AudioTracks[i].SampleRate));
                ptrack->SetConstMemberRaw(penv->GetSC(), "totalSamples",
                                          Value((int)VInfo.AudioTracks[i].TotalSamples));
                ptracks->PushBack(Value(ptrack));
            }
            pobj->SetConstMemberRaw(penv->GetSC(), "audioTracks", Value(ptracks));
        }
    }
    if (VInfo.CuePoints.GetSize() > 0)
    {
        Ptr<ArrayObject> pcuePoints = *static_cast<ArrayObject*>(penv->OperatorNew(penv->GetBuiltin(ASBuiltin_Array)));
        for (UPInt i = 0; i < VInfo.CuePoints.GetSize(); ++i)
        {
            Ptr<Object> pcuePoint = *ConvertCuePoint(VInfo.CuePoints[i], penv);
            pcuePoints->PushBack(Value(pcuePoint));
        }
        pobj->SetConstMemberRaw(penv->GetSC(), "cuePoints", Value(pcuePoints));
    }

    penv->Push(Value(pobj));
    Value ret;
    pNetStream->OnMetaDataCallback.Invoke(FnCall(&ret, pNetStream, penv, 1, penv->GetTopIndex()));
    penv->Drop1();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140009850
void VideoProviderNetStream::SendCuePoints(const Array<VideoPlayer::CuePoint>& cuePoints)
{
    if (!pNetStream || !pTarget || pNetStream->OnCuePointCallback.IsNull() || cuePoints.GetSize() == 0)
        return;
    Environment* penv = GetTargetEnvironment(pTarget);
    if (!penv)
        return;

    for (UPInt i = 0; i < cuePoints.GetSize(); ++i)
    {
        Ptr<Object> pcuePoint = *ConvertCuePoint(cuePoints[i], penv);
        penv->Push(Value(pcuePoint));
        Value ret;
        pNetStream->OnCuePointCallback.Invoke(FnCall(&ret, pNetStream, penv, 1, penv->GetTopIndex()));
        penv->Drop1();
    }
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140009ad0
void VideoProviderNetStream::SendSubtitleInformation()
{
    if (!pTarget)
        return;
    Environment* penv = GetTargetEnvironment(pTarget);
    if (!penv)
        return;

    Value ret;
    penv->Push(Value(penv->CreateString(pSubtitleMsg)));
    pNetStream->OnSubtitleCallback.Invoke(FnCall(&ret, pNetStream, penv, 1, penv->GetTopIndex()));
    penv->Drop1();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000be60
void VideoProviderNetStream::Advance()
{
    if (!pVideoPlayer)
        return;

    FrameIsReady = pVideoPlayer->IsTextureReady();
    pVideoPlayer->Decode();

    VideoPlayer::Status status = pVideoPlayer->GetStatus();
    switch (status)
    {
    case VideoPlayer::Ready:
        if (!pTextureImage)
        {
            pTextureImage = *pVideoPlayer->CreateTexture(pTextureManager);
            if (pTextureImage)
            {
                pVideoPlayer->GetVideoInfo(&VInfo);
                float frameTime = 1000.0f / VInfo.FrameRate;
                FrameTime = frameTime - frameTime * 0.1f;
            }
        }
        if (SeekPos > 0.0f)
            pVideoPlayer->Seek((UInt32)((float)VInfo.FrameRate / 1000.0f * SeekPos));
        InitSoundChannel();
        NotifyVideoCharacters();
        SendNotification("NetStream.Play.Start", false);
        SendMetaInformation();
        pVideoPlayer->Play();
        break;

    case VideoPlayer::Playing:
        if (!SeekNotificationSent && FrameIsReady)
        {
            SeekNotificationSent = true;
            SendNotification("NetStream.Seek.Notify", false);
        }
        break;

    case VideoPlayer::Finished:
    case VideoPlayer::Stopped:
        if (!SeekNotificationSent)
        {
            SeekNotificationSent = true;
            SendNotification("NetStream.Seek.InvalidTime", true);
        }
        SendNotification("NetStream.Play.Stop", false);
        break;

    case VideoPlayer::FileNotFound:
        if (!NotFoundNotificationSent)
        {
            NotFoundNotificationSent = true;
            SendNotification("NetStream.Play.StreamNotFound", true);
        }
        break;

    case VideoPlayer::InternalError:
        SendNotification("NetStream.Play.InternalError", true);
        break;

    default:
        break;
    }

    if (status == VideoPlayer::Ready || status == VideoPlayer::Playing)
    {
        Array<VideoPlayer::CuePoint> cuePoints;
        pVideoPlayer->GetCurrentCuePoints(&cuePoints);
        SendCuePoints(cuePoints);
    }

    if (pNetStream && !pNetStream->OnSubtitleCallback.IsNull() && VInfo.MaxSubtitleLen > 0)
    {
        if (!pSubtitleMsg)
        {
            pSubtitleMsg = (char*)SF_ALLOC(VInfo.MaxSubtitleLen, Stat_Default_Mem);
            memset(pSubtitleMsg, 0, VInfo.MaxSubtitleLen);
        }
        if (!pSubtitleMsgTmp)
        {
            pSubtitleMsgTmp = (char*)SF_ALLOC(VInfo.MaxSubtitleLen, Stat_Default_Mem);
            memset(pSubtitleMsgTmp, 0, VInfo.MaxSubtitleLen);
        }
        if (pVideoPlayer)
            pVideoPlayer->UpdateTexture(pTextureImage, pSubtitleMsgTmp, VInfo.MaxSubtitleLen);
        if (pSubtitleMsg && pSubtitleMsgTmp && strncmp(pSubtitleMsg, pSubtitleMsgTmp, VInfo.MaxSubtitleLen) != 0)
        {
            strncpy_s(pSubtitleMsg, VInfo.MaxSubtitleLen, pSubtitleMsgTmp, VInfo.MaxSubtitleLen);
            SendSubtitleInformation();
        }
    }
    else
    {
        if (pVideoPlayer)
            pVideoPlayer->UpdateTexture(pTextureImage, NULL, 0);
    }
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x1400054b0
bool ObjectInterface::SetConstMemberRaw(ASStringContext* psc, const char* name, const Value& val,
                                        const PropFlags& flags)
{
    return SetMemberRaw(psc, psc->CreateConstString(name), val, flags);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140007af0
FnCall::~FnCall()
{
}

// ==== NetStream constructor function ================================================================================

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000cd30
Object* NetStreamCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) NetStream(penv);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000cd70
void NetStreamCtorFunction::GlobalCtor(const FnCall& fn)
{
    Ptr<NetStream> pnetstream;
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object::Object_NetStream && !fn.ThisPtr->IsBuiltinPrototype())
        pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    else
        pnetstream = *SF_HEAP_NEW(fn.Env->GetHeap()) NetStream(fn.Env);
    fn.Result->SetAsObject(pnetstream.GetPtr());
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000ce30
NetStreamCtorFunction::NetStreamCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
}

// ==== Video ========================================================================================================

// Video.prototype methods.
class VideoProto
{
public:
    static void AttachVideo(const FnCall& fn);   // exe 0x14000d400
};

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000d400
void VideoProto::AttachVideo(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: Video.attachVideo requires one argument (NetStream object)\n");
        return;
    }
    if (!fn.Arg(0).IsObject() || !fn.ThisPtr || fn.ThisPtr->GetObjectType() != Object::Object_Video)
        return;

    VideoCharacter* pvideo    = (VideoCharacter*)static_cast<AvmCharacter*>(fn.ThisPtr)->GetDispObj();
    VideoProvider*  pprovider = NULL;
    if (fn.Arg(0).ToObject(fn.Env)->GetObjectType() == Object::Object_NetStream)
    {
        NetStream* pnetstream = static_cast<NetStream*>(fn.Arg(0).ToObject(fn.Env));
        if (pnetstream)
            pprovider = pnetstream->GetVideoProvider();
    }
    if (pvideo)
    {
        FUN_140010b80(pvideo, pprovider);
        if (pprovider)
        {
            // Without extensions a provider feeds one video only: the one it fed before lets go.
            if (!fn.Env->CheckExtensions())
            {
                VideoCharacter* pcurrent = pprovider->RemoveFirstVideoCharacter();
                if (pcurrent)
                    FUN_140010b80(pcurrent, NULL);
            }
            pprovider->RegisterVideoCharacter(pvideo);
        }
    }
}

// The script object of a Video clip.
class VideoObject : public Object
{
public:
    VideoObject(ASStringContext* psc, Object* pprototype);              // exe 0x14000de10
    VideoObject(GlobalContext* gCtxt, InteractiveObject* pcharacter);   // exe 0x14000dee0
    VideoObject(Environment* penv);                                     // exe 0x14000dfb0

    virtual ObjectType GetObjectType() const { return Object_VideoASObject; }
    virtual InteractiveObject* GetASCharacter();
    virtual const InteractiveObject* GetASCharacter() const;

protected:
    virtual void Finalize_GC();   // exe 0x14000db80

    WeakPtr<InteractiveObject> pCharacter;   // +0x68
};

// The Video class (constructor function).
class VideoCtorFunction : public CFunctionObject
{
public:
    virtual Object* CreateNewObject(Environment* penv) const;   // exe 0x14000e0c0

    static void GlobalCtor(const FnCall& fn);   // exe 0x14000e100
};

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x140007ba0
void Object::Set__proto__(ASStringContext* psc, Object* protoObj)
{
    if (!pProto)
        SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin___proto__), Value(Value::UNSET),
                     PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = protoObj;
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000de10
VideoObject::VideoObject(ASStringContext* psc, Object* pprototype)
    : Object(psc)
{
    Set__proto__(psc, pprototype);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000dee0
VideoObject::VideoObject(GlobalContext* gCtxt, InteractiveObject* pcharacter)
    : Object(gCtxt->GetGC()), pCharacter(pcharacter)
{
    Environment* penv = AS2::ToAvmCharacter(pcharacter)->GetASEnvironment();
    Set__proto__(penv->GetSC(), gCtxt->GetPrototype(ASBuiltin_Video));
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000dfb0
VideoObject::VideoObject(Environment* penv)
    : Object(penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Video));
}

// MS2-FUNCTIONAL: resolves the weak character handle and returns one strong reference to the live clip.
// @0x14000daa0
InteractiveObject* VideoObject::GetASCharacter()
{
    Ptr<InteractiveObject> strong = pCharacter;
    InteractiveObject* character = strong.GetPtr();
    if (character) character->AddRef();
    return character;
}

// MS2-FUNCTIONAL: const overload of the weak character handle lookup.
// @0x14000db10
const InteractiveObject* VideoObject::GetASCharacter() const
{
    return const_cast<VideoObject*>(this)->GetASCharacter();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000db80
void VideoObject::Finalize_GC()
{
    pCharacter.~WeakPtr();
    Object::Finalize_GC();
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000e0c0
Object* VideoCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) VideoObject(penv);
}

// MS2-FUNCTIONAL Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501): other scheduling
// @0x14000e100
void VideoCtorFunction::GlobalCtor(const FnCall& fn)
{
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object::Object_Video && !fn.ThisPtr->IsBuiltinPrototype())
        fn.Result->SetAsObject(static_cast<Object*>(fn.ThisPtr));
    else
        fn.Result->SetAsObject(SF_HEAP_NEW(fn.Env->GetHeap()) VideoObject(fn.Env));
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7NetStream@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b5030
// MS2-PIN: ??_7NetStream@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b5080
// MS2-PIN: ??_7VideoProviderNetStream@AS2@GFx@Scaleform@@6B@ 0x1431b5620
// MS2-PIN: ??_7VideoProvider@Video@GFx@Scaleform@@6B@ 0x1431b4f30
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
// MS2-PIN: ??$ForEachChild_GC@UReleaseFunctor@?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@@NetStream@AS2@GFx@Scaleform@@QEBAXPEAV?$RefCountCollector@$0BED@@123@@Z 0x140007e40
// MS2-PIN: ??$ForEachChild_GC@UMarkInCycleFunctor@?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@@NetStream@AS2@GFx@Scaleform@@QEBAXPEAV?$RefCountCollector@$0BED@@123@@Z 0x140007ea0
// MS2-PIN: ??$ForEachChild_GC@UScanInUseFunctor@?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@@NetStream@AS2@GFx@Scaleform@@QEBAXPEAV?$RefCountCollector@$0BED@@123@@Z 0x140007f00
// MS2-PIN: ??_7SwfVideoSyncObject@AS2@GFx@Scaleform@@6B@ 0x1431b4fe8
// MS2-PIN: ??0?$WeakPtr@VVideoCharacter@Video@GFx@Scaleform@@@Scaleform@@QEAA@PEAVVideoCharacter@Video@GFx@1@@Z 0x140004eb0
// MS2-PIN: ??_7NetStreamCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b56b0
// MS2-PIN: ??_7NetStreamCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b5740
// MS2-PIN: ??_7VideoObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b5af0
// MS2-PIN: ??_7VideoObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b5a40
// MS2-PIN: ??0?$WeakPtr@VSprite@GFx@Scaleform@@@Scaleform@@QEAA@PEAVSprite@GFx@1@@Z 0x14000d530
// MS2-PIN: ?ToString@Value@AS2@GFx@Scaleform@@QEBA?AVASString@34@PEAVEnvironment@234@H@Z 0x140003290
// MS2-PIN: ?CreateString@StringManager@AS2@GFx@Scaleform@@QEBA?AVASString@34@PEBD@Z 0x140003940
// MS2-PIN: ??4?$Ptr@VVideoImage@Video@GFx@Scaleform@@@Scaleform@@QEAAAEBV01@PEAVVideoImage@Video@GFx@1@@Z 0x140003a70
// MS2-PIN: ??0LocationInfo@URLBuilder@GFx@Scaleform@@QEAA@W4FileUse@123@AEBVString@3@1@Z 0x140004290
// MS2-PIN: ?OperatorNew@Environment@AS2@GFx@Scaleform@@QEAAPEAVObject@234@AEBVASString@34@HH@Z 0x1400044b0
// MS2-PIN: ??0?$WeakPtr@VInteractiveObject@GFx@Scaleform@@@Scaleform@@QEAA@PEAVInteractiveObject@GFx@1@@Z 0x140004ef0
// MS2-PIN: ??0CuePointParam@VideoPlayer@Video@GFx@Scaleform@@QEAA@AEBU01234@@Z 0x140005390
// MS2-PIN: ??0CuePoint@VideoPlayer@Video@GFx@Scaleform@@QEAA@XZ 0x14000a920
