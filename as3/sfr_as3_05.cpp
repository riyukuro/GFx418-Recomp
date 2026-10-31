// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_05
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14242a640-0x142438be0 .text$mn
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_mnhash.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_thunkdefs.h"
#include <math.h>
#include <string.h>

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x14242b780: Instances::fl_display::DisplayObject::visibleGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 44, bool>;
// thunk 0x14242b7e0: Instances::fl_display::MovieClip::enabledGet
template struct ThunkFunc0<Instances::fl_display::MovieClip, 5, bool>;
// thunk 0x14242b840: Instances::fl_display::BitmapData::getPixel32
template struct ThunkFunc2<Instances::fl_display::BitmapData, 17, UInt32, SInt32, SInt32>;
// thunk 0x14242b940: Instances::fl_display::DisplayObject::visibleSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 45, const Value, bool>;
// thunk 0x14242b9a0: Instances::fl_display::MovieClip::enabledSet
template struct ThunkFunc1<Instances::fl_display::MovieClip, 6, const Value, bool>;
// thunk 0x14242ba00: Instances::fl_display::BitmapData::getPixels
template struct ThunkFunc1<Instances::fl_display::BitmapData, 18, SPtr<Instances::fl_utils::ByteArray>, Instances::fl_geom::Rectangle*>;
// thunk 0x14242baf0: Instances::fl_display::DisplayObject::widthGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 46, Value::Number>;
// thunk 0x14242bb60: Instances::fl_display::MovieClip::framesLoadedGet
template struct ThunkFunc0<Instances::fl_display::MovieClip, 7, SInt32>;
// thunk 0x14242bbc0: Instances::fl_display::BitmapData::getVector
template struct ThunkFunc1<Instances::fl_display::BitmapData, 19, SPtr<Instances::fl_vec::Vector_uint>, Instances::fl_geom::Rectangle*>;
// thunk 0x14242bcb0: Instances::fl_display::DisplayObject::widthSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 47, const Value, Value::Number>;
// thunk 0x14242bd40: Instances::fl_display::MovieClip::scenesGet
template struct ThunkFunc0<Instances::fl_display::MovieClip, 8, SPtr<Instances::fl::Array>>;
// Instances::fl_display::BitmapData::hitTest argument 4 default
template <> struct ThunkMethodDefault<Instances::fl_display::BitmapData, 20, 4, UInt32>
{
    SF_INLINE static UInt32 Get(StringManager&) { return 1; }
};
// thunk 0x14242bdf0: Instances::fl_display::BitmapData::hitTest
// MS2-FUNCTIONAL: not matched: the exe keeps r12 live as well (597 bytes against 581); same template body
template struct ThunkFunc5<Instances::fl_display::BitmapData, 20, bool, Instances::fl_geom::Point*, UInt32, const Value&, Instances::fl_geom::Point*, UInt32>;
// thunk 0x14242c050: Instances::fl_display::DisplayObject::xGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 48, Value::Number>;
// thunk 0x14242c0c0: Instances::fl_display::MovieClip::totalFramesGet
template struct ThunkFunc0<Instances::fl_display::MovieClip, 9, SInt32>;
// thunk 0x14242c120: Instances::fl_display::BitmapData::histogram
template struct ThunkFunc1<Instances::fl_display::BitmapData, 21, SPtr<Instances::fl::Object>, Instances::fl_geom::Rectangle*>;
// thunk 0x14242c210: Instances::fl_display::MovieClip::trackAsMenuGet
template struct ThunkFunc0<Instances::fl_display::MovieClip, 10, bool>;
// thunk 0x14242c270: Instances::fl_display::DisplayObject::xSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 49, const Value, Value::Number>;
// thunk 0x14242c300: Instances::fl_display::BitmapData::lock
template struct ThunkFunc0<Instances::fl_display::BitmapData, 22, const Value>;
// thunk 0x14242c320: Instances::fl_display::DisplayObject::yGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 50, Value::Number>;
// thunk 0x14242c390: Instances::fl_display::MovieClip::trackAsMenuSet
template struct ThunkFunc1<Instances::fl_display::MovieClip, 11, const Value, bool>;
// thunk 0x14242c3f0: Classes::fl_display::Stage::supportsOrientationChangeGet
template struct ThunkFunc0<Classes::fl_display::Stage, 0, bool>;
// thunk 0x14242c450: Instances::fl_display::BitmapData::merge
template struct ThunkFunc2<Instances::fl_display::BitmapData, 23, Value, unsigned, const Value*>;
// thunk 0x14242c470: Instances::fl_display::DisplayObject::ySet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 51, const Value, Value::Number>;
// thunk 0x14242c500: Instances::fl_display::MovieClip::addFrameScript
template struct ThunkFunc2<Instances::fl_display::MovieClip, 12, Value, unsigned, const Value*>;
// thunk 0x14242c520: Instances::fl_display::DisplayObject::zGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 52, Value::Number>;
// thunk 0x14242c590: Instances::fl_display::MovieClip::gotoAndPlay
template struct ThunkFunc2<Instances::fl_display::MovieClip, 13, const Value, const Value&, const Value&>;
// Instances::fl_display::BitmapData::noise argument 1 default
template <> struct ThunkMethodDefault<Instances::fl_display::BitmapData, 24, 1, UInt32>
{
    SF_INLINE static UInt32 Get(StringManager&) { return 0; }
};
// Instances::fl_display::BitmapData::noise argument 2 default
template <> struct ThunkMethodDefault<Instances::fl_display::BitmapData, 24, 2, UInt32>
{
    SF_INLINE static UInt32 Get(StringManager&) { return 255; }
};
// Instances::fl_display::BitmapData::noise argument 3 default
template <> struct ThunkMethodDefault<Instances::fl_display::BitmapData, 24, 3, UInt32>
{
    SF_INLINE static UInt32 Get(StringManager&) { return 7; }
};
// thunk 0x14242c670: Instances::fl_display::BitmapData::noise
template struct ThunkFunc5<Instances::fl_display::BitmapData, 24, const Value, SInt32, UInt32, UInt32, UInt32, bool>;
// thunk 0x14242c970: Instances::fl_display::DisplayObject::zSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 53, const Value, Value::Number>;
// thunk 0x14242ca00: Instances::fl_display::MovieClip::gotoAndStop
template struct ThunkFunc2<Instances::fl_display::MovieClip, 14, const Value, const Value&, const Value&>;
// thunk 0x14242cae0: Instances::fl_display::BitmapData::paletteMap
template struct ThunkFunc2<Instances::fl_display::BitmapData, 25, Value, unsigned, const Value*>;
// thunk 0x14242cb00: Instances::fl_display::DisplayObject::getBounds
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 54, SPtr<Instances::fl_geom::Rectangle>, Instances::fl_display::DisplayObject*>;
// thunk 0x14242cbf0: Instances::fl_display::MovieClip::nextFrame
template struct ThunkFunc0<Instances::fl_display::MovieClip, 15, const Value>;
// thunk 0x14242cc10: Instances::fl_display::BitmapData::perlinNoise
template struct ThunkFunc2<Instances::fl_display::BitmapData, 26, Value, unsigned, const Value*>;
// thunk 0x14242cc30: Instances::fl_display::DisplayObject::getRect
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 55, SPtr<Instances::fl_geom::Rectangle>, Instances::fl_display::DisplayObject*>;
// thunk 0x14242cd20: Instances::fl_display::MovieClip::nextScene
template struct ThunkFunc0<Instances::fl_display::MovieClip, 16, const Value>;
// thunk 0x14242cd40: Instances::fl_display::BitmapData::pixelDissolve
template struct ThunkFunc6<Instances::fl_display::BitmapData, 27, SInt32, Instances::fl_display::BitmapData*, Instances::fl_geom::Rectangle*, Instances::fl_geom::Point*, SInt32, SInt32, UInt32>;
// thunk 0x14242ced0: Instances::fl_display::MovieClip::play
template struct ThunkFunc0<Instances::fl_display::MovieClip, 17, const Value>;
// thunk 0x14242cef0: Instances::fl_display::DisplayObject::globalToLocal
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 56, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Point*>;
// thunk 0x14242cfe0: Instances::fl_display::BitmapData::scroll
template struct ThunkFunc2<Instances::fl_display::BitmapData, 28, const Value, SInt32, SInt32>;
// thunk 0x14242d090: Instances::fl_display::MovieClip::prevFrame
template struct ThunkFunc0<Instances::fl_display::MovieClip, 18, const Value>;
// thunk 0x14242d0b0: Instances::fl_display::DisplayObject::globalToLocal3D
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 57, SPtr<Instances::fl_geom::Vector3D>, Instances::fl_geom::Point*>;
// thunk 0x14242d1a0: Instances::fl_display::BitmapData::setPixel
template struct ThunkFunc3<Instances::fl_display::BitmapData, 29, const Value, SInt32, SInt32, UInt32>;
// thunk 0x14242d290: Instances::fl_display::MovieClip::prevScene
template struct ThunkFunc0<Instances::fl_display::MovieClip, 19, const Value>;
// thunk 0x14242d2b0: Instances::fl_display::DisplayObject::hitTestObject
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 58, bool, Instances::fl_display::DisplayObject*>;
// thunk 0x14242d4b0: Instances::fl_display::BitmapData::setPixel32
template struct ThunkFunc3<Instances::fl_display::BitmapData, 30, const Value, SInt32, SInt32, UInt32>;
// thunk 0x14242d5a0: Instances::fl_display::MovieClip::stop
template struct ThunkFunc0<Instances::fl_display::MovieClip, 20, const Value>;
// thunk 0x14242d5c0: Instances::fl_display::DisplayObject::hitTestPoint
template struct ThunkFunc3<Instances::fl_display::DisplayObject, 59, bool, Value::Number, Value::Number, bool>;
// thunk 0x14242d700: Instances::fl_display::BitmapData::setPixels
template struct ThunkFunc2<Instances::fl_display::BitmapData, 31, const Value, Instances::fl_geom::Rectangle*, Instances::fl_utils::ByteArray*>;
// thunk 0x14242d750: Instances::fl_display::DisplayObject::localToGlobal
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 60, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Point*>;
// thunk 0x14242d980: Instances::fl_display::BitmapData::setVector
template struct ThunkFunc2<Instances::fl_display::BitmapData, 32, const Value, Instances::fl_geom::Rectangle*, Instances::fl_vec::Vector_uint*>;
// thunk 0x14242d9d0: Instances::fl_display::DisplayObject::local3DToGlobal
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 61, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Vector3D*>;
// thunk 0x14242dac0: Instances::fl_display::FrameLabel::frameGet
template struct ThunkFunc0<Instances::fl_display::FrameLabel, 0, SInt32>;
// thunk 0x14242db20: Instances::fl_display::BitmapData::threshold
template struct ThunkFunc2<Instances::fl_display::BitmapData, 33, Value, unsigned, const Value*>;
// thunk 0x14242db40: Instances::fl_display::FrameLabel::nameGet
template struct ThunkFunc0<Instances::fl_display::FrameLabel, 1, ASString>;
// thunk 0x14242dbb0: Instances::fl_display::BitmapData::unlock
template struct ThunkFunc1<Instances::fl_display::BitmapData, 34, const Value, Instances::fl_geom::Rectangle*>;
// Instances::fl_display::Graphics::beginBitmapFill argument 2 default
template <> struct ThunkMethodDefault<Instances::fl_display::Graphics, 0, 2, bool>
{
    SF_INLINE static bool Get(StringManager&) { return true; }
};
// thunk 0x14242e520: Instances::fl_display::Graphics::beginBitmapFill
template struct ThunkFunc4<Instances::fl_display::Graphics, 0, const Value, Instances::fl_display::BitmapData*, Instances::fl_geom::Matrix*, bool, bool>;
// Instances::fl_display::Graphics::beginFill argument 1 default
template <> struct ThunkMethodDefault<Instances::fl_display::Graphics, 1, 1, Value::Number>
{
    SF_INLINE static Value::Number Get(StringManager&) { return 1.0; }
};
// thunk 0x14242e610: Instances::fl_display::Graphics::beginFill
template struct ThunkFunc2<Instances::fl_display::Graphics, 1, const Value, UInt32, Value::Number>;
// thunk 0x14242e6c0: Instances::fl_display::Graphics::beginGradientFill
template struct ThunkFunc2<Instances::fl_display::Graphics, 2, Value, unsigned, const Value*>;
// thunk 0x14242e6e0: Instances::fl_display::Graphics::clear
template struct ThunkFunc0<Instances::fl_display::Graphics, 3, const Value>;
// thunk 0x14242e700: Instances::fl_display::Graphics::curveTo
template struct ThunkFunc4<Instances::fl_display::Graphics, 4, const Value, Value::Number, Value::Number, Value::Number, Value::Number>;
// thunk 0x14242e880: Instances::fl_display::Graphics::drawCircle
template struct ThunkFunc3<Instances::fl_display::Graphics, 5, const Value, Value::Number, Value::Number, Value::Number>;
// thunk 0x14242e9b0: Instances::fl_display::Graphics::drawEllipse
template struct ThunkFunc4<Instances::fl_display::Graphics, 6, const Value, Value::Number, Value::Number, Value::Number, Value::Number>;
// thunk 0x14242ec90: Instances::fl_display::Graphics::drawRect
template struct ThunkFunc4<Instances::fl_display::Graphics, 7, const Value, Value::Number, Value::Number, Value::Number, Value::Number>;
// thunk 0x14242ee10: Instances::fl_display::Graphics::drawRoundRect
template struct ThunkFunc6<Instances::fl_display::Graphics, 8, const Value, Value::Number, Value::Number, Value::Number, Value::Number, Value::Number, Value::Number>;
// thunk 0x14242eff0: Instances::fl_display::Graphics::drawRoundRectComplex
template struct ThunkFunc2<Instances::fl_display::Graphics, 9, Value, unsigned, const Value*>;
// thunk 0x14242f010: Instances::fl_display::Graphics::endFill
template struct ThunkFunc0<Instances::fl_display::Graphics, 10, const Value>;
// thunk 0x14242f030: Instances::fl_display::Graphics::lineGradientStyle
template struct ThunkFunc2<Instances::fl_display::Graphics, 11, Value, unsigned, const Value*>;
// thunk 0x14242f050: Instances::fl_display::Scene::labelsGet
template struct ThunkFunc0<Instances::fl_display::Scene, 0, SPtr<Instances::fl::Array>>;
// thunk 0x14242f100: Instances::fl_display::Graphics::lineStyle
template struct ThunkFunc2<Instances::fl_display::Graphics, 12, Value, unsigned, const Value*>;
// thunk 0x14242f120: Instances::fl_display::Scene::nameGet
template struct ThunkFunc0<Instances::fl_display::Scene, 1, ASString>;
// thunk 0x14242f190: Instances::fl_display::Graphics::lineTo
template struct ThunkFunc2<Instances::fl_display::Graphics, 13, const Value, Value::Number, Value::Number>;
// thunk 0x14242f270: Instances::fl_display::Scene::numFramesGet
template struct ThunkFunc0<Instances::fl_display::Scene, 2, SInt32>;
// thunk 0x14242f2d0: Instances::fl_display::Graphics::moveTo
template struct ThunkFunc2<Instances::fl_display::Graphics, 14, const Value, Value::Number, Value::Number>;
// thunk 0x14242f4f0: Instances::fl_display::Shape::graphicsGet
template struct ThunkFunc0<Instances::fl_display::Shape, 0, SPtr<Instances::fl_display::Graphics>>;
// thunk 0x14242f700: Instances::fl_display::Bitmap::bitmapDataGet
template struct ThunkFunc0<Instances::fl_display::Bitmap, 0, SPtr<Instances::fl_display::BitmapData>>;
// thunk 0x14242f7b0: Instances::fl_display::Bitmap::bitmapDataSet
template struct ThunkFunc1<Instances::fl_display::Bitmap, 1, const Value, Instances::fl_display::BitmapData*>;
// thunk 0x14242f950: Instances::fl_display::InteractiveObject::contextMenuGet
template struct ThunkFunc0<Instances::fl_display::InteractiveObject, 0, SPtr<Instances::fl::Object>>;
// thunk 0x14242fa00: Instances::fl_display::Bitmap::pixelSnappingGet
template struct ThunkFunc0<Instances::fl_display::Bitmap, 2, ASString>;
// thunk 0x14242fa70: Instances::fl_display::InteractiveObject::contextMenuSet
template struct ThunkFunc1<Instances::fl_display::InteractiveObject, 1, const Value, const Value&>;
// thunk 0x14242fbc0: Instances::fl_display::Bitmap::pixelSnappingSet
template struct ThunkFunc1<Instances::fl_display::Bitmap, 3, const Value, const ASString&>;
// thunk 0x14242fcc0: Instances::fl_display::InteractiveObject::doubleClickEnabledGet
template struct ThunkFunc0<Instances::fl_display::InteractiveObject, 2, bool>;
// thunk 0x14242fd20: Instances::fl_display::Bitmap::smoothingGet
template struct ThunkFunc0<Instances::fl_display::Bitmap, 4, bool>;
// thunk 0x14242fd80: Instances::fl_display::InteractiveObject::doubleClickEnabledSet
template struct ThunkFunc1<Instances::fl_display::InteractiveObject, 3, const Value, bool>;
// thunk 0x14242ff20: Instances::fl_display::Bitmap::smoothingSet
template struct ThunkFunc1<Instances::fl_display::Bitmap, 5, const Value, bool>;
// thunk 0x14242ff80: Instances::fl_display::InteractiveObject::focusRectGet
template struct ThunkFunc0<Instances::fl_display::InteractiveObject, 4, Value>;
// thunk 0x14242ffa0: Instances::fl_display::InteractiveObject::focusRectSet
template struct ThunkFunc1<Instances::fl_display::InteractiveObject, 5, const Value, const Value&>;
// thunk 0x1424300f0: Instances::fl_display::InteractiveObject::mouseEnabledGet
template struct ThunkFunc0<Instances::fl_display::InteractiveObject, 6, bool>;
// thunk 0x142430150: Instances::fl_display::InteractiveObject::mouseEnabledSet
template struct ThunkFunc1<Instances::fl_display::InteractiveObject, 7, const Value, bool>;
// thunk 0x1424301b0: Instances::fl_display::InteractiveObject::tabEnabledGet
template struct ThunkFunc0<Instances::fl_display::InteractiveObject, 8, bool>;
// thunk 0x142430210: Instances::fl_display::InteractiveObject::tabEnabledSet
template struct ThunkFunc1<Instances::fl_display::InteractiveObject, 9, const Value, bool>;
// thunk 0x142430270: Instances::fl_display::InteractiveObject::tabIndexGet
template struct ThunkFunc0<Instances::fl_display::InteractiveObject, 10, SInt32>;
// thunk 0x1424302d0: Instances::fl_display::InteractiveObject::tabIndexSet
template struct ThunkFunc1<Instances::fl_display::InteractiveObject, 11, const Value, SInt32>;
// thunk 0x142430e00: Instances::fl_display::Loader::contentGet
template struct ThunkFunc0<Instances::fl_display::Loader, 0, SPtr<Instances::fl_display::DisplayObject>>;
// thunk 0x142430eb0: Instances::fl_display::Loader::contentLoaderInfoGet
template struct ThunkFunc0<Instances::fl_display::Loader, 1, SPtr<Instances::fl_display::LoaderInfo>>;
// thunk 0x142430f60: Instances::fl_display::Loader::close
template struct ThunkFunc0<Instances::fl_display::Loader, 2, const Value>;
// thunk 0x142430f80: Instances::fl_display::Loader::load
template struct ThunkFunc2<Instances::fl_display::Loader, 3, const Value, Instances::fl_net::URLRequest*, Instances::fl_system::LoaderContext*>;
// thunk 0x142431120: Instances::fl_display::Loader::loadBytes
template struct ThunkFunc2<Instances::fl_display::Loader, 4, const Value, Instances::fl_utils::ByteArray*, Instances::fl_system::LoaderContext*>;
// thunk 0x142431170: Instances::fl_display::Loader::unload
template struct ThunkFunc0<Instances::fl_display::Loader, 5, const Value>;
// Instances::fl_display::Loader::unloadAndStop argument 0 default
template <> struct ThunkMethodDefault<Instances::fl_display::Loader, 6, 0, bool>
{
    SF_INLINE static bool Get(StringManager&) { return true; }
};
// thunk 0x142431190: Instances::fl_display::Loader::unloadAndStop
template struct ThunkFunc1<Instances::fl_display::Loader, 6, const Value, bool>;
// thunk 0x1424311f0: Instances::fl_display::SimpleButton::downStateGet
template struct ThunkFunc0<Instances::fl_display::SimpleButton, 0, SPtr<Instances::fl_display::DisplayObject>>;
// thunk 0x1424312a0: Instances::fl_display::SimpleButton::downStateSet
template struct ThunkFunc1<Instances::fl_display::SimpleButton, 1, const Value, Instances::fl_display::DisplayObject*>;
// thunk 0x1424312e0: Instances::fl_display::SimpleButton::enabledGet
template struct ThunkFunc0<Instances::fl_display::SimpleButton, 2, bool>;
// thunk 0x142431340: Instances::fl_display::SimpleButton::enabledSet
template struct ThunkFunc1<Instances::fl_display::SimpleButton, 3, const Value, bool>;
// thunk 0x1424313a0: Instances::fl_display::SimpleButton::hitTestStateGet
template struct ThunkFunc0<Instances::fl_display::SimpleButton, 4, SPtr<Instances::fl_display::DisplayObject>>;
// thunk 0x142431450: Instances::fl_display::SimpleButton::hitTestStateSet
template struct ThunkFunc1<Instances::fl_display::SimpleButton, 5, const Value, Instances::fl_display::DisplayObject*>;
// thunk 0x142431490: Instances::fl_display::SimpleButton::overStateGet
template struct ThunkFunc0<Instances::fl_display::SimpleButton, 6, SPtr<Instances::fl_display::DisplayObject>>;
// thunk 0x142431540: Instances::fl_display::SimpleButton::overStateSet
template struct ThunkFunc1<Instances::fl_display::SimpleButton, 7, const Value, Instances::fl_display::DisplayObject*>;
// thunk 0x142431580: Instances::fl_display::SimpleButton::soundTransformGet
template struct ThunkFunc0<Instances::fl_display::SimpleButton, 8, SPtr<Instances::fl_media::SoundTransform>>;
// thunk 0x142431630: Instances::fl_display::SimpleButton::soundTransformSet
template struct ThunkFunc1<Instances::fl_display::SimpleButton, 9, const Value, Instances::fl_media::SoundTransform*>;
// thunk 0x142431670: Instances::fl_display::SimpleButton::trackAsMenuGet
template struct ThunkFunc0<Instances::fl_display::SimpleButton, 10, bool>;
// thunk 0x1424316d0: Instances::fl_display::SimpleButton::trackAsMenuSet
template struct ThunkFunc1<Instances::fl_display::SimpleButton, 11, const Value, bool>;
// thunk 0x142431730: Instances::fl_display::SimpleButton::upStateGet
template struct ThunkFunc0<Instances::fl_display::SimpleButton, 12, SPtr<Instances::fl_display::DisplayObject>>;
// thunk 0x1424317e0: Instances::fl_display::SimpleButton::upStateSet
template struct ThunkFunc1<Instances::fl_display::SimpleButton, 13, const Value, Instances::fl_display::DisplayObject*>;
// thunk 0x142431820: Instances::fl_display::SimpleButton::useHandCursorGet
template struct ThunkFunc0<Instances::fl_display::SimpleButton, 14, bool>;
// thunk 0x142431880: Instances::fl_display::SimpleButton::useHandCursorSet
template struct ThunkFunc1<Instances::fl_display::SimpleButton, 15, const Value, bool>;
// thunk 0x142431cd0: Instances::fl_display::Sprite::buttonModeGet
template struct ThunkFunc0<Instances::fl_display::Sprite, 0, bool>;
// thunk 0x142431d30: Instances::fl_display::Sprite::buttonModeSet
template struct ThunkFunc1<Instances::fl_display::Sprite, 1, const Value, bool>;
// thunk 0x142431d90: Instances::fl_display::Sprite::dropTargetGet
template struct ThunkFunc0<Instances::fl_display::Sprite, 2, SPtr<Instances::fl_display::DisplayObject>>;
// thunk 0x142431e40: Instances::fl_display::Sprite::graphicsGet
template struct ThunkFunc0<Instances::fl_display::Sprite, 3, SPtr<Instances::fl_display::Graphics>>;
// thunk 0x142431ef0: Instances::fl_display::Sprite::hitAreaGet
template struct ThunkFunc0<Instances::fl_display::Sprite, 4, SPtr<Instances::fl_display::Sprite>>;
// thunk 0x142431fa0: Instances::fl_display::Sprite::hitAreaSet
template struct ThunkFunc1<Instances::fl_display::Sprite, 5, const Value, Instances::fl_display::Sprite*>;
// thunk 0x142431fe0: Instances::fl_display::Sprite::soundTransformGet
template struct ThunkFunc0<Instances::fl_display::Sprite, 6, SPtr<Instances::fl_media::SoundTransform>>;
// thunk 0x142432090: Instances::fl_display::Sprite::soundTransformSet
template struct ThunkFunc1<Instances::fl_display::Sprite, 7, const Value, Instances::fl_media::SoundTransform*>;
// thunk 0x1424320d0: Instances::fl_display::Sprite::useHandCursorGet
template struct ThunkFunc0<Instances::fl_display::Sprite, 8, bool>;
// thunk 0x142432130: Instances::fl_display::Sprite::useHandCursorSet
template struct ThunkFunc1<Instances::fl_display::Sprite, 9, const Value, bool>;
// thunk 0x142432190: Instances::fl_display::Sprite::startDrag
template struct ThunkFunc2<Instances::fl_display::Sprite, 10, const Value, bool, Instances::fl_geom::Rectangle*>;
// thunk 0x142432210: Instances::fl_display::LoaderInfo::actionScriptVersionGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 0, UInt32>;
// thunk 0x142432270: Instances::fl_display::Sprite::stopDrag
template struct ThunkFunc0<Instances::fl_display::Sprite, 11, const Value>;
// thunk 0x142432290: Instances::fl_display::LoaderInfo::applicationDomainGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 1, SPtr<Instances::fl_system::ApplicationDomain>>;
// thunk 0x142432340: Instances::fl_display::LoaderInfo::bytesGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 2, SPtr<Instances::fl_utils::ByteArray>>;
// thunk 0x1424323f0: Instances::fl_display::LoaderInfo::bytesLoadedGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 3, UInt32>;
// thunk 0x142432450: Instances::fl_display::LoaderInfo::bytesTotalGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 4, UInt32>;
// thunk 0x1424324b0: Instances::fl_display::LoaderInfo::childAllowsParentGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 5, bool>;
// thunk 0x142432510: Instances::fl_display::LoaderInfo::childSandboxBridgeGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 6, SPtr<Instances::fl::Object>>;
// thunk 0x1424325c0: Instances::fl_display::LoaderInfo::childSandboxBridgeSet
template struct ThunkFunc1<Instances::fl_display::LoaderInfo, 7, const Value, const Value&>;
// thunk 0x142432710: Instances::fl_display::LoaderInfo::contentGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 8, SPtr<Instances::fl_display::DisplayObject>>;
// thunk 0x1424327c0: Instances::fl_display::LoaderInfo::contentTypeGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 9, ASString>;
// thunk 0x142432830: Instances::fl_display::LoaderInfo::frameRateGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 10, Value::Number>;
// thunk 0x1424328a0: Instances::fl_display::LoaderInfo::heightGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 11, SInt32>;
// thunk 0x142432900: Instances::fl_display::LoaderInfo::loaderGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 12, SPtr<Instances::fl_display::Loader>>;
// thunk 0x1424329b0: Instances::fl_display::LoaderInfo::loaderURLGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 13, ASString>;
// thunk 0x142432a20: Instances::fl_display::LoaderInfo::parametersGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 14, SPtr<Instances::fl::Object>>;
// thunk 0x142432cc0: Instances::fl_display::Stage::alignGet
template struct ThunkFunc0<Instances::fl_display::Stage, 0, ASString>;
// thunk 0x142432d30: Instances::fl_display::LoaderInfo::parentAllowsChildGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 15, bool>;
// thunk 0x142432d90: Instances::fl_display::Stage::alignSet
template struct ThunkFunc1<Instances::fl_display::Stage, 1, const Value, const ASString&>;
// thunk 0x142432e90: Instances::fl_display::LoaderInfo::parentSandboxBridgeGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 16, SPtr<Instances::fl::Object>>;
// thunk 0x142432f40: Instances::fl_display::Stage::autoOrientsGet
template struct ThunkFunc0<Instances::fl_display::Stage, 2, bool>;
// thunk 0x142432fa0: Instances::fl_display::LoaderInfo::parentSandboxBridgeSet
template struct ThunkFunc1<Instances::fl_display::LoaderInfo, 17, const Value, const Value&>;
// thunk 0x1424330f0: Instances::fl_display::Stage::deviceOrientationGet
template struct ThunkFunc0<Instances::fl_display::Stage, 3, ASString>;
// thunk 0x142433160: Instances::fl_display::LoaderInfo::sameDomainGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 18, bool>;
// thunk 0x1424331c0: Instances::fl_display::Stage::displayStateGet
template struct ThunkFunc0<Instances::fl_display::Stage, 4, ASString>;
// thunk 0x142433230: Instances::fl_display::LoaderInfo::sharedEventsGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 19, SPtr<Instances::fl_events::EventDispatcher>>;
// thunk 0x1424332e0: Instances::fl_display::Stage::displayStateSet
template struct ThunkFunc1<Instances::fl_display::Stage, 5, const Value, const ASString&>;
// thunk 0x1424333e0: Instances::fl_display::LoaderInfo::swfVersionGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 20, UInt32>;
// thunk 0x142433440: Instances::fl_display::Stage::focusGet
template struct ThunkFunc0<Instances::fl_display::Stage, 6, SPtr<Instances::fl_display::InteractiveObject>>;
// thunk 0x1424334f0: Instances::fl_display::LoaderInfo::urlGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 21, ASString>;
// thunk 0x142433560: Instances::fl_display::Stage::focusSet
template struct ThunkFunc1<Instances::fl_display::Stage, 7, const Value, Instances::fl_display::InteractiveObject*>;
// thunk 0x1424335a0: Instances::fl_display::LoaderInfo::widthGet
template struct ThunkFunc0<Instances::fl_display::LoaderInfo, 22, SInt32>;
// thunk 0x142433600: Instances::fl_display::Stage::frameRateGet
template struct ThunkFunc0<Instances::fl_display::Stage, 8, Value::Number>;
// thunk 0x142433670: Instances::fl_display::Stage::frameRateSet
template struct ThunkFunc1<Instances::fl_display::Stage, 9, const Value, Value::Number>;
// thunk 0x142433700: Instances::fl_display::Stage::fullScreenHeightGet
template struct ThunkFunc0<Instances::fl_display::Stage, 10, UInt32>;
// thunk 0x142433760: Instances::fl_display::Stage::fullScreenSourceRectGet
template struct ThunkFunc0<Instances::fl_display::Stage, 11, SPtr<Instances::fl_geom::Rectangle>>;
// thunk 0x142433810: Instances::fl_display::Stage::fullScreenSourceRectSet
template struct ThunkFunc1<Instances::fl_display::Stage, 12, const Value, Instances::fl_geom::Rectangle*>;
// thunk 0x142433850: Instances::fl_display::Stage::fullScreenWidthGet
template struct ThunkFunc0<Instances::fl_display::Stage, 13, UInt32>;
// thunk 0x1424338b0: Instances::fl_display::Stage::heightGet
template struct ThunkFunc0<Instances::fl_display::Stage, 14, Value::Number>;
// thunk 0x142433920: Instances::fl_display::Stage::heightSet
template struct ThunkFunc1<Instances::fl_display::Stage, 15, const Value, Value::Number>;
// thunk 0x1424339b0: Instances::fl_display::Stage::mouseChildrenGet
template struct ThunkFunc0<Instances::fl_display::Stage, 16, bool>;
// thunk 0x142433a10: Instances::fl_display::Stage::mouseChildrenSet
template struct ThunkFunc1<Instances::fl_display::Stage, 17, const Value, bool>;
// thunk 0x142433a70: Instances::fl_display::Stage::numChildrenGet
template struct ThunkFunc0<Instances::fl_display::Stage, 18, SInt32>;
// thunk 0x142433ad0: Classes::fl_display::LoaderInfo::getLoaderInfoByDefinition
template struct ThunkFunc1<Classes::fl_display::LoaderInfo, 0, SPtr<Instances::fl_display::LoaderInfo>, const Value&>;
// thunk 0x142433c90: Instances::fl_display::Stage::orientationGet
template struct ThunkFunc0<Instances::fl_display::Stage, 19, ASString>;
// thunk 0x142433d00: Instances::fl_display::Stage::qualityGet
template struct ThunkFunc0<Instances::fl_display::Stage, 20, ASString>;
// thunk 0x142433d70: Instances::fl_display::DisplayObject::accessibilityPropertiesGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 0, SPtr<Instances::fl_accessibility::AccessibilityProperties>>;
// thunk 0x142433e20: Instances::fl_display::Stage::qualitySet
template struct ThunkFunc1<Instances::fl_display::Stage, 21, const Value, const ASString&>;
// thunk 0x142433f20: Instances::fl_display::DisplayObject::accessibilityPropertiesSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 1, const Value, Instances::fl_accessibility::AccessibilityProperties*>;
// thunk 0x142433f60: Instances::fl_display::Stage::scaleModeGet
template struct ThunkFunc0<Instances::fl_display::Stage, 22, ASString>;
// thunk 0x142433fd0: Instances::fl_display::DisplayObject::alphaGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 2, Value::Number>;
// thunk 0x142434040: Instances::fl_display::Stage::scaleModeSet
template struct ThunkFunc1<Instances::fl_display::Stage, 23, const Value, const ASString&>;
// thunk 0x142434140: Instances::fl_display::DisplayObject::alphaSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 3, const Value, Value::Number>;
// thunk 0x1424341d0: Instances::fl_display::Stage::showDefaultContextMenuGet
template struct ThunkFunc0<Instances::fl_display::Stage, 24, bool>;
// thunk 0x142434230: Instances::fl_display::DisplayObject::blendModeGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 4, ASString>;
// thunk 0x1424342a0: Instances::fl_display::Stage::showDefaultContextMenuSet
template struct ThunkFunc1<Instances::fl_display::Stage, 25, const Value, bool>;
// thunk 0x142434300: Instances::fl_display::DisplayObject::blendModeSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 5, const Value, const ASString&>;
// thunk 0x142434540: Instances::fl_display::Stage::stageFocusRectGet
template struct ThunkFunc0<Instances::fl_display::Stage, 26, bool>;
// thunk 0x1424345a0: Instances::fl_display::DisplayObject::cacheAsBitmapGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 6, bool>;
// thunk 0x142434600: Instances::fl_display::Stage::stageFocusRectSet
template struct ThunkFunc1<Instances::fl_display::Stage, 27, const Value, bool>;
// thunk 0x142434660: Instances::fl_display::DisplayObject::cacheAsBitmapSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 7, const Value, bool>;
// thunk 0x1424346c0: Instances::fl_display::Stage::stageHeightGet
template struct ThunkFunc0<Instances::fl_display::Stage, 28, SInt32>;
// thunk 0x142434720: Instances::fl_display::DisplayObject::filtersGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 8, SPtr<Instances::fl::Array>>;
// thunk 0x142434830: Instances::fl_display::Stage::stageHeightSet
template struct ThunkFunc1<Instances::fl_display::Stage, 29, const Value, SInt32>;
// thunk 0x1424348a0: Instances::fl_display::DisplayObject::filtersSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 9, const Value, Instances::fl::Array*>;
// thunk 0x1424348e0: Instances::fl_display::Stage::stageWidthGet
template struct ThunkFunc0<Instances::fl_display::Stage, 30, SInt32>;
// thunk 0x142434940: Instances::fl_display::DisplayObject::heightGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 10, Value::Number>;
// thunk 0x1424349b0: Instances::fl_display::Stage::stageWidthSet
template struct ThunkFunc1<Instances::fl_display::Stage, 31, const Value, SInt32>;
// thunk 0x142434a20: Instances::fl_display::DisplayObject::heightSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 11, const Value, Value::Number>;
// thunk 0x142434ab0: Instances::fl_display::Stage::tabChildrenGet
template struct ThunkFunc0<Instances::fl_display::Stage, 32, bool>;
// thunk 0x142434b10: Instances::fl_display::DisplayObject::loaderInfoGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 12, SPtr<Instances::fl_display::LoaderInfo>>;
// thunk 0x142434bc0: Instances::fl_display::DisplayObjectContainer::mouseChildrenGet
template struct ThunkFunc0<Instances::fl_display::DisplayObjectContainer, 0, bool>;
// thunk 0x142434c20: Instances::fl_display::DisplayObject::maskGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 13, SPtr<Instances::fl_display::DisplayObject>>;
// thunk 0x142434cd0: Instances::fl_display::Stage::tabChildrenSet
template struct ThunkFunc1<Instances::fl_display::Stage, 33, const Value, bool>;
// thunk 0x142434d30: Instances::fl_display::DisplayObjectContainer::mouseChildrenSet
template struct ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 1, const Value, bool>;
// thunk 0x142434d90: Instances::fl_display::Stage::textSnapshotGet
template struct ThunkFunc0<Instances::fl_display::Stage, 34, SPtr<Instances::fl_text::TextSnapshot>>;
// thunk 0x142434e40: Instances::fl_display::DisplayObject::maskSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 14, const Value, Instances::fl_display::DisplayObject*>;
// thunk 0x142434e80: Instances::fl_display::DisplayObjectContainer::numChildrenGet
template struct ThunkFunc0<Instances::fl_display::DisplayObjectContainer, 2, SInt32>;
// thunk 0x142434ee0: Instances::fl_display::Stage::widthGet
template struct ThunkFunc0<Instances::fl_display::Stage, 35, Value::Number>;
// thunk 0x142434f50: Instances::fl_display::DisplayObject::mouseXGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 15, Value::Number>;
// thunk 0x142434fc0: Instances::fl_display::DisplayObjectContainer::tabChildrenGet
template struct ThunkFunc0<Instances::fl_display::DisplayObjectContainer, 3, bool>;
// thunk 0x142435020: Instances::fl_display::DisplayObject::mouseYGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 16, Value::Number>;
// thunk 0x142435090: Instances::fl_display::Stage::widthSet
template struct ThunkFunc1<Instances::fl_display::Stage, 36, const Value, Value::Number>;
// thunk 0x142435120: Instances::fl_display::DisplayObjectContainer::tabChildrenSet
template struct ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 4, const Value, bool>;
// thunk 0x1424352c0: Instances::fl_display::DisplayObject::nameGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 17, ASString>;
// thunk 0x142435330: Instances::fl_display::Stage::addChild
template struct ThunkFunc1<Instances::fl_display::Stage, 37, SPtr<Instances::fl_display::DisplayObject>, Instances::fl_display::DisplayObject*>;
// thunk 0x142435420: Instances::fl_display::DisplayObjectContainer::textSnapshotGet
template struct ThunkFunc0<Instances::fl_display::DisplayObjectContainer, 5, SPtr<Instances::fl_text::TextSnapshot>>;
// thunk 0x142435610: Instances::fl_display::DisplayObject::nameSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 18, const Value, const ASString&>;
// thunk 0x142435710: Instances::fl_display::Stage::addChildAt
template struct ThunkFunc2<Instances::fl_display::Stage, 38, SPtr<Instances::fl_display::DisplayObject>, Instances::fl_display::DisplayObject*, SInt32>;
// thunk 0x142435830: Instances::fl_display::DisplayObjectContainer::addChild
template struct ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 6, SPtr<Instances::fl_display::DisplayObject>, Instances::fl_display::DisplayObject*>;
// thunk 0x142435920: Instances::fl_display::DisplayObject::opaqueBackgroundGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 19, SPtr<Instances::fl::Object>>;
// thunk 0x1424359d0: Instances::fl_display::DisplayObjectContainer::addChildAt
template struct ThunkFunc2<Instances::fl_display::DisplayObjectContainer, 7, SPtr<Instances::fl_display::DisplayObject>, Instances::fl_display::DisplayObject*, SInt32>;
// thunk 0x142435af0: Instances::fl_display::Stage::addEventListener
template struct ThunkFunc5<Instances::fl_display::Stage, 39, const Value, const ASString&, const Value&, bool, SInt32, bool>;
// thunk 0x142435d90: Instances::fl_display::DisplayObject::opaqueBackgroundSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 20, const Value, const Value&>;
// thunk 0x142435ee0: Instances::fl_display::DisplayObjectContainer::areInaccessibleObjectsUnderPoint
template struct ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 8, bool, Instances::fl_geom::Point*>;
// thunk 0x142435f80: Instances::fl_display::Stage::assignFocus
template struct ThunkFunc2<Instances::fl_display::Stage, 40, const Value, Instances::fl_display::InteractiveObject*, const ASString&>;
// thunk 0x1424360b0: Instances::fl_display::DisplayObject::parentGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 21, SPtr<Instances::fl_display::DisplayObjectContainer>>;
// thunk 0x142436160: Instances::fl_display::DisplayObjectContainer::contains
template struct ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 9, bool, Instances::fl_display::DisplayObject*>;
// thunk 0x142436200: Instances::fl_display::Stage::dispatchEvent
template struct ThunkFunc1<Instances::fl_display::Stage, 41, bool, Instances::fl_events::Event*>;
// thunk 0x1424362a0: Instances::fl_display::DisplayObject::rootGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 22, SPtr<Instances::fl_display::DisplayObject>>;
// thunk 0x142436350: Instances::fl_display::DisplayObjectContainer::getChildAt
template struct ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 10, SPtr<Instances::fl_display::DisplayObject>, SInt32>;
// thunk 0x142436450: Instances::fl_display::Stage::hasEventListener
template struct ThunkFunc1<Instances::fl_display::Stage, 42, bool, const ASString&>;
// thunk 0x142436590: Instances::fl_display::DisplayObject::rotationGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 23, Value::Number>;
// thunk 0x142436600: Instances::fl_display::DisplayObjectContainer::getChildByName
template struct ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 11, SPtr<Instances::fl_display::DisplayObject>, const ASString&>;
// thunk 0x142436780: Instances::fl_display::Stage::invalidate
template struct ThunkFunc0<Instances::fl_display::Stage, 43, const Value>;
// thunk 0x1424367a0: Instances::fl_display::DisplayObject::rotationSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 24, const Value, Value::Number>;
// thunk 0x142436830: Instances::fl_display::DisplayObjectContainer::getChildIndex
template struct ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 12, SInt32, Instances::fl_display::DisplayObject*>;
// thunk 0x1424368d0: Instances::fl_display::Stage::isFocusInaccessible
template struct ThunkFunc0<Instances::fl_display::Stage, 44, bool>;
// thunk 0x142436930: Instances::fl_display::DisplayObject::rotationXGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 25, Value::Number>;
// thunk 0x1424369a0: Instances::fl_display::BitmapData::heightGet
template struct ThunkFunc0<Instances::fl_display::BitmapData, 0, SInt32>;
// thunk 0x142436a00: Instances::fl_display::DisplayObjectContainer::getObjectsUnderPoint
template struct ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 13, SPtr<Instances::fl::Array>, Instances::fl_geom::Point*>;
// thunk 0x142436af0: Instances::fl_display::Stage::removeChildAt
template struct ThunkFunc1<Instances::fl_display::Stage, 45, SPtr<Instances::fl_display::DisplayObject>, SInt32>;
// thunk 0x142436bf0: Instances::fl_display::DisplayObject::rotationXSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 26, const Value, Value::Number>;
// thunk 0x142436c80: Instances::fl_display::BitmapData::rectGet
template struct ThunkFunc0<Instances::fl_display::BitmapData, 1, SPtr<Instances::fl_geom::Rectangle>>;
// thunk 0x142436d30: Instances::fl_display::DisplayObjectContainer::removeChild
template struct ThunkFunc2<Instances::fl_display::DisplayObjectContainer, 14, Value, unsigned, const Value*>;
// thunk 0x142436d50: Instances::fl_display::Stage::removeEventListener
// MS2-FUNCTIONAL: block order only: the exe reads the bool argument after the string and value arguments with the call inline in each branch
template struct ThunkFunc3<Instances::fl_display::Stage, 46, const Value, const ASString&, const Value&, bool>;
// thunk 0x142436f60: Instances::fl_display::DisplayObject::rotationYGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 27, Value::Number>;
// thunk 0x142436fd0: Instances::fl_display::BitmapData::transparentGet
template struct ThunkFunc0<Instances::fl_display::BitmapData, 2, bool>;
// thunk 0x142437030: Instances::fl_display::DisplayObjectContainer::removeChildAt
template struct ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 15, SPtr<Instances::fl_display::DisplayObject>, SInt32>;
// thunk 0x142437130: Instances::fl_display::Stage::setChildIndex
template struct ThunkFunc2<Instances::fl_display::Stage, 47, const Value, Instances::fl_display::DisplayObject*, SInt32>;
// thunk 0x1424371e0: Instances::fl_display::DisplayObject::rotationYSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 28, const Value, Value::Number>;
// thunk 0x142437270: Instances::fl_display::BitmapData::widthGet
template struct ThunkFunc0<Instances::fl_display::BitmapData, 3, SInt32>;
// thunk 0x1424372d0: Instances::fl_display::DisplayObjectContainer::setChildIndex
template struct ThunkFunc2<Instances::fl_display::DisplayObjectContainer, 16, const Value, Instances::fl_display::DisplayObject*, SInt32>;
// thunk 0x142437380: Instances::fl_display::DisplayObject::rotationZGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 29, Value::Number>;
// thunk 0x1424373f0: Instances::fl_display::Stage::setOrientation
template struct ThunkFunc1<Instances::fl_display::Stage, 48, const Value, const ASString&>;
// thunk 0x1424374f0: Instances::fl_display::BitmapData::applyFilter
template struct ThunkFunc4<Instances::fl_display::BitmapData, 4, const Value, Instances::fl_display::BitmapData*, Instances::fl_geom::Rectangle*, Instances::fl_geom::Point*, Instances::fl_filters::BitmapFilter*>;
// thunk 0x1424375a0: Instances::fl_display::DisplayObjectContainer::swapChildren
template struct ThunkFunc2<Instances::fl_display::DisplayObjectContainer, 17, const Value, Instances::fl_display::DisplayObject*, Instances::fl_display::DisplayObject*>;
// thunk 0x1424375f0: Instances::fl_display::DisplayObject::rotationZSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 30, const Value, Value::Number>;
// thunk 0x142437680: Instances::fl_display::Stage::swapChildrenAt
template struct ThunkFunc2<Instances::fl_display::Stage, 49, const Value, SInt32, SInt32>;
// thunk 0x142437870: Instances::fl_display::BitmapData::clone
template struct ThunkFunc0<Instances::fl_display::BitmapData, 5, SPtr<Instances::fl_display::BitmapData>>;
// thunk 0x142437920: Instances::fl_display::DisplayObjectContainer::swapChildrenAt
template struct ThunkFunc2<Instances::fl_display::DisplayObjectContainer, 18, const Value, SInt32, SInt32>;
// thunk 0x1424379d0: Instances::fl_display::DisplayObject::scale9GridGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 31, SPtr<Instances::fl_geom::Rectangle>>;
// thunk 0x142437a80: Instances::fl_display::Stage::willTrigger
template struct ThunkFunc1<Instances::fl_display::Stage, 50, bool, const ASString&>;
// thunk 0x142437bc0: Instances::fl_display::BitmapData::colorTransform
template struct ThunkFunc2<Instances::fl_display::BitmapData, 6, const Value, Instances::fl_geom::Rectangle*, Instances::fl_geom::ColorTransform*>;
// thunk 0x142437c10: Instances::fl_display::DisplayObject::scale9GridSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 32, const Value, Instances::fl_geom::Rectangle*>;
// thunk 0x142437c50: Instances::fl_display::BitmapData::compare
template struct ThunkFunc1<Instances::fl_display::BitmapData, 7, Value, Instances::fl_display::BitmapData*>;
// thunk 0x142437c90: Instances::fl_display::DisplayObject::scaleXGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 33, Value::Number>;
// thunk 0x142437d00: Instances::fl_display::DisplayObject::scaleXSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 34, const Value, Value::Number>;
// thunk 0x142437d90: Instances::fl_display::BitmapData::copyChannel
template struct ThunkFunc5<Instances::fl_display::BitmapData, 8, const Value, Instances::fl_display::BitmapData*, Instances::fl_geom::Rectangle*, Instances::fl_geom::Point*, UInt32, UInt32>;
// thunk 0x142437ee0: Instances::fl_display::DisplayObject::scaleYGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 35, Value::Number>;
// thunk 0x142437f50: Instances::fl_display::BitmapData::copyPixels
template struct ThunkFunc6<Instances::fl_display::BitmapData, 9, const Value, Instances::fl_display::BitmapData*, Instances::fl_geom::Rectangle*, Instances::fl_geom::Point*, Instances::fl_display::BitmapData*, Instances::fl_geom::Point*, bool>;
// thunk 0x142438080: Instances::fl_display::DisplayObject::scaleYSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 36, const Value, Value::Number>;
// thunk 0x142438110: Instances::fl_display::BitmapData::dispose
template struct ThunkFunc0<Instances::fl_display::BitmapData, 10, const Value>;
// thunk 0x142438270: Instances::fl_display::DisplayObject::scaleZGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 37, Value::Number>;
// Instances::fl_display::BitmapData::draw argument 3 default
template <> struct ThunkMethodDefault<Instances::fl_display::BitmapData, 11, 3, const ASString&>
{
    SF_INLINE static ASString Get(StringManager& sm) { return sm.CreateConstString("null"); }
};
// thunk 0x1424382e0: Instances::fl_display::BitmapData::draw
template struct ThunkFunc6<Instances::fl_display::BitmapData, 11, const Value, Instances::fl::Object*, Instances::fl_geom::Matrix*, Instances::fl_geom::ColorTransform*, const ASString&, Instances::fl_geom::Rectangle*, bool>;
// thunk 0x142438460: Instances::fl_display::DisplayObject::scaleZSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 38, const Value, Value::Number>;
// thunk 0x1424384f0: Instances::fl_display::BitmapData::fillRect
template struct ThunkFunc2<Instances::fl_display::BitmapData, 12, const Value, Instances::fl_geom::Rectangle*, UInt32>;
// thunk 0x1424385a0: Instances::fl_display::DisplayObject::scrollRectGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 39, SPtr<Instances::fl_geom::Rectangle>>;
// thunk 0x142438650: Instances::fl_display::MovieClip::currentFrameGet
template struct ThunkFunc0<Instances::fl_display::MovieClip, 0, SInt32>;
// thunk 0x1424386b0: Instances::fl_display::DisplayObject::scrollRectSet
template struct ThunkFunc1<Instances::fl_display::DisplayObject, 40, const Value, Instances::fl_geom::Rectangle*>;
// thunk 0x1424386f0: Instances::fl_display::BitmapData::floodFill
template struct ThunkFunc3<Instances::fl_display::BitmapData, 13, const Value, SInt32, SInt32, UInt32>;
// thunk 0x1424387e0: Instances::fl_display::MovieClip::currentFrameLabelGet
template struct ThunkFunc0<Instances::fl_display::MovieClip, 1, ASString>;
// thunk 0x142438850: Instances::fl_display::DisplayObject::stageGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 41, SPtr<Instances::fl_display::Stage>>;
// thunk 0x142438900: Instances::fl_display::MovieClip::currentLabelGet
template struct ThunkFunc0<Instances::fl_display::MovieClip, 2, ASString>;
// thunk 0x142438970: Instances::fl_display::BitmapData::generateFilterRect
template struct ThunkFunc2<Instances::fl_display::BitmapData, 14, SPtr<Instances::fl_geom::Rectangle>, Instances::fl_geom::Rectangle*, Instances::fl_filters::BitmapFilter*>;
// thunk 0x142438a80: Instances::fl_display::DisplayObject::transformGet
template struct ThunkFunc0<Instances::fl_display::DisplayObject, 42, SPtr<Instances::fl_geom::Transform>>;
// thunk 0x142438b30: Instances::fl_display::MovieClip::currentLabelsGet
template struct ThunkFunc0<Instances::fl_display::MovieClip, 3, SPtr<Instances::fl::Array>>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

namespace Scaleform { namespace GFx { namespace AS3 {

namespace fl_display
{
    extern const ClassInfo AVM1MovieCI;
    extern const ClassInfo ActionScriptVersionCI;
    extern const ClassInfo BitmapCI;
    extern const ClassInfo BitmapDataChannelCI;
    extern const ClassInfo BlendModeCI;
    extern const ClassInfo CapsStyleCI;
    extern const ClassInfo DisplayObjectContainerCI;
    extern const ClassInfo FrameLabelCI;
    extern const ClassInfo GradientTypeCI;
    extern const ClassInfo GraphicsCI;
    extern const ClassInfo IBitmapDrawableCI;
    extern const ClassInfo InteractiveObjectCI;
    extern const ClassInfo InterpolationMethodCI;
    extern const ClassInfo JointStyleCI;
    extern const ClassInfo LineScaleModeCI;
    extern const ClassInfo LoaderCI;
    extern const ClassInfo LoaderInfoCI;
    extern const ClassInfo MorphShapeCI;
    extern const ClassInfo MovieClipCI;
    extern const ClassInfo PixelSnappingCI;
    extern const ClassInfo SWFVersionCI;
    extern const ClassInfo SceneCI;
    extern const ClassInfo ShaderCI;
    extern const ClassInfo ShaderDataCI;
    extern const ClassInfo ShapeCI;
    extern const ClassInfo SimpleButtonCI;
    extern const ClassInfo SpreadMethodCI;
    extern const ClassInfo SpriteCI;
    extern const ClassInfo StageAlignCI;
    extern const ClassInfo StageCI;
    extern const ClassInfo StageDisplayStateCI;
    extern const ClassInfo StageQualityCI;
    extern const ClassInfo StageScaleModeCI;
}

// ---- fl_display class traits factories ----
// The exe builds each class traits object here with its constructor (sfr_as3_06) inlined, except for
// DisplayObject and BitmapData, whose constructors stay out of line. The __forceinline copies below
// repeat the sfr_as3_06 bodies so cl expands them the same way; keep the two in step.

namespace ClassTraits { namespace fl_display
{
}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243caf0); the exe inlines it into MakeClassTraits.
    __forceinline StageAlign::StageAlign(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
        , Bottom("B")
        , BottomLeft("BL")
        , BottomRight("BR")
        , Left("L")
        , Right("R")
        , Top("T")
        , TopLeft("TL")
        , TopRight("TR")
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243c9b0); the exe inlines it into MakeClassTraits.
    __forceinline StageAlign::StageAlign(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::StageAlignCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::StageAlignCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::StageAlign(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x14242c7d0
    Pickable<Traits> StageAlign::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StageAlign(vm, Instances::fl::InlineCtor()));
    }

}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243cc70); the exe inlines it into MakeClassTraits.
    __forceinline StageDisplayState::StageDisplayState(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
        , FullScreen("fullScreen")
        , FullScreenInteractive("fullScreenInteractive")
        , Normal("normal")
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243cb70); the exe inlines it into MakeClassTraits.
    __forceinline StageDisplayState::StageDisplayState(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::StageDisplayStateCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::StageDisplayStateCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::StageDisplayState(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x14242d350
    Pickable<Traits> StageDisplayState::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StageDisplayState(vm, Instances::fl::InlineCtor()));
    }

}}

namespace InstanceTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243ad40); the exe inlines it into MakeClassTraits.
    __forceinline FrameLabel::FrameLabel(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor)
        : CTraits(vm, ci)
    {
        SetMemSize(0x48);
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243ac40); the exe inlines it into MakeClassTraits.
    __forceinline FrameLabel::FrameLabel(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::FrameLabelCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::FrameLabel(vm, AS3::fl_display::FrameLabelCI, Instances::fl::InlineCtor());
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x14242d840
    Pickable<Traits> FrameLabel::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) FrameLabel(vm, Instances::fl::InlineCtor()));
    }

}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243cdd0); the exe inlines it into MakeClassTraits.
    __forceinline StageQuality::StageQuality(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
        , Best("best")
        , High("high")
        , Low("low")
        , Medium("medium")
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243ccc0); the exe inlines it into MakeClassTraits.
    __forceinline StageQuality::StageQuality(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::StageQualityCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::StageQualityCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::StageQuality(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x14242dbf0
    Pickable<Traits> StageQuality::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StageQuality(vm, Instances::fl::InlineCtor()));
    }

}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243aec0); the exe inlines it into MakeClassTraits.
    __forceinline GradientType::GradientType(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
        , Linear("linear")
        , Radial("radial")
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243adc0); the exe inlines it into MakeClassTraits.
    __forceinline GradientType::GradientType(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::GradientTypeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::GradientTypeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::GradientType(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x14242dd60
    Pickable<Traits> GradientType::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) GradientType(vm, Instances::fl::InlineCtor()));
    }

}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243cf30); the exe inlines it into MakeClassTraits.
    __forceinline StageScaleMode::StageScaleMode(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
        , ExactFit("exactFit")
        , NoBorder("noBorder")
        , NoScale("noScale")
        , ShowAll("showAll")
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243ce20); the exe inlines it into MakeClassTraits.
    __forceinline StageScaleMode::StageScaleMode(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::StageScaleModeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::StageScaleModeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::StageScaleMode(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x14242deb0
    Pickable<Traits> StageScaleMode::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StageScaleMode(vm, Instances::fl::InlineCtor()));
    }

}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243bf00); the exe inlines it into MakeClassTraits.
    __forceinline SWFVersion::SWFVersion(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
        , Flash1(1)
        , Flash2(2)
        , Flash3(3)
        , Flash4(4)
        , Flash5(5)
        , Flash6(6)
        , Flash7(7)
        , Flash8(8)
        , Flash9(9)
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243bde0); the exe inlines it into MakeClassTraits.
    __forceinline SWFVersion::SWFVersion(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::SWFVersionCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::SWFVersionCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::SWFVersion(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x14242e020
    Pickable<Traits> SWFVersion::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SWFVersion(vm, Instances::fl::InlineCtor()));
    }

}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243c1a0); the exe inlines it into MakeClassTraits.
    __forceinline ShaderData::ShaderData(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::ShaderDataCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::ShaderDataCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x14242e1a0
    Pickable<Traits> ShaderData::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ShaderData(vm, Instances::fl::InlineCtor()));
    }

}}

namespace InstanceTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b000); the exe inlines it into MakeClassTraits.
    __forceinline Graphics::Graphics(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor)
        : CTraits(vm, ci)
    {
        SetMemSize(0x48);
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243af00); the exe inlines it into MakeClassTraits.
    __forceinline Graphics::Graphics(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::GraphicsCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::Graphics(vm, AS3::fl_display::GraphicsCI, Instances::fl::InlineCtor());
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x14242e2c0
    Pickable<Traits> Graphics::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Graphics(vm, Instances::fl::InlineCtor()));
    }

}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243c0c0); the exe inlines it into MakeClassTraits.
    __forceinline Shader::Shader(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::ShaderCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::ShaderCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x14242e400
    Pickable<Traits> Shader::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Shader(vm, Instances::fl::InlineCtor()));
    }

}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243bd90); the exe inlines it into MakeClassTraits.
    __forceinline PixelSnapping::PixelSnapping(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
        , Always("always")
        , Auto("auto")
        , Never("never")
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243bc90); the exe inlines it into MakeClassTraits.
    __forceinline PixelSnapping::PixelSnapping(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::PixelSnappingCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::PixelSnappingCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::PixelSnapping(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x14242eb30
    Pickable<Traits> PixelSnapping::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) PixelSnapping(vm, Instances::fl::InlineCtor()));
    }

}}

namespace InstanceTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243c380); the exe inlines it into MakeClassTraits.
    __forceinline Shape::Shape(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor)
        : CTraits(vm, ci)
    {
        SetMemSize(0x70);
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243c280); the exe inlines it into MakeClassTraits.
    __forceinline Shape::Shape(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::ShapeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::Shape(vm, AS3::fl_display::ShapeCI, Instances::fl::InlineCtor());
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x14242f3b0
    Pickable<Traits> Shape::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Shape(vm, Instances::fl::InlineCtor()));
    }

}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243a360); the exe inlines it into MakeClassTraits.
    __forceinline BitmapDataChannel::BitmapDataChannel(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
        , Alpha(8)
        , Blue(4)
        , Green(2)
        , Red(1)
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243a260); the exe inlines it into MakeClassTraits.
    __forceinline BitmapDataChannel::BitmapDataChannel(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::BitmapDataChannelCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::BitmapDataChannelCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::BitmapDataChannel(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x14242f5a0
    Pickable<Traits> BitmapDataChannel::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) BitmapDataChannel(vm, Instances::fl::InlineCtor()));
    }

}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243a720); the exe inlines it into MakeClassTraits.
    __forceinline CapsStyle::CapsStyle(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
        , None("none")
        , Round("round")
        , Square("square")
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243a620); the exe inlines it into MakeClassTraits.
    __forceinline CapsStyle::CapsStyle(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::CapsStyleCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::CapsStyleCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::CapsStyle(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x14242f7f0
    Pickable<Traits> CapsStyle::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) CapsStyle(vm, Instances::fl::InlineCtor()));
    }

}}

namespace InstanceTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243c4f0); the exe inlines it into MakeClassTraits.
    __forceinline SimpleButton::SimpleButton(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_SimpleButton;
        SetMemSize(0x70);
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243c3e0); the exe inlines it into MakeClassTraits.
    __forceinline SimpleButton::SimpleButton(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::SimpleButtonCI)
    {
        TraitsType = Traits_SimpleButton;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::SimpleButton(vm, AS3::fl_display::SimpleButtonCI, Instances::fl::InlineCtor());
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x14242fde0
    Pickable<Traits> SimpleButton::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SimpleButton(vm, Instances::fl::InlineCtor()));
    }

}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b060); the exe inlines it into MakeClassTraits.
    __forceinline IBitmapDrawable::IBitmapDrawable(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::IBitmapDrawableCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::Interface(vm, AS3::fl_display::IBitmapDrawableCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x142430340
    Pickable<Traits> IBitmapDrawable::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IBitmapDrawable(vm, Instances::fl::InlineCtor()));
    }

}}

namespace InstanceTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243abe0); the exe inlines it into MakeClassTraits.
    __forceinline DisplayObjectContainer::DisplayObjectContainer(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_DisplayObjectContainer;
        SetMemSize(0x70);
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243aad0); the exe inlines it into MakeClassTraits.
    __forceinline DisplayObjectContainer::DisplayObjectContainer(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::DisplayObjectContainerCI)
    {
        TraitsType = Traits_DisplayObjectContainer;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::DisplayObjectContainer(vm, AS3::fl_display::DisplayObjectContainerCI, Instances::fl::InlineCtor());
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x142430460
    Pickable<Traits> DisplayObjectContainer::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) DisplayObjectContainer(vm, Instances::fl::InlineCtor()));
    }

    // @0x1424305a0
    Pickable<Traits> DisplayObject::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) DisplayObject(vm));
    }

}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b3b0); the exe inlines it into MakeClassTraits.
    __forceinline InterpolationMethod::InterpolationMethod(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
        , LinearRgb("linearRGB")
        , Rgb("rgb")
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b2b0); the exe inlines it into MakeClassTraits.
    __forceinline InterpolationMethod::InterpolationMethod(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::InterpolationMethodCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::InterpolationMethodCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::InterpolationMethod(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x142430600
    Pickable<Traits> InterpolationMethod::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) InterpolationMethod(vm, Instances::fl::InlineCtor()));
    }

}}

namespace InstanceTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x142439d00); the exe inlines it into MakeClassTraits.
    __forceinline AVM1Movie::AVM1Movie(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_AVM1Movie;
        SetMemSize(0x68);
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x142439bf0); the exe inlines it into MakeClassTraits.
    __forceinline AVM1Movie::AVM1Movie(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::AVM1MovieCI)
    {
        TraitsType = Traits_AVM1Movie;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::AVM1Movie(vm, AS3::fl_display::AVM1MovieCI, Instances::fl::InlineCtor());
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x142430750
    Pickable<Traits> AVM1Movie::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) AVM1Movie(vm, Instances::fl::InlineCtor()));
    }

}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b4f0); the exe inlines it into MakeClassTraits.
    __forceinline JointStyle::JointStyle(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
        , Bevel("bevel")
        , Miter("miter")
        , Round("round")
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b3f0); the exe inlines it into MakeClassTraits.
    __forceinline JointStyle::JointStyle(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::JointStyleCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::JointStyleCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::JointStyle(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x142430890
    Pickable<Traits> JointStyle::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) JointStyle(vm, Instances::fl::InlineCtor()));
    }

}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b650); the exe inlines it into MakeClassTraits.
    __forceinline LineScaleMode::LineScaleMode(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
        , Horizontal("horizontal")
        , None("none")
        , Normal("normal")
        , Vertical("vertical")
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b540); the exe inlines it into MakeClassTraits.
    __forceinline LineScaleMode::LineScaleMode(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::LineScaleModeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::LineScaleModeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::LineScaleMode(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x1424309f0
    Pickable<Traits> LineScaleMode::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) LineScaleMode(vm, Instances::fl::InlineCtor()));
    }

}}

namespace InstanceTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b7b0); the exe inlines it into MakeClassTraits.
    __forceinline Loader::Loader(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Loader;
        SetMemSize(0x78);
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b6a0); the exe inlines it into MakeClassTraits.
    __forceinline Loader::Loader(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::LoaderCI)
    {
        TraitsType = Traits_Loader;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::Loader(vm, AS3::fl_display::LoaderCI, Instances::fl::InlineCtor());
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x142430b60
    Pickable<Traits> Loader::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Loader(vm, Instances::fl::InlineCtor()));
    }

}}

namespace InstanceTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243c950); the exe inlines it into MakeClassTraits.
    __forceinline Stage::Stage(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Stage;
        SetMemSize(0x70);
    }
}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243c920); the exe inlines it into MakeClassTraits.
    __forceinline Stage::Stage(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243c810); the exe inlines it into MakeClassTraits.
    __forceinline Stage::Stage(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::StageCI)
    {
        TraitsType = Traits_Stage;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::Stage(vm, AS3::fl_display::StageCI, Instances::fl::InlineCtor());
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::Stage(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x142430ca0
    Pickable<Traits> Stage::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Stage(vm, Instances::fl::InlineCtor()));
    }

}}

namespace InstanceTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b940); the exe inlines it into MakeClassTraits.
    __forceinline LoaderInfo::LoaderInfo(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor)
        : CTraits(vm, ci)
    {
        SetMemSize(0x68);
    }
}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b910); the exe inlines it into MakeClassTraits.
    __forceinline LoaderInfo::LoaderInfo(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b810); the exe inlines it into MakeClassTraits.
    __forceinline LoaderInfo::LoaderInfo(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::LoaderInfoCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::LoaderInfo(vm, AS3::fl_display::LoaderInfoCI, Instances::fl::InlineCtor());
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::LoaderInfo(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x142430fd0
    Pickable<Traits> LoaderInfo::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) LoaderInfo(vm, Instances::fl::InlineCtor()));
    }

}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243c650); the exe inlines it into MakeClassTraits.
    __forceinline SpreadMethod::SpreadMethod(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
        , Pad("pad")
        , Reflect("reflect")
        , Repeat("repeat")
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243c550); the exe inlines it into MakeClassTraits.
    __forceinline SpreadMethod::SpreadMethod(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::SpreadMethodCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::SpreadMethodCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::SpreadMethod(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x1424318e0
    Pickable<Traits> SpreadMethod::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SpreadMethod(vm, Instances::fl::InlineCtor()));
    }

}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x142439e50); the exe inlines it into MakeClassTraits.
    __forceinline ActionScriptVersion::ActionScriptVersion(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
        , Actionscript2(2)
        , Actionscript3(3)
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x142439d60); the exe inlines it into MakeClassTraits.
    __forceinline ActionScriptVersion::ActionScriptVersion(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::ActionScriptVersionCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::ActionScriptVersionCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::ActionScriptVersion(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x142431a40
    Pickable<Traits> ActionScriptVersion::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ActionScriptVersion(vm, Instances::fl::InlineCtor()));
    }

}}

namespace InstanceTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b250); the exe inlines it into MakeClassTraits.
    __forceinline InteractiveObject::InteractiveObject(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_InteractiveObject;
        SetMemSize(0x70);
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b140); the exe inlines it into MakeClassTraits.
    __forceinline InteractiveObject::InteractiveObject(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::InteractiveObjectCI)
    {
        TraitsType = Traits_InteractiveObject;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::InteractiveObject(vm, AS3::fl_display::InteractiveObjectCI, Instances::fl::InlineCtor());
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x142431b90
    Pickable<Traits> InteractiveObject::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) InteractiveObject(vm, Instances::fl::InlineCtor()));
    }

}}

namespace Classes { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243a540); the exe inlines it into MakeClassTraits.
    __forceinline BlendMode::BlendMode(ClassTraits::Traits& t, Instances::fl::InlineCtor)
        : Class(t)
        , Add("add")
        , Alpha("alpha")
        , Darken("darken")
        , Difference("difference")
        , Erase("erase")
        , Hardlight("hardlight")
        , Invert("invert")
        , Layer("layer")
        , Lighten("lighten")
        , Multiply("multiply")
        , Normal("normal")
        , Overlay("overlay")
        , Screen("screen")
        , Subtract("subtract")
    {
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243a3a0); the exe inlines it into MakeClassTraits.
    __forceinline BlendMode::BlendMode(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::BlendModeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_display::BlendModeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_display::BlendMode(*this, Instances::fl::InlineCtor())));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x142432ad0
    Pickable<Traits> BlendMode::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) BlendMode(vm, Instances::fl::InlineCtor()));
    }

}}

namespace InstanceTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243bab0); the exe inlines it into MakeClassTraits.
    __forceinline MorphShape::MorphShape(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_MorphShape;
        SetMemSize(0x68);
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243b9a0); the exe inlines it into MakeClassTraits.
    __forceinline MorphShape::MorphShape(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::MorphShapeCI)
    {
        TraitsType = Traits_MorphShape;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::MorphShape(vm, AS3::fl_display::MorphShapeCI, Instances::fl::InlineCtor());
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x142434400
    Pickable<Traits> MorphShape::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) MorphShape(vm, Instances::fl::InlineCtor()));
    }

    // @0x1424347d0
    Pickable<Traits> BitmapData::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) BitmapData(vm));
    }

}}

namespace InstanceTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x142439f90); the exe inlines it into MakeClassTraits.
    __forceinline Bitmap::Bitmap(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Bitmap;
        SetMemSize(0x78);
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x142439e80); the exe inlines it into MakeClassTraits.
    __forceinline Bitmap::Bitmap(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::BitmapCI)
    {
        TraitsType = Traits_Bitmap;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::Bitmap(vm, AS3::fl_display::BitmapCI, Instances::fl::InlineCtor());
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x142435180
    Pickable<Traits> Bitmap::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Bitmap(vm, Instances::fl::InlineCtor()));
    }

}}

namespace InstanceTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243c7b0); the exe inlines it into MakeClassTraits.
    __forceinline Sprite::Sprite(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Sprite;
        SetMemSize(0x78);
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243c6a0); the exe inlines it into MakeClassTraits.
    __forceinline Sprite::Sprite(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::SpriteCI)
    {
        TraitsType = Traits_Sprite;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::Sprite(vm, AS3::fl_display::SpriteCI, Instances::fl::InlineCtor());
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x1424354d0
    Pickable<Traits> Sprite::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Sprite(vm, Instances::fl::InlineCtor()));
    }

}}

namespace InstanceTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243bc20); the exe inlines it into MakeClassTraits.
    __forceinline MovieClip::MovieClip(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_MovieClip;
        SetMemSize(0x88);
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243bb10); the exe inlines it into MakeClassTraits.
    __forceinline MovieClip::MovieClip(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::MovieClipCI)
    {
        TraitsType = Traits_MovieClip;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::MovieClip(vm, AS3::fl_display::MovieClipCI, Instances::fl::InlineCtor());
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x142437730
    Pickable<Traits> MovieClip::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) MovieClip(vm, Instances::fl::InlineCtor()));
    }

}}

namespace InstanceTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243c060); the exe inlines it into MakeClassTraits.
    __forceinline Scene::Scene(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor)
        : CTraits(vm, ci)
    {
        SetMemSize(0x48);
    }
}}

namespace ClassTraits { namespace fl_display
{
    // Out of line in sfr_as3_06 (0x14243bf60); the exe inlines it into MakeClassTraits.
    __forceinline Scene::Scene(VM& vm, Instances::fl::InlineCtor)
        : Traits(vm, AS3::fl_display::SceneCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_display::Scene(vm, AS3::fl_display::SceneCI, Instances::fl::InlineCtor());
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace ClassTraits { namespace fl_display
{
    // @0x142438130
    Pickable<Traits> Scene::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Scene(vm, Instances::fl::InlineCtor()));
    }
}}

}}} // namespace Scaleform::GFx::AS3


// ---- core natives: Date, Error, QName, RegExp, Math, global functions ----


void* FUN_1424d7e50(void* pmem, const Scaleform::GFx::AS3::Value& function, unsigned delay, bool timeout);   // IntervalTimer ctor (setInterval/setTimeout form)
void  FUN_1425264b0(void* ptimer, unsigned argc, const Scaleform::GFx::AS3::Value* argv);                   // IntervalTimer: copies the extra call arguments
void  FUN_1425e4ad0(const char* pstr, unsigned len, Scaleform::String* presult);                            // URL-style unescape of a string

namespace Scaleform { namespace GFx { namespace AS3 {

// the global unescapeMultiByte (sfr_as3_12)
void unescapeMultiByteInternal(VM& vm, ASString& result, const ASString& value);

namespace Instances { namespace fl
{
    // @0x14242b120
    void Date::timeGet(Value::Number& result)
    {
        result = TimeValue;
    }

    // @0x14242b130
    // MS2-FUNCTIONAL: the exe also builds an undefined Value it never uses around the call
    void Date::timeSet(const Value& result, Value::Number t)
    {
        SF_UNUSED(result);
        Value::Number r;
        AS3setTime(r, t);
    }

    // The offset in minutes, local time behind UTC positive; NaN stays NaN.
    // @0x14242b180
    void Date::timezoneOffsetGet(Value::Number& result)
    {
        Value::Number t = TimeValue;
        if (!NumberUtil::IsNaN(t))
            t = (t - (t + LocalTZA)) / 60000.0;
        result = t;
    }

    // @0x14242b1e0
    // MS2-FUNCTIONAL: written from behaviour (name, then ": " and the message when there is one)
    void Error::toStringProto(ASString& result)
    {
        result = GetTraits().GetName();
        if (message.GetSize() != 0)
        {
            String msg(message.ToCStr(), message.GetSize());
            String text = String(": ") + msg;
            result.Append(text.ToCStr(), strlen(text.ToCStr()));
        }
    }

    // @0x14242b700
    void GlobalObjectCPP::unescapeMultiByte(ASString& result, const ASString& value)
    {
        unescapeMultiByteInternal(GetVM(), result, value);
    }

    // @0x14242b710
    void QName::uriGet(Value& result)
    {
        if (Ns)
            result.Assign(Ns->GetUri());
        else
            result.SetNull();
    }

    // @0x14242b010
    void RegExp::sourceGet(ASString& result)
    {
        result = GetVM().GetStringManager().CreateString(Pattern);
    }

    // @0x14242ae30
    // MS2-FUNCTIONAL: written from behaviour (a one-shot interval timer registered with the movie)
    void GlobalObjectCPP::setTimeout(Value& result, unsigned argc, const Value* argv)
    {
        if (argc < 2)
        {
            GetVM().ThrowArgumentError(VM::Error(VM::eWrongArgumentCountError, GetVM(), "GlobalObjectCPP::setTimeout", 2, 1023, argc));
            return;
        }
        UInt32 delay = 0;
        if (!argv[1].Convert2UInt32(delay))
            return;
        void* pmem = GetVM().GetMemoryHeap()->Alloc(0x70);
        ASIntervalTimerIntf* ptimer = pmem ? (ASIntervalTimerIntf*)FUN_1424d7e50(pmem, argv[0], delay, true) : NULL;
        if (argc > 2)
            FUN_1425264b0(ptimer, argc - 2, argv + 2);
        MovieImpl* proot = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        int id = proot->AddIntervalTimer(ptimer);
        result.Assign(Value(UInt32(id)));
        ptimer->Start(proot);
        ptimer->Release();
    }

    // @0x14242b410
    void GlobalObjectCPP::trace(Value& result, unsigned argc, const Value* argv)
    {
        SF_UNUSED(result);
        StringBuffer buf;
        VM& vm = GetVM();
        for (unsigned i = 0; i < argc; ++i)
        {
            if (i != 0)
                buf.AppendChar(' ');
            ASString str = GetVM().GetStringManager().CreateEmptyString();
            if (!argv[i].Convert2String(str))
                return;
            buf.AppendString(String(str.ToCStr(), str.GetSize()).ToCStr());
        }
        buf.AppendString("\n");
        vm.GetUI().Output(FlashUI::Output_Message, buf.ToCStr());
    }

    // @0x14242b590
    // MS2-FUNCTIONAL: written from behaviour
    void GlobalObjectCPP::unescape(Value& result, unsigned argc, const Value* argv)
    {
        StringManager& sm = GetVM().GetStringManager();
        if (argc == 0)
        {
            result.Assign(sm.GetBuiltin(AS3Builtin_undefined));
            return;
        }
        if (argv[0].IsNullOrUndefined())
        {
            result.Assign(sm.GetBuiltin(AS3Builtin_null));
            return;
        }
        ASString str = sm.CreateEmptyString();
        if (argv[0].Convert2String(str))
        {
            String out;
            FUN_1425e4ad0(str.ToCStr(), str.GetSize(), &out);
            result.Assign(sm.CreateString(out));
        }
    }
}}

namespace Classes { namespace fl
{
    // @0x14242ae20
    void XML::setSettings(const Value& result, const Value& v)
    {
        AS3setSettings(result, v);
    }

    // @0x14242afb0
    void XML::settings(SPtr<Instances::fl::Object>& result)
    {
        AS3settings(result);
    }

    // @0x14242b0d0
    void Error::throwError(Value& result, unsigned argc, const Value* argv)
    {
        SF_UNUSED3(result, argc, argv);
        GetVM().ThrowError(VM::Error(VM::eNotImplementedError, GetVM(), "class_::Error::throwError()"));
    }

    // @0x14242afc0
    void Math::sin(Value::Number& result, Value::Number v)
    {
        result = ::sin(v);
    }

    // @0x14242b090
    void Math::sqrt(Value::Number& result, Value::Number v)
    {
        result = ::sqrt(v);
    }

    // @0x14242b0b0
    void Math::tan(Value::Number& result, Value::Number v)
    {
        result = ::tan(v);
    }

    // @0x14242b300
    void Object::toStringProto(ASString& result)
    {
        result = GetVM().GetStringManager().CreateConstString("[class ") + GetTraits().GetName() + "]";
    }

    // @0x14242b3d0
    void RegExp::toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        SF_UNUSED4(ti, vm, argc, argv);
        result.Assign(static_cast<Instances::fl::RegExp*>(_this.GetObject())->ToString());
    }
}}

}}} // namespace Scaleform::GFx::AS3

// VM class traits cache (MultinameHash<ClassTraits::Traits*>) rehash.
typedef decltype(Scaleform::GFx::AS3::TClassTraitsCache::TContainer::mHash) Ms2ClassTraitsCacheSet;
// @0x14242a640
template void Ms2ClassTraitsCacheSet::BaseType::setRawCapacity(void* pheapAddr, Scaleform::UPInt n);

// Array's sparse part (HashDH<UPInt, Value>) rehash.
typedef decltype(Scaleform::HashDH<Scaleform::UPInt, Scaleform::GFx::AS3::Value>::mHash) Ms2SparseValueSet;
// MS2-FUNCTIONAL: same code; the exe calls Clear (0x142405fd0) out of line for a zero size, ours inlines it
// @0x14242a870
template void Ms2SparseValueSet::BaseType::setRawCapacity(void* pheapAddr, Scaleform::UPInt n);

// The XML namespace-resolution string set (HashSetDH<ASString>) rehash.
// MS2-FUNCTIONAL: same code; the exe allocates and saves registers differently
// @0x14242aaa0
template void Scaleform::HashSetDH<Scaleform::GFx::ASString>::BaseType::setRawCapacity(void* pheapAddr, Scaleform::UPInt n);

// The XML duplicate check set (HashSet<Value, Value::HashFunctor>) rehash.
// MS2-FUNCTIONAL: same code; the exe allocates and saves registers differently
// @0x14242ac40
template void Scaleform::HashSet<Scaleform::GFx::AS3::Value, Scaleform::GFx::AS3::Value::HashFunctor>::BaseType::setRawCapacity(void* pheapAddr, Scaleform::UPInt n);

// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CM@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242b780
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$04_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242b7e0
// MS2-PIN: ?Func@?$ThunkFunc2@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BB@KJJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242b840
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CN@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242b940
// MS2-PIN: ?Func@?$ThunkFunc1@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242b9a0
// MS2-PIN: ?Func@?$ThunkFunc1@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BC@V?$SPtr@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@@456@PEAVRectangle@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242ba00
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CO@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242baf0
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$06J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242bb60
// MS2-PIN: ?Func@?$ThunkFunc1@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BD@V?$SPtr@VVector_uint@fl_vec@Instances@AS3@GFx@Scaleform@@@456@PEAVRectangle@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242bbc0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CP@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242bcb0
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$07V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242bd40
// MS2-PIN: ?Func@?$ThunkFunc5@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BE@_NPEAVPoint@fl_geom@3456@KAEBVValue@456@PEAV783456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242bdf0
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0DA@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c050
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$08J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c0c0
// MS2-PIN: ?Func@?$ThunkFunc1@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BF@V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@PEAVRectangle@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c120
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$09_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c210
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0DB@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c270
// MS2-PIN: ?Func@?$ThunkFunc0@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BG@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c300
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0DC@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c320
// MS2-PIN: ?Func@?$ThunkFunc1@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c390
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Classes@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c3f0
// MS2-PIN: ?Func@?$ThunkFunc2@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BH@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c450
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0DD@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c470
// MS2-PIN: ?Func@?$ThunkFunc2@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c500
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0DE@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c520
// MS2-PIN: ?Func@?$ThunkFunc2@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c590
// MS2-PIN: ?Func@?$ThunkFunc5@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BI@$$CBVValue@456@JKKK_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c670
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0DF@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242c970
// MS2-PIN: ?Func@?$ThunkFunc2@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$0O@$$CBVValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242ca00
// MS2-PIN: ?Func@?$ThunkFunc2@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BJ@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242cae0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0DG@V?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242cb00
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$0P@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242cbf0
// MS2-PIN: ?Func@?$ThunkFunc2@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BK@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242cc10
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0DH@V?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242cc30
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$0BA@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242cd20
// MS2-PIN: ?Func@?$ThunkFunc6@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BL@JPEAV123456@PEAVRectangle@fl_geom@3456@PEAVPoint@83456@JJK@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242cd40
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$0BB@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242ced0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0DI@V?$SPtr@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAVPoint@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242cef0
// MS2-PIN: ?Func@?$ThunkFunc2@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BM@$$CBVValue@456@JJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242cfe0
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$0BC@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242d090
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0DJ@V?$SPtr@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAVPoint@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242d0b0
// MS2-PIN: ?Func@?$ThunkFunc3@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BN@$$CBVValue@456@JJK@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242d1a0
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$0BD@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242d290
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0DK@_NPEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242d2b0
// MS2-PIN: ?Func@?$ThunkFunc3@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BO@$$CBVValue@456@JJK@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242d4b0
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$0BE@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242d5a0
// MS2-PIN: ?Func@?$ThunkFunc3@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0DL@_NNN_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242d5c0
// MS2-PIN: ?Func@?$ThunkFunc2@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0BP@$$CBVValue@456@PEAVRectangle@fl_geom@3456@PEAVByteArray@fl_utils@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242d700
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0DM@V?$SPtr@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAVPoint@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242d750
// MS2-PIN: ?Func@?$ThunkFunc2@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0CA@$$CBVValue@456@PEAVRectangle@fl_geom@3456@PEAVVector_uint@fl_vec@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242d980
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0DN@V?$SPtr@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAVVector3D@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242d9d0
// MS2-PIN: ?Func@?$ThunkFunc0@VFrameLabel@fl_display@Instances@AS3@GFx@Scaleform@@$0A@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242dac0
// MS2-PIN: ?Func@?$ThunkFunc2@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0CB@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242db20
// MS2-PIN: ?Func@?$ThunkFunc0@VFrameLabel@fl_display@Instances@AS3@GFx@Scaleform@@$00VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242db40
// MS2-PIN: ?Func@?$ThunkFunc1@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0CC@$$CBVValue@456@PEAVRectangle@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242dbb0
// MS2-PIN: ?Func@?$ThunkFunc4@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@$0A@$$CBVValue@456@PEAVBitmapData@23456@PEAVMatrix@fl_geom@3456@_N_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242e520
// MS2-PIN: ?Func@?$ThunkFunc2@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@KN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242e610
// MS2-PIN: ?Func@?$ThunkFunc2@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@$01VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242e6c0
// MS2-PIN: ?Func@?$ThunkFunc0@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242e6e0
// MS2-PIN: ?Func@?$ThunkFunc4@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@NNNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242e700
// MS2-PIN: ?Func@?$ThunkFunc3@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@NNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242e880
// MS2-PIN: ?Func@?$ThunkFunc4@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@NNNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242e9b0
// MS2-PIN: ?Func@?$ThunkFunc4@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@NNNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242ec90
// MS2-PIN: ?Func@?$ThunkFunc6@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@NNNNNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242ee10
// MS2-PIN: ?Func@?$ThunkFunc2@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@$08VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242eff0
// MS2-PIN: ?Func@?$ThunkFunc0@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@$09$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242f010
// MS2-PIN: ?Func@?$ThunkFunc2@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@$0L@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242f030
// MS2-PIN: ?Func@?$ThunkFunc0@VScene@fl_display@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242f050
// MS2-PIN: ?Func@?$ThunkFunc2@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242f100
// MS2-PIN: ?Func@?$ThunkFunc0@VScene@fl_display@Instances@AS3@GFx@Scaleform@@$00VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242f120
// MS2-PIN: ?Func@?$ThunkFunc2@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242f190
// MS2-PIN: ?Func@?$ThunkFunc0@VScene@fl_display@Instances@AS3@GFx@Scaleform@@$01J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242f270
// MS2-PIN: ?Func@?$ThunkFunc2@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@$0O@$$CBVValue@456@NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242f2d0
// MS2-PIN: ?Func@?$ThunkFunc0@VShape@fl_display@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242f4f0
// MS2-PIN: ?Func@?$ThunkFunc0@VBitmap@fl_display@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242f700
// MS2-PIN: ?Func@?$ThunkFunc1@VBitmap@fl_display@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@PEAVBitmapData@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242f7b0
// MS2-PIN: ?Func@?$ThunkFunc0@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242f950
// MS2-PIN: ?Func@?$ThunkFunc0@VBitmap@fl_display@Instances@AS3@GFx@Scaleform@@$01VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242fa00
// MS2-PIN: ?Func@?$ThunkFunc1@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242fa70
// MS2-PIN: ?Func@?$ThunkFunc1@VBitmap@fl_display@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242fbc0
// MS2-PIN: ?Func@?$ThunkFunc0@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242fcc0
// MS2-PIN: ?Func@?$ThunkFunc0@VBitmap@fl_display@Instances@AS3@GFx@Scaleform@@$03_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242fd20
// MS2-PIN: ?Func@?$ThunkFunc1@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242fd80
// MS2-PIN: ?Func@?$ThunkFunc1@VBitmap@fl_display@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242ff20
// MS2-PIN: ?Func@?$ThunkFunc0@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@$03VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242ff80
// MS2-PIN: ?Func@?$ThunkFunc1@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14242ffa0
// MS2-PIN: ?Func@?$ThunkFunc0@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@$05_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424300f0
// MS2-PIN: ?Func@?$ThunkFunc1@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142430150
// MS2-PIN: ?Func@?$ThunkFunc0@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@$07_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424301b0
// MS2-PIN: ?Func@?$ThunkFunc1@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142430210
// MS2-PIN: ?Func@?$ThunkFunc0@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@$09J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142430270
// MS2-PIN: ?Func@?$ThunkFunc1@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424302d0
// MS2-PIN: ?Func@?$ThunkFunc0@VLoader@fl_display@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142430e00
// MS2-PIN: ?Func@?$ThunkFunc0@VLoader@fl_display@Instances@AS3@GFx@Scaleform@@$00V?$SPtr@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142430eb0
// MS2-PIN: ?Func@?$ThunkFunc0@VLoader@fl_display@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142430f60
// MS2-PIN: ?Func@?$ThunkFunc2@VLoader@fl_display@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@PEAVURLRequest@fl_net@3456@PEAVLoaderContext@fl_system@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142430f80
// MS2-PIN: ?Func@?$ThunkFunc2@VLoader@fl_display@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@PEAVByteArray@fl_utils@3456@PEAVLoaderContext@fl_system@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431120
// MS2-PIN: ?Func@?$ThunkFunc0@VLoader@fl_display@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431170
// MS2-PIN: ?Func@?$ThunkFunc1@VLoader@fl_display@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431190
// MS2-PIN: ?Func@?$ThunkFunc0@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424311f0
// MS2-PIN: ?Func@?$ThunkFunc1@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@PEAVDisplayObject@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424312a0
// MS2-PIN: ?Func@?$ThunkFunc0@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424312e0
// MS2-PIN: ?Func@?$ThunkFunc1@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431340
// MS2-PIN: ?Func@?$ThunkFunc0@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$03V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424313a0
// MS2-PIN: ?Func@?$ThunkFunc1@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@PEAVDisplayObject@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431450
// MS2-PIN: ?Func@?$ThunkFunc0@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$05V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431490
// MS2-PIN: ?Func@?$ThunkFunc1@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@PEAVDisplayObject@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431540
// MS2-PIN: ?Func@?$ThunkFunc0@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$07V?$SPtr@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431580
// MS2-PIN: ?Func@?$ThunkFunc1@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@PEAVSoundTransform@fl_media@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431630
// MS2-PIN: ?Func@?$ThunkFunc0@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$09_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431670
// MS2-PIN: ?Func@?$ThunkFunc1@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424316d0
// MS2-PIN: ?Func@?$ThunkFunc0@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$0M@V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431730
// MS2-PIN: ?Func@?$ThunkFunc1@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@PEAVDisplayObject@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424317e0
// MS2-PIN: ?Func@?$ThunkFunc0@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$0O@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431820
// MS2-PIN: ?Func@?$ThunkFunc1@VSimpleButton@fl_display@Instances@AS3@GFx@Scaleform@@$0P@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431880
// MS2-PIN: ?Func@?$ThunkFunc0@VSprite@fl_display@Instances@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431cd0
// MS2-PIN: ?Func@?$ThunkFunc1@VSprite@fl_display@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431d30
// MS2-PIN: ?Func@?$ThunkFunc0@VSprite@fl_display@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431d90
// MS2-PIN: ?Func@?$ThunkFunc0@VSprite@fl_display@Instances@AS3@GFx@Scaleform@@$02V?$SPtr@VGraphics@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431e40
// MS2-PIN: ?Func@?$ThunkFunc0@VSprite@fl_display@Instances@AS3@GFx@Scaleform@@$03V?$SPtr@VSprite@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431ef0
// MS2-PIN: ?Func@?$ThunkFunc1@VSprite@fl_display@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431fa0
// MS2-PIN: ?Func@?$ThunkFunc0@VSprite@fl_display@Instances@AS3@GFx@Scaleform@@$05V?$SPtr@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142431fe0
// MS2-PIN: ?Func@?$ThunkFunc1@VSprite@fl_display@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@PEAVSoundTransform@fl_media@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432090
// MS2-PIN: ?Func@?$ThunkFunc0@VSprite@fl_display@Instances@AS3@GFx@Scaleform@@$07_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424320d0
// MS2-PIN: ?Func@?$ThunkFunc1@VSprite@fl_display@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432130
// MS2-PIN: ?Func@?$ThunkFunc2@VSprite@fl_display@Instances@AS3@GFx@Scaleform@@$09$$CBVValue@456@_NPEAVRectangle@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432190
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432210
// MS2-PIN: ?Func@?$ThunkFunc0@VSprite@fl_display@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432270
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$00V?$SPtr@VApplicationDomain@fl_system@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432290
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VByteArray@fl_utils@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432340
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$02K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424323f0
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$03K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432450
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$04_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424324b0
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$05V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432510
// MS2-PIN: ?Func@?$ThunkFunc1@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424325c0
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$07V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432710
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$08VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424327c0
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$09N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432830
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$0L@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424328a0
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$0M@V?$SPtr@VLoader@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432900
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$0N@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424329b0
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$0O@V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432a20
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0A@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432cc0
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$0P@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432d30
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432d90
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$0BA@V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432e90
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432f40
// MS2-PIN: ?Func@?$ThunkFunc1@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$0BB@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142432fa0
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424330f0
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$0BC@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433160
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424331c0
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$0BD@V?$SPtr@VEventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433230
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424332e0
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$0BE@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424333e0
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$05V?$SPtr@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433440
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$0BF@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424334f0
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@PEAVInteractiveObject@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433560
// MS2-PIN: ?Func@?$ThunkFunc0@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@$0BG@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424335a0
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$07N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433600
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433670
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$09K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433700
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0L@V?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433760
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0M@$$CBVValue@456@PEAVRectangle@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433810
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0N@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433850
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0O@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424338b0
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0P@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433920
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BA@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424339b0
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BB@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433a10
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BC@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433a70
// MS2-PIN: ?Func@?$ThunkFunc1@VLoaderInfo@fl_display@Classes@AS3@GFx@Scaleform@@$0A@V?$SPtr@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433ad0
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BD@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433c90
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BE@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433d00
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VAccessibilityProperties@fl_accessibility@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433d70
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BF@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433e20
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@PEAVAccessibilityProperties@fl_accessibility@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433f20
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BG@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433f60
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$01N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142433fd0
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BH@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434040
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434140
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BI@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424341d0
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434230
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BJ@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424342a0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434300
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BK@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434540
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$05_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424345a0
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BL@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434600
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434660
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BM@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424346c0
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$07V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434720
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BN@$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434830
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@PEAVArray@fl@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424348a0
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BO@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424348e0
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$09N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434940
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0BP@$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424349b0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434a20
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CA@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434ab0
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0M@V?$SPtr@VLoaderInfo@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434b10
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434bc0
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0N@V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434c20
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CB@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434cd0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434d30
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CC@V?$SPtr@VTextSnapshot@fl_text@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434d90
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0O@$$CBVValue@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434e40
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$01J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434e80
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CD@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434ee0
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0P@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434f50
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142434fc0
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BA@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142435020
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CE@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142435090
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142435120
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BB@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424352c0
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CF@V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@PEAVDisplayObject@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142435330
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$04V?$SPtr@VTextSnapshot@fl_text@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142435420
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BC@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142435610
// MS2-PIN: ?Func@?$ThunkFunc2@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CG@V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@PEAVDisplayObject@23456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142435710
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$05V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@PEAVDisplayObject@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142435830
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BD@V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142435920
// MS2-PIN: ?Func@?$ThunkFunc2@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$06V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@PEAVDisplayObject@23456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424359d0
// MS2-PIN: ?Func@?$ThunkFunc5@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CH@$$CBVValue@456@AEBVASString@56@AEBV7456@_NJ_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142435af0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BE@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142435d90
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$07_NPEAVPoint@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142435ee0
// MS2-PIN: ?Func@?$ThunkFunc2@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CI@$$CBVValue@456@PEAVInteractiveObject@23456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142435f80
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BF@V?$SPtr@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424360b0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$08_NPEAVDisplayObject@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436160
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CJ@_NPEAVEvent@fl_events@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436200
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BG@V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424362a0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$09V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436350
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CK@_NAEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436450
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BH@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436590
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$0L@V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436600
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CL@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436780
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BI@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424367a0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$0M@JPEAVDisplayObject@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436830
// MS2-PIN: ?Func@?$ThunkFunc0@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CM@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424368d0
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BJ@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436930
// MS2-PIN: ?Func@?$ThunkFunc0@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0A@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424369a0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$0N@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@PEAVPoint@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436a00
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CN@V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436af0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BK@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436bf0
// MS2-PIN: ?Func@?$ThunkFunc0@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$00V?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436c80
// MS2-PIN: ?Func@?$ThunkFunc2@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$0O@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436d30
// MS2-PIN: ?Func@?$ThunkFunc3@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CO@$$CBVValue@456@AEBVASString@56@AEBV7456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436d50
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BL@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436f60
// MS2-PIN: ?Func@?$ThunkFunc0@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142436fd0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$0P@V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437030
// MS2-PIN: ?Func@?$ThunkFunc2@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0CP@$$CBVValue@456@PEAVDisplayObject@23456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437130
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BM@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424371e0
// MS2-PIN: ?Func@?$ThunkFunc0@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$02J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437270
// MS2-PIN: ?Func@?$ThunkFunc2@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$0BA@$$CBVValue@456@PEAVDisplayObject@23456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424372d0
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BN@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437380
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0DA@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424373f0
// MS2-PIN: ?Func@?$ThunkFunc4@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@PEAV123456@PEAVRectangle@fl_geom@3456@PEAVPoint@93456@PEAVBitmapFilter@fl_filters@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424374f0
// MS2-PIN: ?Func@?$ThunkFunc2@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$0BB@$$CBVValue@456@PEAVDisplayObject@23456@PEAV823456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424375a0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BO@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424375f0
// MS2-PIN: ?Func@?$ThunkFunc2@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0DB@$$CBVValue@456@JJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437680
// MS2-PIN: ?Func@?$ThunkFunc0@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$04V?$SPtr@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437870
// MS2-PIN: ?Func@?$ThunkFunc2@VDisplayObjectContainer@fl_display@Instances@AS3@GFx@Scaleform@@$0BC@$$CBVValue@456@JJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437920
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0BP@V?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424379d0
// MS2-PIN: ?Func@?$ThunkFunc1@VStage@fl_display@Instances@AS3@GFx@Scaleform@@$0DC@_NAEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437a80
// MS2-PIN: ?Func@?$ThunkFunc2@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@PEAVRectangle@fl_geom@3456@PEAVColorTransform@93456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437bc0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CA@$$CBVValue@456@PEAVRectangle@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437c10
// MS2-PIN: ?Func@?$ThunkFunc1@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$06VValue@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437c50
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CB@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437c90
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CC@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437d00
// MS2-PIN: ?Func@?$ThunkFunc5@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@PEAV123456@PEAVRectangle@fl_geom@3456@PEAVPoint@93456@KK@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437d90
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CD@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437ee0
// MS2-PIN: ?Func@?$ThunkFunc6@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@PEAV123456@PEAVRectangle@fl_geom@3456@PEAVPoint@93456@PEAV123456@PEAVPoint@93456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142437f50
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CE@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438080
// MS2-PIN: ?Func@?$ThunkFunc0@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$09$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438110
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CF@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438270
// MS2-PIN: ?Func@?$ThunkFunc6@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@PEAVObject@fl@3456@PEAVMatrix@fl_geom@3456@PEAVColorTransform@fl_geom@3456@AEBVASString@56@PEAVRectangle@fl_geom@3456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424382e0
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CG@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438460
// MS2-PIN: ?Func@?$ThunkFunc2@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0M@$$CBVValue@456@PEAVRectangle@fl_geom@3456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424384f0
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CH@V?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424385a0
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$0A@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438650
// MS2-PIN: ?Func@?$ThunkFunc1@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CI@$$CBVValue@456@PEAVRectangle@fl_geom@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424386b0
// MS2-PIN: ?Func@?$ThunkFunc3@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@JJK@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424386f0
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$00VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424387e0
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CJ@V?$SPtr@VStage@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438850
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$01VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438900
// MS2-PIN: ?Func@?$ThunkFunc2@VBitmapData@fl_display@Instances@AS3@GFx@Scaleform@@$0O@V?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAVRectangle@fl_geom@3456@PEAVBitmapFilter@fl_filters@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438970
// MS2-PIN: ?Func@?$ThunkFunc0@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@$0CK@V?$SPtr@VTransform@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438a80
// MS2-PIN: ?Func@?$ThunkFunc0@VMovieClip@fl_display@Instances@AS3@GFx@Scaleform@@$02V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142438b30
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@U?$HashNode@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@@Scaleform@@$0BEJ@@2@V?$HashsetCachedNodeEntry@U?$HashNode@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x14242a640
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@_KVValue@AS3@GFx@Scaleform@@V?$FixedSizeHash@_K@4@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorDH@U?$HashNode@_KVValue@AS3@GFx@Scaleform@@V?$FixedSizeHash@_K@4@@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@_KVValue@AS3@GFx@Scaleform@@V?$FixedSizeHash@_K@4@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x14242a870
// MS2-PIN: ?setRawCapacity@?$HashSetBase@VASString@GFx@Scaleform@@V?$FixedSizeHash@VASString@GFx@Scaleform@@@3@V43@U?$AllocatorDH@VASString@GFx@Scaleform@@$01@3@V?$HashsetCachedEntry@VASString@GFx@Scaleform@@V?$FixedSizeHash@VASString@GFx@Scaleform@@@3@@3@@Scaleform@@AEAAXPEAX_K@Z 0x14242aaa0
// MS2-PIN: ?setRawCapacity@?$HashSetBase@VValue@AS3@GFx@Scaleform@@UHashFunctor@1234@U51234@U?$AllocatorGH@VValue@AS3@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@VValue@AS3@GFx@Scaleform@@UHashFunctor@1234@@4@@Scaleform@@AEAAXPEAX_K@Z 0x14242ac40
// MS2-PIN: ??_7ActionScriptVersion@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x143149790
// MS2-PIN: ??_7ActionScriptVersion@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431496f0
// MS2-PIN: ??_7AVM1Movie@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143149fe0
// MS2-PIN: ??_7AVM1Movie@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143149f38
// MS2-PIN: ??_7BitmapDataChannel@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314ad50
// MS2-PIN: ??_7BitmapDataChannel@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314acb8
// MS2-PIN: ??_7Bitmap@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314a428
// MS2-PIN: ??_7Bitmap@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314a388
// MS2-PIN: ??_7BlendMode@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314a840
// MS2-PIN: ??_7BlendMode@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314a7b0
// MS2-PIN: ??_7CapsStyle@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314af48
// MS2-PIN: ??_7CapsStyle@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314aeb8
// MS2-PIN: ??_7DisplayObjectContainer@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314b1c8
// MS2-PIN: ??_7DisplayObjectContainer@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314b118
// MS2-PIN: ??_7FrameLabel@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314bf68
// MS2-PIN: ??_7FrameLabel@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314bec0
// MS2-PIN: ??_7GradientType@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314c090
// MS2-PIN: ??_7GradientType@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314bff8
// MS2-PIN: ??_7Graphics@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314c2f8
// MS2-PIN: ??_7Graphics@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314c250
// MS2-PIN: ??_7IBitmapDrawable@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314a718
// MS2-PIN: ??_7InteractiveObject@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314a648
// MS2-PIN: ??_7InteractiveObject@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314a598
// MS2-PIN: ??_7InterpolationMethod@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314c528
// MS2-PIN: ??_7InterpolationMethod@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314c488
// MS2-PIN: ??_7JointStyle@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314c6b0
// MS2-PIN: ??_7JointStyle@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314c620
// MS2-PIN: ??_7LineScaleMode@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314c830
// MS2-PIN: ??_7LineScaleMode@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314c798
// MS2-PIN: ??_7Loader@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314b3d8
// MS2-PIN: ??_7Loader@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314b338
// MS2-PIN: ??_7LoaderInfo@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314b950
// MS2-PIN: ??_7LoaderInfo@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314b8c0
// MS2-PIN: ??_7LoaderInfo@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314b818
// MS2-PIN: ??_7MorphShape@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314ce50
// MS2-PIN: ??_7MorphShape@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314cda8
// MS2-PIN: ??_7MovieClip@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314d290
// MS2-PIN: ??_7MovieClip@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314d1e8
// MS2-PIN: ??_7PixelSnapping@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314d5c8
// MS2-PIN: ??_7PixelSnapping@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314d530
// MS2-PIN: ??_7Scene@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314d488
// MS2-PIN: ??_7Scene@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314d3e8
// MS2-PIN: ??_7ShaderData@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314ead8
// MS2-PIN: ??_7Shader@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314eb68
// MS2-PIN: ??_7Shape@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314d840
// MS2-PIN: ??_7Shape@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314d7a0
// MS2-PIN: ??_7SimpleButton@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314da50
// MS2-PIN: ??_7SimpleButton@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314d9a8
// MS2-PIN: ??_7SpreadMethod@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314dc20
// MS2-PIN: ??_7SpreadMethod@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314db88
// MS2-PIN: ??_7Sprite@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314d068
// MS2-PIN: ??_7Sprite@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314cfc8
// MS2-PIN: ??_7StageAlign@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314e3a0
// MS2-PIN: ??_7StageAlign@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314e310
// MS2-PIN: ??_7StageDisplayState@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314e528
// MS2-PIN: ??_7StageDisplayState@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314e490
// MS2-PIN: ??_7Stage@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314b668
// MS2-PIN: ??_7Stage@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314b5d8
// MS2-PIN: ??_7Stage@fl_display@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14314b538
// MS2-PIN: ??_7StageQuality@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314e6d8
// MS2-PIN: ??_7StageQuality@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314e640
// MS2-PIN: ??_7StageScaleMode@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314e878
// MS2-PIN: ??_7StageScaleMode@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314e7e0
// MS2-PIN: ??_7SWFVersion@fl_display@Classes@AS3@GFx@Scaleform@@6B@ 0x14314e9f0
// MS2-PIN: ??_7SWFVersion@fl_display@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314e960
