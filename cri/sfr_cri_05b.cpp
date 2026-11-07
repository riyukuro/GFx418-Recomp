// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): CRI MvCore / Sofdec vendor middleware (YUV->RGB
// converters, MPEG-2 video decode kernels and the CRI support layer), written from the executable. The CRI library was
// built with VS2008 SP1, and so is this unit (MS2-TOOLSET: vc9, cmake/ms2-unit-profiles.cmake): keep it C++03 (no auto,
// decltype, variadic templates, brace-init or nullptr). Every function is a behaviour-equivalent transcription.
// MS2-UNIT: sfr_cri_05b
// MS2-TOOLSET: vc9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14004e5a0-0x140052fa0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
class CriMvEasyPlayer;
struct _RTL_CRITICAL_SECTION;
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
extern "C" cri_u64 DAT_1431ba7c8[];
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
extern "C" cri_u64 DAT_143c49110[];
extern "C" cri_u64 DAT_143c49160[];
extern "C" cri_u64 DAT_143c491b0[];
extern "C" cri_u64 DAT_143c49250[];
extern "C" cri_u64 DAT_143c492b0[];
extern "C" cri_u64 DAT_143c49300[];
extern "C" cri_u64 DAT_143c49350[];
extern "C" cri_u64 DAT_143c493a0[];
extern "C" cri_u64 DAT_143c493f0[];
extern "C" cri_u64 DAT_143c49440[];
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
void FUN_142ccc850(void* decoder);   // the macroblock-type dispatch (sfr_cri_03)

cri_u64 FUN_140027ed8(Any a0,Any a1,Any a2,Any a3);
cri_u64 FUN_140027fb4(Any a0,Any a1);
// cri_movie.h's heap API (C linkage), called with its own types by the /Od criAdec code
extern "C" void* criHeap_AllocFix(void* heap, int size, const char* name, int align);
extern "C" int criHeap_Free(void* heap, void* ptr);
long FUN_140039180(CriMvEasyPlayer *, long, unsigned long *);  // C3: the definition's signature
longlong FUN_14003b674(Any a0,Any a1,Any a2);
cri_u64 FUN_1400467b8(Any a0,Any a1 = 0);
// sfr_cri_03's definitions; the /Od criAdec code calls them with these types
extern "C" long FUN_1400467b8(void* object, long query);
void FUN_1400467c0(Any a0,Any a1,Any a2,Any a3);
// sfr_cri_03's names and types for 0x14003b3fc, 0x14003b674 and 0x1400467c0: the /Od ADX loader functions below
// call these and the typed 0x1400467a0-b8 overloads, so their arguments are passed directly (no Any temporaries).
struct CriUsfStandardHeader;
extern "C" unsigned long criUsfCmn_ParseUsfHeaderStd(const unsigned char* data, unsigned long size, CriUsfStandardHeader* header);
extern "C" const unsigned char* criUsfCmn_GetContents(const unsigned char* data, unsigned long size, long* contentSize);
void criSj_SplitChunk(const void* source, unsigned long maximum, void* prefix, void* suffix);
void FUN_14004c370();
void FUN_14004c7c0(Any a0,Any a1);
void cftfx_makeConvYccRgbTable(void);
cri_u32 mpvlib_ChkFatal(void);
cri_u64 FUN_14004ddb0(cri_u64 a1);
void mpvlib_InitClip0255(void);
void mpvlib_InitObjTbl(void);
void FUN_14004de60(longlong a1);
void FUN_14004def0(cri_u32 *a1);
longlong mpvlib_SearchFreeHn(void);
void FUN_14004dfc0(longlong a1);
void FUN_14004e030(int a1,cri_u32 a2);
long FUN_14004e0a0(longlong a1);
void FUN_14004e0c0(longlong a1);
void FUN_14004e100(longlong a1);
void FUN_14004e1c0(int a1,longlong a2);
void FUN_14004e270(longlong a1);
longlong FUN_14004e460(longlong a1);
void FUN_14004e5b0(cri_u64 a1,cri_u64 a2);
void sjmem_Init(void);
void sjmem_Finish(void);
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
void sjrbf_Init(void);
void sjrbf_Finish(void);
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
void MPVERR_Init(void);
void FUN_14004ff10(cri_u64 *a1);
void FUN_14004ff30(cri_u64 *a1,int a2);
cri_u32 FUN_14004ff50(longlong a1,cri_u32 a2);
void mpvmulti_SetDlgPara(void);
void mpvmulti_lock(void);
void mpvmulti_unlock(void);
DWORD mpvmulti_GetNumberOfProcessors(void);
void FUN_140050280(longlong a1);
int * mpvmulti_CreateMulti(void);
longlong FUN_140050320(longlong a1,void *a2);
long FUN_140050380(longlong a1,cri_u64 a2,cri_u32 a3);
cri_u32 FUN_1400503e0(longlong a1,void *a2,int *a3);
void FUN_140050480(longlong a1,int a2,cri_u64 a3);
void mpvmulti_DecServer(longlong *a1);
void MPVFRM_Init(void);
cri_u32 FUN_140050bd0(longlong a1,cri_u64 a2,void *a3);
void FUN_140050f90(cri_u64 *a1,ulonglong a2);
void MPVHDEC_Init(void);
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
int MPVDELI_Init(void);
long FUN_140053000(cri_u8 *a1);
longlong FUN_1400530c0(longlong a1,int a2,int a3);
void FUN_140053470(cri_u64 *a1);
void FUN_1400536d0(longlong a1);
void FUN_140053880(longlong a1);
void FUN_140054040(longlong a1,cri_u64 a2,cri_u64 a3);
void MPVM2V_Init();
void MPVM2V_Destroy(longlong a0);
int MPVM2V_DecodeFrm(cri_any, cri_any, cri_any);  // 0x140062a40 (sfr_cri_06b)
void MPVM2V_RequestStop(cri_any);  // C3: the definition's signature
int MPVM2V_DecodePicAtr(cri_any, cri_any);  // 0x140062ae0 (sfr_cri_06b)
int FUN_140062bc0(Any a0,Any a1,Any a2);
void FUN_140064d90(Any a0,Any a1);
void UTY_MemcpyDword(void *dst, const void *src, ulonglong n);  // C3: the definition's signature
void * FUN_140064eb0(Any a0,Any a1,Any a2);
void UTY_MemsetDword(cri_any,cri_any,cri_any);  // C3: the definition's signature
void * FUN_140064eb0(void *dst,const void *src,cri_u64 size);
void FUN_140065000(Any a0);
void FUN_140065030(longlong a0);
cri_u64 MPVSL_DecPicture(longlong,longlong *); // C3: the definition's signature
// sfr_cri_06 defines 0x140062a40 and 0x140065450 with cri_any; 0x140050bd0 keeps only the low 32 bits of their results.
void MPVUMC_Init();
void MPVUMC_Finish();
void MPVUMC_InitOutRfb(cri_any);  // C3: the definition's signature
void MPVUMC_EndOfFrame(void);  // C3: the definition's signature
void FUN_140065900(Any a0);
void DCT_FsriInit();
void FUN_140066360(longlong a0);
void MPVCDEC_StartFrame(__int64); // C3: the definition's signature
void MPVBDEC_StartFrame(__int64); // C3: the definition's signature
void MPVCMC_InitMcOiRt(__int64); // C3: the definition's signature
void MPVCMC_SetCcnt(__int64); // C3: the definition's signature
char * CRICRW_Strcpy(char *dst,cri_u64 size,const char *src);  // C3: the definition's signature
char * CRICRW_Strcat(char *dst,cri_u64 size,const char *src);  // C3: the definition's signature
void SJCRS_Init();
void SJCRS_Finish();
void SJCRS_Lock();
void SJCRS_Unlock();
void CRIDLG_Init();
void CRIDLG_Finish();
unsigned __int64 CRIDLG_Create(unsigned __int64, unsigned int);  // C3: the definition's signature
void CRIDLG_Destroy(unsigned __int64); // C3: the definition's signature
unsigned int CRIDLG_TryBeginInvoke(unsigned __int64, unsigned __int64, unsigned __int64); // C3: the definition's signature
void CRIDLG_EndInvoke(unsigned __int64, unsigned int); // C3: the definition's signature
unsigned int CRIDLG_GetPriority(unsigned __int64); // C3: the definition's signature
void CRIDLG_SetPriority(unsigned __int64, unsigned int); // C3: the definition's signature
void CRIDLG_SetAffinityMask(unsigned __int64, unsigned int); // C3: the definition's signature
extern "C" unsigned __int64 CRICRS_Create(__int64, int);  // C3: the definition's signature
extern "C" void CRICRS_Destroy(_RTL_CRITICAL_SECTION *); // C3: the definition's signature
extern "C" unsigned int CRICRS_Enter(_RTL_CRITICAL_SECTION *);   // C3: the definition's signature
extern "C" unsigned int CRICRS_Leave(_RTL_CRITICAL_SECTION *);   // C3: the definition's signature
void MPVUMCT_Intra(__int64);  // C3: the definition's signature
void MPVUMCT_PpicSkipped(__int64, int); // C3: the definition's signature
void MPVUMCT_BpicSkipped(__int64, int); // C3: the definition's signature
void FUN_140068db0(__int64);  // C3: the definition's signature
void FUN_140068e70(__int64);  // C3: the definition's signature
void MPVUMCT_BiDirect(__int64); // C3: the definition's signature
void SJ_SplitChunk(__int64 *, int, __int64 *, __int64 *);  // C3: the definition's signature
int criAdxDecCore_Decode(longlong, int, byte *, uint, int *, uint, longlong *, uint);
int FUN_140069ac4(longlong, int, byte *, uint, int *, uint, longlong *, uint);
void criAdxDecCore_Reset(longlong);
void criAdxDecCore_SetNumChan(longlong, int);
void criAdxDecCore_SetEncryptionKey(longlong, int, int, int);
void criAdxDecCore_SetDlyVal(longlong, uint, short, short);
void criAdxDecCore_SetCutoffFreqency(longlong, uint, uint);
void DCT_Isse2Init();
void MPVUMC_BpicSkipped(void *,long);  // sfr_cri_03, 0x142ccc860
void FUN_142ccca50(void *);  // C3: the definition's signature
void FUN_142ccca90(void *);  // C3: the definition's signature
void MPVUMC_BiDirect(void *);  // C3: the definition's signature
void MPVUMC_PpicSkipped(void *,long);  // sfr_cri_03, 0x142cccb30
void thunk_FUN_140050520();
void thunk_FUN_140050670();
cri_u32 thunk_FUN_14005b040();
void thunk_FUN_14005b0b0();
void thunk_FUN_140067390(Any a0);
void thunk_FUN_1400afe60(const char *msg);  // C3: the definition's signature (sfr_cri_07)

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
// written from the exe; the message is a literal, not the exe's .rdata copy at 0x1431ba2f8.
// @0x14004e5a0
void FUN_14004e5a0(void)
{
  thunk_FUN_1400afe60("SJMEM Error");
}

// @0x14004e5b0
void FUN_14004e5b0(cri_u64 a1,cri_u64 a2)
{
  char msg[64];
  CRICRW_Strcpy(msg,0x40,(const char *)a1);
  CRICRW_Strcat(msg,0x40,(const char *)a2);
  thunk_FUN_1400afe60(msg);
}

// @0x14004e610
void sjmem_Init(void)
{
  if (DAT_143badb24 == 0) {
    memset(&DAT_143ffbce0,0,0x1800);
  }
  DAT_143badb24++;
}

// @0x14004e650
void sjmem_Finish(void)
{
  DAT_143badb24 = DAT_143badb24 + -1;
  if (DAT_143badb24 == 0) {
    memset(&DAT_143ffbce0,0,0x1800);
  }
  return;
}

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

// @0x14004eb50
void SJMEM_Init(void)
{
  SJCRS_Init();
  SJCRS_Lock();
  sjmem_Init();
  SJCRS_Unlock();
  return;
}

// @0x14004eb70
void SJMEM_Finish(void)
{
  SJCRS_Lock();
  sjmem_Finish();
  SJCRS_Unlock();
  SJCRS_Finish();
  return;
}

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

// @0x14004ec20
void SJMEM_Destroy(cri_u64 a1)
{
  SJCRS_Lock();
  FUN_14004e680(a1);
  SJCRS_Unlock();
  return;
}

// @0x14004ec40
cri_u64 SJMEM_GetUuid(cri_u64 a1)
{
  cri_u64 u_v1;
  
  SJCRS_Lock();
  u_v1 = FUN_14004e6e0(a1);
  SJCRS_Unlock();
  return u_v1;
}

// @0x14004ec70
void SJMEM_EntryErrFunc(cri_u64 a1,cri_u64 a2,cri_u64 a3)
{
  SJCRS_Lock();
  FUN_14004e730(a1,a2,a3);
  SJCRS_Unlock();
  return;
}

// @0x14004ecb0
void SJMEM_Reset(cri_u64 a1)
{
  SJCRS_Lock();
  FUN_14004e770(a1);
  SJCRS_Unlock();
  return;
}

// @0x14004ecd0
cri_u32 SJMEM_GetNumData(cri_u64 a1,cri_u32 a2)
{
  cri_u32 u_v1;
  
  SJCRS_Lock();
  u_v1 = FUN_14004e7b0(a1,a2);
  SJCRS_Unlock();
  return u_v1;
}

// @0x14004ed10
void SJMEM_GetChunk(cri_u64 a1,cri_u32 a2,cri_u32 a3,cri_u64 a4)
{
  SJCRS_Lock();
  FUN_14004e820((longlong)a1,(int)a2,(int)a3,(longlong *)a4);
  SJCRS_Unlock();
  return;
}

// @0x14004ed60
void SJMEM_PutChunk(cri_u64 a1,cri_u32 a2,cri_u64 a3)
{
  SJCRS_Lock();
  FUN_14004e8c0((longlong)a1,(int)a2,(longlong *)a3);
  SJCRS_Unlock();
  return;
}

// @0x14004eda0
void SJMEM_UngetChunk(cri_u64 a1,cri_u32 a2,cri_u64 a3)
{
  SJCRS_Lock();
  FUN_14004e940((longlong)a1,(int)a2,(longlong *)a3);
  SJCRS_Unlock();
  return;
}

// @0x14004ede0
cri_u32 SJMEM_IsGetChunk(cri_u64 a1,cri_u32 a2,cri_u32 a3,cri_u64 a4)
{
  cri_u32 u_v1;
  
  SJCRS_Lock();
  u_v1 = FUN_14004e9f0((longlong)a1,(int)a2,(int)a3,(int *)a4);
  SJCRS_Unlock();
  return u_v1;
}

// @0x14004ee40
cri_u64 SJMEM_GetBufPtr(cri_u64 a1)
{
  cri_u64 u_v1;
  
  SJCRS_Lock();
  u_v1 = FUN_14004eab0(a1);
  SJCRS_Unlock();
  return u_v1;
}

// @0x14004ee70
cri_u32 SJMEM_GetBufSize(cri_u64 a1)
{
  cri_u32 u_v1;
  
  SJCRS_Lock();
  u_v1 = FUN_14004eb00(a1);
  SJCRS_Unlock();
  return u_v1;
}

// @0x14004eea0
cri_u64 FUN_14004eea0(cri_u64 a1,cri_u32 a2)
{
  cri_u64 u_v1;
  
  SJCRS_Lock();
  u_v1 = (cri_u64)FUN_14004eb90(a1,a2);
  SJCRS_Unlock();
  return u_v1;
}

// The SJRBF error callback (FUN_14004f8f0 stores it as LAB_14004eee0; Ghidra made no function here): the error code
// picks the message.
// Written from the exe; the messages are literals, not the exe's .rdata copies at 0x1431ba508-0x1431ba548.
// @0x14004eee0
void FUN_14004eee0(cri_u64 a1, int a2)
{
  (void)a1;
  switch (a2) {
  case -3:
    thunk_FUN_1400afe60("SJRBF Parameter Error");
    break;
  case -2:
    thunk_FUN_1400afe60("SJRBF Internal Error");
    break;
  default:
    thunk_FUN_1400afe60(a2 == -1 ? "SJRBF Fatal Error" : "SJRBF Error");
    break;
  }
}

// @0x14004ef20
void FUN_14004ef20(cri_u64 a1,cri_u64 a2)
{
  char msg[64];
  CRICRW_Strcpy(msg,0x40,(const char *)a1);
  CRICRW_Strcat(msg,0x40,(const char *)a2);
  thunk_FUN_1400afe60(msg);
}

// @0x14004ef80
void sjrbf_Init(void)
{
  if (DAT_143badb30 == 0) {
    memset(&DAT_143fe84e0,0,0x13800);
  }
  DAT_143badb30++;
}

// @0x14004efc0
void sjrbf_Finish(void)
{
  DAT_143badb30 = DAT_143badb30 + -1;
  if (DAT_143badb30 == 0) {
    memset(&DAT_143fe84e0,0,0x13800);
  }
  return;
}

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
  if (CriAt<int>(a1, 0x30) == 0) {
    FUN_14004ef20("E2004090219"," : Illegal buffer size.");
    return;
  }
  if (a2 == 0) {
    i_v1 = CriAt<int>(a1, 0x30) + (CriAt<int>(a1, 0x34) - CriAt<int>(a1, 0x20));
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
    i_v1 = CriAt<int>(a1, 0x30) + (CriAt<int>(a1, 0x34) - CriAt<int>(a1, 0x24));
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

// @0x14004f620
int FUN_14004f620(longlong a1,int a2,int a3,int *a4)
{
  int i_v1;
  int i_v2;
  
  if (a1 == 0) {
    FUN_14004ef20("E2004090217"," : NULL pointer is passed.");
    return 0;
  }
  if (CriAt<int>(a1, 0x8) == 0) {
    FUN_14004ef20("E2004090218"," : Specified handle is invalid.");
    return 0;
  }
  if (a2 == 0) {
    // MIN(limit, free space)
    i_v1 = (CriAt<int>(a1, 0x1c) < ((CriAt<int>(a1, 0x34) - CriAt<int>(a1, 0x20)) + CriAt<int>(a1, 0x30))) ? CriAt<int>(a1, 0x1c) : ((CriAt<int>(a1, 0x34) - CriAt<int>(a1, 0x20)) + CriAt<int>(a1, 0x30));
    i_v2 = (i_v1 < a3) ? i_v1 : a3;
  }
  else if (a2 == 1) {
    // MIN(limit, free space)
    i_v1 = (CriAt<int>(a1, 0x18) < ((CriAt<int>(a1, 0x34) - CriAt<int>(a1, 0x24)) + CriAt<int>(a1, 0x30))) ? CriAt<int>(a1, 0x18) : ((CriAt<int>(a1, 0x34) - CriAt<int>(a1, 0x24)) + CriAt<int>(a1, 0x30));
    i_v2 = (i_v1 < a3) ? i_v1 : a3;
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

// @0x14004f8a0
void SJRBF_Init(void)
{
  _DAT_143badb28 = cri_conv("\nSJ/PCx64 Ver.6.48 Build:Jan 13 2012 18:30:46\n");
  SJCRS_Init();
  SJCRS_Lock();
  sjrbf_Init();
  SJCRS_Unlock();
  return;
}

// @0x14004f8d0
void SJRBF_Finish(void)
{
  SJCRS_Lock();
  sjrbf_Finish();
  SJCRS_Unlock();
  SJCRS_Finish();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x14004f8f0
cri_u64 * FUN_14004f8f0(cri_u64 a1,cri_u32 a2,cri_u32 a3)
{
  struct Entry { void *Vtbl; int Used; void *Name; cri_u8 Reserved18[0x10]; cri_u64 Arg; cri_u32 Param1; cri_u32 Param2;
                 cri_u8 Reserved38[0x10]; void *Fn; Entry *Self; cri_u64 Reserved58; cri_u64 Reserved60; };
  Entry *pool = (Entry *)&DAT_143fe84e0;
  Entry *e;
  int i;
  int *used;
  i = 0;
  for (used = &pool[0].Used; (longlong)used < (longlong)&pool[0x300].Used; used += 0x1a) {
    if (*used == 0) break;
    i++;
  }
  if (i == 0x300) {
    return (cri_u64 *)0x0;
  }
  e = &pool[i];
  e->Vtbl = &DAT_143a48840;
  e->Arg = a1;
  e->Name = &DAT_1431ba4f8;
  e->Used = 1;
  e->Param1 = a2;
  e->Param2 = a3;
  e->Fn = (void *)&FUN_14004eee0;
  e->Self = e;
  e->Reserved58 = 0;
  e->Reserved60 = 0;
  FUN_14004f150((longlong)e);
  return (cri_u64 *)e;
}

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

// @0x14004fa80
void SJRBF_Destroy(cri_u64 a1)
{
  SJCRS_Lock();
  FUN_14004f000(a1);
  SJCRS_Unlock();
  return;
}

// @0x14004faa0
cri_u64 SJRBF_GetUuid(cri_u64 a1)
{
  cri_u64 u_v1;
  
  SJCRS_Lock();
  u_v1 = FUN_14004f060(a1);
  SJCRS_Unlock();
  return u_v1;
}

// @0x14004fad0
void SJRBF_EntryErrFunc(cri_u64 a1,cri_u64 a2,cri_u64 a3)
{
  SJCRS_Lock();
  FUN_14004f0b0(a1,a2,a3);
  SJCRS_Unlock();
  return;
}

// @0x14004fb10
void SJRBF_EntryPutFunc(cri_u64 a1,cri_u32 a2,cri_u64 a3,cri_u64 a4)
{
  SJCRS_Lock();
  FUN_14004f0f0(a1,a2,a3,a4);
  SJCRS_Unlock();
  return;
}

// @0x14004fb60
void SJRBF_Reset(cri_u64 a1)
{
  SJCRS_Lock();
  FUN_14004f150(a1);
  SJCRS_Unlock();
  return;
}

// @0x14004fb80
cri_u32 SJRBF_GetNumData(cri_u64 a1,cri_u32 a2)
{
  cri_u32 u_v1;
  
  SJCRS_Lock();
  u_v1 = FUN_14004f1a0(a1,a2);
  SJCRS_Unlock();
  return u_v1;
}

// @0x14004fbc0
void SJRBF_GetChunk(cri_u64 a1,cri_u32 a2,cri_u32 a3,cri_u64 a4)
{
  SJCRS_Lock();
  FUN_14004f220((longlong)a1,(int)a2,(int)a3,(longlong *)a4);
  SJCRS_Unlock();
  return;
}

// @0x14004fc10
void SJRBF_PutChunk(cri_u64 a1,cri_u32 a2,cri_u64 a3)
{
  SJCRS_Lock();
  FUN_14004f350((longlong)a1,(int)a2,(longlong *)a3);
  SJCRS_Unlock();
  return;
}

// @0x14004fc50
void SJRBF_UngetChunk(cri_u64 a1,cri_u32 a2,cri_u64 a3)
{
  SJCRS_Lock();
  FUN_14004f490((longlong)a1,(int)a2,(longlong *)a3);
  SJCRS_Unlock();
  return;
}

// @0x14004fc90
cri_u32 SJRBF_IsGetChunk(cri_u64 a1,cri_u32 a2,cri_u32 a3,cri_u64 a4)
{
  cri_u32 u_v1;
  
  SJCRS_Lock();
  u_v1 = FUN_14004f620((longlong)a1,(int)a2,(int)a3,(int *)a4);
  SJCRS_Unlock();
  return u_v1;
}

// @0x14004fcf0
cri_u64 SJRBF_GetBufPtr(cri_u64 a1)
{
  cri_u64 u_v1;
  
  SJCRS_Lock();
  u_v1 = FUN_14004f700(a1);
  SJCRS_Unlock();
  return u_v1;
}

// @0x14004fd20
cri_u32 SJRBF_GetBufSize(cri_u64 a1)
{
  cri_u32 u_v1;
  
  SJCRS_Lock();
  u_v1 = FUN_14004f750(a1);
  SJCRS_Unlock();
  return u_v1;
}

// @0x14004fd50
cri_u32 SJRBF_GetXtrSize(cri_u64 a1)
{
  cri_u32 u_v1;
  
  SJCRS_Lock();
  u_v1 = FUN_14004f7a0(a1);
  SJCRS_Unlock();
  return u_v1;
}

// @0x14004fd80
void SJRBF_SetFlowCnt(cri_u64 a1,cri_u32 a2,cri_u32 a3,cri_u32 a4)
{
  SJCRS_Lock();
  FUN_14004f7f0(a1,a2,a3,a4);
  SJCRS_Unlock();
  return;
}

// @0x14004fdd0
cri_u32 SJRBF_GetFlowCnt(cri_u64 a1,cri_u32 a2,cri_u32 a3)
{
  cri_u32 u_v1;
  
  SJCRS_Lock();
  u_v1 = FUN_14004f840(a1,a2,a3);
  SJCRS_Unlock();
  return u_v1;
}

// @0x14004fe20
extern "C" cri_u64 SJRBF_Create(cri_u64 a1,cri_u32 a2,cri_u32 a3)
{
  cri_u64 u_v1;
  
  SJCRS_Lock();
  u_v1 = (cri_u64)FUN_14004f8f0(a1,a2,a3);
  SJCRS_Unlock();
  return u_v1;
}

// @0x14004fe70
cri_u64 SJRBF_CreateHndl(cri_u64 a1,cri_u32 a2)
{
  cri_u64 u_v1;
  
  SJCRS_Lock();
  u_v1 = (cri_u64)FUN_14004f9a0(a1,a2);
  SJCRS_Unlock();
  return u_v1;
}

// @0x14004feb0
void SJRBF_SetBuffer(cri_u64 a1,cri_u64 a2,cri_u32 a3,cri_u32 a4)
{
  SJCRS_Lock();
  FUN_14004fa50(a1,a2,a3,a4);
  SJCRS_Unlock();
  return;
}

// @0x14004ff00
void MPVERR_Init(void)
{
  // The exe calls this from another obj, so the call stays even though it does nothing. The barrier emits no code; it
  // only stops VC9 from dropping the same-TU calls.
  _ReadWriteBarrier();
  return;
}

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

// @0x14004ff30
void FUN_14004ff30(cri_u64 *a1,int a2)
{
  CriAt<int>(a1, 0x10) = a2;
  if ((a2 != 0) && ((code *)*a1 != (code *)0x0)) {
    (*(code *)*a1)(a1[1]);
  }
  return;
}

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

// @0x14004ff90
cri_u32 MPV_SetErrFunc(longlong a1,cri_u64 a2,cri_u64 a3)
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

// @0x140050000
cri_u32 MPV_GetErrInf(longlong a1,cri_u64 *a2)
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
void MPV_SetDlgPara(uint a1,longlong a2)
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

// @0x140050100
void mpvmulti_SetDlgPara(void)
{
  struct Ch { longlong Handle; cri_u8 Reserved08[0xf8]; };
  struct Cfg { cri_u32 Value[3]; };
  int i;
  longlong h;
  cri_u32 v;    // the exe loads each setting straight into the argument register
  for (i = 0; i < DAT_143c490e8; i++) {
    h = ((Ch *)DAT_143c490e0)[i].Handle;
    if (h != 0) {
      v = ((Cfg *)&DAT_143badb60)[i].Value[0];
      if (v == 0x5a5a5a5a) {
        v = ((Cfg *)&DAT_143badbb8)[i].Value[0];
      }
      CRIDLG_SetAffinityMask(h,v);
      v = ((Cfg *)&DAT_143badb60)[i].Value[1];
      if (v == 0x5a5a5a5a) {
        v = ((Cfg *)&DAT_143badbb8)[i].Value[1];
      }
      CRIDLG_SetPriority(h,v);
    }
  }
}

// @0x1400501d0
void mpvmulti_lock(void)
{
  CRICRS_Enter((_RTL_CRITICAL_SECTION *)DAT_143c490f8);
  return;
}

// @0x1400501e0
void mpvmulti_unlock(void)
{
  CRICRS_Leave((_RTL_CRITICAL_SECTION *)DAT_143c490f8);
  return;
}

// @0x1400501f0
DWORD mpvmulti_GetNumberOfProcessors(void)
{
  _SYSTEM_INFO loc_38;
  
  GetSystemInfo(&loc_38);
  return loc_38.dwNumberOfProcessors;
}

// MS2-FUNCTIONAL: op-identical apart from register allocation (VS2008 build, our toolset differs).
// @0x140050210
void MPVMULTI_SetProcessorMask(longlong a1,uint a2)
{
  struct Ch { cri_u8 Reserved00[0xc]; cri_u32 Processor; cri_u8 Reserved10[0xf0]; };
  int last;
  int used;
  int count;
  ulonglong n;
  Ch *ch;
  uint bit;

  if (CriAt<uint>(a1, 0x10) != a2) {
    CriAt<uint>(a1, 0x10) = a2;
    last = mpvmulti_GetNumberOfProcessors() - 1;
    count = DAT_143badbdc;
    used = 0;
    bit = 0;
    // each channel takes the next processor in the mask, until all but one are taken
    if (count > 0) {
      ch = (Ch *)DAT_143c490e0;
      for (n = (cri_u32)count; n != 0; n--, ch++) {
        for (; bit < 0x20; bit++) {
          if ((a2 & (1u << bit)) != 0 && used < last) {
            used++;
            break;
          }
        }
        ch->Processor = bit;
        bit++;
      }
    }
  }
}

// @0x140050280
void FUN_140050280(longlong a1)
{
  CriAt<cri_u32>(a1, 0x14) = 1;
  mpvmulti_lock();
  CriAt<cri_u32>(a1, 0x88) = 0x96;
  mpvmulti_unlock();
  return;
}

// @0x1400502b0
int * mpvmulti_CreateMulti(void)
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

// @0x140050310
void MPVMULTI_Destroy(cri_u32 *a1)
{
  *a1 = 0;
  return;
}

// @0x140050320
longlong FUN_140050320(longlong a1,void *a2)
{
  SJCRS_Lock();
  memcpy((&CriAt<cri_u8>(a1, 0x188)),a2,0x68);
  memcpy((&CriAt<cri_u8>(a1, 0x208)),a2,0x68);
  SJCRS_Unlock();
  return a1 + 0x188;
}

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

// @0x1400503e0
cri_u32 FUN_1400503e0(longlong a1,void *a2,int *a3)
{
  struct Entry { int Id; cri_u8 Reserved04[0x7c]; };
  struct Obj { cri_u8 Reserved00[0x88]; int Next; cri_u8 Reserved8c[0x7c]; volatile int Count; volatile int Limit;
               cri_u8 Reserved110[0xf8]; cri_u8 Info[0x68]; cri_u8 Reserved270[0x18]; Entry Entries[1]; };
  Obj *o = (Obj *)a1;
  int i;
  cri_u32 result;

  mpvmulti_lock();
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
  mpvmulti_unlock();
  return result;
}

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

// @0x140050520
void MPVMULTI_Init(void)
{
  struct Work { cri_u64 Handle; cri_u64 Reserved08; cri_u8 Area[0xf0]; };
  struct Slot { cri_u32 State; cri_u32 Id; cri_u32 Reserved08; };
  int i;
  longlong h;
  
  DAT_143c49100 = DAT_143c49100 + 1;
  if ((DAT_143c49100 == 1) && (1 < (int)mpvmulti_GetNumberOfProcessors())) {
    DAT_143c490f8 = (cri_u64)CRICRS_Create((__int64)&DAT_143badb88,0x30);
    // the exe rounds both work areas up to 0x80 ((addr + 0x5f) & ~0x7f)
    DAT_143c490f0 = ((cri_u64)&DAT_143badf80 + 0x5f) & ~(cri_u64)0x7f;
    memset((void *)DAT_143c490f0,0,0x9b100);
    DAT_143c490e0 = ((cri_u64)&DAT_143badc00 + 0x5f) & ~(cri_u64)0x7f;
    memset((void *)DAT_143c490e0,0,0x300);
    DAT_143badbdc = 3;
    CRIDLG_Init();
    DAT_143badb84 = DAT_143badbdc;
    for (i = 0; i < DAT_143badbdc; i++) {
      // per-thread work area at entry + 0x10
      h = CRIDLG_Create((unsigned __int64)(((Work *)DAT_143c490e0)[i].Area),0x7c);
      ((Work *)DAT_143c490e0)[i].Handle = h;
      if (h == 0) {
        FUN_14004ff50(0,0xff030602);
        return;
      }
      ((Slot *)&DAT_143badbb8)[i].State = 0xffffffff;
      ((Slot *)&DAT_143badbb8)[i].Id = CRIDLG_GetPriority(h);
    }
  }
  return;
}

// @0x140050670
void MPVMULTI_Finish(void)
{
  struct Ch { longlong Handle; cri_u8 Reserved08[0xf8]; };
  longlong i;
  Ch *ch;

  DAT_143c49100 = DAT_143c49100 + -1;
  if (DAT_143c49100 == 0) {
    if ((int)mpvmulti_GetNumberOfProcessors() <= 1) {
      return;
    }
    if (DAT_143c490f8 != 0) {
      CRICRS_Destroy((_RTL_CRITICAL_SECTION *)DAT_143c490f8);
      DAT_143c490f8 = 0;
    }
    i = DAT_143badbdc - 1;
    if (i >= 0) {
      ch = (Ch *)DAT_143c490e0;
      do {
        if (ch[i].Handle != 0) {
          CRIDLG_Destroy(ch[i].Handle);
          ch = (Ch *)DAT_143c490e0;
          ch[i].Handle = 0;
        }
        i--;
      } while (i >= 0);
    }
    CRIDLG_Finish();
  }
  if (DAT_143c49100 < 0) {
    DAT_143c49100 = 0;
  }
}

// @0x140050730
longlong MPVMULTI_Create(void)
{
  int i_v1;
  longlong l_v2;
  
  i_v1 = mpvmulti_GetNumberOfProcessors();
  if (1 < i_v1) {
    l_v2 = (longlong)mpvmulti_CreateMulti();
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

// @0x140050770
void mpvmulti_DecServer(longlong *a1)
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

// MS2-FUNCTIONAL: register allocation differs (esi/edi, r14/r15), the chunk id is read from a3's home slot as a qword, and the last loop compares the count in memory (VS2008 build, our toolset differs).
// @0x140050820
cri_u64 MPVMULTI_DecPicture(longlong a1,cri_u64 a2,ulonglong a3,cri_u64 *a4)
{
  // One decoder thread: its handle, the thread id from CRIDLG_TryBeginInvoke, and its state.
  struct Worker { cri_u64 Handle; int Thread; cri_u32 State; cri_u8 Reserved10[0xf0]; };
  // The argument block handed to each mpvmulti_DecServer: the decoder and its work area.
  struct Arg { longlong Dec; longlong Work; };
  longlong *stream;
  int nthreads;
  int startPos;
  uint lastId;
  longlong n;
  longlong k;
  int i;
  Arg args[4];
  typedef int (*TellFn)(longlong *,int);
  
  nthreads = DAT_143badb84;
  CriAt<cri_u32>(a4, 0x20) = 0;
  CriAt<cri_u32>(a4, 0x24) = 0;
  CriAt<cri_u32>(a4, 0x1c) = 0;
  if ((CriAt<int>(a1, 0x10) == 0) || (CriAt<int>(a1, 0x10) == 0x5a5a5a5a)) {
    return 0;
  }
  CriAt<cri_u32>(a4, 0x1c) = 1;
  mpvmulti_SetDlgPara();
  CriAt<cri_u64>(a1, 0x8) = a4[1];
  CriAt<cri_u32>(a1, 0x88) = 0;
  CriAt<cri_u32>(a1, 0x108) = 0x96;
  CriAt<cri_u32>(a1, 0x10c) = 0;
  stream = (longlong *)FUN_140050320(a1,(void *)a2);
  startPos = (*(TellFn *)(*stream + 0x48))(stream,1);
  CriAt<cri_u16>(a4, 0x28) = 0;
  lastId = 0;
  for (;;) {
    if (CriAt<int>(a1, 0x14) != 0) {
      return 0;
    }
    // the chunk id lands in a3's home slot (the exe reuses the parameter)
    if ((FUN_140051ec0(stream,(uint *)&a3) & 1) == 0) break;
    CriAt<short>(a4, 0x28) = CriAt<short>(a4, 0x28) + 1;
    if (lastId != *(uint *)&a3) {
      lastId = *(uint *)&a3;
      if (FUN_140050380(a1,(cri_u64)stream,startPos - (*(TellFn *)(*stream + 0x48))(stream,1)) != 0) {
        CriAt<int>(a4, 0x20) = CriAt<int>(a4, 0x20) + 1;
        break;
      }
    }
    FUN_140052010(stream,1,4);
  }
  CriAt<cri_u32>(a1, 0x108) = CriAt<cri_u32>(a1, 0x10c);
  if (DAT_143badbdc < nthreads) {
    nthreads = DAT_143badbdc;
  }
  n = nthreads;
  if (0 < n) {
    Arg *slot = &args[1];
    longlong w = 0;
    Worker *tbl = (Worker *)DAT_143c490e0;
    i = 1;
    k = n;
    do {
      if (tbl[w].State < 0x20) {
        slot->Dec = a1;
        slot->Work = (*CriAt<code *>(CriAt<longlong>(a1, 0x8), 0x8))(*a4,i);
        int thread = CRIDLG_TryBeginInvoke(((Worker *)DAT_143c490e0)[w].Handle,(unsigned __int64)mpvmulti_DecServer,
                                   (unsigned __int64)&args[i]);
        tbl = (Worker *)DAT_143c490e0;
        tbl[w].Thread = thread;
      }
      else {
        slot->Work = 0;
        tbl[w].Thread = -1;
      }
      i++;
      slot++;
      w++;
    } while (--k != 0);
  }
  args[0].Dec = a1;
  args[0].Work = *a4;
  mpvmulti_DecServer((longlong *)args);
  if ((CriAt<int>(a1, 0x14) != 0) && (0 < n)) {
    for (k = 0; k < n; k++) {
      (**(code **)(CriAt<longlong>(a1, 0x8) + 0x10))(args[k + 1].Work);
    }
  }
  for (k = 0; k < n; k++) {
    if (((Worker *)DAT_143c490e0)[k].Thread >= 0) {
      CRIDLG_EndInvoke(((Worker *)DAT_143c490e0)[k].Handle,((Worker *)DAT_143c490e0)[k].Thread);
    }
  }
  FUN_140052050((longlong *)a2,1,startPos - (*(TellFn *)(*stream + 0x48))(stream,1));
  FUN_140050480(a1,CriAt<cri_u32>(a4, 0x14),*a4);
  for (i = 0; i < CriAt<int>(a1, 0x108); i++) {
    CriAt<int>(a4, 0x20) = CriAt<int>(a4, 0x20) + CriAt<int>(a1, 0x2b0 + i * 0x80);
    CriAt<int>(a4, 0x24) = CriAt<int>(a4, 0x24) + CriAt<int>(a1, 0x2b4 + i * 0x80);
  }
  return 0;
}

// @0x140050b30
cri_u32 MPV_SkipFrm(cri_u64 a1,cri_u64 *a2,int *a3)
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

// @0x140050bc0
void MPVFRM_Init(void)
{
  // The exe calls this from another obj, so the call stays even though it does nothing. The barrier emits no code; it
  // only stops VC9 from dropping the same-TU calls.
  _ReadWriteBarrier();
  return;
}

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
      return MPVM2V_DecodeFrm(a1,a2,a3);
    }
    i_v6 = CriAt<int>(a1, 0x162c);
    i_v3 = CriAt<int>(a1, 0x1630);
    memcpy((&CriAt<cri_u8>(a1, 0x1638)),a3,0x78);
    MPVUMC_InitOutRfb(a1);
    MPVCMC_InitMcOiRt(a1);
    MPVCMC_SetCcnt(a1);
    MPVCDEC_StartFrame(a1);
    MPVBDEC_StartFrame(a1);
    u_v7 = ((cri_u32 (*)(longlong,cri_u64))MPVSL_DecPicture)(a1,a2); // the exe uses only the low half of the cri_u64 result
    ((void (*)(longlong))MPVUMC_EndOfFrame)(a1);  // the exe still passes a1 to the void(void) definition
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

// @0x140050e90
void MPV_RequestStop(longlong a1)
{
  int i_v1;
  
  i_v1 = FUN_14004e0a0(a1);
  if (i_v1 != 0) {
    FUN_14004ff50(0,0xff030211);
    return;
  }
  CriAt<cri_u32>(a1, 0x18f0) = 1;
  if (CriAt<int>(a1, 0x17b8) == 2) {
    MPVM2V_RequestStop(a1);
  }
  if (CriAt<longlong>(a1, 0x18f8) != 0) {
    FUN_140050280(CriAt<longlong>(a1, 0x18f8));
  }
  return;
}

// @0x140050ef0
cri_u32 MPV_DecodeFrm(cri_u64 a1,cri_u64 *a2,int *a3,cri_u64 a4)
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
// @0x140050f80
void FUN_140050f80(void)
{
  DAT_143c492a0 = DAT_143c492a0 + 1;
}

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

// @0x140050fc0
void MPVHDEC_Init(void)
{
  FUN_140050f90(DAT_143c493a0,0x50);
  FUN_140050f90(DAT_143c491b0,0xa0);
  FUN_140050f90(DAT_143c49250,0x50);
  FUN_140050f90(DAT_143c492b0,0x50);
  FUN_140050f90(DAT_143c493f0,0x50);
  FUN_140050f90(DAT_143c49110,0x50);
  FUN_140050f90(DAT_143c49440,0xa0);
  FUN_140050f90(DAT_143c49350,0x50);
  FUN_140050f90(DAT_143c49300,0x50);
  FUN_140050f90(DAT_143c49160,0x50);
  _DAT_143c493a8 = cri_conv(MPVUMC_PpicSkipped);
  _DAT_143c493b8 = cri_conv(MPVUMC_BpicSkipped);
  _DAT_143c491b8 = cri_conv(&FUN_142ccc850);
  _DAT_143c491c0 = cri_conv(&FUN_142ccc850);
  _DAT_143c491c8 = cri_conv(&FUN_142ccc850);
  _DAT_143c491d0 = cri_conv(&FUN_142ccc850);
  _DAT_143c49208 = cri_conv(&FUN_142ccc850);
  _DAT_143c49210 = cri_conv(&FUN_142ccc850);
  _DAT_143c49218 = cri_conv(&FUN_142ccc850);
  _DAT_143c49220 = cri_conv(&FUN_142ccc850);
  _DAT_143c49260 = cri_conv(FUN_142ccca50);
  _DAT_143c49268 = cri_conv(FUN_142ccca50);
  _DAT_143c492c8 = cri_conv(FUN_142ccca90);
  _DAT_143c493b0 = cri_conv(MPVUMC_PpicSkipped);
  _DAT_143c49408 = cri_conv(MPVUMC_BiDirect);
  _DAT_143c49118 = cri_conv(MPVUMCT_PpicSkipped);
  _DAT_143c49120 = cri_conv(MPVUMCT_PpicSkipped);
  _DAT_143c49128 = cri_conv(MPVUMCT_BpicSkipped);
  _DAT_143c49448 = cri_conv(MPVUMCT_Intra);
  _DAT_143c49450 = cri_conv(MPVUMCT_Intra);
  _DAT_143c49458 = cri_conv(MPVUMCT_Intra);
  _DAT_143c49460 = cri_conv(MPVUMCT_Intra);
  _DAT_143c49498 = cri_conv(MPVUMCT_Intra);
  _DAT_143c494a0 = cri_conv(MPVUMCT_Intra);
  _DAT_143c494a8 = cri_conv(MPVUMCT_Intra);
  _DAT_143c494b0 = cri_conv(MPVUMCT_Intra);
  _DAT_143c49360 = cri_conv(FUN_140068db0);
  _DAT_143c49368 = cri_conv(FUN_140068db0);
  _DAT_143c49318 = cri_conv(FUN_140068e70);
  _DAT_143c49178 = cri_conv(MPVUMCT_BiDirect);
  return;
}

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

// @0x1400511f0
void MPV_GetPicUsr(longlong a1,cri_u64 *a2,cri_u32 *a3)
{
  if (a2 != (cri_u64 *)0x0) {
    *a2 = CriAt<cri_u64>(a1, 0x18b8);
  }
  if (a3 != (cri_u32 *)0x0) {
    *a3 = CriAt<cri_u32>(a1, 0x18c4);
  }
  return;
}

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
      l_v3 = l_v3 + 4;
      l_v3 = FUN_1400530c0(l_v3,(*a2 - (int)l_v3) + a2[2],0xffffffff);
      if (l_v3 != 0) {
        u_v2 = FUN_140053000(l_v3);
        if ((u_v2 & 0x10) != 0) {
          CriAt<cri_u32>(a1, 0x17b8) = 2;
        }
        else if (u_v2 != 0) {
          CriAt<cri_u32>(a1, 0x17b8) = 1;
        }
      }
    }
    i_v1 = CriAt<int>(a1, 0x17b8);
  }
  return i_v1;
}

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

// @0x140051330
void FUN_140051330(longlong a1)
{
  int i_v1;
  
  i_v1 = CriAt<int>(a1, 0x156c);
  if (i_v1 == 0) {
    i_v1 = 1;
  }
  UTY_MemcpyDword((char *)a1 + 0xc00,*(const void **)(&DAT_143d749a0 + (longlong)i_v1 * 8),0x10);
  return;
}

// @0x140051360
void FUN_140051360(longlong a1)
{
  UTY_MemsetDword(a1 + 0xc40,0x10101010,0x10);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// Big-endian 32-bit word from four stream bytes; the top byte goes through movsx as in the exe.
#define CRI05B_BE32(a, b, c, d) ((((((int)(signed char)(a) << 8) | (b)) << 8 | (c)) << 8) | (d))
// @0x140051380
cri_u64 FUN_140051380(longlong a1,longlong *a2)
{
  int pos;
  uint low;
  uint next;
  uint tc;
  cri_u8 *cur;
  struct Chunk { cri_u8 *Data; cri_u32 Size; } loc_18;
  
  CriAt<cri_u32>(a1, 0x1850) = 2;
  CriAt<int>(a1, 0x15c8)++;
  CriAt<cri_u32>(a1, 0x18e4) = 0;
  CriAt<cri_u32>(a1, 0x18e8) = 0;
  CriAt<cri_u32>(a1, 0x1600) = 0;
  (**(code **)(*a2 + 0x30))(a2,1,0x7fffffff,a1 + 0x1800);
  // The GOP start code (00 00 01 b8) sits in the first word; low/next are the bit window after it.
  cur = (cri_u8 *)(CriAt<ulonglong>(a1, 0x1800) & 0xfffffffffffffffc);
  pos = (int)((uint)CriAt<ulonglong>(a1, 0x1800) << 3);
  pos -= (int)((uint)(ulonglong)cur << 3);
  low = CRI05B_BE32(cur[4],cur[5],cur[6],cur[7]);
  if (pos != 0) {
    low <<= pos;
  }
  next = CRI05B_BE32(cur[8],cur[9],cur[10],cur[11]);
  cur += 0xc;
  // time_code (25 bits)
  if (pos >= 7) {
    pos -= 7;
    if (pos != 0) {
      tc = (next >> (0x19 - pos) | low) >> 7;
      low = next << pos;
    }
    else {
      tc = low >> 7;
      low = next;
    }
    next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
    cur += 4;
  }
  else {
    pos += 0x19;
    tc = low >> 7;
    low <<= 0x19;
  }
  CriAt<uint>(a1, 0x15c4) = tc & 0x3f;
  tc >>= 6;
  CriAt<uint>(a1, 0x15c0) = tc & 0x3f;
  tc >>= 7;
  CriAt<uint>(a1, 0x15bc) = tc & 0x3f;
  tc >>= 6;
  CriAt<uint>(a1, 0x15b8) = tc & 0x1f;
  CriAt<uint>(a1, 0x15b4) = tc >> 5;
  // closed_gop, broken_link (1 bit each)
  CriAt<uint>(a1, 0x16e0) = (uint)((int)low < 0);
  if (pos == 0x1f) {
    pos = 0;
    low = next;
    cur += 4;
  }
  else {
    pos += 1;
    low <<= 1;
  }
  CriAt<uint>(a1, 0x16e4) = (uint)((int)low < 0);
  if (pos == 0x1f) {
    pos = 0;
    cur += 4;
  }
  else {
    pos += 1;
  }
  SJ_SplitChunk(&CriAt<__int64>(a1, 0x1800),(int)(cur + (pos + 7 >> 3) - 8 - CriAt<cri_u8 *>(a1, 0x1800)),
                &CriAt<__int64>(a1, 0x1800),(__int64 *)&loc_18);
  (**(code **)(*a2 + 0x40))(a2,0,a1 + 0x1800);
  (**(code **)(*a2 + 0x38))(a2,1,&loc_18);
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x1400515c0
cri_u64 FUN_1400515c0(longlong a1,longlong *a2)
{
  int pos;
  int type;
  int fcode;
  uint low;
  uint next;
  uint val;
  longlong row;
  longlong col;
  longlong sel;
  cri_u64 tab;
  cri_u32 ret;
  cri_u8 *cur;
  struct Chunk { cri_u8 *Data; cri_u32 Size; } loc_28;
  
  CriAt<cri_u32>(a1, 0x1850) = 3;
  (**(code **)(*a2 + 0x30))(a2,1,0x7fffffff,a1 + 0x1800);
  // The picture start code (00 00 01 00) sits in the first word; low/next are the bit window after it.
  cur = (cri_u8 *)(CriAt<ulonglong>(a1, 0x1800) & 0xfffffffffffffffc);
  pos = (int)((uint)CriAt<ulonglong>(a1, 0x1800) << 3);
  pos -= (int)((uint)(ulonglong)cur << 3);
  low = CRI05B_BE32(cur[4],cur[5],cur[6],cur[7]);
  if (pos != 0) {
    low <<= pos;
  }
  next = CRI05B_BE32(cur[8],cur[9],cur[10],cur[11]);
  cur += 0xc;
  // temporal_reference (10 bits)
  if (pos >= 0x16) {
    pos -= 0x16;
    if (pos != 0) {
      CriAt<uint>(a1, 0x15ac) = (next >> (10 - pos) | low) >> 0x16;
      low = next << pos;
    }
    else {
      CriAt<uint>(a1, 0x15ac) = low >> 0x16;
      low = next;
    }
    next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
    cur += 4;
  }
  else {
    pos += 10;
    CriAt<uint>(a1, 0x15ac) = low >> 0x16;
    low <<= 10;
  }
  // picture_coding_type (3 bits)
  if (pos >= 0x1d) {
    pos -= 0x1d;
    if (pos != 0) {
      CriAt<uint>(a1, 0x15b0) = (next >> (3 - pos) | low) >> 0x1d;
      low = next << pos;
    }
    else {
      CriAt<uint>(a1, 0x15b0) = low >> 0x1d;
      low = next;
    }
    next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
    cur += 4;
  }
  else {
    pos += 3;
    CriAt<uint>(a1, 0x15b0) = low >> 0x1d;
    low <<= 3;
  }
  // vbv_delay (16 bits)
  if (pos >= 0x10) {
    pos -= 0x10;
    if (pos != 0) {
      CriAt<uint>(a1, 0x16e8) = (next >> (0x10 - pos) | low) >> 0x10;
      low = next << pos;
    }
    else {
      CriAt<uint>(a1, 0x16e8) = low >> 0x10;
      low = next;
    }
    next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
    cur += 4;
  }
  else {
    pos += 0x10;
    CriAt<uint>(a1, 0x16e8) = low >> 0x10;
    low <<= 0x10;
  }
  type = CriAt<int>(a1, 0x15b0);
  if (type == 1 || type == 2) {
    CriAt<int>(a1, 0x18e4)++;
    CriAt<cri_u32>(a1, 0x18e8) = 0;
    val = CriAt<int>(a1, 0x18e4) << 0x10;
  }
  else {
    CriAt<int>(a1, 0x18e8)++;
    val = (CriAt<int>(a1, 0x18e4) - 1) << 0x10 | CriAt<uint>(a1, 0x18e8);
  }
  CriAt<uint>(a1, 0x1600) = val;
  if (type == 2 || type == 3) {
    // full_pel_forward_vector (1 bit)
    CriAt<uint>(a1, 0x174c) = (uint)((int)low < 0);
    if (pos == 0x1f) {
      pos = 0;
      low = next;
      next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
      cur += 4;
    }
    else {
      pos += 1;
      low <<= 1;
    }
    // forward_f_code (3 bits)
    if (pos >= 0x1d) {
      pos -= 0x1d;
      if (pos != 0) {
        val = (next >> (3 - pos) | low) >> 0x1d;
        low = next << pos;
      }
      else {
        val = low >> 0x1d;
        low = next;
      }
      next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
      cur += 4;
    }
    else {
      pos += 3;
      val = low >> 0x1d;
      low <<= 3;
    }
    fcode = val - 1;
    CriAt<int>(a1, 0x1750) = fcode;
    CriAt<int>(a1, 0x1754) = 0x1b - fcode;
    CriAt<int>(a1, 0x1758) = 1 << fcode;
    if (type == 3) {
      // full_pel_backward_vector (1 bit)
      CriAt<uint>(a1, 0x1770) = (uint)((int)low < 0);
      if (pos == 0x1f) {
        pos = 0;
        low = next;
        next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
        cur += 4;
      }
      else {
        pos += 1;
        low <<= 1;
      }
      // backward_f_code (3 bits)
      if (pos >= 0x1d) {
        pos -= 0x1d;
        if (pos != 0) {
          val = (next >> (3 - pos) | low) >> 0x1d;
          low = next << pos;
        }
        else {
          val = low >> 0x1d;
          low = next;
        }
        next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
        cur += 4;
      }
      else {
        pos += 3;
        val = low >> 0x1d;
        low <<= 3;
      }
      fcode = val - 1;
      CriAt<int>(a1, 0x1774) = fcode;
      CriAt<int>(a1, 0x1778) = 0x1b - fcode;
      CriAt<int>(a1, 0x177c) = 1 << fcode;
    }
  }
  row = (longlong)type;
  sel = (longlong)(int)(uint)(CriAt<int>(a1, 0x1558) != 3);
  CriAt<cri_u64>(a1, 0x16f0) = DAT_1431ba7c8[row];
  col = row + sel * 5;
  sel = sel + (longlong)CriAt<int>(a1, 0x1550) * 2;
  if (CriAt<int>(a1, 0x1568) == 0) {
    CriAt<cri_u64>(a1, 0x16f8) = DAT_143c493a0[col];
    CriAt<cri_u64>(a1, 0x1710) = DAT_143c491b0[row + sel * 5];
    CriAt<cri_u64>(a1, 0x1720) = DAT_143c492b0[col];
    CriAt<cri_u64>(a1, 0x1728) = DAT_143c49250[col];
    tab = DAT_143c493f0[col];
  }
  else {
    CriAt<cri_u64>(a1, 0x16f8) = DAT_143c49110[col];
    CriAt<cri_u64>(a1, 0x1710) = DAT_143c49440[row + sel * 5];
    CriAt<cri_u64>(a1, 0x1720) = DAT_143c49300[col];
    CriAt<cri_u64>(a1, 0x1728) = DAT_143c49350[col];
    tab = DAT_143c49160[col];
  }
  CriAt<cri_u64>(a1, 0x1730) = tab;
  CriAt<cri_u64>(a1, 0x1718) = CriAt<cri_u64>(a1, 0x1728);
  // extra_bit_picture (1 bit) + extra_information_picture (8 bits) while the flag is set
  while ((int)low < 0) {
    pos += 9;
    if (pos >= 0x20) {
      pos -= 0x20;
      low = next << pos;
      next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
      cur += 4;
    }
    else {
      low <<= 9;
    }
    if (CriAt<int>(a1, 0x1808) <= (int)(cur + (pos + 7 >> 3) - 8 - CriAt<cri_u8 *>(a1, 0x1800))) {
      ret = 0xfffffffd;
      goto done;
    }
  }
  pos += 1;
  if (pos >= 0x20) {
    pos -= 0x20;
    cur += 4;
  }
  SJ_SplitChunk(&CriAt<__int64>(a1, 0x1800),(int)(cur + (pos + 7 >> 3) - 8 - CriAt<cri_u8 *>(a1, 0x1800)),
                &CriAt<__int64>(a1, 0x1800),(__int64 *)&loc_28);
  (**(code **)(*a2 + 0x40))(a2,0,a1 + 0x1800);
  (**(code **)(*a2 + 0x38))(a2,1,&loc_28);
  ret = 0;
done:
  return ret;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140051c10
cri_u32 FUN_140051c10(longlong a1,longlong a2,int a3)
{
  int i_v1;
  int i_v2;
  char *_Str1;
  char *base = (char *)a2 + 4;
  int count = a3 - 4;
  cri_u32 u_v3;

  i_v2 = 0;
  if (0 < count) {
    do {
      _Str1 = base + i_v2;
      i_v1 = strncmp(_Str1,"IDCPREC",7);
      if (i_v1 == 0) {
        CriAt<uint>(a1, 0x1814) = atoi(_Str1 + 0x10) ? 3 : 0;
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
    } while ((i_v1 == 0) && (i_v2 = i_v2 + 1, i_v2 < count));
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
void MPVHDEC_GoNextDelim(longlong *a1,int *a2,int *a3)
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
    ((void (*)(void *,cri_u64,void *,void *))SJ_SplitChunk)((void *)&buf,(cri_u32)(*(volatile int *)&buf.Len + -3),(void *)&buf,(void *)&info);  // the exe zero-extends the length to 64 bits
    (**(code **)(*a1 + 0x40))(a1,0,&buf);
    (**(code **)(*a1 + 0x38))(a1,1,&info);
    (**(code **)(*a1 + 0x30))(a1,1,0x7fffffff,&buf);
  }
  result = FUN_140053000(found);
  SJ_SplitChunk((__int64 *)((void *)&buf),(cri_u32)((int)found - (int)buf.Ptr),(__int64 *)((void *)&buf),(__int64 *)((void *)&info));
  (**(code **)(*a1 + 0x40))(a1,0,&buf);
  (**(code **)(*a1 + 0x38))(a1,1,&info);
  return result;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor code (VS2008 build, our toolset differs).
// @0x140051ec0
cri_u32 FUN_140051ec0(longlong *a1,uint *a2)
{
  // An SJ chunk: data pointer and byte count (16 bytes with padding).
  struct Chunk { cri_u8 *Data; int Size; int Pad; };
  cri_u32 u_v1;
  longlong l_v2;
  Chunk loc_28;
  Chunk loc_18;
  
  (**(code **)(*a1 + 0x30))(a1,1,0x7fffffff,&loc_28);
  while( true ) {
    if (loc_28.Size < 4) {
      (**(code **)(*a1 + 0x38))(a1,1,&loc_28);
      *a2 = 0;
      return 0;
    }
    l_v2 = FUN_1400530c0((longlong)loc_28.Data,loc_28.Size,0xffffffff);
    if (l_v2 != 0) break;
    SJ_SplitChunk((__int64 *)&loc_28,loc_28.Size + -3,(__int64 *)&loc_28,(__int64 *)&loc_18);
    (**(code **)(*a1 + 0x40))(a1,0,&loc_28);
    (**(code **)(*a1 + 0x38))(a1,1,&loc_18);
    (**(code **)(*a1 + 0x30))(a1,1,0x7fffffff,&loc_28);
  }
  *a2 = CriAt<byte>(l_v2, 0x3) | 0x100;
  u_v1 = FUN_140053000(l_v2);
  SJ_SplitChunk((__int64 *)&loc_28,(int)l_v2 - (int)(longlong)loc_28.Data,(__int64 *)&loc_28,(__int64 *)&loc_18);
  (**(code **)(*a1 + 0x40))(a1,0,&loc_28);
  (**(code **)(*a1 + 0x38))(a1,1,&loc_18);
  return u_v1;
}

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
  int pos;
  int flag;
  uint low;
  uint next;
  uint val;
  longlong i;
  cri_u8 *cur;
  struct Chunk { cri_u8 *Data; cri_u32 Size; } loc_38;
  
  i = 0;
  CriAt<cri_u32>(a1, 0x17bc) = 0;
  CriAt<cri_u32>(a1, 0x1814) = 0;
  CriAt<cri_u32>(a1, 0x1850) = 1;
  FUN_140051300(a1);
  CriAt<int>(a1, 0x15cc)++;
  CriAt<cri_u32>(a1, 0x18e4) = 0;
  CriAt<cri_u32>(a1, 0x18e8) = 0;
  CriAt<cri_u32>(a1, 0x1600) = 0;
  (**(code **)(*a2 + 0x30))(a2,1,0x7fffffff,a1 + 0x1800);
  // The sequence start code (00 00 01 b3) sits in the first word; low/next are the bit window after it.
  cur = (cri_u8 *)(CriAt<ulonglong>(a1, 0x1800) & 0xfffffffffffffffc);
  pos = (int)((uint)CriAt<ulonglong>(a1, 0x1800) << 3);
  pos -= (int)((uint)(ulonglong)cur << 3);
  low = CRI05B_BE32(cur[4],cur[5],cur[6],cur[7]);
  if (pos != 0) {
    low <<= pos;
  }
  next = CRI05B_BE32(cur[8],cur[9],cur[10],cur[11]);
  cur += 0xc;
  // horizontal_size (12 bits)
  if (pos >= 0x14) {
    pos -= 0x14;
    if (pos != 0) {
      CriAt<uint>(a1, 0x1598) = (next >> (0xc - pos) | low) >> 0x14;
      low = next << pos;
    }
    else {
      CriAt<uint>(a1, 0x1598) = low >> 0x14;
      low = next;
    }
    next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
    cur += 4;
  }
  else {
    pos += 0xc;
    CriAt<uint>(a1, 0x1598) = low >> 0x14;
    low <<= 0xc;
  }
  // vertical_size (12 bits)
  if (pos >= 0x14) {
    pos -= 0x14;
    if (pos != 0) {
      CriAt<uint>(a1, 0x159c) = (next >> (0xc - pos) | low) >> 0x14;
      low = next << pos;
    }
    else {
      CriAt<uint>(a1, 0x159c) = low >> 0x14;
      low = next;
    }
    next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
    cur += 4;
  }
  else {
    pos += 0xc;
    CriAt<uint>(a1, 0x159c) = low >> 0x14;
    low <<= 0xc;
  }
  // aspect_ratio_information (4 bits)
  if (pos >= 0x1c) {
    pos -= 0x1c;
    if (pos != 0) {
      CriAt<uint>(a1, 0x16d0) = (next >> (4 - pos) | low) >> 0x1c;
      low = next << pos;
    }
    else {
      CriAt<uint>(a1, 0x16d0) = low >> 0x1c;
      low = next;
    }
    next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
    cur += 4;
  }
  else {
    pos += 4;
    CriAt<uint>(a1, 0x16d0) = low >> 0x1c;
    low <<= 4;
  }
  // frame_rate_code (4 bits)
  if (pos >= 0x1c) {
    pos -= 0x1c;
    if (pos != 0) {
      val = (next >> (4 - pos) | low) >> 0x1c;
      low = next << pos;
    }
    else {
      val = low >> 0x1c;
      low = next;
    }
    next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
    cur += 4;
  }
  else {
    val = low >> 0x1c;
    pos += 4;
    low <<= 4;
  }
  CriAt<uint>(a1, 0x15a8) = val;
  // bit_rate_value (18 bits)
  if (pos >= 0xe) {
    pos -= 0xe;
    if (pos != 0) {
      CriAt<uint>(a1, 0x16d4) = (next >> (0x12 - pos) | low) >> 0xe;
      low = next << pos;
    }
    else {
      CriAt<uint>(a1, 0x16d4) = low >> 0xe;
      low = next;
    }
    next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
    cur += 4;
  }
  else {
    pos += 0x12;
    CriAt<uint>(a1, 0x16d4) = low >> 0xe;
    low <<= 0x12;
  }
  // marker_bit
  pos += 1;
  if (pos >= 0x20) {
    pos -= 0x20;
    low = next << pos;
    next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
    cur += 4;
  }
  else {
    low <<= 1;
  }
  // vbv_buffer_size_value (10 bits)
  if (pos >= 0x16) {
    pos -= 0x16;
    if (pos != 0) {
      CriAt<uint>(a1, 0x16d8) = (next >> (10 - pos) | low) >> 0x16;
      low = next << pos;
    }
    else {
      CriAt<uint>(a1, 0x16d8) = low >> 0x16;
      low = next;
    }
    next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
    cur += 4;
  }
  else {
    pos += 10;
    CriAt<uint>(a1, 0x16d8) = low >> 0x16;
    low <<= 10;
  }
  // constrained_parameters_flag
  CriAt<uint>(a1, 0x16dc) = (uint)((int)low < 0);
  if (pos == 0x1f) {
    pos = 0;
    low = next;
    next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
    cur += 4;
  }
  else {
    pos += 1;
    low <<= 1;
  }
  // load_intra_quantiser_matrix
  flag = (int)low < 0;
  if (pos == 0x1f) {
    pos = 0;
    low = next;
    next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
    cur += 4;
  }
  else {
    pos += 1;
    low <<= 1;
  }
  if (flag) {
    longlong k = i;
    do {
      if (pos >= 0x18) {
        pos -= 0x18;
        if (pos != 0) {
          val = (next >> (8 - pos) | low) >> 0x18;
          low = next << pos;
        }
        else {
          val = low >> 0x18;
          low = next;
        }
        next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
        cur += 4;
      }
      else {
        val = low >> 0x18;
        pos += 8;
        low <<= 8;
      }
      k++;
      CriAt<char>(a1, 0xc00 + (longlong)*(k + CriAt<signed char *>(a1, 0x12d0) - 1)) = (char)val;
    } while (k < 0x40);
  }
  else {
    FUN_140051330(a1);
  }
  // load_non_intra_quantiser_matrix
  flag = (int)low < 0;
  if (pos == 0x1f) {
    pos = 0;
    low = next;
    next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
    cur += 4;
  }
  else {
    pos += 1;
    low <<= 1;
  }
  if (flag) {
    do {
      if (pos >= 0x18) {
        pos -= 0x18;
        if (pos != 0) {
          val = (next >> (8 - pos) | low) >> 0x18;
          low = next << pos;
        }
        else {
          val = low >> 0x18;
          low = next;
        }
        next = CRI05B_BE32(cur[0],cur[1],cur[2],cur[3]);
        cur += 4;
      }
      else {
        val = low >> 0x18;
        pos += 8;
        low <<= 8;
      }
      i++;
      CriAt<char>(a1, 0xc40 + (longlong)*(i + CriAt<signed char *>(a1, 0x12d0) - 1)) = (char)val;
    } while (i < 0x40);
  }
  else {
    FUN_140051360(a1);
  }
  CriAt<int>(a1, 0x15a4) = CriAt<int>(a1, 0x159c) + 0xf >> 4;
  CriAt<int>(a1, 0x15a0) = CriAt<int>(a1, 0x1598) + 0xf >> 4;
  CriAt<int>(a1, 0x17a0) = CriAt<int>(a1, 0x15a4) * CriAt<int>(a1, 0x15a0) - 1;
  CriAt<cri_u32>(a1, 0x15e0) = CriAt<cri_u32>(a1, 0x16d4);
  CriAt<cri_u32>(a1, 0x15e4) = CriAt<cri_u32>(a1, 0x16d8);
  CriAt<cri_u8>(a1, 0x15f1) = CriAt<cri_u8>(a1, 0x16d0);
  CriAt<cri_u8>(a1, 0x15f2) = CriAt<cri_u8>(a1, 0x16dc);
  SJ_SplitChunk(&CriAt<__int64>(a1, 0x1800),(int)(cur + (pos + 7 >> 3) - 8 - CriAt<cri_u8 *>(a1, 0x1800)),
                &CriAt<__int64>(a1, 0x1800),(__int64 *)&loc_38);
  (**(code **)(*a2 + 0x40))(a2,0,a1 + 0x1800);
  (**(code **)(*a2 + 0x38))(a2,1,&loc_38);
  return 0;
}

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
  SJ_SplitChunk((__int64 *)cur,(cri_u32)(((bits + 7) >> 3) - *(int *)cur + 4 + (int)aligned),(__int64 *)cur,(__int64 *)((void *)&info));
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
  struct Chunk { void *Data; int Size; } frame_[2];
  void * &loc_48 = frame_[0].Data;
  int &loc_40 = frame_[0].Size;
  void * &loc_38 = frame_[1].Data;
  int &loc_30 = frame_[1].Size;
  
  i_v5 = CriAt<int>(a1, 0x1850);
  l_v7 = (longlong)i_v5;
  int end = a3 + -3;
  i_v6 = 4;
  i_v4 = 0;
  if (4 < end) {
    do {
      i_v3 = FUN_140053000((longlong)i_v6 + (longlong)a2);
      if (i_v3 != 0) break;
      i_v6 = i_v6 + 1;
    } while (i_v6 < end);
  }
  i_v3 = 0;
  if (i_v6 == end) {
    i_v3 = -1;
  }
  if (i_v5 == 1) {
    i_v4 = FUN_140051c10(a1,(longlong)a2,i_v6);
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
  SJ_SplitChunk(cur,(cri_u32)(((bits + 7) >> 3) - *(int *)cur + 4 + (int)aligned),cur,(__int64 *)((void *)&info));
  (**(code **)(*a2 + 0x40))(a2,0,cur);
  (**(code **)(*a2 + 0x38))(a2,1,&info);
  FUN_140051d90(a2);
  return result;
}

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
    return MPVM2V_DecodePicAtr(a1,a2);
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

// @0x140052c80
cri_u32 MPV_DecodePicAtr(cri_u64 a1,cri_u64 *a2,int *a3)
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

// @0x140052d00
cri_u32 MPV_GetPicAtr(longlong a1,int *a2)
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

// @0x140052da0
cri_u32 MPV_GetBitRate(longlong a1,cri_u32 *a2)
{
  if (FUN_14004e0a0(a1) != 0) {
    return FUN_14004ff50(0,0xff03020d);
  }
  *a2 = (*(cri_u32*)((char*)(a1) + 0x16d4));
  return 0;
}

// @0x140052df0
cri_u32 MPV_GetVbvBufSiz(longlong a1,int *a2,cri_u32 *a3,int *a4)
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

// @0x140052e90
cri_u32 MPV_GetLinkFlg(longlong a1,cri_u32 *a2,cri_u32 *a3)
{
  if (FUN_14004e0a0(a1) != 0) {
    return FUN_14004ff50(0,0xff03020e);
  }
  *a2 = CriAt<cri_u32>(a1, 0x16e0);
  *a3 = CriAt<cri_u32>(a1, 0x16e4);
  return 0;
}

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

int MPVDELI_Init(void);

long FUN_140053000(cri_u8 *a1);

longlong FUN_140053030(longlong a1,int a2,int a3);

longlong FUN_1400530c0(longlong a1,int a2,int a3);

longlong FUN_140053140(byte *a1,longlong a2,int a3,int a4);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
cri_u32 FUN_1400531e0(longlong a1,cri_u64 a2,cri_u64 a3,cri_u32 *a4);

long FUN_140053260(longlong a1,cri_u64 a2,cri_u64 a3,cri_u64 a4, cri_u32 *a5);
#pragma optimize("", on)

void criAdec_Initialize(void);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void criAdec_Finalize(void);

int FUN_1400532e0(int a1);

#pragma function(memset)                      // the exe calls memset here rather than expanding it
extern "C" cri_u64 * criAdec_Create(cri_u64 a1,uint a2,cri_u32 a3);
#pragma intrinsic(memset)

void FUN_140053470(cri_u64 *a1);

extern "C" void FUN_1400534d0(void* a1);

extern "C" void criAdec_SetInputSj(longlong a1,cri_u64 a2);

extern "C" void criAdec_SetOutputSj(longlong a1,uint a2,cri_u64 a3);

void FUN_140053540(longlong a1);

void FUN_140053570(longlong a1);

void FUN_1400535b0(longlong a1,int *a2);

long FUN_140053630(void* a1);

cri_u64 criAadx_Execute(longlong a1);

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

void FUN_1400536d0(longlong a1);

void FUN_140053880(longlong a1);

void criAdec_TerminateSupply(longlong a1);

#pragma function(memset)                      // the exe calls memset here rather than expanding it
void criAadx_InsertDummyHeader(void* a1, unsigned long a2, unsigned long a3, unsigned long a4);
#pragma intrinsic(memset)

void FUN_140054040(longlong a1,cri_u64 a2,cri_u64 a3);
#pragma optimize("", on)

void m2vidct_InitIdctTbls(void);

void FUN_1400540d0(void);

void FUN_140054100(char *ctx);

