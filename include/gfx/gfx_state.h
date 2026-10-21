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
        State_None       = 0,
        State_XMLSupport = 25, // XML::SupportBase ctor passes 0x19
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
