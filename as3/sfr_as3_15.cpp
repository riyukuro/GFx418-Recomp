// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_15
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424c9700-0x1424dc870 .text$mn
// MS2-PIN: ??_7Allocator@Text@Render@Scaleform@@6B@ 0x14317c9d0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BED@@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7Class@AS3@GFx@Scaleform@@6B@ 0x14317b140
// MS2-PIN: ??_7CTraits@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14317b3a0
// MS2-PIN: ??_7Object@AS3@GFx@Scaleform@@6B@ 0x14317b098
// MS2-PIN: ??_7RTraits@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14317b428
// MS2-PIN: ??_7Traits@AS3@GFx@Scaleform@@6B@ 0x14317b210
// MS2-PIN: ??_7Traits@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14317b288
// MS2-PIN: ??_7Traits@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14317b300
#include "ms2/scaleform/include/gfx/gfx_input.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_xml.h"
#include "ms2/scaleform/include/gfx/gfx_sprite.h"
#include "ms2/scaleform/include/render/render_shapedata.h"
#include "ms2/scaleform/include/gfx/gfx_rendertree.h"
#include "ms2/scaleform/include/gfx/gfx_movieslots.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_mnhash.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/gfx_interactiveobject.h"
#include "ms2/scaleform/include/gfx/gfx_imemanager.h"
#include "ms2/scaleform/include/gfx/gfx_imecandidateliststyle.h"
#include "ms2/scaleform/include/kernel/sf_msgformat.h"
#include "ms2/scaleform/include/kernel/sf_simd.h"
#include "ms2/scaleform/include/gfx/as3/as3_intervaltimer.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_utils.h"
#include "ms2/scaleform/include/gfx/as3/as3_loadqueue.h"
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_userdefined.h"
#include "ms2/scaleform/include/gfx/gfx_textfield.h"
#include "ms2/scaleform/include/gfx/as3/as3_callframe.h"
#include "ms2/scaleform/include/gfx/as3/as3_udbase.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/gfx_player.h"

// Bodies of the exe called here (not recovered yet), by their addresses.
// The movie whose library an AS3 object's class came from.
Scaleform::GFx::MovieDefImpl* FUN_14250d8f0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Instances::fl::Object* pobj);
// VM::IsOfType(v, class name).
bool FUN_1425145d0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v, const char* className);
// VM::describeTypeEx (returns the ASString through a hidden pointer)
Scaleform::GFx::ASString* FUN_1425322c0(Scaleform::GFx::AS3::VM* vm, void* result, const Scaleform::GFx::AS3::Value& v);
void FUN_1425bc060(void* ptf);                          // TextField::SetDirtyFlag
bool FUN_1425b9730(void* ptf);                          // TextField::HasStyleSheet
// DocView::AppendHtml (the image tags it meets go to *pimgInfoArr)
void FUN_14260de50(void* pdoc, const char* phtml, Scaleform::UPInt htmlSize, bool multiline, void* pimgInfoArr);
void FUN_1425ba7d0(void* ptf, void* pimgInfoArr);       // TextField::ProcessImageTags
// VM::IsOfType(v, class traits)
bool FUN_1425146d0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v,
                   const Scaleform::GFx::AS3::ClassTraits::Traits& ctr);
void FUN_142614e30(void* psubst, void* pimgDesc);        // DocView::ImageSubstitutor::RemoveImageDesc
void FUN_1425bb680(void* ptf, const char* id);           // TextField::RemoveIdImageDescAssoc
void FUN_1425b7220(void* ptf);                          // TextField::ClearIdImageDescAssoc
const char* FUN_142509b60(int id);                     // the text of error id ("... {0} ...")
// AvmTextField: one image substitution element (an object of the script's array) at index idx
void FUN_14251d070(void* pavmtf, Scaleform::GFx::AS3::VM& vm, unsigned idx, const Scaleform::GFx::AS3::Value& ve);
// Value::operator=(const ASString&), out of line in the exe
Scaleform::GFx::AS3::Value& FUN_1424e0d40(Scaleform::GFx::AS3::Value& v, const Scaleform::GFx::ASString& str);
// AvmInteractiveObj::AvmInteractiveObj (abstract here, so the derived ctors reach it by address)
void FUN_1424d6480(void* self, Scaleform::GFx::InteractiveObject* pdispObj);
// ArrayDataBase::ResizeNoConstruct(pheapAddr, newSize) of VMAbcFile::IntStrings, and ArrayData::Resize of its
// OpCodeArray and Exceptions: out of line in the exe
void FUN_142524a30(void* self, const void* pheapAddr, Scaleform::UPInt newSize);
void FUN_1425244e0(void* self, Scaleform::UPInt newSize);
// VM::UnregisterAbcFile: drops file from VMAbcFilesWeak unless the VM is being destroyed
bool FUN_142522a60(Scaleform::GFx::AS3::VM* vm, void* file);
// the clear-and-free of the VMAbcFile hash sets not modeled (activation and function traits caches), each passed the
// address of its table pointer
void FUN_1424dcdd0(void* table);
void FUN_1424dcc30(void* table);
void FUN_142524710(void* self, Scaleform::UPInt newSize);
// The abs objects and global objects sets of a VMAbcFile (+0x38, +0x70): their destructors 0x1424dd1a0 and
// 0x1424dd250 are instantiated in sfr_as3_16.
namespace Scaleform {
typedef GFx::AS3::SPtr<GFx::AS3::GASRefCountBase> Sfr34AbsObjectValue;
typedef HashSetBase<Sfr34AbsObjectValue, FixedSizeHash<Sfr34AbsObjectValue>, FixedSizeHash<Sfr34AbsObjectValue>,
    AllocatorLH<Sfr34AbsObjectValue, 2>, HashsetCachedEntry<Sfr34AbsObjectValue, FixedSizeHash<Sfr34AbsObjectValue> > >
    Sfr34AbsObjectSet;
typedef GFx::AS3::SPtr<GFx::AS3::Instances::fl::GlobalObjectScript> Sfr34GlobalObjectValue;
typedef HashSetBase<Sfr34GlobalObjectValue, FixedSizeHash<Sfr34GlobalObjectValue>,
    FixedSizeHash<Sfr34GlobalObjectValue>, AllocatorLH<Sfr34GlobalObjectValue, 2>,
    HashsetCachedEntry<Sfr34GlobalObjectValue, FixedSizeHash<Sfr34GlobalObjectValue> > > Sfr34GlobalObjectSet;
extern template Sfr34AbsObjectSet::~HashSetBase();
extern template Sfr34GlobalObjectSet::~HashSetBase();
}
// ResourceHandle::GetResource, the exe's out-of-line copy (the header's is inline)
Scaleform::GFx::Resource* FUN_14250d840(const Scaleform::GFx::ResourceHandle* self, Scaleform::GFx::ResourceBinding* pbinding);
// DisplayObject::DisplayObject (protected; ShapeObject is opaque here, so its ctor reaches it by address)
void FUN_1425f07e0(void* self, Scaleform::GFx::ASMovieRootBase* pasRoot, Scaleform::GFx::InteractiveObject* pparent,
                   Scaleform::GFx::ResourceId id);
namespace Scaleform {
// DocView::ImageSubstitutor::Element, the same stand-in as sfr_as3_14 (ArrayDataBase destructor = exe 0x1424c7090),
// and the substitutor itself (the DocView's +0x30).
struct MS2_ImageSubstElement                // 0x38 bytes
{
    wchar_t              SubString[20];
    Ptr<RefCountNTSImpl> pImageDesc;        // +0x28
    UByte                SubStringLen;
};
// Text::ImageDesc (a RefCountBaseNTS): only its image is touched here.
struct MS2_TextImageDesc : public RefCountNTSImpl
{
    Ptr<Render::Image> pImage;              // +0x10
};
struct MS2_ImageSubstitutor : public NewOverrideBase<Stat_Default_Mem>
{
    ~MS2_ImageSubstitutor();                // out of line in the exe: the Elements destructor 0x1424c7090
    ArrayLH<MS2_ImageSubstElement> Elements;
};
// StyledText::HTMLImageTagInfo: the render Text headers do not mix with this kernel tree, so the same stand-in as
// sfr_as3_14 (whose ArrayDataBase destructor instantiation is the exe's 0x1424c7100).
struct MS2_HTMLImageTagInfo                 // 0x40 bytes
{
    Ptr<RefCountNTSImpl> pTextImageDesc;
    StringDH             Url;               // +0x08
    StringDH             Id;                // +0x18
    unsigned             Width, Height;
    int                  VSpace, HSpace;
    unsigned             ParaId;
    UByte                Alignment;
};
}
namespace Scaleform { namespace GFx { class MovieImpl; class Sprite; }}
namespace Scaleform {
void LogDebugMessage(LogMessageId id, const char* fmt, ...);
namespace GFx {
// What an image creator is asked to make (0x38 bytes); the same as sfr_gfx_06e.
class ImageCreateInfo
{
public:
    enum { Create_SourceImage = 3 };

    ImageCreateInfo(int type, MemoryHeap* pheap, unsigned use, Resource::ResourceUse ruse)
        : Type(type), pHeap(pheap), Use(use), RUse(ruse), pLog(0), pFileOpener(0), pIFHRegistry(0), pMovie(0)
    {
    }

    int                   Type;          // +0
    MemoryHeap*           pHeap;         // +8
    unsigned              Use;           // +0x10
    Resource::ResourceUse RUse;          // +0x14
    void*                 pLog;          // +0x18
    void*                 pFileOpener;   // +0x20
    void*                 pIFHRegistry;  // +0x28
    void*                 pMovie;        // +0x30
};
struct ImageCreateExportInfo;

// Turns image files and sources into images (vftable 0x143184c60); the same as sfr_gfx_06e.
class ImageCreator : public State
{
public:
    virtual Render::Image* LoadProtocolImage(const ImageCreateInfo& info, const String& url);
    virtual Render::Image* LoadImageFile(const ImageCreateInfo& info, const String& url);
    virtual Render::Image* LoadExportedImage(const ImageCreateExportInfo& info, const String& url);
    virtual Render::Image* CreateImage(const ImageCreateInfo& info, Render::ImageSource* source);
};
}}
Scaleform::GFx::Sprite* FUN_14256f820(Scaleform::GFx::MovieImpl* pmovie, unsigned controllerIdx);   // MovieImpl::GetModalClip
// MovieImpl's focus-key processing (moveFocus/findFocus): pinfo is a ProcessFocusKeyInfo (MS2_FocusKeyInfo).
void FUN_142570d80(Scaleform::GFx::MovieImpl* pmovie, void* pinfo, const void* pkeyEntry, bool inclFocusEnabled,
                   void* pfocusGroup);                                                  // MovieImpl::InitFocusKeyInfo
void FUN_142572050(Scaleform::GFx::MovieImpl* pmovie, int eventType, const void* pkeyEntry, void* pinfo); // ProcessFocusKey
void FUN_14256eae0(Scaleform::GFx::MovieImpl* pmovie, void* pinfo);                     // FinalizeProcessFocusKey
// The exe keeps one out-of-line copy of storing a raw pointer into a namespace slot (0x1424e0710).
namespace Scaleform { namespace GFx { namespace AS3 {
template <> SPtr<GASRefCountBase>& SPtr<GASRefCountBase>::SetPtr(GASRefCountBase* p);
}}}

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x1424cdc40: Instances::fl_media::SoundTransform::leftToLeftGet
template struct ThunkFunc0<Instances::fl_media::SoundTransform, 0, Value::Number>;
// thunk 0x1424cdcb0: Instances::fl_media::SoundTransform::leftToLeftSet
template struct ThunkFunc1<Instances::fl_media::SoundTransform, 1, const Value, Value::Number>;
// thunk 0x1424cdd40: Instances::fl_media::SoundTransform::leftToRightGet
template struct ThunkFunc0<Instances::fl_media::SoundTransform, 2, Value::Number>;
// thunk 0x1424cddb0: Instances::fl_media::SoundTransform::leftToRightSet
template struct ThunkFunc1<Instances::fl_media::SoundTransform, 3, const Value, Value::Number>;
// thunk 0x1424cde40: Instances::fl_media::SoundTransform::panGet
template struct ThunkFunc0<Instances::fl_media::SoundTransform, 4, Value::Number>;
// thunk 0x1424cdeb0: Instances::fl_media::SoundTransform::panSet
template struct ThunkFunc1<Instances::fl_media::SoundTransform, 5, const Value, Value::Number>;
// thunk 0x1424cdf40: Instances::fl_media::SoundTransform::rightToLeftGet
template struct ThunkFunc0<Instances::fl_media::SoundTransform, 6, Value::Number>;
// thunk 0x1424cdfb0: Instances::fl_media::SoundTransform::rightToLeftSet
template struct ThunkFunc1<Instances::fl_media::SoundTransform, 7, const Value, Value::Number>;
// thunk 0x1424ce040: Instances::fl_media::SoundTransform::rightToRightGet
template struct ThunkFunc0<Instances::fl_media::SoundTransform, 8, Value::Number>;
// thunk 0x1424ce0b0: Instances::fl_media::SoundTransform::rightToRightSet
template struct ThunkFunc1<Instances::fl_media::SoundTransform, 9, const Value, Value::Number>;
// thunk 0x1424ce140: Instances::fl_media::SoundTransform::volumeGet
template struct ThunkFunc0<Instances::fl_media::SoundTransform, 10, Value::Number>;
// thunk 0x1424ce1b0: Instances::fl_media::SoundTransform::volumeSet
template struct ThunkFunc1<Instances::fl_media::SoundTransform, 11, const Value, Value::Number>;
// thunk 0x1424ceb00: Instances::fl_media::Sound::bytesLoadedGet
template struct ThunkFunc0<Instances::fl_media::Sound, 0, UInt32>;
// thunk 0x1424ceb60: Instances::fl_media::Sound::bytesTotalGet
template struct ThunkFunc0<Instances::fl_media::Sound, 1, SInt32>;
// thunk 0x1424cebc0: Instances::fl_media::Sound::id3Get
template struct ThunkFunc0<Instances::fl_media::Sound, 2, SPtr<Instances::fl_media::ID3Info>>;
// thunk 0x1424cec70: Instances::fl_media::Sound::isBufferingGet
template struct ThunkFunc0<Instances::fl_media::Sound, 3, bool>;
// thunk 0x1424cecd0: Instances::fl_media::Sound::lengthGet
template struct ThunkFunc0<Instances::fl_media::Sound, 4, Value::Number>;
// thunk 0x1424ced40: Instances::fl_media::Sound::urlGet
template struct ThunkFunc0<Instances::fl_media::Sound, 5, ASString>;
// thunk 0x1424cedb0: Instances::fl_media::Sound::close
template struct ThunkFunc0<Instances::fl_media::Sound, 6, const Value>;
// thunk 0x1424cedd0: Instances::fl_media::Sound::load
template struct ThunkFunc2<Instances::fl_media::Sound, 7, const Value, Instances::fl_net::URLRequest*, Instances::fl_media::SoundLoaderContext*>;
// Instances::fl_media::Sound::play argument 0 default
template <> struct ThunkMethodDefault<Instances::fl_media::Sound, 8, 0, Value::Number>
{
    SF_INLINE static Value::Number Get(StringManager&) { return 0.0; }
};
// thunk 0x1424cee20: Instances::fl_media::Sound::play
template struct ThunkFunc3<Instances::fl_media::Sound, 8, Value, Value::Number, SInt32, Instances::fl_media::SoundTransform*>;
// thunk 0x1424cef10: Instances::fl_media::SoundChannel::leftPeakGet
template struct ThunkFunc0<Instances::fl_media::SoundChannel, 0, Value::Number>;
// thunk 0x1424cef80: Instances::fl_media::SoundChannel::positionGet
template struct ThunkFunc0<Instances::fl_media::SoundChannel, 1, Value::Number>;
// thunk 0x1424ceff0: Instances::fl_media::SoundChannel::rightPeakGet
template struct ThunkFunc0<Instances::fl_media::SoundChannel, 2, Value::Number>;
// thunk 0x1424cf060: Instances::fl_media::SoundChannel::soundTransformGet
template struct ThunkFunc0<Instances::fl_media::SoundChannel, 3, SPtr<Instances::fl_media::SoundTransform>>;
// thunk 0x1424cf110: Instances::fl_media::SoundChannel::soundTransformSet
template struct ThunkFunc1<Instances::fl_media::SoundChannel, 4, const Value, Instances::fl_media::SoundTransform*>;
// thunk 0x1424cf150: Instances::fl_media::SoundChannel::stop
template struct ThunkFunc0<Instances::fl_media::SoundChannel, 5, const Value>;
// thunk 0x1424d2160: Class::prototypeGet
template struct ThunkFunc0<Class, 0, Value>;
// thunk 0x1424d2180: Class::lengthGet
template struct ThunkFunc0<Class, 1, SInt32>;
// thunk 0x1424d21e0: Class::toString
// MS2-FUNCTIONAL: inlining only: the exe inlines the string result store (Value::AssignUnsafe(const ASString&))
template struct ThunkFunc0<Class, 2, ASString>;


namespace Instances { namespace fl_gfx
{
    // @0x1424c9d30
    SF_NOINLINE void GamePadAnalogEvent::clone(SPtr<Instances::fl_events::Event>& result)
    {
        result = Clone().GetPtr();
    }

    // @0x1424c9d10
    SPtr<Instances::fl_events::Event> GamePadAnalogEvent::clone()
    {
        SPtr<Instances::fl_events::Event> result;
        clone(result);
        return result;
    }

    // MS2-FUNCTIONAL: the exe reloads each temporary string node from the stack after the Value ctor, ours keeps it in rbx
    // @0x1424cc0f0
    void GamePadAnalogEvent::toString(ASString& result)
    {
        Value r;
        VM& vm = GetVM();
        Value argv[] = {
            Value(vm.GetStringManager().CreateConstString("GamePadAnalogEvent")),
            Value(vm.GetStringManager().CreateConstString("type")),
            Value(vm.GetStringManager().CreateConstString("bubbles")),
            Value(vm.GetStringManager().CreateConstString("cancelable")),
            Value(vm.GetStringManager().CreateConstString("eventPhase")),
            Value(vm.GetStringManager().CreateConstString("code")),
            Value(vm.GetStringManager().CreateConstString("controllerIdx")),
            Value(vm.GetStringManager().CreateConstString("xvalue")),
            Value(vm.GetStringManager().CreateConstString("yvalue"))
        };
        formatToString(r, sizeof(argv) / sizeof(argv[0]), argv);
        r.Convert2String(result).DoNotCheck();
    }
}}

namespace Classes { namespace fl_gfx
{
    // @0x1424ca900
    void Extensions::getEdgeAAMode(UInt32& result, Instances::fl_display::DisplayObject* dobj)
    {
        switch (dobj->pDispObj->GetRenderNode()->GetEdgeAAMode())
        {
        case Render::EdgeAA_On:      result = EDGEAA_ON; break;
        case Render::EdgeAA_Off:     result = EDGEAA_OFF; break;
        case Render::EdgeAA_Disable: result = EDGEAA_DISABLE; break;
        default:                     result = EDGEAA_INHERIT; break;
        }
    }

    // @0x1424cb680
    void Extensions::numControllersGet(UInt32& result)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        if (vm.ExtensionsEnabled)
            result = AsMovieSlots(vm.GetMovieImpl())->GetControllerCount();
    }

    // @0x1424cb7c0
    void Extensions::setEdgeAAMode(const Value& result, Instances::fl_display::DisplayObject* dobj, UInt32 mode)
    {
        SF_UNUSED(result);
        Render::EdgeAAMode m = Render::EdgeAA_Inherit;
        if (mode == EDGEAA_DISABLE)
            m = Render::EdgeAA_Disable;
        else if (mode == EDGEAA_ON)
            m = Render::EdgeAA_On;
        else if (mode == EDGEAA_OFF)
            m = Render::EdgeAA_Off;
        dobj->pDispObj->GetRenderNode()->SetEdgeAAMode(m);
    }
}}

UPInt FUN_142507210(VM& vm, Array<SPtr<VMAbcFile> >& files);

// SystemEx / TextFieldEx natives. The display TextField is opaque here (its flags word is at +0xfc), and so is its
// Text::DocView (TextField+0xe0), whose header does not build with the AS3 kernel headers: AlignProps is at +0x148
// (vertical alignment in bits 2-3: none/top/bottom/center; text auto size in bits 4-5: none/shrink/fit) and the
// RTFlags byte at +0x14b (bit 0: reformat requested).
namespace Classes { namespace fl_gfx
{
    // @0x1424c9ad0
    void SystemEx::actionVerboseSet(const Value& result, bool verbose)
    {
        SF_UNUSED(result);
        AsMovieSlots(static_cast<ASVM&>(GetVM()).GetMovieImpl())->SetVerboseAction(verbose);
        // FlashUI::NeedToCheckOpCode
        *((bool*)&GetVM().GetUI() + 0xc) = verbose;
    }

    // MS2-FUNCTIONAL: same code; the exe allocates one callee-saved register less (re-reads the string node from its slot)
    // @0x1424ca6b0
    void SystemEx::getCodeFileNames(SPtr<Instances::fl::Array>& result)
    {
        // VM::GetAllLoadedAbcFiles: fills files with every loaded ABC file, returns the count.
        Array<SPtr<VMAbcFile> > files;
        const UPInt n = FUN_142507210(GetVM(), files);
        SPtr<Instances::fl::Array> arr = GetVM().MakeArray();
        for (UPInt i = 0; i < n; ++i)
        {
            Value v(GetVM().GetStringManager().CreateString(files[i]->GetAbcFile().Source.ToCStr()));
            arr->SA.PushBack(v);
        }
        result = arr;
    }

    // @0x1424c9e00
    void SystemEx::describeType(ASString& result, const Value& v)
    {
        struct { ASStringNode* pNode; } tmp;
        result = *FUN_1425322c0(&GetVM(), &tmp, v);
        reinterpret_cast<ASString*>(&tmp)->~ASString();
    }

    // @0x1424cb6e0
    void SystemEx::printObjectsReport(const Value& result, bool runGarbageCollector, UInt32 reportFlags,
                                      const ASString& swfFilter)
    {
        SF_UNUSED(result);
        MovieSlots418* pmovie = AsMovieSlots(static_cast<ASVM&>(GetVM()).GetMovieImpl());
        if (runGarbageCollector)
            pmovie->ForceCollectGarbage();
        pmovie->PrintObjectsReport(reportFlags, NULL, swfFilter.ToCStr());
    }

    enum { VAlign_None, VAlign_Top, VAlign_Bottom, VAlign_Center };
    enum { TAS_None, TAS_Shrink, TAS_Fit };

    static inline UByte* TextDocView(GFx::DisplayObject* ptf) { return *(UByte**)((UByte*)ptf + 0xe0); }
    // The head of Text::DocView: its image substitutor at +0x30.
    struct DocViewHead
    {
        UByte                   Unrecovered_00[0x30];
        MS2_ImageSubstitutor*   pImageSubstitutor;  // +0x30
    };
    static inline DocViewHead* TextDocViewHead(GFx::DisplayObject* ptf)
    {
        return reinterpret_cast<DocViewHead*>(TextDocView(ptf));
    }
    static inline unsigned GetVAlignment(UByte* pdoc)   { return (pdoc[0x148] >> 2) & 3; }
    static inline unsigned GetTextAutoSize(UByte* pdoc) { return (pdoc[0x148] >> 4) & 3; }
    static inline void SetVAlignment(UByte* pdoc, unsigned a)
    {
        pdoc[0x148] = (UByte)((pdoc[0x148] & ~(3 << 2)) | ((a & 3) << 2));
        pdoc[0x14b] |= 1;
    }
    static inline void SetTextAutoSize(UByte* pdoc, unsigned a)
    {
        pdoc[0x148] = (UByte)((pdoc[0x148] & ~(3 << 4)) | ((a & 3) << 4));
        pdoc[0x14b] |= 1;
    }

    // @0x1424cbf60
    void TextFieldEx::setVerticalAlign(const Value& result, Instances::fl_text::TextField* textField, const ASString& valign)
    {
        SF_UNUSED(result);
        VM& vm = GetVM();
        if (!textField)
        {
            vm.ThrowArgumentError(VM::Error(VM::eNullArgumentError, vm, "textField"));
            return;
        }
        if (!static_cast<ASVM&>(vm).ExtensionsEnabled)
            return;
        GFx::DisplayObject* ptf = textField->pDispObj.GetPtr();
        if (!ptf)
        {
            vm.ThrowArgumentError(VM::Error(VM::eNullArgumentError, vm, "textField"));
            return;
        }
        if (valign == "none")
            SetVAlignment(TextDocView(ptf), VAlign_None);
        else if (valign == "top")
            SetVAlignment(TextDocView(ptf), VAlign_Top);
        else if (valign == "bottom")
            SetVAlignment(TextDocView(ptf), VAlign_Bottom);
        else if (valign == "center")
            SetVAlignment(TextDocView(ptf), VAlign_Center);
        FUN_1425bc060(ptf);
    }

    // @0x1424cb1d0
    void TextFieldEx::getVerticalAlign(ASString& result, Instances::fl_text::TextField* textField)
    {
        if (!textField)
        {
            GetVM().ThrowArgumentError(VM::Error(VM::eNullArgumentError, GetVM(), "textField"));
            return;
        }
        GFx::DisplayObject* ptf = textField->pDispObj.GetPtr();
        if (!ptf)
        {
            GetVM().ThrowArgumentError(VM::Error(VM::eNullArgumentError, GetVM(), "textField"));
            return;
        }
        switch (GetVAlignment(TextDocView(ptf)))
        {
        case VAlign_Bottom: result = "bottom"; break;
        case VAlign_Center: result = "center"; break;
        case VAlign_Top:    result = "top"; break;
        default:                                   result = "none"; break;
        }
    }

    // @0x1424cbdb0
    void TextFieldEx::setTextAutoSize(const Value& result, Instances::fl_text::TextField* textField, const ASString& autoSz)
    {
        SF_UNUSED(result);
        VM& vm = GetVM();
        if (!textField)
        {
            vm.ThrowArgumentError(VM::Error(VM::eNullArgumentError, vm, "textField"));
            return;
        }
        if (!static_cast<ASVM&>(vm).ExtensionsEnabled)
            return;
        GFx::DisplayObject* ptf = textField->pDispObj.GetPtr();
        if (!ptf)
        {
            vm.ThrowArgumentError(VM::Error(VM::eNullArgumentError, vm, "textField"));
            return;
        }
        if (autoSz == "none")
            SetTextAutoSize(TextDocView(ptf), TAS_None);
        else if (autoSz == "shrink")
            SetTextAutoSize(TextDocView(ptf), TAS_Shrink);
        else if (autoSz == "fit")
            SetTextAutoSize(TextDocView(ptf), TAS_Fit);
        FUN_1425bc060(ptf);
    }

    // @0x1424caf40
    void TextFieldEx::getTextAutoSize(ASString& result, Instances::fl_text::TextField* textField)
    {
        if (!textField)
        {
            GetVM().ThrowArgumentError(VM::Error(VM::eNullArgumentError, GetVM(), "textField"));
            return;
        }
        GFx::DisplayObject* ptf = textField->pDispObj.GetPtr();
        if (!ptf)
        {
            GetVM().ThrowArgumentError(VM::Error(VM::eNullArgumentError, GetVM(), "textField"));
            return;
        }
        switch (GetTextAutoSize(TextDocView(ptf)))
        {
        case TAS_Shrink: result = "shrink"; break;
        case TAS_Fit:    result = "fit"; break;
        default:                                result = "none"; break;
        }
    }

    // @0x1424cbab0
    void TextFieldEx::setIMEEnabled(const Value& result, Instances::fl_text::TextField* textField, bool isEnabled)
    {
        SF_UNUSED(result);
        if (!textField)
        {
            GetVM().ThrowArgumentError(VM::Error(VM::eNullArgumentError, GetVM(), "textField"));
            return;
        }
        GFx::DisplayObject* ptf = textField->pDispObj.GetPtr();
        if (!ptf)
        {
            GetVM().ThrowArgumentError(VM::Error(VM::eNullArgumentError, GetVM(), "textField"));
            return;
        }
        // TextField::SetIMEDisabledFlag
        UInt32& flags = *(UInt32*)((UByte*)ptf + 0xfc);
        if (!isEnabled)
            flags |= 0x800;
        else
            flags &= ~0x800u;
    }

    // @0x1424cbb40
    void TextFieldEx::setImageSubstitutions(const Value& result, Instances::fl_text::TextField* textField, const Value& substInfo)
    {
        SF_UNUSED(result);
        VM& vm = GetVM();
        if (!textField)
        {
            vm.ThrowArgumentError(VM::Error(VM::eNullArgumentError, vm, "TextFieldEx::setImageSubstitutions"));
            return;
        }
        GFx::DisplayObject* ptf = textField->pDispObj.GetPtr();
        if (substInfo.IsNull() || substInfo.IsUndefined())
        {
            // clear all substitutions
            FUN_1425b7220(ptf);
            DocViewHead* pdoc = TextDocViewHead(ptf);
            delete pdoc->pImageSubstitutor;
            pdoc->pImageSubstitutor = NULL;
            TextDocView(ptf)[0x14b] |= 2;   // DocView: reformat
            FUN_1425bc060(ptf);
        }
        else if (substInfo.IsObject())
        {
            Object* pobj = substInfo.GetObject();
            if (FUN_1425146d0(vm, substInfo, *vm.TraitsArray))
            {
                Instances::fl::Array* parr = static_cast<Instances::fl::Array*>(pobj);
                for (UPInt i = 0, n = parr->GetSize(); i < n; ++i)
                {
                    const Value& ve = parr->At(i);
                    if (ve.IsObject())
                    {
                        AvmInteractiveObjBase* pavm = ptf->GetAvmObjImpl()->ToAvmInteractiveObjBase();
                        FUN_14251d070(pavm ? (UByte*)pavm - 0x30 : NULL, vm, (unsigned)i, ve);
                    }
                }
            }
            else if (substInfo.IsObject())
            {
                AvmInteractiveObjBase* pavm = ptf->GetAvmObjImpl()->ToAvmInteractiveObjBase();
                FUN_14251d070(pavm ? (UByte*)pavm - 0x30 : NULL, vm, 0, substInfo);
            }
        }
        else
            ptf->LogScriptWarning("%s.setImageSubstitutions() failed: parameter should be either 'null', object or array",
                                  ptf->GetName().ToCStr());
    }

    // MS2-FUNCTIONAL: same code; the exe keeps the text field in rsi and the hash table in rbp (register permutation)
    // @0x1424cc450
    void TextFieldEx::updateImageSubstitution(const Value& result, Instances::fl_text::TextField* textField, const ASString& id, Instances::fl_display::BitmapData* bitmapData)
    {
        SF_UNUSED(result);
        if (!textField)
        {
            GetVM().ThrowArgumentError(VM::Error(VM::eNullArgumentError, GetVM(), "textField"));
            return;
        }
        GFx::DisplayObject* ptf = textField->pDispObj.GetPtr();
        if (!ptf)
        {
            GetVM().ThrowArgumentError(VM::Error(VM::eNullArgumentError, GetVM(), "textField"));
            return;
        }
        // TextField::pImageDescAssoc
        StringHash<Ptr<MS2_TextImageDesc> >* passoc = *(StringHash<Ptr<MS2_TextImageDesc> >**)((UByte*)ptf + 0x120);
        if (!passoc)
            return;
        Ptr<MS2_TextImageDesc>* ppimgDesc;
        {
            String key(id.ToCStr());
            ppimgDesc = passoc->Get(key);
        }
        if (!ppimgDesc)
            return;
        MS2_TextImageDesc* pimgDesc = *ppimgDesc;
        if (!bitmapData)
        {
            // DocView::GetImageSubstitutor
            MS2_ImageSubstitutor*& psubst = TextDocViewHead(ptf)->pImageSubstitutor;
            if (!psubst)
                psubst = new MS2_ImageSubstitutor;
            if (psubst)
            {
                FUN_142614e30(psubst, pimgDesc);
                TextDocView(ptf)[0x14b] |= 2;   // DocView: reformat
                FUN_1425bb680(ptf, id.ToCStr());
                FUN_1425bc060(ptf);
            }
        }
        else
        {
            ImageResource* pimageRes = bitmapData->GetImageResource();
            Ptr<MovieDefImpl> pmd = ptf->GetResourceMovieDef();
            Ptr<Render::Image> img;
            if (pimageRes->GetImage()->GetImageType() != Render::ImageBase::Type_ImageBase)
                img = (Render::Image*)pimageRes->GetImage();
            else if (!Ptr<ImageCreator>(*(ImageCreator*)pmd->GetStateAddRef(State::State_ImageCreator)))
                LogDebugMessage(Log_Warning, "ImageCreator is null in UpdateImageSubstitution");
            else
            {
                ImageCreateInfo cinfo(ImageCreateInfo::Create_SourceImage, Memory::GetHeapByAddress(ptf), 1,
                                      Resource::Use_Bitmap);
                img = *Ptr<ImageCreator>(*(ImageCreator*)pmd->GetStateAddRef(State::State_ImageCreator))
                           ->CreateImage(cinfo, (Render::ImageSource*)pimageRes->GetImage());
            }
            pimgDesc->pImage = img;
            FUN_1425bc060(ptf);
        }
    }

    // @0x1424c9bb0
    void TextFieldEx::appendHtml(const Value& result, Instances::fl_text::TextField* textField, const ASString& newHtml)
    {
        SF_UNUSED(result);
        VM& vm = GetVM();
        if (!textField)
        {
            vm.ThrowArgumentError(VM::Error(VM::eNullArgumentError, vm, "textField"));
            return;
        }
        if (!static_cast<ASVM&>(vm).ExtensionsEnabled)
            return;
        GFx::DisplayObject* ptf = textField->pDispObj.GetPtr();
        if (!ptf)
        {
            vm.ThrowArgumentError(VM::Error(VM::eNullArgumentError, vm, "textField"));
            return;
        }
        if (FUN_1425b9730(ptf))
            return;
        ArrayDH<MS2_HTMLImageTagInfo> imageInfoArray(Memory::GetHeapByAddress(ptf));
        FUN_14260de50(TextDocView(ptf), newHtml.ToCStr(), SF_MAX_UPINT, false, &imageInfoArray);
        // TextField: the text was set from script (flags word bit 16)
        *(UInt32*)((UByte*)ptf + 0xfc) |= 0x10000;
        if (imageInfoArray.GetSize() > 0)
            FUN_1425ba7d0(ptf, &imageInfoArray);
        FUN_1425bc060(ptf);
    }
}}

namespace Classes { namespace fl_gfx
{
    // @0x1424ca860
    void FocusManager::getControllerFocusGroup(UInt32& result, UInt32 controllerIdx)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        if (vm.ExtensionsEnabled)
        {
            result = AsMovieSlots(vm.GetMovieImpl())->GetControllerFocusGroup(controllerIdx);
            return;
        }
        result = 0;
    }

    // @0x1424ca8b0
    void FocusManager::getControllerMaskByFocusGroup(UInt32& result, UInt32 focusGroupIdx)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        if (vm.ExtensionsEnabled)
        {
            result = vm.GetMovieImpl()->GetControllerMaskByFocusGroup(focusGroupIdx);
            return;
        }
        result = 0;
    }

    // @0x1424cab30
    void FocusManager::getFocusGroupMask(UInt32& result, Instances::fl_display::InteractiveObject* obj)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        if (vm.ExtensionsEnabled)
            result = static_cast<GFx::InteractiveObject*>(obj->pDispObj.GetPtr())->GetFocusGroupMask();
    }

    // @0x1424cb770
    void FocusManager::setControllerFocusGroup(bool& result, UInt32 controllerIdx, UInt32 focusGroupIdx)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        if (vm.ExtensionsEnabled)
        {
            result = AsMovieSlots(vm.GetMovieImpl())->SetControllerFocusGroup(controllerIdx, focusGroupIdx);
            return;
        }
        result = false;
    }
}}

namespace
{
    // The AS3 part of a display object (as3_avm.h is not included here): the CreateASInstance slot (15) and the
    // AS3 object pointers.
    class AvmDisplayObj15 : public AvmDisplayObjBase
    {
    public:
        virtual void        OnRemoved(bool byTimeline);
        virtual void        Unrecovered_14();
        virtual unsigned    CreateASInstance(bool execute);

        Instances::fl_display::DisplayObject* GetAS3Obj() const
        {
            Instances::fl_display::DisplayObject* p = pAS3RawPtr;
            if (!p)
                p = pAS3CollectiblePtr;
            if (reinterpret_cast<UPInt>(p) & 1)
                p = reinterpret_cast<Instances::fl_display::DisplayObject*>(reinterpret_cast<UByte*>(p) - 1);
            return p;
        }

        Instances::fl_display::DisplayObject*   pAS3CollectiblePtr; // +0x08 SPtr<>
        Instances::fl_display::DisplayObject*   pAS3RawPtr;         // +0x10
    };

    // AS3::AvmInteractiveObj: the AvmInteractiveObjBase interface sits at +0x30.
    class AvmInteractiveObjHead15 : public AvmDisplayObj15
    {
        UByte   Unrecovered_18[0x18];
    };
    class AvmInteractiveObj15 : public AvmInteractiveObjHead15, public AvmInteractiveObjBase
    {
    };

    inline AvmDisplayObj15* ToAvmDisplayObj15(GFx::DisplayObject* p)
    {
        return static_cast<AvmDisplayObj15*>(p->GetAvmObjImpl());
    }
    inline AvmInteractiveObj15* ToAvmInteractiveObj15(GFx::InteractiveObject* p)
    {
        return static_cast<AvmInteractiveObj15*>(p->GetAvmIntObj());
    }
}

namespace Classes { namespace fl_gfx
{
    // MS2-FUNCTIONAL: exe strips the AS3 pointer collectible tag with a branch (test/je/dec), ours with cmov; same loads and calls
    // @0x1424cae10
    void Extensions::getMouseTopMostEntity(SPtr<Instances::fl_display::DisplayObject>& result, bool testAll,
                                           UInt32 mouseIndex)
    {
        MovieImpl* proot = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        if (mouseIndex >= AsMovieSlots(proot)->GetMouseCursorCount())
            return;
        // MouseState[mouseIndex].LastPosition (the states are 0x50 apart; no state past the fourth)
        const Render::PointF* plast = (mouseIndex < 4)
            ? reinterpret_cast<const Render::PointF*>(reinterpret_cast<UByte*>(proot) + 0x1298 + mouseIndex * (UPInt)0x50)
            : reinterpret_cast<const Render::PointF*>((UPInt)0x38);
        Render::PointF mousePos = *plast;
        GFx::InteractiveObject* ptop = proot->GetTopMostEntity(mousePos, mouseIndex, testAll, NULL);
        if (ptop)
        {
            AvmInteractiveObj15* pavm = ToAvmInteractiveObj15(ptop);
            pavm->CreateASInstance(true);
            result = pavm->GetAS3Obj();
        }
        else
            result = NULL;
    }

    // MS2-FUNCTIONAL: exe strips the AS3 pointer collectible tag with a branch, ours with cmov; xmm2/xmm3 swapped in the point transform
    // @0x1424cb000
    void Extensions::getTopMostEntity(SPtr<Instances::fl_display::DisplayObject>& result, Value::Number x,
                                      Value::Number y, bool testAll)
    {
        MovieImpl* proot = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        if (proot->pMainMovie)
        {
            Render::Matrix2F m;
            proot->pMainMovie->GetWorldMatrix(&m);
            Render::PointF p((float)(x * 20.0), (float)(y * 20.0));
            Render::PointF pt(m.M[0][0] * p.x + m.M[0][1] * p.y + m.M[0][3],
                              m.M[1][0] * p.x + m.M[1][1] * p.y + m.M[1][3]);
            GFx::InteractiveObject* ptop = proot->GetTopMostEntity(pt, 0, testAll, NULL);
            if (ptop)
            {
                AvmInteractiveObj15* pavm = ToAvmInteractiveObj15(ptop);
                pavm->CreateASInstance(true);
                result = pavm->GetAS3Obj();
                return;
            }
        }
        result = NULL;
    }

    // MS2-FUNCTIONAL: exe strips the AS3 pointer collectible tag with a branch (test/je/dec), ours with cmov; same loads and calls
    // @0x1424cad40
    void FocusManager::getModalClip(SPtr<Instances::fl_display::Sprite>& result, UInt32 controllerIdx)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        if (!vm.ExtensionsEnabled)
            return;
        GFx::Sprite* pmodal = FUN_14256f820(vm.GetMovieImpl(), controllerIdx);
        if (!pmodal)
            return;
        Instances::fl_display::DisplayObject* ido = ToAvmDisplayObj15(reinterpret_cast<GFx::DisplayObject*>(pmodal))->GetAS3Obj();
        BuiltinTraitsType tt = ido->GetTraits().GetTraitsType();
        if (tt == Traits_Sprite || tt == Traits_MovieClip)
            result = static_cast<Instances::fl_display::Sprite*>(ido);
    }
    // MS2-FUNCTIONAL: exe strips the AS3 pointer collectible tag with a branch (test/je/dec), ours with cmov; same loads and calls
    // @0x1424ca9b0
    void FocusManager::getFocus(SPtr<Instances::fl_display::InteractiveObject>& result, UInt32 controllerIdx)
    {
        MovieImpl* proot = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        Ptr<GFx::InteractiveObject> focused = proot->FocusGroups[proot->FocusGroupIndexes[controllerIdx]].LastFocused;
        if (focused)
        {
            AvmInteractiveObjBase* pavm = focused->GetAvmIntObj();
            const UPInt* pas3 = pavm ? reinterpret_cast<const UPInt*>(reinterpret_cast<UByte*>(pavm) - 0x30) : NULL;
            UPInt raw = pas3[2];
            if (!raw)
                raw = pas3[1];
            if (raw & 1)
                raw -= 1;
            Instances::fl_display::DisplayObject* ido = reinterpret_cast<Instances::fl_display::DisplayObject*>(raw);
            if (ido)
            {
                BuiltinTraitsType tt = ido->GetTraits().GetTraitsType();
                if (tt == Traits_InteractiveObject || tt >= Traits_DisplayObjectContainer)
                    result = static_cast<Instances::fl_display::InteractiveObject*>(ido);
            }
            else
                result = NULL;
        }
        else
            result = NULL;
    }

    // @0x1424cb810
    void FocusManager::setFocus(const Value& result, Instances::fl_display::InteractiveObject* obj, UInt32 controllerIdx)
    {
        SF_UNUSED(result);
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        Ptr<GFx::InteractiveObject> newfocus;
        if (obj)
            newfocus = static_cast<GFx::InteractiveObject*>(obj->pDispObj.GetPtr());
        MovieImpl* proot = asvm.GetMovieImpl();
        Ptr<GFx::InteractiveObject> focused = proot->FocusGroups[proot->FocusGroupIndexes[controllerIdx]].LastFocused;
        if (focused != newfocus)
            asvm.GetMovieImpl()->SetKeyboardFocusTo(newfocus, controllerIdx, GFx_FocusMovedByAS);
    }

    // The focus-key state MovieImpl threads through InitFocusKeyInfo/ProcessFocusKey/FinalizeProcessFocusKey
    // (0x40 bytes on the stack; only what moveFocus touches is named).
    struct MS2_FocusKeyInfo
    {
        void*                       pFocusGroup;        // +0x00
        Ptr<GFx::InteractiveObject> CurFocused;         // +0x08
        int                         CurFocusIdx;        // +0x10
        UByte                       Unrecovered14[0x0c];
        UInt64                      Unrecovered20[3];   // +0x20
        UInt32                      Unrecovered38;      // +0x38 (its byte +0x3a is ManualFocus)
        bool                        Unrecovered3c;      // +0x3c

        MS2_FocusKeyInfo() : pFocusGroup(NULL), CurFocusIdx(-1), Unrecovered38(0), Unrecovered3c(false)
        {
            Unrecovered20[0] = Unrecovered20[1] = Unrecovered20[2] = 0;
        }
        bool& ManualFocus() { return reinterpret_cast<bool*>(&Unrecovered38)[2]; }
    };

    // Moves the focus as the key named keyToSimulate would ("up", "down", "left", "right", "tab", "shifttab"),
    // starting from startFromMovie or the controller's focused object; result is the object focused then.
    // MS2-FUNCTIONAL: the focus-key info is built through a local struct; the exe dereferences a null focus result
    // @0x1424cb2c0
    void FocusManager::moveFocus(SPtr<Instances::fl_display::InteractiveObject>& result, const ASString& keyToSimulate,
                                 Instances::fl_display::InteractiveObject* startFromMovie, bool includeFocusEnabledChars,
                                 UInt32 controllerIdx)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        if (!asvm.ExtensionsEnabled)
            return;
        MovieImpl* proot = asvm.GetMovieImpl();
        Ptr<GFx::InteractiveObject> startCh;
        if (startFromMovie)
            startCh = static_cast<GFx::InteractiveObject*>(startFromMovie->pDispObj.GetPtr());
        else
            startCh = proot->FocusGroups[proot->FocusGroupIndexes[controllerIdx]].LastFocused;

        const char* keystr = keyToSimulate.ToCStr();
        UInt32 keycode;
        bool shift = false;
        if (!strcmp(keystr, "up"))
            keycode = Key::Up;
        else if (!strcmp(keystr, "down"))
            keycode = Key::Down;
        else if (!strcmp(keystr, "left"))
            keycode = Key::Left;
        else if (!strcmp(keystr, "right"))
            keycode = Key::Right;
        else if (!strcmp(keystr, "tab"))
            keycode = Key::Tab;
        else if (!strcmp(keystr, "shifttab"))
        {
            keycode = Key::Tab;
            shift = true;
        }
        else
        {
            if (asvm.GetLog())
                asvm.GetLog()->LogWarning("moveFocus - invalid string id for key: '%s'", keyToSimulate.ToCStr());
            return;
        }

        InputEventsQueueEntry::KeyEntry ke;
        ke.Code = keycode;
        ke.KeysState = shift ? 1 : 0;
        ke.KeyboardIndex = (UInt8)controllerIdx;
        MS2_FocusKeyInfo info;
        FUN_142570d80(proot, &info, &ke, includeFocusEnabledChars, NULL);
        info.CurFocused = startCh;
        info.ManualFocus() = true;
        FUN_142572050(proot, 5, &ke, &info);
        FUN_14256eae0(proot, &info);
        if (info.CurFocused)
            result = static_cast<Instances::fl_display::InteractiveObject*>(
                ToAvmInteractiveObj15(info.CurFocused)->GetAS3Obj());
        else
            result = NULL;
    }

    // The focus group findFocus hands InitFocusKeyInfo (MovieImpl::FocusGroupDescr; the movie's own is unmodeled).
    struct MS2_FindFocusGroup
    {
        void*                                     pFocusRectNode;   // +0x00 (never set here)
        ArrayDH<Ptr<GFx::InteractiveObject> >     TabableArray;     // +0x08
        WeakPtr<GFx::InteractiveObject>           LastFocused;      // +0x28
        Ptr<CharacterHandle>                      ModalClip;        // +0x30
        UInt32                                    LastFocusKeyCode; // +0x38
        UInt64                                    LastFocusedRect[2]; // +0x40
        UInt16                                    FocusRectShown;   // +0x50

        MS2_FindFocusGroup(MemoryHeap* pheap) : pFocusRectNode(NULL), TabableArray(pheap), LastFocusKeyCode(0),
                                                FocusRectShown(0)
        {
            LastFocusedRect[0] = LastFocusedRect[1] = 0;
        }
    };

    // Finds the object the key named keyToSimulate would move the focus to, without moving it, within
    // parentMovie (or the modal clip); with loop, wraps around to the tabable object furthest the other way.
    // MS2-FUNCTIONAL: the focus group and key info are local structs; the group's focus rect node is not released
    // @0x1424c9f20
    void FocusManager::findFocus(SPtr<Instances::fl_display::InteractiveObject>& result, const ASString& keyToSimulate,
                                 Instances::fl_display::DisplayObjectContainer* parentMovie, bool loop,
                                 Instances::fl_display::InteractiveObject* startFromMovie,
                                 bool includeFocusEnabledChars, UInt32 controllerIdx)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        if (!asvm.ExtensionsEnabled)
            return;
        MovieImpl* proot = asvm.GetMovieImpl();
        Ptr<GFx::InteractiveObject> startCh;
        if (startFromMovie)
            startCh = static_cast<GFx::InteractiveObject*>(startFromMovie->pDispObj.GetPtr());
        else
            startCh = proot->FocusGroups[proot->FocusGroupIndexes[controllerIdx]].LastFocused;

        const char* keystr = keyToSimulate.ToCStr();
        UInt32 keycode;
        bool shift = false;
        if (!strcmp(keystr, "up"))
            keycode = Key::Up;
        else if (!strcmp(keystr, "down"))
            keycode = Key::Down;
        else if (!strcmp(keystr, "left"))
            keycode = Key::Left;
        else if (!strcmp(keystr, "right"))
            keycode = Key::Right;
        else if (!strcmp(keystr, "tab"))
            keycode = Key::Tab;
        else if (!strcmp(keystr, "shifttab"))
        {
            keycode = Key::Tab;
            shift = true;
        }
        else
            return;

        Ptr<GFx::DisplayObject> modal;
        if (parentMovie)
            modal = parentMovie->pDispObj.GetPtr();
        else
            modal = reinterpret_cast<GFx::DisplayObject*>(FUN_14256f820(proot, controllerIdx));

        InputEventsQueueEntry::KeyEntry ke;
        ke.Code = keycode;
        ke.KeysState = shift ? 1 : 0;
        ke.KeyboardIndex = (UInt8)controllerIdx;
        MS2_FocusKeyInfo info;
        MS2_FindFocusGroup group(asvm.GetMovieImpl()->GetMovieHeap());
        if (modal)
            group.ModalClip = modal->GetCharacterHandle();
        group.LastFocused = startCh;
        FUN_142570d80(proot, &info, &ke, includeFocusEnabledChars, &group);
        info.ManualFocus() = true;
        FUN_142572050(proot, 5, &ke, &info);

        if (info.CurFocused && info.CurFocused != startCh)
            result = static_cast<Instances::fl_display::InteractiveObject*>(
                ToAvmInteractiveObj15(info.CurFocused)->GetAS3Obj());
        else if (loop && group.TabableArray.GetSize() > 0)
        {
            UPInt n = group.TabableArray.GetSize();
            if (keycode == Key::Tab)
            {
                GFx::InteractiveObject* pch = shift ? group.TabableArray[n - 1].GetPtr() : group.TabableArray[0].GetPtr();
                result = static_cast<Instances::fl_display::InteractiveObject*>(ToAvmInteractiveObj15(pch)->GetAS3Obj());
                return;
            }
            const UByte* pinfo = reinterpret_cast<const UByte*>(&info);
            const float sentinel = 1.17549435e-38f;
            float best = sentinel;
            UPInt bestIdx = 0;
            for (UPInt i = 0; i < n; ++i)
            {
                Ptr<GFx::InteractiveObject> ch = group.TabableArray[i];
                if (!pinfo[0x3b] && !ch->IsTabable())
                    continue;
                if (!ch->IsFocusAllowed(proot, pinfo[0x38]))
                    continue;
                Render::Matrix2F m;
                ch->GetLevelMatrix(&m);
                RectF r;
                m.EncloseTransform(&r, ch->GetFocusRect());
                float v;
                bool better;
                switch (keycode)
                {
                case Key::Left:
                    v = r.x2;
                    better = best == sentinel || v > best;
                    break;
                case Key::Up:
                    v = r.y2;
                    better = best == sentinel || v > best;
                    break;
                case Key::Right:
                    v = r.x1;
                    better = best == sentinel || best > v;
                    break;
                case Key::Down:
                    v = r.y1;
                    better = best == sentinel || best > v;
                    break;
                default:
                    continue;
                }
                if (better)
                {
                    bestIdx = i;
                    best = v;
                }
            }
            result = static_cast<Instances::fl_display::InteractiveObject*>(
                ToAvmInteractiveObj15(group.TabableArray[bestIdx])->GetAS3Obj());
        }
        else
            result = NULL;
    }
    // @0x1424cc860
    void Extensions::visibleRectGet(SPtr<Instances::fl_geom::Rectangle>& result)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        Render::RectF r = asvm.GetMovieImpl()->AsMovieInterface()->GetVisibleFrameRect();
        Value args[] = { Value(r.x1), Value(r.y1), Value(r.Width()), Value(r.Height()) };
        Value v;
        static_cast<ASVM&>(GetVM()).RectangleClass->Construct(v, 4, args, true);
        result = static_cast<Instances::fl_geom::Rectangle*>(v.GetObject());
    }

    // @0x1424c9a20
    void IMEEx::SendLangBarMessage(const Value& result, Instances::fl_display::Sprite* mc, const ASString& command,
                                   const ASString& message)
    {
        SF_UNUSED(result);
        MovieImpl* movie = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        if (!movie)
            return;
        IMEManagerBase* pime = movie->GetIMEManager().GetPtr();
        if (pime)
            pime->SendLangBarMessage(mc->pDispObj.GetPtr(), command, message);
    }

    // MS2-FUNCTIONAL: identical but for the encoding of one shift (the exe's shr al, 1 takes an imm8)
    // @0x1424cab90
    void IMEEx::getIMECandidateListStyle(SPtr<Instances::fl_gfx::IMECandidateListStyle>& result)
    {
        GFx::IMECandidateListStyle st;
        ASVM& vm = static_cast<ASVM&>(GetVM());
        MovieImpl* movie = vm.GetMovieImpl();
        if (!movie)
            return;
        movie->GetIMECandidateListStyle(&st);
        if (!vm.ConstructInstance(result, GetVM().GetClass(StringDataPtr("scaleform.gfx.IMECandidateListStyle"))))
            return;
        if (st.HasTextColor())
            result->textColor = st.GetTextColor();
        if (st.HasBackgroundColor())
            result->backgroundColor = st.GetBackgroundColor();
        if (st.HasIndexBackgroundColor())
            result->indexBackgroundColor = st.GetIndexBackgroundColor();
        if (st.HasSelectedTextColor())
            result->selectedTextColor = st.GetSelectedTextColor();
        if (st.HasSelectedBackgroundColor())
            result->selectedBackgroundColor = st.GetSelectedBackgroundColor();
        if (st.HasSelectedIndexBackgroundColor())
            result->selectedIndexBackgroundColor = st.GetSelectedIndexBackgroundColor();
        if (st.HasFontSize())
            result->fontSize = st.GetFontSize();
        if (st.HasReadingWindowTextColor())
            result->readingWindowTextColor = st.GetReadingWindowTextColor();
        if (st.HasReadingWindowBackgroundColor())
            result->readingWindowBackgroundColor = st.GetReadingWindowBackgroundColor();
        if (st.HasReadingWindowFontSize())
            result->readingWindowFontSize = st.GetReadingWindowFontSize();
    }

    // MS2-FUNCTIONAL: the exe sets up an rbp frame for the style struct; same stores, flags and call
    // @0x1424cb980
    void IMEEx::setIMECandidateListStyle(const Value& result, Instances::fl_gfx::IMECandidateListStyle* pstyle)
    {
        SF_UNUSED(result);
        GFx::IMECandidateListStyle st;
        MovieImpl* movie = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        if (!movie)
            return;
        if (pstyle->textColor != -1)
            st.SetTextColor(pstyle->textColor);
        // the exe sets the selected text color twice
        if (pstyle->selectedTextColor != -1)
            st.SetSelectedTextColor(pstyle->selectedTextColor);
        if (pstyle->selectedTextColor != -1)
            st.SetSelectedTextColor(pstyle->selectedTextColor);
        if (pstyle->fontSize != -1)
            st.SetFontSize(pstyle->fontSize);
        if (pstyle->backgroundColor != -1)
            st.SetBackgroundColor(pstyle->backgroundColor);
        if (pstyle->selectedBackgroundColor != -1)
            st.SetSelectedBackgroundColor(pstyle->selectedBackgroundColor);
        if (pstyle->indexBackgroundColor != -1)
            st.SetIndexBackgroundColor(pstyle->indexBackgroundColor);
        if (pstyle->selectedIndexBackgroundColor != -1)
            st.SetSelectedIndexBackgroundColor(pstyle->selectedIndexBackgroundColor);
        if (pstyle->readingWindowTextColor != -1)
            st.SetReadingWindowTextColor(pstyle->readingWindowTextColor);
        if (pstyle->readingWindowBackgroundColor != -1)
            st.SetReadingWindowBackgroundColor(pstyle->readingWindowBackgroundColor);
        if (pstyle->readingWindowFontSize != -1)
            st.SetReadingWindowFontSize(pstyle->readingWindowFontSize);
        movie->SetIMECandidateListStyle(st);
    }
}}

namespace Instances { namespace fl_media
{
    // @0x1424d18c0
    void Sound::bytesLoadedGet(UInt32& result)
    {
        result = 0;
        if (pSoundObject)
            result = pSoundObject->GetBytesLoaded();
    }

    // @0x1424d18f0
    void Sound::bytesTotalGet(SInt32& result)
    {
        result = 0;
        if (pSoundObject)
            result = pSoundObject->GetBytesTotal();
    }

    // @0x1424d1920
    void Sound::close(const Value& result)
    {
        SF_UNUSED(result);
        if (pSoundObject)
        {
            pSoundObject->Stop();
            pSoundObject = NULL;
        }
    }

    void Sound::id3Get(SPtr<Instances::fl_media::ID3Info>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method Sound::id3Get() is not implemented\n");
    }

    // @0x1424d1960
    SPtr<Instances::fl_media::ID3Info> Sound::id3Get()
    {
        SPtr<Instances::fl_media::ID3Info> result;
        id3Get(result);
        return result;
    }

    // @0x1424d1a80
    void Sound::lengthGet(Value::Number& result)
    {
        float v = 0;
        if (pSoundObject)
            v = pSoundObject->GetDuration();
        result = v;
    }

    // @0x1424d1ac0
    void Sound::load(const Value& result, Instances::fl_net::URLRequest* stream, Instances::fl_media::SoundLoaderContext* context)
    {
        SF_UNUSED(result);
        if (!pSoundObject)
            return;
        if (stream)
            SoundURL = stream->GetUrl().ToCStr();
        if (context)
            Streaming = context->bufferTime > 0;
        pSoundObject->LoadFile(SoundURL, Streaming);
    }

    // @0x1424d1b60
    void Sound::play(Value& result, Value::Number startTime, SInt32 loops, Instances::fl_media::SoundTransform* sndTransform)
    {
        Value v;
        Value r;
        VM& vm = GetVM();
        vm.Construct("flash.media.SoundChannel", v, 0, NULL, true);
        if (vm.IsException() || v.IsNullOrUndefined())
            return;

        SPtr<Instances::fl_media::SoundChannel> channel = static_cast<Instances::fl_media::SoundChannel*>(v.GetObject());
        channel->pSoundObject = pSoundObject;
        pChannel = channel;
        if (pSoundObject)
            pSoundObject->Play((int)startTime, loops);
        if (sndTransform)
            channel->soundTransformSet(r, sndTransform);
        result.Assign(channel);
    }

    // @0x1424d20e0
    void Sound::urlGet(ASString& result)
    {
        result.AssignNode(result.GetManager()->CreateStringNode(SoundURL.ToCStr(), SoundURL.GetSize()));
    }

    // @0x1424d1da0
    void SoundChannel::positionGet(Value::Number& result)
    {
        float v = 0;
        if (pSoundObject)
            v = pSoundObject->GetPosition();
        result = v;
    }

    // @0x1424d1ea0
    void SoundChannel::soundTransformGet(SPtr<Instances::fl_media::SoundTransform>& result)
    {
        Value v;
        VM& vm = GetVM();
        vm.Construct("flash.media.SoundTransform", v, 0, NULL, true);
        if (vm.IsException() || v.IsNullOrUndefined())
            return;

        SPtr<Instances::fl_media::SoundTransform> st = static_cast<Instances::fl_media::SoundTransform*>(v.GetObject());
        if (pSoundObject)
        {
            Value r;
            st->volumeSet(r, pSoundObject->GetVolume() / 100);
            st->Pan = pSoundObject->GetPan() / 100;
        }
        result = st;
    }

    // @0x1424d1e80
    SPtr<Instances::fl_media::SoundTransform> SoundChannel::soundTransformGet()
    {
        SPtr<Instances::fl_media::SoundTransform> result;
        soundTransformGet(result);
        return result;
    }

    // @0x1424d2070
    void SoundChannel::soundTransformSet(const Value& result, Instances::fl_media::SoundTransform* value)
    {
        SF_UNUSED(result);
        if (pSoundObject)
        {
            pSoundObject->SetVolume((int)(value->Volume * 100));
            pSoundObject->SetPan((int)(value->Pan * 100));
        }
    }

}}

// ---- flash.xml / flash.security: class traits, instance traits, classes and instances ----

namespace fl_xml
{
    extern const ClassInfo XMLDocumentCI;
    extern const ClassInfo XMLNodeCI;
    extern const ClassInfo XMLNodeTypeCI;
}

namespace fl_security
{
    extern const ClassInfo XMLSignatureValidatorCI;
}

namespace ClassTraits { namespace fl_security
{
    // @0x1424ccb60
    XMLSignatureValidator::XMLSignatureValidator(VM& vm)
        : Traits(vm, AS3::fl_security::XMLSignatureValidatorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_events::EventDispatcher(vm, AS3::fl_security::XMLSignatureValidatorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424cca40
    Pickable<Traits> XMLSignatureValidator::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) XMLSignatureValidator(vm));
    }
}}

namespace ClassTraits { namespace fl_xml
{
    // @0x1424cd0b0
    XMLDocument::XMLDocument(VM& vm)
        : Traits(vm, AS3::fl_xml::XMLDocumentCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_xml::XMLDocument(vm, AS3::fl_xml::XMLDocumentCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424ccf70
    Pickable<Traits> XMLDocument::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) XMLDocument(vm));
    }

    // @0x1424cd220
    XMLNode::XMLNode(VM& vm)
        : Traits(vm, AS3::fl_xml::XMLNodeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_xml::XMLNode(vm, AS3::fl_xml::XMLNodeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424cce30
    Pickable<Traits> XMLNode::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) XMLNode(vm));
    }

    // @0x1424cd3d0
    XMLNodeType::XMLNodeType(VM& vm)
        : Traits(vm, AS3::fl_xml::XMLNodeTypeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_xml::XMLNodeTypeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_xml::XMLNodeType(*this)));
    }

    // @0x1424ccce0
    Pickable<Traits> XMLNodeType::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) XMLNodeType(vm));
    }
}}

namespace Classes { namespace fl_xml
{
    // @0x1424cd4c0
    XMLNodeType::XMLNodeType(ClassTraits::Traits& t)
        : Class(t)
        , ELEMENT_NODE(1)
        , TEXT_NODE(3)
    {
    }
}}

namespace InstanceTraits { namespace fl_xml
{
    // @0x1424cd320
    XMLNode::XMLNode(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x78);
    }

    // @0x1424cdc00
    void XMLNode::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424cdb30
    Pickable<XMLNode::InstanceType> XMLNode::MakeInstance(XMLNode& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424cd1b0
    XMLDocument::XMLDocument(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x98);
    }

    // @0x1424cdb80
    void XMLDocument::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424cdab0
    Pickable<XMLDocument::InstanceType> XMLDocument::MakeInstance(XMLDocument& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
}}

namespace Instances { namespace fl_xml
{
    // @0x1424cd350
    XMLNode::XMLNode(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , nodeName(GetVM().GetStringManager().CreateEmptyString())
        , nodeType(0)
        , nodeValue(GetVM().GetStringManager().CreateEmptyString())
    {
    }

    // @0x1424cd1e0
    XMLDocument::XMLDocument(InstanceTraits::Traits& t)
        : XMLNode(t)
        , ignoreWhite(false)
    {
    }
}}

// ---- flash.media: class traits, instance traits, classes and instances ----

namespace fl_media
{
    extern const ClassInfo CameraCI;
    extern const ClassInfo ID3InfoCI;
    extern const ClassInfo MicrophoneCI;
    extern const ClassInfo SoundCI;
    extern const ClassInfo SoundChannelCI;
    extern const ClassInfo SoundLoaderContextCI;
    extern const ClassInfo SoundMixerCI;
    extern const ClassInfo SoundTransformCI;
}

namespace ClassTraits { namespace fl_media
{
    // @0x1424cf2b0
    Camera::Camera(VM& vm)
        : Traits(vm, AS3::fl_media::CameraCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_events::EventDispatcher(vm, AS3::fl_media::CameraCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_media::Camera(*this)));
    }

    // @0x1424ce240
    Pickable<Traits> Camera::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Camera(vm));
    }

    // @0x1424cf3c0
    ID3Info::ID3Info(VM& vm)
        : Traits(vm, AS3::fl_media::ID3InfoCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_media::ID3Info(vm, AS3::fl_media::ID3InfoCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424ce380
    Pickable<Traits> ID3Info::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ID3Info(vm));
    }

    // @0x1424cf5f0
    Microphone::Microphone(VM& vm)
        : Traits(vm, AS3::fl_media::MicrophoneCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_events::EventDispatcher(vm, AS3::fl_media::MicrophoneCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_media::Microphone(*this)));
    }

    // @0x1424ce4c0
    Pickable<Traits> Microphone::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Microphone(vm));
    }

    // @0x1424cf700
    Sound::Sound(VM& vm)
        : Traits(vm, AS3::fl_media::SoundCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_media::Sound(vm, AS3::fl_media::SoundCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424ce740
    Pickable<Traits> Sound::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Sound(vm));
    }

    // @0x1424cf880
    SoundChannel::SoundChannel(VM& vm)
        : Traits(vm, AS3::fl_media::SoundChannelCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_media::SoundChannel(vm, AS3::fl_media::SoundChannelCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424ce880
    Pickable<Traits> SoundChannel::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SoundChannel(vm));
    }

    // @0x1424cf9e0
    SoundLoaderContext::SoundLoaderContext(VM& vm)
        : Traits(vm, AS3::fl_media::SoundLoaderContextCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_media::SoundLoaderContext(vm, AS3::fl_media::SoundLoaderContextCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424ce9c0
    Pickable<Traits> SoundLoaderContext::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SoundLoaderContext(vm));
    }

    // @0x1424cfb50
    SoundMixer::SoundMixer(VM& vm)
        : Traits(vm, AS3::fl_media::SoundMixerCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_media::SoundMixerCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_media::SoundMixer(*this)));
    }

    // @0x1424cf170
    Pickable<Traits> SoundMixer::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SoundMixer(vm));
    }

    // @0x1424cfc60
    SoundTransform::SoundTransform(VM& vm)
        : Traits(vm, AS3::fl_media::SoundTransformCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_media::SoundTransform(vm, AS3::fl_media::SoundTransformCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424ce600
    Pickable<Traits> SoundTransform::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SoundTransform(vm));
    }
}}

namespace Classes { namespace fl_media
{
    // @0x1424cf390
    Camera::Camera(ClassTraits::Traits& t)
        : Class(t)
    {
    }

    // @0x1424cf6d0
    Microphone::Microphone(ClassTraits::Traits& t)
        : Class(t)
    {
    }

    // @0x1424cfc30
    SoundMixer::SoundMixer(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl_media
{
    // @0x1424cf4c0
    ID3Info::ID3Info(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x70);
    }

    // MS2-FUNCTIONAL: same source; the exe schedules the vftable store of the inlined ID3Info ctor before the first empty-string load
    // @0x1424d15d0
    void ID3Info::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }

    // MS2-FUNCTIONAL: same source; the exe schedules the vftable store and the empty-string loads of the inlined ID3Info ctor differently
    // @0x1424d1280
    Pickable<Instances::fl_media::ID3Info> ID3Info::MakeInstance(ID3Info& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424cf800
    Sound::Sound(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x78);
    }

    // @0x1424d13c0
    Pickable<Instances::fl_media::Sound> Sound::MakeInstance(Sound& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424d1700
    void Sound::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424cf980
    SoundChannel::SoundChannel(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x58);
    }

    // @0x1424d1450
    Pickable<Instances::fl_media::SoundChannel> SoundChannel::MakeInstance(SoundChannel& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424d1780
    void SoundChannel::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424cfae0
    SoundLoaderContext::SoundLoaderContext(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x48);
    }

    // @0x1424d14d0
    Pickable<Instances::fl_media::SoundLoaderContext> SoundLoaderContext::MakeInstance(SoundLoaderContext& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424d17e0
    void SoundLoaderContext::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424cfd60
    SoundTransform::SoundTransform(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x48);
    }

    // @0x1424d1550
    Pickable<Instances::fl_media::SoundTransform> SoundTransform::MakeInstance(SoundTransform& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424d1850
    void SoundTransform::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }
}}

namespace Instances { namespace fl_media
{
    // Forced inline: the exe inlines this ctor into both InstanceTraits MakeObject and MakeInstance; the out-of-line
    // copy is still emitted.
    // @0x1424cf4f0
    SF_INLINE ID3Info::ID3Info(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , album(GetVM().GetStringManager().CreateEmptyString())
        , artist(GetVM().GetStringManager().CreateEmptyString())
        , comment(GetVM().GetStringManager().CreateEmptyString())
        , genre(GetVM().GetStringManager().CreateEmptyString())
        , songName(GetVM().GetStringManager().CreateEmptyString())
        , track(GetVM().GetStringManager().CreateEmptyString())
        , year(GetVM().GetStringManager().CreateEmptyString())
    {
    }

    // @0x1424cf830
    Sound::Sound(InstanceTraits::Traits& t)
        : Instances::fl_events::EventDispatcher(t)
    {
        Streaming = false;
    }

    // @0x1424d0b60
    void Sound::DispatchEventComplete()
    {
        SPtr<fl_events::Event> evt =
            CreateEventObject(static_cast<ASVM&>(GetVM()).GetBuiltin(AS3Builtin_complete), false, false);
        evt->Target = this;
        DispatchSingleEvent(evt, false);
    }

    // @0x1424d0c20
    void Sound::DispatchEventIOError()
    {
        SPtr<fl_events::Event> evt = CreateIOErrorEventObject("soundIOError");
        evt->Target = this;
        DispatchSingleEvent(evt, false);
    }

    // @0x1424d0cd0
    void Sound::DispatchEventOpen()
    {
        SPtr<fl_events::Event> evt =
            CreateEventObject(static_cast<ASVM&>(GetVM()).GetBuiltin(AS3Builtin_open), false, false);
        evt->Target = this;
        DispatchSingleEvent(evt, false);
    }

    // @0x1424d0d90
    void Sound::DispatchEventSoundComplete()
    {
        if (pChannel)
            pChannel->DispatchEventSoundComplete();
    }

    // @0x1424d0ea0
    void SoundChannel::DispatchEventSoundComplete()
    {
        ASString type = GetVM().GetStringManager().CreateConstString("soundComplete");
        SPtr<fl_events::Event> evt = CreateEventObject(type, false, false);
        evt->Target = this;
        DispatchSingleEvent(evt, false);
    }

    // @0x1424d0fa0
    void Sound::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        Instances::fl_events::EventDispatcher::ForEachChild_GC(prcc, op);
        // the exe's GC ops take the owner as a third argument
        typedef void (*GcOpWithOwner)(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const ASRefCountBaseType** pchild,
                                      const ASRefCountBaseType& owner);
        if (pChannel.GetPtr())
            reinterpret_cast<GcOpWithOwner>(op)(prcc, const_cast<const ASRefCountBaseType**>(
                                                          reinterpret_cast<ASRefCountBaseType**>(pChannel.GetRawPtr())), *this);
    }

    // @0x1424d0820
    void Sound::AS3Constructor(unsigned argc, const Value* argv)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        pSoundObject = *SF_HEAP_NEW(AsMovieSlots(vm.GetMovieImpl())->GetHeap()) SoundObject(vm, this);
        if (pResource)
            pSoundObject->AttachResource(pResource);
        if (argc >= 1 && FUN_1425145d0(vm, argv[0], "flash.net.URLRequest"))
        {
            Instances::fl_net::URLRequest* stream = static_cast<Instances::fl_net::URLRequest*>(argv[0].GetObject());
            Instances::fl_media::SoundLoaderContext* context = NULL;
            if (argc > 1 && FUN_1425145d0(vm, argv[1], "flash.media.SoundLoaderContext"))
                // The exe reads the context from argv[0] (the URLRequest), not argv[1] (0x1424d08fb mov rsi,[rbp+0x10]).
                context = static_cast<Instances::fl_media::SoundLoaderContext*>(argv[0].GetObject());
            Value result;
            load(result, stream, context);
        }
    }

    // MS2-FUNCTIONAL: same control flow; the exe keeps found inverted and allocates the name/symbol stack slots the other way round
    // @0x1424d0a00
    bool Sound::CreateLibraryObject()
    {
        if (pResource)
            return false;
        ASVM& vm = static_cast<ASVM&>(GetVM());
        MovieDefImpl* pdefImpl = FUN_14250d8f0(vm, this);
        if (!pdefImpl || !GetTraits().IsAbcObject())
            return false;
        ASString name = GetTraits().GetQualifiedName(Traits::qnfWithDot);
        ResourceBindData data;
        bool found;
        {
            String symbol(name.ToCStr());
            found = vm.GetMovieImpl()->FindExportedResource(pdefImpl, &data, symbol);
        }
        if (!found)
            return false;
        if (data.pResource && (data.pResource->GetResourceTypeCode() & Resource::MakeTypeCode(Resource::RT_SoundSample)))
            pResource = static_cast<SoundResource*>(data.pResource.GetPtr());
        return true;
    }

    // MS2-FUNCTIONAL: inlined CreateLibraryObject; the exe keeps found inverted
    // @0x1424d1130
    void Sound::InitInstance(bool extCall)
    {
        if (!extCall)
            CreateLibraryObject();
    }

    // @0x1424cf9b0
    SoundChannel::SoundChannel(InstanceTraits::Traits& t)
        : Instances::fl_events::EventDispatcher(t)
    {
    }

    // @0x1424cfb10
    SoundLoaderContext::SoundLoaderContext(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , bufferTime(1000)
        , checkPolicyFile(false)
    {
    }

    // @0x1424cfd90
    SoundTransform::SoundTransform(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , Volume(1.0)
        , Pan(0.0)
    {
    }

    // @0x1424d09a0
    void SoundTransform::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc > 0)
        {
            argv[0].Convert2Number(Volume);
            if (argc > 1)
                argv[1].Convert2Number(Pan);
        }
    }

    // @0x1424d2140
    void SoundTransform::volumeGet(Value::Number& result)
    {
        result = Volume;
    }

    // @0x1424d2150
    void SoundTransform::volumeSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        Volume = value;
    }
}}

namespace InstanceTraits { namespace fl_gfx
{
    // MS2-FUNCTIONAL: the exe inlines the instance ctor (whole-program optimisation); here it is a call
    // @0x1424c9700
    void GamePadAnalogEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance ctor (whole-program optimisation); here it is a call
    // @0x1424c9760
    void IMECandidateListStyle::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance ctor (whole-program optimisation); here it is a call
    // @0x1424c97e0
    void IMEEventEx::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance ctor (whole-program optimisation); here it is a call
    // @0x1424c9860
    void KeyboardEventEx::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance ctor (whole-program optimisation); here it is a call
    // @0x1424c98c0
    void MouseCursorEvent::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance ctor (whole-program optimisation); here it is a call
    // @0x1424c9950
    void MouseEventEx::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance ctor (whole-program optimisation); here it is a call
    // @0x1424c99c0
    void TextEventEx::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }
}}
// noinline: the derived ctors call it out of line.
// @0x1424d6480
__declspec(noinline) AvmInteractiveObj::AvmInteractiveObj(InteractiveObject* pdispObj)
    : AvmDisplayObj(pdispObj), MouseOverCnt(0), IntFlags(0)
{
    pdispObj->TabIndex = -1;
}

// The exe's vftables of the AS3 parts of buttons, text fields and static text; these classes are not modelled
// beyond their size, so their ctors store them by hand.
extern void* const AvmButton_vftable[];
extern void* const AvmButton_vftable_30[];
extern void* const AvmButton_vftable_40[];
extern void* const AvmTextField_vftable[];
extern void* const AvmTextField_vftable_30[];
extern void* const AvmTextField_vftable_40[];
extern void* const AvmStaticText_vftable[];

extern void* const ShapeObject_vftable[];
extern void* const ShapeObject_vftable_18[];
extern void* const ShapeObject_vftable_90[];

// A shape on the display list: a DisplayObject with its AS3 part at +0x90, then the shape def (+0xc0) and the
// drawing context of the AS3 Graphics API (+0xc8, made on first use).
// MS2-PIN: ??_7ShapeObject@AS3@GFx@Scaleform@@6B@ 0x14317c210
// ShapeObject is opaque (its virtuals are unrecovered): its bases are built in place and the exe's vftables stored.
// MS2-FUNCTIONAL: same code; the exe orders the inlined AvmDisplayObj member stores differently (scheduling)
// @0x1424d98a0
ShapeObject::ShapeObject(CharacterDef* pdef, ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id)
{
    UByte* const self = reinterpret_cast<UByte*>(this);   // Data is at +8 behind the vptr of the opaque class
    FUN_1425f07e0(this, pasRoot, pparent, id);
    new (self + 0x90) AvmDisplayObj(reinterpret_cast<DisplayObject*>(this));
    *reinterpret_cast<void* const**>(self + 0x00) = ShapeObject_vftable;
    *reinterpret_cast<void* const**>(self + 0x18) = ShapeObject_vftable_18;
    *reinterpret_cast<void* const**>(self + 0x90) = ShapeObject_vftable_90;
    if (pdef)
        reinterpret_cast<Resource*>(pdef)->AddRef();
    *reinterpret_cast<CharacterDef**>(self + 0xc0) = pdef;
    *reinterpret_cast<void**>(self + 0xc8) = NULL;
}

extern void* const AvmBitmap_vftable[];
extern void* const AvmBitmap_vftable_18[];
extern void* const AvmBitmap_vftable_90[];

// A bitmap on the display list: +0xc0 the image resource, +0xc8 the movie that binds it. The image comes from the
// character's resource, or, for a valid id, from the movie's resource binding; only image resources are kept.
// AvmBitmap is opaque (its virtuals are unrecovered): its bases are built in place and the exe's vftables stored.
// MS2-FUNCTIONAL: same code; the exe orders the inlined AvmDisplayObj member stores differently (scheduling)
// @0x1424d6270
AvmBitmap::AvmBitmap(ASMovieRootBase* pasRoot, const CharacterCreateInfo& ccinfo, InteractiveObject* pparent, ResourceId id)
{
    FUN_1425f07e0(this, pasRoot, pparent, id);
    new (Data + 0x90) AvmDisplayObj(reinterpret_cast<DisplayObject*>(this));
    *reinterpret_cast<void* const**>(Data + 0x00) = AvmBitmap_vftable;
    *reinterpret_cast<void* const**>(Data + 0x18) = AvmBitmap_vftable_18;
    *reinterpret_cast<void* const**>(Data + 0x90) = AvmBitmap_vftable_90;
    Resource*& pimage = *reinterpret_cast<Resource**>(Data + 0xc0);
    MovieDefImpl*& pdefImpl = *reinterpret_cast<MovieDefImpl**>(Data + 0xc8);
    pimage = NULL;
    MovieDefImpl* pdef = ccinfo.pBindDefImpl;
    if (pdef)
        reinterpret_cast<Resource*>(pdef)->AddRef();
    pdefImpl = pdef;
    Resource* pres = ccinfo.pResource;
    if (id != ResourceId(ResourceId::InvalidId))
    {
        ResourceHandle rh;
        if (pdef->GetDataDef()->GetResourceHandle(&rh, id))
            pres = FUN_14250d840(&rh, &pdefImpl->GetResourceBinding());
    }
    if (pres && (pres->GetResourceTypeCode() & 0xff00) == Resource::MakeTypeCode(Resource::RT_Image))
    {
        pres->AddRef();
        if (pimage)
            pimage->Release();
        pimage = pres;
    }
}

// A button takes part in tab navigation by default.
// MS2-FUNCTIONAL: AvmButton is opaque; its AvmInteractiveObj part is built in place and the exe's vftables stored
// @0x1424d63e0
AvmButton::AvmButton(Button* pbtn)
{
    FUN_1424d6480(this, reinterpret_cast<InteractiveObject*>(pbtn));
    *reinterpret_cast<void* const**>(Data + 0x00) = AvmButton_vftable;
    *reinterpret_cast<void* const**>(Data + 0x30) = AvmButton_vftable_30;
    *reinterpret_cast<void* const**>(Data + 0x40) = AvmButton_vftable_40;
    reinterpret_cast<InteractiveObject*>(pbtn)->Flags |= InteractiveObject::Mask_TabEnabled;
}

// MS2-FUNCTIONAL: AvmStaticText is opaque; its AvmDisplayObj part is built in place and the exe's vftable stored
// @0x1424d6650
AvmStaticText::AvmStaticText(StaticTextCharacter* ptxt)
{
    new (this) AvmDisplayObj(reinterpret_cast<DisplayObject*>(ptxt));
    *reinterpret_cast<void* const**>(Data) = AvmStaticText_vftable;
}

// An AS3 text field starts with the caret at 0.
// MS2-FUNCTIONAL: AvmTextField is opaque; its AvmInteractiveObj part is built in place and the exe's vftables stored
// @0x1424d66b0
AvmTextField::AvmTextField(TextField* ptxt)
{
    FUN_1424d6480(this, reinterpret_cast<InteractiveObject*>(ptxt));
    *reinterpret_cast<void* const**>(Data + 0x00) = AvmTextField_vftable;
    *reinterpret_cast<void* const**>(Data + 0x30) = AvmTextField_vftable_30;
    *reinterpret_cast<void* const**>(Data + 0x40) = AvmTextField_vftable_40;
    *reinterpret_cast<UInt32*>(reinterpret_cast<UByte*>(ptxt) + 0xfc) |= 2;
    ptxt->SetSelection(0, 0);
}

// MS2-FUNCTIONAL: same code; the byte count lives in rdi, the exe has it in rbx
// @0x1424d6590
AvmSprite::AvmSprite(Sprite* pspr)
    : AvmDisplayObjContainer(reinterpret_cast<DisplayObjContainer*>(pspr))
{
    InitActionsExecutedSize = GetSprite()->pDef->GetFrameCount();
    UPInt bytes = (InitActionsExecutedSize + 7) >> 3;
    InitActionsExecuted = static_cast<UByte*>(Memory::AllocAutoHeap(&InitActionsExecuted, bytes,
                                                                    AllocInfo(StatMV_ActionScript_Mem, 0, 0)));
    memset(InitActionsExecuted, 0, bytes);
    SprFlags = 0;
    GetSprite()->Flags &= ~Sprite::Flags_LockRoot;
}

// A register file starts with one page of the smallest size and no registers reserved.
// @0x1424dc080
ValueRegisterFile::ValueRegisterFile()
    : Unk00(0), Unk02(0), MaxAllocatedPageSize(0), pRF(NULL), pCurrentPage(NULL), pReservedPage(NULL)
{
    pCurrentPage = NewPage(0);
    pCurrentPage->pNext = NULL;
    pCurrentPage->pPrev = NULL;
    pRF = pCurrentPage->Values;
}

// An operand stack starts with one page of 64 values and a reservation of one.
// @0x1424dc0e0
ValueStack::ValueStack()
    : pCurrent(NULL), pStack(NULL), pCurrentPage(NULL), pReserved(NULL)
{
    ReservedNum = 0;
    pCurrentPage = NewPage(64);
    pCurrentPage->pNext = NULL;
    pCurrentPage->pPrev = NULL;
    pCurrentPage->pFirst = NULL;
    pCurrentPage->pCurrent = NULL;
    pStack = pCurrentPage->Values;
    pCurrent = pStack - 1;
    Reserve(1);
}

// The display object behind an AS3 Loader: a plain container with no character definition of its own.
class AvmLoader : public DisplayObjContainer, public AvmDisplayObjContainer
{
public:
    AvmLoader(ASMovieRootBase* pasRoot, MovieDefImpl* pdefImpl, InteractiveObject* pparent, ResourceId id);
    virtual ~AvmLoader();   // sfr_as3_16

    virtual CharacterDef* GetCharacterDef() const;   // 0x142507b40, returns NULL
    // The AvmDisplayObj class-name queries: "flash.display.Loader".
    virtual const char* GetDefaultASClassName() const;          // 0x142508940
    virtual String&     GetASClassName(String* className) const; // 0x142505fa0
};

// @0x1424d6500
AvmLoader::AvmLoader(ASMovieRootBase* pasRoot, MovieDefImpl* pdefImpl, InteractiveObject* pparent, ResourceId id)
    : DisplayObjContainer(pdefImpl, pasRoot, pparent, id), AvmDisplayObjContainer(this)
{
}

// The AS3 stage: the top container holding the root movie clip.
class Stage : public DisplayObjContainer
{
public:
    Ptr<DisplayObjContainer> pRoot;                   // +0x110
    Ptr<InteractiveObject>   FrameCounterObj;         // +0x118
    ASString                 CurrentStageOrientation; // +0x120
    unsigned                 MouseCursorEventCnt;     // +0x128

    Stage(MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id);

    // The container overrides (bodies in other units; same declarations as as3_stage.h).
    virtual void        ForceShutdown();                                    // 54 0x142504860
    virtual InteractiveObject* GetTopParent(bool ignoreLockRoot = false) const; // 62 0x14250f870
protected:
    virtual ASString    CreateNewInstanceName() const;                      // 76 0x1424f3980
public:
    virtual bool        IsFocusEnabled(FocusMovedType = GFx_FocusMovedByKeyboard) const; // 83 0x142514310
    virtual void        PropagateMouseEvent(const EventId& id);             // 93 0x14251f570
    virtual unsigned    GetCurrentFrame() const;                            // 101 0x1425084e0
    virtual bool        GetLabeledFrame(const char* plabel, unsigned* frameNumber, bool translateNumbers = true); // 102 0x14250b370
    virtual const String* GetFrameLabel(unsigned frame, unsigned* exactFrame = NULL); // 103 0x142509dd0
    virtual void        GotoFrame(unsigned targetFrameNumber);              // 104 0x142510d20
    virtual unsigned    GetLoadingFrame() const;                            // 105 0x14250b3b0
    virtual void        ExecuteFrame0Events();                              // 106 0x1424fe620
    virtual void        OnInsertionAsLevel(int level);                      // 119 0x14251a110
    virtual void        ExecuteFrameTags(unsigned frame);                   // 121 0x1424feaf0
};

// @0x1424d9b50
Stage::Stage(MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id)
    : DisplayObjContainer(pbindingDefImpl, pasRoot, pparent, id),
      CurrentStageOrientation(GetStringManager()->GetEmptyStringNode())
{
    DisplayObjectBase::Flags |= DisplayObjectBase::Mask_Loaded;
    DisplayObject::Flags |= DisplayObject::Mask_TimelineObject;
    MouseCursorEventCnt = 0;
}

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// ---- Out-of-line template instances (COMDATs the linker placed in this range)
namespace Scaleform {

namespace GFx {
// MS2-FUNCTIONAL: cl folds the two flag-bit tests into one mask compare; the exe tests the bits separately
// @0x1424d2820
template<>
void InteractiveObject::ModifyOptimizedPlayListLocal<Sprite>()
{
    switch (static_cast<Sprite*>(this)->Sprite::CheckAdvanceStatus(IsInOptimizedPlayList()))
    {
    case 1:  AddToOptimizedPlayList(); break;
    case -1: MarkToRemoveFromOptimizedPlayList(); break;
    }
}
} // namespace GFx

// HashSetBase::add instances: the node type N with its own hash functors, allocator A and entry E.
template<class N, class A, class E>
struct MS2_HashSetOf
{
    typedef HashSetBase<N, typename N::NodeHashF, typename N::NodeAltHashF, A, E> Type;
};
typedef HashNode<int, AutoPtr<ArrayLH<WeakPtr<GFx::DisplayObject>, 2> >, IdentityHash<int> > MS2_DepthToObjsNode;
typedef MS2_HashSetOf<MS2_DepthToObjsNode, AllocatorLH<int, 2>,
                      HashsetNodeEntry<MS2_DepthToObjsNode, MS2_DepthToObjsNode::NodeHashF> >::Type MS2_DepthToObjsSet;
typedef HashNode<GFx::ASString, GFx::AS3::Value, GFx::ASStringHashFunctor> MS2_StringValueNode;
typedef MS2_HashSetOf<MS2_StringValueNode, AllocatorLH<GFx::ASString, GFx::StatMV_ASString_Mem>,
                      HashsetNodeEntry<MS2_StringValueNode, MS2_StringValueNode::NodeHashF> >::Type MS2_StringValueSet;
typedef HashNode<GFx::AS3::GASRefCountBase*, GFx::AS3::WeakProxy*, FixedSizeHash<GFx::AS3::GASRefCountBase*> > MS2_WeakProxyNode;
typedef MS2_HashSetOf<MS2_WeakProxyNode, AllocatorGH<GFx::AS3::GASRefCountBase*, 2>,
                      HashsetCachedNodeEntry<MS2_WeakProxyNode, MS2_WeakProxyNode::NodeHashF> >::Type MS2_WeakProxySet;
typedef HashNode<Ptr<GFx::ASStringNode>, UInt32, GFx::AS3::ASStringNodePtrHashFunc> MS2_SlotNameNode;
// MS2-FUNCTIONAL: same template body; the exe inlines CheckExpand/setRawCapacity and the entry copy, here they are calls
// @0x1424d2be0
template void MS2_DepthToObjsSet::add<MS2_DepthToObjsNode>(void*, const MS2_DepthToObjsNode&, UPInt);
// MS2-FUNCTIONAL: same template body; the exe inlines CheckExpand/setRawCapacity, here it is a call
// @0x1424d3530
template void decltype(GFx::AS3::Slots::SetType::mHash)::BaseType::add<MS2_SlotNameNode>(
    void*, const MS2_SlotNameNode&, UPInt);
// MS2-FUNCTIONAL: same template body; the exe inlines CheckExpand/setRawCapacity and the entry copy, here they are calls
// @0x1424d3870
template void MS2_StringValueSet::add<MS2_StringValueNode>(void*, const MS2_StringValueNode&, UPInt);
// MS2-FUNCTIONAL: same template body; the exe inlines CheckExpand/setRawCapacity and the entry copy, here they are calls
// @0x1424d39f0
template void MS2_DepthToObjsSet::add<MS2_DepthToObjsNode::NodeRef>(void*, const MS2_DepthToObjsNode::NodeRef&, UPInt);
// @0x1424d40a0
template void MS2_WeakProxySet::add<MS2_WeakProxyNode::NodeRef>(void*, const MS2_WeakProxyNode::NodeRef&, UPInt);
typedef HashNode<GFx::AS3::Object::DynAttrsKey, GFx::AS3::Value, GFx::AS3::Object::DynAttrsKeyHashFunctor> MS2_DynAttrsNode;
// MS2-FUNCTIONAL: same template body; register allocation and the save of the scratch registers differ
// @0x1424d4600
template void decltype(GFx::AS3::Object::DynAttrsType::mHash)::BaseType::add<MS2_DynAttrsNode::NodeRef>(
    void*, const MS2_DynAttrsNode::NodeRef&, UPInt);
// @0x1424d4a40
template void decltype(GFx::AS3::Slots::SetType::mHash)::BaseType::add<MS2_SlotNameNode::NodeRef>(
    void*, const MS2_SlotNameNode::NodeRef&, UPInt);
// The VM's registerClassAlias map (alias -> class).
typedef HashUncachedLH<GFx::ASString, GFx::AS3::Class*, GFx::AS3::ASStringNodeHashFunc, GFx::AS3::StatMV_VM_VM_Mem>
    MS2_AliasClassHash;
typedef HashNode<GFx::ASString, GFx::AS3::Class*, GFx::AS3::ASStringNodeHashFunc> MS2_AliasClassNode;
// @0x1424d4c10
template void decltype(MS2_AliasClassHash::mHash)::BaseType::add<MS2_AliasClassNode::NodeRef>(
    void*, const MS2_AliasClassNode::NodeRef&, UPInt);
// MS2-FUNCTIONAL: the exe has one folded copy for every identically laid out node type; this is its out-of-line setRawCapacity
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@PEAVClass@AS3@23@VASStringNodeHashFunc@523@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEJ@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@PEAVClass@AS3@23@VASStringNodeHashFunc@523@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x1425422c0
template void decltype(MS2_AliasClassHash::mHash)::BaseType::setRawCapacity(void*, UPInt);
// MS2-FUNCTIONAL: byte-identical body; the exe calls the folded CheckExpand copy at 0x1424ef090, the symbol table binds ours to 0x1424eefa0
// @0x1424d3710
template void decltype(MS2_AliasClassHash::mHash)::BaseType::add<MS2_AliasClassNode>(void*, const MS2_AliasClassNode&, UPInt);
// MS2-FUNCTIONAL: same template body; register allocation and the save of the scratch registers differ
// @0x1424d4dd0
template void MS2_StringValueSet::add<MS2_StringValueNode::NodeRef>(void*, const MS2_StringValueNode::NodeRef&, UPInt);
// String node -> index maps of the VM (HashLH<ASStringNode*, SInt64>): the nodes hash by their stored HashFlags.
typedef HashNode<GFx::ASStringNode*, SInt64, GFx::AS3::ASStringNodeHashFunc> MS2_StringIndexNode;
typedef MS2_HashSetOf<MS2_StringIndexNode, AllocatorLH<GFx::ASStringNode*, GFx::AS3::StatMV_VM_SlotInfoHash_Mem>,
                      HashsetNodeEntry<MS2_StringIndexNode, MS2_StringIndexNode::NodeHashF> >::Type MS2_StringIndexSet;
// @0x1424d3f10
template void MS2_StringIndexSet::add<MS2_StringIndexNode::NodeRef>(void*, const MS2_StringIndexNode::NodeRef&, UPInt);
// The set of roots the collector keeps alive (HashSetLH<SPtr<GASRefCountBase>> by pointer value).
typedef GFx::AS3::SPtr<GFx::AS3::GASRefCountBase> MS2_GCRootPtr;
typedef HashSetBase<MS2_GCRootPtr, FixedSizeHash<MS2_GCRootPtr>, FixedSizeHash<MS2_GCRootPtr>, AllocatorLH<MS2_GCRootPtr, 2>,
                    HashsetCachedEntry<MS2_GCRootPtr, FixedSizeHash<MS2_GCRootPtr> > > MS2_GCRootSet;
// MS2-FUNCTIONAL: same template body; the exe calls CheckExpand out of line, here it is inlined
// @0x1424d5020
template void MS2_GCRootSet::add<MS2_GCRootPtr>(void*, const MS2_GCRootPtr&, UPInt);
// Adding by raw pointer: the entry is built from a temporary SPtr.
// MS2-FUNCTIONAL: register allocation differs (the exe saves rdi late and swaps rbx/rdi)
// @0x1424d29d0
template void MS2_GCRootSet::add<GFx::AS3::GASRefCountBase*>(void*, GFx::AS3::GASRefCountBase* const&, UPInt);
// The VM's set of script global objects (HashSetLH<SPtr<GlobalObjectScript>> by pointer value).
typedef GFx::AS3::SPtr<GFx::AS3::Instances::fl::GlobalObjectScript> MS2_ScriptPtr;
typedef HashSetBase<MS2_ScriptPtr, FixedSizeHash<MS2_ScriptPtr>, FixedSizeHash<MS2_ScriptPtr>, AllocatorLH<MS2_ScriptPtr, 2>,
                    HashsetCachedEntry<MS2_ScriptPtr, FixedSizeHash<MS2_ScriptPtr> > > MS2_ScriptSet;
// @0x1424d5180
template void MS2_ScriptSet::add<MS2_ScriptPtr>(void*, const MS2_ScriptPtr&, UPInt);
// A VMAbcFile's interned namespaces by constant pool index; the VM adds a whole node to another map of the type.
typedef GFx::AS3::AbcMultinameHash<GFx::AS3::SPtr<GFx::AS3::Instances::Namespace> >::Key MS2_AbcNsKey;
typedef HashNode<MS2_AbcNsKey, GFx::AS3::SPtr<GFx::AS3::Instances::Namespace>, FixedSizeHash<MS2_AbcNsKey> > MS2_AbcNsNode;
typedef MS2_HashSetOf<MS2_AbcNsNode, AllocatorLH<MS2_AbcNsKey, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
                      HashsetCachedNodeEntry<MS2_AbcNsNode, MS2_AbcNsNode::NodeHashF> >::Type MS2_AbcNsSet;
// @0x1424d4850
template void MS2_AbcNsSet::add<MS2_AbcNsNode::NodeRef>(void*, const MS2_AbcNsNode::NodeRef&, UPInt);
// @0x1424d3380
template void MS2_AbcNsSet::add<MS2_AbcNsNode>(void*, const MS2_AbcNsNode&, UPInt);
// A VMAbcFile's function closure traits by method index.
typedef HashNode<UInt32, GFx::AS3::SPtr<GFx::AS3::InstanceTraits::Function>, FixedSizeHash<UInt32> > MS2_FunctionTraitsNode;
typedef MS2_HashSetOf<MS2_FunctionTraitsNode, AllocatorLH<UInt32, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
                      HashsetCachedNodeEntry<MS2_FunctionTraitsNode, MS2_FunctionTraitsNode::NodeHashF> >::Type
    MS2_FunctionTraitsSet;
// @0x1424d3d50
template void MS2_FunctionTraitsSet::add<MS2_FunctionTraitsNode::NodeRef>(void*, const MS2_FunctionTraitsNode::NodeRef&,
                                                                        UPInt);
// A VMAbcFile's activation traits by method body (+0x90), made on first use with the name "activation@...".
typedef HashNode<const GFx::AS3::Abc::MethodBodyInfo*, GFx::AS3::SPtr<GFx::AS3::InstanceTraits::Traits>,
                 FixedSizeHash<const GFx::AS3::Abc::MethodBodyInfo*> > MS2_ActivationTraitsNode;
typedef MS2_HashSetOf<MS2_ActivationTraitsNode, AllocatorLH<const GFx::AS3::Abc::MethodBodyInfo*, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
                      HashsetCachedNodeEntry<MS2_ActivationTraitsNode, MS2_ActivationTraitsNode::NodeHashF> >::Type
    MS2_ActivationTraitsSet;
// @0x1424d4430
template void MS2_ActivationTraitsSet::add<MS2_ActivationTraitsNode::NodeRef>(void*, const MS2_ActivationTraitsNode::NodeRef&,
                                                                            UPInt);
// @0x1424d3200
template void MS2_ActivationTraitsSet::add<MS2_ActivationTraitsNode>(void*, const MS2_ActivationTraitsNode&, UPInt);
// A local map of 0x1424f4a90 (sfr_as3_17): a UInt32 key to a slot position, the absolute index and the slots it is in.
struct MS2_SlotPos
{
    SPInt       Ind;
    const void* pSlots;

    MS2_SlotPos(const MS2_SlotPos& other) : Ind(other.Ind), pSlots(other.pSlots) {}
    MS2_SlotPos& operator=(const MS2_SlotPos& other)
    {
        Ind    = other.Ind;
        pSlots = other.pSlots;
        return *this;
    }
};
typedef HashNode<UInt32, MS2_SlotPos, FixedSizeHash<UInt32> > MS2_SlotPosNode;
typedef MS2_HashSetOf<MS2_SlotPosNode, AllocatorDH<UInt32, 2>,
                      HashsetCachedNodeEntry<MS2_SlotPosNode, MS2_SlotPosNode::NodeHashF> >::Type MS2_SlotPosSet;
// @0x1424d3ba0
template void MS2_SlotPosSet::add<MS2_SlotPosNode::NodeRef>(void*, const MS2_SlotPosNode::NodeRef&, UPInt);
// @0x1424d2d50
template void MS2_SlotPosSet::add<MS2_SlotPosNode>(void*, const MS2_SlotPosNode&, UPInt);
// The movie root's loaded movie definitions (+0x6e8), keyed by identity, with a use count.
struct MS2_LoadedMovieDefInfo
{
    Ptr<GFx::MovieDefImpl> pMovieDef;
    unsigned               UseCnt;

    MS2_LoadedMovieDefInfo(GFx::MovieDefImpl* def) : pMovieDef(def), UseCnt(1) {}
};
typedef HashNode<GFx::MovieDefImpl*, MS2_LoadedMovieDefInfo, IdentityHash<GFx::MovieDefImpl*> > MS2_LoadedMovieDefNode;
typedef MS2_HashSetOf<MS2_LoadedMovieDefNode, AllocatorLH<GFx::MovieDefImpl*, 2>,
                      HashsetNodeEntry<MS2_LoadedMovieDefNode, MS2_LoadedMovieDefNode::NodeHashF> >::Type
    MS2_LoadedMovieDefSet;
// @0x1424d4220
template void MS2_LoadedMovieDefSet::add<MS2_LoadedMovieDefNode::NodeRef>(void*, const MS2_LoadedMovieDefNode::NodeRef&,
                                                                        UPInt);
// @0x1424d3030
template void MS2_LoadedMovieDefSet::add<MS2_LoadedMovieDefNode>(void*, const MS2_LoadedMovieDefNode&, UPInt);
// A local set of object pointers in 0x1424dfbf0 (sfr_as3_16), hashed bytewise.
typedef HashSetBase<const void*, FixedSizeHash<const void*>, FixedSizeHash<const void*>, AllocatorDH<const void*, 2>,
                    HashsetCachedEntry<const void*, FixedSizeHash<const void*> > > MS2_ObjPtrSet;
// @0x1424d2890
template void MS2_ObjPtrSet::add<const void*>(void*, const void* const&, UPInt);
// A number formatted on its own ("{0}").
// @0x1424d2410
template String AsString<double>(const double&);
}
// AsString of an unsigned int (the exe's unfolded copy; it formats through the zero-extending LongFormatter ctor).
// @0x1424d22a0
Scaleform::String FUN_1424d22a0(const unsigned int& v)
{
    Scaleform::String result;
    Scaleform::Format(result, "{0}", v);
    return result;
}
namespace Scaleform {
// Binary search over a sorted index array with a plain comparison function.
// @0x1424d2780
template UPInt Alg::LowerBoundSliced<ArrayDH_POD<UPInt, 0x148>, UPInt, bool (*)(const UPInt&, const UPInt&)>(
    const ArrayDH_POD<UPInt, 0x148>&, UPInt, UPInt, const UPInt&, bool (*)(const UPInt&, const UPInt&));
// @0x1424dc260
template ArrayDataBase<Render::FillStyleType, AllocatorLH<Render::FillStyleType, 2>, ArrayDefaultPolicy>::~ArrayDataBase();
// @0x1424dc350
template ArrayDataBase<Render::StrokeStyleType, AllocatorLH<Render::StrokeStyleType, 2>, ArrayDefaultPolicy>::~ArrayDataBase();
// @0x1424dc440
template ArrayDataBase<GFx::AS3::SPtr<GFx::ASStringNode>,
                       AllocatorLH<GFx::AS3::SPtr<GFx::ASStringNode>, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
// The interned namespace sets of a VMAbcFile (+0x40).
// @0x1424dc530
template ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::NamespaceSet>,
                       AllocatorLH<GFx::AS3::SPtr<GFx::AS3::NamespaceSet>, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
// The byte code of a VMAbcFile's methods (+0xb8; word code).
// @0x1424dc3d0
template ArrayDataBase<ArrayLH_POD<UPInt, GFx::AS3::StatMV_VM_AbcFile_Mem>,
                       AllocatorLH<ArrayLH_POD<UPInt, GFx::AS3::StatMV_VM_AbcFile_Mem>, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
// The class traits loaded from a VMAbcFile (+0xa0).
// @0x1424dc5b0
template ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::ClassTraits::Traits>,
                       AllocatorLH<GFx::AS3::SPtr<GFx::AS3::ClassTraits::Traits>, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
// @0x1424dc630
template ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, 2>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
// The files a VMAbcFile loaded (+0x78).
// @0x1424dc6b0
template ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>,
                       AllocatorLH<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
// The exception tables of a VMAbcFile's methods (+0xd0).
// @0x1424dc800
template ArrayDataBase<GFx::AS3::Abc::MethodBodyInfo::Exception,
                       AllocatorLH<GFx::AS3::Abc::MethodBodyInfo::Exception, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
// An array of namespace sets, out of line
// @0x1424dc4b0
template ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::NamespaceSet>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::NamespaceSet>, 2>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
// @0x1424dc730
template ArrayDataBase<WeakPtr<GFx::DisplayObject>, AllocatorLH<WeakPtr<GFx::DisplayObject>, 2>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
// @0x1424dc7a0
template ArrayDataBase<GFx::ASString, AllocatorLH<GFx::ASString, 2>, ArrayDefaultPolicy>::~ArrayDataBase();
// MS2-FUNCTIONAL: the exe calls ResizeNoConstruct and the copy-construct loop out of line, here they are inlined
// @0x1424d5310
template ArrayDataDH<GFx::AS3::Value, AllocatorDH<GFx::AS3::Value, 2>, ArrayDefaultPolicy>::ArrayDataDH(
    const ArrayDataDH<GFx::AS3::Value, AllocatorDH<GFx::AS3::Value, 2>, ArrayDefaultPolicy>&);
// MS2-FUNCTIONAL: the exe expands Value::AddRef inline, here it calls the out-of-line AddRefInternal/AddRefWeakRef
// @0x1424d5390
template MS2_DynAttrsNode::HashNode(const MS2_DynAttrsNode&);
// MS2-FUNCTIONAL: the exe expands Value::AddRef inline, here it calls the out-of-line AddRefInternal/AddRefWeakRef
// @0x1424d5420
template MS2_StringValueNode::HashNode(const MS2_StringValueNode&);
typedef HashNode<GFx::AS3::TClassTraitsCache::Key, GFx::AS3::ClassTraits::Traits*,
                 GFx::AS3::TClassTraitsCache::Key::HashFunctor> MS2_ClassTraitsCacheNode;
typedef HashsetCachedNodeEntry<MS2_ClassTraitsCacheNode, MS2_ClassTraitsCacheNode::NodeHashF> MS2_ClassTraitsCacheEntry;
// @0x1424d54a0
template MS2_ClassTraitsCacheEntry::HashsetCachedNodeEntry(const MS2_ClassTraitsCacheEntry&);

namespace GFx { namespace AS3 {
// The SPtr overload with AssignUnsafe(Object*) expanded.
// @0x1424d2590
template <>
void Value::AssignUnsafe<Instances::fl::GlobalObjectCPP>(const SPtr<Instances::fl::GlobalObjectCPP>& v)
{
    Object* p = v.GetPtr();
    SetKind(kObject);
    value = p;
    if (p)
        p->AddRef();
}

// @0x1424d5560
ASRefCountCollector::ASRefCountCollector()
{
    FrameCnt = 0;
    PeakRootCount = 0;
    LastRootCount = 0;
    LastCollectedRoots = 0;
    LastPeakRootCount = 0;
    TotalFramesCount = 0;
    LastCollectionFrameNum = 0;
    CollectionScheduledFlags = 0;
    SuspendCnt = 0;
    MaxRootCount = PresetMaxRootCount = 1000;
    MaxFramesBetweenCollections = 0;
}

// Value::AddRefInternal as the exe expands it inline.
static SF_INLINE void MS2_StrongAddRef(const Value& v)
{
    Object* obj;
    switch (v.GetKind())
    {
    case Value::kString:
        v.GetStringNode()->AddRef();
        return;
    case Value::kNamespace:
    case Value::kObject:
    case Value::kClass:
    case Value::kFunction:
    case Value::kThunkFunction:
        obj = v.GetObject();
        break;
    case Value::kThunkClosure:
    case Value::kVTableIndClosure:
        obj = v.GetClosure();
        break;
    default:
        return;
    }
    if (obj)
        obj->AddRef();
}

// A copied call frame is marked as a copy; its debug file/line position starts over.
// MS2-FUNCTIONAL: same code; the exe duplicates the object AddRef tail per closure/object case where ours jumps to one
// @0x1424d6900
CallFrame::CallFrame(const CallFrame& o)
    : DiscardResult(o.DiscardResult), ACopy(true), RegisteredFunction(o.RegisteredFunction), ScopeStackBaseInd(o.ScopeStackBaseInd), CP(o.CP)
    , pRegisterFile(o.pRegisterFile), pHeap(o.pHeap), pFile(o.pFile), MBIIndex(o.MBIIndex), pSavedScope(o.pSavedScope), OriginationTraits(o.OriginationTraits)
    , pScopeStack(o.pScopeStack), PrevInitialStackPos(o.PrevInitialStackPos), DefXMLNamespace(o.DefXMLNamespace), PrevFirstStackPos(o.PrevFirstStackPos)
    , PrevReservedNum(o.PrevReservedNum), Name(o.Name), CurrFileInd(0), CurrLineNumber(0), StartTicks(o.StartTicks), Invoker(o.Invoker, Value::NotRefCounted)
{
    // Value::AddRef as the exe expands it inline (the weak proxy is Value's private +0x08).
    if (o.Invoker.IsRefCounted())
    {
        if (o.Invoker.IsWeakRef())
            ++(*reinterpret_cast<WeakProxy* const*>(reinterpret_cast<const char*>(&o.Invoker) + 8))->RefCount;
        else
            MS2_StrongAddRef(o.Invoker);
    }
}

// A strong copy: copies other with its reference, then trades a weak reference for a strong one to the object, or
// for undefined if the object is gone.
// MS2-FUNCTIONAL: same code; the exe stores the undefined kind before the shared tail clears the weak flag in memory
// @0x1424dbe60
Value::Value(const Value& other, StrongRefType)
{
    SIMD::PrefetchObj(&other);
    memcpy(this, &other, sizeof(Value));
    const KindType ok = other.GetKind();
    if (IsRefCounted(ok))
    {
        if (other.IsWeakRef())
            ++other.Bonus.pWeakProxy->RefCount;
        else
            MS2_StrongAddRef(other);
    }

    if (IsWeakRef())
    {
        if (Bonus.pWeakProxy->pObject)
        {
            MS2_StrongAddRef(*this);
            Bonus.pWeakProxy->Release();
        }
        else
        {
            SetKind(kUndefined);
            value.VS._1.VObj = NULL;
            value.VS._2.VObj = NULL;
        }
        Bonus.pWeakProxy = NULL;
        Flags &= ~weakRefMask;
    }
}

// @0x1424dbf70
SF_NOINLINE Value::Value(const ASString& v)
    : Flags(kString)
    , value(v.GetNode())
{
    if (v.GetNode() == v.GetManager()->GetNullStringNode())
    {
        SetKind(kObject);
        value = (Object*)NULL;
    }
    else
        value.VS._1.VStr->AddRef();
}

// @0x1424dbfc0
Value::Value(ASStringNode* v)
    : Flags(kString)
    , value(v)
{
    if (v)
    {
        if (v == v->GetManager()->GetNullStringNode())
        {
            SetKind(kObject);
            value = (Object*)NULL;
        }
        else
            v->AddRef();
    }
    else
        SetKind(kObject);
}

// @0x1424dc020
Value::Value(Class* v)
    : Flags(kClass)
    , value(v)
{
    if (v)
        v->AddRef();
}

// @0x1424dc050
Value::Value(Object* v)
    : Flags(kObject)
    , value(v)
{
    if (v)
        v->AddRef();
}

// The class traits of a ClassInfo's parent class, NULL for none (0x142525ca0).
const ClassTraits::Traits* RetrieveParentClassTraits(VM& vm, const ClassInfo& ci);

// @0x1424daa20
// noinline: the derived ctors call it out of line.
__declspec(noinline) Traits::Traits(VM& vm, const Traits* pt, bool isDynamic, bool isFinal)
    : GASRefCountBase(&vm.GetGC())
    , FirstOwnSlotInd(0)
    , FixedValueSlotNumber(0)
    , MemSize(0)
    , Flags(0)
    , TraitsType(pt ? pt->GetTraitsType() : Traits_Unknown)
    , pVM(&vm)
    , pConstructor(NULL)
    , pParent(pt)
    , InitScope(vm.GetMemoryHeap())
{
    const bool arrayLike = pt ? pt->IsArrayLike() : false;
    Flags &= ~(SPInt)(ArrayLikeMask | ObjectTypeMask | IsFinalMask);
    RefCount |= Flag_DeleteLast;
    Flags |= (-(SPInt)arrayLike & ArrayLikeMask) | (-(SPInt)isFinal & IsFinalMask) | (-(SPInt)isDynamic & ObjectTypeMask);
}

inline Traits::Traits(VM& vm)
    : GASRefCountBase(&vm.GetGC())
    , FirstOwnSlotInd(0)
    , FixedValueSlotNumber(0)
    , MemSize(0)
    , Flags(0)
    , TraitsType(Traits_Unknown)
    , pVM(&vm)
    , pConstructor(NULL)
    , pParent(NULL)
    , InitScope(vm.GetMemoryHeap())
{
    RefCount |= Flag_DeleteLast;
}

namespace InstanceTraits
{
    // @0x1424dad50
    Traits::Traits(Pickable<Instances::Namespace> ns, VM& vm, const AS3::Traits* pt, bool isDynamic, bool isFinal)
        : AS3::Traits(vm, pt, isDynamic, isFinal)
        , Ns(ns)
    {
        CopyParentTraits();
    }

    // @0x1424d94b0
    RTraits::RTraits(VM& vm, const ASString& n, Pickable<Instances::Namespace> ns, const AS3::Traits* pt, bool isDynamic, bool isFinal)
        : Traits(ns, vm, pt, isDynamic, isFinal)
        , Name(n)
    {
    }

    // The public namespace for an empty package name, else the interned public namespace of the package.
    static Pickable<Instances::Namespace> MakeInternedNamespace(VM& vm, Abc::NamespaceKind kind, const char* name)
    {
        ASString uri = vm.GetStringManager().CreateString(name ? name : "");
        if (kind == Abc::NS_Public && uri.IsEmpty())
        {
            Pickable<Instances::Namespace> ns(vm.PublicNamespace.GetPtr());
            if (ns.GetPtr())
                ns.GetPtr()->AddRef();
            return ns;
        }
        return static_cast<fl::Namespace&>(vm.GetClassTraitsNamespace().GetInstanceTraits())
            .MakeInternedInstance(kind, uri, Value::GetUndefined());
    }

    static const Traits* GetParentInstanceTraits(VM& vm, const ClassInfo& ci)
    {
        const ClassTraits::Traits* ctr = RetrieveParentClassTraits(vm, ci);
        const Traits* itr = NULL;
        if (ctr)
            itr = &ctr->GetInstanceTraits();
        return itr;
    }

    // MS2-FUNCTIONAL: same code; the exe stores the public namespace result before the null test and loads the
    // string manager after the package name select (scheduling)
    // @0x1424d6750
    CTraits::CTraits(VM& vm, const ClassInfo& ci)
        : Traits(MakeInternedNamespace(vm, Abc::NS_Public, ci.GetPkgName()), vm, GetParentInstanceTraits(vm, ci),
                 ci.IsDynamicObject(), ci.IsFinalType())
        , CI(ci)
    {
        for (UInt8 i = 0; i < ci.InstanceMemberNum; ++i)
            AddSlot(ci.InstanceMember[i]);

        for (UInt8 i = 0; i < ci.InstanceMethodNum; ++i)
            Add2VT(ci, ci.InstanceMethod[i]);
    }
}

namespace ClassTraits
{
    // Class objects are dynamic and not final.
    // @0x1424dabd0
    Traits::Traits(VM& vm, const ClassInfo& ci)
        : AS3::Traits(vm, RetrieveParentClassTraits(vm, ci), true, false)
    {
        SetConstructor(vm.GetClassTraitsClassClass().GetInstanceTraits().GetConstructor());
        Flags |= IsClassMask;
        RegisterSlots();

        for (UInt8 i = 0; i < ci.ClassMethodNum; ++i)
            Add2VT(ci, ci.ClassMethod[i]);

        for (UInt8 i = 0; i < ci.ClassMemberNum; ++i)
            AddSlot(ci.ClassMember[i]);
    }

    // @0x1424dacd0
    Traits::Traits(VM& vm, const ClassTraits::Traits* pt)
        : AS3::Traits(vm, pt, true, false)
    {
        SetConstructor(vm.GetClassTraitsClassClass().GetInstanceTraits().GetConstructor());
        Flags |= IsClassMask;
        RegisterSlots();
    }

    // @0x1424dab20
    Traits::Traits(VM& vm)
        : AS3::Traits(vm)
    {
        Flags |= IsClassMask;
    }
}

// The public namespace of uri (the VM's own one for the empty uri).
static inline Pickable<Instances::Namespace> MakePublicNamespace(VM& vm, const ASString& uri)
{
    if (uri.IsEmpty())
        return Pickable<Instances::Namespace>(vm.PublicNamespace.GetPtr(), PickValue);
    return static_cast<InstanceTraits::fl::Namespace&>(vm.GetClassTraitsNamespace().GetInstanceTraits())
        .MakeInternedInstance(Abc::NS_Public, uri, Value::GetUndefined());
}

// "pkg.Name" or "pkg::Name" as a public QName; a name without a package is in the public namespace.
// MS2-FUNCTIONAL: same code; the exe keeps the separator position in r8 and branches on the "::" decrement
// (register allocation)
// MS2-FUNCTIONAL: the exe expands Value::AddRef inline, here it calls the out-of-line AddRefInternal/AddRefWeakRef
// @0x1424d8f90
Multiname::Multiname(const Multiname& other)
    : Kind(other.Kind)
    , Obj(other.Obj)
    , Name(other.Name)
{
}

// Sets mn from a QName object (sfr_as3_03).
void FUN_1425273b0(Multiname& mn, const Value& qname);

// @0x1424d8a90
Multiname::Multiname(Instances::Namespace& ns, const Value& name)
    : Kind(static_cast<Abc::MultinameKind>(0))
    , Obj(&ns)
{
    if (Value::IsObject(name.GetKind()))
    {
        Object* obj = name.GetObject();
        if (obj && obj->GetTraits().GetTraitsType() == Traits_QName && obj->GetTraits().IsInstanceTraits())
        {
            FUN_1425273b0(*this, name);
            return;
        }
    }
    Name.AssignUnsafe(name);
    PostProcessName(false);
}

// The any-name "" in the running frame's default XML namespace, else the public one.
// MS2-FUNCTIONAL: same code; the exe inlines the first SPtr assignment and calls SetPtr for the fallback, ours calls it for both
// @0x1424d8bb0
Multiname::Multiname(VM& vm)
    : Kind(static_cast<Abc::MultinameKind>(0))
{
    FUN_1424e0d40(Name, vm.GetStringManager().CreateEmptyString());
    Obj = vm.GetDefXMLNamespace();
    if (Obj.GetPtr() == NULL)
        Obj.SetPtr(vm.PublicNamespace.GetPtr());
}

// MS2-FUNCTIONAL: same code; the exe branches on the colon flag before decrementing pos (we select it), and allocates registers differently
// @0x1424d9040
Multiname::Multiname(VM& vm, const StringDataPtr& qname)
    : Kind(static_cast<Abc::MultinameKind>(0))
{
    bool colonColon = true;
    SPInt pos = qname.FindLastChar(':');
    if (pos < 0)
    {
        colonColon = false;
        pos = qname.FindLastChar('.');
    }
    const StringDataPtr name = qname.GetTrimLeft(pos + 1);

    if (pos > 0)
    {
        if (colonColon)
            --pos;
        Obj = MakePublicNamespace(vm, vm.GetStringManager().CreateString(qname.ToCStr(), pos));
    }
    else
        Obj = vm.PublicNamespace.GetPtr();

    Name = vm.GetStringManager().CreateString(name.ToCStr(), name.GetSize());
    PostProcessName(false);
}

// The kind keeps the file's flag encoding. Every name but the any-type one is interned; only qualified, non-late
// names and namespace sets get a namespace object.
// MS2-FUNCTIONAL: same code; the exe keeps the namespace kind in edx (register allocation)
// @0x1424d8ec0
Multiname::Multiname(VMAbcFile& file, const Abc::Multiname& mn)
    : Kind(static_cast<Abc::MultinameKind>(mn.Kind))
{
    if (&mn != &file.GetAbcFile().Const_Pool.AnyType)
    {
        Name = file.GetInternedString(mn.NameIndex);
        PostProcessName(false);
    }

    const Abc::MultinameFlagKind nsKind = static_cast<Abc::MultinameFlagKind>(mn.Kind & 3);
    if (nsKind == Abc::MNF_NS_Qualified && !((UInt8)((UInt32)mn.Kind >> 2) & 1))
    {
        if (mn.Ind != 0)
            Obj = &file.GetInternedNamespace(mn.Ind);
    }
    else if (nsKind == Abc::MNF_NS_Multi)
        Obj = &file.GetInternedNamespaceSet(mn.Ind);
}

// The top argCount values of the VM's operand stack, moved (not copied) into the argument slots.
// MS2-FUNCTIONAL: same code; the exe zeroes the fixed values before the heap array and allocates r14/r9 (scheduling)
// @0x1424d9530
ReadArgs::ReadArgs(VM& vm, UInt32 argCount)
    : VMRef(vm)
    , OpStack(reinterpret_cast<ValueStack&>(vm.OpStack))
    , ArgNum(argCount)
    , CallArgs(vm.MHeap)
{
    if (argCount)
    {
        Value* dst = FixedArgs;
        if (argCount > 8)
        {
            CallArgs.Resize(argCount);
            dst = CallArgs.GetDataPtr();
        }
        memcpy(dst, OpStack.GetTopPtr() - (UInt16)(argCount - 1), argCount * sizeof(Value));
        OpStack.Release(argCount);
    }
}

// @0x1424d99f0
SlotInfo::SlotInfo(const SlotInfo& other)
    : ReadOnly(other.ReadOnly)
    , DontEnum(other.DontEnum)
    , DontDelete(other.DontDelete)
    , Internal(other.Internal)
    , CppBinding(other.CppBinding)
    , BindType(other.BindType)
    , ValueInd(other.ValueInd)
    , pNs(other.pNs)
    , CTraits(other.CTraits)
    , File(other.File)
    , TI(other.TI)
    , Name(other.Name)
{
}

// The top argCount values of the tracer state's operand stack, copied into the argument slots and popped.
namespace TR {

// MS2-FUNCTIONAL: same code; the exe inlines the Value copy's AddRef where our Value header calls it out of line
// @0x1424d9640
ReadArgs::ReadArgs(VM& vm, State& s, UInt32 argCount)
    : VMRef(vm), StateRef(s), ReadNum(0), ArgNum(argCount), CallArgs(VMRef.MHeap)
{
    if (argCount)
    {
        const UPInt size  = StateRef.GetOpStack().GetSize();
        const UPInt first = size - argCount;
        if (argCount <= 8)
        {
            for (UPInt i = first, j = 0; i < size; ++i, ++j)
                FixedArgs[j].Assign(StateRef.GetOpStack()[i]);
        }
        else
        {
            for (UPInt i = first; i < size; ++i)
                CallArgs.PushBack(StateRef.GetOpStack()[i]);
        }
        StateRef.GetOpStack().Resize(first);
    }
    ReadNum += argCount;
}

} // namespace TR

// Multiname = QName object (the QName's local name and namespace); XML is not modeled yet.
void FUN_1425273b0(Multiname& mn, const Value& qname);

// The default xml namespace of the running call frame (frames are 0xa8 bytes, 64 to a page).
static inline GASRefCountBase* CurrentDefXMLNamespace(const VM& vm)
{
    const UPInt i = vm.Unk070[1] - 1;
    return *reinterpret_cast<GASRefCountBase* const*>(
        reinterpret_cast<const char* const*>(vm.Unk070[4])[i >> 6] + (i & 0x3f) * 0xa8 + 0x58);
}

// A run-time name: a QName object gives its name and namespace; strings and numbers are the name, other objects
// their string form, in the default xml namespace (else the public one). Anything else throws a TypeError.
// MS2-FUNCTIONAL: same code; the exe duplicates the epilogue per return and keeps &Name in rdi (block layout)
// @0x1424d8cb0
Multiname::Multiname(VM& vm, const Value& name)
    : Kind(static_cast<Abc::MultinameKind>(0))
{
    const Value::KindType kind = name.GetKind();
    if (!((kind >= Value::kInt && kind <= Value::kNumber) || kind == Value::kString))
    {
        if (Value::IsObject(kind))
        {
            Object* obj = name.GetObject();
            if (obj && obj->GetTraits().GetTraitsType() == Traits_QName && obj->GetTraits().IsInstanceTraits())
            {
                FUN_1425273b0(*this, name);
                return;
            }
        }
        if (!Value::IsObject(kind))
        {
            vm.ThrowTypeError(VM::Error(VM::eInvalidArgumentError, vm, "Multiname"));
            return;
        }
        if (name.GetObject() == NULL)
        {
            vm.ThrowTypeError(VM::Error(VM::eNotImplementedError, vm, "Multiname"));
            return;
        }

        Name.Assign(name);
        ASString str = vm.GetStringManager().CreateEmptyString();
        if (!Name.Convert2String(str))
            return;
        Name = str;
    }
    else
        Name.Assign(name);

    PostProcessName(false);

    GASRefCountBase* ns = CurrentDefXMLNamespace(vm);
    if (ns != Obj.GetPtr())
    {
        Obj.Pick(static_cast<GASRefCountBase*>(NULL));
        if (ns)
            ns->AddRef();
        Obj.GetRawRef() = ns;
    }
    if (!Obj)
        Obj = vm.PublicNamespace.GetPtr();
}

// Object(Traits&) has no out-of-line copy in the exe; the Instance ctor inlines it.
inline Object::Object(Traits& t)
    : GASRefCountBase(&t.GetVM().GetGC())
    , pTraits(&t)
    , pUserDataHolder(NULL)
{
}

// @0x1424d7de0
Instance::Instance(InstanceTraits::Traits& t)
    : Object(t)
{
    t.ConstructTail(*this);
}

// Object(VM&) is inlined into Instance(VM&) as well: an object with no traits yet.
inline Object::Object(VM& vm)
    : GASRefCountBase(&vm.GetGC())
    , pUserDataHolder(NULL)
{
}

// MS2-FUNCTIONAL: same stores; the exe writes the vftable before the reference count (scheduling)
// @0x1424d93a0
Instance::Instance(VM& vm)
    : Object(vm)
{
}

// The parent class is the class object of the parent class traits' instance traits.
// @0x1424d6ac0
Class::Class(ClassTraits::Traits& t)
    : Object(t)
    , ParentClass(t.GetParent()
                      ? &static_cast<const ClassTraits::Traits*>(t.GetParent())->GetInstanceTraits().GetConstructor()
                      : NULL)
    , Unk40(1)
{
}

namespace Classes {

// MS2-FUNCTIONAL: the exe inlines Class::Class here; ours calls it (0x1424d6ac0)
// @0x1424dadb0
UDBase::UDBase(ClassTraits::Traits& t)
    : Class(t)
{
    t.ConstructTail(*this);
}

} // Classes

// VM::PrepareClassTraits: registers tr and hands it on
static inline Pickable<ClassTraits::Traits> MS2_PrepareClassTraits(VM& vm, ClassTraits::Traits* tr)
{
    vm.RegisterClassTraits(*tr);
    return Pickable<ClassTraits::Traits>(tr);
}

// @0x1424dc160
XMLSupportImpl::XMLSupportImpl(VM& vm)
    : XMLSupport(vm, true), pVM(&vm),
      TraitsQName(MS2_PrepareClassTraits(vm, SF_HEAP_NEW(vm.GetMemoryHeap()) ClassTraits::fl::QName(vm))),
      TraitsXML(MS2_PrepareClassTraits(vm, SF_HEAP_NEW(vm.GetMemoryHeap()) ClassTraits::fl::XML(vm))),
      TraitsXMLList(MS2_PrepareClassTraits(vm, SF_HEAP_NEW(vm.GetMemoryHeap()) ClassTraits::fl::XMLList(vm)))
{
}

// MS2-FUNCTIONAL: same code; the exe keeps file in r15 (and saves an unused r12)
// @0x1424dbb30
VMAbcFile::VMAbcFile(VM& vm, const Ptr<Abc::File>& file)
    : GASRefCountBase(vm.GetGCPtr()), pVM(&vm), pFile(file), AbsObjectsTable(NULL), GlobalObjectsTable(NULL),
      ActivationTraitsCacheTable(NULL), FunctionTraitsCacheTable(NULL)
{
    RefCount |= Flag_HasFinalize;
    {
        // PushBack, with the exe's out-of-line ResizeNoConstruct
        SPtr<ASStringNode> empty(vm.GetStringManager().GetEmptyStringNode());
        FUN_142524a30(&IntStrings, &IntStrings, IntStrings.GetSize() + 1);
        new (&IntStrings[IntStrings.GetSize() - 1]) SPtr<ASStringNode>(empty);
    }
    const UPInt n = file->MethodBodies.Info.GetSize();
    // OpCodeArray.Resize(n) and Exceptions.Resize(n), out of line in the exe
    FUN_1425244e0(&OpCodeArray, n);
    FUN_142524710(&Exceptions, n);
    if (!vm.InDestructor)
        vm.VMAbcFilesWeak.PushBack(this);
}

// MS2-FUNCTIONAL: the exe has no out-of-line ~VMAbcFile; it is inlined in the scalar deleting destructor 0x1424e3eb0
// (the unmodeled hash sets are cleared through the exe's helpers, the modeled members by their own destructors).
VMAbcFile::~VMAbcFile()
{
    FUN_142522a60(pVM, this);
    FUN_1424dcc30(&FunctionTraitsCacheTable);
    FUN_1424dcdd0(&ActivationTraitsCacheTable);
    reinterpret_cast<Sfr34GlobalObjectSet*>(&GlobalObjectsTable)->~Sfr34GlobalObjectSet();
    reinterpret_cast<Sfr34AbsObjectSet*>(&AbsObjectsTable)->~Sfr34AbsObjectSet();
}

// MS2-FUNCTIONAL: inlined in the scalar deleting destructors 0x1424e4120 and 0x1424e4190; the members release
// themselves.
XMLSupport::~XMLSupport()
{
}

XMLSupportImpl::~XMLSupportImpl()
{
}

namespace fl { extern const char* NS_AS3; extern const char* NS_XML; extern const ClassInfo FunctionCI; }
namespace fl_vec { extern const char* NS_Vector; }

// SF_HEAP_NEW's allocation, for the constructors called through their addresses
static inline void* MS2_VMAlloc(MemoryHeap* heap, UPInt size)
{
    return SF_HEAP_ALLOC(heap, size, StatMV_ActionScript_Mem);
}

namespace InstanceTraits {

// (sfr19) the instance traits of null (VM +0x270): a prototype-less Object-constructed traits. Only inlined.
class Anonimous : public Prototype
{
public:
    Anonimous(VM& vm) : Prototype(vm, CInfo) {}
    virtual ~Anonimous();           // 0x1424e25b0
    static const ClassInfo CInfo;   // 0x14317af30
};

// (sfr19) the instance traits of void (VM +0x278). Only inlined.
class Void : public Prototype
{
public:
    Void(VM& vm) : Prototype(vm, CInfo) {}
    virtual ~Void();                // 0x1424e4040
    static const ClassInfo CInfo;   // 0x14317af80
};

// MS2-FUNCTIONAL: inlined in the scalar deleting destructors 0x1424e25b0 and 0x1424e4040 (just ~CTraits)
Anonimous::~Anonimous()
{
}

Void::~Void()
{
}

} // namespace InstanceTraits

}}} // namespace Scaleform::GFx::AS3

extern const Scaleform::GFx::AS3::ClassInfo DAT_14313dc60;     // the CInfo of the plain function traits (VM +0x280)
// ClassTraits::Function(VM&, const ClassInfo&) (0xe8 bytes)
void* FUN_1423eca40(void* self, Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::ClassInfo& ci);
// InstanceTraits::Function(VM&, const ClassInfo&) (0x100 bytes)
void* FUN_1423ecf50(void* self, Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::ClassInfo& ci);
void* FUN_1423eb860(void* self, Scaleform::GFx::AS3::VM& vm);  // InstanceTraits::Activation(VM&) (0xd0 bytes)
void* FUN_1423ed1c0(void* self, Scaleform::GFx::AS3::VM& vm);  // InstanceTraits::fl::GlobalObject(VM&) (0xe8 bytes)
// Instances::fl::GlobalObjectCPP(VM&, InstanceTraits::fl::GlobalObject&) (0xd8 bytes)
void* FUN_1423ed260(void* self, Scaleform::GFx::AS3::VM& vm, void* itr);
void FUN_142423d00(Scaleform::GFx::AS3::Class* cl);            // Class::InitPrototype-like: the class Class's set-up
void FUN_142522db0(void* arr, void* heapAddr, Scaleform::UPInt newCap);    // ArrayLH<GlobalObject*> Reserve
void FUN_1424dde10(void* frame);                               // CallFrame::~CallFrame

namespace Scaleform { namespace GFx { namespace AS3 {

// The VM: its stacks, the namespaces and class traits of the built-in types, the global object, then every ABC file
// of the loader (the scripts of the last one run). The XML hooks start disabled and the E4X support replaces them
// once the base classes exist. The exe inlines the Prototype, ValueStack and ValueRegisterFile constructors; ours
// calls them, and builds the stacks in place over the VM's opaque members.
// MS2-FUNCTIONAL: out-of-line constructors and a different exception-unwind layout
// @0x1424dae90
VM::VM(FlashUI& ui, FileLoader& loader, StringManager& string_manager, ASRefCountCollector& gc)
    : Initialized(false), InDestructor(false), StringManagerRef(string_manager), GC(&gc), UI(ui), Loader(loader),
      InInitializer(0), MHeap(Memory::GetHeapByAddress(this)), XMLSupport_(Pickable<XMLSupport>(SF_HEAP_NEW(MHeap)
      XMLSupport(*this))), ScopeStack(MHeap), HandleException(false), SystemDomain(NULL)
{
    new (OpStack) ValueStack();
    reinterpret_cast<ValueStack*>(&OpStack)->Reserve(1);
    {
        // the paged call stack: no pages yet, and a default frame on the VM's heap
        for (unsigned i = 1; i < 5; ++i)
            Unk070[i] = 0;
        UInt64 def[0xa8 / 8];
        memset(def, 0, sizeof(def));
        reinterpret_cast<CallFrame*>(def)->pHeap = MHeap;
        new (CallStack) CallFrame(*reinterpret_cast<CallFrame*>(def));
        FUN_1424dde10(def);
    }
    new (RegisterFile) ValueRegisterFile();

    PublicNamespace = Pickable<Instances::Namespace>(SF_HEAP_NEW(MHeap) Instances::Namespace(*this, Abc::NS_Public, ""));
    AS3Namespace = Pickable<Instances::Namespace>(SF_HEAP_NEW(MHeap) Instances::Namespace(*this, Abc::NS_Public, fl::NS_AS3));
    VectorNamespace = Pickable<Instances::Namespace>(
        SF_HEAP_NEW(MHeap) Instances::Namespace(*this, Abc::NS_Public, fl_vec::NS_Vector));
    XMLNamespace = Pickable<Instances::Namespace>(SF_HEAP_NEW(MHeap) Instances::Namespace(*this, Abc::NS_Public, fl::NS_XML));

    TraitsClassClass = MS2_PrepareClassTraits(*this, SF_HEAP_NEW(MHeap) ClassTraits::ClassClass(*this));
    TraitsObject = MS2_PrepareClassTraits(*this, SF_HEAP_NEW(MHeap) ClassTraits::fl::Object(*this));
    TraitsNamespace = MS2_PrepareClassTraits(*this, SF_HEAP_NEW(MHeap) ClassTraits::fl::Namespace(*this));
    // the five constructors called through their addresses run only on a non-null allocation (new-expression)
    void* pmem = MS2_VMAlloc(MHeap, 0xe8);
    TraitsFunction = MS2_PrepareClassTraits(*this, static_cast<ClassTraits::Traits*>(
        pmem ? FUN_1423eca40(pmem, *this, fl::FunctionCI) : 0));
    TraitsBoolean = MS2_PrepareClassTraits(*this, SF_HEAP_NEW(MHeap) ClassTraits::fl::Boolean(*this));
    TraitsNumber = MS2_PrepareClassTraits(*this, SF_HEAP_NEW(MHeap) ClassTraits::fl::Number(*this));
    TraitsInt = MS2_PrepareClassTraits(*this, SF_HEAP_NEW(MHeap) ClassTraits::fl::int_(*this));
    TraitsUint = MS2_PrepareClassTraits(*this, SF_HEAP_NEW(MHeap) ClassTraits::fl::uint(*this));
    TraitsString = MS2_PrepareClassTraits(*this, SF_HEAP_NEW(MHeap) ClassTraits::fl::String(*this));
    TraitsArray = MS2_PrepareClassTraits(*this, SF_HEAP_NEW(MHeap) ClassTraits::fl::Array(*this));
    Traits240 = MS2_PrepareClassTraits(*this, SF_HEAP_NEW(MHeap) ClassTraits::fl::Catch(*this));
    TraitsVector = MS2_PrepareClassTraits(*this, SF_HEAP_NEW(MHeap) ClassTraits::fl_vec::Vector(*this));
    TraitsVector_int = MS2_PrepareClassTraits(*this, SF_HEAP_NEW(MHeap) ClassTraits::fl_vec::Vector_int(*this));
    TraitsVector_uint = MS2_PrepareClassTraits(*this, SF_HEAP_NEW(MHeap) ClassTraits::fl_vec::Vector_uint(*this));
    TraitsVector_double = MS2_PrepareClassTraits(*this, SF_HEAP_NEW(MHeap) ClassTraits::fl_vec::Vector_double(*this));
    TraitsVector_String = MS2_PrepareClassTraits(*this, SF_HEAP_NEW(MHeap) ClassTraits::fl_vec::Vector_String(*this));

    TraitsNull = Pickable<ClassTraits::Traits>(
        reinterpret_cast<ClassTraits::Traits*>(SF_HEAP_NEW(MHeap) InstanceTraits::Anonimous(*this)));
    TraitsVoid = Pickable<ClassTraits::Traits>(
        reinterpret_cast<ClassTraits::Traits*>(SF_HEAP_NEW(MHeap) InstanceTraits::Void(*this)));
    pmem = MS2_VMAlloc(MHeap, 0x100);
    NoFunctionTraits = Pickable<InstanceTraits::Traits>(
        static_cast<InstanceTraits::Traits*>(pmem ? FUN_1423ecf50(pmem, *this, DAT_14313dc60) : 0));
    pmem = MS2_VMAlloc(MHeap, 0xd0);
    ActivationTraits = Pickable<InstanceTraits::Traits>(
        static_cast<InstanceTraits::Traits*>(pmem ? FUN_1423eb860(pmem, *this) : 0));
    pmem = MS2_VMAlloc(MHeap, 0xe8);
    TraitaGlobalObject = Pickable<InstanceTraits::fl::GlobalObject>(
        static_cast<InstanceTraits::fl::GlobalObject*>(pmem ? FUN_1423ed1c0(pmem, *this) : 0));
    pmem = MS2_VMAlloc(MHeap, 0xd8);
    GlobalObject = Pickable<Instances::fl::GlobalObjectCPP>(static_cast<Instances::fl::GlobalObjectCPP*>(
        pmem ? FUN_1423ed260(pmem, *this, TraitaGlobalObject.GetPtr()) : 0));
    GlobalObjectValue = Value(reinterpret_cast<Object*>(GlobalObject.GetPtr()));

    XMLSupport_ = Pickable<XMLSupport>(SF_HEAP_NEW(MHeap) XMLSupportImpl(*this));

    // functions without traits of their own are constructed by the class Function
    {
        Class& ctor = TraitsFunction->GetInstanceTraits().GetConstructor();
        NoFunctionTraits->pConstructor = &ctor;
    }
    Initialized = true;

    // GlobalObjects.PushBack, without a reference (the global object is held by GlobalObject)
    {
        struct RawArray { Instances::fl::GlobalObject** Data; UPInt Size; UPInt Capacity; };
        RawArray& a = reinterpret_cast<RawArray&>(GlobalObjects);
        const UPInt size = a.Size + 1;
        if (size < a.Size)
        {
            if (size < (a.Capacity >> 1))
                FUN_142522db0(&a, &a, size);
        }
        else if (size >= a.Capacity)
            FUN_142522db0(&a, &a, size + (size >> 2));
        a.Size = size;
        a.Data[size - 1] = reinterpret_cast<Instances::fl::GlobalObject*>(GlobalObject.GetPtr());
    }

    const UPInt n = Loader.GetSize();
    for (UPInt i = 0; i < n; ++i)
    {
        // The exe fetches the loader's file (slot 3) before allocating the VMAbcFile.
        const Ptr<Abc::File>& abc = Loader.GetFile(i);
        SPtr<VMAbcFile> file = Pickable<VMAbcFile>(SF_HEAP_NEW(MHeap) VMAbcFile(*this, abc));
        if (file->RegisterUserDefinedClassTraits() && file->RegisterScrips(i == n - 1))
            SPtr<VMAbcFile> loaded = file;
    }

    TraitsClassClass->pParent = TraitsObject.GetPtr();
    TraitsClassClass->RegisterSlots();
    FUN_142423d00(&TraitsClassClass->GetInstanceTraits().GetConstructor());
    TraitsObject->RegisterSlots();
    TraitsNamespace->RegisterSlots();
}

// The movie's VM: the classes the movie root makes its display, geometry and event objects from, looked up once.
// @0x1424d5600
ASVM::ASVM(MovieRoot* pmr, FlashUI& ui, FileLoader& loader, StringManager& sm, ASRefCountCollector& gc)
    : VM(ui, loader, sm, gc), pMovieRoot(pmr), ExtensionsEnabled(false)
{
    GraphicsClass = GetClass(StringDataPtr("flash.display.Graphics"));
    TransformClass = GetClass(StringDataPtr("flash.geom.Transform"));
    MatrixClass = GetClass(StringDataPtr("flash.geom.Matrix"));
    Matrix3DClass = GetClass(StringDataPtr("flash.geom.Matrix3D"));
    PerspectiveProjectionClass = GetClass(StringDataPtr("flash.geom.PerspectiveProjection"));
    ColorTransformClass = GetClass(StringDataPtr("flash.geom.ColorTransform"));
    EventClass = GetClass(StringDataPtr("flash.events.Event"));
    MouseEventClass = GetClass(StringDataPtr("flash.events.MouseEvent"));
    KeyboardEventClass = GetClass(StringDataPtr("flash.events.KeyboardEvent"));
    FocusEventClass = GetClass(StringDataPtr("flash.events.FocusEvent"));
    TextEventClass = GetClass(StringDataPtr("flash.events.TextEvent"));
    MouseEventExClass = GetClass(StringDataPtr("scaleform.gfx.MouseEventEx"));
    KeyboardEventExClass = GetClass(StringDataPtr("scaleform.gfx.KeyboardEventEx"));
    FocusEventExClass = GetClass(StringDataPtr("scaleform.gfx.FocusEventEx"));
    TextEventExClass = GetClass(StringDataPtr("scaleform.gfx.TextEventEx"));
    TimerEventClass = GetClass(StringDataPtr("flash.events.TimerEvent"));
    ProgressEventClass = GetClass(StringDataPtr("flash.events.ProgressEvent"));
    PointClass = GetClass(StringDataPtr("flash.geom.Point"));
    RectangleClass = GetClass(StringDataPtr("flash.geom.Rectangle"));
    TextFormatClass = GetClass(StringDataPtr("flash.text.TextFormat"));
    EventDispatcherClass = GetClass(StringDataPtr("flash.events.EventDispatcher"));
    Vector3DClass = GetClass(StringDataPtr("flash.geom.Vector3D"));
}

// Only inlined in the exe (into the deleting destructor 0x1424e2f10); the members release themselves.
IntervalTimer::~IntervalTimer()
{
}

// MS2-FUNCTIONAL: the exe expands Value::AddRef inline, here it calls the out-of-line AddRefInternal/AddRefWeakRef
// @0x1424d7e50
IntervalTimer::IntervalTimer(const Value& function, unsigned delay, bool timeout)
    : Function(function), CurrentCount(0), RepeatCount(0), Interval(UInt64(delay) * 1000), InvokeTime(0), Id(0)
    , Active(true), Timeout(timeout)
{
}

// @0x1424d7f10
IntervalTimer::IntervalTimer(Instances::fl_utils::Timer* timerObj, unsigned delay, unsigned curCount,
                             unsigned repeatCount)
    : TimerObj(timerObj)
    , CurrentCount(curCount)
    , RepeatCount(repeatCount)
    , Interval(UInt64(delay) * 1000)
    , InvokeTime(0)
    , Id(0)
    , Active(true)
    , Timeout(false)
{
}

namespace InstanceTraits {

// @0x1424d9410
Prototype::Prototype(VM& vm, const ClassInfo& ci)
    : CTraits(vm, ci)
{
    SetConstructor(vm.GetClassTraitsObject().GetInstanceTraits().GetConstructor());
}

// @0x1424d9470
Prototype::Prototype(VM& vm, const ClassInfo& ci, Class& c)
    : CTraits(vm, ci)
{
    SetConstructor(c);
}

} // namespace InstanceTraits

// VM::Error: "Error #<id>: <message>", the message being the error text with the arguments filled in.

// MS2-FUNCTIONAL: same code; the exe loads the string manager before masking the result size (scheduling)
// @0x1424d6b90
VM::Error::Error(ErrorID id, VM& vm)
    : ID(id)
    , Message(vm.GetStringManager().CreateEmptyString())
{
    String result;
    const int num = id;
    const char* msg = FUN_142509b60(id);
    Scaleform::Format(result, "Error #{0}: {1}", num, msg);
    Message = vm.GetStringManager().GetStringManager()->CreateString(result.ToCStr(), result.GetSize());
}

// MS2-FUNCTIONAL: same code; the exe loads the string manager before masking the result size (scheduling)
// @0x1424d6cf0
VM::Error::Error(ErrorID id, VM& vm, const Value& arg1, const Value& arg2)
    : ID(id)
    , Message(vm.GetStringManager().CreateEmptyString())
{
    String result;
    String msg;
    const int num = id;
    StringManager& sm = vm.GetStringManager();
    ASString s1 = sm.CreateEmptyString();
    arg1.Convert2String(s1);
    ASString s2 = sm.CreateEmptyString();
    arg2.Convert2String(s2);
    const char* fmt = FUN_142509b60(id);
    Scaleform::Format(msg, fmt, s1.ToCStr(), s2.ToCStr());
    Scaleform::Format(result, "Error #{0}: {1}", num, msg);
    Message = vm.GetStringManager().GetStringManager()->CreateString(result.ToCStr(), result.GetSize());
}

// MS2-FUNCTIONAL: same code; the exe loads the string manager before masking the result size (scheduling)
// @0x1424d6f40
VM::Error::Error(ErrorID id, VM& vm, const Value& arg1)
    : ID(id)
    , Message(vm.GetStringManager().CreateEmptyString())
{
    String result;
    String msg;
    const int num = id;
    ASString s1 = vm.GetStringManager().CreateEmptyString();
    arg1.Convert2String(s1);
    const char* fmt = FUN_142509b60(id);
    Scaleform::Format(msg, fmt, s1.ToCStr());
    Scaleform::Format(result, "Error #{0}: {1}", num, msg);
    Message = vm.GetStringManager().GetStringManager()->CreateString(result.ToCStr(), result.GetSize());
}

// MS2-FUNCTIONAL: same code; the exe loads the string manager before masking the result size (scheduling)
// @0x1424d7130
VM::Error::Error(ErrorID id, VM& vm, const Value& arg1, const char* arg2)
    : ID(id)
    , Message(vm.GetStringManager().CreateEmptyString())
{
    String result;
    String msg;
    const int num = id;
    ASString s1 = vm.GetStringManager().CreateEmptyString();
    arg1.Convert2String(s1);
    const char* fmt = FUN_142509b60(id);
    Scaleform::Format(msg, fmt, s1.ToCStr(), arg2);
    Scaleform::Format(result, "Error #{0}: {1}", num, msg);
    Message = vm.GetStringManager().GetStringManager()->CreateString(result.ToCStr(), result.GetSize());
}

// MS2-FUNCTIONAL: same code; the exe loads the string manager before masking the result size (scheduling)
// @0x1424d7330
VM::Error::Error(ErrorID id, VM& vm, int arg1)
    : ID(id)
    , Message(vm.GetStringManager().CreateEmptyString())
{
    String result;
    String msg;
    const int num = id;
    const char* fmt = FUN_142509b60(id);
    Scaleform::Format(msg, fmt, arg1);
    Scaleform::Format(result, "Error #{0}: {1}", num, msg);
    Message = vm.GetStringManager().GetStringManager()->CreateString(result.ToCStr(), result.GetSize());
}

// MS2-FUNCTIONAL: same code; the exe loads the string manager before masking the result size (scheduling)
// @0x1424d74d0
VM::Error::Error(ErrorID id, VM& vm, int arg1, int arg2)
    : ID(id)
    , Message(vm.GetStringManager().CreateEmptyString())
{
    String result;
    String msg;
    const int num = id;
    const char* fmt = FUN_142509b60(id);
    Scaleform::Format(msg, fmt, arg1, arg2);
    Scaleform::Format(result, "Error #{0}: {1}", num, msg);
    Message = vm.GetStringManager().GetStringManager()->CreateString(result.ToCStr(), result.GetSize());
}

// MS2-FUNCTIONAL: same code; the exe loads the string manager before masking the result size (scheduling)
// @0x1424d7690
VM::Error::Error(ErrorID id, VM& vm, const char* arg1, const char* arg2)
    : ID(id)
    , Message(vm.GetStringManager().CreateEmptyString())
{
    String result;
    String msg;
    const int num = id;
    const char* fmt = FUN_142509b60(id);
    Scaleform::Format(msg, fmt, arg1, arg2);
    Scaleform::Format(result, "Error #{0}: {1}", num, msg);
    Message = vm.GetStringManager().GetStringManager()->CreateString(result.ToCStr(), result.GetSize());
}

// MS2-FUNCTIONAL: same code; the exe loads the string manager before masking the result size (scheduling)
// @0x1424d7850
VM::Error::Error(ErrorID id, VM& vm, const char* arg1)
    : ID(id)
    , Message(vm.GetStringManager().CreateEmptyString())
{
    String result;
    String msg;
    const int num = id;
    const char* fmt = FUN_142509b60(id);
    Scaleform::Format(msg, fmt, arg1);
    Scaleform::Format(result, "Error #{0}: {1}", num, msg);
    Message = vm.GetStringManager().GetStringManager()->CreateString(result.ToCStr(), result.GetSize());
}

// MS2-FUNCTIONAL: same code; the exe loads the string manager before masking the result size (scheduling)
// @0x1424d79f0
VM::Error::Error(ErrorID id, VM& vm, const char* arg1, const Value& arg2)
    : ID(id)
    , Message(vm.GetStringManager().CreateEmptyString())
{
    String result;
    String msg;
    const int num = id;
    ASString s2 = vm.GetStringManager().CreateEmptyString();
    arg2.Convert2String(s2);
    const char* fmt = FUN_142509b60(id);
    Scaleform::Format(msg, fmt, arg1, s2.ToCStr());
    Scaleform::Format(result, "Error #{0}: {1}", num, msg);
    Message = vm.GetStringManager().GetStringManager()->CreateString(result.ToCStr(), result.GetSize());
}

// MS2-FUNCTIONAL: same code; the exe loads the string manager before masking the result size (scheduling)
// @0x1424d7bf0
VM::Error::Error(ErrorID id, VM& vm, const char* arg1, int arg2, int arg3, int arg4)
    : ID(id)
    , Message(vm.GetStringManager().CreateEmptyString())
{
    String result;
    String msg;
    const int num = id;
    const char* fmt = FUN_142509b60(id);
    Scaleform::Format(msg, fmt, arg1, arg2, arg3, arg4);
    Scaleform::Format(result, "Error #{0}: {1}", num, msg);
    Message = vm.GetStringManager().GetStringManager()->CreateString(result.ToCStr(), result.GetSize());
}

// MS2-FUNCTIONAL: the exe inlines the GFx::LoadQueueEntry ctor (out of line in sfr_as2_03) and ArrayPOD::Resize
// @0x1424d7f90
LoadQueueEntry::LoadQueueEntry(Instances::fl_utils::ByteArray* bytes, Instances::fl_display::Loader* loader,
                               LoadMethod method)
    : GFx::LoadQueueEntry(String(""), method, false, false)
{
    mLoader = loader;
    FirstExec = true;
    NotifyLoadInitCInterface = NULL;
    mBytes = SF_HEAP_AUTO_NEW(this) ArrayPOD<UByte>();
    mBytes->Resize(bytes->GetLength());
    memcpy(mBytes->GetDataPtr(), bytes->Data.GetDataPtr(), mBytes->GetSize());
}

// MS2-FUNCTIONAL: the exe inlines the GFx::LoadQueueEntry ctor (out of line in sfr_as2_03)
// @0x1424d81a0
LoadQueueEntry::LoadQueueEntry(Instances::fl_net::URLRequest* request, Instances::fl_display::Loader* loader,
                               LoadMethod method, bool quietOpen)
    : GFx::LoadQueueEntry(String(request ? request->GetUrl().ToCStr() : ""), method, false, quietOpen)
{
    mLoader = loader;
    mURLRequest = request;
    FirstExec = true;
    NotifyLoadInitCInterface = NULL;
}

// MS2-FUNCTIONAL: the exe inlines the GFx::LoadQueueEntry ctor (out of line in sfr_as2_03)
// @0x1424d8350
LoadQueueEntry::LoadQueueEntry(Instances::fl_net::URLRequest* request, Instances::fl_net::URLLoader* loader,
                               LoadMethod method, bool quietOpen)
    : GFx::LoadQueueEntry(String(request ? request->GetUrl().ToCStr() : ""), method, true, quietOpen)
{
    mURLLoader = loader;
    mURLRequest = request;
    FirstExec = true;
    NotifyLoadInitCInterface = NULL;
}

// ---- Tracer helper objects (the Tracer is not modeled: raw words, like the Sfr27Tracer* helpers of sfr_as3_18) ----
extern const char* DAT_143a2d3d0[];      // the AS3 builtin string table (61 entries)
extern const void* DAT_14317f860[];      // vftable of the 0x10-byte counted dummy owner
void FUN_142524ec0(void* arr, void* heapOwner, UPInt newSize);   // ArrayData<Value>::ResizeNoConstruct
void FUN_142524d80(void* arr, void* heapOwner, UPInt newSize);   // ArrayData<pointer>::ResizeNoConstruct
void FUN_1424f08d0(void* dst, UPInt n, const Value* src);        // ConstructorMov<Value>::ConstructArray

namespace
{
struct Sfr30CountedDummy
{
    const void* const* pVTable;
    UPInt              RefCount;
};
void Sfr30DummyRelease(UPInt p)
{
    if (p && !(p & 1))
    {
        Sfr30CountedDummy* o = reinterpret_cast<Sfr30CountedDummy*>(p);
        if (--*reinterpret_cast<int*>(&o->RefCount) == 0)
            reinterpret_cast<void (*)(void*, unsigned)>(const_cast<void*>(o->pVTable[0]))(o, 1);
    }
}
}

// The AS3 builtin names: 61 string nodes, initialised from the static table.
// MS2-FUNCTIONAL: the Tracer-side helper is written over raw words
// @0x1424d9d70
StringManager* FUN_1424d9d70(StringManager* self, ASStringManager* mgr)
{
    for (unsigned i = 0; i < AS3BuiltinConst_Count_; ++i)
        reinterpret_cast<UPInt*>(self)[i] = 0;
    self->pStringManager = mgr;
    self->pStaticStrings = DAT_143a2d3d0;
    mgr->InitBuiltinArray(self->Builtins, DAT_143a2d3d0, AS3BuiltinConst_Count_);
    return self;
}

// A counted dummy owner stored twice (the second slot is a second reference to it).
// MS2-FUNCTIONAL: raw counted pointers over a hand-written release
// @0x1424d9ca0
UPInt* FUN_1424d9ca0(UPInt* self, UPInt arg)
{
    self[0] = 0;
    self[1] = 0;
    self[2] = arg;
    Sfr30CountedDummy* obj = static_cast<Sfr30CountedDummy*>(Memory::pGlobalHeap->Alloc(0x10));
    if (obj)
    {
        obj->RefCount = 1;
        obj->pVTable = DAT_14317f860;
    }
    if (reinterpret_cast<UPInt>(obj) != self[0])
    {
        Sfr30DummyRelease(self[0]);
        self[0] = reinterpret_cast<UPInt>(obj);
    }
    UPInt old = self[1];
    if (old)
    {
        if (old & 1)
            self[1] = old - 1;
        else
            Sfr30DummyRelease(old);
    }
    if (self[0])
        ++*reinterpret_cast<int*>(self[0] + 8);
    self[1] = self[0];
    return self;
}

// Three heap-owned arrays and a bit set sized from the abc file's table (Tracer state).
// MS2-FUNCTIONAL: raw words; the layout of the three arrays is {Data, Size, Policy, Heap}
// @0x1424d9be0
UPInt* FUN_1424d9be0(UPInt* self, UPInt owner, UPInt arg)
{
    self[0] = owner;
    self[1] = arg;
    self[2] = arg;
    UPInt heapOwner = *reinterpret_cast<UPInt*>(owner + 0x18);
    for (unsigned i = 0; i < 3; ++i)
    {
        UPInt* a = self + 3 + i * 4;
        a[0] = 0;
        a[1] = 0;
        a[2] = 0;
        a[3] = heapOwner;
    }
    UPInt file = *reinterpret_cast<UPInt*>(owner + 0x20);
    UPInt table = *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(file + 0x28) + 0x28);
    UPInt entry = (*reinterpret_cast<UPInt**>(table + 0x170))[*reinterpret_cast<int*>(file + 0x30)];
    unsigned count = *reinterpret_cast<unsigned*>(entry + 0x20);
    *reinterpret_cast<unsigned*>(self + 16) = count;
    UPInt bytes = (count + 7) >> 3;
    AllocInfo info(StatMV_VM_Tracer_Mem, 0, 0);
    void* bits = reinterpret_cast<MemoryHeap*>(heapOwner)->Alloc(bytes, &info);
    self[15] = reinterpret_cast<UPInt>(bits);
    memset(bits, 0, bytes);
    return self;
}

// A one-word owner header, three empty words, and an empty-string reference (Tracer scratch state).
// MS2-FUNCTIONAL: raw words over the VM's string manager chain
// @0x1424dbd10
UPInt* FUN_1424dbd10(UPInt* self, UPInt vm)
{
    self[0] = vm;
    self[1] = 0;
    self[2] = 0;
    self[3] = 0;
    UPInt mgr = *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(vm + 0x78) + 0x10) + 0x1e8);
    ++*reinterpret_cast<int*>(mgr + 0x58);
    self[4] = 0;
    self[5] = 0;
    self[6] = 0;
    self[7] = mgr + 0x40;
    return self;
}

// Copy of a state holding a Value array, a counted-pointer array and one counted pointer.
// MS2-FUNCTIONAL: raw words; the arrays are grown through the exe's ResizeNoConstruct instances
// @0x1424dbd70
UPInt* FUN_1424dbd70(UPInt* self, UPInt vm, const UPInt* src)
{
    self[0] = vm;
    self[1] = 0;
    self[2] = 0;
    self[3] = 0;
    UPInt n = src[2];
    const Value* values = reinterpret_cast<const Value*>(src[1]);
    if (n)
    {
        FUN_142524ec0(self + 1, self + 1, n);
        FUN_1424f08d0(reinterpret_cast<Value*>(self[1]), n, values);
    }
    self[4] = 0;
    self[5] = 0;
    self[6] = 0;
    UPInt ptr = src[7];
    self[7] = ptr;
    ++*reinterpret_cast<int*>(ptr + 0x18);
    UPInt m = src[5];
    UPInt* from = reinterpret_cast<UPInt*>(src[4]);
    if (m)
    {
        UPInt old = self[5];
        FUN_142524d80(self + 4, self + 4, old + m);
        UPInt* to = reinterpret_cast<UPInt*>(self[4]) + old;
        for (; m; --m, ++from, ++to)
        {
            *to = *from;
            ++*reinterpret_cast<int*>(*to + 0x18);
        }
    }
    return self;
}

// ---- LoadQueueEntryMT_LoadMovie constructor (out of line in the exe; sfr_as3_16 inlines its own copy) ----
extern const void* DAT_14317d890[];      // LoadQueueEntryMT_LoadMovie vftable
void FUN_1426396b0(void* self, LoadQueueEntry* pentry, MovieImpl* pmovie);   // LoadQueueEntryMT::LoadQueueEntryMT
void FUN_14257dcb0(void* p);                                                 // Task release

// Starts the preload task (stripped players try the .gfx name first) and hands it to the task manager.
// MS2-FUNCTIONAL: raw words over the entry (its members are private to the class, whose inline constructor lives in
// sfr_as3_16); the cancel loop of the inline copy is not part of this constructor
// @0x1424d84e0
void* FUN_1424d84e0(void* self, LoadQueueEntry* pentry, MovieImpl* pmovie)
{
    UPInt* w = static_cast<UPInt*>(self);
    FUN_1426396b0(self, pentry, pmovie);
    w[0] = reinterpret_cast<UPInt>(DAT_14317d890);
    w[5] = 0;
    *reinterpret_cast<UByte*>(w + 6) = 0;
    *reinterpret_cast<UByte*>(w + 7) = 0;
    *reinterpret_cast<unsigned*>(reinterpret_cast<UByte*>(w) + 0x34) = 0;
    bool stripped = false;
    UPInt movie = w[3];
    UPInt main = *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(movie + 0x18) + 0x10) + 0x50);
    if (main)
    {
        void* def = reinterpret_cast<void* (*)(UPInt)>((*reinterpret_cast<void***>(main))[0x1e0 / 8])(main);
        unsigned flags = reinterpret_cast<unsigned (*)(void*)>((*reinterpret_cast<void***>(def))[0x58 / 8])(def);
        stripped = ((flags >> 4) & 1) != 0;
    }
    MoviePreloadTask* task = NULL;
    if (void* mem = Memory::pGlobalHeap->Alloc(0x50))
        task = ::new (mem) MoviePreloadTask(reinterpret_cast<MovieImpl*>(movie),
                                          *reinterpret_cast<const String*>(reinterpret_cast<UByte*>(pentry) + 0x18),
                                          stripped, *(reinterpret_cast<UByte*>(pentry) + 0x24) != 0);
    if (w[5])
        FUN_14257dcb0(reinterpret_cast<void*>(w[5]));
    w[5] = reinterpret_cast<UPInt>(task);
    void* bag = reinterpret_cast<void*>(movie + 0x10);
    void* tm = reinterpret_cast<void* (*)(void*, unsigned)>((*reinterpret_cast<void***>(bag))[0x18 / 8])(bag, 0x14);
    reinterpret_cast<void (*)(void*, void*)>((*reinterpret_cast<void***>(tm))[1])(tm, task);
    FUN_14257dcb0(tm);
    return self;
}
// ---- MovieRoot constructor ----
extern const void* DAT_14317d8d8[];      // MovieRoot vftable
extern const void* DAT_14317da88[];      // MovieRoot secondary vftable (+0x28)
extern const void* DAT_14317daa0[];      // MovieRoot keyboard-listener vftable (+0x38)
extern const void* DAT_14317eff8[];      // keyboard-listener forwarder vftable
void FUN_14257dc30(void* p);                 // RefCountImpl::AddRef
void FUN_142575ec0(void* pmovie, void* l);   // MovieImpl::SetKeyboardListener

// MS2-FUNCTIONAL: raw words over MovieRoot (several of its members are unrecovered gaps); the exe's dead store of the
// ASMovieRootBase vftable ahead of the final one is omitted
// @0x1424d8640
void* FUN_1424d8640(void* self, MemoryContextImpl* pctx, MovieImpl* pmovie, ASSupport* psupport)
{
    UPInt* w = static_cast<UPInt*>(self);
    UByte* b = static_cast<UByte*>(self);
    w[0] = reinterpret_cast<UPInt>(DAT_14317d8d8);
    *reinterpret_cast<unsigned*>(b + 8) = 1;
    w[2] = 0;
    if (psupport)
        FUN_14257dc30(psupport);
    w[3] = reinterpret_cast<UPInt>(psupport);
    b[0x20] = reinterpret_cast<UByte (*)(void*)>((*reinterpret_cast<void***>(psupport))[0x30 / 8])(psupport);
    *reinterpret_cast<unsigned*>(b + 0x30) = 0;
    b[0x34] = 0;
    w[5] = reinterpret_cast<UPInt>(DAT_14317da88);
    w[7] = reinterpret_cast<UPInt>(DAT_14317daa0);
    if (pctx)
        FUN_14257dc30(pctx);
    w[8] = reinterpret_cast<UPInt>(pctx);
    w[9] = 0;
    b[0x50] = 1;
    *reinterpret_cast<unsigned*>(b + 0x58) = 0;
    w[0xc] = 0;
    w[0xf] = 0;
    UPInt ctxw10 = reinterpret_cast<UPInt*>(pctx)[2];
    for (unsigned o = 0x88; o <= 0x118; o += 0x18)
    {
        w[o / 8] = 0;
        w[o / 8 + 1] = 0;
        w[o / 8 + 2] = 0;
    }
    // (the loop above covers the 7 three-word groups 0x88..0x120)
    w[0x148 / 8] = ctxw10;
    *reinterpret_cast<unsigned*>(b + 0x130) = 1;
    w[0x138 / 8] = 0;
    *reinterpret_cast<unsigned*>(b + 0x140) = 0;
    w[0x150 / 8] = 0;
    w[0x158 / 8] = 0;
    UPInt* sm = w + 0x160 / 8;
    UPInt asm_ = reinterpret_cast<UPInt*>(w[8])[3];
    for (unsigned i = 0; i < 0x3d; ++i)
        sm[i] = 0;
    sm[0x3d] = asm_;
    sm[0x3e] = reinterpret_cast<UPInt>(DAT_143a2d3d0);
    reinterpret_cast<ASStringManager*>(asm_)->InitBuiltinArray(reinterpret_cast<ASStringNodeHolder*>(sm), DAT_143a2d3d0, 0x3d);
    for (unsigned i = 0; i < 4; ++i)
    {
        UByte* e = b + 0x360 + i * 0xe0;
        *reinterpret_cast<UPInt*>(e) = 0;
        *reinterpret_cast<UPInt*>(e + 8) = 0;
        *reinterpret_cast<UPInt*>(e + 0x10) = 0;
        *reinterpret_cast<UPInt*>(e + 0x18) = 0;
        *reinterpret_cast<unsigned*>(e + 0x20) = 0;
        for (unsigned o = 0x2c; o <= 0xdc; o += 0xc)
            *reinterpret_cast<unsigned*>(e + o) = 0;
    }
    b[0x6e0] = 0;
    w[0x6e8 / 8] = 0;
    b[0x6f0] = 0;
    *reinterpret_cast<unsigned*>(b + 0x358) = 0;
    w[2] = reinterpret_cast<UPInt>(pmovie);
    pmovie->SetASMovieRoot(reinterpret_cast<ASMovieRootBase*>(self));
    UPInt heap = reinterpret_cast<UPInt*>(w[2])[8];   // MovieImpl +0x40: its heap
    UPInt* fwd = reinterpret_cast<UPInt*>(reinterpret_cast<void* (*)(UPInt, UPInt, UPInt)>((*reinterpret_cast<void***>(heap))[0x50 / 8])(heap, 0x10, 0));
    if (fwd)
    {
        fwd[1] = reinterpret_cast<UPInt>(pmovie);
        fwd[0] = reinterpret_cast<UPInt>(DAT_14317eff8);
    }
    reinterpret_cast<UPInt*>(pmovie)[7] = reinterpret_cast<UPInt>(fwd);
    FUN_142575ec0(pmovie, b + 0x38);
    w[0x80 / 8] = 0;
    unsigned* fl = reinterpret_cast<unsigned*>(reinterpret_cast<UByte*>(pmovie) + 0x3490);
    *fl = (*fl & 0xdf7fffffu) | 0x10400000u;
    b[0x6e1] = 0;
    return self;
}
// ---- Tracer constructor ----
extern const void* DAT_14317b938[];      // Tracer vftable
void FUN_142545310(const void* sv, UPInt* ret);                  // StringView::ToStringDataPtr
void FUN_1425247f0(void* arr, UPInt n);                          // array: resize
void FUN_142524040(void* arr, void* owner, UPInt n);             // array: reserve
void FUN_142524870(void* arr, UPInt n);                          // array: resize
void FUN_142522e50(void* arr, UPInt heap, UPInt cap);            // array: reserve (heap-owned)
void FUN_14252ecb0(void* vm, const void* error, const void* classInfo);   // VM: raise the error as an instance of the class
UPInt FUN_142524f60(UPInt vm, UPInt file, UPInt multiname);      // VM: class traits of a multiname (0 if unresolved)

namespace
{
inline UPInt& Sfr30Rd(UPInt base, UPInt off) { return *reinterpret_cast<UPInt*>(base + off); }
inline Value Sfr30InstanceValue(UPInt traits, Value::TraceNullType nn)
{
    return Value(*reinterpret_cast<InstanceTraits::Traits*>(traits), nn);
}
inline void Sfr30MarkReg(UPInt state, UPInt ind)
{
    UByte* bits = reinterpret_cast<UByte*>(Sfr30Rd(state, 0x78));
    bits[ind >> 3] = static_cast<UByte>(bits[ind >> 3] | (1u << (ind & 7)));
}
}

// The tracer's entry state: register 0 is the receiver, then undefined locals, then the typed parameters.
// MS2-FUNCTIONAL: raw words over the Tracer and its State (neither is modelled); the exe's inlined null-string special
// case of the verify-error argument is not reproduced
// @0x1424d9f30
UPInt* FUN_1424d9f30(UPInt* self, UPInt heap, UPInt body, UPInt ops, UPInt extra)
{
    self[3] = heap;
    self[0] = reinterpret_cast<UPInt>(DAT_14317b938);
    self[6] = extra;
    *reinterpret_cast<unsigned*>(self + 1) = 0;
    reinterpret_cast<UByte*>(self)[0xc] = 0;
    reinterpret_cast<UByte*>(self)[0x10] = 0;
    self[4] = body;
    self[5] = ops;
    self[7] = 0;
    const UPInt file = Sfr30Rd(body, 0x28);
    const UPInt abc = Sfr30Rd(file, 0x28);
    const UPInt methodInfo = reinterpret_cast<UPInt*>(Sfr30Rd(abc, 0x170))[*reinterpret_cast<int*>(body + 0x30)];
    UPInt sv = Sfr30Rd(methodInfo, 0x38);
    FUN_142545310(&sv, self + 8);
    self[10] = self[8];
    self[11] = self[9];
    self[0xc] = 0;
    self[0xd] = 0;
    for (unsigned off = 0x70; off <= 0xf0; off += 0x20)
    {
        UPInt* a = self + off / 8;
        a[0] = 0;
        a[1] = 0;
        a[2] = 0;
        a[3] = heap;
    }
    self[0x120 / 8] = 0;
    self[0x128 / 8] = 0;
    self[0x130 / 8] = 0;
    self[0x138 / 8] = heap;
    UPInt* sentinel = self + 0x110 / 8;
    sentinel[0] = reinterpret_cast<UPInt>(sentinel);
    sentinel[1] = reinterpret_cast<UPInt>(sentinel);

    const UPInt vm = Sfr30Rd(file, 0x20);
    reinterpret_cast<UByte*>(self)[0xc] = *reinterpret_cast<UByte*>(Sfr30Rd(vm, 0x20) + 0xc);
    *reinterpret_cast<unsigned*>(self + 1) = 3;
    self[0xc] = Sfr30Rd(vm, 0x78);
    if (self[0xc])
        --self[0xc];
    FUN_1425247f0(reinterpret_cast<void*>(ops), 0);
    if (self[9] > Sfr30Rd(ops, 0x10))
        FUN_142524040(reinterpret_cast<void*>(ops), reinterpret_cast<void*>(ops), self[9]);
    FUN_142524870(self + 0x1a, self[9]);

    // The entry State: owner, three Value-or-byte arrays and the register bit set.
    UPInt* state = static_cast<UPInt*>(reinterpret_cast<MemoryHeap*>(heap)->Alloc(0x88));
    if (state)
    {
        state[0] = reinterpret_cast<UPInt>(self);
        state[1] = 0;
        state[2] = 0;
        for (unsigned off = 0x18; off <= 0x58; off += 0x20)
        {
            UPInt* a = state + off / 8;
            a[0] = 0;
            a[1] = 0;
            a[2] = 0;
            a[3] = heap;
        }
        AllocInfo info(StatMV_VM_Tracer_Mem, 0, 0);
        const unsigned nregs = *reinterpret_cast<unsigned*>(methodInfo + 0x20);
        *reinterpret_cast<unsigned*>(state + 0x80 / 8) = nregs;
        const unsigned bytes = (nregs + 7) >> 3;
        void* bits = reinterpret_cast<MemoryHeap*>(heap)->Alloc(bytes, &info);
        state[0x78 / 8] = reinterpret_cast<UPInt>(bits);
        memset(bits, 0, bytes);
    }
    UPInt* states = self + 0xf0 / 8;
    {
        UPInt n = states[1] + 1;
        if (n >= states[2])
            FUN_142522e50(states, states[3], n + (n >> 2));
        states[1] = n;
        reinterpret_cast<UPInt*>(states[0])[n - 1] = reinterpret_cast<UPInt>(state);
    }

    // register 0: the receiver
    ArrayDH<Value>& regs = *reinterpret_cast<ArrayDH<Value>*>(state + 0x18 / 8);
    const UPInt owner = Sfr30Rd(body, 0x40);
    const UPInt objectITraits = Sfr30Rd(Sfr30Rd(Sfr30Rd(file, 0x20), 0x1f8), 0xc0);
    if (owner && (reinterpret_cast<UByte*>(owner)[0x68] >> 5 & 1))
        regs.PushBack(Value(*reinterpret_cast<ClassTraits::Traits*>(owner), Value::NotNull));
    else if (owner && (*reinterpret_cast<unsigned*>(body + 0x88) & 0x1f) != 0xe)
        regs.PushBack(Sfr30InstanceValue(owner, Value::NotNull));
    else
        regs.PushBack(Sfr30InstanceValue(objectITraits, Value::NotNull));
    Sfr30MarkReg(reinterpret_cast<UPInt>(state), 0);

    // undefined locals
    const UPInt abcInfo = Sfr30Rd(abc, 0xf8);
    const UPInt sig = reinterpret_cast<UPInt*>(abcInfo)[*reinterpret_cast<int*>(methodInfo + 0x18)];
    const int nlocals = *reinterpret_cast<int*>(methodInfo + 0x20);
    for (int i = 1; i < nlocals; ++i)
        regs.PushBack(Value());

    // typed parameters
    UPInt reg = 1;
    const UPInt nparams = Sfr30Rd(sig, 0x18);
    const unsigned* ids = reinterpret_cast<const unsigned*>(Sfr30Rd(sig, 0x10));
    for (UPInt i = 0; i < nparams; ++i)
    {
        const unsigned id = ids[i];
        const UPInt mn = id ? Sfr30Rd(abc, 0xb8) + UPInt(id) * 16 : abc + 0xe8;
        const UPInt cls = FUN_142524f60(vm, file, mn);
        if (!cls)
        {
            ASString name = reinterpret_cast<VMAbcFile*>(file)->GetInternedString(*reinterpret_cast<int*>(mn + 8));
            Value arg(name);
            VM::Error err(static_cast<VM::ErrorID>(0x3f6), *reinterpret_cast<VM*>(vm), arg);
            FUN_14252ecb0(reinterpret_cast<void*>(vm), &err, &fl::VerifyErrorCI);
            return self;
        }
        const UPInt t = Sfr30Rd(cls, 0xc0);
        const bool prim = t == Sfr30Rd(Sfr30Rd(vm, 0x220), 0xc0) || t == Sfr30Rd(Sfr30Rd(vm, 0x228), 0xc0) ||
                          t == Sfr30Rd(Sfr30Rd(vm, 0x218), 0xc0) || t == Sfr30Rd(Sfr30Rd(vm, 0x210), 0xc0);
        regs[reg] = Sfr30InstanceValue(t, prim ? Value::NotNull : Value::NullOrNot);
        Sfr30MarkReg(reinterpret_cast<UPInt>(state), reg);
        ++reg;
    }

    // the rest-array / arguments register
    const UByte flags = *reinterpret_cast<UByte*>(sig);
    if (flags & 5)
    {
        regs[reg] = Sfr30InstanceValue(Sfr30Rd(Sfr30Rd(vm, 0x238), 0xc0), Value::NotNull);
        Sfr30MarkReg(reinterpret_cast<UPInt>(state), reg);
    }

    // the entry block, linked at the head of the block list
    UPInt* node = static_cast<UPInt*>(reinterpret_cast<MemoryHeap*>(heap)->Alloc(0x28));
    if (node)
    {
        *reinterpret_cast<unsigned*>(node + 2) |= 1;
        *reinterpret_cast<unsigned*>(reinterpret_cast<UByte*>(node) + 0x14) = 0;
        node[3] = reinterpret_cast<UPInt>(state);
        node[4] = 0;
    }
    node[0] = sentinel[0];
    node[1] = reinterpret_cast<UPInt>(sentinel);
    reinterpret_cast<UPInt*>(sentinel[0])[1] = reinterpret_cast<UPInt>(node);
    sentinel[0] = reinterpret_cast<UPInt>(node);
    return self;
}
}} // namespace GFx::AS3

namespace Render {
// The TreeNode::NodeData vftable (0x14317b700), stored the way TreeContainer's and TreeShape's node data store theirs.
extern const void* const TreeNodeNodeDataVTable[];

// MS2-FUNCTIONAL: the exe sets Type, Flags and pVTable in an EntryData base constructor ahead of the members;
// EntryData has none here, so they are stored after them
// @0x1424d9310
TreeNode::NodeData::NodeData(ContextImpl::EntryData::EntryType type)
{
    Type = (UInt16)type;
    Flags = NF_Visible;
    pVTable = TreeNodeNodeDataVTable;
    AproxLocalBounds.Clear();
    AproxParentBounds.Clear();
}

// MS2-FUNCTIONAL: member-wise copy; the exe stores the EntryData vftable before the NodeData one
// @0x1424d9220
TreeNode::NodeData::NodeData(const NodeData& src)
    : ContextImpl::EntryData(src), M34(src.M34), States(src.States), Cx(src.Cx),
      AproxLocalBounds(src.AproxLocalBounds), AproxParentBounds(src.AproxParentBounds)
{
}

// The per-document text allocator constructor, out of line in the exe (inline in text_core.h), called with the
// storage of an Allocator already allocated.
// @0x1424d61c0
Text::Allocator* FUN_1424d61c0(Text::Allocator* self, MemoryHeap* pheap, UInt8 flags)
{
    return ::new ((void*)self) Text::Allocator(pheap, flags);
}
} // namespace Render

} // namespace Scaleform

// ---- (sfr24) bodies of the native methods the full exe links by name (work/sfr35/outside-units.tsv) ----
namespace Scaleform { namespace GFx { namespace AS3 {
// The source file name of the innermost call frame's ABC file (sfr_as3_17).
void Sfr33CurrentFrameFileName(const UByte* self, ASString& result);
}}}
// MovieRoot::GetMouseCursorType: the cursor name of mouse mouseIndex (sfr_as3_13).
void FUN_14250bad0(void* proot, Scaleform::GFx::ASString& result, Scaleform::UInt32 mouseIndex);

namespace Scaleform { namespace GFx { namespace AS3 {
namespace Classes { namespace fl_gfx {

// @0x1424c9aa0
void SystemEx::actionVerboseGet(bool& result)
{
    result = (static_cast<ASVM&>(GetVM()).GetMovieImpl()->Flags & MovieImpl::Flag_VerboseAction) != 0;
}

// @0x1424ca6a0
void SystemEx::getCodeFileName(ASString& result)
{
    Sfr33CurrentFrameFileName(reinterpret_cast<const UByte*>(&GetVM()), result);
}

// @0x1424caf20
void SystemEx::getStackTrace(ASString& result)
{
    GetVM().GetStackTraceASString(result);
}

// @0x1424cb740
void SystemEx::setBackgroundAlpha(const Value& result, Value::Number alpha)
{
    SF_UNUSED(result);
    static_cast<ASVM&>(GetVM()).GetMovieImpl()->AsMovie()->SetBackgroundAlpha((float)alpha);
}

// @0x1424c9b20
void FocusManager::alwaysEnableArrowKeysGet(bool& result)
{
    ASVM& vm = static_cast<ASVM&>(GetVM());
    if (vm.ExtensionsEnabled)
        result = vm.GetMovieImpl()->IsAlwaysEnableFocusArrowKeys();
}

// The two-bit setting is left at 1 for true, 0 (unset) for false.
// @0x1424c9b70
void FocusManager::alwaysEnableArrowKeysSet(const Value& result, bool v)
{
    SF_UNUSED(result);
    ASVM& vm = static_cast<ASVM&>(GetVM());
    if (vm.ExtensionsEnabled)
    {
        MovieImpl* pmovie = vm.GetMovieImpl();
        pmovie->Flags &= ~(3u << MovieImpl::Shift_AlwaysEnableArrowKeys);
        pmovie->Flags |= (UInt32)v << MovieImpl::Shift_AlwaysEnableArrowKeys;
    }
}

// @0x1424c9e60
void FocusManager::disableFocusKeysGet(bool& result)
{
    ASVM& vm = static_cast<ASVM&>(GetVM());
    if (vm.ExtensionsEnabled)
        result = vm.GetMovieImpl()->IsDisableFocusKeys();
}

// @0x1424c9eb0
void FocusManager::disableFocusKeysSet(const Value& result, bool v)
{
    SF_UNUSED(result);
    ASVM& vm = static_cast<ASVM&>(GetVM());
    if (vm.ExtensionsEnabled)
    {
        MovieImpl* pmovie = vm.GetMovieImpl();
        pmovie->Flags &= ~(3u << MovieImpl::Shift_DisableFocusKeys);
        pmovie->Flags |= (UInt32)v << MovieImpl::Shift_DisableFocusKeys;
    }
}

// @0x1424cb6c0
void FocusManager::numFocusGroupsGet(UInt32& result)
{
    result = static_cast<ASVM&>(GetVM()).GetMovieImpl()->FocusGroupsCnt;
}

// @0x1424cb910
void FocusManager::setFocusGroupMask(const Value& result, Instances::fl_display::InteractiveObject* obj, UInt32 mask)
{
    SF_UNUSED(result);
    ASVM& vm = static_cast<ASVM&>(GetVM());
    if (vm.ExtensionsEnabled && obj)
        static_cast<GFx::InteractiveObject*>(obj->pDispObj.GetPtr())->PropagateFocusGroupMask(mask);
}

// @0x1424cbd50
void FocusManager::setModalClip(const Value& result, Instances::fl_display::Sprite* sprite, UInt32 controllerIdx)
{
    SF_UNUSED(result);
    ASVM& vm = static_cast<ASVM&>(GetVM());
    if (vm.ExtensionsEnabled)
        vm.GetMovieImpl()->SetModalClip(sprite ? static_cast<GFx::Sprite*>(sprite->pDispObj.GetPtr()) : NULL,
                                        controllerIdx);
}

// @0x1424c9ef0
void Extensions::enabledGet(bool& result)
{
    result = static_cast<ASVM&>(GetVM()).ExtensionsEnabled;
}

// @0x1424c9f10
void Extensions::enabledSet(const Value& result, bool v)
{
    SF_UNUSED(result);
    static_cast<ASVM&>(GetVM()).ExtensionsEnabled = v;
}

// @0x1424cadf0
void Extensions::getMouseCursorType(ASString& result, UInt32 mouseIndex)
{
    FUN_14250bad0(static_cast<ASVM&>(GetVM()).GetMovieRoot(), result, mouseIndex);
}

// @0x1424cbd90
void Extensions::setMouseCursorType(const Value& result, const ASString& cursor, UInt32 mouseIndex)
{
    SF_UNUSED(result);
    static_cast<ASVM&>(GetVM()).GetMovieRoot()->SetMouseCursorType(cursor, mouseIndex);
}

// @0x1424cb2b0
void Extensions::isScaleformGet(bool& result)
{
    result = true;
}

// @0x1424cb610
void Extensions::noInvisibleAdvanceGet(bool& result)
{
    ASVM& vm = static_cast<ASVM&>(GetVM());
    if (vm.ExtensionsEnabled)
        result = vm.GetMovieImpl()->IsNoInvisibleAdvanceFlagSet();
}

// @0x1424cb640
void Extensions::noInvisibleAdvanceSet(const Value& result, bool v)
{
    SF_UNUSED(result);
    ASVM& vm = static_cast<ASVM&>(GetVM());
    if (vm.ExtensionsEnabled)
    {
        MovieImpl* pmovie = vm.GetMovieImpl();
        if (v)
            pmovie->Flags |= MovieImpl::Flag_NoInvisibleAdvance;
        else
            pmovie->Flags &= ~(UInt32)MovieImpl::Flag_NoInvisibleAdvance;
    }
}

// The interactive display object behind obj, or NULL.
static GFx::InteractiveObject* Sfr24IntObjOf(Instances::fl_display::InteractiveObject* obj)
{
    if (!obj || !obj->pDispObj || !obj->pDispObj->IsInteractiveObject())
        return NULL;
    return static_cast<GFx::InteractiveObject*>(obj->pDispObj.GetPtr());
}

// @0x1424cab60
void InteractiveObjectEx::getHitTestDisable(bool& result, Instances::fl_display::InteractiveObject* obj)
{
    GFx::InteractiveObject* pio = Sfr24IntObjOf(obj);
    result = pio ? (pio->Flags & GFx::InteractiveObject::Mask_HitTestDisable) != 0 : false;
}

// @0x1424cb940
void InteractiveObjectEx::setHitTestDisable(const Value& result, Instances::fl_display::InteractiveObject* obj, bool v)
{
    SF_UNUSED(result);
    if (GFx::InteractiveObject* pio = Sfr24IntObjOf(obj))
    {
        if (v)
            pio->Flags |= GFx::InteractiveObject::Mask_HitTestDisable;
        else
            pio->Flags &= ~(UInt32)GFx::InteractiveObject::Mask_HitTestDisable;
    }
}

// @0x1424cb1a0
void InteractiveObjectEx::getTopmostLevel(bool& result, Instances::fl_display::InteractiveObject* obj)
{
    GFx::InteractiveObject* pio = Sfr24IntObjOf(obj);
    result = pio ? pio->IsTopmostLevelFlagSet() : false;
}

// @0x1424cbef0
void InteractiveObjectEx::setTopmostLevel(const Value& result, Instances::fl_display::InteractiveObject* obj, bool v)
{
    SF_UNUSED(result);
    GFx::InteractiveObject* pio = Sfr24IntObjOf(obj);
    if (!pio)
        return;
    if (v)
        pio->DisplayObjectBase::Flags |= GFx::DisplayObjectBase::Mask_TopmostLevel;
    else
        pio->DisplayObjectBase::Flags &= (UInt16)~GFx::DisplayObjectBase::Mask_TopmostLevel;
    MovieImpl* pmovie = static_cast<ASVM&>(GetVM()).GetMovieImpl();
    if (pio->IsTopmostLevelFlagSet())
        pmovie->AddTopmostLevelCharacter(pio);
    else
        pmovie->RemoveTopmostLevelCharacter(pio);
}

// @0x1424cc0e0
void GamePad::supportsAnalogEvents(bool& result)
{
    result = false;
}

}} // namespace Classes::fl_gfx

namespace Instances { namespace fl_gfx {
// @0x1424c9dc0
void GamePadAnalogEvent::codeGet(UInt32& result) { result = Code; }
// @0x1424c9dd0
void GamePadAnalogEvent::codeSet(const Value& result, UInt32 v) { SF_UNUSED(result); Code = v; }
// @0x1424c9de0
void GamePadAnalogEvent::controllerIdxGet(UInt32& result) { result = ControllerIdx; }
// @0x1424c9df0
void GamePadAnalogEvent::controllerIdxSet(const Value& result, UInt32 v) { SF_UNUSED(result); ControllerIdx = v; }
// @0x1424cca00
void GamePadAnalogEvent::xvalueGet(Value::Number& result) { result = XValue; }
// @0x1424cca10
void GamePadAnalogEvent::xvalueSet(const Value& result, Value::Number v) { SF_UNUSED(result); XValue = v; }
// @0x1424cca20
void GamePadAnalogEvent::yvalueGet(Value::Number& result) { result = YValue; }
// @0x1424cca30
void GamePadAnalogEvent::yvalueSet(const Value& result, Value::Number v) { SF_UNUSED(result); YValue = v; }
}} // namespace Instances::fl_gfx

namespace Instances { namespace fl_media {
// @0x1424d19c0
void Sound::isBufferingGet(bool& result)
{
    SF_UNUSED(result);
    GetVM().GetUI().Output(FlashUI::Output_Warning, "The method Sound::isBufferingGet() is not implemented\n");
}

// @0x1424d19e0
void SoundChannel::leftPeakGet(Value::Number& result)
{
    SF_UNUSED(result);
    GetVM().GetUI().Output(FlashUI::Output_Warning, "The method SoundChannel::leftPeakGet() is not implemented\n");
}

// @0x1424d1de0
void SoundChannel::rightPeakGet(Value::Number& result)
{
    SF_UNUSED(result);
    GetVM().GetUI().Output(FlashUI::Output_Warning, "The method SoundChannel::rightPeakGet() is not implemented\n");
}

// @0x1424d20d0
void SoundChannel::stop(const Value& result)
{
    SF_UNUSED(result);
    if (pSoundObject)
        pSoundObject->Stop();
}

// @0x1424d1a00
void SoundTransform::leftToLeftGet(Value::Number& result)
{
    SF_UNUSED(result);
    GetVM().GetUI().Output(FlashUI::Output_Warning, "The method SoundTransform::leftToLeftGet() is not implemented\n");
}

// @0x1424d1a20
void SoundTransform::leftToLeftSet(const Value& result, Value::Number v)
{
    SF_UNUSED(result);
    SF_UNUSED(v);
    GetVM().GetUI().Output(FlashUI::Output_Warning, "The method SoundTransform::leftToLeftSet() is not implemented\n");
}

// @0x1424d1a40
void SoundTransform::leftToRightGet(Value::Number& result)
{
    SF_UNUSED(result);
    GetVM().GetUI().Output(FlashUI::Output_Warning, "The method SoundTransform::leftToRightGet() is not implemented\n");
}

// @0x1424d1a60
void SoundTransform::leftToRightSet(const Value& result, Value::Number v)
{
    SF_UNUSED(result);
    SF_UNUSED(v);
    GetVM().GetUI().Output(FlashUI::Output_Warning, "The method SoundTransform::leftToRightSet() is not implemented\n");
}

// @0x1424d1e00
void SoundTransform::rightToLeftGet(Value::Number& result)
{
    SF_UNUSED(result);
    GetVM().GetUI().Output(FlashUI::Output_Warning, "The method SoundTransform::rightToLeftGet() is not implemented\n");
}

// @0x1424d1e20
void SoundTransform::rightToLeftSet(const Value& result, Value::Number v)
{
    SF_UNUSED(result);
    SF_UNUSED(v);
    GetVM().GetUI().Output(FlashUI::Output_Warning, "The method SoundTransform::rightToLeftSet() is not implemented\n");
}

// @0x1424d1e40
void SoundTransform::rightToRightGet(Value::Number& result)
{
    SF_UNUSED(result);
    GetVM().GetUI().Output(FlashUI::Output_Warning, "The method SoundTransform::rightToRightGet() is not implemented\n");
}

// @0x1424d1e60
void SoundTransform::rightToRightSet(const Value& result, Value::Number v)
{
    SF_UNUSED(result);
    SF_UNUSED(v);
    GetVM().GetUI().Output(FlashUI::Output_Warning, "The method SoundTransform::rightToRightSet() is not implemented\n");
}

// @0x1424d1b40
void SoundTransform::panGet(Value::Number& result) { result = Pan; }
// @0x1424d1b50
void SoundTransform::panSet(const Value& result, Value::Number v) { SF_UNUSED(result); Pan = v; }
}} // namespace Instances::fl_media
}}} // namespace Scaleform::GFx::AS3

// MS2-PIN: ?Func@?$ThunkFunc0@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cdc40
// MS2-PIN: ?Func@?$ThunkFunc1@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cdcb0
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$01N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cdd40
// MS2-PIN: ?Func@?$ThunkFunc1@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cddb0
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$03N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cde40
// MS2-PIN: ?Func@?$ThunkFunc1@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cdeb0
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$05N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cdf40
// MS2-PIN: ?Func@?$ThunkFunc1@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cdfb0
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$07N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ce040
// MS2-PIN: ?Func@?$ThunkFunc1@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ce0b0
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$09N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ce140
// MS2-PIN: ?Func@?$ThunkFunc1@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ce1b0
// MS2-PIN: ?Func@?$ThunkFunc0@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ceb00
// MS2-PIN: ?Func@?$ThunkFunc0@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$00J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ceb60
// MS2-PIN: ?Func@?$ThunkFunc0@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VID3Info@fl_media@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cebc0
// MS2-PIN: ?Func@?$ThunkFunc0@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cec70
// MS2-PIN: ?Func@?$ThunkFunc0@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$03N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cecd0
// MS2-PIN: ?Func@?$ThunkFunc0@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$04VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ced40
// MS2-PIN: ?Func@?$ThunkFunc0@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cedb0
// MS2-PIN: ?Func@?$ThunkFunc2@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@PEAVURLRequest@fl_net@3456@PEAVSoundLoaderContext@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cedd0
// MS2-PIN: ?Func@?$ThunkFunc3@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$07VValue@456@NJPEAVSoundTransform@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cee20
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundChannel@fl_media@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cef10
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundChannel@fl_media@Instances@AS3@GFx@Scaleform@@$00N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cef80
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundChannel@fl_media@Instances@AS3@GFx@Scaleform@@$01N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ceff0
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundChannel@fl_media@Instances@AS3@GFx@Scaleform@@$02V?$SPtr@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cf060
// MS2-PIN: ?Func@?$ThunkFunc1@VSoundChannel@fl_media@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@PEAVSoundTransform@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cf110
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundChannel@fl_media@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cf150
// MS2-PIN: ?Func@?$ThunkFunc0@VClass@AS3@GFx@Scaleform@@$0A@VValue@234@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424d2160
// MS2-PIN: ?Func@?$ThunkFunc0@VClass@AS3@GFx@Scaleform@@$00J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424d2180
// MS2-PIN: ?Func@?$ThunkFunc0@VClass@AS3@GFx@Scaleform@@$01VASString@34@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424d21e0

// Hash add instances: the template body carries the line info, so the tags above do not pair them
// MS2-PIN: ??$add@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@@?$HashSetBase@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@H$01@2@V?$HashsetNodeEntry@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAXAEBU?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@1@_K@Z 0x1424d2be0
// MS2-PIN: ??$add@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@Scaleform@@@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAXAEBU?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@1@_K@Z 0x1424d3870
// MS2-PIN: ??$add@UNodeRef@?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@@?$HashSetBase@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@H$01@2@V?$HashsetNodeEntry@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAXAEBUNodeRef@?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@1@_K@Z 0x1424d39f0
// MS2-PIN: ??_7Camera@fl_media@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431780b0
// MS2-PIN: ??_7ID3Info@fl_media@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143178388
// MS2-PIN: ??_7Microphone@fl_media@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143178418
// MS2-PIN: ??_7Sound@fl_media@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143178908
// MS2-PIN: ??_7SoundChannel@fl_media@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143178b10
// MS2-PIN: ??_7SoundLoaderContext@fl_media@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143178d28
// MS2-PIN: ??_7SoundMixer@fl_media@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143178f30
// MS2-PIN: ??_7SoundTransform@fl_media@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143178708
// MS2-PIN: ??_7ID3Info@fl_media@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431782e8
// MS2-PIN: ??_7Sound@fl_media@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143178868
// MS2-PIN: ??_7SoundChannel@fl_media@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143178a68
// MS2-PIN: ??_7SoundLoaderContext@fl_media@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143178c78
// MS2-PIN: ??_7SoundTransform@fl_media@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143178660
// MS2-PIN: ??_7Camera@fl_media@Classes@AS3@GFx@Scaleform@@6B@ 0x143178140
// MS2-PIN: ??_7Microphone@fl_media@Classes@AS3@GFx@Scaleform@@6B@ 0x1431784a8
// MS2-PIN: ??_7SoundMixer@fl_media@Classes@AS3@GFx@Scaleform@@6B@ 0x143178fc0
// MS2-PIN: ??_7ID3Info@fl_media@Instances@AS3@GFx@Scaleform@@6B@ 0x143178220
// MS2-PIN: ??_7Sound@fl_media@Instances@AS3@GFx@Scaleform@@6B@ 0x1431787a0
// MS2-PIN: ??_7SoundChannel@fl_media@Instances@AS3@GFx@Scaleform@@6B@ 0x143178998
// MS2-PIN: ??_7SoundLoaderContext@fl_media@Instances@AS3@GFx@Scaleform@@6B@ 0x143178ba8
// MS2-PIN: ??_7SoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@6B@ 0x143178590
// MS2-PIN: ??_GCamera@fl_media@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424cfdd0
// MS2-PIN: ??_GID3Info@fl_media@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424cfec0
// MS2-PIN: ??_GMicrophone@fl_media@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d0080
// MS2-PIN: ??_GSound@fl_media@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d0170
// MS2-PIN: ??_GSoundChannel@fl_media@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d0330
// MS2-PIN: ??_GSoundLoaderContext@fl_media@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d0490
// MS2-PIN: ??_GSoundMixer@fl_media@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d05e0
// MS2-PIN: ??_GSoundTransform@fl_media@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d06d0
// MS2-PIN: ??_GID3Info@fl_media@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424cff50
// MS2-PIN: ??_GSound@fl_media@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d0200
// MS2-PIN: ??_GSoundChannel@fl_media@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d03c0
// MS2-PIN: ??_GSoundLoaderContext@fl_media@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d0520
// MS2-PIN: ??_GSoundTransform@fl_media@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d0760
// MS2-PIN: ??_GCamera@fl_media@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424cfe60
// MS2-PIN: ??_GMicrophone@fl_media@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d0110
// MS2-PIN: ??_GSoundMixer@fl_media@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d0670
// MS2-PIN: ??_GID3Info@fl_media@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424cffb0
// MS2-PIN: ??_GSoundChannel@fl_media@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d0420
// MS2-PIN: ??_GSoundLoaderContext@fl_media@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d0580
// MS2-PIN: ??_GSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d07c0
// MS2-PIN: ??_7XMLSignatureValidator@fl_security@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143176370
// MS2-PIN: ??_7XMLDocument@fl_xml@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143176de8
// MS2-PIN: ??_7XMLNode@fl_xml@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143176be8
// MS2-PIN: ??_7XMLNodeType@fl_xml@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143176e80
// MS2-PIN: ??_7XMLNodeType@fl_xml@Classes@AS3@GFx@Scaleform@@6B@ 0x143176f18
// MS2-PIN: ??_7XMLNode@fl_xml@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143176b48
// MS2-PIN: ??_7XMLDocument@fl_xml@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143176d40
// MS2-PIN: ??_7XMLNode@fl_xml@Instances@AS3@GFx@Scaleform@@6B@ 0x143176a80
// MS2-PIN: ??_7XMLDocument@fl_xml@Instances@AS3@GFx@Scaleform@@6B@ 0x143176c78
// MS2-PIN: ??1XMLNode@fl_xml@Instances@AS3@GFx@Scaleform@@UEAA@XZ 0x1424cd4f0
// MS2-PIN: ??_GXMLSignatureValidator@fl_security@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ccc40
// MS2-PIN: ??_GXMLDocument@fl_xml@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424cd610
// MS2-PIN: ??_GXMLNode@fl_xml@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424cd7f0
// MS2-PIN: ??_GXMLNodeType@fl_xml@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424cd940
// MS2-PIN: ??_GXMLNodeType@fl_xml@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424cd9d0
// MS2-PIN: ??_GXMLNode@fl_xml@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424cd880
// MS2-PIN: ??_GXMLDocument@fl_xml@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424cd6a0
// MS2-PIN: ??_GXMLNode@fl_xml@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424cd8e0
// MS2-PIN: ??_GXMLDocument@fl_xml@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424cd700
// MS2-PIN: ??_GSound@fl_media@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424d0260
// MS2-PIN: ??_7Prototype@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14317b4b0
// MS2-PIN: ??$add@UNodeRef@?$HashNode@UDynAttrsKey@Object@AS3@GFx@Scaleform@@VValue@345@UDynAttrsKeyHashFunctor@2345@@Scaleform@@@?$HashSetBase@U?$HashNode@UDynAttrsKey@Object@AS3@GFx@Scaleform@@VValue@345@UDynAttrsKeyHashFunctor@2345@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@UDynAttrsKey@Object@AS3@GFx@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@UDynAttrsKey@Object@AS3@GFx@Scaleform@@VValue@345@UDynAttrsKeyHashFunctor@2345@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAXAEBUNodeRef@?$HashNode@UDynAttrsKey@Object@AS3@GFx@Scaleform@@VValue@345@UDynAttrsKeyHashFunctor@2345@@1@_K@Z 0x1424d4600
// MS2-PIN: ??$add@UNodeRef@?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@Scaleform@@@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAXAEBUNodeRef@?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@1@_K@Z 0x1424d4dd0
// MS2-PIN: ??$add@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@?$HashSetBase@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@V54@U?$AllocatorLH@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@@4@@Scaleform@@AEAAXPEAXAEBV?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@1@_K@Z 0x1424d5020
// MS2-PIN: ??$add@U?$HashNode@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@KVASStringNodePtrHashFunc@AS3@GFx@2@@Scaleform@@@?$HashSetBase@U?$HashNode@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@KVASStringNodePtrHashFunc@AS3@GFx@2@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@$0BEN@@2@V?$HashsetNodeEntry@U?$HashNode@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@KVASStringNodePtrHashFunc@AS3@GFx@2@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAXAEBU?$HashNode@V?$Ptr@UASStringNode@GFx@Scaleform@@@Scaleform@@KVASStringNodePtrHashFunc@AS3@GFx@2@@1@_K@Z 0x1424d3530
// MS2-PIN: ??0?$ArrayDataDH@VValue@AS3@GFx@Scaleform@@U?$AllocatorDH@VValue@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAA@AEBU01@@Z 0x1424d5310
// MS2-PIN: ??0?$HashNode@UDynAttrsKey@Object@AS3@GFx@Scaleform@@VValue@345@UDynAttrsKeyHashFunctor@2345@@Scaleform@@QEAA@AEBU01@@Z 0x1424d5390
// MS2-PIN: ??0?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@Scaleform@@QEAA@AEBU01@@Z 0x1424d5420
// MS2-PIN: ??1?$ArrayDataBase@V?$SPtr@VNamespaceSet@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VNamespaceSet@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAA@XZ 0x1424dc530
// MS2-PIN: ??0Multiname@AS3@GFx@Scaleform@@QEAA@AEAVNamespace@Instances@123@AEBVValue@123@@Z 0x1424d8a90
// MS2-PIN: ??0ID3Info@fl_media@Instances@AS3@GFx@Scaleform@@QEAA@AEAVTraits@InstanceTraits@345@@Z 0x1424cf4f0 ; unique
// MS2-PIN: ??$AsString@N@Scaleform@@YA?AVString@0@AEBN@Z 0x1424d2410 ; unique
// MS2-PIN: ??$Format@HVString@Scaleform@@@Scaleform@@YA_KAEBVSink@MsgFormat@0@PEBDAEBHAEBVString@0@@Z 0x1424d25d0 ; unique
// MS2-PIN: ??$LowerBoundSliced@V?$ArrayDH_POD@_K$0BEI@UArrayDefaultPolicy@Scaleform@@@Scaleform@@_KP6A_NAEB_K0@Z@Alg@Scaleform@@YA_KAEBV?$ArrayDH_POD@_K$0BEI@UArrayDefaultPolicy@Scaleform@@@1@_K1AEB_KP6A_N22@Z@Z 0x1424d2780 ; unique
// MS2-PIN: ??1?$ArrayDataBase@UException@MethodBodyInfo@Abc@AS3@GFx@Scaleform@@U?$AllocatorLH@UException@MethodBodyInfo@Abc@AS3@GFx@Scaleform@@$0BFE@@6@UArrayDefaultPolicy@6@@Scaleform@@QEAA@XZ 0x1424dc800 ; unique
// MS2-PIN: ??1?$ArrayDataBase@V?$ArrayLH_POD@_K$0BFC@UArrayDefaultPolicy@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$ArrayLH_POD@_K$0BFC@UArrayDefaultPolicy@Scaleform@@@Scaleform@@$0BFE@@2@UArrayDefaultPolicy@2@@Scaleform@@QEAA@XZ 0x1424dc3d0 ; unique
// MS2-PIN: ??1?$ArrayDataBase@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAA@XZ 0x1424dc5b0 ; unique
// MS2-PIN: ??1?$ArrayDataBase@V?$SPtr@VVMAbcFile@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VVMAbcFile@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAA@XZ 0x1424dc6b0 ; unique
// MS2-PIN: ??1?$ArrayDataBase@V?$SPtr@VVMAbcFile@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VVMAbcFile@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAA@XZ 0x1424dc630 ; unique
// MS2-PIN: ??0AvmDisplayObj@AS3@GFx@Scaleform@@QEAA@PEAVDisplayObject@23@@Z 0x1424d6430 ; unique
// MS2-PIN: ??$add@UNodeRef@?$HashNode@VASString@GFx@Scaleform@@PEAVClass@AS3@23@VASStringNodeHashFunc@523@@Scaleform@@@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@PEAVClass@AS3@23@VASStringNodeHashFunc@523@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEJ@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@PEAVClass@AS3@23@VASStringNodeHashFunc@523@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAXAEBUNodeRef@?$HashNode@VASString@GFx@Scaleform@@PEAVClass@AS3@23@VASStringNodeHashFunc@523@@1@_K@Z 0x1424d4c10 ; unique
// MS2-PIN: ??_7AvmLoader@AS3@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@3@@ 0x14317de60
// MS2-PIN: ??_7AvmLoader@AS3@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@23@@ 0x14317e228
// MS2-PIN: ??_7AvmLoader@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317e238
// MS2-PIN: ??_7Stage@AS3@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@23@@ 0x14317d5f0
// MS2-PIN: ??$add@PEAVGASRefCountBase@AS3@GFx@Scaleform@@@?$HashSetBase@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@V54@U?$AllocatorLH@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@@4@@Scaleform@@AEAAXPEAXAEBQEAVGASRefCountBase@AS3@GFx@1@_K@Z 0x1424d29d0
// MS2-PIN: ??_7UDBase@Classes@AS3@GFx@Scaleform@@6B@ 0x14317f778
// MS2-PIN: ??_7VMAbcFile@AS3@GFx@Scaleform@@6B@ 0x14317b750
// MS2-PIN: ??_7VM@AS3@GFx@Scaleform@@6B@ 0x14317b858
// MS2-PIN: ??_7Anonimous@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14317b538
// MS2-PIN: ??_7Void@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14317b5c0
// MS2-PIN: ??_7ASVM@AS3@GFx@Scaleform@@6B@ 0x14317d8b0
// MS2-PIN: ??_7?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14313f368
// MS2-PIN: ??_7Root@?$RefCountCollector@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14317b010
// MS2-PIN: ??_7ASRefCountCollector@AS3@GFx@Scaleform@@6B@ 0x14317b048
// MS2-PIN: ??_7GASRefCountBase@AS3@GFx@Scaleform@@6B@ 0x14313f398
// MS2-PIN: ??_7Instance@AS3@GFx@Scaleform@@6B@ 0x14313f4d8
// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7?$RefCountBaseNTS@VAllocator@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7LoadQueueEntry@GFx@Scaleform@@6B@ 0x14317c9d8
// MS2-PIN: ??_7IntervalTimer@AS3@GFx@Scaleform@@6B@ 0x14317f258
// MS2-PIN: ??_7?$RefCountCollector@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14317b040
// MS2-PIN: ??_7XMLSupportImpl@AS3@GFx@Scaleform@@6B@ 0x14317f9e0
// MS2-PIN: ??_7AvmInteractiveObj@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317ca60
// MS2-PIN: ??_7AvmLoader@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317e330
// MS2-PIN: ??_7AvmLoader@AS3@GFx@Scaleform@@6B@ 0x14317e3e8
// MS2-PIN: ??_7Stage@AS3@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@3@@ 0x14317d220
// MS2-PIN: ??_7?$RefCountBase@V?$RefCountCollector@$0BED@@AS3@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x14317c9f8
// MS2-PIN: ??_7?$RefCountBase@VASIntervalTimerIntf@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x14317c9f8
// MS2-PIN: ??_7LoadQueueEntry@AS3@GFx@Scaleform@@6B@ 0x14317d888
// MS2-PIN: ??_7XMLSupport@AS3@GFx@Scaleform@@6B@ 0x14317b7b8
// MS2-PIN: ??_7AvmInteractiveObjBase@GFx@Scaleform@@6B@ 0x14317bfe8
// MS2-PIN: ??_7AvmDisplayObjContainerBase@GFx@Scaleform@@6B@ 0x14317c0a0
// MS2-PIN: ??_7AvmSpriteBase@GFx@Scaleform@@6B@ 0x14317c898
// MS2-PIN: ??_7AvmDisplayObj@AS3@GFx@Scaleform@@6B@ 0x14317c160
// MS2-PIN: ??_7AvmInteractiveObj@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317cb30
// MS2-PIN: ??_7AvmDisplayObjContainer@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317cbe8
// MS2-PIN: ??_7AvmDisplayObjContainer@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317cce0
// MS2-PIN: ??_7AvmDisplayObjContainer@AS3@GFx@Scaleform@@6B@ 0x14317cd98
// MS2-PIN: ??_7AvmSprite@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317ce80
// MS2-PIN: ??_7AvmSprite@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317cf78
// MS2-PIN: ??_7AvmSprite@AS3@GFx@Scaleform@@6BAvmDisplayObjContainer@123@@ 0x14317d030
// MS2-PIN: ??_7AvmSprite@AS3@GFx@Scaleform@@6BAvmSpriteBase@23@@ 0x14317d0f0
