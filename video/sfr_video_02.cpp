// Recovered from MapleStory2.exe KMS2_DEV x64: Scaleform GFx 4.1.18 Video glue, AS3 half.
// Source is written from the executable; leaked SDK copies are naming/layout reference only.
// MS2-UNIT: sfr_video_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14000e470-0x140016b50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/video/video_video.h"
#include "../include/video/video_as3providernetstream.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as3/as3_value.h"
#include "../include/gfx/as3/as3_vm.h"
#include "../include/gfx/as3/obj/as3_obj_events.h"
#include "../include/gfx/gfx_stream.h"
#include "../kernel/sf_exedata.h"
#include <cstring>
#include <new>

extern void FUN_14257dc30(void*);
extern void FUN_14257dcb0(void*);
extern void FUN_14257dcd0(void*);
extern void FUN_1425eec50(void*, void*, unsigned __int64);
extern const void* FUN_14261c640(const void*, int);
extern void FUN_142581700(void*);
extern void FUN_142626160(void*);
extern void FUN_14257eb30(void*);
extern void FUN_1425925f0(void*);
extern void FUN_1424d2140(void*, double*);
extern void FUN_140025750(void*, int, int);
extern void FUN_140025300(void*);
extern void FUN_140025410(void*);
extern void FUN_14296bba0();
extern void FUN_1400105b0(void*);
extern void FUN_14257db50(void*);
extern void FUN_14257db40(void*);
extern void FUN_142625ee0(const void*);
extern void FUN_142626070(void*, const void*);
extern void* DAT_1431b6060;
extern void* DAT_1431b63f8;
void FUN_140014830(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher*);

namespace Scaleform { namespace GFx { namespace Video {

// The provider back-pointer sits at +0x40 and is used while detaching a frame image.
class VideoImage : public RefCountBaseV<VideoImage, Stat_Default_Mem>
{
public:
    UByte Pad[0x40 - 0x10];
    VideoProvider* pVideoProvider;
};

}}} // namespace Scaleform::GFx::Video

// MS2-FUNCTIONAL: reproduces the base destructor followed by the conditional global-heap delete.
// @0x140013350
void* FUN_140013350(void* object, unsigned __int64 flags)
{
    FUN_14257db50(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: reproduces the base destructor followed by the conditional global-heap delete.
// @0x140014bb0
void* FUN_140014bb0(void* object, unsigned __int64 flags)
{
    FUN_14257db50(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: reproduces the base destructor followed by the conditional global-heap delete.
// @0x140015550
void* FUN_140015550(void* object, unsigned __int64 flags)
{
    FUN_14257db50(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: dispatches the recovered EventDispatcher destructor, then conditionally frees the allocation.
// @0x140015590
void* FUN_140015590(void* object, unsigned __int64 flags)
{
    FUN_140014830(static_cast<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher*>(object));
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: calls CTraits' executable destructor and frees through the global heap when requested.
// @0x140014a80
Scaleform::GFx::AS3::InstanceTraits::CTraits* FUN_140014a80(
    Scaleform::GFx::AS3::InstanceTraits::CTraits* object, unsigned flags)
{
    object->~CTraits();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: calls Class' executable destructor and frees through the global heap when requested.
// @0x140014b10
Scaleform::GFx::AS3::Class* FUN_140014b10(Scaleform::GFx::AS3::Class* object, unsigned flags)
{
    object->~Class();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: releases the weak reference counter and frees its allocation when the count reaches zero.
// @0x140013db0
void FUN_140013db0(int* refCount)
{
    if (--*refCount == 0) Scaleform::Memory::Free(refCount);
}

// MS2-FUNCTIONAL: reproduces the base destructor followed by the conditional global-heap delete.
// @0x140015c00
void* FUN_140015c00(void* object, unsigned __int64 flags)
{
    FUN_14257db50(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: clears the event-side state and optionally invokes the listener object's first callback.
// @0x140014400
void FUN_140014400(void* object, void*, char invoke)
{
    void* target = *reinterpret_cast<void**>(static_cast<char*>(object) + 0x50);
    FUN_140025300(target);
    if (invoke)
    {
        void** vtable = *reinterpret_cast<void***>(target);
        reinterpret_cast<void (*)(void*)>(vtable[4])(target);
    }
}

// MS2-FUNCTIONAL: returns the integer result of the object's count query plus one as a double.
// @0x1400146c0
void FUN_1400146c0(void* object, double* result)
{
    extern int FUN_140025360(void*);
    *result = static_cast<double>(FUN_140025360(*reinterpret_cast<void**>(static_cast<char*>(object) + 0x50)) + 1);
}

// MS2-FUNCTIONAL: updates the stored track index and releases the old AS3 value when its tag requires it.
// @0x140014730
void FUN_140014730(void* object, void*, double value)
{
    char* bytes = static_cast<char*>(object);
    *reinterpret_cast<int*>(bytes + 0x84) = static_cast<int>(value) - 1;
    unsigned tag = *reinterpret_cast<unsigned*>(bytes + 0xd8) & 0x1f;
    if (tag && (tag < 0x0c || tag > 0x0f || *reinterpret_cast<void**>(bytes + 0xe8)))
        FUN_140025410(*reinterpret_cast<void**>(bytes + 0x50));
}

// MS2-FUNCTIONAL: restores the InteractiveObject base tables, releases its provider and weak proxy, then destroys the base.
// @0x1400104d0
void FUN_1400104d0(Scaleform::GFx::InteractiveObject* object)
{
    char* bytes = reinterpret_cast<char*>(object);
    *reinterpret_cast<void***>(bytes) = Scaleform::SF_ExeData(&DAT_1431b6060);
    *reinterpret_cast<void***>(bytes + 0x18) = Scaleform::SF_ExeData(&DAT_1431b63f8);
    if (void* provider = *reinterpret_cast<void**>(bytes + 0x100))
        reinterpret_cast<void (*)(void*)>(*reinterpret_cast<void***>(provider) + 2)(provider);
    int* refs = *reinterpret_cast<int**>(bytes + 0xf8);
    if (refs && --*refs == 0) Scaleform::Memory::Free(refs);
    object->~InteractiveObject();
}

// MS2-FUNCTIONAL: scalar deleting form of the recovered VideoCharacter base destruction.
// @0x140010530
Scaleform::GFx::InteractiveObject* FUN_140010530(Scaleform::GFx::InteractiveObject* object,
                                                  unsigned __int64 flags)
{
    FUN_1400104d0(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// MS2-FUNCTIONAL: invokes the recovered CFunctionObject destructor and conditionally frees its storage.
// @0x14000ed20
Scaleform::GFx::AS2::CFunctionObject* FUN_14000ed20(
    Scaleform::GFx::AS2::CFunctionObject* object, unsigned flags)
{
    object->~CFunctionObject();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// VideoCharacter's image/update entry points are called from the AS2 provider in video_01.
// MS2-FUNCTIONAL: image release and render-tree refresh recovered with the local image layout.
// @0x140010a30
void FUN_140010a30(Scaleform::GFx::Video::VideoCharacter* pvideo)
{
    char* object = reinterpret_cast<char*>(pvideo);
    Scaleform::Ptr<Scaleform::GFx::Video::VideoImage>* image =
        reinterpret_cast<Scaleform::Ptr<Scaleform::GFx::Video::VideoImage>*>(object + 0x100);
    if (*image)
    {
        (*image)->pVideoProvider = 0;
        *image = (Scaleform::GFx::Video::VideoImage*)0;
        FUN_1400105b0(pvideo);
    }
}

// MS2-FUNCTIONAL: refreshes the provider image and render-tree state; the transform cache refresh is simplified.
// @0x140010a70
void FUN_140010a70(Scaleform::GFx::Video::VideoCharacter* pvideo)
{
    char* object = reinterpret_cast<char*>(pvideo);
    Scaleform::WeakPtr<Scaleform::GFx::Video::VideoProvider>* provider =
        reinterpret_cast<Scaleform::WeakPtr<Scaleform::GFx::Video::VideoProvider>*>(object + 0xf8);
    Scaleform::Ptr<Scaleform::GFx::Video::VideoImage>* image =
        reinterpret_cast<Scaleform::Ptr<Scaleform::GFx::Video::VideoImage>*>(object + 0x100);
    Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> strong = *provider;
    if (strong)
    {
        int width = 0, height = 0;
        Scaleform::GFx::Video::VideoImage* next = strong->GetTexture(&width, &height);
        if (next)
        {
            if (*image)
                (*image)->pVideoProvider = 0;
            *image = next;
            (*image)->pVideoProvider = strong.GetPtr();
        }
    }
    FUN_1400105b0(pvideo);
}

// MS2-FUNCTIONAL: updates the weak provider reference and detaches the old image before render refresh.
// @0x140010b80
void FUN_140010b80(Scaleform::GFx::Video::VideoCharacter* pvideo,
                   Scaleform::GFx::Video::VideoProvider* pprovider)
{
    char* object = reinterpret_cast<char*>(pvideo);
    Scaleform::WeakPtr<Scaleform::GFx::Video::VideoProvider>* provider =
        reinterpret_cast<Scaleform::WeakPtr<Scaleform::GFx::Video::VideoProvider>*>(object + 0xf8);
    Scaleform::Ptr<Scaleform::GFx::Video::VideoImage>* image =
        reinterpret_cast<Scaleform::Ptr<Scaleform::GFx::Video::VideoImage>*>(object + 0x100);
    Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> current = *provider;
    if (current.GetPtr() != pprovider)
    {
        *provider = pprovider;
        if (*image)
        {
            (*image)->pVideoProvider = 0;
            *image = (Scaleform::GFx::Video::VideoImage*)0;
            FUN_1400105b0(pvideo);
        }
    }
}

namespace Scaleform { namespace GFx { namespace Video {

}}} // namespace Scaleform::GFx::Video

namespace Scaleform { namespace GFx { namespace AS2 {

// AvmVideoCharacter::OnUnloading: detach this clip from the frame advance list.
// MS2-FUNCTIONAL: recovered behavior; standalone body is used while AvmVideoCharacter's full vtable is pending.
// @0x14000e5e0
bool AvmVideoCharacter_OnUnloading(AvmCharacter* pavm)
{
    pavm->pDispObj->RemoveFromPlayList();
    return true;
}

// The two interface adjustors are separate executable entries in this video glue range.
// @0x14000e510
void* FUN_14000e510(void* p)
{
    return p ? static_cast<void*>(static_cast<unsigned char*>(p) + 0x30) : 0;
}

// @0x14000e520
uintptr_t FUN_14000e520(uintptr_t value)
{
    return value;
}

// @0x14000e530
uintptr_t FUN_14000e530() { return 0; }

// @0x14000e540
uintptr_t FUN_14000e540() { return 0; }

// @0x14000e550
uintptr_t FUN_14000e550() { return 0; }

// @0x14000e560
uintptr_t FUN_14000e560() { return 0; }

// @0x14000e580
bool FUN_14000e580() { return false; }

// MS2-FUNCTIONAL: reproduces the two indirect interface calls and this adjustment observed at this entry.
// @0x14000e470
void FUN_14000e470(void** adjustedThis, void*, void* arg3, void* arg4)
{
    void** base = adjustedThis - 1;
    typedef void* (*GetContextFn)(void*);
    void* context = reinterpret_cast<GetContextFn>(
        *reinterpret_cast<void**>(static_cast<char*>(*base) + 0xf8))(base);
    typedef void (*DispatchFn)(void*, void*, void*, void*);
    reinterpret_cast<DispatchFn>(*reinterpret_cast<void**>(static_cast<char*>(*adjustedThis) + 0x20))(
        adjustedThis, context, arg3, arg4);
}

// @0x14000e5d0
void FUN_14000e5d0() { FUN_14296bba0(); }

// MS2-FUNCTIONAL: builds the observed default color transform and dispatches it through the object's vtable.
// @0x14000e590
void FUN_14000e590(void** object)
{
    struct DefaultTransform
    {
        UInt32 multiplier[3];
        UByte offsets[5];
    } transform = {{1, 0, 0}, {0, 0, 0xff, 0, 0}};
    typedef void (*ApplyFn)(void*, const DefaultTransform*);
    reinterpret_cast<ApplyFn>(*reinterpret_cast<void**>(static_cast<char*>(*object) + 0x40))(
        object, &transform);
}

// MS2-FUNCTIONAL: forwards the absolute-path query to the executable's AvmCharacter display object.
// @0x14000e570
const char* FUN_14000e570(AvmCharacter* pavm, String* path)
{
    return pavm->pDispObj->GetAbsolutePath(path);
}

// MS2-FUNCTIONAL: these executable entries are FID-conflict copies of the display-object forwarding wrapper.
// @0x14000e630
void FUN_14000e630(AvmCharacter* pavm, const InteractiveObject* oldCharacter)
{
    pavm->pDispObj->CopyPhysicalProperties(oldCharacter);
}

// MS2-FUNCTIONAL: executable duplicate of the physical-property forwarding entry above.
// @0x14000e640
void FUN_14000e640(AvmCharacter* pavm, const InteractiveObject* oldCharacter)
{
    pavm->pDispObj->CopyPhysicalProperties(oldCharacter);
}

// MS2-FUNCTIONAL: forwards the focus callback through the AvmCharacter interface.
// @0x14000e650
void FUN_14000e650(AvmCharacter* pavm, InteractiveObject::FocusEventType event,
                   InteractiveObject* oldOrNewFocus, unsigned controller, FocusMovedType moved)
{
    pavm->OnFocus(event, oldOrNewFocus, controller, moved);
}

// @0x14000e600
bool FUN_14000e600() { return false; }

// @0x14000e610
uintptr_t FUN_14000e610() { return 0; }

// @0x14000e620
bool FUN_14000e620() { return false; }

// The four AS2 Video-character traits live on the secondary AvmVideoCharacter base (+0x08).
// This preserves the exe's field offsets and sends all other names through the script object.
// MS2-FUNCTIONAL: standard-member ordering is approximated; Video-specific properties and fallback are recovered.
// @0x14000e8f0
bool FUN_14000e8f0(void* pvbase, Environment* penv, const ASString& name, const Value& value,
                   const PropFlags& flags)
{
    char* fields = static_cast<char*>(pvbase);
    if (!std::strcmp(name.ToCStr(), "deblocking"))
    {
        *reinterpret_cast<int*>(fields + 0x38) = static_cast<int>(value.ToNumber(penv));
        return true;
    }
    if (!std::strcmp(name.ToCStr(), "smoothing"))
    {
        *reinterpret_cast<bool*>(fields + 0x3c) = value.ToBool(penv);
        return true;
    }
    AvmCharacter* pavm = reinterpret_cast<AvmCharacter*>(fields - 8);
    Object* pvideo = pavm->GetASObject();
    return pvideo ? pvideo->SetMember(penv, name, value, flags) : false;
}

// MS2-FUNCTIONAL: width, height, deblocking and smoothing are returned directly; other names use the script object.
// @0x14000e9f0
bool FUN_14000e9f0(void* pvbase, Environment* penv, const ASString& name, Value* pvalue)
{
    char* fields = static_cast<char*>(pvbase);
    const char* key = name.ToCStr();
    if (!std::strcmp(key, "width"))
        pvalue->SetNumber(*reinterpret_cast<int*>(fields + 0x30));
    else if (!std::strcmp(key, "height"))
        pvalue->SetNumber(*reinterpret_cast<int*>(fields + 0x34));
    else if (!std::strcmp(key, "deblocking"))
        pvalue->SetNumber(*reinterpret_cast<int*>(fields + 0x38));
    else if (!std::strcmp(key, "smoothing"))
        pvalue->SetBool(*reinterpret_cast<bool*>(fields + 0x3c));
    else
    {
        AvmCharacter* pavm = reinterpret_cast<AvmCharacter*>(fields - 8);
        Object* pvideo = pavm->GetASObject();
        return pvideo ? pvideo->GetMember(penv, name, pvalue) : false;
    }
    return true;
}

// @0x14000fc90
void* FUN_14000fc90(void* dst, const void* src) { return std::memcpy(dst, src, 0x30); }

// @0x14000fcb0
void* FUN_14000fcb0(void* dst, const void* src) { return std::memcpy(dst, src, 0x30); }

// @0x14000fcd0
void* FUN_14000fcd0(void* dst, const void* src) { return std::memcpy(dst, src, 0x40); }

// @0x14000fcf0
void* FUN_14000fcf0(void* dst, const void* src) { return std::memcpy(dst, src, 0x40); }

// The Render state data follows the state refcount and storage pointer in both states.
// MS2-FUNCTIONAL: stack copy elided; copies the same 0x30-byte state payload.
// @0x14000ff10
bool FUN_14000ff10(const void* node, void* out)
{
    const void* state = FUN_14261c640(node, 5);
    if (!state)
        return false;
    const char* data = *reinterpret_cast<const char* const*>(static_cast<const char*>(state) + 8);
    std::memcpy(out, data + 0x10, 0x30);
    return true;
}

// MS2-FUNCTIONAL: stack copy elided; copies the same 0x40-byte state payload.
// @0x14000ff70
bool FUN_14000ff70(const void* node, void* out)
{
    const void* state = FUN_14261c640(node, 6);
    if (!state)
        return false;
    const char* data = *reinterpret_cast<const char* const*>(static_cast<const char*>(state) + 8);
    std::memcpy(out, data + 0x10, 0x40);
    return true;
}

// @0x140010eb0
void* FUN_140010eb0(void* dst, const void* src) { return std::memcpy(dst, src, 0x30); }

// Append one retained 16-byte item (four-byte tag plus refcounted payload).
// MS2-FUNCTIONAL: uses the executable's Array reserve helper; element copy/refcount behavior recovered.
// @0x1400110c0
void FUN_1400110c0(unsigned __int64* array, const UInt32* item)
{
    FUN_1425eec50(array, array, array[1] + 1);
    UInt32* dst = reinterpret_cast<UInt32*>(array[0] - 0x10 + array[1] * 0x10);
    *dst = *item;
    void* payload = *reinterpret_cast<void* const*>(item + 2);
    if (payload)
        FUN_14257dc30(payload);
    *reinterpret_cast<void**>(dst + 2) = payload;
}

// @0x140011240
void FUN_140011240(unsigned __int64* array, const UInt32* item)
{
    FUN_1425eec50(array, array, array[1] + 1);
    UInt32* dst = reinterpret_cast<UInt32*>(array[0] - 0x10 + array[1] * 0x10);
    *dst = *item;
    void* payload = *reinterpret_cast<void* const*>(item + 2);
    if (payload)
        FUN_14257dc30(payload);
    *reinterpret_cast<void**>(dst + 2) = payload;
}

// Four-byte transform data is appended as four byte elements by the exe.
// MS2-FUNCTIONAL: same four-byte append sequence; Array growth policy is handled by the executable reserve helper.
// @0x140011120
void FUN_140011120(void** parray, UInt32 value)
{
    const UByte* bytes = reinterpret_cast<const UByte*>(&value);
    for (unsigned i = 0; i != 4; ++i)
    {
        unsigned __int64* array = reinterpret_cast<unsigned __int64*>(parray);
        FUN_1425eec50(array, array, array[1] + 1);
        reinterpret_cast<UByte*>(array[0] - 1 + array[1])[0] = bytes[i];
        ++array[1];
    }
}

// MS2-FUNCTIONAL: appends one byte with the executable's growth thresholds and reserve call.
// @0x140010f60
void FUN_140010f60(unsigned __int64* array, const UByte* value)
{
    unsigned __int64 nextSize = array[1] + 1;
    if (nextSize < array[1])
    {
        if ((array[2] >> 1) <= nextSize)
            FUN_1425eec50(array, array, nextSize);
    }
    else if (nextSize >= array[2])
        FUN_1425eec50(array, array, nextSize + (nextSize >> 2));
    array[1] = nextSize;
    UByte* data = reinterpret_cast<UByte*>(array[0]);
    if (data) data[nextSize - 1] = *value;
}

// MS2-FUNCTIONAL: resizes the executable's byte array and preserves its observed quarter-growth policy.
// @0x140010390
void FUN_140010390(unsigned __int64* array, void* reserveSource, unsigned __int64 newSize)
{
    if (newSize < array[1])
    {
        if (newSize < (array[2] >> 1))
        {
            FUN_1425eec50(array, reserveSource, newSize);
            array[1] = newSize;
            return;
        }
    }
    else if (array[2] <= newSize)
    {
        FUN_1425eec50(array, reserveSource, newSize + (newSize >> 2));
        array[1] = newSize;
        return;
    }
    array[1] = newSize;
}

// MS2-FUNCTIONAL: creates an AS string from the encoded string payload and retains the new node.
// @0x1400128e0
void** FUN_1400128e0(ASStringManager* manager, void** result, const unsigned __int64* encoded)
{
    unsigned __int64 stringData = *encoded & ~static_cast<unsigned __int64>(3);
    const char* chars = reinterpret_cast<const char*>(stringData + 0xc);
    unsigned __int64 length = *reinterpret_cast<const unsigned __int64*>(stringData) & 0x7fffffffffffffffULL;
    ASStringNode* node = manager->CreateStringNode(chars, static_cast<UPInt>(length));
    *result = node;
    ++*reinterpret_cast<int*>(reinterpret_cast<char*>(node) + 0x18);
    return result;
}

// @0x140012940
void FUN_140012940(ASString* string) { string->SetNull(); }

// MS2-FUNCTIONAL: creates a const node through the owning context's manager and retains it for the destination.
// @0x140012f60
void** FUN_140012f60(void* context, void** result, const char* text)
{
    ASStringManager* manager = *reinterpret_cast<ASStringManager**>(static_cast<char*>(context) + 0x1e8);
    ASStringNode* node = manager->CreateConstStringNode(text, std::strlen(text), 0);
    *result = node;
    ++*reinterpret_cast<unsigned*>(reinterpret_cast<char*>(node) + 0x18);
    return result;
}

// MS2-FUNCTIONAL: creates a string node through the context manager and retains it for the destination.
// @0x140012fb0
void** FUN_140012fb0(void* context, void** result, const char* text)
{
    ASStringManager* manager = *reinterpret_cast<ASStringManager**>(static_cast<char*>(context) + 0x1e8);
    ASStringNode* node = manager->CreateStringNode(text);
    *result = node;
    ++*reinterpret_cast<unsigned*>(reinterpret_cast<char*>(node) + 0x18);
    return result;
}

// MS2-FUNCTIONAL: decodes the executable's tagged string payload through the context manager.
// @0x140012fe0
void** FUN_140012fe0(void* context, void** result, const unsigned __int64* encoded)
{
    ASStringManager* manager = *reinterpret_cast<ASStringManager**>(static_cast<char*>(context) + 0x1e8);
    return FUN_1400128e0(manager, result, encoded);
}

// @0x1400134c0
void FUN_1400134c0(ASStringNode** node) { (*node)->Release(); }

// @0x1400134e0
void FUN_1400134e0(void* object)
{
    reinterpret_cast<ASStringNode**>(static_cast<char*>(object) + 0x10)[0]->Release();
}

// @0x140013100
void FUN_140013100(void** ref) { if (*ref) FUN_14257dcd0(*ref); }

// @0x140013120
void** FUN_140013120(void** ref, void* value)
{
    if (*ref) FUN_14257dcd0(*ref);
    *ref = value;
    return ref;
}

// @0x140013180
void FUN_140013180(void** ref) { if (*ref) FUN_14257dcd0(*ref); }

// @0x1400131a0
void** FUN_1400131a0(void** ref, void* value)
{
    if (*ref) FUN_14257dcd0(*ref);
    *ref = value;
    return ref;
}

// @0x1400132d0
void FUN_1400132d0(void** ref) { if (*ref) FUN_14257dcb0(*ref); }

// @0x1400159f0
void** FUN_1400159f0(void** result, void* context)
{
    ASStringManager* manager = *reinterpret_cast<ASStringManager**>(static_cast<char*>(context) + 0x1e8);
    ASStringNode* first = manager->CreateConstStringNode("null", 4, 0);
    first->AddRef();
    ASStringNode* second = manager->CreateConstStringNode("null", 4, 0);
    second->AddRef();
    result[0] = second;
    result[1] = first;
    return result;
}

// @0x1400151a0
long long* FUN_1400151a0(long long* dst, const long long* src)
{
    typedef void (*RefFn)(void*);
    if (*src)
        reinterpret_cast<RefFn>(*reinterpret_cast<void**>(*reinterpret_cast<void***>(*src) + 1))(
            reinterpret_cast<void*>(*src));
    if (*dst)
        reinterpret_cast<RefFn>(*reinterpret_cast<void**>(*reinterpret_cast<void***>(*dst) + 2))(
            reinterpret_cast<void*>(*dst));
    *dst = *src;
    return dst;
}

// @0x140013800
long long* FUN_140013800(long long* dst, long long value)
{
    if (value) FUN_14257dc30(reinterpret_cast<void*>(value));
    if (*dst) FUN_14257dcb0(reinterpret_cast<void*>(*dst));
    *dst = value;
    return dst;
}

// @0x1400138d0
long long* FUN_1400138d0(long long* dst, const long long* src)
{
    if (*src) FUN_14257dc30(reinterpret_cast<void*>(*src));
    *dst = *src;
    return dst;
}

static void SetScalarValue(UInt32* value, UInt32 kind, const void* payload, size_t payloadSize)
{
    *value = (*value & ~0x1fu) | kind;
    std::memset(reinterpret_cast<char*>(value) + 0x10, 0, 0x10);
    std::memcpy(reinterpret_cast<char*>(value) + 0x10, payload, payloadSize);
}

// MS2-FUNCTIONAL: initializes the scalar kind and payload at the offsets used by the executable's AS3 Value.
// @0x140013cc0
void FUN_140013cc0(UInt32* value, UByte input) { SetScalarValue(value, 1, &input, sizeof(input)); }

// MS2-FUNCTIONAL: initializes the integer kind and payload at the executable's AS3 Value offsets.
// @0x140013cf0
void FUN_140013cf0(UInt32* value, UInt32 input) { SetScalarValue(value, 3, &input, sizeof(input)); }

// MS2-FUNCTIONAL: initializes the number kind and payload at the executable's AS3 Value offsets.
// @0x140013d20
void FUN_140013d20(UInt32* value, double input) { SetScalarValue(value, 4, &input, sizeof(input)); }

// MS2-FUNCTIONAL: scalar boolean setter with the same tag and payload layout.
// @0x140015110
void FUN_140015110(UInt32* value, const UByte* input) { SetScalarValue(value, 1, input, sizeof(*input)); }

// MS2-FUNCTIONAL: scalar integer setter with the same tag and payload layout.
// @0x1400150e0
void FUN_1400150e0(UInt32* value, const UInt32* input) { SetScalarValue(value, 3, input, sizeof(*input)); }

// MS2-FUNCTIONAL: scalar number setter with the same tag and payload layout.
// @0x140015080
void FUN_140015080(UInt32* value, const double* input) { SetScalarValue(value, 4, input, sizeof(*input)); }

// MS2-FUNCTIONAL: returning wrapper around the scalar boolean setter.
// @0x140013fb0
uintptr_t FUN_140013fb0(uintptr_t self, UInt32* value, const UByte* input)
{
    SetScalarValue(value, 1, input, sizeof(*input));
    return self;
}

// MS2-FUNCTIONAL: returning wrapper around the scalar integer setter.
// @0x140013ff0
uintptr_t FUN_140013ff0(uintptr_t self, UInt32* value, const UInt32* input)
{
    SetScalarValue(value, 3, input, sizeof(*input));
    return self;
}

// MS2-FUNCTIONAL: returning wrapper around the scalar number setter.
// @0x140014020
uintptr_t FUN_140014020(uintptr_t self, UInt32* value, const double* input)
{
    SetScalarValue(value, 4, input, sizeof(*input));
    return self;
}

// MS2-FUNCTIONAL: performs the inline numeric conversion on the executable's AS3 Value input.
// @0x140012d30
uintptr_t FUN_140012d30(uintptr_t self, uintptr_t, Scaleform::GFx::AS3::Value* input)
{
    double number;
    input->Convert2NumberInline(number);
    return self;
}

// MS2-FUNCTIONAL: performs the inline numeric conversion into the executable's temporary result.
// @0x140013a00
void FUN_140013a00(void*, Scaleform::GFx::AS3::Value* input)
{
    double number;
    input->Convert2NumberInline(number);
}

// MS2-FUNCTIONAL: converts the AS3 Value to a signed 32-bit result through the recovered executable method.
// @0x140012d00
uintptr_t FUN_140012d00(uintptr_t self, SInt32* result, const Scaleform::GFx::AS3::Value* input)
{
    input->Convert2Int32(*result);
    return self;
}

// MS2-FUNCTIONAL: converts the AS3 Value to a signed 32-bit result through the recovered executable method.
// @0x140013a40
void FUN_140013a40(SInt32* result, const Scaleform::GFx::AS3::Value* input)
{
    input->Convert2Int32(*result);
}

// MS2-FUNCTIONAL: converts the indexed AS3 Value to a signed 32-bit result when the index is in range.
// @0x140015170
void FUN_140015170(UInt32 index, SInt32* result, UInt32 length, const void* values)
{
    if (index < length)
    {
        const Scaleform::GFx::AS3::Value* input = reinterpret_cast<const Scaleform::GFx::AS3::Value*>(
            static_cast<const char*>(values) + static_cast<size_t>(index) * 0x20);
        input->Convert2Int32(*result);
    }
}

// MS2-FUNCTIONAL: performs the executable's inline numeric conversion on the indexed Value when present.
// @0x1400150b0
void FUN_1400150b0(UInt32 index, void*, UInt32 length, const void* values)
{
    if (index < length)
    {
        const Scaleform::GFx::AS3::Value* input = reinterpret_cast<const Scaleform::GFx::AS3::Value*>(
            static_cast<const char*>(values) + static_cast<size_t>(index) * 0x20);
        double number;
        input->Convert2NumberInline(number);
    }
}

// MS2-FUNCTIONAL: converts the input Value into the supplied ASString through the recovered conversion method.
// @0x140013f20
uintptr_t FUN_140013f20(uintptr_t self, Scaleform::GFx::ASString* result,
                        const Scaleform::GFx::AS3::Value* input)
{
    input->Convert2String(*result);
    return self;
}

// MS2-FUNCTIONAL: converts the input Value into the supplied ASString through the recovered conversion method.
// @0x140015420
void FUN_140015420(Scaleform::GFx::ASString* result, const Scaleform::GFx::AS3::Value* input)
{
    input->Convert2String(*result);
}

// MS2-FUNCTIONAL: drops a retained AS3 object value using its executable release path.
// @0x140014c50
void FUN_140014c50(Scaleform::GFx::AS3::Value* value)
{
    if (value->GetKind() > Scaleform::GFx::AS3::Value::kNumber)
    {
        Scaleform::GFx::AS3::Value released(*value, Scaleform::GFx::AS3::Value::NotRefCounted);
    }
}

// MS2-FUNCTIONAL: assigns a Pickable object into the AS3 Value through the recovered Pick operation.
// @0x140014c30
Scaleform::GFx::AS3::Value* FUN_140014c30(Scaleform::GFx::AS3::Value* value,
                                          Scaleform::GFx::AS3::Object* object)
{
    value->Pick(object);
    return value;
}

// MS2-FUNCTIONAL: releases the two string nodes through the recovered ASStringNode ownership method.
// @0x140014c90
void FUN_140014c90(ASStringNode** strings)
{
    strings[1]->Release();
    strings[0]->Release();
}

// MS2-FUNCTIONAL: releases the two string nodes at the executable's object offsets.
// @0x140014cc0
void FUN_140014cc0(void* object)
{
    char* bytes = static_cast<char*>(object);
    reinterpret_cast<ASStringNode**>(bytes + 0x18)[0]->Release();
    reinterpret_cast<ASStringNode**>(bytes + 0x10)[0]->Release();
}

// MS2-FUNCTIONAL: releases the three string nodes through the recovered ownership method.
// @0x140014cf0
void FUN_140014cf0(ASStringNode** strings)
{
    strings[2]->Release();
    strings[1]->Release();
    strings[0]->Release();
}

// MS2-FUNCTIONAL: releases the three string nodes at the executable's object offsets.
// @0x140014d30
void FUN_140014d30(void* object)
{
    char* bytes = static_cast<char*>(object);
    reinterpret_cast<ASStringNode**>(bytes + 0x20)[0]->Release();
    reinterpret_cast<ASStringNode**>(bytes + 0x18)[0]->Release();
    reinterpret_cast<ASStringNode**>(bytes + 0x10)[0]->Release();
}

static void* NumberNaNBits();

// MS2-FUNCTIONAL: stores the executable's NaN payload in the third numeric field.
// @0x140014e10
void** FUN_140014e10(void** values, void* first, void* second)
{
    values[0] = first;
    values[1] = second;
    values[2] = NumberNaNBits();
    return values;
}

static void ReleaseAS3ValueAt(void* address)
{
    Scaleform::GFx::AS3::Value* value = static_cast<Scaleform::GFx::AS3::Value*>(address);
    if (value->GetKind() > Scaleform::GFx::AS3::Value::kNumber)
    {
        Scaleform::GFx::AS3::Value released(*value, Scaleform::GFx::AS3::Value::NotRefCounted);
    }
}

// MS2-FUNCTIONAL: releases the VideoPlayer references and AS3 fields before delegating to the recovered base dtor.
// @0x140014830
void FUN_140014830(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher* dispatcher)
{
    char* fields = reinterpret_cast<char*>(dispatcher);
    void* player = *reinterpret_cast<void**>(fields + 0x50);
    if (player)
    {
        *reinterpret_cast<void**>(static_cast<char*>(player) + 0x18) = 0;
        FUN_140025300(player);
    }
    ReleaseAS3ValueAt(fields + 0x98);
    ReleaseAS3ValueAt(fields + 0xb8);
    ReleaseAS3ValueAt(fields + 0xd8);
    void* weakRefs[2] = {*reinterpret_cast<void**>(fields + 0x58), player};
    for (void* ref : weakRefs)
        if (ref) FUN_14257dcd0(ref);
    dispatcher->~EventDispatcher();
}

// MS2-FUNCTIONAL: reads the supplied sound-transform value and refreshes the stored player coordinates.
// @0x1400142e0
void FUN_1400142e0(void* object, void*, void* soundTransform)
{
    if (!soundTransform) return;
    char* fields = static_cast<char*>(object);
    double* x = reinterpret_cast<double*>(fields + 0x88);
    FUN_1424d2140(soundTransform, x);
    FUN_140025750(*reinterpret_cast<void**>(fields + 0x50),
                  static_cast<int>(x[0] * 20.0),
                  static_cast<int>(*reinterpret_cast<double*>(fields + 0x90) * 20.0));
}

// MS2-FUNCTIONAL: reads the second supplied sound-transform value and refreshes the stored player coordinates.
// @0x140014770
void FUN_140014770(void* object, void*, void* soundTransform)
{
    if (!soundTransform) return;
    char* fields = static_cast<char*>(object);
    double* y = reinterpret_cast<double*>(fields + 0x90);
    FUN_1424d2140(soundTransform, y);
    FUN_140025750(*reinterpret_cast<void**>(fields + 0x50),
                  static_cast<int>(*reinterpret_cast<double*>(fields + 0x88) * 20.0),
                  static_cast<int>(y[0] * 20.0));
}

static void* NumberNaNBits()
{
    union { double number; void* pointer; } value;
    value.number = NumberUtil::NaN();
    return value.pointer;
}

// MS2-FUNCTIONAL: initializes the numeric payload to the executable's NaN value.
// @0x140014e80
void** FUN_140014e80(void** value) { *value = NumberNaNBits(); return value; }
// MS2-FUNCTIONAL: initializes the numeric payload to the executable's NaN value.
// @0x140014ee0
void** FUN_140014ee0(void** value) { *value = NumberNaNBits(); return value; }
// MS2-FUNCTIONAL: initializes the numeric payload to the executable's NaN value.
// @0x140014f00
void** FUN_140014f00(void** value) { *value = NumberNaNBits(); return value; }
// MS2-FUNCTIONAL: initializes the numeric payload to the executable's NaN value.
// @0x140014f90
void** FUN_140014f90(void** value) { *value = NumberNaNBits(); return value; }
// MS2-FUNCTIONAL: initializes the numeric payload to the executable's NaN value.
// @0x140014fb0
void** FUN_140014fb0(void** value) { *value = NumberNaNBits(); return value; }
// MS2-FUNCTIONAL: initializes the numeric payload to the executable's NaN value.
// @0x140014fd0
void** FUN_140014fd0(void** value) { *value = NumberNaNBits(); return value; }
// MS2-FUNCTIONAL: initializes the numeric payload to the executable's NaN value.
// @0x140014ff0
void** FUN_140014ff0(void** value) { *value = NumberNaNBits(); return value; }
// MS2-FUNCTIONAL: initializes the numeric payload to the executable's NaN value.
// @0x140015010
void** FUN_140015010(void** value) { *value = NumberNaNBits(); return value; }
// MS2-FUNCTIONAL: initializes the numeric payload to the executable's NaN value.
// @0x140015030
void** FUN_140015030(void** value) { *value = NumberNaNBits(); return value; }
// MS2-FUNCTIONAL: initializes the numeric payload to the executable's NaN value.
// @0x140015050
void** FUN_140015050(void** value) { *value = NumberNaNBits(); return value; }

// MS2-FUNCTIONAL: uses the recovered AS3 Value assignment implementation for the executable's copy entry.
// @0x1400129d0
Scaleform::GFx::AS3::Value* FUN_1400129d0(Scaleform::GFx::AS3::Value* dst,
                                          const Scaleform::GFx::AS3::Value* src)
{
    *dst = *src;
    return dst;
}

// MS2-FUNCTIONAL: initializes the destination with the executable's AS3 Value copy semantics.
// @0x140013be0
Scaleform::GFx::AS3::Value* FUN_140013be0(Scaleform::GFx::AS3::Value* dst,
                                          const Scaleform::GFx::AS3::Value* src)
{
    return new (dst) Scaleform::GFx::AS3::Value(*src);
}

// MS2-FUNCTIONAL: duplicate AS3 Value copy constructor recovered through the local type.
// @0x1400151e0
Scaleform::GFx::AS3::Value* FUN_1400151e0(Scaleform::GFx::AS3::Value* dst,
                                          const Scaleform::GFx::AS3::Value* src)
{
    return new (dst) Scaleform::GFx::AS3::Value(*src);
}

// MS2-FUNCTIONAL: initializes from the AS3 Value undefined singleton used by the executable.
// @0x140013ec0
Scaleform::GFx::AS3::Value* FUN_140013ec0(Scaleform::GFx::AS3::Value* dst)
{
    return new (dst) Scaleform::GFx::AS3::Value(Scaleform::GFx::AS3::Value::GetUndefined());
}

// MS2-FUNCTIONAL: initializes the same undefined Value payload as the executable default helper.
// @0x140015340
UInt32* FUN_140015340(UInt32* dst)
{
    Scaleform::GFx::AS3::Value* value = reinterpret_cast<Scaleform::GFx::AS3::Value*>(dst);
    new (value) Scaleform::GFx::AS3::Value(Scaleform::GFx::AS3::Value::GetUndefined());
    return dst;
}

// MS2-FUNCTIONAL: returns the manager's retained built-in null string node.
// @0x140014060
void** FUN_140014060(void** result, void* context)
{
    ASStringManager* manager = *reinterpret_cast<ASStringManager**>(static_cast<char*>(context) + 0x1e8);
    ASStringNode* node = manager->CreateConstStringNode("null", 4, 0);
    node->AddRef();
    *result = node;
    return result;
}

// MS2-FUNCTIONAL: duplicate entry for the manager's retained built-in null string node.
// @0x1400140a0
void** FUN_1400140a0(void** result, void* context)
{
    ASStringManager* manager = *reinterpret_cast<ASStringManager**>(static_cast<char*>(context) + 0x1e8);
    ASStringNode* node = manager->CreateConstStringNode("null", 4, 0);
    node->AddRef();
    *result = node;
    return result;
}

// MS2-FUNCTIONAL: computes the truth value from the executable's AS3 Value argument.
// @0x140012cd0
uintptr_t FUN_140012cd0(uintptr_t self, UByte* result, Scaleform::GFx::AS3::Value* input)
{
    *result = input->Convert2Boolean();
    return self;
}

// MS2-FUNCTIONAL: forwards the executable's argument frame to the recovered VM internal invocation method.
// @0x140012c30
void FUN_140012c30(Scaleform::GFx::AS3::VM* vm, const Scaleform::GFx::AS3::Value& function,
                   const Scaleform::GFx::AS3::Value& thisValue, Scaleform::GFx::AS3::Value& result,
                   unsigned argc, const Scaleform::GFx::AS3::Value* argv, bool discardResult)
{
    vm->ExecuteInternalUnsafe(function, thisValue, result, argc, argv, discardResult);
}

// MS2-FUNCTIONAL: computes the truth value from the executable's AS3 Value argument.
// @0x140013a20
void FUN_140013a20(UByte* result, Scaleform::GFx::AS3::Value* input)
{
    *result = input->Convert2Boolean();
}

// MS2-FUNCTIONAL: transfers the object reference into the AS3 Value using the recovered Pick operation.
// @0x140013790
void FUN_140013790(Scaleform::GFx::AS3::Value* value, Scaleform::GFx::AS3::Object* object)
{
    value->Pick(object);
}

// MS2-FUNCTIONAL: computes the truth value from the executable's AS3 Value argument.
// @0x140015140
void FUN_140015140(UInt32 index, UByte* result, UInt32 length, Scaleform::GFx::AS3::Value* values)
{
    if (index < length)
        *result = (reinterpret_cast<Scaleform::GFx::AS3::Value*>(
                       reinterpret_cast<char*>(values) + static_cast<size_t>(index) * 0x20))->Convert2Boolean();
}

// MS2-FUNCTIONAL: copies the Value to execute its recovered strong AddRef path without changing the source fields.
// @0x140012a90
void FUN_140012a90(Scaleform::GFx::AS3::Value* value)
{
    if (value->GetKind() > Scaleform::GFx::AS3::Value::kNumber)
    {
        alignas(Scaleform::GFx::AS3::Value) unsigned char storage[sizeof(Scaleform::GFx::AS3::Value)];
        new (storage) Scaleform::GFx::AS3::Value(*value);
    }
}

// MS2-FUNCTIONAL: drops one weak or strong reference through Value's recovered release path.
// @0x140012ac0
void FUN_140012ac0(Scaleform::GFx::AS3::Value* value)
{
    if (value->GetKind() > Scaleform::GFx::AS3::Value::kNumber)
    {
        Scaleform::GFx::AS3::Value released(*value, Scaleform::GFx::AS3::Value::NotRefCounted);
    }
}

// MS2-FUNCTIONAL: drops one strong object reference from a Value when its tag is collectable and not weak.
// @0x140012b80
void FUN_140012b80(void*, const UInt32* flags)
{
    if ((*flags & 0x1f) > 10 && (*flags & 0x200) == 0)
    {
        const Scaleform::GFx::AS3::Value* value = reinterpret_cast<const Scaleform::GFx::AS3::Value*>(flags);
        Scaleform::GFx::AS3::Value released(*value, Scaleform::GFx::AS3::Value::NotRefCounted);
    }
}

// @0x14000f830
long long* FUN_14000f830(long long* dst, const long long* src)
{
    if (*src)
        FUN_14257dc30(reinterpret_cast<void*>(*src));
    *dst = *src;
    return dst;
}

// @0x14000f990
long long* FUN_14000f990(long long* dst, const long long* src)
{
    typedef void (*RefFn)(void*);
    if (*src)
        reinterpret_cast<RefFn>(*reinterpret_cast<void**>(*reinterpret_cast<void***>(*src) + 1))(
            reinterpret_cast<void*>(*src));
    if (*dst)
        reinterpret_cast<RefFn>(*reinterpret_cast<void**>(*reinterpret_cast<void***>(*dst) + 2))(
            reinterpret_cast<void*>(*dst));
    *dst = *src;
    return dst;
}

// @0x14000fbc0
void FUN_14000fbc0(void* object)
{
    void* ref = *reinterpret_cast<void**>(static_cast<char*>(object) + 8);
    if (ref)
        FUN_14257dcb0(ref);
}

// @0x14000f4b0
void FUN_14000f4b0(void** object) { if (*object) FUN_14257dcb0(*object); }

// @0x14000f4e0
void FUN_14000f4e0(void** object) { if (*object) FUN_14257dcb0(*object); }

// @0x14000f500
void** FUN_14000f500(void** dst, void* value)
{
    if (*dst) FUN_14257dcb0(*dst);
    *dst = value;
    return dst;
}

// @0x14000f550
void** FUN_14000f550(void** dst, void* value)
{
    if (value)
    {
        void* base = static_cast<char*>(value) + 0x10;
        typedef void (*RefFn)(void*);
        reinterpret_cast<RefFn>(*reinterpret_cast<void**>(*reinterpret_cast<void***>(base) + 1))(base);
    }
    *dst = value;
    return dst;
}

// @0x14000f5a0
void FUN_14000f5a0(void** object)
{
    if (*object)
    {
        void* base = static_cast<char*>(*object) + 0x10;
        typedef void (*RefFn)(void*);
        reinterpret_cast<RefFn>(*reinterpret_cast<void**>(*reinterpret_cast<void***>(base) + 2))(base);
    }
}

static void ReleaseRenderEntry(void* entry)
{
    if (!entry) return;
    long long* count = reinterpret_cast<long long*>(static_cast<char*>(entry) + 0x40);
    if (--*count == 0) FUN_142581700(entry);
}

// @0x14000f5c0
void FUN_14000f5c0(void** object) { ReleaseRenderEntry(*object); }

// @0x14000f5e0
void** FUN_14000f5e0(void** dst, void* value)
{
    if (value) ++*reinterpret_cast<long long*>(static_cast<char*>(value) + 0x40);
    ReleaseRenderEntry(*dst);
    *dst = value;
    return dst;
}

// @0x14000f660
void FUN_14000f660(void** object) { ReleaseRenderEntry(*object); }

// @0x14000f680
void** FUN_14000f680(void** dst, void* value)
{
    ReleaseRenderEntry(*dst);
    *dst = value;
    return dst;
}

// @0x14000f6f0
void FUN_14000f6f0(void** object)
{
    if (*object)
    {
        void* base = static_cast<char*>(*object) + 0x10;
        typedef void (*RefFn)(void*);
        reinterpret_cast<RefFn>(*reinterpret_cast<void**>(*reinterpret_cast<void***>(base) + 2))(base);
    }
}

// @0x14000f740
void FUN_14000f740(void** object) { if (*object) FUN_14257dcd0(*object); }

// @0x14000fd10
void** FUN_14000fd10(void** dst, void** src)
{
    if (*src) ++*reinterpret_cast<long long*>(static_cast<char*>(*src) + 8);
    ReleaseRenderEntry(*dst);
    *dst = *src;
    return dst;
}

// @0x14000fd70
long long* FUN_14000fd70(long long* dst, const long long* src)
{
    typedef void (*RefFn)(void*);
    if (*src)
        reinterpret_cast<RefFn>(*reinterpret_cast<void**>(*reinterpret_cast<void***>(*src) + 1))(
            reinterpret_cast<void*>(*src));
    if (*dst)
        reinterpret_cast<RefFn>(*reinterpret_cast<void**>(*reinterpret_cast<void***>(*dst) + 2))(
            reinterpret_cast<void*>(*dst));
    *dst = *src;
    return dst;
}

// @0x14000fe90
UInt32* FUN_14000fe90(UInt32* dst, const UInt32* src)
{
    *dst = *src;
    void* payload = *reinterpret_cast<void* const*>(src + 2);
    if (payload)
        FUN_14257dc30(payload);
    *reinterpret_cast<void**>(dst + 2) = payload;
    return dst;
}

// @0x14000fed0
void FUN_14000fed0(void* object)
{
    void* ref = *reinterpret_cast<void**>(static_cast<char*>(object) + 8);
    if (ref)
        FUN_14257dcb0(ref);
}

// @0x14000f060
void FUN_14000f060(void** object)
{
    if (*object)
        FUN_142626160(*object);
}

// @0x14000ef80
UByte FUN_14000ef80(Stream* stream) { return stream->ReadU8(); }

// @0x14000efc0
UInt16 FUN_14000efc0(Stream* stream) { return stream->ReadU16(); }

// MS2-FUNCTIONAL: reads the tag fields at the executable offsets; the tag's public type is not yet recovered.
// @0x14000f2d0
void FUN_14000f2d0(void* tag, void* movieData)
{
    char* movie = static_cast<char*>(movieData);
    Stream* stream = *reinterpret_cast<Stream**>(movie + 0x418);
    if (!stream) stream = reinterpret_cast<Stream*>(movie + 0x50);
    char* fields = static_cast<char*>(tag);
    *reinterpret_cast<UInt16*>(fields + 0x20) = stream->ReadU16();
    *reinterpret_cast<UInt16*>(fields + 0x24) = stream->ReadU16();
    *reinterpret_cast<UInt16*>(fields + 0x28) = stream->ReadU16();
    stream->ReadUInt(5);
    fields[0x2c] = static_cast<char>(stream->ReadUInt(2));
    fields[0x2d] = stream->ReadUInt(1) != 0;
    fields[0x2e] = static_cast<char>(stream->ReadU8());
}

// @0x14000f0e0
void FUN_14000f0e0(void* entry)
{
    long long* ref = reinterpret_cast<long long*>(static_cast<char*>(entry) + 8);
    if (--*ref == 0)
        FUN_142581700(entry);
}

// @0x14000f1a0
void FUN_14000f1a0(void* node)
{
    if (*reinterpret_cast<void**>(static_cast<char*>(node) + 0x40))
        FUN_142626160(static_cast<char*>(node) + 0x40);
    FUN_14257eb30(node);
}

// @0x14000f270
void FUN_14000f270(void* node)
{
    if (*reinterpret_cast<void**>(static_cast<char*>(node) + 0x40))
        FUN_142626160(static_cast<char*>(node) + 0x40);
    FUN_14257eb30(node);
}

// @0x14000fdb0
void** FUN_14000fdb0(void** dst, void* next)
{
    if (*dst)
        FUN_14257dcb0(*dst);
    *dst = next;
    return dst;
}

// MS2-FUNCTIONAL: raw weak-proxy lock follows the exe's proxy/object offsets and returns a live target.
// @0x14000fe00
void* FUN_14000fe00(void** weakProxy)
{
    void* proxy = *weakProxy;
    if (!proxy)
        return 0;
    void* object = *reinterpret_cast<void**>(static_cast<char*>(proxy) + 8);
    if (!object)
    {
        FUN_14257dcb0(proxy);
        *weakProxy = 0;
        return 0;
    }
    return *reinterpret_cast<int*>(static_cast<char*>(object) + 8) ? object : 0;
}

// MS2-FUNCTIONAL: locks a weak proxy using the executable's proxy and target refcount fields.
// @0x1400102c0
void** FUN_1400102c0(void** weakProxy, void** strongTarget)
{
    void* proxy = *weakProxy;
    if (proxy)
    {
        void* target = *reinterpret_cast<void**>(static_cast<char*>(proxy) + 8);
        if (!target)
        {
            int* refs = static_cast<int*>(proxy);
            if (--*refs == 0) FUN_142626160(proxy);
            *weakProxy = 0;
        }
        else
        {
            int* refs = reinterpret_cast<int*>(static_cast<char*>(target) + 8);
            if (*refs)
            {
                ++*refs;
                *strongTarget = target;
                return strongTarget;
            }
        }
    }
    *strongTarget = 0;
    return strongTarget;
}

// @0x140010340
void FUN_140010340(void* begin, size_t count)
{
    char* cursor = static_cast<char*>(begin) - 8 + count * 16;
    while (count--)
    {
        void* weakProxy = *reinterpret_cast<void**>(cursor);
        if (weakProxy) FUN_14257dcb0(weakProxy);
        cursor -= 16;
    }
}

// @0x1400103f0
void FUN_1400103f0(UInt32* dst, const UInt32* src)
{
    if (!dst) return;
    *dst = *src;
    void* payload = *reinterpret_cast<void* const*>(src + 2);
    if (payload) FUN_14257dc30(payload);
    *reinterpret_cast<void**>(dst + 2) = payload;
}

// @0x1400121c0
void FUN_1400121c0(void** slot)
{
    char* object = static_cast<char*>(*slot);
    if (object && (*reinterpret_cast<UInt32*>(object + 0x18) & 0x03ffffff) != 0)
    {
        --*reinterpret_cast<UInt32*>(object + 0x18);
        FUN_1425925f0(object);
    }
}

// @0x1400121f0
void** FUN_1400121f0(void** slot, void* value)
{
    if (value)
    {
        UInt32* refs = reinterpret_cast<UInt32*>(static_cast<char*>(value) + 0x18);
        *refs = (*refs + 1) & 0x8fffffff;
    }
    FUN_1400121c0(slot);
    *slot = value;
    return slot;
}

// @0x140012250
void** FUN_140012250(void** slot, void* value)
{
    FUN_1400121c0(slot);
    *slot = value;
    return slot;
}


// MS2-FUNCTIONAL: encloses the object's cached local bounds with the supplied matrix, as observed in the executable.
// @0x140010200
Scaleform::Render::RectF* FUN_140010200(void* object, Scaleform::Render::RectF* result,
                                        const Scaleform::Render::Matrix2F* matrix)
{
    matrix->EncloseTransform(result,
        *reinterpret_cast<const Scaleform::Render::RectF*>(static_cast<char*>(object) + 0xe0));
    return result;
}

// MS2-FUNCTIONAL: wrapper recovered as the executable's direct EncloseTransform call.
// @0x1400101e0
Scaleform::Render::RectF* FUN_1400101e0(const Scaleform::Render::Matrix2F* matrix,
                                        Scaleform::Render::RectF* result,
                                        const Scaleform::Render::RectF* source)
{
    matrix->EncloseTransform(result, *source);
    return result;
}

// @0x14000ffd0
void FUN_14000ffd0(void** object)
{
    if (*object)
        FUN_14257dcb0(*object);
}

}}} // namespace Scaleform::GFx::AS2

// MS2-FUNCTIONAL: releases the two owned members and invokes the recovered base destructor.
// @0x140010490
void FUN_140010490(void* object)
{
    char* bytes = static_cast<char*>(object);
    if (*reinterpret_cast<void**>(bytes + 0x18)) FUN_14257dcb0(*reinterpret_cast<void**>(bytes + 0x18));
    void* fill = *reinterpret_cast<void**>(bytes + 0x10);
    if (fill) reinterpret_cast<void (*)(void*)>(*reinterpret_cast<void***>(fill) + 2)(fill);
    FUN_14257db40(object);
}

// MS2-FUNCTIONAL: copies both StateData words and retains the referenced bag when nonempty.
// @0x140010d70
void FUN_140010d70(void* destination, const void* source)
{
    *static_cast<unsigned __int64*>(destination) = *static_cast<const unsigned __int64*>(source);
    *reinterpret_cast<unsigned __int64*>(static_cast<char*>(destination) + 8) =
        *reinterpret_cast<const unsigned __int64*>(static_cast<const char*>(source) + 8);
    if (*static_cast<const unsigned __int64*>(source)) FUN_142625ee0(destination);
}

// MS2-FUNCTIONAL: assigns the bag only when either side contains state data.
// @0x140010da0
void FUN_140010da0(void* destination, const void* source)
{
    if (*static_cast<const unsigned __int64*>(source) || *static_cast<const unsigned __int64*>(destination))
        FUN_142626070(destination, source);
}

// MS2-FUNCTIONAL: adds a reference through the owned object's interface vtable.
// @0x140010de0
void* FUN_140010de0(void** destination, void* const* source)
{
    void* value = *source;
    if (value)
    {
        void** iface = *reinterpret_cast<void***>(static_cast<char*>(value) + 0x10);
        reinterpret_cast<void (*)(void*)>(iface[1])(static_cast<char*>(value) + 0x10);
    }
    *destination = value;
    return destination;
}

// MS2-FUNCTIONAL: retains the replacement, releases the old value, then stores the replacement.
// @0x140010e60
void* FUN_140010e60(void** destination, void* const* source)
{
    void* value = *source;
    if (value)
    {
        void** iface = *reinterpret_cast<void***>(static_cast<char*>(value) + 0x10);
        reinterpret_cast<void (*)(void*)>(iface[1])(static_cast<char*>(value) + 0x10);
    }
    void* old = *destination;
    if (old)
    {
        void** iface = *reinterpret_cast<void***>(static_cast<char*>(old) + 0x10);
        reinterpret_cast<void (*)(void*)>(iface[2])(static_cast<char*>(old) + 0x10);
    }
    *destination = value;
    return destination;
}

// MS2-FUNCTIONAL: runs Object's executable destructor and frees the allocation when requested.
// @0x140011d10
Scaleform::GFx::AS2::Object* FUN_140011d10(Scaleform::GFx::AS2::Object* object, unsigned flags)
{
    object->~Object();
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}
