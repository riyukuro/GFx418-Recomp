// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 XML, parser handler that builds the DOM tree. Ends at 0x1429a8910: MFC code follows.
// Queue unit sfr_gfx_09 is split along its three original sources (sfr_gfx_09 / 09b / 09c): inlining of the
// DOMString members differs between them.
// MS2-UNIT: sfr_gfx_09c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429a7310-0x1429a8910 .text$mn

#include "../include/gfx/xml/xml_dom.h"
#include "../include/kernel/sf_std.h"
#include "../include/kernel/sf_utf8util.h"

namespace Scaleform { namespace GFx { namespace XML {

// ---------------------------------------------------------------- DOM builder

// @0x1429a7310
DOMBuilder::DOMBuilder(Ptr<SupportBase> pxmlParser, bool ignorews)
    : pXMLParserState(pxmlParser), pLocator(0), pDoc(0), bIgnoreWhitespace(ignorews), bError(false)
{
}

// @0x1429a7600
void DOMBuilder::Characters(const StringRef& text)
{
    LoadedBytes = pLocator->LoadedBytes;

    // Adjacent character runs are gathered into one text node, created on the first run and filled in when the
    // next element starts or the current one ends.
    Ptr<ObjectManager> memMgr = pDoc->MemoryManager;
    if (pAppendChainRoot.GetPtr() == 0)
    {
        pAppendChainRoot = *memMgr->CreateTextNode(memMgr->EmptyString());
        AppendText.AppendString(text.ToCStr(), text.GetSize());
    }
    else
    {
        AppendText.AppendString(text.ToCStr(), text.GetSize());
    }
}

// @0x1429a76b0
bool CheckWhiteSpaceNode(TextNode* textNode)
{
    const char* p     = textNode->Value.GetBuffer();
    bool        allWs = true;
    UInt32      ch;
    while ((ch = UTF8Util::DecodeNextChar(&p)) != 0)
    {
        if (!SFiswspace((wchar_t)ch))
        {
            allWs = false;
            break;
        }
    }
    return allWs;
}

// @0x1429a7720
void DOMBuilder::Comment(const StringRef&)
{
    LoadedBytes = pLocator->LoadedBytes;
}

void DropWhiteSpaceNodesHelper(ElementNode* elemNode);

// @0x1429a7730
void DOMBuilder::DropWhiteSpaceNodes(Document* document)
{
    for (Node* child = document->FirstChild; child != 0; child = child->NextSibling)
    {
        if (child->Type == ElementNodeType)
            DropWhiteSpaceNodesHelper((ElementNode*)child);
    }
}

// @0x1429a7830
void DropWhiteSpaceNodesHelper(ElementNode* elemNode)
{
    Node* child = elemNode->FirstChild;
    Node* next  = child;
    while (child != 0)
    {
        next = child->NextSibling;
        if (child->Type == ElementNodeType)
            DropWhiteSpaceNodesHelper((ElementNode*)child);
        else if (child->Type == TextNodeType)
        {
            if (CheckWhiteSpaceNode((TextNode*)child))
                elemNode->RemoveChild(child);
        }
        child = next;
    }
}

// @0x1429a7900
void DOMBuilder::EndDocument()
{
    LoadedBytes = pLocator->LoadedBytes;
    ParseStack.Clear();

    // Copy the prolog (version, encoding, standalone) onto the document.
    Ptr<ObjectManager> memMgr = pDoc->MemoryManager;
    pDoc->XMLVersion = memMgr->CreateString(pLocator->XMLVersion.ToCStr(), pLocator->XMLVersion.GetSize());
    pDoc->Encoding   = memMgr->CreateString(pLocator->Encoding.ToCStr(), pLocator->Encoding.GetSize());
    pDoc->Standalone = (SByte)pLocator->StandAlone;
}

// @0x1429a7a00
void DOMBuilder::EndElement(const StringRef&, const StringRef&)
{
    LoadedBytes = pLocator->LoadedBytes;

    Ptr<ElementNode> node = ParseStack.Back();
    if (pAppendChainRoot.GetPtr() != 0)
    {
        // Flush pending text into the closing element.
        Ptr<ObjectManager> memMgr = pDoc->MemoryManager;
        node->AppendChild(pAppendChainRoot);
        pAppendChainRoot->Value = memMgr->CreateString(AppendText.ToCStr(), AppendText.GetSize());
        pAppendChainRoot        = 0;
        AppendText.Clear();
    }

    // Namespace bindings declared by this element go out of scope with it.
    if (PrefixNamespaceStack.GetSize() > 0)
    {
        UPInt n = PrefixNamespaceStack.GetSize();
        for (int i = (int)n - 1; i >= 0; i--)
        {
            PrefixOwnership po = PrefixNamespaceStack[i];
            if (po.Owner != node)
                break;
            PrefixNamespaceStack.PopBack();
        }
    }
    if (DefaultNamespaceStack.GetSize() > 0)
    {
        PrefixOwnership po = DefaultNamespaceStack.Back();
        if (po.Owner == node)
            DefaultNamespaceStack.PopBack();
    }
    ParseStack.PopBack();
}

// @0x1429a7d30
void DOMBuilder::Error(const ParserException&)
{
    LoadedBytes = pLocator->LoadedBytes;
    bError      = true;
}

// @0x1429a7d50
void DOMBuilder::FatalError(const ParserException&)
{
    LoadedBytes = pLocator->LoadedBytes;
    bError      = true;
}

// @0x1429a7d70
void DOMBuilder::IgnorableWhitespace(const StringRef&)
{
    LoadedBytes = pLocator->LoadedBytes;
}

// @0x1429a7d80
Ptr<Document> DOMBuilder::ParseFile(const char* pfilename, FileOpenerBase* pfo, Ptr<ObjectManager> objMgr)
{
    bError           = false;
    TotalBytesToLoad = 0;
    LoadedBytes      = 0;

    if (0 == objMgr.GetPtr())
        objMgr = *new ObjectManager;
    pDoc = *objMgr->CreateDocument();
    if (pXMLParserState)
        bError = !pXMLParserState->ParseFile(pfilename, pfo, this);

    Ptr<Document> result = pDoc;
    pDoc                 = 0;
    if (result.GetPtr() && bIgnoreWhitespace)
        DropWhiteSpaceNodes(result);
    return result;
}

// @0x1429a7ed0
Ptr<Document> DOMBuilder::ParseString(const char* pdata, UPInt len, Ptr<ObjectManager> objMgr)
{
    bError           = false;
    TotalBytesToLoad = 0;
    LoadedBytes      = 0;

    if (0 == objMgr.GetPtr())
        objMgr = *new ObjectManager;
    pDoc = *objMgr->CreateDocument();
    if (pXMLParserState)
        bError = !pXMLParserState->ParseString(pdata, len, this);

    Ptr<Document> result = pDoc;
    pDoc                 = 0;
    if (result.GetPtr() && bIgnoreWhitespace)
        DropWhiteSpaceNodes(result);
    return result;
}

// @0x1429a8020
void DOMBuilder::PrefixMapping(const StringRef& prefix, const StringRef& uri)
{
    LoadedBytes = pLocator->LoadedBytes;

    // The owning element is filled in by the next StartElement.
    Ptr<ObjectManager> memMgr = pDoc->MemoryManager;
    Ptr<Prefix> pfx = *memMgr->CreatePrefix(memMgr->CreateString(prefix.ToCStr(), prefix.GetSize()),
                                            memMgr->CreateString(uri.ToCStr(), uri.GetSize()));
    if (prefix.GetSize() > 0)
        PrefixNamespaceStack.PushBack(PrefixOwnership(pfx, 0));
    else
        DefaultNamespaceStack.PushBack(PrefixOwnership(pfx, 0));
}

// @0x1429a8400
void DOMBuilder::SetDocumentLocator(const ParserLocator* plocator)
{
    pLocator = plocator;
}

// @0x1429a8410
void DOMBuilder::SkippedEntity(const StringRef&)
{
    LoadedBytes = pLocator->LoadedBytes;
}

// @0x1429a8420
void DOMBuilder::StartDocument()
{
    ParseStack.PushBack(pDoc);
    TotalBytesToLoad = pLocator->TotalBytesToLoad;
}

// @0x1429a84a0
void DOMBuilder::StartElement(const StringRef& prefix, const StringRef& localname, const ParserAttributes& atts)
{
    LoadedBytes = pLocator->LoadedBytes;

    Ptr<ObjectManager> memMgr = pDoc->MemoryManager;

    // Pending text belongs to the enclosing element, before this one.
    if (pAppendChainRoot.GetPtr() != 0)
    {
        Ptr<ElementNode> parent = ParseStack.Back();
        parent->AppendChild(pAppendChainRoot);
        pAppendChainRoot->Value = memMgr->CreateString(AppendText.ToCStr(), AppendText.GetSize());
        pAppendChainRoot        = 0;
        AppendText.Clear();
    }

    Ptr<ElementNode> elem = *memMgr->CreateElementNode(memMgr->CreateString(localname.ToCStr(), localname.GetSize()));
    for (UPInt i = 0; i < atts.Length; i++)
    {
        ParserAttribute& att = atts.Attributes[i];
        Attribute* a = memMgr->CreateAttribute(memMgr->CreateString(att.Name.ToCStr(), att.Name.GetSize()),
                                               memMgr->CreateString(att.Value.ToCStr(), att.Value.GetSize()));
        elem->AddAttribute(a);
    }

    // Bindings announced by PrefixMapping just before this element are owned by it.
    if (PrefixNamespaceStack.GetSize() > 0)
    {
        UPInt n = PrefixNamespaceStack.GetSize();
        for (int i = (int)n - 1; i >= 0; i--)
        {
            PrefixOwnership& po = PrefixNamespaceStack[i];
            if (0 != po.Owner.GetPtr())
                break;
            po.Owner = elem;
        }
    }
    if (DefaultNamespaceStack.GetSize() > 0)
    {
        PrefixOwnership& po = DefaultNamespaceStack.Back();
        if (0 == po.Owner.GetPtr())
            po.Owner = elem;
    }

    // Resolve the element's prefix to a namespace (innermost binding wins; unknown prefixes get no namespace).
    if (prefix.GetSize() > 0)
    {
        bool found = false;
        if (PrefixNamespaceStack.GetSize() > 0)
        {
            UPInt n = PrefixNamespaceStack.GetSize();
            for (int i = (int)n - 1; i >= 0; i--)
            {
                PrefixOwnership po = PrefixNamespaceStack[i];
                if (po.mPrefix->Name == DOMStringCompareWrapper(prefix.ToCStr(), prefix.GetSize()))
                {
                    found           = true;
                    elem->Prefix    = po.mPrefix->Name;
                    elem->Namespace = po.mPrefix->Value;
                    break;
                }
            }
        }
        if (!found)
        {
            elem->Prefix    = memMgr->CreateString(prefix.ToCStr(), prefix.GetSize());
            elem->Namespace = memMgr->EmptyString();
        }
    }
    else if (DefaultNamespaceStack.GetSize() > 0)
    {
        PrefixOwnership po = DefaultNamespaceStack.Back();
        elem->Prefix       = po.mPrefix->Name;
        elem->Namespace    = po.mPrefix->Value;
    }

    Ptr<ElementNode> parent = ParseStack.Back();
    parent->AppendChild(elem);
    ParseStack.PushBack(elem);
}

// @0x1429a8900
void DOMBuilder::Warning(const ParserException&)
{
    LoadedBytes = pLocator->LoadedBytes;
}

} // namespace XML
}} // namespace Scaleform::GFx

// Scaleform is built without RTTI: the vftables are pinned by hand. RefCountBaseStatImpl<RefCountImpl> and
// ParserHandler are the AS2 XML loader TU's copies (the linker kept the first one).
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BEG@@Scaleform@@6B@ 0x143224128
// MS2-PIN: ??_7ParserHandler@XML@GFx@Scaleform@@6B@ 0x143224148
// MS2-PIN: ??_7?$RefCountBase@VParserHandler@XML@GFx@Scaleform@@$0BEG@@Scaleform@@6B@ 0x143224840
// MS2-PIN: ??_7DOMBuilder@XML@GFx@Scaleform@@6B@ 0x143224848
// MS2-PIN: ??_G?$RefCountBase@VParserHandler@XML@GFx@Scaleform@@$0BEG@@Scaleform@@UEAAPEAXI@Z 0x1429a74e0
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
