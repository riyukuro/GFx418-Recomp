// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_17
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424ed890-0x142509d40 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

namespace Scaleform { namespace GFx { namespace AS3 {
// MS2-FUNCTIONAL: preserves the old Value's reference and class ownership; Release/SetKind/AddRef schedule
// the flag cleanup and retain separately from the exe's inlined sequence.
// @0x1424edb80
void Value::Assign(Class* v)
{
    Release();
    SetKind(kClass);
    value.VS._1.VClass = v;
    if (v)
        v->AddRef();
}
}}}

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {


}}} // namespace Scaleform::GFx::AS3
// THUNKS-END
