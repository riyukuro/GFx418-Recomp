// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 collector finalization of the
// script objects and of the built-in prototypes (Finalize_GC: release what the collector does not own).
// MS2-UNIT: sfr_as2_05
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142941d70-0x142942930 .text$mn
// MS2-RANGE: 0x142942990-0x142942c00 .text$mn
// MS2-RANGE: 0x142942ca0-0x142942da0 .text$mn
// MS2-RANGE: 0x142942dd0-0x142942f00 .text$mn
// MS2-RANGE: 0x142942f10-0x142942fa0 .text$mn
// MS2-RANGE: 0x142942fc0-0x142942ff0 .text$mn
// MS2-RANGE: 0x142943020-0x1429431a0 .text$mn
// MS2-RANGE: 0x142950b40-0x1429531f0 .text$mn
// MS2-RANGE: 0x1429538a0-0x142953970 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_asstringhash.h"
#include "../include/gfx/gfx_imageresource.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The out-of-line destructors of the hash tables (exe COMDATs that the exe calls where cl inlines them).
void MemberHash_Destruct(ASStringHash_GC<Member>* phash);                         // exe 0x142924800
void WatchpointHash_Destruct(ASStringHash_GC<Object::Watchpoint>* phash);         // exe 0x1429246b0
void SharedObjectHash_Destruct(ASStringHash_GC<SharedObjectPtr>* phash);          // exe 0x1429248c0
void ProgressInfoHash_Destruct(StringHashLH<MovieClipLoader::ProgressDesc>* phash); // exe 0x142924ab0
// The out-of-line destructors of the text formats (the exe calls them; cl inlines the empty ~TextFormat).
void TextFormat_Destruct(Render::Text::TextFormat* pformat);                       // exe 0x1424aa0f0
void ParagraphFormat_Destruct(Render::Text::ParagraphFormat* pformat);             // exe 0x142606690

// @0x142942e70
void Object::Finalize_GC()
{
    MemberHash_Destruct(&Members);
    ResolveHandler.Finalize_GC();
    if (pWatchpoints)
    {
        WatchpointHash_Destruct(pWatchpoints);
        SF_FREE(pWatchpoints);
    }
    if (pUserDataHolder)
    {
        pUserDataHolder->NotifyDestroy(this);
        delete pUserDataHolder;
    }
}

// @0x142942b40
void ArrayObject::Finalize_GC()
{
    UPInt i, n;
    for (i = 0, n = Elements.GetSize(); i < n; i++)
    {
        Value* pval = Elements[i];
        if (pval)
            pval->Finalize_GC();
        SF_FREE(Elements[i]);
    }
    Elements.~ArrayObjectElements();
    StringValue.~StringLH();
    Object::Finalize_GC();
}

// @0x142942ca0
void BitmapData::Finalize_GC()
{
    pImageRes = 0;
    pMovieDef = 0;
    Object::Finalize_GC();
}

// @0x142942cf0
void BitmapFilterObject::Finalize_GC()
{
    Object::Finalize_GC();
    pFilter = 0;
}

// @0x142942d20
void ButtonObject::Finalize_GC()
{
    pButton.~WeakPtr<InteractiveObject>();
    Object::Finalize_GC();
}

// @0x142942d60
void ColorObject::Finalize_GC()
{
    pCharacter.~WeakPtr<InteractiveObject>();
    Object::Finalize_GC();
}

// @0x142942dd0
void MovieClipLoader::Finalize_GC()
{
    ProgressInfoHash_Destruct(&ProgressInfo);
    Object::Finalize_GC();
}

// @0x142942df0
void MovieClipObject::Finalize_GC()
{
    pSprite.~WeakPtr<Sprite>();
    Object::Finalize_GC();
}

// @0x142942e30
void NumberObject::Finalize_GC()
{
    StringValue.~String();
    Object::Finalize_GC();
}

// @0x142942f10
void SharedObject::Finalize_GC()
{
    Name.~String();
    LocalPath.~String();
    Object::Finalize_GC();
}

// @0x142942f80
void SharedObjectCtorFunction::Finalize_GC()
{
    SharedObjectHash_Destruct(&SharedObjects);
    Object::Finalize_GC();
}

// @0x142942fc0
void StringObject::Finalize_GC()
{
    sValue.~ASString();
    Object::Finalize_GC();
}

// @0x142943020
void SuperObject::Finalize_GC()
{
    Constructor.Finalize_GC();
    Object::Finalize_GC();
}

// @0x1429430b0
void TextFieldObject::Finalize_GC()
{
    pTextField.~WeakPtr<InteractiveObject>();
    SF_FREE(pIMECompositionStringStyles);
    Object::Finalize_GC();
}

// @0x142943100
void TextFormatObject::Finalize_GC()
{
    TextFormat_Destruct(&GetTextFormat());
    ParagraphFormat_Destruct(&GetParagraphFormat());
    Object::Finalize_GC();
}

// @0x142943130
void TextSnapshotObject::Finalize_GC()
{
    GetData().~StaticTextSnapshotData();
    Object::Finalize_GC();
}

// @0x142943150
void TransformObject::Finalize_GC()
{
    pMovieRoot = 0;
    TargetHandle.~Ptr<CharacterHandle>();
    Object::Finalize_GC();
}

// The prototypes (template Prototype<BaseClass>::Finalize_GC).
// @0x142941d70
template void Prototype<MatrixObject>::Finalize_GC();
// @0x142941dc0
template void Prototype<ArrayObject>::Finalize_GC();
// @0x142941eb0
template void Prototype<Math>::Finalize_GC();
// @0x142941f00
template void Prototype<DropShadowFilterObject>::Finalize_GC();
// @0x142941f60
template void Prototype<BitmapData>::Finalize_GC();
// @0x142941fe0
template void Prototype<BitmapFilterObject>::Finalize_GC();
// @0x142942040
template void Prototype<GlowFilterObject>::Finalize_GC();
// @0x1429420a0
template void Prototype<BooleanObject>::Finalize_GC();
// @0x1429420f0
template void Prototype<ButtonObject>::Finalize_GC();
// @0x142942160
template void Prototype<BlurFilterObject>::Finalize_GC();
// @0x1429421c0
template void Prototype<ColorObject>::Finalize_GC();
// @0x142942230
template void Prototype<ColorTransformObject>::Finalize_GC();
// @0x142942280
template void Prototype<DateObject>::Finalize_GC();
// @0x1429422d0
template void Prototype<BevelFilterObject>::Finalize_GC();
// @0x142942330
template void Prototype<AmpMarker>::Finalize_GC();
// @0x142942380
template void Prototype<ColorMatrixFilterObject>::Finalize_GC();
// @0x1429423e0
template void Prototype<KeyObject>::Finalize_GC();
// @0x142942430
template void Prototype<LoadVarsObject>::Finalize_GC();
// @0x142942480
template void Prototype<Selection>::Finalize_GC();
// @0x1429424d0
template void Prototype<ExternalInterface>::Finalize_GC();
// @0x142942520
template void Prototype<MouseObject>::Finalize_GC();
// @0x142942570
template void Prototype<MovieClipLoader>::Finalize_GC();
// @0x1429425c0
template void Prototype<MovieClipObject>::Finalize_GC();
// @0x142942630
template void Prototype<NumberObject>::Finalize_GC();
// @0x1429426a0
template void Prototype<Object>::Finalize_GC();
// @0x1429426f0
template void Prototype<PointObject>::Finalize_GC();
// @0x142942740
template void Prototype<RectangleObject>::Finalize_GC();
// @0x142942790
template void Prototype<AsBroadcaster>::Finalize_GC();
// MS2-FUNCTIONAL register allocation (this and the -1 of the two string releases swap rbx / rdi)
// @0x1429427e0
template void Prototype<SharedObject>::Finalize_GC();
// @0x142942880
template void Prototype<StageObject>::Finalize_GC();
// @0x1429428d0
template void Prototype<StringObject>::Finalize_GC();
// @0x142942990
template void Prototype<TextFieldObject>::Finalize_GC();
// @0x142942a10
template void Prototype<TextFormatObject>::Finalize_GC();
// @0x142942a70
template void Prototype<TextSnapshotObject>::Finalize_GC();
// @0x142942ac0
template void Prototype<TransformObject>::Finalize_GC();

// @0x1429530b0
bool ArrayObject::GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val)
{
    int idx;
    if ((idx = ParseIndex(name)) >= 0)
    {
        if (idx >= (int)Elements.GetSize() || Elements[idx] == 0)
        {
            val->SetUndefined();
            return true;
        }
        *val = *Elements[idx];
        return true;
    }
    else if (psc->GetBuiltin(ASBuiltin_length).CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive()))
    {
        // An overridden length of an empty array is kept as set (it may be negative).
        if (!LengthValueOverriden || Elements.GetSize() != 0)
        {
            val->SetInt((int)Elements.GetSize());
            LengthValueOverriden = false;
            return true;
        }
    }
    return Object::GetMemberRaw(psc, name, val);
}

// @0x1429538a0
bool StringObject::GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val)
{
    if (psc->GetBuiltin(ASBuiltin_length).CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive()))
    {
        if (!Object::GetMemberRaw(psc, name, val) || !val->IsSet())
            val->SetInt(sValue.GetLength());
        return true;
    }
    if (Object::GetMemberRaw(psc, name, val))
        return true;
    return false;
}

// Prototype<BaseClass>::GetMemberRaw: "constructor" and "__constructor__" are answered by the prototype part.
template<class BaseClass, class GASEnvironment>
bool Prototype<BaseClass, GASEnvironment>::GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val)
{
    bool isConstructor2 =
        psc->GetBuiltin(ASBuiltin___constructor__).CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive());
    if (isConstructor2 ||
        psc->GetBuiltin(ASBuiltin_constructor).CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive()))
    {
        return GetMemberRawConstructor(this, psc, name, val, isConstructor2);
    }
    return BaseClass::GetMemberRaw(psc, name, val);
}

// @0x142950b40
template bool Prototype<MatrixObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142950c40
template bool Prototype<ArrayObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142950e30
template bool Prototype<Math>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142950f30
template bool Prototype<MovieClipLoader>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951030
template bool Prototype<BitmapData>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951130
template bool Prototype<BitmapFilterObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951230
template bool Prototype<ColorObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951330
template bool Prototype<BooleanObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951430
template bool Prototype<ButtonObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951530
template bool Prototype<DropShadowFilterObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951630
template bool Prototype<BlurFilterObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951730
template bool Prototype<ColorTransformObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951830
template bool Prototype<DateObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951930
template bool Prototype<BevelFilterObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951a30
template bool Prototype<AmpMarker>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951b30
template bool Prototype<ColorMatrixFilterObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951c30
template bool Prototype<KeyObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951d30
template bool Prototype<LoadVarsObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951e30
template bool Prototype<Selection>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142951f30
template bool Prototype<ExternalInterface>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952030
template bool Prototype<MouseObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952130
template bool Prototype<GlowFilterObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952230
template bool Prototype<MovieClipObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952330
template bool Prototype<NumberObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952430
template bool Prototype<Object>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952530
template bool Prototype<PointObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952630
template bool Prototype<RectangleObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952730
template bool Prototype<AsBroadcaster>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952830
template bool Prototype<SharedObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952930
template bool Prototype<StageObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952a30
template bool Prototype<StringObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952bb0
template bool Prototype<StyleSheetObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952cb0
template bool Prototype<TextFieldObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952db0
template bool Prototype<TextFormatObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952eb0
template bool Prototype<TextSnapshotObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);
// @0x142952fb0
template bool Prototype<TransformObject>::GetMemberRaw(ASStringContext*, const ASString&, Value*);

}}} // namespace Scaleform::GFx::AS2
// MS2-PIN: ?Finalize_GC@?$Prototype@VSharedObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@MEAAXXZ 0x1429427e0
