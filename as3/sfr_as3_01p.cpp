// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 (gap recovery of sfr_as3_01):
// the scalar deleting destructor of AS3::Instance, which the exe keeps between the AS3_Obj_All blocks of sfr_as3_01c.
// MS2-UNIT: sfr_as3_01p
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423f3510-0x1423f3570 .text$mn

#include "ms2/scaleform/include/gfx/as3/as3_obj.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// The compiler emits ??_GInstance only next to the Instance vftable (the ctor/dtor units sfr_as3_15/16), so it is
// written out here: destroy, then free with the class delete (the global heap), or with the sized global delete when
// the caller asked for ::delete (flag 4).
// a free function in place of the compiler-generated ??_GInstance@AS3@GFx@Scaleform@@UEAAPEAXI@Z
// @0x1423f3510
void* InstanceScalarDeletingDtor(Instance* self, unsigned flags)
{
    self->Instance::~Instance();
    if (flags & 1)
    {
        if (!(flags & 4))
            Instance::operator delete(self);
        else
            ::operator delete(self, 0x38);
    }
    return self;
}

}}} // namespace Scaleform::GFx::AS3
