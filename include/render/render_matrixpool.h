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
#include "ms2/scaleform/include/render/render_cxform.h"
#include "ms2/scaleform/include/render/render_stats.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_refcount.h"

namespace Scaleform { namespace Render {

namespace MatrixPoolImpl {

enum { Pool_DataUnitSize = 16 };
enum { Pool_UserDataUnits = 4, Pool_UserDataSize = Pool_DataUnitSize * Pool_UserDataUnits };   // (appended for sfr_render_06b)

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

    // (appended for sfr_render_06b) the optional elements, and the page / next block a header sits in / before
    Cxform*   GetCxformPtr()                     { return (Cxform*)GetData(Element_Cxform); }
    void*     GetUserDataPtr()                   { return GetData(Element_UserData); }
    Matrix2F* GetTextureMatrixPtr(ElementIndex e) { return (Matrix2F*)GetData(e); }
    bool      HasElement(ElementIndex e) const    { return (Format & (1 << e)) != 0; }
    struct DataPage* GetDataPage()                { return (struct DataPage*)((UByte*)this + DataPageOffset); }
    DataHeader* Next(unsigned units)              { return (DataHeader*)((UByte*)this + units * Pool_DataUnitSize); }
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

    // (appended for sfr_render_06b) a free handle reuses its pointer as the free-list link; handle pages are
    // 2 KB aligned, so the page is the handle's address with the low 11 bits cleared
    EntryHandle*& FreeLink()  { return *(EntryHandle**)&pHeader; }
    struct HandlePage* GetHandlePage() { return (struct HandlePage*)((UPInt)this & ~(UPInt)0x7ff); }
    void      ReleaseHandle();   // 0x1426ba390
    inline void ChangeFormat(unsigned formatBits);
    void      AddElement(HMatrixConstants::ElementIndex e) { ChangeFormat(pHeader->Format | (1 << e)); }
    bool      HasElement(HMatrixConstants::ElementIndex e) const { return pHeader->HasElement(e); }
    Cxform*   GetCxformPtr()                     { return pHeader->GetCxformPtr(); }
    void*     GetUserDataPtr()                   { return pHeader->GetUserDataPtr(); }
    Matrix2F* GetTextureMatrixPtr(HMatrixConstants::ElementIndex e) { return pHeader->GetTextureMatrixPtr(e); }
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
    // (appended for sfr_render_06b)
    explicit HMatrix(EntryHandle* h) : pHandle(h) { }
    void SetMatrix3D(const Matrix3F& m);              // 0x1426ba520
    void SetCxform(const Cxform& cx);                 // 0x1426ba420
    void SetUserData(const void* data, UPInt size);   // 0x1426ba6d0
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

// ---------------------------------------------------------------------------------------------------------------
// (appended for sfr_render_06b) the pool side: handle pages, data pages and the pool itself (Render_MatrixPool).

class MatrixPool;
class EntryHandleTable;

// A 2 KB aligned page of handles; free handles are chained through their pointer.
struct HandlePageBase : ListNode<HandlePageBase>
{
    unsigned          UseCount;     // +0x10 handles handed out
    EntryHandle*      pFreeList;    // +0x18
    EntryHandleTable* pTable;       // +0x20
};
struct HandlePage : HandlePageBase
{
    enum { PageBytes = 2048 - 16, PageAlign = 2048,
           EntryCount = (PageBytes - sizeof(HandlePageBase)) / sizeof(EntryHandle) };
    EntryHandle Entries[EntryCount];
};

// Hands out handles from pages that still have free ones.
class EntryHandleTable
{
public:
    MemoryHeap*                      pHeap;               // +0x00
    MatrixPool*                      pPool;               // +0x08
    List<HandlePage, HandlePageBase> FullPages;           // +0x10
    List<HandlePage, HandlePageBase> PartiallyFreePages;  // +0x20

    EntryHandleTable(MemoryHeap* heap, MatrixPool* pool) : pHeap(heap), pPool(pool) { }
    EntryHandle* AllocEntry(DataHeader* header = 0);   // 0x1426ba080
private:
    bool         allocEntryPage();                      // 0x1426ba990
};

// A 4 KB page of blocks: allocation takes from the tail, freed blocks leave holes ("middle") until a squeeze.
struct DataPage : ListNode<DataPage>
{
    enum { PageBytes = 4096 };
    MatrixPool* pPool;        // +0x10
    UInt16      FreeTail;     // +0x18
    UInt16      FreeMiddle;   // +0x1a

    static UPInt DataBytes()   { return PageBytes - sizeof(DataPage); }
    UByte*      Begin()        { return (UByte*)(this + 1); }
    DataHeader* First()        { return (DataHeader*)Begin(); }
    DataHeader* TailStart()    { return (DataHeader*)(Begin() + DataBytes() - FreeTail); }
    DataHeader* End()          { return (DataHeader*)(Begin() + DataBytes()); }
};

class MatrixPool : public RefCountBase<MatrixPool, StatRender_MatrixPool_Mem>, public HMatrixConstants
{
public:
    enum SqueezeType { Squeeze_Incremental, Squeeze_Full, Squeeze_Force };

    MatrixPool(MemoryHeap* heap);   // 0x1426b9cd0
    ~MatrixPool();                  // 0x1426b9d50

    HMatrix CreateMatrix(unsigned formatBits = Has_2D);                                            // 0x1426ba240
    HMatrix CreateMatrix(const Matrix2F& m, unsigned formatBits = Has_2D);                         // 0x1426ba1b0
    HMatrix CreateMatrix(const Matrix3F& m, unsigned formatBits = Has_3D);                         // 0x1426ba210
    HMatrix CreateMatrix(const Matrix2F& m, const Cxform& cx, unsigned formatBits = Has_Cxform);  // 0x1426ba180
    HMatrix CreateMatrix(const Matrix3F& m, const Cxform& cx, unsigned formatBits = Has_3D | Has_Cxform);   // 0x1426ba1e0
    bool    MemorySqueeze(SqueezeType type);                                                       // 0x1426ba270

    MemoryHeap*      pHeap;            // +0x10
    UPInt            AllocatedSpace;   // +0x18 data bytes of all pages
    UPInt            DataPageCount;    // +0x20
    UPInt            FreedSpace;       // +0x28 bytes in holes
    EntryHandleTable HandleTable;      // +0x30
    List<DataPage>   DataPages;        // +0x60
    DataPage*        pAllocPage;       // +0x70
    DataPage*        pSqueezePage;     // +0x78 where an incremental squeeze resumes
    DataPage*        pLastFreedPage;   // +0x80 one cached empty page

private:
    friend struct EntryHandle;
    EntryHandle* createMatrixHelper(const Matrix2F& m, const Cxform& cx, unsigned formatBits);   // 0x1426bab60
    EntryHandle* createMatrixHelper(const Matrix3F& m, const Cxform& cx, unsigned formatBits);   // 0x1426bad00
    bool         allocDataPage();                                      // 0x1426ba900
    void         freeDataPage(DataPage* page);                         // 0x1426bafa0
    bool         ensureAllocSpace(UPInt size);                         // 0x1426bae90
    DataHeader*  allocData(UPInt size, EntryHandle* handle = 0);       // 0x1426ba780
    EntryHandle* allocMatrixData(unsigned formatBits);                 // 0x1426baa10
    bool         reallocMatrixData(EntryHandle* handle, unsigned formatBits);   // 0x1426bb040
    bool         squeezeMemoryRange(DataPage* from, DataPage* to, SqueezeType type);   // 0x1426bb3e0
};

// A handle reaches its pool through its page's table (inline in the setters).
inline void EntryHandle::ChangeFormat(unsigned formatBits)
{
    GetHandlePage()->pTable->pPool->reallocMatrixData(this, formatBits);
}

} // namespace MatrixPoolImpl

using MatrixPoolImpl::HMatrix;

}} // namespace Scaleform::Render

#endif
