// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_ASString (the interned
// ActionScript string table: nodes, text buffers, string operations).
// Queue unit sfr_gfx_03 is split along its original sources: this file is GFx_ASString.
// MS2-UNIT: sfr_gfx_03c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425bf3c0-0x1425c1bf0 .text$mn

// Alg::UpperBit is inlined into this TU's hash rehash in the exe.
#define MS2_SF_UPPERBIT_INLINE
#include "../include/gfx/gfx_asstring.h"
#include "../include/gfx/gfx_log.h"
#include <wchar.h>

namespace Scaleform { namespace GFx {

// @0x1425c0ea0
unsigned long ASConstString::HashFunction(const char* pchar, UPInt length)
{
    return (unsigned long)String::BernsteinHashFunctionCIS(pchar, length) & Flag_HashMask;
}

// @0x1425c0460
void ASString::Clear()
{
    AssignNode(GetManager()->GetEmptyStringNode());
}

// @0x1425bfa90
bool ASString::operator<(const ASString& str) const
{
    if (pNode == str.pNode)
        return false;
    unsigned size   = GetSize() < str.GetSize() ? GetSize() : str.GetSize();
    int      result = memcmp(ToCStr(), str.ToCStr(), size);
    if (result != 0)
        return result < 0;
    return GetSize() < str.GetSize();
}

// @0x1425c0e10
unsigned ASConstString::GetLength() const
{
    unsigned size = GetSize();
    if (GetHashFlags() & Flag_LengthIsSize)
        return size;
    unsigned length = (unsigned)UTF8Util::GetLength(GetBuffer(), GetSize());
    if (length == size)
        pNode->HashFlags |= Flag_LengthIsSize;
    return length;
}

// @0x1425c0d60
unsigned long ASConstString::GetCharAt(unsigned index) const
{
    if (GetHashFlags() & Flag_LengthIsSize)
        return (unsigned long)operator[](index);

    int           i   = (int)index;
    const char*   buf = GetBuffer();
    unsigned long ch;
    do
    {
        ch = UTF8Util::DecodeNextChar_Advance0(&buf);
        i--;
    } while (i >= 0);
    return ch;
}

// @0x1425c0da0
unsigned long ASConstString::GetFirstCharAt(UPInt index, const char** offset) const
{
    SPInt         i   = (SPInt)index;
    const char*   buf = ToCStr();
    const char*   end = buf + GetSize();
    unsigned long ch;
    do
    {
        ch = UTF8Util::DecodeNextChar_Advance0(&buf);
        i--;
        if (buf >= end)
            return ch;
    } while (i >= 0);
    *offset = buf;
    return ch;
}

// @0x1425c0e60
unsigned long ASConstString::GetNextChar(const char** offset) const
{
    if (GetHashFlags() & Flag_LengthIsSize)
    {
        unsigned long ch = **offset;
        ++(*offset);
        return ch;
    }
    return UTF8Util::DecodeNextChar(offset);
}

// @0x1425c0370
ASStringNode* ASConstString::AppendCharNode(unsigned long ch) const
{
    char  buff[8];
    SPInt index = 0;
    UTF8Util::EncodeChar(buff, &index, ch);

    ASStringNode* pnode = GetManager()->CreateStringNode(pNode->pData, pNode->Size, buff, index);
    // An ASCII character keeps an ASCII string ASCII.
    if ((pNode->HashFlags & Flag_LengthIsSize) && ch < 128)
        pnode->HashFlags |= Flag_LengthIsSize;
    return pnode;
}

// [start, end) in characters; an end past the text stops at the text's end.
// @0x1425c1760
ASStringNode* ASConstString::SubstringNode(int start, int end) const
{
    if (start == end)
        return GetManager()->GetEmptyStringNode();

    int         index = 0;
    const char* p     = GetBuffer();
    const char* pstart = p;
    const char* pend   = p;
    for (;;)
    {
        if (index == start)
            pstart = p;
        unsigned long ch = UTF8Util::DecodeNextChar(&p);
        index++;
        if (index == end)
        {
            pend = p;
            break;
        }
        if (ch == 0)
        {
            if (index < end)
                pend = p;
            break;
        }
    }
    if (pend < pstart)
        pend = pstart;
    return GetManager()->CreateStringNode(pstart, (int)(pend - pstart));
}

// @0x1425c1910
ASStringNode* ASConstString::TruncateWhitespaceNode() const
{
    const StringDataPtr whole(ToCStr(), GetSize());
    StringDataPtr       trimmed = whole.GetTruncateWhitespace();
    if (trimmed == whole)
        return GetNode();
    return GetManager()->CreateStringNode(trimmed.ToCStr(), trimmed.GetSize());
}

// @0x1425c1860
// MS2-FUNCTIONAL: same code, this and the -1 constant swap rbx/rdi
ASStringNode* ASConstString::ToUpperNode() const
{
    String upper = String(pNode->pData, GetSize()).ToUpper();
    return GetManager()->CreateStringNode(upper.ToCStr(), upper.GetSize());
}

// @0x1425c1820
ASStringNode* ASConstString::ToLowerNode() const
{
    ResolveLowercase();
    return pNode->pLower ? pNode->pLower : GetManager()->GetEmptyStringNode();
}

// @0x1425bf980
void ASString::operator=(const char* pstr)
{
    AssignNode(GetManager()->CreateStringNode(pstr, strlen(pstr)));
}

// @0x1425c0320
void ASString::Append(const char* str, UPInt len)
{
    AssignNode(GetManager()->CreateStringNode(pNode->pData, pNode->Size, str, len));
}

// @0x1425c02d0
void ASString::Append(const ASString& str)
{
    AssignNode(GetManager()->CreateStringNode(pNode->pData, pNode->Size, str.pNode->pData, str.pNode->Size));
}

// @0x1425bfa40
ASString ASString::operator+(const char* pstr) const
{
    return ASString(GetManager()->CreateStringNode(pNode->pData, pNode->Size, pstr, strlen(pstr)));
}

// @0x1425bfa00
ASString ASString::operator+(const ASString& str) const
{
    return ASString(GetManager()->CreateStringNode(pNode->pData, pNode->Size, str.pNode->pData, str.pNode->Size));
}

// @0x1425c0400
ASStringNode* ASConstString::AppendStringNode(const ASConstString& str) const
{
    ASStringNode* pnode = GetManager()->CreateStringNode(pNode->pData, pNode->Size, str.pNode->pData, str.pNode->Size);
    if ((pNode->HashFlags & Flag_LengthIsSize) && (str.GetNode()->HashFlags & Flag_LengthIsSize))
        pnode->HashFlags |= Flag_LengthIsSize;
    return pnode;
}

// @0x1425c1090
int ASConstString::LocaleCompare_CaseCheck(const char* pstr, UPInt len, bool caseSensitive) const
{
    if (len == (UPInt)-1)
        len = strlen(pstr);

    // Wide copies of both texts: on the stack when short, on the global heap otherwise.
    wchar_t  stackA[250], stackB[250];
    wchar_t* pwa;
    wchar_t* pwb;
    UPInt    lenA = GetLength();
    if (lenA >= 250)
        pwa = (wchar_t*)SF_ALLOC(sizeof(wchar_t) * (lenA + 1), Stat_Default_Mem);
    else
        pwa = stackA;
    if (len >= 250)
        pwb = (wchar_t*)SF_ALLOC(sizeof(wchar_t) * (len + 1), Stat_Default_Mem);
    else
        pwb = stackB;

    UTF8Util::DecodeString(pwa, ToCStr(), GetSize());
    UTF8Util::DecodeString(pwb, pstr, len);

    int result;
    if (caseSensitive)
        result = wcscoll(pwa, pwb);
    else
        result = _wcsicoll(pwa, pwb);

    if (pwa != stackA)
        SF_FREE(pwa);
    if (pwb != stackB)
        SF_FREE(pwb);
    return result;
}

// Links pLower to the interned lowercase text (an empty result leaves it unresolved).
// @0x1425c1630
void ASStringNode::ResolveLowercase_Impl()
{
    String        lower = String(pData, Size).ToLower();
    ASStringNode* pnode = pManager->CreateStringNode(lower.ToCStr(), lower.GetSize());
    if (pnode != pManager->GetEmptyStringNode())
    {
        pLower = pnode;
        if (pnode != this)
            pnode->AddRef();
    }
}

// Called once RefCount dropped to 0.
// @0x1425c14e0
void ASStringNode::ReleaseNode()
{
    if (pLower != this && pLower)
        pLower->Release();
    pManager->StringSet.Remove(this);
    pManager->FreeStringNode(this);
}

// @0x1425bf620
ASStringManager::ASStringManager(MemoryHeap* pheap) : pHeap(pheap)
{
    pStringNodePages = 0;
    pFreeStringNodes = 0;
    pFreeTextBuffers = 0;
    pTextBufferPages = 0;

    // The empty string holds a reference of its own and is never freed.
    EmptyStringNode.RefCount  = 1;
    EmptyStringNode.Size      = 0;
    EmptyStringNode.HashFlags = ASConstString::HashFunction("", 0) | ASConstString::Flag_ConstData |
                                ASConstString::Flag_Builtin | ASConstString::Flag_LengthIsSize;
    EmptyStringNode.pData     = "";
    EmptyStringNode.pManager  = this;
    EmptyStringNode.pLower    = &EmptyStringNode;
    StringSet.Add(&EmptyStringNode);

    NullStringNode        = EmptyStringNode;
    NullStringNode.pLower = &NullStringNode;
}

// Frees all pages; nodes still alive at this point are leaks and get reported to pLog.
// @0x1425bf710
ASStringManager::~ASStringManager()
{
    StringBuffer leakReport;
    unsigned     leaks = 0;

    while (pStringNodePages)
    {
        StringNodePage* ppage = pStringNodePages;
        pStringNodePages      = ppage->pNext;

        for (unsigned i = 0; i < StringNodePage::StringNodeCount; i++)
        {
            ASStringNode& node = ppage->Nodes[i];
            if (node.pData)
            {
                if (leaks < 16)
                {
                    leakReport.AppendString(leaks > 0 ? ", '" : "'");
                    leakReport.AppendString(node.pData);
                    leakReport.AppendString("'");
                }
                leaks++;
                if (!(node.HashFlags & ASConstString::Flag_ConstData))
                    FreeTextBuffer(const_cast<char*>(node.pData), node.Size);
            }
        }
        SF_HEAP_FREE(pHeap, ppage);
    }

    while (pTextBufferPages)
    {
        void* pmem       = pTextBufferPages->pMem;
        pTextBufferPages = pTextBufferPages->pNext;
        SF_HEAP_FREE(pHeap, pmem);
    }

    if (leaks && pLog.GetPtr())
    {
        pLog->LogScriptError("ActionScript Memory leaks in movie '%s', including %d string nodes", FileName.ToCStr(),
                             leaks);
        pLog->LogScriptError("Leaked string content: %s\n", leakReport.ToCStr());
    }
}

// @0x1425c16f0
void ASStringManager::SetLeakReportLog(LogState* plog, const char* pfilename)
{
    pLog     = plog;
    FileName = pfilename ? pfilename : "";
}

// @0x1425bfd90
void ASStringManager::AllocateStringNodes()
{
    StringNodePage* ppage = (StringNodePage*)SF_HEAP_ALLOC(pHeap, sizeof(StringNodePage), StatMV_ASString_Mem);
    if (ppage)
    {
        ppage->pNext     = pStringNodePages;
        pStringNodePages = ppage;
        for (unsigned i = 0; i < StringNodePage::StringNodeCount; i++)
        {
            ASStringNode* pnode = &ppage->Nodes[i];
            pnode->pData        = 0;
            pnode->pManager     = this;
            pnode->pNextAlloc   = pFreeStringNodes;
            pFreeStringNodes    = pnode;
        }
    }
}

// @0x1425bfe00
void ASStringManager::AllocateTextBuffers()
{
    // 8-aligned inside an allocation with 8 spare bytes.
    void*     pmem  = SF_HEAP_ALLOC(pHeap, sizeof(TextPage) + 8, StatMV_ASString_Mem);
    TextPage* ppage = (TextPage*)(((UPInt)pmem + 7) & ~(UPInt)7);
    if (ppage)
    {
        ppage->pMem      = pmem;
        ppage->pNext     = pTextBufferPages;
        pTextBufferPages = ppage;
        for (unsigned i = 0; i < TextPage::BuffCount; i++)
        {
            TextPage::Entry* pentry = ppage->Entries + i;
            pentry->pNextAlloc      = pFreeTextBuffers;
            pFreeTextBuffers        = pentry;
        }
    }
}

// @0x1425bfd30
char* ASStringManager::AllocTextBuffer(UPInt length)
{
    if (length < TextPage::BuffSize)
    {
        if (!pFreeTextBuffers)
            AllocateTextBuffers();
        char* pbuff = 0;
        if (pFreeTextBuffers)
        {
            pbuff            = pFreeTextBuffers->Buff;
            pFreeTextBuffers = pFreeTextBuffers->pNextAlloc;
        }
        return pbuff;
    }
    return (char*)SF_HEAP_ALLOC(pHeap, length + 1, StatMV_ASString_Mem);
}

// @0x1425bfca0
char* ASStringManager::AllocTextBuffer(const char* pbuffer, UPInt length)
{
    char* pbuff = AllocTextBuffer(length);
    if (pbuff)
    {
        memcpy(pbuff, pbuffer, length);
        pbuff[length] = 0;
    }
    return pbuff;
}

// @0x1425bf9d0
bool operator==(ASStringNode* pnode, const ASStringKey& key)
{
    if (pnode->Size != key.Length)
        return false;
    return strncmp(pnode->pData, key.pStr, key.Length) == 0;
}

// Interns text the manager does not own (literals); stringFlags are added even to an existing node.
// @0x1425c04a0
ASStringNode* ASStringManager::CreateConstStringNode(const char* pstr, UPInt length, unsigned long stringFlags)
{
    ASStringNode* pnode;
    ASStringKey   key(pstr, ASConstString::HashFunction(pstr, length), length);
    if (StringSet.GetAlt(key, &pnode))
    {
        pnode->HashFlags |= stringFlags;
        return pnode;
    }
    if ((pnode = AllocStringNode()) != 0)
    {
        pnode->RefCount  = 0;
        pnode->Size      = (unsigned)length;
        pnode->pData     = pstr;
        pnode->HashFlags = (unsigned)(key.HashValue | ASConstString::Flag_ConstData | stringFlags);
        pnode->pLower    = 0;
        StringSet.Add(pnode);
        return pnode;
    }
    return &EmptyStringNode;
}

// @0x1425c0a80
ASStringNode* ASStringManager::CreateStringNode(const char* pstr, UPInt length)
{
    if (!pstr || length == 0)
        return &EmptyStringNode;

    ASStringNode* pnode;
    ASStringKey   key(pstr, ASConstString::HashFunction(pstr, length), length);
    if (StringSet.GetAlt(key, &pnode))
        return pnode;
    if ((pnode = AllocStringNode()) != 0)
    {
        pnode->pData = AllocTextBuffer(pstr, length);
        if (pnode->pData)
        {
            pnode->RefCount  = 0;
            pnode->Size      = (unsigned)length;
            pnode->HashFlags = (unsigned)key.HashValue;
            pnode->pLower    = 0;
            StringSet.Add(pnode);
            return pnode;
        }
        FreeStringNode(pnode);
    }
    return &EmptyStringNode;
}

// @0x1425c05f0
ASStringNode* ASStringManager::CreateStringNode(const char* pstr)
{
    if (!pstr)
        return &EmptyStringNode;
    return CreateStringNode(pstr, strlen(pstr));
}

// @0x1425c0c40
ASStringNode* ASStringManager::CreateStringNode(const wchar_t* pwstr, SPInt len)
{
    String utf8;
    utf8.AppendString(pwstr, len);
    return CreateStringNode(utf8.ToCStr(), utf8.GetSize());
}

// Concatenation: the joined text is built first, then looked up.
// @0x1425c0860
ASStringNode* ASStringManager::CreateStringNode(const char* pstr1, UPInt l1, const char* pstr2, UPInt l2)
{
    ASStringNode* pnode;
    UPInt         length  = l1 + l2;
    char*         pbuffer = AllocTextBuffer(length);
    if (pbuffer)
    {
        if (pstr1 && l1 > 0)
            memcpy(pbuffer, pstr1, l1);
        if (pstr2 && l2 > 0)
            memcpy(pbuffer + l1, pstr2, l2);
        pbuffer[length] = 0;

        ASStringKey key(pbuffer, ASConstString::HashFunction(pbuffer, length), length);
        if (StringSet.GetAlt(key, &pnode))
        {
            FreeTextBuffer(pbuffer, length);
            return pnode;
        }
        if ((pnode = AllocStringNode()) != 0)
        {
            pnode->RefCount  = 0;
            pnode->Size      = (unsigned)length;
            pnode->pData     = pbuffer;
            pnode->HashFlags = (unsigned)key.HashValue;
            pnode->pLower    = 0;
            StringSet.Add(pnode);
            return pnode;
        }
        FreeTextBuffer(pbuffer, length);
    }
    return &EmptyStringNode;
}

// @0x1425c0610
ASStringNode* ASStringManager::CreateStringNode(const char* pstr1, UPInt l1, const char* pstr2, UPInt l2,
                                                const char* pstr3, UPInt l3)
{
    ASStringNode* pnode;
    UPInt         length  = l1 + l2 + l3;
    char*         pbuffer = AllocTextBuffer(length);
    if (pbuffer)
    {
        if (pstr1 && l1 > 0)
            memcpy(pbuffer, pstr1, l1);
        if (pstr2 && l2 > 0)
            memcpy(pbuffer + l1, pstr2, l2);
        if (pstr3 && l3 > 0)
            memcpy(pbuffer + l1 + l2, pstr3, l3);
        pbuffer[length] = 0;

        ASStringKey key(pbuffer, ASConstString::HashFunction(pbuffer, length), length);
        if (StringSet.GetAlt(key, &pnode))
        {
            FreeTextBuffer(pbuffer, length);
            return pnode;
        }
        if ((pnode = AllocStringNode()) != 0)
        {
            pnode->RefCount  = 0;
            pnode->Size      = (unsigned)length;
            pnode->pData     = pbuffer;
            pnode->HashFlags = (unsigned)key.HashValue;
            pnode->pLower    = 0;
            StringSet.Add(pnode);
            return pnode;
        }
        FreeTextBuffer(pbuffer, length);
    }
    return &EmptyStringNode;
}

// Interns count literals as builtins; each keeps a reference and has its lowercase twin resolved.
// @0x1425c0ec0
void ASStringManager::InitBuiltinArray(ASStringNodeHolder* nodes, const char** strings, unsigned count)
{
    for (unsigned i = 0; i < count; i++)
    {
        ASString str(CreateConstString(strings[i], strlen(strings[i]), (unsigned long)ASConstString::Flag_Builtin));
        nodes[i].pNode = str.GetNode();
        nodes[i].pNode->AddRef();
        nodes[i].pNode->ResolveLowercase_Impl();
    }
}

// @0x1425c1350
void ASStringManager::ReleaseBuiltinArray(ASStringNodeHolder* nodes, unsigned count)
{
    for (unsigned i = 0; i < count; i++)
    {
        nodes[i].pNode->Release();
        nodes[i].pNode = 0;
    }
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BEE@@Scaleform@@6B@ 0x14318a0e0
// MS2-PIN: ??_7?$RefCountBase@VASStringManager@GFx@Scaleform@@$0BEE@@Scaleform@@6B@ 0x14318a0d8
// MS2-PIN: ??_7ASStringManager@GFx@Scaleform@@6B@ 0x14318a0e8
