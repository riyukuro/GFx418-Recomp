// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): CRI MvCore / Sofdec vendor middleware (YUV->RGB
// converters, MPEG-2 video decode kernels and the CRI support layer), written from the executable. The CRI library was
// built with VS2008 SP1, and so is this unit (MS2-TOOLSET: vc9, cmake/ms2-unit-profiles.cmake): keep it C++03 (no auto,
// decltype, variadic templates, brace-init or nullptr). Every function is a behaviour-equivalent transcription.
// MS2-UNIT: sfr_cri_05b
// MS2-TOOLSET: vc9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14004e5a0-0x140054170 .text$mn
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
// sfr_cri_03's names and types for 0x14003b3fc, 0x14003b674 and 0x1400467c0: the /Od ADX loader functions below
// call these and the typed 0x1400467a0-b8 overloads, so their arguments are passed directly (no Any temporaries).
struct CriUsfStandardHeader;
unsigned long criUsfCmn_ParseUsfHeaderStd(const unsigned char* data, unsigned long size, CriUsfStandardHeader* header);
const unsigned char* criUsfCmn_GetContents(const unsigned char* data, unsigned long size, long* contentSize);
void criSj_SplitChunk(const void* source, unsigned long maximum, void* prefix, void* suffix);
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
cri_u64 FUN_140052720(longlong a1,longlong *a2,cri_u32 a3);
int FUN_1400527c0(longlong a1,void *a2,int a3);
int FUN_140052950(longlong a1,uint a2,cri_u64 a3);
cri_u32 FUN_140052a10(longlong a1,longlong *a2,cri_u32 a3);
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
// Typed views of 0x140062a40 and 0x140065450 (sfr_cri_06 defines them with cri_any): 0x140050bd0 returns their 32-bit
// results unchanged.
cri_u32 FUN_140062a40(longlong a1,cri_u64 a2,void *a3);
cri_u32 FUN_140065450(longlong a1,cri_u64 a2);
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
int FUN_140069844(longlong, int, byte *, uint, int *, uint, longlong *, uint);
int FUN_140069ac4(longlong, int, byte *, uint, int *, uint, longlong *, uint);
void FUN_140069e44(longlong);
void FUN_140069e54(longlong, int);
void FUN_140069e5c(longlong, int, int, int);
void FUN_140069e98(longlong, uint, short, short);
void FUN_140069ef4(longlong, uint, uint);
uint FUN_14006a7f8(cri_u64, uint, longlong);
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
static __forceinline cri_u64 FUN_140052720(Any a0,Any a1,Any a2) { return FUN_140052720((longlong)a0.v,(longlong *)a1.v,(cri_u32)a2.v); }
static __forceinline int FUN_1400527c0(Any a0,Any a1,Any a2) { return FUN_1400527c0((longlong)a0.v,(void *)a1.v,(int)a2.v); }
static __forceinline int FUN_140052950(Any a0,Any a1,Any a2) { return FUN_140052950((longlong)a0.v,(uint)a1.v,(cri_u64)a2.v); }
static __forceinline cri_u32 FUN_140052a10(Any a0,Any a1,Any a2) { return FUN_140052a10((longlong)a0.v,(longlong *)a1.v,(cri_u32)a2.v); }
static __forceinline cri_u32 FUN_140052ae0(Any a0,Any a1) { return FUN_140052ae0((longlong)a0.v,(longlong *)a1.v); }
static __forceinline void FUN_140052ef0(Any a0) { FUN_140052ef0((cri_u8 *)a0.v); }
static __forceinline long FUN_140053000(Any a0) { return FUN_140053000((cri_u8 *)a0.v); }
static __forceinline longlong FUN_1400530c0(Any a0,Any a1,Any a2) { return FUN_1400530c0((longlong)a0.v,(int)a1.v,(int)a2.v); }
static __forceinline void FUN_140053470(Any a0) { FUN_140053470((cri_u64 *)a0.v); }
static __forceinline void FUN_1400536d0(Any a0) { FUN_1400536d0((longlong)a0.v); }
static __forceinline void FUN_140053880(Any a0) { FUN_140053880((longlong)a0.v); }
static __forceinline void FUN_140054040(Any a0,Any a1,Any a2) { FUN_140054040((longlong)a0.v,(cri_u64)a1.v,(cri_u64)a2.v); }
// The SJMEM error callback (FUN_14004eb90 stores it as LAB_14004e5a0; Ghidra made no function here).
// MS2-FUNCTIONAL: written from the exe; the message is a literal, not the exe's .rdata copy at 0x1431ba2f8.
// @0x14004e5a0
void FUN_14004e5a0(void)
{
  thunk_FUN_1400afe60("SJMEM Error");
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e5b0
void FUN_14004e5b0(cri_u64 a1,cri_u64 a2)
{
  char msg[64];
  FUN_1400674d0(msg,0x40,(const char *)a1);
  FUN_140067590(msg,0x40,(const char *)a2);
  FUN_1400674a0(msg);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e610
void FUN_14004e610(void)
{
  if (DAT_143badb24 == 0) {
    memset(&DAT_143ffbce0,0,0x1800);
  }
  DAT_143badb24++;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e650
void FUN_14004e650(void)
{
  DAT_143badb24 = DAT_143badb24 + -1;
  if (DAT_143badb24 == 0) {
    memset(&DAT_143ffbce0,0,0x1800);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e680
void FUN_14004e680(cri_u64 *a1)
{
  if (a1 == (cri_u64 *)0x0) {
    FUN_14004e5b0("E2004090231"," : NULL pointer is passed.");
    return;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004e5b0("E2004090232"," : Specified handle is invalid.");
    return;
  }
  memset(a1, 0, 0x40);
  CriAt<cri_u32>(a1, 0x8) = 0;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e6e0
cri_u64 FUN_14004e6e0(longlong a1)
{
  if (a1 == 0) {
    FUN_14004e5b0("E2004090233"," : NULL pointer is passed.");
    return 0;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004e5b0("E2004090234"," : Specified handle is invalid.");
    return 0;
  }
  return CriAt<cri_u64>(a1, 0x10);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e730
void FUN_14004e730(longlong a1,cri_u64 a2,cri_u64 a3)
{
  if (a1 == 0) {
    FUN_14004e5b0("E2004090235"," : NULL pointer is passed.");
    return;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004e5b0("E2004090236"," : Specified handle is invalid.");
    return;
  }
  CriAt<cri_u64>(a1, 0x30) = a2;
  CriAt<cri_u64>(a1, 0x38) = a3;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e770
void FUN_14004e770(longlong a1)
{
  if (a1 == 0) {
    FUN_14004e5b0("E2004090237"," : NULL pointer is passed.");
    return;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004e5b0("E2004090238"," : Specified handle is invalid.");
    return;
  }
  CriAt<cri_u32>(a1, 0x1c) = 0;
  CriAt<cri_u32>(a1, 0x18) = CriAt<cri_u32>(a1, 0x28);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e7b0
cri_u32 FUN_14004e7b0(longlong a1,int a2)
{
  if (a1 == 0) {
    FUN_14004e5b0("E2004090239"," : NULL pointer is passed.");
    return 0;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004e5b0("E2004090240"," : Specified handle is invalid.");
    return 0;
  }
  if (a2 == 1) {
    return CriAt<cri_u32>(a1, 0x18);
  }
  if ((a2 != 0) && (CriAt<code *>(a1, 0x30) != (code *)0x0)) {
    (*CriAt<code *>(a1, 0x30))(CriAt<cri_u64>(a1, 0x38),0xfffffffd);
  }
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e820
void FUN_14004e820(longlong a1,int a2,int a3,longlong *a4)
{
  if (a1 == 0) {
    FUN_14004e5b0("E2004090241"," : NULL pointer is passed.");
    return;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004e5b0("E2004090242"," : Specified handle is invalid.");
    return;
  }
  if (a2 == 0) {
    CriAt<cri_u32>(a4, 0x8) = 0;
    *a4 = 0;
    return;
  }
  if (a2 == 1) {
    if (CriAt<int>(a1, 0x18) < a3) {
      a3 = CriAt<int>(a1, 0x18);
    }
    CriAt<int>(a4, 0x8) = a3;
    *a4 = (longlong)CriAt<int>(a1, 0x1c) + CriAt<longlong>(a1, 0x20);
    CriAt<int>(a1, 0x1c) = CriAt<int>(a1, 0x1c) + a3;
    CriAt<int>(a1, 0x18) = CriAt<int>(a1, 0x18) - (int)a4[1];
    return;
  }
  CriAt<cri_u32>(a4, 0x8) = 0;
  *a4 = 0;
  if (CriAt<code *>(a1, 0x30) != (code *)0x0) {
    (*CriAt<code *>(a1, 0x30))(CriAt<cri_u64>(a1, 0x38),0xfffffffd);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e8c0
void FUN_14004e8c0(longlong a1,int a2,longlong *a3)
{
  if (a1 == 0) {
    FUN_14004e5b0("E2004090243"," : NULL pointer is passed.");
    return;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004e5b0("E2004090244"," : Specified handle is invalid.");
    return;
  }
  if ((((0 < (int)a3[1]) && (*a3 != 0)) && (a2 != 0)) && (a2 != 1)) {
    CriAt<cri_u32>(a3, 0x8) = 0;
    *a3 = 0;
    if (CriAt<code *>(a1, 0x30) != (code *)0x0) {
      (*CriAt<code *>(a1, 0x30))(CriAt<cri_u64>(a1, 0x38),0xfffffffd);
    }
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e940
void FUN_14004e940(longlong a1,int a2,longlong *a3)
{
  int i_v1;
  int i_v2;
  
  if (a1 == 0) {
    FUN_14004e5b0("E2004090245"," : NULL pointer is passed.");
    return;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004e5b0("E2004090246"," : Specified handle is invalid.");
    return;
  }
  if ((0 < (int)a3[1]) && (*a3 != 0)) {
    if (a2 != 0) {
      i_v2 = 0;
      if (a2 == 1) {
        i_v1 = CriAt<int>(a1, 0x1c) - (int)a3[1];
        if (0 < i_v1) {
          i_v2 = i_v1;
        }
        CriAt<int>(a1, 0x1c) = i_v2;
        i_v1 = CriAt<int>(a1, 0x18) + (int)a3[1];
        if (CriAt<int>(a1, 0x28) < i_v1) {
          i_v1 = CriAt<int>(a1, 0x28);
        }
        CriAt<int>(a1, 0x18) = i_v1;
        if (i_v2 == (int)*a3 - CriAt<int>(a1, 0x20)) {
          return;
        }
      }
      else {
        CriAt<int>(a3, 0x8) = i_v2;
        *a3 = i_v2;
      }
    }
    if (CriAt<code *>(a1, 0x30) != (code *)0x0) {
      (*CriAt<code *>(a1, 0x30))(CriAt<cri_u64>(a1, 0x38),0xfffffffd);
    }
  }
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004e9f0
int FUN_14004e9f0(longlong a1,int a2,int a3,int *a4)
{
  int i_v1;
  
  if (a1 == 0) {
    FUN_14004e5b0("E2004090247"," : NULL pointer is passed.");
    return 0;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004e5b0("E2004090248"," : Specified handle is invalid.");
    return 0;
  }
  if (a2 == 0) {
    i_v1 = 0;
  }
  else if (a2 == 1) {
    i_v1 = (CriAt<int>(a1, 0x18) < a3) ? CriAt<int>(a1, 0x18) : a3;
  }
  else {
    i_v1 = 0;
    if (CriAt<code *>(a1, 0x30) != (code *)0x0) {
      (*CriAt<code *>(a1, 0x30))(CriAt<cri_u64>(a1, 0x38),0xfffffffd);
    }
  }
  *a4 = i_v1;
  return i_v1 == a3;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004eab0
cri_u64 FUN_14004eab0(longlong a1)
{
  if (a1 == 0) {
    FUN_14004e5b0("E2004090249"," : NULL pointer is passed.");
    return 0;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004e5b0("E2004090250"," : Specified handle is invalid.");
    return 0;
  }
  return CriAt<cri_u64>(a1, 0x20);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004eb00
cri_u32 FUN_14004eb00(longlong a1)
{
  if (a1 == 0) {
    FUN_14004e5b0("E2004090251"," : NULL pointer is passed.");
    return 0;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004e5b0("E2004090252"," : Specified handle is invalid.");
    return 0;
  }
  return CriAt<cri_u32>(a1, 0x28);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004eb50
void FUN_14004eb50(void)
{
  FUN_140067700();
  FUN_140067790();
  FUN_14004e610();
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004eb70
void FUN_14004eb70(void)
{
  FUN_140067790();
  FUN_14004e650();
  FUN_1400677c0();
  FUN_140067750();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004eb90
cri_u64 * FUN_14004eb90(cri_u64 a1,cri_u32 a2)
{
  struct Entry { void *Vtbl; int Used; void *Name; cri_u8 Reserved18[8]; cri_u64 Arg; cri_u32 Param; void *Fn; Entry *Self; };
  Entry *pool = (Entry *)&DAT_143ffbce0;
  Entry *e;
  int i;
  int *used;
  i = 0;
  for (used = &pool[0].Used; (longlong)used < (longlong)&pool[0x60].Used; used += 0x10) {
    if (*used == 0) break;
    i++;
  }
  if (i == 0x60) {
    return (cri_u64 *)0x0;
  }
  e = &pool[i];
  e->Vtbl = &DAT_143a487e0;
  e->Arg = a1;
  e->Name = &DAT_1431ba2e8;
  e->Used = 1;
  e->Param = a2;
  e->Self = e;
  e->Fn = (void *)&FUN_14004e5a0;
  FUN_14004e770((longlong)e);
  return (cri_u64 *)e;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ec20
void FUN_14004ec20(cri_u64 a1)
{
  FUN_140067790();
  FUN_14004e680(a1);
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ec40
cri_u64 FUN_14004ec40(cri_u64 a1)
{
  cri_u64 u_v1;
  
  FUN_140067790();
  u_v1 = FUN_14004e6e0(a1);
  FUN_1400677c0();
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ec70
void FUN_14004ec70(cri_u64 a1,cri_u64 a2,cri_u64 a3)
{
  FUN_140067790();
  FUN_14004e730(a1,a2,a3);
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ecb0
void FUN_14004ecb0(cri_u64 a1)
{
  FUN_140067790();
  FUN_14004e770(a1);
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ecd0
cri_u32 FUN_14004ecd0(cri_u64 a1,cri_u32 a2)
{
  cri_u32 u_v1;
  
  FUN_140067790();
  u_v1 = FUN_14004e7b0(a1,a2);
  FUN_1400677c0();
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ed10
void FUN_14004ed10(cri_u64 a1,cri_u32 a2,cri_u32 a3,cri_u64 a4)
{
  FUN_140067790();
  FUN_14004e820((longlong)a1,(int)a2,(int)a3,(longlong *)a4);
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ed60
void FUN_14004ed60(cri_u64 a1,cri_u32 a2,cri_u64 a3)
{
  FUN_140067790();
  FUN_14004e8c0((longlong)a1,(int)a2,(longlong *)a3);
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004eda0
void FUN_14004eda0(cri_u64 a1,cri_u32 a2,cri_u64 a3)
{
  FUN_140067790();
  FUN_14004e940((longlong)a1,(int)a2,(longlong *)a3);
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ede0
cri_u32 FUN_14004ede0(cri_u64 a1,cri_u32 a2,cri_u32 a3,cri_u64 a4)
{
  cri_u32 u_v1;
  
  FUN_140067790();
  u_v1 = FUN_14004e9f0((longlong)a1,(int)a2,(int)a3,(int *)a4);
  FUN_1400677c0();
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ee40
cri_u64 FUN_14004ee40(cri_u64 a1)
{
  cri_u64 u_v1;
  
  FUN_140067790();
  u_v1 = FUN_14004eab0(a1);
  FUN_1400677c0();
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ee70
cri_u32 FUN_14004ee70(cri_u64 a1)
{
  cri_u32 u_v1;
  
  FUN_140067790();
  u_v1 = FUN_14004eb00(a1);
  FUN_1400677c0();
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004eea0
cri_u64 FUN_14004eea0(cri_u64 a1,cri_u32 a2)
{
  cri_u64 u_v1;
  
  FUN_140067790();
  u_v1 = (cri_u64)FUN_14004eb90(a1,a2);
  FUN_1400677c0();
  return u_v1;
}

// The SJRBF error callback (FUN_14004f8f0 stores it as LAB_14004eee0; Ghidra made no function here): the error code
// picks the message.
// MS2-FUNCTIONAL: written from the exe; the messages are literals, not the exe's .rdata copies at 0x1431ba508-0x1431ba548.
// @0x14004eee0
void FUN_14004eee0(cri_u64 a1, int a2)
{
  (void)a1;
  if (a2 == -3) {
    thunk_FUN_1400afe60("SJRBF Parameter Error");
    return;
  }
  if (a2 == -2) {
    thunk_FUN_1400afe60("SJRBF Internal Error");
    return;
  }
  thunk_FUN_1400afe60(a2 == -1 ? "SJRBF Fatal Error" : "SJRBF Error");
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ef20
void FUN_14004ef20(cri_u64 a1,cri_u64 a2)
{
  char msg[64];
  FUN_1400674d0(msg,0x40,(const char *)a1);
  FUN_140067590(msg,0x40,(const char *)a2);
  FUN_1400674a0(msg);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ef80
void FUN_14004ef80(void)
{
  if (DAT_143badb30 == 0) {
    memset(&DAT_143fe84e0,0,0x13800);
  }
  DAT_143badb30++;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004efc0
void FUN_14004efc0(void)
{
  DAT_143badb30 = DAT_143badb30 + -1;
  if (DAT_143badb30 == 0) {
    memset(&DAT_143fe84e0,0,0x13800);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f000
void FUN_14004f000(void *a1)
{
  if (a1 == (void *)0x0) {
    FUN_14004ef20("E2004090201"," : NULL pointer is passed.");
    return;
  }
  if (*(int *)((longlong)a1 + 8) == 0) {
    FUN_14004ef20("E2004090202"," : Specified handle is invalid.");
    return;
  }
  memset(a1,0,0x68);
  *(cri_u32 *)((longlong)a1 + 8) = 0;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f060
cri_u64 FUN_14004f060(longlong a1)
{
  if (a1 == 0) {
    FUN_14004ef20("E2004090203"," : NULL pointer is passed.");
    return 0;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004ef20("E2004090204"," : Specified handle is invalid.");
    return 0;
  }
  return CriAt<cri_u64>(a1, 0x10);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f0b0
void FUN_14004f0b0(longlong a1,cri_u64 a2,cri_u64 a3)
{
  if (a1 == 0) {
    FUN_14004ef20("E2004090205"," : NULL pointer is passed.");
    return;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004ef20("E2004090206"," : Specified handle is invalid.");
    return;
  }
  CriAt<cri_u64>(a1, 0x48) = a2;
  CriAt<cri_u64>(a1, 0x50) = a3;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f0f0
void FUN_14004f0f0(longlong a1,int a2,cri_u64 a3,cri_u64 a4)
{
  typedef void (*Callback)(cri_u64,int);
  struct Handle { cri_u8 Reserved00[8]; int Valid; cri_u8 Reserved0c[0x3c]; Callback ErrFunc; cri_u64 ErrObj; cri_u64 Param0; cri_u64 Param1; };
  Handle *h = (Handle *)a1;
  if (h == 0) {
    FUN_14004ef20((cri_u64)"E2006120701",(cri_u64)" : NULL pointer is passed.");
    return;
  }
  if (h->Valid == 0) {
    FUN_14004ef20((cri_u64)"E2006120702",(cri_u64)" : Specified handle is invalid.");
    return;
  }
  if (a2 != 1) {
    if (h->ErrFunc != 0)
      h->ErrFunc(h->ErrObj,-3);
    return;
  }
  h->Param0 = a3;
  h->Param1 = a4;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f150
void FUN_14004f150(longlong a1)
{
  if (a1 == 0) {
    FUN_14004ef20("E2004090207"," : NULL pointer is passed.");
    return;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004ef20("E2004090208"," : Specified handle is invalid.");
    return;
  }
  CriAt<cri_u32>(a1, 0x18) = 0;
  CriAt<cri_u32>(a1, 0x1c) = CriAt<cri_u32>(a1, 0x30);
  CriAt<cri_u32>(a1, 0x20) = 0;
  CriAt<cri_u32>(a1, 0x24) = 0;
  CriAt<cri_u32>(a1, 0x38) = 0;
  CriAt<cri_u32>(a1, 0x3c) = 0;
  CriAt<cri_u32>(a1, 0x40) = 0;
  CriAt<cri_u32>(a1, 0x44) = 0;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f1a0
cri_u32 FUN_14004f1a0(longlong a1,int a2)
{
  if (a1 == 0) {
    FUN_14004ef20("E2004090209"," : NULL pointer is passed.");
    return 0;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004ef20("E2004090210"," : Specified handle is invalid.");
    return 0;
  }
  if (a2 == 1) {
    return CriAt<cri_u32>(a1, 0x18);
  }
  if (a2 == 0) {
    return CriAt<cri_u32>(a1, 0x1c);
  }
  if (CriAt<code *>(a1, 0x48) != (code *)0x0) {
    (*CriAt<code *>(a1, 0x48))(CriAt<cri_u64>(a1, 0x50),0xfffffffd);
  }
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f220
void FUN_14004f220(longlong a1,int a2,int a3,longlong *a4)
{
  int i_v1;
  
  if (a1 == 0) {
    FUN_14004ef20("E2004090211"," : NULL pointer is passed.");
    return;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004ef20("E2004090212"," : Specified handle is invalid.");
    return;
  }
  i_v1 = CriAt<int>(a1, 0x30);
  if (i_v1 == 0) {
    FUN_14004ef20("E2004090219"," : Illegal buffer size.");
    return;
  }
  if (a2 == 0) {
    i_v1 = i_v1 + (CriAt<int>(a1, 0x34) - CriAt<int>(a1, 0x20));
    if (CriAt<int>(a1, 0x1c) < i_v1) {
      i_v1 = CriAt<int>(a1, 0x1c);
    }
    if (i_v1 < a3) {
      a3 = i_v1;
    }
    CriAt<int>(a4, 0x8) = a3;
    *a4 = (longlong)CriAt<int>(a1, 0x20) + CriAt<longlong>(a1, 0x28);
    CriAt<int>(a1, 0x20) = (CriAt<int>(a1, 0x20) + a3) % CriAt<int>(a1, 0x30);
    CriAt<int>(a1, 0x1c) = CriAt<int>(a1, 0x1c) - (int)a4[1];
    CriAt<int>(a1, 0x38) = CriAt<int>(a1, 0x38) + (int)a4[1];
    return;
  }
  if (a2 == 1) {
    i_v1 = i_v1 + (CriAt<int>(a1, 0x34) - CriAt<int>(a1, 0x24));
    if (CriAt<int>(a1, 0x18) < i_v1) {
      i_v1 = CriAt<int>(a1, 0x18);
    }
    if (i_v1 < a3) {
      a3 = i_v1;
    }
    CriAt<int>(a4, 0x8) = a3;
    *a4 = (longlong)CriAt<int>(a1, 0x24) + CriAt<longlong>(a1, 0x28);
    CriAt<int>(a1, 0x24) = (CriAt<int>(a1, 0x24) + a3) % CriAt<int>(a1, 0x30);
    CriAt<int>(a1, 0x18) = CriAt<int>(a1, 0x18) - (int)a4[1];
    CriAt<int>(a1, 0x40) = CriAt<int>(a1, 0x40) + (int)a4[1];
    return;
  }
  CriAt<cri_u32>(a4, 0x8) = 0;
  *a4 = 0;
  if (CriAt<code *>(a1, 0x48) != (code *)0x0) {
    (*CriAt<code *>(a1, 0x48))(CriAt<cri_u64>(a1, 0x50),0xfffffffd);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f350
void FUN_14004f350(longlong a1,int a2,longlong *a3)
{
  uint u_v1;
  int i_v2;
  uint u_v3;
  
  if (a1 == 0) {
    FUN_14004ef20("E2004090213"," : NULL pointer is passed.");
    return;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004ef20("E2004090214"," : Specified handle is invalid.");
    return;
  }
  if ((0 < (int)a3[1]) && (*a3 != 0)) {
    if (a2 == 1) {
      if (CriAt<code *>(a1, 0x58) != (code *)0x0) {
        (*CriAt<code *>(a1, 0x58))(CriAt<cri_u64>(a1, 0x60),a3);
      }
      i_v2 = (int)*a3 - CriAt<int>(a1, 0x28);
      if (i_v2 < CriAt<int>(a1, 0x34)) {
        u_v3 = CriAt<int>(a1, 0x34) - i_v2;
        if ((int)CriAt<uint>(a3, 0x8) < (int)u_v3) {
          u_v3 = CriAt<uint>(a3, 0x8);
        }
        memcpy((void *)((longlong)(CriAt<int>(a1, 0x30) + i_v2) + CriAt<longlong>(a1, 0x28)
                       ),(void *)*a3,(ulonglong)u_v3);
      }
      u_v3 = CriAt<uint>(a3, 0x8);
      i_v2 = CriAt<int>(a3, 0x8) - CriAt<int>(a1, 0x28) + (int)*a3;
      if (i_v2 > CriAt<int>(a1, 0x30)) {
        u_v1 = i_v2 - CriAt<int>(a1, 0x30);
        if ((int)u_v3 < (int)u_v1) {
          u_v1 = u_v3;
        }
        memcpy(CriAt<void *>(a1, 0x28),
               (void *)((longlong)(int)(i_v2 - u_v1) + (longlong)CriAt<void *>(a1, 0x28)),
               (ulonglong)u_v1);
      }
      CriAt<int>(a1, 0x18) = CriAt<int>(a1, 0x18) + (int)a3[1];
      CriAt<int>(a1, 0x44) = CriAt<int>(a1, 0x44) + (int)a3[1];
      return;
    }
    if (a2 == 0) {
      CriAt<int>(a1, 0x1c) = CriAt<int>(a1, 0x1c) + (int)a3[1];
      CriAt<int>(a1, 0x3c) = CriAt<int>(a1, 0x3c) + (int)a3[1];
      return;
    }
    CriAt<int>(a3, 0x8) = 0;
    *a3 = 0;
    if (CriAt<code *>(a1, 0x48) != (code *)0x0) {
      (*CriAt<code *>(a1, 0x48))(CriAt<cri_u64>(a1, 0x50),0xfffffffd);
    }
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f490
void FUN_14004f490(longlong a1,int a2,longlong *a3)
{
  int i_v1;
  longlong l_v2;
  int i_v3;
  
  if (a1 == 0) {
    FUN_14004ef20("E2004090215"," : NULL pointer is passed.");
    return;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004ef20("E2004090216"," : Specified handle is invalid.");
    return;
  }
  i_v1 = CriAt<int>(a1, 0x30);
  if (i_v1 == 0) {
    FUN_14004ef20("E2004090220"," : Illegal buffer size.");
    return;
  }
  i_v3 = (int)a3[1];
  if ((0 < i_v3) && (l_v2 = *a3, l_v2 != 0)) {
    if (a2 == 0) {
      i_v3 = ((CriAt<int>(a1, 0x20) - i_v3) + i_v1) % i_v1;
      if (i_v3 == (int)((l_v2 - CriAt<longlong>(a1, 0x28)) % (longlong)i_v1)) {
        CriAt<int>(a1, 0x20) = i_v3;
        CriAt<int>(a1, 0x1c) = CriAt<int>(a1, 0x1c) + (int)a3[1];
        CriAt<int>(a1, 0x38) = CriAt<int>(a1, 0x38) - (int)a3[1];
        return;
      }
      if (CriAt<code *>(a1, 0x48) != (code *)0x0) {
        (*CriAt<code *>(a1, 0x48))(CriAt<cri_u64>(a1, 0x50),0xfffffffd);
      }
      CriAt<int>(a1, 0x38) = CriAt<int>(a1, 0x38) - (int)a3[1];
      return;
    }
    if (a2 == 1) {
      i_v3 = ((CriAt<int>(a1, 0x24) - i_v3) + i_v1) % i_v1;
      if (i_v3 == (int)((l_v2 - CriAt<longlong>(a1, 0x28)) % (longlong)i_v1)) {
        CriAt<int>(a1, 0x24) = i_v3;
        CriAt<int>(a1, 0x18) = CriAt<int>(a1, 0x18) + (int)a3[1];
        CriAt<int>(a1, 0x40) = CriAt<int>(a1, 0x40) - (int)a3[1];
        return;
      }
      if (CriAt<code *>(a1, 0x48) != (code *)0x0) {
        (*CriAt<code *>(a1, 0x48))(CriAt<cri_u64>(a1, 0x50),0xfffffffd);
      }
      CriAt<int>(a1, 0x40) = CriAt<int>(a1, 0x40) - (int)a3[1];
      return;
    }
    CriAt<cri_u32>(a3, 0x8) = 0;
    *a3 = 0;
    if (CriAt<code *>(a1, 0x48) != (code *)0x0) {
      (*CriAt<code *>(a1, 0x48))(CriAt<cri_u64>(a1, 0x50),0xfffffffd);
    }
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f620
int FUN_14004f620(longlong a1,int a2,int a3,int *a4)
{
  int i_v1;
  int i_v2;
  
  if (a1 == 0) {
    FUN_14004ef20("E2004090217"," : NULL pointer is passed.");
    return 0;
  }
  if (CriAt<int>(a1, 0x8) != 0) {
    i_v2 = a3;
    if (a2 == 0) {
      i_v1 = (CriAt<int>(a1, 0x34) - CriAt<int>(a1, 0x20)) + CriAt<int>(a1, 0x30);
      if (CriAt<int>(a1, 0x1c) < i_v1) {
        i_v1 = CriAt<int>(a1, 0x1c);
      }
      if (i_v1 < a3) {
        i_v2 = i_v1;
      }
    }
    else if (a2 == 1) {
      i_v1 = (CriAt<int>(a1, 0x34) - CriAt<int>(a1, 0x24)) + CriAt<int>(a1, 0x30);
      if (CriAt<int>(a1, 0x18) < i_v1) {
        i_v1 = CriAt<int>(a1, 0x18);
      }
      if (i_v1 < a3) {
        i_v2 = i_v1;
      }
    }
    else {
      i_v2 = 0;
      if (CriAt<code *>(a1, 0x48) != (code *)0x0) {
        (*CriAt<code *>(a1, 0x48))(CriAt<cri_u64>(a1, 0x50),0xfffffffd);
      }
    }
    *a4 = i_v2;
    return i_v2 == a3;
  }
  FUN_14004ef20("E2004090218"," : Specified handle is invalid.");
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f700
cri_u64 FUN_14004f700(longlong a1)
{
  if (a1 == 0) {
    FUN_14004ef20("E2004090221"," : NULL pointer is passed.");
    return 0;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004ef20("E2004090222"," : Specified handle is invalid.");
    return 0;
  }
  return CriAt<cri_u64>(a1, 0x28);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f750
cri_u32 FUN_14004f750(longlong a1)
{
  if (a1 == 0) {
    FUN_14004ef20("E2004090223"," : NULL pointer is passed.");
    return 0;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004ef20("E2004090224"," : Specified handle is invalid.");
    return 0;
  }
  return CriAt<cri_u32>(a1, 0x30);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f7a0
cri_u32 FUN_14004f7a0(longlong a1)
{
  if (a1 == 0) {
    FUN_14004ef20("E2004090225"," : NULL pointer is passed.");
    return 0;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004ef20("E2004090226"," : Specified handle is invalid.");
    return 0;
  }
  return CriAt<cri_u32>(a1, 0x34);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f7f0
void FUN_14004f7f0(longlong a1,int a2,int a3,cri_u32 a4)
{
  if (a1 == 0) {
    FUN_14004ef20("E2004090227"," : NULL pointer is passed.");
    return;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004ef20("E2004090228"," : Specified handle is invalid.");
    return;
  }
  *(cri_u32 *)(a1 + ((longlong)a3 + 0xe + (longlong)a2 * 2) * 4) = a4;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f840
cri_u32 FUN_14004f840(longlong a1,int a2,int a3)
{
  if (a1 == 0) {
    FUN_14004ef20("E2004090229"," : NULL pointer is passed.");
    return 0;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004ef20("E2004090230"," : Specified handle is invalid.");
    return 0;
  }
  return *(cri_u32 *)(a1 + ((longlong)a3 + 0xe + (longlong)a2 * 2) * 4);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f8a0
void FUN_14004f8a0(void)
{
  _DAT_143badb28 = cri_conv("\nSJ/PCx64 Ver.6.48 Build:Jan 13 2012 18:30:46\n");
  FUN_140067700();
  FUN_140067790();
  FUN_14004ef80();
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f8d0
void FUN_14004f8d0(void)
{
  FUN_140067790();
  FUN_14004efc0();
  FUN_1400677c0();
  FUN_140067750();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f8f0
cri_u64 * FUN_14004f8f0(cri_u64 a1,cri_u32 a2,cri_u32 a3)
{
  longlong l_v1;
  cri_u64 *pu_v2;
  int *pi_v3;
  int i_v4;
  
  i_v4 = 0;
  pi_v3 = cri_conv(&DAT_143fe84e8);
  do {
    if (*pi_v3 == 0) break;
    pi_v3 = pi_v3 + 0x1a;
    i_v4 = i_v4 + 1;
  } while ((longlong)pi_v3 < (longlong)&DAT_143ffbce8);
  if (i_v4 == 0x300) {
    return (cri_u64 *)0x0;
  }
  l_v1 = (longlong)i_v4 * 0x68;
  pu_v2 = (cri_u64 *)(&DAT_143fe84e0 + l_v1);
  *pu_v2 = cri_conv(&DAT_143a48840);
  *(cri_u64 *)(&DAT_143fe8508 + l_v1) = a1;
  *(cri_u8 **)(&DAT_143fe84f0 + l_v1) = cri_conv(&DAT_1431ba4f8);
  (&DAT_143fe84e8)[(longlong)i_v4 * 0x1a] = 1;
  *(cri_u32 *)(&DAT_143fe8510 + l_v1) = a2;
  *(cri_u32 *)(&DAT_143fe8514 + l_v1) = a3;
  *(cri_u8 **)(&DAT_143fe8528 + l_v1) = cri_conv(&FUN_14004eee0);
  *(cri_u64 **)(&DAT_143fe8530 + l_v1) = pu_v2;
  *(cri_u64 *)(&DAT_143fe8538 + l_v1) = 0;
  *(cri_u64 *)(&DAT_143fe8540 + l_v1) = 0;
  FUN_14004f150(pu_v2);
  return pu_v2;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f9a0
cri_u64 * FUN_14004f9a0(void *a1,uint a2)
{
  cri_u64 *pu_v1;
  
  if (a1 == (void *)0x0) {
    FUN_14004ef20("E2005120201"," : NULL pointer is passed.");
    return (cri_u64 *)0x0;
  }
  if ((int)a2 < 0x6c) {
    FUN_14004ef20("E2005120202"," : Work area size is too short.");
    return (cri_u64 *)0x0;
  }
  memset(a1,0,(ulonglong)a2);
  pu_v1 = (cri_u64 *)((longlong)a1 + 3U & 0xfffffffffffffffc);
  *pu_v1 = cri_conv(&DAT_143a48840);
  CriAt<cri_u32>(pu_v1, 0x8) = 1;
  pu_v1[2] = cri_conv(&DAT_1431ba4f8);
  pu_v1[10] = (cri_u64)pu_v1;
  pu_v1[9] = cri_conv(&FUN_14004eee0);
  pu_v1[0xb] = 0;
  pu_v1[0xc] = 0;
  FUN_14004f150(pu_v1);
  return pu_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fa50
void FUN_14004fa50(longlong a1,longlong a2,cri_u32 a3,cri_u32 a4)
{
  if ((a1 != 0) && (a2 != 0)) {
    CriAt<longlong>(a1, 0x28) = a2;
    CriAt<cri_u32>(a1, 0x30) = a3;
    CriAt<cri_u32>(a1, 0x34) = a4;
    FUN_14004f150(a1);
    return;
  }
  FUN_14004ef20("E2005120203"," : NULL pointer is passed.");
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fa80
void FUN_14004fa80(cri_u64 a1)
{
  FUN_140067790();
  FUN_14004f000(a1);
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004faa0
cri_u64 FUN_14004faa0(cri_u64 a1)
{
  cri_u64 u_v1;
  
  FUN_140067790();
  u_v1 = FUN_14004f060(a1);
  FUN_1400677c0();
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fad0
void FUN_14004fad0(cri_u64 a1,cri_u64 a2,cri_u64 a3)
{
  FUN_140067790();
  FUN_14004f0b0(a1,a2,a3);
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fb10
void FUN_14004fb10(cri_u64 a1,cri_u32 a2,cri_u64 a3,cri_u64 a4)
{
  FUN_140067790();
  FUN_14004f0f0(a1,a2,a3,a4);
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fb60
void FUN_14004fb60(cri_u64 a1)
{
  FUN_140067790();
  FUN_14004f150(a1);
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fb80
cri_u32 FUN_14004fb80(cri_u64 a1,cri_u32 a2)
{
  cri_u32 u_v1;
  
  FUN_140067790();
  u_v1 = FUN_14004f1a0(a1,a2);
  FUN_1400677c0();
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fbc0
void FUN_14004fbc0(cri_u64 a1,cri_u32 a2,cri_u32 a3,cri_u64 a4)
{
  FUN_140067790();
  FUN_14004f220((longlong)a1,(int)a2,(int)a3,(longlong *)a4);
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fc10
void FUN_14004fc10(cri_u64 a1,cri_u32 a2,cri_u64 a3)
{
  FUN_140067790();
  FUN_14004f350((longlong)a1,(int)a2,(longlong *)a3);
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fc50
void FUN_14004fc50(cri_u64 a1,cri_u32 a2,cri_u64 a3)
{
  FUN_140067790();
  FUN_14004f490((longlong)a1,(int)a2,(longlong *)a3);
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fc90
cri_u32 FUN_14004fc90(cri_u64 a1,cri_u32 a2,cri_u32 a3,cri_u64 a4)
{
  cri_u32 u_v1;
  
  FUN_140067790();
  u_v1 = FUN_14004f620((longlong)a1,(int)a2,(int)a3,(int *)a4);
  FUN_1400677c0();
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fcf0
cri_u64 FUN_14004fcf0(cri_u64 a1)
{
  cri_u64 u_v1;
  
  FUN_140067790();
  u_v1 = FUN_14004f700(a1);
  FUN_1400677c0();
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fd20
cri_u32 FUN_14004fd20(cri_u64 a1)
{
  cri_u32 u_v1;
  
  FUN_140067790();
  u_v1 = FUN_14004f750(a1);
  FUN_1400677c0();
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fd50
cri_u32 FUN_14004fd50(cri_u64 a1)
{
  cri_u32 u_v1;
  
  FUN_140067790();
  u_v1 = FUN_14004f7a0(a1);
  FUN_1400677c0();
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fd80
void FUN_14004fd80(cri_u64 a1,cri_u32 a2,cri_u32 a3,cri_u32 a4)
{
  FUN_140067790();
  FUN_14004f7f0(a1,a2,a3,a4);
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fdd0
cri_u32 FUN_14004fdd0(cri_u64 a1,cri_u32 a2,cri_u32 a3)
{
  cri_u32 u_v1;
  
  FUN_140067790();
  u_v1 = FUN_14004f840(a1,a2,a3);
  FUN_1400677c0();
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fe20
cri_u64 FUN_14004fe20(cri_u64 a1,cri_u32 a2,cri_u32 a3)
{
  cri_u64 u_v1;
  
  FUN_140067790();
  u_v1 = (cri_u64)FUN_14004f8f0(a1,a2,a3);
  FUN_1400677c0();
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004fe70
cri_u64 FUN_14004fe70(cri_u64 a1,cri_u32 a2)
{
  cri_u64 u_v1;
  
  FUN_140067790();
  u_v1 = (cri_u64)FUN_14004f9a0(a1,a2);
  FUN_1400677c0();
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004feb0
void FUN_14004feb0(cri_u64 a1,cri_u64 a2,cri_u32 a3,cri_u32 a4)
{
  FUN_140067790();
  FUN_14004fa50(a1,a2,a3,a4);
  FUN_1400677c0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ff00
void FUN_14004ff00(void)
{
  // The exe calls this from another obj, so the call stays even though it does nothing. The barrier emits no code; it
  // only stops VC9 from dropping the same-TU calls.
  _ReadWriteBarrier();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ff10
void FUN_14004ff10(cri_u64 *a1)
{
  *a1 = 0;
  a1[1] = 0;
  CriAt<cri_u32>(a1, 0x10) = 0;
  CriAt<cri_u32>(a1, 0x14) = 0;
  CriAt<cri_u32>(a1, 0x18) = 0;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ff30
void FUN_14004ff30(cri_u64 *a1,int a2)
{
  CriAt<int>(a1, 0x10) = a2;
  if ((a2 != 0) && ((code *)*a1 != (code *)0x0)) {
    (*(code *)*a1)(a1[1]);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ff50
cri_u32 FUN_14004ff50(longlong a1,cri_u32 a2)
{
  if (a1 == 0) {
    FUN_14004ff30((cri_u64 *)&DAT_143badb38,(int)a2);
    return a2;
  }
  FUN_14004ff30(&CriAt<cri_u64>(a1, 0x1618),(int)a2);
  return a2;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004ff90
cri_u32 FUN_14004ff90(longlong a1,cri_u64 a2,cri_u64 a3)
{
  cri_u64 *pu_v2;
  
  if (a1 == 0) {
    pu_v2 = cri_conv(&DAT_143badb38);
  }
  else {
    if (FUN_14004e0a0(a1) != 0) {
      return FUN_14004ff50(0,0xff030203);
    }
    pu_v2 = (&CriAt<cri_u64>(a1, 0x1618));
  }
  *pu_v2 = a2;
  pu_v2[1] = a3;
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050000
cri_u32 FUN_140050000(longlong a1,cri_u64 *a2)
{
  struct Q { cri_u64 q[4]; };
  if (a1 == 0) {
    *(Q *)a2 = *(Q *)&DAT_143badb38;
    return 0;
  }
  if (FUN_14004e0a0(a1) != 0) {
    return FUN_14004ff50(0,0xff030204);
  }
  *(Q *)a2 = *(Q *)&CriAt<cri_u64>(a1, 0x1618);
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400500b0
void FUN_1400500b0(uint a1,longlong a2)
{
  struct Entry { cri_u32 A, B, C; };
  Entry *src = (Entry *)a2;
  Entry *dst = (Entry *)&DAT_143badb60;
  uint n = a1;
  if (a1 >= 3) {
    n = 3;
  }
  DAT_143c490e8 = n;
  if ((int)n > 0) {
    uint i;
    for (i = 0; i < n; i++) {
      dst[i] = src[i];
    }
  }
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050100
void FUN_140050100(void)
{
  struct Ch { longlong Handle; cri_u8 Reserved08[0xf8]; };
  struct Cfg { cri_u32 Value[3]; };
  int i;
  longlong h;
  Any v(0);    // the exe loads each setting straight into the argument register
  for (i = 0; i < DAT_143c490e8; i++) {
    h = ((Ch *)DAT_143c490e0)[i].Handle;
    if (h != 0) {
      v.v = ((Cfg *)&DAT_143badb60)[i].Value[0];
      if ((cri_u32)v.v == 0x5a5a5a5a) {
        v.v = ((Cfg *)&DAT_143badbb8)[i].Value[0];
      }
      FUN_140068070(h,v);
      v.v = ((Cfg *)&DAT_143badb60)[i].Value[1];
      if ((cri_u32)v.v == 0x5a5a5a5a) {
        v.v = ((Cfg *)&DAT_143badbb8)[i].Value[1];
      }
      FUN_140067fc0(h,v);
    }
  }
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400501d0
void FUN_1400501d0(void)
{
  FUN_1400683d0(DAT_143c490f8);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400501e0
void FUN_1400501e0(void)
{
  FUN_140068430(DAT_143c490f8);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400501f0
DWORD FUN_1400501f0(void)
{
  _SYSTEM_INFO loc_38;
  
  GetSystemInfo(&loc_38);
  return loc_38.dwNumberOfProcessors;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050210
void FUN_140050210(longlong a1,uint a2)
{
  int i_v1;
  uint u_v2;
  int i_v3;
  uint *pu_v4;
  ulonglong u_v5;
  
  if (CriAt<uint>(a1, 0x10) != a2) {
    CriAt<uint>(a1, 0x10) = a2;
    i_v1 = FUN_1400501f0();
    u_v5 = (ulonglong)DAT_143badbdc;
    i_v3 = 0;
    u_v2 = 0;
    if (0 < (int)DAT_143badbdc) {
      pu_v4 = (&CriAt<uint>(DAT_143c490e0, 0xc));
joined_r0x00014005024e:
      do {
        if (u_v2 < 0x20) {
          if (((a2 >> (u_v2 & 0x1f) & 1) == 0) || (i_v1 + -1 <= i_v3)) {
            u_v2 = u_v2 + 1;
            goto joined_r0x00014005024e;
          }
          i_v3 = i_v3 + 1;
        }
        *pu_v4 = u_v2;
        pu_v4 = pu_v4 + 0x40;
        u_v2 = u_v2 + 1;
        u_v5 = u_v5 - 1;
      } while (u_v5 != 0);
    }
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050280
void FUN_140050280(longlong a1)
{
  CriAt<cri_u32>(a1, 0x14) = 1;
  FUN_1400501d0();
  CriAt<cri_u32>(a1, 0x88) = 0x96;
  FUN_1400501e0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400502b0
int * FUN_1400502b0(void)
{
  struct Obj { int Used; cri_u8 Reserved04[0x4d84]; };
  Obj *obj = (Obj *)DAT_143c490f0;
  int i;
  for (i = 0; i < 0x20; i++, obj++) {
    if (obj->Used == 0) {
      break;
    }
  }
  if (i >= 0x20) {
    return 0;
  }
  memset(obj,0,sizeof(Obj));
  obj->Used = 1;
  return (int *)obj;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050310
void FUN_140050310(cri_u32 *a1)
{
  *a1 = 0;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050320
longlong FUN_140050320(longlong a1,void *a2)
{
  FUN_140067790();
  memcpy((&CriAt<cri_u8>(a1, 0x188)),a2,0x68);
  memcpy((&CriAt<cri_u8>(a1, 0x208)),a2,0x68);
  FUN_1400677c0();
  return a1 + 0x188;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050380
long FUN_140050380(longlong a1,cri_u64 a2,cri_u32 a3)
{
  struct Entry { cri_u32 Value; cri_u8 Reserved04[0x24]; cri_u32 Field28; cri_u32 Field2c; cri_u32 Field30; cri_u32 Field34; cri_u8 Reserved38[0x48]; };
  int count;
  Entry *entry;

  count = (*(int*)((char*)(a1) + 0x10c));
  if (count >= 0x96) {
    return -1;
  }
  entry = (Entry *)((char *)(a1) + 0x288) + count;
  entry->Value = a3;
  entry->Field28 = 0;
  entry->Field2c = 0;
  entry->Field30 = 0;
  entry->Field34 = 0;
  (*(int*)((char*)(a1) + 0x10c)) = count + 1;
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400503e0
cri_u32 FUN_1400503e0(longlong a1,void *a2,int *a3)
{
  struct Entry { int Id; cri_u8 Reserved04[0x7c]; };
  struct Obj { cri_u8 Reserved00[0x88]; int Next; cri_u8 Reserved8c[0x7c]; volatile int Count; volatile int Limit;
               cri_u8 Reserved110[0xf8]; cri_u8 Info[0x68]; cri_u8 Reserved270[0x18]; Entry Entries[1]; };
  Obj *o = (Obj *)a1;
  int i;
  cri_u32 result;

  FUN_1400501d0();
  i = o->Next;
  if (i < o->Count) {
    if (i < o->Limit) {
      *a3 = i;
      memcpy(a2,o->Info,0x68);
      FUN_140052050((longlong *)a2,1,o->Entries[i].Id);
      o->Next = i + 1;
      result = 0;
    }
    else {
      result = 1;
    }
  }
  else {
    result = 1;
  }
  FUN_1400501e0();
  return result;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050480
void FUN_140050480(longlong a1,int a2,cri_u64 a3)
{
  struct Funcs { void *Reserved[3]; void (*Emit)(cri_u64 obj,int from,int to); };
  struct Range { int Start; int End; cri_u8 Reserved08[0x78]; };
  struct Obj { cri_u8 Reserved00[8]; Funcs *Fn; cri_u8 Reserved10[4]; int Busy; cri_u8 Reserved18[0xf0]; volatile int Count;
               cri_u8 Reserved10c[0x1ac]; Range Ranges[1]; };
  Obj *o = (Obj *)a1;
  int last;
  int i;

  if (o->Busy != 0) return;
  last = -1;
  for (i = 0; i < o->Count; i++) {
    if (last + 1 < o->Ranges[i].Start) {
      o->Fn->Emit(a3,last,o->Ranges[i].Start);
    }
    if (last < o->Ranges[i].End) {
      last = o->Ranges[i].End;
    }
  }
  if (last < a2) {
    o->Fn->Emit(a3,last,a2 + 1);
  }
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050520
void FUN_140050520(void)
{
  struct Work { cri_u64 Handle; cri_u64 Reserved08; cri_u8 Area[0xf0]; };
  struct Slot { cri_u32 State; cri_u32 Id; cri_u32 Reserved08; };
  int i;
  longlong h;
  
  DAT_143c49100 = DAT_143c49100 + 1;
  if ((DAT_143c49100 == 1) && (1 < (int)FUN_1400501f0())) {
    DAT_143c490f8 = (cri_u64)FUN_1400682e0(&DAT_143badb88,0x30);
    // the exe rounds both work areas up to 0x80 ((addr + 0x5f) & ~0x7f)
    DAT_143c490f0 = ((cri_u64)&DAT_143badf80 + 0x5f) & ~(cri_u64)0x7f;
    memset((void *)DAT_143c490f0,0,0x9b100);
    DAT_143c490e0 = ((cri_u64)&DAT_143badc00 + 0x5f) & ~(cri_u64)0x7f;
    memset((void *)DAT_143c490e0,0,0x300);
    DAT_143badbdc = 3;
    FUN_1400677f0();
    DAT_143badb84 = DAT_143badbdc;
    for (i = 0; i < DAT_143badbdc; i++) {
      // per-thread work area at entry + 0x10
      h = FUN_140067890(((Work *)DAT_143c490e0)[i].Area,0x7c);
      ((Work *)DAT_143c490e0)[i].Handle = h;
      if (h == 0) {
        FUN_14004ff50(0,0xff030602);
        return;
      }
      ((Slot *)&DAT_143badbb8)[i].State = 0xffffffff;
      ((Slot *)&DAT_143badbb8)[i].Id = FUN_140067f40(h);
    }
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050670
void FUN_140050670(void)
{
  struct Ch { longlong Handle; cri_u8 Reserved08[0xf8]; };
  longlong i;
  Ch *ch;

  DAT_143c49100 = DAT_143c49100 + -1;
  if (DAT_143c49100 == 0) {
    if ((int)FUN_1400501f0() <= 1) {
      return;
    }
    if (DAT_143c490f8 != 0) {
      FUN_140068380(DAT_143c490f8);
      DAT_143c490f8 = 0;
    }
    i = DAT_143badbdc - 1;
    if (i >= 0) {
      ch = (Ch *)DAT_143c490e0;
      do {
        if (ch[i].Handle != 0) {
          FUN_140067a90(ch[i].Handle);
          ch = (Ch *)DAT_143c490e0;
          ch[i].Handle = 0;
        }
        i--;
      } while (i >= 0);
    }
    FUN_140067840();
  }
  if (DAT_143c49100 < 0) {
    DAT_143c49100 = 0;
  }
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050730
longlong FUN_140050730(void)
{
  int i_v1;
  longlong l_v2;
  
  i_v1 = FUN_1400501f0();
  if (1 < i_v1) {
    l_v2 = (longlong)FUN_1400502b0();
    if (l_v2 == 0) {
      FUN_14004ff50(0,0xff030601);
    }
    else {
      CriAt<cri_u32>(l_v2, 0x10) = 0x5a5a5a5a;
      return l_v2;
    }
  }
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050770
void FUN_140050770(longlong *a1)
{
  struct Out { int Base; int Size; int Offset; int Start; int End; int Last; };
  struct Funcs { void (*Read)(longlong obj,void *info,Out *out); };
  struct Entry { int Id; cri_u8 Reserved04[0x24]; int Pos; int Size; int Start; int End; cri_u8 Reserved38[0x48]; };
  struct Obj { cri_u8 Reserved00[8]; Funcs *Fn; cri_u8 Reserved10[4]; int Busy; cri_u8 Reserved18[0x270]; Entry Entries[1]; };
  Obj *o;
  longlong obj;
  int idx;
  Out out;
  cri_u64 info[0xe];

  o = (Obj *)a1[0];
  obj = a1[1];
  while (o->Busy == 0) {
    if (FUN_1400503e0((longlong)o,info,&idx) != 0) {
      break;
    }
    o->Fn->Read(obj,info,&out);
    o->Entries[idx].Pos = out.Base + out.Offset;
    o->Entries[idx].Size = out.Size;
    o->Entries[idx].Start = out.Start;
    o->Entries[idx].End = out.End;
    if (out.Last != 0) {
      break;
    }
  }
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050820
cri_u64 FUN_140050820(longlong a1,cri_u64 a2,ulonglong a3,cri_u64 *a4)
{
  cri_u64 u_v1;
  int i_v2;
  int i_v3;
  cri_u32 u_v4;
  longlong *pl_v5;
  ulonglong u_v6;
  longlong l_v7;
  int *pi_v8;
  ulonglong u_v9;
  longlong *pl_v10;
  uint u_v11;
  ulonglong u_v12;
  longlong l_v13;
  int i_v14;
  ulonglong local_res18;
  longlong local_res20;
  longlong loc_88 [9];
  
  i_v14 = cri_conv(DAT_143badb84);
  u_v12 = 0;
  CriAt<cri_u32>(a4, 0x20) = 0;
  CriAt<cri_u32>(a4, 0x24) = 0;
  CriAt<cri_u32>(a4, 0x1c) = 0;
  if ((CriAt<int>(a1, 0x10) == 0) || (CriAt<int>(a1, 0x10) == 0x5a5a5a5a)) {
    return 0;
  }
  CriAt<cri_u32>(a4, 0x1c) = 1;
  local_res18 = a3;
  FUN_140050100();
  CriAt<cri_u64>(a1, 0x8) = a4[1];
  CriAt<cri_u32>(a1, 0x88) = 0;
  CriAt<cri_u32>(a1, 0x108) = 0x96;
  CriAt<cri_u32>(a1, 0x10c) = 0;
  pl_v5 = (longlong *)FUN_140050320(a1,a2);
  i_v2 = (**(code **)(*pl_v5 + 0x48))(pl_v5,1);
  CriAt<cri_u16>(a4, 0x28) = 0;
  i_v3 = CriAt<int>(a1, 0x14);
  u_v9 = u_v12;
  while( true ) {
    if (i_v3 != 0) {
      return 0;
    }
    u_v6 = FUN_140051ec0(pl_v5,&local_res18);
    if ((u_v6 & 1) == 0) break;
    CriAt<short>(a4, 0x28) = CriAt<short>(a4, 0x28) + 1;
    if ((int)u_v9 != (int)local_res18) {
      u_v9 = local_res18 & 0xffffffff;
      i_v3 = (**(code **)(*pl_v5 + 0x48))(pl_v5,1);
      i_v3 = FUN_140050380(a1,pl_v5,i_v2 - i_v3);
      if (i_v3 != 0) {
        CriAt<int>(a4, 0x20) = CriAt<int>(a4, 0x20) + 1;
        break;
      }
    }
    FUN_140052010(pl_v5,1,4);
    i_v3 = CriAt<int>(a1, 0x14);
  }
  CriAt<cri_u32>(a1, 0x108) = CriAt<cri_u32>(a1, 0x10c);
  if (DAT_143badbdc < i_v14) {
    i_v14 = cri_conv(DAT_143badbdc);
  }
  l_v13 = (longlong)i_v14;
  if (0 < l_v13) {
    i_v14 = 1;
    pl_v10 = loc_88 + 3;
    local_res20 = l_v13;
    l_v7 = cri_conv(DAT_143c490e0);
    u_v9 = u_v12;
    do {
      if (*(uint *)(l_v7 + 0xc + u_v9) < 0x20) {
        l_v7 = CriAt<longlong>(a1, 0x8);
        u_v1 = *a4;
        pl_v10[-1] = a1;
        l_v7 = (*CriAt<code *>(l_v7, 0x8))(u_v1,i_v14);
        *pl_v10 = l_v7;
        u_v4 = FUN_140067c90(*(cri_u64 *)(DAT_143c490e0 + u_v9),FUN_140050770,
                              loc_88 + (longlong)i_v14 * 2);
        l_v7 = cri_conv(DAT_143c490e0);
        *(cri_u32 *)(DAT_143c490e0 + 8 + u_v9) = u_v4;
      }
      else {
        *pl_v10 = 0;
        *(cri_u32 *)(l_v7 + 8 + u_v9) = 0xffffffff;
      }
      i_v14 = i_v14 + 1;
      pl_v10 = pl_v10 + 2;
      u_v9 = u_v9 + 0x100;
      local_res20 = local_res20 + -1;
    } while (local_res20 != 0);
    local_res20 = 0;
  }
  loc_88[1] = *a4;
  loc_88[0] = a1;
  FUN_140050770(loc_88);
  if ((CriAt<int>(a1, 0x14) != 0) && (0 < l_v13)) {
    pl_v10 = loc_88 + 3;
    l_v7 = l_v13;
    do {
      (**(code **)(CriAt<longlong>(a1, 0x8) + 0x10))(*pl_v10);
      pl_v10 = pl_v10 + 2;
      l_v7 = l_v7 + -1;
    } while (l_v7 != 0);
  }
  u_v9 = u_v12;
  if (0 < l_v13) {
    do {
      if (-1 < *(int *)(DAT_143c490e0 + 8 + u_v9)) {
        FUN_140067dd0(*(cri_u64 *)(DAT_143c490e0 + u_v9),*(int *)(DAT_143c490e0 + 8 + u_v9));
      }
      l_v13 = l_v13 + -1;
      u_v9 = u_v9 + 0x100;
    } while (l_v13 != 0);
  }
  i_v14 = (**(code **)(*pl_v5 + 0x48))(pl_v5,1);
  FUN_140052050(a2,1,i_v2 - i_v14);
  FUN_140050480(a1,CriAt<cri_u32>(a4, 0x14),*a4);
  if (0 < CriAt<int>(a1, 0x108)) {
    pi_v8 = (&CriAt<int>(a1, 0x2b4));
    do {
      u_v11 = (int)u_v12 + 1;
      u_v12 = (ulonglong)u_v11;
      CriAt<int>(a4, 0x20) = CriAt<int>(a4, 0x20) + pi_v8[-1];
      CriAt<int>(a4, 0x24) = CriAt<int>(a4, 0x24) + *pi_v8;
      pi_v8 = pi_v8 + 0x20;
    } while ((int)u_v11 < CriAt<int>(a1, 0x108));
  }
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050b30
cri_u32 FUN_140050b30(cri_u64 a1,cri_u64 *a2,int *a3)
{
  cri_u64 base;
  int size;
  longlong l_v3;
  cri_u32 err;
  
  if (FUN_14004e0a0(a1) != 0) {
    return FUN_14004ff50(0,0xff03020a);
  }
  base = *a2;
  size = CriAt<int>(a2, 0x8);
  l_v3 = FUN_1400530c0(base,size,0xcc);
  if (l_v3 == 0) {
    *a3 = size;
    err = 0xff030305;
  }
  else {
    *a3 = (int)l_v3 - (int)base;
    err = 0;
  }
  return FUN_14004ff50(a1,err);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050bc0
void FUN_140050bc0(void)
{
  // The exe calls this from another obj, so the call stays even though it does nothing. The barrier emits no code; it
  // only stops VC9 from dropping the same-TU calls.
  _ReadWriteBarrier();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050bd0
cri_u32 FUN_140050bd0(longlong a1,cri_u64 a2,void *a3)
{
  ushort u_v1;
  ushort u_v2;
  int i_v3;
  ulonglong u_v4;
  ulonglong u_v5;
  int i_v6;
  uint u_v7;
  ulonglong u_v9;
  
  if (FUN_14004e0a0(a1) != 0) {
    return FUN_14004ff50(0,0xff030209);
  }
  u_v9 = *(ulonglong *)((longlong)a3 + 0x50);
  if (((((u_v9 != 0) && (u_v4 = *(ulonglong *)((longlong)a3 + 0x40), u_v4 != 0)) &&
       (u_v5 = *(ulonglong *)((longlong)a3 + 0x48), u_v5 != 0)) &&
      ((((u_v9 & 0x7f) == 0 && ((u_v4 & 0x7f) == 0)) &&
       (((u_v5 & 0x7f) == 0 && ((u_v9 != u_v4 && (u_v9 != u_v5)))))))) &&
     ((u_v4 != u_v5 &&
      (((((u_v1 = *(ushort *)((longlong)a3 + 0x5a), (short)u_v1 > 0 &&
          (u_v2 = *(ushort *)((longlong)a3 + 0x58), (short)u_v2 > 0)) &&
         ((short)u_v1 <= 0x4000)) && (((short)u_v2 <= 0x4000 && ((u_v1 & 0x7f) == 0)))) &&
       ((u_v2 & 0x7f) == 0)))))) {
    if (CriAt<int>(a1, 0x17b8) == 2) {
      return FUN_140062a40(a1,a2,a3);
    }
    i_v6 = CriAt<int>(a1, 0x162c);
    i_v3 = CriAt<int>(a1, 0x1630);
    memcpy((&CriAt<cri_u8>(a1, 0x1638)),a3,0x78);
    FUN_1400657a0(a1);
    FUN_140067420(a1);
    FUN_140067470(a1);
    FUN_140066f80(a1);
    FUN_140067210(a1);
    u_v7 = FUN_140065450(a1,a2);
    FUN_1400657e0(a1);
    memcpy(*(void **)((longlong)a3 + 0x60),(&CriAt<cri_u8>(a1, 0x1598)),0x80);
    if (CriAt<int>(a1, 0x1568) != 0) {
      **(int **)((longlong)a3 + 0x60) = (CriAt<int>(a1, 0x1598) + 7) / 8;
      *(int *)(*(longlong *)((longlong)a3 + 0x60) + 4) = (CriAt<int>(a1, 0x159c) + 7) / 8;
      *(int *)(*(longlong *)((longlong)a3 + 0x60) + 8) = (CriAt<int>(a1, 0x1598) + 0xf) / 16;
      *(int *)(*(longlong *)((longlong)a3 + 0x60) + 0xc) = (CriAt<int>(a1, 0x159c) + 0xf) / 16;
    }
    *(int *)((longlong)a3 + 0x68) = CriAt<int>(a1, 0x162c) - i_v6;
    *(int *)((longlong)a3 + 0x6c) = CriAt<int>(a1, 0x1630) - i_v3;
    *(cri_u16 *)((longlong)a3 + 0x70) = CriAt<cri_u16>(a1, 0x16a8);
    return u_v7;
  }
  return FUN_14004ff50(a1,0xff030306);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050e00
cri_u32 FUN_140050e00(cri_u64 a1,cri_u64 a2)
{
  uint u_v2;
  cri_u32 err;
  
  if (FUN_14004e0a0(a1) != 0) {
    return FUN_14004ff50(0,0xff03020a);
  }
  err = 0xff030305;
  u_v2 = FUN_140051d90(a2);
  while (u_v2 != 0) {
    if ((u_v2 & 0xcc) != 0) {
      err = 0;
      break;
    }
    if (FUN_140052010(a2,1,4) != 4) {
      break;
    }
    u_v2 = FUN_140051d90(a2);
  }
  return FUN_14004ff50(a1,err);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050e90
void FUN_140050e90(longlong a1)
{
  int i_v1;
  
  i_v1 = FUN_14004e0a0(a1);
  if (i_v1 != 0) {
    FUN_14004ff50(0,0xff030211);
    return;
  }
  CriAt<cri_u32>(a1, 0x18f0) = 1;
  if (CriAt<int>(a1, 0x17b8) == 2) {
    FUN_140062ab0(a1);
  }
  if (CriAt<longlong>(a1, 0x18f8) != 0) {
    FUN_140050280(CriAt<longlong>(a1, 0x18f8));
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050ef0
cri_u32 FUN_140050ef0(cri_u64 a1,cri_u64 *a2,int *a3,cri_u64 a4)
{
  cri_u32 u_v1;
  int i_v2;
  longlong *pl_v3;
  
  pl_v3 = (longlong *)FUN_14004eea0(*a2,CriAt<cri_u32>(a2, 0x8));
  if (pl_v3 == (longlong *)0x0) {
    u_v1 = 0xffffffff;
  }
  else {
    u_v1 = FUN_140050bd0(a1,pl_v3,a4);
    i_v2 = (**(code **)(*pl_v3 + 0x48))(pl_v3,1);
    *a3 = CriAt<int>(a2, 0x8) - i_v2;
    (**(code **)(*pl_v3 + 0x18))(pl_v3);
  }
  return u_v1;
}

// The no-op callback FUN_140050f90 fills its slots with (stored as LAB_140050f80; Ghidra made no function here): it
// only counts its calls.
// MS2-FUNCTIONAL: written from the exe (VS2008 build, our toolset differs).
// @0x140050f80
void FUN_140050f80(void)
{
  DAT_143c492a0 = DAT_143c492a0 + 1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050f90
void FUN_140050f90(cri_u64 *a1,ulonglong a2)
{
  longlong l_v1;
  int i_v2;
  
  i_v2 = (int)(a2 >> 3);
  l_v1 = (longlong)i_v2;
  if (0 < i_v2) {
    for (; l_v1 != 0; l_v1 = l_v1 + -1) {
      *a1 = cri_conv(&FUN_140050f80);
      a1 = a1 + 1;
    }
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140050fc0
void FUN_140050fc0(void)
{
  FUN_140050f90(&DAT_143c493a0,0x50);
  FUN_140050f90(&DAT_143c491b0,0xa0);
  FUN_140050f90(&DAT_143c49250,0x50);
  FUN_140050f90(&DAT_143c492b0,0x50);
  FUN_140050f90(&DAT_143c493f0,0x50);
  FUN_140050f90(&DAT_143c49110,0x50);
  FUN_140050f90(&DAT_143c49440,0xa0);
  FUN_140050f90(&DAT_143c49350,0x50);
  FUN_140050f90(&DAT_143c49300,0x50);
  FUN_140050f90(&DAT_143c49160,0x50);
  _DAT_143c493a8 = cri_conv(FUN_142cccb30);
  _DAT_143c493b8 = cri_conv(FUN_142ccc860);
  _DAT_143c491b8 = cri_conv(&LAB_142ccc850);
  _DAT_143c491c0 = cri_conv(&LAB_142ccc850);
  _DAT_143c491c8 = cri_conv(&LAB_142ccc850);
  _DAT_143c491d0 = cri_conv(&LAB_142ccc850);
  _DAT_143c49208 = cri_conv(&LAB_142ccc850);
  _DAT_143c49210 = cri_conv(&LAB_142ccc850);
  _DAT_143c49218 = cri_conv(&LAB_142ccc850);
  _DAT_143c49220 = cri_conv(&LAB_142ccc850);
  _DAT_143c49260 = cri_conv(FUN_142ccca50);
  _DAT_143c49268 = cri_conv(FUN_142ccca50);
  _DAT_143c492c8 = cri_conv(FUN_142ccca90);
  _DAT_143c493b0 = cri_conv(FUN_142cccb30);
  _DAT_143c49408 = cri_conv(FUN_142cccad0);
  _DAT_143c49118 = cri_conv(FUN_140068cc0);
  _DAT_143c49120 = cri_conv(FUN_140068cc0);
  _DAT_143c49128 = cri_conv(FUN_140068d50);
  _DAT_143c49448 = cri_conv(FUN_140068990);
  _DAT_143c49450 = cri_conv(FUN_140068990);
  _DAT_143c49458 = cri_conv(FUN_140068990);
  _DAT_143c49460 = cri_conv(FUN_140068990);
  _DAT_143c49498 = cri_conv(FUN_140068990);
  _DAT_143c494a0 = cri_conv(FUN_140068990);
  _DAT_143c494a8 = cri_conv(FUN_140068990);
  _DAT_143c494b0 = cri_conv(FUN_140068990);
  _DAT_143c49360 = cri_conv(FUN_140068db0);
  _DAT_143c49368 = cri_conv(FUN_140068db0);
  _DAT_143c49318 = cri_conv(FUN_140068e70);
  _DAT_143c49178 = cri_conv(FUN_140068f30);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400511a0
// The exe calls this from another obj (its caller is in sfr_cri_05). Plain noinline (no inline) so the uncalled
// definition is still emitted in this TU.
__declspec(noinline) void FUN_1400511a0(longlong a1,int a2,cri_u64 a3,cri_u64 a4, cri_u64 a5)
{
  struct Entry { cri_u64 Data; cri_u64 Size; cri_u64 Extra; };
  Entry *entries;

  entries = (Entry *)((char *)(a1) + 0x1858);
  entries[a2].Extra = a5;
  entries[a2].Data = a3;
  entries[a2].Size = a4;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400511d0
// The exe calls this from another obj (its caller is in sfr_cri_05). Plain noinline (no inline) so the uncalled
// definition is still emitted in this TU.
__declspec(noinline) void FUN_1400511d0(longlong a1,cri_u64 a2,cri_u32 a3)
{
  CriAt<cri_u64>(a1, 0x18b8) = a2;
  CriAt<cri_u32>(a1, 0x18c0) = a3;
  CriAt<cri_u32>(a1, 0x18c4) = 0;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400511f0
void FUN_1400511f0(longlong a1,cri_u64 *a2,cri_u32 *a3)
{
  if (a2 != (cri_u64 *)0x0) {
    *a2 = CriAt<cri_u64>(a1, 0x18b8);
  }
  if (a3 != (cri_u32 *)0x0) {
    *a3 = CriAt<cri_u32>(a1, 0x18c4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140051210
long FUN_140051210(longlong *a1,cri_u64 *a2)
{
  struct Chunk { cri_u8 *Data; cri_u32 Size; };
  struct Sj;
  struct SjVtbl {
    void *Reserved00[6];
    void (*GetChunk)(Sj *sj, int line, int size, Chunk *ck);
    void (*UngetChunk)(Sj *sj, int line, Chunk *ck);
  };
  struct Sj { SjVtbl *Vtbl; };
  Sj *sj = (Sj *)a1;
  Chunk *ck = (Chunk *)a2;
  sj->Vtbl->GetChunk(sj,1,0x7fffffff,ck);
  sj->Vtbl->UngetChunk(sj,1,ck);
  if ((int)ck->Size < 4) {
    return 0;
  }
  return FUN_140053000(ck->Data);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140051270
int FUN_140051270(longlong a1,int *a2)
{
  int i_v1;
  uint u_v2;
  longlong l_v3;
  
  i_v1 = CriAt<int>(a1, 0x17b8);
  if (i_v1 == 0) {
    l_v3 = FUN_1400530c0(*(cri_u64 *)a2,a2[2],0x40);
    if (l_v3 != 0) {
      l_v3 = FUN_1400530c0(l_v3 + 4,(*a2 - (int)(l_v3 + 4)) + a2[2],0xffffffff);
      if (l_v3 != 0) {
        u_v2 = FUN_140053000(l_v3);
        if ((u_v2 & 0x10) != 0) {
          CriAt<cri_u32>(a1, 0x17b8) = 2;
          return CriAt<int>(a1, 0x17b8);
        }
        if (u_v2 != 0) {
          CriAt<cri_u32>(a1, 0x17b8) = 1;
        }
      }
    }
    i_v1 = CriAt<int>(a1, 0x17b8);
  }
  return i_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140051300
void FUN_140051300(longlong a1)
{
  int i_v1;
  
  i_v1 = CriAt<int>(a1, 0x156c);
  if (i_v1 == 0) {
    i_v1 = 1;
  }
  CriAt<cri_u64>(a1, 0x12d0) = *(cri_u64 *)(&DAT_143d74980 + (longlong)i_v1 * 8);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140051330
void FUN_140051330(longlong a1)
{
  int i_v1;
  
  i_v1 = CriAt<int>(a1, 0x156c);
  if (i_v1 == 0) {
    i_v1 = 1;
  }
  FUN_140064dd0(a1 + 0xc00,*(cri_u64 *)(&DAT_143d749a0 + (longlong)i_v1 * 8),0x10);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140051360
void FUN_140051360(longlong a1)
{
  FUN_140064f70(a1 + 0xc40,0x10101010,0x10);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140051380
cri_u64 FUN_140051380(longlong a1,longlong *a2)
{
  uint u_v1;
  uint u_v2;
  int i_v3;
  uint u_v4;
  int i_v5;
  ulonglong u_v6;
  cri_u8 *pu_v7;
  cri_u8 loc_18 [16];
  
  CriAt<cri_u32>(a1, 0x1850) = 2;
  CriAt<int>(a1, 0x15c8) = CriAt<int>(a1, 0x15c8) + 1;
  CriAt<cri_u32>(a1, 0x18e4) = 0;
  CriAt<cri_u32>(a1, 0x18e8) = 0;
  CriAt<cri_u32>(a1, 0x1600) = 0;
  (**(code **)(*a2 + 0x30))(a2,1,0x7fffffff,a1 + 0x1800);
  u_v6 = CriAt<ulonglong>(a1, 0x1800) & 0xfffffffffffffffc;
  i_v3 = CriAt<int>(a1, 0x1800) * 8 + (int)u_v6 * -8;
  u_v1 = CONCAT31(CONCAT21(CONCAT11(CriAt<cri_u8>(u_v6, 0x4),CriAt<cri_u8>(u_v6, 0x5)),
                            CriAt<cri_u8>(u_v6, 0x6)),CriAt<cri_u8>(u_v6, 0x7));
  if (i_v3 != 0) {
    u_v1 = u_v1 << ((byte)i_v3 & 0x1f);
  }
  pu_v7 = (&CriAt<cri_u8>(u_v6, 0xc));
  u_v4 = CONCAT31(CONCAT21(CONCAT11(CriAt<cri_u8>(u_v6, 0x8),CriAt<cri_u8>(u_v6, 0x9)),
                            CriAt<cri_u8>(u_v6, 0xa)),CriAt<cri_u8>(u_v6, 0xb));
  if (i_v3 < 7) {
    i_v3 = i_v3 + 0x19;
    u_v2 = u_v1 << 0x19;
  }
  else {
    i_v3 = i_v3 + -7;
    u_v2 = u_v4;
    if (i_v3 != 0) {
      u_v1 = u_v4 >> (0x19 - (byte)i_v3 & 0x1f) | u_v1;
      u_v2 = u_v4 << ((byte)i_v3 & 0x1f);
    }
    u_v4 = CONCAT31(CONCAT21(CONCAT11(*pu_v7,CriAt<cri_u8>(u_v6, 0xd)),
                              CriAt<cri_u8>(u_v6, 0xe)),CriAt<cri_u8>(u_v6, 0xf));
    pu_v7 = (&CriAt<cri_u8>(u_v6, 0x10));
  }
  i_v5 = (int)pu_v7;
  CriAt<uint>(a1, 0x15c4) = u_v1 >> 7 & 0x3f;
  CriAt<uint>(a1, 0x15c0) = u_v1 >> 0xd & 0x3f;
  CriAt<uint>(a1, 0x15bc) = u_v1 >> 0x14 & 0x3f;
  CriAt<uint>(a1, 0x15b4) = u_v1 >> 0x1f;
  CriAt<uint>(a1, 0x15b8) = u_v1 >> 0x1a & 0x1f;
  CriAt<uint>(a1, 0x16e0) = (uint)((int)u_v2 < 0);
  if (i_v3 == 0x1f) {
    i_v3 = 0;
    i_v5 = i_v5 + 4;
  }
  else {
    i_v3 = i_v3 + 1;
    u_v4 = u_v2 * 2;
  }
  CriAt<uint>(a1, 0x16e4) = (uint)((int)u_v4 < 0);
  if (i_v3 == 0x1f) {
    i_v3 = 0;
    i_v5 = i_v5 + 4;
  }
  else {
    i_v3 = i_v3 + 1;
  }
  FUN_140069020(a1 + 0x1800,((i_v3 + 7 >> 3) - CriAt<int>(a1, 0x1800)) + -8 + i_v5,
                a1 + 0x1800,loc_18);
  (**(code **)(*a2 + 0x40))(a2,0,a1 + 0x1800);
  (**(code **)(*a2 + 0x38))(a2,1,loc_18);
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400515c0
cri_u64 FUN_1400515c0(longlong a1,longlong *a2)
{
  cri_u8 *pu_v1;
  cri_u8 *pu_v2;
  cri_u8 *pu_v3;
  ulonglong *pu_v4;
  longlong l_v5;
  cri_u8 u_v6;
  cri_u64 u_v7;
  longlong l_v8;
  uint u_v9;
  int i_v10;
  int i_v11;
  int i_v12;
  longlong l_v13;
  uint u_v14;
  uint u_v15;
  uint u_v16;
  int i_v17;
  ulonglong u_v18;
  cri_u8 *pu_v19;
  cri_u8 loc_28 [16];
  
  pu_v4 = (&CriAt<ulonglong>(a1, 0x1800));
  CriAt<cri_u32>(a1, 0x1850) = 3;
  (**(code **)(*a2 + 0x30))(a2,1,0x7fffffff,pu_v4);
  u_v18 = *pu_v4 & 0xfffffffffffffffc;
  i_v17 = *(int *)pu_v4 * 8 + (int)u_v18 * -8;
  u_v16 = CONCAT31(CONCAT21(CONCAT11(CriAt<cri_u8>(u_v18, 0x4),CriAt<cri_u8>(u_v18, 0x5)),
                             CriAt<cri_u8>(u_v18, 0x6)),CriAt<cri_u8>(u_v18, 0x7));
  if (i_v17 != 0) {
    u_v16 = u_v16 << ((byte)i_v17 & 0x1f);
  }
  pu_v19 = (&CriAt<cri_u8>(u_v18, 0xc));
  u_v14 = CONCAT31(CONCAT21(CONCAT11(CriAt<cri_u8>(u_v18, 0x8),CriAt<cri_u8>(u_v18, 0x9)),
                             CriAt<cri_u8>(u_v18, 0xa)),CriAt<cri_u8>(u_v18, 0xb));
  if (i_v17 < 0x16) {
    i_v17 = i_v17 + 10;
    u_v9 = u_v16 << 10;
    CriAt<uint>(a1, 0x15ac) = u_v16 >> 0x16;
  }
  else {
    i_v17 = i_v17 + -0x16;
    if (i_v17 == 0) {
      CriAt<uint>(a1, 0x15ac) = u_v16 >> 0x16;
      u_v9 = u_v14;
    }
    else {
      CriAt<uint>(a1, 0x15ac) = (u_v14 >> (10 - (byte)i_v17 & 0x1f) | u_v16) >> 0x16;
      u_v9 = u_v14 << ((byte)i_v17 & 0x1f);
    }
    u_v14 = CONCAT31(CONCAT21(CONCAT11(*pu_v19,CriAt<cri_u8>(u_v18, 0xd)),
                               CriAt<cri_u8>(u_v18, 0xe)),CriAt<cri_u8>(u_v18, 0xf));
    pu_v19 = (&CriAt<cri_u8>(u_v18, 0x10));
  }
  if (i_v17 < 0x1d) {
    i_v17 = i_v17 + 3;
    u_v16 = u_v9 << 3;
  }
  else {
    i_v17 = i_v17 + -0x1d;
    u_v16 = u_v14;
    if (i_v17 != 0) {
      u_v9 = u_v14 >> (3 - (byte)i_v17 & 0x1f) | u_v9;
      u_v16 = u_v14 << ((byte)i_v17 & 0x1f);
    }
    u_v14 = CONCAT31(CONCAT21(CONCAT11(*pu_v19,pu_v19[1]),pu_v19[2]),pu_v19[3]);
    pu_v19 = pu_v19 + 4;
  }
  CriAt<uint>(a1, 0x15b0) = u_v9 >> 0x1d;
  if (i_v17 < 0x10) {
    i_v17 = i_v17 + 0x10;
    u_v9 = u_v16 << 0x10;
    CriAt<uint>(a1, 0x16e8) = u_v16 >> 0x10;
  }
  else {
    i_v17 = i_v17 + -0x10;
    if (i_v17 == 0) {
      CriAt<uint>(a1, 0x16e8) = u_v16 >> 0x10;
      u_v9 = u_v14;
    }
    else {
      CriAt<uint>(a1, 0x16e8) = (u_v14 >> (0x10 - (byte)i_v17 & 0x1f) | u_v16) >> 0x10;
      u_v9 = u_v14 << ((byte)i_v17 & 0x1f);
    }
    u_v14 = CONCAT31(CONCAT21(CONCAT11(*pu_v19,pu_v19[1]),pu_v19[2]),pu_v19[3]);
    pu_v19 = pu_v19 + 4;
  }
  i_v11 = CriAt<int>(a1, 0x15b0);
  l_v13 = (longlong)i_v11;
  i_v12 = 0;
  if ((i_v11 == 1) || (i_v11 == 2)) {
    CriAt<int>(a1, 0x18e4) = CriAt<int>(a1, 0x18e4) + 1;
    CriAt<cri_u32>(a1, 0x18e8) = 0;
    u_v16 = CriAt<int>(a1, 0x18e4) << 0x10;
  }
  else {
    CriAt<int>(a1, 0x18e8) = CriAt<int>(a1, 0x18e8) + 1;
    u_v16 = CriAt<int>(a1, 0x18e4) * 0x10000 - 0x10000U | CriAt<uint>(a1, 0x18e8);
  }
  CriAt<uint>(a1, 0x1600) = u_v16;
  if ((i_v11 != 2) && (i_v11 != 3)) goto LAB_14005194d;
  CriAt<uint>(a1, 0x174c) = (uint)((int)u_v9 < 0);
  if (i_v17 == 0x1f) {
    pu_v1 = pu_v19 + 1;
    u_v6 = *pu_v19;
    pu_v2 = pu_v19 + 2;
    pu_v3 = pu_v19 + 3;
    pu_v19 = pu_v19 + 4;
    u_v15 = CONCAT31(CONCAT21(CONCAT11(u_v6,*pu_v1),*pu_v2),*pu_v3);
    i_v10 = i_v12;
    u_v16 = u_v14;
LAB_14005189f:
    i_v17 = i_v10 + 3;
    u_v9 = u_v16 << 3;
    u_v14 = u_v15;
  }
  else {
    i_v10 = i_v17 + 1;
    u_v16 = u_v9 * 2;
    u_v15 = u_v14;
    if (i_v10 < 0x1d) goto LAB_14005189f;
    i_v17 = i_v17 + -0x1c;
    u_v9 = u_v14;
    if (i_v17 != 0) {
      u_v16 = u_v14 >> (3 - (byte)i_v17 & 0x1f) | u_v16;
      u_v9 = u_v14 << ((byte)i_v17 & 0x1f);
    }
    u_v14 = CONCAT31(CONCAT21(CONCAT11(*pu_v19,pu_v19[1]),pu_v19[2]),pu_v19[3]);
    pu_v19 = pu_v19 + 4;
  }
  i_v10 = (u_v16 >> 0x1d) - 1;
  CriAt<int>(a1, 0x1750) = i_v10;
  CriAt<int>(a1, 0x1754) = 0x1b - i_v10;
  CriAt<int>(a1, 0x1758) = 1 << ((byte)i_v10 & 0x1f);
  if (i_v11 != 3) goto LAB_14005194d;
  CriAt<uint>(a1, 0x1770) = (uint)((int)u_v9 < 0);
  if (i_v17 == 0x1f) {
    pu_v1 = pu_v19 + 1;
    u_v6 = *pu_v19;
    pu_v2 = pu_v19 + 2;
    pu_v3 = pu_v19 + 3;
    pu_v19 = pu_v19 + 4;
    u_v15 = CONCAT31(CONCAT21(CONCAT11(u_v6,*pu_v1),*pu_v2),*pu_v3);
    u_v16 = u_v14;
LAB_140051921:
    i_v17 = i_v12 + 3;
    u_v9 = u_v16 << 3;
    u_v14 = u_v15;
  }
  else {
    i_v12 = i_v17 + 1;
    u_v16 = u_v9 * 2;
    u_v15 = u_v14;
    if (i_v12 < 0x1d) goto LAB_140051921;
    i_v17 = i_v17 + -0x1c;
    u_v9 = u_v14;
    if (i_v17 != 0) {
      u_v16 = u_v14 >> (3 - (byte)i_v17 & 0x1f) | u_v16;
      u_v9 = u_v14 << ((byte)i_v17 & 0x1f);
    }
    u_v14 = CONCAT31(CONCAT21(CONCAT11(*pu_v19,pu_v19[1]),pu_v19[2]),pu_v19[3]);
    pu_v19 = pu_v19 + 4;
  }
  i_v11 = (u_v16 >> 0x1d) - 1;
  CriAt<int>(a1, 0x1774) = i_v11;
  CriAt<int>(a1, 0x1778) = 0x1b - i_v11;
  CriAt<int>(a1, 0x177c) = 1 << ((byte)i_v11 & 0x1f);
LAB_14005194d:
  l_v8 = (longlong)(int)(uint)(CriAt<int>(a1, 0x1558) != 3);
  CriAt<cri_u64>(a1, 0x16f0) = *(cri_u64 *)(&DAT_1431ba7c8 + l_v13 * 8);
  l_v5 = l_v13 + l_v8 * 5;
  l_v8 = l_v8 + (longlong)CriAt<int>(a1, 0x1550) * 2;
  if (CriAt<int>(a1, 0x1568) == 0) {
    CriAt<cri_u64>(a1, 0x16f8) = *(cri_u64 *)(&DAT_143c493a0 + l_v5 * 8);
    CriAt<cri_u64>(a1, 0x1710) = *(cri_u64 *)(&DAT_143c491b0 + (l_v13 + l_v8 * 5) * 8);
    CriAt<cri_u64>(a1, 0x1720) = *(cri_u64 *)(&DAT_143c492b0 + l_v5 * 8);
    CriAt<cri_u64>(a1, 0x1728) = *(cri_u64 *)(&DAT_143c49250 + l_v5 * 8);
    u_v7 = *(cri_u64 *)(&DAT_143c493f0 + l_v5 * 8);
  }
  else {
    CriAt<cri_u64>(a1, 0x16f8) = *(cri_u64 *)(&DAT_143c49110 + l_v5 * 8);
    CriAt<cri_u64>(a1, 0x1710) = *(cri_u64 *)(&DAT_143c49440 + (l_v13 + l_v8 * 5) * 8);
    CriAt<cri_u64>(a1, 0x1720) = *(cri_u64 *)(&DAT_143c49300 + l_v5 * 8);
    CriAt<cri_u64>(a1, 0x1728) = *(cri_u64 *)(&DAT_143c49350 + l_v5 * 8);
    u_v7 = *(cri_u64 *)(&DAT_143c49160 + l_v5 * 8);
  }
  CriAt<cri_u64>(a1, 0x1730) = u_v7;
  CriAt<cri_u64>(a1, 0x1718) = CriAt<cri_u64>(a1, 0x1728);
  if ((int)u_v9 < 0) {
    i_v11 = i_v17 + 7;
    do {
      i_v12 = i_v11 + 9;
      if (i_v17 + 9 < 0x20) {
        u_v9 = u_v9 << 9;
        i_v17 = i_v17 + 9;
      }
      else {
        i_v12 = i_v11 + -0x17;
        u_v9 = u_v14 << ((byte)(i_v17 + -0x17) & 0x1f);
        u_v14 = CONCAT31(CONCAT21(CONCAT11(*pu_v19,pu_v19[1]),pu_v19[2]),pu_v19[3]);
        pu_v19 = pu_v19 + 4;
        i_v17 = i_v17 + -0x17;
      }
      if (CriAt<int>(a1, 0x1808) <= ((i_v12 >> 3) - *(int *)pu_v4) + -8 + (int)pu_v19) {
        return 0xfffffffd;
      }
      i_v11 = i_v12;
    } while ((int)u_v9 < 0);
  }
  i_v12 = (int)pu_v19;
  i_v11 = i_v17 + 1;
  if (0x1f < i_v11) {
    i_v11 = i_v17 + -0x1f;
    i_v12 = i_v12 + 4;
  }
  FUN_140069020(pu_v4,((i_v11 + 7 >> 3) - *(int *)pu_v4) + -8 + i_v12,pu_v4,loc_28);
  (**(code **)(*a2 + 0x40))(a2,0,pu_v4);
  (**(code **)(*a2 + 0x38))(a2,1,loc_28);
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140051c10
cri_u32 FUN_140051c10(longlong a1,longlong a2,int a3)
{
  int i_v1;
  int i_v2;
  char *_Str1;
  cri_u32 u_v3;
  
  i_v2 = 0;
  if (0 < a3 + -4) {
    do {
      _Str1 = (char *)((longlong)i_v2 + a2 + 4);
      i_v1 = strncmp(_Str1,"IDCPREC",7);
      if (i_v1 == 0) {
        i_v1 = atoi(_Str1 + 0x10);
        CriAt<uint>(a1, 0x1814) = -(uint)(i_v1 != 0) & 3;
      }
      i_v1 = strncmp(_Str1,"STCCODE",7);
      if (i_v1 == 0) {
        i_v1 = atoi(_Str1 + 0x10);
        CriAt<int>(a1, 0x17bc) = i_v1;
        i_v1 = atoi(_Str1 + 0x18);
        CriAt<int>(a1, 0x17c0) = i_v1;
        i_v1 = atoi(_Str1 + 0x20);
        CriAt<int>(a1, 0x17c4) = i_v1;
      }
      i_v1 = FUN_140053000(_Str1);
    } while ((i_v1 == 0) && (i_v2 = i_v2 + 1, i_v2 < a3 + -4));
  }
  u_v3 = 0;
  if (CriAt<int>(a1, 0x17bc) == 8) {
    u_v3 = 0xffffffff;
  }
  if (CriAt<int>(a1, 0x17bc) == 9) {
    u_v3 = 0xffffffff;
  }
  return u_v3;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140051d20
void FUN_140051d20(longlong *a1,int *a2,int *a3)
{
  longlong l_v1;
  int i_v2;
  
  l_v1 = FUN_1400530c0(*a1,*a2,0xffffffff);
  if (l_v1 == 0) {
    i_v2 = *a2;
  }
  else {
    FUN_140053000(l_v1);
    i_v2 = (int)l_v1 - (int)*a1;
  }
  *a1 = *a1 + (longlong)i_v2;
  *a2 = *a2 - i_v2;
  *a3 = *a3 + i_v2;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140051d90
cri_u32 FUN_140051d90(longlong *a1)
{
  // Local structs go to the Any parameters as void*: an Any(Buf*) or Any(Info*) instantiation is named after this
  // function, and tools/fullexe/alias.py takes it as a definition of 0x140051d90 (the intro's demux threads crashed).
  struct Buf { cri_u64 Ptr; int Len; };
  struct Info { cri_u64 Lo; cri_u64 Hi; };
  cri_u32 result;
  longlong found;
  Buf buf;
  Info info;

  (**(code **)(*a1 + 0x30))(a1,1,0x7fffffff,&buf);
  while( true ) {
    if (buf.Len < 4) {
      (**(code **)(*a1 + 0x38))(a1,1,&buf);
      return 0;
    }
    found = FUN_1400530c0(buf.Ptr,buf.Len,0xffffffff);
    if (found != 0) break;
    FUN_140069020((void *)&buf,(cri_u32)(*(volatile int *)&buf.Len + -3),(void *)&buf,(void *)&info);
    (**(code **)(*a1 + 0x40))(a1,0,&buf);
    (**(code **)(*a1 + 0x38))(a1,1,&info);
    (**(code **)(*a1 + 0x30))(a1,1,0x7fffffff,&buf);
  }
  result = FUN_140053000(found);
  FUN_140069020((void *)&buf,(cri_u32)((int)found - (int)buf.Ptr),(void *)&buf,(void *)&info);
  (**(code **)(*a1 + 0x40))(a1,0,&buf);
  (**(code **)(*a1 + 0x38))(a1,1,&info);
  return result;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140051ec0
cri_u32 FUN_140051ec0(longlong *a1,uint *a2)
{
  cri_u32 u_v1;
  longlong l_v2;
  __declspec(align(16)) cri_u8 frame_[32];
  int &loc_28 = *(int *)(frame_ + 0);
  cri_u32 &uStack_24 = *(cri_u32 *)(frame_ + 4);
  int &loc_20 = *(int *)(frame_ + 8);
  cri_u8 (&loc_18)[16] = *(cri_u8 (*)[16])(frame_ + 16);
  
  (**(code **)(*a1 + 0x30))(a1,1,0x7fffffff,&loc_28);
  while( true ) {
    if (loc_20 < 4) {
      (**(code **)(*a1 + 0x38))(a1,1,&loc_28);
      *a2 = 0;
      return 0;
    }
    l_v2 = FUN_1400530c0(CONCAT44(uStack_24,loc_28),loc_20,0xffffffff);
    if (l_v2 != 0) break;
    FUN_140069020(&loc_28,loc_20 + -3,&loc_28,loc_18);
    (**(code **)(*a1 + 0x40))(a1,0,&loc_28);
    (**(code **)(*a1 + 0x38))(a1,1,loc_18);
    (**(code **)(*a1 + 0x30))(a1,1,0x7fffffff,&loc_28);
  }
  *a2 = CriAt<byte>(l_v2, 0x3) | 0x100;
  u_v1 = FUN_140053000(l_v2);
  FUN_140069020(&loc_28,(int)l_v2 - loc_28,&loc_28,loc_18);
  (**(code **)(*a1 + 0x40))(a1,0,&loc_28);
  (**(code **)(*a1 + 0x38))(a1,1,loc_18);
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140052010
cri_u32 FUN_140052010(longlong *a1,int a2,int a3)
{
  struct Chunk { cri_u8 *Data; cri_u32 Size; };
  struct Sj;
  struct SjVtbl {
    void *Reserved00[6];
    void (*GetChunk)(Sj *sj, int line, int size, Chunk *ck);
    void *Reserved38;
    void (*PutChunk)(Sj *sj, int line, Chunk *ck);
  };
  struct Sj { SjVtbl *Vtbl; };
  Sj *sj = (Sj *)a1;
  Chunk ck;
  sj->Vtbl->GetChunk(sj,a2,a3,&ck);
  sj->Vtbl->PutChunk(sj,a2 == 0,&ck);
  return ck.Size;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140052050
cri_u32 FUN_140052050(longlong *a1,int a2,int a3)
{
  int n;
  n = FUN_140052010(a1,a2,a3);
  if (n < a3) {
    n += FUN_140052010(a1,a2,a3 - n);
  }
  return n;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400520c0
cri_u64 FUN_1400520c0(longlong a1,longlong *a2)
{
  cri_u8 *pu_v1;
  cri_u8 *pu_v2;
  cri_u8 *pu_v3;
  cri_u8 u_v4;
  longlong l_v5;
  uint u_v6;
  uint u_v7;
  uint u_v8;
  int i_v9;
  int i_v10;
  uint u_v11;
  ulonglong u_v12;
  cri_u8 *pu_v13;
  uint u_v14;
  ulonglong u_v15;
  ulonglong u_v16;
  ulonglong u_v17;
  cri_u8 loc_38 [16];
  
  u_v16 = 0;
  CriAt<cri_u32>(a1, 0x17bc) = 0;
  CriAt<cri_u32>(a1, 0x1814) = 0;
  CriAt<cri_u32>(a1, 0x1850) = 1;
  l_v5 = a1;
  FUN_140051300(a1);
  CriAt<int>(l_v5, 0x15cc) = CriAt<int>(l_v5, 0x15cc) + 1;
  CriAt<cri_u32>(l_v5, 0x18e4) = 0;
  CriAt<cri_u32>(l_v5, 0x18e8) = 0;
  CriAt<cri_u32>(l_v5, 0x1600) = 0;
  (**(code **)(*a2 + 0x30))(a2,1,0x7fffffff,l_v5 + 0x1800);
  u_v12 = CriAt<ulonglong>(a1, 0x1800) & 0xfffffffffffffffc;
  i_v9 = CriAt<int>(a1, 0x1800) * 8 + (int)u_v12 * -8;
  u_v14 = CONCAT31(CONCAT21(CONCAT11(CriAt<cri_u8>(u_v12, 0x4),CriAt<cri_u8>(u_v12, 0x5)),
                             CriAt<cri_u8>(u_v12, 0x6)),CriAt<cri_u8>(u_v12, 0x7));
  if (i_v9 != 0) {
    u_v14 = u_v14 << ((byte)i_v9 & 0x1f);
  }
  pu_v13 = (&CriAt<cri_u8>(u_v12, 0xc));
  u_v7 = CONCAT31(CONCAT21(CONCAT11(CriAt<cri_u8>(u_v12, 0x8),CriAt<cri_u8>(u_v12, 0x9)),
                            CriAt<cri_u8>(u_v12, 0xa)),CriAt<cri_u8>(u_v12, 0xb));
  if (i_v9 < 0x14) {
    i_v9 = i_v9 + 0xc;
    u_v6 = u_v14 << 0xc;
    CriAt<uint>(a1, 0x1598) = u_v14 >> 0x14;
  }
  else {
    i_v9 = i_v9 + -0x14;
    if (i_v9 == 0) {
      CriAt<uint>(a1, 0x1598) = u_v14 >> 0x14;
      u_v6 = u_v7;
    }
    else {
      CriAt<uint>(a1, 0x1598) = (u_v7 >> (0xc - (byte)i_v9 & 0x1f) | u_v14) >> 0x14;
      u_v6 = u_v7 << ((byte)i_v9 & 0x1f);
    }
    u_v7 = CONCAT31(CONCAT21(CONCAT11(*pu_v13,CriAt<cri_u8>(u_v12, 0xd)),
                              CriAt<cri_u8>(u_v12, 0xe)),CriAt<cri_u8>(u_v12, 0xf));
    pu_v13 = (&CriAt<cri_u8>(u_v12, 0x10));
  }
  if (i_v9 < 0x14) {
    i_v9 = i_v9 + 0xc;
    u_v14 = u_v6 << 0xc;
    CriAt<uint>(a1, 0x159c) = u_v6 >> 0x14;
  }
  else {
    i_v9 = i_v9 + -0x14;
    if (i_v9 == 0) {
      CriAt<uint>(a1, 0x159c) = u_v6 >> 0x14;
      u_v14 = u_v7;
    }
    else {
      CriAt<uint>(a1, 0x159c) = (u_v7 >> (0xc - (byte)i_v9 & 0x1f) | u_v6) >> 0x14;
      u_v14 = u_v7 << ((byte)i_v9 & 0x1f);
    }
    u_v7 = CONCAT31(CONCAT21(CONCAT11(*pu_v13,pu_v13[1]),pu_v13[2]),pu_v13[3]);
    pu_v13 = pu_v13 + 4;
  }
  if (i_v9 < 0x1c) {
    i_v9 = i_v9 + 4;
    u_v6 = u_v14 << 4;
    CriAt<uint>(a1, 0x16d0) = u_v14 >> 0x1c;
  }
  else {
    i_v9 = i_v9 + -0x1c;
    if (i_v9 == 0) {
      CriAt<uint>(a1, 0x16d0) = u_v14 >> 0x1c;
      u_v6 = u_v7;
    }
    else {
      CriAt<uint>(a1, 0x16d0) = (u_v7 >> (4 - (byte)i_v9 & 0x1f) | u_v14) >> 0x1c;
      u_v6 = u_v7 << ((byte)i_v9 & 0x1f);
    }
    u_v7 = CONCAT31(CONCAT21(CONCAT11(*pu_v13,pu_v13[1]),pu_v13[2]),pu_v13[3]);
    pu_v13 = pu_v13 + 4;
  }
  if (i_v9 < 0x1c) {
    i_v9 = i_v9 + 4;
    u_v14 = u_v6 << 4;
  }
  else {
    i_v9 = i_v9 + -0x1c;
    u_v14 = u_v7;
    if (i_v9 != 0) {
      u_v6 = u_v7 >> (4 - (byte)i_v9 & 0x1f) | u_v6;
      u_v14 = u_v7 << ((byte)i_v9 & 0x1f);
    }
    u_v7 = CONCAT31(CONCAT21(CONCAT11(*pu_v13,pu_v13[1]),pu_v13[2]),pu_v13[3]);
    pu_v13 = pu_v13 + 4;
  }
  CriAt<uint>(a1, 0x15a8) = u_v6 >> 0x1c;
  if (i_v9 < 0xe) {
    i_v9 = i_v9 + 0x12;
    u_v6 = u_v14 << 0x12;
    CriAt<uint>(a1, 0x16d4) = u_v14 >> 0xe;
  }
  else {
    i_v9 = i_v9 + -0xe;
    if (i_v9 == 0) {
      CriAt<uint>(a1, 0x16d4) = u_v14 >> 0xe;
      u_v6 = u_v7;
    }
    else {
      CriAt<uint>(a1, 0x16d4) = (u_v7 >> (0x12 - (byte)i_v9 & 0x1f) | u_v14) >> 0xe;
      u_v6 = u_v7 << ((byte)i_v9 & 0x1f);
    }
    u_v7 = CONCAT31(CONCAT21(CONCAT11(*pu_v13,pu_v13[1]),pu_v13[2]),pu_v13[3]);
    pu_v13 = pu_v13 + 4;
  }
  i_v10 = i_v9 + 1;
  if (i_v10 < 0x20) {
    u_v6 = u_v6 * 2;
  }
  else {
    i_v10 = i_v9 + -0x1f;
    u_v6 = u_v7 << ((byte)i_v10 & 0x1f);
    u_v7 = CONCAT31(CONCAT21(CONCAT11(*pu_v13,pu_v13[1]),pu_v13[2]),pu_v13[3]);
    pu_v13 = pu_v13 + 4;
  }
  if (i_v10 < 0x16) {
    i_v10 = i_v10 + 10;
    u_v14 = u_v6 << 10;
    CriAt<uint>(a1, 0x16d8) = u_v6 >> 0x16;
  }
  else {
    i_v10 = i_v10 + -0x16;
    if (i_v10 == 0) {
      CriAt<uint>(a1, 0x16d8) = u_v6 >> 0x16;
      u_v14 = u_v7;
    }
    else {
      CriAt<uint>(a1, 0x16d8) = (u_v7 >> (10 - (byte)i_v10 & 0x1f) | u_v6) >> 0x16;
      u_v14 = u_v7 << ((byte)i_v10 & 0x1f);
    }
    u_v7 = CONCAT31(CONCAT21(CONCAT11(*pu_v13,pu_v13[1]),pu_v13[2]),pu_v13[3]);
    pu_v13 = pu_v13 + 4;
  }
  CriAt<uint>(a1, 0x16dc) = (uint)((int)u_v14 < 0);
  i_v9 = 0;
  if (i_v10 == 0x1f) {
    pu_v1 = pu_v13 + 1;
    u_v4 = *pu_v13;
    pu_v2 = pu_v13 + 2;
    pu_v3 = pu_v13 + 3;
    pu_v13 = pu_v13 + 4;
    u_v6 = CONCAT31(CONCAT21(CONCAT11(u_v4,*pu_v1),*pu_v2),*pu_v3);
    u_v14 = u_v7;
  }
  else {
    i_v9 = i_v10 + 1;
    u_v14 = u_v14 * 2;
    u_v6 = u_v7;
  }
  if (i_v9 == 0x1f) {
    pu_v1 = pu_v13 + 1;
    u_v4 = *pu_v13;
    pu_v2 = pu_v13 + 2;
    pu_v3 = pu_v13 + 3;
    pu_v13 = pu_v13 + 4;
    u_v12 = u_v16;
    u_v8 = CONCAT31(CONCAT21(CONCAT11(u_v4,*pu_v1),*pu_v2),*pu_v3);
    u_v7 = u_v6;
  }
  else {
    u_v12 = (ulonglong)(i_v9 + 1);
    u_v7 = u_v14 * 2;
    u_v8 = u_v6;
  }
  u_v11 = (uint)u_v12;
  u_v17 = u_v16;
  u_v6 = u_v7;
  if ((int)u_v14 < 0) {
    do {
      i_v9 = (int)u_v12;
      if (i_v9 < 0x18) {
        u_v11 = i_v9 + 8;
        u_v7 = u_v6 << 8;
      }
      else {
        u_v11 = i_v9 - 0x18;
        u_v7 = u_v8;
        if (u_v11 != 0) {
          u_v6 = u_v8 >> (8 - (byte)u_v11 & 0x1f) | u_v6;
          u_v7 = u_v8 << ((byte)u_v11 & 0x1f);
        }
        u_v8 = CONCAT31(CONCAT21(CONCAT11(*pu_v13,pu_v13[1]),pu_v13[2]),pu_v13[3]);
        pu_v13 = pu_v13 + 4;
      }
      u_v12 = (ulonglong)u_v11;
      u_v15 = u_v17 + 1;
      *(char *)((longlong)*(char *)(u_v17 + CriAt<longlong>(a1, 0x12d0)) + 0xc00 + a1) =
           (char)(u_v6 >> 0x18);
      u_v17 = u_v15;
      u_v6 = u_v7;
    } while ((longlong)u_v15 < 0x40);
  }
  else {
    FUN_140051330(a1);
  }
  if (u_v11 == 0x1f) {
    pu_v1 = pu_v13 + 1;
    u_v4 = *pu_v13;
    pu_v2 = pu_v13 + 2;
    pu_v3 = pu_v13 + 3;
    pu_v13 = pu_v13 + 4;
    u_v12 = u_v16;
    u_v6 = CONCAT31(CONCAT21(CONCAT11(u_v4,*pu_v1),*pu_v2),*pu_v3);
    u_v14 = u_v8;
  }
  else {
    u_v12 = (ulonglong)(u_v11 + 1);
    u_v14 = u_v7 * 2;
    u_v6 = u_v8;
  }
  u_v8 = (uint)u_v12;
  if ((int)u_v7 < 0) {
    do {
      i_v9 = (int)u_v12;
      if (i_v9 < 0x18) {
        u_v8 = i_v9 + 8;
        u_v7 = u_v14 << 8;
      }
      else {
        u_v8 = i_v9 - 0x18;
        u_v7 = u_v6;
        if (u_v8 != 0) {
          u_v14 = u_v6 >> (8 - (byte)u_v8 & 0x1f) | u_v14;
          u_v7 = u_v6 << ((byte)u_v8 & 0x1f);
        }
        u_v6 = CONCAT31(CONCAT21(CONCAT11(*pu_v13,pu_v13[1]),pu_v13[2]),pu_v13[3]);
        pu_v13 = pu_v13 + 4;
      }
      u_v12 = (ulonglong)u_v8;
      u_v17 = u_v16 + 1;
      *(char *)((longlong)*(char *)(u_v16 + CriAt<longlong>(a1, 0x12d0)) + 0xc40 + a1) =
           (char)(u_v14 >> 0x18);
      u_v16 = u_v17;
      u_v14 = u_v7;
    } while ((longlong)u_v17 < 0x40);
  }
  else {
    FUN_140051360(a1);
  }
  i_v9 = CriAt<int>(a1, 0x159c) + 0xf >> 4;
  i_v10 = CriAt<int>(a1, 0x1598) + 0xf >> 4;
  CriAt<int>(a1, 0x15a4) = i_v9;
  CriAt<int>(a1, 0x15a0) = i_v10;
  CriAt<int>(a1, 0x17a0) = i_v9 * i_v10 + -1;
  CriAt<cri_u32>(a1, 0x15e0) = CriAt<cri_u32>(a1, 0x16d4);
  CriAt<cri_u32>(a1, 0x15e4) = CriAt<cri_u32>(a1, 0x16d8);
  CriAt<cri_u8>(a1, 0x15f1) = CriAt<cri_u8>(a1, 0x16d0);
  CriAt<cri_u8>(a1, 0x15f2) = CriAt<cri_u8>(a1, 0x16dc);
  FUN_140069020(a1 + 0x1800,
                (((int)(u_v8 + 7) >> 3) - CriAt<int>(a1, 0x1800)) + -8 + (int)pu_v13,
                a1 + 0x1800,loc_38);
  (**(code **)(*a2 + 0x40))(a2,0,a1 + 0x1800);
  (**(code **)(*a2 + 0x38))(a2,1,loc_38);
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140052720
// The third parameter is unused; 0x140052ae0 passes it (r8d).
cri_u64 FUN_140052720(longlong a1,longlong *a2,cri_u32 a3)
{
  struct Stream;
  struct Info { cri_u64 Lo; cri_u64 Hi; };
  struct StreamVt {
    void *Reserved00[6];
    void (*Read)(Stream *s,int a,int n,cri_u8 **cur);
    void (*Write)(Stream *s,int a,struct Info *info);
    void (*Seek)(Stream *s,int a,cri_u8 **cur);
  };
  struct Stream { StreamVt *Vt; };
  struct Obj { cri_u8 Reserved00[0x1800]; cri_u8 *Cur; };
  Stream *s = (Stream *)a2;
  cri_u8 **cur = &((Obj *)a1)->Cur;
  Info info;
  ulonglong aligned;
  int bits;
  s->Vt->Read(s,1,0x7fffffff,cur);
  aligned = *(ulonglong *)cur & 0xfffffffffffffffc;
  bits = (*(volatile int *)cur << 3) - ((int)aligned << 3); // the exe reads the low dword again here
  FUN_140069020(cur,(cri_u32)(((bits + 7) >> 3) - *(int *)cur + 4 + (int)aligned),cur,(void *)&info);
  s->Vt->Seek(s,0,cur);
  s->Vt->Write(s,1,&info);
  FUN_140051d90(a2);
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400527c0
int FUN_1400527c0(longlong a1,void *a2,int a3)
{
  longlong *pl_v1;
  code *pc_v2;
  int i_v3;
  int i_v4;
  int i_v5;
  int i_v6;
  longlong l_v7;
  __declspec(align(16)) cri_u8 frame_[32];
  void * &loc_48 = *(void * *)(frame_ + 0);
  int &loc_40 = *(int *)(frame_ + 8);
  void * &loc_38 = *(void * *)(frame_ + 16);
  int &loc_30 = *(int *)(frame_ + 24);
  
  i_v5 = CriAt<int>(a1, 0x1850);
  l_v7 = (longlong)i_v5;
  a3 = a3 + -3;
  i_v6 = 4;
  i_v4 = 0;
  if (4 < a3) {
    do {
      i_v3 = FUN_140053000((longlong)i_v6 + (longlong)a2);
      if (i_v3 != 0) break;
      i_v6 = i_v6 + 1;
    } while (i_v6 < a3);
  }
  i_v3 = 0;
  if (i_v6 == a3) {
    i_v3 = -1;
  }
  if (i_v5 == 1) {
    i_v4 = FUN_140051c10(a1,a2,i_v6);
  }
  pl_v1 = *(longlong **)(a1 + 0x1858 + l_v7 * 0x18);
  if (pl_v1 != (longlong *)0x0) {
    (**(code **)(*pl_v1 + 0x30))(pl_v1,0,i_v6,&loc_48);
    memcpy(loc_48,a2,(longlong)loc_40);
    (**(code **)(*pl_v1 + 0x40))(pl_v1,1,&loc_48);
    if (loc_40 < i_v6) {
      (**(code **)(*pl_v1 + 0x30))(pl_v1,0,i_v6 - loc_40,&loc_38);
      memcpy(loc_38,(void *)((longlong)loc_40 + (longlong)a2),(longlong)loc_30);
      (**(code **)(*pl_v1 + 0x40))(pl_v1,1,&loc_38);
    }
    pc_v2 = *(code **)(a1 + (l_v7 * 3 + 0x30c) * 8);
    if (pc_v2 != (code *)0x0) {
      (*pc_v2)(*(cri_u64 *)(a1 + 0x1868 + l_v7 * 0x18),i_v5);
    }
  }
  if ((i_v5 == 3) && (CriAt<void *>(a1, 0x18b8) != (void *)0x0)) {
    i_v5 = CriAt<int>(a1, 0x18c0);
    if (i_v6 < CriAt<int>(a1, 0x18c0)) {
      i_v5 = i_v6;
    }
    CriAt<int>(a1, 0x18c4) = i_v5;
    memcpy(CriAt<void *>(a1, 0x18b8),a2,(longlong)i_v5);
  }
  if (i_v4 != 0) {
    i_v3 = i_v4;
  }
  return i_v3;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140052950
int FUN_140052950(longlong a1,uint a2,cri_u64 a3)
{
  struct Obj { cri_u8 Reserved00[0x1544]; int Synced; cri_u8 Reserved1548[0xe4]; volatile int Resyncs; int Recovered;
               cri_u8 Reserved1634[0x1c4]; int Lost; volatile int LostCount; };
  Obj *o = (Obj *)a1;
  longlong *s = (longlong *)a3;
  int result;
  uint code;
  int synced = o->Synced;
  if (o->Lost != 0) {
    o->LostCount++;
    o->Lost = 0;
    o->Resyncs++;
    if (synced == 0) {
      return -2;
    }
    o->Recovered++;
  }
  result = (synced != 0) ? -3 : -2;
  for (code = FUN_140051d90(s); code != 0; code = FUN_140051d90(s)) {
    if ((a2 & code) != 0) {
      result = 0;
      break;
    }
    if (FUN_140052010(s,1,4) != 4) {
      break;
    }
  }
  return result;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140052a10
// The third parameter is unused; 0x140052ae0 passes it (r8d).
cri_u32 FUN_140052a10(longlong a1,longlong *a2,cri_u32 a3)
{
  struct Info { cri_u64 Lo; cri_u64 Hi; };
  longlong *cur;
  cri_u64 ptr;
  cri_u64 aligned;
  int bits;
  cri_u32 result;
  Info info;
  
  cur = (&CriAt<longlong>(a1, 0x1800));
  (**(code **)(*a2 + 0x30))(a2,1,0x7fffffff,cur);
  ptr = (cri_u64)*cur;
  aligned = ptr & 0xfffffffffffffffc;
  bits = ((int)*cur << 3) - ((int)aligned << 3);
  result = FUN_1400527c0(a1,(void *)ptr,CriAt<int>(a1, 0x1808));
  FUN_140069020(cur,(cri_u32)(((bits + 7) >> 3) - *(int *)cur + 4 + (int)aligned),cur,(void *)&info);
  (**(code **)(*a2 + 0x40))(a2,0,cur);
  (**(code **)(*a2 + 0x38))(a2,1,&info);
  FUN_140051d90(a2);
  return result;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140052ae0
cri_u32 FUN_140052ae0(longlong a1,longlong *a2)
{
  struct Chunk { cri_u64 Data; cri_u32 Size; };
  Chunk ck;
  Chunk first;
  int ret;
  uint u_v2;
  cri_u32 u_v4;
  
  if (FUN_14004e0a0(a1) != 0) {
    return FUN_14004ff50(0,0xff03020c);
  }
  u_v4 = 0;
  CriAt<cri_u32>(a1, 0x18c4) = 0;
  (**(code **)(*a2 + 0x30))(a2,1,0x7fffffff,&ck);
  (**(code **)(*a2 + 0x38))(a2,1,&ck);
  first.Data = ck.Data;
  first.Size = ck.Size;
  if (FUN_140051270(a1,(int *)&first) == 2) {
    return FUN_140062ae0(a1,a2);
  }
  ret = FUN_140052950(a1,0xffffffff,(cri_u64)a2);
  while (ret == 0) {
    u_v2 = FUN_140051210(a2,(cri_u64 *)&ck);
    if (u_v2 == 0) {
      goto done;
    }
    if ((u_v2 & 3) != 0) {
      goto done;
    }
    if ((char)u_v2 < 0) {
      ret = 0xfffffffe;
      goto done;
    }
    switch (u_v2) {
    case 4:
      u_v4 = 4;
      FUN_1400515c0(a1,a2);
      break;
    case 8:
      u_v4 = 8;
      FUN_140051380(a1,a2);
      break;
    case 0x10:
      FUN_140052720(a1,a2,u_v4);
      break;
    case 0x20:
      FUN_140052a10(a1,a2,u_v4);
      break;
    case 0x40:
      u_v4 = u_v2;
      FUN_1400520c0(a1,a2);
      break;
    }
    ret = FUN_140052950(a1,0xffffffff,(cri_u64)a2);
  }
  return FUN_14004ff50(a1,ret);
done:
  return ret;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140052c80
cri_u32 FUN_140052c80(cri_u64 a1,cri_u64 *a2,int *a3)
{
  cri_u32 u_v1;
  int i_v2;
  longlong *pl_v3;
  
  pl_v3 = (longlong *)FUN_14004eea0(*a2,CriAt<cri_u32>(a2, 0x8));
  if (pl_v3 == (longlong *)0x0) {
    u_v1 = 0xffffffff;
  }
  else {
    u_v1 = FUN_140052ae0(a1,pl_v3);
    i_v2 = (**(code **)(*pl_v3 + 0x48))(pl_v3,1);
    *a3 = CriAt<int>(a2, 0x8) - i_v2;
    (**(code **)(*pl_v3 + 0x18))(pl_v3);
  }
  return u_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140052d00
cri_u32 FUN_140052d00(longlong a1,int *a2)
{
  if (FUN_14004e0a0(a1) != 0) {
    return FUN_14004ff50(0,0xff03020c);
  }
  memcpy(a2,(&CriAt<cri_u8>(a1, 0x1598)),0x80);
  if (CriAt<int>(a1, 0x1568) != 0) {
    a2[0] = (a2[0] + 7) / 8;
    a2[1] = (a2[1] + 7) / 8;
    a2[2] = (a2[0] + 0xf) / 16;
    a2[3] = (a2[1] + 0xf) / 16;
  }
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140052da0
cri_u32 FUN_140052da0(longlong a1,cri_u32 *a2)
{
  if (FUN_14004e0a0(a1) != 0) {
    return FUN_14004ff50(0,0xff03020d);
  }
  *a2 = (*(cri_u32*)((char*)(a1) + 0x16d4));
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140052df0
cri_u32 FUN_140052df0(longlong a1,int *a2,cri_u32 *a3,int *a4)
{
  if (FUN_14004e0a0(a1) != 0) {
    return FUN_14004ff50(0,0xff03020f);
  }
  *a2 = CriAt<int>(a1, 0x16d8) << 0xb;
  *a3 = CriAt<cri_u32>(a1, 0x16e8);
  if (CriAt<int>(a1, 0x16d4) == 0x3ffff) {
    *a4 = -1;
  }
  else {
    *a4 = (CriAt<int>(a1, 0x16e8) * CriAt<int>(a1, 0x16d4)) / 0x708;
  }
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140052e90
cri_u32 FUN_140052e90(longlong a1,cri_u32 *a2,cri_u32 *a3)
{
  if (FUN_14004e0a0(a1) != 0) {
    return FUN_14004ff50(0,0xff03020e);
  }
  *a2 = CriAt<cri_u32>(a1, 0x16e0);
  *a3 = CriAt<cri_u32>(a1, 0x16e4);
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140052ef0
void FUN_140052ef0(cri_u8 *a1)
{
  int v;
  uint code;
  uint i;
  
  for (i = 0; i < 0x100; i++) {
    code = i | 0x100;
    if (code == 0x100) {
      v = 4;
    }
    else if (code == 0x101) {
      v = 3;
    }
    else if (code >= 0x102 && code <= 0x1af) {
      v = 1;
    }
    else if (code == 0x1b2) {
      v = 0x20;
    }
    else if (code == 0x1b3) {
      v = 0x40;
    }
    else if (code == 0x1b5) {
      v = 0x10;
    }
    else if (code == 0x1b7) {
      v = 0x80;
    }
    else if (code == 0x1b8) {
      v = 8;
    }
    else {
      v = 0;
    }
    *a1++ = (cri_u8)v;
  }
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140052fa0
int FUN_140052fa0(void)
{
  cri_u8 table[256];
  FUN_140052ef0(table);
  if (memcmp(table,&DAT_1431ba800,0x100) != 0) {
    return -1;
  }
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140053000
// The exe calls this from another obj, so its callers save and reload registers around the call. noinline inline keeps
// VC9 from using its actual register usage at the same-TU call sites; the code and mangling stay the same.
__declspec(noinline) inline long FUN_140053000(cri_u8 *a1)
{
  if (((((cri_u32)a1[0] << 8) | a1[1]) << 8 | a1[2]) != 1) {
    return 0;
  }
  return (&DAT_1431ba800)[a1[3]];
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140053030
longlong FUN_140053030(longlong a1,int a2,int a3)
{
  cri_u8 *start = (cri_u8 *)a1 - 1;
  cri_u32 code = 0xffffff00;
  cri_u32 next;
  int i;
  for (i = 0; i < a2; i++) {
    code |= start[-i];
    next = code << 8;
    if (next == 0x1000000 && ((&DAT_1431ba800)[code >> 24] & a3) != 0) {
      return (longlong)(start - i);
    }
    code = next;
  }
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400530c0
// The exe calls this from another obj, so its callers save and reload registers around the call. noinline inline keeps
// VC9 from using its actual register usage at the same-TU call sites; the code and mangling stay the same.
__declspec(noinline) inline longlong FUN_1400530c0(longlong a1,int a2,int a3)
{
  cri_u8 *buf = (cri_u8 *)a1;
  cri_u32 code = 0xffffff00;
  cri_u32 b;
  int i;
  for (i = 0; i < a2; i++) {
    b = buf[i];
    if (code == 0x100 && ((&DAT_1431ba800)[b] & a3) != 0) {
      return (longlong)(buf + i - 3);
    }
    code = (code | b) << 8;
  }
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140053140
longlong FUN_140053140(byte *a1,longlong a2,int a3,int a4)
{
  cri_u8 *src = (cri_u8 *)a2;
  cri_u32 code = 0xffffff00;
  cri_u8 b;
  int i;
  for (i = 0; i < a3; i++) {
    b = src[i];
    a1[i] = b;
    if (code == 0x100 && ((&DAT_1431ba800)[b] & a4) != 0) {
      return (longlong)(src + i + 1);
    }
    code = (code | b) << 8;
  }
  return (longlong)(src + i);
}

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400531e0
cri_u32 FUN_1400531e0(longlong a1,cri_u64 a2,cri_u64 a3,cri_u32 *a4)
{
  cri_u32 result;

  result = 0;
  *a4 = 0;
  if (FUN_140039180(a1,0,a4) != 1) {
    return result;
  }
  result = (cri_u32)FUN_140069270((*(cri_u64*)((char*)(a1) + 0x8)),a2,a3);
  return result;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140053260
long FUN_140053260(longlong a1,cri_u64 a2,cri_u64 a3,cri_u64 a4, cri_u32 *a5)
{
  *a5 = 0;
  FUN_140069480((*(cri_u64*)((char*)(a1) + 0x8)),a2,a3,a4);
  return 1;
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400532b0
void FUN_1400532b0(void)
{
  _DAT_143c494e0 = cri_conv("\ncriAdec/PCx64 Ver.1.09 Build:Jan 20 2012 18:13:27\n");
  return;
}

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400532d0
void FUN_1400532d0(void)
{
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400532e0
int FUN_1400532e0(int a1)
{
  int size;
  int base;
  int sjo;

  size = 0;
  base = 0x190;
  size += base;
  sjo = (int)((cri_u32)a1 * sizeof(cri_u64)) + 8;
  size += sjo;
  size += sizeof(cri_u8[0x44]);
  return size;
}

#pragma function(memset)                      // the exe calls memset here rather than expanding it
// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140053340
cri_u64 * FUN_140053340(cri_u64 a1,uint a2,cri_u32 a3)
{
  cri_u64 *adec;

  adec = (cri_u64 *)criHeap_AllocFix((void *)a1,0x188,"CriAdec",0);
  if (adec == NULL) {
    return NULL;
  }
  memset(adec,0,0x188);
  *adec = a1;
  adec[4] = (cri_u64)criHeap_AllocFix((void *)a1,(int)(a2 * sizeof(cri_u64)),"CriAdecSjo",0);
  if (adec[4] == 0) {
    FUN_140053470(adec);
    return NULL;
  }
  memset((void *)adec[4],0,a2 * sizeof(cri_u64));
  (*(cri_u32*)((char*)(adec) + 0xc)) = 0;
  (*(cri_u32*)((char*)(adec) + 0x168)) = a3;
  if ((*(int*)((char*)(adec) + 0x168)) == 0) {
    (*(cri_u32*)((char*)(adec) + 0x16c)) = 2;
  }
  else {
    (*(cri_u32*)((char*)(adec) + 0x16c)) = 4;
  }
  FUN_140054040((longlong)adec,0,0);
  return adec;
}
#pragma intrinsic(memset)

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140053470
void FUN_140053470(cri_u64 *a1)
{
  cri_u64 heap;

  if (a1 != NULL) {
    heap = *a1;
    if (a1[4] != 0) {
      criHeap_Free((void *)heap,(void *)a1[4]);
    }
    criHeap_Free((void *)heap,a1);
  }
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400534d0
void FUN_1400534d0(void* a1)
{
  a1 = a1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400534f0
void FUN_1400534f0(longlong a1,cri_u64 a2)
{
  (*(cri_u64*)((char*)(a1) + 0x18)) = a2;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140053510
void FUN_140053510(longlong a1,uint a2,cri_u64 a3)
{
  *(cri_u64 *)((*(longlong*)((char*)(a1) + 0x20)) + (ulonglong)a2 * 8) = a3;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140053540
void FUN_140053540(longlong a1)
{
  (*(cri_u8*)((char*)(a1) + 0x10)) = 1;
  (*(cri_u32*)((char*)(a1) + 0xc)) = 0;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140053570
void FUN_140053570(longlong a1)
{
  (*(cri_u8*)((char*)(a1) + 0x10)) = 0;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400535b0
void FUN_1400535b0(longlong a1,int *a2)
{
  struct AdecFormat { cri_u8 Reserved00[5]; char Channels; cri_u8 Reserved06[2]; int SamplingRate; int Bits; };
  AdecFormat *format;

  format = (AdecFormat *)((char*)(a1) + 0x28);
  *a2 = format->SamplingRate * (int)format->Channels * 0x12 / 32;
  a2[4] = (*(int*)((char*)(a1) + 0x168));
  a2[3] = format->Bits;
  a2[1] = format->SamplingRate;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140053630
long FUN_140053630(void* a1)
{
  return (*(cri_u8*)((char*)(a1) + 0x10));
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140053650
cri_u64 FUN_140053650(longlong a1)
{
  if ((*(int*)((char*)(a1) + 0xc)) == 1) {
    if (FUN_1400467b8((*(void**)((char*)(a1) + 0x18)),1) == 0) {
      (*(cri_u8*)((char*)(a1) + 0x10)) = 3;
    }
  }
  if ((*(cri_u8*)((char*)(a1) + 0x10)) == 1) {
    FUN_1400536d0(a1);
  }
  if ((*(cri_u8*)((char*)(a1) + 0x10)) == 2) {
    FUN_140053880(a1);
  }
  return 0;
}

// The 0x74-byte ADX header at player+0x28 (layout from the stores in 0x140053e60).
struct AdxHdr {
  cri_u8 Bytes[8];       // 0x00: 4, ?, 3, 4, 0x12, channel count at [5]
  cri_u32 Rate;          // 0x08: a3
  cri_u32 Samples;       // 0x0c: a4
  cri_u32 BlockBits;     // 0x10: 0x20
  cri_u16 Hp;            // 0x14: 500
  cri_u16 HistA[8];      // 0x16
  cri_u16 HistB[8];      // 0x26
  cri_u16 Pad36[3];
  cri_u16 Flag3c;        // 0x3c: 1
  cri_u8 Rest[0x74 - 0x3e];
};

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400536d0
void FUN_1400536d0(longlong a1)
{
  struct Chunk { const cri_u8* Data; unsigned long Size; };
  struct UsfHdr { cri_u32 W0, W4, W8; cri_u8 Bc, Bd, Be, Flag; cri_u32 W10[5]; };   // CriUsfStandardHeader, 0x24 bytes
  uint i;
  AdxHdr* sj;
  long len;
  Chunk usfh;
  void* data;
  longlong hdr;
  UsfHdr usf;

  data = *(void**)((char*)a1 + 0x18);
  sj = (AdxHdr*)((char*)a1 + 0x28);
  hdr = a1 + 0x9c;
  FUN_1400467a0(data,1,0xffffffff,&usfh);
  if (usfh.Size == 0) {
    return;
  }
  // One comma expression: cl then tests the flag in r11d, as the exe does (a separate statement uses eax).
  if (criUsfCmn_ParseUsfHeaderStd(usfh.Data,usfh.Size,(CriUsfStandardHeader*)&usf), usf.Flag != 0) {
    FUN_1400467b0(data,0,&usfh);
    return;
  }
  {
  const cri_u8* contents = criUsfCmn_GetContents(usfh.Data,usfh.Size,&len);
  FUN_14006a7f8((cri_u64)contents,len,a1 + 0x28);
  FUN_140069e44(hdr);
  FUN_140069e54(hdr,(int)(char)sj->Bytes[5]);
  FUN_140069e5c(hdr,0,0,0);
  FUN_140069ef4(hdr,(int)(short)sj->Hp,sj->Rate);
  for (i = 0; i < (uint)(int)(char)sj->Bytes[5]; i = i + 1) {
    FUN_140069e98(hdr,i,sj->HistA[i],sj->HistB[i]);
  }
  FUN_1400467b0(data,0,&usfh);
  *(cri_u32*)((char*)a1 + 0x170) = 0;
  *((cri_u8*)a1 + 0x10) = 2;
  }
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140053880
void FUN_140053880(longlong a1)
{
  struct Chunk { const cri_u8* Data; unsigned long Size; };
  struct UsfHdr { cri_u32 W0, W4, W8; cri_u8 Bc, Bd, Be, Flag; cri_u32 W10[5]; };   // CriUsfStandardHeader, 0x24 bytes
  typedef void (*ChunkCallback)(Chunk*, void*);
  // cl 15 /Od places the locals by a hash of their names (ascending bucket, then the reverse of the declaration order
  // within a bucket); these names and this declaration order give the exe's slots.
  Chunk sfx;
  Chunk pfx;
  uint cutLen;
  uint nchans;
  uint samples;
  UsfHdr hdrStd;
  longlong ctx;
  void* sj;
  Chunk chunk;
  const cri_u8* pdata;
  void** chans;
  uint nsamp;
  Chunk bufs[8];
  cri_u16 code;
  long nLen;
  uint room;
  uint i;
  int x;
  longlong dst16A[8];
  longlong dst32[8];

  sj = *(void**)((char*)a1 + 0x18);
  chans = *(void***)((char*)a1 + 0x20);
  nchans = (int)*(char*)((char*)a1 + 0x2d);
  ctx = a1 + 0x9c;
  nsamp = 0;
  FUN_1400467a0(sj,1,0xffffffff,&chunk);
  if (chunk.Size == 0) {
    return;
  }
  // One comma expression: cl then tests the flag in r11d, as the exe does (a separate statement uses eax).
  if (criUsfCmn_ParseUsfHeaderStd(chunk.Data,chunk.Size,(CriUsfStandardHeader*)&hdrStd), hdrStd.Flag != 0) {
    FUN_1400467b0(sj,0,&chunk);
    return;
  }
  pdata = criUsfCmn_GetContents(chunk.Data,chunk.Size,&nLen);
  code = (cri_u16)((pdata[0] << 8) | pdata[1]);
  if (code == 0x8001) {
    FUN_1400467b0(sj,0,&chunk);
    *((cri_u8*)a1 + 0x10) = 1;
    return;
  }
  samples = (uint)nLen / 0x12 / nchans * 0x20;
  room = samples * *(uint*)((char*)a1 + 0x16c);
  for (i = 0; i < nchans; i = i + 1) {
    if ((uint)FUN_1400467b8(chans[i],0) < room) {
      FUN_1400467a8(sj,1,&chunk);
      return;
    }
  }
  for (i = 0; i < nchans; i = i + 1) {
    FUN_1400467a0(chans[i],0,room,&bufs[i]);
    if (bufs[i].Size < room) {
      FUN_1400467a8(chans[i],0,&bufs[i]);
      FUN_1400467a8(sj,1,&chunk);
      return;
    }
    dst16A[i] = (longlong)bufs[i].Data;
    dst32[i] = (longlong)bufs[i].Data;
    nsamp = bufs[i].Size / *(uint*)((char*)a1 + 0x16c);
  }
  if (*(ChunkCallback*)((char*)a1 + 0x178) != 0) {
    (*(ChunkCallback*)((char*)a1 + 0x178))(&chunk,*(void**)((char*)a1 + 0x180));
  }
  if (*(int*)((char*)a1 + 0x168) == 0) {
    samples = FUN_140069844(ctx,nsamp,(byte*)pdata,nLen,&x,nchans,dst16A,nsamp);
  }
  else {
    samples = FUN_140069ac4(ctx,nsamp,(byte*)pdata,nLen,&x,nchans,dst32,nsamp);
  }
  if (samples > (uint)(*(int*)((char*)a1 + 0x34) - *(int*)((char*)a1 + 0x170))) {
    samples = *(int*)((char*)a1 + 0x34) - *(int*)((char*)a1 + 0x170);
  }
  *(uint*)((char*)a1 + 0x170) = *(int*)((char*)a1 + 0x170) + samples;
  for (i = 0; i < nchans; i = i + 1) {
    if (*(int*)((char*)a1 + 0x168) == 0) {
      cutLen = (uint)(samples * sizeof(short));
    }
    else {
      cutLen = (uint)(samples * sizeof(int));
    }
    criSj_SplitChunk(&bufs[i],cutLen,&pfx,&sfx);
    FUN_1400467b0(chans[i],1,&pfx);
    FUN_1400467a8(chans[i],0,&sfx);
  }
  FUN_1400467b0(sj,0,&chunk);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140053e40
void FUN_140053e40(longlong a1)
{
  (*(cri_u32*)((char*)(a1) + 0xc)) = 1;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140053e60
// Declared as sfr_cri_03 calls it: the exe passes the channel count as a 32-bit value and stores its low byte.
#pragma function(memset)                      // the exe calls memset here rather than expanding it
void FUN_140053e60(void* a1, unsigned long a2, unsigned long a3, unsigned long a4)
{
  int i;
  AdxHdr* hdr;
  longlong adx;

  hdr = (AdxHdr*)((cri_u8*)a1 + 0x28);
  adx = (longlong)a1 + 0x9c;
  if (*((cri_u8*)a1 + 0x10) != 1) {
    return;
  }
  memset(hdr,0,0x74);
  hdr->Bytes[0] = 4;
  hdr->Bytes[2] = 3;
  hdr->Bytes[3] = 4;
  hdr->Bytes[4] = 0x12;
  hdr->Bytes[5] = (cri_u8)a2;
  hdr->Rate = a3;
  hdr->Samples = a4;
  hdr->BlockBits = 0x20;
  hdr->Hp = 500;
  for (i = 0; i < (char)hdr->Bytes[5]; i = i + 1) {
    hdr->HistA[i] = 0;
    hdr->HistB[i] = 0;
  }
  hdr->Flag3c = 1;
  FUN_140069e44(adx);
  FUN_140069e54(adx,(int)(char)hdr->Bytes[5]);
  FUN_140069e5c(adx,0,0,0);
  FUN_140069ef4(adx,(int)(short)hdr->Hp,hdr->Rate);
  for (i = 0; i < (char)hdr->Bytes[5]; i = i + 1) {
    FUN_140069e98(adx,i,hdr->HistA[i],hdr->HistB[i]);
  }
  *(cri_u32*)((char*)a1 + 0x170) = 0;
  *((cri_u8*)a1 + 0x10) = 2;
}
#pragma intrinsic(memset)

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140054040
void FUN_140054040(longlong a1,cri_u64 a2,cri_u64 a3)
{
  (*(cri_u64*)((char*)(a1) + 0x178)) = a2;
  (*(cri_u64*)((char*)(a1) + 0x180)) = a3;
  return;
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140054080
void FUN_140054080(void)
{
  FUN_14006aa90();
  FUN_140066320();
  FUN_140066180(&DAT_143fe82e0);
  FUN_1400659a0(&DAT_1431ba950,&DAT_143fe8420);
  FUN_1400659a0(&DAT_1431ba990,&DAT_143fe83e0);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400540d0
void FUN_1400540d0(void)
{
  return;
}

// The DC rounding callback FUN_140054250 stores in the decoder (sfr_cri_06 keeps it as LAB_140054100; Ghidra made
// no function here): when rounding is on, each enabled block's DC coefficient is divided by 8, rounded half away from 0.
// MS2-FUNCTIONAL: written from the exe (VS2008 build, our toolset differs).
// @0x140054100
void FUN_140054100(char *ctx)
{
  if (CriAt<int>(ctx, 0xd44) == 0) {
    return;
  }
  for (int i = 0; i < 6; i++) {
    if ((CriAt<cri_u32>(ctx, 0x71c) & (1u << i)) != 0) {
      short *p = &CriAt<short>(ctx, 0x780 + i * 0x80);
      int c = *p;
      if (c >= 0) {
        *p = (short)((c + 4) / 8);
      }
      else {
        *p = (short)-((4 - c) / 8);
      }
    }
  }
}

