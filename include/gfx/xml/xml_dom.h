// Recovered Scaleform 4.1.18 GFx XML: parser handler that builds a Document tree.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_XML_DOM_H
#define MS2_SF_GFX_XML_DOM_H

#include "xml_parser.h"
#include "xml_document.h"
#include "xml_support.h"

namespace Scaleform { namespace GFx { namespace XML {

// 0xc0 bytes, vtable 0x143224848.
class DOMBuilder : public ParserHandler
{
public:
    DOMBuilder(Ptr<SupportBase> pxmlParser, bool ignorews = false);

    Ptr<Document> ParseFile(const char* pfilename, FileOpenerBase* pfo, Ptr<ObjectManager> objMgr = 0);
    Ptr<Document> ParseString(const char* pdata, UPInt len, Ptr<ObjectManager> objMgr = 0);

    static void DropWhiteSpaceNodes(Document* document);

    void StartDocument();
    void EndDocument();
    void StartElement(const StringRef& prefix, const StringRef& localname, const ParserAttributes& atts);
    void EndElement(const StringRef& prefix, const StringRef& localname);
    void PrefixMapping(const StringRef& prefix, const StringRef& uri);
    void Characters(const StringRef& text);
    void IgnorableWhitespace(const StringRef& ws);
    void SkippedEntity(const StringRef& name);
    void SetDocumentLocator(const ParserLocator* plocator);
    void Comment(const StringRef& text);
    void Error(const ParserException& exception);
    void FatalError(const ParserException& exception);
    void Warning(const ParserException& exception);

    bool  IsError()             { return bError; }
    UPInt GetTotalBytesToLoad() { return TotalBytesToLoad; }
    UPInt GetLoadedBytes()      { return LoadedBytes; }

private:
    Ptr<SupportBase>     pXMLParserState;   // +0x10
    Ptr<TextNode>        pAppendChainRoot;  // +0x18: pending text node, text gathered in AppendText
    StringBuffer         AppendText;        // +0x20
    const ParserLocator* pLocator;          // +0x50
    Array<Ptr<ElementNode> > ParseStack;    // +0x58: open elements, the document at the bottom

    // A namespace binding and the element that declared it (Owner stays null until that element starts).
    struct PrefixOwnership
    {
        Ptr<Prefix>      mPrefix;
        Ptr<ElementNode> Owner;

        PrefixOwnership() : mPrefix(0), Owner(0) {}
        PrefixOwnership(Ptr<Prefix> pprefix, Ptr<ElementNode> pnode) : mPrefix(pprefix), Owner(pnode) {}
    };
    Array<PrefixOwnership> PrefixNamespaceStack;   // +0x70
    Array<PrefixOwnership> DefaultNamespaceStack;  // +0x88
    Ptr<Document>          pDoc;                   // +0xa0
    bool                   bIgnoreWhitespace;      // +0xa8
    bool                   bError;                 // +0xa9
    UPInt                  TotalBytesToLoad;       // +0xb0
    UPInt                  LoadedBytes;            // +0xb8
};

}}} // namespace Scaleform::GFx::XML

#endif
