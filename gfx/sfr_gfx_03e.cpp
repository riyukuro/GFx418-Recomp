// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_TextField (TextField: the
// dynamic and input text instances, a document view of the text and its editor; the document listener that
// forwards the view's and editor's notifications to the field).
// Queue unit sfr_gfx_03 is split along its original sources: this file is GFx_TextField.
// MS2-UNIT: sfr_gfx_03e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425b5290-0x1425b6580 .text$mn
// MS2-RANGE: 0x1425b65e0-0x1425b6fe0 .text$mn
// MS2-RANGE: 0x1425b6fe0-0x1425b8250 .text$mn
// MS2-RANGE: 0x1425b8250-0x1425bb530 .text$mn
// MS2-RANGE: 0x1425beab0-0x1425beb10 .text$mn
// MS2-RANGE: 0x1425bc060-0x1425bc080 .text$mn
// MS2-PIN: ??_7TextField@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@2@@ 0x143189ac8
// MS2-PIN: ??_7TextField@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@12@@ 0x143189e60
// MS2-PIN: ??_7TextDocumentListener@TextField@GFx@Scaleform@@6B@ 0x143189a68
// MS2-PIN: ??_7?$RefCountBase@VFilter@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318ccd8
// MS2-PIN: ??_7Filter@Render@Scaleform@@6B@ 0x14315ac78
// MS2-PIN: ??_7BlurFilterImpl@Render@Scaleform@@6B@ 0x14315ac90
// MS2-PIN: ??_7BlurFilter@Render@Scaleform@@6B@ 0x14315aca8
// MS2-PIN: ??_7ShadowFilter@Render@Scaleform@@6B@ 0x14315acc0
// MS2-PIN: ??_7GlowFilter@Render@Scaleform@@6B@ 0x14315acd8
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
#include "../include/gfx/gfx_imemanager.h"
#include "../include/gfx/gfx_movieimplstates.h"
#include "../include/gfx/gfx_valueinfo.h"
#include "../include/render/render_filters.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_imagecreator.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/render/text_styledtext.h"

// The debug log of the kernel (the warnings of ProcessImageTags).
namespace Scaleform { void LogDebugMessage(LogMessageId id, const char* fmt, ...); }

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
struct TextField::ShadowParams : public NewOverrideBase<0x143>   // StatMV_ActionScript_Mem
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
// (inline: sfr_gfx_05d has the same inline body; the exe has no out-of-line copy)
inline FontHandle::~FontHandle()
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
        pDocument->SetBackgroundColor(0xffffffffu);
        static_cast<Render::TreeText*>(GetRenderNode())->NotifyLayoutChanged();
        pDocument->SetBorderColor(0xff000000u);
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

// @0x1425beab0
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

// The field is read-only / selectable: the editor's state once it exists, the definition's before.
// @0x1425b9b10
bool TextField::IsReadOnly() const
{
    Render::Text::EditorKitBase* peditor = pDocument->GetEditorKit();
    return peditor ? peditor->IsReadOnly() : pDef->IsReadOnly();
}

// @0x1425b9b50
bool TextField::IsSelectable() const
{
    Text::EditorKit* peditor = EditorOf(pDocument);
    return peditor ? peditor->IsSelectable() : pDef->IsSelectable();
}

// (sfr21) the small TextField overrides (no unwind data; the full-exe link found no object for them).
// @0x1425b7f10
CharacterDef* TextField::GetCharacterDef() const
{
    return pDef;
}

// The hand when the field asks for it, the I-beam over selectable text, else the interactive object's.
// @0x1425b81c0
unsigned TextField::GetCursorType() const
{
    if (Flags & Flags_HandCursor)
        return MouseCursorEvent::HAND;
    if (IsSelectable())
        return MouseCursorEvent::IBEAM;
    return InteractiveObject::GetCursorType();
}

// @0x1425b95e0
CharacterDef::CharacterDefType TextField::GetType() const
{
    return CharacterDef::TextField;
}

// @0x1425b9ad0
bool TextField::IsFocusRectEnabled() const
{
    return false;
}

// @0x1425ba610
bool TextField::OnLosingKeyboardFocus(InteractiveObject*, unsigned, FocusMovedType)
{
    return true;
}

// The text changed: the AVM side hears of it and the field is laid out again.
// @0x1425b9da0
void TextField::NotifyChanged()
{
    if (HasAvmObject())
        GetAvmObjImpl()->ToAvmTextFieldBase()->NotifyChanged();
    SetDirtyFlag();
}

// @0x1425bc060
void TextField::SetDirtyFlag()
{
    static_cast<Render::TreeText*>(GetRenderNode())->NotifyLayoutChanged();
}

// @0x1425b91a0
const Text::StyleManager* TextField::GetStyleSheet() const
{
    if (HasAvmObject())
        return GetAvmObjImpl()->ToAvmTextFieldBase()->GetStyleSheet();
    return NULL;
}

// @0x1425b9730
bool TextField::HasStyleSheet() const
{
    if (HasAvmObject())
        return GetAvmObjImpl()->ToAvmTextFieldBase()->HasStyleSheet();
    return false;
}

// The IME's composition string: emptied (ClearCompositionString), made (CreateCompositionString) and committed
// into the text character by character, as typed, up to the field's maximum length.
// @0x1425b71a0
void TextField::ClearCompositionString()
{
    if (pDocument->GetEditorKit())
    {
        Ptr<Text::CompositionString> pcs =
            static_cast<Text::CompositionString*>(pDocument->GetEditorKit()->GetCompositionString());
        if (pcs)
            pcs->SetText(L"");
        SetDirtyFlag();
    }
}

// @0x1425b77a0
void TextField::CreateCompositionString()
{
    Text::EditorKit* peditor = EditorOf(pDocument);
    if (peditor)
    {
        Ptr<Text::CompositionString> pcs = peditor->CreateCompositionString();
        pcs->SetText(L"");
        pcs->SetPosition(EditorOf(pDocument)->GetCursorPos());
        SetDirtyFlag();
    }
}

// MS2-FUNCTIONAL 0x1425b75f0: same body; our frame reserves 0x10 more stack
// @0x1425b75f0
void TextField::CommitCompositionString(const wchar_t* pstr, UPInt len)
{
    if (pDocument->GetEditorKit())
    {
        Ptr<Text::CompositionString> pcs =
            static_cast<Text::CompositionString*>(pDocument->GetEditorKit()->GetCompositionString());
        if (pcs)
        {
            if (!pstr)
            {
                pstr = pcs->GetText();
                len  = pcs->GetLength();
            }
            else if (len == SF_MAX_UPINT)
                len = SFwcslen(pstr);

            UPInt curLen = pDocument->GetStyledText()->GetLength();
            UPInt maxLen = pDocument->GetMaxLength();
            if (maxLen == 0)
                maxLen = SF_MAX_UPINT;
            EditorOf(pDocument)->SetCursorPos(pcs->GetPosition(), false);
            for (UPInt i = 0; i < len; ++i)
            {
                if (curLen >= maxLen)
                    break;
                if (EditorOf(pDocument)->OnChar(pstr[i]))
                    ++curLen;
            }
            pcs->SetText(L"");
            pcs->SetPosition(EditorOf(pDocument)->GetCursorPos());
            if (HasAvmObject())
                GetAvmObjImpl()->ToAvmTextFieldBase()->UpdateVariable();
            NotifyChanged();
        }
    }
}

// @0x1425b7f80
const wchar_t* TextField::GetCompositionString()
{
    Ptr<Render::Text::CompositionStringBase> pcs = pDocument->GetEditorKit()->GetCompositionString();
    if (pcs)
        return pcs->GetText();
    return NULL;
}

// @0x1425b7fe0
UPInt TextField::GetCompositionStringLength() const
{
    if (pDocument->GetEditorKit())
    {
        Ptr<Render::Text::CompositionStringBase> pcs = pDocument->GetEditorKit()->GetCompositionString();
        if (pcs)
            return pcs->GetLength();
    }
    return 0;
}

// @0x1425b8040
UPInt TextField::GetCompositionStringPosition() const
{
    if (pDocument->GetEditorKit())
    {
        Ptr<Render::Text::CompositionStringBase> pcs = pDocument->GetEditorKit()->GetCompositionString();
        if (pcs)
            return pcs->GetPosition();
    }
    return SF_MAX_UPINT;
}

// The field's editor, made on first use with the definition's read-only / selectable state and the movie's
// clipboard and key map.
// MS2-FUNCTIONAL 0x1425b7840: same logic; block layout differs (one branch distance)
// @0x1425b7840
Ptr<Text::EditorKit> TextField::CreateEditorKit()
{
    Ptr<Text::EditorKit> peditor = EditorOf(pDocument);
    if (!peditor)
    {
        peditor = *SF_HEAP_AUTO_NEW(this) Text::EditorKit(pDocument);
        if (pDef->IsReadOnly())
            peditor->SetReadOnly();
        if (pDef->IsSelectable())
            peditor->SetSelectable();
        Ptr<TextClipboard> pclipBoard =
            *static_cast<TextClipboard*>(GetMovieImpl()->GetStateBag()->GetStateAddRef(State::State_TextClipboard));
        peditor->SetClipboard(pclipBoard);
        Ptr<TextKeyMap> pkeymap =
            *static_cast<TextKeyMap*>(GetMovieImpl()->GetStateBag()->GetStateAddRef(State::State_TextKeyMap));
        peditor->SetKeyMap(pkeymap);
        if (Flags & Flags_UseRichClipboard)
            peditor->SetUseRichClipboard();
        else
            peditor->ClearUseRichClipboard();
    }
    return peditor;
}

// @0x1425b7a00
Ptr<Render::TreeNode> TextField::CreateRenderNode(Render::ContextImpl::Context& context) const
{
    Ptr<Render::TreeText> ptreeText = *context.CreateEntry<Render::TreeText>();
    ptreeText->Init(pDocument);
    return ptreeText;
}

// @0x1425b7aa0
void TextField::TextDocumentListener::Editor_OnChanged(Render::Text::EditorKitBase& editor)
{
    SF_UNUSED(editor);
    TextField* ptextField = GetTextField();
    ptextField->pDocument->GetText(&ptextField->OriginalTextValue);
    if (ptextField->HasAvmObject())
        ptextField->GetAvmObjImpl()->ToAvmTextFieldBase()->UpdateVariable();
    ptextField->NotifyChanged();
}

// @0x1425b7b80
void TextField::TextDocumentListener::Editor_OnCursorMoved(Render::Text::EditorKitBase& editor)
{
    SF_UNUSED(editor);
    GetTextField()->SetDirtyFlag();
}

// @0x1425b7b40
void TextField::TextDocumentListener::Editor_OnCursorBlink(Render::Text::EditorKitBase& editor, bool cursorState)
{
    SF_UNUSED2(editor, cursorState);
    GetTextField()->SetDirtyFlag();
}

// @0x1425b7f40
String TextField::TextDocumentListener::GetCharacterPath()
{
    String path;
    GetTextField()->GetAbsolutePath(&path);
    return path;
}

// The selection's ends and the caret (AS2 Selection natives).
// @0x1425b7df0
UPInt TextField::GetBeginIndex() const
{
    if (pDocument->GetEditorKit())
        return EditorOf(pDocument)->GetBeginSelection();
    return 0;
}

// @0x1425b8220
UPInt TextField::GetEndIndex() const
{
    if (pDocument->GetEditorKit())
        return EditorOf(pDocument)->GetEndSelection();
    return 0;
}

// @0x1425b7e70
SPInt TextField::GetCaretIndex() const
{
    if (!IsReadOnly() || IsSelectable())
    {
        Text::EditorKit* peditor = EditorOf(pDocument);
        if (peditor)
            return peditor->GetCursorPos();
    }
    return -1;
}

// @0x1425b81a0
SPInt TextField::GetCursorPos() const
{
    Text::EditorKit* peditor = EditorOf(pDocument);
    if (peditor)
        return peditor->GetCursorPos();
    return -1;
}

// @0x1425b7220
void TextField::ClearIdImageDescAssoc()
{
    delete pImageDescAssoc;
    pImageDescAssoc = NULL;
}

// @0x1425b7e20
RectF TextField::GetBounds(const Matrix& t) const
{
    return t.EncloseTransform(pDocument->GetViewRect());
}

// @0x1425b80b0
Render::RectF TextField::GetCursorBounds(UPInt charIndex, float* phitTestX, float* phitTestY)
{
    Text::EditorKit* peditor = EditorOf(pDocument);
    if (peditor)
    {
        Render::RectF newCursorRect(0, 0, 0, 0);
        if (peditor->CalcCursorRectOnScreen(charIndex, &newCursorRect, NULL, NULL, false))
        {
            if (phitTestX)
                *phitTestX = float(pDocument->GetHScrollOffset());
            if (phitTestY)
                *phitTestY = float(pDocument->GetVScrollOffset());
            return newCursorRect;
        }
    }
    if (phitTestX)
        *phitTestX = 0;
    if (phitTestY)
        *phitTestY = 0;
    return Render::RectF(0, 0, 0, 0);
}

// The style sheet's URL zones: one per run of adjacent text with the same link, each keeping a copy of its text
// for the hover / press styles.
// MS2-FUNCTIONAL 0x1425b72a0: same logic; the exe frames off r11 and keeps a larger frame (register / stack allocation)
// @0x1425b72a0
void TextField::CollectUrlZones()
{
    if (!pCSSData)
        return;
    for (unsigned i = 0; i < MaxMiceSupported; ++i)
        pCSSData->MouseState[i] = CSSHolderBase::MouseStateType();
    pCSSData->UrlZones.RemoveAll();

    Render::Text::StyledText* ptext = pDocument->GetStyledText();
    String  url;
    UPInt   urlStart = 0, urlLen = 0;
    for (unsigned i = 0; i < ptext->GetParagraphsCount(); ++i)
    {
        const Render::Text::Paragraph* ppara = ptext->GetParagraph(i);
        for (Render::Text::Paragraph::FormatRunIterator it = ppara->GetIterator(); !it.IsFinished(); ++it)
        {
            UPInt runPos = it->Index + ppara->GetStartIndex();
            if (!it->pFormat->IsUrlSet())
                continue;
            if (!url.IsEmpty())
            {
                if (runPos == urlStart + urlLen && url == it->pFormat->GetUrl())
                {
                    urlLen += it->Length;
                    continue;
                }
                CSSHolderBase::UrlZone zone;
                zone.SavedFmt = *pDocument->GetStyledText()->CopyStyledText(urlStart, urlStart + urlLen);
                pCSSData->UrlZones.InsertRange(urlStart, urlLen, zone);
                url.Clear();
            }
            if (url.IsEmpty())
            {
                urlLen   = it->Length;
                url      = it->pFormat->GetUrl();
                urlStart = runPos;
            }
        }
    }
    if (!url.IsEmpty())
    {
        CSSHolderBase::UrlZone zone;
        zone.SavedFmt = *pDocument->GetStyledText()->CopyStyledText(urlStart, urlStart + urlLen);
        pCSSData->UrlZones.InsertRange(urlStart, urlLen, zone);
    }
}


// The interactive-object flags (+0xb8; the field's own Flags word hides the member name).
static inline UInt32 IntObjFlagsOf(const TextField* ptf)
{
    return ptf->InteractiveObject::Flags;
}

// The position in pixels (the geometry keeps twips).
// @0x1425b95f0
Double TextField::GetX() const
{
    GeomDataType geomData;
    const_cast<TextField*>(this)->UpdateAndGetGeomData(&geomData);
    return Render::TwipsToPixels(Double(geomData.X));
}

// @0x1425b9690
Double TextField::GetY() const
{
    GeomDataType geomData;
    const_cast<TextField*>(this)->UpdateAndGetGeomData(&geomData);
    return Render::TwipsToPixels(Double(geomData.Y));
}

// The default text color without its alpha.
// @0x1425b9360
UInt32 TextField::GetTextColor32() const
{
    return pDocument->GetDefaultTextFormat()->GetColor32() & 0xFFFFFFu;
}

// The formatted text's size in pixels.
// @0x1425b93d0
Double TextField::GetTextHeight() const
{
    return Render::TwipsToPixels(pDocument->GetTextHeight());
}

// @0x1425b9400
Double TextField::GetTextWidth() const
{
    return Render::TwipsToPixels(pDocument->GetTextWidth());
}

// The characters the editor accepts (NULL: any, or no editor).
// @0x1425b90a0
const String* TextField::GetRestrict() const
{
    const Text::EditorKit* peditor = static_cast<const Text::EditorKit*>(pDocument->GetEditorKit());
    return peditor ? peditor->GetRestrict() : NULL;
}

// The shadow style string as last set (empty before).
// @0x1425b9100
ASString TextField::GetShadowStyle() const
{
    if (pShadow)
        return pShadow->ShadowStyleStr;
    return ASString(GetStringManager()->GetEmptyStringNode());
}

// The text, or the HTML text when asked for and the field is HTML; with a style sheet the HTML is the original
// source text.
// MS2-FUNCTIONAL 0x1425b91e0: same text/html/original-text choice; the exe repeats the GetText tail per branch
// @0x1425b91e0
ASString TextField::GetText(bool reqHtml) const
{
    ASStringManager* psm = GetStringManager();
    if (reqHtml)
    {
        if (HasStyleSheet())
            return psm->CreateString(OriginalTextValue.ToCStr(), OriginalTextValue.GetSize());
        if (IsHtml())
        {
            String html = pDocument->GetHtml();
            return psm->CreateString(html.ToCStr(), html.GetSize());
        }
    }
    String text = pDocument->GetText();
    return psm->CreateString(text.ToCStr(), text.GetSize());
}

// The field takes the focus only from its own controller (any once none is set).
// @0x1425b9a60
bool TextField::IsFocusAllowed(MovieImpl* proot, unsigned controllerIdx) const
{
    return (FocusedControllerIdx == ~0u || FocusedControllerIdx == controllerIdx) &&
           InteractiveObject::IsFocusAllowed(proot, controllerIdx);
}

// @0x1425b9a30
bool TextField::IsFocusAllowed(MovieImpl* proot, unsigned controllerIdx)
{
    return (FocusedControllerIdx == ~0u || FocusedControllerIdx == controllerIdx) &&
           InteractiveObject::IsFocusAllowed(proot, controllerIdx);
}

// @0x1425b9a90
bool TextField::IsFocusEnabled(FocusMovedType fmt) const
{
    if (HasAvmObject())
        return GetAvmObjImpl()->ToAvmTextFieldBase()->IsFocusEnabled(fmt);
    return false;
}

// Tab reaches a visible, editable field unless tabEnabled says no (undefined: the AVM side decides).
// @0x1425b9b90
bool TextField::IsTabable() const
{
    if (!GetVisible() || IsReadOnly())
        return false;
    UInt32 tabEnabled = IntObjFlagsOf(this) & InteractiveObject::Mask_TabEnabled;
    if (tabEnabled == 0)
    {
        if (HasAvmObject())
            return GetAvmObjImpl()->ToAvmTextFieldBase()->IsTabable();
        return true;
    }
    return tabEnabled == InteractiveObject::Mask_TabEnabled;
}

// @0x1425b9770
void TextField::HighlightCompositionStringText(UPInt pos, UPInt len, unsigned hcategory)
{
    if (!pDocument->GetEditorKit())
        return;
    Ptr<Text::CompositionString> pcs =
        static_cast<Text::CompositionString*>(pDocument->GetEditorKit()->GetCompositionString());
    if (pcs)
    {
        pcs->HighlightText(pos, len, (Text::IMEStyle::Category)hcategory);
        SetDirtyFlag();
    }
}

// The view scrolled: the AVM side's onScroller.
// @0x1425ba710
void TextField::TextDocumentListener::OnScroll(Render::Text::DocView&)
{
    TextField* ptf = GetTextField();
    if (ptf->HasAvmObject())
        ptf->GetAvmObjImpl()->ToAvmTextFieldBase()->OnScroll();
}

// Inside the view rectangle (an invisible field is missed when asked to ignore those).
// @0x1425ba750
bool TextField::PointTestLocal(const PointF& pt, UByte hitTestMask) const
{
    if (IntObjFlagsOf(this) & InteractiveObject::Mask_HitTestDisable)
        return false;
    if ((hitTestMask & HitTest_IgnoreInvisible) && !GetVisible())
        return false;
    return pDocument->GetViewRect().Contains(pt);
}

// The wheel scrolls the text when mouseWheelEnabled.
// @0x1425ba680
bool TextField::OnMouseWheelEvent(int mwDelta)
{
    if (!(Flags & Flags_MouseWheelEnabled))
        return false;
    int vscroll = int(pDocument->GetVScrollOffset()) - mwDelta;
    if (vscroll < 0)
        vscroll = 0;
    if (vscroll > int(pDocument->GetMaxVScroll()))
        vscroll = pDocument->GetMaxVScroll();
    pDocument->SetVScrollOffset(unsigned(vscroll));
    SetDirtyFlag();
    return true;
}

// Whether mouse mouseIndex is over the zone of urlRange still (false once another zone overlapping it is hit).
// @0x1425b9c20
bool TextField::IsUrlTheSame(unsigned mouseIndex, const Range& urlRange)
{
    if (!pCSSData)
        return true;
    RangeDataArray<CSSHolderBase::UrlZone>& zones = pCSSData->UrlZones;
    for (unsigned i = 0; i < zones.Count(); ++i)
    {
        const RangeData<CSSHolderBase::UrlZone>& zone = zones[i];
        if (zone.Index < urlRange.NextIndex() && urlRange.Index < zone.NextIndex() &&
            pCSSData->MouseState[mouseIndex].UrlZoneIndex != i + 1)
            return false;
    }
    return true;
}

// The last position of mouse mouseIndex (the movie keeps four mouse states; without the player layout their
// storage is opaque here).
static inline const Render::PointF& MouseLastPositionOf(MovieImpl* proot, unsigned mouseIndex)
{
    const MouseState* pms =
        mouseIndex < 4 ? reinterpret_cast<const MouseState*>(proot->MouseState0_1260) + mouseIndex : NULL;
    return pms->GetLastPosition();
}

// MS2-FUNCTIONAL 0x1425b9cc0: same mouse point through the inverse world matrix; the exe calls the out-of-line TransformByInverse
// @0x1425b9cc0
bool TextField::IsUrlUnderMouseCursor(unsigned mouseIndex, Render::PointF* ppnt, Range* purlRangePos)
{
    MovieImpl* proot = GetMovieImpl();
    if (!proot)
        return false;
    Render::PointF mousePos = MouseLastPositionOf(proot, mouseIndex);
    Matrix worldMat;
    GetWorldMatrix(&worldMat);
    Render::PointF pnt = worldMat.TransformByInverse(mousePos);
    if (ppnt)
        *ppnt = pnt;
    return pDocument->IsUrlAtPoint(pnt.x, pnt.y, purlRangePos);
}

// A character for the editor: an editable or selectable field takes it from its focusing controller, after the
// AVM side let it through.
// @0x1425b9de0
bool TextField::OnCharEvent(UInt32 wcharCode, unsigned controllerIdx)
{
    if (GetMovieImpl() && pDocument->GetEditorKit())
    {
        if (IsReadOnly() && !IsSelectable())
            return true;
        if (FocusedControllerIdx == controllerIdx &&
            GetAvmObjImpl()->ToAvmTextFieldBase()->OnCharEvent(wchar_t(wcharCode), controllerIdx))
            EditorOf(pDocument)->OnChar(wcharCode);
    }
    return true;
}

// Loaded: the definition's initial text is set and laid out, then the field joins the play list; its geometry
// is taken now unless it already has some.
// @0x1425b9ec0
void TextField::OnEventLoad()
{
    const char* ptext = pDef->DefaultText.GetLength() ? pDef->DefaultText.ToCStr() : "";
    SetTextValue(ptext, IsHtml(), false);
    pDocument->Format();
    InteractiveObject::OnEventLoad();
    if (!pGeomData)
    {
        GeomDataType geomData;
        UpdateAndGetGeomData(&geomData, true);
    }
}

// Unloaded: the IME manager is looked up (its focus handling is compiled out) and the text's layout is
// invalidated before the base unload.
// MS2-FUNCTIONAL 0x1425b9fc0: the exe only takes and drops the IME manager reference here
// @0x1425b9fc0
void TextField::OnEventUnload()
{
    SetUnloading();
    MovieImpl* proot = GetMovieImpl();
    if (proot)
        Ptr<IMEManagerBase> pimeManager = proot->GetIMEManager();
    static_cast<Render::TreeText*>(GetRenderNode())->NotifyLayoutChanged();
    InteractiveObject::OnEventUnload();
}

// The host's on-screen keyboard (state 8; no other unit needs it yet): told when an editable field gains or loses
// the focus.
class VirtualKeyboardInterface : public State
{
public:
    enum { State_VirtualKeyboardInterface = 8 };
    VirtualKeyboardInterface() : State(StateType(State_VirtualKeyboardInterface)) {}
    virtual void OnInputTextfieldFocusIn(bool multiline, const Render::RectF& textBox) = 0;   // 1
    virtual void OnInputTextfieldFocusOut() = 0;                                               // 2
};

static inline Ptr<VirtualKeyboardInterface> GetVirtualKeyboardInterfaceOf(MovieImpl* proot)
{
    return *static_cast<VirtualKeyboardInterface*>(
        proot->GetStateBag()->GetStateAddRef(State::StateType(VirtualKeyboardInterface::State_VirtualKeyboardInterface)));
}

inline bool MovieImpl::IsFocused(const InteractiveObject* ch, unsigned controllerIdx) const
{
    Ptr<InteractiveObject> focused = FocusGroups[FocusGroupIndexes[controllerIdx]].LastFocused;
    return focused.GetPtr() == ch;
}

// A selectable field selects all of its text when the keyboard moves the focus in (unless noAutoSelection) and
// shows its cursor; losing the focus drops the selection (unless alwaysShowSelection). The on-screen keyboard
// hears of it, and an editable field starts advancing to blink the cursor.
// MS2-FUNCTIONAL 0x1425ba020: same selection, virtual keyboard and play list steps; the exe lays the focus rect out in a different frame
// @0x1425ba020
void TextField::OnFocus(FocusEventType event, InteractiveObject* oldOrNewFocusCh, unsigned controllerIdx,
                        FocusMovedType fmt)
{
    if (IsSelectable())
    {
        if (event == InteractiveObject::SetFocus)
        {
            if (!(Flags & Flags_NoAutoSelection) && fmt == GFx_FocusMovedByKeyboard)
            {
                SPInt len = (SPInt)pDocument->GetLength();
                if (!pDocument->GetEditorKit())
                    CreateEditorKit();
                if (pDocument->GetEditorKit())
                {
                    SPInt docLen = (SPInt)pDocument->GetLength();
                    SPInt endPos = len < 0 ? 0 : (len > docLen ? docLen : len);
                    SPInt begPos = docLen < 0 ? docLen : 0;
                    EditorOf(pDocument)->SetSelection(UPInt(begPos), UPInt(endPos));
                    SetDirtyFlag();
                }
            }
            FocusedControllerIdx = controllerIdx;
            if (pDocument->GetEditorKit())
            {
                EditorOf(pDocument)->OnSetFocus();
                SetDirtyFlag();
                Ptr<VirtualKeyboardInterface> vki = GetVirtualKeyboardInterfaceOf(GetMovieImpl());
                if (vki)
                {
                    Matrix worldMat;
                    GetWorldMatrix(&worldMat);
                    Render::RectF bounds = GetBounds(worldMat);
                    Render::RectF worldRect(Render::TwipsToPixels(bounds.x1), Render::TwipsToPixels(bounds.y1),
                                            Render::TwipsToPixels(bounds.x2), Render::TwipsToPixels(bounds.y2));
                    vki->OnInputTextfieldFocusIn(pDocument->IsMultiline(), worldRect);
                }
            }
        }
        else if (event == InteractiveObject::KillFocus)
        {
            FocusedControllerIdx = ~0u;
            if (pDocument->GetEditorKit())
            {
                if (!(Flags & Flags_AlwaysShowSelection))
                    EditorOf(pDocument)->ClearSelection();
                EditorOf(pDocument)->OnKillFocus();
                SetDirtyFlag();
                Ptr<VirtualKeyboardInterface> vki = GetVirtualKeyboardInterfaceOf(GetMovieImpl());
                if (vki)
                    vki->OnInputTextfieldFocusOut();
            }
        }
    }

    if (IsReadOnly() && !IsSelectable())
    {
        if (event != InteractiveObject::KillFocus && !IsFocusEnabled(fmt))
            return;
        InteractiveObject::OnFocus(event, oldOrNewFocusCh, controllerIdx, fmt);
        return;
    }
    ResetBlink(event == InteractiveObject::SetFocus, event == InteractiveObject::SetFocus);
    InteractiveObject::OnFocus(event, oldOrNewFocusCh, controllerIdx, fmt);
    if (pDocument->GetEditorKit() && EditorOf(pDocument)->HasCursor())
    {
        Flags |= Flags_ForceOneTimeAdvance;
        if (!IsInPlayList())
            AddToPlayList();
        ModifyOptimizedPlayListLocal<TextField>();
    }
}

// A key for the focused field: the AVM side hears it first, then the editor of an editable or selectable field
// (Insert toggles overwrite mode). The focus group's handled bit is set.
// @0x1425ba3e0
bool TextField::OnKeyEvent(const EventId& id, int* pkeyMask)
{
    MovieImpl* proot = GetMovieImpl();
    unsigned focusGroup = proot->FocusGroupIndexes[id.KeyboardIndex];
    int groupBit = (1 << focusGroup) & 0xFFFF /* the focused-item-handled bits */;
    if ((*pkeyMask & groupBit) || !proot || !proot->IsFocused(this, id.KeyboardIndex))
        return false;
    if (HasAvmObject())
        GetAvmObjImpl()->ToAvmTextFieldBase()->OnKeyEvent(id, pkeyMask);
    if (pDocument->GetEditorKit() && (!IsReadOnly() || IsSelectable()))
    {
        if (id.Id == EventId::Event_KeyDown)
        {
            EditorOf(pDocument)->OnKeyDown(int(id.KeyCode), KeyModifiers(id.KeysState));
            if (id.KeyCode == Key::Insert && pDocument->GetEditorKit())
            {
                Text::EditorKit* peditor = EditorOf(pDocument);
                if (peditor->IsOverwriteMode())
                    peditor->ClearOverwriteMode();
                else
                    peditor->SetOverwriteMode();
            }
        }
        else if (id.Id == EventId::Event_KeyUp)
            EditorOf(pDocument)->OnKeyUp(int(id.KeyCode), KeyModifiers(id.KeysState));
    }
    *pkeyMask |= groupBit;
    return true;
}

// @0x1425ba620
bool TextField::OnMouseEvent(const EventId& event)
{
    PropagateMouseEvent(event);
    if (HasAvmObject())
        return GetAvmObjImpl()->ToAvmTextFieldBase()->OnMouseEvent(event);
    return false;
}

// The text filters' blending flags as blur filter mode bits.
static inline unsigned TextFilterFlagsToMode(UInt8 flags)
{
    unsigned mode = (flags & Render::TreeText::FilterFlag_KnockOut) ? unsigned(Render::BlurFilterParams::Mode_Knockout) : 0u;
    if (flags & Render::TreeText::FilterFlag_HideObject)
        mode |= Render::BlurFilterParams::Mode_HideObject;
    if (flags & Render::TreeText::FilterFlag_FineBlur)
        mode |= Render::BlurFilterParams::Mode_Highlight;
    return mode;
}

// The filters of the text node as a filter set, made once from up to three text filters (blur, glow, drop
// shadow); NULL when the text has none.
// MS2-FUNCTIONAL 0x1425b8250: same filters made from the text node's; the exe keeps the filter temporaries in a different frame
// @0x1425b8250
const Render::FilterSet* TextField::GetFilters() const
{
    if (!GetRenderNode() || pFilters)
        return pFilters;
    Render::TreeText* ptextNode = static_cast<Render::TreeText*>(GetRenderNode());
    Render::TreeText::Filter filters[3];
    UPInt n = ptextNode->GetFilters(filters, 3);
    if (n == 0)
    {
        pFilters = NULL;
        return NULL;
    }
    pFilters = *SF_NEW Render::FilterSet;
    for (UPInt i = 0; i < n; ++i)
    {
        const Render::TreeText::Filter& tf = filters[i];
        if (tf.Type == Render::TreeText::Filter_DropShadow)
        {
            Ptr<Render::ShadowFilter> pf = *SF_NEW Render::ShadowFilter(
                float(tf.DropShadow.Angle * 3.14159265358979323846 / 180.0), tf.DropShadow.Distance,
                tf.DropShadow.BlurX, tf.DropShadow.BlurY);
            pf->GetParams().Strength  = tf.DropShadow.Strength / 100.f;
            pf->GetParams().Colors[0] = tf.DropShadow.Color;
            pf->GetParams().Mode      = TextFilterFlagsToMode(tf.DropShadow.Flags);
            pFilters->AddFilter(pf);
        }
        else if (tf.Type == Render::TreeText::Filter_Blur)
        {
            Ptr<Render::BlurFilter> pf = *SF_NEW Render::BlurFilter(tf.Blur.BlurX, tf.Blur.BlurY);
            pf->GetParams().Strength = tf.Blur.Strength / 100.f;
            pFilters->AddFilter(pf);
        }
        else if (tf.Type == Render::TreeText::Filter_Glow)
        {
            Ptr<Render::GlowFilter> pf = *SF_NEW Render::GlowFilter(tf.Glow.BlurX, tf.Glow.BlurY);
            pf->GetParams().Strength  = tf.Glow.Strength / 100.f;
            pf->GetParams().Colors[0] = tf.Glow.Color;
            pf->GetParams().Mode      = TextFilterFlagsToMode(tf.Glow.Flags);
            pFilters->AddFilter(pf);
        }
    }
    return pFilters;
}

// The definition's font, through the binding (NULL, with an error logged, when it is missing or no font).
// @0x1425b87f0
FontResource* TextField::GetFontResource()
{
    if (!pDef->FontId.GetIdIndex())
        return NULL;
    ResourceBindData fontData = pBinding->GetResourceData(pDef->pFont);
    if (!fontData.pResource)
    {
        Ptr<Log> plog = GetLog();
        if (plog)
            plog->LogError("Resource for font id = %d is not found in text field id = %d, def text = '%s'",
                           pDef->FontId.GetIdIndex(), unsigned(UInt16(Id)), pDef->DefaultText.ToCStr());
    }
    else if (fontData.pResource->GetResourceType() != Resource::RT_Font)
    {
        Ptr<Log> plog = GetLog();
        if (plog)
            plog->LogError("Font id = %d is referring to non-font resource in text field id = %d, def text = '%s'",
                           pDef->FontId.GetIdIndex(), unsigned(UInt16(Id)), pDef->DefaultText.ToCStr());
    }
    else
        return static_cast<FontResource*>(fontData.pResource.GetPtr());
    return NULL;
}

// The display properties in pixels, percent and degrees, all of them set.
// @0x1425b8e60
void TextField::GetPosition(GFx::Value::DisplayInfo* pinfo)
{
    GeomDataType geomData;
    UpdateAndGetGeomData(&geomData, false);
    Double x = Render::TwipsToPixels(Double(geomData.X));
    Double y = Render::TwipsToPixels(Double(geomData.Y));
    Double alpha = GetCxform().M[0][3] * 100.f;
    bool visible = GetVisible();
    pinfo->XRotation = geomData.XRotation;
    pinfo->YRotation = geomData.YRotation;
    pinfo->Visible   = visible;
    pinfo->VarsSet  |= 0x7ff;   // x .. zscale
    pinfo->ZScale    = geomData.ZScale;
    pinfo->X         = x;
    pinfo->Y         = y;
    pinfo->Rotation  = geomData.Rotation;
    pinfo->Alpha     = alpha;
    pinfo->Z         = geomData.Z;
    pinfo->XScale    = geomData.XScale;
    pinfo->YScale    = geomData.YScale;
}

// Hit under the mouse: a selectable field (or any, when testing all) is the hit itself, as is a link of an HTML
// field; otherwise the first enclosing sprite that acts as a button takes it.
// @0x1425b9430
DisplayObjectBase::TopMostResult TextField::GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr)
{
    pdescr->pResult = NULL;
    if ((IntObjFlagsOf(this) & InteractiveObject::Mask_HitTestDisable) || !GetVisible() || pdescr->pIgnoreMC == this)
        return TopMost_FoundNothing;

    PointF localPt;
    TransformPointToLocal(&localPt, pt, true, NULL);
    if (ClipDepth == 0 && PointTestLocal(localPt, HitTest_TestShape))
    {
        if (pdescr->TestAll || IsSelectable() ||
            (!IsSelectable() && IsHtml() && pDocument->MayHaveUrl() &&
             pDocument->IsUrlAtPoint(localPt.x, localPt.y, NULL)))
        {
            pdescr->pResult = this;
            return TopMost_Found;
        }
        for (InteractiveObject* pparent = GetParent(); pparent && pparent->IsSprite(); pparent = pparent->GetParent())
        {
            if (pdescr->TestAll || (pparent->HasAvmObject() && pparent->GetAvmIntObj()->ActsAsButton()))
            {
                if (!pdescr->pIgnoreMC || pparent != pdescr->pIgnoreMC)
                {
                    pdescr->pResult = pparent;
                    return TopMost_Found;
                }
            }
        }
    }
    pdescr->LocalPt = localPt;
    pdescr->pResult = NULL;
    return TopMost_Continue;
}

// ---- batch 2c draft (sfr33): insert before the closing namespace of sfr_gfx_03e.cpp ----

// The definition's font and layout as the initial text and paragraph formats: the font by id through the binding,
// or by class through the exports (used as the font name when it is no exported resource); the font's name, its
// style unless the text is HTML, and a handle on it unless device fonts are used.
// @0x1425b8910
void TextField::GetInitialFormats(Render::Text::TextFormat* ptextFmt, Render::Text::ParagraphFormat* pparaFmt)
{
    ptextFmt->InitByDefaultValues();
    pparaFmt->InitByDefaultValues();

    ResourceBindData fontData;
    bool lookForResource = true;
    if (pDef->FontId.GetIdIndex())
        fontData = pBinding->GetResourceData(pDef->pFont);
    else if (pDef->FontClass.GetSize() > 0)
    {
        Ptr<MovieDefImpl> md = GetResourceMovieDef();
        if (!GetMovieImpl()->FindExportedResource(md, &fontData, pDef->FontClass))
        {
            ptextFmt->SetFontName(pDef->FontClass);
            lookForResource = false;
        }
    }
    if (lookForResource && (pDef->FontId.GetIdIndex() || pDef->FontClass.GetSize() > 0))
    {
        if (!fontData.pResource)
        {
            Ptr<Log> plog = GetLog();
            if (plog)
            {
                if (pDef->FontId.GetIdIndex())
                    plog->LogError("Resource for font id = %d is not found in text field id = %d, def text = '%s'",
                                   pDef->FontId.GetIdIndex(), unsigned(UInt16(Id)), pDef->DefaultText.ToCStr());
                else
                    plog->LogError("Resource for font class = '%s' is not found in text field id = %d, def text = '%s'",
                                   pDef->FontClass.ToCStr(), unsigned(UInt16(Id)), pDef->DefaultText.ToCStr());
            }
        }
        else if (fontData.pResource->GetResourceType() != Resource::RT_Font)
        {
            Ptr<Log> plog = GetLog();
            if (plog)
                plog->LogError("Font id = %d is referring to non-font resource in text field id = %d, def text = '%s'",
                               pDef->FontId.GetIdIndex(), unsigned(UInt16(Id)), pDef->DefaultText.ToCStr());
        }
        else
        {
            FontResource* pfontRes = static_cast<FontResource*>(fontData.pResource.GetPtr());
            if (pfontRes)
            {
                Render::Font* pfont = pfontRes->GetFont();
                ptextFmt->SetFontName(pfont->GetName());
                // HTML sets its own fonts by name.
                if (!pDef->HasFlag(TextFieldDef::Flags_Html))
                {
                    ptextFmt->SetBold(pfont->IsBold());
                    ptextFmt->SetItalic(pfont->IsItalic());
                    if (!pDef->HasFlag(TextFieldDef::Flags_UseDeviceFont) && pfont->IsResolved())
                    {
                        Ptr<FontHandle> pfontHandle =
                            *SF_NEW FontHandle(NULL, pfont, NULL, 0, fontData.pBinding->GetOwnerDefImpl());
                        ptextFmt->SetFontHandle(pfontHandle);
                    }
                }
            }
        }
    }
    unsigned twips = unsigned(pDef->TextHeight);
    ptextFmt->SetFontSizeInFixp(twips <= 0x10000 ? twips : 0xFFFFu);
    ptextFmt->SetColorARGB(pDef->ColorV.ToColor32());

    Render::Text::ParagraphFormat defaultParagraphFmt;
    switch (pDef->Alignment)
    {
    case TextFieldDef::ALIGN_LEFT:    pparaFmt->SetAlignment(Render::Text::ParagraphFormat::Align_Left); break;
    case TextFieldDef::ALIGN_RIGHT:   pparaFmt->SetAlignment(Render::Text::ParagraphFormat::Align_Right); break;
    case TextFieldDef::ALIGN_CENTER:  pparaFmt->SetAlignment(Render::Text::ParagraphFormat::Align_Center); break;
    case TextFieldDef::ALIGN_JUSTIFY: pparaFmt->SetAlignment(Render::Text::ParagraphFormat::Align_Justify); break;
    }
    if (pDef->HasFlag(TextFieldDef::Flags_HasLayout))
    {
        pparaFmt->SetLeftMargin(unsigned(Render::TwipsToPixels(pDef->LeftMargin)));
        pparaFmt->SetRightMargin(unsigned(Render::TwipsToPixels(pDef->RightMargin)));
        pparaFmt->SetIndent(int(Render::TwipsToPixels(pDef->Indent)));
        pparaFmt->SetLeading(int(Render::TwipsToPixels(pDef->Leading)));
    }
}

// The images of <img> tags: each url names an exported image (or a protocol image the image creator loads); the
// image goes into the tag's image descriptor, sized by the tag (or the image, in twips) and moved up by its height
// plus the vertical space, and the document is reformatted.
// @0x1425ba7d0
void TextField::ProcessImageTags(Render::Text::StyledText::HTMLImageTagInfoArray& imageInfoArray)
{
    UPInt n = imageInfoArray.GetSize();
    if (n > 0)
        static_cast<Render::TreeText*>(GetRenderNode())->NotifyLayoutChanged();
    for (UPInt i = 0; i < n; ++i)
    {
        Render::Text::StyledText::HTMLImageTagInfo& imgTagInfo = imageInfoArray[i];
        ResourceBindData resBindData;
        Ptr<MovieDefImpl> md = GetResourceMovieDef();
        if (!md)
            continue;
        // img:// and imgps:// urls go to the image creator, the others are export names.
        bool userImageProtocol = LoaderImpl::IsProtocolImage(imgTagInfo.Url);
        if (!userImageProtocol && !GetMovieImpl()->FindExportedResource(md, &resBindData, imgTagInfo.Url))
        {
            if (GetLog())
                GetLog()->LogWarning("ProcessImageTags: can't find a resource for export name '%s'\n",
                                     imgTagInfo.Url.ToCStr());
            continue;
        }
        if (userImageProtocol || resBindData.pResource->GetResourceType() == Resource::RT_Image)
        {
            Ptr<Render::Image> img;
            if (!userImageProtocol)
            {
                Ptr<ImageResource> pimgRes = GetMovieImpl()->GetImageResourceByLinkageId(GetResourceMovieDef(),
                                                                                         imgTagInfo.Url.ToCStr());
                if (!pimgRes)
                {
                    if (GetLog())
                        GetLog()->LogWarning("ProcessImageTags: can't load the image '%s'\n", imgTagInfo.Url.ToCStr());
                    continue;
                }
                if (pimgRes->GetImage()->GetImageType() != Render::ImageBase::Type_ImageBase)
                    img = static_cast<Render::Image*>(pimgRes->GetImage());
                else if (!Ptr<ImageCreator>(*static_cast<ImageCreator*>(md->GetStateAddRef(State::State_ImageCreator))))
                    LogDebugMessage(Log_Warning, "ImageCreator is null in ProcessImageTags");
                else
                {
                    ImageCreateInfo cinfo(ImageCreateInfo::Create_SourceImage, Memory::GetHeapByAddress(this), 1,
                                          Resource::Use_Bitmap);
                    img = *Ptr<ImageCreator>(*static_cast<ImageCreator*>(md->GetStateAddRef(State::State_ImageCreator)))
                               ->CreateImage(cinfo, static_cast<Render::ImageSource*>(pimgRes->GetImage()));
                }
            }
            else
            {
                ImageCreateInfo cinfo(ImageCreateInfo::Create_FileImage, md->GetWeakLib()->GetImageHeap(), 0,
                                      Resource::Use_Bitmap);
                Ptr<State> pregistry = *md->GetStateAddRef(State::State_ImageFileHandlerRegistry);
                Ptr<State> popener   = *md->GetStateAddRef(State::State_FileOpener);
                cinfo.SetStates(md->GetLog(), popener, reinterpret_cast<ImageFileHandlerRegistry*>(pregistry.GetPtr()));
                cinfo.pMovie = GetMovieImpl();
                ImageCreator* pcreator =
                    Ptr<ImageCreator>(*static_cast<ImageCreator*>(md->GetStateAddRef(State::State_ImageCreator)));
                if (pcreator)
                    img = *pcreator->LoadProtocolImage(cinfo, imgTagInfo.Url);
                else
                    LogDebugMessage(Log_Warning, "Image resource creation failed - ImageCreator not installed");
            }
            if (!img)
            {
                LogDebugMessage(Log_Warning, "Image '%s' wasn't created in ProcessImageTags", imgTagInfo.Url.ToCStr());
                continue;
            }
            Render::ImageRect dimr = img->GetRect();
            imgTagInfo.pTextImageDesc->pImage = img;
            float origWidth = float(dimr.Width()), origHeight = float(dimr.Height());
            float screenWidth  = float(imgTagInfo.Width ? imgTagInfo.Width : dimr.Width() * 20);
            float screenHeight = float(imgTagInfo.Height ? imgTagInfo.Height : dimr.Height() * 20);
            float baseLineY    = origHeight * 20.f + float(imgTagInfo.VSpace);
            Render::Text::ImageDesc* pdesc = imgTagInfo.pTextImageDesc;
            pdesc->ScreenWidth  = screenWidth;
            pdesc->ScreenHeight = screenHeight;
            pdesc->BaseLineY    = Render::TwipsToPixels(baseLineY);
            pdesc->Matrix.AppendTranslation(0, -pdesc->BaseLineY);
            pdesc->Matrix.AppendScaling(screenWidth / origWidth, screenHeight / origHeight);
            pDocument->SetCompleteReformatReq();
        }
        else if (resBindData.pResource->GetResourceType() == Resource::RT_SpriteDef)
        {
            // a sprite: not supported
        }
    }
}

// The state of mouse mouseIndex (the movie keeps four).
static inline const MouseState* MouseStateOf(MovieImpl* proot, unsigned mouseIndex)
{
    return mouseIndex < 4 ? reinterpret_cast<const MouseState*>(proot->MouseState0_1260) + mouseIndex : NULL;
}

// The entity under the cursor, with a reference (TopmostEntity, the state's first member, is protected).
static inline Ptr<InteractiveObject> TopmostEntityOf(const MouseState* pms)
{
    return *reinterpret_cast<const WeakPtr<InteractiveObject>*>(pms);
}

// The mouse over the field: the URL under the cursor takes the style sheet's link formats and the hand cursor, the
// editor gets the press, the release and the moves (in the field's space), then the field's own handlers run.
// MS2-FUNCTIONAL 0x1425badd0: same event cases; the exe inlines the first HasStyleSheet and calls the out-of-line TransformByInverse
// @0x1425badd0
void TextField::PropagateMouseEvent(const EventId& id)
{
    MovieImpl* proot = GetMovieImpl();
    if (!proot)
        return;
    if (id.Id == EventId::Event_MouseMove)
        DoMouseDrag();

    Ptr<InteractiveObject> ptopMostChar = TopmostEntityOf(MouseStateOf(proot, id.MouseIndex));

    // the cursor left the field (or its URL): the URL formats go back
    if ((ptopMostChar != this || id.Id == EventId::Event_RollOut) &&
        HasStyleSheet() && IsHtml() && pDocument->MayHaveUrl())
    {
        ChangeUrlFormat(Link_release, id.MouseIndex);
        ChangeUrlFormat(Link_rollout, id.MouseIndex);
    }

    if (ptopMostChar == this || (pDocument->HasEditorKit() && EditorOf(pDocument)->IsMouseCaptured()))
    {
        if (!GetVisible())
            return;
        switch (id.Id)
        {
        case EventId::Event_MouseMove:
            {
                const MouseState* pms = MouseStateOf(proot, id.MouseIndex);
                if (pDocument->HasEditorKit())
                {
                    Matrix m;
                    GetWorldMatrix(&m);
                    Render::PointF b = m.TransformByInverse(pms->GetLastPosition());
                    EditorOf(pDocument)->OnMouseMove(b.x, b.y);
                }
                if (HasStyleSheet() && IsHtml() && pDocument->MayHaveUrl())
                {
                    Range urlRange;
                    bool urlIsUnderCursor = IsUrlUnderMouseCursor(id.MouseIndex, NULL, &urlRange);
                    if (urlIsUnderCursor)
                    {
                        if (!IsUrlTheSame(id.MouseIndex, urlRange))
                        {
                            ChangeUrlFormat(Link_release, id.MouseIndex);
                            ChangeUrlFormat(Link_rollout, id.MouseIndex);
                        }
                        ChangeUrlFormat((pms->GetButtonsState() & MouseState::MouseButton_Left) ? Link_press : Link_rollover,
                                        id.MouseIndex, &urlRange);
                    }
                    else
                    {
                        ChangeUrlFormat(Link_release, id.MouseIndex);
                        ChangeUrlFormat(Link_rollout, id.MouseIndex);
                    }
                    if (urlIsUnderCursor)
                        Flags |= Flags_HandCursor;
                    else
                        Flags &= ~Flags_HandCursor;
                }
                else if (IsHtml() && pDocument->MayHaveUrl())
                {
                    if (IsUrlUnderMouseCursor(id.MouseIndex))
                        Flags |= Flags_HandCursor;
                    else
                        Flags &= ~Flags_HandCursor;
                }
                else if (Flags & Flags_HandCursor)
                {
                    ChangeUrlFormat(Link_rollout, id.MouseIndex);
                    Flags &= ~Flags_HandCursor;
                }
                else
                    break;
                proot->ChangeMouseCursorType(id.MouseIndex, GetCursorType());
            }
            break;
        case EventId::Event_MouseDown:
            if (HasStyleSheet() && IsHtml() && pDocument->MayHaveUrl())
            {
                const MouseState* pms = MouseStateOf(proot, id.MouseIndex);
                Range urlRange;
                if (IsUrlUnderMouseCursor(id.MouseIndex, NULL, &urlRange) && pCSSData &&
                    pCSSData->HasASStyleSheet() && (pms->GetButtonsState() & MouseState::MouseButton_Left))
                    ChangeUrlFormat(Link_press, id.MouseIndex, &urlRange);
            }
            if (pDocument->HasEditorKit())
            {
                const MouseState* pms = MouseStateOf(proot, id.MouseIndex);
                Matrix m;
                GetWorldMatrix(&m);
                Render::PointF b = m.TransformByInverse(pms->GetLastPosition());
                EditorOf(pDocument)->OnMouseDown(b.x, b.y, pms->GetButtonsState());
                if (!IsInPlayList())
                    AddToPlayList();
                ModifyOptimizedPlayListLocal<TextField>();
            }
            break;
        case EventId::Event_MouseUp:
        case EventId::Event_ReleaseOutside:
            if (HasStyleSheet() && IsHtml() && pDocument->MayHaveUrl())
            {
                const MouseState* pms = MouseStateOf(proot, id.MouseIndex);
                Range urlRange;
                if (IsUrlUnderMouseCursor(id.MouseIndex, NULL, &urlRange) && pCSSData &&
                    pCSSData->HasASStyleSheet() && !(pms->GetButtonsState() & MouseState::MouseButton_Left))
                    ChangeUrlFormat(Link_release, id.MouseIndex, &urlRange);
                ChangeUrlFormat(Link_release, id.MouseIndex);
            }
            if (pDocument->HasEditorKit())
            {
                const MouseState* pms = MouseStateOf(proot, id.MouseIndex);
                Matrix m;
                GetWorldMatrix(&m);
                Render::PointF b = m.TransformByInverse(pms->GetLastPosition());
                EditorOf(pDocument)->OnMouseUp(b.x, b.y, pms->GetButtonsState());
                if (!IsInPlayList())
                    AddToPlayList();
                ModifyOptimizedPlayListLocal<TextField>();
            }
            break;
        default:
            break;
        }
    }
    InteractiveObject::PropagateMouseEvent(id);
}

// The URL zone of the style sheet that overlaps urlRange (NULL: none); its index in pindex.
static RangeData<TextField::CSSHolderBase::UrlZone>* FindUrlZone(TextField::CSSHolderBase* pcss, const Range& urlRange,
                                                                 unsigned* pindex)
{
    for (unsigned i = 0; i < unsigned(pcss->UrlZones.Count()); ++i)
    {
        RangeData<TextField::CSSHolderBase::UrlZone>& zone = pcss->UrlZones[i];
        if (zone.Index < urlRange.NextIndex() && urlRange.Index < zone.NextIndex())
        {
            *pindex = i;
            return &zone;
        }
    }
    return NULL;
}

// A link event of mouse mouseIndex on a URL of the text (the one in purlRange when the mouse is over none yet): the
// zone's press / over counts change, the AVM side hears the roll-overs and roll-outs, and when the zone's look
// changes its saved format comes back with the style sheet's a:active or a:hover style over it (on top of "a" and
// "a:link").
// MS2-FUNCTIONAL 0x1425b6a40: same counts, notifications and formats; the exe reloads the CSS holder after each store
// @0x1425b6a40
void TextField::ChangeUrlFormat(LinkEvent event, unsigned mouseIndex, const Range* purlRange)
{
    if (!HasStyleSheet())
        return;
    CSSHolderBase::MouseStateType& ms = pCSSData->MouseState[mouseIndex];
    RangeData<CSSHolderBase::UrlZone>* pzone = NULL;
    const char* styleName = NULL;
    unsigned zoneIdx;
    switch (event)
    {
    case Link_press:
        if (ms.UrlZoneIndex != 0)
        {
            if (ms.HitBit)
                return;
            ms.HitBit = true;
            pzone = &pCSSData->UrlZones[ms.UrlZoneIndex - 1];
            if (pzone->GetData().HitCount != 0)
            {
                ++pzone->GetData().HitCount;
                return;
            }
        }
        else
        {
            if ((pzone = FindUrlZone(pCSSData, *purlRange, &zoneIdx)) == NULL)
                return;
            ms.UrlZoneIndex = zoneIdx + 1;
            ms.HitBit       = true;
        }
        if (pzone->GetData().HitCount++ != 0)
            return;
        styleName = "a:active";
        break;

    case Link_release:
        if (ms.UrlZoneIndex == 0 || !ms.HitBit)
            return;
        ms.HitBit = false;
        zoneIdx   = ms.UrlZoneIndex - 1;
        if (!ms.OverBit)
            ms.UrlZoneIndex = 0;
        pzone = &pCSSData->UrlZones[zoneIdx];
        if (pzone->GetData().HitCount != 0)
        {
            if (--pzone->GetData().HitCount != 0)
                return;
            if (pzone->GetData().OverCount != 0)
                styleName = "a:hover";
        }
        break;

    case Link_rollover:
        if (ms.UrlZoneIndex != 0)
        {
            if (ms.OverBit)
                return;
            ms.OverBit = true;
            pzone = &pCSSData->UrlZones[ms.UrlZoneIndex - 1];
            if (pzone->GetData().OverCount != 0)
            {
                ++pzone->GetData().OverCount;
                if (HasAvmObject())
                    GetAvmObjImpl()->ToAvmTextFieldBase()->OnLinkEventEx(event, unsigned(pzone->Index), mouseIndex);
                return;
            }
        }
        else
        {
            if ((pzone = FindUrlZone(pCSSData, *purlRange, &zoneIdx)) == NULL)
                return;
            ms.UrlZoneIndex = zoneIdx + 1;
            ms.OverBit      = true;
            if (HasAvmObject())
                GetAvmObjImpl()->ToAvmTextFieldBase()->OnLinkEventEx(event, unsigned(pzone->Index), mouseIndex);
        }
        if (pzone->GetData().HitCount != 0 || pzone->GetData().OverCount++ != 0)
            return;
        styleName = "a:hover";
        break;

    case Link_rollout:
        if (ms.UrlZoneIndex == 0 || !ms.OverBit)
            return;
        ms.OverBit = false;
        pzone = &pCSSData->UrlZones[ms.UrlZoneIndex - 1];
        if (!ms.HitBit)
            ms.UrlZoneIndex = 0;
        if (pzone->GetData().OverCount != 0)
        {
            --pzone->GetData().OverCount;
            if (HasAvmObject())
                GetAvmObjImpl()->ToAvmTextFieldBase()->OnLinkEventEx(event, unsigned(pzone->Index), mouseIndex);
            if (pzone->GetData().OverCount != 0)
                return;
            if (pzone->GetData().HitCount != 0)
                styleName = "a:active";
        }
        break;

    default:
        return;
    }

    const UPInt startPos = UPInt(pzone->FirstIndex()), endPos = UPInt(pzone->NextIndex());
    if (pzone->GetData().SavedFmt)
    {
        // the zone's own format comes back first
        pDocument->RemoveText(startPos, endPos);
        pDocument->GetStyledText()->InsertStyledText(*pzone->GetData().SavedFmt, startPos);
    }
    if (!styleName)
        return;
    const Render::Text::StyleManagerBase* pstyles = pCSSData->GetTextStyleManager();
    const Render::Text::Style* pstyle = pstyles->GetStyle(Render::Text::StyleManagerBase::CSS_Tag, styleName);
    if (!pstyle)
        return;
    const Render::Text::Style* pastyle =
        pCSSData->GetTextStyleManager()->GetStyle(Render::Text::StyleManagerBase::CSS_Tag, "a");
    const Render::Text::Style* plinkStyle =
        pCSSData->GetTextStyleManager()->GetStyle(Render::Text::StyleManagerBase::CSS_Tag, "a:link");
    Render::Text::TextFormat fmt(Memory::GetHeapByAddress(this));
    if (pastyle)
        fmt = fmt.Merge(pastyle->mTextFormat);
    if (plinkStyle)
        fmt = fmt.Merge(plinkStyle->mTextFormat);
    fmt = fmt.Merge(pstyle->mTextFormat);
    pDocument->SetTextFormat(fmt, startPos, endPos);
}

}} // namespace Scaleform::GFx

namespace Scaleform { namespace Render {

// @0x1425b57e0
TreeText::Filter::Filter()
{
    Type = Filter_Unknown;
    InitByDefaultValues();
}

}} // namespace Scaleform::Render

// The text field's style sheet data (AS2 / AS3 TextField.styleSheet); out of line in the exe.
// @0x1425b7e60
Scaleform::UPInt FUN_1425b7e60(Scaleform::UPInt textField)
{
    return Scaleform::UPInt(reinterpret_cast<const Scaleform::GFx::TextField*>(textField)->GetCSSData());
}

// TextField::ClearRestrict, by its address for sfr_as3_13: drops the editor's restrict set (no editor, nothing).
// @0x1425b7280
void FUN_1425b7280(void* ptf)
{
    Scaleform::Render::Text::DocView* pdoc = static_cast<Scaleform::GFx::TextField*>(ptf)->GetDocument();
    if (Scaleform::GFx::Text::EditorKit* peditor = static_cast<Scaleform::GFx::Text::EditorKit*>(pdoc->GetEditorKit()))
        peditor->ClearRestrict();
}

namespace Scaleform { namespace GFx {

}} // namespace Scaleform::GFx
