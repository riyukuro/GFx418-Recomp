// Recovered Scaleform GFx 4.1.18: random numbers (multiply-with-carry generator with lag 8, xorshift seeding; bodies in
// sfr_kernel_02h).
#ifndef MS2_SF_KERNEL_RANDOM_H
#define MS2_SF_KERNEL_RANDOM_H

#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform { namespace Alg {

class Random
{
public:
    enum { Random_SeedCount = 8 };

    // the shared generator
    static UInt32 SF_STDCALL NextRandom();
    static void   SF_STDCALL SeedRandom(UInt32 seed);
    static float  SF_STDCALL GetUnitFloat();

    // 0x28 bytes
    class Generator
    {
    public:
        UInt32 Q[Random_SeedCount];     // +0x00 lag table
        UInt32 C;                       // +0x20 carry
        UInt32 I;                       // +0x24 current index

        Generator();                    // seeded from Timer::GetTicksMs
        UInt32 NextRandom();
        void   SeedRandom(UInt32 seed);
        float  GetUnitFloat();          // [0, 1]
    };
};

}}  // namespace Scaleform::Alg

#endif
