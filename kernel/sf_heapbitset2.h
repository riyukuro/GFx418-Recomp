// Recovered Scaleform GFx 4.1.18: the two-bits-per-block busy map shared by the PT and MH general allocators
// (SF_HeapBitSet2). Each block of 1 << alignShift bytes owns a 2-bit value, 16 blocks per UInt32 word. A busy run
// stores its length at its head (3 = "look further") and, with alignment tracking, its alignment at its tail; free
// runs are all zero at both ends.
#ifndef MS2_SF_KERNEL_HEAPBITSET2_H
#define MS2_SF_KERNEL_HEAPBITSET2_H

#include <string.h>
#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform { namespace Heap {

class BitSet2
{
public:
    // words needed to describe dataSize bytes (rounded up to whole blocks)
    static UPInt GetBitSetSize(UPInt dataSize, UPInt alignShift)
    {
        UPInt alignMask = (UPInt(1) << alignShift) - 1;
        return (((dataSize + alignMask) >> alignShift) + 15) / 16;
    }

    static void Clear(UInt32* buf, UPInt numWords) { memset(buf, 0, sizeof(UInt32) * numWords); }

    SF_INLINE static unsigned GetValue(const UInt32* buf, UPInt idx) { return (buf[idx >> 4] >> (2 * idx & 30)) & 3; }
    SF_INLINE static void     ClearValue(UInt32* buf, UPInt idx) { buf[idx >> 4] &= ~(UInt32(3) << (2 * idx & 30)); }
    SF_INLINE static void     SetValue(UInt32* buf, UPInt idx, unsigned val)
    {
        UPInt wrd = idx >> 4;
        UPInt rem = 2 * idx & 30;
        buf[wrd]  = (buf[wrd] & ~(UInt32(3) << rem)) | (UInt32(val) << rem);
    }

    SF_INLINE static void MarkFree(UInt32* buf, UPInt start, UPInt num)
    {
        ClearValue(buf, start);
        ClearValue(buf, start + num - 1);
    }

    // length encoding at the head of a busy run:
    //   1 -> "1", 2 -> "2", 3..5 -> "3,n-3", 6..37 -> "3,3,a,b,c" (n-6 in base 4), longer -> "3,3,3" + the whole
    //   length in the next full word; the last block of a run longer than 2 is marked 1
    static void MarkBusy(UInt32* buf, UPInt start, UPInt num)
    {
        switch (num)
        {
        case 0:
        case 1:
            SetValue(buf, start, 1);
            return;
        case 2:
            SetValue(buf, start, 2);
            break;
        case 3:
        case 4:
        case 5:
            SetValue(buf, start, 3);
            SetValue(buf, start + 1, unsigned(num - 3));
            break;
        default:
            if (num < 38)
            {
                unsigned n6 = unsigned(num - 6);
                SetValue(buf, start, 3);
                SetValue(buf, start + 1, 3);
                SetValue(buf, start + 2, n6 >> 4);
                SetValue(buf, start + 3, (n6 >> 2) & 3);
                SetValue(buf, start + 4, n6 & 3);
            }
            else
            {
                SetValue(buf, start, 3);
                SetValue(buf, start + 1, 3);
                SetValue(buf, start + 2, 3);
                buf[(2 * start + 6 + 31) >> 5] = UInt32(num);
            }
            break;
        }
        SetValue(buf, start + num - 1, 1);
    }

    // the same plus the alignment shift at the tail: one value (shift+1) for runs below 8 blocks, else three values
    // holding shift*2+1 in base 4
    static void MarkBusy(UInt32* buf, UPInt start, UPInt num, UPInt alignShift)
    {
        switch (num)
        {
        case 0:
        case 1:
            SetValue(buf, start, 1);
            return;
        case 2:
            SetValue(buf, start, 2);
            SetValue(buf, start + 1, unsigned(alignShift + 1));
            return;
        case 3:
        case 4:
        case 5:
            SetValue(buf, start, 3);
            SetValue(buf, start + 1, unsigned(num - 3));
            SetValue(buf, start + num - 1, unsigned(alignShift + 1));
            return;
        case 6:
        case 7:
            SetValue(buf, start, 3);
            SetValue(buf, start + 1, 3);
            SetValue(buf, start + 2, 0);
            SetValue(buf, start + 3, 0);
            SetValue(buf, start + 4, unsigned(num - 6));
            SetValue(buf, start + num - 1, unsigned(alignShift + 1));
            return;
        default:
            {
                if (num < 38)
                {
                    unsigned n6 = unsigned(num - 6);
                    SetValue(buf, start, 3);
                    SetValue(buf, start + 1, 3);
                    SetValue(buf, start + 2, n6 >> 4);
                    SetValue(buf, start + 3, (n6 >> 2) & 3);
                    SetValue(buf, start + 4, n6 & 3);
                }
                else
                {
                    SetValue(buf, start, 3);
                    SetValue(buf, start + 1, 3);
                    SetValue(buf, start + 2, 3);
                    buf[(2 * start + 6 + 31) >> 5] = UInt32(num);
                }
                unsigned a = unsigned(alignShift << 1) | 1;
                SetValue(buf, start + num - 3, a >> 4);
                SetValue(buf, start + num - 2, (a >> 2) & 3);
                SetValue(buf, start + num - 1, a & 3);
            }
            return;
        }
    }

    // decode the run length written by MarkBusy (0 = free block)
    static UPInt GetBlockSize(const UInt32* buf, UPInt start)
    {
        unsigned size;
        size = GetValue(buf, start);
        if (size < 3)
            return size;
        size = GetValue(buf, start + 1);
        if (size < 3)
            return size + 3;
        size = GetValue(buf, start + 2);
        if (size < 3)
            return 6 + ((size << 4) | (GetValue(buf, start + 3) << 2) | GetValue(buf, start + 4));
        return buf[(2 * start + 6 + 31) >> 5];
    }

    static unsigned GetAlignShift(const UInt32* buf, UPInt start, UPInt num)
    {
        if (num < 8)
            return GetValue(buf, start + num - 1) - 1;
        return (GetValue(buf, start + num - 1) >> 1) | (GetValue(buf, start + num - 2) << 1) |
               (GetValue(buf, start + num - 3) << 3);
    }
};

}}  // namespace Scaleform::Heap

#endif
