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
#include "ms2/scaleform/include/gfx/gfx_displayobject.h"
#include "ms2/scaleform/include/gfx/gfx_displayobjcontainer.h"
#include "ms2/scaleform/include/gfx/gfx_rendertree.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"

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
// Instances::fl_net::SharedObject::setProperty argument 1 default
template <> struct ThunkMethodDefault<Instances::fl_net::SharedObject, 14, 1, const Value&>
{
    SF_INLINE static Value Get(StringManager&) { return Value::GetNull(); }
};
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

// Matrix3D::transpose calls the double 4x4 transpose out of line.
namespace Scaleform { namespace Render
{
    // @0x142486790
    template <> __declspec(noinline) void Matrix4x4<double>::Transpose()
    {
        Matrix4x4<double> t(NoInit);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                t.M[j][i] = M[i][j];
        *this = t;
    }
}}

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
    inline ColorTransform::ColorTransform(InstanceTraits::Traits& t, InlineCtor)
        : Instances::fl::Object(t)
    {
        alphaMultiplier = blueMultiplier = greenMultiplier = redMultiplier = 1.0;
        alphaOffset = blueOffset = greenOffset = redOffset = 0.0;
    }

    inline Matrix3D::Matrix3D(InstanceTraits::Traits& t, InlineCtor)
        : Instances::fl::Object(t)
        , pDispObj(0)
    {
    }

    inline Matrix::Matrix(InstanceTraits::Traits& t, InlineCtor)
        : Instances::fl::Object(t)
        , a(0), b(0), c(0), d(0), tx(0), ty(0)
    {
    }

    inline PerspectiveProjection::PerspectiveProjection(InstanceTraits::Traits& t, InlineCtor)
        : Instances::fl::Object(t)
        , projectionCenter(Render::PointF::NoInit), fieldOfView(55), pDispObj(0)
    {
        projectionCenter.x = 250.f;
        projectionCenter.y = 250.f;
        focalLength = 250.0 / tan(SF_DEGTORAD(fieldOfView) / 2);
    }

    inline Point::Point(InstanceTraits::Traits& t, InlineCtor)
        : Instances::fl::Object(t)
        , x(0), y(0)
    {
    }

    inline Rectangle::Rectangle(InstanceTraits::Traits& t, InlineCtor)
        : Instances::fl::Object(t)
        , height(0), width(0), x(0), y(0)
    {
    }

    inline Transform::Transform(InstanceTraits::Traits& t, InlineCtor)
        : Instances::fl::Object(t)
        , pDispObj(0)
    {
    }

    inline Vector3D::Vector3D(InstanceTraits::Traits& t, InlineCtor)
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
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t, Instances::fl_geom::InlineCtor()));
    }

    // @0x142485540
    Pickable<Matrix3D::InstanceType> Matrix3D::MakeInstance(Matrix3D& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t, Instances::fl_geom::InlineCtor()));
    }

    // @0x1424855f0
    Pickable<Matrix::InstanceType> Matrix::MakeInstance(Matrix& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t, Instances::fl_geom::InlineCtor()));
    }

    // @0x142485680
    Pickable<PerspectiveProjection::InstanceType> PerspectiveProjection::MakeInstance(PerspectiveProjection& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t, Instances::fl_geom::InlineCtor()));
    }

    // @0x142485730
    Pickable<Point::InstanceType> Point::MakeInstance(Point& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t, Instances::fl_geom::InlineCtor()));
    }

    // @0x1424857b0
    Pickable<Rectangle::InstanceType> Rectangle::MakeInstance(Rectangle& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t, Instances::fl_geom::InlineCtor()));
    }

    // @0x142485830
    Pickable<Transform::InstanceType> Transform::MakeInstance(Transform& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t, Instances::fl_geom::InlineCtor()));
    }

    // @0x1424858b0
    Pickable<Vector3D::InstanceType> Vector3D::MakeInstance(Vector3D& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t, Instances::fl_geom::InlineCtor()));
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
    __declspec(noinline) void Rectangle::bottomRightGet(SPtr<Instances::fl_geom::Point>& result)
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
    __declspec(noinline) void Rectangle::sizeGet(SPtr<Instances::fl_geom::Point>& result)
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
    __declspec(noinline) void Rectangle::topLeftGet(SPtr<Instances::fl_geom::Point>& result)
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
    __declspec(noinline) void Matrix::deltaTransformPoint(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point* point)
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
    __declspec(noinline) void Matrix::transformPoint(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point* point)
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

namespace Instances { namespace fl_geom
{
    // @0x142489b70
    void PerspectiveProjection::fieldOfViewSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        fieldOfView = (float)value;
        if (pDispObj)
            pDispObj->SetFOV(fieldOfView);
    }

    // @0x142489bb0
    void PerspectiveProjection::focalLengthSet(const Value& result, Value::Number value)
    {
        SF_UNUSED(result);
        focalLength = (float)value;
        if (pDispObj)
            pDispObj->SetFocalLength(PixelsToTwips(focalLength));
    }

    // @0x14248d9f0
    void PerspectiveProjection::projectionCenterSet(const Value& result, Instances::fl_geom::Point* value)
    {
        SF_UNUSED(result);
        projectionCenter.x = (float)value->x;
        projectionCenter.y = (float)value->y;
        if (pDispObj)
            pDispObj->SetProjectionCenter(PixelsToTwips(projectionCenter));
    }
}}

// The SPtr-returning forms of the natives, for C++ callers.
namespace Instances { namespace fl_geom
{
    // @0x142487520
    SPtr<Instances::fl_geom::Point> Rectangle::bottomRightGet()
    {
        SPtr<Instances::fl_geom::Point> result;
        bottomRightGet(result);
        return result;
    }

    // @0x142489300
    SPtr<Instances::fl_geom::Point> Matrix::deltaTransformPoint(Instances::fl_geom::Point* point)
    {
        SPtr<Instances::fl_geom::Point> result;
        deltaTransformPoint(result, point);
        return result;
    }

    // @0x14248e100
    SPtr<Instances::fl_geom::Point> Rectangle::sizeGet()
    {
        SPtr<Instances::fl_geom::Point> result;
        sizeGet(result);
        return result;
    }

    // @0x1424904e0
    SPtr<Instances::fl_geom::Point> Rectangle::topLeftGet()
    {
        SPtr<Instances::fl_geom::Point> result;
        topLeftGet(result);
        return result;
    }

    // @0x142490660
    SPtr<Instances::fl_geom::Point> Matrix::transformPoint(Instances::fl_geom::Point* point)
    {
        SPtr<Instances::fl_geom::Point> result;
        transformPoint(result, point);
        return result;
    }
}}

namespace Instances { namespace fl_geom
{
    // A new Point each time, made through the movie VM's Point class.
    // @0x14248d8a0
    __declspec(noinline) void PerspectiveProjection::projectionCenterGet(SPtr<Instances::fl_geom::Point>& result)
    {
        Value args[] = { Value(projectionCenter.x), Value(projectionCenter.y) };
        Value r;
        static_cast<ASVM&>(GetVM()).PointClass->Construct(r, 2, args, true);
        result = static_cast<Instances::fl_geom::Point*>(r.GetObject());
    }

    // @0x14248d880
    SPtr<Instances::fl_geom::Point> PerspectiveProjection::projectionCenterGet()
    {
        SPtr<Instances::fl_geom::Point> result;
        projectionCenterGet(result);
        return result;
    }

    // The projection as a Matrix3D: focal length f on the x/y diagonal, z copied into w. Without an explicit focal
    // length f comes from the field of view over the stage width (500 pixels when not on a stage).
    // MS2-FUNCTIONAL: the exe assembles the matrix rows in xmm registers (shufps) and copies them; ours stores directly
    // @0x14248e490
    __declspec(noinline) void PerspectiveProjection::toMatrix3D(SPtr<Instances::fl_geom::Matrix3D>& result)
    {
        float width;
        if (pDispObj)
        {
            const Render::RectF& r = pDispObj->GetMovieImpl()->GetVisibleFrameRectInTwips();
            width = TwipsToPixels((float)fabs(r.x2 - r.x1));
        }
        else
            width = 500.0f;
        float f;
        if (focalLength == 0)
            f = (width * 0.5f) / tanf((float)SF_DEGTORAD(fieldOfView) * 0.5f);
        else
            f = (float)focalLength;
        Render::Matrix4F m(f, 0, 0, 0,
                           0, f, 0, 0,
                           0, 0, 1, 0,
                           0, 0, 1, 0);
        Value argv[16];
        for (int i = 0; i < 16; i++)
            argv[i].SetNumber((Double)m[i]);
        GetVM().ConstructBuiltinObject(result, "flash.geom.Matrix3D", 16, argv);
    }

    // @0x14248e470
    SPtr<Instances::fl_geom::Matrix3D> PerspectiveProjection::toMatrix3D()
    {
        SPtr<Instances::fl_geom::Matrix3D> result;
        toMatrix3D(result);
        return result;
    }
}}

namespace ClassTraits { namespace fl_geom
{
    // The display Cxform of a ColorTransform: multipliers as they are, offsets scaled to 0..1. The identity for null.
    // @0x142484540
    Render::Cxform ColorTransform::GetCxformFromColorTransform(Instances::fl_geom::ColorTransform* ct)
    {
        Render::Cxform cx;
        if (ct)
        {
            cx.M[0][0] = (float)ct->redMultiplier;
            cx.M[0][1] = (float)ct->greenMultiplier;
            cx.M[0][2] = (float)ct->blueMultiplier;
            cx.M[0][3] = (float)ct->alphaMultiplier;
            cx.M[1][0] = (float)ct->redOffset;
            cx.M[1][1] = (float)ct->greenOffset;
            cx.M[1][2] = (float)ct->blueOffset;
            cx.M[1][3] = (float)ct->alphaOffset;
            cx.Normalize();
        }
        return cx;
    }
}}

// flash.geom.Transform: views onto the transform of the display object it was taken from.
namespace Instances { namespace fl_geom
{
    // @0x142487d00
    __declspec(noinline) void Transform::colorTransformGet(SPtr<Instances::fl_geom::ColorTransform>& result)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        SPtr<ColorTransform> ct;
        Value argv[8];
        const Render::Cxform& cx = pDispObj->GetCxform();
        argv[0].SetNumber(cx.M[0][0]);
        argv[1].SetNumber(cx.M[0][1]);
        argv[2].SetNumber(cx.M[0][2]);
        argv[3].SetNumber(cx.M[0][3]);
        argv[4].SetNumber(cx.M[1][0] * 255);
        argv[5].SetNumber(cx.M[1][1] * 255);
        argv[6].SetNumber(cx.M[1][2] * 255);
        argv[7].SetNumber(cx.M[1][3] * 255);
        asvm.ConstructInstance(ct, asvm.ColorTransformClass, 8, argv);
        result = ct;
    }

    // @0x142487ce0
    SPtr<Instances::fl_geom::ColorTransform> Transform::colorTransformGet()
    {
        SPtr<Instances::fl_geom::ColorTransform> result;
        colorTransformGet(result);
        return result;
    }

    // @0x142488100
    void Transform::colorTransformSet(const Value& result, Instances::fl_geom::ColorTransform* value)
    {
        SF_UNUSED(result);
        if (pDispObj)
        {
            pDispObj->SetCxform(ClassTraits::fl_geom::ColorTransform::GetCxformFromColorTransform(value));
            pDispObj->SetAcceptAnimMoves(false);
        }
    }

    // The color transforms of the object and all its parents, combined.
    // @0x142488440
    __declspec(noinline) void Transform::concatenatedColorTransformGet(SPtr<Instances::fl_geom::ColorTransform>& result)
    {
        SPtr<ColorTransform> ct;
        Render::Cxform cx;
        Value argv[8];
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        for (GFx::DisplayObject* obj = pDispObj; obj != NULL; obj = obj->GetParent())
            cx.Append(obj->GetCxform());
        argv[0].SetNumber(cx.M[0][0]);
        argv[1].SetNumber(cx.M[0][1]);
        argv[2].SetNumber(cx.M[0][2]);
        argv[3].SetNumber(cx.M[0][3]);
        argv[4].SetNumber(cx.M[1][0] * 255);
        argv[5].SetNumber(cx.M[1][1] * 255);
        argv[6].SetNumber(cx.M[1][2] * 255);
        argv[7].SetNumber(cx.M[1][3] * 255);
        asvm.ConstructInstance(ct, asvm.ColorTransformClass, 8, argv);
        result = ct;
    }

    // @0x142488420
    SPtr<Instances::fl_geom::ColorTransform> Transform::concatenatedColorTransformGet()
    {
        SPtr<Instances::fl_geom::ColorTransform> result;
        concatenatedColorTransformGet(result);
        return result;
    }

    // The matrices of the object and all its parents, combined; translation in pixels.
    // @0x142488880
    __declspec(noinline) void Transform::concatenatedMatrixGet(SPtr<Instances::fl_geom::Matrix>& result)
    {
        SPtr<Matrix> pm;
        GFx::DisplayObjectBase::Matrix m;
        Value argv[6];
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        for (GFx::DisplayObject* obj = pDispObj; obj != NULL; obj = obj->GetParent())
            m.Append(obj->GetMatrix());
        argv[0].SetNumber(m.Sx());
        argv[1].SetNumber(m.Shy());
        argv[2].SetNumber(m.Shx());
        argv[3].SetNumber(m.Sy());
        argv[4].SetNumber(TwipsToPixels(m.Tx()));
        argv[5].SetNumber(TwipsToPixels(m.Ty()));
        asvm.ConstructInstance(pm, asvm.MatrixClass, 6, argv);
        result = pm;
    }

    // @0x142488860
    SPtr<Instances::fl_geom::Matrix> Transform::concatenatedMatrixGet()
    {
        SPtr<Instances::fl_geom::Matrix> result;
        concatenatedMatrixGet(result);
        return result;
    }

    // @0x14248b450
    __declspec(noinline) void Transform::matrixGet(SPtr<Instances::fl_geom::Matrix>& result)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        SPtr<Matrix> pm;
        Value argv[6];
        GFx::DisplayObjectBase::Matrix m = pDispObj->GetMatrix();
        argv[0].SetNumber(m.Sx());
        argv[1].SetNumber(m.Shy());
        argv[2].SetNumber(m.Shx());
        argv[3].SetNumber(m.Sy());
        argv[4].SetNumber(TwipsToPixels(m.Tx()));
        argv[5].SetNumber(TwipsToPixels(m.Ty()));
        asvm.ConstructInstance(pm, asvm.MatrixClass, 6, argv);
        result = pm;
    }

    // @0x14248b430
    SPtr<Instances::fl_geom::Matrix> Transform::matrixGet()
    {
        SPtr<Instances::fl_geom::Matrix> result;
        matrixGet(result);
        return result;
    }

    // Sets the object's matrix (translation given in pixels) and keeps its x/y/rotation/scale properties in step.
    // @0x14248b7c0
    void Transform::matrixSet(const Value& result, Instances::fl_geom::Matrix* value)
    {
        SF_UNUSED(result);
        if (pDispObj)
        {
            if (value)
            {
                GFx::DisplayObjectBase::Matrix m;
                const float a = (float)value->a;
                const float b = (float)value->b;
                const float c = (float)value->c;
                const float d = (float)value->d;
                const float tx = PixelsToTwips((float)value->tx);
                const float ty = PixelsToTwips((float)value->ty);
                m.SetMatrix(a, c, tx, b, d, ty);
                pDispObj->SetMatrix(m);

                GFx::DisplayObjectBase::GeomDataType geom;
                pDispObj->GetGeomData(geom);
                geom.X = (int)m.Tx();
                geom.Y = (int)m.Ty();
                geom.Rotation = m.GetRotationDouble() * 180 / SF_MATH_PI;
                geom.XScale = m.GetXScaleDouble() * 100;
                geom.YScale = m.GetYScaleDouble() * 100;
                pDispObj->SetGeomData(geom);
            }
            pDispObj->SetAcceptAnimMoves(false);
        }
    }

    // The bounds in the parent's space, rounded to whole pixels.
    // @0x14248c270
    __declspec(noinline) void Transform::pixelBoundsGet(SPtr<Instances::fl_geom::Rectangle>& result)
    {
        if (pDispObj)
        {
            ASVM& asvm = static_cast<ASVM&>(GetVM());
            SPtr<Rectangle> pr;
            Value argv[4];
            Render::RectF bounds = pDispObj->GetBounds(pDispObj->GetMatrix());
            argv[0].SetNumber(Alg::IRound(TwipsToPixels(bounds.TopLeft().x)));
            argv[1].SetNumber(Alg::IRound(TwipsToPixels(bounds.TopLeft().y)));
            argv[2].SetNumber(Alg::IRound(TwipsToPixels(bounds.Width())));
            argv[3].SetNumber(Alg::IRound(TwipsToPixels(bounds.Height())));
            asvm.ConstructInstance(pr, asvm.RectangleClass, 4, argv);
            result = pr;
        }
    }

    // @0x14248c250
    SPtr<Instances::fl_geom::Rectangle> Transform::pixelBoundsGet()
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        pixelBoundsGet(result);
        return result;
    }
}}

namespace Instances { namespace fl_geom
{
    // The focal length that shows a stage stageWidth pixels wide at fieldOfView.
    // @0x142484350
    Value::Number PerspectiveProjection::CalculateFocalLength(float stageWidth)
    {
        return (stageWidth * 0.5f) / tan(fieldOfView * 0.5 * (SF_MATH_PI / 180));
    }

    // A PerspectiveProjection bound to the object, when it has perspective data. On the root with no explicit centre,
    // the centre is the middle of the stage and the focal length follows the stage width.
    // MS2-FUNCTIONAL: the exe reloads pDispObj for the root test where this build reuses the null-check load (register allocation)
    // @0x14248bcc0
    __declspec(noinline) void Transform::perspectiveProjectionGet(SPtr<Instances::fl_geom::PerspectiveProjection>& result)
    {
        if (pDispObj && pDispObj->GetPerspectiveDataPtr())
        {
            ASVM& asvm = static_cast<ASVM&>(GetVM());
            SPtr<PerspectiveProjection> pp;
            Value argv[4];
            GFx::DisplayObject* obj = pDispObj;
            const bool isRoot = (asvm.GetMovieRoot()->GetRootMovie418() == obj);
            argv[0].SetNumber(obj->GetFOV());
            argv[1].SetNumber(TwipsToPixels(pDispObj->GetFocalLength()));
            PointF ctr = pDispObj->GetParent() ? pDispObj->GetParent()->GlobalToLocal(pDispObj->GetProjectionCenter())
                                               : pDispObj->GetProjectionCenter();
            if (isRoot && ctr.x == 0 && ctr.y == 0)
                ctr = asvm.GetMovieImpl()->GetVisibleFrameRectInTwips().Center();
            argv[2].SetNumber(TwipsToPixels(ctr.x));
            argv[3].SetNumber(TwipsToPixels(ctr.y));
            if (asvm.ConstructInstance(pp, asvm.PerspectiveProjectionClass, 4, argv))
            {
                pp->pDispObj = pDispObj;
                if (isRoot)
                    pp->focalLength = pp->CalculateFocalLength(asvm.GetMovieImpl()->AsMovieInterface()->GetVisibleFrameRect().Width());
            }
            result = pp;
        }
    }

    // @0x14248bca0
    SPtr<Instances::fl_geom::PerspectiveProjection> Transform::perspectiveProjectionGet()
    {
        SPtr<Instances::fl_geom::PerspectiveProjection> result;
        perspectiveProjectionGet(result);
        return result;
    }

    // Binds the projection to the object: focal length from the stage width, then FOV and centre (global twips).
    // @0x14248c0d0
    void Transform::perspectiveProjectionSet(const Value& result, Instances::fl_geom::PerspectiveProjection* value)
    {
        SF_UNUSED(result);
        if (value && pDispObj)
        {
            ASVM& asvm = static_cast<ASVM&>(GetVM());
            value->focalLength = value->CalculateFocalLength(asvm.GetMovieImpl()->AsMovieInterface()->GetVisibleFrameRect().Width());
            value->pDispObj = pDispObj;
            pDispObj->SetFocalLength((float)(value->focalLength * 20));
            pDispObj->SetFOV((float)value->fieldOfView);
            PointF ctr = pDispObj->GetParent() ? pDispObj->GetParent()->LocalToGlobal(PixelsToTwips(value->projectionCenter))
                                               : PixelsToTwips(value->projectionCenter);
            pDispObj->SetProjectionCenter(ctr);
        }
    }
}}

namespace Instances { namespace fl_geom
{
    // The object's 3D matrix as a Matrix3D bound to it (translation in twips, as the display object keeps it).
    // @0x14248ac20
    __declspec(noinline) void Transform::matrix3DGet(SPtr<Instances::fl_geom::Matrix3D>& result)
    {
        if (pDispObj)
        {
            ASVM& asvm = static_cast<ASVM&>(GetVM());
            SPtr<Matrix3D> pm;
            Value argv[16];
            Render::Matrix3F m3 = pDispObj->GetMatrix3D();
            Render::Matrix4F m4(m3);
            for (int i = 0; i < 16; i++)
                argv[i].SetNumber((Double)m4[i]);
            if (asvm.ConstructInstance(pm, asvm.Matrix3DClass, 16, argv))
                pm->pDispObj = pDispObj;
            result = pm;
        }
    }

    // @0x14248ac00
    SPtr<Instances::fl_geom::Matrix3D> Transform::matrix3DGet()
    {
        SPtr<Instances::fl_geom::Matrix3D> result;
        matrix3DGet(result);
        return result;
    }

    // The object's world 3D matrix seen from relativeTo's space (relativeTo's inverse world matrix times ours), as a
    // Matrix3D bound to this object. relativeTo gets its stage object first if it has none.
    // @0x142489c00
    __declspec(noinline) void Transform::getRelativeMatrix3D(SPtr<Instances::fl_geom::Matrix3D>& result,
                                                             Instances::fl_display::DisplayObject* relativeTo)
    {
        if (!relativeTo)
            return GetVM().ThrowTypeError(VM::Error(VM::eNullPointerError, GetVM(), "relativeTo"));
        if (!relativeTo->pDispObj)
            relativeTo->CreateStageObject();
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        SPtr<Matrix3D> pm;
        Value argv[16];
        Render::Matrix3F world;
        pDispObj->GetWorldMatrix3D(&world);
        Render::Matrix3F relWorld;
        relativeTo->pDispObj->GetWorldMatrix3D(&relWorld);
        Render::Matrix3F m3(relWorld.GetInverse(), world);
        Render::Matrix4F m4(m3);
        for (int i = 0; i < 16; i++)
            argv[i].SetNumber((Double)m4[i]);
        if (asvm.ConstructInstance(pm, asvm.Matrix3DClass, 16, argv))
            pm->pDispObj = pDispObj;
        result = pm;
    }

    // @0x142489be0
    SPtr<Instances::fl_geom::Matrix3D> Transform::getRelativeMatrix3D(Instances::fl_display::DisplayObject* a0)
    {
        SPtr<Instances::fl_geom::Matrix3D> result;
        getRelativeMatrix3D(result, a0);
        return result;
    }

    // Sets the object's 3D matrix (translation given in pixels) and its x/y/z, rotations and scales. Null drops the 3D
    // state.
    // @0x14248af20
    void Transform::matrix3DSet(const Value& result, Instances::fl_geom::Matrix3D* value)
    {
        SF_UNUSED(result);
        if (pDispObj)
        {
            if (value)
            {
                Render::Matrix4F m4;
                for (int i = 0; i < 16; i++)
                    m4.Data()[i] = (float)value->mat4[i];
                Render::Matrix3F m(m4);
                m.Tx() = PixelsToTwips(m.Tx());
                m.Ty() = PixelsToTwips(m.Ty());
                m.Tz() = PixelsToTwips(m.Tz());
                pDispObj->SetMatrix3D(m);

                GFx::DisplayObjectBase::GeomDataType geom;
                pDispObj->GetGeomData(geom);
                geom.X = (int)m.Tx();
                geom.Y = (int)m.Ty();
                geom.Z = (int)m.Tz();
                float rx, ry, rz;
                m.GetRotation(&rx, &ry, &rz);
                geom.Rotation = SF_RADTODEG(rz);
                geom.XRotation = SF_RADTODEG(rx);
                geom.YRotation = SF_RADTODEG(ry);
                geom.XScale = m.GetXScale() * 100;
                geom.YScale = m.GetYScale() * 100;
                geom.ZScale = m.GetZScale() * 100;
                pDispObj->SetGeomData(geom);
            }
            else if (pDispObj->Is3D())
                pDispObj->Clear3D();
            pDispObj->SetAcceptAnimMoves(false);
        }
    }
}}

namespace Instances { namespace fl_geom
{
    // Each native that changes mat4 pushes it to the bound display object as its float 3x4 matrix.

    // this = this * m (m applied after).
    // @0x142486b60
    void Matrix3D::append(const Value& result, Instances::fl_geom::Matrix3D* m)
    {
        SF_UNUSED(result);
        if (m == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        mat4.Append(m->mat4);
        if (pDispObj)
        {
            Render::Matrix3F m(mat4);
            pDispObj->SetMatrix3D(m);
        }
    }

    // @0x142486dc0
    void Matrix3D::appendRotation(const Value& result, Value::Number degrees, Instances::fl_geom::Vector3D* axis, Instances::fl_geom::Vector3D* pivot)
    {
        SF_UNUSED(result);
        Render::Point3<double> ax = axis ? Render::Point3<double>(axis->x, axis->y, axis->z) : Render::Point3<double>(0, 0, 0);
        Render::Point3<double> pv = pivot ? Render::Point3<double>(pivot->x, pivot->y, pivot->z) : Render::Point3<double>(0, 0, 0);
        mat4.Append(Render::Matrix4x4<double>::Rotation(SF_DEGTORAD(degrees), ax, pv));
        if (pDispObj)
        {
            Render::Matrix3F m(mat4);
            pDispObj->SetMatrix3D(m);
        }
    }

    // @0x142487070
    void Matrix3D::appendScale(const Value& result, Value::Number sx, Value::Number sy, Value::Number sz)
    {
        SF_UNUSED(result);
        mat4.Append(Render::Matrix4x4<double>::Scaling(sx, sy, sz));
        if (pDispObj)
        {
            Render::Matrix3F m(mat4);
            pDispObj->SetMatrix3D(m);
        }
    }

    // @0x1424872c0
    void Matrix3D::appendTranslation(const Value& result, Value::Number tx, Value::Number ty, Value::Number tz)
    {
        SF_UNUSED(result);
        mat4.Append(Render::Matrix4x4<double>::Translation(tx, ty, tz));
        if (pDispObj)
        {
            Render::Matrix3F m(mat4);
            pDispObj->SetMatrix3D(m);
        }
    }

    // A new unbound Matrix3D with the same 16 values.
    // @0x142487690
    void Matrix3D::clone(SPtr<Instances::fl_geom::Matrix3D>& result)
    {
        Value args[16];
        for (int i = 0; i < 16; i++)
            args[i].SetNumber(mat4[i]);
        GetVM().ConstructBuiltinObject(result, "flash.geom.Matrix3D", 16, args).DoNotCheck();
    }

    // v through the matrix without its translation.
    // @0x142489470
    __declspec(noinline) void Matrix3D::deltaTransformVector(SPtr<Instances::fl_geom::Vector3D>& result, Instances::fl_geom::Vector3D* v)
    {
        if (v == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        Render::Matrix4x4<double> m(mat4);
        m.Tx() = 0;
        m.Ty() = 0;
        m.Tz() = 0;
        Render::Point3<double> p = m.Transform(Render::Point3<double>(v->x, v->y, v->z));
        InstanceTraits::fl_geom::Vector3D& itr = static_cast<InstanceTraits::fl_geom::Vector3D&>(v->GetInstanceTraits());
        Pickable<Instances::fl_geom::Vector3D> r = itr.MakeInstance(itr);
        r->x = p.x;
        r->y = p.y;
        r->z = p.z;
        result = r;
    }

    // @0x142489450
    SPtr<Instances::fl_geom::Vector3D> Matrix3D::deltaTransformVector(Instances::fl_geom::Vector3D* a0)
    {
        SPtr<Instances::fl_geom::Vector3D> result;
        deltaTransformVector(result, a0);
        return result;
    }

    // @0x142489690
    void Matrix3D::determinantGet(Value::Number& result)
    {
        result = mat4.GetDeterminant();
    }

    // @0x142489f90
    void Matrix3D::identity(const Value& result)
    {
        SF_UNUSED(result);
        mat4.SetIdentity();
        if (pDispObj)
        {
            Render::Matrix3F m(mat4);
            pDispObj->SetMatrix3D(m);
        }
    }

    // @0x14248a7a0
    void Matrix3D::invert(bool& result)
    {
        mat4.Invert();
        if (pDispObj)
        {
            Render::Matrix3F m(mat4);
            pDispObj->SetMatrix3D(m);
        }
        result = true;
    }

    // The translation in pixels (mat4 keeps it in twips), w = 0.
    // @0x14248cb80
    __declspec(noinline) void Matrix3D::positionGet(SPtr<Instances::fl_geom::Vector3D>& result)
    {
        Value argv[] = { Value(TwipsToPixels(mat4.Tx())), Value(TwipsToPixels(mat4.Ty())), Value(TwipsToPixels(mat4.Tz())), Value(0.0) };
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        asvm.ConstructInstance(result, asvm.GetClass("flash.geom.Vector3D"), 4, argv);
    }

    // @0x14248cb60
    SPtr<Instances::fl_geom::Vector3D> Matrix3D::positionGet()
    {
        SPtr<Instances::fl_geom::Vector3D> result;
        positionGet(result);
        return result;
    }

    // @0x14248ccc0
    void Matrix3D::positionSet(const Value& result, Instances::fl_geom::Vector3D* v)
    {
        SF_UNUSED(result);
        mat4.Tx() = PixelsToTwips(v->x);
        mat4.Ty() = PixelsToTwips(v->y);
        mat4.Tz() = PixelsToTwips(v->z);
        if (pDispObj)
        {
            Render::Matrix3F m(mat4);
            pDispObj->SetMatrix3D(m);
        }
    }

    // this = m * this (m applied before).
    // @0x14248ce90
    void Matrix3D::prepend(const Value& result, Instances::fl_geom::Matrix3D* m)
    {
        SF_UNUSED(result);
        if (m == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        mat4.Prepend(m->mat4);
        if (pDispObj)
        {
            Render::Matrix3F m(mat4);
            pDispObj->SetMatrix3D(m);
        }
    }

    // @0x14248d0f0
    void Matrix3D::prependRotation(const Value& result, Value::Number degrees, Instances::fl_geom::Vector3D* axis, Instances::fl_geom::Vector3D* pivot)
    {
        SF_UNUSED(result);
        Render::Point3<double> ax = axis ? Render::Point3<double>(axis->x, axis->y, axis->z) : Render::Point3<double>(0, 0, 0);
        Render::Point3<double> pv = pivot ? Render::Point3<double>(pivot->x, pivot->y, pivot->z) : Render::Point3<double>(0, 0, 0);
        mat4.Prepend(Render::Matrix4x4<double>::Rotation(SF_DEGTORAD(degrees), ax, pv));
        if (pDispObj)
        {
            Render::Matrix3F m(mat4);
            pDispObj->SetMatrix3D(m);
        }
    }

    // @0x14248d3a0
    void Matrix3D::prependScale(const Value& result, Value::Number sx, Value::Number sy, Value::Number sz)
    {
        SF_UNUSED(result);
        mat4.Prepend(Render::Matrix4x4<double>::Scaling(sx, sy, sz));
        if (pDispObj)
        {
            Render::Matrix3F m(mat4);
            pDispObj->SetMatrix3D(m);
        }
    }

    // @0x14248d5f0
    void Matrix3D::prependTranslation(const Value& result, Value::Number tx, Value::Number ty, Value::Number tz)
    {
        SF_UNUSED(result);
        mat4.Prepend(Render::Matrix4x4<double>::Translation(tx, ty, tz));
        if (pDispObj)
        {
            Render::Matrix3F m(mat4);
            pDispObj->SetMatrix3D(m);
        }
    }

    // @0x1424907e0
    __declspec(noinline) void Matrix3D::transformVector(SPtr<Instances::fl_geom::Vector3D>& result, Instances::fl_geom::Vector3D* v)
    {
        if (v == NULL)
            return GetVM().ThrowTypeError(VM::Error(VM::eConvertNullToObjectError, GetVM()));
        Render::Point3<double> p = mat4.Transform(Render::Point3<double>(v->x, v->y, v->z));
        InstanceTraits::fl_geom::Vector3D& itr = static_cast<InstanceTraits::fl_geom::Vector3D&>(v->GetInstanceTraits());
        Pickable<Instances::fl_geom::Vector3D> r = itr.MakeInstance(itr);
        r->x = p.x;
        r->y = p.y;
        r->z = p.z;
        result = r;
    }

    // @0x1424907c0
    SPtr<Instances::fl_geom::Vector3D> Matrix3D::transformVector(Instances::fl_geom::Vector3D* a0)
    {
        SPtr<Instances::fl_geom::Vector3D> result;
        transformVector(result, a0);
        return result;
    }

    // @0x142490df0
    void Matrix3D::transpose(const Value& result)
    {
        SF_UNUSED(result);
        mat4.Transpose();
        if (pDispObj)
        {
            Render::Matrix3F m(mat4);
            pDispObj->SetMatrix3D(m);
        }
    }
}}

namespace Instances { namespace fl_geom
{
    // decompose, interpolate, interpolateTo and recompose are unimplemented in this GFx version: they throw.

    // @0x142489220
    void Matrix3D::decompose(SPtr<Instances::fl_vec::Vector_object>& result, const ASString& orientationStyle)
    {
        SF_UNUSED2(result, orientationStyle);
        GetVM().ThrowError(VM::Error(VM::eNotImplementedError, GetVM(), "instance::Matrix3D::decompose() is not implemented yet"));
    }

    // @0x1424891c0
    SPtr<Instances::fl_vec::Vector_object> Matrix3D::decompose(const ASString& a0)
    {
        SPtr<Instances::fl_vec::Vector_object> result;
        decompose(result, a0);
        return result;
    }

    // @0x14248a310
    void Matrix3D::interpolate(SPtr<Instances::fl_geom::Matrix3D>& result, Instances::fl_geom::Matrix3D* thisMat, Instances::fl_geom::Matrix3D* toMat, Value::Number percent)
    {
        SF_UNUSED4(result, thisMat, toMat, percent);
        GetVM().ThrowError(VM::Error(VM::eNotImplementedError, GetVM(), "instance::Matrix3D::interpolate() is not implemented yet"));
    }

    // @0x14248a440
    void Matrix3D::interpolateTo(const Value& result, Instances::fl_geom::Matrix3D* toMat, Value::Number percent)
    {
        SF_UNUSED3(result, toMat, percent);
        GetVM().ThrowError(VM::Error(VM::eNotImplementedError, GetVM(), "instance::Matrix3D::interpolateTo() is not implemented yet"));
    }

    // @0x14248df60
    void Matrix3D::recompose(bool& result, Instances::fl_vec::Vector_object* components, const ASString& orientationStyle)
    {
        SF_UNUSED3(result, components, orientationStyle);
        GetVM().ThrowError(VM::Error(VM::eNotImplementedError, GetVM(), "instance::Matrix3D::recompose() is not implemented yet"));
    }
}}


// ---- flash.net: class traits, instance traits, classes and instances ----

namespace fl_net
{
    extern const ClassInfo FileFilterCI;
    extern const ClassInfo FileReferenceCI;
    extern const ClassInfo FileReferenceListCI;
    extern const ClassInfo IDynamicPropertyOutputCI;
    extern const ClassInfo IDynamicPropertyWriterCI;
    extern const ClassInfo LocalConnectionCI;
    extern const ClassInfo NetConnectionCI;
    extern const ClassInfo ObjectEncodingCI;
    extern const ClassInfo ResponderCI;
    extern const ClassInfo SharedObjectCI;
    extern const ClassInfo SharedObjectFlushStatusCI;
    extern const ClassInfo SocketCI;
    extern const ClassInfo URLLoaderCI;
    extern const ClassInfo URLLoaderDataFormatCI;
    extern const ClassInfo URLRequestCI;
    extern const ClassInfo URLRequestHeaderCI;
    extern const ClassInfo URLRequestMethodCI;
    extern const ClassInfo URLStreamCI;
    extern const ClassInfo URLVariablesCI;
    extern const ClassInfo XMLSocketCI;
}

// ---- FileFilter ----

namespace ClassTraits { namespace fl_net
{
    // @0x142495ae0
    FileFilter::FileFilter(VM& vm)
        : Traits(vm, AS3::fl_net::FileFilterCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_net::FileFilterCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424936f0
    Pickable<Traits> FileFilter::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) FileFilter(vm));
    }
}}

// ---- FileReference ----

namespace ClassTraits { namespace fl_net
{
    // @0x142495bc0
    FileReference::FileReference(VM& vm)
        : Traits(vm, AS3::fl_net::FileReferenceCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_events::EventDispatcher(vm, AS3::fl_net::FileReferenceCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142492a80
    Pickable<Traits> FileReference::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) FileReference(vm));
    }
}}

// ---- FileReferenceList ----

namespace ClassTraits { namespace fl_net
{
    // @0x142495ca0
    FileReferenceList::FileReferenceList(VM& vm)
        : Traits(vm, AS3::fl_net::FileReferenceListCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_events::EventDispatcher(vm, AS3::fl_net::FileReferenceListCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142493810
    Pickable<Traits> FileReferenceList::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) FileReferenceList(vm));
    }
}}

// ---- IDynamicPropertyOutput ----

namespace ClassTraits { namespace fl_net
{
    // @0x142495d80
    IDynamicPropertyOutput::IDynamicPropertyOutput(VM& vm)
        : Traits(vm, AS3::fl_net::IDynamicPropertyOutputCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::Interface(vm, AS3::fl_net::IDynamicPropertyOutputCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142493930
    Pickable<Traits> IDynamicPropertyOutput::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IDynamicPropertyOutput(vm));
    }
}}

// ---- IDynamicPropertyWriter ----

namespace ClassTraits { namespace fl_net
{
    // @0x142495e60
    IDynamicPropertyWriter::IDynamicPropertyWriter(VM& vm)
        : Traits(vm, AS3::fl_net::IDynamicPropertyWriterCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::Interface(vm, AS3::fl_net::IDynamicPropertyWriterCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142493a50
    Pickable<Traits> IDynamicPropertyWriter::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IDynamicPropertyWriter(vm));
    }
}}

// ---- LocalConnection ----

namespace ClassTraits { namespace fl_net
{
    // @0x142495f40
    LocalConnection::LocalConnection(VM& vm)
        : Traits(vm, AS3::fl_net::LocalConnectionCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_events::EventDispatcher(vm, AS3::fl_net::LocalConnectionCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142493ef0
    Pickable<Traits> LocalConnection::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) LocalConnection(vm));
    }
}}

// ---- NetConnection ----

namespace ClassTraits { namespace fl_net
{
    // @0x142496020
    NetConnection::NetConnection(VM& vm)
        : Traits(vm, AS3::fl_net::NetConnectionCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_net::NetConnection(vm, AS3::fl_net::NetConnectionCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142494130
    Pickable<Traits> NetConnection::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) NetConnection(vm));
    }
}}

namespace InstanceTraits { namespace fl_net
{
    // @0x142496120
    NetConnection::NetConnection(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x50);
    }
}}

namespace Instances { namespace fl_net
{
    // @0x142496150
    NetConnection::NetConnection(InstanceTraits::Traits& t)
        : Instances::fl_events::EventDispatcher(t)
    {
    }
}}

// ---- ObjectEncoding ----

namespace ClassTraits { namespace fl_net
{
    // @0x142496180
    ObjectEncoding::ObjectEncoding(VM& vm)
        : Traits(vm, AS3::fl_net::ObjectEncodingCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_net::ObjectEncodingCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_net::ObjectEncoding(*this)));
    }

    // @0x142494c70
    Pickable<Traits> ObjectEncoding::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ObjectEncoding(vm));
    }
}}

namespace Classes { namespace fl_net
{
    // @0x142496280
    ObjectEncoding::ObjectEncoding(ClassTraits::Traits& t)
        : Class(t)
        , AMF0(0)
        , AMF3(3)
        , Default(3)
    {
    }
}}

// ---- Responder ----

namespace ClassTraits { namespace fl_net
{
    // @0x1424962c0
    Responder::Responder(VM& vm)
        : Traits(vm, AS3::fl_net::ResponderCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_net::ResponderCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142494f00
    Pickable<Traits> Responder::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Responder(vm));
    }
}}

// ---- SharedObject ----

namespace ClassTraits { namespace fl_net
{
    // @0x1424963a0
    SharedObject::SharedObject(VM& vm)
        : Traits(vm, AS3::fl_net::SharedObjectCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_net::SharedObject(vm, AS3::fl_net::SharedObjectCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_net::SharedObject(*this)));
    }

    // @0x142495020
    Pickable<Traits> SharedObject::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SharedObject(vm));
    }
}}

namespace InstanceTraits { namespace fl_net
{
    // @0x1424964e0
    SharedObject::SharedObject(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x68);
    }
}}

namespace Instances { namespace fl_net
{
    // @0x142496510
    SharedObject::SharedObject(InstanceTraits::Traits& t)
        : Instances::fl_events::EventDispatcher(t)
    {
    }
}}

namespace Classes { namespace fl_net
{
    // @0x1424964b0
    SharedObject::SharedObject(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

// ---- SharedObjectFlushStatus ----

namespace ClassTraits { namespace fl_net
{
    // @0x142496550
    SharedObjectFlushStatus::SharedObjectFlushStatus(VM& vm)
        : Traits(vm, AS3::fl_net::SharedObjectFlushStatusCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_net::SharedObjectFlushStatusCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_net::SharedObjectFlushStatus(*this)));
    }

    // @0x142492400
    Pickable<Traits> SharedObjectFlushStatus::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SharedObjectFlushStatus(vm));
    }
}}

namespace Classes { namespace fl_net
{
    // @0x142496650
    SharedObjectFlushStatus::SharedObjectFlushStatus(ClassTraits::Traits& t)
        : Class(t)
        , Flushed("flushed")
        , Pending("pending")
    {
    }
}}

// ---- Socket ----

namespace ClassTraits { namespace fl_net
{
    // @0x142496690
    Socket::Socket(VM& vm)
        : Traits(vm, AS3::fl_net::SocketCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_events::EventDispatcher(vm, AS3::fl_net::SocketCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142494010
    Pickable<Traits> Socket::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Socket(vm));
    }
}}

// ---- URLLoader ----

namespace ClassTraits { namespace fl_net
{
    // @0x142496770
    URLLoader::URLLoader(VM& vm)
        : Traits(vm, AS3::fl_net::URLLoaderCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_net::URLLoader(vm, AS3::fl_net::URLLoaderCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142494b30
    Pickable<Traits> URLLoader::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) URLLoader(vm));
    }
}}

namespace InstanceTraits { namespace fl_net
{
    // @0x142496870
    URLLoader::URLLoader(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x80);
    }
}}

namespace Instances { namespace fl_net
{
    // @0x1424968a0
    URLLoader::URLLoader(InstanceTraits::Traits& t)
        : Instances::fl_events::EventDispatcher(t)
        , pLoadQueue(NULL)
        , DataFormat(GetVM().GetStringManager().CreateEmptyString())
    {
        DataFormat = "text";
    }
}}

// ---- URLLoaderDataFormat ----

namespace ClassTraits { namespace fl_net
{
    // @0x142496900
    URLLoaderDataFormat::URLLoaderDataFormat(VM& vm)
        : Traits(vm, AS3::fl_net::URLLoaderDataFormatCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_net::URLLoaderDataFormatCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_net::URLLoaderDataFormat(*this)));
    }

    // @0x142491380
    Pickable<Traits> URLLoaderDataFormat::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) URLLoaderDataFormat(vm));
    }
}}

namespace Classes { namespace fl_net
{
    // @0x142496a00
    URLLoaderDataFormat::URLLoaderDataFormat(ClassTraits::Traits& t)
        : Class(t)
        , Binary("binary")
        , Text("text")
        , Variables("variables")
    {
    }
}}

// ---- URLRequest ----

namespace ClassTraits { namespace fl_net
{
    // @0x142496a50
    URLRequest::URLRequest(VM& vm)
        : Traits(vm, AS3::fl_net::URLRequestCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_net::URLRequest(vm, AS3::fl_net::URLRequestCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142492ba0
    Pickable<Traits> URLRequest::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) URLRequest(vm));
    }
}}

namespace InstanceTraits { namespace fl_net
{
    // @0x142496b50
    URLRequest::URLRequest(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x48);
    }
}}

namespace Instances { namespace fl_net
{
    // @0x142496b80
    URLRequest::URLRequest(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , Url(GetVM().GetStringManager().CreateEmptyString())
    {
    }
}}

// ---- URLRequestHeader ----

namespace ClassTraits { namespace fl_net
{
    // @0x142496bd0
    URLRequestHeader::URLRequestHeader(VM& vm)
        : Traits(vm, AS3::fl_net::URLRequestHeaderCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_net::URLRequestHeader(vm, AS3::fl_net::URLRequestHeaderCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424922c0
    Pickable<Traits> URLRequestHeader::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) URLRequestHeader(vm));
    }
}}

namespace InstanceTraits { namespace fl_net
{
    // @0x142496cd0
    URLRequestHeader::URLRequestHeader(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x48);
    }
}}

namespace Instances { namespace fl_net
{
    // @0x142496d00
    URLRequestHeader::URLRequestHeader(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , HeaderName(GetVM().GetStringManager().CreateEmptyString())
        , HeaderValue(GetVM().GetStringManager().CreateEmptyString())
    {
    }
}}

// ---- URLRequestMethod ----

namespace ClassTraits { namespace fl_net
{
    // @0x142496d60
    URLRequestMethod::URLRequestMethod(VM& vm)
        : Traits(vm, AS3::fl_net::URLRequestMethodCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_net::URLRequestMethodCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_net::URLRequestMethod(*this)));
    }

    // @0x142492550
    Pickable<Traits> URLRequestMethod::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) URLRequestMethod(vm));
    }
}}

namespace Classes { namespace fl_net
{
    // @0x142496e90
    URLRequestMethod::URLRequestMethod(ClassTraits::Traits& t)
        : Class(t)
        , Delete("DELETE")
        , Get("GET")
        , Head("HEAD")
        , Options("OPTIONS")
        , Post("POST")
        , Put("PUT")
    {
    }
}}

// ---- URLStream ----

namespace ClassTraits { namespace fl_net
{
    // @0x142496f00
    URLStream::URLStream(VM& vm)
        : Traits(vm, AS3::fl_net::URLStreamCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_events::EventDispatcher(vm, AS3::fl_net::URLStreamCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424926d0
    Pickable<Traits> URLStream::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) URLStream(vm));
    }
}}

// ---- URLVariables ----

namespace ClassTraits { namespace fl_net
{
    // @0x142496fe0
    URLVariables::URLVariables(VM& vm)
        : Traits(vm, AS3::fl_net::URLVariablesCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_net::URLVariables(vm, AS3::fl_net::URLVariablesCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142494dc0
    Pickable<Traits> URLVariables::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) URLVariables(vm));
    }
}}

namespace InstanceTraits { namespace fl_net
{
    // @0x1424970e0
    URLVariables::URLVariables(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x40);
    }
}}

namespace Instances { namespace fl_net
{
    // @0x142497110
    URLVariables::URLVariables(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , Source(GetVM().GetStringManager().CreateEmptyString())
    {
    }
}}

// ---- XMLSocket ----

namespace ClassTraits { namespace fl_net
{
    // @0x142497150
    XMLSocket::XMLSocket(VM& vm)
        : Traits(vm, AS3::fl_net::XMLSocketCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_events::EventDispatcher(vm, AS3::fl_net::XMLSocketCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142492960
    Pickable<Traits> XMLSocket::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) XMLSocket(vm));
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
// MS2-PIN: ?MultiplyMatrix_NonOpt@?$Matrix4x4@N@Render@Scaleform@@QEAAXAEBV123@0@Z 0x142485d30
// MS2-PIN: ?Rotation@?$Matrix4x4@N@Render@Scaleform@@SA?AV123@NAEBV?$Point3@N@23@0@Z 0x142486210
// MS2-PIN: ?GetInverse@?$Matrix4x4@N@Render@Scaleform@@QEBA?AV123@XZ 0x142484b00
// MS2-PIN: ?GetMinor@?$Matrix4x4@N@Render@Scaleform@@AEBANAEBV123@_K11111@Z 0x142485360
// MS2-PIN: ??_7ColorTransform@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315de18
// MS2-PIN: ??_7FileFilter@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143162100
// MS2-PIN: ??_7FileReference@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143162190
// MS2-PIN: ??_7FileReferenceList@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143162428
// MS2-PIN: ??_7IDynamicPropertyOutput@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431624c0
// MS2-PIN: ??_7IDynamicPropertyWriter@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143162560
// MS2-PIN: ??_7LocalConnection@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143162600
// MS2-PIN: ??_7Matrix3D@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315e3d8
// MS2-PIN: ??_7Matrix@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315e6f0
// MS2-PIN: ??_7NetConnection@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143162810
// MS2-PIN: ??_7NetConnection@fl_net@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143162768
// MS2-PIN: ??_7NetConnection@fl_net@Instances@AS3@GFx@Scaleform@@6B@ 0x143162698
// MS2-PIN: ??_7ObjectEncoding@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143162d00
// MS2-PIN: ??_7ObjectEncoding@fl_net@Classes@AS3@GFx@Scaleform@@6B@ 0x143162d98
// MS2-PIN: ??_7PerspectiveProjection@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315ebd8
// MS2-PIN: ??_7Point@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315e8e8
// MS2-PIN: ??_7Rectangle@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315ee00
// MS2-PIN: ??_7Responder@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143162e80
// MS2-PIN: ??_7SharedObject@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431630d0
// MS2-PIN: ??_7SharedObject@fl_net@Classes@AS3@GFx@Scaleform@@6B@ 0x143163168
// MS2-PIN: ??_7SharedObject@fl_net@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143163020
// MS2-PIN: ??_7SharedObject@fl_net@Instances@AS3@GFx@Scaleform@@6B@ 0x143162f58
// MS2-PIN: ??_7SharedObjectFlushStatus@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143163250
// MS2-PIN: ??_7SharedObjectFlushStatus@fl_net@Classes@AS3@GFx@Scaleform@@6B@ 0x1431632f0
// MS2-PIN: ??_7Socket@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431638c0
// MS2-PIN: ??_7Transform@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315f008
// MS2-PIN: ??_7URLLoader@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143163ac0
// MS2-PIN: ??_7URLLoader@fl_net@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143163a18
// MS2-PIN: ??_7URLLoaderDataFormat@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143163dc0
// MS2-PIN: ??_7URLLoaderDataFormat@fl_net@Classes@AS3@GFx@Scaleform@@6B@ 0x143163e60
// MS2-PIN: ??_7URLRequest@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143162398
// MS2-PIN: ??_7URLRequest@fl_net@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431622f0
// MS2-PIN: ??_7URLRequest@fl_net@Instances@AS3@GFx@Scaleform@@6B@ 0x143162228
// MS2-PIN: ??_7URLRequestHeader@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431645b0
// MS2-PIN: ??_7URLRequestHeader@fl_net@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143164500
// MS2-PIN: ??_7URLRequestHeader@fl_net@Instances@AS3@GFx@Scaleform@@6B@ 0x143164430
// MS2-PIN: ??_7URLRequestMethod@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143164648
// MS2-PIN: ??_7URLRequestMethod@fl_net@Classes@AS3@GFx@Scaleform@@6B@ 0x1431646e0
// MS2-PIN: ??_7URLStream@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431647d0
// MS2-PIN: ??_7URLVariables@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143163cc0
// MS2-PIN: ??_7URLVariables@fl_net@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143163c18
// MS2-PIN: ??_7URLVariables@fl_net@Instances@AS3@GFx@Scaleform@@6B@ 0x143163b50
// MS2-PIN: ??_7Vector3D@fl_geom@Instances@AS3@GFx@Scaleform@@6B@ 0x14315e0c0
// MS2-PIN: ??_7XMLSocket@fl_net@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143164860
// MS2-PIN: ??_7URLLoader@fl_net@Instances@AS3@GFx@Scaleform@@6B@ 0x143163950
