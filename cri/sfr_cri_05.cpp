// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): CRI MvCore / Sofdec vendor middleware (YUV->RGB
// converters, MPEG-2 video decode kernels and the CRI support layer), written from the executable. The CRI library was
// built with VS2008 SP1, and so is this unit (MS2-TOOLSET: vc9, cmake/ms2-unit-profiles.cmake): keep it C++03 (no auto,
// decltype, variadic templates, brace-init or nullptr). Every function is a behaviour-equivalent transcription.
// MS2-UNIT: sfr_cri_05
// MS2-TOOLSET: vc9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14004da40-0x14004e5a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include <windows.h>
#include "../include/cri/cri_decomp.h"

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

extern "C" const char* _DAT_143bad690;
extern "C" const char* _DAT_143bad6a8;
extern "C" const char* _DAT_143badb28;
extern "C" const char* _DAT_143c494e0;
extern "C" cri_u64 DAT_143a4a5e8;
extern "C" cri_u64 DAT_143babdd0;
extern "C" cri_u64 DAT_143babdd8;
extern "C" cri_u64 DAT_143babde0;
extern "C" cri_u64 DAT_143badb08;
extern "C" int DAT_143badb10;
extern "C" cri_u64 DAT_143badb18;
extern "C" cri_u64 DAT_143badb38;
extern "C" cri_u64 DAT_143badb40;
extern "C" cri_u64 DAT_143badb48;
extern "C" cri_u64 DAT_143badb50;
extern "C" int DAT_143badbdc;
extern "C" cri_u64 DAT_143badc00;
extern "C" cri_u64 DAT_143c490e0;
extern "C" cri_u64 DAT_143c490f0;
extern "C" cri_u64 DAT_143c490f8;
extern "C" cri_u64 DAT_143d749b8;
extern "C" cri_u64 DAT_143d749c0;
extern "C" cri_u64 DAT_143d74a10;
extern "C" cri_u64 DAT_143d74a40;
extern "C" cri_u64 DAT_143d74a50;
extern "C" cri_u64 DAT_143d74a58;
extern "C" cri_u64 DAT_143d74a60;
extern "C" cri_u64 DAT_143ffd4e8;
extern "C" cri_u64 _DAT_143c49118;
extern "C" cri_u64 _DAT_143c49120;
extern "C" cri_u64 _DAT_143c49128;
extern "C" cri_u64 _DAT_143c49178;
extern "C" cri_u64 _DAT_143c491b8;
extern "C" cri_u64 _DAT_143c491c0;
extern "C" cri_u64 _DAT_143c491c8;
extern "C" cri_u64 _DAT_143c491d0;
extern "C" cri_u64 _DAT_143c49208;
extern "C" cri_u64 _DAT_143c49210;
extern "C" cri_u64 _DAT_143c49218;
extern "C" cri_u64 _DAT_143c49220;
extern "C" cri_u64 _DAT_143c49260;
extern "C" cri_u64 _DAT_143c49268;
extern "C" cri_u64 _DAT_143c492c8;
extern "C" cri_u64 _DAT_143c49318;
extern "C" cri_u64 _DAT_143c49360;
extern "C" cri_u64 _DAT_143c49368;
extern "C" cri_u64 _DAT_143c493a8;
extern "C" cri_u64 _DAT_143c493b0;
extern "C" cri_u64 _DAT_143c493b8;
extern "C" cri_u64 _DAT_143c49408;
extern "C" cri_u64 _DAT_143c49448;
extern "C" cri_u64 _DAT_143c49450;
extern "C" cri_u64 _DAT_143c49458;
extern "C" cri_u64 _DAT_143c49460;
extern "C" cri_u64 _DAT_143c49498;
extern "C" cri_u64 _DAT_143c494a0;
extern "C" cri_u64 _DAT_143c494a8;
extern "C" cri_u64 _DAT_143c494b0;
extern "C" unsigned char DAT_143babdf0;
extern "C" double DAT_143bac640;
extern "C" double DAT_143bac658;
extern "C" double DAT_143bac670;
extern "C" unsigned char DAT_143bac690;
extern "C" unsigned char DAT_143bace90;
extern "C" double _DAT_143bac648;
extern "C" double _DAT_143bac650;
extern "C" double _DAT_143bac660;
extern "C" double _DAT_143bac668;
extern "C" double _DAT_143bac678;
extern "C" double _DAT_143bac680;
extern "C" int DAT_1431ba290;
extern "C" int DAT_1431ba2e0;
extern "C" int DAT_1431ba2e8;
extern "C" int DAT_1431ba4f8;
extern "C" unsigned char DAT_1431ba7c8;
extern "C" unsigned char DAT_1431ba800;
extern "C" int DAT_1431ba950;
extern "C" int DAT_1431ba990;
extern "C" int DAT_143a48740;
extern "C" int DAT_143a487e0;
extern "C" int DAT_143a48840;
extern "C" int DAT_143bad6b0;
extern "C" int DAT_143bad830;
extern "C" unsigned char DAT_143badab0;
extern "C" int DAT_143badb24;
extern "C" int DAT_143badb30;
extern "C" unsigned char DAT_143badb60;
extern "C" int DAT_143badb84;
extern "C" int DAT_143badb88;
extern "C" unsigned char DAT_143badbb8;
extern "C" int DAT_143badf80;
extern "C" int DAT_143c490e8;
extern "C" int DAT_143c49100;
extern "C" unsigned char DAT_143c49110;
extern "C" unsigned char DAT_143c49160;
extern "C" unsigned char DAT_143c491b0;
extern "C" unsigned char DAT_143c49250;
extern "C" unsigned char DAT_143c492b0;
extern "C" unsigned char DAT_143c49300;
extern "C" unsigned char DAT_143c49350;
extern "C" unsigned char DAT_143c493a0;
extern "C" unsigned char DAT_143c493f0;
extern "C" unsigned char DAT_143c49440;
extern "C" unsigned char DAT_143d74980;
extern "C" unsigned char DAT_143d749a0;
extern "C" int DAT_143fe82e0;
extern "C" int DAT_143fe83e0;
extern "C" int DAT_143fe8420;
extern "C" unsigned char DAT_143fe84e0;
extern "C" unsigned char DAT_143fe84e8;
extern "C" unsigned char DAT_143fe84f0;
extern "C" unsigned char DAT_143fe8508;
extern "C" unsigned char DAT_143fe8510;
extern "C" unsigned char DAT_143fe8514;
extern "C" unsigned char DAT_143fe8528;
extern "C" unsigned char DAT_143fe8530;
extern "C" unsigned char DAT_143fe8538;
extern "C" unsigned char DAT_143fe8540;
extern "C" unsigned char DAT_143ffbce0;
extern "C" unsigned char DAT_143ffbce8;
extern "C" unsigned char DAT_143ffbcf0;
extern "C" unsigned char DAT_143ffbd00;
extern "C" unsigned char DAT_143ffbd08;
extern "C" unsigned char DAT_143ffbd10;
extern "C" unsigned char DAT_143ffbd18;
extern "C" longlong _DAT_143bad6a0;
extern "C" longlong _DAT_143badb00;
extern "C" int DAT_143c492a0;
extern "C" cri_u8 LAB_142ccc850;

cri_u64 FUN_140027ed8(Any a0,Any a1,Any a2,Any a3);
cri_u64 FUN_140027fb4(Any a0,Any a1);
// cri_movie.h's heap API (C linkage), called with its own types by the /Od criAdec code
extern "C" void* criHeap_AllocFix(void* heap, int size, const char* name, int align);
extern "C" int criHeap_Free(void* heap, void* ptr);
int FUN_140039180(longlong player,int updateTime,cri_u32 *output);
uint FUN_14003b3fc(Any a0,Any a1,Any a2);
longlong FUN_14003b674(Any a0,Any a1,Any a2);
void FUN_1400467a0(Any a0,Any a1,Any a2,Any a3);
void FUN_1400467a8(Any a0,Any a1,Any a2);
void FUN_1400467b0(Any a0,Any a1,Any a2);
cri_u64 FUN_1400467b8(Any a0,Any a1 = 0);
// sfr_cri_03's definitions; the /Od criAdec code calls them with these types
void FUN_1400467a0(void* object, long operation, unsigned long limit, void* output);
void FUN_1400467a8(void* object, long operation, void* chunk);
void FUN_1400467b0(void* object, long operation, void* chunk);
long FUN_1400467b8(void* object, long query);
void FUN_1400467c0(Any a0,Any a1,Any a2,Any a3);
void FUN_14004c370();
void FUN_14004c7c0(Any a0,Any a1);
void FUN_14004da40(void);
cri_u32 FUN_14004dd30(void);
cri_u64 FUN_14004ddb0(cri_u64 a1);
void FUN_14004ddc0(void);
void FUN_14004de20(void);
void FUN_14004de60(longlong a1);
void FUN_14004def0(cri_u32 *a1);
longlong FUN_14004df90(void);
void FUN_14004dfc0(longlong a1);
void FUN_14004e030(int a1,cri_u32 a2);
long FUN_14004e0a0(longlong a1);
void FUN_14004e0c0(longlong a1);
void FUN_14004e100(longlong a1);
void FUN_14004e1c0(int a1,longlong a2);
void FUN_14004e270(longlong a1);
longlong FUN_14004e460(longlong a1);
void FUN_14004e5b0(cri_u64 a1,cri_u64 a2);
void FUN_14004e610(void);
void FUN_14004e650(void);
void FUN_14004e680(cri_u64 *a1);
cri_u64 FUN_14004e6e0(longlong a1);
void FUN_14004e730(longlong a1,cri_u64 a2,cri_u64 a3);
void FUN_14004e770(longlong a1);
cri_u32 FUN_14004e7b0(longlong a1,int a2);
void FUN_14004e820(longlong a1,int a2,int a3,longlong *a4);
void FUN_14004e8c0(longlong a1,int a2,longlong *a3);
void FUN_14004e940(longlong a1,int a2,longlong *a3);
int FUN_14004e9f0(longlong a1,int a2,int a3,int *a4);
cri_u64 FUN_14004eab0(longlong a1);
cri_u32 FUN_14004eb00(longlong a1);
cri_u64 * FUN_14004eb90(cri_u64 a1,cri_u32 a2);
cri_u64 FUN_14004eea0(cri_u64 a1,cri_u32 a2);
void FUN_14004ef20(cri_u64 a1,cri_u64 a2);
void FUN_14004ef80(void);
void FUN_14004efc0(void);
void FUN_14004f000(void *a1);
cri_u64 FUN_14004f060(longlong a1);
void FUN_14004f0b0(longlong a1,cri_u64 a2,cri_u64 a3);
void FUN_14004f0f0(longlong a1,int a2,cri_u64 a3,cri_u64 a4);
void FUN_14004f150(longlong a1);
cri_u32 FUN_14004f1a0(longlong a1,int a2);
void FUN_14004f220(longlong a1,int a2,int a3,longlong *a4);
void FUN_14004f350(longlong a1,int a2,longlong *a3);
void FUN_14004f490(longlong a1,int a2,longlong *a3);
int FUN_14004f620(longlong a1,int a2,int a3,int *a4);
cri_u64 FUN_14004f700(longlong a1);
cri_u32 FUN_14004f750(longlong a1);
cri_u32 FUN_14004f7a0(longlong a1);
void FUN_14004f7f0(longlong a1,int a2,int a3,cri_u32 a4);
cri_u32 FUN_14004f840(longlong a1,int a2,int a3);
cri_u64 * FUN_14004f8f0(cri_u64 a1,cri_u32 a2,cri_u32 a3);
cri_u64 * FUN_14004f9a0(void *a1,uint a2);
void FUN_14004fa50(longlong a1,longlong a2,cri_u32 a3,cri_u32 a4);
void FUN_14004ff00(void);
void FUN_14004ff10(cri_u64 *a1);
void FUN_14004ff30(cri_u64 *a1,int a2);
cri_u32 FUN_14004ff50(longlong a1,cri_u32 a2);
void FUN_140050100(void);
void FUN_1400501d0(void);
void FUN_1400501e0(void);
DWORD FUN_1400501f0(void);
void FUN_140050280(longlong a1);
int * FUN_1400502b0(void);
longlong FUN_140050320(longlong a1,void *a2);
long FUN_140050380(longlong a1,cri_u64 a2,cri_u32 a3);
cri_u32 FUN_1400503e0(longlong a1,void *a2,int *a3);
void FUN_140050480(longlong a1,int a2,cri_u64 a3);
void FUN_140050770(longlong *a1);
void FUN_140050bc0(void);
cri_u32 FUN_140050bd0(longlong a1,cri_u64 a2,void *a3);
void FUN_140050f90(cri_u64 *a1,ulonglong a2);
void FUN_140050fc0(void);
void FUN_1400511a0(longlong a1,int a2,cri_u64 a3,cri_u64 a4, cri_u64 a5);
void FUN_1400511d0(longlong a1,cri_u64 a2,cri_u32 a3);
long FUN_140051210(longlong *a1,cri_u64 *a2);
int FUN_140051270(longlong a1,int *a2);
void FUN_140051300(longlong a1);
void FUN_140051330(longlong a1);
void FUN_140051360(longlong a1);
cri_u64 FUN_140051380(longlong a1,longlong *a2);
cri_u64 FUN_1400515c0(longlong a1,longlong *a2);
cri_u32 FUN_140051c10(longlong a1,longlong a2,int a3);
cri_u32 FUN_140051d90(longlong *a1);
cri_u32 FUN_140051ec0(longlong *a1,uint *a2);
cri_u32 FUN_140052010(longlong *a1,int a2,int a3);
cri_u32 FUN_140052050(longlong *a1,int a2,int a3);
cri_u64 FUN_1400520c0(longlong a1,longlong *a2);
cri_u64 FUN_140052720(longlong a1,longlong *a2);
int FUN_1400527c0(longlong a1,void *a2,int a3);
int FUN_140052950(longlong a1,uint a2,cri_u64 a3);
cri_u32 FUN_140052a10(longlong a1,longlong *a2);
cri_u32 FUN_140052ae0(longlong a1,longlong *a2);
void FUN_140052ef0(cri_u8 *a1);
int FUN_140052fa0(void);
long FUN_140053000(cri_u8 *a1);
longlong FUN_1400530c0(longlong a1,int a2,int a3);
void FUN_140053470(cri_u64 *a1);
void FUN_1400536d0(longlong a1);
void FUN_140053880(longlong a1);
void FUN_140054040(longlong a1,cri_u64 a2,cri_u64 a3);
void FUN_1400628d0();
cri_u64 FUN_140062900(Any a0);
void FUN_140062910(longlong a0);
void FUN_140062920(longlong a0,int a1,cri_u32 a2);
cri_u64 FUN_140062a40(Any a0,Any a1,Any a2);
void FUN_140062ab0(Any a0);
cri_u64 FUN_140062ae0(Any a0,Any a1);
int FUN_140062bc0(Any a0,Any a1,Any a2);
int FUN_1400630c0();
void FUN_140064d90(Any a0,Any a1);
void FUN_140064dd0(Any a0,Any a1,Any a2);
void * FUN_140064eb0(Any a0,Any a1,Any a2);
void FUN_140064f70(Any a0,Any a1,Any a2);
void * FUN_140064eb0(void *dst,const void *src,cri_u64 size);
void FUN_140064f70(void *dst,int value,cri_u64 size);
void FUN_140065000(Any a0);
void FUN_140065030(longlong a0);
cri_u64 FUN_140065450(Any a0,Any a1);
void FUN_140065770();
void FUN_140065790();
void FUN_1400657a0(Any a0);
void FUN_1400657e0(Any a0);
void FUN_140065900(Any a0);
void FUN_1400659a0(Any a0,Any a1);
void FUN_140066180(Any a0);
void FUN_140066320();
void FUN_140066350(Any a0);
void FUN_140066360(longlong a0);
void FUN_140066f60(Any a0);
void FUN_140066f80(Any a0);
void FUN_140067210(Any a0);
void FUN_140067370(Any a0);
void FUN_140067420(Any a0);
void FUN_140067470(Any a0);
char * FUN_1400674d0(Any a0,Any a1,Any a2);
char * FUN_140067590(Any a0,Any a1,Any a2);
char * FUN_1400674d0(char *dst,int size,const char *src);
char * FUN_140067590(char *dst,int size,const char *src);
void FUN_1400674a0(const char *msg);
void FUN_140067700();
void FUN_140067750();
void FUN_140067790();
void FUN_1400677c0();
void FUN_1400677f0();
void FUN_140067840();
cri_u64 FUN_140067890(Any a0,Any a1);
void FUN_140067a90(Any a0);
cri_u32 FUN_140067c90(Any a0,Any a1,Any a2);
void FUN_140067dd0(Any a0,Any a1);
cri_u32 FUN_140067f40(Any a0);
void FUN_140067fc0(Any a0,Any a1);
void FUN_140068070(Any a0,Any a1);
cri_u64 FUN_1400682e0(cri_any = cri_any(), cri_any = cri_any(), ...);    // sfr_cri_07
cri_u64 FUN_140068380(cri_any = cri_any(), ...);    // sfr_cri_07
cri_u32 FUN_1400683d0(Any a0);
cri_u32 FUN_140068430(Any a0);
void FUN_140068990(Any a0);
void FUN_140068cc0(Any a0);
void FUN_140068d50(Any a0);
void FUN_140068db0(Any a0);
void FUN_140068e70(Any a0);
void FUN_140068f30(Any a0);
void FUN_140069020(Any a0,Any a1,Any a2,Any a3);
cri_u64 FUN_140069270(cri_u64 a0,cri_u64 a1,cri_u64 a2);
cri_u64 FUN_140069480(cri_u64 a0,cri_u64 a1,cri_u64 a2,cri_u64 a3);
int FUN_140069844(Any a0,Any a1,Any a2,Any a3,Any a4,Any a5,Any a6,Any a7);
int FUN_140069ac4(Any a0,Any a1,Any a2,Any a3,Any a4,Any a5,Any a6,Any a7);
void FUN_140069e44(Any a0);
void FUN_140069e54(Any a0,Any a1);
void FUN_140069e5c(Any a0,Any a1,Any a2,Any a3);
void FUN_140069e98(Any a0,Any a1,Any a2,Any a3);
void FUN_140069ef4(Any a0,Any a1,Any a2);
uint FUN_14006a7f8(Any a0,Any a1,Any a2);
void FUN_14006aa90();
/* unknown */ void FUN_142ccc860();
/* unknown */ void FUN_142ccca50();
/* unknown */ void FUN_142ccca90();
/* unknown */ void FUN_142cccad0();
/* unknown */ void FUN_142cccb30();
void thunk_FUN_140050520();
void thunk_FUN_140050670();
cri_u32 thunk_FUN_14005b040();
void thunk_FUN_14005b0b0();
void thunk_FUN_140067390(Any a0);
void thunk_FUN_1400afe60(Any a0);

static __forceinline cri_u64 FUN_14004ddb0(Any a0) { return FUN_14004ddb0((cri_u64)a0.v); }
static __forceinline void FUN_14004de60(Any a0) { FUN_14004de60((longlong)a0.v); }
static __forceinline void FUN_14004def0(Any a0) { FUN_14004def0((cri_u32 *)a0.v); }
static __forceinline void FUN_14004dfc0(Any a0) { FUN_14004dfc0((longlong)a0.v); }
static __forceinline void FUN_14004e030(Any a0,Any a1) { FUN_14004e030((int)a0.v,(cri_u32)a1.v); }
static __forceinline long FUN_14004e0a0(Any a0) { return FUN_14004e0a0((longlong)a0.v); }
static __forceinline void FUN_14004e0c0(Any a0) { FUN_14004e0c0((longlong)a0.v); }
static __forceinline void FUN_14004e100(Any a0) { FUN_14004e100((longlong)a0.v); }
static __forceinline void FUN_14004e1c0(Any a0,Any a1) { FUN_14004e1c0((int)a0.v,(longlong)a1.v); }
static __forceinline void FUN_14004e270(Any a0) { FUN_14004e270((longlong)a0.v); }
static __forceinline longlong FUN_14004e460(Any a0) { return FUN_14004e460((longlong)a0.v); }
static __forceinline void FUN_14004e5b0(Any a0,Any a1) { FUN_14004e5b0((cri_u64)a0.v,(cri_u64)a1.v); }
static __forceinline void FUN_14004e680(Any a0) { FUN_14004e680((cri_u64 *)a0.v); }
static __forceinline cri_u64 FUN_14004e6e0(Any a0) { return FUN_14004e6e0((longlong)a0.v); }
static __forceinline void FUN_14004e730(Any a0,Any a1,Any a2) { FUN_14004e730((longlong)a0.v,(cri_u64)a1.v,(cri_u64)a2.v); }
static __forceinline void FUN_14004e770(Any a0) { FUN_14004e770((longlong)a0.v); }
static __forceinline cri_u32 FUN_14004e7b0(Any a0,Any a1) { return FUN_14004e7b0((longlong)a0.v,(int)a1.v); }
static __forceinline void FUN_14004e820(Any a0,Any a1,Any a2,Any a3) { FUN_14004e820((longlong)a0.v,(int)a1.v,(int)a2.v,(longlong *)a3.v); }
static __forceinline void FUN_14004e8c0(Any a0,Any a1,Any a2) { FUN_14004e8c0((longlong)a0.v,(int)a1.v,(longlong *)a2.v); }
static __forceinline void FUN_14004e940(Any a0,Any a1,Any a2) { FUN_14004e940((longlong)a0.v,(int)a1.v,(longlong *)a2.v); }
static __forceinline int FUN_14004e9f0(Any a0,Any a1,Any a2,Any a3) { return FUN_14004e9f0((longlong)a0.v,(int)a1.v,(int)a2.v,(int *)a3.v); }
static __forceinline cri_u64 FUN_14004eab0(Any a0) { return FUN_14004eab0((longlong)a0.v); }
static __forceinline cri_u32 FUN_14004eb00(Any a0) { return FUN_14004eb00((longlong)a0.v); }
static __forceinline cri_u64 * FUN_14004eb90(Any a0,Any a1) { return FUN_14004eb90((cri_u64)a0.v,(cri_u32)a1.v); }
static __forceinline cri_u64 FUN_14004eea0(Any a0,Any a1) { return FUN_14004eea0((cri_u64)a0.v,(cri_u32)a1.v); }
static __forceinline void FUN_14004ef20(Any a0,Any a1) { FUN_14004ef20((cri_u64)a0.v,(cri_u64)a1.v); }
static __forceinline void FUN_14004f000(Any a0) { FUN_14004f000((void *)a0.v); }
static __forceinline cri_u64 FUN_14004f060(Any a0) { return FUN_14004f060((longlong)a0.v); }
static __forceinline void FUN_14004f0b0(Any a0,Any a1,Any a2) { FUN_14004f0b0((longlong)a0.v,(cri_u64)a1.v,(cri_u64)a2.v); }
static __forceinline void FUN_14004f0f0(Any a0,Any a1,Any a2,Any a3) { FUN_14004f0f0((longlong)a0.v,(int)a1.v,(cri_u64)a2.v,(cri_u64)a3.v); }
static __forceinline void FUN_14004f150(Any a0) { FUN_14004f150((longlong)a0.v); }
static __forceinline cri_u32 FUN_14004f1a0(Any a0,Any a1) { return FUN_14004f1a0((longlong)a0.v,(int)a1.v); }
static __forceinline void FUN_14004f220(Any a0,Any a1,Any a2,Any a3) { FUN_14004f220((longlong)a0.v,(int)a1.v,(int)a2.v,(longlong *)a3.v); }
static __forceinline void FUN_14004f350(Any a0,Any a1,Any a2) { FUN_14004f350((longlong)a0.v,(int)a1.v,(longlong *)a2.v); }
static __forceinline void FUN_14004f490(Any a0,Any a1,Any a2) { FUN_14004f490((longlong)a0.v,(int)a1.v,(longlong *)a2.v); }
static __forceinline int FUN_14004f620(Any a0,Any a1,Any a2,Any a3) { return FUN_14004f620((longlong)a0.v,(int)a1.v,(int)a2.v,(int *)a3.v); }
static __forceinline cri_u64 FUN_14004f700(Any a0) { return FUN_14004f700((longlong)a0.v); }
static __forceinline cri_u32 FUN_14004f750(Any a0) { return FUN_14004f750((longlong)a0.v); }
static __forceinline cri_u32 FUN_14004f7a0(Any a0) { return FUN_14004f7a0((longlong)a0.v); }
static __forceinline void FUN_14004f7f0(Any a0,Any a1,Any a2,Any a3) { FUN_14004f7f0((longlong)a0.v,(int)a1.v,(int)a2.v,(cri_u32)a3.v); }
static __forceinline cri_u32 FUN_14004f840(Any a0,Any a1,Any a2) { return FUN_14004f840((longlong)a0.v,(int)a1.v,(int)a2.v); }
static __forceinline cri_u64 * FUN_14004f8f0(Any a0,Any a1,Any a2) { return FUN_14004f8f0((cri_u64)a0.v,(cri_u32)a1.v,(cri_u32)a2.v); }
static __forceinline cri_u64 * FUN_14004f9a0(Any a0,Any a1) { return FUN_14004f9a0((void *)a0.v,(uint)a1.v); }
static __forceinline void FUN_14004fa50(Any a0,Any a1,Any a2,Any a3) { FUN_14004fa50((longlong)a0.v,(longlong)a1.v,(cri_u32)a2.v,(cri_u32)a3.v); }
static __forceinline void FUN_14004ff10(Any a0) { FUN_14004ff10((cri_u64 *)a0.v); }
static __forceinline void FUN_14004ff30(Any a0,Any a1) { FUN_14004ff30((cri_u64 *)a0.v,(int)a1.v); }
static __forceinline cri_u32 FUN_14004ff50(Any a0,Any a1) { return FUN_14004ff50((longlong)a0.v,(cri_u32)a1.v); }
static __forceinline void FUN_140050280(Any a0) { FUN_140050280((longlong)a0.v); }
static __forceinline longlong FUN_140050320(Any a0,Any a1) { return FUN_140050320((longlong)a0.v,(void *)a1.v); }
static __forceinline long FUN_140050380(Any a0,Any a1,Any a2) { return FUN_140050380((longlong)a0.v,(cri_u64)a1.v,(cri_u32)a2.v); }
static __forceinline cri_u32 FUN_1400503e0(Any a0,Any a1,Any a2) { return FUN_1400503e0((longlong)a0.v,(void *)a1.v,(int *)a2.v); }
static __forceinline void FUN_140050480(Any a0,Any a1,Any a2) { FUN_140050480((longlong)a0.v,(int)a1.v,(cri_u64)a2.v); }
static __forceinline cri_u32 FUN_140050bd0(Any a0,Any a1,Any a2) { return FUN_140050bd0((longlong)a0.v,(cri_u64)a1.v,(void *)a2.v); }
static __forceinline void FUN_140050f90(Any a0,Any a1) { FUN_140050f90((cri_u64 *)a0.v,(ulonglong)a1.v); }
static __forceinline void FUN_1400511a0(Any a0,Any a1,Any a2,Any a3,Any a4) { FUN_1400511a0((longlong)a0.v,(int)a1.v,(cri_u64)a2.v,(cri_u64)a3.v,(cri_u64)a4.v); }
static __forceinline void FUN_1400511d0(Any a0,Any a1,Any a2) { FUN_1400511d0((longlong)a0.v,(cri_u64)a1.v,(cri_u32)a2.v); }
static __forceinline long FUN_140051210(Any a0,Any a1) { return FUN_140051210((longlong *)a0.v,(cri_u64 *)a1.v); }
static __forceinline int FUN_140051270(Any a0,Any a1) { return FUN_140051270((longlong)a0.v,(int *)a1.v); }
static __forceinline void FUN_140051300(Any a0) { FUN_140051300((longlong)a0.v); }
static __forceinline void FUN_140051330(Any a0) { FUN_140051330((longlong)a0.v); }
static __forceinline void FUN_140051360(Any a0) { FUN_140051360((longlong)a0.v); }
static __forceinline cri_u64 FUN_140051380(Any a0,Any a1) { return FUN_140051380((longlong)a0.v,(longlong *)a1.v); }
static __forceinline cri_u64 FUN_1400515c0(Any a0,Any a1) { return FUN_1400515c0((longlong)a0.v,(longlong *)a1.v); }
static __forceinline cri_u32 FUN_140051c10(Any a0,Any a1,Any a2) { return FUN_140051c10((longlong)a0.v,(longlong)a1.v,(int)a2.v); }
static __forceinline cri_u32 FUN_140051d90(Any a0) { return FUN_140051d90((longlong *)a0.v); }
static __forceinline cri_u32 FUN_140051ec0(Any a0,Any a1) { return FUN_140051ec0((longlong *)a0.v,(uint *)a1.v); }
static __forceinline cri_u32 FUN_140052010(Any a0,Any a1,Any a2) { return FUN_140052010((longlong *)a0.v,(int)a1.v,(int)a2.v); }
static __forceinline cri_u32 FUN_140052050(Any a0,Any a1,Any a2) { return FUN_140052050((longlong *)a0.v,(int)a1.v,(int)a2.v); }
static __forceinline cri_u64 FUN_1400520c0(Any a0,Any a1) { return FUN_1400520c0((longlong)a0.v,(longlong *)a1.v); }
static __forceinline cri_u64 FUN_140052720(Any a0,Any a1) { return FUN_140052720((longlong)a0.v,(longlong *)a1.v); }
static __forceinline cri_u64 FUN_140052720(Any a0,Any a1,Any a2) { return FUN_140052720((longlong)a0.v,(longlong *)a1.v); }
static __forceinline int FUN_1400527c0(Any a0,Any a1,Any a2) { return FUN_1400527c0((longlong)a0.v,(void *)a1.v,(int)a2.v); }
static __forceinline int FUN_140052950(Any a0,Any a1,Any a2) { return FUN_140052950((longlong)a0.v,(uint)a1.v,(cri_u64)a2.v); }
static __forceinline cri_u32 FUN_140052a10(Any a0,Any a1) { return FUN_140052a10((longlong)a0.v,(longlong *)a1.v); }
static __forceinline cri_u32 FUN_140052a10(Any a0,Any a1,Any a2) { return FUN_140052a10((longlong)a0.v,(longlong *)a1.v); }
static __forceinline cri_u32 FUN_140052ae0(Any a0,Any a1) { return FUN_140052ae0((longlong)a0.v,(longlong *)a1.v); }
static __forceinline void FUN_140052ef0(Any a0) { FUN_140052ef0((cri_u8 *)a0.v); }
static __forceinline long FUN_140053000(Any a0) { return FUN_140053000((cri_u8 *)a0.v); }
static __forceinline longlong FUN_1400530c0(Any a0,Any a1,Any a2) { return FUN_1400530c0((longlong)a0.v,(int)a1.v,(int)a2.v); }
static __forceinline void FUN_140053470(Any a0) { FUN_140053470((cri_u64 *)a0.v); }
static __forceinline void FUN_1400536d0(Any a0) { FUN_1400536d0((longlong)a0.v); }
static __forceinline void FUN_140053880(Any a0) { FUN_140053880((longlong)a0.v); }
static __forceinline void FUN_140054040(Any a0,Any a1,Any a2) { FUN_140054040((longlong)a0.v,(cri_u64)a1.v,(cri_u64)a2.v); }
// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004da40
void FUN_14004da40(void)
{
  longlong l_v1;
  longlong l_v2;
  longlong l_v3;
  cri_u16 *pu_v4;
  longlong l_v5;
  longlong l_v6;
  longlong l_v7;
  cri_u16 *pu_v8;
  cri_u16 *pu_v9;
  double d_v10;
  
  FUN_14004c7c0(&DAT_143a48740,&DAT_143bac640);
  l_v1 = cri_conv(DAT_143babde0);
  l_v5 = DAT_143babdd8 - DAT_143babdd0;
  l_v7 = DAT_143babde0 - DAT_143babdd8;
  l_v6 = DAT_143babde0 - DAT_143babdd0;
  l_v2 = 0;
  pu_v4 = (&CriAt<cri_u16>(DAT_143babdd8, 0x6));
  pu_v8 = (&CriAt<cri_u16>(DAT_143babdd0, 0x2));
  do {
    l_v3 = l_v2 + 8;
    pu_v9 = pu_v8 + 4;
    pu_v8[1] = (short)(int)(DAT_143bac640 * *(double *)((longlong)&DAT_143bac690 + l_v2) + 0.5);
    *pu_v8 = (short)(int)(DAT_143bac658 * *(double *)((longlong)&DAT_143bac690 + l_v2) + 0.5);
    d_v10 = DAT_143bac670 * *(double *)((longlong)&DAT_143bac690 + l_v2);
    pu_v8[2] = 0x3fc0;
    pu_v8[-1] = (short)(int)(d_v10 + 0.5);
    pu_v4[-1] = (short)(int)((*(double *)((longlong)&DAT_143babdf0 + l_v2) - 128.0) *
                              _DAT_143bac648 + 0.5);
    *(short *)(l_v5 + -8 + (longlong)pu_v9) =
         (short)(int)((*(double *)((longlong)&DAT_143babdf0 + l_v2) - 128.0) * _DAT_143bac660 + 0.5
                     );
    d_v10 = (*(double *)((longlong)&DAT_143babdf0 + l_v2) - 128.0) * _DAT_143bac678;
    *pu_v4 = 0;
    pu_v4[-3] = (short)(int)(d_v10 + 0.5);
    *(short *)(l_v2 + 4 + l_v1) =
         (short)(int)((*(double *)((longlong)&DAT_143bace90 + l_v2) - 128.0) * _DAT_143bac650 + 0.5
                     );
    *(short *)(l_v6 + -8 + (longlong)pu_v9) =
         (short)(int)((*(double *)((longlong)&DAT_143bace90 + l_v2) - 128.0) * _DAT_143bac668 + 0.5
                     );
    d_v10 = (*(double *)((longlong)&DAT_143bace90 + l_v2) - 128.0) * _DAT_143bac680;
    *(cri_u16 *)(l_v7 + -8 + (longlong)(pu_v4 + 4)) = 0;
    *(short *)(l_v2 + l_v1) = (short)(int)(d_v10 + 0.5);
    l_v2 = l_v3;
    pu_v4 = pu_v4 + 4;
    pu_v8 = pu_v9;
  } while (l_v3 < 0x800);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004dc30
void FUN_14004dc30(longlong a1)
{
  DAT_143babdd8 = a1 + 0x800;
  DAT_143babde0 = a1 + 0x1000;
  DAT_143babdd0 = a1;
  FUN_14004c370();
  FUN_14004da40();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004dc70
void FUN_14004dc70(void)
{
  _DAT_143bad690 = cri_conv("\nCRI MvCore/PCx64 Ver.1.00 Build:Jan 13 2012 18:30:47\n");
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004dc90
uint FUN_14004dc90(cri_u64 a1,cri_u64 a2)
{
  byte b_v1;
  int i_v2;
  longlong l_v3;
  
  l_v3 = FUN_1400530c0(a1,a2,0x40);
  if (l_v3 != 0) {
    i_v2 = thunk_FUN_14005b040();
    if (i_v2 != 0) {
      return 1;
    }
    i_v2 = (int)a2 + ((int)a1 - (int)(l_v3 + 4));
    if (0 < i_v2) {
      l_v3 = FUN_1400530c0(l_v3 + 4,i_v2,0xffffffff);
      if (l_v3 != 0) {
        b_v1 = FUN_140053000(l_v3);
        return ((int)(char)~b_v1 & 0x10U) >> 4;
      }
    }
  }
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004dd30
cri_u32 FUN_14004dd30(void)
{
  if (FUN_1400630c0() != 0) {
    return FUN_14004ff50(0,0xff03ff03);
  }
  if (FUN_140062bc0(&DAT_1431ba2e0,0x1900,0x80) != 0) {
    return FUN_14004ff50(0,0xff03ff07);
  }
  if (FUN_140052fa0() != 0) {
    return FUN_14004ff50(0,0xff03ff09);
  }
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ddb0
cri_u64 FUN_14004ddb0(cri_u64 a1)
{
  // The exe calls this from another obj, so the call stays even though it does nothing. The barrier emits no code; it
  // only stops VC9 from dropping the same-TU calls.
  _ReadWriteBarrier();
  return a1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ddc0
void FUN_14004ddc0(void)
{
  int i;
  cri_u8 *p;
  memset(&DAT_143bad6b0,0,0x180);
  p = (cri_u8 *)&DAT_143bad830;
  for (i = 0; i < 0x100; i++) {
    *p++ = (cri_u8)i;
  }
  for (i = 0; i < 0x180; i++) {
    *p++ = 0xff;
  }
  DAT_143ffd4e8 = (cri_u64)&DAT_143bad830;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004de20
void FUN_14004de20(void)
{
  cri_u32 *pu_v1;
  ulonglong u_v2;
  
  if (0 < DAT_143badb10) {
    pu_v1 = (&CriAt<cri_u32>(DAT_143badb18, 0x1538));
    u_v2 = (ulonglong)((DAT_143badb10 - 1U >> 2) + 1);
    do {
      *pu_v1 = 1;
      pu_v1 = pu_v1 + 0x1980;
      u_v2 = u_v2 - 1;
    } while (u_v2 != 0);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004de60
void FUN_14004de60(longlong a1)
{
  longlong l_v1;
  CriAt<longlong>(a1, 0x1450) = a1;
  CriAt<cri_u64>(a1, 0x1448) = CriAt<cri_u64>(a1, 0x12f8);
  l_v1 = a1 + 0xc80;
  CriAt<longlong>(a1, 0x1458) = l_v1;
  CriAt<longlong>(a1, 0x1460) = l_v1 + 0x180;
  longlong *t = &CriAt<longlong>(a1, 0x17c8);
  t[4] = a1;
  t[0] = a1 + 0x100;
  t[1] = a1 + 0x180;
  t[2] = a1 + 0x200;
  t[3] = a1 + 0x280;
  t[5] = a1 + 0x80;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004def0
void FUN_14004def0(cri_u32 *a1)
{
  a1[0xe] = 3;
  a1[0xf] = 1;
  a1[0x10] = 1;
  a1[0x11] = 1;
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  a1[4] = 0;
  a1[5] = 0;
  a1[6] = 0;
  a1[7] = 0;
  a1[8] = 0;
  a1[9] = 0;
  a1[10] = 0;
  a1[0xb] = 0;
  a1[0xc] = 0;
  a1[0xd] = 0;
  a1[0x12] = 0;
  a1[0x13] = 0;
  CriAt<short>(a1, 0x50) = -1;
  CriAt<short>(a1, 0x52) = -1;
  CriAt<cri_u8>(a1, 0x54) = 0;
  CriAt<char>(a1, 0x55) = -1;
  CriAt<char>(a1, 0x56) = -1;
  CriAt<char>(a1, 0x57) = -1;
  CriAt<cri_u8>(a1, 0x58) = 0;
  CriAt<cri_u8>(a1, 0x5a) = 0;
  CriAt<cri_u8>(a1, 0x5b) = 0;
  CriAt<cri_u8>(a1, 0x5c) = 0;
  CriAt<char>(a1, 0x5e) = -1;
  CriAt<char>(a1, 0x5f) = -1;
  CriAt<char>(a1, 0x60) = -1;
  CriAt<cri_u8>(a1, 0x61) = 0;
  a1[0x1a] = 0;
  CriAt<cri_u8>(a1, 0x59) = 1;
  CriAt<cri_u8>(a1, 0x5d) = 0xff;
  CriAt<cri_u8>(a1, 0x62) = 0xff;
  CriAt<cri_u8>(a1, 0x63) = 0xff;
  CriAt<cri_u8>(a1, 0x64) = 0xff;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004df90
longlong FUN_14004df90(void)
{
  longlong l_v1;
  int i_v2;
  
  i_v2 = 0;
  l_v1 = cri_conv(DAT_143badb18);
  if (0 < DAT_143badb10) {
    do {
      if (CriAt<int>(l_v1, 0x1538) == 1) {
        return l_v1;
      }
      i_v2 = i_v2 + 4;
      l_v1 = l_v1 + 0x6600;
    } while (i_v2 < DAT_143badb10);
  }
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004dfc0
void FUN_14004dfc0(longlong a1)
{
  CriAt<longlong>(a1, 0x13b8) = a1 + 0xc80;
  CriAt<longlong>(a1, 0x1388) = a1 + 0x300;
  CriAt<longlong>(a1, 0x1390) = a1 + 0x17c8;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e030
void FUN_14004e030(int a1,cri_u32 a2)
{
  longlong l_v1;
  ulonglong u_v2;
  
  l_v1 = cri_conv(DAT_143badb18);
  if (0 < DAT_143badb10) {
    u_v2 = (ulonglong)((DAT_143badb10 - 1U >> 2) + 1);
    do {
      if (CriAt<int>(l_v1, 0x1538) == 2) {
        *(cri_u32 *)(l_v1 + 0x1540 + (longlong)a1 * 4) = a2;
      }
      l_v1 = l_v1 + 0x6600;
      u_v2 = u_v2 - 1;
    } while (u_v2 != 0);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e0a0
long FUN_14004e0a0(longlong a1)
{
  if (a1 == 0) {
    return -1;
  }
  if ((*(int*)((char*)(a1) + 0x1538)) != 2) {
    return -1;
  }
  _DAT_143bad6a0 = a1;
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e0c0
void FUN_14004e0c0(longlong a1)
{
  FUN_14004ddc0();
  if (a1 != 0) {
    FUN_140064dd0(a1,&DAT_143bad6b0,0x100);
    DAT_143ffd4e8 = a1 + 0x180;
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e100
void FUN_14004e100(longlong a1)
{
  longlong l_v1;
  
  l_v1 = cri_conv(DAT_143badb08);
  CriAt<cri_u64>(a1, 0x1298) = cri_conv(DAT_143d74a60);
  CriAt<longlong>(a1, 0x12a0) = DAT_143d74a40 + -0x10;
  CriAt<longlong>(a1, 0x12a8) = DAT_143d74a10 + -0x20;
  CriAt<longlong>(a1, 0x12b0) = DAT_143d74a58 + -0x20;
  CriAt<cri_u64>(a1, 0x12b8) = cri_conv(DAT_143d749b8);
  CriAt<cri_u64>(a1, 0x12c0) = cri_conv(DAT_143d749c0);
  CriAt<cri_u64>(a1, 0x12c8) = cri_conv(DAT_143d74a50);
  CriAt<longlong>(a1, 0x12e8) = l_v1 + 0x12a0;
  CriAt<longlong>(a1, 0x12f0) = l_v1 + 0x12c0;
  CriAt<longlong>(a1, 0x12d8) = l_v1 + 0x1100;
  CriAt<cri_u64>(a1, 0x12f8) = cri_conv(DAT_143ffd4e8);
  FUN_14004de60(a1);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e1c0
void FUN_14004e1c0(int a1,longlong a2)
{
  ulonglong work;
  longlong p;
  work = (a2 + 0x7f) & ~(longlong)0x7f;
  FUN_140064f70((void *)work,0,(cri_u64)(longlong)((a1 + 1) * 0x2000) >> 2);
  p = (longlong)a1 * 0x1980 + work;
  FUN_140064eb0(&DAT_143badab0,&DAT_1431ba290,0x40);
  _DAT_143badb00 = p;
  DAT_143badb10 = a1;
  DAT_143badb08 = p + 0x330;
  DAT_143badb18 = work;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e250
void FUN_14004e250(void)
{
  FUN_140065790();
  thunk_FUN_140050670();
  thunk_FUN_14005b0b0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e270
void FUN_14004e270(longlong a1)
{
  FUN_140065900(a1 + 0x1350);
  FUN_14004dfc0(a1);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e2a0
cri_u32 FUN_14004e2a0(longlong a1)
{
  if (FUN_14004e0a0(a1) != 0) {
    return FUN_14004ff50(0,0xff030201);
  }
  FUN_140062910(a1);
  FUN_140065030(a1);
  FUN_140066360(a1);
  *(cri_u32 *)((char *)(a1) + 0x1538) = 1;
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e2f0
cri_u32 FUN_14004e2f0(longlong a1,int a2,cri_u32 a3)
{
  cri_u32 *table;
  if (a1 == 0) {
    FUN_14004e030(a2,a3);
    table = (cri_u32 *)&DAT_143badab0;
  }
  else {
    if (FUN_14004e0a0(a1) != 0) {
      return FUN_14004ff50(0,0xff030202);
    }
    table = (cri_u32 *)((char *)(a1) + 0x1540);
  }
  table[a2] = a3;
  FUN_140062920(a1,a2,a3);
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e360
cri_u32 FUN_14004e360(longlong a1,int a2,cri_u32 *a3)
{
  cri_u32 *p;
  
  if (a1 == 0) {
    p = (cri_u32 *)&DAT_143badab0;
  }
  else {
    if ((int)FUN_14004e0a0(a1) != 0) {
      return FUN_14004ff50(0,0xff030210);
    }
    p = &CriAt<cri_u32>(a1, 0x1540);
  }
  *a3 = p[a2];
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e3b0
int FUN_14004e3b0(cri_u32 a1,cri_u64 a2)
{
  longlong l_v1;
  int i_v2;
  cri_u64 u_v3;
  
  _DAT_143bad6a8 = cri_conv("\nCRI MPV/PCx64 Ver.2.080 Build:Jan 13 2012 18:29:27\n");
  i_v2 = FUN_14004dd30();
  if (i_v2 != 0) {
    if (i_v2 == -0xfc00fb) {
      i_v2 = -0xfc00fb;
    }
    return i_v2;
  }
  u_v3 = FUN_14004ddb0(a2);
  FUN_14004e1c0(a1,u_v3);
  l_v1 = cri_conv(DAT_143badb08);
  FUN_14004ff00();
  FUN_140050fc0();
  FUN_140050bc0();
  thunk_FUN_140050520();
  FUN_140064d90(l_v1 + 0x1320,l_v1);
  FUN_140067370(l_v1);
  FUN_140065770();
  FUN_140066f60(l_v1);
  FUN_14004e0c0(l_v1 + 0x18d0);
  FUN_14004de20();
  FUN_1400628d0();
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e460
longlong FUN_14004e460(longlong a1)
{
  int i;
  
  FUN_14004e100(a1);
  CriAt<cri_u32>(a1, 0x153c) = 0;
  FUN_140064eb0(a1 + 0x1540,&DAT_143badab0,0x40);
  CriAt<cri_u64>(a1, 0x1588) = 0;
  CriAt<cri_u64>(a1, 0x1590) = 0;
  CriAt<cri_u32>(a1, 0x1580) = 0x7fffffff;
  FUN_14004ff10(a1 + 0x1618);
  thunk_FUN_140067390(a1);
  FUN_14004e270(a1);
  FUN_14004def0(a1 + 0x1598);
  CriAt<cri_u32>(a1, 0x17f8) = 0;
  CriAt<cri_u32>(a1, 0x17fc) = 0;
  CriAt<cri_u32>(a1, 0x17b8) = 0;
  CriAt<cri_u32>(a1, 0x17bc) = 0;
  CriAt<cri_u32>(a1, 0x17c0) = 0;
  CriAt<cri_u32>(a1, 0x17c4) = 0;
  CriAt<cri_u32>(a1, 0x1814) = 0;
  for (i = 0; i < 4; i++) {
    FUN_1400511a0(a1,i,0,0,0);
  }
  FUN_1400511d0(a1,0,0);
  FUN_140066350(a1);
  CriAt<cri_u32>(a1, 0x18f0) = 0;
  FUN_140065000(a1);
  CriAt<cri_u64>(a1, 0x1848) = FUN_140062900(a1);
  CriAt<cri_u32>(a1, 0x1538) = 2;
  return a1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e580
longlong FUN_14004e580(void)
{
  longlong l_v1;
  
  l_v1 = FUN_14004df90();
  if (l_v1 == 0) {
    return 0;
  }
  return FUN_14004e460(l_v1);
}
