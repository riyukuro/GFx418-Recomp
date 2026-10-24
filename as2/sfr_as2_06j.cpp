// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 Rectangle setters of sfr_as2_06
// (gap recovery, lane sfr31): SetProperties (values and rectangle) and RectangleObject::SetMember.
// MS2-UNIT: sfr_as2_06j
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142986d60-0x14298708d .text$mn
// MS2-RANGE: 0x142989e90-0x14298a03b .text$mn
// MS2-RANGE: 0x14298a040-0x14298a259 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/kernel/sf_std.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// @0x142989e90
void RectangleObject::SetProperties(ASStringContext* psc, const Value params[Rectangle_NumProperties])
{
    ObjectInterface& oi = *this;
    oi.SetMemberRaw(psc, psc->CreateConstString("x"), params[Rectangle_X], PropFlags());
    oi.SetMemberRaw(psc, psc->CreateConstString("y"), params[Rectangle_Y], PropFlags());
    oi.SetMemberRaw(psc, psc->CreateConstString("width"), params[Rectangle_Width], PropFlags());
    oi.SetMemberRaw(psc, psc->CreateConstString("height"), params[Rectangle_Height], PropFlags());
}

// @0x14298a040
void RectangleObject::SetProperties(Environment* penv, const ASRect& r)
{
    ASStringContext* psc = penv->GetSC();
    ObjectInterface& oi = *this;
    oi.SetMemberRaw(psc, psc->CreateConstString("x"), Value(r.x1), PropFlags());
    oi.SetMemberRaw(psc, psc->CreateConstString("y"), Value(r.y1), PropFlags());
    oi.SetMemberRaw(psc, psc->CreateConstString("width"), Value(r.x2 - r.x1), PropFlags());
    oi.SetMemberRaw(psc, psc->CreateConstString("height"), Value(r.y2 - r.y1), PropFlags());
}

// MS2-FUNCTIONAL: the exe compares the names with inlined byte loops in a different order
// @0x142986d60
bool RectangleObject::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    if (flags.Flags & PropFlags::PropFlag_ReadOnly)
        return false;
    const char* pname = name.ToCStr();
    ASRect      r(0, 0, 0, 0);
    if (strcmp(pname, "left") == 0)
    {
        GetProperties(penv, r);
        r.x1 = val.ToNumber(penv);
    }
    else if (strcmp(pname, "top") == 0)
    {
        GetProperties(penv, r);
        r.y1 = val.ToNumber(penv);
    }
    else if (strcmp(pname, "right") == 0)
    {
        GetProperties(penv, r);
        r.x2 = val.ToNumber(penv);
    }
    else if (strcmp(pname, "bottom") == 0)
    {
        GetProperties(penv, r);
        r.y2 = val.ToNumber(penv);
    }
    else if (strcmp(pname, "topLeft") == 0)
    {
        GetProperties(penv, r);
        Object* ppt = val.ToObject(penv);
        if (ppt)
        {
            GASPoint pt;
            GFxObject_GetPointProperties(penv, ppt, pt);
            r.x1 = pt.x;
            r.y1 = pt.y;
        }
    }
    else if (strcmp(pname, "bottomRight") == 0)
    {
        GetProperties(penv, r);
        Object* ppt = val.ToObject(penv);
        if (ppt)
        {
            GASPoint pt;
            GFxObject_GetPointProperties(penv, ppt, pt);
            r.x2 = pt.x;
            r.y2 = pt.y;
        }
    }
    else if (strcmp(pname, "size") == 0)
    {
        GetProperties(penv, r);
        Object* ppt = val.ToObject(penv);
        if (ppt)
        {
            GASPoint pt;
            GFxObject_GetPointProperties(penv, ppt, pt);
            r.y2 = r.y1 + pt.y;
            r.x2 = pt.x + r.x1;
        }
    }
    else
        return Object::SetMember(penv, name, val, flags);
    SetProperties(penv, r);
    return true;
}

}}} // namespace Scaleform::GFx::AS2
