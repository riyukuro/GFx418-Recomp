// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_GEOM_H
#define MS2_SF_GFX_AS3_OBJ_GEOM_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_geom {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class ColorTransform : public Instances::fl::Object
    {
    public:
        // @0x142487c50
        void colorGet(UInt32& result);
        // @0x142487c80
        void colorSet(const Value& result, UInt32);
        // @0x142488220
        void concat(const Value& result, Instances::fl_geom::ColorTransform*);
        // @0x14248e760
        void toString(ASString& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Matrix : public Instances::fl::Object
    {
    public:
        // @0x142487860
        void clone(SPtr<Instances::fl_geom::Matrix>& result);
        // @0x1424882b0
        void concat(const Value& result, Instances::fl_geom::Matrix*);
        // @0x142488df0
        void createBox(const Value& result, Value::Number, Value::Number, Value::Number, Value::Number, Value::Number);
        // @0x142488ef0
        void createGradientBox(const Value& result, Value::Number, Value::Number, Value::Number, Value::Number, Value::Number);
        // @0x142489320
        void deltaTransformPoint(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point*);
        // @0x14248a170
        void identity(const Value& result);
        // @0x14248a9c0
        void invert(const Value& result);
        // @0x14248dfd0
        void rotate(const Value& result, Value::Number);
        // @0x14248e080
        void scale(const Value& result, Value::Number, Value::Number);
        // @0x14248f1f0
        void toString(ASString& result);
        // @0x142490680
        void transformPoint(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point*);
        // @0x142490dd0
        void translate(const Value& result, Value::Number, Value::Number);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Matrix3D : public Instances::fl::Object
    {
    public:
        // @0x142486b60
        void append(const Value& result, Instances::fl_geom::Matrix3D*);
        // @0x142486dc0
        void appendRotation(const Value& result, Value::Number, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*);
        // @0x142487070
        void appendScale(const Value& result, Value::Number, Value::Number, Value::Number);
        // @0x1424872c0
        void appendTranslation(const Value& result, Value::Number, Value::Number, Value::Number);
        // @0x142487690
        void clone(SPtr<Instances::fl_geom::Matrix3D>& result);
        // @0x142489220
        void decompose(SPtr<Instances::fl_vec::Vector_object>& result, const ASString&);
        // @0x142489470
        void deltaTransformVector(SPtr<Instances::fl_geom::Vector3D>& result, Instances::fl_geom::Vector3D*);
        // @0x142489690
        void determinantGet(Value::Number& result);
        // @0x142489f90
        void identity(const Value& result);
        // @0x14248a310
        void interpolate(SPtr<Instances::fl_geom::Matrix3D>& result, Instances::fl_geom::Matrix3D*, Instances::fl_geom::Matrix3D*, Value::Number);
        // @0x14248a440
        void interpolateTo(const Value& result, Instances::fl_geom::Matrix3D*, Value::Number);
        // @0x14248a7a0
        void invert(bool& result);
        // @0x14248c5f0
        void pointAt(const Value& result, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*);
        // @0x14248cb80
        void positionGet(SPtr<Instances::fl_geom::Vector3D>& result);
        // @0x14248ccc0
        void positionSet(const Value& result, Instances::fl_geom::Vector3D*);
        // @0x14248ce90
        void prepend(const Value& result, Instances::fl_geom::Matrix3D*);
        // @0x14248d0f0
        void prependRotation(const Value& result, Value::Number, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*);
        // @0x14248d3a0
        void prependScale(const Value& result, Value::Number, Value::Number, Value::Number);
        // @0x14248d5f0
        void prependTranslation(const Value& result, Value::Number, Value::Number, Value::Number);
        // @0x14248da70
        void rawDataGet(SPtr<Instances::fl_vec::Vector_double>& result);
        // @0x14248dc60
        void rawDataSet(const Value& result, Instances::fl_vec::Vector_double*);
        // @0x14248df60
        void recompose(bool& result, Instances::fl_vec::Vector_object*, const ASString&);
        // @0x1424907e0
        void transformVector(SPtr<Instances::fl_geom::Vector3D>& result, Instances::fl_geom::Vector3D*);
        // @0x142490960
        void transformVectors(const Value& result, Instances::fl_vec::Vector_double*, Instances::fl_vec::Vector_double*);
        // @0x142490df0
        void transpose(const Value& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class PerspectiveProjection : public Instances::fl::Object
    {
    public:
        // @0x142489b60
        void fieldOfViewGet(Value::Number& result);
        // @0x142489b70
        void fieldOfViewSet(const Value& result, Value::Number);
        // @0x142489ba0
        void focalLengthGet(Value::Number& result);
        // @0x142489bb0
        void focalLengthSet(const Value& result, Value::Number);
        // @0x14248d8a0
        void projectionCenterGet(SPtr<Instances::fl_geom::Point>& result);
        // @0x14248d9f0
        void projectionCenterSet(const Value& result, Instances::fl_geom::Point*);
        // @0x14248e490
        void toMatrix3D(SPtr<Instances::fl_geom::Matrix3D>& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Point : public Instances::fl::Object
    {
    public:
        // @0x142486840
        void add(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point*);
        // @0x1424879a0
        void clone(SPtr<Instances::fl_geom::Point>& result);
        // @0x142489990
        void equals(bool& result, Instances::fl_geom::Point*);
        // @0x14248ab60
        void lengthGet(Value::Number& result);
        // @0x14248bac0
        void normalize(const Value& result, Value::Number);
        // @0x14248bbe0
        void offset(const Value& result, Value::Number, Value::Number);
        // @0x14248e240
        void subtract(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point*);
        // @0x14248f9b0
        void toString(ASString& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Rectangle : public Instances::fl::Object
    {
    public:
        // @0x142487510
        void bottomGet(Value::Number& result);
        // @0x142487540
        void bottomRightGet(SPtr<Instances::fl_geom::Point>& result);
        // @0x142487600
        void bottomRightSet(const Value& result, Instances::fl_geom::Point*);
        // @0x142487680
        void bottomSet(const Value& result, Value::Number);
        // @0x142487a50
        void clone(SPtr<Instances::fl_geom::Rectangle>& result);
        // @0x142488c10
        void contains(bool& result, Value::Number, Value::Number);
        // @0x142488c50
        void containsPoint(bool& result, Instances::fl_geom::Point*);
        // @0x142488cf0
        void containsRect(bool& result, Instances::fl_geom::Rectangle*);
        // @0x142489a10
        void equals(bool& result, Instances::fl_geom::Rectangle*);
        // @0x14248a230
        void inflate(const Value& result, Value::Number, Value::Number);
        // @0x14248a270
        void inflatePoint(const Value& result, Instances::fl_geom::Point*);
        // @0x14248a490
        void intersection(SPtr<Instances::fl_geom::Rectangle>& result, Instances::fl_geom::Rectangle*);
        // @0x14248a6c0
        void intersects(bool& result, Instances::fl_geom::Rectangle*);
        // @0x14248ab10
        void isEmpty(bool& result);
        // @0x14248ab30
        void leftGet(Value::Number& result);
        // @0x14248ab40
        void leftSet(const Value& result, Value::Number);
        // @0x14248bc00
        void offset(const Value& result, Value::Number, Value::Number);
        // @0x14248bc20
        void offsetPoint(const Value& result, Instances::fl_geom::Point*);
        // @0x14248dfb0
        void rightGet(Value::Number& result);
        // @0x14248dfc0
        void rightSet(const Value& result, Value::Number);
        // @0x14248e0f0
        void setEmpty(const Value& result);
        // @0x14248e120
        void sizeGet(SPtr<Instances::fl_geom::Point>& result);
        // @0x14248e1d0
        void sizeSet(const Value& result, Instances::fl_geom::Point*);
        // @0x14248fc30
        void toString(ASString& result);
        // @0x1424904d0
        void topGet(Value::Number& result);
        // @0x142490500
        void topLeftGet(SPtr<Instances::fl_geom::Point>& result);
        // @0x1424905b0
        void topLeftSet(const Value& result, Instances::fl_geom::Point*);
        // @0x142490640
        void topSet(const Value& result, Value::Number);
        // @0x142490fb0
        void union_(SPtr<Instances::fl_geom::Rectangle>& result, Instances::fl_geom::Rectangle*);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Transform : public Instances::fl::Object
    {
    public:
        // @0x142487d00
        void colorTransformGet(SPtr<Instances::fl_geom::ColorTransform>& result);
        // @0x142488100
        void colorTransformSet(const Value& result, Instances::fl_geom::ColorTransform*);
        // @0x142488440
        void concatenatedColorTransformGet(SPtr<Instances::fl_geom::ColorTransform>& result);
        // @0x142488880
        void concatenatedMatrixGet(SPtr<Instances::fl_geom::Matrix>& result);
        // @0x142489c00
        void getRelativeMatrix3D(SPtr<Instances::fl_geom::Matrix3D>& result, Instances::fl_display::DisplayObject*);
        // @0x14248ac20
        void matrix3DGet(SPtr<Instances::fl_geom::Matrix3D>& result);
        // @0x14248af20
        void matrix3DSet(const Value& result, Instances::fl_geom::Matrix3D*);
        // @0x14248b450
        void matrixGet(SPtr<Instances::fl_geom::Matrix>& result);
        // @0x14248b7c0
        void matrixSet(const Value& result, Instances::fl_geom::Matrix*);
        // @0x14248bcc0
        void perspectiveProjectionGet(SPtr<Instances::fl_geom::PerspectiveProjection>& result);
        // @0x14248c0d0
        void perspectiveProjectionSet(const Value& result, Instances::fl_geom::PerspectiveProjection*);
        // @0x14248c270
        void pixelBoundsGet(SPtr<Instances::fl_geom::Rectangle>& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Vector3D : public Instances::fl::Object
    {
    public:
        // @0x142486950
        void add(SPtr<Instances::fl_geom::Vector3D>& result, Instances::fl_geom::Vector3D*);
        // @0x142487b50
        void clone(SPtr<Instances::fl_geom::Vector3D>& result);
        // @0x142489060
        void crossProduct(SPtr<Instances::fl_geom::Vector3D>& result, Instances::fl_geom::Vector3D*);
        // @0x142489270
        void decrementBy(const Value& result, Instances::fl_geom::Vector3D*);
        // @0x142489910
        void dotProduct(Value::Number& result, Instances::fl_geom::Vector3D*);
        // @0x142489ab0
        void equals(bool& result, Instances::fl_geom::Vector3D*, bool);
        // @0x14248a1a0
        void incrementBy(const Value& result, Instances::fl_geom::Vector3D*);
        // @0x14248ab90
        void lengthGet(Value::Number& result);
        // @0x14248abd0
        void lengthSquaredGet(Value::Number& result);
        // @0x14248b9b0
        void nearEquals(bool& result, Instances::fl_geom::Vector3D*, Value::Number, bool);
        // @0x14248baa0
        void negate(const Value& result);
        // @0x14248bb60
        void normalize(Value::Number& result);
        // @0x14248d850
        void project(const Value& result);
        // @0x14248e0d0
        void scaleBy(const Value& result, Value::Number);
        // @0x14248e350
        void subtract(SPtr<Instances::fl_geom::Vector3D>& result, Instances::fl_geom::Vector3D*);
        // @0x142490150
        void toString(ASString& result);
        // @0x142491300
        void wGet(Value::Number& result);
        // @0x142491310
        void wSet(const Value& result, Value::Number);
        // @0x142491320
        void xGet(Value::Number& result);
        // @0x142491330
        void xSet(const Value& result, Value::Number);
        // @0x142491340
        void yGet(Value::Number& result);
        // @0x142491350
        void ySet(const Value& result, Value::Number);
        // @0x142491360
        void zGet(Value::Number& result);
        // @0x142491370
        void zSet(const Value& result, Value::Number);
    };

}}

namespace Classes { namespace fl_geom {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Point : public Class
    {
    public:
        // @0x142489880
        void distance(Value::Number& result, Instances::fl_geom::Point*, Instances::fl_geom::Point*);
        // @0x14248a360
        void interpolate(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point*, Instances::fl_geom::Point*, Value::Number);
        // @0x14248ca70
        void polar(SPtr<Instances::fl_geom::Point>& result, Value::Number, Value::Number);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Vector3D : public Class
    {
    public:
        // @0x142486a70
        void angleBetween(Value::Number& result, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*);
        // @0x1424898c0
        void distance(Value::Number& result, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*);
    };

}}

}}} // namespace Scaleform::GFx::AS3

#endif
