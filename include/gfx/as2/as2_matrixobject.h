// Recovered Scaleform 4.1.18 GFx AS2: flash.geom.Matrix (a, b, c, d, tx and ty kept as ordinary members).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_MATRIXOBJECT_H
#define MS2_SF_GFX_AS2_MATRIXOBJECT_H

#include "as2_pointobject.h"
#include "../../render/render_matrix2x4.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// createGradientBox scales the box size by this (1 / 1638.4).
const float GASGradientBoxMagicNumber = 1.0f / 1638.4f;

// Out-of-line Matrix2F members the shared render header does not declare (called with the matrix as this).
Render::Matrix2F& Matrix2F_AppendRotation(Render::Matrix2F* m, float radians);     // exe 0x1425f0ec0
void              Matrix2F_SetInverse(Render::Matrix2F* m, const Render::Matrix2F& src); // exe 0x142446cb0

// Matrix2F::Invert on a temporary, with the out-of-line SetInverse.
SF_FORCEINLINE __declspec(safebuffers) Render::Matrix2F& Matrix2F_Invert(Render::Matrix2F&& m)
{
    Matrix2F_SetInverse(&m, Render::Matrix2F(m));
    return m;
}

// this = translation * this
inline Render::Matrix2F& Matrix2F_AppendTranslation(Render::Matrix2F& m, float tx, float ty)
{
    m.Tx() += tx;
    m.Ty() += ty;
    return m;
}

// Matrix instance. 0x68 bytes.
class MatrixObject : public Object
{
public:
    typedef Value GASMatrixArray[6];

    MatrixObject(Environment* penv); // exe 0x14291e790

    // a, b, c, d, tx, ty (missing members read as the identity).
    GASMatrixArray*  GetMatrixAsValuesArray(ASStringContext* psc, GASMatrixArray* marr); // exe 0x14294b630
    Render::Matrix2F GetMatrix(Environment* penv);                                     // exe 0x14294b2e0
    void             SetMatrix(Environment* penv, const Render::Matrix2F& m);          // exe 0x142982370
};

// The flash.geom.Matrix class.
class GASMatrixCtorFunction : public CFunctionObject
{
public:
    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936e50
};

// Matrix.prototype methods.
class MatrixProto
{
public:
    static void ToString(const FnCall& fn);
    static void Clone(const FnCall& fn);
    static void Concat(const FnCall& fn);
    static void CreateBox(const FnCall& fn);
    static void CreateGradientBox(const FnCall& fn);
    static void DeltaTransformPoint(const FnCall& fn);
    static void Identity(const FnCall& fn);
    static void Invert(const FnCall& fn);
    static void Rotate(const FnCall& fn);
    static void Scale(const FnCall& fn);
    static void TransformPoint(const FnCall& fn);
    static void Translate(const FnCall& fn);
};

}}} // namespace Scaleform::GFx::AS2

#endif
