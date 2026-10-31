// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): CRI MvCore / Sofdec vendor middleware, the obj that
// starts at 0x140052fa0 (support helpers onward, incl. the /Od criAdec code), written from the executable. It is
// its own obj in the exe: sfr_cri_05b's 0x140051d20 keeps its call to the pure 0x140053000 and 0x140051270 reloads its
// argument after the call to 0x1400530c0, which VC9 only does for a callee outside the TU. The CRI library was built with
// VS2008 SP1, and so is this unit (MS2-TOOLSET: vc9, cmake/ms2-unit-profiles.cmake): keep it C++03 (no auto, decltype,
// variadic templates, brace-init or nullptr). Every function is a behaviour-equivalent transcription.
// MS2-UNIT: sfr_cri_05c
// MS2-TOOLSET: vc9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140052fa0-0x140054170 .text$mn
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
void FUN_14004e5a0(void);

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

void FUN_14004eb50(void);

void FUN_14004eb70(void);

cri_u64 * FUN_14004eb90(cri_u64 a1,cri_u32 a2);

void FUN_14004ec20(cri_u64 a1);

cri_u64 FUN_14004ec40(cri_u64 a1);

void FUN_14004ec70(cri_u64 a1,cri_u64 a2,cri_u64 a3);

void FUN_14004ecb0(cri_u64 a1);

cri_u32 FUN_14004ecd0(cri_u64 a1,cri_u32 a2);

void FUN_14004ed10(cri_u64 a1,cri_u32 a2,cri_u32 a3,cri_u64 a4);

void FUN_14004ed60(cri_u64 a1,cri_u32 a2,cri_u64 a3);

void FUN_14004eda0(cri_u64 a1,cri_u32 a2,cri_u64 a3);

cri_u32 FUN_14004ede0(cri_u64 a1,cri_u32 a2,cri_u32 a3,cri_u64 a4);

cri_u64 FUN_14004ee40(cri_u64 a1);

cri_u32 FUN_14004ee70(cri_u64 a1);

cri_u64 FUN_14004eea0(cri_u64 a1,cri_u32 a2);

void FUN_14004eee0(cri_u64 a1, int a2);

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

void FUN_14004f8a0(void);

void FUN_14004f8d0(void);

cri_u64 * FUN_14004f8f0(cri_u64 a1,cri_u32 a2,cri_u32 a3);

cri_u64 * FUN_14004f9a0(void *a1,uint a2);

void FUN_14004fa50(longlong a1,longlong a2,cri_u32 a3,cri_u32 a4);

void FUN_14004fa80(cri_u64 a1);

cri_u64 FUN_14004faa0(cri_u64 a1);

void FUN_14004fad0(cri_u64 a1,cri_u64 a2,cri_u64 a3);

void FUN_14004fb10(cri_u64 a1,cri_u32 a2,cri_u64 a3,cri_u64 a4);

void FUN_14004fb60(cri_u64 a1);

cri_u32 FUN_14004fb80(cri_u64 a1,cri_u32 a2);

void FUN_14004fbc0(cri_u64 a1,cri_u32 a2,cri_u32 a3,cri_u64 a4);

void FUN_14004fc10(cri_u64 a1,cri_u32 a2,cri_u64 a3);

void FUN_14004fc50(cri_u64 a1,cri_u32 a2,cri_u64 a3);

cri_u32 FUN_14004fc90(cri_u64 a1,cri_u32 a2,cri_u32 a3,cri_u64 a4);

cri_u64 FUN_14004fcf0(cri_u64 a1);

cri_u32 FUN_14004fd20(cri_u64 a1);

cri_u32 FUN_14004fd50(cri_u64 a1);

void FUN_14004fd80(cri_u64 a1,cri_u32 a2,cri_u32 a3,cri_u32 a4);

cri_u32 FUN_14004fdd0(cri_u64 a1,cri_u32 a2,cri_u32 a3);

cri_u64 FUN_14004fe20(cri_u64 a1,cri_u32 a2,cri_u32 a3);

cri_u64 FUN_14004fe70(cri_u64 a1,cri_u32 a2);

void FUN_14004feb0(cri_u64 a1,cri_u64 a2,cri_u32 a3,cri_u32 a4);

void FUN_14004ff00(void);

void FUN_14004ff10(cri_u64 *a1);

void FUN_14004ff30(cri_u64 *a1,int a2);

cri_u32 FUN_14004ff50(longlong a1,cri_u32 a2);

cri_u32 FUN_14004ff90(longlong a1,cri_u64 a2,cri_u64 a3);

cri_u32 FUN_140050000(longlong a1,cri_u64 *a2);

void FUN_1400500b0(uint a1,longlong a2);

void FUN_140050100(void);

void FUN_1400501d0(void);

void FUN_1400501e0(void);

DWORD FUN_1400501f0(void);

void FUN_140050210(longlong a1,uint a2);

void FUN_140050280(longlong a1);

int * FUN_1400502b0(void);

void FUN_140050310(cri_u32 *a1);

longlong FUN_140050320(longlong a1,void *a2);

long FUN_140050380(longlong a1,cri_u64 a2,cri_u32 a3);

cri_u32 FUN_1400503e0(longlong a1,void *a2,int *a3);

void FUN_140050480(longlong a1,int a2,cri_u64 a3);

void FUN_140050520(void);

void FUN_140050670(void);

longlong FUN_140050730(void);

void FUN_140050770(longlong *a1);

cri_u64 FUN_140050820(longlong a1,cri_u64 a2,ulonglong a3,cri_u64 *a4);

cri_u32 FUN_140050b30(cri_u64 a1,cri_u64 *a2,int *a3);

void FUN_140050bc0(void);

cri_u32 FUN_140050bd0(longlong a1,cri_u64 a2,void *a3);

cri_u32 FUN_140050e00(cri_u64 a1,cri_u64 a2);

void FUN_140050e90(longlong a1);

cri_u32 FUN_140050ef0(cri_u64 a1,cri_u64 *a2,int *a3,cri_u64 a4);

void FUN_140050f80(void);

void FUN_140050f90(cri_u64 *a1,ulonglong a2);

void FUN_140050fc0(void);

__declspec(noinline) void FUN_1400511a0(longlong a1,int a2,cri_u64 a3,cri_u64 a4, cri_u64 a5);

__declspec(noinline) void FUN_1400511d0(longlong a1,cri_u64 a2,cri_u32 a3);

void FUN_1400511f0(longlong a1,cri_u64 *a2,cri_u32 *a3);

long FUN_140051210(longlong *a1,cri_u64 *a2);

int FUN_140051270(longlong a1,int *a2);

void FUN_140051300(longlong a1);

void FUN_140051330(longlong a1);

void FUN_140051360(longlong a1);

cri_u64 FUN_140051380(longlong a1,longlong *a2);

cri_u64 FUN_1400515c0(longlong a1,longlong *a2);

cri_u32 FUN_140051c10(longlong a1,longlong a2,int a3);

void FUN_140051d20(longlong *a1,int *a2,int *a3);

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

cri_u32 FUN_140052c80(cri_u64 a1,cri_u64 *a2,int *a3);

cri_u32 FUN_140052d00(longlong a1,int *a2);

cri_u32 FUN_140052da0(longlong a1,cri_u32 *a2);

cri_u32 FUN_140052df0(longlong a1,int *a2,cri_u32 *a3,int *a4);

cri_u32 FUN_140052e90(longlong a1,cri_u32 *a2,cri_u32 *a3);

void FUN_140052ef0(cri_u8 *a1);

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
long FUN_140053000(cri_u8 *a1)
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
longlong FUN_1400530c0(longlong a1,int a2,int a3)
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

