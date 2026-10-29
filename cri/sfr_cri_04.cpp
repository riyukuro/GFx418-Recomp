// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): CRI MvCore / Sofdec vendor middleware (YUV->RGB
// converters, MPEG-2 video decode kernels and the CRI support layer), written from the executable. The CRI library was
// built with VS2008 SP1, and so is this unit (MS2-TOOLSET: vc9, cmake/ms2-unit-profiles.cmake): keep it C++03 (no auto,
// decltype, variadic templates, brace-init or nullptr). Every function is a behaviour-equivalent transcription.
// MS2-UNIT: sfr_cri_04
// MS2-TOOLSET: vc9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140047b30-0x14004c1d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include <windows.h>
#include "../include/cri/cri_decomp.h"

extern "C" int DAT_143a488c0;
extern "C" int DAT_143ba9dd0;
extern "C" int DAT_143baa1d0;
extern "C" int DAT_143baa5d0;
extern "C" int DAT_143baa9d0;
extern "C" int DAT_143baadd0;
extern "C" int DAT_143bab1d0;
extern "C" unsigned char DAT_143d74a80;
extern "C" unsigned char DAT_143db4ac0;
extern "C" unsigned char DAT_143dc4b00;
extern "C" unsigned short DAT_143e44b00;  // u16 entries (FUN_14005e720 builds it)


void FUN_140047b30(cri_u64 *a1,longlong *a2,byte *a3);
void FUN_1400486a0(cri_u64 *a1,longlong *a2,longlong a3,byte *a4);
void FUN_140049250(longlong a1,longlong a2,longlong *a3,char *a4);
void FUN_140049e60(longlong *a1,longlong *a2,longlong a3,int a4,int a5);
void FUN_14004a7c0(longlong *a1,longlong *a2,longlong a3,int a4,int a5);
void FUN_14004b120(cri_u64 *a1,longlong *a2,longlong a3,int a4,int a5);
int FUN_14004bef0(byte *a1,byte *a2);
void FUN_14004bf40(cri_u64 a1,longlong a2,cri_u64 a3);
void FUN_14004bff0(cri_u64 a1,longlong a2,cri_u64 a3);
void FUN_1400627f0(const char *a1);
int FUN_140062860(void);    // sfr_cri_06 (the exe tests eax)
int FUN_140062890(void);

static __forceinline void FUN_140047b30(Any a0,Any a1,Any a2) { FUN_140047b30((cri_u64 *)a0.v,(longlong *)a1.v,(byte *)a2.v); }
static __forceinline void FUN_1400486a0(Any a0,Any a1,Any a2,Any a3) { FUN_1400486a0((cri_u64 *)a0.v,(longlong *)a1.v,(longlong)a2.v,(byte *)a3.v); }
static __forceinline void FUN_140049250(Any a0,Any a1,Any a2,Any a3) { FUN_140049250((longlong)a0.v,(longlong)a1.v,(longlong *)a2.v,(char *)a3.v); }
static __forceinline void FUN_140049e60(Any a0,Any a1,Any a2,Any a3,Any a4) { FUN_140049e60((longlong *)a0.v,(longlong *)a1.v,(longlong)a2.v,(int)a3.v,(int)a4.v); }
static __forceinline void FUN_14004a7c0(Any a0,Any a1,Any a2,Any a3,Any a4) { FUN_14004a7c0((longlong *)a0.v,(longlong *)a1.v,(longlong)a2.v,(int)a3.v,(int)a4.v); }
static __forceinline void FUN_14004b120(Any a0,Any a1,Any a2,Any a3,Any a4) { FUN_14004b120((cri_u64 *)a0.v,(longlong *)a1.v,(longlong)a2.v,(int)a3.v,(int)a4.v); }
static __forceinline int FUN_14004bef0(Any a0,Any a1) { return FUN_14004bef0((byte *)a0.v,(byte *)a1.v); }
static __forceinline void FUN_14004bf40(Any a0,Any a1,Any a2) { FUN_14004bf40((cri_u64)a0.v,(longlong)a1.v,(cri_u64)a2.v); }
static __forceinline void FUN_14004bff0(Any a0,Any a1,Any a2) { FUN_14004bff0((cri_u64)a0.v,(longlong)a1.v,(cri_u64)a2.v); }

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140047b30
void FUN_140047b30(cri_u64 *a1,longlong *a2,byte *a3)
{
  int i_v1;
  int i_v2;
  int i_v3;
  uint u_v4;
  int i_v5;
  uint u_v6;
  uint u_v7;
  int i_v8;
  int i_v9;
  uint u_v10;
  uint u_v11;
  uint u_v12;
  uint u_v13;
  ulonglong u_v14;
  uint *pu_v15;
  uint *pu_v16;
  uint *pu_v17;
  uint u_v18;
  int i_v19;
  uint u_v20;
  uint *pu_v21;
  uint *pu_v22;
  uint *pu_v23;
  uint *pu_v24;
  uint *pu_v25;
  uint *pu_v26;
  ulonglong local_res20;
  
  pu_v22 = (uint *)*a2;
  pu_v24 = (uint *)*a1;
  pu_v17 = (uint *)a1[1];
  pu_v16 = (uint *)a1[2];
  i_v1 = (int)a2[1];
  pu_v15 = pu_v24 + (CriAt<uint>(a1, 0x18) >> 2);
  u_v18 = CriAt<uint>(a1, 0x18) * 2 - i_v1 >> 2;
  pu_v26 = pu_v22 + (CriAt<uint>(a2, 0x10) >> 2);
  u_v10 = (int)(i_v1 + (i_v1 >> 0x1f & 7U)) >> 3;
  u_v11 = CriAt<int>(a2, 0xc) / 2;
  u_v14 = (ulonglong)u_v11;
  i_v2 = CriAt<int>(a1, 0x20);
  i_v3 = CriAt<int>(a1, 0x1c);
  u_v20 = (CriAt<uint>(a2, 0x10) >> 2) * 2 - (int)a2[1];
  if (u_v11 != 0) {
    do {
      if (u_v10 != 0) {
        local_res20 = (ulonglong)u_v10;
        pu_v21 = pu_v22;
        pu_v23 = pu_v24;
        pu_v25 = pu_v26;
        do {
          u_v11 = *pu_v17;
          u_v4 = *pu_v16;
          pu_v17 = pu_v17 + 1;
          i_v5 = (&DAT_143baa1d0)[u_v11 & 0xff];
          pu_v16 = pu_v16 + 1;
          i_v19 = (&DAT_143baadd0)[u_v11 & 0xff] + (&DAT_143baa5d0)[u_v4 & 0xff];
          pu_v26 = pu_v15 + 1;
          u_v6 = *pu_v23;
          u_v7 = *pu_v15;
          i_v8 = (&DAT_143ba9dd0)[u_v4 & 0xff];
          i_v9 = (&DAT_143baa9d0)[u_v6 & 0xff];
          *pu_v21 = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                     (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[3] & 0x1f) |
                     (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[1] & 0x1f) |
                     0xff << (*a3 & 0x1f);
          i_v9 = (&DAT_143baa9d0)[u_v6 >> 8 & 0xff];
          pu_v21[1] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[1] & 0x1f) |
                       0xff << (*a3 & 0x1f);
          i_v9 = (&DAT_143baa9d0)[u_v7 & 0xff];
          *pu_v25 = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                     (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[3] & 0x1f) |
                     (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[1] & 0x1f) |
                     0xff << (*a3 & 0x1f);
          i_v9 = (&DAT_143baa9d0)[u_v7 >> 8 & 0xff];
          pu_v25[1] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[1] & 0x1f) |
                       0xff << (*a3 & 0x1f);
          u_v13 = u_v11 >> 8 & 0xff;
          i_v5 = (&DAT_143baa1d0)[u_v13];
          u_v12 = u_v4 >> 8 & 0xff;
          i_v8 = (&DAT_143ba9dd0)[u_v12];
          i_v19 = (&DAT_143baadd0)[u_v13] + (&DAT_143baa5d0)[u_v12];
          i_v9 = (&DAT_143baa9d0)[u_v6 >> 0x10 & 0xff];
          pu_v21[2] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[1] & 0x1f) |
                       0xff << (*a3 & 0x1f);
          i_v9 = (&DAT_143baa9d0)[u_v6 >> 0x18];
          pu_v21[3] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[1] & 0x1f) |
                       0xff << (*a3 & 0x1f);
          i_v9 = (&DAT_143baa9d0)[u_v7 >> 0x10 & 0xff];
          pu_v24 = pu_v23 + 2;
          pu_v25[2] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[1] & 0x1f) |
                       0xff << (*a3 & 0x1f);
          i_v9 = (&DAT_143baa9d0)[u_v7 >> 0x18];
          pu_v15 = pu_v15 + 2;
          pu_v25[3] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[1] & 0x1f) |
                       0xff << (*a3 & 0x1f);
          u_v6 = *pu_v26;
          u_v7 = pu_v23[1];
          u_v13 = u_v11 >> 0x10 & 0xff;
          i_v5 = (&DAT_143baa1d0)[u_v13];
          u_v12 = u_v4 >> 0x10 & 0xff;
          i_v19 = (&DAT_143baadd0)[u_v13] + (&DAT_143baa5d0)[u_v12];
          i_v8 = (&DAT_143ba9dd0)[u_v12];
          i_v9 = (&DAT_143baa9d0)[u_v7 & 0xff];
          pu_v21[4] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[1] & 0x1f) |
                       0xff << (*a3 & 0x1f);
          i_v9 = (&DAT_143baa9d0)[u_v7 >> 8 & 0xff];
          pu_v21[5] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[1] & 0x1f) |
                       0xff << (*a3 & 0x1f);
          i_v9 = (&DAT_143baa9d0)[u_v6 & 0xff];
          pu_v25[4] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[1] & 0x1f) |
                       0xff << (*a3 & 0x1f);
          i_v9 = (&DAT_143baa9d0)[u_v6 >> 8 & 0xff];
          pu_v25[5] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[1] & 0x1f) |
                       0xff << (*a3 & 0x1f);
          i_v5 = (&DAT_143ba9dd0)[u_v4 >> 0x18];
          i_v8 = (&DAT_143baa1d0)[u_v11 >> 0x18];
          i_v19 = (&DAT_143baadd0)[u_v11 >> 0x18] + (&DAT_143baa5d0)[u_v4 >> 0x18];
          i_v9 = (&DAT_143baa9d0)[u_v7 >> 0x10 & 0xff];
          pu_v22 = pu_v21 + 8;
          pu_v21[6] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[1] & 0x1f) |
                       0xff << (*a3 & 0x1f);
          i_v9 = (&DAT_143baa9d0)[u_v7 >> 0x18];
          pu_v21[7] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[1] & 0x1f) |
                       0xff << (*a3 & 0x1f);
          i_v9 = (&DAT_143baa9d0)[u_v6 >> 0x10 & 0xff];
          pu_v25[6] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[1] & 0x1f) |
                       0xff << (*a3 & 0x1f);
          i_v9 = (&DAT_143baa9d0)[u_v6 >> 0x18];
          pu_v26 = pu_v25 + 8;
          local_res20 = local_res20 - 1;
          pu_v25[7] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v19) >> 0x14] << (a3[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a3[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v5) >> 0x14] << (a3[1] & 0x1f) |
                       0xff << (*a3 & 0x1f);
          pu_v21 = pu_v22;
          pu_v23 = pu_v24;
          pu_v25 = pu_v26;
        } while (local_res20 != 0);
      }
      pu_v24 = pu_v24 + u_v18;
      pu_v15 = pu_v15 + u_v18;
      pu_v16 = pu_v16 + ((uint)(i_v2 - i_v1 / 2) >> 2);
      pu_v17 = pu_v17 + ((uint)(i_v3 - i_v1 / 2) >> 2);
      pu_v22 = pu_v22 + u_v20;
      pu_v26 = pu_v26 + u_v20;
      u_v14 = u_v14 - 1;
    } while (u_v14 != 0);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400486a0
void FUN_1400486a0(cri_u64 *a1,longlong *a2,longlong a3,byte *a4)
{
  int i_v1;
  int i_v2;
  int i_v3;
  uint u_v4;
  uint u_v5;
  int i_v6;
  uint u_v7;
  int i_v8;
  int i_v9;
  uint u_v10;
  uint u_v11;
  ulonglong u_v12;
  ulonglong u_v13;
  ulonglong u_v14;
  uint *pu_v15;
  uint *pu_v16;
  uint *pu_v17;
  uint *pu_v18;
  uint u_v19;
  uint u_v20;
  int i_v21;
  uint *pu_v22;
  uint *pu_v23;
  uint *pu_v24;
  uint *pu_v25;
  uint *local_res10;
  ulonglong loc_70;
  
  pu_v23 = (uint *)*a2;
  pu_v25 = (uint *)*a1;
  pu_v18 = (uint *)a1[1];
  pu_v16 = (uint *)a1[2];
  i_v1 = (int)a2[1];
  pu_v15 = pu_v25 + (CriAt<uint>(a1, 0x18) >> 2);
  u_v19 = CriAt<uint>(a1, 0x18) * 2 - i_v1 >> 2;
  pu_v17 = pu_v23 + (CriAt<uint>(a2, 0x10) >> 2);
  u_v10 = (int)(i_v1 + (i_v1 >> 0x1f & 7U)) >> 3;
  u_v11 = CriAt<int>(a2, 0xc) / 2;
  u_v14 = (ulonglong)u_v11;
  i_v2 = CriAt<int>(a1, 0x20);
  i_v3 = CriAt<int>(a1, 0x1c);
  u_v20 = (CriAt<uint>(a2, 0x10) >> 2) * 2 - (int)a2[1];
  if (u_v11 != 0) {
    do {
      if (u_v10 != 0) {
        loc_70 = (ulonglong)u_v10;
        pu_v22 = pu_v23;
        pu_v24 = pu_v25;
        local_res10 = pu_v17;
        do {
          u_v11 = *pu_v16;
          u_v4 = *pu_v18;
          u_v5 = *pu_v24;
          pu_v18 = pu_v18 + 1;
          pu_v16 = pu_v16 + 1;
          pu_v17 = pu_v15 + 1;
          i_v6 = *(int *)(a3 + 0x400 + (ulonglong)(u_v11 & 0xff) * 4);
          i_v21 = *(int *)(a3 + 0xc00 + (ulonglong)(u_v11 & 0xff) * 4) +
                   *(int *)(a3 + 0x800 + (ulonglong)(u_v4 & 0xff) * 4);
          u_v7 = *pu_v15;
          i_v8 = *(int *)(a3 + 0x1000 + (ulonglong)(u_v4 & 0xff) * 4);
          i_v9 = *(int *)(a3 + (ulonglong)(u_v5 & 0xff) * 4);
          u_v12 = (ulonglong)(u_v5 >> 8 & 0xff);
          *pu_v22 = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f) |
                     (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a4[3] & 0x1f) |
                     (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[1] & 0x1f) |
                     (uint)*(byte *)((ulonglong)(u_v5 & 0xff) + 0x1400 + a3) <<
                     (*a4 & 0x1f);
          i_v9 = *(int *)(a3 + u_v12 * 4);
          pu_v22[1] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a4[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[1] & 0x1f) |
                       (uint)*(byte *)(u_v12 + 0x1400 + a3) << (*a4 & 0x1f);
          i_v9 = *(int *)(a3 + (ulonglong)(u_v7 & 0xff) * 4);
          *local_res10 = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f)
                         | (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] <<
                           (a4[3] & 0x1f) |
                         (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[1] & 0x1f)
                         | (uint)*(byte *)((ulonglong)(u_v7 & 0xff) + 0x1400 + a3) <<
                           (*a4 & 0x1f);
          u_v12 = (ulonglong)(u_v7 >> 8 & 0xff);
          i_v9 = *(int *)(a3 + u_v12 * 4);
          local_res10[1] =
               (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f) |
               (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a4[3] & 0x1f) |
               (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[1] & 0x1f) |
               (uint)*(byte *)(u_v12 + 0x1400 + a3) << (*a4 & 0x1f);
          u_v13 = (ulonglong)(u_v4 >> 8 & 0xff);
          i_v6 = *(int *)(a3 + 0x1000 + u_v13 * 4);
          u_v12 = (ulonglong)(u_v11 >> 8 & 0xff);
          i_v8 = *(int *)(a3 + 0x400 + u_v12 * 4);
          i_v21 = *(int *)(a3 + 0xc00 + u_v12 * 4) + *(int *)(a3 + 0x800 + u_v13 * 4);
          u_v12 = (ulonglong)(u_v5 >> 0x10 & 0xff);
          i_v9 = *(int *)(a3 + u_v12 * 4);
          pu_v22[2] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a4[1] & 0x1f) |
                       (uint)*(byte *)(u_v12 + 0x1400 + a3) << (*a4 & 0x1f);
          i_v9 = *(int *)(a3 + (ulonglong)(u_v5 >> 0x18) * 4);
          pu_v22[3] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a4[1] & 0x1f) |
                       (uint)*(byte *)((ulonglong)(u_v5 >> 0x18) + 0x1400 + a3) <<
                       (*a4 & 0x1f);
          pu_v25 = pu_v24 + 2;
          u_v12 = (ulonglong)(u_v7 >> 0x10 & 0xff);
          i_v9 = *(int *)(a3 + u_v12 * 4);
          local_res10[2] =
               (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f) |
               (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[3] & 0x1f) |
               (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a4[1] & 0x1f) |
               (uint)*(byte *)(u_v12 + 0x1400 + a3) << (*a4 & 0x1f);
          i_v9 = *(int *)(a3 + (ulonglong)(u_v7 >> 0x18) * 4);
          pu_v15 = pu_v15 + 2;
          local_res10[3] =
               (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f) |
               (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[3] & 0x1f) |
               (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a4[1] & 0x1f) |
               (uint)*(byte *)((ulonglong)(u_v7 >> 0x18) + 0x1400 + a3) << (*a4 & 0x1f);
          u_v5 = *pu_v17;
          u_v7 = pu_v24[1];
          u_v13 = (ulonglong)(u_v4 >> 0x10 & 0xff);
          u_v12 = (ulonglong)(u_v11 >> 0x10 & 0xff);
          i_v6 = *(int *)(a3 + 0x400 + u_v12 * 4);
          i_v8 = *(int *)(a3 + 0x1000 + u_v13 * 4);
          i_v21 = *(int *)(a3 + 0xc00 + u_v12 * 4) + *(int *)(a3 + 0x800 + u_v13 * 4);
          i_v9 = *(int *)(a3 + (ulonglong)(u_v7 & 0xff) * 4);
          u_v12 = (ulonglong)(u_v7 >> 8 & 0xff);
          pu_v22[4] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a4[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[1] & 0x1f) |
                       (uint)*(byte *)((ulonglong)(u_v7 & 0xff) + 0x1400 + a3) <<
                       (*a4 & 0x1f);
          i_v9 = *(int *)(a3 + u_v12 * 4);
          pu_v22[5] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a4[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[1] & 0x1f) |
                       (uint)*(byte *)(u_v12 + 0x1400 + a3) << (*a4 & 0x1f);
          i_v9 = *(int *)(a3 + (ulonglong)(u_v5 & 0xff) * 4);
          local_res10[4] =
               (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f) |
               (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a4[3] & 0x1f) |
               (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[1] & 0x1f) |
               (uint)*(byte *)((ulonglong)(u_v5 & 0xff) + 0x1400 + a3) << (*a4 & 0x1f);
          u_v12 = (ulonglong)(u_v5 >> 8 & 0xff);
          i_v9 = *(int *)(a3 + u_v12 * 4);
          local_res10[5] =
               (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f) |
               (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a4[3] & 0x1f) |
               (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[1] & 0x1f) |
               (uint)*(byte *)(u_v12 + 0x1400 + a3) << (*a4 & 0x1f);
          i_v6 = *(int *)(a3 + 0x400 + (ulonglong)(u_v11 >> 0x18) * 4);
          i_v21 = *(int *)(a3 + 0xc00 + (ulonglong)(u_v11 >> 0x18) * 4) +
                   *(int *)(a3 + 0x800 + (ulonglong)(u_v4 >> 0x18) * 4);
          i_v8 = *(int *)(a3 + 0x1000 + (ulonglong)(u_v4 >> 0x18) * 4);
          u_v12 = (ulonglong)(u_v7 >> 0x10 & 0xff);
          i_v9 = *(int *)(a3 + u_v12 * 4);
          pu_v23 = pu_v22 + 8;
          pu_v22[6] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a4[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[1] & 0x1f) |
                       (uint)*(byte *)(u_v12 + 0x1400 + a3) << (*a4 & 0x1f);
          i_v9 = *(int *)(a3 + (ulonglong)(u_v7 >> 0x18) * 4);
          pu_v22[7] = (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a4[3] & 0x1f) |
                       (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[1] & 0x1f) |
                       (uint)*(byte *)((ulonglong)(u_v7 >> 0x18) + 0x1400 + a3) <<
                       (*a4 & 0x1f);
          u_v12 = (ulonglong)(u_v5 >> 0x10 & 0xff);
          i_v9 = *(int *)(a3 + u_v12 * 4);
          pu_v17 = local_res10 + 8;
          local_res10[6] =
               (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f) |
               (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a4[3] & 0x1f) |
               (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[1] & 0x1f) |
               (uint)*(byte *)(u_v12 + 0x1400 + a3) << (*a4 & 0x1f);
          i_v9 = *(int *)(a3 + (ulonglong)(u_v5 >> 0x18) * 4);
          loc_70 = loc_70 - 1;
          local_res10[7] =
               (&DAT_143bab1d0)[(longlong)(i_v9 - i_v21) >> 0x14] << (a4[2] & 0x1f) |
               (&DAT_143bab1d0)[(longlong)(i_v9 + i_v8) >> 0x14] << (a4[3] & 0x1f) |
               (&DAT_143bab1d0)[(longlong)(i_v9 + i_v6) >> 0x14] << (a4[1] & 0x1f) |
               (uint)*(byte *)((ulonglong)(u_v5 >> 0x18) + 0x1400 + a3) << (*a4 & 0x1f);
          pu_v22 = pu_v23;
          pu_v24 = pu_v25;
          local_res10 = pu_v17;
        } while (loc_70 != 0);
      }
      pu_v17 = pu_v17 + u_v20;
      pu_v25 = pu_v25 + u_v19;
      pu_v15 = pu_v15 + u_v19;
      pu_v16 = pu_v16 + ((uint)(i_v2 - i_v1 / 2) >> 2);
      pu_v18 = pu_v18 + ((uint)(i_v3 - i_v1 / 2) >> 2);
      pu_v23 = pu_v23 + u_v20;
      u_v14 = u_v14 - 1;
    } while (u_v14 != 0);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140049250
void FUN_140049250(longlong a1,longlong a2,longlong *a3,char *a4)
{
  struct { cri_u64 plane[3]; cri_u32 stride[3]; } dst;
  struct { cri_u64 data; cri_u32 a; cri_u32 b; cri_u32 c; cri_u32 unused[3]; } src;  // 32 bytes in the exe frame

  a4[0] = a4[0] * 8;
  a4[1] = a4[1] * 8;
  a4[2] = a4[2] * 8;
  a4[3] = a4[3] * 8;
  dst.plane[0] = CriAt<cri_u64>(a1, 0x8);
  dst.plane[1] = CriAt<cri_u64>(a1, 0x20);
  dst.plane[2] = CriAt<cri_u64>(a1, 0x38);
  dst.stride[0] = CriAt<cri_u32>(a1, 0x18);
  dst.stride[1] = CriAt<cri_u32>(a1, 0x30);
  dst.stride[2] = CriAt<cri_u32>(a1, 0x48);
  src.data = CriAt<cri_u64>(a2, 0x8);
  src.a = CriAt<cri_u32>(a2, 0x10);
  src.b = CriAt<cri_u32>(a2, 0x14);
  src.c = CriAt<cri_u32>(a2, 0x18);
  if (*a3 == 0) {
    FUN_140047b30((cri_u64 *)&dst,(longlong *)&src,(byte *)a4);
    return;
  }
  FUN_1400486a0((cri_u64 *)&dst,(longlong *)&src,*a3,(byte *)a4);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140049300
void FUN_140049300(longlong a1,longlong a2,longlong *a3)
{
  char order[4] = {3,0,1,2};
  FUN_140049250(a1,a2,a3,order);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140049330
void FUN_140049330(longlong a1,longlong a2,longlong *a3)
{
  char order[4] = {3,2,1,0};
  FUN_140049250(a1,a2,a3,order);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140049360
void FUN_140049360(longlong a1,longlong a2,longlong *a3)
{
  char order[4] = {0,1,2,3};
  FUN_140049250(a1,a2,a3,order);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140049390
void FUN_140049390(longlong a1,longlong a2,longlong *a3)
{
  char order[4] = {0,3,2,1};
  FUN_140049250(a1,a2,a3,order);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400493c0
void FUN_1400493c0(void)
{
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400493d0
void FUN_1400493d0(longlong a1,longlong a2)
{
  ushort u_v1;
  uint u_v2;
  uint u_v3;
  uint u_v4;
  ulonglong u_v5;
  ulonglong u_v6;
  ulonglong u_v7;
  ulonglong u_v8;
  ulonglong u_v9;
  ulonglong u_v10;
  uint u_v11;
  longlong l_v12;
  longlong l_v13;
  ulonglong u_v14;
  uint *pu_v15;
  uint u_v16;
  uint u_v17;
  cri_u8 *pu_v18;
  cri_u8 *pu_v19;
  uint *pu_v20;
  uint *pu_v21;
  uint *pu_v22;
  cri_u8 *local_res20;
  ulonglong loc_60;
  
  FUN_1400627f0("CFT_Ycc420plnToRgb888");
  pu_v20 = CriAt<uint *>(a1, 0x8);
  pu_v21 = CriAt<uint *>(a1, 0x20);
  pu_v22 = CriAt<uint *>(a1, 0x38);
  pu_v19 = CriAt<cri_u8 *>(a2, 0x8);
  u_v16 = CriAt<int>(a2, 0x10) + 7;
  u_v17 = u_v16 & 0xfffffff8;
  local_res20 = pu_v19 + CriAt<int>(a2, 0x18);
  pu_v15 = (uint *)((longlong)pu_v20 + (longlong)CriAt<int>(a1, 0x18));
  u_v16 = (int)u_v16 >> 0x1f;
  u_v3 = (int)(u_v17 + (u_v16 & 7)) >> 3;
  u_v4 = CriAt<int>(a2, 0x14) / 2;
  u_v14 = (ulonglong)u_v4;
  u_v11 = CriAt<int>(a2, 0x18) * 2 + u_v17 * -3;
  if (u_v4 != 0) {
    u_v5 = (ulonglong)(CriAt<int>(a1, 0x18) * 2 - u_v17) & 0xfffffffffffffffc;
    u_v7 = (ulonglong)(uint)(CriAt<int>(a1, 0x30) - ((int)(u_v17 - u_v16) >> 1)) &
            0xfffffffffffffffc;
    do {
      if (u_v3 != 0) {
        loc_60 = (ulonglong)u_v3;
        pu_v18 = pu_v19;
        do {
          u_v4 = *pu_v15;
          u_v16 = *pu_v21;
          u_v17 = *pu_v22;
          u_v2 = *pu_v20;
          u_v10 = (ulonglong)(u_v17 & 0xff);
          u_v8 = (ulonglong)(u_v16 & 0xff);
          pu_v21 = pu_v21 + 1;
          pu_v22 = pu_v22 + 1;
          u_v9 = (ulonglong)(ushort)(&DAT_143e44b00)[u_v8 * 0x100 + u_v10];
          l_v12 = (ulonglong)(u_v2 & 0xff) * 0x100;
          *pu_v18 = (&DAT_143db4ac0)[l_v12 + u_v8];
          pu_v18[1] = *(cri_u8 *)
                        ((longlong)&DAT_143dc4b00 +
                        ((ulonglong)(u_v2 & 0xff) * 0x400 + u_v9) * 2 + 1);
          pu_v18[2] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v10) * 4 + 2);
          u_v6 = (ulonglong)(u_v2 >> 8 & 0xff);
          l_v12 = u_v6 * 0x100;
          pu_v18[3] = (&DAT_143db4ac0)[l_v12 + u_v8];
          pu_v18[4] = *(cri_u8 *)((longlong)&DAT_143dc4b00 + (u_v6 * 0x400 + u_v9) * 2 + 1);
          pu_v18[5] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v10) * 4 + 2);
          l_v12 = (ulonglong)(u_v4 & 0xff) * 0x100;
          *local_res20 = (&DAT_143db4ac0)[l_v12 + u_v8];
          local_res20[1] =
               *(cri_u8 *)
                ((longlong)&DAT_143dc4b00 + ((ulonglong)(u_v4 & 0xff) * 0x400 + u_v9) * 2 + 1);
          local_res20[2] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v10) * 4 + 2);
          u_v6 = (ulonglong)(u_v4 >> 8 & 0xff);
          l_v12 = u_v6 * 0x100;
          local_res20[3] = (&DAT_143db4ac0)[l_v12 + u_v8];
          local_res20[4] =
               *(cri_u8 *)((longlong)&DAT_143dc4b00 + (u_v6 * 0x400 + u_v9) * 2 + 1);
          local_res20[5] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v10) * 4 + 2);
          u_v10 = (ulonglong)(u_v16 >> 8 & 0xff);
          u_v8 = (ulonglong)(u_v17 >> 8 & 0xff);
          u_v9 = (ulonglong)(ushort)(&DAT_143e44b00)[u_v10 * 0x100 + u_v8];
          u_v6 = (ulonglong)(u_v2 >> 0x10 & 0xff);
          l_v13 = u_v6 * 0x100;
          pu_v18[6] = (&DAT_143db4ac0)[l_v13 + u_v10];
          pu_v18[7] = *(cri_u8 *)((longlong)&DAT_143dc4b00 + (u_v6 * 0x400 + u_v9) * 2 + 1);
          l_v12 = (ulonglong)(u_v2 >> 0x18) * 0x100;
          pu_v18[8] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v13 + u_v8) * 4 + 2);
          pu_v18[9] = (&DAT_143db4ac0)[l_v12 + u_v10];
          pu_v18[10] = *(cri_u8 *)
                         ((longlong)&DAT_143dc4b00 +
                         ((ulonglong)(u_v2 >> 0x18) * 0x400 + u_v9) * 2 + 1);
          pu_v18[0xb] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v8) * 4 + 2);
          u_v6 = (ulonglong)(u_v4 >> 0x10 & 0xff);
          l_v12 = u_v6 * 0x100;
          local_res20[6] = (&DAT_143db4ac0)[l_v12 + u_v10];
          local_res20[7] =
               *(cri_u8 *)((longlong)&DAT_143dc4b00 + (u_v6 * 0x400 + u_v9) * 2 + 1);
          l_v13 = (ulonglong)(u_v4 >> 0x18) * 0x100;
          local_res20[8] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v8) * 4 + 2);
          local_res20[9] = (&DAT_143db4ac0)[l_v13 + u_v10];
          local_res20[10] =
               *(cri_u8 *)
                ((longlong)&DAT_143dc4b00 + ((ulonglong)(u_v4 >> 0x18) * 0x400 + u_v9) * 2 + 1);
          local_res20[0xb] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v13 + u_v8) * 4 + 2);
          u_v4 = pu_v20[1];
          u_v2 = pu_v15[1];
          pu_v15 = pu_v15 + 2;
          pu_v20 = pu_v20 + 2;
          u_v10 = (ulonglong)(u_v16 >> 0x10 & 0xff);
          u_v8 = (ulonglong)(u_v17 >> 0x10 & 0xff);
          u_v9 = (ulonglong)(ushort)(&DAT_143e44b00)[u_v10 * 0x100 + u_v8];
          l_v12 = (ulonglong)(u_v4 & 0xff) * 0x100;
          pu_v18[0xc] = (&DAT_143db4ac0)[l_v12 + u_v10];
          pu_v18[0xd] = *(cri_u8 *)
                          ((longlong)&DAT_143dc4b00 +
                          ((ulonglong)(u_v4 & 0xff) * 0x400 + u_v9) * 2 + 1);
          pu_v18[0xe] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v8) * 4 + 2);
          u_v6 = (ulonglong)(u_v4 >> 8 & 0xff);
          l_v12 = u_v6 * 0x100;
          pu_v18[0xf] = (&DAT_143db4ac0)[l_v12 + u_v10];
          pu_v18[0x10] =
               *(cri_u8 *)((longlong)&DAT_143dc4b00 + (u_v6 * 0x400 + u_v9) * 2 + 1);
          pu_v18[0x11] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v8) * 4 + 2);
          l_v12 = (ulonglong)(u_v2 & 0xff) * 0x100;
          local_res20[0xc] = (&DAT_143db4ac0)[l_v12 + u_v10];
          local_res20[0xd] =
               *(cri_u8 *)
                ((longlong)&DAT_143dc4b00 + ((ulonglong)(u_v2 & 0xff) * 0x400 + u_v9) * 2 + 1);
          local_res20[0xe] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v8) * 4 + 2);
          u_v6 = (ulonglong)(u_v2 >> 8 & 0xff);
          l_v12 = u_v6 * 0x100;
          local_res20[0xf] = (&DAT_143db4ac0)[l_v12 + u_v10];
          u_v17 = u_v17 >> 0x18;
          u_v16 = u_v16 >> 0x18;
          pu_v19 = pu_v18 + 0x18;
          local_res20[0x10] =
               *(cri_u8 *)((longlong)&DAT_143dc4b00 + (u_v6 * 0x400 + u_v9) * 2 + 1);
          u_v9 = (ulonglong)u_v17;
          local_res20[0x11] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v8) * 4 + 2);
          u_v8 = (ulonglong)(ushort)(&DAT_143e44b00)[(ulonglong)u_v16 * 0x100 + u_v9];
          u_v6 = (ulonglong)(u_v4 >> 0x10 & 0xff);
          l_v13 = u_v6 * 0x100;
          pu_v18[0x12] = (&DAT_143db4ac0)[l_v13 + (ulonglong)u_v16];
          pu_v18[0x13] =
               *(cri_u8 *)((longlong)&DAT_143dc4b00 + (u_v6 * 0x400 + u_v8) * 2 + 1);
          l_v12 = (ulonglong)(u_v4 >> 0x18) * 0x100;
          pu_v18[0x14] =
               *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v13 + (ulonglong)u_v17) * 4 + 2);
          pu_v18[0x15] = (&DAT_143db4ac0)[l_v12 + (ulonglong)u_v16];
          pu_v18[0x16] =
               *(cri_u8 *)
                ((longlong)&DAT_143dc4b00 + ((ulonglong)(u_v4 >> 0x18) * 0x400 + u_v8) * 2 + 1);
          pu_v18[0x17] =
               *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + (ulonglong)u_v17) * 4 + 2);
          u_v6 = (ulonglong)(u_v2 >> 0x10 & 0xff);
          l_v12 = u_v6 * 0x100;
          local_res20[0x12] = (&DAT_143db4ac0)[l_v12 + (ulonglong)u_v16];
          local_res20[0x13] =
               *(cri_u8 *)((longlong)&DAT_143dc4b00 + (u_v6 * 0x400 + u_v8) * 2 + 1);
          l_v13 = (ulonglong)(u_v2 >> 0x18) * 0x100;
          local_res20[0x14] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v9) * 4 + 2);
          local_res20[0x15] = (&DAT_143db4ac0)[l_v13 + (ulonglong)u_v16];
          local_res20[0x16] =
               *(cri_u8 *)
                ((longlong)&DAT_143dc4b00 + ((ulonglong)(u_v2 >> 0x18) * 0x400 + u_v8) * 2 + 1);
          local_res20[0x17] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v13 + u_v9) * 4 + 2);
          local_res20 = local_res20 + 0x18;
          loc_60 = loc_60 - 1;
          pu_v18 = pu_v19;
        } while (loc_60 != 0);
      }
      local_res20 = local_res20 + u_v11;
      pu_v20 = (uint *)((longlong)pu_v20 + u_v5);
      pu_v15 = (uint *)((longlong)pu_v15 + u_v5);
      pu_v22 = (uint *)((longlong)pu_v22 + u_v7);
      pu_v21 = (uint *)((longlong)pu_v21 + u_v7);
      pu_v19 = pu_v19 + u_v11;
      u_v14 = u_v14 - 1;
    } while (u_v14 != 0);
  }
  if (((CriAt<byte>(a2, 0x14) & 1) != 0) && (u_v3 != 0)) {
    u_v14 = (ulonglong)u_v3;
    do {
      u_v3 = *pu_v20;
      u_v4 = *pu_v21;
      u_v16 = *pu_v22;
      u_v6 = (ulonglong)(u_v16 & 0xff);
      u_v7 = (ulonglong)(u_v4 & 0xff);
      pu_v21 = pu_v21 + 1;
      pu_v22 = pu_v22 + 1;
      u_v1 = (&DAT_143e44b00)[u_v7 * 0x100 + u_v6];
      l_v12 = (ulonglong)(u_v3 & 0xff) * 0x100;
      *pu_v19 = (&DAT_143db4ac0)[l_v12 + u_v7];
      pu_v19[1] = *(cri_u8 *)
                    ((longlong)&DAT_143dc4b00 +
                    ((ulonglong)(u_v3 & 0xff) * 0x400 + (ulonglong)u_v1) * 2 + 1);
      pu_v19[2] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v6) * 4 + 2);
      u_v5 = (ulonglong)(u_v3 >> 8 & 0xff);
      l_v12 = u_v5 * 0x100;
      pu_v19[3] = (&DAT_143db4ac0)[l_v12 + u_v7];
      pu_v19[4] = *(cri_u8 *)
                    ((longlong)&DAT_143dc4b00 + (u_v5 * 0x400 + (ulonglong)u_v1) * 2 + 1);
      pu_v19[5] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v6) * 4 + 2);
      u_v6 = (ulonglong)(u_v4 >> 8 & 0xff);
      u_v7 = (ulonglong)(u_v16 >> 8 & 0xff);
      u_v1 = (&DAT_143e44b00)[u_v6 * 0x100 + u_v7];
      u_v5 = (ulonglong)(u_v3 >> 0x10 & 0xff);
      l_v12 = u_v5 * 0x100;
      pu_v19[6] = (&DAT_143db4ac0)[l_v12 + u_v6];
      pu_v19[7] = *(cri_u8 *)
                    ((longlong)&DAT_143dc4b00 + (u_v5 * 0x400 + (ulonglong)u_v1) * 2 + 1);
      pu_v19[8] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v7) * 4 + 2);
      l_v12 = (ulonglong)(u_v3 >> 0x18) * 0x100;
      pu_v19[9] = (&DAT_143db4ac0)[l_v12 + u_v6];
      pu_v19[10] = *(cri_u8 *)
                     ((longlong)&DAT_143dc4b00 +
                     ((ulonglong)(u_v3 >> 0x18) * 0x400 + (ulonglong)u_v1) * 2 + 1);
      pu_v19[0xb] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v7) * 4 + 2);
      u_v3 = pu_v20[1];
      u_v8 = (ulonglong)(u_v4 >> 0x18);
      u_v6 = (ulonglong)(u_v4 >> 0x10 & 0xff);
      u_v7 = (ulonglong)(u_v16 >> 0x10 & 0xff);
      u_v1 = (&DAT_143e44b00)[u_v6 * 0x100 + u_v7];
      l_v12 = (ulonglong)(u_v3 & 0xff) * 0x100;
      pu_v19[0xc] = (&DAT_143db4ac0)[l_v12 + u_v6];
      pu_v19[0xd] = *(cri_u8 *)
                      ((longlong)&DAT_143dc4b00 +
                      ((ulonglong)(u_v3 & 0xff) * 0x400 + (ulonglong)u_v1) * 2 + 1);
      pu_v19[0xe] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v7) * 4 + 2);
      u_v5 = (ulonglong)(u_v3 >> 8 & 0xff);
      l_v12 = u_v5 * 0x100;
      pu_v19[0xf] = (&DAT_143db4ac0)[l_v12 + u_v6];
      pu_v19[0x10] =
           *(cri_u8 *)((longlong)&DAT_143dc4b00 + (u_v5 * 0x400 + (ulonglong)u_v1) * 2 + 1);
      u_v6 = (ulonglong)(u_v16 >> 0x18);
      pu_v19[0x11] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v7) * 4 + 2);
      u_v1 = (&DAT_143e44b00)[u_v8 * 0x100 + u_v6];
      u_v5 = (ulonglong)(u_v3 >> 0x10 & 0xff);
      l_v12 = u_v5 * 0x100;
      pu_v19[0x12] = (&DAT_143db4ac0)[l_v12 + u_v8];
      pu_v19[0x13] =
           *(cri_u8 *)((longlong)&DAT_143dc4b00 + (u_v5 * 0x400 + (ulonglong)u_v1) * 2 + 1);
      pu_v19[0x14] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v6) * 4 + 2);
      l_v12 = (ulonglong)(u_v3 >> 0x18) * 0x100;
      u_v14 = u_v14 - 1;
      pu_v19[0x15] = (&DAT_143db4ac0)[l_v12 + u_v8];
      pu_v19[0x16] =
           *(cri_u8 *)
            ((longlong)&DAT_143dc4b00 +
            ((ulonglong)(u_v3 >> 0x18) * 0x400 + (ulonglong)u_v1) * 2 + 1);
      pu_v19[0x17] = *(cri_u8 *)((longlong)&DAT_143d74a80 + (l_v12 + u_v6) * 4 + 2);
      pu_v19 = pu_v19 + 0x18;
      pu_v20 = pu_v20 + 2;
    } while (u_v14 != 0);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140049e60
void FUN_140049e60(longlong *a1,longlong *a2,longlong a3,int a4,int a5)
{
  cri_u64 u_v1;
  cri_u64 u_v2;
  cri_u64 u_v3;
  cri_u64 u_v4;
  cri_u64 u_v5;
  cri_u64 u_v6;
  cri_u64 u_v7;
  cri_u64 u_v8;
  int i_v9;
  short s_v10;
  short s_v11;
  short s_v12;
  short s_v13;
  ushort u_v14;
  ushort u_v15;
  longlong l_v16;
  uint u_v17;
  longlong l_v18;
  ulonglong u_v19;
  longlong l_v20;
  int i_v21;
  longlong l_v22;
  cri_u32 *pu_v23;
  longlong l_v24;
  cri_u32 *pu_v25;
  uint u_v26;
  uint u_v27;
  longlong l_v28;
  int i_v29;
  longlong l_v30;
  longlong l_v31;
  longlong l_v32;
  longlong l_v33;
  longlong l_v34;
  V16 au_v35;
  V16 au_v36;
  V16 au_v37;
  V16 au_v38;
  V16 au_v39;
  V16 au_v40;
  V16 au_v41;
  V16 au_v42;
  V16 au_v43;
  V16 au_v44;
  V16 au_v45;
  V16 au_v46;
  V16 au_v47;
  V16 au_v48;
  V16 au_v49;
  V16 au_v50;
  V16 au_v51;
  V16 au_v52;
  V16 au_v53;
  V16 au_v54;
  V16 au_v55;
  V16 au_v56;
  V16 au_v57;
  V16 au_v58;
  short s_v59;
  short s_v68;
  short s_v69;
  short s_v70;
  V16 au_v60;
  V16 au_v61;
  V16 au_v62;
  V16 au_v63;
  V16 au_v64;
  V16 au_v65;
  V16 au_v66;
  V16 au_v67;
  
  FUN_1400627f0("cft_sse_Ycc420plnToArgb8888UserTable");
  l_v22 = *a2;
  l_v32 = *a1;
  l_v33 = a1[1];
  l_v34 = a1[2];
  l_v30 = l_v22 + a4;
  l_v31 = l_v32 + (int)a1[3];
  l_v20 = (longlong)((int)a2[1] / 2);
  u_v17 = CriAt<int>(a2, 0xc) / 2;
  u_v19 = (ulonglong)u_v17;
  if (0 < (int)u_v17) {
    l_v16 = a1[4];
    i_v9 = CriAt<int>(a1, 0x1c);
    l_v24 = (longlong)((int)a1[3] * 2);
    do {
      i_v21 = 0;
      if (0 < l_v20) {
        l_v28 = (l_v20 - 1U >> 3) + 1;
        pu_v23 = (&CriAt<cri_u32>(l_v30, 0x4));
        pu_v25 = (&CriAt<cri_u32>(l_v22, 0xc));
        i_v29 = i_v21;
        do {
          l_v18 = (longlong)i_v29;
          u_v1 = *(cri_u64 *)(l_v18 + l_v32);
          u_v2 = *(cri_u64 *)(l_v18 + l_v31);
          u_v3 = *(cri_u64 *)(l_v18 + 8 + l_v32);
          u_v4 = *(cri_u64 *)(l_v18 + 8 + l_v31);
          u_v5 = *(cri_u64 *)(i_v21 + l_v33);
          u_v6 = *(cri_u64 *)(i_v21 + l_v34);
          u_v7 = *(cri_u64 *)((longlong)(int)(((ushort)u_v5 & 0xff) << 3) + 0x800 + a3);
          u_v8 = *(cri_u64 *)((longlong)(int)(((ushort)u_v6 & 0xff) << 3) + 0x1000 + a3);
          s_v59 = (short)u_v7 + (short)u_v8;
          s_v68 = (short)((ulonglong)u_v7 >> 0x10) + (short)((ulonglong)u_v8 >> 0x10);
          s_v69 = (short)((ulonglong)u_v7 >> 0x20) + (short)((ulonglong)u_v8 >> 0x20);
          s_v70 = (short)((ulonglong)u_v7 >> 0x30) + (short)((ulonglong)u_v8 >> 0x30);
          u_v7 = *(cri_u64 *)((int)(((ushort)u_v1 & 0xff) << 3) + a3);
          (*(short*)&au_v35.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v35.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v35.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v35.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v35.b[8]) = 0;
          au_v35 = psraw(au_v35,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[-3] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                 CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                          (0xff < s_v12),
                                          CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                   (0xff < s_v11),
                                                   (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                   (0xff < s_v10))));
          u_v7 = *(cri_u64 *)((((int)(uint)(ushort)u_v1 >> 8) << 3) + a3);
          (*(short*)&au_v36.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v36.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v36.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v36.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v36.b[8]) = 0;
          au_v35 = psraw(au_v36,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          *(uint *)((l_v22 - l_v30) + (longlong)pu_v23) =
               CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                        CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] - (0xff < s_v12),
                                 CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                          (0xff < s_v11),
                                          (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                          (0xff < s_v10))));
          u_v7 = *(cri_u64 *)((int)(((ushort)u_v2 & 0xff) << 3) + a3);
          (*(short*)&au_v37.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v37.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v37.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v37.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v37.b[8]) = 0;
          au_v35 = psraw(au_v37,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[-1] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                 CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                          (0xff < s_v12),
                                          CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                   (0xff < s_v11),
                                                   (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                   (0xff < s_v10))));
          u_v17 = (uint)(ushort)((ulonglong)u_v1 >> 0x10);
          u_v7 = *(cri_u64 *)((((int)(uint)(ushort)u_v2 >> 8) << 3) + a3);
          (*(short*)&au_v60.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v60.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v60.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v60.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v60.b[8]) = 0;
          au_v35 = psraw(au_v60,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          *pu_v23 = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                              CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                       (0xff < s_v12),
                                       CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                (0xff < s_v11),
                                                (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                (0xff < s_v10))));
          u_v7 = *(cri_u64 *)
                   ((longlong)(((int)(uint)(ushort)u_v5 >> 8) << 3) + 0x800 + a3);
          u_v8 = *(cri_u64 *)
                   ((longlong)(((int)(uint)(ushort)u_v6 >> 8) << 3) + 0x1000 + a3);
          s_v59 = (short)u_v7 + (short)u_v8;
          s_v68 = (short)((ulonglong)u_v7 >> 0x10) + (short)((ulonglong)u_v8 >> 0x10);
          s_v69 = (short)((ulonglong)u_v7 >> 0x20) + (short)((ulonglong)u_v8 >> 0x20);
          s_v70 = (short)((ulonglong)u_v7 >> 0x30) + (short)((ulonglong)u_v8 >> 0x30);
          u_v26 = (uint)(ushort)((ulonglong)u_v6 >> 0x10);
          u_v7 = *(cri_u64 *)((int)((u_v17 & 0xff) << 3) + a3);
          (*(short*)&au_v38.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v38.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v38.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v38.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v38.b[8]) = 0;
          au_v35 = psraw(au_v38,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[-1] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                 CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                          (0xff < s_v12),
                                          CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                   (0xff < s_v11),
                                                   (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                   (0xff < s_v10))));
          u_v14 = (ushort)((ulonglong)u_v2 >> 0x10);
          u_v7 = *(cri_u64 *)((((int)u_v17 >> 8) << 3) + a3);
          (*(short*)&au_v39.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v39.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v39.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v39.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v39.b[8]) = 0;
          au_v35 = psraw(au_v39,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          *pu_v25 = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                              CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                       (0xff < s_v12),
                                       CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                (0xff < s_v11),
                                                (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                (0xff < s_v10))));
          u_v7 = *(cri_u64 *)((int)((u_v14 & 0xff) << 3) + a3);
          (*(short*)&au_v40.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v40.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v40.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v40.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v40.b[8]) = 0;
          au_v35 = psraw(au_v40,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[1] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v7 = *(cri_u64 *)((((int)(uint)u_v14 >> 8) << 3) + a3);
          u_v17 = (uint)(ushort)((ulonglong)u_v5 >> 0x10);
          (*(short*)&au_v61.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v61.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v61.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v61.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v61.b[8]) = 0;
          au_v35 = psraw(au_v61,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[2] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v7 = *(cri_u64 *)((longlong)(int)((u_v17 & 0xff) << 3) + 0x800 + a3);
          u_v8 = *(cri_u64 *)((longlong)(int)((u_v26 & 0xff) << 3) + 0x1000 + a3);
          u_v14 = (ushort)((ulonglong)u_v1 >> 0x20);
          s_v59 = (short)u_v7 + (short)u_v8;
          s_v68 = (short)((ulonglong)u_v7 >> 0x10) + (short)((ulonglong)u_v8 >> 0x10);
          s_v69 = (short)((ulonglong)u_v7 >> 0x20) + (short)((ulonglong)u_v8 >> 0x20);
          s_v70 = (short)((ulonglong)u_v7 >> 0x30) + (short)((ulonglong)u_v8 >> 0x30);
          u_v7 = *(cri_u64 *)((int)((u_v14 & 0xff) << 3) + a3);
          (*(short*)&au_v41.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v41.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v41.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v41.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v41.b[8]) = 0;
          au_v35 = psraw(au_v41,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[1] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v15 = (ushort)((ulonglong)u_v2 >> 0x20);
          u_v7 = *(cri_u64 *)((((int)(uint)u_v14 >> 8) << 3) + a3);
          (*(short*)&au_v42.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v42.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v42.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v42.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v42.b[8]) = 0;
          au_v35 = psraw(au_v42,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[2] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v7 = *(cri_u64 *)((int)((u_v15 & 0xff) << 3) + a3);
          (*(short*)&au_v43.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v43.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v43.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v43.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v43.b[8]) = 0;
          au_v35 = psraw(au_v43,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[3] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v14 = (ushort)((ulonglong)u_v1 >> 0x30);
          u_v1 = *(cri_u64 *)((((int)(uint)u_v15 >> 8) << 3) + a3);
          (*(short*)&au_v62.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v62.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v62.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v62.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v62.b[8]) = 0;
          au_v35 = psraw(au_v62,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[4] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((longlong)(((int)u_v17 >> 8) << 3) + 0x800 + a3);
          u_v27 = (uint)(ushort)((ulonglong)u_v6 >> 0x20);
          u_v7 = *(cri_u64 *)((longlong)(((int)u_v26 >> 8) << 3) + 0x1000 + a3);
          s_v59 = (short)u_v1 + (short)u_v7;
          s_v68 = (short)((ulonglong)u_v1 >> 0x10) + (short)((ulonglong)u_v7 >> 0x10);
          s_v69 = (short)((ulonglong)u_v1 >> 0x20) + (short)((ulonglong)u_v7 >> 0x20);
          s_v70 = (short)((ulonglong)u_v1 >> 0x30) + (short)((ulonglong)u_v7 >> 0x30);
          u_v1 = *(cri_u64 *)((int)((u_v14 & 0xff) << 3) + a3);
          (*(short*)&au_v44.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v44.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v44.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v44.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v44.b[8]) = 0;
          au_v35 = psraw(au_v44,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[3] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v15 = (ushort)((ulonglong)u_v2 >> 0x30);
          u_v1 = *(cri_u64 *)((((int)(uint)u_v14 >> 8) << 3) + a3);
          (*(short*)&au_v45.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v45.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v45.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v45.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v45.b[8]) = 0;
          au_v35 = psraw(au_v45,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[4] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((int)((u_v15 & 0xff) << 3) + a3);
          (*(short*)&au_v46.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v46.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v46.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v46.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v46.b[8]) = 0;
          au_v35 = psraw(au_v46,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[5] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((((int)(uint)u_v15 >> 8) << 3) + a3);
          u_v26 = (uint)(ushort)((ulonglong)u_v5 >> 0x20);
          (*(short*)&au_v63.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v63.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v63.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v63.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v63.b[8]) = 0;
          au_v35 = psraw(au_v63,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[6] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((longlong)(int)((u_v26 & 0xff) << 3) + 0x800 + a3);
          u_v2 = *(cri_u64 *)((longlong)(int)((u_v27 & 0xff) << 3) + 0x1000 + a3);
          s_v59 = (short)u_v1 + (short)u_v2;
          s_v68 = (short)((ulonglong)u_v1 >> 0x10) + (short)((ulonglong)u_v2 >> 0x10);
          s_v69 = (short)((ulonglong)u_v1 >> 0x20) + (short)((ulonglong)u_v2 >> 0x20);
          s_v70 = (short)((ulonglong)u_v1 >> 0x30) + (short)((ulonglong)u_v2 >> 0x30);
          u_v1 = *(cri_u64 *)((int)(((ushort)u_v3 & 0xff) << 3) + a3);
          (*(short*)&au_v47.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v47.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v47.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v47.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v47.b[8]) = 0;
          au_v35 = psraw(au_v47,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[5] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((((int)(uint)(ushort)u_v3 >> 8) << 3) + a3);
          (*(short*)&au_v48.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v48.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v48.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v48.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v48.b[8]) = 0;
          au_v35 = psraw(au_v48,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[6] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((int)(((ushort)u_v4 & 0xff) << 3) + a3);
          (*(short*)&au_v49.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v49.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v49.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v49.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v49.b[8]) = 0;
          au_v35 = psraw(au_v49,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[7] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v17 = (uint)(ushort)((ulonglong)u_v3 >> 0x10);
          u_v1 = *(cri_u64 *)((((int)(uint)(ushort)u_v4 >> 8) << 3) + a3);
          (*(short*)&au_v64.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v64.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v64.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v64.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v64.b[8]) = 0;
          au_v35 = psraw(au_v64,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[8] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((longlong)(((int)u_v26 >> 8) << 3) + 0x800 + a3);
          u_v2 = *(cri_u64 *)((longlong)(((int)u_v27 >> 8) << 3) + 0x1000 + a3);
          s_v59 = (short)u_v1 + (short)u_v2;
          s_v68 = (short)((ulonglong)u_v1 >> 0x10) + (short)((ulonglong)u_v2 >> 0x10);
          s_v69 = (short)((ulonglong)u_v1 >> 0x20) + (short)((ulonglong)u_v2 >> 0x20);
          s_v70 = (short)((ulonglong)u_v1 >> 0x30) + (short)((ulonglong)u_v2 >> 0x30);
          u_v1 = *(cri_u64 *)((int)((u_v17 & 0xff) << 3) + a3);
          (*(short*)&au_v50.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v50.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v50.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v50.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v50.b[8]) = 0;
          au_v35 = psraw(au_v50,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[7] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v27 = (uint)(ushort)((ulonglong)u_v6 >> 0x30);
          u_v14 = (ushort)((ulonglong)u_v4 >> 0x10);
          u_v1 = *(cri_u64 *)((((int)u_v17 >> 8) << 3) + a3);
          (*(short*)&au_v51.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v51.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v51.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v51.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v51.b[8]) = 0;
          au_v35 = psraw(au_v51,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[8] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((int)((u_v14 & 0xff) << 3) + a3);
          (*(short*)&au_v52.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v52.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v52.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v52.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v52.b[8]) = 0;
          au_v35 = psraw(au_v52,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[9] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((((int)(uint)u_v14 >> 8) << 3) + a3);
          u_v26 = (uint)(ushort)((ulonglong)u_v5 >> 0x30);
          (*(short*)&au_v65.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v65.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v65.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v65.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v65.b[8]) = 0;
          au_v35 = psraw(au_v65,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[10] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                 CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                          (0xff < s_v12),
                                          CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                   (0xff < s_v11),
                                                   (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                   (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((longlong)(int)((u_v26 & 0xff) << 3) + 0x800 + a3);
          u_v2 = *(cri_u64 *)((longlong)(int)((u_v27 & 0xff) << 3) + 0x1000 + a3);
          u_v14 = (ushort)((ulonglong)u_v3 >> 0x20);
          s_v59 = (short)u_v1 + (short)u_v2;
          s_v68 = (short)((ulonglong)u_v1 >> 0x10) + (short)((ulonglong)u_v2 >> 0x10);
          s_v69 = (short)((ulonglong)u_v1 >> 0x20) + (short)((ulonglong)u_v2 >> 0x20);
          s_v70 = (short)((ulonglong)u_v1 >> 0x30) + (short)((ulonglong)u_v2 >> 0x30);
          u_v1 = *(cri_u64 *)((int)((u_v14 & 0xff) << 3) + a3);
          (*(short*)&au_v53.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v53.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v53.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v53.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v53.b[8]) = 0;
          au_v35 = psraw(au_v53,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[9] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v17 = (uint)(ushort)((ulonglong)u_v4 >> 0x20);
          u_v1 = *(cri_u64 *)((((int)(uint)u_v14 >> 8) << 3) + a3);
          (*(short*)&au_v54.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v54.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v54.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v54.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v54.b[8]) = 0;
          au_v35 = psraw(au_v54,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[10] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                 CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                          (0xff < s_v12),
                                          CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                   (0xff < s_v11),
                                                   (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                   (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((int)((u_v17 & 0xff) << 3) + a3);
          (*(short*)&au_v55.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v55.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v55.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v55.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v55.b[8]) = 0;
          au_v35 = psraw(au_v55,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[0xb] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                  CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                           (0xff < s_v12),
                                           CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                    (0xff < s_v11),
                                                    (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                    (0xff < s_v10))));
          u_v14 = (ushort)((ulonglong)u_v3 >> 0x30);
          i_v21 = i_v21 + 8;
          i_v29 = i_v29 + 0x10;
          u_v1 = *(cri_u64 *)((((int)u_v17 >> 8) << 3) + a3);
          (*(short*)&au_v66.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v66.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v66.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v66.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v66.b[8]) = 0;
          au_v35 = psraw(au_v66,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[0xc] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                  CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                           (0xff < s_v12),
                                           CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                    (0xff < s_v11),
                                                    (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                    (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((longlong)(((int)u_v26 >> 8) << 3) + 0x800 + a3);
          u_v2 = *(cri_u64 *)((longlong)(((int)u_v27 >> 8) << 3) + 0x1000 + a3);
          s_v59 = (short)u_v1 + (short)u_v2;
          s_v68 = (short)((ulonglong)u_v1 >> 0x10) + (short)((ulonglong)u_v2 >> 0x10);
          s_v69 = (short)((ulonglong)u_v1 >> 0x20) + (short)((ulonglong)u_v2 >> 0x20);
          s_v70 = (short)((ulonglong)u_v1 >> 0x30) + (short)((ulonglong)u_v2 >> 0x30);
          u_v1 = *(cri_u64 *)((int)((u_v14 & 0xff) << 3) + a3);
          (*(short*)&au_v56.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v56.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v56.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v56.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v56.b[8]) = 0;
          au_v35 = psraw(au_v56,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[0xb] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                  CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                           (0xff < s_v12),
                                           CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                    (0xff < s_v11),
                                                    (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                    (0xff < s_v10))));
          u_v15 = (ushort)((ulonglong)u_v4 >> 0x30);
          u_v1 = *(cri_u64 *)((((int)(uint)u_v14 >> 8) << 3) + a3);
          (*(short*)&au_v57.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v57.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v57.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v57.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v57.b[8]) = 0;
          au_v35 = psraw(au_v57,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[0xc] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                  CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                           (0xff < s_v12),
                                           CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                    (0xff < s_v11),
                                                    (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                    (0xff < s_v10))));
          l_v28 = l_v28 + -1;
          u_v1 = *(cri_u64 *)((int)((u_v15 & 0xff) << 3) + a3);
          (*(short*)&au_v58.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v58.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v58.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v58.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v58.b[8]) = 0;
          au_v35 = psraw(au_v58,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[0xd] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                  CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                           (0xff < s_v12),
                                           CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                    (0xff < s_v11),
                                                    (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                    (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((((int)(uint)u_v15 >> 8) << 3) + a3);
          (*(short*)&au_v67.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v67.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v67.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v67.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v67.b[8]) = 0;
          au_v35 = psraw(au_v67,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[0xe] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                  CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                           (0xff < s_v12),
                                           CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                    (0xff < s_v11),
                                                    (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                    (0xff < s_v10))));
          pu_v23 = pu_v23 + 0x10;
          pu_v25 = pu_v25 + 0x10;
        } while (l_v28 != 0);
      }
      l_v22 = l_v22 + a5;
      l_v30 = l_v30 + a5;
      l_v32 = l_v32 + l_v24;
      l_v31 = l_v31 + l_v24;
      l_v34 = l_v34 + (int)l_v16;
      l_v33 = l_v33 + i_v9;
      u_v19 = u_v19 - 1;
    } while (u_v19 != 0);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004a7c0
void FUN_14004a7c0(longlong *a1,longlong *a2,longlong a3,int a4,int a5)
{
  cri_u64 u_v1;
  cri_u64 u_v2;
  cri_u64 u_v3;
  cri_u64 u_v4;
  cri_u64 u_v5;
  cri_u64 u_v6;
  cri_u64 u_v7;
  cri_u64 u_v8;
  int i_v9;
  short s_v10;
  short s_v11;
  short s_v12;
  short s_v13;
  ushort u_v14;
  ushort u_v15;
  longlong l_v16;
  uint u_v17;
  longlong l_v18;
  ulonglong u_v19;
  longlong l_v20;
  int i_v21;
  longlong l_v22;
  cri_u32 *pu_v23;
  longlong l_v24;
  cri_u32 *pu_v25;
  uint u_v26;
  uint u_v27;
  longlong l_v28;
  int i_v29;
  longlong l_v30;
  longlong l_v31;
  longlong l_v32;
  longlong l_v33;
  longlong l_v34;
  V16 au_v35;
  V16 au_v36;
  V16 au_v37;
  V16 au_v38;
  V16 au_v39;
  V16 au_v40;
  V16 au_v41;
  V16 au_v42;
  V16 au_v43;
  V16 au_v44;
  V16 au_v45;
  V16 au_v46;
  V16 au_v47;
  V16 au_v48;
  V16 au_v49;
  V16 au_v50;
  V16 au_v51;
  V16 au_v52;
  V16 au_v53;
  V16 au_v54;
  V16 au_v55;
  V16 au_v56;
  V16 au_v57;
  V16 au_v58;
  short s_v59;
  short s_v68;
  short s_v69;
  short s_v70;
  V16 au_v60;
  V16 au_v61;
  V16 au_v62;
  V16 au_v63;
  V16 au_v64;
  V16 au_v65;
  V16 au_v66;
  V16 au_v67;
  
  FUN_1400627f0("cft_mmx_Ycc420plnToArgb8888UserTable");
  l_v22 = *a2;
  l_v32 = *a1;
  l_v33 = a1[1];
  l_v34 = a1[2];
  l_v30 = l_v22 + a4;
  l_v31 = l_v32 + (int)a1[3];
  l_v20 = (longlong)((int)a2[1] / 2);
  u_v17 = CriAt<int>(a2, 0xc) / 2;
  u_v19 = (ulonglong)u_v17;
  if (0 < (int)u_v17) {
    l_v16 = a1[4];
    i_v9 = CriAt<int>(a1, 0x1c);
    l_v24 = (longlong)((int)a1[3] * 2);
    do {
      i_v21 = 0;
      if (0 < l_v20) {
        l_v28 = (l_v20 - 1U >> 3) + 1;
        pu_v23 = (&CriAt<cri_u32>(l_v30, 0x4));
        pu_v25 = (&CriAt<cri_u32>(l_v22, 0xc));
        i_v29 = i_v21;
        do {
          l_v18 = (longlong)i_v29;
          u_v1 = *(cri_u64 *)(l_v18 + l_v32);
          u_v2 = *(cri_u64 *)(l_v18 + l_v31);
          u_v3 = *(cri_u64 *)(l_v18 + 8 + l_v32);
          u_v4 = *(cri_u64 *)(l_v18 + 8 + l_v31);
          u_v5 = *(cri_u64 *)(i_v21 + l_v33);
          u_v6 = *(cri_u64 *)(i_v21 + l_v34);
          u_v7 = *(cri_u64 *)((longlong)(int)(((ushort)u_v5 & 0xff) << 3) + 0x800 + a3);
          u_v8 = *(cri_u64 *)((longlong)(int)(((ushort)u_v6 & 0xff) << 3) + 0x1000 + a3);
          s_v59 = (short)u_v7 + (short)u_v8;
          s_v68 = (short)((ulonglong)u_v7 >> 0x10) + (short)((ulonglong)u_v8 >> 0x10);
          s_v69 = (short)((ulonglong)u_v7 >> 0x20) + (short)((ulonglong)u_v8 >> 0x20);
          s_v70 = (short)((ulonglong)u_v7 >> 0x30) + (short)((ulonglong)u_v8 >> 0x30);
          u_v7 = *(cri_u64 *)((int)(((ushort)u_v1 & 0xff) << 3) + a3);
          (*(short*)&au_v35.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v35.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v35.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v35.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v35.b[8]) = 0;
          au_v35 = psraw(au_v35,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[-3] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                 CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                          (0xff < s_v12),
                                          CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                   (0xff < s_v11),
                                                   (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                   (0xff < s_v10))));
          u_v7 = *(cri_u64 *)((((int)(uint)(ushort)u_v1 >> 8) << 3) + a3);
          (*(short*)&au_v36.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v36.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v36.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v36.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v36.b[8]) = 0;
          au_v35 = psraw(au_v36,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          *(uint *)((l_v22 - l_v30) + (longlong)pu_v23) =
               CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                        CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] - (0xff < s_v12),
                                 CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                          (0xff < s_v11),
                                          (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                          (0xff < s_v10))));
          u_v7 = *(cri_u64 *)((int)(((ushort)u_v2 & 0xff) << 3) + a3);
          (*(short*)&au_v37.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v37.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v37.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v37.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v37.b[8]) = 0;
          au_v35 = psraw(au_v37,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[-1] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                 CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                          (0xff < s_v12),
                                          CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                   (0xff < s_v11),
                                                   (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                   (0xff < s_v10))));
          u_v17 = (uint)(ushort)((ulonglong)u_v1 >> 0x10);
          u_v7 = *(cri_u64 *)((((int)(uint)(ushort)u_v2 >> 8) << 3) + a3);
          (*(short*)&au_v60.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v60.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v60.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v60.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v60.b[8]) = 0;
          au_v35 = psraw(au_v60,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          *pu_v23 = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                              CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                       (0xff < s_v12),
                                       CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                (0xff < s_v11),
                                                (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                (0xff < s_v10))));
          u_v7 = *(cri_u64 *)
                   ((longlong)(((int)(uint)(ushort)u_v5 >> 8) << 3) + 0x800 + a3);
          u_v8 = *(cri_u64 *)
                   ((longlong)(((int)(uint)(ushort)u_v6 >> 8) << 3) + 0x1000 + a3);
          s_v59 = (short)u_v7 + (short)u_v8;
          s_v68 = (short)((ulonglong)u_v7 >> 0x10) + (short)((ulonglong)u_v8 >> 0x10);
          s_v69 = (short)((ulonglong)u_v7 >> 0x20) + (short)((ulonglong)u_v8 >> 0x20);
          s_v70 = (short)((ulonglong)u_v7 >> 0x30) + (short)((ulonglong)u_v8 >> 0x30);
          u_v26 = (uint)(ushort)((ulonglong)u_v6 >> 0x10);
          u_v7 = *(cri_u64 *)((int)((u_v17 & 0xff) << 3) + a3);
          (*(short*)&au_v38.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v38.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v38.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v38.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v38.b[8]) = 0;
          au_v35 = psraw(au_v38,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[-1] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                 CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                          (0xff < s_v12),
                                          CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                   (0xff < s_v11),
                                                   (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                   (0xff < s_v10))));
          u_v14 = (ushort)((ulonglong)u_v2 >> 0x10);
          u_v7 = *(cri_u64 *)((((int)u_v17 >> 8) << 3) + a3);
          (*(short*)&au_v39.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v39.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v39.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v39.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v39.b[8]) = 0;
          au_v35 = psraw(au_v39,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          *pu_v25 = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                              CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                       (0xff < s_v12),
                                       CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                (0xff < s_v11),
                                                (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                (0xff < s_v10))));
          u_v7 = *(cri_u64 *)((int)((u_v14 & 0xff) << 3) + a3);
          (*(short*)&au_v40.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v40.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v40.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v40.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v40.b[8]) = 0;
          au_v35 = psraw(au_v40,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[1] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v7 = *(cri_u64 *)((((int)(uint)u_v14 >> 8) << 3) + a3);
          u_v17 = (uint)(ushort)((ulonglong)u_v5 >> 0x10);
          (*(short*)&au_v61.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v61.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v61.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v61.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v61.b[8]) = 0;
          au_v35 = psraw(au_v61,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[2] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v7 = *(cri_u64 *)((longlong)(int)((u_v17 & 0xff) << 3) + 0x800 + a3);
          u_v8 = *(cri_u64 *)((longlong)(int)((u_v26 & 0xff) << 3) + 0x1000 + a3);
          u_v14 = (ushort)((ulonglong)u_v1 >> 0x20);
          s_v59 = (short)u_v7 + (short)u_v8;
          s_v68 = (short)((ulonglong)u_v7 >> 0x10) + (short)((ulonglong)u_v8 >> 0x10);
          s_v69 = (short)((ulonglong)u_v7 >> 0x20) + (short)((ulonglong)u_v8 >> 0x20);
          s_v70 = (short)((ulonglong)u_v7 >> 0x30) + (short)((ulonglong)u_v8 >> 0x30);
          u_v7 = *(cri_u64 *)((int)((u_v14 & 0xff) << 3) + a3);
          (*(short*)&au_v41.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v41.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v41.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v41.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v41.b[8]) = 0;
          au_v35 = psraw(au_v41,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[1] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v15 = (ushort)((ulonglong)u_v2 >> 0x20);
          u_v7 = *(cri_u64 *)((((int)(uint)u_v14 >> 8) << 3) + a3);
          (*(short*)&au_v42.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v42.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v42.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v42.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v42.b[8]) = 0;
          au_v35 = psraw(au_v42,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[2] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v7 = *(cri_u64 *)((int)((u_v15 & 0xff) << 3) + a3);
          (*(short*)&au_v43.b[0]) = s_v59 + (short)u_v7;
          (*(short*)&au_v43.b[2]) = s_v68 + (short)((ulonglong)u_v7 >> 0x10);
          (*(short*)&au_v43.b[4]) = s_v69 + (short)((ulonglong)u_v7 >> 0x20);
          (*(short*)&au_v43.b[6]) = s_v70 + (short)((ulonglong)u_v7 >> 0x30);
          (*(__int64*)&au_v43.b[8]) = 0;
          au_v35 = psraw(au_v43,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[3] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v14 = (ushort)((ulonglong)u_v1 >> 0x30);
          u_v1 = *(cri_u64 *)((((int)(uint)u_v15 >> 8) << 3) + a3);
          (*(short*)&au_v62.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v62.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v62.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v62.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v62.b[8]) = 0;
          au_v35 = psraw(au_v62,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[4] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((longlong)(((int)u_v17 >> 8) << 3) + 0x800 + a3);
          u_v27 = (uint)(ushort)((ulonglong)u_v6 >> 0x20);
          u_v7 = *(cri_u64 *)((longlong)(((int)u_v26 >> 8) << 3) + 0x1000 + a3);
          s_v59 = (short)u_v1 + (short)u_v7;
          s_v68 = (short)((ulonglong)u_v1 >> 0x10) + (short)((ulonglong)u_v7 >> 0x10);
          s_v69 = (short)((ulonglong)u_v1 >> 0x20) + (short)((ulonglong)u_v7 >> 0x20);
          s_v70 = (short)((ulonglong)u_v1 >> 0x30) + (short)((ulonglong)u_v7 >> 0x30);
          u_v1 = *(cri_u64 *)((int)((u_v14 & 0xff) << 3) + a3);
          (*(short*)&au_v44.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v44.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v44.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v44.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v44.b[8]) = 0;
          au_v35 = psraw(au_v44,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[3] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v15 = (ushort)((ulonglong)u_v2 >> 0x30);
          u_v1 = *(cri_u64 *)((((int)(uint)u_v14 >> 8) << 3) + a3);
          (*(short*)&au_v45.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v45.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v45.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v45.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v45.b[8]) = 0;
          au_v35 = psraw(au_v45,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[4] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((int)((u_v15 & 0xff) << 3) + a3);
          (*(short*)&au_v46.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v46.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v46.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v46.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v46.b[8]) = 0;
          au_v35 = psraw(au_v46,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[5] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((((int)(uint)u_v15 >> 8) << 3) + a3);
          u_v26 = (uint)(ushort)((ulonglong)u_v5 >> 0x20);
          (*(short*)&au_v63.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v63.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v63.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v63.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v63.b[8]) = 0;
          au_v35 = psraw(au_v63,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[6] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((longlong)(int)((u_v26 & 0xff) << 3) + 0x800 + a3);
          u_v2 = *(cri_u64 *)((longlong)(int)((u_v27 & 0xff) << 3) + 0x1000 + a3);
          s_v59 = (short)u_v1 + (short)u_v2;
          s_v68 = (short)((ulonglong)u_v1 >> 0x10) + (short)((ulonglong)u_v2 >> 0x10);
          s_v69 = (short)((ulonglong)u_v1 >> 0x20) + (short)((ulonglong)u_v2 >> 0x20);
          s_v70 = (short)((ulonglong)u_v1 >> 0x30) + (short)((ulonglong)u_v2 >> 0x30);
          u_v1 = *(cri_u64 *)((int)(((ushort)u_v3 & 0xff) << 3) + a3);
          (*(short*)&au_v47.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v47.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v47.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v47.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v47.b[8]) = 0;
          au_v35 = psraw(au_v47,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[5] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((((int)(uint)(ushort)u_v3 >> 8) << 3) + a3);
          (*(short*)&au_v48.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v48.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v48.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v48.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v48.b[8]) = 0;
          au_v35 = psraw(au_v48,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[6] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((int)(((ushort)u_v4 & 0xff) << 3) + a3);
          (*(short*)&au_v49.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v49.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v49.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v49.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v49.b[8]) = 0;
          au_v35 = psraw(au_v49,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[7] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v17 = (uint)(ushort)((ulonglong)u_v3 >> 0x10);
          u_v1 = *(cri_u64 *)((((int)(uint)(ushort)u_v4 >> 8) << 3) + a3);
          (*(short*)&au_v64.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v64.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v64.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v64.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v64.b[8]) = 0;
          au_v35 = psraw(au_v64,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[8] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((longlong)(((int)u_v26 >> 8) << 3) + 0x800 + a3);
          u_v2 = *(cri_u64 *)((longlong)(((int)u_v27 >> 8) << 3) + 0x1000 + a3);
          s_v59 = (short)u_v1 + (short)u_v2;
          s_v68 = (short)((ulonglong)u_v1 >> 0x10) + (short)((ulonglong)u_v2 >> 0x10);
          s_v69 = (short)((ulonglong)u_v1 >> 0x20) + (short)((ulonglong)u_v2 >> 0x20);
          s_v70 = (short)((ulonglong)u_v1 >> 0x30) + (short)((ulonglong)u_v2 >> 0x30);
          u_v1 = *(cri_u64 *)((int)((u_v17 & 0xff) << 3) + a3);
          (*(short*)&au_v50.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v50.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v50.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v50.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v50.b[8]) = 0;
          au_v35 = psraw(au_v50,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[7] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v27 = (uint)(ushort)((ulonglong)u_v6 >> 0x30);
          u_v14 = (ushort)((ulonglong)u_v4 >> 0x10);
          u_v1 = *(cri_u64 *)((((int)u_v17 >> 8) << 3) + a3);
          (*(short*)&au_v51.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v51.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v51.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v51.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v51.b[8]) = 0;
          au_v35 = psraw(au_v51,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[8] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((int)((u_v14 & 0xff) << 3) + a3);
          (*(short*)&au_v52.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v52.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v52.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v52.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v52.b[8]) = 0;
          au_v35 = psraw(au_v52,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[9] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((((int)(uint)u_v14 >> 8) << 3) + a3);
          u_v26 = (uint)(ushort)((ulonglong)u_v5 >> 0x30);
          (*(short*)&au_v65.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v65.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v65.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v65.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v65.b[8]) = 0;
          au_v35 = psraw(au_v65,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[10] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                 CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                          (0xff < s_v12),
                                          CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                   (0xff < s_v11),
                                                   (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                   (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((longlong)(int)((u_v26 & 0xff) << 3) + 0x800 + a3);
          u_v2 = *(cri_u64 *)((longlong)(int)((u_v27 & 0xff) << 3) + 0x1000 + a3);
          u_v14 = (ushort)((ulonglong)u_v3 >> 0x20);
          s_v59 = (short)u_v1 + (short)u_v2;
          s_v68 = (short)((ulonglong)u_v1 >> 0x10) + (short)((ulonglong)u_v2 >> 0x10);
          s_v69 = (short)((ulonglong)u_v1 >> 0x20) + (short)((ulonglong)u_v2 >> 0x20);
          s_v70 = (short)((ulonglong)u_v1 >> 0x30) + (short)((ulonglong)u_v2 >> 0x30);
          u_v1 = *(cri_u64 *)((int)((u_v14 & 0xff) << 3) + a3);
          (*(short*)&au_v53.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v53.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v53.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v53.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v53.b[8]) = 0;
          au_v35 = psraw(au_v53,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[9] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                         (0xff < s_v12),
                                         CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                  (0xff < s_v11),
                                                  (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                  (0xff < s_v10))));
          u_v17 = (uint)(ushort)((ulonglong)u_v4 >> 0x20);
          u_v1 = *(cri_u64 *)((((int)(uint)u_v14 >> 8) << 3) + a3);
          (*(short*)&au_v54.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v54.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v54.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v54.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v54.b[8]) = 0;
          au_v35 = psraw(au_v54,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[10] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                 CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                          (0xff < s_v12),
                                          CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                   (0xff < s_v11),
                                                   (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                   (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((int)((u_v17 & 0xff) << 3) + a3);
          (*(short*)&au_v55.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v55.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v55.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v55.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v55.b[8]) = 0;
          au_v35 = psraw(au_v55,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[0xb] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                  CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                           (0xff < s_v12),
                                           CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                    (0xff < s_v11),
                                                    (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                    (0xff < s_v10))));
          u_v14 = (ushort)((ulonglong)u_v3 >> 0x30);
          i_v21 = i_v21 + 8;
          i_v29 = i_v29 + 0x10;
          u_v1 = *(cri_u64 *)((((int)u_v17 >> 8) << 3) + a3);
          (*(short*)&au_v66.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v66.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v66.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v66.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v66.b[8]) = 0;
          au_v35 = psraw(au_v66,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[0xc] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                  CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                           (0xff < s_v12),
                                           CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                    (0xff < s_v11),
                                                    (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                    (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((longlong)(((int)u_v26 >> 8) << 3) + 0x800 + a3);
          u_v2 = *(cri_u64 *)((longlong)(((int)u_v27 >> 8) << 3) + 0x1000 + a3);
          s_v59 = (short)u_v1 + (short)u_v2;
          s_v68 = (short)((ulonglong)u_v1 >> 0x10) + (short)((ulonglong)u_v2 >> 0x10);
          s_v69 = (short)((ulonglong)u_v1 >> 0x20) + (short)((ulonglong)u_v2 >> 0x20);
          s_v70 = (short)((ulonglong)u_v1 >> 0x30) + (short)((ulonglong)u_v2 >> 0x30);
          u_v1 = *(cri_u64 *)((int)((u_v14 & 0xff) << 3) + a3);
          (*(short*)&au_v56.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v56.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v56.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v56.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v56.b[8]) = 0;
          au_v35 = psraw(au_v56,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[0xb] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                  CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                           (0xff < s_v12),
                                           CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                    (0xff < s_v11),
                                                    (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                    (0xff < s_v10))));
          u_v15 = (ushort)((ulonglong)u_v4 >> 0x30);
          u_v1 = *(cri_u64 *)((((int)(uint)u_v14 >> 8) << 3) + a3);
          (*(short*)&au_v57.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v57.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v57.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v57.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v57.b[8]) = 0;
          au_v35 = psraw(au_v57,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v25[0xc] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                  CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                           (0xff < s_v12),
                                           CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                    (0xff < s_v11),
                                                    (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                    (0xff < s_v10))));
          l_v28 = l_v28 + -1;
          u_v1 = *(cri_u64 *)((int)((u_v15 & 0xff) << 3) + a3);
          (*(short*)&au_v58.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v58.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v58.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v58.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v58.b[8]) = 0;
          au_v35 = psraw(au_v58,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[0xd] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                  CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                           (0xff < s_v12),
                                           CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                    (0xff < s_v11),
                                                    (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                    (0xff < s_v10))));
          u_v1 = *(cri_u64 *)((((int)(uint)u_v15 >> 8) << 3) + a3);
          (*(short*)&au_v67.b[0]) = s_v59 + (short)u_v1;
          (*(short*)&au_v67.b[2]) = s_v68 + (short)((ulonglong)u_v1 >> 0x10);
          (*(short*)&au_v67.b[4]) = s_v69 + (short)((ulonglong)u_v1 >> 0x20);
          (*(short*)&au_v67.b[6]) = s_v70 + (short)((ulonglong)u_v1 >> 0x30);
          (*(__int64*)&au_v67.b[8]) = 0;
          au_v35 = psraw(au_v67,6);
          s_v10 = (*(short*)&au_v35.b[0]);
          s_v11 = (*(short*)&au_v35.b[2]);
          s_v12 = (*(short*)&au_v35.b[4]);
          s_v13 = (*(short*)&au_v35.b[6]);
          pu_v23[0xe] = CONCAT13((0 < s_v13) * (s_v13 < 0x100) * au_v35.b[6] - (0xff < s_v13),
                                  CONCAT12((0 < s_v12) * (s_v12 < 0x100) * au_v35.b[4] -
                                           (0xff < s_v12),
                                           CONCAT11((0 < s_v11) * (s_v11 < 0x100) * au_v35.b[2] -
                                                    (0xff < s_v11),
                                                    (0 < s_v10) * (s_v10 < 0x100) * au_v35.b[0] -
                                                    (0xff < s_v10))));
          pu_v23 = pu_v23 + 0x10;
          pu_v25 = pu_v25 + 0x10;
        } while (l_v28 != 0);
      }
      l_v22 = l_v22 + a5;
      l_v30 = l_v30 + a5;
      l_v32 = l_v32 + l_v24;
      l_v31 = l_v31 + l_v24;
      l_v34 = l_v34 + (int)l_v16;
      l_v33 = l_v33 + i_v9;
      u_v19 = u_v19 - 1;
    } while (u_v19 != 0);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004b120
void FUN_14004b120(cri_u64 *a1,longlong *a2,longlong a3,int a4,int a5)
{
  byte b_v1;
  uint u_v2;
  cri_u64 u_v3;
  cri_u64 u_v4;
  cri_u64 u_v5;
  cri_u64 u_v6;
  short s_v7;
  short s_v8;
  int i_v9;
  uint u_v10;
  ulonglong u_v11;
  byte *pb_v12;
  short s_v13;
  int i_v14;
  byte *pb_v15;
  short s_v16;
  uint u_v17;
  uint *pu_v18;
  short s_v19;
  short s_v20;
  short s_v21;
  uint u_v22;
  int i_v23;
  int i_v24;
  ulonglong u_v25;
  short s_v26;
  byte *pb_v27;
  int i_v28;
  int i_v29;
  uint *pu_v30;
  int i_v31;
  byte *pb_v32;
  int i_v33;
  byte *loc_b0;
  byte *loc_a8;
  uint *loc_a0;
  byte *loc_98;
  byte *loc_90;
  uint *loc_88;
  int loc_7c;
  ulonglong loc_68;
  
  FUN_1400627f0("cft_c_Ycc420plnToArgb8888UserTable");
  loc_a0 = (uint *)*a2;
  pb_v12 = (byte *)*a1;
  loc_b0 = (byte *)a1[1];
  loc_a8 = (byte *)a1[2];
  pb_v15 = pb_v12 + CriAt<int>(a1, 0x18);
  loc_7c = 0;
  loc_88 = loc_a0 + ((int)(a4 + (a4 >> 0x1f & 3U)) >> 2);
  u_v2 = CriAt<uint>(a2, 0x8);
  u_v22 = CriAt<int>(a1, 0x18) * 2 - u_v2;
  u_v10 = u_v2 & 1;
  u_v17 = u_v10 + u_v2 >> 1;
  if (1 < CriAt<int>(a2, 0xc)) {
    u_v25 = (ulonglong)(CriAt<int>(a1, 0x1c) - u_v17);
    u_v11 = (ulonglong)(a5 + u_v2 * -4) & 0xfffffffffffffffc;
    do {
      loc_68 = (ulonglong)(u_v17 - 1);
      if (u_v17 - 1 != 0) {
        do {
          u_v3 = *(cri_u64 *)(a3 + 0x1000 + (ulonglong)*loc_a8 * 8);
          u_v4 = *(cri_u64 *)(a3 + 0x800 + (ulonglong)*loc_b0 * 8);
          u_v5 = *(cri_u64 *)(a3 + (ulonglong)*pb_v12 * 8);
          u_v6 = *(cri_u64 *)(a3 + (ulonglong)*pb_v15 * 8);
          loc_b0 = loc_b0 + 1;
          i_v29 = (int)(short)u_v3;
          i_v33 = (int)(short)((ulonglong)u_v3 >> 0x10);
          pb_v27 = pb_v15 + 1;
          loc_a8 = loc_a8 + 1;
          pb_v32 = pb_v12 + 1;
          i_v23 = (int)(short)((ulonglong)u_v4 >> 0x10);
          i_v31 = (int)(short)u_v4;
          i_v9 = (int)(short)((ulonglong)u_v3 >> 0x30);
          i_v28 = (int)(short)((ulonglong)u_v3 >> 0x20);
          i_v24 = (int)(short)((ulonglong)u_v4 >> 0x20);
          i_v14 = (int)(short)((ulonglong)u_v4 >> 0x30);
          s_v26 = (short)((int)(short)((ulonglong)u_v5 >> 0x10) + i_v23 + i_v33 >> 6);
          s_v7 = (short)((int)(short)((ulonglong)u_v5 >> 0x30) + i_v14 + i_v9 >> 6);
          s_v21 = (short)((int)(short)((ulonglong)u_v5 >> 0x20) + i_v24 + i_v28 >> 6);
          s_v16 = (short)((int)(short)u_v5 + i_v31 + i_v29 >> 6);
          if (s_v16 < 1) {
            s_v16 = 0;
          }
          if (s_v26 < 1) {
            s_v26 = 0;
          }
          if (s_v21 < 1) {
            s_v21 = 0;
          }
          if (s_v7 < 1) {
            s_v7 = 0;
          }
          if (0xfe < s_v16) {
            s_v16 = 0xff;
          }
          if (0xfe < s_v26) {
            s_v26 = 0xff;
          }
          if (0xfe < s_v21) {
            s_v21 = 0xff;
          }
          if (0xfe < s_v7) {
            s_v7 = 0xff;
          }
          s_v13 = (short)((short)((ulonglong)u_v6 >> 0x10) + i_v23 + i_v33 >> 6);
          s_v8 = (short)((short)((ulonglong)u_v6 >> 0x30) + i_v14 + i_v9 >> 6);
          s_v19 = (short)((short)((ulonglong)u_v6 >> 0x20) + i_v24 + i_v28 >> 6);
          s_v20 = (short)((short)u_v6 + i_v31 + i_v29 >> 6);
          if (s_v20 < 1) {
            s_v20 = 0;
          }
          if (s_v13 < 1) {
            s_v13 = 0;
          }
          if (s_v19 < 1) {
            s_v19 = 0;
          }
          if (s_v8 < 1) {
            s_v8 = 0;
          }
          if (0xfe < s_v20) {
            s_v20 = 0xff;
          }
          if (0xfe < s_v13) {
            s_v13 = 0xff;
          }
          if (0xfe < s_v19) {
            s_v19 = 0xff;
          }
          if (0xfe < s_v8) {
            s_v8 = 0xff;
          }
          *loc_a0 = (((int)s_v7 << 8 | (int)s_v21) << 8 | (int)s_v26) << 8 | (int)s_v16;
          pb_v15 = pb_v15 + 2;
          *loc_88 = (((int)s_v8 << 8 | (int)s_v19) << 8 | (int)s_v13) << 8 | (int)s_v20;
          pu_v18 = loc_88 + 1;
          pb_v12 = pb_v12 + 2;
          u_v3 = *(cri_u64 *)(a3 + (ulonglong)*pb_v32 * 8);
          u_v4 = *(cri_u64 *)(a3 + (ulonglong)*pb_v27 * 8);
          s_v16 = (short)((int)(short)((ulonglong)u_v3 >> 0x10) + i_v23 + i_v33 >> 6);
          s_v7 = (short)((int)(short)((ulonglong)u_v3 >> 0x30) + i_v14 + i_v9 >> 6);
          s_v26 = (short)((int)(short)((ulonglong)u_v3 >> 0x20) + i_v24 + i_v28 >> 6);
          s_v21 = (short)((int)(short)u_v3 + i_v31 + i_v29 >> 6);
          if (s_v21 < 1) {
            s_v21 = 0;
          }
          if (s_v16 < 1) {
            s_v16 = 0;
          }
          if (s_v26 < 1) {
            s_v26 = 0;
          }
          if (s_v7 < 1) {
            s_v7 = 0;
          }
          if (0xfe < s_v21) {
            s_v21 = 0xff;
          }
          if (0xfe < s_v16) {
            s_v16 = 0xff;
          }
          if (0xfe < s_v26) {
            s_v26 = 0xff;
          }
          if (0xfe < s_v7) {
            s_v7 = 0xff;
          }
          s_v13 = (short)((short)((ulonglong)u_v4 >> 0x10) + i_v23 + i_v33 >> 6);
          s_v8 = (short)((short)((ulonglong)u_v4 >> 0x30) + i_v14 + i_v9 >> 6);
          s_v19 = (short)((short)((ulonglong)u_v4 >> 0x20) + i_v24 + i_v28 >> 6);
          s_v20 = (short)((short)u_v4 + i_v31 + i_v29 >> 6);
          if (s_v20 < 1) {
            s_v20 = 0;
          }
          if (s_v13 < 1) {
            s_v13 = 0;
          }
          if (s_v19 < 1) {
            s_v19 = 0;
          }
          if (s_v8 < 1) {
            s_v8 = 0;
          }
          if (0xfe < s_v20) {
            s_v20 = 0xff;
          }
          if (0xfe < s_v13) {
            s_v13 = 0xff;
          }
          if (0xfe < s_v19) {
            s_v19 = 0xff;
          }
          if (0xfe < s_v8) {
            s_v8 = 0xff;
          }
          loc_a0[1] = (((int)s_v7 << 8 | (int)s_v26) << 8 | (int)s_v16) << 8 | (int)s_v21;
          loc_a0 = loc_a0 + 2;
          loc_88 = loc_88 + 2;
          loc_68 = loc_68 - 1;
          *pu_v18 = (((int)s_v8 << 8 | (int)s_v19) << 8 | (int)s_v13) << 8 | (int)s_v20;
        } while (loc_68 != 0);
      }
      u_v3 = *(cri_u64 *)(a3 + 0x1000 + (ulonglong)*loc_a8 * 8);
      u_v4 = *(cri_u64 *)(a3 + 0x800 + (ulonglong)*loc_b0 * 8);
      u_v5 = *(cri_u64 *)(a3 + (ulonglong)*pb_v12 * 8);
      u_v6 = *(cri_u64 *)(a3 + (ulonglong)*pb_v15 * 8);
      i_v29 = (int)(short)u_v3;
      i_v33 = (int)(short)((ulonglong)u_v3 >> 0x10);
      loc_90 = pb_v15 + 1;
      loc_98 = pb_v12 + 1;
      i_v23 = (int)(short)((ulonglong)u_v4 >> 0x10);
      i_v31 = (int)(short)u_v4;
      i_v9 = (int)(short)((ulonglong)u_v3 >> 0x30);
      i_v28 = (int)(short)((ulonglong)u_v3 >> 0x20);
      i_v24 = (int)(short)((ulonglong)u_v4 >> 0x20);
      i_v14 = (int)(short)((ulonglong)u_v4 >> 0x30);
      s_v26 = (short)((int)(short)((ulonglong)u_v5 >> 0x10) + i_v23 + i_v33 >> 6);
      s_v7 = (short)((int)(short)((ulonglong)u_v5 >> 0x30) + i_v14 + i_v9 >> 6);
      s_v21 = (short)((int)(short)((ulonglong)u_v5 >> 0x20) + i_v24 + i_v28 >> 6);
      s_v16 = (short)((int)(short)u_v5 + i_v31 + i_v29 >> 6);
      if (s_v16 < 1) {
        s_v16 = 0;
      }
      if (s_v26 < 1) {
        s_v26 = 0;
      }
      if (s_v21 < 1) {
        s_v21 = 0;
      }
      if (s_v7 < 1) {
        s_v7 = 0;
      }
      if (0xfe < s_v16) {
        s_v16 = 0xff;
      }
      if (0xfe < s_v26) {
        s_v26 = 0xff;
      }
      if (0xfe < s_v21) {
        s_v21 = 0xff;
      }
      if (0xfe < s_v7) {
        s_v7 = 0xff;
      }
      s_v13 = (short)((short)((ulonglong)u_v6 >> 0x10) + i_v23 + i_v33 >> 6);
      s_v8 = (short)((short)((ulonglong)u_v6 >> 0x30) + i_v14 + i_v9 >> 6);
      s_v19 = (short)((short)((ulonglong)u_v6 >> 0x20) + i_v24 + i_v28 >> 6);
      s_v20 = (short)((short)u_v6 + i_v31 + i_v29 >> 6);
      if (s_v20 < 1) {
        s_v20 = 0;
      }
      if (s_v13 < 1) {
        s_v13 = 0;
      }
      if (s_v19 < 1) {
        s_v19 = 0;
      }
      if (s_v8 < 1) {
        s_v8 = 0;
      }
      if (0xfe < s_v20) {
        s_v20 = 0xff;
      }
      if (0xfe < s_v13) {
        s_v13 = 0xff;
      }
      if (0xfe < s_v19) {
        s_v19 = 0xff;
      }
      if (0xfe < s_v8) {
        s_v8 = 0xff;
      }
      pu_v30 = loc_a0 + 1;
      *loc_a0 = (((int)s_v7 << 8 | (int)s_v21) << 8 | (int)s_v26) << 8 | (int)s_v16;
      pu_v18 = loc_88 + 1;
      *loc_88 = (((int)s_v8 << 8 | (int)s_v19) << 8 | (int)s_v13) << 8 | (int)s_v20;
      if (u_v10 == 0) {
        b_v1 = *loc_98;
        loc_98 = pb_v12 + 2;
        u_v3 = *(cri_u64 *)(a3 + (ulonglong)b_v1 * 8);
        u_v4 = *(cri_u64 *)(a3 + (ulonglong)*loc_90 * 8);
        s_v16 = (short)((int)(short)((ulonglong)u_v3 >> 0x10) + i_v23 + i_v33 >> 6);
        s_v7 = (short)((int)(short)((ulonglong)u_v3 >> 0x30) + i_v14 + i_v9 >> 6);
        s_v26 = (short)((int)(short)((ulonglong)u_v3 >> 0x20) + i_v24 + i_v28 >> 6);
        s_v21 = (short)((int)(short)u_v3 + i_v31 + i_v29 >> 6);
        if (s_v21 < 1) {
          s_v21 = 0;
        }
        if (s_v16 < 1) {
          s_v16 = 0;
        }
        if (s_v26 < 1) {
          s_v26 = 0;
        }
        if (s_v7 < 1) {
          s_v7 = 0;
        }
        if (0xfe < s_v21) {
          s_v21 = 0xff;
        }
        if (0xfe < s_v16) {
          s_v16 = 0xff;
        }
        if (0xfe < s_v26) {
          s_v26 = 0xff;
        }
        if (0xfe < s_v7) {
          s_v7 = 0xff;
        }
        s_v13 = (short)((short)((ulonglong)u_v4 >> 0x10) + i_v23 + i_v33 >> 6);
        s_v8 = (short)((short)((ulonglong)u_v4 >> 0x30) + i_v14 + i_v9 >> 6);
        s_v19 = (short)((short)((ulonglong)u_v4 >> 0x20) + i_v24 + i_v28 >> 6);
        s_v20 = (short)((short)u_v4 + i_v31 + i_v29 >> 6);
        if (s_v20 < 1) {
          s_v20 = 0;
        }
        if (s_v13 < 1) {
          s_v13 = 0;
        }
        if (s_v19 < 1) {
          s_v19 = 0;
        }
        if (s_v8 < 1) {
          s_v8 = 0;
        }
        if (0xfe < s_v20) {
          s_v20 = 0xff;
        }
        if (0xfe < s_v13) {
          s_v13 = 0xff;
        }
        if (0xfe < s_v19) {
          s_v19 = 0xff;
        }
        if (0xfe < s_v8) {
          s_v8 = 0xff;
        }
        *pu_v30 = (((int)s_v7 << 8 | (int)s_v26) << 8 | (int)s_v16) << 8 | (int)s_v21;
        pu_v30 = loc_a0 + 2;
        *pu_v18 = (((int)s_v8 << 8 | (int)s_v19) << 8 | (int)s_v13) << 8 | (int)s_v20;
        pu_v18 = loc_88 + 2;
        loc_90 = pb_v15 + 2;
      }
      loc_88 = (uint *)((longlong)pu_v18 + u_v11);
      loc_a0 = (uint *)((longlong)pu_v30 + u_v11);
      pb_v12 = loc_98 + u_v22;
      pb_v15 = loc_90 + u_v22;
      i_v9 = loc_7c + 3;
      loc_b0 = loc_b0 + u_v25 + 1;
      loc_a8 = loc_a8 + u_v25 + 1;
      loc_7c = loc_7c + 2;
    } while (i_v9 < CriAt<int>(a2, 0xc));
  }
  if ((CriAt<byte>(a2, 0xc) & 1) != 0) {
    if (u_v17 - 1 != 0) {
      u_v11 = (ulonglong)(u_v17 - 1);
      pu_v18 = loc_a0;
      pb_v15 = pb_v12;
      do {
        u_v3 = *(cri_u64 *)(a3 + 0x1000 + (ulonglong)*loc_a8 * 8);
        u_v4 = *(cri_u64 *)(a3 + (ulonglong)*pb_v15 * 8);
        u_v5 = *(cri_u64 *)(a3 + 0x800 + (ulonglong)*loc_b0 * 8);
        loc_b0 = loc_b0 + 1;
        loc_a8 = loc_a8 + 1;
        i_v9 = (int)(short)u_v3 + (int)(short)u_v5;
        i_v24 = (int)(short)((ulonglong)u_v3 >> 0x10) + (int)(short)((ulonglong)u_v5 >> 0x10);
        s_v26 = (short)((short)((ulonglong)u_v4 >> 0x10) + i_v24 >> 6);
        i_v14 = (int)(short)((ulonglong)u_v3 >> 0x30) + (int)(short)((ulonglong)u_v5 >> 0x30);
        i_v23 = (int)(short)((ulonglong)u_v3 >> 0x20) + (int)(short)((ulonglong)u_v5 >> 0x20);
        s_v7 = (short)((short)((ulonglong)u_v4 >> 0x30) + i_v14 >> 6);
        s_v16 = (short)((short)((ulonglong)u_v4 >> 0x20) + i_v23 >> 6);
        s_v21 = (short)((short)u_v4 + i_v9 >> 6);
        if (s_v21 < 1) {
          s_v21 = 0;
        }
        if (s_v26 < 1) {
          s_v26 = 0;
        }
        if (s_v16 < 1) {
          s_v16 = 0;
        }
        if (s_v7 < 1) {
          s_v7 = 0;
        }
        if (0xfe < s_v21) {
          s_v21 = 0xff;
        }
        if (0xfe < s_v26) {
          s_v26 = 0xff;
        }
        if (0xfe < s_v16) {
          s_v16 = 0xff;
        }
        if (0xfe < s_v7) {
          s_v7 = 0xff;
        }
        pb_v12 = pb_v15 + 2;
        *pu_v18 = (((int)s_v7 << 8 | (int)s_v16) << 8 | (int)s_v26) << 8 | (int)s_v21;
        u_v3 = *(cri_u64 *)(a3 + (ulonglong)pb_v15[1] * 8);
        s_v16 = (short)((short)((ulonglong)u_v3 >> 0x10) + i_v24 >> 6);
        s_v7 = (short)((short)((ulonglong)u_v3 >> 0x30) + i_v14 >> 6);
        s_v26 = (short)((short)((ulonglong)u_v3 >> 0x20) + i_v23 >> 6);
        s_v21 = (short)((short)u_v3 + i_v9 >> 6);
        if (s_v21 < 1) {
          s_v21 = 0;
        }
        if (s_v16 < 1) {
          s_v16 = 0;
        }
        if (s_v26 < 1) {
          s_v26 = 0;
        }
        if (s_v7 < 1) {
          s_v7 = 0;
        }
        if (0xfe < s_v21) {
          s_v21 = 0xff;
        }
        if (0xfe < s_v16) {
          s_v16 = 0xff;
        }
        if (0xfe < s_v26) {
          s_v26 = 0xff;
        }
        if (0xfe < s_v7) {
          s_v7 = 0xff;
        }
        loc_a0 = pu_v18 + 2;
        u_v11 = u_v11 - 1;
        pu_v18[1] = (((int)s_v7 << 8 | (int)s_v26) << 8 | (int)s_v16) << 8 | (int)s_v21;
        pu_v18 = loc_a0;
        pb_v15 = pb_v12;
      } while (u_v11 != 0);
    }
    u_v3 = *(cri_u64 *)(a3 + (ulonglong)*pb_v12 * 8);
    u_v4 = *(cri_u64 *)(a3 + 0x800 + (ulonglong)*loc_b0 * 8);
    u_v5 = *(cri_u64 *)(a3 + 0x1000 + (ulonglong)*loc_a8 * 8);
    i_v9 = (int)(short)u_v5 + (int)(short)u_v4;
    i_v24 = (int)(short)((ulonglong)u_v5 >> 0x10) + (int)(short)((ulonglong)u_v4 >> 0x10);
    s_v26 = (short)((short)((ulonglong)u_v3 >> 0x10) + i_v24 >> 6);
    i_v14 = (int)(short)((ulonglong)u_v5 >> 0x30) + (int)(short)((ulonglong)u_v4 >> 0x30);
    i_v23 = (int)(short)((ulonglong)u_v5 >> 0x20) + (int)(short)((ulonglong)u_v4 >> 0x20);
    s_v7 = (short)((short)((ulonglong)u_v3 >> 0x30) + i_v14 >> 6);
    s_v16 = (short)((short)((ulonglong)u_v3 >> 0x20) + i_v23 >> 6);
    s_v21 = (short)((short)u_v3 + i_v9 >> 6);
    if (s_v21 < 1) {
      s_v21 = 0;
    }
    if (s_v26 < 1) {
      s_v26 = 0;
    }
    if (s_v16 < 1) {
      s_v16 = 0;
    }
    if (s_v7 < 1) {
      s_v7 = 0;
    }
    if (0xfe < s_v21) {
      s_v21 = 0xff;
    }
    if (0xfe < s_v26) {
      s_v26 = 0xff;
    }
    if (0xfe < s_v16) {
      s_v16 = 0xff;
    }
    if (0xfe < s_v7) {
      s_v7 = 0xff;
    }
    *loc_a0 = (((int)s_v7 << 8 | (int)s_v16) << 8 | (int)s_v26) << 8 | (int)s_v21;
    if (u_v10 == 0) {
      u_v3 = *(cri_u64 *)(a3 + (ulonglong)pb_v12[1] * 8);
      s_v16 = (short)((short)((ulonglong)u_v3 >> 0x10) + i_v24 >> 6);
      s_v7 = (short)((short)((ulonglong)u_v3 >> 0x30) + i_v14 >> 6);
      s_v26 = (short)((short)((ulonglong)u_v3 >> 0x20) + i_v23 >> 6);
      s_v21 = (short)((short)u_v3 + i_v9 >> 6);
      if (s_v21 < 1) {
        s_v21 = 0;
      }
      if (s_v16 < 1) {
        s_v16 = 0;
      }
      if (s_v26 < 1) {
        s_v26 = 0;
      }
      if (s_v7 < 1) {
        s_v7 = 0;
      }
      if (0xfe < s_v21) {
        s_v21 = 0xff;
      }
      if (0xfe < s_v16) {
        s_v16 = 0xff;
      }
      if (0xfe < s_v26) {
        s_v26 = 0xff;
      }
      if (0xfe < s_v7) {
        s_v7 = 0xff;
      }
      loc_a0[1] = (((int)s_v7 << 8 | (int)s_v26) << 8 | (int)s_v16) << 8 | (int)s_v21;
    }
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004bef0
int FUN_14004bef0(byte *a1,byte *a2)
{
  if ((*a1 & 0xf) != 0) return 0;
  if ((a1[8] & 0xf) != 0) return 0;
  if ((a1[0x10] & 0xf) != 0) return 0;
  if ((*a2 & 0xf) != 0) return 0;
  if ((a2[0xc] & 3) != 0) return 0;
  if ((CriAt<int>(a2, 0x8) & 0xf) != 0) return 0;
  return abs(CriAt<int>(a2, 0x10)) < ((CriAt<int>(a2, 0x8) + 15) & ~15) * 4;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004bf40
void FUN_14004bf40(cri_u64 a1,longlong a2,cri_u64 a3)
{
  int i_v1;
  int i_v2;
  
  i_v1 = FUN_14004bef0((byte *)a1,(byte *)a2);
  i_v2 = FUN_140062860();
  if ((i_v2 == 0) || (i_v1 == 0)) {
    i_v2 = FUN_140062890();
    if ((i_v2 == 0) || (i_v1 == 0)) {
      FUN_14004b120((cri_u64 *)a1,(longlong *)a2,(longlong)a3,CriAt<int>(a2, 0x10),CriAt<int>(a2, 0x10) * 2);
    }
    else {
      FUN_14004a7c0((longlong *)a1,(longlong *)a2,(longlong)a3,CriAt<int>(a2, 0x10),CriAt<int>(a2, 0x10) * 2);
    }
  }
  else {
    FUN_140049e60((longlong *)a1,(longlong *)a2,(longlong)a3,CriAt<int>(a2, 0x10),CriAt<int>(a2, 0x10) * 2);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004bff0
void FUN_14004bff0(cri_u64 a1,longlong a2,cri_u64 a3)
{
  int i_v1;
  int i_v2;
  
  i_v1 = FUN_14004bef0((byte *)a1,(byte *)a2);
  i_v2 = FUN_140062860();
  if ((i_v2 == 0) || (i_v1 == 0)) {
    i_v2 = FUN_140062890();
    if ((i_v2 == 0) || (i_v1 == 0)) {
      FUN_14004b120((cri_u64 *)a1,(longlong *)a2,(longlong)a3,(CriAt<int>(a2, 0xc) / 2) * CriAt<int>(a2, 0x10)
                    ,CriAt<int>(a2, 0x10));
    }
    else {
      FUN_14004a7c0((longlong *)a1,(longlong *)a2,(longlong)a3,(CriAt<int>(a2, 0xc) / 2) * CriAt<int>(a2, 0x10)
                    ,CriAt<int>(a2, 0x10));
    }
  }
  else {
    FUN_140049e60((longlong *)a1,(longlong *)a2,(longlong)a3,(CriAt<int>(a2, 0xc) / 2) * CriAt<int>(a2, 0x10),
                  CriAt<int>(a2, 0x10));
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004c0c0
void FUN_14004c0c0(longlong a1,longlong a2,cri_u64 *a3)
{
  struct { cri_u64 plane[3]; cri_u32 stride[3]; } dst;
  struct { cri_u64 data; cri_u32 a; cri_u32 b; cri_u32 c; cri_u32 unused[3]; } src;  // 32 bytes in the exe frame

  dst.plane[0] = CriAt<cri_u64>(a1, 0x8);
  dst.plane[1] = CriAt<cri_u64>(a1, 0x20);
  dst.plane[2] = CriAt<cri_u64>(a1, 0x38);
  dst.stride[0] = CriAt<cri_u32>(a1, 0x18);
  dst.stride[1] = CriAt<cri_u32>(a1, 0x30);
  dst.stride[2] = CriAt<cri_u32>(a1, 0x48);
  src.data = CriAt<cri_u64>(a2, 0x8);
  src.a = CriAt<cri_u32>(a2, 0x10);
  src.b = CriAt<cri_u32>(a2, 0x14);
  src.c = CriAt<cri_u32>(a2, 0x18);
  if (*a3 == 0) {
    FUN_14004bf40((cri_u64)(longlong)&dst,(longlong)&src,(cri_u64)(longlong)&DAT_143a488c0);
    return;
  }
  FUN_14004bf40((cri_u64)(longlong)&dst,(longlong)&src,*a3);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004c140
void FUN_14004c140(longlong a1,longlong a2,cri_u64 *a3)
{
  struct { cri_u64 plane[3]; cri_u32 stride[3]; } dst;
  struct { cri_u64 data; cri_u32 a; cri_u32 b; cri_u32 c; cri_u32 unused[3]; } src;  // 32 bytes in the exe frame

  dst.plane[0] = CriAt<cri_u64>(a1, 0x8);
  dst.plane[1] = CriAt<cri_u64>(a1, 0x20);
  dst.plane[2] = CriAt<cri_u64>(a1, 0x38);
  dst.stride[0] = CriAt<cri_u32>(a1, 0x18);
  dst.stride[1] = CriAt<cri_u32>(a1, 0x30);
  dst.stride[2] = CriAt<cri_u32>(a1, 0x48);
  src.data = CriAt<cri_u64>(a2, 0x8);
  src.a = CriAt<cri_u32>(a2, 0x10);
  src.b = CriAt<cri_u32>(a2, 0x14);
  src.c = CriAt<cri_u32>(a2, 0x18);
  if (*a3 == 0) {
    FUN_14004bff0((cri_u64)(longlong)&dst,(longlong)&src,(cri_u64)(longlong)&DAT_143a488c0);
    return;
  }
  FUN_14004bff0((cri_u64)(longlong)&dst,(longlong)&src,*a3);
}

