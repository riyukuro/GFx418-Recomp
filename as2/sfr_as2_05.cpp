// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 collector finalization of the
// script objects and of the built-in prototypes (Finalize_GC: release what the collector does not own).
// MS2-UNIT: sfr_as2_05
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142939c20-0x142939c60 .text$mn
// MS2-RANGE: 0x142941d70-0x142942930 .text$mn
// MS2-RANGE: 0x142942990-0x142942c00 .text$mn
// MS2-RANGE: 0x142942ca0-0x142942da0 .text$mn
// MS2-RANGE: 0x142942dd0-0x142942f00 .text$mn
// MS2-RANGE: 0x142942f10-0x142942fa0 .text$mn
// MS2-RANGE: 0x142942fc0-0x142942ff0 .text$mn
// MS2-RANGE: 0x142943020-0x1429431a0 .text$mn
// MS2-RANGE: 0x142944c60-0x142944cb0 .text$mn
// MS2-RANGE: 0x142948f10-0x142949070 .text$mn
// MS2-RANGE: 0x142949080-0x1429490a0 .text$mn
// MS2-RANGE: 0x1429497f0-0x142949820 .text$mn
// MS2-RANGE: 0x142949840-0x142949860 .text$mn
// MS2-RANGE: 0x142949f60-0x14294a010 .text$mn
// MS2-RANGE: 0x14294a580-0x14294a5b0 .text$mn
// MS2-RANGE: 0x14294afc0-0x14294afe0 .text$mn
// MS2-RANGE: 0x14294b030-0x14294b080 .text$mn
// MS2-RANGE: 0x14294b210-0x14294b230 .text$mn
// MS2-RANGE: 0x14294b230-0x14294b250 .text$mn
// MS2-RANGE: 0x14294c700-0x14294c720 .text$mn
// MS2-RANGE: 0x14294f7d0-0x14294f7e0 .text$mn
// MS2-RANGE: 0x142950b40-0x1429531f0 .text$mn
// MS2-RANGE: 0x1429531f0-0x142953210 .text$mn
// MS2-RANGE: 0x1429538a0-0x142953970 .text$mn
// MS2-RANGE: 0x142953ee0-0x142953ef0 .text$mn
// MS2-RANGE: 0x142954b40-0x142954ba0 .text$mn
// MS2-RANGE: 0x142954ba0-0x142954c20 .text$mn
// MS2-RANGE: 0x1429561c0-0x1429561d0 .text$mn
// MS2-RANGE: 0x142956230-0x142956270 .text$mn
// MS2-RANGE: 0x1429566d0-0x142956730 .text$mn
// MS2-RANGE: 0x142956740-0x142956760 .text$mn
// MS2-RANGE: 0x142958370-0x1429583d0 .text$mn
// MS2-RANGE: 0x142958490-0x1429584b0 .text$mn
// MS2-RANGE: 0x14295ae20-0x14295ae40 .text$mn
// MS2-RANGE: 0x14295afb0-0x14295b020 .text$mn
// MS2-RANGE: 0x14295bbe0-0x14295bc00 .text$mn
// MS2-RANGE: 0x14295bc00-0x14295bc20 .text$mn
// MS2-RANGE: 0x14295bc20-0x14295bc40 .text$mn
// MS2-RANGE: 0x14295bc40-0x14295bca0 .text$mn
// MS2-RANGE: 0x14295c650-0x14295c670 .text$mn
// MS2-RANGE: 0x14295c6f0-0x14295c710 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_keyobject.h"
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

// The environment's view of its target and movie.

// @0x142949080
MovieRoot* Environment::GetAS2Root() const
{
    return static_cast<MovieRoot*>(Target->GetMovieImpl()->pASMovieRoot);
}

// @0x142949840
AvmCharacter* Environment::GetAvmTarget() const
{
    if (!Target)
        return 0;
    return ToAvmCharacter(Target);
}

// @0x14294b210
Log* Environment::GetLog() const
{
    return Target->GetLog();
}

// @0x14294b230
Log* FnCall::GetLog() const
{
    return Env->GetLog();
}

// @0x142953ee0
MovieImpl* Environment::GetMovieImpl() const
{
    return Target->GetMovieImpl();
}

// @0x142956740
LocalFrame* Environment::GetTopLocalFrame(int off) const
{
    if (LocalFrames.GetSize() - off > 0)
        return LocalFrames[LocalFrames.GetSize() - off - 1];
    return 0;
}

// @0x14294afc0
ASRefCountCollector* GlobalContext::GetGC()
{
    return pMovieRoot ? static_cast<MovieRoot*>(pMovieRoot->pASMovieRoot)->GetASGC() : 0;
}

// @0x1429561c0
StringManager* GlobalContext::GetStringManager() const
{
    return static_cast<MovieRoot*>(pMovieRoot->pASMovieRoot)->GetStringManager();
}

// @0x14294f7d0
bool Object::GetMember(Environment* penv, const ASString& name, Value* val)
{
    return GetMemberRaw(penv->GetSC(), name, val);
}

// @0x14294c700
bool AvmSprite::GetMember(Environment* penv, const ASString& name, Value* val)
{
    return GetMember(penv, 0, name, val);
}

// @0x1429531f0
bool AvmSprite::GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val)
{
    return GetMember(0, psc, name, val);
}

// Classes with nothing to construct, called as a function.

// @0x142958490
void AmpMarkerCtorFunction::GlobalCtor(const FnCall& fn)
{
    fn.Result->SetNull();
}

// @0x14295ae20
void ExternalInterfaceCtorFunction::GlobalCtor(const FnCall& fn)
{
    fn.Result->SetUndefined();
}

// @0x14295bbe0
void KeyCtorFunction::GlobalCtor(const FnCall& fn)
{
    fn.Result->SetNull();
}

// @0x14295bc00
void MathCtorFunction::GlobalCtor(const FnCall& fn)
{
    fn.Result->SetNull();
}

// @0x14295bc20
void MouseCtorFunction::GlobalCtor(const FnCall& fn)
{
    fn.Result->SetNull();
}

// @0x14295c650
void SelectionCtorFunction::GlobalCtor(const FnCall& fn)
{
    fn.Result->SetNull();
}

// @0x14295c6f0
void StageCtorFunction::GlobalCtor(const FnCall& fn)
{
    fn.Result->SetNull();
}

// @0x142939c20
ASString EventId_GetFunctionName(StringManager* psm, const EventId& evt)
{
    return psm->GetBuiltin(EventId_GetFunctionNameBuiltinType(evt));
}

// @0x1429497f0
float BitmapFilterObject::GetAlpha() const
{
    UByte alpha = readonlyFilterParams().Colors[0].GetAlpha();
    if (!alpha)
        return 0.0f;
    return alpha / 255.0f;
}

// @0x14294a580
const Render::Cxform ColorTransformObject::GetCxform()
{
    Render::Cxform cx(mColorTransform);
    cx.Normalize();
    return cx;
}

// The character as an interactive object, 0 for a shape or a static text.
static inline InteractiveObject* CharToInteractiveObject(DisplayObject* pdob)
{
    return pdob->IsInteractiveObject() ? static_cast<InteractiveObject*>(pdob) : 0;
}

// @0x142956230
InteractiveObject* AsFunctionObject::GetTargetCharacter()
{
    if (!pMovieRoot)
        return 0;
    DisplayObject* pdob = TargetHandle->ResolveCharacter(pMovieRoot);
    return pdob ? CharToInteractiveObject(pdob) : 0;
}

// @0x14294b030
GFx::Text::IMEStyle* TextFieldObject::GetIMECompositionStringStyles()
{
    if (pIMECompositionStringStyles)
        return pIMECompositionStringStyles;
    Object* pproto = pProto;
    if (pproto && pproto->GetObjectType() == Object_TextFieldASObject)
        return static_cast<TextFieldObject*>(pproto)->GetIMECompositionStringStyles();
    return 0;
}

// @0x142944c60
bool GlobalContext::FindRegisteredClass(ASStringContext* psc, const ASString& className, FunctionRef* pctorFunction)
{
    const FunctionRef* pctor = RegisteredClasses.GetCaseCheck(className, psc->IsCaseSensitive());
    if (!pctor)
        return false;
    if (pctorFunction)
        *pctorFunction = *pctor;
    return true;
}

// @0x142958370
FunctionRef SuperObject::Get__constructor__(ASStringContext*)
{
    return Constructor;
}

// @0x14295bc40
void MovieClipCtorFunction::GlobalCtor(const FnCall& fn)
{
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object_MovieClipObject)
        fn.Result->SetAsObject(static_cast<MovieClipObject*>(fn.ThisPtr));
    else
        fn.Result->SetUndefined();
}

// @0x142954b40
Object* FunctionObject::GetPrototype(ASStringContext* psc)
{
    Value prototypeVal;
    if (GetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_prototype), &prototypeVal))
        return prototypeVal.ToObject(0);
    return 0;
}

// @0x142954ba0
Object* GlobalContext::GetPrototype(ASBuiltinType type)
{
    Ptr<Object>* presult = Prototypes.Get(type);
    if (!presult)
    {
        ResolveFunctionName(static_cast<MovieRoot*>(pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(type));
        presult = Prototypes.Get(type);
    }
    return presult ? presult->GetPtr() : 0;
}

// @0x1429566d0
const char* NumberObject::GetTextValue(Environment*) const
{
    return const_cast<NumberObject*>(this)->ToString(10);
}

// @0x14295afb0
void GASLoadVarsLoaderCtorFunction::GlobalCtor(const FnCall& fn)
{
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object_LoadVars && !fn.ThisPtr->IsBuiltinPrototype())
        fn.Result->SetAsObject(static_cast<LoadVarsObject*>(fn.ThisPtr));
    else
        fn.Result->SetNull();
}

}}} // namespace Scaleform::GFx::AS2
// MS2-PIN: ?Finalize_GC@?$Prototype@VSharedObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@MEAAXXZ 0x1429427e0
// MS2-PIN: ?GetCaseCheck@?$ASStringHashBase@VFunctionRef@AS2@GFx@Scaleform@@V?$HashUncachedLH@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@$0BEE@@4@@GFx@Scaleform@@QEAAPEAVFunctionRef@AS2@23@AEBVASString@23@_N@Z 0x142949f60
