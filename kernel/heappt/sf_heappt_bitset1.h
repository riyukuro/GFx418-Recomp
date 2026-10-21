// Recovered Scaleform GFx 4.1.18: one-bit-per-unit busy map helpers of the PT heap (bit set = unit in use). The mask and
// run-length tables live in HeapPT_BitSet1 (exe 0x143193310..0x143193710).
#ifndef MS2_SF_KERNEL_HEAPPT_BITSET1_H
#define MS2_SF_KERNEL_HEAPPT_BITSET1_H

#include <string.h>
#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform { namespace HeapPT {

class BitSet1
{
public:
    static void Clear(UInt32* buf, UPInt numWords) { memset(buf, 0, sizeof(UInt32) * numWords); }

    static unsigned GetValue(const UInt32* buf, UPInt num) { return (buf[num >> 5] >> (num & 31)) & 1; }
    static unsigned SetBit(UInt32* buf, UPInt num) { return buf[num >> 5] |= UInt32(1) << (num & 31); }
    static unsigned ClrBit(UInt32* buf, UPInt num) { return buf[num >> 5] &= ~(UInt32(1) << (num & 31)); }

    // mark units [start, start + num) used / free
    static void SetUsed(UInt32* buf, UPInt start, UPInt num)
    {
        UPInt i;
        UPInt first = start >> 5;
        UPInt last  = (start + num - 1) >> 5;
        UPInt tail  = (start + num - 1) & 31;
        if (last > first)
        {
            buf[start >> 5] |= HeadUsedTable[start & 31];
            for (i = first + 1; i < last; ++i)
                buf[i] = ~UInt32(0);
            buf[last] |= TailUsedTable[tail];
        }
        else
        {
            buf[first] |= HeadUsedTable[start & 31] & TailUsedTable[tail];
        }
    }
    static void SetFree(UInt32* buf, UPInt start, UPInt num)
    {
        UPInt i;
        UPInt first = start >> 5;
        UPInt last  = (start + num - 1) >> 5;
        UPInt tail  = (start + num - 1) & 31;
        if (last > first)
        {
            buf[start >> 5] &= HeadFreeTable[start & 31];
            for (i = first + 1; i < last; ++i)
                buf[i] = 0;
            buf[last] &= TailFreeTable[tail];
        }
        else
        {
            buf[first] &= HeadFreeTable[start & 31] | TailFreeTable[tail];
        }
    }

    // length of the run of set (used) / clear (free) bits starting at bit 0 of the word
    static UPInt FindLastUsedInWord(UInt32 bits)
    {
        if ((bits & 0xFFFF) != 0xFFFF)
        {
            return ((bits & 0xFF) == 0xFF) ? LastUsedBlock[(bits >> 8) & 0xFF] + 8
                                           : LastUsedBlock[bits & 0xFF] + 0;
        }
        return ((bits & 0xFFFFFF) == 0xFFFFFF) ? LastUsedBlock[(bits >> 24) & 0xFF] + 24
                                               : LastUsedBlock[(bits >> 16) & 0xFF] + 16;
    }
    static UPInt FindLastFreeInWord(UInt32 bits)
    {
        if (bits & 0xFFFF)
        {
            return (bits & 0xFF) ? LastFreeBlock[bits & 0xFF] + 0
                                 : LastFreeBlock[(bits >> 8) & 0xFF] + 8;
        }
        return (bits & 0xFF0000) ? LastFreeBlock[(bits >> 16) & 0xFF] + 16
                                 : LastFreeBlock[(bits >> 24) & 0xFF] + 24;
    }

    // number of used units from start (not past limit), free units from start (the map ends with a used unit)
    static UPInt FindUsedSize(const UInt32* buf, UPInt start, UPInt limit)
    {
        UPInt  word = start >> 5;
        UPInt  size = 0;
        UInt32 mask = HeadUsedTable[start & 31];
        UInt32 bits = buf[word] & mask;
        if (bits != mask)
            return FindLastUsedInWord(bits >> (start & 31));
        size += 32 - (start & 31);
        while ((word + 1) * 32 < limit && buf[++word] == ~UInt32(0))
            size += 32;
        return size + FindLastUsedInWord(buf[word]);
    }
    static UPInt FindFreeSize(const UInt32* buf, UPInt start)
    {
        UPInt  word = start >> 5;
        UPInt  size = 0;
        UInt32 mask = HeadFreeTable[start & 31];
        UInt32 bits = buf[word] | mask;
        if (bits != mask)
            return FindLastFreeInWord(bits >> (start & 31));
        size += 32 - (start & 31);
        while (buf[++word] == 0)
            size += 32;
        return size + FindLastFreeInWord(buf[word]);
    }

private:
    static const UInt32 HeadUsedTable[32];    // exe 0x143193310
    static const UInt32 TailUsedTable[32];    // exe 0x143193390
    static const UInt32 HeadFreeTable[32];    // exe 0x143193410
    static const UInt32 TailFreeTable[32];    // exe 0x143193490
    static const UByte  LastFreeBlock[256];   // exe 0x143193510
    static const UByte  LastUsedBlock[256];   // exe 0x143193610
};

}}  // namespace Scaleform::HeapPT

#endif
