// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_11
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424837b0-0x142497a90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$ThunkArgs2@V?$SPtr@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@AEBVASString@34@AEBV534@@AS3@GFx@Scaleform@@QEAA@AEAVVM@123@AEAVValue@123@IPEBV5123@AEBU?$ThunkDefs2@AEBVASString@GFx@Scaleform@@AEBV123@@123@@Z 0x1424959c0 ; unique
// MS2-PIN: ??1?$ThunkArgs1@V?$SPtr@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@AEBVASString@34@@AS3@GFx@Scaleform@@QEAA@XZ 0x142497230 ; unique
// MS2-PINS-END tplpin
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x1424914e0: Instances::fl_net::URLRequest::authenticateGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 0, bool>;
// thunk 0x142491540: Instances::fl_net::URLRequest::authenticateSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 1, const Value, bool>;
// thunk 0x1424915a0: Instances::fl_net::URLRequest::cacheResponseGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 2, bool>;
// thunk 0x142491600: Instances::fl_net::URLRequest::cacheResponseSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 3, const Value, bool>;
// thunk 0x142491660: Instances::fl_net::URLRequest::contentTypeGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 4, ASString>;
// thunk 0x1424916d0: Instances::fl_net::URLRequest::contentTypeSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 5, const Value, const ASString&>;
// thunk 0x1424917d0: Instances::fl_net::URLRequest::dataGet
// MS2-FUNCTIONAL: not matched: the Value-result getter with no arguments is laid out differently by the exe (same calls)
template struct ThunkFunc0<Instances::fl_net::URLRequest, 6, Value>;
// thunk 0x142491880: Instances::fl_net::URLRequest::dataSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 7, const Value, const Value&>;
// thunk 0x1424919d0: Instances::fl_net::URLRequest::digestGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 8, ASString>;
// thunk 0x142491a40: Instances::fl_net::URLRequest::digestSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 9, const Value, const ASString&>;
// thunk 0x142491b40: Instances::fl_net::URLRequest::followRedirectsGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 10, bool>;
// thunk 0x142491ba0: Instances::fl_net::URLRequest::followRedirectsSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 11, const Value, bool>;
// thunk 0x142491c00: Instances::fl_net::URLRequest::manageCookiesGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 12, bool>;
// thunk 0x142491c60: Instances::fl_net::URLRequest::manageCookiesSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 13, const Value, bool>;
// thunk 0x142491cc0: Instances::fl_net::URLRequest::methodGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 14, ASString>;
// thunk 0x142491d30: Instances::fl_net::URLRequest::methodSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 15, const Value, const ASString&>;
// thunk 0x142491e30: Instances::fl_net::URLRequest::requestHeadersGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 16, SPtr<Instances::fl::Array>>;
// thunk 0x142491ee0: Instances::fl_net::URLRequest::requestHeadersSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 17, const Value, Instances::fl::Array*>;
// thunk 0x142491f20: Instances::fl_net::URLRequest::urlGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 18, ASString>;
// thunk 0x142491f90: Instances::fl_net::URLRequest::urlSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 19, const Value, const ASString&>;
// thunk 0x142492090: Instances::fl_net::URLRequest::useCacheGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 20, bool>;
// thunk 0x1424920f0: Instances::fl_net::URLRequest::useCacheSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 21, const Value, bool>;
// thunk 0x142492150: Instances::fl_net::URLRequest::userAgentGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 22, ASString>;
// thunk 0x1424921c0: Instances::fl_net::URLRequest::userAgentSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 23, const Value, const ASString&>;
// thunk 0x1424927f0: Instances::fl_net::URLVariables::decode
template struct ThunkFunc1<Instances::fl_net::URLVariables, 0, const Value, const ASString&>;
// thunk 0x1424928f0: Instances::fl_net::URLVariables::toString
template struct ThunkFunc0<Instances::fl_net::URLVariables, 1, ASString>;
// thunk 0x142492ce0: Instances::fl_net::SharedObject::clientGet
template struct ThunkFunc0<Instances::fl_net::SharedObject, 0, SPtr<Instances::fl::Object>>;
// thunk 0x142492d90: Instances::fl_net::SharedObject::clientSet
template struct ThunkFunc1<Instances::fl_net::SharedObject, 1, const Value, const Value&>;
// thunk 0x142492ee0: Instances::fl_net::SharedObject::dataGet
template struct ThunkFunc0<Instances::fl_net::SharedObject, 2, SPtr<Instances::fl::Object>>;
// thunk 0x142492f90: Instances::fl_net::SharedObject::defaultObjectEncodingSet
template struct ThunkFunc1<Instances::fl_net::SharedObject, 3, const Value, UInt32>;
// thunk 0x142493000: Instances::fl_net::SharedObject::fpsSet
template struct ThunkFunc1<Instances::fl_net::SharedObject, 4, const Value, Value::Number>;
// thunk 0x142493090: Instances::fl_net::SharedObject::objectEncodingGet
template struct ThunkFunc0<Instances::fl_net::SharedObject, 5, UInt32>;
// thunk 0x1424930f0: Instances::fl_net::SharedObject::objectEncodingSet
template struct ThunkFunc1<Instances::fl_net::SharedObject, 6, const Value, UInt32>;
// thunk 0x142493160: Instances::fl_net::SharedObject::sizeGet
template struct ThunkFunc0<Instances::fl_net::SharedObject, 7, UInt32>;
// thunk 0x1424931c0: Instances::fl_net::SharedObject::clear
template struct ThunkFunc0<Instances::fl_net::SharedObject, 8, const Value>;
// thunk 0x1424931e0: Instances::fl_net::SharedObject::close
template struct ThunkFunc0<Instances::fl_net::SharedObject, 9, const Value>;
// Instances::fl_net::SharedObject::connect argument 1 default
template <> struct ThunkMethodDefault<Instances::fl_net::SharedObject, 10, 1, const ASString&>
{
    SF_INLINE static ASString Get(StringManager& sm) { return sm.CreateConstString("null"); }
};
// thunk 0x142493200: Instances::fl_net::SharedObject::connect
template struct ThunkFunc2<Instances::fl_net::SharedObject, 10, const Value, Instances::fl_net::NetConnection*, const ASString&>;
// thunk 0x142493340: Instances::fl_net::SharedObject::flush
template struct ThunkFunc1<Instances::fl_net::SharedObject, 11, ASString, SInt32>;
// thunk 0x1424933f0: Instances::fl_net::SharedObject::send
template struct ThunkFunc2<Instances::fl_net::SharedObject, 12, Value, unsigned, const Value*>;
// thunk 0x142493410: Instances::fl_net::SharedObject::setDirty
template struct ThunkFunc1<Instances::fl_net::SharedObject, 13, const Value, const ASString&>;
// thunk 0x142493510: Instances::fl_net::SharedObject::setProperty
template struct ThunkFunc2<Instances::fl_net::SharedObject, 14, const Value, const ASString&, const Value&>;
// Classes::fl_net::SharedObject::getLocal argument 1 default
template <> struct ThunkMethodDefault<Classes::fl_net::SharedObject, 0, 1, const ASString&>
{
    SF_INLINE static ASString Get(StringManager& sm) { return sm.CreateConstString("null"); }
};
// thunk 0x142493b70: Classes::fl_net::SharedObject::getLocal
// MS2-FUNCTIONAL: register allocation only: r12/r15 swapped for the result and argv (4 bytes longer in the exe)
template struct ThunkFunc3<Classes::fl_net::SharedObject, 0, SPtr<Instances::fl_net::SharedObject>, const ASString&, const ASString&, bool>;
// Classes::fl_net::SharedObject::getRemote argument 1 default
template <> struct ThunkMethodDefault<Classes::fl_net::SharedObject, 1, 1, const ASString&>
{
    SF_INLINE static ASString Get(StringManager& sm) { return sm.CreateConstString("null"); }
};
// Classes::fl_net::SharedObject::getRemote argument 2 default
template <> struct ThunkMethodDefault<Classes::fl_net::SharedObject, 1, 2, const Value&>
{
    SF_INLINE static Value Get(StringManager&) { return Value(false); }
};
// thunk 0x142493ce0: Classes::fl_net::SharedObject::getRemote
// MS2-FUNCTIONAL: register allocation only: the exe assigns the result and argv to other callee-saved registers
template struct ThunkFunc4<Classes::fl_net::SharedObject, 1, SPtr<Instances::fl_net::SharedObject>, const ASString&, const ASString&, const Value&, bool>;
// thunk 0x142494270: Instances::fl_net::NetConnection::clientGet
template struct ThunkFunc0<Instances::fl_net::NetConnection, 0, SPtr<Instances::fl::Object>>;
// thunk 0x142494320: Instances::fl_net::NetConnection::clientSet
template struct ThunkFunc1<Instances::fl_net::NetConnection, 1, const Value, const Value&>;
// thunk 0x142494470: Instances::fl_net::NetConnection::connectedGet
template struct ThunkFunc0<Instances::fl_net::NetConnection, 2, bool>;
// thunk 0x1424944d0: Instances::fl_net::NetConnection::connectedProxyTypeGet
template struct ThunkFunc0<Instances::fl_net::NetConnection, 3, ASString>;
// thunk 0x142494540: Instances::fl_net::NetConnection::defaultObjectEncodingSet
template struct ThunkFunc1<Instances::fl_net::NetConnection, 4, const Value, UInt32>;
// thunk 0x1424945b0: Instances::fl_net::NetConnection::objectEncodingGet
template struct ThunkFunc0<Instances::fl_net::NetConnection, 5, UInt32>;
// thunk 0x142494610: Instances::fl_net::NetConnection::objectEncodingSet
template struct ThunkFunc1<Instances::fl_net::NetConnection, 6, const Value, UInt32>;
// thunk 0x142494680: Instances::fl_net::NetConnection::proxyTypeGet
template struct ThunkFunc0<Instances::fl_net::NetConnection, 7, ASString>;
// thunk 0x1424946f0: Instances::fl_net::NetConnection::proxyTypeSet
template struct ThunkFunc1<Instances::fl_net::NetConnection, 8, const Value, const ASString&>;
// thunk 0x1424947f0: Instances::fl_net::NetConnection::uriGet
template struct ThunkFunc0<Instances::fl_net::NetConnection, 9, ASString>;
// thunk 0x142494860: Instances::fl_net::NetConnection::usingTLSGet
template struct ThunkFunc0<Instances::fl_net::NetConnection, 10, bool>;
// Instances::fl_net::NetConnection::addHeader argument 2 default
template <> struct ThunkMethodDefault<Instances::fl_net::NetConnection, 11, 2, const Value&>
{
    SF_INLINE static Value Get(StringManager&) { return Value::GetNull(); }
};
// thunk 0x1424948c0: Instances::fl_net::NetConnection::addHeader
// MS2-FUNCTIONAL: register allocation only: the exe keeps the Null default in another register (same calls)
template struct ThunkFunc3<Instances::fl_net::NetConnection, 11, const Value, const ASString&, bool, const Value&>;
// thunk 0x142494ad0: Instances::fl_net::NetConnection::call
template struct ThunkFunc2<Instances::fl_net::NetConnection, 12, Value, unsigned, const Value*>;
// thunk 0x142494af0: Instances::fl_net::NetConnection::close
template struct ThunkFunc0<Instances::fl_net::NetConnection, 13, const Value>;
// thunk 0x142494b10: Instances::fl_net::NetConnection::connect
template struct ThunkFunc2<Instances::fl_net::NetConnection, 14, Value, unsigned, const Value*>;
// thunk 0x142495170: Instances::fl_net::URLLoader::addEventListener
template struct ThunkFunc5<Instances::fl_net::URLLoader, 0, const Value, const ASString&, const Value&, bool, SInt32, bool>;
// thunk 0x142495410: Instances::fl_net::URLLoader::close
template struct ThunkFunc0<Instances::fl_net::URLLoader, 1, const Value>;
// thunk 0x142495430: Instances::fl_net::URLLoader::load
template struct ThunkFunc1<Instances::fl_net::URLLoader, 2, const Value, Instances::fl_net::URLRequest*>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// result += String: what the String-building natives (Vector3D, Matrix3D) append with. The const char* / ASString
// operator+ overloads come from the AS3 Abc type header.
namespace Scaleform { namespace GFx
{
    inline void operator+=(ASString& l, const String& r)
    {
        const char* str = r.ToCStr();
        l.Append(str, strlen(str));
    }
}}

// ==== flash.geom: AS3 constructors, instance factories and natives (traits and constructors are in sfr_as3_10) ======

namespace Scaleform { namespace GFx { namespace AS3 {

// The instance constructors are out of line in sfr_as3_10; the factories below inline them, as the exe does.
namespace Instances { namespace fl_geom
{
    inline ColorTransform::ColorTransform(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
    {
        alphaMultiplier = blueMultiplier = greenMultiplier = redMultiplier = 1.0;
        alphaOffset = blueOffset = greenOffset = redOffset = 0.0;
    }

    inline Matrix3D::Matrix3D(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , pDispObj(0)
    {
    }

    inline Matrix::Matrix(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , a(0), b(0), c(0), d(0), tx(0), ty(0)
    {
    }

    inline PerspectiveProjection::PerspectiveProjection(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , fieldOfView(55), pDispObj(0)
    {
        projectionCenter.x = 250.f;
        projectionCenter.y = 250.f;
        focalLength = 250.0 / tan(SF_DEGTORAD(fieldOfView) / 2);
    }

    inline Point::Point(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , x(0), y(0)
    {
    }

    inline Rectangle::Rectangle(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , height(0), width(0), x(0), y(0)
    {
    }

    inline Transform::Transform(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , pDispObj(0)
    {
    }

    inline Vector3D::Vector3D(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , x(0), y(0), z(0), w(0)
    {
    }
}}

namespace Instances { namespace fl_geom
{
    // AS3: new ColorTransform(redMultiplier, greenMultiplier, blueMultiplier, alphaMultiplier, redOffset, ...).
    // @0x1424837b0
    void ColorTransform::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc > 0)
        {
            if (!argv[0].Convert2Number(redMultiplier)) return;
            if (argc > 1)
            {
                if (!argv[1].Convert2Number(greenMultiplier)) return;
                if (argc > 2)
                {
                    if (!argv[2].Convert2Number(blueMultiplier)) return;
                    if (argc > 3)
                    {
                        if (!argv[3].Convert2Number(alphaMultiplier)) return;
                        if (argc > 4)
                        {
                            if (!argv[4].Convert2Number(redOffset)) return;
                            if (argc > 5)
                            {
                                if (!argv[5].Convert2Number(greenOffset)) return;
                                if (argc > 6)
                                {
                                    if (!argv[6].Convert2Number(blueOffset)) return;
                                    if (argc > 7)
                                        argv[7].Convert2Number(alphaOffset);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // AS3: new Matrix(a, b, c, d, tx, ty); the identity when no argument is given.
    // @0x142483c90
    void Matrix::AS3Constructor(unsigned argc, const Value* argv)
    {
        a = 1; b = 0; c = 0; d = 1; tx = 0; ty = 0;
        if (argc > 0)
        {
            if (!argv[0].Convert2Number(a)) return;
            if (argc > 1)
            {
                if (!argv[1].Convert2Number(b)) return;
                if (argc > 2)
                {
                    if (!argv[2].Convert2Number(c)) return;
                    if (argc > 3)
                    {
                        if (!argv[3].Convert2Number(d)) return;
                        if (argc > 4)
                        {
                            if (!argv[4].Convert2Number(tx)) return;
                            if (argc > 5)
                                argv[5].Convert2Number(ty);
                        }
                    }
                }
            }
        }
    }

    // AS3: new PerspectiveProjection(fieldOfView, focalLength, centerX, centerY); zero keeps the default.
    // @0x142483db0
    void PerspectiveProjection::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc > 0)
        {
            Value::Number v;
            if (!argv[0].Convert2Number(v))
                return;
            if (v != 0)
                fieldOfView = v;
            if (argc > 1)
            {
                if (!argv[1].Convert2Number(v))
                    return;
                if (v != 0)
                    focalLength = v;
                if (argc > 2)
                {
                    Value::Number cx, cy;
                    if (!argv[2].Convert2Number(cx))
                        return;
                    if (!argv[3].Convert2Number(cy))
                        return;
                    if (cx != 0 && cy != 0)
                    {
                        projectionCenter.x = (float)cx;
                        projectionCenter.y = (float)cy;
                    }
                }
            }
        }
    }

    // AS3: new Point(x, y).
    // @0x142483ec0
    void Point::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc > 0)
        {
            if (!argv[0].Convert2Number(x)) return;
            if (argc > 1)
                argv[1].Convert2Number(y);
        }
    }

    // AS3: new Rectangle(x, y, width, height).
    // @0x142483f20
    void Rectangle::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc > 0)
        {
            if (!argv[0].Convert2Number(x)) return;
            if (argc > 1)
            {
                if (!argv[1].Convert2Number(y)) return;
                if (argc > 2)
                {
                    if (!argv[2].Convert2Number(width)) return;
                    if (argc > 3)
                        argv[3].Convert2Number(height);
                }
            }
        }
    }

    // A Transform is made by DisplayObject.transform, never from script arguments.
    // @0x142483fc0
    void Transform::AS3Constructor(unsigned, const Value*)
    {
    }

    // AS3: new Vector3D(x, y, z, w).
    // @0x142483fd0
    void Vector3D::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc > 0)
        {
            if (!argv[0].Convert2Number(x)) return;
            if (argc > 1)
            {
                if (!argv[1].Convert2Number(y)) return;
                if (argc > 2)
                {
                    if (!argv[2].Convert2Number(z)) return;
                    if (argc > 3)
                        argv[3].Convert2Number(w);
                }
            }
        }
    }
}}

namespace InstanceTraits { namespace fl_geom
{
    // @0x1424854a0
    Pickable<ColorTransform::InstanceType> ColorTransform::MakeInstance(ColorTransform& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x142485540
    Pickable<Matrix3D::InstanceType> Matrix3D::MakeInstance(Matrix3D& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424855f0
    Pickable<Matrix::InstanceType> Matrix::MakeInstance(Matrix& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x142485680
    Pickable<PerspectiveProjection::InstanceType> PerspectiveProjection::MakeInstance(PerspectiveProjection& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x142485730
    Pickable<Point::InstanceType> Point::MakeInstance(Point& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424857b0
    Pickable<Rectangle::InstanceType> Rectangle::MakeInstance(Rectangle& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x142485830
    Pickable<Transform::InstanceType> Transform::MakeInstance(Transform& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1424858b0
    Pickable<Vector3D::InstanceType> Vector3D::MakeInstance(Vector3D& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x142485930
    void ColorTransform::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<ColorTransform&>(t)));
    }

    // @0x1424859c0
    void Matrix3D::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<Matrix3D&>(t)));
    }

    // @0x142485a60
    void Matrix::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<Matrix&>(t)));
    }

    // @0x142485ae0
    void PerspectiveProjection::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<PerspectiveProjection&>(t)));
    }

    // @0x142485b80
    void Point::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<Point&>(t)));
    }

    // @0x142485bf0
    void Rectangle::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<Rectangle&>(t)));
    }

    // @0x142485c60
    void Transform::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<Transform&>(t)));
    }

    // @0x142485cc0
    void Vector3D::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<Vector3D&>(t)));
    }
}}

namespace Instances { namespace fl_geom
{
    // @0x142486840
    void Point::add(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point* v)
    {
        if (v == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        Value args[] = { Value(v->x + x), Value(v->y + y) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Point", 2, args).DoNotCheck();
    }

    // @0x1424879a0
    void Point::clone(SPtr<Instances::fl_geom::Point>& result)
    {
        Value args[] = { Value(x), Value(y) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Point", 2, args).DoNotCheck();
    }

    // @0x142489990
    void Point::equals(bool& result, Instances::fl_geom::Point* toCompare)
    {
        if (toCompare == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        result = x == toCompare->x && y == toCompare->y;
    }

    // @0x14248ab60
    void Point::lengthGet(Value::Number& result)
    {
        result = sqrt(x * x + y * y);
    }

    // Scales the point in place to the given length; the origin stays the origin.
    // @0x14248bac0
    void Point::normalize(const Value& result, Value::Number thickness)
    {
        SF_UNUSED(result);
        if (x == 0 && y == 0)
        {
            x = 0;
            y = 0;
            return;
        }
        const Value::Number len = sqrt(y * y + x * x);
        y = y * thickness / len;
        x = x * thickness / len;
    }

    // @0x14248bbe0
    void Point::offset(const Value& result, Value::Number dx, Value::Number dy)
    {
        SF_UNUSED(result);
        x += dx;
        y += dy;
    }

    // @0x14248e240
    void Point::subtract(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point* v)
    {
        if (v == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        Value args[] = { Value(x - v->x), Value(y - v->y) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Point", 2, args).DoNotCheck();
    }

    // "(x=1, y=2)"
    // @0x14248f9b0
    void Point::toString(ASString& result)
    {
        result += GetVM().GetStringManager().CreateConstString("(x=") + GetVM().AsString(Value(x))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("y=")
            + GetVM().AsString(Value(y)) + GetVM().GetStringManager().CreateConstString(")");
    }
}}

namespace Classes { namespace fl_geom
{
    // @0x142489880
    void Point::distance(Value::Number& result, Instances::fl_geom::Point* pt1, Instances::fl_geom::Point* pt2)
    {
        const Value::Number dy = pt1->y - pt2->y;
        const Value::Number dx = pt1->x - pt2->x;
        result = sqrt(dx * dx + dy * dy);
    }

    // @0x14248a360
    void Point::interpolate(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point* pt1,
                            Instances::fl_geom::Point* pt2, Value::Number f)
    {
        Value args[] = { Value((pt2->x - pt1->x) * f + pt1->x), Value((pt2->y - pt1->y) * f + pt1->y) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Point", 2, args).DoNotCheck();
    }

    // @0x14248ca70
    void Point::polar(SPtr<Instances::fl_geom::Point>& result, Value::Number len, Value::Number angle)
    {
        Value args[] = { Value(cos(angle) * len), Value(sin(angle) * len) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Point", 2, args).DoNotCheck();
    }
}}

namespace Instances { namespace fl_geom
{
    // |a - b| < tol, written out as the exe tests it (a compare and a sign flip, not fabs).
    static inline bool NearlyEqual(Value::Number a, Value::Number b, Value::Number tol)
    {
        Value::Number d = a - b;
        if (d < 0)
            d = -d;
        return d < tol;
    }

    // A new vector made straight from the instance traits; w stays 0.
    // @0x142486950
    void Vector3D::add(SPtr<Instances::fl_geom::Vector3D>& result, Instances::fl_geom::Vector3D* v)
    {
        if (v == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        InstanceTraits::fl_geom::Vector3D& itr = static_cast<InstanceTraits::fl_geom::Vector3D&>(GetInstanceTraits());
        Pickable<Instances::fl_geom::Vector3D> r = itr.MakeInstance(itr);
        r->x = v->x + x;
        r->y = v->y + y;
        r->z = v->z + z;
        result = r;
    }

    // @0x142487b50
    void Vector3D::clone(SPtr<Instances::fl_geom::Vector3D>& result)
    {
        Value args[] = { Value(x), Value(y), Value(z), Value(w) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Vector3D", 4, args).DoNotCheck();
    }

    // @0x142489060
    void Vector3D::crossProduct(SPtr<Instances::fl_geom::Vector3D>& result, Instances::fl_geom::Vector3D* v)
    {
        if (v == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        InstanceTraits::fl_geom::Vector3D& itr = static_cast<InstanceTraits::fl_geom::Vector3D&>(GetInstanceTraits());
        Pickable<Instances::fl_geom::Vector3D> r = itr.MakeInstance(itr);
        const Value::Number tx = y * v->z - z * v->y;
        const Value::Number ty = z * v->x - x * v->z;
        const Value::Number tz = x * v->y - y * v->x;
        r->x = tx;
        r->y = ty;
        r->z = tz;
        result = r;
    }

    // @0x142489270
    void Vector3D::decrementBy(const Value& result, Instances::fl_geom::Vector3D* v)
    {
        SF_UNUSED(result);
        if (v == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        x -= v->x;
        y -= v->y;
        z -= v->z;
    }

    // @0x142489910
    void Vector3D::dotProduct(Value::Number& result, Instances::fl_geom::Vector3D* a)
    {
        if (a == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        result = x * a->x + y * a->y + z * a->z;
    }

    // @0x142489ab0
    void Vector3D::equals(bool& result, Instances::fl_geom::Vector3D* toCompare, bool allFour)
    {
        if (toCompare == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        result = x == toCompare->x && y == toCompare->y && z == toCompare->z;
        if (allFour)
            result = result && w == toCompare->w;
    }

    // @0x14248a1a0
    void Vector3D::incrementBy(const Value& result, Instances::fl_geom::Vector3D* v)
    {
        SF_UNUSED(result);
        if (v == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        x += v->x;
        y += v->y;
        z += v->z;
    }

    // @0x14248ab90
    void Vector3D::lengthGet(Value::Number& result)
    {
        result = sqrt(x * x + y * y + z * z);
    }

    // @0x14248b9b0
    void Vector3D::nearEquals(bool& result, Instances::fl_geom::Vector3D* toCompare, Value::Number tolerance, bool allFour)
    {
        if (toCompare == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        result = NearlyEqual(x, toCompare->x, tolerance) && NearlyEqual(y, toCompare->y, tolerance)
            && NearlyEqual(z, toCompare->z, tolerance);
        if (allFour)
            result = result && NearlyEqual(w, toCompare->w, tolerance);
    }

    // Returns the old length.
    // @0x14248bb60
    void Vector3D::normalize(Value::Number& result)
    {
        lengthGet(result);
        x /= result;
        y /= result;
        z /= result;
    }

    // @0x14248e350
    void Vector3D::subtract(SPtr<Instances::fl_geom::Vector3D>& result, Instances::fl_geom::Vector3D* v)
    {
        if (v == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        InstanceTraits::fl_geom::Vector3D& itr = static_cast<InstanceTraits::fl_geom::Vector3D&>(GetInstanceTraits());
        Pickable<Instances::fl_geom::Vector3D> r = itr.MakeInstance(itr);
        r->x = x - v->x;
        r->y = y - v->y;
        r->z = z - v->z;
        result = r;
    }

    // "(x=1, y=2, z=3)"; w is not shown. Built as a String, unlike Point's ASString chain.
    // @0x142490150
    void Vector3D::toString(ASString& result)
    {
        VM& vm = GetVM();
        result += "(x=" + vm.AsString(Value(x)) + ", y=" + vm.AsString(Value(y)) + ", z=" + vm.AsString(Value(z)) + ")";
    }
}}

namespace Classes { namespace fl_geom
{
    // @0x142486a70
    void Vector3D::angleBetween(Value::Number& result, Instances::fl_geom::Vector3D* a, Instances::fl_geom::Vector3D* b)
    {
        const Value::Number dot = a->x * b->x + a->y * b->y + a->z * b->z;
        const Value::Number aLen = sqrt(a->x * a->x + a->y * a->y + a->z * a->z);
        const Value::Number bLen = sqrt(b->x * b->x + b->y * b->y + b->z * b->z);
        result = acos(dot / (aLen * bLen));
    }

    // @0x1424898c0
    void Vector3D::distance(Value::Number& result, Instances::fl_geom::Vector3D* pt1, Instances::fl_geom::Vector3D* pt2)
    {
        result = sqrt((pt1->x - pt2->x) * (pt1->x - pt2->x) + (pt1->y - pt2->y) * (pt1->y - pt2->y)
            + (pt1->z - pt2->z) * (pt1->z - pt2->z));
    }
}}

namespace Instances { namespace fl_geom
{
    // flash.geom.Rectangle: x/y is the top-left corner, width/height the extent.

    // @0x142487510
    void Rectangle::bottomGet(Value::Number& result)
    {
        result = y + height;
    }

    // @0x142487540
    void Rectangle::bottomRightGet(SPtr<Instances::fl_geom::Point>& result)
    {
        Value args[] = { Value(x + width), Value(y + height) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Point", 2, args).DoNotCheck();
    }

    // Moves the bottom-right corner; the top-left one stays.
    // @0x142487600
    void Rectangle::bottomRightSet(const Value& result, Instances::fl_geom::Point* value)
    {
        SF_UNUSED(result);
        if (value == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        width = value->x - x;
        height = value->y - y;
    }

    // @0x142487680
    void Rectangle::bottomSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        height = value - y;
    }

    // @0x142487a50
    void Rectangle::clone(SPtr<Instances::fl_geom::Rectangle>& result)
    {
        Value args[] = { Value(x), Value(y), Value(width), Value(height) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Rectangle", 4, args).DoNotCheck();
    }

    // Left and top edges are inside, right and bottom ones are not.
    // @0x142488c10
    void Rectangle::contains(bool& result, Value::Number px, Value::Number py)
    {
        result = px < x + width && px >= x && py < y + height && py >= y;
    }

    // @0x142488c50
    void Rectangle::containsPoint(bool& result, Instances::fl_geom::Point* point)
    {
        if (point == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        contains(result, point->x, point->y);
    }

    // A zero-sized rectangle counts as contained when its corner lies strictly below and right of ours.
    // @0x142488cf0
    void Rectangle::containsRect(bool& result, Instances::fl_geom::Rectangle* rect)
    {
        if (rect == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        if (rect->height == 0 && rect->width == 0)
        {
            if (x < rect->x && y < rect->y)
            {
                result = true;
                return;
            }
            result = false;
            return;
        }
        const Value::Number left2 = rect->x;
        const Value::Number top2 = rect->y;
        const Value::Number right2 = rect->width + left2;
        const Value::Number bottom2 = rect->height + top2;
        const Value::Number left1 = x;
        const Value::Number top1 = y;
        const Value::Number right1 = width + left1;
        const Value::Number bottom1 = height + top1;
        result = right1 >= right2 && bottom1 >= bottom2 && left1 <= left2 && top1 <= top2;
    }

    // @0x142489a10
    void Rectangle::equals(bool& result, Instances::fl_geom::Rectangle* toCompare)
    {
        if (toCompare == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        result = x == toCompare->x && y == toCompare->y && width == toCompare->width && height == toCompare->height;
    }

    // Grows by dx/dy on every side.
    // @0x14248a230
    void Rectangle::inflate(const Value& result, Value::Number dx, Value::Number dy)
    {
        SF_UNUSED(result);
        x -= dx;
        width += 2 * dx;
        y -= dy;
        height += 2 * dy;
    }

    // @0x14248a270
    void Rectangle::inflatePoint(const Value& result, Instances::fl_geom::Point* point)
    {
        SF_UNUSED(result);
        if (point == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        const Value::Number dx = point->x;
        const Value::Number dy = point->y;
        x -= dx;
        width += 2 * dx;
        y -= dy;
        height += 2 * dy;
    }

    // The overlap as a new rectangle; an empty (0,0,0,0) one when there is none.
    // @0x14248a490
    void Rectangle::intersection(SPtr<Instances::fl_geom::Rectangle>& result, Instances::fl_geom::Rectangle* toIntersect)
    {
        if (toIntersect == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        bool overlap;
        intersects(overlap, toIntersect);
        if (!overlap)
        {
            const Value::Number zero = 0.0;
            Value args[] = { Value(zero), Value(zero), Value(zero), Value(zero) };
            return GetVM().ConstructBuiltinObject(result, "flash.geom.Rectangle", 4, args).DoNotCheck();
        }
        Value::Number left = toIntersect->x;
        Value::Number top = toIntersect->y;
        Value::Number right = left + toIntersect->width;
        Value::Number bottom = top + toIntersect->height;
        left = x > left ? x : left;
        right = x + width > right ? right : x + width;
        top = y > top ? y : top;
        bottom = y + height > bottom ? bottom : y + height;
        Value args[] = { Value(left), Value(top), Value(right - left), Value(bottom - top) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Rectangle", 4, args).DoNotCheck();
    }

    // Empty rectangles never intersect; touching edges do. Called, not inlined, by intersection in the exe.
    // @0x14248a6c0
    __declspec(noinline) void Rectangle::intersects(bool& result, Instances::fl_geom::Rectangle* toIntersect)
    {
        if (toIntersect == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        bool empty;
        toIntersect->isEmpty(empty);
        if (empty)
        {
            result = false;
            return;
        }
        isEmpty(empty);
        if (empty)
        {
            result = false;
            return;
        }
        const Value::Number bottom = y + height;
        const Value::Number right = x + width;
        const Value::Number bottom2 = toIntersect->y + toIntersect->height;
        const Value::Number right2 = toIntersect->x + toIntersect->width;
        result = bottom >= toIntersect->y && bottom2 >= y && right2 >= x && right >= toIntersect->x;
    }

    // @0x14248ab10
    void Rectangle::isEmpty(bool& result)
    {
        result = width <= 0 || height <= 0;
    }

    // @0x14248ab30
    void Rectangle::leftGet(Value::Number& result)
    {
        result = x;
    }

    // Moves the left edge; the right one stays.
    // @0x14248ab40
    void Rectangle::leftSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        width += x - value;
        x = value;
    }

    // @0x14248bc00
    void Rectangle::offset(const Value& result, Value::Number dx, Value::Number dy)
    {
        SF_UNUSED(result);
        x += dx;
        y += dy;
    }

    // @0x14248bc20
    void Rectangle::offsetPoint(const Value& result, Instances::fl_geom::Point* point)
    {
        SF_UNUSED(result);
        if (point == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        x += point->x;
        y += point->y;
    }

    // @0x14248dfb0
    void Rectangle::rightGet(Value::Number& result)
    {
        result = x + width;
    }

    // @0x14248dfc0
    void Rectangle::rightSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        width = value - x;
    }

    // A no-op in this build.
    // @0x14248e0f0
    void Rectangle::setEmpty(const Value& result)
    {
        SF_UNUSED(result);
    }

    // @0x14248e120
    void Rectangle::sizeGet(SPtr<Instances::fl_geom::Point>& result)
    {
        Value args[] = { Value(width), Value(height) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Point", 2, args).DoNotCheck();
    }

    // @0x14248e1d0
    void Rectangle::sizeSet(const Value& result, Instances::fl_geom::Point* value)
    {
        SF_UNUSED(result);
        if (value == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        width = value->x;
        height = value->y;
    }

    // "(x=0, y=0, w=10, h=10)"
    // @0x14248fc30
    void Rectangle::toString(ASString& result)
    {
        result += GetVM().GetStringManager().CreateConstString("(x=") + GetVM().AsString(Value(x))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("y=")
            + GetVM().AsString(Value(y))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("w=")
            + GetVM().AsString(Value(width))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("h=")
            + GetVM().AsString(Value(height)) + GetVM().GetStringManager().CreateConstString(")");
    }

    // @0x1424904d0
    void Rectangle::topGet(Value::Number& result)
    {
        result = y;
    }

    // @0x142490500
    void Rectangle::topLeftGet(SPtr<Instances::fl_geom::Point>& result)
    {
        Value args[] = { Value(x), Value(y) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Point", 2, args).DoNotCheck();
    }

    // Moves the top-left corner; the bottom-right one stays.
    // @0x1424905b0
    void Rectangle::topLeftSet(const Value& result, Instances::fl_geom::Point* value)
    {
        SF_UNUSED(result);
        if (value == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        width += x - value->x;
        height += y - value->y;
        x = value->x;
        y = value->y;
    }

    // Moves the top edge; the bottom one stays.
    // @0x142490640
    void Rectangle::topSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        height += y - value;
        y = value;
    }

    // The bounding box of both; an empty side yields a copy of the other.
    // MS2-FUNCTIONAL: the exe materialises the inlined toUnion->isEmpty() as a bool in al and lays the copy-of-this block out inline
    // @0x142490fb0
    void Rectangle::union_(SPtr<Instances::fl_geom::Rectangle>& result, Instances::fl_geom::Rectangle* toUnion)
    {
        if (toUnion == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        bool otherEmpty;
        toUnion->isEmpty(otherEmpty);
        if (otherEmpty)
        {
            Value args[] = { Value(x), Value(y), Value(width), Value(height) };
            return GetVM().ConstructBuiltinObject(result, "flash.geom.Rectangle", 4, args).DoNotCheck();
        }
        bool empty;
        isEmpty(empty);
        if (empty)
        {
            Value args[] = { Value(toUnion->x), Value(toUnion->y), Value(toUnion->width), Value(toUnion->height) };
            return GetVM().ConstructBuiltinObject(result, "flash.geom.Rectangle", 4, args).DoNotCheck();
        }
        const Value::Number left1 = x;
        const Value::Number top1 = y;
        const Value::Number right1 = x + width;
        const Value::Number bottom1 = y + height;
        const Value::Number left2 = toUnion->x;
        const Value::Number top2 = toUnion->y;
        const Value::Number right2 = left2 + toUnion->width;
        const Value::Number bottom2 = top2 + toUnion->height;
        Value::Number left, top, right, bottom;
        left = left1 > left2 ? left2 : left1;
        right = right1 > right2 ? right1 : right2;
        top = top1 > top2 ? top2 : top1;
        bottom = bottom1 > bottom2 ? bottom1 : bottom2;
        Value args[] = { Value(left), Value(top), Value(right - left), Value(bottom - top) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Rectangle", 4, args).DoNotCheck();
    }

    // Vector3D accessors and in-place operations.

    // @0x14248abd0
    void Vector3D::lengthSquaredGet(Value::Number& result)
    {
        result = x * x + y * y + z * z;
    }

    // @0x14248baa0
    void Vector3D::negate(const Value& result)
    {
        SF_UNUSED(result);
        x = -x;
        y = -y;
        z = -z;
    }

    // Divides by w (perspective divide).
    // @0x14248d850
    void Vector3D::project(const Value& result)
    {
        SF_UNUSED(result);
        x /= w;
        y /= w;
        z /= w;
    }

    // @0x14248e0d0
    void Vector3D::scaleBy(const Value& result, Value::Number s)
    {
        SF_UNUSED(result);
        x *= s;
        y *= s;
        z *= s;
    }

    // @0x142491300
    void Vector3D::wGet(Value::Number& result) { result = w; }
    // @0x142491310
    void Vector3D::wSet(const Value& result, Value::Number value) { SF_UNUSED(result); w = value; }
    // @0x142491320
    void Vector3D::xGet(Value::Number& result) { result = x; }
    // @0x142491330
    void Vector3D::xSet(const Value& result, Value::Number value) { SF_UNUSED(result); x = value; }
    // @0x142491340
    void Vector3D::yGet(Value::Number& result) { result = y; }
    // @0x142491350
    void Vector3D::ySet(const Value& result, Value::Number value) { SF_UNUSED(result); y = value; }
    // @0x142491360
    void Vector3D::zGet(Value::Number& result) { result = z; }
    // @0x142491370
    void Vector3D::zSet(const Value& result, Value::Number value) { SF_UNUSED(result); z = value; }

    // ColorTransform: the RGB of the offsets, 0xRRGGBB.
    // @0x142487c50
    void ColorTransform::colorGet(UInt32& result)
    {
        result = ((UInt32)(UInt8)(int)redOffset << 16) | ((UInt32)(UInt8)(int)greenOffset << 8) | (UInt8)(int)blueOffset;
    }

    // Sets the offsets from 0xRRGGBB and zeroes the colour multipliers (alpha is kept).
    // @0x142487c80
    void ColorTransform::colorSet(const Value& result, UInt32 value)
    {
        SF_UNUSED(result);
        redMultiplier = greenMultiplier = blueMultiplier = 0;
        redOffset = (float)((value >> 16) & 0xff);
        greenOffset = (float)((value >> 8) & 0xff);
        blueOffset = (float)(value & 0xff);
    }

    // Applies second after this one (no null check in this build).
    // @0x142488220
    void ColorTransform::concat(const Value& result, Instances::fl_geom::ColorTransform* second)
    {
        SF_UNUSED(result);
        redOffset = redMultiplier * second->redOffset + redOffset;
        blueOffset = blueMultiplier * second->blueOffset + blueOffset;
        greenOffset = greenMultiplier * second->greenOffset + greenOffset;
        alphaOffset = alphaMultiplier * second->alphaOffset + alphaOffset;
        redMultiplier *= second->redMultiplier;
        greenMultiplier *= second->greenMultiplier;
        blueMultiplier *= second->blueMultiplier;
        alphaMultiplier *= second->alphaMultiplier;
    }

    // Matrix: in-place operations.

    // @0x14248a170
    void Matrix::identity(const Value& result)
    {
        SF_UNUSED(result);
        a = 1; b = 0; c = 0; d = 1; tx = 0; ty = 0;
    }

    // @0x14248e080
    void Matrix::scale(const Value& result, Value::Number sx, Value::Number sy)
    {
        SF_UNUSED(result);
        Render::Matrix2x4<double> m = GetMatrix();
        m.AppendScaling(sx, sy);
        SetMatrix(m);
    }

    // @0x1424852c0
    Render::Matrix2x4<double> Matrix::GetMatrix() const
    {
        Render::Matrix2x4<double> m(Render::Matrix2x4<double>::NoInit);
        m.M[0][2] = 0;
        m.M[1][2] = 0;
        m.Sx() = a; m.Shy() = b; m.Shx() = c; m.Sy() = d; m.Tx() = tx; m.Ty() = ty;
        return m;
    }

    // @0x142485300
    Render::Matrix2F Matrix::GetMatrixF() const
    {
        Render::Matrix2F m(Render::Matrix2F::NoInit);
        m.M[0][2] = 0;
        m.M[1][2] = 0;
        m.Sx() = (float)a; m.Shy() = (float)b; m.Shx() = (float)c; m.Sy() = (float)d; m.Tx() = (float)tx; m.Ty() = (float)ty;
        return m;
    }

    // @0x142490dd0
    void Matrix::translate(const Value& result, Value::Number dx, Value::Number dy)
    {
        SF_UNUSED(result);
        tx += dx;
        ty += dy;
    }

    // PerspectiveProjection: plain getters.

    // @0x142489b60
    void PerspectiveProjection::fieldOfViewGet(Value::Number& result)
    {
        result = fieldOfView;
    }

    // @0x142489ba0
    void PerspectiveProjection::focalLengthGet(Value::Number& result)
    {
        result = focalLength;
    }
}}

namespace Instances { namespace fl_geom
{
    // flash.geom.Matrix: the operations go through the renderer's 2x4 matrix.

    // @0x142487860
    void Matrix::clone(SPtr<Instances::fl_geom::Matrix>& result)
    {
        Value args[] = { Value(a), Value(b), Value(c), Value(d), Value(tx), Value(ty) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Matrix", 6, args).DoNotCheck();
    }

    // this = this followed by m.
    // MS2-FUNCTIONAL: same inlined append math, the exe schedules the loads of m before this
    // @0x1424882b0

    void Matrix::concat(const Value& result, Instances::fl_geom::Matrix* m)
    {
        SF_UNUSED(result);
        if (m == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        Render::Matrix2x4<double> m2d = GetMatrix();
        m2d.Append(m->GetMatrix());

        SetMatrix(m2d);




    }

    // Rotation, then scaling, then translation, applied to the current matrix.
    // @0x142488df0
    void Matrix::createBox(const Value& result, Value::Number scaleX, Value::Number scaleY, Value::Number rotation,
                           Value::Number dx, Value::Number dy)
    {
        SF_UNUSED(result);
        Render::Matrix2x4<double> m = GetMatrix();
        m.AppendRotation(rotation);
        m.AppendScaling(scaleX, scaleY);
        m.AppendTranslation(dx, dy);
        SetMatrix(m);
    }

    // A gradient box: the unit gradient square (1638.4 twips) scaled to width x height, centred on the box. Computed in
    // float, from the identity.
    // @0x142488ef0
    void Matrix::createGradientBox(const Value& result, Value::Number width, Value::Number height, Value::Number rotation,
                                   Value::Number dx, Value::Number dy)
    {
        SF_UNUSED(result);
        Render::Matrix2x4<double> m;
        float w = float(width);
        float h = float(height);
        const float r = float(rotation);
        const float cx = w * 0.5f + float(dx);
        const float cy = h * 0.5f + float(dy);
        w *= 1.0f / 1638.4f;
        h *= 1.0f / 1638.4f;
        m.AppendRotation(r);
        m.AppendScaling(w, h);
        m.AppendTranslation(cx, cy);
        SetMatrix(m);
    }

    // The point transformed without the translation.
    // @0x142489320
    void Matrix::deltaTransformPoint(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point* point)
    {
        if (point == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        const Value::Number px = point->x;
        const Value::Number py = point->y;
        Value args[] = { Value(a * px + c * py), Value(b * px + d * py) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Point", 2, args).DoNotCheck();
    }

    // @0x14248a9c0
    void Matrix::invert(const Value& result)
    {
        SF_UNUSED(result);
        Render::Matrix2x4<double> m(a, c, tx, b, d, ty);
        m.Invert();
        SetMatrix(m);
    }

    // @0x14248dfd0
    void Matrix::rotate(const Value& result, Value::Number angle)
    {
        SF_UNUSED(result);
        Render::Matrix2x4<double> m(a, c, tx, b, d, ty);
        m.AppendRotation(angle);
        SetMatrix(m);
    }

    // "(a=1, b=0, c=0, d=1, tx=0, ty=0)"
    // @0x14248f1f0
    void Matrix::toString(ASString& result)
    {
        result += GetVM().GetStringManager().CreateConstString("(a=") + GetVM().AsString(Value(a))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("b=")
            + GetVM().AsString(Value(b))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("c=")
            + GetVM().AsString(Value(c))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("d=")
            + GetVM().AsString(Value(d))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("tx=")
            + GetVM().AsString(Value(tx))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("ty=")
            + GetVM().AsString(Value(ty)) + GetVM().GetStringManager().CreateConstString(")");
    }

    // @0x142490680
    void Matrix::transformPoint(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point* point)
    {
        if (point == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        const Value::Number px = point->x;
        const Value::Number py = point->y;
        Value args[] = { Value(a * px + c * py + tx), Value(b * px + d * py + ty) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Point", 2, args).DoNotCheck();
    }

    // "(redMultiplier=1, greenMultiplier=1, ..., alphaOffset=0)"
    // @0x14248e760
    void ColorTransform::toString(ASString& result)
    {
        result += GetVM().GetStringManager().CreateConstString("(redMultiplier=") + GetVM().AsString(Value(redMultiplier))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("greenMultiplier=")
            + GetVM().AsString(Value(greenMultiplier))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("blueMultiplier=")
            + GetVM().AsString(Value(blueMultiplier))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("alphaMultiplier=")
            + GetVM().AsString(Value(alphaMultiplier))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("redOffset=")
            + GetVM().AsString(Value(redOffset))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("greenOffset=")
            + GetVM().AsString(Value(greenOffset))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("blueOffset=")
            + GetVM().AsString(Value(blueOffset))
            + GetVM().GetStringManager().CreateConstString(", ") + GetVM().GetStringManager().CreateConstString("alphaOffset=")
            + GetVM().AsString(Value(alphaOffset)) + GetVM().GetStringManager().CreateConstString(")");
    }
}}

}}} // namespace Scaleform::GFx::AS3

// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424914e0
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491540
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424915a0
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491600
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491660
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424916d0
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$05VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424917d0
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491880
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$07VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424919d0
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491a40
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$09_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491b40
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491ba0
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0M@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491c00
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491c60
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0O@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491cc0
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0P@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491d30
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BA@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491e30
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BB@$$CBVValue@456@PEAVArray@fl@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491ee0
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BC@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491f20
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BD@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491f90
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BE@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142492090
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BF@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424920f0
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BG@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142492150
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BH@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424921c0
// MS2-PIN: ?Func@?$ThunkFunc1@VURLVariables@fl_net@Instances@AS3@GFx@Scaleform@@$0A@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424927f0
// MS2-PIN: ?Func@?$ThunkFunc0@VURLVariables@fl_net@Instances@AS3@GFx@Scaleform@@$00VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424928f0
// MS2-PIN: ?Func@?$ThunkFunc0@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142492ce0
// MS2-PIN: ?Func@?$ThunkFunc1@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142492d90
// MS2-PIN: ?Func@?$ThunkFunc0@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142492ee0
// MS2-PIN: ?Func@?$ThunkFunc1@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142492f90
// MS2-PIN: ?Func@?$ThunkFunc1@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493000
// MS2-PIN: ?Func@?$ThunkFunc0@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$04K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493090
// MS2-PIN: ?Func@?$ThunkFunc1@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424930f0
// MS2-PIN: ?Func@?$ThunkFunc0@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$06K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493160
// MS2-PIN: ?Func@?$ThunkFunc0@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424931c0
// MS2-PIN: ?Func@?$ThunkFunc0@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424931e0
// MS2-PIN: ?Func@?$ThunkFunc2@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$09$$CBVValue@456@PEAVNetConnection@23456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493200
// MS2-PIN: ?Func@?$ThunkFunc1@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$0L@VASString@56@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493340
// MS2-PIN: ?Func@?$ThunkFunc2@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424933f0
// MS2-PIN: ?Func@?$ThunkFunc1@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493410
// MS2-PIN: ?Func@?$ThunkFunc2@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$0O@$$CBVValue@456@AEBVASString@56@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493510
// MS2-PIN: ?Func@?$ThunkFunc3@VSharedObject@fl_net@Classes@AS3@GFx@Scaleform@@$0A@V?$SPtr@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@@456@AEBVASString@56@AEBV856@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493b70
// MS2-PIN: ?Func@?$ThunkFunc4@VSharedObject@fl_net@Classes@AS3@GFx@Scaleform@@$00V?$SPtr@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@@456@AEBVASString@56@AEBV856@AEBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493ce0
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494270
// MS2-PIN: ?Func@?$ThunkFunc1@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494320
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494470
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424944d0
// MS2-PIN: ?Func@?$ThunkFunc1@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494540
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$04K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424945b0
// MS2-PIN: ?Func@?$ThunkFunc1@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494610
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$06VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494680
// MS2-PIN: ?Func@?$ThunkFunc1@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424946f0
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$08VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424947f0
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$09_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494860
// MS2-PIN: ?Func@?$ThunkFunc3@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@AEBVASString@56@_NAEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424948c0
// MS2-PIN: ?Func@?$ThunkFunc2@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494ad0
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494af0
// MS2-PIN: ?Func@?$ThunkFunc2@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$0O@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494b10
// MS2-PIN: ?Func@?$ThunkFunc5@VURLLoader@fl_net@Instances@AS3@GFx@Scaleform@@$0A@$$CBVValue@456@AEBVASString@56@AEBV7456@_NJ_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142495170
// MS2-PIN: ?Func@?$ThunkFunc0@VURLLoader@fl_net@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142495410
// MS2-PIN: ?Func@?$ThunkFunc1@VURLLoader@fl_net@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@PEAVURLRequest@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142495430
// MS2-PIN: ?AppendRotation@?$Matrix2x4@N@Render@Scaleform@@QEAAAEAV123@N@Z 0x142484140
// MS2-PIN: ?Append_NonOpt@?$Matrix2x4@N@Render@Scaleform@@QEAAAEAV123@AEBV123@@Z 0x142484280
