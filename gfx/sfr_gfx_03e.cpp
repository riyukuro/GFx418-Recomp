// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_TextField (TextField: the
// dynamic and input text instances, a document view of the text and its editor; the document listener that
// forwards the view's and editor's notifications to the field).
// Queue unit sfr_gfx_03 is split along its original sources: this file is GFx_TextField.
// MS2-UNIT: sfr_gfx_03e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425b5290-0x1425b57e0 .text$mn
// MS2-RANGE: 0x1425b5800-0x1425b6580 .text$mn
// MS2-RANGE: 0x1425b65e0-0x1425b6a40 .text$mn
// MS2-RANGE: 0x1425b6fe0-0x1425b7100 .text$mn
// MS2-PIN: ??_7TextField@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@2@@ 0x143189ac8
// MS2-PIN: ??_7TextField@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@12@@ 0x143189e60
// MS2-PIN: ??_7TextDocumentListener@TextField@GFx@Scaleform@@6B@ 0x143189a68
// MS2-PIN: ??_7FontHandle@GFx@Scaleform@@6B@ 0x143189e70
// MS2-PIN: ??_7FontHandle@Text@Render@Scaleform@@6B@ 0x1431899e8
// MS2-PIN: ??_7DocumentListener@DocView@Text@Render@Scaleform@@6B@ 0x143189a08
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x14318ea90
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7?$RefCountBase@VFontHandle@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x1431899e0
// MS2-PIN: ??_7?$RefCountBaseNTS@VDocumentListener@DocView@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143189a00
// MS2-PIN: ??_G?$RefCountBase@VFontHandle@Text@Render@Scaleform@@$0EO@@Scaleform@@UEAAPEAXI@Z 0x1425b6010
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@UEAAPEAXI@Z 0x1425b6070
// MS2-PIN: ??_G?$RefCountBaseNTS@VDocumentListener@DocView@Text@Render@Scaleform@@$0EO@@Scaleform@@UEAAPEAXI@Z 0x1425b60d0
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EO@@Scaleform@@UEAAPEAXI@Z 0x1425b6130
// MS2-PIN: ??_GFontHandle@GFx@Scaleform@@UEAAPEAXI@Z 0x1425b61f0

#include "../include/gfx/gfx_textfield.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_fontmanager.h"
#include "../include/gfx/gfx_fonthandle.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_state.h"
#include "../include/gfx/text_editorkit.h"
#include "../include/gfx/text_stylesheet.h"
#include "../include/gfx/gfx_statictextcharacter.h"

namespace Scaleform { namespace GFx {

// The text replacement state (the full class is in sfr_gfx_02f); the fields only ask whether it wraps the lines
// itself.
class Translator : public State
{
public:
    unsigned WWMode; // +0x18 Translator::WordWrappingTypes
    bool HandlesCustomWordWrapping() const { return WWMode != 0; }
};

// DisplayObjectBase::StateChanged_* bits (GetStateChangeFlags).
enum
{
    StateChanged_FontLib      = 0x1,
    StateChanged_FontMap      = 0x2,
    StateChanged_FontProvider = 0x4,
    StateChanged_Translator   = 0x8,
    StateChanged_Fonts        = StateChanged_FontLib | StateChanged_FontMap | StateChanged_FontProvider | StateChanged_Translator
};
// MovieImpl::Flags2: the movie's registered fonts changed since the last advance.
enum { Flag2_RegisteredFontsChanged = 0x2 };

// The shadowStyle / shadowColor state of an AS2 field. 0x40 bytes.
struct TextField::ShadowParams : public NewOverrideBase<StatMV_Text_Mem>
{
    UInt32                   ShadowColor;    // +0x00
    ASString                 ShadowStyleStr; // +0x08
    ArrayLH<Render::PointF>  ShadowOffsets;  // +0x10
    ArrayLH<Render::PointF>  TextOffsets;    // +0x28
};

// The field's editor (the document view keeps it as the render-side base).
static inline Text::EditorKit* EditorOf(Render::Text::DocView* pdoc)
{
    return static_cast<Text::EditorKit*>(pdoc->GetEditorKit());
}

// The movie's translator, with a reference (NULL when none is set).
static inline Ptr<Translator> TranslatorOf(MovieImpl* proot)
{
    return *static_cast<Translator*>(proot->GetStateBag()->GetStateAddRef(State::State_Translator));
}

// MS2-FUNCTIONAL 0x1425b5290: same switch over the play-list states; the exe lays the case blocks out in another order
// @0x1425b5290
template<>
void InteractiveObject::ModifyOptimizedPlayListLocal<TextField>()
{
    switch (static_cast<TextField*>(this)->TextField::CheckAdvanceStatus(IsInOptimizedPlayList()))
    {
    case 1:  AddToOptimizedPlayList(); break;
    case -1: MarkToRemoveFromOptimizedPlayList(); break;
    }
}

// ---- GFx::FontHandle (the handle a field's formats keep: the font and the movie it came from)

// @0x1425b5800
FontHandle::FontHandle(Render::Text::FontManagerBase* pmgr, Render::Font* pfont, const char* name, unsigned flags,
                       MovieDef* psourceMovieDef)
    : Render::Text::FontHandle(pmgr, pfont, name, flags), pSourceMovieDef(psourceMovieDef)
{
}

}} // namespace Scaleform::GFx

namespace Scaleform { namespace Render { namespace Text {
// @0x1425b5e40
FontHandle::~FontHandle()
{
    if (pFont)
        pFont->Release();
}
}}} // namespace Scaleform::Render::Text

namespace Scaleform { namespace GFx {

// (the exe has only the deleting dtor, 0x1425b61f0, with this body inlined)
// MS2-FUNCTIONAL 0x1425b61f0: the deleting dtor (pinned) inlines this body; frame layout differs
FontHandle::~FontHandle()
{
    if (pFontManager)
        static_cast<FontManager*>(pFontManager)->RemoveFontHandle(this);
    if (pFont)
        pFont->Release();
    pFont = 0;
}

// ---- TextField

// MS2-FUNCTIONAL 0x1425b5930: same member init and calls; register allocation and the inlined editor/autosize tests differ
// @0x1425b5930
TextField::TextField(TextFieldDef* def, MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot,
                     InteractiveObject* parent, ResourceId id)
    : InteractiveObject(pbindingDefImpl, pasRoot, parent, id), pDef(def), pImageDescAssoc(NULL)
{
    pBinding = pbindingDefImpl ? &pbindingDefImpl->GetResourceBinding() : NULL;
    Flags = 0;
    FocusedControllerIdx = ~0u;
    Alignment = def->Alignment;
    Flags = (def->IsPassword() ? Flags_Password : 0);
    pShadow = NULL;
    if (def->IsHtml())
        Flags |= Flags_Html;
    Flags |= Flags_MouseWheelEnabled;

    MovieImpl* proot = pasRoot->GetMovieImpl();
    Ptr<Render::Text::Allocator> palloc = proot->GetTextAllocator();
    FontManager* pfontMgr = proot->FindFontManager(pbindingDefImpl);
    if (!pfontMgr && (!parent || !(pfontMgr = parent->GetFontManager())))
        pfontMgr = proot->FindFontManager(NULL);
    pDocument = *SF_HEAP_NEW(proot->GetMovieHeap()) Render::Text::DocView(palloc, pfontMgr, GetLog());
    pDocument->SetDocumentListener(&TextDocListener);
    pDocument->GetStyledText()->SetNewLine0D();

    if (def->IsBorder())
    {
        pDocument->SetBorderColor(0xffffffffu);
        static_cast<Render::TreeText*>(GetRenderNode())->NotifyLayoutChanged();
        pDocument->SetBackgroundColor(0xff000000u);
        static_cast<Render::TreeText*>(GetRenderNode())->NotifyLayoutChanged();
    }
    SetInitialFormatsAsDefault();
    if (def->MaxLength > 0)
        pDocument->SetMaxLength(def->MaxLength);
    pDocument->SetViewRect(def->TextRect);
    if (def->DoesUseDeviceFont())
    {
        pDocument->SetUseDeviceFont();
        pDocument->SetAAForReadability();
    }
    if (def->IsMultiline())
        pDocument->SetMultiline();
    else
        pDocument->ClearMultiline();
    if (def->IsAutoSize())
    {
        // a single-line word-wrapped field keeps its width
        if (!(def->IsWordWrap() && def->IsMultiline()))
            pDocument->SetAutoSizeX();
        pDocument->SetAutoSizeY();
    }
    if (def->IsWordWrap())
        pDocument->SetWordWrap();
    if (IsPassword())
        pDocument->SetPasswordMode();
    if (def->IsAAForReadability())
        pDocument->SetAAForReadability();
    Render::Text::EditorKitBase* peditor = pDocument->GetEditorKit();
    if (!(peditor ? peditor->IsReadOnly() : pDef->IsReadOnly()) || def->IsSelectable())
        CreateEditorKit();
    SetCompleteReformatReq();
}

// @0x1425b5ea0
TextField::~TextField()
{
    delete pImageDescAssoc;
    pImageDescAssoc = NULL;
    pDocument->Close();
    delete pShadow;
}

// The document listener: the line format callback is wanted only when the translator wraps the lines itself.
// MS2-FUNCTIONAL 0x1425b58d0: same base ctor and TranslatorChanged call; the exe inlines TranslatorChanged with a shorter frame
// @0x1425b58d0
TextField::TextDocumentListener::TextDocumentListener()
    : DocumentListener(Mask_OnScroll | Mask_OnMaxScrollChanged | Mask_OnViewChanged)
{
    TranslatorChanged();
}

TextField* TextField::TextDocumentListener::GetTextField() const
{
    return reinterpret_cast<TextField*>(reinterpret_cast<UPInt>(this) - offsetof(TextField, TextDocListener));
}

void TextField::TextDocumentListener::TranslatorChanged()
{
    Ptr<Translator> ptrans = TranslatorOf(GetTextField()->GetMovieImpl());
    if (ptrans && ptrans->HandlesCustomWordWrapping())
        HandlersMask |= Mask_OnLineFormat;
    else
        HandlersMask &= ~Mask_OnLineFormat;
}

// The image the HTML <img id=...> tag named idStr refers to.
// @0x1425b65e0
void TextField::AddIdImageDescAssoc(const char* idStr, Render::Text::ImageDesc* pdesc)
{
    if (!pImageDescAssoc)
        pImageDescAssoc = SF_HEAP_AUTO_NEW(this) StringHashLH<Ptr<Render::Text::ImageDesc> >;
    pImageDescAssoc->Set(idStr, pdesc);
}

// MS2-FUNCTIONAL 0x1425b67d0: same advance logic; the exe keeps the movie root in a callee-saved register and orders blocks differently
// @0x1425b67d0
void TextField::AdvanceFrame(bool nextFrame, float framePos)
{
    SF_UNUSED(framePos);
    UByte stateFlags = GetStateChangeFlags();
    bool  textSet    = false;
    if (((stateFlags & StateChanged_Fonts) || (GetMovieImpl()->Flags2 & Flag2_RegisteredFontsChanged)) && pDocument)
    {
        InteractiveObject::Flags &= ~Mask_ReqPartialAdvance;
        pDocument->SetCompleteReformatReq();
        SetCompleteReformatReq();
        if (stateFlags & StateChanged_Translator)
        {
            TextDocListener.TranslatorChanged();
            SetTextValue(OriginalTextValue.ToCStr(), (Flags & Flags_OriginalIsHtml) != 0, true);
            textSet = true;
        }
    }
    InteractiveObject::Flags &= ~Mask_ChangedFlags;
    if (Flags & Flags_ForceOneTimeAdvance)
    {
        Flags &= ~Flags_ForceOneTimeAdvance;
        ModifyOptimizedPlayListLocal<TextField>();
    }
    if (HasAvmObject())
    {
        Text::StyleManager* pss = const_cast<Text::StyleManager*>(GetAvmObjImpl()->ToAvmTextFieldBase()->GetStyleSheet());
        if (pss)
        {
            if (pss->IsLoadingFinished())
            {
                pss->SetState(Text::StyleManager::Ready);
                ModifyOptimizedPlayListLocal<TextField>();
                if (!textSet)
                {
                    SetCompleteReformatReq();
                    SetTextValue(OriginalTextValue.ToCStr(), (Flags & Flags_OriginalIsHtml) != 0, true);
                }
            }
            else if (pss->IsError())
            {
                pss->SetState(Text::StyleManager::Ready);
                ModifyOptimizedPlayListLocal<TextField>();
            }
        }
    }
    if (nextFrame)
    {
        if ((Flags & Flags_ForceAdvance) && HasAvmObject())
            GetAvmObjImpl()->ToAvmTextFieldBase()->UpdateTextFromVariable();
        Flags |= Flags_NextFrame;
    }
    else
        Flags &= ~Flags_NextFrame;

    Text::EditorKit* peditor = EditorOf(pDocument);
    if (peditor)
    {
        MovieImpl* proot = GetMovieImpl();
        if (proot->IsFocused(this) || peditor->IsMouseCaptured())
            peditor->Advance(Double(proot->TimeElapsed) / 1000000.0);
    }
    if (Flags & Flags_NeedUpdateLayout)
        static_cast<Render::TreeText*>(GetRenderNode())->NotifyLayoutChanged();
}

// 1: the field needs to be on the optimized advance list (and is not), -1: it needs to leave it, 0: no change.
// MS2-FUNCTIONAL 0x1425b6fe0: same result for every flag combination; the exe computes rv with cmov and hoists the movie root load
// @0x1425b6fe0
int TextField::CheckAdvanceStatus(bool playingNow)
{
    int rv = 0;
    if (!IsAdvanceDisabled() && !(DisplayObjectBase::Flags & Mask_MarkedForRemove))
    {
        if (!(Flags & (Flags_ForceOneTimeAdvance | Flags_ForceAdvance)))
        {
            MovieImpl*       proot   = GetMovieImpl();
            Text::EditorKit* peditor = EditorOf(pDocument);
            // advancing only for the cursor of a focused editable field, or a drag selection
            if (!IsVisibleFlagSet() || !peditor ||
                ((peditor->IsReadOnly() || !proot->IsFocused(this)) && !peditor->IsMouseCaptured()))
            {
                if (playingNow)
                    rv = -1;
                goto check_css;
            }
        }
        if (!playingNow)
            return 1;
    }
    else
        rv = playingNow ? -1 : 0;
check_css:
    if (HasAvmObject())
    {
        // a style sheet still loading keeps the field advancing
        const Text::StyleManager* pss = GetAvmObjImpl()->ToAvmTextFieldBase()->GetStyleSheet();
        if (pss && (pss->IsLoading() || pss->IsLoadingFinished()))
            rv = 1;
    }
    return rv;
}

}} // namespace Scaleform::GFx
