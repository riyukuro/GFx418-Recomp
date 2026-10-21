// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_06
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142438be0-0x142444560 .text$mn
// MS2-RANGE: 0x142445480-0x142446c10 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// Instances::fl_display::BitmapData::getColorBoundsRect argument 2 default
template <> struct ThunkMethodDefault<Instances::fl_display::BitmapData, 15, 2, bool>
{
    SF_INLINE static bool Get(StringManager&) { return true; }
};
// thunk 0x142438be0: Instances::fl_display::BitmapData::getColorBoundsRect
template struct ThunkFunc3<Instances::fl_display::BitmapData, 15, SPtr<Instances::fl_geom::Rectangle>, UInt32, UInt32, bool>;
// thunk 0x142438d50: Instances::fl_display::DisplayObject::transformSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 43, const Value, Instances::fl_geom::Transform*>;
// thunk 0x142438d90: Instances::fl_display::MovieClip::currentSceneGet
template struct ThunkFunc0<Instances::fl_display::MovieClip, 4, SPtr<Instances::fl_display::Scene>>;
// thunk 0x142438e40: Instances::fl_display::BitmapData::getPixel
template struct ThunkFunc2<Instances::fl_display::BitmapData, 16, UInt32, SInt32, SInt32>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// MS2-PIN: ?Func@?$ThunkFunc3@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0P@V?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@456@KK_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438be0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CL@$$CBVValue@456@PEAVTransform@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438d50
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$03V?$SPtr@VScene@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438d90
// MS2-PIN: ?Func@?$ThunkFunc2@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BA@KJJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438e40
