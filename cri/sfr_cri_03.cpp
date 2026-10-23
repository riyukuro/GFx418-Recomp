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
#include <cstring>

extern "C" CriSint32 DAT_143ba9d28;
extern "C" const char* DAT_143ba9d08;
extern "C" const char* DAT_143ba9d20;
extern "C" void* DAT_143b15f60;
extern "C" CriUint8 DAT_143b27c80[];
extern "C" CriUint32 DAT_143b27c60;
extern "C" CriUint32 DAT_143b27c6c;
extern "C" CriUint64 DAT_143b27c70;
void FUN_1400532b0(void);
void FUN_1400532d0(void);
void FUN_14003b2ac(void*, CriSint32, void*, CriUint32);

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
            return ((const CriUint8*)&col->DefaultValue[0])[col->Type == 0 ? 0 : (col->Type == 2 ? 1 : 3)];
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
        const CriUint8* d = (const CriUint8*)&col->DefaultValue[0];
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
    return p ? criUtfReadBE64(p) : (col->HasDefault ? col->DefaultValue[0] : 0);
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; decode the record's big-endian IEEE single precision bits.
// @0x14003a6e8
CriFloat32 criUtfRtv_GetDataFloat32(const CriUtfRtvView* table, CriUint32 row, CriUint32 field)
{
    const CriUtfRtvColumn* col;
    const CriUint8* p = criUtfGetRecordField(table, row, field, &col);
    CriUint32 bits = p ? criUtfReadBE32(p) : (col->HasDefault ? (CriUint32)col->DefaultValue[0] : 0);
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
    CriUint64 bits = p ? criUtfReadBE64(p) : (col->HasDefault ? col->DefaultValue[0] : 0);
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
    CriUint32 offset = p ? criUtfReadBE32(p) : (col->HasDefault ? (CriUint32)col->DefaultValue[0] : 0);
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

// MS2-FUNCTIONAL: this decoder copies the field representation into the CRI's tagged 24-byte cell value.
// @0x14003a9e4
void criUtfRtv_GetCellValFromAddr(const CriUtfRtvView* table, const CriUint8* address,
                                  CriSint32 type, CriUtfRtvCell* cell)
{
    cell->Type = (CriUint8)type;
    switch (type)
    {
    case 0: case 1:
        cell->Value[0] = address[0];
        break;
    case 2: case 3:
        cell->Value[0] = address[0]; cell->Value[1] = address[1];
        break;
    case 4: case 5: case 8:
        memcpy(cell->Value, address, 4);
        break;
    case 6: case 7: case 9:
        memcpy(cell->Value, address, 8);
        break;
    case 10:
    {
        CriUint32 offset = criUtfReadBE32(address);
        *(CriUint64*)cell->Value = offset ? (CriUint64)(table->StringData + offset) : 0;
        break;
    }
    case 11:
    {
        CriUint32 offset = criUtfReadBE32(address);
        *(CriUint64*)cell->Value = (CriUint64)(table->BlobData + offset);
        *(CriUint32*)(cell->Value + 8) = criUtfReadBE32(address + 4);
        break;
    }
    case 12:
        memcpy(cell->Value, address, 16);
        break;
    default:
        break;
    }
}

// MS2-FUNCTIONAL: this accessor copies the column's default triple or decodes its row cell into the caller record.
// @0x14003af50
CriBool criUtfRtv_GetCellVal(const CriUtfRtvView* table, CriUint32 row, CriUint32 field, CriUtfRtvCell* cell)
{
    const CriUtfRtvColumn* col = &table->Columns[field];
    if (!col->IsRecordField || row >= table->RecordCount)
        memcpy(cell, col->DefaultValue, sizeof(col->DefaultValue));
    else
        criUtfRtv_GetCellValFromAddr(table, table->RecordData + (CriUint32)table->RecordSize * row + col->DataOffset,
                                     col->Type, cell);
    return 1;
}

// MS2-FUNCTIONAL: the table's 16/32-bit signed fields are summed after rounding each value up to the requested alignment.
// @0x14003aca8
CriSint32 criUtfRtv_SumWithAlignment32(const CriUtfRtvView* table, CriUint32 firstRow, CriSint32 count,
                                       CriUint32 field, CriSint32 alignment)
{
    const CriUtfRtvColumn* col = &table->Columns[field];
    CriSint32 rounded = alignment - 1;
    CriUint32 mask = (CriUint32)-(CriSint32)alignment & ~((CriUint32)alignment - 1);
    CriSint32 sum = 0;
    if (col->Type == 2 || col->Type == 4)
    {
        if (col->IsRecordField)
        {
            const CriUint8* p = table->RecordData + (CriUint32)table->RecordSize * firstRow + col->DataOffset;
            do
            {
                CriUint32 value = col->Type == 2 ? (((CriUint32)p[0] << 8) | p[1]) : criUtfReadBE32(p);
                sum += (CriSint32)((value + rounded) & mask);
                p += table->RecordSize;
            } while (--count >= 0);
            return sum;
        }
        CriUint32 value = col->Type == 2 ? (CriUint16)col->DefaultValue[0] : (CriUint32)col->DefaultValue[0];
        return (CriSint32)((value + rounded) & mask) * count;
    }
    return 0;
}

// MS2-FUNCTIONAL: this 64-bit variant shares the executable's row iteration and alignment rounding behavior.
// @0x14003adac
CriUint64 FUN_14003adac(const CriUtfRtvView* table, CriUint32 firstRow, CriSint32 count,
                        CriUint32 field, CriSint32 alignment)
{
    return (CriUint64)(CriUint32)criUtfRtv_SumWithAlignment32(table, firstRow, count, field, alignment);
}

// MS2-FUNCTIONAL: parse USF chunk ID and size as network-order dwords, requiring the minimum 16-byte header.
// @0x14003b358
CriBool criUsfCmn_GetChunkIdAndSIze(const CriUint8* data, CriUint32 size, CriUint32* id, CriUint32* chunkSize)
{
    if (size < 0x10)
    {
        *id = 0;
        *chunkSize = 0;
        return 0;
    }
    *id = criUtfReadBE32(data);
    *chunkSize = criUtfReadBE32(data + 4);
    return 1;
}

// MS2-FUNCTIONAL: create a UTF runtime table using the CRI heap callback convention.
// @0x14003b348
void criUtfRtv_Create(void* heap, void* table, CriUint32 size)
{
    FUN_14003b2ac(heap, 1, table, size);
}

// MS2-FUNCTIONAL: decode the executable's 0x24-byte USF standard header fields.
// @0x14003b3fc
CriUint32 criUsfCmn_ParseUsfHeaderStd(const CriUint8* data, CriUint32 size, CriUsfStandardHeader* header)
{
    CriUint8 headerSize = data[9];
    if (size <= 0x0f || headerSize == 0 || headerSize > size)
        return 0;
    CriUint8* out = header->Data;
    memcpy(out, data, 8);
    out[8] = data[8]; out[9] = data[9];
    out[10] = data[10]; out[11] = data[11];
    out[12] = data[12]; out[13] = data[13]; out[14] = data[14];
    out[15] = data[15] & 3;
    out[16] = data[15] >> 4;
    memcpy(out + 20, data + 0x10, 16);
    return headerSize;
}

// MS2-FUNCTIONAL: return the payload after the variable USF header and remove its embedded header-size fields.
// @0x14003b674
const CriUint8* criUsfCmn_GetContents(const CriUint8* data, CriUint32 size, CriSint32* contentSize)
{
    CriUint32 id, chunkSize;
    *contentSize = 0;
    if (!criUsfCmn_GetChunkIdAndSIze(data, size, &id, &chunkSize))
        return NULL;
    CriUint8 headerSize = data[9];
    if (size < 0x10 || headerSize == 0)
        return NULL;
    *contentSize = (CriSint32)(chunkSize - ((CriUint32)data[10] << 8 | data[11]) - headerSize);
    return data + headerSize + 8;
}

// MS2-FUNCTIONAL: CRI Movie computes the caller's decoder work size from the requested handle count.
// @0x14003bf30
CriSint32 criVmpv_CalcMovieHandleWork(CriSint32 count)
{
    return count * 0x8000 + 0x2084;
}

// MS2-FUNCTIONAL: return the configured movie handle limit or the default limit of sixteen.
// @0x14003c030
CriUint32 criVmpv_GetMaxNumberOfHandles(void)
{
    return DAT_143b27c70 == 0 ? 0x10 : DAT_143b27c6c;
}

// MS2-FUNCTIONAL: expose the configured movie handle count and work buffer.
// @0x14003c060
void* FUN_14003c060(CriUint32* count)
{
    *count = DAT_143b27c6c;
    return (void*)(uintptr_t)DAT_143b27c70;
}

// MS2-FUNCTIONAL: include the configured internal frame pool in the requested count.
// @0x14003c350
CriSint32 decideInternalFramePoolNum(CriSint32 count)
{
    return count == 0 ? (CriSint32)DAT_143b27c60 : count - 1 + (CriSint32)DAT_143b27c60;
}

// MS2-FUNCTIONAL: publish the primary video and alpha output buffers on a movie handle.
// @0x14003d4b0
void FUN_14003d4b0(void* handle, void* videoBuffer, void* alphaBuffer)
{
    memcpy((CriUint8*)handle + 0x200, &videoBuffer, sizeof(videoBuffer));
    memcpy((CriUint8*)handle + 0x208, &alphaBuffer, sizeof(alphaBuffer));
}

// MS2-FUNCTIONAL: publish the secondary video and alpha output buffers on a movie handle.
// @0x14003d500
void FUN_14003d500(void* handle, void* videoBuffer, void* alphaBuffer)
{
    memcpy((CriUint8*)handle + 0x210, &videoBuffer, sizeof(videoBuffer));
    memcpy((CriUint8*)handle + 0x218, &alphaBuffer, sizeof(alphaBuffer));
}

// MS2-FUNCTIONAL: return the frame pointer currently stored in a CRI VMPV handle.
// @0x14003d940
void* FUN_14003d940(void* handle)
{
    void* frame;
    memcpy(&frame, (CriUint8*)handle + 0x180, sizeof(frame));
    return frame;
}

// MS2-FUNCTIONAL: mark the VMPV handle's frame-ready flag.
// @0x14003d970
void FUN_14003d970(void* handle)
{
    CriUint32 ready = 1;
    memcpy((CriUint8*)handle + 0x20, &ready, sizeof(ready));
}

// MS2-FUNCTIONAL: return the number of picture records held by a video decoder.
// @0x14003d9a0
CriUint32 criVdecCmn_GetNumPictureData(const void* decoder)
{
    CriUint32 count;
    memcpy(&count, (const CriUint8*)decoder + 0x188, sizeof(count));
    return count;
}

// MS2-FUNCTIONAL: normalize the movie player's two 64-entry audio-track maps and copy the active entries.
// @0x14003b720
void FUN_14003b720(CriMvSubAudioTrackState* state, CriSint32 count,
                   const CriSint32* trackIds, const CriSint32* trackValues)
{
    memset(state->TrackIds, 0, sizeof(state->TrackIds));
    memset(state->TrackValues, 0, sizeof(state->TrackValues));
    if (count > 64)
        count = 64;
    state->TrackCount = count;
    for (CriSint32 i = 0; i < count; ++i)
    {
        CriSint32 id = trackIds[i];
        CriSint32 value = trackValues[i];
        state->TrackIds[i] = id == -1 ? 0x5a5a5a5a : id;
        state->TrackValues[i] = value == 0x8000000 ? 0x5a5a5a5a : value;
    }
}

// MS2-FUNCTIONAL: search the table's 32-bit record field in row order and return its first matching row.
// @0x14003b168
CriUint32 criUtfRtv_SearchRecNoByUint32(const CriUtfRtvView* table, CriUint32 field, CriUint32 value)
{
    const CriUtfRtvColumn* col = &table->Columns[field];
    if (!col->IsRecordField || col->Type != 4)
        return 0xffffffff;
    for (CriUint32 row = 0; row < table->RecordCount; ++row)
        if (criUtfRtv_GetDataUint32(table, row, field) == value)
            return row;
    return 0xffffffff;
}

// MS2-FUNCTIONAL: search the table's string record field in row order and return its first matching row.
// @0x14003b094
CriUint32 criUtfRtv_SearchRecNoByStr(const CriUtfRtvView* table, CriUint32 field, const CriChar8* value)
{
    const CriUtfRtvColumn* col = &table->Columns[field];
    if (!col->IsRecordField || col->Type != 10)
        return 0xffffffff;
    for (CriUint32 row = 0; row < table->RecordCount; ++row)
    {
        const CriChar8* candidate = criUtfRtv_GetDataStr(table, row, field);
        if (candidate && strcmp(candidate, value) == 0)
            return row;
    }
    return 0xffffffff;
}

// MS2-FUNCTIONAL: these state initializers clear the decoder's four motion-vector components.
// @0x142ccb4f0
void MPVDEC_ResetMv(CriMpvDecoderState* state)
{
    memset(state->MotionVectors, 0, sizeof(state->MotionVectors));
}

// MS2-FUNCTIONAL: reset the three MPEG DC predictors to the executable's midpoint value.
// @0x142ccb500
void MPVDEC_ResetDc(CriMpvDecoderState* state)
{
    state->DcPredictors[0] = 0x400;
    state->DcPredictors[1] = 0x400;
    state->DcPredictors[2] = 0x400;
}

// MS2-FUNCTIONAL: adjust macroblock address and column by 1 minus the supplied run length.
// @0x142ccc580
void mpvumc_SubMbadr(CriMpvDecoderState* state, CriSint32 run)
{
    CriSint32 delta = 1 - run;
    state->MacroblockAddress += delta;
    state->MacroblockColumn += delta;
    while (state->MacroblockColumn < 0)
    {
        state->MacroblockColumn += state->MacroblockWidth;
        --state->MacroblockRow;
    }
}

// MS2-FUNCTIONAL: advance the macroblock column, wrapping to the next row at the row width.
// @0x142ccc5c0
void mpvumc_IncreMbadr(CriMpvDecoderState* state)
{
    if (++state->MacroblockColumn >= state->MacroblockWidth)
    {
        ++state->MacroblockRow;
        state->MacroblockColumn = 0;
    }
    ++state->MacroblockAddress;
}

// MS2-FUNCTIONAL: read the initialized flag stored in the CRI demux object.
// @0x140044f8c
CriSint32 FUN_140044f8c(void* object)
{
    return object ? *((CriUint8*)object + 9) : 0;
}

// MS2-FUNCTIONAL: reset the demux object's secondary state and mark it initialized.
// @0x140044f9c
void FUN_140044f9c(void* object)
{
    *((CriUint8*)object + 10) = 0;
    *((CriUint8*)object + 9) = 1;
}

// MS2-FUNCTIONAL: store the demux object's opaque user-data pointer.
// @0x140044fa8
void FUN_140044fa8(void* object, void* value)
{
    *(void**)((CriUint8*)object + 0x10) = value;
}

// MS2-FUNCTIONAL: clear the demux object's one-byte status flag.
// @0x140044fd8
void FUN_140044fd8(void* object, CriUint8 value)
{
    *((CriUint8*)object + 0xb) = value;
}

// MS2-FUNCTIONAL: mark the demux object's reset flag.
// @0x140044fdc
void FUN_140044fdc(void* object)
{
    *((CriUint8*)object + 10) = 1;
}

// MS2-FUNCTIONAL: decrement CRI's shared demux counter.
// @0x140044ea8
void FUN_140044ea8(void)
{
    --DAT_143ba9d28;
}

// MS2-FUNCTIONAL: lock the object's embedded CRI critical section when present.
// @0x1400459bc
void FUN_1400459bc(void* object)
{
    void* section = *(void**)((CriUint8*)object + 0x10);
    if (section)
        FUN_140039f50((LPCRITICAL_SECTION)section);
}

// MS2-FUNCTIONAL: unlock the object's embedded CRI critical section when present.
// @0x1400459d4
void FUN_1400459d4(void* object)
{
    void* section = *(void**)((CriUint8*)object + 0x10);
    if (section)
        FUN_140039f8c((LPCRITICAL_SECTION)section);
}

// MS2-FUNCTIONAL: lock the ring-buffer object's embedded CRI critical section when present.
// @0x140046014
void FUN_140046014(void* object)
{
    void* section = *(void**)((CriUint8*)object + 0x10);
    if (section)
        FUN_140039f50((LPCRITICAL_SECTION)section);
}

// MS2-FUNCTIONAL: unlock the ring-buffer object's embedded CRI critical section when present.
// @0x14004602c
void FUN_14004602c(void* object)
{
    void* section = *(void**)((CriUint8*)object + 0x10);
    if (section)
        FUN_140039f8c((LPCRITICAL_SECTION)section);
}

// MS2-FUNCTIONAL: call the stream-joint object's first virtual operation.
// @0x140046798
void FUN_140046798(void* object)
{
    (*(void (**)(void*))(*(void**)((CriUint8*)*(void**)object + 8)))(object);
}

// MS2-FUNCTIONAL: call the stream-joint object's second virtual operation.
// @0x1400467a0
void FUN_1400467a0(void* object)
{
    (*(void (**)(void*))(*(void**)((CriUint8*)*(void**)object + 0x10)))(object);
}

// MS2-FUNCTIONAL: call the stream-joint object's third virtual operation.
// @0x1400467a8
void FUN_1400467a8(void* object)
{
    (*(void (**)(void*))(*(void**)((CriUint8*)*(void**)object + 0x18)))(object);
}

// MS2-FUNCTIONAL: call the stream-joint object's fourth virtual operation.
// @0x1400467b0
void FUN_1400467b0(void* object)
{
    (*(void (**)(void*))(*(void**)((CriUint8*)*(void**)object + 0x20)))(object);
}

// MS2-FUNCTIONAL: call the stream-joint object's fifth virtual operation.
// @0x1400467b8
void FUN_1400467b8(void* object)
{
    (*(void (**)(void*))(*(void**)((CriUint8*)*(void**)object + 0x28)))(object);
}

// MS2-FUNCTIONAL: call the stream-joint object's indexed range operation with default bounds.
// @0x140046804
void FUN_140046804(void* object, void* value)
{
    (*(void (**)(void*, CriSint32, CriSint32, void*))(*(void**)((CriUint8*)*(void**)object + 0x10)))(object, 0, -1, value);
}

// MS2-FUNCTIONAL: copy a null-terminated string with the executable's bounded secure CRT helper.
// @0x140046944
char* FUN_140046944(char* dst, size_t size, const char* src)
{
    strcpy_s(dst, size, src);
    return dst;
}

// MS2-FUNCTIONAL: copy a bounded string with the executable's secure CRT helper.
// @0x14004695c
char* FUN_14004695c(char* dst, size_t size, const char* src, size_t count)
{
    strncpy_s(dst, size, src, count);
    return dst;
}

// MS2-FUNCTIONAL: append a bounded string with the executable's secure CRT helper.
// @0x140046974
char* FUN_140046974(char* dst, size_t size, const char* src, size_t count)
{
    strncat_s(dst, size, src, count);
    return dst;
}

// MS2-FUNCTIONAL: append a null-terminated string with the executable's secure CRT helper.
// @0x14004698c
char* FUN_14004698c(char* dst, size_t size, const char* src)
{
    strcat_s(dst, size, src);
    return dst;
}

// MS2-FUNCTIONAL: copy the requested number of bytes with the executable's secure CRT helper.
// @0x1400469f0
void* FUN_1400469f0(void* dst, size_t size, const void* src, size_t count)
{
    memcpy_s(dst, size, src, count);
    return dst;
}

// MS2-FUNCTIONAL: execute the CRI Movie Player manager initialization hook.
// @0x140041ea0
void criMvPlyAmng_Initialize(void)
{
    FUN_1400532b0();
}

// MS2-FUNCTIONAL: execute the CRI Movie Player manager finalization hook.
// @0x140041ec0
void criMvPlyAmng_Finalize(void)
{
    FUN_1400532d0();
}

// MS2-FUNCTIONAL: return the player's shared work-memory size and default alignment.
// @0x1400411e0
void* FUN_1400411e0(CriUint32* size)
{
    *size = 0x10;
    return DAT_143b27c80;
}

// MS2-FUNCTIONAL: publish CRI Base's runtime banner string.
// @0x1400411f8
void FUN_1400411f8(void)
{
    DAT_143ba9d08 = "\nCRI Base/PCx64 Ver.2.21.07 Build:Jan 13 2012 19:02:07\n";
}

// MS2-FUNCTIONAL: forward to the attached object's virtual stop operation when present.
// @0x140041250
void FUN_140041250(void* object)
{
    void** target = *(void***)((CriUint8*)object + 0x10);
    if (target)
        (*(void (**)(void*))(*(void**)((CriUint8*)*target + 0x10)))(*target);
}

// MS2-FUNCTIONAL: forward to the attached object's virtual operation at slot five when present.
// @0x1400412c0
void FUN_1400412c0(void* object)
{
    void** target = *(void***)((CriUint8*)object + 0x10);
    if (target)
        (*(void (**)(void*))(*(void**)((CriUint8*)*target + 0x28)))(*target);
}

// MS2-FUNCTIONAL: forward to the attached object's virtual destroy operation when present.
// @0x140041340
void FUN_140041340(void* object)
{
    void** target = *(void***)((CriUint8*)object + 0x10);
    if (target)
        (*(void (**)(void*))(*(void**)((CriUint8*)*target + 0x40)))(*target);
}

// MS2-FUNCTIONAL: invoke the global heap manager's work-size operation.
// @0x140041d20
CriUint64 FUN_140041d20(void)
{
    void* manager = DAT_143b15f60;
    (*(void (**)(void*))(*(void**)((CriUint8*)*(void**)manager + 0x60)))(manager);
    return 0;
}

// MS2-FUNCTIONAL: release the supplied CRI heap through the global heap manager.
// @0x140041dd0
void FUN_140041dd0(void* heap)
{
    void* manager = DAT_143b15f60;
    (*(void (**)(void*, void*))(*(void**)((CriUint8*)*(void**)manager + 0x60)))(manager, heap);
}

// MS2-FUNCTIONAL: initialize the USF demux runtime banner on first use and increment its reference count.
// @0x140044e84
void FUN_140044e84(void)
{
    if (DAT_143ba9d28 == 0)
        DAT_143ba9d20 = "\nCRI UsfDmx/PCx64 Ver.1.01.03 Build:Jan 13 2012 19:02:04\n";
    ++DAT_143ba9d28;
}
