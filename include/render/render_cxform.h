// Recovered Scaleform 4.1.18 Render: color transform (per-channel multiply row, then add row; RGBA order).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_CXFORM_H
#define MS2_SF_RENDER_CXFORM_H

#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform { namespace Render {

class Cxform
{
public:
    __declspec(align(16)) float M[2][4]; // [multiply, add][R, G, B, A]; the add row is in 0..1 units

    enum NoInitType { NoInit };

    Cxform();
    Cxform(NoInitType) {}

    // c applied after this / before this
    void Append(const Cxform& c);
    void Prepend(const Cxform& c);
    void SetToAppend(const Cxform& c0, const Cxform& c1);

    // the add row from 0..255 to 0..1
    void Normalize();

    void SetIdentity();
    bool IsIdentity() const;
    bool operator==(const Cxform& x) const;
    bool operator!=(const Cxform& x) const { return !(x == *this); }

    bool RequiresBlend() const { return M[0][3] < 1.0f; }
};

}} // namespace Scaleform::Render

#endif
