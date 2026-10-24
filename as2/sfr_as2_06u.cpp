// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 gap functions of sfr_as2_06
// (lane sfr36): the Transform object setters.
// MS2-UNIT: sfr_as2_06u
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142988380-0x142988688 .text$mn

#include <math.h>
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/gfx/gfx_displayobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// pixelBounds is read-only; colorTransform and matrix are copied to the target character; the rest is a plain
// member.
// @0x142988380
bool TransformObject::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    const char* pname = name.ToCStr();
    if (strcmp(pname, "pixelBounds") == 0)
        return true;
    if (strcmp(pname, "colorTransform") == 0)
    {
        if (!pMovieRoot)
            return true;
        Ptr<DisplayObject> ch = TargetHandle->ResolveCharacter(pMovieRoot);
        if (!ch)
            return true;
        Ptr<Object> pobj = val.ToObject(penv);
        if (pobj && pobj->GetObjectType() == Object_ColorTransform)
        {
            Render::Cxform cx = static_cast<ColorTransformObject*>(pobj.GetPtr())->mColorTransform;
            cx.Normalize();
            ch->SetCxform(cx);
            ch->SetAcceptAnimMoves(false);
        }
        return true;
    }
    if (strcmp(pname, "matrix") != 0)
        return Object::SetMember(penv, name, val, flags);
    if (!pMovieRoot)
        return true;
    Ptr<DisplayObject> ch = TargetHandle->ResolveCharacter(pMovieRoot);
    if (!ch)
        return true;
    Ptr<Object> pobj = val.ToObject(penv);
    if (pobj && pobj->GetObjectType() == Object_Matrix)
    {
        Render::Matrix2F m = static_cast<MatrixObject*>(pobj.GetPtr())->GetMatrix(penv);
        m.Tx() = m.Tx() * 20.f;
        m.Ty() = m.Ty() * 20.f;
        ch->SetMatrix(m);

        DisplayObjectBase::GeomDataType gd;
        ch->GetGeomData(gd);
        gd.X        = int(m.Tx());
        gd.Y        = int(m.Ty());
        gd.Rotation = atan2((double)m.Shy(), (double)m.Sx()) * 180. / SF_MATH_PI;
        gd.XScale   = sqrt((double)m.Sx() * (double)m.Sx() + (double)m.Shy() * (double)m.Shy()) * 100.;
        gd.YScale   = sqrt((double)m.Sy() * (double)m.Sy() + (double)m.Shx() * (double)m.Shx()) * 100.;
        ch->SetGeomData(gd);
    }
    return true;
}

}}} // namespace Scaleform::GFx::AS2
