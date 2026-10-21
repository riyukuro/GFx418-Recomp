// Recovered Scaleform 4.1.18 GFx: loader states and the movie-owned external library hook.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_STATE_H
#define MS2_SF_GFX_STATE_H

#include "../kernel/sf_refcount.h"

namespace Scaleform { namespace GFx {

class FileOpenerBase;
class MovieImpl;

// Base of everything stored in a StateBag; SType says which slot it fills.
class State : public RefCountBase<State, Stat_Default_Mem>
{
public:
    // Only the values confirmed in the exe so far (4.1.18 numbering differs from later SDKs).
    enum StateType
    {
        State_None         = 0,
        State_Log          = 2, // StateBag::SetLog / GetLog
        // The binding states MovieDefBindStates queries (table 0x1431891b8: 9, 10, 11, 15, 16, 23, 27, 28).
        State_FileOpener               = 9,
        State_URLBuilder               = 10,
        State_ImageCreator             = 11,
        State_ImageFileHandlerRegistry = 12,
        State_ImportVisitor            = 15,
        State_FontPackParams           = 16,
        State_FontLib                  = 17, // GFx::FontLib ctor stores 0x11
        State_BindState23              = 23, // binding state of 4.1.18 not identified yet
        State_FontCompactorParams      = 27,
        State_ImagePackerParams        = 28,
        State_FontProvider = 18, // GFx::FontProvider ctor stores 0x12
        State_FontMap      = 19, // GFx::FontMap ctor stores 0x13
        State_XMLSupport = 25, // XML::SupportBase ctor passes 0x19
        State_TaskManager  = 20, // LoaderImpl::CancelLoading queries 0x14
        State_TextClipboard = 21, // LoaderImpl ctor sets 0x15
        State_TextKeyMap    = 22, // LoaderImpl ctor sets 0x16
        State_ParseControl  = 13, // Loader::InitLoader sets 0xd
        State_ZlibSupport   = 26, // Loader::InitLoader sets 0x1a
        State_AS2Support    = 34, // MovieDefImpl::GetASSupport queries 0x22 / 0x23
        State_AS3Support    = 35,
        State_ActionControl = 3, // MovieDefImpl::CreateInstance sets it on the new movie
    };

protected:
    StateType SType;

public:
    State(StateType st = State_None) : SType(st) {}
    virtual ~State() {}

    StateType GetStateType() const { return SType; }
};

// Object owned by a library (XML, ...) that knows its MovieImpl; vtable 0x1432247b0.
class ExternalLibPtr
{
protected:
    MovieImpl* pOwner;

public:
    ExternalLibPtr(MovieImpl* powner) : pOwner(powner) {}
    virtual ~ExternalLibPtr() {}
};

}} // namespace Scaleform::GFx

#endif
