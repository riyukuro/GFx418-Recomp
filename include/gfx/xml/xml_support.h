// Recovered Scaleform 4.1.18 GFx XML: the loader state that owns the XML parser.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_XML_SUPPORT_H
#define MS2_SF_GFX_XML_SUPPORT_H

#include "../gfx_state.h"

namespace Scaleform { namespace GFx { namespace XML {

class ParserHandler;

class Parser : public RefCountBaseNTS<Parser, Stat_Default_Mem>
{
public:
    virtual ~Parser() {}
    virtual bool ParseFile(const char* pfilename, FileOpenerBase* pfo, ParserHandler* pphandler) = 0;
    virtual bool ParseString(const char* pdata, UPInt len, ParserHandler* pphandler) = 0;
};

// vtable 0x143109540: dtor, ParseFile (+8), ParseString (+0x10).
class SupportBase : public State
{
public:
    SupportBase() : State(State_XMLSupport) {}
    virtual ~SupportBase() {}
    virtual bool ParseFile(const char* pfilename, FileOpenerBase* pfo, ParserHandler* pdb) = 0;
    virtual bool ParseString(const char* pdata, UPInt len, ParserHandler* pdb) = 0;
};

}}} // namespace Scaleform::GFx::XML

#endif
