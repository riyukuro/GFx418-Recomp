// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 TextField.setImageSubstitutions
// element of sfr_as2_06 (gap recovery, lane sfr24): one { subString, image, width, height, baseLineX, baseLineY, id }
// object made an image substitution of the field's document.
// MS2-UNIT: sfr_as2_06s7
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14296f870-0x142970202 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_imagecreator.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_textfield.h"
#include "../include/render/text_core.h"
#include "../include/render/text_docview.h"
#include "../include/kernel/sf_utf8util.h"

namespace Scaleform {
void LogDebugMessage(LogMessageId id, const char* fmt, ...);
}

namespace Scaleform { namespace GFx { namespace AS2 {

// TextField::CreateImageSubstitutor: the document's substitutor, made on first use (sfr_as2_04l).
void* FUN_142936510(TextField* ptf);

// The movie's image creator.
static inline Ptr<ImageCreator> GetImageCreator(MovieDefImpl* pmd)
{
    return *static_cast<ImageCreator*>(pmd->GetStateAddRef(State::State_ImageCreator));
}

// Element idx (pve) of setImageSubstitutions: its subString (at most 15 characters) replaced by its image (a
// BitmapData) shown at width x height (the image's size by default) with the baseline at (baseLineX, baseLineY)
// (the bottom by default), and under id when it has one; a script warning when the element is not valid.
// MS2-FUNCTIONAL: register allocation and stack layout differ.
// @0x14296f870
void AvmTextField::ProceedImageSubstitution(const FnCall& fn, int idx, const Value* pve)
{
    typedef Render::Text::DocView::ImageSubstitutor ImageSubstitutor;
    if (!pve || !pve->IsObject())
        return;

    TextField* ptf  = static_cast<TextField*>(GetDispObj());
    Object*    pobj = pve->ToObject(fn.Env);
    Value      val;

    ImageSubstitutor* psubst = static_cast<ImageSubstitutor*>(FUN_142936510(ptf));
    if (!psubst)
        return;

    ImageSubstitutor::Element elem;
    if (!pobj->GetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("subString"), &val))
    {
        ptf->LogScriptWarning("%s.setImageSubstitutions() failed for #%d element - subString should be specified",
                              GetDispObj()->GetName().ToCStr(), idx);
        return;
    }
    {
        ASString       subString = val.ToString(fn.Env);
        const unsigned len       = subString.GetLength();
        if (len > 15)
        {
            ptf->LogScriptWarning(
                "%s.setImageSubstitutions() failed for #%d element - length of subString should not exceed 15 characters",
                GetDispObj()->GetName().ToCStr(), idx);
            return;
        }
        UTF8Util::DecodeString(elem.SubString, subString.ToCStr(), subString.GetSize() + 1);
        elem.SubStringLen = UByte(len);
    }

    Ptr<Render::Image> pimg;
    float screenWidth = 0, screenHeight = 0, baseLineX = 0, origWidth = 0, origHeight = 0;
    const char* pid = 0;
    if (pobj->GetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("image"), &val))
    {
        Object* pimgObj = val.ToObject(fn.Env);
        if (pimgObj && pimgObj->GetObjectType() == Object_BitmapData)
        {
            ImageResource*    pimageRes = static_cast<BitmapData*>(pimgObj)->pImageRes;
            Ptr<MovieDefImpl> pmd       = GetDispObj()->GetResourceMovieDef();
            if (pimageRes->GetImage()->GetImageType() != Render::ImageBase::Type_ImageBase)
                pimg = static_cast<Render::Image*>(pimageRes->GetImage());
            else if (!GetImageCreator(pmd))
                LogDebugMessage(Log_Warning, "ImageCreator is null in ProceedImageSubstitution");
            else
            {
                ImageCreateInfo cinfo(ImageCreateInfo::Create_SourceImage, Memory::GetHeapByAddress(this), 1,
                                      Resource::Use_Bitmap);
                pimg = *GetImageCreator(pmd)->CreateImage(cinfo,
                                                          static_cast<Render::ImageSource*>(pimageRes->GetImage()));
            }
            if (pimg)
            {
                const Render::ImageRect r = pimg->GetRect();
                origWidth    = float(UInt32(r.x2 - r.x1));
                origHeight   = float(UInt32(r.y2 - r.y1));
                screenWidth  = origWidth * 20.0f;
                screenHeight = origHeight * 20.0f;
                if (origWidth == 0 || origHeight == 0)
                {
                    ptf->LogScriptWarning(
                        "%s.setImageSubstitutions() failed for #%d element - image has one zero dimension",
                        GetDispObj()->GetName().ToCStr(), idx);
                    return;
                }
            }
        }
    }
    if (!pimg)
    {
        ptf->LogScriptWarning(
            "%s.setImageSubstitutions() failed for #%d element - 'image' is not specified or not a BitmapData",
            GetDispObj()->GetName().ToCStr(), idx);
        return;
    }

    // Sizes and the baseline in twips; the baseline defaults to the bottom.
    if (pobj->GetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("width"), &val))
        screenWidth = float(val.ToNumber(fn.Env) * 20.0);
    if (pobj->GetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("height"), &val))
        screenHeight = float(val.ToNumber(fn.Env) * 20.0);
    if (pobj->GetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("baseLineX"), &val))
        baseLineX = float(val.ToNumber(fn.Env) * 20.0);
    float baseLineY;
    if (pobj->GetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("baseLineY"), &val))
        baseLineY = float(val.ToNumber(fn.Env) * 20.0);
    else
        baseLineY = origHeight - 20.0f;
    if (pobj->GetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("id"), &val))
        pid = val.ToString(fn.Env).ToCStr();

    elem.pImageDesc = *SF_HEAP_NEW(fn.Env->GetHeap()) Render::Text::ImageDesc;
    elem.pImageDesc->pImage       = pimg;
    elem.pImageDesc->BaseLineX    = Render::TwipsToPixels(baseLineX);
    elem.pImageDesc->BaseLineY    = Render::TwipsToPixels(baseLineY);
    elem.pImageDesc->ScreenWidth  = screenWidth;
    elem.pImageDesc->ScreenHeight = screenHeight;
    if (pid)
        ptf->AddIdImageDescAssoc(pid, elem.pImageDesc);
    elem.pImageDesc->Matrix.Tx() += -elem.pImageDesc->BaseLineX;
    elem.pImageDesc->Matrix.Ty() += -elem.pImageDesc->BaseLineY;
    elem.pImageDesc->Matrix.AppendScaling(elem.pImageDesc->ScreenWidth / origWidth,
                                          elem.pImageDesc->ScreenHeight / origHeight);
    psubst->AddImageDesc(elem);
    ptf->GetDocument()->SetReformatReq();
    ptf->SetDirtyFlag();
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7ImageDesc@Text@Render@Scaleform@@6B@ 0x14317c9c0
// MS2-PIN: ??_7?$RefCountBaseNTS@UImageDesc@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
