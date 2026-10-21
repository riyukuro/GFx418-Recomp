// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, SF_Random (complementary
// multiply-with-carry generator, lag 8, seeded by xorshift). Our own source, written from the exe.
// Queue unit sfr_kernel_02 is split along its original sources.
// MS2-UNIT: sfr_kernel_02h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425e4f80-0x1425e5250 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_random.h"
#include "ms2/scaleform/kernel/sf_timer.h"

namespace Scaleform { namespace Alg {

enum
{
    Random_InitialCarry = 362436,
    Random_Multiplier   = 716514398,        // 0x2AB5245E
    Random_Base         = 0xFFFFFFFE        // the generator works modulo 2^32 - 1, complemented
};

Random::Generator Random_Generator1;        // the shared generator (exe 0x143a2f350)

UInt32 SF_STDCALL Random::NextRandom()
{
    return Random_Generator1.NextRandom();
}

void SF_STDCALL Random::SeedRandom(UInt32 seed)
{
    Random_Generator1.SeedRandom(seed);
}

float SF_STDCALL Random::GetUnitFloat()
{
    return Random_Generator1.GetUnitFloat();
}

Random::Generator::Generator() : C(Random_InitialCarry), I(Random_SeedCount - 1)
{
    SeedRandom(Timer::GetTicksMs());
}

void Random::Generator::SeedRandom(UInt32 seed)
{
    UInt32 x = seed;
    for (int i = 0; i < Random_SeedCount; i++)
    {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        Q[i] = x;
    }
    C = Random_InitialCarry;
    I = Random_SeedCount - 1;
}

UInt32 Random::Generator::NextRandom()
{
    I = (I + 1) & (Random_SeedCount - 1);
    UInt64 t = (UInt64)Random_Multiplier * Q[I] + C;
    C = (UInt32)(t >> 32);
    UInt32 x = (UInt32)t + C;
    if (x < C)
    {
        x++;
        C++;
    }
    return Q[I] = Random_Base - x;
}

float Random::Generator::GetUnitFloat()
{
    return (float)(NextRandom() >> 8) / 16777215.0f;
}

}}  // namespace Scaleform::Alg
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0Generator@Random@Alg@Scaleform@@QEAA@XZ 0x1425e4f80
// MS2-PIN: ?GetUnitFloat@Generator@Random@Alg@Scaleform@@QEAAMXZ 0x1425e4fb0
// MS2-PIN: ?NextRandom@Generator@Random@Alg@Scaleform@@QEAAKXZ 0x1425e5080
// MS2-PIN: ?NextRandom@Random@Alg@Scaleform@@SAKXZ 0x1425e50d0
// MS2-PIN: ?SeedRandom@Generator@Random@Alg@Scaleform@@QEAAXK@Z 0x1425e5130
