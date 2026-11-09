// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Video, the AS2 side: the video sound
// stream helpers, then NetStream (script object, prototype methods, constructor) with its media provider, and the AS2
// Video object. Our own source, written from the exe; the leaked SDK copies were only used to name things.
// This part of the Video add-on lib is VS2008 SP1 code, so the unit builds with cl 15.00.30729 and the vc11
// options (MS2-TOOLSET: vc9v, cmake/ms2-unit-profiles.cmake). Keep it C++03: no auto, nullptr, range-for, std:: C
// functions, alias `using` (so ExeDecl is a struct), explicit conversion operators or variadic templates, and no
// hook/ms2hook.h (its hook registrations are in sfr_video_hooks.cpp). clang-cl compiles it as before.
// MS2-UNIT: sfr_video_01
// MS2-TOOLSET: vc9v
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140002930-0x14000e470 .text$mn
#define MS2_AS2_VALUE_DTOR_CALL
#include "../include/video/video_as2netstream.h"
#include "../include/video/video_as2videoobject.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/video/video_as2avmvideocharacter.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/gfx_loaderimpl.h"

// The exe functions and globals this unit uses but does not define, declared by their FUN_<va> / DAT_<va> names: the
// hook DLL binds them to the exe, the full exe to the recovered definition at that VA (tools/fullexe/alias.py).
template <class T> struct ExeDecl { typedef T type; };

// (C3: real Prototype<VideoObject> ctor/dtor) extern ExeDecl<void*>::type DAT_1431b59f0;
// (C3: real Prototype<VideoObject> ctor/dtor) #define VideoProtoGCVtable DAT_1431b59f0
// (C3: real Prototype<VideoObject> ctor/dtor) extern ExeDecl<void*>::type DAT_1431b5940;
// (C3: real Prototype<VideoObject> ctor/dtor) #define VideoProtoInterfaceVtable DAT_1431b5940
// (C3: real Prototype<VideoObject> ctor/dtor) extern ExeDecl<void*>::type DAT_1431b5938;
// (C3: real Prototype<VideoObject> ctor/dtor) #define VideoProtoBaseVtable DAT_1431b5938
extern ExeDecl<void*>::type DAT_1431b4be0[];
#define VideoSoundStreamVtable (*DAT_1431b4be0)
extern ExeDecl<void*>::type DAT_1431b4ce0[];
#define VideoSoundChannelSystemVtable (*DAT_1431b4ce0)
// The AS2 AvmVideoCharacter vftables (0x1431b5cb0 / 0x1431b5c00 / 0x1431b5b40) come from its ctor (0x14000e2b0).
//
//
//
//
//
// The NetStreamProto vftables (0x1431b5480 / 0x1431b54d0 / 0x1431b5478) come from its ctor below (0x14000ae30),
// which calls the out-of-line Prototype<NetStream> ctor (0x140009e20).
namespace Scaleform { namespace GFx { namespace AS2 {
template<> Prototype<NetStream>::Prototype(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor);   // exe 0x140009e20
}}}
namespace Scaleform { namespace GFx { namespace AS2 { template<> Prototype<VideoObject>::Prototype(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); }}}   // exe 0x14000e1e0
// NetStreamProto's ctor below (no exe row) emits the three ??_7NetStreamProto tables; the hand-inlined ctors
// FUN_14000ae30 / FUN_14000cf20 store them through the DAT_ names, so bind those names to the tables here. The hook
// DLL binds the DAT_ names to the exe by their symbols rows (a second /alternatename would conflict).
#ifndef MS2_HOOK_DLL
//
//
//
//
//
//
//
//
#endif
#ifdef MS2_HOOK_DLL
extern ExeDecl<void*>::type DAT_1431b53c0;
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" void (*const __identifier("??_7?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@")[])();
#define DAT_1431b53c0 (*(ExeDecl<void*>::type*)__identifier("??_7?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@"))
#endif
#define NetStreamPrototypeVtable DAT_1431b53c0
#ifdef MS2_HOOK_DLL
extern ExeDecl<void*>::type DAT_1431b5310;
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" void (*const __identifier("??_7?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@")[])();
#define DAT_1431b5310 (*(ExeDecl<void*>::type*)__identifier("??_7?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@"))
#endif
#define NetStreamPrototypeInterfaceVtable DAT_1431b5310
#ifdef MS2_HOOK_DLL
extern ExeDecl<void*>::type DAT_1431b5300;
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" void (*const __identifier("??_7?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@")[])();
#define DAT_1431b5300 (*(ExeDecl<void*>::type*)__identifier("??_7?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@"))
#endif
#define NetStreamPrototypeBaseVtable DAT_1431b5300
extern ExeDecl<Scaleform::GFx::AS2::NameFunction>::type DAT_1431b4d80[];   // NetStreamProto's function table (5 entries + { 0, 0 })
#define NetStreamCloseFunctionTable DAT_1431b4d80

extern void FUN_14257dcb0(void*);
extern void FUN_14257dcd0(void*);
extern void FUN_14000b3b0(Scaleform::UPInt*, void*, Scaleform::UPInt);
extern void FUN_14000a5d0(void*, Scaleform::GFx::AS2::ASRefCountBaseType::Collector*);
extern void FUN_14000a230(void*, Scaleform::GFx::AS2::ASRefCountBaseType::Collector*);
extern void FUN_14000a420(void*, Scaleform::GFx::AS2::ASRefCountBaseType::Collector*);
extern void FUN_14000a730(void*, Scaleform::GFx::AS2::ASRefCountBaseType::Collector*, int);
extern void FUN_14000b6e0(Scaleform::UPInt*, void*, const unsigned*, Scaleform::UPInt);
extern void FUN_14000b9e0(Scaleform::UPInt*, void*, void**, Scaleform::UPInt);
extern unsigned* FUN_1400079b0(unsigned*, const unsigned*);
extern void FUN_140007870(unsigned*, void**);
extern void FUN_140010a30(Scaleform::GFx::Video::VideoCharacter*);

struct Video01GcAccess : Scaleform::GFx::AS2::RefCountBaseGC<323>
{
    using Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal;
};

struct Video01HandleAccess : Scaleform::GFx::DisplayObject
{
    using Scaleform::GFx::DisplayObject::CreateCharacterHandle;
};

struct NetStreamPrototypeInitAccess : Scaleform::GFx::AS2::GASPrototypeBase
{
    using GASPrototypeBase::InitFunctionMembers;
    using GASPrototypeBase::Init;
};

static void ReleaseAs2GCObject(void* object)
{
    if (!object) return;
    unsigned* count = reinterpret_cast<unsigned*>(static_cast<unsigned char*>(object) + 0x18);
    const unsigned value = *count;
    if ((value & 0x03ffffff) != 0) {
        *count = value - 1;
        reinterpret_cast<Video01GcAccess*>(object)->ReleaseInternal();
    }
}

struct VideoFinalizeAccess : Scaleform::GFx::AS2::Object
{
    using Object::Finalize_GC;
};

static Scaleform::UPInt VideoHashKey4(const void* key)
{
    const unsigned char* bytes = static_cast<const unsigned char*>(key);
    Scaleform::UPInt hash = 0x1505;
    for (int i = 3; i >= 0; --i) hash = hash * 0x1003f + bytes[i];
    return hash;
}

static __forceinline Scaleform::UPInt VideoHashKeyInline(const void* key, Scaleform::UPInt size)
{
    const unsigned char* bytes = static_cast<const unsigned char*>(key);
    Scaleform::UPInt hash = 0x1505;
    do {
        --size;
        hash = hash * 0x1003f + bytes[size];
    } while (size);
    return hash;
}

static __forceinline void CopyConstructVideoHashEntry(Scaleform::UPInt* destination, Scaleform::UPInt next,
                                                       const Scaleform::UPInt* value)
{
    if (destination) {
        destination[0] = next;
        *reinterpret_cast<unsigned*>(destination + 1) = *reinterpret_cast<const unsigned*>(value);
        unsigned char* object = reinterpret_cast<unsigned char*>(value[1]);
        if (object) {
            unsigned* count = reinterpret_cast<unsigned*>(object + 0x18);
            *count = (*count + 1) & 0x8fffffff;
        }
        destination[2] = value[1];
    }
}

// HashSetBase::add shape: an empty home slot is constructed in place; otherwise the home entry is copied to the
// next free slot and reassigned, relinking its chain when it sat there from another bucket.
template<class ConstructEntry, class AssignEntry>
static __forceinline void InsertVideoHashEntry(Scaleform::UPInt* tableRef, void* owner, const void* key,
                                 Scaleform::UPInt hash, ConstructEntry constructEntry, AssignEntry assignEntry)
{
    void** tableSlot = reinterpret_cast<void**>(tableRef);
    Scaleform::UPInt*& pTable = *reinterpret_cast<Scaleform::UPInt**>(tableRef);
    if (pTable == 0) FUN_14000b3b0(tableRef, owner, 8);
    else if (pTable[0] * 5 > (pTable[1] + 1) * 4)
        FUN_14000b3b0(tableRef, owner, (pTable[1] + 1) * 2);
    Scaleform::UPInt* table = static_cast<Scaleform::UPInt*>(*tableSlot);
    table[0]++;
    const Scaleform::UPInt home = hash & table[1];
    table = static_cast<Scaleform::UPInt*>(*tableSlot);
    Scaleform::UPInt* entries = table + 2;
    Scaleform::UPInt* homeEntry = entries + home * 3;
    const Scaleform::UPInt homeNext = homeEntry[0];
    if (homeNext == ~Scaleform::UPInt(1)) {
        homeEntry[0] = ~Scaleform::UPInt(0);
        constructEntry(homeEntry + 1, key);
        return;
    }
    const Scaleform::UPInt* homeValue = homeEntry + 1;
    const Scaleform::UPInt mask = table[1];
    Scaleform::UPInt freeIndex = home;
    do {
        freeIndex = (freeIndex + 1) & mask;
    } while (entries[freeIndex * 3] != ~Scaleform::UPInt(1));
    Scaleform::UPInt* freeEntry = entries + freeIndex * 3;
    if ((VideoHashKeyInline(homeValue, 4) & mask) == home) {
        CopyConstructVideoHashEntry(freeEntry, homeNext, homeValue);
        assignEntry(const_cast<Scaleform::UPInt*>(homeValue), key);
        homeEntry[0] = freeIndex;
    } else {
        Scaleform::UPInt* previous = entries + (VideoHashKeyInline(homeValue, 4) & mask) * 3;
        while (previous[0] != home) previous = entries + previous[0] * 3;
        CopyConstructVideoHashEntry(freeEntry, homeNext, homeValue);
        previous[0] = freeIndex;
        assignEntry(const_cast<Scaleform::UPInt*>(homeValue), key);
        homeEntry[0] = ~Scaleform::UPInt(0);
    }
}

static void ConstructVideoHashFromValue(Scaleform::UPInt* destination, const void* source)
{
    const unsigned* value = static_cast<const unsigned*>(source);
    *reinterpret_cast<unsigned*>(destination) = *value;
    unsigned char* object = *reinterpret_cast<unsigned char* const*>(value + 2);
    if (object) {
        unsigned* count = reinterpret_cast<unsigned*>(object + 0x18);
        *count = (*count + 1) & 0x8fffffff;
    }
    destination[1] = *reinterpret_cast<const Scaleform::UPInt*>(value + 2);
}

static void ConstructVideoHashFromPair(Scaleform::UPInt* destination, const void* source)
{
    void* const* pair = static_cast<void* const*>(source);
    *reinterpret_cast<unsigned*>(destination) = *static_cast<const unsigned*>(pair[0]);
    const Scaleform::UPInt* objectSlot = static_cast<const Scaleform::UPInt*>(pair[1]);
    unsigned char* object = reinterpret_cast<unsigned char*>(*objectSlot);
    if (object) {
        unsigned* count = reinterpret_cast<unsigned*>(object + 0x18);
        *count = (*count + 1) & 0x8fffffff;
    }
    destination[1] = *objectSlot;
}

static void CopyVideoHashValue(Scaleform::UPInt* destination, const void* source)
{
    FUN_1400079b0(reinterpret_cast<unsigned*>(destination), static_cast<const unsigned*>(source));
}

static void CopyVideoHashPair(Scaleform::UPInt* destination, const void* source)
{
    FUN_140007870(reinterpret_cast<unsigned*>(destination), const_cast<void**>(static_cast<void* const*>(source)));
}

// The sound channel a video sound stream holds at +0x10; only the slots these wrappers call are named
struct VideoSoundStreamChannel
{
    virtual void Slot0(); virtual void Slot1(); virtual void Slot2(); virtual void Slot3(); virtual void Slot4();
    virtual void Start();                   // +0x28
    virtual void Slot6(); virtual void Slot7(); virtual void Slot8(); virtual void Slot9();
    virtual void Stop();                    // +0x50
    virtual void SetVolume(float volume);   // +0x58
};
struct VideoSoundStreamState
{
    void* vtable;
    void* unknown8;
    VideoSoundStreamChannel* pChannel;   // +0x10
    float Volume;                        // +0x18
};

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// forwards the video sound stream's channel attachment callback when a channel is present.
// @0x140002930
void FUN_140002930(void* object)
{
    VideoSoundStreamState* stream = static_cast<VideoSoundStreamState*>(object);
    if (stream->pChannel) stream->pChannel->Start();
}

// stores the stream volume and passes it on to the attached channel.
// BEHAVIOUR FIX: the volume is a float (xmm1, movss [rcx+18h]); it was taken as an unsigned from edx, so +0x18 held junk.
// @0x140002960
void FUN_140002960(void* object, float volume)
{
    VideoSoundStreamState* stream = static_cast<VideoSoundStreamState*>(object);
    stream->Volume = volume;
    VideoSoundStreamChannel* channel = stream->pChannel;
    if (channel) channel->SetVolume(volume);
}

// forwards the stop notification when the stream has an attached channel.
// @0x140002980
void FUN_140002980(void* object)
{
    VideoSoundStreamState* stream = static_cast<VideoSoundStreamState*>(object);
    if (stream->pChannel) stream->pChannel->Stop();
}
#pragma optimize("", on)

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases the currently retained audio channel if one is assigned.
// @0x1400029d0
void FUN_1400029d0(void** channel)
{
    if (*channel) FUN_14257dcb0(*channel);
}
#pragma optimize("", on)

// returns the terminated byte string length (the intrinsic strlen: repne scasb).
// @0x140002f70
#pragma intrinsic(strlen)
Scaleform::UPInt FUN_140002f70(const char* text)
{
    return strlen(text);
}

// replaces the retained audio channel after releasing its previous value.
// @0x1400029f0
void** FUN_1400029f0(void** channel, void* replacement)
{
    if (*channel) FUN_14257dcb0(*channel);
    *channel = replacement;
    return channel;
}

// detaches the sound channel from the stream and tears down the video sound base. The exe clears the channel's
// back-pointer without a null test, then releases the Ptr member (null-tested).
// @0x140002ab0
Scaleform::GFx::Video::VideoSoundStream::~VideoSoundStream()
{
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(pChannel.GetPtr()) + 0x10) = 0;
}
//
//
//
//
//

// the stream's sound channel.
// @0x140002b00
Scaleform::Sound::SoundChannel* Scaleform::GFx::Video::VideoSoundStream::GetSoundChannel() { return pChannel.GetPtr(); }

// initializes the refcounted stream and allocates its SoundChannelSystem back-reference; the inlined
// channel ctor keeps the RefCountImplCore base vftable store, so that store is volatile here.
// @0x140002e80
Scaleform::GFx::Video::VideoSoundStream::VideoSoundStream()
{
    void* stream = this;
    unsigned char* bytes = static_cast<unsigned char*>(stream);   // (RefCount 1 at +8, the vftable, the null pChannel:
    // the base, vptr and member inits)
    void** channelSlot = reinterpret_cast<void**>(bytes + 0x10);
//
    void** heapVtable = *reinterpret_cast<void***>(Scaleform::Memory::pGlobalHeap);
    void* mem = reinterpret_cast<void* (*)(void*, Scaleform::UPInt, const void*)>(heapVtable[10])(Scaleform::Memory::pGlobalHeap, 0x20, 0);
    void* channel;
    if (mem) {
        unsigned char* channelBytes = static_cast<unsigned char*>(mem);
        ::new (mem) Scaleform::RefCountImplCore;
        *reinterpret_cast<void**>(channelBytes + 0x10) = stream;
        *reinterpret_cast<float*>(channelBytes + 0x18) = 1.0f;
        *reinterpret_cast<void***>(channelBytes) = &VideoSoundChannelSystemVtable;
        channel = mem;
    } else {
        channel = 0;
    }
    if (*channelSlot) FUN_14257dcb0(*channelSlot);
    *channelSlot = channel;
//
}

// (0x140002e80 / 0x140002ab0 above are VideoSoundStream's ctor and dtor; video_video.h declares the class.)
//
//
//
//
//
//

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// stores the ready flag and forwards the state update to the active player.
// @0x140003580
void FUN_140003580(void* player, bool ready)
{
    unsigned char* bytes = static_cast<unsigned char*>(player);
    bytes[0xc0] = ready;
    void* impl = *reinterpret_cast<void**>(bytes + 0x48);
    if (impl) reinterpret_cast<void (*)(void*, bool)>((*reinterpret_cast<void***>(impl))[21])(impl, ready);
}
#pragma optimize("", on)

// a view of the player wrapper's active implementation (+0x48) and its vftable slots
struct VideoPlayerImplView
{
    virtual void Slot0(); virtual void Slot1(); virtual void Slot2(); virtual void Slot3(); virtual void Slot4();
    virtual void Slot5(); virtual void Slot6(); virtual void Slot7(); virtual void Slot8(); virtual void Slot9();
    virtual void Slot10(); virtual void Slot11(); virtual void Slot12(); virtual void Slot13(); virtual void Slot14();
    virtual void Slot15(); virtual void Slot16(); virtual void Slot17(); virtual void Slot18(); virtual void Slot19();
    virtual void Slot20();
};
struct VideoPlayerOwnerView
{
    unsigned char Pad[0x48];
    VideoPlayerImplView* pImpl;
};
// a view of a NetStream's video provider (+0x68), whose player sits at +0x48 as in the wrapper above
struct VideoStreamProviderView
{
    unsigned char Pad[0x68];
    VideoPlayerOwnerView* pProvider;
};
// the same object with its member table (+0x110), as FUN_14000a3a0 finalizes it
struct VideoFinalizeView
{
    unsigned char Pad[0x68];
    VideoPlayerOwnerView* pProvider;
    unsigned char Pad2[0x110 - 0x70];
    void** pTable;
};

// forwards playback start to the active player implementation.
// @0x1400035b0
void FUN_1400035b0(void* player)
{
    VideoPlayerOwnerView* owner = static_cast<VideoPlayerOwnerView*>(player);
    if (owner->pImpl) owner->pImpl->Slot18();
}

// forwards playback stop to the active player implementation.
// @0x1400035d0
void FUN_1400035d0(void* player)
{
    VideoPlayerOwnerView* owner = static_cast<VideoPlayerOwnerView*>(player);
    if (owner->pImpl) owner->pImpl->Slot19();
}

// forwards seek to the active player implementation.
// @0x1400035f0
void FUN_1400035f0(void* player)
{
    VideoPlayerOwnerView* owner = static_cast<VideoPlayerOwnerView*>(player);
    if (owner->pImpl) owner->pImpl->Slot20();
}

// forwards the frame-ready request to the active player implementation.
// @0x140003610
void FUN_140003610(void* player)
{
    VideoPlayerOwnerView* owner = static_cast<VideoPlayerOwnerView*>(player);
    if (owner->pImpl) owner->pImpl->Slot7();
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// updates the reload threshold and notifies the active player.
// BEHAVIOUR FIX: the threshold is a float (movss [rcx+0C8h],xmm1); it was taken as an unsigned from edx and not
// passed on, so +0xc8 and the player's vfunc got junk.
// @0x140003650
void FUN_140003650(void* player, float threshold)
{
    unsigned char* bytes = static_cast<unsigned char*>(player);
    *reinterpret_cast<float*>(bytes + 0xc8) = threshold;
    void* impl = *reinterpret_cast<void**>(bytes + 0x48);
    if (impl) reinterpret_cast<void (*)(void*, float)>((*reinterpret_cast<void***>(impl))[22])(impl, threshold);
}
#pragma optimize("", on)

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// updates the pool count and notifies the active player.
// @0x140003680
void FUN_140003680(void* player, unsigned count)
{
    unsigned char* bytes = static_cast<unsigned char*>(player);
    *reinterpret_cast<unsigned*>(bytes + 0xc4) = count;
    void* impl = *reinterpret_cast<void**>(bytes + 0x48);
    if (impl) reinterpret_cast<void (*)(void*, unsigned)>((*reinterpret_cast<void***>(impl))[23])(impl, count);
}
#pragma optimize("", on)

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// updates buffer time and notifies the active player.
// @0x1400036b0
void FUN_1400036b0(void* player, float time)
{
    unsigned char* bytes = static_cast<unsigned char*>(player);
    *reinterpret_cast<float*>(bytes + 0xcc) = time;
    void* impl = *reinterpret_cast<void**>(bytes + 0x48);
    if (impl) reinterpret_cast<void (*)(void*, float)>((*reinterpret_cast<void***>(impl))[24])(impl, time);
}
#pragma optimize("", on)

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// updates the open timeout and notifies the active player.
// @0x1400036e0
void FUN_1400036e0(void* player, float timeout)
{
    unsigned char* bytes = static_cast<unsigned char*>(player);
    *reinterpret_cast<float*>(bytes + 0xd0) = timeout;
    void* impl = *reinterpret_cast<void**>(bytes + 0x48);
    if (impl) reinterpret_cast<void (*)(void*, float)>((*reinterpret_cast<void***>(impl))[26])(impl, timeout);
}
#pragma optimize("", on)

// forwards video information retrieval into the active player.
// @0x140003710
void FUN_140003710(void* player)
{
    VideoPlayerOwnerView* owner = static_cast<VideoPlayerOwnerView*>(player);
    if (owner->pImpl)
        reinterpret_cast<void (*)(void*, void*)>((*reinterpret_cast<void***>(owner->pImpl))[28])(owner->pImpl,
            static_cast<unsigned char*>(player) + 0xf0);
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases an owned Scaleform reference when present.
// @0x140003770
void FUN_140003770(void** value) { if (*value) FUN_14257dcb0(*value); }
#pragma optimize("", on)
#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases an owned Scaleform reference when present.
// @0x140003810
void FUN_140003810(void** value) { if (*value) FUN_14257dcb0(*value); }
#pragma optimize("", on)
#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases an owned Scaleform reference when present.
// @0x140003850
void FUN_140003850(void** value) { if (*value) FUN_14257dcb0(*value); }
#pragma optimize("", on)

// releases the previous interface and stores the retained replacement.
// @0x140003a70
void** FUN_140003a70(void** destination, void* replacement)
{
    if (replacement) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(replacement))[1])(replacement);
    if (*destination) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(*destination))[2])(*destination);
    *destination = replacement;
    return destination;
}

// releases and replaces a non-null interface slot without retaining the replacement.
// @0x140003ab0
void** FUN_140003ab0(void** destination, void* replacement)
{
    if (*destination) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(*destination))[2])(*destination);
    *destination = replacement;
    return destination;
}

// Initializes the player, timing, pool, timeout, and notification defaults observed in the constructor.
// @0x1400033f0
void FUN_1400033f0(void* player)
{
    unsigned char* bytes = static_cast<unsigned char*>(player);
    *reinterpret_cast<void**>(bytes + 0x48) = 0;
    memset(bytes + 0x50, 0, 0x50);
    *reinterpret_cast<float*>(bytes + 0xa8) = 1.0f / 12.0f;
    *reinterpret_cast<void**>(bytes + 0xb0) = 0;
    bytes[0xc0] = 0;
    *reinterpret_cast<unsigned*>(bytes + 0xc4) = 2;
    *reinterpret_cast<unsigned*>(bytes + 0xc8) = 0;
    *reinterpret_cast<float*>(bytes + 0xcc) = 0.8f;
    *reinterpret_cast<float*>(bytes + 0xd0) = 5.0f;
    *reinterpret_cast<unsigned*>(bytes + 0xd4) = 0;
    bytes[0xd8] = 0;
    bytes[0xd9] = 0;
    bytes[0xda] = 0;
    bytes[0xdb] = 1;
    bytes[0xdc] = 0;
    *reinterpret_cast<void**>(bytes + 0xe8) = 0;
    *reinterpret_cast<void**>(bytes + 0xe0) = 0;
}

// creates a managed AS2 string and stores its retained node in the return object.
// @0x140003000
Scaleform::GFx::ASString* FUN_140003000(Scaleform::GFx::ASStringManager* manager,
                                         Scaleform::GFx::ASString* result, const char* text)
{
    Scaleform::GFx::ASStringNode* node = manager->CreateStringNode(text);
    *reinterpret_cast<Scaleform::GFx::ASStringNode**>(result) = node;
    node->AddRef();
    return result;
}

// creates a constant AS2 string node over the supplied terminated text.
// @0x140003020
Scaleform::GFx::ASString* FUN_140003020(Scaleform::GFx::ASStringManager* manager,
                                         Scaleform::GFx::ASString* result, const char* text)
{
    Scaleform::GFx::ASStringNode* node = manager->CreateConstStringNode(text, strlen(text), 0);
    *reinterpret_cast<Scaleform::GFx::ASStringNode**>(result) = node;
    node->AddRef();
    return result;
}

// creates an owned AS2 string from the context's movie string manager.
// @0x1400038f0
Scaleform::GFx::ASString* FUN_1400038f0(Scaleform::GFx::AS2::Environment* environment,
                                         Scaleform::GFx::ASString* result, const char* text)
{
    Scaleform::GFx::ASStringManager* manager =
        reinterpret_cast<Scaleform::GFx::AS2::StringManager*>(environment)->pStringManager;
    Scaleform::GFx::ASStringNode* node = manager->CreateConstStringNode(text, strlen(text), 0);
    *reinterpret_cast<Scaleform::GFx::ASStringNode**>(result) = node;
    node->AddRef();
    return result;
}

// creates an owned AS2 string from the context's movie string manager.
// @0x140003940
Scaleform::GFx::ASString* FUN_140003940(Scaleform::GFx::AS2::Environment* environment,
                                         Scaleform::GFx::ASString* result, const char* text)
{
    Scaleform::GFx::ASStringManager* manager =
        reinterpret_cast<Scaleform::GFx::AS2::StringManager*>(environment)->pStringManager;
    Scaleform::GFx::ASStringNode* node = manager->CreateStringNode(text);
    *reinterpret_cast<Scaleform::GFx::ASStringNode**>(result) = node;
    node->AddRef();
    return result;
}

// looks up the selected movie string manager for a built-in table index.
// @0x1400043e0
Scaleform::GFx::ASStringNodeHolder* FUN_1400043e0(Scaleform::GFx::AS2::Environment* environment, int index)
{
    Scaleform::GFx::AS2::GlobalContext* context = *reinterpret_cast<Scaleform::GFx::AS2::GlobalContext**>(
        reinterpret_cast<unsigned char*>(environment) + 0xe8);
    return &context->GetStringManager()->Builtins[index];
}

// selects a built-in string manager within the environment's global context.
// @0x1400044e0
Scaleform::GFx::ASStringNodeHolder* FUN_1400044e0(Scaleform::GFx::AS2::GlobalContext** context, int index)
{
    return &(*context)->GetStringManager()->Builtins[index];
}

// creates an owned AS2 string through the selected movie string manager.
// @0x140004400
Scaleform::GFx::ASString* FUN_140004400(Scaleform::GFx::AS2::Environment* environment,
                                         Scaleform::GFx::ASString* result, const char* text)
{
    Scaleform::GFx::ASStringManager* manager =
        environment->StringContext.pContext->GetStringManager()->pStringManager;
    Scaleform::GFx::ASStringNode* node = manager->CreateStringNode(text);
    node->AddRef();
    *reinterpret_cast<Scaleform::GFx::ASStringNode**>(result) = node;
    return result;
}

// creates a constant AS2 string through the selected movie string manager.
// @0x140004440
Scaleform::GFx::ASString* FUN_140004440(Scaleform::GFx::AS2::Environment* environment,
                                         Scaleform::GFx::ASString* result, const char* text)
{
    Scaleform::GFx::ASStringManager* manager =
        environment->StringContext.pContext->GetStringManager()->pStringManager;
    Scaleform::GFx::ASStringNode* node = manager->CreateConstStringNode(text, strlen(text), 0);
    node->AddRef();
    *reinterpret_cast<Scaleform::GFx::ASStringNode**>(result) = node;
    return result;
}

// creates a constant AS2 string through the global context's movie string manager.
// @0x140004500
Scaleform::GFx::ASString* FUN_140004500(Scaleform::GFx::AS2::GlobalContext** context,
                                         Scaleform::GFx::ASString* result, const char* text)
{
    Scaleform::GFx::AS2::StringManager* strings = (*context)->GetStringManager();
    // the exe builds the ASString in place with no null test on the result slot
    Scaleform::GFx::ASStringManager* manager = strings->pStringManager;
    Scaleform::GFx::ASStringNode* node = manager->CreateConstStringNode(text, strlen(text), 0);
    node->AddRef();
    *reinterpret_cast<Scaleform::GFx::ASStringNode**>(result) = node;
    return result;
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases the weak reference proxy held by this slot.
// @0x140003b20
void FUN_140003b20(void** proxy) { if (*proxy) FUN_14257dcd0(*proxy); }
#pragma optimize("", on)

// replaces the weak reference proxy after releasing its prior proxy.
// @0x140003b40
void** FUN_140003b40(void** proxy, void* replacement)
{
    if (*proxy) FUN_14257dcd0(*proxy);
    *proxy = replacement;
    return proxy;
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases the weak reference proxy held by this slot.
// @0x140003c00
void FUN_140003c00(void** proxy) { if (*proxy) FUN_14257dcd0(*proxy); }
#pragma optimize("", on)

// retains the replacement proxy before releasing the current proxy.
// @0x140003c20
void** FUN_140003c20(void** proxy, void* replacement)
{
    if (replacement) ++*reinterpret_cast<int*>(static_cast<unsigned char*>(replacement) + 8);
    if (*proxy) FUN_14257dcd0(*proxy);
    *proxy = replacement;
    return proxy;
}

// replaces the weak reference proxy after releasing its prior proxy.
// @0x140003c70
void** FUN_140003c70(void** proxy, void* replacement)
{
    if (*proxy) FUN_14257dcd0(*proxy);
    *proxy = replacement;
    return proxy;
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases a weak reference proxy when the slot is populated.
// @0x140003d10
void FUN_140003d10(void** proxy) { if (*proxy) FUN_14257dcd0(*proxy); }
#pragma optimize("", on)
#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases a weak reference proxy when the slot is populated.
// @0x140003da0
void FUN_140003da0(void** proxy) { if (*proxy) FUN_14257dcd0(*proxy); }
#pragma optimize("", on)

// returns the display object's character handle, creating and retaining it on first use.
// @0x140004310
void* FUN_140004310(void* object)
{
    void* handle = *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x70);
    if (!handle) handle = reinterpret_cast<Video01HandleAccess*>(object)->CreateCharacterHandle();
    return handle;
}

// retrieves the display object's character type into the caller's output slot.
// @0x140004330
void** FUN_140004330(void** character, void** result)
{
    *result = reinterpret_cast<void* (*)(void*, unsigned)>((*reinterpret_cast<void***>(character))[3])(character, 0x1e);
    return result;
}

// retrieves the display object's subtype into the caller's output slot.
// @0x140004350
void** FUN_140004350(void** character, void** result)
{
    *result = reinterpret_cast<void* (*)(void*, unsigned)>((*reinterpret_cast<void***>(character))[3])(character, 0xb);
    return result;
}

// forwards the action to refresh the active player implementation.
// @0x140004600
void FUN_140004600(void* object)
{
    VideoPlayerOwnerView* owner = *reinterpret_cast<VideoPlayerOwnerView**>(static_cast<unsigned char*>(object) + 0x68);
    if (owner->pImpl) owner->pImpl->Slot14();
}

#pragma optimize("t", off)   // the exe builds these favouring size: frame + call, no tail call
// BEHAVIOUR FIX (0x140004650..0x1400046e0): each setter passes the stored value on to the player's vfunc (xmm1, or edx
// for the frame-pool count), as the exe does; the calls had no value argument, so the player read a junk register.
// stores the reload-threshold value and forwards it to the active player.
// @0x140004650
void FUN_140004650(void* object, double threshold)
{
    unsigned char* owner = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x68);
    void* impl = *reinterpret_cast<void**>(owner + 0x48);
    const float value = static_cast<float>(threshold);
    *reinterpret_cast<float*>(owner + 0xc8) = value;
    if (impl) reinterpret_cast<void (*)(void*, float)>((*reinterpret_cast<void***>(impl))[22])(impl, value);
}

// updates the frame-pool count on the NetStream's player and forwards the new value.
// @0x140004680
void FUN_140004680(void* object, double count)
{
    unsigned char* owner = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x68);
    void* impl = *reinterpret_cast<void**>(owner + 0x48);
    const unsigned value = static_cast<unsigned>(count);
    *reinterpret_cast<unsigned*>(owner + 0xc4) = value;
    if (impl) reinterpret_cast<void (*)(void*, unsigned)>((*reinterpret_cast<void***>(impl))[23])(impl, value);
}

// updates buffer time on the NetStream's player and forwards it.
// @0x1400046b0
void FUN_1400046b0(void* object, double time)
{
    unsigned char* owner = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x68);
    void* impl = *reinterpret_cast<void**>(owner + 0x48);
    const float value = static_cast<float>(time);
    *reinterpret_cast<float*>(owner + 0xcc) = value;
    if (impl) reinterpret_cast<void (*)(void*, float)>((*reinterpret_cast<void***>(impl))[24])(impl, value);
}

// updates the open timeout on the NetStream's player and forwards it.
// @0x1400046e0
void FUN_1400046e0(void* object, double timeout)
{
    unsigned char* owner = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x68);
    void* impl = *reinterpret_cast<void**>(owner + 0x48);
    const float value = static_cast<float>(timeout);
    *reinterpret_cast<float*>(owner + 0xd0) = value;
    if (impl) reinterpret_cast<void (*)(void*, float)>((*reinterpret_cast<void***>(impl))[26])(impl, value);
}
#pragma optimize("", on)

// forwards a seek position to the active player implementation.
// @0x140004710
void FUN_140004710(void* object, double position)
{
    VideoPlayerOwnerView* owner = *reinterpret_cast<VideoPlayerOwnerView**>(static_cast<unsigned char*>(object) + 0x68);
    if (owner->pImpl)
        reinterpret_cast<void (*)(void*, int)>((*reinterpret_cast<void***>(owner->pImpl))[7])(owner->pImpl, static_cast<int>(position));
}

// forwards the video-info request to the active player with the stored output buffer.
// @0x140004770
void FUN_140004770(void* object)
{
    VideoPlayerOwnerView* owner = *reinterpret_cast<VideoPlayerOwnerView**>(static_cast<unsigned char*>(object) + 0x68);
    if (owner->pImpl)
        reinterpret_cast<void (*)(void*, void*)>((*reinterpret_cast<void***>(owner->pImpl))[28])(owner->pImpl,
            reinterpret_cast<unsigned char*>(owner) + 0xf0);
}

// builds the three-field URL location value using owned copies of the two strings.
// @0x140004290
Scaleform::GFx::URLBuilder::LocationInfo* FUN_140004290(
    Scaleform::GFx::URLBuilder::LocationInfo* location, Scaleform::GFx::URLBuilder::FileUse use,
    const Scaleform::String& filename, const Scaleform::String& parentPath)
{
    __assume(location != 0);   // cl 17.00 null-checks a placement new; the exe's (the inline constructor) has none
    return new (location) Scaleform::GFx::URLBuilder::LocationInfo(use, filename, parentPath);
}

// destroys a character handle and frees its allocation when requested.
// @0x1400042d0
Scaleform::GFx::CharacterHandle* FUN_1400042d0(Scaleform::GFx::CharacterHandle* handle, unsigned flags)
{
    handle->~CharacterHandle();
    if (flags & 1) Scaleform::Memory::Free(handle);
    return handle;
}

// the LogBase<FnCall> deleting destructor: its inline dtor only restores the 0x1431b4de0 vftable.
// @0x1400043b0
Scaleform::GFx::AS2::FnCall* FUN_1400043b0(Scaleform::GFx::AS2::FnCall* call, unsigned flags)
{
    call->Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::~LogBase();
    if (flags & 1) operator delete(call);
    return call;
}

// releases the owned proxy at this weak-pointer slot when present.
// @0x1400045c0
void** FUN_1400045c0(void** proxy, unsigned flags)
{
    if (*proxy) FUN_14257dcd0(*proxy);
    if (flags & 1) operator delete(proxy);
    return proxy;
}

// @0x140004dd0
void FUN_140004dd0(void** value) { if (*value) static_cast<Scaleform::WeakPtrProxy*>(*value)->Release(); }

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// frees the object held by the first pointer slot when non-null.
// @0x140004e50
void FUN_140004e50(void** value) { if (*value) Scaleform::Memory::Free(*value); }
#pragma optimize("", on)

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// frees the object held by the first pointer slot when non-null.
// @0x140004e90
void FUN_140004e90(void** value) { if (*value) Scaleform::Memory::Free(*value); }
#pragma optimize("", on)

// obtains the live object behind a weak proxy, clearing an expired proxy slot. The exe compares pObject in
// memory and reloads it, so the second read is volatile.
#undef GetObject // wingdi.h, and WeakPtrProxy::GetObject is what these rows read
// @0x140005000
void* FUN_140005000(void** weakSlot)
{
    void* object = 0;
    Scaleform::WeakPtrProxy* proxy = static_cast<Scaleform::WeakPtrProxy*>(*weakSlot);
    if (proxy) {
        if (proxy->IsAlive()) {
            object = *reinterpret_cast<void* volatile*>(reinterpret_cast<unsigned char*>(proxy) + 8);
            if (*reinterpret_cast<int*>(static_cast<unsigned char*>(object) + 8) == 0) object = 0;
        } else {
            proxy->Release();
            *weakSlot = 0;
        }
    }
    return object;
}

// 0x1400050c0 is the SDK ArrayDataBase<T, AllocatorLH<T, 2>, ArrayDefaultPolicy>::Reserve for an 8-byte T. Its exact
// copy for void* is the separately linked 0x1423d95f0, so this unit instantiates it for a local 8-byte stand-in.
struct Video01LHSlot { void* p; };
static __forceinline void Video01ReserveLH(void** array, const void* heapOwner, Scaleform::UPInt requested)
{
    typedef Video01LHSlot T;
    reinterpret_cast<Scaleform::ArrayDataBase<T, Scaleform::AllocatorLH<T, 2>, Scaleform::ArrayDefaultPolicy>*>(array)->Reserve(heapOwner, requested);
}
// MS2-PIN: ?Reserve@?$ArrayDataBase@UVideo01LHSlot@@U?$AllocatorLH@UVideo01LHSlot@@$01@Scaleform@@UArrayDefaultPolicy@3@@Scaleform@@QEAAXPEBX_K@Z 0x1400050c0 ; unique
//
//
//
//
//
//
//
//
//
//
//
//
//

// @0x140005160
void FUN_140005160(void** array, void* heapOwner, Scaleform::UPInt size)
{
    if (size < reinterpret_cast<Scaleform::UPInt>(array[1])) {
        if (size < (reinterpret_cast<Scaleform::UPInt>(array[2]) >> 1)) Video01ReserveLH(array, heapOwner, size);
    } else if (size >= reinterpret_cast<Scaleform::UPInt>(array[2])) {
        Video01ReserveLH(array, heapOwner, size + (size >> 2));
    }
    array[1] = reinterpret_cast<void*>(size);
}

// ArrayDataBase<T, AllocatorGH<T, 2>, ArrayDefaultPolicy>::Reserve for a sizeof(T) of Size, inlined into each row.
template<Scaleform::UPInt Size>
static __forceinline void Video01Reserve(void** array, Scaleform::UPInt newCapacity)
{
    typedef Scaleform::AllocatorBaseGH<2> Allocator;
    if (newCapacity == 0) {
        if (array[0]) { Allocator::Free(array[0]); array[0] = 0; }
        array[2] = 0;
    } else {
        newCapacity = (newCapacity + 3) / 4 * 4;
        if (array[0]) array[0] = Allocator::Realloc(array[0], newCapacity * Size, 0, 0);
        else array[0] = Allocator::Alloc(array, newCapacity * Size, 0, 0);
        array[2] = reinterpret_cast<void*>(newCapacity);
    }
}

// The audio-track (0x1400051c0) and sound-vector (0x140005260) arrays reserve through the SDK's own
// ArrayDataBase<T, AllocatorGH<T, 2>, ArrayDefaultPolicy>::Reserve, called out of line.
static __forceinline void Video01ReserveAudioTracks(void** array, void* owner, Scaleform::UPInt requested)
{
    typedef Scaleform::GFx::Video::VideoPlayer::AudioTrackInfo T;
    reinterpret_cast<Scaleform::ArrayDataBase<T, Scaleform::AllocatorGH<T, 2>, Scaleform::ArrayDefaultPolicy>*>(array)
        ->Reserve(owner, requested);
}

static __forceinline void Video01ReserveVectors(void** array, void* owner, Scaleform::UPInt requested)
{
    typedef Scaleform::Sound::SoundChannel::Vector T;
    reinterpret_cast<Scaleform::ArrayDataBase<T, Scaleform::AllocatorGH<T, 2>, Scaleform::ArrayDefaultPolicy>*>(array)
        ->Reserve(owner, requested);
}

// Releases a character handle when its intrusive reference count reaches zero.
// @0x140005480
void FUN_140005480(Scaleform::GFx::CharacterHandle* handle)
{
    if (--*reinterpret_cast<int*>(handle) <= 0) {
        handle->~CharacterHandle();
        Scaleform::Memory::Free(handle);
    }
}

// @0x140005660
void FUN_140005660(void** value) { if (*value) static_cast<Scaleform::WeakPtrProxy*>(*value)->Release(); }

// clears the provider's pending notification and requests the active player to stop.
// @0x140005690
void FUN_140005690(void* stream)
{
    VideoStreamProviderView* view = static_cast<VideoStreamProviderView*>(stream);
    if (view->pProvider) {
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(view->pProvider) + 0x18) = 0;
        VideoPlayerOwnerView* provider = view->pProvider;
        if (provider->pImpl) provider->pImpl->Slot14();
    }
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases the owned player-side allocation.
// @0x140005760
void FUN_140005760(void** value) { if (*value) Scaleform::Memory::Free(*value); }
#pragma optimize("", on)

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases the owned player-side allocation.
// @0x140005830
void FUN_140005830(void** value) { if (*value) Scaleform::Memory::Free(*value); }
#pragma optimize("", on)

// @0x140005870
void FUN_140005870(void** value) { if (*value) static_cast<Scaleform::WeakPtrProxy*>(*value)->Release(); }

// destroys a weak-support object and conditionally frees its storage.
// @0x1400058c0
Scaleform::RefCountWeakSupportImpl* FUN_1400058c0(Scaleform::RefCountWeakSupportImpl* value, unsigned flags)
{
    value->RefCountWeakSupportImpl::~RefCountWeakSupportImpl();
    if (flags & 1) Scaleform::Memory::Free(value);
    return value;
}

// releases a character-handle reference (Ptr<CharacterHandle> dtor).
// @0x140005900
void FUN_140005900(Scaleform::GFx::CharacterHandle** value)
{
    if (*value) (*value)->Release();
}

// retains the replacement character handle before releasing the previous one.
// @0x140005940
void** FUN_140005940(void** destination, Scaleform::GFx::CharacterHandle* replacement)
{
    if (replacement) ++*reinterpret_cast<int*>(replacement);
    Scaleform::GFx::CharacterHandle* old = static_cast<Scaleform::GFx::CharacterHandle*>(*destination);
    if (old && --*reinterpret_cast<int*>(old) <= 0) {
        old->~CharacterHandle();
        Scaleform::Memory::Free(old);
    }
    *destination = replacement;
    return destination;
}

// locks a weak proxy into a retained strong object reference (SDK WeakPtr::GetObjectThroughProxy + Ptr ctor).
// The exe compares pObject in memory and reloads it, so the second read is volatile.
// @0x1400059b0
void** FUN_1400059b0(void** weakSlot, void** result)
{
    Scaleform::RefCountWeakSupportImpl* pobject = 0;
    Scaleform::WeakPtrProxy* proxy = static_cast<Scaleform::WeakPtrProxy*>(*weakSlot);
    if (proxy) {
        if (proxy->IsAlive()) {
            pobject = *reinterpret_cast<Scaleform::RefCountWeakSupportImpl* volatile*>(reinterpret_cast<unsigned char*>(proxy) + 8);
            if (pobject->GetRefCount() == 0)
                pobject = 0;
        } else {
            proxy->Release();
            *weakSlot = 0;
        }
    }
    if (pobject) pobject->AddRef();
    *result = pobject;
    return result;
}

// @0x140005a70
void** FUN_140005a70(void** weakSlot, unsigned flags)
{
    if (*weakSlot) static_cast<Scaleform::WeakPtrProxy*>(*weakSlot)->Release();
    if (flags & 1) operator delete(weakSlot);
    return weakSlot;
}

// the ArrayData the rows below append to.
struct Video01ArrayData { void* Data; Scaleform::UPInt Size; Scaleform::UPInt Capacity; };

// the SDK ArrayData::Resize the append inlines.
static __forceinline void Video01ResizePointers(void** array, Scaleform::UPInt size)
{
    Video01ArrayData* data = reinterpret_cast<Video01ArrayData*>(array);
    if (size < data->Size) { if (size < data->Capacity >> 1) Video01ReserveLH(array, array, size); }
    else if (size >= data->Capacity) Video01ReserveLH(array, array, size + (size >> 2));
    data->Size = size;
}

// Appends one pointer value to the backing array, growing capacity when needed (the volatile first Size read keeps the exe's reload compare).
// @0x140005ac0
void FUN_140005ac0(void** array, const void** value)
{
    Video01ArrayData* data = reinterpret_cast<Video01ArrayData*>(array);
    Video01ResizePointers(array, *reinterpret_cast<const volatile Scaleform::UPInt*>(&data->Size) + 1);
    const void** slot = static_cast<const void**>(data->Data) + data->Size - 1;
    if (slot) *slot = *value;
}

// adjusts the 16-byte record array using its quarter-growth and half-shrink thresholds.
// @0x140005b40
void FUN_140005b40(void** array, void* owner, Scaleform::UPInt size)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    if (size < fields[1]) { if (size < fields[2] / 2) Video01ReserveAudioTracks(array, owner, size); }
    else if (size >= fields[2]) Video01ReserveAudioTracks(array, owner, size + (size >> 2));
    fields[1] = size;
}

// adjusts the 12-byte record array using its quarter-growth and half-shrink thresholds.
// @0x140005ba0
void FUN_140005ba0(void** array, void* owner, Scaleform::UPInt size)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    if (size < fields[1]) { if (size < fields[2] / 2) Video01ReserveVectors(array, owner, size); }
    else if (size >= fields[2]) Video01ReserveVectors(array, owner, size + (size >> 2));
    fields[1] = size;
}

// adjusts the pointer array capacity using four-element rounding and the observed thresholds.
// @0x140005c20
void FUN_140005c20(void** array, Scaleform::UPInt size)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    if (size < fields[1]) { if (size < fields[2] / 2) Video01ReserveLH(array, array, size); }
    else if (size >= fields[2]) Video01ReserveLH(array, array, size + (size >> 2));
    fields[1] = size;
}

// resizes the 12-byte record array and clears each newly exposed record.
// @0x140005ca0
void FUN_140005ca0(void** array, Scaleform::UPInt size)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    const Scaleform::UPInt oldSize = fields[1];
    if (size < oldSize) { if (size < fields[2] / 2) Video01ReserveVectors(array, array, size); }
    else if (size >= fields[2]) Video01ReserveVectors(array, array, size + (size >> 2));
    fields[1] = size;
    if (size > oldSize) {
        unsigned* record = reinterpret_cast<unsigned*>(static_cast<unsigned char*>(*array) + oldSize * 12);
        for (Scaleform::UPInt count = size - oldSize; count != 0; --count, record += 3) {
            if (record) { record[0] = 0; record[1] = 0; record[2] = 0; }
        }
    }
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases the stored allocation through Scaleform's global heap.
// @0x140005f60
void FUN_140005f60(void** allocation) { if (*allocation) Scaleform::Memory::Free(*allocation); }
#pragma optimize("", on)

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases the stored allocation through Scaleform's global heap.
// @0x140005fa0
void FUN_140005fa0(void** allocation) { if (*allocation) Scaleform::Memory::Free(*allocation); }
#pragma optimize("", on)

// releases the two Scaleform::String data references, then optionally frees the pair
// @0x140005d30
void* FUN_140005d30(Scaleform::UPInt* pair, unsigned flags)
{
    reinterpret_cast<Scaleform::String::DataDesc*>(pair[1] & ~Scaleform::UPInt(3))->Release();
    reinterpret_cast<Scaleform::String::DataDesc*>(pair[0] & ~Scaleform::UPInt(3))->Release();
    if (flags & 1) ::operator delete(pair);
    return pair;
}

// releases the two Scaleform::String data references held by this pair
// @0x140005df0
void FUN_140005df0(Scaleform::UPInt* pair)
{
    reinterpret_cast<Scaleform::String::DataDesc*>(pair[1] & ~Scaleform::UPInt(3))->Release();
    reinterpret_cast<Scaleform::String::DataDesc*>(pair[0] & ~Scaleform::UPInt(3))->Release();
}

// A pair of shared strings, copied member by member by its implicit copy constructor.
struct Video01StringPair
{
    Scaleform::String First;
    Scaleform::String Second;
};

// copies both shared string members when a destination pair is supplied.
// @0x140005db0
void FUN_140005db0(Scaleform::String* destination, const Scaleform::String* source)
{
    new (destination) Video01StringPair(*reinterpret_cast<const Video01StringPair*>(source));
}

// initializes a FunctionRefBase from the source, including its frame ownership mode.
// @0x140005f00
Scaleform::GFx::AS2::FunctionRefBase* FUN_140005f00(
    Scaleform::GFx::AS2::FunctionRefBase* destination,
    const Scaleform::GFx::AS2::FunctionRefBase* source)
{
    destination->Flags = 0;
    destination->Function = source->Function;
    if (destination->Function) destination->Function->AddRef();
    destination->pLocalFrame = 0;
    if (source->pLocalFrame)
        destination->SetLocalFrame(source->pLocalFrame, (source->Flags & 1) != 0);
    return destination;
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases the retained weak proxy in the owning SyncObject field.
// @0x1400061f0
void FUN_1400061f0(void** proxy)
{
    if (*proxy) FUN_14257dcd0(*proxy);
}
#pragma optimize("", on)

// resolves a weak proxy (WeakPtr::GetObjectThroughProxy): returns the target while it is alive and still referenced
// (0 once its count reached zero), and drops the proxy and clears the slot after the target has died.
// BEHAVIOUR FIX: the slot holds the proxy untagged, as in the exe (it does not mask the low bits), and a target whose
// count is already zero yields 0 rather than the dying object.
#pragma push_macro("GetObject")
#undef GetObject                              // windows.h's GetObjectA
// @0x140006240
void* FUN_140006240(void** weakSlot)
{
    // WeakPtr<C>::GetObjectThroughProxy (the slot is the Ptr<WeakPtrProxy>).
    Scaleform::Ptr<Scaleform::WeakPtrProxy>& pProxy = *reinterpret_cast<Scaleform::Ptr<Scaleform::WeakPtrProxy>*>(weakSlot);
    Scaleform::RefCountWeakSupportImpl* obj = 0;
    if (pProxy)
    {
        if (pProxy->IsAlive())
        {
            obj = pProxy->GetObject();
            if (obj->GetRefCount() == 0)
                obj = 0;
        }
        else
            pProxy.Clear();
    }
    return obj;
}
#pragma pop_macro("GetObject")

// the VideoSound deleting destructor: restores its vftable and runs the ref-counted base destructor.
// @0x140002a60
void* FUN_140002a60(void* object, unsigned flags)
{
    static_cast<Scaleform::GFx::Video::VideoSound*>(object)->Scaleform::GFx::Video::VideoSound::~VideoSound();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// runs the shared base destructor and conditionally releases the allocation.
// @0x140002b30
void* FUN_140002b30(void* object, unsigned flags)
{
    reinterpret_cast<Scaleform::RefCountNTSImplCore*>(object)->RefCountNTSImplCore::~RefCountNTSImplCore();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// runs the ref-counted base destructor and conditionally releases the allocation.
// @0x140002bb0
void* FUN_140002bb0(void* object, unsigned flags)
{
    reinterpret_cast<Scaleform::RefCountImplCore*>(object)->RefCountImplCore::~RefCountImplCore();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// tears down the sound stream's channel link before its base object. The exe's inline dtors store the own (0x1431b4be0)
// and base (0x1431b4b80) vftables, and clear the channel's back link with no null test.
// @0x140002c10
void* FUN_140002c10(void* object, unsigned flags)
{
    void** fields = static_cast<void**>(object);
    fields[0] = &VideoSoundStreamVtable;
    *reinterpret_cast<void**>(static_cast<unsigned char*>(fields[2]) + 0x10) = 0;
    if (fields[2]) FUN_14257dcb0(fields[2]);
    static_cast<Scaleform::GFx::Video::VideoSound*>(object)->Scaleform::GFx::Video::VideoSound::~VideoSound();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// runs the common ref-counted base destructor and optional allocation release.
// @0x140002cc0
void* FUN_140002cc0(void* object, unsigned flags)
{
    reinterpret_cast<Scaleform::RefCountImplCore*>(object)->RefCountImplCore::~RefCountImplCore();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// runs the common ref-counted base destructor and optional allocation release.
// @0x140002d20
void* FUN_140002d20(void* object, unsigned flags)
{
    reinterpret_cast<Scaleform::RefCountImplCore*>(object)->RefCountImplCore::~RefCountImplCore();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// runs the common ref-counted base destructor and optional allocation release.
// @0x140002e40
void* FUN_140002e40(void* object, unsigned flags)
{
    reinterpret_cast<Scaleform::RefCountImplCore*>(object)->RefCountImplCore::~RefCountImplCore();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// The one-instruction slots of the sound stream vtable 0x1431b4ce0 (slot index in brackets).
// [1]
// @0x140002d90
int FUN_140002d90(void*) { return 0; }
// [2]
// @0x140002da0
int FUN_140002da0(void*) { return 0; }
// [4]
// @0x140002db0
void FUN_140002db0(void*) {}
// [5] true while a channel is attached
// @0x140002950
bool FUN_140002950(void* stream) { return *reinterpret_cast<void**>(static_cast<unsigned char*>(stream) + 0x10) != 0; }
// [6]
// @0x140002dc0
void FUN_140002dc0(void*) {}
// [7]
// @0x140002dd0
float FUN_140002dd0(void*) { return 0.0f; }
// [8]
// @0x140002de0
void FUN_140002de0(void*) {}
// [9] the stored float at +0x18
// @0x140002df0
float FUN_140002df0(void* stream) { return *reinterpret_cast<float*>(static_cast<unsigned char*>(stream) + 0x18); }
// [11]
// @0x140002e00
float FUN_140002e00(void*) { return 0.0f; }
// [12]
// @0x140002e10
void FUN_140002e10(void*) {}
// [13]
// @0x140002e20
void FUN_140002e20(void*) {}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases the retained interface in this slot.
// @0x140003a50
void FUN_140003a50(void** interfaceSlot)
{
    if (*interfaceSlot)
        reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(*interfaceSlot))[2])(*interfaceSlot);
}
#pragma optimize("", on)

// releases the String data pair in reverse field order
// @0x140004b00
void FUN_140004b00(Scaleform::UPInt* pair)
{
    reinterpret_cast<Scaleform::String::DataDesc*>(pair[2] & ~Scaleform::UPInt(3))->Release();
    reinterpret_cast<Scaleform::String::DataDesc*>(pair[1] & ~Scaleform::UPInt(3))->Release();
}

// destroys the base object and releases its allocation when requested.
// @0x140003df0
void* FUN_140003df0(void* object, unsigned flags)
{
    static_cast<Scaleform::GFx::AS2::Value*>(object)->~Value();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// destroys weak-reference support state and optionally frees the object.
// @0x140004fb0
void* FUN_140004fb0(Scaleform::RefCountWeakSupportImpl* object, unsigned flags)
{
    object->RefCountWeakSupportImpl::~RefCountWeakSupportImpl();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// releases the two Scaleform::String data references stored in this small pair
// @0x140005300
void FUN_140005300(Scaleform::UPInt* pair)
{
    reinterpret_cast<Scaleform::String::DataDesc*>(pair[1] & ~Scaleform::UPInt(3))->Release();
    reinterpret_cast<Scaleform::String::DataDesc*>(pair[0] & ~Scaleform::UPInt(3))->Release();
}

// the VideoProvider deleting destructor (its inline dtor stores the 0x1431b4f30 vftable).
// @0x140005430
void* FUN_140005430(Scaleform::RefCountWeakSupportImpl* object, unsigned flags)
{
    static_cast<Scaleform::GFx::Video::VideoProvider*>(object)->VideoProvider::~VideoProvider();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// releases the base object's shared state and optionally its storage.
// @0x140004f30
void* FUN_140004f30(void* object, unsigned flags)
{
    reinterpret_cast<Scaleform::RefCountNTSImplCore*>(object)->RefCountNTSImplCore::~RefCountNTSImplCore();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// the SyncObject deleting destructor (its inline dtor stores the 0x1431b4f78 vftable).
// @0x140005610
void* FUN_140005610(void* object, unsigned flags)
{
    static_cast<Scaleform::GFx::Video::VideoPlayer::SyncObject*>(object)->SyncObject::~SyncObject();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// constructs the function and local-frame references from the supplied fields.
// @0x140005590
void FUN_140005590(
    Scaleform::GFx::AS2::FunctionRefBase* destination,
    const Scaleform::GFx::AS2::FunctionRefBase* source, unsigned char flags)
{
    destination->Flags = flags;
    destination->Function = source->Function;
    if (!(flags & Scaleform::GFx::AS2::FunctionRefBase::FuncRef_Internal) && destination->Function)
        destination->Function->AddRef();
    destination->pLocalFrame = 0;
    if (source->pLocalFrame)
        destination->SetLocalFrame(source->pLocalFrame, (source->Flags & 1) != 0);
}

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases the single allocation held by this stack or page descriptor.
// @0x140006bb0
void FUN_140006bb0(void** allocation) { if (*allocation) Scaleform::Memory::Free(*allocation); }
#pragma optimize("", on)

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// releases the single allocation held by this stack or page descriptor.
// @0x140006bd0
void FUN_140006bd0(void** allocation) { if (*allocation) Scaleform::Memory::Free(*allocation); }
#pragma optimize("", on)

// drops one reference on each weak-pointer proxy in the array (freeing it at zero), then frees the array:
// SDK DestructArray(Data, Size), last element first
// @0x140006c70
void FUN_140006c70(void** array)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    Scaleform::UPInt count = fields[1];
    void** items = static_cast<void**>(*array) + count - 1;
    for (Scaleform::UPInt i = 0; i < count; ++i, --items)
        if (*items) static_cast<Scaleform::WeakPtrProxy*>(*items)->Release();
    if (*array) Scaleform::Memory::Free(*array);
}

struct Video01Record12 { unsigned a, b, c; };

// MS2-FUNCTIONAL: resizes and copies the 12-byte records from the source array (the SDK Array operator= loop);
// only the base/index operand order of the per-dword loads and stores differs.
// @0x140006db0
void* FUN_140006db0(void** destination, const void** source)
{
    FUN_140005ca0(destination, reinterpret_cast<const Scaleform::UPInt*>(source)[1]);
    for (Scaleform::UPInt i = 0; i < reinterpret_cast<const Scaleform::UPInt*>(destination)[1]; i++)
        static_cast<Video01Record12*>(*destination)[i] = static_cast<const Video01Record12*>(*source)[i];
    return destination;
}

// releases both Scaleform::String data references held by each 16-byte record, last record first
// @0x1400068d0
void FUN_1400068d0(void* records, Scaleform::UPInt count)
{
    Scaleform::UPInt* pair = reinterpret_cast<Scaleform::UPInt*>(records) - 2 + count * 2;
    if (count) {
        do {
            reinterpret_cast<Scaleform::String::DataDesc*>(pair[1] & ~Scaleform::UPInt(3))->Release();
            reinterpret_cast<Scaleform::String::DataDesc*>(pair[0] & ~Scaleform::UPInt(3))->Release();
            pair -= 2;
        } while (--count);
    }
}

// destroys every weak pair in the storage and releases the array allocation
// @0x140006e20
void FUN_140006e20(void** array)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    FUN_1400068d0(*array, fields[1]);
    if (*array) Scaleform::Memory::Free(*array);
}

// copies the two shared strings in each 16-byte hash record
// @0x140006940
void FUN_140006940(Scaleform::String* destination, Scaleform::UPInt count,
                   const Scaleform::String* source)
{
    // SDK ConstructArraySource: placement copies of each two-string record
    for (Scaleform::UPInt i = 0; i < count; ++i, source += 2, destination += 2)
        ::new (destination) Video01StringPair(*reinterpret_cast<const Video01StringPair*>(source));
}

// 0x140006810 is the SDK Reserve of the VideoCharacters array (Array<WeakPtr<VideoCharacter> >, ResizeNoConstruct 0x140006e70).
static __forceinline void Video01ReserveCharacters(void** array, void* owner, Scaleform::UPInt requested)
{
    typedef Scaleform::WeakPtr<Scaleform::GFx::Video::VideoCharacter> T;
    reinterpret_cast<Scaleform::ArrayDataBase<T, Scaleform::AllocatorGH<T, 2>, Scaleform::ArrayDefaultPolicy>*>(array)->Reserve(owner, requested);
}
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$WeakPtr@VVideoCharacter@Video@GFx@Scaleform@@@Scaleform@@U?$AllocatorGH@V?$WeakPtr@VVideoCharacter@Video@GFx@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x140006810 ; unique
//
//

// 0x1400069a0 is the SDK Reserve of the CuePointParam array (ResizeNoConstruct 0x140006f50).
static __forceinline void Video01ReserveCueParams(void** array, void* owner, Scaleform::UPInt capacity)
{   typedef Scaleform::GFx::Video::VideoPlayer::CuePointParam T;
    reinterpret_cast<Scaleform::ArrayDataBase<T, Scaleform::AllocatorGH<T, 2>, Scaleform::ArrayDefaultPolicy>*>(array)->Reserve(owner, capacity);
}
// MS2-PIN: ?Reserve@?$ArrayDataBase@UCuePointParam@VideoPlayer@Video@GFx@Scaleform@@U?$AllocatorGH@UCuePointParam@VideoPlayer@Video@GFx@Scaleform@@$01@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAXPEBX_K@Z 0x1400069a0 ; unique

// clears this array descriptor, releasing its buffer when it is dynamically sized.
// @0x140006bf0
#pragma inline_depth(0)
void FUN_140006bf0(void** array)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    if (0 < fields[1]) {
        if (0 < fields[2] >> 1) {
            if (*array) {
                Scaleform::Memory::pGlobalHeap->Free(*array);
                *array = 0;
            }
            fields[2] = 0;
        }
    } else if (0 >= fields[2]) {
        typedef Scaleform::GFx::Video::VideoPlayer::AudioTrackInfo T;
        reinterpret_cast<Scaleform::ArrayDataBase<T, Scaleform::AllocatorGH<T, 2>, Scaleform::ArrayDefaultPolicy>*>(array)
            ->Reserve(array, 0);
    }
    fields[1] = 0;
}
#pragma inline_depth()

// Obtains a 0x400-byte value page, records it, and updates the current stack cursors. The page array's
// data pointer is read before its new size is stored, as in the exe.
// @0x140006a40
template<> void Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value, 32>::PushPage()
{
    Scaleform::UPInt* stack = reinterpret_cast<Scaleform::UPInt*>(this);
    void** freePage = reinterpret_cast<void**>(stack[7]);
    void* page = 0;
    if (freePage) {
        page = freePage;
        stack[7] = *reinterpret_cast<Scaleform::UPInt*>(static_cast<unsigned char*>(page) + 0x400);
    } else {
        void** heapVtable = *reinterpret_cast<void***>(Scaleform::Memory::pGlobalHeap);
        page = reinterpret_cast<void* (*)(void*, void*, Scaleform::UPInt, unsigned)>(heapVtable[14])(
            Scaleform::Memory::pGlobalHeap, stack, 0x408, 0);
    }
    if (page) {
        // stack[4] is the page array's data pointer (size stack[5], capacity stack[6]), not the array itself
        Scaleform::UPInt size = stack[5] + 1;
        void** array = reinterpret_cast<void**>(stack + 4);
        Video01ArrayData* data = reinterpret_cast<Video01ArrayData*>(array);
        if (size < data->Size) { if (size < data->Capacity >> 1) Video01ReserveLH(array, array, size); }
        else if (size >= data->Capacity) Video01ReserveLH(array, array, size + (size >> 2));
        void** slot = reinterpret_cast<void**>(stack[4]) + size - 1;
        data->Size = size;
        if (slot) *slot = page;
        stack[1] = reinterpret_cast<Scaleform::UPInt>(page);
        stack[0] = reinterpret_cast<Scaleform::UPInt>(page);
        stack[3] = stack[2] - 0x20;
        stack[2] = reinterpret_cast<Scaleform::UPInt>(page) + 0x400;
    } else {
        stack[0] -= 0x20;
    }
}

// SDK PagedStack::ReleasePage / Pages.PopBack(); PopBack is the module's out-of-line Resize (0x140005c20)
template<class S, class P> static __forceinline void Video01ReleasePage(S* s, P* ppage)
{
    ppage->pNext = s->pReserved;
    s->pReserved = ppage;
}
template<class A> static __forceinline void Video01PopBackPages(A* a)
{
    FUN_140005c20(reinterpret_cast<void**>(a), a->GetSize() - 1);
}

// SDK PopPage: returns the last page to the free list and restores the preceding stack page.
// @0x140006cf0
template<> void Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value, 32>::PopPage()
{
    if (Pages.GetSize() > 1)
    {
        Video01ReleasePage(this, Pages.Back());
        Video01PopBackPages(&Pages);

        Page* ppage = Pages.Back();

        pPageStart  = ppage->Values;
        pPageEnd    = pPageStart + 32;
        pCurrent    = pPageEnd - 1;

        if (Pages.GetSize() > 1)
        {
            pPrevPageTop = Pages[Pages.GetSize() - 2]->Values + 32 - 1;
        }
        else
        {
            pPrevPageTop = pPageStart;
        }
    }
    else
    {
        pCurrent++;
        Construct<Scaleform::GFx::AS2::Value>(pCurrent);
    }
}

// removes retained elements beyond the new size and adjusts pointer capacity
// @0x140006e70
void FUN_140006e70(void** array, void* owner, Scaleform::UPInt size)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    if (size < fields[1]) {
        // SDK DestructArray(Data + size, oldSize - size): released from the last element down
        void** items = static_cast<void**>(*array) + size;
        Scaleform::UPInt count = fields[1] - size;
        items += count - 1;
        for (Scaleform::UPInt i = 0; i < count; ++i, --items)
            if (*items) static_cast<Scaleform::WeakPtrProxy*>(*items)->Release();
        if (size < fields[2] / 2) Video01ReserveCharacters(array, owner, size);
    } else if (size >= fields[2]) {
        Video01ReserveCharacters(array, owner, size + (size >> 2));
    }
    fields[1] = size;
}

// shrinks or grows an array of two-string records, releasing the truncated ones through FUN_1400068d0
// @0x140006f50
void FUN_140006f50(void** array, void* owner, Scaleform::UPInt size)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    if (size < fields[1]) {
        FUN_1400068d0(static_cast<Scaleform::String*>(*array) + size * 2, fields[1] - size);
        if (size < fields[2] / 2) Video01ReserveCueParams(array, owner, size);
    } else if (size >= fields[2]) {
        Video01ReserveCueParams(array, owner, size + (size >> 2));
    }
    fields[1] = size;
}

// Appends an object value to the current paged stack block.
// @0x140006ff0
void FUN_140006ff0(Scaleform::UPInt* stack, Scaleform::GFx::AS2::Object** value)
{
    *stack += 0x20;
    if (*stack >= stack[2]) reinterpret_cast<Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value, 32>*>(stack)->PushPage();
    if (*stack) ::new (reinterpret_cast<void*>(*stack)) Scaleform::GFx::AS2::Value(*value);
}

// appends a string Value (type 5) to the current paged stack block
// @0x140007030
void FUN_140007030(Scaleform::UPInt* stack, Scaleform::GFx::AS2::Object** value)
{
    *stack += 0x20;
    if (*stack >= stack[2]) reinterpret_cast<Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value, 32>*>(stack)->PushPage();
    if (unsigned char* bytes = reinterpret_cast<unsigned char*>(*stack)) {
        // placement Value(const ASString&): type 5 holds the string node and bumps its plain refcount (+0x18)
        bytes[0] = 5;
        unsigned char* node = *reinterpret_cast<unsigned char**>(value);
        *reinterpret_cast<unsigned char**>(bytes + 8) = node;
        ++*reinterpret_cast<int*>(node + 0x18);
    }
}

// assigns the source 12-byte record array into the destination descriptor and returns the destination
// @0x140007230
void* FUN_140007230(void** destination, const void** source)
{
    FUN_140006db0(destination, source);
    return destination;
}

// source form tried (work/p5h/tmp/pb1.cpp)
// @0x140007270
void FUN_140007270(void** array, void** value)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    FUN_140006e70(array, array, fields[1] + 1);
    Scaleform::Ptr<Scaleform::WeakPtrProxy>* slot = static_cast<Scaleform::Ptr<Scaleform::WeakPtrProxy>*>(*array) + fields[1] - 1;
    // the element is a Ptr whose pointee keeps a plain int refcount at +0 (exe: `if (p) inc dword [p]`, no virtual
    // AddRef), copy-constructed in place
    ::new (slot) Scaleform::Ptr<Scaleform::WeakPtrProxy>(*reinterpret_cast<Scaleform::Ptr<Scaleform::WeakPtrProxy>*>(value));
}

// destroys weak-pair records and releases their backing allocation
// @0x1400072c0
void FUN_1400072c0(void** array)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    FUN_1400068d0(*array, fields[1]);
    if (*array) Scaleform::Memory::Free(*array);
}

// removes the last stack value and returns its page when it becomes empty.
// @0x140007200
void FUN_140007200(Scaleform::UPInt* stack)
{
    reinterpret_cast<Scaleform::GFx::AS2::Value*>(*stack)->~Value();
    *stack -= 0x20;
    if (*stack < stack[1]) reinterpret_cast<Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value, 32>*>(stack)->PopPage();
}

// resizes the retained pointer array and initializes newly added slots to null
// @0x1400072f0
void FUN_1400072f0(void** array, Scaleform::UPInt size)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    const Scaleform::UPInt oldSize = fields[1];
    FUN_140006e70(array, array, size);
    if (size > oldSize) {
        // SDK ConstructArray(Data + oldSize, size - oldSize): placement-new null pointers
        Scaleform::UPInt count = size - oldSize;
        void** slot = static_cast<void**>(*array) + oldSize;
        for (Scaleform::UPInt i = 0; i < count; ++i, ++slot)
            ::new (slot) void*(0);
    }
}

// appends copies of a sequence of two-string records
// @0x140007370
void FUN_140007370(void** array, const Scaleform::String* records, Scaleform::UPInt count)
{
    if (!count) return;
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    const Scaleform::UPInt oldSize = fields[1];
    FUN_140006f50(array, array, oldSize + count);
    // SDK ConstructArraySource(Data + oldSize, count, source): placement copies of each two-string record
    Video01StringPair* destination = static_cast<Video01StringPair*>(*array) + oldSize;
    const Video01StringPair* source = reinterpret_cast<const Video01StringPair*>(records);
    for (Scaleform::UPInt i = 0; i < count; ++i, ++source, ++destination)
        ::new (destination) Video01StringPair(*source);
}

// Appends an object value to the stack at the embedded current cursor.
// @0x140007400
void FUN_140007400(Scaleform::UPInt* owner, Scaleform::GFx::AS2::Object** value)
{
    FUN_140006ff0(owner + 1, value);
}

// appends a retained object value to the embedded current cursor.
// @0x140007450
void FUN_140007450(Scaleform::UPInt* owner, Scaleform::GFx::AS2::Object** value)
{
    FUN_140007030(owner + 1, value);
}

// removes the last value from the embedded paged stack.
// @0x140007510
void FUN_140007510(Scaleform::UPInt* owner)
{
    FUN_140007200(owner + 1);
}

struct As2WeakObjectPair
{
    void* pFirst;
    void* pSecond;
    unsigned char Flags;   // bit 1: pFirst is weak, bit 0: pSecond is weak
};

// releases both owned AS2 references according to the weak/internal mode bits.
// @0x1400074a0
void FUN_1400074a0(Scaleform::UPInt* object)
{
    As2WeakObjectPair* pair = reinterpret_cast<As2WeakObjectPair*>(object);
    if (!(pair->Flags & 2)) ReleaseAs2GCObject(pair->pFirst);
    pair->pFirst = 0;
    if (!(pair->Flags & 1)) ReleaseAs2GCObject(pair->pSecond);
    pair->pSecond = 0;
}

// @0x140007570
void FUN_140007570(void** slot) { ReleaseAs2GCObject(*slot); }

// retains the incoming AS2 object, releases the old value, and assigns it.
// @0x1400075a0
void** FUN_1400075a0(void** destination, void** source)
{
    if (*source) {
        unsigned* count = reinterpret_cast<unsigned*>(static_cast<unsigned char*>(*source) + 0x18);
        *count = (*count + 1) & 0x8fffffff;
    }
    ReleaseAs2GCObject(*destination);
    *destination = *source;
    return destination;
}

// @0x1400076d0
void FUN_1400076d0(void** slot) { ReleaseAs2GCObject(*slot); }

// retains a replacement AS2 object and releases the previous reference.
// @0x140007700
void** FUN_140007700(void** destination, void* replacement)
{
    if (replacement) {
        unsigned* count = reinterpret_cast<unsigned*>(static_cast<unsigned char*>(replacement) + 0x18);
        *count = (*count + 1) & 0x8fffffff;
    }
    ReleaseAs2GCObject(*destination);
    *destination = replacement;
    return destination;
}

// overwrites the slot after releasing its previous AS2 reference.
// @0x140007760
void** FUN_140007760(void** destination, void* replacement)
{
    ReleaseAs2GCObject(*destination);
    *destination = replacement;
    return destination;
}

// @0x1400077b0
void FUN_1400077b0(void** slot) { ReleaseAs2GCObject(*slot); }

// releases both references in the temporary AS2 value pair.
// @0x140007a40
void FUN_140007a40(Scaleform::UPInt* object)
{
    As2WeakObjectPair* pair = reinterpret_cast<As2WeakObjectPair*>(object);
    if (!(pair->Flags & 2)) ReleaseAs2GCObject(pair->pFirst);
    pair->pFirst = 0;
    if (!(pair->Flags & 1)) ReleaseAs2GCObject(pair->pSecond);
    pair->pSecond = 0;
}

// retains the replacement AS2 object and releases the old slot value.
// @0x140007600
void** FUN_140007600(void** destination, void* replacement)
{
    if (replacement) {
        unsigned* count = reinterpret_cast<unsigned*>(static_cast<unsigned char*>(replacement) + 0x18);
        *count = (*count + 1) & 0x8fffffff;
    }
    ReleaseAs2GCObject(*destination);
    *destination = replacement;
    return destination;
}

// source form tried (work/p5h/tmp/pb1.cpp)
// @0x140007680
void FUN_140007680(void** array, void** value)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    FUN_140006e70(array, array, fields[1] + 1);
    Scaleform::Ptr<Scaleform::WeakPtrProxy>* slot = static_cast<Scaleform::Ptr<Scaleform::WeakPtrProxy>*>(*array) + fields[1] - 1;
    // the element is a Ptr whose pointee keeps a plain int refcount at +0 (exe: `if (p) inc dword [p]`, no virtual
    // AddRef), copy-constructed in place
    ::new (slot) Scaleform::Ptr<Scaleform::WeakPtrProxy>(*reinterpret_cast<Scaleform::Ptr<Scaleform::WeakPtrProxy>*>(value));
}

// releases all weak pairs in the backing array and then frees it
// @0x1400077f0
void FUN_1400077f0(void** array)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    FUN_1400068d0(*array, fields[1]);
    if (*array) Scaleform::Memory::Free(*array);
}

// initializes an empty two-string record array and copies the supplied records.
// @0x140007840
void* FUN_140007840(void** destination, const void** source)
{
    destination[0] = 0;
    destination[1] = 0;
    destination[2] = 0;
    FUN_140007370(destination, static_cast<const Scaleform::String*>(*source),
                  reinterpret_cast<const Scaleform::UPInt*>(source)[1]);
    return destination;
}

// copies the type field and retains the AS2 object pointer in the source value.
// @0x140007870
void FUN_140007870(unsigned* destination, void** source)
{
    *destination = *static_cast<unsigned*>(*source);
    void** sourceSlot = static_cast<void**>(source[1]);
    if (*sourceSlot) {
        unsigned* count = reinterpret_cast<unsigned*>(static_cast<unsigned char*>(*sourceSlot) + 0x18);
        *count = (*count + 1) & 0x8fffffff;
    }
    ReleaseAs2GCObject(*reinterpret_cast<void**>(destination + 2));
    *reinterpret_cast<void**>(destination + 2) = *sourceSlot;
}

// @0x1400078d0
void FUN_1400078d0(void** value)
{
    ReleaseAs2GCObject(value[1]);
}

// releases the second-field object reference and optionally deletes the wrapper.
// @0x140007960
void* FUN_140007960(void* value, unsigned flags)
{
    ReleaseAs2GCObject(*reinterpret_cast<void**>(static_cast<unsigned char*>(value) + 8));
    if (flags & 1) ::operator delete(value);
    return value;
}

// assigns a typed AS2 value while retaining the replacement and releasing the old object.
// @0x1400079b0
unsigned* FUN_1400079b0(unsigned* destination, const unsigned* source)
{
    *destination = *source;
    if (void* replacement = *reinterpret_cast<void* const*>(source + 2)) {
        unsigned* count = reinterpret_cast<unsigned*>(static_cast<unsigned char*>(replacement) + 0x18);
        *count = (*count + 1) & 0x8fffffff;
    }
    ReleaseAs2GCObject(*reinterpret_cast<void**>(destination + 2));
    *reinterpret_cast<void**>(destination + 2) = *reinterpret_cast<void* const*>(source + 2);
    return destination;
}

// destroys the AS2 call frame and optionally deletes its storage.
// The exe calls the out-of-line dtor copy here (the dtor is header-inline).
#pragma inline_depth(0)
// @0x140007b70
void* FUN_140007b70(Scaleform::GFx::AS2::FnCall* call, unsigned flags)
{
    call->FnCall::~FnCall();
    if (flags & 1) ::operator delete(call);
    return call;
}
#pragma inline_depth()

// destroys a prototype base and optionally deletes its storage.
// @0x140007c80
void* FUN_140007c80(Scaleform::GFx::AS2::GASPrototypeBase* prototype, unsigned flags)
{
    prototype->GASPrototypeBase::~GASPrototypeBase();
    if (flags & 1) ::operator delete(prototype);
    return prototype;
}

// resolves the lowercase node for an ActionScript string when needed (SDK ASString::ResolveLowercase: the node is
// never null, so there is no null test).
// @0x140009ec0
void FUN_140009ec0(Scaleform::GFx::ASStringNode** nodeSlot)
{
    if (!(*nodeSlot)->pLower) (*nodeSlot)->ResolveLowercase_Impl();
}

// compares string node identity, using cached lowercase nodes for insensitive mode.
// @0x14000a030
bool FUN_14000a030(Scaleform::GFx::ASStringNode** left,
                   Scaleform::GFx::ASStringNode** right, bool caseSensitive)
{
    if (caseSensitive) return *left == *right;
    FUN_140009ec0(right);
    Scaleform::GFx::ASStringNode* rightNode = *right;
    return (*left)->pLower == rightNode->pLower;
}

// MS2-FUNCTIONAL: returns the equality result with the same case handling as the bool helper.
// @0x14000a090
bool FUN_14000a090(Scaleform::GFx::ASStringNode** left,
                   Scaleform::GFx::ASStringNode** right, bool caseSensitive)
{
    if (caseSensitive) return *left == *right;
    FUN_140009ec0(right);
    return (*left)->pLower == (*right)->pLower;
}

// erases one weak-pointer proxy from the pointer array and compacts the tail (SDK ArrayBase::RemoveAt)
// @0x14000a800
void FUN_14000a800(void** array, Scaleform::UPInt index)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    if (fields[1] == 1) {
        FUN_140006e70(array, array, 0);
    } else {
        void* proxy = static_cast<void**>(*array)[index];
        if (proxy) static_cast<Scaleform::WeakPtrProxy*>(proxy)->Release();
        memmove(static_cast<void**>(*array) + index, static_cast<void**>(*array) + 1 + index,
                sizeof(void*) * (fields[1] - 1 - index));
        --fields[1];
    }
}

// releases all weak pairs and the allocated pair array
// @0x14000a8f0
void FUN_14000a8f0(void** array)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    FUN_1400068d0(*array, fields[1]);
    if (*array) Scaleform::Memory::Free(*array);
}

// initializes an empty string-record array from the supplied source records.
// @0x14000a950
void* FUN_14000a950(void** destination, const void** source)
{
    return FUN_140007840(destination, source);
}

// releases the AS2 object stored in a hash entry and marks the entry unused.
// @0x14000a9f0
void FUN_14000a9f0(Scaleform::UPInt* entry)
{
    ReleaseAs2GCObject(reinterpret_cast<void*>(entry[2]));
    entry[0] = ~Scaleform::UPInt(1);
}

// releases the AS2 object stored in a hash entry and marks the entry unused.
// @0x14000aa30
void FUN_14000aa30(Scaleform::UPInt* entry)
{
    ReleaseAs2GCObject(reinterpret_cast<void*>(entry[2]));
    entry[0] = ~Scaleform::UPInt(1);
}

// destroys a NetStream and optionally returns its allocation to the global heap.
// BEHAVIOUR FIX (latent): ~NetStream is called directly (call 0x140008070) as in the exe. The virtual
// stream->~NetStream() would recurse through exe vftable 0x1431b5030 slot 2 (this function).
// The fullexe's own vftables put the compiler ??_G in slot 2, so it does not trigger there.
// @0x14000aa70
void* FUN_14000aa70(Scaleform::GFx::AS2::NetStream* stream, unsigned flags)
{
    stream->NetStream::~NetStream();
    if (flags & 1) Scaleform::Memory::Free(stream);
    return stream;
}

// The cue-point record as its inline ctor builds it: the name and the three numeric fields; +0 and +0x10 are left alone.
struct Video01CuePoint
{
    void*             Unk0;
    Scaleform::String Name;
    void*             Unk10;
    unsigned __int64  Field18, Field20, Field28;
    Video01CuePoint() { memset(&Field18, 0, 0x18); }
};

// constructs the cue-point name and zeros its three numeric fields
// @0x14000b020
void FUN_14000b020(void* cue)
{
    new (cue) Video01CuePoint;
}

// initializes an empty cue-point array and copies the supplied records.
// @0x14000b050
void* FUN_14000b050(void** destination, const void** source)
{
    return FUN_140007840(destination, source);
}

// the exe inlines the body into FUN_14000b120.
static __forceinline void Video01ReleaseValueTable(void** table)
{
    if (*table) {
        const Scaleform::UPInt mask = *reinterpret_cast<Scaleform::UPInt*>(static_cast<unsigned char*>(*table) + 8);
        for (Scaleform::UPInt i = 0; i <= mask; ++i) {
            Scaleform::UPInt* entry = reinterpret_cast<Scaleform::UPInt*>(
                static_cast<unsigned char*>(*table) + 0x10 + i * 0x18);
            if (entry[0] != ~Scaleform::UPInt(1)) {
                ReleaseAs2GCObject(reinterpret_cast<void*>(entry[2]));
                entry[0] = ~Scaleform::UPInt(1);
            }
        }
        Scaleform::Memory::Free(*table);
        *table = 0;
    }
}

// releases AS2 values in an open-addressed hash table and frees its storage.
// @0x14000b080
void FUN_14000b080(void** table)
{
    Video01ReleaseValueTable(table);
}

// releases AS2 values in an open-addressed hash table and frees its storage.
// @0x14000b120
void FUN_14000b120(void** table) { Video01ReleaseValueTable(table); }

// The rehash's local table; its destructor clears what it still owns.
struct VideoHashTableHolder
{
    Scaleform::UPInt* pTable;
    VideoHashTableHolder() : pTable(NULL) {}
    ~VideoHashTableHolder() { if (pTable) FUN_14000b120(reinterpret_cast<void**>(&pTable)); }
};

// MS2-FUNCTIONAL: the exe keeps the alloc info and the new table one slot higher, and rbx/rbp in the slots below.
// @0x14000b3b0
void FUN_14000b3b0(Scaleform::UPInt* tableRef, void* owner, Scaleform::UPInt requested)
{
    void** slot = reinterpret_cast<void**>(tableRef);
    if (requested == 0) {
        FUN_14000b120(slot);
        return;
    }
    if (requested < 8)
        requested = 8;
    else
        requested = Scaleform::UPInt(1) << (Scaleform::Alg::UpperBit(requested - 1) + 1);
    VideoHashTableHolder newHash;
    Scaleform::UPInt*& fresh = newHash.pTable;
    fresh = static_cast<Scaleform::UPInt*>(
        Scaleform::AllocatorBaseLH<>::Alloc(owner, requested * 0x18 + 0x10, __FILE__, __LINE__));
    fresh[0] = 0;
    fresh[1] = requested - 1;
    for (Scaleform::UPInt i = 0; i < requested; ++i) fresh[2 + i * 3] = ~Scaleform::UPInt(1);
    if (*slot) {
        for (Scaleform::UPInt i = 0, n = static_cast<Scaleform::UPInt*>(*slot)[1]; i <= n; ++i) {
            Scaleform::UPInt* entry = static_cast<Scaleform::UPInt*>(*slot) + 2 + i * 3;
            if (entry[0] != ~Scaleform::UPInt(1)) {
                FUN_14000b6e0(reinterpret_cast<Scaleform::UPInt*>(&fresh), owner,
                              reinterpret_cast<unsigned*>(entry + 1), VideoHashKeyInline(entry + 1, 4));
                ReleaseAs2GCObject(reinterpret_cast<void*>(entry[2]));
                entry[0] = ~Scaleform::UPInt(1);
            }
        }
        Scaleform::AllocatorBaseLH<>::Free(*slot);
    }
    *slot = fresh;
    fresh = NULL;
}

// MS2-FUNCTIONAL: inserts a 32-bit key and retained AS2 object into its chained hash bucket.
// @0x14000b6e0
void FUN_14000b6e0(Scaleform::UPInt* tableRef, void* owner, const unsigned* keyValue,
                   Scaleform::UPInt hash)
{
    InsertVideoHashEntry(tableRef, owner, keyValue, hash, ConstructVideoHashFromValue, CopyVideoHashValue);
}

// MS2-FUNCTIONAL: inserts a 32-bit key and retained object from the table's pair record. Same length (528) as the
// exe; left is 0x14000b6e0's VC9 register permutation (mask kept in r12 vs r11, rbp/rsi roles swapped).
// @0x14000b9e0
__declspec(noinline) void FUN_14000b9e0(Scaleform::UPInt* tableRef, void* owner, void** pair, Scaleform::UPInt hash)
{
    InsertVideoHashEntry(tableRef, owner, pair, hash, ConstructVideoHashFromPair, CopyVideoHashPair);
}

// hashes a 32-bit track key and inserts the object the caller's slot holds into the keyed table.
// @0x14000c220
void FUN_14000c220(void* table, const unsigned* key, void** value)
{
    void* pair[2] = {const_cast<unsigned*>(key), value};
    FUN_14000b9e0(reinterpret_cast<Scaleform::UPInt*>(table), table, pair, VideoHashKeyInline(key, 4));
}

// replaces the object for a 32-bit track id, releasing the caller's prior reference.
// @0x14000c280
__declspec(noinline) void FUN_14000c280(void* owner, unsigned key, void** value)
{
    void* pair[2] = {&key, value};
    unsigned char* table = reinterpret_cast<unsigned char*>(owner) + 0x10;
    FUN_14000b9e0(reinterpret_cast<Scaleform::UPInt*>(table), table, pair, VideoHashKeyInline(&key, 4));
    ReleaseAs2GCObject(*value);
}

// releases the String pair array and the String member, then optionally deletes the owner
// @0x14000b230
void* FUN_14000b230(void* owner, unsigned flags)
{
    unsigned char* bytes = static_cast<unsigned char*>(owner);
    void** array = reinterpret_cast<void**>(bytes + 0x18);
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    FUN_1400068d0(*array, fields[1]);
    if (*array) Scaleform::Memory::Free(*array);
    Scaleform::String::DataDesc* data = reinterpret_cast<Scaleform::String::DataDesc*>(
        (*reinterpret_cast<Scaleform::UPInt*>(bytes + 8)) & ~Scaleform::UPInt(3));
    data->Release();   // a String's data is never null
    if (flags & 1) ::operator delete(owner);
    return owner;
}

// the 0x30-byte cue-point record's default constructor: an empty label and an empty nested array
struct Video01CueRecord
{
    unsigned Kind;
    Scaleform::String Label;
    unsigned Meta;
    struct Array
    {
        void* Data;
        Scaleform::UPInt Size;
        Scaleform::UPInt Capacity;
        Array() : Data(0), Size(0), Capacity(0) {}
    } Nested;
    Video01CueRecord() {}
    Video01CueRecord(const Video01CueRecord& source);
};

// initializes each cue-point record with an empty string and zeroed metadata (SDK ConstructArray)
// @0x14000b2a0
void FUN_14000b2a0(void* records, Scaleform::UPInt count)
{
    Video01CueRecord* record = static_cast<Video01CueRecord*>(records);
    for (Scaleform::UPInt i = 0; i < count; ++i, ++record)
        ::new (record) Video01CueRecord();
}

// the cue record's copy constructor: kind, label, metadata, and a copy of the nested record array
// @0x14000b350
Video01CueRecord::Video01CueRecord(const Video01CueRecord& source)
    : Kind(source.Kind), Label(source.Label), Meta(source.Meta)
{
    FUN_140007370(reinterpret_cast<void**>(&Nested),
        static_cast<const Scaleform::String*>(source.Nested.Data), source.Nested.Size);
}

// copy-constructs a cue record in place if the destination is non-null (the exe inlines the copy ctor)
// @0x14000b620
void FUN_14000b620(unsigned* destination, const unsigned* source)
{
    ::new (destination) Video01CueRecord(*reinterpret_cast<const Video01CueRecord*>(source));
}

// releases the nested String pair arrays and the String member of each 48-byte record, last record first
// @0x14000b530
void FUN_14000b530(void* records, Scaleform::UPInt count)
{
    // SDK DestructArray(records, count): last record first
    Video01CueRecord* record = static_cast<Video01CueRecord*>(records) + count - 1;
    for (Scaleform::UPInt i = 0; i < count; ++i, --record) {
        FUN_1400068d0(record->Nested.Data, record->Nested.Size);
        if (record->Nested.Data) Scaleform::Memory::Free(record->Nested.Data);
        record->Label.~String();
    }
}

// destroys every nested video-track record and releases the outer array
// @0x14000b8f0
void FUN_14000b8f0(void** array)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    FUN_14000b530(*array, fields[1]);
    if (*array) Scaleform::Memory::Free(*array);
}

// destroys the track records and releases their backing allocation
// @0x14000bbf0
void FUN_14000bbf0(void** array)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    FUN_14000b530(*array, fields[1]);
    if (*array) Scaleform::Memory::Free(*array);
}

// destroys the NetStream provider and optionally frees its allocation.
// @0x14000cbd0
void* FUN_14000cbd0(Scaleform::GFx::AS2::VideoProviderNetStream* provider, unsigned flags)
{
    provider->VideoProviderNetStream::~VideoProviderNetStream();
    if (flags & 1) Scaleform::Memory::Free(provider);
    return provider;
}

// destroys the NetStream constructor function and optionally releases its allocation.
// BEHAVIOUR FIX (latent): ~CFunctionObject is called directly (call 0x1429255a0) as in the exe. The virtual call would
// recurse through exe vftable 0x1431b56b0 slot 2 (this function).
// The fullexe's own vftables put the compiler ??_G in slot 2, so it does not trigger there.
// @0x14000cee0
Scaleform::GFx::AS2::CFunctionObject* FUN_14000cee0(Scaleform::GFx::AS2::CFunctionObject* object,
                                                    unsigned flags)
{
    object->CFunctionObject::~CFunctionObject();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// 0x14000b940 is the SDK Reserve of the CuePoint array (ResizeNoConstruct 0x14000bc40); the CuePoint instance name is
// the separately linked copy 0x1423ca2b0, so this unit instantiates it for a local 0x30-byte stand-in.
struct Video01CuePointSlot { void* p[6]; };
static __forceinline void Video01ReserveCuePoints(void** array, void* owner, Scaleform::UPInt capacity)
{   typedef Video01CuePointSlot T;
    reinterpret_cast<Scaleform::ArrayDataBase<T, Scaleform::AllocatorGH<T, 2>, Scaleform::ArrayDefaultPolicy>*>(array)->Reserve(owner, capacity); }
// MS2-PIN: ?Reserve@?$ArrayDataBase@UVideo01CuePointSlot@@U?$AllocatorGH@UVideo01CuePointSlot@@$01@Scaleform@@UArrayDefaultPolicy@3@@Scaleform@@QEAAXPEBX_K@Z 0x14000b940 ; unique

// initializes or grows the video-track hash table at its observed load threshold.
// @0x14000b680
void FUN_14000b680(void** table, void* owner)
{
    Scaleform::UPInt** ptable = reinterpret_cast<Scaleform::UPInt**>(table);
    if (*ptable == 0)
        FUN_14000b3b0(reinterpret_cast<Scaleform::UPInt*>(table), owner, 8);
    else if ((*ptable)[0] * 5 > ((*ptable)[1] + 1) * 4)
        FUN_14000b3b0(reinterpret_cast<Scaleform::UPInt*>(table), owner, ((*ptable)[1] + 1) * 2);
}

// @0x14000bc40
void FUN_14000bc40(void** array, void* owner, Scaleform::UPInt size)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    if (size < fields[1])
    {
        FUN_14000b530(static_cast<unsigned char*>(*array) + size * 0x30, fields[1] - size);
        if (size < fields[2] / 2) Video01ReserveCuePoints(array, owner, size);
    }
    else if (size >= fields[2]) Video01ReserveCuePoints(array, owner, size + (size >> 2));
    fields[1] = size;
}

// destroys all track records and releases the array buffer
// @0x14000bd10
void FUN_14000bd10(void** array) { FUN_14000b8f0(array); }

// resizes the track array and initializes every new cue record
// @0x14000bd60
void FUN_14000bd60(void** array, Scaleform::UPInt size)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    const Scaleform::UPInt oldSize = fields[1];
    FUN_14000bc40(array, array, size);
    if (size > oldSize) {
        // SDK ConstructArray(Data + oldSize, size - oldSize), inlined
        Video01CueRecord* record = static_cast<Video01CueRecord*>(*array) + oldSize;
        Scaleform::UPInt count = size - oldSize;
        for (Scaleform::UPInt i = 0; i < count; ++i, ++record)
            ::new (record) Video01CueRecord();
    }
}

// destroys all track records and releases the array buffer
// @0x14000be30
void FUN_14000be30(void** array) { FUN_14000b8f0(array); }

#pragma optimize("t", off)   // the exe builds this one favouring size: frame + call, no tail call
// frees the owning index and releases its track-record array.
// @0x14000c320
void FUN_14000c320(void* owner)
{
    unsigned char* bytes = static_cast<unsigned char*>(owner);
    void* index = *reinterpret_cast<void**>(bytes + 0x38);
    if (index) Scaleform::Memory::Free(index);
    void** records = reinterpret_cast<void**>(bytes + 0x18);
    FUN_14000b530(*records, *reinterpret_cast<Scaleform::UPInt*>(bytes + 0x20));
    if (*records) Scaleform::Memory::Free(*records);
}
#pragma optimize("", on)

// the NetStream prototype destructor body; the exe inlines it into FUN_14000a7b0.
static __forceinline void Video01NetStreamProtoDtor(void* object)
{
    unsigned char* bytes = static_cast<unsigned char*>(object);
    // the implicit prototype destructor resets its three vftables first
    *reinterpret_cast<void**>(bytes) = &NetStreamPrototypeVtable;
    *reinterpret_cast<void**>(bytes + 0x20) = &NetStreamPrototypeInterfaceVtable;
    *reinterpret_cast<void**>(bytes + 0xd8) = &NetStreamPrototypeBaseVtable;
    reinterpret_cast<Scaleform::GFx::AS2::GASPrototypeBase*>(bytes + 0xd8)->GASPrototypeBase::~GASPrototypeBase();
    reinterpret_cast<Scaleform::GFx::AS2::NetStream*>(object)->NetStream::~NetStream();
}

// finalizes the prototype subobject and the NetStream base subobject.
// @0x14000aec0
void FUN_14000aec0(void* object) { Video01NetStreamProtoDtor(object); }

// releases the derived prototype and NetStream state.
// @0x14000a7b0
void FUN_14000a7b0(void* object) { Video01NetStreamProtoDtor(object); }

// destroys the prototype and NetStream base, then optionally frees the object.
// @0x14000a880
__declspec(noinline) void* FUN_14000a880(void* object, unsigned flags)
{
    FUN_14000aec0(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// The NetStream prototype's deleting destructor seen through its two secondary bases.
// The exe thunks are the compiler adjustors (sub rcx,imm; jmp), so they are now the ??_E Prototype<NetStream> adjustors
// that the compiled vftables 0x1431b5300 [0] / 0x1431b5310 [0] hold (MS2-PIN at the end of the file); the free-function
// forms FUN_14000a010 / FUN_14000a020 (this adjustors of the +0xd8 / +0x20 base) emitted add rcx,-imm.
//void* FUN_14000a010(void* object, unsigned flags) { return FUN_14000a880(static_cast<unsigned char*>(object) - 0xd8, flags); }
//
//
//void* FUN_14000a020(void* object, unsigned flags) { return FUN_14000a880(static_cast<unsigned char*>(object) - 0x20, flags); }

// The exe re-stores the three own vftables (0x1431b53c0/0x1431b5310/0x1431b5300) first; nothing reads them before the bases'.
// destroys the prototype and NetStream base, then optionally frees the object.
// @0x14000b1c0
void* FUN_14000b1c0(void* object, unsigned flags)
{
    FUN_14000aec0(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// @0x14000d250
void FUN_14000d250(Scaleform::GFx::AS2::Value* value, double number)
{
    value->SetNumber(number);
}

// sets the bool tag and payload after releasing any previous reference.
// @0x14000d2a0
void FUN_14000d2a0(Scaleform::GFx::AS2::Value* value, bool boolean)
{
    value->SetBool(boolean);
}

// allocates from the global Scaleform heap using the requested memory stat.
// @0x14000d360
void* FUN_14000d360(Scaleform::UPInt size, void* owner)
{
    unsigned stat = 0x143;
    void** heapVtable = *reinterpret_cast<void***>(Scaleform::Memory::pGlobalHeap);
    return reinterpret_cast<void* (*)(void*, void*, Scaleform::UPInt, unsigned*)>(heapVtable[14])(
        Scaleform::Memory::pGlobalHeap, owner, size, &stat);
}

struct VideoPrototypeInitAccess : Scaleform::GFx::AS2::GASPrototypeBase
{
    using GASPrototypeBase::InitFunctionMembers;
};

// registers methods in the GAS prototype subobject at its observed object offset.
// @0x14000d390
void FUN_14000d390(Scaleform::GFx::AS2::Object* object,
                   Scaleform::GFx::AS2::ASStringContext* context,
                   Scaleform::GFx::AS2::NameFunction* table,
                   const Scaleform::GFx::AS2::PropFlags* flags)
{
    VideoPrototypeInitAccess* prototype = reinterpret_cast<VideoPrototypeInitAccess*>(
        reinterpret_cast<unsigned char*>(object) + 0x70);
    prototype->InitFunctionMembers(object, context, table, *flags);
}

struct VideoCtorProtoInitAccess : Scaleform::GFx::AS2::GASPrototypeBase
{
    using GASPrototypeBase::InitFunctionMembers;
};

// initializes the NetStream constructor's prototype members at the observed subobject offset.
// @0x140003ba0
void FUN_140003ba0(Scaleform::GFx::AS2::Object* object,
                   Scaleform::GFx::AS2::ASStringContext* context,
                   Scaleform::GFx::AS2::NameFunction* table,
                   const Scaleform::GFx::AS2::PropFlags* flags)
{
    VideoCtorProtoInitAccess* prototype = reinterpret_cast<VideoCtorProtoInitAccess*>(
        reinterpret_cast<unsigned char*>(object) + 0xd8);
    prototype->InitFunctionMembers(object, context, table, *flags);
}

// looks up the object's constructor member and converts it through the out-of-line Value::ToFunction_Call.
// @0x140007ff0
Scaleform::GFx::AS2::FunctionRef Scaleform::GFx::AS2::ObjectInterface::Get__constructor__(
    Scaleform::GFx::AS2::ASStringContext* context)
{
    Scaleform::GFx::AS2::Value member;
    if (GetMemberRaw(context,
                     context->pContext->GetStringManager()->GetBuiltin(Scaleform::GFx::AS2::ASBuiltin___constructor__),
                     &member))
        return member.ToFunction_Call(0);
    return Scaleform::GFx::AS2::FunctionRef();
}

// @0x14000d570
void FUN_14000d570(void** proxy) { if (*proxy) static_cast<Scaleform::WeakPtrProxy*>(*proxy)->Release(); }

// optionally deletes a small polymorphic helper object. The exe stores the AvmDisplayObjBase vftable (0x14317bf80)
// first, as its inline dtor does: a dead store before the delete.
// @0x14000d5c0
void* FUN_14000d5c0(void* object, unsigned flags)
{
    static_cast<Scaleform::GFx::AvmDisplayObjBase*>(object)->Scaleform::GFx::AvmDisplayObjBase::~AvmDisplayObjBase();
    if (flags & 1) ::operator delete(object);
    return object;
}

// BEHAVIOUR FIX (latent): tail-jumps to Object::~Object (0x142925cf0) as in the exe. Through the exe vftable a virtual
// object->~Object() reaches slot 2 (FUN_14000de80 on a Video) and releases the proxy again.
// The fullexe's own vftables put the compiler ??_G in slot 2, so it does not trigger there.
// @0x14000d5f0
void FUN_14000d5f0(Scaleform::GFx::AS2::Object* object)
{
    void** slot = reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(object) + 0x68);
    if (*slot) static_cast<Scaleform::WeakPtrProxy*>(*slot)->Release();
    object->Object::~Object();
}

// @0x14000d630
void* FUN_14000d630(void** proxy, unsigned flags)
{
    if (*proxy) static_cast<Scaleform::WeakPtrProxy*>(*proxy)->Release();
    if (flags & 1) ::operator delete(proxy);
    return proxy;
}

namespace Scaleform { namespace GFx { namespace AS2 { static __forceinline void Video01VideoPrototypeDtor(Object* object); } } }   // (C3) after VideoObject
// destroys the video prototype extension and its AS2 Object base. The exe's inline Prototype<VideoObject> dtor stores
// its three vftables first.
// @0x14000d680
void FUN_14000d680(Scaleform::GFx::AS2::Object* object)
{
    Scaleform::GFx::AS2::Video01VideoPrototypeDtor(object);
//    *reinterpret_cast<void**>(bytes) = &VideoProtoGCVtable;  (+0x20 / +0x70: the other two)
//    reinterpret_cast<Scaleform::GFx::AS2::GASPrototypeBase*>(bytes + 0x70)->GASPrototypeBase::~GASPrototypeBase();
//    void** slot = reinterpret_cast<void**>(bytes + 0x68);
//    if (*slot) static_cast<Scaleform::WeakPtrProxy*>(*slot)->Release();
//    object->Object::~Object();
//
}

struct VideoObjectGcAccess : Scaleform::GFx::AS2::Object
{
    using Object::ForEachChild_GC;
};

class VideoGcPassAccess : public Scaleform::GFx::AS2::ASRefCountBaseType
{
public:
    typedef Scaleform::GFx::AS2::ASRefCountBaseType::ReleaseFunctor Release;
    typedef Scaleform::GFx::AS2::ASRefCountBaseType::MarkInCycleFunctor Mark;
    typedef Scaleform::GFx::AS2::ASRefCountBaseType::ScanInUseFunctor Scan;
};

// the interface-table walk of the GC passes: size read once, the table reloaded per element.
template<class Functor>
static __forceinline void Video01VisitObjectTable(Scaleform::UPInt** table,
    Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector)
{
    using namespace Scaleform::GFx::AS2;
    if (*table) {
        for (Scaleform::UPInt i = 0, count = (*table)[1]; i < count; ++i) {
            Object* const& item = reinterpret_cast<Object**>((*table)[0])[i];
            if (item) Functor::Call(collector, static_cast<ASRefCountBaseType*>(item));
        }
    }
}

template<class Functor>
static __forceinline void ForEachVideoObjectChild(void* object,
    Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector)
{
    using namespace Scaleform::GFx::AS2;
    reinterpret_cast<VideoObjectGcAccess*>(object)->ForEachChild_GC<Functor>(collector);
    unsigned char* bytes = static_cast<unsigned char*>(object);
    reinterpret_cast<FunctionRefBase*>(bytes + 0x78)->ForEachChild_GC<Functor>(collector);
    reinterpret_cast<FunctionRefBase*>(bytes + 0x90)->ForEachChild_GC<Functor>(collector);
    Video01VisitObjectTable<Functor>(reinterpret_cast<Scaleform::UPInt**>(bytes + 0xa8), collector);
}

// marks all video object children as candidates in a cycle.
// @0x14000d870
void FUN_14000d870(void* object, Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector)
{
    ForEachVideoObjectChild<VideoGcPassAccess::Mark>(object, collector);
}

// scans all video object children for live references.
// @0x14000d9c0
void FUN_14000d9c0(void* object, Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector)
{
    ForEachVideoObjectChild<VideoGcPassAccess::Scan>(object, collector);
}

// releases all video object child references through the cycle collector.
// @0x14000dc30
void FUN_14000dc30(void* object, Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector)
{
    ForEachVideoObjectChild<VideoGcPassAccess::Release>(object, collector);
}

// The collector pass dispatch (release, mark, scan) that the exe inlines into each wrapper.
typedef void (*Video01GcPass)(void*, Scaleform::GFx::AS2::ASRefCountBaseType::Collector*);
static __forceinline void Video01DispatchGc(void* object, Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector, int operation,
                                            Video01GcPass release, Video01GcPass mark, Video01GcPass scan)
{
    switch (operation)
    {
    case 0: release(object, collector); break;
    case 1: mark(object, collector); break;
    case 2: scan(object, collector); break;
    }
}

// @0x14000e1a0
void FUN_14000e1a0(void* object, Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector,
                   int operation)
{
    Video01DispatchGc(object, collector, operation, FUN_14000dc30, FUN_14000d870, FUN_14000d9c0);
}

// @0x14000dd50
void FUN_14000dd50(void** slot) { ReleaseAs2GCObject(*slot); }

// releases an old AS2 reference and stores the replacement.
// @0x14000dd80
void** FUN_14000dd80(void** slot, void* replacement)
{
    ReleaseAs2GCObject(*slot);
    *slot = replacement;
    return slot;
}

// @0x14000ddd0
void FUN_14000ddd0(void* object, Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector,
                   int operation)
{
    Video01DispatchGc(object, collector, operation, FUN_14000dc30, FUN_14000d870, FUN_14000d9c0);
}

// BEHAVIOUR FIX (latent): the base destructor is called directly (call 0x142925cf0) as in the exe. A virtual
// object->~Object() would recurse through exe vftable 0x1431b5af0 slot 2 (this function).
// The fullexe's own vftables put the compiler ??_G in slot 2, so it does not trigger there.
// @0x14000de80
void* FUN_14000de80(Scaleform::GFx::AS2::Object* object, unsigned flags)
{
    void** proxy = reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(object) + 0x68);
    if (*proxy) static_cast<Scaleform::WeakPtrProxy*>(*proxy)->Release();
    object->Object::~Object();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// destroys the video prototype and AS2 Object base, optionally releasing storage
// @0x14000d940
void* FUN_14000d940(Scaleform::GFx::AS2::Object* object, unsigned flags)
{
    FUN_14000d680(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// @0x14000e390
void Scaleform::GFx::AS2::AvmCharacter::OnEventLoad()
{
    void* receiver = this;
    Scaleform::GFx::EventId payload(1);
    reinterpret_cast<void (*)(void*, const Scaleform::GFx::EventId*)>((*reinterpret_cast<void***>(receiver))[8])(
        receiver, &payload);
}

// forwards the character's event through the containing video object.
// @0x14000e410
void FUN_14000e410(void** subobject, void* a, void* b, void* c, void* d)
{
    void** interfaceVtable = reinterpret_cast<void**>(*subobject);
    void* object = subobject - 1;
    void** baseVtable = *reinterpret_cast<void***>(object);
    reinterpret_cast<void (*)(void*, void*, void*, void*, void*)>(interfaceVtable[3])(
        subobject, reinterpret_cast<void* (*)(void*)>(baseVtable[31])(object), b, c, d);
    (void)a;
}

// releases the VideoObject prototype table and the weak-pointer proxy at +0x68 before base finalization
// @0x14000dbc0
void FUN_14000dbc0(void* object)
{
    unsigned char* bytes = static_cast<unsigned char*>(object);
    // the exe frees the table's buffer and the table without null-testing the buffer, and stores nothing back
    if (*reinterpret_cast<void***>(bytes + 0xa8)) {
        Scaleform::Memory::Free(**reinterpret_cast<void***>(bytes + 0xa8));
        Scaleform::Memory::Free(*reinterpret_cast<void**>(bytes + 0xa8));
    }
    // the +0x68 member is a weak-pointer proxy
    if (void* proxy = *reinterpret_cast<void**>(bytes + 0x68))
        static_cast<Scaleform::WeakPtrProxy*>(proxy)->Release();
    reinterpret_cast<VideoFinalizeAccess*>(object)->VideoFinalizeAccess::Finalize_GC();   // qualified = direct, as the exe (0x142942e70)
}

// Video.clear (the Video prototype table at 0x1431b5800): drops the held VideoCharacter's image.
// @0x14000d330
void FUN_14000d330(void* wrapper)
{
    // wrapper is the FnCall; ThisPtr (+0x10) is the Video object's ObjectInterface at +8.
    unsigned char* bytes = static_cast<unsigned char*>(wrapper);
    void* thisPtr = *reinterpret_cast<void**>(bytes + 0x10);
    void* object = thisPtr ? static_cast<unsigned char*>(thisPtr) - 8 : 0;   // static_cast, no null test after it
    // The exe passes the character held at +0x20, not the AS2 object.
    void* character = *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x20);
    if (character)
        FUN_140010a30(static_cast<Scaleform::GFx::Video::VideoCharacter*>(character));
}

// AvmVideoCharacter vtable 0x1431b5cb0 [34]: a constant id.
// @0x14000d320
unsigned Scaleform::GFx::AS2::AvmVideoCharacter::GetStandardMemberBitMask() const { return 0x7027cf; }

// @0x14000a730
void FUN_14000a730(void* object, Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector,
                   int operation)
{
    Video01DispatchGc(object, collector, operation, FUN_14000a5d0, FUN_14000a230, FUN_14000a420);
}

// releases the prototype's member table and weak provider, then finalizes the AS2 object base. As in the exe, the
// table's data is freed without a null test and neither field is cleared (the object is being finalized).
// @0x14000a3a0
void FUN_14000a3a0(void* object)
{
    VideoFinalizeView* view = static_cast<VideoFinalizeView*>(object);
    if (view->pTable) {
        Scaleform::Memory::Free(*view->pTable);
        Scaleform::Memory::Free(view->pTable);
    }
    if (view->pProvider) {
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(view->pProvider) + 0x18) = 0;
        VideoPlayerOwnerView* provider = view->pProvider;
        if (provider->pImpl) provider->pImpl->Slot14();
    }
    if (view->pProvider) FUN_14257dcd0(view->pProvider);
    reinterpret_cast<VideoFinalizeAccess*>(object)->VideoFinalizeAccess::Finalize_GC();   // qualified = direct, as the exe (0x142942e70)
}

// @0x14000a770
void FUN_14000a770(void* object, Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector,
                   int operation)
{
    Video01DispatchGc(object, collector, operation, FUN_14000a5d0, FUN_14000a230, FUN_14000a420);
}

// promotes a live weak proxy to a strong object reference in the output slot. The exe compares pObject in
// memory and reloads it, so the second read is volatile.
// BEHAVIOUR FIX: a live object with a non-zero count gets a plain (RefCountNTSImpl) AddRef, as in the exe. This
// used to call 0x14257dcb0 (RefCountImpl::Release), so every promotion dropped a reference instead of taking one.
// The weak slot also holds the proxy pointer untagged; the exe does not mask its low bits.
// @0x140006350
void** FUN_140006350(void** weakSlot, void** result)
{
    void* object = 0;
    Scaleform::WeakPtrProxy* proxy = static_cast<Scaleform::WeakPtrProxy*>(*weakSlot);
    if (proxy) {
        if (proxy->IsAlive()) {
            object = *reinterpret_cast<void* volatile*>(reinterpret_cast<unsigned char*>(proxy) + 8);
            if (*reinterpret_cast<int*>(static_cast<unsigned char*>(object) + 8) == 0) object = 0;
        } else {
            proxy->Release();
            *weakSlot = 0;
        }
    }
    if (object) ++*reinterpret_cast<int*>(static_cast<unsigned char*>(object) + 8);
    *result = object;
    return result;
}

// adjusts the 16-byte array's size using the executable's growth thresholds.
// @0x140006670
void FUN_140006670(void** array, Scaleform::UPInt size)
{
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    if (size < fields[1]) { if (size < fields[2] / 2) Video01ReserveAudioTracks(array, array, size); }
    else if (size >= fields[2]) Video01ReserveAudioTracks(array, array, size + (size >> 2));
    fields[1] = size;
}

// appends one 12-byte record to the array, growing capacity when needed. The exe reads Size again for the
// shrink compare (hence the volatile first read).
// @0x1400066f0
void FUN_1400066f0(void** array, const unsigned* record)
{
    Video01ArrayData* data = reinterpret_cast<Video01ArrayData*>(array);
    const Scaleform::UPInt size = *reinterpret_cast<const volatile Scaleform::UPInt*>(&data->Size) + 1;
    if (size < data->Size) { if (size < data->Capacity >> 1) Video01ReserveVectors(array, array, size); }
    else if (size >= data->Capacity) Video01ReserveVectors(array, array, size + (size >> 2));
    data->Size = size;
    unsigned* slot = reinterpret_cast<unsigned*>(static_cast<unsigned char*>(data->Data) + (size - 1) * 12);
    if (slot) { slot[0] = record[0]; slot[1] = record[1]; slot[2] = record[2]; }
}

// @0x140006770
void FUN_140006770(void** slot) { if (*slot) static_cast<Scaleform::WeakPtrProxy*>(*slot)->Release(); }

// releases every retained Scaleform reference in the pointer array.
// @0x1400067a0
void FUN_1400067a0(void** values, Scaleform::UPInt count)
{
    void** cursor = values + count - 1;
    while (count) {
        void* value = *cursor;
        if (value) static_cast<Scaleform::WeakPtrProxy*>(value)->Release();
        --cursor;
        --count;
    }
}

template<class Functor>
static __forceinline void ForEachVideoPrototypeChild(void* object,
    Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector)
{
    using namespace Scaleform::GFx::AS2;
    reinterpret_cast<VideoObjectGcAccess*>(object)->ForEachChild_GC<Functor>(collector);
    unsigned char* bytes = static_cast<unsigned char*>(object);
    reinterpret_cast<FunctionRefBase*>(bytes + 0x78)->ForEachChild_GC<Functor>(collector);
    reinterpret_cast<FunctionRefBase*>(bytes + 0x90)->ForEachChild_GC<Functor>(collector);
    reinterpret_cast<FunctionRefBase*>(bytes + 0xa8)->ForEachChild_GC<Functor>(collector);
    reinterpret_cast<FunctionRefBase*>(bytes + 0xc0)->ForEachChild_GC<Functor>(collector);
    reinterpret_cast<FunctionRefBase*>(bytes + 0xe0)->ForEachChild_GC<Functor>(collector);
    reinterpret_cast<FunctionRefBase*>(bytes + 0xf8)->ForEachChild_GC<Functor>(collector);
    Video01VisitObjectTable<Functor>(reinterpret_cast<Scaleform::UPInt**>(bytes + 0x110), collector);
}

// visits prototype children with the collector's release pass.
// @0x14000a5d0
void FUN_14000a5d0(void* object, Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector)
{
    ForEachVideoPrototypeChild<VideoGcPassAccess::Release>(object, collector);
}

// visits prototype children with the collector's cycle-mark pass.
// @0x14000a230
void FUN_14000a230(void* object, Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector)
{
    ForEachVideoPrototypeChild<VideoGcPassAccess::Mark>(object, collector);
}

// visits prototype children with the collector's in-use scan pass.
// @0x14000a420
void FUN_14000a420(void* object, Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector)
{
    ForEachVideoPrototypeChild<VideoGcPassAccess::Scan>(object, collector);
}

// performs the collector's release transition on one AS2 object.
// @0x14000a540
void FUN_14000a540(Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector,
                   Scaleform::GFx::AS2::ASRefCountBaseType* object)
{
    VideoGcPassAccess::Release::Call(collector, object);
}

// releases the String pair array and the String member owned by this record
// @0x14000b300
void FUN_14000b300(void* owner)
{
    unsigned char* bytes = static_cast<unsigned char*>(owner);
    void** array = reinterpret_cast<void**>(bytes + 0x18);
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    FUN_1400068d0(*array, fields[1]);
    if (*array) Scaleform::Memory::Free(*array);
    Scaleform::String::DataDesc* data = reinterpret_cast<Scaleform::String::DataDesc*>(
        (*reinterpret_cast<Scaleform::UPInt*>(bytes + 8)) & ~Scaleform::UPInt(3));
    data->Release();   // a String's data is never null
}

// releases the String pair array and the String member of this owner
// @0x14000afd0
void FUN_14000afd0(void* owner)
{
    unsigned char* bytes = static_cast<unsigned char*>(owner);
    void** array = reinterpret_cast<void**>(bytes + 0x18);
    Scaleform::UPInt* fields = reinterpret_cast<Scaleform::UPInt*>(array);
    FUN_1400068d0(*array, fields[1]);
    if (*array) Scaleform::Memory::Free(*array);
    Scaleform::String::DataDesc* data = reinterpret_cast<Scaleform::String::DataDesc*>(
        (*reinterpret_cast<Scaleform::UPInt*>(bytes + 8)) & ~Scaleform::UPInt(3));
    data->Release();   // a String's data is never null
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
// Wakes a video display object up when its provider has a first frame (sfr_video_02).
void FUN_140010a70(Scaleform::GFx::Video::VideoCharacter* pvideo);
// Points a video display object at a provider, or at none (sfr_video_02).
void FUN_140010b80(Scaleform::GFx::Video::VideoCharacter* pvideo, Scaleform::GFx::Video::VideoProvider* pprovider);

namespace Scaleform { namespace GFx { namespace AS2 {

using namespace Video;

Value* ArgCopy(const FnCall* pfn, int n);    // sfr_as2_04e @0x1429316c0, FnCall::Arg out of line

// ==== VideoProviderNetStream =========================================================================================

// The sprite whose sound settings a provider's audio follows: the audio target itself, or its parent when the target
// is not a sprite.
static inline Sprite* GetAudioTargetSprite(CharacterHandle* ph)
{
    DisplayObject* pch = ph->pCharacter;
    Sprite* psprite = NULL;
    if (pch)
    {
        if (pch->IsSprite())
            psprite = (Sprite*)pch;
        else
        {
            DisplayObject* pparent = (DisplayObject*)pch->pParent;
            if (pparent && pparent->IsSprite())
                psprite = (Sprite*)pparent;
        }
    }
    return psprite;
}

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

// @0x14000c370
VideoProviderNetStream::~VideoProviderNetStream()
{
    Close();
}

// @0x140003490
bool VideoProviderNetStream::IsActive()
{
    if (!pVideoPlayer)
        return false;
    VideoPlayer::Status status = pVideoPlayer->GetStatus();
    return status == VideoPlayer::Opening || status == VideoPlayer::Ready || status == VideoPlayer::Starting ||
           status == VideoPlayer::Playing || status == VideoPlayer::Seeking || status == VideoPlayer::Stopping;
}

// @0x140003520
void VideoProviderNetStream::Stop()
{
    if (pVideoPlayer)
        pVideoPlayer->Stop();
}

// @0x140003540
void VideoProviderNetStream::Pause(bool pause)
{
    if (pVideoPlayer)
        pVideoPlayer->Pause(pause);
}

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

// Gives the main and sub-audio sound channels the audio target sprite's volumes and adds them to its active sounds.
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
                ((Scaleform::GFx::MovieImpl*)(void*)(proot))->AddVideoProvider(this);
        }
        InitSoundChannel();
    }
}

// Moves the main track's sound from the old audio target sprite to ptarget, then makes ptarget the audio target.
// @0x140005fc0
void VideoProviderNetStream::SetAudioTarget(Sprite* ptarget)
{
    Sprite* pold = NULL;
    if (pAudioTarget)
    {
        DisplayObject* pch = pAudioTarget->pCharacter;
        if (pch)
        {
            if (pch->IsSprite())
                pold = (Sprite*)pch;
            else
            {
                DisplayObject* pparent = (DisplayObject*)pch->pParent;
                if (pparent && pparent->IsSprite())
                    pold = (Sprite*)pparent;
            }
        }
    }
    if (pold == ptarget)
        return;
    if (pold && pVideoPlayer)
    {
        VideoPlayer* pplayer = *reinterpret_cast<VideoPlayer* volatile*>(&pVideoPlayer);
        Sound::SoundChannel* pchan = pplayer->GetSoundChannel(VideoPlayer::MainTrack);
        if (pchan)
        {
            Ptr<Sprite::ActiveSoundItem> pitem = MakePickable(pold->ReleaseActiveSound(pchan));
            if (pitem)
            {
                pitem->pChannel->SetVolume(ptarget->GetRealSoundVolume());
                ptarget->AttachActiveSound(pitem);
            }
            else
            {
                pchan->SetVolume(ptarget->GetRealSoundVolume());
                ptarget->AddActiveSound(pchan, NULL, NULL);
            }
        }
    }
    CharacterHandle* phandle = ptarget->GetCharacterHandle();
    if (phandle)
        phandle->AddRef();
    CharacterHandle* pprev = pAudioTarget.GetPtr();
    if (pprev)
        pprev->Release();
    *reinterpret_cast<CharacterHandle**>(&pAudioTarget) = phandle;
}

// NetStream.attachAudio: hands the target sprite to the stream's video provider (AS2VideoSupportImpl::AttachAudio forwards here).
// @0x140006ba0
void FUN_140006ba0(NetStream* pnetStream, Sprite* pchar)
{
    pnetStream->GetVideoProvider()->SetAudioTarget(pchar);
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

// @0x140006120
SwfVideoSyncObject::SwfVideoSyncObject(Sprite* ptarget)
    : pTarget(ptarget), StartFrame(ptarget->GetCurrentFrame()), FrameTime(ptarget->GetMovieImpl()->FrameTime)
{
}

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

// @0x140004da0
VideoImage* VideoProviderNetStream::GetTexture(int* width, int* height)
{
    if (!pVideoPlayer)
        return NULL;
    if (!pTextureImage)
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

// The virtual Movie::GetHeap (vftable slot 47); this unit has no Movie view, so the slot is called directly.
static inline MemoryHeap* Video01MovieGetHeap(const MovieImpl* proot)
{
    typedef MemoryHeap* (*GetHeapFn)(const MovieImpl*);
    return (*reinterpret_cast<GetHeapFn const* const*>(proot))[47](proot);
}

// MS2-FUNCTIONAL: regalloc and frame layout; the exe keeps this in r14 and the state bag in rbp (proot spilled to a
// home slot), puts fileName at [rsp+0x30] instead of a home slot, and its frame is 0x10 larger
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
    StateBag* pstates = proot->GetStateBag();
    if (!pVideoPlayer)
    {
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
            pVideoPlayer = pvideo->CreateVideoPlayer(Video01MovieGetHeap(proot), ptaskMgr, pfileOpener, plog);
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
        CharacterHandle* phandle = penv->GetTarget()->GetCharacterHandle();
        if (phandle)
            phandle->AddRef();
        CharacterHandle* pprev = pTarget.GetPtr();
        if (pprev)
            pprev->Release();
        *reinterpret_cast<CharacterHandle**>(&pTarget) = phandle;
        ((Scaleform::GFx::MovieImpl*)(void*)(proot))->AddVideoProvider(this);
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
        {
            CharacterHandle* paudio = proot->pASMovieRoot->GetRootMovie()->GetCharacterHandle();
            if (paudio)
                paudio->AddRef();
            CharacterHandle* pold = pAudioTarget.GetPtr();
            if (pold)
                pold->Release();
            *reinterpret_cast<CharacterHandle**>(&pAudioTarget) = paudio;
        }
    }
}

// @0x14000c4a0
float VideoProviderNetStream::GetFrameTime()
{
    return FrameTime;
}

// ==== NetStream ======================================================================================================

// @0x14000cc10
void NetStream::commonInit(Environment* penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_NetStream));
    pVideoProvider = *SF_HEAP_NEW(penv->GetHeap()) VideoProviderNetStream(this);
}

// @0x14000cc90
NetStream::NetStream(Environment* penv)
    : Object(penv), Paused(false)
{
    commonInit(penv);
}

// @0x140007ce0
NetStream::NetStream(ASStringContext* psc, Object* pprototype)
    : Object(psc), Paused(false)
{
    Object::Set__proto__(psc, pprototype);
}

inline void NetStream::ReleaseVideoProvider()
{
    if (pVideoProvider)
    {
        pVideoProvider->NotifyNetStreamRemoved();
        pVideoProvider->Stop();
    }
}

// @0x140008070
NetStream::~NetStream()
{
    ReleaseVideoProvider();
}

// @0x1400056d0
void NetStream::Finalize_GC()
{
    ReleaseVideoProvider();
    pVideoProvider.~Ptr<VideoProviderNetStream>();
    Object::Finalize_GC();
}

// The exe keeps the three instantiations out of line (pinned at the end of the file).
// MS2-FUNCTIONAL: other scheduling
template<class Functor>
SF_NOINLINE void NetStream::ForEachChild_GC(Collector* prcc) const
{
    Object::template ForEachChild_GC<Functor>(prcc);
    OnSubtitleCallback.template ForEachChild_GC<Functor>(prcc);
    OnMetaDataCallback.template ForEachChild_GC<Functor>(prcc);
    OnStatusCallback.template ForEachChild_GC<Functor>(prcc);
    OnCuePointCallback.template ForEachChild_GC<Functor>(prcc);
}

// @0x140007fb0
void NetStream::ExecuteForEachChild_GC(Collector* prcc, OperationGC operation) const
{
    ASRefCountBaseType::CallForEachChild<NetStream>(prcc, operation);
}

// @0x140008250
bool NetStream::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    if (name == "onMetaData")
    {
        FunctionRef function = val.ToFunction_Call(penv);
        OnMetaDataCallback = function;
        return true;
    }
    else if (name == "onStatus")
    {
        FunctionRef function = val.ToFunction_Call(penv);
        OnStatusCallback = function;
        return true;
    }
    else if (name == "onCuePoint")
    {
        FunctionRef function = val.ToFunction_Call(penv);
        OnCuePointCallback = function;
        return true;
    }
    if (penv->CheckExtensions())
    {
        if (name == "onSubtitle")
        {
            FunctionRef function = val.ToFunction_Call(penv);
            OnSubtitleCallback = function;
            return true;
        }
        else if (name == "subtitleTrack")
        {
            if (!OnSubtitleCallback.IsNull())
            {
                int channel = (int)val.ToNumber(penv) - 1;
                pVideoProvider->SetSubtitleChannel(channel);
            }
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
                pVideoProvider->SetSwfSync(val.ToBool(penv),
                                           (Sprite*)static_cast<const ObjectInterface*>(pavm)->ToSprite());
            }
        }
    }
    return Object::SetMember(penv, name, val, flags);
}

Value* FUN_142923b90(Value* pthis, const FunctionRef& func);   // sfr_as2_03, Value(const FunctionRef&) out of line

// Raw room for a Value the exe builds through FUN_142923b90.
struct Video01ValueStorage
{
    Video01ValueStorage() {}
    Scaleform::UInt64 Raw0, Raw1, Raw2, Raw3;
};

// *val = Value(func), with the FUNCTION Value built by the exe's out-of-line constructor.
static __forceinline void AssignFunctionValue(Value* val, const FunctionRef& func)
{
    Video01ValueStorage storage;
    Value& function = *reinterpret_cast<Value*>(&storage);
    FUN_142923b90(&function, func);
    *val = function;
    function.~Value();
}

static __forceinline UInt32 NetStreamPosition(VideoProviderNetStream* provider)
{
    return provider->GetPosition();
}

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
            AssignFunctionValue(val, OnSubtitleCallback);
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
            *val = Value((Number)(float)(NetStreamPosition(pVideoProvider) + 1));
            return true;
        }
    }
    if (name == "time")
    {
        UInt32 pos       = NetStreamPosition(pVideoProvider);
        UInt32 frameRate = pVideoProvider->GetVideoInfo().FrameRate;
        if (frameRate)
            *val = Value((Number)((float)pos / ((float)frameRate / 1000.0f)));
        else
            *val = Value((Number)0);
        return true;
    }
    else if (name == "onMetaData")
    {
        AssignFunctionValue(val, OnMetaDataCallback);
        return true;
    }
    else if (name == "onStatus")
    {
        AssignFunctionValue(val, OnStatusCallback);
        return true;
    }
    else if (name == "onCuePoint")
    {
        AssignFunctionValue(val, OnCuePointCallback);
        return true;
    }
    else if (name == "currentFps")
    {
        float fps = (float)pVideoProvider->GetVideoInfo().FrameRate / 1000.0f;
        *val = Value((Number)fps);
        return true;
    }
    return Object::GetMember(penv, name, val);
}

// @0x140005720
void NetStream::Seek(Number pos, Environment* penv)
{
    MovieImpl* proot = penv->GetMovieImpl();
    pVideoProvider->Seek((float)pos, proot);
}

// ---- NetStream.prototype

// @0x1400047a0
void NetStreamProto::Close(const FnCall& fn)
{
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream)
        return;
    pnetstream->Stop();
    // close(true) also drops the player
    if (fn.NArgs > 0 && ArgCopy(&fn, 0)->ToBool(fn.Env))
        pnetstream->GetVideoProvider()->Close();
}

// @0x140004810
void NetStreamProto::Pause(const FnCall& fn)
{
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream)
        return;
    if (fn.NArgs > 0)
        pnetstream->Pause(ArgCopy(&fn, 0)->ToBool(fn.Env));
    else
        pnetstream->Pause();
}

// @0x140004880
void NetStreamProto::SetBufferTime(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.setBufferTime requires one argument (time)\n");
        return;
    }
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream || !ArgCopy(&fn, 0)->IsNumber())
        return;
    pnetstream->SetBufferTime(ArgCopy(&fn, 0)->ToNumber(fn.Env));
}

// @0x140004920
void NetStreamProto::SetNumberOfFramePools(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.setNumberOfFramePools requires one argument (pools)\n");
        return;
    }
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream || !ArgCopy(&fn, 0)->IsNumber())
        return;
    pnetstream->SetNumberOfFramePools(ArgCopy(&fn, 0)->ToNumber(fn.Env));
}

// @0x1400049c0
void NetStreamProto::SetReloadThresholdTime(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.setReloadThresholdTime requires one argument (time)\n");
        return;
    }
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream || !ArgCopy(&fn, 0)->IsNumber())
        return;
    pnetstream->SetReloadThresholdTime(ArgCopy(&fn, 0)->ToNumber(fn.Env));
}

// @0x140004a60
void NetStreamProto::SetOpenURLTimeout(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.setOpenTimeout requires one argument (timeout)\n");
        return;
    }
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream || !ArgCopy(&fn, 0)->IsNumber())
        return;
    pnetstream->SetOpenURLTimeout(ArgCopy(&fn, 0)->ToNumber(fn.Env));
}

// Reads an array of numbers as (x, y, z) triples.
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

// MS2-FUNCTIONAL: other scheduling
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
    ReadVectorArray(penv, *ArgCopy(&fn, 0), position);
    pnetstream->GetVideoProvider()->SetSpatialInfo(0, position);
    if (fn.NArgs > 1)
    {
        Array<Sound::SoundChannel::Vector> orientation;
        ReadVectorArray(penv, *ArgCopy(&fn, 1), orientation);
        pnetstream->GetVideoProvider()->SetSpatialInfo(1, orientation);
    }
    if (fn.NArgs > 2)
    {
        Array<Sound::SoundChannel::Vector> velocity;
        ReadVectorArray(penv, *ArgCopy(&fn, 2), velocity);
        pnetstream->GetVideoProvider()->SetSpatialInfo(2, velocity);
    }
    pnetstream->GetVideoProvider()->ApplySpatialInfo();
}

// @0x140005780
void NetStreamProto::Seek(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.seek requires one argument (offset)\n");
        return;
    }
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (!pnetstream || !ArgCopy(&fn, 0)->IsNumber())
        return;
    pnetstream->Seek(ArgCopy(&fn, 0)->ToNumber(fn.Env), fn.Env);
}

// MS2-FUNCTIONAL: other scheduling
// @0x14000c9f0
void NetStreamProto::Play(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: NetStream.Play requires one argument (file name)\n");
        return;
    }
    ASString url = ArgCopy(&fn, 0)->ToString(fn.Env);
    NetStream* pnetstream = static_cast<NetStream*>(fn.ThisPtr);
    if (pnetstream)
        pnetstream->OpenUrl(url.ToCStr(), fn.Env);
}

// @0x140009cf0
void VideoProviderNetStream::RegisterVideoCharacter(VideoCharacter* pvideo)
{
    if (!pvideo)
        return;
    for (UPInt i = 0; i < VideoCharacters.GetSize(); ++i)
    {
        Ptr<VideoCharacter> pchar = VideoCharacters[i];
        if (pvideo == pchar)
            return;
    }
    VideoCharacters.PushBack(WeakPtr<VideoCharacter>(pvideo));
}

// Removes and returns the first video character, and drops the texture image.
// @0x14000af10
VideoCharacter* VideoProviderNetStream::RemoveFirstVideoCharacter()
{
    if (VideoCharacters.GetSize() > 0)
    {
        Ptr<VideoCharacter> pvideo = VideoCharacters[0];
        VideoCharacters.RemoveAt(0);
        pTextureImage = NULL;
        return pvideo;
    }
    return NULL;
}

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

// Calls onStatus with a {level, code} object on the target's environment. Like the exe, it does not check that
// environment for NULL. The strings come through the out-of-line GetStringManager, and the stack pop is written
// out, since cl's inline budget here would call Drop1 out of line where the exe inlines it.
// @0x140008860
void VideoProviderNetStream::SendNotification(const char* note, bool error)
{
    if (!pTarget || !pNetStream || pNetStream->OnStatusCallback.IsNull())
        return;
    DisplayObject* pch = pTarget->pCharacter;
    InteractiveObject* pchar = pch->IsInteractiveObject() ? (InteractiveObject*)pch : NULL;
    if (!pchar)
        return;
    AvmDisplayObjBase* pavm = reinterpret_cast<AvmDisplayObjBase*>(reinterpret_cast<UInt32*>(pchar) + pchar->AvmObjOffset);
    Environment* penv = static_cast<AvmCharacter*>(pavm->ToAvmInteractiveObjBase())->GetASEnvironment();

    Ptr<Object> pobj = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
    if (error)
        pobj->SetConstMemberRaw(penv->GetSC(), "level",
                                Value(penv->GetSC()->pContext->GetStringManager()->CreateConstString("error")));
    else
        pobj->SetConstMemberRaw(penv->GetSC(), "level",
                                Value(penv->GetSC()->pContext->GetStringManager()->CreateConstString("status")));
    pobj->SetConstMemberRaw(penv->GetSC(), "code",
                            Value(penv->GetSC()->pContext->GetStringManager()->CreateConstString(note)));

    penv->Push(pobj.GetPtr());
    Value ret;
    pNetStream->OnStatusCallback.Invoke(FnCall(&ret, pNetStream, penv, 1, penv->GetTopIndex()));
    PagedStack<Value, 32>& stack = penv->Stack;
    stack.pCurrent->~Value();
    if (--stack.pCurrent < stack.pPageStart)
        stack.PopPage();
}

// Sets one named member: the caller builds the Value, the key string and default flags are built here.
static __forceinline void SetCuePointMember(Object* pobj, Environment* penv, const char* name, const Value& v)
{
    pobj->SetMemberRaw(penv->GetSC(), penv->GetSC()->pContext->GetStringManager()->CreateConstString(name), v);
}

// A cue point as a script object: name, time in seconds, type and its parameters.
// MS2-FUNCTIONAL: same length (1413) as the exe. Left: the params loop holds the Params data pointer and name node in rbx (ours rax/rdi) and the value node in rdi (ours rbx), and stores the string Value type before reading the name (ours after). The members "name", "type" and "parameters" go through SetCuePointMember, which builds the key string, flags and Value after the caller-built value, as the exe does.
// @0x140008bb0
static Object* ConvertCuePoint(const VideoPlayer::CuePoint& cp, Environment* penv)
{
    Object* pobj = SF_HEAP_NEW(penv->GetHeap()) Object(penv);
    SetCuePointMember(pobj, penv, "name", Value(penv->GetSC()->pContext->GetStringManager()->CreateString(cp.Name.ToCStr())));
    pobj->SetMemberRaw(penv->GetSC(), penv->GetSC()->pContext->GetStringManager()->CreateConstString("time"),
                       (Number)(cp.Time / 1000.0f));
    SetCuePointMember(pobj, penv, "type",
                      Value(cp.Type == VideoPlayer::NavigationCuePoint
                                ? penv->GetSC()->pContext->GetStringManager()->CreateConstString("navigation")
                                : penv->GetSC()->pContext->GetStringManager()->CreateConstString("event")));
    if (cp.Params.GetSize() > 0)
    {
        Ptr<Object> pparams = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
        for (UPInt i = 0; i < cp.Params.GetSize(); ++i)
        {
            // The exe builds an object per parameter that it never uses.
            Ptr<Object> pparam = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
            pparams->SetMemberRaw(penv->GetSC(), penv->GetSC()->pContext->GetStringManager()->CreateString(cp.Params[i].Name.ToCStr()),
                                  Value(penv->GetSC()->pContext->GetStringManager()->CreateString(cp.Params[i].Value.ToCStr())));
        }
        SetCuePointMember(pobj, penv, "parameters", Value(pparams.GetPtr()));
    }
    return pobj;
}

// Builds the metadata object and calls onMetaData on the target's environment. Like the exe, it does not
// check that environment for NULL.
// @0x140009140
void VideoProviderNetStream::SendMetaInformation()
{
    if (!pNetStream || !pTarget || pNetStream->OnMetaDataCallback.IsNull())
        return;
    DisplayObject* pch = pTarget->pCharacter;
    InteractiveObject* pchar = pch->IsInteractiveObject() ? (InteractiveObject*)pch : NULL;
    if (!pchar)
        return;
    AvmDisplayObjBase* pavm = reinterpret_cast<AvmDisplayObjBase*>(reinterpret_cast<UInt32*>(pchar) + pchar->AvmObjOffset);
    Environment* penv = static_cast<AvmCharacter*>(pavm->ToAvmInteractiveObjBase())->GetASEnvironment();

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
            Ptr<ArrayObject> ptracks = *static_cast<ArrayObject*>(penv->OperatorNew(penv->GetSC()->pContext->GetStringManager()->GetBuiltin(ASBuiltin_Array)));
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
        Ptr<ArrayObject> pcuePoints = *static_cast<ArrayObject*>(penv->OperatorNew(penv->GetSC()->pContext->GetStringManager()->GetBuiltin(ASBuiltin_Array)));
        for (UPInt i = 0; i < VInfo.CuePoints.GetSize(); ++i)
        {
            Ptr<Object> pcuePoint = *ConvertCuePoint(VInfo.CuePoints[i], penv);
            pcuePoints->PushBack(Value(pcuePoint));
        }
        pobj->SetConstMemberRaw(penv->GetSC(), "cuePoints", Value(pcuePoints));
    }

    penv->Push(pobj.GetPtr());
    Value ret;
    pNetStream->OnMetaDataCallback.Invoke(FnCall(&ret, pNetStream, penv, 1, penv->GetTopIndex()));
    PagedStack<Value, 32>& stack = penv->Stack;
    stack.pCurrent->~Value();
    if (--stack.pCurrent < stack.pPageStart)
        stack.PopPage();
}

// Calls onCuePoint once per cue point on the target's environment. Like the exe, it does not check that
// environment for NULL.
// @0x140009850
void VideoProviderNetStream::SendCuePoints(const Array<VideoPlayer::CuePoint>& cuePoints)
{
    if (!pNetStream || !pTarget || pNetStream->OnCuePointCallback.IsNull() || cuePoints.GetSize() <= 0)
        return;
    DisplayObject* pch = pTarget->pCharacter;
    InteractiveObject* pchar = pch->IsInteractiveObject() ? (InteractiveObject*)pch : NULL;
    if (!pchar)
        return;
    AvmDisplayObjBase* pavm = reinterpret_cast<AvmDisplayObjBase*>(reinterpret_cast<UInt32*>(pchar) + pchar->AvmObjOffset);
    Environment* penv = static_cast<AvmCharacter*>(pavm->ToAvmInteractiveObjBase())->GetASEnvironment();

    for (UPInt i = 0; i < cuePoints.GetSize(); ++i)
    {
        Ptr<Object> pcuePoint = *ConvertCuePoint(cuePoints[i], penv);
        penv->Push(pcuePoint.GetPtr());
        Value ret;
        pNetStream->OnCuePointCallback.Invoke(FnCall(&ret, pNetStream, penv, 1, penv->GetTopIndex()));
        penv->Drop1();
    }
}

// Pushes the subtitle text and calls onSubtitle on the target's environment. Like the exe, it does not
// check the environment for NULL, and it holds a second, unused Value besides the result.
// @0x140009ad0
void VideoProviderNetStream::SendSubtitleInformation()
{
    if (!pTarget)
        return;
    DisplayObject* pch = pTarget->pCharacter;
    InteractiveObject* pchar = pch->IsInteractiveObject() ? (InteractiveObject*)pch : NULL;
    if (!pchar)
        return;
    AvmDisplayObjBase* pavm = reinterpret_cast<AvmDisplayObjBase*>(reinterpret_cast<UInt32*>(pchar) + pchar->AvmObjOffset);
    Value unused;
    Environment* penv = static_cast<AvmCharacter*>(pavm->ToAvmInteractiveObjBase())->GetASEnvironment();
    penv->Push(penv->GetSC()->pContext->GetStringManager()->CreateString(pSubtitleMsg));
    Value ret;
    pNetStream->OnSubtitleCallback.Invoke(FnCall(&ret, pNetStream, penv, 1, penv->GetTopIndex()));
    penv->Drop1();
}

static __forceinline void AdoptTexture(Ptr<VideoImage>& ptr, VideoImage& src)
{
    if (ptr)
        ptr->Release();
    ptr.GetRawRef() = &src;
}

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
    case VideoPlayer::Playing:
        if (!SeekNotificationSent && FrameIsReady)
        {
            SeekNotificationSent = true;
            SendNotification("NetStream.Seek.Notify", false);
        }
        break;

    case VideoPlayer::Ready:
        if (!pTextureImage)
        {
            AdoptTexture(pTextureImage, *pVideoPlayer->CreateTexture(pTextureManager));
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

// The exe reads the name through the out-of-line GlobalContext::GetStringManager and sets default PropFlags.
// It takes no flags: its callers pass four arguments. The exe never inlines it.
// @0x1400054b0
SF_NOINLINE bool ObjectInterface::SetConstMemberRaw(ASStringContext* psc, const char* name, const Value& val)
{
    return SetMemberRaw(psc, psc->pContext->GetStringManager()->CreateConstString(name), val, PropFlags());
}

// ==== NetStream constructor function ================================================================================

// @0x14000cd30
Object* NetStreamCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) NetStream(penv);
}

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

// @0x14000d400
void VideoProto::AttachVideo(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Error: Video.attachVideo requires one argument (NetStream object)\n");
        return;
    }
    if (!ArgCopy(&fn, 0)->IsObject() || !fn.ThisPtr || fn.ThisPtr->GetObjectType() != Object::Object_Video)
        return;

    VideoCharacter* pvideo    = (VideoCharacter*)static_cast<AvmCharacter*>(fn.ThisPtr)->GetDispObj();
    VideoProvider*  pprovider = NULL;
    if (ArgCopy(&fn, 0)->ToObject(fn.Env)->GetObjectType() == Object::Object_NetStream)
    {
        NetStream* pnetstream = static_cast<NetStream*>(ArgCopy(&fn, 0)->ToObject(fn.Env));
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

// VideoObject: include/video/video_as2videoobject.h

// "constructor" and "__constructor__" are answered by the prototype part (as sfr_as2_07b's Prototype<SoundObject>).
// @0x14000a110
template<>
bool Prototype<NetStream>::GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val)
{
    // The builtins come through GlobalContext::GetStringManager here (not inlined into this file).
    bool isConstructor2 = psc->pContext->GetStringManager()->GetBuiltin(ASBuiltin___constructor__)
                              .CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive());
    if (isConstructor2 || psc->pContext->GetStringManager()->GetBuiltin(ASBuiltin_constructor)
                              .CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive()))
    {
        return GetMemberRawConstructor(this, psc, name, val, isConstructor2);
    }
    return NetStream::GetMemberRaw(psc, name, val);
}

// "constructor" and "__constructor__" are answered by the prototype part.
// @0x14000d760
template<>
bool Prototype<VideoObject>::GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val)
{
    // The builtins come through GlobalContext::GetStringManager here (not inlined into this file).
    bool isConstructor2 = psc->pContext->GetStringManager()->GetBuiltin(ASBuiltin___constructor__)
                              .CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive());
    if (isConstructor2 || psc->pContext->GetStringManager()->GetBuiltin(ASBuiltin_constructor)
                              .CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive()))
    {
        return GetMemberRawConstructor(this, psc, name, val, isConstructor2);
    }
    return VideoObject::GetMemberRaw(psc, name, val);
}

// The Video class (constructor function).
class VideoCtorFunction : public CFunctionObject
{
public:
    virtual Object* CreateNewObject(Environment* penv) const;   // exe 0x14000e0c0

    static void GlobalCtor(const FnCall& fn);   // exe 0x14000e100
};

// The builtin name is read through the out-of-line GlobalContext::GetStringManager, as in the exe.
// @0x140007ba0
void Object::Set__proto__(ASStringContext* psc, Object* protoObj)
{
    if (!pProto)
        SetMemberRaw(psc, psc->pContext->GetStringManager()->GetBuiltin(ASBuiltin___proto__), Value(Value::UNSET),
                     PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = protoObj;
}

// @0x14000de10
VideoObject::VideoObject(ASStringContext* psc, Object* pprototype)
    : Object(psc)
{
    Set__proto__(psc, pprototype);
}

// Takes the prototype from the character's environment. The AVM character is found inline, NULL for a NULL
// character (which the exe then dereferences anyway).
// @0x14000dee0
VideoObject::VideoObject(GlobalContext* gCtxt, InteractiveObject* pcharacter)
    : Object(gCtxt->GetGC()), pCharacter(pcharacter)
{
    AvmCharacter* pavm = NULL;
    if (pcharacter)
        pavm = static_cast<AvmCharacter*>(reinterpret_cast<AvmDisplayObjBase*>(
            reinterpret_cast<UInt32*>(pcharacter) + pcharacter->AvmObjOffset)->ToAvmInteractiveObjBase());
    Environment* penv = pavm->GetASEnvironment();
    Set__proto__(penv->GetSC(), gCtxt->GetPrototype(ASBuiltin_Video));
}

// @0x14000dfb0
VideoObject::VideoObject(Environment* penv)
    : Object(penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Video));
}

// The Prototype<VideoObject> ctor: the inlined VideoObject part, then GASPrototypeBase() at +0x70 and Init.
// @0x14000e1e0
template<> Prototype<VideoObject>::Prototype(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : VideoObject(psc, pprototype)
{
    Init(this, psc, constructor);
}
//
//
//
//
//
//
//
//
//
static __forceinline void Video01VideoPrototypeDtor(Object* object) { static_cast<Prototype<VideoObject>*>(object)->Prototype<VideoObject>::~Prototype(); }   // FUN_14000d680

// No exe row. FUN_14000e1e0 and NetStreamProtoConstruct inline the Prototype<VideoObject> and Prototype<NetStream>
// ctors by hand, so no other TU instantiates them. This function does: their vftables and virtuals are the targets of
// the DAT_140009ef0.., DAT_14000d6f0.. and DAT_1431b5478.. rows of data_rdata_sf_video.cpp, which are stubs in fullexe
// without them.
void Video01EmitPrototypeVtables(void* netStream, void* video, ASStringContext* context, Object* prototype,
                                 const FunctionRef& constructor)
{
    ::new (netStream) Prototype<NetStream>(context, prototype, constructor);
    ::new (video) Prototype<VideoObject>(context, prototype, constructor);
}
// (NetStreamProto's ctor is 0x14000ae30 below.)
// Lazily allocates and caches the script VideoObject for its display character. The exe calls GetGC()
// before it reads the display object.
// @0x14000e020
VideoObject* FUN_14000e020(AvmCharacter* character)
{
    unsigned char* bytes = reinterpret_cast<unsigned char*>(character);
    VideoObject** slot = reinterpret_cast<VideoObject**>(bytes + 0x48);
    if (!*slot) {
        void* storage = FUN_14000d360(0x70, character);
        GlobalContext* gc;
        VideoObject* created = storage ? (gc = character->GetGC(), ::new (storage) VideoObject(gc, character->GetDispObj())) : 0;
        ReleaseAs2GCObject(*slot);
        *slot = created;
    }
    return *slot;
}

// (the video character's own fields at +0x38 are the AvmVideoCharacterFields base of the header)
//
//
//
//
//
//
//
//

// Initializes the AVM video-character bases and retains its lazily created VideoObject state. The exe does
// not check that object for NULL.
// @0x14000e2b0
AvmVideoCharacter::AvmVideoCharacter(InteractiveObject* displayObject) : AvmCharacter(displayObject)
{
    AvmCharacter* character = this;
    unsigned char* bytes = reinterpret_cast<unsigned char*>(character);
    VideoObject* video = FUN_14000e020(character);
    void* held = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(video) + 0x30);
    if (held) {
        unsigned* count = reinterpret_cast<unsigned*>(static_cast<unsigned char*>(held) + 0x18);
        *count = (*count + 1) & 0x8fffffff;
    }
    ReleaseAs2GCObject(*reinterpret_cast<void**>(bytes + 0x18));
    *reinterpret_cast<void**>(bytes + 0x18) = held;
}
//
//
//
//
//
//

// (the exe's temporary strong pointers add and release two references, net zero).
// @0x14000daa0
InteractiveObject* VideoObject::GetASCharacter()
{
    Ptr<InteractiveObject> strong = pCharacter;
    return strong.GetPtr();
}

// @0x14000db10
const InteractiveObject* VideoObject::GetASCharacter() const
{
    Ptr<InteractiveObject> strong = pCharacter;   // the exe inlines the non-const lookup
    return strong.GetPtr();
}

// @0x14000db80
void VideoObject::Finalize_GC()
{
    pCharacter.~WeakPtr();
    Object::Finalize_GC();
}

// @0x14000e0c0
Object* VideoCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) VideoObject(penv);
}

// @0x14000e100
void VideoCtorFunction::GlobalCtor(const FnCall& fn)
{
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object::Object_Video && !fn.ThisPtr->IsBuiltinPrototype())
        fn.Result->SetAsObject(static_cast<Object*>(fn.ThisPtr));
    else
        fn.Result->SetAsObject(SF_HEAP_NEW(fn.Env->GetHeap()) VideoObject(fn.Env));
}

// constructs the NetStream prototype base and initializes its constructor links.
// @0x140009e20
template<> Prototype<NetStream>::Prototype(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : NetStream(psc, pprototype)
{
    Init(this, psc, constructor);
}
//
//
//
//
//
//
//
//
//
//
//

// adds the public close method and installs the NetStreamProto virtual tables.
// @0x14000ae30
NetStreamProto::NetStreamProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<NetStream>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, NetStreamCloseFunctionTable, PropFlags(1));
}
//
//
//
//
//
//
//

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

// creates the NetStream constructor/prototype pair, registers the prototype and publishes the class.
// @0x14000cf20
FunctionRef FUN_14000cf20(GlobalContext* global)
{
    ASStringContext context(global, 8);
    FunctionRef constructor(*SF_HEAP_NEW(global->pHeap) NetStreamCtorFunction(&context));

    void* storage = Scaleform::Memory::AllocInHeap(global->pHeap, 0x120);
    Object* created = storage ? ::new (storage) NetStreamProto(&context, global->GetPrototype(ASBuiltin_Object), constructor)
//
                              : 0;
    Ptr<Object> proto(created);

    {
        Object* registered = proto;
        FUN_14000c280(global, 0x23, reinterpret_cast<void**>(&registered));
    }
    {
        PropFlags flags;
        // The exe builds and destroys the member value out of line (0x142923b90 / 0x1429260b0).
        Video01ValueStorage valueStorage;
        global->pGlobal->SetMemberRaw(&context, global->GetStringManager()->GetBuiltin(ASBuiltin_NetStream),
                                      *FUN_142923b90(reinterpret_cast<Value*>(&valueStorage), constructor), flags);
        reinterpret_cast<Value*>(&valueStorage)->Value::~Value();
    }
    return constructor;
}

}}} // namespace Scaleform::GFx::AS2

// The complete and deleting destructors of SwfVideoSyncObject: its inline dtor stores the own (0x1431b4fe8) vftable,
// releases the target proxy, and ~SyncObject stores 0x1431b4f78 before the base dtor.
// @0x140006290
void FUN_140006290(void* object)
{
    static_cast<Scaleform::GFx::AS2::SwfVideoSyncObject*>(object)->SwfVideoSyncObject::~SwfVideoSyncObject();
}

// @0x1400062e0
void* FUN_1400062e0(void* object, unsigned flags)
{
    static_cast<Scaleform::GFx::AS2::SwfVideoSyncObject*>(object)->SwfVideoSyncObject::~SwfVideoSyncObject();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// A view that reaches the collector's protected pass functors (never constructed).
struct Video01NetStreamGc : Scaleform::GFx::AS2::NetStream
{
    static __forceinline void Dispatch(const Scaleform::GFx::AS2::NetStream* stream, Collector* collector, int operation)
    {
        switch (operation)
        {
        case 0: stream->ForEachChild_GC<ReleaseFunctor>(collector); break;
        case 1: stream->ForEachChild_GC<MarkInCycleFunctor>(collector); break;
        case 2: stream->ForEachChild_GC<ScanInUseFunctor>(collector); break;
        }
    }
};

// A second copy of NetStream::ExecuteForEachChild_GC (0x140007fb0): the collector passes over a NetStream's children.
// @0x140007f70
void FUN_140007f70(void* object, Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector,
                   int operation)
{
    Video01NetStreamGc::Dispatch(static_cast<const Scaleform::GFx::AS2::NetStream*>(object), collector, operation);
}

namespace Scaleform { namespace GFx { namespace AS2 {
// The video object vtable points at these small AS2 base implementations in the executable.
// @0x140007d90
bool ObjectInterface::IsSuper() const { return false; }
// @0x140007da0
bool ObjectInterface::IsBuiltinPrototype() const { return false; }
// @0x140007db0
void ObjectInterface::AddInterface(ASStringContext*, int, FunctionObject*) {}
// @0x140007dc0
const char* Object::GetTextValue(Environment*) const { return 0; }
// @0x140007dd0
bool Object::DoesImplement(Environment*, const Object* prototype) const { return this == prototype; }
// @0x140007de0
InteractiveObject* Object::GetASCharacter() { return 0; }
// @0x140007df0
const InteractiveObject* Object::GetASCharacter() const { return 0; }
// @0x140007e00
void Object::CheckAndResetCtorRef(FunctionObject*) {}
// @0x14000ce70
ObjectInterface::ObjectType FunctionObject::GetObjectType() const { return static_cast<ObjectType>(0x17); }
// @0x14000ce80
bool FunctionObject::IsAsFunction() const { return false; }
// The executable tests the native callback pointer at object offset 0x68 for null.
// @0x14000ce90
bool CFunctionObject::IsNull() const
{
    return *reinterpret_cast<void* const*>(reinterpret_cast<const unsigned char*>(this) + 0x68) == 0;
}
// @0x14000cea0
bool CFunctionObject::IsCFunction() const { return true; }
// The native function wrapper uses -1 as its variable-argument count sentinel.
// @0x14000ceb0
int CFunctionObject::GetNumArgs() const { return -1; }
// @0x14000e370
const char* ObjectInterface::GetTextValue(Environment*) const { return 0; }
}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7NetStream@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b5030
// MS2-PIN: ??_7NetStream@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b5080
// MS2-PIN: ??_7VideoProviderNetStream@AS2@GFx@Scaleform@@6B@ 0x1431b5620
// MS2-PIN: ??_7VideoProvider@Video@GFx@Scaleform@@6B@ 0x1431b4f30
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??1FnCall@AS2@GFx@Scaleform@@UEAA@XZ 0x140007af0
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
// MS2-PIN: ??_7?$Prototype@VVideoObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b59f0
// MS2-PIN: ??_7?$Prototype@VVideoObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b5940
// MS2-PIN: ??_7?$Prototype@VVideoObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x1431b5938
// MS2-PIN: ??_7?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b53c0
// MS2-PIN: ??_7?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b5310
// MS2-PIN: ??_7?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x1431b5300
// MS2-PIN: ??_7NetStreamProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b5480
// MS2-PIN: ??_7NetStreamProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b54d0
// MS2-PIN: ??_7NetStreamProto@AS2@GFx@Scaleform@@6B@ 0x1431b5478
// MS2-PIN: ??_E?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@WNI@EAAPEAXI@Z 0x14000a010
// MS2-PIN: ??_E?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@WCA@EAAPEAXI@Z 0x14000a020
// MS2-PIN: ??_ENetStreamProto@AS2@GFx@Scaleform@@WNI@EAAPEAXI@Z 0x14000aeb0
// MS2-PIN: ??_ENetStreamProto@AS2@GFx@Scaleform@@WCA@EAAPEAXI@Z 0x14000aea0
// The base table is a distinct address point before the NetStream prototype table.
// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// MS2-PIN: ??_7RefCountWeakSupportImpl@Scaleform@@6B@ 0x143183cf8
// MS2-PIN: ??_7SyncObject@VideoPlayer@Video@GFx@Scaleform@@6B@ 0x1431b4f78
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountWeakSupportImpl@Scaleform@@$01@Scaleform@@6B@ 0x143183cf8
// MS2-PIN: ??_7?$RefCountBaseWeakSupport@VVideoProvider@Video@GFx@Scaleform@@$01@Scaleform@@6B@ 0x1431b4f30
// MS2-PIN: ?IsSuper@ObjectInterface@AS2@GFx@Scaleform@@UEBA_NXZ 0x140007d90
// MS2-PIN: ?IsBuiltinPrototype@ObjectInterface@AS2@GFx@Scaleform@@UEBA_NXZ 0x140007da0
// MS2-PIN: ?AddInterface@ObjectInterface@AS2@GFx@Scaleform@@UEAAXPEAVASStringContext@234@HPEAVFunctionObject@234@@Z 0x140007db0
// MS2-PIN: ?GetTextValue@Object@AS2@GFx@Scaleform@@UEBAPEBDPEAVEnvironment@234@@Z 0x140007dc0
// MS2-PIN: ?DoesImplement@Object@AS2@GFx@Scaleform@@UEBA_NPEAVEnvironment@234@PEBV1234@@Z 0x140007dd0
// MS2-PIN: ?GetASCharacter@Object@AS2@GFx@Scaleform@@UEAAPEAVInteractiveObject@34@XZ 0x140007de0
// MS2-PIN: ?GetASCharacter@Object@AS2@GFx@Scaleform@@UEBAPEBVInteractiveObject@34@XZ 0x140007df0
// MS2-PIN: ?CheckAndResetCtorRef@Object@AS2@GFx@Scaleform@@UEAAXPEAVFunctionObject@234@@Z 0x140007e00
// MS2-PIN: ?GetObjectType@FunctionObject@AS2@GFx@Scaleform@@UEBA?AW4ObjectType@ObjectInterface@234@XZ 0x14000ce70
// MS2-PIN: ?IsAsFunction@FunctionObject@AS2@GFx@Scaleform@@UEBA_NXZ 0x14000ce80
// MS2-PIN: ?IsNull@CFunctionObject@AS2@GFx@Scaleform@@UEBA_NXZ 0x14000ce90
// MS2-PIN: ?IsCFunction@CFunctionObject@AS2@GFx@Scaleform@@UEBA_NXZ 0x14000cea0
// MS2-PIN: ?GetNumArgs@CFunctionObject@AS2@GFx@Scaleform@@UEBAHXZ 0x14000ceb0
// MS2-PIN: ?GetTextValue@ObjectInterface@AS2@GFx@Scaleform@@UEBAPEBDPEAVEnvironment@234@@Z 0x14000e370
// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
// MS2-PIN: ??_7VideoSound@Video@GFx@Scaleform@@6B@ 0x1431b4b80
// MS2-PIN: ??_7AvmInteractiveObjBase@GFx@Scaleform@@6B@ 0x14317bfe8
// MS2-PIN: ??_7AvmVideoCharacter@AS2@GFx@Scaleform@@6B@ 0x1431b5b40
// MS2-PIN: ??_7AvmVideoCharacter@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b5c00
// MS2-PIN: ??_7AvmVideoCharacter@AS2@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x1431b5cb0
// MS2-PIN: ??_7VideoSoundStream@Video@GFx@Scaleform@@6B@ 0x1431b4be0
