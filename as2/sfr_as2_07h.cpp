// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_07):
// setters of the AS2 runtime: clip event handlers, the prototype constructor, Selection's focus groups and modal
// clip, hit areas, IME composition styles, BitmapData images, level numbers, Matrix members and AmpMarker.
// MS2-UNIT: sfr_as2_07h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14297fed0-0x142980234 .text$mn
// MS2-RANGE: 0x142981670-0x142981b70 .text$mn
// MS2-RANGE: 0x142981bf0-0x142981d80 .text$mn
// MS2-RANGE: 0x142982370-0x1429829b1 .text$mn
// MS2-RANGE: 0x142982af0-0x142982b9c .text$mn
// MS2-RANGE: 0x142989060-0x1429891b7 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_intervaltimer.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_movieslots.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/kernel/sf_msgformat.h"
#include "../include/gfx/gfx_rendertree.h"
#include "../include/render/text_highlight.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {

// MovieRoot's sprites that have a hit area (+0x628; the member is not recovered in as2_movieroot.h yet).
typedef ArrayLH<Ptr<Sprite>, StatMV_ActionScript_Mem> SpritesWithHitAreaArray;

SF_FORCEINLINE SpritesWithHitAreaArray& SpritesWithHitAreaOf(MovieRoot* proot)
{
    return *reinterpret_cast<SpritesWithHitAreaArray*>(reinterpret_cast<UByte*>(proot) + 0x628);
}

// MovieImpl::AdvanceStats (+0x30, a Ptr<AMP::ViewStats>).
SF_FORCEINLINE AMP::ViewStats* AdvanceStatsOf(MovieImpl* pmovie)
{
    return *reinterpret_cast<AMP::ViewStats**>(reinterpret_cast<UByte*>(pmovie) + 0x30);
}

// Text::IMEStyle as the text field object stores it (0x54 bytes; text_editorkit.h does not mix with the AS2
// headers): a highlight look per category and the mask of those set.
struct IMEStyleData : public NewOverrideBase<0x145>
{
    Render::Text::HighlightInfo HighlightStyles[5];
    UByte                       PresenceMask;
};

// Value::ToFunction without a function name to resolve (no environment).
SF_FORCEINLINE FunctionRef FunctionOf(const Value& v)
{
    if (v.GetType() == Value::FUNCTION)
        return v.V.FunctionValue;
    return FunctionRef();
}

// Value::ToCharacter as the exe has it inline.
SF_FORCEINLINE InteractiveObject* CharacterOf(const Value& v, const Environment* penv)
{
    if (v.GetType() == Value::CHARACTER && penv && v.V.pCharHandle)
    {
        DisplayObject* pdisp = v.V.pCharHandle->ResolveCharacter(penv->GetTarget()->GetMovieImpl());
        if (pdisp)
            return pdisp->IsInteractiveObject() ? static_cast<InteractiveObject*>(pdisp) : 0;
    }
    return 0;
}

} // namespace

// One handler for every event of the flag set: each event bit gets it as a single event.
// MS2-FUNCTIONAL: the popcount and the mask loop allocate registers differently; same behavior
// @0x14297fed0
void AvmCharacter::SetClipEventHandlers(const EventId& id, const Value& method)
{
    UInt32 v = id.Id;
    v        = (v & 0x55555555) + ((v >> 1) & 0x55555555);
    v        = (v & 0x33333333) + ((v >> 2) & 0x33333333);
    v        = (v & 0x0f0f0f0f) + ((v >> 4) & 0x0f0f0f0f);
    UByte n  = UByte(v % 255);
    if (n == 1)
    {
        SetSingleClipEventHandler(id, method);
        return;
    }
    for (unsigned i = 0, mask = 1; i < n; mask <<= 1)
    {
        if (id.Id & mask)
        {
            EventId singleId = id;
            singleId.Id      = mask;
            ++i;
            SetSingleClipEventHandler(singleId, method);
        }
    }
}

// The constructor goes to Constructor; "constructor" itself is left unset, resolved from it when read.
// MS2-FUNCTIONAL: FunctionRef assignment codegen differs; same behavior
// @0x14297ffc0
bool GASPrototypeBase::SetConstructor(Object* pthis, ASStringContext* psc, const Value& ctor)
{
    Constructor = FunctionOf(ctor);
    pthis->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_constructor), Value(Value::UNSET),
                        PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete);
    return true;
}

// Selection.setControllerFocusGroup(controllerIdx, focusGroupIdx): whether the controller was moved.
// @0x142980120
void SelectionCtorFunction::SetControllerFocusGroup(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (fn.NArgs >= 2)
    {
        MovieImpl* proot         = fn.Env->GetTarget()->GetMovieImpl();
        unsigned   controllerIdx = fn.Arg(0).ToUInt32(fn.Env);
        unsigned   focusGroupIdx = fn.Arg(1).ToUInt32(fn.Env);
        fn.Result->SetBool(AsMovieSlots(proot)->SetControllerFocusGroup(controllerIdx, focusGroupIdx));
    }
}

// The sprite joins the movie's hit area sprites when it gets a hit area, and leaves when it loses it.
// MS2-FUNCTIONAL: hit-area array search and PushBack codegen differ; same behavior
// @0x142981670
void AvmSprite::SetHitAreaNotify(Sprite* phitArea)
{
    Sprite*                  psprite = GetSprite();
    SpritesWithHitAreaArray& sprites = SpritesWithHitAreaOf(GetAS2Root());
    int                      index   = -1;
    if (psprite->pHitAreaHandle)
    {
        for (unsigned i = 0; i < sprites.GetSize(); i++)
        {
            if (sprites[i] == psprite)
            {
                index = (int)i;
                break;
            }
        }
    }
    if (!phitArea)
    {
        if (index >= 0)
            sprites.RemoveAt(index);
    }
    else if (index == -1)
        sprites.PushBack(Ptr<Sprite>(psprite));
}

// The styles of the IME composition string, allocated on first use.
// MS2-FUNCTIONAL: style copy and allocation codegen differ; same behavior
// @0x142981750
void TextFieldObject::SetIMECompositionStringStyles(const GFx::Text::IMEStyle& st)
{
    const IMEStyleData& style = reinterpret_cast<const IMEStyleData&>(st);
    if (pIMECompositionStringStyles)
        reinterpret_cast<IMEStyleData&>(*pIMECompositionStringStyles) = style;
    else
        pIMECompositionStringStyles =
            reinterpret_cast<GFx::Text::IMEStyle*>(SF_HEAP_AUTO_NEW(this) IMEStyleData(style));
}

// The image of the BitmapData, and its "rectangle": a flash.geom.Rectangle of the image size.
// MS2-FUNCTIONAL: Value temporaries and the Ptr assignments schedule differently; same behavior
// @0x1429818e0
void BitmapData::SetImage(Environment* penv, ImageResource* pimg, MovieDef* pmovieDef)
{
    pImageRes = pimg;
    pMovieDef = pmovieDef;

    Render::ImageRect rect = pimg->GetImage()->GetRect();
    Value             params[Rectangle_NumProperties];
    params[0] = Value(0);
    params[1] = Value(0);
    params[2] = Value(Number(rect.Width()));
    params[3] = Value(Number(rect.Height()));

    ASStringContext*     psc = penv->GetSC();
    Ptr<RectangleObject> prect =
        *static_cast<RectangleObject*>(penv->OperatorNew(psc->pContext->FlashGeomPackage,
                                                         penv->GetBuiltin(ASBuiltin_Rectangle)));
    prect->SetProperties(psc, params);
    SetMemberRaw(psc, psc->CreateConstString("rectangle"), Value(prect.GetPtr()));
}

// Makes the clip _level<level>: its render node goes in among the levels' nodes in level order, and it takes
// the level name.
// MS2-FUNCTIONAL: the name buffer and Format codegen differ; same behavior
// @0x142981bf0
void AvmSprite::SetLevel(int level)
{
    MovieRoot* proot  = GetAS2Root();
    MovieImpl* pmovie = proot->GetMovieImpl();
    UPInt      index  = 0;
    for (; index < pmovie->MovieLevelsSize; index++)
    {
        if (pmovie->pMovieLevels[index].Level > level)
            break;
    }
    Ptr<Render::TreeContainer>& topNode = *reinterpret_cast<Ptr<Render::TreeContainer>*>(proot->Unrecovered_28);
    topNode->Insert(index, GetDispObj()->GetRenderNode());
    Level = level;

    char nameBuff[64] = "";
    Format(StringDataPtr(nameBuff, sizeof(nameBuff)), "_level{0}", level);
    GetSprite()->SetName(GetASEnvironment()->CreateString(nameBuff));
}

// The matrix as the a, b, c, d, tx, ty members of the Matrix object.
// MS2-FUNCTIONAL: member-string temporaries codegen differs; same behavior
// @0x142982370
void MatrixObject::SetMatrix(Environment* penv, const Render::Matrix2F& m)
{
    ASStringContext* psc = penv->GetSC();
    ObjectInterface& oi  = *this;
    oi.SetMemberRaw(psc, psc->CreateConstString("a"), Value(Number(m.Sx())));
    oi.SetMemberRaw(psc, psc->CreateConstString("b"), Value(Number(m.Shy())));
    oi.SetMemberRaw(psc, psc->CreateConstString("c"), Value(Number(m.Shx())));
    oi.SetMemberRaw(psc, psc->CreateConstString("d"), Value(Number(m.Sy())));
    oi.SetMemberRaw(psc, psc->CreateConstString("tx"), Value(Number(m.Tx())));
    oi.SetMemberRaw(psc, psc->CreateConstString("ty"), Value(Number(m.Ty())));
}

// SetMatrix with the translation given in twips.
// MS2-FUNCTIONAL: member-string temporaries codegen differs; same behavior
// @0x142982690
void MatrixObject::SetMatrixTwips(ASStringContext* psc, const Render::Matrix2F& m)
{
    ObjectInterface& oi = *this;
    oi.SetMemberRaw(psc, psc->CreateConstString("a"), Value(Number(m.Sx())));
    oi.SetMemberRaw(psc, psc->CreateConstString("b"), Value(Number(m.Shy())));
    oi.SetMemberRaw(psc, psc->CreateConstString("c"), Value(Number(m.Shx())));
    oi.SetMemberRaw(psc, psc->CreateConstString("d"), Value(Number(m.Sy())));
    oi.SetMemberRaw(psc, psc->CreateConstString("tx"), Value(Number(m.Tx()) * 0.05));
    oi.SetMemberRaw(psc, psc->CreateConstString("ty"), Value(Number(m.Ty()) * 0.05));
}

// Amp.addMarker = name adds a profiler marker; everything else is an ordinary member.
// @0x142982af0
bool AmpMarkerCtorFunction::SetMember(Environment* penv, const ASString& name, const Value& val,
                                      const PropFlags& flags)
{
    MovieImpl* pmovie = penv->GetTarget()->GetMovieImpl();
    if (!strcmp(name.ToCStr(), "addMarker"))
    {
        AdvanceStatsOf(pmovie)->AddMarker(val.ToString(penv).ToCStr());
        return true;
    }
    return Object::SetMember(penv, name, val, flags);
}

// Selection.setModalClip(clip[, controllerIdx]): focus stays inside the sprite (none when it is not a sprite).
// MS2-FUNCTIONAL: one register move is scheduled across the null test; same behavior
// @0x142989060
void SelectionCtorFunction::SetModalClip(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (fn.NArgs >= 1)
    {
        MovieImpl*             proot = fn.Env->GetTarget()->GetMovieImpl();
        Ptr<InteractiveObject> pch   = CharacterOf(fn.Arg(0), fn.Env);
        unsigned               controllerIdx = fn.NArgs >= 2 ? fn.Arg(1).ToUInt32(fn.Env) : 0;
        proot->SetModalClip(pch && pch->IsSprite() ? static_cast<Sprite*>(pch.GetPtr()) : 0, controllerIdx);
    }
}

// IntervalTimer's id setter (no pdata, only the timer's vftable reaches it).
// @0x1429818d0
void IntervalTimer::SetId(int id)
{
    Id = id;
}

}}} // namespace Scaleform::GFx::AS2
