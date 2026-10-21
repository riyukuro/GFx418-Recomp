// Recovered Scaleform 4.1.18 GFx XML: SAX-style parser callback interface.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_XML_PARSER_H
#define MS2_SF_GFX_XML_PARSER_H

#include "../../kernel/sf_refcount.h"
#include "../../kernel/sf_string.h"

namespace Scaleform { namespace GFx { namespace XML {

typedef StringDataPtr StringRef;

struct ParserAttribute
{
    StringRef Name;
    StringRef Value;
};

struct ParserAttributes
{
    ParserAttribute* Attributes;
    UPInt            Length;
};

// Position and prolog data the parser exposes to its handler.
struct ParserLocator
{
    int       Column;
    int       Line;
    StringRef Encoding;          // +0x08
    StringRef XMLVersion;        // +0x18
    int       StandAlone;        // +0x28
    UPInt     TotalBytesToLoad;  // +0x30
    UPInt     LoadedBytes;       // +0x38

    ParserLocator() : StandAlone(-1) {}
};

struct ParserException
{
    StringRef ErrorMessage;

    ParserException(const StringRef& error) : ErrorMessage(error) {}
};

class ParserHandler : public RefCountBase<ParserHandler, StatMV_XML_Mem>
{
public:
    ParserHandler() {}
    virtual ~ParserHandler() {}

    virtual void StartDocument() = 0;
    virtual void EndDocument() = 0;
    virtual void StartElement(const StringRef& prefix, const StringRef& localname, const ParserAttributes& atts) = 0;
    virtual void EndElement(const StringRef& prefix, const StringRef& localname) = 0;
    virtual void PrefixMapping(const StringRef& prefix, const StringRef& uri) = 0;
    virtual void Characters(const StringRef& text) = 0;
    virtual void IgnorableWhitespace(const StringRef& ws) = 0;
    virtual void SkippedEntity(const StringRef& name) = 0;
    virtual void SetDocumentLocator(const ParserLocator* plocator) = 0;
    virtual void Comment(const StringRef& text) = 0;
    virtual void Error(const ParserException& exception) = 0;
    virtual void FatalError(const ParserException& exception) = 0;
    virtual void Warning(const ParserException& exception) = 0;
};

}}} // namespace Scaleform::GFx::XML

#endif
