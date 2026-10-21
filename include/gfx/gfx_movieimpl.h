// Recovered Scaleform 4.1.18 GFx: the movie implementation (MovieImpl), as far as the recovered units call into it.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder. The bases (Movie :
// RefCountBase, StateBag) are not recovered yet; their words are kept as placeholders up to the members read.
#ifndef MS2_SF_GFX_MOVIEIMPL_H
#define MS2_SF_GFX_MOVIEIMPL_H

namespace Scaleform { namespace GFx {

class ASMovieRootBase;

class MovieImpl
{
public:
    void*            MovieBase_Unrecovered[3]; // +0x00 RefCountBase vftable + count, StateBag vftable
    ASMovieRootBase* pASMovieRoot;             // +0x18 Ptr<ASMovieRootBase>: the AVM specific root

    // Removes the setInterval/setTimeout timer with the given id (exe 0x14256e0d0).
    void ClearIntervalTimer(int id);
};

}} // namespace Scaleform::GFx

#endif
