// Recovered Scaleform GFx 4.1.18 AS3: the class object of a user-defined (ABC-loaded) class.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
// From the constructor 0x1424dadb0 (vftable 0x14317f778, 26 slots, Class's size).
#ifndef MS2_SF_GFX_AS3_UDBASE_H
#define MS2_SF_GFX_AS3_UDBASE_H

#include "ms2/scaleform/include/gfx/as3/as3_obj.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Classes {

class UDBase : public Class
{
public:
    // Builds the class object, then lets the class traits finish it (slot values etc.). 0x1424dadb0
    UDBase(ClassTraits::Traits& t);
    // 0x1424e3d60 (deleting)
    virtual ~UDBase();

    // Sets up the instance's slot values. 0x14251cfd0
    virtual CheckResult PreInit(const Value& _this) const;
    // Only adds the constructor property. 0x142511880
    virtual void InitPrototype(AS3::Object& obj) const;
};

} // Classes

}}} // Scaleform::GFx::AS3

#endif
