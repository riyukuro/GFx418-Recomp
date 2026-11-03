// Recovered Scaleform GFx 4.1.18 pieces that no unit owned (own source, written from the exe; SDK material is reference
// only): the Expat parser's static callbacks that ParserExpat::ParseString (sfr_gfx_12) registers, and the one argument
// Format the parser's ParseFile reports a missing / empty file with.
// MS2-UNIT: sfr_gfx_12x
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423b14e0-0x1423b1912 .text$mn
// MS2-RANGE: 0x1423b1d40-0x1423b245e .text$mn
#include "../include/gfx/xml/xml_support.h"
#include "../include/gfx/xml/xml_parser.h"
#include "../include/kernel/sf_msgformat.h"
#include "hook/ms2hook.h"
#include <string.h>

// The Expat library linked into the exe (libgfxexpat, built static), as sfr_gfx_12 includes it.
#define XML_STATIC
#include "../third_party/src/expat-2.0.1/lib/expat.h"

using namespace Scaleform;
using namespace Scaleform::GFx::XML;

// The user data ParseString hands to Expat: the parser, the handler being fed and the locator it was given.
struct Unk_ParserExpatUserData
{
    void*          Parser;   // +0x00
    ParserHandler* Handler;  // +0x08
    ParserLocator* Locator;  // +0x10
};

// Copies Expat's current position into the locator before a handler call (column made one-based).
static inline void UpdateLocator(Unk_ParserExpatUserData* ud)
{
    XML_Parser     parser  = (XML_Parser)ud->Parser;
    ParserLocator* locator = ud->Locator;
    locator->Column      = XML_GetCurrentColumnNumber(parser) + 1;
    locator->Line        = XML_GetCurrentLineNumber(parser);
    locator->LoadedBytes = XML_GetCurrentByteIndex(parser);
}

// Splits a qualified name at its first ':' into prefix and local name (no ':' -> empty prefix, the whole name local).
static inline void SplitQName(const char* name, StringRef& prefix, StringRef& localname)
{
    const char* colon = strchr(name, ':');
    if (!colon)
        localname = StringRef(name);
    else
    {
        prefix    = StringRef(name, colon - name);
        localname = StringRef(colon + 1);
    }
}

// Formats one message into a small caller supplied buffer descriptor: the MsgFormat::Sink of a StringDataPtr
// (type 2, buffer, capacity), so ParseFile's declaration of it is kept.
struct Unk_XmlMsgBuffer { int Mode; char* Buffer; UPInt Capacity; };

// Format(sink, fmt, v1) with v1 a const char*.
// @0x1423b14e0
UPInt FUN_1423b14e0(Unk_XmlMsgBuffer* buffer, const char* fmt, const char** v1)
{
    return Format(*reinterpret_cast<const MsgFormat::Sink*>(buffer), fmt, *v1);
}

// Expat character data: the text (not terminated) and its length.
// @0x1423b1660
void FUN_1423b1660(void* userData, const char* s, int len)
{
    Unk_ParserExpatUserData* ud = (Unk_ParserExpatUserData*)userData;
    StringRef text(s, (UPInt)(SPInt)len);
    UpdateLocator(ud);
    ud->Handler->Characters(text);
}

// Expat comment: the terminated comment text.
// @0x1423b16d0
void FUN_1423b16d0(void* userData, const char* data)
{
    Unk_ParserExpatUserData* ud = (Unk_ParserExpatUserData*)userData;
    StringRef text(data);
    UpdateLocator(ud);
    ud->Handler->Comment(text);
}

// Expat default handler (the text nothing else handled, e.g. entity references): reported as a skipped entity.
// @0x1423b1760
void FUN_1423b1760(void* userData, const char* s, int len)
{
    Unk_ParserExpatUserData* ud = (Unk_ParserExpatUserData*)userData;
    StringRef text(s, (UPInt)(SPInt)len);
    UpdateLocator(ud);
    ud->Handler->SkippedEntity(text);
}

// Expat end element: the qualified name, split into prefix and local name.
// @0x1423b17d0
void FUN_1423b17d0(void* userData, const char* name)
{
    Unk_ParserExpatUserData* ud = (Unk_ParserExpatUserData*)userData;
    StringRef prefix, localname;
    SplitQName(name, prefix, localname);
    UpdateLocator(ud);
    ud->Handler->EndElement(prefix, localname);
}

// The locator update on its own (the callbacks inline it).
// @0x1423b18d0
void FUN_1423b18d0(void* userData)
{
    UpdateLocator((Unk_ParserExpatUserData*)userData);
}

// Expat start element: the qualified name and the null terminated name / value array. The attributes go into a
// 32 entry stack array (a heap array beyond that); every xmlns / xmlns:<prefix> attribute is also reported as a prefix
// mapping, before the element itself.
// @0x1423b1d40
void FUN_1423b1d40(void* userData, const char* name, const char** atts)
{
    Unk_ParserExpatUserData* ud = (Unk_ParserExpatUserData*)userData;

    ParserAttribute  astack[32];
    ParserAttributes attlist;

    UPInt sz         = 0;
    bool  attsInHeap = false;
    for (int i = 0; atts[i]; i += 2, sz++) {}
    attlist.Length = sz;

    if (sz > 32)
    {
        attlist.Attributes = new ParserAttribute[sz];
        attsInHeap         = true;
    }
    else
    {
        attlist.Attributes = astack;
    }

    int aidx = 0;
    for (UPInt i = 0; atts[i]; i += 2, aidx++)
    {
        attlist.Attributes[aidx].Name  = StringRef(atts[i]);
        attlist.Attributes[aidx].Value = StringRef(atts[i + 1]);

        // xmlns:<prefix> and xmlns attributes declare namespaces.
        const char* att = atts[i];
        if ((att[0] == 'x') && (att[1] == 'm') && (att[2] == 'l') && (att[3] == 'n') && (att[4] == 's'))
        {
            if (att[5] == ':')
            {
                ud->Handler->PrefixMapping(&att[6], atts[i + 1]);
            }
            else
            {
                if (strlen(att) == 5)
                {
                    ud->Handler->PrefixMapping(StringRef(), atts[i + 1]);
                }
            }
        }
    }

    StringRef   prefix;
    StringRef   localname;
    const char* delim = strchr(name, ':');
    if (delim == NULL)
    {
        localname = StringRef(name);
    }
    else
    {
        prefix    = StringRef(name, delim - name);
        localname = StringRef(delim + 1);
    }

    UpdateLocator(ud);
    ud->Handler->StartElement(prefix, localname, attlist);

    if (attsInHeap)
    {
        delete[] attlist.Attributes;
    }
}

// Expat XML declaration: version, encoding and standalone go into the locator.
// @0x1423b23e0
void FUN_1423b23e0(void* userData, const char* version, const char* encoding, int standalone)
{
    ParserLocator* locator = ((Unk_ParserExpatUserData*)userData)->Locator;
    locator->XMLVersion = StringRef(version);
    locator->Encoding   = StringRef(encoding);
    locator->StandAlone = standalone;
}
