// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_10
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142473710-0x1424837b0 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/render/render_filters.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x142473af0: Instances::fl_filters::BevelFilter::angleGet
template struct ThunkFunc0<Instances::fl_filters::BevelFilter, 0, Value::Number>;
// thunk 0x142473b60: Instances::fl_filters::BevelFilter::angleSet
template struct ThunkFunc1<Instances::fl_filters::BevelFilter, 1, const Value, Value::Number>;
// thunk 0x142473bf0: Instances::fl_filters::BevelFilter::blurXGet
template struct ThunkFunc0<Instances::fl_filters::BevelFilter, 2, Value::Number>;
// thunk 0x142473c60: Instances::fl_filters::BevelFilter::blurXSet
template struct ThunkFunc1<Instances::fl_filters::BevelFilter, 3, const Value, Value::Number>;
// thunk 0x142473cf0: Instances::fl_filters::BevelFilter::blurYGet
template struct ThunkFunc0<Instances::fl_filters::BevelFilter, 4, Value::Number>;
// thunk 0x142473d60: Instances::fl_filters::BevelFilter::blurYSet
template struct ThunkFunc1<Instances::fl_filters::BevelFilter, 5, const Value, Value::Number>;
// thunk 0x142473df0: Instances::fl_filters::BevelFilter::distanceGet
template struct ThunkFunc0<Instances::fl_filters::BevelFilter, 6, Value::Number>;
// thunk 0x142473e60: Instances::fl_filters::BevelFilter::distanceSet
template struct ThunkFunc1<Instances::fl_filters::BevelFilter, 7, const Value, Value::Number>;
// thunk 0x142473ef0: Instances::fl_filters::BevelFilter::highlightAlphaGet
template struct ThunkFunc0<Instances::fl_filters::BevelFilter, 8, Value::Number>;
// thunk 0x142473f60: Instances::fl_filters::BevelFilter::highlightAlphaSet
template struct ThunkFunc1<Instances::fl_filters::BevelFilter, 9, const Value, Value::Number>;
// thunk 0x142473ff0: Instances::fl_filters::BevelFilter::highlightColorGet
template struct ThunkFunc0<Instances::fl_filters::BevelFilter, 10, UInt32>;
// thunk 0x142474050: Instances::fl_filters::BevelFilter::highlightColorSet
template struct ThunkFunc1<Instances::fl_filters::BevelFilter, 11, const Value, UInt32>;
// thunk 0x1424740c0: Instances::fl_filters::BevelFilter::knockoutGet
template struct ThunkFunc0<Instances::fl_filters::BevelFilter, 12, bool>;
// thunk 0x142474120: Instances::fl_filters::BevelFilter::knockoutSet
template struct ThunkFunc1<Instances::fl_filters::BevelFilter, 13, const Value, bool>;
// thunk 0x142474180: Instances::fl_filters::BevelFilter::qualityGet
template struct ThunkFunc0<Instances::fl_filters::BevelFilter, 14, SInt32>;
// thunk 0x1424741e0: Instances::fl_filters::BevelFilter::qualitySet
template struct ThunkFunc1<Instances::fl_filters::BevelFilter, 15, const Value, SInt32>;
// thunk 0x142474250: Instances::fl_filters::BevelFilter::shadowAlphaGet
template struct ThunkFunc0<Instances::fl_filters::BevelFilter, 16, Value::Number>;
// thunk 0x1424742c0: Instances::fl_filters::BevelFilter::shadowAlphaSet
template struct ThunkFunc1<Instances::fl_filters::BevelFilter, 17, const Value, Value::Number>;
// thunk 0x142474350: Instances::fl_filters::BevelFilter::shadowColorGet
template struct ThunkFunc0<Instances::fl_filters::BevelFilter, 18, UInt32>;
// thunk 0x1424743b0: Instances::fl_filters::BevelFilter::shadowColorSet
template struct ThunkFunc1<Instances::fl_filters::BevelFilter, 19, const Value, UInt32>;
// thunk 0x142474420: Instances::fl_filters::BevelFilter::strengthGet
template struct ThunkFunc0<Instances::fl_filters::BevelFilter, 20, Value::Number>;
// thunk 0x142474490: Instances::fl_filters::BevelFilter::strengthSet
template struct ThunkFunc1<Instances::fl_filters::BevelFilter, 21, const Value, Value::Number>;
// thunk 0x142474520: Instances::fl_filters::BevelFilter::typeGet
template struct ThunkFunc0<Instances::fl_filters::BevelFilter, 22, ASString>;
// thunk 0x142474590: Instances::fl_filters::BevelFilter::typeSet
template struct ThunkFunc1<Instances::fl_filters::BevelFilter, 23, const Value, const ASString&>;
// thunk 0x142474690: Instances::fl_filters::BevelFilter::clone
template struct ThunkFunc0<Instances::fl_filters::BevelFilter, 24, SPtr<Instances::fl_filters::BitmapFilter>>;
// thunk 0x1424748b0: Instances::fl_filters::BitmapFilter::clone
template struct ThunkFunc0<Instances::fl_filters::BitmapFilter, 0, SPtr<Instances::fl_filters::BitmapFilter>>;
// thunk 0x142474d50: Instances::fl_filters::DropShadowFilter::alphaGet
template struct ThunkFunc0<Instances::fl_filters::DropShadowFilter, 0, Value::Number>;
// thunk 0x142474dc0: Instances::fl_filters::DropShadowFilter::alphaSet
template struct ThunkFunc1<Instances::fl_filters::DropShadowFilter, 1, const Value, Value::Number>;
// thunk 0x142474e50: Instances::fl_filters::DropShadowFilter::angleGet
template struct ThunkFunc0<Instances::fl_filters::DropShadowFilter, 2, Value::Number>;
// thunk 0x142474ec0: Instances::fl_filters::DropShadowFilter::angleSet
template struct ThunkFunc1<Instances::fl_filters::DropShadowFilter, 3, const Value, Value::Number>;
// thunk 0x142475090: Instances::fl_filters::DropShadowFilter::blurXGet
template struct ThunkFunc0<Instances::fl_filters::DropShadowFilter, 4, Value::Number>;
// thunk 0x142475100: Instances::fl_filters::DropShadowFilter::blurXSet
template struct ThunkFunc1<Instances::fl_filters::DropShadowFilter, 5, const Value, Value::Number>;
// thunk 0x142475190: Instances::fl_filters::BlurFilter::blurXGet
template struct ThunkFunc0<Instances::fl_filters::BlurFilter, 0, Value::Number>;
// thunk 0x142475200: Instances::fl_filters::DropShadowFilter::blurYGet
template struct ThunkFunc0<Instances::fl_filters::DropShadowFilter, 6, Value::Number>;
// thunk 0x142475270: Instances::fl_filters::BlurFilter::blurXSet
template struct ThunkFunc1<Instances::fl_filters::BlurFilter, 1, const Value, Value::Number>;
// thunk 0x142475300: Instances::fl_filters::DropShadowFilter::blurYSet
template struct ThunkFunc1<Instances::fl_filters::DropShadowFilter, 7, const Value, Value::Number>;
// thunk 0x142475390: Instances::fl_filters::BlurFilter::blurYGet
template struct ThunkFunc0<Instances::fl_filters::BlurFilter, 2, Value::Number>;
// thunk 0x142475400: Instances::fl_filters::DropShadowFilter::colorGet
template struct ThunkFunc0<Instances::fl_filters::DropShadowFilter, 8, UInt32>;
// thunk 0x142475460: Instances::fl_filters::BlurFilter::blurYSet
template struct ThunkFunc1<Instances::fl_filters::BlurFilter, 3, const Value, Value::Number>;
// thunk 0x1424754f0: Instances::fl_filters::DropShadowFilter::colorSet
template struct ThunkFunc1<Instances::fl_filters::DropShadowFilter, 9, const Value, UInt32>;
// thunk 0x142475560: Instances::fl_filters::BlurFilter::qualityGet
template struct ThunkFunc0<Instances::fl_filters::BlurFilter, 4, SInt32>;
// thunk 0x1424755c0: Instances::fl_filters::DropShadowFilter::distanceGet
template struct ThunkFunc0<Instances::fl_filters::DropShadowFilter, 10, Value::Number>;
// thunk 0x142475630: Instances::fl_filters::BlurFilter::qualitySet
template struct ThunkFunc1<Instances::fl_filters::BlurFilter, 5, const Value, SInt32>;
// thunk 0x1424756a0: Instances::fl_filters::DropShadowFilter::distanceSet
template struct ThunkFunc1<Instances::fl_filters::DropShadowFilter, 11, const Value, Value::Number>;
// thunk 0x142475730: Instances::fl_filters::BlurFilter::clone
template struct ThunkFunc0<Instances::fl_filters::BlurFilter, 6, SPtr<Instances::fl_filters::BitmapFilter>>;
// thunk 0x1424757e0: Instances::fl_filters::DropShadowFilter::hideObjectGet
template struct ThunkFunc0<Instances::fl_filters::DropShadowFilter, 12, bool>;
// thunk 0x142475840: Instances::fl_filters::DropShadowFilter::hideObjectSet
template struct ThunkFunc1<Instances::fl_filters::DropShadowFilter, 13, const Value, bool>;
// thunk 0x1424758a0: Instances::fl_filters::DropShadowFilter::innerGet
template struct ThunkFunc0<Instances::fl_filters::DropShadowFilter, 14, bool>;
// thunk 0x142475900: Instances::fl_filters::DropShadowFilter::innerSet
template struct ThunkFunc1<Instances::fl_filters::DropShadowFilter, 15, const Value, bool>;
// thunk 0x142475960: Instances::fl_filters::DropShadowFilter::knockoutGet
template struct ThunkFunc0<Instances::fl_filters::DropShadowFilter, 16, bool>;
// thunk 0x1424759c0: Instances::fl_filters::DropShadowFilter::knockoutSet
template struct ThunkFunc1<Instances::fl_filters::DropShadowFilter, 17, const Value, bool>;
// thunk 0x142475a20: Instances::fl_filters::DropShadowFilter::qualityGet
template struct ThunkFunc0<Instances::fl_filters::DropShadowFilter, 18, SInt32>;
// thunk 0x142475a80: Instances::fl_filters::DropShadowFilter::qualitySet
template struct ThunkFunc1<Instances::fl_filters::DropShadowFilter, 19, const Value, SInt32>;
// thunk 0x142475af0: Instances::fl_filters::DropShadowFilter::strengthGet
template struct ThunkFunc0<Instances::fl_filters::DropShadowFilter, 20, Value::Number>;
// thunk 0x142475b60: Instances::fl_filters::DropShadowFilter::strengthSet
template struct ThunkFunc1<Instances::fl_filters::DropShadowFilter, 21, const Value, Value::Number>;
// thunk 0x142475bf0: Instances::fl_filters::DropShadowFilter::clone
template struct ThunkFunc0<Instances::fl_filters::DropShadowFilter, 22, SPtr<Instances::fl_filters::BitmapFilter>>;
// thunk 0x142475f20: Instances::fl_filters::GlowFilter::alphaGet
template struct ThunkFunc0<Instances::fl_filters::GlowFilter, 0, Value::Number>;
// thunk 0x142475f90: Instances::fl_filters::GlowFilter::alphaSet
template struct ThunkFunc1<Instances::fl_filters::GlowFilter, 1, const Value, Value::Number>;
// thunk 0x142476020: Instances::fl_filters::GlowFilter::blurXGet
template struct ThunkFunc0<Instances::fl_filters::GlowFilter, 2, Value::Number>;
// thunk 0x142476090: Instances::fl_filters::GlowFilter::blurXSet
template struct ThunkFunc1<Instances::fl_filters::GlowFilter, 3, const Value, Value::Number>;
// thunk 0x142476120: Instances::fl_filters::GlowFilter::blurYGet
template struct ThunkFunc0<Instances::fl_filters::GlowFilter, 4, Value::Number>;
// thunk 0x142476190: Instances::fl_filters::GlowFilter::blurYSet
template struct ThunkFunc1<Instances::fl_filters::GlowFilter, 5, const Value, Value::Number>;
// thunk 0x142476220: Instances::fl_filters::GlowFilter::colorGet
template struct ThunkFunc0<Instances::fl_filters::GlowFilter, 6, UInt32>;
// thunk 0x142476280: Instances::fl_filters::GlowFilter::colorSet
template struct ThunkFunc1<Instances::fl_filters::GlowFilter, 7, const Value, UInt32>;
// thunk 0x1424762f0: Instances::fl_filters::GlowFilter::innerGet
template struct ThunkFunc0<Instances::fl_filters::GlowFilter, 8, bool>;
// thunk 0x142476350: Instances::fl_filters::GlowFilter::innerSet
template struct ThunkFunc1<Instances::fl_filters::GlowFilter, 9, const Value, bool>;
// thunk 0x1424763b0: Instances::fl_filters::GlowFilter::knockoutGet
template struct ThunkFunc0<Instances::fl_filters::GlowFilter, 10, bool>;
// thunk 0x142476410: Instances::fl_filters::GlowFilter::knockoutSet
template struct ThunkFunc1<Instances::fl_filters::GlowFilter, 11, const Value, bool>;
// thunk 0x142476470: Instances::fl_filters::GlowFilter::qualityGet
template struct ThunkFunc0<Instances::fl_filters::GlowFilter, 12, SInt32>;
// thunk 0x1424764d0: Instances::fl_filters::GlowFilter::qualitySet
template struct ThunkFunc1<Instances::fl_filters::GlowFilter, 13, const Value, SInt32>;
// thunk 0x142476540: Instances::fl_filters::GlowFilter::strengthGet
template struct ThunkFunc0<Instances::fl_filters::GlowFilter, 14, Value::Number>;
// thunk 0x1424765b0: Instances::fl_filters::GlowFilter::strengthSet
template struct ThunkFunc1<Instances::fl_filters::GlowFilter, 15, const Value, Value::Number>;
// thunk 0x142476640: Instances::fl_filters::GlowFilter::clone
template struct ThunkFunc0<Instances::fl_filters::GlowFilter, 16, SPtr<Instances::fl_filters::BitmapFilter>>;
// thunk 0x142476970: Instances::fl_filters::ColorMatrixFilter::matrixGet
template struct ThunkFunc0<Instances::fl_filters::ColorMatrixFilter, 0, SPtr<Instances::fl::Array>>;
// thunk 0x142476a20: Instances::fl_filters::ColorMatrixFilter::matrixSet
template struct ThunkFunc1<Instances::fl_filters::ColorMatrixFilter, 1, const Value, Instances::fl::Array*>;
// thunk 0x142476a60: Instances::fl_filters::ColorMatrixFilter::clone
template struct ThunkFunc0<Instances::fl_filters::ColorMatrixFilter, 2, SPtr<Instances::fl_filters::BitmapFilter>>;
// thunk 0x14247c430: Instances::fl_geom::Matrix::clone
template struct ThunkFunc0<Instances::fl_geom::Matrix, 0, SPtr<Instances::fl_geom::Matrix>>;
// thunk 0x14247c4e0: Instances::fl_geom::Matrix::concat
template struct ThunkFunc1<Instances::fl_geom::Matrix, 1, const Value, Instances::fl_geom::Matrix*>;
// Instances::fl_geom::Matrix::createBox argument 2 default
template <> struct ThunkMethodDefault<Instances::fl_geom::Matrix, 2, 2, Value::Number>
{
    SF_INLINE static Value::Number Get(StringManager&) { return 0.0; }
};
// Instances::fl_geom::Matrix::createBox argument 3 default
template <> struct ThunkMethodDefault<Instances::fl_geom::Matrix, 2, 3, Value::Number>
{
    SF_INLINE static Value::Number Get(StringManager&) { return 0.0; }
};
// Instances::fl_geom::Matrix::createBox argument 4 default
template <> struct ThunkMethodDefault<Instances::fl_geom::Matrix, 2, 4, Value::Number>
{
    SF_INLINE static Value::Number Get(StringManager&) { return 0.0; }
};
// thunk 0x14247c520: Instances::fl_geom::Matrix::createBox
template struct ThunkFunc5<Instances::fl_geom::Matrix, 2, const Value, Value::Number, Value::Number, Value::Number, Value::Number, Value::Number>;
// Instances::fl_geom::Matrix::createGradientBox argument 2 default
template <> struct ThunkMethodDefault<Instances::fl_geom::Matrix, 3, 2, Value::Number>
{
    SF_INLINE static Value::Number Get(StringManager&) { return 0.0; }
};
// Instances::fl_geom::Matrix::createGradientBox argument 3 default
template <> struct ThunkMethodDefault<Instances::fl_geom::Matrix, 3, 3, Value::Number>
{
    SF_INLINE static Value::Number Get(StringManager&) { return 0.0; }
};
// Instances::fl_geom::Matrix::createGradientBox argument 4 default
template <> struct ThunkMethodDefault<Instances::fl_geom::Matrix, 3, 4, Value::Number>
{
    SF_INLINE static Value::Number Get(StringManager&) { return 0.0; }
};
// thunk 0x14247c6a0: Instances::fl_geom::Matrix::createGradientBox
template struct ThunkFunc5<Instances::fl_geom::Matrix, 3, const Value, Value::Number, Value::Number, Value::Number, Value::Number, Value::Number>;
// thunk 0x14247c820: Instances::fl_geom::Matrix::deltaTransformPoint
template struct ThunkFunc1<Instances::fl_geom::Matrix, 4, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Point*>;
// thunk 0x14247c910: Instances::fl_geom::Matrix::identity
template struct ThunkFunc0<Instances::fl_geom::Matrix, 5, const Value>;
// thunk 0x14247c930: Instances::fl_geom::Matrix::invert
template struct ThunkFunc0<Instances::fl_geom::Matrix, 6, const Value>;
// thunk 0x14247c950: Instances::fl_geom::Matrix::rotate
template struct ThunkFunc1<Instances::fl_geom::Matrix, 7, const Value, Value::Number>;
// thunk 0x14247c9e0: Instances::fl_geom::Matrix::scale
template struct ThunkFunc2<Instances::fl_geom::Matrix, 8, const Value, Value::Number, Value::Number>;
// thunk 0x14247cac0: Instances::fl_geom::Matrix::toString
template struct ThunkFunc0<Instances::fl_geom::Matrix, 9, ASString>;
// thunk 0x14247cb30: Instances::fl_geom::Matrix::transformPoint
template struct ThunkFunc1<Instances::fl_geom::Matrix, 10, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Point*>;
// thunk 0x14247cc20: Instances::fl_geom::Matrix::translate
template struct ThunkFunc2<Instances::fl_geom::Matrix, 11, const Value, Value::Number, Value::Number>;
// thunk 0x14247cf80: Instances::fl_geom::PerspectiveProjection::projectionCenterGet
template struct ThunkFunc0<Instances::fl_geom::PerspectiveProjection, 0, SPtr<Instances::fl_geom::Point>>;
// thunk 0x14247d030: Instances::fl_geom::PerspectiveProjection::projectionCenterSet
template struct ThunkFunc1<Instances::fl_geom::PerspectiveProjection, 1, const Value, Instances::fl_geom::Point*>;
// thunk 0x14247d070: Instances::fl_geom::PerspectiveProjection::focalLengthGet
template struct ThunkFunc0<Instances::fl_geom::PerspectiveProjection, 2, Value::Number>;
// thunk 0x14247d0e0: Instances::fl_geom::PerspectiveProjection::focalLengthSet
template struct ThunkFunc1<Instances::fl_geom::PerspectiveProjection, 3, const Value, Value::Number>;
// thunk 0x14247d170: Instances::fl_geom::PerspectiveProjection::fieldOfViewGet
template struct ThunkFunc0<Instances::fl_geom::PerspectiveProjection, 4, Value::Number>;
// thunk 0x14247d1e0: Instances::fl_geom::PerspectiveProjection::fieldOfViewSet
template struct ThunkFunc1<Instances::fl_geom::PerspectiveProjection, 5, const Value, Value::Number>;
// thunk 0x14247d270: Instances::fl_geom::ColorTransform::colorGet
template struct ThunkFunc0<Instances::fl_geom::ColorTransform, 0, UInt32>;
// thunk 0x14247d2d0: Instances::fl_geom::PerspectiveProjection::toMatrix3D
template struct ThunkFunc0<Instances::fl_geom::PerspectiveProjection, 6, SPtr<Instances::fl_geom::Matrix3D>>;
// thunk 0x14247d380: Instances::fl_geom::ColorTransform::colorSet
template struct ThunkFunc1<Instances::fl_geom::ColorTransform, 1, const Value, UInt32>;
// thunk 0x14247d3f0: Instances::fl_geom::ColorTransform::concat
template struct ThunkFunc1<Instances::fl_geom::ColorTransform, 2, const Value, Instances::fl_geom::ColorTransform*>;
// thunk 0x14247d430: Instances::fl_geom::ColorTransform::toString
template struct ThunkFunc0<Instances::fl_geom::ColorTransform, 3, ASString>;
// thunk 0x14247d4a0: Instances::fl_geom::Point::lengthGet
template struct ThunkFunc0<Instances::fl_geom::Point, 0, Value::Number>;
// thunk 0x14247d510: Instances::fl_geom::Point::add
template struct ThunkFunc1<Instances::fl_geom::Point, 1, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Point*>;
// thunk 0x14247d600: Instances::fl_geom::Point::clone
template struct ThunkFunc0<Instances::fl_geom::Point, 2, SPtr<Instances::fl_geom::Point>>;
// thunk 0x14247d6b0: Instances::fl_geom::Point::equals
template struct ThunkFunc1<Instances::fl_geom::Point, 3, bool, Instances::fl_geom::Point*>;
// thunk 0x14247d750: Instances::fl_geom::Point::normalize
template struct ThunkFunc1<Instances::fl_geom::Point, 4, const Value, Value::Number>;
// thunk 0x14247d7e0: Instances::fl_geom::Point::offset
template struct ThunkFunc2<Instances::fl_geom::Point, 5, const Value, Value::Number, Value::Number>;
// thunk 0x14247d8c0: Instances::fl_geom::Point::subtract
template struct ThunkFunc1<Instances::fl_geom::Point, 6, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Point*>;
// thunk 0x14247d9b0: Instances::fl_geom::Point::toString
template struct ThunkFunc0<Instances::fl_geom::Point, 7, ASString>;
// thunk 0x14247da20: Classes::fl_geom::Point::distance
template struct ThunkFunc2<Classes::fl_geom::Point, 0, Value::Number, Instances::fl_geom::Point*, Instances::fl_geom::Point*>;
// thunk 0x14247daf0: Classes::fl_geom::Point::interpolate
template struct ThunkFunc3<Classes::fl_geom::Point, 1, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Point*, Instances::fl_geom::Point*, Value::Number>;
// thunk 0x14247dc60: Classes::fl_geom::Point::polar
template struct ThunkFunc2<Classes::fl_geom::Point, 2, SPtr<Instances::fl_geom::Point>, Value::Number, Value::Number>;
// thunk 0x14247df10: Instances::fl_geom::Vector3D::lengthGet
template struct ThunkFunc0<Instances::fl_geom::Vector3D, 0, Value::Number>;
// thunk 0x14247df80: Instances::fl_geom::Vector3D::lengthSquaredGet
template struct ThunkFunc0<Instances::fl_geom::Vector3D, 1, Value::Number>;
// thunk 0x14247dff0: Instances::fl_geom::Vector3D::xSet
template struct ThunkFunc1<Instances::fl_geom::Vector3D, 2, const Value, Value::Number>;
// thunk 0x14247e080: Instances::fl_geom::Vector3D::xGet
template struct ThunkFunc0<Instances::fl_geom::Vector3D, 3, Value::Number>;
// thunk 0x14247e0f0: Instances::fl_geom::Vector3D::ySet
template struct ThunkFunc1<Instances::fl_geom::Vector3D, 4, const Value, Value::Number>;
// thunk 0x14247e180: Instances::fl_geom::Vector3D::yGet
template struct ThunkFunc0<Instances::fl_geom::Vector3D, 5, Value::Number>;
// thunk 0x14247e1f0: Instances::fl_geom::Vector3D::zSet
template struct ThunkFunc1<Instances::fl_geom::Vector3D, 6, const Value, Value::Number>;
// thunk 0x14247e280: Instances::fl_geom::Vector3D::zGet
template struct ThunkFunc0<Instances::fl_geom::Vector3D, 7, Value::Number>;
// thunk 0x14247e2f0: Instances::fl_geom::Vector3D::wSet
template struct ThunkFunc1<Instances::fl_geom::Vector3D, 8, const Value, Value::Number>;
// thunk 0x14247e380: Instances::fl_geom::Vector3D::wGet
template struct ThunkFunc0<Instances::fl_geom::Vector3D, 9, Value::Number>;
// thunk 0x14247e3f0: Instances::fl_geom::Vector3D::add
template struct ThunkFunc1<Instances::fl_geom::Vector3D, 10, SPtr<Instances::fl_geom::Vector3D>, Instances::fl_geom::Vector3D*>;
// thunk 0x14247e620: Instances::fl_geom::Vector3D::clone
template struct ThunkFunc0<Instances::fl_geom::Vector3D, 11, SPtr<Instances::fl_geom::Vector3D>>;
// thunk 0x14247e6d0: Instances::fl_geom::Vector3D::crossProduct
template struct ThunkFunc1<Instances::fl_geom::Vector3D, 12, SPtr<Instances::fl_geom::Vector3D>, Instances::fl_geom::Vector3D*>;
// thunk 0x14247e7c0: Instances::fl_geom::Rectangle::bottomGet
template struct ThunkFunc0<Instances::fl_geom::Rectangle, 0, Value::Number>;
// thunk 0x14247e830: Instances::fl_geom::Vector3D::decrementBy
template struct ThunkFunc1<Instances::fl_geom::Vector3D, 13, const Value, Instances::fl_geom::Vector3D*>;
// thunk 0x14247e870: Instances::fl_geom::Rectangle::bottomSet
template struct ThunkFunc1<Instances::fl_geom::Rectangle, 1, const Value, Value::Number>;
// thunk 0x14247e900: Instances::fl_geom::Vector3D::dotProduct
template struct ThunkFunc1<Instances::fl_geom::Vector3D, 14, Value::Number, Instances::fl_geom::Vector3D*>;
// thunk 0x14247e9b0: Instances::fl_geom::Rectangle::bottomRightGet
template struct ThunkFunc0<Instances::fl_geom::Rectangle, 2, SPtr<Instances::fl_geom::Point>>;
// thunk 0x14247ea60: Instances::fl_geom::Vector3D::equals
template struct ThunkFunc2<Instances::fl_geom::Vector3D, 15, bool, Instances::fl_geom::Vector3D*, bool>;
// thunk 0x14247eb40: Instances::fl_geom::Rectangle::bottomRightSet
template struct ThunkFunc1<Instances::fl_geom::Rectangle, 3, const Value, Instances::fl_geom::Point*>;
// thunk 0x14247eb80: Instances::fl_geom::Vector3D::incrementBy
template struct ThunkFunc1<Instances::fl_geom::Vector3D, 16, const Value, Instances::fl_geom::Vector3D*>;
// thunk 0x14247ebc0: Instances::fl_geom::Rectangle::leftGet
template struct ThunkFunc0<Instances::fl_geom::Rectangle, 4, Value::Number>;
// thunk 0x14247ec30: Instances::fl_geom::Vector3D::nearEquals
template struct ThunkFunc3<Instances::fl_geom::Vector3D, 17, bool, Instances::fl_geom::Vector3D*, Value::Number, bool>;
// thunk 0x14247ed60: Instances::fl_geom::Rectangle::leftSet
template struct ThunkFunc1<Instances::fl_geom::Rectangle, 5, const Value, Value::Number>;
// thunk 0x14247edf0: Instances::fl_geom::Vector3D::negate
template struct ThunkFunc0<Instances::fl_geom::Vector3D, 18, const Value>;
// thunk 0x14247ee10: Instances::fl_geom::Rectangle::rightGet
template struct ThunkFunc0<Instances::fl_geom::Rectangle, 6, Value::Number>;
// thunk 0x14247ee80: Instances::fl_geom::Vector3D::normalize
template struct ThunkFunc0<Instances::fl_geom::Vector3D, 19, Value::Number>;
// thunk 0x14247eef0: Instances::fl_geom::Rectangle::rightSet
template struct ThunkFunc1<Instances::fl_geom::Rectangle, 7, const Value, Value::Number>;
// thunk 0x14247ef80: Instances::fl_geom::Vector3D::project
template struct ThunkFunc0<Instances::fl_geom::Vector3D, 20, const Value>;
// thunk 0x14247efa0: Instances::fl_geom::Rectangle::sizeGet
template struct ThunkFunc0<Instances::fl_geom::Rectangle, 8, SPtr<Instances::fl_geom::Point>>;
// thunk 0x14247f050: Instances::fl_geom::Vector3D::scaleBy
template struct ThunkFunc1<Instances::fl_geom::Vector3D, 21, const Value, Value::Number>;
// thunk 0x14247f0e0: Instances::fl_geom::Rectangle::sizeSet
template struct ThunkFunc1<Instances::fl_geom::Rectangle, 9, const Value, Instances::fl_geom::Point*>;
// thunk 0x14247f120: Instances::fl_geom::Vector3D::subtract
template struct ThunkFunc1<Instances::fl_geom::Vector3D, 22, SPtr<Instances::fl_geom::Vector3D>, Instances::fl_geom::Vector3D*>;
// thunk 0x14247f210: Instances::fl_geom::Rectangle::topGet
template struct ThunkFunc0<Instances::fl_geom::Rectangle, 10, Value::Number>;
// thunk 0x14247f280: Instances::fl_geom::Vector3D::toString
template struct ThunkFunc0<Instances::fl_geom::Vector3D, 23, ASString>;
// thunk 0x14247f2f0: Instances::fl_geom::Rectangle::topSet
template struct ThunkFunc1<Instances::fl_geom::Rectangle, 11, const Value, Value::Number>;
// thunk 0x14247f380: Instances::fl_geom::Rectangle::topLeftGet
template struct ThunkFunc0<Instances::fl_geom::Rectangle, 12, SPtr<Instances::fl_geom::Point>>;
// thunk 0x14247f430: Instances::fl_geom::Rectangle::topLeftSet
template struct ThunkFunc1<Instances::fl_geom::Rectangle, 13, const Value, Instances::fl_geom::Point*>;
// thunk 0x14247f470: Instances::fl_geom::Rectangle::clone
template struct ThunkFunc0<Instances::fl_geom::Rectangle, 14, SPtr<Instances::fl_geom::Rectangle>>;
// thunk 0x14247f520: Instances::fl_geom::Rectangle::contains
template struct ThunkFunc2<Instances::fl_geom::Rectangle, 15, bool, Value::Number, Value::Number>;
// thunk 0x14247f650: Instances::fl_geom::Rectangle::containsPoint
template struct ThunkFunc1<Instances::fl_geom::Rectangle, 16, bool, Instances::fl_geom::Point*>;
// thunk 0x14247f6f0: Instances::fl_geom::Rectangle::containsRect
template struct ThunkFunc1<Instances::fl_geom::Rectangle, 17, bool, Instances::fl_geom::Rectangle*>;
// thunk 0x14247f790: Instances::fl_geom::Rectangle::equals
template struct ThunkFunc1<Instances::fl_geom::Rectangle, 18, bool, Instances::fl_geom::Rectangle*>;
// thunk 0x14247f830: Instances::fl_geom::Rectangle::inflate
template struct ThunkFunc2<Instances::fl_geom::Rectangle, 19, const Value, Value::Number, Value::Number>;
// thunk 0x14247f910: Instances::fl_geom::Rectangle::inflatePoint
template struct ThunkFunc1<Instances::fl_geom::Rectangle, 20, const Value, Instances::fl_geom::Point*>;
// thunk 0x14247f950: Instances::fl_geom::Rectangle::intersection
template struct ThunkFunc1<Instances::fl_geom::Rectangle, 21, SPtr<Instances::fl_geom::Rectangle>, Instances::fl_geom::Rectangle*>;
// thunk 0x14247fa40: Classes::fl_geom::Vector3D::angleBetween
template struct ThunkFunc2<Classes::fl_geom::Vector3D, 0, Value::Number, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*>;
// thunk 0x14247fb10: Instances::fl_geom::Rectangle::intersects
template struct ThunkFunc1<Instances::fl_geom::Rectangle, 22, bool, Instances::fl_geom::Rectangle*>;
// thunk 0x14247fbb0: Classes::fl_geom::Vector3D::distance
template struct ThunkFunc2<Classes::fl_geom::Vector3D, 1, Value::Number, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*>;
// thunk 0x14247fc80: Instances::fl_geom::Rectangle::isEmpty
template struct ThunkFunc0<Instances::fl_geom::Rectangle, 23, bool>;
// thunk 0x14247fce0: Instances::fl_geom::Rectangle::offset
template struct ThunkFunc2<Instances::fl_geom::Rectangle, 24, const Value, Value::Number, Value::Number>;
// thunk 0x14247fdc0: Instances::fl_geom::Rectangle::offsetPoint
template struct ThunkFunc1<Instances::fl_geom::Rectangle, 25, const Value, Instances::fl_geom::Point*>;
// thunk 0x14247fe00: Instances::fl_geom::Rectangle::setEmpty
template struct ThunkFunc0<Instances::fl_geom::Rectangle, 26, const Value>;
// thunk 0x14247fe20: Instances::fl_geom::Rectangle::toString
template struct ThunkFunc0<Instances::fl_geom::Rectangle, 27, ASString>;
// thunk 0x14247fe90: Instances::fl_geom::Rectangle::union_
template struct ThunkFunc1<Instances::fl_geom::Rectangle, 28, SPtr<Instances::fl_geom::Rectangle>, Instances::fl_geom::Rectangle*>;
// thunk 0x1424800c0: Instances::fl_geom::Transform::colorTransformGet
template struct ThunkFunc0<Instances::fl_geom::Transform, 0, SPtr<Instances::fl_geom::ColorTransform>>;
// thunk 0x142480170: Instances::fl_geom::Transform::colorTransformSet
template struct ThunkFunc1<Instances::fl_geom::Transform, 1, const Value, Instances::fl_geom::ColorTransform*>;
// thunk 0x1424801b0: Instances::fl_geom::Transform::concatenatedColorTransformGet
template struct ThunkFunc0<Instances::fl_geom::Transform, 2, SPtr<Instances::fl_geom::ColorTransform>>;
// thunk 0x142480260: Instances::fl_geom::Transform::concatenatedMatrixGet
template struct ThunkFunc0<Instances::fl_geom::Transform, 3, SPtr<Instances::fl_geom::Matrix>>;
// thunk 0x142480310: Instances::fl_geom::Transform::matrixGet
template struct ThunkFunc0<Instances::fl_geom::Transform, 4, SPtr<Instances::fl_geom::Matrix>>;
// thunk 0x1424803c0: Instances::fl_geom::Transform::matrixSet
template struct ThunkFunc1<Instances::fl_geom::Transform, 5, const Value, Instances::fl_geom::Matrix*>;
// thunk 0x142480400: Instances::fl_geom::Transform::matrix3DGet
template struct ThunkFunc0<Instances::fl_geom::Transform, 6, SPtr<Instances::fl_geom::Matrix3D>>;
// thunk 0x1424804b0: Instances::fl_geom::Transform::matrix3DSet
template struct ThunkFunc1<Instances::fl_geom::Transform, 7, const Value, Instances::fl_geom::Matrix3D*>;
// thunk 0x1424804f0: Instances::fl_geom::Transform::perspectiveProjectionGet
template struct ThunkFunc0<Instances::fl_geom::Transform, 8, SPtr<Instances::fl_geom::PerspectiveProjection>>;
// thunk 0x1424805a0: Instances::fl_geom::Transform::perspectiveProjectionSet
template struct ThunkFunc1<Instances::fl_geom::Transform, 9, const Value, Instances::fl_geom::PerspectiveProjection*>;
// thunk 0x1424805e0: Instances::fl_geom::Transform::pixelBoundsGet
template struct ThunkFunc0<Instances::fl_geom::Transform, 10, SPtr<Instances::fl_geom::Rectangle>>;
// thunk 0x142480690: Instances::fl_geom::Transform::getRelativeMatrix3D
template struct ThunkFunc1<Instances::fl_geom::Transform, 11, SPtr<Instances::fl_geom::Matrix3D>, Instances::fl_display::DisplayObject*>;
// thunk 0x142480780: Instances::fl_geom::Matrix3D::determinantGet
template struct ThunkFunc0<Instances::fl_geom::Matrix3D, 0, Value::Number>;
// thunk 0x1424807f0: Instances::fl_geom::Matrix3D::positionGet
template struct ThunkFunc0<Instances::fl_geom::Matrix3D, 1, SPtr<Instances::fl_geom::Vector3D>>;
// thunk 0x1424808a0: Instances::fl_geom::Matrix3D::positionSet
template struct ThunkFunc1<Instances::fl_geom::Matrix3D, 2, const Value, Instances::fl_geom::Vector3D*>;
// thunk 0x1424808e0: Instances::fl_geom::Matrix3D::rawDataGet
template struct ThunkFunc0<Instances::fl_geom::Matrix3D, 3, SPtr<Instances::fl_vec::Vector_double>>;
// thunk 0x142480990: Instances::fl_geom::Matrix3D::rawDataSet
template struct ThunkFunc1<Instances::fl_geom::Matrix3D, 4, const Value, Instances::fl_vec::Vector_double*>;
// thunk 0x1424809d0: Instances::fl_geom::Matrix3D::append
template struct ThunkFunc1<Instances::fl_geom::Matrix3D, 5, const Value, Instances::fl_geom::Matrix3D*>;
// thunk 0x142480b50: Instances::fl_geom::Matrix3D::appendRotation
template struct ThunkFunc3<Instances::fl_geom::Matrix3D, 6, const Value, Value::Number, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*>;
// thunk 0x142480c50: Instances::fl_geom::Matrix3D::appendScale
template struct ThunkFunc3<Instances::fl_geom::Matrix3D, 7, const Value, Value::Number, Value::Number, Value::Number>;
// thunk 0x142480d80: Instances::fl_geom::Matrix3D::appendTranslation
template struct ThunkFunc3<Instances::fl_geom::Matrix3D, 8, const Value, Value::Number, Value::Number, Value::Number>;
// thunk 0x142480eb0: Instances::fl_geom::Matrix3D::clone
template struct ThunkFunc0<Instances::fl_geom::Matrix3D, 9, SPtr<Instances::fl_geom::Matrix3D>>;
// Instances::fl_geom::Matrix3D::decompose argument 0 default
template <> struct ThunkMethodDefault<Instances::fl_geom::Matrix3D, 10, 0, const ASString&>
{
    SF_INLINE static ASString Get(StringManager& sm) { return sm.CreateConstString("eulerAngles"); }
};
// thunk 0x142480f60: Instances::fl_geom::Matrix3D::decompose
template struct ThunkFunc1<Instances::fl_geom::Matrix3D, 10, SPtr<Instances::fl_vec::Vector_object>, const ASString&>;
// thunk 0x1424810f0: Instances::fl_geom::Matrix3D::deltaTransformVector
template struct ThunkFunc1<Instances::fl_geom::Matrix3D, 11, SPtr<Instances::fl_geom::Vector3D>, Instances::fl_geom::Vector3D*>;
// thunk 0x1424811e0: Instances::fl_geom::Matrix3D::identity
template struct ThunkFunc0<Instances::fl_geom::Matrix3D, 12, const Value>;
// thunk 0x142481200: Instances::fl_geom::Matrix3D::interpolate
template struct ThunkFunc3<Instances::fl_geom::Matrix3D, 13, SPtr<Instances::fl_geom::Matrix3D>, Instances::fl_geom::Matrix3D*, Instances::fl_geom::Matrix3D*, Value::Number>;
// thunk 0x142481370: Instances::fl_geom::Matrix3D::interpolateTo
template struct ThunkFunc2<Instances::fl_geom::Matrix3D, 14, const Value, Instances::fl_geom::Matrix3D*, Value::Number>;
// thunk 0x142481430: Instances::fl_geom::Matrix3D::invert
template struct ThunkFunc0<Instances::fl_geom::Matrix3D, 15, bool>;
// thunk 0x142481490: Instances::fl_geom::Matrix3D::pointAt
template struct ThunkFunc3<Instances::fl_geom::Matrix3D, 16, const Value, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*>;
// thunk 0x142481510: Instances::fl_geom::Matrix3D::prepend
template struct ThunkFunc1<Instances::fl_geom::Matrix3D, 17, const Value, Instances::fl_geom::Matrix3D*>;
// thunk 0x142481550: Instances::fl_geom::Matrix3D::prependRotation
template struct ThunkFunc3<Instances::fl_geom::Matrix3D, 18, const Value, Value::Number, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*>;
// thunk 0x142481650: Instances::fl_geom::Matrix3D::prependScale
template struct ThunkFunc3<Instances::fl_geom::Matrix3D, 19, const Value, Value::Number, Value::Number, Value::Number>;
// thunk 0x142481780: Instances::fl_geom::Matrix3D::prependTranslation
template struct ThunkFunc3<Instances::fl_geom::Matrix3D, 20, const Value, Value::Number, Value::Number, Value::Number>;
// Instances::fl_geom::Matrix3D::recompose argument 1 default
template <> struct ThunkMethodDefault<Instances::fl_geom::Matrix3D, 21, 1, const ASString&>
{
    SF_INLINE static ASString Get(StringManager& sm) { return sm.CreateConstString("eulerAngles"); }
};
// thunk 0x1424818b0: Instances::fl_geom::Matrix3D::recompose
template struct ThunkFunc2<Instances::fl_geom::Matrix3D, 21, bool, Instances::fl_vec::Vector_object*, const ASString&>;
// thunk 0x142481a30: Instances::fl_geom::Matrix3D::transformVector
template struct ThunkFunc1<Instances::fl_geom::Matrix3D, 22, SPtr<Instances::fl_geom::Vector3D>, Instances::fl_geom::Vector3D*>;
// thunk 0x142481b20: Instances::fl_geom::Matrix3D::transformVectors
template struct ThunkFunc2<Instances::fl_geom::Matrix3D, 23, const Value, Instances::fl_vec::Vector_double*, Instances::fl_vec::Vector_double*>;
// thunk 0x142481b70: Instances::fl_geom::Matrix3D::transpose
template struct ThunkFunc0<Instances::fl_geom::Matrix3D, 24, const Value>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// ==== flash.external.ExternalInterface (statics): the host's ExternalInterface handler of the movie ===============

namespace Scaleform { namespace GFx { namespace AS3 {

void Sfr21AddInvokeAlias(MovieRoot* self, const ASString& alias, const Value& closure);    // sfr_as3_16z

namespace Classes { namespace fl_external
{
    // ExternalInterface.addCallback(functionName, closure): the movie root invokes the closure for the alias.
    // @0x142473710
    void ExternalInterface::addCallback(const Value& result, const ASString& functionName, const Value& closure)
    {
        SF_UNUSED(result);
        Sfr21AddInvokeAlias(static_cast<ASVM&>(GetVM()).GetMovieRoot(), functionName, closure);
    }

    // ExternalInterface.available: whether the host installed an external interface handler.
    // @0x142473730
    void ExternalInterface::availableGet(bool& result)
    {
        result = static_cast<ASVM&>(GetVM()).GetMovieRoot()->GetMovieImpl()->pExtIntfHandler != NULL;
    }

    // ExternalInterface.call(methodName, ...args): hands the arguments, as host values, to the movie's external
    // interface handler and returns what the handler stored in the movie root.
    // MS2-FUNCTIONAL: same calls and data flow; the exe keeps the movie in a register (one more saved register, smaller frame) and merges the Convert2String failure exit into the common one
    // @0x142473760
    void ExternalInterface::call(Value& result, unsigned argc, const Value* argv)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        MovieRoot* root = asvm.GetMovieRoot();
        MovieImpl* movie = root->GetMovieImpl();
        if (movie->pExtIntfHandler)
        {
            unsigned nargs = 0;
            ASString methodName(asvm.GetStringManager().GetBuiltin(AS3Builtin_empty_));
            if (argc >= 1)
            {
                if (!argv[0].Convert2String(methodName))
                    return;
                nargs = argc - 1;
            }

            // Up to 10 arguments are converted on the stack.
            void* onStack[10 * (sizeof(GFx::Value) / sizeof(void*))];
            GFx::Value* args = (GFx::Value*)onStack;
            if (nargs > 10)
                args = (GFx::Value*)SF_HEAP_AUTO_ALLOC(this, nargs * sizeof(GFx::Value));
            for (unsigned i = 0; i < nargs; i++)
                root->ASValue2GFxValue(argv[i + 1], Scaleform::Construct<GFx::Value>(&args[i]));

            root->ExternalIntfRetVal.SetUndefined();
            movie->pExtIntfHandler->Callback(movie->AsMovie(), methodName.IsEmpty() ? NULL : methodName.ToCStr(), args, nargs);
            result.Assign(root->ExternalIntfRetVal);

            for (unsigned i = 0; i < nargs; i++)
                args[i].~Value();
            if (nargs > 10)
                SF_FREE(args);
        }
        else
        {
            asvm.GetUI().Output(FlashUI::Output_Warning, "Warning: ExternalInterface.call - handler is not installed.\n");
            result.SetUndefined();
        }
    }

    // marshallExceptions has no meaning here: always false, with a warning.
    // @0x142473990
    void ExternalInterface::marshallExceptionsGet(bool& result)
    {
        result = false;
        if (LogState* log = static_cast<ASVM&>(GetVM()).GetMovieImpl()->GetStateBag()->GetLogState())
            log->LogWarning("ExternalInterface::marshallExceptions is not supported.");
    }

    // @0x1424739f0
    void ExternalInterface::marshallExceptionsSet(const Value& result, bool value)
    {
        SF_UNUSED2(result, value);
        if (LogState* log = static_cast<ASVM&>(GetVM()).GetMovieImpl()->GetStateBag()->GetLogState())
            log->LogWarning("ExternalInterface::marshallExceptions is not supported.");
    }

    // There is no embedding object: null, with a warning.
    // @0x142473a50
    void ExternalInterface::objectIDGet(ASString& result)
    {
        result = GetVM().GetStringManager().GetBuiltin(AS3Builtin_null);
        if (LogState* log = static_cast<ASVM&>(GetVM()).GetMovieImpl()->GetStateBag()->GetLogState())
            log->LogWarning("ExternalInterface::objectID is not supported.");
    }
}}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {

// Native class descriptors (data of the exe, with the thunk and member tables).
namespace fl_filters
{
    extern const ClassInfo BevelFilterCI;
    extern const ClassInfo BitmapFilterCI;
    extern const ClassInfo BitmapFilterQualityCI;
    extern const ClassInfo BitmapFilterTypeCI;
    extern const ClassInfo BlurFilterCI;
    extern const ClassInfo ColorMatrixFilterCI;
    extern const ClassInfo ConvolutionFilterCI;
    extern const ClassInfo DisplacementMapFilterCI;
    extern const ClassInfo DisplacementMapFilterModeCI;
    extern const ClassInfo DropShadowFilterCI;
    extern const ClassInfo GlowFilterCI;
    extern const ClassInfo GradientBevelFilterCI;
    extern const ClassInfo GradientGlowFilterCI;
}

// ==== flash.filters: class traits factories ==========================================================================

namespace ClassTraits { namespace fl_filters
{
    // @0x142474740
    Pickable<Traits> DisplacementMapFilterMode::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) DisplacementMapFilterMode(vm));
    }

    // @0x142474960
    Pickable<Traits> BitmapFilterQuality::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) BitmapFilterQuality(vm));
    }

    // @0x142474ab0
    Pickable<Traits> BitmapFilterType::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) BitmapFilterType(vm));
    }

    // @0x142474c10
    Pickable<Traits> DropShadowFilter::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) DropShadowFilter(vm));
    }

    // @0x142474f50
    Pickable<Traits> BlurFilter::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) BlurFilter(vm));
    }

    // @0x142475ca0
    Pickable<Traits> ColorMatrixFilter::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ColorMatrixFilter(vm));
    }

    // @0x142475de0
    Pickable<Traits> GlowFilter::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) GlowFilter(vm));
    }

    // @0x1424766f0
    Pickable<Traits> GradientBevelFilter::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) GradientBevelFilter(vm));
    }

    // @0x142476830
    Pickable<Traits> GradientGlowFilter::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) GradientGlowFilter(vm));
    }

    // @0x142476b10
    Pickable<Traits> ConvolutionFilter::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ConvolutionFilter(vm));
    }

    // @0x142476c50
    Pickable<Traits> DisplacementMapFilter::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) DisplacementMapFilter(vm));
    }

    // @0x142476d90
    Pickable<Traits> BitmapFilter::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) BitmapFilter(vm));
    }

    // @0x142476ed0
    Pickable<Traits> BevelFilter::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) BevelFilter(vm));
    }

// ---- constructors ---------------------------------------------------------------------------------------------------

    // @0x142477010
    BevelFilter::BevelFilter(VM& vm)
        : Traits(vm, AS3::fl_filters::BevelFilterCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_filters::BevelFilter(vm, AS3::fl_filters::BevelFilterCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_filters
{
    // @0x142477110
    BevelFilter::BevelFilter(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_filters
{
    // @0x142477140
    BevelFilter::BevelFilter(InstanceTraits::Traits& t)
        : Instances::fl_filters::BitmapFilter(t)
    {
        FilterData = *new Render::BevelFilter();
    }
}}

namespace ClassTraits { namespace fl_filters
{
    // @0x1424772a0
    BitmapFilter::BitmapFilter(VM& vm)
        : Traits(vm, AS3::fl_filters::BitmapFilterCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_filters::BitmapFilter(vm, AS3::fl_filters::BitmapFilterCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_filters
{
    // @0x1424773a0
    BitmapFilter::BitmapFilter(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_filters
{
    // @0x1424773d0
    BitmapFilter::BitmapFilter(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
    {
    }
}}

namespace ClassTraits { namespace fl_filters
{
    // Constant holders: plain Object instance traits, the class object carries the constants.
    // @0x142477400
    BitmapFilterQuality::BitmapFilterQuality(VM& vm)
        : Traits(vm, AS3::fl_filters::BitmapFilterQualityCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_filters::BitmapFilterQualityCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_filters::BitmapFilterQuality(*this)));
    }
}}

namespace Classes { namespace fl_filters
{
    // @0x142477500
    BitmapFilterQuality::BitmapFilterQuality(ClassTraits::Traits& t)
        : Class(t), HIGH(3), LOW(1), MEDIUM(2)
    {
    }
}}

namespace ClassTraits { namespace fl_filters
{
    // @0x142477540
    BitmapFilterType::BitmapFilterType(VM& vm)
        : Traits(vm, AS3::fl_filters::BitmapFilterTypeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_filters::BitmapFilterTypeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_filters::BitmapFilterType(*this)));
    }
}}

namespace Classes { namespace fl_filters
{
    // @0x142477640
    BitmapFilterType::BitmapFilterType(ClassTraits::Traits& t)
        : Class(t), FULL("full"), INNER("inner"), OUTER("outer")
    {
    }
}}

namespace ClassTraits { namespace fl_filters
{
    // @0x142477690
    BlurFilter::BlurFilter(VM& vm)
        : Traits(vm, AS3::fl_filters::BlurFilterCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_filters::BlurFilter(vm, AS3::fl_filters::BlurFilterCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_filters
{
    // @0x142477790
    BlurFilter::BlurFilter(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_filters
{
    // @0x1424777c0
    BlurFilter::BlurFilter(InstanceTraits::Traits& t)
        : Instances::fl_filters::BitmapFilter(t)
    {
        FilterData = *new Render::BlurFilter();
    }
}}

namespace ClassTraits { namespace fl_filters
{
    // @0x1424778c0
    ColorMatrixFilter::ColorMatrixFilter(VM& vm)
        : Traits(vm, AS3::fl_filters::ColorMatrixFilterCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_filters::ColorMatrixFilter(vm, AS3::fl_filters::ColorMatrixFilterCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_filters
{
    // @0x1424779c0
    ColorMatrixFilter::ColorMatrixFilter(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_filters
{
    // @0x1424779f0
    ColorMatrixFilter::ColorMatrixFilter(InstanceTraits::Traits& t)
        : Instances::fl_filters::BitmapFilter(t)
    {
        FilterData = *new Render::ColorMatrixFilter();
    }
}}

namespace ClassTraits { namespace fl_filters
{
    // The filters the player does not implement: BitmapFilter instance traits, plain class object.
    // @0x142477a60
    ConvolutionFilter::ConvolutionFilter(VM& vm)
        : Traits(vm, AS3::fl_filters::ConvolutionFilterCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_filters::BitmapFilter(vm, AS3::fl_filters::ConvolutionFilterCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142477b60
    DisplacementMapFilter::DisplacementMapFilter(VM& vm)
        : Traits(vm, AS3::fl_filters::DisplacementMapFilterCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_filters::BitmapFilter(vm, AS3::fl_filters::DisplacementMapFilterCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142477c60
    DisplacementMapFilterMode::DisplacementMapFilterMode(VM& vm)
        : Traits(vm, AS3::fl_filters::DisplacementMapFilterModeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_filters::DisplacementMapFilterModeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_filters::DisplacementMapFilterMode(*this)));
    }
}}

namespace Classes { namespace fl_filters
{
    // @0x142477d70
    DisplacementMapFilterMode::DisplacementMapFilterMode(ClassTraits::Traits& t)
        : Class(t), CLAMP("clamp"), COLOR("color"), IGNORE_("ignore"), WRAP("wrap")
    {
    }
}}

namespace ClassTraits { namespace fl_filters
{
    // @0x142477dc0
    DropShadowFilter::DropShadowFilter(VM& vm)
        : Traits(vm, AS3::fl_filters::DropShadowFilterCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_filters::DropShadowFilter(vm, AS3::fl_filters::DropShadowFilterCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_filters
{
    // @0x142477ec0
    DropShadowFilter::DropShadowFilter(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_filters
{
    // @0x142477ef0
    DropShadowFilter::DropShadowFilter(InstanceTraits::Traits& t)
        : Instances::fl_filters::BitmapFilter(t)
    {
        FilterData = *new Render::ShadowFilter();
    }
}}

namespace ClassTraits { namespace fl_filters
{
    // @0x142478040
    GlowFilter::GlowFilter(VM& vm)
        : Traits(vm, AS3::fl_filters::GlowFilterCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_filters::GlowFilter(vm, AS3::fl_filters::GlowFilterCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_filters
{
    // @0x142478140
    GlowFilter::GlowFilter(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_filters
{
    // @0x142478170
    GlowFilter::GlowFilter(InstanceTraits::Traits& t)
        : Instances::fl_filters::BitmapFilter(t)
    {
        FilterData = *new Render::GlowFilter();
    }
}}

namespace ClassTraits { namespace fl_filters
{
    // @0x142478280
    GradientBevelFilter::GradientBevelFilter(VM& vm)
        : Traits(vm, AS3::fl_filters::GradientBevelFilterCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_filters::BitmapFilter(vm, AS3::fl_filters::GradientBevelFilterCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142478380
    GradientGlowFilter::GradientGlowFilter(VM& vm)
        : Traits(vm, AS3::fl_filters::GradientGlowFilterCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_filters::BitmapFilter(vm, AS3::fl_filters::GradientGlowFilterCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

// ==== flash.filters: instances =======================================================================================

namespace Instances { namespace fl_filters
{
    // Arguments past the given count keep the defaults; a failed conversion (exception) stops the constructor.
    // @0x142479470
    void BevelFilter::AS3Constructor(unsigned argc, const Value* argv)
    {
        Value::Number distance(4), angle(45);
        UInt32 highlightColor(0xFFFFFF);
        Value::Number highlightAlpha(1);
        UInt32 shadowColor(0);
        Value::Number shadowAlpha(1), blurX(4), blurY(4), strength(1);
        SInt32 quality(1);
        ASString type = GetVM().GetStringManager().CreateConstString("inner");
        bool knockout(false);

        if (argc >= 1 && !argv[0].Convert2Number(distance)) return;
        if (argc >= 2 && !argv[1].Convert2Number(angle)) return;
        if (argc >= 3 && !argv[2].Convert2UInt32(highlightColor)) return;
        if (argc >= 4 && !argv[3].Convert2Number(highlightAlpha)) return;
        if (argc >= 5 && !argv[4].Convert2UInt32(shadowColor)) return;
        if (argc >= 6 && !argv[5].Convert2Number(shadowAlpha)) return;
        if (argc >= 7 && !argv[6].Convert2Number(blurX)) return;
        if (argc >= 8 && !argv[7].Convert2Number(blurY)) return;
        if (argc >= 9 && !argv[8].Convert2Number(strength)) return;
        if (argc >= 10 && !argv[9].Convert2Int32(quality)) return;
        if (argc >= 11 && !argv[10].Convert2String(type)) return;
        if (argc >= 12) knockout = argv[11].Convert2Boolean();

        Value result;
        distanceSet(result, distance);
        angleSet(result, angle);
        highlightColorSet(result, highlightColor);
        highlightAlphaSet(result, highlightAlpha);
        shadowColorSet(result, shadowColor);
        shadowAlphaSet(result, shadowAlpha);
        blurXSet(result, blurX);
        blurYSet(result, blurY);
        strengthSet(result, strength);
        qualitySet(result, quality);
        typeSet(result, type);
        knockoutSet(result, knockout);
    }

    // @0x1424798f0
    void BlurFilter::AS3Constructor(unsigned argc, const Value* argv)
    {
        Value result;
        Value::Number blurX(4), blurY(4);
        SInt32 quality(1);

        if (argc >= 1 && !argv[0].Convert2Number(blurX)) return;
        if (argc >= 2 && !argv[1].Convert2Number(blurY)) return;
        if (argc >= 3 && !argv[2].Convert2Int32(quality)) return;

        blurXSet(result, blurX);
        blurYSet(result, blurY);
        qualitySet(result, (SInt16)quality);
    }

    // @0x142479a10
    void ColorMatrixFilter::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc > 0 && argv[0].IsObject() && argv[0].GetObject())
        {
            Traits& tr = argv[0].GetObject()->GetTraits();
            if (tr.GetTraitsType() == Traits_Array && tr.IsInstanceTraits())
            {
                Value result;
                matrixSet(result, static_cast<Instances::fl::Array*>(argv[0].GetObject()));
            }
        }
    }

    // Arguments 6 and 7 are read twice: as strength/quality and as inner/knockout (hideObject is never read).
    // @0x142479a90
    void DropShadowFilter::AS3Constructor(unsigned argc, const Value* argv)
    {
        Value::Number distance(4), angle(45);
        UInt32 color(0);
        Value::Number alpha(1), blurX(4), blurY(4), strength(1);
        SInt32 quality(1);
        bool inner(false), knockout(false);

        if (argc >= 1 && !argv[0].Convert2Number(distance)) return;
        if (argc >= 2 && !argv[1].Convert2Number(angle)) return;
        if (argc >= 3 && !argv[2].Convert2UInt32(color)) return;
        if (argc >= 4 && !argv[3].Convert2Number(alpha)) return;
        if (argc >= 5 && !argv[4].Convert2Number(blurX)) return;
        if (argc >= 6 && !argv[5].Convert2Number(blurY)) return;
        if (argc >= 7 && !argv[6].Convert2Number(strength)) return;
        if (argc >= 8 && !argv[7].Convert2Int32(quality)) return;
        if (argc >= 7) inner = argv[6].Convert2Boolean();
        if (argc >= 8) knockout = argv[7].Convert2Boolean();

        Value result;
        distanceSet(result, distance);
        angleSet(result, angle);
        colorSet(result, color);
        alphaSet(result, alpha);
        blurXSet(result, blurX);
        blurYSet(result, blurY);
        strengthSet(result, strength);
        qualitySet(result, quality);
        innerSet(result, inner);
        knockoutSet(result, knockout);
    }

    // @0x142479df0
    void GlowFilter::AS3Constructor(unsigned argc, const Value* argv)
    {
        UInt32 color(0xFF0000);
        Value::Number alpha(1), blurX(6), blurY(6), strength(2);
        SInt32 quality(1);
        bool inner(false), knockout(false);

        if (argc >= 1 && !argv[0].Convert2UInt32(color)) return;
        if (argc >= 2 && !argv[1].Convert2Number(alpha)) return;
        if (argc >= 3 && !argv[2].Convert2Number(blurX)) return;
        if (argc >= 4 && !argv[3].Convert2Number(blurY)) return;
        if (argc >= 5 && !argv[4].Convert2Number(strength)) return;
        if (argc >= 6 && !argv[5].Convert2Int32(quality)) return;
        if (argc >= 7) inner = argv[6].Convert2Boolean();
        if (argc >= 8) knockout = argv[7].Convert2Boolean();

        Value result;
        colorSet(result, color);
        alphaSet(result, alpha);
        blurXSet(result, blurX);
        blurYSet(result, blurY);
        strengthSet(result, strength);
        qualitySet(result, quality);
        innerSet(result, inner);
        knockoutSet(result, knockout);
    }
}}

// ---- instance factories ---------------------------------------------------------------------------------------------

namespace InstanceTraits { namespace fl_filters
{
    // @0x14247a220
    Pickable<BevelFilter::InstanceType> BevelFilter::MakeInstance(BevelFilter& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x14247a3b0
    Pickable<BitmapFilter::InstanceType> BitmapFilter::MakeInstance(BitmapFilter& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x14247a430
    Pickable<BlurFilter::InstanceType> BlurFilter::MakeInstance(BlurFilter& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x14247a550
    Pickable<ColorMatrixFilter::InstanceType> ColorMatrixFilter::MakeInstance(ColorMatrixFilter& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x14247a600
    Pickable<DropShadowFilter::InstanceType> DropShadowFilter::MakeInstance(DropShadowFilter& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x14247a780
    Pickable<GlowFilter::InstanceType> GlowFilter::MakeInstance(GlowFilter& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x14247a8c0
    void BevelFilter::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<BevelFilter&>(t)));
    }

    // @0x14247a8f0
    void BitmapFilter::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<BitmapFilter&>(t)));
    }

    // @0x14247a950
    void BlurFilter::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<BlurFilter&>(t)));
    }

    // @0x14247a980
    void ColorMatrixFilter::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<ColorMatrixFilter&>(t)));
    }

    // @0x14247aa20
    void DropShadowFilter::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<DropShadowFilter&>(t)));
    }

    // @0x14247aa50
    void GlowFilter::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<GlowFilter&>(t)));
    }
}}

// ---- native methods -------------------------------------------------------------------------------------------------

namespace Instances { namespace fl_filters
{
    // @0x14247aa80
    void DropShadowFilter::alphaGet(Value::Number& result)
    {
        result = GetShadowFilterData()->GetParams().Colors[0].GetAlpha() / 255.0;
    }

    // @0x14247aaa0
    void GlowFilter::alphaGet(Value::Number& result)
    {
        result = GetGlowFilterData()->GetParams().Colors[0].GetAlpha() / 255.0;
    }

    // @0x14247aac0
    void DropShadowFilter::alphaSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().Colors[0].SetAlpha((UByte)(value * 255));
    }

    // @0x14247aae0
    void GlowFilter::alphaSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetGlowFilterData()->GetParams().Colors[0].SetAlpha((UByte)(value * 255));
    }

    // @0x14247ab00
    void BevelFilter::angleGet(Value::Number& result)
    {
        result = SF_RADTODEG(GetBevelFilterData()->GetAngle());
    }

    // @0x14247ab40
    void DropShadowFilter::angleGet(Value::Number& result)
    {
        result = SF_RADTODEG(GetShadowFilterData()->GetAngle());
    }

    // @0x14247ab70
    void BevelFilter::angleSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetBevelFilterData()->SetAngleDistance((float)SF_DEGTORAD((float)value), GetBevelFilterData()->GetDistance());
    }

    // @0x14247ac10
    void DropShadowFilter::angleSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetShadowFilterData()->SetAngleDistance((float)SF_DEGTORAD((float)value), GetShadowFilterData()->GetDistance());
    }

    // @0x14247aca0
    void BevelFilter::blurXGet(Value::Number& result)
    {
        result = TwipsToPixels(GetBevelFilterData()->GetParams().BlurX);
    }

    // @0x14247acd0
    void BlurFilter::blurXGet(Value::Number& result)
    {
        result = TwipsToPixels(GetBlurFilterData()->GetParams().BlurX);
    }

    // @0x14247acf0
    void DropShadowFilter::blurXGet(Value::Number& result)
    {
        result = TwipsToPixels(GetShadowFilterData()->GetParams().BlurX);
    }

    // @0x14247ad10
    void GlowFilter::blurXGet(Value::Number& result)
    {
        result = TwipsToPixels(GetGlowFilterData()->GetParams().BlurX);
    }

    // @0x14247ad30
    void BevelFilter::blurXSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetBevelFilterData()->GetParams().BlurX = PixelsToTwips((float)value);
    }

    // @0x14247ad60
    void BlurFilter::blurXSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetBlurFilterData()->GetParams().BlurX = PixelsToTwips((float)value);
    }

    // @0x14247ad80
    void DropShadowFilter::blurXSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().BlurX = PixelsToTwips((float)value);
    }

    // @0x14247ada0
    void GlowFilter::blurXSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetGlowFilterData()->GetParams().BlurX = PixelsToTwips((float)value);
    }

    // @0x14247adc0
    void BevelFilter::blurYGet(Value::Number& result)
    {
        result = TwipsToPixels(GetBevelFilterData()->GetParams().BlurY);
    }

    // @0x14247adf0
    void BlurFilter::blurYGet(Value::Number& result)
    {
        result = TwipsToPixels(GetBlurFilterData()->GetParams().BlurY);
    }

    // @0x14247ae10
    void DropShadowFilter::blurYGet(Value::Number& result)
    {
        result = TwipsToPixels(GetShadowFilterData()->GetParams().BlurY);
    }

    // @0x14247ae30
    void GlowFilter::blurYGet(Value::Number& result)
    {
        result = TwipsToPixels(GetGlowFilterData()->GetParams().BlurY);
    }

    // @0x14247ae50
    void BevelFilter::blurYSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetBevelFilterData()->GetParams().BlurY = PixelsToTwips((float)value);
    }

    // @0x14247ae80
    void BlurFilter::blurYSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetBlurFilterData()->GetParams().BlurY = PixelsToTwips((float)value);
    }

    // @0x14247aea0
    void DropShadowFilter::blurYSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().BlurY = PixelsToTwips((float)value);
    }

    // @0x14247aec0
    void GlowFilter::blurYSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetGlowFilterData()->GetParams().BlurY = PixelsToTwips((float)value);
    }

    // @0x14247aee0
    SPtr<Instances::fl_filters::BitmapFilter> BevelFilter::clone()
    {
        SPtr<Instances::fl_filters::BitmapFilter> result;
        clone(result);
        return result;
    }

    // Copies through the accessors: a new instance gets every property of this one.
    // MS2-FUNCTIONAL: the exe keeps the inlined flag getters as shr/and/shl (not folded to a mask); register allocation differs
    // @0x14247af00
    void BevelFilter::clone(SPtr<Instances::fl_filters::BitmapFilter>& result)
    {
        InstanceTraits::fl_filters::BevelFilter& itr = static_cast<InstanceTraits::fl_filters::BevelFilter&>(GetTraits());
        Pickable<BevelFilter> r = itr.MakeInstance(itr);

        Value::Number distance, angle, highlightAlpha, shadowAlpha, blurX, blurY, strength;
        UInt32 highlightColor, shadowColor;
        SInt32 quality;
        ASString type = GetVM().GetStringManager().CreateEmptyString();
        bool knockout;
        distanceGet(distance);
        angleGet(angle);
        highlightColorGet(highlightColor);
        highlightAlphaGet(highlightAlpha);
        shadowColorGet(shadowColor);
        shadowAlphaGet(shadowAlpha);
        blurXGet(blurX);
        blurYGet(blurY);
        strengthGet(strength);
        qualityGet(quality);
        typeGet(type);
        knockoutGet(knockout);

        Value tempResult;
        r->distanceSet(tempResult, distance);
        r->angleSet(tempResult, angle);
        r->highlightColorSet(tempResult, highlightColor);
        r->highlightAlphaSet(tempResult, highlightAlpha);
        r->shadowColorSet(tempResult, shadowColor);
        r->shadowAlphaSet(tempResult, shadowAlpha);
        r->blurXSet(tempResult, blurX);
        r->blurYSet(tempResult, blurY);
        r->strengthSet(tempResult, strength);
        r->qualitySet(tempResult, quality);
        r->typeSet(tempResult, type);
        r->knockoutSet(tempResult, knockout);
        result = r;
    }

    // @0x14247b400
    void BitmapFilter::clone(SPtr<Instances::fl_filters::BitmapFilter>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method instance::BitmapFilter::clone() is not implemented\n");
    }

    // @0x14247b420
    SPtr<Instances::fl_filters::BitmapFilter> BlurFilter::clone()
    {
        SPtr<Instances::fl_filters::BitmapFilter> result;
        clone(result);
        return result;
    }

    // @0x14247b440
    __declspec(noinline) void BlurFilter::clone(SPtr<Instances::fl_filters::BitmapFilter>& result)
    {
        InstanceTraits::fl_filters::BlurFilter& itr = static_cast<InstanceTraits::fl_filters::BlurFilter&>(GetTraits());
        Pickable<BlurFilter> r = itr.MakeInstance(itr);

        Value::Number blurX, blurY;
        SInt32 quality;
        blurXGet(blurX);
        blurYGet(blurY);
        qualityGet(quality);

        Value tempResult;
        r->blurXSet(tempResult, blurX);
        r->blurYSet(tempResult, blurY);
        r->qualitySet(tempResult, quality);
        result = r;
    }

    // @0x14247b530
    SPtr<Instances::fl_filters::BitmapFilter> ColorMatrixFilter::clone()
    {
        SPtr<Instances::fl_filters::BitmapFilter> result;
        clone(result);
        return result;
    }

    // Through the AS3 array form of the matrix.
    // @0x14247b550
    __declspec(noinline) void ColorMatrixFilter::clone(SPtr<Instances::fl_filters::BitmapFilter>& result)
    {
        InstanceTraits::fl_filters::ColorMatrixFilter& itr = static_cast<InstanceTraits::fl_filters::ColorMatrixFilter&>(GetTraits());
        Pickable<ColorMatrixFilter> r = itr.MakeInstance(itr);

        SPtr<Instances::fl::Array> matrix;
        Value tempResult;
        matrixGet(matrix);
        r->matrixSet(tempResult, matrix.GetPtr());
        result = r;
    }

    // @0x14247b6a0
    SPtr<Instances::fl_filters::BitmapFilter> DropShadowFilter::clone()
    {
        SPtr<Instances::fl_filters::BitmapFilter> result;
        clone(result);
        return result;
    }

    // MS2-FUNCTIONAL: the exe keeps the inlined flag getters as shr/and/shl (not folded to a mask); register allocation differs
    // @0x14247b6c0
    void DropShadowFilter::clone(SPtr<Instances::fl_filters::BitmapFilter>& result)
    {
        InstanceTraits::fl_filters::DropShadowFilter& itr = static_cast<InstanceTraits::fl_filters::DropShadowFilter&>(GetTraits());
        Pickable<DropShadowFilter> r = itr.MakeInstance(itr);

        Value::Number distance, angle;
        UInt32 color;
        Value::Number alpha, blurX, blurY, strength;
        SInt32 quality;
        bool inner, knockout, hideObject;
        distanceGet(distance);
        angleGet(angle);
        colorGet(color);
        alphaGet(alpha);
        blurXGet(blurX);
        blurYGet(blurY);
        strengthGet(strength);
        qualityGet(quality);
        innerGet(inner);
        knockoutGet(knockout);
        hideObjectGet(hideObject);

        Value tempResult;
        r->distanceSet(tempResult, distance);
        r->angleSet(tempResult, angle);
        r->colorSet(tempResult, color);
        r->alphaSet(tempResult, alpha);
        r->blurXSet(tempResult, blurX);
        r->blurYSet(tempResult, blurY);
        r->strengthSet(tempResult, strength);
        r->qualitySet(tempResult, quality);
        r->innerSet(tempResult, inner);
        r->knockoutSet(tempResult, knockout);
        r->hideObjectSet(tempResult, hideObject);
        result = r;
    }

    // @0x14247b960
    SPtr<Instances::fl_filters::BitmapFilter> GlowFilter::clone()
    {
        SPtr<Instances::fl_filters::BitmapFilter> result;
        clone(result);
        return result;
    }

    // MS2-FUNCTIONAL: the exe keeps the inlined flag getters as shr/and/shl (not folded to a mask); register allocation differs
    // @0x14247b980
    void GlowFilter::clone(SPtr<Instances::fl_filters::BitmapFilter>& result)
    {
        InstanceTraits::fl_filters::GlowFilter& itr = static_cast<InstanceTraits::fl_filters::GlowFilter&>(GetTraits());
        Pickable<GlowFilter> r = itr.MakeInstance(itr);

        UInt32 color;
        Value::Number alpha, blurX, blurY, strength;
        SInt32 quality;
        bool inner, knockout;
        colorGet(color);
        alphaGet(alpha);
        blurXGet(blurX);
        blurYGet(blurY);
        strengthGet(strength);
        qualityGet(quality);
        innerGet(inner);
        knockoutGet(knockout);

        Value tempResult;
        r->colorSet(tempResult, color);
        r->alphaSet(tempResult, alpha);
        r->blurXSet(tempResult, blurX);
        r->blurYSet(tempResult, blurY);
        r->strengthSet(tempResult, strength);
        r->qualitySet(tempResult, quality);
        r->innerSet(tempResult, inner);
        r->knockoutSet(tempResult, knockout);
        result = r;
    }

    // @0x14247baf0
    void DropShadowFilter::colorGet(UInt32& result)
    {
        result = GetShadowFilterData()->GetParams().Colors[0].GetColorRGB().Raw;
    }

    // @0x14247bb00
    void GlowFilter::colorGet(UInt32& result)
    {
        result = GetGlowFilterData()->GetParams().Colors[0].GetColorRGB().Raw;
    }

    // @0x14247bb10
    void DropShadowFilter::colorSet(const Value& result, UInt32 value)
    {
        SF_UNUSED(result);
        Render::Color& c = GetShadowFilterData()->GetParams().Colors[0];
        c.SetColor(value, c.GetAlpha());
    }

    // @0x14247bb20
    void GlowFilter::colorSet(const Value& result, UInt32 value)
    {
        SF_UNUSED(result);
        Render::Color& c = GetGlowFilterData()->GetParams().Colors[0];
        c.SetColor(value, c.GetAlpha());
    }

    // @0x14247bb30
    void BevelFilter::distanceGet(Value::Number& result)
    {
        result = TwipsToPixels(GetBevelFilterData()->GetDistance());
    }

    // @0x14247bb60
    void DropShadowFilter::distanceGet(Value::Number& result)
    {
        result = TwipsToPixels(GetShadowFilterData()->GetDistance());
    }

    // @0x14247bb80
    void BevelFilter::distanceSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetBevelFilterData()->SetAngleDistance(GetBevelFilterData()->GetAngle(), PixelsToTwips((float)value));
    }

    // @0x14247bc20
    void DropShadowFilter::distanceSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetShadowFilterData()->SetAngleDistance(GetShadowFilterData()->GetAngle(), PixelsToTwips((float)value));
    }

    // @0x14247bca0
    void DropShadowFilter::hideObjectGet(bool& result)
    {
        result = (GetShadowFilterData()->GetParams().Mode >> 6) & 1;
    }

    // The flag setters only ever set the bit.
    // @0x14247bcb0
    void DropShadowFilter::hideObjectSet(const Value& result, bool value)
    {
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().Mode |= ((unsigned)value << 6);
    }

    // @0x14247bcc0
    void BevelFilter::highlightAlphaGet(Value::Number& result)
    {
        result = GetBevelFilterData()->GetParams().Colors[1].GetAlpha() / 255.0;
    }

    // @0x14247bcf0
    void BevelFilter::highlightAlphaSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetBevelFilterData()->GetParams().Colors[1].SetAlpha((UByte)(value * 255));
    }

    // @0x14247bd20
    void BevelFilter::highlightColorGet(UInt32& result)
    {
        result = GetBevelFilterData()->GetParams().Colors[1].GetColorRGB().Raw;
    }

    // @0x14247bd50
    void BevelFilter::highlightColorSet(const Value& result, UInt32 value)
    {
        SF_UNUSED(result);
        Render::Color& c = GetBevelFilterData()->GetParams().Colors[1];
        c.SetColor(value, c.GetAlpha());
    }

    // @0x14247bd80
    void DropShadowFilter::innerGet(bool& result)
    {
        result = (GetShadowFilterData()->GetParams().Mode >> 5) & 1;
    }

    // @0x14247bd90
    void GlowFilter::innerGet(bool& result)
    {
        result = (GetGlowFilterData()->GetParams().Mode >> 5) & 1;
    }

    // @0x14247bda0
    void DropShadowFilter::innerSet(const Value& result, bool value)
    {
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().Mode |= ((unsigned)value << 5);
    }

    // @0x14247bdb0
    void GlowFilter::innerSet(const Value& result, bool value)
    {
        SF_UNUSED(result);
        GetGlowFilterData()->GetParams().Mode |= ((unsigned)value << 5);
    }

    // @0x14247bdc0
    void BevelFilter::knockoutGet(bool& result)
    {
        result = (GetBevelFilterData()->GetParams().Mode >> 4) & 1;
    }

    // @0x14247bdf0
    void DropShadowFilter::knockoutGet(bool& result)
    {
        result = (GetShadowFilterData()->GetParams().Mode >> 4) & 1;
    }

    // @0x14247be00
    void GlowFilter::knockoutGet(bool& result)
    {
        result = (GetGlowFilterData()->GetParams().Mode >> 4) & 1;
    }

    // @0x14247be10
    void BevelFilter::knockoutSet(const Value& result, bool value)
    {
        SF_UNUSED(result);
        GetBevelFilterData()->GetParams().Mode |= ((unsigned)value << 4);
    }

    // @0x14247be40
    void DropShadowFilter::knockoutSet(const Value& result, bool value)
    {
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().Mode |= ((unsigned)value << 4);
    }

    // @0x14247be50
    void GlowFilter::knockoutSet(const Value& result, bool value)
    {
        SF_UNUSED(result);
        GetGlowFilterData()->GetParams().Mode |= ((unsigned)value << 4);
    }

    // @0x14247be60
    SPtr<Instances::fl::Array> ColorMatrixFilter::matrixGet()
    {
        SPtr<Instances::fl::Array> result;
        matrixGet(result);
        return result;
    }

    // AS3 order: four rows of five (four factors and the offset); the render filter keeps the 4x4 factors first and the
    // four offsets after them.
    // @0x14247be80
    void ColorMatrixFilter::matrixGet(SPtr<Instances::fl::Array>& result)
    {
        SPtr<Instances::fl::Array> asArray = GetVM().MakeArray();
        asArray->Resize(20);
        const Render::ColorMatrixFilter* filterData = GetColorMatrixFilterData();
        for (unsigned i = 0; i < 20; i++)
        {
            Value v;
            if (i % 5 == 0 && i != 0)
                v.SetNumber((Value::Number)(*filterData)[16 + i / 5]);
            else
                v.SetNumber((Value::Number)(*filterData)[i / 5 * 4 + i % 5]);
            asArray->Set(i, v);
        }
        result = asArray;
    }

    // @0x14247c020
    void ColorMatrixFilter::matrixSet(const Value& result, Instances::fl::Array* value)
    {
        if (value == 0)
            return;
        SF_UNUSED(result);
        Render::ColorMatrixFilter* filterData = GetColorMatrixFilterData();
        for (unsigned i = 0; i < value->GetSize(); ++i)
        {
            Value::Number n;
            if (!value->At(i).Convert2Number(n))
                return;
            if (i >= 20)
                continue;
            if (i % 5 == 4)
                (*filterData)[16 + i / 5] = (float)n / 255.0f;
            else
                (*filterData)[i / 5 * 4 + i % 5] = (float)n;
        }
    }

    // @0x14247c0e0
    void BevelFilter::qualityGet(SInt32& result)
    {
        result = GetBevelFilterData()->GetParams().Passes;
    }

    // @0x14247c100
    void BlurFilter::qualityGet(SInt32& result)
    {
        result = GetBlurFilterData()->GetParams().Passes;
    }

    // @0x14247c110
    void DropShadowFilter::qualityGet(SInt32& result)
    {
        result = GetShadowFilterData()->GetParams().Passes;
    }

    // @0x14247c120
    void GlowFilter::qualityGet(SInt32& result)
    {
        result = GetGlowFilterData()->GetParams().Passes;
    }

    // @0x14247c130
    void BevelFilter::qualitySet(const Value& result, SInt32 value)
    {
        SF_UNUSED(result);
        GetBevelFilterData()->GetParams().Passes = value;
    }

    // @0x14247c150
    void BlurFilter::qualitySet(const Value& result, SInt32 value)
    {
        SF_UNUSED(result);
        GetBlurFilterData()->GetParams().Passes = value;
    }

    // @0x14247c160
    void DropShadowFilter::qualitySet(const Value& result, SInt32 value)
    {
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().Passes = value;
    }

    // @0x14247c170
    void GlowFilter::qualitySet(const Value& result, SInt32 value)
    {
        SF_UNUSED(result);
        GetGlowFilterData()->GetParams().Passes = value;
    }

    // @0x14247c180
    void BevelFilter::shadowAlphaGet(Value::Number& result)
    {
        result = GetBevelFilterData()->GetParams().Colors[0].GetAlpha() / 255.0;
    }

    // @0x14247c1b0
    void BevelFilter::shadowAlphaSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetBevelFilterData()->GetParams().Colors[0].SetAlpha((UByte)(value * 255));
    }

    // @0x14247c1e0
    void BevelFilter::shadowColorGet(UInt32& result)
    {
        result = GetBevelFilterData()->GetParams().Colors[0].GetColorRGB().Raw;
    }

    // @0x14247c210
    void BevelFilter::shadowColorSet(const Value& result, UInt32 value)
    {
        SF_UNUSED(result);
        Render::Color& c = GetBevelFilterData()->GetParams().Colors[0];
        c.SetColor(value, c.GetAlpha());
    }

    // @0x14247c240
    void BevelFilter::strengthGet(Value::Number& result)
    {
        result = GetBevelFilterData()->GetParams().Strength;
    }

    // @0x14247c270
    void DropShadowFilter::strengthGet(Value::Number& result)
    {
        result = GetShadowFilterData()->GetParams().Strength;
    }

    // @0x14247c290
    void GlowFilter::strengthGet(Value::Number& result)
    {
        result = GetGlowFilterData()->GetParams().Strength;
    }

    // @0x14247c2b0
    void BevelFilter::strengthSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetBevelFilterData()->GetParams().Strength = (float)value;
    }

    // @0x14247c2e0
    void DropShadowFilter::strengthSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetShadowFilterData()->GetParams().Strength = (float)value;
    }

    // @0x14247c300
    void GlowFilter::strengthSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        GetGlowFilterData()->GetParams().Strength = (float)value;
    }

    // @0x14247c320
    void BevelFilter::typeGet(ASString& result)
    {
        result = (GetBevelFilterData()->GetParams().Mode & Render::BlurFilterParams::Mode_Inner) == 0 ? "outer" : "inner";
    }

    // "full" (inner and outer) is not supported by the render filter: warning only.
    // @0x14247c360
    void BevelFilter::typeSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        if (value == "inner")
            GetBevelFilterData()->GetParams().Mode |= Render::BlurFilterParams::Mode_Inner;
        else if (value == "outer")
            GetBevelFilterData()->GetParams().Mode &= ~Render::BlurFilterParams::Mode_Inner;
        else if (value == "full")
            GetVM().GetUI().Output(FlashUI::Output_Warning, "The method instance::BevelFilter::typeSet() - full is not implemented\n");
    }
}}

}}} // namespace Scaleform::GFx::AS3

// ==== flash.geom: traits and constructors (the natives, AS3 constructors and MakeObject are in sfr_as3_11) ===========

namespace Scaleform { namespace GFx { namespace AS3 {

namespace fl_geom
{
    extern const ClassInfo ColorTransformCI;
    extern const ClassInfo Matrix3DCI;
    extern const ClassInfo MatrixCI;
    extern const ClassInfo PerspectiveProjectionCI;
    extern const ClassInfo PointCI;
    extern const ClassInfo RectangleCI;
    extern const ClassInfo TransformCI;
    extern const ClassInfo Vector3DCI;
}

namespace ClassTraits { namespace fl_geom
{
    // @0x14247cd00
    Pickable<Traits> PerspectiveProjection::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) PerspectiveProjection(vm));
    }

    // @0x14247ce40
    Pickable<Traits> Matrix3D::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Matrix3D(vm));
    }

    // @0x14247ddd0
    Pickable<Traits> Vector3D::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Vector3D(vm));
    }

    // @0x14247e4e0
    Pickable<Traits> Rectangle::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Rectangle(vm));
    }

    // @0x14247ff80
    Pickable<Traits> Transform::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Transform(vm));
    }

    // @0x142480a10
    Pickable<Traits> ColorTransform::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ColorTransform(vm));
    }

    // @0x142481b90
    Pickable<Traits> Matrix::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Matrix(vm));
    }

    // @0x142481cd0
    Pickable<Traits> Point::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Point(vm));
    }
}}

namespace ClassTraits { namespace fl_geom
{
    // @0x142481e50
    ColorTransform::ColorTransform(VM& vm)
        : Traits(vm, AS3::fl_geom::ColorTransformCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_geom::ColorTransform(vm, AS3::fl_geom::ColorTransformCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_geom
{
    // @0x142481f50
    ColorTransform::ColorTransform(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_geom
{
    // @0x142481f80
    ColorTransform::ColorTransform(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
    {
        alphaMultiplier = blueMultiplier = greenMultiplier = redMultiplier = 1.0;
        alphaOffset = blueOffset = greenOffset = redOffset = 0.0;
    }
}}

namespace ClassTraits { namespace fl_geom
{
    // @0x142481fd0
    Matrix3D::Matrix3D(VM& vm)
        : Traits(vm, AS3::fl_geom::Matrix3DCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_geom::Matrix3D(vm, AS3::fl_geom::Matrix3DCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_geom
{
    // @0x1424820d0
    Matrix3D::Matrix3D(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_geom
{
    // @0x142482100
    Matrix3D::Matrix3D(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , pDispObj(0)
    {
    }
}}

namespace ClassTraits { namespace fl_geom
{
    // @0x142482160
    Matrix::Matrix(VM& vm)
        : Traits(vm, AS3::fl_geom::MatrixCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_geom::Matrix(vm, AS3::fl_geom::MatrixCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_geom
{
    // @0x142482260
    Matrix::Matrix(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_geom
{
    // The AS3 constructor sets the identity; the native object starts zeroed.
    // @0x142482290
    Matrix::Matrix(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , a(0), b(0), c(0), d(0), tx(0), ty(0)
    {
    }
}}

namespace ClassTraits { namespace fl_geom
{
    // @0x1424822d0
    PerspectiveProjection::PerspectiveProjection(VM& vm)
        : Traits(vm, AS3::fl_geom::PerspectiveProjectionCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_geom::PerspectiveProjection(vm, AS3::fl_geom::PerspectiveProjectionCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_geom
{
    // @0x1424823d0
    PerspectiveProjection::PerspectiveProjection(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_geom
{
    // @0x142482400
    PerspectiveProjection::PerspectiveProjection(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , projectionCenter(Render::PointF::NoInit), fieldOfView(55), pDispObj(0)
    {
        // A 500x500 stage: the centre and the focal length of a 55 degree field of view.
        projectionCenter.x = 250.f;
        projectionCenter.y = 250.f;
        focalLength = 250.0 / tan(SF_DEGTORAD(fieldOfView) / 2);
    }
}}

namespace ClassTraits { namespace fl_geom
{
    // @0x142482470
    Point::Point(VM& vm)
        : Traits(vm, AS3::fl_geom::PointCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_geom::Point(vm, AS3::fl_geom::PointCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_geom::Point(*this)));
    }
}}

namespace Classes { namespace fl_geom
{
    // @0x142482570
    Point::Point(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl_geom
{
    // @0x1424825a0
    Point::Point(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_geom
{
    // @0x1424825d0
    Point::Point(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , x(0), y(0)
    {
    }
}}

namespace ClassTraits { namespace fl_geom
{
    // @0x142482600
    Rectangle::Rectangle(VM& vm)
        : Traits(vm, AS3::fl_geom::RectangleCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_geom::Rectangle(vm, AS3::fl_geom::RectangleCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_geom
{
    // @0x142482700
    Rectangle::Rectangle(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_geom
{
    // @0x142482730
    Rectangle::Rectangle(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , height(0), width(0), x(0), y(0)
    {
    }
}}

namespace ClassTraits { namespace fl_geom
{
    // @0x142482770
    Transform::Transform(VM& vm)
        : Traits(vm, AS3::fl_geom::TransformCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_geom::Transform(vm, AS3::fl_geom::TransformCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_geom
{
    // @0x142482870
    Transform::Transform(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_geom
{
    // @0x1424828a0
    Transform::Transform(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , pDispObj(0)
    {
    }
}}

namespace ClassTraits { namespace fl_geom
{
    // @0x1424828d0
    Vector3D::Vector3D(VM& vm)
        : Traits(vm, AS3::fl_geom::Vector3DCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_geom::Vector3D(vm, AS3::fl_geom::Vector3DCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_geom::Vector3D(*this)));
    }
}}

namespace Classes { namespace fl_geom
{
    // @0x1424829d0
    Vector3D::Vector3D(ClassTraits::Traits& t)
        : Class(t)
    {
        InstanceTraits::Traits& itr = GetInstanceTraits();
        X_AXIS = Pickable<Instances::fl_geom::Vector3D>(new(itr.Alloc()) Instances::fl_geom::Vector3D(itr));
        Y_AXIS = Pickable<Instances::fl_geom::Vector3D>(new(itr.Alloc()) Instances::fl_geom::Vector3D(itr));
        Z_AXIS = Pickable<Instances::fl_geom::Vector3D>(new(itr.Alloc()) Instances::fl_geom::Vector3D(itr));
        X_AXIS->x = 1;
        Y_AXIS->y = 1;
        Z_AXIS->z = 1;
    }
}}

namespace InstanceTraits { namespace fl_geom
{
    // @0x142482b80
    Vector3D::Vector3D(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_geom
{
    // @0x142482bb0
    Vector3D::Vector3D(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , x(0), y(0), z(0), w(0)
    {
    }
}}

}}} // namespace Scaleform::GFx::AS3

// MS2-PIN: ?Func@?$ThunkFunc0@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473af0
// MS2-PIN: ?Func@?$ThunkFunc1@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473b60
// MS2-PIN: ?Func@?$ThunkFunc0@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$01N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473bf0
// MS2-PIN: ?Func@?$ThunkFunc1@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473c60
// MS2-PIN: ?Func@?$ThunkFunc0@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$03N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473cf0
// MS2-PIN: ?Func@?$ThunkFunc1@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473d60
// MS2-PIN: ?Func@?$ThunkFunc0@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$05N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473df0
// MS2-PIN: ?Func@?$ThunkFunc1@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473e60
// MS2-PIN: ?Func@?$ThunkFunc0@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$07N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473ef0
// MS2-PIN: ?Func@?$ThunkFunc1@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473f60
// MS2-PIN: ?Func@?$ThunkFunc0@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$09K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142473ff0
// MS2-PIN: ?Func@?$ThunkFunc1@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142474050
// MS2-PIN: ?Func@?$ThunkFunc0@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0M@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424740c0
// MS2-PIN: ?Func@?$ThunkFunc1@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142474120
// MS2-PIN: ?Func@?$ThunkFunc0@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0O@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142474180
// MS2-PIN: ?Func@?$ThunkFunc1@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0P@$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424741e0
// MS2-PIN: ?Func@?$ThunkFunc0@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BA@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142474250
// MS2-PIN: ?Func@?$ThunkFunc1@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BB@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424742c0
// MS2-PIN: ?Func@?$ThunkFunc0@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BC@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142474350
// MS2-PIN: ?Func@?$ThunkFunc1@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BD@$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424743b0
// MS2-PIN: ?Func@?$ThunkFunc0@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BE@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142474420
// MS2-PIN: ?Func@?$ThunkFunc1@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BF@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142474490
// MS2-PIN: ?Func@?$ThunkFunc0@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BG@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142474520
// MS2-PIN: ?Func@?$ThunkFunc1@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BH@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142474590
// MS2-PIN: ?Func@?$ThunkFunc0@VBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BI@V?$SPtr@VBitmapFilter@fl_filters@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142474690
// MS2-PIN: ?Func@?$ThunkFunc0@VBitmapFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VBitmapFilter@fl_filters@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424748b0
// MS2-PIN: ?Func@?$ThunkFunc0@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142474d50
// MS2-PIN: ?Func@?$ThunkFunc1@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142474dc0
// MS2-PIN: ?Func@?$ThunkFunc0@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$01N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142474e50
// MS2-PIN: ?Func@?$ThunkFunc1@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142474ec0
// MS2-PIN: ?Func@?$ThunkFunc0@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$03N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475090
// MS2-PIN: ?Func@?$ThunkFunc1@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475100
// MS2-PIN: ?Func@?$ThunkFunc0@VBlurFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475190
// MS2-PIN: ?Func@?$ThunkFunc0@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$05N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475200
// MS2-PIN: ?Func@?$ThunkFunc1@VBlurFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475270
// MS2-PIN: ?Func@?$ThunkFunc1@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475300
// MS2-PIN: ?Func@?$ThunkFunc0@VBlurFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$01N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475390
// MS2-PIN: ?Func@?$ThunkFunc0@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$07K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475400
// MS2-PIN: ?Func@?$ThunkFunc1@VBlurFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475460
// MS2-PIN: ?Func@?$ThunkFunc1@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424754f0
// MS2-PIN: ?Func@?$ThunkFunc0@VBlurFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$03J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475560
// MS2-PIN: ?Func@?$ThunkFunc0@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$09N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424755c0
// MS2-PIN: ?Func@?$ThunkFunc1@VBlurFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475630
// MS2-PIN: ?Func@?$ThunkFunc1@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424756a0
// MS2-PIN: ?Func@?$ThunkFunc0@VBlurFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$05V?$SPtr@VBitmapFilter@fl_filters@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475730
// MS2-PIN: ?Func@?$ThunkFunc0@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0M@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424757e0
// MS2-PIN: ?Func@?$ThunkFunc1@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475840
// MS2-PIN: ?Func@?$ThunkFunc0@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0O@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424758a0
// MS2-PIN: ?Func@?$ThunkFunc1@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0P@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475900
// MS2-PIN: ?Func@?$ThunkFunc0@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BA@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475960
// MS2-PIN: ?Func@?$ThunkFunc1@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BB@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424759c0
// MS2-PIN: ?Func@?$ThunkFunc0@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BC@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475a20
// MS2-PIN: ?Func@?$ThunkFunc1@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BD@$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475a80
// MS2-PIN: ?Func@?$ThunkFunc0@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BE@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475af0
// MS2-PIN: ?Func@?$ThunkFunc1@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BF@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475b60
// MS2-PIN: ?Func@?$ThunkFunc0@VDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BG@V?$SPtr@VBitmapFilter@fl_filters@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475bf0
// MS2-PIN: ?Func@?$ThunkFunc0@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475f20
// MS2-PIN: ?Func@?$ThunkFunc1@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142475f90
// MS2-PIN: ?Func@?$ThunkFunc0@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$01N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142476020
// MS2-PIN: ?Func@?$ThunkFunc1@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142476090
// MS2-PIN: ?Func@?$ThunkFunc0@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$03N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142476120
// MS2-PIN: ?Func@?$ThunkFunc1@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142476190
// MS2-PIN: ?Func@?$ThunkFunc0@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$05K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142476220
// MS2-PIN: ?Func@?$ThunkFunc1@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142476280
// MS2-PIN: ?Func@?$ThunkFunc0@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$07_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424762f0
// MS2-PIN: ?Func@?$ThunkFunc1@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142476350
// MS2-PIN: ?Func@?$ThunkFunc0@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$09_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424763b0
// MS2-PIN: ?Func@?$ThunkFunc1@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142476410
// MS2-PIN: ?Func@?$ThunkFunc0@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0M@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142476470
// MS2-PIN: ?Func@?$ThunkFunc1@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424764d0
// MS2-PIN: ?Func@?$ThunkFunc0@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0O@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142476540
// MS2-PIN: ?Func@?$ThunkFunc1@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0P@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424765b0
// MS2-PIN: ?Func@?$ThunkFunc0@VGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0BA@V?$SPtr@VBitmapFilter@fl_filters@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142476640
// MS2-PIN: ?Func@?$ThunkFunc0@VColorMatrixFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142476970
// MS2-PIN: ?Func@?$ThunkFunc1@VColorMatrixFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@PEAVArray@fl@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142476a20
// MS2-PIN: ?Func@?$ThunkFunc0@VColorMatrixFilter@fl_filters@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VBitmapFilter@fl_filters@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142476a60
// MS2-PIN: ?Func@?$ThunkFunc0@VMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247c430
// MS2-PIN: ?Func@?$ThunkFunc1@VMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247c4e0
// MS2-PIN: ?Func@?$ThunkFunc5@VMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@NNNNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247c520
// MS2-PIN: ?Func@?$ThunkFunc5@VMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@NNNNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247c6a0
// MS2-PIN: ?Func@?$ThunkFunc1@VMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@$03V?$SPtr@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAVPoint@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247c820
// MS2-PIN: ?Func@?$ThunkFunc0@VMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247c910
// MS2-PIN: ?Func@?$ThunkFunc0@VMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247c930
// MS2-PIN: ?Func@?$ThunkFunc1@VMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247c950
// MS2-PIN: ?Func@?$ThunkFunc2@VMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247c9e0
// MS2-PIN: ?Func@?$ThunkFunc0@VMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@$08VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247cac0
// MS2-PIN: ?Func@?$ThunkFunc1@VMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@$09V?$SPtr@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAVPoint@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247cb30
// MS2-PIN: ?Func@?$ThunkFunc2@VMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247cc20
// MS2-PIN: ?Func@?$ThunkFunc0@VPerspectiveProjection@fl_geom@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247cf80
// MS2-PIN: ?Func@?$ThunkFunc1@VPerspectiveProjection@fl_geom@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@PEAVPoint@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d030
// MS2-PIN: ?Func@?$ThunkFunc0@VPerspectiveProjection@fl_geom@Instances@AS3@GFx@Scaleform@@$01N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d070
// MS2-PIN: ?Func@?$ThunkFunc1@VPerspectiveProjection@fl_geom@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d0e0
// MS2-PIN: ?Func@?$ThunkFunc0@VPerspectiveProjection@fl_geom@Instances@AS3@GFx@Scaleform@@$03N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d170
// MS2-PIN: ?Func@?$ThunkFunc1@VPerspectiveProjection@fl_geom@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d1e0
// MS2-PIN: ?Func@?$ThunkFunc0@VColorTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d270
// MS2-PIN: ?Func@?$ThunkFunc0@VPerspectiveProjection@fl_geom@Instances@AS3@GFx@Scaleform@@$05V?$SPtr@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d2d0
// MS2-PIN: ?Func@?$ThunkFunc1@VColorTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d380
// MS2-PIN: ?Func@?$ThunkFunc1@VColorTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d3f0
// MS2-PIN: ?Func@?$ThunkFunc0@VColorTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d430
// MS2-PIN: ?Func@?$ThunkFunc0@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d4a0
// MS2-PIN: ?Func@?$ThunkFunc1@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@$00V?$SPtr@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d510
// MS2-PIN: ?Func@?$ThunkFunc0@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d600
// MS2-PIN: ?Func@?$ThunkFunc1@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@$02_NPEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d6b0
// MS2-PIN: ?Func@?$ThunkFunc1@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d750
// MS2-PIN: ?Func@?$ThunkFunc2@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d7e0
// MS2-PIN: ?Func@?$ThunkFunc1@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@$05V?$SPtr@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d8c0
// MS2-PIN: ?Func@?$ThunkFunc0@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@$06VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247d9b0
// MS2-PIN: ?Func@?$ThunkFunc2@VPoint@fl_geom@Classes@AS3@GFx@Scaleform@@$0A@NPEAV12Instances@456@PEAV127456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247da20
// MS2-PIN: ?Func@?$ThunkFunc3@VPoint@fl_geom@Classes@AS3@GFx@Scaleform@@$00V?$SPtr@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAV12Instances@456@PEAV128456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247daf0
// MS2-PIN: ?Func@?$ThunkFunc2@VPoint@fl_geom@Classes@AS3@GFx@Scaleform@@$01V?$SPtr@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@@456@NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247dc60
// MS2-PIN: ?Func@?$ThunkFunc0@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247df10
// MS2-PIN: ?Func@?$ThunkFunc0@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$00N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247df80
// MS2-PIN: ?Func@?$ThunkFunc1@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247dff0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$02N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247e080
// MS2-PIN: ?Func@?$ThunkFunc1@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247e0f0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$04N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247e180
// MS2-PIN: ?Func@?$ThunkFunc1@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247e1f0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$06N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247e280
// MS2-PIN: ?Func@?$ThunkFunc1@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247e2f0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$08N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247e380
// MS2-PIN: ?Func@?$ThunkFunc1@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$09V?$SPtr@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247e3f0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0L@V?$SPtr@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247e620
// MS2-PIN: ?Func@?$ThunkFunc1@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0M@V?$SPtr@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247e6d0
// MS2-PIN: ?Func@?$ThunkFunc0@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247e7c0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247e830
// MS2-PIN: ?Func@?$ThunkFunc1@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247e870
// MS2-PIN: ?Func@?$ThunkFunc1@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0O@NPEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247e900
// MS2-PIN: ?Func@?$ThunkFunc0@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247e9b0
// MS2-PIN: ?Func@?$ThunkFunc2@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0P@_NPEAV123456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247ea60
// MS2-PIN: ?Func@?$ThunkFunc1@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@PEAVPoint@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247eb40
// MS2-PIN: ?Func@?$ThunkFunc1@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BA@$$CBVValue@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247eb80
// MS2-PIN: ?Func@?$ThunkFunc0@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$03N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247ebc0
// MS2-PIN: ?Func@?$ThunkFunc3@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BB@_NPEAV123456@N_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247ec30
// MS2-PIN: ?Func@?$ThunkFunc1@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247ed60
// MS2-PIN: ?Func@?$ThunkFunc0@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BC@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247edf0
// MS2-PIN: ?Func@?$ThunkFunc0@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$05N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247ee10
// MS2-PIN: ?Func@?$ThunkFunc0@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BD@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247ee80
// MS2-PIN: ?Func@?$ThunkFunc1@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247eef0
// MS2-PIN: ?Func@?$ThunkFunc0@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BE@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247ef80
// MS2-PIN: ?Func@?$ThunkFunc0@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$07V?$SPtr@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247efa0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BF@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f050
// MS2-PIN: ?Func@?$ThunkFunc1@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@PEAVPoint@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f0e0
// MS2-PIN: ?Func@?$ThunkFunc1@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BG@V?$SPtr@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f120
// MS2-PIN: ?Func@?$ThunkFunc0@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$09N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f210
// MS2-PIN: ?Func@?$ThunkFunc0@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BH@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f280
// MS2-PIN: ?Func@?$ThunkFunc1@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f2f0
// MS2-PIN: ?Func@?$ThunkFunc0@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0M@V?$SPtr@VPoint@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f380
// MS2-PIN: ?Func@?$ThunkFunc1@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@PEAVPoint@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f430
// MS2-PIN: ?Func@?$ThunkFunc0@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0O@V?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f470
// MS2-PIN: ?Func@?$ThunkFunc2@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0P@_NNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f520
// MS2-PIN: ?Func@?$ThunkFunc1@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0BA@_NPEAVPoint@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f650
// MS2-PIN: ?Func@?$ThunkFunc1@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0BB@_NPEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f6f0
// MS2-PIN: ?Func@?$ThunkFunc1@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0BC@_NPEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f790
// MS2-PIN: ?Func@?$ThunkFunc2@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0BD@$$CBVValue@456@NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f830
// MS2-PIN: ?Func@?$ThunkFunc1@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0BE@$$CBVValue@456@PEAVPoint@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f910
// MS2-PIN: ?Func@?$ThunkFunc1@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0BF@V?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247f950
// MS2-PIN: ?Func@?$ThunkFunc2@VVector3D@fl_geom@Classes@AS3@GFx@Scaleform@@$0A@NPEAV12Instances@456@PEAV127456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247fa40
// MS2-PIN: ?Func@?$ThunkFunc1@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0BG@_NPEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247fb10
// MS2-PIN: ?Func@?$ThunkFunc2@VVector3D@fl_geom@Classes@AS3@GFx@Scaleform@@$00NPEAV12Instances@456@PEAV127456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247fbb0
// MS2-PIN: ?Func@?$ThunkFunc0@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0BH@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247fc80
// MS2-PIN: ?Func@?$ThunkFunc2@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0BI@$$CBVValue@456@NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247fce0
// MS2-PIN: ?Func@?$ThunkFunc1@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0BJ@$$CBVValue@456@PEAVPoint@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247fdc0
// MS2-PIN: ?Func@?$ThunkFunc0@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0BK@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247fe00
// MS2-PIN: ?Func@?$ThunkFunc0@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0BL@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247fe20
// MS2-PIN: ?Func@?$ThunkFunc1@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@$0BM@V?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14247fe90
// MS2-PIN: ?Func@?$ThunkFunc0@VTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VColorTransform@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424800c0
// MS2-PIN: ?Func@?$ThunkFunc1@VTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@PEAVColorTransform@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142480170
// MS2-PIN: ?Func@?$ThunkFunc0@VTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VColorTransform@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424801b0
// MS2-PIN: ?Func@?$ThunkFunc0@VTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$02V?$SPtr@VMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142480260
// MS2-PIN: ?Func@?$ThunkFunc0@VTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$03V?$SPtr@VMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142480310
// MS2-PIN: ?Func@?$ThunkFunc1@VTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@PEAVMatrix@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424803c0
// MS2-PIN: ?Func@?$ThunkFunc0@VTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$05V?$SPtr@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142480400
// MS2-PIN: ?Func@?$ThunkFunc1@VTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@PEAVMatrix3D@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424804b0
// MS2-PIN: ?Func@?$ThunkFunc0@VTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$07V?$SPtr@VPerspectiveProjection@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424804f0
// MS2-PIN: ?Func@?$ThunkFunc1@VTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@PEAVPerspectiveProjection@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424805a0
// MS2-PIN: ?Func@?$ThunkFunc0@VTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$09V?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424805e0
// MS2-PIN: ?Func@?$ThunkFunc1@VTransform@fl_geom@Instances@AS3@GFx@Scaleform@@$0L@V?$SPtr@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAVDisplayObject@fl_display@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142480690
// MS2-PIN: ?Func@?$ThunkFunc0@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142480780
// MS2-PIN: ?Func@?$ThunkFunc0@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$00V?$SPtr@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424807f0
// MS2-PIN: ?Func@?$ThunkFunc1@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@PEAVVector3D@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424808a0
// MS2-PIN: ?Func@?$ThunkFunc0@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$02V?$SPtr@VVector_double@fl_vec@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424808e0
// MS2-PIN: ?Func@?$ThunkFunc1@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@PEAVVector_double@fl_vec@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142480990
// MS2-PIN: ?Func@?$ThunkFunc1@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424809d0
// MS2-PIN: ?Func@?$ThunkFunc3@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@NPEAVVector3D@23456@PEAV823456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142480b50
// MS2-PIN: ?Func@?$ThunkFunc3@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@NNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142480c50
// MS2-PIN: ?Func@?$ThunkFunc3@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@NNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142480d80
// MS2-PIN: ?Func@?$ThunkFunc0@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$08V?$SPtr@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142480eb0
// MS2-PIN: ?Func@?$ThunkFunc1@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$09V?$SPtr@VVector_object@fl_vec@Instances@AS3@GFx@Scaleform@@@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142480f60
// MS2-PIN: ?Func@?$ThunkFunc1@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0L@V?$SPtr@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAVVector3D@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424810f0
// MS2-PIN: ?Func@?$ThunkFunc0@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0M@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424811e0
// MS2-PIN: ?Func@?$ThunkFunc3@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0N@V?$SPtr@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAV123456@PEAV123456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142481200
// MS2-PIN: ?Func@?$ThunkFunc2@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0O@$$CBVValue@456@PEAV123456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142481370
// MS2-PIN: ?Func@?$ThunkFunc0@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0P@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142481430
// MS2-PIN: ?Func@?$ThunkFunc3@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BA@$$CBVValue@456@PEAVVector3D@23456@PEAV823456@PEAV823456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142481490
// MS2-PIN: ?Func@?$ThunkFunc1@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BB@$$CBVValue@456@PEAV123456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142481510
// MS2-PIN: ?Func@?$ThunkFunc3@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BC@$$CBVValue@456@NPEAVVector3D@23456@PEAV823456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142481550
// MS2-PIN: ?Func@?$ThunkFunc3@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BD@$$CBVValue@456@NNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142481650
// MS2-PIN: ?Func@?$ThunkFunc3@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BE@$$CBVValue@456@NNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142481780
// MS2-PIN: ?Func@?$ThunkFunc2@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BF@_NPEAVVector_object@fl_vec@3456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424818b0
// MS2-PIN: ?Func@?$ThunkFunc1@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BG@V?$SPtr@VVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@@456@PEAVVector3D@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142481a30
// MS2-PIN: ?Func@?$ThunkFunc2@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BH@$$CBVValue@456@PEAVVector_double@fl_vec@3456@PEAV893456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142481b20
// MS2-PIN: ?Func@?$ThunkFunc0@VMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@$0BI@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142481b70
// MS2-PIN: ??_7?$RefCountBase@VFilter@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318ccd8
// MS2-PIN: ??_7Filter@Render@Scaleform@@6B@ 0x14315ac78
// MS2-PIN: ??_7BlurFilterImpl@Render@Scaleform@@6B@ 0x14315ac90
// MS2-PIN: ??_7BlurFilter@Render@Scaleform@@6B@ 0x14315aca8
// MS2-PIN: ??_7ShadowFilter@Render@Scaleform@@6B@ 0x14315acc0
// MS2-PIN: ??_7GlowFilter@Render@Scaleform@@6B@ 0x14315acd8
// MS2-PIN: ??_7BevelFilter@Render@Scaleform@@6B@ 0x14315acf0
// MS2-PIN: ??_7BitmapFilter@fl_filters@Instances@AS3@GFx@Scaleform@@6B@ 0x14315ad08
// MS2-PIN: ??_7BitmapFilter@fl_filters@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14315add8
// MS2-PIN: ??_7BitmapFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315ae80
// MS2-PIN: ??_7BevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@6B@ 0x14315af18
// MS2-PIN: ??_7BevelFilter@fl_filters@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14315aff0
// MS2-PIN: ??_7BevelFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315b098
// MS2-PIN: ??_7BitmapFilterQuality@fl_filters@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315b1c8
// MS2-PIN: ??_7BitmapFilterQuality@fl_filters@Classes@AS3@GFx@Scaleform@@6B@ 0x14315b268
// MS2-PIN: ??_7BitmapFilterType@fl_filters@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315b358
// MS2-PIN: ??_7BitmapFilterType@fl_filters@Classes@AS3@GFx@Scaleform@@6B@ 0x14315b3f0
// MS2-PIN: ??_7BlurFilter@fl_filters@Instances@AS3@GFx@Scaleform@@6B@ 0x14315b4e0
// MS2-PIN: ??_7BlurFilter@fl_filters@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14315b5b0
// MS2-PIN: ??_7BlurFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315b658
// MS2-PIN: ??_7ColorMatrixFilter@fl_filters@Instances@AS3@GFx@Scaleform@@6B@ 0x14315b6e8
// MS2-PIN: ??_7ColorMatrixFilter@fl_filters@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14315b7c0
// MS2-PIN: ??_7ColorMatrixFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315b870
// MS2-PIN: ??_7ConvolutionFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315b908
// MS2-PIN: ??_7DisplacementMapFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315b9a0
// MS2-PIN: ??_7DisplacementMapFilterMode@fl_filters@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315ba40
// MS2-PIN: ??_7DisplacementMapFilterMode@fl_filters@Classes@AS3@GFx@Scaleform@@6B@ 0x14315bae0
// MS2-PIN: ??_7DropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@6B@ 0x14315bbe0
// MS2-PIN: ??_7DropShadowFilter@fl_filters@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14315bcb0
// MS2-PIN: ??_7DropShadowFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315bd60
// MS2-PIN: ??_7GlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@6B@ 0x14315bdf8
// MS2-PIN: ??_7GlowFilter@fl_filters@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14315bec8
// MS2-PIN: ??_7GlowFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315bf70
// MS2-PIN: ??_7GradientBevelFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315c000
// MS2-PIN: ??_7GradientGlowFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315c0a0
// MS2-PIN: ??_GFilter@Render@Scaleform@@UEAAPEAXI@Z 0x1424790d0
// MS2-PIN: ??_GBlurFilterImpl@Render@Scaleform@@UEAAPEAXI@Z 0x142478ba0
// MS2-PIN: ??_GBlurFilter@Render@Scaleform@@UEAAPEAXI@Z 0x1424789e0
// MS2-PIN: ??_GShadowFilter@Render@Scaleform@@UEAAPEAXI@Z 0x142479410
// MS2-PIN: ??_GGlowFilter@Render@Scaleform@@UEAAPEAXI@Z 0x142479130
// MS2-PIN: ??_GBevelFilter@Render@Scaleform@@UEAAPEAXI@Z 0x1424784e0
// MS2-PIN: ??_GBitmapFilter@fl_filters@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478790
// MS2-PIN: ??_GBitmapFilter@fl_filters@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478730
// MS2-PIN: ??_GBitmapFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424786a0
// MS2-PIN: ??_GBevelFilter@fl_filters@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478630
// MS2-PIN: ??_GBevelFilter@fl_filters@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424785d0
// MS2-PIN: ??_GBevelFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478540
// MS2-PIN: ??_GBitmapFilterQuality@fl_filters@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478800
// MS2-PIN: ??_GBitmapFilterQuality@fl_filters@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478890
// MS2-PIN: ??_GBitmapFilterType@fl_filters@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424788f0
// MS2-PIN: ??_GBitmapFilterType@fl_filters@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478980
// MS2-PIN: ??_GBlurFilter@fl_filters@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478b30
// MS2-PIN: ??_GBlurFilter@fl_filters@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478ad0
// MS2-PIN: ??_GBlurFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478a40
// MS2-PIN: ??_GColorMatrixFilter@fl_filters@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478cf0
// MS2-PIN: ??_GColorMatrixFilter@fl_filters@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478c90
// MS2-PIN: ??_GColorMatrixFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478c00
// MS2-PIN: ??_GConvolutionFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478d60
// MS2-PIN: ??_GDisplacementMapFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478df0
// MS2-PIN: ??_GDisplacementMapFilterMode@fl_filters@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478e80
// MS2-PIN: ??_GDisplacementMapFilterMode@fl_filters@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478f10
// MS2-PIN: ??_GDropShadowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142479060
// MS2-PIN: ??_GDropShadowFilter@fl_filters@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142479000
// MS2-PIN: ??_GDropShadowFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142478f70
// MS2-PIN: ??_GGlowFilter@fl_filters@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142479280
// MS2-PIN: ??_GGlowFilter@fl_filters@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142479220
// MS2-PIN: ??_GGlowFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142479190
// MS2-PIN: ??_GGradientBevelFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424792f0
// MS2-PIN: ??_GGradientGlowFilter@fl_filters@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142479380
// MS2-PIN: ??_7ColorTransform@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315de18
// MS2-PIN: ??_7ColorTransform@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14315dee8
// MS2-PIN: ??_7ColorTransform@fl_geom@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315df90
// MS2-PIN: ??_7Vector3D@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315e0c0
// MS2-PIN: ??_7Vector3D@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14315e188
// MS2-PIN: ??_7Vector3D@fl_geom@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315e238
// MS2-PIN: ??_7Vector3D@fl_geom@Classes@AS3@GFx@Scaleform@@6B@ 0x14315e2c8
// MS2-PIN: ??_7Matrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315e3d8
// MS2-PIN: ??_7Matrix3D@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14315e4a0
// MS2-PIN: ??_7Matrix3D@fl_geom@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315e548
// MS2-PIN: ??_7Matrix@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315e6f0
// MS2-PIN: ??_7Matrix@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14315e7b8
// MS2-PIN: ??_7Matrix@fl_geom@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315e858
// MS2-PIN: ??_7Point@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315e8e8
// MS2-PIN: ??_7Point@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14315e9b0
// MS2-PIN: ??_7Point@fl_geom@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315ea50
// MS2-PIN: ??_7Point@fl_geom@Classes@AS3@GFx@Scaleform@@6B@ 0x14315eae0
// MS2-PIN: ??_7PerspectiveProjection@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315ebd8
// MS2-PIN: ??_7PerspectiveProjection@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14315ecb0
// MS2-PIN: ??_7PerspectiveProjection@fl_geom@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315ed60
// MS2-PIN: ??_7Rectangle@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315ee00
// MS2-PIN: ??_7Rectangle@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14315eec8
// MS2-PIN: ??_7Rectangle@fl_geom@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315ef70
// MS2-PIN: ??_7Transform@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315f008
// MS2-PIN: ??_7Transform@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14315f0d0
// MS2-PIN: ??_7Transform@fl_geom@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14315f178
// MS2-PIN: ??_GColorTransform@fl_geom@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142482ce0
// MS2-PIN: ??_GColorTransform@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142482c80
// MS2-PIN: ??_GColorTransform@fl_geom@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142482bf0
// MS2-PIN: ??_GMatrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142482e30
// MS2-PIN: ??_GMatrix3D@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142482dd0
// MS2-PIN: ??_GMatrix3D@fl_geom@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142482d40
// MS2-PIN: ??_GMatrix@fl_geom@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142482f80
// MS2-PIN: ??_GMatrix@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142482f20
// MS2-PIN: ??_GMatrix@fl_geom@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142482e90
// MS2-PIN: ??_GPoint@fl_geom@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142483280
// MS2-PIN: ??_GPoint@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142483220
// MS2-PIN: ??_GPoint@fl_geom@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142483130
// MS2-PIN: ??_GPoint@fl_geom@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424831c0
// MS2-PIN: ??_GPerspectiveProjection@fl_geom@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424830d0
// MS2-PIN: ??_GPerspectiveProjection@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142483070
// MS2-PIN: ??_GPerspectiveProjection@fl_geom@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142482fe0
// MS2-PIN: ??_GVector3D@fl_geom@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142483750
// MS2-PIN: ??_GVector3D@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424836f0
// MS2-PIN: ??_GVector3D@fl_geom@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142483580
// MS2-PIN: ??_GVector3D@fl_geom@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142483610
// MS2-PIN: ??_GRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424833d0
// MS2-PIN: ??_GRectangle@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142483370
// MS2-PIN: ??_GRectangle@fl_geom@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424832e0
// MS2-PIN: ??_GTransform@fl_geom@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142483520
// MS2-PIN: ??_GTransform@fl_geom@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424834c0
// MS2-PIN: ??_GTransform@fl_geom@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142483430
