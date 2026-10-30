// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): CRI MvCore / Sofdec vendor middleware, the IDCT obj at
// 0x14006aa60-0x14006b0d0 (the DC rounding hook, an empty init function and the 8x8 IDCT). In the exe it is its own obj
// inside sfr_cri_07's range: FUN_140066e10 in 07 still calls the empty FUN_14006aa90, a call VC9 drops for an empty
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

void FUN_140065e70(cri_any = cri_any(), cri_any = cri_any());
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
void FUN_1400356a0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140037910(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140037950(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140038ce4(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
cri_u4 FUN_140043f70(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
cri_u8 FUN_140043fe0(cri_any = cri_any(), cri_any = cri_any());
void FUN_140044050(cri_any = cri_any(), cri_any = cri_any());
cri_u4 FUN_140044950(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
cri_u8 FUN_1400449c0(cri_any = cri_any(), cri_any = cri_any());
void FUN_140044a30(cri_any = cri_any(), cri_any = cri_any());
void FUN_140050210(cri_any = cri_any(), cri_any = cri_any());
cri_u8 FUN_140050820(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
cri_u4 FUN_140051ec0(longlong *, uint *);
void FUN_140054320(cri_any = cri_any());
void FUN_14005dc70(cri_any = cri_any(), cri_any = cri_any());
void FUN_1400627f0(cri_any = cri_any());
cri_u8 FUN_140062830();
int FUN_140062860();
void FUN_140064dd0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140065800();
int FUN_140065940(int);
void FUN_1400659a0(const cri_u1 *, cri_u1 *);
void FUN_1400659f0();
void FUN_140066180(longlong);
void FUN_1400661e0();
void FUN_140066320();
void FUN_140066350(longlong);
void FUN_140066360();
void FUN_140066370(longlong);
void FUN_1400663b0(longlong);
void FUN_1400663d0(longlong, cri_u4 *, cri_u4 *);
void FUN_1400663f0(longlong);
int FUN_140066400(longlong);
void FUN_140066460(longlong, uint);
void FUN_140066a10(longlong, uint);
void FUN_140066c60(longlong, int);
void FUN_140066d80(cri_u8);
void FUN_140066da0(cri_u8);
void FUN_140066de0(cri_u8);
void FUN_140066e10(longlong);
void FUN_140066e70();
void FUN_140066e90(longlong, int);
void FUN_140066f30(longlong, int);
void FUN_140066f60(longlong);
void FUN_140066f80(longlong);
void FUN_140066fe0(longlong, cri_u1 *, longlong);
void FUN_140067100(longlong);
void FUN_140067210(longlong);
void FUN_1400672b0(longlong);
void FUN_140067370(cri_u8);
void FUN_140067390(longlong);
void FUN_140067420(longlong);
void FUN_140067470(longlong);
char * FUN_1400674d0(char *, size_t, const char *);
char * FUN_140067510(char *, size_t, const char *, size_t);
char * FUN_140067550(char *, size_t, const char *, size_t);
char * FUN_140067590(char *, size_t, const char *);
int FUN_1400675d0(char *, size_t, const char *, ...);
int FUN_140067630(const char *, const char *, ...);
void FUN_140067680(char *, size_t, const char *, va_list);
FILE * FUN_1400676c0(const char *, const char *);
void FUN_140067700();
void FUN_140067750();
void FUN_140067790();
void FUN_1400677c0();
void FUN_1400677f0();
void FUN_140067840();
cri_u8 FUN_140067890(cri_u8, cri_u4);
cri_u8 FUN_1400678d0(longlong, uint);
void FUN_140067a90(cri_u8);
void FUN_140067ac0(void *);
cri_u4 FUN_140067bf0(cri_u8);
int FUN_140067c20(int *);
cri_u4 FUN_140067c90(cri_u8, cri_u8, cri_u8);
int FUN_140067cd0(int *, cri_u8, cri_u8);
void FUN_140067dd0(cri_u8, cri_u4);
void FUN_140067e00(int *, cri_u4);
cri_u4 FUN_140067e80(cri_u8, cri_u4);
int FUN_140067ec0(int *, int);
cri_u4 FUN_140067f40(cri_u8);
int FUN_140067f70(int *);
void FUN_140067fc0(cri_u8, cri_u4);
void FUN_140067ff0(int *, int);
void FUN_140068070(cri_u8, cri_u4);
void FUN_1400680a0(int *, uint);
cri_u8 FUN_140068190(longlong);
cri_u8 FUN_140068200(cri_u8);
cri_u8 FUN_140068210(longlong);
void FUN_140068280(const char *);
void FUN_1400682a0();
void FUN_1400682c0();
cri_u8 FUN_1400682e0(longlong, int);
void FUN_140068380(LPCRITICAL_SECTION);
cri_u4 FUN_1400683d0(LPCRITICAL_SECTION);
cri_u4 FUN_140068430(LPCRITICAL_SECTION);
void FUN_140068490(short *, int *, longlong);
void FUN_140068590(longlong *, longlong, uint);
void FUN_1400686c0(longlong *, longlong, uint);
void FUN_140068840(int *, longlong *, longlong *);
void FUN_1400688f0(longlong, longlong, int *);
void FUN_140068920(longlong, int);
void FUN_140068960(longlong);
void FUN_140068990(longlong);
void FUN_140068a40(longlong, longlong, int *, longlong *, longlong);
void FUN_140068cc0(longlong, int);
void FUN_140068d50(longlong, int);
void FUN_140068db0(longlong);
void FUN_140068e70(longlong);
void FUN_140068f30(longlong);
void FUN_140069020(longlong *, int, longlong *, longlong *);
void FUN_140069060(uint, char *);
int FUN_1400690e0(char *);
void FUN_140069140(longlong *, cri_u8);
void FUN_140069190(longlong, longlong *);
char * FUN_1400691b0(longlong *, char *, char *, cri_u8 *);
cri_u8 FUN_140069270(longlong, cri_u8 *, cri_u8);
cri_u8 FUN_140069480(longlong, cri_u8 *, cri_u8 *, cri_u8 *);
int FUN_140069844(longlong, int, byte *, uint, int *, uint, longlong *, uint);
int FUN_140069ac4(longlong, int, byte *, uint, int *, uint, longlong *, uint);
void FUN_140069e44(longlong);
void FUN_140069e54(longlong, int);
void FUN_140069e5c(longlong, int, int, int);
void FUN_140069e98(longlong, uint, short, short);
void FUN_140069ef4(longlong, uint, uint);
int FUN_14006a090(cri_u1 *, uint);
int FUN_14006a110(short *, uint, cri_u1 *, cri_u1 *);
cri_u8 FUN_14006a16c(cri_u1 *, uint, short *, cri_u1 *, char *, char *, cri_u1 *, cri_u4 *, cri_u4 *, int *);
cri_u8 FUN_14006a260(longlong, cri_u8, ushort *, ushort *);
cri_u8 FUN_14006a388(longlong, cri_u8, uint *, ushort *, ushort *, uint *, uint *, uint *, uint *);
cri_u8 FUN_14006a598(longlong, cri_u8, uint *, void *, ushort *, ushort *);
int FUN_14006a750(short *, int, ushort *);
uint FUN_14006a7f8(cri_u8, uint, longlong);
cri_u2 FUN_14006a928(cri_u8, cri_u4, longlong);
void FUN_14006aa90();
void FUN_14006aaa0(V16 *, V16 *, int);
longlong FUN_14006b0d0(longlong);
longlong FUN_140073c80(longlong);
longlong FUN_14007ba60(longlong);
longlong FUN_140083350(longlong);
void FUN_140089e90(longlong, cri_u8, cri_u4 *);
void * FUN_140089f60(void *, int);
void FUN_140089fe0(longlong, cri_u8);
void FUN_14008a180(longlong, cri_u8, int *);
void FUN_14008a2b0(longlong);
void FUN_14008a3c0(longlong);
void FUN_14008a430(longlong, int, int);
void FUN_14008a5b0(longlong, int, int);
void FUN_14008a730(longlong, uint, int, int, int);
void FUN_14008a830(longlong, int *, int *, int, int);
void FUN_14008a970(longlong, uint);
void FUN_14008aa80(longlong, cri_u4, cri_u4);
void FUN_14008ab00(longlong);
void FUN_14008ab40(longlong);
void FUN_14008ab60(longlong, cri_u4, int);
void FUN_14008b6b0(longlong, longlong, int, cri_u4, uint, cri_u4, int, int, uint, uint, int);
void FUN_14008b780(longlong, longlong, int, cri_u8, int, int, int, int, uint, uint, int);
void FUN_14008c150(longlong, longlong *, int, longlong *, int, byte, byte, int, int, int, int, int, int, cri_u4);
void FUN_14008c400(longlong, longlong *, int, longlong *, int, byte, byte, int, int, int, int, int, int, cri_u4);
void FUN_14008c780(longlong);
void FUN_14008c7b0(longlong);
void FUN_14008c7e0(longlong);
void FUN_14008c800(longlong, cri_u4 *, cri_u4 *);
void FUN_14008c820(longlong);
int FUN_14008c830(longlong);
void FUN_14008c890(longlong, uint);
void FUN_14008ce50(longlong, uint);
void FUN_14008d0b0(longlong, int);
void FUN_14008d220(cri_u8);
void FUN_14008d240(cri_u8);
void FUN_14008d280(cri_u8);
void FUN_14008d2a0(longlong *, longlong *, longlong, longlong);
void FUN_14008e570(longlong *, longlong *, longlong, longlong);
void FUN_14008fa50(longlong *, longlong *, longlong, longlong);
void FUN_140090080(longlong *, longlong *, longlong, longlong);
void FUN_140090730(cri_u8 *, longlong *, cri_u8, longlong);
void FUN_140090f20(cri_u8 *, cri_u8 *);
void FUN_140091df0(cri_u8 *, longlong *);
void FUN_1400923d0(cri_u8 *, longlong *);
void FUN_1400927c0(byte *, byte *, cri_u8, cri_u8);
void FUN_140092850(byte *, byte *, cri_u8, cri_u8);
void FUN_1400928e0(byte *, byte *, cri_u8, cri_u8);
void FUN_140092970(longlong, longlong);
void FUN_140093150(longlong, longlong);
void FUN_140093890(void *, int, int);
void FUN_140093940(void *, byte, byte, int);
void FUN_140093cf0();
void FUN_140093ec0(longlong, longlong);
void FUN_1400946b0(longlong, longlong);
void FUN_140094df0(void *, int, int);
void FUN_140094ea0(void *, byte, byte, int);
void FUN_140095250();
cri_u8 FUN_140095430();
void FUN_140095440(cri_u8, cri_u8);
void FUN_140095450(cri_u4);
void FUN_140095480();
void FUN_140095590(void *, void *, void *);
void FUN_140095800(void *, void *);
void FUN_140095810(void *, void *);
void FUN_140095820(longlong, cri_u2 *);
void FUN_1400959a0(longlong, cri_u2 *);
void FUN_140095b20();
uint FUN_140095b40(longlong, uint *);
uint FUN_14009a3d0(longlong, uint *);
uint FUN_14009ec40(longlong, uint *);
uint FUN_1400a3920(longlong, uint *);
uint FUN_1400a8ad0(longlong, uint *);
uint FUN_1400adc50(longlong, uint *);
void FUN_1400afd20();
void FUN_1400afd30(uint);
void FUN_1400afd70();
void FUN_1400afde0(const char *, ...);
void FUN_1400afe60(const char *);
void FUN_1400afed0(const char *, const char *);
void FUN_1400aff40(int);
cri_u8 FUN_1400affc0();
void FUN_1400b0090();
int FUN_1400b0130();
void FUN_1400b01f0();
void FUN_1400b0210();
void FUN_1400b0240(int);
void FUN_1400b0290(int);
void FUN_1400b02e0(int);
void FUN_1400b0340();
uint FUN_1400b03a0(uint, longlong, longlong, char *);
void FUN_1400b0470(uint, uint);
void FUN_1400b0500(uint, uint, cri_u8, cri_u8, char *);
void FUN_1400b05c0(int, cri_u8, cri_u8);
uint FUN_1400b0610(int);
cri_u4 FUN_1400b06c0(uint, uint);
uint FUN_1400b07d0(int *, cri_u8, cri_u8, cri_u8);
cri_u4 FUN_1400b0820(uint, longlong, longlong, char *);
void FUN_1400b0880(uint, uint);
void FUN_1400b08b0(uint, uint, cri_u8, cri_u8, char *);
void FUN_1400b0920(uint, uint, cri_u8, cri_u8);
void FUN_1400b09a0(const char *);
void FUN_1400b0a10(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_1400b1720(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_1400b1e50(cri_any = cri_any(), cri_any = cri_any(), ...);
int FUN_14029dd60(const char *, const char *, ...);   // game code's legacy inline sscanf
cri_u8 * FUN_142096410(cri_any = cri_any());

void FUN_140066180(longlong arg1);

void FUN_1400661e0();
void FUN_1400662e0(char *ctx);

void FUN_1400662f0(char *ctx);

void FUN_140066300(char *ctx);

void FUN_140066310(char *ctx);


void FUN_140066320();

void FUN_140066350(longlong arg1);

void FUN_140066360();

void FUN_140066370(longlong arg1);

void FUN_1400663b0(longlong arg1);

void FUN_1400663d0(longlong arg1, cri_u4 *arg2, cri_u4 *arg3);

void FUN_1400663f0(longlong arg1);

int FUN_140066400(longlong arg1);

void FUN_140066460(longlong arg1, uint arg2);

void FUN_140066a10(longlong arg1, uint arg2);

void FUN_140066c60(longlong arg1, int arg2);

void FUN_140066d80(cri_u8 arg1);

void FUN_140066da0(cri_u8 arg1);

void FUN_140066de0(cri_u8 arg1);

uint FUN_140066e00(longlong a1, uint a2);

void FUN_140066e10(longlong arg1);

void FUN_140066e70();

void FUN_140066e90(longlong arg1, int arg2);

void FUN_140066f30(longlong arg1, int arg2);

void FUN_140066f60(longlong arg1);

void FUN_140066f80(longlong arg1);

void FUN_140066fe0(longlong arg1, cri_u1 *arg2, longlong arg3);

// The 32-byte table FUN_140067100 copies to +0x12a0 (exe .rdata 0x1431bbe00, inside data_cri's DAT_1431bbdc1 piece).
struct cri07_tbl32 { cri_u8 q[4]; };

void FUN_140067100(longlong arg1);

void FUN_140067210(longlong arg1);

void FUN_1400672b0(longlong arg1);

void FUN_140067370(cri_u8 arg1);

void FUN_140067390(longlong arg1);

void FUN_140067420(longlong arg1);

void FUN_140067470(longlong arg1);

void thunk_FUN_140067390(longlong arg1);

void thunk_FUN_1400afe60(const char *arg1);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
char * FUN_1400674d0(char *dst, size_t size, const char *src);

char * FUN_140067510(char *dst, size_t size, const char *src, size_t count);

char * FUN_140067550(char *dst, size_t size, const char *src, size_t count);

char * FUN_140067590(char *dst, size_t size, const char *src);

int FUN_1400675d0(char *_Dest,size_t _Count,const char *_Format,...);

int FUN_140067630(const char *buf, const char *format, ...);

void FUN_140067680(char *arg1,size_t arg2,const char *arg3,va_list arg4);

FILE * FUN_1400676c0(const char *name, const char *mode);
#pragma optimize("", on)

void FUN_140067700();

void FUN_140067750();

void FUN_140067790();

void FUN_1400677c0();

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
void FUN_1400677f0();

void FUN_140067840();

cri_u8 FUN_140067890(cri_u8 arg1, cri_u4 arg2);

cri_u8 FUN_1400678d0(longlong arg1, uint arg2);

void FUN_140067a90(cri_u8 arg1);

#pragma function(memset)                      // the exe obj calls memset here
void FUN_140067ac0(void *arg1);
#pragma intrinsic(memset)

cri_u4 FUN_140067bf0(cri_u8 arg1);

int FUN_140067c20(int *arg1);

cri_u4 FUN_140067c90(cri_u8 arg1, cri_u8 arg2, cri_u8 arg3);

int FUN_140067cd0(int *arg1, cri_u8 arg2, cri_u8 arg3);

void FUN_140067dd0(cri_u8 arg1, cri_u4 arg2);

void FUN_140067e00(int *arg1, cri_u4 arg2);

cri_u4 FUN_140067e80(cri_u8 arg1, cri_u4 arg2);

int FUN_140067ec0(int *arg1, int arg2);

cri_u4 FUN_140067f40(cri_u8 arg1);

int FUN_140067f70(int *arg1);

void FUN_140067fc0(cri_u8 arg1, cri_u4 arg2);

void FUN_140067ff0(int *arg1, int arg2);

void FUN_140068070(cri_u8 arg1, cri_u4 arg2);

void FUN_1400680a0(int *arg1, uint arg2);

cri_u8 FUN_140068190(longlong arg1);

cri_u8 FUN_140068200(cri_u8 arg1);

cri_u8 FUN_140068210(longlong arg1);

void FUN_140068280(const char *arg1);

void FUN_1400682a0();

void FUN_1400682c0();

#pragma function(memset)                      // the exe obj calls memset here
cri_u8 FUN_1400682e0(longlong arg1, int arg2);
#pragma intrinsic(memset)

#pragma function(memset)                      // the exe obj calls memset here
void FUN_140068380(LPCRITICAL_SECTION arg1);
#pragma intrinsic(memset)

cri_u4 FUN_1400683d0(LPCRITICAL_SECTION arg1);

cri_u4 FUN_140068430(LPCRITICAL_SECTION arg1);
#pragma optimize("", on)

void FUN_140068490(short *arg1, int *arg2, longlong arg3);

void FUN_140068590(longlong *arg1, longlong arg2, uint arg3);

void FUN_1400686c0(longlong *arg1, longlong arg2, uint arg3);

void FUN_140068840(int *arg1, longlong *arg2, longlong *arg3);

void FUN_1400688f0(longlong arg1, longlong arg2, int *arg3);

void FUN_140068920(longlong arg1, int arg2);

void FUN_140068960(longlong arg1);

void FUN_140068990(longlong arg1);

void FUN_140068a40(longlong arg1, longlong arg2, int *arg3, longlong *arg4, longlong arg5);

void FUN_140068cc0(longlong arg1, int arg2);

void FUN_140068d50(longlong arg1, int arg2);

void FUN_140068db0(longlong arg1);

void FUN_140068e70(longlong arg1);

void FUN_140068f30(longlong arg1);

void FUN_140069020(longlong *arg1, int arg2, longlong *arg3, longlong *arg4);

void FUN_140069060(uint arg1, char *arg2);

int FUN_1400690e0(char *arg1);

void FUN_140069140(longlong *arg1, cri_u8 arg2);

void FUN_140069190(longlong arg1, longlong *arg2);

char * FUN_1400691b0(longlong *arg1, char *arg2, char *arg3, cri_u8 *arg4);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
cri_u8 FUN_140069270(longlong arg1, cri_u8 *arg2, cri_u8 arg3);

cri_u8 FUN_140069480(longlong arg1, cri_u8 *arg2, cri_u8 *arg3, cri_u8 *arg4);
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
int FUN_140069844(longlong cri_p0, int cri_p1, byte *cri_p2, uint cri_p3, int *cri_p4, uint cri_p5, longlong *cri_p6, uint cri_p7);

int FUN_140069ac4(longlong cri_p0, int cri_p1, byte *cri_p2, uint cri_p3, int *cri_p4, uint cri_p5, longlong *cri_p6, uint cri_p7);

void FUN_140069e44(longlong cri_p0);

void FUN_140069e54(longlong cri_p0, int cri_p1);

void FUN_140069e5c(longlong cri_p0, int cri_p1, int cri_p2, int cri_p3);

void FUN_140069e98(longlong cri_p0, uint cri_p1, short cri_p2, short cri_p3);

void FUN_140069ef4(longlong cri_p0, uint cri_p1, uint cri_p2);

#pragma function(strlen, memcmp)                // the exe calls strlen and memcmp here rather than expanding them
int FUN_14006a090(cri_u1 *arg1, uint arg2);
#pragma intrinsic(strlen, memcmp)

int FUN_14006a110(short *arg1, uint arg2, cri_u1 *arg3, cri_u1 *arg4);

cri_u8 FUN_14006a16c(cri_u1 *arg1, uint arg2, short *arg3, cri_u1 *arg4, char *arg5, char *arg6, cri_u1 *arg7, cri_u4 *arg8, cri_u4 *arg9, int *arg10);

cri_u8 FUN_14006a260(longlong arg1, cri_u8 arg2, ushort *arg3, ushort *arg4);

cri_u8 FUN_14006a388(longlong arg1, cri_u8 arg2, uint *arg3, ushort *arg4, ushort *arg5, uint *arg6, uint *arg7, uint *arg8, uint *arg9);

cri_u8 FUN_14006a598(longlong arg1, cri_u8 arg2, uint *arg3, void *arg4, ushort *arg5, ushort *arg6);

int FUN_14006a750(short *arg1, int arg2, ushort *arg3);

uint FUN_14006a7f8(cri_u8 cri_p0, uint cri_p1, longlong cri_p2);

cri_u2 FUN_14006a928(cri_u8 arg1, cri_u4 arg2, longlong arg3);
#pragma optimize("", on)

// The DC rounding hook FUN_140066e10 stores in DAT_143d4ee08 (Ghidra made no function here): src's coefficient divided
// by 8, rounded half away from 0, into dst.
// MS2-FUNCTIONAL: written from the exe (VS2008 build, our toolset differs).
// @0x14006aa60
void FUN_14006aa60(short *src, short *dst)
{
  int c = *src;
  if (c >= 0) {
    *dst = (short)((c + 4) >> 3);
  }
  else {
    *dst = (short)-((4 - c) >> 3);
  }
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14006aa90
void FUN_14006aa90()
{
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14006aaa0
void FUN_14006aaa0(V16 *arg1, V16 *arg2, int arg3)
{
  short s_v1;
  ushort u_v2;
  cri_u4 u_v3;
  cri_u4 u_v11;
  cri_u1 in_XMM0 [16];
  V16 au_v4;
  V16 au_v5;
  V16 au_v6;
  V16 au_v7;
  V16 au_v8;
  V16 au_v9;
  V16 au_v10;
  V16 au_v12;
  V16 au_v13;
  V16 au_v14;
  V16 au_v15;
  V16 au_v16;
  V16 au_v17;
  V16 au_v18;
  V16 au_v19;
  V16 au_v20;
  cri_u1 in_XMM2 [16];
  V16 au_v21;
  V16 au_v22;
  V16 au_v23;
  V16 au_v24;
  V16 au_v25;
  V16 au_v26;
  int i_v27;
  int i_v32;
  int i_v33;
  V16 au_v28;
  int i_v34;
  V16 au_v29;
  V16 au_v30;
  V16 au_v31;
  int i_v35;
  int i_v44;
  int i_v45;
  V16 au_v36;
  V16 au_v37;
  V16 au_v38;
  int i_v46;
  V16 au_v39;
  V16 au_v40;
  V16 au_v41;
  V16 au_v42;
  V16 au_v43;
  int i_v47;
  int i_v52;
  int i_v53;
  cri_u4 u_v54;
  V16 au_v48;
  V16 au_v49;
  int i_v55;
  V16 au_v50;
  V16 au_v51;
  cri_u4 u_v56;
  cri_u1 unaf_XMM6 [16];
  V16 au_v57;
  V16 au_v58;
  V16 au_v59;
  int i_v60;
  int i_v65;
  int i_v66;
  V16 au_v61;
  V16 au_v62;
  int i_v67;
  V16 au_v63;
  V16 au_v64;
  V16 au_v68;
  V16 au_v69;
  V16 au_v70;
  V16 au_v71;
  V16 au_v72;
  ulonglong loc_78;
  cri_u8 uStack_70;
  
  if (arg3 == 0) {
    s_v1 = *(short *)arg1->b;
    if (s_v1 < 0) {
      u_v2 = -(short)(4 - s_v1 >> 3);
    }
    else {
      u_v2 = (ushort)(s_v1 + 4 >> 3);
    }
    CRI_PART(au_v4,8,8) = uStack_70;
    CRI_PART(au_v4,0,8) = loc_78 & 0xffffffffffff0000 | (ulonglong)u_v2;
    au_v5 = pshuflw(au_v4,au_v4,0);
    u_v3 = CRI_PART(au_v5,0,4);
    *(cri_u4 *)arg2->b = u_v3;
    *(cri_u4 *)(arg2->b + 4) = u_v3;
    *(cri_u4 *)(arg2->b + 8) = u_v3;
    *(cri_u4 *)(arg2->b + 0xc) = u_v3;
    *(cri_u4 *)arg2[1].b = u_v3;
    *(cri_u4 *)(arg2[1].b + 4) = u_v3;
    *(cri_u4 *)(arg2[1].b + 8) = u_v3;
    *(cri_u4 *)(arg2[1].b + 0xc) = u_v3;
    *(cri_u4 *)arg2[2].b = u_v3;
    *(cri_u4 *)(arg2[2].b + 4) = u_v3;
    *(cri_u4 *)(arg2[2].b + 8) = u_v3;
    *(cri_u4 *)(arg2[2].b + 0xc) = u_v3;
    *(cri_u4 *)arg2[3].b = u_v3;
    *(cri_u4 *)(arg2[3].b + 4) = u_v3;
    *(cri_u4 *)(arg2[3].b + 8) = u_v3;
    *(cri_u4 *)(arg2[3].b + 0xc) = u_v3;
    *(cri_u4 *)arg2[4].b = u_v3;
    *(cri_u4 *)(arg2[4].b + 4) = u_v3;
    *(cri_u4 *)(arg2[4].b + 8) = u_v3;
    *(cri_u4 *)(arg2[4].b + 0xc) = u_v3;
    *(cri_u4 *)arg2[5].b = u_v3;
    *(cri_u4 *)(arg2[5].b + 4) = u_v3;
    *(cri_u4 *)(arg2[5].b + 8) = u_v3;
    *(cri_u4 *)(arg2[5].b + 0xc) = u_v3;
    *(cri_u4 *)arg2[6].b = u_v3;
    *(cri_u4 *)(arg2[6].b + 4) = u_v3;
    *(cri_u4 *)(arg2[6].b + 8) = u_v3;
    *(cri_u4 *)(arg2[6].b + 0xc) = u_v3;
    *(cri_u4 *)arg2[7].b = u_v3;
    *(cri_u4 *)(arg2[7].b + 4) = u_v3;
    *(cri_u4 *)(arg2[7].b + 8) = u_v3;
    *(cri_u4 *)(arg2[7].b + 0xc) = u_v3;
    return;
  }
  au_v5 = pshuflw(in_XMM0,*arg1,0xd8);
  au_v21 = pshufhw(in_XMM2,au_v5,0xd8);
  u_v3 = CRI_PART(au_v5,0,4);
  u_v11 = CRI_PART(au_v5,4,4);
  CRI_PART(au_v36,4,4) = u_v11;
  CRI_PART(au_v36,0,4) = u_v11;
  CRI_PART(au_v36,8,4) = u_v11;
  CRI_PART(au_v36,12,4) = u_v11;
  CRI_PART(au_v61,4,4) = u_v3;
  CRI_PART(au_v61,0,4) = u_v3;
  CRI_PART(au_v61,8,4) = u_v3;
  CRI_PART(au_v61,12,4) = u_v3;
  au_v5 = pshufhw(au_v5,arg1[2],0xd8);
  u_v3 = CRI_PART(au_v21,8,4);
  u_v11 = CRI_PART(au_v21,12,4);
  CRI_PART(au_v48,4,4) = u_v11;
  CRI_PART(au_v48,0,4) = u_v11;
  CRI_PART(au_v48,8,4) = u_v11;
  CRI_PART(au_v48,12,4) = u_v11;
  au_v21 = pmaddwd(au_v36,_DAT_143a4a4c0);
  au_v62 = pmaddwd(au_v61,_DAT_143a4a4a0);
  au_v49 = pmaddwd(au_v48,_DAT_143a4a4d0);
  i_v47 = CRI_PART(au_v49,0,4) + CRI_PART(au_v21,0,4);
  i_v52 = CRI_PART(au_v49,4,4) + CRI_PART(au_v21,4,4);
  i_v53 = CRI_PART(au_v49,8,4) + CRI_PART(au_v21,8,4);
  i_v55 = CRI_PART(au_v49,12,4) + CRI_PART(au_v21,12,4);
  au_v57 = pshuflw(unaf_XMM6,au_v5,0xd8);
  CRI_PART(au_v12,4,4) = u_v3;
  CRI_PART(au_v12,0,4) = u_v3;
  CRI_PART(au_v12,8,4) = u_v3;
  CRI_PART(au_v12,12,4) = u_v3;
  u_v3 = CRI_PART(au_v57,0,4);
  u_v11 = CRI_PART(au_v57,4,4);
  u_v54 = CRI_PART(au_v57,8,4);
  u_v56 = CRI_PART(au_v57,12,4);
  CRI_PART(au_v37,4,4) = u_v3;
  CRI_PART(au_v37,0,4) = u_v3;
  CRI_PART(au_v37,8,4) = u_v3;
  CRI_PART(au_v37,12,4) = u_v3;
  CRI_PART(au_v5,4,4) = u_v54;
  CRI_PART(au_v5,0,4) = u_v54;
  CRI_PART(au_v5,8,4) = u_v54;
  CRI_PART(au_v5,12,4) = u_v54;
  au_v5 = pmaddwd(au_v5,_DAT_143a4a530);
  au_v38 = pmaddwd(au_v37,_DAT_143a4a520);
  au_v21 = pmaddwd(au_v12,_DAT_143a4a4b0);
  i_v60 = CRI_PART(au_v62,0,4) + _DAT_143a4a430 + CRI_PART(au_v21,0,4);
  i_v65 = CRI_PART(au_v62,4,4) + iRam0000000143a4a434 + CRI_PART(au_v21,4,4);
  i_v66 = CRI_PART(au_v62,8,4) + iRam0000000143a4a438 + CRI_PART(au_v21,8,4);
  i_v67 = CRI_PART(au_v62,12,4) + iRam0000000143a4a43c + CRI_PART(au_v21,12,4);
  CRI_PART(au_v28,4,4) = u_v56;
  CRI_PART(au_v28,0,4) = u_v56;
  CRI_PART(au_v28,8,4) = u_v56;
  CRI_PART(au_v28,12,4) = u_v56;
  au_v49 = pmaddwd(au_v28,_DAT_143a4a550);
  i_v35 = CRI_PART(au_v38,0,4) + _DAT_143a4a430 + CRI_PART(au_v5,0,4);
  i_v44 = CRI_PART(au_v38,4,4) + iRam0000000143a4a434 + CRI_PART(au_v5,4,4);
  i_v45 = CRI_PART(au_v38,8,4) + iRam0000000143a4a438 + CRI_PART(au_v5,8,4);
  i_v46 = CRI_PART(au_v38,12,4) + iRam0000000143a4a43c + CRI_PART(au_v5,12,4);
  CRI_PART(au_v13,0,4) = i_v47 + i_v60 >> 0xc;
  CRI_PART(au_v13,4,4) = i_v52 + i_v65 >> 0xc;
  CRI_PART(au_v13,8,4) = i_v53 + i_v66 >> 0xc;
  CRI_PART(au_v13,12,4) = i_v55 + i_v67 >> 0xc;
  CRI_PART(au_v21,4,4) = u_v11;
  CRI_PART(au_v21,0,4) = u_v11;
  CRI_PART(au_v21,8,4) = u_v11;
  CRI_PART(au_v21,12,4) = u_v11;
  au_v5 = pmaddwd(au_v21,_DAT_143a4a540);
  i_v27 = CRI_PART(au_v49,0,4) + CRI_PART(au_v5,0,4);
  i_v32 = CRI_PART(au_v49,4,4) + CRI_PART(au_v5,4,4);
  i_v33 = CRI_PART(au_v49,8,4) + CRI_PART(au_v5,8,4);
  i_v34 = CRI_PART(au_v49,12,4) + CRI_PART(au_v5,12,4);
  CRI_PART(au_v49,4,4) = i_v66 - i_v53 >> 0xc;
  CRI_PART(au_v49,0,4) = i_v67 - i_v55 >> 0xc;
  CRI_PART(au_v49,8,4) = i_v65 - i_v52 >> 0xc;
  CRI_PART(au_v49,12,4) = i_v60 - i_v47 >> 0xc;
  au_v5 = packssdw(au_v13,au_v49);
  *arg2 = au_v5;
  CRI_PART(au_v22,0,4) = i_v27 + i_v35 >> 0xc;
  CRI_PART(au_v22,4,4) = i_v32 + i_v44 >> 0xc;
  CRI_PART(au_v22,8,4) = i_v33 + i_v45 >> 0xc;
  CRI_PART(au_v22,12,4) = i_v34 + i_v46 >> 0xc;
  CRI_PART(au_v38,4,4) = i_v45 - i_v33 >> 0xc;
  CRI_PART(au_v38,0,4) = i_v46 - i_v34 >> 0xc;
  CRI_PART(au_v38,8,4) = i_v44 - i_v32 >> 0xc;
  CRI_PART(au_v38,12,4) = i_v35 - i_v27 >> 0xc;
  au_v21 = packssdw(au_v22,au_v38);
  arg2[2] = au_v21;
  au_v5 = pshuflw(au_v38,arg1[4],0xd8);
  au_v21 = pshufhw(au_v21,au_v5,0xd8);
  u_v3 = CRI_PART(au_v5,0,4);
  u_v11 = CRI_PART(au_v5,4,4);
  CRI_PART(au_v39,4,4) = u_v11;
  CRI_PART(au_v39,0,4) = u_v11;
  CRI_PART(au_v39,8,4) = u_v11;
  CRI_PART(au_v39,12,4) = u_v11;
  CRI_PART(au_v63,4,4) = u_v3;
  CRI_PART(au_v63,0,4) = u_v3;
  CRI_PART(au_v63,8,4) = u_v3;
  CRI_PART(au_v63,12,4) = u_v3;
  au_v49 = pmaddwd(au_v39,_DAT_143a4a4c0);
  au_v38 = pmaddwd(au_v63,_DAT_143a4a4a0);
  au_v5 = pshufhw(au_v5,arg1[6],0xd8);
  u_v3 = CRI_PART(au_v21,8,4);
  u_v11 = CRI_PART(au_v21,12,4);
  CRI_PART(au_v50,4,4) = u_v11;
  CRI_PART(au_v50,0,4) = u_v11;
  CRI_PART(au_v50,8,4) = u_v11;
  CRI_PART(au_v50,12,4) = u_v11;
  au_v21 = pmaddwd(au_v50,_DAT_143a4a4d0);
  au_v5 = pshuflw(au_v57,au_v5,0xd8);
  CRI_PART(au_v51,0,4) = CRI_PART(au_v21,0,4) + CRI_PART(au_v49,0,4);
  CRI_PART(au_v51,4,4) = CRI_PART(au_v21,4,4) + CRI_PART(au_v49,4,4);
  CRI_PART(au_v51,8,4) = CRI_PART(au_v21,8,4) + CRI_PART(au_v49,8,4);
  CRI_PART(au_v51,12,4) = CRI_PART(au_v21,12,4) + CRI_PART(au_v49,12,4);
  CRI_PART(au_v14,4,4) = u_v3;
  CRI_PART(au_v14,0,4) = u_v3;
  CRI_PART(au_v14,8,4) = u_v3;
  CRI_PART(au_v14,12,4) = u_v3;
  au_v21 = pmaddwd(au_v14,_DAT_143a4a4b0);
  u_v3 = CRI_PART(au_v5,0,4);
  u_v11 = CRI_PART(au_v5,4,4);
  u_v54 = CRI_PART(au_v5,8,4);
  u_v56 = CRI_PART(au_v5,12,4);
  CRI_PART(au_v40,4,4) = u_v3;
  CRI_PART(au_v40,0,4) = u_v3;
  CRI_PART(au_v40,8,4) = u_v3;
  CRI_PART(au_v40,12,4) = u_v3;
  CRI_PART(au_v57,4,4) = u_v54;
  CRI_PART(au_v57,0,4) = u_v54;
  CRI_PART(au_v57,8,4) = u_v54;
  CRI_PART(au_v57,12,4) = u_v54;
  au_v5 = pmaddwd(au_v57,_DAT_143a4a530);
  au_v49 = pmaddwd(au_v40,_DAT_143a4a520);
  i_v47 = CRI_PART(au_v38,0,4) + _DAT_143a4a430 + CRI_PART(au_v21,0,4);
  i_v52 = CRI_PART(au_v38,4,4) + iRam0000000143a4a434 + CRI_PART(au_v21,4,4);
  i_v53 = CRI_PART(au_v38,8,4) + iRam0000000143a4a438 + CRI_PART(au_v21,8,4);
  i_v55 = CRI_PART(au_v38,12,4) + iRam0000000143a4a43c + CRI_PART(au_v21,12,4);
  CRI_PART(au_v29,4,4) = u_v56;
  CRI_PART(au_v29,0,4) = u_v56;
  CRI_PART(au_v29,8,4) = u_v56;
  CRI_PART(au_v29,12,4) = u_v56;
  au_v21 = pmaddwd(au_v29,_DAT_143a4a550);
  i_v35 = CRI_PART(au_v49,0,4) + _DAT_143a4a430 + CRI_PART(au_v5,0,4);
  i_v44 = CRI_PART(au_v49,4,4) + iRam0000000143a4a434 + CRI_PART(au_v5,4,4);
  i_v45 = CRI_PART(au_v49,8,4) + iRam0000000143a4a438 + CRI_PART(au_v5,8,4);
  i_v46 = CRI_PART(au_v49,12,4) + iRam0000000143a4a43c + CRI_PART(au_v5,12,4);
  CRI_PART(au_v62,4,4) = u_v11;
  CRI_PART(au_v62,0,4) = u_v11;
  CRI_PART(au_v62,8,4) = u_v11;
  CRI_PART(au_v62,12,4) = u_v11;
  au_v5 = pmaddwd(au_v62,_DAT_143a4a540);
  CRI_PART(au_v15,0,4) = (int)CRI_PART(au_v51,0,4) + i_v47 >> 0xc;
  CRI_PART(au_v15,4,4) = (int)CRI_PART(au_v51,4,4) + i_v52 >> 0xc;
  CRI_PART(au_v15,8,4) = (int)CRI_PART(au_v51,8,4) + i_v53 >> 0xc;
  CRI_PART(au_v15,12,4) = (int)CRI_PART(au_v51,12,4) + i_v55 >> 0xc;
  i_v27 = CRI_PART(au_v21,0,4) + CRI_PART(au_v5,0,4);
  i_v32 = CRI_PART(au_v21,4,4) + CRI_PART(au_v5,4,4);
  i_v33 = CRI_PART(au_v21,8,4) + CRI_PART(au_v5,8,4);
  i_v34 = CRI_PART(au_v21,12,4) + CRI_PART(au_v5,12,4);
  CRI_PART(au_v69,4,4) = i_v53 - (int)CRI_PART(au_v51,8,4) >> 0xc;
  CRI_PART(au_v69,0,4) = i_v55 - (int)CRI_PART(au_v51,12,4) >> 0xc;
  CRI_PART(au_v69,8,4) = i_v52 - (int)CRI_PART(au_v51,4,4) >> 0xc;
  CRI_PART(au_v69,12,4) = i_v47 - (int)CRI_PART(au_v51,0,4) >> 0xc;
  au_v5 = packssdw(au_v15,au_v69);
  arg2[4] = au_v5;
  CRI_PART(au_v23,0,4) = i_v27 + i_v35 >> 0xc;
  CRI_PART(au_v23,4,4) = i_v32 + i_v44 >> 0xc;
  CRI_PART(au_v23,8,4) = i_v33 + i_v45 >> 0xc;
  CRI_PART(au_v23,12,4) = i_v34 + i_v46 >> 0xc;
  CRI_PART(au_v71,4,4) = i_v45 - i_v33 >> 0xc;
  CRI_PART(au_v71,0,4) = i_v46 - i_v34 >> 0xc;
  CRI_PART(au_v71,8,4) = i_v44 - i_v32 >> 0xc;
  CRI_PART(au_v71,12,4) = i_v35 - i_v27 >> 0xc;
  au_v21 = packssdw(au_v23,au_v71);
  arg2[6] = au_v21;
  au_v5 = pshuflw(au_v71,arg1[3],0xd8);
  au_v21 = pshufhw(au_v21,au_v5,0xd8);
  u_v3 = CRI_PART(au_v5,0,4);
  u_v11 = CRI_PART(au_v5,4,4);
  CRI_PART(au_v41,4,4) = u_v11;
  CRI_PART(au_v41,0,4) = u_v11;
  CRI_PART(au_v41,8,4) = u_v11;
  CRI_PART(au_v41,12,4) = u_v11;
  CRI_PART(au_v64,4,4) = u_v3;
  CRI_PART(au_v64,0,4) = u_v3;
  CRI_PART(au_v64,8,4) = u_v3;
  CRI_PART(au_v64,12,4) = u_v3;
  au_v49 = pmaddwd(au_v41,_DAT_143a4a580);
  au_v62 = pmaddwd(au_v64,_DAT_143a4a560);
  au_v5 = pshufhw(au_v5,arg1[1],0xd8);
  u_v3 = CRI_PART(au_v21,8,4);
  u_v11 = CRI_PART(au_v21,12,4);
  CRI_PART(au_v58,4,4) = u_v11;
  CRI_PART(au_v58,0,4) = u_v11;
  CRI_PART(au_v58,8,4) = u_v11;
  CRI_PART(au_v58,12,4) = u_v11;
  CRI_PART(au_v16,4,4) = u_v3;
  CRI_PART(au_v16,0,4) = u_v3;
  CRI_PART(au_v16,8,4) = u_v3;
  CRI_PART(au_v16,12,4) = u_v3;
  au_v21 = pmaddwd(au_v16,_DAT_143a4a570);
  au_v38 = pmaddwd(au_v58,_DAT_143a4a590);
  au_v57 = pshuflw(au_v51,au_v5,0xd8);
  i_v47 = CRI_PART(au_v38,0,4) + CRI_PART(au_v49,0,4);
  i_v52 = CRI_PART(au_v38,4,4) + CRI_PART(au_v49,4,4);
  i_v53 = CRI_PART(au_v38,8,4) + CRI_PART(au_v49,8,4);
  i_v55 = CRI_PART(au_v38,12,4) + CRI_PART(au_v49,12,4);
  i_v60 = CRI_PART(au_v62,0,4) + _DAT_143a4a430 + CRI_PART(au_v21,0,4);
  i_v65 = CRI_PART(au_v62,4,4) + iRam0000000143a4a434 + CRI_PART(au_v21,4,4);
  i_v66 = CRI_PART(au_v62,8,4) + iRam0000000143a4a438 + CRI_PART(au_v21,8,4);
  i_v67 = CRI_PART(au_v62,12,4) + iRam0000000143a4a43c + CRI_PART(au_v21,12,4);
  u_v3 = CRI_PART(au_v57,0,4);
  u_v11 = CRI_PART(au_v57,4,4);
  u_v54 = CRI_PART(au_v57,8,4);
  u_v56 = CRI_PART(au_v57,12,4);
  CRI_PART(au_v42,4,4) = u_v3;
  CRI_PART(au_v42,0,4) = u_v3;
  CRI_PART(au_v42,8,4) = u_v3;
  CRI_PART(au_v42,12,4) = u_v3;
  CRI_PART(au_v72,4,4) = u_v54;
  CRI_PART(au_v72,0,4) = u_v54;
  CRI_PART(au_v72,8,4) = u_v54;
  CRI_PART(au_v72,12,4) = u_v54;
  au_v5 = pmaddwd(au_v72,_DAT_143a4a4f0);
  au_v49 = pmaddwd(au_v42,_DAT_143a4a4e0);
  CRI_PART(au_v24,4,4) = u_v56;
  CRI_PART(au_v24,0,4) = u_v56;
  CRI_PART(au_v24,8,4) = u_v56;
  CRI_PART(au_v24,12,4) = u_v56;
  au_v21 = pmaddwd(au_v24,_DAT_143a4a510);
  i_v35 = CRI_PART(au_v49,0,4) + _DAT_143a4a430 + CRI_PART(au_v5,0,4);
  i_v44 = CRI_PART(au_v49,4,4) + iRam0000000143a4a434 + CRI_PART(au_v5,4,4);
  i_v45 = CRI_PART(au_v49,8,4) + iRam0000000143a4a438 + CRI_PART(au_v5,8,4);
  i_v46 = CRI_PART(au_v49,12,4) + iRam0000000143a4a43c + CRI_PART(au_v5,12,4);
  CRI_PART(au_v6,4,4) = u_v11;
  CRI_PART(au_v6,0,4) = u_v11;
  CRI_PART(au_v6,8,4) = u_v11;
  CRI_PART(au_v6,12,4) = u_v11;
  au_v5 = pmaddwd(au_v6,_DAT_143a4a500);
  i_v27 = CRI_PART(au_v21,0,4) + CRI_PART(au_v5,0,4);
  i_v32 = CRI_PART(au_v21,4,4) + CRI_PART(au_v5,4,4);
  i_v33 = CRI_PART(au_v21,8,4) + CRI_PART(au_v5,8,4);
  i_v34 = CRI_PART(au_v21,12,4) + CRI_PART(au_v5,12,4);
  CRI_PART(au_v17,0,4) = i_v27 + i_v35 >> 0xc;
  CRI_PART(au_v17,4,4) = i_v32 + i_v44 >> 0xc;
  CRI_PART(au_v17,8,4) = i_v33 + i_v45 >> 0xc;
  CRI_PART(au_v17,12,4) = i_v34 + i_v46 >> 0xc;
  CRI_PART(au_v25,0,4) = i_v47 + i_v60 >> 0xc;
  CRI_PART(au_v25,4,4) = i_v52 + i_v65 >> 0xc;
  CRI_PART(au_v25,8,4) = i_v53 + i_v66 >> 0xc;
  CRI_PART(au_v25,12,4) = i_v55 + i_v67 >> 0xc;
  CRI_PART(au_v7,4,4) = i_v45 - i_v33 >> 0xc;
  CRI_PART(au_v7,0,4) = i_v46 - i_v34 >> 0xc;
  CRI_PART(au_v7,8,4) = i_v44 - i_v32 >> 0xc;
  CRI_PART(au_v7,12,4) = i_v35 - i_v27 >> 0xc;
  au_v5 = packssdw(au_v17,au_v7);
  CRI_PART(au_v8,4,4) = i_v66 - i_v53 >> 0xc;
  CRI_PART(au_v8,0,4) = i_v67 - i_v55 >> 0xc;
  CRI_PART(au_v8,8,4) = i_v65 - i_v52 >> 0xc;
  CRI_PART(au_v8,12,4) = i_v60 - i_v47 >> 0xc;
  arg2[1] = au_v5;
  au_v49 = packssdw(au_v25,au_v8);
  arg2[3] = au_v49;
  au_v21 = _DAT_143a4a420;
  au_v5 = pshuflw(au_v8,arg1[5],0xd8);
  au_v49 = pshufhw(au_v49,au_v5,0xd8);
  u_v3 = CRI_PART(au_v5,0,4);
  u_v11 = CRI_PART(au_v5,4,4);
  CRI_PART(au_v59,4,4) = u_v3;
  CRI_PART(au_v59,0,4) = u_v3;
  CRI_PART(au_v59,8,4) = u_v3;
  CRI_PART(au_v59,12,4) = u_v3;
  CRI_PART(au_v43,4,4) = u_v11;
  CRI_PART(au_v43,0,4) = u_v11;
  CRI_PART(au_v43,8,4) = u_v11;
  CRI_PART(au_v43,12,4) = u_v11;
  au_v62 = pmaddwd(au_v59,_DAT_143a4a560);
  au_v38 = pmaddwd(au_v43,_DAT_143a4a580);
  au_v5 = pshufhw(au_v5,arg1[7],0xd8);
  u_v3 = CRI_PART(au_v49,8,4);
  u_v11 = CRI_PART(au_v49,12,4);
  CRI_PART(au_v18,4,4) = u_v3;
  CRI_PART(au_v18,0,4) = u_v3;
  CRI_PART(au_v18,8,4) = u_v3;
  CRI_PART(au_v18,12,4) = u_v3;
  CRI_PART(au_v68,4,4) = u_v11;
  CRI_PART(au_v68,0,4) = u_v11;
  CRI_PART(au_v68,8,4) = u_v11;
  CRI_PART(au_v68,12,4) = u_v11;
  au_v69 = pmaddwd(au_v68,_DAT_143a4a590);
  au_v49 = pmaddwd(au_v18,_DAT_143a4a570);
  au_v5 = pshuflw(au_v57,au_v5,0xd8);
  i_v47 = CRI_PART(au_v69,0,4) + CRI_PART(au_v38,0,4);
  i_v52 = CRI_PART(au_v69,4,4) + CRI_PART(au_v38,4,4);
  i_v53 = CRI_PART(au_v69,8,4) + CRI_PART(au_v38,8,4);
  i_v55 = CRI_PART(au_v69,12,4) + CRI_PART(au_v38,12,4);
  i_v35 = CRI_PART(au_v62,0,4) + _DAT_143a4a430 + CRI_PART(au_v49,0,4);
  i_v44 = CRI_PART(au_v62,4,4) + iRam0000000143a4a434 + CRI_PART(au_v49,4,4);
  i_v45 = CRI_PART(au_v62,8,4) + iRam0000000143a4a438 + CRI_PART(au_v49,8,4);
  i_v46 = CRI_PART(au_v62,12,4) + iRam0000000143a4a43c + CRI_PART(au_v49,12,4);
  u_v3 = CRI_PART(au_v5,0,4);
  u_v11 = CRI_PART(au_v5,4,4);
  u_v54 = CRI_PART(au_v5,8,4);
  u_v56 = CRI_PART(au_v5,12,4);
  CRI_PART(au_v26,4,4) = u_v3;
  CRI_PART(au_v26,0,4) = u_v3;
  CRI_PART(au_v26,8,4) = u_v3;
  CRI_PART(au_v26,12,4) = u_v3;
  CRI_PART(au_v9,4,4) = u_v54;
  CRI_PART(au_v9,0,4) = u_v54;
  CRI_PART(au_v9,8,4) = u_v54;
  CRI_PART(au_v9,12,4) = u_v54;
  au_v5 = pmaddwd(au_v9,_DAT_143a4a4f0);
  au_v49 = pmaddwd(au_v26,_DAT_143a4a4e0);
  i_v27 = CRI_PART(au_v49,0,4) + _DAT_143a4a430 + CRI_PART(au_v5,0,4);
  i_v32 = CRI_PART(au_v49,4,4) + iRam0000000143a4a434 + CRI_PART(au_v5,4,4);
  i_v33 = CRI_PART(au_v49,8,4) + iRam0000000143a4a438 + CRI_PART(au_v5,8,4);
  i_v34 = CRI_PART(au_v49,12,4) + iRam0000000143a4a43c + CRI_PART(au_v5,12,4);
  CRI_PART(au_v70,0,4) = i_v47 + i_v35 >> 0xc;
  CRI_PART(au_v70,4,4) = i_v52 + i_v44 >> 0xc;
  CRI_PART(au_v70,8,4) = i_v53 + i_v45 >> 0xc;
  CRI_PART(au_v70,12,4) = i_v55 + i_v46 >> 0xc;
  CRI_PART(au_v19,4,4) = i_v45 - i_v53 >> 0xc;
  CRI_PART(au_v19,0,4) = i_v46 - i_v55 >> 0xc;
  CRI_PART(au_v19,8,4) = i_v44 - i_v52 >> 0xc;
  CRI_PART(au_v19,12,4) = i_v35 - i_v47 >> 0xc;
  au_v71 = packssdw(au_v70,au_v19);
  CRI_PART(au_v30,4,4) = u_v56;
  CRI_PART(au_v30,0,4) = u_v56;
  CRI_PART(au_v30,8,4) = u_v56;
  CRI_PART(au_v30,12,4) = u_v56;
  CRI_PART(au_v10,4,4) = u_v11;
  CRI_PART(au_v10,0,4) = u_v11;
  CRI_PART(au_v10,8,4) = u_v11;
  CRI_PART(au_v10,12,4) = u_v11;
  au_v5 = pmaddwd(au_v10,_DAT_143a4a500);
  au_v49 = pmaddwd(au_v30,_DAT_143a4a510);
  i_v35 = CRI_PART(au_v49,0,4) + CRI_PART(au_v5,0,4);
  i_v44 = CRI_PART(au_v49,4,4) + CRI_PART(au_v5,4,4);
  i_v45 = CRI_PART(au_v49,8,4) + CRI_PART(au_v5,8,4);
  i_v46 = CRI_PART(au_v49,12,4) + CRI_PART(au_v5,12,4);
  au_v62 = pmulhw(arg2[6],_DAT_143a4a470);
  au_v72 = pmulhw(_DAT_143a4a470,arg2[2]);
  CRI_PART(au_v31,0,4) = i_v35 + i_v27 >> 0xc;
  CRI_PART(au_v31,4,4) = i_v44 + i_v32 >> 0xc;
  CRI_PART(au_v31,8,4) = i_v45 + i_v33 >> 0xc;
  CRI_PART(au_v31,12,4) = i_v46 + i_v34 >> 0xc;
  CRI_PART(au_v20,4,4) = i_v33 - i_v45 >> 0xc;
  CRI_PART(au_v20,0,4) = i_v34 - i_v46 >> 0xc;
  CRI_PART(au_v20,8,4) = i_v32 - i_v44 >> 0xc;
  CRI_PART(au_v20,12,4) = i_v27 - i_v35 >> 0xc;
  au_v5 = arg2[3];
  au_v57 = packssdw(au_v31,au_v20);
  au_v38 = pmulhw(au_v71,_DAT_143a4a480);
  au_v49 = pmulhw(_DAT_143a4a480,au_v5);
  au_v49 = paddsw(au_v49,au_v5);
  au_v38 = paddsw(au_v38,au_v71);
  au_v69 = pmulhw(au_v57,_DAT_143a4a460);
  au_v38 = paddsw(au_v38,au_v5);
  au_v71 = psubsw(au_v71,au_v49);
  au_v5 = pmulhw(_DAT_143a4a460,arg2[1]);
  au_v69 = paddsw(au_v69,arg2[1]);
  au_v49 = psubsw(au_v5,au_v57);
  au_v5 = paddsw(au_v38,au_v69);
  au_v69 = psubsw(au_v69,au_v38);
  au_v5 = paddsw(au_v5,_DAT_143a4a420);
  au_v38 = paddsw(au_v49,au_v71);
  au_v49 = psubsw(au_v49,au_v71);
  arg2[7] = au_v5;
  au_v5 = _DAT_143a4a490;
  arg2[3] = au_v38;
  au_v57 = paddsw(au_v62,arg2[2]);
  au_v71 = psubsw(au_v72,arg2[6]);
  au_v21 = paddsw(au_v49,au_v21);
  au_v62 = paddsw(au_v69,au_v21);
  au_v49 = psubsw(au_v69,au_v21);
  au_v38 = paddsw(arg2[4],*arg2);
  au_v69 = psubsw(*arg2,arg2[4]);
  au_v21 = pmulhw(au_v5,au_v62);
  au_v5 = pmulhw(au_v5,au_v49);
  au_v72 = paddsw(au_v62,au_v21);
  au_v62 = paddsw(au_v5,au_v49);
  au_v5 = paddsw(au_v38,au_v57);
  au_v72 = au_v72 | _DAT_143a4a420;
  au_v62 = au_v62 | _DAT_143a4a420;
  au_v21 = paddsw(au_v69,au_v71);
  au_v49 = paddsw(au_v5,_DAT_143a4a440);
  au_v21 = paddsw(au_v21,_DAT_143a4a440);
  au_v5 = psubsw(au_v38,au_v57);
  au_v57 = paddsw(au_v5,_DAT_143a4a450);
  au_v38 = psubsw(au_v69,au_v71);
  au_v5 = paddsw(arg2[7],au_v49);
  au_v69 = paddsw(au_v38,_DAT_143a4a450);
  au_v5 = psraw(au_v5,5);
  *arg2 = au_v5;
  au_v5 = paddsw(au_v21,au_v72);
  au_v5 = psraw(au_v5,5);
  au_v71 = psubsw(au_v69,au_v62);
  au_v38 = psubsw(au_v21,au_v72);
  au_v21 = paddsw(au_v69,au_v62);
  au_v62 = psraw(au_v71,5);
  au_v38 = psraw(au_v38,5);
  arg2[1] = au_v5;
  au_v5 = psraw(au_v21,5);
  arg2[2] = au_v5;
  au_v21 = psubsw(au_v49,arg2[7]);
  au_v5 = paddsw(arg2[3],au_v57);
  au_v21 = psraw(au_v21,5);
  au_v5 = psraw(au_v5,5);
  arg2[7] = au_v21;
  au_v21 = psubsw(au_v57,arg2[3]);
  arg2[3] = au_v5;
  au_v5 = psraw(au_v21,5);
  arg2[4] = au_v5;
  arg2[5] = au_v62;
  arg2[6] = au_v38;
  return;
}

longlong FUN_14006b0d0(longlong arg1);

longlong FUN_140073c80(longlong arg1);

longlong FUN_14007ba60(longlong arg1);

longlong FUN_140083350(longlong arg1);

void FUN_140089e90(longlong arg1, cri_u8 arg2, cri_u4 *arg3);

void * FUN_140089f60(void *arg1, int arg2);

void FUN_140089fe0(longlong arg1, cri_u8 arg2);

void FUN_14008a180(longlong arg1, cri_u8 arg2, int *arg3);

void FUN_14008a2b0(longlong arg1);

void FUN_14008a3c0(longlong arg1);

void FUN_14008a430(longlong arg1, int arg2, int arg3);

void FUN_14008a5b0(longlong arg1, int arg2, int arg3);

void FUN_14008a730(longlong arg1, uint arg2, int arg3, int arg4, int arg5);

void FUN_14008a830(longlong arg1, int *arg2, int *arg3, int arg4, int arg5);

void FUN_14008a970(longlong arg1, uint arg2);

void FUN_14008aa80(longlong arg1, cri_u4 arg2, cri_u4 arg3);

void FUN_14008ab00(longlong arg1);

void FUN_14008ab40(longlong arg1);

void FUN_14008ab60(longlong arg1, cri_u4 arg2, int arg3);

void FUN_14008b6b0(longlong arg1, longlong arg2, int arg3, cri_u4 arg4, uint arg5, cri_u4 arg6, int arg7, int arg8, uint arg9, uint arg10, int arg11);

void FUN_14008b780(longlong arg1, longlong arg2, int arg3, cri_u8 arg4, int arg5, int arg6, int arg7, int arg8, uint arg9, uint arg10, int arg11);

void FUN_14008c150(longlong arg1, longlong *arg2, int arg3, longlong *arg4, int arg5, byte arg6, byte arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, cri_u4 arg14);

void FUN_14008c400(longlong arg1, longlong *arg2, int arg3, longlong *arg4, int arg5, byte arg6, byte arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, cri_u4 arg14);

void FUN_14008c780(longlong arg1);

void FUN_14008c7b0(longlong arg1);

void FUN_14008c7e0(longlong arg1);

void FUN_14008c800(longlong arg1, cri_u4 *arg2, cri_u4 *arg3);

void FUN_14008c820(longlong arg1);

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

void FUN_14008e570(longlong *arg1, longlong *arg2, longlong arg3, longlong arg4);

void FUN_14008fa50(longlong *arg1, longlong *arg2, longlong arg3, longlong arg4);

void FUN_140090080(longlong *arg1, longlong *arg2, longlong arg3, longlong arg4);

void FUN_140090730(cri_u8 *arg1, longlong *arg2, cri_u8 arg3, longlong arg4);

void FUN_140090f20(cri_u8 *arg1, cri_u8 *arg2);

void FUN_140091df0(cri_u8 *arg1, longlong *arg2);

void FUN_1400923d0(cri_u8 *arg1, longlong *arg2);

void FUN_1400927c0(byte *arg1, byte *arg2, cri_u8 arg3, cri_u8 arg4);

void FUN_140092850(byte *arg1, byte *arg2, cri_u8 arg3, cri_u8 arg4);

void FUN_1400928e0(byte *arg1, byte *arg2, cri_u8 arg3, cri_u8 arg4);

void FUN_140092970(longlong arg1, longlong arg2);

void FUN_140093150(longlong arg1, longlong arg2);

void FUN_140093890(void *arg1, int arg2, int arg3);

void FUN_140093940(void *arg1, byte arg2, byte arg3, int arg4);

void FUN_140093cf0();

void FUN_140093ec0(longlong arg1, longlong arg2);

void FUN_1400946b0(longlong arg1, longlong arg2);

void FUN_140094df0(void *arg1, int arg2, int arg3);

void FUN_140094ea0(void *arg1, byte arg2, byte arg3, int arg4);

void FUN_140095250();

cri_u8 FUN_140095430();

void FUN_140095440(cri_u8 arg1, cri_u8 arg2);

void FUN_140095450(cri_u4 arg1);

void FUN_140095480();

void FUN_140095590(void *cri_p0, void *cri_p1, void *cri_p2);

void FUN_140095800(void *arg1, void *arg2);

void FUN_140095810(void *arg1, void *arg2);

void FUN_140095820(longlong arg1, cri_u2 *arg2);

void FUN_1400959a0(longlong arg1, cri_u2 *arg2);

void FUN_140095b20();

uint FUN_140095b40(longlong arg1, uint *arg2);

uint FUN_14009a3d0(longlong arg1, uint *arg2);

uint FUN_14009ec40(longlong arg1, uint *arg2);

uint FUN_1400a3920(longlong arg1, uint *arg2);

uint FUN_1400a8ad0(longlong arg1, uint *arg2);

uint FUN_1400adc50(longlong arg1, uint *arg2);

void FUN_1400afd20();

void FUN_1400afd30(uint arg1);

void FUN_1400afd70();

void FUN_1400afde0(const char *arg1, ...);

void FUN_1400afe60(const char *arg1);

void FUN_1400afed0(const char *arg1, const char *arg2);

void FUN_1400aff40(int arg1);

#pragma function(memset)                // the exe calls memset here rather than expanding it
cri_u8 FUN_1400affc0();
#pragma intrinsic(memset)

void FUN_1400b0090();

int FUN_1400b0130();

void FUN_1400b01f0();

void FUN_1400b0210();

void FUN_1400b0240(int arg1);

void FUN_1400b0290(int arg1);

void FUN_1400b02e0(int arg1);

void FUN_1400b0340();

uint FUN_1400b03a0(uint arg1, longlong arg2, longlong arg3, char *arg4);

void FUN_1400b0470(uint arg1, uint arg2);

void FUN_1400b0500(uint arg1, uint arg2, cri_u8 arg3, cri_u8 arg4, char *arg5);

void FUN_1400b05c0(int arg1, cri_u8 arg2, cri_u8 arg3);

// One 0x18-byte entry of a server slot callback table (DAT_143d683d0, 6 entries per slot).
struct cri07_srvcb { uint (*fn)(cri_u8); cri_u8 arg; cri_u8 spare; };

uint FUN_1400b0610(int arg1);

cri_u4 FUN_1400b06c0(uint arg1, uint arg2);

uint FUN_1400b07d0(int *arg1, cri_u8 a2, cri_u8 a3, cri_u8 a4);

cri_u4 FUN_1400b0820(uint arg1, longlong arg2, longlong arg3, char *arg4);

void FUN_1400b0880(uint arg1, uint arg2);

void FUN_1400b08b0(uint arg1, uint arg2, cri_u8 arg3, cri_u8 arg4, char *arg5);

void FUN_1400b0920(uint arg1, uint arg2, cri_u8 arg3, cri_u8 arg4);

void FUN_1400b0a10(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...);

void FUN_1400b1720(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...);

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
