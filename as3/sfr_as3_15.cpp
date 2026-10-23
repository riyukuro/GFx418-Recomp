// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_15
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424c9700-0x1424dc870 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_xml.h"
#include "ms2/scaleform/include/gfx/gfx_sprite.h"
#include "ms2/scaleform/include/render/render_shapedata.h"
#include "ms2/scaleform/include/gfx/gfx_rendertree.h"
#include "ms2/scaleform/include/gfx/gfx_movieslots.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_mnhash.h"
#include "ms2/scaleform/include/gfx/gfx_interactiveobject.h"

// Bodies of the exe called here (not recovered yet), by their addresses.
// The movie whose library an AS3 object's class came from.
Scaleform::GFx::MovieDefImpl* FUN_14250d8f0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Instances::fl::Object* pobj);
// VM::IsOfType(v, class name).
bool FUN_1425145d0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v, const char* className);
// VM::describeTypeEx (returns the ASString through a hidden pointer)
Scaleform::GFx::ASString* FUN_1425322c0(Scaleform::GFx::AS3::VM* vm, void* result, const Scaleform::GFx::AS3::Value& v);
void FUN_1425bc060(void* ptf);                          // TextField::SetDirtyFlag

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

    // MS2-FUNCTIONAL: same source; the exe schedules the vftable store and the first empty-string load of the inlined ID3Info ctor differently
    // @0x1424d15d0
    void ID3Info::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424cf800
    Sound::Sound(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x78);
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

    // @0x1424d1850
    void SoundTransform::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }
}}

namespace Instances { namespace fl_media
{
    // @0x1424cf4f0
    ID3Info::ID3Info(InstanceTraits::Traits& t)
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
                context = static_cast<Instances::fl_media::SoundLoaderContext*>(argv[1].GetObject());
            Value result;
            load(result, stream, context);
        }
    }

    // MS2-FUNCTIONAL: same control flow; the exe keeps found inverted and allocates the name/symbol stack slots the other way round
    // @0x1424d1130
    void Sound::InitInstance(bool extCall)
    {
        if (extCall || pResource)
            return;
        ASVM& vm = static_cast<ASVM&>(GetVM());
        MovieDefImpl* pdefImpl = FUN_14250d8f0(vm, this);
        if (!pdefImpl || !GetTraits().IsAbcObject())
            return;
        bool found;
        ASString name = GetTraits().GetQualifiedName(Traits::qnfWithDot);
        ResourceBindData data;
        {
            String symbol(name.ToCStr());
            found = vm.GetMovieImpl()->FindExportedResource(pdefImpl, &data, symbol);
        }
        if (!found)
            return;
        if (data.pResource && (data.pResource->GetResourceTypeCode() & Resource::MakeTypeCode(Resource::RT_SoundSample)))
            pResource = static_cast<SoundResource*>(data.pResource.GetPtr());
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
// @0x1424dc260
template ArrayDataBase<Render::FillStyleType, AllocatorLH<Render::FillStyleType, 2>, ArrayDefaultPolicy>::~ArrayDataBase();
// @0x1424dc350
template ArrayDataBase<Render::StrokeStyleType, AllocatorLH<Render::StrokeStyleType, 2>, ArrayDefaultPolicy>::~ArrayDataBase();
// @0x1424dc440
template ArrayDataBase<GFx::AS3::SPtr<GFx::ASStringNode>,
                       AllocatorLH<GFx::AS3::SPtr<GFx::ASStringNode>, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
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
typedef HashNode<GFx::AS3::Object::DynAttrsKey, GFx::AS3::Value, GFx::AS3::Object::DynAttrsKeyHashFunctor> MS2_DynAttrsNode;
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

// @0x1424dbf70
Value::Value(const ASString& v)
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
}} // namespace GFx::AS3

} // namespace Scaleform

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
