// Recovered Scaleform 4.1.18 GFx: ASIMEManager, the reference-counted IME manager an AS support state creates
// (ASSupport::CreateASIMEManager). Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
// OPAQUE for now: only the AS3 support unit creates one (AS3::IMEManager, 0xe0 bytes, constructor in the
// AS3 IME code); its members come with the IME units.
#ifndef MS2_SF_GFX_ASIMEMANAGER_H
#define MS2_SF_GFX_ASIMEMANAGER_H

#include "ms2/scaleform/include/kernel/sf_refcount.h"

namespace Scaleform { namespace GFx {

enum { StatIME_Mem = (8 << 6) + 1 };   // StatGroup_GFxIME + 1

class ASIMEManager : public RefCountBase<ASIMEManager, StatIME_Mem>
{
};

}} // namespace Scaleform::GFx

#endif
