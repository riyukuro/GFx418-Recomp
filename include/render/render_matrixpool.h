// Recovered Scaleform 4.1.18 Render: the matrix pool (Render_MatrixPool). Cache nodes keep their final matrices
// (2D or 3D, plus optional color transform / texture matrices / user data) in pooled blocks reached through a
// handle; only the handle side the tree cache nodes use is declared here.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// A block starts with a 16-byte DataHeader; its elements follow in 16-byte units at the offsets the format's row of
// MatrixElementSizeTable (0x143a2fc60, 5 bytes per row) gives. SetMatrix2D 0x1426ba4c0 and SetTextureMatrix
// 0x1426ba5e0 are out of line in the matrix pool TU.
#ifndef MS2_SF_RENDER_MATRIXPOOL_H
#define MS2_SF_RENDER_MATRIXPOOL_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_matrix4x4.h"

namespace Scaleform { namespace Render {

namespace MatrixPoolImpl {

enum { Pool_DataUnitSize = 16 };

class HMatrixConstants
{
public:
    enum ElementIndex
    {
        Element_Cxform   = 0,
        Element_T0       = 1,
        Element_T1       = 2,
        Element_UserData = 3,
        Element_Matrix   = 4
    };
    enum FormatBits
    {
        Has_Cxform   = 1 << Element_Cxform,
        Has_T0       = 1 << Element_T0,
        Has_T1       = 1 << Element_T1,
        Has_UserData = 1 << Element_UserData,
        Has_3D       = 1 << Element_Matrix,
        Has_2D       = 0
    };
    enum { Has_TableSize = 16, Has_TableMask = Has_TableSize - 1 };

    // unit offsets of the elements of one format (the matrix last)
    struct ElementsInfo
    {
        UByte Offsets[Element_Matrix + 1];
    };
    static ElementsInfo MatrixElementSizeTable[Has_TableSize];
};

struct EntryHandle;

// the head of a pooled block
class DataHeader : public HMatrixConstants
{
public:
    EntryHandle* pHandle;
    UInt32       RefCount;
    SInt16       DataPageOffset;
    UByte        UnitSize;
    UByte        Format;

    // (appended for sfr_render_04f) a block is freed with its last handle reference
    void   AddRef() { RefCount++; }
    void   Release();   // 0x1426ba340

    UByte* GetDataStart() { return (UByte*)this + Pool_DataUnitSize; }
    void*  GetData(ElementIndex index)
    {
        return GetDataStart() + MatrixElementSizeTable[Format & Has_TableMask].Offsets[index] * Pool_DataUnitSize;
    }
    Matrix2F* GetMatrixPtr()   { return (Matrix2F*)GetData(Element_Matrix); }
    Matrix3F* GetMatrix3DPtr() { return (Matrix3F*)GetData(Element_Matrix); }
};

// the stable indirection to a block (blocks move when the pool compacts)
struct EntryHandle
{
    DataHeader* pHeader;

    Matrix2F* GetMatrixPtr()   { return pHeader->GetMatrixPtr(); }
    Matrix3F* GetMatrix3DPtr() { return pHeader->GetMatrix3DPtr(); }
    unsigned  GetFormatBits() const { return pHeader->Format; }

    void      AddRef()  { pHeader->AddRef(); }
    void      Release() { pHeader->Release(); }
};

class HMatrix : public HMatrixConstants
{
public:
    EntryHandle* pHandle;

    // (appended for sfr_render_04f) handles are reference counted; the shared null handle (0x143a2fcb0) is not
    static EntryHandle NullHandle;

    HMatrix() : pHandle(&NullHandle) { }
    HMatrix(const HMatrix& other) : pHandle(other.pHandle)
    {
        if (pHandle != &NullHandle)
            pHandle->AddRef();
    }
    ~HMatrix()
    {
        if (pHandle != &NullHandle)
            pHandle->Release();
    }
    void operator=(const HMatrix& other);   // 0x1426b9e00

    void Clear()
    {
        if (pHandle != &NullHandle)
        {
            pHandle->Release();
            pHandle = &NullHandle;
        }
    }
    bool IsNull() const { return pHandle == &NullHandle; }

    void SetMatrix2D(const Matrix2F& m);
    void SetTextureMatrix(const Matrix2F& m, unsigned index);

    unsigned GetFormatBits() const { return pHandle->GetFormatBits(); }
    bool     Has3D() const         { return (GetFormatBits() & Has_3D) != 0; }

    const Matrix2F& GetMatrix2D() const { return *pHandle->GetMatrixPtr(); }
    const Matrix3F& GetMatrix3D() const
    {
        if (!Has3D())
            return Matrix3F::Identity;
        return *pHandle->GetMatrix3DPtr();
    }
};

} // namespace MatrixPoolImpl

using MatrixPoolImpl::HMatrix;

}} // namespace Scaleform::Render

#endif
