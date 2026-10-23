// Recovered CRI Movie decoder and timing helpers from MapleStory2.exe, written from the executable's behavior.
// The CRI Movie 3.07 library was built with VS2008 SP1; this unit is functional under our VS2017 toolset.
// MS2-UNIT: sfr_cri_03
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140039ea8-0x140046a1c .text$mn
// MS2-RANGE: 0x142ccb000-0x142ccd143 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/cri/cri_movie.h"
#include <windows.h>

// ==== CRI critical-section helpers ================================================================================

// MS2-FUNCTIONAL: CRI Base was built with VS2008; this wrapper reproduces its aligned storage and initialization.
// @0x140039ea8
void* criCs_Create(void* work, CriSint32 size)
{
    memset(work, 0, (size_t)size);
    uintptr_t aligned = (uintptr_t)work;
    while ((aligned & 7) != 0)
        ++aligned;
    LPCRITICAL_SECTION section = (LPCRITICAL_SECTION)aligned;
    InitializeCriticalSection(section);
    return section;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; this wrapper destroys and clears the caller's lock storage.
// @0x140039f00
void criCs_Destroy(LPCRITICAL_SECTION section)
{
    DeleteCriticalSection(section);
    memset(section, 0, 0x30);
}

// MS2-FUNCTIONAL: the CRI lock helper tracks recursive depth and its owning thread around EnterCriticalSection.
// @0x140039f50
void FUN_140039f50(LPCRITICAL_SECTION section)
{
    EnterCriticalSection(section);
    CriSint32* depth = (CriSint32*)((CriUint8*)section + 0x2c);
    ++*depth;
    if (*depth == 1)
        *(DWORD*)((CriUint8*)section + 0x28) = GetCurrentThreadId();
}

// MS2-FUNCTIONAL: the CRI lock helper clears its owner at the outermost exit and then leaves the section.
// @0x140039f8c
void FUN_140039f8c(LPCRITICAL_SECTION section)
{
    CriSint32* depth = (CriSint32*)((CriUint8*)section + 0x2c);
    --*depth;
    if (*depth == 0)
        *(DWORD*)((CriUint8*)section + 0x28) = 0;
    LeaveCriticalSection(section);
}

// ==== CRI UTF heap callback helpers ================================================================================

// MS2-FUNCTIONAL: this callback forwarder uses the executable's two-word heap interface.
// @0x14003a0d0
void criUtfHeap_Alloc(void* heap)
{
    void** slots = (void**)heap;
    ((void(__fastcall*)(void*))slots[0])(slots[2]);
}

// MS2-FUNCTIONAL: this callback forwarder uses the executable's three-word UTF heap interface.
// @0x14003a0ec
void FUN_14003a0ec(void* heap)
{
    void** slots = (void**)heap;
    ((void(__fastcall*)(void*))slots[1])(slots[2]);
}

// MS2-FUNCTIONAL: this callback forwarder uses the executable's two-word heap interface.
// @0x14003a184
void FUN_14003a184(void* heap)
{
    void** slots = (void**)heap;
    ((void(__fastcall*)(void*))slots[0])(slots[2]);
}

// ==== CRI UTF runtime table field accessors ========================================================================

static CriUint32 criUtfReadBE32(const CriUint8* p)
{
    return ((CriUint32)p[0] << 24) | ((CriUint32)p[1] << 16) | ((CriUint32)p[2] << 8) | p[3];
}

static CriUint64 criUtfReadBE64(const CriUint8* p)
{
    return ((CriUint64)criUtfReadBE32(p) << 32) | criUtfReadBE32(p + 4);
}

static const CriUint8* criUtfGetRecordField(const CriUtfRtvView* table, CriUint32 row,
                                             CriUint32 field, const CriUtfRtvColumn** column)
{
    const CriUtfRtvColumn* col = &table->Columns[field];
    *column = col;
    if (!col->IsRecordField || row >= table->RecordCount)
        return NULL;
    return table->RecordData + (CriUint32)table->RecordSize * row + col->DataOffset;
}

// MS2-FUNCTIONAL: the CRI table library was built with VS2008; preserve its field-name scan and 0xffffffff sentinel.
// @0x14003a3e0
CriUint32 criUtfRtv_ConvFieldNameToNo(const CriUtfRtvView* table, const CriChar8* name)
{
    for (CriUint32 i = 0; i < table->FieldCount; ++i)
        if (strcmp(name, table->Columns[i].Name) == 0)
            return i;
    return 0xffffffff;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; this accessor reads the table's row count.
// @0x14003a45c
CriUint32 FUN_14003a45c(const CriUtfRtvView* table)
{
    return table->RecordCount;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; field types 0/2/4 read the executable's byte positions.
// @0x14003a460
CriUint8 criUtfRtv_GetDataUint8(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col;
    const CriUint8* p = criUtfGetRecordField(table, row, field, &col);
    if (!p)
    {
        if (col->HasDefault && col->Type >= 0 && col->Type < 6)
            return ((const CriUint8*)&col->DefaultValue)[col->Type == 0 ? 0 : (col->Type == 2 ? 1 : 3)];
        return 0;
    }
    if (col->Type < 0 || col->Type >= 6)
        return 0;
    return p[col->Type == 0 ? 0 : (col->Type == 2 ? 1 : 3)];
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; this accessor decodes stored integers in network byte order.
// @0x14003a58c
CriUint32 criUtfRtv_GetDataUint32(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col;
    const CriUint8* p = criUtfGetRecordField(table, row, field, &col);
    if (!p)
    {
        if (!col->HasDefault || col->Type < 0 || col->Type >= 6)
            return 0;
        const CriUint8* d = (const CriUint8*)&col->DefaultValue;
        return col->Type < 2 ? d[0] : (col->Type < 4 ? *(const CriUint16*)d : *(const CriUint32*)d);
    }
    if (col->Type < 0 || col->Type >= 6)
        return 0;
    if (col->Type < 2)
        return p[0];
    if (col->Type < 4)
        return ((CriUint32)p[0] << 8) | p[1];
    return criUtfReadBE32(p);
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; this accessor reads 64-bit big-endian record fields.
// @0x14003a648
CriUint64 criUtfRtv_GetDataUint64(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col;
    const CriUint8* p = criUtfGetRecordField(table, row, field, &col);
    return p ? criUtfReadBE64(p) : (col->HasDefault ? col->DefaultValue : 0);
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; decode the record's big-endian IEEE single precision bits.
// @0x14003a6e8
CriFloat32 criUtfRtv_GetDataFloat32(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col;
    const CriUint8* p = criUtfGetRecordField(table, row, field, &col);
    CriUint32 bits = p ? criUtfReadBE32(p) : (col->HasDefault ? (CriUint32)col->DefaultValue : 0);
    CriFloat32 value;
    memcpy(&value, &bits, sizeof(value));
    return value;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; decode the record's big-endian IEEE double precision bits.
// @0x14003a754
double criUtfRtv_GetDataFloat64(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col;
    const CriUint8* p = criUtfGetRecordField(table, row, field, &col);
    CriUint64 bits = p ? criUtfReadBE64(p) : (col->HasDefault ? col->DefaultValue : 0);
    double value;
    memcpy(&value, &bits, sizeof(value));
    return value;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; string cells hold a big-endian offset into the table string block.
// @0x14003a7f4
const CriChar8* criUtfRtv_GetDataStr(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col;
    const CriUint8* p = criUtfGetRecordField(table, row, field, &col);
    CriUint32 offset = p ? criUtfReadBE32(p) : (col->HasDefault ? (CriUint32)col->DefaultValue : 0);
    return offset ? (const CriChar8*)(table->StringData + offset) : NULL;
}

// MS2-FUNCTIONAL: the CRI name-based callback resolves its field, then forwards to the corresponding typed accessor.
// @0x14003a85c
CriUint32 FID_conflict_criUtfRtv_GetDataSint32Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriUint32 field = criUtfRtv_ConvFieldNameToNo(table, name);
    return field == 0xffffffff ? 0 : criUtfRtv_GetDataUint32(table, row, field);
}

// MS2-FUNCTIONAL: this second CRI callback has the same executable body and forwards the resolved field to uint32.
// @0x14003a894
CriUint32 FUN_14003a894(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriUint32 field = criUtfRtv_ConvFieldNameToNo(table, name);
    return field == 0xffffffff ? 0 : criUtfRtv_GetDataUint32(table, row, field);
}

// MS2-FUNCTIONAL: the CRI name-based callback resolves the field before reading a float.
// @0x14003a8cc
CriFloat32 criUtfRtv_GetDataFload32Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriUint32 field = criUtfRtv_ConvFieldNameToNo(table, name);
    return field == 0xffffffff ? 0 : criUtfRtv_GetDataFloat32(table, row, field);
}

// MS2-FUNCTIONAL: the CRI name-based callback resolves the field before reading a double.
// @0x14003a904
double criUtfRtv_GetDataFloat64Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriUint32 field = criUtfRtv_ConvFieldNameToNo(table, name);
    return field == 0xffffffff ? 0 : criUtfRtv_GetDataFloat64(table, row, field);
}

// MS2-FUNCTIONAL: the CRI name-based callback resolves the field before reading a string.
// @0x14003a940
const CriChar8* criUtfRtv_GetDataStrFn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriUint32 field = criUtfRtv_ConvFieldNameToNo(table, name);
    return field == 0xffffffff ? NULL : criUtfRtv_GetDataStr(table, row, field);
}

// MS2-FUNCTIONAL: the CRI name-based callback resolves the field before reading a byte.
// @0x14003a978
CriUint8 criUtfRtv_GetDataUint8Fn(const CriUtfRtvView* table, CriUint32 row, const CriChar8* name)
{
    CriUint32 field = criUtfRtv_ConvFieldNameToNo(table, name);
    return field == 0xffffffff ? 0 : criUtfRtv_GetDataUint8(table, row, field);
}
