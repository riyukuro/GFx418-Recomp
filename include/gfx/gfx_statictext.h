// Recovered Scaleform GFx 4.1.18: StaticTextCharacter (DefineText instances). Shared header of the src/ms2/scaleform
// units (sfr lane). OPAQUE for now (size 0x180 and constructor); the full declaration comes with GFx_StaticText.
#ifndef MS2_SF_GFX_STATICTEXT_H
#define MS2_SF_GFX_STATICTEXT_H

#include "GFx/GFx_DisplayObject.h"

namespace Scaleform { namespace GFx {

class StaticTextDef;

class StaticTextCharacter
{
public:
    StaticTextCharacter(StaticTextDef* pdef, MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot,
                        InteractiveObject* pparent, ResourceId id);
    operator DisplayObjectBase*() { return reinterpret_cast<DisplayObjectBase*>(this); }
    UByte Data[0x180];
};

}} // namespace Scaleform::GFx

#endif
