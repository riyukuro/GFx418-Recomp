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
// Render::Text::DocView by address (render/text_docview.h needs the full kernel array headers, not the ones of
// this unit; see sfr_as2_02.cpp).
void  FUN_14260cc10(void* pdoc, Render::Text::Allocator* palloc, Render::Text::FontManagerBase* pfontMgr, void* plog);  // DocView::DocView
void  FUN_14260f920(void* pdoc);                                  // DocView::Format
float FUN_1426134d0(void* pdoc);                                  // DocView::GetTextHeight
float FUN_142613510(void* pdoc);                                  // DocView::GetTextWidth
void  FUN_1426150b0(void* pdoc);                                  // DocView::SetAutoSizeX
void  FUN_1426150d0(void* pdoc);                                  // DocView::SetAutoSizeY
void  FUN_1426155e0(void* pdoc, const char* putf8Str, unsigned long long size);  // DocView::SetText
void  FUN_142615910(void* pdoc);                                  // DocView::SetWordWrap
void  FUN_1426156d0(void* pdoc, const void* prect, int useType);  // DocView::SetViewRect
void  FUN_14259c250(void* pst, const Render::Text::TextFormat& fmt);       // StyledText::SetDefaultTextFormat
void  FUN_14259c170(void* pst, const Render::Text::ParagraphFormat& fmt);  // StyledText::SetDefaultParagraphFormat
void  FUN_14257dcb0(void* pobj);                                  // RefCountBase release
Render::Text::Allocator* FUN_14256fdd0(void* pmovieCtx);
void FUN_142614e30(void* psubst, void* pimageDesc);  // ImageSubstitutor::RemoveImageDesc
void* FUN_142936510(TextField* ptf);                  // TextField::CreateImageSubstitutor
void  FUN_1425bb680(TextField* ptf, const char* pid); // TextField::RemoveIdImageDescAssoc

// The movie context the text allocator hangs off: the character's movie, +0x10 of its +0x20 member.
static inline void* MS2_AS2_TextAllocatorOwner(InteractiveObject* ptarget)
{
    return *(void**)(*(char**)((char*)ptarget + 0x20) + 0x10);
}

// The movie's image creator.
static inline Ptr<ImageCreator> MS2_AS2_GetImageCreator(MovieDefImpl* pmd)
{
    return *static_cast<ImageCreator*>(pmd->GetStateAddRef(State::State_ImageCreator));
}

// The substitution's image from a BitmapData: a Render::Image is shared as is; an image source is made into an
// image by the movie's image creator (a warning and no image when the movie has none).
static void MS2_AS2_SetSubstituteImage(TextField* ptf, Render::Text::ImageDesc* pdesc, BitmapData* pbmp)
{
    ImageResource*     pimageRes = pbmp->pImageRes;
    Ptr<MovieDefImpl>  pmd       = ptf->GetResourceMovieDef();
    Ptr<Render::Image> pimg;
    if (pimageRes->GetImage()->GetImageType() != Render::ImageBase::Type_ImageBase)
        pimg = static_cast<Render::Image*>(pimageRes->GetImage());
    else if (!MS2_AS2_GetImageCreator(pmd))
        LogDebugMessage(Log_Warning, "ImageCreator is null in UpdateImageSubstitution");
    else
    {
        ImageCreateInfo cinfo(ImageCreateInfo::Create_SourceImage, Memory::GetHeapByAddress(ptf), 1,
                              Resource::Use_Bitmap);
        pimg = *MS2_AS2_GetImageCreator(pmd)->CreateImage(cinfo,
                                                           static_cast<Render::ImageSource*>(pimageRes->GetImage()));
    }
    pdesc->pImage = pimg;
    ptf->SetDirtyFlag();
}

// The DocView fields the extent measure sets (exe layout).
inline void* DocView_GetStyledText(void* pdoc) { return *(void**)((char*)pdoc + 0x10); }
inline Render::Text::FontManagerBase* DocView_GetFontManager(void* pdoc)
{
    return *(Render::Text::FontManagerBase**)((char*)pdoc + 0x18);
}
inline void DocView_SetFlag(void* pdoc, unsigned off, unsigned bit)
{
    void* pst = DocView_GetStyledText(pdoc);
    *((unsigned char*)pst + off) |= (unsigned char)bit;
}
inline void DocView_SetMultiline(void* pdoc) { *((unsigned char*)pdoc + 0x149) |= 4; }
inline void DocView_ClearMultiline(void* pdoc) { *((unsigned char*)pdoc + 0x149) &= 0xfe; }

inline void DocView_SetReformatReq(void* pdoc) { *((unsigned char*)pdoc + 0x14b) |= 2; }

// TextFormat.getTextExtent(text [, width]): the size and font metrics of the text in the format, as an object.
// MS2-FUNCTIONAL the metrics are the same expressions; register allocation and stack layout differ from the exe
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
    InteractiveObject* ptarget = fn.Env->GetTarget();
    if (!ptarget)
        return;
    Ptr<InteractiveObject> holdTarget = ptarget;
    TextFormatObject*      pfmtObj    = static_cast<TextFormatObject*>(fn.ThisPtr);

    Ptr<Object> pres = *SF_HEAP_NEW(fn.Env->GetHeap()) Object(fn.Env);
    ASString    text = fn.Arg(0).ToString(fn.Env);

    void* pdoc = SF_HEAP_AUTO_ALLOC(ptarget, 0x150);
    FUN_14260cc10(pdoc, FUN_14256fdd0(MS2_AS2_TextAllocatorOwner(ptarget)), reinterpret_cast<Render::Text::FontManagerBase*>(ptarget->GetFontManager()), 0);
    DocView_SetFlag(pdoc, 0x40, 2);
    FUN_1426150b0(pdoc);
    FUN_1426150d0(pdoc);
    if (fn.Env->CheckExtensions() && fn.NArgs > 1)
    {
        float width = float(fn.Arg(1).ToNumber(fn.Env));
        DocView_ClearMultiline(pdoc);
        FUN_142615910(pdoc);
        float rect[4] = {0, 0, width * 20.0f, 0};
        FUN_1426156d0(pdoc, rect, 1);
    }
    DocView_SetMultiline(pdoc);

    MemoryHeap*                    pheap = fn.Env->GetHeap();
    Render::Text::TextFormat       textFmt(pheap);
    Render::Text::ParagraphFormat  paraFmt;
    textFmt.InitByDefaultValues();
    paraFmt.InitByDefaultValues();
    textFmt = textFmt.Merge(pfmtObj->GetTextFormat());
    paraFmt = paraFmt.Merge(pfmtObj->GetParagraphFormat());
    void* pstyled = DocView_GetStyledText(pdoc);
    FUN_14259c250(pstyled, textFmt);
    FUN_14259c170(pstyled, paraFmt);
    FUN_1426155e0(pdoc, text.ToCStr(), ~0ull);
    FUN_14260f920(pdoc);

    const Double kGutter = 80.0;
    const Double kScale  = 0.05;
    pres->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("textFieldWidth"),
                       Value((Double(FUN_142613510(pdoc)) + kGutter) * kScale));
    pres->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("textFieldHeight"),
                       Value((Double(FUN_1426134d0(pdoc)) + kGutter) * kScale));
    pres->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("width"), Value(Double(FUN_142613510(pdoc)) * kScale));
    pres->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("height"), Value(Double(FUN_1426134d0(pdoc)) * kScale));

    // ascent and descent of the first font of the list, scaled by the font size
    Ptr<Render::Text::FontHandle> pfont = *DocView_GetFontManager(pdoc)->CreateFontHandle(
        textFmt.GetFontList().ToCStr(), textFmt.IsBold(), textFmt.IsItalic(), false, false);
    Double fontAscent = 0, fontDescent = 0;
    if (pfont)
    {
        fontAscent  = Double(pfont->GetFont()->GetAscent());
        fontDescent = Double(pfont->GetFont()->GetDescent());
    }
    if (fontAscent == 0.0)
        fontAscent = 960.0;
    if (fontDescent == 0.0)
        fontDescent = 1024.0 - fontAscent;
    Double sizeScale = Double(float(textFmt.GetFontSizeInFixp()) * 0.05f) * 20.0 * (1.0 / 1024.0);
    unsigned descent = unsigned(SInt64(sizeScale * fontDescent * kScale));
    unsigned ascent  = unsigned(SInt64(sizeScale * fontAscent * kScale));
    pres->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("ascent"), Value(Double(ascent)));
    pres->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("descent"), Value(Double(descent)));
    fn.Result->SetAsObject(pres);
    if (pfont)
        pfont = 0;
    FUN_14257dcb0(pdoc);
}

// The field's StringHashLH<Ptr<ImageDesc>> of images by id (+0x120).
static inline StringHashLH<Ptr<Render::Text::ImageDesc> >* MS2_TextImageDescHash(TextField* ptf)
{
    return *reinterpret_cast<StringHashLH<Ptr<Render::Text::ImageDesc> >**>(reinterpret_cast<char*>(ptf) + 0x120);
}

// The field as a TextField through its character (TextField is opaque here).
static inline TextField* MS2_ThisTextField(const FnCall& fn)
{
    return reinterpret_cast<TextField*>(fn.ThisPtr);
}

// updateImageSubstitution(id [, image]): swaps the image of a substitution (or removes it for null / undefined).
// MS2-FUNCTIONAL: register allocation and stack layout differ.
// @0x14290b4c0
void AvmTextField::UpdateImageSubstitution(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (!fn.ThisPtr || fn.ThisPtr->GetObjectType() != Object::Object_TextField)
        return;
    TextField* ptf = MS2_ThisTextField(fn);
    if (fn.NArgs < 1)
        return;
    ASString id = fn.Arg(0).ToString(fn.Env);
    StringHashLH<Ptr<Render::Text::ImageDesc> >* phash = MS2_TextImageDescHash(ptf);
    if (!phash)
        return;
    Ptr<Render::Text::ImageDesc>* pentry = phash->Get(String(id.ToCStr()));
    if (!pentry || fn.NArgs < 2)
        return;
    Render::Text::ImageDesc* pdesc = pentry->GetPtr();
    const Value&             arg1  = fn.Arg(1);
    if (!arg1.IsNull() && !arg1.IsUndefined())
    {
        // an Image object replaces the description's image
        Object* pobj = arg1.ToObject(fn.Env);
        if (!pobj || pobj->GetObjectType() != Object::Object_BitmapData)
            return;
        MS2_AS2_SetSubstituteImage(ptf, pdesc, static_cast<BitmapData*>(pobj));
        return;
    }
    void* psubst = FUN_142936510(ptf);
    if (psubst)
    {
        FUN_142614e30(psubst, pdesc);
        DocView_SetReformatReq(ptf->GetDocument());
        FUN_1425bb680(ptf, id.ToCStr());
        ptf->SetDirtyFlag();
    }
}

}}} // namespace Scaleform::GFx::AS2
