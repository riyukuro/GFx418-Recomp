// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): CRI MvCore / Sofdec vendor middleware, the IDCT obj at
// 0x14006aa60-0x14006b0d0 (the DC rounding hook, an empty init function and the 8x8 IDCT). In the exe it is its own obj
// inside sfr_cri_07's range: mpvcdec_InitDct in 07 still calls the empty DCT_Isse2Init, a call VC9 drops for an empty
// function in the same TU. Written from the executable. The CRI library was built with VS2008 SP1, and so is this unit
// (MS2-TOOLSET: vc9, cmake/ms2-unit-profiles.cmake): keep it C++03 (no auto, decltype, variadic templates, brace-init or
// nullptr). Every function is a behaviour-equivalent transcription.
// MS2-UNIT: sfr_cri_07c
// MS2-TOOLSET: vc9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14006aa60-0x14006b0d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/cri/cri_vendor_shim.h"
// The exe reads some data_cri tables with a plain lea; only clang needs the launder, so it cannot bound the access by
// the scalar declaration.
#if defined(__clang__)
#define CRI_FILL_ADDR(x) CRI_ADDR(x)
#else
#define CRI_FILL_ADDR(x) (&(x))
#endif
extern "C" V16 _DAT_143a4a420;
extern "C" V16 _DAT_143a4a490;
extern "C" const char* _DAT_143d4ef20;
extern "C" const char* _DAT_143d4ef38;
extern "C" const char* _DAT_143d4ef40;
extern "C" const char* _DAT_143d67f58;
extern "C" const char* _DAT_143d683c8;
extern "C" const char* _DAT_143d68ac0;
extern "C" cri_code* DAT_143d67f60;
extern "C" cri_code* DAT_143d68390;
extern "C" cri_code* DAT_143d68398;
extern "C" cri_code* DAT_143d683a8;
extern "C" cri_code* DAT_143d683b8;
extern "C" cri_code* DAT_143d68850;
extern "C" cri_code* DAT_143d68860;
extern "C" cri_u1 DAT_143d4ee20;
extern "C" cri_u1 DAT_143d4ee60;

void DCT_FsriTransCore(cri_any = cri_any(), cri_any = cri_any());
void FUN_140065fc0(char *ctx, int mask);
uint FUN_14004ff50(longlong a1, uint a2);
extern "C" cri_u1* PTR_FUN_143a4a5a0;
extern "C" cri_u1* PTR_LAB_1431bbd20[];
extern "C" cri_u1* PTR_LAB_1431bc290[];
extern "C" cri_u1* PTR_LAB_1431bc450[];
extern "C" cri_u4 DAT_143d74940;
extern "C" int DAT_1431bbd60;
extern "C" int DAT_1431bbd80;
extern "C" int DAT_1431bbdc1;
extern "C" unsigned char DAT_1431bc310;
extern "C" unsigned char DAT_1431bc350;
extern "C" int DAT_1431bc3b8;
extern "C" unsigned char DAT_1431bc3e8;
extern "C" unsigned short DAT_1431bc3f8;
extern "C" unsigned char DAT_1431bc410;
extern "C" unsigned char DAT_1431bc440;
extern "C" unsigned char DAT_143a4a120;
extern "C" unsigned long long DAT_143a4a5e8;
extern "C" double DAT_143d4abf0;
extern "C" unsigned char DAT_143d4adf0;
extern "C" unsigned char DAT_143d4edf0;
extern "C" longlong DAT_143d4ee10;
extern "C" int DAT_143d4eea8;
extern "C" volatile int DAT_143d4eee8;      // the exe re-reads it after each inc/dec: volatile
extern "C" int DAT_143d4eef0;
extern "C" int DAT_143d4ef30;
extern "C" unsigned char DAT_143d4ef50;
extern "C" unsigned int DAT_143d4fb50;
extern "C" unsigned int DAT_143d4ff50;
extern "C" unsigned char DAT_143d50350;
extern "C" unsigned char DAT_143d50f50;
extern "C" unsigned char DAT_143d51b50;
extern "C" unsigned char DAT_143d52750;
extern "C" unsigned int DAT_143d53350;
extern "C" unsigned char DAT_143d53750;
extern "C" unsigned char DAT_143d54350;
extern "C" unsigned char DAT_143d54f50;
extern "C" unsigned char DAT_143d55b50;
extern "C" unsigned char DAT_143d56750;
extern "C" unsigned char DAT_143d57350;
extern "C" unsigned char DAT_143d57f50;
extern "C" unsigned char DAT_143d58b50;
extern "C" int DAT_143d59750;
extern "C" unsigned int DAT_143d59b50;
extern "C" unsigned char DAT_143d59f50;
extern "C" unsigned char DAT_143d5ab50;
extern "C" unsigned char DAT_143d5b750;
extern "C" unsigned int DAT_143d5c350;
extern "C" unsigned int DAT_143d5c750;
extern "C" unsigned char DAT_143d5cb50;
extern "C" unsigned char DAT_143d5d750;
extern "C" unsigned char DAT_143d5e350;
extern "C" unsigned char DAT_143d5ef50;
extern "C" unsigned int DAT_143d5fb50;
extern "C" unsigned char DAT_143d5ff50;
extern "C" unsigned char DAT_143d60b50;
extern "C" unsigned char DAT_143d61750;
extern "C" unsigned char DAT_143d62350;
extern "C" unsigned char DAT_143d62f50;
extern "C" unsigned char DAT_143d63b50;
extern "C" unsigned char DAT_143d64750;
extern "C" unsigned char DAT_143d65350;
extern "C" int DAT_143d65f50;
extern "C" unsigned int DAT_143d66350;
extern "C" unsigned char DAT_143d66750;
extern "C" unsigned char DAT_143d67350;
extern "C" int DAT_143d67f50;
extern "C" longlong DAT_143d67f68;
extern "C" int DAT_143d67f90;
extern "C" int DAT_143d68190;
extern "C" longlong DAT_143d683a0;
extern "C" longlong DAT_143d683b0;
extern "C" longlong DAT_143d683c0;
extern "C" unsigned char DAT_143d683d0;
extern "C" unsigned char DAT_143d683d8;
extern "C" unsigned char DAT_143d683e0;
extern "C" longlong DAT_143d68858;
extern "C" longlong DAT_143d68868;
extern "C" longlong DAT_143d68878;
extern "C" unsigned char DAT_143d688b0;
extern "C" unsigned char DAT_143d688b8;
extern "C" unsigned char DAT_143d68930;
extern "C" volatile int DAT_143d68ab0;   // the SVM init count; volatile only gives the exe's re-read after the decrement
extern "C" volatile int DAT_143d68ab4;   // the SVM lock depth and type; volatile only gives the exe's re-reads
extern "C" volatile int DAT_143d68ab8;
extern "C" longlong DAT_143d68ac8;
extern "C" int DAT_143d68ad0;
extern "C" unsigned char DAT_143d74820;
extern "C" int DAT_143d74840;
extern "C" unsigned char DAT_143d74960;
extern "C" longlong DAT_143d74988;
extern "C" longlong DAT_143d749b8;
extern "C" longlong DAT_143d749c0;
extern "C" longlong DAT_143d749e8;
extern "C" longlong DAT_143d74a10;
extern "C" longlong DAT_143d74a18;
extern "C" longlong DAT_143d74a28;
extern "C" longlong DAT_143d74a40;
extern "C" longlong DAT_143d74a48;
extern "C" longlong DAT_143d74a50;
extern "C" longlong DAT_143d74a58;
extern "C" unsigned int DAT_143d74a80;
extern "C" unsigned char DAT_143db4ac0;
extern "C" unsigned short DAT_143dc4b00;
extern "C" unsigned short DAT_143e44b00;
extern "C" unsigned char DAT_143e64c00;
extern "C" unsigned char DAT_143e64c01;
extern "C" unsigned char DAT_143e668c0;
extern "C" unsigned char DAT_143e668c1;
extern "C" unsigned char DAT_143e668c2;
extern "C" unsigned char DAT_143ee78c0;
extern "C" unsigned char DAT_143ee78c1;
extern "C" unsigned char DAT_143f68240;
extern "C" unsigned char DAT_143f68241;
extern "C" unsigned char DAT_143f68242;
extern "C" longlong DAT_143fe8248;
extern "C" longlong DAT_143fe8250;
extern "C" unsigned char DAT_143fe82e0;
extern "C" unsigned char DAT_143fe83e0;
extern "C" char DAT_143fe841f;
extern "C" longlong DAT_143ffd4e8;
extern "C" int PTR_FUN_1431bbd40;
extern "C" int PTR_FUN_1431bbd50;
extern "C" int PTR_FUN_1431bc6c0;
extern "C" int PTR_FUN_1431bc6d8;
extern "C" int UNK_1431bbd7d;
extern "C" int UNK_1431bbd7e;
extern "C" int UNK_1431bbd7f;
extern "C" int _DAT_143a4a430;
extern "C" V16 _DAT_143a4a440;
extern "C" V16 _DAT_143a4a450;
extern "C" V16 _DAT_143a4a460;
extern "C" V16 _DAT_143a4a470;
extern "C" V16 _DAT_143a4a480;
extern "C" V16 _DAT_143a4a4a0;
extern "C" V16 _DAT_143a4a4b0;
extern "C" V16 _DAT_143a4a4c0;
extern "C" V16 _DAT_143a4a4d0;
extern "C" V16 _DAT_143a4a4e0;
extern "C" V16 _DAT_143a4a4f0;
extern "C" V16 _DAT_143a4a500;
extern "C" V16 _DAT_143a4a510;
extern "C" V16 _DAT_143a4a520;
extern "C" V16 _DAT_143a4a530;
extern "C" V16 _DAT_143a4a540;
extern "C" V16 _DAT_143a4a550;
extern "C" V16 _DAT_143a4a560;
extern "C" V16 _DAT_143a4a570;
extern "C" V16 _DAT_143a4a580;
extern "C" V16 _DAT_143a4a590;
extern "C" int _DAT_143d4eee0;
extern "C" int _DAT_143d67f70;
extern "C" longlong _DAT_143d68880;
extern "C" longlong _DAT_143d68888;
extern "C" longlong _DAT_143d68890;
extern "C" longlong _DAT_143d68898;
extern "C" longlong _DAT_143d688a0;
extern "C" longlong _DAT_143d688a8;
extern "C" longlong _DAT_143d74820;
extern "C" longlong _DAT_143d74828;
extern "C" longlong _DAT_143d74830;
extern "C" longlong _DAT_143d74838;
extern "C" longlong _DAT_143d74990;
extern "C" int iRam0000000143a4a434;
extern "C" int iRam0000000143a4a438;
extern "C" int iRam0000000143a4a43c;
extern "C" longlong DAT_143d68870;
extern "C" void* DAT_143d4ee08;
extern "C" void* DAT_143d4ee18;
extern "C" void* DAT_143d4eed8;
extern "C" void* DAT_143d4ef28;
extern "C" void* DAT_143d74968;
extern "C" void* DAT_143d749a8;
extern "C" void* PTR_FUN_143a4a5c0;
extern "C" void* _DAT_143d4ab88;
extern "C" void* _DAT_143d4edf8;
extern "C" void* _DAT_143d4ee00;
extern "C" void* _DAT_143d67f80;
extern "C" void* _DAT_143d74970;
extern "C" void* _DAT_143d749b0;
void FUN_14006aa60(short *src, short *dst);

void FUN_140035090(cri_any = cri_any());
void FUN_1400351c0(cri_any = cri_any());
void FUN_140035260(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
cri_u8 FUN_140035560(cri_any = cri_any());
extern "C" void FUN_1400356a0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140037910(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140037950(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140038ce4(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
cri_u4 FUN_140043f70(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
cri_u8 FUN_140043fe0(cri_any = cri_any(), cri_any = cri_any());
void FUN_140044050(cri_any = cri_any(), cri_any = cri_any());
cri_u4 FUN_140044950(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
cri_u8 FUN_1400449c0(cri_any = cri_any(), cri_any = cri_any());
void FUN_140044a30(cri_any = cri_any(), cri_any = cri_any());
cri_u4 FUN_140051ec0(longlong *, uint *);
void M2VIDCT_SetWork(cri_any = cri_any());
void M2VFRM_ParseSsc(cri_any = cri_any(), cri_any = cri_any());
void CFTCOM_SetCftFunctionName(cri_any = cri_any());
cri_u8 FUN_140062830();
int UTY_SupportSse();
void UTY_MemcpyDword(void *dst, const void *src, ulonglong n);
void FUN_140065800();
int seq2dctfsir(int);
void DCT_FsriInitScanTbl(const cri_u1 *, cri_u1 *);
void initB0Tbl();
void DCT_FsriInitScaleTbl(longlong);
void FUN_1400661e0();
void DCT_FsriInit();
void MPVCONCEAL_Init(longlong);
void MPVCONCEAL_Finish();
void MPVCONCEAL_StartFrame(longlong);
void MPVCONCEAL_StartTask(longlong);
void MPVCONCEAL_GetMbaInfo(longlong, cri_u4 *, cri_u4 *);
void MPVCONCEAL_SkippedMb(longlong);
int FUN_140066400(longlong);
void FUN_140066460(longlong, uint);
void FUN_140066a10(longlong, uint);
void FUN_140066c60(longlong, int);
void FUN_140066d80(cri_u8);
void FUN_140066da0(cri_u8);
void FUN_140066de0(cri_u8);
void mpvcdec_InitDct(longlong);
void mpvcdec_InitFuncsIdct();
void mpvcdec_SetDctFunc(longlong, int);
void mpvcdec_SetBlocksFunc(longlong, int);
void MPVCDEC_Init(longlong);
void MPVCDEC_StartFrame(longlong);
void mpvbdec_MakeTable(longlong, cri_u1 *, longlong);
void mpvbdec_SetupIxa(longlong);
void MPVBDEC_StartFrame(longlong);
void mpvbdec_InitZigzagTable(longlong);
void MPVBDEC_Init(cri_u8);
void mpvcmc_InitMcOiTa(longlong);
void MPVCMC_InitMcOiRt(longlong);
void MPVCMC_SetCcnt(longlong);
char * CRICRW_Strcpy(char *, size_t, const char *);
char * CRICRW_Strncpy(char *, size_t, const char *, size_t);
char * CRICRW_Strncat(char *, size_t, const char *, size_t);
char * CRICRW_Strcat(char *, size_t, const char *);
int FUN_1400675d0(char *, size_t, const char *, ...);
int FUN_140067630(const char *, const char *, ...);
void CRICRW_Vsprintf(char *, size_t, const char *, va_list);
FILE * FUN_1400676c0(const char *, const char *);
void SJCRS_Init();
void SJCRS_Finish();
void SJCRS_Lock();
void SJCRS_Unlock();
void CRIDLG_Init();
void CRIDLG_Finish();
cri_u8 CRIDLG_Create(cri_u8, cri_u4);
extern "C" cri_u8 cridlg_Create(longlong, uint);
void CRIDLG_Destroy(cri_u8);
extern "C" void FUN_140067ac0(void *);
cri_u4 CRIDLG_GetStat(cri_u8);
int cridlg_GetStat(int *);
cri_u4 CRIDLG_TryBeginInvoke(cri_u8, cri_u8, cri_u8);
int cridlg_TryBeginInvoke(int *, cri_u8, cri_u8);
void CRIDLG_EndInvoke(cri_u8, cri_u4);
extern "C" void cridlg_EndInvoke(int *, cri_u4);
cri_u4 CRIDLG_IsCompleted(cri_u8, cri_u4);
int cridlg_IsCompleted(int *, int);
cri_u4 CRIDLG_GetPriority(cri_u8);
int cridlg_GetPriority(int *);
void CRIDLG_SetPriority(cri_u8, cri_u4);
void cridlg_SetPriority(int *, int);
void CRIDLG_SetAffinityMask(cri_u8, cri_u4);
void cridlg_SetAffinityMask(int *, uint);
cri_u8 FUN_140068190(longlong);
cri_u8 FUN_140068200(cri_u8);
extern "C" cri_u8 FUN_140068210(longlong);
extern "C" void cridlg_assert(const char *);
void cridlg_lock();
void cridlg_unlock();
extern "C" cri_u8 CRICRS_Create(longlong, int);
extern "C" void CRICRS_Destroy(LPCRITICAL_SECTION);
extern "C" cri_u4 CRICRS_Enter(LPCRITICAL_SECTION);
extern "C" cri_u4 CRICRS_Leave(LPCRITICAL_SECTION);
void mpvumct_OutputIntra6blk(short *, int *, longlong);
void FUN_140068590(longlong *, longlong, uint);
void mpvumct_BiMakeMb(longlong *, longlong, uint);
void mpvumct_PpicSkipMb(int *, longlong *, longlong *);
void mpvumct_CalcOfs(longlong, longlong, int *);
void mpvumct_SubMbadr(longlong, int);
void mpvumct_IncreMbadr(longlong);
void MPVUMCT_Intra(longlong);
void mpvumct_OneReadMb(longlong, longlong, int *, longlong *, longlong);
void MPVUMCT_PpicSkipped(longlong, int);
void MPVUMCT_BpicSkipped(longlong, int);
void FUN_140068db0(longlong);
void FUN_140068e70(longlong);
void MPVUMCT_BiDirect(longlong);
void SJ_SplitChunk(longlong *, int, longlong *, longlong *);
void sj_val_to_hexstr(uint, char *);
int sj_hexstr_to_val(char *);
void SJ_MakeTag(longlong *, cri_u8);
void SJ_GetTagContent(longlong, longlong *);
char * SJ_SearchTag(longlong *, char *, char *, cri_u8 *);
cri_u8 criMvPly_GetFrameYUVBuffers(longlong, cri_u8 *, cri_u8);
cri_u8 criMvPly_CopyFrameYUVBuffers(longlong, cri_u8 *, cri_u8 *, cri_u8 *);
int criAdxDecCore_Decode(longlong, int, byte *, uint, int *, uint, longlong *, uint);
int FUN_140069ac4(longlong, int, byte *, uint, int *, uint, longlong *, uint);
void criAdxDecCore_Reset(longlong);
void criAdxDecCore_SetNumChan(longlong, int);
void criAdxDecCore_SetEncryptionKey(longlong, int, int, int);
void criAdxDecCore_SetDlyVal(longlong, uint, short, short);
void criAdxDecCore_SetCutoffFreqency(longlong, uint, uint);
int FUN_14006a090(cri_u1 *, uint);
int criAdxDec_DecodeInfoVer(short *, uint, cri_u1 *, cri_u1 *);
int criAdxDec_DecodeBasicInfo(cri_u1 *, uint, short *, cri_u1 *, char *, char *, cri_u1 *, cri_u4 *, cri_u4 *, int *);
uint criAdxDec_DecodeInfoInitialDelay(longlong, uint, ushort *, ushort *);
uint criAdxDec_DecodeInfoLoop(longlong, uint, uint *, ushort *, ushort *, uint *, uint *, uint *, uint *);
uint criAdxDec_DecodeInfoAinf(longlong, uint, uint *, void *, ushort *, ushort *);
int criAdxDec_DecodeInfoExADPCM2(short *, int, ushort *);
uint criAdxDec_DecodeHeader(cri_u8, uint, longlong);
uint criAdxDec_DecodeHeaderEx(cri_u8, cri_u4, longlong);
void DCT_Isse2Init();
void DCT_Isse2Trans(V16 *, V16 *, int);
longlong FUN_14006b0d0(longlong);
longlong FUN_140073c80(longlong);
longlong FUN_14007ba60(longlong);
longlong FUN_140083350(longlong);
void m2vsl_DecSliceOne(longlong, cri_u8, cri_u4 *);
void * m2vsl_DuplicateObj(void *, int);
void M2VSL_DecPicture(longlong, cri_u8);
void m2vsl_DecTaskOne(longlong, cri_u8, int *);
void m2vmc_SetFrameBuffer(longlong);
void M2VMC_MacroBlock(longlong);
void FUN_14008a430(longlong, int, int);
void FUN_14008a5b0(longlong, int, int);
void m2vmc_AddBlock_thumbnail(longlong, uint, int, int, int);
void Dual_Prime_Arithmetic(longlong, int *, int *, int, int);
void M2VMC_Skipped(longlong, uint);
void m2vmc_AddBlocks_thumbnail(longlong, cri_u4, cri_u4);
void m2vmc_SetFunction(longlong);
void M2VMC_StartFrame(longlong);
void M2VPRD_FormPredictions(longlong, cri_u4, int);
void FUN_14008b6b0(longlong, longlong, int, cri_u4, uint, cri_u4, int, int, uint, uint, int);
void form_component_prediction_thumbnail(longlong, longlong, int, cri_u4, int, int, int, int, uint, uint, int);
void FUN_14008c150(longlong, longlong *, int, longlong *, int, int, int, int, int, int, int, int, int, cri_u4);
void form_prediction_thumbnail(longlong, longlong *, int, longlong *, int, int, int, int, int, int, int, int, int, cri_u4);
void M2VPRD_SetFunction(longlong);
void M2VCONCEAL_StartFrame(longlong);
void M2VCONCEAL_StartTask(longlong);
void M2VCONCEAL_GetMbaInfo(longlong, cri_u4 *, cri_u4 *);
void M2VCONCEAL_SkippedMb(longlong);
int FUN_14008c830(longlong);
void FUN_14008c890(longlong, uint);
void FUN_14008ce50(longlong, uint);
void FUN_14008d0b0(longlong, int);
void FUN_14008d220(cri_u8);
void FUN_14008d240(cri_u8);
void FUN_14008d280(cri_u8);
void FUN_14008d2a0(longlong *, longlong *, longlong, longlong);
void cft_sse_Ycc420plnToRgb888Int2smp(longlong *, longlong *, longlong, longlong);
void cft_sse_Ycc420plnToArgb8888Prg(longlong *, longlong *, longlong, longlong);
void cft_sse_Ycc420plnToRgb888Prg(longlong *, longlong *, longlong, longlong);
void FUN_140090730(cri_u8 *, longlong *, cri_u8, longlong);
void cft_c_Ycc420plnToArgb8888Int1smp(cri_u8 *, cri_u8 *);
void cft_c_Ycc420plnToArgb8888Prg1smp(cri_u8 *, longlong *);
void cft_c_Ycc420plnToYcc422pix2Int1smp(cri_u8 *, longlong *);
void CFT_Ycc420plnToArgb8888Int1smp(byte *, byte *, cri_u8, cri_u8);
void CFT_Ycc420plnToArgb8888Prg1smp(byte *, byte *, cri_u8, cri_u8);
void CFT_Ycc420plnToYcc422pix2Int1smp(byte *, byte *, cri_u8, cri_u8);
void CFT_Ycc420plnToRgb555(longlong, longlong);
void CFT_Ycc420plnToRgb555WithDither(longlong, longlong);
void FUN_140093890(void *, int, int);
void FUN_140093940(void *, int, int, int);
void CFT_Ycc420plnToRgb555Init();
void CFT_Ycc420plnToRgb565(longlong, longlong);
void CFT_Ycc420plnToRgb565WithDither(longlong, longlong);
void FUN_140094df0(void *, int, int);
void FUN_140094ea0(void *, int, int, int);
void CFT_Ycc420plnToRgb565Init();
cri_u8 DCT_GetVerStr();
void DCT_SetErrFunc(cri_u8, cri_u8);
void DCTVER_Error(cri_u4);
void DCT_AcInit();
void dctac_TransDouble(void *, void *, void *);
void DCT_AcFdctDouble(void *, void *);
void DCT_AcIdctDouble(void *, void *);
void DCT_AcFdctShort(longlong, cri_u2 *);
void DCT_AcIdctShort(longlong, cri_u2 *);
void FUN_140095b20();
uint FUN_140095b40(longlong, uint *);
uint FUN_14009a3d0(longlong, uint *);
uint FUN_14009ec40(longlong, uint *);
uint FUN_1400a3920(longlong, uint *);
uint FUN_1400a8ad0(longlong, uint *);
uint FUN_1400adc50(longlong, uint *);
void MPVABDEC_Init();
void svm_lock(uint);
void SVM_Lock();
void SVM_CallErr(const char *, ...);
void SVM_CallErr1(const char *);
void SVM_CallErr2(const char *, const char *);
void FUN_1400aff40(int);
cri_u8 svm_reset_variable();
void SVM_Init();
void SVM_Finish();
void FUN_1400b01f0();
void FUN_1400b0210();
void svm_enterCriticalSection(int);
void svm_leaveCriticalSection(int);
void svm_unlock(int);
void SVM_Unlock();
uint svm_SetCbSvr(uint, longlong, longlong, char *);
void svm_DelCbSvr(uint, uint);
void svm_SetCbSvrId(uint, uint, cri_u8, cri_u8, char *);
void SVM_SetCbBdr(int, cri_u8, cri_u8);
uint SVM_ExecSvrFunc(int);
cri_u4 SVM_ExecSvrFuncId(uint, uint);
uint SVM_TestAndSet(int *, cri_u8, cri_u8, cri_u8);
cri_u4 SVM_SetCbSvrWithString(uint, longlong, longlong, char *);
void SVM_DelCbSvr(uint, uint);
void SVM_SetCbSvrIdWithString(uint, uint, cri_u8, cri_u8, char *);
void SVM_SetCbSvrId(uint, uint, cri_u8, cri_u8);
void CRIERR_CallErr(const char *);
void cft_sse_Ycc420plnToArgb8888Int1smp(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void cft_sse_Ycc420plnToArgb8888Prg1smp(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_1400b1e50(cri_any = cri_any(), cri_any = cri_any(), ...);
int FUN_14029dd60(const char *, const char *, ...);   // game code's legacy inline sscanf
// C3: was cri_u8 * FUN_142096410(cri_any) (= efd::GenerateAssetResponseCategory); unused here

void DCT_FsriInitScaleTbl(longlong arg1);

void FUN_1400661e0();
void FUN_1400662e0(char *ctx);

void FUN_1400662f0(char *ctx);

void FUN_140066300(char *ctx);

void FUN_140066310(char *ctx);


void DCT_FsriInit();

void MPVCONCEAL_Init(longlong arg1);

void MPVCONCEAL_Finish();

void MPVCONCEAL_StartFrame(longlong arg1);

void MPVCONCEAL_StartTask(longlong arg1);

void MPVCONCEAL_GetMbaInfo(longlong arg1, cri_u4 *arg2, cri_u4 *arg3);

void MPVCONCEAL_SkippedMb(longlong arg1);

int FUN_140066400(longlong arg1);

void FUN_140066460(longlong arg1, uint arg2);

void FUN_140066a10(longlong arg1, uint arg2);

void FUN_140066c60(longlong arg1, int arg2);

void FUN_140066d80(cri_u8 arg1);

void FUN_140066da0(cri_u8 arg1);

void FUN_140066de0(cri_u8 arg1);

uint FUN_140066e00(longlong a1, uint a2);

void mpvcdec_InitDct(longlong arg1);

void mpvcdec_InitFuncsIdct();

void mpvcdec_SetDctFunc(longlong arg1, int arg2);

void mpvcdec_SetBlocksFunc(longlong arg1, int arg2);

void MPVCDEC_Init(longlong arg1);

void MPVCDEC_StartFrame(longlong arg1);

void mpvbdec_MakeTable(longlong arg1, cri_u1 *arg2, longlong arg3);

// The 32-byte table mpvbdec_SetupIxa copies to +0x12a0 (exe .rdata 0x1431bbe00, inside data_cri's DAT_1431bbdc1 piece).
struct cri07_tbl32 { cri_u8 q[4]; };

void mpvbdec_SetupIxa(longlong arg1);

void MPVBDEC_StartFrame(longlong arg1);

void mpvbdec_InitZigzagTable(longlong arg1);

void MPVBDEC_Init(cri_u8 arg1);

void mpvcmc_InitMcOiTa(longlong arg1);

void MPVCMC_InitMcOiRt(longlong arg1);

void MPVCMC_SetCcnt(longlong arg1);

void thunk_FUN_140067390(longlong arg1);

void thunk_FUN_1400afe60(const char *arg1);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
char * CRICRW_Strcpy(char *dst, size_t size, const char *src);

char * CRICRW_Strncpy(char *dst, size_t size, const char *src, size_t count);

char * CRICRW_Strncat(char *dst, size_t size, const char *src, size_t count);

char * CRICRW_Strcat(char *dst, size_t size, const char *src);

int FUN_1400675d0(char *_Dest,size_t _Count,const char *_Format,...);

int FUN_140067630(const char *buf, const char *format, ...);

void CRICRW_Vsprintf(char *arg1,size_t arg2,const char *arg3,va_list arg4);

FILE * FUN_1400676c0(const char *name, const char *mode);
#pragma optimize("", on)

void SJCRS_Init();

void SJCRS_Finish();

void SJCRS_Lock();

void SJCRS_Unlock();

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void CRIDLG_Init();

void CRIDLG_Finish();

cri_u8 CRIDLG_Create(cri_u8 arg1, cri_u4 arg2);

extern "C" cri_u8 cridlg_Create(longlong arg1, uint arg2);

void CRIDLG_Destroy(cri_u8 arg1);

#pragma function(memset)                      // the exe obj calls memset here
extern "C" void FUN_140067ac0(void *arg1);
#pragma intrinsic(memset)

cri_u4 CRIDLG_GetStat(cri_u8 arg1);

int cridlg_GetStat(int *arg1);

cri_u4 CRIDLG_TryBeginInvoke(cri_u8 arg1, cri_u8 arg2, cri_u8 arg3);

int cridlg_TryBeginInvoke(int *arg1, cri_u8 arg2, cri_u8 arg3);

void CRIDLG_EndInvoke(cri_u8 arg1, cri_u4 arg2);

extern "C" void cridlg_EndInvoke(int *arg1, cri_u4 arg2);

cri_u4 CRIDLG_IsCompleted(cri_u8 arg1, cri_u4 arg2);

int cridlg_IsCompleted(int *arg1, int arg2);

cri_u4 CRIDLG_GetPriority(cri_u8 arg1);

int cridlg_GetPriority(int *arg1);

void CRIDLG_SetPriority(cri_u8 arg1, cri_u4 arg2);

void cridlg_SetPriority(int *arg1, int arg2);

void CRIDLG_SetAffinityMask(cri_u8 arg1, cri_u4 arg2);

void cridlg_SetAffinityMask(int *arg1, uint arg2);

cri_u8 FUN_140068190(longlong arg1);

cri_u8 FUN_140068200(cri_u8 arg1);

extern "C" cri_u8 FUN_140068210(longlong arg1);

extern "C" void cridlg_assert(const char *arg1);

void cridlg_lock();

void cridlg_unlock();

#pragma function(memset)                      // the exe obj calls memset here
extern "C" cri_u8 CRICRS_Create(longlong arg1, int arg2);
#pragma intrinsic(memset)

#pragma function(memset)                      // the exe obj calls memset here
extern "C" void CRICRS_Destroy(LPCRITICAL_SECTION arg1);
#pragma intrinsic(memset)

extern "C" cri_u4 CRICRS_Enter(LPCRITICAL_SECTION arg1);

extern "C" cri_u4 CRICRS_Leave(LPCRITICAL_SECTION arg1);
#pragma optimize("", on)

void mpvumct_OutputIntra6blk(short *arg1, int *arg2, longlong arg3);

void FUN_140068590(longlong *arg1, longlong arg2, uint arg3);

void mpvumct_BiMakeMb(longlong *arg1, longlong arg2, uint arg3);

void mpvumct_PpicSkipMb(int *arg1, longlong *arg2, longlong *arg3);

void mpvumct_CalcOfs(longlong arg1, longlong arg2, int *arg3);

void mpvumct_SubMbadr(longlong arg1, int arg2);

void mpvumct_IncreMbadr(longlong arg1);

void MPVUMCT_Intra(longlong arg1);

void mpvumct_OneReadMb(longlong arg1, longlong arg2, int *arg3, longlong *arg4, longlong arg5);

void MPVUMCT_PpicSkipped(longlong arg1, int arg2);

void MPVUMCT_BpicSkipped(longlong arg1, int arg2);

void FUN_140068db0(longlong arg1);

void FUN_140068e70(longlong arg1);

void MPVUMCT_BiDirect(longlong arg1);

void SJ_SplitChunk(longlong *arg1, int arg2, longlong *arg3, longlong *arg4);

void sj_val_to_hexstr(uint arg1, char *arg2);

int sj_hexstr_to_val(char *arg1);

void SJ_MakeTag(longlong *arg1, cri_u8 arg2);

void SJ_GetTagContent(longlong arg1, longlong *arg2);

char * SJ_SearchTag(longlong *arg1, char *arg2, char *arg3, cri_u8 *arg4);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
cri_u8 criMvPly_GetFrameYUVBuffers(longlong arg1, cri_u8 *arg2, cri_u8 arg3);

cri_u8 criMvPly_CopyFrameYUVBuffers(longlong arg1, cri_u8 *arg2, cri_u8 *arg3, cri_u8 *arg4);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
int criAdxDecCore_Decode(longlong cri_p0, int cri_p1, byte *cri_p2, uint cri_p3, int *cri_p4, uint cri_p5, longlong *cri_p6, uint cri_p7);

int FUN_140069ac4(longlong cri_p0, int cri_p1, byte *cri_p2, uint cri_p3, int *cri_p4, uint cri_p5, longlong *cri_p6, uint cri_p7);

void criAdxDecCore_Reset(longlong cri_p0);

void criAdxDecCore_SetNumChan(longlong cri_p0, int cri_p1);

void criAdxDecCore_SetEncryptionKey(longlong cri_p0, int cri_p1, int cri_p2, int cri_p3);

void criAdxDecCore_SetDlyVal(longlong cri_p0, uint cri_p1, short cri_p2, short cri_p3);

void criAdxDecCore_SetCutoffFreqency(longlong cri_p0, uint cri_p1, uint cri_p2);

#pragma function(strlen, memcmp)                // the exe calls strlen and memcmp here rather than expanding them
int FUN_14006a090(cri_u1 *arg1, uint arg2);
#pragma intrinsic(strlen, memcmp)

int criAdxDec_DecodeInfoVer(short *arg1, uint arg2, cri_u1 *arg3, cri_u1 *arg4);

int criAdxDec_DecodeBasicInfo(cri_u1 *arg1, uint arg2, short *arg3, cri_u1 *arg4, char *arg5, char *arg6, cri_u1 *arg7, cri_u4 *arg8, cri_u4 *arg9, int *arg10);

uint criAdxDec_DecodeInfoInitialDelay(longlong arg1, uint arg2, ushort *arg3, ushort *arg4);

uint criAdxDec_DecodeInfoLoop(longlong arg1, uint arg2, uint *arg3, ushort *arg4, ushort *arg5, uint *arg6, uint *arg7, uint *arg8, uint *arg9);

uint criAdxDec_DecodeInfoAinf(longlong arg1, uint arg2, uint *arg3, void *arg4, ushort *arg5, ushort *arg6);

int criAdxDec_DecodeInfoExADPCM2(short *arg1, int arg2, ushort *arg3);

uint criAdxDec_DecodeHeader(cri_u8 cri_p0, uint cri_p1, longlong cri_p2);

uint criAdxDec_DecodeHeaderEx(cri_u8 arg1, cri_u4 arg2, longlong arg3);
#pragma optimize("", on)

// The DC rounding hook mpvcdec_InitDct stores in DAT_143d4ee08 (Ghidra made no function here): src's coefficient divided
// by 8, rounded half away from 0, into dst.
// MS2-FUNCTIONAL: written from the exe (VS2008 build, our toolset differs).
// @0x14006aa60
void FUN_14006aa60(short *src, short *dst)
{
  int c = *src;
  int v;
  if (c >= 0) {
    v = (c + 4) >> 3;
  }
  else {
    v = -((4 - c) >> 3);
  }
  *dst = (short)v;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14006aa90
void DCT_Isse2Init()
{
  return;
}

// The 8x8 IDCT (Intel AP-922 style): arg1 holds the 8 rows of coefficients, arg2 receives the result. With arg3 == 0
// only the DC term is set, so every output is its rounded value / 8. Otherwise the row pass multiplies each row by its
// pmaddwd tables (0x143a4a4a0 rows 0/4, 0x143a4a4e0 rows 1/7, 0x143a4a520 rows 2/6, 0x143a4a560 rows 3/5) two rows at a
// time, and the column pass uses the tangent / cos(4) constants at 0x143a4a460-0x143a4a490, keeping rows 3 and 7 of
// arg2 as scratch until the end.
// MS2-FUNCTIONAL: written from the exe with SSE2 intrinsics (same instructions; VC9 schedules and allocates registers
// differently, and the exe's /GS cookie is missing).
#define DCT_T(x) (*(const __m128i *)CRI_FILL_ADDR(x))
// one row times its 4 table words t0..t3; DCT_ROWA shuffles the low words first, DCT_ROWB the high words
#define DCT_ROWA(src, t0, t1, t2, t3, res) \
  lo = _mm_shufflelo_epi16(src, 0xd8); \
  hi = _mm_shufflehi_epi16(lo, 0xd8); \
  od = _mm_add_epi32(_mm_madd_epi16(_mm_shuffle_epi32(hi, 0xff), DCT_T(t3)), \
                     _mm_madd_epi16(_mm_shuffle_epi32(lo, 0x55), DCT_T(t2))); \
  ev = _mm_add_epi32(_mm_add_epi32(_mm_madd_epi16(_mm_shuffle_epi32(lo, 0), DCT_T(t0)), rnd), \
                     _mm_madd_epi16(_mm_shuffle_epi32(hi, 0xaa), DCT_T(t1))); \
  res = _mm_packs_epi32(_mm_srai_epi32(_mm_add_epi32(od, ev), 12), \
                        _mm_shuffle_epi32(_mm_srai_epi32(_mm_sub_epi32(ev, od), 12), 0x1b))
#define DCT_ROWB(src, t0, t1, t2, t3, res) \
  lo = _mm_shufflelo_epi16(_mm_shufflehi_epi16(src, 0xd8), 0xd8); \
  ev = _mm_add_epi32(_mm_add_epi32(_mm_madd_epi16(_mm_shuffle_epi32(lo, 0), DCT_T(t0)), rnd), \
                     _mm_madd_epi16(_mm_shuffle_epi32(lo, 0xaa), DCT_T(t1))); \
  od = _mm_add_epi32(_mm_madd_epi16(_mm_shuffle_epi32(lo, 0xff), DCT_T(t3)), \
                     _mm_madd_epi16(_mm_shuffle_epi32(lo, 0x55), DCT_T(t2))); \
  res = _mm_packs_epi32(_mm_srai_epi32(_mm_add_epi32(od, ev), 12), \
                        _mm_shuffle_epi32(_mm_srai_epi32(_mm_sub_epi32(ev, od), 12), 0x1b))
// @0x14006aaa0
void DCT_Isse2Trans(V16 *arg1, V16 *arg2, int arg3)
{
  __m128i *s = (__m128i *)arg1;
  __m128i *d = (__m128i *)arg2;
  if (arg3 == 0) {
    short c = *(short *)arg1;
    short v;
    __m128i x;
    if (c < 0) {
      v = -(short)((4 - c) >> 3);
    }
    else {
      v = (short)((c + 4) >> 3);
    }
    x = _mm_setzero_si128();
    x = _mm_insert_epi16(x, v, 0);
    x = _mm_shufflelo_epi16(x, 0);
    x = _mm_shuffle_epi32(x, 0);
    d[0] = x; d[1] = x; d[2] = x; d[3] = x;
    d[4] = x; d[5] = x; d[6] = x; d[7] = x;
    return;
  }
  __m128i lo, hi, ev, od, rnd, ra, rb, r5, r7;
  rnd = DCT_T(_DAT_143a4a430);
  DCT_ROWA(s[0], _DAT_143a4a4a0, _DAT_143a4a4b0, _DAT_143a4a4c0, _DAT_143a4a4d0, ra);
  DCT_ROWB(s[2], _DAT_143a4a520, _DAT_143a4a530, _DAT_143a4a540, _DAT_143a4a550, rb);
  d[0] = ra;
  d[2] = rb;
  rnd = DCT_T(_DAT_143a4a430);
  DCT_ROWA(s[4], _DAT_143a4a4a0, _DAT_143a4a4b0, _DAT_143a4a4c0, _DAT_143a4a4d0, ra);
  DCT_ROWB(s[6], _DAT_143a4a520, _DAT_143a4a530, _DAT_143a4a540, _DAT_143a4a550, rb);
  d[4] = ra;
  d[6] = rb;
  rnd = DCT_T(_DAT_143a4a430);
  DCT_ROWA(s[3], _DAT_143a4a560, _DAT_143a4a570, _DAT_143a4a580, _DAT_143a4a590, ra);
  DCT_ROWB(s[1], _DAT_143a4a4e0, _DAT_143a4a4f0, _DAT_143a4a500, _DAT_143a4a510, rb);
  d[1] = rb;
  d[3] = ra;
  rnd = DCT_T(_DAT_143a4a430);
  DCT_ROWA(s[5], _DAT_143a4a560, _DAT_143a4a570, _DAT_143a4a580, _DAT_143a4a590, r5);
  DCT_ROWB(s[7], _DAT_143a4a4e0, _DAT_143a4a4f0, _DAT_143a4a500, _DAT_143a4a510, r7);

  // column pass
  __m128i tg1 = DCT_T(_DAT_143a4a460);
  __m128i tg2 = DCT_T(_DAT_143a4a470);
  __m128i tg3 = DCT_T(_DAT_143a4a480);
  __m128i tm26 = _mm_mulhi_epi16(d[6], tg2);
  __m128i t26 = _mm_mulhi_epi16(tg2, d[2]);
  __m128i b3 = _mm_adds_epi16(_mm_adds_epi16(_mm_mulhi_epi16(r5, tg3), r5), d[3]);
  __m128i b5 = _mm_subs_epi16(r5, _mm_adds_epi16(_mm_mulhi_epi16(tg3, d[3]), d[3]));
  __m128i tp17 = _mm_adds_epi16(_mm_mulhi_epi16(r7, tg1), d[1]);
  __m128i tm17 = _mm_subs_epi16(_mm_mulhi_epi16(tg1, d[1]), r7);
  __m128i one = DCT_T(_DAT_143a4a420);
  __m128i x7 = _mm_subs_epi16(tp17, b3);
  d[7] = _mm_adds_epi16(_mm_adds_epi16(b3, tp17), one);
  d[3] = _mm_adds_epi16(tm17, b5);
  __m128i x2 = _mm_adds_epi16(_mm_subs_epi16(tm17, b5), one);
  __m128i cos4 = DCT_T(_DAT_143a4a490);
  tm26 = _mm_adds_epi16(tm26, d[2]);
  t26 = _mm_subs_epi16(t26, d[6]);
  __m128i tp04 = _mm_adds_epi16(d[4], d[0]);
  __m128i tm04 = _mm_subs_epi16(d[0], d[4]);
  __m128i y1 = _mm_adds_epi16(x7, x2);
  __m128i y2 = _mm_subs_epi16(x7, x2);
  y1 = _mm_or_si128(_mm_adds_epi16(y1, _mm_mulhi_epi16(cos4, y1)), DCT_T(_DAT_143a4a420));
  y2 = _mm_or_si128(_mm_adds_epi16(_mm_mulhi_epi16(cos4, y2), y2), DCT_T(_DAT_143a4a420));
  __m128i a0 = _mm_adds_epi16(_mm_adds_epi16(tp04, tm26), DCT_T(_DAT_143a4a440));
  __m128i a1 = _mm_adds_epi16(_mm_adds_epi16(tm04, t26), DCT_T(_DAT_143a4a440));
  __m128i a3 = _mm_adds_epi16(_mm_subs_epi16(tp04, tm26), DCT_T(_DAT_143a4a450));
  __m128i a2 = _mm_adds_epi16(_mm_subs_epi16(tm04, t26), DCT_T(_DAT_143a4a450));
  d[0] = _mm_srai_epi16(_mm_adds_epi16(d[7], a0), 5);
  d[1] = _mm_srai_epi16(_mm_adds_epi16(a1, y1), 5);
  d[2] = _mm_srai_epi16(_mm_adds_epi16(a2, y2), 5);
  d[7] = _mm_srai_epi16(_mm_subs_epi16(a0, d[7]), 5);
  __m128i r3 = d[3];
  d[3] = _mm_srai_epi16(_mm_adds_epi16(r3, a3), 5);
  d[4] = _mm_srai_epi16(_mm_subs_epi16(a3, r3), 5);
  d[5] = _mm_srai_epi16(_mm_subs_epi16(a2, y2), 5);
  d[6] = _mm_srai_epi16(_mm_subs_epi16(a1, y1), 5);
}
#undef DCT_ROWB
#undef DCT_ROWA
#undef DCT_T

longlong FUN_14006b0d0(longlong arg1);

longlong FUN_140073c80(longlong arg1);

longlong FUN_14007ba60(longlong arg1);

longlong FUN_140083350(longlong arg1);

void m2vsl_DecSliceOne(longlong arg1, cri_u8 arg2, cri_u4 *arg3);

void * m2vsl_DuplicateObj(void *arg1, int arg2);

void M2VSL_DecPicture(longlong arg1, cri_u8 arg2);

void m2vsl_DecTaskOne(longlong arg1, cri_u8 arg2, int *arg3);

void m2vmc_SetFrameBuffer(longlong arg1);

void M2VMC_MacroBlock(longlong arg1);

void FUN_14008a430(longlong arg1, int arg2, int arg3);

void FUN_14008a5b0(longlong arg1, int arg2, int arg3);

void m2vmc_AddBlock_thumbnail(longlong arg1, uint arg2, int arg3, int arg4, int arg5);

void Dual_Prime_Arithmetic(longlong arg1, int *arg2, int *arg3, int arg4, int arg5);

void M2VMC_Skipped(longlong arg1, uint arg2);

void m2vmc_AddBlocks_thumbnail(longlong arg1, cri_u4 arg2, cri_u4 arg3);

void m2vmc_SetFunction(longlong arg1);

void M2VMC_StartFrame(longlong arg1);

void M2VPRD_FormPredictions(longlong arg1, cri_u4 arg2, int arg3);

void FUN_14008b6b0(longlong arg1, longlong arg2, int arg3, cri_u4 arg4, uint arg5, cri_u4 arg6, int arg7, int arg8, uint arg9, uint arg10, int arg11);

void form_component_prediction_thumbnail(longlong arg1, longlong arg2, int arg3, cri_u4 arg4, int arg5, int arg6, int arg7, int arg8, uint arg9, uint arg10, int arg11);

void FUN_14008c150(longlong arg1, longlong *arg2, int arg3, longlong *arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, cri_u4 arg14);

void form_prediction_thumbnail(longlong arg1, longlong *arg2, int arg3, longlong *arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, cri_u4 arg14);

void M2VPRD_SetFunction(longlong arg1);

void M2VCONCEAL_StartFrame(longlong arg1);

void M2VCONCEAL_StartTask(longlong arg1);

void M2VCONCEAL_GetMbaInfo(longlong arg1, cri_u4 *arg2, cri_u4 *arg3);

void M2VCONCEAL_SkippedMb(longlong arg1);

int FUN_14008c830(longlong arg1);

void FUN_14008c890(longlong arg1, uint arg2);

void FUN_14008ce50(longlong arg1, uint arg2);

void FUN_14008d0b0(longlong arg1, int arg2);

void FUN_14008d220(cri_u8 arg1);

void FUN_14008d240(cri_u8 arg1);

void FUN_14008d280(cri_u8 arg1);

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// Last 8 output bytes of a 4:2:0 chroma row (exe pavgw/packuswb tail): c0 (c0+c1) c1 (c1+c2) c2 (c2+c3) c3 c3,
// interpolated pairs rounded up. Replaces Ghidra's lane-shuffle transcription, which got the averages wrong.
static cri_u8 cri07_upsample_tail(cri_u8 v)
{
  cri_u8 c0 = v & 0xff;
  cri_u8 c1 = v >> 8 & 0xff;
  cri_u8 c2 = v >> 0x10 & 0xff;
  cri_u8 c3 = v >> 0x18 & 0xff;
  return c0 | (c0 + c1 + 1 >> 1) << 8 | c1 << 0x10 | (c1 + c2 + 1 >> 1) << 0x18 | c2 << 0x20 |
         (c2 + c3 + 1 >> 1) << 0x28 | c3 << 0x30 | c3 << 0x38;
}

void FUN_14008d2a0(longlong *arg1, longlong *arg2, longlong arg3, longlong arg4);

void cft_sse_Ycc420plnToRgb888Int2smp(longlong *arg1, longlong *arg2, longlong arg3, longlong arg4);

void cft_sse_Ycc420plnToArgb8888Prg(longlong *arg1, longlong *arg2, longlong arg3, longlong arg4);

void cft_sse_Ycc420plnToRgb888Prg(longlong *arg1, longlong *arg2, longlong arg3, longlong arg4);

void FUN_140090730(cri_u8 *arg1, longlong *arg2, cri_u8 arg3, longlong arg4);

void cft_c_Ycc420plnToArgb8888Int1smp(cri_u8 *arg1, cri_u8 *arg2);

void cft_c_Ycc420plnToArgb8888Prg1smp(cri_u8 *arg1, longlong *arg2);

void cft_c_Ycc420plnToYcc422pix2Int1smp(cri_u8 *arg1, longlong *arg2);

void CFT_Ycc420plnToArgb8888Int1smp(byte *arg1, byte *arg2, cri_u8 arg3, cri_u8 arg4);

void CFT_Ycc420plnToArgb8888Prg1smp(byte *arg1, byte *arg2, cri_u8 arg3, cri_u8 arg4);

void CFT_Ycc420plnToYcc422pix2Int1smp(byte *arg1, byte *arg2, cri_u8 arg3, cri_u8 arg4);

void CFT_Ycc420plnToRgb555(longlong arg1, longlong arg2);

void CFT_Ycc420plnToRgb555WithDither(longlong arg1, longlong arg2);

void FUN_140093890(void *arg1, int arg2, int arg3);

void FUN_140093940(void *arg1, int arg2, int arg3, int arg4);

void CFT_Ycc420plnToRgb555Init();

void CFT_Ycc420plnToRgb565(longlong arg1, longlong arg2);

void CFT_Ycc420plnToRgb565WithDither(longlong arg1, longlong arg2);

void FUN_140094df0(void *arg1, int arg2, int arg3);

void FUN_140094ea0(void *arg1, int arg2, int arg3, int arg4);

void CFT_Ycc420plnToRgb565Init();

cri_u8 DCT_GetVerStr();

void DCT_SetErrFunc(cri_u8 arg1, cri_u8 arg2);

void DCTVER_Error(cri_u4 arg1);

void DCT_AcInit();

void dctac_TransDouble(void *cri_p0, void *cri_p1, void *cri_p2);

void DCT_AcFdctDouble(void *arg1, void *arg2);

void DCT_AcIdctDouble(void *arg1, void *arg2);

void DCT_AcFdctShort(longlong arg1, cri_u2 *arg2);

void DCT_AcIdctShort(longlong arg1, cri_u2 *arg2);

void FUN_140095b20();

uint FUN_140095b40(longlong arg1, uint *arg2);

uint FUN_14009a3d0(longlong arg1, uint *arg2);

uint FUN_14009ec40(longlong arg1, uint *arg2);

uint FUN_1400a3920(longlong arg1, uint *arg2);

uint FUN_1400a8ad0(longlong arg1, uint *arg2);

uint FUN_1400adc50(longlong arg1, uint *arg2);

void MPVABDEC_Init();

void svm_lock(uint arg1);

void SVM_Lock();

void SVM_CallErr(const char *arg1, ...);

void SVM_CallErr1(const char *arg1);

void SVM_CallErr2(const char *arg1, const char *arg2);

void FUN_1400aff40(int arg1);

#pragma function(memset)                // the exe calls memset here rather than expanding it
cri_u8 svm_reset_variable();
#pragma intrinsic(memset)

void SVM_Init();

void SVM_Finish();

void FUN_1400b01f0();

void FUN_1400b0210();

void svm_enterCriticalSection(int arg1);

void svm_leaveCriticalSection(int arg1);

void svm_unlock(int arg1);

void SVM_Unlock();

uint svm_SetCbSvr(uint arg1, longlong arg2, longlong arg3, char *arg4);

void svm_DelCbSvr(uint arg1, uint arg2);

void svm_SetCbSvrId(uint arg1, uint arg2, cri_u8 arg3, cri_u8 arg4, char *arg5);

void SVM_SetCbBdr(int arg1, cri_u8 arg2, cri_u8 arg3);

// One 0x18-byte entry of a server slot callback table (DAT_143d683d0, 6 entries per slot).
struct cri07_srvcb { uint (*fn)(cri_u8); cri_u8 arg; cri_u8 spare; };

uint SVM_ExecSvrFunc(int arg1);

cri_u4 SVM_ExecSvrFuncId(uint arg1, uint arg2);

uint SVM_TestAndSet(int *arg1, cri_u8 a2, cri_u8 a3, cri_u8 a4);

cri_u4 SVM_SetCbSvrWithString(uint arg1, longlong arg2, longlong arg3, char *arg4);

void SVM_DelCbSvr(uint arg1, uint arg2);

void SVM_SetCbSvrIdWithString(uint arg1, uint arg2, cri_u8 arg3, cri_u8 arg4, char *arg5);

void SVM_SetCbSvrId(uint arg1, uint arg2, cri_u8 arg3, cri_u8 arg4);

void cft_sse_Ycc420plnToArgb8888Int1smp(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...);

void cft_sse_Ycc420plnToArgb8888Prg1smp(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...);

void FUN_1400b1e50(cri_any cri_p0, cri_any cri_p1, ...);


// ---- full-exe unresolved: leaves without .pdata that data_cri / data_data_game reference as ?FUN_<va>@@YAXXZ ----
// The pel predictors take a context with dst +0x30 and the reference rows +0x40 / +0x48.
struct cri07_pelctx { void* _00[6]; cri_u1* dst; void* _38; const cri_u1* a; const cri_u1* b; };

void FUN_140066450(void*);

void FUN_140068510(cri07_pelctx* ctx);

void FUN_140068520(cri07_pelctx* ctx);

void FUN_140068540(cri07_pelctx* ctx);

void FUN_140068560(cri07_pelctx* ctx);

struct cri07_decfields
{
  cri_u1 _000[0x6f0]; int p2;
  cri_u1 _6f4[0xc9c - 0x6f4]; int p1;
  cri_u1 _ca0[0x1bc0 - 0xca0]; int abort;
  cri_u1 _1bc4[0x1be0 - 0x1bc4]; void (*handler)(cri07_decfields*, int, int);
};
void FUN_140089fa0(cri07_decfields* self);

void FUN_140089fc0(cri07_decfields* self, int a, int b);

void FUN_14008c880(void*);
