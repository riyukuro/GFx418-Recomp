// Scaleform GFx 4.1.18 video sound (FMOD back end) in the sfr_as2_01 map range: the sound objects' deleting
// destructors, the renderer taking a sound on (and starting its update thread) and the channel sync-point callback.
// Raw-layout free functions under the exe's own FUN_<va> names (these classes are RTTI-less), in the style of
// sfr_d3d9_01h / sfr_kernel_03o. Our own source, written from the exe.
// MS2-UNIT: sfr_as2_01g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142743db0-0x142744560 .text$mn

#include "../gfx/sfr_gfx_07raw.h"
#include "ms2/scaleform/include/kernel/sf_refcount.h"
#include <windows.h>
#include "fmod44464/api/inc/fmod.hpp"

void __empty_global_delete(void*, size_t);   // the sized operator delete the compiler pairs with ::new

namespace Scaleform { class Event { public: virtual ~Event(); void PulseEvent(); }; }

namespace Scaleform { namespace GFx {

extern "C" char DAT_1431bcbb0[];   // the sound objects' outermost base
extern "C" char DAT_1431bec40[];   // list node
extern "C" char DAT_1431bec50[];   // listed sound object
extern "C" char DAT_1431bec80[];
extern "C" char DAT_1431bef00[];   // buffered sound
extern "C" char DAT_1431bef38[];
extern "C" char DAT_1431bee50[];   // streamed sound
extern "C" char DAT_1431bee68[];
extern "C" char DAT_1431b80b8[];   // SoundRenderer::AuxStreamer

extern "C" void FUN_142743730(void*);       // sound dtor
extern "C" int FUN_142303a3b(void*);        // FMOD::Sound::release
void* FUN_142745630(void** set, const unsigned char* key);                  // sync-point set: the value at key
U* FUN_142743900(U* self, const U* source);                                // ArrayPOD<VideoPlayerImpl*> assign
void FUN_142742d10(U** self, void* heap, const NodeRef* node, U hash);     // array-valued set add
extern "C" void FUN_1427463e0(U*, void*, U); // ArrayData<VideoPlayerImpl*>::Reserve
void* FUN_14258a490(void* mem, void* createParams);                         // Thread::Thread(const CreateParams&)
int FUN_142747310(void* thread, void* renderer);                            // the FMOD update thread's body
void FUN_1427474d0(void* channel, void* syncinfo);                          // audio channel: sync point reached

static inline void RawRefCountCoreDtor(void* p)
{
    static_cast<RefCountImplCore*>(p)->RefCountImplCore::~RefCountImplCore();
}

static inline void RawRefCountAddRef(void* p)
{
    static_cast<RefCountImpl*>(p)->AddRef();
}

static inline void RawRefCountRelease(void* p)
{
    static_cast<RefCountImpl*>(p)->Release();
}

static inline void RawRefCountNTSRelease(void* p)
{
    static_cast<RefCountNTSImpl*>(p)->Release();
}

static inline void* RawDeleteTail(void* self, unsigned flags, UPInt size)
{
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            __empty_global_delete(self, size);
    }
    return self;
}

// Unlinks the list node at +0x10 (prev +0x18, next +0x20) from its owner's list.
static inline void RawUnlinkNode(void* self)
{
    if (char* next = RawField<char*>(self, 0x20))
    {
        RawField<char*>(RawField<char*>(self, 0x18), 0x10) = next;
        RawField<char*>(RawField<char*>(self, 0x20), 8) = RawField<char*>(self, 0x18);
        RawField<char*>(self, 0x18) = 0;
        RawField<char*>(self, 0x20) = 0;
    }
}

// FixedSizeHash<UPInt>: SDBM over the key's bytes, last to first.
static inline U RawHashWord(const unsigned char* key)
{
    U h = 5381;
    for (int i = 7; i >= 0; --i)
        h = h * 65599 + key[i];
    return h;
}

// The sound objects' outermost base (0x10 bytes).
// @0x142743db0
void* FUN_142743db0(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_1431bcbb0;
    return RawDeleteTail(self, flags, 0x10);
}

// Sound (0x40 bytes).
// @0x142743e00
void* FUN_142743e00(void* self, unsigned flags)
{
    FUN_142743730(self);
    return RawDeleteTail(self, flags, 0x40);
}

// Buffered sound (0x78 bytes): frees its sample buffer (+0x58) and its file (+0x40).
// @0x142743e60
void* FUN_142743e60(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_1431bef00;
    RawField<void*>(self, 0x10) = DAT_1431bef38;
    if (RawField<void*>(self, 0x58))
        Memory::Free(RawField<void*>(self, 0x58));
    if (RawField<void*>(self, 0x40))
        RawRefCountRelease(RawField<void*>(self, 0x40));
    FUN_142743730(self);
    return RawDeleteTail(self, flags, 0x78);
}

// Listed sound object (0x28 bytes).
// @0x142743f00
void* FUN_142743f00(void* self, unsigned flags)
{
    // vptr stores: kept although the base's overwrite them
    RawField<void* volatile>(self, 0) = DAT_1431bec50;
    RawField<void* volatile>(self, 0x10) = DAT_1431bec80;
    RawUnlinkNode(self);
    RawField<void*>(self, 0x10) = DAT_1431bec40;
    RawField<void*>(self, 0) = DAT_1431bcbb0;
    return RawDeleteTail(self, flags, 0x28);
}

// Streamed sound (0x40 bytes): releases its FMOD sound (+0x30), leaves the list and drops the renderer (+0x28).
// @0x142743fa0
void* FUN_142743fa0(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_1431bee50;
    RawField<void*>(self, 0x10) = DAT_1431bee68;
    if (RawField<void*>(self, 0x30))
        FUN_142303a3b(RawField<void*>(self, 0x30));
    RawField<void*>(self, 0x30) = 0;
    RawUnlinkNode(self);
    if (RawField<void*>(self, 0x28))
        RawRefCountNTSRelease(RawField<void*>(self, 0x28));
    RawField<void*>(self, 0x10) = DAT_1431bec40;
    RawField<void*>(self, 0) = DAT_1431b80b8;
    RawRefCountCoreDtor(self);
    return RawDeleteTail(self, flags, 0x40);
}

// Thread::CreateParams.
struct Sfr01gThreadParams
{
    int (*Func)(void*, void*);
    void*    UserHandle;
    UPInt    StackSize;
    int      Processor;
    int      InitialState;
    int      Priority;
};

// The renderer takes on a sound: under its lock (+0x80) the sound joins the list kept for its FMOD sound's key
// (+0x40 of the sound data, in the set at +0xa8); with updates on (+0xf1) and no update thread yet (+0x18) one is
// started, and turned off if it fails to. Then the update event (+0x20) is pulsed.
// MS2-FUNCTIONAL raw-offset model; the key's hash is computed in a loop here
// @0x142744070
void FUN_142744070(char* self, void* psound)
{
    if (!psound)
        return;
    char* data = RawField<char*>(psound, 0x30);
    if (!data || !RawField<U>(data, 0x40))
        return;
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0x80));
    U key = RawField<U>(data, 0x40);
    U* list = (U*)FUN_142745630(RawFieldPtr<void*>(self, 0xa8), (const unsigned char*)&key);
    if (!list)
    {
        U nkey = key;
        U empty[3] = { 0, 0, 0 };
        NodeRef ref = { &nkey, (void* const*)empty };
        const U hash = RawHashWord((const unsigned char*)&nkey);
        U* table = RawField<U*>(self, 0xa8);
        bool set = false;
        if (table)
        {
            U index = table[1] & hash;
            const U home = index;
            char* e = RawEntry(table, index, 0x30);
            if (RawField<U>(e, 0) != (U)-2 && RawField<U>(e, 8) == home)
            {
                while (RawField<U>(e, 8) != home || RawField<U>(e, 0x10) != nkey)
                {
                    index = RawField<U>(e, 0);
                    if (index == (U)-1)
                        break;
                    e = RawEntry(table, index, 0x30);
                }
                if (index != (U)-1 && (SPInt)index >= 0)
                {
                    RawField<U>(e, 0x10) = nkey;
                    FUN_142743900(RawFieldPtr<U>(e, 0x18), empty);
                    set = true;
                }
            }
        }
        if (!set)
            FUN_142742d10(RawFieldPtr<U*>(self, 0xa8), self + 0xa8, &ref, hash);
        if (empty[0])
            Memory::Free((void*)empty[0]);
        U again = RawField<U>(data, 0x40);
        list = (U*)FUN_142745630(RawFieldPtr<void*>(self, 0xa8), (const unsigned char*)&again);
    }
    const U n = list[1] + 1;
    if (n < list[1])
    {
        if (n < (list[2] >> 1))
            FUN_1427463e0(list, list, n);
    }
    else if (n > list[2])
        FUN_1427463e0(list, list, n + (n >> 2));
    list[1] = n;
    ((void**)list[0])[n - 1] = psound;
    RawRefCountAddRef(psound);
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0x80));

    if (RawField<char>(self, 0xf1) && !RawField<void*>(self, 0x18))
    {
        RawField<char>(self, 0x78) = 0;
        Sfr01gThreadParams params = { FUN_142747310, self, 0x8000, -1, 0, 1 };
        void* mem = Memory::Alloc(0x60);
        void* pthread = mem ? FUN_14258a490(mem, &params) : NULL;
        if (RawField<void*>(self, 0x18))
            RawRefCountRelease(RawField<void*>(self, 0x18));
        RawField<void*>(self, 0x18) = pthread;
        // Thread::Start(Running), Thread::SetThreadName
        typedef bool (*StartFunc)(void*, int);
        typedef void (*SetNameFunc)(void*, const char*);
        if ((*reinterpret_cast<StartFunc**>(pthread))[5](pthread, 1))
        {
            void* t = RawField<void*>(self, 0x18);
            (*reinterpret_cast<SetNameFunc**>(t))[7](t, "Scaleform FMOD Update");
        }
        else
        {
            RawField<char>(self, 0x78) = 1;
            if (RawField<void*>(self, 0x18))
                RawRefCountRelease(RawField<void*>(self, 0x18));
            RawField<void*>(self, 0x18) = 0;
            RawField<char>(self, 0xf1) = 0;
        }
    }
    reinterpret_cast<Event*>(self + 0x20)->PulseEvent();
}

// FMOD channel callback: at a sync point (type 2) of the channel's sound, a sync point the sound listens for
// (the set at +0x40 of the channel's owner) goes to the owner's audio channel (+0x38).
// MS2-FUNCTIONAL raw-offset model; the key's hash is computed in a loop here
// @0x1427443c0
int FUN_1427443c0(void* channel, int type, void* commanddata1, void* commanddata2)
{
    (void)commanddata2;
    char* owner = NULL;
    static_cast<FMOD::Channel*>(channel)->getUserData((void**)&owner);
    if (!owner || type != 2)
        return 0;
    char* data = RawField<char*>(owner, 0x30);
    if (!data || !RawField<void*>(data, 0x30))
        return 0;
    U point;
    if (RawField<FMOD::Sound*>(data, 0x30)->getSyncPoint((int)(SPInt)commanddata1, (FMOD_SYNCPOINT**)&point) != FMOD_OK)
        return 0;
    U* table = RawField<U*>(owner, 0x40);
    char* found = NULL;
    if (table)
    {
        U index = table[1] & RawHashWord((const unsigned char*)&point);
        const U home = index;
        char* e = RawEntry(table, index, 0x28);
        if (RawField<U>(e, 0) != (U)-2 && RawField<U>(e, 8) == home)
        {
            while (RawField<U>(e, 8) != home || RawField<U>(e, 0x10) != point)
            {
                index = RawField<U>(e, 0);
                if (index == (U)-1)
                    break;
                e = RawEntry(table, index, 0x28);
            }
            if (index != (U)-1 && (SPInt)index >= 0)
                found = e + 0x10;
        }
    }
    char* value = found ? found + 8 : NULL;
    if (value)
        FUN_1427474d0(RawField<void*>(owner, 0x38), value);
    return 0;
}

}} // namespace Scaleform::GFx
