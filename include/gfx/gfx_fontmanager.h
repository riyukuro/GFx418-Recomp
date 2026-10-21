// Recovered Scaleform 4.1.18 GFx: FontManager, the per-movie font lookup (device fonts, the font library, the
// movie's own and imported fonts). Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Only the members called from recovered units so far; the class layout is not recovered yet.
#ifndef MS2_SF_GFX_FONTMANAGER_H
#define MS2_SF_GFX_FONTMANAGER_H

namespace Scaleform { namespace GFx {

class FontHandle;
class MovieImpl;
class MovieDefImpl;
class FontManagerStates;

class FontManager
{
public:
    // Font used by the IME candidate list window (0x14263db50, an ICF-folded body).
    void SetIMECandidateFont(FontHandle* pfont);

    // (appended for the containers, sfr_gfx_06d) the font manager of one root movie; 0x70 bytes,
    // reference counted (RefCountImpl) (0x14263b350).
    FontManager(MovieImpl* pmovie, MovieDefImpl* pdefImpl, FontManagerStates* pfontStates);
};

}} // namespace Scaleform::GFx

#endif
