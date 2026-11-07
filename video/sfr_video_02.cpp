// Recovered from MapleStory2.exe KMS2_DEV x64: Scaleform GFx 4.1.18 Video glue, AS3 half.
// Source is written from the executable; leaked SDK copies are naming/layout reference only.
// This part of the Video add-on lib is VS2008 SP1 code, so the unit builds with cl 15.00.30729 and the vc11
// options (MS2-TOOLSET: vc9v, cmake/ms2-unit-profiles.cmake). Keep it C++03: no auto, nullptr, range-for, std:: C
// functions, alias `using`, explicit conversion operators or variadic templates. clang-cl compiles it as before.
// MS2-UNIT: sfr_video_02
// MS2-TOOLSET: vc9v
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14000e470-0x140016b50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_AS2_VALUE_DTOR_CALL
#include "../include/video/video_video.h"
#include "../include/video/video_characterdef.h"
#include "../include/video/video_as3providernetstream.h"
#include "../include/video/video_as2videoobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_actiontypes.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as3/as3_value.h"
#include "../include/gfx/as3/as3_vm.h"
#include "../include/gfx/as3/as3_asvm.h"
#include "../include/gfx/as3/obj/as3_obj_events.h"
#include "../include/gfx/as3/obj/as3_obj_media.h"
#include "../include/gfx/gfx_stream.h"
#include "../include/gfx/gfx_rendertree.h"
#include "../include/render/render_shapedatafloatmp.h"
#include <cstring>
#include <cstdint>
#include <new>

namespace Scaleform { namespace Render {
struct Video02StateDataAccess : StateData
{
    using StateData::addRefBag_NotEmpty;
    using StateData::destroyBag_NotEmpty;
    using StateData::assignBag;
};
struct Video02EntryAccess : ContextImpl::Entry { using ContextImpl::Entry::destroyHelper; };
// Context::createEntryHelper (0x142581520) is private: an explicit instantiation may name it, so this hands out its
// member pointer and the calls below go to the real member.
struct Video02CreateEntryTag
{
    typedef ContextImpl::Entry* (ContextImpl::Context::*Fn)(ContextImpl::EntryData*);
    friend Fn Video02CreateEntryFn(Video02CreateEntryTag);
};
template<class Tag, typename Tag::Fn F> struct Video02Expose { friend typename Tag::Fn Video02CreateEntryFn(Tag) { return F; } };
template struct Video02Expose<Video02CreateEntryTag, &ContextImpl::Context::createEntryHelper>;
inline ContextImpl::Entry* Video02CreateEntry(void* context, void* data)
{
    return (static_cast<ContextImpl::Context*>(context)->*Video02CreateEntryFn(Video02CreateEntryTag()))(
        static_cast<ContextImpl::EntryData*>(data));
}
}}
namespace Scaleform { namespace GFx { namespace AS2 {
struct Video02GCAccess : RefCountBaseGC<323> { using RefCountBaseGC<323>::ReleaseInternal; };
}}}

namespace Scaleform { namespace GFx { namespace AS2 {
// Unit-local classes of sfr_video_01, declared here for their native callbacks.
// VideoProto: see its vftable model at the end of this file.
class VideoProto : public Prototype<VideoObject>
{
public:
    VideoProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
        : Prototype<VideoObject>(psc, pprototype, constructor) {}
    // (implicit destructor: the ??_G 0x14000ec40 inlines it; FUN_14000ebe0 is the out-of-line ~Prototype<VideoObject>)
    static void AttachVideo(const FnCall& fn);   // exe 0x14000d400
};
class VideoCtorFunction : public CFunctionObject
{
public:
    VideoCtorFunction(ASStringContext* psc) : CFunctionObject(psc, GlobalCtor) {}
    // (implicit destructor: the ??_G 0x14000ed20 calls the out-of-line ~CFunctionObject)
    virtual Object* CreateNewObject(Environment* penv) const;   // exe 0x14000e0c0 (sfr_video_01)
    static void GlobalCtor(const FnCall& fn);   // exe 0x14000e100
};
Object* FUN_14000e1e0(Object* pthis, ASStringContext* psc, Object* prototype, const FunctionRef& constructor);   // sfr_video_01
}}}
namespace Scaleform { namespace GFx { namespace AS3 {
void Sfr33PathEndRun(UByte* self);                            // sfr_as3_17
void Sfr31WriteRecord3(UPInt self, UInt32 a, UInt32 b, UInt32 c);   // sfr_as3_19
}}}
struct Video02DispatcherAccess : Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher
{
    using EventDispatcher::ForEachChild_GC;
};

// The protected GASPrototypeBase / Object members the exe calls directly.
struct Video02PrototypeAccess : Scaleform::GFx::AS2::GASPrototypeBase
{
    using GASPrototypeBase::Init;
    using GASPrototypeBase::InitFunctionMembers;
    using GASPrototypeBase::DoesImplement; typedef bool (GASPrototypeBase::*AddInterfaceSlot)(void*, void*, void*); static AddInterfaceSlot AddInterfaceAsSlot() { return reinterpret_cast<AddInterfaceSlot>(&GASPrototypeBase::AddInterface); }
};
struct Video02FinalizeAccess : Scaleform::GFx::AS2::Object
{
    using Object::Finalize_GC;
};

extern void FUN_14257dc30(void*);
extern void FUN_14257dcb0(void*);
extern void FUN_14257dcd0(void*);
// ArrayDataBase<UByte, AllocatorGH>::Reserve (0x142522c70) and ArrayDataBase<FillStyleType, AllocatorLH>::ResizeNoConstruct
// (0x1425eec50) through member pointers: the exe calls the out-of-line copies; a direct call inlines the header bodies.
typedef Scaleform::ArrayDataBase<Scaleform::UByte, Scaleform::AllocatorGH<Scaleform::UByte, 2>,
                                 Scaleform::ArrayDefaultPolicy> Video02ByteData;
typedef Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType, Scaleform::AllocatorLH<Scaleform::Render::FillStyleType, 2>,
                                 Scaleform::ArrayDefaultPolicy> Video02FillData;
static __forceinline void Video02ReserveBytes(void* array, const void* heapAddr, unsigned __int64 newCapacity)
{
    void (Video02ByteData::*reserve)(const void*, Scaleform::UPInt) = &Video02ByteData::Reserve;
    (static_cast<Video02ByteData*>(array)->*reserve)(heapAddr, newCapacity);
}
static __forceinline void Video02ResizeFills(void* array, const void* heapAddr, unsigned __int64 newSize)
{
    void (Video02FillData::*resize)(const void*, Scaleform::UPInt) = &Video02FillData::ResizeNoConstruct;
    (static_cast<Video02FillData*>(array)->*resize)(heapAddr, newSize);
}
extern void FUN_14257eb30(void*);
#define DAT_143b15f60 (static_cast<void*>(Scaleform::Memory::pGlobalHeap))
#include "../include/render/render_gradients.h"   // GradientData, for ComplexFill's Ptr<GradientData>
namespace Scaleform { namespace Render { inline ComplexFill::ComplexFill() : BindIndex(~0u) {} }}   // the SDK ctor (as in sfr_gfx_06e): the fill below stores ??_7ComplexFill by name
namespace Scaleform { typedef ArrayPagedBase<const GFx::AS3::RefCountBaseGC<323>*, 10, 5, AllocatorPagedLH_POD<const GFx::AS3::RefCountBaseGC<323>*, 2> > Video02GcRoots; template<> bool Video02GcRoots::allocatePageSafe(UPInt); struct ArrayPagedFriend { static bool AllocatePageSafe(Video02GcRoots* a, UPInt nb) { return a->allocatePageSafe(nb); } }; } // (C3) FUN_1423dfe30
extern void* PTR_FUN_1431b71b0;
extern void* PTR_FUN_1431b7260;
extern void* PTR_LAB_1431b5fb0;
extern void* PTR_LAB_1431b5f20;
extern void* PTR_LAB_1431b67d0;
extern void* PTR_LAB_1431b6740;
extern void* PTR_LAB_1431b6540;
extern void* PTR_LAB_1431b65f0;
extern void* PTR_LAB_1431b5e70;
extern void* PTR_LAB_1431b5e18;
extern void* PTR_FUN_1431b5e20;
extern void* PTR_LAB_1431b65f0;
extern void* PTR_LAB_1431b6540;
extern void* PTR_FUN_1431b64f0;
extern void* PTR_LAB_1431b6440;
extern void* PTR_LAB_1431b6430;
extern void* PTR_FUN_1431b7360;
extern void* PTR_FUN_1431b6060;
extern void* PTR_LAB_1431b63f8;
extern void* PTR_LAB_1431b6690;
extern void* PTR_LAB_1431b6638;
extern void* PTR_FUN_1431b6640;
extern void* PTR_FUN_1431b7858;
extern void* DAT_143b274d8;
extern void* DAT_143b274e0;
extern void* DAT_143b27518;
extern void* DAT_143b27520;
extern void* DAT_143b27698;
extern void* DAT_143b276a0;
extern void* DAT_143b27458;
extern void* DAT_143b27460;
extern void* DAT_143b27478;
extern void* DAT_143b27480;
extern void* DAT_143b274f8;
extern void* DAT_143b27500;
extern void* DAT_143b27448;
extern void* DAT_143b27450;
extern void* DAT_143b274c8;
extern void* DAT_143b274d0;
extern void* DAT_143b274b8;
extern void* DAT_143b274c0;
extern void* DAT_143b276e8;
extern void* DAT_143b276f0;
extern void* DAT_143b27578;
extern void* DAT_143b27580;
extern void* DAT_143b27568;
extern void* DAT_143b27570;
extern void* DAT_143b27468;
extern void* DAT_143b27470;
extern void* DAT_143b27508;
extern void* DAT_143b27510;
extern void* DAT_143b274e8;
extern void* DAT_143b274f0;
extern void* DAT_143b276a8;
extern void* DAT_143b276b0;
extern void* DAT_143b276c8;
extern void* DAT_143b276d0;
extern void* DAT_143b27628;
extern void* DAT_143b27630;
extern void* DAT_143b27648;
extern void* DAT_143b27650;
extern void* DAT_143b27538;
extern void* DAT_143b27540;
extern void* DAT_143b27618;
extern void* DAT_143b27620;
extern void* DAT_143b27688;
extern void* DAT_143b27690;
extern void* DAT_143b276b8;
extern void* DAT_143b276c0;
extern void* DAT_143b275c8;
extern void* DAT_143b275d0;
extern void* DAT_143b275a8;
extern void* DAT_143b275b0;
extern void* DAT_143b27658;
extern void* DAT_143b27660;
extern void* DAT_143b27438;
extern void* DAT_143b27440;
extern void* DAT_143b275b8;
extern void* DAT_143b275c0;
extern void* DAT_143b27678;
extern void* DAT_143b27680;
extern void* FUN_1400105b0(void*);
// The RefCount base destructors, called directly as the exe calls them (0x14257db50 / 0x14257db40).
static inline void RawRefCountNTSCoreDtor(void* p) { static_cast<Scaleform::RefCountNTSImplCore*>(p)->Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(); }
static inline void RawRefCountCoreDtor(void* p) { static_cast<Scaleform::RefCountImplCore*>(p)->Scaleform::RefCountImplCore::~RefCountImplCore(); }
// ShapeDataFloatTempl<Array<UByte> >::MoveTo/LineTo/StartLayer (0x142518040/0x142515a20/0x1425ef130) through member
// pointers: the exe calls the out-of-line copies; a direct call inlines the header bodies.
typedef Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<Scaleform::UByte> > Video02ShapeData;
static __forceinline void Video02MoveTo(void* path, float x, float y)
{
    void (Video02ShapeData::*moveTo)(float, float) = &Video02ShapeData::MoveTo;
    (static_cast<Video02ShapeData*>(path)->*moveTo)(x, y);
}
static __forceinline void Video02LineTo(void* path, float x, float y)
{
    void (Video02ShapeData::*lineTo)(float, float) = &Video02ShapeData::LineTo;
    (static_cast<Video02ShapeData*>(path)->*lineTo)(x, y);
}
static __forceinline void Video02StartLayer(void* path)
{
    void (Video02ShapeData::*startLayer)() = &Video02ShapeData::StartLayer;
    (static_cast<Video02ShapeData*>(path)->*startLayer)();
}
extern void FUN_14000d330(void*);                                  // Video.clear (sfr_video_01)

// NetConnection.connect (exe 0x140011b00) is an empty native method.
static void Video02NetConnectionConnect(const Scaleform::GFx::AS2::FnCall&) {}

// The exe's native method tables. The data unit only defines the first 8-byte slot of each
// (PTR_s_connect_1431b6410, PTR_s_attachVideo_1431b5800), and the fullexe does not lay data out at exe VAs,
// so InitFunctionMembers must get a complete {0, 0}-terminated table.
static const Scaleform::GFx::AS2::NameFunction Video02ConnectFunctions[] = {   // 0x1431b6410
    {"connect", Video02NetConnectionConnect},
    {0, 0},
};
namespace Scaleform { namespace GFx { namespace AS2 {
// The AS2 NetConnection object (vftables 0x1431b65f0 / +0x20 0x1431b6540): an Object with its own type tag. Its ??_G
// 0x140011d10 calls the out-of-line ~Object; the ObjectInterface slot 0 is cl's adjustor thunk 0x140011d00.
class NetConnection : public Object
{
public:
    NetConnection(ASStringContext* psc, Object* pprototype) : Object(psc) { Set__proto__(psc, pprototype); }
    virtual ObjectType GetObjectType() const;   // exe 0x140011b80 (FUN_140011b80, bound by /alternatename)
};
// constructor and __constructor__ from the prototype part (exe 0x140011de0, FUN_140011de0, bound by /alternatename)
template<> bool Prototype<NetConnection>::GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val);
// NetConnection's prototype (vftables 0x1431b6640 / +0x20 0x1431b6690 / +0x68 0x1431b6638). Its ??_G is 0x1400125e0;
// the ObjectInterface / GASPrototypeBase slots are cl's adjustor thunks 0x140012580 / 0x140012590. The
// Prototype<NetConnection> base's own vftables are 0x1431b64f0 / 0x1431b6440 / 0x1431b6430 (??_G 0x140011c00,
// thunks 0x140011c70 / 0x140011c80).
class NetConnectionProto : public Prototype<NetConnection>
{
public:
    NetConnectionProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
        : Prototype<NetConnection>(psc, pprototype, constructor)
    {
        InitFunctionMembers(this, psc, Video02ConnectFunctions, PropFlags(1));
    }
};
}}}
static const Scaleform::GFx::AS2::NameFunction Video02VideoFunctions[] = {     // 0x1431b5800
    {"attachVideo", Scaleform::GFx::AS2::VideoProto::AttachVideo},
    {"clear", reinterpret_cast<Scaleform::GFx::AS2::CFunctionPtr>(&FUN_14000d330)},
    {0, 0},
};
namespace Scaleform { namespace GFx { namespace AS2 {
void FUN_140014830(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher*); // defined below, in the AS2 block
}}}
namespace Scaleform { namespace GFx { namespace AS3 {
// The exe's out-of-line copies of the private Value::AddRef/Release (0x140012a90, 0x140012ac0, 0x140014c50).
struct Video02ValueRefs
{
    static SF_INLINE void AddRef(const Value* value) { value->AddRef(); }
    static SF_INLINE void Release(Value* value) { value->Release(); }
};
}}} // namespace Scaleform::GFx::AS3
extern void FUN_142504530(void*, void*, void*, void*);

namespace Scaleform { namespace GFx { namespace Video {

// The provider back-pointer sits at +0x40 and is used while detaching a frame image.
class VideoImage : public RefCountBaseV<VideoImage, Stat_Default_Mem>
{
public:
    UByte Pad[0x40 - 0x10];
    VideoProvider* pVideoProvider;
};

}}} // namespace Scaleform::GFx::Video

// @0x140013350
void* FUN_140013350(void* object, unsigned int flags)
{
    RawRefCountNTSCoreDtor(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// @0x140014bb0
void* FUN_140014bb0(void* object, unsigned int flags)
{
    RawRefCountNTSCoreDtor(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// @0x140015550
void* FUN_140015550(void* object, unsigned int flags)
{
    RawRefCountNTSCoreDtor(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// dispatches the recovered EventDispatcher destructor, then conditionally frees the allocation.
// @0x140015590
void* FUN_140015590(void* object, unsigned flags)
{
    Scaleform::GFx::AS2::FUN_140014830(static_cast<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher*>(object));
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// @0x140014a80
Scaleform::GFx::AS3::InstanceTraits::CTraits* FUN_140014a80(
    Scaleform::GFx::AS3::InstanceTraits::CTraits* object, unsigned flags)
{
    object->CTraits::~CTraits();  // MS2: non-virtual, as the exe (a virtual call from the deleting dtor recurses)
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// @0x140014b10
Scaleform::GFx::AS3::Class* FUN_140014b10(Scaleform::GFx::AS3::Class* object, unsigned flags)
{
    object->Class::~Class();  // MS2: non-virtual, as the exe (a virtual call from the deleting dtor recurses)
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// @0x140013db0
void FUN_140013db0(int* refCount)
{
    if (--*refCount == 0) Scaleform::Memory::Free(refCount);
}

// reproduces the base destructor followed by the conditional global-heap delete.
// @0x140015c00
void* FUN_140015c00(void* object, unsigned flags)
{
    RawRefCountNTSCoreDtor(object);
    if (flags & 1) Scaleform::Memory::Free(object);
    return object;
}

// @0x140014400
void FUN_140014400(void* object, void*, char invoke)
{
    void*& target = *reinterpret_cast<void**>(static_cast<char*>(object) + 0x50);   // re-read after the call
    ((::Scaleform::GFx::AS3::VideoProviderNetStream*)(target))->Stop();
    if (invoke)
    {
        void** vtable = *reinterpret_cast<void***>(target);
        reinterpret_cast<void (*)(void*)>(vtable[4])(target);
    }
}

// BEHAVIOUR FIX: the exe converts the unsigned count to float first (cvtsi2ss of the zero-extended value), then to
// double. It used to convert the signed int straight to double.
// @0x1400146c0
void FUN_1400146c0(void* object, double* result)
{
    const float count = static_cast<float>(
        static_cast<Scaleform::GFx::AS3::VideoProviderNetStream*>(*reinterpret_cast<void**>(static_cast<char*>(object) + 0x50))->GetPosition() + 1u);
    *result = count;
}

// Updates the stored track index and selects that subtitle channel unless the track value is undefined or null.
// @0x140014730
void FUN_140014730(void* object, void*, double value)
{
    char* bytes = static_cast<char*>(object);
    *reinterpret_cast<int*>(bytes + 0x84) = static_cast<int>(value) - 1;
    const ::Scaleform::GFx::AS3::Value& track = *reinterpret_cast<const ::Scaleform::GFx::AS3::Value*>(bytes + 0xd8);
    if (!track.IsUndefined() && !track.IsNull())
        ((::Scaleform::GFx::AS3::VideoProviderNetStream*)(*reinterpret_cast<void**>(bytes + 0x50)))->SetSubtitleChannel(static_cast<int>(value) - 1);
}

// (0x1400104d0 / 0x140010530 are Video02Character's ~Video02Character and ??_G, emitted by its out-of-line dtor below)

// (0x14000ed20 is VideoCtorFunction's ??_G, emitted by Video02EmitVideoCtorVftables)

// VideoCharacter's image/update entry points are called from the AS2 provider in video_01.
// Releases the image and refreshes the render tree. The exe tests the slot in memory, then reloads it for the release (the volatile read).
// @0x140010a30
void FUN_140010a30(Scaleform::GFx::Video::VideoCharacter* pvideo)
{
    char* object = reinterpret_cast<char*>(pvideo);
    Scaleform::Ptr<Scaleform::GFx::Video::VideoImage>* image =
        reinterpret_cast<Scaleform::Ptr<Scaleform::GFx::Video::VideoImage>*>(object + 0x100);
    if (*image)
    {
        Scaleform::GFx::Video::VideoImage* p = *reinterpret_cast<Scaleform::GFx::Video::VideoImage* volatile*>(object + 0x100);
        if (p) p->Release();
        *reinterpret_cast<void**>(object + 0x100) = 0;
        FUN_1400105b0(pvideo);
    }
}

// Locks the weak provider (a dead proxy is released and the WeakPtr cleared), takes the active provider's texture into
// +0x100 with its extent, then refreshes the render tree. Same calls and stores as the exe.
// @0x140010a70
void FUN_140010a70(Scaleform::GFx::Video::VideoCharacter* pvideo)
{
    char* object = reinterpret_cast<char*>(pvideo);
    // the AVM interface (object + [0x6d]*4) slot 12 returns the video extent; FUN_140011610 scales the fill by it
    char* iface = object + static_cast<unsigned char>(object[0x6d]) * sizeof(int);
    int* extent = static_cast<int*>(reinterpret_cast<void* (*)(void*)>((*reinterpret_cast<void***>(iface))[12])(iface));
    Scaleform::WeakPtr<Scaleform::GFx::Video::VideoProvider>* provider =
        reinterpret_cast<Scaleform::WeakPtr<Scaleform::GFx::Video::VideoProvider>*>(object + 0xf8);
    Scaleform::Ptr<Scaleform::GFx::Video::VideoImage>* image =
        reinterpret_cast<Scaleform::Ptr<Scaleform::GFx::Video::VideoImage>*>(object + 0x100);
    // both locals live to the end: the exe releases strong, then next, after FUN_1400105b0
    Scaleform::Ptr<Scaleform::GFx::Video::VideoImage> next;
    Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> strong = *provider;
    if (strong && strong->IsActive())
    {
        int width, height;
        next = strong->GetTexture(&width, &height);
        // the exe only swaps the reference (0x140010b24); image +0x40 is the owning player CreateTexture stored
        if (next)
        {
            *image = next;
            extent[2] = width;
            extent[3] = height;
        }
    }
    FUN_1400105b0(pvideo);
}

// Updates the weak provider reference and detaches the old image before render refresh. The outer image test reads
// the raw slot (exe: cmp qword [rdi+0x100],0, then Ptr::Clear reloads it), so cl does not fold it into Clear's test.
// @0x140010b80
void FUN_140010b80(Scaleform::GFx::Video::VideoCharacter* pvideo,
                   Scaleform::GFx::Video::VideoProvider* pprovider)
{
    char* object = reinterpret_cast<char*>(pvideo);
    Scaleform::WeakPtr<Scaleform::GFx::Video::VideoProvider>& provider =
        *reinterpret_cast<Scaleform::WeakPtr<Scaleform::GFx::Video::VideoProvider>*>(object + 0xf8);
    Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> current = provider;
    if (pprovider != current.GetPtr())
    {
        provider = pprovider;
        if (*reinterpret_cast<void**>(object + 0x100))
        {
            reinterpret_cast<Scaleform::Ptr<Scaleform::GFx::Video::VideoImage>*>(object + 0x100)->Clear();
            FUN_1400105b0(pvideo);
        }
    }
}

// 0x140010250 is the out-of-line copy of this SF_INLINE operator; cl 17.00 inlines every call, so instantiate it
// MS2-PIN: ??4?$WeakPtr@VVideoProvider@Video@GFx@Scaleform@@@Scaleform@@QEAAXPEAVVideoProvider@Video@GFx@1@@Z 0x140010250
template void Scaleform::WeakPtr<Scaleform::GFx::Video::VideoProvider>::operator=(Scaleform::GFx::Video::VideoProvider*);

namespace Scaleform { namespace GFx { namespace Video {

}}} // namespace Scaleform::GFx::Video

namespace Scaleform { namespace GFx { namespace AS2 {

// Forwards to slot 4 of the adjusted interface, with the context from slot 31 (+0xf8) of the base object.
// @0x14000e470
void FUN_14000e470(void** adjustedThis, void*, void* arg3, void* arg4)
{
    typedef void* (*GetContextFn)(void*);
    typedef void (*DispatchFn)(void*, void*, void*, void*);
    DispatchFn* dispatchTable = *reinterpret_cast<DispatchFn**>(adjustedThis);   // the exe loads this vtable before the first call
    void** base = adjustedThis - 1;
    dispatchTable[4](adjustedThis, reinterpret_cast<GetContextFn*>(*base)[0xf8 / 8](base), arg3, arg4);
}

// The cached script object (sfr_video_01).
VideoObject* FUN_14000e020(AvmCharacter* character);

#pragma function(memcpy)   // the exe's state copy-assigns call memcpy out of line and return dst themselves
// @0x14000fc90
void* FUN_14000fc90(void* dst, const void* src) { memcpy(dst, src, 0x30); return dst; }

// @0x14000fcb0
void* FUN_14000fcb0(void* dst, const void* src) { memcpy(dst, src, 0x30); return dst; }

// @0x14000fcd0
void* FUN_14000fcd0(void* dst, const void* src) { memcpy(dst, src, 0x40); return dst; }

// @0x14000fcf0
void* FUN_14000fcf0(void* dst, const void* src) { memcpy(dst, src, 0x40); return dst; }
#pragma intrinsic(memcpy)

// The Render state data follows the state refcount and storage pointer in both states.
// copies the 0x30-byte state payload out through a stack copy
#pragma function(memcpy)
// @0x14000ff10
bool FUN_14000ff10(const void* node, void* out)
{
    const void* state = static_cast<const Scaleform::Render::TreeNode*>(node)->GetState(static_cast<Scaleform::Render::StateType>(5));
    if (!state)
        return false;
    const char* data = *reinterpret_cast<const char* const*>(static_cast<const char*>(state) + 8);
    unsigned __int64 state_copy[6];   // the exe copies the payload through a stack copy
    memcpy(state_copy, data + 0x10, 0x30);
    memcpy(out, state_copy, 0x30);
    return true;
}
#pragma intrinsic(memcpy)

// copies the 0x40-byte state payload out through a stack copy
#pragma function(memcpy)
// @0x14000ff70
bool FUN_14000ff70(const void* node, void* out)
{
    const void* state = static_cast<const Scaleform::Render::TreeNode*>(node)->GetState(static_cast<Scaleform::Render::StateType>(6));
    if (!state)
        return false;
    const char* data = *reinterpret_cast<const char* const*>(static_cast<const char*>(state) + 8);
    unsigned __int64 state_copy[8];   // the exe copies the payload through a stack copy
    memcpy(state_copy, data + 0x10, 0x40);
    memcpy(out, state_copy, 0x40);
    return true;
}
#pragma intrinsic(memcpy)

#pragma function(memcpy)   // called out of line here too
// @0x140010eb0
void* FUN_140010eb0(void* dst, const void* src) { memcpy(dst, src, 0x30); return dst; }
#pragma intrinsic(memcpy)

// The 16-byte item: a four-byte tag, then a payload retained by its copy.
struct Video02RetainedItem
{
    UInt32 Tag;
    void* pPayload;
    Video02RetainedItem(const Video02RetainedItem& source) : Tag(source.Tag)
    {
        if (source.pPayload)
            FUN_14257dc30(source.pPayload);
        pPayload = source.pPayload;
    }
};

// Append one retained 16-byte item (four-byte tag plus refcounted payload).
// @0x1400110c0
void FUN_1400110c0(unsigned __int64* array, const UInt32* item)
{
    Video02ResizeFills(array, array, array[1] + 1);
    ::new (reinterpret_cast<void*>(array[0] - 0x10 + array[1] * 0x10))
        Video02RetainedItem(*reinterpret_cast<const Video02RetainedItem*>(item));
}

// @0x140011240
void FUN_140011240(unsigned __int64* array, const UInt32* item)
{
    Video02ResizeFills(array, array, array[1] + 1);
    ::new (reinterpret_cast<void*>(array[0] - 0x10 + array[1] * 0x10))
        Video02RetainedItem(*reinterpret_cast<const Video02RetainedItem*>(item));
}

// MS2-FUNCTIONAL: appends one byte with the executable's growth thresholds and reserve call.
// BEHAVIOUR FIX: reserves through ArrayDataBase<UByte, AllocatorGH>::Reserve (0x142522c70) like the exe, not
// FUN_1425eec50 (the 16-byte-element FillStyleType ResizeNoConstruct, about 25 times the memory). The shrink branch
// now reserves when the size drops below half the capacity, as the exe does; it was inverted (unreachable after +1).
// the SDK ArrayDataBase::ResizeNoConstruct, inlined into its PushBack caller
static __forceinline void Video02ResizeBytes(unsigned __int64* array, unsigned __int64 newSize)
{
    if (newSize < array[1])
    {
        if (newSize < (array[2] >> 1))
            Video02ReserveBytes(array, array, newSize);
    }
    else if (newSize >= array[2])
        Video02ReserveBytes(array, array, newSize + (newSize >> 2));
    array[1] = newSize;
}

// @0x140010f60
void FUN_140010f60(unsigned __int64* array, const UByte* value)
{
    Video02ResizeBytes(array, array[1] + 1);
    UByte* slot = reinterpret_cast<UByte*>(array[0]) + array[1] - 1;   // placement construction of the new last byte
    if (slot) *slot = *value;
}

// Four-byte transform data is appended as four byte elements by the exe.
// @0x140011120
void FUN_140011120(void** parray, float value)
{
    const UByte* bytes = reinterpret_cast<const UByte*>(&value);
    FUN_140010f60(static_cast<unsigned __int64*>(*parray), bytes);
    FUN_140010f60(static_cast<unsigned __int64*>(*parray), bytes + 1);
    FUN_140010f60(static_cast<unsigned __int64*>(*parray), bytes + 2);
    FUN_140010f60(static_cast<unsigned __int64*>(*parray), bytes + 3);
}

// BEHAVIOUR FIX: the exe reserves through ArrayDataBase<UByte, AllocatorGH>::Reserve (0x142522c70). This called
// FUN_1425eec50, ArrayDataBase<FillStyleType, AllocatorLH>::ResizeNoConstruct, which sizes the buffer for 16-byte
// elements and adds its own quarter growth, so every byte array grown here took about 25 times the memory.
// @0x140010390
void FUN_140010390(unsigned __int64* array, void* reserveSource, unsigned __int64 newSize)
{
    if (newSize < array[1])
    {
        if (newSize < (array[2] >> 1))
            Video02ReserveBytes(array, reserveSource, newSize);
    }
    else if (newSize >= array[2])
        Video02ReserveBytes(array, reserveSource, newSize + (newSize >> 2));
    array[1] = newSize;
}

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

// @0x140012f60
void** FUN_140012f60(void* context, void** result, const char* text)
{
    ASStringManager* manager = *reinterpret_cast<ASStringManager**>(static_cast<char*>(context) + 0x1e8);
    ASStringNode* node = manager->CreateConstStringNode(text, strlen(text), 0);
    *result = node;
    ++*reinterpret_cast<unsigned*>(reinterpret_cast<char*>(node) + 0x18);
    return result;
}

// @0x140012fb0
void** FUN_140012fb0(void* context, void** result, const char* text)
{
    ASStringManager* manager = *reinterpret_cast<ASStringManager**>(static_cast<char*>(context) + 0x1e8);
    ASStringNode* node = manager->CreateStringNode(text);
    *result = node;
    ++*reinterpret_cast<unsigned*>(reinterpret_cast<char*>(node) + 0x18);
    return result;
}

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
    // two "null" temps, copied into the pair in reverse; the manager is read from the context for each
    ASString first((*reinterpret_cast<ASStringManager**>(static_cast<char*>(context) + 0x1e8))->CreateConstStringNode("null", 4, 0));
    ASString second((*reinterpret_cast<ASStringManager**>(static_cast<char*>(context) + 0x1e8))->CreateConstStringNode("null", 4, 0));
    reinterpret_cast<ASString*>(result)->ASString::ASString(second);
    reinterpret_cast<ASString*>(result + 1)->ASString::ASString(first);
    return result;
}

// @0x1400151a0
long long* FUN_1400151a0(long long* dst, const long long* src)
{
    if (*src) FUN_14257dc30(reinterpret_cast<void*>(*src));
    if (*dst) FUN_14257dcb0(reinterpret_cast<void*>(*dst));
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

// The AS3 Value SetKind + V(payload) assignments, as the exe inlines them (the payload goes through a 16-byte V temp).
static SF_INLINE ::Scaleform::GFx::AS3::Value& ScalarValue(UInt32* value)
{
    return *reinterpret_cast< ::Scaleform::GFx::AS3::Value*>(value);
}

// initializes the scalar kind and payload at the offsets used by the executable's AS3 Value.
// @0x140013cc0
void FUN_140013cc0(UInt32* value, UByte input) { ScalarValue(value).SetBoolUnsafe(*reinterpret_cast<const bool*>(&input)); }

// initializes the integer kind and payload at the executable's AS3 Value offsets.
// @0x140013cf0
void FUN_140013cf0(UInt32* value, UInt32 input) { ScalarValue(value).SetUInt32Unsafe(input); }

// initializes the number kind and payload at the executable's AS3 Value offsets.
// @0x140013d20
void FUN_140013d20(UInt32* value, double input) { ScalarValue(value).SetNumberUnsafe(input); }

// scalar boolean setter with the same tag and payload layout.
// @0x140015110
void FUN_140015110(UInt32* value, const UByte* input) { ScalarValue(value).SetBoolUnsafe(*reinterpret_cast<const bool*>(input)); }

// scalar integer setter with the same tag and payload layout.
// @0x1400150e0
void FUN_1400150e0(UInt32* value, const UInt32* input) { ScalarValue(value).SetUInt32Unsafe(*input); }

// scalar number setter with the same tag and payload layout.
// @0x140015080
void FUN_140015080(UInt32* value, const double* input) { ScalarValue(value).SetNumberUnsafe(*input); }

// returning wrapper around the scalar boolean setter.
// @0x140013fb0
uintptr_t FUN_140013fb0(uintptr_t self, UInt32* value, const UByte* input)
{
    ScalarValue(value).SetBoolUnsafe(*reinterpret_cast<const bool*>(input));
    return self;
}

// returning wrapper around the scalar integer setter.
// @0x140013ff0
uintptr_t FUN_140013ff0(uintptr_t self, UInt32* value, const UInt32* input)
{
    ScalarValue(value).SetUInt32Unsafe(*input);
    return self;
}

// returning wrapper around the scalar number setter.
// @0x140014020
uintptr_t FUN_140014020(uintptr_t self, UInt32* value, const double* input)
{
    ScalarValue(value).SetNumberUnsafe(*input);
    return self;
}

// @0x140012d30
uintptr_t FUN_140012d30(uintptr_t self, uintptr_t result, Scaleform::GFx::AS3::Value* input)
{
    input->Convert2Number(*reinterpret_cast<double*>(result));
    return self;
}

// @0x140013a00
void FUN_140013a00(void* result, Scaleform::GFx::AS3::Value* input)
{
    input->Convert2Number(*static_cast<double*>(result));
}

// @0x140012d00
uintptr_t FUN_140012d00(uintptr_t self, SInt32* result, const Scaleform::GFx::AS3::Value* input)
{
    input->Convert2Int32(*result);
    return self;
}

// @0x140013a40
void FUN_140013a40(SInt32* result, const Scaleform::GFx::AS3::Value* input)
{
    input->Convert2Int32(*result);
}

// @0x140015170
void FUN_140015170(UInt32 index, SInt32* result, UInt32 length, const void* values)
{
    if (length > index)
    {
        const Scaleform::GFx::AS3::Value* input = reinterpret_cast<const Scaleform::GFx::AS3::Value*>(
            static_cast<const char*>(values) + static_cast<size_t>(index) * 0x20);
        input->Convert2Int32(*result);
    }
}

// @0x1400150b0
void FUN_1400150b0(UInt32 index, void* result, UInt32 length, const void* values)
{
    if (length > index)
    {
        const Scaleform::GFx::AS3::Value* input = reinterpret_cast<const Scaleform::GFx::AS3::Value*>(
            static_cast<const char*>(values) + static_cast<size_t>(index) * 0x20);
        input->Convert2Number(*static_cast<double*>(result));
    }
}

// VC9 `add [m],-1` release and register choice differ (cl15 object).
// @0x140013f20
uintptr_t FUN_140013f20(uintptr_t self, Scaleform::GFx::ASString* result,
                        const Scaleform::GFx::AS3::Value* input)
{
    if (input->IsNull())
        result->SetNull();
    else
        input->Convert2String(*result);
    return self;
}

// VC9 `add [m],-1` release and register choice differ (cl15 object).
// @0x140015420
void FUN_140015420(Scaleform::GFx::ASString* result, const Scaleform::GFx::AS3::Value* input)
{
    if (input->IsNull())
        result->SetNull();
    else
        input->Convert2String(*result);
}

// Value::Release: drops a weak or strong reference when the value is refcounted.
// @0x140014c50
void FUN_140014c50(Scaleform::GFx::AS3::Value* value)
{
    Scaleform::GFx::AS3::Video02ValueRefs::Release(value);
}

// @0x140014c30
Scaleform::GFx::AS3::Value* FUN_140014c30(Scaleform::GFx::AS3::Value* value,
                                          Scaleform::GFx::AS3::Object* object)
{
    value->Pick(object);
    return value;
}

// @0x140014c90
void FUN_140014c90(ASStringNode** strings)
{
    strings[1]->Release();
    strings[0]->Release();
}

// @0x140014cc0
void FUN_140014cc0(void* object)
{
    char* bytes = static_cast<char*>(object);
    reinterpret_cast<ASStringNode**>(bytes + 0x18)[0]->Release();
    reinterpret_cast<ASStringNode**>(bytes + 0x10)[0]->Release();
}

// @0x140014cf0
void FUN_140014cf0(ASStringNode** strings)
{
    strings[2]->Release();
    strings[1]->Release();
    strings[0]->Release();
}

// @0x140014d30
void FUN_140014d30(void* object)
{
    char* bytes = static_cast<char*>(object);
    reinterpret_cast<ASStringNode**>(bytes + 0x20)[0]->Release();
    reinterpret_cast<ASStringNode**>(bytes + 0x18)[0]->Release();
    reinterpret_cast<ASStringNode**>(bytes + 0x10)[0]->Release();
}

static void* NumberNaNBits();

// Stores the executable's NaN payload in the third numeric field.
// @0x140014e10
void** FUN_140014e10(void** values, void* first, void* second)
{
    values[0] = first;
    values[1] = second;
    *reinterpret_cast<double*>(&values[2]) = NumberUtil::NaN();
    return values;
}

// Releases the VideoPlayer references and AS3 fields before delegating to the recovered base dtor.
// @0x140014830
void FUN_140014830(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher* dispatcher)
{
    // the exe's dtor: vftable store, the player detached with no null check, the AS3 Value members destroyed in
    // place in reverse order (0xd8, 0xb8, 0x98), then the two weak references (+0x58, +0x50)
    char* fields = reinterpret_cast<char*>(dispatcher);
    *reinterpret_cast<void**>(fields) = &PTR_FUN_1431b7360;
    *reinterpret_cast<void**>(*reinterpret_cast<char**>(fields + 0x50) + 0x18) = 0;
    ((::Scaleform::GFx::AS3::VideoProviderNetStream*)(*reinterpret_cast<void**>(fields + 0x50)))->Stop();
    reinterpret_cast<Scaleform::GFx::AS3::Value*>(fields + 0xd8)->~Value();
    reinterpret_cast<Scaleform::GFx::AS3::Value*>(fields + 0xb8)->~Value();
    reinterpret_cast<Scaleform::GFx::AS3::Value*>(fields + 0x98)->~Value();
    if (*reinterpret_cast<void**>(fields + 0x58)) FUN_14257dcd0(*reinterpret_cast<void**>(fields + 0x58));
    if (*reinterpret_cast<void**>(fields + 0x50)) FUN_14257dcd0(*reinterpret_cast<void**>(fields + 0x50));
    dispatcher->EventDispatcher::~EventDispatcher();  // MS2: non-virtual, as the exe (a virtual call from the deleting dtor recurses)
}

// to SetSoundVolume.
// @0x1400142e0
void FUN_1400142e0(void* object, void*, void* soundTransform)
{
    if (!soundTransform) return;
    char* fields = static_cast<char*>(object);
    double* x = reinterpret_cast<double*>(fields + 0x88);
    static_cast<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform*>(soundTransform)->volumeGet(*x);
    ((::Scaleform::GFx::AS3::VideoProviderNetStream*)(*reinterpret_cast<void**>(fields + 0x50)))->SetSoundVolume(static_cast<int>(x[0] * 100.0),
                  static_cast<int>(*reinterpret_cast<double*>(fields + 0x90) * 100.0));
}

// to SetSoundVolume.
// @0x140014770
void FUN_140014770(void* object, void*, void* soundTransform)
{
    if (!soundTransform) return;
    char* fields = static_cast<char*>(object);
    double* y = reinterpret_cast<double*>(fields + 0x90);
    static_cast<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform*>(soundTransform)->volumeGet(*y);
    ((::Scaleform::GFx::AS3::VideoProviderNetStream*)(*reinterpret_cast<void**>(fields + 0x50)))->SetSoundVolume(static_cast<int>(*reinterpret_cast<double*>(fields + 0x88) * 100.0),
                  static_cast<int>(y[0] * 100.0));
}

static void* NumberNaNBits()
{
    union { double number; void* pointer; } value;
    value.number = NumberUtil::NaN();
    return value.pointer;
}

// @0x140014e80
void** FUN_140014e80(void** value) { *value = NumberNaNBits(); return value; }
// @0x140014ee0
void** FUN_140014ee0(void** value) { *value = NumberNaNBits(); return value; }
// @0x140014f00
void** FUN_140014f00(void** value) { *value = NumberNaNBits(); return value; }
// @0x140014f90
void** FUN_140014f90(void** value) { *value = NumberNaNBits(); return value; }
// @0x140014fb0
void** FUN_140014fb0(void** value) { *value = NumberNaNBits(); return value; }
// @0x140014fd0
void** FUN_140014fd0(void** value) { *value = NumberNaNBits(); return value; }
// @0x140014ff0
void** FUN_140014ff0(void** value) { *value = NumberNaNBits(); return value; }
// @0x140015010
void** FUN_140015010(void** value) { *value = NumberNaNBits(); return value; }
// @0x140015030
void** FUN_140015030(void** value) { *value = NumberNaNBits(); return value; }
// @0x140015050
void** FUN_140015050(void** value) { *value = NumberNaNBits(); return value; }

// @0x1400129d0
Scaleform::GFx::AS3::Value* FUN_1400129d0(Scaleform::GFx::AS3::Value* dst,
                                          const Scaleform::GFx::AS3::Value* src)
{
    *dst = *src;
    return dst;
}

// @0x140013be0
Scaleform::GFx::AS3::Value* FUN_140013be0(Scaleform::GFx::AS3::Value* dst,
                                          const Scaleform::GFx::AS3::Value* src)
{
    dst->Scaleform::GFx::AS3::Value::Value(*src);   // in place, no null check
    return dst;
}

// @0x1400151e0
Scaleform::GFx::AS3::Value* FUN_1400151e0(Scaleform::GFx::AS3::Value* dst,
                                          const Scaleform::GFx::AS3::Value* src)
{
    dst->Scaleform::GFx::AS3::Value::Value(*src);   // in place, no null check
    return dst;
}

// Copies the AS3 undefined singleton; __restrict keeps the source flags in a register as the exe does.
// @0x140013ec0
Scaleform::GFx::AS3::Value* FUN_140013ec0(Scaleform::GFx::AS3::Value* dst)
{
    Scaleform::GFx::AS3::Value* __restrict out = dst;
    out->Scaleform::GFx::AS3::Value::Value(Scaleform::GFx::AS3::Value::GetUndefined());   // in place, no null check
    return dst;
}

// Same undefined-Value copy as FUN_140013ec0, on a UInt32* view of the slot.
// @0x140015340
UInt32* FUN_140015340(UInt32* dst)
{
    Scaleform::GFx::AS3::Value* __restrict value = reinterpret_cast<Scaleform::GFx::AS3::Value*>(dst);
    value->Scaleform::GFx::AS3::Value::Value(Scaleform::GFx::AS3::Value::GetUndefined());   // in place, no null check
    return dst;
}

// @0x140014060
void** FUN_140014060(void** result, void* context)
{
    ASStringManager* manager = *reinterpret_cast<ASStringManager**>(static_cast<char*>(context) + 0x1e8);
    ASStringNode* node = manager->CreateConstStringNode("null", 4, 0);
    *result = node;
    node->AddRef();
    return result;
}

// @0x1400140a0
void** FUN_1400140a0(void** result, void* context)
{
    ASStringManager* manager = *reinterpret_cast<ASStringManager**>(static_cast<char*>(context) + 0x1e8);
    ASStringNode* node = manager->CreateConstStringNode("null", 4, 0);
    *result = node;
    node->AddRef();
    return result;
}

// @0x140012cd0
uintptr_t FUN_140012cd0(uintptr_t self, UByte* result, Scaleform::GFx::AS3::Value* input)
{
    *result = input->Convert2Boolean();
    return self;
}

// Forwards the executable's argument frame to the recovered VM internal invocation method.
// @0x140012c30
void FUN_140012c30(Scaleform::GFx::AS3::VM* vm, const Scaleform::GFx::AS3::Value& function,
                   const Scaleform::GFx::AS3::Value& thisValue, Scaleform::GFx::AS3::Value& result,
                   unsigned argc, const Scaleform::GFx::AS3::Value* argv, bool)
{
    // The exe ignores the discard flag and always keeps the result.
    vm->ExecuteInternalUnsafe(function, thisValue, result, argc, argv, false);
}

// @0x140013a20
void FUN_140013a20(UByte* result, Scaleform::GFx::AS3::Value* input)
{
    *result = input->Convert2Boolean();
}

// transfers the object reference into the AS3 Value: Value::Pick<Object>(Pickable<Object>). The Pickable taken by value
// makes cl call Pick from a frame (sub rsp; call; add rsp) as the exe does, not tail-jump.
// @0x140013790
void FUN_140013790(Scaleform::GFx::AS3::Value* value, Scaleform::Pickable<Scaleform::GFx::AS3::Object> object)
{
    value->Pick(object);
}

// @0x140015140
void FUN_140015140(UInt32 index, UByte* result, UInt32 length, Scaleform::GFx::AS3::Value* values)
{
    if (length > index)
        *result = (reinterpret_cast<Scaleform::GFx::AS3::Value*>(
                       reinterpret_cast<char*>(values) + static_cast<size_t>(index) * 0x20))->Convert2Boolean();
}

// Value::AddRef: adds a weak or strong reference when the value is refcounted.
// @0x140012a90
void FUN_140012a90(Scaleform::GFx::AS3::Value* value)
{
    AS3::Video02ValueRefs::AddRef(value);
}

// Value::Release: drops a weak or strong reference when the value is refcounted.
// @0x140012ac0
void FUN_140012ac0(Scaleform::GFx::AS3::Value* value)
{
    AS3::Video02ValueRefs::Release(value);
}

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform { namespace GFx { namespace AS3 {
// Visits the collectable a value holds (0x142504530, sfr_as3_06).
void ForEachChild_GC_Internal(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const Value& v,
                              ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner);
}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS2 {

// AS3 ForEachChild_GC for a Value: visits it when it is collectable and not a weak reference.
// @0x140012b80
void FUN_140012b80(AS3::RefCountCollector<StatMV_ActionScript_Mem>* prcc, const AS3::Value& v,
                   AS3::ASRefCountBaseType::GcOp op, const AS3::ASRefCountBaseType& owner)
{
    if (v.IsGarbageCollectable() && !v.IsWeakRef())
        AS3::ForEachChild_GC_Internal(prcc, v, op, owner);
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
    long long* count = reinterpret_cast<long long*>(static_cast<char*>(entry) + 8);
    if (--*count == 0) static_cast<Scaleform::Render::Video02EntryAccess*>(entry)->Scaleform::Render::Video02EntryAccess::destroyHelper();
}

// @0x14000f5c0
void FUN_14000f5c0(void** object) { ReleaseRenderEntry(*object); }

// @0x14000f5e0
void** FUN_14000f5e0(void** dst, void* value)
{
    if (value) ++*reinterpret_cast<long long*>(static_cast<char*>(value) + 8);
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
    if (*reinterpret_cast<void* const*>(src + 2))
        FUN_14257dc30(*reinterpret_cast<void* const*>(src + 2));
    *reinterpret_cast<void**>(dst + 2) = *reinterpret_cast<void* const*>(src + 2);
    return dst;
}

// @0x14000fed0
void FUN_14000fed0(void* object)
{
    void* ref = *reinterpret_cast<void**>(static_cast<char*>(object) + 8);
    if (ref)
        FUN_14257dcb0(ref);
}

// Render::StateData destructor: releases a non-empty bag. destroyBag_NotEmpty (0x142626160) takes the bag itself.
// BEHAVIOUR FIX: this passed the bag's interface pointer (*object) as the bag.
// @0x14000f060
void FUN_14000f060(void** object)
{
    if (*object)
        static_cast<Scaleform::Render::Video02StateDataAccess*>(static_cast<void*>(object))->destroyBag_NotEmpty();
}

// @0x14000ef80
UByte FUN_14000ef80(Stream* stream) { return stream->ReadU8(); }

// @0x14000efc0
UInt16 FUN_14000efc0(Stream* stream) { return stream->ReadU16(); }

}}} // namespace Scaleform::GFx::AS2
namespace Scaleform { namespace GFx { namespace Video {
// Reads the tag fields at the executable offsets (the LoadProcess stream: the alternate one at
// +0x418, else the one at +0x50).
// @0x14000f2d0
void VideoCharacterDef::Read(LoadProcess* p, int)
{
    char* movie = reinterpret_cast<char*>(p);
    Stream* stream = *reinterpret_cast<Stream**>(movie + 0x418);
    if (!stream) stream = reinterpret_cast<Stream*>(movie + 0x50);
    char* fields = reinterpret_cast<char*>(this);
    *reinterpret_cast<unsigned*>(fields + 0x20) = stream->ReadU16();
    *reinterpret_cast<unsigned*>(fields + 0x24) = stream->ReadU16();
    *reinterpret_cast<unsigned*>(fields + 0x28) = stream->ReadU16();
    stream->ReadUInt(5);
    fields[0x2c] = static_cast<char>(stream->ReadUInt(2));
    fields[0x2d] = stream->ReadUInt(1) != 0;
    fields[0x2e] = static_cast<char>(stream->ReadU8());
}
}}} // namespace Scaleform::GFx::Video
namespace Scaleform { namespace GFx { namespace AS2 {

// @0x14000f0e0
void FUN_14000f0e0(void* entry)
{
    long long* ref = reinterpret_cast<long long*>(static_cast<char*>(entry) + 8);
    if (--*ref == 0)
        static_cast<Scaleform::Render::Video02EntryAccess*>(entry)->Scaleform::Render::Video02EntryAccess::destroyHelper();
}

// @0x14000f1a0
void FUN_14000f1a0(void* node)
{
    if (*reinterpret_cast<void**>(static_cast<char*>(node) + 0x40))
        static_cast<Scaleform::Render::Video02StateDataAccess*>(static_cast<void*>(static_cast<char*>(node) + 0x40))->destroyBag_NotEmpty();
    FUN_14257eb30(node);
}

// @0x14000f270
void FUN_14000f270(void* node)
{
    if (*reinterpret_cast<void**>(static_cast<char*>(node) + 0x40))
        static_cast<Scaleform::Render::Video02StateDataAccess*>(static_cast<void*>(static_cast<char*>(node) + 0x40))->destroyBag_NotEmpty();
    FUN_14257eb30(node);
}

// @0x14000fdb0
void** FUN_14000fdb0(void** dst, void* next)
{
    // the weak proxy's Release, inline: free it from the global heap when its count drops to zero
    void* old = *dst;
    if (old && --*static_cast<int*>(old) == 0)
    {
        Scaleform::MemoryHeap* heap = Scaleform::Memory::pGlobalHeap;
        reinterpret_cast<void(*)(void*, void*)>((*reinterpret_cast<void***>(heap))[0x60 / sizeof(void*)])(heap, old);
    }
    *dst = next;
    return dst;
}

// locks a weak proxy: the live target, or 0 (a proxy whose object is gone is released and cleared);
// WeakPtr<C>::GetObjectThroughProxy, the SDK body
// @0x14000fe00
void* FUN_14000fe00(void** weakProxy)
{
    typedef Scaleform::GFx::Video::VideoProvider C;
    Scaleform::Ptr<Scaleform::WeakPtrProxy>& pProxy = *reinterpret_cast<Scaleform::Ptr<Scaleform::WeakPtrProxy>*>(weakProxy);
    C* pobject = 0;
    if (pProxy)
    {
        if (pProxy->IsAlive())
        {
            pobject = (C*)pProxy->GetObject();
            if (pobject->GetRefCount() == 0)
                pobject = 0;
        }
        else
            pProxy.Clear();
    }
    return pobject;
}

// WeakPtr<VideoProvider>::operator Ptr<VideoProvider> (the SDK GetObjectThroughProxy body)
// @0x1400102c0
void** FUN_1400102c0(void** weakProxy, void** strongTarget)
{
    typedef Scaleform::GFx::Video::VideoProvider C;
    Scaleform::Ptr<Scaleform::WeakPtrProxy>& pProxy = *reinterpret_cast<Scaleform::Ptr<Scaleform::WeakPtrProxy>*>(weakProxy);
    C* pobject = 0;
    if (pProxy)
    {
        if (pProxy->IsAlive())
        {
            pobject = (C*)pProxy->GetObject();
            if (pobject->GetRefCount() == 0)
                pobject = 0;
        }
        else
            pProxy.Clear();
    }
    reinterpret_cast<Scaleform::Ptr<C>*>(strongTarget)->Scaleform::Ptr<C>::Ptr(pobject);
    return strongTarget;
}

// @0x140010340
void FUN_140010340(void* begin, size_t count)
{
    if (!count)
        return;
    char* cursor = static_cast<char*>(begin) - 8 + count * 16;
    do
    {
        void* weakProxy = *reinterpret_cast<void**>(cursor);
        if (weakProxy) FUN_14257dcb0(weakProxy);
        cursor -= 16;
    } while (--count);
}

// @0x1400103f0
void FUN_1400103f0(UInt32* dst, const UInt32* src)
{
    if (!dst) return;
    *dst = *src;
    if (*reinterpret_cast<void* const*>(src + 2)) FUN_14257dc30(*reinterpret_cast<void* const*>(src + 2));
    *reinterpret_cast<void**>(dst + 2) = *reinterpret_cast<void* const*>(src + 2);
}

// @0x1400121c0
void FUN_1400121c0(void** slot)
{
    char* object = static_cast<char*>(*slot);
    if (object && (*reinterpret_cast<UInt32*>(object + 0x18) & 0x03ffffff) != 0)
    {
        --*reinterpret_cast<UInt32*>(object + 0x18);
        reinterpret_cast<Scaleform::GFx::AS2::Video02GCAccess*>(object)->ReleaseInternal();
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



// @0x1400101e0
Scaleform::Render::RectF* FUN_1400101e0(const Scaleform::Render::Matrix2F* matrix,
                                        Scaleform::Render::RectF* result,
                                        const Scaleform::Render::RectF* source)
{
    matrix->EncloseTransform(result, *source);
    return result;
}

// releases a raw refcounted allocation (count at +0): frees it when the count drops to zero.
// BEHAVIOUR FIX (latent): this called RefCountImpl::Release (0x14257dcb0: vftable at +0, count at +8, virtual delete);
// the exe decrements the int at +0 and frees the block. Nothing in the exe calls or references 0x14000ffd0.
// @0x14000ffd0
void FUN_14000ffd0(void** object)
{
    void* p = *object;
    if (p && --*static_cast<int*>(p) == 0)
        Scaleform::Memory::Free(p);
}

}}} // namespace Scaleform::GFx::AS2

// @0x140010490
void FUN_140010490(void* object)
{
    char* bytes = static_cast<char*>(object);
    if (*reinterpret_cast<void**>(bytes + 0x18)) FUN_14257dcb0(*reinterpret_cast<void**>(bytes + 0x18));
    void* fill = *reinterpret_cast<void**>(bytes + 0x10);
    if (fill) reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(fill))[2])(fill);
    RawRefCountCoreDtor(object);
}

// Copies both StateData words and retains the referenced bag when nonempty.
// @0x140010d70
void* FUN_140010d70(void* destination, const void* source)
{
    *static_cast<unsigned __int64*>(destination) = *static_cast<const unsigned __int64*>(source);
    *reinterpret_cast<unsigned __int64*>(static_cast<char*>(destination) + 8) =
        *reinterpret_cast<const unsigned __int64*>(static_cast<const char*>(source) + 8);
    if (*static_cast<const unsigned __int64*>(source)) static_cast<const Scaleform::Render::Video02StateDataAccess*>(static_cast<const void*>(destination))->addRefBag_NotEmpty();
    return destination;
}

// Assigns the bag only when either side contains state data. The exe loads source and ors destination; the volatile
// read keeps source in the load (cl folds the volatile-free operand into the or).
// @0x140010da0
void FUN_140010da0(void* destination, const void* source)
{
    if ((*static_cast<const volatile unsigned __int64*>(source) | *static_cast<const unsigned __int64*>(destination)) != 0)
        static_cast<Scaleform::Render::Video02StateDataAccess*>(destination)->assignBag(*static_cast<const Scaleform::Render::StateData*>(source));
}

// @0x140010de0
void* FUN_140010de0(void** destination, void* const* source)
{
    void* value = *source;
    if (value)
    {
        void** iface = *reinterpret_cast<void***>(static_cast<char*>(value) + 0x10);
        reinterpret_cast<void (*)(void*)>(iface[1])(static_cast<char*>(value) + 0x10);
    }
    *destination = *source;
    return destination;
}

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
    *destination = *source;
    return destination;
}

// (0x140011d10 is NetConnection's ??_G, emitted by Video02EmitNetConnectionVftables)

// @0x140011410
void FUN_140011410(void* path)
{
    unsigned char* bytes = static_cast<unsigned char*>(path);
    const float lastX = *reinterpret_cast<float*>(bytes + 0x5c);
    const float lastY = *reinterpret_cast<float*>(bytes + 0x60);
    if (lastX != *reinterpret_cast<float*>(bytes + 0x54) ||
        lastY != *reinterpret_cast<float*>(bytes + 0x58))
        Video02LineTo(path, *reinterpret_cast<float*>(bytes + 0x54), *reinterpret_cast<float*>(bytes + 0x58));
}

// Rebuilds a path from its control points, closes it at the current endpoint, and finalizes it.
// @0x140011500
void FUN_140011500(void* object, float x1, float y1, float x2, float y2)
{
    void** path = reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x88);   // reloaded for each step
    Video02MoveTo(*path, x1, y1);
    Video02LineTo(*path, x2, y1);
    Video02LineTo(*path, x2, y2);
    Video02LineTo(*path, x1, y2);
    FUN_140011410(*path);
    Scaleform::GFx::AS3::Sfr33PathEndRun(static_cast<Scaleform::UByte*>(*path));
}

// @0x1400115c0
void FUN_1400115c0(void* object)
{
    FUN_140011410(*reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x88));
}

// environment's builtin prototype type 0x22.
// @0x140011c90
Scaleform::GFx::AS2::Object* FUN_140011c90(Scaleform::GFx::AS2::Object* object,
                                            Scaleform::GFx::AS2::Environment* environment)
{
    object->Scaleform::GFx::AS2::Object::Object(environment);
    *reinterpret_cast<void**>(object) = &PTR_LAB_1431b65f0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(object) + 0x20) = &PTR_LAB_1431b6540;
    Scaleform::GFx::AS2::ObjectInterface* iface = reinterpret_cast<Scaleform::GFx::AS2::ObjectInterface*>(
        reinterpret_cast<char*>(object) + 0x20);
    iface->Set__proto__(environment->GetSC(),
        environment->GetPrototype(static_cast<Scaleform::GFx::AS2::ASBuiltinType>(0x22)));
    return object;
}

// BEHAVIOUR FIX: allocates from the movie's heap (Environment::GetHeap), as the exe does and as the constructor
// path at 0x140012340 already did; it used the global heap.
// @0x140011d50
Scaleform::GFx::AS2::Object* FUN_140011d50(void*, Scaleform::GFx::AS2::Environment* environment)
{
    void* storage = environment->GetHeap()->Alloc(0x68);
    if (storage) return FUN_140011c90(static_cast<Scaleform::GFx::AS2::Object*>(storage), environment);
    return 0;
}

// Releases the interface array storage and runs the executable prototype finalizer.
// @0x140011d90
void FUN_140011d90(void* object)
{
    void** interfaces = *reinterpret_cast<void***>(static_cast<char*>(object) + 0xa0);
    if (interfaces)
    {
        Scaleform::Memory::Free(interfaces[0]);
        Scaleform::Memory::Free(*reinterpret_cast<void**>(static_cast<char*>(object) + 0xa0));
    }
    static_cast<Video02FinalizeAccess*>(object)->Video02FinalizeAccess::Finalize_GC();
}

// @0x140011b10
void FUN_140011b10(void* object, void* stringContext, void* functions, const void* flags)
{
    reinterpret_cast<Video02PrototypeAccess*>(static_cast<char*>(object) + 0x68)->InitFunctionMembers(
        static_cast<Scaleform::GFx::AS2::Object*>(object), static_cast<Scaleform::GFx::AS2::ASStringContext*>(stringContext),
        static_cast<const Scaleform::GFx::AS2::NameFunction*>(functions), *static_cast<const Scaleform::GFx::AS2::PropFlags*>(flags));
}

// The exe copies Value::GetUndefined() into a temp, copy-constructs the fresh result storage from it (no release of the
// old contents) and destroys the temp.
// @0x1400158e0
Scaleform::GFx::AS3::Value* FUN_1400158e0(Scaleform::GFx::AS3::Value* result)
{
    Scaleform::GFx::AS3::Value undefinedValue(Scaleform::GFx::AS3::Value::GetUndefined());
    result->Scaleform::GFx::AS3::Value::Value(undefinedValue);   // in place, no null check
    return result;
}

// A retained link of the chain: copying AddRefs, assigning and clearing reload the slot.
struct Video02ChainPtr
{
    void* pObject;
    Video02ChainPtr(const Video02ChainPtr& source)
    {
        if (source.pObject) FUN_14257dc30(source.pObject);
        pObject = source.pObject;
    }
    ~Video02ChainPtr() { if (pObject) FUN_14257dcb0(pObject); }
    void operator=(const Video02ChainPtr& source)
    {
        if (source.pObject) FUN_14257dc30(source.pObject);
        if (pObject) FUN_14257dcb0(pObject);
        pObject = source.pObject;
    }
    void Clear()
    {
        if (pObject) FUN_14257dcb0(pObject);
        pObject = 0;
    }
};

// Clears the current object and walks/releases its chained child references.
// @0x140015830
void FUN_140015830(void* object)
{
    char* bytes = static_cast<char*>(object);
    Video02ChainPtr node(*reinterpret_cast<Video02ChainPtr*>(bytes + 0x80));
    reinterpret_cast<Video02ChainPtr*>(bytes + 0x80)->Clear();
    if (node.pObject)
    {
        *reinterpret_cast<unsigned char*>(bytes + 0x78) |= 0x10;
        do
        {
            Video02ChainPtr next(*reinterpret_cast<Video02ChainPtr*>(static_cast<char*>(node.pObject) + 0x20));
            reinterpret_cast<Video02ChainPtr*>(static_cast<char*>(node.pObject) + 0x20)->Clear();
            node = next;
        } while (node.pObject);
    }
}

// @0x140013e00
unsigned char* FUN_140013e00(void* vm, unsigned char* result, unsigned* value,
                             void* receiver, unsigned flags, void* argument)
{
    static_cast<Scaleform::GFx::AS3::VM*>(vm)->Construct(static_cast<const char*>(receiver),
        *reinterpret_cast<Scaleform::GFx::AS3::Value*>(value), flags,
        static_cast<const Scaleform::GFx::AS3::Value*>(argument), true);   // VM::Construct 0x1424f0750
    if (!*reinterpret_cast<unsigned char*>(static_cast<char*>(vm) + 0x180))
    {
        unsigned tag = *value & 0x1f;
        if (tag != 0)
        {
            bool isNullObject = false;
            if (tag - 0x0c <= 3) isNullObject = *reinterpret_cast<void**>(value + 4) == 0;
            if (!isNullObject)
            {
                *result = 1;
                return result;
            }
        }
    }
    *result = 0;
    return result;
}

// BEHAVIOUR FIX: the exe constructs the Value with Flags = 0 and a null Bonus (weak proxy) before the assign. The
// SetUndefinedUnsafe here only cleared the kind bits of the uninitialised slot, which left stray flag bits and a
// garbage weak-proxy pointer in the new Value.
// @0x1400156a0
Scaleform::GFx::AS3::Value* FUN_1400156a0(Scaleform::GFx::AS3::Value* result,
                                         Scaleform::GFx::AS3::Object* const* object)
{
    *reinterpret_cast<Scaleform::UInt32*>(result) = 0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(result) + 8) = 0;
    result->AssignUnsafe(*object);
    return result;
}

// @0x1400155d0
void FUN_1400155d0(void*, Scaleform::GFx::AS3::Value* result, void* traits)
{
    extern void* FUN_1400140e0(void*, void*);
    void* instanceTraits = static_cast<const Scaleform::GFx::AS3::Traits*>(traits)->Alloc();
    Scaleform::GFx::AS3::Object* instance = instanceTraits
        ? static_cast<Scaleform::GFx::AS3::Object*>(FUN_1400140e0(instanceTraits, traits))
        : 0;
    result->Pick(instance);
}

// writes a numeric result only when the VM has no pending exception.
// @0x1400156d0
void FUN_1400156d0(void** frame)
{
    char* vm = static_cast<char*>(frame[0]);
    if (!*reinterpret_cast<unsigned char*>(vm + 0x180))
    {
        Scaleform::GFx::AS3::Value* result = static_cast<Scaleform::GFx::AS3::Value*>(frame[1]);
        result->SetNumberUnsafe(*reinterpret_cast<double*>(&frame[2]));
    }
}

// @0x140015710
void** FUN_140015710(void** frame, void* vm, void* receiver, int convert,
                     Scaleform::GFx::AS3::Value* source, const uintptr_t* extra)
{
    frame[0] = vm;
    frame[1] = receiver;
    frame[2] = reinterpret_cast<void*>(*extra);
    if (convert)
        source->Convert2Number(*reinterpret_cast<double*>(&frame[2]));
    return frame;
}

// writes an integer result only when the VM has no pending exception.
// @0x140015750
void FUN_140015750(void** frame)
{
    char* vm = static_cast<char*>(frame[0]);
    if (!*reinterpret_cast<unsigned char*>(vm + 0x180))
    {
        Scaleform::GFx::AS3::Value* result = static_cast<Scaleform::GFx::AS3::Value*>(frame[1]);
        result->SetUInt32Unsafe(static_cast<Scaleform::UInt32>(reinterpret_cast<intptr_t>(frame[2])));
    }
}

// writes a boolean result only when the VM has no pending exception.
// @0x140015790
void FUN_140015790(void** frame)
{
    char* vm = static_cast<char*>(frame[0]);
    if (!*reinterpret_cast<unsigned char*>(vm + 0x180))
    {
        Scaleform::GFx::AS3::Value* result = static_cast<Scaleform::GFx::AS3::Value*>(frame[1]);
        result->SetBoolUnsafe(*reinterpret_cast<bool*>(&frame[2]));   // the exe stores the raw low byte
    }
}

// @0x1400157d0
void** FUN_1400157d0(void** frame, void* vm, void* receiver, int convert,
                     uintptr_t value, const unsigned char* extra)
{
    frame[0] = vm;
    frame[1] = receiver;
    // ThunkArgs1<bool>::a0 is one byte, stored as the exe stores it (the rest of the slot is padding).
    unsigned char& a0 = *reinterpret_cast<unsigned char*>(&frame[2]);
    a0 = *extra;
    if (convert)
    {
        a0 = reinterpret_cast<const Scaleform::GFx::AS3::Value*>(value)->Convert2Boolean();
    }
    return frame;
}

// @0x140014ac0
void** FUN_140014ac0(void*, void** result, void* traits)
{
    extern void* FUN_1400140e0(void*, void*);
    void* instanceTraits = static_cast<const Scaleform::GFx::AS3::Traits*>(traits)->Alloc();
    *result = instanceTraits ? FUN_1400140e0(instanceTraits, traits) : 0;
    return result;
}

// BEHAVIOUR FIX: the table grows only when the index reaches the capacity (+0x18), as the exe does; ours compared
// the page count (+0x10), so every append reallocated the table and added five more slots. The table and the
// 0x2000-byte page come from the array's own heap (AllocAutoHeap on the array, stat 2), not the global heap.
// @0x140013600
void FUN_140013600(void* array, unsigned __int64 index)
{
    char* bytes = static_cast<char*>(array);
    const unsigned __int64 capacity = *reinterpret_cast<unsigned __int64*>(bytes + 0x18);
    if (index >= capacity)
    {
        char* data = *reinterpret_cast<char**>(bytes + 0x20);
        void* grown;
        if (data)
            grown = Scaleform::Memory::Realloc(data, capacity * 8 + 0x28);
        else
            grown = Scaleform::Memory::AllocAutoHeap(array, 0x28, Scaleform::AllocInfo(2, 0, 0));
        *reinterpret_cast<unsigned __int64*>(bytes + 0x18) += 5;
        *reinterpret_cast<void**>(bytes + 0x20) = grown;
    }
    void* page = Scaleform::Memory::AllocAutoHeap(array, 0x2000, Scaleform::AllocInfo(2, 0, 0));
    (*reinterpret_cast<void***>(bytes + 0x20))[index] = page;
    ++*reinterpret_cast<unsigned __int64*>(bytes + 0x10);
}

// AS3 ForEachChild_GC for a Value, inline as in the SDK.
static SF_INLINE void Video02ForEachChildGC(
    Scaleform::GFx::AS3::RefCountCollector<Scaleform::GFx::AS3::StatMV_ActionScript_Mem>* prcc,
    const Scaleform::GFx::AS3::Value& v, Scaleform::GFx::AS3::ASRefCountBaseType::GcOp op,
    const Scaleform::GFx::AS3::ASRefCountBaseType& owner)
{
    if (v.IsGarbageCollectable() && !v.IsWeakRef())
        Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, v, op, owner);
}

// Follows the executable's EventDispatcher GC traversal and visits its three Value fields.
// @0x140012e10
void FUN_140012e10(void* dispatcher, void* collector, void* operation)
{
    char* fields = static_cast<char*>(dispatcher);
    static_cast<Video02DispatcherAccess*>(dispatcher)->Video02DispatcherAccess::ForEachChild_GC(
        static_cast<Scaleform::GFx::AS3::RefCountCollector<Scaleform::GFx::AS3::StatMV_ActionScript_Mem>*>(collector),
        reinterpret_cast<Scaleform::GFx::AS3::RefCountBaseGC<Scaleform::GFx::AS3::StatMV_ActionScript_Mem>::GcOp>(operation));
    Scaleform::GFx::AS3::RefCountCollector<Scaleform::GFx::AS3::StatMV_ActionScript_Mem>* prcc =
        static_cast<Scaleform::GFx::AS3::RefCountCollector<Scaleform::GFx::AS3::StatMV_ActionScript_Mem>*>(collector);
    Scaleform::GFx::AS3::ASRefCountBaseType::GcOp op =
        reinterpret_cast<Scaleform::GFx::AS3::ASRefCountBaseType::GcOp>(operation);
    const Scaleform::GFx::AS3::ASRefCountBaseType& owner =
        *static_cast<const Scaleform::GFx::AS3::ASRefCountBaseType*>(dispatcher);
    Video02ForEachChildGC(prcc, *reinterpret_cast<const Scaleform::GFx::AS3::Value*>(fields + 0x98), op, owner);
    Video02ForEachChildGC(prcc, *reinterpret_cast<const Scaleform::GFx::AS3::Value*>(fields + 0xb8), op, owner);
    Video02ForEachChildGC(prcc, *reinterpret_cast<const Scaleform::GFx::AS3::Value*>(fields + 0xd8), op, owner);
}

// releases the video character's retained AS2 value and then runs its AvmCharacter base destructor. The exe stores
// the AvmDisplayObjBase vftable at +0x30 first, as the inline AvmDisplayObjBase dtor does.
// @0x14000e840
void FUN_14000e840(void* object)
{
    char* bytes = static_cast<char*>(object);
    void* value = *reinterpret_cast<void**>(bytes + 0x48);
    if (value && (*reinterpret_cast<unsigned*>(static_cast<char*>(value) + 0x18) & 0x03ffffff))
    {
        --*reinterpret_cast<unsigned*>(static_cast<char*>(value) + 0x18);
        reinterpret_cast<Scaleform::GFx::AS2::Video02GCAccess*>(value)->ReleaseInternal();
    }
    reinterpret_cast<Scaleform::GFx::AvmDisplayObjBase*>(bytes + 0x30)->Scaleform::GFx::AvmDisplayObjBase::~AvmDisplayObjBase();
    static_cast<Scaleform::GFx::AS2::AvmCharacter*>(object)->Scaleform::GFx::AS2::AvmCharacter::~AvmCharacter();
}


// Returns the next paged AS2 collector slot, allocating its 1024-entry page when needed.
// @0x140015250
void* FUN_140015250(void* array)
{
    char* bytes = static_cast<char*>(array);
    const unsigned __int64 page = *reinterpret_cast<unsigned __int64*>(bytes + 8) >> 10;
    if (page >= *reinterpret_cast<unsigned __int64*>(bytes + 0x10) &&
        !Scaleform::ArrayPagedFriend::AllocatePageSafe(reinterpret_cast<Scaleform::Video02GcRoots*>(array), page))
        return 0;
    void** pages = *reinterpret_cast<void***>(bytes + 0x20);
    return static_cast<char*>(pages[page]) + (*reinterpret_cast<unsigned*>(bytes + 8) & 0x3ff) * sizeof(void*);
}

// @0x140014340
void FUN_140014340(void* object, double* result)
{
    void*& stream = *reinterpret_cast<void**>(static_cast<char*>(object) + 0x50);   // re-read after the call
    const unsigned frame = static_cast<Scaleform::GFx::AS3::VideoProviderNetStream*>(stream)->GetPosition();   // the exe asks for the frame first
    const unsigned duration = *reinterpret_cast<unsigned*>(static_cast<char*>(stream) + 0x58);
    const float seconds = duration ? static_cast<float>(frame) / (static_cast<float>(duration) / 1000.0f) : 0.0f;
    *result = seconds;
}

// ---- NetStream natives the AS3 method tables reference (leaf functions, no unwind data) ----------------------------
// The instance keeps the provider at +0x50 and mirrors each setting: +0x60 paused, +0x64 bufferTime,
// +0x68 reloadThresholdTime, +0x6c numberOfFramePools, +0x70 openTimeout, +0x74 loop, +0x78 audioTrack,
// +0x7c subAudioTrack, +0x80 voiceTrack, +0x84 subtitleTrack.
static inline Scaleform::GFx::AS3::VideoProviderNetStream* NetStreamProvider(void* self)
{
    return *(Scaleform::GFx::AS3::VideoProviderNetStream**)((Scaleform::UByte*)self + 0x50);
}
static inline void NetStreamNotImplemented(Scaleform::GFx::AS3::Object* self, const char* msg)
{
    self->GetVM().GetUI().Output(Scaleform::GFx::AS3::FlashUI::Output_Warning, msg);
}

// NetStream.bufferTime getter.
// @0x140012d90
void FUN_140012d90(void* self, double* result) { *result = *(float*)((Scaleform::UByte*)self + 0x64); }
// NetStream.loop getter.
// @0x140012da0
void FUN_140012da0(void* self, bool* result) { *result = *(bool*)((Scaleform::UByte*)self + 0x74); }
// NetStream.audioTrack getter.
// @0x140012db0
void FUN_140012db0(void* self, double* result) { *result = *(int*)((Scaleform::UByte*)self + 0x78); }
// NetStream.subAudioTrack getter.
// @0x140012dc0
void FUN_140012dc0(void* self, double* result) { *result = *(int*)((Scaleform::UByte*)self + 0x7c); }
// NetStream.voiceTrack getter.
// @0x140012dd0
void FUN_140012dd0(void* self, double* result) { *result = *(int*)((Scaleform::UByte*)self + 0x80); }
// NetStream.subtitleTrack getter.
// @0x140012df0
void FUN_140012df0(void* self, double* result) { *result = *(int*)((Scaleform::UByte*)self + 0x84); }

// NetStream.bufferLength getter (unsupported).
// @0x1400141b0
void FUN_1400141b0(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method NetStream::bufferLengthGet() is not implemented\n"); }
// NetStream.bufferTime setter.
// @0x1400141d0
void FUN_1400141d0(void* self, const void* result, double value)
{
    SF_UNUSED(result);
    *(float*)((Scaleform::UByte*)self + 0x64) = (float)value;
    NetStreamProvider(self)->SetBufferTime((float)value);
}
// NetStream.bytesLoaded getter (unsupported).
// @0x1400141f0
void FUN_1400141f0(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method NetStream::bytesLoadedGet() is not implemented\n"); }
// NetStream.bytesTotal getter (unsupported).
// @0x140014210
void FUN_140014210(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method NetStream::bytesTotalGet() is not implemented\n"); }
// NetStream.checkPolicyFile getter (unsupported).
// @0x140014230
void FUN_140014230(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method NetStream::checkPolicyFileGet() is not implemented\n"); }
// NetStream.checkPolicyFile setter (unsupported).
// @0x140014250
void FUN_140014250(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method NetStream::checkPolicyFileSet() is not implemented\n"); }
// the stream's total length in seconds (the provider keeps milliseconds at +0x58).
// @0x140014270
void FUN_140014270(void* self, double* result)
{
    *result = (float)*(unsigned*)((Scaleform::UByte*)NetStreamProvider(self) + 0x58) / 1000.0f;
}
// NetStream.liveDelay getter (unsupported).
// @0x1400142a0
void FUN_1400142a0(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method NetStream::liveDelayGet() is not implemented\n"); }
// NetStream.objectEncoding getter (unsupported).
// @0x1400142c0
void FUN_1400142c0(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method NetStream::objectEncodingGet() is not implemented\n"); }
// NetStream.attachAudio (unsupported).
// @0x1400143c0
void FUN_1400143c0(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method NetStream::attachAudio() is not implemented\n"); }
// NetStream.attachCamera (unsupported).
// @0x1400143e0
void FUN_1400143e0(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method NetStream::attachCamera() is not implemented\n"); }
// NetStream.pause.
// @0x140014440
void FUN_140014440(void* self)
{
    *(bool*)((Scaleform::UByte*)self + 0x60) = true;
    NetStreamProvider(self)->Pause(true);
}
// NetStream.publish (unsupported).
// @0x140014580
void FUN_140014580(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method NetStream::publish() is not implemented\n"); }
// NetStream.receiveAudio (unsupported).
// @0x1400145a0
void FUN_1400145a0(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method NetStream::receiveAudio() is not implemented\n"); }
// NetStream.receiveVideo (unsupported).
// @0x1400145c0
void FUN_1400145c0(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method NetStream::receiveVideo() is not implemented\n"); }
// NetStream.receiveVideoFPS (unsupported).
// @0x1400145e0
void FUN_1400145e0(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method NetStream::receiveVideoFPS() is not implemented\n"); }
// NetStream.resume.
// @0x140014600
void FUN_140014600(void* self)
{
    *(bool*)((Scaleform::UByte*)self + 0x60) = false;
    NetStreamProvider(self)->Pause(false);
}
// NetStream.seek(offset) against the movie the VM runs.
// @0x140014620
void FUN_140014620(Scaleform::GFx::AS3::Object* self, const void* result, double offset)
{
    SF_UNUSED(result);
    NetStreamProvider(self)->Seek((float)offset,
        static_cast<Scaleform::GFx::AS3::ASVM&>(self->GetVM()).GetMovieImpl());
}
// NetStream.send (unsupported).
// @0x140014640
void FUN_140014640(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method NetStream::send() is not implemented\n"); }
// NetStream.setDRMAuthenticationCredentials (unsupported).
// @0x140014660
void FUN_140014660(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method NetStream::setDRMAuthenticationCredentials() is not implemented\n"); }
// NetStream.togglePause.
// @0x140014680
void FUN_140014680(void* self)
{
    bool& paused = *(bool*)((Scaleform::UByte*)self + 0x60);
    paused = !paused;
    NetStreamProvider(self)->Pause(paused);
}
// NetStream.loop setter.
// @0x1400146a0
void FUN_1400146a0(void* self, const void* result, bool value)
{
    SF_UNUSED(result);
    *(bool*)((Scaleform::UByte*)self + 0x74) = value;
    NetStreamProvider(self)->SetLoopFlag(value);
}
// NetStream.audioTrack setter.
// @0x1400146f0
void FUN_1400146f0(void* self, const void* result, double value)
{
    SF_UNUSED(result);
    *(int*)((Scaleform::UByte*)self + 0x78) = (int)value;
    NetStreamProvider(self)->SetAudioTrack((int)value);
}
// NetStream.subAudioTrack setter.
// @0x140014700
void FUN_140014700(void* self, const void* result, double value)
{
    SF_UNUSED(result);
    *(int*)((Scaleform::UByte*)self + 0x7c) = (int)value;
    NetStreamProvider(self)->SetSubAudioTrack((int)value);
}
// NetStream.voiceTrack setter.
// @0x140014710
void FUN_140014710(void* self, const void* result, double value)
{
    SF_UNUSED(result);
    *(int*)((Scaleform::UByte*)self + 0x80) = (int)value;
    NetStreamProvider(self)->ReplaceCenterVoice((int)value);
}
// NetStream.reloadThresholdTime setter.
// @0x1400147d0
void FUN_1400147d0(void* self, const void* result, double value)
{
    SF_UNUSED(result);
    *(float*)((Scaleform::UByte*)self + 0x68) = (float)value;
    NetStreamProvider(self)->SetReloadThresholdTime((float)value);
}
// NetStream.numberOfFramePools setter.
// @0x1400147f0
void FUN_1400147f0(void* self, const void* result, double value)
{
    SF_UNUSED(result);
    const unsigned pools = (unsigned)value;
    *(unsigned*)((Scaleform::UByte*)self + 0x6c) = pools;
    NetStreamProvider(self)->SetNumberOfFramePools(pools);
}
// NetStream.openTimeout setter.
// @0x140014810
void FUN_140014810(void* self, const void* result, double value)
{
    SF_UNUSED(result);
    *(float*)((Scaleform::UByte*)self + 0x70) = (float)value;
    NetStreamProvider(self)->SetOpenURLTimeout((float)value);
}
// NetStream.resetDRMVouchers class method (unsupported).
// @0x140014b50
void FUN_140014b50(Scaleform::GFx::AS3::Object* self)
{ NetStreamNotImplemented(self, "The method class_::NetStream::resetDRMVouchers() is not implemented\n"); }

// reads the indexed AS3 value, maps an empty object-like value to the null string, otherwise stringifies it.
// BEHAVIOUR FIX: the null-object test read +8 (the weak proxy) in place of the object pointer at +0x10, so a live
// object with no weak proxy came back as the null string and was never stringified.
// @0x140015af0
void FUN_140015af0(unsigned index, Scaleform::GFx::ASString* result, unsigned count,
                   const Scaleform::GFx::AS3::Value* values)
{
    if (count <= index) return;
    const unsigned char* value = reinterpret_cast<const unsigned char*>(values) +
                        static_cast<unsigned __int64>(index) * sizeof(Scaleform::GFx::AS3::Value);
    // The object pointer of kinds 0xc-0xf is at +0x10 (+8 holds the weak proxy).
    const unsigned tag = *reinterpret_cast<const unsigned*>(value) & 0x1f;
    bool isNullObject = false;
    if (tag >= 0x0c && tag <= 0x0f) isNullObject = *reinterpret_cast<void* const*>(value + 0x10) == 0;
    if (isNullObject)
    {
        result->SetNull();
        return;
    }
    reinterpret_cast<const Scaleform::GFx::AS3::Value*>(value)->Convert2String(*result);
}

// initializes the executable's class-traits object, its 0xf8-byte instance size, and vtable.
// @0x140012ec0
void* FUN_140012ec0(void* object, void* vm, void* classInfo)
{
    static_cast<Scaleform::GFx::AS3::InstanceTraits::CTraits*>(object)->Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
        *static_cast<Scaleform::GFx::AS3::VM*>(vm), *static_cast<const Scaleform::GFx::AS3::ClassInfo*>(classInfo));
    *reinterpret_cast<void**>(object) = &PTR_FUN_1431b71b0;
    *reinterpret_cast<unsigned*>(static_cast<char*>(object) + 0x60) = 0xf8;
    return object;
}

// @0x140012f10
void* FUN_140012f10(void* object, void* traits)
{
    static_cast<Scaleform::GFx::AS3::Class*>(object)->Scaleform::GFx::AS3::Class::Class(
        *static_cast<Scaleform::GFx::AS3::ClassTraits::Traits*>(traits));
    *reinterpret_cast<void**>(object) = &PTR_FUN_1431b7260;
    return object;
}

// constructs the native AS2 function object with the executable's video constructor callback and tables.
// @0x14000ecc0
Scaleform::GFx::AS2::CFunctionObject* FUN_14000ecc0(
    Scaleform::GFx::AS2::CFunctionObject* object, Scaleform::GFx::AS2::ASStringContext* context)
{
    object->Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(context, Scaleform::GFx::AS2::VideoCtorFunction::GlobalCtor);
    *reinterpret_cast<void**>(object) = &PTR_LAB_1431b5f20;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(object) + 0x20) = &PTR_LAB_1431b5fb0;
    return object;
}

// constructs the frame-rate native function object and installs its executable tables.
// @0x140012650
Scaleform::GFx::AS2::CFunctionObject* FUN_140012650(
    Scaleform::GFx::AS2::CFunctionObject* object, Scaleform::GFx::AS2::ASStringContext* context)
{
    extern void FUN_140012340(const Scaleform::GFx::AS2::FnCall&);
    object->Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(context, FUN_140012340);
    *reinterpret_cast<void**>(object) = &PTR_LAB_1431b6740;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(object) + 0x20) = &PTR_LAB_1431b67d0;
    return object;
}

// initializes the recovered AS2 function prototype's Object and function-reference bases.
// @0x1400122e0
Scaleform::GFx::AS2::Object* FUN_1400122e0(
    Scaleform::GFx::AS2::Object* object, Scaleform::GFx::AS2::ASStringContext* context, void* prototype)
{
    // the exe runs Object(ASStringContext*) (0x14291f6f0), not the prototype overload (0x14291f790), and sets the
    // prototype once below, after the vtables are stored
    object->Scaleform::GFx::AS2::Object::Object(context);
    *reinterpret_cast<void**>(object) = &PTR_LAB_1431b65f0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(object) + 0x20) = &PTR_LAB_1431b6540;
    object->Scaleform::GFx::AS2::Object::Set__proto__(context, static_cast<Scaleform::GFx::AS2::Object*>(prototype));
    return object;
}

// @0x14000eb50
Scaleform::GFx::AS2::Object* FUN_14000eb50(
    Scaleform::GFx::AS2::Object* object, Scaleform::GFx::AS2::ASStringContext* context,
    Scaleform::GFx::AS2::Object* prototype, const void* constructor)
{
    Scaleform::GFx::AS2::FUN_14000e1e0(object, context, prototype,
        *static_cast<const Scaleform::GFx::AS2::FunctionRef*>(constructor));
    *reinterpret_cast<void**>(object) = &PTR_FUN_1431b5e20;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(object) + 0x20) = &PTR_LAB_1431b5e70;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(object) + 0x70) = &PTR_LAB_1431b5e18;
    const Scaleform::GFx::AS2::PropFlags flags(1);
    reinterpret_cast<Video02PrototypeAccess*>(reinterpret_cast<char*>(object) + 0x70)->InitFunctionMembers(
        object, context, Video02VideoFunctions, flags);
    return object;
}

// The members of GASPrototypeBase behind its vptr, as its inlined ctor builds them.
struct Video02PrototypeFields
{
    void* vtable;
    Scaleform::GFx::AS2::FunctionRef Constructor;
    Scaleform::GFx::AS2::FunctionRef ConstructorInternal;
    void* pInterfaces;
    Video02PrototypeFields() : pInterfaces(0) {}
};

// @0x140012440
Scaleform::GFx::AS2::Object* FUN_140012440(
    Scaleform::GFx::AS2::Object* object, Scaleform::GFx::AS2::ASStringContext* context,
    void* prototype, const Scaleform::GFx::AS2::FunctionRef* constructor)
{
    object->Scaleform::GFx::AS2::Object::Object(context);
    *reinterpret_cast<void**>(object) = &PTR_LAB_1431b65f0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(object) + 0x20) = &PTR_LAB_1431b6540;
    object->Scaleform::GFx::AS2::Object::Set__proto__(context, static_cast<Scaleform::GFx::AS2::Object*>(prototype));
    reinterpret_cast<Video02PrototypeFields*>(reinterpret_cast<char*>(object) + 0x68)->Video02PrototypeFields::Video02PrototypeFields();
    *reinterpret_cast<void**>(object) = &PTR_FUN_1431b64f0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(object) + 0x20) = &PTR_LAB_1431b6440;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(object) + 0x68) = &PTR_LAB_1431b6430;
    reinterpret_cast<Video02PrototypeAccess*>(reinterpret_cast<char*>(object) + 0x68)->Init(object, context, *constructor);
    return object;
}

// @0x14000f470
void FUN_14000f470(void* object, void* value)
{
    unsigned flags = 2;
    Scaleform::MemoryHeap* heap = Scaleform::Memory::pGlobalHeap;
    void** heapVtable = *reinterpret_cast<void***>(heap);
    reinterpret_cast<void(*)(void*, void*, void*, unsigned*)>(heapVtable[0x70 / sizeof(void*)])(
        heap, value, object, &flags);
}

// @0x140011de0
void FUN_140011de0(Scaleform::GFx::AS2::Object* object, Scaleform::GFx::AS2::ASStringContext* context,
                   Scaleform::GFx::ASString* name, Scaleform::GFx::AS2::Value* value)
{
    // `object` is the ObjectInterface subobject (the vtable slot's this); the complete Object starts 0x20 before it.
    // the builtins come from the string manager at +0x280 (__constructor__) and +0x278 (constructor), the exe's
    // out-of-line GetStringManager call (0x140011e14); constructor is only tested when __constructor__ fails.
    // BEHAVIOUR FIX: the compare runs on the builtin with the name as its argument, as in the exe, so the name's
    // lowercase node is resolved before the case-insensitive compare (SWF <= 6). Ours resolved the builtin's and
    // read the name's pLower unresolved, so "constructor" spelled in another case could miss.
    typedef Scaleform::GFx::ASString Builtin;
    const bool constructor2 = reinterpret_cast<const Builtin*>(reinterpret_cast<char*>(context->pContext->GetStringManager()) + 0x280)
        ->CompareBuiltIn_CaseCheck(*name, context->IsCaseSensitive());
    if (constructor2 || reinterpret_cast<const Builtin*>(reinterpret_cast<char*>(context->pContext->GetStringManager()) + 0x278)
        ->CompareBuiltIn_CaseCheck(*name, context->IsCaseSensitive()))
    {
        Scaleform::GFx::AS2::Object* owner = reinterpret_cast<Scaleform::GFx::AS2::Object*>(reinterpret_cast<char*>(object) - 0x20);
        Scaleform::GFx::AS2::GASPrototypeBase* prototypeBase = reinterpret_cast<Scaleform::GFx::AS2::GASPrototypeBase*>(
            reinterpret_cast<char*>(object) + 0x48);
        prototypeBase->GetMemberRawConstructor(owner, context, *name, value, constructor2);
        return;
    }
    reinterpret_cast<Scaleform::GFx::AS2::Object*>(reinterpret_cast<char*>(object) - 0x20)
        ->Scaleform::GFx::AS2::Object::GetMemberRaw(context, *name, value);
}

// The NetConnection constructor: reuses a NetConnection `this` that is not the builtin prototype
// (exe: type 0x21, slot 0x80 IsBuiltinPrototype, AddRef on this-0x20), otherwise allocates a plain Object.
// @0x140012340
void FUN_140012340(const Scaleform::GFx::AS2::FnCall& call)
{
    Scaleform::GFx::AS2::Object* object;
    if (call.ThisPtr && call.ThisPtr->GetObjectType() == Scaleform::GFx::AS2::ObjectInterface::Object_NetConnection
        && !call.ThisPtr->IsBuiltinPrototype())
    {
        object = static_cast<Scaleform::GFx::AS2::Object*>(call.ThisPtr);
        if (object)
        {
            unsigned* refs = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(object) + 0x18);
            *refs = (*refs + 1) & 0x8fffffffu;
        }
    }
    else
    {
        void* storage = call.Env->GetHeap()->Alloc(0x68);
        object = storage ? FUN_140011c90(static_cast<Scaleform::GFx::AS2::Object*>(storage), call.Env) : 0;
    }
    call.Result->SetAsObject(object);
    if (object)
    {
        unsigned* count = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(object) + 0x18);
        if ((*count & 0x03ffffffu) != 0)
        {
            --*count;
            reinterpret_cast<Scaleform::GFx::AS2::Video02GCAccess*>(object)->ReleaseInternal();
        }
    }
}

// @0x14000fe50
void* FUN_14000fe50(void* object, unsigned flags)
{
    if (void* resource = *reinterpret_cast<void**>(reinterpret_cast<char*>(object) + 8))
        FUN_14257dcb0(resource);
    if (flags & 1)
        ::operator delete(object);
    return object;
}

// MS2-FUNCTIONAL: runs the executable base constructor and initializes the recovered application fields. The 1.0 store at +0x88
// is volatile so it stays ahead of the float stores, as in the exe; the exe still stores the vptr before the init-list
// stores and sets rax mid-body (a real ctor of unknown layout).
// @0x1400140e0
void* FUN_1400140e0(void* object, void* traits)
{
    static_cast<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher*>(object)->
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(
            *static_cast<Scaleform::GFx::AS3::InstanceTraits::Traits*>(traits));
    unsigned char* bytes = static_cast<unsigned char*>(object);
    *reinterpret_cast<void**>(bytes) = &PTR_FUN_1431b7360;
    *reinterpret_cast<void**>(bytes + 0x50) = 0;
    *reinterpret_cast<void**>(bytes + 0x58) = 0;
    *reinterpret_cast<unsigned*>(bytes + 0x98) = 0;
    *reinterpret_cast<void**>(bytes + 0xa0) = 0;
    *reinterpret_cast<unsigned*>(bytes + 0xb8) = 0;
    *reinterpret_cast<void**>(bytes + 0xc0) = 0;
    *reinterpret_cast<unsigned*>(bytes + 0xd8) = 0;
    *reinterpret_cast<void**>(bytes + 0xe0) = 0;
    *reinterpret_cast<volatile double*>(bytes + 0x88) = 1.0;
    bytes[0x60] = 0;
    bytes[0x74] = 0;
    *reinterpret_cast<float*>(bytes + 0x64) = 0.1f;
    *reinterpret_cast<float*>(bytes + 0x68) = 0.08f;
    *reinterpret_cast<unsigned*>(bytes + 0x6c) = 2;
    *reinterpret_cast<float*>(bytes + 0x70) = 5.0f;
    *reinterpret_cast<float*>(bytes + 0x78) = 0.0f;
    *reinterpret_cast<unsigned*>(bytes + 0x7c) = 0;
    *reinterpret_cast<unsigned*>(bytes + 0x80) = 0;
    *reinterpret_cast<unsigned*>(bytes + 0x84) = 0;
    *reinterpret_cast<void**>(bytes + 0x90) = 0;
    return object;
}

// constructs the InteractiveObject base and initializes the recovered video extent fields
// @0x140010000
Scaleform::GFx::InteractiveObject* FUN_140010000(
    Scaleform::GFx::InteractiveObject* object, void* definition,
    Scaleform::GFx::MovieDefImpl* binding, Scaleform::GFx::ASMovieRootBase* root,
    Scaleform::GFx::InteractiveObject* parent, const Scaleform::GFx::ResourceId* resourceId)
{
    object->Scaleform::GFx::InteractiveObject::InteractiveObject(
        binding, root, parent, *resourceId);
    char* bytes = reinterpret_cast<char*>(object);
    *reinterpret_cast<void**>(bytes) = &PTR_FUN_1431b6060;
    *reinterpret_cast<void**>(bytes + 0x18) = &PTR_LAB_1431b63f8;
    // the bounds start at 0 and are then set from the definition's pixel size, in twips
    float* bounds = reinterpret_cast<float*>(bytes + 0xe0);
    bounds[0] = 0; bounds[1] = 0; bounds[2] = 0; bounds[3] = 0;
    *reinterpret_cast<void**>(bytes + 0xf0) = definition;
    *reinterpret_cast<void**>(bytes + 0xf8) = 0;
    *reinterpret_cast<void* volatile*>(bytes + 0x100) = 0;   // volatile: keeps the member read below after this store
    const unsigned char* dimensions = *reinterpret_cast<const unsigned char* volatile*>(bytes + 0xf0);   // volatile: the exe reads the member back
    float width = static_cast<float>(*reinterpret_cast<const unsigned*>(dimensions + 0x24));
    float height = static_cast<float>(*reinterpret_cast<const unsigned*>(dimensions + 0x28));
    float x2 = width * 20.0f, y2 = height * 20.0f;
    bounds[0] = 0;
    bounds[1] = 0;
    bounds[2] = x2;
    bounds[3] = y2;
    return object;
}

// the Connect prototype's constructor body; the exe inlines it into FUN_1400126f0.
static __forceinline Scaleform::GFx::AS2::Object* Video02ConnectProtoInit(
    Scaleform::GFx::AS2::Object* object, Scaleform::GFx::AS2::ASStringContext* context,
    void* prototype, const Scaleform::GFx::AS2::FunctionRef* constructor)
{
    FUN_140012440(object, context, prototype, constructor);
    *reinterpret_cast<void**>(object) = &PTR_FUN_1431b6640;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(object) + 0x20) = &PTR_LAB_1431b6690;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(object) + 0x68) = &PTR_LAB_1431b6638;
    Scaleform::GFx::AS2::PropFlags flags(1);
    reinterpret_cast<Video02PrototypeAccess*>(reinterpret_cast<char*>(object) + 0x68)->InitFunctionMembers(
        object, context, Video02ConnectFunctions, flags);
    return object;
}

// @0x140012510
Scaleform::GFx::AS2::Object* FUN_140012510(
    Scaleform::GFx::AS2::Object* object, Scaleform::GFx::AS2::ASStringContext* context,
    void* prototype, const Scaleform::GFx::AS2::FunctionRef* constructor)
{
    return Video02ConnectProtoInit(object, context, prototype, constructor);
}

// The exe builds the native function and prototype inline in both registration functions below.
namespace Scaleform { namespace GFx { namespace AS2 {
Value* FUN_142923b90(Value* pthis, const FunctionRef& func);
}}}
struct Video02ValueStorage
{
    Video02ValueStorage() {}
    std::uint64_t Raw0, Raw1, Raw2, Raw3;
};

// MS2-FUNCTIONAL: creates and registers the attachVideo native function and prototype (VideoCtorFunction::Register),
// written out in full so the temps share the rcx home slot like the exe. Left: our
// placement new tests result for null (the exe does not; without the test the result/prototype registers swap), the
// prototype vptr stores are scheduled differently, and global/manager sit in rbx/rsi.
// @0x14000ed60
Scaleform::GFx::AS2::FunctionRef* FUN_14000ed60(
    Scaleform::GFx::AS2::FunctionRef* result, Scaleform::GFx::AS2::GlobalContext* context)
{
    Scaleform::GFx::AS2::ASStringContext stringContext(context, 8);
    Scaleform::GFx::AS2::CFunctionObject* function = static_cast<Scaleform::GFx::AS2::CFunctionObject*>(context->pHeap->Alloc(0x70));
    if (function)
    {
        function->Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(&stringContext, Scaleform::GFx::AS2::VideoCtorFunction::GlobalCtor);
        *reinterpret_cast<void**>(function) = &PTR_LAB_1431b5f20;
        *reinterpret_cast<void**>(reinterpret_cast<char*>(function) + 0x20) = &PTR_LAB_1431b5fb0;
    }
    else
        function = 0;
    new (result) Scaleform::GFx::AS2::FunctionRef(*function);

    Scaleform::GFx::AS2::Object* prototype = static_cast<Scaleform::GFx::AS2::Object*>(context->pHeap->Alloc(0xb0));
    if (prototype)
    {
        Scaleform::GFx::AS2::FUN_14000e1e0(prototype, &stringContext,
            context->GetPrototype(Scaleform::GFx::AS2::ASBuiltin_Object), *result);
        *reinterpret_cast<void**>(prototype) = &PTR_FUN_1431b5e20;
        *reinterpret_cast<void**>(reinterpret_cast<char*>(prototype) + 0x20) = &PTR_LAB_1431b5e70;
        *reinterpret_cast<void**>(reinterpret_cast<char*>(prototype) + 0x70) = &PTR_LAB_1431b5e18;
        const Scaleform::GFx::AS2::PropFlags flags(1);
        reinterpret_cast<Video02PrototypeAccess*>(reinterpret_cast<char*>(prototype) + 0x70)->InitFunctionMembers(
            prototype, &stringContext, Video02VideoFunctions, flags);
        unsigned* count = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(prototype) + 0x18);
        *count = (*count + 1) & 0x8fffffff;
    }
    else
        prototype = 0;
    extern void FUN_14000c280(void*, unsigned, void**);
    {
        void* prototypeSlot = prototype;
        FUN_14000c280(context, 0x24, &prototypeSlot);
    }

    {
        Scaleform::GFx::AS2::Object* global = context->pGlobal;
        Scaleform::GFx::AS2::PropFlags flags;
        Scaleform::GFx::AS2::StringManager* manager = context->GetStringManager();
        const Scaleform::GFx::ASString& name = *reinterpret_cast<const Scaleform::GFx::ASString*>(
            reinterpret_cast<char*>(manager) + 0x120);
        // The exe builds and destroys the member value out of line (0x142923b90 / 0x1429260b0).
        Video02ValueStorage valueStorage;
        global->SetMemberRaw(&stringContext, name,
            *Scaleform::GFx::AS2::FUN_142923b90(reinterpret_cast<Scaleform::GFx::AS2::Value*>(&valueStorage), *result),
            flags);
        reinterpret_cast<Scaleform::GFx::AS2::Value*>(&valueStorage)->Scaleform::GFx::AS2::Value::~Value();
    }
    if (prototype)
    {
        unsigned* count = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(prototype) + 0x18);
        if ((*count & 0x03ffffffu) != 0)
        {
            --*count;
            reinterpret_cast<Scaleform::GFx::AS2::Video02GCAccess*>(prototype)->ReleaseInternal();
        }
    }
    return result;
}

// MS2-FUNCTIONAL: creates and registers the Connect native function and prototype, written out in full with the
// exe's in-place Init of the result. The PropFlags is a named local in a block, so it shares the prototypeSlot slot
// and is stored before the GetStringManager call, as in the exe. Left: global/manager sit in rbx/rsi (exe rsi/rbx).
// @0x1400126f0
Scaleform::GFx::AS2::FunctionRef* FUN_1400126f0(
    Scaleform::GFx::AS2::FunctionRef* result, Scaleform::GFx::AS2::GlobalContext* context)
{
    Scaleform::GFx::AS2::ASStringContext stringContext(context, 8);
    Scaleform::GFx::AS2::CFunctionObject* function = static_cast<Scaleform::GFx::AS2::CFunctionObject*>(context->pHeap->Alloc(0x70));
    if (function)
    {
        function->Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(&stringContext, FUN_140012340);
        *reinterpret_cast<void**>(function) = &PTR_LAB_1431b6740;
        *reinterpret_cast<void**>(reinterpret_cast<char*>(function) + 0x20) = &PTR_LAB_1431b67d0;
    }
    else
        function = 0;
    result->Init(*function);   // adopts the new function's reference

    Scaleform::GFx::AS2::Object* prototype = static_cast<Scaleform::GFx::AS2::Object*>(context->pHeap->Alloc(0xa8));
    if (prototype)
    {
        Video02ConnectProtoInit(prototype, &stringContext,
            context->GetPrototype(Scaleform::GFx::AS2::ASBuiltin_Object), result);
        unsigned* count = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(prototype) + 0x18);
        *count = (*count + 1) & 0x8fffffff;
    }
    else
        prototype = 0;
    extern void FUN_14000c280(void*, unsigned, void**);
    {
        void* prototypeSlot = prototype;
        FUN_14000c280(context, 0x22, &prototypeSlot);
    }

    {
        Scaleform::GFx::AS2::Object* global = context->pGlobal;
        Scaleform::GFx::AS2::PropFlags flags;
        Scaleform::GFx::AS2::StringManager* manager = context->GetStringManager();
        const Scaleform::GFx::ASString& name = *reinterpret_cast<const Scaleform::GFx::ASString*>(
            reinterpret_cast<char*>(manager) + 0x110);
        // The exe builds and destroys the member value out of line (0x142923b90 / 0x1429260b0).
        Video02ValueStorage valueStorage;
        global->SetMemberRaw(&stringContext, name,
            *Scaleform::GFx::AS2::FUN_142923b90(reinterpret_cast<Scaleform::GFx::AS2::Value*>(&valueStorage), *result),
            flags);
        reinterpret_cast<Scaleform::GFx::AS2::Value*>(&valueStorage)->Scaleform::GFx::AS2::Value::~Value();
    }
    if (prototype)
    {
        unsigned* count = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(prototype) + 0x18);
        if ((*count & 0x03ffffffu) != 0)
        {
            --*count;
            reinterpret_cast<Scaleform::GFx::AS2::Video02GCAccess*>(prototype)->ReleaseInternal();
        }
    }
    return result;
}

// Replaces the player event relay and its associated VideoPlayerImpl state object.
// @0x140015c40
void FUN_140015c40(void* object)
{
    // MS2: the movie root is [[object+0x20]+0x78] (exe 0x140015c54), and both Allocs pass a null AllocInfo
    void* vm = *reinterpret_cast<void**>(*reinterpret_cast<char**>(reinterpret_cast<char*>(object) + 0x20) + 0x78);
    void* manager = *reinterpret_cast<void**>(static_cast<char*>(vm) + 0x2d8);
    void* owner = *reinterpret_cast<void**>(static_cast<char*>(manager) + 0x10);
    void** ownerVtable = *reinterpret_cast<void***>(owner);
    void* heap = reinterpret_cast<void*(*)(void*)>(ownerVtable[0x178 / sizeof(void*)])(owner);
    void** heapVtable = *reinterpret_cast<void***>(heap);
    void* relay = reinterpret_cast<void*(*)(void*, size_t, void*)>(heapVtable[0x50 / sizeof(void*)])(
        heap, 0x18, 0);
    void* state = 0;
    if (relay)
    {
        *reinterpret_cast<unsigned*>(static_cast<char*>(relay) + 8) = 1;
        *reinterpret_cast<void**>(relay) = &PTR_FUN_1431b7858;
        *reinterpret_cast<void**>(static_cast<char*>(relay) + 0x10) = object;
    }
    else
        relay = state;
    void** oldRelay = reinterpret_cast<void**>(static_cast<char*>(object) + 0x58);
    if (*oldRelay)
        FUN_14257dcd0(*oldRelay);
    *oldRelay = relay;

    manager = *reinterpret_cast<void**>(static_cast<char*>(vm) + 0x2d8);
    owner = *reinterpret_cast<void**>(static_cast<char*>(manager) + 0x10);
    heap = reinterpret_cast<void*(*)(void*)>((*reinterpret_cast<void***>(owner))[0x178 / sizeof(void*)])(owner);
    void* memory = reinterpret_cast<void*(*)(void*, size_t, void*)>((*reinterpret_cast<void***>(heap))[0x50 / sizeof(void*)])(
        heap, 0x108, 0);
    if (memory)
    {
        state = ::new (memory) Scaleform::GFx::AS3::VideoProviderNetStream(
            static_cast<Scaleform::GFx::AS3::NetStreamInterface*>(*oldRelay));
    }
    void** oldState = reinterpret_cast<void**>(static_cast<char*>(object) + 0x50);
    if (*oldState)
        FUN_14257dcd0(*oldState);
    *oldState = state;
}

// @0x140014460
void FUN_140014460(void* object, void*, int hasValue, const Scaleform::GFx::AS3::Value* input)
{
    if (static_cast<unsigned>(hasValue) < 1)
        return;
    char* self = static_cast<char*>(object);
    Scaleform::GFx::AS3::Value text(*input);
    // MS2: exe 0x1400144be: the VM is [[this+0x20]+0x78], re-read for each use
    text.ToStringValue((*reinterpret_cast<Scaleform::GFx::AS3::VM**>(*reinterpret_cast<char**>(self + 0x20) + 0x78))->GetStringManager());
    // OpenUrl takes the url chars, read through a temp ASString (inc/dec of the node refcount at 0x1400144de)
    const char* url = text.AsString().ToCStr();
    Scaleform::GFx::AS3::ASVM& vm = *static_cast<Scaleform::GFx::AS3::ASVM*>(*reinterpret_cast<Scaleform::GFx::AS3::VM**>(*reinterpret_cast<char**>(self + 0x20) + 0x78));
    *reinterpret_cast<unsigned char*>(self + 0x60) = 0;
    static_cast<Scaleform::GFx::AS3::VideoProviderNetStream*>(*reinterpret_cast<void**>(self + 0x50))->OpenUrl(url, vm);
    ((::Scaleform::GFx::AS3::VideoProviderNetStream*)(*reinterpret_cast<void**>(self + 0x50)))->SetSoundVolume(static_cast<int>(*reinterpret_cast<double*>(self + 0x88) * 100.0),
        static_cast<int>(*reinterpret_cast<double*>(self + 0x90) * 100.0));
}

// interns the dynamic property name and invokes the executable trait setter.
// @0x140014900
void FUN_140014900(void* object, const unsigned long long* encodedName)
{
    // MS2: as exe 0x140014900: traits is the pointer at +0x10, vm is [traits+0x20]+0x78, the name is a
    // String DataDesc (size at +0, chars at +0xc) interned by the ASStringManager, and the result is a whole Value.
    // traits and vm are reread through the object at each use, as in the exe
#define VIDEO_TRAITS (*reinterpret_cast<char**>(static_cast<char*>(object) + 0x10))
#define VIDEO_VM (*reinterpret_cast<Scaleform::GFx::AS3::VM**>(*reinterpret_cast<char**>(VIDEO_TRAITS + 0x20) + 0x78))
    if (reinterpret_cast<const Scaleform::GFx::AS3::Value*>(VIDEO_TRAITS + 0xd8)->IsNullOrUndefined())
        return;
    Scaleform::GFx::AS3::Value result;
    const char* desc = reinterpret_cast<const char*>(*encodedName & ~3ull);
    Scaleform::GFx::ASStringManager* strings = *reinterpret_cast<Scaleform::GFx::ASStringManager**>(
        *reinterpret_cast<char**>(reinterpret_cast<char*>(VIDEO_VM) + 0x10) + 0x1e8);
    Scaleform::GFx::AS3::Value propertyName(Scaleform::GFx::ASString(strings->CreateStringNode(desc + 0xc,
        *reinterpret_cast<const unsigned long long*>(desc) & 0x7fffffffffffffffull)));
    {
        Scaleform::GFx::AS3::VM& vm = *VIDEO_VM;
        const Scaleform::GFx::AS3::Value& undefinedValue = Scaleform::GFx::AS3::Value::GetUndefined();
        vm.ExecuteInternalUnsafe(*reinterpret_cast<const Scaleform::GFx::AS3::Value*>(VIDEO_TRAITS + 0xd8),
            undefinedValue, result, 1, &propertyName, false);
    }
    if (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(VIDEO_VM) + 0x180) != 0)
        VIDEO_VM->OutputAndIgnoreException();
#undef VIDEO_VM
#undef VIDEO_TRAITS
}

// Shared path for the generated AS3 trait getters in this range.
// ThunkDefault<R> of as3_marshalling.h for the result types used here.
template <typename R> struct Video02ThunkDefault;
template <> struct Video02ThunkDefault<bool> { static bool Get() { return false; } };
template <> struct Video02ThunkDefault<Scaleform::UInt32> { static Scaleform::UInt32 Get() { return 0; } };
template <> struct Video02ThunkDefault<double>
{
    static double Get() { return Scaleform::GFx::NumberUtil::NaN(); }
};

// ThunkArgs0<R> of as3_marshalling.h: the result starts at its default and the destructor stores it unless the
// call raised an exception.
// BEHAVIOUR FIX: the Number getters start from NaN, as the exe does (they used to start from 0), and the result is
// not stored when the getter raised.
template <typename R>
struct Video02ThunkResult
{
    Video02ThunkResult(Scaleform::GFx::AS3::VM& vm, Scaleform::GFx::AS3::Value& result)
        : vm(vm), result(result), r(Video02ThunkDefault<R>::Get()) {}
    ~Video02ThunkResult() { if (!vm.IsException()) result.AssignUnsafe(r); }

    Scaleform::GFx::AS3::VM&    vm;
    Scaleform::GFx::AS3::Value& result;
    R                           r;
};

// ThunkFunc0<T, N, R>::Func: calls the getter through its method pointer (code at `method`, this adjustment in the
// int at `adjust`) on the object in the this value.
template <typename R>
static __forceinline void Video02TraitGet(void* instance, void* traits, unsigned* output, void*& method, void*& adjust)
{
    char* self = *reinterpret_cast<char**>(static_cast<char*>(traits) + 0x10);   // the this value's object
    Video02ThunkResult<R> args(*static_cast<Scaleform::GFx::AS3::VM*>(instance),
                               *reinterpret_cast<Scaleform::GFx::AS3::Value*>(output));
    reinterpret_cast<void (*)(char*, R*)>(method)(self + *reinterpret_cast<int*>(&adjust), &args.r);
}

// ThunkArgs1<const Value, A0> argument conversion: the out-of-line Value converters, as the exe calls them.
static __forceinline void Video02ThunkConvert(const Scaleform::GFx::AS3::Value& from, double& to)
{
    from.Convert2Number(to);
}
static __forceinline void Video02ThunkConvert(const Scaleform::GFx::AS3::Value& from, bool& to)
{
    to = from.Convert2Boolean();
}

// ThunkArgs1<const Value, A0>: the argument starts at its default and is converted from argv[0] when given.
template <typename A0>
struct Video02ThunkArgs1
{
    Video02ThunkArgs1(Scaleform::GFx::AS3::VM& vm, Scaleform::GFx::AS3::Value& result, unsigned argc,
                      const Scaleform::GFx::AS3::Value* argv, const A0& defaultValue0)
        : vm(vm), r(result), a0(defaultValue0)
    {
        if (argc > 0)
            Video02ThunkConvert(argv[0], a0);
    }

    Scaleform::GFx::AS3::VM&    vm;
    Scaleform::GFx::AS3::Value& r;
    A0                          a0;
};

// ThunkFunc1<T, N, const Value, A0>::Func: calls the setter through its method pointer (code at `method`, this
// adjustment in the int at `adjust`) unless the argument conversion raised an exception.
// BEHAVIOUR FIX: the exception check comes after the conversion, as in the exe. It used to come before it, so the
// setter still ran with a default argument when Convert2Number/Convert2Boolean raised.
template <typename A0>
static __forceinline void Video02TraitSet(void* instance, void* traits, void* context, int hasValue,
                                          Scaleform::GFx::AS3::Value* value, void*& method, void*& adjust)
{
    char* self = *reinterpret_cast<char**>(static_cast<char*>(traits) + 0x10);   // the this value's object
    Scaleform::GFx::AS3::VM& vm = *static_cast<Scaleform::GFx::AS3::VM*>(instance);
    Video02ThunkArgs1<A0> args(vm, *static_cast<Scaleform::GFx::AS3::Value*>(context), hasValue, value,
                                Video02ThunkDefault<A0>::Get());
    if (vm.IsException())
        return;
    reinterpret_cast<void (*)(char*, void*, A0)>(method)(self + *reinterpret_cast<int*>(&adjust), &args.r, args.a0);
}

// @0x140015d20
void FUN_140015d20(void*, void* instance, void* traits, unsigned* output)
{
    Video02TraitGet<double>(instance, traits, output, DAT_143b274d8, DAT_143b274e0);
}

// @0x140015da0
void FUN_140015da0(void*, void* instance, void* traits, unsigned* output)
{
    Video02TraitGet<double>(instance, traits, output, DAT_143b27518, DAT_143b27520);
}

// @0x140015eb0
void FUN_140015eb0(void*, void* instance, void* traits, unsigned* output)
{
    Video02TraitGet<Scaleform::UInt32>(instance, traits, output, DAT_143b27698, DAT_143b276a0);
}

// @0x140015f20
void FUN_140015f20(void*, void* instance, void* traits, unsigned* output)
{
    Video02TraitGet<Scaleform::UInt32>(instance, traits, output, DAT_143b27458, DAT_143b27460);
}

// @0x140015f90
void FUN_140015f90(void*, void* instance, void* traits, unsigned* output)
{
    Video02TraitGet<bool>(instance, traits, output, DAT_143b27478, DAT_143b27480);
}

// @0x140016100
void FUN_140016100(void*, void* instance, void* traits, unsigned* output)
{
    Video02TraitGet<double>(instance, traits, output, DAT_143b274f8, DAT_143b27500);
}

// @0x140016180
void FUN_140016180(void*, void* instance, void* traits, unsigned* output)
{
    Video02TraitGet<double>(instance, traits, output, DAT_143b27448, DAT_143b27450);
}

// @0x140016200
void FUN_140016200(void*, void* instance, void* traits, unsigned* output)
{
    Video02TraitGet<Scaleform::UInt32>(instance, traits, output, DAT_143b274c8, DAT_143b274d0);
}

// @0x140016270
void FUN_140016270(void*, void* instance, void* traits, unsigned* output)
{
    Video02TraitGet<double>(instance, traits, output, DAT_143b274b8, DAT_143b274c0);
}

// @0x140016530
void FUN_140016530(void*, void* instance, void* traits, unsigned* output)
{
    Video02TraitGet<bool>(instance, traits, output, DAT_143b276e8, DAT_143b276f0);
}

// @0x140016600
void FUN_140016600(void*, void* instance, void* traits, unsigned* output)
{
    Video02TraitGet<double>(instance, traits, output, DAT_143b27578, DAT_143b27580);
}

// @0x140016680
void FUN_140016680(void*, void* instance, void* traits, unsigned* output)
{
    Video02TraitGet<double>(instance, traits, output, DAT_143b27568, DAT_143b27570);
}

// @0x140016790
void FUN_140016790(void*, void* instance, void* traits, unsigned* output)
{
    Video02TraitGet<double>(instance, traits, output, DAT_143b27468, DAT_143b27470);
}

// @0x1400168a0
void FUN_1400168a0(void*, void* instance, void* traits, unsigned* output)
{
    Video02TraitGet<double>(instance, traits, output, DAT_143b27508, DAT_143b27510);
}

// @0x1400169b0
void FUN_1400169b0(void*, void* instance, void* traits, unsigned* output)
{
    Video02TraitGet<double>(instance, traits, output, DAT_143b274e8, DAT_143b274f0);
}

// Converts the optional trait value and forwards it to the executable setter.
// @0x140015e20
void FUN_140015e20(void*, void* instance, void* traits, void* context, int hasValue,
                  Scaleform::GFx::AS3::Value* value)
{
    Video02TraitSet<double>(instance, traits, context, hasValue, value, DAT_143b276a8, DAT_143b276b0);
}

// @0x140016000
void FUN_140016000(void*, void* instance, void* traits, void* context, int hasValue,
                  Scaleform::GFx::AS3::Value* value)
{
    Video02TraitSet<bool>(instance, traits, context, hasValue, value, DAT_143b276c8, DAT_143b276d0);
}

// @0x1400162f0
void FUN_1400162f0(void*, void* instance, void* traits, void* context, int hasValue,
                  Scaleform::GFx::AS3::Value* value)
{
    Video02TraitSet<bool>(instance, traits, context, hasValue, value, DAT_143b27628, DAT_143b27630);
}

// @0x140016350
void FUN_140016350(void*, void* instance, void* traits, void* context, int hasValue,
                  Scaleform::GFx::AS3::Value* value)
{
    Video02TraitSet<bool>(instance, traits, context, hasValue, value, DAT_143b27648, DAT_143b27650);
}

// @0x1400163b0
void FUN_1400163b0(void*, void* instance, void* traits, void* context, int hasValue,
                  Scaleform::GFx::AS3::Value* value)
{
    Video02TraitSet<bool>(instance, traits, context, hasValue, value, DAT_143b27538, DAT_143b27540);
}

// Converts the optional trait value and forwards it to the executable setter.
// @0x140016410
void FUN_140016410(void*, void* instance, void* traits, void* context, int hasValue,
                  Scaleform::GFx::AS3::Value* value)
{
    Video02TraitSet<double>(instance, traits, context, hasValue, value, DAT_143b27618, DAT_143b27620);
}

// Converts the optional trait value and forwards it to the executable setter.
// @0x1400164a0
void FUN_1400164a0(void*, void* instance, void* traits, void* context, int hasValue,
                  Scaleform::GFx::AS3::Value* value)
{
    Video02TraitSet<double>(instance, traits, context, hasValue, value, DAT_143b27688, DAT_143b27690);
}

// @0x1400165a0
void FUN_1400165a0(void*, void* instance, void* traits, void* context, int hasValue,
                  Scaleform::GFx::AS3::Value* value)
{
    Video02TraitSet<bool>(instance, traits, context, hasValue, value, DAT_143b276b8, DAT_143b276c0);
}

// Converts the optional trait value and forwards it to the executable setter.
// @0x140016700
void FUN_140016700(void*, void* instance, void* traits, void* context, int hasValue,
                  Scaleform::GFx::AS3::Value* value)
{
    Video02TraitSet<double>(instance, traits, context, hasValue, value, DAT_143b275c8, DAT_143b275d0);
}

// Converts the optional trait value and forwards it to the executable setter.
// @0x140016810
void FUN_140016810(void*, void* instance, void* traits, void* context, int hasValue,
                  Scaleform::GFx::AS3::Value* value)
{
    Video02TraitSet<double>(instance, traits, context, hasValue, value, DAT_143b275a8, DAT_143b275b0);
}

// Converts the optional trait value and forwards it to the executable setter.
// @0x140016920
void FUN_140016920(void*, void* instance, void* traits, void* context, int hasValue,
                  Scaleform::GFx::AS3::Value* value)
{
    Video02TraitSet<double>(instance, traits, context, hasValue, value, DAT_143b27658, DAT_143b27660);
}

// Converts the optional trait value and forwards it to the executable setter.
// @0x140016a30
void FUN_140016a30(void*, void* instance, void* traits, void* context, int hasValue,
                  Scaleform::GFx::AS3::Value* value)
{
    Video02TraitSet<double>(instance, traits, context, hasValue, value, DAT_143b27438, DAT_143b27440);
}

// Stores either the supplied AS3 Value or an undefined Value in the active trait slot.
// @0x140016060
void FUN_140016060(void*, void* instance, void* traits, void* context, int hasValue,
                   Scaleform::GFx::AS3::Value* value)
{
    typedef Scaleform::GFx::AS3::Value Value;
    intptr_t offset = *reinterpret_cast<intptr_t*>(reinterpret_cast<char*>(traits) + 0x10);
    Video02ValueStorage storage;
    const Value* undefinedValue = reinterpret_cast<Value* (*)(void*, void*)>(FUN_1400158e0)(
        &storage, *reinterpret_cast<void**>(reinterpret_cast<char*>(instance) + 0x10));
    const Value* stored = static_cast<unsigned>(hasValue) > 0 ? value : undefinedValue;
    reinterpret_cast<Value*>(&storage)->~Value();
    if (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(instance) + 0x180) != 0)
        return;
    reinterpret_cast<void(*)(char*, void*, const Value*)>(DAT_143b27678)(
        *reinterpret_cast<int*>(&DAT_143b27680) + reinterpret_cast<char*>(offset), context, stored);
}

// Converts the optional trait value and forwards it to the executable setter.
// @0x140016ac0
void FUN_140016ac0(void*, void* instance, void* traits, void* context, int hasValue,
                  Scaleform::GFx::AS3::Value* value)
{
    Video02TraitSet<double>(instance, traits, context, hasValue, value, DAT_143b275b8, DAT_143b275c0);
}

// (0x140011b40 is ~Prototype<NetConnection>, emitted by Video02EmitNetConnectionVftables)

// (0x140011c00 is Prototype<NetConnection>'s ??_G, emitted by Video02EmitNetConnectionVftables)

// destroys the GASPrototypeBase subobject, releases its retained object, then destroys Object. The exe's inline
// Prototype<VideoObject> dtor stores its three vftables (+0, +0x20, +0x70) first.
// @0x14000ebe0
void FUN_14000ebe0(Scaleform::GFx::AS2::Object* object)
{
    // the real dtor (non-virtual, as the exe: a virtual call from the deleting dtor recurses)
    static_cast<Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::VideoObject>*>(object)
        ->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::VideoObject>::~Prototype();
}

// (0x14000ec40, the scalar deleting form of the above, is cl's ??_G of the VideoProto model at the end of this file)

// @0x1400113a0
unsigned FUN_1400113a0(void* array, const unsigned* source)
{
    char* bytes = static_cast<char*>(array);
    unsigned __int64 length = *reinterpret_cast<unsigned __int64*>(bytes + 0x20);
    Video02ResizeFills(bytes + 0x18, bytes + 0x18, length + 1);
    // the new last entry, at the resized count; the exe returns that count
    unsigned __int64 size = *reinterpret_cast<unsigned __int64*>(bytes + 0x20);
    char* item = *reinterpret_cast<char**>(bytes + 0x18) + size * 0x10 - 0x10;
    if (item)   // the exe's placement copy construction of the entry
    {
        *reinterpret_cast<unsigned*>(item) = *source;
        void* value = *reinterpret_cast<void* const*>(source + 2);
        if (value) FUN_14257dc30(value);
        *reinterpret_cast<void**>(item + 8) = *reinterpret_cast<void* const*>(source + 2);
    }
    return static_cast<unsigned>(*reinterpret_cast<unsigned __int64*>(bytes + 0x20));
}

// Appends a copied reference entry in the nested +0x88 collection.
// @0x140011450
unsigned FUN_140011450(void* object, const unsigned* source)
{
    char* outer = static_cast<char*>(*reinterpret_cast<void**>(static_cast<char*>(object) + 0x88));
    Video02ResizeFills(outer + 0x18, outer + 0x18, *reinterpret_cast<unsigned __int64*>(outer + 0x20) + 1);
    // the new last entry, at the resized count; the exe returns that count
    char* item = *reinterpret_cast<char**>(outer + 0x18) + *reinterpret_cast<unsigned __int64*>(outer + 0x20) * 0x10 - 0x10;
    if (item)   // the exe's placement copy construction of the entry
    {
        *reinterpret_cast<unsigned*>(item) = *source;
        void* value = *reinterpret_cast<void* const*>(source + 2);
        if (value) FUN_14257dc30(value);
        *reinterpret_cast<void**>(item + 8) = *reinterpret_cast<void* const*>(source + 2);
    }
    return static_cast<unsigned>(*reinterpret_cast<unsigned __int64*>(outer + 0x20));
}

// Frees the old page and allocates the grown one (the SDK PagedItemBuffer::allocPage).
// @0x140010cd0
void FUN_140010cd0(void** buffer, unsigned __int64 requested)
{
    // SDK PagedItemBuffer::allocPage (Render_Containers.h)
    using Scaleform::UByte; using Scaleform::UPInt;
    struct PageType { UByte* pStart; UByte* pEnd; UByte* pFree; };
    struct Heap { Scaleform::MemoryHeap* pHeap; UPInt Granularity; void* pPagePool; PageType* pLastPage; };
    Heap* h = reinterpret_cast<Heap*>(buffer);
    UPInt size = requested;
    if (h->pLastPage->pStart)
        h->pHeap->Free(h->pLastPage->pStart);

    size = (size + h->Granularity - 1) / h->Granularity * h->Granularity;

    h->pLastPage->pStart = h->pLastPage->pFree = (UByte*)h->pHeap->Alloc(size);
    h->pLastPage->pEnd   = h->pLastPage->pStart + size;
}

// (0x1400125a0 is ~NetConnectionProto (implicit; it inlines ~Prototype<NetConnection>), emitted by Video02EmitNetConnectionVftables)

// (0x1400125e0 is NetConnectionProto's ??_G, emitted by Video02EmitNetConnectionVftables)

// (0x1400126b0 is NetConnectionCtorFunction's ??_G, emitted by Video02EmitNetConnectionCtorVftables)

// RemoveFromList, inlined twice into FUN_1400152b0.
static __forceinline void Video02UnlinkTracked(unsigned __int64* object)
{
    unsigned* words = reinterpret_cast<unsigned*>(object);
    *reinterpret_cast<unsigned __int64*>(object[3] + 8) = object[1];
    *reinterpret_cast<unsigned __int64*>(object[1] + 0x18) = object[3];
    words[4] &= 0x7effffff;
    object[1] = 0;
    if ((static_cast<unsigned char>(words[4] >> 24) & 1) == 0)
        reinterpret_cast<unsigned*>(object + 3)[0] = 0xffffffff;
}

// Unlinks a tracked GC object (ReleaseInternal's root/list branches: RemoveFromList on both InList paths, RemoveRoot
// when only in the root list) and deletes it through its vtable.
// @0x1400152b0
void FUN_1400152b0(unsigned __int64* object)
{
    enum { GcStat = Scaleform::GFx::AS3::StatMV_ActionScript_Mem };
    unsigned* words = reinterpret_cast<unsigned*>(object);
    words[4] &= 0x8fffffff;
    if (!(static_cast<unsigned char>(words[4] >> 31) & 1)) {
        if (static_cast<unsigned char>(words[4] >> 24) & 1)
            Video02UnlinkTracked(object);
    } else if (!(static_cast<unsigned char>(words[4] >> 24) & 1)) {
        reinterpret_cast<Scaleform::GFx::AS3::RefCountCollector<GcStat>*>(object[1])->RemoveRoot(
            reinterpret_cast<const Scaleform::GFx::AS3::RefCountBaseGC<GcStat>*>(object));
    } else {
        Video02UnlinkTracked(object);
    }
    (*reinterpret_cast<void (***)(void*, int)>(object))[4](object, 1);
}

// @0x140010ed0
Scaleform::Render::TreeNode::NodeData* FUN_140010ed0(
    Scaleform::Render::TreeNode::NodeData* destination,
    const Scaleform::Render::TreeNode::NodeData* source)
{
    destination->operator=(*source);
    return destination;
}

namespace Scaleform { namespace Render {
// the ContextImpl::ContextData_ImplMixin<TreeShape::NodeData, TreeNode::NodeData> vftable (0x14317bbf0)
extern const void* const TreeShapeNodeDataMixinVTable[];
} }

// ContextData_ImplMixin<TreeShape::NodeData, TreeNode::NodeData>(EntryType): the base NodeData(type) ctor, then the
// mixin vftable
// @0x140010ca0
Scaleform::Render::TreeNode::NodeData* FUN_140010ca0(
    Scaleform::Render::TreeNode::NodeData* destination,
    Scaleform::Render::TreeNode::NodeData::EntryType type)
{
    destination->Scaleform::Render::TreeNode::NodeData::NodeData(type);
    destination->pVTable = Scaleform::Render::TreeShapeNodeDataMixinVTable;
    return destination;
}

// BEHAVIOUR FIX: this is the mixin's copy constructor. The exe passes the source node data through to the
// NodeData copy ctor (0x1424d9220); ours ignored it and default-constructed an ET_Base node, so every copy lost the
// source's fields. It also stores the mixin vftable as the exe does.
// @0x140010fe0
Scaleform::Render::TreeNode::NodeData* FUN_140010fe0(
    Scaleform::Render::TreeNode::NodeData* destination, const Scaleform::Render::TreeNode::NodeData* source)
{
    destination->Scaleform::Render::TreeNode::NodeData::NodeData(*source);
    destination->pVTable = Scaleform::Render::TreeShapeNodeDataMixinVTable;
    return destination;
}

// @0x140010ef0
Scaleform::Render::TreeShape::NodeData* FUN_140010ef0(
    Scaleform::Render::TreeShape::NodeData* destination,
    const Scaleform::Render::TreeShape::NodeData* source)
{
    destination->Scaleform::Render::TreeNode::NodeData::operator=(
        *static_cast<const Scaleform::Render::TreeNode::NodeData*>(source));
    void* incoming = *reinterpret_cast<void* const*>(reinterpret_cast<const unsigned char*>(source) + 0x90);
    if (incoming) {
        void* refBase = static_cast<unsigned char*>(incoming) + 0x10;
        void (*addRef)(void*) = reinterpret_cast<void (*)(void*)>(
            *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(*reinterpret_cast<void***>(refBase)) + 8));
        addRef(refBase);
    }
    void* current = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(destination) + 0x90);
    if (current) {
        void* refBase = static_cast<unsigned char*>(current) + 0x10;
        void (*release)(void*) = reinterpret_cast<void (*)(void*)>(
            *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(*reinterpret_cast<void***>(refBase)) + 0x10));
        release(refBase);
    }
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(destination) + 0x90) =
        *reinterpret_cast<void* const*>(reinterpret_cast<const unsigned char*>(source) + 0x90);
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(destination) + 0x98) =
        *reinterpret_cast<const float*>(reinterpret_cast<const unsigned char*>(source) + 0x98);
    return destination;
}

// @0x140011170
Scaleform::Render::TreeShape::NodeData* FUN_140011170(
    Scaleform::Render::TreeShape::NodeData* destination,
    const Scaleform::Render::TreeShape::NodeData* source)
{
    // The exe copy-constructs the base snapshot (0x1424d9220), then stores the TreeShape vftable.
    destination->Scaleform::Render::TreeNode::NodeData::NodeData(
        *static_cast<const Scaleform::Render::TreeNode::NodeData*>(source));   // in place, no null check
    destination->pVTable = Scaleform::Render::TreeShapeNodeDataVTable;
    void* provider = *reinterpret_cast<void* const*>(reinterpret_cast<const unsigned char*>(source) + 0x90);
    if (provider) {
        void* refBase = static_cast<unsigned char*>(provider) + 0x10;
        void (*addRef)(void*) = reinterpret_cast<void (*)(void*)>(
            *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(*reinterpret_cast<void***>(refBase)) + 8));
        addRef(refBase);
    }
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(destination) + 0x90) =
        *reinterpret_cast<void* const*>(reinterpret_cast<const unsigned char*>(source) + 0x90);
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(destination) + 0x98) =
        *reinterpret_cast<const float*>(reinterpret_cast<const unsigned char*>(source) + 0x98);
    return destination;
}

// @0x140011330
Scaleform::Render::TreeShape::NodeData* FUN_140011330(
    Scaleform::Render::TreeShape::NodeData* destination,
    const Scaleform::Render::TreeShape::NodeData* source)
{
    return destination ? FUN_140011170(destination, source) : 0;
}

// @0x140011010
Scaleform::Render::TreeShape::NodeData* FUN_140011010(
    Scaleform::Render::TreeShape::NodeData* destination, void* provider)
{
    // The exe runs the base NodeData(ET_Shape) ctor (0x1424d9310) in place, no null check, then stores the TreeShape
    // vftable, then the provider and morph ratio.
    destination->Scaleform::Render::TreeNode::NodeData::NodeData(Scaleform::Render::ContextImpl::EntryData::ET_Shape);
    destination->pVTable = Scaleform::Render::TreeShapeNodeDataVTable;
    typedef Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> ProviderPtr;
    reinterpret_cast<ProviderPtr*>(reinterpret_cast<unsigned char*>(destination) + 0x90)->ProviderPtr::Ptr(
        static_cast<Scaleform::Render::ShapeMeshProvider*>(provider));
    *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(destination) + 0x98) = 0.0f;
    return destination;
}

// @0x1400111d0
Scaleform::Render::TreeShape::NodeData* FUN_1400111d0(
    Scaleform::Render::TreeShape::NodeData* destination, const void* const* providerRef)
{
    return destination ? FUN_140011010(destination, const_cast<void*>(*providerRef)) : 0;
}

// Releases the shape provider, then the base node's state bag, then the out-of-line EntryData dtor (as in 14000f1a0).
// @0x140011070
void FUN_140011070(Scaleform::Render::TreeShape::NodeData* node)
{
    typedef Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> ProviderPtr;
    node->pVTable = Scaleform::Render::TreeShapeNodeDataVTable;
    reinterpret_cast<ProviderPtr*>(reinterpret_cast<unsigned char*>(node) + 0x90)->~ProviderPtr();
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(node) + 0x40))
        static_cast<Scaleform::Render::Video02StateDataAccess*>(static_cast<void*>(reinterpret_cast<char*>(node) + 0x40))->destroyBag_NotEmpty();
    FUN_14257eb30(node);
}

// @0x1400112a0
void FUN_1400112a0(
    Scaleform::Render::Context* context, const void* const* providerRef)
{
    // Context::CreateEntry<TreeShape>(provider), with the NodeData(provider) ctor inlined
    Scaleform::Render::TreeShape::NodeData* data = static_cast<Scaleform::Render::TreeShape::NodeData*>(
        (*reinterpret_cast<Scaleform::MemoryHeap**>(context))->Alloc(0xa0));
    if (data)
        FUN_140011010(data, const_cast<void*>(*providerRef));
    Scaleform::Render::Video02CreateEntry(context, data);
}

// MS2-FUNCTIONAL: recreates the video render node after its provider changes, retaining the parent slot and transform.
// Written out as the SDK body (Ptr<TreeNode> slot at +0x48, memcpy matrix copies, virtual CreateRenderNode). As in the
// exe, the transform is kept only when the old node has a parent (else identity), and the child index is the search
// position. Remaining diffs are VC9 scheduling: the exe loads the creator's vtable right before the call (ours early
// into r9), computes the visible flag after reloading the slot, and orders the entry zeroing and setne differently.
// slot 1 of the video character: builds its render node (returned as a Ptr through the hidden result slot)
struct Video02NodeCreator
{
    virtual void Slot0();
    virtual Scaleform::Ptr<Scaleform::Render::TreeNode> CreateRenderNode(void* context);
};
#pragma function(memcpy)   // the matrix copies call memcpy out of line in the exe
// TreeNode::GetViewMatrix3D / GetProjectionMatrix3D (render_treenode.h); the gfx_rendertree.h view lacks them.
static __forceinline bool Video02GetViewMatrix3D(const Scaleform::Render::TreeNode* node, Scaleform::Render::Matrix3F* m)
{
    const Scaleform::Render::State* state = node->GetState(static_cast<Scaleform::Render::StateType>(5));
    if (!state)
        return false;
    const unsigned char* data = *reinterpret_cast<const unsigned char* const*>(reinterpret_cast<const unsigned char*>(state) + 8);
    *m = Scaleform::Render::Matrix3F(reinterpret_cast<const float (*)[4]>(data + 0x10));
    return true;
}
static __forceinline bool Video02GetProjectionMatrix3D(const Scaleform::Render::TreeNode* node, Scaleform::Render::Matrix4F* m)
{
    const Scaleform::Render::State* state = node->GetState(static_cast<Scaleform::Render::StateType>(6));
    if (!state)
        return false;
    const unsigned char* data = *reinterpret_cast<const unsigned char* const*>(reinterpret_cast<const unsigned char*>(state) + 8);
    *m = Scaleform::Render::Matrix4F(reinterpret_cast<const float (*)[4]>(data + 0x10));
    return true;
}
// @0x1400105b0
void* FUN_1400105b0(void* object)
{
    using namespace Scaleform::Render;
    unsigned char* bytes = static_cast<unsigned char*>(object);
    Scaleform::Ptr<TreeNode>& pnode = *reinterpret_cast<Scaleform::Ptr<TreeNode>*>(bytes + 0x48);
    const bool hadNode = pnode.GetPtr() != 0;
    TreeContainer* parent = 0;
    Scaleform::UPInt childIndex = ~0u;   // SF_MAX_UINT
    Matrix2F matrix2;
    bool is3D = false;
    Matrix3F matrix3;
    bool hasView = false;
    Matrix3F view;
    bool hasProjection = false;
    Matrix4F projection;
    TreeNode* oldNode = pnode;
    if (oldNode && oldNode->GetParent()) {
        parent = static_cast<TreeContainer*>(oldNode->GetParent());
        const Scaleform::UPInt count = parent->GetSize();
        for (childIndex = 0; childIndex < count; ++childIndex)
            if (parent->GetAt(childIndex) == oldNode) break;
        is3D = oldNode->Is3D();
        if (is3D) {
            matrix3 = oldNode->M3D();
            hasView = Video02GetViewMatrix3D(oldNode, &view);
            hasProjection = Video02GetProjectionMatrix3D(pnode, &projection);
        }
        else matrix2 = oldNode->M2D();
        parent->Remove(childIndex, 1);
    }
    pnode = 0;
    if (hadNode) {
        if (!reinterpret_cast<void* const*>(object)[9]) {
            const uintptr_t contextBase = *reinterpret_cast<uintptr_t*>(bytes + 0x20);
            pnode = static_cast<Video02NodeCreator*>(object)->CreateRenderNode(
                reinterpret_cast<void*>(*reinterpret_cast<uintptr_t*>(contextBase + 0x10) + 0x34f0));
            pnode->SetVisible((*reinterpret_cast<unsigned short*>(bytes + 0x6a) & 0x4000) != 0);
            if (is3D) {
                pnode->SetMatrix3D(matrix3);
                if (hasView) pnode->SetViewMatrix3D(view);
                if (hasProjection) pnode->SetProjectionMatrix3D(projection);
            }
            else pnode->SetMatrix(matrix2);
        }
        if (parent) parent->Insert(childIndex, pnode);
    }
    return pnode;
}
#pragma intrinsic(memcpy)

// ShapeDataFloatTempl::ClosePath inlined on the reloaded pData (the exe inlines it here, FUN_140011410 is its copy)
static __forceinline void Video02ClosePath(void* path)
{
    unsigned char* bytes = static_cast<unsigned char*>(path);
    if (*reinterpret_cast<float*>(bytes + 0x5c) != *reinterpret_cast<float*>(bytes + 0x54) ||
        *reinterpret_cast<float*>(bytes + 0x60) != *reinterpret_cast<float*>(bytes + 0x58))
        Video02LineTo(path, *reinterpret_cast<float*>(bytes + 0x54), *reinterpret_cast<float*>(bytes + 0x58));
}

namespace {
struct AS2ObjectGCTraversal : Scaleform::GFx::AS2::Object
{
    typedef Scaleform::GFx::AS2::ASRefCountBaseType::Collector Collector;
    typedef Scaleform::GFx::AS2::ASRefCountBaseType::ReleaseFunctor ReleaseFunctor;
    typedef Scaleform::GFx::AS2::ASRefCountBaseType::MarkInCycleFunctor MarkInCycleFunctor;
    typedef Scaleform::GFx::AS2::ASRefCountBaseType::ScanInUseFunctor ScanInUseFunctor;
    template<class Functor> static void Run(const Scaleform::GFx::AS2::Object* object, Collector* collector)
    {
        reinterpret_cast<const AS2ObjectGCTraversal*>(object)->template ForEachChild_GC<Functor>(collector);
    }
};

struct AS2PrototypeGCTraversal : Scaleform::GFx::AS2::GASPrototypeBase
{
    typedef Scaleform::GFx::AS2::ASRefCountBaseType::Collector Collector;
    template<class Functor> static __forceinline void Run(const AS2PrototypeGCTraversal* self, Collector* collector)
    {
        self->Constructor.template ForEachChild_GC<Functor>(collector);
        self->__Constructor__.template ForEachChild_GC<Functor>(collector);
        if (self->pInterfaces) {
            for (Scaleform::UPInt i = 0, count = self->pInterfaces->GetSize(); i < count; ++i) {
                const Scaleform::Ptr<Scaleform::GFx::AS2::Object>& pinterface = (*self->pInterfaces)[i];
                if (pinterface) Functor::Call(collector, pinterface);
            }
        }
    }
};

template<class Functor>
__forceinline void VisitAS2PrototypeChildren(Scaleform::GFx::AS2::Object* object,
                               Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector)
{
    AS2ObjectGCTraversal::Run<Functor>(object, collector);
    const AS2PrototypeGCTraversal* proto = reinterpret_cast<const AS2PrototypeGCTraversal*>(
        reinterpret_cast<const unsigned char*>(object) + 0x68);
    AS2PrototypeGCTraversal::Run<Functor>(proto, collector);
}
}

// @0x140011ef0
void FUN_140011ef0(Scaleform::GFx::AS2::Object* object,
                   Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector)
{
    VisitAS2PrototypeChildren<AS2ObjectGCTraversal::MarkInCycleFunctor>(object, collector);
}

// @0x140011fc0
void FUN_140011fc0(Scaleform::GFx::AS2::Object* object,
                   Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector)
{
    VisitAS2PrototypeChildren<AS2ObjectGCTraversal::ScanInUseFunctor>(object, collector);
}

// @0x1400120a0
void FUN_1400120a0(Scaleform::GFx::AS2::Object* object,
                   Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector)
{
    VisitAS2PrototypeChildren<AS2ObjectGCTraversal::ReleaseFunctor>(object, collector);
}

// dispatches a collector pass to the matching prototype child traversal
// @0x1400122a0
void FUN_1400122a0(Scaleform::GFx::AS2::Object* object,
                   Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector, int operation)
{
    switch (operation)
    {
    case 0: FUN_1400120a0(object, collector); break;
    case 1: FUN_140011ef0(object, collector); break;
    case 2: FUN_140011fc0(object, collector); break;
    }
}

// dispatches a collector pass to the matching prototype child traversal
// @0x140012400
void FUN_140012400(Scaleform::GFx::AS2::Object* object,
                   Scaleform::GFx::AS2::ASRefCountBaseType::Collector* collector, int operation)
{
    switch (operation)
    {
    case 0: FUN_1400120a0(object, collector); break;
    case 1: FUN_140011ef0(object, collector); break;
    case 2: FUN_140011fc0(object, collector); break;
    }
}

// @0x140011ac0
void FUN_140011ac0(Scaleform::GFx::AS2::Object* object, Scaleform::GFx::AS2::Environment* environment)
{
    Scaleform::GFx::AS2::ASStringContext* stringContext = environment->GetSC();
    Scaleform::GFx::AS2::Object* prototype = stringContext->pContext->GetPrototype(
        static_cast<Scaleform::GFx::AS2::ASBuiltinType>(0x22));
    reinterpret_cast<Scaleform::GFx::AS2::ObjectInterface*>(
        reinterpret_cast<unsigned char*>(object) + 0x20)->Set__proto__(stringContext, prototype);
}

// ---- vtable-slot adjustor thunks (no .pdata; `sub rcx,N; jmp` into the scalar deleting destructors above) ----

// (0x14000ebc0 / 0x14000ebd0, this - 0x20 / - 0x70 into 0x14000ec40, are cl's adjustor thunks of VideoProto's ??_G)

// (0x14000ed10, this - 0x20 into 0x14000ed20, is cl's adjustor thunk of VideoCtorFunction's ??_G)

// (0x140010180, this - 0x18 into 0x140010530, is cl's adjustor thunk of Video02Character's ??_E)

// (0x140011c70 is cl's adjustor thunk; see the NetConnection models)

// (0x140011c80 is cl's adjustor thunk; see the NetConnection models)

// (0x140011d00 is cl's adjustor thunk; see the NetConnection models)

// (0x140012580 is cl's adjustor thunk; see the NetConnection models)

// (0x140012590 is cl's adjustor thunk; see the NetConnection models)

// (0x1400126a0, this - 0x20 into 0x1400126b0, is cl's adjustor thunk of NetConnectionCtorFunction's ??_G)

// Leaf slot targets of the video vtables (data_rdata_sf_video): getters, forwarders and the AS3 NetStream method
// thunks. A thunk calls the native through the member-pointer static the exe keeps in .bss ({function, this
// adjustment}, built by sfr_gfx_13's dynamic initialisers), on the object of the `this` Value (+0x10).
extern void* DAT_143b276f8;
extern int DAT_143b27700;
extern void* DAT_143b274a8;
extern int DAT_143b274b0;
extern void* DAT_143b27558;
extern int DAT_143b27560;
extern void* DAT_143b27498;
extern int DAT_143b274a0;
extern void* DAT_143b275d8;
extern int DAT_143b275e0;
extern void* DAT_143b27668;
extern int DAT_143b27670;
// (GASPrototypeBase::AddInterface is called through Video02PrototypeAccess; the slot keeps its bool form)

typedef void (*Video02ArgsNative)(void*, void*, unsigned, const void*);
typedef void (*Video02ResultNative)(void*, void*);

static void* Video02ThunkThis(const void* thisValue, int adjust)
{
    return *reinterpret_cast<char* const*>(static_cast<const char*>(thisValue) + 0x10) + adjust;
}



// object type tag 0x21.
// @0x140011b80
int FUN_140011b80(void*) { return 0x21; }

// forwards to virtual slot 11 with the member block at +0xe8 of the second argument.
// @0x140011b90
void* FUN_140011b90(void* self, void* owner, void* a2, void* a3)
{
    typedef void* (*Slot)(void*, void*, void*, void*);
    return (*reinterpret_cast<Slot**>(self))[11](self, static_cast<char*>(owner) + 0xe8, a2, a3);
}

// GASPrototypeBase::AddInterface on the prototype base at +0x48.
// @0x140011ba0
bool FUN_140011ba0(void* self, void* context, void* index, void* function)
{
    return (reinterpret_cast<Scaleform::GFx::AS2::GASPrototypeBase*>(static_cast<char*>(self) + 0x48)->*Video02PrototypeAccess::AddInterfaceAsSlot())(context, index, function);
}

// InstanceOf: the object itself, else GASPrototypeBase::DoesImplement on the base at +0x68.
// @0x140011bb0
bool FUN_140011bb0(void* self, void* env, void* prototype)
{
    if (self == prototype)
        return true;
    return reinterpret_cast<Video02PrototypeAccess*>(static_cast<char*>(self) + 0x68)->DoesImplement(
        static_cast<Scaleform::GFx::AS2::Environment*>(env), static_cast<const Scaleform::GFx::AS2::Object*>(prototype));
}

// always true.
// @0x140011bd0
bool FUN_140011bd0(void*) { return true; }

// instance traits name.
// @0x140012ef0
const char* FUN_140012ef0(void*) { return "InstanceTraits::NetStream"; }

// class traits name.
// @0x140012f40
const char* FUN_140012f40(void*) { return "Classes::NetStream"; }

// AS3 thunk, native (this, result, argc, argv) through the member pointer at 0x143b276f8.
// @0x140013230
void FUN_140013230(void*, void*, const void* thisValue, void* result, unsigned argc, const void* argv)
{
    reinterpret_cast<Video02ArgsNative>(DAT_143b276f8)(Video02ThunkThis(thisValue, DAT_143b27700), result, argc, argv);
}

// AS3 thunk, native (this, result, argc, argv) through the member pointer at 0x143b274a8.
// @0x140013250
void FUN_140013250(void*, void*, const void* thisValue, void* result, unsigned argc, const void* argv)
{
    reinterpret_cast<Video02ArgsNative>(DAT_143b274a8)(Video02ThunkThis(thisValue, DAT_143b274b0), result, argc, argv);
}

// AS3 thunk, native (this, result) through the member pointer at 0x143b27558.
// @0x1400133e0
void FUN_1400133e0(void*, void*, const void* thisValue, void* result, unsigned, const void*)
{
    reinterpret_cast<Video02ResultNative>(DAT_143b27558)(Video02ThunkThis(thisValue, DAT_143b27560), result);
}

// AS3 thunk, native (this, result) through the member pointer at 0x143b27498.
// @0x140013400
void FUN_140013400(void*, void*, const void* thisValue, void* result, unsigned, const void*)
{
    reinterpret_cast<Video02ResultNative>(DAT_143b27498)(Video02ThunkThis(thisValue, DAT_143b274a0), result);
}

// AS3 thunk, native (this, result) through the member pointer at 0x143b275d8.
// @0x140013420
void FUN_140013420(void*, void*, const void* thisValue, void* result, unsigned, const void*)
{
    reinterpret_cast<Video02ResultNative>(DAT_143b275d8)(Video02ThunkThis(thisValue, DAT_143b275e0), result);
}

// AS3 thunk, native (this, result) through the member pointer at 0x143b27668.
// @0x140013440
void FUN_140013440(void*, void*, const void* thisValue, void* result, unsigned, const void*)
{
    reinterpret_cast<Video02ResultNative>(DAT_143b27668)(Video02ThunkThis(thisValue, DAT_143b27670), result);
}

// instance name.
// @0x1400141a0
const char* FUN_1400141a0(void*) { return "Instances::fl_net::NetStream"; }

// The AS2 video character (vftables 0x1431b5cb0 at +0x00, 0x1431b5c00 for its ObjectInterface at +0x08 and
// 0x1431b5b40 for its AvmVideoCharacterBase at +0x30; ctor in sfr_video_01). The overriders are the leaves above at
// their exe VAs (declared here, symbols-manual rows), so the secondary tables' slots are cl's own adjustor thunks
// (sub rcx,N; jmp member): the exe ones in 0x14000e6c0-0x14000e830. Video02EmitAvmVideoVftables copy-constructs one so
// that cl emits the vftables and thunks.
#include "../include/video/video_as2avmvideocharacter.h"
namespace Scaleform { namespace GFx { namespace AS2 {
void Video02EmitAvmVideoVftables(void* p, const AvmVideoCharacter* pvideo)
{
    ::new (p) AvmVideoCharacter(*pvideo);
}

// AvmVideoCharacter's overriders at their exe VAs.
// @0x14000e510
AvmVideoCharacterBase* AvmVideoCharacter::ToAvmVideoCharacterBase() { return this; }
// @0x14000e520
AvmInteractiveObjBase* AvmVideoCharacter::ToAvmInteractiveObjBase() { return static_cast<AvmCharacter*>(this); }
// @0x14000e530
AvmSpriteBase* AvmVideoCharacter::ToAvmSpriteBase() { return NULL; }
// @0x14000e540
AvmButtonBase* AvmVideoCharacter::ToAvmButttonBase() { return NULL; }
// @0x14000e550
AvmTextFieldBase* AvmVideoCharacter::ToAvmTextFieldBase() { return NULL; }
// @0x14000e560
AvmDisplayObjContainerBase* AvmVideoCharacter::ToAvmDispContainerBase() { return NULL; }
// pDispObj->GetAbsolutePath would dispatch back here via GetAvmObjImpl() (thunk 0x14000e750) and recurse.
// @0x14000e570
const char* AvmVideoCharacter::GetAbsolutePath(String* ppath) const { return AvmCharacter::GetAbsolutePath(ppath); }
// @0x14000e580
bool AvmVideoCharacter::OnEvent(const EventId&) { return false; }
// Sends Event_Load (id 1) through the object's own vtable slot 8.
// @0x14000e590
void AvmVideoCharacter::OnEventLoad()
{
    void** object = reinterpret_cast<void**>(this);
    Scaleform::GFx::EventId payload(1);
    typedef void (*ApplyFn)(void*, const Scaleform::GFx::EventId*);
    reinterpret_cast<ApplyFn>(*reinterpret_cast<void**>(static_cast<char*>(*object) + 0x40))(
        object, &payload);
}
// @0x14000e5d0
void AvmVideoCharacter::OnEventUnload() { AvmCharacter::OnEventUnload(); }
// Detaches this clip from the frame advance list.
// @0x14000e5e0
bool AvmVideoCharacter::OnUnloading(bool)
{
    pDispObj->RemoveFromPlayList();
    return true;
}
// @0x14000e600
bool AvmVideoCharacter::HasEventHandler(const EventId&) const { return false; }
// @0x14000e610
unsigned AvmVideoCharacter::GetCursorType() const { return 0; }
// @0x14000e620
bool AvmVideoCharacter::ActsAsButton() const { return false; }
// @0x14000e630
void AvmVideoCharacter::CloneInternalData(const InteractiveObject* src) { AvmCharacter::CloneInternalData(src); }
// The display object's InteractiveObject::CopyPhysicalProperties ends in GetAvmIntObj()->CopyPhysicalProperties,
// which is this slot, so forwarding through pDispObj recursed.
// @0x14000e640
void AvmVideoCharacter::CopyPhysicalProperties(const InteractiveObject* poldChar)
{
    AvmCharacter::CopyPhysicalProperties(poldChar);
}
// AvmCharacter::OnFocus (0x14296bd60) directly, not through the vtable.
// @0x14000e650
void AvmVideoCharacter::OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                                unsigned controllerIdx, FocusMovedType fmt)
{
    AvmCharacter::OnFocus(event, oldOrNewFocusCh, controllerIdx, fmt);
}
// @0x14000e670
void AvmVideoCharacter::OnGettingKeyboardFocus(unsigned, FocusMovedType) {}
// @0x14000e680
bool AvmVideoCharacter::OnKeyEvent(const EventId&, int*) { return false; }
// @0x14000e690
bool AvmVideoCharacter::OnLosingKeyboardFocus(InteractiveObject*, unsigned, FocusMovedType) { return true; }
// @0x14000e6a0
bool AvmVideoCharacter::IsFocusEnabled(FocusMovedType) const { return true; }
// the AvmCharacter tab rule
// @0x14000e6b0
bool AvmVideoCharacter::IsTabable() const { return AvmCharacter::IsTabable(); }
// @0x14000e880
Object* AvmVideoCharacter::GetASObject() { return reinterpret_cast<Object*>(FUN_14000e020(this)); }
// @0x14000e890
Object* AvmVideoCharacter::GetASObject() const
{
    return reinterpret_cast<Object*>(FUN_14000e020(const_cast<AvmVideoCharacter*>(this)));
}
// 0x1431b5c00 [2]: a constant kind.
// @0x14000e500
ObjectInterface::ObjectType AvmVideoCharacter::GetObjectType() const { return static_cast<ObjectType>(5); }

// SetMember and GetMember override ObjectInterface (+0x08), so cl enters them with that subobject in rcx.
// Standard members first (slot 0x118 on the AvmCharacter), then the Video properties, then the script object
// (FUN_14000e020, called twice like the exe).
// @0x14000e8f0
bool AvmVideoCharacter::SetMember(Environment* penv, const ASString& name, const Value& value, const PropFlags& flags)
{
    char* fields = reinterpret_cast<char*>(this) + 8;   // the ObjectInterface subobject cl entered with
    // pavm (this-8) is recomputed at each use, as in the exe (no register holds it)
    // the exe tries the standard members (_x, _alpha, ...) first: slot 0x118 on this-8 (0x14000e93d)
    if ((UByte(name.GetHashFlags() >> 29) & 1)
        && reinterpret_cast<AvmCharacter*>(fields - 8)->SetStandardMember(
               reinterpret_cast<AvmCharacter*>(fields - 8)->GetStandardMemberConstant(name), value, false))
        goto done;
    if (!strcmp(name.ToCStr(), "deblocking"))
    {
        *reinterpret_cast<int*>(fields + 0x38) = static_cast<int>(value.ToNumber(penv));
    done:
        return true;
    }
    if (!strcmp(name.ToCStr(), "smoothing"))
    {
        *reinterpret_cast<bool*>(fields + 0x3c) = value.ToBool(penv);
        return true;
    }
    if (FUN_14000e020(reinterpret_cast<AvmCharacter*>(fields - 8)))
        return reinterpret_cast<Object*>(FUN_14000e020(reinterpret_cast<AvmCharacter*>(fields - 8)))
            ->SetMember(penv, name, value, flags);
    return false;
}

// Standard members first (slot 0x120 on the AvmCharacter), then width, height, deblocking and smoothing, then the script object.
// @0x14000e9f0
bool AvmVideoCharacter::GetMember(Environment* penv, const ASString& name, Value* pvalue)
{
    char* fields = reinterpret_cast<char*>(this) + 8;   // the ObjectInterface subobject cl entered with
    // the exe tries the standard members first: slot 0x120 on this-8 (0x14000ea3d)
    if (((UInt8)(name.GetHashFlags() >> 29) & 1)
        && reinterpret_cast<AvmCharacter*>(fields - 8)->GetStandardMember(reinterpret_cast<AvmCharacter*>(fields - 8)->GetStandardMemberConstant(name), pvalue, false))
        return true;
    const char* key = name.ToCStr();
    if (!strcmp(key, "width"))
    {
        pvalue->SetNumber(*reinterpret_cast<int*>(fields + 0x30));
        return true;
    }
    if (!strcmp(key, "height"))
    {
        pvalue->SetNumber(*reinterpret_cast<int*>(fields + 0x34));
        return true;
    }
    if (!strcmp(key, "deblocking"))
        pvalue->SetNumber(*reinterpret_cast<int*>(fields + 0x38));
    else if (!strcmp(key, "smoothing"))
        pvalue->SetBool(*reinterpret_cast<bool*>(fields + 0x3c));
    else if (FUN_14000e020(reinterpret_cast<AvmCharacter*>(fields - 8)))
        return reinterpret_cast<Object*>(FUN_14000e020(reinterpret_cast<AvmCharacter*>(fields - 8)))->GetMember(penv, name, pvalue);
    else
        return false;
    return true;
}

// VideoObject's prototype (vftables 0x1431b5e20 / +0x20 0x1431b5e70 / +0x70 0x1431b5e18, stored by FUN_14000eb50):
// Prototype<VideoObject> with no overriders of its own. Its ??_G is 0x14000ec40 and the ObjectInterface / GASPrototypeBase slots are cl's adjustor thunks
// 0x14000ebc0 / 0x14000ebd0. Video02EmitVideoProtoVftables constructs one so cl emits them. (The class is
// declared near the top of this file.)
void Video02EmitVideoProtoVftables(void* p, ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
{
    ::new (p) VideoProto(psc, pprototype, constructor);
}

// The Video constructor function (vftables 0x1431b5f20 / +0x20 0x1431b5fb0, stored by FUN_14000ecc0). Its ??_G is
// 0x14000ed20 and the ObjectInterface slot 0 is cl's adjustor thunk 0x14000ed10.
void Video02EmitVideoCtorVftables(void* p, ASStringContext* psc)
{
    ::new (p) VideoCtorFunction(psc);
}

// Emits the NetConnectionProto, Prototype<NetConnection> and NetConnection vftables with their ??_G and thunks.
void Video02EmitNetConnectionVftables(void* p, ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
{
    ::new (p) NetConnectionProto(psc, pprototype, constructor);
}
// The NetConnection constructor function (vftables 0x1431b6740 / 0x1431b67d0).
class NetConnectionCtorFunction : public CFunctionObject
{
public:
    NetConnectionCtorFunction(ASStringContext* psc) : CFunctionObject(psc, ::FUN_140012340) {}
    // (implicit destructor: the ??_G 0x1400126b0 calls the out-of-line ~CFunctionObject)
    virtual Object* CreateNewObject(Environment* penv) const;   // exe 0x140011d50 (FUN_140011d50)
};
// Emits NetConnectionCtorFunction's vftables with its ??_G and the ObjectInterface (+0x20) adjustor thunk.
void Video02EmitNetConnectionCtorVftables(void* p, ASStringContext* psc)
{
    ::new (p) NetConnectionCtorFunction(psc);
}
}}} // namespace Scaleform::GFx::AS2
namespace Scaleform { namespace GFx {
// VideoCharacter's vftables: 0x1431b6060 (115 slots, InteractiveObject's with five overrides) and the LogBase table
// 0x1431b63f8 at +0x18. FUN_140010000 stores them. Slots 1/55/59/75 are the overriders defined after
// the dtor below; the dtor is 0x1400104d0 and cl's ??_G (0x140010530) and ??_E thunk (0x140010180)
// come with its vftable.
class Video02Character : public InteractiveObject
{
public:
    virtual ~Video02Character();
    virtual Ptr<Render::TreeNode> CreateRenderNode(Render::ContextImpl::Context& context) const;  // 0x140011610
    virtual RectF GetBounds(const Matrix& t) const;                                               // 0x140010200
    virtual CharacterDef* GetCharacterDef() const;                                                // 0x140010130
    virtual CharacterDef::CharacterDefType GetType() const;                                       // 0x140010140
    RectF Bounds;        // +0xe0
    void* pDef;          // +0xf0
    int* pRefs;          // +0xf8
    void* pProvider;     // +0x100
};
static_assert(offsetof(Video02Character, Bounds) == 0xe0, "Video02Character layout");
static_assert(offsetof(Video02Character, pProvider) == 0x100, "Video02Character layout");

// @0x1400104d0
Video02Character::~Video02Character()
{
    if (pProvider)
        reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(pProvider))[2])(pProvider);
    int* refs = pRefs;
    if (refs && --*refs == 0) Memory::Free(refs);
}

// returns the pointer member at +0xf0.
// @0x140010130
CharacterDef* Video02Character::GetCharacterDef() const { return static_cast<CharacterDef*>(pDef); }

// object type tag 7.
// @0x140010140
CharacterDef::CharacterDefType Video02Character::GetType() const { return static_cast<CharacterDef::CharacterDefType>(7); }

// @0x140010200
RectF Video02Character::GetBounds(const Matrix& t) const
{
    return t.EncloseTransform(Bounds);
}

// MS2-FUNCTIONAL: constructs the video shape provider, scales its geometry to the decoded frame, and creates a tree entry.
// The video rectangle is (0, 0, width, height) as in the exe; without a provider the placeholder path is the exe's
// 0,0 -> 1,1 segment. Both paths are closed inline (ClosePath) as the exe does.
// @0x140011610
Ptr<Render::TreeNode> Video02Character::CreateRenderNode(Render::ContextImpl::Context& contextRef) const
{
    // the return value is built in place (NRVO): result is the caller's Ptr slot
    Ptr<Render::TreeNode> ret;
    void** result = reinterpret_cast<void**>(&ret);
    void* object = const_cast<Video02Character*>(this);
    void* context = &contextRef;
    using namespace Scaleform;
    using namespace Scaleform::Render;
    unsigned char* bytes = static_cast<unsigned char*>(object);
    // the exe asks the interface (object + [0x6d]*4, slot 0x60) for the extent before allocating (0x140011638)
    unsigned char* iface = bytes + static_cast<UPInt>(bytes[0x6d]) * 4;
    typedef void* (*GetVideoExtent)(void*);
    unsigned char* extent = static_cast<unsigned char*>(reinterpret_cast<GetVideoExtent>((*reinterpret_cast<void***>(iface))[12])(iface));
    void* shapeMem = Memory::pGlobalHeap->AllocAutoHeap(object, 0x90, &static_cast<const AllocInfo&>(AllocInfo(2, 0, 0)));
    ShapeDataFloatMP* pshape = shapeMem ? ::new (shapeMem) ShapeDataFloatMP() : 0;
    unsigned char* shape = reinterpret_cast<unsigned char*>(pshape);
    void** pdata = reinterpret_cast<void**>(shape + 0x88);   // reloaded for each step
    Ptr<ImageBase>& pimage = *reinterpret_cast<Ptr<ImageBase>*>(bytes + 0x100);
    if (pimage) {
        FillStyleType fs;
        void* fillMem = Memory::pGlobalHeap->AllocAutoHeap(object, 0x50, &static_cast<const AllocInfo&>(AllocInfo(2, 0, 0)));
        ComplexFill* pcf = fillMem ? ::new (fillMem) ComplexFill() : 0;
        pcf->pImage = pimage;
        pcf->ImageMatrix.SetIdentity();
        pcf->ImageMatrix.AppendScaling(0.05f);   // twips
        pcf->ImageMatrix.AppendScaling(
            static_cast<float>(*reinterpret_cast<int*>(extent + 8) * 20) /
                (*reinterpret_cast<float*>(bytes + 0xe8) - *reinterpret_cast<float*>(bytes + 0xe0)),
            static_cast<float>(*reinterpret_cast<int*>(extent + 12) * 20) /
                (*reinterpret_cast<float*>(bytes + 0xec) - *reinterpret_cast<float*>(bytes + 0xe4)));
        pcf->FillMode.Fill = *reinterpret_cast<unsigned char*>(extent + 0x14) ? 3 : 1;   // Wrap_Clamp, Sample_Linear when smoothing
        // ShapeDataFloatTempl::AddFillStyle: Fills.PushBack, the copy's AddRef unconditional as in the exe (0x1400118de)
        unsigned char* data = static_cast<unsigned char*>(*pdata);
        Video02ResizeFills(data + 0x18, data + 0x18, *reinterpret_cast<UPInt*>(data + 0x20) + 1);
        UInt32* fill = reinterpret_cast<UInt32*>(*reinterpret_cast<unsigned char**>(data + 0x18) - 0x10 +
                                                 *reinterpret_cast<UPInt*>(data + 0x20) * 0x10);
        if (fill) {
            *fill = fs.Color;
            FUN_14257dc30(pcf);
            *reinterpret_cast<ComplexFill**>(fill + 2) = pcf;
        }
        Video02StartLayer(*pdata);
        unsigned fillStyles = reinterpret_cast<unsigned (*)(void*)>((*reinterpret_cast<void***>(*pdata))[2])(*pdata);
        Scaleform::GFx::AS3::Sfr31WriteRecord3(reinterpret_cast<UPInt>(*pdata), fillStyles, 0, 0);
        // the rectangle is the frame's size at the origin (0x140011943), not its bounds
        FUN_140011500(shape, 0.0f, 0.0f,
            *reinterpret_cast<float*>(bytes + 0xe8) - *reinterpret_cast<float*>(bytes + 0xe0),
            *reinterpret_cast<float*>(bytes + 0xec) - *reinterpret_cast<float*>(bytes + 0xe4));
        Video02ClosePath(*pdata);
        pshape->CountLayers();
        // The closing reference drop is RefCountImpl::Release (exe 0x140011982 -> 0x14257dcb0), not vftable slot 2:
        // slot 2 of ??_7ComplexFill (0x1424e3830) is a deleting dtor, which freed the fill while the path still
        // held it (refcount 2); the path's later Release then decremented +8 of the freed (reused) block.
        FUN_14257dcb0(pcf);
    } else {
        Scaleform::GFx::AS3::Sfr31WriteRecord3(reinterpret_cast<UPInt>(*pdata), 0, 0, 0);
        Video02MoveTo(*pdata, 0.0f, 0.0f);
        Video02LineTo(*pdata, 1.0f, 1.0f);
        Video02ClosePath(*pdata);
        Scaleform::GFx::AS3::Sfr33PathEndRun(static_cast<UByte*>(*pdata));
    }
    typedef void* (*AllocateNodeData)(void*, size_t, size_t);
    void* nodeHeap = *reinterpret_cast<void**>(context);  // MS2: exe 0x140011a06 allocates from [context], the context's heap
    unsigned char* nodeData = static_cast<unsigned char*>(
        reinterpret_cast<AllocateNodeData>((*reinterpret_cast<void***>(nodeHeap))[10])(nodeHeap, 0xa0, 0));
    unsigned char* providerBase = shape + 0x10;
    if (nodeData) {
        reinterpret_cast<TreeNode::NodeData*>(nodeData)->TreeNode::NodeData::NodeData(static_cast<ContextImpl::EntryData::EntryType>(3));
        *reinterpret_cast<const void* const**>(nodeData) = TreeShapeNodeDataVTable;
        reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(providerBase))[1])(providerBase);
        *reinterpret_cast<void**>(nodeData + 0x90) = shape;
        *reinterpret_cast<float*>(nodeData + 0x98) = 0.0f;
    }
    void* entry = Video02CreateEntry(context, nodeData);
    if (entry) ++*reinterpret_cast<UPInt*>(static_cast<unsigned char*>(entry) + 8);
    *result = entry;
    reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(providerBase))[2])(providerBase);
    if (entry) {
        if (--*reinterpret_cast<UPInt*>(static_cast<unsigned char*>(entry) + 8) == 0)
            static_cast<Video02EntryAccess*>(entry)->Video02EntryAccess::destroyHelper();
    }
    return ret;
}
}} // namespace Scaleform::GFx
#ifndef MS2_HOOK_DLL
// FUN_140010000 stores Video02Character's vftables through these names.
#pragma comment(linker, "/alternatename:?PTR_FUN_1431b6060@@3PEAXEA=??_7Video02Character@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@2@@")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b63f8@@3PEAXEA=??_7Video02Character@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@12@@")
// FUN_14000eb50 stores VideoProto's vftables through these names (the hook DLL binds them by their symbols rows).
#pragma comment(linker, "/alternatename:?PTR_FUN_1431b5e20@@3PEAXEA=??_7VideoProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b5e70@@3PEAXEA=??_7VideoProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b5e18@@3PEAXEA=??_7VideoProto@AS2@GFx@Scaleform@@6B@")
// FUN_14000ecc0 stores VideoCtorFunction's vftables through these names.
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b5f20@@3PEAXEA=??_7VideoCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b5fb0@@3PEAXEA=??_7VideoCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@")
// FUN_140011ef0 / FUN_1400122e0 / FUN_140012440 store the NetConnection family vftables through these names.
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b65f0@@3PEAXEA=??_7NetConnection@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b6540@@3PEAXEA=??_7NetConnection@AS2@GFx@Scaleform@@6BObjectInterface@123@@")
#pragma comment(linker, "/alternatename:?PTR_FUN_1431b64f0@@3PEAXEA=??_7?$Prototype@VNetConnection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b6440@@3PEAXEA=??_7?$Prototype@VNetConnection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b6430@@3PEAXEA=??_7?$Prototype@VNetConnection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@")
#pragma comment(linker, "/alternatename:?PTR_FUN_1431b6640@@3PEAXEA=??_7NetConnectionProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b6690@@3PEAXEA=??_7NetConnectionProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b6638@@3PEAXEA=??_7NetConnectionProto@AS2@GFx@Scaleform@@6B@")
// NetConnection::GetObjectType and Prototype<NetConnection>::GetMemberRaw are the hand FUN_ bodies.
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b6740@@3PEAXEA=??_7NetConnectionCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b67d0@@3PEAXEA=??_7NetConnectionCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@")
#pragma comment(linker, "/alternatename:?CreateNewObject@NetConnectionCtorFunction@AS2@GFx@Scaleform@@UEBAPEAVObject@234@PEAVEnvironment@234@@Z=?FUN_140011d50@@YAPEAVObject@AS2@GFx@Scaleform@@PEAXPEAVEnvironment@234@@Z")
#pragma comment(linker, "/alternatename:?GetObjectType@NetConnection@AS2@GFx@Scaleform@@UEBA?AW4ObjectType@ObjectInterface@234@XZ=?FUN_140011b80@@YAHPEAX@Z")
#pragma comment(linker, "/alternatename:?GetMemberRaw@?$Prototype@VNetConnection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@PEAVValue@234@@Z=?FUN_140011de0@@YAXPEAVObject@AS2@GFx@Scaleform@@PEAVASStringContext@234@PEAVASString@34@PEAVValue@234@@Z")
#endif

// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
// MS2-PIN: ??_7?$RefCountBase@VComplexFill@Render@Scaleform@@$01@Scaleform@@6B@ 0x14317b660
// MS2-PIN: ??_7ComplexFill@Render@Scaleform@@6B@ 0x14317b668
// MS2-PIN: ??_7?$Prototype@VVideoObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b59f0
// MS2-PIN: ??_7?$Prototype@VVideoObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b5940
// MS2-PIN: ??_7?$Prototype@VVideoObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x1431b5938
// The AS2 AvmVideoCharacter model's vftables and its bases', its deleting destructor and cl's adjustor thunks for the
// 0x1431b5c00 / 0x1431b5b40 slots.
// MS2-PIN: ??_7AvmInteractiveObjBase@GFx@Scaleform@@6B@ 0x14317bfe8
// MS2-PIN: ??_7ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215410
// MS2-PIN: ??_7AvmCharacter@AS2@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x143215b00
// MS2-PIN: ??_7AvmCharacter@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215c48
// MS2-PIN: ??_GAvmVideoCharacter@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x14000e8a0
// MS2-PIN: ??_EAvmVideoCharacter@AS2@GFx@Scaleform@@W7EAAPEAXI@Z 0x14000e6c0
// MS2-PIN: ?CloneInternalData@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAAXPEBVInteractiveObject@34@@Z 0x14000e6d0
// MS2-PIN: ?OnEventLoad@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAAXXZ 0x14000e6e0
// MS2-PIN: ?OnFocus@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAAXW4FocusEventType@InteractiveObject@34@PEAV634@IW4FocusMovedType@34@@Z 0x14000e6f0
// MS2-PIN: ?OnEventUnload@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAAXXZ 0x14000e700
// MS2-PIN: ??_EAvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAAPEAXI@Z 0x14000e710
// MS2-PIN: ?HasEventHandler@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EBA_NAEBVEventId@34@@Z 0x14000e720
// MS2-PIN: ?ToAvmDispContainerBase@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAAPEAVAvmDisplayObjContainerBase@34@XZ 0x14000e730
// MS2-PIN: ?OnEvent@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAA_NAEBVEventId@34@@Z 0x14000e740
// MS2-PIN: ?GetAbsolutePath@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EBAPEBDPEAVString@4@@Z 0x14000e750
// MS2-PIN: ?IsTabable@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EBA_NXZ 0x14000e760
// MS2-PIN: ?GetCursorType@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EBAIXZ 0x14000e770
// MS2-PIN: ?OnLosingKeyboardFocus@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAA_NPEAVInteractiveObject@34@IW4FocusMovedType@34@@Z 0x14000e780
// MS2-PIN: ?ToAvmVideoCharacterBase@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAAPEAVAvmVideoCharacterBase@34@XZ 0x14000e790
// MS2-PIN: ?ToAvmButttonBase@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAAPEAVAvmButtonBase@34@XZ 0x14000e7a0
// MS2-PIN: ?ToAvmInteractiveObjBase@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAAPEAVAvmInteractiveObjBase@34@XZ 0x14000e7b0
// MS2-PIN: ?IsFocusEnabled@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EBA_NW4FocusMovedType@34@@Z 0x14000e7c0
// MS2-PIN: ?OnKeyEvent@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAA_NAEBVEventId@34@PEAH@Z 0x14000e7d0
// MS2-PIN: ?CopyPhysicalProperties@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAAXPEBVInteractiveObject@34@@Z 0x14000e7e0
// MS2-PIN: ?OnUnloading@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAA_N_N@Z 0x14000e7f0
// MS2-PIN: ?ToAvmSpriteBase@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAAPEAVAvmSpriteBase@34@XZ 0x14000e800
// MS2-PIN: ?ToAvmTextFieldBase@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAAPEAVAvmTextFieldBase@34@XZ 0x14000e810
// MS2-PIN: ?ActsAsButton@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EBA_NXZ 0x14000e820
// MS2-PIN: ?OnGettingKeyboardFocus@AvmVideoCharacter@AS2@GFx@Scaleform@@WDA@EAAXIW4FocusMovedType@34@@Z 0x14000e830
// MS2-PIN: ??_7AvmVideoCharacter@AS2@GFx@Scaleform@@6B@ 0x1431b5b40
// MS2-PIN: ??_7AvmVideoCharacter@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b5c00
// MS2-PIN: ??_7AvmVideoCharacter@AS2@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x1431b5cb0
// VideoProto (declared near the top; vftables emitted by Video02EmitVideoProtoVftables)
// MS2-PIN: ??_GVideoProto@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x14000ec40
// MS2-PIN: ??_EVideoProto@AS2@GFx@Scaleform@@WCA@EAAPEAXI@Z 0x14000ebc0
// MS2-PIN: ??_EVideoProto@AS2@GFx@Scaleform@@WHA@EAAPEAXI@Z 0x14000ebd0
// MS2-PIN: ??_7VideoProto@AS2@GFx@Scaleform@@6B@ 0x1431b5e18
// MS2-PIN: ??_7VideoProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b5e20
// MS2-PIN: ??_7VideoProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b5e70
// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// The Video constructor function's vftables, deleting destructor and cl's adjustor thunk for the ObjectInterface slot.
// MS2-PIN: ??_GVideoCtorFunction@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x14000ed20
// MS2-PIN: ??_EVideoCtorFunction@AS2@GFx@Scaleform@@WCA@EAAPEAXI@Z 0x14000ed10
// MS2-PIN: ??_7VideoCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b5f20
// MS2-PIN: ??_7VideoCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b5fb0

// MS2-PIN: ??_GNetConnection@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x140011d10
// MS2-PIN: ??_ENetConnection@AS2@GFx@Scaleform@@WCA@EAAPEAXI@Z 0x140011d00
// MS2-PIN: ??_7NetConnection@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b65f0
// MS2-PIN: ??_7NetConnection@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b6540
// MS2-PIN: ??_G?$Prototype@VNetConnection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x140011c00
// MS2-PIN: ??1?$Prototype@VNetConnection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEAA@XZ 0x140011b40
// MS2-PIN: ??_E?$Prototype@VNetConnection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@WCA@EAAPEAXI@Z 0x140011c70
// MS2-PIN: ??_E?$Prototype@VNetConnection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@WGI@EAAPEAXI@Z 0x140011c80
// MS2-PIN: ??_7?$Prototype@VNetConnection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b64f0
// MS2-PIN: ??_7?$Prototype@VNetConnection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b6440
// MS2-PIN: ??_7?$Prototype@VNetConnection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x1431b6430
// MS2-PIN: ??_GNetConnectionProto@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x1400125e0
// MS2-PIN: ??1NetConnectionProto@AS2@GFx@Scaleform@@UEAA@XZ 0x1400125a0
// MS2-PIN: ??_ENetConnectionProto@AS2@GFx@Scaleform@@WCA@EAAPEAXI@Z 0x140012580
// MS2-PIN: ??_ENetConnectionProto@AS2@GFx@Scaleform@@WGI@EAAPEAXI@Z 0x140012590
// MS2-PIN: ??_7NetConnectionProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b6640
// MS2-PIN: ??_7NetConnectionProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b6690
// MS2-PIN: ??_7NetConnectionProto@AS2@GFx@Scaleform@@6B@ 0x1431b6638
// MS2-PIN: ??_7NetConnectionCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1431b6740
// MS2-PIN: ??_7NetConnectionCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1431b67d0
// MS2-PIN: ??_GNetConnectionCtorFunction@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x1400126b0
// MS2-PIN: ??_ENetConnectionCtorFunction@AS2@GFx@Scaleform@@WCA@EAAPEAXI@Z 0x1400126a0
// MS2-PIN: ??_7Video02Character@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@2@@ 0x1431b6060
// MS2-PIN: ??_7Video02Character@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@12@@ 0x1431b63f8
// MS2-PIN: ??_GVideo02Character@GFx@Scaleform@@UEAAPEAXI@Z 0x140010530
// MS2-PIN: ??_EVideo02Character@GFx@Scaleform@@WBI@EAAPEAXI@Z 0x140010180
