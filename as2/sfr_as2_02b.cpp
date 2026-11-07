// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 TextFormat.getTextExtent and
// the text field image substitution update (gap recovery of sfr_as2_02).
// MS2-UNIT: sfr_as2_02b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429006a0-0x142900f4a .text$mn
// MS2-RANGE: 0x14290b4c0-0x14290b91e .text$mn

#define MS2_AS2_TEXTSNAPSHOT_CTOR_INLINE // MovieClip.getTextSnapshot inlines the TextSnapshotObject ctor
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/as2/as2_keyobject.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_refcountcollector.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/gfx_asstringhash.h"
#include "../include/gfx/gfx_event.h"
#include "../include/gfx/gfx_textfield.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_imagecreator.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_placeobject.h"
#include "../include/video/video_statebag.h"
#include "../include/kernel/sf_alg.h"
#include "../include/kernel/sf_msgformat.h"
#include "../include/kernel/sf_stringhash.h"
#include "../include/render/render_twips.h"
#include "../include/render/render_screentoworld.h"
#include "../include/kernel/sf_std.h"
#include "../include/render/text_core.h"
#include "../include/render/text_fontmanager.h"
#include "../include/render/render_font.h"

namespace Scaleform {
void LogDebugMessage(LogMessageId id, const char* fmt, ...);
}

namespace Scaleform { namespace GFx { namespace AS2 {

// The text allocator of the movie a character belongs to (the exe reads it through the character's movie pointers).
void* FUN_142936510(TextField* ptf);                  // TextField::CreateImageSubstitutor

// The movie's image creator.
static inline Ptr<ImageCreator> MS2_AS2_GetImageCreator(MovieDefImpl* pmd)
{
    return *static_cast<ImageCreator*>(pmd->GetStateAddRef(State::State_ImageCreator));
}

// The DocView flag the image substitution update sets (exe layout).

inline void DocView_SetReformatReq(void* pdoc) { *((unsigned char*)pdoc + 0x14b) |= 2; }

// The SDK's header-inline ObjectInterface::SetConstMemberRaw, which the exe inlines here.
static SF_FORCEINLINE bool GteSetConstMemberRaw(ObjectInterface& obj, ASStringContext* psc, const char* pname, const Value& val)
{
    return obj.SetMemberRaw(psc, ASString(psc->CreateConstString(pname)), val);
}

// FnCall::Arg(0) with the PagedStack::Bottom body, which the exe inlines here.
static SF_FORCEINLINE Value& GteArg0(const FnCall& fn)
{
    unsigned offset = (unsigned)fn.FirstArgBottomIndex;
    Value*   p      = 0;
    if (offset <= fn.Env->Stack.GetTopIndex())
        p = &fn.Env->Stack.Pages[offset / 32]->Values[offset % 32];
    return *p;
}

#ifndef GFX_TEXT_GUTTER
#define GFX_TEXT_GUTTER 40 // 2 pixels in twips (text_linebuffer.h)
#endif

// TextFormat.getTextExtent(text [, width]): the size and font metrics of the text in the format, as an object.
// @0x1429006a0
void TextFormatProto::GetTextExtent(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (fn.NArgs == 0)
        return;
    if (!fn.ThisPtr || fn.ThisPtr->GetObjectType() != Object::Object_TextFormat)
    {
        fn.Env->LogScriptError("Error: Null or invalid 'this' is used for a method of %s class.\n", "TextFormat");
        return;
    }
    TextFormatObject* pfmtObj = static_cast<TextFormatObject*>(fn.ThisPtr);
    Ptr<InteractiveObject> ptarget = fn.Env->GetTarget();
    if (ptarget)
    {
        Ptr<Object> pobj = *SF_HEAP_NEW(fn.Env->GetHeap()) Object(fn.Env);
        ASString str = GteArg0(fn).ToString(fn.Env);

        Ptr<Render::Text::DocView> pdocument =
            *SF_HEAP_NEW(fn.Env->GetHeap()) Render::Text::DocView(fn.Env->GetTarget()->GetMovieImpl()->GetTextAllocator(),
                reinterpret_cast<Render::Text::FontManagerBase*>(ptarget->GetFontManager()), NULL);
        pdocument->GetStyledText()->SetNewLine0D();
        pdocument->SetAutoSizeX();
        pdocument->SetAutoSizeY();
        if (fn.Env->GetVersion() >= 7)
        {
            if (fn.NArgs >= 2)
            {
                Number width = fn.Arg(1).ToNumber(fn.Env);
                pdocument->ClearAutoSizeX();
                pdocument->SetWordWrap();
                float x1 = 0, y1 = 0;
                Render::RectF vr(x1, y1, x1 + Render::PixelsToTwips((float)width), y1 + 0);
                pdocument->SetViewRect(vr);
            }
        }
        pdocument->SetMultiline();

        Render::Text::TextFormat      eTextFmt(fn.Env->GetHeap());
        Render::Text::ParagraphFormat eParagraphFmt;
        eTextFmt.InitByDefaultValues();
        eParagraphFmt.InitByDefaultValues();
        // The exe calls the implicit TextFormat / ParagraphFormat operator= out of line.
        Render::Text::TextFormat& (Render::Text::TextFormat::*const assignText)(const Render::Text::TextFormat&) =
            &Render::Text::TextFormat::operator=;
        Render::Text::ParagraphFormat& (Render::Text::ParagraphFormat::*const assignPara)(const Render::Text::ParagraphFormat&) =
            &Render::Text::ParagraphFormat::operator=;
        (eTextFmt.*assignText)(eTextFmt.Merge(pfmtObj->GetTextFormat()));
        (eParagraphFmt.*assignPara)(eParagraphFmt.Merge(pfmtObj->GetParagraphFormat()));

        pdocument->SetDefaultTextFormat(eTextFmt);
        pdocument->SetDefaultParagraphFormat(eParagraphFmt);
        pdocument->SetText(str.ToCStr());
        pdocument->Format();

        GteSetConstMemberRaw(*pobj, fn.Env->GetSC(), "textFieldWidth",
            Value((Number)Render::TwipsToPixels((Double)pdocument->GetTextWidth() + GFX_TEXT_GUTTER*2)));
        GteSetConstMemberRaw(*pobj, fn.Env->GetSC(), "textFieldHeight",
            Value((Number)Render::TwipsToPixels((Double)pdocument->GetTextHeight() + GFX_TEXT_GUTTER*2)));
        GteSetConstMemberRaw(*pobj, fn.Env->GetSC(), "width",
            Value((Number)Render::TwipsToPixels((Double)pdocument->GetTextWidth())));
        GteSetConstMemberRaw(*pobj, fn.Env->GetSC(), "height",
            Value((Number)Render::TwipsToPixels((Double)pdocument->GetTextHeight())));

        // now determine the ascent and descent of used font
        Ptr<Render::Text::FontHandle> pfontHandle = *pdocument->GetFontManager()->CreateFontHandle(
            eTextFmt.GetFontList().ToCStr(),
            eTextFmt.IsBold(),
            eTextFmt.IsItalic(),
            true, true);
        Double ascent = 0, descent = 0;
        if (pfontHandle)
        {
            ascent  = pfontHandle->GetFont()->GetAscent();
            descent = pfontHandle->GetFont()->GetDescent();
        }
        if (ascent == 0)
            ascent = 960.f;
        if (descent == 0)
            descent = 1024.f - ascent;
        Double scale = Render::PixelsToTwips((Double)eTextFmt.GetFontSize()) / 1024.0f; // the EM square is 1024 x 1024
        unsigned uascent  = (unsigned)Render::TwipsToPixels(ascent * scale);
        unsigned udescent = (unsigned)Render::TwipsToPixels(descent * scale);
        GteSetConstMemberRaw(*pobj, fn.Env->GetSC(), "ascent", Value(Number(uascent)));
        GteSetConstMemberRaw(*pobj, fn.Env->GetSC(), "descent", Value(Number(udescent)));
        fn.Result->SetAsObject(pobj);
    }
}

// The field's StringHashLH<Ptr<ImageDesc>> of images by id (+0x120).
static inline StringHashLH<Ptr<Render::Text::ImageDesc> >* MS2_TextImageDescHash(TextField* ptf)
{
    return *reinterpret_cast<StringHashLH<Ptr<Render::Text::ImageDesc> >**>(reinterpret_cast<char*>(ptf) + 0x120);
}

// The field as a TextField through its character (TextField is opaque here).
static inline TextField* MS2_ThisTextField(const FnCall& fn)
{
    return reinterpret_cast<TextField*>(fn.ThisPtr->ToCharacter());
}

// updateImageSubstitution(id [, image]): swaps the image of a substitution (or removes it for null / undefined).
// MS2-FUNCTIONAL: SDK body; the inlined StringHashLH Get loop keeps the key String's data in r11 (the exe in rdx, the free arg), one byte longer
// @0x14290b4c0
void AvmTextField::UpdateImageSubstitution(const FnCall& fn)
{
    fn.Result->SetBool(false);
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object::Object_TextField)
    {
        TextField* pthis = MS2_ThisTextField(fn);
        if (fn.NArgs >= 1)
        {
            ASString idStr = fn.Arg(0).ToString(fn.Env);
            StringHashLH<Ptr<Render::Text::ImageDesc> >* pimageDescAssoc = MS2_TextImageDescHash(pthis);
            if (pimageDescAssoc)
            {
                Ptr<Render::Text::ImageDesc>* ppimgDesc = pimageDescAssoc->Get(idStr.ToCStr());
                if (ppimgDesc)
                {
                    Render::Text::ImageDesc* pimageDesc = ppimgDesc->GetPtr();
                    if (fn.NArgs >= 2)
                    {
                        if (fn.Arg(1).IsNull() || fn.Arg(1).IsUndefined())
                        {
                            Render::Text::DocView::ImageSubstitutor* pimgSubst = static_cast<Render::Text::DocView::ImageSubstitutor*>(FUN_142936510(pthis));
                            if (pimgSubst)
                            {
                                pimgSubst->RemoveImageDesc(pimageDesc);
                                DocView_SetReformatReq(pthis->GetDocument());
                                pthis->RemoveIdImageDescAssoc(idStr.ToCStr());
                                pthis->SetDirtyFlag();
                            }
                        }
                        else
                        {
                            Object* piobj = fn.Arg(1).ToObject(fn.Env);
                            if (piobj && piobj->GetObjectType() == Object::Object_BitmapData)
                            {
                                BitmapData* pbmpData = static_cast<BitmapData*>(piobj);
                                ImageResource* pimgRes = pbmpData->pImageRes;
                                Ptr<MovieDefImpl> md = pthis->GetResourceMovieDef();
                                Ptr<Render::Image> img;
                                if (pimgRes->GetImage()->GetImageType() != Render::ImageBase::Type_ImageBase)
                                    img = static_cast<Render::Image*>(pimgRes->GetImage());
                                else
                                {
                                    if (!MS2_AS2_GetImageCreator(md))
                                        LogDebugMessage(Log_Warning, "ImageCreator is null in UpdateImageSubstitution");
                                    else
                                    {
                                        ImageCreateInfo cinfo(ImageCreateInfo::Create_SourceImage, Memory::GetHeapByAddress(pthis), 1,
                                                              Resource::Use_Bitmap);
                                        img = *MS2_AS2_GetImageCreator(md)->CreateImage(cinfo, static_cast<Render::ImageSource*>(pimgRes->GetImage()));
                                    }
                                }
                                pimageDesc->pImage = img;
                                pthis->SetDirtyFlag();
                            }
                        }
                    }
                }
            }
        }
    }
}

}}} // namespace Scaleform::GFx::AS2
