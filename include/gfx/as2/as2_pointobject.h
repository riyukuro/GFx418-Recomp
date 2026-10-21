// Recovered Scaleform 4.1.18 GFx AS2: flash.geom.Point (x and y kept as ordinary members of the object).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_POINTOBJECT_H
#define MS2_SF_GFX_AS2_POINTOBJECT_H

#include "as2_movieroot.h"
#include "../../render/render_types2d.h"

namespace Scaleform { namespace GFx { namespace AS2 {

enum Point_Property
{
    Point_X,
    Point_Y,
    Point_NumProperties
};

typedef Render::Point<Number> GASPoint;

// x and y of any object (exe 0x1429484e0).
void GFxObject_GetPointProperties(Environment* penv, Object* pobj, GASPoint& pt);

// x and y of any object as values.
SF_FORCEINLINE void GFxObject_GetPointProperties(Environment* penv, Object* pobj, Value params[Point_NumProperties])
{
    ASStringContext* psc = penv->GetSC();
    pobj->GetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_x), &params[Point_X]);
    pobj->GetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_y), &params[Point_Y]);
}

// Both NaN (exe 0x143d747b0).
extern const Value Point_NanParams[Point_NumProperties];

// Point instance. 0x68 bytes.
class PointObject : public Object
{
public:
    PointObject(Environment* penv); // exe 0x14291fc10

    void GetProperties(Environment* penv, GASPoint& pt);       // exe 0x142954590
    void SetProperties(Environment* penv, const GASPoint& pt); // exe 0x142989db0

    void GetProperties(ASStringContext* psc, Value params[Point_NumProperties])
    {
        GetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_x), &params[Point_X]);
        GetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_y), &params[Point_Y]);
    }
    // Inlined at every exe call site (the unity build sees the body); MSVC's own budget would not.
    SF_FORCEINLINE void SetProperties(ASStringContext* psc, const Value params[Point_NumProperties])
    {
        SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_x), params[Point_X]);
        SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_y), params[Point_Y]);
    }
    // The out-of-line copy of the above (exe 0x142989d20), called where the exe did not inline it.
    void SetProperties_Call(ASStringContext* psc, const Value params[Point_NumProperties]);

    // length is the distance from the origin, the rest are plain members (exe 0x14294f7e0).
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);
};

// Point.prototype methods.
class PointProto
{
public:
    static void Add(const FnCall& fn);
    static void Clone(const FnCall& fn);
    static void Equals(const FnCall& fn);
    static void Normalize(const FnCall& fn);
    static void Offset(const FnCall& fn);
    static void Subtract(const FnCall& fn);
    static void ToString(const FnCall& fn);
};

// The Point constructor function's own methods.
class PointCtorFunction : public CFunctionObject
{
public:
    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x1429371b0

    // new Point(x, y) / Point(x, y): the instance (a new one when called as a function) with x and y set
    // (exe 0x14295c160).
    static void GlobalCtor(const FnCall& fn);

protected:
    static void Distance(const FnCall& fn);
    static void Interpolate(const FnCall& fn);
    static void Polar(const FnCall& fn);
};

}}} // namespace Scaleform::GFx::AS2

#endif
