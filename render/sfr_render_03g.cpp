// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 COMDAT leftovers inside the queue
// ranges of sfr_render_03: three deleting destructors (a bare ref-counted object, a socket buffer, an array of
// counted pointers), the Array Reserve instances for 0x18- and 8-byte elements and the out-of-line copy of
// Matrix2x4::SetRectToParl. Raw-layout free functions under the exe's own FUN_<va> names.
// Sub-unit of queue unit sfr_render_03 (see sfr_render_03d for the TU these sit between).
// MS2-UNIT: sfr_render_03g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142620160-0x1426202f0 .text$mn
// MS2-RANGE: 0x142623d00-0x142624020 .text$mn
// MS2-RANGE: 0x14262ce60-0x14262cfb0 .text$mn
// MS2-FUNCTIONAL: raw-layout transcriptions of the exe's template instances; the algorithms and effects match.

#include "../gfx/sfr_gfx_07raw.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"

namespace Scaleform { namespace GFx {

extern char DAT_14318efe8[];

void FUN_14257db40(void*);
void FUN_14015b310(void*, UPInt);

static inline void RawDeleteBranch(void* self, unsigned flags, UPInt size)
{
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, size);
    }
}

// @0x142620160
void* FUN_142620160(void* self, unsigned flags)
{
    RawField<void*>(self, 0) = DAT_14318efe8;
    FUN_14257db40(self);
    RawDeleteBranch(self, flags, 0x10);
    return self;
}

// A buffer pointer at +0x10 that is freed with the object.
// @0x1426201d0
void* FUN_1426201d0(void* self, unsigned flags)
{
    Memory::Free(RawField<void*>(self, 0x10));
    FUN_14257db40(self);
    RawDeleteBranch(self, flags, 0x28);
    return self;
}

// An array of counted pointers (data at +0x30, size at +0x38).
// @0x142620240
void* FUN_142620240(void* self, unsigned flags)
{
    U size = RawField<U>(self, 0x38);
    void** p = (void**)RawField<U>(self, 0x30) + (size - 1);
    for (; size != 0; size--, p--)
    {
        if (*p)
            FUN_14257dcb0(*p);
    }
    Memory::Free(RawField<void*>(self, 0x30));
    FUN_14257db40(self);
    RawDeleteBranch(self, flags, 0x48);
    return self;
}

// Array::Reserve for POD-like elements: capacity rounded up to four, freed at zero. The exe keeps one full copy per
// instance.
#define RAW_RESERVE(name, Elem)                                                                  \
    void name(U* array, void* heapOwner, U n)                                                    \
    {                                                                                            \
        if (n == 0)                                                                              \
        {                                                                                        \
            if (array[0])                                                                        \
            {                                                                                    \
                Memory::Free((void*)array[0]);                                                   \
                array[0] = 0;                                                                    \
                array[2] = 0;                                                                    \
                return;                                                                          \
            }                                                                                    \
            array[2] = 0;                                                                        \
            return;                                                                              \
        }                                                                                        \
        U cap = (n + 3) & ~3ULL;                                                                 \
        if (array[0])                                                                            \
        {                                                                                        \
            array[0] = (U)Memory::Realloc((void*)array[0], cap * Elem);                          \
            array[2] = cap;                                                                      \
            return;                                                                              \
        }                                                                                        \
        array[0] = (U)Memory::AllocAutoHeap(heapOwner, cap * Elem, AllocInfo(2, 0, 0));          \
        array[2] = cap;                                                                          \
    }

// @0x142623d00
RAW_RESERVE(FUN_142623d00, 0x18)
// @0x142623da0
RAW_RESERVE(FUN_142623da0, 8)
// @0x142623e40
RAW_RESERVE(FUN_142623e40, 8)
// @0x142623ee0
RAW_RESERVE(FUN_142623ee0, 8)
// @0x142623f80
RAW_RESERVE(FUN_142623f80, 8)

// The out-of-line expansion of Matrix2x4<float>::SetRectToParl.
// @0x14262ce60
Render::Matrix2x4<float>* FUN_14262ce60(Render::Matrix2x4<float>* m, float x1, float y1, float x2, float y2, const float* parl)
{
    return &m->SetRectToParl(x1, y1, x2, y2, parl);
}

}} // namespace Scaleform::GFx
