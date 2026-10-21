// Recovered Scaleform 4.1.18 GFx: small value types shared across GFx.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_TYPES_H
#define MS2_SF_GFX_TYPES_H

#include "../kernel/sf_types.h"

namespace Scaleform { namespace GFx {

// Three state flag (not set / true / false), 1 byte.
class Bool3W
{
public:
    enum
    {
        B3W_Undefined,
        B3W_True,
        B3W_False
    };

    UByte Value;

    Bool3W() : Value(B3W_Undefined) {}
    Bool3W(bool v) : Value((UByte)(v ? B3W_True : B3W_False)) {}

    bool IsDefined() const { return Value != B3W_Undefined; }
    bool IsTrue() const    { return Value == B3W_True; }
    bool IsFalse() const   { return Value == B3W_False; }
};

}} // namespace Scaleform::GFx

#endif
