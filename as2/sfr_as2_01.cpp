// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 builtin class natives
// (Boolean prototype methods, the Math object functions).
// MS2-UNIT: sfr_as2_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1428f4cd0-0x1428f4e40 .text$mn
// MS2-RANGE: 0x1428fb110-0x1428fbb70 .text$mn

#include <math.h>

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/gfx_displayobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// Boolean wrapper object. 0x70 bytes.
class BooleanObject : public Object
{
public:
    bool bValue; // +0x68
};

// Boolean.prototype.toString(): "true" / "false" of the wrapped value.
// @0x1428f4cd0
void GAS_BooleanToString(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Boolean);
    BooleanObject* pthis = (BooleanObject*)(Object*)fn.ThisPtr;
    fn.Result->SetString(pthis->GetValue().ToString(fn.Env));
}

// Boolean.prototype.valueOf()
// @0x1428f4da0
void GAS_BooleanValueOf(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Boolean);
    BooleanObject* pthis = (BooleanObject*)(Object*)fn.ThisPtr;
    fn.Result->SetBool(pthis->GetValue().ToBool(fn.Env));
}

class Math
{
public:
    // Next value of the movie's random generator (exe 0x142953f50).
    static UInt32 GetNextRandom(MovieImpl* proot);
};

// The Math object's functions; every argument goes through ToNumber.
class MathCtorFunction
{
    static void Abs(const FnCall& fn);
    static void Acos(const FnCall& fn);
    static void Asin(const FnCall& fn);
    static void Atan(const FnCall& fn);
    static void Ceil(const FnCall& fn);
    static void Cos(const FnCall& fn);
    static void Exp(const FnCall& fn);
    static void Floor(const FnCall& fn);
    static void Log(const FnCall& fn);
    static void Sin(const FnCall& fn);
    static void Sqrt(const FnCall& fn);
    static void Tan(const FnCall& fn);
    static void Atan2(const FnCall& fn);
    static void Max(const FnCall& fn);
    static void Min(const FnCall& fn);
    static void Pow(const FnCall& fn);
    static void Random(const FnCall& fn);
    static void Round(const FnCall& fn);
};

// @0x1428fb110
void MathCtorFunction::Abs(const FnCall& fn)
{
    fn.Result->SetNumber(fabs(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb1a0
void MathCtorFunction::Acos(const FnCall& fn)
{
    fn.Result->SetNumber(acos(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb220
void MathCtorFunction::Asin(const FnCall& fn)
{
    fn.Result->SetNumber(asin(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb2a0
void MathCtorFunction::Atan(const FnCall& fn)
{
    fn.Result->SetNumber(atan(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb320
void MathCtorFunction::Ceil(const FnCall& fn)
{
    fn.Result->SetNumber(ceil(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb3a0
void MathCtorFunction::Cos(const FnCall& fn)
{
    fn.Result->SetNumber(cos(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb420
void MathCtorFunction::Exp(const FnCall& fn)
{
    fn.Result->SetNumber(exp(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb4a0
void MathCtorFunction::Floor(const FnCall& fn)
{
    fn.Result->SetNumber(floor(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb520
void MathCtorFunction::Log(const FnCall& fn)
{
    fn.Result->SetNumber(log(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb5a0
void MathCtorFunction::Sin(const FnCall& fn)
{
    fn.Result->SetNumber(sin(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb620
void MathCtorFunction::Sqrt(const FnCall& fn)
{
    fn.Result->SetNumber(sqrt(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb6a0
void MathCtorFunction::Tan(const FnCall& fn)
{
    fn.Result->SetNumber(tan(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb720
void MathCtorFunction::Atan2(const FnCall& fn)
{
    Number y = fn.Arg(0).ToNumber(fn.Env);
    Number x = fn.Arg(1).ToNumber(fn.Env);
    fn.Result->SetNumber(atan2(y, x));
}

// @0x1428fb800
void MathCtorFunction::Max(const FnCall& fn)
{
    Number a = fn.Arg(0).ToNumber(fn.Env);
    Number b = fn.Arg(1).ToNumber(fn.Env);
    fn.Result->SetNumber(a > b ? a : b);
}

// @0x1428fb8d0
void MathCtorFunction::Min(const FnCall& fn)
{
    Number a = fn.Arg(0).ToNumber(fn.Env);
    Number b = fn.Arg(1).ToNumber(fn.Env);
    fn.Result->SetNumber(a < b ? a : b);
}

// @0x1428fb9a0
void MathCtorFunction::Pow(const FnCall& fn)
{
    Number base     = fn.Arg(0).ToNumber(fn.Env);
    Number exponent = fn.Arg(1).ToNumber(fn.Env);
    fn.Result->SetNumber(pow(base, exponent));
}

// Uniform in [0, 1].
// @0x1428fba80
void MathCtorFunction::Random(const FnCall& fn)
{
    MovieImpl* proot = ((DisplayObjectBase*)fn.Env->Target)->GetMovieImpl();
    fn.Result->SetNumber(Number(Math::GetNextRandom(proot)) / Number(0xFFFFFFFFu));
}

// @0x1428fbae0
void MathCtorFunction::Round(const FnCall& fn)
{
    fn.Result->SetNumber(floor(fn.Arg(0).ToNumber(fn.Env) + 0.5));
}

}}} // namespace Scaleform::GFx::AS2
