// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scaleform GFx 4.1.18 Render: Text StyledText - the
// paragraph list of a text document (Paragraph text buffers, their TextFormat runs, the run/character iterators)
// and the document editing operations (append/insert/remove strings, copy styled text, format queries).
// Queue unit sfr_render_01 is split along its original sources (sfr_render_01 Render_Image, 01b Render_Context +
// Renderer2D, 01c Text_StyledText).
// Not yet recovered: GetHtml(StringBuffer*) and the two MsgFormat::FormatD1 instantiations it pulls in (need the
// kernel MsgFormat class).
// MS2-UNIT: sfr_render_01c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142593170-0x14259d950 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include <string.h>
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/include/render/text_styledtext.h"

namespace Scaleform { namespace Render { namespace Text {

// ---------------------------------------------------------------------------------------------------------------
// Allocator: paragraphs live in the document heap

// @0x1425947a0
Paragraph* Allocator::AllocateParagraph()
{
    return SF_HEAP_NEW(pHeap) Paragraph(this);
}

// @0x142594750
Paragraph* Allocator::AllocateParagraph(const Paragraph& srcPara)
{
    return SF_HEAP_NEW(pHeap) Paragraph(srcPara, this);
}

// ---------------------------------------------------------------------------------------------------------------
// Paragraph::TextBuffer

// @0x142593f00
Paragraph::TextBuffer::TextBuffer(const TextBuffer& o, Allocator* pallocator)
{
    pText = pallocator->AllocText(o.Size);
    Allocated = Size = o.Size;
    memcpy(pText, o.pText, o.Size * sizeof(wchar_t));
}

Paragraph::TextBuffer::~TextBuffer()
{
    // the owner has already returned the memory through Free
}

// @0x142596a70
void Paragraph::TextBuffer::Free(Allocator* pallocator)
{
    pallocator->FreeText(pText);
    pText = NULL;
    Size = Allocated = 0;
}

const wchar_t* Paragraph::TextBuffer::GetCharPtrAt(UPInt pos) const
{
    if (pText == NULL || pos >= Size)
        return NULL;
    return pText + pos;
}

// @0x14259ccc0
void Paragraph::TextBuffer::SetString(Allocator* pallocator, const char* putf8Str, UPInt utf8length)
{
    UPInt numChars = (utf8length == SF_MAX_UPINT) ? UTF8Util::GetLength(putf8Str, SFstrlen(putf8Str))
                                                  : utf8length;
    if (Allocated < numChars)
    {
        pText = pallocator->ReallocText(pText, Allocated, numChars);
        Allocated = numChars;
    }
    if (numChars > 0)
        UTF8Util::DecodeString(pText, putf8Str, utf8length);
    Size = numChars;
}

// @0x14259cd80
void Paragraph::TextBuffer::SetString(Allocator* pallocator, const wchar_t* pstr, UPInt length)
{
    if (length == SF_MAX_UPINT)
        length = StrLen(pstr);
    if (Allocated < length)
    {
        pText = pallocator->ReallocText(pText, Allocated, length);
        Allocated = length;
    }
    if (length > 0)
        memcpy(pText, pstr, length * sizeof(wchar_t));
    Size = length;
}

// opens a gap of length characters at pos and returns it
// @0x1425965a0
wchar_t* Paragraph::TextBuffer::CreatePosition(Allocator* pallocator, UPInt pos, UPInt length)
{
    if (Allocated < Size + length)
    {
        pText = pallocator->ReallocText(pText, Allocated, Size + length);
        Allocated = Size + length;
    }
    if (Size - pos > 0)
        memmove(pText + pos + length, pText + pos, (Size - pos) * sizeof(wchar_t));
    Size += length;
    return pText + pos;
}

// @0x14259b800
void Paragraph::TextBuffer::Remove(UPInt pos, UPInt length)
{
    if (pos >= Size)
        return;
    if (pos + length >= Size)
    {
        Size = pos;
    }
    else
    {
        memmove(pText + pos, pText + pos + length, (Size - (pos + length)) * sizeof(wchar_t));
        Size -= length;
    }
}

SPInt Paragraph::TextBuffer::StrChr(const wchar_t* ptext, UPInt length, wchar_t c)
{
    for (UPInt i = 0; i < length; ++i)
    {
        if (ptext[i] == c)
            return (SPInt)i;
    }
    return -1;
}

UPInt Paragraph::TextBuffer::StrLen(const wchar_t* ptext)
{
    UPInt n = 0;
    while (ptext[n] != 0)
        ++n;
    return n;
}

void Paragraph::TextBuffer::StripTrailingNewLines()
{
    int len = int(Size);
    if (len > 0 && pText[len - 1] == 0)
        --len;   // keep the terminating null
    for (int i = len - 1; i >= 0 && (pText[i] == '\n' || pText[i] == '\r'); --i)
    {
        --Size;
        pText[i] = 0;
    }
}

void Paragraph::TextBuffer::StripTrailingNull()
{
    if (Size > 0 && pText[Size - 1] == 0)
        --Size;
}

// @0x1425953b0
void Paragraph::TextBuffer::AppendTrailingNull(Allocator* pallocator)
{
    if (Size > 0 && Size < Allocated)
    {
        pText[Size++] = 0;
    }
    else
    {
        wchar_t* p = CreatePosition(pallocator, Size, 1);
        if (p)
            *p = 0;
    }
}

UPInt Paragraph::TextBuffer::GetLength() const
{
    int len = int(Size);
    if (len > 0 && pText[len - 1] == 0)
        return Size - 1;
    return Size;
}

// ---------------------------------------------------------------------------------------------------------------
// Paragraph

// @0x142593c60
Paragraph::Paragraph(Allocator* ptextAllocator)
    : StartIndex(0), ModCounter(0)
{
    UniqueId = ptextAllocator->AllocateParagraphId();
}

// The copy takes fresh format records from the target allocator, so they end up in the target document's heap.
// @0x142593a60
Paragraph::Paragraph(const Paragraph& o, Allocator* ptextAllocator)
    : Text(o.Text, ptextAllocator), FormatInfo(o.FormatInfo), StartIndex(o.StartIndex), ModCounter(0)
{
    UniqueId = ptextAllocator->AllocateParagraphId();
    pFormat  = *ptextAllocator->AllocateParagraphFormat(*o.pFormat);

    for (TextFormatArrayType::Iterator it = FormatInfo.Begin(); !it.IsFinished(); it++)
    {
        TextFormatRunType& run = *it;
        Ptr<TextFormat> pcopy = *ptextAllocator->AllocateTextFormat(*run.GetData());
        run.SetData(pcopy);
    }
}

// @0x1425953f0
void Paragraph::Clear()
{
    Text.Clear();
    FormatInfo.RemoveAll();
    ++ModCounter;
}

// @0x14259cec0
void Paragraph::SetText(Allocator* pallocator, const wchar_t* pstring, UPInt length)
{
    if (length != SF_MAX_UPINT)
    {
        // an embedded null cuts the string short
        for (SPInt i = (SPInt)length - 1; i >= 0; --i)
        {
            if (pstring[i] == 0)
            {
                length = (UPInt)i;
                break;
            }
        }
    }
    Text.SetString(pallocator, pstring, length);
    ++ModCounter;
}

// Merges fmt into every run of [startPos, endPos).
// @0x14259d050
void Paragraph::SetTextFormat(Allocator* pallocator, const TextFormat& fmt, UPInt startPos, UPInt endPos)
{
    FormatRunIterator it = GetIteratorAt(startPos);
    if (endPos < startPos)
        endPos = startPos;
    SPInt remaining = (endPos == SF_MAX_UPINT) ? SF_MAX_SPINT : (SPInt)(endPos - startPos);
    while (remaining > 0 && !it.IsFinished())
    {
        const StyledTextRun& run = *it;
        const UPInt runIndex = run.Index, runLength = run.Length;
        SPInt from = (startPos > runIndex) ? (SPInt)startPos : (SPInt)runIndex;

        TextFormat merged(pallocator->GetHeap());
        Ptr<TextFormat> pnewFmt;
        if (run.pFormat)
        {
            merged  = run.pFormat->Merge(fmt);
            pnewFmt = *pallocator->AllocateTextFormat(merged);
        }
        else
        {
            pnewFmt = *pallocator->AllocateTextFormat(fmt);
        }

        UPInt len = Alg::PMin(UPInt(runLength - (from - runIndex)), (UPInt)remaining);
        FormatInfo.SetRange(from, len, pnewFmt);
        remaining -= len;
        it.SetTextPos(runIndex + runLength);
    }
    ++ModCounter;
}

// The format common to every run of [startPos, endPos).
// @0x142599920
TextFormat Paragraph::GetTextFormat(UPInt startPos, UPInt endPos) const
{
    FormatRunIterator it = GetIteratorAt(startPos);
    if (endPos < startPos)
        endPos = startPos;
    SPInt remaining = (endPos == SF_MAX_UPINT) ? SF_MAX_SPINT : (SPInt)(endPos - startPos);
    TextFormat result(Memory::GetHeapByAddress(this));
    unsigned n = 0;
    while (remaining > 0 && !it.IsFinished())
    {
        const StyledTextRun& run = *it;
        if (run.pFormat)
        {
            if (n++ == 0)
                result = *run.pFormat;
            else
                result = run.pFormat->Intersection(result);
        }
        remaining -= (run.Length - (startPos - run.Index));
        startPos = run.Index + run.Length;
        ++it;
    }
    return result;
}

// the format record at pos itself (NULL when that position is unformatted)
// @0x142599e90
TextFormat* Paragraph::GetTextFormatPtr(UPInt startPos) const
{
    FormatRunIterator it = GetIteratorAt(startPos);
    TextFormat* pfmt = NULL;
    if (!it.IsFinished())
    {
        const StyledTextRun& run = *it;
        if (run.pFormat)
            pfmt = run.pFormat;
    }
    return pfmt;
}

// @0x142595920
void Paragraph::ClearTextFormat(UPInt startPos, UPInt endPos)
{
    FormatRunIterator it = GetIteratorAt(startPos);
    if (endPos < startPos)
        endPos = startPos;
    SPInt remaining = (endPos == SF_MAX_UPINT) ? SF_MAX_SPINT : (SPInt)(endPos - startPos);
    while (remaining > 0 && !it.IsFinished())
    {
        const StyledTextRun& run = *it;
        const UPInt runIndex = run.Index, runLength = run.Length;
        SPInt from = (startPos > runIndex) ? (SPInt)startPos : (SPInt)runIndex;

        UPInt len = Alg::PMin(UPInt(runLength - (from - runIndex)), (UPInt)remaining);
        FormatInfo.ClearRange(from, len);
        remaining -= len;
        it.SetTextPos(runIndex + runLength);
    }
    ++ModCounter;
}

// @0x14259c4c0
void Paragraph::SetFormat(Allocator* pallocator, const ParagraphFormat& fmt)
{
    Ptr<ParagraphFormat> pnewFmt;
    if (pFormat)
        pnewFmt = *pallocator->AllocateParagraphFormat(pFormat->Merge(fmt));
    else
        pnewFmt = *pallocator->AllocateParagraphFormat(fmt);
    pFormat = pnewFmt;
    ++ModCounter;
}

// @0x14259c580
void Paragraph::SetFormat(const ParagraphFormat* pfmt)
{
    pFormat = const_cast<ParagraphFormat*>(pfmt);
    ++ModCounter;
}

// @0x1425987c0
Paragraph::FormatRunIterator Paragraph::GetIterator() const
{
    return FormatRunIterator(FormatInfo, Text);
}

// @0x1425987f0
Paragraph::FormatRunIterator Paragraph::GetIteratorAt(UPInt index) const
{
    return FormatRunIterator(FormatInfo, Text, index);
}

// @0x142596520
wchar_t* Paragraph::CreatePosition(Allocator* pallocator, UPInt pos, UPInt length)
{
    if (length == 0)
        return NULL;
    wchar_t* p = Text.CreatePosition(pallocator, pos, length);
    FormatInfo.ExpandRange(pos, length);
    ++ModCounter;
    return p;
}

// the terminating null takes the format of the character before it
// @0x14259ce30
void Paragraph::SetTermNullFormat()
{
    if (HasTermNull())
    {
        UPInt len = GetLength();
        FormatInfo.ExpandRange(len, 1);
        FormatInfo.RemoveRange(len + 1, 1);
    }
}

// @0x14259a3e0
void Paragraph::InsertString(Allocator* pallocator, const wchar_t* pstr, UPInt pos, UPInt length,
                             const TextFormat* pnewFmt)
{
    if (length == 0)
        return;
    if (length == SF_MAX_UPINT)
        length = TextBuffer::StrLen(pstr);
    wchar_t* p = CreatePosition(pallocator, pos, length);
    if (p)
    {
        memcpy(p, pstr, length * sizeof(wchar_t));
        if (pnewFmt)
            FormatInfo.SetRange(pos, length, const_cast<TextFormat*>(pnewFmt));
        SetTermNullFormat();
        ++ModCounter;
    }
}

// @0x142594ab0
void Paragraph::AppendPlainText(Allocator* pallocator, const wchar_t* pstr, UPInt length)
{
    if (length == 0)
        return;
    if (length == SF_MAX_UPINT)
        length = TextBuffer::StrLen(pstr);
    wchar_t* p = CreatePosition(pallocator, GetLength(), length);
    if (p)
    {
        memcpy(p, pstr, length * sizeof(wchar_t));
        ++ModCounter;
    }
}

// @0x1425949e0
void Paragraph::AppendPlainText(Allocator* pallocator, const char* putf8str, UPInt utf8StrSize)
{
    if (utf8StrSize == 0)
        return;
    UPInt length;
    if (utf8StrSize == SF_MAX_UPINT)
        length = (UPInt)UTF8Util::GetLength(putf8str);
    else
        length = (UPInt)UTF8Util::GetLength(putf8str, (SPInt)utf8StrSize);
    wchar_t* p = CreatePosition(pallocator, GetLength(), length);
    if (p)
    {
        UTF8Util::DecodeString(p, putf8str, utf8StrSize);
        ++ModCounter;
    }
}

// @0x142595250
void Paragraph::AppendTermNull(Allocator* pallocator, const TextFormat* pdefTextFmt)
{
    if (HasTermNull())
        return;
    UPInt pos = GetLength();
    wchar_t* p = CreatePosition(pallocator, pos, 1);
    if (p)
    {
        *p = 0;
        if (FormatInfo.Count() == 0 && pdefTextFmt)
        {
            Ptr<TextFormat> pfmt = *pallocator->AllocateTextFormat(*pdefTextFmt);
            FormatInfo.SetRange(pos, 1, pfmt);
        }
    }
}

// @0x14259bce0
void Paragraph::RemoveTermNull()
{
    if (HasTermNull())
    {
        FormatInfo.RemoveRange(GetLength(), 1);
        Text.StripTrailingNull();
    }
}

bool Paragraph::HasTermNull() const
{
    UPInt size = Text.GetSize();
    return size > 0 && *Text.GetCharPtrAt(size - 1) == 0;
}

bool Paragraph::HasNewLine() const
{
    UPInt size = Text.GetSize();
    if (size > 0)
    {
        wchar_t c = *Text.GetCharPtrAt(size - 1);
        return c == '\r' || c == '\n';
    }
    return false;
}

// the character count without the terminating null
// @0x142598a10
UPInt Paragraph::GetLength() const
{
    UPInt len = GetSize();
    if (len > 0 && HasTermNull())
        --len;
    return len;
}

// @0x14259b2b0
void Paragraph::Remove(UPInt startPos, UPInt endPos)
{
    UPInt length = (endPos == SF_MAX_UPINT) ? SF_MAX_UPINT : (UPInt)(endPos - startPos);
    if (length == 0)
        return;
    Text.Remove(startPos, length);
    FormatInfo.RemoveRange(startPos, length);
    SetTermNullFormat();
    ++ModCounter;
}

// Copies length characters with their formats from psrcPara (at startSrcIndex) into this paragraph at
// startDestIndex. Format records are re-allocated from pallocator.
// @0x142595dc0
void Paragraph::Copy(Allocator* pallocator, const Paragraph& psrcPara, UPInt startSrcIndex, UPInt startDestIndex,
                     UPInt length)
{
    if (length == 0)
        return;
    InsertString(pallocator, psrcPara.GetText() + startSrcIndex, startDestIndex, length);

    FormatRunIterator it = psrcPara.GetIteratorAt(startSrcIndex);
    UPInt left = length;
    for (; !it.IsFinished() && left > 0; ++it)
    {
        const StyledTextRun& run = *it;
        SPInt offset;
        UPInt len;
        if (run.Index < SPInt(startSrcIndex))
        {
            offset = 0;
            len    = run.Length - (startSrcIndex - run.Index);
        }
        else
        {
            offset = run.Index - startSrcIndex;
            len    = run.Length;
        }
        len = Alg::PMin(len, left);
        if (run.pFormat)
        {
            Ptr<TextFormat> pfmt = *pallocator->AllocateTextFormat(*run.pFormat);
            FormatInfo.SetRange(startDestIndex + offset, len, pfmt);
        }
        left -= len;
    }
    SetTermNullFormat();
    ++ModCounter;
}

// drops the last delta characters
void Paragraph::Shrink(UPInt delta)
{
    UPInt size = Text.GetSize();
    delta = Alg::PMin(delta, size);
    Remove(size - delta, size);
}

// ---------------------------------------------------------------------------------------------------------------
// Paragraph::FormatRunIterator

Paragraph::FormatRunIterator::FormatRunIterator(const TextFormatArrayType& fmts, const TextBuffer& textHandle)
    : pFormatInfo(&fmts), FormatIterator(fmts.Begin()), pText(&textHandle), CurTextIndex(0)
{
}

// starts at the run holding index (or at the gap before the next run)
// @0x142593970
Paragraph::FormatRunIterator::FormatRunIterator(const TextFormatArrayType& fmts, const TextBuffer& textHandle,
                                                UPInt index)
    : pFormatInfo(&fmts), FormatIterator(pFormatInfo->GetIteratorByNearestIndex(index)), pText(&textHandle),
      CurTextIndex(0)
{
    if (FormatIterator.IsFinished())
        return;
    if (FormatIterator->Contains((SPInt)index))
    {
        CurTextIndex = (UPInt)FormatIterator->Index;
    }
    else if ((SPInt)index > FormatIterator->Index)
    {
        CurTextIndex = (UPInt)FormatIterator->Index;
        CurTextIndex += FormatIterator->Length;
        ++FormatIterator;
    }
}

Paragraph::FormatRunIterator::FormatRunIterator(const FormatRunIterator& orig)
    : pFormatInfo(orig.pFormatInfo), FormatIterator(orig.FormatIterator), pText(orig.pText),
      CurTextIndex(orig.CurTextIndex)
{
}

Paragraph::FormatRunIterator& Paragraph::FormatRunIterator::operator=(const FormatRunIterator& orig)
{
    FormatIterator = orig.FormatIterator;
    pFormatInfo    = orig.pFormatInfo;
    pText          = orig.pText;
    CurTextIndex   = orig.CurTextIndex;
    return *this;
}

// @0x1425942d0
const Paragraph::StyledTextRun& Paragraph::FormatRunIterator::operator*()
{
    if (!FormatIterator.IsFinished())
    {
        const TextFormatRunType& range = *FormatIterator;
        if (CurTextIndex < (UPInt)range.Index)
        {
            // the unformatted gap up to the next run
            return PlaceHolder.Set(pText->ToWStr() + CurTextIndex, CurTextIndex, range.Index - CurTextIndex, NULL);
        }
        return PlaceHolder.Set(pText->ToWStr() + range.Index, range.Index, range.Length, range.GetData());
    }
    return PlaceHolder.Set(pText->ToWStr() + CurTextIndex, CurTextIndex, pText->GetSize() - CurTextIndex, NULL);
}

// @0x142594500
void Paragraph::FormatRunIterator::operator++()
{
    if (!FormatIterator.IsFinished())
    {
        const TextFormatRunType& range = *FormatIterator;
        if (CurTextIndex < UPInt(range.Index))
        {
            CurTextIndex = range.Index;   // the gap ends where the run starts
        }
        else
        {
            CurTextIndex += range.Length;
            ++FormatIterator;
        }
    }
    else
        CurTextIndex = pText->GetSize();
}

// @0x14259d7c0
void Paragraph::FormatRunIterator::SetTextPos(UPInt newTextPos)
{
    while (!IsFinished())
    {
        const StyledTextRun& run = *(*this);
        if (run.Index >= (SPInt)newTextPos)
            break;
        operator++();
    }
}

// ---------------------------------------------------------------------------------------------------------------
// Paragraph::CharactersIterator

Paragraph::CharactersIterator::CharactersIterator(const Paragraph* pparagraph)
    : pFormatInfo(&pparagraph->FormatInfo), FormatIterator(pFormatInfo->Begin()), pText(&pparagraph->Text),
      CurTextIndex(0)
{
}

// @0x1425934b0
Paragraph::CharactersIterator::CharactersIterator(const Paragraph* pparagraph, UPInt index)
    : pFormatInfo(&pparagraph->FormatInfo), FormatIterator(pFormatInfo->GetIteratorByNearestIndex(index)),
      pText(&pparagraph->Text), CurTextIndex(index)
{
    if (!FormatIterator.IsFinished())
    {
        if (!FormatIterator->Contains(index) && (int)index > FormatIterator->Index)
            ++FormatIterator;
    }
}

// @0x142594110
Paragraph::CharacterInfo& Paragraph::CharactersIterator::operator*()
{
    if (!IsFinished())
    {
        PlaceHolder.Character = *(pText->ToWStr() + CurTextIndex);
        PlaceHolder.Index     = CurTextIndex;
        if (!FormatIterator.IsFinished())
        {
            const TextFormatRunType& range = *FormatIterator;
            if (CurTextIndex < (UPInt)range.Index)
                PlaceHolder.pFormat = NULL;   // in a gap before the run
            else
                PlaceHolder.pFormat = range.GetData();
        }
        else
            PlaceHolder.pFormat = NULL;
    }
    else
    {
        PlaceHolder.Character = 0;
        PlaceHolder.Index     = CurTextIndex;
        PlaceHolder.pFormat   = NULL;
    }
    return PlaceHolder;
}

// @0x1425943a0
void Paragraph::CharactersIterator::operator++()
{
    if (IsFinished())
    {
        CurTextIndex = pText->GetSize();
        return;
    }
    ++CurTextIndex;
    if (!FormatIterator.IsFinished())
    {
        const TextFormatRunType& range = *FormatIterator;
        if (CurTextIndex >= UPInt(range.NextIndex()))
            ++FormatIterator;
    }
}

// @0x142594570
void Paragraph::CharactersIterator::operator+=(UPInt n)
{
    for (UPInt i = 0; i < n; ++i)
        operator++();
}

// @0x142598cf0
const wchar_t* Paragraph::CharactersIterator::GetRemainingTextPtr(UPInt* plen) const
{
    if (!IsFinished())
    {
        if (plen)
            *plen = pText->GetSize() - CurTextIndex;
        return pText->ToWStr() + CurTextIndex;
    }
    *plen = 0;
    return NULL;
}

// ---------------------------------------------------------------------------------------------------------------
// StyledText: construction and paragraph list

// a standalone document: its default formats come from the heap the document lives in
// @0x142593da0
StyledText::StyledText()
    : Paragraphs(), RTFlags(0)
{
    MemoryHeap* pheap       = Memory::GetHeapByAddress(this);
    pDefaultParagraphFormat = *SF_HEAP_NEW(pheap) ParagraphFormat;
    pDefaultTextFormat      = *SF_HEAP_NEW(pheap) TextFormat(pheap);
}

// @0x142593ca0
StyledText::StyledText(Allocator* pallocator)
    : pTextAllocator(pallocator), Paragraphs(), RTFlags(0)
{
    pDefaultParagraphFormat = *pallocator->AllocateParagraphFormat(ParagraphFormat());
    pDefaultTextFormat      = *pallocator->AllocateDefaultTextFormat();
}

// @0x142594900
Paragraph* StyledText::AppendNewParagraph(const ParagraphFormat* pdefParaFmt)
{
    UPInt count = Paragraphs.GetSize();
    UPInt startPos = 0;
    if (count > 0)
    {
        Paragraph* plast = Paragraphs[count - 1];
        startPos = plast->GetStartIndex() + plast->GetLength();
    }

    Paragraphs.PushBack(GetAllocator()->AllocateParagraph());

    count = Paragraphs.GetSize();
    Paragraph* ppara = Paragraphs[count - 1];
    ppara->SetFormat(pTextAllocator, (pdefParaFmt == NULL) ? *pDefaultParagraphFormat : *pdefParaFmt);
    ppara->SetStartIndex(startPos);
    return ppara;
}

// @0x142594810
Paragraph* StyledText::AppendCopyOfParagraph(const Paragraph& srcPara)
{
    UPInt count = Paragraphs.GetSize();
    UPInt startPos = 0;
    if (count > 0)
    {
        Paragraph* plast = Paragraphs[count - 1];
        startPos = plast->GetStartIndex() + plast->GetLength();
    }

    Paragraphs.PushBack(GetAllocator()->AllocateParagraph(srcPara));

    count = Paragraphs.GetSize();
    Paragraph* ppara = Paragraphs[count - 1];
    ppara->SetStartIndex(startPos);
    return ppara;
}

// @0x14259a280
Paragraph* StyledText::InsertNewParagraph(ParagraphsIterator& iter, const ParagraphFormat* pdefParaFmt)
{
    if (iter.IsFinished())
        return AppendNewParagraph(pdefParaFmt);

    UPInt index = UPInt(iter.GetIndex());
    UPInt startPos = 0;
    if (index > 0)
    {
        Paragraph* pprev = Paragraphs[index - 1];
        startPos = pprev->GetStartIndex() + pprev->GetLength();
    }

    Paragraphs.InsertAt(index, GetAllocator()->AllocateParagraph());

    Paragraph* ppara = Paragraphs[index];
    ppara->SetFormat(pTextAllocator, (pdefParaFmt == NULL) ? *pDefaultParagraphFormat : *pdefParaFmt);
    ppara->SetStartIndex(startPos);
    return ppara;
}

// @0x14259a130
Paragraph* StyledText::InsertCopyOfParagraph(ParagraphsIterator& iter, const Paragraph& srcPara)
{
    if (iter.IsFinished())
        return AppendCopyOfParagraph(srcPara);

    UPInt index = UPInt(iter.GetIndex());
    UPInt startPos = 0;
    if (index > 0)
    {
        Paragraph* pprev = Paragraphs[index - 1];
        startPos = pprev->GetStartIndex() + pprev->GetLength();
    }

    Paragraphs.InsertAt(index, GetAllocator()->AllocateParagraph(srcPara));

    Paragraph* ppara = Paragraphs[index];
    ppara->SetStartIndex(startPos);
    return ppara;
}

// @0x1425989b0
Paragraph* StyledText::GetLastParagraph()
{
    ParagraphsIterator it = Paragraphs.Last();
    if (!it.IsFinished())
        return it->GetPtr();
    return NULL;
}

const Paragraph* StyledText::GetLastParagraph() const
{
    ParagraphsConstIterator it = Paragraphs.Last();
    if (!it.IsFinished())
        return it->GetPtr();
    return NULL;
}

// ---------------------------------------------------------------------------------------------------------------
// StyledText: appending text

// @0x142594b90
UPInt StyledText::AppendString(const char* putf8String, UPInt stringSize, NewLinePolicy newLinePolicy)
{
    return AppendString(putf8String, stringSize, newLinePolicy, GetDefaultTextFormat(), GetDefaultParagraphFormat());
}

// Appends UTF-8 text: the first line continues the last paragraph, every new-line character starts a new one.
// @0x142594bb0
UPInt StyledText::AppendString(const char* putf8String, UPInt stringSize, NewLinePolicy newLinePolicy,
                               const TextFormat* pdefTextFmt, const ParagraphFormat* pdefParaFmt)
{
    const char* pcur = putf8String;
    if (stringSize == SF_MAX_UPINT)
        stringSize = SFstrlen(putf8String);
    const char* pend = pcur + stringSize;

    UInt32 ch = 0;
    UPInt  appended = 0;
    UPInt  textPos;
    Paragraph* ppara = GetLastParagraph();
    if (!ppara)
        textPos = 0;
    else
        textPos = ppara->GetStartIndex();

    OnTextInserting(textPos, stringSize, putf8String);

    unsigned line = 0;
    do
    {
        UPInt posInPara;
        UPInt paraStart = textPos;
        if (line++ > 0 || ppara == NULL)
        {
            ppara = AppendNewParagraph(pdefParaFmt);
            posInPara = 0;
            ppara->SetStartIndex(paraStart);
        }
        else
        {
            ppara->RemoveTermNull();
            posInPara = ppara->GetLength();
        }

        // measure the line (in characters) up to and including its new-line
        UPInt lineLen = 0;
        const char* pscan = pcur;
        UInt32 prevCh = ch;
        for (ch = ~0u; pscan < pend && ch != 0;)
        {
            UInt32 next = UTF8Util::DecodeNextChar(&pscan);
            if (newLinePolicy == NLP_CompressCRLF && prevCh == '\r' && lineLen == 0)
            {
                prevCh = ~0u;
                if (next == '\n')
                {
                    ++pcur;     // the LF of a CR LF pair
                    continue;
                }
            }
            ch = next;
            if (ch == '\n' || ch == '\r')
                break;
            ++lineLen;
        }
        if (ch == '\n' || ch == '\r')
            ++lineLen;

        if (lineLen > 0)
        {
            wchar_t* pdst = ppara->CreatePosition(pTextAllocator, posInPara, lineLen);
            pscan = pcur;
            for (ch = ~0u; pscan < pend && ch != 0;)
            {
                ch = UTF8Util::DecodeNextChar(&pscan);
                if (ch == '\r' || ch == '\n')
                    ch = NewLineChar();
                *pdst++ = (wchar_t)ch;
                if (ch == NewLineChar())
                    break;
            }
            ppara->SetTextFormat(pTextAllocator, *pdefTextFmt, posInPara, SF_MAX_UPINT);
            pcur = pscan;
            textPos  += lineLen + posInPara;
            appended += lineLen;
        }
    } while (pcur < pend && ch != 0);

    // text ending in a new-line leaves an empty last paragraph
    if (ch == NewLineChar())
        ppara = AppendNewParagraph(pdefParaFmt);
    ppara->AppendTermNull(pTextAllocator, pdefTextFmt);

    if (pdefTextFmt->IsUrlSet())
        SetMayHaveUrl();
    return appended;
}

// @0x142594ed0
UPInt StyledText::AppendString(const wchar_t* pstr, UPInt length, NewLinePolicy newLinePolicy)
{
    return AppendString(pstr, length, newLinePolicy, GetDefaultTextFormat(), GetDefaultParagraphFormat());
}

// @0x142594ef0
UPInt StyledText::AppendString(const wchar_t* pstr, UPInt length, NewLinePolicy newLinePolicy,
                               const TextFormat* pdefTextFmt, const ParagraphFormat* pdefParaFmt)
{
    UInt32 ch = 0;
    if (length == SF_MAX_UPINT)
        length = SFwcslen(pstr);
    const wchar_t* pend = pstr + length;

    UPInt textPos;
    Paragraph* ppara = GetLastParagraph();
    if (!ppara)
        textPos = 0;
    else
        textPos = ppara->GetStartIndex();

    OnTextInserting(textPos, length, pstr);

    UPInt appended = 0;
    unsigned line = 0;
    do
    {
        UPInt posInPara;
        UPInt paraStart = textPos;
        if (line++ > 0 || ppara == NULL)
        {
            ppara = AppendNewParagraph(pdefParaFmt);
            posInPara = 0;
            ppara->SetStartIndex(paraStart);
        }
        else
        {
            ppara->RemoveTermNull();
            posInPara = ppara->GetLength();
            if (posInPara == 0 && pdefParaFmt)
                ppara->SetFormat(pTextAllocator, *pdefParaFmt);   // still empty: take the new format
        }

        UPInt lineLen = 0;
        if (newLinePolicy == NLP_CompressCRLF && ch == '\r' && pstr[0] == '\n')
        {
            // the LF of a CR LF pair
            ++pstr;
            --length;
            if (length == 0)
                break;
        }
        for (; lineLen < length; ++lineLen)
        {
            ch = pstr[lineLen];
            if (ch == '\n' || ch == '\r' || ch == 0)
                break;
        }
        if (ch == '\n' || ch == '\r')
            ++lineLen;

        wchar_t* pdst = ppara->CreatePosition(pTextAllocator, posInPara, lineLen);
        memcpy(pdst, pstr, lineLen * sizeof(wchar_t));
        pstr   += lineLen;
        length -= lineLen;

        if ((ch == '\n' || ch == '\r') && ch != NewLineChar())
        {
            // store the document's own new-line character
            UPInt len = ppara->GetLength();
            if (len > 0)
            {
                wchar_t* ptxt = ppara->GetText();
                ptxt[len - 1] = NewLineChar();
            }
            ch = NewLineChar();
        }
        ppara->SetTextFormat(pTextAllocator, *pdefTextFmt, posInPara, SF_MAX_UPINT);
        textPos  += lineLen + posInPara;
        appended += lineLen;
    } while (pstr < pend && ch != 0);

    if (ch == NewLineChar())
        ppara = AppendNewParagraph(pdefParaFmt);
    ppara->AppendTermNull(pTextAllocator, pdefTextFmt);

    if (pdefTextFmt->IsUrlSet())
        SetMayHaveUrl();
    return appended;
}

// @0x14259cf90
void StyledText::SetText(const char* putf8String, UPInt stringSize)
{
    Clear();
    AppendString(putf8String, stringSize);
}

// @0x14259cff0
void StyledText::SetText(const wchar_t* pstr, UPInt length)
{
    Clear();
    AppendString(pstr, length);
}

// ---------------------------------------------------------------------------------------------------------------
// StyledText: position lookup

// the paragraph holding index (finished iterator if none)
// @0x142598be0
StyledText::ParagraphsIterator StyledText::GetParagraphByIndex(UPInt index, UPInt* pindexInParagraph)
{
    UPInt i = Alg::LowerBound(Paragraphs, index, ParagraphComparator::Less);
    if (i < Paragraphs.GetSize() && ParagraphComparator::Compare(Paragraphs[i], index) == 0)
    {
        ParagraphsIterator it(Paragraphs.Begin() + (int)i);
        if (pindexInParagraph)
            *pindexInParagraph = index - it->GetPtr()->GetStartIndex();
        return it;
    }
    return ParagraphsIterator();
}

// like GetParagraphByIndex, but a position past the end maps to the last paragraph
// @0x142598af0
StyledText::ParagraphsIterator StyledText::GetNearestParagraphByIndex(UPInt index, UPInt* pindexInParagraph)
{
    if (Paragraphs.GetSize() > 0)
    {
        UPInt i = Alg::LowerBound(Paragraphs, index, ParagraphComparator::Less);
        if (i == Paragraphs.GetSize())
            --i;
        ParagraphsIterator it(Paragraphs.Begin() + (int)i);
        if (pindexInParagraph)
            *pindexInParagraph = index - (*it)->GetStartIndex();
        return it;
    }
    return ParagraphsIterator();
}

// @0x1425967b0
void StyledText::EnsureTermNull()
{
    Paragraph* ppara = GetLastParagraph();
    if (!ppara)
        ppara = AppendNewParagraph();
    if (ppara && !ppara->HasNewLine())
        ppara->AppendTermNull(pTextAllocator, pDefaultTextFormat);
}

// ---------------------------------------------------------------------------------------------------------------
// StyledText: formats

// @0x14259d5d0
void StyledText::SetTextFormat(const TextFormat& fmt, UPInt startPos, UPInt endPos)
{
    UPInt from, to;
    ParagraphsIterator it = GetParagraphByIndex(startPos, &from);
    UPInt left = endPos - startPos;
    while (!it.IsFinished())
    {
        Paragraph* ppara = *it;
        UPInt paraLen = ppara->GetLength();
        if (from + left > paraLen)
            to = from + paraLen - from;
        else
            to = from + left;

        if (to == paraLen && ppara->HasTermNull())
        {
            // the terminating null takes the format too
            ++to;
            if (left != SF_MAX_UPINT)
                ++left;
        }

        ppara->SetTextFormat(pTextAllocator, fmt, from, to);

        left -= (to - from);
        from = 0;
        ++it;
    }
    if (fmt.IsUrlSet())
        SetMayHaveUrl();
}

// the paragraph format goes to every paragraph that starts inside [startPos, endPos)
// @0x14259c5e0
void StyledText::SetParagraphFormat(const ParagraphFormat& fmt, UPInt startPos, UPInt endPos)
{
    UPInt from, to;
    ParagraphsIterator it = GetParagraphByIndex(startPos, &from);
    UPInt left = endPos - startPos;
    while (!it.IsFinished())
    {
        Paragraph* ppara = *it;
        if (from == 0)
            ppara->SetFormat(pTextAllocator, fmt);
        if (left == 0)
            break;
        UPInt paraLen = ppara->GetLength();
        if (left > paraLen)
            to = from + paraLen - from;
        else
            to = from + left;
        left -= (to - from);
        from = 0;
        ++it;
    }
}

// @0x142595c10
void StyledText::ClearTextFormat(UPInt startPos, UPInt endPos)
{
    UPInt from, to;
    ParagraphsIterator it = GetParagraphByIndex(startPos, &from);
    UPInt left = endPos - startPos;
    while (!it.IsFinished())
    {
        Paragraph* ppara = *it;
        UPInt paraLen = ppara->GetLength();
        if (from + left > paraLen)
            to = from + paraLen - from;
        else
            to = from + left;

        if (to == paraLen && ppara->HasTermNull())
        {
            ++to;
            if (left != SF_MAX_UPINT)
                ++left;
        }

        ppara->ClearTextFormat(from, to);

        left -= (to - from);
        from = 0;
        ++it;
    }
}

// The text and paragraph formats common to the whole of [startPos, endPos).
// @0x1425990d0
void StyledText::GetTextAndParagraphFormat(TextFormat* pdestTextFmt, ParagraphFormat* pdestParaFmt, UPInt startPos,
                                           UPInt endPos)
{
    UPInt from;
    UPInt left = endPos - startPos;

    ParagraphsIterator it = GetParagraphByIndex(startPos, &from);
    TextFormat      textFmt(Memory::GetHeapByAddress(this));
    ParagraphFormat paraFmt;

    int nText = 0, nPara = 0;
    while (left > 0 && !it.IsFinished())
    {
        Paragraph* ppara = *it;
        UPInt len = Alg::PMin(left, ppara->GetLength());
        if (len == 0)
            break;   // only the last paragraph can be empty
        if (nText++ == 0)
            textFmt = ppara->GetTextFormat(from, from + len);
        else
            textFmt = ppara->GetTextFormat(from, from + len).Intersection(textFmt);
        if (from == 0)
        {
            const ParagraphFormat* ppfmt = ppara->GetFormat();
            if (ppfmt)
            {
                if (nPara++ == 0)
                    paraFmt = *ppfmt;
                else
                    paraFmt = ppfmt->Intersection(paraFmt);
            }
        }
        left -= len;
        ++it;
    }
    if (pdestTextFmt)
        *pdestTextFmt = textFmt;
    if (pdestParaFmt)
        *pdestParaFmt = paraFmt;
}

// The format records at pos (the defaults where there are none); false when pos is outside the text.
// @0x1425996b0
bool StyledText::GetTextAndParagraphFormat(const TextFormat** ppdestTextFmt, const ParagraphFormat** ppdestParaFmt,
                                           UPInt pos)
{
    UPInt indexInPara;
    ParagraphsIterator it = GetParagraphByIndex(pos, &indexInPara);
    const ParagraphFormat* pparaFmt = NULL;
    const TextFormat*      ptextFmt = NULL;
    bool found = false;
    if (!it.IsFinished())
    {
        Paragraph* ppara = *it;
        ptextFmt = ppara->GetTextFormatPtr(indexInPara);
        pparaFmt = ppara->GetFormat();
        found = true;
    }
    if (ptextFmt == NULL)
        ptextFmt = pDefaultTextFormat;
    if (pparaFmt == NULL)
        pparaFmt = pDefaultParagraphFormat;
    if (ppdestTextFmt)
        *ppdestTextFmt = ptextFmt;
    if (ppdestParaFmt)
        *ppdestParaFmt = pparaFmt;
    return found;
}

// the default text format never carries an image
// @0x14259c250
void StyledText::SetDefaultTextFormat(const TextFormat& defaultTextFmt)
{
    if (defaultTextFmt.GetImageDesc())
    {
        TextFormat noImage = defaultTextFmt;
        noImage.SetImageDesc(NULL);
        pDefaultTextFormat = *GetAllocator()->AllocateTextFormat(noImage);
    }
    else
    {
        pDefaultTextFormat = *GetAllocator()->AllocateTextFormat(defaultTextFmt);
    }
}

// @0x14259c170
void StyledText::SetDefaultParagraphFormat(const ParagraphFormat& defaultParagraphFmt)
{
    pDefaultParagraphFormat = *GetAllocator()->AllocateParagraphFormat(defaultParagraphFmt);
}

// @0x14259c440
void StyledText::SetDefaultTextFormat(const TextFormat* pdefaultTextFmt)
{
    if (pdefaultTextFmt->GetImageDesc())
        SetDefaultTextFormat(*pdefaultTextFmt);
    else
        pDefaultTextFormat = const_cast<TextFormat*>(pdefaultTextFmt);
}

// @0x14259c1e0
void StyledText::SetDefaultParagraphFormat(const ParagraphFormat* pdefaultParagraphFmt)
{
    pDefaultParagraphFormat = const_cast<ParagraphFormat*>(pdefaultParagraphFmt);
}

// ---------------------------------------------------------------------------------------------------------------
// StyledText: reading the text

// @0x142596bc0
String StyledText::GetHtml() const
{
    StringBuffer html;
    return String(GetHtml(&html));
}

// @0x142596c20
String& StyledText::GetHtml(String* retStr) const
{
    StringBuffer html;
    (*retStr) = GetHtml(&html);
    return *retStr;
}

// @0x142598a50
UPInt StyledText::GetLength() const
{
    UPInt length = 0;
    for (ParagraphsIterator it = GetParagraphIterator(); !it.IsFinished(); ++it)
    {
        Paragraph* ppara = *it;
        length += ppara->GetLength();
    }
    return length;
}

// @0x142598d30
String StyledText::GetText() const
{
    String text;
    GetText(&text);
    return text;
}

// @0x142598dd0
String& StyledText::GetText(String* retStr) const
{
    (*retStr) = "";
    for (ParagraphsIterator it = GetParagraphIterator(); !it.IsFinished(); ++it)
    {
        Paragraph* ppara = *it;
        const wchar_t* ptxt = ppara->GetText();
        retStr->AppendString(ptxt, ppara->GetLength());
    }
    return *retStr;
}

// @0x142598e70
void StyledText::GetText(WStringBuffer* pBuffer) const
{
    pBuffer->Resize(GetLength() + 1);

    ParagraphsIterator it = GetParagraphIterator();
    UPInt filled = 0;
    for (; !it.IsFinished(); ++it)
    {
        Paragraph* ppara = *it;
        const wchar_t* ptxt = ppara->GetText();
        UPInt len = ppara->GetLength();
        memcpy(pBuffer->GetBuffer() + filled, ptxt, len * sizeof(wchar_t));
        filled += len;
    }
    pBuffer->GetBuffer()[filled] = 0;
}

// @0x142598f40
void StyledText::GetText(WStringBuffer* pBuffer, UPInt startPos, UPInt endPos) const
{
    if (endPos == SF_MAX_UPINT)
        endPos = GetLength();
    UPInt len = endPos - startPos;

    pBuffer->Resize(len + 1);
    UPInt from = 0, left = len;
    ParagraphsIterator it = GetParagraphByIndex(startPos, &from);
    UPInt filled = 0;
    for (; !it.IsFinished() && left > 0; ++it)
    {
        Paragraph* ppara = *it;
        UPInt n = ppara->GetLength() - from;
        if (n > left)
            n = left;
        const wchar_t* ptxt = ppara->GetText();
        memcpy(pBuffer->GetBuffer() + filled, ptxt + from, n * sizeof(wchar_t));
        filled += n;
        from = 0;
        left -= n;
    }
    pBuffer->GetBuffer()[filled] = 0;
}

// ---------------------------------------------------------------------------------------------------------------
// StyledText: copying and editing

// @0x1425960e0
StyledText* StyledText::CopyStyledText(UPInt startPos, UPInt endPos) const
{
    Allocator*  pallocator = GetAllocator();
    StyledText* pcopy      = SF_HEAP_NEW(pallocator->GetHeap()) StyledText(pallocator);
    CopyStyledText(pcopy, startPos, endPos);
    return pcopy;
}

// @0x142596230
void StyledText::CopyStyledText(StyledText* pdest, UPInt startPos, UPInt endPos) const
{
    if (endPos == SF_MAX_UPINT)
        endPos = GetLength();
    UPInt len = endPos - startPos;
    UPInt from = 0, left = len;
    pdest->Clear();
    pdest->OnTextInserting(startPos, len, "");
    ParagraphsIterator it = GetParagraphByIndex(startPos, &from);
    if (!it.IsFinished())
    {
        // a partial first paragraph is copied piecewise, whole paragraphs as they are
        if (from != 0)
        {
            Paragraph* psrc = *it;
            Paragraph* pdst = pdest->AppendNewParagraph(psrc->GetFormat());
            UPInt n = psrc->GetLength() - from;
            n = Alg::PMin(n, len);
            pdst->Copy(pdest->GetAllocator(), *psrc, from, 0, n);
            left -= n;
            ++it;
        }
        for (; !it.IsFinished() && left > 0; ++it)
        {
            Paragraph* ppara = *it;
            UPInt paraLen = ppara->GetLength();
            if (paraLen > left)
            {
                // the tail lies inside this paragraph
                Paragraph* psrc = *it;
                Paragraph* pdst = pdest->AppendNewParagraph(psrc->GetFormat());
                pdst->Copy(pdest->GetAllocator(), *psrc, 0, 0, left);
                break;
            }
            pdest->AppendCopyOfParagraph(*ppara);
            left -= paraLen;
        }
    }
    Paragraph* plast = pdest->GetLastParagraph();
    if (plast && plast->HasNewLine())
        pdest->AppendNewParagraph(plast->GetFormat());

    pdest->EnsureTermNull();
    if (MayHaveUrl())
        pdest->SetMayHaveUrl();
}

// @0x14259a500
UPInt StyledText::InsertString(const wchar_t* pstr, UPInt pos, UPInt length, NewLinePolicy newLinePolicy)
{
    return InsertString(pstr, pos, length, newLinePolicy, GetDefaultTextFormat(), GetDefaultParagraphFormat());
}

// Inserts plain text at pos: the characters take pdefTextFmt, each new-line character splits the paragraph.
// (4.1.18 has no NLP_IgnoreCRLF handling here; single-line fields filter new-lines before calling.)
// @0x14259a530
UPInt StyledText::InsertString(const wchar_t* pstr, UPInt pos, UPInt length, NewLinePolicy newLinePolicy,
                               const TextFormat* pdefTextFmt, const ParagraphFormat* pdefParaFmt)
{
    if (length == 0)
        return 0;
    if (pos > GetLength())
        pos = GetLength();
    if (length == SF_MAX_UPINT)
        length = Paragraph::TextBuffer::StrLen(pstr);

    OnTextInserting(pos, length, pstr);

    UPInt indexInPara = 0;
    UPInt left = length;
    SPInt newLineAt;
    ParagraphsIterator it = GetNearestParagraphByIndex(pos, &indexInPara);

    UPInt   lineLen;
    UPInt   nextStart = (!it.IsFinished()) ? (*it)->GetStartIndex() : 0;
    wchar_t ch = 0;
    UPInt   inserted = 0;

    do
    {
        if (it.IsFinished())
        {
            AppendNewParagraph(pdefParaFmt);
            it = GetParagraphIterator();
            indexInPara = 0;
        }
        Paragraph* ppara = *it;
        if (ppara->IsEmpty())
            ppara->SetFormat(pTextAllocator, *pdefParaFmt);

        lineLen   = 0;
        newLineAt = -1;
        if (newLinePolicy == NLP_CompressCRLF && ch == '\r' && pstr[lineLen] == '\n')
        {
            ++pstr;
            --left;
            if (left == 0)
                break;
        }
        for (; lineLen < left; ++lineLen)
        {
            ch = pstr[lineLen];
            if (ch == '\n' || ch == '\r')
            {
                newLineAt = lineLen;
                break;
            }
            else if (ch == 0)
                break;
        }
        if (ch == '\n' || ch == '\r')
            ++lineLen;

        if (newLineAt != -1)
        {
            // split: the tail of this paragraph moves to a new one after it
            ParagraphsIterator nextIt = it;
            ++nextIt;
            Paragraph& tail = *InsertNewParagraph(nextIt, pdefParaFmt);
            tail.SetFormat(ppara->GetFormat());
            tail.Copy(pTextAllocator, *ppara, indexInPara, 0, ppara->GetSize() - indexInPara);

            UPInt cut = ppara->GetSize();
            cut -= indexInPara;

            ppara->InsertString(pTextAllocator, pstr, indexInPara, lineLen, pdefTextFmt);
            if (cut > 0)
                ppara->Shrink(cut);
        }
        else
        {
            ppara->InsertString(pTextAllocator, pstr, indexInPara, lineLen, pdefTextFmt);
        }
        if ((ch == '\r' || ch == '\n') && ch != NewLineChar())
        {
            wchar_t* ptxt = ppara->GetText();
            ptxt[indexInPara + lineLen - 1] = NewLineChar();
        }

        left     -= lineLen;
        pstr     += lineLen;
        inserted += lineLen;
        ppara->SetStartIndex(nextStart);

        indexInPara = 0;
        nextStart += ppara->GetSize();
        ++it;
    } while (left > 0 && ch != 0);

    for (; !it.IsFinished(); ++it)
    {
        Paragraph* ppara = *it;
        ppara->SetStartIndex(nextStart);
        nextStart += ppara->GetSize();
    }

    EnsureTermNull();

    if (pdefTextFmt->IsUrlSet())
        SetMayHaveUrl();
    return inserted;
}

// @0x14259ab80
UPInt StyledText::InsertStyledText(const StyledText& text, UPInt pos, UPInt length)
{
    UPInt srcLen = text.GetLength();
    if (length == SF_MAX_UPINT || length > srcLen)
        length = srcLen;
    if (length == 0 || text.Paragraphs.GetSize() == 0)
        return 0;
    OnTextInserting(pos, length, "");

    UPInt indexInPara = 0;
    ParagraphsIterator dst = GetNearestParagraphByIndex(pos, &indexInPara);
    if (dst.IsFinished())
    {
        AppendNewParagraph();
        dst = GetParagraphIterator();
        indexInPara = 0;
    }

    UPInt nextStart = (!dst.IsFinished()) ? (*dst)->GetStartIndex() : 0;
    if (text.Paragraphs.GetSize() == 1)
    {
        // a single source paragraph goes straight into the target one
        Paragraph*       pdst = *dst;
        const Paragraph* psrc = text.Paragraphs[0];
        pdst->Copy(pTextAllocator, *psrc, 0, indexInPara, psrc->GetLength());
        if (indexInPara == 0)
            pdst->SetFormat(pTextAllocator, *psrc->GetFormat());

        nextStart += pdst->GetSize();
        ++dst;
    }
    else
    {
        UPInt left = length;
        ParagraphsIterator src = text.GetParagraphIterator();

        // split the target paragraph at the insertion point
        Paragraph* ppara = *dst;
        ParagraphsIterator nextIt = dst;
        ++nextIt;
        Paragraph& tail = *InsertNewParagraph(nextIt, ppara->GetFormat());
        tail.Copy(pTextAllocator, *ppara, indexInPara, 0, ppara->GetSize() - indexInPara);

        UPInt cut = ppara->GetSize();
        cut -= indexInPara;

        // the first source paragraph continues the head
        Paragraph* psrc = *src;
        ppara->Copy(pTextAllocator, *psrc, 0, indexInPara, psrc->GetLength());
        left -= psrc->GetLength();
        if (indexInPara == 0)
            ppara->SetFormat(pTextAllocator, *psrc->GetFormat());
        if (cut > 0)
            ppara->Shrink(cut);
        nextStart += ppara->GetLength();

        ++dst;
        ++src;
        for (; !src.IsFinished() && left > 0; ++src, ++dst)
        {
            const Paragraph* pnext = *src;
            UPInt paraLen = pnext->GetLength();

            // the last (partial or unterminated) source paragraph goes in front of the tail
            if (paraLen > left || (paraLen == left && !pnext->HasNewLine()))
            {
                tail.Copy(pTextAllocator, *pnext, 0, 0, paraLen);
                tail.SetFormat(pTextAllocator, *pnext->GetFormat());
                break;
            }
            InsertCopyOfParagraph(dst, *pnext);
            left      -= paraLen;
            nextStart += paraLen;
        }
        tail.SetStartIndex(nextStart);
        nextStart += tail.GetLength();
        ++dst;
    }

    for (; !dst.IsFinished(); ++dst)
    {
        Paragraph* ppara = *dst;
        if (ppara->GetStartIndex() == nextStart)
            break;
        ppara->SetStartIndex(nextStart);
        nextStart += ppara->GetSize();
    }
    EnsureTermNull();
    if (text.MayHaveUrl())
        SetMayHaveUrl();
    return length;
}

// @0x14259b860
void StyledText::RemoveParagraph(ParagraphsIterator& paraIter, Paragraph* ppara)
{
    OnParagraphRemoving(*ppara);
    ppara->FreeText(pTextAllocator);
    paraIter.Remove();
}

// Removes length characters at startPos; the paragraphs on both sides of a removed new-line are joined.
// @0x14259b340
void StyledText::Remove(UPInt startPos, UPInt length)
{
    if (length == SF_MAX_UPINT)
        length = GetLength();

    OnTextRemoving(startPos, length);

    UPInt indexInPara;
    ParagraphsIterator it = GetParagraphByIndex(startPos, &indexInPara);
    Paragraph* pfirst = NULL;

    UPInt left = length;
    bool  join = false;
    // the part of the first paragraph
    if (!it.IsFinished())
    {
        Paragraph* ppara = *it;
        UPInt n = Alg::PMin(left, ppara->GetSize() - indexInPara);
        if (n <= ppara->GetSize())
        {
            join   = (indexInPara + n >= ppara->GetSize());
            pfirst = *it;
            ppara->Remove(indexInPara, indexInPara + n);
            left -= n;
            ++it;
        }
    }

    // whole paragraphs, then the head of the last one
    while (!it.IsFinished())
    {
        Paragraph* ppara = *it;
        UPInt paraSize = ppara->GetSize();
        if (left >= paraSize)
        {
            RemoveParagraph(it, ppara);
            left -= paraSize;
        }
        else if (pfirst)
        {
            if (join)
            {
                UPInt at = pfirst->GetSize();
                UPInt n  = paraSize - left;
                pfirst->Copy(pTextAllocator, *ppara, left, at, n);

                RemoveParagraph(it, ppara);
                join = false;
            }
            break;
        }
        else
            break;
        if (left == 0)
            break;
    }
    if (!it.IsFinished())
    {
        Paragraph* ppara = *it;
        if (ppara->GetSize() == 0)
        {
            RemoveParagraph(it, ppara);
        }
        else if (pfirst && join)
        {
            UPInt paraSize = ppara->GetSize();
            UPInt at       = pfirst->GetSize();
            pfirst->Copy(pTextAllocator, *ppara, 0, at, paraSize);

            RemoveParagraph(it, ppara);
        }
    }

    for (; !it.IsFinished(); ++it)
    {
        Paragraph* ppara = *it;
        ppara->SetStartIndex(ppara->GetStartIndex() - length);
    }
    EnsureTermNull();
}

void StyledText::OnTextInserting(UPInt startPos, UPInt length, const wchar_t* ptxt)
{
    SF_UNUSED3(startPos, length, ptxt);
}

void StyledText::OnTextRemoving(UPInt startPos, UPInt length)
{
    SF_UNUSED2(startPos, length);
}

void StyledText::OnParagraphRemoving(const Paragraph& para)
{
    SF_UNUSED(para);
}

// ---------------------------------------------------------------------------------------------------------------
// StyledText::CharactersIterator

// @0x142593560
StyledText::CharactersIterator::CharactersIterator(StyledText* ptext)
    : Paragraphs(ptext->GetParagraphIterator()), pText(ptext), FirstCharInParagraphIndex(0)
{
    if (!Paragraphs.IsFinished())
    {
        Paragraph* ppara = *Paragraphs;
        FirstCharInParagraphIndex = ppara->GetStartIndex();
        Characters = ppara->GetCharactersIterator();
    }
}

// @0x142593680
StyledText::CharactersIterator::CharactersIterator(StyledText* ptext, int index)
    : pText(ptext)
{
    UPInt indexInPara;
    Paragraphs = ptext->GetParagraphByIndex(index, &indexInPara);
    if (!Paragraphs.IsFinished())
    {
        Paragraph* ppara = *Paragraphs;
        FirstCharInParagraphIndex = ppara->GetStartIndex();
        Characters = ppara->GetCharactersIterator(indexInPara);
    }
}

// @0x142594230
StyledText::CharacterInfo& StyledText::CharactersIterator::operator*()
{
    Paragraph::CharacterInfo& info = *Characters;
    CharInfoPlaceHolder.Character       = info.Character;
    CharInfoPlaceHolder.Index           = info.Index + FirstCharInParagraphIndex;
    CharInfoPlaceHolder.pOriginalFormat = info.pFormat;
    CharInfoPlaceHolder.pParagraph      = *Paragraphs;
    return CharInfoPlaceHolder;
}

// @0x142594400
void StyledText::CharactersIterator::operator++()
{
    ++Characters;
    if (!Characters.IsFinished())
        return;
    ++Paragraphs;
    if (!Paragraphs.IsFinished())
    {
        Paragraph* ppara = *Paragraphs;
        FirstCharInParagraphIndex = ppara->GetStartIndex();
        Characters = ppara->GetCharactersIterator();
    }
}

// @0x142595420
void StyledText::Clear()
{
    for (UPInt i = 0, n = Paragraphs.GetSize(); i < n; ++i)
        Paragraphs[i]->FreeText(GetAllocator());
    Paragraphs.Resize(0);
    ClearMayHaveUrl();
}

// back to the default formats
// @0x14259bea0
void Style::Reset()
{
    mTextFormat      = TextFormat(mTextFormat.GetHeap());
    mParagraphFormat = ParagraphFormat();
}

}}} // namespace Scaleform::Render::Text

// vftables (no RTTI under /GR-): the RefCountBaseNTS<..., StatRender_Text_Mem> bases share one table
// MS2-PIN: ??_7RefCountNTSImpl@Scaleform@@6B@ 0x1431093f0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7?$RefCountBaseNTS@VAllocator@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7Allocator@Text@Render@Scaleform@@6B@ 0x14317c9d0
// MS2-PIN: ??_7?$RefCountBaseNTS@VStyledText@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7StyledText@Text@Render@Scaleform@@6B@ 0x143184ca0

// MS2-PINS-BEGIN covpin
// MS2-PIN: ??$LowerBound@V?$ArrayLH@VParagraphPtrWrapper@StyledText@Text@Render@Scaleform@@$01UArrayDefaultPolicy@5@@Scaleform@@_KP6AHPEBVParagraph@Text@Render@2@_K@Z@Alg@Scaleform@@YA_KAEBV?$ArrayLH@VParagraphPtrWrapper@StyledText@Text@Render@Scaleform@@$01UArrayDefaultPolicy@5@@1@AEB_KP6AHPEBVParagraph@Text@Render@1@_K@Z@Z 0x142593350
// MS2-PIN: ??$LowerBoundSliced@V?$ArrayLH@VParagraphPtrWrapper@StyledText@Text@Render@Scaleform@@$01UArrayDefaultPolicy@5@@Scaleform@@_KP6AHPEBVParagraph@Text@Render@2@_K@Z@Alg@Scaleform@@YA_KAEBV?$ArrayLH@VParagraphPtrWrapper@StyledText@Text@Render@Scaleform@@$01UArrayDefaultPolicy@5@@1@_K1AEB_KP6AHPEBVParagraph@Text@Render@1@1@Z@Z 0x1425933e0
// MS2-PIN: ??1?$ArrayDataBase@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAA@XZ 0x142593f60
// MS2-PIN: ??1ParagraphPtrWrapper@StyledText@Text@Render@Scaleform@@QEAA@XZ 0x142596650
// MS2-PIN: ??1TextBuffer@Paragraph@Text@Render@Scaleform@@QEAA@XZ 0x142593ff0
// MS2-PIN: ??4TextFormat@Text@Render@Scaleform@@QEAAAEAV0123@AEBV0123@@Z 0x142594030
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@UEAAPEAXI@Z 0x1425945f0
// MS2-PIN: ??_GStyledText@Text@Render@Scaleform@@UEAAPEAXI@Z 0x142594650
// MS2-PIN: ?ClearRange@?$RangeDataArray@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@V?$ArrayLH@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@2@@Scaleform@@QEAAX_J_K@Z 0x142595580
// MS2-PIN: ?DestructArray@?$ConstructorMov@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@@Scaleform@@SAXPEAV?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@2@_K@Z 0x1425966b0
// MS2-PIN: ?DestructArray@?$ConstructorMov@VParagraphPtrWrapper@StyledText@Text@Render@Scaleform@@@Scaleform@@SAXPEAVParagraphPtrWrapper@StyledText@Text@Render@2@_K@Z 0x142596720
// MS2-PIN: ?ExpandRange@?$RangeDataArray@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@V?$ArrayLH@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@2@@Scaleform@@QEAAX_J_K@Z 0x142596840
// MS2-PIN: ?FindNearestRangeIndex@?$RangeDataArray@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@V?$ArrayLH@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@2@@Scaleform@@AEBA_K_J@Z 0x142596920
// MS2-PIN: ?GetAllocator@StyledText@Text@Render@Scaleform@@IEBAPEAVAllocator@234@XZ 0x142596aa0
// MS2-PIN: ?GetImageDesc@TextFormat@Text@Render@Scaleform@@QEBAPEAUHTMLImageTagDesc@234@XZ 0x142598730
// MS2-PIN: ?GetIteratorByNearestIndex@?$RangeDataArray@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@V?$ArrayLH@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@2@@Scaleform@@QEAA?AVIterator@12@_J@Z 0x1425988d0
// MS2-PIN: ?GetIteratorByNearestIndex@?$RangeDataArray@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@V?$ArrayLH@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@2@@Scaleform@@QEBA?AVConstIterator@12@_J@Z 0x142598940
// MS2-PIN: ?InsertAt@?$ArrayBase@U?$ArrayData@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@QEAAX_KAEBV?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@2@@Z 0x14259a050
// MS2-PIN: ?IsFinished@Iterator@?$RangeDataArray@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@V?$ArrayLH@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@2@@Scaleform@@QEBA_NXZ 0x14259b130
// MS2-PIN: ?Remove@Iterator@?$RangeDataArray@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@V?$ArrayLH@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@2@@Scaleform@@AEAAXXZ 0x14259b1e0
// MS2-PIN: ?RemoveRange@?$RangeDataArray@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@V?$ArrayLH@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@2@@Scaleform@@QEAAX_J_K@Z 0x14259b910
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x14259bd60
// MS2-PIN: ?Reserve@?$ArrayDataBase@VParagraphPtrWrapper@StyledText@Text@Render@Scaleform@@U?$AllocatorLH@VParagraphPtrWrapper@StyledText@Text@Render@Scaleform@@$01@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAXPEBX_K@Z 0x14259be00
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x14259bfb0
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@VParagraphPtrWrapper@StyledText@Text@Render@Scaleform@@U?$AllocatorLH@VParagraphPtrWrapper@StyledText@Text@Render@Scaleform@@$01@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAXPEBX_K@Z 0x14259c050
// MS2-PIN: ?Set@StyledTextRun@Paragraph@Text@Render@Scaleform@@QEAAAEAU12345@PEB_W_J_KPEAVTextFormat@345@@Z 0x14259c0f0
// MS2-PIN: ?SetRange@?$RangeDataArray@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@V?$ArrayLH@V?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@2@@Scaleform@@QEAAXAEBV?$RangeData@V?$Ptr@VTextFormat@Text@Render@Scaleform@@@Scaleform@@@2@@Z 0x14259c740
// MS2-PINS-END covpin
