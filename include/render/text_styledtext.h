// Recovered Scaleform 4.1.18 Render Text: StyledText, the formatted text document behind text fields - a list of
// Paragraphs, each a wide-character buffer with its runs of TextFormat (a RangeDataArray) and its ParagraphFormat.
// The last paragraph of a document ends in a terminating null character (with a format of its own); every other
// paragraph ends in the new-line character. Paragraph 0x48 bytes, StyledText 0x48 (vftable 0x143184ca0).
// Bodies: unit sfr_render_01c (Text_StyledText).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TEXT_STYLEDTEXT_H
#define MS2_SF_RENDER_TEXT_STYLEDTEXT_H

#include "ms2/scaleform/kernel/sf_wstring.h"
#include "ms2/scaleform/include/render/text_core.h"

namespace Scaleform { namespace Render { namespace Text {

// A CSS style: a text format and a paragraph format.
struct Style : public NewOverrideBase<StatRender_Text_Mem>
{
    TextFormat      mTextFormat;
    ParagraphFormat mParagraphFormat;

    Style(MemoryHeap* pheap) : mTextFormat(pheap) {}
    void Reset();
};

// Style lookup for HTML parsing (implemented by the GFx style sheet).
class StyleManagerBase
{
public:
    enum KeyType
    {
        CSS_Tag   = 0,
        CSS_Class = 1,
        CSS_None  = 2
    };

    virtual ~StyleManagerBase() {}
    virtual const Style* GetStyle(KeyType type, const String& name) const = 0;
    virtual const Style* GetStyle(KeyType type, const char* name, UPInt len = SF_MAX_UPINT) const = 0;
    virtual const Style* GetStyle(KeyType type, const wchar_t* name, UPInt len = SF_MAX_UPINT) const = 0;
};

#define GFX_NBSP_CHAR_CODE 160

class Paragraph : public NewOverrideBase<StatRender_Text_Mem>
{
    friend class StyledText;
    friend class CompositionString;

    typedef RangeDataArray<Ptr<TextFormat>, ArrayLH<RangeData<Ptr<TextFormat> > > > TextFormatArrayType;
    typedef RangeData<Ptr<TextFormat> >                                             TextFormatRunType;

    // The paragraph's characters. Memory comes from (and goes back to) the document's Allocator, so the buffer
    // has no destructor work: the owner calls Free.
    class TextBuffer
    {
        wchar_t* pText;
        UPInt    Size;
        UPInt    Allocated;

        TextBuffer(const TextBuffer&);

    public:
        TextBuffer() : pText(0), Size(0), Allocated(0) {}
        TextBuffer(const TextBuffer& o, Allocator* pallocator);
        ~TextBuffer();

        wchar_t* ToWStr() const { return pText; }
        UPInt    GetSize() const { return Size; }
        UPInt    GetLength() const;
        const wchar_t* GetCharPtrAt(UPInt pos) const;

        void     SetString(Allocator* pallocator, const char* putf8Str, UPInt utf8length = SF_MAX_UPINT);
        void     SetString(Allocator* pallocator, const wchar_t* pstr, UPInt length = SF_MAX_UPINT);
        wchar_t* CreatePosition(Allocator* pallocator, UPInt pos, UPInt length);
        void     Remove(UPInt pos, UPInt length);
        void     Clear() { Size = 0; }     // keeps the memory
        void     Free(Allocator* pallocator);
        void     StripTrailingNewLines();
        void     StripTrailingNull();
        void     AppendTrailingNull(Allocator* pallocator);

        SPInt StrChr(wchar_t c) { return StrChr(pText, GetLength(), c); }
        static SPInt StrChr(const wchar_t* ptext, UPInt length, wchar_t c);
        static UPInt StrLen(const wchar_t* ptext);
    };

public:
    void        SetStartIndex(UPInt i) { StartIndex = i; }
    TextFormat* GetTextFormatPtr(UPInt pos) const;
    void        SetFormat(const ParagraphFormat* pfmt);
    void        AppendTermNull(Allocator* pallocator, const TextFormat* pdefTextFmt);
    void        RemoveTermNull();
    bool        HasTermNull() const;
    bool        HasNewLine() const;
    void        SetTermNullFormat();
    bool        IsEmpty() const { return GetLength() == 0; }
    void        MarkToReformat() { ++ModCounter; }

    // a run of equally formatted characters (pFormat NULL: unformatted)
    struct StyledTextRun
    {
        const wchar_t*  pText;
        SPInt           Index;
        UPInt           Length;
        Ptr<TextFormat> pFormat;

        StyledTextRun() : pText(0), Index(0), Length(0) {}
        StyledTextRun& Set(const wchar_t* ptext, SPInt index, UPInt len, TextFormat* pfmt)
        {
            pText   = ptext;
            Index   = index;
            Length  = len;
            pFormat = pfmt;
            return *this;
        }
    };

    // Walks the paragraph run by run; the gaps between format runs come out as unformatted runs.
    class FormatRunIterator
    {
        StyledTextRun                      PlaceHolder;
        const TextFormatArrayType*         pFormatInfo;
        TextFormatArrayType::ConstIterator FormatIterator;
        const TextBuffer*                  pText;
        UPInt                              CurTextIndex;

    public:
        FormatRunIterator(const TextFormatArrayType& fmts, const TextBuffer& textHandle);
        FormatRunIterator(const TextFormatArrayType& fmts, const TextBuffer& textHandle, UPInt index);
        FormatRunIterator(const FormatRunIterator& orig);
        FormatRunIterator& operator=(const FormatRunIterator& orig);

        bool IsFinished() const { return CurTextIndex >= pText->GetSize(); }
        const StyledTextRun& operator*();
        const StyledTextRun* operator->() { return &operator*(); }
        void operator++();
        void operator++(int) { operator++(); }
        void SetTextPos(UPInt newTextPos);
    };

    struct CharacterInfo
    {
        Ptr<TextFormat> pFormat;
        UPInt           Index;
        wchar_t         Character;

        CharacterInfo() : pFormat(NULL), Index(0), Character(0) {}
    };

    // Walks the paragraph character by character with each one's format.
    class CharactersIterator
    {
        CharacterInfo                      PlaceHolder;
        const TextFormatArrayType*         pFormatInfo;
        TextFormatArrayType::ConstIterator FormatIterator;
        const TextBuffer*                  pText;
        UPInt                              CurTextIndex;

    public:
        CharactersIterator() : pFormatInfo(NULL), pText(NULL), CurTextIndex(0) {}
        CharactersIterator(const Paragraph* pparagraph);
        CharactersIterator(const Paragraph* pparagraph, UPInt index);

        bool IsFinished() const { return pText == NULL || CurTextIndex >= pText->GetSize(); }
        CharacterInfo&  operator*();
        CharacterInfo*  operator->() { return &operator*(); }
        void operator++();
        void operator++(int) { operator++(); }
        void operator+=(UPInt n);
        const wchar_t* GetRemainingTextPtr(UPInt* plen) const;
        UPInt GetCurTextIndex() const { return CurTextIndex; }
    };

    CharactersIterator GetCharactersIterator() const            { return CharactersIterator(this); }
    CharactersIterator GetCharactersIterator(UPInt index) const { return CharactersIterator(this, index); }

private:
    Paragraph(const Paragraph& o);

public:
    Paragraph(Allocator* ptextAllocator);
    Paragraph(const Paragraph& o, Allocator* ptextAllocator);
    ~Paragraph() {}

    FormatRunIterator GetIterator() const;
    FormatRunIterator GetIteratorAt(UPInt index) const;

    UPInt GetStartIndex() const { return StartIndex; }
    UPInt GetLength() const;
    UPInt GetSize() const       { return Text.GetSize(); }
    UPInt GetNextIndex() const  { return StartIndex + GetLength(); }
    const wchar_t* GetText() const { return Text.ToWStr(); }
    wchar_t*       GetText()       { return Text.ToWStr(); }

    wchar_t* CreatePosition(Allocator* pallocator, UPInt pos, UPInt length = 1);
    void InsertString(Allocator* pallocator, const wchar_t* pstr, UPInt pos, UPInt length, const TextFormat* pnewFmt);
    void InsertString(Allocator* pallocator, const wchar_t* pstr, UPInt pos, UPInt length = SF_MAX_UPINT)
    {
        InsertString(pallocator, pstr, pos, length, NULL);
    }
    void AppendPlainText(Allocator* pallocator, const wchar_t* pstr, UPInt length = SF_MAX_UPINT);
    void AppendPlainText(Allocator* pallocator, const char* putf8str, UPInt utf8StrSize = SF_MAX_UPINT);
    void Remove(UPInt startPos, UPInt endPos = SF_MAX_UPINT);
    void Clear();
    void FreeText(Allocator* pallocator) { Text.Free(pallocator); }
    void SetText(Allocator* pallocator, const wchar_t* pstring, UPInt length = SF_MAX_UPINT);

    void       SetTextFormat(Allocator* pallocator, const TextFormat& fmt, UPInt startPos = 0, UPInt endPos = SF_MAX_UPINT);
    TextFormat GetTextFormat(UPInt startPos, UPInt endPos = SF_MAX_UPINT) const;
    void       ClearTextFormat(UPInt startPos = 0, UPInt endPos = SF_MAX_UPINT);
    void       SetFormat(Allocator* pallocator, const ParagraphFormat& fmt);
    const ParagraphFormat* GetFormat() const { return pFormat.GetPtr(); }

    UInt32 GetId() const         { return UniqueId; }
    UInt16 GetModCounter() const { return ModCounter; }

    void Copy(Allocator* pallocator, const Paragraph& psrcPara, UPInt startSrcIndex, UPInt startDestIndex, UPInt length);
    void Shrink(UPInt delta);

private:
    TextBuffer           Text;          // +0x00
    Ptr<ParagraphFormat> pFormat;       // +0x18
    TextFormatArrayType  FormatInfo;    // +0x20
    UPInt                StartIndex;    // +0x38
    UInt32               UniqueId;      // +0x40
    UInt16               ModCounter;    // +0x44
};

class StyledText : public RefCountBaseNTS<StyledText, StatRender_Text_Mem>
{
    friend class DocView;
    friend class CompositionString;

public:
    // Owning paragraph pointer; copying moves the paragraph (the array relocates its elements by copy).
    class ParagraphPtrWrapper
    {
        mutable Paragraph* pPara;

    public:
        ParagraphPtrWrapper() : pPara(NULL) {}
        ParagraphPtrWrapper(Paragraph* ptr) : pPara(ptr) {}
        ParagraphPtrWrapper(const ParagraphPtrWrapper& ptr) : pPara(ptr.pPara) { ptr.pPara = NULL; }
        ~ParagraphPtrWrapper() { delete pPara; }

        Paragraph&       operator*()        { return *pPara; }
        const Paragraph& operator*() const  { return *pPara; }
        Paragraph*       operator->()       { return pPara; }
        const Paragraph* operator->() const { return pPara; }
        Paragraph*       GetPtr()           { return pPara; }
        const Paragraph* GetPtr() const     { return pPara; }
        operator Paragraph*()               { return pPara; }
        operator const Paragraph*() const   { return pPara; }

        ParagraphPtrWrapper& operator=(const ParagraphPtrWrapper& p)
        {
            if (pPara != p.pPara)
                delete pPara;
            pPara   = p.pPara;
            p.pPara = NULL;
            return *this;
        }
    };

    // An <IMG> tag found while parsing HTML.
    struct HTMLImageTagInfo : public NewOverrideBase<StatRender_Text_Mem>
    {
        Ptr<ImageDesc> pTextImageDesc;
        StringDH       Url;
        StringDH       Id;
        unsigned       Width, Height;   // twips
        int            VSpace, HSpace;  // twips
        unsigned       ParaId;
        enum
        {
            Align_BaseLine,
            Align_Right,
            Align_Left
        };
        UByte Alignment;

        HTMLImageTagInfo(MemoryHeap* pheap)
            : Url(pheap), Id(pheap), Width(0), Height(0), VSpace(0), HSpace(0), ParaId(~0u),
              Alignment(Align_BaseLine)
        {
        }
    };
    typedef ArrayDH<HTMLImageTagInfo> HTMLImageTagInfoArray;

    typedef ArrayLH<ParagraphPtrWrapper>      ParagraphArrayType;
    typedef ParagraphArrayType::Iterator      ParagraphsIterator;
    typedef ParagraphArrayType::ConstIterator ParagraphsConstIterator;

    struct CharacterInfo
    {
        Ptr<TextFormat> pOriginalFormat;
        Paragraph*      pParagraph;
        UPInt           Index;
        wchar_t         Character;

        CharacterInfo() : Index(0), Character(0) {}
    };

    // Walks the whole document character by character.
    class CharactersIterator
    {
        ParagraphsIterator            Paragraphs;
        Paragraph::CharactersIterator Characters;
        Ptr<StyledText>               pText;
        UPInt                         FirstCharInParagraphIndex;
        CharacterInfo                 CharInfoPlaceHolder;

    public:
        CharactersIterator(StyledText* ptext);
        CharactersIterator(StyledText* ptext, int index);

        bool IsFinished() const { return Characters.IsFinished() && Paragraphs.IsFinished(); }
        CharacterInfo& operator*();
        void operator++();
        void operator++(int) { operator++(); }
    };

private:
    // orders paragraphs against a text position: 0 if the paragraph holds it
    struct ParagraphComparator
    {
        static int Compare(const Paragraph* pp1, UPInt index)
        {
            UPInt si1 = pp1->GetStartIndex();
            if (index >= si1 && index < (si1 + pp1->GetSize()))
                return 0;
            return (int)(si1 - index);
        }
        static int Less(const Paragraph* pp1, UPInt index) { return Compare(pp1, index) < 0; }
    };

    void EnsureTermNull();

public:
    StyledText();
    StyledText(Allocator* pallocator);
    ~StyledText() { Clear(); }

    void  Clear();
    UPInt GetLength() const;

    void SetText(const char* putf8String, UPInt stringSize = SF_MAX_UPINT);
    void SetText(const wchar_t* pstring, UPInt length = SF_MAX_UPINT);
    String  GetText() const;
    String& GetText(String*) const;
    void    GetText(WStringBuffer* pBuffer) const;
    void    GetText(WStringBuffer* pBuffer, UPInt startPos, UPInt endPos) const;

    void        CopyStyledText(StyledText* pdest, UPInt startPos = 0, UPInt endPos = SF_MAX_UPINT) const;
    StyledText* CopyStyledText(UPInt startPos = 0, UPInt endPos = SF_MAX_UPINT) const;

    void          SetHtml(const String&);
    void          SetHtml(const wchar_t* pstring, UPInt length = SF_MAX_UPINT);
    String        GetHtml() const;
    String&       GetHtml(String*) const;
    StringBuffer& GetHtml(StringBuffer*) const;

    void GetTextAndParagraphFormat(TextFormat* pdestTextFmt, ParagraphFormat* pdestParaFmt, UPInt startPos,
                                   UPInt endPos = SF_MAX_UPINT);
    bool GetTextAndParagraphFormat(const TextFormat** ppdestTextFmt, const ParagraphFormat** pdestParaFmt, UPInt pos);
    void SetTextFormat(const TextFormat& fmt, UPInt startPos = 0, UPInt endPos = SF_MAX_UPINT);
    void SetParagraphFormat(const ParagraphFormat& fmt, UPInt startPos = 0, UPInt endPos = SF_MAX_UPINT);
    void ClearTextFormat(UPInt startPos = 0, UPInt endPos = SF_MAX_UPINT);

    void SetDefaultTextFormat(const TextFormat* pdefaultTextFmt);
    void SetDefaultTextFormat(const TextFormat& defaultTextFmt);
    void SetDefaultParagraphFormat(const ParagraphFormat* pdefaultParagraphFmt);
    void SetDefaultParagraphFormat(const ParagraphFormat& defaultParagraphFmt);
    const TextFormat*      GetDefaultTextFormat() const      { return pDefaultTextFormat; }
    const ParagraphFormat* GetDefaultParagraphFormat() const { return pDefaultParagraphFormat; }

    const Paragraph* GetParagraph(unsigned paragraphIndex) const
    {
        return (paragraphIndex < GetParagraphsCount()) ? Paragraphs[paragraphIndex].GetPtr() : NULL;
    }
    unsigned GetParagraphsCount() const { return (unsigned)Paragraphs.GetSize(); }

    enum NewLinePolicy
    {
        NLP_CompressCRLF,   // CR LF becomes one new line
        NLP_ReplaceCRLF,    // every CR and every LF becomes a new line
        NLP_IgnoreCRLF      // CR and LF are dropped (single line fields)
    };

    UPInt AppendString(const char* putf8String, UPInt stringSize = SF_MAX_UPINT,
                       NewLinePolicy newLinePolicy = NLP_ReplaceCRLF);
    UPInt AppendString(const char* putf8String, UPInt stringSize, NewLinePolicy newLinePolicy,
                       const TextFormat* pdefTextFmt, const ParagraphFormat* pdefParaFmt);
    UPInt AppendString(const wchar_t* pstr, UPInt length = ~0u, NewLinePolicy newLinePolicy = NLP_ReplaceCRLF);
    UPInt AppendString(const wchar_t* pstr, UPInt length, NewLinePolicy newLinePolicy,
                       const TextFormat* pdefTextFmt, const ParagraphFormat* pdefParaFmt);
    UPInt InsertString(const wchar_t* pstr, UPInt pos, UPInt length = SF_MAX_UPINT,
                       NewLinePolicy newLinePolicy = NLP_ReplaceCRLF);
    UPInt InsertString(const wchar_t* pstr, UPInt pos, UPInt length, NewLinePolicy newLinePolicy,
                       const TextFormat* pdefTextFmt, const ParagraphFormat* pdefParaFmt);
    UPInt InsertStyledText(const StyledText& text, UPInt pos, UPInt length = SF_MAX_UPINT);
    void  Remove(UPInt startPos, UPInt length);

    CharactersIterator GetCharactersIterator() { return CharactersIterator(this); }

    bool          IsNewLine0D() const { return (RTFlags & (RTFlags_NewLine0D)) != 0; }
    unsigned char NewLineChar() const { return IsNewLine0D() ? '\r' : '\n'; }

    ParagraphsIterator GetParagraphByIndex(UPInt index, UPInt* pindexInParagraph = NULL);
    ParagraphsIterator GetParagraphByIndex(UPInt index, UPInt* pindexInParagraph = NULL) const
    {
        return const_cast<StyledText*>(this)->GetParagraphByIndex(index, pindexInParagraph);
    }

protected:
    void RemoveParagraph(ParagraphsIterator& paraIter, Paragraph* ppara);

    MemoryHeap* GetHeap() const
    {
        if (!pTextAllocator)
            return Memory::GetHeapByAddress(this);
        return pTextAllocator->GetHeap();
    }
    // the allocator is created on first use, in the heap that holds the document
    Allocator* GetAllocator() const
    {
        if (!pTextAllocator)
        {
            MemoryHeap* pheap = Memory::GetHeapByAddress(this);
            pTextAllocator = *SF_HEAP_NEW(pheap) Allocator(pheap);
        }
        return pTextAllocator;
    }

    void SetMayHaveUrl()    { RTFlags |= RTFlags_MayHaveUrl; }
    void ClearMayHaveUrl()  { RTFlags &= (~(RTFlags_MayHaveUrl)); }
    bool MayHaveUrl() const { return (RTFlags & (RTFlags_MayHaveUrl)) != 0; }

    ParagraphsIterator GetNearestParagraphByIndex(UPInt index, UPInt* pindexInParagraph = NULL);
    ParagraphsIterator GetParagraphIterator()       { return Paragraphs.Begin(); }
    ParagraphsIterator GetParagraphIterator() const { return const_cast<StyledText*>(this)->Paragraphs.Begin(); }

    Paragraph* AppendNewParagraph(const ParagraphFormat* pdefParaFmt = NULL);
    Paragraph* InsertNewParagraph(ParagraphsIterator& iter, const ParagraphFormat* pdefParaFmt = NULL);
    Paragraph* AppendCopyOfParagraph(const Paragraph& srcPara);
    Paragraph* InsertCopyOfParagraph(ParagraphsIterator& iter, const Paragraph& srcPara);
    Paragraph* GetLastParagraph();
    const Paragraph* GetLastParagraph() const;

    // notifications for the document view (slots 1-6 of the vftable)
    virtual void OnTextInserting(UPInt startPos, UPInt length, const wchar_t* ptxt);
    virtual void OnTextInserting(UPInt startPos, UPInt length, const char* ptxt)
    {
        SF_UNUSED3(startPos, length, ptxt);
    }
    virtual void OnTextRemoving(UPInt startPos, UPInt length);
    virtual void OnTextInserted(UPInt startPos, UPInt length, const wchar_t* ptxt)
    {
        SF_UNUSED3(startPos, length, ptxt);
    }
    virtual void OnParagraphRemoving(const Paragraph& para);
    virtual void OnDocumentChanged() {}

protected:
    mutable Ptr<Allocator> pTextAllocator;          // +0x10
    ParagraphArrayType     Paragraphs;              // +0x18
    Ptr<ParagraphFormat>   pDefaultParagraphFormat; // +0x30
    Ptr<TextFormat>        pDefaultTextFormat;      // +0x38

    enum
    {
        RTFlags_MayHaveUrl = 0x1,
        RTFlags_NewLine0D  = 0x2    // '\r' is the internal new-line character
    };
    UByte RTFlags;                                  // +0x40
};

}}} // namespace Scaleform::Render::Text

#endif
