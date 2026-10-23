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
#include "../include/gfx/gfx_stream.h"
#include <cstring>

extern void FUN_14257dc30(void*);
extern void FUN_14257dcb0(void*);
extern void FUN_14257dcd0(void*);
extern void FUN_1425eec50(void*, void*, unsigned __int64);
extern const void* FUN_14261c640(const void*, int);
extern void FUN_142581700(void*);
extern void FUN_142626160(void*);
extern void FUN_14257eb30(void*);
extern void FUN_1400105b0(void*);

namespace Scaleform { namespace GFx { namespace Video {

// The provider back-pointer sits at +0x40 and is used while detaching a frame image.
class VideoImage : public RefCountBaseV<VideoImage, Stat_Default_Mem>
{
public:
    UByte Pad[0x40 - 0x10];
    VideoProvider* pVideoProvider;
};

}}} // namespace Scaleform::GFx::Video

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

// @0x14000ffd0
void FUN_14000ffd0(void** object)
{
    if (*object)
        FUN_14257dcb0(*object);
}

}}} // namespace Scaleform::GFx::AS2
