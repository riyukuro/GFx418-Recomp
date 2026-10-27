// Recovered Scaleform 4.1.18 GFx XML: ParserExpat, the XML parser over the statically linked expat (GFx_XML_Expat).
// ParseFile / ParseString are in the Scaleform lib; the game's GFxManager (gfxui/gfxmanager.cpp) creates one for its
// XML support state and keeps the inline ctor and dtor as /Od COMDATs (0x1422b3550, 0x1422b3fb0).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_XML_EXPAT_H
#define MS2_SF_GFX_XML_EXPAT_H

#include "xml_support.h"

namespace Scaleform { namespace GFx { namespace XML {

class ParserExpat : public Parser
{
public:
    ParserExpat() {}

    virtual bool ParseFile(const char* pfilename, FileOpenerBase* pfo, ParserHandler* pparseHandler);
    virtual bool ParseString(const char* pdata, UPInt len, ParserHandler* pparseHandler);
};

}}} // namespace Scaleform::GFx::XML

#endif
