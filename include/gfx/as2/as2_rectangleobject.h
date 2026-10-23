// Recovered Scaleform 4.1.18 GFx AS2: flash.geom.Rectangle (x, y, width and height kept as ordinary members).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_RECTANGLEOBJECT_H
#define MS2_SF_GFX_AS2_RECTANGLEOBJECT_H

#include "as2_pointobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

enum Rectangle_Property
{
    Rectangle_X,
    Rectangle_Y,
    Rectangle_Width,
    Rectangle_Height,
    Rectangle_NumProperties
};

typedef Render::Rect<Number> ASRect;

// No edge is NaN (exe 0x142965db0).
MS2_AS2_SCU bool IsRectValid(const ASRect& r);
// NaN edges become 0 (exe 0x142992e30).
void ValidateRect(ASRect* r);

// The out-of-line copy of NumberUtil::IsNaN (exe 0x142444c00): some unity-build call sites call it instead of
// inlining the header body.
MS2_AS2_SCU bool NumberUtil_IsNaN(Double v);

// x, y, width and height of any object (exe 0x142948660).
void GFxObject_GetRectangleProperties(Environment* penv, Object* pobj, Value params[Rectangle_NumProperties]);

// All NaN (exe 0x143d74730).
extern const Value Rectangle_NaNParams[Rectangle_NumProperties];
// The x, y, width and height of a new Rectangle (exe 0x143a51bb0).
extern const Value Rectangle_DefaultParams[Rectangle_NumProperties];

// Rectangle instance. 0x68 bytes.
class RectangleObject : public Object
{
public:
    RectangleObject(Environment* penv); // exe 0x142920000
    RectangleObject(ASStringContext* psc, Object* pprototype) : Object(psc)
    {
        Set__proto__(psc, pprototype);
    }

    virtual ObjectType GetObjectType() const; // exe 0x1429542f0
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags()); // exe 0x142986d60
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val); // exe 0x14294f880

    void GetProperties(ASStringContext* psc, Value params[Rectangle_NumProperties]);       // exe 0x142954690
    void SetProperties(ASStringContext* psc, const Value params[Rectangle_NumProperties]); // exe 0x142989e90
    void GetProperties(Environment* penv, ASRect& r);                                      // exe 0x142954800
    void SetProperties(Environment* penv, const ASRect& r);                                // exe 0x14298a040
};

// Rectangle.prototype: the methods plus the edge and corner members.
class RectangleProto : public Prototype<RectangleObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x1432130e0

    RectangleProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142920080

    static void Clone(const FnCall& fn);
    static void Contains(const FnCall& fn);
    static void ContainsPoint(const FnCall& fn);
    static void ContainsRectangle(const FnCall& fn);
    static void Equals(const FnCall& fn);
    static void Inflate(const FnCall& fn);
    static void InflatePoint(const FnCall& fn);
    static void Intersection(const FnCall& fn);
    static void Intersects(const FnCall& fn);
    static void IsEmpty(const FnCall& fn);
    static void Offset(const FnCall& fn);
    static void OffsetPoint(const FnCall& fn);
    static void SetEmpty(const FnCall& fn);
    static void ToString(const FnCall& fn);
    static void Union(const FnCall& fn);
};

// The flash.geom.Rectangle class.
class RectangleCtorFunction : public CFunctionObject
{
public:
    // (appended for sfr_as2_06) Inlined into Register in the exe.
    RectangleCtorFunction(ASStringContext* psc) : CFunctionObject(psc, GlobalCtor) {}

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x1429371f0

    // new Rectangle(x, y, w, h) / Rectangle(...): the instance (a new one when called as a function) with the
    // given properties set (exe 0x14295c3a0).
    static void GlobalCtor(const FnCall& fn);

    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "Rectangle" (exe 0x142979d00).
    static FunctionRef Register(GlobalContext* pgc);
};

}}} // namespace Scaleform::GFx::AS2

#endif
