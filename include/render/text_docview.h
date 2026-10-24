// Recovered Scaleform 4.1.18 Render Text: DocView, the view of a text field - the StyledText document, its
// formatted LineBuffer, scrolling, selection / highlighting, the editor kit hooks and the field-wide flags.
// DocView 0x150 bytes (vftable 0x14318e9c0), DocumentText 0x50 (vftable 0x14318e988).
// Bodies: Text_DocView (unit sfr_render_03b).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TEXT_DOCVIEW_H
#define MS2_SF_RENDER_TEXT_DOCVIEW_H

#include "ms2/scaleform/kernel/sf_log.h"
#include "ms2/scaleform/include/render/text_styledtext.h"
#include "ms2/scaleform/include/render/text_filterdesc.h"
#include "ms2/scaleform/include/render/text_linebuffer.h"
#include "ms2/scaleform/include/render/text_fontmanager.h"
#include "ms2/scaleform/include/render/render_font.h"

namespace Scaleform { namespace Render { namespace Text {

class DocView;

// The IME composition string an editor kit may be showing.
class CompositionStringBase : public RefCountBase<CompositionStringBase, StatRender_Text_Mem>
{
public:
    virtual UPInt          GetPosition() const        = 0;
    virtual UPInt          GetLength() const          = 0;
    virtual const wchar_t* GetText() const            = 0;
    virtual TextFormat*    GetTextFormat(UPInt pos)   = 0;
    virtual Allocator*     GetAllocator() const       = 0;
};

// The editing side of a text field (cursor, IME); the view only asks it these questions.
class EditorKitBase : public RefCountBase<EditorKitBase, StatRender_Text_Mem>
{
public:
    virtual ~EditorKitBase() {}
    virtual void  AddDrawCursorInfo(TextLayout::Builder& bld) = 0;
    virtual bool  IsReadOnly() const                          = 0;
    virtual bool  HasCompositionString() const                = 0;
    virtual UPInt TextPos2GlyphOffset(UPInt textPos)          = 0;
    virtual UPInt TextPos2GlyphPos(UPInt textPos)             = 0;
    virtual UPInt GlyphPos2TextPos(UPInt glyphPos)            = 0;
    virtual CompositionStringBase* GetCompositionString()     = 0;
};

#define GFX_EDIT_HSCROLL_DELTA PixelsToFixp(60)
#ifndef GFX_ACTIVE_SEL_BKCOLOR
#define GFX_ACTIVE_SEL_BKCOLOR   0xFF000000u
#define GFX_ACTIVE_SEL_TEXTCOLOR 0xFFFFFFFFu
#endif

class DocView : public RefCountBase<DocView, StatRender_Text_Mem>
{
    friend class EditorKitBase;
    friend class CompositionStringBase;
    friend class GFxLineCursor;
    friend class ParagraphFormatter;

public:
    typedef HashIdentityDH<const TextFormat*, Ptr<FontHandle>, StatRender_Text_Mem> FontCache;

    enum CommandType
    {
        Cmd_InsertChar,
        Cmd_InsertPlainText,
        Cmd_InsertStyledText,
        Cmd_DeleteChar,
        Cmd_DeleteText,
        Cmd_ReplaceTextByChar,
        Cmd_ReplaceTextByPlainText,
        Cmd_ReplaceTextByStyledText,
        Cmd_BackspaceChar
    };
    struct InsertCharCommand
    {
        UPInt   PosAt;
        wchar_t CharCode;
        InsertCharCommand(UPInt pos, wchar_t c) : PosAt(pos), CharCode(c) {}
    };
    struct InsertPlainTextCommand
    {
        UPInt          PosAt;
        const wchar_t* pStr;
        UPInt          Length;
        InsertPlainTextCommand(UPInt pos, const wchar_t* pstr, UPInt len) : PosAt(pos), pStr(pstr), Length(len) {}
    };
    struct InsertStyledTextCommand
    {
        UPInt             PosAt;
        const StyledText* pText;
        InsertStyledTextCommand(UPInt pos, const StyledText* pstr) : PosAt(pos), pText(pstr) {}
    };
    struct DeleteCharCommand
    {
        UPInt PosAt;
        DeleteCharCommand(UPInt pos) : PosAt(pos) {}
    };
    struct DeleteTextCommand
    {
        UPInt BeginPos;
        UPInt EndPos;
        DeleteTextCommand(UPInt startPos, UPInt endPos) : BeginPos(startPos), EndPos(endPos) {}
    };
    struct ReplaceTextByCharCommand
    {
        UPInt   BeginPos;
        UPInt   EndPos;
        wchar_t CharCode;
        ReplaceTextByCharCommand(UPInt startPos, UPInt endPos, wchar_t c)
            : BeginPos(startPos), EndPos(endPos), CharCode(c) {}
    };
    struct ReplaceTextByPlainTextCommand
    {
        UPInt          BeginPos;
        UPInt          EndPos;
        const wchar_t* pStr;
        UPInt          Length;
        ReplaceTextByPlainTextCommand(UPInt startPos, UPInt endPos, const wchar_t* pstr, UPInt len)
            : BeginPos(startPos), EndPos(endPos), pStr(pstr), Length(len) {}
    };
    struct ReplaceTextByStyledTextCommand
    {
        UPInt             BeginPos;
        UPInt             EndPos;
        const StyledText* pText;
        ReplaceTextByStyledTextCommand(UPInt startPos, UPInt endPos, const StyledText* pstr)
            : BeginPos(startPos), EndPos(endPos), pText(pstr) {}
    };

    // What a custom word-wrap handler gets to look at (and may change).
    struct LineFormatDesc
    {
        const wchar_t* pParaText;
        UPInt          ParaTextLen;
        float*         pWidths;               // line width before each character, NumCharsInLine + 1 entries
        UPInt          LineStartPos;
        UPInt          NumCharsInLine;
        float          VisibleRectWidth;
        float          CurrentLineWidth;
        float          LineWidthBeforeWordWrap;
        float          DashSymbolWidth;
        enum
        {
            Align_Left    = 0,
            Align_Right   = 1,
            Align_Center  = 2,
            Align_Justify = 3
        };
        UInt8          Alignment;
        UPInt          ProposedWordWrapPoint; // in / out
        bool           UseHyphenation;        // out
    };

    // Notifications from the view and its editor (HandlersMask says which ones the listener wants).
    class DocumentListener : public RefCountBaseNTS<DocumentListener, StatRender_Text_Mem>
    {
    protected:
        enum
        {
            Mask_OnLineFormat       = 0x01,
            Mask_OnScroll           = 0x02,
            Mask_OnMaxScrollChanged = 0x04,
            Mask_OnViewChanged      = 0x08,
            Mask_All                = 0x0f
        };
        UInt8 HandlersMask;     // +0x10 (DoesHandleLineFormat test at 0x142613f37)

    public:
        DocumentListener(UInt8 handlersMask = 0) : HandlersMask(handlersMask) {}

        bool DoesHandleLineFormat() const         { return (HandlersMask & Mask_OnLineFormat) != 0; }
        bool DoesHandleOnScroll() const           { return (HandlersMask & Mask_OnScroll) != 0; }
        bool DoesHandleOnMaxScrollChanged() const { return (HandlersMask & Mask_OnMaxScrollChanged) != 0; }
        bool DoesHandleOnViewChanged() const      { return (HandlersMask & Mask_OnViewChanged) != 0; }

        virtual bool     View_OnLineFormat(DocView&, LineFormatDesc&)         { return false; }
        virtual void     View_OnHScroll(DocView&, unsigned newScroll)         { SF_UNUSED(newScroll); }
        virtual void     View_OnVScroll(DocView&, unsigned newScroll)         { SF_UNUSED(newScroll); }
        virtual void     View_OnMaxScrollChanged(DocView&)                    {}
        virtual void     View_OnChanged(DocView&)                             {}
        virtual unsigned Editor_OnKey(EditorKitBase&, unsigned keyCode)       { return keyCode; }
        virtual wchar_t  Editor_OnCharacter(EditorKitBase&, wchar_t srcChar)  { return srcChar; }
        virtual void     Editor_OnChanged(EditorKitBase&)                     {}
        virtual void     Editor_OnCursorMoved(EditorKitBase&)                 {}
        virtual void     Editor_OnCursorBlink(EditorKitBase&, bool cursorState) { SF_UNUSED(cursorState); }
        virtual String   GetCharacterPath()                                   { return String(); }
    };

    enum ViewAlignment
    {
        Align_Left   = 0,
        Align_Right  = 1,
        Align_Center = 2
    };
    enum ViewVAlignment
    {
        VAlign_None   = 0,
        VAlign_Top    = 1,
        VAlign_Bottom = 2,
        VAlign_Center = 3
    };
    enum ViewTextAutoSize
    {
        TAS_None   = 0,
        TAS_Shrink = 1,
        TAS_Fit    = 2
    };
    enum
    {
        Align_Mask   = 0x3,
        Align_Shift  = 0,
        VAlign_Mask  = 0x3,
        VAlign_Shift = 2,
        TAS_Mask     = 0x3,
        TAS_Shift    = 4
    };

    // Replaces character sequences (emoticons) by images; the list is kept sorted.
    struct ImageSubstitutor : public NewOverrideBase<StatRender_Text_Mem>
    {
        struct Element                  // 0x38 bytes
        {
            wchar_t        SubString[20];
            Ptr<ImageDesc> pImageDesc;  // +0x28
            UByte          SubStringLen;
        };
        ArrayLH<Element> Elements;

        ImageDesc* FindImageDesc(const wchar_t* pstr, UPInt maxlen, UPInt* ptextLen = NULL);
        void       AddImageDesc(const Element& elem);
        void       RemoveImageDesc(ImageDesc*);
    };

    // State carried between FindFont calls over a run of characters.
    struct FindFontInfo
    {
        FontCache*        pFontCache;
        const TextFormat* pCurrentFormat;
        const TextFormat* pPrevFormat;
        Ptr<FontHandle>   pCurrentFont;

        explicit FindFontInfo(FontCache* pfc = NULL) : pFontCache(pfc) { init(); }
        void init() { pCurrentFormat = pPrevFormat = NULL; pCurrentFont = NULL; }
    };

    SF_INLINE Allocator* GetAllocator() { return pDocument->GetAllocator(); }

protected:
    void ClearReformatReq()           { RTFlags &= ~(RTFlags_ReformatReq | RTFlags_CompleteReformatReq); }
    void ClearCompleteReformatReq()   { RTFlags &= ~RTFlags_CompleteReformatReq; }
    bool IsCompleteReformatReq() const { return (RTFlags & RTFlags_CompleteReformatReq) != 0; }

    FontHandle* FindFont(FindFontInfo* pfontInfo, bool quietMode);
    UPInt       GetCursorPosInLineByOffset(unsigned lineIndex, float relativeOffsetX);
    StyledText::NewLinePolicy GetNewLinePolicy() const
    {
        return DoesCompressCRLF() ? StyledText::NLP_CompressCRLF : StyledText::NLP_ReplaceCRLF;
    }

    enum UseType { UseInternally, UseExternally };
    void SetViewRect(const RectF& rect, UseType ut);
    HighlightDesc* GetSelectionHighlighterDesc();
    HighlightDesc* GetSelectionHighlighterDesc() const;

    bool ContainsNonLeftAlignment() const;
    void SetBitmapFontFlag()          { RTFlags |= RTFlags_BitmapFontUsed; }
    void ClearBitmapFontFlag()        { RTFlags &= ~RTFlags_BitmapFontUsed; }
    bool IsBitmapFontFlagSet() const  { return (RTFlags & RTFlags_BitmapFontUsed) != 0; }

public:
    enum ViewNotificationMasks
    {
        ViewNotify_SignificantMask         = 0x100,
        ViewNotify_FormatChange            = 0x1,
        ViewNotify_TextChange              = 0x2,
        ViewNotify_ScrollingParamsChange   = 0x4,
        ViewNotify_SignificantFormatChange = ViewNotify_SignificantMask | ViewNotify_FormatChange,
        ViewNotify_SignificantTextChange   = ViewNotify_SignificantMask | ViewNotify_TextChange
    };

    DocView(Allocator* pallocator, FontManagerBase* pfontMgr, Log* plog);
    ~DocView();

    bool IsReformatReq() const { return (RTFlags & (RTFlags_ReformatReq | RTFlags_CompleteReformatReq)) != 0; }

    MemoryHeap* GetHeap() const  { return pDocument->GetHeap(); }
    UPInt   GetLength() const    { return pDocument->GetLength(); }
    String  GetText() const;
    String& GetText(String*) const;
    String  GetHtml() const;
    String& GetHtml(String*) const;
    StringBuffer& GetHtml(StringBuffer*) const;
    StyledText*      GetStyledText() const  { return pDocument; }
    FontManagerBase* GetFontManager() const { return pFontManager; }

    void SetText(const char* putf8String, UPInt stringSize = SF_MAX_UPINT);
    void SetText(const wchar_t* pstring, UPInt length = SF_MAX_UPINT);

    void ParseHtml(const char* putf8Str, UPInt utf8Len, bool condenseWhite,
                   StyledText::HTMLImageTagInfoArray* pimgInfoArr = NULL, const StyleManagerBase* pstyleMgr = NULL,
                   const TextFormat* defTxtFmt = NULL, const ParagraphFormat* defParaFmt = NULL);
    void ParseHtml(const wchar_t* pwStr, UPInt strLen = SF_MAX_UPINT, bool condenseWhite = false,
                   StyledText::HTMLImageTagInfoArray* pimgInfoArr = NULL, const StyleManagerBase* pstyleMgr = NULL,
                   const TextFormat* defTxtFmt = NULL, const ParagraphFormat* defParaFmt = NULL);
    bool MayHaveUrl() const { return pDocument->MayHaveUrl(); }

    void SetTextFormat(const TextFormat& fmt, UPInt startPos = 0, UPInt endPos = SF_MAX_UPINT);
    void SetParagraphFormat(const ParagraphFormat& fmt, UPInt startPos = 0, UPInt endPos = SF_MAX_UPINT);
    void SetDefaultTextFormat(const TextFormat& defaultTextFmt)           { pDocument->SetDefaultTextFormat(defaultTextFmt); }
    void SetDefaultParagraphFormat(const ParagraphFormat& defaultParaFmt) { pDocument->SetDefaultParagraphFormat(defaultParaFmt); }
    const TextFormat*      GetDefaultTextFormat() const      { return pDocument->GetDefaultTextFormat(); }
    const ParagraphFormat* GetDefaultParagraphFormat() const { return pDocument->GetDefaultParagraphFormat(); }

    void SetDocumentListener(DocumentListener* plistener) { pDocumentListener = plistener; }
    DocumentListener* GetDocumentListener() const        { return pDocumentListener; }

    void  AppendText(const wchar_t* pwStr, UPInt strLen = SF_MAX_UPINT);
    void  AppendText(const char* putf8Str, UPInt utf8Len = SF_MAX_UPINT);
    void  AppendHtml(const wchar_t* pwStr, UPInt strLen = SF_MAX_UPINT, bool condenseWhite = false,
                     StyledText::HTMLImageTagInfoArray* pimgInfoArr = NULL);
    void  AppendHtml(const char* putf8Str, UPInt utf8Len = SF_MAX_UPINT, bool condenseWhite = false,
                     StyledText::HTMLImageTagInfoArray* pimgInfoArr = NULL);
    UPInt InsertText(const wchar_t* pstr, UPInt startPos, UPInt strLen = SF_MAX_UPINT);
    UPInt ReplaceText(const wchar_t* pstr, UPInt startPos, UPInt endPos, UPInt strLen = SF_MAX_UPINT);
    void  RemoveText(UPInt startPos, UPInt endPos)
    {
        UPInt len = (endPos >= startPos) ? endPos - startPos : 0;
        pDocument->Remove(startPos, len);
    }
    UPInt EditCommand(CommandType cmdId, const void* command);

    ImageSubstitutor* CreateImageSubstitutor()
    {
        if (!pImageSubstitutor)
            pImageSubstitutor = new ImageSubstitutor;
        return pImageSubstitutor;
    }
    ImageSubstitutor* GetImageSubstitutor() const { return pImageSubstitutor; }
    void ClearImageSubstitutor() { delete pImageSubstitutor; pImageSubstitutor = NULL; }

    void Close();
    virtual void OnDocumentChanged(unsigned notifyMask);
    virtual void OnDocumentParagraphRemoving(const Paragraph& para);

    void SetReformatReq()         { RTFlags |= RTFlags_ReformatReq; }
    void SetCompleteReformatReq() { RTFlags |= RTFlags_CompleteReformatReq; }
    void Format();
    void CreateVisibleTextLayout(TextLayout::Builder& bld);

    void   SetBorderColor(UInt32 c)     { BorderColor = c; }
    UInt32 GetBorderColor() const       { return BorderColor; }
    void   SetBackgroundColor(UInt32 c) { BackgroundColor = c; }
    UInt32 GetBackgroundColor() const   { return BackgroundColor; }

    void SetAutoSizeX();
    void ClearAutoSizeX()        { Flags &= ~Flags_AutoSizeX; }
    bool IsAutoSizeX() const     { return (Flags & Flags_AutoSizeX) != 0; }
    void SetAutoSizeY();
    void ClearAutoSizeY()        { Flags &= ~Flags_AutoSizeY; }
    bool IsAutoSizeY() const     { return (Flags & Flags_AutoSizeY) != 0; }
    void SetMultiline()          { Flags |= Flags_Multiline; }
    void ClearMultiline()        { Flags &= ~Flags_Multiline; }
    bool IsMultiline() const     { return (Flags & Flags_Multiline) != 0; }
    void SetWordWrap();
    void ClearWordWrap();
    bool IsWordWrap() const      { return (Flags & Flags_WordWrap) != 0; }
    void SetPasswordMode()       { Flags |= Flags_PasswordMode; }
    void ClearPasswordMode()     { Flags &= ~Flags_PasswordMode; }
    bool IsPasswordMode() const  { return (Flags & Flags_PasswordMode) != 0; }
    void SetUseDeviceFont()      { Flags |= Flags_UseDeviceFont; }
    void ClearUseDeviceFont()    { Flags &= ~Flags_UseDeviceFont; }
    bool DoesUseDeviceFont() const { return (Flags & Flags_UseDeviceFont) != 0; }
    void SetAAForReadability()   { Flags |= Flags_AAReadability; }
    void ClearAAForReadability() { Flags &= ~Flags_AAReadability; }
    bool IsAAForReadability() const { return (Flags & Flags_AAReadability) != 0; }
    void SetAutoFit()            { Flags |= Flags_AutoFit; }
    void ClearAutoFit()          { Flags &= ~Flags_AutoFit; }
    bool IsAutoFit() const       { return (Flags & Flags_AutoFit) != 0; }

    const TextFilter& GetFilters() const { return Filter; }
    // (appended for sfr_render_04l) false when nothing changed
    bool SetFilters(const TextFilter& f)
    {
        if (Filter == f)
            return false;
        Filter = f;
        return true;
    }
    void SetDefaultShadow()              { Filter.SetDefaultShadow(); }
    // (appended, sfr35) the shadow's RGB; the alpha stays the filter's shadow alpha.
    void   SetShadowColor(UInt32 c) { Filter.ShadowParams.Colors[0] = Color((UInt32(Filter.ShadowAlpha) << 24) | (c & 0xFFFFFFu)); }
    UInt32 GetShadowColor() const   { return Filter.ShadowParams.Colors[0].ToColor32() & 0xFFFFFFu; }
    // (appended, sfr35) the old style (AS2 shadowStyle) shadow turns the filter shadow off.
    void   DisableSoftShadow()      { Filter.ShadowFlags |= 1; }
    bool  GetFauxBold() const            { return (FlagsEx & FlagsEx_FauxBold) != 0; }
    bool  GetFauxItalic() const          { return (FlagsEx & FlagsEx_FauxItalic) != 0; }
    void  SetFauxBold(bool f)            { if (f) FlagsEx |= FlagsEx_FauxBold; else FlagsEx &= ~FlagsEx_FauxBold; }
    void  SetFauxItalic(bool f)          { if (f) FlagsEx |= FlagsEx_FauxItalic; else FlagsEx &= ~FlagsEx_FauxItalic; }
    void  SetOutline(float v)            { Outline = v; }
    float GetOutline() const             { return Outline; }

    void         SetViewRect(const RectF& rect) { SetViewRect(rect, UseExternally); }
    const RectF& GetViewRect();
    const RectF& GetTextRect() const            { return mLineBuffer.Geom.VisibleRect; }

    bool     SetHScrollOffset(unsigned hscroll);
    bool     SetVScrollOffset(unsigned vscroll);
    unsigned GetHScrollOffset();
    unsigned GetVScrollOffset();
    float    GetTextWidth();
    float    GetTextHeight();
    unsigned GetLinesCount();
    unsigned GetMaxHScroll();
    unsigned GetMaxVScroll();
    void     SetMaxLength(UPInt maxLen) { MaxLength = unsigned(maxLen); }
    UPInt    GetMaxLength() const       { return MaxLength; }
    bool     HasMaxLength() const       { return MaxLength != 0; }
    bool     ForceReformat();

    void SetAlignment(ViewAlignment alignment)
    {
        AlignProps = (UByte)((AlignProps & ~(Align_Mask << Align_Shift)) | ((alignment & Align_Mask) << Align_Shift));
        SetReformatReq();
    }
    ViewAlignment GetAlignment() const { return ViewAlignment((AlignProps >> Align_Shift) & Align_Mask); }
    void SetVAlignment(ViewVAlignment valignment)
    {
        AlignProps = (UByte)((AlignProps & ~(VAlign_Mask << VAlign_Shift)) | ((valignment & VAlign_Mask) << VAlign_Shift));
        SetReformatReq();
    }
    ViewVAlignment GetVAlignment() const { return ViewVAlignment((AlignProps >> VAlign_Shift) & VAlign_Mask); }
    void SetTextAutoSize(ViewTextAutoSize tas)
    {
        AlignProps = (UByte)((AlignProps & ~(TAS_Mask << TAS_Shift)) | ((tas & TAS_Mask) << TAS_Shift));
        SetReformatReq();
    }
    ViewTextAutoSize GetTextAutoSize() const { return ViewTextAutoSize((AlignProps >> TAS_Shift) & TAS_Mask); }

    bool  IsUrlAtPoint(float x, float y, Range* purlPosRange = NULL);
    bool  IsReadOnly() const;
    void  SetFontScaleFactor(float f);
    float GetFontScaleFactor() const { return FixpToPixels((float)FontScaleFactor); }
    bool  HasFontScaleFactor() const { return (RTFlags & RTFlags_HasFontScaleFactor) != 0; }

    UPInt    GetCharIndexAtPoint(float x, float y);
    UPInt    GetCursorPosAtPoint(float x, float y);
    UPInt    GetCursorPosInLine(unsigned lineIndex, float x);
    UPInt    GetFirstCharInParagraph(UPInt indexOfChar);
    unsigned GetLineIndexAtPoint(float x, float y);
    unsigned GetLineIndexOfChar(UPInt indexOfChar);
    UPInt    GetLineOffset(unsigned lineIndex);
    UPInt    GetLineLength(unsigned lineIndex, bool* phasNewLine = NULL);
    const wchar_t* GetLineText(unsigned lineIndex, UPInt* plen);
    SPInt    GetParagraphLength(UPInt charIndex);

    struct LineMetrics      // twips
    {
        unsigned Width, Height;
        unsigned Ascent, Descent;
        int      FirstCharXOff;
        int      Leading;
    };
    bool GetLineMetrics(unsigned lineIndex, LineMetrics* pmetrics);
    bool GetCharBoundaries(RectF* pCharRect, UPInt indexOfChar);
    bool GetExactCharBoundaries(RectF* pCharRect, UPInt indexOfChar);
    unsigned GetBottomVScroll();
    bool     SetBottomVScroll(unsigned newBottomMostLine);

    void           SetEditorKit(EditorKitBase* ek) { pEditorKit = ek; }
    EditorKitBase* GetEditorKit()                  { return pEditorKit; }
    const EditorKitBase* GetEditorKit() const      { return pEditorKit; }
    bool HasEditorKit() const                      { return pEditorKit.GetPtr() != NULL; }
    // text positions as glyph offsets (the editor kit knows where its composition string sits)
    UPInt TextPos2GlyphOffset(UPInt textPos)
    {
        if (HasEditorKit())
            return GetEditorKit()->TextPos2GlyphOffset(textPos);
        return textPos;
    }

    unsigned char NewLineChar() const { return pDocument->NewLineChar(); }
    void SetCompressCRLF()            { RTFlags |= RTFlags_CompressCRLF; }
    void ClearCompressCRLF()          { RTFlags &= ~RTFlags_CompressCRLF; }
    bool DoesCompressCRLF() const     { return (RTFlags & RTFlags_CompressCRLF) != 0; }

    bool AddHighlight(HighlightDesc* pdesc);
    bool RemoveHighlight(int id);
    Highlighter* GetHighlighterManager() const { return pHighlight ? &pHighlight->HighlightManager : NULL; }
    void UpdateHighlight(const HighlightDesc& desc);

    void  SetSelection(UPInt startPos, UPInt endPos, bool highlightSelection = true);
    void  ClearSelection()                { SetSelection(0, 0); }
    UPInt GetBeginSelection() const       { return Alg::PMin(BeginSelection, EndSelection); }
    UPInt GetEndSelection() const         { return Alg::PMax(BeginSelection, EndSelection); }
    void  SetBeginSelection(UPInt begSel) { SetSelection(begSel, EndSelection); }
    void  SetEndSelection(UPInt endSel)   { SetSelection(BeginSelection, endSel); }
    void   SetSelectionTextColor(UInt32 color);
    void   SetSelectionBackgroundColor(UInt32 color);
    UInt32 GetSelectionTextColor() const;
    UInt32 GetSelectionBackgroundColor() const;

    const LineBuffer& GetLineBuffer() const { return mLineBuffer; }
    void     SetDefaultTextAndParaFormat(UPInt cursorPos);
    unsigned GetMaxHScrollValue() const;
    unsigned GetMaxVScrollValue() const          { return MaxVScroll.Value; }
    unsigned GetHScrollOffsetValue() const       { return mLineBuffer.GetHScrollOffset(); }
    unsigned GetVScrollOffsetValue() const       { return mLineBuffer.GetFirstVisibleLineIndex(); }
    unsigned GetVScrollOffsetValueInFixp() const { return mLineBuffer.GetVScrollOffsetInFixp(); }
    UInt16   GetFormatCounter() const            { return FormatCounter; }

    // The document of the view: forwards its change notifications to the view (pDocument +0x48).
    class DocumentText : public StyledText
    {
        DocView* pDocument;

    public:
        DocumentText(DocView* pdoc, Allocator* pallocator) : StyledText(pallocator), pDocument(pdoc) {}

        virtual void OnParagraphRemoving(const Paragraph& para);
        virtual void OnTextInserting(UPInt startPos, UPInt length, const wchar_t* ptxt);
        virtual void OnTextInserting(UPInt startPos, UPInt length, const char* ptxt);
        virtual void OnTextRemoving(UPInt startPos, UPInt length);
    };

    Highlighter* CreateHighlighterManager();

protected:
    Ptr<DocumentText>     pDocument;            // +0x10
    Ptr<FontManagerBase>  pFontManager;         // +0x18
    Ptr<DocumentListener> pDocumentListener;    // +0x20

    // the highlighter with the scroll state it was laid out for (0x48 bytes)
    struct HighlightDescLoc : public NewOverrideBase<StatRender_Text_Mem>
    {
        Highlighter HighlightManager;
        float       HScrollOffset;
        float       VScrollOffset;
        UInt16      FormatCounter;

        HighlightDescLoc() : HScrollOffset(-1), VScrollOffset(-1), FormatCounter(0) {}
        void Invalidate()    { HighlightManager.Invalidate(); }
        void Validate()      { HighlightManager.Validate(); }
        bool IsValid() const { return HighlightManager.IsValid(); }
    }* pHighlight;                              // +0x28

    ImageSubstitutor*           pImageSubstitutor;  // +0x30
    UPInt                       BeginSelection, EndSelection;   // +0x38
    Text::LineBuffer            mLineBuffer;        // +0x50
    __declspec(align(16)) RectF ViewRect;           // +0xb0 the whole view
    unsigned                    TextWidth;          // +0xc0 twips
    unsigned                    TextHeight;         // +0xc4
    unsigned                    MaxLength;          // +0xc8
    CachedPrimValue<unsigned>   MaxVScroll;         // +0xcc
    Ptr<EditorKitBase>          pEditorKit;         // +0xd8
    TextFilter                  Filter;             // +0xe0
    Ptr<Log>                    pLog;               // +0x130
    UInt32                      BorderColor, BackgroundColor;   // +0x138
    UInt16                      FormatCounter;      // +0x140 bumped by every Format
    UInt16                      FontScaleFactor;    // +0x142 twips
    float                       Outline;            // +0x144
    UInt8                       AlignProps;         // +0x148 alignment, vertical alignment, auto size
    enum
    {
        Flags_AutoSizeX     = 0x1,
        Flags_AutoSizeY     = 0x2,
        Flags_Multiline     = 0x4,
        Flags_WordWrap      = 0x8,
        Flags_PasswordMode  = 0x10,
        Flags_UseDeviceFont = 0x20,
        Flags_AAReadability = 0x40,
        Flags_AutoFit       = 0x80
    };
    UInt8                       Flags;              // +0x149
    enum
    {
        FlagsEx_FauxBold   = 0x1,
        FlagsEx_FauxItalic = 0x2
    };
    UInt8                       FlagsEx;            // +0x14a
    enum
    {
        RTFlags_ReformatReq         = 0x1,
        RTFlags_CompleteReformatReq = 0x2,
        RTFlags_HasFontScaleFactor  = 0x4,
        RTFlags_CompressCRLF        = 0x8,
        RTFlags_FontErrorDetected   = 0x10,
        RTFlags_BitmapFontUsed      = 0x20
    };
    UInt8                       RTFlags;            // +0x14b
};

}}} // namespace Scaleform::Render::Text

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::Render::Text::DocView) == 0x150, "DocView size");
static_assert(sizeof(Scaleform::Render::Text::DocView::DocumentText) == 0x50, "DocumentText size");

#endif
